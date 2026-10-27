// Effect sequences of the Defend and Heal skills (names from the ROM's skill list at 0x083BE4D4):
// action script opcodes 0x25/0x26 Recovery (30), 0x27/0x28 Repair (32), 0x29 Grap Trap / Shot Trap /
// Attack Clr / Team Form (10-12, 51), 0x2A Break Form (21), 0x2B Stability (22), 0x2C Force Bind (23),
// 0x2D Defence / Full Block / Half Block (27-29), 0x2E AutoRecover (31), 0x2F Reactivate (33).
// Each *_run clears unkB5 and calls entry [unkAA] of its *Steps table; it is one action script command
// (gActionScriptCommands -> script_op_*). Step 0 (*_begin) checks the time-out and whether the skill can work,
// the last step sets unkA6 (the result message) and unkB5. The skill id is part data[1].

#include "global.h"

void recovery_run(void) {
    gBattleWork.unkB5 = 0;
    gRecoverySteps[gBattleWork.unkAA]();
}

void recovery_begin(void) {
    u32 r;

    if (!part_broken_or_undamaged(gBattleWork.unk88, gBattleWork.unk8B)) {
        calc_battle_action_speed(gBattleWork.unk87, gBattleWork.unkA7);
        apply_battle_bot_damage_reduction(gBattleWork.unk87);
        r = decrement_battle_timer_and_check_zero();
        if (r) {
            gBattleWork.unkA6 = 0x1A;
            gBattleWork.unkAA = 2;
            gBattleWork.unkAB = 1;
        } else {
            calc_battle_stat_ratio(gBattleWork.unk87, gBattleWork.unkA7);
            side_add_action_point();
            gBattleWork.unkAA++;
            gBattleWork.unkAB = r;
        }
    } else {
        gBattleWork.unkA6 = 0x26;
        gBattleWork.unkAA = 2;
        gBattleWork.unkAB = 1;
    }
}

void recovery_heal_run(void) {
    gBattleWork.unkB5 = 0;
    gRecoveryHealSteps[gBattleWork.unkAA]();
}

void recovery_heal_apply(void) {
    clear_battle_sprite_slot(0, 0x80);
    gBattleWork.unkD0 = gBattleWork.unk8B;
    battle_calc_damage_split(gBattleWork.unk88, gBattleWork.unkD0, gBattleWork.unkEC);
    gBattleWork.unkAA++;
}

void recovery_heal_spread(void) {
    u32 part;
    struct BattleWork *s;

    if (gBattleBots[gBattleWork.unk87].parts[(s = &gBattleWork)->unkA7].data[7] && s->unkCA &&
        (part = find_most_damaged_part(s->unk88))) {
        part--;
        s->unkD0 = part;
        s->unk8B = part;
        battle_calc_damage_split(s->unk88, s->unkD0, s->unkCA);
        s->unkAA = 0xE;
    } else {
        s->unkAA++;
    }
}

void recovery_heal_repeat(void) {
    gBattleWork.unkAA = 2;
}

void repair_run(void) {
    gBattleWork.unkB5 = 0;
    gRepairSteps[gBattleWork.unkAA]();
}

void repair_begin(void) {
    u32 r;

    if (!gBattleBots[gBattleWork.unk88].parts[gBattleWork.unk8B].unk11) {
        calc_battle_action_speed(gBattleWork.unk87, gBattleWork.unkA7);
        apply_battle_bot_damage_reduction(gBattleWork.unk87);
        r = decrement_battle_timer_and_check_zero();
        if (r) {
            gBattleWork.unkA6 = 0x1A;
            gBattleWork.unkAA = 2;
            gBattleWork.unkAB = 1;
        } else {
            calc_battle_stat_ratio(gBattleWork.unk87, gBattleWork.unkA7);
            side_add_action_point();
            gBattleWork.unkAA++;
            gBattleWork.unkAB = r;
        }
    } else {
        gBattleWork.unkA6 = 0x27;
        gBattleWork.unkAA = 2;
        gBattleWork.unkAB = 1;
    }
}

void repair_apply_run(void) {
    gBattleWork.unkB5 = 0;
    gRepairApplySteps[gBattleWork.unkAA]();
}

void repair_apply(void) {
    clear_battle_sprite_slot(0, 0x80);
    gBattleWork.unkD0 = gBattleWork.unk8B;
    battle_set_damage_display(gBattleWork.unk88, gBattleWork.unkD0, gBattleWork.unkEC);
    gBattleWork.unkAA++;
}

void repair_spread(void) {
    u32 part;
    struct BattleWork *s = &gBattleWork;

    bot_restore_leg_stats(s->unk88);
    if (gBattleBots[s->unk87].parts[s->unkA7].data[7] && s->unkCA && (part = find_random_broken_part(s->unk88))) {
        part--;
        s->unkD0 = part;
        s->unk8B = part;
        battle_set_damage_display(s->unk88, s->unkD0, s->unkCA);
        s->unkAA = 0xF;
    } else {
        s->unkAA++;
    }
}

