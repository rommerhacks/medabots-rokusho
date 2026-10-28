// Blend fade effect: init_blend_effect sets up a BLDCNT/BLDY fade state, blend_fade_step_08065598 advances it
// once per frame and reports when it is done. Used by the title, link and race screens.
#include "global.h"

void init_blend_effect(void *state, u8 level, u8 delay, s8 step, u16 mode) {
    struct BlendEffect *blend = state;
    u16 zero = 0;
    vu16 *reg;
    blend->mode = mode;
    blend->level = level;
    blend->delay = delay;
    blend->step = step;
    REG_BLDCNT = mode | 0x3F;
    reg = &REG_BLDALPHA;
    *reg = zero;
    reg++;
    *reg = blend->level;
}

u32 blend_fade_step_08065598(void *state) {
    struct BlendEffect *blend = state;
    u32 done = 0;
    if (blend->step == 0) {
        done = 1;
    } else {
        REG_BLDCNT = blend->mode | 0x3F;
        REG_BLDALPHA = done;
        REG_BLDY = blend->level;
        if (++blend->counter >= blend->delay) {
            blend->counter = 0;
            if (blend->step > 0 && blend->level > 0xF) {
                blend->step = 0;
                done = 1;
            }
            if (blend->step < 0 && blend->level == 0) {
                blend->step = 0;
                done = 1;
            }
            if (done == 0)
                blend->level += blend->step;
        }
    }
    return done;
}
