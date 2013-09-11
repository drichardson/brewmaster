#include "paths.h"
#include <string.h>

char const* path_basename(char const* path) {
    char const* result = strrchr(path, '/');
    if (result == NULL) {
        // No forward slash found. Assume relative path using only filename.
        return path;
    }
    // Move past the slash.
    return result+1;
}

char const* path_extension(char const* path) {
    char const* result = strrchr(path_basename(path), '.');
    if (result) {
        // Move past the dot.
        return result+1;
    }
    return NULL;
}

