#pragma once

#include <GLES2/gl2.h>
#include "geometry.h"
#include "gl_context.h"
#include "color.h"

typedef struct {
    GLenum format;
    void* bytes;
    GLsizei width;
    GLsizei height;
    GLuint texture;
    rgba_t tint;
    unsigned options;
} image_t;

#define IMAGE_OPTION_COPY (1 << 0)
#define IMAGE_OPTION_NO_FREE (1 << 1)

// Create an image_t using the given parameters. By default, ownership of bytes is transferred
// to the image_t and it will be freed when image_free is called. However, if you want
// image_t to make a copy of the image, set the IMAGE_OPTION_COPY flag. If you don't want
// image_t to free it's internal bytes when image_free is called, set the IMAGE_OPTION_NO_FREE
// flag. You should not set both IMAGE_OPTION_COPY and IMAGE_OPTION_NO_FREE or else you will
// create a leak.
image_t* image_with_bytes(void* bytes, GLenum format, GLsizei width, GLsizei height, unsigned options);
void image_free(image_t*);
size2d_t image_size(image_t*);

// Convenience for reading from common file types. Currently supports PNG and JPEG.
image_t* image_with_path(char const* path);

#define IMAGE_DRAW_OPTION_FLIPPED (1 << 0)
void image_draw_with_options(image_t*, gl_context_t*, rect2d_t, unsigned options_mask);
void image_draw(image_t*, gl_context_t*, rect2d_t);

void image_set_tint(image_t* img, rgba_t);

