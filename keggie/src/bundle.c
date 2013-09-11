#include "bundle.h"
#include "log.h"
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <libgen.h>
#include <limits.h>
#include <stdio.h>

void bundle_path(char* path, size_t max_path) {
    if (readlink("/proc/self/exe", path, max_path) != -1) {
       dirname(path);
       size_t len = strlen(path);
       if (len+1 < max_path) {
           path[len] = '/';
           path[len+1] = 0;
       }
    } else {
        log_error("bundle_path: couldn't get path to current bundle. %d: %s", errno, strerror(errno));
    }
}

void bundle_resource_path(char* path, size_t max_path, char const* resource) {
    char buf[PATH_MAX];
    bundle_path(buf, sizeof(buf));
    snprintf(path, max_path, "%s%s", buf, resource);
}

image_t* bundle_image_named(char const* name) {
    char path[PATH_MAX];
    char resource_subpath[PATH_MAX];
    bundle_resource_path(resource_subpath, sizeof(resource_subpath), "images");
    snprintf(path, sizeof(path), "%s/%s", resource_subpath, name);
    return image_with_path(path);
}