void repair_redraw_bot(void) {
    armor_heal_step(&gBattleWork.unkC8, gBattleWork.unk88, gBattleWork.unk8B);
    if (gBattleWork.unkF8 & 2) {
        get_active_bot_part_index_and_load_values(0);
        draw_medabot_sprite(0, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3],
                            (s16)gBattleWork.unk154, (s16)gBattleWork.unk156, gBattleWork.unk39[3] + 2, 4, 0, 2, 0,
                            gBattleWork.unk114[0]);
        draw_medabot_sprite(0, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3],
                            (s16)gBattleWork.unk154, (s16)gBattleWork.unk156, gBattleWork.unk39[3] + 2, 4, 0, 1, 0,
                            gBattleWork.unk114[0]);
    } else {
        get_active_bot_part_index_and_load_values(1);
        draw_medabot_sprite(1, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3],
                            (s16)gBattleWork.unk158, (s16)gBattleWork.unk15A, gBattleWork.unk39[3] + 2, 8, 1, 2, 1,
                            gBattleWork.unk114[1]);
        draw_medabot_sprite(1, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3],
                            (s16)gBattleWork.unk158, (s16)gBattleWork.unk15A, gBattleWork.unk39[3] + 2, 8, 1, 1, 1,
                            gBattleWork.unk114[1]);
    }
    gBattleWork.unkAA++;
}

void repair_repeat(void) {
    gBattleWork.unkAA = 2;
}

void trap_run(void) {
    gBattleWork.unkB5 = 0;
    gTrapSteps[gBattleWork.unkAA]();
}

void trap_begin(void) {
    u32 r;

    calc_battle_action_speed(gBattleWork.unk87, gBattleWork.unkA7);
    apply_battle_bot_damage_reduction(gBattleWork.unk87);
    r = decrement_battle_timer_and_check_zero();
    if (r) {
        gBattleWork.unkA6 = 0x1A;
        gBattleWork.unkAA++;
        return;
    }
    calc_battle_stat_ratio(gBattleWork.unk87, gBattleWork.unkA7);
    side_add_action_point();
    switch (gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1]) {
    case 0xA:
        gBattleWork.unk51 = r;
        break;
    case 0xB:
        gBattleWork.unk51 = 1;
        break;
    case 0xC:
        gBattleWork.unk51 = 2;
        break;
    default:
        gBattleWork.unk51 = 3;
        break;
    }
    gBattleWork.unk52 = gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1];
    gBattleWork.unkAA = 4;
}

// Steps 4-7 of most skill sequences (also the Interrupt skills): a sprite hops over the user, then a
// burst animation plays. guess: the "skill cast" effect.
void skill_cast_hop_spawn(void) {
    lz_decompress_dispatch(gUnk_084D50DC, (void *)0x06015800);
    CpuFastSet(gUnk_0850E658, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[0x5D + gBattleWork.unk87 * 4].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[0x5D + gBattleWork.unk87 * 4].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk6 = 0x4100;
    gSpriteEntries[0x21].unk23 = 0;
    gSpriteEntries[0x21].unk27 = 0;
    play_sound_effect(0x29);
    gBattleWork.unkAA++;
}

void skill_cast_hop(void) {
    sprite_hop_step(0x21);
    if (gSpriteEntries[0x21].unk27 == 0x20) {
        gSpriteEntries[0x21].unk0 &= ~0x200;
        gSpriteEntries[0x21].unk18 = 0;
        gBattleWork.unkAA++;
        return;
    }
    if (!(gBattleWork.unkF8 & 1))
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x20) & 0x3FF;
    else
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 - 0x20) & 0x3FF;
    if (!(gSpriteEntries[0x21].unk27 & 1)) {
        if (!(gBattleWork.unkF8 & 1))
            gSpriteEntries[0x21].unk2++;
        else
            gSpriteEntries[0x21].unk2--;
    }
    gSpriteEntries[0x21].unk27++;
}

void skill_cast_flash_init(void) {
    lz_decompress_dispatch(gUnk_084CCE48, (void *)0x06014800);
    CpuFastSet(gUnk_0850E358, (void *)0x050002E0, 8);
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x23], 0x21);
    gBattleWork.unkAA++;
}

void skill_cast_flash_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x23], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF)
        gBattleWork.unkAA++;
}

void trap_sprite_spawn(void) {
    switch (gBattleWork.unk51) {
    case 0:
        lz_decompress_dispatch(gUnk_084C907C, (void *)0x06014800);
        CpuFastSet(gUnk_0850E058, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk4 = 0x3C;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x19], 0x21);
        break;
    case 1:
        lz_decompress_dispatch(gUnk_084C9288, (void *)0x06014800);
        CpuFastSet(gUnk_0850E078, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk4 = 0x3C;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1A], 0x21);
        break;
    case 2:
        lz_decompress_dispatch(gUnk_084C9624, (void *)0x06014800);
        CpuFastSet(gUnk_0850E098, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk4 = 0x3C;
        gSpriteEntries[0x21].unk6 = 0xD00;
        break;
    case 3:
        lz_decompress_dispatch(gUnk_084D513C, (void *)0x06014800);
        CpuFastSet(gUnk_0850E678, (void *)0x050002E0, 8);
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x38], 0x21);
        break;
    }
    gSpriteEntries[0x21].unk0 |= 0x220;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk8 = 8;
    if (gBattleWork.unkF8 & 1) {
        gSpriteEntries[0x21].unk0 |= 0x1000;
        gSpriteEntries[0x21].unk2--;
    }
    gBattleWork.unkAA++;
}

void trap_sprite_grow(void) {
    if ((gSpriteEntries[0x21].unk8 += 8) == 0x40) {
        if (gBattleWork.unk51 == 3)
            gGameWork.unk86 = 1;
        else
            gGameWork.unk86 = 0x3C;
        gBattleWork.unkAA++;
    }
}

