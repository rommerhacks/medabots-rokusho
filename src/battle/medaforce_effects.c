// Medaforce effect sequences: action script opcodes 0x40-0x6A. A Medaforce runs script 0x50 + its id
// (unkF9 = unkA8[0] + 0x50, script_op_skill_anim_start), so scripts 80-131 use these; 0x45 (side_add_action_point) and
// a few script-side commands sit elsewhere. Each runner (medaforce_*_run, clears unkB5 and calls entry [unkAA] of its
// gMedaforce*Steps table) is one action script command (gActionScriptCommands, opcode order = ROM order); its step
// handlers follow it and the last step sets unkB5. Runner names come from the Medaforce names (gMedaforceNames) of
// the scripts that use each opcode. Abilities are part data[1], and the script of ability n is gActionScripts[n].

#include "global.h"

// Opcode 0x40: Spiral Bolt (Medaforce 0), damage to all four parts of the target.
void medaforce_spiral_bolt_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceSpiralBoltSteps[gUnk_03001800.unkAA]();
}

void medaforce_spiral_bolt_calc(void) {
    medaforce_calc_success(gUnk_03001800.unk87);
    medaforce_calc_damage(gUnk_03001800.unk87);
    gUnk_03001800.unkAA++;
}

void medaforce_spiral_bolt_set_damage(void) {
    hit_list_set_part_damage(gUnk_03001800.unk88, 0, gUnk_03001800.unkEC);
    hit_list_set_part_damage(gUnk_03001800.unk88, 1, gUnk_03001800.unkEC);
    hit_list_set_part_damage(gUnk_03001800.unk88, 2, gUnk_03001800.unkEC);
    hit_list_set_part_damage(gUnk_03001800.unk88, 3, gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void medaforce_spiral_bolt_digits_spawn(void) {
    s16 x, y;

    lz_decompress_dispatch(gUnk_084D1824, (void *)0x06010000);
    CpuFastSet(gUnk_0850E018, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    set_display_digit_type(gUnk_03000440.unk9E, gUnk_03001800.unkD6[0], 1);
    setup_battle_sprite_oam_entries(gUnk_03000440.unk9E, 0xA, 0, x, y);
    set_display_digit_type(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkD6[1], 1);
    setup_battle_sprite_oam_entries(gUnk_03000440.unk9E + 0x14, 0xE, 1, x, y);
    set_display_digit_type(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unkD6[2], 1);
    setup_battle_sprite_oam_entries(gUnk_03000440.unk9E + 0x28, 0x12, 2, x, y);
    set_display_digit_type(gUnk_03000440.unk9E + 0x3C, gUnk_03001800.unkD6[3], 1);
    setup_battle_sprite_oam_entries(gUnk_03000440.unk9E + 0x3C, 0x16, 3, x, y);
    play_sound_effect(0x5B);
    gUnk_03001800.unkAA++;
}

void medaforce_spiral_bolt_digits_rise(void) {
    sprite_group_rise_step(gUnk_03000440.unk9E, 0xA);
    sprite_group_rise_step(gUnk_03000440.unk9E + 0x14, 0xE);
    sprite_group_rise_step(gUnk_03000440.unk9E + 0x28, 0x12);
    if (sprite_group_rise_step(gUnk_03000440.unk9E + 0x3C, 0x16)) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void medaforce_spiral_bolt_drain_armor(void) {
    s32 n;
    u32 side;

    n = armor_drain_step(&gUnk_03001800.unkD6[0], gUnk_03001800.unk88, 0);
    n += armor_drain_step(&gUnk_03001800.unkD6[1], gUnk_03001800.unk88, 1);
    n += armor_drain_step(&gUnk_03001800.unkD6[2], gUnk_03001800.unk88, 2);
    n += armor_drain_step(&gUnk_03001800.unkD6[3], gUnk_03001800.unk88, 3);
    if (!(gUnk_03001800.unkF8 & 2))
        side = 1;
    else
        side = 0;
    armor_panel_draw_bars(side, gUnk_03001800.unk88);
    armor_panel_draw_numbers(side, gUnk_03001800.unk88);
    if (n == 4) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void medaforce_spiral_bolt_break_burst_spawn(void) {
    u16 x, y;
    s32 shown = 0;

    lz_decompress_dispatch(gUnk_084CCE48, (void *)0x06010800);
    CpuFastSet(gUnk_0850E358, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    if (gUnk_03001800.unkD2[0]) {
        effect_sprite_spawn_at_part(0xA, 0, x, y, 0x1E);
        shown = 1;
    }
    if (gUnk_03001800.unkD2[1]) {
        effect_sprite_spawn_at_part(0xB, 1, x, y, 0x1E);
        shown = 1;
    }
    if (gUnk_03001800.unkD2[2]) {
        effect_sprite_spawn_at_part(0xC, 2, x, y, 0x1E);
        shown = 1;
    }
    if (gUnk_03001800.unkD2[3]) {
        effect_sprite_spawn_at_part(0xD, 3, x, y, 0x1E);
        shown = 1;
    }
    if (shown) {
        bot_halve_broken_leg_stats(gUnk_03001800.unk88);
        gUnk_03001800.unkAA = 0xD;
    } else {
        gUnk_03001800.unkAA++;
    }
}

void medaforce_spiral_bolt_break_burst_wait(void) {
    s32 done = 0;

    if (gUnk_03001800.unkD2[0]) {
        process_sprite_anim_commands(gUnk_083B5F80[0x1E], 0xA);
        if (gSpriteEntries[0xA].unk22 == 0xFF)
            done = 1;
    }
    if (gUnk_03001800.unkD2[1]) {
        process_sprite_anim_commands(gUnk_083B5F80[0x1E], 0xB);
        if (gSpriteEntries[0xB].unk22 == 0xFF)
            done = 1;
    }
    if (gUnk_03001800.unkD2[2]) {
        process_sprite_anim_commands(gUnk_083B5F80[0x1E], 0xC);
        if (gSpriteEntries[0xC].unk22 == 0xFF)
            done = 1;
    }
    if (gUnk_03001800.unkD2[3]) {
        process_sprite_anim_commands(gUnk_083B5F80[0x1E], 0xD);
        if (gSpriteEntries[0xD].unk22 == 0xFF)
            done = 1;
    }
    if (done) {
        clear_battle_sprite_slot(0xA, 4);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_spiral_bolt_check_defeated(void) {
    if (gUnk_03000590[gUnk_03001800.unk88].parts[0].unk11 == 0)
        add_bot_to_defeated_list(gUnk_03001800.unk88);
    gUnk_03001800.unkAA++;
}

// Opcode 0x44: the shared Medaforce hit on one part (Ultra Shot, Damage Ball, Life Drain, Shrapnel Attack,
// Unbreakable Will, Structureless, Dice Attack, Type Crash).
void medaforce_hit_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceHitSteps[gUnk_03001800.unkAA]();
}

void medaforce_hit_check_nullified(void) {
    if (gUnk_03001800.unkB8 & 2)
        gUnk_03001800.unkAA = 0x20;
    else
        gUnk_03001800.unkAA++;
}

void medaforce_hit_carry_over_retarget(void) {
    if (gUnk_03001800.unkCA) {
        battle_pick_random_target_part(gUnk_03001800.unk87);
        battle_load_action_target(gUnk_03001800.unk87);
        gUnk_03001800.unkD0 = gUnk_03001800.unk8B;
        battle_set_damage_vs_armor(gUnk_03001800.unk88, gUnk_03001800.unk8B, gUnk_03001800.unkCA);
        gUnk_03001800.unkAA += 3;
    } else {
        gUnk_03001800.unkAA++;
    }
}

void medaforce_part_marker_spawn(void) {
    lz_decompress_dispatch(gUnk_084CA61C, (void *)0x06010000);
    CpuFastSet(gUnk_0850E198, (void *)0x050003C0, 8);
    gSpriteEntries[0xA].unk6 = 0x1500;
    play_sound_effect(0x2A);
    gSpriteEntries[0xA].unk0 = 0xC404;
    gSpriteEntries[0xA].unk1C = 0;
    gSpriteEntries[0xA].unkA = 0xE;
    gSpriteEntries[0xA].unkB = 0x80;
    gSpriteEntries[0xA].unk23 = 0;
    if (!(gUnk_03001800.unkF8 & 2)) {
        if (gUnk_03001800.unk8B == 2)
            gSpriteEntries[0xA].unk2 = gUnk_03001800.unk158 - 0x10;
        else
            gSpriteEntries[0xA].unk2 = gUnk_03001800.unk158;
        gSpriteEntries[0xA].unk4 = gUnk_03001800.unk15A;
    } else {
        if (gUnk_03001800.unk8B == 1)
            gSpriteEntries[0xA].unk2 = gUnk_03001800.unk154 + 0x10;
        else
            gSpriteEntries[0xA].unk2 = gUnk_03001800.unk154;
        gSpriteEntries[0xA].unk4 = gUnk_03001800.unk156;
    }
    gUnk_03001800.unkAA++;
}

void medaforce_hit_goto_sparks(void) {
    gUnk_03001800.unkAA = 2;
}

// Opcode 0x48: Life Drain (Medaforce 0x14) heals the actor's most damaged part.
void medaforce_life_drain_heal_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceLifeDrainHealSteps[gUnk_03001800.unkAA]();
}

void medaforce_life_drain_heal_find_part(void) {
    u32 r = find_most_damaged_part(gUnk_03001800.unk87);
    if (r) {
        gUnk_03001800.unk8B = gUnk_03001800.unkD0 = r - 1;
        gUnk_03001800.unkAA = 2;
    } else {
        gUnk_03001800.unkAA++;
    }
}

void medaforce_life_drain_heal_calc(void) {
    clear_battle_sprite_slot(0, 0x80);
    battle_calc_damage_split(gUnk_03001800.unk87, gUnk_03001800.unkD0, gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void medaforce_life_drain_heal_carry_over(void) {
    u32 r;
    struct Unk_03001800 *g = &gUnk_03001800;
    if (g->unkCA && (r = find_most_damaged_part(g->unk88))) {
        r--;
        g->unkD0 = r;
        g->unk8B = r;
        battle_calc_damage_split(g->unk87, g->unkD0, g->unkCA);
        g->unkAA = 0x10;
    } else {
        g->unkAA++;
    }
}

void medaforce_life_drain_heal_goto_sparkle(void) {
    gUnk_03001800.unkAA = 4;
}

// Opcode 0x50: Side Bolt (Medaforce 1), damage to all three opponents.
void medaforce_side_bolt_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceSideBoltSteps[gUnk_03001800.unkAA]();
}

void medaforce_side_bolt_calc(void) {
    u32 i;
    struct Unk_03000590 *bots;
    for (i = 0; i <= 2; i++) {
        gUnk_03001800.unkD2[i] = 0;
        gUnk_03001800.unkD6[i] = 0;
    }
    gUnk_03001800.unk60 = battle_enemy_side_first_record(gUnk_03001800.unk87);
    i = 0;
    bots = gUnk_03000590;
    for (; i <= 2; i++) {
        u32 rec = gUnk_03001800.unk60 + i;
        if (bots[rec].unk40 && bots[rec].parts[0].unk11) {
            gUnk_03001800.unkD2[i] = get_random_battle_weight_entry(rec);
            battle_set_damage_vs_armor(gUnk_03001800.unk60 + i, gUnk_03001800.unkD2[i], gUnk_03001800.unkEC);
            gUnk_03001800.unkD2[i] |= gUnk_03001800.unkD1 << 7;
            gUnk_03001800.unkD6[i] = gUnk_03001800.unkC8;
        }
    }
    gUnk_03001800.unkAA++;
}

// guess: sprite meaning unsure; two big scaled sprites (0x21/0x22) at screen centre

void medaforce_side_bolt_halves_spawn(void) {
    lz_decompress_dispatch(gUnk_084DB788, (void *)0x06014800);
    CpuFastSet(gUnk_0850EB38, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC624;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = 0x78;
    gSpriteEntries[0x21].unk4 = 0x30;
    gSpriteEntries[0x21].unk8 = 0x80;
    gSpriteEntries[0x21].unk9 = 0x80;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk6 = 0x6500;
    gSpriteEntries[0x22].unk0 = 0x4624;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = 0x78;
    gSpriteEntries[0x22].unk4 = 0x50;
    gSpriteEntries[0x22].unk8 = 0x80;
    gSpriteEntries[0x22].unk9 = 0x80;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = 0xF0;
    gSpriteEntries[0x22].unk6 = 0x6501;
    gUnk_03001800.unkAA++;
}

// guess: sprite meaning unsure; scale 0x80->0x40 one after the other, sfx 0x30

void medaforce_side_bolt_halves_shrink(void) {
    if (gSpriteEntries[0x21].unk8 != 0x40) {
        gSpriteEntries[0x21].unk8 -= 8;
        gSpriteEntries[0x21].unk9 -= 8;
        if (gSpriteEntries[0x21].unk8 == 0x40)
            play_sound_effect(0x30);
    } else {
        gSpriteEntries[0x22].unk0 |= 0x8000;
        if (gSpriteEntries[0x22].unk8 != 0x40) {
            gSpriteEntries[0x22].unk8 -= 8;
            gSpriteEntries[0x22].unk9 -= 8;
            if (gSpriteEntries[0x22].unk8 == 0x40)
                play_sound_effect(0x30);
        } else {
            gUnk_03000440.unk86 = 0x3C;
            gUnk_03001800.unkAA++;
        }
    }
}

void medaforce_side_bolt_bolt_spawn(void) {
    clear_battle_sprite_slot(0x21, 2);
    gSpriteEntries[0x21].unk0 = 0xC404;
    if (gUnk_03001800.unkF8 & 2)
        gSpriteEntries[0x21].unk0 |= 0x1000;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = 0x78;
    gSpriteEntries[0x21].unk4 = 0x40;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x5A], 0x21);
    gUnk_03001800.unkAA++;
}

void medaforce_side_bolt_bolt_anim_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x5A], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        gUnk_03000440.unk86 = 0;
        play_sound_effect(0x73);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_side_bolt_slide(void) {
    gUnk_03000440.unk86++;
    particle_slide_lead_sprite();
    if (gUnk_03000440.unk86 == 0x10) {
        palette_backup_from_hardware();
        gUnk_03000440.unk84 = 0;
        gUnk_03001800.unkAA++;
    }
}

void medaforce_side_bolt_flash_in(void) {
    gUnk_03000440.unk86++;
    particle_slide_lead_sprite();
    if (gUnk_03000440.unk84 <= 4) {
        bg_palettes_blend_masked_now(0x7FFF, gUnk_03000440.unk84 * 8, 0xFFFF);
        obj_palettes_blend_masked_now(0x7FFF, gUnk_03000440.unk84 * 8, 0xFFFF);
        gUnk_03000440.unk84++;
    } else {
        gUnk_03000440.unk84 = 0;
        gUnk_03001800.unkAA++;
    }
}

void medaforce_side_bolt_flash_out(void) {
    gUnk_03000440.unk86++;
    particle_slide_lead_sprite();
    if (gUnk_03000440.unk84 <= 8) {
        bg_palettes_blend_masked_now(0x7FFF, 0x20 - gUnk_03000440.unk84 * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0x7FFF, 0x20 - gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else {
        gUnk_03001800.unkAA++;
    }
}

void medaforce_side_bolt_slide_end(void) {
    gUnk_03000440.unk86++;
    particle_slide_lead_sprite();
    if (gUnk_03000440.unk86 > 0x23) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_side_bolt_set_message(void) {
    gUnk_03001800.unkA6 = 0x3A;
    gUnk_03001800.unkAA++;
}

void medaforce_side_bolt_apply_damage(void) {
    u32 i;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11) {
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[gUnk_03001800.unkD2[i] & 0x7F].unk11 -= gUnk_03001800.unkD6[i];
            bot_halve_broken_leg_stats(gUnk_03001800.unk60 + i);
            if ((gUnk_03001800.unkD2[i] & 0x7F) == 0 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
                add_bot_to_defeated_list(gUnk_03001800.unk60 + i);
        }
    }
    gUnk_03001800.unkAA++;
}

void medaforce_team_damage_popup_init(void) {
    u32 i;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40) {
            switch (i) {
            case 0:
                set_display_digit_type(gUnk_03000440.unk9E, gUnk_03001800.unkD6[i], 1);
                battle_number_popup_init_slot(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
                break;
            case 1:
                set_display_digit_type(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkD6[1], 1);
                battle_number_popup_init_slot(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
                break;
            case 2:
                set_display_digit_type(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unkD6[2], 1);
                battle_number_popup_init_slot(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
                break;
            }
        }
    }
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void medaforce_team_popup_wait(void) {
    u32 i;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40) {
            switch (i) {
            case 0:
                battle_popup_update_slot(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
                break;
            case 1:
                battle_popup_update_slot(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
                break;
            case 2:
                battle_popup_update_slot(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
                break;
            }
        }
    }
    gUnk_03000440.unk84++;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1) && gUnk_03000440.unk84 > 0x32)
        gUnk_03000440.unk84 = 0x78;
    if (gUnk_03000440.unk84 == 0x78) {
        clear_battle_sprite_slot(gUnk_03001800.unk60 * 4 + 0x21, 0xC);
        gUnk_03001800.unkAA++;
    }
}

void decompress_sprite_tiles_to_vram_obj_4800_alt(void) {
    u32 done = 0;
    u32 i;

    lz_decompress_dispatch(gUnk_084CDBD8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E378, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] & 0x80) {
            staggered_sprites_spawn(
                i * 4 + 0x21,
                gSpriteEntries[0x5A + (gUnk_03001800.unk60 + i) * 4 + (gUnk_03001800.unkD2[i] & 0x7F)].unk2,
                gSpriteEntries[0x5A + (gUnk_03001800.unk60 + i) * 4 + (gUnk_03001800.unkD2[i] & 0x7F)].unk4, 4);
            done = 1;
        }
    }
    if (!done)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 3;
}

void medaforce_team_break_burst_wait(void) {
    u32 r = 0;
    u32 i;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] & 0x80)
            r = staggered_sprites_update(i * 4 + 0x21, 4);
    }
    if (r)
        gUnk_03001800.unkAA++;
}

void medaforce_team_break_anim_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084CC9A8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E338, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] & 0x80) {
            gSpriteEntries[i + 0x21].unk0 = 0xC004;
            gSpriteEntries[i + 0x21].unk1C = 0;
            gSpriteEntries[i + 0x21].unk2 =
                gSpriteEntries[0x5A + (gUnk_03001800.unk60 + i) * 4 + (gUnk_03001800.unkD2[i] & 0x7F)].unk2;
            gSpriteEntries[i + 0x21].unk4 =
                gSpriteEntries[0x5A + (gUnk_03001800.unk60 + i) * 4 + (gUnk_03001800.unkD2[i] & 0x7F)].unk4;
            gSpriteEntries[i + 0x21].unkA = 7;
            gSpriteEntries[i + 0x21].unkB = 0xF0;
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x22], i + 0x21);
        }
    }
    gUnk_03001800.unkAA++;
}

