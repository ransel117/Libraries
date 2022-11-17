#ifndef RAN_AUDIO_H
#define RAN_AUDIO_H

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdint.h>

#define RAN_INLINE static inline __attribute((always_inline))

RAN_INLINE float_t amp2dB(float_t amplitude)
{
    return 20.0F * log10f(amplitude);
}

RAN_INLINE float_t dB2amp(float_t decibel)
{
    return powf(10.0F, (decibel / 20.0F));
}

#endif /* RAN_AUDIO_H */