void trap_sprite_hold(void) {
    gGameWork.unk86--;
    if (gGameWork.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gGameWork.unk86 = 0;
    if (gGameWork.unk86 == 0) {
        switch (gBattleWork.unk51) {
        case 0:
        case 1:
        case 2:
            gSpriteEntries[0x21].unk27 = 0;
            gBattleWork.unkAA++;
            break;
        case 3:
            play_sound_effect(0x52);
            gBattleWork.unkAA = 0x20;
            break;
        }
    }
}

void trap_sprite_slide(void) {
    if (gSpriteEntries[0x21].unk27 == 0x10) {
        gBattleWork.unkAA++;
        return;
    }
    if (!(gBattleWork.unkF8 & 1))
        gSpriteEntries[0x21].unk2++;
    else
        gSpriteEntries[0x21].unk2--;
    gSpriteEntries[0x21].unk27++;
}

// The side already holds this trap: pulse the sprite and add to it; Attack Clr skips the pulse.
void trap_check_existing(void) {
    if (gBattleWork.unk28[gBattleWork.unk8A].active &&
        gBattleWork.unk28[gBattleWork.unk8A].skill == gBattleWork.unk52) {
        gSpriteEntries[0x21].unk27 = 0;
        gBattleWork.unkAA++;
    } else if (gBattleWork.unk51 == 2) {
        gBattleWork.unkAA = 0x14;
    } else {
        play_sound_effect(0x3E);
        gBattleWork.unkAA = 0xE;
    }
}

void trap_sprite_pulse(void) {
    if (gSpriteEntries[0x21].unk27 == 0x10) {
        if (gBattleWork.unk51 == 2) {
            gBattleWork.unkAA = 0x14;
        } else {
            play_sound_effect(0x3E);
            gBattleWork.unkAA = 0xE;
        }
        return;
    }
    if (gSpriteEntries[0x21].unk27 < 8)
        gSpriteEntries[0x21].unk8 += 8;
    else
        gSpriteEntries[0x21].unk8 -= 8;
    gSpriteEntries[0x21].unk27++;
}

void trap_sprite_shrink(void) {
    if (gSpriteEntries[0x21].unk8 == 8) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 8;
    }
}

// unk28[side]: the side's trap / Team Form record (active, skill kind, power); a repeat stacks half.
void trap_apply(void) {
    if (gBattleWork.unk28[gBattleWork.unk8A].active &&
        gBattleWork.unk28[gBattleWork.unk8A].skill == gBattleWork.unk52) {
        gBattleWork.unk53 = 1;
        if (gBattleWork.unk51 != 2) {
            add_u8_capped(&gBattleWork.unk28[gBattleWork.unk8A].durability, gBattleWork.unkE8 >> 1, 0xFF);
            add_u8_capped(&gBattleWork.unk28[gBattleWork.unk8A].power,
                          (gBattleWork.unkEC + gBattleBots[gBattleWork.unk87].trapBonus) >> 1, 0xFF);
            gBattleWork.unkAA++;
        } else {
            gBattleWork.unk28[gBattleWork.unk8A].durability++;
            gBattleWork.unkAA++;
        }
    } else {
        gBattleWork.unk53 = 0;
        gBattleWork.unk28[gBattleWork.unk8A].active = 1;
        gBattleWork.unk28[gBattleWork.unk8A].skill = gBattleWork.unk52;
        gBattleWork.unk28[gBattleWork.unk8A].durability = 0;
        gBattleWork.unk28[gBattleWork.unk8A].power = 0;
        if (gBattleWork.unk51 != 2) {
            add_u8_capped(&gBattleWork.unk28[gBattleWork.unk8A].durability, gBattleWork.unkE8, 0xFF);
            add_u8_capped(&gBattleWork.unk28[gBattleWork.unk8A].power,
                          gBattleWork.unkEC + gBattleBots[gBattleWork.unk87].trapBonus, 0xFF);
        } else {
            gBattleWork.unk28[gBattleWork.unk8A].durability++;
        }
        gBattleWork.unkAA++;
    }
}

void trap_finish(void) {
    switch (gBattleWork.unk51) {
    case 0:
        gBattleWork.unkA6 = 0x1E;
        break;
    case 1:
        gBattleWork.unkA6 = 0x1F;
        break;
    case 2:
        gBattleWork.unkA6 = 0x20;
        break;
    case 3:
        gBattleWork.unkA6 = 0x21;
        break;
    }
    if (gBattleWork.unk53)
        gBattleWork.unkA6 = 0x71;
    gBattleWork.unkAA++;
}

void trap_sprite_fly_init(void) {
    gSpriteEntries[0x21].unk24 = 4;
    gSpriteEntries[0x21].unk25 = 0;
    gSpriteEntries[0x21].unk30 = 0;
    play_sound_effect(0x40);
    gBattleWork.unkAA++;
}

void trap_sprite_fly(void) {
    if (update_sprite_deceleration(0x21, -0x40, -0x30)) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.unkAA++;
    }
}

void team_form_anim_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x38], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        gGameWork.unk86 = 0x3C;
        gBattleWork.unkAA++;
    }
}

