// interpolate_entity_positions: moves a list of entities a step toward their keyframe positions each frame,
// taking the shortest way around a 0x10000 wrap. Called from engine/common.

#include "global.h"

// Keeps `x + k` as one term (C's `p - (x - 0x10000)` gets folded to `(p + 0x10000) - x`).
static inline s32 wrap(s32 value, s32 k) {
    return value + k;
}

s32 interpolate_entity_positions(struct InterpEnt *ents, s16 *pos, s8 *off, u8 *tbl, u8 unused, u8 frame, u8 idx,
                                 s32 count, s32 stride) {
    s32 done = 0;
    u8 end;
    struct InterpCand cands[3];
    s32 rem, i, delta;

    pos += idx;
    off += idx * 2;
    if (tbl != NULL) {
        end = tbl[idx];
        for (i = 1; i < count; i++, pos += stride, off += stride * 2) {
            if (frame < end) {
                rem = end - frame;
                delta = *pos;
                cands[0].val = delta - ents[i].unkC;
                cands[1].val = delta - wrap(ents[i].unkC, -0x10000);
                cands[2].val = delta - wrap(ents[i].unkC, 0x10000);
                cands[0].abs = cands[0].val;
                cands[1].abs = cands[1].val;
                cands[2].abs = cands[2].val;
                if (cands[0].abs < 0)
                    cands[0].abs = -cands[0].abs;
                if (cands[1].abs < 0)
                    cands[1].abs = -cands[1].abs;
                if (cands[2].abs < 0)
                    cands[2].abs = -cands[2].abs;
                if (cands[0].abs > cands[1].abs) {
                    if (cands[1].abs > cands[2].abs)
                        delta = cands[2].val;
                    else
                        delta = cands[1].val;
                } else {
                    if (cands[0].abs > cands[2].abs)
                        delta = cands[2].val;
                    else
                        delta = cands[0].val;
                }
                ents[i].unkC += Div(delta, rem);
                if (off != NULL) {
                    ents[i].unk8 += Div((off[0] << 8) - ents[i].unk8, rem);
                    ents[i].unkA += Div((off[1] << 8) - ents[i].unkA, rem);
                }
            } else {
                ents[i].unkC = *pos;
                if (off != NULL) {
                    ents[i].unk8 = off[0] << 8;
                    ents[i].unkA = off[1] << 8;
                }
                done++;
            }
        }
    }
    return done;
}

// Empty and never referenced (dead code kept in the ROM).
static void interpolate_unused_stub(void) {}
