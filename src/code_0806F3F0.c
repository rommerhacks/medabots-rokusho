#include "global.h"

void sub_0806F3F0(void)
{
    if (battle_transition_fade_step()) {
        sub_0806FF50();
        sub_0806FF90();
        gUnk_03001800_s.timer = 0;
        gUnk_03001800_s.nextSubState = 7;
        gUnk_03001800_s.unkC.h = 0xE;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_0806F418);

// Not called (dead code after sub_0806F418).
void sub_0806F750(void)
{
    gUnk_03001800_s.unkF4 += 0x10;
    gUnk_03001800_s.unkF6 -= 0x10;
    if (gUnk_03001800_s.timer++ > 0x3A) {
        gUnk_03001800_s.timer = 0;
        gUnk_03001800_s.nextSubState = 6;
        gUnk_03001800_s.unkC.h = 0x10;
        gGameSubState = 2;
    }
}

void sub_0806F78C(void)
{
    if (battle_transition_fade_step()) {
        gUnk_03001800_s.timer = 0;
        gUnk_03001800_s.nextSubState = 0xA;
        gUnk_03001800_s.unkC.h = 0x11;
    }
}

void sub_0806F7AC(void)
{
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

// Not called (dead code after sub_0806F7AC).
void sub_0806F830(void)
{
    gGameMode = 3;
    gGameState = 2;
    gGameSubState = 0;
}

INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_0806F850);

bool32 sub_0806F9D4(void)
{
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

INCLUDE_ASM("asm/nonmatching/code_0806F3F0", copy_tilemap_rect_to_vram);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", process_text_tile_and_dma_transfer);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", check_battle_timer_expired);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", battle_timer_digit_extract);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", battle_draw_tilemap_row_dma);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_0806FF50);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_0806FF90);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_0806FFF8);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_08070030);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", battle_transition_fade_step);

