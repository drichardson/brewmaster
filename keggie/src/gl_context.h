#pragma once

#include "egl_context.h"

// gl_context_t - a common OpenGL context for keggie. Built around
// keggie's shaders, represented by programObject.
typedef struct
{
    egl_context_t egl_context;

    // keggie's main OpenGL shader program and associated attributes (prefixed with a_)
    // and uniforms (prefixed with u_).
    GLuint mainProgram; 
    GLuint a_position;
    GLuint a_textureCoordinates;
    GLint u_fragColor;
    GLint u_texture;
    GLint u_enableTexture;
} gl_context_t;

bool gl_context_initialize(gl_context_t* ctx);

// Select the mainProgram and reset it's attributes and uniforms back to their default values.
void gl_context_use_main_program(gl_context_t *ctx);