void medaforce_team_break_anim_wait(void) {
    u32 done = 0;
    u32 i;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] & 0x80) {
            u8 slot;
            process_sprite_anim_commands(gUnk_083B5F80[0x22], slot = i + 0x21);
            if (gSpriteEntries[i + 0x21].unk22 == 0xFF) {
                clear_battle_sprite_slot(slot, 1);
                done = 1;
            }
        }
    }
    if (done) {
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
        gUnk_03001800.unkAA++;
    }
}

// Opcode 0x51: Optic / Bomb / Gravity Form and Absorb Optic / Bomb / Gravity (Medaforces 4-9).
void medaforce_form_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceFormSteps[gUnk_03001800.unkAA]();
}

void medaforce_form_begin(void) {
    switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0]) {
    case 4:
        gUnk_03001800.unk51 = 0;
        break;
    case 5:
        gUnk_03001800.unk51 = 1;
        break;
    case 6:
        gUnk_03001800.unk51 = 2;
        break;
    case 7:
        gUnk_03001800.unk51 = 3;
        break;
    case 8:
        gUnk_03001800.unk51 = 4;
        break;
    default:
        gUnk_03001800.unk51 = 5;
        break;
    }
    gUnk_03001800.unkAA++;
}

void medaforce_form_emblem_spawn(void) {
    lz_decompress_dispatch(gUnk_084DBB28, (void *)0x06014800);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0]) {
    case 4:
    case 5:
        lz_decompress_dispatch(gUnk_084DBCAC, (void *)0x06014C00);
        CpuFastSet(gUnk_0850EB58, (void *)0x050002E0, 8);
        play_sound_effect(0x27);
        break;
    case 6:
    case 7:
        lz_decompress_dispatch(gUnk_084DBD0C, (void *)0x06014C00);
        CpuFastSet(gUnk_0850EB78, (void *)0x050002E0, 8);
        play_sound_effect(0x45);
        break;
    case 8:
    default:
        lz_decompress_dispatch(gUnk_084DBD60, (void *)0x06014C00);
        CpuFastSet(gUnk_0850EB98, (void *)0x050002E0, 8);
        play_sound_effect(0x33);
        break;
    }
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[0x5D + gUnk_03001800.unk87 * 4].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[0x5D + gUnk_03001800.unk87 * 4].unk4 - 4;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unkB = 0xF0;
    if (gUnk_03001800.unk51 & 1)
        gSpriteEntries[0x21].unk6 = 0x6601;
    else
        gSpriteEntries[0x21].unk6 = 0x6600;
    gUnk_03000440.unk86 = 0;
    gUnk_03001800.unkAA++;
}

void medaforce_form_emblem_spin(void) {
    gUnk_03000440.unk86++;
    gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x40) & 0x3FF;
    if (gUnk_03000440.unk86 > 0x3C)
        gUnk_03001800.unkAA++;
}

void medaforce_form_ring_spawn(void) {
    gUnk_03000440.unk86++;
    gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x40) & 0x3FF;
    gSpriteEntries[0x22].unk0 = 0xC624;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = gSpriteEntries[0x5D + gUnk_03001800.unk87 * 4].unk2;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[0x5D + gUnk_03001800.unk87 * 4].unk4 - 4;
    gSpriteEntries[0x22].unk8 = 0x80;
    gSpriteEntries[0x22].unk9 = 0x80;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = 0xF1;
    gSpriteEntries[0x22].unk6 = 0x6700;
    gUnk_03001800.unkAA++;
}

void medaforce_form_ring_shrink(void) {
    gUnk_03000440.unk86++;
    gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x40) & 0x3FF;
    if (gSpriteEntries[0x22].unk8 == 0x40) {
        play_sound_effect(0x30);
        gUnk_03000440.unk84 = 0x3C;
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x22].unk8 -= 8;
        gSpriteEntries[0x22].unk9 -= 8;
    }
}

void medaforce_form_hold(void) {
    gUnk_03000440.unk86++;
    gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x40) & 0x3FF;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1)) {
        play_sound_effect(0x2B);
        gUnk_03001800.unkAA++;
    } else if (gUnk_03000440.unk84) {
        gUnk_03000440.unk84--;
    } else {
        play_sound_effect(0x2B);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_form_shrink_out(void) {
    gUnk_03000440.unk86++;
    gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x40) & 0x3FF;
    if (gSpriteEntries[0x21].unk8 == 4) {
        clear_battle_sprite_slot(0x21, 2);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 4;
        gSpriteEntries[0x21].unk9 -= 4;
        gSpriteEntries[0x22].unk8 -= 4;
        gSpriteEntries[0x22].unk9 -= 4;
    }
}

void medaforce_form_apply(void) {
    switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0]) {
    case 4:
        gUnk_03000590[gUnk_03001800.unk87].unkD6 |= 1;
        break;
    case 5:
        gUnk_03000590[gUnk_03001800.unk87].unkD6 |= 8;
        break;
    case 6:
        gUnk_03000590[gUnk_03001800.unk87].unkD6 |= 2;
        break;
    case 7:
        gUnk_03000590[gUnk_03001800.unk87].unkD6 |= 0x10;
        break;
    case 8:
        gUnk_03000590[gUnk_03001800.unk87].unkD6 |= 4;
        break;
    default:
        gUnk_03000590[gUnk_03001800.unk87].unkD6 |= 0x20;
        break;
    }
    gUnk_03001800.unkAA++;
}

void medaforce_form_set_message(void) {
    switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0]) {
    case 4:
        gUnk_03001800.unkA6 = 0x4A;
        break;
    case 5:
        gUnk_03001800.unkA6 = 0x61;
        break;
    case 6:
        gUnk_03001800.unkA6 = 0x4B;
        break;
    case 7:
        gUnk_03001800.unkA6 = 0x62;
        break;
    case 8:
        gUnk_03001800.unkA6 = 0x4C;
        break;
    default:
        gUnk_03001800.unkA6 = 0x63;
        break;
    }
    gUnk_03001800.unkAA++;
}

// Opcode 0x52: Anti Attk Trap (Medaforce 0xA).
void medaforce_anti_attack_trap_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceAntiAttackTrapSteps[gUnk_03001800.unkAA]();
}

void medaforce_anti_attack_trap_trap_spawn(void) {
    lz_decompress_dispatch(gUnk_084C978C, (void *)0x06014800);
    CpuFastSet(gUnk_0850E0B8, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 |= 0x220;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk8 = 8;
    gSpriteEntries[0x21].unk4 = 0x3C;
    gSpriteEntries[0x21].unk6 = 0xE00;
    if (gUnk_03001800.unkF8 & 1) {
        gSpriteEntries[0x21].unk0 |= 0x1000;
        gSpriteEntries[0x21].unk2--;
    }
    gUnk_03001800.unkAA++;
}

void medaforce_anti_attack_trap_trap_grow(void) {
    gSpriteEntries[0x21].unk8 += 8;
    if (gSpriteEntries[0x21].unk8 == 0x40) {
        gUnk_03000440.unk86 = 0x3C;
        gSpriteEntries[0x21].unk27 = 0;
        gUnk_03001800.unkAA++;
    }
}

void medaforce_anti_attack_trap_check_existing(void) {
    if (gUnk_03001800.unk28[gUnk_03001800.unk8A].active && gUnk_03001800.unk28[gUnk_03001800.unk8A].skill == 0x5A) {
        gSpriteEntries[0x21].unk27 = 0;
        gUnk_03001800.unkAA++;
    } else {
        play_sound_effect(0x3E);
        gUnk_03001800.unkAA += 2;
    }
}

void medaforce_anti_attack_trap_trap_pulse(void) {
    if (gSpriteEntries[0x21].unk27 == 0x10) {
        play_sound_effect(0x3E);
        gUnk_03001800.unkAA++;
        return;
    }
    if (gSpriteEntries[0x21].unk27 < 8)
        gSpriteEntries[0x21].unk8 += 8;
    else
        gSpriteEntries[0x21].unk8 -= 8;
    gSpriteEntries[0x21].unk27++;
}

void medaforce_anti_attack_trap_apply(void) {
    if (gUnk_03001800.unk28[gUnk_03001800.unk8A].active && gUnk_03001800.unk28[gUnk_03001800.unk8A].skill == 0x5A) {
        gUnk_03001800.unk53 = 1;
        add_u8_capped(&gUnk_03001800.unk28[gUnk_03001800.unk8A].durability, gUnk_03001800.unkE8 >> 1, 0xFF);
        add_u8_capped(&gUnk_03001800.unk28[gUnk_03001800.unk8A].power,
                      (gUnk_03001800.unkEC + gUnk_03000590[gUnk_03001800.unk87].unkD5) >> 1, 0xFF);
        gUnk_03001800.unkAA++;
    } else {
        gUnk_03001800.unk53 = 0;
        gUnk_03001800.unk28[gUnk_03001800.unk8A].active = 1;
        gUnk_03001800.unk28[gUnk_03001800.unk8A].skill = 0x5A;
        gUnk_03001800.unk28[gUnk_03001800.unk8A].durability = 0;
        gUnk_03001800.unk28[gUnk_03001800.unk8A].power = 0;
        add_u8_capped(&gUnk_03001800.unk28[gUnk_03001800.unk8A].durability, gUnk_03001800.unkE8, 0xFF);
        add_u8_capped(&gUnk_03001800.unk28[gUnk_03001800.unk8A].power,
                      gUnk_03001800.unkEC + gUnk_03000590[gUnk_03001800.unk87].unkD5, 0xFF);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_anti_attack_trap_set_message(void) {
    gUnk_03001800.unkA6 = 0x50;
    gUnk_03001800.unkAA++;
}

// Opcode 0x53: Cancel Formation (Medaforce 0xB).
void medaforce_cancel_formation_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceCancelFormationSteps[gUnk_03001800.unkAA]();
}

void medaforce_cancel_formation_load_graphics(void) {
    lz_decompress_dispatch(gUnk_084DBDC8, (void *)0x06014800);
    CpuFastSet(gUnk_0850EBB8, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk6 = 0x6A00;
    gSpriteEntries[0x21].unk4 += 4;
    gSpriteEntries[0x21].unk27 = 0;
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void medaforce_cancel_formation_slide(void) {
    if (gSpriteEntries[0x21].unk27 == 0x10) {
        play_sound_effect(0x28);
        gSpriteEntries[0x21].unk27 = 0;
        gUnk_03001800.unkAA++;
        return;
    }
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x21].unk2--;
    else
        gSpriteEntries[0x21].unk2++;
    gSpriteEntries[0x21].unk27++;
}

void medaforce_cancel_formation_blink(void) {
    gSpriteEntries[0x21].unk27++;
    if (gSpriteEntries[0x21].unk27 & 2)
        gSpriteEntries[0x21].unk0 |= 0x8000;
    else
        gSpriteEntries[0x21].unk0 &= 0x7FFF;
    if (gSpriteEntries[0x21].unk27 == 0x3C) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_cancel_formation_apply(void) {
    gUnk_03000590[gUnk_03001800.unk87].unkC0 |= 2;
    gUnk_03001800.unkAA++;
}

void medaforce_cancel_formation_set_message(void) {
    gUnk_03001800.unkA6 = 0x64;
    gUnk_03001800.unkAA++;
}

// Opcode 0x54: Movement / Stop / Bind / Flow (Medaforces 0xC, 0xE, 0x10, 0x12) and Chaos (0x28).
void medaforce_inflict_status_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceInflictStatusSteps[gUnk_03001800.unkAA]();
}

void medaforce_inflict_status_begin(void) {
    switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0]) {
    case 0xC:
        gUnk_03001800.unk51 = 0;
        break;
    case 0xE:
        gUnk_03001800.unk51 = 1;
        break;
    case 0x10:
        gUnk_03001800.unk51 = 2;
        break;
    case 0x12:
        gUnk_03001800.unk51 = 3;
        break;
    case 0x28:
        gUnk_03001800.unk51 = 4;
        break;
    }
    gUnk_03001800.unkAA++;
}

void medaforce_inflict_status_orb_spawn(void) {
    switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0]) {
    case 0xC:
        lz_decompress_dispatch(gUnk_084DBEE4, (void *)0x06014800);
        CpuFastSet(gUnk_0850EBD8, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk28 = 0;
        gSpriteEntries[0x21].unk2E = 0x5B;
        break;
    case 0xE:
        lz_decompress_dispatch(gUnk_084DC100, (void *)0x06014800);
        CpuFastSet(gUnk_0850EBF8, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk28 = 1;
        gSpriteEntries[0x21].unk2E = 0x5B;
        break;
    case 0x10:
        lz_decompress_dispatch(gUnk_084DC544, (void *)0x06014800);
        CpuFastSet(gUnk_0850EC18, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk28 = 2;
        gSpriteEntries[0x21].unk2E = 0x5B;
        break;
    case 0x12:
        lz_decompress_dispatch(gUnk_084DC7D0, (void *)0x06014800);
        CpuFastSet(gUnk_0850EC38, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk28 = 3;
        gSpriteEntries[0x21].unk2E = 0x5C;
        break;
    case 0x28:
        lz_decompress_dispatch(gUnk_084DD188, (void *)0x06014800);
        CpuFastSet(gUnk_0850EC78, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk28 = 4;
        gSpriteEntries[0x21].unk2E = 0x5B;
        break;
    }
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk4 = 0xE0;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk29 = 1;
    gSpriteEntries[0x21].unk2B = 0x20;
    gSpriteEntries[0x21].unk2C = 0xC0;
    gSpriteEntries[0x21].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[0x21].unk2E], 0x21);
    if (!(gUnk_03001800.unkF8 & 1)) {
        gSpriteEntries[0x21].unk2 = 0xB8;
    } else {
        gSpriteEntries[0x21].unk0 |= 0x1000;
        gSpriteEntries[0x21].unk2 = 0x38;
    }
    gUnk_03001800.unkAA++;
}

void medaforce_orb_orbit_wait(void) {
    if (particle_run_orbit_handlers())
        gUnk_03001800.unkAA++;
}

void medaforce_inflict_status_apply(void) {
    u32 i;

    medaforce_clear_hit_list();
    gUnk_03001800.unk60 = battle_enemy_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        if (battle_bot_lacks_stability(gUnk_03001800.unk60 + i) == 0)
            continue;
        switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0]) {
        case 0xC:
            if (bot_has_status_guard(gUnk_03001800.unk60 + i, 0xD) == 0) {
                gUnk_03001800.unkD2[i] = 1;
                battle_inflict_status(gUnk_03001800.unk60 + i, 0xD, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            }
            break;
        case 0xE:
            if (bot_has_status_guard(gUnk_03001800.unk60 + i, 0x10) == 0) {
                gUnk_03001800.unkD2[i] = 1;
                battle_inflict_status(gUnk_03001800.unk60 + i, 0x10, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            }
            break;
        case 0x10:
            if (bot_has_status_guard(gUnk_03001800.unk60 + i, 0x12) == 0) {
                gUnk_03001800.unkD2[i] = 1;
                battle_inflict_status(gUnk_03001800.unk60 + i, 0x12, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            }
            break;
        case 0x12:
            if (bot_has_status_guard(gUnk_03001800.unk60 + i, 0x13) == 0) {
                gUnk_03001800.unkD2[i] = 1;
                battle_inflict_status(gUnk_03001800.unk60 + i, 0x13, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            }
            break;
        case 0x28:
            gUnk_03001800.unkD2[i] = 1;
            battle_inflict_status(gUnk_03001800.unk60 + i, 0x2C, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            break;
        }
    }
    gUnk_03001800.unkAA++;
}

void medaforce_inflict_status_check_any(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            gUnk_03001800.unkAA += 2;
            return;
        }
    }
    gUnk_03001800.unkAA++;
}

void medaforce_inflict_status_icons_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084DCF54, (void *)0x06016000);
    CpuFastSet(gUnk_0850EC58, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk0 = 0xC404;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        gSpriteEntries[0x21 + i].unk23 = 0;
        switch (gUnk_03001800.unk51) {
        case 0:
            gSpriteEntries[0x21 + i].unk6 = 0x6F00;
            break;
        case 1:
            gSpriteEntries[0x21 + i].unk6 = 0x6F03;
            break;
        case 2:
            gSpriteEntries[0x21 + i].unk6 = 0x6F01;
            break;
        case 3:
            gSpriteEntries[0x21 + i].unk6 = 0x6F02;
            break;
        case 4:
            gSpriteEntries[0x21 + i].unk6 = 0x6F05;
            break;
        case 5:
            gSpriteEntries[0x21 + i].unk6 = 0x6F04;
            break;
        }
    }
    play_sound_effect(0x5B);
    gUnk_03001800.unkAA++;
}

