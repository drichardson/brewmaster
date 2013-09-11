#pragma once

#include <stddef.h>
#include "image.h"

// Return a path to this application
void bundle_path(char* path, size_t max_path);

// Return the path to the resouce specified as a sub-path from the current
// application.
void bundle_resource_path(char* path, size_t max_path, char const* resource);

// Create an image_t for an image with the given name located in the bundles images directory.
image_t* bundle_image_named(char const* name);

