// Effect sequences of the Support abilities: action script opcodes 0x30-0x35.
// Each runner (*_run: clears unkB5 and calls entry [unkAA] of its step table) is one action script command
// (gActionScriptCommands, opcode order = ROM order); its step handlers follow it and the last step sets unkB5.
// Abilities are part data[1], and the script of ability n is gActionScripts[n]:
//   0x30 Scout (36), 0x31 Conceal (37), 0x32 Boost Chrg (38), 0x33 Rapid Chrg (39), 0x34 Drain Chrg (41),
//   0x35 Pushover (42; guess, see pushover_run). Ability 40 (Accel Chrg) has an empty script: it works
//   while equipped. Skill names from the parts that carry them (re/tables/parts.json) and a public FAQ.
// The *_begin step of each sequence ends the action on a battle time-out (unkA6 0x1A); otherwise it skips
// the time-out steps 1-3 and starts the effect at step 4. A target with a working Stability part shrugs off
// the Charge effects (unkA6 0x39, battle_bot_lacks_stability).

#include "global.h"

void scout_run(void) {
    gBattleWork.unkB5 = 0;
    gScoutSteps[gBattleWork.unkAA]();
}

void scout_begin(void) {
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

void scout_load_graphics(void) {
    lz_decompress_dispatch(gUnk_084D5D78, (void *)0x06014800);
    CpuFastSet(gUnk_0850E778, (void *)0x050002C0, 0x10);
    gBattleWork.unkAA++;
}

void scout_darken_init(void) {
    palette_backup_from_hardware();
    gGameWork.unk84 = 0;
    gBattleWork.unkAA++;
}

void scout_darken(void) {
    bg_palettes_blend_masked_now(0x1084, gGameWork.unk84, 0xFFFF);
    obj_palettes_blend_masked_now(0x1084, gGameWork.unk84, 0xFF00);
    if (gGameWork.unk84 == 0x10)
        gBattleWork.unkAA++;
    else
        gGameWork.unk84++;
}

void scout_beam_spawn(void) {
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gBattleWork.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gBattleWork.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk6 = 0x4800;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk2D = 0;
    play_sound_effect(0x4C);
    gBattleWork.unkAA++;
}

void scout_beam_spin(void) {
    if (gSpriteEntries[0x21].unk2D == 0x40) {
        clear_battle_sprite_slot(0x21, 2);
        gBattleWork.unkAA++;
    } else {
        gSpriteEntries[0x21].unk2D++;
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x10) & 0x3FF;
    }
}

void scout_brighten(void) {
    bg_palettes_blend_masked_now(0x1084, gGameWork.unk84, 0xFFFF);
    obj_palettes_blend_masked_now(0x1084, gGameWork.unk84, 0xFF00);
    if (gGameWork.unk84 == 0)
        gBattleWork.unkAA++;
    else
        gGameWork.unk84--;
}

void scout_arrows_spawn(void) {
    u32 i;
    u32 first = battle_side_first_record(gBattleWork.unk87);

    for (i = 0; i < 3; i++) {
        if (gBattleBots[first + i].unk40) {
            gSpriteEntries[0x21 + i].unk0 = 0xC624;
            gSpriteEntries[0x21 + i].unk1C = 0;
            gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[(first + i) * 4 + 0x5D].unk2;
            gSpriteEntries[0x21 + i].unk4 = gSpriteEntries[(first + i) * 4 + 0x5D].unk4;
            gSpriteEntries[0x21 + i].unkA = 7;
            gSpriteEntries[0x21 + i].unkB = 0xF0;
            gSpriteEntries[0x21 + i].unk8 = 0x40;
            gSpriteEntries[0x21 + i].unk9 = 0x40;
            gSpriteEntries[0x21 + i].unk6 = 0x4801;
        }
    }
    gGameWork.unk86 = 0;
    play_sound_effect(0x2E);
    gBattleWork.unkAA++;
}

void scout_arrows_rise(void) {
    u32 i;

    if (gGameWork.unk86 == 0x14) {
        gGameWork.unk86 = 0x3C;
        gBattleWork.unkAA++;
    } else {
        gGameWork.unk86++;
        for (i = 0; i < 3; i++) {
            if (gSpriteEntries[0x21 + i].unk0 & 0x8000)
                gSpriteEntries[0x21 + i].unk4--;
        }
    }
}

