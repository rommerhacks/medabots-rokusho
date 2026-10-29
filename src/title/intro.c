// Mode-3 state 1: the opening intro before the title screen (gIntroSubStates). Order, seen at runtime:
// Rokusho's silhouette on a stormy mountain (eyes fade in, lightning flash) -> a Medapart scan screen typing
// out "SWORD" and "PIPO HAMMER" -> silhouette -> scan of "TATACKER" and "ANTENNA" -> Rokusho's sprite posing ->
// silhouette -> Rokusho / Metabee art banner (mosaic in) -> Rokusho close-up art (white flash) -> title screen.
// intro_update runs it; intro_check_skip lets START jump to the title screen.
// The [1] entries of the gIntro* graphics tables are the Rokusho version's (index 0 presumably Metabee's).
#include "global.h"
#include "constants/sprites.h"

// gSpriteEntries work[] / work16[] indices
#define INTRO_SPR_ACTION 0x0    // gIntroSpriteActions index + 1, 0 = none
#define INTRO_SPR_STEP 0x1      // the action's step counter (bob: wave phase)
#define INTRO_SPR_BOB_SPEED 0x2 // bob: extra phase added each step (random 0-3)
#define INTRO_SPR_BASE_Y 0x3    // bob: y the wave is centred on
#define INTRO_SPR_START_FRAME 0 // work16: frame when the action started

static bool32 intro_eyes_fade_in_step(void);
static bool32 intro_mosaic_fade_in_step(void);
static void copy_tilemap_rect_to_vram(const u16 *src, u8 bg, u8 w, u8 h, u8 x, u8 y, u16 tile, u8 pal);
static void intro_draw_counters(void);
static void intro_clear_part_name(void);
static void intro_clear_scan_text(void);
static void intro_clear_counters(void);
static void intro_clear_pointer_lines(void);
static bool32 intro_silhouette_step(void);
static void intro_sprite_set_action(u8 action, u8 i, u8 y);

static void intro_draw_rokusho_pose(void) {
    if (gVBlankOamMode == 2) {
        u32 oam_fill = 0x200;
        DmaSet(3, &oam_fill, gSpriteWork->oamBuf, 0x85000100);
        setup_scene_with_bg_and_sprites(0, 0x2A, 0x2A, 0x2A, 0x2A, 0x70, 0x50, gVBlankOamMode, 0xC, 0, 1, 0);
        medabot_pose_anim_step(0, 0x2D, 0x2A);
    }
}

static void intro_check_skip(void) {
    if (KEYS_LO(gHeldKeys) & START_BUTTON) {
        gTitleSkipIntro = 1;
        gVBlankOamMode = 0;
        gGameMode = 3;
        gGameState = 2;
        gGameSubState = 0;
    }
}

void intro_update(void) {
    intro_draw_rokusho_pose();
    gIntroSubStates[gGameSubState]();
    intro_check_skip();
}

void intro_eyes_fade_in_state(void) {
    if (intro_eyes_fade_in_step()) {
        gGameMode = gSceneWork.nextMode;
        gGameState = gSceneWork.nextState;
        gGameSubState = gSceneWork.nextSubState;
    }
}

void intro_mosaic_fade_in_state(void) {
    if (intro_mosaic_fade_in_step()) {
        gGameMode = gSceneWork.nextMode;
        gGameState = gSceneWork.nextState;
        gGameSubState = gSceneWork.nextSubState;
    }
}

void intro_flash_state(void) {
    if (gSceneWork.timer > 0x4C && gSceneWork.flashAlpha >= 0) {
        u8 src_weight = gSceneWork.flashAlpha;
        u8 dst_weight = 16 - gSceneWork.flashAlpha;
        REG_BLDALPHA = src_weight | (dst_weight << 8);
        gSceneWork.flashAlpha--;
    }
    if (scene_transition_step_080686F4()) {
        REG_DISPCNT &= 0xFBFF;
        gGameMode = gSceneWork.nextMode;
        gGameState = gSceneWork.nextState;
        gGameSubState = gSceneWork.nextSubState;
    }
    gSceneWork.timer++;
}

void intro_transition_out_state(void) {
    gSceneWork.frameCounter++;
    gSceneWork.noiseCounter += 0x6F;
    intro_draw_counters();
    intro_update_sprite_actions();
    if (execute_scene_step()) {
        u32 zero = 0;
        DmaSet(3, &zero, gSpriteEntries, 0x85000800);
        gVBlankOamMode = 0;
        REG_DISPCNT &= 0x80FF;
        gGameMode = gSceneWork.nextMode;
        gGameState = gSceneWork.nextState;
        gGameSubState = gSceneWork.nextSubState;
    }
}

