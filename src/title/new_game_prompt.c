// Mode-2 state 28 (guess: the "start a new game?" prompt, reached from the title menu's New Game; scenario
// 03_new_game_intro runs it): new_game_prompt_update runs gNewGamePromptStates (load the window, message,
// yes / no choice); yes starts the intro through dispatch_by_index_0476e8, no fades back to the title menu (state 3).
#include "global.h"

void new_game_prompt_init(void) {
    u32 zero = 0;

    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    clear_battle_sprite_slot(0, 0x80);
    reset_bg_scroll();
    REG_DISPCNT = 0x60;
    CpuFastSet(gSpriteFontPalette, &gPaletteBackup[0xF0], 8);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)(OBJ_VRAM0 + 0x7400));
    text_window_init(1, 2, 0);
    REG_DISPCNT |= 0x1000;
    gGameSubState++;
}

void new_game_prompt_show_message(void) {
    u8 buf[0x54];
    memcpy_optimized(buf, gNewGamePromptMessage, 0x53);
    if (run_message(buf)) {
        open_choice_menu(1, 0x16, 7);
        gGameSubState++;
    }
}

void new_game_prompt_poll_choice(void) {
    if (poll_choice_menu()) {
        if (gGameWork.choiceCursor == 0)
            gGameSubState++;
        else
            gGameSubState += 2;
    }
}

void new_game_prompt_start_intro(void) {
    if (game_state_execute_handler_a())
        dispatch_by_index_0476e8(10);
}

void new_game_prompt_fade_out(void) {
    if (game_state_execute_handler_a()) {
        gGameSubState++;
        init_blend_effect(gMenuWork->blend, 0, 0, 1, 0xC0);
    }
}

void new_game_prompt_return_to_title(void) {
    if (blend_effect_step(gMenuWork->blend)) {
        gGameState = 3;
        gGameSubState = 0;
    }
}

// Runs the prompt's sub-states: init, message, choice, then start the intro or fade back to the title menu.
void new_game_prompt_update(void) {
    struct FuncTable6 states = gNewGamePromptStates;
    states.f[gGameSubState]();
}
