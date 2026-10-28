// Game mode 1 (field) entry: field RAM reset (field_clear_ram), the mode-1 state dispatcher (gUnk_083D1F84),
// and the transitions out of field scripts into other modes and states (switch_game_mode: battle, shop,
// title-mode screens, minigames). Called by the field, menu, shop and minigame modules.

#include "global.h"

static void field_clear_ram(void) {
    memzero_bytes((u8 *)&gFieldState, 0x3C);
    memzero_bytes((u8 *)&gFieldDebug, 0x38);
    memzero_bytes((u8 *)&gFieldTilemapBuf, 4);
    memzero_bytes((u8 *)&gAreaAnimTileSrc, 4);
    memzero_bytes((u8 *)&gUnk_0300534C, 4);
    memzero_bytes((u8 *)gEntityStates, 0x200);
    memzero_bytes((u8 *)gAffineParams, 0x200);
    memzero_bytes((u8 *)&gBlendEffect, 0x34);
    memzero_bytes((u8 *)&gFieldSceneParams, 8);
    memzero_bytes((u8 *)&gScriptCmdWork, 0x10);
    memzero_bytes((u8 *)&gEventFlags, 4);
    memzero_bytes((u8 *)&gMapScriptData, 4);
    memzero_bytes((u8 *)&gFieldEffect, 0x240);
    memzero_bytes((u8 *)&gFieldEffectEntities, 4);
    memzero_bytes((u8 *)&gFieldScriptWork, 0x874);
}

void field_mode_dispatch(void) {
    gUnk_083D1F84[gGameState]();
}

// guess: back to the field after a battle (0: sub-state 5 or 13) or into field state 2 (1).
void field_resume(u32 a) {
    switch (a) {
    case 0:
        gFieldState.sceneResult = gGameWork.unk9C;
        if (gFieldWork.script_running != 0) {
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
        gScriptCmdWork.mode_result = 7;
        break;
    case 8:
        gScriptCmdWork.mode_result = 8;
        break;
    case 10:
        field_clear_ram();
        memzero_bytes((u8 *)&gFieldWork, 0xCC0);
        gPlayTimeRunning = 1;
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 0;
        return;
    case 11:
        field_clear_ram();
        gFieldWork.script_running = 0;
        gFieldWork.cmd_busy = 0;
        gPlayTimeRunning = 1;
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 10;
        return;
    case 9:
        gPlayTimeRunning = 1;
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
        gFieldWork.fixed_battle = 1;
        gGameMode = 0;
        gGameState = 6;
        gGameSubState = 0;
        break;
    case 0x21:
        gFieldWork.fixed_battle = 0;
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
        gNameEntryMode = 0;
        gGameMode = 2;
        gGameState = 0x12;
        gGameSubState = 0;
        break;
    case 1:
        gNameEntryMode = 1;
        gGameMode = 2;
        gGameState = 0x12;
        gGameSubState = 0;
        break;
    case 2:
        gNameEntryMode = 2;
        gGameMode = 2;
        gGameState = 0x12;
        gGameSubState = 0;
        break;
    case 3:
        gShopId = b;
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
        gPlayTimeRunning = 0;
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
