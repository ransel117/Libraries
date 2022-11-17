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
 * NOTE: DOES NOT WORK WITH CGLM
 */
/**
 * MACROS:
 *  RAN_UTILS                                                       - is defined if any of my other libraries is included
 *  RAN_INLINE static inline __attribute((always_inline))           - makes sure the compiler makes everything inline
 *
 * TYPES:
 *  vec2                                                            - a struct containing two floats
 *  ivec2                                                           - a struct containing two ints
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
 *  void ran_vec2_printf(vec2 v)                                    - prints the given vector
 *  void ran_ivec2_printf(ivec2 v)
 *  float_t *ran_vec22opengl_vec2(vec2 v)                           - converts vector from a struct to an array of floats for better compatibility with OpenGL
 *  float_t ran_vec2_dot(vec2 a, vec2 b)                            - calculates the dotproduct of two given vectors
 *  float_t ran_vec2_cross(vec2 a, vec2 b)                          - calculates the crossproduct of two given vectors
 *  float_t ran_vec2_norm2(vec2 v)                                  - calculates the squared norm of the vector
 *  float_t ran_vec2_norm(vec2 v)                                   - calculates the norm of the vector
 *  vec2 ran_vec2_set(float_t x, float_t y)                         - sets the x and y values to the given values
 *  ivec2 ran_ivec2_set(int32_t x, int32_t y)
 *  vec2 ran_vec2_copy(vec2 v)                                      - copies the given vector
 *  ivec2 ran_ivec2_copy(ivec2 v)
 *  vec2 ran_vec2_zero()                                            - sets the x and y values to zero
 *  ivec2 ran_ivec2_zero()
 *  vec2 ran_vec2_one()                                             - sets the x and y values to one
 *  ivec2 ran_ivec2_one()
 *  vec2 ran_vec2_add(vec2 a, vec2 b)                               - adds two vectors
 *  ivec2 ran_ivec2_add(ivec2 a, ivec2 b)
 *  vec2 ran_vec2_adds(vec2 v, float_t s)                           - adds a scalar to given vector
 *  ivec2 ran_ivec2_adds(ivec2 v, int32_t s)
 *  vec2 ran_vec2_sub(vec2 a, vec2 b)                               - subtracts two vectors
 *  ivec2 ran_ivec2_sub(ivec2 a, ivec2 b)
 *  vec2 ran_vec2_subs(vec2 v, float_t s)                           - subtracts a scalar from given vector
 *  ivec2 ran_ivec2_subs(ivec2 v, int32_t s)
 *  vec2 ran_vec2_mul(vec2 a, vec2 b)                               - multiplies two vectors
 *  ivec2 ran_ivec2_mul(ivec2 a, ivec2 b)
 *  vec2 ran_vec2_scale(vec2 v, float_t s)                          - multiplies a scalar to given vector
 *  ivec2 ran_ivec2_scale(ivec2 v, int32_t s)
 *  vec2 ran_vec2_scale_as(vec2 v, float_t s)                       - multiplies a scalar to given vector if the norm != 0
 *  vec2 ran_vec2_div(vec2 a, vec2 b)                               - divides two vectors
 *  vec2 ran_vec2_divs(vec2 v, float_t s)                           - divides given vector by a scalar
 *  vec2 ran_vec2_negate(vec2 v)                                    - negates the given vector
 *  ivec2 ran_ivec2_negate(ivec2 v)
 *  vec2 ran_vec2_normalize(vec2 v)                                 - calculates the normal of given vector
 *  vec2 ran_vec2_rotate(vec2 v, float_t a)                         - rotates given vector by given angle in radians
 *  vec2 ran_vec2_rotate_deg(vec2 v, float_t a)                     - rotates given vector by given angle in degrees
 *  float_t ran_vec2_distance2(vec2 a, vec2 b)                      - calculates the distance squared between two vectors
 *  int32_t ran_ivec2_distance2(ivec2 a, ivec2 b)
 *  float_t ran_vec2_distance(vec2 a, vec2 b)                       - calculates the distance between two vectors
 *  float_t ran_ivec2_distance(ivec2 a, ivec2 b)
 *  vec2 ran_vec2_max(vec2 a, vec2 b)                               - returns the the biggest possible vector of the given vectors
 *  ivec2 ran_ivec2_max(ivec2 a, ivec2 b)
 *  vec2 ran_vec2_min(vec2 a, vec2 b)                               - returns the the smallest possible vector of the given vectors
 *  ivec2 ran_ivec2_min(ivec2 a, ivec2 b)
 *  vec2 ran_vec2_clamp(vec2 v, float_t minval, float_t maxval)     - clamps the vectors values between the minimum value and the maximum value
 *  ivec2 ran_ivec2_clamp(ivec2 v, int32_t minval, int32_t maxval)
 */

