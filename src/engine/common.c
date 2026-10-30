// Shared helpers used by menus and battles, one unit with no clear inner boundary (call-crossing scores
// stay at 2-16): a second RNG, BG blend effects, number and tilemap drawing, polar coordinates, the
// battle Medabot sprite groups, Medapart slot searches, the random encounter check, scroll / blend
// effects of the battle field, tilemap rect copies, scene setup and init_game_mode.

#include "global.h"
#include "constants/sprites.h"

static void scanline_scroll_vblank(void);

// Second RNG (0-255): mixes the frame counter into a 16-bit state, or replays gReplayRandomBytes when skipBotSetup is
// set.
s32 rng_next_byte(void) {
    if (gGameWork.skipBotSetup == 0) {
        u16 state = gGameWork.rngSeed + gGameWork.rngLast;

        state += 0x87 + (((gFrameCounter << 4) + (gFrameCounter >> 4) + 1) >> 1);
        gGameWork.rngSeed = ((state & 0xFF) << 8) | (((state & 0xFF00) >> 8) ^ (state & 0xFF));
        gGameWork.rngLast = ((state & 0xFF00) >> 8) ^ state;
        return gGameWork.rngLast;
    } else {
        gGameWork.rngIndex++;
        gGameWork.rngLast = gReplayRandomBytes[gGameWork.rngIndex];
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
    u16 *base = BG_TILEMAP(bgcnt) + x + y * 32;

    for (j = 0; j < h; j++) {
        u16 *dst = base + j * 32;
        for (i = 0; i < w; i++)
            *dst++ = entry++;
    }
}

void fill_tilemap_pair_or_divide(u8 value, u8 x, u8 y, u32 bgcnt, u16 tile) {
    u8 digits[3];
    u8 remainder;

    if (value == 0xFF) {
        draw_tile_block(1, 2, x, y, bgcnt, tile + 0x18);
        draw_tile_block(1, 2, x + 1, y, bgcnt, tile + 0x18);
    } else {
        digits[0] = value / 100;
        remainder = value - (u8)(value / 100) * 100;
        digits[1] = remainder / 10;
        digits[2] = remainder - (u8)(remainder / 10) * 10;
        if (digits[0] != 0) {
            draw_tile_block(1, 2, x, y, bgcnt, tile + 0x14);
            draw_tile_block(1, 2, x + 1, y, bgcnt, tile + 0x16);
        } else if (digits[1] != 0) {
            draw_tile_block(1, 2, x, y, bgcnt, tile + digits[1] * 2);
            draw_tile_block(1, 2, x + 1, y, bgcnt, tile + digits[2] * 2);
        } else {
            vram_fill_tilemap_rect(1, 2, x, y, bgcnt, 0);
            draw_tile_block(1, 2, x + 1, y, bgcnt, tile + digits[2] * 2);
        }
    }
}

// Draws the last `digits` decimal digits of n as tiles (tile + digit); leading zeros blank, the last digit always.
void draw_number_bgcnt(u32 n, u32 x, u32 y, u32 digits, u32 bgcnt, u32 tile) {
    u8 digit_buf[6];
    u32 remainder;
    u32 i;
    u8 start, started;
    u16 *dst;
    u8 count = digits;
    u16 base_tile = tile;

    digit_buf[0] = n / 100000;
    remainder = n - n / 100000 * 100000;
    digit_buf[1] = remainder / 10000;
    remainder = remainder - n / 10000 * 10000;
    digit_buf[2] = remainder / 1000;
    remainder = remainder - remainder / 1000 * 1000;
    digit_buf[3] = remainder / 100;
    remainder = remainder - remainder / 100 * 100;
    digit_buf[4] = remainder / 10;
    remainder = remainder - remainder / 10 * 10;
    digit_buf[5] = remainder;

    start = 6 - count;
    started = 0;
    dst = BG_TILEMAP(bgcnt) + x + y * 32;
    for (i = start; i <= 5; i++) {
        if (i <= 4) {
            if (digit_buf[i] == 0) {
                if (started)
                    *dst++ = base_tile + digit_buf[i];
                else
                    *dst++ = 0;
            } else {
                *dst++ = base_tile + digit_buf[i];
                started = 1;
            }
        } else {
            *dst++ = base_tile + digit_buf[i];
        }
    }
}

static inline u32 lower_digit_tile(s16 base, u32 digit) {
    return base + 1 + digit * 2;
}

// draw_number_bgcnt with 2-row digits: top tile base + digit * 2, bottom tile one row below.
void draw_number_tall_bgcnt(u32 value, u32 x, u32 y, u8 digits, u32 bgcnt, u16 base) {
    u8 digit_buf[6];
    u32 rem;
    u32 i;
    u8 start;
    u32 flag;
    vu16 *dst;

    digit_buf[0] = value / 100000;
    rem = value - value / 100000 * 100000;
    digit_buf[1] = rem / 10000;
    rem -= value / 10000 * 10000;
    digit_buf[2] = rem / 1000;
    rem -= rem / 1000 * 1000;
    digit_buf[3] = rem / 100;
    rem -= rem / 100 * 100;
    digit_buf[4] = rem / 10;
    rem -= rem / 10 * 10;
    digit_buf[5] = rem;

    start = 6 - digits;
    flag = 0;
    dst = (vu16 *)(VRAM + BGCNT_SCREEN_OFFSET(bgcnt)) + x + y * 32;
    for (i = start; i < 6; i++) {
        if (i <= 4) {
            if (digit_buf[i] == 0) {
                if (flag) {
                    *dst = base + digit_buf[i] * 2;
                    dst[32] = lower_digit_tile(base, digit_buf[i]);
                    *dst++;
                } else {
                    *dst = 0;
                    dst[32] = 0;
                    *dst++;
                }
            } else {
                *dst = base + digit_buf[i] * 2;
                dst[32] = lower_digit_tile(base, digit_buf[i]);
                *dst++;
                flag = 1;
            }
        } else {
            *dst = base + digit_buf[i] * 2;
            dst[32] = lower_digit_tile(base, digit_buf[i]);
            *dst++;
        }
    }
}

// "cur<tile>max" with 1-2 digits each (a leading 0 is skipped).
void draw_count_over_max(u32 cur, u32 max, u32 x, u32 y, u32 tile, u32 bgcnt, u16 tile2) {
    u8 cur_digits[2];
    u8 max_digits[2];
    u16 *dst;
    u32 i;
    u32 digit;
    u8 *max_ptr;
    u8 *cur_ptr;

    cur_ptr = cur_digits;
    digit = cur / 10;
    cur_ptr[0] = digit;
    digit = cur - digit * 10;
    cur_digits[1] = digit;
    max_ptr = max_digits;
    digit = max / 10;
    max_ptr[0] = digit;
    digit = max - digit * 10;
    max_ptr[1] = digit;
    dst = (u16 *)(VRAM + BGCNT_SCREEN_OFFSET(bgcnt) + x * 2) + y * 32;
    for (i = 0; i < 2; i++) {
        if (cur_digits[i] == 0) {
            if (i == 1)
                *dst++ = tile2 + cur_digits[i];
        } else
            *dst++ = tile2 + cur_digits[i];
    }
    *dst++ = tile;
    for (i = 0; i < 2; i++) {
        if (max_digits[i] == 0) {
            if (i == 1)
                *dst++ = tile2 + max_digits[i];
        } else
            *dst++ = tile2 + max_digits[i];
    }
}

void load_part_data(u32 part, u32 kind, u8 *dst) {
    u32 i;
    u8 *out = dst;
    for (i = 0; i < 16; i++)
        *out++ = gMedapartData[part * 64 + kind * 16 + i];
}

// Skill types 0, 1, 4, 5 are proximity, 2, 3, 6, 7 remote (gMenuMessages messages 17 / 18: "Proximity
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
    struct Coords16 result;

    x += (u32)(gCosTableQ8[angle] * (radius / 256.0f));
    y += (u32)(gJumpArcTable[0][angle] * (radius / 256.0f));
    result.x = x & 0x1FF;
    result.y = y & 0xFF;
    return result;
}

