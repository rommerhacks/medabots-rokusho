// Mode-3 state 6: Medabots Weekly, the in-game TV show. medabots_weekly_update runs the scrolling / animated BG
// helpers, then gMedabotsWeeklySubStates[gGameSubState] (19 entries, init first). Runtime (scenario
// 20_medabots_weekly): a TV studio whose curtains (sprites 0-10 right half, 11-21 left half) open; four
// characters (sprites 22-25, shadows 26-29) walk or jump on stage and talk (gWeeklyMessages 0-7); then the
// "Medabots Lecture" corner builds a Medabot part by part (head, both arms, legs, then the Medal and a white
// flash, gWeeklyLectureSteps); back in the studio a closing talk, the curtains close and the game returns to
// mode 1. Sprite moves are effects from gWeeklySpriteEffects, run every frame by weekly_run_sprite_effects.
#include "global.h"
#include "constants/sprites.h"

// gSpriteEntries work[] / work16[] indices
#define WEEKLY_SPR_EFFECT 0x0       // gWeeklySpriteEffects index + 1, 0 = none
#define WEEKLY_SPR_EFFECT_STEP 0x1  // curtain effects: steps taken (gWeeklyCurtainOpenTimes / CloseTimes index)
#define WEEKLY_SPR_CYCLE_STEP 0x1   // cycle anim (sprites 0x16-0x19): gCycleAnimFrameOffsets index, 0-3
#define WEEKLY_SPR_NEXT_STRIP 0x2   // curtain strips: the next strip's sprite, 0xFF = the last one (0 once it is done)
#define WEEKLY_SPR_CYCLE_PERIOD 0x3 // cycle anim: frames per frame step, 0 = stopped
#define WEEKLY_SPR_BASE_FRAME 0     // work16: cycle anim base frame
#define WEEKLY_SPR_CYCLE_TIMER 1    // work16: cycle anim frame counter
#define WEEKLY_SPR_DURATION 2       // work16: frames the effect runs (walk / jump effects)

// Scrolls BG3 down one line every other frame (gMedabotsWeekly.scrollBg3, the lecture backdrop).
void weekly_scroll_bg3(void) {
    if (gFrameCounter & 1)
        gBg3Scroll.y++;
}

// Studio frame update: cycles the two animated BG tile strips, runs the sprite effects and the cycle anims.
void weekly_update_studio(void) {
    if ((gFrameCounter & 3) == 0) {
        if (++gMedabotsWeekly.tileFrame > 5)
            gMedabotsWeekly.tileFrame = 0;
        DmaSet(3, gWeeklyAnimTiles + gMedabotsWeekly.tileFrame * 0x280, VRAM + 0x4020, 0x84000040);
    }
    if ((gFrameCounter & 0xF) == 0) {
        if (++gMedabotsWeekly.tileFrame2 > 5)
            gMedabotsWeekly.tileFrame2 = 0;
        if (gMedabotsWeekly.tileFrame2 <= 5)
            DmaSet(3, gWeeklyAnimTiles2 + gMedabotsWeekly.tileFrame2 * 0x280, VRAM + 0x4120, 0x84000060);
    }
    weekly_run_sprite_effects();
    if (gWeeklyCycleAnimMask != 0)
        sprite_cycle_anim_update();
}

void medabots_weekly_update(void) {
    if (gMedabotsWeekly.scrollBg3 != 0)
        weekly_scroll_bg3();
    if (gMedabotsWeekly.animTiles != 0)
        weekly_update_studio();
    gMedabotsWeeklySubStates[gGameSubState]();
}

// Sub-state 0: clears VRAM, palettes and sprites, then loads the studio (sub-state 3).
void medabots_weekly_init(void) {
    vu32 zero;

    zero = 0;
    DmaSet(3, &zero, VRAM, 0x85006000);
    zero = 0;
    DmaSet(3, &zero, PLTT, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, gSpriteEntries, 0x85000800);
    zero = 0;
    DmaSet(3, &zero, &gMedabotsWeekly, 0x85000005);
    play_song(0);
    REG_DISPCNT = 0x60;
    gMedabotsWeekly.nextMode = 3;
    gMedabotsWeekly.nextState = 6;
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gWeeklyCycleAnimMask = 0;
    gGameSubState = 3;
}

