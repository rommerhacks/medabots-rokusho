// Mode-3 state 5: the bomb minigame (entered from a field script, switch_game_mode case 0x11).
// bomb_game_dispatch runs gUnk_08485E5C; bomb_game_init / bomb_game_load_graphics set up the screen, then the
// handlers drop the bombs, move the player sprite and count the score. Uses the race module's sprite animator
// and the mode-3 screen transitions (engine/scene_transition.c).
#include "global.h"

static void sub_0806BD84(void);
static void sub_0806BEF0(void);
static void sub_0806C20C(void);
static void sub_0806C4CC(void);
static u32 sub_0806C6F8(void);
static u32 sub_0806C7C4(void);
static void sub_0806CAEC(void);
static void update_battle_sprite_direction(void);
static void sub_0806CD48(void);
static void sub_0806CE58(void);
static void sub_0806CFA4(void);

void bomb_game_dispatch(void) {
    gUnk_08485E5C[gGameSubState]();
}

void bomb_game_init(void) {
    u32 zero = 0;
    DmaSet(3, &zero, VRAM, 0x85006000);
    REG_DISPCNT = 0x60;
    zero = 0;
    DmaSet(3, &zero, gSpriteEntries, 0x85000800);
    zero = 0;
    DmaSet(3, &zero, &gUnk_03001800_s, 0x85000012);
    gUnk_03001800_s.nextMode = 3;
    gUnk_03001800_s.nextState = 5;
    gUnk_03001800_s.timer = 0;
    gUnk_03001800_s.unkC.s[1] = 0xC;
    gUnk_03001800_s.unkC.s[0] = 0x32;
    gUnk_03001800_s.unkC.s[2] = 0;
    play_song(0);
    setup_screen_transition_effect_080682CC(3, 2, 0);
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gGameSubState++;
}

void bomb_game_load_graphics(void) {
    s32 i;

    LZ77UnCompVram(gUnk_087B3B30, (void *)(VRAM + 0x4000));
    LZ77UnCompVram(gUnk_087B50AC, (void *)(VRAM + 0x800));
    LZ77UnCompVram(gUnk_087B5214, (void *)(VRAM + 0x1000));
    LZ77UnCompVram(gUnk_087B52E4, (void *)(VRAM + 0x1800));
    DmaSet(3, gUnk_087B551C, PLTT, 0x80000050);
    REG_BG1CNT = 0x105;
    REG_BG2CNT = 0x206;
    REG_BG3CNT = 0x307;
    LZ77UnCompVram(gUnk_087AA19C, (void *)(VRAM + 0x10000));
    DmaSet(3, gUnk_0807C0A0, PLTT + 0x200, 0x800000F0);

    sprite_entry_init(30, 0xCF20, 0, 0, 3);
    gSpriteEntries[30].unk2 = 0x78;
    gSpriteEntries[30].unk4 = 0x80;
    gSpriteEntries[30].unk8 = 0x40;
    gSpriteEntries[30].unk9 = 0x40;
    gSpriteEntries[30].unk18 = 0;
    gUnk_03001800_bomb.unk41 = 0;
    gSpriteEntries[30].unk20 = 3;
    gSpriteEntries[30].unk21 = 0;

    sprite_entry_init(32, 0xCC00, 7, 1, 3);
    gSpriteEntries[32].unk2 = 0x78;
    gSpriteEntries[32].unk4 = 0x10;
    sprite_entry_init(31, 0xCC00, 0x10, 2, 3);
    gSpriteEntries[31].unk4 = 0xC8;
    sprite_entry_init(10, 0xC400, 0x10, 2, 3);
    gSpriteEntries[10].unk2 = 0x10;
    gSpriteEntries[10].unk4 = 0x30;
    for (i = 0; i < 2; i++) {
        sprite_entry_init(i + 11, 0xC400, 0x21, 8, 3);
        gSpriteEntries[11 + i].unk2 = 0x18 + i * 16;
        gSpriteEntries[11 + i].unk4 = 0x28;
    }
    sprite_entry_init(57, 0xC800, 0x2B, 9, 3);
    gSpriteEntries[57].unk2 = 0x78;
    gSpriteEntries[57].unk4 = 0x98;
    for (i = 0; i < 3; i++) {
        sprite_entry_init(i + 13, 0xC400, 0x18, 5, 3);
        gSpriteEntries[13 + i].unk2 = 8 + i * 16;
        gSpriteEntries[13 + i].unk4 = 0x78;
    }
    sprite_entry_init(16, 0xC400, 0x1E, 7, 3);
    gSpriteEntries[16].unk2 = 0xB8;
    gSpriteEntries[16].unk4 = 0x68;
    sprite_entry_init(17, 0xC400, 0x1A, 6, 3);
    gSpriteEntries[17].unk2 = 0xB8;
    gSpriteEntries[17].unk4 = 0x58;
    sprite_entry_init(18, 0xC400, 0x1C, 6, 3);
    gSpriteEntries[18].unk2 = 0xD8;
    gSpriteEntries[18].unk4 = 0x58;
    sprite_entry_init(19, 0xC400, 0x19, 6, 3);
    gSpriteEntries[19].unk2 = 0xB8;
    gSpriteEntries[19].unk4 = 0xC8;
    REG_DISPCNT |= 0x1E00;
    gGameSubState++;
}

