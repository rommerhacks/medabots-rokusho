// Shared helpers used by menus and battles, one unit with no clear inner boundary (call-crossing scores
// stay at 2-16): a second RNG, BG blend effects, number and tilemap drawing, polar coordinates, the
// battle Medabot sprite groups, Medapart slot searches, the random encounter check, scroll / blend
// effects of the battle field, tilemap rect copies, scene setup and init_game_mode.

#include "global.h"

static void scanline_scroll_vblank(void);

// Second RNG (0-255): mixes the frame counter into a 16-bit state, or replays gUnk_083B286C when unk89 is set.
s32 rng_next_byte(void) {
    if (gGameWork.skipBotSetup == 0) {
        u16 s = gGameWork.rngSeed + gGameWork.rngLast;

        s += 0x87 + (((gFrameCounter << 4) + (gFrameCounter >> 4) + 1) >> 1);
        gGameWork.rngSeed = ((s & 0xFF) << 8) | (((s & 0xFF00) >> 8) ^ (s & 0xFF));
        gGameWork.rngLast = ((s & 0xFF00) >> 8) ^ s;
        return gGameWork.rngLast;
    } else {
        gGameWork.rngIndex++;
        gGameWork.rngLast = gUnk_083B286C[gGameWork.rngIndex];
        return gGameWork.rngLast;
    }
}

void set_blend_effect_mode(u8 mode, u16 targets, u16 speed) {
    u16 bld, eva, evb, evy;

    gGameWork.blendMode = mode;
    gGameWork.blendSpeed = speed;
    gGameWork.blendProgress = 0;
    switch (mode) {
    case 1:
        bld = 0x40;
        eva = 16;
        evb = 16;
        evy = 16;
        break;
    case 2:
        bld = 0x40;
        eva = 0;
        evb = 0;
        evy = 0;
        break;
    case 3:
        bld = 0x80;
        eva = 16;
        evb = 16;
        evy = 16;
        break;
    case 4:
        bld = 0x80;
        eva = 0;
        evb = 0;
        evy = 0;
        break;
    case 5:
        bld = 0xC0;
        eva = 16;
        evb = 16;
        evy = 16;
        break;
    case 6:
        bld = 0xC0;
        eva = 0;
        evb = 0;
        evy = 0;
        break;
    default:
        bld = 0;
        eva = 0;
        evb = 0;
        evy = 0;
        break;
    }
    REG_BLDALPHA = ((evb & 0x1F) << 8) | (eva & 0x1F);
    REG_BLDY = evy & 0x1F;
    REG_BLDCNT = bld | targets;
}

// Other modes write whatever eva / evb / evy hold (uninitialized), like the original.
u32 update_blend_effect(void) {
    u16 eva, evb, evy;

    gGameWork.blendProgress += gGameWork.blendSpeed;
    switch (gGameWork.blendMode) {
    case 1:
    case 3:
    case 5:
        eva = 16 - (gGameWork.blendProgress >> 4);
        evb = eva;
        evy = eva;
        break;
    case 2:
    case 4:
    case 6:
        eva = gGameWork.blendProgress >> 4;
        evb = eva;
        evy = eva;
        break;
    }
    REG_BLDALPHA = ((evb & 0x1F) << 8) | (eva & 0x1F);
    REG_BLDY = evy & 0x1F;
    if (gGameWork.blendProgress > 0xFF)
        return 1;
    return 0;
}

void fill_text_blank(u8 *buf, u8 n) {
    u32 i;

    for (i = 0; i < n; i++)
        *buf++ = 0x43;
    *buf = 0xFE;
}

void draw_tile_block(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, u16 entry) {
    u32 i, j;
    u16 *base = (u16 *)(VRAM + ((bgcnt >> 8) & 0x1F) * 0x800) + x + y * 32;

    for (j = 0; j < h; j++) {
        u16 *p = base + j * 32;
        for (i = 0; i < w; i++)
            *p++ = entry++;
    }
}

void fill_tilemap_pair_or_divide(u8 value, u8 x, u8 y, u32 bgcnt, u16 tile) {
    u8 d[3];
    u8 r;

    if (value == 0xFF) {
        draw_tile_block(1, 2, x, y, bgcnt, tile + 0x18);
        draw_tile_block(1, 2, x + 1, y, bgcnt, tile + 0x18);
    } else {
        d[0] = value / 100;
        r = value - (u8)(value / 100) * 100;
        d[1] = r / 10;
        d[2] = r - (u8)(r / 10) * 10;
        if (d[0] != 0) {
            draw_tile_block(1, 2, x, y, bgcnt, tile + 0x14);
            draw_tile_block(1, 2, x + 1, y, bgcnt, tile + 0x16);
        } else if (d[1] != 0) {
            draw_tile_block(1, 2, x, y, bgcnt, tile + d[1] * 2);
            draw_tile_block(1, 2, x + 1, y, bgcnt, tile + d[2] * 2);
        } else {
            vram_fill_tilemap_rect(1, 2, x, y, bgcnt, 0);
            draw_tile_block(1, 2, x + 1, y, bgcnt, tile + d[2] * 2);
        }
    }
}

// Draws the last `digits` decimal digits of n as tiles (tile + digit); leading zeros blank, the last digit always.
void draw_number_bgcnt(u32 n, u32 x, u32 y, u32 digits, u32 bgcnt, u32 tile) {
    u8 d[6];
    u32 r;
    u32 i;
    u8 start, started;
    u16 *dst;
    u8 count = digits;
    u16 t = tile;

    d[0] = n / 100000;
    r = n - n / 100000 * 100000;
    d[1] = r / 10000;
    r = r - n / 10000 * 10000;
    d[2] = r / 1000;
    r = r - r / 1000 * 1000;
    d[3] = r / 100;
    r = r - r / 100 * 100;
    d[4] = r / 10;
    r = r - r / 10 * 10;
    d[5] = r;

    start = 6 - count;
    started = 0;
    dst = (u16 *)(VRAM + ((bgcnt >> 8) & 0x1F) * 0x800) + x + y * 32;
    for (i = start; i <= 5; i++) {
        if (i <= 4) {
            if (d[i] == 0) {
                if (started)
                    *dst++ = t + d[i];
                else
                    *dst++ = 0;
            } else {
                *dst++ = t + d[i];
                started = 1;
            }
        } else {
            *dst++ = t + d[i];
        }
    }
}

static inline u32 lower_digit_tile(s16 base, u32 digit) {
    return base + 1 + digit * 2;
}

// draw_number_bgcnt with 2-row digits: top tile base + digit * 2, bottom tile one row below.
void draw_number_tall_bgcnt(u32 value, u32 x, u32 y, u8 digits, u32 bgcnt, u16 base) {
    u8 d[6];
    u32 rem;
    u32 i;
    u8 start;
    u32 flag;
    vu16 *dst;

    d[0] = value / 100000;
    rem = value - value / 100000 * 100000;
    d[1] = rem / 10000;
    rem -= value / 10000 * 10000;
    d[2] = rem / 1000;
    rem -= rem / 1000 * 1000;
    d[3] = rem / 100;
    rem -= rem / 100 * 100;
    d[4] = rem / 10;
    rem -= rem / 10 * 10;
    d[5] = rem;

    start = 6 - digits;
    flag = 0;
    dst = (vu16 *)(VRAM + ((bgcnt >> 8) & 0x1F) * 0x800) + x + y * 32;
    for (i = start; i < 6; i++) {
        if (i <= 4) {
            if (d[i] == 0) {
                if (flag) {
                    *dst = base + d[i] * 2;
                    dst[32] = lower_digit_tile(base, d[i]);
                    *dst++;
                } else {
                    *dst = 0;
                    dst[32] = 0;
                    *dst++;
                }
            } else {
                *dst = base + d[i] * 2;
                dst[32] = lower_digit_tile(base, d[i]);
                *dst++;
                flag = 1;
            }
        } else {
            *dst = base + d[i] * 2;
            dst[32] = lower_digit_tile(base, d[i]);
            *dst++;
        }
    }
}

