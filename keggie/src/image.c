#include "image.h"
#include "texture_loader.h"
#include "opengl_utilities.h"
#include <assert.h>

image_t* image_from_jpg_file(char const* filename) {
    // TODO:DOUG Probably better to load the image and convert to texture as needed.
    // There are only a certain number of texture units and we don't want to use them
    // all up. May need a texture unit manager that has a LRU cache for images.
    int w, h;
    GLuint texture;
    if (!texture_load_jpeg(filename, &texture, &w, &h)) return NULL;

    image_t* result = (image_t*)calloc(sizeof(image_t), 1);
    result->texture = texture;
    result->width = w;
    result->height = h;
    return result;
}

void image_free(image_t* img) {
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
    // Draw the toolbar background
#if 0
    GLfloat toolbarVertices[] = {
        -1.0, 1.0, 0.0,
        -1.0, 0.8, 0.0,
        1.0, 0.8, 0.0,
        1.0, 1.0, 0.0,
        -1.0, 1.0, 0.0,
        1.0, 0.8, 0.0
    };
#else
    GLfloat v[3*6];
    v[0] = rect_left(r); v[1] = rect_top(r); v[2] = 0;
    v[3] = rect_left(r); v[4] = rect_bottom(r); v[5] = 0;
    v[6] = rect_right(r); v[7] = rect_bottom(r); v[8] = 0;
    v[9] = rect_right(r); v[10] = rect_top(r); v[11] = 0;
    v[12] = rect_left(r); v[13] = rect_top(r); v[14] = 0;
    v[15] = rect_right(r); v[16] = rect_bottom(r); v[17] = 0;
#endif

    // TODO: try with indices too
    GLfloat toolbarTextureCoordinates[] = {
        0, 1,
        0, 0,
        1, 0,
        1, 1,
        0, 1,
        1, 0
    };

    gl_context_use_main_program(ctx);

    //GLint fragColor = glGetUniformLocation(ctx->mainProgram, "u_fragColor"); 
    GLint enableTexture = glGetUniformLocation(ctx->mainProgram, "u_enableTexture"); 
    GLint texture = glGetUniformLocation(ctx->mainProgram, "u_texture");
    assert(enableTexture != -1);
    assert(texture != -1);

    glVertexAttribPointer(ctx->a_position, 3, GL_FLOAT, GL_FALSE, 0, v);
    check_gl();
    glEnableVertexAttribArray(ctx->a_position);
    check_gl();
    glVertexAttribPointer(ctx->a_textureCoordinates, 2, GL_FLOAT, GL_FALSE, 0, toolbarTextureCoordinates);
    check_gl();
    glEnableVertexAttribArray(ctx->a_textureCoordinates);
    //glUniform4f(fragColor, 0,1,0,1);
    glUniform1i(enableTexture, GL_TRUE);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, image_gl_texture(img));
    check_gl();

    glDrawArrays(GL_TRIANGLES, 0, 6);
    check_gl();
    glUniform1i(enableTexture, GL_FALSE);
    check_gl();
    glDisableVertexAttribArray(ctx->a_textureCoordinates);
    check_gl();

}


