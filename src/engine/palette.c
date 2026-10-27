// Palette backup (gPaletteBackup / gPaletteBackupBg) and blends / fades of OBJ and BG palettes toward a
// colour, uploaded to palette RAM by DMA.

#include "global.h"

void palette_backup_from_hardware(void) {
    CpuFastSet((void *)OBJ_PLTT, gPaletteBackup, 0x80);
    CpuFastSet((void *)PLTT, gPaletteBackupBg, 0x80);
}

void palettes_blend_to_color(u16 color, u32 amount) {
    u32 i;
    u32 inv;
    if (amount > 32)
        amount = 32;
    inv = 32 - amount;
    for (i = 0; i < 0x200; i++) {
        u16 *dst = &gPaletteBuffer[i];
        u16 *src = &gPaletteBackup[i];
        *dst = (((*src & 0x1F) * inv + (color & 0x1F) * amount) >> 5) |
               ((((*src & 0x3E0) * inv + (color & 0x3E0) * amount) >> 5) & 0x3E0) |
               ((((*src & 0x7C00) * inv + (color & 0x7C00) * amount) >> 5) & 0x7C00);
    }
    gVBlankOnceCallback = palette_buffer_upload;
}

void palette_buffer_upload(void) {
    CpuFastSet(gPaletteBuffer, (void *)OBJ_PLTT, 0x80);
    CpuFastSet(gPaletteBufferBg, (void *)PLTT, 0x80);
}

static void palette_blend_16_colors(u16 *src, u16 *dst, u16 color, u32 amount) {
    u32 i;
    u32 inv;
    if (amount > 32)
        amount = 32;
    inv = 32 - amount;
    for (i = 0; i < 16; i++) {
        dst[i] = (((color & 0x1F) * amount + (src[i] & 0x1F) * inv) >> 5) |
                 ((((src[i] & 0x3E0) * inv + (color & 0x3E0) * amount) >> 5) & 0x3E0) |
                 ((((color & 0x7C00) * amount + (src[i] & 0x7C00) * inv) >> 5) & 0x7C00);
    }
}
