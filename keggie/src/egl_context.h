#pragma once

#include "GLES2/gl2.h"
#include "EGL/egl.h"
#include <stdint.h>
#include <stdbool.h>

typedef struct egl_context
{
   uint32_t screen_width;
   uint32_t screen_height;
   EGLDisplay display;
   EGLSurface surface;
   EGLContext context;
} egl_context_t;
 

// Setup the display for rendering using OpenGL.
// Returns true on success; false otherwise.
bool egl_initialize(egl_context_t* context_out);

