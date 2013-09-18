#pragma once

// Clamped 0-1 red, green, blue, and alpha.

typedef struct {
    GLfloat r;
    GLfloat g;
    GLfloat b;
    GLfloat a;
} rgba_t;

static inline rgba_t rgba_make(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    rgba_t r;
    r.r = red;
    r.g = green;
    r.b = blue;
    r.a = alpha;
    return r;
}

static inline rgba_t rgb_make(GLfloat red, GLfloat green, GLfloat blue) {
    return rgba_make(red, green, blue, 1);
}

