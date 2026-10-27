// Mode-2 state 21 (dispatch_battle_cutscene_substate, sub-states gUnk_080AFB10), entered from field/field_mode
// (case 4): message and yes/no prompts, saves the game (save_dispatch) and starts the serial link
// (serial_link_init). Name is a guess.
#include "global.h"

void sub_08065618(void) {
    gUnk_03006F74->unk7F = sub_08074B68();
    text_window_init(1, 0, 0);
    gUnk_03006F74->unk8 = 0;
    gGameSubState++;
}

void battle_cutscene_dispatch(void) {
    u8 t;
    u16 r;
    s8 i;

    t = gUnk_03006F74->unk2++;
    r = 0;
    if (!(*(u8 *)&gUnk_03001784 & 2)) {
        if (run_message(gUnk_08485BD8[gUnk_080AFB08[gUnk_03006F74->unk8]]) && KEYS_LO(gNewKeys) & 1) {
            play_sound_effect(0xD);
            if (++gUnk_03006F74->unk8 > 2) {
                gUnk_03000440.unk84 = r;
                gUnk_03000440.unk1B = r;
                gGameSubState++;
                *(u8 *)&gUnk_03001784 |= 2;
            } else
                sub_0803FB0C();
        }
        return;
    }
    switch (gUnk_03006F74->unk8) {
    case 0:
        if (run_message(gUnk_08485BD8[gUnk_080AFB0B[gUnk_03006F74->unk8]]) && KEYS_LO(gNewKeys) & 1) {
            play_sound_effect(0xD);
            gUnk_03006F74->unk8++;
            sub_0803FB0C();
            open_choice_menu(1, 0, 7);
        }
        break;
    case 1:
    case 2:
    case 3:
        if (run_message(gUnk_08485BD8[gUnk_080AFB0B[gUnk_03006F74->unk8]]) && poll_choice_menu()) {
            if (gUnk_03000440.unk2A == 0) {
                if (*(u8 *)&gUnk_03001784 & 1) {
                    if (++gUnk_03006F74->unk8 <= 3)
                        open_choice_menu(1, 0, 7);
                } else {
                    if (++gUnk_03006F74->unk8 <= 2)
                        open_choice_menu(1, 0, 7);
                    else
                        gUnk_03006F74->unk8++;
                }
            } else {
                gUnk_03006F74->unk8 = 0;
                gGameSubState += 2;
            }
            sub_0803FB0C();
        }
        break;
    case 4:
        if (run_message(gUnk_08485BD8[gUnk_080AFB0B[gUnk_03006F74->unk8]])) {
            play_song(0);
            play_sound_effect(0);
            eeprom_setup_timer_irq();
            gUnk_03006F74->unk2 = 0;
            gUnk_03006F74->unk8++;
        }
        break;
    case 5:
        if (t > 0x1D && !is_sound_playing_with_lock(4)) {
            for (i = 0; i < 4; i++) {
                r = save_dispatch(0);
                if (r == 0)
                    break;
            }
            play_song(gUnk_03006F74->unk7F);
            gUnk_03006F74->unk8 = r;
            gGameSubState += 3;
            sub_0803FB0C();
            serial_link_init();
        }
        break;
    }
}

void sub_08065894(void) {
    if (run_message(gUnk_08485BD8[gUnk_03006F74->unk8 ? 7 : 6]) && KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(0xD);
        if ((s32)++gUnk_03006F74->unk8 > 1) {
            gUnk_03000440.unk84 = 0;
            gUnk_03000440.unk1B = 0;
            gGameSubState--;
        } else
            sub_0803FB0C();
    }
}

void sub_08065908(void) {
    if (game_state_execute_handler_a())
        dispatch_by_index_0476e8(8);
}

void fade_transition_and_input_check(void) {
    if (run_message(gUnk_08485BD8[gUnk_03006F74->unk8 ? 5 : 4])) {
        struct Unk_03006F74 *w = gUnk_03006F74;
        if (w->unk8 == 0) {
            gGameSubState++;
            w->unk3A = w->unk8;
        } else if (KEYS_LO(gNewKeys) & 1) {
            play_sound_effect(0xD);
            gUnk_03000440.unk84 = 0;
            gUnk_03000440.unk1B = 0;
            gGameSubState -= 2;
        }
    }
}

void multiplayer_battle_sync_update(void) {
    struct Unk_03006F74 *w;
    u8 *ready;
    u32 zero;
    struct Unk_03005010 *link;

    if (!(gUnk_03005010.unk0 & 0xF00) && !(gFrameCounter & 0xF))
        serial_link_init();
    sio_start_transfers();
    init_multiplayer_id();
    link = &gUnk_03005010;
    w = gUnk_03006F74;
    ready = &w->unk49;
    link->unk6 = *ready | 0xFF00;
    zero = 0;
    if (link->unk8[gUnk_03000B90][1] == 0xFF01) {
        if (link->unk8[gUnk_03000B90 == 0][1] == 0xFF01) {
            if (gUnk_03000B90 <= 1) {
                gGameSubState++;
                w->unk3A = zero;
                gUnk_03005030 = -1;
                return;
            }
            sub_0803FB0C();
            gUnk_03006F74->unk8 = 1;
            gGameSubState--;
            link->unk6 = zero;
        }
    } else if ((link->unk0 & 3) == 3 && (u16)(link->unk8[gUnk_03000B90 == 0][1] + 0x100) <= 1) {
        link->unk6 = 0xFF01;
        *ready = 1;
        return;
    }
    if (++gUnk_03006F74->unk3A > 300) {
        sub_0803FB0C();
        gUnk_03006F74->unk8 = 1;
        gGameSubState--;
        gUnk_03005010.unk6 = 0;
    } else if (gUnk_03006F74->unk3A > 0x10C) {
        if (gUnk_03005010.unk8[gUnk_03000B90 == 0][1] == 0xFF00)
            gUnk_03006F74->unk3A = 0;
        else
            gUnk_03005010.unk6 = 0;
    }
}

void handle_battle_fade_transition(void) {
    if (gUnk_03000B90 > 1) {
        sub_0803FB0C();
        gUnk_03006F74->unk8 = 1;
        gGameSubState -= 2;
    } else if (gUnk_03005010.unk0 & (1 << gUnk_03000B90)) {
        gGameSubState++;
    } else {
        sub_0803FB0C();
        gUnk_03006F74->unk8 = 1;
        gGameSubState -= 2;
    }
}

void sub_08065B68(void) {
    if (game_state_execute_handler_a())
        dispatch_by_index_0476e8(7);
}

void dispatch_battle_cutscene_substate(void) {
    struct FuncTable8 t = gUnk_080AFB10;
    t.f[gGameSubState]();
}
