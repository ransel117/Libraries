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
 *
 * TYPES:
 *  vec4                                                            - a struct containing four floats
 *  ivec4                                                           - a struct containing four ints
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
 *  void ran_vec4_printf(vec4 v)                                    - prints the vector
 *  void ran_ivec4_printf(ivec4 v)
 *  float_t *ran_vec42opengl_vec4(vec4 v)                           - converts vector from a struct to an array of floats for better compatibility with OpenGL
 *  float_t ran_vec4_dot(vec4 a, vec4 b)                            - calculates the dotproduct of two vectors
 *  float_t ran_vec4_norm2(vec4 v)                                  - calculates the squared norm of the vector
 *  float_t ran_vec4_norm(vec4 v)                                   - calculates the euclidean norm of the vector
 *  float_t ran_vec4_norm_one(vec4 v)                               - calculates the L1 norm (Manhattan Distance or Taxicab norm) of the vector
 *  float_t ran_vec4_norm_inf(vec4 v)                               - calculates the infinity norm (Maximum norm) of the vector
 *  vec4 ran_vec4_set(float_t x, float_t y)                         - sets the x, y and z values to the values
 *  ivec4 ran_ivec4_set(int32_t x, int32_t y)
 *  vec4 ran_vec4_copy(vec4 v)                                      - copies the vector
 *  ivec4 ran_ivec4_copy(ivec4 v)
 *  vec4 ran_vec4_zero()                                            - sets the x, y and z values to zero
 *  ivec4 ran_ivec4_zero()
 *  vec4 ran_vec4_one()                                             - sets the x, y and z values to one
 *  ivec4 ran_ivec4_one()
 *  vec4 ran_vec4_add(vec4 a, vec4 b)                               - adds two vectors
 *  ivec4 ran_ivec4_add(ivec4 a, ivec4 b)
 *  vec4 ran_vec4_adds(vec4 v, float_t s)                           - adds a scalar to vector
 *  ivec4 ran_ivec4_adds(ivec4 v, int32_t s)
 *  vec4 ran_vec4_sub(vec4 a, vec4 b)                               - subtracts two vectors
 *  ivec4 ran_ivec4_sub(ivec4 a, ivec4 b)
 *  vec4 ran_vec4_subs(vec4 v, float_t s)                           - subtracts a scalar from vector
 *  ivec4 ran_ivec4_subs(ivec4 v, int32_t s)
 *  vec4 ran_vec4_mul(vec4 a, vec4 b)                               - multiplies two vectors
 *  ivec4 ran_ivec4_mul(ivec4 a, ivec4 b)
 *  vec4 ran_vec4_scale(vec4 v, float_t s)                          - multiplies a scalar to vector
 *  ivec4 ran_ivec4_scale(ivec4 v, int32_t s)
 *  vec4 ran_vec4_scale_as(vec4 v, float_t s)                       - multiplies a scalar to vector if the norm != 0
 *  vec4 ran_vec4_div(vec4 a, vec4 b)                               - divides vector a with vector b
 *  vec4 ran_vec4_divs(vec4 v, float_t s)                           - divides vector by a scalar
 *  vec4 ran_vec4_add_scaled_vec(vec4 a, vec4 b, float_t s)         - adds a scaled vector b to vector a
 *  ivec4 ran_ivec4_add_scaled_vec(ivec4 a, ivec4 b, float_t s)
 *  vec4 ran_vec4_sub_scaled_vec(vec4 a, vec4 b, float_t s)         - subtracts a scaled vector b to vector a
 *  ivec4 ran_ivec4_sub_scaled_vec(ivec4 a, ivec4 b, float_t s)
 *  vec4 ran_vec4_negate(vec4 v)                                    - negates the vector
 *  ivec4 ran_ivec4_negate(ivec4 v)
 *  vec4 ran_vec4_normalize(vec4 v)                                 - calculates the normal of vector
 *  float_t ran_vec4_distance2(vec4 a, vec4 b)                      - calculates the distance squared between two vectors
 *  int32_t ran_ivec4_distance2(ivec4 a, ivec4 b)
 *  float_t ran_vec4_distance(vec4 a, vec4 b)                       - calculates the distance between two vectors
 *  float_t ran_ivec4_distance(ivec4 a, ivec4 b)
 *  vec4 ran_vec4_max(vec4 a, vec4 b)                               - returns the the biggest possible vector of two vectors
 *  ivec4 ran_ivec4_max(ivec4 a, ivec4 b)
 *  vec4 ran_vec4_min(vec4 a, vec4 b)                               - returns the the smallest possible vector of two vectors
 *  ivec4 ran_ivec4_min(ivec4 a, ivec4 b)
 *  vec4 ran_vec4_clamp(vec4 v, float_t minval, float_t maxval)     - clamps the vector values between the minimum value and the maximum value
 *  ivec4 ran_ivec4_clamp(ivec4 v, int32_t minval, int32_t maxval)
 *
 *  vec3 ran_vec4_copy3(vec4 v)                                     - copies the first three elements of the vec4 into a vec3
 */

