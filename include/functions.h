#ifndef GUARD_FUNCTIONS_H
#define GUARD_FUNCTIONS_H

// Prototypes for game functions (decompiled or still in asm), in ROM order.

// elsewhere (unk3C 2/3) or the part is owned
// Robattle action step dispatchers run by the action script (code_08030CAC wrappers)
// amount/32, for the 16-colour palettes in mask
// h, u8 i, u8 j): callers were compiled without a prototype
// h, u8 i, u8 j, u8 base): callers were compiled without a prototype

void CpuSet(const void *src, void *dest, u32 control);
s32 Div(s32 num, s32 denom);    // BIOS SWI 6
s32 DivArm(s32 denom, s32 num); // BIOS SWI 7
s32 Mod(s32 num, s32 denom);    // BIOS SWI 6, returns the remainder
void CpuFastSet(const void *src, void *dest, u32 control);
#define CpuCopy16(src, dest, size) CpuSet(src, dest, ((size) / 2) & 0x1FFFFF)
void VBlankIntrWait(void);
u16 sub_0807C740(u16 kbitSize); // EEPROM library: picks the EEPROM type (4 or 64 kbit)
void irq_dispatch_arm(void);
u16 sub_0807C7A8(u8 timer, Func *slot); // EEPROM library: sets the timer and its IRQ handler slot
void link_buffer_swap_arm(void);        // ARM, crt0.s; copied to IWRAM 0x03005250

// code_0804D10C

// code_0805137C (field)
void LZ77UnCompVram(const void *src, void *dst);

// code_08044CDC
void divide_by_3(u8 a, u8 b); // guess: refreshes racer a's 4-part sprite group at its current position (not a divide)
void sub_08069A68(u8 idx, s16 x, s16 y, u8 h,
                  u8 pal); // guess: places racer idx's 4-part sprite group at x, y and sets its palette
void matrix_set_identity(void);
void ring_points_place_on_hexagon(u32 a);

// code_080490C4

// tiles; align 0 center, 1 left, 2 right
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
// code_0805AB40
// the BG0 tiles masked by gUnk_080AF740
u32 Sqrt(u32 n);
void ObjAffineSet(struct ObjAffineSrcData *src, void *dest, s32 count, s32 offset);
// screen (guess: name entry)

struct ObjSortEntry;
struct RotateSrc;

void sub_08064A74(void);
void sub_08064A94(void);
void sub_08064AB4(void);
void sub_08064AD4(void);
// numbers of a 32x32 screen block, sets palette pal
void LZ77UnCompWram(const void *src, void *dst);
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
void sub_080608EC(void);
void sub_0806174C(void);
void sub_08060FD4(void);
void sub_08061374(void);
void init_fade_screen_setup(void);
void sub_080609C0(void);
void update_animated_tilemap(void);
void update_scroll_animation_tiles(void);
void init_scene_rendering_context(u32 a);
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

#include "field/field_effects.h"
#include "field/field_update.h"

#include "field/map_script.h"
#include "field/map_script_update.h"

#include "field/script_sprites.h"
#include "field/field_walk.h"

#include "field/player_walk.h"
#include "field/map_objects.h"

#include "field/scene_3d.h"
#include "field/vehicle_menu.h"

#include "field/field_debug.h"
#include "engine/bg_draw.h"

#include "menu/item_list.h"
#include "title/screen_helpers.h"

#include "title/title_menu.h"
#include "title/new_game_prompt.h"

#include "menu/item_menu.h"
#include "save/save_screen.h"

#include "save/save_data.h"
#include "menu/name_entry.h"

#endif // GUARD_FUNCTIONS_H
