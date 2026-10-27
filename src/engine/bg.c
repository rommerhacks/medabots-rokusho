// Background helpers: decompress a tilemap into a BG screen block or a RAM buffer, copy tilemap rectangles to
// VRAM, and the per-scanline BG2 affine parameters streamed by HBlank DMA 0 (hblank_dma0_bg2affine).

#include "global.h"

static void copy_tilemap_with_offset_08000F78(u16 *dst, struct Tilemap *map);
static void hblank_dma0_bg2affine(void);

void set_tilemap_and_decompress_bg(u32 x, u32 y, const u8 *src, u32 bgcnt, u16 base) {
    gTilemapBaseEntry = base;
    lz_decompress_dispatch(src, gDecompressBuffer);
    write_tilemap_to_vram_08000E94(x, y, (struct Tilemap *)gDecompressBuffer, bgcnt);
}

static void decompress_to_ewram_buffer(u32 x, u32 y, const u8 *src, u32 bgcnt) {
    lz_decompress_dispatch(src, gDecompressBuffer);
    load_tilemap_rows_to_vram(x, y, (struct Tilemap *)gDecompressBuffer, bgcnt);
}

static void decompress_to_bg_scroll_buffer(const u8 *src, void *dst) {
    u32 size = lz_decompress_dispatch(src, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, dst, size);
}

void write_tilemap_to_vram_08000E94(u32 x, u32 y, struct Tilemap *map, u32 bgcnt) {
    u16 *dst = (u16 *)((((bgcnt >> 8) & 0x1F) * 0x800) + VRAM) + x + y * 32;
    u16 *src = map->data;
    u16 *d;
    u32 i, j;

    if (((bgcnt & 0xC000) >> 14) & 1) {
        copy_tilemap_with_offset_08000F78(dst, map);
    } else {
        for (i = 0; i < map->height; i++) {
            d = dst + (i << 5);
            for (j = 0; j < map->width; j++)
                *d++ = *src++ + gTilemapBaseEntry;
        }
    }
}

void load_tilemap_rows_to_vram(u32 x, u32 y, struct Tilemap *map, u32 bgcnt) {
    u32 shift = ((bgcnt & 0xC000) >> 14) + 3;
    u8 *dst = (u8 *)((((bgcnt >> 8) & 0x1F) * 0x800) + VRAM) + x + (y << shift);
    u8 *src = (u8 *)map->data;
    u32 i;
    for (i = 0; i < map->height; i++) {
        CpuCopy16(src, (u16 *)dst + (i << shift), map->width);
        src += map->width;
    }
}

static void copy_tilemap_with_offset_08000F78(u16 *dst, struct Tilemap *map) {
    s32 w, hh;
    s32 i, j;
    u16 *s, *d;

    w = map->width;
    if (w > 32)
        w = 32;
    hh = map->height;
    if (hh > 32)
        do {
            hh = 32;
        } while (0);

    i = 0;
    do {
        if (i >= hh)
            break;
        s = &map->data[map->width * i];
        d = dst + i * 32;
        i++;
        for (j = 0; j < w; j++)
            *d++ = *s++ + gTilemapBaseEntry;
    } while (1);
    for (i = 0; i < hh; i++) {
        s = &map->data[i * map->width + 32];
        d = dst + 0x400 + i * 32;
        for (j = 32; j < map->width; j++)
            d[j - 32] = s[j - 32] + gTilemapBaseEntry;
    }
    for (i = 32; i < map->height; i++) {
        s = &map->data[map->width * i];
        d = dst + 0x400 + i * 32;
        for (j = 0; j < w; j++)
            *d++ = *s++ + gTilemapBaseEntry;
    }
    for (i = 32; i < map->height; i++) {
        s = &map->data[i * map->width + 32];
        d = dst + 0x800 + i * 32;
        for (j = 32; j < map->width; j++)
            d[j - 32] = s[j - 32] + gTilemapBaseEntry;
    }
}

