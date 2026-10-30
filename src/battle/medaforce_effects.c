// Medaforce effect sequences: action script opcodes 0x40-0x6A. A Medaforce runs script 0x50 + its id
// (animSkill = actorSkill[0] + 0x50, script_op_skill_anim_start), so scripts 80-131 use these; 0x45
// (side_add_action_point) and a few script-side commands sit elsewhere. Each runner (medaforce_*_run, clears stepDone
// and calls entry [step] of its gMedaforce*Steps table) is one action script command (gActionScriptCommands, opcode
// order = ROM order); its step handlers follow it and the last step sets stepDone. Runner names come from the Medaforce
// names (gMedaforceNames) of the scripts that use each opcode. Abilities are part data[1], and the script of ability n
// is gActionScripts[n].

#include "global.h"
#include "constants/battle_seq_sprites.h"
#include "constants/skill_sprites.h"
#include "constants/sprites.h"

// Opcode 0x40: Spiral Bolt (Medaforce 0), damage to all four parts of the target.
void medaforce_spiral_bolt_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceSpiralBoltSteps[gBattleWork.step]();
}

void medaforce_spiral_bolt_calc(void) {
    medaforce_calc_success(gBattleWork.actor);
    medaforce_calc_damage(gBattleWork.actor);
    gBattleWork.step++;
}

void medaforce_spiral_bolt_set_damage(void) {
    hit_list_set_part_damage(gBattleWork.target, 0, gBattleWork.amount);
    hit_list_set_part_damage(gBattleWork.target, 1, gBattleWork.amount);
    hit_list_set_part_damage(gBattleWork.target, 2, gBattleWork.amount);
    hit_list_set_part_damage(gBattleWork.target, 3, gBattleWork.amount);
    gBattleWork.step++;
}

void medaforce_spiral_bolt_digits_spawn(void) {
    s16 x, y;

    lz_decompress_dispatch(gDamageNumberTiles, (void *)OBJ_VRAM0);
    CpuFastSet(gDamageNumberPalette, (void *)0x050003C0, 8);
    if (!(gBattleWork.actorSideFlags & 2)) {
        x = gBattleWork.closeupRightX;
        y = gBattleWork.closeupRightY;
    } else {
        x = gBattleWork.closeupLeftX;
        y = gBattleWork.closeupLeftY;
    }
    set_display_digit_type(gGameWork.textBuf, gBattleWork.partDamage[0], 1);
    setup_battle_sprite_oam_entries(gGameWork.textBuf, 0xA, 0, x, y);
    set_display_digit_type(gGameWork.textBuf + 0x14, gBattleWork.partDamage[1], 1);
    setup_battle_sprite_oam_entries(gGameWork.textBuf + 0x14, 0xE, 1, x, y);
    set_display_digit_type(gGameWork.textBuf + 0x28, gBattleWork.partDamage[2], 1);
    setup_battle_sprite_oam_entries(gGameWork.textBuf + 0x28, 0x12, 2, x, y);
    set_display_digit_type(gGameWork.textBuf + 0x3C, gBattleWork.partDamage[3], 1);
    setup_battle_sprite_oam_entries(gGameWork.textBuf + 0x3C, 0x16, 3, x, y);
    play_sound_effect(0x5B);
    gBattleWork.step++;
}

void medaforce_spiral_bolt_digits_rise(void) {
    sprite_group_rise_step(gGameWork.textBuf, 0xA);
    sprite_group_rise_step(gGameWork.textBuf + 0x14, 0xE);
    sprite_group_rise_step(gGameWork.textBuf + 0x28, 0x12);
    if (sprite_group_rise_step(gGameWork.textBuf + 0x3C, 0x16)) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void medaforce_spiral_bolt_drain_armor(void) {
    s32 n;
    u32 side;

    n = armor_drain_step(&gBattleWork.partDamage[0], gBattleWork.target, 0);
    n += armor_drain_step(&gBattleWork.partDamage[1], gBattleWork.target, 1);
    n += armor_drain_step(&gBattleWork.partDamage[2], gBattleWork.target, 2);
    n += armor_drain_step(&gBattleWork.partDamage[3], gBattleWork.target, 3);
    if (!(gBattleWork.actorSideFlags & 2))
        side = 1;
    else
        side = 0;
    armor_panel_draw_bars(side, gBattleWork.target);
    armor_panel_draw_numbers(side, gBattleWork.target);
    if (n == 4) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void medaforce_spiral_bolt_break_burst_spawn(void) {
    u16 x, y;
    s32 shown = 0;

    lz_decompress_dispatch(gPartBreakBurstTiles, (void *)(OBJ_VRAM0 + 0x800));
    CpuFastSet(gPartBreakBurstPalette, (void *)0x050003C0, 8);
    if (!(gBattleWork.actorSideFlags & 2)) {
        x = gBattleWork.closeupRightX;
        y = gBattleWork.closeupRightY;
    } else {
        x = gBattleWork.closeupLeftX;
        y = gBattleWork.closeupLeftY;
    }
    if (gBattleWork.partBreaks[0]) {
        effect_sprite_spawn_at_part(0xA, 0, x, y, 0x1E);
        shown = 1;
    }
    if (gBattleWork.partBreaks[1]) {
        effect_sprite_spawn_at_part(0xB, 1, x, y, 0x1E);
        shown = 1;
    }
    if (gBattleWork.partBreaks[2]) {
        effect_sprite_spawn_at_part(0xC, 2, x, y, 0x1E);
        shown = 1;
    }
    if (gBattleWork.partBreaks[3]) {
        effect_sprite_spawn_at_part(0xD, 3, x, y, 0x1E);
        shown = 1;
    }
    if (shown) {
        bot_halve_broken_leg_stats(gBattleWork.target);
        gBattleWork.step = 0xD;
    } else {
        gBattleWork.step++;
    }
}

void medaforce_spiral_bolt_break_burst_wait(void) {
    s32 done = 0;

    if (gBattleWork.partBreaks[0]) {
        process_sprite_anim_commands(gBattleSpriteAnimScripts[0x1E], 0xA);
        if (gSpriteEntries[0xA].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
            done = 1;
    }
    if (gBattleWork.partBreaks[1]) {
        process_sprite_anim_commands(gBattleSpriteAnimScripts[0x1E], 0xB);
        if (gSpriteEntries[0xB].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
            done = 1;
    }
    if (gBattleWork.partBreaks[2]) {
        process_sprite_anim_commands(gBattleSpriteAnimScripts[0x1E], 0xC);
        if (gSpriteEntries[0xC].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
            done = 1;
    }
    if (gBattleWork.partBreaks[3]) {
        process_sprite_anim_commands(gBattleSpriteAnimScripts[0x1E], 0xD);
        if (gSpriteEntries[0xD].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
            done = 1;
    }
    if (done) {
        clear_battle_sprite_slot(0xA, 4);
        gBattleWork.step++;
    }
}

void medaforce_spiral_bolt_check_defeated(void) {
    if (gBattleBots[gBattleWork.target].parts[0].armor == 0)
        add_bot_to_defeated_list(gBattleWork.target);
    gBattleWork.step++;
}

// Opcode 0x44: the shared Medaforce hit on one part (Ultra Shot, Damage Ball, Life Drain, Shrapnel Attack,
// Unbreakable Will, Structureless, Dice Attack, Type Crash).
void medaforce_hit_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceHitSteps[gBattleWork.step]();
}

void medaforce_hit_check_nullified(void) {
    if (gBattleWork.blockResult & 2)
        gBattleWork.step = 0x20;
    else
        gBattleWork.step++;
}

void medaforce_hit_carry_over_retarget(void) {
    if (gBattleWork.overflowAmount) {
        battle_pick_random_target_part(gBattleWork.actor);
        battle_load_action_target(gBattleWork.actor);
        gBattleWork.damagePart = gBattleWork.targetPart;
        battle_set_damage_vs_armor(gBattleWork.target, gBattleWork.targetPart, gBattleWork.overflowAmount);
        gBattleWork.step += 3;
    } else {
        gBattleWork.step++;
    }
}

void medaforce_part_marker_spawn(void) {
    lz_decompress_dispatch(gCarryOverMarkerTiles, (void *)OBJ_VRAM0);
    CpuFastSet(gCarryOverMarkerPalette, (void *)0x050003C0, 8);
    gSpriteEntries[0xA].frame = 0x1500;
    play_sound_effect(0x2A);
    gSpriteEntries[0xA].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0xA].frame_table = 0;
    gSpriteEntries[0xA].palette = 0xE;
    gSpriteEntries[0xA].order = 0x80;
    gSpriteEntries[0xA].work[FX_SPR_STEP] = 0;
    if (!(gBattleWork.actorSideFlags & 2)) {
        if (gBattleWork.targetPart == 2)
            gSpriteEntries[0xA].x = gBattleWork.closeupRightX - 0x10;
        else
            gSpriteEntries[0xA].x = gBattleWork.closeupRightX;
        gSpriteEntries[0xA].y = gBattleWork.closeupRightY;
    } else {
        if (gBattleWork.targetPart == 1)
            gSpriteEntries[0xA].x = gBattleWork.closeupLeftX + 0x10;
        else
            gSpriteEntries[0xA].x = gBattleWork.closeupLeftX;
        gSpriteEntries[0xA].y = gBattleWork.closeupLeftY;
    }
    gBattleWork.step++;
}

void medaforce_hit_goto_sparks(void) {
    gBattleWork.step = 2;
}

// Opcode 0x48: Life Drain (Medaforce 0x14) heals the actor's most damaged part.
void medaforce_life_drain_heal_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceLifeDrainHealSteps[gBattleWork.step]();
}

void medaforce_life_drain_heal_find_part(void) {
    u32 part = find_most_damaged_part(gBattleWork.actor);
    if (part) {
        gBattleWork.targetPart = gBattleWork.damagePart = part - 1;
        gBattleWork.step = 2;
    } else {
        gBattleWork.step++;
    }
}

void medaforce_life_drain_heal_calc(void) {
    clear_battle_sprite_slot(0, 0x80);
    battle_calc_damage_split(gBattleWork.actor, gBattleWork.damagePart, gBattleWork.amount);
    gBattleWork.step++;
}

void medaforce_life_drain_heal_carry_over(void) {
    u32 part;
    struct BattleWork *work = &gBattleWork;
    if (work->overflowAmount && (part = find_most_damaged_part(work->target))) {
        part--;
        work->damagePart = part;
        work->targetPart = part;
        battle_calc_damage_split(work->actor, work->damagePart, work->overflowAmount);
        work->step = 0x10;
    } else {
        work->step++;
    }
}

void medaforce_life_drain_heal_goto_sparkle(void) {
    gBattleWork.step = 4;
}

// Opcode 0x50: Side Bolt (Medaforce 1), damage to all three opponents.
void medaforce_side_bolt_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceSideBoltSteps[gBattleWork.step]();
}

void medaforce_side_bolt_calc(void) {
    u32 i;
    struct BattleBot *bots;
    for (i = 0; i <= 2; i++) {
        gBattleWork.partBreaks[i] = 0;
        gBattleWork.partDamage[i] = 0;
    }
    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    i = 0;
    bots = gBattleBots;
    for (; i <= 2; i++) {
        u32 rec = gBattleWork.targetSideFirst + i;
        if (bots[rec].teamState && bots[rec].parts[0].armor) {
            gBattleWork.partBreaks[i] = get_random_battle_weight_entry(rec);
            battle_set_damage_vs_armor(gBattleWork.targetSideFirst + i, gBattleWork.partBreaks[i], gBattleWork.amount);
            gBattleWork.partBreaks[i] |= gBattleWork.partBroken << 7;
            gBattleWork.partDamage[i] = gBattleWork.appliedAmount;
        }
    }
    gBattleWork.step++;
}

// guess: sprite meaning unsure; two big scaled sprites (0x21/0x22) at screen centre

void medaforce_side_bolt_halves_spawn(void) {
    lz_decompress_dispatch(gMedaforceSideBoltTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceSideBoltPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE |
                                 SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = 0x78;
    gSpriteEntries[0x21].y = 0x30;
    gSpriteEntries[0x21].scale_x = 0x80;
    gSpriteEntries[0x21].scale_y = 0x80;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].frame = 0x6500;
    gSpriteEntries[0x22].flags = SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE |
                                 SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x22].frame_table = 0;
    gSpriteEntries[0x22].x = 0x78;
    gSpriteEntries[0x22].y = 0x50;
    gSpriteEntries[0x22].scale_x = 0x80;
    gSpriteEntries[0x22].scale_y = 0x80;
    gSpriteEntries[0x22].palette = 7;
    gSpriteEntries[0x22].order = 0xF0;
    gSpriteEntries[0x22].frame = 0x6501;
    gBattleWork.step++;
}

// guess: sprite meaning unsure; scale 0x80->0x40 one after the other, sfx 0x30

void medaforce_side_bolt_halves_shrink(void) {
    if (gSpriteEntries[0x21].scale_x != 0x40) {
        gSpriteEntries[0x21].scale_x -= 8;
        gSpriteEntries[0x21].scale_y -= 8;
        if (gSpriteEntries[0x21].scale_x == 0x40)
            play_sound_effect(0x30);
    } else {
        gSpriteEntries[0x22].flags |= SPRITE_FLAG_ENABLED;
        if (gSpriteEntries[0x22].scale_x != 0x40) {
            gSpriteEntries[0x22].scale_x -= 8;
            gSpriteEntries[0x22].scale_y -= 8;
            if (gSpriteEntries[0x22].scale_x == 0x40)
                play_sound_effect(0x30);
        } else {
            gGameWork.stepTimer = 0x3C;
            gBattleWork.step++;
        }
    }
}

void medaforce_side_bolt_bolt_spawn(void) {
    clear_battle_sprite_slot(0x21, 2);
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    if (gBattleWork.actorSideFlags & 2)
        gSpriteEntries[0x21].flags |= SPRITE_FLAG_HFLIP;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = 0x78;
    gSpriteEntries[0x21].y = 0x40;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x5A], 0x21);
    gBattleWork.step++;
}

void medaforce_side_bolt_bolt_anim_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x5A], 0x21);
    if (gSpriteEntries[0x21].work[SPR_CMD_STATE] == SPR_CMD_ENDED) {
        gGameWork.stepTimer = 0;
        play_sound_effect(0x73);
        gBattleWork.step++;
    }
}

void medaforce_side_bolt_slide(void) {
    gGameWork.stepTimer++;
    particle_slide_lead_sprite();
    if (gGameWork.stepTimer == 0x10) {
        palette_backup_from_hardware();
        gGameWork.stepCounter = 0;
        gBattleWork.step++;
    }
}

void medaforce_side_bolt_flash_in(void) {
    gGameWork.stepTimer++;
    particle_slide_lead_sprite();
    if (gGameWork.stepCounter <= 4) {
        bg_palettes_blend_masked_now(0x7FFF, gGameWork.stepCounter * 8, 0xFFFF);
        obj_palettes_blend_masked_now(0x7FFF, gGameWork.stepCounter * 8, 0xFFFF);
        gGameWork.stepCounter++;
    } else {
        gGameWork.stepCounter = 0;
        gBattleWork.step++;
    }
}

void medaforce_side_bolt_flash_out(void) {
    gGameWork.stepTimer++;
    particle_slide_lead_sprite();
    if (gGameWork.stepCounter <= 8) {
        bg_palettes_blend_masked_now(0x7FFF, 0x20 - gGameWork.stepCounter * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0x7FFF, 0x20 - gGameWork.stepCounter * 4, 0xFFFF);
        gGameWork.stepCounter++;
    } else {
        gBattleWork.step++;
    }
}

void medaforce_side_bolt_slide_end(void) {
    gGameWork.stepTimer++;
    particle_slide_lead_sprite();
    if (gGameWork.stepTimer > 0x23) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    }
}

void medaforce_side_bolt_set_message(void) {
    gBattleWork.messageId = 0x3A;
    gBattleWork.step++;
}

void medaforce_side_bolt_apply_damage(void) {
    u32 i;
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState &&
            gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor) {
            gBattleBots[gBattleWork.targetSideFirst + i].parts[gBattleWork.partBreaks[i] & 0x7F].armor -=
                gBattleWork.partDamage[i];
            bot_halve_broken_leg_stats(gBattleWork.targetSideFirst + i);
            if ((gBattleWork.partBreaks[i] & 0x7F) == 0 &&
                gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor == 0)
                add_bot_to_defeated_list(gBattleWork.targetSideFirst + i);
        }
    }
    gBattleWork.step++;
}

void medaforce_team_damage_popup_init(void) {
    u32 i;
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState) {
            switch (i) {
            case 0:
                set_display_digit_type(gGameWork.textBuf, gBattleWork.partDamage[i], 1);
                battle_number_popup_init_slot(gGameWork.textBuf, gBattleWork.targetSideFirst + i, 0x21);
                break;
            case 1:
                set_display_digit_type(gGameWork.textBuf + 0x14, gBattleWork.partDamage[1], 1);
                battle_number_popup_init_slot(gGameWork.textBuf + 0x14, gBattleWork.targetSideFirst + 1, 0x21);
                break;
            case 2:
                set_display_digit_type(gGameWork.textBuf + 0x28, gBattleWork.partDamage[2], 1);
                battle_number_popup_init_slot(gGameWork.textBuf + 0x28, gBattleWork.targetSideFirst + 2, 0x21);
                break;
            }
        }
    }
    play_sound_effect(0x5B);
    gGameWork.stepCounter = 0;
    gBattleWork.step++;
}

void medaforce_team_popup_wait(void) {
    u32 i;
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState) {
            switch (i) {
            case 0:
                battle_popup_update_slot(gGameWork.textBuf, gBattleWork.targetSideFirst + i, 0x21);
                break;
            case 1:
                battle_popup_update_slot(gGameWork.textBuf + 0x14, gBattleWork.targetSideFirst + 1, 0x21);
                break;
            case 2:
                battle_popup_update_slot(gGameWork.textBuf + 0x28, gBattleWork.targetSideFirst + 2, 0x21);
                break;
            }
        }
    }
    gGameWork.stepCounter++;
    if (gGameWork.skipBotSetup == 0 && (KEYS_LO(gRepeatKeys) & A_BUTTON) && gGameWork.stepCounter > 0x32)
        gGameWork.stepCounter = 0x78;
    if (gGameWork.stepCounter == 0x78) {
        clear_battle_sprite_slot(gBattleWork.targetSideFirst * 4 + 0x21, 0xC);
        gBattleWork.step++;
    }
}

void decompress_sprite_tiles_to_vram_obj_4800_alt(void) {
    u32 done = 0;
    u32 i;

    lz_decompress_dispatch(gBreakRingTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gBreakRingPalette, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] & 0x80) {
            staggered_sprites_spawn(
                i * 4 + 0x21,
                gSpriteEntries[BOT_SPRITE_HEAD((gBattleWork.targetSideFirst + i)) + (gBattleWork.partBreaks[i] & 0x7F)]
                    .x,
                gSpriteEntries[BOT_SPRITE_HEAD((gBattleWork.targetSideFirst + i)) + (gBattleWork.partBreaks[i] & 0x7F)]
                    .y,
                4);
            done = 1;
        }
    }
    if (!done)
        gBattleWork.step++;
    else
        gBattleWork.step += 3;
}

void medaforce_team_break_burst_wait(void) {
    u32 done = 0;
    u32 i;
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] & 0x80)
            done = staggered_sprites_update(i * 4 + 0x21, 4);
    }
    if (done)
        gBattleWork.step++;
}

