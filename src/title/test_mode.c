// Mode-2 state 7: the hidden TEST MODE screen (Music / Effect / Erase saved game / Exit).
// test_mode_dispatch runs gUnk_08483C6C: graphics, fades, test_mode_update (menu input, sound test), then the
// erase-save steps (sub_0805F8F0 retries save_dispatch(2) through save/save_data.c).
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
    sprite_bob_y(0, gFrameCounter, 0x14);
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
