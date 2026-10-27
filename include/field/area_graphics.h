#ifndef GUARD_FIELD_AREA_GRAPHICS_H
#define GUARD_FIELD_AREA_GRAPHICS_H

// Area BG scroll, animated tiles, terrain graphics and palettes

u32 field_update_music(u32 a, u32 b);
void sprite_entry_clear(u8 slot);
void area_load_bg_palettes(void);
void animate_area_bg_tiles(void);
u32 area_sprite_sheet_id(u32 arg);
void sprite_set_blend_from_kind(u8 idx);
void sprite_entry_init(u8 idx, u16 attr, u32 frame, u8 a3, u8 a4);
void area_load_sprite_sheets(void);
void area_load_sprite_palettes_now(void);
void area_load_sprite_palettes(void);
void area_load_graphics(void);
void blend_set_alpha_12_10(void);
u8 area_song_id(void);
s32 resolve_sprite_sheet_id(s32 t);
void fill_sprite_sheets(s32 arg);
void fill_sprite_palettes(s32 arg);

#endif // GUARD_FIELD_AREA_GRAPHICS_H
