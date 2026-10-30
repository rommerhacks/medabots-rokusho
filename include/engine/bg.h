#ifndef GUARD_ENGINE_BG_H
#define GUARD_ENGINE_BG_H

// BG tilemap loading and the per-scanline BG2 affine DMA.

void set_tilemap_and_decompress_bg(u32 x, u32 y, const u8 *src, u32 bgcnt, u16 base);
void write_tilemap_with_base(u32 x, u32 y, struct Tilemap *map, u32 bgcnt);
void load_tilemap_rows_to_vram(u32 x, u32 y, struct Tilemap *map, u32 bgcnt);

#endif // GUARD_ENGINE_BG_H