void intro_init(void) {
    u32 zero = 0;
    DmaSet(3, &zero, VRAM, 0x85006000);
    zero = 0;
    DmaSet(3, &zero, PLTT, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, gSpriteEntries, 0x85000800);
    zero = 0;
    DmaSet(3, &zero, &gSceneWork, 0x8500003E);
    REG_DISPCNT = 0x60;
    gSceneWork.nextMode = 3;
    gSceneWork.nextState = 1;
    gSceneWork.timer = 0;
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gSceneWork.param.afterSubState = 11;
    gSceneWork.nextSubState = 11;
    gSceneWork.stepFrames = 1;
    gSceneWork.poseCounterUp = 0x7C0;
    gSceneWork.poseCounterDown = 0x100;
    gTitleSkipIntro = 0;
    gGameSubState = 8;
}

void intro_load_silhouette_scene(void) {
    u16 buf1[0x78];
    u16 buf2[0x190];

    LZ77UnCompVram(gIntroSilhouetteBgTiles, (void *)VRAM);
    LZ77UnCompVram(gIntroSilhouetteBg2Tiles, (void *)(VRAM + 0x8020));
    LZ77UnCompVram(gIntroSilhouetteTiles[1], (void *)(VRAM + 0x8C80));
    DmaSet(3, gIntroSilhouetteBgPalettes, PLTT, 0x84000080);
    DmaSet(3, gIntroSilhouetteBg2Palette, PLTT, 0x84000008);
    DmaSet(3, gIntroSilhouettePals[1], PLTT + 0x20, 0x84000008);
    LZ77UnCompVram(gIntroSilhouetteBg1Tilemap, (void *)(VRAM + 0x7000));
    LZ77UnCompVram(gIntroSilhouetteBg3Tilemap, (void *)(VRAM + 0x7800));
    LZ77UnCompVram(gIntroSilhouetteBg2Tilemap, buf1);
    copy_tilemap_rect_to_vram(buf1, 0x1F, 0xA, 0xC, 0, 0, 1, 0);
    LZ77UnCompVram(gIntroSilhouetteMaps[1], buf2);
    copy_tilemap_rect_to_vram(buf2, 0x1E, 0x14, 0x14, 0xA, 0, 0x64, 1);
    REG_BG1CNT = 0xE01;
    REG_BG3CNT = 0xF03;
    REG_BG0CNT = 0x1E08;
    REG_BG2CNT = 0x1F0A;
    DmaSet(3, gIntroObjPals[1], PLTT + 0x200, 0x80000050);
    sprite_entry_init(0, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE, 0x40D, 4, 3);
    gSpriteEntries[0].x = 0x98;
    gSpriteEntries[0].y = 0x40;
    setup_screen_transition_effect_080682CC(2, 1, 0);
    gVBlankOamMode = 0;
    gSceneWork.nextSubState = gSceneWork.param.afterSubState;
    gGameSubState = 3;
}

void intro_load_scan_screen(void) {
    u8 buf[0x50]; // unused, but the original reserves the stack space
    u32 fill;
    u16 zero;
    s32 i;

    LZ77UnCompVram(gIntroScanBgTiles, (void *)VRAM);
    LZ77UnCompVram(gIntroScanFontTiles, (void *)(VRAM + 0x8020));
    LZ77UnCompVram(gIntroPartNameFontTiles, (void *)(VRAM + 0x8C80));
    LZ77UnCompVram(gIntroCounterDigitTiles, (void *)(VRAM + 0x9900));
    LZ77UnCompVram(gIntroPointerLineTiles, (void *)(VRAM + 0x9A40));
    DmaSet(3, gIntroScanBgPalettes, PLTT, 0x84000080);
    DmaSet(3, gIntroScanTextPalette, PLTT + 0x100, 0x84000008);
    DmaSet(3, gIntroScanLabelPalette, PLTT + 0x120, 0x84000008);
    DmaSet(3, gIntroScanBgPalette0, PLTT, 0x84000008);
    LZ77UnCompVram(gIntroScanBg2Tilemap, (void *)(VRAM + 0x7000));
    LZ77UnCompVram(gIntroScanBg3Tilemap, (void *)(VRAM + 0x7800));
    zero = 0;
    fill = zero;
    DmaSet(3, &fill, VRAM + 0xF800, 0x85000200);
    REG_BG1CNT = 0x1F09;
    REG_BG2CNT = 0xE02;
    REG_BG3CNT = 0xF03;
    setup_screen_transition_effect_080682CC(4, 1, 0);
    sprite_entry_init(9, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x404, 1, 3);
    gSpriteEntries[9].x = 8;
    gSpriteEntries[9].y = 0xA0;
    sprite_entry_init(10, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x405, 1, 3);
    gSpriteEntries[10].x = zero;
    gSpriteEntries[10].y = 0x90;
    for (i = 0; i <= 2; i++) {
        ((void (*)())sprite_entry_init)(i + 11, 0xC400, i + 0x400, 0, 3);
        gSpriteEntries[i + 11].x = 0xC0;
        gSpriteEntries[i + 11].y = 0xC8;
    }
    for (i = 0; i <= 5; i++) {
        ((void (*)())sprite_entry_init)(i + 3, 0xC400, 0x408, 2, 3);
        gSpriteEntries[i + 3].x = i * 8 + 0xA0;
        gSpriteEntries[i + 3].y = 0xC8;
        gSpriteEntries[i + 3].order = 0x20;
    }
    intro_clear_part_name();
    intro_clear_scan_text();
    intro_clear_pointer_lines();
    intro_clear_counters();
    REG_DISPCNT |= 0x1E00;
    REG_BLDCNT = 0x1844;
    REG_BLDALPHA = 0x80B;
    gSceneWork.nextSubState = gSceneWork.param.afterSubState;
    gGameSubState = 1;
}