void sub_0806B990(void) {
    if (scene_transition_step_080686F4()) {
        play_song(0x14);
        gGameSubState++;
    }
}

void sub_0806B9B0(void) {
    if (sub_0806BBDC())
        gGameSubState++;
    sub_0806C994();
}

void sub_0806B9D0(void) {
    s32 i;

    gUnk_03001800_bomb.unkF[0] = gRandomBytes[(gFrameCounter + i) & 0xFF] % 3;
    for (i = 1; i < gUnk_03001800_bomb.unkC; i++) {
        switch ((u8)(gRandomBytes[(gFrameCounter + i) & 0xFF] % 7)) {
        case 0:
            gUnk_03001800_bomb.unkF[i] = gUnk_03001800_bomb.unkF[i - 1];
            break;
        case 1:
        case 2:
        case 3:
            gUnk_03001800_bomb.unkF[i] = gUnk_03001800_bomb.unkF[i - 1] == 0 ? 1 : gUnk_03001800_bomb.unkF[i - 1] - 1;
            break;
        case 4:
        case 5:
        case 6:
            gUnk_03001800_bomb.unkF[i] = gUnk_03001800_bomb.unkF[i - 1] == 2 ? 1 : gUnk_03001800_bomb.unkF[i - 1] + 1;
            break;
        }
    }
    gGameSubState++;
}

void sub_0806BAB4(void) {
    if (gSpriteEntries[30].unk21 == 0) {
        sub_0806BE58();
        bomb_game_drop_bombs();
        sub_0806BD84();
    } else {
        sub_0806C500();
    }
    sub_0806BEF0();
    sub_0806C20C();
    sub_0806C4CC();
    get_battle_state_value_div10();
    sub_0806CDE8();
    update_battle_sprite_direction();
    sub_0806CD48();
    sub_0806CAEC();
}

void sub_0806BB00(void) {
    sub_0806CE58();
    if (sub_0806C6F8()) {
        gUnk_03005310.unk39 = 1;
        sound_stop_all_with_fade_guard(0x30);
        gGameSubState = 8;
    }
}

void sub_0806BB30(void) {
    sub_0806C20C();
    sub_0806CFA4();
    sub_0806CDE8();
    if (sub_0806C7C4()) {
        gUnk_03005310.unk39 = 2;
        sound_stop_all_with_fade_guard(0x30);
        gGameSubState = 8;
    }
}

void sub_0806BB68(void) {
    if (execute_scene_step()) {
        u32 zero = 0;
        DmaSet(3, &zero, gSpriteEntries, 0x85000800);
        gGameSubState++;
    }
}

void sub_0806BBA8(void) {
    REG_BLDCNT = 0xFF;
    REG_BLDY = 0x10;
    REG_DISPCNT &= 0x80FF;
    play_song(0);
    field_return_from_scene(1);
}

u32 sub_0806BBDC(void) {
    switch (gSpriteEntries[0].unk20) {
    case 0:
        sprite_entry_init(0, 0xCA00, 0x2E, 10, 3);
        gSpriteEntries[0].unk2 = 0x78;
        gSpriteEntries[0].unk4 = 0x50;
        gSpriteEntries[0].unk1A = 0;
        gSpriteEntries[0].unk8 = 4;
        gSpriteEntries[0].unk9 = 4;
        gSpriteEntries[0].unk20++;
        break;
    case 1:
        if (gSpriteEntries[0].unk1A < 0x18) {
            gSpriteEntries[0].unk1A++;
        } else if (++gSpriteEntries[0].unk1A > 0xB4 || (KEYS_LO(gNewKeys) & 9)) {
            gSpriteEntries[0].unk1A = 0;
            gSpriteEntries[0].unk20++;
        }
        break;
    case 2:
        if (gSpriteEntries[0].unk1A < 0x18) {
            gSpriteEntries[0].unk1A++;
        } else {
            gSpriteEntries[0].unk1A = 0;
            gSpriteEntries[0].unk4 = 0xC8;
            gSpriteEntries[0].unk20++;
        }
        break;
    case 3:
        if (gUnk_03001800_bomb.unkC == gUnk_03001800_bomb.unkE) {
            sprite_entry_init(0, 0xCA08, 0x2F, 11, 3);
            gSpriteEntries[0].unk2 = 0x78;
            gSpriteEntries[0].unk4 = 0x50;
            gSpriteEntries[0].unk8 = 0;
            gSpriteEntries[0].unk9 = 0x60;
            gSpriteEntries[0].unk1A = 0;
            gSpriteEntries[0].unk20++;
            REG_BLDCNT = 0x840;
            REG_BLDALPHA = 0x10;
        } else {
            gUnk_03001800_bomb.unkE++;
        }
        break;
    case 4:
    case 5:
    case 6:
        if (gSpriteEntries[0].unk1A == 0)
            play_sound_effect(0x18);
        if (++gSpriteEntries[0].unk1A > 0x3C) {
            gSpriteEntries[0].unk6++;
            gSpriteEntries[0].unk1A = 0;
            gSpriteEntries[0].unk20++;
        }
        break;
    case 7:
        if (gSpriteEntries[0].unk1A == 0)
            play_sound_effect(7);
        if (++gSpriteEntries[0].unk1A > 0x1E) {
            clear_sprite_entry(0);
            gUnk_03001800_bomb.timer = 0;
            gUnk_03001800_bomb.unk44 = gUnk_03001800_bomb.unkC + gUnk_03001800_bomb.unkD;
            REG_BLDCNT = 0x840;
            REG_BLDALPHA = 0x808;
            return 1;
        }
        break;
    }
    return 0;
}

