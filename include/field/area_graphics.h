#ifndef GUARD_FIELD_AREA_GRAPHICS_H
#define GUARD_FIELD_AREA_GRAPHICS_H

// Area BG scroll, animated tiles, terrain graphics and palettes

u32 dispatch_jump_table_29(u32 a, u32 b);
void clear_battle_sprite_entry(u8 slot);
void sub_080482C0(void);
void animate_area_bg_tiles(void);
u32 resolve_tile_from_battle_state(u32 arg);
void sub_0804877C(u8 idx);
void init_battle_sprite_entry_08048818(u8 idx, u16 attr, u32 frame, u8 a3, u8 a4);
void decompress_battle_tile_graphics(void);
void dma_load_obj_palettes_08048664(void);
void dma_load_battle_palettes(void);
void update_battle_field_frame(void);
void sub_080487E4(void);
u8 sub_080483AC(void);
s32 sub_080481C4(s32 t);
void decompress_terrain_tiles_to_vram(s32 arg);
void dma_load_obj_palettes_08048730(s32 arg);

#endif // GUARD_FIELD_AREA_GRAPHICS_H