// "cur<tile>max" with 1-2 digits each (a leading 0 is skipped).
void draw_count_over_max(u32 cur, u32 max, u32 x, u32 y, u32 tile, u32 bgcnt, u16 tile2) {
    u8 a[2];
    u8 b[2];
    u16 *dst;
    u32 i;
    u32 q;
    u8 *p;
    u8 *pa;

    pa = a;
    q = cur / 10;
    pa[0] = q;
    q = cur - q * 10;
    a[1] = q;
    p = b;
    q = max / 10;
    p[0] = q;
    q = max - q * 10;
    p[1] = q;
    dst = (u16 *)(VRAM + ((bgcnt >> 8) & 0x1F) * 0x800 + x * 2) + y * 32;
    for (i = 0; i < 2; i++) {
        if (a[i] == 0) {
            if (i == 1)
                *dst++ = tile2 + a[i];
        } else
            *dst++ = tile2 + a[i];
    }
    *dst++ = tile;
    for (i = 0; i < 2; i++) {
        if (b[i] == 0) {
            if (i == 1)
                *dst++ = tile2 + b[i];
        } else
            *dst++ = tile2 + b[i];
    }
}

void load_part_data(u32 part, u32 kind, u8 *dst) {
    u32 i;
    u8 *d = dst;
    for (i = 0; i < 16; i++)
        *d++ = gUnk_083B827C[part * 64 + kind * 16 + i];
}

// Skill types 0, 1, 4, 5 are proximity, 2, 3, 6, 7 remote (gUnk_083B53F8 messages 17 / 18: "Proximity
// Medaparts" / "Remote Medaparts"). No return for type > 7: the original falls through with type in r0.
u32 skill_type_is_remote(u32 type) {
    switch (type) {
    case 0:
    case 1:
    case 4:
    case 5:
        return 0;
    case 2:
    case 3:
    case 6:
        return 1;
    case 7:
        return 1;
    }
}

struct Coords16 calc_polar_to_screen_coords(u32 angle, u32 radius, s32 x, s32 y) {
    struct Coords16 r;

    x += (u32)(gUnk_083D6BA0[angle] * (radius / 256.0f));
    y += (u32)(gJumpArcTable[0][angle] * (radius / 256.0f));
    r.x = x & 0x1FF;
    r.y = y & 0xFF;
    return r;
}

struct Vec16 compute_polar_to_screen_position(u32 angle, u32 radius, u32 cx, u32 cy, u32 a, u32 b) {
    struct Vec16 r;

    if (radius < a)
        a = radius;
    if (radius < b)
        b = radius;
    cx += (u32)(gUnk_083D6BA0[angle] * ((radius - b) / 256.0f));
    cy += (u32)(gJumpArcTable[0][angle] * ((radius - a) / 256.0f));
    r.x = cx & 0x1FF;
    r.y = cy & 0xFF;
    return r;
}

// Decompresses 6 sprite tile chunks (0x80 bytes each in VRAM) into OBJ tile slot `slot` (0x400 bytes):
// chunk 0 from Medabot a, 1-2 from b, 3-4 from c, 5 from d (gUnk_083B1888 has 6 pointers per Medabot).
// The index is written as (n << 2) + (n << 1): `n * 6` compiles to (n * 3) << 1.
void decompress_sprite_to_vram_08042D94(u32 a, u32 b, u32 c, u32 d, u32 slot) {
    lz_decompress_dispatch(gUnk_083B1888[(a << 2) + (a << 1)], (void *)(VRAM + 0x10000 + slot * 0x400));
    lz_decompress_dispatch(gUnk_083B1888[(b << 2) + (b << 1) + 1], (void *)(VRAM + 0x10000 + 0x80 + slot * 0x400));
    lz_decompress_dispatch(gUnk_083B1888[(b << 2) + (b << 1) + 2], (void *)(VRAM + 0x10000 + 0x100 + slot * 0x400));
    lz_decompress_dispatch(gUnk_083B1888[(c << 2) + (c << 1) + 3], (void *)(VRAM + 0x10000 + 0x180 + slot * 0x400));
    lz_decompress_dispatch(gUnk_083B1888[(c << 2) + (c << 1) + 4], (void *)(VRAM + 0x10000 + 0x200 + slot * 0x400));
    lz_decompress_dispatch(gUnk_083B1888[(d << 2) + (d << 1) + 5], (void *)(VRAM + 0x10000 + 0x280 + slot * 0x400));
}

void init_battle_medabot_sprites(u32 head, u32 rarm, u32 larm, u32 legs, u32 tile, u32 sprite, u32 x, u32 y, u32 flip,
                                 u32 prio, u32 pal) {
    clear_battle_sprite_slot(sprite, 4);
    gSpriteEntries[sprite].unk0 = 0xC004 | (prio << 10);
    if (flip)
        gSpriteEntries[sprite].unk0 |= 0x1000;
    else
        gSpriteEntries[sprite].unk0 &= 0xEFFF;
    gSpriteEntries[sprite].unk2 = x;
    gSpriteEntries[sprite].unk4 = y - 4;
    gSpriteEntries[sprite].unk6 = tile * 8 + 0x500;
    gSpriteEntries[sprite].unkA = gUnk_083BEA14[head];
    gSpriteEntries[sprite].unk1C = 0;
    gSpriteEntries[sprite].unkB = pal + 2;

    gSpriteEntries[sprite + 1].unk0 = 0xC004 | (prio << 10);
    if (flip) {
        gSpriteEntries[sprite + 1].unk0 |= 0x1000;
        gSpriteEntries[sprite + 1].unk6 = tile * 8 + 0x502;
        gSpriteEntries[sprite + 1].unkB = pal;
    } else {
        gSpriteEntries[sprite + 1].unk0 &= 0xEFFF;
        gSpriteEntries[sprite + 1].unk6 = tile * 8 + 0x501;
        gSpriteEntries[sprite + 1].unkB = pal + 3;
    }
    gSpriteEntries[sprite + 1].unk2 = x - 8;
    gSpriteEntries[sprite + 1].unk4 = y + 4;
    gSpriteEntries[sprite + 1].unkA = gUnk_083BEA14[rarm];
    gSpriteEntries[sprite + 1].unk1C = 0;
    gSpriteEntries[sprite + 1].unk8 = 0x40;
    gSpriteEntries[sprite + 1].unk9 = 0x40;
    gSpriteEntries[sprite + 1].unk18 = 0;

    gSpriteEntries[sprite + 2].unk0 = 0xC004 | (prio << 10);
    if (flip) {
        gSpriteEntries[sprite + 2].unk0 |= 0x1000;
        gSpriteEntries[sprite + 2].unk6 = tile * 8 + 0x503;
        gSpriteEntries[sprite + 2].unkB = pal + 3;
    } else {
        gSpriteEntries[sprite + 2].unk0 &= 0xEFFF;
        gSpriteEntries[sprite + 2].unk6 = tile * 8 + 0x504;
        gSpriteEntries[sprite + 2].unkB = pal;
    }
    gSpriteEntries[sprite + 2].unk2 = x + 8;
    gSpriteEntries[sprite + 2].unk4 = y + 4;
    gSpriteEntries[sprite + 2].unkA = gUnk_083BEA14[larm];
    gSpriteEntries[sprite + 2].unk1C = 0;
    gSpriteEntries[sprite + 2].unk8 = 0x40;
    gSpriteEntries[sprite + 2].unk9 = 0x40;
    gSpriteEntries[sprite + 2].unk18 = 0;

    gSpriteEntries[sprite + 3].unk0 = 0xC004 | (prio << 10);
    if (flip)
        gSpriteEntries[sprite + 3].unk0 |= 0x1000;
    else
        gSpriteEntries[sprite + 3].unk0 &= 0xEFFF;
    gSpriteEntries[sprite + 3].unk2 = x;
    gSpriteEntries[sprite + 3].unk4 = y + 4;
    gSpriteEntries[sprite + 3].unk6 = tile * 8 + 0x505;
    gSpriteEntries[sprite + 3].unkA = gUnk_083BEA14[legs];
    gSpriteEntries[sprite + 3].unk1C = 0;
    gSpriteEntries[sprite + 3].unkB = pal + 1;
}

