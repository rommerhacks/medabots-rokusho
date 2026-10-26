#ifndef GUARD_ENGINE_PALETTE_H
#define GUARD_ENGINE_PALETTE_H

// Palette backup, fades and blends.

void copy_obj_palette_to_buffer(void);
void palette_blend_to_color_080013A8(u16 color, u32 amount);
void dma_obj_palette_to_hardware(void);

#endif // GUARD_ENGINE_PALETTE_H