void team_form_split(void) {
    struct SpriteEntry *spr;

    gGameWork.unk86--;
    if (gGameWork.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gGameWork.unk86 = 0;
    if (gGameWork.unk86 == 0) {
        spr = &gSpriteEntries[0x21];
        memcpy_bytes_0803F63C(spr, spr + 1, 0x40);
        memcpy_bytes_0803F63C(spr, spr + 2, 0x40);
        spr[0].unk32 = 0x58;
        spr[0].unk24 = 6;
        spr[1].unk32 = 0x40;
        spr[1].unk24 = 6;
        spr[2].unk32 = 0x28;
        spr[2].unk24 = 6;
        if (!(gBattleWork.unkF8 & 1))
            spr[2].unk30 = spr[1].unk30 = spr[0].unk30 = 0x88;
        else
            spr[2].unk30 = spr[1].unk30 = spr[0].unk30 = 0x68;
        gBattleWork.unkAA++;
    }
}

void team_form_move(void) {
    u32 r = move_sprite_toward_target(0x21);
    u32 n = (r | -r) >> 31;
    if (move_sprite_toward_target(0x22))
        n++;
    if (move_sprite_toward_target(0x23))
        n++;
    if (n == 3)
        gBattleWork.unkAA++;
}

void team_form_check_existing(void) {
    if (gBattleWork.unk28[gBattleWork.unk8A].active &&
        gBattleWork.unk28[gBattleWork.unk8A].skill == gBattleWork.unk52) {
        gSpriteEntries[0x21].unk27 = 0;
        gBattleWork.unkAA++;
    } else {
        play_sound_effect(0x3E);
        gBattleWork.unkAA = 0x25;
    }
}

void team_form_pulse(void) {
    if (gSpriteEntries[0x21].unk27 == 0x10) {
        play_sound_effect(0x3E);
        gBattleWork.unkAA++;
        return;
    }
    if (gSpriteEntries[0x21].unk27 < 8) {
        gSpriteEntries[0x21].unk8 += 8;
        gSpriteEntries[0x22].unk8 += 8;
        gSpriteEntries[0x23].unk8 += 8;
    } else {
        gSpriteEntries[0x21].unk8 -= 8;
        gSpriteEntries[0x22].unk8 -= 8;
        gSpriteEntries[0x23].unk8 -= 8;
    }
    gSpriteEntries[0x21].unk27++;
}

void team_form_shrink(void) {
    if (gSpriteEntries[0x21].unk8 == 8) {
        clear_battle_sprite_slot(0x21, 3);
        gBattleWork.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 8;
        gSpriteEntries[0x22].unk8 -= 8;
        gSpriteEntries[0x23].unk8 -= 8;
    }
}

void break_form_run(void) {
    gBattleWork.unkB5 = 0;
    gBreakFormSteps[gBattleWork.unkAA]();
}

void break_form_begin(void) {
    calc_battle_action_speed(gBattleWork.unk87, gBattleWork.unkA7);
    apply_battle_bot_damage_reduction(gBattleWork.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.unkA6 = 0x1A;
        gBattleWork.unkAA++;
    } else if (!gBattleWork.unk28[gBattleWork.unk89].active) {
        gBattleWork.unkA6 = 0x24;
        gBattleWork.unkAA++;
    } else {
        side_add_action_point();
        gBattleWork.unkAA = 4;
    }
}

void break_form_sprite_spawn(void) {
    lz_decompress_dispatch(gUnk_084D54BC, (void *)0x06014800);
    CpuFastSet(gUnk_0850E698, (void *)0x050002E0, 8);
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x39], 0x21);
    if (gBattleWork.unkF8 & 1)
        gSpriteEntries[0x21].unk0 |= 0x1000;
    gBattleWork.unkAA++;
}

void break_form_anim_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x39], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3B], 0x21);
        gGameWork.unk86 = 0x3C;
        gBattleWork.unkAA++;
    }
}

void break_form_hold(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x3B], 0x21);
    gGameWork.unk86--;
    if (gGameWork.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gGameWork.unk86 = 0;
    if (gGameWork.unk86 == 0)
        gBattleWork.unkAA++;
}

void break_form_split(void) {
    struct SpriteEntry *spr;

    process_sprite_anim_commands(gUnk_083B5F80[0x3B], 0x21);
    spr = &gSpriteEntries[0x21];
    memcpy_bytes_0803F63C(spr, spr + 1, 0x40);
    memcpy_bytes_0803F63C(spr, spr + 2, 0x40);
    spr[0].unk32 = 0x58;
    spr[0].unk24 = 6;
    spr[1].unk32 = 0x40;
    spr[1].unk24 = 6;
    spr[2].unk32 = 0x28;
    spr[2].unk24 = 6;
    if (gBattleWork.unkF8 & 1)
        spr[2].unk30 = spr[1].unk30 = spr[0].unk30 = 0x88;
    else
        spr[2].unk30 = spr[1].unk30 = spr[0].unk30 = 0x68;
    gBattleWork.unkAA++;
}

void break_form_move(void) {
    u32 r, n;

    process_sprite_anim_commands(gUnk_083B5F80[0x3B], 0x21);
    process_sprite_anim_commands(gUnk_083B5F80[0x3B], 0x22);
    process_sprite_anim_commands(gUnk_083B5F80[0x3B], 0x23);
    r = move_sprite_toward_target(0x21);
    n = (r | -r) >> 31;
    if (move_sprite_toward_target(0x22))
        n++;
    if (move_sprite_toward_target(0x23))
        n++;
    if (n == 3) {
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3A], 0x21);
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3A], 0x22);
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3A], 0x23);
        gBattleWork.unkAA++;
    }
}

void break_form_hit_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x3A], 0x21);
    process_sprite_anim_commands(gUnk_083B5F80[0x3A], 0x22);
    process_sprite_anim_commands(gUnk_083B5F80[0x3A], 0x23);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_sprite_table_mask(0x21, 3);
        gGameWork.unk86 = 0x3C;
        gBattleWork.unkAA++;
    }
}

