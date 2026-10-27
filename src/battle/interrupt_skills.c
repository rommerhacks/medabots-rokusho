// Effect sequences of the Interrupt abilities (and two Defend ones): action script opcodes 0x36-0x3F.
// Each runner (*_run: clears unkB5 and calls entry [unkAA] of its step table) is one action script command
// (gActionScriptCommands, opcode order = ROM order); its step handlers follow it and the last step sets unkA6.
// Abilities are part data[1], and the script of ability n is gActionScripts[n]:
//   0x36 Impair (43), 0x37 Confusion (44), 0x38 Use Drain (45), 0x39 No Escape (46) / No Defense (47),
//   0x3A Forcedrain (50), 0x3B / 0x3C TeamAttack (52: a Shoot script with the Team Form check and the turret
//   animation inserted), 0x3D clears the queued action (script_op_clear_queued_action, in action_script.c),
//   0x3E CntrAttk (54), 0x3F Change, ItrpChange, AttkChange, DEF Change, HealChange (55-59).
// Skill names from the in-game skill list and help texts (text after gUnk_083BE4D4); effects match a
// public FAQ's skill table. Steps 1-3 of each table are the shared time-out steps and 4-7 the shared
// "small Medabot tosses something" steps of battle/action_steps.
// Statuses set on the target: unkC9 = skill id (0x2B Impair, 0x2C Confusion, 0x2E / 0x2F No Escape /
// No Defense), unkCA = Impair's part kind + 1, unkCB / unkCC = durations (clamp_1_99).

#include "global.h"

void impair_run(void) {
    gBattleWork.unkB5 = 0;
    gImpairSteps[gBattleWork.unkAA]();
}

void impair_begin(void) {
    calc_battle_action_speed(gBattleWork.unk87, gBattleWork.unkA7);
    apply_battle_bot_damage_reduction(gBattleWork.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.unkA6 = 0x1A;
        gBattleWork.unkAA++;
    } else if (battle_bot_lacks_stability(gBattleWork.unk88) == 0) {
        gBattleWork.unkA6 = 0x39;
        gBattleWork.unkAA++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.unk87, gBattleWork.unkA7);
        gBattleWork.unkAA = 4;
    }
}

