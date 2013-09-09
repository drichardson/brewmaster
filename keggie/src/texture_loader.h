#pragma once

#include "GLES2/gl2.h"
#include <stdbool.h>

bool texture_load_image(unsigned char const* pixel, GLenum format, GLuint* texture, int width, int height);
bool texture_load_png(const char* filename, GLuint* texture, int *width, int *height);
bool texture_load_jpeg(const char* filename, GLuint* texture, int *width, int *height);

