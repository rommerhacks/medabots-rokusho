// Mode-3 state 2: the title screen. title_screen_update runs gTitleScreenStates with a BG2 per-scanline wave (HBlank
// handler title_screen_hblank). START goes to the title menu (mode 2 state 3), SELECT+START to the test mode
// (mode 2 state 7); after a timeout it loops back to the boot logos (mode 3 state 0).
// Sub-states: 0 reset, 4 graphics, 5 logo, 6 sprites slide in, 7 wave + PRESS START, 8 wait for START,
// 9 START pressed, 10 skip the intro (START held, or gTitleSkipIntro set by the logos / intro / test mode),
// 1-3 shared fade / exit helpers. Each sprite runs a per-frame effect from gTitleSpriteEffects
// (work[TITLE_SPR_EFFECT]).
#include "global.h"
#include "constants/sprites.h"

// gSpriteEntries work[] / work16[] indices
#define TITLE_SPR_EFFECT 0x0    // gTitleSpriteEffects index + 1, 0 = none
#define TITLE_SPR_STEP 0x2      // the effect's step counter
#define TITLE_SPR_START_FRAME 0 // work16: frame when the effect started
#define TITLE_SPR_GLINT_WAIT 1  // work16, glint effect: frames until the next glint (0xFFFF = none)

static void title_sprite_start_effect(u8 effect, u8 sprite);

static void title_screen_check_skip_or_test_mode(void) {
    if (gSceneWork.nextSubState == 5 && ((KEYS_LO(gHeldKeys) & START_BUTTON) || gTitleSkipIntro != 0)) {
        gTitleSkipIntro = 0;
        gGameMode = 3;
        gGameState = 2;
        gGameSubState = 10;
    } else if ((KEYS_LO(gHeldKeys) & SELECT_BUTTON) && (KEYS_LO(gNewKeys) & START_BUTTON)) {
        gGameMode = 2;
        gGameState = 7;
        gGameSubState = 0;
    }
}

static inline s32 mul120(u16 x) {
    return x * 120;
}

static inline s32 sub_counter(void) {
    return 0x7800 - gTitleBg2ScrollX;
}

// Builds the per-scanline BG2 PA / X tables read by the HBlank handler title_screen_hblank:
// lines 0-31 and 128-159 get X = 0x7800 -+ counter - PA * 120, lines 32-127 X = 0.
// Builds the BG2 PA / X tables read by the HBlank handler title_screen_hblank (rows 32-127 get X = 0).
void title_screen_build_wave_tables(void) {
    s32 i;
    s32 x;
    s32 center_x;

    gTitleBg2ScrollX += 0x80;
    for (i = 0; i < 32; i++) {
        x = sub_counter() - mul120(gTitleBg2PaTable[i]);
        gTitleBg2XLowTable[i] = x;
        gTitleBg2XHighTable[i] = x >> 16;
    }
    for (; i < 128; i++) {
        gTitleBg2XLowTable[i] = 0;
        gTitleBg2XHighTable[i] = 0;
    }
    for (; i < 160; i++) {
        center_x = gTitleBg2ScrollX + 0x7800;
        x = center_x - mul120(gTitleBg2PaTable[i]);
        gTitleBg2XLowTable[i] = x;
        gTitleBg2XHighTable[i] = x >> 16;
    }
    REG_BG2PA = gTitleBg2PaTable[0];
    REG_BG2X_L = gTitleBg2XLowTable[0];
    REG_BG2X_H = gTitleBg2XHighTable[0];
}

void title_screen_update(void) {
    title_screen_build_wave_tables();
    gTitleScreenStates[gGameSubState]();
    title_screen_update_sprite_effects();
    title_screen_check_skip_or_test_mode();
}

