// Blend fade effect: init_blend_effect sets up a BLDCNT/BLDY fade state, blend_fade_step_08065598 advances it
// once per frame and reports when it is done. Used by the title, link and race screens.
#include "global.h"

void init_blend_effect(void *state, u8 a, u8 b, s8 c, u16 mode) {
    struct BlendEffect *s = state;
    u16 zero = 0;
    vu16 *r;
    s->mode = mode;
    s->unk2 = a;
    s->unk3 = b;
    s->unk5 = c;
    REG_BLDCNT = mode | 0x3F;
    r = &REG_BLDALPHA;
    *r = zero;
    r++;
    *r = s->unk2;
}

u32 blend_fade_step_08065598(void *state) {
    struct BlendEffect *s = state;
    u32 done = 0;
    if (s->unk5 == 0) {
        done = 1;
    } else {
        REG_BLDCNT = s->mode | 0x3F;
        REG_BLDALPHA = done;
        REG_BLDY = s->unk2;
        if (++s->unk4 >= s->unk3) {
            s->unk4 = 0;
            if (s->unk5 > 0 && s->unk2 > 0xF) {
                s->unk5 = 0;
                done = 1;
            }
            if (s->unk5 < 0 && s->unk2 == 0) {
                s->unk5 = 0;
                done = 1;
            }
            if (done == 0)
                s->unk2 += s->unk5;
        }
    }
    return done;
}
