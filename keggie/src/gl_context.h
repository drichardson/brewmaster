#pragma once

#include "egl_context.h"
#include "geometry.h"

// gl_context_t - a common OpenGL context for keggie. Built around
// keggie's shaders, represented by programObject.
typedef struct
{
    egl_context_t egl_context;

    rect2d_t screen_bounds;

    // keggie's main OpenGL shader program and associated attributes (prefixed with a_)
    // and uniforms (prefixed with u_).
    GLuint mainProgram; 

    // mainProgram attributes
    GLuint a_position;
    GLuint a_textureCoordinates;

    // mainProgram uniforms
    GLint u_modelViewProjectionMatrix;
    GLint u_fragColor;
    GLint u_texture;
    GLint u_enableTexture;
} gl_context_t;

bool gl_context_initialize(gl_context_t* ctx);

// Select the mainProgram and reset it's attributes and uniforms back to their default values.
void gl_context_use_main_program(gl_context_t *ctx);

void gl_context_swap_buffers(gl_context_t* ctx);