void setup_battle_sprite_group(u32 head, u32 rarm, u32 larm, u32 legs, u32 tile, u32 sprite, u32 x, u32 y, u32 flip,
                               u32 prio, u32 pal) {
    gSpriteEntries[sprite].unk0 |= 0xC004 | (prio << 10);
    if (flip)
        gSpriteEntries[sprite].unk0 |= 0x1000;
    else
        gSpriteEntries[sprite].unk0 &= 0xEFFF;
    gSpriteEntries[sprite].unk2 = x;
    gSpriteEntries[sprite].unk4 = y - 4;
    gSpriteEntries[sprite].unk6 = tile * 8 + 0x500;
    gSpriteEntries[sprite].unkA = gUnk_083BEA14[head];
    gSpriteEntries[sprite].unk1C = 0;
    gSpriteEntries[sprite].unkB = pal + 2;

    gSpriteEntries[sprite + 1].unk0 |= 0xC004 | (prio << 10);
    if (flip) {
        gSpriteEntries[sprite + 1].unk0 |= 0x1000;
        gSpriteEntries[sprite + 1].unk6 = tile * 8 + 0x502;
        gSpriteEntries[sprite + 1].unkB = pal;
    } else {
        gSpriteEntries[sprite + 1].unk0 &= 0xEFFF;
        gSpriteEntries[sprite + 1].unk6 = tile * 8 + 0x501;
        gSpriteEntries[sprite + 1].unkB = pal + 3;
    }
    gSpriteEntries[sprite + 1].unk2 = x - 8;
    gSpriteEntries[sprite + 1].unk4 = y + 4;
    gSpriteEntries[sprite + 1].unkA = gUnk_083BEA14[rarm];
    gSpriteEntries[sprite + 1].unk1C = 0;

    gSpriteEntries[sprite + 2].unk0 |= 0xC004 | (prio << 10);
    if (flip) {
        gSpriteEntries[sprite + 2].unk0 |= 0x1000;
        gSpriteEntries[sprite + 2].unk6 = tile * 8 + 0x503;
        gSpriteEntries[sprite + 2].unkB = pal + 3;
    } else {
        gSpriteEntries[sprite + 2].unk0 &= 0xEFFF;
        gSpriteEntries[sprite + 2].unk6 = tile * 8 + 0x504;
        gSpriteEntries[sprite + 2].unkB = pal;
    }
    gSpriteEntries[sprite + 2].unk2 = x + 8;
    gSpriteEntries[sprite + 2].unk4 = y + 4;
    gSpriteEntries[sprite + 2].unkA = gUnk_083BEA14[larm];
    gSpriteEntries[sprite + 2].unk1C = 0;

    gSpriteEntries[sprite + 3].unk0 |= 0xC004 | (prio << 10);
    if (flip)
        gSpriteEntries[sprite + 3].unk0 |= 0x1000;
    else
        gSpriteEntries[sprite + 3].unk0 &= 0xEFFF;
    gSpriteEntries[sprite + 3].unk2 = x;
    gSpriteEntries[sprite + 3].unk4 = y + 4;
    gSpriteEntries[sprite + 3].unk6 = tile * 8 + 0x505;
    gSpriteEntries[sprite + 3].unkA = gUnk_083BEA14[legs];
    gSpriteEntries[sprite + 3].unk1C = 0;
    gSpriteEntries[sprite + 3].unkB = pal + 1;
}

void battle_sprite_group_set_anim(u32 sprite, u32 anim) {
    u32 i;

    gSpriteEntries[sprite + 1].unk0 |= 0x200;
    gSpriteEntries[sprite + 2].unk0 |= 0x200;
    for (i = 0; i < 16; i++)
        ;
    gSpriteEntries[sprite].unk24 = anim;
    gSpriteEntries[sprite + 1].unk24 = anim;
    gSpriteEntries[sprite + 2].unk24 = anim;
    gSpriteEntries[sprite + 3].unk24 = anim;
}

