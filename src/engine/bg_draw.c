// BG helpers shared by the title, save and item screens: clear all sprites, clear BG1 / BG2 tilemaps,
// and draw decimal numbers into BG tilemaps (draw_number*, plain and two-tile tall digits). Called from
// code_0805AB40 and code_0805EE6C; several of the variants are dead code.
#include "global.h"

void free_all_sprites(void) {
    s32 i;

    for (i = 0; i < 128; i++)
        gSpriteEntries[i].unk0 = 0;
}

static void clear_vram_bg2_tilemap(void) {
    u32 zero = 0;
    vu16 *bg2;
    u16 v;

    CpuFastSet(&zero, (void *)0x06008000, 0x01001000);
    lz_decompress_dispatch(gUnk_08784CB0, (void *)0x06008020);
    CpuFastSet(gUnk_08483AA0, (void *)0x05000020, 8);
    bg2 = &REG_BG2CNT;
    v = 0x1608;
    *bg2 = v;
    REG_DISPCNT |= 0x400;
}

static void clear_vram_bg1_tilemap(void) {
    u32 zero = 0;
    vu16 *bg1;
    u16 v;

    CpuFastSet(&zero, (void *)0x06004000, 0x01001000);
    lz_decompress_dispatch(gUnk_08784CB0, (void *)0x06004020);
    bg1 = &REG_BG1CNT;
    v = 0x1E04;
    *bg1 = v;
    REG_DISPCNT |= 0x200;
}

static void clear_vram_bg2_screenblock(void) {
    u32 zero = 0;
    vu16 *bg2;
    u16 v;

    CpuFastSet(&zero, (void *)0x06008400, 0x01000F00);
    bg2 = &REG_BG2CNT;
    v = 0x1608;
    *bg2 = v;
    REG_DISPCNT |= 0x400;
}

// Decimal number on BG screen block bg: width > 0 right-aligned blank-padded, < 0 zero-padded in -width
// places, 0 left-aligned.
void draw_number(u16 value, s32 width, u8 x, u8 y, u8 pal, u8 bg) {
    u16 buf[6];
    u16 base = gMenuWork->bg_tile_base + 0x16;
    s8 w = width;
    vu16 *p;
    s32 i;

    if (w != 0) {
        if (w > 0) {
            p = (vu16 *)(VRAM + (bg << 11)) + (x + w - 1) + y * 32;
            for (i = 0; i < w; i++) {
                if (i != 0 && value == 0)
                    *p-- = pal << 12;
                else {
                    *p-- = (value % 10 + base) | (pal << 12);
                    value /= 10;
                }
            }
        } else {
            s8 n = -w;
            p = (vu16 *)(VRAM + (bg << 11)) + (x + n - 1) + y * 32;
            for (i = 0; i < n; i++) {
                if (i != 0 && value == 0)
                    *p-- = base | (pal << 12);
                else {
                    *p-- = (value % 10 + base) | (pal << 12);
                    value /= 10;
                }
            }
        }
    } else {
        p = (vu16 *)(VRAM + (bg << 11)) + x + y * 32;
        for (i = 0; i <= 4; i++) {
            buf[i] = value % 10;
            if (value == 0 && i != 0)
                break;
            value /= 10;
        }
        for (i--; i >= 0; i--)
            *p++ = (buf[i] + base) | (pal << 12);
    }
}