#ifndef RAN_VEC2_H
#define RAN_VEC2_H

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

typedef struct vec2
{
    float_t x;
    float_t y;
} vec2;

typedef struct ivec2
{
    int32_t x;
    int32_t y;
} ivec2;

/**
 * @brief Prints the vector values to console
 * @param v
 * @return
 */
RAN_INLINE void ran_vec2_printf(vec2 v)
{
    printf("<x: %f, y: %f>\n", v.x, v.y);
}

/**
 * @brief Prints the vector values to console
 * @param v
 * @return
 */
RAN_INLINE void ran_ivec2_printf(ivec2 v)
{
    printf("<x: %d, y: %d>\n", v.x, v.y);
}

/**
 * @brief Converts vector to OpenGL compatible type
 * @param v
 * @return float*
 */
RAN_INLINE float_t *ran_vec22opengl_vec2(vec2 v)
{
    return (float[2]){v.x, v.y};
}

/**
 * @brief Returns the dot product of two vectors
 * @param a
 * @param b
 * @return float
 */
RAN_INLINE float_t ran_vec2_dot(vec2 a, vec2 b)
{
    return (a.x * b.x) + (a.y * b.y);
}

/**
 * @brief Returns the cross product of two vectors
 * @param a
 * @param b
 * @return float
 */
RAN_INLINE float_t ran_vec2_cross(vec2 a, vec2 b)
{
    return (a.x * b.y) - (a.y * b.x);
}

/**
 * @brief Returns the squared norm (squared magnitude) of the vector
 * @param v
 * @return float
 */
RAN_INLINE float_t ran_vec2_norm2(vec2 v)
{
    return ran_vec2_dot(v, v);
}

/**
 * @brief Returns the norm (magnitude) of the vector
 * @param v
 * @return float
 */
RAN_INLINE float_t ran_vec2_norm(vec2 v)
{
    return sqrtf(ran_vec2_norm2(v));
}

/**
 * @brief Returns a vector with the specified values
 * @param x
 * @param y
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_set(float_t x, float_t y)
{
    return (vec2){x, y};
}
/**
 * @brief Returns a vector with the specified values
 * @param x
 * @param y
 * @return ivec2
 */
RAN_INLINE ivec2 ran_ivec2_set(int32_t x, int32_t y)
{
    return (ivec2){x, y};
}

/**
 * @brief Returns a copy of a vector
 * @param v
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_copy(vec2 v)
{
    return (vec2){v.x, v.y};
}
/**
 * @brief Returns a copy of a vector
 * @param v
 * @return ivec2
 */
RAN_INLINE ivec2 ran_ivec2_copy(ivec2 v)
{
    return (ivec2){v.x, v.y};
}

/**
 * @brief Returns a vector with the value zero
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_zero()
{
    return (vec2){0.0F, 0.0F};
}
/**
 * @brief Returns a vector with the value zero
 * @return ivec2
 */
RAN_INLINE ivec2 ran_ivec2_zero()
{
    return (ivec2){0, 0};
}

/**
 * @brief Returns a vector with the value one
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_one()
{
    return (vec2){1.0F, 1.0F};
}
/**
 * @brief Returns a vector with the value one
 * @return ivec2
 */
