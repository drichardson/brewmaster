#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "GLES2/gl2.h"
#include "EGL/egl.h"

#include "opengl_initialize.h"
#include "opengl_utilities.h"
#include "shader_loader.h"
#include "texture_loader.h"

typedef struct
{
    opengl_context_t context;

    GLuint programObject;
    GLuint toolbarBackgroundTexture;
    GLuint vPositionAttribute;
} app_opengl_state_t;



///
// Initialize the shader and program object
//
static int init_app_gl(app_opengl_state_t *state) 
{
#if 0
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
#endif

    // Set background color and clear buffers
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    check_gl();

 
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
    glBindAttribLocation(programObject, 0, "a_position");
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
// Draw a triangle using the shader pair created in init_app_gl()
//
static void DrawTriangle(app_opengl_state_t* state)
{
    GLfloat vVertices[] = {
        -0.5f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };

    //printf("Drawing %dx%d\n", state->screen_width, state->screen_height);
    // Set the viewport
    glViewport(0, 0, state->context.screen_width, state->context.screen_height);

    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Use the program object
    glUseProgram(state->programObject);
    GLint fragColor = glGetUniformLocation(state->programObject, "u_fragColor"); 

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

    eglSwapBuffers(state->context.display, state->context.surface);
}



int main ( int argc, char *argv[] )
{
    app_opengl_state_t state;
    memset(&state, 0, sizeof(state));

    bool rc = opengl_initialize(&state.context);
    if (!rc) {
        fprintf(stderr, "Couldn't initialize open gl to get full screen.\n");
        exit(1);
    }

    if (!init_app_gl(&state)) {
        fprintf(stderr, "Application specific gl initialization failed.\n");
        exit(1);
    }

    rc = texture_load_png("images/toolbar-background.png", &state.toolbarBackgroundTexture, NULL, NULL);
    if (!rc) {
        fprintf(stderr, "error loading toolbar-background.png");
    }

    DrawTriangle(&state);

    while(1) sleep(10);

    return 0;
}

