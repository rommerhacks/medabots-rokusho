// Mode-3 dispatcher (gGameStateHandlers: boot logos, intro, race, bomb game, Medabots Weekly...) and the screen
// transitions those scenes share: random tile-mosaic in / out effects and the fade / wipe step tables
// gSceneTransitionSteps (scene_transition_step_080686F4) and gSceneSteps (execute_scene_step).
#include "global.h"

void dispatch_game_mode_handler(void) {
    gGameStateHandlers[gGameState]();
}

void setup_screen_transition_effect_080682CC(u8 step, u8 frames_per_level, u16 fade_color) {
    u8 tiles[0x80];
    u16 map[0x280];
    u16 pal[0x200];
    int i;

    gSceneStepFrames = 0;
    gTransitionFadeColor = fade_color;
    gSceneStep = step;
    gTransitionFramesPerLevel = frames_per_level;
    if (frames_per_level == 0)
        gTransitionFramesPerLevel = 1;
    switch (step) {
    case 1:
        REG_BLDCNT = 0xBF;
        REG_BLDY = 0x10;
        break;
    case 2:
        REG_BLDCNT = 0xFF;
        REG_BLDY = 0x10;
        break;
    case 3:
        for (i = 0; i < 0x80; i++)
            tiles[i] = 0x11;
        DmaSet(3, tiles, BG_VRAM + 0xFF80, 0x80000040);
        for (i = 0; i < 0x280; i++)
            map[i] = (gRandomBytes[(gFrameCounter + i) & 0xFF] % 4) + 0xF1FC;
        DmaSet(3, map, BG_SCREEN_ADDR(31), 0x84000140);
        DmaSet(3, &gTransitionFadeColor, 0x050001E2, 0x80000001);
        REG_BG0CNT = 0x1F0C;
        REG_DISPCNT |= 0x100;
        REG_BLDY = 0;
        for (i = 0; i < 4; i++) {
            gTransitionWipeRows[i * 4 + 0] = (i + 0x1FC) * 0x20;
            gTransitionWipeRows[i * 4 + 1] = (i + 0x1FC) * 0x20 + 2;
            gTransitionWipeRows[i * 4 + 2] = (i + 0x1FC) * 0x20 + 0x10;
            gTransitionWipeRows[i * 4 + 3] = (i + 0x1FC) * 0x20 + 0x12;
        }
        for (i = 0; i < 15; i++) {
            int j = gRandomBytes[(gFrameCounter + i) & 0xFF] % (16 - i) + i;
            u16 swap = gTransitionWipeRows[i];
            gTransitionWipeRows[i] = gTransitionWipeRows[j];
            gTransitionWipeRows[j] = swap;
        }
        break;
    case 4:
        gTransitionSourcePalette = gPaletteBackup;
        DmaSet(3, PLTT, gPaletteBackup, 0x80000200);
        for (i = 0; i < 0x200; i++)
            pal[i] = fade_color;
        DmaSet(3, pal, PLTT, 0x84000100);
        break;
    }
}

void setup_screen_transition_effect_080684F0(u8 step, u8 frames_per_level, u16 fade_color) {
    u8 tiles[0x80];
    u16 map[0x280];
    int i;

    gSceneStepFrames = frames_per_level;
    gTransitionFadeColor = fade_color;
    gSceneStep = step;
    gTransitionFramesPerLevel = frames_per_level;
    if (frames_per_level == 0)
        gTransitionFramesPerLevel = 1;
    switch (step) {
    case 1:
        REG_BLDCNT = 0xBF;
        break;
    case 2:
        REG_BLDCNT = 0xFF;
        break;
    case 3:
        for (i = 0; i < 0x80; i++)
            tiles[i] = 0x11;
        DmaSet(3, tiles, BG_VRAM + 0xFF80, 0x80000040);
        for (i = 0; i < 0x280; i++)
            map[i] = (gRandomBytes[(gFrameCounter + i) & 0xFF] % 4) + 0xF1FC;
        DmaSet(3, map, BG_SCREEN_ADDR(31), 0x84000140);
        DmaSet(3, &gTransitionFadeColor, 0x050001E2, 0x80000001);
        REG_BG0CNT = 0x1F0C;
        REG_DISPCNT |= 0x100;
        for (i = 0; i < 4; i++) {
            gTransitionWipeRows[i * 4 + 0] = (i + 0x1FC) * 0x20;
            gTransitionWipeRows[i * 4 + 1] = (i + 0x1FC) * 0x20 + 2;
            gTransitionWipeRows[i * 4 + 2] = (i + 0x1FC) * 0x20 + 0x10;
            gTransitionWipeRows[i * 4 + 3] = (i + 0x1FC) * 0x20 + 0x12;
        }
        for (i = 0; i < 15; i++) {
            int j = gRandomBytes[(gFrameCounter + i) & 0xFF] % (16 - i) + i;
            u16 swap = gTransitionWipeRows[i];
            gTransitionWipeRows[i] = gTransitionWipeRows[j];
            gTransitionWipeRows[j] = swap;
        }
        break;
    case 4:
        gTransitionSourcePalette = gPaletteBackup;
        DmaSet(3, PLTT, gPaletteBackup, 0x80000200);
        scene_step_palette_fade_out();
        break;
    }
}

// Unused (nothing calls it): copies the saved palette back to PLTT.
static void scene_restore_palette(void) {
    DmaSet(3, gTransitionSourcePalette, PLTT, 0x80000200);
}

bool32 scene_transition_step_080686F4(void) {
    if (gSceneTransitionSteps[gSceneStep]()) {
        gSceneStepFrames = 0;
        if (gSceneStep == 3)
            REG_DISPCNT &= 0xFEFF;
        return TRUE;
    }
    gSceneStepFrames++;
    return FALSE;
}

