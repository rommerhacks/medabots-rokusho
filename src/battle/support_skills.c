// Effect sequences of the Support abilities: action script opcodes 0x30-0x35.
// Each runner (*_run: clears stepDone and calls entry [step] of its step table) is one action script command
// (gActionScriptCommands, opcode order = ROM order); its step handlers follow it and the last step sets stepDone.
// Abilities are part data[1], and the script of ability n is gActionScripts[n]:
//   0x30 Scout (36), 0x31 Conceal (37), 0x32 Boost Chrg (38), 0x33 Rapid Chrg (39), 0x34 Drain Chrg (41),
//   0x35 Pushover (42; guess, see pushover_run). Ability 40 (Accel Chrg) has an empty script: it works
//   while equipped. Skill names from the parts that carry them (re/tables/parts.json) and a public FAQ.
// The *_begin step of each sequence ends the action on a battle time-out (messageId 0x1A); otherwise it skips
// the time-out steps 1-3 and starts the effect at step 4. A target with a working Stability part shrugs off
// the Charge effects (messageId 0x39, battle_bot_lacks_stability).

#include "global.h"
#include "constants/skill_sprites.h"
#include "constants/sprites.h"

void scout_run(void) {
    gBattleWork.stepDone = 0;
    gScoutSteps[gBattleWork.step]();
}

void scout_begin(void) {
    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
        gBattleWork.step = 4;
    }
}

void scout_load_graphics(void) {
    lz_decompress_dispatch(gScoutTilesLz, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gScoutPalettes, (void *)0x050002C0, 0x10);
    gBattleWork.step++;
}

void scout_darken_init(void) {
    palette_backup_from_hardware();
    gGameWork.stepCounter = 0;
    gBattleWork.step++;
}

void scout_darken(void) {
    bg_palettes_blend_masked_now(0x1084, gGameWork.stepCounter, 0xFFFF);
    obj_palettes_blend_masked_now(0x1084, gGameWork.stepCounter, 0xFF00);
    if (gGameWork.stepCounter == 0x10)
        gBattleWork.step++;
    else
        gGameWork.stepCounter++;
}

void scout_beam_spawn(void) {
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x;
    gSpriteEntries[0x21].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x21].palette = 6;
    gSpriteEntries[0x21].order = 0xF0;
    gSpriteEntries[0x21].frame = 0x4800;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].work[FX_SPR_TIMER] = 0;
    play_sound_effect(0x4C);
    gBattleWork.step++;
}

void scout_beam_spin(void) {
    if (gSpriteEntries[0x21].work[FX_SPR_TIMER] == 0x40) {
        clear_battle_sprite_slot(0x21, 2);
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].work[FX_SPR_TIMER]++;
        gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle + 0x10) & 0x3FF;
    }
}

void scout_brighten(void) {
    bg_palettes_blend_masked_now(0x1084, gGameWork.stepCounter, 0xFFFF);
    obj_palettes_blend_masked_now(0x1084, gGameWork.stepCounter, 0xFF00);
    if (gGameWork.stepCounter == 0)
        gBattleWork.step++;
    else
        gGameWork.stepCounter--;
}

void scout_arrows_spawn(void) {
    u32 i;
    u32 first = battle_side_first_record(gBattleWork.actor);

    for (i = 0; i < 3; i++) {
        if (gBattleBots[first + i].teamState) {
            gSpriteEntries[0x21 + i].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                             SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
            gSpriteEntries[0x21 + i].frame_table = 0;
            gSpriteEntries[0x21 + i].x = gSpriteEntries[BOT_SPRITE_LEGS(first + i)].x;
            gSpriteEntries[0x21 + i].y = gSpriteEntries[BOT_SPRITE_LEGS(first + i)].y;
            gSpriteEntries[0x21 + i].palette = 7;
            gSpriteEntries[0x21 + i].order = 0xF0;
            gSpriteEntries[0x21 + i].scale_x = 0x40;
            gSpriteEntries[0x21 + i].scale_y = 0x40;
            gSpriteEntries[0x21 + i].frame = 0x4801;
        }
    }
    gGameWork.stepTimer = 0;
    play_sound_effect(0x2E);
    gBattleWork.step++;
}

void scout_arrows_rise(void) {
    u32 i;

    if (gGameWork.stepTimer == 0x14) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    } else {
        gGameWork.stepTimer++;
        for (i = 0; i < 3; i++) {
            if (gSpriteEntries[0x21 + i].flags & SPRITE_FLAG_ENABLED)
                gSpriteEntries[0x21 + i].y--;
        }
    }
}