RAN_INLINE ivec2 ran_ivec2_one()
{
    return (ivec2){1, 1};
}

/**
 * @brief Returns the sum of two vectors
 * @param a
 * @param b
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_add(vec2 a, vec2 b)
{
    return (vec2){a.x + b.x, a.y + b.y};
}
/**
 * @brief Returns the sum of two vectors
 * @param a
 * @param b
 * @return ivec2
 */
RAN_INLINE ivec2 ran_ivec2_add(ivec2 a, ivec2 b)
{
    return (ivec2){a.x + b.x, a.y + b.y};
}

/**
 * @brief Returns the sum of a vector and a scalar
 * @param v
 * @param s
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_adds(vec2 v, float_t s)
{
    return (vec2){v.x + s, v.y + s};
}
/**
 * @brief Returns the sum of a vector and a scalar
 * @param v
 * @param s
 * @return ivec2
 */
RAN_INLINE ivec2 ran_ivec2_adds(ivec2 v, int32_t s)
{
    return (ivec2){v.x + s, v.y + s};
}

/**
 * @brief Returns the difference of two vectors
 * @param a
 * @param b
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_sub(vec2 a, vec2 b)
{
    return (vec2){a.x - b.x, a.y - b.y};
}
/**
 * @brief Returns the difference of two vectors
 * @param a
 * @param b
 * @return ivec2
 */
RAN_INLINE ivec2 ran_ivec2_sub(ivec2 a, ivec2 b)
{
    return (ivec2){a.x - b.x, a.y - b.y};
}

/**
 * @brief Returns the difference of a vector and a scalar
 * @param v
 * @param s
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_subs(vec2 v, int32_t s)
{
    return (vec2){v.x - s, v.y - s};
}
/**
 * @brief Returns the difference of a vector and a scalar
 * @param v
 * @param s
 * @return ivec2
 */
RAN_INLINE ivec2 ran_ivec2_subs(ivec2 v, int32_t s)
{
    return (ivec2){v.x - s, v.y - s};
}

/**
 * @brief Returns the product of two vectors
 * @param a
 * @param b
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_mul(vec2 a, vec2 b)
{
    return (vec2){a.x * b.x, a.y * b.y};
}
/**
 * @brief Returns the product of two vectors
 * @param a
 * @param b
 * @return ivec2
 */
RAN_INLINE ivec2 ran_ivec2_mul(ivec2 a, ivec2 b)
{
    return (ivec2){a.x * b.x, a.y * b.y};
}

/**
 * @brief Scales a vector
 * @param v
 * @param s
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_scale(vec2 v, float_t s)
{
    return (vec2){v.x * s, v.y * s};
}
/**
 * @brief Scales a vector
 * @param v
 * @param s
 * @return ivec2
 */
RAN_INLINE ivec2 ran_ivec2_scale(ivec2 v, int32_t s)
{
    return (ivec2){v.x * s, v.y * s};
}

/**
 * @brief Scales a vector if its norm is not zero
 * @param v
 * @param s
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_scale_as(vec2 v, float_t s)
{
    float_t norm = ran_vec2_norm(v);
    return fabsf(norm) <= FLT_EPSILON ? ran_vec2_zero() : ran_vec2_scale(v, s / norm);
}

/**
 * @brief Returns the quotient of two vectors
 * @param a
 * @param b
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_div(vec2 a, vec2 b)
{
    return (vec2){a.x / b.x, a.y / b.y};
}

/**
 * @brief Returns the quotient of a vector and a scalar
 * @param v
 * @param s
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_divs(vec2 v, float_t s)
{
    return (vec2){v.x / s, v.y / s};
}

/**
 * @brief Returns an inverted vector
 * @param v
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_negate(vec2 v)
{
    return (vec2){-v.x, -v.y};
}
/**
 * @brief Returns an inverted vector
 * @param v
 * @return ivec2
 */
RAN_INLINE ivec2 ran_ivec2_negate(ivec2 v)
{
    return (ivec2){-v.x, -v.y};
}

