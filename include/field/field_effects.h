#ifndef GUARD_FIELD_FIELD_EFFECTS_H
#define GUARD_FIELD_FIELD_EFFECTS_H

// Field helpers: metatile/tilemap rects, OAM affine, sprite animation frames, random, blend effects and palette fades,
// u8 sort

void memzero_bytes(u8 *dst, u32 size);
u32 run_blend_fade_transition(u16 a);
void sub_0804A1C4(void);
void setup_palette_fade_to_color(u16 color, float a, float b, float c);
void setup_palette_fade_to_color_with_obj(u16 color, float a, float b, float c);
void sub_080493D4(u8 idx, u8 val);
void advance_sprite_animation_frame(u8 idx);
u8 field_random(u8 n); // returns 0..n-1
void memcpy_u8(const void *src, void *dst, u32 n);
void sub_080492CC(void);
void calculate_oam_affine_matrix(u8 i);
void setup_blend_effect(u8 mode, u16 bldcnt, u8 type, u8 sa, u8 sb, u8 sy, u8 a, u8 b, u8 y);
u32 blend_effect_update(void);
void clear_entity_state(u8 slot);
void memset_bytes(u8 *dst, u32 n, u8 val);
void sub_08049E74(u16 a, u32 b, u16 c);
void sub_08049E88(u16 a, u32 b, u16 c);
void sub_08049CC0(void);
void build_bg_tile_entry(u16 *dst, u16 id, u16 base, u16 y, u16 x, u16 yoff, u16 xoff);
void copy_tilemap_rect_with_offset(u16 *src, u16 *dst, s32 y, s32 x, s32 w, s32 h, s32 unused6, s32 unused7, s32 add,
                                   s32 mode);
void copy_tilemap_region(u16 *src, u16 *dst, s32 y, s32 x, s32 w, s32 h, s32 add, s32 pal, s32 mode);
void fill_tilemap_rect_0804916C(u16 *dst, s32 y, s32 x, s32 w, s32 h, s32 tile, s32 pal, s32 mode);
void sub_08049CB0(u16 color, u32 amount);

#endif // GUARD_FIELD_FIELD_EFFECTS_H