void scout_arrows_shrink(void) {
    u32 i;

    for (i = 0; i < 3; i++) {
        if (gSpriteEntries[0x21 + i].unk0 & 0x8000) {
            gSpriteEntries[0x21 + i].unk8 -= 8;
            gSpriteEntries[0x21 + i].unk9 += 8;
        }
    }
    if (gSpriteEntries[0x21].unk8 == 8) {
        clear_battle_sprite_slot(0x21, 3);
        gBattleWork.unkAA++;
    }
}

// Raises the side bonus unk28[side].unk0 by unkEC (up to 0xA0): Scout raises Power and success for the team.
void scout_apply_bonus(void) {
    add_u8_capped(&gBattleWork.unk28[gBattleWork.unk89].unk0, gBattleWork.unkEC, 0xA0);
    gBattleWork.unkAA++;
}

void scout_finish(void) {
    gBattleWork.unkA6 = 0x1C;
    gBattleWork.unkAA++;
}

void conceal_run(void) {
    gBattleWork.unkB5 = 0;
    gConcealSteps[gBattleWork.unkAA]();
}

void conceal_begin(void) {
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

void conceal_dome_spawn(void) {
    lz_decompress_dispatch(gUnk_084D5EBC, (void *)0x06014800);
    CpuFastSet(gUnk_0850E7B8, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC404;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gBattleWork.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gBattleWork.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x40], 0x21);
    play_sound_effect(0x4D);
    gBattleWork.unkAA++;
}

void conceal_dome_open_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x40], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        gGameWork.unk86 = 0x3C;
        gBattleWork.unkAA++;
    }
}

void conceal_dome_close_init(void) {
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x41], 0x21);
    play_sound_effect(0x4D);
    gGameWork.unk84 = 0;
    gBattleWork.unkAA++;
}

void conceal_dome_close(void) {
    gGameWork.unk84++;
    battle_bot_sprites_blink(gBattleWork.unk87, gGameWork.unk84, 2);
    process_sprite_anim_commands(gUnk_083B5F80[0x41], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gGameWork.unk86 = 0x3C;
        gBattleWork.unkAA++;
    }
}

void conceal_blink_wait(void) {
    gGameWork.unk84++;
    battle_bot_sprites_blink(gBattleWork.unk87, gGameWork.unk84, 2);
    if (gGameWork.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1)) {
        battle_bot_sprites_show(gBattleWork.unk87);
        gBattleWork.unkAA++;
    } else if (gGameWork.unk86)
        gGameWork.unk86--;
    else {
        battle_bot_sprites_show(gBattleWork.unk87);
        gBattleWork.unkAA++;
    }
}

// Raises the user's unkB9 by unkEC (up to 0x78): Conceal raises evasion.
void conceal_apply_evasion(void) {
    add_u8_capped(&gBattleBots[gBattleWork.unk87].unkB8 + 1, gBattleWork.unkEC, 0x78);
    gBattleWork.unkAA++;
}

void conceal_finish(void) {
    gBattleWork.unkA6 = 0x1D;
    gBattleWork.unkAA++;
}

void boost_charge_run(void) {
    gBattleWork.unkB5 = 0;
    gBoostChargeSteps[gBattleWork.unkAA]();
}

void boost_charge_begin(void) {
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

void boost_charge_hourglass_spawn(void) {
    lz_decompress_dispatch(gUnk_084D6098, (void *)0x06014800);
    CpuFastSet(gUnk_0850E7D8, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 |= 0x220;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    gGameWork.unk84 = 0x42;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x42], 0x21);
    gGameWork.unk86 = 0x3C;
    gBattleWork.unkAA++;
}

void charge_hourglass_hold(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gGameWork.unk84], 0x21);
    if (gGameWork.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gBattleWork.unkAA++;
    else if (gGameWork.unk86)
        gGameWork.unk86--;
    else
        gBattleWork.unkAA++;
}

