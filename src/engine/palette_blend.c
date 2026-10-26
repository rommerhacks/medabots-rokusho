// Palette blends: mix the backed-up BG / OBJ palettes (gPaletteBackupBg ..) towards a color by
// amount / 32 for the palettes selected in a 16-bit mask, into the palette buffers or straight to PLTT.
// The screen fades of the menus, battle and field call these every frame.

#include "global.h"

static inline void flush_pal(const void *s) {
    CpuFastSet(s, (void *)PLTT, 0x80);
}

void blend_obj_palettes_to_color_0803F684(u16 color, u32 amount, u16 mask) {
    u32 i, j;
    u32 inv;
    u16 bit = 1;
    if (amount > 32)
        amount = 32;
    inv = 32 - amount;
    for (i = 0; i < 16; i++) {
        if (mask & bit) {
            for (j = 0; j < 16; j++) {
                u16 *dst = &gPaletteBufferBg[i * 16 + j];
                u16 *src = &gPaletteBackupBg[i * 16 + j];
                *dst = (((*src & 0x1F) * inv + amount * (color & 0x1F)) >> 5) |
                       ((((*src & 0x3E0) * inv + amount * (color & 0x3E0)) >> 5) & 0x3E0) |
                       ((((*src & 0x7C00) * inv + amount * (color & 0x7C00)) >> 5) & 0x7C00);
            }
        } else {
            for (j = 0; j < 16; j++)
                gPaletteBufferBg[i * 16 + j] = gPaletteBackupBg[i * 16 + j];
        }
        bit <<= 1;
    }
    flush_pal(gPaletteBufferBg);
}

static void blend_obj_palettes_to_color_0803F788(u16 color, u32 amount, u16 mask) {
    u32 i, j;
    u32 inv;
    u16 bit = 1;
    if (amount > 32)
        amount = 32;
    inv = 32 - amount;
    for (i = 0; i < 16; i++) {
        if (mask & bit) {
            for (j = 0; j < 16; j++) {
                u16 *dst = &gPaletteBufferBg[i * 16 + j];
                u16 *src = &gPaletteBackupBg[i * 16 + j];
                *dst = (((*src & 0x1F) * inv + amount * (color & 0x1F)) >> 5) |
                       ((((*src & 0x3E0) * inv + amount * (color & 0x3E0)) >> 5) & 0x3E0) |
                       ((((*src & 0x7C00) * inv + amount * (color & 0x7C00)) >> 5) & 0x7C00);
            }
        } else {
            for (j = 0; j < 16; j++)
                gPaletteBufferBg[i * 16 + j] = gPaletteBackupBg[i * 16 + j];
        }
        bit <<= 1;
    }
    gVBlankOnceCallback = dma_obj_palette_to_hardware;
}

static void palette_blend_to_color_0803F890(u16 color, u32 amount, u16 mask) {
    u32 i, j;
    u32 inv;
    u16 bit = 1;
    if (amount > 32)
        amount = 32;
    inv = 32 - amount;
    for (i = 0; i < 16; i++) {
        if (mask & bit) {
            for (j = 0; j < 16; j++) {
                u16 *dst = &gPaletteBuffer[i * 16 + j];
                u16 *src = &gPaletteBackup[i * 16 + j];
                *dst = (((*src & 0x1F) * inv + amount * (color & 0x1F)) >> 5) |
                       ((((*src & 0x3E0) * inv + amount * (color & 0x3E0)) >> 5) & 0x3E0) |
                       ((((*src & 0x7C00) * inv + amount * (color & 0x7C00)) >> 5) & 0x7C00);
            }
        } else {
            for (j = 0; j < 16; j++)
                gPaletteBuffer[i * 16 + j] = gPaletteBackup[i * 16 + j];
        }
        bit <<= 1;
    }
    gVBlankOnceCallback = dma_obj_palette_to_hardware;
}

static inline void flush_obj_pal(const void *s) {
    CpuFastSet(s, (void *)OBJ_PLTT, 0x80);
}
void blend_obj_palettes_to_color_0803F998(u16 color, u32 amount, u16 mask) {
    u32 i, j;
    u32 inv;
    u16 bit = 1;
    if (amount > 32)
        amount = 32;
    inv = 32 - amount;
    for (i = 0; i < 16; i++) {
        if (mask & bit) {
            for (j = 0; j < 16; j++) {
                u16 *dst = &gPaletteBuffer[i * 16 + j];
                u16 *src = &gPaletteBackup[i * 16 + j];
                *dst = (((*src & 0x1F) * inv + amount * (color & 0x1F)) >> 5) |
                       ((((*src & 0x3E0) * inv + amount * (color & 0x3E0)) >> 5) & 0x3E0) |
                       ((((*src & 0x7C00) * inv + amount * (color & 0x7C00)) >> 5) & 0x7C00);
            }
        } else {
            for (j = 0; j < 16; j++)
                gPaletteBuffer[i * 16 + j] = gPaletteBackup[i * 16 + j];
        }
        bit <<= 1;
    }
    flush_obj_pal(gPaletteBuffer);
}
