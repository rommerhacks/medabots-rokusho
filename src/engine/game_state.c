// Game mode 0 dispatcher (dispatch_game_state_handler_08002534 runs gGameState's handler: field menu,
// Medawatch, Medabots, Medals, Medaparts, pre-battle, Robattle, debug menu...) and game state 0, a developer
// test screen (BG scroll, message / text window / choice menu tests; not reachable in normal play).

#include "global.h"

void dispatch_game_state_handler_08002534(void) {
    gGameStateHandlers_083AC148[gGameState]();
}

void dispatch_game_substate_handler_08002554(void) {
    gDevTestStates[gGameSubState]();
}

// Sub-state 0: shows BG1 over the screen.
void devtest_init(void) {
    u16 priority;
    REG_BLDCNT = 0;
    REG_BLDY = 0;
    REG_DISPCNT = 0x1260;
    priority = 9; // the low bits have to go through a variable to load 0x5E09 straight into r0
    REG_BG1CNT = priority | 0x5E00;
    gGameWork.unk85 = 1;
    gGameSubState++;
}

// guess: debug map viewer input (D-pad scrolls gBg1Scroll, START/SELECT open text windows)
// Sub-state 1: D-pad scrolls BG1; A, Start and Select start the tests, B leaves for the field menu state.
void devtest_update(void) {
    if (KEYS_LO(gHeldKeys) & 0x40)
        gBg1Scroll.y++;
    if (KEYS_LO(gHeldKeys) & 0x80)
        gBg1Scroll.y--;
    if (KEYS_LO(gHeldKeys) & 0x20)
        gBg1Scroll.x++;
    if (KEYS_LO(gHeldKeys) & 0x10)
        gBg1Scroll.x--;
    if (KEYS_LO(gNewKeys) & 2)
        gGameWork.menuRowAnim ^= 1;
    if (KEYS_LO(gNewKeys) & 1) {
        gGameWork.unkE = 0;
        gGameSubState++;
        gGameWork.unk85 ^= 1;
    }
    if (KEYS_LO(gNewKeys) & 2) {
        gGameState = 1;
        gGameSubState = 0;
    }
    if (KEYS_LO(gNewKeys) & 8) {
        text_window_init(0, 0, 0);
        gGameSubState += 2;
    }
    if (KEYS_LO(gNewKeys) & 4) {
        text_window_init(0, 0, 0);
        gGameSubState += 3;
    }
}

void load_overworld_column_and_advance(void) {
    u8 r = message_portrait_anim_step(0, 1, 8, 4, gGameWork.menuRowAnim, gGameWork.unk85);
    if (r == 1)
        gGameSubState = r;
}

void init_save_prompt_text(void) {
    u8 r;

    gPlayerRecord.name[0] = 0x17;
    gPlayerRecord.name[1] = 0x29;
    gPlayerRecord.name[2] = 0x2C;
    gPlayerRecord.name[3] = 0x25;
    gPlayerRecord.name[4] = 0;
    gPlayerRecord.name[5] = 0x2E;
    gPlayerRecord.name[6] = 0x1F;
    gPlayerRecord.name[7] = 0x2D;
    gPlayerRecord.name[8] = 0x2E;
    gPlayerRecord.name[9] = 0xFE;
    r = run_message(gMenuMessages[0]);
    if (r == 1)
        gGameSubState = r;
}

void devtest_message_then_choice(void) {
    if (run_message(gMenuMessages[1])) {
        open_choice_menu(0, 0x16, 7);
        gGameSubState++;
    }
}

void devtest_wait_choice(void) {
    if (poll_choice_menu()) {
        message_next();
        gGameSubState++;
    }
}

// guess: shows one of two messages depending on the choice made, then returns to sub-state 1.
void devtest_show_choice_result(void) {
    const void *msg;

    if (gGameWork.unk28 & 0xF0)
        msg = gMenuMessages[3];
    else
        msg = gMenuMessages[2];
    if (run_message(msg))
        gGameSubState = 1;
}
