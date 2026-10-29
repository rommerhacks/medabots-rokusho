// Helpers used by the field code: decimal digit counting / truncation, fixed-point divides, BG2 affine
// setup, a debug BG scroller, and copies of tilemaps and 2x2 metatile maps into 64x64 BG screens.

#include "global.h"

s32 count_decimal_digits(s32 n) {
    s32 i, j, power;

    if (n == 0)
        return 1;
    for (i = 0; i <= 9; i++) {
        power = 1;
        for (j = 0; j < i; j++)
            power *= 10;
        if (n / power == 0)
            break;
    }
    return i;
}

s32 truncate_to_digit_count(s32 n, u8 k) {
    s32 rem = n;
    register s32 i asm("r4") = 0; // pinned: the original allocates i before power / j
    s32 power, j;

    do {
        while (i < count_decimal_digits(n) - k && i != count_decimal_digits(n) - 1) {
            power = 1;
            j = 0;
            i++;
            while (j < count_decimal_digits(n) - i) {
                power *= 10;
                j++;
            }
            j = rem / power;
            rem -= power * j;
        }
    } while (0);
    if (k != 0)
        return j;
    return rem;
}

// Whether item item_id can be used now: 0 not a usable item, 1 yes, 2-4 not here (2: town map in an area of type
// 0xA, 3: blocked by a gFieldWork.useBlockFlags flag, 4: disguise while player_form is 1-2). Items 1, 5, 12, 13, 19,
// 39, 40 are the disguises ("Transform Goods").
u32 item_get_use_result(u32 item_id) {
    u32 result;

    switch (item_id) {
    case 0:
        if (gAreaTypes[gFieldWork.area_id] == 0xA) {
            result = 2;
            break;
        }
        result = 1;
        if (gFieldWork.useBlockFlags & 0x20)
            result = 3;
        break;
    case 1:
    case 5:
    case 12:
    case 13:
    case 19:
    case 39:
    case 40:
        result = 1;
        if (gFieldWork.useBlockFlags & 1)
            result = 3;
        else if ((u8)(gFieldWork.player_form - 1) <= 1)
            result = 4;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

// Dead code (nothing calls it): BG2 affine matrix in gFieldState (guess).
static void bg2_affine_update_matrix(void) {
    const s16 *sine = gSineTable;
    struct FieldState *state = &gFieldState;
    s32 angle;

    state->bg2_pa = fixed_point_multiply(sine[angle = state->bg2_angle + 0x40], divide_by_65536(state->bg2_scale_x));
    state->bg2_pb = fixed_point_multiply(sine[state->bg2_angle], divide_by_65536(state->bg2_scale_x));
    state->bg2_pc = fixed_point_multiply(-sine[state->bg2_angle], divide_by_65536(state->bg2_scale_y));
    state->bg2_pd = fixed_point_multiply(sine[angle = state->bg2_angle + 0x40], divide_by_65536(state->bg2_scale_y));
    state->bg2_x = (120 - state->bg2_center_x) * 256 - state->bg2_pa * 120 - state->bg2_pb * 80;
    state->bg2_y = (120 - state->bg2_center_y) * 256 - state->bg2_pc * 120 - state->bg2_pd * 80;
}

s16 fixed_point_multiply(s16 lhs, s16 rhs) {
    s32 product = lhs * rhs;
    product /= 256;
    return product;
}

static s16 fixed_point_divide(s16 num, s16 denom) {
    return (num << 8) / denom;
}

s16 divide_by_65536(s16 divisor) {
    s32 n = 0x10000;

    return n / divisor;
}

void bg2_affine_reset(void) {
    struct FieldState *state = &gFieldState;

    state->bg2_x = 0;
    state->bg2_y = 0;
    state->bg2_pa = 0x100;
    state->bg2_pb = 0;
    state->bg2_pc = 0;
    state->bg2_pd = 0x100;
    state->unused30 = 0;
    state->bg2_scale_x = 0x100;
    state->bg2_scale_y = 0x100;
    state->bg2_angle = 0;
    state->bg2_center_x = 0;
    state->bg2_center_y = 0;
}

// Not called directly (hidden in the tail of bg2_affine_reset). Guess: debug, B + D-pad scrolls BG1-3,
// RIGHT/LEFT step gFieldState.bg2_angle (0-255).
void debug_bg_scroll_input(void) {
    if (KEYS_LO(gHeldKeys) & 2) {
        if (KEYS_LO(gHeldKeys) & 0x40) {
            gFieldState.saved_bg1_y -= 4;
            gFieldState.saved_bg2_y -= 4;
            gFieldState.saved_bg3_y -= 4;
        }
        if (KEYS_LO(gHeldKeys) & 0x80) {
            gFieldState.saved_bg1_y += 4;
            gFieldState.saved_bg2_y += 4;
            gFieldState.saved_bg3_y += 4;
        }
        if (KEYS_LO(gHeldKeys) & 0x20) {
            gFieldState.saved_bg1_x -= 4;
            gFieldState.saved_bg2_x -= 4;
            gFieldState.saved_bg3_x -= 4;
        }
        if (KEYS_LO(gHeldKeys) & 0x10) {
            gFieldState.saved_bg1_x += 4;
            gFieldState.saved_bg2_x += 4;
            gFieldState.saved_bg3_x += 4;
        }
    }
    if (KEYS_LO(gHeldKeys) & 0x10)
        gFieldState.bg2_angle = ++gFieldState.bg2_angle & 0xFF;
    if (KEYS_LO(gHeldKeys) & 0x20)
        gFieldState.bg2_angle = (gFieldState.bg2_angle + 0xFF) & 0xFF;
}

// Not called directly (hidden in the tail of bg2_affine_reset).
static void copy_tilemap_rows_add(u16 *src, u16 *dst, s32 h, s32 w, s32 maxh, s32 pitch, s32 add) {
    s32 i, j;
    if (h > maxh)
        h = maxh;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++)
            *dst++ = *src++ + add;
        dst += pitch - w;
    }
}