// HBlank: sets the next scanline's BG2 PA and X from the tables built by title_screen_build_wave_tables.
// VCOUNT is read through a non-volatile pointer: the compare's load is reused for the first index.
void title_screen_hblank(void) {
    if (*(u8 *)REG_ADDR_VCOUNT < 159) {
        REG_BG2PA = gTitleBg2PaTable[*(u8 *)REG_ADDR_VCOUNT + 1];
        REG_BG2X_L = gTitleBg2XLowTable[*(u8 *)REG_ADDR_VCOUNT + 1];
        REG_BG2X_H = gTitleBg2XHighTable[*(u8 *)REG_ADDR_VCOUNT + 1];
    }
}

void title_screen_fade_out_exit(void) {
    if (execute_scene_step()) {
        u32 zero = 0;
        DmaSet(3, &zero, gSpriteEntries, 0x85000800);
        REG_DISPCNT &= 0x80FF;
        gGameMode = gSceneWork.nextMode;
        gGameState = gSceneWork.nextState;
        gGameSubState = gSceneWork.nextSubState;
        REG_DISPCNT &= ~0x0400;
        REG_IE &= ~2;
        REG_DISPSTAT &= ~0x10;
        gHBlankCallback = empty_callback;
        play_song(0);
    }
}

void title_screen_wait_then_exit(void) {
    if (gSceneWork.stepFrames < ++gSceneWork.timer) {
        gSceneWork.timer = 0;
        gGameMode = gSceneWork.nextMode;
        gGameState = gSceneWork.nextState;
        gGameSubState = gSceneWork.nextSubState;
    }
}

// Title screen sub-state 0: clears the screen and the scene struct, then sub-state 4 (title_screen_load_graphics).
void title_screen_reset(void) {
    u32 zero = 0;
    DmaSet(3, &zero, VRAM, 0x85006000);
    zero = 0;
    DmaSet(3, &zero, PLTT, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, gSpriteEntries, 0x85000800);
    zero = 0;
    DmaSet(3, &zero, &gSceneWork, 0x8500000B);
    REG_DISPCNT = 0x61;
    gSceneWork.nextMode = 3;
    gSceneWork.nextState = 2;
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gGameSubState = 4;
}

void title_screen_load_graphics(void) {
    LZ77UnCompVram(gTitleBgTiles, (void *)VRAM);
    DmaSet(3, gTitleBg2Tiles, VRAM + 0x8000, 0x84000090);
    DmaSet(3, gTitleBgPalettes, PLTT, 0x84000030);
    LZ77UnCompVram(gTitleBg0Tilemap, (void *)(VRAM + 0x6800));
    LZ77UnCompVram(gTitleBg1Tilemap, (void *)(VRAM + 0x7000));
    DmaSet(3, gTitleBg2Tilemap, VRAM + 0x7800, 0x840000A0);
    REG_BG0CNT = 0xD01;
    REG_BG1CNT = 0xE03;
    REG_BG2CNT = 0x6F8A;
    LZ77UnCompVram(gTitleObjTiles, (void *)(VRAM + 0x10000));
    DmaSet(3, gTitleObjPalettes, PLTT + 0x200, 0x80000060);
    DmaSet(3, gTitleObjPalettes + 0x60, &gSceneWork.param, 0x8000000E);
    setup_screen_transition_effect_080682CC(2, 1, 0);
    gSceneWork.nextSubState = 5;
    gGameSubState = 1;
}

void title_screen_show_logo(void) {
    if (gSceneWork.timer == 0) {
        sprite_entry_init(0, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3), 0x224, 6, 3);
        gSpriteEntries[0].x = 0x78;
        gSpriteEntries[0].y = 0x3C;
        gSpriteEntries[0].order = 0x10;
        title_sprite_start_effect(1, 0);
        REG_DISPCNT |= 0x1000;
    } else if (gSceneWork.timer == 0x20) {
        sprite_entry_init(1, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1), 0x200, 0, 3);
        gSpriteEntries[1].x = 0x78;
        gSpriteEntries[1].y = 0x3C;
        gSpriteEntries[1].order = 0x20;
        title_sprite_start_effect(2, 1);
    }
    if (gSpriteEntries[0].work[TITLE_SPR_EFFECT] == 0) {
        gSceneWork.nextSubState = 6;
        gSceneWork.timer = 0;
        setup_screen_transition_effect_080682CC(4, 4, 0x7FFF);
        clear_sprite_entry(1);
        sprite_entry_init(0, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1), 0x21B, 4, 3);
        REG_DISPCNT |= 0x300;
        gGameSubState = 1;
    } else {
        gSceneWork.timer++;
    }
}