void break_form_shatter_init(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084CCE48, (void *)0x06014800);
    CpuFastSet(gUnk_0850E358, (void *)0x050002E0, 8);
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x23], 0x21);
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x23], 0x22);
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x23], 0x23);
    set_sprite_hidden_flags(0x21, 3);
    for (i = 0; i < 6; i++) {
        if (gBattleBots[i].teamState) {
            gSpriteEntries[0x5A + i * 4].unk23 = 0;
            gSpriteEntries[0x5B + i * 4].unk23 = 0;
            gSpriteEntries[0x5C + i * 4].unk23 = 0;
            gSpriteEntries[0x5D + i * 4].unk23 = 0;
        }
    }
    gGameWork.unk86 = 0;
    gBattleWork.unkAA++;
}

void break_form_shatter(void) {
    u32 i;

    gGameWork.unk86++;
    bg3_shake_step(gGameWork.unk86);
    for (i = 0; i < 6; i++) {
        if (gBattleBots[i].teamState) {
            advance_sprite_anim_frame(0x5A + i * 4, 0);
            advance_sprite_anim_frame(0x5B + i * 4, 0);
            advance_sprite_anim_frame(0x5C + i * 4, 0);
            advance_sprite_anim_frame(0x5D + i * 4, 0);
        }
    }
    process_sprite_anim_commands(gUnk_083B5F80[0x23], 0x21);
    process_sprite_anim_commands(gUnk_083B5F80[0x23], 0x22);
    process_sprite_anim_commands(gUnk_083B5F80[0x23], 0x23);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        for (i = 0; i < 6; i++) {
            if (gBattleBots[i].teamState) {
                gSpriteEntries[0x5A + i * 4].unk23 = 0;
                gSpriteEntries[0x5B + i * 4].unk23 = 0;
                gSpriteEntries[0x5C + i * 4].unk23 = 0;
                gSpriteEntries[0x5D + i * 4].unk23 = 0;
            }
        }
        gBg3Scroll.y = 0;
        clear_battle_sprite_slot(0x21, 3);
        gBattleWork.unkAA++;
    }
}

void break_form_apply(void) {
    gBattleWork.unk28[gBattleWork.unk89].active = 0;
    gBattleWork.unk28[gBattleWork.unk89].skill = 0;
    gBattleWork.unk28[gBattleWork.unk89].durability = 0;
    gBattleWork.unk28[gBattleWork.unk89].power = 0;
    gBattleWork.unkAA++;
}

void break_form_finish(void) {
    gBattleWork.unkA6 = 0x25;
    gBattleWork.unkAA++;
}

void stability_run(void) {
    gBattleWork.unkB5 = 0;
    gStabilitySteps[gBattleWork.unkAA]();
}

void stability_begin(void) {
    calc_battle_action_speed(gBattleWork.unk87, gBattleWork.unkA7);
    apply_battle_bot_damage_reduction(gBattleWork.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.unkA6 = 0x1A;
        gBattleWork.unkAA++;
    } else if (!gBattleBots[gBattleWork.unk88].statusType) {
        gBattleWork.unkA6 = 0x70;
        gBattleWork.unkAA++;
    } else {
        side_add_action_point();
        gBattleWork.unkAA = 4;
    }
}

void stability_sprite_spawn(void) {
    lz_decompress_dispatch(gUnk_084D55D0, (void *)0x06014800);
    CpuFastSet(gUnk_0850E6B8, (void *)0x050002E0, 8);
    if (gBattleWork.unkF8 & 1)
        gSpriteEntries[0x21].unk0 |= 0x1000;
    gSpriteEntries[0x21].unk0 |= 0x200;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3C], 0x21);
    gGameWork.unk86 = 0x3C;
    gBattleWork.unkAA++;
}

void stability_sprite_fly(void) {
    if (!(gBattleWork.unkF8 & 1))
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 - 0x40) & 0x3FF;
    else
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x40) & 0x3FF;
    if (move_sprite_toward_target(0x21)) {
        gSpriteEntries[0x21].unk0 &= ~0x200;
        gSpriteEntries[0x21].unk18 = 0;
        gBattleWork.unkAA++;
    }
}

// Stability cures the target's negative status (unkC9-unkCC, set by Impair, Confusion...).
void stability_apply(void) {
    gBattleBots[gBattleWork.unk88].statusType = 0;
    gBattleBots[gBattleWork.unk88].statusPart = 0;
    gBattleBots[gBattleWork.unk88].statusTimer = 0;
    gBattleBots[gBattleWork.unk88].statusAmount = 0;
    gSpriteEntries[gBattleWork.unk88 * 3 + 0x47].unk0 |= 0x8220;
    gSpriteEntries[gBattleWork.unk88 * 3 + 0x47].unk9 = 0x40;
    gSpriteEntries[gBattleWork.unk88 * 3 + 0x47].unk8 = 0x40;
    play_sound_effect(0x37);
    gBattleWork.unkAA++;
}

void stability_status_icon_fade(void) {
    if (gSpriteEntries[gBattleWork.unk88 * 3 + 0x47].unk8 != 4) {
        gSpriteEntries[gBattleWork.unk88 * 3 + 0x47].unk0 |= 0x8000;
        gSpriteEntries[gBattleWork.unk88 * 3 + 0x47].unk9 += 4;
        gSpriteEntries[gBattleWork.unk88 * 3 + 0x47].unk8 -= 4;
    }
    process_sprite_anim_commands(gUnk_083B5F80[0x3C], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        clear_battle_sprite_slot(gBattleWork.unk88 * 3 + 0x47, 1);
        gBattleWork.unkAA++;
    }
}