void medaforce_team_break_anim_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gHitSparksTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gHitSparksPalette, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] & 0x80) {
            gSpriteEntries[i + 0x21].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
            gSpriteEntries[i + 0x21].frame_table = 0;
            gSpriteEntries[i + 0x21].x =
                gSpriteEntries[BOT_SPRITE_HEAD((gBattleWork.targetSideFirst + i)) + (gBattleWork.partBreaks[i] & 0x7F)]
                    .x;
            gSpriteEntries[i + 0x21].y =
                gSpriteEntries[BOT_SPRITE_HEAD((gBattleWork.targetSideFirst + i)) + (gBattleWork.partBreaks[i] & 0x7F)]
                    .y;
            gSpriteEntries[i + 0x21].palette = 7;
            gSpriteEntries[i + 0x21].order = 0xF0;
            battle_sprite_anim_init(gBattleSpriteAnimScripts[0x22], i + 0x21);
        }
    }
    gBattleWork.step++;
}

void medaforce_team_break_anim_wait(void) {
    u32 done = 0;
    u32 i;
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] & 0x80) {
            u8 slot;
            process_sprite_anim_commands(gBattleSpriteAnimScripts[0x22], slot = i + 0x21);
            if (gSpriteEntries[i + 0x21].work[SPR_CMD_STATE] == SPR_CMD_ENDED) {
                clear_battle_sprite_slot(slot, 1);
                done = 1;
            }
        }
    }
    if (done) {
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
        gBattleWork.step++;
    }
}

// Opcode 0x51: Optic / Bomb / Gravity Form and Absorb Optic / Bomb / Gravity (Medaforces 4-9).
void medaforce_form_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceFormSteps[gBattleWork.step]();
}

void medaforce_form_begin(void) {
    switch (gBattleBots[gBattleWork.actor].medaforce[0]) {
    case 4:
        gBattleWork.scratch = 0;
        break;
    case 5:
        gBattleWork.scratch = 1;
        break;
    case 6:
        gBattleWork.scratch = 2;
        break;
    case 7:
        gBattleWork.scratch = 3;
        break;
    case 8:
        gBattleWork.scratch = 4;
        break;
    default:
        gBattleWork.scratch = 5;
        break;
    }
    gBattleWork.step++;
}

void medaforce_form_emblem_spawn(void) {
    lz_decompress_dispatch(gMedaforceFormEmblemTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gEffectCommonPalette, (void *)0x050002C0, 8);
    switch (gBattleBots[gBattleWork.actor].medaforce[0]) {
    case 4:
    case 5:
        lz_decompress_dispatch(gMedaforceOpticFormTiles, (void *)(OBJ_VRAM0 + 0x4C00));
        CpuFastSet(gMedaforceOpticFormPalette, (void *)0x050002E0, 8);
        play_sound_effect(0x27);
        break;
    case 6:
    case 7:
        lz_decompress_dispatch(gMedaforceBombFormTiles, (void *)(OBJ_VRAM0 + 0x4C00));
        CpuFastSet(gMedaforceBombFormPalette, (void *)0x050002E0, 8);
        play_sound_effect(0x45);
        break;
    case 8:
    default:
        lz_decompress_dispatch(gMedaforceGravityFormTiles, (void *)(OBJ_VRAM0 + 0x4C00));
        CpuFastSet(gMedaforceGravityFormPalette, (void *)0x050002E0, 8);
        play_sound_effect(0x33);
        break;
    }
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x;
    gSpriteEntries[0x21].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].palette = 6;
    gSpriteEntries[0x21].order = 0xF0;
    if (gBattleWork.scratch & 1)
        gSpriteEntries[0x21].frame = 0x6601;
    else
        gSpriteEntries[0x21].frame = 0x6600;
    gGameWork.stepTimer = 0;
    gBattleWork.step++;
}

void medaforce_form_emblem_spin(void) {
    gGameWork.stepTimer++;
    gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle + 0x40) & 0x3FF;
    if (gGameWork.stepTimer > 0x3C)
        gBattleWork.step++;
}

void medaforce_form_ring_spawn(void) {
    gGameWork.stepTimer++;
    gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle + 0x40) & 0x3FF;
    gSpriteEntries[0x22].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE |
                                 SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x22].frame_table = 0;
    gSpriteEntries[0x22].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x;
    gSpriteEntries[0x22].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x22].scale_x = 0x80;
    gSpriteEntries[0x22].scale_y = 0x80;
    gSpriteEntries[0x22].palette = 7;
    gSpriteEntries[0x22].order = 0xF1;
    gSpriteEntries[0x22].frame = 0x6700;
    gBattleWork.step++;
}

void medaforce_form_ring_shrink(void) {
    gGameWork.stepTimer++;
    gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle + 0x40) & 0x3FF;
    if (gSpriteEntries[0x22].scale_x == 0x40) {
        play_sound_effect(0x30);
        gGameWork.stepCounter = 0x3C;
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x22].scale_x -= 8;
        gSpriteEntries[0x22].scale_y -= 8;
    }
}

void medaforce_form_hold(void) {
    gGameWork.stepTimer++;
    gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle + 0x40) & 0x3FF;
    if (gGameWork.skipBotSetup == 0 && (KEYS_LO(gRepeatKeys) & A_BUTTON)) {
        play_sound_effect(0x2B);
        gBattleWork.step++;
    } else if (gGameWork.stepCounter) {
        gGameWork.stepCounter--;
    } else {
        play_sound_effect(0x2B);
        gBattleWork.step++;
    }
}

void medaforce_form_shrink_out(void) {
    gGameWork.stepTimer++;
    gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle + 0x40) & 0x3FF;
    if (gSpriteEntries[0x21].scale_x == 4) {
        clear_battle_sprite_slot(0x21, 2);
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x -= 4;
        gSpriteEntries[0x21].scale_y -= 4;
        gSpriteEntries[0x22].scale_x -= 4;
        gSpriteEntries[0x22].scale_y -= 4;
    }
}

void medaforce_form_apply(void) {
    switch (gBattleBots[gBattleWork.actor].medaforce[0]) {
    case 4:
        gBattleBots[gBattleWork.actor].formFlags |= 1;
        break;
    case 5:
        gBattleBots[gBattleWork.actor].formFlags |= 8;
        break;
    case 6:
        gBattleBots[gBattleWork.actor].formFlags |= 2;
        break;
    case 7:
        gBattleBots[gBattleWork.actor].formFlags |= 0x10;
        break;
    case 8:
        gBattleBots[gBattleWork.actor].formFlags |= 4;
        break;
    default:
        gBattleBots[gBattleWork.actor].formFlags |= 0x20;
        break;
    }
    gBattleWork.step++;
}

void medaforce_form_set_message(void) {
    switch (gBattleBots[gBattleWork.actor].medaforce[0]) {
    case 4:
        gBattleWork.messageId = 0x4A;
        break;
    case 5:
        gBattleWork.messageId = 0x61;
        break;
    case 6:
        gBattleWork.messageId = 0x4B;
        break;
    case 7:
        gBattleWork.messageId = 0x62;
        break;
    case 8:
        gBattleWork.messageId = 0x4C;
        break;
    default:
        gBattleWork.messageId = 0x63;
        break;
    }
    gBattleWork.step++;
}

// Opcode 0x52: Anti Attk Trap (Medaforce 0xA).
void medaforce_anti_attack_trap_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceAntiAttackTrapSteps[gBattleWork.step]();
}

void medaforce_anti_attack_trap_trap_spawn(void) {
    lz_decompress_dispatch(gMedaforceTrapTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceTrapPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags |= SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].scale_x = 8;
    gSpriteEntries[0x21].y = 0x3C;
    gSpriteEntries[0x21].frame = 0xE00;
    if (gBattleWork.actorSideFlags & 1) {
        gSpriteEntries[0x21].flags |= SPRITE_FLAG_HFLIP;
        gSpriteEntries[0x21].x--;
    }
    gBattleWork.step++;
}

void medaforce_anti_attack_trap_trap_grow(void) {
    gSpriteEntries[0x21].scale_x += 8;
    if (gSpriteEntries[0x21].scale_x == 0x40) {
        gGameWork.stepTimer = 0x3C;
        gSpriteEntries[0x21].work[FX_SPR_FRAMES] = 0;
        gBattleWork.step++;
    }
}

void medaforce_anti_attack_trap_check_existing(void) {
    if (gBattleWork.traps[gBattleWork.otherSide].active && gBattleWork.traps[gBattleWork.otherSide].skill == 0x5A) {
        gSpriteEntries[0x21].work[FX_SPR_FRAMES] = 0;
        gBattleWork.step++;
    } else {
        play_sound_effect(0x3E);
        gBattleWork.step += 2;
    }
}

void medaforce_anti_attack_trap_trap_pulse(void) {
    if (gSpriteEntries[0x21].work[FX_SPR_FRAMES] == 0x10) {
        play_sound_effect(0x3E);
        gBattleWork.step++;
        return;
    }
    if (gSpriteEntries[0x21].work[FX_SPR_FRAMES] < 8)
        gSpriteEntries[0x21].scale_x += 8;
    else
        gSpriteEntries[0x21].scale_x -= 8;
    gSpriteEntries[0x21].work[FX_SPR_FRAMES]++;
}

void medaforce_anti_attack_trap_apply(void) {
    if (gBattleWork.traps[gBattleWork.otherSide].active && gBattleWork.traps[gBattleWork.otherSide].skill == 0x5A) {
        gBattleWork.scratchAux = 1;
        add_u8_capped(&gBattleWork.traps[gBattleWork.otherSide].durability, gBattleWork.success >> 1, 0xFF);
        add_u8_capped(&gBattleWork.traps[gBattleWork.otherSide].power,
                      (gBattleWork.amount + gBattleBots[gBattleWork.actor].trapBonus) >> 1, 0xFF);
        gBattleWork.step++;
    } else {
        gBattleWork.scratchAux = 0;
        gBattleWork.traps[gBattleWork.otherSide].active = 1;
        gBattleWork.traps[gBattleWork.otherSide].skill = 0x5A;
        gBattleWork.traps[gBattleWork.otherSide].durability = 0;
        gBattleWork.traps[gBattleWork.otherSide].power = 0;
        add_u8_capped(&gBattleWork.traps[gBattleWork.otherSide].durability, gBattleWork.success, 0xFF);
        add_u8_capped(&gBattleWork.traps[gBattleWork.otherSide].power,
                      gBattleWork.amount + gBattleBots[gBattleWork.actor].trapBonus, 0xFF);
        gBattleWork.step++;
    }
}

void medaforce_anti_attack_trap_set_message(void) {
    gBattleWork.messageId = 0x50;
    gBattleWork.step++;
}

// Opcode 0x53: Cancel Formation (Medaforce 0xB).
void medaforce_cancel_formation_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceCancelFormationSteps[gBattleWork.step]();
}

void medaforce_cancel_formation_load_graphics(void) {
    lz_decompress_dispatch(gMedaforceCancelFormationTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceCancelFormationPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].frame = 0x6A00;
    gSpriteEntries[0x21].y += 4;
    gSpriteEntries[0x21].work[FX_SPR_FRAMES] = 0;
    gGameWork.stepTimer = 0x3C;
    gBattleWork.step++;
}

void medaforce_cancel_formation_slide(void) {
    if (gSpriteEntries[0x21].work[FX_SPR_FRAMES] == 0x10) {
        play_sound_effect(0x28);
        gSpriteEntries[0x21].work[FX_SPR_FRAMES] = 0;
        gBattleWork.step++;
        return;
    }
    if (!(gBattleWork.actorSideFlags & 1))
        gSpriteEntries[0x21].x--;
    else
        gSpriteEntries[0x21].x++;
    gSpriteEntries[0x21].work[FX_SPR_FRAMES]++;
}

void medaforce_cancel_formation_blink(void) {
    gSpriteEntries[0x21].work[FX_SPR_FRAMES]++;
    if (gSpriteEntries[0x21].work[FX_SPR_FRAMES] & 2)
        gSpriteEntries[0x21].flags |= SPRITE_FLAG_ENABLED;
    else
        gSpriteEntries[0x21].flags &= (u16)~SPRITE_FLAG_ENABLED;
    if (gSpriteEntries[0x21].work[FX_SPR_FRAMES] == 0x3C) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    }
}

void medaforce_cancel_formation_apply(void) {
    gBattleBots[gBattleWork.actor].guardFlags |= 2;
    gBattleWork.step++;
}

void medaforce_cancel_formation_set_message(void) {
    gBattleWork.messageId = 0x64;
    gBattleWork.step++;
}

// Opcode 0x54: Movement / Stop / Bind / Flow (Medaforces 0xC, 0xE, 0x10, 0x12) and Chaos (0x28).
void medaforce_inflict_status_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceInflictStatusSteps[gBattleWork.step]();
}

void medaforce_inflict_status_begin(void) {
    switch (gBattleBots[gBattleWork.actor].medaforce[0]) {
    case 0xC:
        gBattleWork.scratch = 0;
        break;
    case 0xE:
        gBattleWork.scratch = 1;
        break;
    case 0x10:
        gBattleWork.scratch = 2;
        break;
    case 0x12:
        gBattleWork.scratch = 3;
        break;
    case 0x28:
        gBattleWork.scratch = 4;
        break;
    }
    gBattleWork.step++;
}

void medaforce_inflict_status_orb_spawn(void) {
    switch (gBattleBots[gBattleWork.actor].medaforce[0]) {
    case 0xC:
        lz_decompress_dispatch(gMedaforceMovementEmblemTiles, (void *)(OBJ_VRAM0 + 0x4800));
        CpuFastSet(gMedaforceMovementEmblemPalette, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].work[FX_ORB_EMBLEM] = 0;
        gSpriteEntries[0x21].work[PARTICLE_ANIM] = 0x5B;
        break;
    case 0xE:
        lz_decompress_dispatch(gMedaforceStopEmblemTiles, (void *)(OBJ_VRAM0 + 0x4800));
        CpuFastSet(gMedaforceStopEmblemPalette, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].work[FX_ORB_EMBLEM] = 1;
        gSpriteEntries[0x21].work[PARTICLE_ANIM] = 0x5B;
        break;
    case 0x10:
        lz_decompress_dispatch(gMedaforceBindEmblemTiles, (void *)(OBJ_VRAM0 + 0x4800));
        CpuFastSet(gMedaforceBindEmblemPalette, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].work[FX_ORB_EMBLEM] = 2;
        gSpriteEntries[0x21].work[PARTICLE_ANIM] = 0x5B;
        break;
    case 0x12:
        lz_decompress_dispatch(gMedaforceFlowEmblemTiles, (void *)(OBJ_VRAM0 + 0x4800));
        CpuFastSet(gMedaforceFlowEmblemPalette, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].work[FX_ORB_EMBLEM] = 3;
        gSpriteEntries[0x21].work[PARTICLE_ANIM] = 0x5C;
        break;
    case 0x28:
        lz_decompress_dispatch(gMedaforceChaosEmblemTiles, (void *)(OBJ_VRAM0 + 0x4800));
        CpuFastSet(gMedaforceChaosEmblemPalette, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].work[FX_ORB_EMBLEM] = 4;
        gSpriteEntries[0x21].work[PARTICLE_ANIM] = 0x5B;
        break;
    }
    CpuFastSet(gEffectCommonPalette, (void *)0x050002C0, 8);
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].y = 0xE0;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].work[PARTICLE_STATE] = 1;
    gSpriteEntries[0x21].work[PARTICLE_ORBIT_RADIUS] = 0x20;
    gSpriteEntries[0x21].work[PARTICLE_ORBIT_ANGLE] = 0xC0;
    gSpriteEntries[0x21].work[PARTICLE_TIMER] = 0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[gSpriteEntries[0x21].work[PARTICLE_ANIM]], 0x21);
    if (!(gBattleWork.actorSideFlags & 1)) {
        gSpriteEntries[0x21].x = 0xB8;
    } else {
        gSpriteEntries[0x21].flags |= SPRITE_FLAG_HFLIP;
        gSpriteEntries[0x21].x = 0x38;
    }
    gBattleWork.step++;
}

void medaforce_orb_orbit_wait(void) {
    if (particle_run_orbit_handlers())
        gBattleWork.step++;
}

void medaforce_inflict_status_apply(void) {
    u32 i;

    medaforce_clear_hit_list();
    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState == 0)
            continue;
        if (gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor == 0)
            continue;
        if (battle_bot_lacks_stability(gBattleWork.targetSideFirst + i) == 0)
            continue;
        switch (gBattleBots[gBattleWork.actor].medaforce[0]) {
        case 0xC:
            if (bot_has_status_guard(gBattleWork.targetSideFirst + i, 0xD) == 0) {
                gBattleWork.partBreaks[i] = 1;
                battle_inflict_status(gBattleWork.targetSideFirst + i, 0xD, gBattleWork.success, gBattleWork.amount);
            }
            break;
        case 0xE:
            if (bot_has_status_guard(gBattleWork.targetSideFirst + i, 0x10) == 0) {
                gBattleWork.partBreaks[i] = 1;
                battle_inflict_status(gBattleWork.targetSideFirst + i, 0x10, gBattleWork.success, gBattleWork.amount);
            }
            break;
        case 0x10:
            if (bot_has_status_guard(gBattleWork.targetSideFirst + i, 0x12) == 0) {
                gBattleWork.partBreaks[i] = 1;
                battle_inflict_status(gBattleWork.targetSideFirst + i, 0x12, gBattleWork.success, gBattleWork.amount);
            }
            break;
        case 0x12:
            if (bot_has_status_guard(gBattleWork.targetSideFirst + i, 0x13) == 0) {
                gBattleWork.partBreaks[i] = 1;
                battle_inflict_status(gBattleWork.targetSideFirst + i, 0x13, gBattleWork.success, gBattleWork.amount);
            }
            break;
        case 0x28:
            gBattleWork.partBreaks[i] = 1;
            battle_inflict_status(gBattleWork.targetSideFirst + i, 0x2C, gBattleWork.success, gBattleWork.amount);
            break;
        }
    }
    gBattleWork.step++;
}

void medaforce_inflict_status_check_any(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            gBattleWork.step += 2;
            return;
        }
    }
    gBattleWork.step++;
}

void medaforce_inflict_status_icons_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gMedaforceTargetBurstTiles, (void *)(OBJ_VRAM0 + 0x6000));
    CpuFastSet(gMedaforceTargetBurstPalette, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0x21 + i].frame_table = 0;
        gSpriteEntries[0x21 + i].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[0x21 + i].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4;
        gSpriteEntries[0x21 + i].palette = 7;
        gSpriteEntries[0x21 + i].order = 0xF0;
        gSpriteEntries[0x21 + i].work[FX_SPR_STEP] = 0;
        switch (gBattleWork.scratch) {
        case 0:
            gSpriteEntries[0x21 + i].frame = 0x6F00;
            break;
        case 1:
            gSpriteEntries[0x21 + i].frame = 0x6F03;
            break;
        case 2:
            gSpriteEntries[0x21 + i].frame = 0x6F01;
            break;
        case 3:
            gSpriteEntries[0x21 + i].frame = 0x6F02;
            break;
        case 4:
            gSpriteEntries[0x21 + i].frame = 0x6F05;
            break;
        case 5:
            gSpriteEntries[0x21 + i].frame = 0x6F04;
            break;
        }
    }
    play_sound_effect(0x5B);
    gBattleWork.step++;
}

void medaforce_team_icons_anim_wait(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] && advance_sprite_anim_frame(0x21 + i, 0))
            done = 1;
    }
    if (done) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void medaforce_inflict_status_set_message(void) {
    clear_battle_sprite_slot(0x21, 3);
    switch (gBattleWork.scratch) {
    case 0:
        gBattleWork.messageId = 0x46;
        break;
    case 1:
        gBattleWork.messageId = 0x49;
        break;
    case 2:
        gBattleWork.messageId = 0x47;
        break;
    case 3:
        gBattleWork.messageId = 0x48;
        break;
    case 4:
        gBattleWork.messageId = 0x5D;
        break;
    case 5:
        gBattleWork.messageId = 0x5E;
        break;
    }
    gBattleWork.step++;
}

