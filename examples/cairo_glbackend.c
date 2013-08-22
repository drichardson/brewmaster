#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <unistd.h>
#include <cairo/cairo.h>

#include "bcm_host.h"

#include "GLES2/gl2.h"
#include "EGL/egl.h"
#include "EGL/eglext.h"

typedef struct
{
   uint32_t screen_width;
   uint32_t screen_height;
// OpenGL|ES objects
   EGLDisplay display;
   EGLSurface surface;
   EGLContext context;
   GLuint texture_id;

} CUBE_STATE_T;

static CUBE_STATE_T _state, *state=&_state;

#define check() assert(glGetError() == 0)

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
static void init_ogl(CUBE_STATE_T *state)
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
   check();

   // initialize the EGL display connection
   result = eglInitialize(state->display, NULL, NULL);
   assert(EGL_FALSE != result);
   check();

   // get an appropriate EGL frame buffer configuration
   result = eglChooseConfig(state->display, attribute_list, &config, 1, &num_config);
   assert(EGL_FALSE != result);
   check();

   // get an appropriate EGL frame buffer configuration
   result = eglBindAPI(EGL_OPENGL_ES_API);
   assert(EGL_FALSE != result);
   check();

   // create an EGL rendering context
   state->context = eglCreateContext(state->display, config, EGL_NO_CONTEXT, context_attributes);
   assert(state->context!=EGL_NO_CONTEXT);
   check();

   // create an EGL window surface
   success = graphics_get_display_size(0 /* LCD */, &state->screen_width, &state->screen_height);
   assert( success >= 0 );

   dst_rect.x = 0;
   dst_rect.y = 0;
   dst_rect.width = state->screen_width;
   dst_rect.height = state->screen_height;
      
   src_rect.x = 0;
   src_rect.y = 0;
   src_rect.width = state->screen_width << 16;
   src_rect.height = state->screen_height << 16;        

   dispman_display = vc_dispmanx_display_open( 0 /* LCD */);
   dispman_update = vc_dispmanx_update_start( 0 );
         
   dispman_element = vc_dispmanx_element_add ( dispman_update, dispman_display,
      0/*layer*/, &dst_rect, 0/*src*/,
      &src_rect, DISPMANX_PROTECTION_NONE, 0 /*alpha*/, 0/*clamp*/, 0/*transform*/);
      
   nativewindow.element = dispman_element;
   nativewindow.width = state->screen_width;
   nativewindow.height = state->screen_height;
   vc_dispmanx_update_submit_sync( dispman_update );
      
   check();

   state->surface = eglCreateWindowSurface( state->display, config, &nativewindow, NULL );
   assert(state->surface != EGL_NO_SURFACE);
   check();

   // connect the context to the surface
   result = eglMakeCurrent(state->display, state->surface, state->surface, state->context);
   assert(EGL_FALSE != result);
   check();

   // Set background color and clear buffers
   glClearColor(0.15f, 0.25f, 0.35f, 1.0f);
   glClear( GL_COLOR_BUFFER_BIT );
   check();

   //glEnable(GL_TEXTURE_2D);
   //glEnable(GL_BLEND);
   //glBlendFunc(GL_ONE, GL_SRC_COLOR);
   check();

   glViewport ( 0, 0, state->screen_width, state->screen_height );
   check();
}

#if 0
static cairo_t*
create_cairo_context (int               width,
                      int               height,
                      int               channels,
                      cairo_surface_t** surf,
                      unsigned char**   buffer)
{
    cairo_t* cr;

    // create cairo-surface/context to act as OpenGL-texture source
    *buffer = calloc (channels * width * height, sizeof (unsigned char));
    if (!*buffer)
    {
        printf ("create_cairo_context() - Couldn't allocate buffer\n");
        return NULL;
    }

    *surf = cairo_image_surface_create_for_data (*buffer,
                             CAIRO_FORMAT_ARGB32,
                             width,
                             height,
                             channels * width);
    if (cairo_surface_status (*surf) != CAIRO_STATUS_SUCCESS)
    {
        free (*buffer);
        printf ("create_cairo_context() - Couldn't create surface\n");
        return NULL;
    }

    cr = cairo_create (*surf);
    if (cairo_status (cr) != CAIRO_STATUS_SUCCESS)
    {
        free (*buffer);
        printf ("create_cairo_context() - Couldn't create context\n");
        return NULL;
    }

    return cr;
}
#endif

static void draw(CUBE_STATE_T *state)
{
    //glBindFramebuffer(GL_FRAMEBUFFER,0);
    glClearColor(0,1,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    check();

    glEnableClientState(GL_VERTEX_ARRAY);
    GLfloat const vertices[] = {
        0, 0, 0,
        1, 1, 0,
        1, 0, 0
    };

#if 0
    unsigned const width = state->screen_width, height = state->screen_height;
    // Render 2D junk onto a cairo surface.
    unsigned char* cairo_surface_data = NULL;
    cairo_surface_t* cairo_surface = NULL;
    cairo_t* cairo_ctx = create_cairo_context(width, height, 4, &cairo_surface, &cairo_surface_data);
   
    cairo_save(cairo_ctx);
    cairo_set_operator(cairo_ctx, CAIRO_OPERATOR_OVER);
    cairo_scale(cairo_ctx, (double) width / 1.0f, (double) height / 1.0f);
    cairo_set_source_rgba(cairo_ctx, 0.0f, 0.0f, 1.0f, 1.0f);
    cairo_paint(cairo_ctx); 
    cairo_restore(cairo_ctx);
    cairo_destroy(cairo_ctx);

    // Now render to the main frame buffer
    glBindFramebuffer(GL_FRAMEBUFFER,0);

    // Clear the background (not really necessary I suppose)
    glClearColor(red,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    check();

    GLuint texture_id;
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, cairo_surface_data);
    glEnableClientState(GL_COLOR_ARRAY);
    glColor4f (0.25f, 0.5f, 1.0f, 1.0);
    glBegin (GL_QUADS);
    glTexCoord2f (0.0f, 0.0f);
    glVertex2f (0.0f, 0.0f);
    glTexCoord2f ((GLfloat) width, 0.0f);
    glVertex2f (1.0f, 0.0f);
    glTexCoord2f ((GLfloat) width, (GLfloat) height);
    glVertex2f (1.0f, 1.0f);
    glTexCoord2f (0.0f, (GLfloat) height);
    glVertex2f (0.0f, 1.0f);
    glEnd ();

    free(cairo_surface_data);
#endif

    eglSwapBuffers(state->display, state->surface);
    check();

}

int main ()
{
   bcm_host_init();

   // Clear application state
   memset( state, 0, sizeof( *state ) );
      
   // Start OGLES
   init_ogl(state);

   draw(state);
   sleep(2);

   return 0;
}

