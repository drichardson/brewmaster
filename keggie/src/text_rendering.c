#include "text_rendering.h"
#include "texture_loader.h"
#include "log.h"
#include "opengl_utilities.h"
#include "image.h"
#include <iconv.h>

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_TRUETYPE_TABLES_H
#include FT_TRUETYPE_IDS_H

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

#if 0
    {
        // DEBUG: log the character maps
        int cmi = 0;
        log_debug("Font %s has %d charmaps", font, face->num_charmaps);
        log_debug("TT_PLATFORM_MACINTOSH = %d", TT_PLATFORM_MACINTOSH);
        for(cmi = 0; cmi < face->num_charmaps; cmi++) {
            FT_CharMap r = face->charmaps[cmi];
            int c1 = (r->encoding >> 24) & 0xff;
            int c2 = (r->encoding >> 16) & 0xff;
            int c3 = (r->encoding >> 8) & 0xff;
            int c4 = (r->encoding >> 0) & 0xff;
            log_debug("charmap %d: encoding=%x (%c%c%c%c), platform_id=%hd, encoding_id=%hd, Language ID=%lu", cmi, r->encoding, c1, c2, c3, c4, r->platform_id, r->encoding_id, FT_Get_CMap_Language_ID(r));
        }
    }
#endif

#if 0
    // DEBUG: Enumerate character codes in font. Useful to figure out why a specific unicode
    // character isn't rendering like you expect (i.e., it may not be in the font).
    {
        FT_ULong  charcode;                                              
        FT_UInt   gindex;                                                

        log_debug("Character codes for font %s", font);
        charcode = FT_Get_First_Char( face, &gindex );                   
        while (gindex != 0) {
            log_debug("  charcode: %lx, gindex: %d", charcode, gindex);
            charcode = FT_Get_Next_Char( face, charcode, &gindex );
        } 
    }
#endif

    error = FT_Select_Charmap(face, FT_ENCODING_UNICODE);
    if (error != 0) {
        log_error("Error selecting unicode character map.");
        goto done;
    }

    error = FT_Set_Char_Size(face, 0 /* 0 is same as vertical size*/, font_size*64, 72, 0 /* 0 is same as horizontal res */);
    if (error != 0)  {
        log_error("Error setting font size error = %x", error);
        goto done;
    }

    FT_GlyphSlot g = face->glyph;

    uint32_t *utf32 = NULL;
    size_t utf32count = 0;
    bool rc = utf8_to_utf32(text, &utf32, &utf32count);
    assert(rc); // Should I even care about the return value here or just display what I can?

    size_t i; // start at 1 instead of 0 to skip the unicode BOM at the beginning.
    for(i = 1; i < utf32count; ++i) {
        FT_UInt glyph_index= FT_Get_Char_Index(face, utf32[i]);
        if (glyph_index == 0) {
            log_debug("Font error: couldn't get glyph index for character code %x at index %d", utf32[i], i);
            continue;
        }
        error = FT_Load_Glyph(face, glyph_index, FT_LOAD_DEFAULT);
        if (error) {
            log_error("Font error: couldn't load glyph. %x", error);
            continue;
        }
        error = FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);
        if (error) {
            log_error("Font error: render glyph failed with %x", error);
            continue;
        }

        image_t* image = image_with_pixels(g->bitmap.buffer, GL_ALPHA, g->bitmap.width, g->bitmap.rows);
        image_set_tint(image, color);
        rect2d_t r;
        r.size = image_size(image);
        // log_debug("g->bitmap.rows = %d, g->bitmap_top = %d, g->bitmap_left = %d", g->bitmap.rows, g->bitmap_top, g->bitmap_left);
        // Adjust point.y so that small items, like the degrees symbol, are positioned correctly.
        r.origin = point_make(point.x + g->bitmap_left, point.y + (g->bitmap_top - g->bitmap.rows));
        image_draw_with_options(image, ctx, r, IMAGE_OPTION_FLIPPED);
        image_free(image);

        // x and y advanced given in 1/64th of pixels, so divide by 64.
        point.x += g->advance.x >> 6;
        // point.y += g->advance.y >> 6; // not doing y advances right now
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
        *utf32count = (outbufbytes - outbufbytesleft) / sizeof(uint32_t);
    } else {
        if (out) free(out);
    }

    return result;
}