void impair_portrait_spawn(void) {
    lz_decompress_dispatch(gUnk_084D651C, (void *)0x06014800);
    CpuFastSet(gUnk_0850E858, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 |= 0x220;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk6 = 0x4E00;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    gGameWork.unk86 = 0x3C;
    gBattleWork.unkAA++;
}

// Shows the portrait icon with the targeted part (unk8B: 0 head, 1 right arm, 2 left arm) highlighted.
void impair_part_icon_spawn(void) {
    clear_sprite_table_mask(0x21, 1);
    gSpriteEntries[0x22].unk0 = 0xC404;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk2;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk4 - 4;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = 0xE0;
    gSpriteEntries[0x22].unk23 = 0;
    switch (gBattleWork.unk8B) {
    case 1:
        gSpriteEntries[0x22].unk6 = 0x4E02;
        break;
    case 2:
        gSpriteEntries[0x22].unk6 = 0x4E03;
        break;
    default:
        gSpriteEntries[0x22].unk6 = 0x4E01;
        break;
    }
    play_sound_effect(0x6A);
    gBattleWork.unkAA++;
}

void interrupt_icon_anim_wait(void) {
    if (advance_sprite_anim_frame(0x22, 0)) {
        gGameWork.unk86 = 0x3C;
        gBattleWork.unkAA++;
    }
}

// Steps shared with No Escape / No Defense: the X drawn over the icon, shrinking in, then shaking.
void interrupt_cross_spawn(void) {
    set_sprite_hidden_flags(0x21, 1);
    gSpriteEntries[0x21].unk0 |= 0x220;
    gSpriteEntries[0x21].unk8 = 0x80;
    gSpriteEntries[0x21].unk9 = 0x80;
    gBattleWork.unkAA++;
}

void interrupt_cross_shrink(void) {
    if (gSpriteEntries[0x21].unk8 == 0x40) {
        play_sound_effect(0x3C);
        gGameWork.unk86 = 0;
        gBattleWork.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 8;
        gSpriteEntries[0x21].unk9 -= 8;
    }
}

void interrupt_cross_shake(void) {
    if (gGameWork.unk86 == 0x3C) {
        clear_battle_sprite_slot(0x21, 2);
        gBattleWork.unkAA++;
    } else {
        gGameWork.unk86++;
        if (gGameWork.unk86 & 4)
            gSpriteEntries[0x21].unk2 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk2 - 2;
        else
            gSpriteEntries[0x21].unk2 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk2 + 2;
    }
}

void impair_apply(void) {
    gBattleBots[gBattleWork.unk88].unkC9 = 0x2B;
    gBattleBots[gBattleWork.unk88].unkCB = clamp_1_99(gBattleWork.unkE8);
    gBattleBots[gBattleWork.unk88].unkCC = clamp_1_99(gBattleWork.unkEC);
    switch (gBattleWork.unk8B) {
    case 1:
        gBattleBots[gBattleWork.unk88].unkCA = 2;
        break;
    case 2:
        gBattleBots[gBattleWork.unk88].unkCA = 3;
        break;
    default:
        gBattleBots[gBattleWork.unk88].unkCA = 1;
        break;
    }
    gBattleWork.unkAA++;
}

void impair_finish(void) {
    const u8 *kind_name;

    switch (gBattleWork.unk8B) {
    case 1:
        kind_name = gPartKindNames[1];
        break;
    case 2:
        kind_name = gPartKindNames[2];
        break;
    default:
        kind_name = gPartKindNames[0];
        break;
    }
    memcpy_bytes_0803F63C(kind_name, gGameWork.unk9E, 0xE);
    gBattleWork.unkA6 = 0x30;
    gBattleWork.unkAA++;
}

void confusion_run(void) {
    gBattleWork.unkB5 = 0;
    gConfusionSteps[gBattleWork.unkAA]();
}

void confusion_begin(void) {
    calc_battle_action_speed(gBattleWork.unk87, gBattleWork.unkA7);
    apply_battle_bot_damage_reduction(gBattleWork.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.unkA6 = 0x1A;
        gBattleWork.unkAA++;
    } else if (battle_bot_lacks_stability(gBattleWork.unk88) == 0) {
        gBattleWork.unkA6 = 0x39;
        gBattleWork.unkAA++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.unk87, gBattleWork.unkA7);
        gBattleWork.unkAA = 4;
    }
}

void confusion_ball_spawn(void) {
    lz_decompress_dispatch(gUnk_084D6780, (void *)0x06014800);
    CpuFastSet(gUnk_0850E878, (void *)0x050002C0, 0x10);
    if (gBattleWork.unkF8 & 1)
        gSpriteEntries[0x21].unk0 |= 0x1000;
    gSpriteEntries[0x21].unk0 |= 0x220;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unk6 = 0x4F00;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    gGameWork.unk86 = 0x3C;
    gBattleWork.unkAA++;
}

void confusion_wave_init(void) {
    play_sound_effect(0x33);
    gSpriteEntries[0x21].unk0 |= 0x220;
    gBattleWork.unkAA++;
}

void confusion_wave_spin(void) {
    if (!(gBattleWork.unkF8 & 1))
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 - 0x80) & 0x3FF;
    else
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x80) & 0x3FF;
    if (gSpriteEntries[0x21].unk8 == 0x80)
        gBattleWork.unkAA++;
    else {
        gSpriteEntries[0x21].unk8++;
        gSpriteEntries[0x21].unk9++;
    }
}

void confusion_marks_spawn(void) {
    if (gBattleWork.unkF8 & 1)
        gSpriteEntries[0x21].unk0 &= ~0x1000;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk4 - 0xC;
    gGameWork.unk84 = 0x47;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gGameWork.unk84], 0x21);
    play_sound_effect(0x4F);
    gBattleWork.unkAA++;
}

