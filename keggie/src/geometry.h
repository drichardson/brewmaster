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