// Note: writes the BG3 affine registers (0x04000030-0x0400003E), not BG2.
// pa/pd = cos * 0x400 / scale, pb/pc = +-sin * 0x400 / scale (scale 0x100 = 1:1), angle 1024 steps/turn;
// reference point X = -(pa * a4 + pb * a5) - a2, Y = -(pc * a4 + pd * a5) - a3.
static void set_bg2_affine_transform(s32 scale, u32 angle, s32 cx, s32 cy, s32 sx, s32 sy) {
    s32 pa, pb, pc, pd, x, y;

    pa = Div(gSineTableQ14[(angle & 0x3FF) + 0x100] * 4, scale);
    pb = Div(gSineTableQ14[(angle & 0x3FF)] * 4, scale);
    pc = Div(-gSineTableQ14[(angle & 0x3FF)] * 4, scale);
    pd = Div(gSineTableQ14[(angle & 0x3FF) + 0x100] * 4, scale);
    *(vu16 *)0x04000030 = pa;
    *(vu16 *)0x04000032 = pb;
    *(vu16 *)0x04000034 = pc;
    *(vu16 *)0x04000036 = pd;
    x = -(pa * sx) - pb * sy - cx;
    y = -(pc * sx) - pd * sy - cy;
    *(vu16 *)0x04000038 = x;
    *(vu16 *)0x0400003A = (x & 0x0FFF0000) >> 16;
    *(vu16 *)0x0400003C = y;
    *(vu16 *)0x0400003E = (y & 0x0FFF0000) >> 16;
}

// New local struct: one scanline of BG2 affine registers (BG2PA..BG2PD, BG2X, BG2Y), 16 bytes.
struct BgAffineLine {
    s16 pa, pb, pc, pd;
    u16 xl, xh, yl, yh;
};

// MATCH: the line pointer uses its own counter j (for i, j; i++, j++) so its increment lands after i++.
// Fills the back buffer (gBg2AffineScanlineBuffer2 on odd frames, gDecompressBuffer on even) with 160
// per-scanline BG2 affine sets whose zoom shrinks as 1 / (1 + line * step) (a perspective
// "floor" effect, Mode-7 like), then arms hblank_dma0_bg2affine for the next vblank.

static void compute_bg_affine_scanline_params(s32 step, u32 angle, s32 unused, s32 cx, s32 cy, s32 sx, s32 sy) {
    struct BgAffineLine *buf;
    s32 i, j;
    s32 pa, pb, pc, pd, x, y, t;

    if (!(gFrameCounter & 1))
        buf = (struct BgAffineLine *)gDecompressBuffer;
    else
        buf = (struct BgAffineLine *)gBg2AffineScanlineBuffer2;
    for (i = 0, j = 0; i < 160; i++, j++) {
        pa = DivArm(i * step + 1, gSineTableQ14[(angle & 0x3FF) + 0x100] << 7);
        t = DivArm(i * step + 1, gSineTableQ14[angle & 0x3FF] << 7);
        pc = -t;
        pb = t * 3;
        pd = pa * 3;
        buf[j].pa = pa;
        buf[j].pb = pb;
        buf[j].pc = pc;
        buf[j].pd = pd;
        x = -(pa * sx) - pb * sy - cx + pb * i;
        y = -(pc * sx) - pd * sy - cy + pd * i;
        buf[j].xl = x;
        buf[j].xh = x >> 16;
        buf[j].yl = y;
        buf[j].yh = y >> 16;
    }
    gVBlankOnceCallback = hblank_dma0_bg2affine;
}

// Run once at vblank (gVBlankOnceCallback, set by compute_bg_affine_scanline_params): copies line 0 of the current
// (double-buffered) BG2 affine table to BG2PA..BG2Y, then starts DMA0 (hblank-triggered, repeat, 8 halfwords) to feed
// the rest of the lines.
static void hblank_dma0_bg2affine(void) {
    vu32 *dma = (vu32 *)REG_ADDR_DMA0;
    vu16 *dst = (vu16 *)0x04000020;
    u16 *src;

    if (gFrameCounter & 1)
        src = (u16 *)gDecompressBuffer;
    else
        src = (u16 *)gBg2AffineScanlineBuffer2;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
    dst[6] = src[6];
    dst[7] = src[7];
    REG_DMA0CNT_H = 0;
    dma[0] = (u32)(src + 8);
    dma[1] = (u32)dst;
    dma[2] = 0xA2600008;
}

// Stops the per-scanline affine DMA (unreferenced).
static void affine_dma_stop(void) {
    REG_DMA0CNT_H = 0;
}
