#include "global.h"

// Battle action phase, every frame: unless waiting on the serial link, runs the gUnk_083AEB58 step for
// gGameSubState (load sprites 0x08030890, turn cursor 0x08030910 / 0x08030990, choice check sub_080309C8,
// resolve_battle_action_phase; runtime-checked in the battle scenario).
void battle_action_state_update(void) {
    if (sub_0803EED8() == 0) {
        sub_0803E780();
        update_all_battle_status_sprites();
        gUnk_083AEB58[gGameSubState]();
    }
}

void sub_08030890(void) {
    switch (gUnk_03000440.unk139) {
    case 0:
        reset_bot_status_and_init_palette_transfers(gUnk_03001800.unk87);
        copy_battle_entity_positions();
        gUnk_03000440.unk139++;
        break;
    case 1:
        lz_decompress_dispatch(gUnk_084C8AC4, (void *)0x06014E00);
        gUnk_03000440.unk139++;
        break;
    case 2:
        CpuFastSet(gUnk_084E2FF8, (void *)0x050002C0, 8);
        gGameSubState++;
        gUnk_03000440.unk139 = 0;
        break;
    }
}

void sub_08030910(void) {
    gUnk_03002C30[3].unk0 = 0xC004;
    gUnk_03002C30[3].unk1C = 0;
    gUnk_03002C30[3].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[3].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[3].unkA = 6;
    gUnk_03002C30[3].unkB = 0x81;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x15], 3);
    play_sound_effect(7);
    gGameSubState++;
}

void sub_08030990(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x15], 3);
    if (gUnk_03002C30[3].unk22 == 0xFF) {
        clear_battle_sprite_slot(3, 1);
        gGameSubState++;
    }
}

// Fails with message 4 when the acting Medabot has unkBD bit 0 set; no part chosen (unkDD == 0) goes to
// sub-state 0x10, otherwise on to resolve_battle_action_phase.
void sub_080309C8(void) {
    if (gUnk_03000590[gUnk_03001800.unk87].unkBD & 1) {
        gUnk_03001800.unkA6 = 4;
        gGameSubState = 0x20;
    } else if (gUnk_03000590[gUnk_03001800.unk87].unkDD == 0)
        gGameSubState = 0x10;
    else
        gGameSubState++;
}