void load_bg_screen_a(void)
{
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

void load_bg_screen_b(void)
{
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

void load_bg_screen_c(void)
{
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

void update_sprite_animations_080703D8(void)
{
    u8 i;

    for (i = 0; i <= 10; i++) {
        struct Unk_03002C30 *base = gUnk_03002C30;
        struct Unk_03002C30 *s = &base[i];

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

s32 sub_08070468(u8 i)
{
    if (gUnk_03002C30[i].unk8 > 0x3F && gUnk_03002C30[i].unk9 > 0x3F)
        return 0;
    if (gUnk_03002C30[i].unk9 <= 0x3F) {
        if ((gUnk_03002C30[i].unk9 += 8) > 0x40)
            gUnk_03002C30[i].unk9 = 0x40;
    } else {
        if ((gUnk_03002C30[i].unk8 += 8) > 0x40)
            gUnk_03002C30[i].unk8 = 0x40;
    }
    gUnk_03002C30[i].unk21++;
    return 1;
}

s32 sub_080704D0(u8 i)
{
    if (gUnk_03002C30[i].unk8 > 0x3F && gUnk_03002C30[i].unk9 > 0x3F)
        return 0;
    if (gUnk_03002C30[i].unk8 <= 0x3F) {
        if ((gUnk_03002C30[i].unk8 += 8) > 0x40)
            gUnk_03002C30[i].unk8 = 0x40;
    } else {
        if ((gUnk_03002C30[i].unk9 += 8) > 0x40)
            gUnk_03002C30[i].unk9 = 0x40;
    }
    gUnk_03002C30[i].unk21++;
    return 1;
}

s32 sub_0807052C(u8 i)
{
    if (i & 1)
        gUnk_03002C30[i].unk4 = gUnk_03002C30[i].unk23 - gUnk_080AFF50[gUnk_03002C30[i].unk21 & 0x3F];
    else
        gUnk_03002C30[i].unk4 = gUnk_03002C30[i].unk23 + gUnk_080AFF50[gUnk_03002C30[i].unk21 & 0x3F];
    gUnk_03002C30[i].unk21 += 1 + gUnk_03002C30[i].unk22;
    return 1;
}

s32 sub_080705BC(u8 i)
{
    if (gUnk_03002C30[i].unk21 < 0x48) {
        gUnk_03002C30[i].unk21++;
    } else if (gUnk_03002C30[i].unk4 < -0x50) {
        gUnk_03002C30[i].unk4 = 0xA0;
        gUnk_03002C30[i].unk21 = 0;
    } else {
        gUnk_03002C30[i].unk4 -= 4;
    }
    return 1;
}

s32 sub_08070600(u8 i)
{
    if (gUnk_03002C30[i].unk21 < 0x48) {
        gUnk_03002C30[i].unk21++;
    } else if (gUnk_03002C30[i].unk2 > 0x168) {
        gUnk_03002C30[i].unk2 = 0;
        gUnk_03002C30[i].unk21 = 0;
    } else {
        gUnk_03002C30[i].unk2 += 6;
    }
    return 1;
}

void battle_sprite_set_action(u8 action, u8 i, u8 y)
{
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *s = &base[i];

    s->unk20 = action;
    s->unk21 = 0;
    if (y != 0) {
        s->unk22 = rng_next(0) & 3;
        s->unk23 = y - 4;
    }
    s->unk30 = s->unk6;
    s->unk1A = 0;
}

void sub_0807068C(void)
{
    if (gFrameCounter & 1)
        gBg3Scroll.y++;
}

void sub_080706AC(void)
{
    if ((gFrameCounter & 3) == 0) {
        if (++gUnk_03001800_bganim.unkE > 5)
            gUnk_03001800_bganim.unkE = 0;
        DmaSet(3, gUnk_02031000 + gUnk_03001800_bganim.unkE * 0x280, VRAM + 0x4020, 0x84000040);
    }
    if ((gFrameCounter & 0xF) == 0) {
        if (++gUnk_03001800_bganim.unkF > 5)
            gUnk_03001800_bganim.unkF = 0;
        if (gUnk_03001800_bganim.unkF <= 5)
            DmaSet(3, gUnk_02031100 + gUnk_03001800_bganim.unkF * 0x280, VRAM + 0x4120, 0x84000060);
    }
    sub_08071614();
    if (gUnk_03007010 != 0)
        sub_0807168C();
}

void sub_08070760(void)
{
    if (gUnk_03001800_bganim.unkC != 0)
        sub_0807068C();
    if (gUnk_03001800_bganim.unkD != 0)
        sub_080706AC();
    gUnk_084860C8[gGameSubState]();
}

void sub_0807079C(void)
{
    vu32 zero;

    zero = 0;
    DmaSet(3, &zero, VRAM, 0x85006000);
    zero = 0;
    DmaSet(3, &zero, PLTT, 0x85000100);
    zero = 0;
    DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
    zero = 0;
    DmaSet(3, &zero, &gUnk_03001800_bganim, 0x85000005);
    play_song(0);
    REG_DISPCNT = 0x60;
    gUnk_03001800_bganim.unk0 = 3;
    gUnk_03001800_bganim.unk2 = 6;
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gUnk_03007010 = 0;
    gGameSubState = 3;
}

void load_battle_bg_tilemaps(void)
{
    s32 i;

    LZ77UnCompVram(gUnk_087C11C4, (void *)0x06004000);
    LZ77UnCompVram(gUnk_087C2598, (void *)0x06008000);
    LZ77UnCompVram(gUnk_087C3928, (void *)0x06006800);
    LZ77UnCompVram(gUnk_087C3AF4, (void *)0x06007000);
    LZ77UnCompVram(gUnk_087C3D40, (void *)0x06007800);
    LZ77UnCompVram(gUnk_087C40B0, (void *)0x0600A800);
    LZ77UnCompVram(gUnk_087C4210, (void *)0x0600B000);
    LZ77UnCompVram(gUnk_087C4498, (void *)0x0600B800);
    LZ77UnCompVram(gUnk_087B1CEC, (void *)0x06010000);

    for (i = 0; i <= 10; i++)
    {
        init_battle_sprite_entry_08048818(i, 0xC800, 0x50E, 4, 3);
        gUnk_03002C30[i].unk2 = i * 8 + 0x78;
        gUnk_03002C30[i].unk4 = 0;
        gUnk_03002C30[i].unkB = i + 0x40;
        gUnk_03002C30[i].unk22 = i + 1;
        init_battle_sprite_entry_08048818(i + 11, 0xC800, 0x50E, 4, 3);
        gUnk_03002C30[i + 11].unk2 = 0x70 - i * 8;
        gUnk_03002C30[i + 11].unk4 = 0;
        gUnk_03002C30[i + 11].unkB = i + 0x40;
        gUnk_03002C30[i + 11].unk22 = i + 12;
    }
    gUnk_03002C30[10].unk22 = 0xFF;
    gUnk_03002C30[21].unk22 = 0xFF;

    for (i = 0; i <= 3; i++)
    {
        init_battle_sprite_entry_08048818(i + 22, 0xCC00, 0, i, 1);
        gUnk_03002C30[i + 22].unk4 = 0x40;
    }
    gUnk_03002C30[22].unk2 = 0x10;
    gUnk_03002C30[22].unkB = 8;
    gUnk_03002C30[23].unk2 = 0xD0;
    gUnk_03002C30[23].unkB = 8;
    gUnk_03002C30[24].unk2 = 0x10;
    gUnk_03002C30[24].unkB = 4;
    gUnk_03002C30[24].unk4 = 0x30;
    gUnk_03002C30[25].unk2 = 0xD0;
    gUnk_03002C30[25].unkB = 6;

    for (i = 0; i <= 3; i++)
    {
        init_battle_sprite_entry_08048818(i + 26, 0xCC08, 0x513, 0xE, 3);
        gUnk_03002C30[i + 26].unk2 = gUnk_03002C30[i + 22].unk2;
        gUnk_03002C30[i + 26].unk4 = 0x40;
    }
    gUnk_03002C30[28].unk4 = 0x38;
    gUnk_03001800_s.nextSubState = 6;
    gGameSubState = 4;
}

void load_battle_field_graphics(void)
{
    LZ77UnCompVram(gUnk_087C481C, (void *)0x02031000);
    DmaSet(3, gUnk_087C4C5C, PLTT, 0x84000068);
    LZ77UnCompVram(gUnk_085E3AC8, (void *)0x06011B00);
    LZ77UnCompVram(gUnk_085E32C0, (void *)0x06012400);
    LZ77UnCompVram(gUnk_085E1A0C, (void *)0x06012D00);
    LZ77UnCompVram(gUnk_085E0A58, (void *)0x06013600);
    DmaSet(3, gUnk_085E3AA8, PLTT + 0x200, 0x80000010);
    DmaSet(3, gUnk_085E32A0, PLTT + 0x220, 0x80000010);
    DmaSet(3, gUnk_085E19EC, PLTT + 0x240, 0x80000010);
    DmaSet(3, gUnk_085E0A38, PLTT + 0x260, 0x80000010);
    DmaSet(3, &gUnk_0807C540[0xF0], PLTT + 0x3C0, 0x80000010);
    DmaSet(3, &gUnk_0807C540[0xD0], PLTT + 0x280, 0x80000010);
    REG_BG1CNT = 0xD05;
    REG_BG2CNT = 0xE06;
    REG_BG3CNT = 0xF07;
    REG_BLDCNT = 0xC40;
    REG_BLDALPHA = 0xA0C;
    gUnk_03001800_bomb.unkC = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gUnk_03001800_bomb.unkD = 1;
    setup_screen_transition_effect_080682CC(4, 2, 0);
    REG_DISPCNT |= 0x1E00;
    gGameSubState = 1;
}

void init_battle_bg_palettes_and_layers(void)
{
    DmaSet(3, gUnk_087C4DFC, PLTT, 0x84000030);
    DmaSet(3, &gUnk_0807C540[0xE0], PLTT + 0x200, 0x80000010);
    DmaSet(3, &gUnk_0807C540[0xC0], PLTT + 0x220, 0x80000010);
    DmaSet(3, &gUnk_0807C540[0x80], PLTT + 0x300, 0x80000040);
    DmaSet(3, &gUnk_0807C540[0], PLTT + 0x380, 0x80000040);
    REG_BG1CNT = 0x1509;
    REG_BG2CNT = 0x160A;
    REG_BG3CNT = 0x170B;
    REG_BLDCNT = 0x1C42;
    REG_BLDALPHA = 0x80A;

    init_battle_sprite_entry_08048818(6, 0xC800, 0x508, 8, 3);
    gUnk_03002C30[6].unk2 = 0x40;
    gUnk_03002C30[6].unk4 = 0x42;
    gUnk_03002C30[6].unkB = 0x24;
    init_battle_sprite_entry_08048818(7, 0xC800, 0x509, 8, 3);
    gUnk_03002C30[7].unk2 = 0x38;
    gUnk_03002C30[7].unk4 = 0x3A;
    gUnk_03002C30[7].unkB = 0x28;
    init_battle_sprite_entry_08048818(8, 0xC800, 0x50A, 8, 3);
    gUnk_03002C30[8].unk2 = 0x44;
    gUnk_03002C30[8].unk4 = 0x3A;
    gUnk_03002C30[8].unkB = 0x1C;
    init_battle_sprite_entry_08048818(9, 0xC800, 0x50B, 8, 3);
    gUnk_03002C30[9].unk2 = 0x40;
    gUnk_03002C30[9].unk4 = 0x42;
    gUnk_03002C30[9].unkB = 0x20;
    init_battle_sprite_entry_08048818(2, 0xC800, 0x500, 8, 3);
    gUnk_03002C30[2].unk2 = 0x50;
    gUnk_03002C30[2].unk4 = -0x30;
    gUnk_03002C30[2].unkB = 0x25;
    init_battle_sprite_entry_08048818(1, 0xC800, 0x50C, 1, 3);
    gUnk_03002C30[1].unk2 = 0x50;
    gUnk_03002C30[1].unk4 = -0x30;
    gUnk_03002C30[1].unkB = 0x30;
    init_battle_sprite_entry_08048818(3, 0xC800, 0x501, 8, 3);
    gUnk_03002C30[3].unk2 = 0x28;
    gUnk_03002C30[3].unk4 = -0x30;
    gUnk_03002C30[3].unkB = 0x29;
    init_battle_sprite_entry_08048818(4, 0xC800, 0x502, 8, 3);
    gUnk_03002C30[4].unk2 = 0x54;
    gUnk_03002C30[4].unk4 = -0x30;
    gUnk_03002C30[4].unkB = 0x1D;
    init_battle_sprite_entry_08048818(5, 0xC800, 0x503, 8, 3);
    gUnk_03002C30[5].unk2 = 0x50;
    gUnk_03002C30[5].unk4 = -0x30;
    gUnk_03002C30[5].unkB = 0x29;

    gUnk_03001800_bomb.unkC = 1;
    gUnk_03001800_bomb.unkD = 0;
    setup_screen_transition_effect_080682CC(4, 2, 0);
    REG_DISPCNT |= 0x1E00;
    gGameSubState = 1;
}

void sub_08070EB8(void)
{
    play_song(4);
    sub_08071C40(1, 0, 0);
    sub_08071C40(2, 11, 0);
    gGameSubState++;
}

void sub_08070EE4(void)
{
    if (gUnk_03002C30[10].unk22 == 0)
    {
        sound_channel_set_note(0x16, 0x2D, 8);
        sound_channel_set_note(0x17, 0x36, 8);
        sub_08071C40(5, 0x16, 0x48);
        sub_08071C40(6, 0x17, 0x48);
        gGameSubState++;
    }
}

void sub_08070F34(void)
{
    if (gUnk_03002C30[22].unk20 == 0)
    {
        sound_channel_stop_0807175C(0x16, 0x27);
        sound_channel_stop_0807175C(0x17, 0x33);
        sound_channel_set_note(0x18, 0x45, 8);
        sub_08071C40(7, 0x18, 0x60);
        gGameSubState++;
    }
}

void sub_08070F7C(void)
{
    if (gUnk_03002C30[24].unk20 == 0)
    {
        sound_channel_set_note(0x18, 0x3F, 0xC);
        sound_channel_set_note(0x19, 0x4E, 8);
        sub_08071C40(6, 0x19, 0x60);
        gGameSubState++;
    }
}

void sub_08070FC0(void)
{
    if (gUnk_03002C30[25].unk20 == 0)
    {
        sound_channel_stop_0807175C(0x19, 0x4B);
        gGameSubState++;
    }
}

void sub_08070FEC(void)
{
    switch (gUnk_03001800_s.timer) {
    case 0:
        text_window_init(1, 0, 0);
        sound_channel_set_note(0x19, 0x4B, 8);
        gUnk_03001800_s.timer++;
        break;
    case 2:
        sub_0803FB0C();
        sound_channel_stop_0807175C(0x19, 0x4B);
        sound_channel_set_note(0x16, 0x2D, 8);
        gUnk_03001800_s.timer++;
        break;
    case 4:
        sub_0803FB0C();
        sound_channel_stop_0807175C(0x16, 0x2D);
        sound_channel_set_note(0x19, 0x4E, 8);
        gUnk_03001800_s.timer++;
        break;
    case 6:
        sub_0803FB0C();
        sound_channel_stop_0807175C(0x19, 0x4B);
        sound_channel_set_note(0x17, 0x36, 8);
        gUnk_03001800_s.timer++;
        break;
    case 8:
        sub_0803FB0C();
        sound_channel_stop_0807175C(0x17, 0x36);
        sound_channel_set_note(0x19, 0x51, 8);
        gUnk_03001800_s.timer++;
        break;
    case 10:
        sub_0803FB0C();
        sound_channel_stop_0807175C(0x19, 0x4B);
        sound_channel_set_note(0x16, 0x2D, 8);
        gUnk_03001800_s.timer++;
        break;
    case 12:
        sub_0803FB0C();
        sound_channel_stop_0807175C(0x16, 0x2D);
        sound_channel_set_note(0x19, 0x4B, 8);
        gUnk_03001800_s.timer++;
        break;
    case 14:
        sub_0803FB0C();
        sound_channel_stop_0807175C(0x16, 0x27);
        sound_channel_stop_0807175C(0x17, 0x33);
        sound_channel_stop_0807175C(0x19, 0x4B);
        sound_channel_set_note(0x18, 0x3F, 6);
        gUnk_03001800_s.timer++;
        break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
    case 11:
    case 13:
    case 15:
        if (run_message(gUnk_084872DC[gUnk_03001800_s.timer >> 1]))
            gUnk_03001800_s.timer++;
        break;
    default:
        sound_channel_set_note(0x18, 0x3F, 0xC);
        gUnk_03001800_s.timer = 0;
        gUnk_03001800_s.nextSubState = 0xC;
        gGameSubState = 2;
        break;
    }
}

// Not called (dead code after sub_08070FEC).
void sub_08071150(void)
{
    u32 zero = 0;

    DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
    gUnk_03001800_s.nextSubState = 0xD;
    gGameSubState = 5;
}

void sub_0807118C(void)
{
    switch (gUnk_03001800_s.timer) {
    case 0:
        text_window_init(1, 0, 0);
        gUnk_03001800_s.timer++;
        break;
    case 4:
    case 8:
    case 12:
    case 16:
    case 20:
    case 24:
        sub_0803FB0C();
        gUnk_03001800_s.timer++;
        break;
    case 1:
    case 5:
    case 9:
    case 13:
    case 17:
    case 21:
        if (run_message(gUnk_084872DC[(gUnk_03001800_s.timer >> 2) + 8])) {
            sub_0803FB0C();
            run_message(gUnk_08486114);
            gUnk_03001800_s.timer++;
        }
        break;
    case 25:
        if (run_message(gUnk_084872DC[(gUnk_03001800_s.timer >> 2) + 8]))
            gUnk_03001800_s.timer++;
        break;
    case 2:
    case 6:
    case 10:
    case 14:
    case 18:
        gUnk_03001800_s.timer++;
        break;
    case 22:
        init_battle_sprite_entry_08048818(0, 0xC800, 0x50F, 0, 3);
        gUnk_03002C30[0].unk2 = 0x42;
        gUnk_03002C30[0].unk4 = -8;
        gUnk_03002C30[0].unkB = 0x40;
        gUnk_03002C30[0].unk1A = 0;
        gUnk_03001800_s.timer++;
        break;
    case 3:
    case 7:
    case 11:
    case 15:
    case 19:
    case 23:
        if (call_battle_handler_by_state_08071C64())
            gUnk_03001800_s.timer++;
        break;
    default:
        setup_screen_transition_effect_080684F0(4, 2, 0);
        gUnk_03001800_s.timer = 0;
        gUnk_03001800_s.nextSubState = 0xE;
        gGameSubState = 2;
        break;
    }
}

void sub_080712E8(void)
{
    u32 zero = 0;
    s32 i;
    u32 z;

    DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
    init_battle_sprite_entry_08048818(0, 0xCC00, 0x50E, 4, 3);
    gUnk_03002C30[0].unk2 = 0xD4;
    gUnk_03002C30[0].unk4 = 0;
    gUnk_03002C30[0].unkB = 0x4A;
    gUnk_03002C30[10].unk22 = 0xFF;
    init_battle_sprite_entry_08048818(0xB, 0xCC00, 0x50E, 4, 3);
    gUnk_03002C30[11].unk2 = 0x14;
    gUnk_03002C30[11].unk4 = 0;
    gUnk_03002C30[11].unkB = 0x4A;
    gUnk_03002C30[21].unk22 = 0xFF;
    for (i = 0; i < 4; i++) {
        init_battle_sprite_entry_08048818(i + 0x16, 0xCC00, (u16)(i * 12 + 0x27), i, 1);
        gUnk_03002C30[i + 0x16].unk4 = 0x48;
    }
    gUnk_03002C30[0x16].unk2 = 0x58;
    gUnk_03002C30[0x16].unkB = 8;
    gUnk_03002C30[0x17].unk2 = 0x88;
    gUnk_03002C30[0x17].unkB = 8;
    gUnk_03002C30[0x18].unk2 = 0x70;
    gUnk_03002C30[0x18].unkB = 0xC;
    gUnk_03002C30[0x18].unk4 = 0x24;
    gUnk_03002C30[0x19].unk2 = 0x70;
    gUnk_03002C30[0x19].unkB = 4;
    for (i = 0; i < 4; i++) {
        init_battle_sprite_entry_08048818(i + 0x1A, 0xCC08, 0x513, 0xE, 3);
        gUnk_03002C30[i + 0x1A].unk2 = gUnk_03002C30[i + 0x16].unk2;
        gUnk_03002C30[i + 0x1A].unk4 = 0x48;
    }
    z = 0;
    gUnk_03002C30[0x1C].unk4 = 0x38;
    gUnk_03007010 = 0;
    sound_channel_set_note(0x18, 0x3F, 0xC);
    gUnk_03000430 = z;
    gUnk_03001800_s.nextSubState = 0xF;
    gGameSubState = 4;
}

void battle_audio_phase_dispatch(void)
{
    switch (gUnk_03001800_s.timer) {
    case 0:
        text_window_init(1, 0, 0);
        sound_channel_set_note(0x19, 0x4B, 8);
        gUnk_03001800_s.timer++;
        break;
    case 2:
        sub_0803FB0C();
        sound_channel_stop_0807175C(0x19, 0x4B);
        sound_channel_set_note(0x17, 0x36, 8);
        gUnk_03001800_s.timer++;
        break;
    case 4:
        sub_0803FB0C();
        sound_channel_stop_0807175C(0x17, 0x36);
        sound_channel_set_note(0x19, 0x4B, 8);
        gUnk_03001800_s.timer++;
        break;
    case 6:
        sub_0803FB0C();
        sound_channel_stop_0807175C(0x17, 0x33);
        sound_channel_stop_0807175C(0x19, 0x4B);
        sound_channel_set_note(0x18, 0x3F, 6);
        gUnk_03001800_s.timer++;
        break;
    case 1:
    case 3:
    case 5:
    case 7:
        if (run_message(gUnk_084872DC[(gUnk_03001800_s.timer >> 1) + 15]))
            gUnk_03001800_s.timer++;
        break;
    default:
        gUnk_03001800_s.timer = 0;
        sound_channel_set_note(0x16, 0x27, 8);
        sound_channel_set_note(0x17, 0x33, 8);
        sound_channel_set_note(0x19, 0x4B, 8);
        sub_08071C40(3, 0, 0);
        sub_08071C40(4, 0xB, 0);
        gGameSubState++;
        break;
    }
}

void check_sprite_done_and_advance_battle(void)
{
    if (gUnk_03002C30[10].unk22 == 0) {
        sound_stop_all_with_fade_guard(0x20);
        gUnk_03001800_s.nextSubState = 0x11;
        gGameSubState = 2;
    }
}

void sub_08071600(void)
{
    play_song(0);
    sub_08047850(3);
}

void sub_08071614(void)
{
    u8 i;

    for (i = 0; i < 0x1A; i++) {
        if (gUnk_03002C30[i].unk20 != 0) {
            gUnk_03002C30[i].unk1A++;
            switch (gUnk_08486118[gUnk_03002C30[i].unk20 - 1](i)) {
            case 0:
                gUnk_03002C30[i].unk20 = 0;
                gUnk_03002C30[i].unk21 = 0;
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

INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_0807168C);

void sound_channel_set_note(u8 sprite, u16 frame, u8 arg2)
{
    u8 mask = 1 << (sprite - 0x16);

    gUnk_03007010 |= mask;
    gUnk_03002C30[sprite].unk23 = arg2;
    gUnk_03002C30[sprite].unk30 = frame;
    gUnk_03002C30[sprite].unk6 = frame;
}

void sound_channel_stop_0807175C(u8 sprite, u16 frame)
{
    u8 mask = 1 << (sprite - 0x16);

    gUnk_03007010 &= ~mask;
    gUnk_03002C30[sprite].unk23 = 0;
    gUnk_03002C30[sprite].unk6 = frame;
}

u32 sub_08071794(u8 sprite)
{
    s8 tbl[8];
    struct Unk_03002C30 *p;
    struct Unk_03002C30 *base;

    memcpy_optimized(tbl, gUnk_080AFF94, 8);
    base = gUnk_03002C30;
    p = &base[sprite];
    if (p->unk21 < 8) {
        if (p->unk1A == tbl[p->unk21]) {
            p->unk2++;
            p->unk21++;
        }
    } else {
        p->unk2++;
    }
    if (gUnk_03002C30[sprite].unk21 == 4 && gUnk_03002C30[sprite].unk22 != 0xFF)
        sub_08071C40(1, gUnk_03002C30[sprite].unk22, 0);
    if (gUnk_03002C30[sprite].unk2 == 0xC9)
        gUnk_03002C30[sprite].unk0 = (gUnk_03002C30[sprite].unk0 & 0xF7FF) | 0xC00;
    else if (gUnk_03002C30[sprite].unk2 > 0xCF)
        return 0xFF;
    return 1;
}

u32 sub_08071840(u8 sprite)
{
    s8 tbl[8];
    struct Unk_03002C30 *p;
    struct Unk_03002C30 *base;

    memcpy_optimized(tbl, gUnk_080AFF94, 8);
    base = gUnk_03002C30;
    p = &base[sprite];
    if (p->unk21 < 8) {
        if (p->unk1A == tbl[p->unk21]) {
            p->unk2--;
            p->unk21++;
        }
    } else {
        p->unk2--;
    }
    if (gUnk_03002C30[sprite].unk21 == 4 && gUnk_03002C30[sprite].unk22 != 0xFF)
        sub_08071C40(2, gUnk_03002C30[sprite].unk22, 0);
    if (gUnk_03002C30[sprite].unk2 == 0x1F)
        gUnk_03002C30[sprite].unk0 = (gUnk_03002C30[sprite].unk0 & 0xF7FF) | 0xC00;
    else if (gUnk_03002C30[sprite].unk2 < 0x19)
        return 0xFF;
    return 1;
}

INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_080718EC);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_080719EC);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_08071AF0);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_08071B44);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_08071C40);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", call_battle_handler_by_state_08071C64);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_08071C94);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_08071D14);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_08071D84);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_08071DFC);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_08071E80);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_08071F08);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_08072010);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_080720BC);
INCLUDE_ASM("asm/nonmatching/code_0806F3F0", sub_08072138);
