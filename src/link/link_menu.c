// Mode-2 state 20 (dispatch_battle_menu_and_update_counters, sub-states gUnk_080AFB48), entered from
// field/field_mode (case 5) and when the link trade scenes end: the link menu hub with its own save + connect
// step and yes/no confirmation. Name is a guess.
#include "global.h"

void clear_vram_bg(void) {
    u32 zero;
    u32 size;

    zero = 0;
    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    clear_battle_sprite_slot(0, 0x80);
    reset_bg_scroll();
    REG_DISPCNT = 0x60;
    REG_BG1CNT = 0x1E05;
    REG_BG2CNT = 0x1D06;
    REG_BG3CNT = 0x3C07;
    decompress_and_write_tilemap(gUnk_0879C06C, REG_BG1CNT);
    decompress_and_write_tilemap(gUnk_0879C260, REG_BG2CNT);
    decompress_and_write_tilemap(gUnk_0879C3A0, REG_BG3CNT);
    size = dma3_copy_or_decompress(gUnk_0879AC40, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)0x06004000, size);
    CpuFastSet(gUnk_0879AA40, (void *)PLTT, 0x80);
    CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    CpuFastSet(gUnk_0850DEB8, (void *)0x05000200, 8);
    gSpriteEntries[0].unk0 = 0x8000;
    gSpriteEntries[0].unk1C = 2;
    gSpriteEntries[0].unkA = 0xE;
    gSpriteEntries[0].unk6 = 6;
    gSpriteEntries[0].unk2 = 0xC;
    gSpriteEntries[0].unk4 = 0x1C;
    init_blend_effect(gUnk_03006F74->unk50, 0x10, 0, -1, 0xC0);
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03006F74->unk3A = 0;
    gUnk_03006F74->unk5 = 0;
    gUnk_03006F74->unk7A = -1;
    if (sound_current_song() != 0x18)
        play_song(0x18);
    gGameSubState++;
}

void fade_state_dispatch(void) {

    if (gUnk_03000B90 != 0) {
        switch (gUnk_03006F74->unk3A) {
        case 0:
            if ((s32)count_assembled_medabots() <= 1) {
                gUnk_03006F74->unk7B = 0;
                gUnk_03005010.unk6 = 0xFF02;
            } else {
                gUnk_03006F74->unk7B = -1;
                gUnk_03005010.unk6 = 0xFF03;
            }
            if (gUnk_03005010.unk8[0][1] == 0xFF04)
                gUnk_03006F74->unk3A++;
            break;
        case 1:
            gUnk_03005010.unk6 = 0xFF05;
            if (gUnk_03005010.unk8[0][1] == 0xFF02 || gUnk_03005010.unk8[0][1] == 0xFF03) {
                gUnk_03006F74->unk7B = gUnk_03005010.unk8[0][1] != 0xFF02;
                gUnk_03005010.unk6 = 0xFF04;
            }
            if (gUnk_03005010.unk8[0][1] == 0xFF05)
                gUnk_03006F74->unk3A++;
            break;
        case 2:
            gUnk_03005010.unk6 = 0xFF06;
            if (gUnk_03005010.unk8[0][1] == 0xFF06)
                gUnk_03006F74->unk3A++;
            break;
        case 3:
            if (medaparts_all_equipped()) {
                gUnk_03006F74->unk7C = 0;
                gUnk_03005010.unk6 = 0xFF02;
            } else {
                gUnk_03006F74->unk7C = -1;
                gUnk_03005010.unk6 = 0xFF03;
            }
            if (gUnk_03005010.unk8[0][1] == 0xFF04)
                gUnk_03006F74->unk3A++;
            break;
        case 4:
            gUnk_03005010.unk6 = 0xFF05;
            if (gUnk_03005010.unk8[0][1] == 0xFF02 || gUnk_03005010.unk8[0][1] == 0xFF03) {
                gUnk_03006F74->unk7C = gUnk_03005010.unk8[0][1] != 0xFF02;
                gUnk_03005010.unk6 = 0xFF04;
            }
            if (gUnk_03005010.unk8[0][1] == 0xFF05)
                gUnk_03006F74->unk3A++;
            break;
        case 5:
            gUnk_03005010.unk6 = 0xFF06;
            if (gUnk_03005010.unk8[0][1] == 0xFF06)
                gGameSubState++;
            break;
        }
    } else {
        switch (gUnk_03006F74->unk3A) {
        case 0:
            if (gUnk_03005010.unk8[1][1] == 0xFF02 || gUnk_03005010.unk8[1][1] == 0xFF03) {
                gUnk_03006F74->unk7B = gUnk_03005010.unk8[1][1] != 0xFF02;
                gUnk_03005010.unk6 = 0xFF04;
            }
            if (gUnk_03005010.unk8[1][1] == 0xFF05)
                gUnk_03006F74->unk3A++;
            break;
        case 1:
            if (gUnk_03006F74->unk7B == 0 || (s32)count_assembled_medabots() <= 1) {
                gUnk_03005010.unk6 = 0xFF02;
                gUnk_03006F74->unk7B = 0;
            } else {
                gUnk_03005010.unk6 = 0xFF03;
            }
            if (gUnk_03005010.unk8[1][1] == 0xFF04)
                gUnk_03006F74->unk3A++;
            break;
        case 2:
            gUnk_03005010.unk6 = 0xFF05;
            if (gUnk_03005010.unk8[0][1] == 0xFF05 && gUnk_03005010.unk8[1][1] == 0xFF06)
                gUnk_03005010.unk6 = gUnk_03005010.unk8[1][1];
            if (gUnk_03005010.unk8[0][1] == 0xFF06)
                gUnk_03006F74->unk3A++;
            break;
        case 3:
            if (gUnk_03005010.unk8[1][1] == 0xFF02 || gUnk_03005010.unk8[1][1] == 0xFF03) {
                gUnk_03006F74->unk7C = gUnk_03005010.unk8[1][1] != 0xFF02;
                gUnk_03005010.unk6 = 0xFF04;
            }
            if (gUnk_03005010.unk8[1][1] == 0xFF05)
                gUnk_03006F74->unk3A++;
            break;
        case 4:
            if (gUnk_03006F74->unk7C == 0 || medaparts_all_equipped()) {
                gUnk_03005010.unk6 = 0xFF02;
                gUnk_03006F74->unk7C = 0;
            } else {
                gUnk_03005010.unk6 = 0xFF03;
            }
            if (gUnk_03005010.unk8[1][1] == 0xFF04)
                gUnk_03006F74->unk3A++;
            break;
        case 5:
            gUnk_03005010.unk6 = 0xFF05;
            if (gUnk_03005010.unk8[0][1] == 0xFF05 && gUnk_03005010.unk8[1][1] == 0xFF06)
                gUnk_03005010.unk6 = gUnk_03005010.unk8[1][1];
            if (gUnk_03005010.unk8[0][1] == 0xFF06)
                gGameSubState++;
            break;
        }
    }
}