void update_battle_sprite_orbiting_positions(u32 sprite, u32 idx, u32 c) {
    struct Coords16 v;
    u32 t;
    u8 a;

    gSpriteEntries[sprite].unk2 = gSpriteEntries[sprite + 3].unk2;
    gSpriteEntries[sprite + 3].unk26 += gSpriteEntries[sprite + 3].unk24;
    if (gSpriteEntries[sprite + 3].unk26 > 0x3F) {
        gSpriteEntries[sprite + 3].unk26 -= 0x40;
        gSpriteEntries[sprite + 3].unk21 = (gSpriteEntries[sprite + 3].unk21 + 1) & 3;
        gSpriteEntries[sprite + 3].unk6 = idx * 8 + 0x505 + gUnk_083B296C[gSpriteEntries[sprite + 3].unk21];
    }

    gSpriteEntries[sprite + 1].unk26 += gSpriteEntries[sprite + 1].unk24;
    a = gSpriteEntries[sprite + 1].unk26;
    t = a >> 1;
    if (a > 0x3F) {
        t = 0x20;
        gSpriteEntries[sprite + 1].unk26 -= 0x40;
    }
    switch (gSpriteEntries[sprite + 1].unk21) {
    case 0:
        gSpriteEntries[sprite + 1].unk18 = t * 4;
        v = calc_polar_to_screen_coords(t + 0x60, 5, gSpriteEntries[sprite + 3].unk2, gSpriteEntries[sprite + 3].unk4);
        gSpriteEntries[sprite + 1].unk2 = v.x - 5;
        gSpriteEntries[sprite + 1].unk4 = v.y - 3;
        break;
    case 1:
        gSpriteEntries[sprite + 1].unk18 = 0x80 - t * 4;
        v = calc_polar_to_screen_coords(0x80 - t, 5, gSpriteEntries[sprite + 3].unk2, gSpriteEntries[sprite + 3].unk4);
        gSpriteEntries[sprite + 1].unk2 = v.x - 5;
        gSpriteEntries[sprite + 1].unk4 = v.y - 3;
        break;
    case 2:
        gSpriteEntries[sprite + 1].unk18 = 0x400 - t * 4;
        v = calc_polar_to_screen_coords(0x60 - t, 5, gSpriteEntries[sprite + 3].unk2, gSpriteEntries[sprite + 3].unk4);
        gSpriteEntries[sprite + 1].unk2 = v.x - 5;
        gSpriteEntries[sprite + 1].unk4 = v.y - 3;
        break;
    case 3:
        gSpriteEntries[sprite + 1].unk18 = t * 4 + 0x380;
        v = calc_polar_to_screen_coords(t + 0x40, 5, gSpriteEntries[sprite + 3].unk2, gSpriteEntries[sprite + 3].unk4);
        gSpriteEntries[sprite + 1].unk2 = v.x - 5;
        gSpriteEntries[sprite + 1].unk4 = v.y - 3;
        break;
    }
    if (t == 0x20)
        gSpriteEntries[sprite + 1].unk21 = (gSpriteEntries[sprite + 1].unk21 + 1) & 3;

    gSpriteEntries[sprite + 2].unk26 += gSpriteEntries[sprite + 2].unk24;
    a = gSpriteEntries[sprite + 2].unk26;
    t = a >> 1;
    if (a > 0x3F) {
        t = 0x20;
        gSpriteEntries[sprite + 2].unk26 -= 0x40;
    }
    switch (gSpriteEntries[sprite + 2].unk21) {
    case 2:
        gSpriteEntries[sprite + 2].unk18 = t * 4;
        v = calc_polar_to_screen_coords(t + 0x20, 5, gSpriteEntries[sprite + 3].unk2, gSpriteEntries[sprite + 3].unk4);
        gSpriteEntries[sprite + 2].unk2 = v.x + 5;
        gSpriteEntries[sprite + 2].unk4 = v.y - 3;
        break;
    case 3:
        gSpriteEntries[sprite + 2].unk18 = 0x80 - t * 4;
        v = calc_polar_to_screen_coords(0x40 - t, 5, gSpriteEntries[sprite + 3].unk2, gSpriteEntries[sprite + 3].unk4);
        gSpriteEntries[sprite + 2].unk2 = v.x + 5;
        gSpriteEntries[sprite + 2].unk4 = v.y - 3;
        break;
    case 0:
        gSpriteEntries[sprite + 2].unk18 = 0x400 - t * 4;
        v = calc_polar_to_screen_coords(0x20 - t, 5, gSpriteEntries[sprite + 3].unk2, gSpriteEntries[sprite + 3].unk4);
        gSpriteEntries[sprite + 2].unk2 = v.x + 5;
        gSpriteEntries[sprite + 2].unk4 = v.y - 3;
        break;
    case 1:
        gSpriteEntries[sprite + 2].unk18 = t * 4 + 0x380;
        v = calc_polar_to_screen_coords(t, 5, gSpriteEntries[sprite + 3].unk2, gSpriteEntries[sprite + 3].unk4);
        gSpriteEntries[sprite + 2].unk2 = v.x + 5;
        gSpriteEntries[sprite + 2].unk4 = v.y - 3;
        break;
    }
    if (t == 0x20)
        gSpriteEntries[sprite + 2].unk21 = (gSpriteEntries[sprite + 2].unk21 + 1) & 3;

    if (gUnk_083B296C[gSpriteEntries[sprite + 3].unk21]) {
        gSpriteEntries[sprite].unk4 = gSpriteEntries[sprite + 3].unk4 - 7;
        gSpriteEntries[sprite + 1].unk4++;
        gSpriteEntries[sprite + 2].unk4++;
    } else {
        gSpriteEntries[sprite].unk4 = gSpriteEntries[sprite + 3].unk4 - 8;
    }
}

void modify_medapart_quantity(u32 id, u32 kind, u32 byte, u32 subtract, u32 n) {
    if (subtract) {
        gMedapartInventory[kind * 240 + id * 2 + byte] -= n;
    } else {
        u8 *inv = gMedapartInventory;
        u8 *p = &inv[kind * 240 + id * 2 + byte];
        u32 v = *p + n;

        if (v > 99)
            v = 99;
        *p = v;
    }
}

void draw_tilemap_with_offset(u32 id, u32 x, u32 y, u32 bgcnt, u16 flags) {
    if (id == 0xFF)
        draw_tile_block(2, 2, x, y, bgcnt, flags + 0x101C);
    else if (id >> 2)
        draw_tile_block(2, 2, x, y, bgcnt, flags + id * 4 + 0x1000);
    else
        draw_tile_block(2, 2, x, y, bgcnt, flags + id * 4);
}

// Previous (backward) or next Medal that is owned (bit 7) and not set in a Medabot (bit 6); 30 if none.
// FAKEMATCH: the backward search is a goto loop (no loop hoisting of 0x80) with two pointer locals for the
// two base copies (r2/r3) the original keeps.
u32 find_next_free_medal(volatile u32 medal, volatile u32 backward) {
    if (backward) {
        if (medal != 0) {
            struct MedalData *medals = gMedals;
            struct MedalData *medals2 = gMedals; // FAKEMATCH: second base copy
        loop:
            medal--;
            if (medals2[medal].flags & 0x80) {
                if (!(medals[medal].flags & 0x40))
                    return medal;
            }
            if (medal != 0)
                goto loop;
        }
    } else {
        do {
            medal++;
            if (medal == 31)
                medal = 0;
            if (medal == 30)
                goto none;
        } while (!(gMedals[medal].flags & 0x80) || (gMedals[medal].flags & 0x40));
        return medal;
    }
none:
    return 30;
}

u32 find_next_available_medapart_slot(vu32 part, vu32 kind, vu32 backward, vu32 gender) {
    if (backward) {
        while (part != 0) {
            part--;
            if (part == 0x78)
                part--;
            load_part_data(part, kind, gGameWork.medalGfxRecord);
            if (gender == gGameWork.medalGfxRecord[3] && gMedapartInventory[kind * 240 + part * 2] != 0 &&
                gMedapartInventory[kind * 240 + part * 2] - gMedapartInventory[kind * 240 + part * 2 + 1] != 0)
                goto found;
        }
    } else {
        while (1) {
            part++;
            if (gender != 0 && part == 0x78)
                part = 0x79;
            if (part == gender + 0x79)
                part = 0;
            if (part == gender + 0x78)
                return gender + 0x78;
            load_part_data(part, kind, gGameWork.medalGfxRecord);
            if (gender == gGameWork.medalGfxRecord[3] && gMedapartInventory[kind * 240 + part * 2] != 0 &&
                gMedapartInventory[kind * 240 + part * 2] - gMedapartInventory[kind * 240 + part * 2 + 1] != 0)
                return part;
        }
    }
    goto fail;
found:
    return part;
fail:
    return gender + 0x78;
}

