#pragma once

#include "GLES2/gl2.h"
#include <stdbool.h>

bool shader_load_from_string(GLenum type, const char *shader_source, GLuint* shader_out);
bool shader_load_from_file(GLenum shaderType, const char* filename, GLuint* shader_out);
