// Mode-2 state 28 (guess: the "start a new game?" prompt, reached from the title menu's New Game; scenario
// 03_new_game_intro runs it): dispatch_rotation_menu_substate runs gUnk_080AF7A8 (load the window, message,
// yes / no choice); yes starts the intro through dispatch_by_index_0476e8, no fades back to state 3.
#include "global.h"

void new_game_prompt_init(void) {
    u32 zero = 0;

    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    clear_battle_sprite_slot(0, 0x80);
    reset_bg_scroll();
    REG_DISPCNT = 0x60;
    CpuFastSet(gSpriteFontPalette, &gPaletteBackup[0xF0], 8);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
    text_window_init(1, 2, 0);
    REG_DISPCNT |= 0x1000;
    gGameSubState++;
}

void load_rotation_grid_and_advance(void) {
    u8 buf[0x54];
    memcpy_optimized(buf, gUnk_080AF755, 0x53);
    if (run_message(buf)) {
        open_choice_menu(1, 0x16, 7);
        gGameSubState++;
    }
}

void new_game_prompt_poll_choice(void) {
    if (poll_choice_menu()) {
        if (gGameWork.unk2A == 0)
            gGameSubState++;
        else
            gGameSubState += 2;
    }
}

void new_game_prompt_start_intro(void) {
    if (game_state_execute_handler_a())
        dispatch_by_index_0476e8(10);
}

void advance_substate_with_fade(void) {
    if (game_state_execute_handler_a()) {
        gGameSubState++;
        init_blend_effect(gMenuWork->blend, 0, 0, 1, 0xC0);
    }
}

void fade_step_and_transition_to_mode3(void) {
    if (blend_fade_step_08065598(gMenuWork->blend)) {
        gGameState = 3;
        gGameSubState = 0;
    }
}

// guess: options screen sub-states (gUnk_080AF7A8); the inherited name is probably wrong
void dispatch_rotation_menu_substate(void) {
    struct FuncTable6 t = gUnk_080AF7A8;
    t.f[gGameSubState]();
}