u32 medabot_detail_is_full_set(void) {
    if (gGameWork.shownHead != gGameWork.shownRightArm)
        return 0;
    if (gGameWork.shownHead != gGameWork.shownLeftArm)
        return 0;
    if (gGameWork.shownHead != gGameWork.shownLegs)
        return 0;
    return 1;
}

u32 validate_medapart_stats(u8 medal, u8 head, u8 rarm, u8 larm, u8 legs) {
    if (medal != 0x1E && head <= 0x77 && rarm <= 0x77 && larm <= 0x77 && legs <= 0x77)
        return 1;
    return 0;
}

// Team slot whose Medabot holds Medal `medal`, or 0xFF.
u32 find_medabot_slot_by_medal(u8 medal) {
    u32 i;
    if (medal >= 0x1E)
        return 0xFF;
    for (i = 0; i < 9; i++)
        if (gTeamSlots[i].state > 1 && gTeamSlots[i].medal == medal)
            return i;
    return 0xFF;
}

void load_battlefield_data_to_buffer(void) {
    memcpy_bytes_08041D04(gUnk_083BEA90[gUnk_030057E0.unk7FE], &gGameWork.partAbility, 1);
    gUnk_030057E0.unkC29 = gGameWork.partAbility;
    gUnk_030057E0.unkC2B = 0;
}

static inline u32 roll_encounter(void) {
    if ((rng_next_byte() & 0x1F) == 0x1F)
        return 1;
    return 0;
}

u32 check_random_encounter(void) {
    u8 n;

    if (gUnk_030057E0.unkC2D != 0)
        return 0;
    if (gUnk_030057E0.unkC5F != 0)
        return 0;
    if (gUnk_030057E0.unkC29 == 0)
        return 0;
    if (gUnk_030057E0.encounters_off & 1)
        return 0;
    n = ++gUnk_030057E0.unkC2B;
    if (n > 0x10 && (n > 0x1F || roll_encounter())) {
        gUnk_030057E0.unkC2B = 0;
        gUnk_030057E0.unkC2E = 0;
        gUnk_030057E0.unkC2F = 0;
        return 1;
    }
    return 0;
}

// Fills next frame's per-scanline BG0-3 scroll table: lines above `lines` get a sine x offset (every 4th
// line recomputed), the rest the plain scroll. scanline_scroll_vblank then feeds it to the BG registers.
void start_scanline_wave_scroll(u32 phase, s32 amplitude, u32 lines) {
    s32 i;
    u32 idx;
    struct Vec16(*buf)[4];

    buf = !(gFrameCounter & 1) ? gUnk_02023200 : gUnk_02023C00;
    for (i = 0; i < 160; i++) {
        if (i < lines) {
            if ((i & 3) == 0) {
                idx = (i + phase) & 0xFF;
                gGameWork.unk86 = (u32)(gJumpArcTable[0][idx] * (amplitude / 512.0f));
            }
            buf[i][0].x = gGameWork.unk86 + (gBg0Scroll.x + gUnk_03002C2C.x);
            buf[i][0].y = gBg0Scroll.y + gUnk_03002C2C.y;
            buf[i][1].x = gGameWork.unk86 + (gBg1Scroll.x + gUnk_03002C2C.x);
            buf[i][1].y = gBg1Scroll.y + gUnk_03002C2C.y;
            buf[i][2].x = gGameWork.unk86 + (gBg2Scroll.x + gUnk_03002C2C.x);
            buf[i][2].y = gBg2Scroll.y + gUnk_03002C2C.y;
            buf[i][3].x = gGameWork.unk86 + (gBg3Scroll.x + gUnk_03002C2C.x);
            buf[i][3].y = gBg3Scroll.y + gUnk_03002C2C.y;
        } else {
            buf[i][0].x = gBg0Scroll.x + gUnk_03002C2C.x;
            buf[i][0].y = gBg0Scroll.y + gUnk_03002C2C.y;
            buf[i][1].x = gBg1Scroll.x + gUnk_03002C2C.x;
            buf[i][1].y = gBg1Scroll.y + gUnk_03002C2C.y;
            buf[i][2].x = gBg2Scroll.x + gUnk_03002C2C.x;
            buf[i][2].y = gBg2Scroll.y + gUnk_03002C2C.y;
            buf[i][3].x = gBg3Scroll.x + gUnk_03002C2C.x;
            buf[i][3].y = gBg3Scroll.y + gUnk_03002C2C.y;
        }
    }
    gVBlankOnceCallback = scanline_scroll_vblank;
}

// Own code (0x78) matches; the .s has a hidden function at 0x08043B58 (0x24 bytes) after the pool.
// Vblank-once callback: line 0 of the double-buffered per-scanline BG0-3 scroll table to BG0HOFS..BG3VOFS,
// then DMA0 (hblank, repeat, 4 words) for the remaining lines.
static void scanline_scroll_vblank(void) {
    vu32 *dma = (vu32 *)REG_ADDR_DMA0;
    u16 *src;

    if (!(gFrameCounter & 1))
        src = (u16 *)gUnk_02023200;
    else
        src = (u16 *)gUnk_02023C00;
    *(vu16 *)0x04000010 = src[0];
    *(vu16 *)0x04000012 = src[1];
    *(vu16 *)0x04000014 = src[2];
    *(vu16 *)0x04000016 = src[3];
    *(vu16 *)0x04000018 = src[4];
    *(vu16 *)0x0400001A = src[5];
    *(vu16 *)0x0400001C = src[6];
    *(vu16 *)0x0400001E = src[7];
    REG_DMA0CNT_H = 0;
    dma[0] = (u32)(src + 8);
    dma[1] = 0x04000010;
    dma[2] = 0xA6600004;
}

// Stops the scanline scroll started by start_scanline_wave_scroll (DMA0 off, no vblank-once callback).
static void stop_scanline_wave_scroll(void) {
    VBlankIntrWait();
    REG_DMA0CNT_H = 0;
    gVBlankOnceCallback = nullsub_08000840;
}

// Tileset idx (4 pointers per entry in gUnk_083B23F8): tiles -> VRAM 0x06008000, BG2 / BG3 tilemaps,
// BG palette -> gPaletteBackupBg (backup != 0) or straight to PLTT.
void decompress_tileset_to_vram(u32 idx, u32 backup) {
    u32 i;

    lz_decompress_dispatch(gUnk_083B23F8[i = idx * 4], (void *)(VRAM + 0x8000));
    set_tilemap_and_decompress_bg(0, 0, gUnk_083B23F8[i + 2], REG_BG2CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gUnk_083B23F8[i + 3], REG_BG3CNT, 0);
    if (backup)
        CpuFastSet(gUnk_083B23F8[i + 1], gPaletteBackupBg, 0x40);
    else
        CpuFastSet(gUnk_083B23F8[i + 1], (void *)PLTT, 0x40);
}

void decompress_sprite_to_vram_08043C08(u32 idx, u32 backup) {
    lz_decompress_dispatch(gUnk_083B24A8[idx * 5], (void *)(VRAM + 0x8000));
    set_tilemap_and_decompress_bg(0, 0, gUnk_083B24A8[idx * 5 + 3], REG_BG2CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gUnk_083B24A8[idx * 5 + 4], REG_BG3CNT, 0);
    if (backup)
        CpuFastSet(gUnk_083B24A8[idx * 5 + 2], gPaletteBackupBg, 0x40);
    else
        CpuFastSet(gUnk_083B24A8[idx * 5 + 2], (void *)PLTT, 0x40);
}

