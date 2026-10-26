#ifndef GUARD_FUNCTIONS_H
#define GUARD_FUNCTIONS_H

// Prototypes for game functions (decompiled or still in asm), in ROM order.

// elsewhere (unk3C 2/3) or the part is owned
// Robattle action step dispatchers run by the action script (code_08030CAC wrappers)
// amount/32, for the 16-colour palettes in mask
// h, u8 i, u8 j): callers were compiled without a prototype
// h, u8 i, u8 j, u8 base): callers were compiled without a prototype
void sub_080496C8(u8 *dst, u32 size);
u32 run_blend_fade_transition(u16 a);
void sub_0804A1C4(void);
void sub_0804B70C(void);
void map_script_read_warp(void);
s32 sub_0804D8A8(u16 id);
void sub_0804D934(struct MapObject *obj);
void spawn_script_sprite(u8 a, u8 b, u8 c, u8 d);
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
void load_room_graphics(void);
void init_battle_field_setup(void);
void update_bg_scroll_offsets_a(void);
u32 sub_08050868(void);
u32 sub_080508CC(void);
u32 sub_080509A0(void);
void init_battle_sprites(void);
void sub_08050F10(void);
void sub_08053798(void);
void get_state_float_as_int(float a, float b, s32 *x, s32 *y);
u32 battle_sequence_dispatch(void);
void dispatch_by_index(u32 idx);
void sub_08058214(u32 a);
u32 sub_0805937C(void);
void handle_battle_end_state_transition(void);

void CpuSet(const void *src, void *dest, u32 control);
s32 Div(s32 num, s32 denom);    // BIOS SWI 6
s32 DivArm(s32 denom, s32 num); // BIOS SWI 7
s32 Mod(s32 num, s32 denom);    // BIOS SWI 6, returns the remainder
void CpuFastSet(const void *src, void *dest, u32 control);
#define CpuCopy16(src, dest, size) CpuSet(src, dest, ((size) / 2) & 0x1FFFFF)
void VBlankIntrWait(void);
u16 sub_0807C740(u16 kbitSize); // EEPROM library: picks the EEPROM type (4 or 64 kbit)
void irq_dispatch_arm(void);
u16 eeprom_setup_timer_irq(void);
u16 sub_0807C7A8(u8 timer, Func *slot); // EEPROM library: sets the timer and its IRQ handler slot
void link_buffer_swap_arm(void);        // ARM, crt0.s; copied to IWRAM 0x03005250

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
u32 get_adjacent_tile_value(u8 dir);
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
void save_script_sprites(void);
void setup_palette_fade_to_color_with_obj(u16 color, float a, float b, float c);
void LZ77UnCompVram(const void *src, void *dst);

// code_08044CDC
void divide_by_3(u8 a, u8 b); // guess: refreshes racer a's 4-part sprite group at its current position (not a divide)
void sub_08069A68(u8 idx, s16 x, s16 y, u8 h,
                  u8 pal); // guess: places racer idx's 4-part sprite group at x, y and sets its palette
void matrix_set_identity(void);
void ring_points_place_on_hexagon(u32 a);

// code_080490C4
void sub_080493D4(u8 idx, u8 val);
void advance_sprite_animation_frame(u8 idx);
u8 field_random(u8 n); // returns 0..n-1
void memcpy_u8(const void *src, void *dst, u32 n);

