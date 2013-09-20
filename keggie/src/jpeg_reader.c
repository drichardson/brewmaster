#include "jpeg_reader.h"
#include "log.h"
#include <stdlib.h>
#include <stdio.h>
#include <jpeglib.h>

bool read_jpeg_file(const char* filename, GLenum* formatOut, unsigned char** pixelsOut, int *widthOut, int *heightOut) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        log_error("couldn't open JPEG file %s", filename);
        return false;
    }

    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, fp);
    jpeg_read_header(&cinfo, true);

    jpeg_start_decompress(&cinfo);
    uint8_t* pixels = malloc(cinfo.output_height * cinfo.output_width * cinfo.output_components);
    int const stride = cinfo.output_width * cinfo.output_components;
    while(cinfo.output_scanline < cinfo.output_height) {
        unsigned char *rowp[4];
        rowp[0] = (unsigned char*) pixels + ((cinfo.output_height - (cinfo.output_scanline+1)) * stride);
        rowp[1] = (unsigned char*) pixels + ((cinfo.output_height - (cinfo.output_scanline+2)) * stride);
        rowp[2] = (unsigned char*) pixels + ((cinfo.output_height - (cinfo.output_scanline+3)) * stride);
        rowp[3] = (unsigned char*) pixels + ((cinfo.output_height - (cinfo.output_scanline+4)) * stride);
        jpeg_read_scanlines(&cinfo, rowp, 4);
    }

    //Now generate the OpenGL texture object
    GLenum const format = GL_RGB;
    int width = cinfo.output_width;
    int height = cinfo.output_height;

    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);

    if (fp) fclose(fp);
    if (widthOut) *widthOut = width;
    if (heightOut) *heightOut = height;
    if (formatOut) *formatOut = format;
    if (pixelsOut) {
        *pixelsOut = pixels;
    } else {
        free(pixels);
    }

    return true;
}