void medaforce_team_icons_anim_wait(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] && advance_sprite_anim_frame(0x21 + i, 0))
            done = 1;
    }
    if (done) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void medaforce_inflict_status_set_message(void) {
    clear_battle_sprite_slot(0x21, 3);
    switch (gUnk_03001800.unk51) {
    case 0:
        gUnk_03001800.unkA6 = 0x46;
        break;
    case 1:
        gUnk_03001800.unkA6 = 0x49;
        break;
    case 2:
        gUnk_03001800.unkA6 = 0x47;
        break;
    case 3:
        gUnk_03001800.unkA6 = 0x48;
        break;
    case 4:
        gUnk_03001800.unkA6 = 0x5D;
        break;
    case 5:
        gUnk_03001800.unkA6 = 0x5E;
        break;
    }
    gUnk_03001800.unkAA++;
}

// Opcode 0x55: Cancel Movement / Stop / Bind / Flow (Medaforces 0xD, 0xF, 0x11, 0x13).
void medaforce_cancel_status_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceCancelStatusSteps[gUnk_03001800.unkAA]();
}

void medaforce_cancel_status_begin(void) {
    switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0]) {
    case 0xD:
        gUnk_03001800.unk51 = 0;
        break;
    case 0xF:
        gUnk_03001800.unk51 = 1;
        break;
    case 0x11:
        gUnk_03001800.unk51 = 2;
        break;
    case 0x13:
        gUnk_03001800.unk51 = 3;
        break;
    }
    gUnk_03001800.unkAA++;
}

void medaforce_cancel_status_emblem_spawn(void) {
    switch (gUnk_03001800.unk51) {
    case 0:
        lz_decompress_dispatch(gUnk_084DBEE4, (void *)0x06014800);
        CpuFastSet(gUnk_0850EBD8, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk2E = 0x5B;
        break;
    case 1:
        lz_decompress_dispatch(gUnk_084DC100, (void *)0x06014800);
        CpuFastSet(gUnk_0850EBF8, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk2E = 0x5B;
        break;
    case 2:
        lz_decompress_dispatch(gUnk_084DC544, (void *)0x06014800);
        CpuFastSet(gUnk_0850EC18, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk2E = 0x5B;
        break;
    case 3:
        lz_decompress_dispatch(gUnk_084DC7D0, (void *)0x06014800);
        CpuFastSet(gUnk_0850EC38, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk2E = 0x5C;
        break;
    }
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk4 = 0xE0;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[0x21].unk2E], 0x21);
    if (gUnk_03001800.unkF8 & 1) {
        gSpriteEntries[0x21].unk2 = 0xB8;
    } else {
        gSpriteEntries[0x21].unk0 |= 0x1000;
        gSpriteEntries[0x21].unk2 = 0x38;
    }
    play_sound_effect(0x61);
    gUnk_03001800.unkAA++;
}

void medaforce_cancel_status_emblem_rise(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[0x21].unk2E], 0x21);
    if (gSpriteEntries[0x21].unk4 == 0x40) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
        return;
    }
    gSpriteEntries[0x21].unk4 = (gSpriteEntries[0x21].unk4 + 2) & 0xFF;
    if (gUnk_03001800.unkF8 & 1) {
        if (gUnk_03001800.unk51 != 3)
            gSpriteEntries[gUnk_03000440.unk12F].unk18 = (gSpriteEntries[gUnk_03000440.unk12F].unk18 - 0x10) & 0x3FF;
    } else {
        if (gUnk_03001800.unk51 != 3)
            gSpriteEntries[gUnk_03000440.unk12F].unk18 = (gSpriteEntries[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
    }
}

void medaforce_cancel_status_emblem_hold(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[0x21].unk2E], 0x21);
    if (gUnk_03001800.unkF8 & 1) {
        if (gUnk_03001800.unk51 != 3)
            gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 - 0x10) & 0x3FF;
    } else {
        if (gUnk_03001800.unk51 != 3)
            gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x10) & 0x3FF;
    }
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03001800.unkAA++;
    else if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else
        gUnk_03001800.unkAA++;
}

void medaforce_cancel_status_shatter_spawn(void) {
    lz_decompress_dispatch(gUnk_084CCE48, (void *)0x06014800);
    CpuFastSet(gUnk_0850E358, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x23], 0x21);
    CpuSet(&gSpriteEntries[0x21], &gSpriteEntries[0x22], 0x20);
    CpuSet(&gSpriteEntries[0x21], &gSpriteEntries[0x23], 0x20);
    CpuSet(&gSpriteEntries[0x21], &gSpriteEntries[0x24], 0x20);
    CpuSet(&gSpriteEntries[0x21], &gSpriteEntries[0x25], 0x20);
    gSpriteEntries[0x21].unk24 = 0;
    gSpriteEntries[0x22].unk24 = 2;
    gSpriteEntries[0x22].unk25 = 0x1C;
    gSpriteEntries[0x22].unk2 -= 0x10;
    gSpriteEntries[0x22].unk4 -= 0x10;
    gSpriteEntries[0x23].unk24 = 2;
    gSpriteEntries[0x23].unk25 = 4;
    gSpriteEntries[0x23].unk2 += 0x10;
    gSpriteEntries[0x23].unk4 -= 0x10;
    gSpriteEntries[0x24].unk24 = 2;
    gSpriteEntries[0x24].unk25 = 0x14;
    gSpriteEntries[0x24].unk2 -= 0x10;
    gSpriteEntries[0x24].unk4 += 0x10;
    gSpriteEntries[0x25].unk24 = 2;
    gSpriteEntries[0x25].unk25 = 0xC;
    gSpriteEntries[0x25].unk2 += 0x10;
    gSpriteEntries[0x25].unk4 += 0x10;
    gUnk_03001800.unkAA++;
}

void medaforce_cancel_status_shatter_wait(void) {
    u32 i;

    for (i = 0; i <= 4; i++) {
        process_sprite_anim_commands(gUnk_083B5F80[0x23], 0x21 + i);
        update_sprite_animation_position(0x21 + i);
    }
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 5);
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void medaforce_cancel_status_sparkle_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084DD45C, (void *)0x06014800);
    CpuFastSet(gUnk_0850EC98, (void *)0x050002E0, 8);
    medaforce_clear_hit_list();
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        gUnk_03001800.unkD2[i] = 1;
        gSpriteEntries[0x21 + i].unk0 = 0xC404;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x5F], 0x21 + i);
    }
    gUnk_03001800.unkAA++;
}

void medaforce_cancel_status_sparkle_wait(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            process_sprite_anim_commands(gUnk_083B5F80[0x5F], 0x21 + i);
            if (gSpriteEntries[0x21 + i].unk22 == 0xFF)
                done = 1;
        }
    }
    if (done) {
        clear_battle_sprite_slot(0x21, 3);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_cancel_status_apply(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        switch (gUnk_03001800.unk51) {
        case 0:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCF |= 1;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 == 0xD)
                goto call_0xD;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 != 0xE)
                break;
        call_0xD:
            bot_clear_effects(gUnk_03001800.unk60 + i, 1);
            break;
        case 1:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCF |= 8;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 == 0xF)
                goto call_0xF;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 != 0x10)
                break;
        call_0xF:
            bot_clear_effects(gUnk_03001800.unk60 + i, 1);
            break;
        case 2:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCF |= 2;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 == 0x11)
                goto call_0x11;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 != 0x12)
                break;
        call_0x11:
            bot_clear_effects(gUnk_03001800.unk60 + i, 1);
            break;
        case 3:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCF |= 4;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 == 0x13)
                goto call_0x13;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 != 0x14)
                break;
        call_0x13:
            bot_clear_effects(gUnk_03001800.unk60 + i, 1);
            break;
        }
    }
    gUnk_03001800.unkAA++;
}

void medaforce_cancel_status_set_message(void) {
    switch (gUnk_03001800.unk51) {
    case 0:
        gUnk_03001800.unkA6 = 0x55;
        break;
    case 1:
        gUnk_03001800.unkA6 = 0x58;
        break;
    case 2:
        gUnk_03001800.unkA6 = 0x56;
        break;
    case 3:
        gUnk_03001800.unkA6 = 0x57;
        break;
    }
    gUnk_03001800.unkAA++;
}

// Opcode 0x56: Status Restore (Medaforce 0x15).
void medaforce_status_restore_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceStatusRestoreSteps[gUnk_03001800.unkAA]();
}

void medaforce_status_restore_orb_spawn(void) {
    lz_decompress_dispatch(gUnk_084DD648, (void *)0x06014800);
    CpuFastSet(gUnk_0850ECB8, (void *)0x050002E0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk4 = 0xE0;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk28 = 0;
    gSpriteEntries[0x21].unk2E = 0x5B;
    gSpriteEntries[0x21].unk29 = 6;
    gSpriteEntries[0x21].unk2B = 0x20;
    gSpriteEntries[0x21].unk2C = 0xC0;
    gSpriteEntries[0x21].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[0x21].unk2E], 0x21);
    if (gUnk_03001800.unkF8 & 1)
        gSpriteEntries[0x21].unk2 = 0xB8;
    else
        gSpriteEntries[0x21].unk2 = 0x38;
    gUnk_03001800.unk51 = 0;
    gUnk_03001800.unkAA++;
}

void medaforce_status_restore_check_targets(void) {
    u32 found = 0;
    u32 i;

    medaforce_clear_hit_list();
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 == 0)
            continue;
        found = 1;
        gUnk_03001800.unkD2[i] = found;
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 2;
}

void medaforce_status_restore_sparkle_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084D55D0, (void *)0x06014800);
    CpuFastSet(gUnk_0850E6B8, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk0 = 0xC404;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3C], 0x21 + i);
        if (gUnk_03001800.unkF8 & 1)
            gSpriteEntries[0x21 + i].unk0 |= 0x1000;
    }
    play_sound_effect(0x37);
    gUnk_03001800.unkAA++;
}

void medaforce_status_restore_sparkle_wait(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            process_sprite_anim_commands(gUnk_083B5F80[0x3C], 0x21 + i);
            if (gSpriteEntries[0x21 + i].unk22 == 0xFF)
                done = 1;
        }
    }
    if (done) {
        clear_battle_sprite_slot(0x21, 3);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_status_restore_apply(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i])
            bot_clear_effects(gUnk_03001800.unk60 + i, 1);
    }
    gUnk_03001800.unkAA++;
}

void medaforce_status_restore_set_message(void) {
    gUnk_03001800.unkA6 = 0x53;
    gUnk_03001800.unkAA++;
}

// Opcode 0x57: Total Recovery (Medaforce 0x1A).
void medaforce_total_recovery_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceTotalRecoverySteps[gUnk_03001800.unkAA]();
}

void medaforce_total_recovery_orb_spawn(void) {
    lz_decompress_dispatch(gUnk_084DD894, (void *)0x06014800);
    CpuFastSet(gUnk_0850ECD8, (void *)0x050002E0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk4 = 0xE0;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk28 = 0;
    gSpriteEntries[0x21].unk2E = 0x5C;
    gSpriteEntries[0x21].unk29 = 6;
    gSpriteEntries[0x21].unk2B = 0x20;
    gSpriteEntries[0x21].unk2C = 0xC0;
    gSpriteEntries[0x21].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[0x21].unk2E], 0x21);
    if (gUnk_03001800.unkF8 & 1)
        gSpriteEntries[0x21].unk2 = 0xB8;
    else
        gSpriteEntries[0x21].unk2 = 0x38;
    gUnk_03001800.unk51 = 1;
    gUnk_03001800.unkAA++;
}

void medaforce_total_recovery_check_targets(void) {
    u32 found = 0;
    u32 i;

    medaforce_clear_hit_list();
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        if (find_most_damaged_part(gUnk_03001800.unk60 + i) == 0)
            continue;
        found = 1;
        gUnk_03001800.unkD2[i] = found;
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 2;
}

void medaforce_team_heal_sparkle_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084DE4BC, (void *)0x06014800);
    CpuFastSet(gUnk_0850ED18, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk0 = 0xC404;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x60], 0x21 + i);
        if (gUnk_03001800.unkF8 & 1)
            gSpriteEntries[0x21 + i].unk0 |= 0x1000;
    }
    play_sound_effect(0x2A);
    gUnk_03001800.unkAA++;
}

void medaforce_team_heal_sparkle_wait(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            process_sprite_anim_commands(gUnk_083B5F80[0x60], 0x21 + i);
            if (gSpriteEntries[0x21 + i].unk22 == 0xFF)
                done = 1;
        }
    }
    if (done) {
        clear_battle_sprite_slot(0x21, 3);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_total_recovery_apply_heal(void) {
    u32 i, j;
    u32 r;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        for (j = 0; j <= 3; j++) {
            r = find_most_damaged_part(gUnk_03001800.unk60 + i);
            if (r == 0)
                goto next;
            gUnk_03001800.unkD0 = r - 1;
            battle_calc_damage_split(gUnk_03001800.unk60 + i, gUnk_03001800.unkD0, gUnk_03001800.unkEC);
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[gUnk_03001800.unkD0].unk11 += gUnk_03001800.unkC8;
            gUnk_03001800.unkD6[i] += gUnk_03001800.unkC8;
            if (gUnk_03001800.unkCA == 0)
                goto next;
            gUnk_03001800.unkEC = gUnk_03001800.unkCA;
        }
    next:;
    }
    gUnk_03001800.unkAA++;
}

void init_battle_bot_display_digits(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        switch (i) {
        case 0:
            set_display_digit_type(gUnk_03000440.unk9E, gUnk_03001800.unkD6[i], 0);
            battle_number_popup_init_slot(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
            break;
        case 1:
            set_display_digit_type(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkD6[1], 0);
            battle_number_popup_init_slot(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
            break;
        case 2:
            set_display_digit_type(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unkD6[2], 0);
            battle_number_popup_init_slot(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
            break;
        }
    }
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void medaforce_team_marked_popup_wait(void) {
    u32 i;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            switch (i) {
            case 0:
                battle_popup_update_slot(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
                break;
            case 1:
                battle_popup_update_slot(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
                break;
            case 2:
                battle_popup_update_slot(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
                break;
            }
        }
    }
    gUnk_03000440.unk84++;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1) && gUnk_03000440.unk84 > 0x32)
        gUnk_03000440.unk84 = 0x78;
    if (gUnk_03000440.unk84 == 0x78) {
        clear_battle_sprite_slot(gUnk_03001800.unk60 * 4 + 0x21, 0xC);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_total_recovery_set_message(void) {
    gUnk_03001800.unkA6 = 0x3B;
    gUnk_03001800.unkAA++;
}

// Opcode 0x58: Full Body Repair (Medaforce 0x1C).
void medaforce_full_body_repair_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceFullBodyRepairSteps[gUnk_03001800.unkAA]();
}

void medaforce_full_body_repair_begin(void) {
    lz_decompress_dispatch(gUnk_084DDEA4, (void *)0x06014800);
    CpuFastSet(gUnk_0850ECF8, (void *)0x050002E0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk4 = 0xE0;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk28 = 0;
    gSpriteEntries[0x21].unk2E = 0x5C;
    gSpriteEntries[0x21].unk29 = 6;
    gSpriteEntries[0x21].unk2B = 0x20;
    gSpriteEntries[0x21].unk2C = 0xC0;
    gSpriteEntries[0x21].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[0x21].unk2E], 0x21);
    if (gUnk_03001800.unkF8 & 1)
        gSpriteEntries[0x21].unk2 = 0xB8;
    else
        gSpriteEntries[0x21].unk2 = 0x38;
    gUnk_03001800.unk51 = 2;
    gUnk_03001800.unkAA++;
}

void medaforce_full_body_repair_check_targets(void) {
    u32 found = 0;
    u32 i;

    medaforce_clear_hit_list();
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        if (find_random_broken_part(gUnk_03001800.unk60 + i) == 0)
            continue;
        found = 1;
        gUnk_03001800.unkD2[i] = found;
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 2;
}

void medaforce_full_body_repair_apply_repair(void) {
    u32 i, j;
    u32 r;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        for (j = 0; j <= 3; j++) {
            r = find_random_broken_part(gUnk_03001800.unk60 + i);
            if (r == 0)
                goto next;
            gUnk_03001800.unkD0 = r - 1;
            battle_set_damage_display(gUnk_03001800.unk60 + i, gUnk_03001800.unkD0, gUnk_03001800.unkEC);
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[gUnk_03001800.unkD0].unk11 += gUnk_03001800.unkC8;
            gUnk_03001800.unkD6[i] += gUnk_03001800.unkC8;
            bot_restore_leg_stats(gUnk_03001800.unk60 + i);
            if (gUnk_03001800.unkCA == 0)
                goto next;
            gUnk_03001800.unkEC = gUnk_03001800.unkCA;
        }
    next:;
    }
    load_all_bot_part_sprites();
    iterate_bots_setup_battle_sprites();
    gUnk_03001800.unkAA++;
}

void medaforce_full_body_repair_finish(void) {
    gUnk_03001800.unkA6 = 0x3C;
    gUnk_03001800.unkAA++;
}

// Opcode 0x59: Full Body Up (Medaforce 0x16).
void medaforce_full_body_up_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceFullBodyUpSteps[gUnk_03001800.unkAA]();
}

