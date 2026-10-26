// Mode-3 state 2: the title screen. sub_0806D3F4 runs gUnk_08485EC4 with a BG2 per-scanline wave (HBlank
// handler sub_0806D420). START goes to the title menu (mode 2 state 3), SELECT+START to the test mode
// (mode 2 state 7); after a timeout it loops back to the boot logos (mode 3 state 0).
#include "global.h"

static void sub_0806DF80(u8 anim, u8 sprite);

void set_bot_y_positions_by_count(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        s16 y = 0xC8;
        if (i < gUnk_03002C30[30].unk20)
            y = 0x78;
        gUnk_03002C30[13 + i].unk4 = y;
    }
}

static void sub_0806D288(void) {
    if (gUnk_03001800_s.nextSubState == 5 && ((KEYS_LO(gHeldKeys) & 8) || gUnk_03007008 != 0)) {
        gUnk_03007008 = 0;
        gGameMode = 3;
        gGameState = 2;
        gGameSubState = 10;
    } else if ((KEYS_LO(gHeldKeys) & 4) && (KEYS_LO(gNewKeys) & 8)) {
        gGameMode = 2;
        gGameState = 7;
        gGameSubState = 0;
    }
}

static inline s32 mul120(u16 x) {
    return x * 120;
}

static inline s32 sub_counter(void) {
    return 0x7800 - gUnk_030003F0;
}

// Builds the per-scanline BG2 PA / X tables read by the HBlank handler sub_0806D420:
// lines 0-31 and 128-159 get X = 0x7800 -+ counter - PA * 120, lines 32-127 X = 0.
// Builds the BG2 PA / X tables read by the HBlank handler sub_0806D420 (rows 32-127 get X = 0).
void update_bg2_affine_scanline_params(void) {
    s32 i;
    s32 x;
    s32 c;

    gUnk_030003F0 += 0x80;
    for (i = 0; i < 32; i++) {
        x = sub_counter() - mul120(gUnk_03000030[i]);
        gUnk_03000170[i] = x;
        gUnk_030002B0[i] = x >> 16;
    }
    for (; i < 128; i++) {
        gUnk_03000170[i] = 0;
        gUnk_030002B0[i] = 0;
    }
    for (; i < 160; i++) {
        c = gUnk_030003F0 + 0x7800;
        x = c - mul120(gUnk_03000030[i]);
        gUnk_03000170[i] = x;
        gUnk_030002B0[i] = x >> 16;
    }
    REG_BG2PA = gUnk_03000030[0];
    REG_BG2X_L = gUnk_03000170[0];
    REG_BG2X_H = gUnk_030002B0[0];
}

void sub_0806D3F4(void) {
    update_bg2_affine_scanline_params();
    gUnk_08485EC4[gGameSubState]();
    update_sprite_special_effects();
    sub_0806D288();
}

// HBlank: sets the next scanline's BG2 PA and X from the tables built by update_bg2_affine_scanline_params.
// VCOUNT is read through a non-volatile pointer: the compare's load is reused for the first index.
void sub_0806D420(void) {
    if (*(u8 *)REG_ADDR_VCOUNT < 159) {
        REG_BG2PA = gUnk_03000030[*(u8 *)REG_ADDR_VCOUNT + 1];
        REG_BG2X_L = gUnk_03000170[*(u8 *)REG_ADDR_VCOUNT + 1];
        REG_BG2X_H = gUnk_030002B0[*(u8 *)REG_ADDR_VCOUNT + 1];
    }
}

void teardown_scene_and_restore_state(void) {
    if (execute_scene_step()) {
        u32 zero = 0;
        DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
        REG_DISPCNT &= 0x80FF;
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
        REG_DISPCNT &= ~0x0400;
        REG_IE &= ~2;
        REG_DISPSTAT &= ~0x10;
        gHBlankCallback = nullsub_08000840;
        play_song(0);
    }
}