void link_menu_fade_in(void) {
    if (blend_fade_step_08065598(gUnk_03006F74->unk50)) {
        gGameSubState++;
        text_window_init(1, 0, 1);
        gSpriteEntries[0].unk0 |= 0x4000;
    }
}

void handle_battle_menu_selection(void) {
    if ((gUnk_03005010.unk8[gUnk_03000B90 == 0][1] & 0xFF00) == 0xEF00) {
        gUnk_03006F74->unk5 = gUnk_03005010.unk8[gUnk_03000B90 == 0][1];
        gUnk_03006F74->unk7A = 1;
        gGameSubState++;
        play_sound_effect(4);
        gSpriteEntries[0].unk4 = gUnk_03006F74->unk5 * 16 + 0x1C;
        return;
    }

    sprite_bob_y(0, gFrameCounter, 0xC);
    if (gUnk_03006F74->unk5 == 6)
        run_message(gUnk_080AFB30);
    else
        run_message(gUnk_08485BD8[gUnk_080AFB3F[gUnk_03006F74->unk5]]);

    if (gUnk_03006F74->unk5 > 4) {
        if (KEYS_LO(gRepeatKeys) & 0xC1) {
            gUnk_03006F74->unk5 = gUnk_03006F74->unk5 == 5 ? 1 : 4;
            message_next();
        }
        return;
    }

    if (KEYS_LO(gRepeatKeys) & 0x40) {
        gUnk_03006F74->unk5 = gUnk_03006F74->unk5 != 0 ? gUnk_03006F74->unk5 - 1 : 4;
        message_next();
        play_sound_effect(2);
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        gUnk_03006F74->unk5 = gUnk_03006F74->unk5 <= 3 ? gUnk_03006F74->unk5 + 1 : 0;
        message_next();
        play_sound_effect(2);
    }
    gSpriteEntries[0].unk4 = gUnk_03006F74->unk5 * 16 + 0x1C;
    if (KEYS_LO(gRepeatKeys) & 1) {
        if (gUnk_03006F74->unk5 == 1 && gUnk_03006F74->unk7B == 0) {
            gUnk_03006F74->unk5 = 5;
            message_next();
            play_sound_effect(6);
        } else if (gUnk_03006F74->unk5 == 2 && gUnk_03006F74->unk7C == 0) {
            play_sound_effect(6);
        } else {
            gUnk_03006F74->unk7A = 0;
            gUnk_03005010.unk6 = gUnk_03006F74->unk5 | 0xEF00;
            gGameSubState++;
            play_sound_effect(4);
        }
    }
}