void medaforce_full_body_up_begin(void) {
    lz_decompress_dispatch(gUnk_084DE628, (void *)0x06014800);
    CpuFastSet(gUnk_0850ED38, (void *)0x050002E0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = 0x78;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk8 = 4;
    gSpriteEntries[0x21].unk9 = 4;
    gSpriteEntries[0x21].unk18 = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x61], 0x21);
    gSpriteEntries[0x22].unk0 = 0xC604;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = 0x78;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x22].unkA = 6;
    gSpriteEntries[0x22].unkB = 0xE0;
    gSpriteEntries[0x22].unk8 = 4;
    gSpriteEntries[0x22].unk9 = 4;
    gSpriteEntries[0x22].unk18 = 0;
    gSpriteEntries[0x22].unk6 = 0x7604;
    play_sound_effect(0x67);
    gUnk_03001800.unkAA++;
}

// guess: sprite meaning unsure; scales sprites 0x21/0x22 up to 0x40, then 60-frame wait (orb)

void medaforce_full_body_up_orb_grow(void) {
    if (gSpriteEntries[0x21].unk8 == 0x40) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 += 4;
        gSpriteEntries[0x21].unk9 += 4;
        gSpriteEntries[0x22].unk8 += 4;
        gSpriteEntries[0x22].unk9 += 4;
    }
}

void medaforce_full_body_up_orb_rise(void) {
    if (gSpriteEntries[0x21].unk4 == 0x20) {
        play_sound_effect(0x42);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk4--;
        gSpriteEntries[0x22].unk4--;
    }
}

void medaforce_full_body_up_orb_anim_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x61], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_full_body_up_orbs_spawn(void) {
    u32 i;

    medaforce_clear_hit_list();
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        memcpy_bytes_0803F63C(&gSpriteEntries[0x22], &gSpriteEntries[0x23 + i], 0x40);
        gSpriteEntries[0x23 + i].unk30 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x23 + i].unk32 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x23 + i].unk24 = 3;
        gSpriteEntries[0x23 + i].unk23 = 0;
        gUnk_03001800.unkD2[i] = 1;
    }
    clear_battle_sprite_slot(0x22, 1);
    gUnk_03001800.unkAA++;
}

void medaforce_full_body_up_orbs_fly(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            gSpriteEntries[0x23 + i].unk18 = (gSpriteEntries[0x23 + i].unk18 + 0x20) & 0x3FF;
            if (move_sprite_toward_target(0x23 + i))
                done++;
        }
    }
    if (count == done) {
        play_sound_effect(0x2B);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_full_body_up_orbs_shrink(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            gSpriteEntries[0x23 + i].unk18 = (gSpriteEntries[0x23 + i].unk18 + 0x20) & 0x3FF;
            gSpriteEntries[0x23 + i].unk8 -= 4;
            gSpriteEntries[0x23 + i].unk9 -= 4;
            if (gSpriteEntries[0x23 + i].unk9 == 4)
                done = 1;
        }
    }
    if (done) {
        clear_battle_sprite_slot(0x24, 3);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_full_body_up_apply_head_uses(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            calc_head_uses_given(gUnk_03001800.unk60 + i, gUnk_03001800.unkEC);
            gUnk_03001800.unkD6[i] = gUnk_03001800.unkC8;
            add_u8_capped(&gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk10, gUnk_03001800.unkD6[i],
                          gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].data[8]);
        }
    }
    gUnk_03001800.unkAA++;
}

void medaforce_team_text_popups_init(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084D6BFC, (void *)0x06017E00);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        switch (i) {
        case 0:
            set_display_digit_type(gUnk_03000440.unk9E, gUnk_03001800.unkD6[i], 0);
            battle_text_popup_init_slot(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
            break;
        case 1:
            set_display_digit_type(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkD6[1], 0);
            battle_text_popup_init_slot(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
            break;
        case 2:
            set_display_digit_type(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unkD6[2], 0);
            battle_text_popup_init_slot(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
            break;
        }
    }
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void medaforce_full_body_up_finish(void) {
    gUnk_03001800.unkA6 = 0x54;
    gUnk_03001800.unkAA++;
}

// Opcode 0x5A: Full Body RAD (Medaforce 0x17).
void medaforce_full_body_rad_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceFullBodyRadSteps[gUnk_03001800.unkAA]();
}

void medaforce_full_body_rad_begin(void) {
    lz_decompress_dispatch(gUnk_084DED1C, (void *)0x06014800);
    CpuFastSet(gUnk_0850ED58, (void *)0x050002E0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk8 = 4;
    gSpriteEntries[0x21].unk9 = 4;
    gSpriteEntries[0x21].unk18 = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x62], 0x21);
    if (!(gUnk_03001800.unkF8 & 1)) {
        gSpriteEntries[0x21].unk2 = 0x70;
    } else {
        gSpriteEntries[0x21].unk0 |= 0x1000;
        gSpriteEntries[0x21].unk2 = 0x80;
    }
    play_sound_effect(0x6A);
    gUnk_03001800.unkAA++;
}

void medaforce_full_body_rad_grow(void) {
    if (gSpriteEntries[0x21].unk8 == 0x40) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 += 4;
        gSpriteEntries[0x21].unk9 += 4;
    }
}

void medaforce_full_body_rad_push_back_init(void) {
    u32 i;

    medaforce_clear_hit_list();
    gUnk_03001800.unk60 = battle_enemy_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        gUnk_03000590[gUnk_03001800.unk60 + i].unkBD |= 4;
        gUnk_03001800.unkD2[i] = 1;
        battle_queue_remove_bot(gUnk_03001800.unk60 + i);
        gUnk_03000590[gUnk_03001800.unk60 + i].moveSubpixel = 0;
        gUnk_03000590[gUnk_03001800.unk60 + i].moveDelay = 0x14;
        gUnk_03000590[gUnk_03001800.unk60 + i].moveStep = 0;
        gSpriteEntries[0x22 + i].unk0 = 0xC404;
        gSpriteEntries[0x22 + i].unk1C = 0;
        gSpriteEntries[0x22 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x22 + i].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 0x10;
        gSpriteEntries[0x22 + i].unkA = 7;
        gSpriteEntries[0x22 + i].unkB = 0xE0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x63], 0x22 + i);
        if (gUnk_03001800.unkF8 & 1)
            gSpriteEntries[0x22 + i].unk0 |= 0x1000;
    }
    iterate_bots_setup_battle_sprites();
    gUnk_03000440.unk86 = 0;
    gSpriteEntries[0x21].unk0 &= 0xFDFF;
    gSpriteEntries[0x2B].unk29 = 1;
    gSpriteEntries[0x2B].unk2 = gSpriteEntries[0x21].unk2;
    gSpriteEntries[0x2B].unk4 = gSpriteEntries[0x21].unk4;
    battle_queue_sort();
    gUnk_03001800.unkAA++;
}

void medaforce_full_body_rad_push_back(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        count++;
        bot_update_walk_anim(gUnk_03001800.unk60 + i);
        if (battle_bot_move_reverse(gUnk_03001800.unk60 + i))
            done++;
        process_sprite_anim_commands(gUnk_083B5F80[0x63], 0x22 + i);
        gSpriteEntries[0x22 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x22 + i].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 0x10;
        init_battle_sprite_entry_0801BC04(gUnk_03001800.unk60 + i);
    }
    process_sprite_anim_commands(gUnk_083B5F80[0x62], 0x21);
    if (!(gUnk_03000440.unk86 & 0x3F))
        play_sound_effect(0x33);
    gUnk_03000440.unk86++;
    particle_run_spark_handlers();
    if (done == count && gUnk_03000440.unk86 > 0x3C) {
        clear_battle_sprite_slot(0x21, 0x1B);
        iterate_bots_setup_battle_sprites();
        gUnk_03001800.unkAA++;
    }
}

void medaforce_full_body_rad_finish(void) {
    gUnk_03001800.unkA6 = 0x65;
    gUnk_03001800.unkAA++;
}

// Opcode 0x5B: Iron Wall (Medaforce 0x18).
void medaforce_iron_wall_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceIronWallSteps[gUnk_03001800.unkAA]();
}

void medaforce_iron_wall_begin(void) {
    lz_decompress_dispatch(gUnk_084DF024, (void *)0x06014800);
    CpuFastSet(gUnk_0850ED78, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = -0x39DC;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x20;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = -0x10;
    gSpriteEntries[0x21].unk8 = 0x80;
    gSpriteEntries[0x21].unk9 = 0x80;
    gSpriteEntries[0x21].unk2B = 0x1C;
    gSpriteEntries[0x21].unk2C = 0;
    gSpriteEntries[0x21].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1C], 0x21);
    gSpriteEntries[0x22].unk0 = -0x39DC;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x20;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = -0x10;
    gSpriteEntries[0x22].unk8 = 0x80;
    gSpriteEntries[0x22].unk9 = 0x80;
    gSpriteEntries[0x22].unk2B = 0x1C;
    gSpriteEntries[0x22].unk2C = 0x80;
    gSpriteEntries[0x22].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1C], 0x22);
    play_sound_effect(0x33);
    gUnk_03001800.unkAA++;
}

void medaforce_iron_wall_apply_defence(void) {
    add_u8_capped(&gUnk_03000590[gUnk_03001800.unk87].unkD0 + 1, gUnk_03001800.unkEC, 0xFF);
    gUnk_03001800.unkAA++;
}

void medaforce_iron_wall_finish(void) {
    gUnk_03001800.unkA6 = 0x45;
    gUnk_03001800.unkAA++;
}

// Opcode 0x5C: Power Up (Medaforce 0x19).
void medaforce_power_up_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforcePowerUpSteps[gUnk_03001800.unkAA]();
}

void medaforce_power_up_begin(void) {
    lz_decompress_dispatch(gUnk_084DF400, (void *)0x06014800);
    CpuFastSet(gUnk_0850ED98, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = -0x39DC;
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
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x64], 0x21);
    gSpriteEntries[0x22].unk0 = -0x39DC;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x20;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = 0xF0;
    gSpriteEntries[0x22].unk8 = 0x80;
    gSpriteEntries[0x22].unk9 = 0x80;
    gSpriteEntries[0x22].unk6 = 0x7901;
    gSpriteEntries[0x22].unk2B = 0x1C;
    gSpriteEntries[0x22].unk2C = 0x80;
    gSpriteEntries[0x22].unk2D = 0;
    play_sound_effect(0x33);
    gUnk_03001800.unkAA++;
}

void medaforce_power_up_shield_anim_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x64], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

// guess: sprite meaning unsure; spawns sprite 0x21 (anim 0x65) on the user, sound 0x71    (aura)

void medaforce_power_up_aura_spawn(void) {
    gSpriteEntries[0x21].unk0 = 0xCC04;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x65], 0x21);
    play_sound_effect(0x71);
    gUnk_03001800.unkAA++;
}

void medaforce_power_up_aura_anim_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x65], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_power_up_apply_power(void) {
    add_u8_capped(&gUnk_03000590[gUnk_03001800.unk87].unkD0, gUnk_03001800.unkEC, 0xFF);
    gUnk_03001800.unkAA++;
}

void medaforce_power_up_finish(void) {
    gUnk_03001800.unkA6 = 0x44;
    gUnk_03001800.unkAA++;
}

// Opcode 0x5D: Anti Air / Anti Sea (Medaforces 0x1E, 0x20).
void medaforce_anti_terrain_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceAntiTerrainSteps[gUnk_03001800.unkAA]();
}

void medaforce_anti_terrain_beam_spawn(void) {
    lz_decompress_dispatch(gUnk_084DFA88, (void *)0x06014800);
    CpuFastSet(gUnk_0850EDB8, (void *)0x050002C0, 0x10);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk6 = 0x7A00;
    gSpriteEntries[0x22].unk0 = 0xC404;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = 0xE0;
    gSpriteEntries[0x22].unk2D = 0;
    if (gUnk_03000590[gUnk_03001800.unk87].unkA8[0] == 0x1E)
        gSpriteEntries[0x22].unk6 = 0x7A01;
    else
        gSpriteEntries[0x22].unk6 = 0x7A02;
    play_sound_effect(0x4C);
    gUnk_03001800.unkAA++;
}

void medaforce_anti_terrain_check_targets(void) {
    u32 i;
    u32 found = 0;

    medaforce_clear_hit_list();
    gUnk_03001800.unk60 = battle_enemy_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0 ||
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0 ||
            battle_bot_lacks_stability(gUnk_03001800.unk60 + i) == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk87].unkA8[0] == 0x1E) {
            if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].data[1] == 0x64) {
                gUnk_03001800.unkD2[i] = 1;
                found = 1;
            }
        } else if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].data[1] == 0x6A) {
            gUnk_03001800.unkD2[i] = 2;
            found = 1;
        }
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 2;
}

void medaforce_anti_terrain_bolts_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084DFBD4, (void *)0x06014800);
    CpuFastSet(gUnk_0850EDF8, (void *)0x050002C0, 0x10);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].unk0 = 0xC404;
        gSpriteEntries[i + 0x21].unk1C = 0;
        gSpriteEntries[i + 0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
        gSpriteEntries[i + 0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[i + 0x21].unk30 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[i + 0x21].unk32 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[i + 0x21].unk24 = 6;
        gSpriteEntries[i + 0x21].unk23 = 0;
        gSpriteEntries[i + 0x21].unkB = 0xF0;
        if (gUnk_03001800.unkF8 & 1)
            gSpriteEntries[i + 0x21].unk0 |= 0x1000;
        if (gUnk_03001800.unkD2[i] == 1) {
            gSpriteEntries[i + 0x21].unkA = 6;
            gSpriteEntries[i + 0x21].unk6 = 0x7B00;
        } else {
            gSpriteEntries[i + 0x21].unkA = 7;
            gSpriteEntries[i + 0x21].unk6 = 0x7B01;
        }
    }
    play_sound_effect(0x24);
    gUnk_03001800.unkAA++;
}

void medaforce_anti_terrain_bolts_fly(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        count++;
        if (move_sprite_toward_target(i + 0x21))
            done++;
    }
    if (done == count)
        gUnk_03001800.unkAA++;
}

void medaforce_anti_terrain_burst_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084DCF54, (void *)0x06016000);
    CpuFastSet(gUnk_0850EC58, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].unkA = 7;
        gSpriteEntries[i + 0x21].unk0 &= 0xEFFF;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x66], i + 0x21);
    }
    gUnk_03001800.unkAA++;
}

void medaforce_anti_terrain_burst_anim_wait(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        process_sprite_anim_commands(gUnk_083B5F80[0x66], i + 0x21);
        if (gSpriteEntries[i + 0x21].unk22 == 0xFF)
            done = 1;
    }
    if (done)
        gUnk_03001800.unkAA++;
}

