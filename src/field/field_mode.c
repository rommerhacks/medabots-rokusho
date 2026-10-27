// Game mode 1 (field) entry: field RAM reset (field_clear_ram), the mode-1 state dispatcher (gUnk_083D1F84),
// and the transitions out of field scripts into other modes and states (switch_game_mode: battle, shop,
// title-mode screens, minigames). Called by the field, menu, shop and minigame modules.

#include "global.h"

static void field_clear_ram(void) {
    memzero_bytes((u8 *)&gUnk_03005310, 0x3C);
    memzero_bytes((u8 *)&gUnk_030057A0, 0x38);
    memzero_bytes((u8 *)&gUnk_03006D14, 4);
    memzero_bytes((u8 *)&gUnk_030057DC, 4);
    memzero_bytes((u8 *)&gUnk_0300534C, 4);
    memzero_bytes((u8 *)gUnk_030055A0, 0x200);
    memzero_bytes((u8 *)gUnk_03006D40, 0x200);
    memzero_bytes((u8 *)&gUnk_03006F40, 0x34);
    memzero_bytes((u8 *)&gUnk_03006D38, 8);
    memzero_bytes((u8 *)&gUnk_03006D20, 0x10);
    memzero_bytes((u8 *)&gUnk_030057D8, 4);
    memzero_bytes((u8 *)&gMapScriptData, 4);
    memzero_bytes((u8 *)&gUnk_03005350, 0x240);
    memzero_bytes((u8 *)&gUnk_03006D30, 4);
    memzero_bytes((u8 *)&gUnk_030064A0, 0x874);
}

void field_mode_dispatch(void) {
    gUnk_083D1F84[gGameState]();
}

// guess: back to the field after a battle (0: sub-state 5 or 13) or into field state 2 (1).
void field_resume(u32 a) {
    switch (a) {
    case 0:
        gUnk_03005310.unk39 = gUnk_03000440.unk9C;
        if (gUnk_030057E0.unkC88 != 0) {
            gGameMode = 1;
            gGameState = 1;
            gGameSubState = 5;
        } else {
            gGameMode = 1;
            gGameState = 1;
            gGameSubState = 13;
        }
        break;
    case 1:
        gGameMode = 1;
        gGameState = 2;
        gGameSubState = 0;
        break;
    }
}

void dispatch_by_index_0476e8(u32 idx) {
    switch (idx) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 12:
        break;
    case 4:
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0x10;
        return;
    case 5:
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0x20;
        return;
    case 6:
        gGameMode = 1;
        gGameState = 2;
        gGameSubState = 8;
        return;
    case 7:
        gUnk_03006D20.unkC = 7;
        break;
    case 8:
        gUnk_03006D20.unkC = 8;
        break;
    case 10:
        field_clear_ram();
        memzero_bytes((u8 *)&gUnk_030057E0, 0xCC0);
        gUnk_03000588 = 1;
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0;
        return;
    case 11:
        field_clear_ram();
        gUnk_030057E0.unkC88 = 0;
        gUnk_030057E0.unkC89 = 0;
        gUnk_03000588 = 1;
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 10;
        return;
    case 9:
        gUnk_03000588 = 1;
        break;
    default:
        return;
    }
    gGameMode = 1;
    gGameState = 1;
    gGameSubState = 5;
}

void field_return_from_scene(s32 mode) {
    if (mode > 3)
        return;
    if (mode < 0)
        return;
    gGameMode = 1;
    gGameState = 1;
    gGameSubState = 5;
}

// Runtime: id 4 when leaving the shop (07_shop, from dispatch_and_increment_state).
void switch_game_mode(u32 a, u32 b) {
    switch (a) {
    case 0x20:
        gUnk_030057E0.unkC2D = 1;
        gGameMode = 0;
        gGameState = 6;
        gGameSubState = 0;
        break;
    case 0x21:
        gUnk_030057E0.unkC2D = 0;
        gGameMode = 0;
        gGameState = 6;
        gGameSubState = 0;
        break;
    case 0x40:
        gGameMode = 0;
        gGameState = 1;
        gGameSubState = 0x10;
        break;
    case 0x41:
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0x18;
        break;
    case 0x42:
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0x1C;
        break;
    case 0x43:
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0x28;
        break;
    case 0:
        gUnk_03000584 = 0;
        gGameMode = 2;
        gGameState = 0x12;
        gGameSubState = 0;
        break;
    case 1:
        gUnk_03000584 = 1;
        gGameMode = 2;
        gGameState = 0x12;
        gGameSubState = 0;
        break;
    case 2:
        gUnk_03000584 = 2;
        gGameMode = 2;
        gGameState = 0x12;
        gGameSubState = 0;
        break;
    case 3:
        gUnk_03002420 = b;
        gGameMode = 2;
        gGameState = 0xB;
        gGameSubState = 0;
        break;
    case 4:
        gGameMode = 2;
        gGameState = 0x15;
        gGameSubState = 0;
        break;
    case 5:
        gUnk_03000588 = 0;
        gGameMode = 2;
        gGameState = 0x14;
        gGameSubState = 0;
        break;
    case 6:
        gGameMode = 2;
        gGameState = 0x17;
        gGameSubState = 0;
        break;
    case 8:
        gGameMode = 2;
        gGameState = 0x16;
        gGameSubState = 0;
        break;
    case 0x10:
        gGameMode = 3;
        gGameState = 4;
        gGameSubState = 0;
        break;
    case 0x11:
        gGameMode = 3;
        gGameState = 5;
        gGameSubState = 0;
        break;
    case 0x12:
        gGameMode = 3;
        gGameState = 3;
        gGameSubState = 0;
        break;
    case 0x13:
        gGameMode = 3;
        gGameState = 6;
        gGameSubState = 0;
        break;
    }
}