struct Vec16 compute_polar_to_screen_position(u32 angle, u32 radius, u32 cx, u32 cy, u32 inset_y, u32 inset_x) {
    struct Vec16 result;

    if (radius < inset_y)
        inset_y = radius;
    if (radius < inset_x)
        inset_x = radius;
    cx += (u32)(gCosTableQ8[angle] * ((radius - inset_x) / 256.0f));
    cy += (u32)(gJumpArcTable[0][angle] * ((radius - inset_y) / 256.0f));
    result.x = cx & 0x1FF;
    result.y = cy & 0xFF;
    return result;
}

// Decompresses 6 sprite tile chunks (0x80 bytes each in VRAM) into OBJ tile slot `slot` (0x400 bytes):
// chunk 0 from part id head, 1-2 from right_arm, 3-4 from left_arm, 5 from legs (gMedabotPartSpriteTiles has 6
// pointers per Medabot).
// The index is written as (n << 2) + (n << 1): `n * 6` compiles to (n * 3) << 1.
void load_medabot_part_tiles(u32 head, u32 right_arm, u32 left_arm, u32 legs, u32 slot) {
    lz_decompress_dispatch(gMedabotPartSpriteTiles[(head << 2) + (head << 1)], (void *)(VRAM + 0x10000 + slot * 0x400));
    lz_decompress_dispatch(gMedabotPartSpriteTiles[(right_arm << 2) + (right_arm << 1) + 1],
                           (void *)(VRAM + 0x10000 + 0x80 + slot * 0x400));
    lz_decompress_dispatch(gMedabotPartSpriteTiles[(right_arm << 2) + (right_arm << 1) + 2],
                           (void *)(VRAM + 0x10000 + 0x100 + slot * 0x400));
    lz_decompress_dispatch(gMedabotPartSpriteTiles[(left_arm << 2) + (left_arm << 1) + 3],
                           (void *)(VRAM + 0x10000 + 0x180 + slot * 0x400));
    lz_decompress_dispatch(gMedabotPartSpriteTiles[(left_arm << 2) + (left_arm << 1) + 4],
                           (void *)(VRAM + 0x10000 + 0x200 + slot * 0x400));
    lz_decompress_dispatch(gMedabotPartSpriteTiles[(legs << 2) + (legs << 1) + 5],
                           (void *)(VRAM + 0x10000 + 0x280 + slot * 0x400));
}