void scout_arrows_shrink(void) {
    u32 i;

    for (i = 0; i < 3; i++) {
        if (gSpriteEntries[0x21 + i].flags & SPRITE_FLAG_ENABLED) {
            gSpriteEntries[0x21 + i].scale_x -= 8;
            gSpriteEntries[0x21 + i].scale_y += 8;
        }
    }
    if (gSpriteEntries[0x21].scale_x == 8) {
        clear_battle_sprite_slot(0x21, 3);
        gBattleWork.step++;
    }
}

// Raises the side bonus traps[side].successBonus by gBattleWork.amount (up to 0xA0): Scout raises Power and success for
// the team.
void scout_apply_bonus(void) {
    add_u8_capped(&gBattleWork.traps[gBattleWork.actorSide].successBonus, gBattleWork.amount, 0xA0);
    gBattleWork.step++;
}

void scout_finish(void) {
    gBattleWork.messageId = 0x1C;
    gBattleWork.step++;
}

void conceal_run(void) {
    gBattleWork.stepDone = 0;
    gConcealSteps[gBattleWork.step]();
}

void conceal_begin(void) {
    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
        gBattleWork.step = 4;
    }
}

void conceal_dome_spawn(void) {
    lz_decompress_dispatch(gConcealDomeTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gConcealDomePalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x;
    gSpriteEntries[0x21].y = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x40], 0x21);
    play_sound_effect(0x4D);
    gBattleWork.step++;
}

void conceal_dome_open_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x40], 0x21);
    if (gSpriteEntries[0x21].work[SPR_CMD_STATE] == SPR_CMD_ENDED) {
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void conceal_dome_close_init(void) {
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x41], 0x21);
    play_sound_effect(0x4D);
    gGameWork.stepCounter = 0;
    gBattleWork.step++;
}

void conceal_dome_close(void) {
    gGameWork.stepCounter++;
    battle_bot_sprites_blink(gBattleWork.actor, gGameWork.stepCounter, 2);
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x41], 0x21);
    if (gSpriteEntries[0x21].work[SPR_CMD_STATE] == SPR_CMD_ENDED) {
        clear_battle_sprite_slot(0x21, 1);
        gGameWork.stepTimer = 0x3C;
        gBattleWork.step++;
    }
}

void conceal_blink_wait(void) {
    gGameWork.stepCounter++;
    battle_bot_sprites_blink(gBattleWork.actor, gGameWork.stepCounter, 2);
    if (gGameWork.skipBotSetup == 0 && (KEYS_LO(gRepeatKeys) & A_BUTTON)) {
        battle_bot_sprites_show(gBattleWork.actor);
        gBattleWork.step++;
    } else if (gGameWork.stepTimer)
        gGameWork.stepTimer--;
    else {
        battle_bot_sprites_show(gBattleWork.actor);
        gBattleWork.step++;
    }
}

// Raises the user's evasionBonus by amount (up to 0x78): Conceal raises evasion.
void conceal_apply_evasion(void) {
    add_u8_capped(&gBattleBots[gBattleWork.actor].index + 1, gBattleWork.amount, 0x78);
    gBattleWork.step++;
}

void conceal_finish(void) {
    gBattleWork.messageId = 0x1D;
    gBattleWork.step++;
}

void boost_charge_run(void) {
    gBattleWork.stepDone = 0;
    gBoostChargeSteps[gBattleWork.step]();
}

void boost_charge_begin(void) {
    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else if (battle_bot_lacks_stability(gBattleWork.target) == 0) {
        gBattleWork.messageId = 0x39;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
        gBattleWork.step = 4;
    }
}

void boost_charge_hourglass_spawn(void) {
    lz_decompress_dispatch(gChargeHourglassTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gChargeHourglassPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags |= SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_X] = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.target)].x;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_Y] = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.target)].y - 4;
    gSpriteEntries[0x21].work[SPR_MOTION_TABLE] = 6;
    gGameWork.stepCounter = 0x42;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x42], 0x21);
    gGameWork.stepTimer = 0x3C;
    gBattleWork.step++;
}

void charge_hourglass_hold(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[gGameWork.stepCounter], 0x21);
    if (gGameWork.skipBotSetup == 0 && (KEYS_LO(gRepeatKeys) & A_BUTTON))
        gBattleWork.step++;
    else if (gGameWork.stepTimer)
        gGameWork.stepTimer--;
    else
        gBattleWork.step++;
}

