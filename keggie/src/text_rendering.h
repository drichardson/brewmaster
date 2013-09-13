#pragma once

#include <stdbool.h>
#include <GLES2/gl2.h>
#include "gl_context.h"

void text_render(gl_context_t*, char const* text, char const* font, float font_size, GLfloat x, GLfloat y);

