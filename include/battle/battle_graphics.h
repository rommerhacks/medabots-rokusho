#ifndef GUARD_BATTLE_BATTLE_GRAPHICS_H
#define GUARD_BATTLE_BATTLE_GRAPHICS_H

// Battle graphics loading, message windows, UI tilemaps, Medaforce gauge

void sub_0801ABF8(
    void); // text_window_init(1, 2, 0) unless gOptionSkipMessages is set (guess: skipped in link Robattles)
u32 sub_0801AC6C(void);     // game_state_execute_handler_a() unless gOptionSkipMessages is set (then 1)
void sub_0801AC98(u32 rec); // draws the BG1 message frame tilemaps on the team (rec 0-2) or opponent side
u32 battle_load_graphics_step(u32 direct); // one LZ graphics load per call (step 0x0300057A 0-8); returns 1 when done,
u32 sub_0801AC24(u32 msg);                 // run_message(gUnk_083C65C4[msg]) unless gOptionSkipMessages is set (then 1)
void sub_0801AD10(u32 rec); // redraws a Medabot's panel (left_b when the Medaforce gauge is full) and its gauge
void sub_0801AD48(u32 rec); // guess: Medaforce effect: 8 sprites 0x78-0x7F (tiles 0x616-0x619) lined up at y 0x78, x
u32 sub_0801ADE8(u32 rec);  // moves those sprites 4 px per step toward the other side; 1 when all are done
void sub_0801AE70(u32 rec); // animates those sprites (tile 0x616 + frame, every 4 frames)
void sub_0801AEB4(void);
void sub_0801AED4(void);
void clear_battle_ui_tilemaps(void);
u32 medaforce_gauge_fill_step(
    u32 rec); // moves one point from gUnk_03001800.unk51 into the Medaforce gauge (max 80) and redraws it; 1 when done
u32 medaforce_gauge_drain_step(u32 rec); // the same, taking one point out of the gauge
u32 sub_0801B0E8(
    u32 rec); // guess: spins the sprites of sub_0801B004 around the Medabot while they sink; 1 when all 8 are gone
void sub_0801B274(u32 rec); // guess: end of a Medabot's action: unkDE / unkDF = chosen part and its skill, clears the
void sub_0801B3AC(u32 rec); // writes gUnk_03001800.unk11C back into the acting Medabot's part unkA7 when unk118 is set,
void sub_0801B004(u32 rec); // guess: 8 sprites 0x21-0x28 in a circle (radius 16) around the Medabot's sprite, OBJ

#endif // GUARD_BATTLE_BATTLE_GRAPHICS_H