// Opcode 0x55: Cancel Movement / Stop / Bind / Flow (Medaforces 0xD, 0xF, 0x11, 0x13).
void medaforce_cancel_status_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceCancelStatusSteps[gBattleWork.step]();
}

void medaforce_cancel_status_begin(void) {
    switch (gBattleBots[gBattleWork.actor].medaforce[0]) {
    case 0xD:
        gBattleWork.scratch = 0;
        break;
    case 0xF:
        gBattleWork.scratch = 1;
        break;
    case 0x11:
        gBattleWork.scratch = 2;
        break;
    case 0x13:
        gBattleWork.scratch = 3;
        break;
    }
    gBattleWork.step++;
}

void medaforce_cancel_status_emblem_spawn(void) {
    switch (gBattleWork.scratch) {
    case 0:
        lz_decompress_dispatch(gMedaforceMovementEmblemTiles, (void *)(OBJ_VRAM0 + 0x4800));
        CpuFastSet(gMedaforceMovementEmblemPalette, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].work[FX_SPR_ANIM] = 0x5B;
        break;
    case 1:
        lz_decompress_dispatch(gMedaforceStopEmblemTiles, (void *)(OBJ_VRAM0 + 0x4800));
        CpuFastSet(gMedaforceStopEmblemPalette, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].work[FX_SPR_ANIM] = 0x5B;
        break;
    case 2:
        lz_decompress_dispatch(gMedaforceBindEmblemTiles, (void *)(OBJ_VRAM0 + 0x4800));
        CpuFastSet(gMedaforceBindEmblemPalette, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].work[FX_SPR_ANIM] = 0x5B;
        break;
    case 3:
        lz_decompress_dispatch(gMedaforceFlowEmblemTiles, (void *)(OBJ_VRAM0 + 0x4800));
        CpuFastSet(gMedaforceFlowEmblemPalette, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].work[FX_SPR_ANIM] = 0x5C;
        break;
    }
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].y = 0xE0;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].order = 0xF0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[gSpriteEntries[0x21].work[FX_SPR_ANIM]], 0x21);
    if (gBattleWork.actorSideFlags & 1) {
        gSpriteEntries[0x21].x = 0xB8;
    } else {
        gSpriteEntries[0x21].flags |= SPRITE_FLAG_HFLIP;
        gSpriteEntries[0x21].x = 0x38;
    }
    play_sound_effect(0x61);
    gBattleWork.step++;
}

void medaforce_cancel_status_emblem_rise(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[gSpriteEntries[0x21].work[FX_SPR_ANIM]], 0x21);
    if (gSpriteEntries[0x21].y == 0x40) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
        return;
    }
    gSpriteEntries[0x21].y = (gSpriteEntries[0x21].y + 2) & 0xFF;
    if (gBattleWork.actorSideFlags & 1) {
        if (gBattleWork.scratch != 3)
            gSpriteEntries[gGameWork.runningSpriteSlot].angle =
                (gSpriteEntries[gGameWork.runningSpriteSlot].angle - 0x10) & 0x3FF;
    } else {
        if (gBattleWork.scratch != 3)
            gSpriteEntries[gGameWork.runningSpriteSlot].angle =
                (gSpriteEntries[gGameWork.runningSpriteSlot].angle + 0x10) & 0x3FF;
    }
}

void medaforce_cancel_status_emblem_hold(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[gSpriteEntries[0x21].work[FX_SPR_ANIM]], 0x21);
    if (gBattleWork.actorSideFlags & 1) {
        if (gBattleWork.scratch != 3)
            gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle - 0x10) & 0x3FF;
    } else {
        if (gBattleWork.scratch != 3)
            gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle + 0x10) & 0x3FF;
    }
    if (gGameWork.skipBotSetup == 0 && (KEYS_LO(gRepeatKeys) & A_BUTTON))
        gBattleWork.step++;
    else if (gGameWork.stepTimer)
        gGameWork.stepTimer--;
    else
        gBattleWork.step++;
}

void medaforce_cancel_status_shatter_spawn(void) {
    lz_decompress_dispatch(gPartBreakBurstTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gPartBreakBurstPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].order = 0xF0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x23], 0x21);
    CpuSet(&gSpriteEntries[0x21], &gSpriteEntries[0x22], 0x20);
    CpuSet(&gSpriteEntries[0x21], &gSpriteEntries[0x23], 0x20);
    CpuSet(&gSpriteEntries[0x21], &gSpriteEntries[0x24], 0x20);
    CpuSet(&gSpriteEntries[0x21], &gSpriteEntries[0x25], 0x20);
    gSpriteEntries[0x21].work[SPR_MOTION_TABLE] = 0;
    gSpriteEntries[0x22].work[SPR_MOTION_TABLE] = 2;
    gSpriteEntries[0x22].work[SPR_MOTION_ROW] = 0x1C;
    gSpriteEntries[0x22].x -= 0x10;
    gSpriteEntries[0x22].y -= 0x10;
    gSpriteEntries[0x23].work[SPR_MOTION_TABLE] = 2;
    gSpriteEntries[0x23].work[SPR_MOTION_ROW] = 4;
    gSpriteEntries[0x23].x += 0x10;
    gSpriteEntries[0x23].y -= 0x10;
    gSpriteEntries[0x24].work[SPR_MOTION_TABLE] = 2;
    gSpriteEntries[0x24].work[SPR_MOTION_ROW] = 0x14;
    gSpriteEntries[0x24].x -= 0x10;
    gSpriteEntries[0x24].y += 0x10;
    gSpriteEntries[0x25].work[SPR_MOTION_TABLE] = 2;
    gSpriteEntries[0x25].work[SPR_MOTION_ROW] = 0xC;
    gSpriteEntries[0x25].x += 0x10;
    gSpriteEntries[0x25].y += 0x10;
    gBattleWork.step++;
}

void medaforce_cancel_status_shatter_wait(void) {
    u32 i;

    for (i = 0; i <= 4; i++) {
        process_sprite_anim_commands(gBattleSpriteAnimScripts[0x23], 0x21 + i);
        update_sprite_animation_position(0x21 + i);
    }
    if (gSpriteEntries[0x21].work[SPR_CMD_STATE] == SPR_CMD_ENDED) {
        clear_battle_sprite_slot(0x21, 5);
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void medaforce_cancel_status_sparkle_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gMedaforceCancelStatusSparkleTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceCancelStatusSparklePalette, (void *)0x050002E0, 8);
    medaforce_clear_hit_list();
    gBattleWork.targetSideFirst = battle_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState == 0)
            continue;
        if (gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor == 0)
            continue;
        gBattleWork.partBreaks[i] = 1;
        gSpriteEntries[0x21 + i].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0x21 + i].frame_table = 0;
        gSpriteEntries[0x21 + i].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[0x21 + i].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4;
        gSpriteEntries[0x21 + i].palette = 7;
        gSpriteEntries[0x21 + i].order = 0xF0;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x5F], 0x21 + i);
    }
    gBattleWork.step++;
}

void medaforce_cancel_status_sparkle_wait(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            process_sprite_anim_commands(gBattleSpriteAnimScripts[0x5F], 0x21 + i);
            if (gSpriteEntries[0x21 + i].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
                done = 1;
        }
    }
    if (done) {
        clear_battle_sprite_slot(0x21, 3);
        gBattleWork.step++;
    }
}

void medaforce_cancel_status_apply(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        switch (gBattleWork.scratch) {
        case 0:
            gBattleBots[gBattleWork.targetSideFirst + i].statusGuardFlags |= 1;
            if (gBattleBots[gBattleWork.targetSideFirst + i].statusType == 0xD)
                goto call_0xD;
            if (gBattleBots[gBattleWork.targetSideFirst + i].statusType != 0xE)
                break;
        call_0xD:
            bot_clear_effects(gBattleWork.targetSideFirst + i, 1);
            break;
        case 1:
            gBattleBots[gBattleWork.targetSideFirst + i].statusGuardFlags |= 8;
            if (gBattleBots[gBattleWork.targetSideFirst + i].statusType == 0xF)
                goto call_0xF;
            if (gBattleBots[gBattleWork.targetSideFirst + i].statusType != 0x10)
                break;
        call_0xF:
            bot_clear_effects(gBattleWork.targetSideFirst + i, 1);
            break;
        case 2:
            gBattleBots[gBattleWork.targetSideFirst + i].statusGuardFlags |= 2;
            if (gBattleBots[gBattleWork.targetSideFirst + i].statusType == 0x11)
                goto call_0x11;
            if (gBattleBots[gBattleWork.targetSideFirst + i].statusType != 0x12)
                break;
        call_0x11:
            bot_clear_effects(gBattleWork.targetSideFirst + i, 1);
            break;
        case 3:
            gBattleBots[gBattleWork.targetSideFirst + i].statusGuardFlags |= 4;
            if (gBattleBots[gBattleWork.targetSideFirst + i].statusType == 0x13)
                goto call_0x13;
            if (gBattleBots[gBattleWork.targetSideFirst + i].statusType != 0x14)
                break;
        call_0x13:
            bot_clear_effects(gBattleWork.targetSideFirst + i, 1);
            break;
        }
    }
    gBattleWork.step++;
}

void medaforce_cancel_status_set_message(void) {
    switch (gBattleWork.scratch) {
    case 0:
        gBattleWork.messageId = 0x55;
        break;
    case 1:
        gBattleWork.messageId = 0x58;
        break;
    case 2:
        gBattleWork.messageId = 0x56;
        break;
    case 3:
        gBattleWork.messageId = 0x57;
        break;
    }
    gBattleWork.step++;
}

// Opcode 0x56: Status Restore (Medaforce 0x15).
void medaforce_status_restore_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceStatusRestoreSteps[gBattleWork.step]();
}

void medaforce_status_restore_orb_spawn(void) {
    lz_decompress_dispatch(gMedaforceStatusRestoreTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceStatusRestorePalette, (void *)0x050002E0, 8);
    CpuFastSet(gEffectCommonPalette, (void *)0x050002C0, 8);
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].y = 0xE0;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].work[FX_ORB_EMBLEM] = 0;
    gSpriteEntries[0x21].work[PARTICLE_ANIM] = 0x5B;
    gSpriteEntries[0x21].work[PARTICLE_STATE] = 6;
    gSpriteEntries[0x21].work[PARTICLE_ORBIT_RADIUS] = 0x20;
    gSpriteEntries[0x21].work[PARTICLE_ORBIT_ANGLE] = 0xC0;
    gSpriteEntries[0x21].work[PARTICLE_TIMER] = 0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[gSpriteEntries[0x21].work[PARTICLE_ANIM]], 0x21);
    if (gBattleWork.actorSideFlags & 1)
        gSpriteEntries[0x21].x = 0xB8;
    else
        gSpriteEntries[0x21].x = 0x38;
    gBattleWork.scratch = 0;
    gBattleWork.step++;
}

void medaforce_status_restore_check_targets(void) {
    u32 found = 0;
    u32 i;

    medaforce_clear_hit_list();
    gBattleWork.targetSideFirst = battle_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState == 0)
            continue;
        if (gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor == 0)
            continue;
        if (gBattleBots[gBattleWork.targetSideFirst + i].statusType == 0)
            continue;
        found = 1;
        gBattleWork.partBreaks[i] = found;
    }
    if (!found)
        gBattleWork.step++;
    else
        gBattleWork.step += 2;
}

void medaforce_status_restore_sparkle_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gStabilitySparkleTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gStabilitySparklePalette, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0x21 + i].frame_table = 0;
        gSpriteEntries[0x21 + i].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[0x21 + i].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4;
        gSpriteEntries[0x21 + i].palette = 7;
        gSpriteEntries[0x21 + i].order = 0xF0;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x3C], 0x21 + i);
        if (gBattleWork.actorSideFlags & 1)
            gSpriteEntries[0x21 + i].flags |= SPRITE_FLAG_HFLIP;
    }
    play_sound_effect(0x37);
    gBattleWork.step++;
}

void medaforce_status_restore_sparkle_wait(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            process_sprite_anim_commands(gBattleSpriteAnimScripts[0x3C], 0x21 + i);
            if (gSpriteEntries[0x21 + i].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
                done = 1;
        }
    }
    if (done) {
        clear_battle_sprite_slot(0x21, 3);
        gBattleWork.step++;
    }
}

void medaforce_status_restore_apply(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i])
            bot_clear_effects(gBattleWork.targetSideFirst + i, 1);
    }
    gBattleWork.step++;
}

void medaforce_status_restore_set_message(void) {
    gBattleWork.messageId = 0x53;
    gBattleWork.step++;
}

// Opcode 0x57: Total Recovery (Medaforce 0x1A).
void medaforce_total_recovery_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceTotalRecoverySteps[gBattleWork.step]();
}

void medaforce_total_recovery_orb_spawn(void) {
    lz_decompress_dispatch(gMedaforceTotalRecoveryTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceTotalRecoveryPalette, (void *)0x050002E0, 8);
    CpuFastSet(gEffectCommonPalette, (void *)0x050002C0, 8);
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].y = 0xE0;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].work[FX_ORB_EMBLEM] = 0;
    gSpriteEntries[0x21].work[PARTICLE_ANIM] = 0x5C;
    gSpriteEntries[0x21].work[PARTICLE_STATE] = 6;
    gSpriteEntries[0x21].work[PARTICLE_ORBIT_RADIUS] = 0x20;
    gSpriteEntries[0x21].work[PARTICLE_ORBIT_ANGLE] = 0xC0;
    gSpriteEntries[0x21].work[PARTICLE_TIMER] = 0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[gSpriteEntries[0x21].work[PARTICLE_ANIM]], 0x21);
    if (gBattleWork.actorSideFlags & 1)
        gSpriteEntries[0x21].x = 0xB8;
    else
        gSpriteEntries[0x21].x = 0x38;
    gBattleWork.scratch = 1;
    gBattleWork.step++;
}

void medaforce_total_recovery_check_targets(void) {
    u32 found = 0;
    u32 i;

    medaforce_clear_hit_list();
    gBattleWork.targetSideFirst = battle_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState == 0)
            continue;
        if (gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor == 0)
            continue;
        if (find_most_damaged_part(gBattleWork.targetSideFirst + i) == 0)
            continue;
        found = 1;
        gBattleWork.partBreaks[i] = found;
    }
    if (!found)
        gBattleWork.step++;
    else
        gBattleWork.step += 2;
}

void medaforce_team_heal_sparkle_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gMedaforceTotalRecoverySparkleTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceTotalRecoverySparklePalette, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0x21 + i].frame_table = 0;
        gSpriteEntries[0x21 + i].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[0x21 + i].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4;
        gSpriteEntries[0x21 + i].palette = 7;
        gSpriteEntries[0x21 + i].order = 0xF0;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x60], 0x21 + i);
        if (gBattleWork.actorSideFlags & 1)
            gSpriteEntries[0x21 + i].flags |= SPRITE_FLAG_HFLIP;
    }
    play_sound_effect(0x2A);
    gBattleWork.step++;
}

void medaforce_team_heal_sparkle_wait(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            process_sprite_anim_commands(gBattleSpriteAnimScripts[0x60], 0x21 + i);
            if (gSpriteEntries[0x21 + i].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
                done = 1;
        }
    }
    if (done) {
        clear_battle_sprite_slot(0x21, 3);
        gBattleWork.step++;
    }
}

void medaforce_total_recovery_apply_heal(void) {
    u32 i, j;
    u32 part;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        for (j = 0; j <= 3; j++) {
            part = find_most_damaged_part(gBattleWork.targetSideFirst + i);
            if (part == 0)
                goto next;
            gBattleWork.damagePart = part - 1;
            battle_calc_damage_split(gBattleWork.targetSideFirst + i, gBattleWork.damagePart, gBattleWork.amount);
            gBattleBots[gBattleWork.targetSideFirst + i].parts[gBattleWork.damagePart].armor +=
                gBattleWork.appliedAmount;
            gBattleWork.partDamage[i] += gBattleWork.appliedAmount;
            if (gBattleWork.overflowAmount == 0)
                goto next;
            gBattleWork.amount = gBattleWork.overflowAmount;
        }
    next:;
    }
    gBattleWork.step++;
}

void init_battle_bot_display_digits(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        switch (i) {
        case 0:
            set_display_digit_type(gGameWork.textBuf, gBattleWork.partDamage[i], 0);
            battle_number_popup_init_slot(gGameWork.textBuf, gBattleWork.targetSideFirst + i, 0x21);
            break;
        case 1:
            set_display_digit_type(gGameWork.textBuf + 0x14, gBattleWork.partDamage[1], 0);
            battle_number_popup_init_slot(gGameWork.textBuf + 0x14, gBattleWork.targetSideFirst + 1, 0x21);
            break;
        case 2:
            set_display_digit_type(gGameWork.textBuf + 0x28, gBattleWork.partDamage[2], 0);
            battle_number_popup_init_slot(gGameWork.textBuf + 0x28, gBattleWork.targetSideFirst + 2, 0x21);
            break;
        }
    }
    play_sound_effect(0x5B);
    gGameWork.stepCounter = 0;
    gBattleWork.step++;
}

void medaforce_team_marked_popup_wait(void) {
    u32 i;
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            switch (i) {
            case 0:
                battle_popup_update_slot(gGameWork.textBuf, gBattleWork.targetSideFirst + i, 0x21);
                break;
            case 1:
                battle_popup_update_slot(gGameWork.textBuf + 0x14, gBattleWork.targetSideFirst + 1, 0x21);
                break;
            case 2:
                battle_popup_update_slot(gGameWork.textBuf + 0x28, gBattleWork.targetSideFirst + 2, 0x21);
                break;
            }
        }
    }
    gGameWork.stepCounter++;
    if (gGameWork.skipBotSetup == 0 && (KEYS_LO(gRepeatKeys) & A_BUTTON) && gGameWork.stepCounter > 0x32)
        gGameWork.stepCounter = 0x78;
    if (gGameWork.stepCounter == 0x78) {
        clear_battle_sprite_slot(gBattleWork.targetSideFirst * 4 + 0x21, 0xC);
        gBattleWork.step++;
    }
}

void medaforce_total_recovery_set_message(void) {
    gBattleWork.messageId = 0x3B;
    gBattleWork.step++;
}

// Opcode 0x58: Full Body Repair (Medaforce 0x1C).
void medaforce_full_body_repair_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceFullBodyRepairSteps[gBattleWork.step]();
}

void medaforce_full_body_repair_begin(void) {
    lz_decompress_dispatch(gMedaforceFullBodyRepairTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceFullBodyRepairPalette, (void *)0x050002E0, 8);
    CpuFastSet(gEffectCommonPalette, (void *)0x050002C0, 8);
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].y = 0xE0;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].work[FX_ORB_EMBLEM] = 0;
    gSpriteEntries[0x21].work[PARTICLE_ANIM] = 0x5C;
    gSpriteEntries[0x21].work[PARTICLE_STATE] = 6;
    gSpriteEntries[0x21].work[PARTICLE_ORBIT_RADIUS] = 0x20;
    gSpriteEntries[0x21].work[PARTICLE_ORBIT_ANGLE] = 0xC0;
    gSpriteEntries[0x21].work[PARTICLE_TIMER] = 0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[gSpriteEntries[0x21].work[PARTICLE_ANIM]], 0x21);
    if (gBattleWork.actorSideFlags & 1)
        gSpriteEntries[0x21].x = 0xB8;
    else
        gSpriteEntries[0x21].x = 0x38;
    gBattleWork.scratch = 2;
    gBattleWork.step++;
}

void medaforce_full_body_repair_check_targets(void) {
    u32 found = 0;
    u32 i;

    medaforce_clear_hit_list();
    gBattleWork.targetSideFirst = battle_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState == 0)
            continue;
        if (gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor == 0)
            continue;
        if (find_random_broken_part(gBattleWork.targetSideFirst + i) == 0)
            continue;
        found = 1;
        gBattleWork.partBreaks[i] = found;
    }
    if (!found)
        gBattleWork.step++;
    else
        gBattleWork.step += 2;
}