void charge_hourglass_fly(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[gGameWork.stepCounter], 0x21);
    if (!(gBattleWork.actorSideFlags & 1))
        gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle - 0x40) & 0x3FF;
    else
        gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle + 0x40) & 0x3FF;
    if (move_sprite_toward_target(0x21)) {
        gSpriteEntries[0x21].angle = 0;
        gBattleWork.step++;
    }
}

void boost_charge_hourglass_burst(void) {
    gGameWork.stepCounter = 0x43;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x43], 0x21);
    play_sound_effect(0x4E);
    gBattleWork.step++;
}

void charge_hourglass_anim_wait(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[gGameWork.stepCounter], 0x21);
    if (gSpriteEntries[0x21].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
        gBattleWork.step++;
}

void charge_hourglass_shrink(void) {
    if (gSpriteEntries[0x21].scale_x == 8) {
        clear_battle_sprite_slot(0x21, 1);
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x -= 8;
        gSpriteEntries[0x21].scale_y += 8;
    }
}

// Puts the Time status (effect A 0x26) on the target: faster CRG/RAD.
void boost_charge_apply(void) {
    gBattleBots[gBattleWork.target].buffType = 0x26;
    gBattleBots[gBattleWork.target].buffPart = 0;
    gBattleBots[gBattleWork.target].buffTimer = clamp_1_99(gBattleWork.success);
    gBattleBots[gBattleWork.target].buffAmount = clamp_1_99(gBattleWork.amount);
    gBattleWork.step++;
}

void boost_charge_finish(void) {
    gBattleWork.messageId = 0x2C;
    gBattleWork.step++;
}

void rapid_charge_run(void) {
    gBattleWork.stepDone = 0;
    gRapidChargeSteps[gBattleWork.step]();
}

void rapid_charge_begin(void) {
    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
        gBattleWork.step = 4;
    }
}

void rapid_charge_hourglass_spawn(void) {
    lz_decompress_dispatch(gRapidChargeHourglassTilesLz, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gRapidChargeHourglassPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags |= SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_X] = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.target)].x;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_Y] = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.target)].y - 4;
    gSpriteEntries[0x21].work[SPR_MOTION_TABLE] = 6;
    gGameWork.stepCounter = 0x45;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[gGameWork.stepCounter], 0x21);
    gGameWork.stepTimer = 0x3C;
    gBattleWork.step++;
}

void rapid_charge_hourglass_burst(void) {
    gGameWork.stepCounter = 0x46;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x46], 0x21);
    play_sound_effect(0x4E);
    gBattleWork.step++;
}

// guess: rapidCharge makes the target run straight to the center / its side (action_queue.c).
void rapid_charge_apply(void) {
    gBattleBots[gBattleWork.target].rapidCharge = 1;
    gBattleWork.step++;
}

void rapid_charge_finish(void) {
    gBattleWork.messageId = 0x2B;
    gBattleWork.step++;
}

void drain_charge_run(void) {
    gBattleWork.stepDone = 0;
    gDrainChargeSteps[gBattleWork.step]();
}

void drain_charge_begin(void) {
    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else if (battle_bot_lacks_stability(gBattleWork.target) == 0) {
        gBattleWork.messageId = 0x39;
        gBattleWork.step++;
    } else if (battle_bot_lacks_stability(gBattleWork.actor) == 0) {
        gBattleWork.messageId = 0x39;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
        gBattleWork.step = 4;
    }
}

void drain_charge_hourglass_spawn(void) {
    lz_decompress_dispatch(gDrainChargeHourglassTilesLz, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gDrainChargeHourglassPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags |= SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_X] = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.target)].x;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_Y] = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.target)].y - 4;
    gSpriteEntries[0x21].work[SPR_MOTION_TABLE] = 6;
    gGameWork.stepCounter = 0x42;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[gGameWork.stepCounter], 0x21);
    gGameWork.stepTimer = 0x3C;
    gBattleWork.step++;
}

void drain_charge_hourglass_drain(void) {
    gGameWork.stepCounter = 0x44;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x44], 0x21);
    play_sound_effect(0x4E);
    gBattleWork.step++;
}

void drain_charge_hourglass_shrink(void) {
    if (gSpriteEntries[0x21].scale_x == 8) {
        disable_sprites(0x21, 1);
        gBattleWork.step++;
    } else {
        gSpriteEntries[0x21].scale_x -= 8;
        gSpriteEntries[0x21].scale_y -= 8;
    }
}