u32 scene_state_dispatch(u32 a, u32 b);
void sub_08050C74(void);
void sub_080500D8(u8 slot, u8 a, u8 b);
u32 sub_0804F13C(u8 a);
void sub_080492CC(void);
void calculate_oam_affine_matrix(u8 i);
u8 sub_08050264(u8 a);
u8 sub_0805026C(u8 a);
void restore_script_sprites(void);
void load_map_npc_sprites(); // takes one argument (update_battle_field_frame passes gUnk_030057E0.unkCBA)
void update_entity_sprites_on_screen(void);
u32 battle_scene_state_dispatch(void);
void sub_08050B50(void);
void init_script_sprite(u8 idx, u8 part, u8 x, u8 y);
u8 calc_medapart_table_index(u8 a);
u8 compute_battle_sprite_anim_offset(u8 id, u8 a);
void field_player_step(u8 dir);
bool32 check_tile_and_trigger_battle_action(u8 dir);
bool32 field_player_at_map_edge(u8 dir);
void update_npc_random_animation(void);
u32 map_cursor_move_and_check_event(void);
void field_player_walk_input(void);
void field_warp_to_area(void);
void update_bg_scroll_offsets_b(void);
// tiles; align 0 center, 1 left, 2 right
void setup_blend_effect(u8 mode, u16 bldcnt, u8 type, u8 sa, u8 sb, u8 sy, u8 a, u8 b, u8 y);
u32 blend_effect_update(void);
void sub_08067A48(u8 slot);
int sub_08067160(u8 *s); // string length, 0 when it is 1
void sub_0806918C(void); // clears VRAM, the sprite table and the four BG scrolls
void dma_copy_tilemap_strip(u8 n);
void sub_08069EE4(u8 *dst, u8 *src);  // copies bytes up to and including the first one > 0xF8
bool32 race_check_all_finished(void); // TRUE 240 frames after all three gUnk_03006F8C racer states are > 2
void sub_08068DA0(void);
void dispatch_game_mode_handler(void);
void sub_08068CF4(void);
void sub_08068D74(void);
void sub_08068FD4(void);
void sub_0806904C(void);
void init_battle_sprite_small(void);
void race_update_racer_anim_counters(
    void); // per racer: gUnk_03006FE0[i] counts frames, steps the racer sprite's unk1A at the gUnk_08485CE3 delay
bool32 scene_transition_step_080686F4(void);
bool32 sub_08069EF8(void);
bool32 sub_08069F80(void);
bool32 sub_0806A4C0(void);
void update_sprite_animations_tick_0806AF40(void);
void update_sprite_animations_0806B334(void);
void sprite_animation_dispatch(u8 sprite, u8 a, u8 b, u8 c);
void clear_sprite_entry(u8 sprite); // zeroes gUnk_03002C30[sprite] (0x40 bytes)
void sub_0806B310(void);
void init_battle_field_screen(void);
void init_battle_icon_positions(void);
void init_battle_bg_layer1(void);
void write_tilemap_tiles_dma(u8 a, u8 b, u8 c);
void setup_screen_transition_effect_080682CC(u8 a, u8 b, u16 c);
void setup_screen_transition_effect_080684F0(u8 a, u8 b, u16 c);
bool32 scene_step_palette_fade_out(void);
bool32 sub_0806F850(void);
bool32 sub_0806F9D4(void);
void battle_timer_digit_extract(void);
void update_sprite_animations_080703D8(void);
void load_bg_screen_b(void);
bool32 battle_transition_fade_step(void);
void copy_tilemap_rect_to_vram(const u16 *src, u8 bg, u8 w, u8 h, u8 x, u8 y, u16 tile, u8 pal);
void sub_0806FF50(void);
void sub_0806FF90(void);
void sub_0806FFF8(void);
void sub_08070030(void);
void battle_sprite_set_action(u8 a, u8 b, u8 c);
void update_bg2_affine_scanline_params(void);
void update_sprite_special_effects(void);
void sub_0806D288(void);
bool32 sub_0806DEAC(u8 i);
bool32 sub_0806DEE8(u8 i);
void sub_0806D420(void);
u32 sub_0806BBDC(void);
void sub_0806C994(void);
void sub_0806BE58(void);
void bomb_game_drop_bombs(void);
void sub_0806BD84(void);
void sub_0806C500(void);
void sub_0806BEF0(void);
void sub_0806C20C(void);
void sub_0806C4CC(void);
void get_battle_state_value_div10(void);
void sub_0806CDE8(void);
void update_battle_sprite_direction(void);
void sub_0806CD48(void);
void sub_0806CAEC(void);
void sub_0806CE58(void);
void sub_0806CFA4(void);
u32 sub_0806C6F8(void);
u32 sub_0806C7C4(void);
void set_bot_y_positions_by_count(void);
void sub_0806DF80(
    u8 anim,
    u8 sprite); // starts animation anim on sprite slot sprite (unk20 = anim, unk22 = 0, unk30 = unk6, unk1A = 0)
