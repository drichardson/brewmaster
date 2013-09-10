#pragma once

#include <stddef.h>

// Return a path to this application
void bundle_path(char* path, size_t max_path);

// Return the path to the resouce specified as a sub-path from the current
// application.
void bundle_resource_path(char* path, size_t max_path, char const* resource);