void confusion_apply(void) {
    clear_battle_sprite_slot(0x21, 1);
    gBattleBots[gBattleWork.unk88].unkC9 = 0x2C;
    gBattleBots[gBattleWork.unk88].unkCA = 0;
    gBattleBots[gBattleWork.unk88].unkCB = clamp_1_99(gBattleWork.unkE8);
    gBattleBots[gBattleWork.unk88].unkCC = clamp_1_99(gBattleWork.unkEC);
    gBattleWork.unkAA++;
}

void confusion_finish(void) {
    gBattleWork.unkA6 = 0x33;
    gBattleWork.unkAA++;
}

void use_drain_run(void) {
    gBattleWork.unkB5 = 0;
    gUseDrainSteps[gBattleWork.unkAA]();
}

// Fails (unkA6 0x34) when the target's head has no uses left.
void use_drain_begin(void) {
    calc_battle_action_speed(gBattleWork.unk87, gBattleWork.unkA7);
    apply_battle_bot_damage_reduction(gBattleWork.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.unkA6 = 0x1A;
        gBattleWork.unkAA++;
    } else if (gBattleBots[gBattleWork.unk88].parts[0].unk10 == 0) {
        gBattleWork.unkA6 = 0x34;
        gBattleWork.unkAA++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.unk87, gBattleWork.unkA7);
        gBattleWork.unkAA = 4;
    }
}

void use_drain_bubble_spawn(void) {
    lz_decompress_dispatch(gUnk_084D6AAC, (void *)0x06014800);
    CpuFastSet(gUnk_0850E8B8, (void *)0x050002C0, 0x10);
    gSpriteEntries[0x21].unk0 |= 0x220;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unk6 = 0x5000;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 3;
    gSpriteEntries[0x21].unk23 = 0;
    gGameWork.unk86 = 0x3C;
    gBattleWork.unkAA++;
}