void update_fade_transition_state_080662CC(void) {
    struct Unk_03006F74 *p = gUnk_03006F74;

    if (p->unk7A != 0) {
        gUnk_03005010.unk6 = 0xFE0F;
    } else if (gUnk_03000B90 != 0) {
        if ((gUnk_03005010.unk8[0][1] & 0xFF00) == 0xEF00) {
            p->unk5 = gUnk_03005010.unk8[0][1];
            gUnk_03006F74->unk7A = 1;
        } else if (gUnk_03005010.unk8[0][1] == 0xFE0F) {
            gUnk_03005010.unk6 = 0xFE0F;
        }
    } else {
        p->unk7A = 0;
        gUnk_03005010.unk6 = gUnk_03006F74->unk5 | 0xEF00;
    }
    if (gUnk_03005010.unk8[1][1] == 0xFE0F) {
        if (gUnk_03006F74->unk5 == 4) {
            gGameSubState = 8;
            message_next();
        } else {
            init_blend_effect(gUnk_03006F74->unk50, 0, 0, 1, 0xC0);
            gGameSubState += 2;
        }
    }
}

void advance_fade_and_play_music(void) {
    if (blend_fade_step_08065598(gUnk_03006F74->unk50) && !is_sound_effect_playing(4)) {
        play_song(0);
        play_sound_effect(0);
        eeprom_setup_timer_irq();
        gGameSubState += 2;
    }
}

void init_link_save_and_connect(void) {
    s32 i;

    gGameSubState = 0;
    if (gUnk_03006F74->unk4A == 0) {
        for (i = 0; i <= 3; i++) {
            if (save_dispatch(0) == 0)
                break;
        }
    }
    init_linking_mode();
}

void link_menu_fade_out_exit(void) {
    if (blend_fade_step_08065598(gUnk_03006F74->unk50)) {
        if (gUnk_03006F74->unk5 <= 2)
            init_game_mode(gUnk_080AFB45[gUnk_03006F74->unk5]);
        else {
            gGameState = 0x1B;
            gGameSubState = 0;
        }
    }
}

void setup_dialogue_script_from_rom(void) {
    struct Unk_03006F74 *p = gUnk_03006F74;
    u8 *d;
    const u8 *s;

    d = &p->unk270[0];
    *d = 0xFB;
    d = &p->unk270[1];
    *d = 1;
    d = &p->unk270[2];
    *d = 0xC;
    d = &p->unk270[3];
    *d = 0;
    d = &p->unk270[4];
    s = gUnk_0848564F;
    while ((*d = *s) != 0xFF) {
        d++;
        s++;
    }
    *d = 0xFF;
    d[1] = 4;
    d = gUnk_03006F74->unk270;
    if (run_message(d)) {
        message_next();
        open_choice_menu(1, 0x16, 7);
        gGameSubState++;
    }
}

void link_menu_poll_yes_no(void) {
    if (poll_choice_menu()) {
        if (gUnk_03000440.unk2A == 0) {
            gGameSubState++;
            message_next();
        } else
            gGameSubState += 3;
    }
}

void advance_substate_with_sound_ch1(void) {
    if (run_message(gUnk_08485BD8[18])) {
        open_choice_menu(1, 0x16, 7);
        gGameSubState++;
    }
}

void link_menu_wait_choice(void) {
    if (poll_choice_menu()) {
        gGameSubState++;
        message_next();
    }
}

void menu_yes_no_confirmation_handler(void) {
    const u8 *s = gUnk_08485BD8[15];
    struct Unk_03006F74 *p = gUnk_03006F74;
    u8 *d;
    s32 i;
    u16 a, b;

    d = &p->unk270[0];
    *d = 0xFB;
    d = &p->unk270[1];
    *d = 0;
    d = &p->unk270[2];
    *d = 0xC;
    d = &p->unk270[3];
    *d = 0;
    d = &p->unk270[4];
    i = 0;
    do {
        d[i] = s[i];
        i++;
    } while (d[i] != 0xFF);
    d[i] = s[i];
    i++;
    d[i] = s[i];
    if (run_message(gUnk_03006F74->unk270)) {
        if (gUnk_03000440.unk2A == 0)
            gUnk_03005010.unk6 = 0xFF00;
        else
            gUnk_03005010.unk6 = 0xFF01;
        a = gUnk_03005010.unk8[0][1];
        b = gUnk_03005010.unk8[1][1];
        if ((a & 0xFF00) == 0xFF00 && (b & 0xFF00) == 0xFF00) {
            message_next();
            if (a == b) {
                init_blend_effect(gUnk_03006F74->unk50, 0, 0, 1, 0xC0);
                gGameSubState = 5;
                gUnk_03006F74->unk4A = a != 0xFF00;
            } else {
                gGameSubState = 3;
                gUnk_03006F74->unk5 = 6;
            }
        }
    }
}

void dispatch_battle_menu_and_update_counters(void) {
    struct FuncTable13 t = gUnk_080AFB48;
    t.f[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}
