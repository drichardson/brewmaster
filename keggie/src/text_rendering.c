#include "text_rendering.h"
#include "texture_loader.h"
#include "log.h"
#include "opengl_utilities.h"

#include <ft2build.h>
#include FT_FREETYPE_H

void text_render(char const* text, char const* font, float font_size, GLfloat x, GLfloat y) {
    FT_Library library = NULL;
    FT_Face face = NULL;
    FT_Error error;

    error = FT_Init_FreeType(&library);
   
   if (error != 0) {
        log_error("Error initializing FreeType library. error = %d", error);
        goto done;
    }
    
    error = FT_New_Face(library, font, 0, &face);
   
    if (error != 0)  {
        log_error("Error reading font face from %s. error = %d", font, error);
        goto done;
    }

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    FT_GlyphSlot g = face->glyph;

    while(*text) {
        if (FT_Load_Char(face, *text, FT_LOAD_RENDER) != 0) continue;

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
    }

done:
    if (face) FT_Done_Face(face);
    if (library) FT_Done_FreeType(library);
}