void intro_load_scan_sprites(void) {
    LZ77UnCompVram(gIntroScanObjTiles[1], (void *)0x06010000);
    LZ77UnCompVram(gIntroScanTextGlyphs, gSceneWork.scanTextGlyphs);
    gGameSubState = 6;
}

void intro_load_rokusho_sprite(void) {
    u32 fill;
    s32 legs = 0x2A;
    init_scene_buffers_080445F4();
    fill = 0x200;
    DmaSet(3, &fill, gSpriteWork->oamBuf, 0x85000100);
    setup_scene_with_bg_and_sprites(0, 0x2A, 0x2A, 0x2A, legs, 0x78, 0x50, 2, 0xC, 0, 0, 0);
    DmaSet(3, gIntroObjPals[1], PLTT + 0x200, 0x80000050);
    setup_screen_transition_effect_080682CC(2, 4, 0);
    REG_DISPCNT |= 0x1000;
    gSceneWork.nextSubState = 15;
    gGameSubState = 1;
}

void intro_load_versus_scene(void) {
    intro_load_versus_art();
    REG_MOSAIC = 0xFF;
    gSceneWork.stepFrames = 6;
    gBg0Scroll.y = 0xFFE4;
    DmaSet(3, gIntroObjPals[1], PLTT + 0x200, 0x80000050);
    gSceneWork.nextSubState = gSceneWork.param.afterSubState;
    gGameSubState = 4;
}

void intro_silhouette_first_state(void) {
    if (intro_silhouette_step()) {
        gSceneWork.timer = 0;
        gSceneWork.nextSubState = 7;
        gSceneWork.param.afterSubState = 12;
    }
}

void intro_scan_arms_state(void) {
    s32 half = 0xC4;
    s32 i;

    gSceneWork.frameCounter++;
    gSceneWork.noiseCounter += 0x6F;
    if (gSceneWork.timer < half) {
        switch (gSceneWork.timer) {
        case 0:
            sprite_entry_init(1, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_AFFINE,
                              0x409, 3, 3);
            gSpriteEntries[1].x = 0x50;
            gSpriteEntries[1].y = 0x38;
            gSpriteEntries[1].scale_x = 2;
            gSpriteEntries[1].scale_y = 2;
            intro_sprite_set_action(1, 1, 0);
            intro_sprite_set_action(4, 9, 0);
            intro_sprite_set_action(5, 10, 0);
            gSceneWork.timer++;
            break;
        case 1:
            if (gSpriteEntries[1].work[INTRO_SPR_ACTION] == 0)
                gSceneWork.timer++;
            break;
        case 2:
            sprite_entry_init(2, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE,
                              0x406, 2, 3);
            gSpriteEntries[2].x = 0xB8;
            gSpriteEntries[2].y = 0x70;
            gSpriteEntries[2].scale_x = 2;
            gSpriteEntries[2].scale_y = 2;
            intro_sprite_set_action(2, 2, 0);
            gSceneWork.timer++;
            break;
        case 3:
            if (gSpriteEntries[2].work[INTRO_SPR_ACTION] == 0) {
                intro_sprite_set_action(3, 3, 0x70);
                intro_sprite_set_action(3, 4, 0x68);
                intro_sprite_set_action(3, 5, 0x68);
                intro_sprite_set_action(3, 6, 0x70);
                intro_sprite_set_action(3, 7, 0x78);
                intro_sprite_set_action(3, 8, 0x78);
                gSceneWork.timer++;
            }
            break;
        case 4:
            if (intro_draw_pointer_line(0))
                gSceneWork.timer++;
            break;
        default:
            if (intro_type_scan_text(0))
                intro_type_part_name(0);
            gSceneWork.timer++;
            break;
        }
    } else if (gSceneWork.timer == half) {
        intro_clear_part_name();
        intro_clear_scan_text();
        intro_clear_pointer_lines();
        gSpriteEntries[1].y = 0xC8;
        gSpriteEntries[2].y = 0xC8;
        for (i = 0; i < 3; i++)
            gSpriteEntries[i + 11].y = 0xC8;
        for (i = 0; i < 6; i++) {
            intro_sprite_set_action(0, i + 3, 0);
            gSpriteEntries[i + 3].y = 0xC8;
        }
        gSceneWork.timer++;
    } else {
        switch (gSceneWork.timer) {
        case 0xC5:
            gSpriteEntries[1].frame = 0x40A;
            gSpriteEntries[1].y = 0x38;
            gSpriteEntries[1].scale_x = 2;
            gSpriteEntries[1].scale_y = 2;
            intro_sprite_set_action(1, 1, 0);
            gSceneWork.timer++;
            break;
        case 0xC6:
            if (gSpriteEntries[1].work[INTRO_SPR_ACTION] == 0)
                gSceneWork.timer++;
            break;
        case 0xC7:
            gSpriteEntries[2].frame = 0x407;
            gSpriteEntries[2].y = 0x70;
            gSpriteEntries[2].scale_x = 2;
            gSpriteEntries[2].scale_y = 2;
            intro_sprite_set_action(2, 2, 0);
            gSceneWork.timer++;
            break;
        case 0xC8:
            if (gSpriteEntries[2].work[INTRO_SPR_ACTION] == 0) {
                intro_sprite_set_action(3, 3, 0x78);
                intro_sprite_set_action(3, 4, 0x70);
                intro_sprite_set_action(3, 5, 0x78);
                intro_sprite_set_action(3, 6, 0x70);
                intro_sprite_set_action(3, 7, 0x68);
                intro_sprite_set_action(3, 8, 0x70);
                gSceneWork.timer++;
            }
            break;
        case 0xC9:
            if (intro_draw_pointer_line(1))
                gSceneWork.timer++;
            break;
        default:
            if (intro_type_scan_text(0x28))
                intro_type_part_name(1);
            gSceneWork.timer++;
            break;
        }
    }
    intro_draw_counters();
    intro_update_sprite_actions();
    if (half * 2 <= gSceneWork.timer) {
        gSceneWork.timer = 0;
        gSceneWork.nextSubState = 6;
        gSceneWork.param.afterSubState = 13;
        gGameSubState = 2;
    }
}