/**
 * @brief Returns the normalized vector
 * @param v
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_normalize(vec2 v)
{
    float_t norm = ran_vec2_norm(v);
    return fabsf(norm) <= FLT_EPSILON ? ran_vec2_zero() : ran_vec2_scale(v, 1 / norm);
}

/**
 * @brief Rotates the vector by an angle in radians
 * @param v
 * @param a
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_rotate(vec2 v, float_t a)
{
    return (vec2){(v.x * cosf(a)) - (v.y * sinf(a)),
                  (v.x * sinf(a)) + (v.y * cosf(a))};
}
/**
 * @brief Rotates the vector by an angle in degrees
 * @param v
 * @param a
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_rotate_deg(vec2 v, float_t a)
{
    return (vec2){v.x * cosf(ran_deg2rad(a)) - (v.y * sinf(ran_deg2rad(a))),
                  v.x * sinf(ran_deg2rad(a)) + (v.y * cosf(ran_deg2rad(a)))};
}

/**
 * @brief Returns the distance squared between two vectors
 * @param a
 * @param b
 * @return float
 */
RAN_INLINE float_t ran_vec2_distance2(vec2 a, vec2 b)
{
    return ran_pow2f(a.x - b.x) + ran_pow2f(a.y - b.y);
}
/**
 * @brief Returns the distance squared between two vectors
 * @param a
 * @param b
 * @return float
 */
RAN_INLINE int32_t ran_ivec2_distance2(ivec2 a, ivec2 b)
{
    return ran_pow2i(a.x - b.x) + ran_pow2i(a.y - b.y);
}

/**
 * @brief Returns the distance between two vectors
 * @param a
 * @param b
 * @return float
 */
RAN_INLINE float_t ran_vec2_distance(vec2 a, vec2 b)
{
    return sqrtf(ran_vec2_distance2(a, b));
}
/**
 * @brief Returns the distance between two vectors
 * @param a
 * @param b
 * @return float
 */
RAN_INLINE float_t ran_ivec2_distance(ivec2 a, ivec2 b)
{
    return sqrtf((float_t)ran_ivec2_distance2(a, b));
}

/**
 * @brief Returns the biggest possible vector
 * @param a
 * @param b
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_max(vec2 a, vec2 b)
{
    return (vec2){ran_maxf(a.x, b.x), ran_maxf(a.y, b.y)};
}
/**
 * @brief Returns the biggest possible vector
 * @param a
 * @param b
 * @return ivec2
 */
RAN_INLINE ivec2 ran_ivec2_max(ivec2 a, ivec2 b)
{
    return (ivec2){ran_maxi(a.x, b.x), ran_maxi(a.y, b.y)};
}

/**
 * @brief Returns the smallest possible vector
 * @param a
 * @param b
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_min(vec2 a, vec2 b)
{
    return (vec2){ran_minf(a.x, b.x), ran_minf(a.y, b.y)};
}
/**
 * @brief Returns the smallest possible vector
 * @param a
 * @param b
 * @return ivec2
 */
RAN_INLINE ivec2 ran_ivec2_min(ivec2 a, ivec2 b)
{
    return (ivec2){ran_mini(a.x, b.x), ran_mini(a.y, b.y)};
}

/**
 * @brief Clamps the vector between the specified values
 * @param v
 * @param minval
 * @param maxval
 * @return vec2
 */
RAN_INLINE vec2 ran_vec2_clamp(vec2 v, float_t minval, float_t maxval)
{
    return (vec2){ran_clampf(v.x, minval, maxval), ran_clampf(v.y, minval, maxval)};
}
/**
 * @brief Clamps the vector between the specified values
 * @param v
 * @param minval
 * @param maxval
 * @return ivec2
 */
RAN_INLINE ivec2 ran_ivec2_clamp(ivec2 v, int32_t minval, int32_t maxval)
{
    return (ivec2){ran_clampi(v.x, minval, maxval), ran_clampi(v.y, minval, maxval)};
}

#endif /* RAN_VEC2_H */