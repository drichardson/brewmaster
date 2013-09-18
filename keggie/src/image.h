#pragma once

#include <GLES2/gl2.h>
#include "geometry.h"
#include "gl_context.h"
#include "color.h"

typedef struct {
    GLenum format;
    unsigned char* texels;
    GLsizei width;
    GLsizei height;
    GLuint texture;
    rgba_t tint;
} image_t;

#define IMAGE_OPTION_FLIPPED (1 << 0)

image_t* image_with_path(char const* path);
image_t* image_with_pixels(unsigned char const* pixels, GLenum format, GLsizei width, GLsizei height);
void image_free(image_t*);
size2d_t image_size(image_t*);
GLuint image_gl_texture(image_t*);
void image_draw(image_t*, gl_context_t*, rect2d_t);
void image_draw_with_options(image_t*, gl_context_t*, rect2d_t, unsigned options_mask);
void image_set_tint(image_t* img, rgba_t);

