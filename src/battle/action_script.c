// Battle state 9: battle_run_action_script reads the acting Medabot's action script one byte at a time
// and calls gUnk_083AF000[command] (sub_080338DC..sub_08034E78, in ROM order; opcodes 0x1E-0x6A start the
// effect sequences of battle/action_steps and the *_skills / medaforce_effects modules). Ends with the
// script reader (battle_script_read_byte / load_operands / advance).

#include "global.h"

// Runs the acting Medabot's action script (gUnk_083C6B28[gUnk_03001800.unkA8]): commands < 0x80 go to
// gUnk_083AF000, others are skipped; a command sets unk163 to run the next one in the same frame.
void battle_run_action_script(void) {
    if (link_error_check() == 0) {
        if (gUnk_03000430 == 2) {
            u32 fill = 0x200;

            CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
        }
        if (gUnk_03001800.unk1AE == 0)
            update_all_battle_status_sprites();
        do {
            gUnk_03001800.unk163 = 0;
            gGameSubState = battle_script_read_byte();
            while ((s32)gGameSubState > 0x7F) {
                battle_script_advance();
                gGameSubState = battle_script_read_byte();
            }
            gUnk_083AF000[gGameSubState]();
        } while (gUnk_03001800.unk163);
    }
}

void sub_080338DC(void) {
    gGameState = 8;
    gGameSubState = 0x40;
}

void sub_080338F4(void) {
    vu8 found = 0;
    struct Unk_03001800 *s;
    const u8 *const *tbl;
    const u8 *script;

    battle_script_load_operands();
    battle_script_advance();
    while (!found) {
        tbl = gUnk_083C6B28;
        s = &gUnk_03001800;
        script = tbl[s->unkA8];
        if (s->unkAC[0] == script[s->unkBC]) {
            battle_script_advance();
            found = 1;
        } else
            battle_script_advance();
    }
    gUnk_03001800.unk163 = 1;
}

void sub_08033974(void) {
    vu8 found = 0;
    struct Unk_03001800 *s;
    const u8 *const *tbl;
    const u8 *script;

    battle_script_load_operands();
    battle_script_advance();
    while (!found) {
        tbl = gUnk_083C6B28;
        s = &gUnk_03001800;
        script = tbl[s->unkA8];
        if (s->unkAC[s->unkAB] == script[s->unkBC]) {
            battle_script_advance();
            found = 1;
        } else
            battle_script_advance();
    }
    gUnk_03001800.unk163 = 1;
}