void drain_charge_hourglass_return(void) {
    lz_decompress_dispatch(gChargeHourglassTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gChargeHourglassPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags |= SPRITE_FLAG_ENABLED;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_X] = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].x;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_Y] = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.actor)].y - 4;
    gSpriteEntries[0x21].work[SPR_MOTION_TABLE] = 6;
    gGameWork.stepCounter = 0x42;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[gGameWork.stepCounter], 0x21);
    gGameWork.stepTimer = 0x3C;
    gBattleWork.step++;
}

void drain_charge_hourglass_grow(void) {
    if (gSpriteEntries[0x21].scale_x == 0x40)
        gBattleWork.step++;
    else {
        gSpriteEntries[0x21].scale_x += 8;
        gSpriteEntries[0x21].scale_y += 8;
    }
}

void drain_charge_hourglass_burst(void) {
    gGameWork.stepCounter = 0x43;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x43], 0x21);
    play_sound_effect(0x4E);
    gBattleWork.step++;
}

// Effect B 0x29 on the target (Bind: slower CRG/RAD) and effect A 0x29 on the user (Time).
void drain_charge_apply(void) {
    gBattleBots[gBattleWork.target].statusType = 0x29;
    gBattleBots[gBattleWork.target].statusPart = 0;
    gBattleBots[gBattleWork.target].statusTimer = clamp_1_99(gBattleWork.success);
    gBattleBots[gBattleWork.target].statusAmount = clamp_1_99(gBattleWork.amount);
    gBattleBots[gBattleWork.actor].buffType = 0x29;
    gBattleBots[gBattleWork.actor].buffPart = 0;
    gBattleBots[gBattleWork.actor].buffTimer = clamp_1_99(gBattleWork.success);
    gBattleBots[gBattleWork.actor].buffAmount = clamp_1_99(gBattleWork.amount);
    gBattleWork.step++;
}

void drain_charge_finish(void) {
    gBattleWork.messageId = 0x2D;
    gBattleWork.step++;
}

// guess: Pushover (ability 42, the Majoram head): a thrown object spins onto the target, the target hops
// and falls over, its head takes amount damage (1 if stateFlags bit 2 is set) and the script goes on with
// opcode 0x21. The guide describes Pushover as "throws a banana, very little damage, erases orders".
void pushover_run(void) {
    gBattleWork.stepDone = 0;
    gPushoverSteps[gBattleWork.step]();
}

void pushover_begin(void) {
    calc_battle_action_speed(gBattleWork.actor, gBattleWork.actorPart);
    apply_battle_bot_damage_reduction(gBattleWork.actor);
    if (decrement_battle_timer_and_check_zero()) {
        gBattleWork.messageId = 0x1A;
        gBattleWork.step++;
    } else {
        side_add_action_point();
        calc_battle_stat_ratio(gBattleWork.actor, gBattleWork.actorPart);
        gBattleWork.step = 4;
    }
}

void pushover_banana_spawn(void) {
    lz_decompress_dispatch(gPushoverBananaTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gPushoverBananaPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags |= SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE;
    gSpriteEntries[0x21].scale_x = 0x40;
    gSpriteEntries[0x21].scale_y = 0x40;
    gSpriteEntries[0x21].angle = 0;
    gSpriteEntries[0x21].frame = 0x4D00;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_X] = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.target)].x;
    gSpriteEntries[0x21].work16[FX_SPR_TARGET_Y] = gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.target)].y - 4;
    gSpriteEntries[0x21].work[SPR_MOTION_TABLE] = 6;
    if (gBattleWork.actorSideFlags & 1)
        gSpriteEntries[0x21].flags |= SPRITE_FLAG_HFLIP;
    gGameWork.stepTimer = 0x3C;
    gBattleWork.step++;
}

void pushover_banana_fly(void) {
    if (move_sprite_toward_target(0x21))
        gBattleWork.step++;
}