void charge_hourglass_fly(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gGameWork.unk84], 0x21);
    if (!(gBattleWork.unkF8 & 1))
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 - 0x40) & 0x3FF;
    else
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x40) & 0x3FF;
    if (move_sprite_toward_target(0x21)) {
        gSpriteEntries[0x21].unk18 = 0;
        gBattleWork.unkAA++;
    }
}

void boost_charge_hourglass_burst(void) {
    gGameWork.unk84 = 0x43;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x43], 0x21);
    play_sound_effect(0x4E);
    gBattleWork.unkAA++;
}

void charge_hourglass_anim_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gGameWork.unk84], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF)
        gBattleWork.unkAA++;
}

void charge_hourglass_shrink(void) {
    if (gSpriteEntries[0x21].unk8 == 8) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 8;
        gSpriteEntries[0x21].unk9 += 8;
    }
}

// Puts the Time status (effect A 0x26) on the target: faster CRG/RAD.
void boost_charge_apply(void) {
    gBattleBots[gBattleWork.unk88].unkC4 = 0x26;
    gBattleBots[gBattleWork.unk88].unkC5 = 0;
    gBattleBots[gBattleWork.unk88].unkC6 = clamp_1_99(gBattleWork.unkE8);
    gBattleBots[gBattleWork.unk88].unkC7 = clamp_1_99(gBattleWork.unkEC);
    gBattleWork.unkAA++;
}

void boost_charge_finish(void) {
    gBattleWork.unkA6 = 0x2C;
    gBattleWork.unkAA++;
}

void rapid_charge_run(void) {
    gBattleWork.unkB5 = 0;
    gRapidChargeSteps[gBattleWork.unkAA]();
}

void rapid_charge_begin(void) {
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

void rapid_charge_hourglass_spawn(void) {
    lz_decompress_dispatch(gUnk_084D61DC, (void *)0x06014800);
    CpuFastSet(gUnk_0850E7F8, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 |= 0x220;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    gGameWork.unk84 = 0x45;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gGameWork.unk84], 0x21);
    gGameWork.unk86 = 0x3C;
    gBattleWork.unkAA++;
}

void rapid_charge_hourglass_burst(void) {
    gGameWork.unk84 = 0x46;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x46], 0x21);
    play_sound_effect(0x4E);
    gBattleWork.unkAA++;
}

// guess: unkBF makes the target run straight to the center / its side (action_queue.c).
void rapid_charge_apply(void) {
    gBattleBots[gBattleWork.unk88].unkBF = 1;
    gBattleWork.unkAA++;
}

void rapid_charge_finish(void) {
    gBattleWork.unkA6 = 0x2B;
    gBattleWork.unkAA++;
}

void drain_charge_run(void) {
    gBattleWork.unkB5 = 0;
    gDrainChargeSteps[gBattleWork.unkAA]();
}

void drain_charge_begin(void) {
    calc_battle_action_speed(gBattleWork.unk87, gBattleWork.unkA7);
    apply_battle_bot_damage_reduction(gBattleWork.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.unkA6 = 0x1A;
        gBattleWork.unkAA++;
    } else if (battle_bot_lacks_stability(gBattleWork.unk88) == 0) {
        gBattleWork.unkA6 = 0x39;
        gBattleWork.unkAA++;
    } else if (battle_bot_lacks_stability(gBattleWork.unk87) == 0) {
        gBattleWork.unkA6 = 0x39;
        gBattleWork.unkAA++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.unk87, gBattleWork.unkA7);
        gBattleWork.unkAA = 4;
    }
}

void drain_charge_hourglass_spawn(void) {
    lz_decompress_dispatch(gUnk_084D6320, (void *)0x06014800);
    CpuFastSet(gUnk_0850E818, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 |= 0x220;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    gGameWork.unk84 = 0x42;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gGameWork.unk84], 0x21);
    gGameWork.unk86 = 0x3C;
    gBattleWork.unkAA++;
}

void drain_charge_hourglass_drain(void) {
    gGameWork.unk84 = 0x44;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x44], 0x21);
    play_sound_effect(0x4E);
    gBattleWork.unkAA++;
}