#ifndef RAN_VEC4_H
#define RAN_VEC4_H

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

typedef RAN_ALIGN(16) struct vec4
{
    float_t x;
    float_t y;
    float_t z;
    float_t w;
} vec4;

typedef RAN_ALIGN(16) struct ivec4
{
    int32_t x;
    int32_t y;
    int32_t z;
    int32_t w;
} ivec4;

RAN_INLINE void ran_vec4_printf(vec4 v)
{
    printf("<x: %f, y: %f, z: %f, w: %f>\n", v.x, v.y, v.z, v.w);
}
RAN_INLINE void ran_vec4_printf(ivec4 v)
{
    printf("<x: %d, y: %d, z: %d, w: %d>\n", v.x, v.y, v.z, v.w);
}

RAN_INLINE float_t *ran_vec42opengl_vec4(vec4 v)
{
    return (float_t[4]){v.x, v.y, v.z, v.w};
}

RAN_INLINE float_t ran_vec4_dot(vec4 a, vec4 b)
{
    return ((a.x * b.x) + (a.y * b.y)) + ((a.z * b.z) + (a.w * b.w));
}

RAN_INLINE float_t ran_vec4_norm2(vec4 v)
{
    return ran_vec4_dot(v, v);
}
RAN_INLINE float_t ran_vec4_norm(vec4 v)
{
    return sqrtf(ran_vec4_norm2(v));
}
RAN_INLINE float_t ran_vec4_norm_one(vec4 v)
{
    return (fabsf(v.x) + fabsf(v.y)) + (fabsf(v.z) + fabsf(v.w));
}
RAN_INLINE float_t ran_vec4_norm_inf(vec4 v)
{
    return ran_maxf(ran_maxf(fabsf(v.x), fabsf(v.y)),
                    ran_maxf(fabsf(v.z), fabsf(v.w)));
}

RAN_INLINE vec4 ran_vec4_set(float_t x, float_t y, float_t z, float_t w)
{
    return (vec4){x, y, z, w};
}
RAN_INLINE ivec4 ran_ivec4_set(float_t x, float_t y, float_t z, float_t w)
{
    return (ivec4){x, y, z, w};
}

RAN_INLINE vec4 ran_vec4_copy(vec4 v)
{
    return (vec4){v.x, v.y, v.z, v.w};
}
RAN_INLINE ivec4 ran_ivec4_copy(ivec4 v)
{
    return (ivec4){v.x, v.y, v.z, v.w};
}

RAN_INLINE vec4 ran_vec4_zero()
{
    return (vec4){0.0F, 0.0F, 0.0F, 0.0F};
}
RAN_INLINE ivec4 ran_ivec4_zero()
{
    return (ivec4){0, 0, 0, 0};
}

RAN_INLINE vec4 ran_vec4_one()
{
    return (vec4){1.0F, 1.0F, 1.0F, 1.0F};
}
RAN_INLINE ivec4 ran_ivec4_one()
{
    return (ivec4){1, 1, 1, 1};
}