void pushover_target_hop_init(void) {
    gSpriteEntries[0x21].work[FX_SPR_STEP] = 0;
    copy_bytes(&gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.target)], &gSpriteEntries[0x22], 0x40);
    copy_bytes(&gSpriteEntries[BOT_SPRITE_RIGHT_ARM(gBattleWork.target)], &gSpriteEntries[0x23], 0x40);
    copy_bytes(&gSpriteEntries[BOT_SPRITE_LEFT_ARM(gBattleWork.target)], &gSpriteEntries[0x24], 0x40);
    copy_bytes(&gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.target)], &gSpriteEntries[0x25], 0x40);
    disable_sprites(0x22, 4);
    gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.target)].work[FX_SPR_STEP] = 0;
    gSpriteEntries[BOT_SPRITE_RIGHT_ARM(gBattleWork.target)].work[FX_SPR_STEP] = 0;
    gSpriteEntries[BOT_SPRITE_LEFT_ARM(gBattleWork.target)].work[FX_SPR_STEP] = 0;
    gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.target)].work[FX_SPR_STEP] = 0;
    sprite_enable_affine_unit_scale(gBattleWork.target + 0x72);
    play_sound_effect(0x34);
    gBattleWork.step++;
}

void pushover_target_hop(void) {
    u32 landed;

    if (gSpriteEntries[0x21].flags & SPRITE_FLAG_ENABLED) {
        if (advance_sprite_anim_frame(0x21, 0))
            clear_battle_sprite_slot(0x21, 1);
        else if (!(gBattleWork.actorSideFlags & 1)) {
            gSpriteEntries[0x21].x--;
            gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle - 0x10) & 0x3FF;
        } else {
            gSpriteEntries[0x21].x++;
            gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle + 0x10) & 0x3FF;
        }
    }
    sprite_hop_step(BOT_SPRITE_HEAD(gBattleWork.target));
    sprite_hop_step(BOT_SPRITE_RIGHT_ARM(gBattleWork.target));
    sprite_hop_step(BOT_SPRITE_LEFT_ARM(gBattleWork.target));
    landed = sprite_hop_step(BOT_SPRITE_LEGS(gBattleWork.target));
    if (gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.target)].work[FX_SPR_STEP] == 0x10) {
        gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.target)].y += 8;
        gSpriteEntries[BOT_SPRITE_RIGHT_ARM(gBattleWork.target)].y -= 8;
        gSpriteEntries[BOT_SPRITE_LEFT_ARM(gBattleWork.target)].y -= 8;
        gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.target)].y -= 8;
        gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.target)].flags |= SPRITE_FLAG_VFLIP;
        gSpriteEntries[BOT_SPRITE_RIGHT_ARM(gBattleWork.target)].flags |= SPRITE_FLAG_VFLIP;
        gSpriteEntries[BOT_SPRITE_LEFT_ARM(gBattleWork.target)].flags |= SPRITE_FLAG_VFLIP;
        gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.target)].flags |= SPRITE_FLAG_VFLIP;
    }
    check_sprite_overlap_and_adjust(BOT_SPRITE_LEGS(gBattleWork.target), gBattleWork.target + 0x72);
    if (landed) {
        sprite_disable_affine(gBattleWork.target + 0x72);
        play_sound_effect(0x41);
        gBattleWork.step++;
    }
}

void pushover_burst_spawn(void) {
    u32 i;

    for (i = 0; i < 4; i++) {
        gSpriteEntries[0x26 + i].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0x26 + i].frame_table = 0;
        gSpriteEntries[0x26 + i].x = gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.target)].x;
        gSpriteEntries[0x26 + i].y = gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.target)].y + 4;
        gSpriteEntries[0x26 + i].palette = 7;
        gSpriteEntries[0x26 + i].order = 0xF0;
        gSpriteEntries[0x26 + i].work[SPR_MOTION_TABLE] = 6;
        gSpriteEntries[0x26 + i].work[SPR_MOTION_ROW] = gBurstSpriteDirections[i];
        gSpriteEntries[0x26 + i].frame = 0x4D01;
    }
    gGameWork.stepCounter = 0;
    gBattleWork.step++;
}