void title_screen_slide_in_sprites(void) {
    if (gSceneWork.timer == 0) {
        play_song(0);
        sprite_entry_init(1, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1), 0x211, 1, 3);
        gSpriteEntries[1].x = 0x118;
        gSpriteEntries[1].y = 0x55;
        gSpriteEntries[1].order = 0x20;
        title_sprite_start_effect(3, 1);
    }
    if (gSpriteEntries[1].work[TITLE_SPR_EFFECT] == 0) {
        sprite_entry_init(3, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE, 0x213, 3, 3);
        gSpriteEntries[3].x = 0x12C;
        gSpriteEntries[3].y = 0x55;
        gSpriteEntries[3].order = 0x40;
        gSpriteEntries[3].work16[TITLE_SPR_GLINT_WAIT] = 0;
        title_sprite_start_effect(7, 3);
        sprite_entry_init(4, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1), 0x21C, 5, 3);
        gSpriteEntries[4].x = 0x12C;
        gSpriteEntries[4].y = 0x3C;
        gSpriteEntries[4].order = 0x10;
        gSpriteEntries[4].work16[TITLE_SPR_GLINT_WAIT] = 0;
        title_sprite_start_effect(8, 4);
        gSceneWork.timer = 0;
        gGameSubState = 7;
    } else {
        gSceneWork.timer++;
    }
}

void title_screen_start_wave(void) {
    s32 i;

    if (gSceneWork.timer == 0) {
        play_song(2);
        REG_BLDCNT = 0x244;
        REG_BLDALPHA = 0x1000;
        REG_DISPCNT |= 0x400;
        REG_IE |= 2;
        REG_DISPSTAT |= 0x10;
        gHBlankCallback = title_screen_hblank;
        for (i = 0; i < 160; i++) {
            s32 x;
            if (i < 32) {
                x = i * 4;
                goto div;
            }
            if (i > 0x7F) {
                x = (0x9F - i) * 4;
            div:
                gTitleBg2PaTable[i] = 0x10000u / (0x100 - x);
            } else {
                gTitleBg2PaTable[i] = 0x100;
            }
        }
    } else if (gSceneWork.timer > 0x40) {
        gSpriteEntries[2].flags &= ~SPRITE_FLAG_AFFINE;
        title_sprite_start_effect(5, 2);
        gSceneWork.timer = 0;
        gGameSubState = 8;
        return;
    } else if ((gSceneWork.timer & 7) == 0) {
        REG_BLDALPHA++;
        if ((gSceneWork.timer & 0xF) == 0)
            REG_BLDALPHA -= 0x100;
    }
    if (gSceneWork.timer == 0x39) {
        sprite_entry_init(2, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE, 0x212,
                          2, 3);
        gSpriteEntries[2].x = 0x78;
        gSpriteEntries[2].y = 0x73;
        gSpriteEntries[2].scale_x = 0x40;
        gSpriteEntries[2].scale_y = 8;
        title_sprite_start_effect(4, 2);
    }
    gSceneWork.timer++;
}

void title_screen_wait_start(void) {
    u8 start;
    if ((start = KEYS_LO(gNewKeys) & START_BUTTON) != 0) {
        title_sprite_start_effect(6, 2);
        play_sound_effect(3);
        gSceneWork.timer = 0;
        gGameSubState++;
    } else if (gSceneWork.timer > 0x547) {
        gSceneWork.timer = start;
        clear_sprite_entry(2);
        setup_screen_transition_effect_080684F0(4, 1, 0);
        gSceneWork.nextMode = 3;
        gSceneWork.nextState = start;
        gSceneWork.nextSubState = start;
        gGameSubState = 2;
    } else {
        gSceneWork.timer++;
    }
}