void use_drain_bubble_hold(void) {
    sprite_bob_step(0x21);
    if (gGameWork.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gBattleWork.unkAA++;
    else if (gGameWork.unk86)
        gGameWork.unk86--;
    else
        gBattleWork.unkAA++;
}

void use_drain_bubble_fly(void) {
    if (move_sprite_toward_target(0x21))
        gBattleWork.unkAA++;
    sprite_bob_step(0x21);
}

void use_drain_drop_spawn(void) {
    sprite_bob_step(0x21);
    gSpriteEntries[0x22].unk0 = 0xC604;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk2;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk4 - 4;
    gSpriteEntries[0x22].unk8 = 1;
    gSpriteEntries[0x22].unk9 = 1;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = 0xE0;
    gSpriteEntries[0x22].unk6 = 0x5001;
    gSpriteEntries[0x22].unk30 = gSpriteEntries[0x5D + gBattleWork.unk87 * 4].unk2;
    gSpriteEntries[0x22].unk32 = gSpriteEntries[0x5D + gBattleWork.unk87 * 4].unk4 - 4;
    gSpriteEntries[0x22].unk24 = 3;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[0x5D + gBattleWork.unk87 * 4].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[0x5D + gBattleWork.unk87 * 4].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 3;
    play_sound_effect(0x6F);
    gBattleWork.unkAA++;
}

void use_drain_drop_grow(void) {
    sprite_bob_step(0x21);
    if (gSpriteEntries[0x22].unk8 == 0x40) {
        gSpriteEntries[0x22].unk2 = gSpriteEntries[0x21].unk2;
        gSpriteEntries[0x22].unk4 = gSpriteEntries[0x21].unk4;
        gBattleWork.unkAA++;
    } else {
        gSpriteEntries[0x22].unk8++;
        gSpriteEntries[0x22].unk9++;
    }
}

void use_drain_bubble_return(void) {
    if (move_sprite_toward_target(0x21)) {
        gSpriteEntries[0x22].unk2 = gSpriteEntries[0x21].unk2;
        gSpriteEntries[0x22].unk4 = gSpriteEntries[0x21].unk4;
        play_sound_effect(0x2B);
        gBattleWork.unkAA++;
    }
    sprite_bob_step(0x21);
    gSpriteEntries[0x22].unk2 = gSpriteEntries[0x21].unk2;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[0x21].unk4;
}

void use_drain_bubble_shrink(void) {
    sprite_bob_step(0x21);
    gSpriteEntries[0x22].unk2 = gSpriteEntries[0x21].unk2;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[0x21].unk4;
    if (gSpriteEntries[0x21].unk8 == 1) {
        clear_battle_sprite_slot(0x21, 2);
        gBattleWork.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8--;
        gSpriteEntries[0x21].unk9--;
        gSpriteEntries[0x22].unk8--;
        gSpriteEntries[0x22].unk9--;
    }
}

// Moves head uses (parts[0].unk10) from the target to the user, capped by the user's maximum (data[8]).
void use_drain_apply(void) {
    calc_head_uses_taken(gBattleWork.unk88, gBattleWork.unkEC);
    gBattleWork.unk51 = gBattleWork.unkC8;
    subtract_u8_floored(&gBattleBots[gBattleWork.unk88].parts[0].unk10, gBattleWork.unk51);
    calc_head_uses_given(gBattleWork.unk87, gBattleWork.unk51);
    gBattleWork.unk52 = gBattleWork.unkC8;
    add_u8_capped(&gBattleBots[gBattleWork.unk87].parts[0].unk10, gBattleWork.unk52,
                  gBattleBots[gBattleWork.unk87].parts[0].data[8]);
    gBattleWork.unkAA++;
}

void use_drain_popup_init(void) {
    lz_decompress_dispatch(gUnk_084D6BFC, (void *)0x06017E00);
    set_display_digit_type(&gGameWork.unkEE, gBattleWork.unk51, 1);
    battle_text_popup_init_slot(&gGameWork.unkEE, gBattleWork.unk88, 0x21);
    set_display_digit_type(&gGameWork.unkEE + 0x20, gBattleWork.unk52, 0);
    battle_text_popup_init_slot(&gGameWork.unkEE + 0x20, gBattleWork.unk87, 0x21);
    play_sound_effect(0x5B);
    gGameWork.unk84 = 0;
    gBattleWork.unkAA++;
}

void use_drain_popup_wait(void) {
    battle_popup_update_slot(&gGameWork.unkEE, gBattleWork.unk88, 0x21);
    battle_popup_update_slot(&gGameWork.unkEE + 0x20, gBattleWork.unk87, 0x21);
    if (++gGameWork.unk84, gGameWork.unk89 == 0 && (KEYS_LO(gRepeatKeys) & 1) && gGameWork.unk84 > 0x32)
        gGameWork.unk84 = 0x78;
    if (gGameWork.unk84 == 0x78) {
        clear_battle_sprite_slot(gBattleWork.unk88 * 4 + 0x21, 4);
        clear_battle_sprite_slot(gBattleWork.unk87 * 4 + 0x21, 4);
        gBattleWork.unkAA++;
    }
}

void use_drain_finish(void) {
    divide_by_100000_b(gGameWork.unk9E, gBattleWork.unk51, 0x35);
    gBattleWork.unkA6 = 0x35;
    gBattleWork.unkAA++;
}

void no_escape_defense_run(void) {
    gBattleWork.unkB5 = 0;
    gNoEscapeDefenseSteps[gBattleWork.unkAA]();
}

void no_escape_defense_begin(void) {
    calc_battle_action_speed(gBattleWork.unk87, gBattleWork.unkA7);
    apply_battle_bot_damage_reduction(gBattleWork.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.unkA6 = 0x1A;
        gBattleWork.unkAA++;
    } else if (battle_bot_lacks_stability(gBattleWork.unk88) == 0) {
        gBattleWork.unkA6 = 0x39;
        gBattleWork.unkAA++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.unk87, gBattleWork.unkA7);
        gBattleWork.unkAA = 4;
    }
}

