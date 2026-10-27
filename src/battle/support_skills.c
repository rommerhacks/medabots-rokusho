// Effect sequences of the Support abilities: action script opcodes 0x30-0x35.
// Each runner (*_run: clears unkB5 and calls entry [unkAA] of its step table) is one action script command
// (gUnk_083AF000, opcode order = ROM order); its step handlers follow it and the last step sets unkB5.
// Abilities are part data[1], and the script of ability n is gUnk_083C6B28[n]:
//   0x30 Scout (36), 0x31 Conceal (37), 0x32 Boost Chrg (38), 0x33 Rapid Chrg (39), 0x34 Drain Chrg (41),
//   0x35 Pushover (42; guess, see pushover_run). Ability 40 (Accel Chrg) has an empty script: it works
//   while equipped. Skill names from the parts that carry them (re/tables/parts.json) and a public FAQ.
// The *_begin step of each sequence ends the action on a battle time-out (unkA6 0x1A); otherwise it skips
// the time-out steps 1-3 and starts the effect at step 4. A target with a working Stability part shrugs off
// the Charge effects (unkA6 0x39, battle_bot_lacks_stability).

#include "global.h"

void scout_run(void) {
    gUnk_03001800.unkB5 = 0;
    gScoutSteps[gUnk_03001800.unkAA]();
}

void scout_begin(void) {
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void scout_load_graphics(void) {
    lz_decompress_dispatch(gUnk_084D5D78, (void *)0x06014800);
    CpuFastSet(gUnk_0850E778, (void *)0x050002C0, 0x10);
    gUnk_03001800.unkAA++;
}

void scout_darken_init(void) {
    palette_backup_from_hardware();
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void scout_darken(void) {
    bg_palettes_blend_masked_now(0x1084, gUnk_03000440.unk84, 0xFFFF);
    obj_palettes_blend_masked_now(0x1084, gUnk_03000440.unk84, 0xFF00);
    if (gUnk_03000440.unk84 == 0x10)
        gUnk_03001800.unkAA++;
    else
        gUnk_03000440.unk84++;
}

void scout_beam_spawn(void) {
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk6 = 0x4800;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk2D = 0;
    play_sound_effect(0x4C);
    gUnk_03001800.unkAA++;
}

void scout_beam_spin(void) {
    if (gSpriteEntries[0x21].unk2D == 0x40) {
        clear_battle_sprite_slot(0x21, 2);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk2D++;
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x10) & 0x3FF;
    }
}

void scout_brighten(void) {
    bg_palettes_blend_masked_now(0x1084, gUnk_03000440.unk84, 0xFFFF);
    obj_palettes_blend_masked_now(0x1084, gUnk_03000440.unk84, 0xFF00);
    if (gUnk_03000440.unk84 == 0)
        gUnk_03001800.unkAA++;
    else
        gUnk_03000440.unk84--;
}

void scout_arrows_spawn(void) {
    u32 i;
    u32 first = battle_side_first_record(gUnk_03001800.unk87);

    for (i = 0; i < 3; i++) {
        if (gUnk_03000590[first + i].unk40) {
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
    gUnk_03000440.unk86 = 0;
    play_sound_effect(0x2E);
    gUnk_03001800.unkAA++;
}

void scout_arrows_rise(void) {
    u32 i;

    if (gUnk_03000440.unk86 == 0x14) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    } else {
        gUnk_03000440.unk86++;
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
        gUnk_03001800.unkAA++;
    }
}

// Raises the side bonus unk28[side].unk0 by unkEC (up to 0xA0): Scout raises Power and success for the team.
void scout_apply_bonus(void) {
    add_u8_capped(&gUnk_03001800.unk28[gUnk_03001800.unk89].unk0, gUnk_03001800.unkEC, 0xA0);
    gUnk_03001800.unkAA++;
}

void scout_finish(void) {
    gUnk_03001800.unkA6 = 0x1C;
    gUnk_03001800.unkAA++;
}

void conceal_run(void) {
    gUnk_03001800.unkB5 = 0;
    gConcealSteps[gUnk_03001800.unkAA]();
}

void conceal_begin(void) {
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void conceal_dome_spawn(void) {
    lz_decompress_dispatch(gUnk_084D5EBC, (void *)0x06014800);
    CpuFastSet(gUnk_0850E7B8, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC404;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x40], 0x21);
    play_sound_effect(0x4D);
    gUnk_03001800.unkAA++;
}

void conceal_dome_open_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x40], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void conceal_dome_close_init(void) {
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x41], 0x21);
    play_sound_effect(0x4D);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void conceal_dome_close(void) {
    gUnk_03000440.unk84++;
    battle_bot_sprites_blink(gUnk_03001800.unk87, gUnk_03000440.unk84, 2);
    process_sprite_anim_commands(gUnk_083B5F80[0x41], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void conceal_blink_wait(void) {
    gUnk_03000440.unk84++;
    battle_bot_sprites_blink(gUnk_03001800.unk87, gUnk_03000440.unk84, 2);
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1)) {
        battle_bot_sprites_show(gUnk_03001800.unk87);
        gUnk_03001800.unkAA++;
    } else if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else {
        battle_bot_sprites_show(gUnk_03001800.unk87);
        gUnk_03001800.unkAA++;
    }
}