void medaforce_full_body_repair_apply_repair(void) {
    u32 i, j;
    u32 broken_part;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        for (j = 0; j <= 3; j++) {
            broken_part = find_random_broken_part(gBattleWork.targetSideFirst + i);
            if (broken_part == 0)
                goto next;
            gBattleWork.damagePart = broken_part - 1;
            battle_set_damage_display(gBattleWork.targetSideFirst + i, gBattleWork.damagePart, gBattleWork.amount);
            gBattleBots[gBattleWork.targetSideFirst + i].parts[gBattleWork.damagePart].armor +=
                gBattleWork.appliedAmount;
            gBattleWork.partDamage[i] += gBattleWork.appliedAmount;
            bot_restore_leg_stats(gBattleWork.targetSideFirst + i);
            if (gBattleWork.overflowAmount == 0)
                goto next;
            gBattleWork.amount = gBattleWork.overflowAmount;
        }
    next:;
    }
    load_all_bot_part_sprites();
    iterate_bots_setup_battle_sprites();
    gBattleWork.step++;
}

void medaforce_full_body_repair_finish(void) {
    gBattleWork.messageId = 0x3C;
    gBattleWork.step++;
}

// Opcode 0x59: Full Body Up (Medaforce 0x16).
void medaforce_full_body_up_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceFullBodyUpSteps[gBattleWork.step]();
}

void medaforce_full_body_up_begin(void) {
    lz_decompress_dispatch(gMedaforceFullBodyUpTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceFullBodyUpPalette, (void *)0x050002E0, 8);
    CpuFastSet(gEffectCommonPalette, (void *)0x050002C0, 8);
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = 0x78;
    gSpriteEntries[0x21].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].scale_x = 4;
    gSpriteEntries[0x21].scale_y = 4;
    gSpriteEntries[0x21].angle = 0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x61], 0x21);
    gSpriteEntries[0x22].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x22].frame_table = 0;
    gSpriteEntries[0x22].x = 0x78;
    gSpriteEntries[0x22].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x22].palette = 6;
    gSpriteEntries[0x22].order = 0xE0;
    gSpriteEntries[0x22].scale_x = 4;
    gSpriteEntries[0x22].scale_y = 4;
    gSpriteEntries[0x22].angle = 0;
    gSpriteEntries[0x22].frame = 0x7604;
    play_sound_effect(0x67);
    gBattleWork.step++;
}

// guess: sprite meaning unsure; scales sprites 0x21/0x22 up to 0x40, then 60-frame wait (orb)

void medaforce_full_body_up_orb_grow(void) {
    if (gSpriteEntries[0x21].scale_x == 0x40) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x += 4;
        gSpriteEntries[0x21].scale_y += 4;
        gSpriteEntries[0x22].scale_x += 4;
        gSpriteEntries[0x22].scale_y += 4;
    }
}

void medaforce_full_body_up_orb_rise(void) {
    if (gSpriteEntries[0x21].y == 0x20) {
        play_sound_effect(0x42);
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].y--;
        gSpriteEntries[0x22].y--;
    }
}

void medaforce_full_body_up_orb_anim_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x61], 0x21);
    if (gSpriteEntries[0x21].work[SPR_CMD_STATE] == SPR_CMD_ENDED) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    }
}

void medaforce_full_body_up_orbs_spawn(void) {
    u32 i;

    medaforce_clear_hit_list();
    gBattleWork.targetSideFirst = battle_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState == 0)
            continue;
        if (gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor == 0)
            continue;
        copy_bytes(&gSpriteEntries[0x22], &gSpriteEntries[0x23 + i], 0x40);
        gSpriteEntries[0x23 + i].work16[FX_SPR_TARGET_X] =
            gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[0x23 + i].work16[FX_SPR_TARGET_Y] =
            gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4;
        gSpriteEntries[0x23 + i].work[SPR_MOTION_TABLE] = 3;
        gSpriteEntries[0x23 + i].work[FX_SPR_STEP] = 0;
        gBattleWork.partBreaks[i] = 1;
    }
    clear_battle_sprite_slot(0x22, 1);
    gBattleWork.step++;
}

void medaforce_full_body_up_orbs_fly(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            count++;
            gSpriteEntries[0x23 + i].angle = (gSpriteEntries[0x23 + i].angle + 0x20) & 0x3FF;
            if (move_sprite_toward_target(0x23 + i))
                done++;
        }
    }
    if (count == done) {
        play_sound_effect(0x2B);
        gBattleWork.step++;
    }
}

void medaforce_full_body_up_orbs_shrink(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            gSpriteEntries[0x23 + i].angle = (gSpriteEntries[0x23 + i].angle + 0x20) & 0x3FF;
            gSpriteEntries[0x23 + i].scale_x -= 4;
            gSpriteEntries[0x23 + i].scale_y -= 4;
            if (gSpriteEntries[0x23 + i].scale_y == 4)
                done = 1;
        }
    }
    if (done) {
        clear_battle_sprite_slot(0x24, 3);
        gBattleWork.step++;
    }
}

void medaforce_full_body_up_apply_head_uses(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            calc_head_uses_given(gBattleWork.targetSideFirst + i, gBattleWork.amount);
            gBattleWork.partDamage[i] = gBattleWork.appliedAmount;
            add_u8_capped(&gBattleBots[gBattleWork.targetSideFirst + i].parts[0].headUses, gBattleWork.partDamage[i],
                          gBattleBots[gBattleWork.targetSideFirst + i].parts[0].data[8]);
        }
    }
    gBattleWork.step++;
}

void medaforce_team_text_popups_init(void) {
    u32 i;

    lz_decompress_dispatch(gBattlePopupDigitTiles, (void *)(OBJ_VRAM0 + 0x7E00));
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        switch (i) {
        case 0:
            set_display_digit_type(gGameWork.textBuf, gBattleWork.partDamage[i], 0);
            battle_text_popup_init_slot(gGameWork.textBuf, gBattleWork.targetSideFirst + i, 0x21);
            break;
        case 1:
            set_display_digit_type(gGameWork.textBuf + 0x14, gBattleWork.partDamage[1], 0);
            battle_text_popup_init_slot(gGameWork.textBuf + 0x14, gBattleWork.targetSideFirst + 1, 0x21);
            break;
        case 2:
            set_display_digit_type(gGameWork.textBuf + 0x28, gBattleWork.partDamage[2], 0);
            battle_text_popup_init_slot(gGameWork.textBuf + 0x28, gBattleWork.targetSideFirst + 2, 0x21);
            break;
        }
    }
    play_sound_effect(0x5B);
    gGameWork.stepCounter = 0;
    gBattleWork.step++;
}

void medaforce_full_body_up_finish(void) {
    gBattleWork.messageId = 0x54;
    gBattleWork.step++;
}

// Opcode 0x5A: Full Body RAD (Medaforce 0x17).
void medaforce_full_body_rad_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceFullBodyRadSteps[gBattleWork.step]();
}

void medaforce_full_body_rad_begin(void) {
    lz_decompress_dispatch(gMedaforceFullBodyRadTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceFullBodyRadPalette, (void *)0x050002E0, 8);
    CpuFastSet(gEffectCommonPalette, (void *)0x050002C0, 8);
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].scale_x = 4;
    gSpriteEntries[0x21].scale_y = 4;
    gSpriteEntries[0x21].angle = 0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x62], 0x21);
    if (!(gBattleWork.actorSideFlags & 1)) {
        gSpriteEntries[0x21].x = 0x70;
    } else {
        gSpriteEntries[0x21].flags |= SPRITE_FLAG_HFLIP;
        gSpriteEntries[0x21].x = 0x80;
    }
    play_sound_effect(0x6A);
    gBattleWork.step++;
}

void medaforce_full_body_rad_grow(void) {
    if (gSpriteEntries[0x21].scale_x == 0x40) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x += 4;
        gSpriteEntries[0x21].scale_y += 4;
    }
}

void medaforce_full_body_rad_push_back_init(void) {
    u32 i;

    medaforce_clear_hit_list();
    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState == 0)
            continue;
        if (gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor == 0)
            continue;
        gBattleBots[gBattleWork.targetSideFirst + i].stateFlags |= 4;
        gBattleWork.partBreaks[i] = 1;
        battle_queue_remove_bot(gBattleWork.targetSideFirst + i);
        gBattleBots[gBattleWork.targetSideFirst + i].moveSubpixel = 0;
        gBattleBots[gBattleWork.targetSideFirst + i].moveDelay = 0x14;
        gBattleBots[gBattleWork.targetSideFirst + i].moveStep = 0;
        gSpriteEntries[0x22 + i].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0x22 + i].frame_table = 0;
        gSpriteEntries[0x22 + i].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[0x22 + i].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 0x10;
        gSpriteEntries[0x22 + i].palette = 7;
        gSpriteEntries[0x22 + i].order = 0xE0;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x63], 0x22 + i);
        if (gBattleWork.actorSideFlags & 1)
            gSpriteEntries[0x22 + i].flags |= SPRITE_FLAG_HFLIP;
    }
    iterate_bots_setup_battle_sprites();
    gGameWork.stepTimer = 0;
    gSpriteEntries[0x21].flags &= (u16)~SPRITE_FLAG_AFFINE;
    gSpriteEntries[0x2B].work[PARTICLE_STATE] = 1;
    gSpriteEntries[0x2B].x = gSpriteEntries[0x21].x;
    gSpriteEntries[0x2B].y = gSpriteEntries[0x21].y;
    battle_queue_sort();
    gBattleWork.step++;
}

void medaforce_full_body_rad_push_back(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        count++;
        bot_update_walk_anim(gBattleWork.targetSideFirst + i);
        if (battle_bot_move_reverse(gBattleWork.targetSideFirst + i))
            done++;
        process_sprite_anim_commands(gBattleSpriteAnimScripts[0x63], 0x22 + i);
        gSpriteEntries[0x22 + i].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[0x22 + i].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 0x10;
        init_bot_shadow_sprite(gBattleWork.targetSideFirst + i);
    }
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x62], 0x21);
    if (!(gGameWork.stepTimer & 0x3F))
        play_sound_effect(0x33);
    gGameWork.stepTimer++;
    particle_run_spark_handlers();
    if (done == count && gGameWork.stepTimer > 0x3C) {
        clear_battle_sprite_slot(0x21, 0x1B);
        iterate_bots_setup_battle_sprites();
        gBattleWork.step++;
    }
}

void medaforce_full_body_rad_finish(void) {
    gBattleWork.messageId = 0x65;
    gBattleWork.step++;
}

// Opcode 0x5B: Iron Wall (Medaforce 0x18).
void medaforce_iron_wall_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceIronWallSteps[gBattleWork.step]();
}

void medaforce_iron_wall_begin(void) {
    lz_decompress_dispatch(gMedaforceIronWallTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceIronWallPalette, (void *)0x050002E0, 8);
    // FAKEMATCH: the constant is a negative s16 in the original (literal pool value)
    gSpriteEntries[0x21].flags = (s16)(SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                       SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE);
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x - 0x20;
    gSpriteEntries[0x21].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = -0x10;
    gSpriteEntries[0x21].scale_x = 0x80;
    gSpriteEntries[0x21].scale_y = 0x80;
    gSpriteEntries[0x21].work[FX_ORBIT_RADIUS] = 0x1C;
    gSpriteEntries[0x21].work[FX_ORBIT_ANGLE] = 0;
    gSpriteEntries[0x21].work[FX_ORBIT_TIMER] = 0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x1C], 0x21);
    // FAKEMATCH: the constant is a negative s16 in the original (literal pool value)
    gSpriteEntries[0x22].flags = (s16)(SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                       SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE);
    gSpriteEntries[0x22].frame_table = 0;
    gSpriteEntries[0x22].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x + 0x20;
    gSpriteEntries[0x22].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x22].palette = 7;
    gSpriteEntries[0x22].order = -0x10;
    gSpriteEntries[0x22].scale_x = 0x80;
    gSpriteEntries[0x22].scale_y = 0x80;
    gSpriteEntries[0x22].work[FX_ORBIT_RADIUS] = 0x1C;
    gSpriteEntries[0x22].work[FX_ORBIT_ANGLE] = 0x80;
    gSpriteEntries[0x22].work[FX_ORBIT_TIMER] = 0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x1C], 0x22);
    play_sound_effect(0x33);
    gBattleWork.step++;
}

void medaforce_iron_wall_apply_defence(void) {
    add_u8_capped(&gBattleBots[gBattleWork.actor].powerBonus + 1, gBattleWork.amount, 0xFF);
    gBattleWork.step++;
}

void medaforce_iron_wall_finish(void) {
    gBattleWork.messageId = 0x45;
    gBattleWork.step++;
}

// Opcode 0x5C: Power Up (Medaforce 0x19).
void medaforce_power_up_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforcePowerUpSteps[gBattleWork.step]();
}

void medaforce_power_up_begin(void) {
    lz_decompress_dispatch(gMedaforcePowerUpTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforcePowerUpPalette, (void *)0x050002E0, 8);
    // FAKEMATCH: the constant is a negative s16 in the original (literal pool value)
    gSpriteEntries[0x21].flags = (s16)(SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                       SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE);
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x - 0x20;
    gSpriteEntries[0x21].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].scale_x = 0x80;
    gSpriteEntries[0x21].scale_y = 0x80;
    gSpriteEntries[0x21].work[FX_ORBIT_RADIUS] = 0x1C;
    gSpriteEntries[0x21].work[FX_ORBIT_ANGLE] = 0;
    gSpriteEntries[0x21].work[FX_ORBIT_TIMER] = 0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x64], 0x21);
    // FAKEMATCH: the constant is a negative s16 in the original (literal pool value)
    gSpriteEntries[0x22].flags = (s16)(SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                       SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE);
    gSpriteEntries[0x22].frame_table = 0;
    gSpriteEntries[0x22].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x + 0x20;
    gSpriteEntries[0x22].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x22].palette = 7;
    gSpriteEntries[0x22].order = 0xF0;
    gSpriteEntries[0x22].scale_x = 0x80;
    gSpriteEntries[0x22].scale_y = 0x80;
    gSpriteEntries[0x22].frame = 0x7901;
    gSpriteEntries[0x22].work[FX_ORBIT_RADIUS] = 0x1C;
    gSpriteEntries[0x22].work[FX_ORBIT_ANGLE] = 0x80;
    gSpriteEntries[0x22].work[FX_ORBIT_TIMER] = 0;
    play_sound_effect(0x33);
    gBattleWork.step++;
}

void medaforce_power_up_shield_anim_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x64], 0x21);
    if (gSpriteEntries[0x21].work[SPR_CMD_STATE] == SPR_CMD_ENDED) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    }
}

// guess: sprite meaning unsure; spawns sprite 0x21 (anim 0x65) on the user, sound 0x71    (aura)

void medaforce_power_up_aura_spawn(void) {
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x;
    gSpriteEntries[0x21].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x65], 0x21);
    play_sound_effect(0x71);
    gBattleWork.step++;
}

void medaforce_power_up_aura_anim_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x65], 0x21);
    if (gSpriteEntries[0x21].work[SPR_CMD_STATE] == SPR_CMD_ENDED) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    }
}

void medaforce_power_up_apply_power(void) {
    add_u8_capped(&gBattleBots[gBattleWork.actor].powerBonus, gBattleWork.amount, 0xFF);
    gBattleWork.step++;
}

void medaforce_power_up_finish(void) {
    gBattleWork.messageId = 0x44;
    gBattleWork.step++;
}

// Opcode 0x5D: Anti Air / Anti Sea (Medaforces 0x1E, 0x20).
void medaforce_anti_terrain_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceAntiTerrainSteps[gBattleWork.step]();
}

void medaforce_anti_terrain_beam_spawn(void) {
    lz_decompress_dispatch(gMedaforceAntiTerrainBeamTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceAntiTerrainBeamPalettes, (void *)0x050002C0, 0x10);
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x;
    gSpriteEntries[0x21].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x21].palette = 6;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].frame = 0x7A00;
    gSpriteEntries[0x22].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x22].frame_table = 0;
    gSpriteEntries[0x22].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x;
    gSpriteEntries[0x22].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x22].palette = 7;
    gSpriteEntries[0x22].order = 0xE0;
    gSpriteEntries[0x22].work[FX_SPR_TIMER] = 0;
    if (gBattleBots[gBattleWork.actor].medaforce[0] == 0x1E)
        gSpriteEntries[0x22].frame = 0x7A01;
    else
        gSpriteEntries[0x22].frame = 0x7A02;
    play_sound_effect(0x4C);
    gBattleWork.step++;
}

void medaforce_anti_terrain_check_targets(void) {
    u32 i;
    u32 found = 0;

    medaforce_clear_hit_list();
    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState == 0 ||
            gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor == 0 ||
            battle_bot_lacks_stability(gBattleWork.targetSideFirst + i) == 0)
            continue;
        if (gBattleBots[gBattleWork.actor].medaforce[0] == 0x1E) {
            if (gBattleBots[gBattleWork.targetSideFirst + i].parts[3].data[1] == 0x64) {
                gBattleWork.partBreaks[i] = 1;
                found = 1;
            }
        } else if (gBattleBots[gBattleWork.targetSideFirst + i].parts[3].data[1] == 0x6A) {
            gBattleWork.partBreaks[i] = 2;
            found = 1;
        }
    }
    if (!found)
        gBattleWork.step++;
    else
        gBattleWork.step += 2;
}

void medaforce_anti_terrain_bolts_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gMedaforceAntiTerrainBoltTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceAntiTerrainBoltPalettes, (void *)0x050002C0, 0x10);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[i + 0x21].frame_table = 0;
        gSpriteEntries[i + 0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x;
        gSpriteEntries[i + 0x21].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
        gSpriteEntries[i + 0x21].work16[FX_SPR_TARGET_X] =
            gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[i + 0x21].work16[FX_SPR_TARGET_Y] =
            gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4;
        gSpriteEntries[i + 0x21].work[SPR_MOTION_TABLE] = 6;
        gSpriteEntries[i + 0x21].work[FX_SPR_STEP] = 0;
        gSpriteEntries[i + 0x21].order = 0xF0;
        if (gBattleWork.actorSideFlags & 1)
            gSpriteEntries[i + 0x21].flags |= SPRITE_FLAG_HFLIP;
        if (gBattleWork.partBreaks[i] == 1) {
            gSpriteEntries[i + 0x21].palette = 6;
            gSpriteEntries[i + 0x21].frame = 0x7B00;
        } else {
            gSpriteEntries[i + 0x21].palette = 7;
            gSpriteEntries[i + 0x21].frame = 0x7B01;
        }
    }
    play_sound_effect(0x24);
    gBattleWork.step++;
}

void medaforce_anti_terrain_bolts_fly(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        count++;
        if (move_sprite_toward_target(i + 0x21))
            done++;
    }
    if (done == count)
        gBattleWork.step++;
}

void medaforce_anti_terrain_burst_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gMedaforceTargetBurstTiles, (void *)(OBJ_VRAM0 + 0x6000));
    CpuFastSet(gMedaforceTargetBurstPalette, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].palette = 7;
        gSpriteEntries[i + 0x21].flags &= (u16)~SPRITE_FLAG_HFLIP;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x66], i + 0x21);
    }
    gBattleWork.step++;
}

void medaforce_anti_terrain_burst_anim_wait(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        process_sprite_anim_commands(gBattleSpriteAnimScripts[0x66], i + 0x21);
        if (gSpriteEntries[i + 0x21].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
            done = 1;
    }
    if (done)
        gBattleWork.step++;
}