// Ability 46 (0x2E) shows the running-person icon, 47 the shield icon.
void no_escape_defense_icon_load(void) {
    if (gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1] == 0x2E) {
        lz_decompress_dispatch(gUnk_084D6CC4, (void *)0x06014800);
        CpuFastSet(gUnk_0850E8F8, (void *)0x050002E0, 0x10);
    } else {
        lz_decompress_dispatch(gUnk_084D6E20, (void *)0x06014800);
        CpuFastSet(gUnk_0850E918, (void *)0x050002E0, 0x10);
    }
    gSpriteEntries[0x21].unk0 |= 0x220;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unk6 = 0x5200;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    gGameWork.unk86 = 0x3C;
    gBattleWork.unkAA++;
}

void no_escape_defense_icon_spawn(void) {
    clear_sprite_table_mask(0x21, 1);
    gSpriteEntries[0x22].unk0 = 0xC404;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk2;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk4 - 4;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = 0xE0;
    gSpriteEntries[0x22].unk23 = 0;
    gSpriteEntries[0x22].unk6 = 0x5201;
    play_sound_effect(0x6A);
    gBattleWork.unkAA++;
}

void no_escape_defense_apply(void) {
    gBattleBots[gBattleWork.unk88].unkCA = 0;
    gBattleBots[gBattleWork.unk88].unkCB = clamp_1_99(gBattleWork.unkE8);
    gBattleBots[gBattleWork.unk88].unkCC = clamp_1_99(gBattleWork.unkEC);
    if (gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1] == 0x2E)
        gBattleBots[gBattleWork.unk88].unkC9 = 0x2E;
    else
        gBattleBots[gBattleWork.unk88].unkC9 = 0x2F;
    gBattleWork.unkAA++;
}

void no_escape_defense_finish(void) {
    if (gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1] == 0x2E)
        gBattleWork.unkA6 = 0x31;
    else
        gBattleWork.unkA6 = 0x32;
    gBattleWork.unkAA++;
}

void forcedrain_run(void) {
    gBattleWork.unkB5 = 0;
    gForcedrainSteps[gBattleWork.unkAA]();
}

// Fails (unkA6 0x74) when the target has no Medaforce (unkC1).
void forcedrain_begin(void) {
    calc_battle_action_speed(gBattleWork.unk87, gBattleWork.unkA7);
    apply_battle_bot_damage_reduction(gBattleWork.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.unkA6 = 0x1A;
        gBattleWork.unkAA++;
    } else if (gBattleBots[gBattleWork.unk88].unkC1 == 0) {
        gBattleWork.unkA6 = 0x74;
        gBattleWork.unkAA++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.unk87, gBattleWork.unkA7);
        gBattleWork.unkAA = 4;
    }
}

void forcedrain_glass_spawn(void) {
    lz_decompress_dispatch(gUnk_084D6F88, (void *)0x06014800);
    CpuFastSet(gUnk_0850E938, (void *)0x050002E0, 0x10);
    gSpriteEntries[0x21].unk0 |= 0x220;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[0x5D + gBattleWork.unk88 * 4].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    gSpriteEntries[0x21].unk23 = 0;
    gGameWork.unk84 = 0x48;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gGameWork.unk84], 0x21);
    gGameWork.unk86 = 0x3C;
    gBattleWork.unkAA++;
}

// Drains up to unkEC Medaforce from the target and gives it to the user (doubled when unkC0 bit 3 is set);
// the gauge steps run on the target first (unk87 swapped, restored by forcedrain_glass_return).
void forcedrain_calc(void) {
    calc_drain_amount(gBattleBots[gBattleWork.unk88].unkC1, gBattleWork.unkEC);
    gBattleWork.unk51 = gBattleWork.unkC8;
    if (gBattleBots[gBattleWork.unk87].unkC0 & 8)
        calc_fill_amount(gBattleBots[gBattleWork.unk87].unkC1, 0x50, gBattleWork.unk51 * 2);
    else
        calc_fill_amount(gBattleBots[gBattleWork.unk87].unkC1, 0x50, gBattleWork.unk51);
    gBattleWork.unk52 = gBattleWork.unkC8;
    gBattleWork.unk64[0] = gBattleWork.unk87;
    gBattleWork.unk87 = gBattleWork.unk88;
    battle_substeps_reset();
    gBattleWork.unkAA++;
}

