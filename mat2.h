/**
 * MIT License
 *
 * @copyright (c) 2022 Ransel117
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *
 * NOTE: DOES NOT WORK WITH CGLM
 */
/**
 * MACROS:
 *  RAN_UTILS                                                       - is defined if any of my other libraries is included
 *  RAN_INLINE static inline __attribute((always_inline))           - makes sure the compiler makes everything inline
 *  RAN_vec2_H                                                      - is defined if my 4d vector library is included
 *
 * TYPES:
 *  mat2                                                            - a struct containing two vec2 aka four floats
 *
 * FUNCTIONS:
 *  float_t ran_deg2rad(float_t deg)                                - converts degrees to radians
 *  float_t ran_rad2deg(float_t rad)                                - converts radians to degrees
 *  float_t ran_maxf(float_t a, float_t b)                          - returns the bigger value
 *  int32_t ran_maxi(int32_t a, int32_t b)
 *  float_t ran_minf(float_t a, float_t b)                          - returns the smaller value
 *  int32_t ran_mini(int32_t a, int32_t b)
 *  float_t ran_clampf(float_t val, float_t minval, float_t maxval) - clamps the value between the minimum value and the maximum value
 *  int32_t ran_clampi(float_t val, int32_t minval, int32_t maxval)
 *  void ran_mat2_printf(mat2 m)                                    - prints the values of the matrix
 *  float_t **ran_mat22opengl_mat2(mat2 m)                          - converts matrix from a struct to an array of floats for better compatibility with OpenGL
 *  mat2 ran_mat2_copy(mat2 m)                                      - copies the matrix
 *  mat2 ran_mat2_identity()                                        - makes given identity to matrix
 *  mat2 *ran_mat2_identity_array(uint32_t count)                   - makes given identity to array of matrices
 *  mat2 ran_mat2_zero()                                            - sets all members to zero
 *  mat2 ran_mat2_mul(mat2 a, mat2 b)                               - multiplies two matrices together
 *  mat2 ran_mat2_transpose(mat2 m)                                 - returns the transposed matrix
 *  vec2 ran_mat2_mulv(mat2 m, vec2 v)                              - multiplies a 2d vector with a matrix
 *  float_t ran_mat2_trace(mat2 m)                                  - returns the trace value of the matrix
 *  mat2 ran_mat2_scale(mat2 m, float_t s)                          - returns the scaled matrix
 *  float_t ran_mat2_det(mat2 m)                                    - returns the determinant of the matrix
 *  mat2 ran_mat2_inv(mat2 m)                                       - returns the inverse matrix
 *  mat2 ran_mat2_swap_col(mat2 m, uint32_t col1, uint32_t col2)    - swaps two columns with eachother
 *  mat2 ran_mat2_swap_row(mat2 m, uint32_t row1, uint32_t row2)    - swaps two rows with eachother
 *  float_t ran_mat2_rmc(vec2 r, mat2 m, vec2 c)                    - helper for  R (row vector) * M (matrix) * C (column vector)
 */
#ifndef RAN_MAT2_H
#define RAN_MAT2_H

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdint.h>

#include "vec2.h"

#ifndef RAN_VEC2_H
#error CORRECT vec2.h IS NOT INCLUDED!!
#endif /* RAN_VEC2_H */

#ifndef RAN_UTILS
#define RAN_UTILS

#if defined(_MSC_VER)
#define RAN_INLINE __forceinline
#define RAN_ALIGN(X) __declspec(align(X))
#else
#define RAN_INLINE static inline __attribute((always_inline))
#define RAN_ALIGN(X) __attribute((aligned(X)))
#endif

#ifndef M_PI
#define RAN_PI ((float_t)3.14159265358979323846)
#else
#define RAN_PI M_PI
#endif /* Make sure PI exists */

RAN_INLINE float_t ran_deg2rad(float_t deg)
{
    return deg * (RAN_PI / 180);
}
RAN_INLINE float_t ran_rad2deg(float_t rad)
{
    return rad * (180 / RAN_PI);
}

RAN_INLINE float_t ran_pow2f(float_t num)
{
    return num * num;
}
RAN_INLINE int32_t ran_pow2i(int32_t num)
{
    return num * num;
}

RAN_INLINE float_t ran_maxf(float_t a, float_t b)
{
    return a > b ? a : b;
}
RAN_INLINE float_t ran_minf(float_t a, float_t b)
{
    return a < b ? a : b;
}

RAN_INLINE int32_t ran_maxi(int32_t a, int32_t b)
{
    return a > b ? a : b;
}
RAN_INLINE int32_t ran_mini(int32_t a, int32_t b)
{
    return a < b ? a : b;
}

RAN_INLINE float_t ran_clampf(float_t val, float_t minval, float_t maxval)
{
    return ran_minf(ran_maxf(val, minval), maxval);
}
RAN_INLINE int32_t ran_clampi(int32_t val, int32_t minval, int32_t maxval)
{
    return ran_mini(ran_maxi(val, minval), maxval);
}
#endif /* RAN_UTILS */

typedef struct mat2
{
    vec2 c1;
    vec2 c2;
} mat2;

RAN_INLINE void ran_mat2_printf(mat2 m)
{
    printf("Column 1 values:\n");
    ran_vec2_printf(m.c1);
    printf("Column 2 values:\n");
    ran_vec2_printf(m.c2);
}