// Raises the user's unkB9 by unkEC (up to 0x78): Conceal raises evasion.
void conceal_apply_evasion(void) {
    add_u8_capped(&gUnk_03000590[gUnk_03001800.unk87].unkB8 + 1, gUnk_03001800.unkEC, 0x78);
    gUnk_03001800.unkAA++;
}

void conceal_finish(void) {
    gUnk_03001800.unkA6 = 0x1D;
    gUnk_03001800.unkAA++;
}

void boost_charge_run(void) {
    gUnk_03001800.unkB5 = 0;
    gBoostChargeSteps[gUnk_03001800.unkAA]();
}

void boost_charge_begin(void) {
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    } else if (battle_bot_lacks_stability(gUnk_03001800.unk88) == 0) {
        gUnk_03001800.unkA6 = 0x39;
        gUnk_03001800.unkAA++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void boost_charge_hourglass_spawn(void) {
    lz_decompress_dispatch(gUnk_084D6098, (void *)0x06014800);
    CpuFastSet(gUnk_0850E7D8, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 |= 0x220;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    gUnk_03000440.unk84 = 0x42;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x42], 0x21);
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void charge_hourglass_hold(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03000440.unk84], 0x21);
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03001800.unkAA++;
    else if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else
        gUnk_03001800.unkAA++;
}

void charge_hourglass_fly(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03000440.unk84], 0x21);
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 - 0x40) & 0x3FF;
    else
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x40) & 0x3FF;
    if (move_sprite_toward_target(0x21)) {
        gSpriteEntries[0x21].unk18 = 0;
        gUnk_03001800.unkAA++;
    }
}

void boost_charge_hourglass_burst(void) {
    gUnk_03000440.unk84 = 0x43;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x43], 0x21);
    play_sound_effect(0x4E);
    gUnk_03001800.unkAA++;
}

void charge_hourglass_anim_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03000440.unk84], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF)
        gUnk_03001800.unkAA++;
}

void charge_hourglass_shrink(void) {
    if (gSpriteEntries[0x21].unk8 == 8) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 8;
        gSpriteEntries[0x21].unk9 += 8;
    }
}