// Sub-state 3: decompresses the studio graphics and builds the curtain (0-21), character (22-25) and shadow
// (26-29) sprites; continues with sub-state 4, then 6.
void weekly_load_studio(void) {
    s32 i;

    LZ77UnCompVram(gWeeklyStudioBgTiles, (void *)0x06004000);
    LZ77UnCompVram(gWeeklyLectureBgTiles, (void *)0x06008000);
    LZ77UnCompVram(gWeeklyStudioBg1Tilemap, (void *)0x06006800);
    LZ77UnCompVram(gWeeklyStudioBg2Tilemap, (void *)0x06007000);
    LZ77UnCompVram(gWeeklyStudioBg3Tilemap, (void *)0x06007800);
    LZ77UnCompVram(gWeeklyLectureBg1Tilemap, (void *)0x0600A800);
    LZ77UnCompVram(gWeeklyLectureBg2Tilemap, (void *)0x0600B000);
    LZ77UnCompVram(gWeeklyLectureBg3Tilemap, (void *)0x0600B800);
    LZ77UnCompVram(gWeeklyObjTiles, (void *)0x06010000);

    for (i = 0; i <= 10; i++) {
        sprite_entry_init(i, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x50E, 4, 3);
        gSpriteEntries[i].x = i * 8 + 0x78;
        gSpriteEntries[i].y = 0;
        gSpriteEntries[i].order = i + 0x40;
        gSpriteEntries[i].work[WEEKLY_SPR_NEXT_STRIP] = i + 1;
        sprite_entry_init(i + 11, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x50E, 4, 3);
        gSpriteEntries[i + 11].x = 0x70 - i * 8;
        gSpriteEntries[i + 11].y = 0;
        gSpriteEntries[i + 11].order = i + 0x40;
        gSpriteEntries[i + 11].work[WEEKLY_SPR_NEXT_STRIP] = i + 12;
    }
    gSpriteEntries[10].work[WEEKLY_SPR_NEXT_STRIP] = 0xFF;
    gSpriteEntries[21].work[WEEKLY_SPR_NEXT_STRIP] = 0xFF;

    for (i = 0; i <= 3; i++) {
        sprite_entry_init(i + 22, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3), 0, i, 1);
        gSpriteEntries[i + 22].y = 0x40;
    }
    gSpriteEntries[22].x = 0x10;
    gSpriteEntries[22].order = 8;
    gSpriteEntries[23].x = 0xD0;
    gSpriteEntries[23].order = 8;
    gSpriteEntries[24].x = 0x10;
    gSpriteEntries[24].order = 4;
    gSpriteEntries[24].y = 0x30;
    gSpriteEntries[25].x = 0xD0;
    gSpriteEntries[25].order = 6;

    for (i = 0; i <= 3; i++) {
        sprite_entry_init(i + 26, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3) | SPRITE_OBJ_MODE(1),
                          0x513, 0xE, 3);
        gSpriteEntries[i + 26].x = gSpriteEntries[i + 22].x;
        gSpriteEntries[i + 26].y = 0x40;
    }
    gSpriteEntries[28].y = 0x38;
    gSceneWork.nextSubState = 6;
    gGameSubState = 4;
}

// Sub-state 4: studio palettes and BG layers, starts the tile animation and fades in.
void weekly_show_studio(void) {
    LZ77UnCompVram(gWeeklyAnimTilesLz, (void *)0x02031000);
    DmaSet(3, gWeeklyStudioBgPalettes, PLTT, 0x84000068);
    LZ77UnCompVram(gMapSpriteSheet48Tiles, (void *)0x06011B00);
    LZ77UnCompVram(gMapSpriteSheet46Tiles, (void *)0x06012400);
    LZ77UnCompVram(gMapSpriteSheet40Tiles, (void *)0x06012D00);
    LZ77UnCompVram(gMapSpriteSheet37Tiles, (void *)0x06013600);
    DmaSet(3, gMapSpriteSheet48Palette, PLTT + 0x200, 0x80000010);
    DmaSet(3, gMapSpriteSheet46Palette, PLTT + 0x220, 0x80000010);
    DmaSet(3, gMapSpriteSheet40Palette, PLTT + 0x240, 0x80000010);
    DmaSet(3, gMapSpriteSheet37Palette, PLTT + 0x260, 0x80000010);
    DmaSet(3, &gWeeklyObjPalettes[0xF0], PLTT + 0x3C0, 0x80000010);
    DmaSet(3, &gWeeklyObjPalettes[0xD0], PLTT + 0x280, 0x80000010);
    REG_BG1CNT = 0xD05;
    REG_BG2CNT = 0xE06;
    REG_BG3CNT = 0xF07;
    REG_BLDCNT = 0xC40;
    REG_BLDALPHA = 0xA0C;
    gMedabotsWeekly.scrollBg3 = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gMedabotsWeekly.animTiles = 1;
    setup_screen_transition_effect_080682CC(4, 2, 0);
    REG_DISPCNT |= 0x1E00;
    gGameSubState = 1;
}

// Sub-state 5: "Medabots Lecture" palettes and BG layers; the bare Medabot (sprites 6-9) and the new parts
// (2-5, above the screen); fades in.
void weekly_show_lecture(void) {
    DmaSet(3, gWeeklyLectureBgPalettes, PLTT, 0x84000030);
    DmaSet(3, &gWeeklyObjPalettes[0xE0], PLTT + 0x200, 0x80000010);
    DmaSet(3, &gWeeklyObjPalettes[0xC0], PLTT + 0x220, 0x80000010);
    DmaSet(3, &gWeeklyObjPalettes[0x80], PLTT + 0x300, 0x80000040);
    DmaSet(3, &gWeeklyObjPalettes[0], PLTT + 0x380, 0x80000040);
    REG_BG1CNT = 0x1509;
    REG_BG2CNT = 0x160A;
    REG_BG3CNT = 0x170B;
    REG_BLDCNT = 0x1C42;
    REG_BLDALPHA = 0x80A;

    sprite_entry_init(6, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x508, 8, 3);
    gSpriteEntries[6].x = 0x40;
    gSpriteEntries[6].y = 0x42;
    gSpriteEntries[6].order = 0x24;
    sprite_entry_init(7, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x509, 8, 3);
    gSpriteEntries[7].x = 0x38;
    gSpriteEntries[7].y = 0x3A;
    gSpriteEntries[7].order = 0x28;
    sprite_entry_init(8, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x50A, 8, 3);
    gSpriteEntries[8].x = 0x44;
    gSpriteEntries[8].y = 0x3A;
    gSpriteEntries[8].order = 0x1C;
    sprite_entry_init(9, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x50B, 8, 3);
    gSpriteEntries[9].x = 0x40;
    gSpriteEntries[9].y = 0x42;
    gSpriteEntries[9].order = 0x20;
    sprite_entry_init(2, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x500, 8, 3);
    gSpriteEntries[2].x = 0x50;
    gSpriteEntries[2].y = -0x30;
    gSpriteEntries[2].order = 0x25;
    sprite_entry_init(1, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x50C, 1, 3);
    gSpriteEntries[1].x = 0x50;
    gSpriteEntries[1].y = -0x30;
    gSpriteEntries[1].order = 0x30;
    sprite_entry_init(3, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x501, 8, 3);
    gSpriteEntries[3].x = 0x28;
    gSpriteEntries[3].y = -0x30;
    gSpriteEntries[3].order = 0x29;
    sprite_entry_init(4, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x502, 8, 3);
    gSpriteEntries[4].x = 0x54;
    gSpriteEntries[4].y = -0x30;
    gSpriteEntries[4].order = 0x1D;
    sprite_entry_init(5, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x503, 8, 3);
    gSpriteEntries[5].x = 0x50;
    gSpriteEntries[5].y = -0x30;
    gSpriteEntries[5].order = 0x29;

    gMedabotsWeekly.scrollBg3 = 1;
    gMedabotsWeekly.animTiles = 0;
    setup_screen_transition_effect_080682CC(4, 2, 0);
    REG_DISPCNT |= 0x1E00;
    gGameSubState = 1;
}