void resolve_battle_action_phase(void) {
    sub_0801B67C(gUnk_03001800.unk87);
    if (gUnk_03000590[gUnk_03001800.unk87].unkBD & 1) {
        gUnk_03001800.unkA6 = 4;
        gGameSubState = 0x20;
        return;
    }
    if (gUnk_03000590[gUnk_03001800.unk87].unkDD <= 3 &&
        gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03000590[gUnk_03001800.unk87].unkDD - 1].unk11 == 0) {
        gUnk_03001800.unkA6 = 5;
        gGameSubState = 0x20;
        return;
    }
    if (gUnk_03000590[gUnk_03001800.unk87].unkC9 == 0x2B &&
        gUnk_03000590[gUnk_03001800.unk87].unkCA == gUnk_03000590[gUnk_03001800.unk87].unkDD) {
        gUnk_03001800.unkA6 = 6;
        gGameSubState = 0x20;
        return;
    }
    if (gUnk_03000590[gUnk_03001800.unk87].unkDD > 3) {
        gUnk_03001800.unkA7 = gUnk_03000590[gUnk_03001800.unk87].unkDD - 4;
        gGameSubState = 0x30;
        return;
    }
    gUnk_03001800.unk164 = 1;
    select_next_bot_and_action(gUnk_03001800.unk87);
    if (part_skill_is_passive(gUnk_03001800.unk87, gUnk_03000590[gUnk_03001800.unk87].unkDD - 1)) {
        gUnk_03001800.unkA6 = 7;
        gGameSubState = 0x20;
        return;
    }
    if (gUnk_03000590[gUnk_03001800.unk87].unkDD == 1 && gUnk_03001800.unk118 != 1) {
        if (gUnk_03000590[gUnk_03001800.unk87].parts[0].unk10 == 0) {
            gUnk_03001800.unkA6 = 8;
            gGameSubState = 0x20;
            return;
        }
        gUnk_03000590[gUnk_03001800.unk87].parts[0].unk10--;
    }
    if (gUnk_03000590[gUnk_03001800.unk87].unkE0) {
        if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03000590[gUnk_03001800.unk87].unkDD - 1].data[1] == 0x21) {
            if (gUnk_03000590[gUnk_03000590[gUnk_03001800.unk87].unkE0 - 1].unk40) {
                gUnk_03001800.unkA6 = 9;
                gGameSubState = 0x20;
                return;
            }
        } else if (gUnk_03000590[gUnk_03000590[gUnk_03001800.unk87].unkE0 - 1].unk40 == 0) {
            gUnk_03001800.unkA6 = 0xA;
            gGameSubState = 0x20;
            return;
        }
    }
    if (gUnk_03000590[gUnk_03001800.unk87].unkE1) {
        if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03000590[gUnk_03001800.unk87].unkDD - 1].data[1] == 0x20) {
            if (gUnk_03000590[gUnk_03000590[gUnk_03001800.unk87].unkE0 - 1]
                    .parts[gUnk_03000590[gUnk_03001800.unk87].unkE1 - 1]
                    .unk11) {
                gUnk_03001800.unkA6 = 0xB;
                gGameSubState = 0x20;
                return;
            }
        } else if (gUnk_03000590[gUnk_03000590[gUnk_03001800.unk87].unkE0 - 1]
                       .parts[gUnk_03000590[gUnk_03001800.unk87].unkE1 - 1]
                       .unk11 == 0) {
            gUnk_03001800.unkA6 = 0xC;
            gGameSubState = 0x20;
            return;
        }
    }
    gUnk_03001800.unkA8 =
        gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03000590[gUnk_03001800.unk87].unkDD - 1].data[1];
    gUnk_03001800.unkA7 = gUnk_03000590[gUnk_03001800.unk87].unkDD - 1;
    gGameState = 9;
    gGameSubState = 0;
}

void sub_08030C94(void) {
    gGameSubState = 0x40;
}

void sub_08030CA0(void) {
    gGameSubState = 0x50;
}

void sub_08030CAC(void) {
    CpuFastSet(gUnk_084E2EF8, (void *)0x05000300, 8);
    CpuFastSet(gUnk_084E2F18, (void *)0x05000320, 8);
    CpuFastSet(gUnk_084E2F38, (void *)0x05000340, 8);
    gGameState = 7;
    gGameSubState = 0x46;
}

void sub_08030CFC(void) {
    if (gUnk_03000590[gUnk_03001800.unk87].unkC1 == 0x50)
        gGameSubState++;
    else {
        sub_0801AEB4();
        gGameSubState = 0x14;
    }
}

void sub_08030D3C(void) {
    if (sub_0801C154())
        gGameSubState++;
}

void sub_08030D58(void) {
    if (sub_0801C0BC(0))
        gGameSubState++;
}

void sub_08030D74(void) {
    if (dispatch_battle_action_substate(0))
        gGameSubState++;
}

void sub_08030D90(void) {
    dispatch_battle_action_substate(0);
    if (sub_0801C0BC(1))
        gGameSubState++;
}

void sub_08030DB4(void) {
    dispatch_battle_action_substate(0);
    play_sound_effect(0x51);
    if (gUnk_03000590[gUnk_03001800.unk87].unkC0 & 8)
        gUnk_03001800.unk51 = 0x50;
    else
        gUnk_03001800.unk51 = 0x28;
    sub_0801B004(gUnk_03001800.unk87);
    gGameSubState++;
}

