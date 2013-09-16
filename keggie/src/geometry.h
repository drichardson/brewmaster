#pragma once

typedef struct {
    float width;
    float height;
} size2d_t;

typedef struct {
    float x;
    float y;
} point2d_t;

typedef struct {
    point2d_t origin;
    size2d_t size;
} rect2d_t;

static inline size2d_t size_make(float width, float height) {
    size2d_t s;
    s.width = width;
    s.height = height;
    return s;
}

static inline point2d_t point_make(float x, float y) {
    point2d_t p;
    p.x = x;
    p.y = y;
    return p;
}

static inline float rect_top(rect2d_t r) {
    return r.origin.y + r.size.height;
}

static inline float rect_left(rect2d_t r) {
    return r.origin.x;
}

static inline float rect_bottom(rect2d_t r) {
    return r.origin.y;
}

static inline float rect_right(rect2d_t r) {
    return r.origin.x + r.size.width;
}

static inline rect2d_t rect_make(float x, float y, float width, float height) {
    rect2d_t r;
    r.origin.x = x;
    r.origin.y = y;
    r.size.width = width;
    r.size.height = height;
    return r;
}

static inline point2d_t rect_midpoint(rect2d_t r) {
    point2d_t p;
    p.x = (r.origin.x + r.size.width) / 2.0;
    p.y = (r.origin.y + r.size.height) / 2.0;
    return p;
}

// Get a rectangle of size s that is centered in r. Like a midpoint but with dimentions.
static inline rect2d_t rect_midrect_of_size(rect2d_t r, size2d_t s) {
    rect2d_t result;
    result.origin.x = (r.origin.x + r.size.width - s.width) / 2.0;
    result.origin.y = (r.origin.y + r.size.height - s.height) / 2.0;
    result.size = s;
    return result;
}