void stability_finish(void) {
    gBattleWork.unkA6 = 0x23;
    gBattleWork.unkAA++;
}

void force_bind_run(void) {
    gBattleWork.unkB5 = 0;
    gForceBindSteps[gBattleWork.unkAA]();
}

void force_bind_begin(void) {
    calc_battle_action_speed(gBattleWork.unk87, gBattleWork.unkA7);
    apply_battle_bot_damage_reduction(gBattleWork.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.unkA6 = 0x1A;
        gBattleWork.unkAA++;
    } else {
        side_add_action_point();
        gBattleWork.unkAA = 4;
    }
}

void force_bind_orbs_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084D5788, (void *)0x06014800);
    CpuFastSet(gUnk_0850E6D8, (void *)0x050002E0, 8);
    for (i = 0; i < 4; i++) {
        gSpriteEntries[0x21 + i].unk0 = 0xC604;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[gBattleWork.unk87 * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk4 = gSpriteEntries[gBattleWork.unk87 * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        gSpriteEntries[0x21 + i].unk8 = 0x40;
        gSpriteEntries[0x21 + i].unk9 = 0x40;
        gSpriteEntries[0x21 + i].unk2B = 0;
        gSpriteEntries[0x21 + i].unk2C = i << 6;
        gSpriteEntries[0x21 + i].unk2D = 0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3D], 0x21 + i);
    }
    play_sound_effect(0x5C);
    gBattleWork.unkAA++;
}

void force_bind_orbs_spin(void) {
    u32 i;
    struct Coords16 v;

    for (i = 0; i < 4; i++) {
        process_sprite_anim_commands(gUnk_083B5F80[0x3D], 0x21 + i);
        v = calc_polar_to_screen_coords(gSpriteEntries[0x21 + i].unk2C, gSpriteEntries[0x21 + i].unk2B,
                                        gSpriteEntries[gBattleWork.unk87 * 4 + 0x5D].unk2,
                                        gSpriteEntries[gBattleWork.unk87 * 4 + 0x5D].unk4 - 4);
        gSpriteEntries[0x21 + i].unk2 = v.x;
        gSpriteEntries[0x21 + i].unk4 = v.y;
        gSpriteEntries[0x21 + i].unk2C += 4;
        gSpriteEntries[0x21 + i].unk2D++;
        if (!(gSpriteEntries[0x21 + i].unk2D & 3))
            gSpriteEntries[0x21 + i].unk2B++;
        if (gSpriteEntries[0x21 + i].unk2D > 0xB4) {
            gSpriteEntries[0x21 + i].unk8 -= 4;
            gSpriteEntries[0x21 + i].unk9 -= 4;
        }
    }
    if (gSpriteEntries[0x21].unk9 == 4) {
        clear_battle_sprite_slot(0x21, 4);
        gBattleWork.unkAA++;
    }
}

// Each use toggles Force Bind on (message 0x72) or off (0x73).
void force_bind_toggle(void) {
    if (!gBattleWork.unk58) {
        gBattleWork.unkA6 = 0x72;
        gBattleWork.unk58 = 1;
    } else {
        gBattleWork.unkA6 = 0x73;
        gBattleWork.unk58 = 0;
    }
    gBattleWork.unkAA++;
}

void defence_run(void) {
    gBattleWork.unkB5 = 0;
    gDefenceSteps[gBattleWork.unkAA]();
}

void defence_begin(void) {
    u32 r;

    calc_battle_action_speed(gBattleWork.unk87, gBattleWork.unkA7);
    apply_battle_bot_damage_reduction(gBattleWork.unk87);
    r = decrement_battle_timer_and_check_zero();
    if (r) {
        gBattleWork.unkA6 = 0x1A;
        gBattleWork.unkAA++;
    } else {
        side_add_action_point();
        switch (gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1]) {
        case 0x1B:
            gBattleWork.unk51 = r;
            break;
        case 0x1C:
            gBattleWork.unk51 = 1;
            break;
        default:
            gBattleWork.unk51 = 2;
            break;
        }
        calc_battle_stat_ratio(gBattleWork.unk87, gBattleWork.unkA7);
        gBattleWork.unkAA = 4;
    }
}

void defence_shields_spawn(void) {
    switch (gBattleWork.unk51) {
    case 0:
        lz_decompress_dispatch(gUnk_084C9880, (void *)0x06014800);
        CpuFastSet(gUnk_0850E0F8, (void *)0x050002E0, 8);
        break;
    case 1:
        lz_decompress_dispatch(gUnk_084C9B88, (void *)0x06014800);
        CpuFastSet(gUnk_0850E118, (void *)0x050002E0, 8);
        break;
    default:
        lz_decompress_dispatch(gUnk_084C9E9C, (void *)0x06014800);
        CpuFastSet(gUnk_0850E138, (void *)0x050002E0, 8);
        break;
    }
    gSpriteEntries[0x21].unk0 = 0xC624;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gBattleWork.unk87 * 4 + 0x5D].unk2 - 0x20;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gBattleWork.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk8 = 0x80;
    gSpriteEntries[0x21].unk9 = 0x80;
    gSpriteEntries[0x21].unk2B = 0x1C;
    gSpriteEntries[0x21].unk2C = 0;
    gSpriteEntries[0x21].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1C], 0x21);
    gSpriteEntries[0x22].unk0 = 0xC624;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = gSpriteEntries[gBattleWork.unk87 * 4 + 0x5D].unk2 + 0x20;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[gBattleWork.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = 0xF0;
    gSpriteEntries[0x22].unk8 = 0x80;
    gSpriteEntries[0x22].unk9 = 0x80;
    gSpriteEntries[0x22].unk2B = 0x1C;
    gSpriteEntries[0x22].unk2C = 0x80;
    gSpriteEntries[0x22].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1C], 0x22);
    play_sound_effect(0x33);
    gBattleWork.unkAA++;
}

