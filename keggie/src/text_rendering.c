#include "text_rendering.h"
#include "texture_loader.h"
#include "log.h"
#include "opengl_utilities.h"
#include "image.h"
#include <iconv.h>

#include <ft2build.h>
#include FT_FREETYPE_H

// Convert a UTF-8 string to a UTF-32 array. The returned array must be freed.
static bool utf8_to_utf32(char const* utf8, uint32_t** utf32out, size_t* utf32count);

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

    uint32_t *utf32 = NULL;
    size_t utf32count = 0;
    bool rc = utf8_to_utf32(text, &utf32, &utf32count);
    assert(rc); // Should I even care about the return value here or just display what I can?

    size_t i;
    for(i = 0; i < utf32count; ++i) {
        error = FT_Load_Char(face, utf32[i], FT_LOAD_RENDER); 
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
    if (utf32) free(utf32);
}


static bool utf8_to_utf32(char const* utf8, uint32_t** utf32out, size_t* utf32count) {
    iconv_t cd = iconv_open("UTF-32", "UTF-8");

    if (cd == (iconv_t)-1) {
        log_error("iconv_open failed with %d. %s", errno, strerror(errno));
        return false;
    }

    size_t inbufbytes = strlen(utf8);

    // Upper bounds on output is 4 times the number of characters in the UTF-8 string (1-3 bytes per character)
    // plus 1 extra 4 byte UTF-32 character for the BOM (byte order marker) which occurs at the beginning
    // of the output stream.
    size_t outbufbytes = (inbufbytes+1) * sizeof(uint32_t);
    char* out = malloc(outbufbytes);

    size_t inbufbytesleft = inbufbytes;
    size_t outbufbytesleft = outbufbytes;
    char* inbuf = (char*)utf8;
    char* outbuf = out;
    int rc = iconv(cd, &inbuf, &inbufbytesleft, &outbuf, &outbufbytesleft);
    bool result = true;
    if (rc == -1) {
        log_error("iconv failed with -1. errno is %d: %s", errno, strerror(errno));
        result = false;
    }

    rc = iconv_close(cd);
    if (rc != 0) log_error("iconv_close failed with %d: %s", errno, strerror(errno));

    if (result) {
        *utf32out = (uint32_t*)out;
        *utf32count = outbufbytes - outbufbytesleft;
    } else {
        if (out) free(out);
    }

    return result;
}