void medaforce_anti_terrain_roll_status(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gBattleWork.partDamage[i] = rng_next_byte() & 7;
        switch (gBattleWork.partDamage[i]) {
        case 0:
            if (bot_has_status_guard(gBattleWork.targetSideFirst + i, 0xD))
                gBattleWork.partDamage[i] = 5;
            break;
        case 1:
            if (bot_has_status_guard(gBattleWork.targetSideFirst + i, 0x11))
                gBattleWork.partDamage[i] = 5;
            break;
        case 2:
            if (bot_has_status_guard(gBattleWork.targetSideFirst + i, 0x13))
                gBattleWork.partDamage[i] = 5;
            break;
        case 3:
            if (bot_has_status_guard(gBattleWork.targetSideFirst + i, 0x10))
                gBattleWork.partDamage[i] = 5;
            break;
        }
        gSpriteEntries[i + 0x21].frame = 0x6F00 + gBattleWork.partDamage[i];
        gSpriteEntries[i + 0x21].work[FX_SPR_STEP] = 0;
    }
    play_sound_effect(0x5B);
    gBattleWork.step++;
}

void medaforce_anti_terrain_apply_status(void) {
    u32 i;

    clear_battle_sprite_slot(0x21, 3);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        switch (gBattleWork.partDamage[i]) {
        case 0:
            battle_inflict_status(gBattleWork.targetSideFirst + i, 0xD, gBattleWork.success, gBattleWork.amount);
            break;
        case 1:
            battle_inflict_status(gBattleWork.targetSideFirst + i, 0x11, gBattleWork.success, gBattleWork.amount);
            break;
        case 2:
            battle_inflict_status(gBattleWork.targetSideFirst + i, 0x13, gBattleWork.success, gBattleWork.amount);
            break;
        case 3:
            battle_inflict_status(gBattleWork.targetSideFirst + i, 0x10, gBattleWork.success, gBattleWork.amount);
            break;
        case 4:
            gBattleBots[gBattleWork.targetSideFirst + i].statusType = 0x2B;
            gBattleBots[gBattleWork.targetSideFirst + i].statusTimer = clamp_1_99(gBattleWork.success);
            gBattleBots[gBattleWork.targetSideFirst + i].statusAmount = clamp_1_99(gBattleWork.amount);
            gBattleBots[gBattleWork.targetSideFirst + i].statusPart = 1;
            break;
        case 5:
            gBattleBots[gBattleWork.targetSideFirst + i].statusType = 0x2C;
            gBattleBots[gBattleWork.targetSideFirst + i].statusPart = 0;
            gBattleBots[gBattleWork.targetSideFirst + i].statusTimer = clamp_1_99(gBattleWork.success);
            gBattleBots[gBattleWork.targetSideFirst + i].statusAmount = clamp_1_99(gBattleWork.amount);
            break;
        case 6:
            gBattleBots[gBattleWork.targetSideFirst + i].statusType = 0x2E;
            gBattleBots[gBattleWork.targetSideFirst + i].statusPart = 0;
            gBattleBots[gBattleWork.targetSideFirst + i].statusTimer = clamp_1_99(gBattleWork.success);
            gBattleBots[gBattleWork.targetSideFirst + i].statusAmount = clamp_1_99(gBattleWork.amount);
            break;
        case 7:
            gBattleBots[gBattleWork.targetSideFirst + i].statusType = 0x2F;
            gBattleBots[gBattleWork.targetSideFirst + i].statusPart = 0;
            gBattleBots[gBattleWork.targetSideFirst + i].statusTimer = clamp_1_99(gBattleWork.success);
            gBattleBots[gBattleWork.targetSideFirst + i].statusAmount = clamp_1_99(gBattleWork.amount);
            break;
        }
    }
    gBattleWork.step++;
}

void medaforce_anti_terrain_finish(void) {
    if (gBattleBots[gBattleWork.actor].medaforce[0] == 0x1E)
        gBattleWork.messageId = 0x4D;
    else
        gBattleWork.messageId = 0x4E;
    gBattleWork.step++;
}

// Opcode 0x5E: Propulsion / Mobility / PROX / Remoteness Up (Medaforces 0x1F, 0x21, 0x23, 0x25).
void medaforce_legs_stat_up_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceLegsStatUpSteps[gBattleWork.step]();
}

void medaforce_legs_stat_up_begin(void) {
    u32 i;

    medaforce_clear_hit_list();
    gBattleWork.targetSideFirst = battle_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState != 0 &&
            gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor != 0)
            gBattleWork.partBreaks[i] = 1;
    }
    switch (gBattleBots[gBattleWork.actor].medaforce[0]) {
    case 0x1F:
        gBattleWork.scratch = 0;
        break;
    case 0x21:
        gBattleWork.scratch = 1;
        break;
    case 0x23:
        gBattleWork.scratch = 2;
        break;
    case 0x25:
        gBattleWork.scratch = 3;
        break;
    }
    gBattleWork.step++;
}

// guess: sprite meaning unsure; loads graphics, spawns sprites 0x21+i (anim 0x67) above each target    (arrows)

void medaforce_legs_stat_up_arrows_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gMedaforceUpArrowTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceUpArrowPalettes, (void *)0x050002C0, 0x10);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[i + 0x21].frame_table = 0;
        gSpriteEntries[i + 0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[i + 0x21].y = 0xF0;
        gSpriteEntries[i + 0x21].palette = 6;
        gSpriteEntries[i + 0x21].order = 0xF0;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x67], i + 0x21);
    }
    play_sound_effect(0x2C);
    gBattleWork.step++;
}

void medaforce_legs_stat_up_arrows_fall(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        count++;
        process_sprite_anim_commands(gBattleSpriteAnimScripts[0x67], i + 0x21);
        if (gSpriteEntries[i + 0x21].y == gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4)
            done++;
        else
            gSpriteEntries[i + 0x21].y = (gSpriteEntries[i + 0x21].y + 1) & 0xFF;
    }
    if (done == count)
        gBattleWork.step++;
}

void medaforce_legs_stat_up_burst_spawn(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[i + 0x21].order = 0;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x68], i + 0x21);
    }
    play_sound_effect(0x30);
    gBattleWork.step++;
}

void medaforce_legs_stat_up_burst_anim_wait(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        process_sprite_anim_commands(gBattleSpriteAnimScripts[0x68], i + 0x21);
        if (gSpriteEntries[i + 0x21].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
            done = 1;
    }
    if (done)
        gBattleWork.step++;
}

void medaforce_legs_stat_up_icon_spawn(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[i + 0x21].order = 0xE0;
        gSpriteEntries[i + 0x21].y += 8;
        gSpriteEntries[i + 0x21].palette = 7;
        gSpriteEntries[i + 0x21].frame = 0x7C04 + gBattleWork.scratch;
    }
    gGameWork.stepTimer = 0;
    play_sound_effect(0x2E);
    gBattleWork.step++;
}

void medaforce_legs_stat_up_icon_rise(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] != 0 && !(gGameWork.stepTimer & 1))
            gSpriteEntries[i + 0x21].y--;
    }
    if (++gGameWork.stepTimer == 0x20) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void medaforce_legs_stat_up_set_amounts(void) {
    u32 i;

    clear_battle_sprite_slot(0x21, 3);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] != 0)
            gBattleWork.partDamage[i] = gBattleWork.amount;
    }
    gBattleWork.step++;
}

void medaforce_legs_stat_up_apply_stat(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        switch (gBattleWork.scratch) {
        case 0:
            add_u8_capped(&gBattleBots[gBattleWork.targetSideFirst + i].parts[3].data[5], gBattleWork.amount, 0xFF);
            break;
        case 1:
            add_u8_capped(&gBattleBots[gBattleWork.targetSideFirst + i].parts[3].data[6], gBattleWork.amount, 0xFF);
            break;
        case 2:
            add_u8_capped(&gBattleBots[gBattleWork.targetSideFirst + i].parts[3].data[8], gBattleWork.amount, 0xFF);
            break;
        case 3:
            add_u8_capped(&gBattleBots[gBattleWork.targetSideFirst + i].parts[3].data[9], gBattleWork.amount, 0xFF);
            break;
        }
        bot_halve_broken_leg_stats(gBattleWork.targetSideFirst + i);
        bot_restore_leg_stats(gBattleWork.targetSideFirst + i);
    }
    gBattleWork.step++;
}

void medaforce_legs_stat_up_finish(void) {
    switch (gBattleWork.scratch) {
    case 0:
        gBattleWork.messageId = 0x3D;
        break;
    case 1:
        gBattleWork.messageId = 0x3E;
        break;
    case 2:
        gBattleWork.messageId = 0x40;
        break;
    case 3:
        gBattleWork.messageId = 0x41;
        break;
    }
    gBattleWork.step++;
}

// Opcode 0x5F: Spy Game (Medaforce 0x22).
void medaforce_spy_game_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceSpyGameSteps[gBattleWork.step]();
}

void medaforce_spy_game_beam_spawn(void) {
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = 0x78;
    gSpriteEntries[0x21].y = 0x40;
    gSpriteEntries[0x21].palette = 6;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].frame = 0x4800;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].work[FX_SPR_TIMER] = 0;
    gSpriteEntries[0x21].work[FX_SPR_SPIN_SPEED] = 1;
    gGameWork.stepTimer = 0;
    gGameWork.stepCounter = 0;
    gBattleWork.step++;
}

void medaforce_spy_game_beam_spin(void) {
    u32 angle;

    if (gGameWork.stepCounter <= 2) {
        if (gGameWork.stepTimer == 0) {
            gGameWork.stepCounter++;
            play_sound_effect(0x4C);
        }
        if (++gGameWork.stepTimer == gSpyGameBeamSpinFrames[gGameWork.stepCounter - 1])
            gGameWork.stepTimer = 0;
    }
    if (gSpriteEntries[0x21].angle == 0)
        gSpriteEntries[0x21].work[FX_SPR_SPIN_SPEED]++;
    angle = (u16)(gSpriteEntries[0x21].work[FX_SPR_SPIN_SPEED] * 16 + gSpriteEntries[0x21].angle) & 0x3FF;
    gSpriteEntries[0x21].angle = angle;
    if (gSpriteEntries[0x21].work[FX_SPR_SPIN_SPEED] == 5 && angle == 0) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    }
}

void medaforce_mark_both_sides(void) {
    u32 i;

    medaforce_clear_hit_list();
    gBattleWork.targetSideFirst = battle_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState != 0 &&
            gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor != 0)
            gBattleWork.partBreaks[i] = 1;
    }
    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState != 0 &&
            gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor != 0)
            gBattleWork.partDamage[i] = 1;
    }
    gBattleWork.step++;
}

void medaforce_spy_game_arrows_spawn(void) {
    u32 i;

    gBattleWork.targetSideFirst = battle_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                         SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[i + 0x21].frame_table = 0;
        gSpriteEntries[i + 0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[i + 0x21].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y;
        gSpriteEntries[i + 0x21].palette = 7;
        gSpriteEntries[i + 0x21].order = 0xF0;
        gSpriteEntries[i + 0x21].scale_x = 0x40;
        gSpriteEntries[i + 0x21].scale_y = 0x40;
        gSpriteEntries[i + 0x21].frame = 0x4801;
    }
    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partDamage[i] == 0)
            continue;
        gSpriteEntries[i + 0x24].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                         SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[i + 0x24].frame_table = 0;
        gSpriteEntries[i + 0x24].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[i + 0x24].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 0x10;
        gSpriteEntries[i + 0x24].palette = 7;
        gSpriteEntries[i + 0x24].order = 0xF0;
        gSpriteEntries[i + 0x24].scale_x = 0x40;
        gSpriteEntries[i + 0x24].scale_y = 0x40;
        gSpriteEntries[i + 0x24].frame = 0x4802;
    }
    gGameWork.stepCounter = 0;
    play_sound_effect(0x2E);
    gBattleWork.step++;
}

void medaforce_spy_game_arrows_move(void) {
    u32 i;

    gBattleWork.targetSideFirst = battle_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] != 0 && !(gGameWork.stepCounter & 1))
            gSpriteEntries[i + 0x21].y--;
    }
    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partDamage[i] != 0 && !(gGameWork.stepCounter & 1))
            gSpriteEntries[i + 0x24].y++;
    }
    if (gGameWork.stepCounter == 0x20) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    } else
        gGameWork.stepCounter++;
}

void medaforce_spy_game_arrows_shrink(void) {
    u32 i;

    gBattleWork.targetSideFirst = battle_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] != 0) {
            gSpriteEntries[i + 0x21].scale_x -= 8;
            gSpriteEntries[i + 0x21].scale_y += 8;
        }
    }
    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partDamage[i] != 0) {
            gSpriteEntries[i + 0x24].scale_x -= 8;
            gSpriteEntries[i + 0x24].scale_y += 8;
        }
    }
    if (gSpriteEntries[0x21].scale_x == 8) {
        clear_battle_sprite_slot(0x21, 6);
        gBattleWork.step++;
    }
}

void medaforce_spy_game_apply_bonus(void) {
    add_u8_capped(&gBattleWork.traps[gBattleWork.actorSide].successBonus, gBattleWork.amount, 0xA0);
    subtract_u8_floored(&gBattleWork.traps[gBattleWork.otherSide].successBonus, gBattleWork.amount);
    gBattleWork.step++;
}

void medaforce_spy_game_finish(void) {
    gBattleWork.messageId = 0x5B;
    gBattleWork.step++;
}

// Opcode 0x60: Hide n Seek (Medaforce 0x24).
void medaforce_hide_n_seek_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceHideNSeekSteps[gBattleWork.step]();
}

void medaforce_hide_n_seek_domes_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gConcealDomeTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gConcealDomePalette, (void *)0x050002E0, 8);
    gBattleWork.targetSideFirst = battle_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[i + 0x21].frame_table = 0;
        gSpriteEntries[i + 0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[i + 0x21].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4;
        gSpriteEntries[i + 0x21].palette = 7;
        gSpriteEntries[i + 0x21].order = 0xF0;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x40], i + 0x21);
    }
    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partDamage[i] == 0)
            continue;
        gSpriteEntries[i + 0x24].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[i + 0x24].frame_table = 0;
        gSpriteEntries[i + 0x24].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[i + 0x24].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4;
        gSpriteEntries[i + 0x24].palette = 7;
        gSpriteEntries[i + 0x24].order = 0xF0;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x41], i + 0x24);
    }
    play_sound_effect(0x4D);
    gBattleWork.step++;
}

void medaforce_hide_n_seek_domes_anim_wait(void) {
    u32 i;

    gBattleWork.targetSideFirst = battle_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] != 0)
            process_sprite_anim_commands(gBattleSpriteAnimScripts[0x40], i + 0x21);
    }
    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partDamage[i] != 0)
            process_sprite_anim_commands(gBattleSpriteAnimScripts[0x41], i + 0x24);
    }
    if (gSpriteEntries[0x21].work[SPR_CMD_STATE] == SPR_CMD_ENDED) {
        clear_battle_sprite_slot(0x21, 6);
        gGameWork.stepCounter = 0;
        gBattleWork.step++;
    }
}

void medaforce_hide_n_seek_blink_wait(void) {
    u32 i;

    gGameWork.stepCounter++;
    gBattleWork.targetSideFirst = battle_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] != 0)
            battle_bot_sprites_blink(gBattleWork.targetSideFirst + i, gGameWork.stepCounter, 2);
    }
    if (gGameWork.stepCounter == 0x3C) {
        for (i = 0; i <= 2; i++) {
            if (gBattleWork.partBreaks[i] != 0)
                battle_bot_sprites_show(gBattleWork.targetSideFirst + i);
        }
        gBattleWork.step++;
    }
}

void medaforce_hide_n_seek_apply_evasion(void) {
    u32 i;

    gBattleWork.targetSideFirst = battle_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] != 0)
            add_u8_capped(&gBattleBots[gBattleWork.targetSideFirst + i].index + 1, gBattleWork.amount, 0x78);
    }
    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partDamage[i] != 0)
            subtract_u8_floored(&gBattleBots[gBattleWork.targetSideFirst + i].index + 1, gBattleWork.amount);
    }
    gBattleWork.step++;
}

void medaforce_hide_n_seek_finish(void) {
    gBattleWork.messageId = 0x5C;
    gBattleWork.step++;
}

// Opcode 0x61: Charge (Medaforce 0x26).
void medaforce_charge_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceChargeSteps[gBattleWork.step]();
}

void medaforce_charge_begin(void) {
    lz_decompress_dispatch(gMedaforceChargeTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceChargePalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = 0x78;
    gSpriteEntries[0x21].y = 0x40;
    gSpriteEntries[0x21].scale_x = 4;
    gSpriteEntries[0x21].scale_y = 4;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].frame = 0x7D00;
    play_sound_effect(0x6E);
    gBattleWork.step++;
}

void medaforce_center_sprite_grow(void) {
    if (gSpriteEntries[0x21].scale_x == 0x40) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x += 4;
        gSpriteEntries[0x21].scale_y += 4;
    }
}

void medaforce_center_sprite_shrink_half(void) {
    if (gSpriteEntries[0x21].scale_x == 0x20) {
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x -= 4;
        gSpriteEntries[0x21].scale_y -= 4;
    }
}

void medaforce_charge_check_targets(void) {
    u32 i;
    u32 found = 0;

    medaforce_clear_hit_list();
    gBattleWork.targetSideFirst = battle_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState != 0 &&
            gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor != 0 &&
            battle_bot_lacks_stability(gBattleWork.targetSideFirst + i) != 0) {
            gBattleWork.partBreaks[i] = 1;
            found = 1;
        }
    }
    if (!found)
        gBattleWork.step++;
    else
        gBattleWork.step += 3;
}

void medaforce_center_sprite_shrink_out(void) {
    if (gSpriteEntries[0x21].scale_x == 4) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x -= 4;
        gSpriteEntries[0x21].scale_y -= 4;
    }
}

void medaforce_charge_hourglass_spawn(void) {
    u32 i;

    clear_battle_sprite_slot(0x21, 1);
    lz_decompress_dispatch(gChargeHourglassTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gChargeHourglassPalette, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                         SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[i + 0x21].frame_table = 0;
        gSpriteEntries[i + 0x21].x = 0x78;
        gSpriteEntries[i + 0x21].y = 0x40;
        gSpriteEntries[i + 0x21].palette = 7;
        gSpriteEntries[i + 0x21].order = 0xF0;
        gSpriteEntries[i + 0x21].scale_x = 0x40;
        gSpriteEntries[i + 0x21].scale_y = 0x40;
        gSpriteEntries[i + 0x21].angle = 0;
        gSpriteEntries[i + 0x21].work16[FX_SPR_TARGET_X] =
            gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[i + 0x21].work16[FX_SPR_TARGET_Y] =
            gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4;
        gSpriteEntries[i + 0x21].work[SPR_MOTION_TABLE] = 6;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x42], i + 0x21);
    }
    gBattleWork.step++;
}

void medaforce_charge_hourglass_fly(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        count++;
        process_sprite_anim_commands(gBattleSpriteAnimScripts[0x42], i + 0x21);
        if (!(gBattleWork.actorSideFlags & 1))
            gSpriteEntries[i + 0x21].angle = (u16)(gSpriteEntries[i + 0x21].angle - 0x40) & 0x3FF;
        else
            gSpriteEntries[i + 0x21].angle = (u16)(gSpriteEntries[i + 0x21].angle + 0x40) & 0x3FF;
        if (move_sprite_toward_target(i + 0x21))
            done++;
    }
    if (done == count) {
        gSpriteEntries[0x21].angle = 0;
        gSpriteEntries[0x22].angle = 0;
        gSpriteEntries[0x23].angle = 0;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x43], 0x21);
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x43], 0x22);
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x43], 0x23);
        play_sound_effect(0x4E);
        gBattleWork.step++;
    }
}

void medaforce_charge_hourglass_burst_wait(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            process_sprite_anim_commands(gBattleSpriteAnimScripts[0x43], 0x21 + i);
            if (gSpriteEntries[0x21 + i].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
                done = 1;
        }
    }
    if (done)
        gBattleWork.step++;
}