static void sub_0806BD84(void) {
    s32 i;
    s32 max;

    if (gSpriteEntries[19].unk20 == 0) {
        max = 0;
        for (i = 0; i < 8; i++) {
            if (gSpriteEntries[40 + i].unk20 == 1 && max < gSpriteEntries[40 + i].unk4) {
                max = gSpriteEntries[40 + i].unk4;
                gSpriteEntries[19].unk20 = gSpriteEntries[40 + i].unk20;
                gSpriteEntries[19].unk21 = gSpriteEntries[40 + i].unk21;
                gSpriteEntries[19].unk1A = 0;
            }
        }
    } else {
        switch (gSpriteEntries[19].unk21) {
        case 0:
            gSpriteEntries[19].unk2 = 0xB8;
            break;
        case 1:
            gSpriteEntries[19].unk2 = 0xC8;
            break;
        case 2:
            gSpriteEntries[19].unk2 = 0xD8;
            break;
        }
        gSpriteEntries[19].unk4 = (gSpriteEntries[19].unk1A & 4) ? 0x47 : 0x49;
        gSpriteEntries[19].unk1A++;
    }
}

void sub_0806BE58(void) {
    u32 k = KEYS_HI(gHeldKeys) & 3;

    if (k == 1) {
        if (++gUnk_03001800_bomb.unk41 > 8)
            gUnk_03001800_bomb.unk41 = 8;
    } else if (k == 2) {
        if (--gUnk_03001800_bomb.unk41 < -8)
            gUnk_03001800_bomb.unk41 = -8;
    } else {
        if (gUnk_03001800_bomb.unk41 > 0)
            gUnk_03001800_bomb.unk41--;
        if (gUnk_03001800_bomb.unk41 < 0)
            gUnk_03001800_bomb.unk41++;
    }
    gSpriteEntries[30].unk2 = gUnk_03001800_bomb.unk41 * 3 + 0x78;
}

static void sub_0806BEF0(void) {
    switch (gSpriteEntries[32].unk20) {
    case 0:
        break;
    case 3:
        if (++gSpriteEntries[32].unk1A == 20) {
            gSpriteEntries[32].unk20 = 0;
            gSpriteEntries[32].unk21 = 0;
            gSpriteEntries[32].unk1A = 0;
            gSpriteEntries[31].unk4 = 0xC8;
        }
        break;
    case 1:
        if (gSpriteEntries[30].unk21 == 0) {
            gSpriteEntries[31].unk2 = gSpriteEntries[32].unk2;
            gSpriteEntries[31].unk4 = 0x18;
        } else {
            gSpriteEntries[32].unk20 = 3;
        }
        break;
    case 2:
        if (gSpriteEntries[32].unk1A++ <= 7) {
            switch (gSpriteEntries[32].unk21) {
            case 0:
                gSpriteEntries[32].unk2 -= 2;
                if (gSpriteEntries[32].unk2 < 0x6C)
                    gSpriteEntries[32].unk2 = 0x6C;
                gSpriteEntries[31].unk2 = gSpriteEntries[32].unk2 - gSpriteEntries[32].unk1A - 2;
                break;
            case 1:
                if (gSpriteEntries[32].unk2 < 0x78) {
                    if ((gSpriteEntries[32].unk2 += 2) > 0x78)
                        gSpriteEntries[32].unk2 = 0x78;
                } else if (gSpriteEntries[32].unk2 > 0x78) {
                    if ((gSpriteEntries[32].unk2 -= 2) < 0x78)
                        gSpriteEntries[32].unk2 = 0x78;
                }
                gSpriteEntries[31].unk2 = gSpriteEntries[32].unk2;
                break;
            case 2:
                gSpriteEntries[32].unk2 += 2;
                if (gSpriteEntries[32].unk2 > 0x84)
                    gSpriteEntries[32].unk2 = 0x84;
                gSpriteEntries[31].unk2 = gSpriteEntries[32].unk2 + gSpriteEntries[32].unk1A + 2;
                break;
            }
            gSpriteEntries[31].unk4 = gSpriteEntries[32].unk1A <= 3 ? 0x12 : 10;
        } else {
            gSpriteEntries[32].unk20 = 3;
        }
        break;
    }
}

