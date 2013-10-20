#pragma once

#include <stdbool.h>
#include <GLES2/gl2.h>

bool read_jpeg_file(const char* filename, GLenum* formatOut, unsigned char** pixels, int *widthOut, int *heightOut);