// Random value 0-100.
s32 rng_percent(void) {
    return rng_next_byte() * 100 / 255;
}

void clear_bg_scroll(void) {
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
}

void update_scroll_movement_a(void) {
    vu8 *acc;
    u32 t;

    if (gBattleWork.battlefieldParams[0] == 0)
        return;
    acc = &gBattleWork.battlefieldParams[6];
    *acc = *(vu8 *)&gBattleWork.battlefieldParams[2] + *acc;
    if ((t = *acc >> 2) == 0)
        return;
    gBattleWork.battlefieldParams[7] = t;
    {
        u32 v = *acc;
        register u32 mask asm("r1") = 3; // pinned: the original loads the byte into r0, the mask into r1
        *acc = v & mask;
    }
    if (gBattleWork.battlefieldParams[1] & 1) {
        switch (gBattleWork.battlefieldParams[0]) {
        case 1:
            gBg2Scroll.y += gBattleWork.battlefieldParams[7];
            break;
        case 2:
            gBg3Scroll.y += gBattleWork.battlefieldParams[7];
            break;
        }
    }
    if (gBattleWork.battlefieldParams[1] & 2) {
        switch (gBattleWork.battlefieldParams[0]) {
        case 1:
            gBg2Scroll.y -= gBattleWork.battlefieldParams[7];
            break;
        case 2:
            gBg3Scroll.y -= gBattleWork.battlefieldParams[7];
            break;
        }
    }
    if (gBattleWork.battlefieldParams[1] & 4) {
        switch (gBattleWork.battlefieldParams[0]) {
        case 1:
            gBg2Scroll.x += gBattleWork.battlefieldParams[7];
            break;
        case 2:
            gBg3Scroll.x += gBattleWork.battlefieldParams[7];
            break;
        }
    }
    if (gBattleWork.battlefieldParams[1] & 8) {
        switch (gBattleWork.battlefieldParams[0]) {
        case 1:
            gBg2Scroll.x -= gBattleWork.battlefieldParams[7];
            break;
        case 2:
            gBg3Scroll.x -= gBattleWork.battlefieldParams[7];
            break;
        }
    }
}

void apply_battle_blend_effect_a(void) {
    if (gBattleWork.battlefieldParams[3]) {
        REG_BLDALPHA = (gBattleWork.battlefieldParams[4] << 8) | gBattleWork.battlefieldParams[5];
        REG_BLDY = 0;
        REG_BLDCNT = 0x1844;
    } else
        set_blend_effect_mode(0, 0, 0);
}

// gVBlankCallback of the battle intro and the race: BG2/BG3 scroll movement only.
void battle_bg_scroll_vblank(void) {
    update_scroll_movement_a();
}

void load_battle_script_entry_b(void) {
    memcpy_bytes_0803F63C(gUnk_083C3B5C[gBattleWork.battlefield], gBattleWork.unk74, 8);
}

static void update_scroll_movement_b(void) {
    vu8 *acc;
    u32 t;

    if (gBattleWork.unk74[0] == 0)
        return;
    acc = &gBattleWork.unk74[6];
    *acc = *(vu8 *)&gBattleWork.unk74[2] + *acc;
    if ((t = *acc >> 2) == 0)
        return;
    gBattleWork.unk74[7] = t;
    {
        u32 v = *acc;
        register u32 mask asm("r1") = 3; // pinned: the original loads the byte into r0, the mask into r1
        *acc = v & mask;
    }
    if (gBattleWork.unk74[1] & 1) {
        switch (gBattleWork.unk74[0]) {
        case 1:
            gBg2Scroll.y += gBattleWork.unk74[7];
            break;
        case 2:
            gBg3Scroll.y += gBattleWork.unk74[7];
            break;
        }
    }
    if (gBattleWork.unk74[1] & 2) {
        switch (gBattleWork.unk74[0]) {
        case 1:
            gBg2Scroll.y -= gBattleWork.unk74[7];
            break;
        case 2:
            gBg3Scroll.y -= gBattleWork.unk74[7];
            break;
        }
    }
    if (gBattleWork.unk74[1] & 4) {
        switch (gBattleWork.unk74[0]) {
        case 1:
            gBg2Scroll.x += gBattleWork.unk74[7];
            break;
        case 2:
            gBg3Scroll.x += gBattleWork.unk74[7];
            break;
        }
    }
    if (gBattleWork.unk74[1] & 8) {
        switch (gBattleWork.unk74[0]) {
        case 1:
            gBg2Scroll.x -= gBattleWork.unk74[7];
            break;
        case 2:
            gBg3Scroll.x -= gBattleWork.unk74[7];
            break;
        }
    }
}

void apply_battle_blend_effect_b(void) {
    if (gBattleWork.unk74[3]) {
        REG_BLDALPHA = (gBattleWork.unk74[4] << 8) | gBattleWork.unk74[5];
        REG_BLDY = 0;
        REG_BLDCNT = 0x1844;
    } else
        set_blend_effect_mode(0, 0, 0);
}

void advance_battle_animation_frame(u32 field) {
    if (++gBattleWork.fieldAnimTick > 2) {
        gBattleWork.fieldAnimTick = 0;
        gBattleWork.fieldAnimFrame = (gBattleWork.fieldAnimFrame + 1) & 0x7F;
        memcpy_bytes_08041D04(&gUnk_083C40B8[field], &gBattleWork.fieldAnimTiles, 1);
        memcpy_bytes_08041D04(&gUnk_083C40C3[field * 128 + gBattleWork.fieldAnimFrame], &gBattleWork.fieldAnimBlock, 1);
        if (gBattleWork.fieldAnimBlock == 0xFF) {
            gBattleWork.fieldAnimFrame = 0;
            memcpy_bytes_08041D04(&gUnk_083C40C3[field * 128], &gBattleWork.fieldAnimBlock, 1);
        }
        CpuSet((void *)(0x02027000 + gBattleWork.fieldAnimTiles * gBattleWork.fieldAnimBlock * 32),
               (void *)(VRAM + 0x8020), (gBattleWork.fieldAnimTiles * 8) | 0x04000000);
    }
}

// Back to the field: mode 1, state 1, sub-state 7 (restores the script sprites, then resumes the map).
void return_to_field(void) {
    gGameMode = 1;
    gGameState = 1;
    gGameSubState = 7;
}

// guess: state 3 = Medal and parts set (the Medabots screen and link battles refuse when this is 0 / <= 1).
u32 count_assembled_medabots(void) {
    u32 n = 0;
    u32 i;

    for (i = 0; i < 9; i++)
        if (gTeamSlots[i].state == 3)
            n++;
    return n;
}

// 1 if every Medapart's owned count equals its in-use count (no spare part to trade).
u32 medaparts_all_equipped(void) {
    u32 i;

    for (i = 0; i < 480; i++)
        if (gMedapartInventory[i * 2] != gMedapartInventory[i * 2 + 1])
            return 0;
    return 1;
}

void battle_vblank_update_bg(void) {
    update_scroll_movement_b();
    advance_battle_animation_frame(gBattleWork.battlefield);
}

