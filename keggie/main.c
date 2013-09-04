#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "GLES2/gl2.h"
#include "EGL/egl.h"

#include "bcm_host.h"

#include "texture_loader.h"
#include "shader_loader.h"

#define check_gl() assert(glGetError() == 0)

typedef struct
{
   uint32_t screen_width;
   uint32_t screen_height;
// OpenGL|ES objects
   EGLDisplay display;
   EGLSurface surface;
   EGLContext context;
   GLuint programObject;
   GLuint toolbarBackgroundTexture;
   GLuint vPositionAttribute;
} raspi_opengl_state_t;



///
// Initialize the shader and program object
//
static int Init (raspi_opengl_state_t *state) 
{
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint programObject;
    GLint linked;

    bool const vertexShaderLoaded = shader_load_from_file(GL_VERTEX_SHADER, "shaders/vertex.glsl", &vertexShader);
    bool const fragmentShaderLoaded = shader_load_from_file(GL_FRAGMENT_SHADER, "shaders/fragment.glsl", &fragmentShader);

    assert(vertexShaderLoaded);
    assert(fragmentShaderLoaded);

    // Create the program object
    programObject = glCreateProgram();

    if ( programObject == 0 ) {
        printf("glCreateProgram failed\n");
        return 0;
    }

    glAttachShader(programObject, vertexShader);
    glAttachShader(programObject, fragmentShader);

    // Won't be deleted until program is deleted.
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Bind vPosition to attribute 0   
    glBindAttribLocation(programObject, 0, "vPosition");
    state->vPositionAttribute = 0;

    // Link the program
    glLinkProgram(programObject);

    // Check the link status
    glGetProgramiv(programObject, GL_LINK_STATUS, &linked);

    if (!linked) 
    {
        GLint infoLen = 0;

        glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen);

        if (infoLen > 1)
        {
            char* infoLog = malloc(sizeof(char) * infoLen);

            glGetProgramInfoLog(programObject, infoLen, NULL, infoLog);
            printf("Error linking program:\n%s\n", infoLog);

            free(infoLog);
        }

        glDeleteProgram(programObject);
        return GL_FALSE;
    }

    // Store the program object
    state->programObject = programObject;

    return GL_TRUE;
}

