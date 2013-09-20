#include "png_reader.h"
#include <stdio.h>
#include <png.h>
#include <stdlib.h>
#include "log.h"

bool read_png_file(const char* filename, GLenum* formatOut, unsigned char** pixels, int *widthOut, int *heightOut) {
    //header for testing if it is a png
    png_byte header[8];

    int width, height;

    //open file as binary
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        return false;
    }

    //read the header
    fread(header, 1, 8, fp);

    png_structp png_ptr = NULL;
    png_infop info_ptr = NULL, end_info = NULL;

    //test if png
    int is_png = !png_sig_cmp(header, 0, 8);
    if (!is_png) {
        fclose(fp);
        return false;
    }

    //create png struct
    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr) {
        fclose(fp);
        return false;
    }

    // libpng uses setjmp/longjmp for error/exception handling.
    if (setjmp(png_jmpbuf(png_ptr))) {
        log_error("Got libpng error loading %s.", filename);
        if (png_ptr) {
            png_destroy_read_struct(&png_ptr, info_ptr ? &info_ptr : NULL, end_info ? &end_info : NULL);
        }
        if (fp) fclose(fp);
        return false;
    }

    //create png info struct
    info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        png_destroy_read_struct(&png_ptr, (png_infopp) NULL, (png_infopp) NULL);
        fclose(fp);
        return false;
    }

    //create png info struct
    end_info = png_create_info_struct(png_ptr);
    if (!end_info) {
        png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp) NULL);
        fclose(fp);
        return false;
    }

    //init png reading
    png_init_io(png_ptr, fp);

    //let libpng know you already read the first 8 bytes
    png_set_sig_bytes(png_ptr, 8);

    // read all the info up to the image data
    png_read_info(png_ptr, info_ptr);

    //variables to pass to get info
    int bit_depth, color_type;
    png_uint_32 twidth, theight;

    // get info about png
    png_get_IHDR(png_ptr, info_ptr, &twidth, &theight, &bit_depth, &color_type, NULL, NULL, NULL);

    //update width and height based on png info
    width = twidth;
    height = theight;

    // Update the png info struct.
    png_read_update_info(png_ptr, info_ptr);

    // Row size in bytes.
    int rowbytes = png_get_rowbytes(png_ptr, info_ptr);

    // Allocate the image_data as a big block, to be given to opengl
    png_byte *image_data = malloc(sizeof(png_byte)*rowbytes*height);
    if (!image_data) {
        //clean up memory and close stuff
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        fclose(fp);
        return false;
    }

    //row_pointers is for pointing to image_data for reading the png with libpng
    png_bytep *row_pointers = malloc(sizeof(png_bytep)*height);
    if (!row_pointers) {
        //clean up memory and close stuff
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        free(image_data);
        fclose(fp);
        return false;
    }
    // set the individual row_pointers to point at the correct offsets of image_data
    int i;
    for (i = 0; i < height; ++i)
        row_pointers[height - 1 - i] = image_data + i * rowbytes;

    //read the png into image_data through row_pointers
    png_read_image(png_ptr, row_pointers);

    png_byte channels = png_get_channels(png_ptr, info_ptr);
    GLenum format;
    if (channels == 4) {
        format = GL_RGBA;
    } else if (channels == 3) {
        format = GL_RGB;
    } else {
        log_error("PNG has unsupported number of channels for texture. %d", channels);
    }

    //clean up memory and close stuff
    png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
    free(row_pointers);
    fclose(fp);

    if (widthOut) *widthOut = width;
    if (heightOut) *heightOut = height;
    if (formatOut) *formatOut = format;
    if (pixels) {
        *pixels = image_data;
    } else {
        free(image_data);
    }

    return true;
}