void intro_silhouette_second_state(void) {
    if (intro_silhouette_step()) {
        intro_clear_part_name();
        intro_clear_scan_text();
        gSceneWork.timer = 0;
        gSceneWork.nextSubState = 7;
        gSceneWork.param.afterSubState = 0xE;
    }
}

void intro_scan_legs_head_state(void) {
    s32 half = 0xC4;
    s32 i;

    gSceneWork.frameCounter++;
    gSceneWork.noiseCounter += 0x6F;
    if (gSceneWork.timer < half) {
        switch (gSceneWork.timer) {
        case 0:
            sprite_entry_init(1, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_AFFINE,
                              0x40B, 3, 3);
            gSpriteEntries[1].x = 0x50;
            gSpriteEntries[1].y = 0x38;
            gSpriteEntries[1].scale_x = 2;
            gSpriteEntries[1].scale_y = 2;
            intro_sprite_set_action(1, 1, 0);
            intro_sprite_set_action(4, 9, 0);
            intro_sprite_set_action(5, 10, 0);
            gSceneWork.timer++;
            break;
        case 1:
            if (gSpriteEntries[1].work[INTRO_SPR_ACTION] == 0)
                gSceneWork.timer++;
            break;
        case 2:
            sprite_entry_init(2, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE,
                              0x406, 2, 3);
            gSpriteEntries[2].x = 0xB8;
            gSpriteEntries[2].y = 0x70;
            gSpriteEntries[2].scale_x = 2;
            gSpriteEntries[2].scale_y = 2;
            intro_sprite_set_action(2, 2, 0);
            gSceneWork.timer++;
            break;
        case 3:
            if (gSpriteEntries[2].work[INTRO_SPR_ACTION] == 0) {
                intro_sprite_set_action(3, 3, 0x70);
                intro_sprite_set_action(3, 4, 0x68);
                intro_sprite_set_action(3, 5, 0x68);
                intro_sprite_set_action(3, 6, 0x70);
                intro_sprite_set_action(3, 7, 0x78);
                intro_sprite_set_action(3, 8, 0x78);
                gSceneWork.timer++;
            }
            break;
        case 4:
            if (intro_draw_pointer_line(2))
                gSceneWork.timer++;
            break;
        default:
            if (intro_type_scan_text(0x28))
                intro_type_part_name(2);
            gSceneWork.timer++;
            break;
        }
    } else if (gSceneWork.timer == half) {
        intro_clear_part_name();
        intro_clear_scan_text();
        intro_clear_pointer_lines();
        gSpriteEntries[1].y = 200;
        gSpriteEntries[2].y = 200;
        for (i = 0; i < 3; i++)
            gSpriteEntries[i + 11].y = 200;
        for (i = 0; i < 6; i++) {
            intro_sprite_set_action(0, i + 3, 0);
            gSpriteEntries[i + 3].y = 200;
        }
        gSceneWork.timer++;
    } else {
        switch (gSceneWork.timer) {
        case 0xC5:
            gSpriteEntries[1].frame = 0x40C;
            gSpriteEntries[1].y = 0x38;
            gSpriteEntries[1].scale_x = 2;
            gSpriteEntries[1].scale_y = 2;
            intro_sprite_set_action(1, 1, 0);
            gSceneWork.timer++;
            break;
        case 0xC6:
            if (gSpriteEntries[1].work[INTRO_SPR_ACTION] == 0)
                gSceneWork.timer++;
            break;
        case 0xC7:
            gSpriteEntries[2].frame = 0x407;
            gSpriteEntries[2].y = 0x70;
            gSpriteEntries[2].scale_x = 2;
            gSpriteEntries[2].scale_y = 2;
            intro_sprite_set_action(2, 2, 0);
            gSceneWork.timer++;
            break;
        case 0xC8:
            if (gSpriteEntries[2].work[INTRO_SPR_ACTION] == 0) {
                intro_sprite_set_action(3, 3, 0x78);
                intro_sprite_set_action(3, 4, 0x70);
                intro_sprite_set_action(3, 5, 0x78);
                intro_sprite_set_action(3, 6, 0x70);
                intro_sprite_set_action(3, 7, 0x68);
                intro_sprite_set_action(3, 8, 0x70);
                gSceneWork.timer++;
            }
            break;
        case 0xC9:
            if (intro_draw_pointer_line(3))
                gSceneWork.timer++;
            break;
        default:
            if (intro_type_scan_text(0))
                intro_type_part_name(3);
            gSceneWork.timer++;
            break;
        }
    }
    intro_draw_counters();
    intro_update_sprite_actions();
    if (half * 2 <= gSceneWork.timer) {
        gSceneWork.timer = 0;
        gSceneWork.nextSubState = 9;
        gGameSubState = 2;
    }
}

