// Palette blends: mix the backed-up BG / OBJ palettes (gPaletteBackupBg ..) towards a color by
// amount / 32 for the palettes selected in a 16-bit mask, into the palette buffers or straight to PLTT.
// The screen fades of the menus, battle and field call these every frame.

#include "global.h"

static inline void flush_pal(const void *src) {
    CpuFastSet(src, (void *)PLTT, 0x80);
}

void bg_palettes_blend_masked_now(u16 color, u32 amount, u16 mask) {
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

static void bg_palettes_blend_masked(u16 color, u32 amount, u16 mask) {
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
    gVBlankOnceCallback = palette_buffer_upload;
}

static void obj_palettes_blend_masked(u16 color, u32 amount, u16 mask) {
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
    gVBlankOnceCallback = palette_buffer_upload;
}

static inline void flush_obj_pal(const void *src) {
    CpuFastSet(src, (void *)OBJ_PLTT, 0x80);
}
void obj_palettes_blend_masked_now(u16 color, u32 amount, u16 mask) {
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