void init_battle_medabot_sprites(u32 head, u32 rarm, u32 larm, u32 legs, u32 tile, u32 sprite, u32 x, u32 y, u32 flip,
                                 u32 prio, u32 pal) {
    clear_battle_sprite_slot(sprite, 4);
    gSpriteEntries[sprite].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE | SPRITE_PRIORITY(prio);
    if (flip)
        gSpriteEntries[sprite].flags |= SPRITE_FLAG_HFLIP;
    else
        gSpriteEntries[sprite].flags &= (u16)~SPRITE_FLAG_HFLIP;
    gSpriteEntries[sprite].x = x;
    gSpriteEntries[sprite].y = y - 4;
    gSpriteEntries[sprite].frame = tile * 8 + 0x500;
    gSpriteEntries[sprite].palette = gMedabotSpritePalettes[head];
    gSpriteEntries[sprite].frame_table = 0;
    gSpriteEntries[sprite].order = pal + 2;

    gSpriteEntries[sprite + 1].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE | (prio << 10);
    if (flip) {
        gSpriteEntries[sprite + 1].flags |= SPRITE_FLAG_HFLIP;
        gSpriteEntries[sprite + 1].frame = tile * 8 + 0x502;
        gSpriteEntries[sprite + 1].order = pal;
    } else {
        gSpriteEntries[sprite + 1].flags &= (u16)~SPRITE_FLAG_HFLIP;
        gSpriteEntries[sprite + 1].frame = tile * 8 + 0x501;
        gSpriteEntries[sprite + 1].order = pal + 3;
    }
    gSpriteEntries[sprite + 1].x = x - 8;
    gSpriteEntries[sprite + 1].y = y + 4;
    gSpriteEntries[sprite + 1].palette = gMedabotSpritePalettes[rarm];
    gSpriteEntries[sprite + 1].frame_table = 0;
    gSpriteEntries[sprite + 1].scale_x = 0x40;
    gSpriteEntries[sprite + 1].scale_y = 0x40;
    gSpriteEntries[sprite + 1].angle = 0;

    gSpriteEntries[sprite + 2].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE | (prio << 10);
    if (flip) {
        gSpriteEntries[sprite + 2].flags |= SPRITE_FLAG_HFLIP;
        gSpriteEntries[sprite + 2].frame = tile * 8 + 0x503;
        gSpriteEntries[sprite + 2].order = pal + 3;
    } else {
        gSpriteEntries[sprite + 2].flags &= (u16)~SPRITE_FLAG_HFLIP;
        gSpriteEntries[sprite + 2].frame = tile * 8 + 0x504;
        gSpriteEntries[sprite + 2].order = pal;
    }
    gSpriteEntries[sprite + 2].x = x + 8;
    gSpriteEntries[sprite + 2].y = y + 4;
    gSpriteEntries[sprite + 2].palette = gMedabotSpritePalettes[larm];
    gSpriteEntries[sprite + 2].frame_table = 0;
    gSpriteEntries[sprite + 2].scale_x = 0x40;
    gSpriteEntries[sprite + 2].scale_y = 0x40;
    gSpriteEntries[sprite + 2].angle = 0;

    gSpriteEntries[sprite + 3].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE | (prio << 10);
    if (flip)
        gSpriteEntries[sprite + 3].flags |= SPRITE_FLAG_HFLIP;
    else
        gSpriteEntries[sprite + 3].flags &= (u16)~SPRITE_FLAG_HFLIP;
    gSpriteEntries[sprite + 3].x = x;
    gSpriteEntries[sprite + 3].y = y + 4;
    gSpriteEntries[sprite + 3].frame = tile * 8 + 0x505;
    gSpriteEntries[sprite + 3].palette = gMedabotSpritePalettes[legs];
    gSpriteEntries[sprite + 3].frame_table = 0;
    gSpriteEntries[sprite + 3].order = pal + 1;
}

void setup_battle_sprite_group(u32 head, u32 rarm, u32 larm, u32 legs, u32 tile, u32 sprite, u32 x, u32 y, u32 flip,
                               u32 prio, u32 pal) {
    gSpriteEntries[sprite].flags |= SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE | (prio << 10);
    if (flip)
        gSpriteEntries[sprite].flags |= SPRITE_FLAG_HFLIP;
    else
        gSpriteEntries[sprite].flags &= (u16)~SPRITE_FLAG_HFLIP;
    gSpriteEntries[sprite].x = x;
    gSpriteEntries[sprite].y = y - 4;
    gSpriteEntries[sprite].frame = tile * 8 + 0x500;
    gSpriteEntries[sprite].palette = gMedabotSpritePalettes[head];
    gSpriteEntries[sprite].frame_table = 0;
    gSpriteEntries[sprite].order = pal + 2;

    gSpriteEntries[sprite + 1].flags |=
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE | (prio << 10);
    if (flip) {
        gSpriteEntries[sprite + 1].flags |= SPRITE_FLAG_HFLIP;
        gSpriteEntries[sprite + 1].frame = tile * 8 + 0x502;
        gSpriteEntries[sprite + 1].order = pal;
    } else {
        gSpriteEntries[sprite + 1].flags &= (u16)~SPRITE_FLAG_HFLIP;
        gSpriteEntries[sprite + 1].frame = tile * 8 + 0x501;
        gSpriteEntries[sprite + 1].order = pal + 3;
    }
    gSpriteEntries[sprite + 1].x = x - 8;
    gSpriteEntries[sprite + 1].y = y + 4;
    gSpriteEntries[sprite + 1].palette = gMedabotSpritePalettes[rarm];
    gSpriteEntries[sprite + 1].frame_table = 0;

    gSpriteEntries[sprite + 2].flags |=
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE | (prio << 10);
    if (flip) {
        gSpriteEntries[sprite + 2].flags |= SPRITE_FLAG_HFLIP;
        gSpriteEntries[sprite + 2].frame = tile * 8 + 0x503;
        gSpriteEntries[sprite + 2].order = pal + 3;
    } else {
        gSpriteEntries[sprite + 2].flags &= (u16)~SPRITE_FLAG_HFLIP;
        gSpriteEntries[sprite + 2].frame = tile * 8 + 0x504;
        gSpriteEntries[sprite + 2].order = pal;
    }
    gSpriteEntries[sprite + 2].x = x + 8;
    gSpriteEntries[sprite + 2].y = y + 4;
    gSpriteEntries[sprite + 2].palette = gMedabotSpritePalettes[larm];
    gSpriteEntries[sprite + 2].frame_table = 0;

    gSpriteEntries[sprite + 3].flags |=
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE | (prio << 10);
    if (flip)
        gSpriteEntries[sprite + 3].flags |= SPRITE_FLAG_HFLIP;
    else
        gSpriteEntries[sprite + 3].flags &= (u16)~SPRITE_FLAG_HFLIP;
    gSpriteEntries[sprite + 3].x = x;
    gSpriteEntries[sprite + 3].y = y + 4;
    gSpriteEntries[sprite + 3].frame = tile * 8 + 0x505;
    gSpriteEntries[sprite + 3].palette = gMedabotSpritePalettes[legs];
    gSpriteEntries[sprite + 3].frame_table = 0;
    gSpriteEntries[sprite + 3].order = pal + 1;
}