void medaforce_charge_hourglass_shrink(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            gSpriteEntries[0x21 + i].scale_x -= 4;
            gSpriteEntries[0x21 + i].scale_y -= 4;
            if (gSpriteEntries[0x21 + i].scale_x == 4)
                done = 1;
        }
    }
    if (done) {
        clear_battle_sprite_slot(0x21, 3);
        gBattleWork.step++;
    }
}

void medaforce_charge_apply_buff(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            gBattleBots[gBattleWork.targetSideFirst + i].buffType = 0x26;
            gBattleBots[gBattleWork.targetSideFirst + i].buffPart = 0;
            gBattleBots[gBattleWork.targetSideFirst + i].buffTimer = clamp_1_99(gBattleWork.success);
            gBattleBots[gBattleWork.targetSideFirst + i].buffAmount = clamp_1_99(gBattleWork.amount);
        }
    }
    gBattleWork.step++;
}

void medaforce_charge_finish(void) {
    gBattleWork.messageId = 0x59;
    gBattleWork.step++;
}

// Opcode 0x62: Pushover Attk (Medaforce 0x27).
void medaforce_pushover_attack_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforcePushoverAttackSteps[gBattleWork.step]();
}

void medaforce_pushover_attack_begin(void) {
    u32 i;

    medaforce_clear_hit_list();
    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState &&
            gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor)
            gBattleWork.partBreaks[i] = 1;
    }
    gBattleWork.step++;
}

void medaforce_pushover_attack_banana_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gPushoverBananaTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gPushoverBananaPalette, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                         SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0x21 + i].frame_table = 0;
        gSpriteEntries[0x21 + i].x = 0x78;
        gSpriteEntries[0x21 + i].y = 0xF0;
        gSpriteEntries[0x21 + i].scale_x = 0x40;
        gSpriteEntries[0x21 + i].scale_y = 0x40;
        gSpriteEntries[0x21 + i].palette = 7;
        gSpriteEntries[0x21 + i].order = 0xF0;
        gSpriteEntries[0x21 + i].frame = 0x4D00;
        gSpriteEntries[0x21 + i].work[FX_FALL_ACCEL] = 4;
        gSpriteEntries[0x21 + i].work[FX_FALL_FRAC] = 0;
        gSpriteEntries[0x21 + i].work16[FX_FALL_SPEED] = 0;
        if (gBattleWork.actorSideFlags & 1)
            gSpriteEntries[0x21 + i].flags |= SPRITE_FLAG_HFLIP;
    }
    play_sound_effect(0x61);
    gBattleWork.step++;
}

void medaforce_pushover_attack_banana_drop(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            count++;
            if (sprite_move_toward_target(0x21 + i,
                                          gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4,
                                          gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y + 0x10)) {
                gSpriteEntries[0x21 + i].work16[FX_SPR_TARGET_X] =
                    gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
                gSpriteEntries[0x21 + i].work16[FX_SPR_TARGET_Y] =
                    gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4;
                gSpriteEntries[0x21 + i].work[SPR_MOTION_TABLE] = 6;
                done++;
            }
        }
    }
    if (done == count) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void medaforce_pushover_attack_banana_fly(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            count++;
            if (move_sprite_toward_target(0x21 + i))
                done++;
        }
    }
    if (done == count)
        gBattleWork.step++;
}

void medaforce_pushover_attack_target_hop_init(void) {
    u32 i;
    u32 j;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].work[FX_SPR_STEP] = 0;
        copy_bytes(&gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.targetSideFirst + i)],
                   &gSpriteEntries[(j = i * 4) + 0x24], 0x40);
        copy_bytes(&gSpriteEntries[BOT_SPRITE_RIGHT_ARM(gBattleWork.targetSideFirst + i)], &gSpriteEntries[j + 0x25],
                   0x40);
        copy_bytes(&gSpriteEntries[BOT_SPRITE_LEFT_ARM(gBattleWork.targetSideFirst + i)], &gSpriteEntries[j + 0x26],
                   0x40);
        copy_bytes(&gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)], &gSpriteEntries[j + 0x27], 0x40);
        disable_sprites(j + 0x24, 4);
        gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.targetSideFirst + i)].work[FX_SPR_STEP] = 0;
        gSpriteEntries[BOT_SPRITE_RIGHT_ARM(gBattleWork.targetSideFirst + i)].work[FX_SPR_STEP] = 0;
        gSpriteEntries[BOT_SPRITE_LEFT_ARM(gBattleWork.targetSideFirst + i)].work[FX_SPR_STEP] = 0;
        gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].work[FX_SPR_STEP] = 0;
        sprite_enable_affine_unit_scale(gBattleWork.targetSideFirst + 0x72 + i);
    }
    play_sound_effect(0x34);
    gBattleWork.step++;
}

void medaforce_pushover_attack_target_hop(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i, j;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        count++;
        if (gSpriteEntries[0x21 + i].flags & SPRITE_FLAG_ENABLED) {
            if (advance_sprite_anim_frame(0x21 + i, 0))
                clear_battle_sprite_slot(0x21 + i, 1);
            else if (!(gBattleWork.actorSideFlags & 1)) {
                gSpriteEntries[0x21 + i].x--;
                gSpriteEntries[0x21 + i].angle = (gSpriteEntries[0x21 + i].angle - 0x10) & 0x3FF;
            } else {
                gSpriteEntries[0x21 + i].x++;
                gSpriteEntries[0x21 + i].angle = (gSpriteEntries[0x21 + i].angle + 0x10) & 0x3FF;
            }
        }
        sprite_hop_step(BOT_SPRITE_HEAD(gBattleWork.targetSideFirst + i));
        sprite_hop_step(BOT_SPRITE_RIGHT_ARM(gBattleWork.targetSideFirst + i));
        sprite_hop_step(BOT_SPRITE_LEFT_ARM(gBattleWork.targetSideFirst + i));
        done += sprite_hop_step(BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i));
        if (gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].work[FX_SPR_STEP] == 0x10) {
            gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.targetSideFirst + i)].y += 8;
            gSpriteEntries[BOT_SPRITE_RIGHT_ARM(gBattleWork.targetSideFirst + i)].y -= 8;
            gSpriteEntries[BOT_SPRITE_LEFT_ARM(gBattleWork.targetSideFirst + i)].y -= 8;
            gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y -= 8;
            gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.targetSideFirst + i)].flags |= SPRITE_FLAG_VFLIP;
            gSpriteEntries[BOT_SPRITE_RIGHT_ARM(gBattleWork.targetSideFirst + i)].flags |= SPRITE_FLAG_VFLIP;
            gSpriteEntries[BOT_SPRITE_LEFT_ARM(gBattleWork.targetSideFirst + i)].flags |= SPRITE_FLAG_VFLIP;
            gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].flags |= SPRITE_FLAG_VFLIP;
        }
        check_sprite_overlap_and_adjust(BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i),
                                        gBattleWork.targetSideFirst + (j = i + 0x72));
    }
    if (done == count) {
        for (i = 0; i <= 2; i++) {
            if (gBattleWork.partBreaks[i])
                sprite_disable_affine((j = i + 0x72) + gBattleWork.targetSideFirst);
        }
        play_sound_effect(0x41);
        gBattleWork.step++;
    }
}

void medaforce_pushover_attack_burst_spawn(void) {
    u32 i, j;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        for (j = 0; j < 4; j++) {
            gSpriteEntries[0x30 + j + i * 4].flags =
                SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
            gSpriteEntries[0x30 + j + i * 4].frame_table = 0;
            gSpriteEntries[0x30 + j + i * 4].x = gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.targetSideFirst + i)].x;
            gSpriteEntries[0x30 + j + i * 4].y = gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.targetSideFirst + i)].y + 4;
            gSpriteEntries[0x30 + j + i * 4].palette = 7;
            gSpriteEntries[0x30 + j + i * 4].order = 0xF0;
            gSpriteEntries[0x30 + j + i * 4].work[SPR_MOTION_TABLE] = 6;
            gSpriteEntries[0x30 + j + i * 4].work[SPR_MOTION_ROW] = gBurstSpriteDirections[j];
            gSpriteEntries[0x30 + j + i * 4].frame = 0x4D01;
        }
    }
    gGameWork.stepCounter = 0;
    gBattleWork.step++;
}

void medaforce_pushover_attack_burst(void) {
    u32 i, j;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        for (j = 0; j < 4; j++)
            update_sprite_animation_position(0x30 + j + i * 4);
    }
    if (gGameWork.stepCounter == 0x10) {
        for (i = 0; i <= 2; i++) {
            if (gBattleWork.partBreaks[i] == 0)
                continue;
            copy_bytes(&gSpriteEntries[0x24 + i * 4], &gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.targetSideFirst + i)],
                       0x40);
            copy_bytes(&gSpriteEntries[0x25 + i * 4],
                       &gSpriteEntries[BOT_SPRITE_RIGHT_ARM(gBattleWork.targetSideFirst + i)], 0x40);
            copy_bytes(&gSpriteEntries[0x26 + i * 4],
                       &gSpriteEntries[BOT_SPRITE_LEFT_ARM(gBattleWork.targetSideFirst + i)], 0x40);
            copy_bytes(&gSpriteEntries[0x27 + i * 4], &gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)],
                       0x40);
            gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.targetSideFirst + i)].flags |= SPRITE_FLAG_ENABLED;
            gSpriteEntries[BOT_SPRITE_RIGHT_ARM(gBattleWork.targetSideFirst + i)].flags |= SPRITE_FLAG_ENABLED;
            gSpriteEntries[BOT_SPRITE_LEFT_ARM(gBattleWork.targetSideFirst + i)].flags |= SPRITE_FLAG_ENABLED;
            gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].flags |= SPRITE_FLAG_ENABLED;
        }
        clear_battle_sprite_slot(0x21, 0x1B);
        gBattleWork.step++;
    } else
        gGameWork.stepCounter++;
}

void apply_battle_damage_and_render(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        if (gBattleBots[gBattleWork.targetSideFirst + i].stateFlags & 4)
            battle_set_damage_vs_armor(gBattleWork.targetSideFirst + i, 0, 1);
        else
            battle_set_damage_vs_armor(gBattleWork.targetSideFirst + i, 0, gBattleWork.amount);
        gBattleWork.partDamage[i] = gBattleWork.appliedAmount;
        switch (i) {
        case 0:
            set_display_digit_type(gGameWork.textBuf, gBattleWork.appliedAmount, 1);
            battle_number_popup_init_slot(gGameWork.textBuf, gBattleWork.targetSideFirst + i, 0x21);
            break;
        case 1:
            set_display_digit_type(gGameWork.textBuf + 0x14, gBattleWork.appliedAmount, 1);
            battle_number_popup_init_slot(gGameWork.textBuf + 0x14, gBattleWork.targetSideFirst + 1, 0x21);
            break;
        case 2:
            set_display_digit_type(gGameWork.textBuf + 0x28, gBattleWork.appliedAmount, 1);
            battle_number_popup_init_slot(gGameWork.textBuf + 0x28, gBattleWork.targetSideFirst + 2, 0x21);
            break;
        }
    }
    play_sound_effect(0x5B);
    gGameWork.stepCounter = 0;
    gBattleWork.step++;
}

void medaforce_pushover_attack_damage_popup_wait(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            switch (i) {
            case 0:
                battle_popup_update_slot(gGameWork.textBuf, gBattleWork.targetSideFirst + i, 0x21);
                break;
            case 1:
                battle_popup_update_slot(gGameWork.textBuf + 0x14, gBattleWork.targetSideFirst + 1, 0x21);
                break;
            case 2:
                battle_popup_update_slot(gGameWork.textBuf + 0x28, gBattleWork.targetSideFirst + 2, 0x21);
                break;
            }
        }
    }
    gGameWork.stepCounter++;
    if (gGameWork.skipBotSetup == 0 && (KEYS_LO(gRepeatKeys) & A_BUTTON) && gGameWork.stepCounter > 0x32)
        gGameWork.stepCounter = 0x78;
    if (gGameWork.stepCounter == 0x78) {
        for (i = 0; i <= 2; i++) {
            if (gBattleWork.partBreaks[i])
                clear_battle_sprite_slot((gBattleWork.targetSideFirst + i) * 4 + 0x21, 4);
        }
        gBattleWork.step++;
    }
}

void apply_battle_damage_to_team(void) {
    u32 defeated = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        reduce_bot_part_stat(gBattleWork.targetSideFirst + i, 0, gBattleWork.partDamage[i]);
        if (gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor == 0) {
            add_bot_to_defeated_list(gBattleWork.targetSideFirst + i);
            gBattleWork.partBreaks[i] = 0x80;
            defeated = 1;
        } else if (!(gBattleBots[gBattleWork.targetSideFirst + i].stateFlags & 4))
            gBattleBots[gBattleWork.targetSideFirst + i].stateFlags |= 1;
    }
    if (defeated)
        gBattleWork.step = 0x10;
    else
        gBattleWork.step++;
}

void medaforce_pushover_attack_finish(void) {
    gBattleWork.messageId = 0x42;
    gBattleWork.step++;
}

// Opcode 0x63: Useless (Medaforce 0x29).
void medaforce_useless_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceUselessSteps[gBattleWork.step]();
}

void medaforce_useless_begin(void) {
    lz_decompress_dispatch(gMedaforceUselessTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceUselessPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = 0x78;
    gSpriteEntries[0x21].y = 0x40;
    gSpriteEntries[0x21].scale_x = 4;
    gSpriteEntries[0x21].scale_y = 4;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].frame = 0x7E00;
    play_sound_effect(0x6E);
    gBattleWork.step++;
}

void medaforce_useless_find_targets(void) {
    u32 found = 0;
    u32 i;

    medaforce_clear_hit_list();
    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState &&
            gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor &&
            battle_bot_lacks_stability(gBattleWork.targetSideFirst + i)) {
            gBattleWork.partBreaks[i] = (s8)bot_random_intact_part(gBattleWork.targetSideFirst + i) - 0x80;
            found = 1;
        }
    }
    if (!found)
        gBattleWork.step++;
    else
        gBattleWork.step += 3;
}

void medaforce_useless_orbs_spawn(void) {
    u32 i;

    clear_battle_sprite_slot(0x21, 1);
    lz_decompress_dispatch(gImpairPortraitTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gImpairPortraitPalette, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                         SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0x21 + i].frame_table = 0;
        gSpriteEntries[0x21 + i].x = 0x78;
        gSpriteEntries[0x21 + i].y = 0x40;
        gSpriteEntries[0x21 + i].palette = 7;
        gSpriteEntries[0x21 + i].order = 0xF0;
        gSpriteEntries[0x21 + i].scale_x = 0x40;
        gSpriteEntries[0x21 + i].scale_y = 0x40;
        gSpriteEntries[0x21 + i].angle = 0;
        gSpriteEntries[0x21 + i].work16[FX_SPR_TARGET_X] =
            gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[0x21 + i].work16[FX_SPR_TARGET_Y] =
            gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4;
        gSpriteEntries[0x21 + i].work[SPR_MOTION_TABLE] = 6;
        gSpriteEntries[0x21 + i].frame = 0x4E00;
    }
    gBattleWork.step++;
}

void medaforce_useless_orbs_fly(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            count++;
            if (!(gBattleWork.actorSideFlags & 1))
                gSpriteEntries[0x21 + i].angle = (gSpriteEntries[0x21 + i].angle - 0x40) & 0x3FF;
            else
                gSpriteEntries[0x21 + i].angle = (gSpriteEntries[0x21 + i].angle + 0x40) & 0x3FF;
            if (move_sprite_toward_target(0x21 + i))
                done++;
        }
    }
    if (done == count) {
        struct SpriteEntry *spr;
        s16 *pos;

        for (i = 0, spr = gSpriteEntries; i <= 2; i++) {
            if (gBattleWork.partBreaks[i] == 0)
                continue;
            disable_sprites(0x21 + i, 1);
            gSpriteEntries[0x24 + i].flags =
                SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
            spr[0x24 + i].frame_table = 0;
            pos = &gSpriteEntries[0x21 + i].x;
            gSpriteEntries[0x24 + i].x = pos[0];
            spr[0x24 + i].y = pos[1];
            spr[0x24 + i].palette = 7;
            spr[0x24 + i].order = 0xE0;
            spr[0x24 + i].angle = 0;
            spr[0x24 + i].work[FX_SPR_STEP] = 0;
            switch (gBattleWork.partBreaks[i] & 0x7F) {
            case 1:
                gSpriteEntries[0x24 + i].frame = 0x4E02;
                break;
            case 2:
                gSpriteEntries[0x24 + i].frame = 0x4E03;
                break;
            default:
                spr[0x24 + i].frame = 0x4E01;
                break;
            }
        }
        play_sound_effect(0x6A);
        gBattleWork.step++;
    }
}

void medaforce_useless_part_icons_wait(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            count++;
            if (advance_sprite_anim_frame(0x24 + i, 0))
                done++;
        }
    }
    if (done == count) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

// guess: sprite meaning unsure; set affine flags, scale 0x80 on target marks

void medaforce_useless_marks_scale_init(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            enable_sprites(0x21 + i, 1);
            gSpriteEntries[0x21 + i].flags |= SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
            gSpriteEntries[0x21 + i].scale_x = 0x80;
            gSpriteEntries[0x21 + i].scale_y = 0x80;
            gSpriteEntries[0x21 + i].angle = 0;
        }
    }
    gBattleWork.step++;
}

void medaforce_useless_marks_shrink(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            count++;
            if (gSpriteEntries[0x21 + i].scale_x == 0x40)
                done++;
            else {
                gSpriteEntries[0x21 + i].scale_x -= 8;
                gSpriteEntries[0x21 + i].scale_y -= 8;
            }
        }
    }
    if (done == count) {
        play_sound_effect(0x3C);
        gGameWork.stepTimer = 0;
        gBattleWork.step++;
    }
}

// guess: sprite meaning unsure; jitter marks x +/-2 for 0x3C frames, then clear sprites

void medaforce_useless_marks_shake(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            if (gGameWork.stepTimer & 4)
                gSpriteEntries[0x21 + i].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x - 2;
            else
                gSpriteEntries[0x21 + i].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x + 2;
        }
    }
    if (gGameWork.stepTimer == 0x3C) {
        clear_battle_sprite_slot(0x21, 6);
        gBattleWork.step++;
    } else
        gGameWork.stepTimer++;
}

void medaforce_useless_apply_impair(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gBattleBots[gBattleWork.targetSideFirst + i].statusType = 0x2B;
        gBattleBots[gBattleWork.targetSideFirst + i].statusTimer = clamp_1_99(gBattleWork.success);
        gBattleBots[gBattleWork.targetSideFirst + i].statusAmount = clamp_1_99(gBattleWork.amount);
        switch (gBattleWork.partBreaks[i] & 0x7F) {
        case 1:
            gBattleBots[gBattleWork.targetSideFirst + i].statusPart = 2;
            break;
        case 2:
            gBattleBots[gBattleWork.targetSideFirst + i].statusPart = 3;
            break;
        default:
            gBattleBots[gBattleWork.targetSideFirst + i].statusPart = 1;
            break;
        }
    }
    gBattleWork.step++;
}

void medaforce_useless_finish(void) {
    gBattleWork.messageId = 0x5E;
    gBattleWork.step++;
}

// Opcode 0x64: Destroyer (Medaforce 0x2A).
void medaforce_destroyer_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceDestroyerSteps[gBattleWork.step]();
}

void medaforce_destroyer_begin(void) {
    lz_decompress_dispatch(gMedaforceDestroyerTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceDestroyerPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].y = 0xE0;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    if (!(gBattleWork.actorSideFlags & 1))
        gSpriteEntries[0x21].x = 0xB8;
    else
        gSpriteEntries[0x21].x = 0x40;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x69], 0x21);
    gBattleWork.step++;
}