bool32 execute_scene_step(void) {
    if (gSceneSteps[gSceneStep]()) {
        gSceneStepFrames = 0;
        return TRUE;
    }
    gSceneStepFrames++;
    return FALSE;
}

bool32 scene_step_none(void) {
    return TRUE;
}

bool32 scene_step_fade_in_bldy(void) {
    s32 *frames_ptr = &gSceneStepFrames;
    u8 *np = &gTransitionFramesPerLevel;
    u8 n = *np;
    s32 frame = *frames_ptr;
    if (frame % n == 0)
        REG_BLDY = 16 - frame / n;
    if (*frames_ptr == *np * 16)
        return TRUE;
    return FALSE;
}

bool32 scene_step_wipe_clear_bg0(void) {
    u16 zero = 0;
    s32 *frames_ptr;
    u8 *np;
    s32 frame;
    REG_DISPCNT |= 0x100;
    frames_ptr = &gSceneStepFrames;
    np = &gTransitionFramesPerLevel;
    {
        u8 n = *np;
        frame = *frames_ptr;
        if (frame % n == 0) {
            DmaSet(3, &zero, gTransitionWipeRows[frame / *np] + BG_SCREEN_ADDR(24), 0x80000001);
            DmaSet(3, &zero, gTransitionWipeRows[frame / *np] + (BG_VRAM + 0xC004), 0x80000001);
            DmaSet(3, &zero, gTransitionWipeRows[frame / *np] + (BG_VRAM + 0xC008), 0x80000001);
            DmaSet(3, &zero, gTransitionWipeRows[frame / *np] + (BG_VRAM + 0xC00C), 0x80000001);
        }
    }
    if (*frames_ptr == *np * 16) {
        REG_DISPCNT &= 0xFEFF;
        return TRUE;
    }
    return FALSE;
}

bool32 scene_step_palette_fade_in(void) {
    s32 *frames_ptr = &gSceneStepFrames;
    s32 n = gTransitionFramesPerLevel;
    s32 end_frame = n * 32;
    s32 frame = *frames_ptr;
    if (frame == end_frame)
        return TRUE;
    if (frame % n == 0) {
        int i, k, inv;
        k = frame / n;
        inv = 0x20 - k;
        for (i = 0; i < 0x200; i++) {
            gPaletteBuffer[i] =
                (((gTransitionSourcePalette[i] & 0x1F) * k + (gTransitionFadeColor & 0x1F) * inv) >> 5) +
                ((((gTransitionSourcePalette[i] & 0x3E0) * k + (gTransitionFadeColor & 0x3E0) * inv) >> 5) & 0x3E0) +
                ((((gTransitionSourcePalette[i] & 0x7C00) * k + (gTransitionFadeColor & 0x7C00) * inv) >> 5) & 0x7C00);
        }
        DmaSet(3, gPaletteBuffer, PLTT, 0x84000100);
    }
    return FALSE;
}

bool32 scene_step_fade_out_bldy(void) {
    s32 *frames_ptr = &gSceneStepFrames;
    u8 *np = &gTransitionFramesPerLevel;
    u8 n = *np;
    s32 frame = *frames_ptr;
    if (frame % n == 0)
        REG_BLDY = frame / n;
    if (*frames_ptr == *np * 16)
        return TRUE;
    return FALSE;
}

bool32 scene_step_wipe_fill_bg0(void) {
    u16 fill = 0x1111;
    s32 *frames_ptr;
    u8 *np;
    frames_ptr = &gSceneStepFrames;
    if (*frames_ptr == 0)
        REG_DISPCNT |= 0x100;
    np = &gTransitionFramesPerLevel;
    if (*frames_ptr % *np == 0) {
        DmaSet(3, &fill, gTransitionWipeRows[*frames_ptr / *np] + BG_SCREEN_ADDR(24), 0x80000001);
        DmaSet(3, &fill, gTransitionWipeRows[*frames_ptr / *np] + (BG_VRAM + 0xC004), 0x80000001);
        DmaSet(3, &fill, gTransitionWipeRows[*frames_ptr / *np] + (BG_VRAM + 0xC008), 0x80000001);
        DmaSet(3, &fill, gTransitionWipeRows[*frames_ptr / *np] + (BG_VRAM + 0xC00C), 0x80000001);
    }
    if (*frames_ptr == *np * 16)
        return TRUE;
    return FALSE;
}

bool32 scene_step_palette_fade_out(void) {
    s32 *frames_ptr = &gSceneStepFrames;
    s32 n = gTransitionFramesPerLevel;
    s32 end_frame = n * 32;
    s32 frame = *frames_ptr;
    if (frame == end_frame)
        return TRUE;
    if (frame % n == 0) {
        int i, k, inv;
        u16 *dst;
        k = frame / n;
        inv = 0x20 - k;
        if (k <= 0) {
            DmaSet(3, PLTT, gTransitionSourcePalette, 0x84000100);
        } else {
            for (i = 0; i < 0x200; i++) {
                gPaletteBuffer[i] =
                    (((gTransitionSourcePalette[i] & 0x1F) * inv + (gTransitionFadeColor & 0x1F) * k) >> 5) +
                    ((((gTransitionSourcePalette[i] & 0x3E0) * inv + (gTransitionFadeColor & 0x3E0) * k) >> 5) &
                     0x3E0) +
                    ((((gTransitionSourcePalette[i] & 0x7C00) * inv + (gTransitionFadeColor & 0x7C00) * k) >> 5) &
                     0x7C00);
            }
            DmaSet(3, gPaletteBuffer, PLTT, 0x84000100);
        }
    }
    return FALSE;
}
