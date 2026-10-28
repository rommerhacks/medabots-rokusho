// Tilemap helpers: fill / copy rectangles into a BG's screen block (given by its BGCNT value), decompress
// BG tiles to VRAM, set up BG0, load indexed LZ assets and BG0 tilemaps, and the message portrait tiles
// (message_portrait_anim_step, called by text/message). Used by nearly every screen.

#include "global.h"

void vram_fill_tilemap_rect(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, u16 value) {
    u16 *base = BG_TILEMAP(bgcnt) + x + y * 32;
    u32 i, j;
    for (i = 0; i < h; i++) {
        u16 *out = base + i * 32;
        for (j = 0; j < w; j++)
            *out++ = value;
    }
}

void tilemap_fill_rect(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, u16 tile) {
    u16 *dst;
    u16 *out;
    u32 i, j;
    u32 cols, rows;

    if (x < 32) {
        if (y < 32) {
            dst = BG_TILEMAP(bgcnt) + x + y * 32;
            rows = 32 - y;
            for (i = 0; i < h; i++) {
                cols = 32 - x;
                out = dst + i * 32;
                for (j = 0; j < w; j++) {
                    *out++ = tile;
                    if (--cols == 0)
                        out += 0x3E0;
                }
                if (--rows == 0)
                    dst += 0x400;
            }
        } else {
            y -= 32;
            dst = BG_TILEMAP(bgcnt) + x + y * 32 + 0x800;
            for (i = 0; i < h; i++) {
                cols = 32 - x;
                out = dst + i * 32;
                for (j = 0; j < w; j++) {
                    *out++ = tile;
                    if (--cols == 0)
                        out += 0x3E0;
                }
            }
        }
    } else {
        if (y < 32) {
            dst = BG_TILEMAP(bgcnt) + (x - 32) + y * 32 + 0x400;
            rows = 32 - y;
            for (i = 0; i < h; i++) {
                out = dst + i * 32;
                for (j = 0; j < w; j++)
                    *out++ = tile;
                if (--rows == 0)
                    dst += 0x400;
            }
        } else {
            y -= 32;
            dst = BG_TILEMAP(bgcnt) + (x - 32) + y * 32 + 0xC00;
            for (i = 0; i < h; i++) {
                out = dst + i * 32;
                for (j = 0; j < w; j++)
                    *out++ = tile;
            }
        }
    }
}

void write_tilemap_rect(u32 w, u32 h, u32 x, u32 y, const void *src, u32 bgcnt, u32 base) {
    u16 *dst;
    const u16 *in;
    u32 i, j;
    gTilemapBaseEntry = base;
    dst = BG_TILEMAP(bgcnt) + x + y * 32;
    in = src;
    for (i = 0; i < h; i++) {
        u16 *out = dst + i * 32;
        for (j = 0; j < w; j++)
            *out++ = *in++ + gTilemapBaseEntry;
    }
}

void write_tilemap_to_vram_0803F1C8(u32 w, u32 h, u32 x, u32 y, const void *src, u32 bgcnt, u32 base) {
    u16 *dst;
    u16 *out;
    const u16 *in;
    u32 i, j;
    u32 cols, rows;

    gTilemapBaseEntry = base;
    in = src;
    if (x < 32) {
        if (y < 32) {
            dst = BG_TILEMAP(bgcnt) + x + y * 32;
            rows = 32 - y;
            for (i = 0; i < h; i++) {
                cols = 32 - x;
                out = dst + i * 32;
                for (j = 0; j < w; j++) {
                    *out++ = *in++ + gTilemapBaseEntry;
                    if (--cols == 0)
                        out += 0x3E0;
                }
                if (--rows == 0)
                    dst += 0x400;
            }
        } else {
            y -= 32;
            dst = BG_TILEMAP(bgcnt) + x + y * 32 + 0x800;
            for (i = 0; i < h; i++) {
                cols = 32 - x;
                out = dst + (i << 5);
                for (j = 0; j < w; j++) {
                    *out++ = *in++ + gTilemapBaseEntry;
                    if (--cols == 0)
                        out += 0x3E0;
                }
            }
        }
    } else {
        if (y < 32) {
            dst = BG_TILEMAP(bgcnt) + (x - 32) + y * 32 + 0x400;
            rows = 32 - y;
            for (i = 0; i < h; i++) {
                out = dst + i * 32;
                for (j = 0; j < w; j++)
                    *out++ = *in++ + gTilemapBaseEntry;
                if (--rows == 0)
                    dst += 0x400;
            }
        } else {
            y -= 32;
            dst = BG_TILEMAP(bgcnt) + (x - 32) + y * 32 + 0xC00;
            for (i = 0; i < h; i++) {
                out = dst + i * 32;
                for (j = 0; j < w; j++)
                    *out++ = *in++ + gTilemapBaseEntry;
            }
        }
    }
}