void battle_sprite_group_set_anim(u32 sprite, u32 anim) {
    u32 i;

    gSpriteEntries[sprite + 1].flags |= SPRITE_FLAG_AFFINE;
    gSpriteEntries[sprite + 2].flags |= SPRITE_FLAG_AFFINE;
    for (i = 0; i < 16; i++)
        ;
    gSpriteEntries[sprite].work[SPR_WALK_SPEED] = anim;
    gSpriteEntries[sprite + 1].work[SPR_WALK_SPEED] = anim;
    gSpriteEntries[sprite + 2].work[SPR_WALK_SPEED] = anim;
    gSpriteEntries[sprite + 3].work[SPR_WALK_SPEED] = anim;
}

void update_battle_sprite_orbiting_positions(u32 sprite, u32 idx, u32 unused) {
    struct Coords16 pos;
    u32 phase;
    u8 progress;

    gSpriteEntries[sprite].x = gSpriteEntries[sprite + 3].x;
    gSpriteEntries[sprite + 3].work[SPR_WALK_PHASE] += gSpriteEntries[sprite + 3].work[SPR_WALK_SPEED];
    if (gSpriteEntries[sprite + 3].work[SPR_WALK_PHASE] > 0x3F) {
        gSpriteEntries[sprite + 3].work[SPR_WALK_PHASE] -= 0x40;
        gSpriteEntries[sprite + 3].work[SPR_WALK_STEP] = (gSpriteEntries[sprite + 3].work[SPR_WALK_STEP] + 1) & 3;
        gSpriteEntries[sprite + 3].frame =
            idx * 8 + 0x505 + gLegWalkFrames[gSpriteEntries[sprite + 3].work[SPR_WALK_STEP]];
    }

    gSpriteEntries[sprite + 1].work[SPR_WALK_PHASE] += gSpriteEntries[sprite + 1].work[SPR_WALK_SPEED];
    progress = gSpriteEntries[sprite + 1].work[SPR_WALK_PHASE];
    phase = progress >> 1;
    if (progress > 0x3F) {
        phase = 0x20;
        gSpriteEntries[sprite + 1].work[SPR_WALK_PHASE] -= 0x40;
    }
    switch (gSpriteEntries[sprite + 1].work[SPR_WALK_STEP]) {
    case 0:
        gSpriteEntries[sprite + 1].angle = phase * 4;
        pos = calc_polar_to_screen_coords(phase + 0x60, 5, gSpriteEntries[sprite + 3].x, gSpriteEntries[sprite + 3].y);
        gSpriteEntries[sprite + 1].x = pos.x - 5;
        gSpriteEntries[sprite + 1].y = pos.y - 3;
        break;
    case 1:
        gSpriteEntries[sprite + 1].angle = 0x80 - phase * 4;
        pos = calc_polar_to_screen_coords(0x80 - phase, 5, gSpriteEntries[sprite + 3].x, gSpriteEntries[sprite + 3].y);
        gSpriteEntries[sprite + 1].x = pos.x - 5;
        gSpriteEntries[sprite + 1].y = pos.y - 3;
        break;
    case 2:
        gSpriteEntries[sprite + 1].angle = 0x400 - phase * 4;
        pos = calc_polar_to_screen_coords(0x60 - phase, 5, gSpriteEntries[sprite + 3].x, gSpriteEntries[sprite + 3].y);
        gSpriteEntries[sprite + 1].x = pos.x - 5;
        gSpriteEntries[sprite + 1].y = pos.y - 3;
        break;
    case 3:
        gSpriteEntries[sprite + 1].angle = phase * 4 + 0x380;
        pos = calc_polar_to_screen_coords(phase + 0x40, 5, gSpriteEntries[sprite + 3].x, gSpriteEntries[sprite + 3].y);
        gSpriteEntries[sprite + 1].x = pos.x - 5;
        gSpriteEntries[sprite + 1].y = pos.y - 3;
        break;
    }
    if (phase == 0x20)
        gSpriteEntries[sprite + 1].work[SPR_WALK_STEP] = (gSpriteEntries[sprite + 1].work[SPR_WALK_STEP] + 1) & 3;

    gSpriteEntries[sprite + 2].work[SPR_WALK_PHASE] += gSpriteEntries[sprite + 2].work[SPR_WALK_SPEED];
    progress = gSpriteEntries[sprite + 2].work[SPR_WALK_PHASE];
    phase = progress >> 1;
    if (progress > 0x3F) {
        phase = 0x20;
        gSpriteEntries[sprite + 2].work[SPR_WALK_PHASE] -= 0x40;
    }
    switch (gSpriteEntries[sprite + 2].work[SPR_WALK_STEP]) {
    case 2:
        gSpriteEntries[sprite + 2].angle = phase * 4;
        pos = calc_polar_to_screen_coords(phase + 0x20, 5, gSpriteEntries[sprite + 3].x, gSpriteEntries[sprite + 3].y);
        gSpriteEntries[sprite + 2].x = pos.x + 5;
        gSpriteEntries[sprite + 2].y = pos.y - 3;
        break;
    case 3:
        gSpriteEntries[sprite + 2].angle = 0x80 - phase * 4;
        pos = calc_polar_to_screen_coords(0x40 - phase, 5, gSpriteEntries[sprite + 3].x, gSpriteEntries[sprite + 3].y);
        gSpriteEntries[sprite + 2].x = pos.x + 5;
        gSpriteEntries[sprite + 2].y = pos.y - 3;
        break;
    case 0:
        gSpriteEntries[sprite + 2].angle = 0x400 - phase * 4;
        pos = calc_polar_to_screen_coords(0x20 - phase, 5, gSpriteEntries[sprite + 3].x, gSpriteEntries[sprite + 3].y);
        gSpriteEntries[sprite + 2].x = pos.x + 5;
        gSpriteEntries[sprite + 2].y = pos.y - 3;
        break;
    case 1:
        gSpriteEntries[sprite + 2].angle = phase * 4 + 0x380;
        pos = calc_polar_to_screen_coords(phase, 5, gSpriteEntries[sprite + 3].x, gSpriteEntries[sprite + 3].y);
        gSpriteEntries[sprite + 2].x = pos.x + 5;
        gSpriteEntries[sprite + 2].y = pos.y - 3;
        break;
    }
    if (phase == 0x20)
        gSpriteEntries[sprite + 2].work[SPR_WALK_STEP] = (gSpriteEntries[sprite + 2].work[SPR_WALK_STEP] + 1) & 3;

    if (gLegWalkFrames[gSpriteEntries[sprite + 3].work[SPR_WALK_STEP]]) {
        gSpriteEntries[sprite].y = gSpriteEntries[sprite + 3].y - 7;
        gSpriteEntries[sprite + 1].y++;
        gSpriteEntries[sprite + 2].y++;
    } else {
        gSpriteEntries[sprite].y = gSpriteEntries[sprite + 3].y - 8;
    }
}

