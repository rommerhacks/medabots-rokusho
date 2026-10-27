// Mode-3 state 1: the opening intro (gIntroSubStates, 19 steps: BG scenes, palette fades, scrolling text,
// sprite animations) before the title screen. intro_update runs it; intro_check_skip lets START jump to the title
// screen.
#include "global.h"

static bool32 sub_0806F850(void);
static bool32 sub_0806F9D4(void);
static void copy_tilemap_rect_to_vram(const u16 *src, u8 bg, u8 w, u8 h, u8 x, u8 y, u16 tile, u8 pal);
static void battle_timer_digit_extract(void);
static void sub_0806FF50(void);
static void sub_0806FF90(void);
static void sub_0806FFF8(void);
static void sub_08070030(void);
static bool32 battle_transition_fade_step(void);
static void battle_sprite_set_action(u8 a, u8 b, u8 c);

static void sub_0806E854(void) {
    if (gUnk_03000430 == 2) {
        u32 v = 0x200;
        DmaSet(3, &v, gSpriteWork->oamBuf, 0x85000100);
        setup_scene_with_bg_and_sprites(0, 0x2A, 0x2A, 0x2A, 0x2A, 0x70, 0x50, gUnk_03000430, 0xC, 0, 1, 0);
        advance_text_display(0, 0x2D, 0x2A);
    }
}

static void intro_check_skip(void) {
    if (KEYS_LO(gHeldKeys) & 8) {
        gTitleSkipIntro = 1;
        gUnk_03000430 = 0;
        gGameMode = 3;
        gGameState = 2;
        gGameSubState = 0;
    }
}

void intro_update(void) {
    sub_0806E854();
    gIntroSubStates[gGameSubState]();
    intro_check_skip();
}

