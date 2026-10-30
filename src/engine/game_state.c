// Game mode 0 dispatcher (menu_battle_mode_update runs gGameState's handler, MODE0_STATE_* in constants/game_states.h:
// field menu, Medawatch, Medabots, Medals, Medaparts, pre-battle, Robattle, debug menu...) and game state 0, a
// developer test screen (BG scroll, message / text window / choice menu tests; not reachable in normal play).

#include "global.h"

void menu_battle_mode_update(void) {
    gMenuBattleModeStates[gGameState]();
}

void devtest_dispatch(void) {
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
    gGameWork.repeatCounter = 1;
    gGameSubState++;
}

// guess: debug map viewer input (D-pad scrolls gBg1Scroll, START/SELECT open text windows)
// Sub-state 1: D-pad scrolls BG1; A, Start and Select start the tests, B leaves for the field menu state.
void devtest_update(void) {
    if (KEYS_LO(gHeldKeys) & DPAD_UP)
        gBg1Scroll.y++;
    if (KEYS_LO(gHeldKeys) & DPAD_DOWN)
        gBg1Scroll.y--;
    if (KEYS_LO(gHeldKeys) & DPAD_LEFT)
        gBg1Scroll.x++;
    if (KEYS_LO(gHeldKeys) & DPAD_RIGHT)
        gBg1Scroll.x--;
    if (KEYS_LO(gNewKeys) & B_BUTTON)
        gGameWork.menuRowAnim ^= 1;
    if (KEYS_LO(gNewKeys) & A_BUTTON) {
        gGameWork.portraitAnimFrame = 0;
        gGameSubState++;
        gGameWork.repeatCounter ^= 1;
    }
    if (KEYS_LO(gNewKeys) & B_BUTTON) {
        gGameState = 1;
        gGameSubState = 0;
    }
    if (KEYS_LO(gNewKeys) & START_BUTTON) {
        text_window_init(0, 0, 0);
        gGameSubState += 2;
    }
    if (KEYS_LO(gNewKeys) & SELECT_BUTTON) {
        text_window_init(0, 0, 0);
        gGameSubState += 3;
    }
}

void load_overworld_column_and_advance(void) {
    u8 done = message_portrait_anim_step(0, 1, 8, 4, gGameWork.menuRowAnim, gGameWork.repeatCounter);
    if (done == 1)
        gGameSubState = done;
}

void init_save_prompt_text(void) {
    u8 done;

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
    done = run_message(gMenuMessages[0]);
    if (done == 1)
        gGameSubState = done;
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

    if (gGameWork.choiceResult & 0xF0)
        msg = gMenuMessages[3];
    else
        msg = gMenuMessages[2];
    if (run_message(msg))
        gGameSubState = 1;
}
