#include "texture_loader.h"
#include "opengl_utilities.h"
#include "log.h"
#include <GLES2/gl2.h>
#include <stdlib.h>
#include "png_reader.h"
#include "jpeg_reader.h"

bool texture_load_image(unsigned char const* pixels, GLenum format, GLuint* texture_out, int width, int height) {
    GLuint texture;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D,0, format, width, height, 0, format, GL_UNSIGNED_BYTE, pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    check_gl();

    *texture_out = texture;

    return true;
}

bool texture_load_png(const char* filename, GLenum* formatOut, GLuint* textureOut, int *widthOut, int *heightOut) {
    unsigned char* pixels = NULL;
    GLenum format = 0;
    int width = 0;
    int height = 0;
    bool result = read_png_file(filename, &format, &pixels, &width, &height);
    if (!result) return false;

    //Now generate the OpenGL texture object
    result = texture_load_image(pixels, format, textureOut, width, height);

    free(pixels);

    if (formatOut) *formatOut = format;
    if (widthOut) *widthOut = width;
    if (heightOut) *heightOut = height;

    return result;
}

bool texture_load_jpeg(const char* filename, GLenum *formatOut, GLuint *textureOut, int *widthOut, int *heightOut) {
    GLenum format;
    int width = 0, height = 0;
    unsigned char* pixels = NULL;
    bool result = read_jpeg_file(filename, &format, &pixels, &width, &height);
    if (!result) return false;

    result = texture_load_image(pixels, format, textureOut, width, height);

    if (pixels) free(pixels);
    if (widthOut) *widthOut = width;
    if (heightOut) *heightOut = height;
    if (formatOut) *formatOut = format;

    return result;
} 