void read_vram_tilemap_rect(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, void *dst) {
    u32 i, j;
    u16 *d = dst;
    u16 *base = (u16 *)(VRAM + ((bgcnt >> 8) & 0x1F) * 0x800) + x + y * 32;

    for (j = 0; j < h; j++) {
        u16 *p = base + j * 32;
        for (i = 0; i < w; i++)
            *d++ = *p++;
    }
}

void write_vram_tilemap_rect(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, const void *src) {
    u32 i, j;
    const u16 *s = src;
    u16 *base = (u16 *)(VRAM + ((bgcnt >> 8) & 0x1F) * 0x800) + x + y * 32;

    for (j = 0; j < h; j++) {
        u16 *p = base + j * 32;
        for (i = 0; i < w; i++)
            *p++ = *s++;
    }
}

void decompress_to_ewram_27000(const u8 *src) {
    lz_decompress_dispatch(src, (void *)0x02027000);
}

void race_enter_team_select(void) {
    u32 a = 0;
    u32 b;

    CpuFastSet(&a, (void *)OBJ_PLTT, 0x01000080);
    b = 0;
    CpuFastSet(&b, (void *)PLTT, 0x01000080);
    mem_fill8(&gGameWork.medabotsMode, 0x14, 0);
    gGameWork.medabotsMode = 3;
    gBattleWork.teamPicks[0] = 0;
    gBattleWork.teamPicks[1] = 0;
    gBattleWork.teamPicks[2] = 0;
    gGameMode = 0;
    gGameState = 3;
    gGameSubState = 0;
}

// Sprite slot: while unk24 (table, 1-based) is set, add the (x, y) step for frame unk27 & 3 of row unk25
// from gUnk_083C6DF8 to unk4 (wrapped to 0xFF) and unk2 (wrapped to 0x1FF), then advance unk27.
void update_sprite_animation_position(u32 slot) {
    s32 mask = 0x1FF;

    if (gSpriteEntries[slot].unk24 != 0) {
        gSpriteEntries[slot].unk4 =
            (gSpriteEntries[slot].unk4 +
             gUnk_083C6DF8[(gSpriteEntries[slot].unk24 - 1) * 256 + gSpriteEntries[slot].unk25 * 8 +
                           (gSpriteEntries[slot].unk27 & 3) * 2]) &
            0xFF;
        gSpriteEntries[slot].unk2 =
            (gSpriteEntries[slot].unk2 +
             gUnk_083C6DF8[(gSpriteEntries[slot].unk24 - 1) * 256 + gSpriteEntries[slot].unk25 * 8 +
                           (gSpriteEntries[slot].unk27 & 3) * 2 + 1]) &
            mask;
        gSpriteEntries[slot].unk27++;
    }
}

u32 calculate_direction_index(s32 x, s32 y, s32 tx, s32 ty) {
    s32 sx, sy;
    float dx, dy;
    s32 r;

    if (x <= tx) {
        sx = 0;
        dx = tx - x;
    } else {
        sx = 1;
        dx = x - tx;
    }
    if (y <= ty) {
        sy = 0;
        dy = ty - y;
    } else {
        sy = 1;
        dy = y - ty;
    }

    if (sx == 0) {
        if (sy == 0) {
            if (dx == 0)
                return 0x10;
            if (dy == 0)
                return 8;
            if (dx == dy)
                return 0xC;
            if (dx > dy) {
                r = (dx + dy * 0.5f) / dy;
                if (r > 4) {
                    r = (gFrameCounter & 3) ? 4 : 3;
                }
                return 0xC - r;
            } else {
                r = (dy + dx * 0.5f) / dx;
                if (r > 4) {
                    r = (gFrameCounter & 3) ? 4 : 3;
                }
                return r + 0xC;
            }
        } else if (sy == 1) {
            if (dx == 0)
                return 0;
            if (dy == 0)
                return 8;
            if (dx == dy)
                return 4;
            if (dx > dy) {
                r = (dx + dy * 0.5f) / dy;
                if (r > 4) {
                    r = (gFrameCounter & 3) ? 4 : 3;
                }
                return r + 4;
            } else {
                r = (dy + dx * 0.5f) / dx;
                if (r > 4) {
                    r = (gFrameCounter & 3) ? 4 : 3;
                }
                return 4 - r;
            }
        }
    }
    if (sx == 1) {
        if (sy == 1) {
            if (dx == 0)
                return 0;
            if (dy == 0)
                return 0x18;
            if (dx == dy)
                return 0x1C;
            if (dx > dy) {
                r = (dx + dy * 0.5f) / dy;
                if (r > 4) {
                    r = (gFrameCounter & 3) ? 4 : 3;
                }
                return 0x1C - r;
            } else {
                r = (dy + dx * 0.5f) / dx;
                if (r > 4) {
                    r = (gFrameCounter & 3) ? 4 : 3;
                }
                return r + 0x1C;
            }
        } else if (sy == 0) {
            if (dx == 0)
                return 0x10;
            if (dy == 0)
                return 0x18;
            if (dx == dy)
                return 0x14;
            if (dx > dy) {
                r = (dx + dy * 0.5f) / dy;
                if (r > 4) {
                    r = (gFrameCounter & 3) ? 4 : 3;
                }
                return r + 0x14;
            } else {
                r = (dy + dx * 0.5f) / dx;
                if (r > 4) {
                    r = (gFrameCounter & 3) ? 4 : 3;
                }
                return 0x14 - r;
            }
        }
    }
}

void init_scene_buffers_080445F4(void) {
    struct SpriteTree *obj = (struct SpriteTree *)0x02026000;
    u8 *b;
    u8 *c;
    u32 fill;
    u32 fill2;

    mem_fill8((u8 *)obj, 0xD0, 0);
    b = (u8 *)0x020260D0;
    mem_fill8(b, 0x820, 0);
    c = (u8 *)0x020268F0;
    mem_fill8(c, 0x60, 0);
    gUnk_03000430 = 2;
    gSpriteWork = (struct SpriteWork *)0x02024000;
    fill = 0;
    CpuFastSet(&fill, (void *)0x02024000, 0x01000426);
    gUnk_03005308 = (struct SceneSlot *)c;
    fill2 = 0x200;
    CpuFastSet(&fill2, gSpriteWork->oamBuf, 0x01000100);
    gSpriteWork->oamCount = 0;
    gSpriteWork->affineIdx = 0;
    init_sprite_tree(obj, (u8 *)gSpriteWork, (struct SpriteNodeDesc **)gUnk_083D1BF8, (struct SpriteNodeOam *)b);
}

// K&R definitions: the callers were compiled without a prototype (promoted int arguments), and the
// callee narrows its parameters itself. A prototype with u8 / u16 parameters changes the callers.
void setup_scene_with_bg_and_sprites(slot, head, rarm, larm, legs, y, x, f, g, h, i, j) u32 slot;
u8 head, rarm, larm, legs;
u16 y, x;
u32 f;
u8 g, h, i, j;
{
    u32 flags;
    u32 fill;

    switch (f) {
    case 0:
        f = 100;
        break;
    case 1:
        f = 200;
        break;
    case 2:
        f = 300;
        break;
    case 3:
        f = 400;
        break;
    }
    if (h == 0)
        h = 1;
    else
        h = 2;
    flags = 0;
    if (i == 1)
        flags = 4;
    ((struct SpriteTree *)0x02026000)->oams = (struct SpriteNodeOam *)(0x020260D0 + slot * 0x410);
    setup_medabot_part_sprites(gSpriteWork->oamBuf, (struct SpriteTree *)0x02026000, head, rarm, larm, legs, (s16)x,
                               (s16)y, f, g, h | flags, j);
    if (i == 2) {
        fill = 0x200;
        CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
        gSpriteWork->oamCount = 0;
        gSpriteWork->affineIdx = 0;
    }
}

