#include "texture_loader.h"
#include "opengl_utilities.h"
#include <GLES2/gl2.h>
#include <png.h>
#include <jpeglib.h>
#include <stdlib.h>
#include <assert.h>

bool texture_load_png(const char* filename, GLuint* textureOut, int *widthOut, int *heightOut) {
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
        fprintf(stderr, "Got libpng error loading %s.\n", filename);
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
    printf("PNG has %d channels\n", channels);
    GLenum format;
    if (channels == 4) {
        format = GL_RGBA;
    } else if (channels == 3) {
        format = GL_RGB;
    } else {
        fprintf(stderr, "PNG has unsupported number of channels for texture. %d\n", channels);
    }

    //Now generate the OpenGL texture object
    GLuint texture;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D,0, format, width, height, 0, format, GL_UNSIGNED_BYTE, (GLvoid*) image_data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    check_gl();

    //clean up memory and close stuff
    png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
    free(image_data);
    free(row_pointers);
    fclose(fp);

    if (widthOut) *widthOut = width;
    if (heightOut) *heightOut = height;
    if (textureOut) *textureOut = texture;

    return true;
}

bool texture_load_jpeg(const char* filename, GLuint *textureOut, int *width, int *height) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "coulnd't open JPEG file %s\n", filename);
        return false;
    }

    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, fp);
    jpeg_read_header(&cinfo, true);

    jpeg_start_decompress(&cinfo);
    
#error stack overflow says this mysteriously needs to use a different 2nd parameters to jpeg_read_scanlines:
#error see here http://stackoverflow.com/questions/5616216/need-help-in-reading-jpeg-file-using-libjpeg
    uint8_t* pixels = malloc(cinfo.output_height * cinfo.output_width * cinfo.output_components);
    printf("Reading a JPEG that is %dx%d. %d componenets\n", cinfo.output_width, cinfo.output_height, cinfo.output_components);
    int const stride = cinfo.output_width * cinfo.output_components;
    while(cinfo.output_scanline < cinfo.output_height) {
        printf("reading into %d * %d = %d\n", cinfo.output_scanline, stride, cinfo.output_scanline * stride);
        jpeg_read_scanlines(&cinfo, pixels + cinfo.output_scanline * stride, 1);
    }

    jpeg_finish_decompress(&cinfo);

    jpeg_destroy_decompress(&cinfo);

    if (fp) fclose(fp);
    if (pixels) free(pixels);

    return false;
} 