// Sub-state 6: show music, both curtains start opening.
void weekly_open_curtains(void) {
    play_song(4);
    weekly_set_sprite_effect(1, 0, 0);
    weekly_set_sprite_effect(2, 11, 0);
    gGameSubState++;
}

// Sub-state 7: once the curtains are open, characters 22 and 23 walk on from both sides.
void weekly_enter_pair(void) {
    if (gSpriteEntries[10].work[WEEKLY_SPR_NEXT_STRIP] == 0) {
        sprite_cycle_anim_start(0x16, 0x2D, 8);
        sprite_cycle_anim_start(0x17, 0x36, 8);
        weekly_set_sprite_effect(5, 0x16, 0x48);
        weekly_set_sprite_effect(6, 0x17, 0x48);
        gGameSubState++;
    }
}

// Sub-state 8: character 24 jumps on stage.
void weekly_enter_jumper(void) {
    if (gSpriteEntries[22].work[WEEKLY_SPR_EFFECT] == 0) {
        sprite_cycle_anim_stop(0x16, 0x27);
        sprite_cycle_anim_stop(0x17, 0x33);
        sprite_cycle_anim_start(0x18, 0x45, 8);
        weekly_set_sprite_effect(7, 0x18, 0x60);
        gGameSubState++;
    }
}

// Sub-state 9: character 25 walks on.
void weekly_enter_host(void) {
    if (gSpriteEntries[24].work[WEEKLY_SPR_EFFECT] == 0) {
        sprite_cycle_anim_start(0x18, 0x3F, 0xC);
        sprite_cycle_anim_start(0x19, 0x4E, 8);
        weekly_set_sprite_effect(6, 0x19, 0x60);
        gGameSubState++;
    }
}

// Sub-state 10: waits for character 25 to arrive.
void weekly_wait_host(void) {
    if (gSpriteEntries[25].work[WEEKLY_SPR_EFFECT] == 0) {
        sprite_cycle_anim_stop(0x19, 0x4B);
        gGameSubState++;
    }
}

// Sub-state 11: the opening talk (gWeeklyMessages 0-7); the speaker's sprite cycles while their line is shown.
void weekly_opening_talk(void) {
    switch (gSceneWork.timer) {
    case 0:
        text_window_init(1, 0, 0);
        sprite_cycle_anim_start(0x19, 0x4B, 8);
        gSceneWork.timer++;
        break;
    case 2:
        message_next();
        sprite_cycle_anim_stop(0x19, 0x4B);
        sprite_cycle_anim_start(0x16, 0x2D, 8);
        gSceneWork.timer++;
        break;
    case 4:
        message_next();
        sprite_cycle_anim_stop(0x16, 0x2D);
        sprite_cycle_anim_start(0x19, 0x4E, 8);
        gSceneWork.timer++;
        break;
    case 6:
        message_next();
        sprite_cycle_anim_stop(0x19, 0x4B);
        sprite_cycle_anim_start(0x17, 0x36, 8);
        gSceneWork.timer++;
        break;
    case 8:
        message_next();
        sprite_cycle_anim_stop(0x17, 0x36);
        sprite_cycle_anim_start(0x19, 0x51, 8);
        gSceneWork.timer++;
        break;
    case 10:
        message_next();
        sprite_cycle_anim_stop(0x19, 0x4B);
        sprite_cycle_anim_start(0x16, 0x2D, 8);
        gSceneWork.timer++;
        break;
    case 12:
        message_next();
        sprite_cycle_anim_stop(0x16, 0x2D);
        sprite_cycle_anim_start(0x19, 0x4B, 8);
        gSceneWork.timer++;
        break;
    case 14:
        message_next();
        sprite_cycle_anim_stop(0x16, 0x27);
        sprite_cycle_anim_stop(0x17, 0x33);
        sprite_cycle_anim_stop(0x19, 0x4B);
        sprite_cycle_anim_start(0x18, 0x3F, 6);
        gSceneWork.timer++;
        break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
    case 11:
    case 13:
    case 15:
        if (run_message(gWeeklyMessages[gSceneWork.timer >> 1]))
            gSceneWork.timer++;
        break;
    default:
        sprite_cycle_anim_start(0x18, 0x3F, 0xC);
        gSceneWork.timer = 0;
        gSceneWork.nextSubState = 0xC;
        gGameSubState = 2;
        break;
    }
}

// Sub-state 12: clears the sprites and goes to the lecture screen (sub-state 5, then 13).
void weekly_go_to_lecture(void) {
    u32 zero = 0;

    DmaSet(3, &zero, gSpriteEntries, 0x85000800);
    gSceneWork.nextSubState = 0xD;
    gGameSubState = 5;
}