void forcedrain_substate_wait(void) {
    if (target_panels_show(0))
        gBattleWork.unkAA++;
}

void forcedrain_gauge_sound(void) {
    target_panels_show(0);
    play_sound_effect(0x51);
    gBattleWork.unkAA++;
}

void forcedrain_gauge_drain(void) {
    s32 done;

    target_panels_show(0);
    done = medaforce_gauge_drain_step(gBattleWork.unk87);
    process_sprite_anim_commands(gUnk_083B5F80[gGameWork.unk84], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF)
        done++;
    if (done == 2) {
        clear_battle_ui_tilemaps();
        battle_substeps_reset();
        gBattleWork.unkAA++;
    }
}

void forcedrain_glass_return(void) {
    gBattleWork.unk87 = gBattleWork.unk64[0];
    gBattleWork.unk51 = gBattleWork.unk52;
    gSpriteEntries[0x21].unk0 |= 0x220;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[0x5D + gBattleWork.unk87 * 4].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[0x5D + gBattleWork.unk87 * 4].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    gSpriteEntries[0x21].unk23 = 0;
    gBattleWork.unkAA++;
}

void forcedrain_gauge_fill(void) {
    s32 done;

    target_panels_show(0);
    done = medaforce_gauge_fill_step(gBattleWork.unk87);
    if (gSpriteEntries[0x21].unk0 & 0x8000) {
        gSpriteEntries[0x21].unk0 |= 0x220;
        if (gSpriteEntries[0x21].unk8 == 1) {
            clear_battle_sprite_slot(0x21, 1);
        } else {
            gSpriteEntries[0x21].unk8--;
            gSpriteEntries[0x21].unk9--;
        }
    } else {
        done++;
    }
    if (done == 2) {
        clear_battle_ui_tilemaps();
        battle_substeps_reset();
        gBattleWork.unkAA++;
    }
}

void forcedrain_finish(void) {
    gBattleWork.unkA6 = 0x75;
    gBattleWork.unkAA++;
}

void team_attack_check_run(void) {
    gBattleWork.unkB5 = 0;
    gTeamAttackCheckSteps[gBattleWork.unkAA]();
}

// guess: TeamAttack needs the queued action of slot unk8A to be Team Form (skill 0x33); else it fails
// with unkA6 0x22.
void team_attack_check_form(void) {
    if (gBattleWork.unk28[gBattleWork.unk8A].active && gBattleWork.unk28[gBattleWork.unk8A].skill == 0x33) {
        gBattleWork.unkAB = 0;
        gBattleWork.unkAA++;
    } else {
        gBattleWork.unkA6 = 0x22;
        gBattleWork.unkAB = 1;
        gBattleWork.unkAA = 2;
    }
}

void team_attack_turrets_run(void) {
    gBattleWork.unkB5 = 0;
    gTeamAttackTurretSteps[gBattleWork.unkAA]();
}

void team_attack_turrets_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084D513C, (void *)0x06014800);
    CpuFastSet(gUnk_0850E678, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        gSpriteEntries[i + 0x21].unk0 = 0xC404;
        gSpriteEntries[i + 0x21].unk1C = 0;
        gSpriteEntries[i + 0x21].unk4 = 0x58 - i * 0x18;
        gSpriteEntries[i + 0x21].unkA = 7;
        gSpriteEntries[i + 0x21].unkB = 0xF0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x38], i + 0x21);
        if (!(gBattleWork.unkF8 & 1)) {
            gSpriteEntries[i + 0x21].unk2 = 0x88;
        } else {
            gSpriteEntries[i + 0x21].unk0 |= 0x1000;
            gSpriteEntries[i + 0x21].unk2 = 0x68;
        }
    }
    play_sound_effect(0x52);
    gBattleWork.unkAA++;
}