void decompress_bg_tiles_to_vram_bg(void) {
    lz_decompress_dispatch(gMessageWindowTiles, (void *)0x06000020);
    lz_decompress_dispatch(gMessageWindowIconTiles, (void *)0x06001780);
    CpuFastSet(gMenuBgPalette, (void *)(PLTT + 0x1E0), 8);
}

void setup_bg0_display_layer(void) {
    vu16 *bgcnt_reg;
    u16 bgcnt;
    REG_DISPCNT |= 0x100;
    bgcnt_reg = &REG_BG0CNT;
    bgcnt = 0x500;
    *bgcnt_reg = bgcnt;
    set_tilemap_and_decompress_bg(0, 0xD, gMessageWindowTilemap, REG_BG0CNT, 1);
}

void decompress_indexed_asset(u32 set, u32 idx, void *dst, u32 pal, u32 toBuffer) {
    lz_decompress_dispatch(gPortraitTiles[set][idx], dst);
    if (toBuffer)
        CpuFastSet(gPortraitPalettes[set], (void *)(0x0202FA00 + pal * 32), 8);
    else
        CpuFastSet(gPortraitPalettes[set], (void *)(PLTT + pal * 32), 8);
}

void load_bg0_tilemap(u32 set, u32 idx, u32 x, u32 y, u32 anim) {
    REG_DISPCNT |= 0x100;
    REG_BG0CNT = 0x500;
    lz_decompress_dispatch(gPortraitTiles[set][idx], (void *)0x06000F80);
    CpuFastSet(gPortraitPalettes[set], (void *)0x050001A0, 8);
    write_tilemap_rect(8, 8, x, y, gUiTilemaps[anim * 9 + 8], REG_BG0CNT, 0);
}

// The helpers keep gcc from folding mul9(anim) - (frame - 8) into (anim * 9 + 8) - frame.
static inline s32 mul9(s32 value) {
    return value * 9;
}

static inline s32 sub8(u32 value) {
    return value - 8;
}

// One frame of the message window portrait animation (8x8 tiles on BG0): frame gGameWork.portraitAnimFrame of
// tilemap set anim (9 frames, gUiTilemaps[anim * 9 ..]), played backwards when reverse is set; loads
// portrait set/idx (gPortraitTiles, as load_bg0_tilemap) first. Returns 1 after the last frame.
// Runtime: message_clear_text_area calls it 9 frames in a row with (0, 4, 3, 5, ...) on the new game prompt.
u32 message_portrait_anim_step(u32 set, u32 idx, u32 x, u32 y, s32 anim, u32 reverse) {
    u8 ids[2];
    u8 *id_ptr = ids;

    *id_ptr++ = set;
    *id_ptr = idx;
    if (gGameWork.portraitAnimFrame == 0) {
        REG_DISPCNT |= 0x100;
        REG_BG0CNT = 0x500;
        lz_decompress_dispatch(gPortraitTiles[set][idx], (void *)0x06000F80);
        CpuFastSet(gPortraitPalettes[set], (void *)0x050001A0, 8);
    }
    if (reverse == 0)
        write_tilemap_rect(8, 8, x, y, gUiTilemaps[anim * 9 + gGameWork.portraitAnimFrame], REG_BG0CNT, 0);
    else
        write_tilemap_rect(8, 8, x, y, gUiTilemaps[mul9(anim) - sub8(gGameWork.portraitAnimFrame)], REG_BG0CNT, 0);
    if (++gGameWork.portraitAnimFrame == 9)
        return 1;
    return 0;
}
