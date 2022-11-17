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
 *  RAN_VEC4_H                                                      - is defined if my 4d vector library is included
 *  RAN_VEC3_H                                                      - is defined if my 3d vector library is included
 *  RAN_MAT3_H                                                      - is defined if my 3d matrix library is included
 *
 * TYPES:
 *  mat4                                                            - a struct containing four vec4 aka 16 floats
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
 *  void ran_mat4_printf(mat4 m)                                    - prints the values of the matrix
 *  float_t **ran_mat42opengl_mat4(mat4 m)                          - converts matrix from a struct to an array of floats for better compatibility with OpenGL
 *  mat4 ran_mat4_copy(mat4 m)                                      - copies the matrix
 *  mat4 ran_mat4_identity()                                        - makes given identity to matrix
 *  mat4 *ran_mat4_identity_array(uint32_t count)                   - makes given identity to array of matrices
 *  mat4 ran_mat4_zero()                                            - sets all members to zero
 *  mat4 ran_mat4_mul(mat4 a, mat4 b)                               - multiplies two matrices together
 *  mat4 ran_mat4_mulN(mat4 *m[], uint32_t len)                     - multiplies a matrix with N number of matrices
 *  vec4 ran_mat4_mulv(mat4 m, vec4 v)                              - multiplies a 4d vector with a matrix
 *  float_t ran_mat4_trace(mat4 m)                                  - returns the trace value of the matrix
 *  float_t ran_mat4_trace3(mat4 m)                                 - returns the trace value of the rotation part of the matrix
 *  vec4 ran_mat4_quat(mat4 m)                                      - converts matrix rotation part to a quaternion (4d vector)
 *  mat4 ran_mat4_transpose(mat4 m)                                 - returns the transposed matrix
 *  mat4 ran_mat4_scale(mat4 m, float_t s)                          - returns the scaled matrix
 *  float_t ran_mat4_det(mat4 mat)                                  - returns the determinant of the matrix
 *  mat4 ran_mat4_inv(mat4 m)                                       - returns the inverse matrix
 *  mat4 ran_mat4_swap_col(mat4 m, uint32_t col1, uint32_t col2)    - swaps two columns with eachother
 *  mat4 ran_mat4_swap_row(mat4 m, uint32_t row1, uint32_t row2)    - swaps two rows with eachother
 *  float_t ran_mat4_rmc(vec4 r, mat4 m, vec4 c)                    - helper for  R (row vector) * M (matrix) * C (column vector)
 *
 *  vec3 ran_mat4_mulv3(mat4 m, vec3 v, float_t last)               - multiplies a 3d vector with matrix
 *  mat3 ran_mat4_pick3(mat4 m)                                     - copies the upper left of 4d matrix to 3d matrix
 *  mat3 ran_mat4_pick3t(mat4 m)                                    - copies the transposed upperleft of 4d matrix to 3d matrix
 *  mat4 ran_mat4_ins3(mat4 m1, mat3 m2)                            - copies 3d matrix to upper left of 4d matrix
 */
#ifndef RAN_MAT4_H
#define RAN_MAT4_H

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdint.h>

#include "vec4.h"

#ifndef RAN_VEC4_H
#error CORRECT vec4.h IS NOT INCLUDED!!
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

typedef RAN_ALIGN(16) struct mat4
{
    vec4 c1;
    vec4 c2;
    vec4 c3;
    vec4 c4;
} mat4;

RAN_INLINE void ran_mat4_printf(mat4 m)
{
    printf("Column 1 values:\n");
    ran_vec4_printf(m.c1);
    printf("Column 2 values:\n");
    ran_vec4_printf(m.c2);
    printf("Column 3 values:\n");
    ran_vec4_printf(m.c3);
    printf("Column 4 values:\n");
    ran_vec4_printf(m.c4);
}

RAN_INLINE float_t **ran_mat42opengl_mat4(mat4 m)
{
    return (float_t *[4]){ran_vec42opengl_vec4(m.c1),
                          ran_vec42opengl_vec4(m.c2),
                          ran_vec42opengl_vec4(m.c3),
                          ran_vec42opengl_vec4(m.c4)};
}

RAN_INLINE mat4 ran_mat4_copy(mat4 m)
{
    return (mat4){
        ran_vec4_copy(m.c1),
        ran_vec4_copy(m.c2),
        ran_vec4_copy(m.c3),
        ran_vec4_copy(m.c4)};
}

