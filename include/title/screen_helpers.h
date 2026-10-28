#ifndef GUARD_TITLE_SCREEN_HELPERS_H
#define GUARD_TITLE_SCREEN_HELPERS_H

// Title-mode helpers: sprite wave, tilemap decompress, multiplayer id

void decompress_and_write_tilemap(
    const void *src,
    u32 bgcnt); // LZ77 tilemap with a w, h header (u32 each, 16-byte header) into the BG screen block of bgcnt
void init_multiplayer_id(void);
void keys_update_from(u16 keys); // link: gNewKeys / gReleasedKeys from the other player's keys
void tilemap_offset_tiles_and_palette(u32 tiles, u32 palette,
                                      u32 blk); // (u16, u8, u8): callers pass full ints; adds tiles to the tile
void update_battle_sprite_priority_flags(void);
u32 town_map_move_cursor(void);

#endif // GUARD_TITLE_SCREEN_HELPERS_H
