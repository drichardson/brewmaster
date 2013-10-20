#include "jpeg_reader.h"
#include "log.h"
#include <stdlib.h>
#include <stdio.h>
#include <jpeglib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>

#include "debug.h"

#define TIME_LOAD 1
#define USE_MMAP 1

bool read_jpeg_file(const char* filename, GLenum* formatOut, unsigned char** pixelsOut, int *widthOut, int *heightOut) {
#if TIME_LOAD
    debug_timer timer;
    debug_timer_init(&timer);
#endif

#if USE_MMAP
    int fd = open(filename, O_RDONLY | O_CLOEXEC);
    if (fd == -1) {
        log_error("couldn't open JPEG file %s. %d: %s", filename, errno, strerror(errno));
        return false;
    }

    struct stat statbuf;
    if (fstat(fd, &statbuf) == -1) {
        log_error("couldn't get stat info for %s", filename);
        close(fd);
        return false;
    }
    void* jpeg_bytes = mmap(NULL, statbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (jpeg_bytes == MAP_FAILED) {
        log_error("couldn't memory map %s. %d: %s", filename, errno, strerror(errno));
        close(fd);
        return false;
    }
#else
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        log_error("couldn't open JPEG file %s", filename);
        return false;
    }
#endif

    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
#if USE_MMAP
    jpeg_mem_src(&cinfo, jpeg_bytes, statbuf.st_size);
#else
    jpeg_stdio_src(&cinfo, fp);
#endif
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

#if USE_MMAP
    if (munmap(jpeg_bytes, statbuf.st_size) == -1) {
        log_error("error unmap file %s. %d: %s", filename, errno, strerror(errno));
    }
    close(fd);
#else
    fclose(fp);
#endif
    if (widthOut) *widthOut = width;
    if (heightOut) *heightOut = height;
    if (formatOut) *formatOut = format;
    if (pixelsOut) {
        *pixelsOut = pixels;
    } else {
        free(pixels);
    }

#if TIME_LOAD
    debug_timer_log(&timer, "Opened JPEG %s", filename);
#endif

    return true;
}

