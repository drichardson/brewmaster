#include <stdio.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_TRUETYPE_TABLES_H
#include FT_TRUETYPE_IDS_H


int main(int argc, char const** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: fontinfo <font_file>\n");
        return 1;
    }
    
    char const* font = argv[1];

    FT_Library library = NULL;
    FT_Face face = NULL;
    FT_Error error;

    error = FT_Init_FreeType(&library);
    if (error != 0) {
        fprintf(stderr, "Error initializing FreeType library. error = %x\n", error);
        return 1;
    }
    
    error = FT_New_Face(library, font, 0, &face);
    if (error != 0)  {
        fprintf(stderr, "Error reading font face from %s. error = %x\n", font, error);
        return 1;
    }

    // log the character maps
    int cmi = 0;
    printf("============================================\n");
    printf("Font %s has %d charmaps\n", font, face->num_charmaps);
    printf("============================================\n");
    for(cmi = 0; cmi < face->num_charmaps; cmi++) {
        FT_CharMap r = face->charmaps[cmi];
        int c1 = (r->encoding >> 24) & 0xff;
        int c2 = (r->encoding >> 16) & 0xff;
        int c3 = (r->encoding >> 8) & 0xff;
        int c4 = (r->encoding >> 0) & 0xff;
        printf("charmap %d: encoding=%x (%c%c%c%c), platform_id=%hd, encoding_id=%hd, Language ID=%lu\n", cmi, r->encoding, c1, c2, c3, c4, r->platform_id, r->encoding_id, FT_Get_CMap_Language_ID(r));
    }

    // Enumerate character codes in font. Useful to figure out why a specific unicode
    // character isn't rendering like you expect (i.e., it may not be in the font).
    FT_ULong  charcode;                                              
    FT_UInt   gindex;                                                

    printf("============================================\n");
    printf("Character codes for font %s\n", font);
    printf("============================================\n");
    charcode = FT_Get_First_Char( face, &gindex ); 
    while (gindex != 0) {
        printf("  charcode: %lx, gindex: %d\n", charcode, gindex);
        charcode = FT_Get_Next_Char( face, charcode, &gindex );
    } 

    return 0;
}


