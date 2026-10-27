#ifndef GUARD_ENGINE_COMMON_H
#define GUARD_ENGINE_COMMON_H

// Shared helpers for menus and battles

void lz_decompress(const u8 *src, void *dst); // wrapper of lz_decompress_dispatch
u32 resolve_area_sprite_set(u8 set);          // guess: 0 = the current area's default (gUnk_083B2970[player_form])
void draw_number_tall_bgcnt(u32 value, u32 x, u32 y, u8 digits, u32 bgcnt,
                            u16 base); // last `digits` digits of value as 2-row tiles (base + d * 2 / + 1)
u32 skill_type_is_remote(u32 type);    // 1 for skill types 2, 3, 6, 7 ("Remote Medaparts"), 0 for proximity
s32 rng_next_byte(void);
void load_part_data(u32 part, u32 kind, u8 *dst);
struct Vec16 compute_polar_to_screen_position(u32 angle, u32 radius, u32 cx, u32 cy, u32 a, u32 b);
u32 find_medabot_slot_by_medal(u8 medal); // team slot (gUnk_030017A0) holding Medal id `medal`, or 0xFF
void decompress_sprite_to_vram_08042D94(u32 a, u32 b, u32 c, u32 d, u32 slot);
void init_battle_medabot_sprites(
    u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j,
    u32 k); // creates the 4 part sprites of a Medabot (head, arms, legs) at sprite..sprite+3
void setup_battle_sprite_group(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j,
                               u32 k); // refreshes the 4 part sprites set up by init_battle_medabot_sprites
u32 find_next_free_medal(
    vu32 medal,
    vu32 backward); // previous or next owned Medal not in a Medabot (gUnk_03000BE0 bit 7 set, bit 6 clear), 30 if none
u32 find_next_available_medapart_slot(u32 part, u32 kind, u32 backward,
                                      u32 d); // next / previous owned Medapart id of gender d; d + 0x78 if none
void init_scene_buffers_080445F4(void);
void setup_scene_with_bg_and_sprites(); // (u32 slot, u8 head, u8 rarm, u8 larm, u8 legs, u16 y, u16 x, u32 f, u8 g, u8
void draw_medabot_sprite();             // (u32 slot, u8 head, u8 rarm, u8 larm, u8 legs, u16 y, u16 x, u32 f, u8 g, u8
u32 medabot_pose_anim_step(u32 a0, u32 a1, u32 a2);
u32 medabot_detail_is_full_set(void); // 1 if gUnk_03000440.unk98-9B (the four shown Medaparts) are all the same set
u32 count_assembled_medabots(void);   // team slots (gUnk_030017A0) with state 3
void battle_sprite_group_set_anim(u32 sprite, u32 anim); // sets anim script unk24 on the 4 sprites from sprite
void update_battle_sprite_orbiting_positions(
    u32 sprite, u32 idx,
    u32 c); // guess: idle animation of a part-sprite Medabot (legs anchor, arms swing on a circle, head bobs)
u32 validate_medapart_stats(u8 medal, u8 head, u8 rarm, u8 larm, u8 legs);
void modify_medapart_quantity(u32 id, u32 kind, u32 byte, u32 subtract,
                              u32 n); // byte 0 or 1 of the Medapart (id, kind): -= n, or += n capped at 99
void fill_tilemap_pair_or_divide(
    u8 value, u8 x, u8 y, u32 bgcnt,
    u16 entry); // guess: draws a 2-digit number with 1x2 tiles (0xFF: blank, >= 100: fixed tiles)
void draw_tilemap_with_offset(u32 id, u32 x, u32 y, u32 bgcnt, u16 flags);
void clear_bg_scroll(void);
void decompress_tileset_to_vram(u32 id, u32 arg);
void apply_battle_blend_effect_a(void);
void update_scroll_movement_a(void);
void give_starter_medabot(void); // team slot 0: Medal 0 with the four 0x2A parts
void load_battlefield_data_to_buffer(void);
u32 check_random_encounter(void);
void start_scanline_wave_scroll(u32 phase, s32 amplitude, u32 lines); // sine-wave BG0-3 x scroll on the top `lines`
void draw_number_bgcnt(u32 n, u32 x, u32 y, u32 digits, u32 bgcnt, u32 tile); // last `digits` digits, leading 0s blank
void fill_text_blank(u8 *buf, u8 n);
void draw_tile_block(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, u16 entry);
void return_to_field(void); // field sub-state 7: restore script sprites, resume the map
void set_blend_effect_mode(u8 mode, u16 targets, u16 speed);
u32 update_blend_effect(void); // 1 once the effect set up by set_blend_effect_mode is done
s32 rng_percent(void);         // random 0-100
void setup_sprite_animation_entry(u32 a, u8 id, u8 kind, u16 y, u16 x, u32 f, u8 g, u8 h, u8 i);
void load_battle_script_entry_b(void);
void apply_battle_blend_effect_b(void);
void decompress_to_ewram_27000(const u8 *src);
void battle_vblank_update_bg(
    void); // battle gVBlankCallback: BG scroll movement (unk74) + battlefield tile animation (runtime-checked)
void read_vram_tilemap_rect(u32 w, u32 h, u32 x, u32 y, u32 bgcnt,
                            void *dst); // w x h tiles at (x, y) of the BG map selected by bgcnt
void write_vram_tilemap_rect(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, const void *src);
void draw_count_over_max(u32 cur, u32 max, u32 x, u32 y, u32 tile, u32 bgcnt,
                         u16 tile2); // draws cur/max as two 2-digit numbers
void update_sprite_animation_position(u32 slot);
u32 calculate_direction_index(
    s32 x, s32 y, s32 tx,
    s32 ty); // direction from (x, y) to (tx, ty), stored in sprite unk25 (move_sprite_toward_target)
struct Coords16 calc_polar_to_screen_coords(u32 angle, u32 radius, s32 x,
                                            s32 y); // returned in memory (hidden pointer in r0)
void battle_bg_scroll_vblank(void);                 // gVBlankCallback: BG2/BG3 scroll movement (unk39)
void advance_battle_animation_frame(u32 field);     // steps the battlefield tile animation (gUnk_03001800.unk7C-7F)
void race_enter_team_select(void);
void decompress_sprite_to_vram_08043C08(u32 idx, u32 backup);
void init_battle_scene(u32 mode, u32 id);
void init_game_mode(u32 mode);
u32 medaparts_all_equipped(void); // 1 if no Medapart has a spare copy (owned == in use)

#endif // GUARD_ENGINE_COMMON_H
