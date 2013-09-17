#include "image.h"
#include "texture_loader.h"
#include "opengl_utilities.h"
#include "paths.h"
#include <assert.h>
#include "log.h"

static image_t* image_constructor_base(GLuint texture, GLenum format, GLsizei width, GLsizei height) {
    image_t* result = (image_t*)calloc(sizeof(image_t), 1);
    result->texture = texture;
    result->width = width;
    result->height = height;
    result->format = format;

    return result;
}

static image_t* image_constructor(char const* filename, bool (*texture_loader)(const char*,GLenum*,GLuint*,int*,int*)) {
    // TODO:DOUG Probably better to load the image and convert to texture as needed.
    // There are only a certain number of texture units and we don't want to use them
    // all up. May need a texture unit manager that has a LRU cache for images.
    int w, h;
    GLuint texture;
    GLenum format;
    if (!texture_loader(filename, &format, &texture, &w, &h)) return NULL;
    return image_constructor_base(texture, format, w, h);
}

image_t* image_with_path(char const* path) {
   char const* extension = path_extension(path); 
   if (extension) {
       if(strcasecmp(extension, "png") == 0) {
           return image_constructor(path, texture_load_png);
       } else if(strcasecmp(extension, "jpg") == 0 || strcasecmp(extension, "jpeg") == 0) {
           return image_constructor(path, texture_load_jpeg);
       }
   }
   return NULL;
}

image_t* image_with_pixels(unsigned char const* pixels, GLenum format, GLsizei width, GLsizei height) {
    GLuint texture;
    if(!texture_load_image(pixels, format, &texture, width, height)) return NULL;
    return image_constructor_base(texture, format, width, height);
}

void image_free(image_t* img) {
    glDeleteTextures(1, &img->texture);
    free(img);
}

size2d_t image_size(image_t* img) {
    size2d_t result;
    result.width = img->width;
    result.height = img->height;
    return result;
}

GLuint image_gl_texture(image_t* img) {
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

    GLfloat const* textureCoordinates = options_mask & IMAGE_OPTION_FLIPPED ? toolbarTextureCoordinatesFlipped : toolbarTextureCoordinates;

    gl_context_use_main_program(ctx);

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

