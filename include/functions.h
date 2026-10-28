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

// code_080490C4

// tiles; align 0 center, 1 left, 2 right

// Robattle (game state 7) helpers
// direct = palettes straight to PLTT
// 0x5C team / 0x94 opponents
// per-turn part flags
// then clears partChanged..
// palette 6 from gMfChargeSparklePalette
// can't use Medaforce)

// Medal level, Propulsion)

// 0x11/0x12 (2), 0x13/0x14 (4)

void *memcpy_optimized(void *dst, const void *src, u32 n); // library
void *memcpy(void *dst, const void *src, unsigned long n); // libc (the compiler's builtin)
void *custom_memset(void *dst, int c, u32 n);              // library
u16 ReadEepromDword(u16 address, u16 *data);               // EEPROM library: reads 8 bytes
u16 ProgramEepromDword(u16 address, u16 *data);            // EEPROM library: writes 8 bytes
u32 ProgramEepromDwordEx(u16 address, u16 *data);          // EEPROM library: writes 8 bytes and verifies; u32 so
                                                  // save_lost_erase_and_restart tests the result without truncating it
// code_0805AB40
// the BG0 tiles masked by gTitleOptionValueMasks
u32 Sqrt(u32 n);
void ObjAffineSet(struct ObjAffineSrcData *src, void *dest, s32 count, s32 offset);
// screen (guess: name entry)

struct ObjSortEntry;

// numbers of a 32x32 screen block, sets palette pal
void LZ77UnCompWram(const void *src, void *dst);
// code_0805EE6C
// gGameWork.textBuf (+0x14 if second), 0xFE-terminated
// = gShopkeeperPortraitSets[gShopId]; one caller passes only dst, src
// gDecompressBuffer to VRAM 0x06004020
// up sprite 0 at (0xB8, 0x38)

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

#include "title/test_mode.h"
#include "title/game_over.h"

#include "save/save_lost.h"
#include "menu/town_map.h"

#include "shop/shop_menu.h"
#include "shop/shop_list.h"

#include "shop/shop_return.h"
#include "link/link_trade.h"

#include "title/scroll_banner.h"
#include "link/link_medal_sync.h"

#include "shop/medal_shop.h"
#include "engine/blend_fade.h"

#include "link/link_start.h"
#include "link/link_menu.h"

#include "engine/rings_3d.h"
#include "cutscene/text_scroll.h"

#include "battle/medal_level_up.h"
#include "engine/scene_transition.h"

#include "minigame/race.h"
#include "minigame/bomb_game.h"

#include "title/title_screen.h"
#include "cutscene/event_picture.h"

#include "title/boot_logos.h"
#include "title/intro.h"
#include "cutscene/medabots_weekly.h"

#endif // GUARD_FUNCTIONS_H