u32 check_battle_timer_expired(u8 a);
u32 process_text_tile_and_dma_transfer(u8 a);
u32 battle_draw_tilemap_row_dma(u8 a);
void update_battle_sprite_explosions(void);
void update_scene_animation_frame(void);
bool32 bg_tilemap_scroll_up_row(s32 step);
bool32 copy_bg_tile_column(s32 col, s32 step);
void clear_stack_buffer_64(s32 len, s32 step);
void render_text_right_aligned(const u8 *s, u8 row);
void scroll_tilemap_column(s32 a, s32 b);
void load_battle_sprite_graphics(void);
void init_battle_background_layers(void);
void load_bg_tilemaps_and_palette(void);
void update_battle_icon_rotation(void);
void update_battle_bot_entry_animations(void);
void update_battle_bot_death_animations(void);
void update_battle_bot_damage_animations(void);
void update_battle_bot_turn_order_tiles(void);
bool32 sub_0806A230(void);
void race_dispatch_substate(void); // gRaceSubStates[gGameSubState]()
void sub_08069000(void);
void race_update(void); // race sub-state 9: the race itself, every frame (runtime-checked)
void sub_080690C4(void);
void sub_08069114(void);
void sub_08069158(void);
void init_battle_sprite_medium(void);
void init_battle_sprite_c400(void);
void init_battle_sprite_entry_1(void);
void init_battle_sprite_large(void);
void init_battle_bg_layer(void);
bool32 execute_scene_step(void);
void get_entity_speed_value(void);

// Robattle (game state 7) helpers
// direct = palettes straight to PLTT
// 0x5C team / 0x94 opponents
// per-turn part flags
// then clears unk118..
// palette 6 from gUnk_084E3058
// can't use Medaforce)

// Medal level, Propulsion)

// 0x11/0x12 (2), 0x13/0x14 (4)

void *memcpy_optimized(void *dst, const void *src, u32 n); // library
void *memcpy(void *dst, const void *src, unsigned long n); // libc (the compiler's builtin)
void *custom_memset(void *dst, int c, u32 n);              // library
u16 ReadEepromDword(u16 address, u16 *data);               // EEPROM library: reads 8 bytes
u16 ProgramEepromDword(u16 address, u16 *data);            // EEPROM library: writes 8 bytes
u32 ProgramEepromDwordEx(u16 address, u16 *data); // EEPROM library: writes 8 bytes and verifies; u32 so sub_080603A4
                                                  // tests the result without truncating it
void init_blend_effect(void *state, u8 a, u8 b, s8 c, u16 mode);
u32 blend_fade_step_08065598(void *state);
void sub_08059D04(void); // clears unk0 of the 128 gUnk_03002C30 sprites
// code_0805AB40
void decompress_and_write_tilemap(
    const void *src,
    u32 bgcnt);          // LZ77 tilemap with a w, h header (u32 each, 16-byte header) into the BG screen block of bgcnt
void sub_0805AB40(void); // VBlank-once callback: copies gPaletteBuffer / gPaletteBufferBg to OBJ / BG palette RAM
void sub_0805AB68(
    u16 color, s32 t,
    u32 pal); // guess: blends OBJ palette pal from gPaletteBackup toward color by t / 32, then uploads in VBlank
void sub_0805AC4C(u16 color, s32 t); // guess: same blend for all BG palettes
void load_battle_sprite_tiles(u32 id, s32 kind, s32 slot);
u32 sub_0805B4B0(u32 id);                   // gUnk_08483AC0[id] == 1
u32 sub_0805B4C8(struct Unk_03002C30 *spr); // guess: sine-wave bobbing of 8 sprites, 1 when done
void sub_0805BB64(u8 sel, u8 count);
void swap_inventory_items(void);
void item_menu_draw_page_numbers(void); // "page / pages" on the item screen
void init_fade_sprite_and_start_fade(void);
void sub_0805B3E4(s32 x, s32 y, s32 n); // clears n tilemap entries at (x, y) of the BG map at 0x0600B000
void sub_0805B470(struct Unk_03002C30 *sprite);
s16 sub_0805BB10(
    s16 step); // title menu blend pulse: sets BLDALPHA from gUnk_080AF6F0[step / 8], returns step + 1 (0 after 0xA0)