// Puts the Time status (effect A 0x26) on the target: faster CRG/RAD.
void boost_charge_apply(void) {
    gUnk_03000590[gUnk_03001800.unk88].unkC4 = 0x26;
    gUnk_03000590[gUnk_03001800.unk88].unkC5 = 0;
    gUnk_03000590[gUnk_03001800.unk88].unkC6 = clamp_1_99(gUnk_03001800.unkE8);
    gUnk_03000590[gUnk_03001800.unk88].unkC7 = clamp_1_99(gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void boost_charge_finish(void) {
    gUnk_03001800.unkA6 = 0x2C;
    gUnk_03001800.unkAA++;
}

void rapid_charge_run(void) {
    gUnk_03001800.unkB5 = 0;
    gRapidChargeSteps[gUnk_03001800.unkAA]();
}

void rapid_charge_begin(void) {
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void rapid_charge_hourglass_spawn(void) {
    lz_decompress_dispatch(gUnk_084D61DC, (void *)0x06014800);
    CpuFastSet(gUnk_0850E7F8, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 |= 0x220;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    gUnk_03000440.unk84 = 0x45;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03000440.unk84], 0x21);
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void rapid_charge_hourglass_burst(void) {
    gUnk_03000440.unk84 = 0x46;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x46], 0x21);
    play_sound_effect(0x4E);
    gUnk_03001800.unkAA++;
}

// guess: unkBF makes the target run straight to the center / its side (action_queue.c).
void rapid_charge_apply(void) {
    gUnk_03000590[gUnk_03001800.unk88].unkBF = 1;
    gUnk_03001800.unkAA++;
}

void rapid_charge_finish(void) {
    gUnk_03001800.unkA6 = 0x2B;
    gUnk_03001800.unkAA++;
}

void drain_charge_run(void) {
    gUnk_03001800.unkB5 = 0;
    gDrainChargeSteps[gUnk_03001800.unkAA]();
}

void drain_charge_begin(void) {
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    } else if (battle_bot_lacks_stability(gUnk_03001800.unk88) == 0) {
        gUnk_03001800.unkA6 = 0x39;
        gUnk_03001800.unkAA++;
    } else if (battle_bot_lacks_stability(gUnk_03001800.unk87) == 0) {
        gUnk_03001800.unkA6 = 0x39;
        gUnk_03001800.unkAA++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void drain_charge_hourglass_spawn(void) {
    lz_decompress_dispatch(gUnk_084D6320, (void *)0x06014800);
    CpuFastSet(gUnk_0850E818, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 |= 0x220;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    gUnk_03000440.unk84 = 0x42;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03000440.unk84], 0x21);
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void drain_charge_hourglass_drain(void) {
    gUnk_03000440.unk84 = 0x44;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x44], 0x21);
    play_sound_effect(0x4E);
    gUnk_03001800.unkAA++;
}

void drain_charge_hourglass_shrink(void) {
    if (gSpriteEntries[0x21].unk8 == 8) {
        clear_sprite_table_mask(0x21, 1);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 8;
        gSpriteEntries[0x21].unk9 -= 8;
    }
}

void drain_charge_hourglass_return(void) {
    lz_decompress_dispatch(gUnk_084D6098, (void *)0x06014800);
    CpuFastSet(gUnk_0850E7D8, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 |= 0x8000;
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    gUnk_03000440.unk84 = 0x42;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03000440.unk84], 0x21);
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void drain_charge_hourglass_grow(void) {
    if (gSpriteEntries[0x21].unk8 == 0x40)
        gUnk_03001800.unkAA++;
    else {
        gSpriteEntries[0x21].unk8 += 8;
        gSpriteEntries[0x21].unk9 += 8;
    }
}

void drain_charge_hourglass_burst(void) {
    gUnk_03000440.unk84 = 0x43;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x43], 0x21);
    play_sound_effect(0x4E);
    gUnk_03001800.unkAA++;
}