void bomb_game_drop_bombs(void) {
    s32 i;
    s32 k;
    struct Unk_03001800_bomb *s;

    if (gUnk_03001800_bomb.unkE != 0 && gUnk_03001800_bomb.unk44 - 0x12 < gUnk_03001800_bomb.timer &&
        gUnk_03001800_bomb.timer < gUnk_03001800_bomb.unk44 - 9) {
        gSpriteEntries[32].unk20 = (gUnk_03001800_bomb.unk44 - 10 == gUnk_03001800_bomb.timer) ? 2 : 1;
        gSpriteEntries[32].unk21 = gUnk_03001800_bomb.unkF[gUnk_03001800_bomb.unkE - 1];
        gSpriteEntries[32].unk1A = 0;
    }
    s = &gUnk_03001800_bomb;
    if (s->unk44 < s->timer) {
        if (s->unkE == 0) {
            for (i = 0; i < 8; i++) {
                if (gSpriteEntries[40 + i].unk20 != 0)
                    return;
            }
            play_song(0);
            play_song(0xE);
            gGameSubState = 6;
            return;
        }
        s->unkE--;
        get_battle_state_value_div10();
        s->unk44 += s->unkE * s->unkE / 50 + s->unkD;
        for (i = 0; i < 8; i++) {
            if (gSpriteEntries[40 + i].unk20 == 0) {
                ((void (*)())sprite_entry_init)(i + 0x28, 0xC800, 0x10, 2, 3);
                gSpriteEntries[40 + i].unk2 = gSpriteEntries[32].unk2;
                gSpriteEntries[40 + i].unk4 = 0xC;
                gSpriteEntries[40 + i].unk1A = 0;
                gSpriteEntries[40 + i].unk20 = 1;
                gSpriteEntries[40 + i].unk21 = gUnk_03001800_bomb.unkF[gUnk_03001800_bomb.unkE];
                k = i + 0x30;
                ((void (*)())sprite_entry_init)(k, 0xCC08, 0x12, 2, 3);
                gSpriteEntries[k].unk2 = gSpriteEntries[40 + i].unk2;
                gSpriteEntries[k].unk4 = 0x10;
                play_sound_effect(0x61);
                gSpriteEntries[31].unk4 = 0xC8;
                break;
            }
        }
    }
    gUnk_03001800_bomb.timer++;
}

static void sub_0806C20C(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        switch (gSpriteEntries[40 + i].unk20) {
        case 0:
            break;
        case 1:
            gSpriteEntries[40 + i].unk2 =
                (gSpriteEntries[40 + i].unk21 - 1) * ((gSpriteEntries[40 + i].unk1A >> 2) + 0x18) + 0x78;
            gSpriteEntries[40 + i].unk4 = gSpriteEntries[40 + i].unk1A * 2 + 0xC;
            gSpriteEntries[i + 0x30].unk2 = gSpriteEntries[40 + i].unk2;
            gSpriteEntries[i + 0x30].unk4 = gSpriteEntries[40 + i].unk4 + 4;
            if (gSpriteEntries[40 + i].unk1A > 0x38) {
                if (gSpriteEntries[40 + i].unk1A > 0x3F) {
                    gSpriteEntries[40 + i].unk20 = 3;
                    gSpriteEntries[40 + i].unk1A = 0;
                    gSpriteEntries[40 + i].unk4 = 0x90;
                    gSpriteEntries[i + 0x30].unk4 = 0xC8;
                    if (gSpriteEntries[30].unk21 == 0) {
                        gSpriteEntries[30].unk21 = 1;
                        gSpriteEntries[30].unk1A = 0;
                        if ((s8)(gUnk_03001800_bomb.unk41 / 5) == 0)
                            gSpriteEntries[30].unk22 = gSpriteEntries[40 + i].unk21 != 2;
                        else
                            gSpriteEntries[30].unk22 = gUnk_03001800_bomb.unk41 > 0;
                        gSpriteEntries[19].unk20 = 0;
                        gSpriteEntries[19].unk21 = 0;
                        gSpriteEntries[19].unk4 = 0xC8;
                        gSpriteEntries[19].unk1A = 0;
                        sprite_entry_init(0x21, 0xCC08, 0x12, 2, 3);
                        gSpriteEntries[33].unk2 = gSpriteEntries[30].unk2;
                        gSpriteEntries[33].unk4 = gSpriteEntries[30].unk4 + 0xC;
                    }
                    play_sound_effect(0x3B);
                } else if (gSpriteEntries[30].unk21 == 0) {
                    if ((s8)(gUnk_03001800_bomb.unk41 / 5) + 1 == gSpriteEntries[40 + i].unk21) {
                        if (gSpriteEntries[40 + i].unk21 == 1)
                            gSpriteEntries[40 + i].unk21 = gUnk_03001800_bomb.unkE & 2;
                        gSpriteEntries[40 + i].unk20 = 2;
                        sprite_entry_init(0x38, 0xC400, 0x17, 4, 3);
                        gSpriteEntries[56].unk2 = gSpriteEntries[40 + i].unk2;
                        gSpriteEntries[56].unk4 =
                            gSpriteEntries[40 + i].unk4 - gUnk_08485E84[gSpriteEntries[40 + i].unk1A & 0x3F];
                        gSpriteEntries[56].unk20 = 1;
                        gSpriteEntries[56].unk1A = 0;
                        gSpriteEntries[19].unk20 = 0;
                        play_sound_effect(0x68);
                    }
                }
            }
            gSpriteEntries[40 + i].unk1A++;
            break;
        case 2:
            if (gSpriteEntries[40 + i].unk21 == 0)
                gSpriteEntries[40 + i].unk2 -= 4;
            else
                gSpriteEntries[40 + i].unk2 += 4;
            gSpriteEntries[40 + i].unk4 = gSpriteEntries[40 + i].unk1A * 2 + 0xC;
            gSpriteEntries[48 + i].unk2 = gSpriteEntries[40 + i].unk2;
            gSpriteEntries[48 + i].unk4 = gSpriteEntries[40 + i].unk4 + 4;
            if (gSpriteEntries[40 + i].unk1A < 0x28) {
                gSpriteEntries[40 + i].unk21 = 0;
                gSpriteEntries[40 + i].unk20 = 0;
                gSpriteEntries[40 + i].unk4 = 0xC8;
                gSpriteEntries[48 + i].unk4 = 0xC8;
            }
            gSpriteEntries[40 + i].unk1A--;
            break;
        case 3:
            if (gSpriteEntries[40 + i].unk1A == 0)
                ((void (*)())sprite_entry_init)(i + 0x28, 0xC400, 0x13, 3, 3);
            else if (gSpriteEntries[40 + i].unk1A > 0xF)
                clear_sprite_entry(i + 0x28);
            gSpriteEntries[40 + i].unk1A++;
            break;
        }
    }
}

