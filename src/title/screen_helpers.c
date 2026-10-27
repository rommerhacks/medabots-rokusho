// Helpers shared by the mode-2 (title-side) screens: the eight-sprite wave effect, sprite priority flags,
// decompress_and_write_tilemap (used by nearly every mode-2 screen and the link scenes), tilemap tile /
// palette offsets, init_multiplayer_id and small geometry helpers. Talks to engine/ and link/.
#include "global.h"

// Eight sprites (spr[0..7]) bob on a sine wave around y = 80: sprite k uses phase t - (7 - k) * 0x80,
// amplitude gUnk_03006F74->unk15 (counts down each call), speed unk16 (counts up). Returns 1 once the
// amplitude is 0. The divide by d (not a constant) keeps the __divsi3 call of the original.
#define WAVE_X(a) (gUnk_080750E0[(a) & 0x3FF] / d * amp >> 3)
#define SET_WAVE_Y(k, a)                                                                                               \
    if (gUnk_080750E0[(a) & 0x3FF] < 0)                                                                                \
        spr[k].unk4 = WAVE_X(a) + mid;                                                                                 \
    else                                                                                                               \
        spr[k].unk4 = mid - WAVE_X(a)

static u32 sprite_wave_bob8(struct Unk_03002C30 *spr) {
    u32 done = 0;
    s32 d = 0x400;
    s32 mid = 80;
    u8 amp = gUnk_03006F74->unk15;
    u8 speed = gUnk_03006F74->unk16;
    s32 ph[8];

    ph[0] = gUnk_03006F74->unk2++ * speed;
    ph[1] = ph[0] - 0x80;
    ph[2] = ph[0] - 0x100;
    ph[3] = ph[0] - 0x180;
    ph[4] = ph[0] - 0x200;
    ph[5] = ph[0] - 0x280;
    ph[6] = ph[0] - 0x300;
    ph[7] = ph[0] - 0x380;

    if (gUnk_080750E0[ph[7] & 0x3FF] < 0)
        spr[0].unk4 = WAVE_X(ph[7]) + mid;
    else
        spr[0].unk4 = -WAVE_X(ph[7]) + mid;
    SET_WAVE_Y(1, ph[6]);
    SET_WAVE_Y(2, ph[5]);
    SET_WAVE_Y(3, ph[4]);
    SET_WAVE_Y(4, ph[3]);
    SET_WAVE_Y(5, ph[2]);
    SET_WAVE_Y(6, ph[1]);
    SET_WAVE_Y(7, ph[0]);
    if (gUnk_03006F74->unk15 == 0)
        done = 1;
    else {
        gUnk_03006F74->unk15--;
        gUnk_03006F74->unk16++;
    }
    return done;
}

// D-pad moves the town map cursor (unk17) through the neighbour table of the current map; returns 1 on a press.
u32 town_map_move_cursor(void) {
    struct Unk_03006F74 **pw = &gUnk_03006F74;
    struct Unk_03006F74 *w = *pw;
    u8 old = w->unk17;
    u32 off = old * 4 + gUnk_030057E0.unkC32 * 40;
    const u8 *tbl = w->unk18 ? gUnk_080AF674 : gUnk_080AF5FC;
    if (*(u8 *)&gNewKeys & 0x20)
        w->unk17 = tbl[off];
    else if (*(u8 *)&gNewKeys & 0x10)
        w->unk17 = tbl[off + 1];
    else if (*(u8 *)&gNewKeys & 0x40)
        w->unk17 = tbl[off + 2];
    else if (*(u8 *)&gNewKeys & 0x80)
        w->unk17 = tbl[off + 3];
    else
        goto none;
    play_sound_effect(old != (*pw)->unk17 ? 2 : 6);
    return 1;
none:
    return 0;
}

void update_battle_sprite_priority_flags(void) {
    if (gUnk_03006F74->unk20 > 4) {
        if ((*(u8 *)0x02023078) == 0)
            gUnk_03002C30[104].unk0 &= 0xBFFF;
        else if (gFrameCounter & 8)
            gUnk_03002C30[104].unk0 |= 0x4000;
        else
            gUnk_03002C30[104].unk0 &= 0xBFFF;
        if ((*(u8 *)0x02023078) + 3 == gUnk_03006F74->unk20 - 1)
            gUnk_03002C30[105].unk0 &= 0xBFFF;
        else if (gFrameCounter & 8)
            gUnk_03002C30[105].unk0 |= 0x4000;
        else
            gUnk_03002C30[105].unk0 &= 0xBFFF;
    }
}

void decompress_and_write_tilemap(const void *src, u32 bgcnt) {
    s32 w, h, x, y, cols;
    u16 *data, *dst;

    LZ77UnCompWram(src, gDecompressBuffer);
    w = *(u32 *)gDecompressBuffer;
    h = *(u32 *)0x02030004;
    data = (u16 *)(gDecompressBuffer + 0x10);
    dst = (u16 *)(((bgcnt >> 8) & 0x1F) * 0x800 + VRAM);
    cols = (((bgcnt & 0xC000) >> 14) & 1) ? 64 : 32;
    for (y = 0; y < h; y++) {
        for (x = 0; x < cols; x++) {
            if (x < w)
                *dst = *data++;
            dst++;
        }
    }
}

void tilemap_offset_tiles_and_palette(u32 tiles, u32 palette, u32 blk) {
    u16 add = tiles;
    // pinned so pal << 12 stays inside the loop (the original recomputes it every tile)
    register u32 pal asm("r6") = (u8)palette;
    u8 block = blk;
    u16 *p = (u16 *)(VRAM + block * 0x800);
    s32 i;

    for (i = 0; i < 0x400; i++) {
        u32 h;
        u32 x = *p;
        u32 t = (((x & 0x3FF) + add) & 0x3FF) | (x & 0xFC00);
        s32 mask = 0xF000;

        x = pal;
        h = (t & mask) + (x << 12);
        *p = (t & 0xFFF) | h;
        p++;
    }
}

void init_multiplayer_id(void) {
    u8 buf[4];
    memcpy_optimized(buf, gUnk_080AF6EC, 4);
    gUnk_03000B90 = (*(vu32 *)0x04000128 << 26) >> 30;
}

// guess: link play uses a key word received over the link; new / released keys from it (no callers).
void keys_update_from(u16 keys) {
    u16 *newKeys = &gNewKeys;
    u16 *prev = &gUnk_03006F74->unk78;
    *newKeys = keys & ~*prev;
    gReleasedKeys = *prev & ~keys;
    *prev = keys;
}

static void link_poll_keys(void) {
    if (gUnk_03005030 != 0) {
        if (gUnk_03000B90)
            keys_update_from(gUnk_03005010.unk8[0][0]);
        else {
            register struct Unk_03005010 *p asm("r0") = &gUnk_03005010;
            p->unk4 = gHeldKeys;
            keys_update_from(p->unk8[0][0]);
        }
    }
}

static u16 point_distance(s16 x1, s16 y1, s16 x2, s16 y2) {
    s32 dx = x2 - x1;
    s32 dy = y2 - y1;
    return Sqrt(dx * dx + dy * dy);
}
