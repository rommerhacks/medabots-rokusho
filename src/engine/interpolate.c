// interpolate_entity_positions: moves a list of entities a step toward their keyframe positions each frame,
// taking the shortest way around a 0x10000 wrap. Called from engine/common.

#include "global.h"

// Keeps `x + k` as one term (C's `p - (x - 0x10000)` gets folded to `(p + 0x10000) - x`).
static inline s32 wrap(s32 v, s32 k) {
    return v + k;
}

s32 interpolate_entity_positions(struct InterpEnt *e, s16 *pos, s8 *off, u8 *tbl, u8 unused, u8 frame, u8 idx,
                                 s32 count, s32 stride) {
    s32 done = 0;
    u8 end;
    struct InterpCand c[3];
    s32 rem, i, p;

    pos += idx;
    off += idx * 2;
    if (tbl != NULL) {
        end = tbl[idx];
        for (i = 1; i < count; i++, pos += stride, off += stride * 2) {
            if (frame < end) {
                rem = end - frame;
                p = *pos;
                c[0].val = p - e[i].unkC;
                c[1].val = p - wrap(e[i].unkC, -0x10000);
                c[2].val = p - wrap(e[i].unkC, 0x10000);
                c[0].abs = c[0].val;
                c[1].abs = c[1].val;
                c[2].abs = c[2].val;
                if (c[0].abs < 0)
                    c[0].abs = -c[0].abs;
                if (c[1].abs < 0)
                    c[1].abs = -c[1].abs;
                if (c[2].abs < 0)
                    c[2].abs = -c[2].abs;
                if (c[0].abs > c[1].abs) {
                    if (c[1].abs > c[2].abs)
                        p = c[2].val;
                    else
                        p = c[1].val;
                } else {
                    if (c[0].abs > c[2].abs)
                        p = c[2].val;
                    else
                        p = c[0].val;
                }
                e[i].unkC += Div(p, rem);
                if (off != NULL) {
                    e[i].unk8 += Div((off[0] << 8) - e[i].unk8, rem);
                    e[i].unkA += Div((off[1] << 8) - e[i].unkA, rem);
                }
            } else {
                e[i].unkC = *pos;
                if (off != NULL) {
                    e[i].unk8 = off[0] << 8;
                    e[i].unkA = off[1] << 8;
                }
                done++;
            }
        }
    }
    return done;
}

// Empty and never referenced (dead code kept in the ROM).
static void interpolate_unused_stub(void) {}