void sub_08030E14(void) {
    u32 done;

    dispatch_battle_action_substate(0);
    done = medaforce_gauge_fill_step(gUnk_03001800.unk87);
    done += sub_0801B0E8(gUnk_03001800.unk87);
    if (done == 2) {
        clear_battle_ui_tilemaps();
        sub_0801AEB4();
        gGameSubState++;
    }
}

void sub_08030E54(void) {
    if (sub_0801C0BC(gUnk_03001800.unkA6))
        gGameSubState++;
}

void sub_08030E78(void) {
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    increment_medal_skill_level(gUnk_03001800.unk87);
    sub_0801B274(gUnk_03001800.unk87);
    gUnk_03000440.unk9C = 0;
    if (gUnk_03000590[0].unk40 == 0) {
        gUnk_03000440.unk9C = 2;
        sound_stop_all_with_fade_guard(4);
        play_sound_effect(0x6F);
        gGameSubState++;
    } else if (gUnk_03000590[3].unk40 == 0) {
        gUnk_03000440.unk9C = 1;
        sound_stop_all_with_fade_guard(4);
        play_sound_effect(0x6F);
        gGameSubState++;
    } else
        gGameSubState = 0x48;
}

void sub_08030F10(void) {
    lz_decompress_dispatch(gUnk_084C84E4, (void *)0x06014800);
    CpuFastSet(gUnk_084E2FD8, (void *)0x050003E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC624;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = 0x78;
    gUnk_03002C30[0x21].unk4 = 0x40;
    gUnk_03002C30[0x21].unkA = 0xF;
    gUnk_03002C30[0x21].unkB = 0xC0;
    gUnk_03002C30[0x21].unk6 = 0x902;
    gUnk_03002C30[0x21].unk9 = 0x80;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gGameSubState++;
}

void sub_08030FB4(void) {
    if (gUnk_03002C30[0x21].unk9 == 0x40) {
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    } else
        gUnk_03002C30[0x21].unk9 -= 8;
}

void sub_08030FEC(void) {
    if (gUnk_03000440.unk86 == 0x5A) {
        if (gUnk_03002C30[0x21].unk9 == 8) {
            play_song(0x1C);
            clear_battle_sprite_slot(0x21, 1);
            text_window_init(1, 2, 0);
            gGameSubState++;
        } else
            gUnk_03002C30[0x21].unk9 -= 8;
    } else
        gUnk_03000440.unk86++;
}

void sub_08031048(void) {
    if (gUnk_03000440.unk86 == 0x5A) {
        if (gUnk_03002C30[0x21].unk9 == 8) {
            clear_battle_sprite_slot(0x21, 1);
            text_window_init(1, 2, 0);
            gGameSubState++;
        } else
            gUnk_03002C30[0x21].unk9 -= 8;
    } else
        gUnk_03000440.unk86++;
}

void sub_080310A0(void) {
    if (gUnk_03000440.unk9C == 1)
        memcpy_bytes_0803F63C(gUnk_03002B74, gUnk_03000440.unk9E, 0xE);
    else if (gUnk_03000440.unk89 != 1)
        memcpy_bytes_0803F63C(gUnk_083C3F38[gUnk_03001800.unk0], gUnk_03000440.unk9E, 0x12);
    else
        memcpy_bytes_0803F63C(gUnk_0300198A, gUnk_03000440.unk9E, 0x12);
    if (run_message(gUnk_083C65C4[2]))
        gGameSubState++;
}

void sub_08031120(void) {
    if (gUnk_03001800.unk57) {
        if (gUnk_03001800.unk165)
            gGameSubState = 0x60;
        else
            gGameSubState = 0x4F;
    } else {
        robattle_judge_time_up();
        play_song(0x11);
        gGameSubState++;
    }
}

void sub_08031174(void) {
    lz_decompress_dispatch(gUnk_084C84E4, (void *)0x06014800);
    CpuFastSet(gUnk_084E2FD8, (void *)0x050003E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC624;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = 0x78;
    gUnk_03002C30[0x21].unk4 = 0x40;
    gUnk_03002C30[0x21].unkA = 0xF;
    gUnk_03002C30[0x21].unkB = 0xC0;
    gUnk_03002C30[0x21].unk6 = 0x903;
    gUnk_03002C30[0x21].unk9 = 0x80;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gGameSubState++;
}

void sub_08031218(void) {
    if (gUnk_03000440.unk9C == 1)
        memcpy_bytes_0803F63C(gUnk_03002B74, gUnk_03000440.unk9E, 0xE);
    else if (gUnk_03000440.unk89 != 1)
        memcpy_bytes_0803F63C(gUnk_083C3F38[gUnk_03001800.unk0], gUnk_03000440.unk9E, 0x12);
    else
        memcpy_bytes_0803F63C(gUnk_0300198A, gUnk_03000440.unk9E, 0x12);
    if (run_message(gUnk_083C65C4[3]))
        gGameSubState++;
}

void sub_08031298(void) {
    if (gUnk_03000440.unk89 != 1) {
        sound_stop_all_with_fade_guard(8);
        gGameSubState++;
    } else
        gGameSubState = 0x58;
}

void sub_080312CC(void) {
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_080312F0(void) {
    if (gUnk_03000440.unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else
        gGameSubState++;
}

void sub_0803133C(void) {
    gVBlankCallback = nullsub_08000840;
    gUnk_03000440.unk132 = 1;
    if (gUnk_03000440.unk89 != 1) {
        gGameState = 6;
        gGameSubState = 0x30;
    } else {
        gGameState = 10;
        gGameSubState = 0x20;
    }
}

void sub_08031390(void) {
    lz_decompress_dispatch(gUnk_084D796C, (void *)0x06014800);
    gUnk_03002C30[0x21].unk0 = 0xC404;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 0xC;
    gUnk_03002C30[0x21].unkB = 0x80;
    gUnk_03002C30[0x21].unk6 = 0x5800;
    gUnk_03002C30[0x21].unk23 = 0;
    play_sound_effect(0x2A);
    gGameSubState++;
}

void sub_08031438(void) {
    if (advance_sprite_anim_frame(0x21, 0))
        gGameSubState++;
}

void sub_08031458(void) {
    gUnk_03002C30[0x22].unk0 = 0xC404;
    gUnk_03002C30[0x22].unk1C = 0;
    gUnk_03002C30[0x22].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x10;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 + 4;
    gUnk_03002C30[0x22].unkA = gUnk_083AED18[gUnk_03001800.unk166];
    gUnk_03002C30[0x22].unkB = 0x80;
    gUnk_03002C30[0x22].unk6 = 0x5801 + gUnk_03001800.unk166;
    gUnk_03002C30[0x22].unk23 = 0;
    play_sound_effect(0x2A);
    gGameSubState++;
}

void sub_08031518(void) {
    if (medal_update_exp_progress(0x22, 0))
        gGameSubState++;
}

void sub_08031538(void) {
    lz_decompress_dispatch(gUnk_084D6BFC, (void *)0x06017E00);
    set_display_digit_type(&gUnk_03000440.unkEE, gUnk_03001800.unk167, 2);
    battle_setup_text_sprites_0801A4F4(&gUnk_03000440.unkEE, gUnk_03001800.unk87, 0x23,
                                       gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18,
                                       gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 + 4);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_080315B0(void) {
    update_battle_sprite_animations(&gUnk_03000440.unkEE, gUnk_03001800.unk87, 0x23);
    if (++gUnk_03000440.unk84 == 0x78) {
        clear_battle_sprite_slot(0x21, 2);
        clear_battle_sprite_slot(gUnk_03001800.unk87 * 4 + 0x23, 4);
        gGameSubState++;
    }
}

void sub_08031608(void) {
    gGameSubState = 0x4F;
}

void sub_08031614(void) {
    sub_0801AEB4();
    if (gUnk_03001800.unk58) {
        gUnk_03001800.unkA6 = 0x79;
        gGameSubState++;
    } else if (gUnk_03001800.unkA7 == 0 && gUnk_03000590[gUnk_03001800.unk87].medal.unk5 <= 9) {
        gUnk_03001800.unkA6 = 0x36;
        gGameSubState++;
    } else if (gUnk_03001800.unkA7 == 1 && gUnk_03000590[gUnk_03001800.unk87].medal.unk5 <= 0x1D) {
        gUnk_03001800.unkA6 = 0x36;
        gGameSubState++;
    } else if (gUnk_03001800.unkA7 == 2 && gUnk_03000590[gUnk_03001800.unk87].medal.unk5 <= 0x3B) {
        gUnk_03001800.unkA6 = 0x36;
        gGameSubState++;
    } else if (gUnk_03000590[gUnk_03001800.unk87].unkC1 != 0x50) {
        gUnk_03001800.unkA6 = 0x37;
        gGameSubState++;
    } else
        gGameSubState = 0x34;
}

void sub_08031704(void) {
    dispatch_battle_action_substate(0);
    CpuFastSet(gUnk_084E3018, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = ((gUnk_03001800.unk39[3] + 2) << 10) | 0xC004;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0x81;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x4D], 0x21);
    gUnk_03002C30[0x22].unk0 = ((gUnk_03001800.unk39[3] + 2) << 10) | 0xC004;
    gUnk_03002C30[0x22].unk1C = 0;
    gUnk_03002C30[0x22].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x22].unkA = 7;
    gUnk_03002C30[0x22].unkB = gUnk_03001800.unk87 * 4 + 0x59;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x4E], 0x22);
    gUnk_03001800.unk51 = gUnk_03000590[gUnk_03001800.unk87].unkA8[2];
    gGameSubState++;
}

void sub_0803185C(void) {
    dispatch_battle_action_substate(0);
    medaforce_gauge_drain_step(gUnk_03001800.unk87);
    process_sprite_anim_commands(gUnk_083B5F80[0x4D], 0x21);
    process_sprite_anim_commands(gUnk_083B5F80[0x4E], 0x22);
    if (gUnk_03002C30[0x21].unk22 == 0xFF) {
        clear_battle_ui_tilemaps();
        sub_0801AEB4();
        clear_battle_sprite_slot(0x21, 2);
        gGameSubState++;
    }
}

void sub_080318CC(void) {
    memcpy_bytes_0803F63C((void *)gUnk_083B7338[gUnk_03000590[gUnk_03001800.unk87].unkA8[0]], gUnk_03000440.unk9E,
                          0x11);
    gUnk_03001800.unkA6 = 0x38;
    gGameSubState++;
}

void battle_start_transition_to_action(void) {
    gUnk_03001800.unk164 = 1;
    gUnk_03001800.unkA8 = gUnk_03000590[gUnk_03001800.unk87].unkA8[0] + 0x50;
    gUnk_03000590[gUnk_03001800.unk87].unkE0 = 0;
    gUnk_03000590[gUnk_03001800.unk87].unkE1 = 0;
    gGameState = 9;
    gGameSubState = 0;
}

void sub_08031978(void) {
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void sub_08031994(void) {
    if (run_message(gUnk_083CF3B0[1]))
        gGameSubState++;
}

void sub_080319B8(void) {
    if (sub_0803E79C()) {
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
}

void sub_080319E0(void) {
    if (gUnk_03000440.unk86 == 8)
        gGameSubState++;
    else
        gUnk_03000440.unk86++;
}

void sub_08031A08(void) {
    if (game_state_execute_handler_a())
        gGameSubState++;
}

void sub_08031A24(void) {
    sound_stop_all_with_fade_guard(8);
    gGameSubState = 0x51;
}