// Copies a w x h tilemap (u16 entries, row pitch w) into a 64x64 BG screen (four 32x32 blocks), adding add.
void copy_tilemap_with_offset_08048CA4(const void *src, void *dst, s32 h, s32 w, s32 dst_h, s32 dst_w, s32 add) {
    s32 i, j, n;
    s32 rows;

    rows = 32;
    if (h < 32)
        rows = h;
    for (i = 0; i < rows; i++) {
        n = 32;
        if (w < 32)
            n = w;
        for (j = 0; j < n; j++)
            ((u16 *)dst)[i * 32 + j] = ((const u16 *)src)[w * i + j] + add;
        if (w > 31) {
            for (j = 0; j < w - 32; j++)
                ((u16 *)dst)[0x400 + i * 32 + j] = ((const u16 *)src)[w * i + 32 + j] + add;
        }
    }
    if (h > 31) {
        for (i = 0; i < h - 32; i++) {
            n = 32;
            if (w < 32)
                n = w;
            for (j = 0; j < n; j++)
                ((u16 *)dst)[0x800 + i * 32 + j] = ((const u16 *)src)[(i + 32) * w + j] + add;
            if (w > 31) {
                for (j = 0; j < w - 32; j++)
                    ((u16 *)dst)[0xC00 + i * 32 + j] = ((const u16 *)src)[(i + 32) * w + 32 + j] + add;
            }
        }
    }
}

// Expands a (h/2) x (w/2) map of 2x2 metatile ids (src) into a 64x64 BG screen at tile (x, y) (four 32x32 blocks).
#define MAP ((u16(*)[32])dst)
#define SRC(r, c) (((const u8 *)src) + (w / 2) * (r))[c]
void copy_tiles_to_bg_tilemap(const void *src, void *dst, s32 h, s32 w, s32 dst_h, s32 dst_w, s32 y, s32 x, s32 tile) {
    s32 i, j;
    s32 rows, cols;

    rows = h + y > 31 ? 32 : h;
    for (i = 0; i < rows; i++) {
        cols = w + x > 31 ? 32 : w;
        for (j = 0; j < cols; j++)
            build_bg_tile_entry(&MAP[i + y][j + x], SRC(i / 2, j / 2), tile, i % 2, j % 2, y % 2, x % 2);
        if (w > 31) {
            for (j = 0; j < w - 32; j++)
                build_bg_tile_entry(&MAP[i + y + 32][j + x], SRC(i / 2, j / 2 + 16), tile, i % 2, j % 2, y % 2, x % 2);
        }
    }
    if (h > 31) {
        for (i = 0; i < h - 32; i++) {
            cols = 32;
            if (w < 32)
                cols = w;
            for (j = 0; j < cols; j++)
                build_bg_tile_entry(&MAP[i + y + 64][j + x], SRC(i / 2 + 16, j / 2), tile, i % 2, j % 2, y % 2, x % 2);
            if (w > 31) {
                for (j = 0; j < w - 32; j++)
                    build_bg_tile_entry(&MAP[i + y + 96][j + x], SRC(i / 2 + 16, j / 2 + 16), tile, i % 2, j % 2, y % 2,
                                        x % 2);
            }
        }
    }
}
#undef SRC
#undef MAP

// Not called directly (hidden in the tail of copy_tiles_to_bg_tilemap). Writes one 2x2 metatile.
static void write_metatile_2x2(u16 *dst, s32 pal, s32 tile) {
    s32 base = (pal + 1) * 4;
    s32 attr = (pal << 12) + tile;

    dst[0] = base | attr;
    dst[1] = (base + 1) | attr;
    dst[32] = (base + 2) | attr;
    dst[33] = (base + 3) | attr;
}
