#ifndef GUARD_BATTLE_BATTLE_GRAPHICS_H
#define GUARD_BATTLE_BATTLE_GRAPHICS_H

// Battle graphics loading, message windows, Medabot panels, UI tilemaps, Medaforce gauge

// One LZ graphics load per call (step gGameWork.gfxLoadStep 0-8); returns 1 when done. direct = 0 stages the
// palettes in the EWRAM buffer instead of palette RAM.
u32 battle_load_graphics_step(u32 direct);
// Battle message window: open, print message msg (gBattleMessages), finish (close). With gOptionSkipMessages set they
// do nothing and report done, unless gGameWork.skipBotSetup == 1 forces the message.
void battle_message_open(void);
u32 battle_message_print(u32 msg);
u32 battle_message_finish(void);
// Draws the BG1 frame of a Medabot's panel on its side (bot 0-2 = player, left; 3-5 = opponent, right).
void draw_bot_panel_frame(u32 bot);
// Draws a Medabot's panel (left_b when the Medaforce gauge is full) and its gauge.
void draw_bot_status_panel(u32 bot);
// The 8 arrow sprites 0x78-0x7F (tiles 0x616-0x619) that run from the actor's panel toward the target's
// (target_panels_show): init on the actor's side, slide 4 px every 2 frames (1 when all arrived), animate.
void target_arrows_init(u32 bot);
u32 target_arrows_slide(u32 bot);
void target_arrows_animate(u32 bot);
// Clear the step state of target_panels_show / miss_popup_run (unk9C) and of battle_message_show (unkA1).
void battle_substeps_reset(void);
void battle_message_reset(void);
void clear_battle_ui_tilemaps(void);
// Moves one point from gBattleWork.unk51 into the Medaforce gauge (max 80) and redraws it; 1 when done.
u32 medaforce_gauge_fill_step(u32 bot);
// The same, taking one point out of the gauge.
u32 medaforce_gauge_drain_step(u32 bot);
// 8 sparkle sprites 0x21-0x28 in a circle (radius 16) around the Medabot while its Medaforce gauge fills; update
// spins them up and around it and returns 1 when all 8 are gone.
void mf_charge_sparkles_init(u32 bot);
u32 mf_charge_sparkles_update(u32 bot);
// End of a Medabot's action: unkDE / unkDF = chosen part and its skill, clears the per-turn part and defence
// state, then restore_changed_part.
void battle_action_cleanup(u32 bot);
// Writes the part saved by a Change skill (gBattleWork.unk11C, flag unk118) back into the acting Medabot's
// part unkA7 and reloads the part sprites.
void restore_changed_part(u32 bot);

#endif // GUARD_BATTLE_BATTLE_GRAPHICS_H