void team_attack_turrets_anim(void) {
    u32 i;
    s32 done = 0;

    for (i = 0; i <= 2; i++) {
        process_sprite_anim_commands(gUnk_083B5F80[0x38], i + 0x21);
        if (gSpriteEntries[i + 0x21].unk22 == 0xFF)
            done = 1;
    }
    if (done) {
        gGameWork.unk86 = 0x3C;
        gBattleWork.unkAA++;
    }
}

void team_attack_turrets_clear(void) {
    clear_battle_sprite_slot(0x21, 3);
    gBattleWork.unkAA++;
}

void counter_attack_run(void) {
    gBattleWork.unkB5 = 0;
    gCounterAttackSteps[gBattleWork.unkAA]();
}

void counter_attack_begin(void) {
    calc_battle_action_speed(gBattleWork.unk87, gBattleWork.unkA7);
    apply_battle_bot_damage_reduction(gBattleWork.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.unkA6 = 0x1A;
        gBattleWork.unkAA++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.unk87, gBattleWork.unkA7);
        gBattleWork.unkAA = 4;
    }
}

void counter_attack_ball_spawn(void) {
    lz_decompress_dispatch(gUnk_084D71D8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E978, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC624;
    if (gBattleWork.unkF8 & 1)
        gSpriteEntries[0x21].unk0 |= 0x1000;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[0x5D + gBattleWork.unk87 * 4].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[0x5D + gBattleWork.unk87 * 4].unk4 - 6;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk6 = 0x616;
    gSpriteEntries[0x21].unk23 = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x4A], 0x21);
    gBattleWork.unkAA++;
}

void counter_attack_glove_show(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x4A], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        gSpriteEntries[0x21].unk8 = 0x80;
        gSpriteEntries[0x21].unk9 = 0x80;
        gSpriteEntries[0x21].unk6 = 0x5604;
        gSpriteEntries[0x21].unk4 = gSpriteEntries[0x5D + gBattleWork.unk87 * 4].unk4 - 4;
        gBattleWork.unkAA++;
    }
}

void counter_attack_glove_shrink(void) {
    if (gSpriteEntries[0x21].unk8 == 0x40) {
        play_sound_effect(0x53);
        gBattleWork.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 8;
        gSpriteEntries[0x21].unk9 -= 8;
    }
}

void counter_attack_glove_pulse_grow(void) {
    if (gSpriteEntries[0x21].unk8 == 0x50) {
        gBattleWork.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 += 4;
        gSpriteEntries[0x21].unk9 += 4;
    }
}

void counter_attack_glove_pulse_shrink(void) {
    if (gSpriteEntries[0x21].unk8 == 0x40) {
        gGameWork.unk86 = 0x3C;
        gBattleWork.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 4;
        gSpriteEntries[0x21].unk9 -= 4;
    }
}

// Arms the counter on the user: unkBD bit 4, unkDF = the skill id, unkD8 = the part's data[6].
void counter_attack_apply(void) {
    clear_battle_sprite_slot(0x21, 1);
    gBattleBots[gBattleWork.unk87].unkBD |= 0x10;
    gBattleBots[gBattleWork.unk87].unkDF = gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1];
    gBattleBots[gBattleWork.unk87].unkD8 = 0;
    add_u8_capped(&gBattleBots[gBattleWork.unk87].moveSubpixel + 1,
                  gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[6], 0xFF);
    gBattleWork.unkAA++;
}

void counter_attack_finish(void) {
    gBattleWork.unkA6 = 0x2A;
    gBattleWork.unkAA++;
}

void change_run(void) {
    gBattleWork.unkB5 = 0;
    gChangeSteps[gBattleWork.unkAA]();
}

