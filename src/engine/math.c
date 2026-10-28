// Random numbers (rng_next: table-driven generator, optional range) and a 4.12 fixed-point lerp.

#include "global.h"

u32 rng_next(u16 range) {
    gRngCounter++;
    gRngValue = gRngTable[gRngCounter & 0xF] ^ gRngState;
    {
        u32 n = ~gRngValue;
        u32 state_hi = ((s16 *)&gRngState)[1] + 0x55555555;
        gRngState = n + state_hi;
    }
    if (range == 0)
        return gRngValue;
    return (u32)(((s16 *)&gRngValue)[1] * range) >> 16;
}

// Linear interpolation in 4.12 fixed point: a at t = 0, b at t = 0x1000. Not called.
static s32 lerp_fixed12(s32 from, s32 to, s32 weight) {
    return to * weight / 4096 + from * (4096 - weight) / 4096;
}