void sub_0805BCC0(u8 sel); // title option rows: palette 0xA (selected row, current value), 9 (current value) or 8 on
                           // the BG0 tiles masked by gUnk_080AF740
void sub_0805BDC8(u8 a); // BG palette 10 = blend of the two 16-color halves at 0x0202FB00 by (a - 16) / 32 (0 below 16)
void sub_0805BEA0(
    u8 sel,
    u8 f); // BG palettes 0-2 from 0x0202FA00; palette sel blended between its two halves by f / 32 (title cursor pulse)
void sub_0805BBF8(u8 sel); // title menu: palette 7 on the selected row of three 11-tile BG0 rows, 6 on the others
void sub_0805BC6C(void);   // sets palette 8 on three 16-tile BG0 rows (dead code, carved from sub_0805BBF8)
void sub_0805C820(void);   // fades REG_BLDY up to 16, then game state 9 (carved from sub_0805C7E8)
void sub_0805CA28(u32 a);
void sub_0805D57C(u16 a);
void attempt_save_and_transition(
    void); // save screen state 7: up to 4 tries of save_dispatch(0), then state 8 (ok) or 12 (failed)
s32 load_save_with_retries(
    void); // title: stops the music, clears the name, tries save_dispatch(1) 4 times; nonzero while sound 4 plays
s32 save_dispatch(s32 mode); // 0: save, 1: load (returns validate_save_data), 2: erase; all through gDecompressBuffer
void load_save_data(struct SaveData *save);
void serialize_save_data(struct SaveData *save);
s32 validate_save_data(struct SaveData *save); // reads the EEPROM into save: 0 ok, 1 wrong signature, -1 corrupt
s32 write_save_to_eeprom(
    u16 *src, u32 force); // writes 0x1CC0 bytes to EEPROM: every block if (u8)force, else only blocks that differ
void sub_0805E170(u16 a);
void init_multiplayer_id(void);
void sub_0805B9EC(u16 keys); // link: gNewKeys / gReleasedKeys from the other player's keys
void sub_0805BA20(void);     // link: exchanges keys through gUnk_03005010 (player 0 sends gHeldKeys)
u16 sub_0805BA68(s16 x1, s16 y1, s16 x2, s16 y2); // distance: Sqrt(dx * dx + dy * dy)
u32 Sqrt(u32 n);
void ObjAffineSet(struct ObjAffineSrcData *src, void *dest, s32 count, s32 offset);
void unpack_item_inventory_to_buffer(
    void); // gItemInventory -> struct ItemListEntry list at 0x02040000, count in gUnk_03006F74->unk10
void update_battle_medapart_icons(void);
void render_battle_medapart_list(u32 mode);
s32 calc_text_pixel_width(const u8 *s); // sum of gUnk_083B4C88 widths, up to 10 characters or the 0xFE terminator
void sub_0805E1CC(const u8 *s); // draws 10 characters as 2-row BG1 tiles copied from a 26-per-row font map on the same
                                // screen (guess: name entry)
void draw_number_3digits(s32 n, s32 x, s32 y); // 3 digits, blank-padded, BG tilemap 0x0600F000 (item list page numbers)
void item_menu_set_cursor_pos(
    struct Unk_03002C30 *sprite); // list cursor sprite: unk2 = 0x54, unk4 = 0x1C + 16 * (gUnk_03006F74->unkC % 5)

struct ObjSortEntry;
struct RotateSrc;

void shop_build_sell_list(void);
void sub_08064A74(void);
void sub_08064A94(void);
void sub_08064AB4(void);
void sub_08064AD4(void);
void tilemap_offset_tiles_and_palette(u32 tiles, u32 pal,
                                      u32 block); // (u16, u8, u8): callers pass full ints; adds tiles to the tile
                                                  // numbers of a 32x32 screen block, sets palette pal