void sub_0806E934(void) {
    if (sub_0806F850()) {
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
}

void sub_0806E968(void) {
    if (sub_0806F9D4()) {
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
}

void scene_fade_out_and_restore_state(void) {
    if (gUnk_03001800_s.timer > 0x4C && gUnk_03001800_s.unkEE >= 0) {
        u8 a = gUnk_03001800_s.unkEE;
        u8 b = 16 - gUnk_03001800_s.unkEE;
        REG_BLDALPHA = a | (b << 8);
        gUnk_03001800_s.unkEE--;
    }
    if (scene_transition_step_080686F4()) {
        REG_DISPCNT &= 0xFBFF;
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
    gUnk_03001800_s.timer++;
}

void scene_animate_and_complete(void) {
    gUnk_03001800_s.unkF0++;
    gUnk_03001800_s.unkF2 += 0x6F;
    battle_timer_digit_extract();
    update_sprite_animations_080703D8();
    if (execute_scene_step()) {
        u32 zero = 0;
        DmaSet(3, &zero, gSpriteEntries, 0x85000800);
        gUnk_03000430 = 0;
        REG_DISPCNT &= 0x80FF;
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
}

void battle_scene_init_clear(void) {
    u32 zero = 0;
    DmaSet(3, &zero, VRAM, 0x85006000);
    zero = 0;
    DmaSet(3, &zero, PLTT, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, gSpriteEntries, 0x85000800);
    zero = 0;
    DmaSet(3, &zero, &gUnk_03001800_s, 0x8500003E);
    REG_DISPCNT = 0x60;
    gUnk_03001800_s.nextMode = 3;
    gUnk_03001800_s.nextState = 1;
    gUnk_03001800_s.timer = 0;
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gUnk_03001800_s.unkC.h = 11;
    gUnk_03001800_s.nextSubState = 11;
    gUnk_03001800_s.unk6 = 1;
    gUnk_03001800_s.unkF4 = 0x7C0;
    gUnk_03001800_s.unkF6 = 0x100;
    gTitleSkipIntro = 0;
    gGameSubState = 8;
}

void load_battle_scene_graphics(void) {
    u16 buf1[0x78];
    u16 buf2[0x190];

    LZ77UnCompVram(gUnk_087BA86C, (void *)VRAM);
    LZ77UnCompVram(gUnk_087C8368, (void *)(VRAM + 0x8020));
    LZ77UnCompVram(gUnk_08485FB8[1], (void *)(VRAM + 0x8C80));
    DmaSet(3, gUnk_087BDC10, PLTT, 0x84000080);
    DmaSet(3, gUnk_087C8818, PLTT, 0x84000008);
    DmaSet(3, gUnk_08485FC8[1], PLTT + 0x20, 0x84000008);
    LZ77UnCompVram(gUnk_087BDE10, (void *)(VRAM + 0x7000));
    LZ77UnCompVram(gUnk_087BE18C, (void *)(VRAM + 0x7800));
    LZ77UnCompVram(gUnk_087C8838, buf1);
    copy_tilemap_rect_to_vram(buf1, 0x1F, 0xA, 0xC, 0, 0, 1, 0);
    LZ77UnCompVram(gUnk_08485FC0[1], buf2);
    copy_tilemap_rect_to_vram(buf2, 0x1E, 0x14, 0x14, 0xA, 0, 0x64, 1);
    REG_BG1CNT = 0xE01;
    REG_BG3CNT = 0xF03;
    REG_BG0CNT = 0x1E08;
    REG_BG2CNT = 0x1F0A;
    DmaSet(3, gUnk_08485FD8[1], PLTT + 0x200, 0x80000050);
    sprite_entry_init(0, 0xC000, 0x40D, 4, 3);
    gSpriteEntries[0].unk2 = 0x98;
    gSpriteEntries[0].unk4 = 0x40;
    setup_screen_transition_effect_080682CC(2, 1, 0);
    gUnk_03000430 = 0;
    gUnk_03001800_s.nextSubState = gUnk_03001800_s.unkC.h;
    gGameSubState = 3;
}

void init_scene_graphics(void) {
    u8 buf[0x50]; // unused, but the original reserves the stack space
    u32 tmp;
    u16 zero;
    s32 i;

    LZ77UnCompVram(gUnk_087BE494, (void *)VRAM);
    LZ77UnCompVram(gUnk_087C88F4, (void *)(VRAM + 0x8020));
    LZ77UnCompVram(gUnk_087C8BD8, (void *)(VRAM + 0x8C80));
    LZ77UnCompVram(gUnk_087C8C94, (void *)(VRAM + 0x9900));
    LZ77UnCompVram(gUnk_087C8CE4, (void *)(VRAM + 0x9A40));
    DmaSet(3, gUnk_087C09C0, PLTT, 0x84000080);
    DmaSet(3, gUnk_087C8CF4, PLTT + 0x100, 0x84000008);
    DmaSet(3, gUnk_087C8D14, PLTT + 0x120, 0x84000008);
    DmaSet(3, gUnk_087C8D34, PLTT, 0x84000008);
    LZ77UnCompVram(gUnk_087C0BC0, (void *)(VRAM + 0x7000));
    LZ77UnCompVram(gUnk_087C0E0C, (void *)(VRAM + 0x7800));
    zero = 0;
    tmp = zero;
    DmaSet(3, &tmp, VRAM + 0xF800, 0x85000200);
    REG_BG1CNT = 0x1F09;
    REG_BG2CNT = 0xE02;
    REG_BG3CNT = 0xF03;
    setup_screen_transition_effect_080682CC(4, 1, 0);
    sprite_entry_init(9, 0xC800, 0x404, 1, 3);
    gSpriteEntries[9].unk2 = 8;
    gSpriteEntries[9].unk4 = 0xA0;
    sprite_entry_init(10, 0xC800, 0x405, 1, 3);
    gSpriteEntries[10].unk2 = zero;
    gSpriteEntries[10].unk4 = 0x90;
    for (i = 0; i <= 2; i++) {
        ((void (*)())sprite_entry_init)(i + 11, 0xC400, i + 0x400, 0, 3);
        gSpriteEntries[i + 11].unk2 = 0xC0;
        gSpriteEntries[i + 11].unk4 = 0xC8;
    }
    for (i = 0; i <= 5; i++) {
        ((void (*)())sprite_entry_init)(i + 3, 0xC400, 0x408, 2, 3);
        gSpriteEntries[i + 3].unk2 = i * 8 + 0xA0;
        gSpriteEntries[i + 3].unk4 = 0xC8;
        gSpriteEntries[i + 3].unkB = 0x20;
    }
    sub_0806FF50();
    sub_0806FF90();
    sub_08070030();
    sub_0806FFF8();
    REG_DISPCNT |= 0x1E00;
    REG_BLDCNT = 0x1844;
    REG_BLDALPHA = 0x80B;
    gUnk_03001800_s.nextSubState = gUnk_03001800_s.unkC.h;
    gGameSubState = 1;
}

void load_battle_ui_assets(void) {
    LZ77UnCompVram(gUnk_08485FD0[1], (void *)0x06010000);
    LZ77UnCompVram(gUnk_087C8D54, gUnk_03001800_s.unk30);
    gGameSubState = 6;
}

void init_battle_result_screen(void) {
    u32 v;
    s32 legs = 0x2A;
    init_scene_buffers_080445F4();
    v = 0x200;
    DmaSet(3, &v, gSpriteWork->oamBuf, 0x85000100);
    setup_scene_with_bg_and_sprites(0, 0x2A, 0x2A, 0x2A, legs, 0x78, 0x50, 2, 0xC, 0, 0, 0);
    DmaSet(3, gUnk_08485FD8[1], PLTT + 0x200, 0x80000050);
    setup_screen_transition_effect_080682CC(2, 4, 0);
    REG_DISPCNT |= 0x1000;
    gUnk_03001800_s.nextSubState = 15;
    gGameSubState = 1;
}

void sub_0806F038(void) {
    load_bg_screen_b();
    REG_MOSAIC = 0xFF;
    gUnk_03001800_s.unk6 = 6;
    gBg0Scroll.y = 0xFFE4;
    DmaSet(3, gUnk_08485FD8[1], PLTT + 0x200, 0x80000050);
    gUnk_03001800_s.nextSubState = gUnk_03001800_s.unkC.h;
    gGameSubState = 4;
}

void sub_0806F094(void) {
    if (battle_transition_fade_step()) {
        gUnk_03001800_s.timer = 0;
        gUnk_03001800_s.nextSubState = 7;
        gUnk_03001800_s.unkC.h = 12;
    }
}

void sub_0806F0B4(void) {
    s32 n = 0xC4;
    s32 i;

    gUnk_03001800_s.unkF0++;
    gUnk_03001800_s.unkF2 += 0x6F;
    if (gUnk_03001800_s.timer < n) {
        switch (gUnk_03001800_s.timer) {
        case 0:
            sprite_entry_init(1, 0xCA00, 0x409, 3, 3);
            gSpriteEntries[1].unk2 = 0x50;
            gSpriteEntries[1].unk4 = 0x38;
            gSpriteEntries[1].unk8 = 2;
            gSpriteEntries[1].unk9 = 2;
            battle_sprite_set_action(1, 1, 0);
            battle_sprite_set_action(4, 9, 0);
            battle_sprite_set_action(5, 10, 0);
            gUnk_03001800_s.timer++;
            break;
        case 1:
            if (gSpriteEntries[1].unk20 == 0)
                gUnk_03001800_s.timer++;
            break;
        case 2:
            sprite_entry_init(2, 0xC600, 0x406, 2, 3);
            gSpriteEntries[2].unk2 = 0xB8;
            gSpriteEntries[2].unk4 = 0x70;
            gSpriteEntries[2].unk8 = 2;
            gSpriteEntries[2].unk9 = 2;
            battle_sprite_set_action(2, 2, 0);
            gUnk_03001800_s.timer++;
            break;
        case 3:
            if (gSpriteEntries[2].unk20 == 0) {
                battle_sprite_set_action(3, 3, 0x70);
                battle_sprite_set_action(3, 4, 0x68);
                battle_sprite_set_action(3, 5, 0x68);
                battle_sprite_set_action(3, 6, 0x70);
                battle_sprite_set_action(3, 7, 0x78);
                battle_sprite_set_action(3, 8, 0x78);
                gUnk_03001800_s.timer++;
            }
            break;
        case 4:
            if (battle_draw_tilemap_row_dma(0))
                gUnk_03001800_s.timer++;
            break;
        default:
            if (check_battle_timer_expired(0))
                process_text_tile_and_dma_transfer(0);
            gUnk_03001800_s.timer++;
            break;
        }
    } else if (gUnk_03001800_s.timer == n) {
        sub_0806FF50();
        sub_0806FF90();
        sub_08070030();
        gSpriteEntries[1].unk4 = 0xC8;
        gSpriteEntries[2].unk4 = 0xC8;
        for (i = 0; i < 3; i++)
            gSpriteEntries[i + 11].unk4 = 0xC8;
        for (i = 0; i < 6; i++) {
            battle_sprite_set_action(0, i + 3, 0);
            gSpriteEntries[i + 3].unk4 = 0xC8;
        }
        gUnk_03001800_s.timer++;
    } else {
        switch (gUnk_03001800_s.timer) {
        case 0xC5:
            gSpriteEntries[1].unk6 = 0x40A;
            gSpriteEntries[1].unk4 = 0x38;
            gSpriteEntries[1].unk8 = 2;
            gSpriteEntries[1].unk9 = 2;
            battle_sprite_set_action(1, 1, 0);
            gUnk_03001800_s.timer++;
            break;
        case 0xC6:
            if (gSpriteEntries[1].unk20 == 0)
                gUnk_03001800_s.timer++;
            break;
        case 0xC7:
            gSpriteEntries[2].unk6 = 0x407;
            gSpriteEntries[2].unk4 = 0x70;
            gSpriteEntries[2].unk8 = 2;
            gSpriteEntries[2].unk9 = 2;
            battle_sprite_set_action(2, 2, 0);
            gUnk_03001800_s.timer++;
            break;
        case 0xC8:
            if (gSpriteEntries[2].unk20 == 0) {
                battle_sprite_set_action(3, 3, 0x78);
                battle_sprite_set_action(3, 4, 0x70);
                battle_sprite_set_action(3, 5, 0x78);
                battle_sprite_set_action(3, 6, 0x70);
                battle_sprite_set_action(3, 7, 0x68);
                battle_sprite_set_action(3, 8, 0x70);
                gUnk_03001800_s.timer++;
            }
            break;
        case 0xC9:
            if (battle_draw_tilemap_row_dma(1))
                gUnk_03001800_s.timer++;
            break;
        default:
            if (check_battle_timer_expired(0x28))
                process_text_tile_and_dma_transfer(1);
            gUnk_03001800_s.timer++;
            break;
        }
    }
    battle_timer_digit_extract();
    update_sprite_animations_080703D8();
    if (n * 2 <= gUnk_03001800_s.timer) {
        gUnk_03001800_s.timer = 0;
        gUnk_03001800_s.nextSubState = 6;
        gUnk_03001800_s.unkC.h = 13;
        gGameSubState = 2;
    }
}

void sub_0806F3F0(void) {
    if (battle_transition_fade_step()) {
        sub_0806FF50();
        sub_0806FF90();
        gUnk_03001800_s.timer = 0;
        gUnk_03001800_s.nextSubState = 7;
        gUnk_03001800_s.unkC.h = 0xE;
    }
}

void sub_0806F418(void) {
    s32 n = 0xC4;
    s32 i;

    gUnk_03001800_s.unkF0++;
    gUnk_03001800_s.unkF2 += 0x6F;
    if (gUnk_03001800_s.timer < n) {
        switch (gUnk_03001800_s.timer) {
        case 0:
            sprite_entry_init(1, 0xCA00, 0x40B, 3, 3);
            gSpriteEntries[1].unk2 = 0x50;
            gSpriteEntries[1].unk4 = 0x38;
            gSpriteEntries[1].unk8 = 2;
            gSpriteEntries[1].unk9 = 2;
            battle_sprite_set_action(1, 1, 0);
            battle_sprite_set_action(4, 9, 0);
            battle_sprite_set_action(5, 10, 0);
            gUnk_03001800_s.timer++;
            break;
        case 1:
            if (gSpriteEntries[1].unk20 == 0)
                gUnk_03001800_s.timer++;
            break;
        case 2:
            sprite_entry_init(2, 0xC600, 0x406, 2, 3);
            gSpriteEntries[2].unk2 = 0xB8;
            gSpriteEntries[2].unk4 = 0x70;
            gSpriteEntries[2].unk8 = 2;
            gSpriteEntries[2].unk9 = 2;
            battle_sprite_set_action(2, 2, 0);
            gUnk_03001800_s.timer++;
            break;
        case 3:
            if (gSpriteEntries[2].unk20 == 0) {
                battle_sprite_set_action(3, 3, 0x70);
                battle_sprite_set_action(3, 4, 0x68);
                battle_sprite_set_action(3, 5, 0x68);
                battle_sprite_set_action(3, 6, 0x70);
                battle_sprite_set_action(3, 7, 0x78);
                battle_sprite_set_action(3, 8, 0x78);
                gUnk_03001800_s.timer++;
            }
            break;
        case 4:
            if (battle_draw_tilemap_row_dma(2))
                gUnk_03001800_s.timer++;
            break;
        default:
            if (check_battle_timer_expired(0x28))
                process_text_tile_and_dma_transfer(2);
            gUnk_03001800_s.timer++;
            break;
        }
    } else if (gUnk_03001800_s.timer == n) {
        sub_0806FF50();
        sub_0806FF90();
        sub_08070030();
        gSpriteEntries[1].unk4 = 200;
        gSpriteEntries[2].unk4 = 200;
        for (i = 0; i < 3; i++)
            gSpriteEntries[i + 11].unk4 = 200;
        for (i = 0; i < 6; i++) {
            battle_sprite_set_action(0, i + 3, 0);
            gSpriteEntries[i + 3].unk4 = 200;
        }
        gUnk_03001800_s.timer++;
    } else {
        switch (gUnk_03001800_s.timer) {
        case 0xC5:
            gSpriteEntries[1].unk6 = 0x40C;
            gSpriteEntries[1].unk4 = 0x38;
            gSpriteEntries[1].unk8 = 2;
            gSpriteEntries[1].unk9 = 2;
            battle_sprite_set_action(1, 1, 0);
            gUnk_03001800_s.timer++;
            break;
        case 0xC6:
            if (gSpriteEntries[1].unk20 == 0)
                gUnk_03001800_s.timer++;
            break;
        case 0xC7:
            gSpriteEntries[2].unk6 = 0x407;
            gSpriteEntries[2].unk4 = 0x70;
            gSpriteEntries[2].unk8 = 2;
            gSpriteEntries[2].unk9 = 2;
            battle_sprite_set_action(2, 2, 0);
            gUnk_03001800_s.timer++;
            break;
        case 0xC8:
            if (gSpriteEntries[2].unk20 == 0) {
                battle_sprite_set_action(3, 3, 0x78);
                battle_sprite_set_action(3, 4, 0x70);
                battle_sprite_set_action(3, 5, 0x78);
                battle_sprite_set_action(3, 6, 0x70);
                battle_sprite_set_action(3, 7, 0x68);
                battle_sprite_set_action(3, 8, 0x70);
                gUnk_03001800_s.timer++;
            }
            break;
        case 0xC9:
            if (battle_draw_tilemap_row_dma(3))
                gUnk_03001800_s.timer++;
            break;
        default:
            if (check_battle_timer_expired(0))
                process_text_tile_and_dma_transfer(3);
            gUnk_03001800_s.timer++;
            break;
        }
    }
    battle_timer_digit_extract();
    update_sprite_animations_080703D8();
    if (n * 2 <= gUnk_03001800_s.timer) {
        gUnk_03001800_s.timer = 0;
        gUnk_03001800_s.nextSubState = 9;
        gGameSubState = 2;
    }
}

// Story intro sub-state (gUnk_08485F1C entry 34); only reached through that table.
void sub_0806F750(void) {
    gUnk_03001800_s.unkF4 += 0x10;
    gUnk_03001800_s.unkF6 -= 0x10;
    if (gUnk_03001800_s.timer++ > 0x3A) {
        gUnk_03001800_s.timer = 0;
        gUnk_03001800_s.nextSubState = 6;
        gUnk_03001800_s.unkC.h = 0x10;
        gGameSubState = 2;
    }
}

void sub_0806F78C(void) {
    if (battle_transition_fade_step()) {
        gUnk_03001800_s.timer = 0;
        gUnk_03001800_s.nextSubState = 0xA;
        gUnk_03001800_s.unkC.h = 0x11;
    }
}

void sub_0806F7AC(void) {
    s32 n = 0x3C;

    if (n == gUnk_03001800_s.timer) {
        REG_BLDCNT = 0xBF;
        REG_BLDY = 0x10;
        load_bg_screen_c();
        setup_screen_transition_effect_080682CC(4, 4, 0x7FFF);
        REG_BLDY = 0;
        gUnk_03001800_s.nextSubState = gGameSubState;
        gGameSubState = 1;
    } else if (n < gUnk_03001800_s.timer) {
        gUnk_03001800_s.timer = 0;
        gUnk_03001800_s.nextSubState = 0x12;
        setup_screen_transition_effect_080684F0(4, 4, 0);
        gGameSubState = 2;
        return;
    }
    gUnk_03001800_s.timer++;
}

// Story intro sub-state (gUnk_08485F1C entry 37); only reached through that table.
void sub_0806F830(void) {
    gGameMode = 3;
    gGameState = 2;
    gGameSubState = 0;
}

// View of 0x03001800 (gUnk_03001800_s) for the battle-intro palette fades of code_0806F3F0:
// unkE holds a saved copy of OBJ palette 4 (0x05000280, 16 colours).
struct Unk_03001800_fade {
    u16 nextMode;
    u16 nextState;
    u16 nextSubState;
    u16 unk6; // fade step length (frames)
    s32 timer;
    u16 unkC;
    u16 unkE[16]; // saved palette (PLTT + 0x280)
};
#define gUnk_03001800_fade (*(struct Unk_03001800_fade *)&gUnk_03001800_s)

// guess: fade OBJ palette 4 in from black (blend towards `zero` colour, which folds away), BLDY fading out.
static bool32 sub_0806F850(void) {
    u16 buf[16];
    vs32 inv;
    s32 zero;
    s32 i;
    s32 k;
    u16 d;

    zero = 0;
    if (gUnk_03001800_fade.timer == 0) {
        DmaSet(3, PLTT + 0x280, gUnk_03001800_fade.unkE, 0x80000010);
        for (i = 0; i < 16; i++)
            buf[i] = zero;
        DmaSet(3, buf, PLTT + 0x280, 0x84000008);
        REG_BLDCNT &= 0xFFEF;
        REG_DISPCNT |= 0x1B00;
        if (gUnk_03001800_fade.unk6 == 0)
            gUnk_03001800_fade.unk6 = 1;
    } else if (gUnk_03001800_fade.timer == gUnk_03001800_fade.unk6 * 32) {
        gUnk_03001800_fade.timer = zero;
        DmaSet(3, gUnk_03001800_fade.unkE, PLTT + 0x280, 0x80000010);
        return TRUE;
    } else if (gUnk_03001800_fade.timer % gUnk_03001800_fade.unk6 == 0) {
        k = gUnk_03001800_fade.timer / gUnk_03001800_fade.unk6;
        inv = 0x20 - k;
        for (i = 0; i < 16; i++)
            buf[i] = (((gUnk_03001800_fade.unkE[i] & 0x1F) * k + (zero & 0x1F) * (0x20 - k)) >> 5) +
                     ((((gUnk_03001800_fade.unkE[i] & 0x3E0) * k + (zero & 0x3E0) * (0x20 - k)) >> 5) & 0x3E0) +
                     ((((gUnk_03001800_fade.unkE[i] & 0x7C00) * k + (zero & 0x7C00) * (0x20 - k)) >> 5) & 0x7C00);
        DmaSet(3, buf, PLTT + 0x280, 0x84000008);
        d = gUnk_03001800_fade.unk6;
        if (gUnk_03001800_fade.timer % (d * 2) == (zero & 0x1F))
            REG_BLDY = 16 - gUnk_03001800_fade.timer / (d * 4);
    }
    gUnk_03001800_fade.timer++;
    return FALSE;
}

static bool32 sub_0806F9D4(void) {
    u16 div = gUnk_03001800_s.unk6;
    s32 t = gUnk_03001800_s.timer;
    u8 v;

    if (t % div == 0) {
        v = 16 - t / div;
        REG_BLDY = v;
        REG_MOSAIC = (v & 0xF) | ((v & 0xF) << 4);
        if (v == 0) {
            gUnk_03001800_s.timer = v;
            return TRUE;
        }
    }
    gUnk_03001800_s.timer++;
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

u32 process_text_tile_and_dma_transfer(u8 a) {
    const u8 *s = gUnk_0848602C[a + 4];
    u8 c;

    s += gUnk_03001800_s.unkD0;
    if (gUnk_03001800_s.timer & 1) {
        if (*s == 0x14)
            return 1;
        return 0;
    }
    if (*s == 0x14) {
        if (gUnk_03001800_s.timer & 8)
            gUnk_03001800_s.unkD2[gUnk_03001800_s.unkD0] = 0;
        else
            gUnk_03001800_s.unkD2[gUnk_03001800_s.unkD0] = 0x9078;
        DmaSet(3, gUnk_03001800_s.unkD2, 0x0600FC44, 0x8000000D);
        return 1;
    }
    c = *s;
    if (c == 0x15)
        gUnk_03001800_s.unkD2[gUnk_03001800_s.unkD0] = 0;
    else
        gUnk_03001800_s.unkD2[gUnk_03001800_s.unkD0] = c + 0x9064;
    gUnk_03001800_s.unkD0++;
    DmaSet(3, gUnk_03001800_s.unkD2, 0x0600FC44, 0x8000000D);
    return 0;
}

u32 check_battle_timer_expired(u8 a) {
    u16 v;
    register u8 n asm("r8") = gUnk_03001800_s.unk2E;

    if (n > 39)
        return 1;
    if (!(gUnk_03001800_s.timer & 1)) {
        u8 k = *(vu8 *)&gUnk_03001800_s.unk2E;
        u32 off = (u8)(k / 10) * 64 + (u8)(k % 10) * 2;
        v = gUnk_03001800_s.unk30[k + a] + 0x8001;
        DmaSet(3, &v, 0x0600FB0A + off, 0x80000001);
        gUnk_03001800_s.unk2E = n + 1;
    }
    return 0;
}

static void battle_timer_digit_extract(void) {
    u16 buf[8];
    u16 a = gUnk_03001800_s.unkF0;
    u16 b = gUnk_03001800_s.unkF2 % 1000;
    u16 t;

    buf[3] = a % 10 + 0x90C8;
    t = a / 10;
    buf[1] = t % 10 + 0x90C8;
    t /= 10;
    buf[0] = t % 10 + 0x90C8;
    buf[2] = 0;
    buf[6] = b % 10 + 0x90C8;
    t = b / 10;
    buf[5] = t % 10 + 0x90C8;
    t /= 10;
    buf[4] = t % 10 + 0x90C8;
    DmaSet(3, buf, 0x0600F86C, 0x80000007);
}

#define ROW_ENT(k) gUnk_0848604C[gUnk_03001800_s.unkED * 4 + a * 12 + 0x30 + (k)]

u32 battle_draw_tilemap_row_dma(u8 a) {
    u16 tile = 0xD2;
    s32 slot;
    s32 pos;
    s32 k = 14;

    if (gUnk_03001800_s.unkED > 2)
        return 1;
    if (ROW_ENT(2) <= ROW_ENT(0) + gUnk_03001800_s.unkEC) {
        gSpriteEntries[gUnk_03001800_s.unkED + 11].unk4 = ROW_ENT(3) * 8;
        gUnk_03001800_s.unkEC = 0;
        gUnk_03001800_s.unkED++;
        return 0;
    }
    if (gUnk_03001800_s.unkEC <= 1) {
        if (ROW_ENT(3) + gUnk_03001800_s.unkEC < ROW_ENT(1)) {
            slot = gUnk_03001800_s.unkED * 2 + (gUnk_03001800_s.unkEC + k);
            ((void (*)())sprite_entry_init)(slot, 0xC400, 0x403, 0, 3);
            gSpriteEntries[slot].unk2 = (ROW_ENT(0) + gUnk_03001800_s.unkEC) * 8;
            gSpriteEntries[slot].unk4 = (ROW_ENT(1) - gUnk_03001800_s.unkEC) * 8 - 4;
        } else if (ROW_ENT(1) + gUnk_03001800_s.unkEC < ROW_ENT(3)) {
            slot = gUnk_03001800_s.unkED * 2 + (gUnk_03001800_s.unkEC + k);
            ((void (*)())sprite_entry_init)(slot, 0xE400, 0x403, 0, 3);
            gSpriteEntries[slot].unk2 = (ROW_ENT(0) + gUnk_03001800_s.unkEC) * 8;
            gSpriteEntries[slot].unk4 = (ROW_ENT(1) + gUnk_03001800_s.unkEC) * 8 + 12;
        } else {
            pos = gUnk_03001800_s.unkEC + (ROW_ENT(0) + ROW_ENT(3) * 32);
            DmaSet(3, &tile, (u16 *)0x0600F800 + pos, 0x80000001);
        }
    } else {
        pos = gUnk_03001800_s.unkEC + (ROW_ENT(0) + ROW_ENT(3) * 32);
        DmaSet(3, &tile, (u16 *)0x0600F800 + pos, 0x80000001);
    }
    gUnk_03001800_s.unkEC++;
    return 0;
}

#undef ROW_ENT

static void sub_0806FF50(void) {
    s32 i;

    for (i = 0; i < 13; i++)
        gUnk_03001800_s.unkD2[i] = 0;
    gUnk_03001800_s.unkD0 = 0;
    DmaSet(3, gUnk_03001800_s.unkD2, 0x0600FC44, 0x8000000D);
}

static void sub_0806FF90(void) {
    vu16 v;

    v = 0;
    DmaSet(3, &v, 0x0600FB0A, 0x8100000A);
    v = 0;
    DmaSet(3, &v, 0x0600FB4A, 0x8100000A);
    v = 0;
    DmaSet(3, &v, 0x0600FB8A, 0x8100000A);
    v = 0;
    DmaSet(3, &v, 0x0600FBCA, 0x8100000A);
    gUnk_03001800_s.unk2E = 0;
}

static void sub_0806FFF8(void) {
    u16 v;

    gUnk_03001800_s.unkF2 = 0;
    gUnk_03001800_s.unkF0 = 0;
    v = 0;
    DmaSet(3, &v, 0x0600F86C, 0x81000007);
}

static void sub_08070030(void) {
    u32 v;
    s32 i;

    gUnk_03001800_s.unkEC = 0;
    gUnk_03001800_s.unkED = 0;
    v = 0;
    DmaSet(3, &v, 0x0600F800, 0x850000A0);
    for (i = 0; i < 6; i++)
        gSpriteEntries[i + 0xE].unk4 = 0xC8;
}

static bool32 battle_transition_fade_step(void) {
    if (gUnk_03001800_s.timer == 0x3C) {
        setup_screen_transition_effect_080682CC(4, 1, 0x7FFF);
        REG_BLDCNT = 0x844;
        REG_BLDALPHA = 0x10;
        REG_BLDY = 0;
        REG_DISPCNT |= 0x400;
        gUnk_03001800_s.nextSubState = gGameSubState;
        gUnk_03001800_s.unkEE = 0x10;
        gGameSubState = 5;
    } else if (gUnk_03001800_s.timer > 0x3C) {
        setup_screen_transition_effect_080684F0(2, 2, 0);
        gGameSubState = 2;
        return TRUE;
    }
    gUnk_03001800_s.timer++;
    return FALSE;
}

void load_bg_screen_a(void) {
    u16 dst[0x280];
    u16 src[0x258];
    vu32 zero;
    s32 i, j;

    LZ77UnCompVram(gUnk_087C8E00, (void *)VRAM);
    LZ77UnCompVram(gUnk_087CC7BC, src);
    zero = 0;
    DmaSet(3, &zero, VRAM + 0x7800, 0x85000200);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            dst[i * 32 + j] = src[i * 30 + j];
        dst[i * 32 + 30] = dst[i * 32 + 31] = 0;
    }
    DmaSet(3, dst, VRAM + 0x7800, 0x80000280);
    DmaSet(3, gUnk_087CCAEC, PLTT, 0x80000100);
    REG_BG0CNT = 0xFC0;
    REG_DISPCNT |= 0x100;
}

void load_bg_screen_b(void) {
    u16 dst[0x280];
    u16 src[0x258];
    vu32 zero;
    s32 i, j;

    LZ77UnCompVram(gUnk_087CCCEC, (void *)VRAM);
    LZ77UnCompVram(gUnk_087D0954, src);
    zero = 0;
    DmaSet(3, &zero, VRAM + 0x7800, 0x85000200);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            dst[i * 32 + j] = src[i * 30 + j];
        dst[i * 32 + 30] = dst[i * 32 + 31] = 0;
    }
    DmaSet(3, dst, VRAM + 0x7800, 0x80000280);
    DmaSet(3, gUnk_087D0C80, PLTT, 0x80000100);
    REG_BG0CNT = 0xFC0;
    REG_DISPCNT |= 0x100;
}

void load_bg_screen_c(void) {
    u16 dst[0x280];
    u16 src[0x258];
    vu32 zero;
    s32 i, j;

    LZ77UnCompVram(gUnk_087D0E80, (void *)VRAM);
    LZ77UnCompVram(gUnk_087D424C, src);
    zero = 0;
    DmaSet(3, &zero, VRAM + 0x7800, 0x85000200);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            dst[i * 32 + j] = src[i * 30 + j];
        dst[i * 32 + 30] = dst[i * 32 + 31] = 0;
    }
    DmaSet(3, dst, VRAM + 0x7800, 0x80000280);
    DmaSet(3, gUnk_087D4564, PLTT, 0x80000100);
    REG_BG0CNT = 0xF80;
    REG_DISPCNT |= 0x100;
}

void update_sprite_animations_080703D8(void) {
    u8 i;

    for (i = 0; i <= 10; i++) {
        struct SpriteEntry *base = gSpriteEntries;
        struct SpriteEntry *s = &base[i];

        if (s->unk20 != 0) {
            if (++s->unk1A % gUnk_084860C0[s->unk20 - 1] == 0) {
                switch (gUnk_084860AC[s->unk20 - 1](i)) {
                case 0:
                    s->unk20 = 0;
                    s->unk21 = 0;
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

s32 sub_08070468(u8 i) {
    if (gSpriteEntries[i].unk8 > 0x3F && gSpriteEntries[i].unk9 > 0x3F)
        return 0;
    if (gSpriteEntries[i].unk9 <= 0x3F) {
        if ((gSpriteEntries[i].unk9 += 8) > 0x40)
            gSpriteEntries[i].unk9 = 0x40;
    } else {
        if ((gSpriteEntries[i].unk8 += 8) > 0x40)
            gSpriteEntries[i].unk8 = 0x40;
    }
    gSpriteEntries[i].unk21++;
    return 1;
}

s32 sub_080704D0(u8 i) {
    if (gSpriteEntries[i].unk8 > 0x3F && gSpriteEntries[i].unk9 > 0x3F)
        return 0;
    if (gSpriteEntries[i].unk8 <= 0x3F) {
        if ((gSpriteEntries[i].unk8 += 8) > 0x40)
            gSpriteEntries[i].unk8 = 0x40;
    } else {
        if ((gSpriteEntries[i].unk9 += 8) > 0x40)
            gSpriteEntries[i].unk9 = 0x40;
    }
    gSpriteEntries[i].unk21++;
    return 1;
}

s32 sub_0807052C(u8 i) {
    if (i & 1)
        gSpriteEntries[i].unk4 = gSpriteEntries[i].unk23 - gUnk_080AFF50[gSpriteEntries[i].unk21 & 0x3F];
    else
        gSpriteEntries[i].unk4 = gSpriteEntries[i].unk23 + gUnk_080AFF50[gSpriteEntries[i].unk21 & 0x3F];
    gSpriteEntries[i].unk21 += 1 + gSpriteEntries[i].unk22;
    return 1;
}

s32 sub_080705BC(u8 i) {
    if (gSpriteEntries[i].unk21 < 0x48) {
        gSpriteEntries[i].unk21++;
    } else if (gSpriteEntries[i].unk4 < -0x50) {
        gSpriteEntries[i].unk4 = 0xA0;
        gSpriteEntries[i].unk21 = 0;
    } else {
        gSpriteEntries[i].unk4 -= 4;
    }
    return 1;
}

s32 sub_08070600(u8 i) {
    if (gSpriteEntries[i].unk21 < 0x48) {
        gSpriteEntries[i].unk21++;
    } else if (gSpriteEntries[i].unk2 > 0x168) {
        gSpriteEntries[i].unk2 = 0;
        gSpriteEntries[i].unk21 = 0;
    } else {
        gSpriteEntries[i].unk2 += 6;
    }
    return 1;
}

static void battle_sprite_set_action(u8 action, u8 i, u8 y) {
    struct SpriteEntry *base = gSpriteEntries;
    struct SpriteEntry *s = &base[i];

    s->unk20 = action;
    s->unk21 = 0;
    if (y != 0) {
        s->unk22 = rng_next(0) & 3;
        s->unk23 = y - 4;
    }
    s->unk30 = s->unk6;
    s->unk1A = 0;
}