RAN_INLINE mat4 ran_mat4_identity()
{
    return (mat4){
        (vec4){1.0f, 0.0F, 0.0F, 0.0F},
        (vec4){0.0F, 1.0f, 0.0F, 0.0F},
        (vec4){0.0F, 0.0F, 1.0f, 0.0F},
        (vec4){0.0F, 0.0F, 0.0F, 1.0f}};
}
RAN_INLINE mat4 *ran_mat4_identity_array(uint32_t count)
{
    mat4 m[count];

    for (uint32_t i = 0; i < count; i++)
    {
        m[i] = ran_mat4_identity();
    }

    return m;
}

RAN_INLINE mat4 ran_mat4_zero()
{
    return (mat4){0.0F};
}

RAN_INLINE mat4 ran_mat4_mul(mat4 a, mat4 b)
{
    return (mat4){
        {((a.c1.x * b.c1.x) + (a.c2.x * b.c1.y)) + ((a.c3.x * b.c1.z) + (a.c4.x * b.c1.w)),
         ((a.c1.y * b.c1.x) + (a.c2.y * b.c1.y)) + ((a.c3.y * b.c1.z) + (a.c4.y * b.c1.w)),
         ((a.c1.z * b.c1.x) + (a.c2.z * b.c1.y)) + ((a.c3.z * b.c1.z) + (a.c4.z * b.c1.w)),
         ((a.c1.w * b.c1.x) + (a.c2.w * b.c1.y)) + ((a.c3.w * b.c1.z) + (a.c4.w * b.c1.w))},
        {((a.c1.x * b.c2.x) + (a.c2.x * b.c2.y)) + ((a.c3.x * b.c2.z) + (a.c4.x * b.c2.w)),
         ((a.c1.y * b.c2.x) + (a.c2.y * b.c2.y)) + ((a.c3.y * b.c2.z) + (a.c4.y * b.c2.w)),
         ((a.c1.z * b.c2.x) + (a.c2.z * b.c2.y)) + ((a.c3.z * b.c2.z) + (a.c4.z * b.c2.w)),
         ((a.c1.w * b.c2.x) + (a.c2.w * b.c2.y)) + ((a.c3.w * b.c2.z) + (a.c4.w * b.c2.w))},
        {((a.c1.x * b.c3.x) + (a.c2.x * b.c3.y)) + ((a.c3.x * b.c3.z) + (a.c4.x * b.c3.w)),
         ((a.c1.y * b.c3.x) + (a.c2.y * b.c3.y)) + ((a.c3.y * b.c3.z) + (a.c4.y * b.c3.w)),
         ((a.c1.z * b.c3.x) + (a.c2.z * b.c3.y)) + ((a.c3.z * b.c3.z) + (a.c4.z * b.c3.w)),
         ((a.c1.w * b.c3.x) + (a.c2.w * b.c3.y)) + ((a.c3.w * b.c3.z) + (a.c4.w * b.c3.w))},
        {((a.c1.x * b.c4.x) + (a.c2.x * b.c4.y)) + ((a.c3.x * b.c4.z) + (a.c4.x * b.c4.w)),
         ((a.c1.y * b.c4.x) + (a.c2.y * b.c4.y)) + ((a.c3.y * b.c4.z) + (a.c4.y * b.c4.w)),
         ((a.c1.z * b.c4.x) + (a.c2.z * b.c4.y)) + ((a.c3.z * b.c4.z) + (a.c4.z * b.c4.w)),
         ((a.c1.w * b.c4.x) + (a.c2.w * b.c4.y)) + ((a.c3.w * b.c4.z) + (a.c4.w * b.c4.w))}};
}
RAN_INLINE mat4 ran_mat4_mulN(mat4 *m[], uint32_t len)
{

    mat4 dest = ran_mat4_mul(*m[0], *m[1]);

    for (uint32_t i = 2; i < len; i++)
    {
        dest = ran_mat4_mul(dest, *m[i]);
    }

    return dest;
}
RAN_INLINE vec4 ran_mat4_mulv(mat4 m, vec4 v)
{
    return (vec4){
        ((m.c1.x * v.x) + (m.c2.x * v.y)) + ((m.c3.x * v.z) + (m.c4.x * v.w)),
        ((m.c1.y * v.x) + (m.c2.y * v.y)) + ((m.c3.y * v.z) + (m.c4.y * v.w)),
        ((m.c1.z * v.x) + (m.c2.z * v.y)) + ((m.c3.z * v.z) + (m.c4.z * v.w)),
        ((m.c1.w * v.x) + (m.c2.w * v.y)) + ((m.c3.w * v.z) + (m.c4.w * v.w))};
}

