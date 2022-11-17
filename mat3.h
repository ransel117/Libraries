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
 *  RAN_VEC3_H                                                      - is defined if my 3d vector library is included
 *  RAN_VEC4_H                                                      - is defined if my 4d vector library is included
 *
 * TYPES:
 *  mat3                                                            - a struct containing three vec3 aka 9 floats
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
 *  void ran_mat3_printf(mat3 m)                                    - prints the values of the matrix
 *  float_t **ran_mat32opengl_mat3(mat3 m)                          - converts matrix from a struct to an array of floats for better compatibility with OpenGL
 *  mat3 ran_mat3_copy(mat3 m)                                      - copies the matrix
 *  mat3 ran_mat3_identity()                                        - makes given identity to matrix
 *  mat3 *ran_mat3_identity_array(uint32_t count)                   - makes given identity to array of matrices
 *  mat3 ran_mat3_zero()                                            - sets all members to zero
 *  mat3 ran_mat3_mul(mat3 a, mat3 b)                               - multiplies two matrices together
 *  mat3 ran_mat3_transpose(mat3 m)                                 - returns the transposed matrix
 *  vec3 ran_mat3_mulv(mat3 m, vec3 v)                              - multiplies a 3d vector with a matrix
 *  float_t ran_mat3_trace(mat3 m)                                  - returns the trace value of the matrix
 *  mat3 ran_mat3_scale(mat3 m, float_t s)                          - returns the scaled matrix
 *  float_t ran_mat3_det(mat3 m)                                    - returns the determinant of the matrix
 *  mat3 ran_mat3_inv(mat3 m)                                       - returns the inverse of the matrix
 *  mat3 ran_mat3_swap_col(mat3 m, uint32_t col1, uint32_t col2)    - swaps two columns
 *  mat3 ran_mat3_swap_row(mat3 m, uint32_t row1, uint32_t row2)    - swaps two rows
 *  float_t ran_mat3_rmc(vec3 r, mat3 m, vec3 c)                    - helper for  R (row vector) * M (matrix) * C (column vector)
 *
 *  vec4 ran_mat3_quat(mat3 m)                                      - converts 3d matrix to quaternion (4d vector)
 */
#ifndef RAN_MAT3_H
#define RAN_MAT3_H

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdint.h>

#include "vec3.h"

#ifndef RAN_VEC3_H
#error CORRECT vec3.h IS NOT INCLUDED!!
#endif /* RAN_VEC4_H */

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

typedef struct mat3
{
    vec3 c1;
    vec3 c2;
    vec3 c3;
} mat3;

RAN_INLINE void ran_mat3_printf(mat3 m)
{
    printf("Column 1 values:\n");
    ran_vec3_printf(m.c1);
    printf("Column 2 values:\n");
    ran_vec3_printf(m.c2);
    printf("Column 3 values:\n");
    ran_vec3_printf(m.c3);
}

RAN_INLINE float_t **ran_mat32opengl_mat3(mat3 m)
{
    return (float_t *[3]){
        ran_vec32opengl_vec3(m.c1),
        ran_vec32opengl_vec3(m.c2),
        ran_vec32opengl_vec3(m.c3)};
}

RAN_INLINE mat3 ran_mat3_copy(mat3 m)
{
    return (mat3){
        ran_vec3_copy(m.c1),
        ran_vec3_copy(m.c2),
        ran_vec3_copy(m.c3)};
}

RAN_INLINE mat3 ran_mat3_identity()
{
    return (mat3){
        (vec3){1.0F, 0.0F, 0.0F},
        (vec3){0.0F, 1.0F, 0.0F},
        (vec3){0.0F, 0.0F, 1.0F}};
}
RAN_INLINE mat3 *ran_mat3_identity_array(uint32_t count)
{
    mat3 m[count];

    for (uint32_t i = 0; i < count; i++)
    {
        m[i] = ran_mat3_identity();
    }

    return m;
}

RAN_INLINE mat3 ran_mat3_zero()
{
    return (mat3){0.0F};
}

