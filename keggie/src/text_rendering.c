#include "text_rendering.h"
#include "texture_loader.h"
#include "log.h"
#include "opengl_utilities.h"

#include <ft2build.h>
#include FT_FREETYPE_H

void text_render(gl_context_t* ctx, char const* text, char const* font, float font_size, GLfloat x, GLfloat y) {
    FT_Library library = NULL;
    FT_Face face = NULL;
    FT_Error error;

    error = FT_Init_FreeType(&library);
   if (error != 0) {
        log_error("Error initializing FreeType library. error = %x", error);
        goto done;
    }
    
    error = FT_New_Face(library, font, 0, &face);
    if (error != 0)  {
        log_error("Error reading font face from %s. error = %x", font, error);
        goto done;
    }

    error = FT_Set_Char_Size(face, font_size, font_size, 72, 72);
    if (error != 0)  {
        log_error("Error setting font size error = %x", error);
        goto done;
    }

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    FT_GlyphSlot g = face->glyph;

    const double sx = 1, sy = 1;

    for(;*text;text++) {
        error = FT_Load_Char(face, *text, FT_LOAD_RENDER); 
        if (error) {
            log_error("Font error: %x", error);
            continue;
        }

        glTexImage2D(GL_TEXTURE_2D,
                0, // level of detail 0 (not scaled down)
                GL_ALPHA, // internal format of texture
                g->bitmap.width, 
                g->bitmap.rows,
                0, // border, must be 0 for gl es 2.0
                GL_ALPHA, // format of texel data
                GL_UNSIGNED_BYTE, // data type of texel
                g->bitmap.buffer);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        check_gl();
        float x2 = x + g->bitmap_left * sx;
        float y2 = -y - g->bitmap_top * sy;
        float w = g->bitmap.width * sx;
        float h = g->bitmap.rows * sy;

#error do drawing stuff using image_draw. Probably refactor into common code or use image draw directly
        GLfloat box[4][4] = {
            {x2,     -y2    , 0, 0},
            {x2 + w, -y2    , 1, 0},
            {x2,     -y2 - h, 0, 1},
            {x2 + w, -y2 - h, 1, 1},
        };

        glBufferData(GL_ARRAY_BUFFER, sizeof box, box, GL_DYNAMIC_DRAW);
        check_gl();
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        check_gl();

        x += (g->advance.x >> 6) * sx;
        y += (g->advance.y >> 6) * sy; 
    }

done:
    if (face) FT_Done_Face(face);
    if (library) FT_Done_FreeType(library);
}