void defence_shields_spin(void) {
    u32 i;
    struct Coords16 v;

    for (i = 0; i < 2; i++) {
        v = calc_polar_to_screen_coords(gSpriteEntries[0x21 + i].unk2C, gSpriteEntries[0x21 + i].unk2B,
                                        gSpriteEntries[gBattleWork.unk87 * 4 + 0x5D].unk2,
                                        gSpriteEntries[gBattleWork.unk87 * 4 + 0x5D].unk4 - 4);
        gSpriteEntries[0x21 + i].unk2 = v.x;
        gSpriteEntries[0x21 + i].unk4 = v.y;
        gSpriteEntries[0x21 + i].unk2C += 8;
        gSpriteEntries[0x21 + i].unk2D++;
        if (!(gSpriteEntries[0x21 + i].unk2D & 3))
            gSpriteEntries[0x21 + i].unk2B--;
        if (gSpriteEntries[0x21 + i].unk8 != 0x40) {
            gSpriteEntries[0x21 + i].unk8--;
            gSpriteEntries[0x21 + i].unk9--;
        }
    }
    if (gSpriteEntries[0x21].unk2B == 0) {
        play_sound_effect(0x30);
        clear_battle_sprite_slot(0x22, 1);
        gBattleWork.unkAA++;
    }
}

void defence_shield_anim_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x1C], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.unkAA++;
    }
}

// Marks the user as guarding (unkBD bit 3) with this skill (Defence, Full Block or Half Block).
void defence_apply(void) {
    gBattleBots[gBattleWork.unk87].stateFlags |= 8;
    gBattleBots[gBattleWork.unk87].lastActionSkill = gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1];
    gBattleBots[gBattleWork.unk87].defence = 0;
    add_u8_capped(&gBattleBots[gBattleWork.unk87].moveSubpixel + 1, gBattleWork.unkEC, 0xFF);
    gBattleWork.unkAA++;
}

void defence_finish(void) {
    gBattleWork.unkA6 = 0x1B;
    gBattleWork.unkAA++;
}

void autorecover_run(void) {
    gBattleWork.unkB5 = 0;
    gAutoRecoverSteps[gBattleWork.unkAA]();
}

void autorecover_begin(void) {
    calc_battle_action_speed(gBattleWork.unk87, gBattleWork.unkA7);
    apply_battle_bot_damage_reduction(gBattleWork.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.unkA6 = 0x1A;
        gBattleWork.unkAA++;
    } else if (!battle_bot_lacks_stability(gBattleWork.unk88)) {
        gBattleWork.unkA6 = 0x39;
        gBattleWork.unkAA++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.unk87, gBattleWork.unkA7);
        gBattleWork.unkAA = 4;
    }
}

void autorecover_orb_spawn(void) {
    lz_decompress_dispatch(gUnk_084D5860, (void *)0x06014800);
    CpuFastSet(gUnk_0850E6F8, (void *)0x050002C0, 0x10);
    gSpriteEntries[0x21].unk0 |= 0x200;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3E], 0x21);
    gGameWork.unk86 = 0x3C;
    gBattleWork.unkAA++;
}

void heal_orb_hold(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x3E], 0x21);
    if (gGameWork.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gBattleWork.unkAA++;
    else if (gGameWork.unk86)
        gGameWork.unk86--;
    else
        gBattleWork.unkAA++;
}

void heal_orb_fly(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x3E], 0x21);
    if (move_sprite_toward_target(0x21))
        gBattleWork.unkAA++;
}

void heal_orb_shrink(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x3E], 0x21);
    if (gSpriteEntries[0x21].unk8 == 8) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.unkAA++;
    } else
        gSpriteEntries[0x21].unk8 -= 8;
}

void autorecover_ring_spawn(void) {
    u32 i;
    struct Coords16 v;

    gSpriteEntries[0x25].unk0 = 0xC604;
    gSpriteEntries[0x25].unk1C = 0;
    gSpriteEntries[0x25].unk2 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[0x25].unk4 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x25].unkA = 7;
    gSpriteEntries[0x25].unk8 = 0x40;
    gSpriteEntries[0x25].unk9 = 0x40;
    gSpriteEntries[0x25].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3F], 0x25);
    for (i = 0; i < 4; i++) {
        gSpriteEntries[0x21 + i].unk0 = 0xC604;
        v = calc_polar_to_screen_coords(i << 6, 0x10, gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk2,
                                        gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk4 - 4);
        gSpriteEntries[0x21 + i].unk2 = v.x;
        gSpriteEntries[0x21 + i].unk4 = v.y;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        gSpriteEntries[0x21 + i].unk6 = 0x4604;
        gSpriteEntries[0x21 + i].unk8 = 0x40;
        gSpriteEntries[0x21 + i].unk9 = 0x40;
        gSpriteEntries[0x21 + i].unk2B = 0x10;
        gSpriteEntries[0x21 + i].unk2C = i << 6;
        gSpriteEntries[0x21 + i].unk2D = 0;
    }
    play_sound_effect(0x4A);
    gBattleWork.unkAA++;
}

