// Mode-3 dispatcher (gUnk_08485C48: boot logos, intro, race, bomb game, Medabots Weekly...) and the screen
// transitions those scenes share: random tile-mosaic in / out effects and the fade / wipe step tables
// gUnk_08485C68 (scene_transition_step_080686F4) and gUnk_08485C7C (execute_scene_step).
#include "global.h"

void dispatch_game_mode_handler(void) {
    gUnk_08485C48[gGameState]();
}

void setup_screen_transition_effect_080682CC(u8 a, u8 b, u16 c) {
    u8 tiles[0x80];
    u16 map[0x280];
    u16 pal[0x200];
    int i;

    gUnk_03000000 = 0;
    gUnk_03000028 = c;
    gUnk_03000004 = a;
    gUnk_03000005 = b;
    if (b == 0)
        gUnk_03000005 = 1;
    switch (a) {
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
        DmaSet(3, tiles, 0x0600FF80, 0x80000040);
        for (i = 0; i < 0x280; i++)
            map[i] = (gUnk_083F7FF4[(gFrameCounter + i) & 0xFF] % 4) + 0xF1FC;
        DmaSet(3, map, 0x0600F800, 0x84000140);
        DmaSet(3, &gUnk_03000028, 0x050001E2, 0x80000001);
        REG_BG0CNT = 0x1F0C;
        REG_DISPCNT |= 0x100;
        REG_BLDY = 0;
        for (i = 0; i < 4; i++) {
            gUnk_03000008[i * 4 + 0] = (i + 0x1FC) * 0x20;
            gUnk_03000008[i * 4 + 1] = (i + 0x1FC) * 0x20 + 2;
            gUnk_03000008[i * 4 + 2] = (i + 0x1FC) * 0x20 + 0x10;
            gUnk_03000008[i * 4 + 3] = (i + 0x1FC) * 0x20 + 0x12;
        }
        for (i = 0; i < 15; i++) {
            int j = gUnk_083F7FF4[(gFrameCounter + i) & 0xFF] % (16 - i) + i;
            u16 tmp = gUnk_03000008[i];
            gUnk_03000008[i] = gUnk_03000008[j];
            gUnk_03000008[j] = tmp;
        }
        break;
    case 4:
        gUnk_0300002C = gPaletteBackup;
        DmaSet(3, PLTT, gPaletteBackup, 0x80000200);
        for (i = 0; i < 0x200; i++)
            pal[i] = c;
        DmaSet(3, pal, PLTT, 0x84000100);
        break;
    }
}

void setup_screen_transition_effect_080684F0(u8 a, u8 b, u16 c) {
    u8 tiles[0x80];
    u16 map[0x280];
    int i;

    gUnk_03000000 = b;
    gUnk_03000028 = c;
    gUnk_03000004 = a;
    gUnk_03000005 = b;
    if (b == 0)
        gUnk_03000005 = 1;
    switch (a) {
    case 1:
        REG_BLDCNT = 0xBF;
        break;
    case 2:
        REG_BLDCNT = 0xFF;
        break;
    case 3:
        for (i = 0; i < 0x80; i++)
            tiles[i] = 0x11;
        DmaSet(3, tiles, 0x0600FF80, 0x80000040);
        for (i = 0; i < 0x280; i++)
            map[i] = (gUnk_083F7FF4[(gFrameCounter + i) & 0xFF] % 4) + 0xF1FC;
        DmaSet(3, map, 0x0600F800, 0x84000140);
        DmaSet(3, &gUnk_03000028, 0x050001E2, 0x80000001);
        REG_BG0CNT = 0x1F0C;
        REG_DISPCNT |= 0x100;
        for (i = 0; i < 4; i++) {
            gUnk_03000008[i * 4 + 0] = (i + 0x1FC) * 0x20;
            gUnk_03000008[i * 4 + 1] = (i + 0x1FC) * 0x20 + 2;
            gUnk_03000008[i * 4 + 2] = (i + 0x1FC) * 0x20 + 0x10;
            gUnk_03000008[i * 4 + 3] = (i + 0x1FC) * 0x20 + 0x12;
        }
        for (i = 0; i < 15; i++) {
            int j = gUnk_083F7FF4[(gFrameCounter + i) & 0xFF] % (16 - i) + i;
            u16 tmp = gUnk_03000008[i];
            gUnk_03000008[i] = gUnk_03000008[j];
            gUnk_03000008[j] = tmp;
        }
        break;
    case 4:
        gUnk_0300002C = gPaletteBackup;
        DmaSet(3, PLTT, gPaletteBackup, 0x80000200);
        scene_step_palette_fade_out();
        break;
    }
}

// Unused (nothing calls it): copies the saved palette back to PLTT.
static void scene_restore_palette(void) {
    DmaSet(3, gUnk_0300002C, PLTT, 0x80000200);
}

bool32 scene_transition_step_080686F4(void) {
    if (gUnk_08485C68[gUnk_03000004]()) {
        gUnk_03000000 = 0;
        if (gUnk_03000004 == 3)
            REG_DISPCNT &= 0xFEFF;
        return TRUE;
    }
    gUnk_03000000++;
    return FALSE;
}