void LZ77UnCompWram(const void *src, void *dst);
void clear_entity_state(u8 slot);
void init_battle_medaforce_sprite(void);
void update_battle_entity_status_chars(void);
// code_0805EE6C
void sub_080600E0(void); // gUnk_03002C30[0].unk1A counts 0-63, unk6 = 0x100 + gUnk_080AF980[(count >> 3) & 7]
void sub_08062A74(u16 id, u8 second); // copies Medapart name pointer id (part * 4 + kind) of gUnk_083BB9CC into
                                      // gUnk_03000440.unk9E (+0x14 if second), 0xFE-terminated
void copy_text_with_lookup(); // (u8 *dst, u8 *src, u32 unused, u32 i): copies src[i..] up to 0xFF plus 2 bytes, dst[2]
                              // = gUnk_080AFA10[gUnk_03002420]; one caller passes only dst, src
void sub_0805FD60(void);
void sub_08060804(void);
void sub_0805F898(void);
void sub_08061830(void);
void town_map_dispatch(void); // gUnk_08483DA0[gGameSubState]()
void advance_substate_on_handler_complete(void);
void advance_substate_on_handler_complete_1c(void);
void sub_0805EE6C(void);
void sub_080612D8(void);
void sub_0806098C(void);
void sub_0805F860(void);
void sub_0805F974(void);
void sub_0805F9AC(void);
void sub_08060324(void);
void sub_080608B4(void);
void sub_0805FAF0(void);       // gUnk_08483CA4[gGameSubState](), BG3 scrolls down every other frame
void save_lost_dispatch(void); // gUnk_08483CC4[gGameSubState](), BG3 scrolls up every other frame
void test_mode_dispatch(void); // gUnk_08483C6C[gGameSubState](), BG3 scrolls diagonally
void update_fade_effect(void);
void town_map_update_cursor(void);
void update_animation_timer(void); // gUnk_03006F74->unk3A counts 0-109; every 10th frame copies a 480-byte frame of
                                   // gDecompressBuffer to VRAM 0x06004020
void sub_0805F8B0(void);
void sub_0806142C(void);
void shop_list_dispatch(void); // gUnk_08483E8C[gGameSubState](), BG3 scrolls diagonally
void battle_menu_highlight_icons(
    u32 sel, u32 frame); // BG2 tiles of 4 icons: palette 6 for icon sel when frame & 8, else palette 5
void sub_0805F81C(void);
void sub_0806035C(void);
void sub_0806086C(void);
void sub_080625EC(void);
void sub_08060154(void);
void sub_08061180(void);
void sub_080616F8(void);
void sub_08060C44(void);
void sub_08060C60(void);
void update_battle_sprite_priority_flags(void);
void silence_and_clear_vram(void);
void copy_bg2_tilemap_to_ewram(void);
void shop_menu_dispatch(void); // gUnk_08483E10[gGameSubState](), BG3 scrolls diagonally
void sub_08061D30(void);
void sub_08062638(
    void); // fades OBJ palettes in, then init_battle_scene(unk19, id of shop list entry unk1A + gUnk_02023078)
void fade_out_transition_step(void);
void clear_or_fill_bg2_tilemap(s32 n);
void sub_08062AB0(u32 medal, u32 frame); // decompresses Medal sprite gUnk_083AC494[medal][frame] to OBJ VRAM and sets
                                         // up sprite 0 at (0xB8, 0x38)