void script_op_trap_hit(void) {
    trap_hit_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_action_part_check(void) {
    action_part_check_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08033A2C(void) {
    if (gUnk_03000590[gUnk_03001800.unk87].unkE0 == 0)
        sub_08035478(gUnk_03001800.unk87);
    if (gUnk_03000590[gUnk_03001800.unk87].unkE1 == 0)
        calc_bot_evasion_modifier(gUnk_03001800.unk87);
    sub_080355C4(gUnk_03001800.unk87);
    battle_script_advance();
}

void script_op_target_part_check(void) {
    target_part_check_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_action_flash(void) {
    action_flash_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_guard(void) {
    guard_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_guard_restore(void) {
    if (gUnk_03001800.unkDE) {
        memcpy_bytes_0803F63C(gUnk_03003470, gUnk_03003470 + 0xE40 + ((gUnk_03001800.unkDE - 1) << 8), 0x40);
        memcpy_bytes_0803F63C(gUnk_03003470 + 0x40, gUnk_03003470 + 0xE80 + ((gUnk_03001800.unkDE - 1) << 8), 0x40);
        memcpy_bytes_0803F63C(gUnk_03003470 + 0x80, gUnk_03003470 + 0xEC0 + ((gUnk_03001800.unkDE - 1) << 8), 0x40);
        memcpy_bytes_0803F63C(gUnk_03003470 + 0xC0, gUnk_03003470 + 0xF00 + ((gUnk_03001800.unkDE - 1) << 8), 0x40);
        clear_battle_sprite_slot(0x21, 4);
        set_sprite_hidden_flags(gUnk_03001800.unkDE * 4 + 0x56, 4);
        init_battle_sprite_entry_0801BC04(gUnk_03001800.unkDE - 1);
        gUnk_03001800.unkDE = 0;
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
    }
    battle_script_advance();
}

void sub_08033B7C(void) {
    u32 type = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[2];

    if (type == 0)
        goto both;
    if (type == 1) {
    both:
        gUnk_03000590[gUnk_03001800.unk87].unkBC |= 2;
        if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[2] == 1)
            gUnk_03000590[gUnk_03001800.unk87].unkBC |= 1;
    } else if (type == 3)
        gUnk_03000590[gUnk_03001800.unk87].unkBC |= 1;
    battle_script_advance();
}

void sub_08033C00(void) {
    sub_08038BC0();
    battle_script_advance();
}

void sub_08033C10(void) {
    sub_08038D30();
    battle_script_advance();
}

void sub_08033C20(void) {
    u32 type;

    if (gUnk_03000590[gUnk_03001800.unk88].unkC9 == 0x2E)
        gUnk_03000590[gUnk_03001800.unk88].unkBC |= 4;
    if (gUnk_03000590[gUnk_03001800.unk88].unkC9 == 0x2F)
        gUnk_03000590[gUnk_03001800.unk88].unkBC |= 8;
    type = gUnk_03000590[gUnk_03001800.unk88].unkC9;
    if (type == 0xF)
        goto both;
    if (type == 0x10) {
    both:
        gUnk_03000590[gUnk_03001800.unk88].unkBC |= 0xC;
    }
    if (gUnk_03000590[gUnk_03001800.unk88].unkBC & 1)
        gUnk_03000590[gUnk_03001800.unk88].unkBC |= 4;
    if (gUnk_03000590[gUnk_03001800.unk88].unkBC & 2)
        gUnk_03000590[gUnk_03001800.unk88].unkBC |= 8;
    battle_script_advance();
}

void sub_08033CD0(void) {
    battle_begin_action_phase();
    battle_script_advance();
}

void sub_08033CE0(void) {
    sub_08039188();
    battle_script_advance();
}

void sub_08033CF0(void) {
    sub_080391C4();
    battle_script_advance();
}

void sub_08033D00(void) {
    sub_080392D8();
    battle_script_advance();
}

void sub_08033D10(void) {
    gUnk_03001800.unkEA = gUnk_03001800.unkE8 >> 2;
    battle_script_advance();
}

void sub_08033D30(void) {
    u32 type;

    gUnk_03001800.unkEC = 0;
    gUnk_03001800.unkEC = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[6] + gUnk_03001800.unkEA;
    gUnk_03001800.unkEC += gUnk_03000590[gUnk_03001800.unk87].unkD0;
    type = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[2];
    if (type == 0)
        goto melee;
    if (type == 1) {
    melee:
        gUnk_03001800.unkEC += gUnk_03000590[gUnk_03001800.unk87].unkD3;
    }
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[2] == 2)
        goto ranged;
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[2] == 3) {
    ranged:
        gUnk_03001800.unkEC += gUnk_03000590[gUnk_03001800.unk87].unkD4;
    }
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[2] == 1)
        gUnk_03001800.unkEC += gUnk_03000590[gUnk_03001800.unk87].parts[3].unk12 >> 1;
    type = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
    if (type == 4)
        goto skill;
    if (type == 5) {
    skill:
        gUnk_03001800.unkEC += gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[6];
    }
    if (gUnk_03000590[gUnk_03001800.unk87].unkD6 & 1)
        gUnk_03001800.unkEC += gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[6];
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 0x34 &&
        gUnk_03001800.unk28[gUnk_03001800.unk8A].skill == 0x33)
        gUnk_03001800.unkEC += gUnk_03001800.unk28[gUnk_03001800.unk8A].power;
    sub_08035B9C(gUnk_03001800.unk87);
    subtract_s16_floored(&gUnk_03001800.unkEC, gUnk_03000590[gUnk_03001800.unk88].unkD1);
    if (gUnk_03001800.unkDE != 0 && gUnk_03001800.unkDF == 0x1B)
        subtract_s16_floored(&gUnk_03001800.unkEC, (s16)gUnk_03000590[gUnk_03001800.unk88].unkD8);
    battle_script_advance();
}

void sub_08033F04(void) {
    if (gUnk_03001800.unkDE != 0 && gUnk_03001800.unkDF == 0x1D && gUnk_03001800.unkB8 == 0 &&
        gUnk_03001800.unkEC < (s16)gUnk_03000590[gUnk_03001800.unk88].unkD8) {
        gUnk_03001800.unkB8 = 2;
        gUnk_03001800.unkBE = 1;
    }
    battle_script_advance();
}

void sub_08033F64(void) {
    if (gUnk_03001800.unkDE != 0 && gUnk_03001800.unkDF == 0x1C && gUnk_03001800.unkB8 == 0) {
        gUnk_03001800.unkB8 = 2;
        gUnk_03001800.unkBE = 5;
    }
    battle_script_advance();
}

