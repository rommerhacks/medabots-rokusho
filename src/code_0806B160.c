#include "global.h"

u32 update_sprite_position_sincos(u8 i)
{
#define S gUnk_03002C30[i]
    S.unkC_8 += gUnk_083D69A0[0][(S.unk23 + 0x40) & 0xFF];
    S.unk10_8 += gUnk_083D69A0[0][S.unk23];
    if (i > 11) {
        S.unk2 = S.unkC_8 / 256 + 0x20;
        S.unk4 = 0x10 - S.unk10_8 / 256;
    } else {
        S.unk2 = S.unkC_8 / 128 + 0x20;
        S.unk4 = 0x10 - S.unk10_8 / 128;
    }
    if (S.unk1A > 8) {
        S.unk1A = gUnk_083F7FF4[(gFrameCounter + i) & 0xFF] >> 3;
        S.unk20 = 9;
    }
    return 1;
#undef S
}

u32 sub_0806B244(u8 i)
{
#define S gUnk_03002C30[i]
    u32 phase = (S.unk1A + 0x10) & 0x3F;

    if (S.unk4 > 0x60) {
        S.unk4 = 0xC8;
        return 0;
    }
    if (S.unk1A & 1)
        S.unk4++;
    if (phase & 0x10) {
        if (S.unk1A & 1) {
            if (i & 1)
                S.unk2++;
            else
                S.unk2--;
        }
    } else {
        if (S.unk1A & 1) {
            if (i & 1)
                S.unk2--;
            else
                S.unk2++;
        }
    }
    if (S.unk1A & 8)
        S.unk0 |= 0x1000;
    else
        S.unk0 &= 0xEFFF;
    return 1;
#undef S
}

u32 sub_0806B2F0(u8 i)
{
    if (gUnk_03002C30[i].unk27)
        gUnk_03002C30[i].unk27--;
    return 1;
}

void sub_0806B310(void)
{
    if (gFrameCounter & 1) {
        gBg3Scroll.x--;
        gBg3Scroll.y++;
    }
}