// unkAB = 0 lets script_op_change restart the action (battle state 8) with the part swapped in.
void change_begin(void) {
    u32 timed_out;

    calc_battle_action_speed(gBattleWork.unk87, gBattleWork.unkA7);
    apply_battle_bot_damage_reduction(gBattleWork.unk87);
    timed_out = decrement_battle_timer_and_check_zero();
    if (timed_out) {
        gBattleWork.unkAB = 1;
        gBattleWork.unkA6 = 0x1A;
        gBattleWork.unkAA++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.unk87, gBattleWork.unkA7);
        gBattleWork.unkAB = timed_out;
        gBattleWork.unkAA = 4;
    }
}

void change_effect_spawn(void) {
    lz_decompress_dispatch(gUnk_084D7528, (void *)0x06014800);
    CpuFastSet(gUnk_0850E998, (void *)0x050002C0, 0x10);
    gSpriteEntries[0x21].unk0 = 0xC404;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[0x5D + gBattleWork.unk87 * 4].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[0x5D + gBattleWork.unk87 * 4].unk4 - 4;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unkB = 0xE0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x4B], 0x21);
    gSpriteEntries[0x22].unk0 = 0xC404;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = gSpriteEntries[0x5D + gBattleWork.unk87 * 4].unk2;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[0x5D + gBattleWork.unk87 * 4].unk4 - 6;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x4C], 0x22);
    play_sound_effect(0x5E);
    gGameWork.unk86 = 0;
    gBattleWork.unkAA++;
}

void change_effect_anim(void) {
    if (gGameWork.unk86 == 0x5A) {
        gBattleWork.unkAA++;
    } else {
        gGameWork.unk86++;
        process_sprite_anim_commands(gUnk_083B5F80[0x4B], 0x21);
        process_sprite_anim_commands(gUnk_083B5F80[0x4C], 0x22);
    }
}

// Swaps the acting part for a random one of the ability's family (unk119: 0 Change, 1 ItrpChange,
// 2 AttkChange, 3 DEF Change, 4 HealChange); the original part is kept in unk11C (unk118 = 1) and restored
// after the action.
void change_transform_part(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x4B], 0x21);
    process_sprite_anim_commands(gUnk_083B5F80[0x4C], 0x22);
    gBattleWork.unk118 = 1;
    gBattleWork.unk119 = gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1] - 0x37;
    gBattleWork.unk11A = pick_random_change_part(gBattleWork.unk119, gBattleWork.unkA7);
    memcpy_bytes_0803F63C(&gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7], &gBattleWork.unk11C, 0x18);
    load_part_data(gBattleWork.unk11A, gBattleWork.unkA7, &gGameWork.unkEE);
    gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[0] = (&gGameWork.unkEE)[0];
    gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1] = (&gGameWork.unkEE)[1];
    gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[5] = (&gGameWork.unkEE)[5];
    gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[6] = (&gGameWork.unkEE)[6];
    gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[7] = (&gGameWork.unkEE)[7];
    gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[0xC] = (&gGameWork.unkEE)[0xC];
    gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[2] = 7;
    gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].unk17 = gBattleWork.unk11A;
    ai_pick_bot_targets(gBattleWork.unk87);
    battle_bot_select_part(gBattleWork.unk87, gBattleWork.unkA7 + 1);
    load_all_bot_part_sprites();
    iterate_bots_setup_battle_sprites();
    gBattleWork.unkAA++;
}

// Copies the old and the new part names into the message buffer for the change message (unkA6 0x2F).
void change_finish(void) {
    clear_battle_sprite_slot(0x21, 2);
    memcpy_bytes_08041D04((const void *)gUnk_083BB9CC[0][gBattleWork.unk11C.unk17 * 4 + gBattleWork.unkA7],
                          gGameWork.unk9E, 0xF);
    memcpy_bytes_08041D04((const void *)gUnk_083BB9CC[0][gBattleWork.unk11A * 4 + gBattleWork.unkA7],
                          gGameWork.unk9E + 0x14, 0xF);
    gBattleWork.unkA6 = 0x2F;
    gBattleWork.unkAA++;
}