RAN_INLINE mat3 ran_mat3_mul(mat3 a, mat3 b)
{
    return {(vec3){((a.c1.x * b.c1.x) + (a.c2.x * b.c1.y)) + (a.c3.x * b.c1.z),
                   ((a.c1.y * b.c1.x) + (a.c2.y * b.c1.y)) + (a.c3.y * b.c1.z),
                   ((a.c1.z * b.c1.x) + (a.c2.z * b.c1.y)) + (a.c3.z * b.c1.z)},
            (vec3){((a.c1.x * b.c2.x) + (a.c2.x * b.c2.y)) + (a.c3.x * b.c2.z),
                   ((a.c1.y * b.c2.x) + (a.c2.y * b.c2.y)) + (a.c3.y * b.c2.z),
                   ((a.c1.z * b.c2.x) + (a.c2.z * b.c2.y)) + (a.c3.z * b.c2.z)},
            (vec3){((a.c1.x * b.c3.x) + (a.c2.x * b.c3.y)) + (a.c3.x * b.c3.z),
                   ((a.c1.y * b.c3.x) + (a.c2.y * b.c3.y)) + (a.c3.y * b.c3.z),
                   ((a.c1.z * b.c3.x) + (a.c2.z * b.c3.y)) + (a.c3.z * b.c3.z)}};
}

RAN_INLINE mat3 ran_mat3_transpose(mat3 m)
{

    return (mat3){(vec3){m.c1.x, m.c2.x, m.c3.x},
                  (vec3){m.c1.y, m.c2.y, m.c3.y},
                  (vec3){m.c1.z, m.c2.z, m.c3.z}};
}

RAN_INLINE vec3 ran_mat3_mulv(mat3 m, vec3 v)
{
    return (vec3){((m.c1.x * v.x) + (m.c2.x * v.y)) + (m.c3.x * v.z),
                  ((m.c1.y * v.x) + (m.c2.y * v.y)) + (m.c3.y * v.z),
                  ((m.c1.z * v.x) + (m.c2.z * v.y)) + (m.c3.z * v.z)};
}

RAN_INLINE float_t ran_mat3_trace(mat3 m)
{
    return (m.c1.x + m.c2.y) + m.c3.z;
}

RAN_INLINE mat3 ran_mat3_scale(mat3 m, float_t s)
{
    return (mat3){(vec3){m.c1.x * s, m.c1.y * s, m.c1.z * s},
                  (vec3){m.c2.x * s, m.c2.y * s, m.c2.z * s},
                  (vec3){m.c3.x * s, m.c3.y * s, m.c3.z * s}};
}

RAN_INLINE float_t ran_mat3_det(mat3 m)
{
    float_t dest[3];
    dest[0] = (m.c1.x * ((m.c2.y * m.c3.z) - (m.c3.y * m.c2.z)));
    dest[1] = (m.c2.x * ((m.c1.y * m.c3.z) - (m.c1.z * m.c3.y)));
    dest[2] = (m.c3.x * ((m.c1.y * m.c2.z) - (m.c1.z * m.c2.y)));

    return (dest[0] - dest[1]) + dest[2];
}

RAN_INLINE mat3 ran_mat3_inv(mat3 m)
{
    mat3 dest = ran_mat3_zero();

    dest.c1.x = ((m.c2.y * m.c3.z) - (m.c2.z * m.c3.y));
    dest.c1.y = -((m.c1.y * m.c3.z) - (m.c3.y * m.c1.z));
    dest.c1.z = ((m.c1.y * m.c2.z) - (m.c2.y * m.c1.z));

    dest.c2.x = -((m.c2.x * m.c3.z) - (m.c3.x * m.c2.z));
    dest.c2.y = ((m.c1.x * m.c3.z) - (m.c1.z * m.c3.x));
    dest.c2.z = -((m.c1.x * m.c2.z) - (m.c2.x * m.c1.z));

    dest.c3.x = ((m.c2.x * m.c3.y) - (m.c3.x * m.c2.y));
    dest.c3.y = -((m.c1.x * m.c3.y) - (m.c3.x * m.c1.y));
    dest.c3.z = ((m.c1.x * m.c2.y) - (m.c1.y * m.c2.x));

    float det = 1.0F / (((m.c1.x * dest.c1.x) + (m.c1.y * dest.c2.x)) + (m.c1.z * dest.c3.x));

    return ran_mat3_scale(dest, det);
}