void title_screen_start_pressed(void) {
    if (gSceneWork.timer > 0x28) {
        gSceneWork.timer = 0;
        clear_sprite_entry(2);
        setup_screen_transition_effect_080684F0(4, 1, 0);
        gSceneWork.nextMode = 2;
        gSceneWork.nextState = 3;
        gSceneWork.nextSubState = 0;
        gGameSubState = 2;
    } else {
        gSceneWork.timer++;
    }
}

void title_screen_skip_intro(void) {
    setup_screen_transition_effect_080682CC(4, 2, 0x7FFF);
    REG_BLDY = 0;
    play_song(0);
    sprite_entry_init(0, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1), 0x21B, 4, 3);
    REG_DISPCNT |= 0x300;
    gSpriteEntries[0].x = 0x78;
    gSpriteEntries[0].y = 0x3C;
    gSpriteEntries[0].order = 0x10;
    title_sprite_start_effect(0, 0);
    sprite_entry_init(1, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1), 0x211, 1, 3);
    gSpriteEntries[1].x = 0x78;
    gSpriteEntries[1].y = 0x55;
    gSpriteEntries[1].order = 0x20;
    title_sprite_start_effect(0, 1);
    sprite_entry_init(3, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE, 0x213, 3, 3);
    gSpriteEntries[3].x = 0x12C;
    gSpriteEntries[3].y = 0x55;
    gSpriteEntries[3].order = 0x40;
    gSpriteEntries[3].work16[TITLE_SPR_GLINT_WAIT] = 0x80;
    title_sprite_start_effect(7, 3);
    sprite_entry_init(4, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1), 0x21C, 5, 3);
    gSpriteEntries[4].x = 0x12C;
    gSpriteEntries[4].y = 0x3C;
    gSpriteEntries[4].order = 0x10;
    gSpriteEntries[4].work16[TITLE_SPR_GLINT_WAIT] = 0x80;
    title_sprite_start_effect(8, 4);
    REG_DISPCNT |= 0x1300;
    gSceneWork.nextSubState = 7;
    gSceneWork.timer = 0;
    gGameSubState = 1;
}

