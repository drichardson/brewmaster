#pragma once

#include <stdbool.h>
#include <GLES2/gl2.h>

bool texture_render_text(GLuint* texture, char const* text, char const* font, float font_size, int *rendered_width, int *rendered_height);