void medaforce_anti_terrain_roll_status(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03001800.unkD6[i] = rng_next_byte() & 7;
        switch (gUnk_03001800.unkD6[i]) {
        case 0:
            if (bot_has_status_guard(gUnk_03001800.unk60 + i, 0xD))
                gUnk_03001800.unkD6[i] = 5;
            break;
        case 1:
            if (bot_has_status_guard(gUnk_03001800.unk60 + i, 0x11))
                gUnk_03001800.unkD6[i] = 5;
            break;
        case 2:
            if (bot_has_status_guard(gUnk_03001800.unk60 + i, 0x13))
                gUnk_03001800.unkD6[i] = 5;
            break;
        case 3:
            if (bot_has_status_guard(gUnk_03001800.unk60 + i, 0x10))
                gUnk_03001800.unkD6[i] = 5;
            break;
        }
        gSpriteEntries[i + 0x21].unk6 = 0x6F00 + gUnk_03001800.unkD6[i];
        gSpriteEntries[i + 0x21].unk23 = 0;
    }
    play_sound_effect(0x5B);
    gUnk_03001800.unkAA++;
}

void medaforce_anti_terrain_apply_status(void) {
    u32 i;

    clear_battle_sprite_slot(0x21, 3);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        switch (gUnk_03001800.unkD6[i]) {
        case 0:
            battle_inflict_status(gUnk_03001800.unk60 + i, 0xD, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            break;
        case 1:
            battle_inflict_status(gUnk_03001800.unk60 + i, 0x11, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            break;
        case 2:
            battle_inflict_status(gUnk_03001800.unk60 + i, 0x13, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            break;
        case 3:
            battle_inflict_status(gUnk_03001800.unk60 + i, 0x10, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            break;
        case 4:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 = 0x2B;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCB = clamp_1_99(gUnk_03001800.unkE8);
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCC = clamp_1_99(gUnk_03001800.unkEC);
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 1;
            break;
        case 5:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 = 0x2C;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 0;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCB = clamp_1_99(gUnk_03001800.unkE8);
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCC = clamp_1_99(gUnk_03001800.unkEC);
            break;
        case 6:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 = 0x2E;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 0;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCB = clamp_1_99(gUnk_03001800.unkE8);
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCC = clamp_1_99(gUnk_03001800.unkEC);
            break;
        case 7:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 = 0x2F;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 0;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCB = clamp_1_99(gUnk_03001800.unkE8);
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCC = clamp_1_99(gUnk_03001800.unkEC);
            break;
        }
    }
    gUnk_03001800.unkAA++;
}

void medaforce_anti_terrain_finish(void) {
    if (gUnk_03000590[gUnk_03001800.unk87].unkA8[0] == 0x1E)
        gUnk_03001800.unkA6 = 0x4D;
    else
        gUnk_03001800.unkA6 = 0x4E;
    gUnk_03001800.unkAA++;
}

// Opcode 0x5E: Propulsion / Mobility / PROX / Remoteness Up (Medaforces 0x1F, 0x21, 0x23, 0x25).
void medaforce_legs_stat_up_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceLegsStatUpSteps[gUnk_03001800.unkAA]();
}

void medaforce_legs_stat_up_begin(void) {
    u32 i;

    medaforce_clear_hit_list();
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 != 0 &&
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 != 0)
            gUnk_03001800.unkD2[i] = 1;
    }
    switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0]) {
    case 0x1F:
        gUnk_03001800.unk51 = 0;
        break;
    case 0x21:
        gUnk_03001800.unk51 = 1;
        break;
    case 0x23:
        gUnk_03001800.unk51 = 2;
        break;
    case 0x25:
        gUnk_03001800.unk51 = 3;
        break;
    }
    gUnk_03001800.unkAA++;
}

// guess: sprite meaning unsure; loads graphics, spawns sprites 0x21+i (anim 0x67) above each target    (arrows)

void medaforce_legs_stat_up_arrows_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084DFC18, (void *)0x06014800);
    CpuFastSet(gUnk_0850EE38, (void *)0x050002C0, 0x10);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].unk0 = 0xC404;
        gSpriteEntries[i + 0x21].unk1C = 0;
        gSpriteEntries[i + 0x21].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[i + 0x21].unk4 = 0xF0;
        gSpriteEntries[i + 0x21].unkA = 6;
        gSpriteEntries[i + 0x21].unkB = 0xF0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x67], i + 0x21);
    }
    play_sound_effect(0x2C);
    gUnk_03001800.unkAA++;
}

void medaforce_legs_stat_up_arrows_fall(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        count++;
        process_sprite_anim_commands(gUnk_083B5F80[0x67], i + 0x21);
        if (gSpriteEntries[i + 0x21].unk4 == gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4)
            done++;
        else
            gSpriteEntries[i + 0x21].unk4 = (gSpriteEntries[i + 0x21].unk4 + 1) & 0xFF;
    }
    if (done == count)
        gUnk_03001800.unkAA++;
}

void medaforce_legs_stat_up_burst_spawn(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].unk0 = 0xCC04;
        gSpriteEntries[i + 0x21].unkB = 0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x68], i + 0x21);
    }
    play_sound_effect(0x30);
    gUnk_03001800.unkAA++;
}

void medaforce_legs_stat_up_burst_anim_wait(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        process_sprite_anim_commands(gUnk_083B5F80[0x68], i + 0x21);
        if (gSpriteEntries[i + 0x21].unk22 == 0xFF)
            done = 1;
    }
    if (done)
        gUnk_03001800.unkAA++;
}

void medaforce_legs_stat_up_icon_spawn(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].unk0 = 0xC404;
        gSpriteEntries[i + 0x21].unkB = 0xE0;
        gSpriteEntries[i + 0x21].unk4 += 8;
        gSpriteEntries[i + 0x21].unkA = 7;
        gSpriteEntries[i + 0x21].unk6 = 0x7C04 + gUnk_03001800.unk51;
    }
    gUnk_03000440.unk86 = 0;
    play_sound_effect(0x2E);
    gUnk_03001800.unkAA++;
}

void medaforce_legs_stat_up_icon_rise(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] != 0 && !(gUnk_03000440.unk86 & 1))
            gSpriteEntries[i + 0x21].unk4--;
    }
    if (++gUnk_03000440.unk86 == 0x20) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void medaforce_legs_stat_up_set_amounts(void) {
    u32 i;

    clear_battle_sprite_slot(0x21, 3);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] != 0)
            gUnk_03001800.unkD6[i] = gUnk_03001800.unkEC;
    }
    gUnk_03001800.unkAA++;
}

void medaforce_legs_stat_up_apply_stat(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        switch (gUnk_03001800.unk51) {
        case 0:
            add_u8_capped(&gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].data[5], gUnk_03001800.unkEC, 0xFF);
            break;
        case 1:
            add_u8_capped(&gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].data[6], gUnk_03001800.unkEC, 0xFF);
            break;
        case 2:
            add_u8_capped(&gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].data[8], gUnk_03001800.unkEC, 0xFF);
            break;
        case 3:
            add_u8_capped(&gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].data[9], gUnk_03001800.unkEC, 0xFF);
            break;
        }
        bot_halve_broken_leg_stats(gUnk_03001800.unk60 + i);
        bot_restore_leg_stats(gUnk_03001800.unk60 + i);
    }
    gUnk_03001800.unkAA++;
}

void medaforce_legs_stat_up_finish(void) {
    switch (gUnk_03001800.unk51) {
    case 0:
        gUnk_03001800.unkA6 = 0x3D;
        break;
    case 1:
        gUnk_03001800.unkA6 = 0x3E;
        break;
    case 2:
        gUnk_03001800.unkA6 = 0x40;
        break;
    case 3:
        gUnk_03001800.unkA6 = 0x41;
        break;
    }
    gUnk_03001800.unkAA++;
}

// Opcode 0x5F: Spy Game (Medaforce 0x22).
void medaforce_spy_game_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceSpyGameSteps[gUnk_03001800.unkAA]();
}

void medaforce_spy_game_beam_spawn(void) {
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = 0x78;
    gSpriteEntries[0x21].unk4 = 0x40;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk6 = 0x4800;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk2D = 0;
    gSpriteEntries[0x21].unk2E = 1;
    gUnk_03000440.unk86 = 0;
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void medaforce_spy_game_beam_spin(void) {
    u32 v;

    if (gUnk_03000440.unk84 <= 2) {
        if (gUnk_03000440.unk86 == 0) {
            gUnk_03000440.unk84++;
            play_sound_effect(0x4C);
        }
        if (++gUnk_03000440.unk86 == gUnk_083AE7D0[gUnk_03000440.unk84 - 1])
            gUnk_03000440.unk86 = 0;
    }
    if (gSpriteEntries[0x21].unk18 == 0)
        gSpriteEntries[0x21].unk2E++;
    v = (u16)(gSpriteEntries[0x21].unk2E * 16 + gSpriteEntries[0x21].unk18) & 0x3FF;
    gSpriteEntries[0x21].unk18 = v;
    if (gSpriteEntries[0x21].unk2E == 5 && v == 0) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_mark_both_sides(void) {
    u32 i;

    medaforce_clear_hit_list();
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 != 0 &&
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 != 0)
            gUnk_03001800.unkD2[i] = 1;
    }
    gUnk_03001800.unk60 = battle_enemy_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 != 0 &&
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 != 0)
            gUnk_03001800.unkD6[i] = 1;
    }
    gUnk_03001800.unkAA++;
}

void medaforce_spy_game_arrows_spawn(void) {
    u32 i;

    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].unk0 = 0xC624;
        gSpriteEntries[i + 0x21].unk1C = 0;
        gSpriteEntries[i + 0x21].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[i + 0x21].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4;
        gSpriteEntries[i + 0x21].unkA = 7;
        gSpriteEntries[i + 0x21].unkB = 0xF0;
        gSpriteEntries[i + 0x21].unk8 = 0x40;
        gSpriteEntries[i + 0x21].unk9 = 0x40;
        gSpriteEntries[i + 0x21].unk6 = 0x4801;
    }
    gUnk_03001800.unk60 = battle_enemy_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD6[i] == 0)
            continue;
        gSpriteEntries[i + 0x24].unk0 = 0xC624;
        gSpriteEntries[i + 0x24].unk1C = 0;
        gSpriteEntries[i + 0x24].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[i + 0x24].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 0x10;
        gSpriteEntries[i + 0x24].unkA = 7;
        gSpriteEntries[i + 0x24].unkB = 0xF0;
        gSpriteEntries[i + 0x24].unk8 = 0x40;
        gSpriteEntries[i + 0x24].unk9 = 0x40;
        gSpriteEntries[i + 0x24].unk6 = 0x4802;
    }
    gUnk_03000440.unk84 = 0;
    play_sound_effect(0x2E);
    gUnk_03001800.unkAA++;
}

void medaforce_spy_game_arrows_move(void) {
    u32 i;

    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] != 0 && !(gUnk_03000440.unk84 & 1))
            gSpriteEntries[i + 0x21].unk4--;
    }
    gUnk_03001800.unk60 = battle_enemy_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD6[i] != 0 && !(gUnk_03000440.unk84 & 1))
            gSpriteEntries[i + 0x24].unk4++;
    }
    if (gUnk_03000440.unk84 == 0x20) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    } else
        gUnk_03000440.unk84++;
}

void medaforce_spy_game_arrows_shrink(void) {
    u32 i;

    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] != 0) {
            gSpriteEntries[i + 0x21].unk8 -= 8;
            gSpriteEntries[i + 0x21].unk9 += 8;
        }
    }
    gUnk_03001800.unk60 = battle_enemy_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD6[i] != 0) {
            gSpriteEntries[i + 0x24].unk8 -= 8;
            gSpriteEntries[i + 0x24].unk9 += 8;
        }
    }
    if (gSpriteEntries[0x21].unk8 == 8) {
        clear_battle_sprite_slot(0x21, 6);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_spy_game_apply_bonus(void) {
    add_u8_capped(&gUnk_03001800.unk28[gUnk_03001800.unk89].unk0, gUnk_03001800.unkEC, 0xA0);
    subtract_u8_floored(&gUnk_03001800.unk28[gUnk_03001800.unk8A].unk0, gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void medaforce_spy_game_finish(void) {
    gUnk_03001800.unkA6 = 0x5B;
    gUnk_03001800.unkAA++;
}

// Opcode 0x60: Hide n Seek (Medaforce 0x24).
void medaforce_hide_n_seek_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceHideNSeekSteps[gUnk_03001800.unkAA]();
}

void medaforce_hide_n_seek_domes_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084D5EBC, (void *)0x06014800);
    CpuFastSet(gUnk_0850E7B8, (void *)0x050002E0, 8);
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].unk0 = 0xC404;
        gSpriteEntries[i + 0x21].unk1C = 0;
        gSpriteEntries[i + 0x21].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[i + 0x21].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[i + 0x21].unkA = 7;
        gSpriteEntries[i + 0x21].unkB = 0xF0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x40], i + 0x21);
    }
    gUnk_03001800.unk60 = battle_enemy_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD6[i] == 0)
            continue;
        gSpriteEntries[i + 0x24].unk0 = 0xC404;
        gSpriteEntries[i + 0x24].unk1C = 0;
        gSpriteEntries[i + 0x24].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[i + 0x24].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[i + 0x24].unkA = 7;
        gSpriteEntries[i + 0x24].unkB = 0xF0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x41], i + 0x24);
    }
    play_sound_effect(0x4D);
    gUnk_03001800.unkAA++;
}

void medaforce_hide_n_seek_domes_anim_wait(void) {
    u32 i;

    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] != 0)
            process_sprite_anim_commands(gUnk_083B5F80[0x40], i + 0x21);
    }
    gUnk_03001800.unk60 = battle_enemy_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD6[i] != 0)
            process_sprite_anim_commands(gUnk_083B5F80[0x41], i + 0x24);
    }
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 6);
        gUnk_03000440.unk84 = 0;
        gUnk_03001800.unkAA++;
    }
}

void medaforce_hide_n_seek_blink_wait(void) {
    u32 i;

    gUnk_03000440.unk84++;
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] != 0)
            battle_bot_sprites_blink(gUnk_03001800.unk60 + i, gUnk_03000440.unk84, 2);
    }
    if (gUnk_03000440.unk84 == 0x3C) {
        for (i = 0; i <= 2; i++) {
            if (gUnk_03001800.unkD2[i] != 0)
                battle_bot_sprites_show(gUnk_03001800.unk60 + i);
        }
        gUnk_03001800.unkAA++;
    }
}

void medaforce_hide_n_seek_apply_evasion(void) {
    u32 i;

    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] != 0)
            add_u8_capped(&gUnk_03000590[gUnk_03001800.unk60 + i].unkB8 + 1, gUnk_03001800.unkEC, 0x78);
    }
    gUnk_03001800.unk60 = battle_enemy_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD6[i] != 0)
            subtract_u8_floored(&gUnk_03000590[gUnk_03001800.unk60 + i].unkB8 + 1, gUnk_03001800.unkEC);
    }
    gUnk_03001800.unkAA++;
}

void medaforce_hide_n_seek_finish(void) {
    gUnk_03001800.unkA6 = 0x5C;
    gUnk_03001800.unkAA++;
}

// Opcode 0x61: Charge (Medaforce 0x26).
void medaforce_charge_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceChargeSteps[gUnk_03001800.unkAA]();
}

void medaforce_charge_begin(void) {
    lz_decompress_dispatch(gUnk_084DFFE4, (void *)0x06014800);
    CpuFastSet(gUnk_0850EE78, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = 0x78;
    gSpriteEntries[0x21].unk4 = 0x40;
    gSpriteEntries[0x21].unk8 = 4;
    gSpriteEntries[0x21].unk9 = 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk6 = 0x7D00;
    play_sound_effect(0x6E);
    gUnk_03001800.unkAA++;
}

void medaforce_center_sprite_grow(void) {
    if (gSpriteEntries[0x21].unk8 == 0x40) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 += 4;
        gSpriteEntries[0x21].unk9 += 4;
    }
}

void medaforce_center_sprite_shrink_half(void) {
    if (gSpriteEntries[0x21].unk8 == 0x20) {
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 4;
        gSpriteEntries[0x21].unk9 -= 4;
    }
}

void medaforce_charge_check_targets(void) {
    u32 i;
    u32 found = 0;

    medaforce_clear_hit_list();
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 != 0 &&
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 != 0 &&
            battle_bot_lacks_stability(gUnk_03001800.unk60 + i) != 0) {
            gUnk_03001800.unkD2[i] = 1;
            found = 1;
        }
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 3;
}

void medaforce_center_sprite_shrink_out(void) {
    if (gSpriteEntries[0x21].unk8 == 4) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 4;
        gSpriteEntries[0x21].unk9 -= 4;
    }
}

void medaforce_charge_hourglass_spawn(void) {
    u32 i;

    clear_battle_sprite_slot(0x21, 1);
    lz_decompress_dispatch(gUnk_084D6098, (void *)0x06014800);
    CpuFastSet(gUnk_0850E7D8, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].unk0 = 0xC624;
        gSpriteEntries[i + 0x21].unk1C = 0;
        gSpriteEntries[i + 0x21].unk2 = 0x78;
        gSpriteEntries[i + 0x21].unk4 = 0x40;
        gSpriteEntries[i + 0x21].unkA = 7;
        gSpriteEntries[i + 0x21].unkB = 0xF0;
        gSpriteEntries[i + 0x21].unk8 = 0x40;
        gSpriteEntries[i + 0x21].unk9 = 0x40;
        gSpriteEntries[i + 0x21].unk18 = 0;
        gSpriteEntries[i + 0x21].unk30 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[i + 0x21].unk32 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[i + 0x21].unk24 = 6;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x42], i + 0x21);
    }
    gUnk_03001800.unkAA++;
}

