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
 *  RAN_MAT4_H                                                      - is defined if my 4d matrix library is included
 *  RAN_MAT3_H                                                      - is defined if my 3d matrix library is included
 *
 * TYPES:
 *  vec3                                                            - a struct containing three floats
 *  ivec3                                                           - a struct containing three ints
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
 *  void ran_vec3_printf(vec3 v)                                    - prints the vector
 *  void ran_ivec3_printf(ivec3 v)
 *  float_t *ran_vec32opengl_vec3(vec3 v)                           - converts vector from a struct to an array of floats for better compatibility with OpenGL
 *  float_t ran_vec3_dot(vec3 a, vec3 b)                            - calculates the dotproduct of two vectors
 *  float_t ran_vec3_norm2(vec3 v)                                  - calculates the squared norm of the vector
 *  float_t ran_vec3_norm(vec3 v)                                   - calculates the euclidean norm of the vector
 *  float_t ran_vec3_norm_one(vec3 v)                               - calculates the L1 norm (Manhattan Distance or Taxicab norm) of the vector
 *  float_t ran_vec3_norm_inf(vec3 v)                               - calculates the infinity norm (Maximum norm) of the vector
 *  vec3 ran_vec3_set(float_t x, float_t y)                         - sets the x, y and z values to the values
 *  ivec3 ran_ivec3_set(int32_t x, int32_t y)
 *  vec3 ran_vec3_copy(vec3 v)                                      - copies the vector
 *  ivec3 ran_ivec3_copy(ivec3 v)
 *  vec3 ran_vec3_zero()                                            - sets the x, y and z values to zero
 *  ivec3 ran_ivec3_zero()
 *  vec3 ran_vec3_one()                                             - sets the x, y and z values to one
 *  ivec3 ran_ivec3_one()
 *  vec3 ran_vec3_add(vec3 a, vec3 b)                               - adds two vectors
 *  ivec3 ran_ivec3_add(ivec3 a, ivec3 b)
 *  vec3 ran_vec3_adds(vec3 v, float_t s)                           - adds a scalar to vector
 *  ivec3 ran_ivec3_adds(ivec3 v, int32_t s)
 *  vec3 ran_vec3_sub(vec3 a, vec3 b)                               - subtracts two vectors
 *  ivec3 ran_ivec3_sub(ivec3 a, ivec3 b)
 *  vec3 ran_vec3_subs(vec3 v, float_t s)                           - subtracts a scalar from vector
 *  ivec3 ran_ivec3_subs(ivec3 v, int32_t s)
 *  vec3 ran_vec3_mul(vec3 a, vec3 b)                               - multiplies two vectors
 *  ivec3 ran_ivec3_mul(ivec3 a, ivec3 b)
 *  vec3 ran_vec3_scale(vec3 v, float_t s)                          - multiplies a scalar to vector
 *  ivec3 ran_ivec3_scale(ivec3 v, int32_t s)
 *  vec3 ran_vec3_scale_as(vec3 v, float_t s)                       - multiplies a scalar to vector if the norm != 0
 *  vec3 ran_vec3_div(vec3 a, vec3 b)                               - divides vector a with vector b
 *  vec3 ran_vec3_divs(vec3 v, float_t s)                           - divides vector by a scalar
 *  vec3 ran_vec3_add_scaled_vec(vec3 a, vec3 b, float_t s)         - adds a scaled vector b to vector a
 *  vec3 ran_vec3_sub_scaled_vec(vec3 a, vec3 b, float_t s)         - subtracts a scaled vector b to vector a
 *  vec3 ran_vec3_negate(vec3 v)                                    - negates the vector
 *  ivec3 ran_ivec3_negate(ivec3 v)
 *  vec3 ran_vec3_normalize(vec3 v)                                 - calculates the normal of vector
 *  vec3 ran_vec3_cross(vec3 a, vec3 b)                             - calculates the cross product of two vectors
 *  vec3 ran_vec3_crossn(vec3 a, vec3 b)                            - calculates the cross product of two vectors and normalizes it
 *  float_t ran_vec3_angle(vec3 a, vec3 b)                          - calculates the angle between two vectors in radians
 *  float_t ran_vec3_angle_deg(vec3 a, vec3 b)                      - calculates the angle between two vectors in degrees
 *  vec3 ran_vec3_rotate(vec3 v, float_t a)                         - rotates vector by angle in radians
 *  vec3 ran_vec3_rotate_deg(vec3 v, float_t a)                     - rotates vector by angle in degrees
 *  vec3 ran_vec3_proj(vec3 a, vec3 b)                              - projects a vector onto b vector
 *  vec3 ran_vec3_center(vec3 a, vec3 b)                            - calculates the center point between two vectors
 *  float_t ran_vec3_distance2(vec3 a, vec3 b)                      - calculates the distance squared between two vectors
 *  int32_t ran_ivec3_distance2(ivec3 a, ivec3 b)
 *  float_t ran_vec3_distance(vec3 a, vec3 b)                       - calculates the distance between two vectors
 *  float_t ran_ivec3_distance(ivec3 a, ivec3 b)
 *  vec3 ran_vec3_max(vec3 a, vec3 b)                               - returns the the biggest possible vector of two vectors
 *  ivec3 ran_ivec3_max(ivec3 a, ivec3 b)
 *  vec3 ran_vec3_min(vec3 a, vec3 b)                               - returns the the smallest possible vector of two vectors
 *  ivec3 ran_ivec3_min(ivec3 a, ivec3 b)
 *  vec3 ran_vec3_clamp(vec3 v, float_t minval, float_t maxval)     - clamps the vector values between the minimum value and the maximum value
 *  ivec3 ran_ivec3_clamp(ivec3 v, int32_t minval, int32_t maxval)
 *
 *  vec3 ran_vec3_rotate_m4(mat4 m, vec3 v)                         - rotates vector using a 4d matrix
 *  vec3 ran_vec3_rotate_m3(mat3 m, vec3 v)                         - rotates vector using a 3d matrix
 */

