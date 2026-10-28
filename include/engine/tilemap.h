#ifndef GUARD_ENGINE_TILEMAP_H
#define GUARD_ENGINE_TILEMAP_H

// Tilemap rectangles, BG tile decompression, BG0 layer and portrait tiles

void tilemap_fill_rect(u32 w, u32 h, u32 x, u32 y, u32 bgcnt,
                       u16 tile); // fills a rectangle of the BG map at bgcnt's screen base
void load_bg0_tilemap(u32 set, u32 idx, u32 x, u32 y, u32 anim);
void write_tilemap_rect(u32 w, u32 h, u32 x, u32 y, const void *src, u32 bgcnt, u32 base);
void write_tilemap_to_vram_0803F1C8(u32 w, u32 h, u32 x, u32 y, const void *src, u32 bgcnt, u32 base);
void vram_fill_tilemap_rect(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, u16 value);
u32 message_portrait_anim_step(u32 set, u32 idx, u32 x, u32 y, s32 anim, u32 reverse);
void decompress_indexed_asset(u32 set, u32 idx, void *dst, u32 pal, u32 toBuffer);
void decompress_bg_tiles_to_vram_bg(void);
void setup_bg0_display_layer(void);

#endif // GUARD_ENGINE_TILEMAP_H