void medaforce_charge_hourglass_fly(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        count++;
        process_sprite_anim_commands(gUnk_083B5F80[0x42], i + 0x21);
        if (!(gUnk_03001800.unkF8 & 1))
            gSpriteEntries[i + 0x21].unk18 = (u16)(gSpriteEntries[i + 0x21].unk18 - 0x40) & 0x3FF;
        else
            gSpriteEntries[i + 0x21].unk18 = (u16)(gSpriteEntries[i + 0x21].unk18 + 0x40) & 0x3FF;
        if (move_sprite_toward_target(i + 0x21))
            done++;
    }
    if (done == count) {
        gSpriteEntries[0x21].unk18 = 0;
        gSpriteEntries[0x22].unk18 = 0;
        gSpriteEntries[0x23].unk18 = 0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x43], 0x21);
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x43], 0x22);
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x43], 0x23);
        play_sound_effect(0x4E);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_charge_hourglass_burst_wait(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            process_sprite_anim_commands(gUnk_083B5F80[0x43], 0x21 + i);
            if (gSpriteEntries[0x21 + i].unk22 == 0xFF)
                done = 1;
        }
    }
    if (done)
        gUnk_03001800.unkAA++;
}

void medaforce_charge_hourglass_shrink(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            gSpriteEntries[0x21 + i].unk8 -= 4;
            gSpriteEntries[0x21 + i].unk9 -= 4;
            if (gSpriteEntries[0x21 + i].unk8 == 4)
                done = 1;
        }
    }
    if (done) {
        clear_battle_sprite_slot(0x21, 3);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_charge_apply_buff(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC4 = 0x26;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC5 = 0;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC6 = clamp_1_99(gUnk_03001800.unkE8);
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC7 = clamp_1_99(gUnk_03001800.unkEC);
        }
    }
    gUnk_03001800.unkAA++;
}

void medaforce_charge_finish(void) {
    gUnk_03001800.unkA6 = 0x59;
    gUnk_03001800.unkAA++;
}

// Opcode 0x62: Pushover Attk (Medaforce 0x27).
void medaforce_pushover_attack_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforcePushoverAttackSteps[gUnk_03001800.unkAA]();
}

void medaforce_pushover_attack_begin(void) {
    u32 i;

    medaforce_clear_hit_list();
    gUnk_03001800.unk60 = battle_enemy_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11)
            gUnk_03001800.unkD2[i] = 1;
    }
    gUnk_03001800.unkAA++;
}

void medaforce_pushover_attack_banana_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084D6464, (void *)0x06014800);
    CpuFastSet(gUnk_0850E838, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk0 = 0xC624;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = 0x78;
        gSpriteEntries[0x21 + i].unk4 = 0xF0;
        gSpriteEntries[0x21 + i].unk8 = 0x40;
        gSpriteEntries[0x21 + i].unk9 = 0x40;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        gSpriteEntries[0x21 + i].unk6 = 0x4D00;
        gSpriteEntries[0x21 + i].unk24 = 4;
        gSpriteEntries[0x21 + i].unk25 = 0;
        gSpriteEntries[0x21 + i].unk30 = 0;
        if (gUnk_03001800.unkF8 & 1)
            gSpriteEntries[0x21 + i].unk0 |= 0x1000;
    }
    play_sound_effect(0x61);
    gUnk_03001800.unkAA++;
}

void medaforce_pushover_attack_banana_drop(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            if (sprite_move_toward_target(0x21 + i, gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4,
                                          gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 + 0x10)) {
                gSpriteEntries[0x21 + i].unk30 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
                gSpriteEntries[0x21 + i].unk32 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
                gSpriteEntries[0x21 + i].unk24 = 6;
                done++;
            }
        }
    }
    if (done == count) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void medaforce_pushover_attack_banana_fly(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            if (move_sprite_toward_target(0x21 + i))
                done++;
        }
    }
    if (done == count)
        gUnk_03001800.unkAA++;
}

void medaforce_pushover_attack_target_hop_init(void) {
    u32 i;
    u32 j;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk23 = 0;
        memcpy_bytes_0803F63C(&gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5A],
                              &gSpriteEntries[(j = i * 4) + 0x24], 0x40);
        memcpy_bytes_0803F63C(&gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5B], &gSpriteEntries[j + 0x25], 0x40);
        memcpy_bytes_0803F63C(&gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5C], &gSpriteEntries[j + 0x26], 0x40);
        memcpy_bytes_0803F63C(&gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D], &gSpriteEntries[j + 0x27], 0x40);
        clear_sprite_table_mask(j + 0x24, 4);
        gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5A].unk23 = 0;
        gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5B].unk23 = 0;
        gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5C].unk23 = 0;
        gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk23 = 0;
        sprite_enable_affine_unit_scale(gUnk_03001800.unk60 + 0x72 + i);
    }
    play_sound_effect(0x34);
    gUnk_03001800.unkAA++;
}

void medaforce_pushover_attack_target_hop(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i, j;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        count++;
        if (gSpriteEntries[0x21 + i].unk0 & 0x8000) {
            if (advance_sprite_anim_frame(0x21 + i, 0))
                clear_battle_sprite_slot(0x21 + i, 1);
            else if (!(gUnk_03001800.unkF8 & 1)) {
                gSpriteEntries[0x21 + i].unk2--;
                gSpriteEntries[0x21 + i].unk18 = (gSpriteEntries[0x21 + i].unk18 - 0x10) & 0x3FF;
            } else {
                gSpriteEntries[0x21 + i].unk2++;
                gSpriteEntries[0x21 + i].unk18 = (gSpriteEntries[0x21 + i].unk18 + 0x10) & 0x3FF;
            }
        }
        sprite_hop_step((gUnk_03001800.unk60 + i) * 4 + 0x5A);
        sprite_hop_step((gUnk_03001800.unk60 + i) * 4 + 0x5B);
        sprite_hop_step((gUnk_03001800.unk60 + i) * 4 + 0x5C);
        done += sprite_hop_step((gUnk_03001800.unk60 + i) * 4 + 0x5D);
        if (gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk23 == 0x10) {
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5A].unk4 += 8;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5B].unk4 -= 8;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5C].unk4 -= 8;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 -= 8;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5A].unk0 |= 0x2000;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5B].unk0 |= 0x2000;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5C].unk0 |= 0x2000;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk0 |= 0x2000;
        }
        check_sprite_overlap_and_adjust((gUnk_03001800.unk60 + i) * 4 + 0x5D, gUnk_03001800.unk60 + (j = i + 0x72));
    }
    if (done == count) {
        for (i = 0; i <= 2; i++) {
            if (gUnk_03001800.unkD2[i])
                sprite_disable_affine((j = i + 0x72) + gUnk_03001800.unk60);
        }
        play_sound_effect(0x41);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_pushover_attack_burst_spawn(void) {
    u32 i, j;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        for (j = 0; j < 4; j++) {
            gSpriteEntries[0x30 + j + i * 4].unk0 = 0xC404;
            gSpriteEntries[0x30 + j + i * 4].unk1C = 0;
            gSpriteEntries[0x30 + j + i * 4].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5A].unk2;
            gSpriteEntries[0x30 + j + i * 4].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5A].unk4 + 4;
            gSpriteEntries[0x30 + j + i * 4].unkA = 7;
            gSpriteEntries[0x30 + j + i * 4].unkB = 0xF0;
            gSpriteEntries[0x30 + j + i * 4].unk24 = 6;
            gSpriteEntries[0x30 + j + i * 4].unk25 = gBurstSpriteDirections[j];
            gSpriteEntries[0x30 + j + i * 4].unk6 = 0x4D01;
        }
    }
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void medaforce_pushover_attack_burst(void) {
    u32 i, j;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        for (j = 0; j < 4; j++)
            update_sprite_animation_position(0x30 + j + i * 4);
    }
    if (gUnk_03000440.unk84 == 0x10) {
        for (i = 0; i <= 2; i++) {
            if (gUnk_03001800.unkD2[i] == 0)
                continue;
            memcpy_bytes_0803F63C(&gSpriteEntries[0x24 + i * 4], &gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5A],
                                  0x40);
            memcpy_bytes_0803F63C(&gSpriteEntries[0x25 + i * 4], &gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5B],
                                  0x40);
            memcpy_bytes_0803F63C(&gSpriteEntries[0x26 + i * 4], &gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5C],
                                  0x40);
            memcpy_bytes_0803F63C(&gSpriteEntries[0x27 + i * 4], &gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D],
                                  0x40);
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5A].unk0 |= 0x8000;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5B].unk0 |= 0x8000;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5C].unk0 |= 0x8000;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk0 |= 0x8000;
        }
        clear_battle_sprite_slot(0x21, 0x1B);
        gUnk_03001800.unkAA++;
    } else
        gUnk_03000440.unk84++;
}

void apply_battle_damage_and_render(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unkBD & 4)
            battle_set_damage_vs_armor(gUnk_03001800.unk60 + i, 0, 1);
        else
            battle_set_damage_vs_armor(gUnk_03001800.unk60 + i, 0, gUnk_03001800.unkEC);
        gUnk_03001800.unkD6[i] = gUnk_03001800.unkC8;
        switch (i) {
        case 0:
            set_display_digit_type(gUnk_03000440.unk9E, gUnk_03001800.unkC8, 1);
            battle_number_popup_init_slot(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
            break;
        case 1:
            set_display_digit_type(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkC8, 1);
            battle_number_popup_init_slot(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
            break;
        case 2:
            set_display_digit_type(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unkC8, 1);
            battle_number_popup_init_slot(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
            break;
        }
    }
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void medaforce_pushover_attack_damage_popup_wait(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            switch (i) {
            case 0:
                battle_popup_update_slot(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
                break;
            case 1:
                battle_popup_update_slot(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
                break;
            case 2:
                battle_popup_update_slot(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
                break;
            }
        }
    }
    gUnk_03000440.unk84++;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1) && gUnk_03000440.unk84 > 0x32)
        gUnk_03000440.unk84 = 0x78;
    if (gUnk_03000440.unk84 == 0x78) {
        for (i = 0; i <= 2; i++) {
            if (gUnk_03001800.unkD2[i])
                clear_battle_sprite_slot((gUnk_03001800.unk60 + i) * 4 + 0x21, 4);
        }
        gUnk_03001800.unkAA++;
    }
}

void apply_battle_damage_to_team(void) {
    u32 defeated = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        reduce_bot_part_stat(gUnk_03001800.unk60 + i, 0, gUnk_03001800.unkD6[i]);
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0) {
            add_bot_to_defeated_list(gUnk_03001800.unk60 + i);
            gUnk_03001800.unkD2[i] = 0x80;
            defeated = 1;
        } else if (!(gUnk_03000590[gUnk_03001800.unk60 + i].unkBD & 4))
            gUnk_03000590[gUnk_03001800.unk60 + i].unkBD |= 1;
    }
    if (defeated)
        gUnk_03001800.unkAA = 0x10;
    else
        gUnk_03001800.unkAA++;
}

void medaforce_pushover_attack_finish(void) {
    gUnk_03001800.unkA6 = 0x42;
    gUnk_03001800.unkAA++;
}

// Opcode 0x63: Useless (Medaforce 0x29).
void medaforce_useless_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceUselessSteps[gUnk_03001800.unkAA]();
}

void medaforce_useless_begin(void) {
    lz_decompress_dispatch(gUnk_084E0360, (void *)0x06014800);
    CpuFastSet(gUnk_0850EE98, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = 0x78;
    gSpriteEntries[0x21].unk4 = 0x40;
    gSpriteEntries[0x21].unk8 = 4;
    gSpriteEntries[0x21].unk9 = 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk6 = 0x7E00;
    play_sound_effect(0x6E);
    gUnk_03001800.unkAA++;
}

void medaforce_useless_find_targets(void) {
    u32 found = 0;
    u32 i;

    medaforce_clear_hit_list();
    gUnk_03001800.unk60 = battle_enemy_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 &&
            battle_bot_lacks_stability(gUnk_03001800.unk60 + i)) {
            gUnk_03001800.unkD2[i] = (s8)bot_random_intact_part(gUnk_03001800.unk60 + i) - 0x80;
            found = 1;
        }
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 3;
}

void medaforce_useless_orbs_spawn(void) {
    u32 i;

    clear_battle_sprite_slot(0x21, 1);
    lz_decompress_dispatch(gUnk_084D651C, (void *)0x06014800);
    CpuFastSet(gUnk_0850E858, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk0 = 0xC624;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = 0x78;
        gSpriteEntries[0x21 + i].unk4 = 0x40;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        gSpriteEntries[0x21 + i].unk8 = 0x40;
        gSpriteEntries[0x21 + i].unk9 = 0x40;
        gSpriteEntries[0x21 + i].unk18 = 0;
        gSpriteEntries[0x21 + i].unk30 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk32 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unk24 = 6;
        gSpriteEntries[0x21 + i].unk6 = 0x4E00;
    }
    gUnk_03001800.unkAA++;
}

void medaforce_useless_orbs_fly(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            if (!(gUnk_03001800.unkF8 & 1))
                gSpriteEntries[0x21 + i].unk18 = (gSpriteEntries[0x21 + i].unk18 - 0x40) & 0x3FF;
            else
                gSpriteEntries[0x21 + i].unk18 = (gSpriteEntries[0x21 + i].unk18 + 0x40) & 0x3FF;
            if (move_sprite_toward_target(0x21 + i))
                done++;
        }
    }
    if (done == count) {
        struct SpriteEntry *spr;
        s16 *p;

        for (i = 0, spr = gSpriteEntries; i <= 2; i++) {
            if (gUnk_03001800.unkD2[i] == 0)
                continue;
            clear_sprite_table_mask(0x21 + i, 1);
            gSpriteEntries[0x24 + i].unk0 = 0xC404;
            spr[0x24 + i].unk1C = 0;
            p = &gSpriteEntries[0x21 + i].unk2;
            gSpriteEntries[0x24 + i].unk2 = p[0];
            spr[0x24 + i].unk4 = p[1];
            spr[0x24 + i].unkA = 7;
            spr[0x24 + i].unkB = 0xE0;
            spr[0x24 + i].unk18 = 0;
            spr[0x24 + i].unk23 = 0;
            switch (gUnk_03001800.unkD2[i] & 0x7F) {
            case 1:
                gSpriteEntries[0x24 + i].unk6 = 0x4E02;
                break;
            case 2:
                gSpriteEntries[0x24 + i].unk6 = 0x4E03;
                break;
            default:
                spr[0x24 + i].unk6 = 0x4E01;
                break;
            }
        }
        play_sound_effect(0x6A);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_useless_part_icons_wait(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            if (advance_sprite_anim_frame(0x24 + i, 0))
                done++;
        }
    }
    if (done == count) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

// guess: sprite meaning unsure; set affine flags, scale 0x80 on target marks

void medaforce_useless_marks_scale_init(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            set_sprite_hidden_flags(0x21 + i, 1);
            gSpriteEntries[0x21 + i].unk0 |= 0x220;
            gSpriteEntries[0x21 + i].unk8 = 0x80;
            gSpriteEntries[0x21 + i].unk9 = 0x80;
            gSpriteEntries[0x21 + i].unk18 = 0;
        }
    }
    gUnk_03001800.unkAA++;
}

void medaforce_useless_marks_shrink(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            if (gSpriteEntries[0x21 + i].unk8 == 0x40)
                done++;
            else {
                gSpriteEntries[0x21 + i].unk8 -= 8;
                gSpriteEntries[0x21 + i].unk9 -= 8;
            }
        }
    }
    if (done == count) {
        play_sound_effect(0x3C);
        gUnk_03000440.unk86 = 0;
        gUnk_03001800.unkAA++;
    }
}

// guess: sprite meaning unsure; jitter marks x +/-2 for 0x3C frames, then clear sprites

void medaforce_useless_marks_shake(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            if (gUnk_03000440.unk86 & 4)
                gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2 - 2;
            else
                gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2 + 2;
        }
    }
    if (gUnk_03000440.unk86 == 0x3C) {
        clear_battle_sprite_slot(0x21, 6);
        gUnk_03001800.unkAA++;
    } else
        gUnk_03000440.unk86++;
}

void medaforce_useless_apply_impair(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 = 0x2B;
        gUnk_03000590[gUnk_03001800.unk60 + i].unkCB = clamp_1_99(gUnk_03001800.unkE8);
        gUnk_03000590[gUnk_03001800.unk60 + i].unkCC = clamp_1_99(gUnk_03001800.unkEC);
        switch (gUnk_03001800.unkD2[i] & 0x7F) {
        case 1:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 2;
            break;
        case 2:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 3;
            break;
        default:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 1;
            break;
        }
    }
    gUnk_03001800.unkAA++;
}

