#ifndef GUARD_FIELD_AREA_GRAPHICS_H
#define GUARD_FIELD_AREA_GRAPHICS_H

// Area BG scroll, animated tiles, terrain graphics and palettes

u32 field_update_music(u32 event, u32 song);
void sprite_entry_clear(u8 slot);
void area_load_bg_palettes(void);
void animate_area_bg_tiles(void);
u32 area_sprite_sheet_id(u32 slot);
void sprite_set_blend_from_kind(u8 idx);
void sprite_entry_init(u8 slot, u16 flags, u32 frame, u8 palette, u8 frame_table);
void area_load_sprite_sheets(void);
void area_load_sprite_palettes_now(void);
void area_load_sprite_palettes(void);
void area_load_graphics(void);
void blend_set_alpha_12_10(void);
u8 area_song_id(void);
s32 resolve_sprite_sheet_id(s32 sheet_id);
void fill_sprite_sheets(s32 sheet_code);
void fill_sprite_palettes(s32 sheet_code);

#endif // GUARD_FIELD_AREA_GRAPHICS_H