///
// Draw a triangle using the shader pair created in Init()
//
static void Draw(raspi_opengl_state_t* state)
{
    GLfloat vVertices[] = {
        -0.5f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };

    //printf("Drawing %dx%d\n", state->screen_width, state->screen_height);
    // Set the viewport
    glViewport(0, 0, state->screen_width, state->screen_height);

    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Use the program object
    glUseProgram(state->programObject);
    GLint fragColor = glGetUniformLocation(state->programObject, "fragColor"); 

    // Load the vertex data
    glVertexAttribPointer(state->vPositionAttribute, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
    glEnableVertexAttribArray(state->vPositionAttribute);
    glUniform4f(fragColor, 1, 1, 0, 1);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    check_gl();


    // Draw the toolbar background
    GLfloat toolbarVertices[] = {
        -1.0, 1.0, 0.0,
        -1.0, 0.8, 0.0,
        1.0, 0.8, 0.0,
        1.0, 1.0, 0.0,
        -1.0, 1.0, 0.0,
        1.0, 0.8, 0.0
    };

    glVertexAttribPointer(state->vPositionAttribute, 3, GL_FLOAT, GL_FALSE, 0, toolbarVertices);
    check_gl();
    glEnableVertexAttribArray(state->vPositionAttribute);
    check_gl();
    glUniform4f(fragColor, 0,1,0,1);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    check_gl();


    // Draw a yellow 1 pixel box around the entire thing.
    GLfloat boxLines[] = {
        -1.0, -1.0, 0,
        -1.0, 1.0, 0,
        1.0, 1.0, 0,
        1.0, -1.0, 0
    };
    glVertexAttribPointer(state->vPositionAttribute, 3, GL_FLOAT, GL_FALSE, 0, boxLines);
    glEnableVertexAttribArray(state->vPositionAttribute);
    glUniform4f(fragColor, 1,0,0,1);
    glDrawArrays(GL_LINE_LOOP, 0, 4);
    check_gl();

    eglSwapBuffers(state->display, state->surface);
}


/***********************************************************
 * Name: init_ogl
 *
 * Arguments:
 *       CUBE_STATE_T *state - holds OGLES model info
 *
 * Description: Sets the display, OpenGL|ES context and screen stuff
 *
 * Returns: void
 *
 ***********************************************************/
static void init_ogl(raspi_opengl_state_t *state)
{
   int32_t success = 0;
   EGLBoolean result;
   EGLint num_config;

   static EGL_DISPMANX_WINDOW_T nativewindow;

   DISPMANX_ELEMENT_HANDLE_T dispman_element;
   DISPMANX_DISPLAY_HANDLE_T dispman_display;
   DISPMANX_UPDATE_HANDLE_T dispman_update;
   VC_RECT_T dst_rect;
   VC_RECT_T src_rect;

   static const EGLint attribute_list[] =
   {
      EGL_RED_SIZE, 8,
      EGL_GREEN_SIZE, 8,
      EGL_BLUE_SIZE, 8,
      EGL_ALPHA_SIZE, 8,
      EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
      EGL_NONE
   };
   
   static const EGLint context_attributes[] = 
   {
      EGL_CONTEXT_CLIENT_VERSION, 2,
      EGL_NONE
   };
   EGLConfig config;

   // get an EGL display connection
   state->display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
   assert(state->display!=EGL_NO_DISPLAY);
   check_gl();

   // initialize the EGL display connection
   result = eglInitialize(state->display, NULL, NULL);
   assert(EGL_FALSE != result);
   check_gl();

   // get an appropriate EGL frame buffer configuration
   result = eglChooseConfig(state->display, attribute_list, &config, 1, &num_config);
   assert(EGL_FALSE != result);
   check_gl();

   // get an appropriate EGL frame buffer configuration
   result = eglBindAPI(EGL_OPENGL_ES_API);
   assert(EGL_FALSE != result);
   check_gl();

   // create an EGL rendering context
   state->context = eglCreateContext(state->display, config, EGL_NO_CONTEXT, context_attributes);
   assert(state->context!=EGL_NO_CONTEXT);
   check_gl();

   // create an EGL window surface
   success = graphics_get_display_size(0 /* LCD */, &state->screen_width, &state->screen_height);
   assert(success >= 0);

   dst_rect.x = 0;
   dst_rect.y = 0;
   dst_rect.width = state->screen_width;
   dst_rect.height = state->screen_height;
      
   src_rect.x = 0;
   src_rect.y = 0;
   src_rect.width = state->screen_width << 16;
   src_rect.height = state->screen_height << 16;        

   dispman_display = vc_dispmanx_display_open(0 /* LCD */);
   dispman_update = vc_dispmanx_update_start(0);
         
   dispman_element = vc_dispmanx_element_add(dispman_update, dispman_display,
      0/*layer*/, &dst_rect, 0/*src*/,
      &src_rect, DISPMANX_PROTECTION_NONE, 0 /*alpha*/, 0/*clamp*/, 0/*transform*/);
      
   nativewindow.element = dispman_element;
   nativewindow.width = state->screen_width;
   nativewindow.height = state->screen_height;
   vc_dispmanx_update_submit_sync(dispman_update);
      
   check_gl();

   state->surface = eglCreateWindowSurface(state->display, config, &nativewindow, NULL);
   assert(state->surface != EGL_NO_SURFACE);
   check_gl();

   // connect the context to the surface
   result = eglMakeCurrent(state->display, state->surface, state->surface, state->context);
   assert(EGL_FALSE != result);
   check_gl();

#if 0
   glEnable(GL_CULL_FACE);
   glCullFace(GL_BACK);
#endif

   // Set background color and clear buffers
   glClearColor(1, 1, 1, 1);
   glClear(GL_COLOR_BUFFER_BIT);

   check_gl();
}


int main ( int argc, char *argv[] )
{
    bcm_host_init();

    raspi_opengl_state_t state;
    memset(&state, 0, sizeof(state));
    init_ogl(&state);

    if ( !Init ( &state ) )
        return 0;
    bool rc = texture_load_png("images/toolbar-background.png", &state.toolbarBackgroundTexture, NULL, NULL);
    if (!rc) {
        fprintf(stderr, "error loading toolbar-background.png");
    }

    Draw(&state);

    while(1) sleep(10);

    return 0;
}