// draw_number with 2-tile-tall digits (rows y and y + 1).
void draw_number_tall(u16 value, s8 w, u8 x, u8 y, u8 pal, u8 bg) {
    u16 buf[6];
    u16 saved = value;
    u16 base = gMenuWork->bg_tile_base + 1;
    vu16 *p;
    s32 i;

    if (w != 0) {
        if (w > 0) {
            p = (vu16 *)(VRAM + (bg << 11)) + (x + w - 1) + y * 32;
            for (i = 0; i < w; i++) {
                if (i != 0 && value == 0)
                    *p-- = pal << 12;
                else {
                    *p-- = (value % 10 + base) | (pal << 12);
                    value /= 10;
                }
            }
            value = saved;
            base += 10;
            p = (vu16 *)(VRAM + (bg << 11)) + (x + w - 1) + (y + 1) * 32;
            for (i = 0; i < w; i++) {
                if (i != 0 && value == 0)
                    *p-- = pal << 12;
                else {
                    *p-- = (value % 10 + base) | (pal << 12);
                    value /= 10;
                }
            }
        } else {
            w = -w;
            p = (vu16 *)(VRAM + (bg << 11)) + (x + w - 1) + y * 32;
            for (i = 0; i < w; i++) {
                if (i != 0 && value == 0)
                    *p-- = base | (pal << 12);
                else {
                    *p-- = (value % 10 + base) | (pal << 12);
                    value /= 10;
                }
            }
            value = saved;
            base += 10;
            p = (vu16 *)(VRAM + (bg << 11)) + (x + w - 1) + (y + 1) * 32;
            for (i = 0; i < w; i++) {
                if (i != 0 && value == 0)
                    *p-- = base | (pal << 12);
                else {
                    *p-- = (value % 10 + base) | (pal << 12);
                    value /= 10;
                }
            }
        }
    } else {
        p = (vu16 *)(VRAM + (bg << 11)) + x + y * 32;
        for (i = 0; i <= 4; i++) {
            if ((buf[i] = value % 10) == 0 && i != 0)
                break;
            value /= 10;
        }
        for (i--; i >= 0; i--)
            *p++ = (buf[i] + base) | (pal << 12);
        p = (vu16 *)(VRAM + (bg << 11)) + x + (y + 1) * 32;
        value = saved;
        for (i = 0; i <= 4; i++) {
            if ((buf[i] = value % 10) == 0 && i != 0)
                break;
            value /= 10;
        }
        for (i--; i >= 0; i--)
            *p++ = (buf[i] + base) | (pal << 12);
    }
}

// Runtime: item list page numbers (item_menu_draw_page_numbers).
void draw_number_3digits(s32 n, s32 x, s32 y) {
    s32 pal = 13;
    u16 base = gMenuWork->bg_tile_base + 0x16;
    vu16 *p = (vu16 *)(VRAM + 0xF000);

    p = p + x + y * 32;
    if (n / 100 % 10)
        *p = (base + n / 100 % 10) | (pal << 12);
    else
        *p = 0;
    *p++;
    if (n / 100 % 10 || n / 10 % 10)
        *p = (base + n / 10 % 10) | (pal << 12);
    else
        *p = 0;
    *p++;
    *p = (base + n % 10) | (pal << 12);
}

// n % 100 as 2-tile-tall digits. Runtime: item quantities (update_battle_medapart_icons).
void draw_number_2digits_tall(s32 n, s32 x, s32 y) {
    s16 base;
    s32 pal = 12;
    vu16 *p;
    s32 sbb = 30;

    n %= 100;
    base = gMenuWork->bg_tile_base;
    p = (vu16 *)(VRAM + (sbb << 11)) + x + y * 32;
    if (n / 100 % 10 || n / 10 % 10)
        *p = (n / 10 % 10 + (base + 1)) | (pal << 12);
    else
        *p = 0;
    *p++;
    *p = (n % 10 + (base + 1)) | (pal << 12);
    p = (vu16 *)(VRAM + (sbb << 11)) + x + (y + 1) * 32;
    if (n / 100 % 10 || n / 10 % 10)
        *p = (n / 10 % 10 + (base + 0xB)) | (pal << 12);
    else
        *p = 0;
    *p++;
    *p = (n % 10 + (base + 0xB)) | (pal << 12);
}

// 5 digits on BG screen block 22, leading zeros blanked.
static void draw_number_5digits(u16 value, u8 x, u8 y) {
    vu16 *p;
    u32 sbb = 22;
    u32 pal = 1;
    u16 base = 0x16;
    u16 d;

    p = (vu16 *)(VRAM + sbb * 0x800 + x * 2 + y * 64);
    d = value / 10000;
    if (d != 0)
        *p = (d + base) | (pal << 12);
    else
        *p = 0;
    *p++;

    d = (u16)(value / 1000) % 10;
    if (d != 0 || (u16)(value / 10000) != 0)
        *p = (d + base) | (pal << 12);
    else
        *p = 0;
    *p++;

    d = (u16)(value / 100) % 10;
    if (d != 0 || (u16)(value / 10000) != 0 || (u16)((u16)(value / 1000) % 10) != 0)
        *p = (d + base) | (pal << 12);
    else
        *p = 0;
    *p++;

    d = (u16)(value / 10) % 10;
    if (d != 0 || (u16)(value / 10000) != 0 || (u16)((u16)(value / 1000) % 10) != 0 ||
        (u16)((u16)(value / 100) % 10) != 0)
        *p = (d + base) | (pal << 12);
    else
        *p = 0;
    *p++;

    *p = (value % 10 + base) | (pal << 12);
}