// Sub-state 15: Rokusho's sprite is shown (intro_draw_rokusho_pose) for ~60 frames.
void intro_rokusho_pose_state(void) {
    gSceneWork.poseCounterUp += 0x10;
    gSceneWork.poseCounterDown -= 0x10;
    if (gSceneWork.timer++ > 0x3A) {
        gSceneWork.timer = 0;
        gSceneWork.nextSubState = 6;
        gSceneWork.param.afterSubState = 0x10;
        gGameSubState = 2;
    }
}

void intro_silhouette_third_state(void) {
    if (intro_silhouette_step()) {
        gSceneWork.timer = 0;
        gSceneWork.nextSubState = 0xA;
        gSceneWork.param.afterSubState = 0x11;
    }
}

void intro_closeup_art_state(void) {
    s32 flash_frame = 0x3C;

    if (flash_frame == gSceneWork.timer) {
        REG_BLDCNT = 0xBF;
        REG_BLDY = 0x10;
        intro_load_closeup_art();
        setup_screen_transition_effect_080682CC(4, 4, 0x7FFF);
        REG_BLDY = 0;
        gSceneWork.nextSubState = gGameSubState;
        gGameSubState = 1;
    } else if (flash_frame < gSceneWork.timer) {
        gSceneWork.timer = 0;
        gSceneWork.nextSubState = 0x12;
        setup_screen_transition_effect_080684F0(4, 4, 0);
        gGameSubState = 2;
        return;
    }
    gSceneWork.timer++;
}

// Sub-state 18: the intro is over, go to the title screen.
void intro_go_to_title(void) {
    gGameMode = 3;
    gGameState = 2;
    gGameSubState = 0;
}

// View of 0x03001800 (gSceneWork) for the eye palette fade-in: savedPal holds a copy of OBJ palette 4
// (0x05000280, 16 colours).
struct IntroFade {
    u16 nextMode;
    u16 nextState;
    u16 nextSubState;
    u16 stepFrames; // frames per fade step
    s32 timer;
    u16 afterSubState;
    u16 savedPal[16]; // saved palette (PLTT + 0x280)
};
#define gIntroFade (*(struct IntroFade *)&gSceneWork)

// guess: fades OBJ palette 4 (the silhouette's eyes sprite) in from black over 32 steps while BLDY fades out.
static bool32 intro_eyes_fade_in_step(void) {
    u16 buf[16];
    vs32 inv_level;
    s32 zero;
    s32 i;
    s32 level;
    u16 step;

    zero = 0;
    if (gIntroFade.timer == 0) {
        DmaSet(3, PLTT + 0x280, gIntroFade.savedPal, 0x80000010);
        for (i = 0; i < 16; i++)
            buf[i] = zero;
        DmaSet(3, buf, PLTT + 0x280, 0x84000008);
        REG_BLDCNT &= 0xFFEF;
        REG_DISPCNT |= 0x1B00;
        if (gIntroFade.stepFrames == 0)
            gIntroFade.stepFrames = 1;
    } else if (gIntroFade.timer == gIntroFade.stepFrames * 32) {
        gIntroFade.timer = zero;
        DmaSet(3, gIntroFade.savedPal, PLTT + 0x280, 0x80000010);
        return TRUE;
    } else if (gIntroFade.timer % gIntroFade.stepFrames == 0) {
        level = gIntroFade.timer / gIntroFade.stepFrames;
        inv_level = 0x20 - level;
        for (i = 0; i < 16; i++)
            buf[i] = (((gIntroFade.savedPal[i] & 0x1F) * level + (zero & 0x1F) * (0x20 - level)) >> 5) +
                     ((((gIntroFade.savedPal[i] & 0x3E0) * level + (zero & 0x3E0) * (0x20 - level)) >> 5) & 0x3E0) +
                     ((((gIntroFade.savedPal[i] & 0x7C00) * level + (zero & 0x7C00) * (0x20 - level)) >> 5) & 0x7C00);
        DmaSet(3, buf, PLTT + 0x280, 0x84000008);
        step = gIntroFade.stepFrames;
        if (gIntroFade.timer % (step * 2) == (zero & 0x1F))
            REG_BLDY = 16 - gIntroFade.timer / (step * 4);
    }
    gIntroFade.timer++;
    return FALSE;
}

