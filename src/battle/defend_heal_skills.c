// Effect sequences of the Defend and Heal skills (names from the ROM's skill list at 0x083BE4D4):
// action script opcodes 0x25/0x26 Recovery (30), 0x27/0x28 Repair (32), 0x29 Grap Trap / Shot Trap /
// Attack Clr / Team Form (10-12, 51), 0x2A Break Form (21), 0x2B Stability (22), 0x2C Force Bind (23),
// 0x2D Defence / Full Block / Half Block (27-29), 0x2E AutoRecover (31), 0x2F Reactivate (33).
// Each *_run clears unkB5 and calls entry [unkAA] of its *Steps table; it is one action script command
// (gUnk_083AF000 -> script_op_*). Step 0 (*_begin) checks the time-out and whether the skill can work,
// the last step sets unkA6 (the result message) and unkB5. The skill id is part data[1].

#include "global.h"

void recovery_run(void) {
    gUnk_03001800.unkB5 = 0;
    gRecoverySteps[gUnk_03001800.unkAA]();
}

void recovery_begin(void) {
    u32 r;

    if (!part_broken_or_undamaged(gUnk_03001800.unk88, gUnk_03001800.unk8B)) {
        calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
        r = decrement_battle_timer_and_check_zero();
        if (r) {
            gUnk_03001800.unkA6 = 0x1A;
            gUnk_03001800.unkAA = 2;
            gUnk_03001800.unkAB = 1;
        } else {
            calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
            side_add_action_point();
            gUnk_03001800.unkAA++;
            gUnk_03001800.unkAB = r;
        }
    } else {
        gUnk_03001800.unkA6 = 0x26;
        gUnk_03001800.unkAA = 2;
        gUnk_03001800.unkAB = 1;
    }
}

void recovery_heal_run(void) {
    gUnk_03001800.unkB5 = 0;
    gRecoveryHealSteps[gUnk_03001800.unkAA]();
}

