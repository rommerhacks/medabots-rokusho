// Mode-2 state 21 (dispatch_battle_cutscene_substate, sub-states gLinkStartStates), entered from field/field_mode
// (case 4): message and yes/no prompts, saves the game (save_dispatch) and starts the serial link
// (serial_link_init). Name is a guess.
#include "global.h"

void link_start_init(void) {
    gMenuWork->saved_song = sound_current_song();
    text_window_init(1, 0, 0);
    gMenuWork->step = 0;
    gGameSubState++;
}

void battle_cutscene_dispatch(void) {
    u8 elapsed;
    u16 save_err;
    s8 i;

    elapsed = gMenuWork->timer++;
    save_err = 0;
    // FAKEMATCH: byte access to gSaveStatus (bit 1 linkIntroSeen, bit 0 saveExists); the bitfield loads a word
    if (!(*(u8 *)&gSaveStatus & 2)) {
        if (run_message(gLinkMenuMessages[gLinkIntroMessageIds[gMenuWork->step]]) && KEYS_LO(gNewKeys) & 1) {
            play_sound_effect(0xD);
            if (++gMenuWork->step > 2) {
                gGameWork.stepCounter = save_err;
                gGameWork.endModeStep = save_err;
                gGameSubState++;
                *(u8 *)&gSaveStatus |= 2;
            } else
                message_next();
        }
        return;
    }
    switch (gMenuWork->step) {
    case 0:
        if (run_message(gLinkMenuMessages[gLinkStartMessageIds[gMenuWork->step]]) && KEYS_LO(gNewKeys) & 1) {
            play_sound_effect(0xD);
            gMenuWork->step++;
            message_next();
            open_choice_menu(1, 0, 7);
        }
        break;
    case 1:
    case 2:
    case 3:
        if (run_message(gLinkMenuMessages[gLinkStartMessageIds[gMenuWork->step]]) && poll_choice_menu()) {
            if (gGameWork.choiceCursor == 0) {
                if (*(u8 *)&gSaveStatus & 1) {
                    if (++gMenuWork->step <= 3)
                        open_choice_menu(1, 0, 7);
                } else {
                    if (++gMenuWork->step <= 2)
                        open_choice_menu(1, 0, 7);
                    else
                        gMenuWork->step++;
                }
            } else {
                gMenuWork->step = 0;
                gGameSubState += 2;
            }
            message_next();
        }
        break;
    case 4:
        if (run_message(gLinkMenuMessages[gLinkStartMessageIds[gMenuWork->step]])) {
            play_song(0);
            play_sound_effect(0);
            eeprom_setup_timer_irq();
            gMenuWork->timer = 0;
            gMenuWork->step++;
        }
        break;
    case 5:
        if (elapsed > 0x1D && !is_sound_effect_playing(4)) {
            for (i = 0; i < 4; i++) {
                save_err = save_dispatch(0);
                if (save_err == 0)
                    break;
            }
            play_song(gMenuWork->saved_song);
            gMenuWork->step = save_err;
            gGameSubState += 3;
            message_next();
            serial_link_init();
        }
        break;
    }
}

void link_start_show_messages(void) {
    if (run_message(gLinkMenuMessages[gMenuWork->step ? 7 : 6]) && KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(0xD);
        if ((s32)++gMenuWork->step > 1) {
            gGameWork.stepCounter = 0;
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
    if (run_message(gLinkMenuMessages[gMenuWork->step ? 5 : 4])) {
        struct MenuWork *w = gMenuWork;
        if (w->step == 0) {
            gGameSubState++;
            w->frame = w->step;
        } else if (KEYS_LO(gNewKeys) & 1) {
            play_sound_effect(0xD);
            gGameWork.stepCounter = 0;
            gGameWork.endModeStep = 0;
            gGameSubState -= 2;
        }
    }
}

void multiplayer_battle_sync_update(void) {
    struct MenuWork *w;
    u8 *ready;
    u32 zero;
    struct LinkPackets *link;

    if (!(gLinkPackets.status & 0xF00) && !(gFrameCounter & 0xF))
        serial_link_init();
    sio_start_transfers();
    init_multiplayer_id();
    link = &gLinkPackets;
    w = gMenuWork;
    ready = &w->aux;
    link->sendData = *ready | 0xFF00;
    zero = 0;
    if (link->recv[gLinkPlayerId][1] == 0xFF01) {
        if (link->recv[gLinkPlayerId == 0][1] == 0xFF01) {
            if (gLinkPlayerId <= 1) {
                gGameSubState++;
                w->frame = zero;
                gLinkMultiplayerActive = -1;
                return;
            }
            message_next();
            gMenuWork->step = 1;
            gGameSubState--;
            link->sendData = zero;
        }
    } else if ((link->status & 3) == 3 && (u16)(link->recv[gLinkPlayerId == 0][1] + 0x100) <= 1) {
        link->sendData = 0xFF01;
        *ready = 1;
        return;
    }
    if (++gMenuWork->frame > 300) {
        message_next();
        gMenuWork->step = 1;
        gGameSubState--;
        gLinkPackets.sendData = 0;
    } else if (gMenuWork->frame > 0x10C) {
        if (gLinkPackets.recv[gLinkPlayerId == 0][1] == 0xFF00)
            gMenuWork->frame = 0;
        else
            gLinkPackets.sendData = 0;
    }
}

void handle_battle_fade_transition(void) {
    if (gLinkPlayerId > 1) {
        message_next();
        gMenuWork->step = 1;
        gGameSubState -= 2;
    } else if (gLinkPackets.status & (1 << gLinkPlayerId)) {
        gGameSubState++;
    } else {
        message_next();
        gMenuWork->step = 1;
        gGameSubState -= 2;
    }
}

// guess: the last sub-state, after the link session (field result 7).
void link_start_exit_finished(void) {
    if (game_state_execute_handler_a())
        dispatch_by_index_0476e8(7);
}

void dispatch_battle_cutscene_substate(void) {
    struct FuncTable8 states = gLinkStartStates;
    states.f[gGameSubState]();
}