void update_sprite_animations_0806B334(void)
{
    u8 i;

    for (i = 0; i < 20; i++) {
        struct Unk_03002C30 *s = &gUnk_03002C30[i];
        if (s->unk21 != 0) {
            const struct SpriteAnimFrame *tbl = gUnk_08485D5C;
            if (tbl[s->unk21].duration <= s->unk27++) {
                s->unk27 = 0;
                s->unk21 = tbl[s->unk21].next;
                s->unk6 = tbl[s->unk21].frame;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_0806B160", sprite_animation_dispatch);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806B420);

void clear_sprite_entry(u8 sprite)
{
    u32 zero = 0;
    DmaSet(3, &zero, &gUnk_03002C30[sprite], 0x85000010);
}

void battle_screen_dispatch(void)
{
    gUnk_08485E5C[gGameSubState]();
}

void init_battle_screen(void)
{
    u32 zero = 0;
    DmaSet(3, &zero, VRAM, 0x85006000);
    REG_DISPCNT = 0x60;
    zero = 0;
    DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
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

void load_battle_screen_graphics(void)
{
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

    init_battle_sprite_entry_08048818(30, 0xCF20, 0, 0, 3);
    gUnk_03002C30[30].unk2 = 0x78;
    gUnk_03002C30[30].unk4 = 0x80;
    gUnk_03002C30[30].unk8 = 0x40;
    gUnk_03002C30[30].unk9 = 0x40;
    gUnk_03002C30[30].unk18 = 0;
    gUnk_03001800_arcade.unk41 = 0;
    gUnk_03002C30[30].unk20 = 3;
    gUnk_03002C30[30].unk21 = 0;

    init_battle_sprite_entry_08048818(32, 0xCC00, 7, 1, 3);
    gUnk_03002C30[32].unk2 = 0x78;
    gUnk_03002C30[32].unk4 = 0x10;
    init_battle_sprite_entry_08048818(31, 0xCC00, 0x10, 2, 3);
    gUnk_03002C30[31].unk4 = 0xC8;
    init_battle_sprite_entry_08048818(10, 0xC400, 0x10, 2, 3);
    gUnk_03002C30[10].unk2 = 0x10;
    gUnk_03002C30[10].unk4 = 0x30;
    for (i = 0; i < 2; i++) {
        init_battle_sprite_entry_08048818(i + 11, 0xC400, 0x21, 8, 3);
        gUnk_03002C30[11 + i].unk2 = 0x18 + i * 16;
        gUnk_03002C30[11 + i].unk4 = 0x28;
    }
    init_battle_sprite_entry_08048818(57, 0xC800, 0x2B, 9, 3);
    gUnk_03002C30[57].unk2 = 0x78;
    gUnk_03002C30[57].unk4 = 0x98;
    for (i = 0; i < 3; i++) {
        init_battle_sprite_entry_08048818(i + 13, 0xC400, 0x18, 5, 3);
        gUnk_03002C30[13 + i].unk2 = 8 + i * 16;
        gUnk_03002C30[13 + i].unk4 = 0x78;
    }
    init_battle_sprite_entry_08048818(16, 0xC400, 0x1E, 7, 3);
    gUnk_03002C30[16].unk2 = 0xB8;
    gUnk_03002C30[16].unk4 = 0x68;
    init_battle_sprite_entry_08048818(17, 0xC400, 0x1A, 6, 3);
    gUnk_03002C30[17].unk2 = 0xB8;
    gUnk_03002C30[17].unk4 = 0x58;
    init_battle_sprite_entry_08048818(18, 0xC400, 0x1C, 6, 3);
    gUnk_03002C30[18].unk2 = 0xD8;
    gUnk_03002C30[18].unk4 = 0x58;
    init_battle_sprite_entry_08048818(19, 0xC400, 0x19, 6, 3);
    gUnk_03002C30[19].unk2 = 0xB8;
    gUnk_03002C30[19].unk4 = 0xC8;
    REG_DISPCNT |= 0x1E00;
    gGameSubState++;
}

void sub_0806B990(void)
{
    if (scene_transition_step_080686F4()) {
        play_song(0x14);
        gGameSubState++;
    }
}

void sub_0806B9B0(void)
{
    if (sub_0806BBDC())
        gGameSubState++;
    sub_0806C994();
}

void sub_0806B9D0(void)
{
    s32 i;

    gUnk_03001800_arcade.unkF[0] = gUnk_083F7FF4[(gFrameCounter + i) & 0xFF] % 3;
    for (i = 1; i < gUnk_03001800_arcade.unkC; i++) {
        switch ((u8)(gUnk_083F7FF4[(gFrameCounter + i) & 0xFF] % 7)) {
        case 0:
            gUnk_03001800_arcade.unkF[i] = gUnk_03001800_arcade.unkF[i - 1];
            break;
        case 1:
        case 2:
        case 3:
            gUnk_03001800_arcade.unkF[i] = gUnk_03001800_arcade.unkF[i - 1] == 0 ? 1 : gUnk_03001800_arcade.unkF[i - 1] - 1;
            break;
        case 4:
        case 5:
        case 6:
            gUnk_03001800_arcade.unkF[i] = gUnk_03001800_arcade.unkF[i - 1] == 2 ? 1 : gUnk_03001800_arcade.unkF[i - 1] + 1;
            break;
        }
    }
    gGameSubState++;
}

void sub_0806BAB4(void)
{
    if (gUnk_03002C30[30].unk21 == 0) {
        sub_0806BE58();
        sub_0806C084();
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

void sub_0806BB00(void)
{
    sub_0806CE58();
    if (sub_0806C6F8()) {
        gUnk_03005310.unk39 = 1;
        sound_stop_all_with_fade_guard(0x30);
        gGameSubState = 8;
    }
}

void sub_0806BB30(void)
{
    sub_0806C20C();
    sub_0806CFA4();
    sub_0806CDE8();
    if (sub_0806C7C4()) {
        gUnk_03005310.unk39 = 2;
        sound_stop_all_with_fade_guard(0x30);
        gGameSubState = 8;
    }
}

void sub_0806BB68(void)
{
    if (execute_scene_step()) {
        u32 zero = 0;
        DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
        gGameSubState++;
    }
}

void sub_0806BBA8(void)
{
    REG_BLDCNT = 0xFF;
    REG_BLDY = 0x10;
    REG_DISPCNT &= 0x80FF;
    play_song(0);
    sub_08047850(1);
}

u32 sub_0806BBDC(void)
{
    switch (gUnk_03002C30[0].unk20) {
    case 0:
        init_battle_sprite_entry_08048818(0, 0xCA00, 0x2E, 10, 3);
        gUnk_03002C30[0].unk2 = 0x78;
        gUnk_03002C30[0].unk4 = 0x50;
        gUnk_03002C30[0].unk1A = 0;
        gUnk_03002C30[0].unk8 = 4;
        gUnk_03002C30[0].unk9 = 4;
        gUnk_03002C30[0].unk20++;
        break;
    case 1:
        if (gUnk_03002C30[0].unk1A < 0x18) {
            gUnk_03002C30[0].unk1A++;
        } else if (++gUnk_03002C30[0].unk1A > 0xB4 || (KEYS_LO(gNewKeys) & 9)) {
            gUnk_03002C30[0].unk1A = 0;
            gUnk_03002C30[0].unk20++;
        }
        break;
    case 2:
        if (gUnk_03002C30[0].unk1A < 0x18) {
            gUnk_03002C30[0].unk1A++;
        } else {
            gUnk_03002C30[0].unk1A = 0;
            gUnk_03002C30[0].unk4 = 0xC8;
            gUnk_03002C30[0].unk20++;
        }
        break;
    case 3:
        if (gUnk_03001800_arcade.unkC == gUnk_03001800_arcade.unkE) {
            init_battle_sprite_entry_08048818(0, 0xCA08, 0x2F, 11, 3);
            gUnk_03002C30[0].unk2 = 0x78;
            gUnk_03002C30[0].unk4 = 0x50;
            gUnk_03002C30[0].unk8 = 0;
            gUnk_03002C30[0].unk9 = 0x60;
            gUnk_03002C30[0].unk1A = 0;
            gUnk_03002C30[0].unk20++;
            REG_BLDCNT = 0x840;
            REG_BLDALPHA = 0x10;
        } else {
            gUnk_03001800_arcade.unkE++;
        }
        break;
    case 4:
    case 5:
    case 6:
        if (gUnk_03002C30[0].unk1A == 0)
            play_sound_effect(0x18);
        if (++gUnk_03002C30[0].unk1A > 0x3C) {
            gUnk_03002C30[0].unk6++;
            gUnk_03002C30[0].unk1A = 0;
            gUnk_03002C30[0].unk20++;
        }
        break;
    case 7:
        if (gUnk_03002C30[0].unk1A == 0)
            play_sound_effect(7);
        if (++gUnk_03002C30[0].unk1A > 0x1E) {
            clear_sprite_entry(0);
            gUnk_03001800_arcade.timer = 0;
            gUnk_03001800_arcade.unk44 = gUnk_03001800_arcade.unkC + gUnk_03001800_arcade.unkD;
            REG_BLDCNT = 0x840;
            REG_BLDALPHA = 0x808;
            return 1;
        }
        break;
    }
    return 0;
}

void sub_0806BD84(void)
{
    s32 i;
    s32 max;

    if (gUnk_03002C30[19].unk20 == 0) {
        max = 0;
        for (i = 0; i < 8; i++) {
            if (gUnk_03002C30[40 + i].unk20 == 1 && max < gUnk_03002C30[40 + i].unk4) {
                max = gUnk_03002C30[40 + i].unk4;
                gUnk_03002C30[19].unk20 = gUnk_03002C30[40 + i].unk20;
                gUnk_03002C30[19].unk21 = gUnk_03002C30[40 + i].unk21;
                gUnk_03002C30[19].unk1A = 0;
            }
        }
    } else {
        switch (gUnk_03002C30[19].unk21) {
        case 0:
            gUnk_03002C30[19].unk2 = 0xB8;
            break;
        case 1:
            gUnk_03002C30[19].unk2 = 0xC8;
            break;
        case 2:
            gUnk_03002C30[19].unk2 = 0xD8;
            break;
        }
        gUnk_03002C30[19].unk4 = (gUnk_03002C30[19].unk1A & 4) ? 0x47 : 0x49;
        gUnk_03002C30[19].unk1A++;
    }
}

void sub_0806BE58(void)
{
    u32 k = KEYS_HI(gHeldKeys) & 3;

    if (k == 1) {
        if (++gUnk_03001800_arcade.unk41 > 8)
            gUnk_03001800_arcade.unk41 = 8;
    } else if (k == 2) {
        if (--gUnk_03001800_arcade.unk41 < -8)
            gUnk_03001800_arcade.unk41 = -8;
    } else {
        if (gUnk_03001800_arcade.unk41 > 0)
            gUnk_03001800_arcade.unk41--;
        if (gUnk_03001800_arcade.unk41 < 0)
            gUnk_03001800_arcade.unk41++;
    }
    gUnk_03002C30[30].unk2 = gUnk_03001800_arcade.unk41 * 3 + 0x78;
}

void sub_0806BEF0(void)
{
    switch (gUnk_03002C30[32].unk20) {
    case 0:
        break;
    case 3:
        if (++gUnk_03002C30[32].unk1A == 20) {
            gUnk_03002C30[32].unk20 = 0;
            gUnk_03002C30[32].unk21 = 0;
            gUnk_03002C30[32].unk1A = 0;
            gUnk_03002C30[31].unk4 = 0xC8;
        }
        break;
    case 1:
        if (gUnk_03002C30[30].unk21 == 0) {
            gUnk_03002C30[31].unk2 = gUnk_03002C30[32].unk2;
            gUnk_03002C30[31].unk4 = 0x18;
        } else {
            gUnk_03002C30[32].unk20 = 3;
        }
        break;
    case 2:
        if (gUnk_03002C30[32].unk1A++ <= 7) {
            switch (gUnk_03002C30[32].unk21) {
            case 0:
                gUnk_03002C30[32].unk2 -= 2;
                if (gUnk_03002C30[32].unk2 < 0x6C)
                    gUnk_03002C30[32].unk2 = 0x6C;
                gUnk_03002C30[31].unk2 = gUnk_03002C30[32].unk2 - gUnk_03002C30[32].unk1A - 2;
                break;
            case 1:
                if (gUnk_03002C30[32].unk2 < 0x78) {
                    if ((gUnk_03002C30[32].unk2 += 2) > 0x78)
                        gUnk_03002C30[32].unk2 = 0x78;
                } else if (gUnk_03002C30[32].unk2 > 0x78) {
                    if ((gUnk_03002C30[32].unk2 -= 2) < 0x78)
                        gUnk_03002C30[32].unk2 = 0x78;
                }
                gUnk_03002C30[31].unk2 = gUnk_03002C30[32].unk2;
                break;
            case 2:
                gUnk_03002C30[32].unk2 += 2;
                if (gUnk_03002C30[32].unk2 > 0x84)
                    gUnk_03002C30[32].unk2 = 0x84;
                gUnk_03002C30[31].unk2 = gUnk_03002C30[32].unk2 + gUnk_03002C30[32].unk1A + 2;
                break;
            }
            gUnk_03002C30[31].unk4 = gUnk_03002C30[32].unk1A <= 3 ? 0x12 : 10;
        } else {
            gUnk_03002C30[32].unk20 = 3;
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806C084);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806C20C);

void sub_0806C4CC(void)
{
    if (gUnk_03002C30[56].unk20 == 1 && ++gUnk_03002C30[56].unk1A > 2)
        clear_sprite_entry(56);
}

INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806C500);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806C6F8);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806C7C4);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806C994);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806CAEC);
INCLUDE_ASM("asm/nonmatching/code_0806B160", update_battle_sprite_direction);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806CD48);

void sub_0806CDE8(void)
{
    s32 i;

    for (i = 0; i < 8; i++) {
        switch (gUnk_03002C30[40 + i].unk20) {
        case 1:
        case 2:
            gUnk_03002C30[40 + i].unk6 = (gUnk_03002C30[40 + i].unk1A & 8) ? 0x10 : 0x11;
            gUnk_03002C30[40 + i].unk4 -= gUnk_08485E84[gUnk_03002C30[40 + i].unk1A & 0x3F];
            break;
        case 3:
            gUnk_03002C30[40 + i].unk6 = (gUnk_03002C30[40 + i].unk1A - 1) / 4 + 0x13;
            break;
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806CE58);
INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806CFA4);

void get_battle_state_value_div10(void)
{
    u16 attr = 0xC400;
    init_battle_sprite_entry_08048818(11, attr, (s8)(gUnk_03001800_s.unkC.s[2] / 10) + 0x21, 8, 3);
    init_battle_sprite_entry_08048818(12, attr, (s8)(gUnk_03001800_s.unkC.s[2] % 10) + 0x21, 8, 3);
}

void set_bot_y_positions_by_count(void)
{
    s32 i;
    for (i = 0; i < 3; i++) {
        s16 y = 0xC8;
        if (i < gUnk_03002C30[30].unk20)
            y = 0x78;
        gUnk_03002C30[13 + i].unk4 = y;
    }
}

void sub_0806D288(void)
{
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

static inline s32 mul120(u16 x)
{
    return x * 120;
}

static inline s32 sub_counter(void)
{
    return 0x7800 - gUnk_030003F0;
}

// Builds the per-scanline BG2 PA / X tables read by the HBlank handler sub_0806D420:
// lines 0-31 and 128-159 get X = 0x7800 -+ counter - PA * 120, lines 32-127 X = 0.
// Builds the BG2 PA / X tables read by the HBlank handler sub_0806D420 (rows 32-127 get X = 0).
void update_bg2_affine_scanline_params(void)
{
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

void sub_0806D3F4(void)
{
    update_bg2_affine_scanline_params();
    gUnk_08485EC4[gGameSubState]();
    update_sprite_special_effects();
    sub_0806D288();
}

// HBlank: sets the next scanline's BG2 PA and X from the tables built by update_bg2_affine_scanline_params.
// VCOUNT is read through a non-volatile pointer: the compare's load is reused for the first index.
void sub_0806D420(void)
{
    if (*(u8 *)REG_ADDR_VCOUNT < 159) {
        REG_BG2PA = gUnk_03000030[*(u8 *)REG_ADDR_VCOUNT + 1];
        REG_BG2X_L = gUnk_03000170[*(u8 *)REG_ADDR_VCOUNT + 1];
        REG_BG2X_H = gUnk_030002B0[*(u8 *)REG_ADDR_VCOUNT + 1];
    }
}

void teardown_scene_and_restore_state(void)
{
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

void sub_0806D518(void)
{
    if (gUnk_03001800_s.unk6 < ++gUnk_03001800_s.timer) {
        gUnk_03001800_s.timer = 0;
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
}

// Title screen sub-state 0: clears the screen and the scene struct, then sub-state 4 (load_scene_graphics).
void sub_0806D550(void)
{
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

void load_scene_graphics(void)
{
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

void battle_transition_animate_step(void)
{
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

void battle_scene_intro_step(void)
{
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

void battle_transition_wipe_effect(void)
{
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

void battle_intro_countdown_tick(void)
{
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

void sub_0806DAEC(void)
{
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

void sub_0806DB30(void)
{
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

void update_sprite_special_effects(void)
{
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

INCLUDE_ASM("asm/nonmatching/code_0806B160", sub_0806DD10);

bool32 sub_0806DE34(u8 i)
{
    if (gUnk_03002C30[i].unk22 > 15)
        return FALSE;
    if (gUnk_03002C30[i].unk22 != 0)
        gUnk_03002C30[i].unk6++;
    gUnk_03002C30[i].unk22++;
    return TRUE;
}

bool32 sub_0806DE64(u8 i)
{
    if ((gUnk_03002C30[i].unk2 -= 8) <= 0x78)
        return FALSE;
    return TRUE;
}

bool32 sub_0806DE88(u8 i)
{
    if ((gUnk_03002C30[i].unk9 += 8) > 0x3F)
        return FALSE;
    return TRUE;
}

bool32 sub_0806DEAC(u8 i)
{
    if (gUnk_03002C30[i].unk22 & 1)
        gUnk_03002C30[i].unk4 = 0x73;
    else
        gUnk_03002C30[i].unk4 = 0xC8;
    gUnk_03002C30[i].unk22++;
    return TRUE;
}

bool32 sub_0806DEE8(u8 i)
{
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

void sub_0806DF80(u8 a, u8 i)
{
    gUnk_03002C30[i].unk20 = a;
    gUnk_03002C30[i].unk22 = 0;
    gUnk_03002C30[i].unk30 = gUnk_03002C30[i].unk6;
    gUnk_03002C30[i].unk1A = 0;
}

void dispatch_game_substate_handler_0806DFA4(void)
{
    gUnk_08485F1C[gGameSubState]();
}

void sub_0806DFC4(void)
{
    if (scene_transition_step_080686F4()) {
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
}

void scene_complete_dma_and_restore_state(void)
{
    if (execute_scene_step()) {
        u32 zero = 0;
        DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
        REG_DISPCNT &= 0x80FF;
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
}

void sub_0806E060(void)
{
    u32 zero = 0;
    DmaSet(3, &zero, VRAM, 0x85006000);
    zero = 0;
    DmaSet(3, &zero, PLTT, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
    zero = 0;
    DmaSet(3, &zero, &gUnk_03001800_s, 0x85000004);
    REG_DISPCNT = 0x60;
    gUnk_03001800_s.nextMode = 3;
    gUnk_03001800_s.nextState = 3;
    gUnk_03001800_s.unkC.h = gUnk_03006D38.unk1;
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

void battle_init_tilemap_and_palette(void)
{
    u16 map[20][30];
    u16 out[20 * 32];
    s32 i, j;

    LZ77UnCompVram(gUnk_08487328[gUnk_03001800_s.unkC.h], (void *)(VRAM + 0x8000));
    LZ77UnCompVram(gUnk_08487358[gUnk_03001800_s.unkC.h], map);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            out[i * 32 + j] = map[i][j];
        out[i * 32 + 30] = 0;
        out[i * 32 + 31] = 0;
    }
    DmaSet(3, out, VRAM + 0x7800, 0x84000140);
    DmaSet(3, gUnk_08487388[gUnk_03001800_s.unkC.h], PLTT, 0x800000E0);
    REG_BG1CNT = 0xF8B;
    setup_screen_transition_effect_080682CC(2, 1, 0);
    text_window_init(1, 2, 0);
    REG_DISPCNT |= 0x200;
    gUnk_03001800_s.nextSubState = 4;
    gGameSubState = 1;
}

void dispatch_battle_event_script(void)
{
    if (run_message(gUnk_08486EEC[gUnk_03001800_s.unkC.h])) {
        gUnk_03001800_s.nextSubState = 5;
        gGameSubState = 2;
    }
}

void sub_0806E26C(void)
{
    sub_08047850(2);
}

void boot_logos_check_skip(void)
{
    if (--gUnk_03001800_s.unk10 == 0)
        play_song(3);
    if (gUnk_03001800_s.unkC.b != 0 && (KEYS_LO(gNewKeys) & 8)) {
        gGameMode = 3;
        gGameState = 2;
        gGameSubState = 0;
        gUnk_03007008 = 1;
    }
}

void boot_logos_update(void)
{
    gBootLogosSubStates[gGameSubState]();
    boot_logos_check_skip();
}

bool32 blend_fade_step_0806E2F8(void)
{
    if ((gUnk_03001800_s.timer & 3) == 0) {
        u8 a = 16 - (gUnk_03001800_s.timer >> 2);
        u8 b = 16 - a;
        REG_BLDALPHA = (b << 8) | a;
        if (b == 16)
            return TRUE;
    }
    gUnk_03001800_s.timer++;
    return FALSE;
}

void sub_0806E340(void)
{
    if (blend_fade_step_0806E2F8()) {
        gUnk_03001800_s.timer = 0;
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
}

void boot_logos_init(void)
{
    u32 zero = 0;
    DmaSet(3, &zero, VRAM, 0x85006000);
    zero = 0;
    DmaSet(3, &zero, PLTT, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, OAM, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
    zero = 0;
    DmaSet(3, &zero, &gUnk_03001800_s, 0x85000005);
    play_song(0);
    REG_DISPCNT = 0x60;
    gUnk_03001800_s.nextMode = 3;
    gUnk_03001800_s.nextState = 0;
    gUnk_03001800_s.timer = 0;
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gUnk_03007008 = 0;
    setup_screen_transition_effect_080682CC(2, 4, 0);
    gGameSubState = 4;
}

void boot_logos_load_licensed_by(void)
{
    u16 map[20][30];
    u16 out[20 * 32];
    s32 i, j;

    LZ77UnCompVram(gUnk_087F1B4C, (void *)VRAM);
    LZ77UnCompVram(gUnk_087F1E4C, map);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            out[i * 32 + j] = *(map[i] + j);
        out[i * 32 + 30] = 0;
        out[i * 32 + 31] = 0;
    }
    DmaSet(3, out, VRAM + 0x7800, 0x84000140);
    DmaSet(3, gUnk_087F1F38, PLTT, 0x80000010);
    REG_BG0CNT = 0xF01;
    REG_DISPCNT |= 0x100;
    gUnk_03001800_s.nextSubState = 5;
    gGameSubState = 1;
}

void boot_logos_load_natsume(void)
{
    u16 map[20][30];
    u16 out[20 * 32];
    s32 i, j;

    LZ77UnCompVram(gUnk_087F1F58, (void *)VRAM);
    LZ77UnCompVram(gUnk_087F2658, map);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            out[i * 32 + j] = *(map[i] + j);
        out[i * 32 + 30] = 0;
        out[i * 32 + 31] = 0;
    }
    DmaSet(3, out, VRAM + 0x7800, 0x84000140);
    DmaSet(3, gUnk_087F27D8, PLTT, 0x80000010);
    gUnk_03001800_s.unk10 = 0x34;
    REG_BG0CNT = 0xF02;
    REG_DISPCNT |= 0x100;
    gUnk_03001800_s.nextSubState = 7;
    gGameSubState = 1;
}

void boot_logos_load_overlay(void)
{
    u16 map[20][30];
    u16 out[20 * 32];
    s32 i, j;

    LZ77UnCompVram(gUnk_087F27F8, (void *)(VRAM + 0x8000));
    LZ77UnCompVram(gUnk_087F3070, map);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++)
            out[i * 32 + j] = *(map[i] + j) + 0x1000;
        out[i * 32 + 30] = 0;
        out[i * 32 + 31] = 0;
    }
    DmaSet(3, out, VRAM + 0xF800, 0x84000140);
    DmaSet(3, gUnk_087F3250, PLTT + 0x20, 0x80000010);
    REG_BG1CNT = 0x1F0B;
    REG_DISPCNT |= 0x200;
    REG_BLDCNT = 0x241;
    REG_BLDALPHA = 0x10;
    gUnk_03001800_s.nextSubState = 9;
    gGameSubState = 3;
}

void sub_0806E780(void)
{
    if (gUnk_03001800_s.timer == 0) {
    } else if (gUnk_03001800_s.timer > 60) {
        gUnk_03001800_s.timer = 0;
        gUnk_03001800_s.nextSubState = 6;
        gGameSubState = 2;
        return;
    }
    gUnk_03001800_s.timer++;
}

void sub_0806E7B0(void)
{
    if (gUnk_03001800_s.timer == 0) {
        gUnk_03001800_s.unkC.b = 1;
    } else if (gUnk_03001800_s.timer > 60) {
        gUnk_03001800_s.timer = 0;
        gGameSubState = 8;
        return;
    }
    gUnk_03001800_s.timer++;
}

void sub_0806E7E0(void)
{
    if (gUnk_03001800_s.timer == 0) {
        REG_DISPCNT &= 0xFEFF;
    } else if (gUnk_03001800_s.timer > 60) {
        gUnk_03001800_s.timer = 0;
        setup_screen_transition_effect_080684F0(2, 4, 0);
        gUnk_03001800_s.nextSubState = 10;
        gGameSubState = 2;
        return;
    }
    gUnk_03001800_s.timer++;
}

void boot_logos_end(void)
{
    gGameMode = 3;
    gGameState = 1;
    gGameSubState = 0;
}

void sub_0806E854(void)
{
    if (gUnk_03000430 == 2) {
        u32 v = 0x200;
        DmaSet(3, &v, gUnk_03002414->unkB84, 0x85000100);
        setup_scene_with_bg_and_sprites(0, 0x2A, 0x2A, 0x2A, 0x2A, 0x70, 0x50, gUnk_03000430, 0xC, 0, 1, 0);
        advance_text_display(0, 0x2D, 0x2A);
    }
}

void intro_check_skip(void)
{
    if (KEYS_LO(gHeldKeys) & 8) {
        gUnk_03007008 = 1;
        gUnk_03000430 = 0;
        gGameMode = 3;
        gGameState = 2;
        gGameSubState = 0;
    }
}

void intro_update(void)
{
    sub_0806E854();
    gIntroSubStates[gGameSubState]();
    intro_check_skip();
}

void sub_0806E934(void)
{
    if (sub_0806F850()) {
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
}

void sub_0806E968(void)
{
    if (sub_0806F9D4()) {
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
}

void scene_fade_out_and_restore_state(void)
{
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

void scene_animate_and_complete(void)
{
    gUnk_03001800_s.unkF0++;
    gUnk_03001800_s.unkF2 += 0x6F;
    battle_timer_digit_extract();
    update_sprite_animations_080703D8();
    if (execute_scene_step()) {
        u32 zero = 0;
        DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
        gUnk_03000430 = 0;
        REG_DISPCNT &= 0x80FF;
        gGameMode = gUnk_03001800_s.nextMode;
        gGameState = gUnk_03001800_s.nextState;
        gGameSubState = gUnk_03001800_s.nextSubState;
    }
}

void battle_scene_init_clear(void)
{
    u32 zero = 0;
    DmaSet(3, &zero, VRAM, 0x85006000);
    zero = 0;
    DmaSet(3, &zero, PLTT, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
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
    gUnk_03007008 = 0;
    gGameSubState = 8;
}

void load_battle_scene_graphics(void)
{
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
    init_battle_sprite_entry_08048818(0, 0xC000, 0x40D, 4, 3);
    gUnk_03002C30[0].unk2 = 0x98;
    gUnk_03002C30[0].unk4 = 0x40;
    setup_screen_transition_effect_080682CC(2, 1, 0);
    gUnk_03000430 = 0;
    gUnk_03001800_s.nextSubState = gUnk_03001800_s.unkC.h;
    gGameSubState = 3;
}

void init_scene_graphics(void)
{
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
    init_battle_sprite_entry_08048818(9, 0xC800, 0x404, 1, 3);
    gUnk_03002C30[9].unk2 = 8;
    gUnk_03002C30[9].unk4 = 0xA0;
    init_battle_sprite_entry_08048818(10, 0xC800, 0x405, 1, 3);
    gUnk_03002C30[10].unk2 = zero;
    gUnk_03002C30[10].unk4 = 0x90;
    for (i = 0; i <= 2; i++) {
        ((void (*)())init_battle_sprite_entry_08048818)(i + 11, 0xC400, i + 0x400, 0, 3);
        gUnk_03002C30[i + 11].unk2 = 0xC0;
        gUnk_03002C30[i + 11].unk4 = 0xC8;
    }
    for (i = 0; i <= 5; i++) {
        ((void (*)())init_battle_sprite_entry_08048818)(i + 3, 0xC400, 0x408, 2, 3);
        gUnk_03002C30[i + 3].unk2 = i * 8 + 0xA0;
        gUnk_03002C30[i + 3].unk4 = 0xC8;
        gUnk_03002C30[i + 3].unkB = 0x20;
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

void load_battle_ui_assets(void)
{
    LZ77UnCompVram(gUnk_08485FD0[1], (void *)0x06010000);
    LZ77UnCompVram(gUnk_087C8D54, gUnk_03001800_s.unk30);
    gGameSubState = 6;
}

void init_battle_result_screen(void)
{
    u32 v;
    s32 legs = 0x2A;
    init_scene_buffers_080445F4();
    v = 0x200;
    DmaSet(3, &v, gUnk_03002414->unkB84, 0x85000100);
    setup_scene_with_bg_and_sprites(0, 0x2A, 0x2A, 0x2A, legs, 0x78, 0x50, 2, 0xC, 0, 0, 0);
    DmaSet(3, gUnk_08485FD8[1], PLTT + 0x200, 0x80000050);
    setup_screen_transition_effect_080682CC(2, 4, 0);
    REG_DISPCNT |= 0x1000;
    gUnk_03001800_s.nextSubState = 15;
    gGameSubState = 1;
}

void sub_0806F038(void)
{
    load_bg_screen_b();
    REG_MOSAIC = 0xFF;
    gUnk_03001800_s.unk6 = 6;
    gBg0Scroll.y = 0xFFE4;
    DmaSet(3, gUnk_08485FD8[1], PLTT + 0x200, 0x80000050);
    gUnk_03001800_s.nextSubState = gUnk_03001800_s.unkC.h;
    gGameSubState = 4;
}

void sub_0806F094(void)
{
    if (battle_transition_fade_step()) {
        gUnk_03001800_s.timer = 0;
        gUnk_03001800_s.nextSubState = 7;
        gUnk_03001800_s.unkC.h = 12;
    }
}

void sub_0806F0B4(void)
{
    s32 n = 0xC4;
    s32 i;

    gUnk_03001800_s.unkF0++;
    gUnk_03001800_s.unkF2 += 0x6F;
    if (gUnk_03001800_s.timer < n) {
        switch (gUnk_03001800_s.timer) {
        case 0:
            init_battle_sprite_entry_08048818(1, 0xCA00, 0x409, 3, 3);
            gUnk_03002C30[1].unk2 = 0x50;
            gUnk_03002C30[1].unk4 = 0x38;
            gUnk_03002C30[1].unk8 = 2;
            gUnk_03002C30[1].unk9 = 2;
            battle_sprite_set_action(1, 1, 0);
            battle_sprite_set_action(4, 9, 0);
            battle_sprite_set_action(5, 10, 0);
            gUnk_03001800_s.timer++;
            break;
        case 1:
            if (gUnk_03002C30[1].unk20 == 0)
                gUnk_03001800_s.timer++;
            break;
        case 2:
            init_battle_sprite_entry_08048818(2, 0xC600, 0x406, 2, 3);
            gUnk_03002C30[2].unk2 = 0xB8;
            gUnk_03002C30[2].unk4 = 0x70;
            gUnk_03002C30[2].unk8 = 2;
            gUnk_03002C30[2].unk9 = 2;
            battle_sprite_set_action(2, 2, 0);
            gUnk_03001800_s.timer++;
            break;
        case 3:
            if (gUnk_03002C30[2].unk20 == 0) {
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
        gUnk_03002C30[1].unk4 = 0xC8;
        gUnk_03002C30[2].unk4 = 0xC8;
        for (i = 0; i < 3; i++)
            gUnk_03002C30[i + 11].unk4 = 0xC8;
        for (i = 0; i < 6; i++) {
            battle_sprite_set_action(0, i + 3, 0);
            gUnk_03002C30[i + 3].unk4 = 0xC8;
        }
        gUnk_03001800_s.timer++;
    } else {
        switch (gUnk_03001800_s.timer) {
        case 0xC5:
            gUnk_03002C30[1].unk6 = 0x40A;
            gUnk_03002C30[1].unk4 = 0x38;
            gUnk_03002C30[1].unk8 = 2;
            gUnk_03002C30[1].unk9 = 2;
            battle_sprite_set_action(1, 1, 0);
            gUnk_03001800_s.timer++;
            break;
        case 0xC6:
            if (gUnk_03002C30[1].unk20 == 0)
                gUnk_03001800_s.timer++;
            break;
        case 0xC7:
            gUnk_03002C30[2].unk6 = 0x407;
            gUnk_03002C30[2].unk4 = 0x70;
            gUnk_03002C30[2].unk8 = 2;
            gUnk_03002C30[2].unk9 = 2;
            battle_sprite_set_action(2, 2, 0);
            gUnk_03001800_s.timer++;
            break;
        case 0xC8:
            if (gUnk_03002C30[2].unk20 == 0) {
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