void pushover_burst(void) {
    u32 i;

    for (i = 0; i < 4; i++)
        update_sprite_animation_position(0x26 + i);
    if (gGameWork.stepCounter == 0x10) {
        clear_battle_sprite_slot(0x26, 4);
        copy_bytes(&gSpriteEntries[0x22], &gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.target)], 0x40);
        copy_bytes(&gSpriteEntries[0x23], &gSpriteEntries[BOT_SPRITE_RIGHT_ARM(gBattleWork.target)], 0x40);
        copy_bytes(&gSpriteEntries[0x24], &gSpriteEntries[BOT_SPRITE_LEFT_ARM(gBattleWork.target)], 0x40);
        copy_bytes(&gSpriteEntries[0x25], &gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.target)], 0x40);
        gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.target)].flags |= SPRITE_FLAG_ENABLED;
        gSpriteEntries[BOT_SPRITE_RIGHT_ARM(gBattleWork.target)].flags |= SPRITE_FLAG_ENABLED;
        gSpriteEntries[BOT_SPRITE_LEFT_ARM(gBattleWork.target)].flags |= SPRITE_FLAG_ENABLED;
        gSpriteEntries[BOT_SPRITE_LEGS(gBattleWork.target)].flags |= SPRITE_FLAG_ENABLED;
        clear_battle_sprite_slot(0x21, 4);
        gBattleWork.step++;
    } else
        gGameWork.stepCounter++;
}

void pushover_damage_init(void) {
    if (gBattleBots[gBattleWork.target].stateFlags & 4)
        battle_set_damage_vs_armor(gBattleWork.target, 0, 1);
    else
        battle_set_damage_vs_armor(gBattleWork.target, 0, gBattleWork.amount);
    set_display_digit_type(&gGameWork.partAbility, gBattleWork.appliedAmount, 1);
    battle_number_popup_init_slot(&gGameWork.partAbility, gBattleWork.target, 0x21);
    play_sound_effect(0x5B);
    gGameWork.stepCounter = 0;
    gBattleWork.step++;
}

void pushover_damage_popup(void) {
    battle_popup_update_slot(&gGameWork.partAbility, gBattleWork.target, 0x21);
    if (++gGameWork.stepCounter,
        gGameWork.skipBotSetup == 0 && (KEYS_LO(gRepeatKeys) & A_BUTTON) && gGameWork.stepCounter > 0x32)
        gGameWork.stepCounter = 0x78;
    if (gGameWork.stepCounter == 0x78) {
        clear_battle_sprite_slot(gBattleWork.target * 4 + 0x21, 4);
        gBattleWork.step++;
    }
}

void pushover_apply_head_damage(void) {
    u8 armor;

    reduce_bot_part_stat(gBattleWork.target, 0, gBattleWork.appliedAmount);
    armor = gBattleBots[gBattleWork.target].parts[0].armor;
    if (armor == 0) {
        add_bot_to_defeated_list(gBattleWork.target);
        gBattleWork.damagePart = armor;
        gBattleWork.step = 0x1A;
    } else
        gBattleWork.step = 0x13;
}

// guess: stateFlags bit 2 set -> step 0x14, which leads to pushover_flag_target (stateFlags bit 0).
void pushover_check_target_flag(void) {
    if (gBattleBots[gBattleWork.target].stateFlags & 4)
        gBattleWork.step++;
    else
        gBattleWork.step = 0x15;
}

void pushover_flag_target(void) {
    gBattleBots[gBattleWork.target].stateFlags |= 1;
    gBattleWork.step++;
}

void pushover_finish(void) {
    gBattleWork.messageId = 0x2E;
    gBattleWork.step++;
}

void pushover_part_destroyed_cursor(void) {
    lz_decompress_dispatch(gBreakRingTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gBreakRingPalette, (void *)0x050002E0, 8);
    staggered_sprites_spawn(0x21, gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.target) + gBattleWork.damagePart].x,
                            gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.target) + gBattleWork.damagePart].y, 4);
    gBattleWork.step++;
}

void pushover_part_destroyed_cursor_wait(void) {
    if (staggered_sprites_update(0x21, 4))
        gBattleWork.step++;
}

void pushover_part_explode_spawn(void) {
    lz_decompress_dispatch(gHitSparksTiles, (void *)(OBJ_VRAM0 + 0x4800));
    CpuFastSet(gHitSparksPalette, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0x21].frame_table = 0;
    gSpriteEntries[0x21].x = gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.target) + gBattleWork.damagePart].x;
    gSpriteEntries[0x21].y = gSpriteEntries[BOT_SPRITE_HEAD(gBattleWork.target) + gBattleWork.damagePart].y;
    gSpriteEntries[0x21].palette = 7;
    gSpriteEntries[0x21].order = 0xF0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x22], 0x21);
    gBattleWork.step++;
}

void pushover_part_explode(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x22], 0x21);
    if (gSpriteEntries[0x21].work[SPR_CMD_STATE] == SPR_CMD_ENDED) {
        clear_battle_sprite_slot(0x21, 1);
        load_bot_part_sprite(gBattleWork.target);
        gBattleWork.step++;
    }
}