// Unused.
static void draw_number_5digits_tall(u16 value, u8 x, u8 y) {
    vu16 *p;
    u32 pal = 1;
    u16 base = 1;
    u32 sbb = 22;
    u16 d;

    p = (vu16 *)(VRAM + sbb * 0x800 + x * 2 + y * 64);
    d = value / 10000;
    if (d != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = (u16)(value / 1000) % 10;
    if (d != 0 || (u16)(value / 10000) != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = (u16)(value / 100) % 10;
    if (d != 0 || (u16)(value / 10000) != 0 || (u16)((u16)(value / 1000) % 10) != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = (u16)(value / 10) % 10;
    if (d != 0 || (u16)(value / 10000) != 0 || (u16)((u16)(value / 1000) % 10) != 0 ||
        (u16)((u16)(value / 100) % 10) != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    *p = (value % 10 + base) | (pal << 12);

    p = (vu16 *)(VRAM + sbb * 0x800 + x * 2 + (y + 1) * 64);
    base = 0xB;
    d = value / 10000;
    if (d != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = (u16)(value / 1000) % 10;
    if (d != 0 || (u16)(value / 10000) != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = (u16)(value / 100) % 10;
    if (d != 0 || (u16)(value / 10000) != 0 || (u16)((u16)(value / 1000) % 10) != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = (u16)(value / 10) % 10;
    if (d != 0 || (u16)(value / 10000) != 0 || (u16)((u16)(value / 1000) % 10) != 0 ||
        (u16)((u16)(value / 100) % 10) != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    *p = (value % 10 + base) | (pal << 12);
}

// Unused; the tens-of-thousands digit misses its % 10 in the original.
static void draw_number_7digits(u32 value, u32 x, u32 y) {
    vu16 *p;
    u32 sbb = 22;
    u32 pal = 1;
    u16 base = 0x16;
    u16 d;

    p = (vu16 *)(VRAM + sbb * 0x800 + x * 2 + y * 64);
    d = value / 1000000;
    if (d != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = value / 100000 % 10;
    if (d != 0 || value / 1000000 != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = value / 10000 % 10;
    if (d != 0 || value / 1000000 != 0 || value / 100000 % 10 != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = value / 1000 % 10;
    if (d != 0 || value / 1000000 != 0 || value / 100000 % 10 != 0 || value / 10000 % 10 != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = value / 100 % 10;
    if (d != 0 || value / 1000000 != 0 || value / 100000 % 10 != 0 || value / 10000 % 10 != 0 || value / 1000 % 10 != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    d = value / 10 % 10;
    if (d != 0 || value / 1000000 != 0 || value / 100000 % 10 != 0 || value / 10000 != 0 || value / 1000 % 10 != 0 ||
        value / 100 % 10 != 0)
        *p++ = (d + base) | (pal << 12);
    else
        *p++;

    *p = (value % 10 + base) | (pal << 12);
}

// Unused (nothing calls it): writes row `row` of a len-wide byte grid to screenblock 22 at (x, y) as
// tiles 0x9F + byte, palette 1.
static void bg22_draw_tile_row(u8 *src, u16 row, u16 x, u16 y, u8 len) {
    u32 entry;
    vu16 *dst;
    u32 sbb = 22;
    u16 i;

    entry &= 0xFFFF0000;
    dst = (vu16 *)(VRAM + sbb * 0x800 + x * 2 + y * 64);
    ((struct BgTileEntry *)&entry)->pal = 1;
    for (i = 0; i < len; i++) {
        ((struct BgTileEntry *)&entry)->tile = (src + i)[row * len] + 0x9F;
        *dst++ = *(u16 *)&entry;
    }
}

static void copy_palettes_to_backup(void) {
    CpuFastSet((void *)(PLTT + 0x200), gPaletteBackup, 0x80);
    CpuFastSet((void *)PLTT, gPaletteBackupBg, 0x80);
}