RAN_INLINE mat3 ran_mat3_swap_col(mat3 m, uint32_t col1, uint32_t col2)
{
    mat3 dest = ran_mat3_copy(m);
    if (col1 == 1)
    {
        if (col2 == 1)
        {
            dest.c1 = ran_vec3_copy(m.c1); // col1 col2
            dest.c1 = ran_vec3_copy(m.c1); // col2 col1
        }
        if (col2 == 2)
        {
            dest.c1 = ran_vec3_copy(m.c2); // col1 col2
            dest.c2 = ran_vec3_copy(m.c1); // col2 col1
        }
        if (col2 == 3)
        {
            dest.c1 = ran_vec3_copy(m.c3); // col1 col2
            dest.c3 = ran_vec3_copy(m.c1); // col2 col1
        }
    }
    if (col1 == 2)
    {
        if (col2 == 1)
        {
            dest.c2 = ran_vec3_copy(m.c1); // col1 col2
            dest.c1 = ran_vec3_copy(m.c2); // col2 col1
        }
        if (col2 == 2)
        {
            dest.c2 = ran_vec3_copy(m.c2); // col1 col2
            dest.c2 = ran_vec3_copy(m.c2); // col2 col1
        }
        if (col2 == 3)
        {
            dest.c2 = ran_vec3_copy(m.c3); // col1 col2
            dest.c3 = ran_vec3_copy(m.c2); // col2 col1
        }
    }
    if (col1 == 3)
    {
        if (col2 == 1)
        {
            dest.c3 = ran_vec3_copy(m.c1); // col1 col2
            dest.c1 = ran_vec3_copy(m.c3); // col2 col1
        }
        if (col2 == 2)
        {
            dest.c3 = ran_vec3_copy(m.c2); // col1 col2
            dest.c2 = ran_vec3_copy(m.c3); // col2 col1
        }
        if (col2 == 3)
        {
            dest.c3 = ran_vec3_copy(m.c3); // col1 col2
            dest.c3 = ran_vec3_copy(m.c3); // col2 col1
        }
    }
    return dest;
}

