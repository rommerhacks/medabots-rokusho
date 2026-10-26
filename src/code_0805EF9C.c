#include "global.h"

static inline void *vram_at(u32 off) {
    return (void *)(0x06004000 + off);
}

void test_mode_dispatch(void) {
    gUnk_08483C6C[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void silence_and_clear_vram(void) {
    u32 zero;

    play_song(0);
    zero = 0;
    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    reset_bg_scroll();
    clear_battle_sprite_slot(0, 0x80);
    REG_DISPCNT = 0x60;
    REG_BLDCNT = 0x2FF;
    REG_BLDY = 0x10;
    gGameSubState++;
}

void test_mode_load_graphics(void) {
    vu16 *bg1, *bg2, *bg3;
    u16 v;
    u32 size;
    u8 zero;
    u8 i;

    bg1 = &REG_BG1CNT;
    v = 0x1E05;
    *bg1 = v;
    bg2 = &REG_BG2CNT;
    v -= 0xFF;
    *bg2 = v;
    bg3 = &REG_BG3CNT;
    v = 0x3C07;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_08791694, *bg1);
    decompress_and_write_tilemap(gUnk_087917F4, *bg2);
    decompress_and_write_tilemap(gUnk_087919C4, *bg3);
    size = dma3_copy_or_decompress(gUnk_08790600, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, vram_at(0), size);
    lz_decompress_dispatch(gUnk_08784CB0, vram_at(size));
    gUnk_03006F74->unk36 = (size >> 5) - 1;
    zero = 0;
    CpuFastSet(gUnk_08790400, (void *)PLTT, 0x80);
    CpuFastSet(gUnk_08483AA0, (void *)(PLTT + 0x1C0), 8);
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    CpuFastSet(gUnk_084E2E58, (void *)(PLTT + 0x3C0), 8);
    gUnk_03002C30[0].unk0 = 0x8000;
    gUnk_03002C30[0].unk1C = 2;
    gUnk_03002C30[0].unkA = 0xE;
    gUnk_03002C30[0].unk6 = 6;
    gUnk_03006F74->unk5 = zero;
    gUnk_03002C30[0].unk2 = 0x14;
    gUnk_03002C30[0].unk4 = gUnk_03006F74->unk5 * 16 + 0x20;
    for (i = 0; i <= 1; i++) {
        gUnk_03002C30[i + 1].unk0 = 0x8000;
        gUnk_03002C30[i + 1].unk1C = 2;
        gUnk_03002C30[i + 1].unkA = 0xE;
        gUnk_03002C30[i + 1].unk6 = 5;
    }
    gUnk_03002C30[1].unk0 |= 0x1000;
    gUnk_03002C30[1].unk2 = 0x78;
    gUnk_03002C30[1].unk4 = 0x20;
    gUnk_03002C30[2].unk2 = 0x90;
    gUnk_03002C30[2].unk4 = 0x20;
    for (i = 0; i <= 1; i++) {
        gUnk_03002C30[i + 3].unk0 = 0x8000;
        gUnk_03002C30[i + 3].unk1C = 2;
        gUnk_03002C30[i + 3].unkA = 0xE;
        gUnk_03002C30[i + 3].unk6 = 5;
    }
    gUnk_03002C30[3].unk0 |= 0x1000;
    gUnk_03002C30[3].unk2 = 0x78;
    gUnk_03002C30[3].unk4 = 0x30;
    gUnk_03002C30[4].unk2 = 0x90;
    gUnk_03002C30[4].unk4 = 0x30;
    gGameSubState++;
}

void init_fade_screen_setup(void) {
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03006F74->unk2B = 0;
    gUnk_03006F74->unk2C = 0;
    draw_number(gUnk_03006F74->unk2B, -2, 0x10, 4, 2, (REG_BG1CNT >> 8) & 0x1F);
    draw_number(gUnk_03006F74->unk2C, -3, 0xF, 6, 2, (REG_BG1CNT >> 8) & 0x1F);
    gUnk_03006F74->unk0 = 0x20;
    REG_BLDY = gUnk_03006F74->unk0 >> 1;
    gGameSubState++;
}

void update_fade_effect(void) {
    struct Unk_03006F74 *p = gUnk_03006F74;

    if (p->unk0 != 0) {
        REG_BLDY = p->unk0-- >> 1;
    } else {
        p->unk2 = 0;
        p->unk0 = 0;
        gUnk_03006F74->unk6 = 0;
        gUnk_03006F74->unk48 = 0;
        gUnk_03006F74->unk49 = 0;
        gUnk_03006F74->unk4A = 0;
        gUnk_03006F74->unk4B = 0;
        gUnk_03002C30[0].unk0 |= 0x4000;
        gUnk_03002C30[1].unk0 |= 0x4000;
        gGameSubState++;
    }
}

void test_mode_update(void) {
    sub_08041C14(0, gFrameCounter, 0x14);
    if (gUnk_03006F74->unk48 != 0) {
        if (--gUnk_03006F74->unk48 == 0)
            play_sound_effect(2);
    }
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        if (gUnk_03006F74->unk5 != 0)
            gUnk_03006F74->unk5--;
        else
            gUnk_03006F74->unk5 = 3;
        play_song(0);
        gUnk_03006F74->unk48 = 2;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        if (gUnk_03006F74->unk5 <= 2)
            gUnk_03006F74->unk5++;
        else
            gUnk_03006F74->unk5 = 0;
        play_song(0);
        gUnk_03006F74->unk48 = 2;
    }
    gUnk_03002C30[0].unk4 = gUnk_03006F74->unk5 * 16 + 0x20;
    switch (gUnk_03006F74->unk5) {
    case 0:
        if (gFrameCounter & 8) {
            gUnk_03002C30[1].unk0 |= 0x4000;
            gUnk_03002C30[2].unk0 |= 0x4000;
        } else {
            gUnk_03002C30[1].unk0 &= 0xBFFF;
            gUnk_03002C30[2].unk0 &= 0xBFFF;
        }
        gUnk_03002C30[3].unk0 &= 0xBFFF;
        gUnk_03002C30[4].unk0 &= 0xBFFF;
        break;
    case 1:
        gUnk_03002C30[1].unk0 &= 0xBFFF;
        gUnk_03002C30[2].unk0 &= 0xBFFF;
        if (gFrameCounter & 8) {
            gUnk_03002C30[3].unk0 |= 0x4000;
            gUnk_03002C30[4].unk0 |= 0x4000;
        } else {
            gUnk_03002C30[3].unk0 &= 0xBFFF;
            gUnk_03002C30[4].unk0 &= 0xBFFF;
        }
        break;
    default:
        gUnk_03002C30[1].unk0 &= 0xBFFF;
        gUnk_03002C30[2].unk0 &= 0xBFFF;
        gUnk_03002C30[3].unk0 &= 0xBFFF;
        gUnk_03002C30[4].unk0 &= 0xBFFF;
        break;
    }
    switch (gUnk_03006F74->unk5) {
    case 0:
        if (KEYS_LO(gRepeatKeys) & 0x20) {
            if (gUnk_03006F74->unk2B != 0)
                gUnk_03006F74->unk2B--;
            else
                gUnk_03006F74->unk2B = 0x33;
            draw_number(gUnk_03006F74->unk2B, -2, 0x10, 4, 2, (REG_BG1CNT >> 8) & 0x1F);
        }
        if (KEYS_LO(gRepeatKeys) & 0x10) {
            if (gUnk_03006F74->unk2B <= 0x32)
                gUnk_03006F74->unk2B++;
            else
                gUnk_03006F74->unk2B = 0;
            draw_number(gUnk_03006F74->unk2B, -2, 0x10, 4, 2, (REG_BG1CNT >> 8) & 0x1F);
        }
        break;
    case 1:
        if (KEYS_LO(gRepeatKeys) & 0x20) {
            if (gUnk_03006F74->unk2C != 0)
                gUnk_03006F74->unk2C--;
            else
                gUnk_03006F74->unk2C = 0x75;
            draw_number(gUnk_03006F74->unk2C, -3, 0xF, 6, 2, (REG_BG1CNT >> 8) & 0x1F);
        }
        if (KEYS_LO(gRepeatKeys) & 0x10) {
            if (gUnk_03006F74->unk2C <= 0x74)
                gUnk_03006F74->unk2C++;
            else
                gUnk_03006F74->unk2C = 0;
            draw_number(gUnk_03006F74->unk2C, -3, 0xF, 6, 2, (REG_BG1CNT >> 8) & 0x1F);
        }
        break;
    }
    if (gUnk_03006F74->unk4B != 0)
        gUnk_03006F74->unk4B--;
    if (gUnk_03006F74->unk4A != 0 && gUnk_03006F74->unk4B == 0) {
        play_sound_effect(gUnk_03006F74->unk4A);
        gUnk_03006F74->unk4A = 0;
    }
    if (KEYS_LO(gNewKeys) & 1) {
        switch (gUnk_03006F74->unk5) {
        case 0:
            play_song(gUnk_080AF854[gUnk_03006F74->unk2B]);
            return;
        case 1:
            gUnk_03006F74->unk4B = 2;
            gUnk_03006F74->unk4A = gUnk_080AF888[gUnk_03006F74->unk2C];
            play_song(0);
            play_sound_effect(0);
            return;
        case 2:
            play_sound_effect(4);
            open_choice_menu(1, 0x16, 7);
            text_window_init(1, 2, 0);
            gGameSubState = 6;
            return;
        case 3:
            gUnk_03006F74->unk49 = 0;
            break;
        default:
            return;
        }
    } else if (KEYS_LO(gNewKeys) & 2) {
        gUnk_03006F74->unk49 = 1;
    } else {
        return;
    }
    play_song(0);
    gUnk_03006F74->unk0 = 0;
    gGameSubState = 5;
    gUnk_03002C30[0].unk0 &= 0xBFFF;
    gUnk_03002C30[1].unk0 &= 0xBFFF;
    gUnk_03002C30[2].unk0 &= 0xBFFF;
    gUnk_03002C30[3].unk0 &= 0xBFFF;
    gUnk_03002C30[4].unk0 &= 0xBFFF;
}