void recovery_heal_apply(void) {
    clear_battle_sprite_slot(0, 0x80);
    gUnk_03001800.unkD0 = gUnk_03001800.unk8B;
    battle_calc_damage_split(gUnk_03001800.unk88, gUnk_03001800.unkD0, gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void recovery_heal_spread(void) {
    u32 part;
    struct Unk_03001800 *s;

    if (gUnk_03000590[gUnk_03001800.unk87].parts[(s = &gUnk_03001800)->unkA7].data[7] && s->unkCA &&
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
    gUnk_03001800.unkAA = 2;
}

void repair_run(void) {
    gUnk_03001800.unkB5 = 0;
    gRepairSteps[gUnk_03001800.unkAA]();
}

void repair_begin(void) {
    u32 r;

    if (!gUnk_03000590[gUnk_03001800.unk88].parts[gUnk_03001800.unk8B].unk11) {
        calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
        r = decrement_battle_timer_and_check_zero();
        if (r) {
            gUnk_03001800.unkA6 = 0x1A;
            gUnk_03001800.unkAA = 2;
            gUnk_03001800.unkAB = 1;
        } else {
            calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
            side_add_action_point();
            gUnk_03001800.unkAA++;
            gUnk_03001800.unkAB = r;
        }
    } else {
        gUnk_03001800.unkA6 = 0x27;
        gUnk_03001800.unkAA = 2;
        gUnk_03001800.unkAB = 1;
    }
}

void repair_apply_run(void) {
    gUnk_03001800.unkB5 = 0;
    gRepairApplySteps[gUnk_03001800.unkAA]();
}

void repair_apply(void) {
    clear_battle_sprite_slot(0, 0x80);
    gUnk_03001800.unkD0 = gUnk_03001800.unk8B;
    battle_set_damage_display(gUnk_03001800.unk88, gUnk_03001800.unkD0, gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void repair_spread(void) {
    u32 part;
    struct Unk_03001800 *s = &gUnk_03001800;

    bot_restore_leg_stats(s->unk88);
    if (gUnk_03000590[s->unk87].parts[s->unkA7].data[7] && s->unkCA && (part = find_random_broken_part(s->unk88))) {
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
    armor_heal_step(&gUnk_03001800.unkC8, gUnk_03001800.unk88, gUnk_03001800.unk8B);
    if (gUnk_03001800.unkF8 & 2) {
        get_active_bot_part_index_and_load_values(0);
        draw_medabot_sprite(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                            gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156,
                            gUnk_03001800.unk39[3] + 2, 4, 0, 2, 0, gUnk_03001800.unk114[0]);
        draw_medabot_sprite(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                            gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156,
                            gUnk_03001800.unk39[3] + 2, 4, 0, 1, 0, gUnk_03001800.unk114[0]);
    } else {
        get_active_bot_part_index_and_load_values(1);
        draw_medabot_sprite(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                            gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A,
                            gUnk_03001800.unk39[3] + 2, 8, 1, 2, 1, gUnk_03001800.unk114[1]);
        draw_medabot_sprite(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                            gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A,
                            gUnk_03001800.unk39[3] + 2, 8, 1, 1, 1, gUnk_03001800.unk114[1]);
    }
    gUnk_03001800.unkAA++;
}

void repair_repeat(void) {
    gUnk_03001800.unkAA = 2;
}

void trap_run(void) {
    gUnk_03001800.unkB5 = 0;
    gTrapSteps[gUnk_03001800.unkAA]();
}

void trap_begin(void) {
    u32 r;

    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    r = decrement_battle_timer_and_check_zero();
    if (r) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
        return;
    }
    calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    side_add_action_point();
    switch (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1]) {
    case 0xA:
        gUnk_03001800.unk51 = r;
        break;
    case 0xB:
        gUnk_03001800.unk51 = 1;
        break;
    case 0xC:
        gUnk_03001800.unk51 = 2;
        break;
    default:
        gUnk_03001800.unk51 = 3;
        break;
    }
    gUnk_03001800.unk52 = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
    gUnk_03001800.unkAA = 4;
}

// Steps 4-7 of most skill sequences (also the Interrupt skills): a sprite hops over the user, then a
// burst animation plays. guess: the "skill cast" effect.
void skill_cast_hop_spawn(void) {
    lz_decompress_dispatch(gUnk_084D50DC, (void *)0x06015800);
    CpuFastSet(gUnk_0850E658, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[0x5D + gUnk_03001800.unk87 * 4].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[0x5D + gUnk_03001800.unk87 * 4].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk6 = 0x4100;
    gSpriteEntries[0x21].unk23 = 0;
    gSpriteEntries[0x21].unk27 = 0;
    play_sound_effect(0x29);
    gUnk_03001800.unkAA++;
}

void skill_cast_hop(void) {
    sprite_hop_step(0x21);
    if (gSpriteEntries[0x21].unk27 == 0x20) {
        gSpriteEntries[0x21].unk0 &= ~0x200;
        gSpriteEntries[0x21].unk18 = 0;
        gUnk_03001800.unkAA++;
        return;
    }
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x20) & 0x3FF;
    else
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 - 0x20) & 0x3FF;
    if (!(gSpriteEntries[0x21].unk27 & 1)) {
        if (!(gUnk_03001800.unkF8 & 1))
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
    gUnk_03001800.unkAA++;
}

void skill_cast_flash_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x23], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF)
        gUnk_03001800.unkAA++;
}

void trap_sprite_spawn(void) {
    switch (gUnk_03001800.unk51) {
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
    if (gUnk_03001800.unkF8 & 1) {
        gSpriteEntries[0x21].unk0 |= 0x1000;
        gSpriteEntries[0x21].unk2--;
    }
    gUnk_03001800.unkAA++;
}

void trap_sprite_grow(void) {
    if ((gSpriteEntries[0x21].unk8 += 8) == 0x40) {
        if (gUnk_03001800.unk51 == 3)
            gUnk_03000440.unk86 = 1;
        else
            gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void trap_sprite_hold(void) {
    gUnk_03000440.unk86--;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03000440.unk86 = 0;
    if (gUnk_03000440.unk86 == 0) {
        switch (gUnk_03001800.unk51) {
        case 0:
        case 1:
        case 2:
            gSpriteEntries[0x21].unk27 = 0;
            gUnk_03001800.unkAA++;
            break;
        case 3:
            play_sound_effect(0x52);
            gUnk_03001800.unkAA = 0x20;
            break;
        }
    }
}

void trap_sprite_slide(void) {
    if (gSpriteEntries[0x21].unk27 == 0x10) {
        gUnk_03001800.unkAA++;
        return;
    }
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x21].unk2++;
    else
        gSpriteEntries[0x21].unk2--;
    gSpriteEntries[0x21].unk27++;
}

// The side already holds this trap: pulse the sprite and add to it; Attack Clr skips the pulse.
void trap_check_existing(void) {
    if (gUnk_03001800.unk28[gUnk_03001800.unk8A].active &&
        gUnk_03001800.unk28[gUnk_03001800.unk8A].skill == gUnk_03001800.unk52) {
        gSpriteEntries[0x21].unk27 = 0;
        gUnk_03001800.unkAA++;
    } else if (gUnk_03001800.unk51 == 2) {
        gUnk_03001800.unkAA = 0x14;
    } else {
        play_sound_effect(0x3E);
        gUnk_03001800.unkAA = 0xE;
    }
}

void trap_sprite_pulse(void) {
    if (gSpriteEntries[0x21].unk27 == 0x10) {
        if (gUnk_03001800.unk51 == 2) {
            gUnk_03001800.unkAA = 0x14;
        } else {
            play_sound_effect(0x3E);
            gUnk_03001800.unkAA = 0xE;
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
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 8;
    }
}

// unk28[side]: the side's trap / Team Form record (active, skill kind, power); a repeat stacks half.
void trap_apply(void) {
    if (gUnk_03001800.unk28[gUnk_03001800.unk8A].active &&
        gUnk_03001800.unk28[gUnk_03001800.unk8A].skill == gUnk_03001800.unk52) {
        gUnk_03001800.unk53 = 1;
        if (gUnk_03001800.unk51 != 2) {
            add_u8_capped(&gUnk_03001800.unk28[gUnk_03001800.unk8A].durability, gUnk_03001800.unkE8 >> 1, 0xFF);
            add_u8_capped(&gUnk_03001800.unk28[gUnk_03001800.unk8A].power,
                          (gUnk_03001800.unkEC + gUnk_03000590[gUnk_03001800.unk87].unkD5) >> 1, 0xFF);
            gUnk_03001800.unkAA++;
        } else {
            gUnk_03001800.unk28[gUnk_03001800.unk8A].durability++;
            gUnk_03001800.unkAA++;
        }
    } else {
        gUnk_03001800.unk53 = 0;
        gUnk_03001800.unk28[gUnk_03001800.unk8A].active = 1;
        gUnk_03001800.unk28[gUnk_03001800.unk8A].skill = gUnk_03001800.unk52;
        gUnk_03001800.unk28[gUnk_03001800.unk8A].durability = 0;
        gUnk_03001800.unk28[gUnk_03001800.unk8A].power = 0;
        if (gUnk_03001800.unk51 != 2) {
            add_u8_capped(&gUnk_03001800.unk28[gUnk_03001800.unk8A].durability, gUnk_03001800.unkE8, 0xFF);
            add_u8_capped(&gUnk_03001800.unk28[gUnk_03001800.unk8A].power,
                          gUnk_03001800.unkEC + gUnk_03000590[gUnk_03001800.unk87].unkD5, 0xFF);
        } else {
            gUnk_03001800.unk28[gUnk_03001800.unk8A].durability++;
        }
        gUnk_03001800.unkAA++;
    }
}

void trap_finish(void) {
    switch (gUnk_03001800.unk51) {
    case 0:
        gUnk_03001800.unkA6 = 0x1E;
        break;
    case 1:
        gUnk_03001800.unkA6 = 0x1F;
        break;
    case 2:
        gUnk_03001800.unkA6 = 0x20;
        break;
    case 3:
        gUnk_03001800.unkA6 = 0x21;
        break;
    }
    if (gUnk_03001800.unk53)
        gUnk_03001800.unkA6 = 0x71;
    gUnk_03001800.unkAA++;
}

void trap_sprite_fly_init(void) {
    gSpriteEntries[0x21].unk24 = 4;
    gSpriteEntries[0x21].unk25 = 0;
    gSpriteEntries[0x21].unk30 = 0;
    play_sound_effect(0x40);
    gUnk_03001800.unkAA++;
}

void trap_sprite_fly(void) {
    if (update_sprite_deceleration(0x21, -0x40, -0x30)) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void team_form_anim_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x38], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void team_form_split(void) {
    struct SpriteEntry *spr;

    gUnk_03000440.unk86--;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03000440.unk86 = 0;
    if (gUnk_03000440.unk86 == 0) {
        spr = &gSpriteEntries[0x21];
        memcpy_bytes_0803F63C(spr, spr + 1, 0x40);
        memcpy_bytes_0803F63C(spr, spr + 2, 0x40);
        spr[0].unk32 = 0x58;
        spr[0].unk24 = 6;
        spr[1].unk32 = 0x40;
        spr[1].unk24 = 6;
        spr[2].unk32 = 0x28;
        spr[2].unk24 = 6;
        if (!(gUnk_03001800.unkF8 & 1))
            spr[2].unk30 = spr[1].unk30 = spr[0].unk30 = 0x88;
        else
            spr[2].unk30 = spr[1].unk30 = spr[0].unk30 = 0x68;
        gUnk_03001800.unkAA++;
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
        gUnk_03001800.unkAA++;
}

void team_form_check_existing(void) {
    if (gUnk_03001800.unk28[gUnk_03001800.unk8A].active &&
        gUnk_03001800.unk28[gUnk_03001800.unk8A].skill == gUnk_03001800.unk52) {
        gSpriteEntries[0x21].unk27 = 0;
        gUnk_03001800.unkAA++;
    } else {
        play_sound_effect(0x3E);
        gUnk_03001800.unkAA = 0x25;
    }
}

void team_form_pulse(void) {
    if (gSpriteEntries[0x21].unk27 == 0x10) {
        play_sound_effect(0x3E);
        gUnk_03001800.unkAA++;
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
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 8;
        gSpriteEntries[0x22].unk8 -= 8;
        gSpriteEntries[0x23].unk8 -= 8;
    }
}

void break_form_run(void) {
    gUnk_03001800.unkB5 = 0;
    gBreakFormSteps[gUnk_03001800.unkAA]();
}

void break_form_begin(void) {
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    } else if (!gUnk_03001800.unk28[gUnk_03001800.unk89].active) {
        gUnk_03001800.unkA6 = 0x24;
        gUnk_03001800.unkAA++;
    } else {
        side_add_action_point();
        gUnk_03001800.unkAA = 4;
    }
}

void break_form_sprite_spawn(void) {
    lz_decompress_dispatch(gUnk_084D54BC, (void *)0x06014800);
    CpuFastSet(gUnk_0850E698, (void *)0x050002E0, 8);
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x39], 0x21);
    if (gUnk_03001800.unkF8 & 1)
        gSpriteEntries[0x21].unk0 |= 0x1000;
    gUnk_03001800.unkAA++;
}

void break_form_anim_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x39], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3B], 0x21);
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void break_form_hold(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x3B], 0x21);
    gUnk_03000440.unk86--;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03000440.unk86 = 0;
    if (gUnk_03000440.unk86 == 0)
        gUnk_03001800.unkAA++;
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
    if (gUnk_03001800.unkF8 & 1)
        spr[2].unk30 = spr[1].unk30 = spr[0].unk30 = 0x88;
    else
        spr[2].unk30 = spr[1].unk30 = spr[0].unk30 = 0x68;
    gUnk_03001800.unkAA++;
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
        gUnk_03001800.unkAA++;
    }
}