RAN_INLINE mat3 ran_mat3_swap_row(mat3 m, uint32_t row1, uint32_t row2)
{
    mat3 dest = ran_mat3_copy(m);
    if (row1 == 1)
    {
        if (row2 == 1)
        {
            dest.c1.x = m.c1.x; // row1 row2
            dest.c2.x = m.c2.x; // row1 row2
            dest.c3.x = m.c3.x; // row1 row2

            dest.c1.x = m.c1.x; // row2 row1
            dest.c2.x = m.c2.x; // row2 row1
            dest.c3.x = m.c3.x; // row2 row1
        }
        if (row2 == 2)
        {
            dest.c1.x = m.c1.y; // row1 row2
            dest.c2.x = m.c2.y; // row1 row2
            dest.c3.x = m.c3.y; // row1 row2

            dest.c1.y = m.c1.x; // row2 row1
            dest.c2.y = m.c2.x; // row2 row1
            dest.c3.y = m.c3.x; // row2 row1
        }
        if (row2 == 3)
        {
            dest.c1.x = m.c1.z; // row1 row2
            dest.c2.x = m.c2.z; // row1 row2
            dest.c3.x = m.c3.z; // row1 row2

            dest.c1.z = m.c1.x; // row2 row1
            dest.c2.z = m.c2.x; // row2 row1
            dest.c3.z = m.c3.x; // row2 row1
        }
    }
    if (row1 == 2)
    {
        if (row2 == 1)
        {
            dest.c1.y = m.c1.x; // row1 row2
            dest.c2.y = m.c2.x; // row1 row2
            dest.c3.y = m.c3.x; // row1 row2

            dest.c1.x = m.c1.y; // row2 row1
            dest.c2.x = m.c2.y; // row2 row1
            dest.c3.x = m.c3.y; // row2 row1
        }
        if (row2 == 2)
        {
            dest.c1.y = m.c1.y; // row1 row2
            dest.c2.y = m.c2.y; // row1 row2
            dest.c3.y = m.c3.y; // row1 row2

            dest.c1.y = m.c1.y; // row2 row1
            dest.c2.y = m.c2.y; // row2 row1
            dest.c3.y = m.c3.y; // row2 row1
        }
        if (row2 == 3)
        {
            dest.c1.y = m.c1.z; // row1 row2
            dest.c2.y = m.c2.z; // row1 row2
            dest.c3.y = m.c3.z; // row1 row2

            dest.c1.z = m.c1.y; // row2 row1
            dest.c2.z = m.c2.y; // row2 row1
            dest.c3.z = m.c3.y; // row2 row1
        }
    }
    if (row1 == 3)
    {
        if (row2 == 1)
        {
            dest.c1.z = m.c1.x; // row1 row2
            dest.c2.z = m.c2.x; // row1 row2
            dest.c3.z = m.c3.x; // row1 row2

            dest.c1.x = m.c1.z; // row2 row1
            dest.c2.x = m.c2.z; // row2 row1
            dest.c3.x = m.c3.z; // row2 row1
        }
        if (row2 == 2)
        {
            dest.c1.z = m.c1.y; // row1 row2
            dest.c2.z = m.c2.y; // row1 row2
            dest.c3.z = m.c3.y; // row1 row2

            dest.c1.y = m.c1.z; // row2 row1
            dest.c2.y = m.c2.z; // row2 row1
            dest.c3.y = m.c3.z; // row2 row1
        }
        if (row2 == 3)
        {
            dest.c1.z = m.c1.z; // row1 row2
            dest.c2.z = m.c2.z; // row1 row2
            dest.c3.z = m.c3.z; // row1 row2

            dest.c1.z = m.c1.z; // row2 row1
            dest.c2.z = m.c2.z; // row2 row1
            dest.c3.z = m.c3.z; // row2 row1
        }
    }
    return dest;
}

RAN_INLINE float_t ran_mat3_rmc(vec3 r, mat3 m, vec3 c)
{
    return ran_vec3_dot(r, ran_mat3_mulv(m, c));
}

#if defined(RAN_VEC4_H)
RAN_INLINE vec4 ran_mat3_quat(mat3 m)
{
    float_t r, rinv;
    vec4 dest = ran_vec4_zero();

    float_t trace = ran_mat3_trace(m);
    if (trace >= 0.0F)
    {
        r = sqrtf(1.0F + trace);
        rinv = 0.5F / r;

        dest.x = rinv * (m.c2.z - m.c3.y);
        dest.y = rinv * (m.c3.x - m.c1.z);
        dest.z = rinv * (m.c1.y - m.c2.x);
        dest.w = r * 0.5F;
    }
    else if (m.c1.x >= m.c2.y && m.c1.x >= m.c3.z)
    {
        r = sqrtf(((1.0F - m.c2.y) - m.c3.z) + m.c1.x);
        rinv = 0.5F / r;

        dest.x = r * 0.5F;
        dest.y = rinv * (m.c1.y + m.c2.x);
        dest.z = rinv * (m.c1.z + m.c3.x);
        dest.w = rinv * (m.c2.z - m.c3.y);
    }
    else if (m.c2.y >= m.c3.z)
    {
        r = sqrtf(((1.0F - m.c1.x) - m.c3.z) + m.c2.y);
        rinv = 0.5F / r;

        dest.x = rinv * (m.c1.y + m.c2.x);
        dest.y = r * 0.5F;
        dest.z = rinv * (m.c2.z + m.c3.y);
        dest.w = rinv * (m.c3.x - m.c1.z);
    }
    else
    {
        r = sqrtf(((1.0F - m.c1.x) - m.c2.y) + m.c3.z);
        rinv = 0.5F / r;

        dest.x = rinv * (m.c1.z + m.c3.x);
        dest.y = rinv * (m.c2.z + m.c3.y);
        dest.z = r * 0.5F;
        dest.w = rinv * (m.c1.y - m.c2.x);
    }

    return dest;
}
#endif /* Using vec4 library */

#endif /* RAN_MAT3_H */