void drain_charge_hourglass_shrink(void) {
    if (gSpriteEntries[0x21].unk8 == 8) {
        clear_sprite_table_mask(0x21, 1);
        gBattleWork.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 8;
        gSpriteEntries[0x21].unk9 -= 8;
    }
}

void drain_charge_hourglass_return(void) {
    lz_decompress_dispatch(gUnk_084D6098, (void *)0x06014800);
    CpuFastSet(gUnk_0850E7D8, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 |= 0x8000;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gBattleWork.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gBattleWork.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    gGameWork.unk84 = 0x42;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gGameWork.unk84], 0x21);
    gGameWork.unk86 = 0x3C;
    gBattleWork.unkAA++;
}

void drain_charge_hourglass_grow(void) {
    if (gSpriteEntries[0x21].unk8 == 0x40)
        gBattleWork.unkAA++;
    else {
        gSpriteEntries[0x21].unk8 += 8;
        gSpriteEntries[0x21].unk9 += 8;
    }
}

void drain_charge_hourglass_burst(void) {
    gGameWork.unk84 = 0x43;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x43], 0x21);
    play_sound_effect(0x4E);
    gBattleWork.unkAA++;
}

// Effect B 0x29 on the target (Bind: slower CRG/RAD) and effect A 0x29 on the user (Time).
void drain_charge_apply(void) {
    gBattleBots[gBattleWork.unk88].unkC9 = 0x29;
    gBattleBots[gBattleWork.unk88].unkCA = 0;
    gBattleBots[gBattleWork.unk88].unkCB = clamp_1_99(gBattleWork.unkE8);
    gBattleBots[gBattleWork.unk88].unkCC = clamp_1_99(gBattleWork.unkEC);
    gBattleBots[gBattleWork.unk87].unkC4 = 0x29;
    gBattleBots[gBattleWork.unk87].unkC5 = 0;
    gBattleBots[gBattleWork.unk87].unkC6 = clamp_1_99(gBattleWork.unkE8);
    gBattleBots[gBattleWork.unk87].unkC7 = clamp_1_99(gBattleWork.unkEC);
    gBattleWork.unkAA++;
}

void drain_charge_finish(void) {
    gBattleWork.unkA6 = 0x2D;
    gBattleWork.unkAA++;
}

// guess: Pushover (ability 42, the Majoram head): a thrown object spins onto the target, the target hops
// and falls over, its head takes unkEC damage (1 if unkBD bit 2 is set) and the script goes on with
// opcode 0x21. The guide describes Pushover as "throws a banana, very little damage, erases orders".
void pushover_run(void) {
    gBattleWork.unkB5 = 0;
    gPushoverSteps[gBattleWork.unkAA]();
}

