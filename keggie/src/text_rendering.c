#include "text_rendering.h"
#include "texture_loader.h"
#include "log.h"
#include "opengl_utilities.h"
#include "image.h"

#include <ft2build.h>
#include FT_FREETYPE_H

void text_render(gl_context_t* ctx, char const* text, char const* font, float font_size, point2d_t point, rgba_t color) {
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

    error = FT_Set_Char_Size(face, 0, font_size*64, 72, 72);
    if (error != 0)  {
        log_error("Error setting font size error = %x", error);
        goto done;
    }

    FT_GlyphSlot g = face->glyph;

    const double sx = 1, sy = 1;

    for(;*text;text++) {
        error = FT_Load_Char(face, *text, FT_LOAD_RENDER); 
        if (error) {
            log_error("Font error: %x", error);
            continue;
        }

        image_t* image = image_with_pixels(g->bitmap.buffer, GL_ALPHA, g->bitmap.width, g->bitmap.rows);
        image_set_tint(image, color);
        rect2d_t r;
        r.size = image_size(image);
        r.origin = point_make(point.x, point.y);
        image_draw_with_options(image, ctx, r, IMAGE_OPTION_FLIPPED);
        image_free(image);

        point.x += (g->advance.x >> 6) * sx;
        point.y += (g->advance.y >> 6) * sy; 
    }

done:
    if (face) FT_Done_Face(face);
    if (library) FT_Done_FreeType(library);
}