// Sub-state 13: the lecture talk (gWeeklyMessages 8-13); after each line one gWeeklyLectureSteps step runs to
// its end.
void weekly_lecture(void) {
    switch (gSceneWork.timer) {
    case 0:
        text_window_init(1, 0, 0);
        gSceneWork.timer++;
        break;
    case 4:
    case 8:
    case 12:
    case 16:
    case 20:
    case 24:
        message_next();
        gSceneWork.timer++;
        break;
    case 1:
    case 5:
    case 9:
    case 13:
    case 17:
    case 21:
        if (run_message(gWeeklyMessages[(gSceneWork.timer >> 2) + 8])) {
            message_next();
            run_message(gMessageWaitKeyKeep);
            gSceneWork.timer++;
        }
        break;
    case 25:
        if (run_message(gWeeklyMessages[(gSceneWork.timer >> 2) + 8]))
            gSceneWork.timer++;
        break;
    case 2:
    case 6:
    case 10:
    case 14:
    case 18:
        gSceneWork.timer++;
        break;
    case 22:
        sprite_entry_init(0, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x50F, 0, 3);
        gSpriteEntries[0].x = 0x42;
        gSpriteEntries[0].y = -8;
        gSpriteEntries[0].order = 0x40;
        gSpriteEntries[0].timer = 0;
        gSceneWork.timer++;
        break;
    case 3:
    case 7:
    case 11:
    case 15:
    case 19:
    case 23:
        if (weekly_lecture_run_step())
            gSceneWork.timer++;
        break;
    default:
        setup_screen_transition_effect_080684F0(4, 2, 0);
        gSceneWork.timer = 0;
        gSceneWork.nextSubState = 0xE;
        gGameSubState = 2;
        break;
    }
}

// Sub-state 14: rebuilds the studio with closed curtains and the characters on stage (sub-state 4, then 15).
void weekly_back_to_studio(void) {
    u32 zero = 0;
    s32 i;
    u32 zero_late; // FAKEMATCH: a second zero, loaded late for gVBlankOamMode

    DmaSet(3, &zero, gSpriteEntries, 0x85000800);
    sprite_entry_init(0, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3), 0x50E, 4, 3);
    gSpriteEntries[0].x = 0xD4;
    gSpriteEntries[0].y = 0;
    gSpriteEntries[0].order = 0x4A;
    gSpriteEntries[10].work[WEEKLY_SPR_NEXT_STRIP] = 0xFF;
    sprite_entry_init(0xB, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3), 0x50E, 4, 3);
    gSpriteEntries[11].x = 0x14;
    gSpriteEntries[11].y = 0;
    gSpriteEntries[11].order = 0x4A;
    gSpriteEntries[21].work[WEEKLY_SPR_NEXT_STRIP] = 0xFF;
    for (i = 0; i < 4; i++) {
        sprite_entry_init(i + 0x16, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3),
                          (u16)(i * 12 + 0x27), i, 1);
        gSpriteEntries[i + 0x16].y = 0x48;
    }
    gSpriteEntries[0x16].x = 0x58;
    gSpriteEntries[0x16].order = 8;
    gSpriteEntries[0x17].x = 0x88;
    gSpriteEntries[0x17].order = 8;
    gSpriteEntries[0x18].x = 0x70;
    gSpriteEntries[0x18].order = 0xC;
    gSpriteEntries[0x18].y = 0x24;
    gSpriteEntries[0x19].x = 0x70;
    gSpriteEntries[0x19].order = 4;
    for (i = 0; i < 4; i++) {
        sprite_entry_init(i + 0x1A, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3) | SPRITE_OBJ_MODE(1),
                          0x513, 0xE, 3);
        gSpriteEntries[i + 0x1A].x = gSpriteEntries[i + 0x16].x;
        gSpriteEntries[i + 0x1A].y = 0x48;
    }
    zero_late = 0;
    gSpriteEntries[0x1C].y = 0x38;
    gWeeklyCycleAnimMask = 0;
    sprite_cycle_anim_start(0x18, 0x3F, 0xC);
    gVBlankOamMode = zero_late;
    gSceneWork.nextSubState = 0xF;
    gGameSubState = 4;
}

// Sub-state 15: the closing talk (gWeeklyMessages 15-18), then the curtains close.
void weekly_closing_talk(void) {
    switch (gSceneWork.timer) {
    case 0:
        text_window_init(1, 0, 0);
        sprite_cycle_anim_start(0x19, 0x4B, 8);
        gSceneWork.timer++;
        break;
    case 2:
        message_next();
        sprite_cycle_anim_stop(0x19, 0x4B);
        sprite_cycle_anim_start(0x17, 0x36, 8);
        gSceneWork.timer++;
        break;
    case 4:
        message_next();
        sprite_cycle_anim_stop(0x17, 0x36);
        sprite_cycle_anim_start(0x19, 0x4B, 8);
        gSceneWork.timer++;
        break;
    case 6:
        message_next();
        sprite_cycle_anim_stop(0x17, 0x33);
        sprite_cycle_anim_stop(0x19, 0x4B);
        sprite_cycle_anim_start(0x18, 0x3F, 6);
        gSceneWork.timer++;
        break;
    case 1:
    case 3:
    case 5:
    case 7:
        if (run_message(gWeeklyMessages[(gSceneWork.timer >> 1) + 15]))
            gSceneWork.timer++;
        break;
    default:
        gSceneWork.timer = 0;
        sprite_cycle_anim_start(0x16, 0x27, 8);
        sprite_cycle_anim_start(0x17, 0x33, 8);
        sprite_cycle_anim_start(0x19, 0x4B, 8);
        weekly_set_sprite_effect(3, 0, 0);
        weekly_set_sprite_effect(4, 0xB, 0);
        gGameSubState++;
        break;
    }
}

