// Game mode 0 dispatcher (dispatch_game_state_handler_08002534 runs gGameState's handler: field menu,
// Medawatch, Medabots, Medals, Medaparts, pre-battle, Robattle, debug menu...) and game state 0, a developer
// test screen (BG scroll, message / text window / choice menu tests; not reachable in normal play).

#include "global.h"

void dispatch_game_state_handler_08002534(void) {
    gGameStateHandlers_083AC148[gGameState]();
}

void dispatch_game_substate_handler_08002554(void) {
    gUnk_083AC248[gGameSubState]();
}

void sub_08002574(void) {
    u16 priority;
    REG_BLDCNT = 0;
    REG_BLDY = 0;
    REG_DISPCNT = 0x1260;
    priority = 9; // the low bits have to go through a variable to load 0x5E09 straight into r0
    REG_BG1CNT = priority | 0x5E00;
    gUnk_03000440.unk85 = 1;
    gGameSubState++;
}

// guess: debug map viewer input (D-pad scrolls gBg1Scroll, START/SELECT open text windows)
void sub_080025B4(void) {
    if (KEYS_LO(gHeldKeys) & 0x40)
        gBg1Scroll.y++;
    if (KEYS_LO(gHeldKeys) & 0x80)
        gBg1Scroll.y--;
    if (KEYS_LO(gHeldKeys) & 0x20)
        gBg1Scroll.x++;
    if (KEYS_LO(gHeldKeys) & 0x10)
        gBg1Scroll.x--;
    if (KEYS_LO(gNewKeys) & 2)
        gUnk_03000440.unk88 ^= 1;
    if (KEYS_LO(gNewKeys) & 1) {
        gUnk_03000440.unkE = 0;
        gGameSubState++;
        gUnk_03000440.unk85 ^= 1;
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
    u8 r = message_portrait_anim_step(0, 1, 8, 4, gUnk_03000440.unk88, gUnk_03000440.unk85);
    if (r == 1)
        gGameSubState = r;
}

void init_save_prompt_text(void) {
    u8 r;

    gUnk_03002B70.unk4[0] = 0x17;
    gUnk_03002B70.unk4[1] = 0x29;
    gUnk_03002B70.unk4[2] = 0x2C;
    gUnk_03002B70.unk4[3] = 0x25;
    gUnk_03002B70.unk4[4] = 0;
    gUnk_03002B70.unk4[5] = 0x2E;
    gUnk_03002B70.unk4[6] = 0x1F;
    gUnk_03002B70.unk4[7] = 0x2D;
    gUnk_03002B70.unk4[8] = 0x2E;
    gUnk_03002B70.unk4[9] = 0xFE;
    r = run_message(gUnk_083B53F8[0]);
    if (r == 1)
        gGameSubState = r;
}

void sub_08002730(void) {
    if (run_message(gUnk_083B53F8[1])) {
        open_choice_menu(0, 0x16, 7);
        gGameSubState++;
    }
}

void sub_0800275C(void) {
    if (poll_choice_menu()) {
        sub_0803FB0C();
        gGameSubState++;
    }
}

void sub_0800277C(void) {
    const void *msg;

    if (gUnk_03000440.unk28 & 0xF0)
        msg = gUnk_083B53F8[3];
    else
        msg = gUnk_083B53F8[2];
    if (run_message(msg))
        gGameSubState = 1;
}
