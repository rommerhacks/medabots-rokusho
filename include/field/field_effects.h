#ifndef GUARD_FIELD_FIELD_EFFECTS_H
#define GUARD_FIELD_FIELD_EFFECTS_H

// Field helpers: metatile/tilemap rects, OAM affine, sprite animation frames, random, blend effects and palette fades,
// u8 sort

void memzero_bytes(u8 *dst, u32 size);
u32 run_blend_fade_transition(u16 a);
void game_substate_advance(void);
void setup_palette_fade_to_color(u16 color, float a, float b, float c);
void setup_palette_fade_to_color_with_obj(u16 color, float a, float b, float c);
void sprite_anim_start(u8 slot, u8 anim_id);
void advance_sprite_animation_frame(u8 idx);
u8 field_random(u8 n); // returns 0..n-1
void memcpy_u8(const void *src, void *dst, u32 n);
void affine_params_reset(void);
void calculate_oam_affine_matrix(u8 i);
void setup_blend_effect(u8 mode, u16 bldcnt, u8 type, u8 eva_frames, u8 evb_frames, u8 evy_frames, u8 target_eva,
                        u8 target_evb, u8 target_evy);
u32 blend_effect_update(void);
void clear_entity_state(u8 slot);
void memset_bytes(u8 *dst, u32 n, u8 val);
void field_bg_palettes_blend_masked(u16 a, u32 b, u16 c);
void field_obj_palettes_blend_masked(u16 a, u32 b, u16 c);
void field_palette_backup(void);
void build_bg_tile_entry(u16 *dst, u16 id, u16 base, u16 y, u16 x, u16 yoff, u16 xoff);
void copy_tilemap_rect_with_offset(u16 *src, u16 *dst, s32 y, s32 x, s32 w, s32 h, s32 unused6, s32 unused7, s32 add,
                                   s32 mode);
void copy_tilemap_region(u16 *src, u16 *dst, s32 y, s32 x, s32 w, s32 h, s32 add, s32 pal, s32 mode);
void fill_tilemap_rect(u16 *dst, s32 y, s32 x, s32 w, s32 h, s32 tile, s32 pal, s32 mode);
void field_palettes_blend_to_color(u16 color, u32 amount);

#endif // GUARD_FIELD_FIELD_EFFECTS_H