void break_form_hit_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x3A], 0x21);
    process_sprite_anim_commands(gUnk_083B5F80[0x3A], 0x22);
    process_sprite_anim_commands(gUnk_083B5F80[0x3A], 0x23);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_sprite_table_mask(0x21, 3);
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
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
        if (gUnk_03000590[i].unk40) {
            gSpriteEntries[0x5A + i * 4].unk23 = 0;
            gSpriteEntries[0x5B + i * 4].unk23 = 0;
            gSpriteEntries[0x5C + i * 4].unk23 = 0;
            gSpriteEntries[0x5D + i * 4].unk23 = 0;
        }
    }
    gUnk_03000440.unk86 = 0;
    gUnk_03001800.unkAA++;
}

void break_form_shatter(void) {
    u32 i;

    gUnk_03000440.unk86++;
    bg3_shake_step(gUnk_03000440.unk86);
    for (i = 0; i < 6; i++) {
        if (gUnk_03000590[i].unk40) {
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
            if (gUnk_03000590[i].unk40) {
                gSpriteEntries[0x5A + i * 4].unk23 = 0;
                gSpriteEntries[0x5B + i * 4].unk23 = 0;
                gSpriteEntries[0x5C + i * 4].unk23 = 0;
                gSpriteEntries[0x5D + i * 4].unk23 = 0;
            }
        }
        gBg3Scroll.y = 0;
        clear_battle_sprite_slot(0x21, 3);
        gUnk_03001800.unkAA++;
    }
}