static void sub_0806C4CC(void) {
    if (gSpriteEntries[56].unk20 == 1 && ++gSpriteEntries[56].unk1A > 2)
        clear_sprite_entry(56);
}

void sub_0806C500(void) {
    struct S32Array3 tbl;
    s32 i;

    tbl = gUnk_080AFF34;
    if (gSpriteEntries[30].unk1A < 0x50) {
        if (gSpriteEntries[30].unk1A <= tbl.v[gSpriteEntries[30].unk20 - 1] && (gSpriteEntries[30].unk1A & 7) == 0) {
            for (i = 0; i < 8; i++) {
                if (gSpriteEntries[40 + i].unk20 == 0) {
                    gSpriteEntries[40 + i].unk20 = 3;
                    gSpriteEntries[40 + i].unk2 = (gRandomBytes[(gFrameCounter + i) & 0xFF] & 0x3F) + 0x58;
                    gSpriteEntries[40 + i].unk4 = 0x90;
                    gSpriteEntries[40 + i].unk1A = 0;
                    if (gSpriteEntries[30].unk1A % 16 == 0)
                        play_sound_effect(0x3B);
                    break;
                }
            }
        }
        if (gSpriteEntries[30].unk22)
            gSpriteEntries[30].unk2 += 2;
        else
            gSpriteEntries[30].unk2 -= 2;
        gSpriteEntries[30].unk4 -= 2;
        gSpriteEntries[30].unk1A++;
    } else {
        gSpriteEntries[30].unk20--;
        set_bot_y_positions_by_count();
        if (gSpriteEntries[30].unk20 != 0) {
            u16 zero;

            gGameSubState = 3;
            gSpriteEntries[0].unk20 = 3;
            gSpriteEntries[30].unk21 = 0;
            gSpriteEntries[30].unk6 = 0;
            gSpriteEntries[30].unk18 = 0;
            gSpriteEntries[30].unk2 = 0x78;
            gSpriteEntries[30].unk4 = 0x80;
            gSpriteEntries[30].unk8 = 0x40;
            gSpriteEntries[30].unk9 = 0x40;
            gSpriteEntries[30].unk22 = 0;
            gUnk_03001800_bomb.unk41 = 0;
            gSpriteEntries[32].unk6 = 7;
            gSpriteEntries[32].unk2 = 0x78;
            gSpriteEntries[32].unk4 = 0x10;
            gSpriteEntries[32].unk1A = 0;
            zero = 0;
            DmaSet(3, &zero, &gSpriteEntries[32].unk20, 0x81000008);
            gUnk_03001800_bomb.unkC = gUnk_03001800_bomb.unkE + 10;
            if (gUnk_03001800_bomb.unkC > 0x32)
                gUnk_03001800_bomb.unkC = 0x32;
            gUnk_03001800_bomb.unkD += 4;
            gUnk_03001800_bomb.timer = 0;
        } else {
            play_song(0);
            play_song(0xF);
            gGameSubState = 7;
            gUnk_03001800_bomb.timer = 0;
        }
    }
}

