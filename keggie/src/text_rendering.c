#include "text_rendering.h"
#include "texture_loader.h"
#include "threads.h"
#include <ft2build.h>
#include FT_FREETYPE_H
#include <assert.h>
#include <stdio.h>

// Current implementation is not thread safe, which is why there are thread_assert_is_main()
// calls peppered throughout the code. This code assumes that all the drawing will be
// done on the main thread.
static FT_Library _library;

void text_rendering_initialization(void) {
    thread_assert_is_main();    
    FT_Init_FreeType(&_library);
}


bool texture_render_text(GLuint* texture_out, char const* text, char const* font, float font_size, int *rendered_width, int *rendered_height) {
    thread_assert_is_main();


    return false;
}

