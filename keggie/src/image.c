#include "image.h"
#include "texture_loader.h"
#include "png_reader.h"
#include "jpeg_reader.h"
#include "opengl_utilities.h"
#include "paths.h"
#include <assert.h>
#include "log.h"

#define INVALID_TEXTURE ((GLuint)0)

static size_t bytes_per_pixel_for_gl_format(GLenum format);

image_t* image_with_bytes(void* bytes, GLenum format, GLsizei width, GLsizei height, unsigned options) {
    // assert if IMAGE_OPTION_COPY and IMAGE_OPTION_NO_FREE set because this will leak.
    assert(!((options & IMAGE_OPTION_COPY) && (options & IMAGE_OPTION_NO_FREE)));

    image_t* img = (image_t*)calloc(sizeof(image_t), 1);
    img->texture = INVALID_TEXTURE;
    img->width = width;
    img->height = height;
    img->format = format;
    img->tint = rgba_make(0,0,0,0);
    img->options = options;

    if (options & IMAGE_OPTION_COPY) {
        size_t bytes_per_pixel = bytes_per_pixel_for_gl_format(format);
        size_t total_bytes = width * height * bytes_per_pixel;
        img->bytes = malloc(total_bytes);
        memcpy(img->bytes, bytes, total_bytes);
    } else {
        img->bytes = bytes;
    }
    return img;
}

void image_free(image_t* img) {
    if (img->texture != INVALID_TEXTURE) glDeleteTextures(1, &img->texture);
    if (!(img->options & IMAGE_OPTION_NO_FREE)) free(img);
}

static image_t* image_with_path_helper(char const* filename, bool (*image_reader)(const char*,GLenum*,unsigned char**,int*,int*)) {
    int w = 0, h = 0;
    unsigned char* bytes = NULL;
    GLenum format = 0;
    if (!image_reader(filename, &format, &bytes, &w, &h)) return NULL;
    return image_with_bytes(bytes, format, w, h, 0);
}

image_t* image_with_path(char const* path) {
   char const* extension = path_extension(path); 
   if (extension) {
       if(strcasecmp(extension, "png") == 0) {
           return image_with_path_helper(path, read_png_file);
       } else if(strcasecmp(extension, "jpg") == 0 || strcasecmp(extension, "jpeg") == 0) {
           return image_with_path_helper(path, read_jpeg_file);
       }
   }
   return NULL;
}

size2d_t image_size(image_t* img) {
    size2d_t result;
    result.width = img->width;
    result.height = img->height;
    return result;
}

static GLuint image_gl_texture(image_t* img) {
    if (img->texture == INVALID_TEXTURE) {
        bool rc = texture_load_image(img->bytes, img->format, &img->texture, img->width, img->height);
        assert(rc);
    }

    return img->texture;
}

void image_draw(image_t* img, gl_context_t* ctx, rect2d_t r) {
    image_draw_with_options(img, ctx, r, 0);
}

void image_draw_with_options(image_t* img, gl_context_t* ctx, rect2d_t r, unsigned options_mask) {
    // Draw the toolbar background
    GLfloat v[3*6];
    v[0] = rect_left(r); v[1] = rect_top(r); v[2] = 0;
    v[3] = rect_left(r); v[4] = rect_bottom(r); v[5] = 0;
    v[6] = rect_right(r); v[7] = rect_bottom(r); v[8] = 0;
    v[9] = rect_right(r); v[10] = rect_top(r); v[11] = 0;
    v[12] = rect_left(r); v[13] = rect_top(r); v[14] = 0;
    v[15] = rect_right(r); v[16] = rect_bottom(r); v[17] = 0;

    static GLfloat const toolbarTextureCoordinates[] = {
        0, 1,
        0, 0,
        1, 0,
        1, 1,
        0, 1,
        1, 0
    };

    static GLfloat const toolbarTextureCoordinatesFlipped[] = {
        0, 0,
        0, 1,
        1, 1,
        1, 0,
        0, 0,
        1, 1
    };

    GLfloat const* textureCoordinates = options_mask & IMAGE_DRAW_OPTION_FLIPPED ? toolbarTextureCoordinatesFlipped : toolbarTextureCoordinates;

    gl_context_use_main_program(ctx);

    glUniform4f(ctx->u_fragColor, img->tint.r, img->tint.g, img->tint.b, img->tint.a);

    glVertexAttribPointer(ctx->a_position, 3, GL_FLOAT, GL_FALSE, 0, v);
    glEnableVertexAttribArray(ctx->a_position);
    glVertexAttribPointer(ctx->a_textureCoordinates, 2, GL_FLOAT, GL_FALSE, 0, textureCoordinates);
    glEnableVertexAttribArray(ctx->a_textureCoordinates);
    glUniform1i(ctx->u_enableTexture, GL_TRUE);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, image_gl_texture(img));

    switch(img->format) {
        case GL_ALPHA:
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            break;
        case GL_RGBA:
            glEnable(GL_BLEND);
            glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
            break;
        case GL_RGB:
            glDisable(GL_BLEND);
            break;
        default:
            log_error("Unsupported image format %d", img->format);
            assert(false);
            break;
    }

    glDrawArrays(GL_TRIANGLES, 0, 6);
    glDisableVertexAttribArray(ctx->a_textureCoordinates);

    glDisable(GL_BLEND);

    check_gl();
}

void image_set_tint(image_t* img, rgba_t tint) {
    img->tint = tint;
}

static size_t bytes_per_pixel_for_gl_format(GLenum format) {
    switch(format) {
        case GL_RGBA:
            return 4;
        case GL_RGB:
            return 3;
        case GL_ALPHA:
            return 1;
    }
    assert(0);
    return 4;
}