// Sub-state 16: once the curtains are closed, fades the music out and leaves (sub-state 17).
void weekly_wait_curtains_closed(void) {
    if (gSpriteEntries[10].work[WEEKLY_SPR_NEXT_STRIP] == 0) {
        fade_out_music(0x20);
        gSceneWork.nextSubState = 0x11;
        gGameSubState = 2;
    }
}

// Sub-state 17: back to game mode 1.
void weekly_exit(void) {
    play_song(0);
    field_return_from_scene(3);
}

// Runs each sprite's effect (work[WEEKLY_SPR_EFFECT] = gWeeklySpriteEffects index + 1) and counts its frames in
// timer.
// Effects return 1 to go on, 0 when done, 0xFF to delete the sprite.
void weekly_run_sprite_effects(void) {
    u8 i;

    for (i = 0; i < 0x1A; i++) {
        if (gSpriteEntries[i].work[WEEKLY_SPR_EFFECT] != 0) {
            gSpriteEntries[i].timer++;
            switch (gWeeklySpriteEffects[gSpriteEntries[i].work[WEEKLY_SPR_EFFECT] - 1](i)) {
            case 0:
                gSpriteEntries[i].work[WEEKLY_SPR_EFFECT] = 0;
                gSpriteEntries[i].work[WEEKLY_SPR_EFFECT_STEP] = 0;
                break;
            case 1:
                break;
            case 0xFF:
                clear_sprite_entry(i);
                break;
            }
        }
    }
}

// Steps the cycle anims of sprites 0x16-0x19 (gWeeklyCycleAnimMask): base frame + gCycleAnimFrameOffsets.
void sprite_cycle_anim_update(void) {
    u8 frame_offsets[4];
    s32 j;
    u8 mask;

    memcpy_optimized(frame_offsets, gCycleAnimFrameOffsets, 4);
    for (j = 0, mask = 1; j <= 3; j++, mask <<= 1) {
        if (gWeeklyCycleAnimMask & mask) {
            s32 phase = gSpriteEntries[j + 0x16].work16[WEEKLY_SPR_CYCLE_TIMER] %
                        gSpriteEntries[j + 0x16].work[WEEKLY_SPR_CYCLE_PERIOD];
            if (phase == 0) {
                if (++gSpriteEntries[j + 0x16].work[WEEKLY_SPR_CYCLE_STEP] > 3)
                    gSpriteEntries[j + 0x16].work[WEEKLY_SPR_CYCLE_STEP] = phase;
                gSpriteEntries[j + 0x16].frame = gSpriteEntries[j + 0x16].work16[WEEKLY_SPR_BASE_FRAME] +
                                                 frame_offsets[gSpriteEntries[j + 0x16].work[WEEKLY_SPR_CYCLE_STEP]];
            }
            gSpriteEntries[j + 0x16].work16[WEEKLY_SPR_CYCLE_TIMER]++;
        }
    }
}

void sprite_cycle_anim_start(u8 sprite, u16 frame, u8 period) {
    u8 mask = 1 << (sprite - 0x16);

    gWeeklyCycleAnimMask |= mask;
    gSpriteEntries[sprite].work[WEEKLY_SPR_CYCLE_PERIOD] = period;
    gSpriteEntries[sprite].work16[WEEKLY_SPR_BASE_FRAME] = frame;
    gSpriteEntries[sprite].frame = frame;
}

void sprite_cycle_anim_stop(u8 sprite, u16 frame) {
    u8 mask = 1 << (sprite - 0x16);

    gWeeklyCycleAnimMask &= ~mask;
    gSpriteEntries[sprite].work[WEEKLY_SPR_CYCLE_PERIOD] = 0;
    gSpriteEntries[sprite].frame = frame;
}

// Effect 1: a right-curtain strip slides right (gWeeklyCurtainOpenTimes) and starts the next strip
// (work[WEEKLY_SPR_NEXT_STRIP]) halfway; deleted off screen.
u32 weekly_fx_right_curtain_open(u8 sprite) {
    s8 step_times[8];
    struct SpriteEntry *curtain;
    struct SpriteEntry *sprites;

    memcpy_optimized(step_times, gWeeklyCurtainOpenTimes, 8);
    sprites = gSpriteEntries;
    curtain = &sprites[sprite];
    if (curtain->work[WEEKLY_SPR_EFFECT_STEP] < 8) {
        if (curtain->timer == step_times[curtain->work[WEEKLY_SPR_EFFECT_STEP]]) {
            curtain->x++;
            curtain->work[WEEKLY_SPR_EFFECT_STEP]++;
        }
    } else {
        curtain->x++;
    }
    if (gSpriteEntries[sprite].work[WEEKLY_SPR_EFFECT_STEP] == 4 &&
        gSpriteEntries[sprite].work[WEEKLY_SPR_NEXT_STRIP] != 0xFF)
        weekly_set_sprite_effect(1, gSpriteEntries[sprite].work[WEEKLY_SPR_NEXT_STRIP], 0);
    if (gSpriteEntries[sprite].x == 0xC9)
        gSpriteEntries[sprite].flags = (gSpriteEntries[sprite].flags & (u16)~SPRITE_PRIORITY(2)) | SPRITE_PRIORITY(3);
    else if (gSpriteEntries[sprite].x > 0xCF)
        return 0xFF;
    return 1;
}