void modify_medapart_quantity(u32 id, u32 kind, u32 byte, u32 subtract, u32 n) {
    if (subtract) {
        gMedapartInventory[kind * 240 + id * 2 + byte] -= n;
    } else {
        u8 *inv = gMedapartInventory;
        u8 *qty_ptr = &inv[kind * 240 + id * 2 + byte];
        u32 qty = *qty_ptr + n;

        if (qty > 99)
            qty = 99;
        *qty_ptr = qty;
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

void area_load_encounter_rate(void) {
    copy_bytes_short(gAreaBattleSettings[gFieldWork.area_id], &gGameWork.partAbility, 1);
    gFieldWork.encounter_rate = gGameWork.partAbility;
    gFieldWork.encounter_steps = 0;
}

static inline u32 roll_encounter(void) {
    if ((rng_next_byte() & 0x1F) == 0x1F)
        return 1;
    return 0;
}

u32 check_random_encounter(void) {
    u8 n;

    if (gFieldWork.fixed_battle != 0)
        return 0;
    if (gFieldWork.script_field_update != 0)
        return 0;
    if (gFieldWork.encounter_rate == 0)
        return 0;
    if (gFieldWork.encounters_off & 1)
        return 0;
    n = ++gFieldWork.encounter_steps;
    if (n > 0x10 && (n > 0x1F || roll_encounter())) {
        gFieldWork.encounter_steps = 0;
        gFieldWork.battle_flags = 0;
        gFieldWork.story_battle = 0;
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

    buf = !(gFrameCounter & 1) ? gScanlineScrollEven : gScanlineScrollOdd;
    for (i = 0; i < 160; i++) {
        if (i < lines) {
            if ((i & 3) == 0) {
                idx = (i + phase) & 0xFF;
                gGameWork.stepTimer = (u32)(gJumpArcTable[0][idx] * (amplitude / 512.0f));
            }
            buf[i][0].x = gGameWork.stepTimer + (gBg0Scroll.x + gBgScrollOffset.x);
            buf[i][0].y = gBg0Scroll.y + gBgScrollOffset.y;
            buf[i][1].x = gGameWork.stepTimer + (gBg1Scroll.x + gBgScrollOffset.x);
            buf[i][1].y = gBg1Scroll.y + gBgScrollOffset.y;
            buf[i][2].x = gGameWork.stepTimer + (gBg2Scroll.x + gBgScrollOffset.x);
            buf[i][2].y = gBg2Scroll.y + gBgScrollOffset.y;
            buf[i][3].x = gGameWork.stepTimer + (gBg3Scroll.x + gBgScrollOffset.x);
            buf[i][3].y = gBg3Scroll.y + gBgScrollOffset.y;
        } else {
            buf[i][0].x = gBg0Scroll.x + gBgScrollOffset.x;
            buf[i][0].y = gBg0Scroll.y + gBgScrollOffset.y;
            buf[i][1].x = gBg1Scroll.x + gBgScrollOffset.x;
            buf[i][1].y = gBg1Scroll.y + gBgScrollOffset.y;
            buf[i][2].x = gBg2Scroll.x + gBgScrollOffset.x;
            buf[i][2].y = gBg2Scroll.y + gBgScrollOffset.y;
            buf[i][3].x = gBg3Scroll.x + gBgScrollOffset.x;
            buf[i][3].y = gBg3Scroll.y + gBgScrollOffset.y;
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
        src = (u16 *)gScanlineScrollEven;
    else
        src = (u16 *)gScanlineScrollOdd;
    REG_BG0HOFS = src[0];
    REG_BG0VOFS = src[1];
    REG_BG1HOFS = src[2];
    REG_BG1VOFS = src[3];
    REG_BG2HOFS = src[4];
    REG_BG2VOFS = src[5];
    REG_BG3HOFS = src[6];
    REG_BG3VOFS = src[7];
    REG_DMA0CNT_H = 0;
    dma[0] = (u32)(src + 8);
    dma[1] = REG_ADDR_BG0HOFS;
    dma[2] = 0xA6600004;
}

// Stops the scanline scroll started by start_scanline_wave_scroll (DMA0 off, no vblank-once callback).
static void stop_scanline_wave_scroll(void) {
    VBlankIntrWait();
    REG_DMA0CNT_H = 0;
    gVBlankOnceCallback = empty_callback;
}

// Tileset idx (4 pointers per entry in gBattlefieldTilesets): tiles -> VRAM 0x06008000, BG2 / BG3 tilemaps,
// BG palette -> gPaletteBackupBg (backup != 0) or straight to PLTT.
void decompress_tileset_to_vram(u32 idx, u32 backup) {
    u32 i;

    lz_decompress_dispatch(gBattlefieldTilesets[i = idx * 4], (void *)(VRAM + 0x8000));
    set_tilemap_and_decompress_bg(0, 0, gBattlefieldTilesets[i + 2], REG_BG2CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gBattlefieldTilesets[i + 3], REG_BG3CNT, 0);
    if (backup)
        CpuFastSet(gBattlefieldTilesets[i + 1], gPaletteBackupBg, 0x40);
    else
        CpuFastSet(gBattlefieldTilesets[i + 1], (void *)PLTT, 0x40);
}

void load_battlefield_graphics(u32 idx, u32 backup) {
    lz_decompress_dispatch(gBattlefieldGraphics[idx * 5], (void *)(VRAM + 0x8000));
    set_tilemap_and_decompress_bg(0, 0, gBattlefieldGraphics[idx * 5 + 3], REG_BG2CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gBattlefieldGraphics[idx * 5 + 4], REG_BG3CNT, 0);
    if (backup)
        CpuFastSet(gBattlefieldGraphics[idx * 5 + 2], gPaletteBackupBg, 0x40);
    else
        CpuFastSet(gBattlefieldGraphics[idx * 5 + 2], (void *)PLTT, 0x40);
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
    u32 step;

    if (gBattleWork.battlefieldParams[0] == 0)
        return;
    acc = &gBattleWork.battlefieldParams[6];
    *acc = *(vu8 *)&gBattleWork.battlefieldParams[2] + *acc;
    if ((step = *acc >> 2) == 0)
        return;
    gBattleWork.battlefieldParams[7] = step;
    {
        u32 acc_val = *acc;
        register u32 mask asm("r1") = 3; // pinned: the original loads the byte into r0, the mask into r1
        *acc = acc_val & mask;
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
    copy_bytes(gBattlefieldEffectParams[gBattleWork.battlefield], gBattleWork.battlefieldEffect, 8);
}

static void update_scroll_movement_b(void) {
    vu8 *acc;
    u32 step;

    if (gBattleWork.battlefieldEffect[0] == 0)
        return;
    acc = &gBattleWork.battlefieldEffect[6];
    *acc = *(vu8 *)&gBattleWork.battlefieldEffect[2] + *acc;
    if ((step = *acc >> 2) == 0)
        return;
    gBattleWork.battlefieldEffect[7] = step;
    {
        u32 acc_val = *acc;
        register u32 mask asm("r1") = 3; // pinned: the original loads the byte into r0, the mask into r1
        *acc = acc_val & mask;
    }
    if (gBattleWork.battlefieldEffect[1] & 1) {
        switch (gBattleWork.battlefieldEffect[0]) {
        case 1:
            gBg2Scroll.y += gBattleWork.battlefieldEffect[7];
            break;
        case 2:
            gBg3Scroll.y += gBattleWork.battlefieldEffect[7];
            break;
        }
    }
    if (gBattleWork.battlefieldEffect[1] & 2) {
        switch (gBattleWork.battlefieldEffect[0]) {
        case 1:
            gBg2Scroll.y -= gBattleWork.battlefieldEffect[7];
            break;
        case 2:
            gBg3Scroll.y -= gBattleWork.battlefieldEffect[7];
            break;
        }
    }
    if (gBattleWork.battlefieldEffect[1] & 4) {
        switch (gBattleWork.battlefieldEffect[0]) {
        case 1:
            gBg2Scroll.x += gBattleWork.battlefieldEffect[7];
            break;
        case 2:
            gBg3Scroll.x += gBattleWork.battlefieldEffect[7];
            break;
        }
    }
    if (gBattleWork.battlefieldEffect[1] & 8) {
        switch (gBattleWork.battlefieldEffect[0]) {
        case 1:
            gBg2Scroll.x -= gBattleWork.battlefieldEffect[7];
            break;
        case 2:
            gBg3Scroll.x -= gBattleWork.battlefieldEffect[7];
            break;
        }
    }
}

void apply_battle_blend_effect_b(void) {
    if (gBattleWork.battlefieldEffect[3]) {
        REG_BLDALPHA = (gBattleWork.battlefieldEffect[4] << 8) | gBattleWork.battlefieldEffect[5];
        REG_BLDY = 0;
        REG_BLDCNT = 0x1844;
    } else
        set_blend_effect_mode(0, 0, 0);
}

void advance_battle_animation_frame(u32 field) {
    if (++gBattleWork.fieldAnimTick > 2) {
        gBattleWork.fieldAnimTick = 0;
        gBattleWork.fieldAnimFrame = (gBattleWork.fieldAnimFrame + 1) & 0x7F;
        copy_bytes_short(&gBattlefieldAnimTileCounts[field], &gBattleWork.fieldAnimTiles, 1);
        copy_bytes_short(&gBattlefieldAnimFrames[field * 128 + gBattleWork.fieldAnimFrame], &gBattleWork.fieldAnimBlock,
                         1);
        if (gBattleWork.fieldAnimBlock == 0xFF) {
            gBattleWork.fieldAnimFrame = 0;
            copy_bytes_short(&gBattlefieldAnimFrames[field * 128], &gBattleWork.fieldAnimBlock, 1);
        }
        CpuSet((void *)(BATTLEFIELD_ANIM_TILES_ADDR + gBattleWork.fieldAnimTiles * gBattleWork.fieldAnimBlock * 32),
               (void *)(VRAM + 0x8020), (gBattleWork.fieldAnimTiles * 8) | CPU_SET_32BIT);
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
    u16 *out = dst;
    u16 *base = BG_TILEMAP(bgcnt) + x + y * 32;

    for (j = 0; j < h; j++) {
        u16 *vram = base + j * 32;
        for (i = 0; i < w; i++)
            *out++ = *vram++;
    }
}

void write_vram_tilemap_rect(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, const void *src) {
    u32 i, j;
    const u16 *in = src;
    u16 *base = BG_TILEMAP(bgcnt) + x + y * 32;

    for (j = 0; j < h; j++) {
        u16 *vram = base + j * 32;
        for (i = 0; i < w; i++)
            *vram++ = *in++;
    }
}

void decompress_to_ewram_27000(const u8 *src) {
    lz_decompress_dispatch(src, (void *)BATTLEFIELD_ANIM_TILES_ADDR);
}

void race_enter_team_select(void) {
    u32 zero_obj = 0;
    u32 zero_bg;

    CpuFastSet(&zero_obj, (void *)OBJ_PLTT, 0x01000080);
    zero_bg = 0;
    CpuFastSet(&zero_bg, (void *)PLTT, 0x01000080);
    mem_fill8(&gGameWork.medabotsMode, 0x14, 0);
    gGameWork.medabotsMode = 3;
    gBattleWork.teamPicks[0] = 0;
    gBattleWork.teamPicks[1] = 0;
    gBattleWork.teamPicks[2] = 0;
    gGameMode = 0;
    gGameState = 3;
    gGameSubState = 0;
}

// Sprite slot: while its motion table (1-based) is set, add the (x, y) step for the current step of its row
// from gSpriteMotionSteps to y (wrapped to 0xFF) and x (wrapped to 0x1FF), then advance the step.
void update_sprite_animation_position(u32 slot) {
    s32 mask = 0x1FF;

    if (gSpriteEntries[slot].work[SPR_MOTION_TABLE] != 0) {
        gSpriteEntries[slot].y =
            (gSpriteEntries[slot].y + gSpriteMotionSteps[(gSpriteEntries[slot].work[SPR_MOTION_TABLE] - 1) * 256 +
                                                         gSpriteEntries[slot].work[SPR_MOTION_ROW] * 8 +
                                                         (gSpriteEntries[slot].work[SPR_MOTION_STEP] & 3) * 2]) &
            0xFF;
        gSpriteEntries[slot].x =
            (gSpriteEntries[slot].x + gSpriteMotionSteps[(gSpriteEntries[slot].work[SPR_MOTION_TABLE] - 1) * 256 +
                                                         gSpriteEntries[slot].work[SPR_MOTION_ROW] * 8 +
                                                         (gSpriteEntries[slot].work[SPR_MOTION_STEP] & 3) * 2 + 1]) &
            mask;
        gSpriteEntries[slot].work[SPR_MOTION_STEP]++;
    }
}

u32 calculate_direction_index(s32 x, s32 y, s32 tx, s32 ty) {
    s32 sx, sy;
    float dx, dy;
    s32 ratio;

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
                ratio = (dx + dy * 0.5f) / dy;
                if (ratio > 4) {
                    ratio = (gFrameCounter & 3) ? 4 : 3;
                }
                return 0xC - ratio;
            } else {
                ratio = (dy + dx * 0.5f) / dx;
                if (ratio > 4) {
                    ratio = (gFrameCounter & 3) ? 4 : 3;
                }
                return ratio + 0xC;
            }
        } else if (sy == 1) {
            if (dx == 0)
                return 0;
            if (dy == 0)
                return 8;
            if (dx == dy)
                return 4;
            if (dx > dy) {
                ratio = (dx + dy * 0.5f) / dy;
                if (ratio > 4) {
                    ratio = (gFrameCounter & 3) ? 4 : 3;
                }
                return ratio + 4;
            } else {
                ratio = (dy + dx * 0.5f) / dx;
                if (ratio > 4) {
                    ratio = (gFrameCounter & 3) ? 4 : 3;
                }
                return 4 - ratio;
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
                ratio = (dx + dy * 0.5f) / dy;
                if (ratio > 4) {
                    ratio = (gFrameCounter & 3) ? 4 : 3;
                }
                return 0x1C - ratio;
            } else {
                ratio = (dy + dx * 0.5f) / dx;
                if (ratio > 4) {
                    ratio = (gFrameCounter & 3) ? 4 : 3;
                }
                return ratio + 0x1C;
            }
        } else if (sy == 0) {
            if (dx == 0)
                return 0x10;
            if (dy == 0)
                return 0x18;
            if (dx == dy)
                return 0x14;
            if (dx > dy) {
                ratio = (dx + dy * 0.5f) / dy;
                if (ratio > 4) {
                    ratio = (gFrameCounter & 3) ? 4 : 3;
                }
                return ratio + 0x14;
            } else {
                ratio = (dy + dx * 0.5f) / dx;
                if (ratio > 4) {
                    ratio = (gFrameCounter & 3) ? 4 : 3;
                }
                return 0x14 - ratio;
            }
        }
    }
}

void init_medabot_sprite_tree(void) {
    struct SpriteTree *obj = (struct SpriteTree *)SPRITE_TREE_ADDR;
    u8 *node_oams;
    u8 *slots;
    u32 fill;
    u32 fill2;

    mem_fill8((u8 *)obj, 0xD0, 0);
    node_oams = (u8 *)SPRITE_TREE_OAMS_ADDR(0);
    mem_fill8(node_oams, 0x820, 0);
    slots = (u8 *)SPRITE_SLOTS_TWO_ADDR;
    mem_fill8(slots, 0x60, 0);
    gVBlankOamMode = 2;
    gSpriteWork = (struct SpriteWork *)SPRITE_WORK_ADDR;
    fill = 0;
    CpuFastSet(&fill, (void *)SPRITE_WORK_ADDR, 0x01000426);
    gMedabotSpriteSlots = (struct MedabotSpriteSlot *)slots;
    fill2 = 0x200;
    CpuFastSet(&fill2, gSpriteWork->oamBuf, 0x01000100);
    gSpriteWork->oamCount = 0;
    gSpriteWork->affineIdx = 0;
    init_sprite_tree(obj, (u8 *)gSpriteWork, (struct SpriteNodeDesc **)gMedabotSpriteNodeDescs,
                     (struct SpriteNodeOam *)node_oams);
}

// K&R definitions: the callers were compiled without a prototype (promoted int arguments), and the
// callee narrows its parameters itself. A prototype with u8 / u16 parameters changes the callers.
void setup_scene_with_bg_and_sprites(slot, head, rarm, larm, legs, y, x, depth, pal, bank, step, side) u32 slot;
u8 head, rarm, larm, legs;
u16 y, x;
u32 depth;
u8 pal, bank, step, side;
{
    u32 flags;
    u32 fill;

    switch (depth) {
    case 0:
        depth = 100;
        break;
    case 1:
        depth = 200;
        break;
    case 2:
        depth = 300;
        break;
    case 3:
        depth = 400;
        break;
    }
    if (bank == 0)
        bank = 1;
    else
        bank = 2;
    flags = 0;
    if (step == 1)
        flags = 4;
    ((struct SpriteTree *)SPRITE_TREE_ADDR)->oams = (struct SpriteNodeOam *)SPRITE_TREE_OAMS_ADDR(slot);
    setup_medabot_part_sprites(gSpriteWork->oamBuf, (struct SpriteTree *)SPRITE_TREE_ADDR, head, rarm, larm, legs,
                               (s16)x, (s16)y, depth, pal, bank | flags, side);
    if (step == 2) {
        fill = 0x200;
        CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
        gSpriteWork->oamCount = 0;
        gSpriteWork->affineIdx = 0;
    }
}

// Draws a Medabot sprite (sprite tree slot `slot`) from its four part ids at (x, y); used by the battle close-ups,
// the status screen and the Medabots screen.
void draw_medabot_sprite(slot, head, rarm, larm, legs, y, x, depth, pal, bank, step, side, base) u32 slot;
u8 head, rarm, larm, legs;
u16 y, x;
u32 depth;
u8 pal, bank, step, side, base;
{
    u32 flags;
    u32 fill;

    switch (depth) {
    case 0:
        depth = base + 100;
        break;
    case 1:
        depth = base + 200;
        break;
    case 2:
        depth = base + 300;
        break;
    case 3:
        depth = base + 400;
        break;
    }
    if (bank == 0)
        bank = 1;
    else
        bank = 2;
    flags = 0;
    if (step == 1)
        flags = 4;
    ((struct SpriteTree *)SPRITE_TREE_ADDR)->oams = (struct SpriteNodeOam *)SPRITE_TREE_OAMS_ADDR(slot);
    setup_medabot_part_sprites(gSpriteWork->oamBuf, (struct SpriteTree *)SPRITE_TREE_ADDR, head, rarm, larm, legs,
                               (s16)x, (s16)y, depth, pal, bank | flags, side);
    if (step == 2) {
        fill = 0x200;
        CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
        gSpriteWork->oamCount = 0;
        gSpriteWork->affineIdx = 0;
    }
}

void setup_sprite_animation_entry(u32 slot, u8 id, u8 kind, u16 y, u16 x, u32 depth, u8 pal, u8 bank, u8 step) {
    u32 flags;
    u32 fill;

    switch (depth) {
    case 0:
        depth = 100;
        break;
    case 1:
        depth = 200;
        break;
    case 2:
        depth = 300;
        break;
    case 3:
        depth = 400;
        break;
    }
    if (bank == 0)
        bank = 1;
    else
        bank = 2;
    flags = 0;
    if (step == 1)
        flags = 4;
    ((struct SpriteTree *)SPRITE_TREE_ADDR)->oams = (struct SpriteNodeOam *)SPRITE_TREE_OAMS_ADDR(slot);
    draw_medapart_sprite(gSpriteWork->oamBuf, (struct SpriteTree *)SPRITE_TREE_ADDR, id, kind, (s16)x, (s16)y, depth,
                         pal, bank | flags);
    if (step == 2) {
        fill = 0x200;
        CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
        gSpriteWork->oamCount = 0;
        gSpriteWork->affineIdx = 0;
    }
}

u32 medabot_pose_anim_step(u32 slot, u32 anim, u32 legs) {
    u32 n;
    u8 *cnt;
    u8 *pos;
    u32 zero;
    s32 done;
    register struct SpriteTree *obj asm(
        "r1"); // pinned: the original loads SPRITE_TREE_ADDR before SPRITE_TREE_POSE_KEY_ADDR
    // `done` is deliberately uninitialized: the original reads ip when *pos >= n

    anim = gPoseAnimIds[anim][gLegPartPoseSets[legs]];
    n = 0;
    if (gPoseKeyframeEnds[anim][0] != 0) {
        do {
            n++;
            if (n > 0xFE)
                break;
        } while (gPoseKeyframeEnds[anim][n] != 0);
    }
    cnt = (u8 *)SPRITE_TREE_POSE_FRAME_ADDR + slot;
    {
        // (*cnt)++ with the zero set between the add and the store
        u8 new_cnt = *cnt + 1;
        zero = 0;
        *cnt = new_cnt;
    }
    obj = (struct SpriteTree *)SPRITE_TREE_ADDR;
    pos = (u8 *)SPRITE_TREE_POSE_KEY_ADDR + slot;
    if (*pos < n) {
        obj->oams = (struct SpriteNodeOam *)SPRITE_TREE_OAMS_ADDR(slot);
        done = interpolate_entity_positions((struct InterpEnt *)obj->oams, gPoseKeyframeAngles[anim],
                                            gPoseKeyframeOffsets[anim], gPoseKeyframeEnds[anim], anim, *cnt, *pos, 0x40,
                                            n);
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

// guess: message sprite set, 0 = the current area's default (gFieldWork.player_form is the area palette id).
u32 resolve_area_sprite_set(u8 set) {
    if (set == 0)
        return gPlayerFormSpriteSets[gFieldWork.player_form];
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
    gGameWork.noAffineSprites = 0;
    gVBlankOamMode = 0;
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
