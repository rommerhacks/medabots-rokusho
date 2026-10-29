#ifndef GUARD_ENGINE_BG_DRAW_H
#define GUARD_ENGINE_BG_DRAW_H

// BG clears and number drawing on BG tilemaps

void free_all_sprites(void);                   // clears flags of the 128 gSpriteEntries sprites
void draw_number_3digits(s32 n, s32 x, s32 y); // 3 digits, blank-padded, BG tilemap 0x0600F000 (item list page numbers)
void draw_number_2digits_tall(s32 n, s32 x, s32 y);
void draw_number(u16 value, s32 width, u8 x, u8 y, u8 pal, u8 bg);
void draw_number_tall(u16 value, s8 w, u8 x, u8 y, u8 pal, u8 bg);

#endif // GUARD_ENGINE_BG_DRAW_H