// Effect 2: the same for a left-curtain strip, sliding left.
u32 weekly_fx_left_curtain_open(u8 sprite) {
    s8 step_times[8];
    struct SpriteEntry *curtain;
    struct SpriteEntry *sprites;

    memcpy_optimized(step_times, gWeeklyCurtainOpenTimes, 8);
    sprites = gSpriteEntries;
    curtain = &sprites[sprite];
    if (curtain->work[WEEKLY_SPR_EFFECT_STEP] < 8) {
        if (curtain->timer == step_times[curtain->work[WEEKLY_SPR_EFFECT_STEP]]) {
            curtain->x--;
            curtain->work[WEEKLY_SPR_EFFECT_STEP]++;
        }
    } else {
        curtain->x--;
    }
    if (gSpriteEntries[sprite].work[WEEKLY_SPR_EFFECT_STEP] == 4 &&
        gSpriteEntries[sprite].work[WEEKLY_SPR_NEXT_STRIP] != 0xFF)
        weekly_set_sprite_effect(2, gSpriteEntries[sprite].work[WEEKLY_SPR_NEXT_STRIP], 0);
    if (gSpriteEntries[sprite].x == 0x1F)
        gSpriteEntries[sprite].flags = (gSpriteEntries[sprite].flags & (u16)~SPRITE_PRIORITY(2)) | SPRITE_PRIORITY(3);
    else if (gSpriteEntries[sprite].x < 0x19)
        return 0xFF;
    return 1;
}

// Effect 3: a right-curtain strip slides left (gWeeklyCurtainCloseTimes), creating the next strip on the way.
u32 weekly_fx_right_curtain_close(u8 sprite) {
    s8 step_times[12];
    struct SpriteEntry *sprites;
    struct SpriteEntry *curtain;
    struct SpriteEntry *entries;
    u32 next;

    memcpy_optimized(step_times, gWeeklyCurtainCloseTimes, 12);
    sprites = gSpriteEntries;
    curtain = &sprites[sprite];
    if (curtain->work[WEEKLY_SPR_EFFECT_STEP] <= 11) {
        if (curtain->timer == step_times[curtain->work[WEEKLY_SPR_EFFECT_STEP]]) {
            curtain->x--;
            if (++curtain->work[WEEKLY_SPR_EFFECT_STEP] == 8 && curtain->work[WEEKLY_SPR_NEXT_STRIP] != 0xFF) {
                if (sprite == 0) {
                    sprite_entry_init(1, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3), 0x50E, 4, 3);
                    next = 1;
                } else {
                    next = sprite + 1;
                    ((void (*)())sprite_entry_init)(
                        next, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x50E, 4, 3);
                }
                entries = gSpriteEntries;
                entries[next].x = entries[sprite].x;
                entries[next].y = 0;
                entries[next].order = entries[sprite].order - 1;
                weekly_set_sprite_effect(3, next, 0);
            }
        }
    } else {
        if (sprite == 0) {
            sprites[0].flags = (sprites[0].flags & (u16)~SPRITE_FLAG_PRIORITY_MASK) | SPRITE_PRIORITY(2);
            sprites[1].flags = (sprites[1].flags & (u16)~SPRITE_FLAG_PRIORITY_MASK) | SPRITE_PRIORITY(2);
        }
        if (curtain->work[WEEKLY_SPR_NEXT_STRIP] == 0xFF)
            curtain->work[WEEKLY_SPR_NEXT_STRIP] = 0;
        return 0;
    }
    return 1;
}

// Effect 4: the same for the left curtain, sliding right.
u32 weekly_fx_left_curtain_close(u8 sprite) {
    s8 step_times[12];
    struct SpriteEntry *sprites;
    struct SpriteEntry *curtain;
    struct SpriteEntry *entries;
    u32 next;

    memcpy_optimized(step_times, gWeeklyCurtainCloseTimes, 12);
    sprites = gSpriteEntries;
    curtain = &sprites[sprite];
    if (curtain->work[WEEKLY_SPR_EFFECT_STEP] <= 11) {
        if (curtain->timer == step_times[curtain->work[WEEKLY_SPR_EFFECT_STEP]]) {
            curtain->x++;
            if (++curtain->work[WEEKLY_SPR_EFFECT_STEP] == 8 && curtain->work[WEEKLY_SPR_NEXT_STRIP] != 0xFF) {
                if (sprite == 11) {
                    sprite_entry_init(12, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3), 0x50E, 4, 3);
                    next = 12;
                } else {
                    next = sprite + 1;
                    ((void (*)())sprite_entry_init)(
                        next, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x50E, 4, 3);
                }
                entries = gSpriteEntries;
                entries[next].x = entries[sprite].x;
                entries[next].y = 0;
                entries[next].order = entries[sprite].order - 1;
                weekly_set_sprite_effect(4, next, 0);
            }
        }
    } else {
        if (sprite == 11) {
            curtain->flags = (curtain->flags & (u16)~SPRITE_FLAG_PRIORITY_MASK) | SPRITE_PRIORITY(2);
            sprites[12].flags = (sprites[12].flags & (u16)~SPRITE_FLAG_PRIORITY_MASK) | SPRITE_PRIORITY(2);
        }
        if (curtain->work[WEEKLY_SPR_NEXT_STRIP] != 0xFF)
            curtain->work[WEEKLY_SPR_NEXT_STRIP] = 0;
        return 0;
    }
    return 1;
}

// Effect 5: walks right (with the shadow, sprite + 4) for `duration` frames, then steps down (effect 8).
u32 weekly_fx_walk_right(u8 sprite) {
    struct SpriteEntry *sprites = gSpriteEntries;
    struct SpriteEntry *actor = &sprites[sprite];
    u16 frame;

    actor->x++;
    sprites[(u16)(sprite + 4)].x = actor->x;
    if (actor->work16[WEEKLY_SPR_DURATION] <= actor->timer) {
        frame = actor->frame / 12;
        frame = frame * 12;
        actor->frame = actor->work16[WEEKLY_SPR_BASE_FRAME] = frame + 3;
        weekly_set_sprite_effect(8, sprite, 0);
    }
    return 1;
}