// Effect B 0x29 on the target (Bind: slower CRG/RAD) and effect A 0x29 on the user (Time).
void drain_charge_apply(void) {
    gUnk_03000590[gUnk_03001800.unk88].unkC9 = 0x29;
    gUnk_03000590[gUnk_03001800.unk88].unkCA = 0;
    gUnk_03000590[gUnk_03001800.unk88].unkCB = clamp_1_99(gUnk_03001800.unkE8);
    gUnk_03000590[gUnk_03001800.unk88].unkCC = clamp_1_99(gUnk_03001800.unkEC);
    gUnk_03000590[gUnk_03001800.unk87].unkC4 = 0x29;
    gUnk_03000590[gUnk_03001800.unk87].unkC5 = 0;
    gUnk_03000590[gUnk_03001800.unk87].unkC6 = clamp_1_99(gUnk_03001800.unkE8);
    gUnk_03000590[gUnk_03001800.unk87].unkC7 = clamp_1_99(gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void drain_charge_finish(void) {
    gUnk_03001800.unkA6 = 0x2D;
    gUnk_03001800.unkAA++;
}

// guess: Pushover (ability 42, the Majoram head): a thrown object spins onto the target, the target hops
// and falls over, its head takes unkEC damage (1 if unkBD bit 2 is set) and the script goes on with
// opcode 0x21. The guide describes Pushover as "throws a banana, very little damage, erases orders".
void pushover_run(void) {
    gUnk_03001800.unkB5 = 0;
    gPushoverSteps[gUnk_03001800.unkAA]();
}

void pushover_begin(void) {
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
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
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 6;
    if (gUnk_03001800.unkF8 & 1)
        gSpriteEntries[0x21].unk0 |= 0x1000;
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void pushover_banana_fly(void) {
    if (move_sprite_toward_target(0x21))
        gUnk_03001800.unkAA++;
}

void pushover_target_hop_init(void) {
    gSpriteEntries[0x21].unk23 = 0;
    memcpy_bytes_0803F63C(&gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5A], &gSpriteEntries[0x22], 0x40);
    memcpy_bytes_0803F63C(&gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5B], &gSpriteEntries[0x23], 0x40);
    memcpy_bytes_0803F63C(&gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5C], &gSpriteEntries[0x24], 0x40);
    memcpy_bytes_0803F63C(&gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D], &gSpriteEntries[0x25], 0x40);
    clear_sprite_table_mask(0x22, 4);
    gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5A].unk23 = 0;
    gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5B].unk23 = 0;
    gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5C].unk23 = 0;
    gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk23 = 0;
    sub_08035694(gUnk_03001800.unk88 + 0x72);
    play_sound_effect(0x34);
    gUnk_03001800.unkAA++;
}

void pushover_target_hop(void) {
    u32 r;

    if (gSpriteEntries[0x21].unk0 & 0x8000) {
        if (advance_sprite_anim_frame(0x21, 0))
            clear_battle_sprite_slot(0x21, 1);
        else if (!(gUnk_03001800.unkF8 & 1)) {
            gSpriteEntries[0x21].unk2--;
            gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 - 0x10) & 0x3FF;
        } else {
            gSpriteEntries[0x21].unk2++;
            gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x10) & 0x3FF;
        }
    }
    sprite_hop_step(gUnk_03001800.unk88 * 4 + 0x5A);
    sprite_hop_step(gUnk_03001800.unk88 * 4 + 0x5B);
    sprite_hop_step(gUnk_03001800.unk88 * 4 + 0x5C);
    r = sprite_hop_step(gUnk_03001800.unk88 * 4 + 0x5D);
    if (gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk23 == 0x10) {
        gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5A].unk4 += 8;
        gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5B].unk4 -= 8;
        gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5C].unk4 -= 8;
        gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk4 -= 8;
        gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5A].unk0 |= 0x2000;
        gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5B].unk0 |= 0x2000;
        gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5C].unk0 |= 0x2000;
        gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk0 |= 0x2000;
    }
    check_sprite_overlap_and_adjust(gUnk_03001800.unk88 * 4 + 0x5D, gUnk_03001800.unk88 + 0x72);
    if (r) {
        sub_080356B4(gUnk_03001800.unk88 + 0x72);
        play_sound_effect(0x41);
        gUnk_03001800.unkAA++;
    }
}

void pushover_burst_spawn(void) {
    u32 i;

    for (i = 0; i < 4; i++) {
        gSpriteEntries[0x26 + i].unk0 = 0xC404;
        gSpriteEntries[0x26 + i].unk1C = 0;
        gSpriteEntries[0x26 + i].unk2 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5A].unk2;
        gSpriteEntries[0x26 + i].unk4 = gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5A].unk4 + 4;
        gSpriteEntries[0x26 + i].unkA = 7;
        gSpriteEntries[0x26 + i].unkB = 0xF0;
        gSpriteEntries[0x26 + i].unk24 = 6;
        gSpriteEntries[0x26 + i].unk25 = gBurstSpriteDirections[i];
        gSpriteEntries[0x26 + i].unk6 = 0x4D01;
    }
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void pushover_burst(void) {
    u32 i;

    for (i = 0; i < 4; i++)
        update_sprite_animation_position(0x26 + i);
    if (gUnk_03000440.unk84 == 0x10) {
        clear_battle_sprite_slot(0x26, 4);
        memcpy_bytes_0803F63C(&gSpriteEntries[0x22], &gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5A], 0x40);
        memcpy_bytes_0803F63C(&gSpriteEntries[0x23], &gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5B], 0x40);
        memcpy_bytes_0803F63C(&gSpriteEntries[0x24], &gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5C], 0x40);
        memcpy_bytes_0803F63C(&gSpriteEntries[0x25], &gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D], 0x40);
        gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5A].unk0 |= 0x8000;
        gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5B].unk0 |= 0x8000;
        gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5C].unk0 |= 0x8000;
        gSpriteEntries[gUnk_03001800.unk88 * 4 + 0x5D].unk0 |= 0x8000;
        clear_battle_sprite_slot(0x21, 4);
        gUnk_03001800.unkAA++;
    } else
        gUnk_03000440.unk84++;
}

