// Mode-2 state 21 (dispatch_battle_cutscene_substate, sub-states gUnk_080AFB10), entered from field/field_mode
// (case 4): message and yes/no prompts, saves the game (save_dispatch) and starts the serial link
// (serial_link_init). Name is a guess.
#include "global.h"

void link_start_init(void) {
    gUnk_03006F74->unk7F = sound_current_song();
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
                gGameWork.unk84 = r;
                gGameWork.endModeStep = r;
                gGameSubState++;
                *(u8 *)&gUnk_03001784 |= 2;
            } else
                message_next();
        }
        return;
    }
    switch (gUnk_03006F74->unk8) {
    case 0:
        if (run_message(gUnk_08485BD8[gUnk_080AFB0B[gUnk_03006F74->unk8]]) && KEYS_LO(gNewKeys) & 1) {
            play_sound_effect(0xD);
            gUnk_03006F74->unk8++;
            message_next();
            open_choice_menu(1, 0, 7);
        }
        break;
    case 1:
    case 2:
    case 3:
        if (run_message(gUnk_08485BD8[gUnk_080AFB0B[gUnk_03006F74->unk8]]) && poll_choice_menu()) {
            if (gGameWork.unk2A == 0) {
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
            message_next();
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
        if (t > 0x1D && !is_sound_effect_playing(4)) {
            for (i = 0; i < 4; i++) {
                r = save_dispatch(0);
                if (r == 0)
                    break;
            }
            play_song(gUnk_03006F74->unk7F);
            gUnk_03006F74->unk8 = r;
            gGameSubState += 3;
            message_next();
            serial_link_init();
        }
        break;
    }
}

void link_start_show_messages(void) {
    if (run_message(gUnk_08485BD8[gUnk_03006F74->unk8 ? 7 : 6]) && KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(0xD);
        if ((s32)++gUnk_03006F74->unk8 > 1) {
            gGameWork.unk84 = 0;
            gGameWork.endModeStep = 0;
            gGameSubState--;
        } else
            message_next();
    }
}

// guess: sub-state 2, leaves after the first prompt (field result 8).
void link_start_exit_declined(void) {
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
            gGameWork.unk84 = 0;
            gGameWork.endModeStep = 0;
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
            message_next();
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
        message_next();
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
        message_next();
        gUnk_03006F74->unk8 = 1;
        gGameSubState -= 2;
    } else if (gUnk_03005010.unk0 & (1 << gUnk_03000B90)) {
        gGameSubState++;
    } else {
        message_next();
        gUnk_03006F74->unk8 = 1;
        gGameSubState -= 2;
    }
}

// guess: the last sub-state, after the link session (field result 7).
void link_start_exit_finished(void) {
    if (game_state_execute_handler_a())
        dispatch_by_index_0476e8(7);
}

void dispatch_battle_cutscene_substate(void) {
    struct FuncTable8 t = gUnk_080AFB10;
    t.f[gGameSubState]();
}
