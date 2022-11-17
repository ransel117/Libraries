#ifndef RAN_ARRAY_H
#define RAN_ARRAY_H

#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef void (*ranarr_elem_destructor_t)(void *elem);

#define ranarr_array_type(type) type *

#define ranarr_capacity(arr) \
    ((arr) ? ((size_t *)(arr))[-1] : (size_t)0)

#define ranarr_size(arr) \
    ((arr) ? ((size_t *)(arr))[-2] : (size_t)0)

#define ranarr_set_elem_destructor(arr, elem_destructor_fn)                                \
    do                                                                                     \
    {                                                                                      \
        if (!(arr))                                                                        \
        {                                                                                  \
            ranarr_grow((arr), 0);                                                         \
        }                                                                                  \
        ((ranarr_elem_destructor_t *)&(((size_t *)(arr))[-2]))[-1] = (elem_destructor_fn); \
    } while (0)

#define ranarr_elem_destructor(arr) \
    ((arr) ? (((ranarr_elem_destructor_t *)&(((size_t *)(arr))[-2]))[-1]) : NULL)

#define ranarr_empty(arr) \
    (ranarr_size(arr) == 0)

#define ranarr_reserve(arr, capacity)           \
    do                                          \
    {                                           \
        size_t cv_cap__ = ranarr_capacity(arr); \
        if (cv_cap__ < (capacity))              \
        {                                       \
            ranarr_grow((arr), (capacity));     \
        }                                       \
    } while (0)

#define ranarr_erase(arr, i)                                                                 \
    do                                                                                       \
    {                                                                                        \
        if ((arr))                                                                           \
        {                                                                                    \
            const size_t cv_sz__ = ranarr_size(arr);                                         \
            if ((i) < cv_sz__)                                                               \
            {                                                                                \
                ranarr_set_size((arr), cv_sz__ - 1);                                         \
                memmove((arr) + (i), (arr) + (i) + 1, sizeof(*(arr)) * (cv_sz__ - 1 - (i))); \
            }                                                                                \
        }                                                                                    \
    } while (0)

#define ranarr_free(arr)                                                                            \
    do                                                                                              \
    {                                                                                               \
        if ((arr))                                                                                  \
        {                                                                                           \
            size_t *p1__ = (size_t *)&(((ranarr_elem_destructor_t *)&(((size_t *)(arr))[-2]))[-1]); \
            ranarr_elem_destructor_t elem_destructor__ = ranarr_elem_destructor((arr));             \
            if (elem_destructor__)                                                                  \
            {                                                                                       \
                size_t i__;                                                                         \
                for (i__ = 0; i__ < ranarr_size(arr); ++i__)                                        \
                    elem_destructor__(&arr[i__]);                                                   \
            }                                                                                       \
            free(p1__);                                                                             \
        }                                                                                           \
    } while (0)

#define ranarr_begin(arr) \
    (arr)

#define ranarr_end(arr) \
    ((arr) ? &((arr)[ranarr_size(arr)]) : NULL)

#ifdef ranarr_LOGARITHMIC_GROWTH
#define ranarr_compute_next_grow(size) \
    ((size) ? ((size) << 1) : 1)
#else
#define ranarr_compute_next_grow(size) \
    ((size) + 1)

#endif /* ranarr_LOGARITHMIC_GROWTH */

#define ranarr_push_back(arr, value)                                \
    do                                                              \
    {                                                               \
        size_t cv_cap__ = ranarr_capacity(arr);                     \
        if (cv_cap__ <= ranarr_size(arr))                           \
        {                                                           \
            ranarr_grow((arr), ranarr_compute_next_grow(cv_cap__)); \
        }                                                           \
        (arr)[ranarr_size(arr)] = (value);                          \
        ranarr_set_size((arr), ranarr_size(arr) + 1);               \
    } while (0)

#define ranarr_insert(arr, pos, val)                                                                      \
    do                                                                                                    \
    {                                                                                                     \
        if (ranarr_capacity(arr) <= ranarr_size(arr) + 1)                                                 \
        {                                                                                                 \
            ranarr_grow((arr), ranarr_compute_next_grow(ranarr_capacity((arr))));                         \
        }                                                                                                 \
        if ((pos) < ranarr_size(arr))                                                                     \
        {                                                                                                 \
            memmove((arr) + (pos) + 1, (arr) + (pos), sizeof(*(arr)) * ((ranarr_size(arr) + 1) - (pos))); \
        }                                                                                                 \
        (arr)[(pos)] = (val);                                                                             \
        ranarr_set_size((arr), ranarr_size(arr) + 1);                                                     \
    } while (0)

#define ranarr_pop_back(arr)                                                        \
    do                                                                              \
    {                                                                               \
        ranarr_elem_destructor_t elem_destructor__ = ranarr_elem_destructor((arr)); \
        if (elem_destructor__)                                                      \
            elem_destructor__(&(arr)[ranarr_size(arr) - 1]);                        \
        ranarr_set_size((arr), ranarr_size(arr) - 1);                               \
    } while (0)

#define ranarr_copy(from, to)                                          \
    do                                                                 \
    {                                                                  \
        if ((from))                                                    \
        {                                                              \
            ranarr_grow(to, ranarr_size(from));                        \
            ranarr_set_size(to, ranarr_size(from));                    \
            memcpy((to), (from), ranarr_size(from) * sizeof(*(from))); \
        }                                                              \
    } while (0)

#define ranarr_set_capacity(arr, size)      \
    do                                      \
    {                                       \
        if ((arr))                          \
        {                                   \
            ((size_t *)(arr))[-1] = (size); \
        }                                   \
    } while (0)

#define ranarr_set_size(arr, size)          \
    do                                      \
    {                                       \
        if ((arr))                          \
        {                                   \
            ((size_t *)(arr))[-2] = (size); \
        }                                   \
    } while (0)

#define ranarr_grow(arr, count)                                                                                  \
    do                                                                                                           \
    {                                                                                                            \
        const size_t cv_sz__ = (count) * sizeof(*(arr)) + sizeof(size_t) * 2 + sizeof(ranarr_elem_destructor_t); \
        if ((arr))                                                                                               \
        {                                                                                                        \
            ranarr_elem_destructor_t *cv_p1__ = &((ranarr_elem_destructor_t *)&((size_t *)(arr))[-2])[-1];       \
            ranarr_elem_destructor_t *cv_p2__ = realloc(cv_p1__, cv_sz__);                                       \
            assert(cv_p2__);                                                                                     \
            (arr) = (void *)&((size_t *)&cv_p2__[1])[2];                                                         \
        }                                                                                                        \
        else                                                                                                     \
        {                                                                                                        \
            ranarr_elem_destructor_t *cv_p__ = malloc(cv_sz__);                                                  \
            assert(cv_p__);                                                                                      \
            (arr) = (void *)&((size_t *)&cv_p__[1])[2];                                                          \
            ranarr_set_size((arr), 0);                                                                           \
            ((ranarr_elem_destructor_t *)&(((size_t *)(arr))[-2]))[-1] = NULL;                                   \
        }                                                                                                        \
        ranarr_set_capacity((arr), (count));                                                                     \
    } while (0)

#endif /* RAN_ARRAY_H */