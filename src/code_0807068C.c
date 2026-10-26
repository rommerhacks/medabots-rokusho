#include "global.h"

void sub_0807068C(void) {
    if (gFrameCounter & 1)
        gBg3Scroll.y++;
}

void sub_080706AC(void) {
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

void medabots_weekly_update(void) {
    if (gUnk_03001800_bganim.unkC != 0)
        sub_0807068C();
    if (gUnk_03001800_bganim.unkD != 0)
        sub_080706AC();
    gMedabotsWeeklySubStates[gGameSubState]();
}

void medabots_weekly_init(void) {
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

void load_battle_bg_tilemaps(void) {
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

    for (i = 0; i <= 10; i++) {
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

    for (i = 0; i <= 3; i++) {
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

    for (i = 0; i <= 3; i++) {
        init_battle_sprite_entry_08048818(i + 26, 0xCC08, 0x513, 0xE, 3);
        gUnk_03002C30[i + 26].unk2 = gUnk_03002C30[i + 22].unk2;
        gUnk_03002C30[i + 26].unk4 = 0x40;
    }
    gUnk_03002C30[28].unk4 = 0x38;
    gUnk_03001800_s.nextSubState = 6;
    gGameSubState = 4;
}

void load_battle_field_graphics(void) {
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
    gUnk_03001800_bganim.unkC = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gUnk_03001800_bganim.unkD = 1;
    setup_screen_transition_effect_080682CC(4, 2, 0);
    REG_DISPCNT |= 0x1E00;
    gGameSubState = 1;
}

void init_battle_bg_palettes_and_layers(void) {
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

    gUnk_03001800_bganim.unkC = 1;
    gUnk_03001800_bganim.unkD = 0;
    setup_screen_transition_effect_080682CC(4, 2, 0);
    REG_DISPCNT |= 0x1E00;
    gGameSubState = 1;
}

void sub_08070EB8(void) {
    play_song(4);
    sub_08071C40(1, 0, 0);
    sub_08071C40(2, 11, 0);
    gGameSubState++;
}

void sub_08070EE4(void) {
    if (gUnk_03002C30[10].unk22 == 0) {
        sprite_cycle_anim_start(0x16, 0x2D, 8);
        sprite_cycle_anim_start(0x17, 0x36, 8);
        sub_08071C40(5, 0x16, 0x48);
        sub_08071C40(6, 0x17, 0x48);
        gGameSubState++;
    }
}

void sub_08070F34(void) {
    if (gUnk_03002C30[22].unk20 == 0) {
        sprite_cycle_anim_stop(0x16, 0x27);
        sprite_cycle_anim_stop(0x17, 0x33);
        sprite_cycle_anim_start(0x18, 0x45, 8);
        sub_08071C40(7, 0x18, 0x60);
        gGameSubState++;
    }
}

void sub_08070F7C(void) {
    if (gUnk_03002C30[24].unk20 == 0) {
        sprite_cycle_anim_start(0x18, 0x3F, 0xC);
        sprite_cycle_anim_start(0x19, 0x4E, 8);
        sub_08071C40(6, 0x19, 0x60);
        gGameSubState++;
    }
}

void sub_08070FC0(void) {
    if (gUnk_03002C30[25].unk20 == 0) {
        sprite_cycle_anim_stop(0x19, 0x4B);
        gGameSubState++;
    }
}

void sub_08070FEC(void) {
    switch (gUnk_03001800_s.timer) {
    case 0:
        text_window_init(1, 0, 0);
        sprite_cycle_anim_start(0x19, 0x4B, 8);
        gUnk_03001800_s.timer++;
        break;
    case 2:
        sub_0803FB0C();
        sprite_cycle_anim_stop(0x19, 0x4B);
        sprite_cycle_anim_start(0x16, 0x2D, 8);
        gUnk_03001800_s.timer++;
        break;
    case 4:
        sub_0803FB0C();
        sprite_cycle_anim_stop(0x16, 0x2D);
        sprite_cycle_anim_start(0x19, 0x4E, 8);
        gUnk_03001800_s.timer++;
        break;
    case 6:
        sub_0803FB0C();
        sprite_cycle_anim_stop(0x19, 0x4B);
        sprite_cycle_anim_start(0x17, 0x36, 8);
        gUnk_03001800_s.timer++;
        break;
    case 8:
        sub_0803FB0C();
        sprite_cycle_anim_stop(0x17, 0x36);
        sprite_cycle_anim_start(0x19, 0x51, 8);
        gUnk_03001800_s.timer++;
        break;
    case 10:
        sub_0803FB0C();
        sprite_cycle_anim_stop(0x19, 0x4B);
        sprite_cycle_anim_start(0x16, 0x2D, 8);
        gUnk_03001800_s.timer++;
        break;
    case 12:
        sub_0803FB0C();
        sprite_cycle_anim_stop(0x16, 0x2D);
        sprite_cycle_anim_start(0x19, 0x4B, 8);
        gUnk_03001800_s.timer++;
        break;
    case 14:
        sub_0803FB0C();
        sprite_cycle_anim_stop(0x16, 0x27);
        sprite_cycle_anim_stop(0x17, 0x33);
        sprite_cycle_anim_stop(0x19, 0x4B);
        sprite_cycle_anim_start(0x18, 0x3F, 6);
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
        sprite_cycle_anim_start(0x18, 0x3F, 0xC);
        gUnk_03001800_s.timer = 0;
        gUnk_03001800_s.nextSubState = 0xC;
        gGameSubState = 2;
        break;
    }
}

// Medabots Weekly sub-state 12 (gMedabotsWeeklySubStates); only reached through that table.
void sub_08071150(void) {
    u32 zero = 0;

    DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
    gUnk_03001800_s.nextSubState = 0xD;
    gGameSubState = 5;
}

void sub_0807118C(void) {
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

void sub_080712E8(void) {
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
    sprite_cycle_anim_start(0x18, 0x3F, 0xC);
    gUnk_03000430 = z;
    gUnk_03001800_s.nextSubState = 0xF;
    gGameSubState = 4;
}

void battle_audio_phase_dispatch(void) {
    switch (gUnk_03001800_s.timer) {
    case 0:
        text_window_init(1, 0, 0);
        sprite_cycle_anim_start(0x19, 0x4B, 8);
        gUnk_03001800_s.timer++;
        break;
    case 2:
        sub_0803FB0C();
        sprite_cycle_anim_stop(0x19, 0x4B);
        sprite_cycle_anim_start(0x17, 0x36, 8);
        gUnk_03001800_s.timer++;
        break;
    case 4:
        sub_0803FB0C();
        sprite_cycle_anim_stop(0x17, 0x36);
        sprite_cycle_anim_start(0x19, 0x4B, 8);
        gUnk_03001800_s.timer++;
        break;
    case 6:
        sub_0803FB0C();
        sprite_cycle_anim_stop(0x17, 0x33);
        sprite_cycle_anim_stop(0x19, 0x4B);
        sprite_cycle_anim_start(0x18, 0x3F, 6);
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
        sprite_cycle_anim_start(0x16, 0x27, 8);
        sprite_cycle_anim_start(0x17, 0x33, 8);
        sprite_cycle_anim_start(0x19, 0x4B, 8);
        sub_08071C40(3, 0, 0);
        sub_08071C40(4, 0xB, 0);
        gGameSubState++;
        break;
    }
}

void check_sprite_done_and_advance_battle(void) {
    if (gUnk_03002C30[10].unk22 == 0) {
        sound_stop_all_with_fade_guard(0x20);
        gUnk_03001800_s.nextSubState = 0x11;
        gGameSubState = 2;
    }
}

void sub_08071600(void) {
    play_song(0);
    sub_08047850(3);
}

void sub_08071614(void) {
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

void sub_0807168C(void) {
    u8 buf[4];
    s32 j;
    u8 mask;

    memcpy_optimized(buf, gUnk_080AFF90, 4);
    for (j = 0, mask = 1; j <= 3; j++, mask <<= 1) {
        if (gUnk_03007010 & mask) {
            s32 r = gUnk_03002C30[j + 0x16].unk32 % gUnk_03002C30[j + 0x16].unk23;
            if (r == 0) {
                if (++gUnk_03002C30[j + 0x16].unk21 > 3)
                    gUnk_03002C30[j + 0x16].unk21 = r;
                gUnk_03002C30[j + 0x16].unk6 = gUnk_03002C30[j + 0x16].unk30 + buf[gUnk_03002C30[j + 0x16].unk21];
            }
            gUnk_03002C30[j + 0x16].unk32++;
        }
    }
}

void sprite_cycle_anim_start(u8 sprite, u16 frame, u8 arg2) {
    u8 mask = 1 << (sprite - 0x16);

    gUnk_03007010 |= mask;
    gUnk_03002C30[sprite].unk23 = arg2;
    gUnk_03002C30[sprite].unk30 = frame;
    gUnk_03002C30[sprite].unk6 = frame;
}

void sprite_cycle_anim_stop(u8 sprite, u16 frame) {
    u8 mask = 1 << (sprite - 0x16);

    gUnk_03007010 &= ~mask;
    gUnk_03002C30[sprite].unk23 = 0;
    gUnk_03002C30[sprite].unk6 = frame;
}

u32 sub_08071794(u8 sprite) {
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

u32 sub_08071840(u8 sprite) {
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

u32 sub_080718EC(u8 sprite) {
    s8 tbl[12];
    struct Unk_03002C30 *base;
    struct Unk_03002C30 *s;
    struct Unk_03002C30 *p;
    u32 n;

    memcpy_optimized(tbl, gUnk_080AFF9C, 12);
    base = gUnk_03002C30;
    s = &base[sprite];
    if (s->unk21 <= 11) {
        if (s->unk1A == tbl[s->unk21]) {
            s->unk2--;
            if (++s->unk21 == 8 && s->unk22 != 0xFF) {
                if (sprite == 0) {
                    init_battle_sprite_entry_08048818(1, 0xCC00, 0x50E, 4, 3);
                    n = 1;
                } else {
                    n = sprite + 1;
                    ((void (*)())init_battle_sprite_entry_08048818)(n, 0xC800, 0x50E, 4, 3);
                }
                p = gUnk_03002C30;
                p[n].unk2 = p[sprite].unk2;
                p[n].unk4 = 0;
                p[n].unkB = p[sprite].unkB - 1;
                sub_08071C40(3, n, 0);
            }
        }
    } else {
        if (sprite == 0) {
            base[0].unk0 = (base[0].unk0 & 0xF3FF) | 0x800;
            base[1].unk0 = (base[1].unk0 & 0xF3FF) | 0x800;
        }
        if (s->unk22 == 0xFF)
            s->unk22 = 0;
        return 0;
    }
    return 1;
}

u32 sub_080719EC(u8 sprite) {
    s8 tbl[12];
    struct Unk_03002C30 *base;
    struct Unk_03002C30 *s;
    struct Unk_03002C30 *p;
    u32 n;

    memcpy_optimized(tbl, gUnk_080AFF9C, 12);
    base = gUnk_03002C30;
    s = &base[sprite];
    if (s->unk21 <= 11) {
        if (s->unk1A == tbl[s->unk21]) {
            s->unk2++;
            if (++s->unk21 == 8 && s->unk22 != 0xFF) {
                if (sprite == 11) {
                    init_battle_sprite_entry_08048818(12, 0xCC00, 0x50E, 4, 3);
                    n = 12;
                } else {
                    n = sprite + 1;
                    ((void (*)())init_battle_sprite_entry_08048818)(n, 0xC800, 0x50E, 4, 3);
                }
                p = gUnk_03002C30;
                p[n].unk2 = p[sprite].unk2;
                p[n].unk4 = 0;
                p[n].unkB = p[sprite].unkB - 1;
                sub_08071C40(4, n, 0);
            }
        }
    } else {
        if (sprite == 11) {
            s->unk0 = (s->unk0 & 0xF3FF) | 0x800;
            base[12].unk0 = (base[12].unk0 & 0xF3FF) | 0x800;
        }
        if (s->unk22 != 0xFF)
            s->unk22 = 0;
        return 0;
    }
    return 1;
}

u32 sub_08071AF0(u8 sprite) {
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *s = &base[sprite];
    u16 f;

    s->unk2++;
    base[(u16)(sprite + 4)].unk2 = s->unk2;
    if (s->unk34 <= s->unk1A) {
        f = s->unk6 / 12;
        f = f * 12;
        s->unk6 = s->unk30 = f + 3;
        sub_08071C40(8, sprite, 0);
    }
    return 1;
}

u32 sub_08071B44(u8 sprite) {
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *s = &base[sprite];
    u16 f;

    s->unk2--;
    base[(u16)(sprite + 4)].unk2 = s->unk2;
    if (s->unk34 <= s->unk1A) {
        f = s->unk6 / 12;
        f = f * 12;
        s->unk6 = s->unk30 = f + 3;
        sub_08071C40(8, sprite, 0);
    }
    return 1;
}

// Sprite effects 7 and 8 (gUnk_08486118); only reached through that table.
u32 sub_08071B98(u8 sprite) {
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *s = &base[sprite];

    s->unk2++;
    base[(u16)(sprite + 4)].unk2 = s->unk2;
    s->unk4 = 0x32 - (gSineTable[s->unk1A >> 1] >> 4);
    if (s->unk2 == 0x20)
        s->unk0 = (s->unk0 & 0xF3FF) | 0x800;
    if (s->unk34 <= s->unk1A) {
        s->unk0 = (s->unk0 & 0xF7FF) | 0xC00;
        return 0;
    }
    return 1;
}

u32 sub_08071C10(u8 sprite) {
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *s = &base[sprite];

    s->unk4++;
    base[(u16)(sprite + 4)].unk4++;
    if (s->unk1A > 7)
        return 0;
    return 1;
}

void sub_08071C40(u8 state, u8 sprite, u16 arg2) {
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *s = &base[sprite];

    s->unk20 = state;
    s->unk21 = 0;
    s->unk34 = arg2;
    s->unk1A = 0;
}

u32 call_battle_handler_by_state_08071C64(void) {
    return gUnk_08486138[gUnk_03001800_s.unk10.end.state]();
}

// Battle-end state 4 (gUnk_08486138): just moves on.
u32 sub_08071C84(void) {
    gUnk_03001800_s.unk10.end.state++;
    return 1;
}

u32 sub_08071C94(void) {
    struct Unk_03002C30 *base = gUnk_03002C30;

    if (base[2].unk4 <= 0x3D)
        base[1].unk4 = base[2].unk4 += 2;
    else if (base[2].unk4 <= 0x41)
        base[1].unk4 = base[2].unk4 += 1;
    else if (base[2].unk1A <= 0x1F)
        base[2].unk1A++;
    else if (base[2].unk2 <= 0x40) {
        clear_sprite_entry(6);
        play_sound_effect(0x54);
        base[2].unk1A = 0;
        gUnk_03001800_s.unk10.end.state++;
        return 1;
    } else
        base[1].unk2 = base[2].unk2 -= 4;
    return 0;
}

u32 sub_08071D14(void) {
    struct Unk_03002C30 *base = gUnk_03002C30;
    s16 *y = &base[3].unk4;
    u16 *t;
    s16 *x;

    if (*y <= 0x35)
        *y += 2;
    else if (*y <= 0x39)
        *y += 1;
    else if (*(t = &base[3].unk1A) <= 0x1F)
        (*t)++;
    else if (*(x = &base[3].unk2) > 0x37) {
        clear_sprite_entry(7);
        play_sound_effect(0x54);
        *t = 0;
        gUnk_03001800_s.unk10.end.state++;
        return 1;
    } else
        *x += 4;
    return 0;
}

u32 sub_08071D84(void) {
    struct Unk_03002C30 *base = gUnk_03002C30;
    s16 *y = &base[4].unk4;
    u16 *t;
    s16 *x;

    if (*y <= 0x35)
        *y += 2;
    else if (*y <= 0x39)
        *y += 1;
    else if (*(t = &base[4].unk1A) <= 0x1F)
        (*t)++;
    else if (*(x = &base[4].unk2) <= 0x44) {
        clear_sprite_entry(8);
        play_sound_effect(0x54);
        *t = 0;
        gUnk_03001800_s.unk10.end.state++;
        return 1;
    } else
        *x -= 4;
    return 0;
}

u32 sub_08071DFC(void) {
    struct Unk_03002C30 *base = gUnk_03002C30;
    s16 *y = &base[5].unk4;
    u16 *t;
    s16 *x;

    if (*y <= 0x3D)
        *y += 2;
    else if (*y <= 0x41)
        *y += 1;
    else if (*(t = &base[5].unk1A) <= 0x1F)
        (*t)++;
    else if (*(x = &base[5].unk2) <= 0x40) {
        clear_sprite_entry(9);
        play_sound_effect(0x54);
        {
            u8 *b = &base[5].unkB;
            u16 zero = 0;

            *b = 0x21;
            *t = zero;
        }
        gUnk_03001800_s.unk10.end.state++;
        return 1;
    } else
        *x -= 4;
    return 0;
}

u32 sub_08071E80(void) {
    if (gUnk_03002C30[0].unk1A++ & 1) {
        if (++gUnk_03002C30[0].unk4 == 0)
            play_sound_effect(0x59);
    }
    gUnk_03002C30[0].unk6 = ((gUnk_03002C30[0].unk1A >> 2) & 3) + 0x50F;
    if (gUnk_03002C30[0].unk4 > 0x3F) {
        play_sound_effect(7);
        gUnk_0300700C = gPaletteBackupBg;
        gUnk_03001800_s.unk10.end.step = 0;
        DmaSet(3, OBJ_PLTT, gPaletteBackupBg, 0x84000080);
        gUnk_03001800_s.unk10.end.state++;
    }
    return 0;
}

u32 sub_08071F08(void) {
    u8 t;
    u8 w;
    s32 i;
    u16 *dst = gPaletteBufferBg;

    if (gUnk_03001800_s.unk10.end.step > 0x40) {
        play_sound_effect(10);
        gUnk_03001800_s.unk10.end.state++;
    } else {
        if (gUnk_03001800_s.unk10.end.step < 0x20)
            t = 0x20 - gUnk_03001800_s.unk10.end.step;
        else
            t = gUnk_03001800_s.unk10.end.step - 0x20;
        if (gUnk_03001800_s.unk10.end.step == 0x20)
            clear_sprite_entry(0);
        if (gUnk_03001800_s.unk10.end.step == 0x14)
            play_sound_effect(0x51);
        w = 0x20 - t;
        for (i = 0; i <= 0xFF; i++) {
            dst[i] = (((gUnk_0300700C[i] & 0x1F) * t + w * 31) >> 5) +
                     ((((gUnk_0300700C[i] & 0x3E0) * t + (w * 31 << 5)) >> 5) & 0x3E0) +
                     ((((gUnk_0300700C[i] & 0x7C00) * t + (w * 31 << 10)) >> 5) & 0x7C00);
        }
        DmaSet(3, dst, OBJ_PLTT, 0x84000080);
    }
    if (gFrameCounter & 1)
        gUnk_03001800_s.unk10.end.step++;
    return 0;
}

u32 sub_08072010(void) {
    struct Unk_03002C30 *base = gUnk_03002C30;
    vu32 fill;

    if (base[1].unk1A & 4)
        base[1].unk4 = 0xC8;
    else
        base[1].unk4 = 0x42;
    if (base[1].unk1A++ > 0x1F) {
        clear_sprite_entry(1);
        init_scene_buffers_080445F4();
        fill = 0x200;
        DmaSet(3, &fill, gUnk_03002414->unkB84, 0x85000100);
        setup_scene_with_bg_and_sprites(0, 0x2A, 0x2A, 0x2A, 0x2A, 0x40, 0x42, 2, 8, 0, 0, 0);
        gUnk_03001800_s.unk10.end.state++;
    }
    return 0;
}

u32 sub_080720BC(void) {
    vu32 fill;

    fill = 0x200;
    DmaSet(3, &fill, gUnk_03002414->unkB84, 0x85000100);
    setup_scene_with_bg_and_sprites(0, 0x2A, 0x2A, 0x2A, 0x2A, 0x40, 0x42, 2, 8, 0, 1, 0);
    advance_text_display(0, 0x2D, 0);
    gUnk_03001800_s.unk10.end.state++;
    gUnk_03001800_s.unk10.end.step = 0;
    return 0;
}

u32 sub_08072138(void) {
    struct Unk_03002C30 *base;
    u8 script[13];
    vu32 fill;
    register u32 zero asm("r5"); // pinned: the original keeps a second zero (r2) for the arguments
    u32 h;
    s16 *p;

    memcpy_optimized(script, gUnk_080AFFA8, 13);
    base = gUnk_03002C30;
    p = &base[2].unk4;
    zero = 0;
    h = 0;
    *p = 0xC8;
    *&base[3].unk4 = 0xC8;
    *&base[4].unk4 = 0xC8;
    *&base[5].unk4 = 0xC8;
    fill = 0x200;
    DmaSet(3, &fill, gUnk_03002414->unkB84, 0x85000100);
    setup_scene_with_bg_and_sprites(0, 0x2A, 0x2A, 0x2A, 0x2A, 0x40, 0x42, 2, 8, h, 1, h);
    switch (script[gUnk_03001800_s.unk10.end.pos]) {
    case 0:
        if (script[gUnk_03001800_s.unk10.end.pos + 1] >= gUnk_03001800_s.unk10.end.step++)
            break;
        gUnk_03001800_s.unk10.end.pos += 2;
        gUnk_03001800_s.unk10.end.step = zero;
        break;
    case 1:
        play_sound_effect(script[gUnk_03001800_s.unk10.end.pos + 1]);
        gUnk_03001800_s.unk10.end.pos += 2;
        gUnk_03001800_s.unk10.end.step = zero;
        break;
    case 2:
        break;
    }
    if (advance_text_display(0, 0x2D, 0) != 0) {
        gUnk_03001800_s.unk10.end.state = 0;
        return 1;
    }
    return 0;
}