void sub_0806006C(void);
void sub_08061300(void);
void sub_0805FB2C(void);
void update_fade_transition_state_0805F778(void);
void sub_08061678(void);
void sub_0805F8F0(void); // up to 4 tries of save_dispatch(2) (erase), then the next sub-state (ok) or 12 (failed)
void sub_080603A4(void); // zeroes EEPROM block 0 (up to 4 tries), then game mode 3 state 2
void load_medapart_sprite_animation(u8 id, u8 kind, u32 which);
u32 sub_0805B7A0(void);
void sub_080608EC(void);
void sub_0806174C(void);
void sub_08060FD4(void);
void sub_08061374(void);
void draw_number_2digits_tall(s32 n, s32 x, s32 y);
void draw_number(u16 a, s32 b, u8 c, u8 d, u8 e, u8 f);
void init_fade_screen_setup(void);
void sub_080609C0(void);
void update_animated_tilemap(void);
void update_scroll_animation_tiles(void);
void init_scene_rendering_context(u32 a);
void init_linking_mode(void);
void compute_difference_div3(s32 *a, s32 *b, s32 *c, s32 *d);
u8 u8_difference_divide(u8 a, u8 b, u8 n);
void copy_block_64bytes(s32 dst[4][4], s32 src[4][4]);
void matrix_multiply_4x4_fixed(s32 dst[4][4], s32 a[4][4], s32 b[4][4]);
void matrix_rotate_xyz(s32 a, s32 b, s32 c);
void ring_points_place_on_circle(u16 phase);
void ring_points_place_on_circle_b(u16 phase);
void animate_battle_scroll_tiles(void);
void fade_update_tilemap_copy(void);
void render_battle_medal_names(u8 first);
void sprite_cycle_anim_start(
    u8 sprite, u16 frame,
    u8 arg2); // sprite (0x16+): unk23 = arg2, unk30 = unk6 = frame; sets bit (sprite - 0x16) in byte 0x03007010
void sprite_cycle_anim_stop(u8 sprite, u16 frame); // clears that bit, unk23 = 0, unk6 = frame
void sub_08071C40(u8 state, u8 sprite,
                  u16 arg2); // gUnk_03002C30[sprite]: unk20 = state, unk21 = 0, unk34 = arg2, unk1A = 0
void sub_08071614(void);
void sub_0807168C(void);
void sub_0807068C(void);
void sub_080706AC(void);
void load_bg_screen_c(void);
u32 call_battle_handler_by_state_08071C64(void);
void apply_blend_coefficients(void);
void sub_080496DC(u8 *dst, u32 n, u8 val);
s32 count_byte_differences(const u8 *a, const u8 *b, s32 n);
s32 sum_bytes_0804971C(const u8 *p, s32 n);
void quicksort_u8_array(u8 *arr, s16 left, s16 right);
void sub_08049F84(u16 *arr, s16 left, s16 right);
void sub_0804A0A4(u16 *arr, s16 left, s16 right);
void sub_08049E74(u16 a, u32 b, u16 c);
void sub_08049E88(u16 a, u32 b, u16 c);
void sub_08049CC0(void);
void map_script_update_command(void);
void map_script_run_command(void);
void update_npc_sprite_animations(void);
void sub_0804B1FC(void);
void sub_08058110(); // defined as (void); sub_0804AF4C passes an argument
s32 check_room_exit_at_position(void);
u32 sub_0804B694(void);
void clear_vram_bg2_tiles(void);
void check_and_update_battlefield_palette(void);
void build_bg_tile_entry(u16 *dst, u16 id, u16 base, u16 y, u16 x, u16 yoff, u16 xoff);
u32 sub_08052990(u32 unused, u8 which);
u32 sub_08053194(u16 id);
void draw_number_tall(u16 value, s8 w, u8 x, u8 y, u8 pal, u8 bg);
void update_cursor_sprite_position(void);
u32 check_vehicle_usability(s32 idx);
void load_battle_sprite_from_index(u32 value, s32 bits, s32 x, s32 y);
void copy_tilemap_rect_with_offset(u16 *src, u16 *dst, s32 y, s32 x, s32 w, s32 h, s32 unused6, s32 unused7, s32 add,
                                   s32 mode);