void update_fade_transition_state_0805F778(void) {
    if (gUnk_03006F74->unk0 == 1)
        play_sound_effect(gUnk_03006F74->unk49 ? 5 : 4);
    if (gUnk_03006F74->unk0 != 32) {
        gUnk_03006F74->unk0++;
        REG_BLDY = gUnk_03006F74->unk0 >> 1;
    } else {
        REG_DISPCNT &= 0xFDFF;
        gGameMode = 3;
        gGameState = 2;
        gGameSubState = 0;
        gUnk_03007008 = 1;
    }
}

void advance_substate_on_handler_complete(void) {
    if (run_message(gUnk_08485788[3]))
        gGameSubState++;
}

void sub_0805F81C(void) {
    if (poll_choice_menu()) {
        gUnk_03006F74->unk2 = 0;
        sub_0803FB0C();
        if (gUnk_03000440.unk2A == 0)
            gGameSubState = 9;
        else
            gGameSubState++;
    }
}

void sub_0805F860(void) {
    if (run_message(gUnk_08485788[16])) {
        if (gUnk_03006F74->unk2++ > 60)
            gGameSubState = 13;
    }
}

void sub_0805F898(void) {
    if (game_state_execute_handler_a())
        gGameSubState = 4;
}

void sub_0805F8B0(void) {
    if (run_message(gUnk_08485788[4])) {
        play_song(0);
        play_sound_effect(0);
        eeprom_setup_timer_irq();
        gUnk_03006F74->unk2 = 0;
        gGameSubState++;
    }
}

void sub_0805F8F0(void) {
    u8 t = gUnk_03006F74->unk2++;
    u16 err = 0;
    s8 i;

    if (t > 29 && !is_sound_playing_with_lock(4)) {
        for (i = 0; i <= 3; i++) {
            err = save_dispatch(2);
            if (err == 0)
                break;
        }
        if (err == 0) {
            sub_0803FB0C();
            gUnk_03006F74->unk2 = err;
            gGameSubState++;
        } else {
            sub_0803FB0C();
            gUnk_03006F74->unk2 = 0;
            gGameSubState = 12;
        }
    }
}

void sub_0805F974(void) {
    if (run_message(gUnk_08485788[5])) {
        if (gUnk_03006F74->unk2++ > 60)
            gGameSubState = 8;
    }
}

void sub_0805F9AC(void) {
    if (run_message(gUnk_08485788[6])) {
        if (gUnk_03006F74->unk2++ > 60)
            gGameSubState = 8;
    }
}

void clear_or_fill_bg2_tilemap(s32 a) {
    u16 buf[0x20];
    u16 *d;
    u16 *s;
    s32 i;

    if (a < 8) {
        u32 zero = 0;

        CpuFastSet(&zero, buf, 0x01000010);
        CpuSet((u8 *)VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800 + (7 - a) * 2, buf, (a + 1) & 0x1FFFFF);
        CpuSet((u8 *)VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800 + 0x2C, &buf[0x1D - a], (a + 1) & 0x1FFFFF);
    } else {
        a -= 8;
        CpuFastSet((u8 *)VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800, buf, 0x10);
        d = &buf[14];
        s = &buf[13 - a];
        for (i = 13; i >= 0; i--) {
            if (i <= a)
                *d = buf[0];
            else
                *d = *s--;
            d--;
        }
        d = &buf[15];
        s = &buf[16 + a];
        for (i = 13; i >= 0; i--) {
            if (i <= a)
                *d = buf[29];
            else
                *d = *s++;
            d++;
        }
    }
    for (i = 0; i < 20; i++)
        CpuFastSet(buf, (u8 *)VRAM + ((REG_BG1CNT >> 8) & 0x1F) * 0x800 + i * 0x40, 0x10);
}

void sub_0805FAF0(void) {
    gUnk_08483CA4[gGameSubState]();
    if (gFrameCounter & 1)
        gBg3Scroll.y++;
}

void sub_0805FB2C(void) {
    u32 zero = 0;

    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    sub_08059D04();
    reset_bg_scroll();
    REG_WIN0H = 0xF0;
    REG_WIN0V = 0x80;
    REG_WININ = 0x3F3F;
    REG_WINOUT = 0x2F;
    REG_DISPCNT = 0x2060;
    REG_BLDCNT = 0x2BF;
    play_song(0x12);
    REG_BLDY = 0x10;
    gGameSubState++;
}

void sub_0805FBA8(void) {
    vu16 *bg0, *bg1, *bg2, *bg3;
    u16 v;
    u32 size;
    u8 one;
    u8 zero8;
    u16 zero16;

    bg0 = &REG_BG0CNT;
    one = 1;
    v = 0x1F04;
    *bg0 = v;
    bg1 = &REG_BG1CNT;
    v -= 0xFF;
    *bg1 = v;
    bg2 = &REG_BG2CNT;
    v -= 0xFF;
    *bg2 = v;
    bg3 = &REG_BG3CNT;
    v = 0x3C07;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_087962E8, *bg0);
    decompress_and_write_tilemap(gUnk_08796474, *bg2);
    decompress_and_write_tilemap(gUnk_08796598, *bg3);
    size = dma3_copy_or_decompress(gUnk_0879579C, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, vram_at(0), size);
    lz_decompress_dispatch(gUnk_08784CB0, vram_at(size));
    gUnk_03006F74->unk36 = (size >> 5) - 1;
    zero8 = 0;
    zero16 = 0;
    CpuFastSet(gUnk_0879559C, (void *)PLTT, 0x80);
    CpuFastSet(gUnk_080AF900, (void *)(PLTT + 0x200), 0x10);
    lz_decompress_dispatch(gUnk_08785F34, (void *)0x06010000);
    gUnk_03002C30[0].unk0 = 0x8A20;
    gUnk_03002C30[0].unk1C = 2;
    gUnk_03002C30[0].unk2 = 0x78;
    gUnk_03002C30[0].unk4 = -0x20;
    gUnk_03002C30[0].unkA = zero8;
    gUnk_03002C30[0].unk6 = 0x108;
    gUnk_03002C30[0].unk8 = 0x80;
    gUnk_03002C30[0].unk9 = 0x80;
    gUnk_03002C30[0].unk18 = zero16;
    gUnk_03002C30[1].unk0 = 0x8220;
    gUnk_03002C30[1].unk1C = 2;
    gUnk_03002C30[1].unk2 = 0x78;
    gUnk_03002C30[1].unk4 = -0x40;
    gUnk_03002C30[1].unkA = one;
    gUnk_03002C30[1].unk6 = 0x109;
    gUnk_03002C30[1].unk8 = 0x80;
    gUnk_03002C30[1].unk9 = 0x80;
    gUnk_03002C30[1].unk18 = zero16;
    gUnk_03006F74->unk2 = zero16;
    gUnk_03006F74->unk15 = 0x3C;
    gUnk_03006F74->unk16 = zero8;
    gGameSubState++;
}

void sub_0805FD1C(void) {
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03006F74->unk0 = 0x20;
    REG_BLDY = gUnk_03006F74->unk0 >> 1;
    gGameSubState++;
}

void sub_0805FD60(void) {
    struct Unk_03006F74 *p = gUnk_03006F74;

    if (p->unk0 != 0) {
        REG_BLDY = p->unk0-- >> 1;
    } else {
        p->unk2 = 0;
        gUnk_03002C30[1].unk0 |= 0x4000;
        gUnk_03002C30[1].unk1A = 0;
        gGameSubState++;
    }
}

void sub_0805FDB4(void) {
    struct Unk_03002C30 *s = gUnk_03002C30;
    u32 c = s[1].unk1A;
    u16 zero;

    s[1].unk6 = (c & 4) ? 0x109 : 0x10A;
    zero = 0;
    c = (u16)c;
    if ((u16)c < 0x78) {
        s[1].unk4 = (s32)(s[1].unk1A * 0xA8) / 0x78 - 0x40;
        s[1].unk8 = -0x80 - (s32)(s[1].unk1A * 64) / 0x78;
        s[1].unk9 = -0x80 - (s32)(s[1].unk1A * 64) / 0x78;
        s[1].unk18 = (c & 0x3F) * 16 + 0x340;
        s[1].unk1A = c + 1;
    } else {
        REG_DISPCNT |= 0x100;
        s[1].unk6 = 0x10B;
        s[1].unk8 = 0x40;
        s[1].unk9 = 0x40;
        s[1].unk4 = 0x68;
        s[1].unk18 = zero;
        s[1].unk1A = zero;
        gUnk_03006F74->unk3A = zero;
        gGameSubState++;
    }
}

void sub_0805FE90(void) {
    u32 done = 0;
    struct Unk_03006F74 *p = gUnk_03006F74;
    u16 t;
    u16 y;

    if (p->unk3A <= 7) {
        if (++p->unk3A == 4) {
            REG_DISPCNT &= 0xFEFF;
            REG_DISPCNT |= 0x200;
            play_sound_effect(0x17);
        }
        if (gUnk_03006F74->unk3A <= 3)
            gUnk_03002C30[1].unk4--;
        else
            gUnk_03002C30[1].unk4++;
    } else {
        if ((u16)p->unk3A <= 0x31)
            p->unk3A++;
        t = gUnk_03006F74->unk3A - 9;
        if (t == 0)
            gUnk_03002C30[0].unk0 |= 0x4000;
        if (t <= 0x13) {
            s32 q = (t << 6) / 20;

            y = q - 0x20;
            gUnk_03002C30[0].unk9 = gUnk_03002C30[0].unk8 = -0x80 - q;
        } else {
            t -= 0x14;
            if (t == 0) {
                gUnk_03002C30[0].unk8 = 0x40;
                gUnk_03002C30[0].unk9 = 0x40;
            }
            if (t <= 0xC)
                y = gUnk_080AF95A[t] + 0x20;
            else {
                y = 0x20;
                t -= 0xD;
                if (t <= 7)
                    clear_or_fill_bg2_tilemap(t);
                else
                    done = 1;
            }
        }
        gUnk_03002C30[0].unk4 = y;
    }
    if (++gUnk_03002C30[1].unk1A > 0x47)
        gUnk_03002C30[1].unk1A = 0;
    gUnk_03002C30[1].unk6 = gUnk_080AF942[gUnk_03002C30[1].unk1A / 6];
    if ((KEYS_LO(gNewKeys) & 1) && done) {
        gUnk_03002C30[1].unk0 = 0xCA20;
        gUnk_03006F74->unk3A = 0;
        gGameSubState += 2;
    }
}