#ifndef RAN_VEC3_H
#define RAN_VEC3_H

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdint.h>

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

typedef struct vec3
{
    float_t x;
    float_t y;
    float_t z;
} vec3;

typedef struct ivec3
{
    int32_t x;
    int32_t y;
    int32_t z;
} ivec3;

RAN_INLINE void ran_vec3_printf(vec3 v)
{
    printf("<x: %f, y: %f, z: %f>\n", v.x, v.y, v.z);
}
RAN_INLINE void ran_ivec3_printf(ivec3 v)
{
    printf("<x: %d, y: %d, z: %d>\n", v.x, v.y, v.z);
}
RAN_INLINE float_t *ran_vec32opengl_vec3(vec3 v)
{
    return (float_t[3]){v.x, v.y, v.z};
}

RAN_INLINE float_t ran_vec3_dot(vec3 a, vec3 b)
{
    return ((a.x * b.x) + (a.y * b.y)) + (a.z * b.z);
}

RAN_INLINE float_t ran_vec3_norm2(vec3 v)
{
    return ran_vec3_dot(v, v);
}
RAN_INLINE float_t ran_vec3_norm(vec3 v)
{
    return sqrtf(ran_vec3_norm2(v));
}
RAN_INLINE float_t ran_vec3_norm_one(vec3 v)
{
    return (fabsf(v.x) + fabsf(v.y)) + fabsf(v.z);
}
RAN_INLINE float_t ran_vec3_norm_inf(vec3 v)
{
    return ran_maxf(ran_maxf(fabsf(v.x), fabsf(v.y)), fabsf(v.z));
}

RAN_INLINE vec3 ran_vec3_set(float_t x, float_t y, float_t z)
{
    return (vec3){x, y, z};
}
RAN_INLINE ivec3 ran_ivec3_set(int32_t x, int32_t y, int32_t z)
{
    return (ivec3){x, y, z};
}

RAN_INLINE vec3 ran_vec3_copy(vec3 v)
{
    return (vec3){v.x, v.y, v.z};
}
RAN_INLINE ivec3 ran_ivec3_copy(ivec3 v)
{
    return (ivec3){v.x, v.y, v.z};
}

