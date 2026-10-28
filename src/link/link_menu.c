// Mode-2 state 20 (dispatch_battle_menu_and_update_counters, sub-states gLinkMenuStates), entered from
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
    decompress_and_write_tilemap(gLinkMenuBg1Tilemap, REG_BG1CNT);
    decompress_and_write_tilemap(gLinkMenuBg2Tilemap, REG_BG2CNT);
    decompress_and_write_tilemap(gLinkMenuBg3Tilemap, REG_BG3CNT);
    size = dma3_copy_or_decompress(gLinkMenuBgTiles, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)0x06004000, size);
    CpuFastSet(gLinkMenuBgPalette, (void *)PLTT, 0x80);
    CpuFastSet(gCursorArrowPalette, (void *)0x050003C0, 8);
    lz_decompress_dispatch(gMenuObjTilesLz, (void *)0x06010000);
    CpuFastSet(gBlackObjPalettes, (void *)0x05000200, 8);
    gSpriteEntries[0].flags = 0x8000;
    gSpriteEntries[0].frame_table = 2;
    gSpriteEntries[0].palette = 0xE;
    gSpriteEntries[0].frame = 6;
    gSpriteEntries[0].x = 0xC;
    gSpriteEntries[0].y = 0x1C;
    init_blend_effect(gMenuWork->blend, 0x10, 0, -1, 0xC0);
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gMenuWork->frame = 0;
    gMenuWork->cursor = 0;
    gMenuWork->partner_chose = -1;
    if (sound_current_song() != 0x18)
        play_song(0x18);
    gGameSubState++;
}

void fade_state_dispatch(void) {

    if (gLinkPlayerId != 0) {
        switch (gMenuWork->frame) {
        case 0:
            if ((s32)count_assembled_medabots() <= 1) {
                gMenuWork->link_battle_ok = 0;
                gLinkPackets.sendData = 0xFF02;
            } else {
                gMenuWork->link_battle_ok = -1;
                gLinkPackets.sendData = 0xFF03;
            }
            if (gLinkPackets.recv[0][1] == 0xFF04)
                gMenuWork->frame++;
            break;
        case 1:
            gLinkPackets.sendData = 0xFF05;
            if (gLinkPackets.recv[0][1] == 0xFF02 || gLinkPackets.recv[0][1] == 0xFF03) {
                gMenuWork->link_battle_ok = gLinkPackets.recv[0][1] != 0xFF02;
                gLinkPackets.sendData = 0xFF04;
            }
            if (gLinkPackets.recv[0][1] == 0xFF05)
                gMenuWork->frame++;
            break;
        case 2:
            gLinkPackets.sendData = 0xFF06;
            if (gLinkPackets.recv[0][1] == 0xFF06)
                gMenuWork->frame++;
            break;
        case 3:
            if (medaparts_all_equipped()) {
                gMenuWork->link_trade_ok = 0;
                gLinkPackets.sendData = 0xFF02;
            } else {
                gMenuWork->link_trade_ok = -1;
                gLinkPackets.sendData = 0xFF03;
            }
            if (gLinkPackets.recv[0][1] == 0xFF04)
                gMenuWork->frame++;
            break;
        case 4:
            gLinkPackets.sendData = 0xFF05;
            if (gLinkPackets.recv[0][1] == 0xFF02 || gLinkPackets.recv[0][1] == 0xFF03) {
                gMenuWork->link_trade_ok = gLinkPackets.recv[0][1] != 0xFF02;
                gLinkPackets.sendData = 0xFF04;
            }
            if (gLinkPackets.recv[0][1] == 0xFF05)
                gMenuWork->frame++;
            break;
        case 5:
            gLinkPackets.sendData = 0xFF06;
            if (gLinkPackets.recv[0][1] == 0xFF06)
                gGameSubState++;
            break;
        }
    } else {
        switch (gMenuWork->frame) {
        case 0:
            if (gLinkPackets.recv[1][1] == 0xFF02 || gLinkPackets.recv[1][1] == 0xFF03) {
                gMenuWork->link_battle_ok = gLinkPackets.recv[1][1] != 0xFF02;
                gLinkPackets.sendData = 0xFF04;
            }
            if (gLinkPackets.recv[1][1] == 0xFF05)
                gMenuWork->frame++;
            break;
        case 1:
            if (gMenuWork->link_battle_ok == 0 || (s32)count_assembled_medabots() <= 1) {
                gLinkPackets.sendData = 0xFF02;
                gMenuWork->link_battle_ok = 0;
            } else {
                gLinkPackets.sendData = 0xFF03;
            }
            if (gLinkPackets.recv[1][1] == 0xFF04)
                gMenuWork->frame++;
            break;
        case 2:
            gLinkPackets.sendData = 0xFF05;
            if (gLinkPackets.recv[0][1] == 0xFF05 && gLinkPackets.recv[1][1] == 0xFF06)
                gLinkPackets.sendData = gLinkPackets.recv[1][1];
            if (gLinkPackets.recv[0][1] == 0xFF06)
                gMenuWork->frame++;
            break;
        case 3:
            if (gLinkPackets.recv[1][1] == 0xFF02 || gLinkPackets.recv[1][1] == 0xFF03) {
                gMenuWork->link_trade_ok = gLinkPackets.recv[1][1] != 0xFF02;
                gLinkPackets.sendData = 0xFF04;
            }
            if (gLinkPackets.recv[1][1] == 0xFF05)
                gMenuWork->frame++;
            break;
        case 4:
            if (gMenuWork->link_trade_ok == 0 || medaparts_all_equipped()) {
                gLinkPackets.sendData = 0xFF02;
                gMenuWork->link_trade_ok = 0;
            } else {
                gLinkPackets.sendData = 0xFF03;
            }
            if (gLinkPackets.recv[1][1] == 0xFF04)
                gMenuWork->frame++;
            break;
        case 5:
            gLinkPackets.sendData = 0xFF05;
            if (gLinkPackets.recv[0][1] == 0xFF05 && gLinkPackets.recv[1][1] == 0xFF06)
                gLinkPackets.sendData = gLinkPackets.recv[1][1];
            if (gLinkPackets.recv[0][1] == 0xFF06)
                gGameSubState++;
            break;
        }
    }
}