static bool32 intro_mosaic_fade_in_step(void) {
    u16 step = gSceneWork.stepFrames;
    s32 frame = gSceneWork.timer;
    u8 level;

    if (frame % step == 0) {
        level = 16 - frame / step;
        REG_BLDY = level;
        REG_MOSAIC = (level & 0xF) | ((level & 0xF) << 4);
        if (level == 0) {
            gSceneWork.timer = level;
            return TRUE;
        }
    }
    gSceneWork.timer++;
    return FALSE;
}

static void copy_tilemap_rect_to_vram(const u16 *src, u8 bg, u8 w, u8 h, u8 x, u8 y, u16 tile, u8 pal) {
    u16 buf[0x280];
    vu32 zero;
    s32 i;
    s32 j;

    zero = 0;
    DmaSet(3, &zero, buf, 0x85000140);
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++)
            buf[(i + y) * 32 + j + x] = src[i * w + j] + (pal << 12) + tile;
    }
    DmaSet(3, buf, (bg << 11) + VRAM, 0x80000280);
}

u32 intro_type_part_name(u8 part) {
    const u8 *str = gIntroScanStrings[part + 4];
    u8 ch;

    str += gSceneWork.partNameLen;
    if (gSceneWork.timer & 1) {
        if (*str == 0x14)
            return 1;
        return 0;
    }
    if (*str == 0x14) {
        if (gSceneWork.timer & 8)
            gSceneWork.partNameTiles[gSceneWork.partNameLen] = 0;
        else
            gSceneWork.partNameTiles[gSceneWork.partNameLen] = 0x9078;
        DmaSet(3, gSceneWork.partNameTiles, 0x0600FC44, 0x8000000D);
        return 1;
    }
    ch = *str;
    if (ch == 0x15)
        gSceneWork.partNameTiles[gSceneWork.partNameLen] = 0;
    else
        gSceneWork.partNameTiles[gSceneWork.partNameLen] = ch + 0x9064;
    gSceneWork.partNameLen++;
    DmaSet(3, gSceneWork.partNameTiles, 0x0600FC44, 0x8000000D);
    return 0;
}

u32 intro_type_scan_text(u8 glyph_base) {
    u16 tile;
    register u8 len asm("r8") = gSceneWork.scanTextLen;

    if (len > 39)
        return 1;
    if (!(gSceneWork.timer & 1)) {
        u8 cell = *(vu8 *)&gSceneWork.scanTextLen;
        u32 offset = (u8)(cell / 10) * 64 + (u8)(cell % 10) * 2;
        tile = gSceneWork.scanTextGlyphs[cell + glyph_base] + 0x8001;
        DmaSet(3, &tile, 0x0600FB0A + offset, 0x80000001);
        gSceneWork.scanTextLen = len + 1;
    }
    return 0;
}

static void intro_draw_counters(void) {
    u16 buf[8];
    u16 frames = gSceneWork.frameCounter;
    u16 noise = gSceneWork.noiseCounter % 1000;
    u16 rest;

    buf[3] = frames % 10 + 0x90C8;
    rest = frames / 10;
    buf[1] = rest % 10 + 0x90C8;
    rest /= 10;
    buf[0] = rest % 10 + 0x90C8;
    buf[2] = 0;
    buf[6] = noise % 10 + 0x90C8;
    rest = noise / 10;
    buf[5] = rest % 10 + 0x90C8;
    rest /= 10;
    buf[4] = rest % 10 + 0x90C8;
    DmaSet(3, buf, 0x0600F86C, 0x80000007);
}

// Pointer line `lineIdx` of scan `part`: start column, row, end column, end row.
#define ROW_ENT(field) gIntroPointerLines[gSceneWork.lineIdx * 4 + part * 12 + 0x30 + (field)]