bool32 execute_scene_step(void) {
    if (gUnk_08485C7C[gUnk_03000004]()) {
        gUnk_03000000 = 0;
        return TRUE;
    }
    gUnk_03000000++;
    return FALSE;
}

bool32 scene_step_none(void) {
    return TRUE;
}

bool32 scene_step_fade_in_bldy(void) {
    s32 *c = &gUnk_03000000;
    u8 *np = &gUnk_03000005;
    u8 n = *np;
    s32 t = *c;
    if (t % n == 0)
        REG_BLDY = 16 - t / n;
    if (*c == *np * 16)
        return TRUE;
    return FALSE;
}

bool32 scene_step_wipe_clear_bg0(void) {
    u16 zero = 0;
    s32 *c;
    u8 *np;
    s32 t;
    REG_DISPCNT |= 0x100;
    c = &gUnk_03000000;
    np = &gUnk_03000005;
    {
        u8 n = *np;
        t = *c;
        if (t % n == 0) {
            DmaSet(3, &zero, gUnk_03000008[t / *np] + 0x0600C000, 0x80000001);
            DmaSet(3, &zero, gUnk_03000008[t / *np] + 0x0600C004, 0x80000001);
            DmaSet(3, &zero, gUnk_03000008[t / *np] + 0x0600C008, 0x80000001);
            DmaSet(3, &zero, gUnk_03000008[t / *np] + 0x0600C00C, 0x80000001);
        }
    }
    if (*c == *np * 16) {
        REG_DISPCNT &= 0xFEFF;
        return TRUE;
    }
    return FALSE;
}

bool32 scene_step_palette_fade_in(void) {
    s32 *c = &gUnk_03000000;
    s32 n = gUnk_03000005;
    s32 m = n * 32;
    s32 t = *c;
    if (t == m)
        return TRUE;
    if (t % n == 0) {
        int i, k, inv;
        k = t / n;
        inv = 0x20 - k;
        for (i = 0; i < 0x200; i++) {
            gPaletteBuffer[i] = (((gUnk_0300002C[i] & 0x1F) * k + (gUnk_03000028 & 0x1F) * inv) >> 5) +
                                ((((gUnk_0300002C[i] & 0x3E0) * k + (gUnk_03000028 & 0x3E0) * inv) >> 5) & 0x3E0) +
                                ((((gUnk_0300002C[i] & 0x7C00) * k + (gUnk_03000028 & 0x7C00) * inv) >> 5) & 0x7C00);
        }
        DmaSet(3, gPaletteBuffer, PLTT, 0x84000100);
    }
    return FALSE;
}

bool32 scene_step_fade_out_bldy(void) {
    s32 *c = &gUnk_03000000;
    u8 *np = &gUnk_03000005;
    u8 n = *np;
    s32 t = *c;
    if (t % n == 0)
        REG_BLDY = t / n;
    if (*c == *np * 16)
        return TRUE;
    return FALSE;
}

bool32 scene_step_wipe_fill_bg0(void) {
    u16 fill = 0x1111;
    s32 *c;
    u8 *np;
    c = &gUnk_03000000;
    if (*c == 0)
        REG_DISPCNT |= 0x100;
    np = &gUnk_03000005;
    if (*c % *np == 0) {
        DmaSet(3, &fill, gUnk_03000008[*c / *np] + 0x0600C000, 0x80000001);
        DmaSet(3, &fill, gUnk_03000008[*c / *np] + 0x0600C004, 0x80000001);
        DmaSet(3, &fill, gUnk_03000008[*c / *np] + 0x0600C008, 0x80000001);
        DmaSet(3, &fill, gUnk_03000008[*c / *np] + 0x0600C00C, 0x80000001);
    }
    if (*c == *np * 16)
        return TRUE;
    return FALSE;
}

bool32 scene_step_palette_fade_out(void) {
    s32 *c = &gUnk_03000000;
    s32 n = gUnk_03000005;
    s32 m = n * 32;
    s32 t = *c;
    if (t == m)
        return TRUE;
    if (t % n == 0) {
        int i, k, inv;
        u16 *dst;
        k = t / n;
        inv = 0x20 - k;
        if (k <= 0) {
            DmaSet(3, PLTT, gUnk_0300002C, 0x84000100);
        } else {
            for (i = 0; i < 0x200; i++) {
                gPaletteBuffer[i] =
                    (((gUnk_0300002C[i] & 0x1F) * inv + (gUnk_03000028 & 0x1F) * k) >> 5) +
                    ((((gUnk_0300002C[i] & 0x3E0) * inv + (gUnk_03000028 & 0x3E0) * k) >> 5) & 0x3E0) +
                    ((((gUnk_0300002C[i] & 0x7C00) * inv + (gUnk_03000028 & 0x7C00) * k) >> 5) & 0x7C00);
            }
            DmaSet(3, gPaletteBuffer, PLTT, 0x84000100);
        }
    }
    return FALSE;
}