void link_menu_fade_in(void) {
    if (blend_fade_step_08065598(gMenuWork->blend)) {
        gGameSubState++;
        text_window_init(1, 0, 1);
        gSpriteEntries[0].flags |= 0x4000;
    }
}

void handle_battle_menu_selection(void) {
    if ((gLinkPackets.recv[gLinkPlayerId == 0][1] & 0xFF00) == 0xEF00) {
        gMenuWork->cursor = gLinkPackets.recv[gLinkPlayerId == 0][1];
        gMenuWork->partner_chose = 1;
        gGameSubState++;
        play_sound_effect(4);
        gSpriteEntries[0].y = gMenuWork->cursor * 16 + 0x1C;
        return;
    }

    sprite_bob_x(0, gFrameCounter, 0xC);
    if (gMenuWork->cursor == 6)
        run_message(gLinkAnswersDifferMessage);
    else
        run_message(gLinkMenuMessages[gLinkMenuHelpMessageIds[gMenuWork->cursor]]);

    if (gMenuWork->cursor > 4) {
        if (KEYS_LO(gRepeatKeys) & 0xC1) {
            gMenuWork->cursor = gMenuWork->cursor == 5 ? 1 : 4;
            message_next();
        }
        return;
    }

    if (KEYS_LO(gRepeatKeys) & 0x40) {
        gMenuWork->cursor = gMenuWork->cursor != 0 ? gMenuWork->cursor - 1 : 4;
        message_next();
        play_sound_effect(2);
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        gMenuWork->cursor = gMenuWork->cursor <= 3 ? gMenuWork->cursor + 1 : 0;
        message_next();
        play_sound_effect(2);
    }
    gSpriteEntries[0].y = gMenuWork->cursor * 16 + 0x1C;
    if (KEYS_LO(gRepeatKeys) & 1) {
        if (gMenuWork->cursor == 1 && gMenuWork->link_battle_ok == 0) {
            gMenuWork->cursor = 5;
            message_next();
            play_sound_effect(6);
        } else if (gMenuWork->cursor == 2 && gMenuWork->link_trade_ok == 0) {
            play_sound_effect(6);
        } else {
            gMenuWork->partner_chose = 0;
            gLinkPackets.sendData = gMenuWork->cursor | 0xEF00;
            gGameSubState++;
            play_sound_effect(4);
        }
    }
}