RAN_INLINE float_t ran_mat4_trace(mat4 m)
{
    return (m.c1.x + m.c2.y) + (m.c3.z + m.c4.w);
}
RAN_INLINE float_t ran_mat4_trace3(mat4 m)
{
    return m.c1.x + (m.c2.y + m.c3.z);
}

RAN_INLINE vec4 ran_mat4_quat(mat4 m)
{
    float trace, r, rinv;

    vec4 dest = ran_vec4_zero();

    trace = (m.c1.x + m.c2.y) + m.c3.z;

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

RAN_INLINE mat4 ran_mat4_transpose(mat4 m)
{
    return (mat4){
        (vec4){m.c1.x, m.c2.x, m.c3.x, m.c4.x},
        (vec4){m.c1.y, m.c2.y, m.c3.y, m.c4.y},
        (vec4){m.c1.z, m.c2.z, m.c3.z, m.c4.z},
        (vec4){m.c1.w, m.c2.w, m.c3.w, m.c4.w},
    };
}

RAN_INLINE mat4 ran_mat4_scale(mat4 m, float_t s)
{
    return (mat4){
        ran_vec4_scale(m.c1, s),
        ran_vec4_scale(m.c2, s),
        ran_vec4_scale(m.c3, s),
        ran_vec4_scale(m.c4, s)};
}

RAN_INLINE float_t ran_mat4_det(mat4 mat)
{
    float t[6];
    float dest[4];

    t[0] = ((mat.c3.z * mat.c4.w) - (mat.c4.z * mat.c3.w));
    t[1] = ((mat.c3.y * mat.c4.w) - (mat.c4.y * mat.c3.w));
    t[2] = ((mat.c3.y * mat.c4.z) - (mat.c4.y * mat.c3.z));
    t[3] = ((mat.c3.x * mat.c4.w) - (mat.c4.x * mat.c3.w));
    t[4] = ((mat.c3.x * mat.c4.z) - (mat.c4.x * mat.c3.z));
    t[5] = ((mat.c3.x * mat.c4.y) - (mat.c4.x * mat.c3.y));

    dest[0] = mat.c1.x * (((mat.c2.y * t[0]) - (mat.c2.z * t[1])) + (mat.c2.w * t[2]));
    dest[1] = mat.c1.y * (((mat.c2.x * t[0]) - (mat.c2.z * t[3])) + (mat.c2.w * t[4]));
    dest[2] = mat.c1.z * (((mat.c2.x * t[1]) - (mat.c2.y * t[3])) + (mat.c2.w * t[5]));
    dest[3] = mat.c1.w * (((mat.c2.x * t[2]) - (mat.c2.y * t[4])) + (mat.c2.z * t[5]));

    return (dest[0] - dest[1]) + (dest[2] - dest[3]);
}

RAN_INLINE mat4 ran_mat4_inv(mat4 mat)
{
    float t[6];
    float p[2];
    float det;
    mat4 dest = ran_mat4_zero();

    t[0] = ((mat.c3.z * mat.c4.w) - (mat.c4.z * mat.c3.w));
    t[1] = ((mat.c3.y * mat.c4.w) - (mat.c4.y * mat.c3.w));
    t[2] = ((mat.c3.y * mat.c4.z) - (mat.c4.y * mat.c3.z));
    t[3] = ((mat.c3.x * mat.c4.w) - (mat.c4.x * mat.c3.w));
    t[4] = ((mat.c3.x * mat.c4.z) - (mat.c4.x * mat.c3.z));
    t[5] = ((mat.c3.x * mat.c4.y) - (mat.c4.x * mat.c3.y));

    dest.c1.x = ((mat.c2.y * t[0]) - (mat.c2.z * t[1])) + (mat.c2.w * t[2]);
    dest.c2.x = -(((mat.c2.x * t[0]) - (mat.c2.z * t[3])) + (mat.c2.w * t[4]));
    dest.c3.x = ((mat.c2.x * t[1]) - (mat.c2.y * t[3])) + (mat.c2.w * t[5]);
    dest.c4.x = -(((mat.c2.x * t[2]) - (mat.c2.y * t[4])) + (mat.c2.z * t[5]));

    dest.c1.y = -(((mat.c1.y * t[0]) - (mat.c1.z * t[1])) + (mat.c1.w * t[2]));
    dest.c2.y = ((mat.c1.x * t[0]) - (mat.c1.z * t[3])) + (mat.c1.w * t[4]);
    dest.c3.y = -(((mat.c1.x * t[1]) - (mat.c1.y * t[3])) + (mat.c1.w * t[5]));
    dest.c4.y = ((mat.c1.x * t[2]) - (mat.c1.y * t[4])) + (mat.c1.z * t[5]);

    t[0] = ((mat.c2.z * mat.c4.w) - (mat.c4.z * mat.c2.w));
    t[1] = ((mat.c2.y * mat.c4.w) - (mat.c4.y * mat.c2.w));
    t[2] = ((mat.c2.y * mat.c4.z) - (mat.c4.y * mat.c2.z));
    t[3] = ((mat.c2.x * mat.c4.w) - (mat.c4.x * mat.c2.w));
    t[4] = ((mat.c2.x * mat.c4.z) - (mat.c4.x * mat.c2.z));
    t[5] = ((mat.c2.x * mat.c4.y) - (mat.c4.x * mat.c2.y));

    dest.c1.z = ((mat.c1.y * t[0]) - (mat.c1.z * t[1])) + (mat.c1.w * t[2]);
    dest.c2.z = -(((mat.c1.x * t[0]) - (mat.c1.z * t[3])) + (mat.c1.w * t[4]));
    dest.c3.z = ((mat.c1.x * t[1]) - (mat.c1.y * t[3])) + (mat.c1.w * t[5]);
    dest.c4.z = -(((mat.c1.x * t[2]) - (mat.c1.y * t[4])) + (mat.c1.z * t[5]));

    t[0] = ((mat.c2.z * mat.c3.w) - (mat.c3.z * mat.c2.w));
    t[1] = ((mat.c2.y * mat.c3.w) - (mat.c3.y * mat.c2.w));
    t[2] = ((mat.c2.y * mat.c3.z) - (mat.c3.y * mat.c2.z));
    t[3] = ((mat.c2.x * mat.c3.w) - (mat.c3.x * mat.c2.w));
    t[4] = ((mat.c2.x * mat.c3.z) - (mat.c3.x * mat.c2.z));
    t[5] = ((mat.c2.x * mat.c3.y) - (mat.c3.x * mat.c2.y));

    dest.c1.w = -(((mat.c1.y * t[0]) - (mat.c1.z * t[1])) + (mat.c1.w * t[2]));
    dest.c2.w = ((mat.c1.x * t[0]) - (mat.c1.z * t[3])) + (mat.c1.w * t[4]);
    dest.c3.w = -(((mat.c1.x * t[1]) - (mat.c1.y * t[3])) + (mat.c1.w * t[5]));
    dest.c4.w = ((mat.c1.x * t[2]) - (mat.c1.y * t[4])) + (mat.c1.z * t[5]);
    p[0] = ((mat.c1.x * dest.c1.x) + (mat.c1.y * dest.c2.x));
    p[1] = ((mat.c1.z * dest.c3.x) + (mat.c1.w * dest.c4.x));
    det = 1.0f / (p[0] + p[1]);

    return ran_mat4_scale(dest, det);
}

RAN_INLINE mat4 ran_mat4_swap_col(mat4 m, uint32_t col1, uint32_t col2)
{
    mat4 dest = ran_mat4_copy(m);
    if (col1 == 1)
    {
        if (col2 == 1)
        {
            dest.c1 = ran_vec4_copy(m.c1); // col1 col2
            dest.c1 = ran_vec4_copy(m.c1); // col2 col1
        }
        if (col2 == 2)
        {
            dest.c1 = ran_vec4_copy(m.c2); // col1 col2
            dest.c2 = ran_vec4_copy(m.c1); // col2 col1
        }
        if (col2 == 3)
        {
            dest.c1 = ran_vec4_copy(m.c3); // col1 col2
            dest.c3 = ran_vec4_copy(m.c1); // col2 col1
        }
        if (col2 == 4)
        {
            dest.c1 = ran_vec4_copy(m.c4); // col1 col2
            dest.c4 = ran_vec4_copy(m.c1); // col2 col1
        }
    }
    if (col1 == 2)
    {
        if (col2 == 1)
        {
            dest.c2 = ran_vec4_copy(m.c1); // col1 col2
            dest.c1 = ran_vec4_copy(m.c2); // col2 col1
        }
        if (col2 == 2)
        {
            dest.c2 = ran_vec4_copy(m.c2); // col1 col2
            dest.c2 = ran_vec4_copy(m.c2); // col2 col1
        }
        if (col2 == 3)
        {
            dest.c2 = ran_vec4_copy(m.c3); // col1 col2
            dest.c3 = ran_vec4_copy(m.c2); // col2 col1
        }
        if (col2 == 4)
        {
            dest.c2 = ran_vec4_copy(m.c4); // col1 col2
            dest.c4 = ran_vec4_copy(m.c2); // col2 col1
        }
    }
    if (col1 == 3)
    {
        if (col2 == 1)
        {
            dest.c3 = ran_vec4_copy(m.c1); // col1 col2
            dest.c1 = ran_vec4_copy(m.c3); // col2 col1
        }
        if (col2 == 2)
        {
            dest.c3 = ran_vec4_copy(m.c2); // col1 col2
            dest.c2 = ran_vec4_copy(m.c3); // col2 col1
        }
        if (col2 == 3)
        {
            dest.c3 = ran_vec4_copy(m.c3); // col1 col2
            dest.c3 = ran_vec4_copy(m.c3); // col2 col1
        }
        if (col2 == 4)
        {
            dest.c3 = ran_vec4_copy(m.c4); // col1 col2
            dest.c4 = ran_vec4_copy(m.c3); // col2 col1
        }
    }
    if (col1 == 4)
    {
        if (col2 == 1)
        {
            dest.c4 = ran_vec4_copy(m.c1); // col1 col2
            dest.c1 = ran_vec4_copy(m.c4); // col2 col1
        }
        if (col2 == 2)
        {
            dest.c4 = ran_vec4_copy(m.c2); // col1 col2
            dest.c2 = ran_vec4_copy(m.c4); // col2 col1
        }
        if (col2 == 3)
        {
            dest.c4 = ran_vec4_copy(m.c3); // col1 col2
            dest.c3 = ran_vec4_copy(m.c4); // col2 col1
        }
        if (col2 == 4)
        {
            dest.c4 = ran_vec4_copy(m.c4); // col1 col2
            dest.c4 = ran_vec4_copy(m.c4); // col2 col1
        }
    }
    return dest;
}

RAN_INLINE mat4 ran_mat4_swap_row(mat4 m, uint32_t row1, uint32_t row2)
{
    mat4 dest = ran_mat4_copy(m);
    if (row1 == 1)
    {
        if (row2 == 1)
        {
            dest.c1.x = m.c1.x; // row1 row2
            dest.c2.x = m.c2.x; // row1 row2
            dest.c3.x = m.c3.x; // row1 row2
            dest.c4.x = m.c4.x; // row1 row2

            dest.c1.x = m.c1.x; // row2 row1
            dest.c2.x = m.c2.x; // row2 row1
            dest.c3.x = m.c3.x; // row2 row1
            dest.c4.x = m.c4.x; // row2 row1
        }
        if (row2 == 2)
        {
            dest.c1.x = m.c1.y; // row1 row2
            dest.c2.x = m.c2.y; // row1 row2
            dest.c3.x = m.c3.y; // row1 row2
            dest.c4.x = m.c4.y; // row1 row2

            dest.c1.y = m.c1.x; // row2 row1
            dest.c2.y = m.c2.x; // row2 row1
            dest.c3.y = m.c3.x; // row2 row1
            dest.c4.y = m.c4.x; // row2 row1
        }
        if (row2 == 3)
        {
            dest.c1.x = m.c1.z; // row1 row2
            dest.c2.x = m.c2.z; // row1 row2
            dest.c3.x = m.c3.z; // row1 row2
            dest.c4.x = m.c4.z; // row1 row2

            dest.c1.z = m.c1.x; // row2 row1
            dest.c2.z = m.c2.x; // row2 row1
            dest.c3.z = m.c3.x; // row2 row1
            dest.c4.z = m.c4.x; // row2 row1
        }
        if (row2 == 4)
        {
            dest.c1.x = m.c1.w; // row1 row2
            dest.c2.x = m.c2.w; // row1 row2
            dest.c3.x = m.c3.w; // row1 row2
            dest.c4.x = m.c4.w; // row1 row2

            dest.c1.w = m.c1.x; // row2 row1
            dest.c2.w = m.c2.x; // row2 row1
            dest.c3.w = m.c3.x; // row2 row1
            dest.c4.w = m.c4.x; // row2 row1
        }
    }
    if (row1 == 2)
    {
        if (row2 == 1)
        {
            dest.c1.y = m.c1.x; // row1 row2
            dest.c2.y = m.c2.x; // row1 row2
            dest.c3.y = m.c3.x; // row1 row2
            dest.c4.y = m.c4.x; // row1 row2

            dest.c1.x = m.c1.y; // row2 row1
            dest.c2.x = m.c2.y; // row2 row1
            dest.c3.x = m.c3.y; // row2 row1
            dest.c4.x = m.c4.y; // row2 row1
        }
        if (row2 == 2)
        {
            dest.c1.y = m.c1.y; // row1 row2
            dest.c2.y = m.c2.y; // row1 row2
            dest.c3.y = m.c3.y; // row1 row2
            dest.c4.y = m.c4.y; // row1 row2

            dest.c1.y = m.c1.y; // row2 row1
            dest.c2.y = m.c2.y; // row2 row1
            dest.c3.y = m.c3.y; // row2 row1
            dest.c4.y = m.c4.y; // row2 row1
        }
        if (row2 == 3)
        {
            dest.c1.y = m.c1.z; // row1 row2
            dest.c2.y = m.c2.z; // row1 row2
            dest.c3.y = m.c3.z; // row1 row2
            dest.c4.y = m.c4.z; // row1 row2

            dest.c1.z = m.c1.y; // row2 row1
            dest.c2.z = m.c2.y; // row2 row1
            dest.c3.z = m.c3.y; // row2 row1
            dest.c4.z = m.c4.y; // row2 row1
        }
        if (row2 == 4)
        {
            dest.c1.y = m.c1.w; // row1 row2
            dest.c2.y = m.c2.w; // row1 row2
            dest.c3.y = m.c3.w; // row1 row2
            dest.c4.y = m.c4.w; // row1 row2

            dest.c1.w = m.c1.y; // row2 row1
            dest.c2.w = m.c2.y; // row2 row1
            dest.c3.w = m.c3.y; // row2 row1
            dest.c4.w = m.c4.y; // row2 row1
        }
    }
    if (row1 == 3)
    {
        if (row2 == 1)
        {
            dest.c1.z = m.c1.x; // row1 row2
            dest.c2.z = m.c2.x; // row1 row2
            dest.c3.z = m.c3.x; // row1 row2
            dest.c4.z = m.c4.x; // row1 row2

            dest.c1.x = m.c1.z; // row2 row1
            dest.c2.x = m.c2.z; // row2 row1
            dest.c3.x = m.c3.z; // row2 row1
            dest.c4.x = m.c4.z; // row2 row1
        }
        if (row2 == 2)
        {
            dest.c1.z = m.c1.y; // row1 row2
            dest.c2.z = m.c2.y; // row1 row2
            dest.c3.z = m.c3.y; // row1 row2
            dest.c4.z = m.c4.y; // row1 row2

            dest.c1.y = m.c1.z; // row2 row1
            dest.c2.y = m.c2.z; // row2 row1
            dest.c3.y = m.c3.z; // row2 row1
            dest.c4.y = m.c4.z; // row2 row1
        }
        if (row2 == 3)
        {
            dest.c1.z = m.c1.z; // row1 row2
            dest.c2.z = m.c2.z; // row1 row2
            dest.c3.z = m.c3.z; // row1 row2
            dest.c4.z = m.c4.z; // row1 row2

            dest.c1.z = m.c1.z; // row2 row1
            dest.c2.z = m.c2.z; // row2 row1
            dest.c3.z = m.c3.z; // row2 row1
            dest.c4.z = m.c4.z; // row2 row1
        }
        if (row2 == 4)
        {
            dest.c1.z = m.c1.w; // row1 row2
            dest.c2.z = m.c2.w; // row1 row2
            dest.c3.z = m.c3.w; // row1 row2
            dest.c4.z = m.c4.w; // row1 row2

            dest.c1.w = m.c1.z; // row2 row1
            dest.c2.w = m.c2.z; // row2 row1
            dest.c3.w = m.c3.z; // row2 row1
            dest.c4.w = m.c4.z; // row2 row1
        }
    }
    if (row1 == 4)
    {
        if (row2 == 1)
        {
            dest.c1.w = m.c1.x; // row1 row2
            dest.c2.w = m.c2.x; // row1 row2
            dest.c3.w = m.c3.x; // row1 row2
            dest.c4.w = m.c4.x; // row1 row2

            dest.c1.x = m.c1.w; // row2 row1
            dest.c2.x = m.c2.w; // row2 row1
            dest.c3.x = m.c3.w; // row2 row1
            dest.c4.x = m.c4.w; // row2 row1
        }
        if (row2 == 2)
        {
            dest.c1.w = m.c1.y; // row1 row2
            dest.c2.w = m.c2.y; // row1 row2
            dest.c3.w = m.c3.y; // row1 row2
            dest.c4.w = m.c4.y; // row1 row2

            dest.c1.y = m.c1.w; // row2 row1
            dest.c2.y = m.c2.w; // row2 row1
            dest.c3.y = m.c3.w; // row2 row1
            dest.c4.y = m.c4.w; // row2 row1
        }
        if (row2 == 3)
        {
            dest.c1.w = m.c1.z; // row1 row2
            dest.c2.w = m.c2.z; // row1 row2
            dest.c3.w = m.c3.z; // row1 row2
            dest.c4.w = m.c4.z; // row1 row2

            dest.c1.z = m.c1.w; // row2 row1
            dest.c2.z = m.c2.w; // row2 row1
            dest.c3.z = m.c3.w; // row2 row1
            dest.c4.z = m.c4.w; // row2 row1
        }
        if (row2 == 4)
        {
            dest.c1.w = m.c1.w; // row1 row2
            dest.c2.w = m.c2.w; // row1 row2
            dest.c3.w = m.c3.w; // row1 row2
            dest.c4.w = m.c4.w; // row1 row2

            dest.c1.w = m.c1.w; // row2 row1
            dest.c2.w = m.c2.w; // row2 row1
            dest.c3.w = m.c3.w; // row2 row1
            dest.c4.w = m.c4.w; // row2 row1
        }
    }

    return dest;
}

RAN_INLINE float_t ran_mat4_rmc(vec4 r, mat4 m, vec4 c)
{
    return ran_vec4_dot(r, ran_mat4_mulv(m, c));
}

#if defined(RAN_VEC3_H)
RAN_INLINE vec3 ran_mat4_mulv3(mat4 m, vec3 v, float_t last)
{
    vec4 res = ran_mat4_mulv(m, (vec4){v.x, v.y, v.z, last});
    return ran_vec4_copy3(res);
}
#endif /* Using vec3 library */

#if defined(RAN_MAT3_H)
#include "vec3.h"

RAN_INLINE mat3 ran_mat4_pick3(mat4 m){
    return (mat3){(vec3){m.c1.x, m.c1.y, m.c1.z},
                  (vec3){m.c2.x, m.c2.y, m.c2.z},
                  (vec3){m.c3.x, m.c3.y, m.c3.z}} :
}

RAN_INLINE mat3 ran_mat4_pick3t(mat4 m)
{
    return (mat3){(vec3){m.c1.x, m.c2.x, m.c3.x},
                  (vec3){m.c1.y, m.c2.y, m.c3.y},
                  (vec3){m.c1.z, m.c2.z, m.c3.z}};
}

// Returns m2 inserted into m1
RAN_INLINE mat4 ran_mat4_ins3(mat4 m1, mat3 m2)
{
    mat4 t = ran_mat4_copy(m1);
    t.c1.x = m2.c1.x;
    t.c1.y = m2.c1.y;
    t.c1.z = m2.c1.z;

    t.c2.x = m2.c2.x;
    t.c2.y = m2.c2.y;
    t.c2.z = m2.c2.z;

    t.c3.x = m2.c3.x;
    t.c3.y = m2.c3.y;
    t.c3.z = m2.c3.z;

    return t;
}
#endif /* Using mat3 library */

#endif /* RAN_MAT4_H */