static bool32 sub_0806C6F8(void) {
    u8 buf[0x20]; // unused, but the original reserves the stack space
    struct SpriteEntry *s = gSpriteEntries;

    switch (s->unk20) {
    case 0:
        sprite_entry_init(0, 0xC000, 0x33, 0xC, 3);
        s->unk2 = 0x78;
        s->unk4 = 0x50;
        s->unk1A = 0;
        s->unk20++;
        gSpriteEntries[30].unk6 = 0;
        sprite_entry_init(0x21, 0xCC08, 0x12, 2, 3);
        gSpriteEntries[33].unk2 = gSpriteEntries[30].unk2;
        gSpriteEntries[33].unk4 = gSpriteEntries[30].unk4 + 10;
        break;
    case 1:
        s->unk1A++;
        if (s->unk1A % 8 == 0)
            gSpriteEntries[32].unk4 -= 2;
        if (s->unk1A > 0xEB || (KEYS_LO(gNewKeys) & 9)) {
            clear_sprite_entry(0);
            return 1;
        }
        break;
    }
    return 0;
}

static u32 sub_0806C7C4(void) {
    s32 i;

    switch (gSpriteEntries[0].unk20) {
    case 0:
        sprite_entry_init(0, 0xC000, 0x34, 0xD, 3);
        gSpriteEntries[0].unk2 = 0x78;
        gSpriteEntries[0].unk4 = -0x10;
        gSpriteEntries[0].unk1A = 0;
        gSpriteEntries[0].unk21 = 1;
        gSpriteEntries[0].unk20++;
        if (gUnk_03001800_s.unkC.s[2] > 0x23) {
            sprite_entry_init(0x2E, 0xC800, 0x10, 2, 3);
            sprite_entry_init(0x36, 0xCC08, 0x12, 2, 3);
            gSpriteEntries[0x36].unk4 = 0x1E;
        } else if (gUnk_03001800_s.unkC.s[2] > 0) {
            sprite_entry_init(0x21, 0xCC08, 0x12, 2, 3);
            gSpriteEntries[0x21].unk2 = gSpriteEntries[0x20].unk2;
            gSpriteEntries[0x21].unk4 = gSpriteEntries[0x20].unk4 + 8;
        }
        break;
    case 1:
        if (gSpriteEntries[0].unk1A <= 0x90 && !(gSpriteEntries[0].unk1A % 4)) {
            for (i = 0; i <= 5; i++) {
                if (gSpriteEntries[0x28 + i].unk20 == 0) {
                    gSpriteEntries[0x28 + i].unk20 = 3;
                    gSpriteEntries[0x28 + i].unk2 = (gRandomBytes[(gFrameCounter + i) & 0xFF] & 0x3F) + 0x58;
                    gSpriteEntries[0x28 + i].unk4 = gSpriteEntries[0x39].unk4 - 0x10;
                    gSpriteEntries[0x28 + i].unk1A = 0;
                    if (!(gSpriteEntries[0].unk1A % 16))
                        play_sound_effect(0x3D);
                    break;
                }
            }
            gSpriteEntries[0x39].unk2 = (gSpriteEntries[0].unk1A & 4) ? 0x7A : 0x76;
            gSpriteEntries[0x39].unk4++;
        }
        if (gSpriteEntries[0].unk1A > 0xEB || (KEYS_LO(gNewKeys) & 9)) {
            clear_sprite_entry(0);
            clear_sprite_entry(0x39);
            return 1;
        }
        if (++gSpriteEntries[0].unk1A == 0x20) {
            sprite_entry_init(0x2F, 0xC800, 0x10, 2, 3);
            sprite_entry_init(0x37, 0xCC08, 0x12, 2, 3);
            gSpriteEntries[0x37].unk4 = 0x1E;
        }
        break;
    }
    return 0;
}

void sub_0806C994(void) {
    u8 eva[8];
    u8 evb[8];

    memcpy(eva, gUnk_080AFF40, 8);
    memcpy(evb, gUnk_080AFF48, 8);

    switch (gSpriteEntries[0].unk20) {
    case 1:
        if (gSpriteEntries[0].unk1A <= 0x17) {
            if (gSpriteEntries[0].unk1A <= 0xF) {
                gSpriteEntries[0].unk8 += 4;
                if (gSpriteEntries[0].unk8 > 0x40)
                    gSpriteEntries[0].unk8 = 0x40;
            } else {
                gSpriteEntries[0].unk9 += 8;
                if (gSpriteEntries[0].unk9 > 0x40)
                    gSpriteEntries[0].unk9 = 0x40;
            }
        }
        break;
    case 2:
        if (gSpriteEntries[0].unk1A <= 0x17) {
            if (gSpriteEntries[0].unk1A <= 7) {
                gSpriteEntries[0].unk9 -= 8;
                if (gSpriteEntries[0].unk9 < 4)
                    gSpriteEntries[0].unk9 = 4;
            } else {
                gSpriteEntries[0].unk8 -= 4;
                if (gSpriteEntries[0].unk8 < 4)
                    gSpriteEntries[0].unk8 = 4;
            }
        }
        break;
    case 3:
        get_battle_state_value_div10();
        break;
    case 4:
    case 5:
    case 6:
        if (gSpriteEntries[0].unk1A <= 8) {
            if (((gSpriteEntries[0].unk8 += 8) & 0xFF) > 0x40)
                gSpriteEntries[0].unk8 = 0x40;
            if (((gSpriteEntries[0].unk9 -= 4) & 0xFF) < 0x40)
                gSpriteEntries[0].unk9 = 0x40;
        } else if (gSpriteEntries[0].unk1A > 0x33) {
            if (gSpriteEntries[0].unk8 > 8)
                gSpriteEntries[0].unk8 -= 8;
            gSpriteEntries[0].unk9 += 4;
            if (gSpriteEntries[0].unk9 > 0x60)
                gSpriteEntries[0].unk9 = 0x60;
        }
        break;
    case 7:
        if (gSpriteEntries[0].unk1A <= 8) {
            if (((gSpriteEntries[0].unk8 += 8) & 0xFF) > 0x40)
                gSpriteEntries[0].unk8 = 0x40;
            if (((gSpriteEntries[0].unk9 -= 4) & 0xFF) < 0x40)
                gSpriteEntries[0].unk9 = 0x40;
        } else if (gSpriteEntries[0].unk1A > 0x15) {
            REG_BLDALPHA = (evb[gSpriteEntries[0].unk1A - 0x16] << 8) | eva[gSpriteEntries[0].unk1A - 0x16];
        }
        break;
    }
}

