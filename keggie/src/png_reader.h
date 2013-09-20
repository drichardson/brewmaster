#pragma once
#include <stdbool.h>
#include <GLES2/gl2.h>

// read a png file. Caller must free pixels when done.
bool read_png_file(const char* filename, GLenum* formatOut, unsigned char** pixels, int *width, int *height);