// Effect 6: the same, walking left.
u32 weekly_fx_walk_left(u8 sprite) {
    struct SpriteEntry *sprites = gSpriteEntries;
    struct SpriteEntry *actor = &sprites[sprite];
    u16 frame;

    actor->x--;
    sprites[(u16)(sprite + 4)].x = actor->x;
    if (actor->work16[WEEKLY_SPR_DURATION] <= actor->timer) {
        frame = actor->frame / 12;
        frame = frame * 12;
        actor->frame = actor->work16[WEEKLY_SPR_BASE_FRAME] = frame + 3;
        weekly_set_sprite_effect(8, sprite, 0);
    }
    return 1;
}

// Effect 7: moves right on a sine arc (with the shadow) for `duration` frames.
u32 weekly_fx_jump_in(u8 sprite) {
    struct SpriteEntry *sprites = gSpriteEntries;
    struct SpriteEntry *actor = &sprites[sprite];

    actor->x++;
    sprites[(u16)(sprite + 4)].x = actor->x;
    actor->y = 0x32 - (gSineTable[actor->timer >> 1] >> 4);
    if (actor->x == 0x20)
        actor->flags = (actor->flags & (u16)~SPRITE_FLAG_PRIORITY_MASK) | SPRITE_PRIORITY(2);
    if (actor->work16[WEEKLY_SPR_DURATION] <= actor->timer) {
        actor->flags = (actor->flags & (u16)~SPRITE_PRIORITY(2)) | SPRITE_PRIORITY(3);
        return 0;
    }
    return 1;
}

// Effect 8: moves down 8 lines (with the shadow).
u32 weekly_fx_step_down(u8 sprite) {
    struct SpriteEntry *sprites = gSpriteEntries;
    struct SpriteEntry *actor = &sprites[sprite];

    actor->y++;
    sprites[(u16)(sprite + 4)].y++;
    if (actor->timer > 7)
        return 0;
    return 1;
}

void weekly_set_sprite_effect(u8 effect, u8 sprite, u16 duration) {
    struct SpriteEntry *sprites = gSpriteEntries;
    struct SpriteEntry *entry = &sprites[sprite];

    entry->work[WEEKLY_SPR_EFFECT] = effect;
    entry->work[WEEKLY_SPR_EFFECT_STEP] = 0;
    entry->work16[WEEKLY_SPR_DURATION] = duration;
    entry->timer = 0;
}

// Runs the current lecture step; nonzero once it is done.
u32 weekly_lecture_run_step(void) {
    return gWeeklyLectureSteps[gSceneWork.progress.lecture.state]();
}

// Lecture step 4: nothing to show.
u32 weekly_lecture_skip_step(void) {
    gSceneWork.progress.lecture.state++;
    return 1;
}

// Lecture step 0: the new head (sprite 2, with sprite 1) drops, slides onto the body and replaces sprite 6.
u32 weekly_lecture_attach_head(void) {
    struct SpriteEntry *sprites = gSpriteEntries;

    if (sprites[2].y <= 0x3D)
        sprites[1].y = sprites[2].y += 2;
    else if (sprites[2].y <= 0x41)
        sprites[1].y = sprites[2].y += 1;
    else if (sprites[2].timer <= 0x1F)
        sprites[2].timer++;
    else if (sprites[2].x <= 0x40) {
        clear_sprite_entry(6);
        play_sound_effect(0x54);
        sprites[2].timer = 0;
        gSceneWork.progress.lecture.state++;
        return 1;
    } else
        sprites[1].x = sprites[2].x -= 4;
    return 0;
}

// Lecture step 1: an arm (sprite 3) drops and slides right onto the body, replacing sprite 7.
u32 weekly_lecture_attach_arm_from_left(void) {
    struct SpriteEntry *sprites = gSpriteEntries;
    s16 *y = &sprites[3].y;
    u16 *wait;
    s16 *x;

    if (*y <= 0x35)
        *y += 2;
    else if (*y <= 0x39)
        *y += 1;
    else if (*(wait = &sprites[3].timer) <= 0x1F)
        (*wait)++;
    else if (*(x = &sprites[3].x) > 0x37) {
        clear_sprite_entry(7);
        play_sound_effect(0x54);
        *wait = 0;
        gSceneWork.progress.lecture.state++;
        return 1;
    } else
        *x += 4;
    return 0;
}

// Lecture step 2: an arm (sprite 4) drops and slides left onto the body, replacing sprite 8.
u32 weekly_lecture_attach_arm_from_right(void) {
    struct SpriteEntry *sprites = gSpriteEntries;
    s16 *y = &sprites[4].y;
    u16 *wait;
    s16 *x;

    if (*y <= 0x35)
        *y += 2;
    else if (*y <= 0x39)
        *y += 1;
    else if (*(wait = &sprites[4].timer) <= 0x1F)
        (*wait)++;
    else if (*(x = &sprites[4].x) <= 0x44) {
        clear_sprite_entry(8);
        play_sound_effect(0x54);
        *wait = 0;
        gSceneWork.progress.lecture.state++;
        return 1;
    } else
        *x -= 4;
    return 0;
}

// Lecture step 3: the legs (sprite 5) drop and slide left, replacing sprite 9.
u32 weekly_lecture_attach_legs(void) {
    struct SpriteEntry *sprites = gSpriteEntries;
    s16 *y = &sprites[5].y;
    u16 *wait;
    s16 *x;

    if (*y <= 0x3D)
        *y += 2;
    else if (*y <= 0x41)
        *y += 1;
    else if (*(wait = &sprites[5].timer) <= 0x1F)
        (*wait)++;
    else if (*(x = &sprites[5].x) <= 0x40) {
        clear_sprite_entry(9);
        play_sound_effect(0x54);
        {
            u8 *priority = &sprites[5].order;
            u16 zero = 0;

            *priority = 0x21;
            *wait = zero;
        }
        gSceneWork.progress.lecture.state++;
        return 1;
    } else
        *x -= 4;
    return 0;
}