void break_form_apply(void) {
    gUnk_03001800.unk28[gUnk_03001800.unk89].active = 0;
    gUnk_03001800.unk28[gUnk_03001800.unk89].skill = 0;
    gUnk_03001800.unk28[gUnk_03001800.unk89].durability = 0;
    gUnk_03001800.unk28[gUnk_03001800.unk89].power = 0;
    gUnk_03001800.unkAA++;
}

void break_form_finish(void) {
    gUnk_03001800.unkA6 = 0x25;
    gUnk_03001800.unkAA++;
}

void stability_run(void) {
    gUnk_03001800.unkB5 = 0;
    gStabilitySteps[gUnk_03001800.unkAA]();
}

void stability_begin(void) {
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    } else if (!gUnk_03000590[gUnk_03001800.unk88].unkC9) {
        gUnk_03001800.unkA6 = 0x70;
        gUnk_03001800.unkAA++;
    } else {
        side_add_action_point();
        gUnk_03001800.unkAA = 4;
    }
}

void stability_sprite_spawn(void) {
    lz_decompress_dispatch(gUnk_084D55D0, (void *)0x06014800);
    CpuFastSet(gUnk_0850E6B8, (void *)0x050002E0, 8);
    if (gUnk_03001800.unkF8 & 1)
        gSpriteEntries[0x21].unk0 |= 0x1000;
    gSpriteEntries[0x21].unk0 |= 0x200;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3C], 0x21);
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void stability_sprite_fly(void) {
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 - 0x40) & 0x3FF;
    else
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x40) & 0x3FF;
    if (move_sprite_toward_target(0x21)) {
        gSpriteEntries[0x21].unk0 &= ~0x200;
        gSpriteEntries[0x21].unk18 = 0;
        gUnk_03001800.unkAA++;
    }
}