u32 intro_draw_pointer_line(u8 part) {
    u16 tile = 0xD2;
    s32 slot;
    s32 pos;
    s32 first_slot = 14;

    if (gSceneWork.lineIdx > 2)
        return 1;
    if (ROW_ENT(2) <= ROW_ENT(0) + gSceneWork.lineStep) {
        gSpriteEntries[gSceneWork.lineIdx + 11].y = ROW_ENT(3) * 8;
        gSceneWork.lineStep = 0;
        gSceneWork.lineIdx++;
        return 0;
    }
    if (gSceneWork.lineStep <= 1) {
        if (ROW_ENT(3) + gSceneWork.lineStep < ROW_ENT(1)) {
            slot = gSceneWork.lineIdx * 2 + (gSceneWork.lineStep + first_slot);
            ((void (*)())sprite_entry_init)(slot, 0xC400, 0x403, 0, 3);
            gSpriteEntries[slot].x = (ROW_ENT(0) + gSceneWork.lineStep) * 8;
            gSpriteEntries[slot].y = (ROW_ENT(1) - gSceneWork.lineStep) * 8 - 4;
        } else if (ROW_ENT(1) + gSceneWork.lineStep < ROW_ENT(3)) {
            slot = gSceneWork.lineIdx * 2 + (gSceneWork.lineStep + first_slot);
            ((void (*)())sprite_entry_init)(slot, 0xE400, 0x403, 0, 3);
            gSpriteEntries[slot].x = (ROW_ENT(0) + gSceneWork.lineStep) * 8;
            gSpriteEntries[slot].y = (ROW_ENT(1) + gSceneWork.lineStep) * 8 + 12;
        } else {
            pos = gSceneWork.lineStep + (ROW_ENT(0) + ROW_ENT(3) * 32);
            DmaSet(3, &tile, (u16 *)0x0600F800 + pos, 0x80000001);
        }
    } else {
        pos = gSceneWork.lineStep + (ROW_ENT(0) + ROW_ENT(3) * 32);
        DmaSet(3, &tile, (u16 *)0x0600F800 + pos, 0x80000001);
    }
    gSceneWork.lineStep++;
    return 0;
}

#undef ROW_ENT

static void intro_clear_part_name(void) {
    s32 i;

    for (i = 0; i < 13; i++)
        gSceneWork.partNameTiles[i] = 0;
    gSceneWork.partNameLen = 0;
    DmaSet(3, gSceneWork.partNameTiles, 0x0600FC44, 0x8000000D);
}

static void intro_clear_scan_text(void) {
    vu16 fill;

    fill = 0;
    DmaSet(3, &fill, 0x0600FB0A, 0x8100000A);
    fill = 0;
    DmaSet(3, &fill, 0x0600FB4A, 0x8100000A);
    fill = 0;
    DmaSet(3, &fill, 0x0600FB8A, 0x8100000A);
    fill = 0;
    DmaSet(3, &fill, 0x0600FBCA, 0x8100000A);
    gSceneWork.scanTextLen = 0;
}

static void intro_clear_counters(void) {
    u16 fill;

    gSceneWork.noiseCounter = 0;
    gSceneWork.frameCounter = 0;
    fill = 0;
    DmaSet(3, &fill, 0x0600F86C, 0x81000007);
}

static void intro_clear_pointer_lines(void) {
    u32 fill;
    s32 i;

    gSceneWork.lineStep = 0;
    gSceneWork.lineIdx = 0;
    fill = 0;
    DmaSet(3, &fill, 0x0600F800, 0x850000A0);
    for (i = 0; i < 6; i++)
        gSpriteEntries[i + 0xE].y = 0xC8;
}

static bool32 intro_silhouette_step(void) {
    if (gSceneWork.timer == 0x3C) {
        setup_screen_transition_effect_080682CC(4, 1, 0x7FFF);
        REG_BLDCNT = 0x844;
        REG_BLDALPHA = 0x10;
        REG_BLDY = 0;
        REG_DISPCNT |= 0x400;
        gSceneWork.nextSubState = gGameSubState;
        gSceneWork.flashAlpha = 0x10;
        gGameSubState = 5;
    } else if (gSceneWork.timer > 0x3C) {
        setup_screen_transition_effect_080684F0(2, 2, 0);
        gGameSubState = 2;
        return TRUE;
    }
    gSceneWork.timer++;
    return FALSE;
}

void intro_load_art_unused(void) {
    u16 dst[0x280];
    u16 src[0x258];
    vu32 zero;
    s32 i, j;

    LZ77UnCompVram(gIntroUnusedArtTilesLz, (void *)VRAM);
    LZ77UnCompVram(gIntroUnusedArtTilemapLz, src);
    zero = 0;
    DmaSet(3, &zero, VRAM + 0x7800, 0x85000200);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            dst[i * 32 + j] = src[i * 30 + j];
        dst[i * 32 + 30] = dst[i * 32 + 31] = 0;
    }
    DmaSet(3, dst, VRAM + 0x7800, 0x80000280);
    DmaSet(3, gIntroUnusedArtPalette, PLTT, 0x80000100);
    REG_BG0CNT = 0xFC0;
    REG_DISPCNT |= 0x100;
}

void intro_load_versus_art(void) {
    u16 dst[0x280];
    u16 src[0x258];
    vu32 zero;
    s32 i, j;

    LZ77UnCompVram(gIntroVersusArtTilesLz, (void *)VRAM);
    LZ77UnCompVram(gIntroVersusArtTilemapLz, src);
    zero = 0;
    DmaSet(3, &zero, VRAM + 0x7800, 0x85000200);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            dst[i * 32 + j] = src[i * 30 + j];
        dst[i * 32 + 30] = dst[i * 32 + 31] = 0;
    }
    DmaSet(3, dst, VRAM + 0x7800, 0x80000280);
    DmaSet(3, gIntroVersusArtPalette, PLTT, 0x80000100);
    REG_BG0CNT = 0xFC0;
    REG_DISPCNT |= 0x100;
}

