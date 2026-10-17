#ifndef GUARD_FUNCTIONS_H
#define GUARD_FUNCTIONS_H

// Prototypes for game functions (decompiled or still in asm), in ROM order.

u32 lz_decompress_dispatch(const u8 *src, void *dst);
void set_tilemap_and_decompress_bg(u32 x, u32 y, const u8 *src, u32 bgcnt, u16 base);
void copy_obj_palette_to_buffer(void);
void palette_blend_to_color_080013A8(u16 color, u32 amount);
void medawatch_menu_load_icon(void);
void medawatch_menu_init_cursor(void);
void medawatch_scroll_bg3(void);
void medabots_scroll_bg3(void);
void sub_08004E98(void);
void update_battle_sprite_orbit_clockwise(u32 i);
void sub_08004FD0(void);
void sub_08005000(void);
void sub_0800508C(void);
void sub_08005118(void);
void sub_0800519C(void);
void sub_0800522C(void);
void sub_080053C8(void);
void update_battle_sprite_orbit_counterclockwise(u32 i);
void sub_0800529C(void);
void setup_overworld_scene_from_position(void);
u32 medabots_screen_cursor_input(void);
void medabots_screen_start_reorder_orbit(void);
void update_battle_icon_blink_and_orbit(void);
u32 medabots_screen_reorder_input(void);
void sub_08005948(void);
void check_and_update_battle_sprite_orbit(void);
void sub_080059D0(void);
void sub_08005AD0(void);
void sub_08005B44(void);
void sub_08005BB4(void);
void sub_08005C10(void);
void medabot_detail_draw_head_name(void);
void medabot_detail_draw_head_skill_icon(void);
void medabot_detail_draw_rarm_name(void);
void medabot_detail_draw_rarm_skill_icon(void);
void medabot_detail_draw_larm_name(void);
void medabot_detail_draw_larm_skill_icon(void);
void medabot_detail_draw_legs_name(void);
void medabot_detail_draw_legs_skill_icon(void);
void medabot_detail_draw_row_icon_0(u32 a);
void medabot_detail_draw_row_icon_1(u32 a);
void medabot_detail_draw_row_icon_2(u32 a);
void medabot_detail_draw_row_icon_3(u32 a);
void medabot_detail_draw_row_icon_4(u32 a);
void medabot_detail_draw_legs_type_icon(void);
void decompress_sprite_from_game_state(void);
void setup_battle_sprite_from_game_state(void);
void medabot_detail_place_row_arrows(void);
void medabot_detail_blink_row_arrows(void);
void init_scene_state(void);
void setup_scene_with_link_check(void);
void sub_08006764(void);
void medabot_detail_blink_row_icon(void);
u32 medabot_detail_row_cursor_input(void);
u32 medabot_detail_cycle_medal_input(void);
u32 medabot_detail_cycle_head_input(void);
u32 medabot_detail_cycle_rarm_input(void);
u32 medabot_detail_cycle_larm_input(void);
u32 medabot_detail_cycle_legs_input(void);
u32 medabot_detail_equip_full_set_input(void);
u32 medabot_detail_prev_part_id(u32 part); // previous Medapart id: 0 wraps to 120 + slot unk1, >= 120 clamps to 119
void battle_update_medabot_display(void);
void sub_08006F14(void);
u8 medabot_detail_check_row_select(void);
void count_unequipped_medals(void);
void assign_medal_to_team_slot(void);
void team_select_draw_pick_markers(void);
void medabots_screen_cancel_input(void);
u32 team_select_slot_not_picked(u32 n);
void team_select_confirm_pick(void);
void team_select_finish_input(void);
void sub_08007480(void);
void sub_0800750C(void);
void sub_08007540(void);
// code_08008430: Medals screen (game state 4) drawing helpers
void medals_scroll_bg(void);
void medals_list_set_cursor_from_medal(void);
void count_owned_medals(void);
void render_medal_sprite_tile(void);
void render_medal_list_entries(void);
void render_medal_slots_in_menu(void);
void render_medal_name_display(void);
void load_medal_sprite(void);
void render_medal_level_display(void);
void medals_list_init_tab_arrows(void);
void medals_list_init_cursor(void);
void medals_list_blink_tab_arrows(void);
void medals_list_row_input(void);
void medals_list_tab_input(void);
void update_battle_sprite_visibility(void);
void medals_list_swap_input(void);
void decompress_active_medal_sprite(void);
void init_active_medal_battle_sprites(void);
void draw_medal_position_tile(void);
u32 get_medal_active_slot(u8 medal);
void medal_page_draw_icon(void);
void medal_page_draw_kind_name(void);
void medal_page_draw_name(void);
void medal_skill_draw_icon(void);
void medal_page_draw_level(void);
void medal_skill_draw_level(void);
void medal_ability_draw_attribute(void);
void medal_ability_draw_aim(void);
void medal_ability_draw_compatibility(void);
void medal_page_init_medal_arrows(void);
void medal_page_blink_medal_arrows(void);
void medal_page_cycle_medal_input(void);
void medal_ability_redraw(void);
void medal_medaforce_draw_list(void);
void medal_medaforce_draw_selected(void);
void medal_medaforce_init_cursor(void);
u32 medal_medaforce_cursor_input(void);
u32 medal_medaforce_redraw(void);
u32 medal_medaforce_get_selected(void);
void sub_0800AA1C(void); // guess: Medals help cursor sprite (layout gUnk_083B7EBC[unk43], entry unk44)
void sub_0800AAC0(void); // guess: moves the Medals help cursor sprite to entry unk44
void sub_0800AB0C(void); // guess: draws the 8 Rotation entries (greyed past Medal unk9)
void sub_0800ABA4(void); // guess: Rotation page frame tilemap for unk9 entries
void medal_rotation_redraw(void);
void sub_0800AC2C(void); // guess: Rotation edit arrows above/below slot unk46
void sub_0800ACA8(void); // guess: Rotation page end marker sprite at entry unk9
void sub_0800AD00(void); // guess: blinks the Rotation edit arrows
u32 sub_0800AD58(void); // guess: UP/DOWN cycles Rotation entry unk46 (0-7), returns 1 on change
u32 sub_0800ADE8(void); // guess: LEFT/RIGHT moves the Rotation slot cursor unk46 (0-7)
u32 sub_0800AE54(void); // guess: LEFT/RIGHT changes the Rotation entry count (Medal unk9, 0-7)
void sub_0800AED0(void); // guess: loads the parts graphics of the Medabot holding the Medal
void sub_0800AF0C(void); // guess: shows the Medabot holding the Medal (sprites 0x64..)
void sub_0800AF64(void); // guess: draws the legs type of the Medabot holding the Medal
void render_medal_skill_stats(void);
void sub_0800B0F8(void); // guess: copies animation frame unk3F of a 5-tile strip (gUnk_084C3B14)
void draw_medal_skill_bars(void);
void sub_0800B130(void); // guess: animates that strip, a frame every 2 ticks after 180 ticks
void medal_skill_redraw(void);
void sub_0800B498(void); // guess: copies the Medal's Rotation (unk9, unk18) into gUnk_03000590[gUnk_03001800.unk80]
void setup_battle_cursor_sprite_0800B5E8(void);
void init_battle_cursor_sprite_0800B668(void);
u32 update_battle_sprite_and_check_done(void);
void handle_menu_cursor_updown(void);
// Debug menu (game mode 0, game state 63; labels in gDebugMenuLabels). Runtime-checked: "Process" sets
// gGameMode / gGameState / gGameSubState and jumps there.
void debug_menu_update(void);
void debug_menu_init(void);
void debug_menu_select_input(void);
void debug_menu_exit(void);
void debug_menu_run_entry(void);
void debug_process_update(void);
void debug_process_input(void);
void debug_medal_update(void);
void debug_medal_input(void); // rows: give Medal id, remove Medal id, give all 30
void debug_parts_update(void);
void debug_parts_input(void); // rows: give Medapart id (all 4 kinds), take one, give all 120
void debug_tinpet_update(void);
void debug_tinpet_input(void); // one row toggled 0/1, A: add_position_entry(value) unless sub_08042218()
void debug_item_update(void);
void debug_item_input(void); // rows: give item id, take one, give all 63
void debug_face_update(void);
void debug_face_input(void); // rows: portrait 0-0xAF, expression 0-8; A draws it twice with load_bg0_tilemap
void debug_mdlpic_update(void);
void debug_mdlpic_input(void); // rows: Medal graphic 0-29, sprite variant 0-4; A shows the Medal sprite
void debug_rndtk_update(void);
void debug_rndtk_input(void); // toggles gUnk_030057E0.unkC2C
void debug_battle_update(void);
void debug_battle_input(void); // A: unkC2A = id, starts game state 6 (Robattle intro)
void debug_sound_update(void);
void debug_sound_input(void); // rows: sound effect 0-0x7F, song 0-0x35; B stops the music
void debug_motion_update(void);
void debug_motion_init(void);
void debug_motion_load(void);
void debug_motion_input(void); // START / SELECT change the Medabot model (unk39), A plays animation unk35[0]
void debug_motion_play(void);
void medaparts_scroll_bg(void);
void sub_08010040(void); // guess: inits the 3-choice cursor sprite 4 (row gUnk_03000440.unk4A)
void sub_080100BC(void); // guess: UP/DOWN moves the 3-choice cursor
u32 sub_0801013C(void); // runs sprite 4's sub-state handler, 1 when done
void medaparts_list_set_cursor_from_part(void);
void medaparts_list_draw_names(void);
void medaparts_list_draw_counts(void);
void sub_0800EDA0(void); // draws gMedapartInventory byte 1 of each row (1 digit, column 0x19); guess: count equipped
void medaparts_list_draw_part_icons(void); // 2x2 icon per owned row, tile by part data unkF1 (guess: the SEX column)
void medaparts_list_init_page_arrows(void);
void medaparts_list_blink_page_arrows(void);
void medaparts_list_init_cursor(void);
u32 medaparts_list_row_input(void);
u32 medaparts_list_page_input(void);
u32 medaparts_list_kind_input(void);
void medaparts_list_load_part_sprite(void); // sets unk3D from the cursor, loads the selected Medapart's sprite (load_sprite_animation_by_type)
void medapart_draw_sprite(void); // Medapart sprite (unk3D, kind unk3E) at the per-kind position, clears the OAM copy
void load_medapart_sprite_by_slot(void); // guess: per-frame Medapart sprite redraw (animation 5/6) when opened from elsewhere (unk3C 2/3) or the part is owned
void medapart_detail_init_sprite(void);
s32 sub_0800F6CC(void);
void medapart_detail_draw_skill(void); // skill type name (gUnk_083B6EC8[unkF0]) or, for ids >= 100 in unkEF, gUnk_083BE97C[unkEF - 100] (leg type)
void medapart_detail_draw_ability(void); // ability name gUnk_083B656C[unkEE] (e.g. Anti-Air, Regenerate)
void medapart_detail_draw_skill_icon(void);
void medapart_detail_draw_name(void);
void medapart_detail_draw_gender_icon(void); // icon after the name: unkF1 = 0 male, 1 female
void medapart_detail_draw_stat_labels(void);
void medapart_detail_draw_stats(void); // stat values unkF2.. per kind (head: Armor, Success, Power, Uses; unkF5 = power icon flag)
void count_compatible_medaparts(void); // unk41 = owned parts of kind unk3E; from a Medabot (unk3C 1) only spare ones of its gender
void medapart_detail_init_arrows(void);
void medapart_detail_blink_arrows(void);
u32 medapart_detail_cycle_part_input(void); // LEFT/RIGHT: previous/next part counted by count_compatible_medaparts, redraws; 1 if moved
void medaparts_help_init_cursor(void); // same code as sub_0800AA1C (Medals help cursor)
void sub_0800FFF4(void);
void load_sprite_animation_by_type(struct OamData *oam, struct Unk_08047414 *obj, u32 id, u32 kind, u32 x, u32 y, u32 tile, u32 pal, u32 e);
void sub_08042950(u32 value, u32 x, u32 y, u8 digits, u32 bgcnt, u16 base);
u32 sub_08042B80(u8 a);
void setup_bot_render_label(u32 a, u32 n);
void clear_battle_bot_array(void);
void count_active_battle_bots(void);
void battle_setup_bot_entry(void);
void sub_08015F90(u32 a);
void sub_08016080(u32 a);
void animate_battle_sprites(u32 idx);
void sub_0801ABF8(void);
void sub_08034F08(void);
u32 get_random_battle_weight_entry(u32 idx);
void sub_08036270(void);
void sub_08038BC0(void);
void sub_08038D30(void);
void battle_begin_action_phase(void);
void sub_08039188(void);
void sub_080391C4(void);
void sub_080392D8(void);
void battle_advance_sequence_counter(void);
u32 sub_0803E79C(void);
void soft_reset_to_title(void);
void sub_0803F624(u8 *dst, u32 size, u8 val);
void blend_obj_palettes_to_color_0803F684(u16 a, u32 b, u16 c);
void blend_obj_palettes_to_color_0803F998(u16 a, u32 b, u16 c);
void clear_battle_sprite_slot(u8 a, u8 b);
void load_bg0_tilemap(u32 a, u32 b, u32 x, u32 y, u32 c);
u32 game_state_execute_handler_a(void);
u32 find_medal_slot_by_id(u8 id);
u32 load_palette_entry(u8 id);
void medal_remove_by_id(u8 id);
void medapart_add_quantity(u8 id, u8 kind, u8 n);
void reduce_medapart_stat(u8 id, u8 kind, u8 n); // takes n of Medapart (id, kind), floor 0
u32 sub_080420C4(u8 level, u8 a, u8 b, u8 c, u8 d); // guess: Medal sprite variant (0-4) from its level and four gUnk_083B6158 record bytes
u32 sub_08042114(u8 a, u8 b);
u32 sub_08042218(void);
void add_position_entry(u8 id);
void sub_080422B8(u8 id, u8 n); // guess: add n of item id (inventory 0x03002BA0: 0x80 | id, count; max 99)
void sub_08042318(u8 id, u8 n); // guess: take n of item id
u32 get_item_quantity_by_id(u8 id);
s32 rng_next_080424B8(void);
void load_part_data(u32 part, u32 kind, u8 *dst);
struct Vec16 compute_polar_to_screen_position(u32 angle, u32 radius, u32 cx, u32 cy, u32 a, u32 b);
u32 sub_0804384C(u8 medal); // team slot (gUnk_030017A0) holding Medal id `medal`, or 0xFF
void decompress_sprite_to_vram_08042D94(u32 a, u32 b, u32 c, u32 d, u32 slot);
void init_battle_medabot_sprites(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j, u32 k);
void setup_battle_sprite_group(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j, u32 k);
u32 sub_0804361C(u32 medal, u32 forward); // guess: previous (forward = 0) / next owned Medal slot (gUnk_03000BE0)
u32 find_next_available_medapart_slot(u32 part, u32 kind, u32 forward, u32 d);
void init_scene_buffers_080445F4(void);
void setup_scene_with_bg_and_sprites(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9, u32 a10, u32 a11);
void init_scene_with_bg_and_palette(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9, u32 a10, u32 a11, u32 a12);
void advance_text_display(u32 a0, u32 a1, u32 a2);
u32 medabot_detail_is_full_set(void); // 1 if gUnk_03000440.unk98-9B (the four shown Medaparts) are all the same set
u32 sub_080440B4(void);
void sub_08047414(struct Unk_08047414 *obj, u8 *buf, u32 b, u32 c);
void setup_scene_bg_layers_and_sprites(void *oam, struct Unk_08047414 *obj, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
void battle_sprite_set_palette_index(u32 sprite, u32 pal);
void update_battle_sprite_orbiting_positions(u32 sprite, u32 idx, u32 c);
u32 validate_medapart_stats(u8 medal, u8 head, u8 rarm, u8 larm, u8 legs);
void modify_medapart_quantity(u32 part, u32 kind, u32 amount, u32 add, u32 e);
void fill_tilemap_pair_or_divide(u8 value, u32 x, u32 y, u32 bgcnt, u16 entry);
void draw_tilemap_with_offset(u32 id, u32 x, u32 y, u32 bgcnt, u16 flags);
void sub_08043CA8(void);
void decompress_tileset_to_vram(u32 id, u32 arg);
void apply_battle_blend_effect_a(void);
void prebattle_draw_opponent_name(void);
void prebattle_draw_battlefield_name(void);
void load_opponent_medabot_sprites(void);
void init_opponent_medabot_sprites(void);
void draw_opponent_leg_type_icons(void);
void prebattle_init_rubberobo_sprite(void);
void sub_080121A8(void);
void update_scroll_movement_a(void);
void update_all_battle_sprite_orbits(void);
void sub_08044B58(void);
void sub_08044CDC(u32 a);
void dispatch_by_index_0476e8(u32 idx);
void sub_08047850(s32 a);
void sub_08047878(u32 a, u32 b);
void sub_08047BA8(u32 id);
void sub_08047BC0(u32 a);
void init_cursor_state(void);
u32 get_money(void);
u32 sub_08047D8C(u8 id);
u32 sub_08047D9C(u8 a, u8 b);
u32 sub_08047DB0(u8 id);
u32 lookup_position_table_value(u8 a, u8 b);
s32 sub_08047F50(void);
u32 sub_08047F70(u8 id);
u32 dispatch_jump_table_29(u32 a, u32 b);
void clear_battle_sprite_entry(u8 slot);
void sub_080496C8(u8 *dst, u32 size);
u32 run_blend_fade_transition(u16 a);
void sub_0804A1C4(void);
void sub_0804B70C(void);
void map_script_read_warp(void);
s32 sub_0804D8A8(u16 id);
void sub_0804D934(struct MapObject *obj);
void spawn_battle_medapart_sprite(u8 a, u8 b, u8 c, u8 d);
void sub_08050508(u8 id);
void set_battle_sprite_animation(u8 id, u8 state);
void sub_08053234(u16 id);
u32 sub_08053288(u16 id);
struct MapObject *battle_find_entity_by_id(u16 id);
void set_battle_state_cancel_flag(void);
void setup_palette_fade_to_color(u16 color, float a, float b, float c);
void setup_battle_sprite_terrain(u8 slot, u8 a, u8 b);
void sub_0805311C(u16 id);
void sub_08053154(u16 id);
void sub_080531EC(u16 id, u8 val);
u8 read_map_script_byte(void);
void read_map_script_bytes(u8 n);
void sub_0804DB34(void);
void sub_0804DB84(u8 i, u8 v);
u32 sub_0804DBA4(u8 i);
void sub_0804D9AC(u8 slot);
void sub_0804DD80(void);
void sub_0804E44C(void);
void sub_0804E4E8(void);
void sub_0804E5A4(u8 a, u8 b);
void map_script_command_done(void);
u32 find_next_available_battle_sprite_slot(void);
void sub_08050770(u32 idx, u8 val);
void sub_08050780(u8 i, u32 val);
void sub_080507A0(u32 idx, u32 val);
void sub_080507C0(u8 i, u8 val);
void sub_08052BA0(u8 on);
u32 sub_0804B6EC(void);
u32 sub_080507E0(u8 slot);
u32 update_battle_sprite_movement(u8 slot, u8 a);
void sub_080482C0(void);
void load_room_graphics(void);
void load_battlefield_data_to_buffer(void);
void update_sprite_animation_dma(void);
void init_battle_field_setup(void);
void update_bg_scroll_offsets_a(void);
u32 scene_transition_step_08047C24(u8 a, u8 b, u8 c, const void *text);
u32 sub_08050868(void);
u32 sub_080508CC(void);
u32 sub_080509A0(void);
void init_battle_sprites(void);
void sub_08050F10(void);
void sub_08053798(void);
void get_state_float_as_int(u32 a, u32 b, s32 *x, s32 *y);
u32 battle_sequence_dispatch(void);
void dispatch_by_index(u32 idx);
void sub_08058214(u32 a);
u32 sub_0805937C(void);
void handle_battle_end_state_transition(void);
u32 sound_env_check_release(struct SoundTrack *track);
void sub_08072658(struct SoundTrack *track);
void sound_channel_update_pitch_sweep(struct SoundTrack *track);
u32 sub_08072708(struct SoundTrack *track);
void sound_update_channel_at_690(void);
void sound_update_channel_at_6d8(void);
void sound_channel_finish_and_callback(struct SoundTrack *track);
void play_song(u32 id);
void play_sound_effect(u32 id);
void sound_channel_update(struct SoundMixChannel *ch);
void load_song_channels(u32 id, u32 arg);
void play_sound_from_command(u32 id, u32 arg);
u32 is_sound_playing_at_position(s32 a);
void sound_track_start_fade(struct SoundTrack *track, u32 target, u32 frames);
void sound_reset_channel_callbacks(u32 a, u32 b);
void set_all_sound_channels_flag_0x40(u32 a);
void sound_fade_out_music(u32 a);
void play_song(u32 id);
void play_song_alt(u32 id, u32 arg);
void play_sound_effect_alt(u32 id, u32 arg);
void sound_stop_all_with_fade_guard(u32 a);

u16 sub_08073140(u32 idx);
void init_all_sound_channels(void);
void sound_init_wave_channel(void);
u32 sound_set_pitch_offset(struct SoundMixChannel *ch, s32 note);
void CpuSet(const void *src, void *dest, u32 control);
void CpuFastSet(const void *src, void *dest, u32 control);
u32 rng_next(u16 range);
#define CpuCopy16(src, dest, size) CpuSet(src, dest, ((size) / 2) & 0x1FFFFF)
void write_tilemap_to_vram_08000E94(u32 x, u32 y, struct Tilemap *map, u32 bgcnt);
void load_tilemap_rows_to_vram(u32 x, u32 y, struct Tilemap *map, u32 bgcnt);
void copy_tilemap_with_offset_08000F78(u16 *dst, struct Tilemap *map);
void dma_obj_palette_to_hardware(void);
void update_anim_object_flags(void);
void copy_oam_affine_params(struct OamData *oam, u16 *affine);
u32 lz_decompress_custom_08000A0C(const u8 *src, u8 *dst, u32 size);
u32 lz_decompress_custom_08000B14(const u8 *src, void *dst);
u32 check_soft_reset(void);
void vblank_irq(void);
void hblank_irq(void);
void VBlankIntrWait(void);
u16 sub_0807C740(u16 kbitSize); // EEPROM library: picks the EEPROM type (4 or 64 kbit)
void irq_dispatch_arm(void);
void nullsub_08000840(void);
void clear_oam(void);
void hw_reset_init(void);
void irq_init(void);
void vblank_body(void);
void soft_reset(void);
void read_keys(void);
void sound_init(struct Unk_03007014 *work);
u16 eeprom_setup_timer_irq(void);
u16 sub_0807C7A8(u8 timer, Func *slot); // EEPROM library: sets the timer and its IRQ handler slot
void sub_080023D8(void);
void serial_link_init(void);
void serial_multiplayer_init(void);
void serial_prepare_send_packet(u16 *packet);
void sound_engine_init(struct Unk_03007014 *work);
void sound_tick_both_channels(void);
void sound_engine_tick(void);
void sub_08074900(struct SoundSongHeader **val);
void sub_08074BC4(struct SoundSongHeader **val);
void sub_08074E70(struct SoundNoteTable *val);
void sub_08073AE4(u32 val);
void sub_08073AF8(u32 val);
void sound_env_off(struct SoundTrack *track);
void sound_env_start_release(struct SoundTrack *track);
void sound_env_tick_release(struct SoundTrack *track);
void sound_env_start_sustain(struct SoundTrack *track);
void sound_env_start_decay(struct SoundTrack *track);
void sound_env_start_attack(struct SoundTrack *track);
void sound_env_key_on(struct SoundTrack *track);
void sound_env_tick_delay(struct SoundTrack *track);
void sound_env_tick_attack(struct SoundTrack *track);
void sound_env_tick_decay(struct SoundTrack *track);
void sound_env_tick_sustain(struct SoundTrack *track);

void sub_08072984(struct SoundTrack *track, u8 val);
void sub_080729A0(struct SoundTrack *track, u8 val);
void sub_080729A8(struct SoundTrack *track, u32 val);
void sound_env_update(struct SoundTrack *track);
void sound_channel_process_command_08072E04(struct SoundTrack *track);
void sound_channel_process_event(struct SoundTrack *track);

void sub_08072948(struct SoundTrack *track);
void sub_080729BC(struct SoundTrack *track);
void sub_080729D8(struct SoundTrack *track, u32 val);
void sub_080729EC(struct SoundTrack *track);
void sub_080729FC(struct SoundTrack *track);
void sub_08072A18(struct SoundTrack *track);
void sub_08072A34(struct SoundTrack *track);
void sub_08072A40(struct SoundTrack *track);
void sub_08072A54(struct SoundTrack *track);
void sub_08072A6C(struct SoundTrack *track);
void sub_08072A80(struct SoundTrack *track);
void stream_read_u32_to_field(struct SoundTrack *track);
void stream_read_and_shift_u32(struct SoundTrack *track);
void sub_08072ABC(struct SoundTrack *track);
void sub_08072AC4(struct SoundTrack *track);
void sub_08072AEC(struct SoundTrack *track);
void sub_08072AFC(struct SoundTrack *track);
void sub_08072B28(struct SoundTrack *track);
void sound_read_envelope_params(struct SoundTrack *track);
void sound_channel_enable(struct SoundTrack *track);
void sound_channel_disable(struct SoundTrack *track);
void sub_08072BD4(struct SoundTrack *track);
void sub_08072BE4(struct SoundTrack *track);
void sound_channel_update_note_08072798(struct SoundTrack *track, u8 cmd);

void sound_set_channel_note(struct SoundTrack *track, u8 note);
void sub_0807255C(struct SoundTrack *track);
void sound_channel1_update(struct SoundTrack *track);
void sound_channel_process_tone(struct SoundTrack *track);
void update_wave_channel(struct SoundTrack *track);
void sound_update_channel_3(struct SoundTrack *track);
void sound_channel_6_update_note(struct SoundTrack *track);
void sound_channel_update_note_08073698(struct SoundTrack *track, struct SoundMixChannel *ch);
u32 sound_semitone_ratio(s32 n);
u32 sound_finetune_ratio(s32 n);
u32 sound_apply_finetune(u32 rate, u32 fine);
u32 sound_calculate_playback_rate(struct SoundMixChannel *ch, u32 ratio);
void update_sound_channel_frequency_08073244(struct SoundTrack *track, vu16 *reg);
void sound_channel_check_note_change(struct SoundTrack *track, u16 *out);
void sound_update_channel_output_routing(struct SoundTrack *track);
void update_sound_channel_frequency_080733AC(struct SoundTrack *track, vu16 *cnt, vu16 *freq);
void sound_channel_read_pending_note(struct SoundTrack *track, u16 *out);
void sound_channel_set_note_attributes(struct SoundTrack *track, vu16 *cnt, vu8 *freqHi);
void sound_channel_update_frequency(struct SoundTrack *track, vu16 *freq);
void update_wave_channel_params(struct SoundTrack *track, vu16 *cnt);
void sound_update_channel3_frequency(struct SoundTrack *track, vu16 *freq);
void sound_channel_reset(struct SoundTrack *track);
void sound_channel_stop_08073B0C(struct SoundMixChannel *ch);
void init_sound_channel_struct(struct SoundMixChannel *ch, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u8 a6, u8 a7);
void sub_08073CA4(struct SoundMixChannel *ch);
void sub_08073E18(struct SoundMixChannel *ch);
void sub_08073E40(struct SoundMixChannel *ch);
void sound_channel_init_full(struct SoundMixChannel *ch);
void sub_080725BC(struct SoundTrack *track);
void sound_configure_mixing_channel(struct SoundMixChannel *ch);
void configure_sound_channel(s32 n, u32 *src);
void sound_start_channel_full(struct SoundMixChannel *ch);
void sound_restart_channel(struct SoundMixChannel *ch);
void sound_channel_request_stop(struct SoundMixChannel *ch);
void sound_channel_trigger_pending(struct SoundMixChannel *ch);
void sound_channel_play(struct SoundMixChannel *ch, u32 src);
void sound_stop_channel_by_index(u32 idx);
struct Unk_03007014 *sub_080750CC(void);
void load_wave_pattern(u32 n);
void sound_set_volume(u32 left, u32 right);
s32 get_sound_channel_position(u32 idx);
void sound_channel_7_update_note(struct SoundTrack *track);
void sub_080740D4(struct SoundTrack *track);
u32 sound_is_paused(void);
void sound_set_paused_nolock(u32 pause);
void sound_set_paused(u32 pause);
void init_sound_channel(struct SoundTrack *track, u8 *seq);
void clear_sound_channel_wave_data(struct SoundTrack *track);
void sound_track_link(struct SoundTrack *track);
void sub_08073EAC(struct SoundMixChannel *ch);
void sound_engine_update_all_channels(void);
void sound_play_with_lock(struct SoundTrack *track, u32 target, u32 frames);
void sound_update_master_volume(void);
void sound_channel_advance_sequence(struct SoundTrack *track);

// code_0804D10C
u8 sub_080502B4(u8 idx, u8 dir);

// code_0805137C (field)
void sub_08051E8C(void);
void set_tile_data(u8 x, u8 y, u8 val);
void init_sprite_affine_matrices_and_state(u32 a, u32 x, u32 y, u32 d);
s32 sub_080518F4(u8 idx);
void update_battle_direction_indicator(u8 arg);
void load_battle_palette_via_dma(u32 toBuffer);
void set_sprite_animation_state(u8 idx, u8 state);
u8 sub_080526F0(u16 x);
u8 sub_08052714(u16 y);
void set_battle_state_byte_c83(u8 dir);
u32 sub_0804803C(u8 arg);
u8 get_adjacent_tile_value(u8 dir);
void field_set_player_facing(u8 dir);
void set_sprite_anim_and_store(u8 idx, u8 state, struct MapObject *obj);
void load_battle_terrain_data(void);
u32 sub_08052960(u8 area, u8 which);
void sub_080529C4(u16 x);
void sub_080529E4(u16 y);
u32 sub_08052A04(void);
u32 sub_08052A18(void);
void field_load_area_tiles(u8 area);
void field_center_camera_on_player(void);
void update_cursor_tile_position(void);
void battle_camera_scroll_update(u8 dir);
void advance_sprite_by_terrain_modifier(u8 idx);
void sub_08052A2C(s16 dx);
void sub_08052AF8(s16 dy);
u32 find_npc_event_match(void);
u32 find_map_event_by_coords(u32 x, u32 y);
u32 check_random_encounter(void);
void populate_battle_entity_tile_positions(void);
void setup_palette_fade_to_color_with_obj(u16 color, float a, float b, float c);
void LZ77UnCompVram(const void *src, void *dst);

// code_08044F54
u32 resolve_tile_from_battle_state(u32 arg);
void sub_0804877C(u8 idx);
void init_battle_sprite_entry_08048818(u8 idx, u16 attr, u32 frame, u8 a3, u8 a4);
void decompress_battle_tile_graphics(void);
void dma_load_obj_palettes_08048664(void);
void dma_load_battle_palettes(void);

// code_080490C4
void sub_080493D4(u8 idx, u8 val);
void advance_sprite_animation_frame(u8 idx);
u8 field_random(u8 n); // returns 0..n-1
void memcpy_u8(const void *src, void *dst, u32 n);

u32 scene_state_dispatch(u8 a, u8 b);
void init_bg0_for_cursor(u32 mode);
u32 sub_08047FEC(void);
void sub_08050C74(void);
void sub_08047D24(u32 a, u32 n);
void add_money(u32 n);
void sub_money(u32 n);
void sub_080500D8(u8 slot, u8 a, u8 b);
u32 sub_0804F13C(u8 a);
void sub_080492CC(void);
void calculate_oam_affine_matrix(u8 i);
u8 sub_08050264(u8 a);
u8 sub_0805026C(u8 a);
u32 sub_08048088(u32 idx);
u32 sub_08047E30(void);
void sub_08047E3C(u8 id);
void sub_08047DC0(u8 id, u8 n);
void copy_string_to_text_buffer(u32 slot, u32 str);
void format_number_to_text_buffer(u32 slot, u32 n);
u32 sub_08047BCC(u32 idx);
u32 sub_08047E20(u8 id);
void sub_08047DD8(u8 id, u8 n);
void init_battle_medapart_sprites_all(void);
void load_map_npc_sprites(void);
void update_entity_sprites_on_screen(void);
u32 sub_08047BEC(u32 a, u32 b);
void sub_08047DF0(u8 a, u8 b, u8 n);
void sub_08047E08(u8 a, u8 b, u8 n);
u32 battle_scene_state_dispatch(void);
void update_bg_scroll_offsets_b(void);
void write_tilemap_rect(u32 x, u32 w, u32 y, u32 h, const void *src, u32 bgcnt, u32 base);
void vram_fill_tilemap_rect(u32 x, u32 w, u32 y, u32 h, u32 bgcnt, u16 value);
u32 load_overworld_map_column(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
void text_window_init(u8 a, u8 b, u32 c);
void sub_0803FB0C(void);
u32 run_message(const void *msg);
void open_choice_menu(u8 a, u8 b, u32 c);
u32 poll_choice_menu(void);
void divide_by_10000(u8 *digits, u32 n);
void divide_by_100000_08041370(u8 *digits, u32 n);
void divide_by_100000_08042838(u32 n, u32 x, u32 y, u32 digits, u32 bgcnt, u32 tile); // guess: draws n as tile digits
void clear_sprite_table_mask(u8 first, u8 count);
void fill_text_blank(u8 *buf, u8 n);
void fill_tilemap_rect_08042698(u32 w, u32 h, u32 x, u32 y, u32 bgcnt, u16 entry);
void memcpy_bytes_0803F63C(const void *src, void *dst, u32 n);
void sub_08041C14(u8 sprite, u8 frame, u16 y); // sets gUnk_03002C30[sprite].unk2 from y and frame (guess: cursor bob)
void sub_08041C5C(u8 sprite, u8 frame, u16 x); // guess: horizontal counterpart of sub_08041C14
void memcpy_bytes_08041D04(const void *src, void *dst, u8 n);
void memswap(void *a, void *b, u32 n);
void render_text_sprites_08040DB8(u8 *digits, u8 a, u32 b, u32 c, u8 d, u8 e, u8 f, u16 g);
void process_sprite_anim_commands(const void *cmds, u8 slot);
void sub_08044094(void);
void field_menu_init_cursor(void);
void sub_0804765C(u32 a);
void update_battle_field_frame(void);
void sub_080487E4(void);
void setup_blend_effect(u8 a, u16 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i);
void blend_effect_update(void);
void init_battle_sprite_entry_08040B90(const void *cmds, u8 slot);
void reset_bg_scroll(void); // zeroes the four BG scroll positions
void set_blend_effect_mode(u8 mode, u16 a, u16 b);
u32 update_blend_effect(void);
void load_encounter_into_battle_setup(void);
u32 sub_0803EED8(void); // nonzero: waiting on the serial link (reads gUnk_03005010)
u32 game_state_execute_handler_b(void);
void sub_080121CC(void);
void setup_battle_result_sprite(void);
void sub_08012468(void);
void setup_battle_result_sprite_animation(void);
void calculate_battle_score_summary(void);
void calc_average_bot_stat_080125B4(void);
void accumulate_alive_bot_score(void);
void calc_average_bot_stat_0801264C(void);
void calc_medaforce_gauge_from_damage(void);
void sub_0801275C(void);
void accumulate_team_armor_stats(void);
void battle_check_medal_level_up(void);
void divide_by_100000_b(u8 *buf, u32 value, u32 tile);
u32 advance_sprite_anim_frame(u8 sprite, u8 b);
void sub_0801BF64(u16 *counter, u16 max);
void sub_08067A48(u8 slot);

s32 sub_08043C94(void); // random 0-100
void render_text_sprites_08040EE4(u8 *text, u8 a, u32 x, u32 y, u8 b, u8 c, u8 d, u16 e, s32 f, s32 g);
void sub_080122F4(u32 a);
void sub_080421B4(u8 a, u8 b);
u32 random_pick_weighted4(u32 a, u32 b, u32 c, u32 d);
void load_area_battlefield(void);
void setup_random_encounter_enemies(void);
void setup_sprite_animation_entry(u32 a, u8 id, u8 kind, u16 x, u16 y, u32 f, u8 g, u8 h, u8 i);
s32 sub_080121F0(void);
u32 sub_08012234(void);

// Robattle (game state 7) helpers
void update_all_battle_status_sprites(void);
void battle_process_bot_actions_for_side(u32 side);
void sub_08016370(u32 rec);
u32 sub_08016438(u32 rec);
void load_battle_bg_layers(void);
void render_bot_name_sprites(u32 rec);
void draw_battle_panel_left_a(u32 rec);
void render_bot_health_bar(u32 rec);
void render_bot_cash_display(u32 rec);
void battle_load_sprite_data(void);
void sub_08015F78(void);
void init_battle_entities_and_labels(void);
void battle_process_all_bots_actions(void);
void sub_08018A18(void);
void load_battle_script_entry_b(void);
u32 battle_phase_dispatch_0801A788(u32 a);
void load_bg3_tilemap_08488764(void);
void draw_battle_bot_portraits(void);
void load_all_bot_part_sprites(void);
void setup_all_battle_bot_sprite_positions(void);
void init_battle_bot_sprites(void);
void apply_battle_blend_effect_b(void);
void decompress_to_ewram_27000(const u8 *src);
void sub_08044100(void);
void sub_08016288(void);
void sub_080178CC(void);
void sub_0801630C(void);
void sub_08017914(void);
void setup_bot_battle_sprites_08015A00(u32 rec, u32 x, u32 y);
void sub_0801A744(u32 rec);
void sub_08016554(void);
void sub_080165B0(void);
void sub_080165D0(void);
void sub_08016614(void);
void sub_08016660(void);
void decompress_two_bg1_layers(void);
void sub_08016068(void);
void read_vram_tilemap_rect(u32 x, u32 w, u32 y, u32 h, u32 bgcnt, void *dst);
void draw_partial_bg1_column(void);
void scroll_tilemap_window(void);
void sub_08016FB4(void);
void process_bot_battle_turn(u32 rec);
void load_bot_palette_data(u32 rec, u32 part);
void battle_bot_select_part(u32 rec, u32 part);
void sub_08018900(u32 a);
void init_battle_action_select_ui(u32 a);
void sub_080166AC(void);
void determine_battle_part_action_priority(void);
void sub_080166F0(void);
void sub_0801672C(void);
void sub_08016DA4(void);
void sub_0801677C(void);
void sub_08016A3C(void);
void sub_08016AD8(void);
void sub_08016D18(void);
void sub_08016DCC(void);
void sub_0801B894(void);
void sub_0801B9C4(void);
void sub_080168F4(void);
void sub_080169AC(void);
void sub_08016C0C(void);
void sub_0801BACC(void);
void sub_0801767C(void);
void sub_080175FC(void);
void sub_08017948(void);
void save_restore_bg0_tilemap_region(void);
void save_restore_bg1_tilemap_region(void);
void sub_08017004(void);
void sub_08017048(void);
void sub_08017084(void);
void sub_080170D4(void);
void sub_08017104(void);
void sub_08017268(void);
void sub_08017178(u32 a);
void sub_080171C0(u32 a);
void sub_08017208(u32 a);
void sub_08017130(u32 a);
void sub_080173B4(u32 a);
void sub_080167BC(u32 a);
void sub_08016804(u32 a);
void sub_0801684C(u32 a);
void sub_08016894(u32 a);
void position_battle_team_cursors(u32 a, u32 b);
void init_battle_cursor_sprite_08017B24(void);
void render_battle_bot_label(void);
void sub_08017D14(void);
void load_bot_sprite_tiles_to_vram(void);
void copy_battle_bot_data_to_state(void);
void battle_load_script_to_buffer(void);
void battle_setup_bot_font_tile(void);
void render_battle_bot_status_row(void);
void get_bot_part_effective_values(u32 bot, u8 *out);
void set_game_state_params(u8 a, u8 b, u8 c, u8 d);
void init_ewram_buffers_and_state(void);
void setup_battle_bot_display(void);
void sub_080182D0(void);
void animate_bg_window_blink(void);
void setup_scene_bg_from_game_state(void);
u32 sub_0801827C(void);
void sub_080182AC(void);
void handle_battle_bot_selection(void);
void display_battle_cursor_on_bot(void);
u32 animate_battle_field_scroll(void);
u32 animate_battle_bots_entry(void);
void setup_scene_from_game_state(void);
void sub_080189EC(void);
void select_battle_music(void);
void sub_08018BD4(void);
void sub_08018C38(void);
void sub_08018C78(void);
void sub_0801902C(void);
u32 sub_08019EF0(void);
void sub_08019078(void);
void sort_active_medal_slots(void);
void battle_calc_bot_count_minus_one_mod3(void);
void sub_0801A678(void);
void iterate_bots_setup_battle_sprites(void);
void sub_08015414(u32 rec);
u32 sub_0801A6B0(void);
void battle_process_all_bot_actions(u32 rec);
u32 sub_0801A6EC(u32 rec);
void sub_08019348(u32 rec);
void sub_08019544(u32 rec);
u32 sub_08019FBC(u32 rec, u32 a);
u32 sub_0801A030(u32 rec, u32 a);
void set_display_digit_type(u8 *buf, u32 value, u32 type);
void sub_0801A144(u8 *buf, u32 rec);
void sub_0801A228(u32 rec);
void copy_player_medals_to_battle_bots(void);
void copy_battle_position_to_sprite(void);
void init_enemy_bot_medal(u8 i);
void init_enemy_bot_loadouts(void);
u32 battle_dispatch_action_by_type(u32 rec);
void select_bot_battle_action(u32 rec);
u32 sub_080154E0(u32 rec, u32 part);
u32 sub_08015508(u32 rec, u32 part);
u32 sub_08015528(u32 rec, u32 part);
u32 check_medaforce_availability(u32 rec, u32 slot, u32 random);
u32 sub_08015648(u32 rec);
void set_random_battle_formation(void);
u32 can_bot_perform_action(u32 rec, u32 part);
u32 rng_lookup_table_value(void);
u32 begin_battle_action_lookup(u32 rec, u32 part);

#endif // GUARD_FUNCTIONS_H