void sub_08033F9C(void) {
    if ((gUnk_03000590[gUnk_03001800.unk88].unkBD & 0x10) &&
        gUnk_03000590[gUnk_03001800.unk88].parts[gUnk_03000590[gUnk_03001800.unk88].unkDE - 1].unk11 != 0 &&
        gUnk_03001800.unkB7 == 0 && gUnk_03001800.unkEC > (s16)gUnk_03000590[gUnk_03001800.unk88].unkD8)
        gUnk_03001800.unkB7 = 3;
    battle_script_advance();
}

void sub_08034008(void) {
    sub_08035BD4();
    sub_08035BFC(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    battle_script_advance();
}

void script_op_announce_action(void) {
    action_announce_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_closeup_enter(void) {
    gUnk_03000440.unk130 = 1;
    closeup_enter_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034074(void) {
    init_battle_scene_backgrounds();
    battle_advance_dialogue_text();
    battle_advance_action_text();
    clear_battle_sprite_slot(0, 0x28);
    CpuFastSet(gUnk_084E30B8, (void *)0x05000380, 8);
    gUnk_03001800.unk100 = 0;
    gUnk_03001800.unkFB = 0;
    gUnk_03001800.unkFC = 0;
    gUnk_03001800.unkFD = 0;
    gUnk_03001800.unkFE = 0;
    if (gUnk_03000590[gUnk_03001800.unk87].unkDD <= 3)
        gUnk_03001800.unkF9 = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
    else
        gUnk_03001800.unkF9 = gUnk_03000590[gUnk_03001800.unk87].unkA8[0] + 0x50;
    gSpriteEntries[1].unk29 = 1;
    gSpriteEntries[2].unk29 = 1;
    battle_script_advance();
}

void sub_08034120(void) {
    init_battle_scene_backgrounds();
    gUnk_03001800.unk15F = battle_advance_dialogue_text();
    gUnk_03001800.unk160 = battle_advance_action_text();
    gUnk_03001800.unkB5 = 0;
    battle_sequence_update();
    if (gUnk_03001800.unkB5) {
        gUnk_03000440.unk130 = 0;
        battle_script_advance();
    }
}

void script_op_set_damage(void) {
    init_battle_scene_backgrounds();
    gUnk_03001800.unk15F = battle_advance_dialogue_text();
    gUnk_03001800.unk160 = battle_advance_action_text();
    gUnk_03001800.unkD0 = gUnk_03001800.unk8B;
    battle_set_damage_vs_armor(gUnk_03001800.unk88, gUnk_03001800.unkD0, gUnk_03001800.unkEC);
    battle_script_advance();
}

void script_op_attack_hit(void) {
    init_battle_scene_backgrounds();
    gUnk_03001800.unk15F = battle_advance_dialogue_text();
    gUnk_03001800.unk160 = battle_advance_action_text();
    attack_hit_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_status_attack(void) {
    init_battle_scene_backgrounds();
    gUnk_03001800.unk15F = battle_advance_dialogue_text();
    gUnk_03001800.unk160 = battle_advance_action_text();
    status_attack_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_closeup_exit(void) {
    closeup_exit_run();
    if (gUnk_03001800.unkB5) {
        gUnk_03000440.unk130 = 0;
        battle_script_advance();
    }
}

void script_op_bot_defeat(void) {
    bot_defeat_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_reaction(void) {
    init_battle_scene_backgrounds();
    gUnk_03001800.unk15F = battle_advance_dialogue_text();
    gUnk_03001800.unk160 = battle_advance_action_text();
    reaction_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_sacrifice(void) {
    sacrifice_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_destroy_check(void) {
    destroy_check_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_recovery(void) {
    recovery_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_recovery_heal(void) {
    init_battle_scene_backgrounds();
    gUnk_03001800.unk15F = battle_advance_dialogue_text();
    gUnk_03001800.unk160 = battle_advance_action_text();
    recovery_heal_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_repair(void) {
    repair_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_repair_apply(void) {
    init_battle_scene_backgrounds();
    gUnk_03001800.unk15F = battle_advance_dialogue_text();
    gUnk_03001800.unk160 = battle_advance_action_text();
    repair_apply_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_trap(void) {
    trap_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_break_form(void) {
    break_form_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_stability(void) {
    stability_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_force_bind(void) {
    force_bind_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_defence(void) {
    defence_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_autorecover(void) {
    autorecover_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_reactivate(void) {
    reactivate_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_scout(void) {
    scout_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_conceal(void) {
    conceal_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_boost_charge(void) {
    boost_charge_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_rapid_charge(void) {
    rapid_charge_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_drain_charge(void) {
    drain_charge_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_pushover(void) {
    pushover_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_impair(void) {
    impair_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_confusion(void) {
    confusion_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_use_drain(void) {
    use_drain_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_no_escape_defense(void) {
    no_escape_defense_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_forcedrain(void) {
    forcedrain_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_team_attack_check(void) {
    team_attack_check_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_team_attack_turrets(void) {
    team_attack_turrets_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_clear_queued_action(void) {
    gUnk_03001800.unk28[gUnk_03001800.unk8A].active = 0;
    gUnk_03001800.unk28[gUnk_03001800.unk8A].skill = 0;
    gUnk_03001800.unk28[gUnk_03001800.unk8A].durability = 0;
    gUnk_03001800.unk28[gUnk_03001800.unk8A].power = 0;
    battle_script_advance();
}

void script_op_counter_attack(void) {
    counter_attack_run();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void script_op_change(void) {
    change_run();
    if (gUnk_03001800.unkB5) {
        if (gUnk_03001800.unkAB == 1)
            battle_script_advance();
        else {
            gGameState = 8;
            gGameSubState = 0;
        }
    }
}

void sub_08034684(void) {
    init_battle_scene_backgrounds();
    gUnk_03001800.unk15F = battle_advance_dialogue_text();
    gUnk_03001800.unk160 = battle_advance_action_text();
    sub_08026884();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_080346C4(void) {
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    gUnk_03000590[gUnk_03001800.unk87].unkE0 = select_random_battle_target(gUnk_03001800.unk60) + 1;
    calc_bot_evasion_modifier(gUnk_03001800.unk87);
    sub_080355C4(gUnk_03001800.unk87);
    battle_script_advance();
}

void sub_08034708(void) {
    sub_0803769C(gUnk_03001800.unk87);
    sub_080376F4(gUnk_03001800.unk87);
    battle_script_advance();
}

void sub_08034728(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk87].parts[i].unk11 != 0) {
            u32 type = gUnk_03000590[gUnk_03001800.unk87].parts[i].data[2];

            if (type == 2)
                goto add;
            if (type == 3) {
            add:
                gUnk_03001800.unkEC += gUnk_03000590[gUnk_03001800.unk87].parts[i].data[6];
            }
        }
    }
    battle_script_advance();
}

void sub_0803476C(void) {
    init_battle_scene_backgrounds();
    gUnk_03001800.unk15F = battle_advance_dialogue_text();
    gUnk_03001800.unk160 = battle_advance_action_text();
    sub_08026CF4();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_080347AC(void) {
    side_add_action_point();
    battle_script_advance();
}

void sub_080347BC(void) {
    u32 i;

    for (i = 0; i <= 3; i++)
        gUnk_03001800.unkEC +=
            gUnk_03000590[gUnk_03001800.unk87].parts[i].data[4] - gUnk_03000590[gUnk_03001800.unk87].parts[i].unk11;
    battle_script_advance();
}

void sub_080347F8(void) {
    init_battle_scene_backgrounds();
    gUnk_03001800.unk15F = battle_advance_dialogue_text();
    gUnk_03001800.unk160 = battle_advance_action_text();
    gUnk_03001800.unkF6 = 3;
    gUnk_03000590[gUnk_03001800.unk87].unkE0 = gUnk_03001800.unk87 + 1;
    gUnk_03001800.unk161 = gUnk_03001800.unk88;
    sub_080355C4(gUnk_03001800.unk87);
    gUnk_03001800.unkF8 ^= 2;
    if (!(gUnk_03001800.unkF8 & 2))
        gUnk_03001800.unk114[0] = 0;
    else {
        gUnk_03001800.unk114[0] = 0x28;
        gUnk_03001800.unkFF |= 1;
    }
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03001800.unk114[1] = 0x28;
        gUnk_03001800.unkFF |= 2;
    } else
        gUnk_03001800.unk114[1] = 0;
    battle_script_advance();
}

void sub_080348D0(void) {
    init_battle_scene_backgrounds();
    gUnk_03001800.unk15F = battle_advance_dialogue_text();
    gUnk_03001800.unk160 = battle_advance_action_text();
    sub_08026ED0();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034910(void) {
    u32 i;

    for (i = 0; i <= 3; i++) {
        gUnk_03001800.unkD6[i] = gUnk_03000590[gUnk_03001800.unk87].parts[i].unk11 >> 1;
        gUnk_03001800.unkEC += gUnk_03000590[gUnk_03001800.unk87].parts[i].unk11 >> 1;
    }
    battle_script_advance();
}

void sub_0803496C(void) {
    u32 i, j;

    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unkBA != 0) {
            for (j = 0; j <= 3; j++) {
                if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[j].unk11 == 0)
                    gUnk_03001800.unkEC += 10;
            }
        }
    }
    battle_script_advance();
}

void sub_080349D8(void) {
    u32 t;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    t = sub_08037798(gUnk_03001800.unk60);
    if (t != 0xFF) {
        gUnk_03000590[gUnk_03001800.unk87].unkE0 = t + 1;
        gUnk_03000590[gUnk_03001800.unk87].unkE1 = gUnk_03000590[t].unkDE;
    } else {
        gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
        gUnk_03000590[gUnk_03001800.unk87].unkE0 = select_random_battle_target(gUnk_03001800.unk60) + 1;
        calc_bot_evasion_modifier(gUnk_03001800.unk87);
        gUnk_03001800.unkB8 = 2;
    }
    sub_080355C4(gUnk_03001800.unk87);
    battle_script_advance();
}

void sub_08034A68(void) {
    gUnk_03001800.unkEC = gUnk_03000590[gUnk_03001800.unk88].parts[gUnk_03001800.unk8B].unk11;
    battle_script_advance();
}

void sub_08034AA0(void) {
    gUnk_03001800.unk188 = gUnk_083AF200[rng_next_byte() & 0xF];
    gUnk_03001800.unk189 = gUnk_083AF200[rng_next_byte() & 0xF];
    gUnk_03001800.unkEC = (gUnk_03001800.unk188 + gUnk_03001800.unk189) * 10;
    battle_script_advance();
}

void sub_08034AF4(void) {
    u32 t;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    t = battle_select_random_target(gUnk_03001800.unk60, gUnk_03001800.unk87);
    if (t != 0xFF)
        gUnk_03000590[gUnk_03001800.unk87].unkE0 = t + 1;
    else {
        gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
        gUnk_03000590[gUnk_03001800.unk87].unkE0 = select_random_battle_target(gUnk_03001800.unk60) + 1;
    }
    calc_bot_evasion_modifier(gUnk_03001800.unk87);
    sub_080355C4(gUnk_03001800.unk87);
    battle_script_advance();
}

void sub_08034B68(void) {
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    if (battle_select_random_target(gUnk_03001800.unk60, gUnk_03001800.unk87) == 0xFF)
        gUnk_03001800.unkEC = 10;
    battle_script_advance();
}

void sub_08034BA0(void) {
    sub_08026FD0();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034BBC(void) {
    sub_0802793C();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034BD8(void) {
    sub_08027F5C();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034BF4(void) {
    sub_08028248();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034C10(void) {
    sub_08028404();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034C2C(void) {
    sub_08028C40();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034C48(void) {
    sub_080294B4();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034C64(void) {
    sub_08029840();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034C80(void) {
    sub_08029E0C();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034C9C(void) {
    sub_0802A0E8();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034CB8(void) {
    sub_0802A6AC();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034CD4(void) {
    sub_0802AAD0();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034CF0(void) {
    sub_0802ACCC();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034D0C(void) {
    sub_0802B000();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034D28(void) {
    sub_0802B7E8();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034D44(void) {
    sub_0802BD6C();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034D60(void) {
    sub_0802C2AC();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034D7C(void) {
    sub_0802C644();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034D98(void) {
    sub_0802CBE8();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034DB4(void) {
    sub_0802D688();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034DD0(void) {
    sub_0802DCB4();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034DEC(void) {
    battle_dispatch_phase_handler_0802E424();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034E08(void) {
    sub_0802EBC0();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034E24(void) {
    sub_0802F030();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034E40(void) {
    sub_0802F628();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034E5C(void) {
    sub_0802F990();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

void sub_08034E78(void) {
    sub_0802FE50();
    if (gUnk_03001800.unkB5)
        battle_script_advance();
}

s32 battle_script_read_byte(void) {
    const u8 *script = gUnk_083C6B28[gUnk_03001800.unkA8];
    return script[gUnk_03001800.unkBC];
}

void battle_script_load_operands(void) {
    const u8 *script = gUnk_083C6B28[gUnk_03001800.unkA8];
    u32 n = gUnk_083C6D38[script[gUnk_03001800.unkBC]];
    u32 i;
    for (i = 0; i < n; i++)
        gUnk_03001800.unkAC[i] = script[gUnk_03001800.unkBC + i + 1];
}

void battle_script_advance(void) {
    struct Unk_03001800 *b = &gUnk_03001800;
    const u8 *script;
    const u8 *len;
    u16 *pc;
    s32 n;

    b->unkAA = 0;
    script = gUnk_083C6B28[b->unkA8];
    len = gUnk_083C6D38;
    pc = &b->unkBC;
    n = *pc;
    *pc = n + 1 + len[script[n]];
}
