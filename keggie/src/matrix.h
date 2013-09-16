#pragma once

#include <GLES2/gl2.h>

// matrix_t is a 4x4 matrix laid out in column-major order in memory. m[ij] represents
// the ith row and jth column. Can be cast to an OpenGL GLfloat column major array.
typedef struct {
    GLfloat m11, m21, m31, m41;
    GLfloat m12, m22, m32, m42;
    GLfloat m13, m23, m33, m43;
    GLfloat m14, m24, m34, m44;
} matrix_t;

extern matrix_t const identity_matrix;

// Multiply matrix m1 by m2 and place the result in result. result is undefined if it is also used as
// one of the input parameters.
void matrix_multiply(matrix_t const* m1, matrix_t const* m2, matrix_t* result);

// Make a translation matrix and put the result in result. This wipes out anything that was previously in result.
void matrix_make_translation(GLfloat xTranslation, GLfloat yTranslation, GLfloat zTranslation, matrix_t* result);

// Make a scaling matrix and put the result in result. This wipes out anything that was previously in result.
void matrix_make_scale(GLfloat xScale, GLfloat yScale, GLfloat zScale, matrix_t* result);

// Make a rotation matrix and put the result in result. This wipes out anything that was previously in result.
void matrix_make_rotation_around_z(GLfloat radians, matrix_t* result);