RAN_INLINE vec4 ran_vec4_add(vec4 a, vec4 b)
{
    return (vec4){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}
RAN_INLINE ivec4 ran_ivec4_add(ivec4 a, ivec4 b)
{
    return (ivec4){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}

RAN_INLINE vec4 ran_vec4_adds(vec4 a, float_t s)
{
    return (vec4){a.x + s, a.y + s, a.z + s, a.w + s};
}
RAN_INLINE ivec4 ran_ivec4_adds(ivec4 a, float_t s)
{
    return (ivec4){a.x + s, a.y + s, a.z + s, a.w + s};
}

RAN_INLINE vec4 ran_vec4_sub(vec4 a, vec4 b)
{
    return (vec4){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}
RAN_INLINE ivec4 ran_ivec4_sub(ivec4 a, ivec4 b)
{
    return (ivec4){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}

RAN_INLINE vec4 ran_vec4_subs(vec4 v, float_t s)
{
    return (vec4){v.x - s, v.y - s, v.z - s, v.w - s};
}
RAN_INLINE ivec4 ran_ivec4_subs(ivec4 v, float_t s)
{
    return (ivec4){v.x - s, v.y - s, v.z - s, v.w - s};
}

RAN_INLINE vec4 ran_vec4_mul(vec4 a, vec4 b)
{
    return (vec4){a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
}
RAN_INLINE ivec4 ran_ivec4_mul(ivec4 a, ivec4 b)
{
    return (ivec4){a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
}

RAN_INLINE vec4 ran_vec4_scale(vec4 v, float_t s)
{
    return (vec4){v.x * s, v.y * s, v.z * s, v.w * s};
}
RAN_INLINE ivec4 ran_ivec4_scale(ivec4 v, int32_t s)
{
    return (ivec4){v.x * s, v.y * s, v.z * s, v.w * s};
}

RAN_INLINE vec4 ran_vec4_scale_as(vec4 v, float_t s)
{
    float_t norm = ran_vec4_norm(v);
    return fabsf(norm) <= FLT_EPSILON ? ran_vec4_zero() : ran_vec4_scale(v, s / norm);
}

RAN_INLINE vec4 ran_vec4_div(vec4 a, vec4 b)
{
    return (vec4){a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w};
}
RAN_INLINE vec4 ran_vec4_divs(vec4 v, float_t s)
{
    return (vec4){v.x / s, v.y / s, v.z / s, v.w / s};
}

RAN_INLINE vec4 ran_vec4_add_scaled_vec(vec4 a, vec4 b, float_t s)
{
    return ran_vec4_add(a, ran_vec4_scale(b, s));
}
RAN_INLINE ivec4 ran_ivec4_add_scaled_vec(ivec4 a, ivec4 b, float_t s)
{
    return ran_ivec4_add(a, ran_ivec4_scale(b, s));
}

RAN_INLINE vec4 ran_vec4_sub_scaled_vec(vec4 a, vec4 b, float_t s)
{
    return ran_vec4_sub(a, ran_vec4_scale(b, s));
}
RAN_INLINE ivec4 ran_ivec4_sub_scaled_vec(ivec4 a, ivec4 b, float_t s)
{
    return ran_ivec4_sub(a, ran_ivec4_scale(b, s));
}

RAN_INLINE vec4 ran_vec4_negate(vec4 v)
{
    return (vec4){-v.x, -v.y, -v.z, -v.w};
}
RAN_INLINE ivec4 ran_ivec4_negate(ivec4 v)
{
    return (ivec4){-v.x, -v.y, -v.z, -v.w};
}

RAN_INLINE vec4 ran_vec4_normalize(vec4 v)
{
    float_t norm = ran_vec4_norm(v);
    return fabsf(norm) <= FLT_EPSILON ? ran_vec4_zero() : ran_vec4_scale(v, 1 / norm);
}

RAN_INLINE float_t ran_vec4_distance2(vec4 a, vec4 b)
{
    return ran_pow2f(a.x - b.x) + ran_pow2f(a.y - b.y) + ran_pow2f(a.z - b.z) + ran_pow2f(a.w - b.w);
}
RAN_INLINE int32_t ran_ivec4_distance2(ivec4 a, ivec4 b)
{
    return ran_pow2f(a.x - b.x) + ran_pow2f(a.y - b.y) + ran_pow2f(a.z - b.z) + ran_pow2f(a.w - b.w);
}

RAN_INLINE float_t ran_vec4_distance(vec4 a, vec4 b)
{
    return sqrtf(ran_vec4_distance2(a, b));
}
RAN_INLINE float_t ran_ivec4_distance(ivec4 a, ivec4 b)
{
    return sqrtf((float_t)ran_ivec4_distance2(a, b));
}

RAN_INLINE vec4 ran_vec4_max(vec4 a, vec4 b)
{
    return (vec4){ran_maxf(a.x, b.x), ran_maxf(a.y, b.y),
                  ran_maxf(a.z, b.z), ran_maxf(a.w, b.w)};
}
RAN_INLINE ivec4 ran_ivec4_max(ivec4 a, ivec4 b)
{
    return (ivec4){ran_maxi(a.x, b.x), ran_maxi(a.y, b.y),
                   ran_maxi(a.z, b.z), ran_maxi(a.w, b.w)};
}

RAN_INLINE vec4 ran_vec4_min(vec4 a, vec4 b)
{
    return (vec4){ran_minf(a.x, b.x), ran_minf(a.y, b.y),
                  ran_minf(a.z, b.z), ran_minf(a.w, b.w)};
}
RAN_INLINE ivec4 ran_ivec4_min(ivec4 a, ivec4 b)
{
    return (ivec4){ran_mini(a.x, b.x), ran_mini(a.y, b.y),
                   ran_mini(a.z, b.z), ran_mini(a.w, b.w)};
}

RAN_INLINE vec4 ran_vec4_clamp(vec4 v, float_t minval, float_t maxval)
{
    return (vec4){ran_clampf(v.x, minval, maxval), ran_clampf(v.y, minval, maxval),
                  ran_clampf(v.z, minval, maxval), ran_clampf(v.w, minval, maxval)};
}
RAN_INLINE ivec4 ran_ivec4_clamp(ivec4 v, int32_t minval, int32_t maxval)
{
    return (ivec4){ran_clampi(v.x, minval, maxval), ran_clampi(v.y, minval, maxval),
                   ran_clampi(v.z, minval, maxval), ran_clampi(v.w, minval, maxval)};
}

#if defined(RAN_VEC3_H)
RAN_INLINE vec3 ran_vec4_copy3(vec4 v)
{
    return (vec3){v.x, v.y, v.z};
}
#endif /* Using vec3 library */

#endif /* RAN_VEC4_H */