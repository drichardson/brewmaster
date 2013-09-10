#pragma once

#include <GLES2/gl2.h>
#include "geometry.h"
#include "gl_context.h"

typedef struct {
    GLenum format;
    unsigned char* texels;
    GLsizei width;
    GLsizei height;
    GLuint texture;
} image_t;

image_t* image_from_jpg_file(char const* filename);
void image_free(image_t*);
size2d_t image_size(image_t*);
GLuint image_gl_texture(image_t*);
void image_draw(image_t*, gl_context_t*, rect2d_t);

