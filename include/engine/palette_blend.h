#ifndef GUARD_ENGINE_PALETTE_BLEND_H
#define GUARD_ENGINE_PALETTE_BLEND_H

// Palette buffer blends towards a color

void bg_palettes_blend_masked_now(u16 a, u32 b, u16 c);
void obj_palettes_blend_masked_now(u16 a, u32 b, u16 c);

#endif // GUARD_ENGINE_PALETTE_BLEND_H