void sub_08060018(void) {
    if (gUnk_03006F74->unk0 != 32) {
        gUnk_03006F74->unk0++;
        REG_BLDY = gUnk_03006F74->unk0 >> 1;
    } else {
        REG_DISPCNT &= 0xFDFF;
        gGameMode = 3;
        gGameState = 0;
        gGameSubState = 0;
    }
}

void sub_0806006C(void) {
    struct Unk_03006F74 *p = gUnk_03006F74;

    p->unk3A++;
    clear_or_fill_bg2_tilemap(p->unk3A + 8);
    if (++gUnk_03002C30[1].unk1A > 0x47)
        gUnk_03002C30[1].unk1A = 0;
    gUnk_03002C30[1].unk6 = gUnk_080AF968[(u16)(gUnk_03002C30[1].unk1A / 6)];
    p = gUnk_03006F74;
    if (p->unk3A > 13) {
        p->unk0 = 0;
        gGameSubState--;
    }
}

void sub_080600E0(void) {
    if (++gUnk_03002C30[0].unk1A > 0x3F)
        gUnk_03002C30[0].unk1A = 0;
    gUnk_03002C30[0].unk6 = gUnk_080AF980[(gUnk_03002C30[0].unk1A >> 3) & 7] + 0x100;
}

void save_lost_dispatch(void) {
    gUnk_08483CC4[gGameSubState]();
    if (gFrameCounter & 1)
        gBg3Scroll.y--;
}

void sub_08060154(void) {
    u32 zero = 0;

    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    reset_bg_scroll();
    clear_battle_sprite_slot(0, 0x80);
    REG_DISPCNT = 0x60;
    REG_BLDCNT = 0x2FF;
    REG_BLDY = 0x10;
    gGameSubState++;
}

void sub_080601A4(void) {
    s32 size;
    vu16 *bg0, *bg1, *bg3;
    u16 v;

    bg0 = &REG_BG0CNT;
    v = 0x1F04;
    *bg0 = v;
    bg1 = &REG_BG1CNT;
    v -= 0xFF;
    *bg1 = v;
    bg3 = &REG_BG3CNT;
    v = 0x3C07;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_08792CD0, *bg0);
    decompress_and_write_tilemap(gUnk_08792E6C, *bg1);
    decompress_and_write_tilemap(gUnk_08792FC4, *bg3);
    size = dma3_copy_or_decompress(gUnk_08791D88, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)0x06004000, size);
    gUnk_03006F74->unk36 = size / 32 - 1;
    CpuFastSet(gUnk_08791CA8, (void *)PLTT, 0x38);
    CpuFastSet(gUnk_080AF988, (void *)(PLTT + 0x200), 8);
    lz_decompress_dispatch(gUnk_08785F34, (void *)0x06010000);
    gUnk_03002C30[0].unk0 = 0xC000;
    gUnk_03002C30[0].unk1C = 2;
    gUnk_03002C30[0].unkA = 0;
    gUnk_03002C30[0].unk6 = 0x112;
    gUnk_03002C30[0].unk2 = 0x70;
    gUnk_03002C30[0].unk4 = 0x18;
    gUnk_03002C30[0].unk1A = 0;
    gGameSubState++;
}

void sub_08060298(void) {
    REG_DISPCNT |= 0x100;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03006F74->unk0 = 0x20;
    REG_BLDY = gUnk_03006F74->unk0 >> 1;
    gGameSubState++;
}

void sub_080602F4(void) {
    struct Unk_03006F74 *p = gUnk_03006F74;

    if (p->unk0 != 0)
        REG_BLDY = p->unk0-- >> 1;
    else
        gGameSubState++;
}

void sub_08060324(void) {
    sub_080600E0();
    if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        gUnk_03006F74->unk0 = 0;
        gGameSubState++;
    }
}

void sub_0806035C(void) {
    sub_080600E0();
    if (gUnk_03006F74->unk0 != 32) {
        gUnk_03006F74->unk0++;
        REG_BLDY = gUnk_03006F74->unk0 >> 1;
    } else {
        REG_DISPCNT &= 0xFDFF;
        gGameSubState++;
    }
}

void sub_080603A4(void) {
    u16 buf[4];
    u32 r = is_sound_playing_with_lock(4);
    u16 ie;
    u32 zero;
    s32 i;

    if (r == 0) {
        REG_IME = r;
        ie = REG_IE;
        REG_IE = 0x2020;
        REG_IME = 1;
        zero = r;
        CpuSet(&zero, buf, 0x05000002);
        for (i = 0; i <= 3; i++) {
            if (ProgramEepromDwordEx(0, buf) == 0)
                break;
        }
        REG_IE |= ie;
        gGameMode = 3;
        gGameState = 2;
        gGameSubState = 0;
        gUnk_03007008 = 1;
    }
}

void town_map_update_cursor(void) {
    u8 row = gUnk_03006F74->unk18;
    const u8 *t;

    if (++gUnk_03002C30[0].unk1A > 0x60)
        gUnk_03002C30[0].unk1A = 0;
    t = (const u8 *)gUnk_08483DC0;
    gUnk_03002C30[0].unk2 = t[gUnk_03006F74->unk17 * 2] * 8 + gUnk_08483DD4[row][(gUnk_03002C30[0].unk1A >> 3) & 3];
    gUnk_03002C30[0].unk4 =
        t[(u16)(gUnk_03006F74->unk17 * 2 + 1)] * 8 + gUnk_08483DE4[row][(gUnk_03002C30[0].unk1A >> 3) & 3];
    gUnk_03002C30[0].unk6 = gUnk_08483DF4[row][(gUnk_03002C30[0].unk1A >> 3) & 3];
}

void update_animation_timer(void) {
    s32 t;

    if ((u16)++gUnk_03006F74->unk3A > 0x6D)
        gUnk_03006F74->unk3A = 0;
    t = gUnk_03006F74->unk3A;
    if ((s16)(t % 10) == 0)
        CpuSet(gDecompressBuffer + (gUnk_08483E04[(s16)(t / 10)] + 1) * 480, (void *)0x06004020, 0xF0);
}

void town_map_dispatch(void) {
    gUnk_08483DA0[gGameSubState]();
}

void copy_bg2_tilemap_to_ewram(void) {
    u32 zero;

    CpuFastSet((void *)0x06002800, (void *)0x02020800, 0x28);
    zero = 0;
    CpuFastSet(&zero, (void *)0x06002800, 0x01000200);
    reset_bg_scroll();
    sub_08059D04();
    REG_DISPCNT = 0x60;
    REG_BLDCNT = 0x2FF;
    REG_BLDY = 0x10;
    gGameSubState++;
}

void town_map_load_graphics(void) {
    u32 size;
    u32 off;
    register u32 cb asm("r5");
    u8 i;
    vu16 tmp;
    vu16 *bg1, *bg2, *bg3;
    u16 v;
    struct Unk_03006F74 *p;

    cb = 1;
    bg1 = &REG_BG1CNT;
    v = 0x1E05;
    *bg1 = v;
    bg2 = &REG_BG2CNT;
    v -= 0xFF;
    *bg2 = v;
    bg3 = &REG_BG3CNT;
    v -= 0xFF;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_0878A844, *bg1);
    decompress_and_write_tilemap(gUnk_0878A918, *bg2);
    decompress_and_write_tilemap(gUnk_0878AA0C, *bg3);
    {
        struct Unk_03006F74 *q;
        if (gGameState == 0x17) {
            q = gUnk_03006F74;
            q->unk18 = 1;
        } else {
            *(u16 *)(((*bg3 >> 8) & 0x1F) * 0x800 + (VRAM + 0x248)) =
                *(u16 *)(((*bg3 >> 8) & 0x1F) * 0x800 + (VRAM + 0x21E));
            q = gUnk_03006F74;
            q->unk18 = 0;
        }
    }
    switch (gUnk_030057E0.unkC32) {
    case 0:
        for (i = 0; i <= 2; i++) {
            tmp = 0;
            CpuSet((void *)&tmp, (u16 *)(VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800) + 13 + (i + 10) * 32, 0x01000005);
        }
    case 1:
        for (i = 0; i <= 2; i++) {
            tmp = 0;
            CpuSet((void *)&tmp, (u16 *)(VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800) + 8 + (i + 4) * 32, 0x01000005);
        }
        break;
    }
    off = cb << 14;
    size = dma3_copy_or_decompress(gUnk_087877C4, gDecompressBuffer);
    CpuFastSet(gDecompressBuffer, (void *)(VRAM + off), (size / 4) & 0x1FFFFF);
    lz_decompress_dispatch(gUnk_08784CB0, (void *)(VRAM + off + size));
    gUnk_03006F74->unk36 = size / 32 - 1;
    CpuFastSet(gUnk_087871E4, (void *)PLTT, 0x70);
    lz_decompress_dispatch(gUnk_08785F34, (void *)0x06010000);
    CpuFastSet(gUnk_080AF9A8, (void *)(PLTT + 0x200), 0x18);
    gUnk_03006F74->unk17 = gUnk_08483CE0[gUnk_030057E0.unk7FE];
    gUnk_03002C30[0].unk0 = 0xC000;
    gUnk_03002C30[0].unk1C = 2;
    gUnk_03002C30[0].unk4 = 0x3C;
    p = gUnk_03006F74;
    gUnk_03002C30[0].unkA = p->unk18;
    gUnk_03002C30[0].unk6 = 0x10D;
    gUnk_03002C30[0].unk1A = 0;
    gUnk_03002C30[1].unk0 = 0xC000;
    gUnk_03002C30[1].unk1C = 2;
    gUnk_03002C30[1].unk2 = gUnk_08483DC0[0][p->unk17 * 2] * 8;
    gUnk_03002C30[1].unk4 = gUnk_08483DC0[0][p->unk17 * 2 + 1] * 8;
    gUnk_03002C30[1].unkA = 2;
    gUnk_03002C30[1].unk6 = 0x10E;
    gUnk_03002C30[0].unk2 = gUnk_08483DC0[0][p->unk17 * 2] * 8;
    gUnk_03002C30[0].unk4 = gUnk_08483DC0[0][p->unk17 * 2 + 1] * 8;
    dma3_copy_or_decompress(gUnk_087873A4, (void *)0x020301E0);
    gGameSubState++;
}