// Draws a Medabot sprite (sprite tree slot `slot`) from its four part ids at (x, y); used by the battle close-ups,
// the status screen and the Medabots screen.
void draw_medabot_sprite(slot, head, rarm, larm, legs, y, x, f, g, h, i, j, base) u32 slot;
u8 head, rarm, larm, legs;
u16 y, x;
u32 f;
u8 g, h, i, j, base;
{
    u32 flags;
    u32 fill;

    switch (f) {
    case 0:
        f = base + 100;
        break;
    case 1:
        f = base + 200;
        break;
    case 2:
        f = base + 300;
        break;
    case 3:
        f = base + 400;
        break;
    }
    if (h == 0)
        h = 1;
    else
        h = 2;
    flags = 0;
    if (i == 1)
        flags = 4;
    ((struct SpriteTree *)0x02026000)->oams = (struct SpriteNodeOam *)(0x020260D0 + slot * 0x410);
    setup_medabot_part_sprites(gSpriteWork->oamBuf, (struct SpriteTree *)0x02026000, head, rarm, larm, legs, (s16)x,
                               (s16)y, f, g, h | flags, j);
    if (i == 2) {
        fill = 0x200;
        CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
        gSpriteWork->oamCount = 0;
        gSpriteWork->affineIdx = 0;
    }
}

void setup_sprite_animation_entry(u32 a, u8 id, u8 kind, u16 y, u16 x, u32 f, u8 g, u8 h, u8 i) {
    u32 flags;
    u32 fill;

    switch (f) {
    case 0:
        f = 100;
        break;
    case 1:
        f = 200;
        break;
    case 2:
        f = 300;
        break;
    case 3:
        f = 400;
        break;
    }
    if (h == 0)
        h = 1;
    else
        h = 2;
    flags = 0;
    if (i == 1)
        flags = 4;
    ((struct SpriteTree *)0x02026000)->oams = (struct SpriteNodeOam *)(0x020260D0 + a * 0x410);
    load_sprite_animation_by_type(gSpriteWork->oamBuf, (struct SpriteTree *)0x02026000, id, kind, (s16)x, (s16)y, f, g,
                                  h | flags);
    if (i == 2) {
        fill = 0x200;
        CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
        gSpriteWork->oamCount = 0;
        gSpriteWork->affineIdx = 0;
    }
}

u32 medabot_pose_anim_step(u32 a0, u32 a1, u32 a2) {
    u32 n;
    u8 *cnt;
    u8 *pos;
    u32 zero;
    s32 done;
    register struct SpriteTree *obj asm("r1"); // pinned: the original loads 0x02026000 before 0x020260CE
    // `done` is deliberately uninitialized: the original reads ip when *pos >= n

    a1 = gUnk_0807E77C[a1][gUnk_083CABF8[a2]];
    n = 0;
    if (gUnk_083D1E98[a1][0] != 0) {
        do {
            n++;
            if (n > 0xFE)
                break;
        } while (gUnk_083D1E98[a1][n] != 0);
    }
    cnt = (u8 *)0x020260CC + a0;
    {
        // (*cnt)++ with the zero set between the add and the store
        u8 c = *cnt + 1;
        zero = 0;
        *cnt = c;
    }
    obj = (struct SpriteTree *)0x02026000;
    pos = (u8 *)0x020260CE + a0;
    if (*pos < n) {
        obj->oams = (struct SpriteNodeOam *)(0x020260D0 + a0 * 0x410);
        done = interpolate_entity_positions((struct InterpEnt *)obj->oams, gUnk_083D1CC0[a1], gUnk_083D1DAC[a1],
                                            gUnk_083D1E98[a1], a1, *cnt, *pos, 0x40, n);
    }
    if (done) {
        if (++(*pos) >= n) {
            *pos = zero;
            *cnt = zero;
            return 1;
        }
        *cnt = zero;
    }
    return 0;
}

void lz_decompress(const u8 *src, void *dst) {
    lz_decompress_dispatch(src, dst);
}

// guess: message sprite set, 0 = the current area's default (gUnk_030057E0.player_form is the area palette id).
u32 resolve_area_sprite_set(u8 set) {
    if (set == 0)
        return gUnk_083B2970[gUnk_030057E0.player_form];
    return set;
}

// Map script: puts the first Medabot in team slot 0 (Medal 0 owned and set, parts 0x2A in use).
void give_starter_medabot(void) {
    gMedals[0].flags |= 0xC0;
    gTeamSlots[0].state = 3;
    gTeamSlots[0].medal = 0;
    gTeamSlots[0].head = 0x2A;
    gTeamSlots[0].rightArm = 0x2A;
    gTeamSlots[0].leftArm = 0x2A;
    gTeamSlots[0].legs = 0x2A;
    gMedapartInventory[0 * 240 + 0x2A * 2 + 1] = 1;
    gMedapartInventory[1 * 240 + 0x2A * 2 + 1] = 1;
    gMedapartInventory[2 * 240 + 0x2A * 2 + 1] = 1;
    gMedapartInventory[3 * 240 + 0x2A * 2 + 1] = 1;
}

void init_battle_scene(u32 mode, u32 id) {
    clear_bg_scroll();
    clear_battle_sprite_slot(0, 0x80);
    gGameWork.unk96 = 0;
    gUnk_03000430 = 0;
    mem_fill8(&gGameWork.openedFrom, 0x14, 0);
    gGameWork.openedFrom = 3;
    gGameWork.shownId = id;
    switch (mode) {
    case 0:
        gGameWork.partSlot = 0;
        break;
    case 1:
        gGameWork.partSlot = mode;
        break;
    case 2:
        gGameWork.partSlot = mode;
        break;
    case 3:
        gGameWork.partSlot = mode;
        break;
    }
    gGameMode = 0;
    gGameState = 5;
    gGameSubState = 0x10;
}

void init_game_mode(u32 mode) {
    clear_bg_scroll();
    mem_fill8(&gGameWork.openedFrom, 0x14, 0);
    mem_fill8(&gGameWork.openedFrom + 0x14, 0x14, 0);
    gGameWork.skipBotSetup = 1;
    gGameWork.rngIndex = 0;
    switch (mode) {
    case 0:
        gGameWork.openedFrom = 4;
        gGameMode = 0;
        gGameState = 4;
        gGameSubState = 0;
        break;
    case 1:
        gGameWork.openedFrom = 4;
        gGameMode = 0;
        gGameState = 5;
        gGameSubState = 0;
        break;
    case 2:
        gGameWork.prizeGamePending = 0;
        gGameMode = 0;
        gGameState = 10;
        gGameSubState = 0;
        break;
    case 3:
        gGameWork.prizeGamePending = 1;
        gGameMode = 0;
        gGameState = 10;
        gGameSubState = 0;
        break;
    }
}