void init_vehicle_menu_sprite(s32 slide);
void copy_tilemap_region(u16 *src, u16 *dst, s32 y, s32 x, s32 w, s32 h, s32 add, s32 pal, s32 mode);
void fill_tilemap_rect_0804916C(u16 *dst, s32 y, s32 x, s32 w, s32 h, s32 tile, s32 pal, s32 mode);
void render_npc_tilemap_row(s32 row);
void handle_cursor_up_down_input(s32 count);
void sub_08057EBC(void);
void sub_080531D0(u16 id, u8 val);
void sub_0805889C(s32 max);
void sub_08058908(u32 idx, s32 max);
void sub_080589B0(u32 idx, s32 max);
void update_anim_counter(u32 idx, s32 max);
void sub_08058A88(u32 idx, u32 sub, s32 max);
void clear_all_battle_sprites(void);
void sub_08058B04(u32 idx);
void sub_080581C0(u32 a, s32 b);
void init_battle_field_sprites(void);
void load_or_clear_battle_sprites(s8 key, s32 value, u8 width, u8 x, u8 y);
void load_battle_sprite_tile(const u8 *tiles, s32 count, s32 x, s32 y);
float float_abs_if_negative(float x);
float float_default_to_one_if_zero(float x);
float float_sign(float x);
double compute_sqrt_scaled(double x);
void sub_08053418(void);
void compute_distance_to_state_position(float *xs, float *ys, float *zs);
void compute_plane_from_points(float *x, float *y, float *z, float *a, float *b, float *c, float *d);
void get_state_position_xyz(float *x, float *y, float *z);
void sub_0805378C(void);
void affine_set_destination_and_compute_transform(float x0, float x1, float y0, float y1);
void affine_set_source_and_compute_transform(float x0, float x1, float y0, float y1);
void set_state_float_field(float a, float b, float dist, float d);
void sub_08053AB8(float *x, float *y, float *z);
void sub_08053B94(float x, float y, float z);
void sub_08053BB4(float a, float b);
void update_battle_entity_screen_position(float x, float y, float z);
void compute_3d_transform_vectors(float x, float y, float z, float *outX, float *outY, float *outZ);
void update_entity_position_and_triggers(float a, float b);
void init_affine_transform_viewport(s32 x, s32 y);
u32 animation_interpolation_step(struct AnimInterp *p);
void update_3d_entity_projections(void);
void sub_0805689C(struct AnimInterp *p, s32 *a);
void update_battle_sprite_status_effects(void);
void sub_08049CB0(u16 color, u32 amount);

#include "audio/sound_seq.h"
#include "audio/sound_driver.h"

#include "engine/main.h"
#include "engine/decompress.h"

#include "engine/bg.h"
#include "engine/math.h"

#include "engine/palette.h"
#include "engine/oam.h"

#include "link/serial.h"
#include "engine/game_state.h"

#include "menu/field_menu.h"
#include "menu/medawatch_menu.h"

#include "menu/medabots_screen.h"
#include "menu/medals_screen.h"

#include "debug/debug_menu.h"
#include "menu/medaparts_screen.h"

#include "battle/prebattle.h"
#include "battle/robattle.h"

#include "battle/battle_bots.h"
#include "battle/battle_hud.h"

#include "battle/command_ring.h"
#include "battle/part_select.h"

#include "battle/medaforce_select.h"
#include "battle/status_screen.h"

#include "battle/battle_setup.h"
#include "battle/robattle_timer.h"

#include "battle/part_stats.h"
#include "battle/bot_movement.h"

#include "battle/status_sprites.h"
#include "battle/action_queue.h"

#include "battle/battle_graphics.h"
#include "battle/turn_order.h"

#include "battle/battle_sprites.h"
#include "battle/action_steps.h"

#include "battle/defend_heal_skills.h"
#include "battle/support_skills.h"

#include "battle/interrupt_skills.h"
#include "battle/medaforce_effects.h"

#include "battle/effect_steps.h"
#include "battle/action_phase.h"

#include "battle/battle_ai.h"
#include "battle/action_script.h"

#include "battle/combat_helpers.h"
#include "battle/closeup_scene.h"

#include "battle/effect_sprites.h"
#include "battle/skill_helpers.h"

#include "battle/particles.h"
#include "battle/action_calc.h"

#include "battle/battle_sequence.h"
#include "link/link_robattle.h"

#include "engine/tilemap.h"
#include "engine/memory.h"

#include "engine/palette_blend.h"
#include "text/message.h"

#include "engine/sprites.h"
#include "text/choice_menu.h"

#include "inventory/inventory.h"
#include "engine/common.h"

#include "engine/sprite_engine.h"
#include "engine/interpolate.h"

#include "field/field_mode.h"
#include "field/script_helpers.h"

#include "field/area_graphics.h"
#include "field/field_utils.h"

#endif // GUARD_FUNCTIONS_H