void medaforce_useless_finish(void) {
    gUnk_03001800.unkA6 = 0x5E;
    gUnk_03001800.unkAA++;
}

// Opcode 0x64: Destroyer (Medaforce 0x2A).
void medaforce_destroyer_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceDestroyerSteps[gUnk_03001800.unkAA]();
}

void medaforce_destroyer_begin(void) {
    lz_decompress_dispatch(gUnk_084E046C, (void *)0x06014800);
    CpuFastSet(gUnk_0850EEB8, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC404;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk4 = 0xE0;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x21].unk2 = 0xB8;
    else
        gSpriteEntries[0x21].unk2 = 0x40;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x69], 0x21);
    gUnk_03001800.unkAA++;
}

void medaforce_destroyer_descend(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x69], 0x21);
    if (gSpriteEntries[0x21].unk4 == 0x40) {
        gUnk_03000440.unk86 = 0;
        gSpriteEntries[0x21].unk25 = 0x14;
        gSpriteEntries[0x21].unk24 = 0;
        gSpriteEntries[0x21].unk28 = 0;
        gSpriteEntries[0x21].unk23 = 0;
        gUnk_03001800.unkAA++;
    } else
        gSpriteEntries[0x21].unk4 = (gSpriteEntries[0x21].unk4 + 1) & 0xFF;
}

// guess: sprite meaning unsure; follow path table gUnk_083AE988; at end clear sprite, goto step 10 (brighten)

void medaforce_destroyer_swing(void) {
    const u8 *tbl;

    if ((gUnk_03000440.unk86 & 0x1F) == 0 && gSpriteEntries[0x21].unk23 <= 7) {
        gUnk_03001800.unkAA++;
        gUnk_03000440.unk86++;
        return;
    }
    gUnk_03000440.unk86++;
    process_sprite_anim_commands(gUnk_083B5F80[0x69], 0x21);
    update_sprite_animation_position(0x21);
    gSpriteEntries[0x21].unk24 = 4;
    if (gSpriteEntries[0x21].unk28) {
        gSpriteEntries[0x21].unk28--;
        return;
    }
    tbl = gUnk_083AE988;
    gSpriteEntries[0x21].unk25 = tbl[gSpriteEntries[0x21].unk23 * 2];
    if (gSpriteEntries[0x21].unk25 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA = 0xA;
        return;
    }
    if (gUnk_03001800.unkF8 & 1)
        gSpriteEntries[0x21].unk25 = (0x20 - gSpriteEntries[0x21].unk25) & 0x1F;
    gSpriteEntries[0x21].unk28 = gUnk_083AE988[gSpriteEntries[0x21].unk23 * 2 + 1];
    gSpriteEntries[0x21].unk23++;
}

void medaforce_destroyer_flash_begin(void) {
    gSpriteEntries[0x21].unk6 = 0x7F02;
    play_sound_effect(0x38);
    gUnk_03001800.unkAA++;
}

void medaforce_destroyer_flash_white(void) {
    bg_palettes_blend_masked_now(0x7FFF, gUnk_03000440.unk84, 0xFFFF);
    obj_palettes_blend_masked_now(0x7FFF, gUnk_03000440.unk84, 0xFF00);
    if (gUnk_03000440.unk84 == 0x20)
        gUnk_03001800.unkAA++;
    else
        gUnk_03000440.unk84 += 2;
}

void medaforce_destroyer_flash_fade(void) {
    bg_palettes_blend_masked_now(0x1084, gUnk_03000440.unk84, 0xFFFF);
    obj_palettes_blend_masked_now(0x1084, gUnk_03000440.unk84, 0xFF00);
    if (gUnk_03000440.unk84 == 0x10)
        gUnk_03001800.unkAA++;
    else
        gUnk_03000440.unk84 -= 2;
}

void medaforce_destroyer_goto_swing(void) {
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x69], 0x21);
    gUnk_03001800.unkAA = 4;
}

void medaforce_destroyer_find_targets(void) {
    u32 found = 0;
    u32 i;

    medaforce_clear_hit_list();
    gUnk_03001800.unk60 = battle_enemy_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 &&
            (gUnk_03000590[gUnk_03001800.unk60 + i].unkBD & 4)) {
            gUnk_03001800.unkD2[i] = 1;
            found = 1;
        }
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 2;
}

void medaforce_destroyer_marks_spawn(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk0 = 0xC624;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unk8 = 0x80;
        gSpriteEntries[0x21 + i].unk9 = 0x80;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        gSpriteEntries[0x21 + i].unk6 = 0x7F03;
    }
    play_sound_effect(0x54);
    gUnk_03001800.unkAA++;
}

void medaforce_destroyer_marks_shrink(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            if (gSpriteEntries[0x21 + i].unk8 == 0x40)
                done = 1;
            else {
                gSpriteEntries[0x21 + i].unk8 -= 8;
                gSpriteEntries[0x21 + i].unk9 -= 8;
            }
        }
    }
    if (done) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void medaforce_destroyer_set_message(void) {
    clear_battle_sprite_slot(0x21, 3);
    gUnk_03001800.unkA6 = 0x43;
    gUnk_03001800.unkAA++;
}

void medaforce_destroyer_apply_damage(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03001800.unkD2[i] = get_random_battle_weight_entry(gUnk_03001800.unk60 + i);
        battle_set_damage_vs_armor(gUnk_03001800.unk60 + i, gUnk_03001800.unkD2[i], 0xC8);
        gUnk_03001800.unkD2[i] |= gUnk_03001800.unkD1 << 7;
        gUnk_03001800.unkD6[i] = gUnk_03001800.unkC8;
        gUnk_03000590[gUnk_03001800.unk60 + i].parts[gUnk_03001800.unkD2[i] & 0x7F].unk11 -= gUnk_03001800.unkD6[i];
        bot_halve_broken_leg_stats(gUnk_03001800.unk60 + i);
        if ((gUnk_03001800.unkD2[i] & 0x7F) == 0 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            add_bot_to_defeated_list(gUnk_03001800.unk60 + i);
    }
    gUnk_03001800.unkAA++;
}

void medaforce_destroyer_damage_popups_init(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            switch (i) {
            case 0:
                set_display_digit_type(gUnk_03000440.unk9E, gUnk_03001800.unkD6[i], 1);
                battle_number_popup_init_slot(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
                break;
            case 1:
                set_display_digit_type(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkD6[1], 1);
                battle_number_popup_init_slot(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
                break;
            case 2:
                set_display_digit_type(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unkD6[2], 1);
                battle_number_popup_init_slot(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
                break;
            }
        }
    }
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void medaforce_destroyer_damage_popups_wait(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            switch (i) {
            case 0:
                battle_popup_update_slot(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
                break;
            case 1:
                battle_popup_update_slot(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
                break;
            case 2:
                battle_popup_update_slot(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
                break;
            }
        }
    }
    gUnk_03000440.unk84++;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1) && gUnk_03000440.unk84 > 0x32)
        gUnk_03000440.unk84 = 0x78;
    if (gUnk_03000440.unk84 == 0x78) {
        clear_battle_sprite_slot(gUnk_03001800.unk60 * 4 + 0x21, 0xC);
        gUnk_03001800.unkAA++;
    }
}

// Opcode 0x65: Crazy Medaforce (Medaforce 0x2C).
void medaforce_crazy_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceCrazySteps[gUnk_03001800.unkAA]();
}

void medaforce_crazy_find_targets(void) {
    u32 i;

    medaforce_clear_hit_list();
    gUnk_03001800.unk60 = battle_enemy_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11) {
            gUnk_03001800.unkD2[i] = 1;
            gUnk_03001800.unkD6[i] = gUnk_03000590[gUnk_03001800.unk60 + i].unkC1;
        }
    }
    gUnk_03001800.unkAA++;
}

void medaforce_crazy_orbs_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084D6F88, (void *)0x06014800);
    CpuFastSet(gUnk_0850E938, (void *)0x050002E0, 0x10);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0xA + i].unk0 = 0xC624;
        gSpriteEntries[0xA + i].unk1C = 0;
        gSpriteEntries[0xA + i].unk2 = 0x78;
        gSpriteEntries[0xA + i].unk4 = 0x40;
        gSpriteEntries[0xA + i].unk8 = 4;
        gSpriteEntries[0xA + i].unk9 = 4;
        gSpriteEntries[0xA + i].unk18 = 0;
        gSpriteEntries[0xA + i].unk30 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0xA + i].unk32 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0xA + i].unk24 = 6;
        gSpriteEntries[0xA + i].unk23 = 0;
        gSpriteEntries[0xA + i].unkA = 7;
        gSpriteEntries[0xA + i].unkB = 0xE0;
        gUnk_03000440.unk84 = 0x48;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03000440.unk84], i + 0xA);
    }
    play_sound_effect(0x6A);
    gUnk_03001800.unkAA++;
}

void medaforce_crazy_orbs_grow(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            if (gSpriteEntries[0xA + i].unk8 == 0x40)
                done = 1;
            else {
                gSpriteEntries[0xA + i].unk8 += 4;
                gSpriteEntries[0xA + i].unk9 += 4;
            }
        }
    }
    if (done) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void medaforce_crazy_orbs_fly(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            if (!(gUnk_03001800.unkF8 & 1))
                gSpriteEntries[0xA + i].unk18 = (gSpriteEntries[0xA + i].unk18 - 0x40) & 0x3FF;
            else
                gSpriteEntries[0xA + i].unk18 = (gSpriteEntries[0xA + i].unk18 + 0x40) & 0x3FF;
            if (move_sprite_toward_target(0xA + i)) {
                gSpriteEntries[0xA + i].unk18 = 0;
                done++;
            }
        }
    }
    if (done == count) {
        for (i = 0; i <= 2; i++) {
            if (gUnk_03001800.unkD2[i] && gUnk_03001800.unkD6[i])
                play_sound_effect(0x51);
        }
        gUnk_03001800.unkAA++;
    }
}

void medaforce_crazy_drain_anim_wait(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            if (gUnk_03001800.unkD6[i] == 0)
                done++;
            else {
                process_sprite_anim_commands(gUnk_083B5F80[gUnk_03000440.unk84], 0xA + i);
                if (gSpriteEntries[0xA + i].unk22 == 0xFF)
                    done++;
            }
        }
    }
    if (done == count)
        gUnk_03001800.unkAA++;
}

void medaforce_crazy_orbs_target_user(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            gSpriteEntries[0xA + i].unk30 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
            gSpriteEntries[0xA + i].unk32 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
            gSpriteEntries[0xA + i].unk23 = 0;
        }
    }
    gUnk_03001800.unkAA++;
}

void medaforce_crazy_orbs_return(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            if (gUnk_03001800.unkF8 & 1)
                gSpriteEntries[0xA + i].unk18 = (gSpriteEntries[0xA + i].unk18 - 0x40) & 0x3FF;
            else
                gSpriteEntries[0xA + i].unk18 = (gSpriteEntries[0xA + i].unk18 + 0x40) & 0x3FF;
            if (move_sprite_toward_target(0xA + i)) {
                gSpriteEntries[0xA + i].unk18 = 0;
                done++;
            }
        }
    }
    if (done == count) {
        play_sound_effect(0x2B);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_crazy_orbs_shrink(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            if (gSpriteEntries[0xA + i].unk8 == 2) {
                done = 1;
                clear_battle_sprite_slot(0xA + i, 1);
            } else {
                gSpriteEntries[0xA + i].unk8 -= 2;
                gSpriteEntries[0xA + i].unk9 -= 2;
            }
        }
    }
    if (done)
        gUnk_03001800.unkAA++;
}

void medaforce_crazy_shots_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084E1518, (void *)0x06017000);
    CpuFastSet(gUnk_0850EED8, (void *)0x050002E0, 8);
    lz_decompress_dispatch(gUnk_084C8AC4, (void *)0x06014E00);
    CpuFastSet(gUnk_084E3018, (void *)0x050002C0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk0 = ((gUnk_03001800.unk39[3] + 2) << 10) | 0xC004;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0x81;
        gSpriteEntries[0x21 + i].unk30 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk32 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unk24 = 6;
        gSpriteEntries[0x21 + i].unk23 = 0;
        gSpriteEntries[0x21 + i].unk29 = 1;
        if (gUnk_03001800.unkF8 & 1)
            gSpriteEntries[0x21 + i].unk0 |= 0x1000;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6A], 0x21 + i);
    }
    gUnk_03001800.unkAA++;
}

void medaforce_crazy_shots_wait(void) {
    if (particle_run_shot_handlers())
        gUnk_03001800.unkAA++;
}

void medaforce_crazy_set_message(void) {
    gUnk_03001800.unkA6 = 0x67;
    gUnk_03001800.unkAA++;
}

void medaforce_crazy_apply_damage(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03000590[gUnk_03001800.unk60 + i].unkC1 = 0;
        gUnk_03001800.unkD2[i] = get_random_battle_weight_entry(gUnk_03001800.unk60 + i);
        battle_set_damage_vs_armor(gUnk_03001800.unk60 + i, gUnk_03001800.unkD2[i], gUnk_03001800.unkD6[i]);
        gUnk_03001800.unkD2[i] |= gUnk_03001800.unkD1 << 7;
        gUnk_03001800.unkD6[i] = gUnk_03001800.unkC8;
        gUnk_03000590[gUnk_03001800.unk60 + i].parts[gUnk_03001800.unkD2[i] & 0x7F].unk11 -= gUnk_03001800.unkD6[i];
        bot_halve_broken_leg_stats(gUnk_03001800.unk60 + i);
        if ((gUnk_03001800.unkD2[i] & 0x7F) == 0 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            add_bot_to_defeated_list(gUnk_03001800.unk60 + i);
    }
    gUnk_03001800.unkAA++;
}

// Opcode 0x66: Medaforce Up (Medaforce 0x2D).
void medaforce_up_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceUpSteps[gUnk_03001800.unkAA]();
}

void medaforce_up_find_targets(void) {
    u32 i;

    medaforce_clear_hit_list();
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11)
            gUnk_03001800.unkD2[i] = 1;
    }
    gUnk_03001800.unkAA++;
}

void medaforce_up_sparkles_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084D6F88, (void *)0x06014800);
    CpuFastSet(gUnk_0850E938, (void *)0x050002E0, 0x10);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk0 = 0xC624;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unk8 = 0x80;
        gSpriteEntries[0x21 + i].unk9 = 0x80;
        gSpriteEntries[0x21 + i].unk18 = 0;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xE0;
        gUnk_03000440.unk84 = 0x48;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03000440.unk84], i + 0x21);
    }
    play_sound_effect(0x6A);
    gUnk_03001800.unkAA++;
}

void medaforce_up_sparkles_shrink(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            if (gSpriteEntries[0x21 + i].unk8 == 0x40)
                done = 1;
            else {
                gSpriteEntries[0x21 + i].unk8 -= 4;
                gSpriteEntries[0x21 + i].unk9 -= 4;
            }
        }
    }
    if (done) {
        play_sound_effect(0x51);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_up_sparkles_anim_wait(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            process_sprite_anim_commands(gUnk_083B5F80[gUnk_03000440.unk84], 0x21 + i);
            if (gSpriteEntries[0x21 + i].unk22 == 0xFF)
                done = 1;
        }
    }
    if (done) {
        gUnk_03000440.unk86 = 0x20;
        gUnk_03001800.unkAA++;
    }
}

void decrement_timer_and_decompress_sprite(void) {
    u32 i;

    if (gUnk_03000440.unk86) {
        gUnk_03000440.unk86--;
        return;
    }
    lz_decompress_dispatch(gUnk_084E17E0, (void *)0x06015400);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x24 + i].unk0 = 0xC624;
        gSpriteEntries[0x24 + i].unk1C = 0;
        gSpriteEntries[0x24 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x24 + i].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x24 + i].unk8 = 0x40;
        gSpriteEntries[0x24 + i].unk9 = 0x40;
        gSpriteEntries[0x24 + i].unk18 = 0;
        gSpriteEntries[0x24 + i].unkA = 6;
        gSpriteEntries[0x24 + i].unkB = 0xF0;
        gSpriteEntries[0x24 + i].unk23 = 0;
        gSpriteEntries[0x24 + i].unk6 = 0x8100;
    }
    play_sound_effect(0x2A);
    gUnk_03001800.unkAA++;
}

// guess: sprite meaning unsure; sprite_slide_x_step on icons 0x24+, timer 0x3C

void medaforce_up_arrows_slide_wait(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] && sprite_slide_x_step(0x24 + i, 0))
            done = 1;
    }
    if (done) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void medaforce_up_sprites_shrink(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            if (gSpriteEntries[0x21 + i].unk8 == 4)
                done = 1;
            else {
                gSpriteEntries[0x21 + i].unk8 -= 4;
                gSpriteEntries[0x21 + i].unk9 -= 4;
                gSpriteEntries[0x24 + i].unk8 -= 4;
                gSpriteEntries[0x24 + i].unk9 -= 4;
            }
        }
    }
    if (done) {
        clear_battle_sprite_slot(0x21, 6);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_up_apply_gauge_boost(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i])
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC0 |= 8;
    }
    gUnk_03001800.unkAA++;
}