void medaforce_destroyer_descend(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x69], 0x21);
    if (gSpriteEntries[0x21].y == 0x40) {
        gGameWork.stepTimer = 0;
        gSpriteEntries[0x21].work[SPR_MOTION_ROW] = 0x14;
        gSpriteEntries[0x21].work[SPR_MOTION_TABLE] = 0;
        gSpriteEntries[0x21].work[FX_SWING_WAIT] = 0;
        gSpriteEntries[0x21].work[FX_SWING_POS] = 0;
        gBattleWork.step++;
    } else
        gSpriteEntries[0x21].y = (gSpriteEntries[0x21].y + 1) & 0xFF;
}

// guess: sprite meaning unsure; follow path table gDestroyerSwingFrames; at end clear sprite, goto step 10 (brighten)

void medaforce_destroyer_swing(void) {
    const u8 *tbl;

    if ((gGameWork.stepTimer & 0x1F) == 0 && gSpriteEntries[0x21].work[FX_SWING_POS] <= 7) {
        gBattleWork.step++;
        gGameWork.stepTimer++;
        return;
    }
    gGameWork.stepTimer++;
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x69], 0x21);
    update_sprite_animation_position(0x21);
    gSpriteEntries[0x21].work[SPR_MOTION_TABLE] = 4;
    if (gSpriteEntries[0x21].work[FX_SWING_WAIT]) {
        gSpriteEntries[0x21].work[FX_SWING_WAIT]--;
        return;
    }
    tbl = gDestroyerSwingFrames;
    gSpriteEntries[0x21].work[SPR_MOTION_ROW] = tbl[gSpriteEntries[0x21].work[FX_SWING_POS] * 2];
    if (gSpriteEntries[0x21].work[SPR_MOTION_ROW] == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step = 0xA;
        return;
    }
    if (gBattleWork.actorSideFlags & 1)
        gSpriteEntries[0x21].work[SPR_MOTION_ROW] = (0x20 - gSpriteEntries[0x21].work[SPR_MOTION_ROW]) & 0x1F;
    gSpriteEntries[0x21].work[FX_SWING_WAIT] = gDestroyerSwingFrames[gSpriteEntries[0x21].work[FX_SWING_POS] * 2 + 1];
    gSpriteEntries[0x21].work[FX_SWING_POS]++;
}

void medaforce_destroyer_flash_begin(void) {
    gSpriteEntries[0x21].frame = 0x7F02;
    play_sound_effect(0x38);
    gBattleWork.step++;
}

void medaforce_destroyer_flash_white(void) {
    bg_palettes_blend_masked_now(0x7FFF, gGameWork.stepCounter, 0xFFFF);
    obj_palettes_blend_masked_now(0x7FFF, gGameWork.stepCounter, 0xFF00);
    if (gGameWork.stepCounter == 0x20)
        gBattleWork.step++;
    else
        gGameWork.stepCounter += 2;
}

void medaforce_destroyer_flash_fade(void) {
    bg_palettes_blend_masked_now(0x1084, gGameWork.stepCounter, 0xFFFF);
    obj_palettes_blend_masked_now(0x1084, gGameWork.stepCounter, 0xFF00);
    if (gGameWork.stepCounter == 0x10)
        gBattleWork.step++;
    else
        gGameWork.stepCounter -= 2;
}

void medaforce_destroyer_goto_swing(void) {
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x69], 0x21);
    gBattleWork.step = 4;
}

void medaforce_destroyer_find_targets(void) {
    u32 found = 0;
    u32 i;

    medaforce_clear_hit_list();
    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState &&
            gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor &&
            (gBattleBots[gBattleWork.targetSideFirst + i].stateFlags & 4)) {
            gBattleWork.partBreaks[i] = 1;
            found = 1;
        }
    }
    if (!found)
        gBattleWork.step++;
    else
        gBattleWork.step += 2;
}

void medaforce_destroyer_marks_spawn(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                         SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0x21 + i].frame_table = 0;
        gSpriteEntries[0x21 + i].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[0x21 + i].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4;
        gSpriteEntries[0x21 + i].scale_x = 0x80;
        gSpriteEntries[0x21 + i].scale_y = 0x80;
        gSpriteEntries[0x21 + i].palette = 7;
        gSpriteEntries[0x21 + i].order = 0xF0;
        gSpriteEntries[0x21 + i].frame = 0x7F03;
    }
    play_sound_effect(0x54);
    gBattleWork.step++;
}

void medaforce_destroyer_marks_shrink(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            if (gSpriteEntries[0x21 + i].scale_x == 0x40)
                done = 1;
            else {
                gSpriteEntries[0x21 + i].scale_x -= 8;
                gSpriteEntries[0x21 + i].scale_y -= 8;
            }
        }
    }
    if (done) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void medaforce_destroyer_set_message(void) {
    clear_battle_sprite_slot(0x21, 3);
    gBattleWork.messageId = 0x43;
    gBattleWork.step++;
}

void medaforce_destroyer_apply_damage(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gBattleWork.partBreaks[i] = get_random_battle_weight_entry(gBattleWork.targetSideFirst + i);
        battle_set_damage_vs_armor(gBattleWork.targetSideFirst + i, gBattleWork.partBreaks[i], 0xC8);
        gBattleWork.partBreaks[i] |= gBattleWork.partBroken << 7;
        gBattleWork.partDamage[i] = gBattleWork.appliedAmount;
        gBattleBots[gBattleWork.targetSideFirst + i].parts[gBattleWork.partBreaks[i] & 0x7F].armor -=
            gBattleWork.partDamage[i];
        bot_halve_broken_leg_stats(gBattleWork.targetSideFirst + i);
        if ((gBattleWork.partBreaks[i] & 0x7F) == 0 && gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor == 0)
            add_bot_to_defeated_list(gBattleWork.targetSideFirst + i);
    }
    gBattleWork.step++;
}

void medaforce_destroyer_damage_popups_init(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            switch (i) {
            case 0:
                set_display_digit_type(gGameWork.textBuf, gBattleWork.partDamage[i], 1);
                battle_number_popup_init_slot(gGameWork.textBuf, gBattleWork.targetSideFirst + i, 0x21);
                break;
            case 1:
                set_display_digit_type(gGameWork.textBuf + 0x14, gBattleWork.partDamage[1], 1);
                battle_number_popup_init_slot(gGameWork.textBuf + 0x14, gBattleWork.targetSideFirst + 1, 0x21);
                break;
            case 2:
                set_display_digit_type(gGameWork.textBuf + 0x28, gBattleWork.partDamage[2], 1);
                battle_number_popup_init_slot(gGameWork.textBuf + 0x28, gBattleWork.targetSideFirst + 2, 0x21);
                break;
            }
        }
    }
    play_sound_effect(0x5B);
    gGameWork.stepCounter = 0;
    gBattleWork.step++;
}

void medaforce_destroyer_damage_popups_wait(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            switch (i) {
            case 0:
                battle_popup_update_slot(gGameWork.textBuf, gBattleWork.targetSideFirst + i, 0x21);
                break;
            case 1:
                battle_popup_update_slot(gGameWork.textBuf + 0x14, gBattleWork.targetSideFirst + 1, 0x21);
                break;
            case 2:
                battle_popup_update_slot(gGameWork.textBuf + 0x28, gBattleWork.targetSideFirst + 2, 0x21);
                break;
            }
        }
    }
    gGameWork.stepCounter++;
    if (gGameWork.skipBotSetup == 0 && (KEYS_LO(gRepeatKeys) & A_BUTTON) && gGameWork.stepCounter > 0x32)
        gGameWork.stepCounter = 0x78;
    if (gGameWork.stepCounter == 0x78) {
        clear_battle_sprite_slot(gBattleWork.targetSideFirst * 4 + 0x21, 0xC);
        gBattleWork.step++;
    }
}

// Opcode 0x65: Crazy Medaforce (Medaforce 0x2C).
void medaforce_crazy_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceCrazySteps[gBattleWork.step]();
}

void medaforce_crazy_find_targets(void) {
    u32 i;

    medaforce_clear_hit_list();
    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState &&
            gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor) {
            gBattleWork.partBreaks[i] = 1;
            gBattleWork.partDamage[i] = gBattleBots[gBattleWork.targetSideFirst + i].medaforceGauge;
        }
    }
    gBattleWork.step++;
}

void medaforce_crazy_orbs_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gForcedrainGlassTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gForcedrainGlassPalettes, (void *)0x050002E0, 0x10);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[0xA + i].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                        SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0xA + i].frame_table = 0;
        gSpriteEntries[0xA + i].x = 0x78;
        gSpriteEntries[0xA + i].y = 0x40;
        gSpriteEntries[0xA + i].scale_x = 4;
        gSpriteEntries[0xA + i].scale_y = 4;
        gSpriteEntries[0xA + i].angle = 0;
        gSpriteEntries[0xA + i].work16[FX_SPR_TARGET_X] =
            gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[0xA + i].work16[FX_SPR_TARGET_Y] =
            gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4;
        gSpriteEntries[0xA + i].work[SPR_MOTION_TABLE] = 6;
        gSpriteEntries[0xA + i].work[FX_SPR_STEP] = 0;
        gSpriteEntries[0xA + i].palette = 7;
        gSpriteEntries[0xA + i].order = 0xE0;
        gGameWork.stepCounter = 0x48;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[gGameWork.stepCounter], i + 0xA);
    }
    play_sound_effect(0x6A);
    gBattleWork.step++;
}

void medaforce_crazy_orbs_grow(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            if (gSpriteEntries[0xA + i].scale_x == 0x40)
                done = 1;
            else {
                gSpriteEntries[0xA + i].scale_x += 4;
                gSpriteEntries[0xA + i].scale_y += 4;
            }
        }
    }
    if (done) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void medaforce_crazy_orbs_fly(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            count++;
            if (!(gBattleWork.actorSideFlags & 1))
                gSpriteEntries[0xA + i].angle = (gSpriteEntries[0xA + i].angle - 0x40) & 0x3FF;
            else
                gSpriteEntries[0xA + i].angle = (gSpriteEntries[0xA + i].angle + 0x40) & 0x3FF;
            if (move_sprite_toward_target(0xA + i)) {
                gSpriteEntries[0xA + i].angle = 0;
                done++;
            }
        }
    }
    if (done == count) {
        for (i = 0; i <= 2; i++) {
            if (gBattleWork.partBreaks[i] && gBattleWork.partDamage[i])
                play_sound_effect(0x51);
        }
        gBattleWork.step++;
    }
}

void medaforce_crazy_drain_anim_wait(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            count++;
            if (gBattleWork.partDamage[i] == 0)
                done++;
            else {
                process_sprite_anim_commands(gBattleSpriteAnimScripts[gGameWork.stepCounter], 0xA + i);
                if (gSpriteEntries[0xA + i].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
                    done++;
            }
        }
    }
    if (done == count)
        gBattleWork.step++;
}

void medaforce_crazy_orbs_target_user(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            gSpriteEntries[0xA + i].work16[FX_SPR_TARGET_X] = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x;
            gSpriteEntries[0xA + i].work16[FX_SPR_TARGET_Y] = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
            gSpriteEntries[0xA + i].work[FX_SPR_STEP] = 0;
        }
    }
    gBattleWork.step++;
}

void medaforce_crazy_orbs_return(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            count++;
            if (gBattleWork.actorSideFlags & 1)
                gSpriteEntries[0xA + i].angle = (gSpriteEntries[0xA + i].angle - 0x40) & 0x3FF;
            else
                gSpriteEntries[0xA + i].angle = (gSpriteEntries[0xA + i].angle + 0x40) & 0x3FF;
            if (move_sprite_toward_target(0xA + i)) {
                gSpriteEntries[0xA + i].angle = 0;
                done++;
            }
        }
    }
    if (done == count) {
        play_sound_effect(0x2B);
        gBattleWork.step++;
    }
}

void medaforce_crazy_orbs_shrink(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            if (gSpriteEntries[0xA + i].scale_x == 2) {
                done = 1;
                clear_battle_sprite_slot(0xA + i, 1);
            } else {
                gSpriteEntries[0xA + i].scale_x -= 2;
                gSpriteEntries[0xA + i].scale_y -= 2;
            }
        }
    }
    if (done)
        gBattleWork.step++;
}

void medaforce_crazy_shots_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gMedaforceCrazyShotTiles, (void *)(OBJ_VRAM0 + 0x7000));
    CpuFastSet(gMedaforceCrazyShotPalette, (void *)0x050002E0, 8);
    lz_decompress_dispatch(gMissPopupTiles, (void *)(OBJ_VRAM0 + 0x4E00));
    CpuFastSet(gMedaforceActivatePalette, (void *)0x050002C0, 8);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].flags = SPRITE_PRIORITY(gBattleWork.battlefieldParams[3] + 2) | SPRITE_FLAG_ENABLED |
                                         SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0x21 + i].frame_table = 0;
        gSpriteEntries[0x21 + i].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x;
        gSpriteEntries[0x21 + i].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
        gSpriteEntries[0x21 + i].palette = 7;
        gSpriteEntries[0x21 + i].order = 0x81;
        gSpriteEntries[0x21 + i].work16[FX_SPR_TARGET_X] =
            gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[0x21 + i].work16[FX_SPR_TARGET_Y] =
            gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4;
        gSpriteEntries[0x21 + i].work[SPR_MOTION_TABLE] = 6;
        gSpriteEntries[0x21 + i].work[FX_SPR_STEP] = 0;
        gSpriteEntries[0x21 + i].work[PARTICLE_STATE] = 1;
        if (gBattleWork.actorSideFlags & 1)
            gSpriteEntries[0x21 + i].flags |= SPRITE_FLAG_HFLIP;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x6A], 0x21 + i);
    }
    gBattleWork.step++;
}

void medaforce_crazy_shots_wait(void) {
    if (particle_run_shot_handlers())
        gBattleWork.step++;
}

void medaforce_crazy_set_message(void) {
    gBattleWork.messageId = 0x67;
    gBattleWork.step++;
}

void medaforce_crazy_apply_damage(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gBattleBots[gBattleWork.targetSideFirst + i].medaforceGauge = 0;
        gBattleWork.partBreaks[i] = get_random_battle_weight_entry(gBattleWork.targetSideFirst + i);
        battle_set_damage_vs_armor(gBattleWork.targetSideFirst + i, gBattleWork.partBreaks[i],
                                   gBattleWork.partDamage[i]);
        gBattleWork.partBreaks[i] |= gBattleWork.partBroken << 7;
        gBattleWork.partDamage[i] = gBattleWork.appliedAmount;
        gBattleBots[gBattleWork.targetSideFirst + i].parts[gBattleWork.partBreaks[i] & 0x7F].armor -=
            gBattleWork.partDamage[i];
        bot_halve_broken_leg_stats(gBattleWork.targetSideFirst + i);
        if ((gBattleWork.partBreaks[i] & 0x7F) == 0 && gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor == 0)
            add_bot_to_defeated_list(gBattleWork.targetSideFirst + i);
    }
    gBattleWork.step++;
}

// Opcode 0x66: Medaforce Up (Medaforce 0x2D).
void medaforce_up_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceUpSteps[gBattleWork.step]();
}

void medaforce_up_find_targets(void) {
    u32 i;

    medaforce_clear_hit_list();
    gBattleWork.targetSideFirst = battle_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState &&
            gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor)
            gBattleWork.partBreaks[i] = 1;
    }
    gBattleWork.step++;
}

void medaforce_up_sparkles_spawn(void) {
    u32 i;

    lz_decompress_dispatch(gForcedrainGlassTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gForcedrainGlassPalettes, (void *)0x050002E0, 0x10);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                         SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0x21 + i].frame_table = 0;
        gSpriteEntries[0x21 + i].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[0x21 + i].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4;
        gSpriteEntries[0x21 + i].scale_x = 0x80;
        gSpriteEntries[0x21 + i].scale_y = 0x80;
        gSpriteEntries[0x21 + i].angle = 0;
        gSpriteEntries[0x21 + i].palette = 7;
        gSpriteEntries[0x21 + i].order = 0xE0;
        gGameWork.stepCounter = 0x48;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[gGameWork.stepCounter], i + 0x21);
    }
    play_sound_effect(0x6A);
    gBattleWork.step++;
}

void medaforce_up_sparkles_shrink(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            if (gSpriteEntries[0x21 + i].scale_x == 0x40)
                done = 1;
            else {
                gSpriteEntries[0x21 + i].scale_x -= 4;
                gSpriteEntries[0x21 + i].scale_y -= 4;
            }
        }
    }
    if (done) {
        play_sound_effect(0x51);
        gBattleWork.step++;
    }
}

void medaforce_up_sparkles_anim_wait(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            process_sprite_anim_commands(gBattleSpriteAnimScripts[gGameWork.stepCounter], 0x21 + i);
            if (gSpriteEntries[0x21 + i].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
                done = 1;
        }
    }
    if (done) {
        gGameWork.stepTimer = 0x20;
        gBattleWork.step++;
    }
}

void decrement_timer_and_decompress_sprite(void) {
    u32 i;

    if (gGameWork.stepTimer) {
        gGameWork.stepTimer--;
        return;
    }
    lz_decompress_dispatch(gMedaforceUpTiles, (void *)(OBJ_VRAM0 + 0x5400));
    CpuFastSet(gEffectCommonPalette, (void *)0x050002C0, 8);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[0x24 + i].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                         SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0x24 + i].frame_table = 0;
        gSpriteEntries[0x24 + i].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].x;
        gSpriteEntries[0x24 + i].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4;
        gSpriteEntries[0x24 + i].scale_x = 0x40;
        gSpriteEntries[0x24 + i].scale_y = 0x40;
        gSpriteEntries[0x24 + i].angle = 0;
        gSpriteEntries[0x24 + i].palette = 6;
        gSpriteEntries[0x24 + i].order = 0xF0;
        gSpriteEntries[0x24 + i].work[FX_SPR_STEP] = 0;
        gSpriteEntries[0x24 + i].frame = 0x8100;
    }
    play_sound_effect(0x2A);
    gBattleWork.step++;
}

// guess: sprite meaning unsure; sprite_slide_x_step on icons 0x24+, timer 0x3C

void medaforce_up_arrows_slide_wait(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] && sprite_slide_x_step(0x24 + i, 0))
            done = 1;
    }
    if (done) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void medaforce_up_sprites_shrink(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            if (gSpriteEntries[0x21 + i].scale_x == 4)
                done = 1;
            else {
                gSpriteEntries[0x21 + i].scale_x -= 4;
                gSpriteEntries[0x21 + i].scale_y -= 4;
                gSpriteEntries[0x24 + i].scale_x -= 4;
                gSpriteEntries[0x24 + i].scale_y -= 4;
            }
        }
    }
    if (done) {
        clear_battle_sprite_slot(0x21, 6);
        gBattleWork.step++;
    }
}

void medaforce_up_apply_gauge_boost(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i])
            gBattleBots[gBattleWork.targetSideFirst + i].guardFlags |= 8;
    }
    gBattleWork.step++;
}

void medaforce_up_finish(void) {
    gBattleWork.messageId = 0x68;
    gBattleWork.step++;
}

// Opcode 0x67: Formation Orders (Medaforce 0x2E).
void medaforce_formation_orders_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceFormationOrdersSteps[gBattleWork.step]();
}

void medaforce_formation_orders_begin(void) {
    lz_decompress_dispatch(gSkillCastHopTiles, (void *)(OBJ_VRAM0 + 0x5800));
    CpuFastSet(gSkillCastHopPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE |
                                 SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x;
    gSpriteEntries[0x21].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].frame = 0x4100;
    gSpriteEntries[0x21].work[FX_SPR_STEP] = 0;
    gSpriteEntries[0x21].work[FX_SPR_FRAMES] = 0;
    play_sound_effect(0x29);
    gBattleWork.step++;
}

