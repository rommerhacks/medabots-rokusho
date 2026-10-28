#ifndef GUARD_ENGINE_PALETTE_BLEND_H
#define GUARD_ENGINE_PALETTE_BLEND_H

// Palette buffer blends towards a color

void bg_palettes_blend_masked_now(u16 color, u32 amount, u16 mask);
void obj_palettes_blend_masked_now(u16 color, u32 amount, u16 mask);

#endif // GUARD_ENGINE_PALETTE_BLEND_H
