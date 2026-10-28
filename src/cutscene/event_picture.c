// Mode-3 state 3: a full-screen picture with a message, entered from a field script (switch_game_mode case 0x12;
// the picture index comes from map script command map_script_cmd_event_picture). Returns to the field afterwards. Its
// fade-and-switch steps scene_switch_after_transition / scene_complete_dma_and_restore_state are shared by the boot
// logos and intro tables. Name is a guess.
#include "global.h"

void dispatch_game_substate_handler_0806DFA4(void) {
    gStoryIntroHandlers[gGameSubState]();
}

void scene_switch_after_transition(void) {
    if (scene_transition_step_080686F4()) {
        gGameMode = gSceneWork.nextMode;
        gGameState = gSceneWork.nextState;
        gGameSubState = gSceneWork.nextSubState;
    }
}

void scene_complete_dma_and_restore_state(void) {
    if (execute_scene_step()) {
        u32 zero = 0;
        DmaSet(3, &zero, gSpriteEntries, 0x85000800);
        REG_DISPCNT &= 0x80FF;
        gGameMode = gSceneWork.nextMode;
        gGameState = gSceneWork.nextState;
        gGameSubState = gSceneWork.nextSubState;
    }
}

void event_picture_init(void) {
    u32 zero = 0;
    DmaSet(3, &zero, VRAM, 0x85006000);
    zero = 0;
    DmaSet(3, &zero, PLTT, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, gSpriteEntries, 0x85000800);
    zero = 0;
    DmaSet(3, &zero, &gSceneWork, 0x85000004);
    REG_DISPCNT = 0x60;
    gSceneWork.nextMode = 3;
    gSceneWork.nextState = 3;
    gSceneWork.unkC.h = gFieldSceneParams.event_picture_id;
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gGameSubState = 3;
}

void battle_init_tilemap_and_palette(void) {
    u16 map[20][30];
    u16 out[20 * 32];
    s32 i, j;

    LZ77UnCompVram(gStoryIntroTiles[gSceneWork.unkC.h], (void *)(VRAM + 0x8000));
    LZ77UnCompVram(gStoryIntroTilemaps[gSceneWork.unkC.h], map);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            out[i * 32 + j] = map[i][j];
        out[i * 32 + 30] = 0;
        out[i * 32 + 31] = 0;
    }
    DmaSet(3, out, VRAM + 0x7800, 0x84000140);
    DmaSet(3, gStoryIntroPalettes[gSceneWork.unkC.h], PLTT, 0x800000E0);
    REG_BG1CNT = 0xF8B;
    setup_screen_transition_effect_080682CC(2, 1, 0);
    text_window_init(1, 2, 0);
    REG_DISPCNT |= 0x200;
    gSceneWork.nextSubState = 4;
    gGameSubState = 1;
}

void dispatch_battle_event_script(void) {
    if (run_message(gStoryIntroTexts[gSceneWork.unkC.h])) {
        gSceneWork.nextSubState = 5;
        gGameSubState = 2;
    }
}

void event_picture_return_to_field(void) {
    field_return_from_scene(2);
}