RAN_INLINE vec3 ran_vec3_zero()
{
    return (vec3){0.0F, 0.0F, 0.0F};
}
RAN_INLINE ivec3 ran_ivec3_zero()
{
    return (ivec3){0, 0, 0};
}

RAN_INLINE vec3 ran_vec3_one()
{
    return (vec3){1.0F, 1.0F, 1.0F};
}
RAN_INLINE ivec3 ran_ivec3_one()
{
    return (ivec3){1, 1, 1};
}

RAN_INLINE vec3 ran_vec3_add(vec3 a, vec3 b)
{
    return (vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}
RAN_INLINE ivec3 ran_ivec3_add(ivec3 a, ivec3 b)
{
    return (ivec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

RAN_INLINE vec3 ran_vec3_adds(vec3 v, float_t s)
{
    return (vec3){v.x + s, v.y + s, v.z + s};
}
RAN_INLINE ivec3 ran_ivec3_adds(ivec3 v, float_t s)
{
    return (ivec3){v.x + s, v.y + s, v.z + s};
}

RAN_INLINE vec3 ran_vec3_sub(vec3 a, vec3 b)
{
    return (vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}
RAN_INLINE ivec3 ran_ivec3_sub(ivec3 a, ivec3 b)
{
    return (ivec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

RAN_INLINE vec3 ran_vec3_subs(vec3 v, float_t s)
{
    return (vec3){v.x - s, v.y - s, v.z - s};
}
RAN_INLINE ivec3 ran_ivec3_subs(ivec3 v, float_t s)
{
    return (ivec3){v.x - s, v.y - s, v.z - s};
}

RAN_INLINE vec3 ran_vec3_mul(vec3 a, vec3 b)
{
    return (vec3){a.x * b.x, a.y * b.y, a.z * b.z};
}
RAN_INLINE ivec3 ran_ivec3_mul(ivec3 a, ivec3 b)
{
    return (ivec3){a.x * b.x, a.y * b.y, a.z * b.z};
}

RAN_INLINE vec3 ran_vec3_scale(vec3 v, float_t s)
{
    return (vec3){v.x * s, v.y * s, v.z * s};
}
RAN_INLINE ivec3 ran_ivec3_scale(ivec3 v, float_t s)
{
    return (ivec3){v.x * s, v.y * s, v.z * s};
}

RAN_INLINE vec3 ran_vec3_scale_as(vec3 v, float_t s)
{
    float_t norm = ran_vec3_norm(v);
    return fabsf(norm) <= FLT_EPSILON ? ran_vec3_zero() : ran_vec3_scale(v, s / norm);
}

RAN_INLINE vec3 ran_vec3_div(vec3 a, vec3 b)
{
    return (vec3){a.x / b.x, a.y / b.y, a.z / b.z};
}
RAN_INLINE vec3 ran_vec3_divs(vec3 v, float_t s)
{
    return (vec3){v.x / s, v.y / s, v.z / s};
}

RAN_INLINE vec3 ran_vec3_add_scaled_vec(vec3 a, vec3 b, float_t s)
{
    return ran_vec3_add(a, ran_vec3_scale(b, s));
}
RAN_INLINE ivec3 ran_ivec3_add_scaled_vec(ivec3 a, ivec3 b, float_t s)
{
    return ran_ivec3_add(a, ran_ivec3_scale(b, s));
}

RAN_INLINE vec3 ran_vec3_sub_scaled_vec(vec3 a, vec3 b, float_t s)
{
    return ran_vec3_sub(a, ran_vec3_scale(b, s));
}
RAN_INLINE ivec3 ran_ivec3_sub_scaled_vec(ivec3 a, ivec3 b, float_t s)
{
    return ran_ivec3_sub(a, ran_ivec3_scale(b, s));
}

RAN_INLINE vec3 ran_vec3_negate(vec3 v)
{
    return (vec3){-v.x, -v.y, -v.z};
}
RAN_INLINE ivec3 ran_ivec3_negate(ivec3 v)
{
    return (ivec3){-v.x, -v.y, -v.z};
}

RAN_INLINE vec3 ran_vec3_normalize(vec3 v)
{
    float_t norm = ran_vec3_norm(v);
    return fabsf(norm) <= FLT_EPSILON ? ran_vec3_zero() : ran_vec3_scale(v, 1 / norm);
}

RAN_INLINE vec3 ran_vec3_cross(vec3 a, vec3 b)
{

    return (vec3){(a.y * b.z) - (a.z * b.y),
                  (a.z * b.x) - (a.x * b.z),
                  (a.x * b.y) - (a.y * b.x)};
}
RAN_INLINE vec3 ran_vec3_crossn(vec3 a, vec3 b)
{
    return ran_vec3_normalize(ran_vec3_cross(a, b));
}

RAN_INLINE float_t ran_vec3_angle(vec3 a, vec3 b)
{
    float_t dot = ran_vec3_dot(a, b) * (1 / (ran_vec3_norm(a) * ran_vec3_norm(b)));

    /*
    if (dot > 1.0F)
    {
        return 0.0F;
    }
    else if (dot < -1.0F)
    {
        return RAN_PI;
    }

    return acosf(dot);
    */

    return dot > 1.0F ? 0.0F : (dot < -1.0F ? RAN_PI : acosf(dot));
}
RAN_INLINE float_t ran_vec3_angle_deg(vec3 a, vec3 b)
{
    float_t dot = ran_vec3_dot(a, b) * (1 / (ran_vec3_norm(a) * ran_vec3_norm(b)));

    /*
    if (dot > 1.0F)
    {
        return 0.0F;
    }
    else if (dot < -1.0F)
    {
        return rad2deg(RAN_PI);
    }

    return acosf(dot);
    */

    return dot > 1.0F ? 0.0F : (dot < -1.0F ? ran_rad2deg(RAN_PI) : ran_rad2deg(acosf(dot)));
}

RAN_INLINE vec3 ran_vec3_rotate(vec3 v, float_t angle, vec3 axis)
{
    vec3 v1, v2, k, dest;
    float_t c, s;

    c = cosf(angle);
    s = sinf(angle);

    k = ran_vec3_normalize(axis);

    /**
     * Right Hand, Rodrigues' rotation formula:
     * v = v*cos(t) + (kxv)sin(t) + k*(k.v)(1 - cos(t))
     */
    v1 = ran_vec3_scale(v, c);

    v2 = ran_vec3_cross(k, v);
    v2 = ran_vec3_scale(v2, s);

    v1 = ran_vec3_add(v1, v2);

    v2 = ran_vec3_scale(k, ran_vec3_dot(k, v) * (1.0f - c));
    dest = ran_vec3_add(v1, v2);

    return dest;
}
RAN_INLINE vec3 ran_vec3_rotate_deg(vec3 v, float_t angle, vec3 axis)
{
    vec3 v1, v2, k, dest;

    float_t c = cosf(ran_deg2rad(angle));
    float_t s = sinf(ran_deg2rad(angle));

    k = ran_vec3_normalize(axis);

    /* Right Hand, Rodrigues' rotation formula:
          v = v*cos(t) + (kxv)sin(t) + k*(k.v)(1 - cos(t))
     */
    v1 = ran_vec3_scale(v, c);

    v2 = ran_vec3_cross(k, v);
    v2 = ran_vec3_scale(v2, s);

    v1 = ran_vec3_add(v1, v2);

    v2 = ran_vec3_scale(k, ran_vec3_dot(k, v) * (1.0f - c));
    dest = ran_vec3_add(v1, v2);

    return dest;
}

RAN_INLINE vec3 ran_vec3_proj(vec3 a, vec3 b)
{
    return ran_vec3_scale(b, ran_vec3_dot(a, b) / ran_vec3_norm2(b));
}

RAN_INLINE vec3 ran_vec3_center(vec3 a, vec3 b)
{
    return ran_vec3_scale(ran_vec3_add(a, b), 0.5F);
}

RAN_INLINE float_t ran_vec3_distance2(vec3 a, vec3 b)
{
    return (ran_pow2f(a.x - b.x) + ran_pow2f(a.y - b.y)) + ran_pow2f(a.z - b.z);
}
RAN_INLINE int32_t ran_ivec3_distance2(ivec3 a, ivec3 b)
{
    return (ran_pow2f(a.x - b.x) + ran_pow2f(a.y - b.y)) + ran_pow2f(a.z - b.z);
}

RAN_INLINE float_t ran_vec3_distance(vec3 a, vec3 b)
{
    return sqrtf(ran_vec3_distance2(a, b));
}
RAN_INLINE float_t ran_ivec3_distance(ivec3 a, ivec3 b)
{
    return sqrtf(ran_ivec3_distance2(a, b));
}

RAN_INLINE vec3 ran_vec3_max(vec3 a, vec3 b)
{
    return (vec3){ran_maxf(a.x, b.x), ran_maxf(a.y, b.y), ran_maxf(a.z, b.z)};
}
RAN_INLINE ivec3 ran_ivec3_max(ivec3 a, ivec3 b)
{
    return (ivec3){ran_maxi(a.x, b.x), ran_maxi(a.y, b.y), ran_maxi(a.z, b.z)};
}

RAN_INLINE vec3 ran_vec3_min(vec3 a, vec3 b)
{
    return (vec3){ran_minf(a.x, b.x), ran_minf(a.y, b.y), ran_minf(a.z, b.z)};
}
RAN_INLINE ivec3 ran_ivec3_min(ivec3 a, ivec3 b)
{
    return (ivec3){ran_mini(a.x, b.x), ran_mini(a.y, b.y), ran_mini(a.z, b.z)};
}

RAN_INLINE vec3 ran_vec3_ortho(vec3 v)
{
    float_t ignore;
    float_t f = modff(fabsf(v.x) + 0.5f, &ignore);
    return (vec3){-v.y, v.x - (f * v.z), f * v.y};
}

RAN_INLINE vec3 ran_vec3_clamp(vec3 v, float_t minval, float_t maxval)
{
    return (vec3){ran_clampf(v.x, minval, maxval),
                  ran_clampf(v.y, minval, maxval),
                  ran_clampf(v.z, minval, maxval)};
}
RAN_INLINE ivec3 ran_ivec3_clamp(ivec3 v, float_t minval, float_t maxval)
{
    return (ivec3){ran_clampi(v.x, minval, maxval),
                   ran_clampi(v.y, minval, maxval),
                   ran_clampi(v.z, minval, maxval)};
}

#if defined(RAN_MAT4_H) || defined(RAN_MAT3_H)
#include "vec4.h"
#if defined(RAN_MAT4_H)

// Rotation using rotation matrix
RAN_INLINE vec3 ran_vec3_rotate_m4(mat4 m, vec3 v)
{
    vec4 x, y, z, res;

    x = ran_vec4_normalize(m.c1);
    y = ran_vec4_normalize(m.c2);
    z = ran_vec4_normalize(m.c3);

    res = ran_vec4_scale(x, v.x);
    res = ran_vec4_add(res, ran_vec4_scale(y, v.y));
    res = ran_vec4_add(res, ran_vec4_scale(z, v.z));

    return (vec3){res.x, res.y, res.z};
}
#endif /* Using mat4 library */
#if defined(RAN_MAT3_H)

RAN_INLINE vec3 ran_vec3_rotate_m3(mat3 m, vec3 v)
{
    vec4 res, x, y, z;

    x = ran_vec4_set(m.c1.x, m.c1.y, m.c1.z, 0.0F);
    y = ran_vec4_set(m.c2.x, m.c2.y, m.c2.z, 0.0F);
    z = ran_vec4_set(m.c3.x, m.c3.y, m.c3.z, 0.0F);

    x = ran_vec4_normalize(x);
    y = ran_vec4_normalize(y);
    z = ran_vec4_normalize(z);

    res = ran_vec4_scale(x, v.x);
    res = ran_vec4_add(res, ran_vec4_scale(y, v.y));
    res = ran_vec4_add(res, ran_vec4_scale(z, v.z));

    return (vec3){res.x, res.y, res.z};
}
#endif /* Using mat3 library */
#endif /* Using any of the matrix libraries */
#endif /* RAN_VEC3_H */