void heal_ring_spin(void) {
    u32 i;
    struct Coords16 v;
    u32 n;

    process_sprite_anim_commands(gUnk_083B5F80[0x3F], 0x25);
    for (i = 0; i < 5; i++) {
        if (i < 4) {
            v = calc_polar_to_screen_coords(gSpriteEntries[0x21 + i].unk2C, gSpriteEntries[0x21 + i].unk2B,
                                            gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk2,
                                            gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk4 - 4);
            gSpriteEntries[0x21 + i].unk2 = v.x;
            gSpriteEntries[0x21 + i].unk4 = v.y;
            gSpriteEntries[0x21 + i].unk2C += 4;
        }
        n = gSpriteEntries[0x21 + i].unk2D + 1;
        gSpriteEntries[0x21 + i].unk2D = n;
        if (gSpriteEntries[0x21 + i].unk2D > 0x5A) {
            if (n & 1)
                gSpriteEntries[0x21 + i].unk2B++;
            gSpriteEntries[0x21 + i].unk8 -= 2;
            gSpriteEntries[0x21 + i].unk9 -= 2;
        }
    }
    if (gSpriteEntries[0x21].unk9 == 4) {
        clear_battle_sprite_slot(0x21, 5);
        gBattleWork.unkAA++;
    }
}

// Gives the target the AutoRecover status (unkC4 = skill 31) with this action's power.
void autorecover_apply(void) {
    gBattleBots[gBattleWork.unk88].buffType = 0x1F;
    gBattleBots[gBattleWork.unk88].buffPart = 0;
    gBattleBots[gBattleWork.unk88].buffTimer = clamp_1_99(gBattleWork.unkE8);
    gBattleBots[gBattleWork.unk88].buffAmount = clamp_1_99(gBattleWork.unkEC);
    gBattleWork.unkAA++;
}

void autorecover_finish(void) {
    gBattleWork.unkA6 = 0x29;
    gBattleWork.unkAA++;
}

void reactivate_run(void) {
    gBattleWork.unkB5 = 0;
    gReactivateSteps[gBattleWork.unkAA]();
}

void reactivate_begin(void) {
    calc_battle_action_speed(gBattleWork.unk87, gBattleWork.unkA7);
    apply_battle_bot_damage_reduction(gBattleWork.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.unkA6 = 0x1A;
        gBattleWork.unkAA++;
    } else if (gBattleBots[gBattleWork.unk88].parts[0].unk11) {
        gBattleWork.unkA6 = 9;
        gBattleWork.unkAA++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.unk87, gBattleWork.unkA7);
        gBattleWork.unkAA = 4;
    }
}

void reactivate_orb_spawn(void) {
    lz_decompress_dispatch(gUnk_084D5B08, (void *)0x06014800);
    CpuFastSet(gUnk_0850E738, (void *)0x050002C0, 0x10);
    gSpriteEntries[0x21].unk0 |= 0x200;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3E], 0x21);
    gGameWork.unk86 = 0x3C;
    gBattleWork.unkAA++;
}

void reactivate_ring_spawn(void) {
    u32 i;
    struct Coords16 v;

    gSpriteEntries[0x25].unk0 = 0xC604;
    gSpriteEntries[0x25].unk1C = 0;
    gSpriteEntries[0x25].unk2 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[0x25].unk4 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x25].unkA = 7;
    gSpriteEntries[0x25].unk8 = 0x40;
    gSpriteEntries[0x25].unk9 = 0x40;
    gSpriteEntries[0x25].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3F], 0x25);
    for (i = 0; i < 4; i++) {
        gSpriteEntries[0x21 + i].unk0 = 0xC604;
        v = calc_polar_to_screen_coords(i << 6, 0x10, gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk2,
                                        gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk4 - 4);
        gSpriteEntries[0x21 + i].unk2 = v.x;
        gSpriteEntries[0x21 + i].unk4 = v.y;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        gSpriteEntries[0x21 + i].unk6 = 0x4604;
        gSpriteEntries[0x21 + i].unk8 = 0x40;
        gSpriteEntries[0x21 + i].unk9 = 0x40;
        gSpriteEntries[0x21 + i].unk2B = 0x10;
        gSpriteEntries[0x21 + i].unk2C = i << 6;
        gSpriteEntries[0x21 + i].unk2D = 0;
    }
    play_sound_effect(0x4B);
    gBattleWork.unkAA++;
}

// Revives a target whose head is broken: refills the head and redraws its parts.
void reactivate_apply(void) {
    gBattleBots[gBattleWork.unk88].teamState = 3;
    battle_calc_damage_split(gBattleWork.unk88, 0, gBattleWork.unkEC);
    gBattleBots[gBattleWork.unk88].parts[0].unk11 = gBattleWork.unkC8;
    gBattleBots[gBattleWork.unk88].present = 1;
    load_all_bot_part_sprites();
    iterate_bots_setup_battle_sprites();
    gBattleWork.unkAA++;
}

void reactivate_finish(void) {
    memcpy_bytes_0803F63C(gBattleBots[gBattleWork.unk88].medal.name, gGameWork.unk9E, 0xE);
    gBattleWork.unkA6 = 0x28;
    gBattleWork.unkAA++;
}