static void sub_0806CAEC(void) {
    if (gSpriteEntries[19].unk20 != 0) {
        switch (gSpriteEntries[19].unk21) {
        case 0:
            gSpriteEntries[17].unk6 = (gSpriteEntries[19].unk1A & 4) ? 0x1A : 0x1B;
            gSpriteEntries[18].unk6 = 0x1C;
            gSpriteEntries[16].unk6 = 0x1F;
            break;
        case 1:
            gSpriteEntries[17].unk6 = 0x1A;
            gSpriteEntries[18].unk6 = 0x1C;
            gSpriteEntries[16].unk6 = 0x1E;
            break;
        case 2:
            gSpriteEntries[17].unk6 = 0x1A;
            gSpriteEntries[18].unk6 = (gSpriteEntries[19].unk1A & 4) ? 0x1C : 0x1D;
            gSpriteEntries[16].unk6 = 0x20;
            break;
        }
    } else {
        gSpriteEntries[17].unk6 = 0x1A;
        gSpriteEntries[18].unk6 = 0x1C;
        gSpriteEntries[16].unk6 = 0x1E;
    }
}

static void update_battle_sprite_direction(void) {
    s8 d = gUnk_03001800_bomb.unk41;

    if (d > 3)
        gSpriteEntries[30].unk6 = (d == 8) ? 4 : 3;
    else if (d < -3)
        gSpriteEntries[30].unk6 = (d == -8) ? 2 : 1;
    else
        gSpriteEntries[30].unk6 = 0;

    if (gSpriteEntries[30].unk21 != 0) {
        gSpriteEntries[30].unk6 = (gSpriteEntries[30].unk1A & 8) ? 5 : 6;
        if (gSpriteEntries[30].unk22 != 0)
            gSpriteEntries[30].unk18 += 0x20;
        else
            gSpriteEntries[30].unk18 -= 0x20;
        gSpriteEntries[33].unk2 = gSpriteEntries[30].unk2;
        gSpriteEntries[33].unk4 = gSpriteEntries[30].unk4 + ((u32)gSpriteEntries[30].unk1A / 10 + 0xC);
        if (gSpriteEntries[30].unk1A < 0x20) {
            gSpriteEntries[30].unk8 = (gUnk_08485E84[gSpriteEntries[30].unk1A] >> 1) + 0x40;
            gSpriteEntries[30].unk9 = (gUnk_08485E84[gSpriteEntries[30].unk1A] >> 1) + 0x40;
        } else if (gSpriteEntries[30].unk20 == 3) {
            gSpriteEntries[57].unk6 = (gSpriteEntries[30].unk1A & 4) ? 0x2B : 0x2C;
        } else if (gSpriteEntries[30].unk20 == 2) {
            gSpriteEntries[57].unk6 = (gSpriteEntries[30].unk1A & 4) ? 0x2C : 0x2D;
        }
    }
}

static void sub_0806CD48(void) {
    s32 t = gSpriteEntries[32].unk1A;

    if (t != 0) {
        if (gSpriteEntries[30].unk21 != 0) {
            gSpriteEntries[32].unk6 = 8;
            gSpriteEntries[31].unk4 = 0x12;
        } else if (t <= 3) {
            gSpriteEntries[32].unk6 = 8;
        } else {
            switch (gSpriteEntries[32].unk21) {
            case 0:
                gSpriteEntries[32].unk6 = t <= 7 ? 0xA : 0xB;
                break;
            case 1:
                gSpriteEntries[32].unk6 = t <= 0xE ? 9 : 8;
                break;
            case 2:
                gSpriteEntries[32].unk6 = t <= 7 ? 0xC : 0xD;
                break;
            }
        }
    } else {
        gSpriteEntries[32].unk6 = 7;
    }
}

void sub_0806CDE8(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        switch (gSpriteEntries[40 + i].unk20) {
        case 1:
        case 2:
            gSpriteEntries[40 + i].unk6 = (gSpriteEntries[40 + i].unk1A & 8) ? 0x10 : 0x11;
            gSpriteEntries[40 + i].unk4 -= gUnk_08485E84[gSpriteEntries[40 + i].unk1A & 0x3F];
            break;
        case 3:
            gSpriteEntries[40 + i].unk6 = (gSpriteEntries[40 + i].unk1A - 1) / 4 + 0x13;
            break;
        }
    }
}

