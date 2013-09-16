#pragma once

#include <GLES2/gl2.h>

// matrix_t is a 4x4 matrix laid out in column-major order in memory. m[ij] represents
// the ith row and jth column. Can be cast to an OpenGL GLfloat column major array.
typedef struct {
    GLfloat m11, m12, m13, m14;
    GLfloat m21, m22, m23, m24;
    GLfloat m31, m32, m33, m34;
    GLfloat m41, m42, m43, m44;
} matrix_t;

extern matrix_t const identity_matrix;

void matrix_multiply(matrix_t const* m1, matrix_t const* m2, matrix_t* result);
void matrix_make_scale(GLfloat xScale, GLfloat yScale, GLfloat zScale, matrix_t* result);
void matrix_make_rotation_around_z(GLfloat radians, matrix_t* result);

