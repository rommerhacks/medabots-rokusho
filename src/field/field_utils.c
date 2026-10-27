// Helpers used by the field code: decimal digit counting / truncation, fixed-point divides, BG2 affine
// setup, a debug BG scroller, and copies of tilemaps and 2x2 metatile maps into 64x64 BG screens.

#include "global.h"

s32 count_decimal_digits(s32 n) {
    s32 i, j, p;

    if (n == 0)
        return 1;
    for (i = 0; i <= 9; i++) {
        p = 1;
        for (j = 0; j < i; j++)
            p *= 10;
        if (n / p == 0)
            break;
    }
    return i;
}

s32 truncate_to_digit_count(s32 n, u8 k) {
    s32 rem = n;
    register s32 i asm("r4") = 0; // pinned: the original allocates i before p / j
    s32 p, j;

    do {
        while (i < count_decimal_digits(n) - k && i != count_decimal_digits(n) - 1) {
            p = 1;
            j = 0;
            i++;
            while (j < count_decimal_digits(n) - i) {
                p *= 10;
                j++;
            }
            j = rem / p;
            rem -= p * j;
        }
    } while (0);
    if (k != 0)
        return j;
    return rem;
}

// Whether item a can be used now: 0 not a usable item, 1 yes, 2-4 not here (2: town map in an area of type
// 0xA, 3: blocked by a gUnk_030057E0.unkC5D flag, 4: disguise while unkC5C is 1-2). Items 1, 5, 12, 13, 19,
// 39, 40 are the disguises ("Transform Goods").
u32 item_get_use_result(u32 a) {
    u32 r;

    switch (a) {
    case 0:
        if (gUnk_083D29EB[gUnk_030057E0.unk7FE] == 0xA) {
            r = 2;
            break;
        }
        r = 1;
        if (gUnk_030057E0.unkC5D & 0x20)
            r = 3;
        break;
    case 1:
    case 5:
    case 12:
    case 13:
    case 19:
    case 39:
    case 40:
        r = 1;
        if (gUnk_030057E0.unkC5D & 1)
            r = 3;
        else if ((u8)(gUnk_030057E0.unkC5C - 1) <= 1)
            r = 4;
        break;
    default:
        r = 0;
        break;
    }
    return r;
}

// Dead code (nothing calls it): BG2 affine matrix for gUnk_03005310 (guess).
static void bg2_affine_update_matrix(void) {
    const s16 *sine = gSineTable;
    struct Unk_03005310 *p = &gUnk_03005310;
    s32 a;

    p->unk8 = fixed_point_multiply(sine[a = p->unk36 + 0x40], divide_by_65536(p->unk32));
    p->unkA = fixed_point_multiply(sine[p->unk36], divide_by_65536(p->unk32));
    p->unkC = fixed_point_multiply(-sine[p->unk36], divide_by_65536(p->unk34));
    p->unkE = fixed_point_multiply(sine[a = p->unk36 + 0x40], divide_by_65536(p->unk34));
    p->unk10 = (120 - p->unk2C) * 256 - p->unk8 * 120 - p->unkA * 80;
    p->unk14 = (120 - p->unk2E) * 256 - p->unkC * 120 - p->unkE * 80;
}

s16 fixed_point_multiply(s16 a, s16 b) {
    s32 r = a * b;
    r /= 256;
    return r;
}

static s16 fixed_point_divide(s16 a, s16 b) {
    return (a << 8) / b;
}

s16 divide_by_65536(s16 a) {
    s32 n = 0x10000;

    return n / a;
}

void bg2_affine_reset(void) {
    struct Unk_03005310 *p = &gUnk_03005310;

    p->unk10 = 0;
    p->unk14 = 0;
    p->unk8 = 0x100;
    p->unkA = 0;
    p->unkC = 0;
    p->unkE = 0x100;
    p->unk30 = 0;
    p->unk32 = 0x100;
    p->unk34 = 0x100;
    p->unk36 = 0;
    p->unk2C = 0;
    p->unk2E = 0;
}

// Not called directly (hidden in the tail of bg2_affine_reset). Guess: debug, B + D-pad scrolls BG1-3,
// RIGHT/LEFT step unk36 (0-255).
void debug_bg_scroll_input(void) {
    if (KEYS_LO(gHeldKeys) & 2) {
        if (KEYS_LO(gHeldKeys) & 0x40) {
            gUnk_03005310.unk26 -= 4;
            gUnk_03005310.unk28 -= 4;
            gUnk_03005310.unk2A -= 4;
        }
        if (KEYS_LO(gHeldKeys) & 0x80) {
            gUnk_03005310.unk26 += 4;
            gUnk_03005310.unk28 += 4;
            gUnk_03005310.unk2A += 4;
        }
        if (KEYS_LO(gHeldKeys) & 0x20) {
            gUnk_03005310.unk1E -= 4;
            gUnk_03005310.unk20 -= 4;
            gUnk_03005310.unk22 -= 4;
        }
        if (KEYS_LO(gHeldKeys) & 0x10) {
            gUnk_03005310.unk1E += 4;
            gUnk_03005310.unk20 += 4;
            gUnk_03005310.unk22 += 4;
        }
    }
    if (KEYS_LO(gHeldKeys) & 0x10)
        gUnk_03005310.unk36 = ++gUnk_03005310.unk36 & 0xFF;
    if (KEYS_LO(gHeldKeys) & 0x20)
        gUnk_03005310.unk36 = (gUnk_03005310.unk36 + 0xFF) & 0xFF;
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
void copy_tilemap_with_offset_08048CA4(const void *src, void *dst, s32 h, s32 w, s32 c, s32 d, s32 add) {
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
void copy_tiles_to_bg_tilemap(const void *src, void *dst, s32 h, s32 w, s32 c, s32 d, s32 y, s32 x, s32 tile) {
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
    s32 t = (pal + 1) * 4;
    s32 attr = (pal << 12) + tile;

    dst[0] = t | attr;
    dst[1] = (t + 1) | attr;
    dst[32] = (t + 2) | attr;
    dst[33] = (t + 3) | attr;
}