void medaforce_formation_orders_first_hop(void) {
    sprite_hop_step(0x21);
    if (gSpriteEntries[0x21].work[FX_SPR_FRAMES] == 0x20) {
        gSpriteEntries[0x21].angle = 0;
        gGameWork.stepCounter = 1;
        gBattleWork.step++;
        return;
    }
    if (!(gBattleWork.actorSideFlags & 1))
        gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle + 0x20) & 0x3FF;
    else
        gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle - 0x20) & 0x3FF;
    if (!(gSpriteEntries[0x21].work[FX_SPR_FRAMES] & 1)) {
        if (!(gBattleWork.actorSideFlags & 1))
            gSpriteEntries[0x21].x++;
        else
            gSpriteEntries[0x21].x--;
    }
    gSpriteEntries[0x21].work[FX_SPR_FRAMES]++;
}

void medaforce_formation_orders_next_spawn(void) {
    gSpriteEntries[gGameWork.stepCounter + 0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[gGameWork.stepCounter + 0x21].frame_table = 0;
    gSpriteEntries[gGameWork.stepCounter + 0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x;
    gSpriteEntries[gGameWork.stepCounter + 0x21].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[gGameWork.stepCounter + 0x21].palette = 7;
    gSpriteEntries[gGameWork.stepCounter + 0x21].order = 0xF0;
    gSpriteEntries[gGameWork.stepCounter + 0x21].scale_x = 0x40;
    gSpriteEntries[gGameWork.stepCounter + 0x21].scale_y = 0x40;
    gSpriteEntries[gGameWork.stepCounter + 0x21].angle = 0;
    gSpriteEntries[gGameWork.stepCounter + 0x21].frame = 0x4100;
    gSpriteEntries[gGameWork.stepCounter + 0x21].work[FX_SPR_STEP] = 0;
    gSpriteEntries[gGameWork.stepCounter + 0x21].work[FX_SPR_FRAMES] = 0;
    play_sound_effect(0x29);
    gBattleWork.step++;
}

void medaforce_formation_orders_next_hop(void) {
    sprite_hop_step(gGameWork.stepCounter + 0x21);
    if (gSpriteEntries[gGameWork.stepCounter + 0x21].work[FX_SPR_FRAMES] == 0x20) {
        clear_battle_sprite_slot(gGameWork.stepCounter + 0x21, 1);
        gSpriteEntries[0x21].scale_x += gGameWork.stepCounter << 4;
        gSpriteEntries[0x21].scale_y += gGameWork.stepCounter << 4;
        if (++gGameWork.stepCounter == 4)
            gBattleWork.step++;
        else
            gBattleWork.step = 2;
        return;
    }
    if (!(gBattleWork.actorSideFlags & 1))
        gSpriteEntries[gGameWork.stepCounter + 0x21].angle =
            (gSpriteEntries[gGameWork.stepCounter + 0x21].angle + 0x20) & 0x3FF;
    else
        gSpriteEntries[gGameWork.stepCounter + 0x21].angle =
            (gSpriteEntries[gGameWork.stepCounter + 0x21].angle - 0x20) & 0x3FF;
    if (!(gSpriteEntries[gGameWork.stepCounter + 0x21].work[FX_SPR_FRAMES] & 1)) {
        if (!(gBattleWork.actorSideFlags & 1))
            gSpriteEntries[gGameWork.stepCounter + 0x21].x++;
        else
            gSpriteEntries[gGameWork.stepCounter + 0x21].x--;
    }
    gSpriteEntries[gGameWork.stepCounter + 0x21].work[FX_SPR_FRAMES]++;
}

void medaforce_formation_orders_target_user(void) {
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_X] = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_Y] = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x21].work[SPR_MOTION_TABLE] = 4;
    gSpriteEntries[0x21].work[FX_SPR_STEP] = 0;
    gBattleWork.step++;
}

void medaforce_formation_orders_move(void) {
    if (move_sprite_toward_target(0x21)) {
        play_sound_effect(0x2B);
        gBattleWork.step++;
    }
}

void medaforce_formation_orders_shrink(void) {
    if (gSpriteEntries[0x21].scale_x == 4) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x -= 4;
        gSpriteEntries[0x21].scale_y -= 4;
    }
}

void medaforce_formation_orders_burst_spawn(void) {
    lz_decompress_dispatch(gMedaforceUpArrowTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceUpArrowPalettes, (void *)0x050002E0, 0x10);
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x;
    gSpriteEntries[0x21].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x68], 0x21);
    play_sound_effect(0x2C);
    gBattleWork.step++;
}

void medaforce_formation_orders_burst_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x68], 0x21);
    if (gSpriteEntries[0x21].work[SPR_CMD_STATE] == SPR_CMD_ENDED) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    }
}

void medaforce_formation_orders_apply_trap_boost(void) {
    add_u8_capped(&gBattleBots[gBattleWork.actor].powerBonus + 5, gBattleWork.amount, 0xFF);
    gBattleWork.step++;
}

void medaforce_formation_orders_finish(void) {
    gBattleWork.messageId = 0x51;
    gBattleWork.step++;
}

// Opcode 0x68: Leg Crash (Medaforce 0x2F).
void medaforce_leg_crash_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceLegCrashSteps[gBattleWork.step]();
}

void medaforce_leg_crash_find_targets(void) {
    u32 i;

    medaforce_clear_hit_list();
    gBattleWork.targetSideFirst = battle_enemy_side_first_record(gBattleWork.actor);
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[gBattleWork.targetSideFirst + i].teamState &&
            gBattleBots[gBattleWork.targetSideFirst + i].parts[0].armor) {
            gBattleWork.partBreaks[i] = 1;
            gBattleWork.partDamage[i] = gBattleBots[gBattleWork.targetSideFirst + i].parts[3].armor;
        }
    }
    gBattleWork.step++;
}

void medaforce_leg_crash_begin(void) {
    u32 i;

    lz_decompress_dispatch(gMedaforceLegCrashTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceLegCrashPalette, (void *)0x050002E0, 8);
    CpuFastSet(gEffectCommonPalette, (void *)0x050002C0, 8);
    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0x21 + i].frame_table = 0;
        gSpriteEntries[0x21 + i].x = 0x78;
        gSpriteEntries[0x21 + i].y = 0xF0;
        gSpriteEntries[0x21 + i].palette = 7;
        gSpriteEntries[0x21 + i].order = 0xF0;
        gSpriteEntries[0x21 + i].work[FX_FALL_ACCEL] = 4;
        gSpriteEntries[0x21 + i].work[FX_FALL_FRAC] = 0;
        gSpriteEntries[0x21 + i].work16[FX_FALL_SPEED] = 0;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x6D], 0x21 + i);
        if (gBattleWork.actorSideFlags & 1)
            gSpriteEntries[0x21 + i].flags |= SPRITE_FLAG_HFLIP;
    }
    play_sound_effect(0x61);
    gBattleWork.step++;
}

void medaforce_leg_crash_drop(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i]) {
            count++;
            if (sprite_move_toward_target(0x21 + i,
                                          gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y - 4,
                                          gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.targetSideFirst + i)].y + 0x10)) {
                gSpriteEntries[0x21 + i].work[PARTICLE_SWEEP_TIMER] = 0;
                gSpriteEntries[0x21 + i].work[PARTICLE_SWEEP_HIT] = 0;
                gSpriteEntries[0x21 + i].work[PARTICLE_STATE] = 1;
                done++;
            }
        }
    }
    if (done == count) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void medaforce_leg_crash_sound(void) {
    play_sound_effect(0x22);
    gBattleWork.step++;
}

void medaforce_leg_crash_sweep_wait(void) {
    if (particle_run_sweep_handlers())
        gBattleWork.step++;
}

void medaforce_leg_crash_check_legs(void) {
    u32 found = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] && gBattleWork.partDamage[i])
            found = 1;
    }
    if (!found)
        gBattleWork.step++;
    else
        gBattleWork.step += 2;
}

void medaforce_leg_crash_apply_damage(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleWork.partBreaks[i] && gBattleWork.partDamage[i]) {
            gBattleWork.partBreaks[i] = 3;
            battle_set_damage_vs_armor(gBattleWork.targetSideFirst + i, 3, gBattleWork.partDamage[i]);
            gBattleWork.partBreaks[i] |= gBattleWork.partBroken << 7;
            gBattleWork.partDamage[i] = gBattleWork.appliedAmount;
            gBattleBots[gBattleWork.targetSideFirst + i].parts[gBattleWork.partBreaks[i] & 0x7F].armor -=
                gBattleWork.partDamage[i];
            bot_halve_broken_leg_stats(gBattleWork.targetSideFirst + i);
        }
    }
    gBattleWork.step++;
}

// Opcode 0x69: Protector (Medaforce 0x30).
void medaforce_protector_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceProtectorSteps[gBattleWork.step]();
}

void medaforce_protector_begin(void) {
    lz_decompress_dispatch(gMedaforceProtectorTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceProtectorPalettes, (void *)0x050002C0, 8);
    CpuFastSet(gEffectCommonPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 0x1C;
    gSpriteEntries[0x21].palette = 6;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].frame = 0x8300;
    if (!(gBattleWork.actorSideFlags & 1))
        gSpriteEntries[0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x - 0x18;
    else
        gSpriteEntries[0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x + 0x18;
    gSpriteEntries[0x22].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x22].frame_table = 0;
    gSpriteEntries[0x22].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 0x1C;
    gSpriteEntries[0x22].palette = 7;
    gSpriteEntries[0x22].order = 0xF1;
    gSpriteEntries[0x22].frame = 0x8301;
    if (!(gBattleWork.actorSideFlags & 1))
        gSpriteEntries[0x22].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x + 0x18;
    else {
        gSpriteEntries[0x22].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x - 0x18;
        gSpriteEntries[0x22].flags |= SPRITE_FLAG_HFLIP;
    }
    gGameWork.stepTimer = 0;
    play_sound_effect(0x2B);
    gBattleWork.step++;
}

void medaforce_protector_halves_close(void) {
    if (gGameWork.stepTimer == 0x18) {
        gGameWork.stepTimer = 0;
        gBattleWork.step++;
        return;
    }
    gGameWork.stepTimer++;
    if (!(gBattleWork.actorSideFlags & 1)) {
        gSpriteEntries[0x21].x++;
        gSpriteEntries[0x22].x--;
    } else {
        gSpriteEntries[0x21].x--;
        gSpriteEntries[0x22].x++;
    }
}

void medaforce_protector_halves_lower(void) {
    if (gGameWork.stepTimer == 0xC) {
        gBattleWork.step++;
        return;
    }
    gGameWork.stepTimer++;
    gSpriteEntries[0x21].y += 2;
    gSpriteEntries[0x22].y += 2;
}

void medaforce_protector_shield_spawn(void) {
    clear_battle_sprite_slot(0x21, 2);
    CpuFastSet(gMedaforceProtectorPalettes, (void *)0x050002C0, 0x10);
    gSpriteEntries[0x21].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE |
                                 SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x;
    gSpriteEntries[0x21].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].scale_x = 0x80;
    gSpriteEntries[0x21].scale_y = 0x80;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].frame = 0x8302;
    gBattleWork.step++;
}

void medaforce_protector_shield_shrink(void) {
    if (gSpriteEntries[0x21].scale_x == 0x40) {
        play_sound_effect(0x54);
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x -= 8;
        gSpriteEntries[0x21].scale_y -= 8;
    }
}

void medaforce_protector_shield_grow(void) {
    if (gSpriteEntries[0x21].scale_x == 0x60)
        gBattleWork.step++;
    else {
        gSpriteEntries[0x21].scale_x += 4;
        gSpriteEntries[0x21].scale_y += 4;
    }
}

void medaforce_protector_shield_settle(void) {
    if (gSpriteEntries[0x21].scale_x == 0x40) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x -= 4;
        gSpriteEntries[0x21].scale_y -= 4;
    }
}

void medaforce_protector_shield_vanish(void) {
    if (gSpriteEntries[0x21].scale_x == 4) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x -= 4;
        gSpriteEntries[0x21].scale_y -= 4;
    }
}

void medaforce_protector_apply_protect(void) {
    gBattleBots[gBattleWork.actor].guardFlags |= 1;
    gBattleWork.step++;
}

void medaforce_protector_finish(void) {
    gBattleWork.messageId = 0x4F;
    gBattleWork.step++;
}

// Opcode 0x6A: Anti-Protection (Medaforce 0x31).
void medaforce_anti_protection_run(void) {
    gBattleWork.stepDone = 0;
    gMedaforceAntiProtectionSteps[gBattleWork.step]();
}

void medaforce_anti_protection_begin(void) {
    lz_decompress_dispatch(gMedaforceAntiProtectionTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gMedaforceProtectorPalettes, (void *)0x050002C0, 8);
    CpuFastSet(gEffectCommonPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 0x1C;
    gSpriteEntries[0x21].palette = 6;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].frame = 0x8400;
    if (!(gBattleWork.actorSideFlags & 1))
        gSpriteEntries[0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x - 0x18;
    else
        gSpriteEntries[0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x + 0x18;
    gSpriteEntries[0x22].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x22].frame_table = 0;
    gSpriteEntries[0x22].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 0x1C;
    gSpriteEntries[0x22].palette = 6;
    gSpriteEntries[0x22].order = 0xF0;
    gSpriteEntries[0x22].frame = 0x8401;
    if (!(gBattleWork.actorSideFlags & 1))
        gSpriteEntries[0x22].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x - 0x18;
    else
        gSpriteEntries[0x22].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x + 0x18;
    gSpriteEntries[0x23].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x23].frame_table = 0;
    gSpriteEntries[0x23].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 0x1C;
    gSpriteEntries[0x23].palette = 7;
    gSpriteEntries[0x23].order = 0xF1;
    gSpriteEntries[0x23].frame = 0x8402;
    if (!(gBattleWork.actorSideFlags & 1))
        gSpriteEntries[0x23].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x + 0x18;
    else {
        gSpriteEntries[0x23].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x - 0x18;
        gSpriteEntries[0x23].flags |= SPRITE_FLAG_HFLIP;
    }
    gSpriteEntries[0x24].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x24].frame_table = 0;
    gSpriteEntries[0x24].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 0x1C;
    gSpriteEntries[0x24].palette = 7;
    gSpriteEntries[0x24].order = 0xF1;
    gSpriteEntries[0x24].frame = 0x8403;
    if (!(gBattleWork.actorSideFlags & 1))
        gSpriteEntries[0x24].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x + 0x18;
    else {
        gSpriteEntries[0x24].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x - 0x18;
        gSpriteEntries[0x24].flags |= SPRITE_FLAG_HFLIP;
    }
    gGameWork.stepTimer = 0;
    play_sound_effect(0x2B);
    gBattleWork.step++;
}

void medaforce_anti_protection_pieces_close(void) {
    if (gGameWork.stepTimer == 0x18) {
        gGameWork.stepTimer = 0;
        gBattleWork.step++;
        return;
    }
    gGameWork.stepTimer++;
    if (!(gBattleWork.actorSideFlags & 1)) {
        gSpriteEntries[0x21].x++;
        gSpriteEntries[0x22].x++;
        gSpriteEntries[0x23].x--;
        gSpriteEntries[0x24].x--;
    } else {
        gSpriteEntries[0x21].x--;
        gSpriteEntries[0x22].x--;
        gSpriteEntries[0x23].x++;
        gSpriteEntries[0x24].x++;
    }
}

void medaforce_anti_protection_pieces_lower(void) {
    if (gGameWork.stepTimer == 0xC) {
        gBattleWork.step++;
        return;
    }
    gGameWork.stepTimer++;
    gSpriteEntries[0x21].y += 2;
    gSpriteEntries[0x22].y += 2;
    gSpriteEntries[0x23].y += 2;
    gSpriteEntries[0x24].y += 2;
}

void medaforce_anti_protection_break_spawn(void) {
    gSpriteEntries[0x25].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x25].frame_table = 0;
    gSpriteEntries[0x25].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x;
    gSpriteEntries[0x25].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x25].palette = 7;
    gSpriteEntries[0x25].order = 0xF2;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x6F], 0x25);
    if (gBattleWork.actorSideFlags & 1)
        gSpriteEntries[0x25].flags |= SPRITE_FLAG_HFLIP;
    play_sound_effect(0x30);
    gBattleWork.step++;
}

void medaforce_anti_protection_break_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x6F], 0x25);
    if (gSpriteEntries[0x25].work[SPR_CMD_STATE] == SPR_CMD_ENDED) {
        gGameWork.stepTimer = 0;
        clear_battle_sprite_slot(0x25, 1);
        gBattleWork.step++;
    }
}

void medaforce_anti_protection_pieces_split(void) {
    if (gGameWork.stepTimer == 0x20) {
        gGameWork.stepTimer = 0;
        gBattleWork.step++;
        return;
    }
    if (gGameWork.stepTimer & 1) {
        if (!(gBattleWork.actorSideFlags & 1)) {
            gSpriteEntries[0x21].x = (gSpriteEntries[0x21].x - 1) & 0x1FF;
            gSpriteEntries[0x22].x = (gSpriteEntries[0x22].x + 1) & 0x1FF;
            gSpriteEntries[0x23].x = (gSpriteEntries[0x23].x - 1) & 0x1FF;
            gSpriteEntries[0x24].x = (gSpriteEntries[0x24].x + 1) & 0x1FF;
        } else {
            gSpriteEntries[0x21].x = (gSpriteEntries[0x21].x + 1) & 0x1FF;
            gSpriteEntries[0x22].x = (gSpriteEntries[0x22].x - 1) & 0x1FF;
            gSpriteEntries[0x23].x = (gSpriteEntries[0x23].x + 1) & 0x1FF;
            gSpriteEntries[0x24].x = (gSpriteEntries[0x24].x - 1) & 0x1FF;
        }
    }
    gGameWork.stepTimer++;
}

// guess: sprite meaning unsure; drift pieces vertically while flickering, then clear

void medaforce_anti_protection_pieces_scatter(void) {
    if (gGameWork.stepTimer == 0x20) {
        clear_battle_sprite_slot(0x21, 4);
        gGameWork.stepTimer = 0;
        gBattleWork.step++;
        return;
    }
    if (!(gGameWork.stepTimer & 3)) {
        gSpriteEntries[0x21].y = (gSpriteEntries[0x21].y - 1) & 0xFF;
        gSpriteEntries[0x22].y = (gSpriteEntries[0x22].y + 1) & 0xFF;
        gSpriteEntries[0x23].y = (gSpriteEntries[0x23].y - 1) & 0xFF;
        gSpriteEntries[0x24].y = (gSpriteEntries[0x24].y + 1) & 0xFF;
    }
    if (gGameWork.stepTimer & 1) {
        gSpriteEntries[0x21].flags |= SPRITE_FLAG_ENABLED;
        gSpriteEntries[0x22].flags |= SPRITE_FLAG_ENABLED;
        gSpriteEntries[0x23].flags |= SPRITE_FLAG_ENABLED;
        gSpriteEntries[0x24].flags |= SPRITE_FLAG_ENABLED;
    } else {
        gSpriteEntries[0x21].flags &= (u16)~SPRITE_FLAG_ENABLED;
        gSpriteEntries[0x22].flags &= (u16)~SPRITE_FLAG_ENABLED;
        gSpriteEntries[0x23].flags &= (u16)~SPRITE_FLAG_ENABLED;
        gSpriteEntries[0x24].flags &= (u16)~SPRITE_FLAG_ENABLED;
    }
    gGameWork.stepTimer++;
}

void medaforce_anti_protection_apply(void) {
    gBattleBots[gBattleWork.actor].guardFlags |= 4;
    gBattleWork.step++;
}

void medaforce_anti_protection_finish(void) {
    gBattleWork.messageId = 0x6A;
    gBattleWork.step++;
}