void pushover_damage_init(void) {
    if (gUnk_03000590[gUnk_03001800.unk88].unkBD & 4)
        battle_set_damage_vs_armor(gUnk_03001800.unk88, 0, 1);
    else
        battle_set_damage_vs_armor(gUnk_03001800.unk88, 0, gUnk_03001800.unkEC);
    set_display_digit_type(&gUnk_03000440.unkEE, gUnk_03001800.unkC8, 1);
    battle_number_popup_init_slot(&gUnk_03000440.unkEE, gUnk_03001800.unk88, 0x21);
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void pushover_damage_popup(void) {
    battle_popup_update_slot(&gUnk_03000440.unkEE, gUnk_03001800.unk88, 0x21);
    if (++gUnk_03000440.unk84, gUnk_03000440.unk89 == 0 && (KEYS_LO(gRepeatKeys) & 1) && gUnk_03000440.unk84 > 0x32)
        gUnk_03000440.unk84 = 0x78;
    if (gUnk_03000440.unk84 == 0x78) {
        clear_battle_sprite_slot(gUnk_03001800.unk88 * 4 + 0x21, 4);
        gUnk_03001800.unkAA++;
    }
}

void pushover_apply_head_damage(void) {
    u8 armor;

    reduce_bot_part_stat(gUnk_03001800.unk88, 0, gUnk_03001800.unkC8);
    armor = gUnk_03000590[gUnk_03001800.unk88].parts[0].unk11;
    if (armor == 0) {
        add_bot_to_defeated_list(gUnk_03001800.unk88);
        gUnk_03001800.unkD0 = armor;
        gUnk_03001800.unkAA = 0x1A;
    } else
        gUnk_03001800.unkAA = 0x13;
}

// guess: unkBD bit 2 set -> step 0x14, which leads to pushover_flag_target (unkBD bit 0).
void pushover_check_target_flag(void) {
    if (gUnk_03000590[gUnk_03001800.unk88].unkBD & 4)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA = 0x15;
}

void pushover_flag_target(void) {
    gUnk_03000590[gUnk_03001800.unk88].unkBD |= 1;
    gUnk_03001800.unkAA++;
}

void pushover_finish(void) {
    gUnk_03001800.unkA6 = 0x2E;
    gUnk_03001800.unkAA++;
}

void pushover_part_destroyed_cursor(void) {
    lz_decompress_dispatch(gUnk_084CDBD8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E378, (void *)0x050002E0, 8);
    staggered_sprites_spawn(0x21, gSpriteEntries[0x5A + gUnk_03001800.unk88 * 4 + gUnk_03001800.unkD0].unk2,
                            gSpriteEntries[0x5A + gUnk_03001800.unk88 * 4 + gUnk_03001800.unkD0].unk4, 4);
    gUnk_03001800.unkAA++;
}

void pushover_part_destroyed_cursor_wait(void) {
    if (staggered_sprites_update(0x21, 4))
        gUnk_03001800.unkAA++;
}

void pushover_part_explode_spawn(void) {
    lz_decompress_dispatch(gUnk_084CC9A8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E338, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC004;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[0x5A + gUnk_03001800.unk88 * 4 + gUnk_03001800.unkD0].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[0x5A + gUnk_03001800.unk88 * 4 + gUnk_03001800.unkD0].unk4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x22], 0x21);
    gUnk_03001800.unkAA++;
}

void pushover_part_explode(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x22], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        load_bot_part_sprite(gUnk_03001800.unk88);
        gUnk_03001800.unkAA++;
    }
}