void medaforce_up_finish(void) {
    gUnk_03001800.unkA6 = 0x68;
    gUnk_03001800.unkAA++;
}

// Opcode 0x67: Formation Orders (Medaforce 0x2E).
void medaforce_formation_orders_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceFormationOrdersSteps[gUnk_03001800.unkAA]();
}

void medaforce_formation_orders_begin(void) {
    lz_decompress_dispatch(gUnk_084D50DC, (void *)0x06015800);
    CpuFastSet(gUnk_0850E658, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC624;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
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

void medaforce_formation_orders_first_hop(void) {
    sprite_hop_step(0x21);
    if (gSpriteEntries[0x21].unk27 == 0x20) {
        gSpriteEntries[0x21].unk18 = 0;
        gUnk_03000440.unk84 = 1;
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

void medaforce_formation_orders_next_spawn(void) {
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk0 = 0xC604;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk1C = 0;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unkA = 7;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unkB = 0xF0;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk8 = 0x40;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk9 = 0x40;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk18 = 0;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk6 = 0x4100;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk23 = 0;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk27 = 0;
    play_sound_effect(0x29);
    gUnk_03001800.unkAA++;
}

void medaforce_formation_orders_next_hop(void) {
    sprite_hop_step(gUnk_03000440.unk84 + 0x21);
    if (gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk27 == 0x20) {
        clear_battle_sprite_slot(gUnk_03000440.unk84 + 0x21, 1);
        gSpriteEntries[0x21].unk8 += gUnk_03000440.unk84 << 4;
        gSpriteEntries[0x21].unk9 += gUnk_03000440.unk84 << 4;
        if (++gUnk_03000440.unk84 == 4)
            gUnk_03001800.unkAA++;
        else
            gUnk_03001800.unkAA = 2;
        return;
    }
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk18 =
            (gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk18 + 0x20) & 0x3FF;
    else
        gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk18 =
            (gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk18 - 0x20) & 0x3FF;
    if (!(gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk27 & 1)) {
        if (!(gUnk_03001800.unkF8 & 1))
            gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk2++;
        else
            gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk2--;
    }
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk27++;
}

void medaforce_formation_orders_target_user(void) {
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 4;
    gSpriteEntries[0x21].unk23 = 0;
    gUnk_03001800.unkAA++;
}

void medaforce_formation_orders_move(void) {
    if (move_sprite_toward_target(0x21)) {
        play_sound_effect(0x2B);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_formation_orders_shrink(void) {
    if (gSpriteEntries[0x21].unk8 == 4) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 4;
        gSpriteEntries[0x21].unk9 -= 4;
    }
}

void medaforce_formation_orders_burst_spawn(void) {
    lz_decompress_dispatch(gUnk_084DFC18, (void *)0x06014800);
    CpuFastSet(gUnk_0850EE38, (void *)0x050002E0, 0x10);
    gSpriteEntries[0x21].unk0 = 0xCC04;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x68], 0x21);
    play_sound_effect(0x2C);
    gUnk_03001800.unkAA++;
}

void medaforce_formation_orders_burst_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x68], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_formation_orders_apply_trap_boost(void) {
    add_u8_capped(&gUnk_03000590[gUnk_03001800.unk87].unkD0 + 5, gUnk_03001800.unkEC, 0xFF);
    gUnk_03001800.unkAA++;
}

void medaforce_formation_orders_finish(void) {
    gUnk_03001800.unkA6 = 0x51;
    gUnk_03001800.unkAA++;
}

// Opcode 0x68: Leg Crash (Medaforce 0x2F).
void medaforce_leg_crash_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceLegCrashSteps[gUnk_03001800.unkAA]();
}

void medaforce_leg_crash_find_targets(void) {
    u32 i;

    medaforce_clear_hit_list();
    gUnk_03001800.unk60 = battle_enemy_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11) {
            gUnk_03001800.unkD2[i] = 1;
            gUnk_03001800.unkD6[i] = gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].unk11;
        }
    }
    gUnk_03001800.unkAA++;
}

void medaforce_leg_crash_begin(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084E1884, (void *)0x06014800);
    CpuFastSet(gUnk_0850EEF8, (void *)0x050002E0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk0 = 0xC404;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = 0x78;
        gSpriteEntries[0x21 + i].unk4 = 0xF0;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        gSpriteEntries[0x21 + i].unk24 = 4;
        gSpriteEntries[0x21 + i].unk25 = 0;
        gSpriteEntries[0x21 + i].unk30 = 0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6D], 0x21 + i);
        if (gUnk_03001800.unkF8 & 1)
            gSpriteEntries[0x21 + i].unk0 |= 0x1000;
    }
    play_sound_effect(0x61);
    gUnk_03001800.unkAA++;
}

void medaforce_leg_crash_drop(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            if (sprite_move_toward_target(0x21 + i, gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4,
                                          gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 + 0x10)) {
                gSpriteEntries[0x21 + i].unk27 = 0;
                gSpriteEntries[0x21 + i].unk28 = 0;
                gSpriteEntries[0x21 + i].unk29 = 1;
                done++;
            }
        }
    }
    if (done == count) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void medaforce_leg_crash_sound(void) {
    play_sound_effect(0x22);
    gUnk_03001800.unkAA++;
}

void medaforce_leg_crash_sweep_wait(void) {
    if (particle_run_sweep_handlers())
        gUnk_03001800.unkAA++;
}

void medaforce_leg_crash_check_legs(void) {
    u32 found = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] && gUnk_03001800.unkD6[i])
            found = 1;
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 2;
}

void medaforce_leg_crash_apply_damage(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] && gUnk_03001800.unkD6[i]) {
            gUnk_03001800.unkD2[i] = 3;
            battle_set_damage_vs_armor(gUnk_03001800.unk60 + i, 3, gUnk_03001800.unkD6[i]);
            gUnk_03001800.unkD2[i] |= gUnk_03001800.unkD1 << 7;
            gUnk_03001800.unkD6[i] = gUnk_03001800.unkC8;
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[gUnk_03001800.unkD2[i] & 0x7F].unk11 -= gUnk_03001800.unkD6[i];
            bot_halve_broken_leg_stats(gUnk_03001800.unk60 + i);
        }
    }
    gUnk_03001800.unkAA++;
}

// Opcode 0x69: Protector (Medaforce 0x30).
void medaforce_protector_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceProtectorSteps[gUnk_03001800.unkAA]();
}

void medaforce_protector_begin(void) {
    lz_decompress_dispatch(gUnk_084E1B98, (void *)0x06014800);
    CpuFastSet(gUnk_0850EF18, (void *)0x050002C0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC404;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 0x1C;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk6 = 0x8300;
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x18;
    else
        gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18;
    gSpriteEntries[0x22].unk0 = 0xC404;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 0x1C;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = 0xF1;
    gSpriteEntries[0x22].unk6 = 0x8301;
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x22].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18;
    else {
        gSpriteEntries[0x22].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x18;
        gSpriteEntries[0x22].unk0 |= 0x1000;
    }
    gUnk_03000440.unk86 = 0;
    play_sound_effect(0x2B);
    gUnk_03001800.unkAA++;
}

void medaforce_protector_halves_close(void) {
    if (gUnk_03000440.unk86 == 0x18) {
        gUnk_03000440.unk86 = 0;
        gUnk_03001800.unkAA++;
        return;
    }
    gUnk_03000440.unk86++;
    if (!(gUnk_03001800.unkF8 & 1)) {
        gSpriteEntries[0x21].unk2++;
        gSpriteEntries[0x22].unk2--;
    } else {
        gSpriteEntries[0x21].unk2--;
        gSpriteEntries[0x22].unk2++;
    }
}

void medaforce_protector_halves_lower(void) {
    if (gUnk_03000440.unk86 == 0xC) {
        gUnk_03001800.unkAA++;
        return;
    }
    gUnk_03000440.unk86++;
    gSpriteEntries[0x21].unk4 += 2;
    gSpriteEntries[0x22].unk4 += 2;
}

void medaforce_protector_shield_spawn(void) {
    clear_battle_sprite_slot(0x21, 2);
    CpuFastSet(gUnk_0850EF18, (void *)0x050002C0, 0x10);
    gSpriteEntries[0x21].unk0 = 0xC624;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unk8 = 0x80;
    gSpriteEntries[0x21].unk9 = 0x80;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk6 = 0x8302;
    gUnk_03001800.unkAA++;
}

void medaforce_protector_shield_shrink(void) {
    if (gSpriteEntries[0x21].unk8 == 0x40) {
        play_sound_effect(0x54);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 8;
        gSpriteEntries[0x21].unk9 -= 8;
    }
}

void medaforce_protector_shield_grow(void) {
    if (gSpriteEntries[0x21].unk8 == 0x60)
        gUnk_03001800.unkAA++;
    else {
        gSpriteEntries[0x21].unk8 += 4;
        gSpriteEntries[0x21].unk9 += 4;
    }
}

void medaforce_protector_shield_settle(void) {
    if (gSpriteEntries[0x21].unk8 == 0x40) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 4;
        gSpriteEntries[0x21].unk9 -= 4;
    }
}

void medaforce_protector_shield_vanish(void) {
    if (gSpriteEntries[0x21].unk8 == 4) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 4;
        gSpriteEntries[0x21].unk9 -= 4;
    }
}

void medaforce_protector_apply_protect(void) {
    gUnk_03000590[gUnk_03001800.unk87].unkC0 |= 1;
    gUnk_03001800.unkAA++;
}

void medaforce_protector_finish(void) {
    gUnk_03001800.unkA6 = 0x4F;
    gUnk_03001800.unkAA++;
}

// Opcode 0x6A: Anti-Protection (Medaforce 0x31).
void medaforce_anti_protection_run(void) {
    gUnk_03001800.unkB5 = 0;
    gMedaforceAntiProtectionSteps[gUnk_03001800.unkAA]();
}

void medaforce_anti_protection_begin(void) {
    lz_decompress_dispatch(gUnk_084E1EA4, (void *)0x06014800);
    CpuFastSet(gUnk_0850EF18, (void *)0x050002C0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC404;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 0x1C;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk6 = 0x8400;
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x18;
    else
        gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18;
    gSpriteEntries[0x22].unk0 = 0xC404;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 0x1C;
    gSpriteEntries[0x22].unkA = 6;
    gSpriteEntries[0x22].unkB = 0xF0;
    gSpriteEntries[0x22].unk6 = 0x8401;
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x22].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x18;
    else
        gSpriteEntries[0x22].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18;
    gSpriteEntries[0x23].unk0 = 0xC404;
    gSpriteEntries[0x23].unk1C = 0;
    gSpriteEntries[0x23].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 0x1C;
    gSpriteEntries[0x23].unkA = 7;
    gSpriteEntries[0x23].unkB = 0xF1;
    gSpriteEntries[0x23].unk6 = 0x8402;
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x23].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18;
    else {
        gSpriteEntries[0x23].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x18;
        gSpriteEntries[0x23].unk0 |= 0x1000;
    }
    gSpriteEntries[0x24].unk0 = 0xC404;
    gSpriteEntries[0x24].unk1C = 0;
    gSpriteEntries[0x24].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 0x1C;
    gSpriteEntries[0x24].unkA = 7;
    gSpriteEntries[0x24].unkB = 0xF1;
    gSpriteEntries[0x24].unk6 = 0x8403;
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x24].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18;
    else {
        gSpriteEntries[0x24].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x18;
        gSpriteEntries[0x24].unk0 |= 0x1000;
    }
    gUnk_03000440.unk86 = 0;
    play_sound_effect(0x2B);
    gUnk_03001800.unkAA++;
}

void medaforce_anti_protection_pieces_close(void) {
    if (gUnk_03000440.unk86 == 0x18) {
        gUnk_03000440.unk86 = 0;
        gUnk_03001800.unkAA++;
        return;
    }
    gUnk_03000440.unk86++;
    if (!(gUnk_03001800.unkF8 & 1)) {
        gSpriteEntries[0x21].unk2++;
        gSpriteEntries[0x22].unk2++;
        gSpriteEntries[0x23].unk2--;
        gSpriteEntries[0x24].unk2--;
    } else {
        gSpriteEntries[0x21].unk2--;
        gSpriteEntries[0x22].unk2--;
        gSpriteEntries[0x23].unk2++;
        gSpriteEntries[0x24].unk2++;
    }
}

void medaforce_anti_protection_pieces_lower(void) {
    if (gUnk_03000440.unk86 == 0xC) {
        gUnk_03001800.unkAA++;
        return;
    }
    gUnk_03000440.unk86++;
    gSpriteEntries[0x21].unk4 += 2;
    gSpriteEntries[0x22].unk4 += 2;
    gSpriteEntries[0x23].unk4 += 2;
    gSpriteEntries[0x24].unk4 += 2;
}

void medaforce_anti_protection_break_spawn(void) {
    gSpriteEntries[0x25].unk0 = 0xC404;
    gSpriteEntries[0x25].unk1C = 0;
    gSpriteEntries[0x25].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x25].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x25].unkA = 7;
    gSpriteEntries[0x25].unkB = 0xF2;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6F], 0x25);
    if (gUnk_03001800.unkF8 & 1)
        gSpriteEntries[0x25].unk0 |= 0x1000;
    play_sound_effect(0x30);
    gUnk_03001800.unkAA++;
}

void medaforce_anti_protection_break_wait(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x6F], 0x25);
    if (gSpriteEntries[0x25].unk22 == 0xFF) {
        gUnk_03000440.unk86 = 0;
        clear_battle_sprite_slot(0x25, 1);
        gUnk_03001800.unkAA++;
    }
}

void medaforce_anti_protection_pieces_split(void) {
    if (gUnk_03000440.unk86 == 0x20) {
        gUnk_03000440.unk86 = 0;
        gUnk_03001800.unkAA++;
        return;
    }
    if (gUnk_03000440.unk86 & 1) {
        if (!(gUnk_03001800.unkF8 & 1)) {
            gSpriteEntries[0x21].unk2 = (gSpriteEntries[0x21].unk2 - 1) & 0x1FF;
            gSpriteEntries[0x22].unk2 = (gSpriteEntries[0x22].unk2 + 1) & 0x1FF;
            gSpriteEntries[0x23].unk2 = (gSpriteEntries[0x23].unk2 - 1) & 0x1FF;
            gSpriteEntries[0x24].unk2 = (gSpriteEntries[0x24].unk2 + 1) & 0x1FF;
        } else {
            gSpriteEntries[0x21].unk2 = (gSpriteEntries[0x21].unk2 + 1) & 0x1FF;
            gSpriteEntries[0x22].unk2 = (gSpriteEntries[0x22].unk2 - 1) & 0x1FF;
            gSpriteEntries[0x23].unk2 = (gSpriteEntries[0x23].unk2 + 1) & 0x1FF;
            gSpriteEntries[0x24].unk2 = (gSpriteEntries[0x24].unk2 - 1) & 0x1FF;
        }
    }
    gUnk_03000440.unk86++;
}

// guess: sprite meaning unsure; drift pieces vertically while flickering, then clear

void medaforce_anti_protection_pieces_scatter(void) {
    if (gUnk_03000440.unk86 == 0x20) {
        clear_battle_sprite_slot(0x21, 4);
        gUnk_03000440.unk86 = 0;
        gUnk_03001800.unkAA++;
        return;
    }
    if (!(gUnk_03000440.unk86 & 3)) {
        gSpriteEntries[0x21].unk4 = (gSpriteEntries[0x21].unk4 - 1) & 0xFF;
        gSpriteEntries[0x22].unk4 = (gSpriteEntries[0x22].unk4 + 1) & 0xFF;
        gSpriteEntries[0x23].unk4 = (gSpriteEntries[0x23].unk4 - 1) & 0xFF;
        gSpriteEntries[0x24].unk4 = (gSpriteEntries[0x24].unk4 + 1) & 0xFF;
    }
    if (gUnk_03000440.unk86 & 1) {
        gSpriteEntries[0x21].unk0 |= 0x8000;
        gSpriteEntries[0x22].unk0 |= 0x8000;
        gSpriteEntries[0x23].unk0 |= 0x8000;
        gSpriteEntries[0x24].unk0 |= 0x8000;
    } else {
        gSpriteEntries[0x21].unk0 &= 0x7FFF;
        gSpriteEntries[0x22].unk0 &= 0x7FFF;
        gSpriteEntries[0x23].unk0 &= 0x7FFF;
        gSpriteEntries[0x24].unk0 &= 0x7FFF;
    }
    gUnk_03000440.unk86++;
}

void medaforce_anti_protection_apply(void) {
    gUnk_03000590[gUnk_03001800.unk87].unkC0 |= 4;
    gUnk_03001800.unkAA++;
}

void medaforce_anti_protection_finish(void) {
    gUnk_03001800.unkA6 = 0x6A;
    gUnk_03001800.unkAA++;
}