void pushover_begin(void) {
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

void pushover_banana_spawn(void) {
    lz_decompress_dispatch(gUnk_084D6464, (void *)0x06014800);
    CpuFastSet(gUnk_0850E838, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 |= 0x220;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk6 = 0x4D00;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    if (gBattleWork.unkF8 & 1)
        gSpriteEntries[0x21].unk0 |= 0x1000;
    gGameWork.unk86 = 0x3C;
    gBattleWork.unkAA++;
}

void pushover_banana_fly(void) {
    if (move_sprite_toward_target(0x21))
        gBattleWork.unkAA++;
}

void pushover_target_hop_init(void) {
    gSpriteEntries[0x21].unk23 = 0;
    memcpy_bytes_0803F63C(&gSpriteEntries[gBattleWork.unk88 * 4 + 0x5A], &gSpriteEntries[0x22], 0x40);
    memcpy_bytes_0803F63C(&gSpriteEntries[gBattleWork.unk88 * 4 + 0x5B], &gSpriteEntries[0x23], 0x40);
    memcpy_bytes_0803F63C(&gSpriteEntries[gBattleWork.unk88 * 4 + 0x5C], &gSpriteEntries[0x24], 0x40);
    memcpy_bytes_0803F63C(&gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D], &gSpriteEntries[0x25], 0x40);
    clear_sprite_table_mask(0x22, 4);
    gSpriteEntries[gBattleWork.unk88 * 4 + 0x5A].unk23 = 0;
    gSpriteEntries[gBattleWork.unk88 * 4 + 0x5B].unk23 = 0;
    gSpriteEntries[gBattleWork.unk88 * 4 + 0x5C].unk23 = 0;
    gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk23 = 0;
    sprite_enable_affine_unit_scale(gBattleWork.unk88 + 0x72);
    play_sound_effect(0x34);
    gBattleWork.unkAA++;
}

void pushover_target_hop(void) {
    u32 r;

    if (gSpriteEntries[0x21].unk0 & 0x8000) {
        if (advance_sprite_anim_frame(0x21, 0))
            clear_battle_sprite_slot(0x21, 1);
        else if (!(gBattleWork.unkF8 & 1)) {
            gSpriteEntries[0x21].unk2--;
            gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 - 0x10) & 0x3FF;
        } else {
            gSpriteEntries[0x21].unk2++;
            gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x10) & 0x3FF;
        }
    }
    sprite_hop_step(gBattleWork.unk88 * 4 + 0x5A);
    sprite_hop_step(gBattleWork.unk88 * 4 + 0x5B);
    sprite_hop_step(gBattleWork.unk88 * 4 + 0x5C);
    r = sprite_hop_step(gBattleWork.unk88 * 4 + 0x5D);
    if (gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk23 == 0x10) {
        gSpriteEntries[gBattleWork.unk88 * 4 + 0x5A].unk4 += 8;
        gSpriteEntries[gBattleWork.unk88 * 4 + 0x5B].unk4 -= 8;
        gSpriteEntries[gBattleWork.unk88 * 4 + 0x5C].unk4 -= 8;
        gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk4 -= 8;
        gSpriteEntries[gBattleWork.unk88 * 4 + 0x5A].unk0 |= 0x2000;
        gSpriteEntries[gBattleWork.unk88 * 4 + 0x5B].unk0 |= 0x2000;
        gSpriteEntries[gBattleWork.unk88 * 4 + 0x5C].unk0 |= 0x2000;
        gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk0 |= 0x2000;
    }
    check_sprite_overlap_and_adjust(gBattleWork.unk88 * 4 + 0x5D, gBattleWork.unk88 + 0x72);
    if (r) {
        sprite_disable_affine(gBattleWork.unk88 + 0x72);
        play_sound_effect(0x41);
        gBattleWork.unkAA++;
    }
}

void pushover_burst_spawn(void) {
    u32 i;

    for (i = 0; i < 4; i++) {
        gSpriteEntries[0x26 + i].unk0 = 0xC404;
        gSpriteEntries[0x26 + i].unk1C = 0;
        gSpriteEntries[0x26 + i].unk2 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5A].unk2;
        gSpriteEntries[0x26 + i].unk4 = gSpriteEntries[gBattleWork.unk88 * 4 + 0x5A].unk4 + 4;
        gSpriteEntries[0x26 + i].unkA = 7;
        gSpriteEntries[0x26 + i].unkB = 0xF0;
        gSpriteEntries[0x26 + i].unk24 = 6;
        gSpriteEntries[0x26 + i].unk25 = gBurstSpriteDirections[i];
        gSpriteEntries[0x26 + i].unk6 = 0x4D01;
    }
    gGameWork.unk84 = 0;
    gBattleWork.unkAA++;
}

void pushover_burst(void) {
    u32 i;

    for (i = 0; i < 4; i++)
        update_sprite_animation_position(0x26 + i);
    if (gGameWork.unk84 == 0x10) {
        clear_battle_sprite_slot(0x26, 4);
        memcpy_bytes_0803F63C(&gSpriteEntries[0x22], &gSpriteEntries[gBattleWork.unk88 * 4 + 0x5A], 0x40);
        memcpy_bytes_0803F63C(&gSpriteEntries[0x23], &gSpriteEntries[gBattleWork.unk88 * 4 + 0x5B], 0x40);
        memcpy_bytes_0803F63C(&gSpriteEntries[0x24], &gSpriteEntries[gBattleWork.unk88 * 4 + 0x5C], 0x40);
        memcpy_bytes_0803F63C(&gSpriteEntries[0x25], &gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D], 0x40);
        gSpriteEntries[gBattleWork.unk88 * 4 + 0x5A].unk0 |= 0x8000;
        gSpriteEntries[gBattleWork.unk88 * 4 + 0x5B].unk0 |= 0x8000;
        gSpriteEntries[gBattleWork.unk88 * 4 + 0x5C].unk0 |= 0x8000;
        gSpriteEntries[gBattleWork.unk88 * 4 + 0x5D].unk0 |= 0x8000;
        clear_battle_sprite_slot(0x21, 4);
        gBattleWork.unkAA++;
    } else
        gGameWork.unk84++;
}