// Stability cures the target's negative status (unkC9-unkCC, set by Impair, Confusion...).
void stability_apply(void) {
    gUnk_03000590[gUnk_03001800.unk88].unkC9 = 0;
    gUnk_03000590[gUnk_03001800.unk88].unkCA = 0;
    gUnk_03000590[gUnk_03001800.unk88].unkCB = 0;
    gUnk_03000590[gUnk_03001800.unk88].unkCC = 0;
    gSpriteEntries[gUnk_03001800.unk88 * 3 + 0x47].unk0 |= 0x8220;
    gSpriteEntries[gUnk_03001800.unk88 * 3 + 0x47].unk9 = 0x40;
    gSpriteEntries[gUnk_03001800.unk88 * 3 + 0x47].unk8 = 0x40;
    play_sound_effect(0x37);
    gUnk_03001800.unkAA++;
}

void stability_status_icon_fade(void) {
    if (gSpriteEntries[gUnk_03001800.unk88 * 3 + 0x47].unk8 != 4) {
        gSpriteEntries[gUnk_03001800.unk88 * 3 + 0x47].unk0 |= 0x8000;
        gSpriteEntries[gUnk_03001800.unk88 * 3 + 0x47].unk9 += 4;
        gSpriteEntries[gUnk_03001800.unk88 * 3 + 0x47].unk8 -= 4;
    }
    process_sprite_anim_commands(gUnk_083B5F80[0x3C], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        clear_battle_sprite_slot(gUnk_03001800.unk88 * 3 + 0x47, 1);
        gUnk_03001800.unkAA++;
    }
}

void stability_finish(void) {
    gUnk_03001800.unkA6 = 0x23;
    gUnk_03001800.unkAA++;
}

void force_bind_run(void) {
    gUnk_03001800.unkB5 = 0;
    gForceBindSteps[gUnk_03001800.unkAA]();
}

void force_bind_begin(void) {
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    } else {
        side_add_action_point();
        gUnk_03001800.unkAA = 4;
    }
}

void force_bind_orbs_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084D5788, (void *)0x06014800);
    CpuFastSet(gUnk_0850E6D8, (void *)0x050002E0, 8);
    for (i = 0; i < 4; i++) {
        gSpriteEntries[0x21 + i].unk0 = 0xC604;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
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
    gUnk_03001800.unkAA++;
}