void title_screen_update_sprite_effects(void) {
    u8 i;

    for (i = 0; i < 5; i++) {
        if (gSpriteEntries[i].work[TITLE_SPR_EFFECT] != 0) {
            if (++gSpriteEntries[i].timer % gTitleSpriteEffectPeriods[gSpriteEntries[i].work[TITLE_SPR_EFFECT] - 1] ==
                0) {
                switch (gTitleSpriteEffects[gSpriteEntries[i].work[TITLE_SPR_EFFECT] - 1](i)) {
                case 0:
                    gSpriteEntries[i].work[TITLE_SPR_EFFECT] = 0;
                    gSpriteEntries[i].work[TITLE_SPR_STEP] = 0;
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

// Title sprite palette fade-in: copies the title palette (gSceneWork.param, u16[14]) into
// OBJ palette 6 step by step (work[TITLE_SPR_STEP] = step 0..0x1E).
bool32 title_effect_palette_fade_in(u8 idx) {
    u8 n;
    struct SpriteEntry *base = gSpriteEntries;
    struct SpriteEntry *entry = &base[idx];
    u8 fade_step = entry->work[TITLE_SPR_STEP];

    if (entry->work[TITLE_SPR_STEP] > 0x1E)
        return FALSE;
    if (entry->work[TITLE_SPR_STEP] == 0 || entry->work[TITLE_SPR_STEP] == 0x1E) {
        vu32 zero = 0;
        DmaSet(3, &zero, PLTT + 0x2C0, 0x85000000 | (0x20 / 4));
    } else if (entry->work[TITLE_SPR_STEP] <= 0xE) {
        n = fade_step * 2;
        {
            vu32 zero = 0;
            DmaSet(3, &zero, PLTT + 0x2C0, 0x85000000 | ((0x20 - n) / 4));
        }
        DmaSet(3, (u16 *)&gSceneWork.param, PLTT + 0x2E0 - n, 0x80000000 | (n / 2));
    } else if (entry->work[TITLE_SPR_STEP] == 0xF) {
        DmaSet(3, (u16 *)&gSceneWork.param, PLTT + 0x2C0, 0x80000000 | (0x1C / 2));
    } else {
        n = (0x1E - fade_step) * 2;
        {
            vu32 zero = 0;
            DmaSet(3, &zero, PLTT + 0x2C0 + n, 0x85000000 | ((0x20 - n) / 4));
        }
        DmaSet(3, &((u16 *)&gSceneWork.param)[entry->work[TITLE_SPR_STEP] - 15], PLTT + 0x2C0, 0x80000000 | (n / 2));
    }
    gSpriteEntries[idx].work[TITLE_SPR_STEP]++;
    return TRUE;
}

bool32 title_effect_animate_frames(u8 i) {
    if (gSpriteEntries[i].work[TITLE_SPR_STEP] > 15)
        return FALSE;
    if (gSpriteEntries[i].work[TITLE_SPR_STEP] != 0)
        gSpriteEntries[i].frame++;
    gSpriteEntries[i].work[TITLE_SPR_STEP]++;
    return TRUE;
}

bool32 title_effect_slide_left(u8 i) {
    if ((gSpriteEntries[i].x -= 8) <= 0x78)
        return FALSE;
    return TRUE;
}

bool32 title_effect_grow(u8 i) {
    if ((gSpriteEntries[i].scale_y += 8) > 0x3F)
        return FALSE;
    return TRUE;
}

bool32 title_effect_blink(u8 i) {
    if (gSpriteEntries[i].work[TITLE_SPR_STEP] & 1)
        gSpriteEntries[i].y = 0x73;
    else
        gSpriteEntries[i].y = 0xC8;
    gSpriteEntries[i].work[TITLE_SPR_STEP]++;
    return TRUE;
}

bool32 title_effect_glint(u8 i) {
    if (gSpriteEntries[i].work16[TITLE_SPR_GLINT_WAIT] < gSpriteEntries[i].timer) {
        if (gSpriteEntries[i].work[TITLE_SPR_STEP] > 7) {
            gSpriteEntries[i].x = 300;
            gSpriteEntries[i].work[TITLE_SPR_STEP] = 0;
            gSpriteEntries[i].work16[TITLE_SPR_GLINT_WAIT] = (rng_next(0) & 0x1FF) + 0x20;
            gSpriteEntries[i].frame = gSpriteEntries[i].work16[TITLE_SPR_START_FRAME];
            gSpriteEntries[i].timer = 0;
        } else if (gGameSubState == 9 && gSpriteEntries[i].work[TITLE_SPR_STEP] == 0) {
            gSpriteEntries[i].work16[TITLE_SPR_GLINT_WAIT] |= 0xFFFF;
            gSpriteEntries[i].timer = 0;
        } else if (++gSpriteEntries[i].work[TITLE_SPR_STEP] != 1) {
            gSpriteEntries[i].frame++;
        } else {
            gSpriteEntries[i].x = 0x78;
        }
    }
    return TRUE;
}

// Starts effect `effect` (1-based index into gTitleSpriteEffects) on title sprite `sprite`.
static void title_sprite_start_effect(u8 effect, u8 sprite) {
    gSpriteEntries[sprite].work[TITLE_SPR_EFFECT] = effect;
    gSpriteEntries[sprite].work[TITLE_SPR_STEP] = 0;
    gSpriteEntries[sprite].work16[TITLE_SPR_START_FRAME] = gSpriteEntries[sprite].frame;
    gSpriteEntries[sprite].timer = 0;
}