void pushover_damage_init(void) {
    if (gBattleBots[gBattleWork.unk88].unkBD & 4)
        battle_set_damage_vs_armor(gBattleWork.unk88, 0, 1);
    else
        battle_set_damage_vs_armor(gBattleWork.unk88, 0, gBattleWork.unkEC);
    set_display_digit_type(&gGameWork.unkEE, gBattleWork.unkC8, 1);
    battle_number_popup_init_slot(&gGameWork.unkEE, gBattleWork.unk88, 0x21);
    play_sound_effect(0x5B);
    gGameWork.unk84 = 0;
    gBattleWork.unkAA++;
}

void pushover_damage_popup(void) {
    battle_popup_update_slot(&gGameWork.unkEE, gBattleWork.unk88, 0x21);
    if (++gGameWork.unk84, gGameWork.unk89 == 0 && (KEYS_LO(gRepeatKeys) & 1) && gGameWork.unk84 > 0x32)
        gGameWork.unk84 = 0x78;
    if (gGameWork.unk84 == 0x78) {
        clear_battle_sprite_slot(gBattleWork.unk88 * 4 + 0x21, 4);
        gBattleWork.unkAA++;
    }
}

void pushover_apply_head_damage(void) {
    u8 armor;

    reduce_bot_part_stat(gBattleWork.unk88, 0, gBattleWork.unkC8);
    armor = gBattleBots[gBattleWork.unk88].parts[0].unk11;
    if (armor == 0) {
        add_bot_to_defeated_list(gBattleWork.unk88);
        gBattleWork.unkD0 = armor;
        gBattleWork.unkAA = 0x1A;
    } else
        gBattleWork.unkAA = 0x13;
}

// guess: unkBD bit 2 set -> step 0x14, which leads to pushover_flag_target (unkBD bit 0).
void pushover_check_target_flag(void) {
    if (gBattleBots[gBattleWork.unk88].unkBD & 4)
        gBattleWork.unkAA++;
    else
        gBattleWork.unkAA = 0x15;
}

void pushover_flag_target(void) {
    gBattleBots[gBattleWork.unk88].unkBD |= 1;
    gBattleWork.unkAA++;
}

void pushover_finish(void) {
    gBattleWork.unkA6 = 0x2E;
    gBattleWork.unkAA++;
}

void pushover_part_destroyed_cursor(void) {
    lz_decompress_dispatch(gUnk_084CDBD8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E378, (void *)0x050002E0, 8);
    staggered_sprites_spawn(0x21, gSpriteEntries[0x5A + gBattleWork.unk88 * 4 + gBattleWork.unkD0].unk2,
                            gSpriteEntries[0x5A + gBattleWork.unk88 * 4 + gBattleWork.unkD0].unk4, 4);
    gBattleWork.unkAA++;
}

void pushover_part_destroyed_cursor_wait(void) {
    if (staggered_sprites_update(0x21, 4))
        gBattleWork.unkAA++;
}

void pushover_part_explode_spawn(void) {
    lz_decompress_dispatch(gUnk_084CC9A8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E338, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC004;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[0x5A + gBattleWork.unk88 * 4 + gBattleWork.unkD0].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[0x5A + gBattleWork.unk88 * 4 + gBattleWork.unkD0].unk4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x22], 0x21);
    gBattleWork.unkAA++;
}

void pushover_part_explode(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x22], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        load_bot_part_sprite(gBattleWork.unk88);
        gBattleWork.unkAA++;
    }
}