RAN_INLINE float_t **ran_mat22opengl_mat2(mat2 m)
{
    return (float_t *[2]){ran_vec22opengl_vec2(m.c1), ran_vec22opengl_vec2(m.c2)};
}

RAN_INLINE mat2 ran_mat2_copy(mat2 m)
{
    return (mat2){ran_vec2_copy(m.c1), ran_vec2_copy(m.c2)};
}

RAN_INLINE mat2 ran_mat2_identity()
{
    return (mat2){
        (vec2){1.0F, 0.0F}, (vec2){0.0F, 1.0F}};
}
RAN_INLINE mat2 *ran_mat2_identity_array(uint32_t count)
{
    mat2 dest[count];

    for (uint32_t i = 0; i < count; i++)
    {
        dest[i] = ran_mat2_identity();
    }

    return dest;
}

RAN_INLINE mat2 ran_mat2_zero()
{
    return (mat2){0.0F};
}

RAN_INLINE mat2 ran_mat2_mul(mat2 a, mat2 b)
{
    return (mat2){(vec2){(a.c1.x * b.c1.x) + (a.c2.x * b.c1.y),
                         (a.c1.y * b.c1.x) + (a.c2.y * b.c1.y)},
                  (vec2){(a.c1.x * b.c2.x) + (a.c2.x * b.c2.y),
                         (a.c1.y * b.c2.x) + (a.c2.y * b.c2.y)}};
}

RAN_INLINE mat2 ran_mat2_transpose(mat2 m)
{
    return (mat2){(vec2){m.c1.x, m.c2.x},
                  (vec2){m.c1.y, m.c2.y}};
}

RAN_INLINE vec2 ran_mat2_mulv(mat2 m, vec2 v)
{
    return (vec2){(m.c1.x * v.x) + (m.c2.x * v.y),
                  (m.c1.y * v.x) + (m.c2.y * v.y)};
}

RAN_INLINE float_t ran_mat2_trace(mat2 m)
{
    return m.c1.x + m.c2.y;
}

RAN_INLINE mat2 ran_mat2_scale(mat2 m, float_t s)
{
    return (mat2){(vec2){m.c1.x * s, m.c1.y * s},
                  (vec2){m.c2.x * s, m.c2.y * s}};
}

RAN_INLINE float_t ran_mat2_det(mat2 m)
{
    return (m.c1.x * m.c2.y) - (m.c2.x * m.c1.y);
}

RAN_INLINE mat2 ran_mat2_inv(mat2 m)
{
    float det = 1.0f / ((m.c1.x * m.c2.y) - (m.c1.y * m.c2.x));

    return (mat2){(vec2){m.c2.y * det, -(m.c1.y * det)},
                  (vec2){-(m.c2.x * det), m.c1.x * det}};
}

RAN_INLINE mat2 ran_mat2_swap_col(mat2 m, uint32_t col1, uint32_t col2)
{
    mat2 dest = ran_mat2_copy(m);

    if (col1 == 1)
    {
        if (col2 == 1)
        {
            dest.c1 = ran_vec2_copy(m.c1); // col1 col2
            dest.c1 = ran_vec2_copy(m.c1); // col2 col1
        }
        if (col2 == 2)
        {
            dest.c1 = ran_vec2_copy(m.c2); // col1 col2
            dest.c2 = ran_vec2_copy(m.c1); // col2 col1
        }
    }
    if (col1 == 2)
    {
        if (col2 == 1)
        {
            dest.c2 = ran_vec2_copy(m.c1); // col1 col2
            dest.c1 = ran_vec2_copy(m.c2); // col2 col1
        }
        if (col2 == 2)
        {
            dest.c2 = ran_vec2_copy(m.c2); // col1 col2
            dest.c2 = ran_vec2_copy(m.c2); // col2 col1
        }
    }

    return dest;
}

RAN_INLINE mat2 ran_mat2_swap_row(mat2 m, uint32_t row1, uint32_t row2)
{
    mat2 dest = ran_mat2_copy(m);

    if (row1 == 1)
    {
        if (row2 == 1)
        {
            dest.c1.x = m.c1.x; // row1 row2
            dest.c2.x = m.c2.x; // row1 row2

            dest.c1.x = m.c1.x; // row2 row1
            dest.c2.x = m.c2.x; // row2 row1
        }
        if (row2 == 2)
        {
            dest.c1.x = m.c1.y; // row1 row2
            dest.c2.x = m.c2.y; // row1 row2

            dest.c1.y = m.c1.x; // row2 row1
            dest.c2.y = m.c2.x; // row2 row1
        }
    }
    if (row1 == 2)
    {
        if (row2 == 1)
        {
            dest.c1.y = m.c1.x; // row1 row2
            dest.c2.y = m.c2.x; // row1 row2

            dest.c1.x = m.c1.y; // row2 row1
            dest.c2.x = m.c2.y; // row2 row1
        }
        if (row2 == 2)
        {
            dest.c1.y = m.c1.y; // row1 row2
            dest.c2.y = m.c2.y; // row1 row2

            dest.c1.y = m.c1.y; // row2 row1
            dest.c2.y = m.c2.y; // row2 row1
        }
    }

    return dest;
}

RAN_INLINE float_t ran_mat2_rmc(vec2 r, mat2 m, vec2 c)
{
    return ran_vec2_dot(r, ran_mat2_mulv(m, c));
}

#endif /* RAN_MAT2_H */