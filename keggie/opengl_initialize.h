#pragma once

#include "GLES2/gl2.h"
#include "EGL/egl.h"
#include <stdint.h>
#include <stdbool.h>

typedef struct opengl_context
{
   uint32_t screen_width;
   uint32_t screen_height;
   EGLDisplay display;
   EGLSurface surface;
   EGLContext context;
} opengl_context_t;
 

// Setup the display for rendering using OpenGL.
// Returns true on success; false otherwise.
bool opengl_initialize(opengl_context_t* context_out);