static void sub_0806CE58(void) {
    u16 buf[16];

    if (gSpriteEntries[0].unk20 == 1) {
        if (!(gSpriteEntries[0].unk1A % 8)) {
            if (gSpriteEntries[0].unk1A & 0x20) {
                DmaSet(3, 0x05000380, buf, 0x80000010);
                DmaSet(3, buf + 1, 0x05000384, 0x8000000B);
                DmaSet(3, buf + 4, 0x05000382, 0x80000001);
                DmaSet(3, buf + 8, 0x0500038A, 0x80000001);
                DmaSet(3, buf + 12, 0x05000392, 0x80000001);
            } else {
                DmaSet(3, 0x05000380, buf, 0x80000010);
                DmaSet(3, buf + 2, 0x05000382, 0x8000000B);
                DmaSet(3, buf + 1, 0x05000388, 0x80000001);
                DmaSet(3, buf + 5, 0x05000390, 0x80000001);
                DmaSet(3, buf + 9, 0x05000398, 0x80000001);
            }
        }
        if (gSpriteEntries[0].unk1A & 0x10)
            gSpriteEntries[30].unk4 = 0x80 - (gUnk_08485E84[(gSpriteEntries[0].unk1A & 0xF) * 4] >> 2);
        gSpriteEntries[32].unk6 = (gSpriteEntries[0].unk1A & 8) ? 0xE : 0xF;
    }
}

static void sub_0806CFA4(void) {
    s32 t = gSpriteEntries[0].unk1A;
    s32 k;

    if (gSpriteEntries[0].unk20 != 1)
        return;

    if (t > 0x2F) {
        if (t <= 0x3F) {
            gSpriteEntries[0].unk4 += 6;
        } else if (t <= 0x5F) {
            k = t & 0xF;
            if (k == 0)
                gSpriteEntries[0].unk21++;
            gSpriteEntries[0].unk4 = 0x50 - gUnk_08485E84[k * 4] / gSpriteEntries[0].unk21;
        }
    }

    if (gUnk_03001800_s.unkC.s[2] > 0x23) {
        if (t & 0x10) {
            if (t & 8)
                gSpriteEntries[32].unk6 = 0xA;
        } else {
            gSpriteEntries[32].unk6 = 8;
        }
        if (t & 0x20) {
            if ((t & 0x1F) <= 7)
                gSpriteEntries[46].unk2 = gSpriteEntries[32].unk2 + 0x10;
            else if ((t & 0x1F) > 0x17)
                gSpriteEntries[46].unk2 = gSpriteEntries[32].unk2 - 0x10;
            else
                gSpriteEntries[46].unk2 = gSpriteEntries[32].unk2 - (s16)((((t - 8) * 2) & 0x1F) - 0x10);
            gSpriteEntries[46].unk4 = 0x12;
            gSpriteEntries[47].unk2 = gSpriteEntries[32].unk2 + (s16)((t & 0x1F) - 0x10);
            gSpriteEntries[47].unk4 = 0x12 - (gUnk_08485E84[(t * 2) & 0x3F] >> 1);
        } else {
            gSpriteEntries[46].unk2 = gSpriteEntries[32].unk2 + (s16)((t & 0x1F) - 0x10);
            gSpriteEntries[46].unk4 = 0x12 - (gUnk_08485E84[(t * 2) & 0x3F] >> 1);
            if ((t & 0x1F) <= 7)
                gSpriteEntries[47].unk2 = gSpriteEntries[32].unk2 + 0x10;
            else if ((t & 0x1F) > 0x17)
                gSpriteEntries[47].unk2 = gSpriteEntries[32].unk2 - 0x10;
            else
                gSpriteEntries[47].unk2 = gSpriteEntries[32].unk2 - (s16)((((t - 8) * 2) & 0x1F) - 0x10);
            gSpriteEntries[47].unk4 = 0x12;
        }
        gSpriteEntries[54].unk2 = gSpriteEntries[46].unk2;
        gSpriteEntries[55].unk2 = gSpriteEntries[47].unk2;
    } else if (gUnk_03001800_s.unkC.s[2] > 0) {
        if (t & 0x10)
            gSpriteEntries[32].unk4 = 0x10 - gUnk_08485E84[(t & 0xF) * 4] / 4;
        gSpriteEntries[32].unk6 = (t & 0x10) ? 9 : (t & 8) ? 8 : 7;
    } else {
        gSpriteEntries[32].unk6 = (t & 8) ? 8 : (t & 0x10) ? 0xA : 0xC;
    }
}

void get_battle_state_value_div10(void) {
    u16 attr = 0xC400;
    sprite_entry_init(11, attr, (s8)(gUnk_03001800_s.unkC.s[2] / 10) + 0x21, 8, 3);
    sprite_entry_init(12, attr, (s8)(gUnk_03001800_s.unkC.s[2] % 10) + 0x21, 8, 3);
}