// Lecture step 5 ("the finishing touch"): the Medal (sprite 0) falls into the Medabot; backs up the OBJ
// palettes for the flash.
u32 weekly_lecture_drop_medal(void) {
    if (gSpriteEntries[0].timer++ & 1) {
        if (++gSpriteEntries[0].y == 0)
            play_sound_effect(0x59);
    }
    gSpriteEntries[0].frame = ((gSpriteEntries[0].timer >> 2) & 3) + 0x50F;
    if (gSpriteEntries[0].y > 0x3F) {
        play_sound_effect(7);
        gWeeklyFlashPalette = gPaletteBackupBg;
        gSceneWork.progress.lecture.step = 0;
        DmaSet(3, OBJ_PLTT, gPaletteBackupBg, 0x84000080);
        gSceneWork.progress.lecture.state++;
    }
    return 0;
}

// Lecture step 6: the OBJ palettes fade to white and back.
u32 weekly_lecture_flash(void) {
    u8 fade;
    u8 white;
    s32 i;
    u16 *dst = gPaletteBufferBg;

    if (gSceneWork.progress.lecture.step > 0x40) {
        play_sound_effect(10);
        gSceneWork.progress.lecture.state++;
    } else {
        if (gSceneWork.progress.lecture.step < 0x20)
            fade = 0x20 - gSceneWork.progress.lecture.step;
        else
            fade = gSceneWork.progress.lecture.step - 0x20;
        if (gSceneWork.progress.lecture.step == 0x20)
            clear_sprite_entry(0);
        if (gSceneWork.progress.lecture.step == 0x14)
            play_sound_effect(0x51);
        white = 0x20 - fade;
        for (i = 0; i <= 0xFF; i++) {
            dst[i] = (((gWeeklyFlashPalette[i] & 0x1F) * fade + white * 31) >> 5) +
                     ((((gWeeklyFlashPalette[i] & 0x3E0) * fade + (white * 31 << 5)) >> 5) & 0x3E0) +
                     ((((gWeeklyFlashPalette[i] & 0x7C00) * fade + (white * 31 << 10)) >> 5) & 0x7C00);
        }
        DmaSet(3, dst, OBJ_PLTT, 0x84000080);
    }
    if (gFrameCounter & 1)
        gSceneWork.progress.lecture.step++;
    return 0;
}

// Lecture step 7: sprite 1 blinks, then the finished Medabot is drawn from its parts.
u32 weekly_lecture_show_medabot(void) {
    struct SpriteEntry *sprites = gSpriteEntries;
    vu32 fill;

    if (sprites[1].timer & 4)
        sprites[1].y = 0xC8;
    else
        sprites[1].y = 0x42;
    if (sprites[1].timer++ > 0x1F) {
        clear_sprite_entry(1);
        init_scene_buffers_080445F4();
        fill = 0x200;
        DmaSet(3, &fill, gSpriteWork->oamBuf, 0x85000100);
        setup_scene_with_bg_and_sprites(0, 0x2A, 0x2A, 0x2A, 0x2A, 0x40, 0x42, 2, 8, 0, 0, 0);
        gSceneWork.progress.lecture.state++;
    }
    return 0;
}

// Lecture step 8: starts the Medabot's action animation.
u32 weekly_lecture_start_pose(void) {
    vu32 fill;

    fill = 0x200;
    DmaSet(3, &fill, gSpriteWork->oamBuf, 0x85000100);
    setup_scene_with_bg_and_sprites(0, 0x2A, 0x2A, 0x2A, 0x2A, 0x40, 0x42, 2, 8, 0, 1, 0);
    medabot_pose_anim_step(0, 0x2D, 0);
    gSceneWork.progress.lecture.state++;
    gSceneWork.progress.lecture.step = 0;
    return 0;
}

// Lecture step 9: runs the action animation with its sound script (gWeeklyLectureSfxScript).
u32 weekly_lecture_run_pose(void) {
    struct SpriteEntry *sprites;
    u8 script[13];
    vu32 fill;
    register u32 zero asm("r5"); // FAKEMATCH: pinned; the original keeps a second zero (r2) for the arguments
    u32 none;                    // FAKEMATCH: the original keeps this zero apart from `zero`
    s16 *head_y;

    memcpy_optimized(script, gWeeklyLectureSfxScript, 13);
    sprites = gSpriteEntries;
    head_y = &sprites[2].y;
    zero = 0;
    none = 0;
    *head_y = 0xC8;
    *&sprites[3].y = 0xC8;
    *&sprites[4].y = 0xC8;
    *&sprites[5].y = 0xC8;
    fill = 0x200;
    DmaSet(3, &fill, gSpriteWork->oamBuf, 0x85000100);
    setup_scene_with_bg_and_sprites(0, 0x2A, 0x2A, 0x2A, 0x2A, 0x40, 0x42, 2, 8, none, 1, none);
    switch (script[gSceneWork.progress.lecture.pos]) {
    case 0:
        if (script[gSceneWork.progress.lecture.pos + 1] >= gSceneWork.progress.lecture.step++)
            break;
        gSceneWork.progress.lecture.pos += 2;
        gSceneWork.progress.lecture.step = zero;
        break;
    case 1:
        play_sound_effect(script[gSceneWork.progress.lecture.pos + 1]);
        gSceneWork.progress.lecture.pos += 2;
        gSceneWork.progress.lecture.step = zero;
        break;
    case 2:
        break;
    }
    if (medabot_pose_anim_step(0, 0x2D, 0) != 0) {
        gSceneWork.progress.lecture.state = 0;
        return 1;
    }
    return 0;
}