void force_bind_orbs_spin(void) {
    u32 i;
    struct Coords16 v;

    for (i = 0; i < 4; i++) {
        process_sprite_anim_commands(gUnk_083B5F80[0x3D], 0x21 + i);
        v = calc_polar_to_screen_coords(gSpriteEntries[0x21 + i].unk2C, gSpriteEntries[0x21 + i].unk2B,
                                        gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2,
                                        gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4);
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
        gUnk_03001800.unkAA++;
    }
}

// Each use toggles Force Bind on (message 0x72) or off (0x73).
void force_bind_toggle(void) {
    if (!gUnk_03001800.unk58) {
        gUnk_03001800.unkA6 = 0x72;
        gUnk_03001800.unk58 = 1;
    } else {
        gUnk_03001800.unkA6 = 0x73;
        gUnk_03001800.unk58 = 0;
    }
    gUnk_03001800.unkAA++;
}

void defence_run(void) {
    gUnk_03001800.unkB5 = 0;
    gDefenceSteps[gUnk_03001800.unkAA]();
}

void defence_begin(void) {
    u32 r;

    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    r = decrement_battle_timer_and_check_zero();
    if (r) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    } else {
        side_add_action_point();
        switch (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1]) {
        case 0x1B:
            gUnk_03001800.unk51 = r;
            break;
        case 0x1C:
            gUnk_03001800.unk51 = 1;
            break;
        default:
            gUnk_03001800.unk51 = 2;
            break;
        }
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void defence_shields_spawn(void) {
    switch (gUnk_03001800.unk51) {
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
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x20;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
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
    gSpriteEntries[0x22].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x20;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = 0xF0;
    gSpriteEntries[0x22].unk8 = 0x80;
    gSpriteEntries[0x22].unk9 = 0x80;
    gSpriteEntries[0x22].unk2B = 0x1C;
    gSpriteEntries[0x22].unk2C = 0x80;
    gSpriteEntries[0x22].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1C], 0x22);
    play_sound_effect(0x33);
    gUnk_03001800.unkAA++;
}

void defence_shields_spin(void) {
    u32 i;
    struct Coords16 v;

    for (i = 0; i < 2; i++) {
        v = calc_polar_to_screen_coords(gSpriteEntries[0x21 + i].unk2C, gSpriteEntries[0x21 + i].unk2B,
                                        gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2,
                                        gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4);
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
        gUnk_03001800.unkAA++;
    }
}

void defence_shield_anim_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x1C], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

// Marks the user as guarding (unkBD bit 3) with this skill (Defence, Full Block or Half Block).
void defence_apply(void) {
    gUnk_03000590[gUnk_03001800.unk87].unkBD |= 8;
    gUnk_03000590[gUnk_03001800.unk87].unkDF = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
    gUnk_03000590[gUnk_03001800.unk87].unkD8 = 0;
    add_u8_capped(&gUnk_03000590[gUnk_03001800.unk87].moveSubpixel + 1, gUnk_03001800.unkEC, 0xFF);
    gUnk_03001800.unkAA++;
}

void defence_finish(void) {
    gUnk_03001800.unkA6 = 0x1B;
    gUnk_03001800.unkAA++;
}

void autorecover_run(void) {
    gUnk_03001800.unkB5 = 0;
    gAutoRecoverSteps[gUnk_03001800.unkAA]();
}

void autorecover_begin(void) {
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    } else if (!battle_bot_lacks_stability(gUnk_03001800.unk88)) {
        gUnk_03001800.unkA6 = 0x39;
        gUnk_03001800.unkAA++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void autorecover_orb_spawn(void) {
    lz_decompress_dispatch(gUnk_084D5860, (void *)0x06014800);
    CpuFastSet(gUnk_0850E6F8, (void *)0x050002C0, 0x10);
    gSpriteEntries[0x21].unk0 |= 0x200;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3E], 0x21);
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void heal_orb_hold(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x3E], 0x21);
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03001800.unkAA++;
    else if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else
        gUnk_03001800.unkAA++;
}

void heal_orb_fly(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x3E], 0x21);
    if (move_sprite_toward_target(0x21))
        gUnk_03001800.unkAA++;
}

void heal_orb_shrink(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x3E], 0x21);
    if (gSpriteEntries[0x21].unk8 == 8) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    } else
        gSpriteEntries[0x21].unk8 -= 8;
}