void sub_08060804(void) {
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03006F74->unk0 = 8;
    REG_BLDY = gUnk_03006F74->unk0 * 2;
    gUnk_03006F74->unk3A = 0;
    gGameSubState++;
}

void sub_0806086C(void) {
    struct Unk_03006F74 *p = gUnk_03006F74;

    if (p->unk0 != 0) {
        REG_BLDY = --p->unk0 * 2;
    } else {
        p->unk2 = 0;
        text_window_init(1, 2, 0);
        gGameSubState++;
    }
    town_map_update_cursor();
    update_animation_timer();
}

void sub_080608B4(void) {
    u8 i = gUnk_03006F74->unk17;
    if (run_message(gUnk_08485504[i]))
        gGameSubState++;
    town_map_update_cursor();
    update_animation_timer();
}

void sub_080608EC(void) {
    u8 keys;

    town_map_update_cursor();
    update_animation_timer();
    if (sub_0805B7A0() == 0) {
        if (!((keys = KEYS_LO(gNewKeys)) & 3))
            return;
        if (gGameState == 10) {
            play_sound_effect(5);
            gUnk_03006F74->unk48 = 1;
        } else if (keys & 1) {
            play_sound_effect(4);
            gUnk_03006F74->unk48 = 1;
        } else {
            play_sound_effect(5);
            gUnk_03006F74->unk48 = 0;
        }
        gUnk_03006F74->unk0 = 0;
        gGameSubState++;
    } else {
        sub_0803FB0C();
        gGameSubState = 4;
    }
}