void intro_load_closeup_art(void) {
    u16 dst[0x280];
    u16 src[0x258];
    vu32 zero;
    s32 i, j;

    LZ77UnCompVram(gIntroCloseupArtTilesLz, (void *)VRAM);
    LZ77UnCompVram(gIntroCloseupArtTilemapLz, src);
    zero = 0;
    DmaSet(3, &zero, VRAM + 0x7800, 0x85000200);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            dst[i * 32 + j] = src[i * 30 + j];
        dst[i * 32 + 30] = dst[i * 32 + 31] = 0;
    }
    DmaSet(3, dst, VRAM + 0x7800, 0x80000280);
    DmaSet(3, gIntroCloseupArtPalette, PLTT, 0x80000100);
    REG_BG0CNT = 0xF80;
    REG_DISPCNT |= 0x100;
}

void intro_update_sprite_actions(void) {
    u8 i;

    for (i = 0; i <= 10; i++) {
        struct SpriteEntry *base = gSpriteEntries;
        struct SpriteEntry *sprite = &base[i];

        if (sprite->work[INTRO_SPR_ACTION] != 0) {
            if (++sprite->timer % gIntroSpriteActionPeriods[sprite->work[INTRO_SPR_ACTION] - 1] == 0) {
                switch (gIntroSpriteActions[sprite->work[INTRO_SPR_ACTION] - 1](i)) {
                case 0:
                    sprite->work[INTRO_SPR_ACTION] = 0;
                    sprite->work[INTRO_SPR_STEP] = 0;
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
}

s32 intro_action_grow_height_first(u8 i) {
    if (gSpriteEntries[i].scale_x > 0x3F && gSpriteEntries[i].scale_y > 0x3F)
        return 0;
    if (gSpriteEntries[i].scale_y <= 0x3F) {
        if ((gSpriteEntries[i].scale_y += 8) > 0x40)
            gSpriteEntries[i].scale_y = 0x40;
    } else {
        if ((gSpriteEntries[i].scale_x += 8) > 0x40)
            gSpriteEntries[i].scale_x = 0x40;
    }
    gSpriteEntries[i].work[INTRO_SPR_STEP]++;
    return 1;
}

s32 intro_action_grow_width_first(u8 i) {
    if (gSpriteEntries[i].scale_x > 0x3F && gSpriteEntries[i].scale_y > 0x3F)
        return 0;
    if (gSpriteEntries[i].scale_x <= 0x3F) {
        if ((gSpriteEntries[i].scale_x += 8) > 0x40)
            gSpriteEntries[i].scale_x = 0x40;
    } else {
        if ((gSpriteEntries[i].scale_y += 8) > 0x40)
            gSpriteEntries[i].scale_y = 0x40;
    }
    gSpriteEntries[i].work[INTRO_SPR_STEP]++;
    return 1;
}

s32 intro_action_bob(u8 i) {
    if (i & 1)
        gSpriteEntries[i].y =
            gSpriteEntries[i].work[INTRO_SPR_BASE_Y] - gIntroBobOffsets[gSpriteEntries[i].work[INTRO_SPR_STEP] & 0x3F];
    else
        gSpriteEntries[i].y =
            gSpriteEntries[i].work[INTRO_SPR_BASE_Y] + gIntroBobOffsets[gSpriteEntries[i].work[INTRO_SPR_STEP] & 0x3F];
    gSpriteEntries[i].work[INTRO_SPR_STEP] += 1 + gSpriteEntries[i].work[INTRO_SPR_BOB_SPEED];
    return 1;
}

s32 intro_action_scan_up(u8 i) {
    if (gSpriteEntries[i].work[INTRO_SPR_STEP] < 0x48) {
        gSpriteEntries[i].work[INTRO_SPR_STEP]++;
    } else if (gSpriteEntries[i].y < -0x50) {
        gSpriteEntries[i].y = 0xA0;
        gSpriteEntries[i].work[INTRO_SPR_STEP] = 0;
    } else {
        gSpriteEntries[i].y -= 4;
    }
    return 1;
}

s32 intro_action_scan_right(u8 i) {
    if (gSpriteEntries[i].work[INTRO_SPR_STEP] < 0x48) {
        gSpriteEntries[i].work[INTRO_SPR_STEP]++;
    } else if (gSpriteEntries[i].x > 0x168) {
        gSpriteEntries[i].x = 0;
        gSpriteEntries[i].work[INTRO_SPR_STEP] = 0;
    } else {
        gSpriteEntries[i].x += 6;
    }
    return 1;
}

static void intro_sprite_set_action(u8 action, u8 i, u8 y) {
    struct SpriteEntry *base = gSpriteEntries;
    struct SpriteEntry *sprite = &base[i];

    sprite->work[INTRO_SPR_ACTION] = action;
    sprite->work[INTRO_SPR_STEP] = 0;
    if (y != 0) {
        sprite->work[INTRO_SPR_BOB_SPEED] = rng_next(0) & 3;
        sprite->work[INTRO_SPR_BASE_Y] = y - 4;
    }
    sprite->work16[INTRO_SPR_START_FRAME] = sprite->frame;
    sprite->timer = 0;
}