void autorecover_ring_spawn(void) {
    u32 i;
    struct Coords16 v;

    gSpriteEntries[0x25].unk0 = 0xC604;
    gSpriteEntries[0x25].unk1C = 0;
    gSpriteEntries[0x25].unk2 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[0x25].unk4 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x25].unkA = 7;
    gSpriteEntries[0x25].unk8 = 0x40;
    gSpriteEntries[0x25].unk9 = 0x40;
    gSpriteEntries[0x25].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3F], 0x25);
    for (i = 0; i < 4; i++) {
        gSpriteEntries[0x21 + i].unk0 = 0xC604;
        v = calc_polar_to_screen_coords(i << 6, 0x10, gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk2,
                                        gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4);
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
    gUnk_03001800.unkAA++;
}

void heal_ring_spin(void) {
    u32 i;
    struct Coords16 v;
    u32 n;

    process_sprite_anim_commands(gUnk_083B5F80[0x3F], 0x25);
    for (i = 0; i < 5; i++) {
        if (i < 4) {
            v = calc_polar_to_screen_coords(gSpriteEntries[0x21 + i].unk2C, gSpriteEntries[0x21 + i].unk2B,
                                            gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk2,
                                            gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4);
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
        gUnk_03001800.unkAA++;
    }
}

// Gives the target the AutoRecover status (unkC4 = skill 31) with this action's power.
void autorecover_apply(void) {
    gUnk_03000590[gUnk_03001800.unk88].unkC4 = 0x1F;
    gUnk_03000590[gUnk_03001800.unk88].unkC5 = 0;
    gUnk_03000590[gUnk_03001800.unk88].unkC6 = clamp_1_99(gUnk_03001800.unkE8);
    gUnk_03000590[gUnk_03001800.unk88].unkC7 = clamp_1_99(gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void autorecover_finish(void) {
    gUnk_03001800.unkA6 = 0x29;
    gUnk_03001800.unkAA++;
}

void reactivate_run(void) {
    gUnk_03001800.unkB5 = 0;
    gReactivateSteps[gUnk_03001800.unkAA]();
}

void reactivate_begin(void) {
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    } else if (gUnk_03000590[gUnk_03001800.unk88].parts[0].unk11) {
        gUnk_03001800.unkA6 = 9;
        gUnk_03001800.unkAA++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void reactivate_orb_spawn(void) {
    lz_decompress_dispatch(gUnk_084D5B08, (void *)0x06014800);
    CpuFastSet(gUnk_0850E738, (void *)0x050002C0, 0x10);
    gSpriteEntries[0x21].unk0 |= 0x200;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3E], 0x21);
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void reactivate_ring_spawn(void) {
    u32 i;
    struct Coords16 v;

    gSpriteEntries[0x25].unk0 = 0xC604;
    gSpriteEntries[0x25].unk1C = 0;
    gSpriteEntries[0x25].unk2 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[0x25].unk4 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x25].unkA = 7;
    gSpriteEntries[0x25].unk8 = 0x40;
    gSpriteEntries[0x25].unk9 = 0x40;
    gSpriteEntries[0x25].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3F], 0x25);
    for (i = 0; i < 4; i++) {
        gSpriteEntries[0x21 + i].unk0 = 0xC604;
        v = calc_polar_to_screen_coords(i << 6, 0x10, gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk2,
                                        gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4);
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
    gUnk_03001800.unkAA++;
}

// Revives a target whose head is broken: refills the head and redraws its parts.
void reactivate_apply(void) {
    gUnk_03000590[gUnk_03001800.unk88].unk40 = 3;
    battle_calc_damage_split(gUnk_03001800.unk88, 0, gUnk_03001800.unkEC);
    gUnk_03000590[gUnk_03001800.unk88].parts[0].unk11 = gUnk_03001800.unkC8;
    gUnk_03000590[gUnk_03001800.unk88].unkBA = 1;
    load_all_bot_part_sprites();
    iterate_bots_setup_battle_sprites();
    gUnk_03001800.unkAA++;
}

void reactivate_finish(void) {
    memcpy_bytes_0803F63C(gUnk_03000590[gUnk_03001800.unk88].medal.unkA, gUnk_03000440.unk9E, 0xE);
    gUnk_03001800.unkA6 = 0x28;
    gUnk_03001800.unkAA++;
}