void sub_0806098C(void) {
    town_map_update_cursor();
    update_animation_timer();
    if (game_state_execute_handler_a()) {
        copy_obj_palette_to_buffer();
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

void sub_080609C0(void) {
    struct Unk_03000440 *s;
    u8 *n;

    town_map_update_cursor();
    update_animation_timer();
    s = &gUnk_03000440;
    n = &s->unk84;
    if (*n <= 8) {
        blend_obj_palettes_to_color_0803F684(0, *n * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, *n * 4, 0xFFFF);
        (*n)++;
    } else {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFEFF;
        CpuFastSet((void *)0x02020800, (void *)0x06002800, 0x28);
        if (gGameState == 10) {
            gGameState = 4;
            gGameSubState = 0;
        } else if (gUnk_03006F74->unk48) {
            gUnk_03006D38.unk5 = gUnk_03006F74->unk17;
            dispatch_by_index_0476e8(5);
        } else {
            dispatch_by_index_0476e8(6);
        }
    }
}

void battle_menu_highlight_icons(u32 sel, u32 frame) {
    u16 t = (s16)(sel * 4 + gUnk_03006F74->unk38 + 5) | (s16)0xC000;
    s32 i, j;
    u16 *a, *b;
    u16 pal;

    *(u16 *)(((REG_BG2CNT >> 8) & 0x1F) * 0x800 + 0x06000152) = t++;
    *(u16 *)(((REG_BG2CNT >> 8) & 0x1F) * 0x800 + 0x06000154) = t++;
    *(u16 *)(((REG_BG2CNT >> 8) & 0x1F) * 0x800 + 0x06000192) = t++;
    *(u16 *)(((REG_BG2CNT >> 8) & 0x1F) * 0x800 + 0x06000194) = t;
    for (i = 0; i < 4; i++) {
        a = (u16 *)(VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800) + gUnk_080AFA08[i][0] + gUnk_080AFA08[i][1] * 32;
        b = (u16 *)(VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800) + gUnk_080AFA08[i][0] + (gUnk_080AFA08[i][1] + 1) * 32;
        if (frame & 8)
            pal = (i == sel) ? 0x6000 : 0x5000;
        else
            pal = 0x5000;
        for (j = 0; j < 8; j++) {
            *a = (*a & 0xFFF) | pal;
            a++;
            *b = (*b & 0xFFF) | pal;
            b++;
        }
    }
}

void copy_text_with_lookup(dst, src, unused, i) u8 *dst;
u8 *src;
u32 unused;
u32 i;
{
    do {
        dst[i] = src[i];
        i++;
    } while (src[i] != 0xFF);
    dst[i] = src[i];
    i++;
    dst[i] = src[i];
    dst[2] = gUnk_080AFA10[gUnk_03002420];
}

void shop_menu_dispatch(void) {
    gUnk_08483E10[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_08060C44(void) {
    gUnk_03006F74->unk5 = 0;
    gUnk_03006F74->unk6 = 0;
    gGameSubState = 14;
}

void sub_08060C60(void) {
    gGameSubState = 1;
}

void sub_08060C6C(void) {
    u32 zero;
    vu16 *bg1, *bg2, *bg3;
    u16 v;
    u32 size;
    u32 n;
    u32 vram;
    u32 off;
    u8 *dst;

    zero = 0;
    vram = VRAM;
    CpuFastSet(&zero, (void *)vram, 0x01006000);
    reset_bg_scroll();
    clear_battle_sprite_slot(0, 0x80);
    REG_DISPCNT = 0x60;
    REG_BLDCNT = 0xC42;
    REG_BLDALPHA = 0x10;
    bg1 = &REG_BG1CNT;
    v = 0x1B05;
    *bg1 = v;
    decompress_and_write_tilemap(gUnk_08799838, *bg1);
    bg2 = &REG_BG2CNT;
    v = 0x1A06;
    *bg2 = v;
    decompress_and_write_tilemap(gUnk_087999EC, *bg2);
    v = 0x1E05;
    *bg1 = v;
    v -= 0xFF;
    *bg2 = v;
    bg3 = &REG_BG3CNT;
    v -= 0xFF;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_08798608, *bg1);
    decompress_and_write_tilemap(gUnk_08798824, *bg2);
    decompress_and_write_tilemap(gUnk_08798A34, *bg3);
    size = dma3_copy_or_decompress(gUnk_0879691C, gDecompressBuffer);
    off = 0x4000;
    CpuCopy16(gDecompressBuffer, (void *)(off + vram), size);
    n = lz_decompress_dispatch(gUnk_084C4DB0, vram_at(size));
    gUnk_03006F74->unk38 = (size >> 5) - 1;
    size += n;
    tilemap_offset_tiles_and_palette(size >> 5, 0, 0x1B);
    tilemap_offset_tiles_and_palette(size >> 5, 0, 0x1A);
    n = dma3_copy_or_decompress(gUnk_08798F2C, gDecompressBuffer);
    dst = vram_at(size);
    CpuCopy16(gDecompressBuffer, dst, n);
    gUnk_03006F74->unk36 = ((size + n) >> 5) - 1;
    lz_decompress_dispatch(gUnk_08784CB0, dst += n);
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    gGameSubState++;
}

void shop_menu_init(void) {
    u32 zero;
    u8 i;

    zero = 0;
    CpuFastSet(&zero, (void *)0x0600DA80, 0x01000080);
    clear_battle_sprite_slot(0, 0x80);
    gUnk_03002C30[8].unk0 = 0x8004;
    gUnk_03002C30[8].unk1C = 0;
    gUnk_03002C30[8].unkA = 0xE;
    gUnk_03002C30[8].unk6 = 0x307;
    gUnk_03002C30[8].unk2 = 8;
    gUnk_03002C30[8].unk4 = gUnk_03006F74->unk5 * 24 + 0x20;
    gUnk_03002C30[8].unk0 |= 0x1200;
    gUnk_03002C30[8].unk8 = 0x40;
    gUnk_03002C30[8].unk9 = 0x40;
    gUnk_03002C30[7].unk0 = 0xC000;
    gUnk_03002C30[7].unk1C = 2;
    gUnk_03002C30[7].unkA = 1;
    gUnk_03002C30[7].unk6 = 0x1A;
    gUnk_03002C30[7].unk2 = 0x98;
    gUnk_03002C30[7].unk4 = 0;
    for (i = 0; i < 4; i++) {
        gUnk_03002C30[i + 12].unk0 = 0x8000;
        gUnk_03002C30[i + 12].unk1C = 2;
        gUnk_03002C30[i + 12].unkA = 0;
    }
    gUnk_03002C30[13].unk0 |= 0x1000;
    gUnk_03002C30[15].unk0 |= 0x2000;
    gUnk_03002C30[13].unk6 = 5;
    gUnk_03002C30[14].unk6 = 5;
    gUnk_03002C30[12].unk6 = 8;
    gUnk_03002C30[15].unk6 = 8;
    gUnk_03002C30[13].unk2 = 0x48;
    gUnk_03002C30[13].unk4 = 0x2C;
    gUnk_03002C30[14].unk2 = 0x58;
    gUnk_03002C30[14].unk4 = 0x2C;
    gUnk_03002C30[12].unk2 = 0x50;
    gUnk_03002C30[12].unk4 = 0x22;
    gUnk_03002C30[15].unk2 = 0x50;
    gUnk_03002C30[15].unk4 = 0x3E;
    divide_by_10000(gUnk_030004DE, gUnk_03002B70.money);
    render_text_sprites_08040DB8(gUnk_030004DE, 0, 0x15, 1, 7, 0xF, 1, 0);
    gGameSubState++;
}

void sub_08060FD4(void) {
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    CpuFastSet(gUnk_084E2E58, (void *)0x0202F800, 8);
    CpuFastSet(gUnk_084E2E38, (void *)0x0202F9E0, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x0202F9C0, 8);
    CpuFastSet(gUnk_08488AA4, (void *)0x0202F820, 8);
    CpuFastSet(gUnk_0879671C, (void *)0x0202FA00, 0x80);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_08061080(void) {
    if (gUnk_03006F74->unk6 == 1) {
        struct Unk_03000440 *s;
        u8 *n;

        battle_menu_highlight_icons(gUnk_03006F74->unk19, 8);
        s = &gUnk_03000440;
        n = &s->unk84;
        if (*n <= 8) {
            blend_obj_palettes_to_color_0803F684(0, 0x20 - *n * 4, 0x7FFE);
            blend_obj_palettes_to_color_0803F998(0, 0x20 - *n * 4, 0x7FFD);
            (*n)++;
        } else {
            gUnk_03006F74->unk2 = 0;
            text_window_init(1, 0, 0);
            gUnk_03006F74->unk2 = 0;
            gUnk_03006F74->unk0 = 0;
            gUnk_03006F74->unk6 = 0;
            gGameSubState = 9;
        }
    } else {
        struct Unk_03000440 *s = &gUnk_03000440;
        u8 *n = &s->unk84;

        if (*n <= 8) {
            blend_obj_palettes_to_color_0803F684(0, 0x20 - *n * 4, 0xFFFF);
            blend_obj_palettes_to_color_0803F998(0, 0x20 - *n * 4, 0xFFFF);
            (*n)++;
        } else {
            gUnk_03006F74->unk2 = 0;
            gUnk_03002C30[8].unk0 |= 0x4000;
            text_window_init(1, 0, 0);
            gUnk_03006F74->unk2 = 0;
            gUnk_03006F74->unk0 = 0;
            gGameSubState++;
        }
    }
}

void sub_08061180(void) {
    u8 *buf = gUnk_03006F74->unk270;

    copy_text_with_lookup(buf, gUnk_0848552C);
    if (run_message(buf)) {
        gUnk_03002C30[8].unk0 |= 0x4000;
        gGameSubState++;
    }
}

void sub_080611D0(void) {
    sub_08041C14(8, gFrameCounter, 8);
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        play_sound_effect(2);
        if (gUnk_03006F74->unk5 != 0)
            gUnk_03006F74->unk5--;
        else
            gUnk_03006F74->unk5 = 2;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        play_sound_effect(2);
        if (gUnk_03006F74->unk5 <= 1)
            gUnk_03006F74->unk5++;
        else
            gUnk_03006F74->unk5 = 0;
    }
    gUnk_03002C30[8].unk4 = gUnk_03006F74->unk5 * 24 + 0x20;
    if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        switch (gUnk_03006F74->unk5) {
        case 0:
            gUnk_03006F74->unk2 = 0;
            gGameSubState = 8;
            gUnk_03006F74->unk6 = 0;
            battle_menu_highlight_icons(0, 0);
            break;
        case 1:
            gUnk_03006F74->unk2 = 0;
            gGameSubState = 8;
            gUnk_03006F74->unk6 = 0;
            battle_menu_highlight_icons(0, 0);
            break;
        case 2:
        cancel:
            gUnk_03000440.unk84 = 0;
            gGameSubState = 6;
            break;
        }
    } else if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        goto cancel;
    }
}

void sub_080612D8(void) {
    if (game_state_execute_handler_a()) {
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

void sub_08061300(void) {
    struct Unk_03000440 *s = &gUnk_03000440;
    u8 *n = &s->unk84;

    if (*n <= 8) {
        blend_obj_palettes_to_color_0803F684(0, *n * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, *n * 4, 0xFFFF);
        (*n)++;
    } else {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFBFF;
        REG_DISPCNT &= 0xF7FF;
        clear_battle_sprite_slot(0, 0x80);
        dispatch_by_index_0476e8(3);
    }
}

void sub_08061374(void) {
    u8 t = gUnk_03006F74->unk2++;

    if (gUnk_03002C30[8].unk8 > 4) {
        gUnk_03002C30[8].unk8 -= 4;
        gUnk_03002C30[8].unk9 -= 4;
    } else {
        gUnk_03002C30[8].unk0 &= 0xBFFF;
    }
    if (t <= 16) {
        REG_BLDALPHA = (t << 8) | (16 - t);
    } else {
        REG_BLDALPHA = 0x1000;
        REG_DISPCNT &= 0xFDFF;
        gUnk_03002C30[8].unk0 &= 0xBFFF;
        sub_0803FB0C();
        gGameSubState++;
    }
    gUnk_03006F74->unk19 = 0;
}

void sub_0806142C(void) {
    u8 buf[0x30];

    copy_text_with_lookup(buf, gUnk_03006F74->unk5 == 0 ? gUnk_08485551 : gUnk_08485580);
    if (run_message(buf))
        gGameSubState++;
}

void sub_0806146C(void) {
    s8 i;

    for (i = 0; i < 4; i++) {
        if ((gFrameCounter >> 3) & 1)
            gUnk_03002C30[12 + i].unk0 |= 0x4000;
        else if (gUnk_03006F74->unk19 == i)
            gUnk_03002C30[12 + gUnk_03006F74->unk19].unk0 &= 0xBFFF;
    }
    if (KEYS_LO(gNewKeys) & 0x40) {
        play_sound_effect(2);
        gUnk_03006F74->unk19 = 0;
        battle_menu_highlight_icons(0, gFrameCounter);
    }
    if (KEYS_LO(gNewKeys) & 0x80) {
        play_sound_effect(2);
        gUnk_03006F74->unk19 = 3;
        battle_menu_highlight_icons(3, gFrameCounter);
    }
    if (KEYS_LO(gNewKeys) & 0x20) {
        play_sound_effect(2);
        gUnk_03006F74->unk19 = 1;
        battle_menu_highlight_icons(1, gFrameCounter);
    }
    if (KEYS_LO(gNewKeys) & 0x10) {
        play_sound_effect(2);
        gUnk_03006F74->unk19 = 2;
        battle_menu_highlight_icons(2, gFrameCounter);
    }
    if (!(gFrameCounter & 7))
        battle_menu_highlight_icons(gUnk_03006F74->unk19, gFrameCounter);
    if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        for (i = 0; i < 4; i++)
            gUnk_03002C30[12 + i].unk0 |= 0x4000;
        if (gUnk_03006F74->unk19 == 4) {
        back:
            gGameSubState = 0xB;
        } else {
            gUnk_03000440.unk84 = 0;
            gUnk_03006F74->unk48 = 0x2D;
            gGameSubState = 0xC;
        }
    } else if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        for (i = 0; i < 4; i++)
            gUnk_03002C30[12 + i].unk0 &= 0xBFFF;
        REG_DISPCNT |= 0x200;
        gUnk_03002C30[8].unk0 |= 0x4000;
        gUnk_03006F74->unk2 = 0x10;
        goto back;
    }
}

void sub_08061678(void) {
    u8 t = gUnk_03006F74->unk2--;

    if (gUnk_03002C30[8].unk8 < 0x40) {
        gUnk_03002C30[8].unk8 += 4;
        gUnk_03002C30[8].unk9 += 4;
    } else {
        gUnk_03002C30[8].unk9 = 0x40;
    }
    if (t != 0) {
        REG_BLDALPHA = (t << 8) | (16 - t);
    } else {
        REG_BLDALPHA = 16;
        sub_0803FB0C();
        gGameSubState = 4;
    }
}

void sub_080616F8(void) {
    u8 *t;

    battle_menu_highlight_icons(gUnk_03006F74->unk19, gFrameCounter * 2);
    t = &gUnk_03006F74->unk48;
    if (*t != 0)
        (*t)--;
    else if (game_state_execute_handler_a()) {
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

void sub_0806174C(void) {
    struct Unk_03000440 *s = &gUnk_03000440;
    u8 *n = &s->unk84;
    s32 i;

    if (*n <= 8) {
        blend_obj_palettes_to_color_0803F684(0, *n * 4, 0xFFFE);
        blend_obj_palettes_to_color_0803F998(0, *n * 4, 0x7FFD);
        (*n)++;
    } else {
        for (i = 0; i < 4; i++)
            gUnk_03002C30[12 + i].unk0 &= 0xBFFF;
        gUnk_03006F74->unk6 = 1;
        gUnk_03006F74->unk1A = 0;
        *(u8 *)0x02023078 = 0;
        {
            u8 *b;
            u32 z = 0;
            i = 0x77;
            b = (u8 *)0x02023077;
            for (; i >= 0; i--)
                *b-- = z;
        }
        gGameState = 12;
        gGameSubState = 0;
    }
}

void shop_list_dispatch(void) {
    gUnk_08483E8C[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_08061830(void) {
    reset_bg_scroll();
    gGameSubState++;
}

void shop_list_init(void) {
    s8 i;

    REG_DISPCNT |= 0x200;
    REG_BG1CNT = 0x1B05;
    REG_BG2CNT = 0x1A06;
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    gUnk_03002C30[8].unk0 = 0x8400;
    gUnk_03002C30[8].unk1C = 2;
    gUnk_03002C30[8].unkA = 2;
    gUnk_03002C30[8].unk6 = 6;
    for (i = 0; i < 2; i++) {
        gUnk_03002C30[11 + i].unk0 = 0x8000;
        gUnk_03002C30[11 + i].unk1C = 2;
        gUnk_03002C30[11 + i].unkA = 2;
        gUnk_03002C30[11 + i].unk6 = 5;
        gUnk_03002C30[11 + i].unk2 = i * 24 + 0xD0;
        gUnk_03002C30[11 + i].unk4 = gUnk_03006F74->unk1A * 16 + 0x54;
    }
    gUnk_03002C30[11].unk0 |= 0x1000;
    for (i = 0; i < 2; i++) {
        gUnk_03002C30[0x68 + i].unk0 = 0x8400;
        gUnk_03002C30[0x68 + i].unk1C = 2;
        gUnk_03002C30[0x68 + i].unkA = 2;
        gUnk_03002C30[0x68 + i].unk6 = 8;
        gUnk_03002C30[0x68 + i].unk2 = 0x1C;
        gUnk_03002C30[0x68 + i].unk4 = i ? 0x95 : 0x44;
    }
    gUnk_03002C30[0x69].unk0 |= 0x2000;
    for (i = 0; i < 4; i++) {
        gUnk_03002C30[0x6A + i].unk0 = 0x8400;
        gUnk_03002C30[0x6A + i].unk1C = 2;
        gUnk_03002C30[0x6A + i].unkA = 3;
        gUnk_03002C30[0x6A + i].unk2 = 0x78;
        gUnk_03002C30[0x6A + i].unk4 = i * 16 + 0x50;
    }
    for (i = 0; i < 4; i++) {
        gUnk_03002C30[0x6E + i].unk0 = 0x8400;
        gUnk_03002C30[0x6E + i].unk1C = 2;
        gUnk_03002C30[0x6E + i].unkA = 3;
        gUnk_03002C30[0x6E + i].unk6 = i + 0x1D;
        gUnk_03002C30[0x6E + i].unk2 = 0x90;
        gUnk_03002C30[0x6E + i].unk4 = i * 16 + 0x50;
    }
    REG_BLDALPHA = 0x10;
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    gUnk_03002C30[8].unk2 = 8;
    gUnk_03002C30[8].unk4 = gUnk_03006F74->unk1A * 16 + 0x54;
    if (gUnk_03006F74->unk5 == 1) {
        shop_build_sell_list();
    } else {
        struct ShopSellEntry *l;
        u32 *prices;
        const u8 *tbl;

        tbl = gUnk_08483E50;
        i = 0;
        l = (struct ShopSellEntry *)0x02040000;
        prices = (u32 *)0x02040004;
        for (; i < 4; i++) {
            const u8 *e = (const u8 *)(gUnk_03002420 * 4 + i + (u32)tbl);

            if (*e != 0xFF && (*e != 0x20 || gUnk_03006F74->unk19 == 3)) {
                l[i].id = *e;
                l[i].count = gMedapartInventory[l[i].id * 2 + gUnk_03006F74->unk19 * 240];
                load_part_data(l[i].id, gUnk_03006F74->unk19, &gUnk_03000440.unkEE);
                l[i].unk3 = (&gUnk_03000440.unkEE)[3];
                prices[i * 2] = (&gUnk_03000440.unkEE)[0xB] * 100;
            } else {
                break;
            }
        }
        ((struct ShopSellEntry *)0x02040000)[i].count = 0;
        gUnk_03006F74->unk20 = i;
    }
    for (i = 0; i < 4; i++) {
        if (gUnk_03006F74->unk20 > i)
            load_battle_sprite_tiles(((struct ShopSellEntry *)0x02040000)[i].id, gUnk_03006F74->unk19, i);
        else
            break;
    }
    gUnk_03006F74->unk1C = 0;
    for (i = 0; i < gUnk_03006F74->unk20; i++)
        gUnk_03006F74->unk1C += ((u8 *)0x02023000)[i] * ((u32 *)0x02040004)[i * 2];
    if (gUnk_03006F74->unk5)
        gUnk_03006F74->unk1C /= 2;
    if (gUnk_03006F74->unk1C > 99999)
        gUnk_03006F74->unk1C = 99999;
    gGameSubState++;
}

void enable_obj_layer_and_load_palette(void) {
    REG_DISPCNT |= 0x1000;
    CpuFastSet(gUnk_0850DD58 + 0x30, (void *)0x0202F9A0, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x0202F840, 8);
    CpuFastSet(gUnk_084C69B8, (void *)0x0202F860, 8);
    CpuFastSet(gUnk_0850DD58 + 0xB0, (void *)0x0202F9C0, 8);
    CpuFastSet(gUnk_0850DD58 - 0x30, (void *)0x0202F9E0, 8);
    CpuFastSet(gUnk_0850DD58 - 0x30, (void *)0x0202F980, 8);
    CpuFastSet(gUnk_0850DEF8, (void *)0x0202F880, 0x40);
    CpuFastSet(gUnk_08798D2C, (void *)0x0202FA00, 0x80);
    gUnk_03000440.unk84 = 0;
    render_battle_medapart_list(gUnk_03006F74->unk5);
    if (gUnk_03006F74->unk20 != 0) {
        u8 *buf = (u8 *)0x02023000;
        draw_number_tall(buf[buf[0x78]], 2, 0x1B, 10, 6, (REG_BG1CNT >> 8) & 0x1F);
        gUnk_03002C30[8].unk0 |= 0x4000;
    }
    if (gUnk_03006F74->unk20 > 1)
        draw_number_tall(((u8 *)0x02023000)[gUnk_02023078 + 1], 2, 0x1B, 12, 6, (REG_BG1CNT >> 8) & 0x1F);
    if (gUnk_03006F74->unk20 > 2)
        draw_number_tall(((u8 *)0x02023000)[gUnk_02023078 + 2], 2, 0x1B, 14, 6, (REG_BG1CNT >> 8) & 0x1F);
    if (gUnk_03006F74->unk20 > 3)
        draw_number_tall(((u8 *)0x02023000)[gUnk_02023078 + 3], 2, 0x1B, 16, 6, (REG_BG1CNT >> 8) & 0x1F);
    gGameSubState++;
}

void sub_08061D30(void) {
    struct Unk_03000440 *s = &gUnk_03000440;
    u8 *n = &s->unk84;

    if (*n <= 8) {
        blend_obj_palettes_to_color_0803F684(0, 32 - *n * 4, 0xFFFE);
        blend_obj_palettes_to_color_0803F998(0, 32 - *n * 4, 0x7FFD);
        (*n)++;
    } else {
        update_battle_sprite_priority_flags();
        gUnk_03006F74->unk2 = 0;
        gGameSubState++;
    }
}

#define CART gUnk_02023000
#define SHOP ((struct ShopSellEntry *)0x02040000)
#define PRICE ((u32 *)0x02040004)

static inline u32 cart_cost(s32 i) {
    return ((u8 *)0x02023000)[i] * PRICE[i * 2];
}

void shop_purchase_menu_handler(void) {
    u8 idx;
    s8 i;

    sub_08041C14(8, gFrameCounter, 4);
    update_battle_sprite_priority_flags();
    if (KEYS_LO(gRepeatKeys) & 8) {
        if (gUnk_03006F74->unk20 == 0)
            goto fail;
        play_sound_effect(4);
        gUnk_03000440.unk84 = 0;
        gGameSubState = 9;
        return;
    }
    if (gUnk_03006F74->unk5 == 0) {
        if (gFrameCounter & 8) {
            if (CART[gUnk_03006F74->unk1A] != 0)
                gUnk_03002C30[11].unk0 |= 0x4000;
            {
                u32 *m = &gUnk_03002B70.money;
                u32 sum = CART[0];
                u32 *p = (u32 *)0x02040000;
                u8 k;
                u32 off;

                sum = sum * p[1] + CART[1] * p[3] + CART[2] * p[5] + CART[3] * p[7];
                k = gUnk_03006F74->unk1A;
                off = k * 8;
                p++;
                sum += *(u32 *)((u8 *)p + off);
                if (*m >= sum && ((struct ShopSellEntry *)(p - 1))[k].count + CART[k] <= 0x62)
                    gUnk_03002C30[12].unk0 |= 0x4000;
            }
        } else {
            gUnk_03002C30[11].unk0 &= 0xBFFF;
            gUnk_03002C30[12].unk0 &= 0xBFFF;
        }
    } else {
        if (gFrameCounter & 8) {
            struct ShopSellEntry *l = SHOP;

            idx = gUnk_03006F74->unk1A + CART[0x78];
            if (CART[idx] != 0)
                gUnk_03002C30[11].unk0 |= 0x4000;
            if (l[idx].count > CART[idx])
                gUnk_03002C30[12].unk0 |= 0x4000;
        } else {
            gUnk_03002C30[11].unk0 &= 0xBFFF;
            gUnk_03002C30[12].unk0 &= 0xBFFF;
        }
    }

    if (gUnk_03006F74->unk20 > 1) {
        if (KEYS_LO(gRepeatKeys) & 0x40) {
            if (gUnk_03006F74->unk1A == 0) {
                if (gUnk_02023078 == 0)
                    goto cursor;
                gUnk_02023078--;
                goto scroll;
            }
            gUnk_03006F74->unk1A--;
            play_sound_effect(2);
            goto cursor;
        } else if (KEYS_LO(gRepeatKeys) & 0x80) {
            if (gUnk_03006F74->unk1A + gUnk_02023078 >= gUnk_03006F74->unk20 - 1)
                goto cursor;
            if (gUnk_03006F74->unk1A == 3) {
                gUnk_02023078++;
            scroll:
                render_battle_medapart_list(1);
                update_battle_sprite_priority_flags();
                goto changed;
            }
            if (gUnk_03006F74->unk1A >= gUnk_03006F74->unk20)
                goto cursor;
            gUnk_03006F74->unk1A++;
            play_sound_effect(2);
            goto cursor;
        }
    }

    if (KEYS_LO(gRepeatKeys) & 0x10) {
        struct Unk_03006F74 *t = gUnk_03006F74;
        u8 *buf = (u8 *)0x02023000;
        struct ShopSellEntry *l = SHOP;

        idx = t->unk1A + buf[0x78];
        if (t->unk5 == 0) {
            u32 *m = &gUnk_03002B70.money;
            u32 total = buf[buf[0x78]] * PRICE[buf[0x78] * 2];

            total += cart_cost(buf[0x78] + 1);
            total += cart_cost(buf[0x78] + 2);
            total += cart_cost(buf[0x78] + 3);
            if (*m >= total + PRICE[idx * 2] && l[idx].count + buf[idx] <= 0x62) {
                buf[idx]++;
                goto changed;
            }
        } else if (l[idx].count > buf[idx]) {
            buf[idx]++;
            goto changed;
        }
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        idx = gUnk_03006F74->unk1A + CART[0x78];
        if (CART[idx] != 0) {
            CART[idx]--;
            goto changed;
        }
    }
    if (KEYS_LO(gNewKeys) & 1) {
        if (gUnk_03006F74->unk1C == 0) {
        fail:
            play_sound_effect(6);
            return;
        }
        play_sound_effect(4);
        for (i = 0; i <= 1; i++)
            gUnk_03002C30[11 + i].unk0 &= 0xBFFF;
        open_choice_menu(1, 0x16, 7);
        text_window_init(1, 0, 0);
        gGameSubState = 6;
        return;
    }
    if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        clear_sprite_table_mask(0x61, 7);
        clear_sprite_table_mask(0xD, 0x34);
        clear_sprite_table_mask(0x45, 0x1C);
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
    return;

cursor:
    gUnk_03002C30[8].unk4 = gUnk_03006F74->unk1A * 16 + 0x54;
    gUnk_03002C30[11].unk4 = gUnk_03006F74->unk1A * 16 + 0x54;
    gUnk_03002C30[12].unk4 = gUnk_03006F74->unk1A * 16 + 0x54;
    return;

changed:
    play_sound_effect(2);
    if (gUnk_03006F74->unk20 != 0)
        draw_number_tall(CART[CART[0x78]], 2, 0x1B, 0xA, 6, (REG_BG1CNT >> 8) & 0x1F);
    if (gUnk_03006F74->unk20 > 1)
        draw_number_tall(((u8 *)0x02023000)[gUnk_02023078 + 1], 2, 0x1B, 0xC, 6, (REG_BG1CNT >> 8) & 0x1F);
    if (gUnk_03006F74->unk20 > 2)
        draw_number_tall(((u8 *)0x02023000)[gUnk_02023078 + 2], 2, 0x1B, 0xE, 6, (REG_BG1CNT >> 8) & 0x1F);
    if (gUnk_03006F74->unk20 > 3)
        draw_number_tall(((u8 *)0x02023000)[gUnk_02023078 + 3], 2, 0x1B, 0x10, 6, (REG_BG1CNT >> 8) & 0x1F);
    gUnk_03006F74->unk1C = 0;
    for (i = 0; i < 0x78; i++) {
        if (gUnk_03006F74->unk5 == 0)
            gUnk_03006F74->unk1C += CART[i] * PRICE[i * 2];
        else
            gUnk_03006F74->unk1C += CART[i] * PRICE[i * 2] / 2;
    }
    if (gUnk_03006F74->unk1C > 99999)
        gUnk_03006F74->unk1C = 99999;
    clear_sprite_table_mask(0x61, 7);
    divide_by_10000(gUnk_03000440.unk9E, gUnk_03006F74->unk1C);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x61, 0x13, 5, 7, 0xC, 2, 0);
}

void transition_fade_to_battle(void) {
    struct Unk_03000440 *s = &gUnk_03000440;
    u8 *n = &s->unk84;

    if (*n <= 8) {
        blend_obj_palettes_to_color_0803F684(0, *n * 4, 0xFFFE);
        blend_obj_palettes_to_color_0803F998(0, *n * 4, 0x7FFD);
        (*n)++;
    } else if (gUnk_03006F74->unk48 != 0) {
        struct Unk_03006F74 *p = gUnk_03006F74;
        u8 mode = p->unk19;
        struct ShopSellEntry *l = (struct ShopSellEntry *)0x02040000;

        init_battle_scene(mode, l[p->unk1A].id);
        gGameMode = 0;
    } else {
        s8 i;

        REG_DISPCNT &= 0xFDFF;
        for (i = 0; i < 2; i++)
            gUnk_03002C30[11 + i].unk0 &= 0xBFFF;
        for (i = 0; i < 2; i++)
            gUnk_03002C30[0x68 + i].unk0 &= 0xBFFF;
        for (i = 0; i < 4; i++)
            gUnk_03002C30[0x6A + i].unk0 &= 0xBFFF;
        for (i = 0; i < 4; i++)
            gUnk_03002C30[0x6E + i].unk0 &= 0xBFFF;
        gUnk_03002C30[8].unk0 &= 0xBFFF;
        REG_BLDALPHA = 0x1000;
        REG_BG1CNT = 0x1E05;
        REG_BG2CNT = 0x1D06;
        gGameState = 0xB;
        gGameSubState = 1;
    }
}

void advance_substate_on_handler_complete_1c(void) {
    if (run_message(gUnk_08485788[7]))
        gGameSubState++;
}

void shop_complete_transaction(void) {
    s8 i;

    if (!poll_choice_menu())
        return;
    gUnk_03000440.unk84 = 0;
    gUnk_03000440.unk1B = 0;
    if (gUnk_03000440.unk2A == 0) {
        if (gUnk_03006F74->unk5 == 0) {
            gUnk_03002B70.money -= gUnk_03006F74->unk1C;
            for (i = 0; i < 120; i++) {
                u8 *inv = gMedapartInventory;
                struct ShopSellEntry *l = (struct ShopSellEntry *)0x02040000;
                u8 *p = &inv[l[i].id * 2 + gUnk_03006F74->unk19 * 240];
                *p += ((u8 *)0x02023000)[i];
            }
        } else {
            u32 m = gUnk_03002B70.money + gUnk_03006F74->unk1C;

            if (m <= 99998)
                gUnk_03002B70.money = m;
            else
                gUnk_03002B70.money = 99999;
            for (i = 0; i < 120; i++) {
                u8 *inv = gMedapartInventory;
                struct ShopSellEntry *l = (struct ShopSellEntry *)0x02040000;
                u8 *p = &inv[l[i].id * 2 + gUnk_03006F74->unk19 * 240];
                *p -= ((u8 *)0x02023000)[i];
            }
        }
        clear_sprite_table_mask(0, 7);
        divide_by_10000(gUnk_03000440.unk9E, gUnk_03002B70.money);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0, 0x15, 1, 7, 0xF, 1, 0);
        gUnk_03000440.unk84 = 0;
    }
    gGameSubState++;
}

void sub_080625EC(void) {
    if (game_state_execute_handler_a()) {
        if (gUnk_03000440.unk2A == 0) {
            clear_sprite_table_mask(0x61, 7);
            clear_sprite_table_mask(0xD, 0x34);
            clear_sprite_table_mask(0x45, 0x1C);
            gGameSubState = 5;
        } else {
            gGameSubState = 4;
        }
    }
}

void sub_08062638(void) {
    struct Unk_03000440 *s = &gUnk_03000440;
    u8 *n = &s->unk84;

    if (*n <= 8) {
        blend_obj_palettes_to_color_0803F684(0, *n * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, *n * 4, 0xFFFF);
        (*n)++;
    } else {
        struct Unk_03006F74 *p = gUnk_03006F74;
        u8 mode = p->unk19;
        struct ShopSellEntry *l = (struct ShopSellEntry *)0x02040000;
        init_battle_scene(mode, l[p->unk1A + gUnk_02023078].id);
        gGameMode = 0;
    }
}

void sub_080626A4(void) {
    s32 i;

    battle_menu_highlight_icons(gUnk_03006F74->unk19, 8);
    clear_battle_sprite_slot(0, 0x80);
    for (i = 0; i < 4; i++)
        gUnk_03002C30[12 + i].unk0 &= 0xBFFF;
    CpuFastSet(gUnk_084E2E58, (void *)0x0202F800, 8);
    CpuFastSet(gUnk_084E2E38, (void *)0x0202F9E0, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x0202F9C0, 8);
    CpuFastSet(gUnk_08488AA4, (void *)0x0202F820, 8);
    CpuFastSet(gUnk_0879671C, (void *)0x0202FA00, 0x80);
    gUnk_03000440.unk84 = 0;
    gUnk_03006F74->unk6 = 1;
    gGameSubState++;
    REG_DISPCNT |= 0x100;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03002C30[7].unk0 = 0xC000;
    gUnk_03002C30[7].unk1C = 2;
    gUnk_03002C30[7].unkA = 1;
    gUnk_03002C30[7].unk6 = 0x1A;
    gUnk_03002C30[7].unk2 = 0x98;
    gUnk_03002C30[7].unk4 = 0;
    divide_by_10000(gUnk_03000440.unk9E, gUnk_03002B70.money);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0, 0x15, 1, 7, 0xF, 1, 0);
}

void fade_out_transition_step(void) {
    struct Unk_03000440 *s = &gUnk_03000440;
    u8 *n = &s->unk84;

    if (*n <= 8) {
        blend_obj_palettes_to_color_0803F684(0, 32 - *n * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - *n * 4, 0xFFFF);
        (*n)++;
    } else {
        update_battle_sprite_priority_flags();
        gUnk_03006F74->unk2 = 0;
        gGameState = 12;
        gGameSubState = 4;
    }
}

void dispatch_substate_handler(void) {
    struct FuncTable7 t = gUnk_080AFA20;
    t.f[gGameSubState]();
}

void init_scene_rendering_context(u32 a) {
    if (a == 0) {
        struct Unk_08047414 *obj = (struct Unk_08047414 *)0x02026000;
        u8 *b;
        u8 *c;
        u32 fill;

        sub_0803F624((u8 *)obj, 0xD0, 0);
        b = (u8 *)0x020260D0;
        sub_0803F624(b, 0x820, 0);
        sub_0803F624((u8 *)0x020264E0, 0x820, 0);
        c = (u8 *)0x020268F0;
        sub_0803F624(c, 0x60, 0);
        gUnk_03000430 = 2;
        gUnk_03002414 = (struct Unk_03002414 *)0x02024000;
        fill = a;
        CpuFastSet(&fill, (void *)0x02024000, 0x01000426);
        gUnk_03005308 = (struct SceneSlot *)c;
        sub_08047414(obj, (u8 *)gUnk_03002414, (struct SpriteNodeDesc **)gUnk_083D1BF8, (struct SpriteNodeOam *)b);
        obj->oams = (struct SpriteNodeOam *)b;
        load_sprite_animation_by_type(gUnk_03002414->unkB84, obj, gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0x3C,
                                      0x28, 0xC7, a, 1);
    } else {
        struct Unk_08047414 *obj = (struct Unk_08047414 *)0x02026000;

        sub_08047414(obj, (u8 *)gUnk_03002414, (struct SpriteNodeDesc **)gUnk_083D1BF8,
                     (struct SpriteNodeOam *)0x020264E0);
        obj->oams = (struct SpriteNodeOam *)0x020264E0;
        load_sprite_animation_by_type(gUnk_03002414->unkB84, obj, gUnk_03006F74->unk32, gUnk_03006F74->unk34, 0x3C,
                                      0x28, 0xC7, 4, 2);
    }
}

void load_medapart_sprite_animation(u8 id, u8 kind, u32 which) {
    struct Unk_08047414 *obj = (struct Unk_08047414 *)0x02026000;
    u8 x, y;

    obj->oams = (struct SpriteNodeOam *)(0x020260D0 + which * 0x410);
    x = gUnk_080AFA3C[which][kind][0];
    y = gUnk_080AFA3C[which][kind][1];
    if (which)
        load_sprite_animation_by_type(gUnk_03002414->unkB84, obj, id, kind, y, x, 0xC7, 4, 6);
    else
        load_sprite_animation_by_type(gUnk_03002414->unkB84, obj, id, kind, y, x, 0xC7, which, 5);
}

void sub_08062A74(u16 id, u8 second) {
    const u8 *src;
    u8 *dst;
    u32 i;

    src = (const u8 *)gUnk_083BB9CC[0][id];
    dst = gUnk_03000440.unk9E;
    if (second)
        dst += 0x14;
    for (i = 0; i < 20; i++) {
        *dst++ = *src++;
        if (*src == 0xFE)
            break;
    }
    *dst = 0xFE;
}

void sub_08062AB0(u32 medal, u32 frame) {
    struct Unk_03002C30 *s;
    u8 zero;

    lz_decompress_dispatch(gUnk_083AC494[medal][frame], (void *)0x06010000);
    s = gUnk_03002C30;
    zero = 0;
    s->unk0 = 0x8A24;
    if (gUnk_03006F74->unk7A == 0)
        s->unk0 |= 0x4000;
    s->unk2 = 0xB8;
    s->unk4 = 0x38;
    s->unk6 = 0x200;
    s->unkA = zero;
    s->unk1C = zero;
    s->unkB = 0x40;
    s->unk8 = 0x40;
    s->unk9 = 0x40;
}

void update_animated_tilemap(void) {
    s32 v;
    s32 i;
    u32 s;
    u32 d;
    s32 t;
    s32 w;
    u32 tiles;

    switch (gUnk_03006F74->unk3A / 128) {
    case 0:
        v = gUnk_03006F74->unk3A >> 1;
        break;
    case 1:
        v = gUnk_03006F74->unk3A >> 2;
        break;
    case 2:
        v = gUnk_03006F74->unk3A >> 3;
        break;
    case 3:
        v = gUnk_03006F74->unk3A >> 4;
        break;
    default:
        v = gUnk_03006F74->unk3A >> 5;
        break;
    }
    v &= 3;
    if (--gUnk_03006F74->unk3A < 0)
        gUnk_03006F74->unk3A = 0x3F;
    i = 0;
    w = v + 2;
    tiles = 0x0600D800;
    d = 0x1C0;
    s = v << 9;
    for (; i < 8; i++) {
        t = v;
        CpuSet((void *)(s + tiles), (void *)(0x0600E804 + d), 0xC);
        t = w & 3;
        CpuSet((void *)((t * 8 + i) * 0x40 + tiles), (void *)(0x0600E820 + d), 0xC);
        d += 0x40;
        s += 0x40;
    }
}

void animate_battle_scroll_tiles(void) {
    s32 v;
    s32 i;
    u8 *src;
    u8 *dst;

    switch (gUnk_03006F74->unk3A / 128) {
    case 0:
        v = gUnk_03006F74->unk3A >> 1;
        break;
    case 1:
        v = gUnk_03006F74->unk3A >> 2;
        break;
    case 2:
        v = gUnk_03006F74->unk3A >> 3;
        break;
    case 3:
        v = gUnk_03006F74->unk3A >> 4;
        break;
    default:
        v = gUnk_03006F74->unk3A >> 5;
        break;
    }
    v &= 3;
    if (--gUnk_03006F74->unk3A < 0)
        gUnk_03006F74->unk3A = 0x3F;
    dst = (u8 *)0x0600E9E2;
    v <<= 9;
    src = (u8 *)0x0600D800 + v;
    for (i = 0; i < 8; i++) {
        CpuSet(src, dst, 0xC);
        dst += 0x40;
        src += 0x40;
    }
}

void update_scroll_animation_tiles(void) {
    s32 v;
    s32 i;
    u32 s;
    u32 d;
    s32 t;
    s32 w;
    u32 tiles;

    switch (gUnk_03006F74->unk3A / 128) {
    case 0:
    case 1:
        v = gUnk_03006F74->unk3A >> 5;
        break;
    case 2:
        v = gUnk_03006F74->unk3A >> 4;
        break;
    case 3:
        v = gUnk_03006F74->unk3A >> 3;
        break;
    case 4:
        v = gUnk_03006F74->unk3A >> 2;
        break;
    default:
        v = gUnk_03006F74->unk3A >> 1;
        break;
    }
    v &= 3;
    if (--gUnk_03006F74->unk3A < 0)
        gUnk_03006F74->unk3A = 0x3F;
    i = 0;
    w = v + 2;
    tiles = 0x0600D800;
    d = 0x1C0;
    s = v << 9;
    for (; i < 8; i++) {
        t = v;
        CpuSet((void *)(s + tiles), (void *)(0x0600E804 + d), 0xC);
        t = w & 3;
        CpuSet((void *)((t * 8 + i) * 0x40 + tiles), (void *)(0x0600E820 + d), 0xC);
        d += 0x40;
        s += 0x40;
    }
}

void fade_update_tilemap_copy(void) {
    s32 v;
    s32 i;
    u8 *src;
    u8 *dst;

    switch (gUnk_03006F74->unk3A / 128) {
    case 0:
    case 1:
        v = gUnk_03006F74->unk3A >> 5;
        break;
    case 2:
        v = gUnk_03006F74->unk3A >> 4;
        break;
    case 3:
        v = gUnk_03006F74->unk3A >> 3;
        break;
    case 4:
        v = gUnk_03006F74->unk3A >> 2;
        break;
    default:
        v = gUnk_03006F74->unk3A >> 1;
        break;
    }
    v &= 3;
    if (--gUnk_03006F74->unk3A < 0)
        gUnk_03006F74->unk3A = 0x3F;
    dst = (u8 *)0x0600E9E2;
    v <<= 9;
    src = (u8 *)0x0600D800 + v;
    for (i = 0; i < 8; i++) {
        CpuSet(src, dst, 0xC);
        dst += 0x40;
        src += 0x40;
    }
}

void sub_08062E10(void) {
    gUnk_03006F74->unk31 = gUnk_03002B68;
    gUnk_03006F74->unk33 = ((u16 *)&gUnk_03002B68)[1];
    gGameSubState++;
}

void sub_08062E3C(void) {
    u32 size;
    u32 zero;
    u32 z;

    if (sub_08074B68() != 0x18)
        play_song(0x18);
    zero = z = 0;
    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    reset_bg_scroll();
    clear_battle_sprite_slot(0, 0x80);
    REG_DISPCNT = 0x60;
    REG_BLDCNT = 0x2FF;
    REG_BLDY = 0x10;
    REG_BG1CNT = 0x1E05;
    REG_BG2CNT = 0x1B06;
    REG_BG3CNT = 0x3C07;
    decompress_and_write_tilemap(gUnk_0879DDCC, REG_BG1CNT);
    decompress_and_write_tilemap(gUnk_0879DF44, REG_BG2CNT);
    decompress_and_write_tilemap(gUnk_0879E1DC, REG_BG3CNT);
    REG_BG2CNT = 0x1D06;
    size = dma3_copy_or_decompress(gUnk_0879C89C, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)0x06004000, size);
    lz_decompress_dispatch(gUnk_08784CB0, (void *)(0x06004000 + size));
    gUnk_03006F74->unk36 = size / 32 - 1;
    CpuFastSet(gUnk_0879C69C, (void *)PLTT, 0x80);
    CpuFastSet(gUnk_0850DD78, (void *)(PLTT + 0x3A0), 8);
    CpuFastSet(gUnk_0850DD78, &gPaletteBackup[0xD0], 8);
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06011E00);
    gUnk_03006F74->unk3A = 0x280;
    sub_08062A74(gUnk_03006F74->unk31 * 4 + gUnk_03006F74->unk33, 0);
    render_text_string_to_sprites(gUnk_03000440.unk9E, 0, 0, 10, 16, 13, z, 1);
    init_scene_rendering_context(0);
    load_medapart_sprite_animation(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0);
    update_animated_tilemap();
    init_blend_effect(gUnk_03006F74->unk50, 0x10, 0, -1, 0xC0);
    gUnk_03002C30[0x21].unk0 = 0x8000;
    gUnk_03002C30[0x21].unk1C = 2;
    gUnk_03002C30[0x21].unk2 = 0x28;
    gUnk_03002C30[0x21].unk4 = 0x40;
    gUnk_03002C30[0x21].unkA = 8;
    gUnk_03002C30[0x21].unk6 = 0x2A;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gGameSubState++;
}