void update_fade_transition_state_080662CC(void) {
    struct MenuWork *p = gMenuWork;

    if (p->partner_chose != 0) {
        gLinkPackets.sendData = 0xFE0F;
    } else if (gLinkPlayerId != 0) {
        if ((gLinkPackets.recv[0][1] & 0xFF00) == 0xEF00) {
            p->cursor = gLinkPackets.recv[0][1];
            gMenuWork->partner_chose = 1;
        } else if (gLinkPackets.recv[0][1] == 0xFE0F) {
            gLinkPackets.sendData = 0xFE0F;
        }
    } else {
        p->partner_chose = 0;
        gLinkPackets.sendData = gMenuWork->cursor | 0xEF00;
    }
    if (gLinkPackets.recv[1][1] == 0xFE0F) {
        if (gMenuWork->cursor == 4) {
            gGameSubState = 8;
            message_next();
        } else {
            init_blend_effect(gMenuWork->blend, 0, 0, 1, 0xC0);
            gGameSubState += 2;
        }
    }
}

void advance_fade_and_play_music(void) {
    if (blend_fade_step_08065598(gMenuWork->blend) && !is_sound_effect_playing(4)) {
        play_song(0);
        play_sound_effect(0);
        eeprom_setup_timer_irq();
        gGameSubState += 2;
    }
}

void init_link_save_and_connect(void) {
    s32 i;

    gGameSubState = 0;
    if (gMenuWork->pending_sound == 0) {
        for (i = 0; i <= 3; i++) {
            if (save_dispatch(0) == 0)
                break;
        }
    }
    init_linking_mode();
}

void link_menu_fade_out_exit(void) {
    if (blend_fade_step_08065598(gMenuWork->blend)) {
        if (gMenuWork->cursor <= 2)
            init_game_mode(gLinkMenuGameModes[gMenuWork->cursor]);
        else {
            gGameState = 0x1B;
            gGameSubState = 0;
        }
    }
}

void setup_dialogue_script_from_rom(void) {
    struct MenuWork *p = gMenuWork;
    u8 *d;
    const u8 *s;

    d = &p->message_buf[0];
    *d = 0xFB;
    d = &p->message_buf[1];
    *d = 1;
    d = &p->message_buf[2];
    *d = 0xC;
    d = &p->message_buf[3];
    *d = 0;
    d = &p->message_buf[4];
    s = gLinkSavePromptMessage;
    while ((*d = *s) != 0xFF) {
        d++;
        s++;
    }
    *d = 0xFF;
    d[1] = 4;
    d = gMenuWork->message_buf;
    if (run_message(d)) {
        message_next();
        open_choice_menu(1, 0x16, 7);
        gGameSubState++;
    }
}

void link_menu_poll_yes_no(void) {
    if (poll_choice_menu()) {
        if (gGameWork.unk2A == 0) {
            gGameSubState++;
            message_next();
        } else
            gGameSubState += 3;
    }
}

void advance_substate_with_sound_ch1(void) {
    if (run_message(gLinkMenuMessages[18])) {
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
    const u8 *s = gLinkMenuMessages[15];
    struct MenuWork *p = gMenuWork;
    u8 *d;
    s32 i;
    u16 a, b;

    d = &p->message_buf[0];
    *d = 0xFB;
    d = &p->message_buf[1];
    *d = 0;
    d = &p->message_buf[2];
    *d = 0xC;
    d = &p->message_buf[3];
    *d = 0;
    d = &p->message_buf[4];
    i = 0;
    do {
        d[i] = s[i];
        i++;
    } while (d[i] != 0xFF);
    d[i] = s[i];
    i++;
    d[i] = s[i];
    if (run_message(gMenuWork->message_buf)) {
        if (gGameWork.unk2A == 0)
            gLinkPackets.sendData = 0xFF00;
        else
            gLinkPackets.sendData = 0xFF01;
        a = gLinkPackets.recv[0][1];
        b = gLinkPackets.recv[1][1];
        if ((a & 0xFF00) == 0xFF00 && (b & 0xFF00) == 0xFF00) {
            message_next();
            if (a == b) {
                init_blend_effect(gMenuWork->blend, 0, 0, 1, 0xC0);
                gGameSubState = 5;
                gMenuWork->pending_sound = a != 0xFF00;
            } else {
                gGameSubState = 3;
                gMenuWork->cursor = 6;
            }
        }
    }
}

void dispatch_battle_menu_and_update_counters(void) {
    struct FuncTable13 t = gLinkMenuStates;
    t.f[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}