void sub_0806D518(void) {
    if (gUnk_03001800_s.unk6 < ++gUnk_03001800_s.timer) {
        gUnk_03001800_s.timer = 0;
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
}

// Title screen sub-state 0: clears the screen and the scene struct, then sub-state 4 (load_scene_graphics).
void sub_0806D550(void) {
    u32 zero = 0;
    DmaSet(3, &zero, VRAM, 0x85006000);
    zero = 0;
    DmaSet(3, &zero, PLTT, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
    zero = 0;
    DmaSet(3, &zero, &gUnk_03001800_s, 0x8500000B);
    REG_DISPCNT = 0x61;
    gUnk_03001800_s.nextMode = 3;
    gUnk_03001800_s.nextState = 2;
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

void load_scene_graphics(void) {
    LZ77UnCompVram(gUnk_087B55BC, (void *)VRAM);
    DmaSet(3, gUnk_087B9B6C, VRAM + 0x8000, 0x84000090);
    DmaSet(3, gUnk_087B9DAC, PLTT, 0x84000030);
    LZ77UnCompVram(gUnk_087B9E6C, (void *)(VRAM + 0x6800));
    LZ77UnCompVram(gUnk_087BA0AC, (void *)(VRAM + 0x7000));
    DmaSet(3, gUnk_087BA5EC, VRAM + 0x7800, 0x840000A0);
    REG_BG0CNT = 0xD01;
    REG_BG1CNT = 0xE03;
    REG_BG2CNT = 0x6F8A;
    LZ77UnCompVram(gUnk_087ADDDC, (void *)(VRAM + 0x10000));
    DmaSet(3, gUnk_0807C320, PLTT + 0x200, 0x80000060);
    DmaSet(3, gUnk_0807C320 + 0x60, &gUnk_03001800_s.unkC, 0x8000000E);
    setup_screen_transition_effect_080682CC(2, 1, 0);
    gUnk_03001800_s.nextSubState = 5;
    gGameSubState = 1;
}

void battle_transition_animate_step(void) {
    if (gUnk_03001800_s.timer == 0) {
        init_battle_sprite_entry_08048818(0, 0xCC00, 0x224, 6, 3);
        gUnk_03002C30[0].unk2 = 0x78;
        gUnk_03002C30[0].unk4 = 0x3C;
        gUnk_03002C30[0].unkB = 0x10;
        sub_0806DF80(1, 0);
        REG_DISPCNT |= 0x1000;
    } else if (gUnk_03001800_s.timer == 0x20) {
        init_battle_sprite_entry_08048818(1, 0xC400, 0x200, 0, 3);
        gUnk_03002C30[1].unk2 = 0x78;
        gUnk_03002C30[1].unk4 = 0x3C;
        gUnk_03002C30[1].unkB = 0x20;
        sub_0806DF80(2, 1);
    }
    if (gUnk_03002C30[0].unk20 == 0) {
        gUnk_03001800_s.nextSubState = 6;
        gUnk_03001800_s.timer = 0;
        setup_screen_transition_effect_080682CC(4, 4, 0x7FFF);
        clear_sprite_entry(1);
        init_battle_sprite_entry_08048818(0, 0xC400, 0x21B, 4, 3);
        REG_DISPCNT |= 0x300;
        gGameSubState = 1;
    } else {
        gUnk_03001800_s.timer++;
    }
}

void battle_scene_intro_step(void) {
    if (gUnk_03001800_s.timer == 0) {
        play_song(0);
        init_battle_sprite_entry_08048818(1, 0xC400, 0x211, 1, 3);
        gUnk_03002C30[1].unk2 = 0x118;
        gUnk_03002C30[1].unk4 = 0x55;
        gUnk_03002C30[1].unkB = 0x20;
        sub_0806DF80(3, 1);
    }
    if (gUnk_03002C30[1].unk20 == 0) {
        init_battle_sprite_entry_08048818(3, 0xC000, 0x213, 3, 3);
        gUnk_03002C30[3].unk2 = 0x12C;
        gUnk_03002C30[3].unk4 = 0x55;
        gUnk_03002C30[3].unkB = 0x40;
        gUnk_03002C30[3].unk32 = 0;
        sub_0806DF80(7, 3);
        init_battle_sprite_entry_08048818(4, 0xC400, 0x21C, 5, 3);
        gUnk_03002C30[4].unk2 = 0x12C;
        gUnk_03002C30[4].unk4 = 0x3C;
        gUnk_03002C30[4].unkB = 0x10;
        gUnk_03002C30[4].unk32 = 0;
        sub_0806DF80(8, 4);
        gUnk_03001800_s.timer = 0;
        gGameSubState = 7;
    } else {
        gUnk_03001800_s.timer++;
    }
}

void battle_transition_wipe_effect(void) {
    s32 i;

    if (gUnk_03001800_s.timer == 0) {
        play_song(2);
        REG_BLDCNT = 0x244;
        REG_BLDALPHA = 0x1000;
        REG_DISPCNT |= 0x400;
        REG_IE |= 2;
        REG_DISPSTAT |= 0x10;
        gHBlankCallback = sub_0806D420;
        for (i = 0; i < 160; i++) {
            s32 x;
            if (i < 32) {
                x = i * 4;
                goto div;
            }
            if (i > 0x7F) {
                x = (0x9F - i) * 4;
            div:
                gUnk_03000030[i] = 0x10000u / (0x100 - x);
            } else {
                gUnk_03000030[i] = 0x100;
            }
        }
    } else if (gUnk_03001800_s.timer > 0x40) {
        gUnk_03002C30[2].unk0 &= ~0x200;
        sub_0806DF80(5, 2);
        gUnk_03001800_s.timer = 0;
        gGameSubState = 8;
        return;
    } else if ((gUnk_03001800_s.timer & 7) == 0) {
        REG_BLDALPHA++;
        if ((gUnk_03001800_s.timer & 0xF) == 0)
            REG_BLDALPHA -= 0x100;
    }
    if (gUnk_03001800_s.timer == 0x39) {
        init_battle_sprite_entry_08048818(2, 0xC600, 0x212, 2, 3);
        gUnk_03002C30[2].unk2 = 0x78;
        gUnk_03002C30[2].unk4 = 0x73;
        gUnk_03002C30[2].unk8 = 0x40;
        gUnk_03002C30[2].unk9 = 8;
        sub_0806DF80(4, 2);
    }
    gUnk_03001800_s.timer++;
}

void battle_intro_countdown_tick(void) {
    u8 start;
    if ((start = KEYS_LO(gNewKeys) & 8) != 0) {
        sub_0806DF80(6, 2);
        play_sound_effect(3);
        gUnk_03001800_s.timer = 0;
        gGameSubState++;
    } else if (gUnk_03001800_s.timer > 0x547) {
        gUnk_03001800_s.timer = start;
        clear_sprite_entry(2);
        setup_screen_transition_effect_080684F0(4, 1, 0);
        gUnk_03001800_s.nextMode = 3;
        gUnk_03001800_s.nextState = start;
        gUnk_03001800_s.nextSubState = start;
        gGameSubState = 2;
    } else {
        gUnk_03001800_s.timer++;
    }
}

void sub_0806DAEC(void) {
    if (gUnk_03001800_s.timer > 0x28) {
        gUnk_03001800_s.timer = 0;
        clear_sprite_entry(2);
        setup_screen_transition_effect_080684F0(4, 1, 0);
        gUnk_03001800_s.nextMode = 2;
        gUnk_03001800_s.nextState = 3;
        gUnk_03001800_s.nextSubState = 0;
        gGameSubState = 2;
    } else {
        gUnk_03001800_s.timer++;
    }
}

void sub_0806DB30(void) {
    setup_screen_transition_effect_080682CC(4, 2, 0x7FFF);
    REG_BLDY = 0;
    play_song(0);
    init_battle_sprite_entry_08048818(0, 0xC400, 0x21B, 4, 3);
    REG_DISPCNT |= 0x300;
    gUnk_03002C30[0].unk2 = 0x78;
    gUnk_03002C30[0].unk4 = 0x3C;
    gUnk_03002C30[0].unkB = 0x10;
    sub_0806DF80(0, 0);
    init_battle_sprite_entry_08048818(1, 0xC400, 0x211, 1, 3);
    gUnk_03002C30[1].unk2 = 0x78;
    gUnk_03002C30[1].unk4 = 0x55;
    gUnk_03002C30[1].unkB = 0x20;
    sub_0806DF80(0, 1);
    init_battle_sprite_entry_08048818(3, 0xC000, 0x213, 3, 3);
    gUnk_03002C30[3].unk2 = 0x12C;
    gUnk_03002C30[3].unk4 = 0x55;
    gUnk_03002C30[3].unkB = 0x40;
    gUnk_03002C30[3].unk32 = 0x80;
    sub_0806DF80(7, 3);
    init_battle_sprite_entry_08048818(4, 0xC400, 0x21C, 5, 3);
    gUnk_03002C30[4].unk2 = 0x12C;
    gUnk_03002C30[4].unk4 = 0x3C;
    gUnk_03002C30[4].unkB = 0x10;
    gUnk_03002C30[4].unk32 = 0x80;
    sub_0806DF80(8, 4);
    REG_DISPCNT |= 0x1300;
    gUnk_03001800_s.nextSubState = 7;
    gUnk_03001800_s.timer = 0;
    gGameSubState = 1;
}

void update_sprite_special_effects(void) {
    u8 i;

    for (i = 0; i < 5; i++) {
        if (gUnk_03002C30[i].unk20 != 0) {
            if (++gUnk_03002C30[i].unk1A % gUnk_08485F14[gUnk_03002C30[i].unk20 - 1] == 0) {
                switch (gUnk_08485EF4[gUnk_03002C30[i].unk20 - 1](i)) {
                case 0:
                    gUnk_03002C30[i].unk20 = 0;
                    gUnk_03002C30[i].unk22 = 0;
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

// Title sprite palette fade-in: copies the title palette (gUnk_03001800_s.unkC, u16[14]) into
// OBJ palette 6 step by step (unk22 = step 0..0x1E).
bool32 sub_0806DD10(u8 idx) {
    u8 n;
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *p = &base[idx];
    u8 c = p->unk22;

    if (p->unk22 > 0x1E)
        return FALSE;
    if (p->unk22 == 0 || p->unk22 == 0x1E) {
        vu32 zero = 0;
        DmaSet(3, &zero, PLTT + 0x2C0, 0x85000000 | (0x20 / 4));
    } else if (p->unk22 <= 0xE) {
        n = c * 2;
        {
            vu32 zero = 0;
            DmaSet(3, &zero, PLTT + 0x2C0, 0x85000000 | ((0x20 - n) / 4));
        }
        DmaSet(3, (u16 *)&gUnk_03001800_s.unkC, PLTT + 0x2E0 - n, 0x80000000 | (n / 2));
    } else if (p->unk22 == 0xF) {
        DmaSet(3, (u16 *)&gUnk_03001800_s.unkC, PLTT + 0x2C0, 0x80000000 | (0x1C / 2));
    } else {
        n = (0x1E - c) * 2;
        {
            vu32 zero = 0;
            DmaSet(3, &zero, PLTT + 0x2C0 + n, 0x85000000 | ((0x20 - n) / 4));
        }
        DmaSet(3, &((u16 *)&gUnk_03001800_s.unkC)[p->unk22 - 15], PLTT + 0x2C0, 0x80000000 | (n / 2));
    }
    gUnk_03002C30[idx].unk22++;
    return TRUE;
}

bool32 sub_0806DE34(u8 i) {
    if (gUnk_03002C30[i].unk22 > 15)
        return FALSE;
    if (gUnk_03002C30[i].unk22 != 0)
        gUnk_03002C30[i].unk6++;
    gUnk_03002C30[i].unk22++;
    return TRUE;
}

bool32 sub_0806DE64(u8 i) {
    if ((gUnk_03002C30[i].unk2 -= 8) <= 0x78)
        return FALSE;
    return TRUE;
}

bool32 sub_0806DE88(u8 i) {
    if ((gUnk_03002C30[i].unk9 += 8) > 0x3F)
        return FALSE;
    return TRUE;
}

bool32 sub_0806DEAC(u8 i) {
    if (gUnk_03002C30[i].unk22 & 1)
        gUnk_03002C30[i].unk4 = 0x73;
    else
        gUnk_03002C30[i].unk4 = 0xC8;
    gUnk_03002C30[i].unk22++;
    return TRUE;
}

bool32 sub_0806DEE8(u8 i) {
    if (gUnk_03002C30[i].unk32 < gUnk_03002C30[i].unk1A) {
        if (gUnk_03002C30[i].unk22 > 7) {
            gUnk_03002C30[i].unk2 = 300;
            gUnk_03002C30[i].unk22 = 0;
            gUnk_03002C30[i].unk32 = (rng_next(0) & 0x1FF) + 0x20;
            gUnk_03002C30[i].unk6 = gUnk_03002C30[i].unk30;
            gUnk_03002C30[i].unk1A = 0;
        } else if (gGameSubState == 9 && gUnk_03002C30[i].unk22 == 0) {
            gUnk_03002C30[i].unk32 |= 0xFFFF;
            gUnk_03002C30[i].unk1A = 0;
        } else if (++gUnk_03002C30[i].unk22 != 1) {
            gUnk_03002C30[i].unk6++;
        } else {
            gUnk_03002C30[i].unk2 = 0x78;
        }
    }
    return TRUE;
}

static void sub_0806DF80(u8 a, u8 i) {
    gUnk_03002C30[i].unk20 = a;
    gUnk_03002C30[i].unk22 = 0;
    gUnk_03002C30[i].unk30 = gUnk_03002C30[i].unk6;
    gUnk_03002C30[i].unk1A = 0;
}
