#pragma once

#include <GLES2/gl2.h>

typedef struct {
    GLenum format;
    unsigned char* texels;
    GLsizei width;
    GLsizei height;
} image_t;

image_t* image_from_file(char const* filename);
void image_free(image_t*);

// Draws a png or jpg based on the file extension.
void draw_image_from_file(const char* filename);
