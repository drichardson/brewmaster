#include "matrix.h"
#include <math.h>
#include <assert.h>

matrix_t const identity_matrix = {
    1, 0, 0, 0, // column 1
    0, 1, 0, 0, // column 2
    0, 0, 1, 0, // column 3
    0, 0, 0, 1  // column 4
};

void matrix_multiply(matrix_t const* a, matrix_t const* b, matrix_t* r) {
    assert(a != r && b != r);

    GLfloat* d = (GLfloat*)r;
    GLfloat const* m0 = (GLfloat const*)a;
    GLfloat const* m1 = (GLfloat const*)b;

    // TODO:DOUG Consider SIMD implementations.
    // http://code.google.com/p/math-neon/source/browse/trunk/math_mat4.c

    d[0] = m0[0]*m1[0] + m0[4]*m1[1] + m0[8]*m1[2] + m0[12]*m1[3];
    d[1] = m0[1]*m1[0] + m0[5]*m1[1] + m0[9]*m1[2] + m0[13]*m1[3];
    d[2] = m0[2]*m1[0] + m0[6]*m1[1] + m0[10]*m1[2] + m0[14]*m1[3];
    d[3] = m0[3]*m1[0] + m0[7]*m1[1] + m0[11]*m1[2] + m0[15]*m1[3];
    d[4] = m0[0]*m1[4] + m0[4]*m1[5] + m0[8]*m1[6] + m0[12]*m1[7];
    d[5] = m0[1]*m1[4] + m0[5]*m1[5] + m0[9]*m1[6] + m0[13]*m1[7];
    d[6] = m0[2]*m1[4] + m0[6]*m1[5] + m0[10]*m1[6] + m0[14]*m1[7];
    d[7] = m0[3]*m1[4] + m0[7]*m1[5] + m0[11]*m1[6] + m0[15]*m1[7];
    d[8] = m0[0]*m1[8] + m0[4]*m1[9] + m0[8]*m1[10] + m0[12]*m1[11];
    d[9] = m0[1]*m1[8] + m0[5]*m1[9] + m0[9]*m1[10] + m0[13]*m1[11];
    d[10] = m0[2]*m1[8] + m0[6]*m1[9] + m0[10]*m1[10] + m0[14]*m1[11];
    d[11] = m0[3]*m1[8] + m0[7]*m1[9] + m0[11]*m1[10] + m0[15]*m1[11];
    d[12] = m0[0]*m1[12] + m0[4]*m1[13] + m0[8]*m1[14] + m0[12]*m1[15];
    d[13] = m0[1]*m1[12] + m0[5]*m1[13] + m0[9]*m1[14] + m0[13]*m1[15];
    d[14] = m0[2]*m1[12] + m0[6]*m1[13] + m0[10]*m1[14] + m0[14]*m1[15];
    d[15] = m0[3]*m1[12] + m0[7]*m1[13] + m0[11]*m1[14] + m0[15]*m1[15];
}

void matrix_make_translation(GLfloat xTranslation, GLfloat yTranslation, GLfloat zTranslation, matrix_t* result) {
    *result = identity_matrix;
    result->m14 = xTranslation;
    result->m24 = yTranslation;
    result->m34 = zTranslation;
}

void matrix_make_scale(GLfloat xScale, GLfloat yScale, GLfloat zScale, matrix_t* r) {
    *r = identity_matrix;
    r->m11 = xScale;
    r->m22 = yScale;
    r->m33 = zScale;
}

void matrix_make_rotation_around_z(GLfloat radians, matrix_t* r) {
    *r = identity_matrix;

    r->m11 = cosf(radians);
    r->m12 = -sinf(radians);
    r->m21 = sinf(radians);
    r->m22 = cosf(radians);
}


