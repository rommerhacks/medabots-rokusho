// Mode-3 state 0, the power-on state: the licensed-by / Natsume logos (gBootLogosSubStates), then the intro
// (mode 3 state 1). boot_logos_check_skip starts the music and lets START jump to the title screen.
#include "global.h"

void boot_logos_check_skip(void) {
    if (--gSceneWork.unk10.w == 0)
        play_song(3);
    if (gSceneWork.unkC.b != 0 && (KEYS_LO(gNewKeys) & 8)) {
        gGameMode = 3;
        gGameState = 2;
        gGameSubState = 0;
        gTitleSkipIntro = 1;
    }
}

void boot_logos_update(void) {
    gBootLogosSubStates[gGameSubState]();
    boot_logos_check_skip();
}

static bool32 blend_fade_step_0806E2F8(void) {
    if ((gSceneWork.timer & 3) == 0) {
        u8 a = 16 - (gSceneWork.timer >> 2);
        u8 b = 16 - a;
        REG_BLDALPHA = (b << 8) | a;
        if (b == 16)
            return TRUE;
    }
    gSceneWork.timer++;
    return FALSE;
}

void scene_switch_after_blend_fade(void) {
    if (blend_fade_step_0806E2F8()) {
        gSceneWork.timer = 0;
        gGameMode = gSceneWork.nextMode;
        gGameState = gSceneWork.nextState;
        gGameSubState = gSceneWork.nextSubState;
    }
}

void boot_logos_init(void) {
    u32 zero = 0;
    DmaSet(3, &zero, VRAM, 0x85006000);
    zero = 0;
    DmaSet(3, &zero, PLTT, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, gSpriteEntries, 0x85000800);
    zero = 0;
    DmaSet(3, &zero, &gSceneWork, 0x85000005);
    play_song(0);
    REG_DISPCNT = 0x60;
    gSceneWork.nextMode = 3;
    gSceneWork.nextState = 0;
    gSceneWork.timer = 0;
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gTitleSkipIntro = 0;
    setup_screen_transition_effect_080682CC(2, 4, 0);
    gGameSubState = 4;
}

void boot_logos_load_licensed_by(void) {
    u16 map[20][30];
    u16 out[20 * 32];
    s32 i, j;

    LZ77UnCompVram(gLicensedByLogoTiles, (void *)VRAM);
    LZ77UnCompVram(gLicensedByLogoTilemap, map);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            out[i * 32 + j] = *(map[i] + j);
        out[i * 32 + 30] = 0;
        out[i * 32 + 31] = 0;
    }
    DmaSet(3, out, VRAM + 0x7800, 0x84000140);
    DmaSet(3, gLicensedByLogoPalette, PLTT, 0x80000010);
    REG_BG0CNT = 0xF01;
    REG_DISPCNT |= 0x100;
    gSceneWork.nextSubState = 5;
    gGameSubState = 1;
}

void boot_logos_load_natsume(void) {
    u16 map[20][30];
    u16 out[20 * 32];
    s32 i, j;

    LZ77UnCompVram(gNatsumeLogoTiles, (void *)VRAM);
    LZ77UnCompVram(gNatsumeLogoTilemap, map);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            out[i * 32 + j] = *(map[i] + j);
        out[i * 32 + 30] = 0;
        out[i * 32 + 31] = 0;
    }
    DmaSet(3, out, VRAM + 0x7800, 0x84000140);
    DmaSet(3, gNatsumeLogoPalette, PLTT, 0x80000010);
    gSceneWork.unk10.w = 0x34;
    REG_BG0CNT = 0xF02;
    REG_DISPCNT |= 0x100;
    gSceneWork.nextSubState = 7;
    gGameSubState = 1;
}

void boot_logos_load_overlay(void) {
    u16 map[20][30];
    u16 out[20 * 32];
    s32 i, j;

    LZ77UnCompVram(gBootOverlayTiles, (void *)(VRAM + 0x8000));
    LZ77UnCompVram(gBootOverlayTilemap, map);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            out[i * 32 + j] = *(map[i] + j) + 0x1000;
        out[i * 32 + 30] = 0;
        out[i * 32 + 31] = 0;
    }
    DmaSet(3, out, VRAM + 0xF800, 0x84000140);
    DmaSet(3, gBootOverlayPalette, PLTT + 0x20, 0x80000010);
    REG_BG1CNT = 0x1F0B;
    REG_DISPCNT |= 0x200;
    REG_BLDCNT = 0x241;
    REG_BLDALPHA = 0x10;
    gSceneWork.nextSubState = 9;
    gGameSubState = 3;
}

void boot_logos_hold_licensed_by(void) {
    if (gSceneWork.timer == 0) {
    } else if (gSceneWork.timer > 60) {
        gSceneWork.timer = 0;
        gSceneWork.nextSubState = 6;
        gGameSubState = 2;
        return;
    }
    gSceneWork.timer++;
}

void boot_logos_hold_natsume(void) {
    if (gSceneWork.timer == 0) {
        gSceneWork.unkC.b = 1;
    } else if (gSceneWork.timer > 60) {
        gSceneWork.timer = 0;
        gGameSubState = 8;
        return;
    }
    gSceneWork.timer++;
}

void boot_logos_hold_overlay(void) {
    if (gSceneWork.timer == 0) {
        REG_DISPCNT &= 0xFEFF;
    } else if (gSceneWork.timer > 60) {
        gSceneWork.timer = 0;
        setup_screen_transition_effect_080684F0(2, 4, 0);
        gSceneWork.nextSubState = 10;
        gGameSubState = 2;
        return;
    }
    gSceneWork.timer++;
}

void boot_logos_end(void) {
    gGameMode = 3;
    gGameState = 1;
    gGameSubState = 0;
}
