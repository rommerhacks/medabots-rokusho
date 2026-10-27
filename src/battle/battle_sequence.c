// Battle sequences: the close-up skill animation scripts. script_op_skill_anim_start picks the script
// gBattleSeqScripts[gBattleWork.unkF9] (the skill: acting part's data[1], or Medaforce + 0x50) and
// script_op_skill_anim_run calls battle_sequence_update each frame. Each script entry is an opcode for
// gBattleSeqCommands (battle_seq_cmd_*, in opcode order 0x01-0x3A) followed by gBattleSeqOperandCounts[opcode]
// operands, copied to gBattleWork.unk102 by battle_seq_load_operands; negative entries are labels for
// battle_seq_cmd_goto / battle_seq_cmd_branch. Commands mostly set up sprite slots, whose per-frame handler
// gBattleSeqSpriteHandlers[unk29] (battle_seq_spr_*) is run by battle_sequence_update_sprites.
// Slots: 1 / 2 left / right Medabot pose, 3 the actor's movement, 4 and 0x23 BG0 tile effects, 9 armor panel,
// 0xA-0x12 effect sprites, 0x1E camera. gBattleWork.unkF8 bit 1 = actor on the right: x positions and
// directions are mirrored. Runtime (re/states/battle_start.ss0, skill 22): actor_pose, bg_effect, sound,
// load_effect_gfx, spawn_effect x2, sprite_motion, trail, camera_track, test_missed, branch, target_pose, goto,
// clear_sprites, actor_home, end.

#include "global.h"

static void battle_sprite_rotate_angles(u32 dir, u32 delta);

void battle_sequence_update(void) {
    while (gSpriteEntries[0].unk2A == 0)
        battle_sequence_run_command();
    battle_sequence_update_sprites();
    gSpriteEntries[0].unk2A = 0;
}

void battle_sequence_run_command(void) {
    s8 *p;
    if ((s8)(gSpriteEntries[0].unk29 = battle_seq_peek()) < 0) {
        p = (s8 *)&gSpriteEntries[0].unk29;
        do {
            battle_seq_advance();
            *p = battle_seq_peek();
        } while (*p < 0);
    }
    gBattleSeqCommands[gSpriteEntries[0].unk29]();
}

// Opcode 0x01: ends the sequence (yields and sets the step-done flag unkB5).
void battle_seq_cmd_end(void) {
    gSpriteEntries[0].unk2A = 1;
    gBattleWork.unkB5 = 1;
}

// Opcode 0x02: jumps past the label (negative entry) equal to operand 0.
void battle_seq_cmd_goto(void) {
    const s16 *seq;
    vu8 done = 0;

    battle_seq_load_operands();
    battle_seq_advance();
    while (!done) {
        seq = gBattleSeqScripts[gBattleWork.unkF9];
        if (gBattleWork.unk102[0] == seq[gBattleWork.unk100]) {
            battle_seq_advance();
            done = 1;
        } else {
            battle_seq_advance();
        }
    }
}

// Opcode 0x03: jumps to label operand[unkFD], the condition set by the test_* commands.
void battle_seq_cmd_branch(void) {
    const s16 *seq;
    vu8 done = 0;

    battle_seq_load_operands();
    battle_seq_advance();
    while (!done) {
        seq = gBattleSeqScripts[gBattleWork.unkF9];
        if (gBattleWork.unk102[gBattleWork.unkFD] == seq[gBattleWork.unk100]) {
            battle_seq_advance();
            done = 1;
        } else {
            battle_seq_advance();
        }
    }
}

// Opcode 0x04: condition = the attack missed (unkB7 == 1).
void battle_seq_cmd_test_missed(void) {
    if (gBattleWork.unkB7 == 1)
        gBattleWork.unkFD = 1;
    else
        gBattleWork.unkFD = 0;
    battle_seq_advance();
}

// Opcode 0x05: condition = the target has a reaction ready (unkF6 bit 0).
void battle_seq_cmd_test_reaction(void) {
    if (gBattleWork.unkF6 & 1)
        gBattleWork.unkFD = 1;
    else
        gBattleWork.unkFD = gBattleWork.unkF6 & 1;
    battle_seq_advance();
}

// Opcode 0x06: condition = the attack was nullified (unkB8 == 2).
void battle_seq_cmd_test_nullified(void) {
    if (gBattleWork.unkB8 == 2)
        gBattleWork.unkFD = 1;
    else
        gBattleWork.unkFD = 0;
    battle_seq_advance();
}

// Opcode 0x07: condition = the attack was absorbed (unkB8 == 4).
void battle_seq_cmd_test_absorbed(void) {
    if (gBattleWork.unkB8 == 4)
        gBattleWork.unkFD = 1;
    else
        gBattleWork.unkFD = 0;
    battle_seq_advance();
}

// Opcode 0x08: the actor plays a pose (operands: delay, pose per part for left, for right).
void battle_seq_cmd_actor_pose(void) {
    battle_seq_load_operands();
    if (!(gBattleWork.unkF8 & 2)) {
        gSpriteEntries[1].unk2B = 1;
        if (gBattleWork.unkF6 & 2)
            gSpriteEntries[1].unk2C = gBattleWork.unk102[gBattleWork.unk162 + 1];
        else
            gSpriteEntries[1].unk2C = gBattleWork.unk102[gBattleWork.unkA7 + 1];
        gSpriteEntries[1].unk30 = gBattleWork.unk102[0];
        gSpriteEntries[1].unk2D = 0;
    } else {
        gSpriteEntries[2].unk2B = 1;
        if (gBattleWork.unkF6 & 2)
            gSpriteEntries[2].unk2C = gBattleWork.unk102[gBattleWork.unk162 + 4];
        else
            gSpriteEntries[2].unk2C = gBattleWork.unk102[gBattleWork.unkA7 + 4];
        gSpriteEntries[2].unk30 = gBattleWork.unk102[0];
        gSpriteEntries[2].unk2D = 0;
    }
    battle_seq_advance();
}

// Opcode 0x09: yields until the next frame without advancing.
void battle_seq_cmd_yield(void) {
    gSpriteEntries[0].unk2A = 1;
}

// Opcode 0x0A: the target plays a pose (same operands as actor_pose).
void battle_seq_cmd_target_pose(void) {
    battle_seq_load_operands();
    if (!(gBattleWork.unkF8 & 2)) {
        gSpriteEntries[2].unk2B = 1;
        if (gBattleWork.unkF6 & 2)
            gSpriteEntries[2].unk2C = gBattleWork.unk102[gBattleWork.unk162 + 4];
        else
            gSpriteEntries[2].unk2C = gBattleWork.unk102[gBattleWork.unkA7 + 4];
        gSpriteEntries[2].unk30 = gBattleWork.unk102[0];
        gSpriteEntries[2].unk2D = 0;
    } else {
        gSpriteEntries[1].unk2B = 1;
        if (gBattleWork.unkF6 & 2)
            gSpriteEntries[1].unk2C = gBattleWork.unk102[gBattleWork.unk162 + 1];
        else
            gSpriteEntries[1].unk2C = gBattleWork.unk102[gBattleWork.unkA7 + 1];
        gSpriteEntries[1].unk30 = gBattleWork.unk102[0];
        gSpriteEntries[1].unk2D = 0;
    }
    battle_seq_advance();
}

// Opcode 0x0B: the actor runs across the field at speed operand 0, the camera following.
void battle_seq_cmd_actor_dash(void) {
    u8 f;

    battle_seq_load_operands();
    gSpriteEntries[3].unk2B = gBattleWork.unk102[0];
    f = gBattleWork.unkF8 & 2;
    if (!f) {
        gSpriteEntries[3].unk2C = f;
        gSpriteEntries[3].unk30 = gBattleWork.unk154;
    } else {
        gSpriteEntries[3].unk2C = 1;
        gSpriteEntries[3].unk30 = gBattleWork.unk158;
    }
    gSpriteEntries[3].unk29 = 8;
    battle_seq_advance();
}

// Opcode 0x0C: waits for the actor (0), the target (1) or both to finish their pose.
void battle_seq_cmd_wait_pose(void) {
    battle_seq_load_operands();
    switch (gBattleWork.unk102[0]) {
    case 0:
        if (!(gBattleWork.unkF8 & 2)) {
            if (gBattleWork.unk15F)
                battle_seq_advance();
        } else {
            if (gBattleWork.unk160)
                battle_seq_advance();
        }
        break;
    case 1:
        if (gBattleWork.unkF8 & 2) {
            if (gBattleWork.unk15F)
                battle_seq_advance();
        } else {
            if (gBattleWork.unk160)
                battle_seq_advance();
        }
        break;
    default:
        if (gBattleWork.unk15F && gBattleWork.unk160)
            battle_seq_advance();
        break;
    }
    gSpriteEntries[0].unk2A = 1;
}

// Opcode 0x0D: a BG0 tile animation in the skill's palette (removed when it ends).
void battle_seq_cmd_bg_effect(void) {
    u32 skill;
    u32 t;

    battle_seq_load_operands();
    if (gBattleBots[gBattleWork.unk87].chosenAction <= 3)
        skill = gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1];
    else
        skill = gBattleBots[gBattleWork.unk87].medaforce[0] + 0x50;
    load_battle_entity_palette(skill, gBattleWork.unk102[4], 9);
    gSpriteEntries[4].unk2E = gBattleWork.unk102[0];
    gSpriteEntries[4].unk2F = gBattleWork.unk102[1];
    gSpriteEntries[4].unk2B = gBattleWork.unk102[6];
    gSpriteEntries[4].unk30 = gBattleWork.unk102[5];
    gSpriteEntries[4].unk29 = 0x10;
    tile_anim_init(gBattleSeqTileAnims[gSpriteEntries[4].unk2B], 0, 0);
    gSpriteEntries[4].unk4 = gBattleWork.unk102[3];
    if (!(gBattleWork.unkF8 & 2)) {
        gSpriteEntries[4].unk2 = gBattleWork.unk102[2];
        gSpriteEntries[4].unk2C = gBattleWork.unk102[7];
    } else {
        t = gSpriteEntries[4].unk2E >> 1;
        gSpriteEntries[4].unk2 = 0x1E - t - (gBattleWork.unk102[2] + t);
        gSpriteEntries[4].unk2C = gBattleWork.unk102[7] + 2;
    }
    gSpriteEntries[4].unk2D = 0;
    battle_seq_advance();
}

// Opcode 0x0E: waits operand 0 frames.
void battle_seq_cmd_wait_frames(void) {
    battle_seq_load_operands();
    if (gSpriteEntries[0].unk30 != gBattleWork.unk102[0]) {
        gSpriteEntries[0].unk30++;
    } else {
        gSpriteEntries[0].unk30 = 0;
        battle_seq_advance();
    }
    gSpriteEntries[0].unk2A = 1;
}

// Opcode 0x0F: plays a sound effect a number of times (slot 5 + operand 0).
void battle_seq_cmd_sound(void) {
    battle_seq_load_operands();
    gSpriteEntries[gBattleWork.unk102[0] + 5].unk30 = gBattleWork.unk102[1];
    gSpriteEntries[gBattleWork.unk102[0] + 5].unk2B = gBattleWork.unk102[2];
    gSpriteEntries[gBattleWork.unk102[0] + 5].unk2C = 0;
    gSpriteEntries[gBattleWork.unk102[0] + 5].unk2D = gBattleWork.unk102[3];
    gSpriteEntries[gBattleWork.unk102[0] + 5].unk2E = gBattleWork.unk102[4];
    gSpriteEntries[gBattleWork.unk102[0] + 5].unk29 = 0x18;
    battle_seq_advance();
}

// Opcode 0x10: like sound, the effect picked by the actor's legs type. guess: footsteps.
void battle_seq_cmd_leg_sound(void) {
    u32 i;
    const u8 *set;

    battle_seq_load_operands();
    gSpriteEntries[gBattleWork.unk102[0] + 5].unk30 = gBattleWork.unk102[1];
    gSpriteEntries[gBattleWork.unk102[0] + 5].unk2C = 0;
    gSpriteEntries[gBattleWork.unk102[0] + 5].unk2D = gBattleWork.unk102[3];
    gSpriteEntries[gBattleWork.unk102[0] + 5].unk2E = gBattleWork.unk102[4];
    gSpriteEntries[gBattleWork.unk102[0] + 5].unk29 = 0x18;
    if (gBattleWork.unkF6 & 2)
        get_bot_part_effective_values(gBattleWork.unk161, gBattleWork.unk64);
    else
        get_bot_part_effective_values(gBattleWork.unk87, gBattleWork.unk64);
    if (gBattleWork.unk64[3] > 0x77)
        i = 3;
    else if (gBattleWork.unkF6 & 2)
        i = gBattleBots[gBattleWork.unk161].parts[3].data[1] - 0x64;
    else
        i = gBattleBots[gBattleWork.unk87].parts[3].data[1] - 0x64;
    set = gBattleSeqLegSoundSets[gBattleWork.unk102[2]];
    gSpriteEntries[gBattleWork.unk102[0] + 5].unk2B = set[i];
    battle_seq_advance();
}

// Opcode 0x11: moves the actor for some frames (speed, direction, frames).
void battle_seq_cmd_actor_move(void) {
    u8 f;

    battle_seq_load_operands();
    gSpriteEntries[3].unk24 = gBattleWork.unk102[0];
    gSpriteEntries[3].unk2D = gBattleWork.unk102[2];
    f = gBattleWork.unkF8 & 2;
    if (!f) {
        gSpriteEntries[3].unk2C = f;
        gSpriteEntries[3].unk25 = gBattleWork.unk102[1];
        gSpriteEntries[3].unk2 = gBattleWork.unk154;
        gSpriteEntries[3].unk4 = gBattleWork.unk156;
    } else {
        gSpriteEntries[3].unk2C = 1;
        gSpriteEntries[3].unk25 = (0x20 - (u8)gBattleWork.unk102[1]) & 0x1F;
        gSpriteEntries[3].unk2 = gBattleWork.unk158;
        gSpriteEntries[3].unk4 = gBattleWork.unk15A;
    }
    gSpriteEntries[3].unk29 = 9;
    battle_seq_advance();
}

// Opcode 0x12: condition = target unkBC bit 5 (guess: evaded onto its strongest part).
void battle_seq_cmd_test_evaded(void) {
    u8 f = gBattleBots[gBattleWork.unk88].hitFlags & 0x20;
    if (f)
        gBattleWork.unkFD = 1;
    else
        gBattleWork.unkFD = f;
    battle_seq_advance();
}

// Opcode 0x13: bg_effect with the fixed palette 0x3C.
void battle_seq_cmd_bg_effect_fixed(void) {
    u32 t;

    battle_seq_load_operands();
    load_battle_entity_palette(0x3C, gBattleWork.unk102[4], 9);
    gSpriteEntries[4].unk2E = gBattleWork.unk102[0];
    gSpriteEntries[4].unk2F = gBattleWork.unk102[1];
    gSpriteEntries[4].unk2B = gBattleWork.unk102[6];
    gSpriteEntries[4].unk30 = gBattleWork.unk102[5];
    gSpriteEntries[4].unk29 = 0x10;
    tile_anim_init(gBattleSeqTileAnims[gSpriteEntries[4].unk2B], 0, 0);
    gSpriteEntries[4].unk4 = gBattleWork.unk102[3];
    if (!(gBattleWork.unkF8 & 2)) {
        gSpriteEntries[4].unk2 = gBattleWork.unk102[2];
        gSpriteEntries[4].unk2C = gBattleWork.unk102[7];
    } else {
        t = gSpriteEntries[4].unk2E >> 1;
        gSpriteEntries[4].unk2 = 0x1E - t - (gBattleWork.unk102[2] + t);
        gSpriteEntries[4].unk2C = gBattleWork.unk102[7] + 2;
    }
    gSpriteEntries[4].unk2D = 0;
    battle_seq_advance();
}

// Opcode 0x14: puts the actor back at its home position, standing (pose 0x29).
void battle_seq_cmd_actor_home(void) {
    if (!(gBattleWork.unkF8 & 2)) {
        gBattleWork.unk154 = 0x12C;
        gBattleWork.unk156 = 0x50;
        get_active_bot_part_index_and_load_values(0);
        draw_medabot_sprite(0, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3],
                            (s16)gBattleWork.unk154, (s16)gBattleWork.unk156, gBattleWork.unk39[3] + 2, 4, 0, 2, 0,
                            gBattleWork.unk114[0]);
        draw_medabot_sprite(0, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3],
                            (s16)gBattleWork.unk154, (s16)gBattleWork.unk156, gBattleWork.unk39[3] + 2, 4, 0, 1, 0,
                            gBattleWork.unk114[0]);
        gBattleWork.unk112 = 0x29;
        medabot_pose_anim_step(0, 0x29, gBattleWork.unk64[3]);
    } else {
        gBattleWork.unk158 = 0x1C4;
        gBattleWork.unk15A = 0x50;
        get_active_bot_part_index_and_load_values(1);
        draw_medabot_sprite(1, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3],
                            (s16)gBattleWork.unk158, (s16)gBattleWork.unk15A, gBattleWork.unk39[3] + 2, 8, 1, 2, 1,
                            gBattleWork.unk114[1]);
        draw_medabot_sprite(1, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3],
                            (s16)gBattleWork.unk158, (s16)gBattleWork.unk15A, gBattleWork.unk39[3] + 2, 8, 1, 1, 1,
                            gBattleWork.unk114[1]);
        gBattleWork.unk113 = 0x29;
        medabot_pose_anim_step(1, 0x29, gBattleWork.unk64[3]);
    }
    battle_seq_advance();
}

// Opcode 0x15: a moving camera point (slot 0x1E): BG2/BG3 and both Medabots scroll to follow it.
void battle_seq_cmd_camera_track(void) {
    battle_seq_load_operands();
    clear_battle_sprite_slot(0x1E, 1);
    gSpriteEntries[0x1E].unk2B = gBattleWork.unk102[0];
    gSpriteEntries[0x1E].unk4 = gBattleWork.unk102[2];
    gSpriteEntries[0x1E].unk24 = gBattleWork.unk102[4];
    gSpriteEntries[0x1E].unk29 = 10;
    if (!(gBattleWork.unkF8 & 2)) {
        gSpriteEntries[0x1E].unk2 = gBattleWork.unk102[1];
        gSpriteEntries[0x1E].unk25 = gBattleWork.unk102[3];
    } else {
        gSpriteEntries[0x1E].unk2 = 0xF0 - gBattleWork.unk102[1];
        gSpriteEntries[0x1E].unk25 = (0x20 - (u8)gBattleWork.unk102[3]) & 0x1F;
    }
    gSpriteEntries[0x1E].unk30 = gSpriteEntries[0x1E].unk2;
    battle_seq_advance();
}

// Opcode 0x16: waits until the camera point has stopped.
void battle_seq_cmd_wait_camera(void) {
    if (!gSpriteEntries[0x1E].unk29)
        battle_seq_advance();
    gSpriteEntries[0].unk2A = 1;
}

// Opcode 0x17: loads effect tiles gBattleSeqEffectGfx[operand 0] to OBJ VRAM and OBJ palette 14.
void battle_seq_cmd_load_effect_gfx(void) {
    battle_seq_load_operands();
    lz_decompress_dispatch(gBattleSeqEffectGfx[gBattleWork.unk102[0] * 2], (void *)0x06010000);
    CpuFastSet(gBattleSeqEffectGfx[gBattleWork.unk102[0] * 2 + 1], (void *)0x050003C0, 8);
    battle_seq_advance();
}

// Opcode 0x18: spawns a moving effect sprite in the first free slot 0xA-0x12.
void battle_seq_cmd_spawn_effect(void) {
    u32 i;
    u32 slot;

    battle_seq_load_operands();
    for (i = 0; i <= 8; i++) {
        if (gSpriteEntries[i + 10].unk0 == 0) {
            slot = i + 10;
            break;
        }
    }
    clear_battle_sprite_slot(slot, 1);
    gSpriteEntries[slot].unk0 = (gBattleWork.unk102[6] << 10) | 0x4004;
    gSpriteEntries[slot].unk1C = 0;
    gSpriteEntries[slot].unkA = 0xE;
    gSpriteEntries[slot].unkB = 0x80;
    gSpriteEntries[slot].unk2D = gBattleWork.unk102[7];
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[slot].unk2D], slot);
    gSpriteEntries[slot].unk2B = gBattleWork.unk102[0];
    gSpriteEntries[slot].unk4 = gBattleWork.unk102[2];
    gSpriteEntries[slot].unk24 = gBattleWork.unk102[4];
    gSpriteEntries[slot].unk2C = gBattleWork.unk102[5];
    gSpriteEntries[slot].unk29 = 0xB;
    if (!(gBattleWork.unkF8 & 2)) {
        gSpriteEntries[slot].unk2 = gBattleWork.unk102[1];
        gSpriteEntries[slot].unk25 = gBattleWork.unk102[3];
    } else {
        gSpriteEntries[slot].unk0 |= 0x1000;
        gSpriteEntries[slot].unk2 = 0xF0 - gBattleWork.unk102[1];
        gSpriteEntries[slot].unk25 = (0x20 - (u8)gBattleWork.unk102[3]) & 0x1F;
    }
    battle_seq_advance();
}

// Opcode 0x19: waits until sprite operand 1 has moved past x = operand 0 (mirrored).
void battle_seq_cmd_wait_sprite_x(void) {
    battle_seq_load_operands();
    if (!(gBattleWork.unkF8 & 2)) {
        if (gSpriteEntries[gBattleWork.unk102[1]].unk2 >= gBattleWork.unk102[0])
            battle_seq_advance();
    } else {
        if (gSpriteEntries[gBattleWork.unk102[1]].unk2 <= 0xF0 - gBattleWork.unk102[0])
            battle_seq_advance();
    }
    gSpriteEntries[0].unk2A = 1;
}

// Opcode 0x1A: clears operand 1 sprite slots from operand 0.
void battle_seq_cmd_clear_sprites(void) {
    battle_seq_load_operands();
    clear_battle_sprite_slot(gBattleWork.unk102[0], gBattleWork.unk102[1]);
    battle_seq_advance();
}

// Opcode 0x1B: after a delay, plays a sprite animation once on a slot.
void battle_seq_cmd_play_anim(void) {
    s32 n;

    battle_seq_load_operands();
    n = gBattleWork.unk102[2];
    gSpriteEntries[n].unkA = gBattleWork.unk102[4];
    gSpriteEntries[n].unk2D = gBattleWork.unk102[1];
    gSpriteEntries[n].unk2B = gBattleWork.unk102[0];
    gSpriteEntries[n].unk29 = 0x20;
    gSpriteEntries[n].unk2E = gBattleWork.unk102[3];
    battle_seq_advance();
}

// Opcode 0x1C: camera_track that also scrolls BG0 and BG1.
void battle_seq_cmd_camera_track_all(void) {
    battle_seq_load_operands();
    clear_battle_sprite_slot(0x1E, 1);
    gSpriteEntries[0x1E].unk2B = gBattleWork.unk102[0];
    gSpriteEntries[0x1E].unk4 = gBattleWork.unk102[2];
    gSpriteEntries[0x1E].unk24 = gBattleWork.unk102[4];
    gSpriteEntries[0x1E].unk29 = 12;
    if (!(gBattleWork.unkF8 & 2)) {
        gSpriteEntries[0x1E].unk2 = gBattleWork.unk102[1];
        gSpriteEntries[0x1E].unk25 = gBattleWork.unk102[3];
    } else {
        gSpriteEntries[0x1E].unk2 = 0xF0 - gBattleWork.unk102[1];
        gSpriteEntries[0x1E].unk25 = (0x20 - (u8)gBattleWork.unk102[3]) & 0x1F;
    }
    gSpriteEntries[0x1E].unk30 = gSpriteEntries[0x1E].unk2;
    battle_seq_advance();
}

// Opcode 0x1D: makes BG0 64x32 tiles and clears it.
void battle_seq_cmd_bg0_wide(void) {
    REG_BG0CNT = 0x4500;
    tilemap_fill_rect(0x40, 0x20, 0, 0, REG_BG0CNT, 0);
    battle_seq_advance();
}

// Opcode 0x1E: a BG0 tile animation drawn one column further every other frame (slot 0x23).
void battle_seq_cmd_bg_sweep(void) {
    u32 skill;
    u32 t;

    battle_seq_load_operands();
    clear_battle_sprite_slot(0x23, 1);
    if (gBattleBots[gBattleWork.unk87].chosenAction <= 3)
        skill = gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1];
    else
        skill = gBattleBots[gBattleWork.unk87].medaforce[0] + 0x50;
    load_battle_entity_palette(skill, gBattleWork.unk102[4], 9);
    gSpriteEntries[0x23].unk2E = gBattleWork.unk102[0];
    gSpriteEntries[0x23].unk2F = gBattleWork.unk102[1];
    gSpriteEntries[0x23].unk2B = gBattleWork.unk102[6];
    gSpriteEntries[0x23].unk30 = gBattleWork.unk102[5];
    gSpriteEntries[0x23].unk29 = 0x11;
    tile_anim_init(gBattleSeqTileAnims[gSpriteEntries[0x23].unk2B], 1, 1);
    gSpriteEntries[0x23].unk4 = gBattleWork.unk102[3];
    if (!(gBattleWork.unkF8 & 2)) {
        gSpriteEntries[0x23].unk2 = gBattleWork.unk102[2];
        gSpriteEntries[0x23].unk2C = gBattleWork.unk102[7];
    } else {
        t = gSpriteEntries[0x23].unk2E >> 1;
        gSpriteEntries[0x23].unk2 = (s16)(0x1E - t - (gBattleWork.unk102[2] + t)) - 1;
        gSpriteEntries[0x23].unk2C = gBattleWork.unk102[7] + 2;
    }
    gSpriteEntries[0x23].unk2D = 0;
    gSpriteEntries[0x23].unk28 = 0;
    battle_seq_advance();
}

// Opcode 0x1F: bg_effect at row 4 with a separate x for each side (cleared when it ends).
void battle_seq_cmd_bg_effect_at(void) {
    u32 skill;

    battle_seq_load_operands();
    if (gBattleBots[gBattleWork.unk87].chosenAction <= 3)
        skill = gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1];
    else
        skill = gBattleBots[gBattleWork.unk87].medaforce[0] + 0x50;
    load_battle_entity_palette(skill, gBattleWork.unk102[4], 9);
    gSpriteEntries[4].unk2E = gBattleWork.unk102[0];
    gSpriteEntries[4].unk2F = gBattleWork.unk102[1];
    gSpriteEntries[4].unk2B = gBattleWork.unk102[6];
    gSpriteEntries[4].unk30 = gBattleWork.unk102[5];
    gSpriteEntries[4].unk29 = 0x12;
    tile_anim_init(gBattleSeqTileAnims[gSpriteEntries[4].unk2B], 0, 0);
    gSpriteEntries[4].unk4 = 4;
    if (!(gBattleWork.unkF8 & 2)) {
        gSpriteEntries[4].unk2 = gBattleWork.unk102[2];
        gSpriteEntries[4].unk2C = gBattleWork.unk102[7];
    } else {
        gSpriteEntries[4].unk2 = gBattleWork.unk102[3];
        gSpriteEntries[4].unk2C = gBattleWork.unk102[7] + 2;
    }
    gSpriteEntries[4].unk2D = 0;
    battle_seq_advance();
}

// Opcode 0x20: clears the 64x32 BG0, restores it to 32x32 and stops the BG effects.
void battle_seq_cmd_bg_effect_end(void) {
    tilemap_fill_rect(0x20, 0x20, 0, 0, REG_BG0CNT, 0);
    tilemap_fill_rect(0x20, 0x20, 0x20, 0, REG_BG0CNT, 0);
    REG_BG0CNT = 0x500;
    gBg0Scroll.x = 0;
    gBg1Scroll.x = 0;
    clear_battle_sprite_slot(4, 1);
    clear_battle_sprite_slot(0x23, 1);
    battle_seq_advance();
}

// Opcode 0x21: actor_pose, repeated until changed.
void battle_seq_cmd_actor_pose_loop(void) {
    battle_seq_load_operands();
    if (!(gBattleWork.unkF8 & 2)) {
        gSpriteEntries[1].unk2B = 1;
        if (gBattleWork.unkF6 & 2)
            gSpriteEntries[1].unk2C = gBattleWork.unk102[gBattleWork.unk162 + 1];
        else
            gSpriteEntries[1].unk2C = gBattleWork.unk102[gBattleWork.unkA7 + 1];
        gSpriteEntries[1].unk30 = gBattleWork.unk102[0];
        gSpriteEntries[1].unk2D = 1;
    } else {
        gSpriteEntries[2].unk2B = 1;
        if (gBattleWork.unkF6 & 2)
            gSpriteEntries[2].unk2C = gBattleWork.unk102[gBattleWork.unk162 + 4];
        else
            gSpriteEntries[2].unk2C = gBattleWork.unk102[gBattleWork.unkA7 + 4];
        gSpriteEntries[2].unk30 = gBattleWork.unk102[0];
        gSpriteEntries[2].unk2D = 1;
    }
    battle_seq_advance();
}

// Opcode 0x22: target_pose, repeated until changed.
void battle_seq_cmd_target_pose_loop(void) {
    battle_seq_load_operands();
    if (!(gBattleWork.unkF8 & 2)) {
        gSpriteEntries[2].unk2B = 1;
        if (gBattleWork.unkF6 & 2)
            gSpriteEntries[2].unk2C = gBattleWork.unk102[gBattleWork.unk162 + 4];
        else
            gSpriteEntries[2].unk2C = gBattleWork.unk102[gBattleWork.unkA7 + 4];
        gSpriteEntries[2].unk30 = gBattleWork.unk102[0];
        gSpriteEntries[2].unk2D = 1;
    } else {
        gSpriteEntries[1].unk2B = 1;
        if (gBattleWork.unkF6 & 2)
            gSpriteEntries[1].unk2C = gBattleWork.unk102[gBattleWork.unk162 + 1];
        else
            gSpriteEntries[1].unk2C = gBattleWork.unk102[gBattleWork.unkA7 + 1];
        gSpriteEntries[1].unk30 = gBattleWork.unk102[0];
        gSpriteEntries[1].unk2D = 1;
    }
    battle_seq_advance();
}

// Opcode 0x23: stops the bg_sweep from growing.
void battle_seq_cmd_bg_sweep_stop(void) {
    gSpriteEntries[0x23].unk27 = 1;
    battle_seq_advance();
}

// Opcode 0x24: a trail spawner (slot 0xC / 0xD) dropping puffs behind a sprite.
void battle_seq_cmd_trail(void) {
    u32 i;
    u32 slot;

    battle_seq_load_operands();
    for (i = 0; i < 2; i++) {
        if (gSpriteEntries[i + 0xC].unk29 == 0) {
            slot = i + 0xC;
            break;
        }
    }
    clear_battle_sprite_slot(slot, 1);
    gSpriteEntries[slot].unk2B = gBattleWork.unk102[0];
    gSpriteEntries[slot].unk2E = gBattleWork.unk102[1];
    gSpriteEntries[slot].unk30 = gBattleWork.unk102[2];
    gSpriteEntries[slot].unk32 = gBattleWork.unk102[3];
    gSpriteEntries[slot].unk2C = gBattleWork.unk102[4];
    gSpriteEntries[slot].unk2D = gBattleWork.unk102[5];
    gSpriteEntries[slot].unk27 = gBattleWork.unk102[6];
    gSpriteEntries[slot].unk28 = 0;
    gSpriteEntries[slot].unk29 = 0x22;
    battle_seq_advance();
}

// Opcode 0x25: sets sprite operand 0 direction (mirrored) and speed.
void battle_seq_cmd_sprite_motion(void) {
    battle_seq_load_operands();
    if (!(gBattleWork.unkF8 & 2))
        gSpriteEntries[gBattleWork.unk102[0]].unk25 = gBattleWork.unk102[1];
    else
        gSpriteEntries[gBattleWork.unk102[0]].unk25 = (0x20 - (u8)gBattleWork.unk102[1]) & 0x1F;
    gSpriteEntries[gBattleWork.unk102[0]].unk24 = gBattleWork.unk102[2];
    battle_seq_advance();
}

// Opcode 0x26: toggles the horizontal / vertical flip of a sprite.
void battle_seq_cmd_sprite_flip(void) {
    battle_seq_load_operands();
    if (gBattleWork.unk102[1] != 0)
        gSpriteEntries[gBattleWork.unk102[0]].unk0 ^= 0x1000;
    if (gBattleWork.unk102[2] != 0)
        gSpriteEntries[gBattleWork.unk102[0]].unk0 ^= 0x2000;
    battle_seq_advance();
}

// Opcode 0x27: fades all palettes towards a colour (0) or back (1).
void battle_seq_cmd_palette_fade(void) {
    battle_seq_load_operands();
    if (gBattleWork.unk102[0] == 0) {
        palette_backup_from_hardware();
        gSpriteEntries[0x27].unk2F = 0;
        gSpriteEntries[0x27].unk29 = 0x28;
    } else {
        gSpriteEntries[0x27].unk29 = 0x29;
    }
    gSpriteEntries[0x27].unk2B = gBattleWork.unk102[1];
    gSpriteEntries[0x27].unk2C = gBattleWork.unk102[2];
    gSpriteEntries[0x27].unk2D = gBattleWork.unk102[3];
    gSpriteEntries[0x27].unk2E = gBattleWork.unk102[4];
    battle_seq_advance();
}

// Opcode 0x28: copies OBJ palettes 8-11 (actor on the left) or 4-7 to the backup buffer.
void battle_seq_cmd_backup_bot_palettes(void) {
    if (!(gBattleWork.unkF8 & 2)) {
        CpuFastSet((void *)0x05000300, (void *)0x0202F900, 8);
        CpuFastSet((void *)0x05000320, (void *)0x0202F920, 8);
        CpuFastSet((void *)0x05000340, (void *)0x0202F940, 8);
        CpuFastSet((void *)0x05000360, (void *)0x0202F960, 8);
    } else {
        CpuFastSet((void *)0x05000280, (void *)0x0202F880, 8);
        CpuFastSet((void *)0x050002A0, (void *)0x0202F8A0, 8);
        CpuFastSet((void *)0x050002C0, (void *)0x0202F8C0, 8);
        CpuFastSet((void *)0x050002E0, (void *)0x0202F8E0, 8);
    }
    battle_seq_advance();
}

// Opcode 0x2A: copies one BG (0) or OBJ (1) palette to the backup buffer.
void battle_seq_cmd_backup_palette(void) {
    battle_seq_load_operands();
    if (gBattleWork.unk102[0] == 0)
        CpuFastSet((void *)(gBattleWork.unk102[1] * 32 + 0x05000000), (void *)(gBattleWork.unk102[1] * 32 + 0x0202FA00),
                   8);
    else
        CpuFastSet((void *)(gBattleWork.unk102[1] * 32 + 0x05000200), (void *)(gBattleWork.unk102[1] * 32 + 0x0202F800),
                   8);
    battle_seq_advance();
}

// Opcode 0x29: spawn_effect, bobbing up and down as it moves.
void battle_seq_cmd_spawn_effect_wave(void) {
    u32 i;
    u32 slot;

    battle_seq_load_operands();
    for (i = 0; i < 9; i++) {
        if (gSpriteEntries[i + 0xA].unk0 == 0) {
            slot = i + 0xA;
            break;
        }
    }
    clear_battle_sprite_slot(slot, 1);
    gSpriteEntries[slot].unk0 = (gBattleWork.unk102[6] << 10) | 0x4004;
    gSpriteEntries[slot].unk1C = 0;
    gSpriteEntries[slot].unkA = 0xE;
    gSpriteEntries[slot].unkB = 0x80;
    gSpriteEntries[slot].unk2D = gBattleWork.unk102[7];
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[slot].unk2D], slot);
    gSpriteEntries[slot].unk2B = gBattleWork.unk102[0];
    gSpriteEntries[slot].unk4 = gBattleWork.unk102[2];
    gSpriteEntries[slot].unk24 = gBattleWork.unk102[4];
    gSpriteEntries[slot].unk2C = gBattleWork.unk102[5];
    gSpriteEntries[slot].unk29 = 0xD;
    if (!(gBattleWork.unkF8 & 2)) {
        gSpriteEntries[slot].unk2 = gBattleWork.unk102[1];
        gSpriteEntries[slot].unk25 = gBattleWork.unk102[3];
    } else {
        gSpriteEntries[slot].unk0 |= 0x1000;
        gSpriteEntries[slot].unk2 = 0xF0 - gBattleWork.unk102[1];
        gSpriteEntries[slot].unk25 = (0x20 - (u8)gBattleWork.unk102[3]) & 0x1F;
    }
    battle_seq_advance();
}

// Opcode 0x2B: removes the trail spawners.
void battle_seq_cmd_clear_trails(void) {
    clear_battle_sprite_slot(0xC, 2);
    battle_seq_advance();
}

// Opcode 0x2C: bg_effect_at whose last frame stays on screen.
void battle_seq_cmd_bg_effect_keep(void) {
    u32 skill;

    battle_seq_load_operands();
    if (gBattleBots[gBattleWork.unk87].chosenAction <= 3)
        skill = gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1];
    else
        skill = gBattleBots[gBattleWork.unk87].medaforce[0] + 0x50;
    load_battle_entity_palette(skill, gBattleWork.unk102[4], 9);
    gSpriteEntries[4].unk2E = gBattleWork.unk102[0];
    gSpriteEntries[4].unk2F = gBattleWork.unk102[1];
    gSpriteEntries[4].unk2B = gBattleWork.unk102[6];
    gSpriteEntries[4].unk30 = gBattleWork.unk102[5];
    gSpriteEntries[4].unk29 = 0x13;
    tile_anim_init(gBattleSeqTileAnims[gSpriteEntries[4].unk2B], 0, 0);
    gSpriteEntries[4].unk4 = 4;
    if (!(gBattleWork.unkF8 & 2)) {
        gSpriteEntries[4].unk2 = gBattleWork.unk102[2];
        gSpriteEntries[4].unk2C = gBattleWork.unk102[7];
    } else {
        gSpriteEntries[4].unk2 = gBattleWork.unk102[3];
        gSpriteEntries[4].unk2C = (u8)gBattleWork.unk102[7] + 2;
    }
    gSpriteEntries[4].unk2D = 0;
    battle_seq_advance();
}

// Opcode 0x2D: a moving effect sprite (slot 0xA) with four sprites circling it.
void battle_seq_cmd_spawn_orbit(void) {
    u32 i;
    struct Coords16 v;

    battle_seq_load_operands();
    gSpriteEntries[0xA].unk2B = gBattleWork.unk102[0];
    gSpriteEntries[0xA].unk4 = gBattleWork.unk102[2];
    gSpriteEntries[0xA].unk24 = gBattleWork.unk102[4];
    gSpriteEntries[0xA].unk2C = gBattleWork.unk102[5];
    gSpriteEntries[0xA].unk29 = 0x30;
    if (!(gBattleWork.unkF8 & 2)) {
        gSpriteEntries[0xA].unk2 = gBattleWork.unk102[1];
        gSpriteEntries[0xA].unk25 = gBattleWork.unk102[3];
    } else {
        gSpriteEntries[0xA].unk2 = 0xF0 - gBattleWork.unk102[1];
        gSpriteEntries[0xA].unk25 = (0x20 - (u8)gBattleWork.unk102[3]) & 0x1F;
    }
    for (i = 0; i < 4; i++) {
        gSpriteEntries[i + 0xB].unk0 = (gBattleWork.unk102[6] << 10) | 0x4004;
        gSpriteEntries[i + 0xB].unk1C = 0;
        gSpriteEntries[i + 0xB].unkA = 0xE;
        gSpriteEntries[i + 0xB].unkB = 0x80;
        gSpriteEntries[i + 0xB].unk2D = gBattleWork.unk102[7];
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[i + 0xB].unk2D], i + 0xB);
        gSpriteEntries[i + 0xB].unk2B = gBattleWork.unk102[0];
        gSpriteEntries[i + 0xB].unk2C = gBattleWork.unk102[5];
        gSpriteEntries[i + 0xB].unk29 = 0x31;
        v = calc_polar_to_screen_coords(i * 64, 0x10, gSpriteEntries[0xA].unk2, gSpriteEntries[0xA].unk4);
        gSpriteEntries[i + 0xB].unk2 = v.x;
        gSpriteEntries[i + 0xB].unk4 = v.y;
        gSpriteEntries[i + 0xB].unk26 = i * 64 - 0x20;
    }
    battle_seq_advance();
}

// Opcode 0x2E: four effect sprites at the gBattleSeqEffectSetPos positions.
void battle_seq_cmd_spawn_effect_set(void) {
    u32 i;
    const struct Unk_083AF94C *tbl;
    struct BattleWork *b;
    u8 *f;

    battle_seq_load_operands();
    i = 0;
    b = &gBattleWork;
    f = &b->unkF8;
    tbl = gBattleSeqEffectSetPos;
    do {
        gSpriteEntries[i + 0xA].unk0 = 0xC004;
        gSpriteEntries[i + 0xA].unk1C = 0;
        gSpriteEntries[i + 0xA].unk4 = tbl->y;
        gSpriteEntries[i + 0xA].unkA = 0xE;
        gSpriteEntries[i + 0xA].unkB = 0x80;
        gSpriteEntries[i + 0xA].unk2C = b->unk102[0];
        gSpriteEntries[i + 0xA].unk2B = b->unk102[0];
        gSpriteEntries[i + 0xA].unk25 = b->unk102[1];
        gSpriteEntries[i + 0xA].unk24 = b->unk102[2];
        gSpriteEntries[i + 0xA].unk29 = 0xB;
        gSpriteEntries[i + 0xA].unk2D = b->unk102[3];
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[i + 0xA].unk2D], i + 0xA);
        if (!(*f & 2))
            gSpriteEntries[i + 0xA].unk2 = tbl->x;
        else
            gSpriteEntries[i + 0xA].unk2 = (0xF6 - tbl->x) & 0x1FF;
        tbl++;
        i++;
    } while (i < 4);
    battle_seq_advance();
}

// Opcode 0x2F: decompresses gBattleSeqEwramGfx[operand 0] to EWRAM, palette to OBJ palette 14.
void battle_seq_cmd_load_effect_gfx_ewram(void) {
    battle_seq_load_operands();
    lz_decompress(gBattleSeqEwramGfx[gBattleWork.unk102[0] * 2], (void *)0x02000000);
    CpuFastSet(gBattleSeqEwramGfx[gBattleWork.unk102[0] * 2 + 1], (void *)0x050003C0, 8);
    battle_seq_advance();
}

// Opcode 0x30: spawn_effect that also runs a tile animation.
void battle_seq_cmd_spawn_effect_tiles(void) {
    u32 i;
    u32 slot;

    battle_seq_load_operands();
    for (i = 0; i < 9; i++) {
        if (gSpriteEntries[i + 0xA].unk0 == 0) {
            slot = i + 0xA;
            break;
        }
    }
    clear_battle_sprite_slot(slot, 1);
    gSpriteEntries[slot].unk0 = (gBattleWork.unk102[6] << 10) | 0x4004;
    gSpriteEntries[slot].unk1C = 0;
    gSpriteEntries[slot].unkA = 0xE;
    gSpriteEntries[slot].unkB = 0x80;
    gSpriteEntries[slot].unk2D = gBattleWork.unk102[7];
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[slot].unk2D], slot);
    gSpriteEntries[slot].unk2B = gBattleWork.unk102[0];
    gSpriteEntries[slot].unk4 = gBattleWork.unk102[2];
    gSpriteEntries[slot].unk24 = gBattleWork.unk102[4];
    gSpriteEntries[slot].unk2C = gBattleWork.unk102[5];
    gSpriteEntries[slot].unk29 = 0xE;
    if (!(gBattleWork.unkF8 & 2)) {
        gSpriteEntries[slot].unk2 = gBattleWork.unk102[1];
        gSpriteEntries[slot].unk25 = gBattleWork.unk102[3];
    } else {
        gSpriteEntries[slot].unk0 |= 0x1000;
        gSpriteEntries[slot].unk2 = 0xF0 - gBattleWork.unk102[1];
        gSpriteEntries[slot].unk25 = (0x20 - (u8)gBattleWork.unk102[3]) & 0x1F;
    }
    battle_seq_advance();
}

// Opcode 0x31: starts tile animation operand 0 for sprite operand 1.
void battle_seq_cmd_set_tile_anim(void) {
    battle_seq_load_operands();
    gSpriteEntries[gBattleWork.unk102[1]].unk2E = gBattleWork.unk102[0];
    tile_anim_init_dup(gBattleSeqTileAnims[gBattleWork.unk102[0]], 0, 0);
    battle_seq_advance();
}

// Opcode 0x32: decompresses the skill's graphics to EWRAM.
void battle_seq_cmd_load_skill_gfx(void) {
    if (gBattleBots[gBattleWork.unk87].chosenAction <= 3)
        decompress_indexed_graphics_to_ewram(gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1]);
    else
        decompress_indexed_graphics_to_ewram(gBattleBots[gBattleWork.unk87].medaforce[0] + 0x50);
    battle_seq_advance();
}

// Opcode 0x33: load_effect_gfx at OBJ tile operand 1.
void battle_seq_cmd_load_effect_gfx_at(void) {
    battle_seq_load_operands();
    lz_decompress_dispatch(gBattleSeqEffectGfx[gBattleWork.unk102[0] * 2],
                           (void *)(gBattleWork.unk102[1] * 32 + 0x06010000));
    CpuFastSet(gBattleSeqEffectGfx[gBattleWork.unk102[0] * 2 + 1], (void *)0x050003C0, 8);
    battle_seq_advance();
}

// Opcode 0x34: makes a sprite affine and shrinks or grows it.
void battle_seq_cmd_scale_sprite(void) {
    battle_seq_load_operands();
    gSpriteEntries[gBattleWork.unk102[0]].unk0 |= 0x200;
    gSpriteEntries[gBattleWork.unk102[0]].unk8 = gBattleWork.unk102[4];
    gSpriteEntries[gBattleWork.unk102[0]].unk9 = gBattleWork.unk102[5];
    gSpriteEntries[gBattleWork.unk102[0]].unk18 = 0;
    gSpriteEntries[gBattleWork.unk102[0]].unk26 = gBattleWork.unk102[3];
    gSpriteEntries[gBattleWork.unk102[0]].unk2D = gBattleWork.unk102[2];
    gSpriteEntries[gBattleWork.unk102[0]].unk23 = gBattleWork.unk102[1];
    gSpriteEntries[gBattleWork.unk102[0]].unk29 = 0x34;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[gBattleWork.unk102[0]].unk2D],
                                      gBattleWork.unk102[0]);
    battle_seq_advance();
}

// Opcode 0x35: eight sprites in a ring around a sprite, spiralling.
void battle_seq_cmd_spawn_ring(void) {
    u32 i;
    struct Coords16 v;

    battle_seq_load_operands();
    for (i = 0; i < 8; i++) {
        gSpriteEntries[i + 0xB].unk0 = 0xC604;
        gSpriteEntries[i + 0xB].unk1C = 0;
        v = calc_polar_to_screen_coords(i * 32, gBattleWork.unk102[3], gSpriteEntries[gBattleWork.unk102[0]].unk2,
                                        gSpriteEntries[gBattleWork.unk102[0]].unk4);
        gSpriteEntries[i + 0xB].unk2 = v.x;
        gSpriteEntries[i + 0xB].unk4 = v.y;
        gSpriteEntries[i + 0xB].unk8 = 8;
        gSpriteEntries[i + 0xB].unk9 = 8;
        gSpriteEntries[i + 0xB].unkA = 0xE;
        gSpriteEntries[i + 0xB].unkB = 0x80;
        gSpriteEntries[i + 0xB].unk29 = 0x36;
        gSpriteEntries[i + 0xB].unk26 = i * 32;
        gSpriteEntries[i + 0xB].unk27 = gBattleWork.unk102[3];
        gSpriteEntries[i + 0xB].unk2B = 0;
        gSpriteEntries[i + 0xB].unk23 = gBattleWork.unk102[1];
        gSpriteEntries[i + 0xB].unk2D = gBattleWork.unk102[2];
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[i + 0xB].unk2D], i + 0xB);
    }
    battle_seq_advance();
}

// Opcode 0x36: shows the armor panel and drains the actor's armor values.
void battle_seq_cmd_armor_panel(void) {
    u8 mirrored;

    battle_seq_load_operands();
    lz_decompress_dispatch(gUnk_084C4F00, (void *)0x06006400);
    lz_decompress_dispatch(gUnk_084882F4, (void *)0x06006520);
    lz_decompress_dispatch(gUnk_084C3648, (void *)0x06006600);
    lz_decompress_dispatch(gUnk_084C65C8, (void *)0x06006800);
    CpuFastSet(gUnk_08488B24, (void *)0x05000140, 8);
    CpuFastSet(gUnk_084E3098, (void *)0x05000100, 8);
    CpuFastSet(gUnk_084C6A58, (void *)0x05000160, 8);
    mirrored = gBattleWork.unkF8 & 2;
    if (mirrored == 0)
        gSpriteEntries[9].unk2D = mirrored;
    else
        gSpriteEntries[9].unk2D = 1;
    gSpriteEntries[9].unk2E = 1;
    gSpriteEntries[9].unk2B = gBattleWork.unk102[0];
    gSpriteEntries[9].unk2C = gBattleWork.unk102[1];
    gSpriteEntries[9].unk29 = 0x38;
    battle_seq_advance();
}

// Opcode 0x37: waits until the armor panel is done.
void battle_seq_cmd_wait_armor_panel(void) {
    if (gSpriteEntries[9].unk29 == 0)
        battle_seq_advance();
    gSpriteEntries[0].unk2A = 1;
}

// Opcode 0x38: clears BG0 and BG1 and stops the BG effects.
void battle_seq_cmd_bg_effect_clear(void) {
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG1CNT, 0);
    clear_battle_sprite_slot(4, 1);
    clear_battle_sprite_slot(0x23, 1);
    battle_seq_advance();
}

// Opcode 0x39: bg_effect without the mirrored tile variant.
void battle_seq_cmd_bg_effect_noflip(void) {
    u32 skill;

    battle_seq_load_operands();
    if (gBattleBots[gBattleWork.unk87].chosenAction <= 3)
        skill = gBattleBots[gBattleWork.unk87].parts[gBattleWork.unkA7].data[1];
    else
        skill = gBattleBots[gBattleWork.unk87].medaforce[0] + 0x50;
    load_battle_entity_palette(skill, gBattleWork.unk102[4], 9);
    gSpriteEntries[4].unk2E = gBattleWork.unk102[0];
    gSpriteEntries[4].unk2F = gBattleWork.unk102[1];
    gSpriteEntries[4].unk2B = gBattleWork.unk102[6];
    gSpriteEntries[4].unk30 = gBattleWork.unk102[5];
    gSpriteEntries[4].unk29 = 0x10;
    tile_anim_init(gBattleSeqTileAnims[gSpriteEntries[4].unk2B], 0, 0);
    gSpriteEntries[4].unk4 = gBattleWork.unk102[3];
    gSpriteEntries[4].unk2C = gBattleWork.unk102[7];
    if (!(gBattleWork.unkF8 & 2))
        gSpriteEntries[4].unk2 = gBattleWork.unk102[2];
    else
        gSpriteEntries[4].unk2 =
            0x1E - (gSpriteEntries[4].unk2E >> 1) - (gBattleWork.unk102[2] + (gSpriteEntries[4].unk2E >> 1));
    gSpriteEntries[4].unk2D = 0;
    battle_seq_advance();
}

// Opcode 0x3A: two sprites hop and show the digits unk188 / unk189. guess: the two rolls.
void battle_seq_cmd_show_rolls(void) {
    u32 i;

    for (i = 0; i < 2; i++) {
        gSpriteEntries[i + 0xA].unk28 = (&gBattleWork.unk188)[i];
        gSpriteEntries[i + 0xA].unk23 = 0;
        gSpriteEntries[i + 0xA].unk29 = 0x3A;
        gSpriteEntries[i + 0xA].unk26 = i + 0x56;
    }
    play_sound_effect(0x10);
    battle_seq_advance();
}

void battle_sequence_update_sprites(void) {
    u32 i;

    for (i = 0; i <= 0x26; i++) {
        gEffectSpriteSlot = i + 1;
        gBattleSeqSpriteHandlers[gSpriteEntries[i + 1].unk29]();
    }
}

// Sprite 1 / 2 state 1: waits for the pose to finish before the queued one (state 2, or 3 to loop).
void battle_seq_spr_pose_wait(void) {
    if (gSpriteEntries[gGameWork.unk12F].unk2B != 0) {
        if (gGameWork.unk12F == 1) {
            if (gBattleWork.unk15F != 0) {
                gSpriteEntries[gGameWork.unk12F].unk2B = 0;
                if (gSpriteEntries[gGameWork.unk12F].unk2D != 0) {
                    gSpriteEntries[gGameWork.unk12F].unk29++;
                    gSpriteEntries[gGameWork.unk12F].unk29++;
                } else {
                    gSpriteEntries[gGameWork.unk12F].unk29++;
                }
            }
        } else if (gBattleWork.unk160 != 0) {
            gSpriteEntries[gGameWork.unk12F].unk2B = 0;
            if (gSpriteEntries[gGameWork.unk12F].unk2D != 0) {
                gSpriteEntries[gGameWork.unk12F].unk29++;
                gSpriteEntries[gGameWork.unk12F].unk29++;
            } else {
                gSpriteEntries[gGameWork.unk12F].unk29++;
            }
        }
    }
}

// Sprite 1 / 2 state 2: after the delay, starts the queued pose (redrawing the Medabot if needed).
void battle_seq_spr_pose_set(void) {
    if (gSpriteEntries[gEffectSpriteSlot].unk30 != 0) {
        gSpriteEntries[gEffectSpriteSlot].unk30--;
        return;
    }
    if (gEffectSpriteSlot == 1) {
        if (gBattleWork.unkFF & 1) {
            get_active_bot_part_index_and_load_values(0);
            draw_medabot_sprite(0, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2],
                                gBattleWork.unk64[3], (s16)gBattleWork.unk154, (s16)gBattleWork.unk156,
                                gBattleWork.unk39[3] + 2, 4, 0, 0, 0, gBattleWork.unk114[0]);
            draw_medabot_sprite(0, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2],
                                gBattleWork.unk64[3], (s16)gBattleWork.unk154, (s16)gBattleWork.unk156,
                                gBattleWork.unk39[3] + 2, 4, 0, 1, 0, gBattleWork.unk114[0]);
        }
        gBattleWork.unkFF &= ~1;
        gBattleWork.unk112 = gSpriteEntries[gEffectSpriteSlot].unk2C;
    } else {
        if (gBattleWork.unkFF & 2) {
            get_active_bot_part_index_and_load_values(1);
            draw_medabot_sprite(1, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2],
                                gBattleWork.unk64[3], (s16)gBattleWork.unk158, (s16)gBattleWork.unk15A,
                                gBattleWork.unk39[3] + 2, 8, 1, 0, 1, gBattleWork.unk114[1]);
            draw_medabot_sprite(1, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2],
                                gBattleWork.unk64[3], (s16)gBattleWork.unk158, (s16)gBattleWork.unk15A,
                                gBattleWork.unk39[3] + 2, 8, 1, 1, 1, gBattleWork.unk114[1]);
        }
        gBattleWork.unkFF &= ~2;
        gBattleWork.unk113 = gSpriteEntries[gEffectSpriteSlot].unk2C;
    }
    gSpriteEntries[gGameWork.unk12F].unk29 = 1;
}

// Sprite 1 / 2 state 3: restarts the queued pose each time it finishes.
void battle_seq_spr_pose_repeat(void) {
    struct SpriteEntry *base = gSpriteEntries;
    register u32 i asm("r4") = gEffectSpriteSlot;
    u8 slot;
    struct GameWork *p;
    register struct SpriteEntry *q asm("r1") = &base[i];
    register u16 t asm("r3");
    if ((t = q->unk30) != 0) {
        register u16 n asm("r0") = t - 1;
        q->unk30 = n;
        return;
    }
    slot = i;
    p = &gGameWork;
    if (slot == 1) {
        if (gBattleWork.unk15F != 0) {
            if (gBattleWork.unkFF & 1) {
                get_active_bot_part_index_and_load_values(0);
                draw_medabot_sprite(0, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2],
                                    gBattleWork.unk64[3], (s16)gBattleWork.unk154, (s16)gBattleWork.unk156,
                                    gBattleWork.unk39[3] + 2, 4, 0, 0, 0, gBattleWork.unk114[0]);
                draw_medabot_sprite(0, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2],
                                    gBattleWork.unk64[3], (s16)gBattleWork.unk154, (s16)gBattleWork.unk156,
                                    gBattleWork.unk39[3] + 2, 4, 0, 1, 0, gBattleWork.unk114[0]);
            }
            gBattleWork.unkFF &= ~1;
            gBattleWork.unk112 = gSpriteEntries[gEffectSpriteSlot].unk2C;
        }
    } else if (gBattleWork.unk160 != 0) {
        if (gBattleWork.unkFF & 2) {
            get_active_bot_part_index_and_load_values(1);
            draw_medabot_sprite(1, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2],
                                gBattleWork.unk64[3], (s16)gBattleWork.unk158, (s16)gBattleWork.unk15A,
                                gBattleWork.unk39[3] + 2, 8, 1, 0, 1, gBattleWork.unk114[1]);
            draw_medabot_sprite(1, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2],
                                gBattleWork.unk64[3], (s16)gBattleWork.unk158, (s16)gBattleWork.unk15A,
                                gBattleWork.unk39[3] + 2, 8, 1, 1, 1, gBattleWork.unk114[1]);
        }
        gBattleWork.unkFF &= ~2;
        gBattleWork.unk113 = gSpriteEntries[gEffectSpriteSlot].unk2C;
    }
    if (gSpriteEntries[p->unk12F].unk2D == 0)
        gSpriteEntries[p->unk12F].unk29 = 1;
}

static inline void set_xy(u32 a, u32 b) {
    gBattleWork.unk154 = a & 0x1FF;
    gBattleWork.unk158 = b & 0x1FF;
}

static inline void set_yx(u32 b, u32 a, u32 m) {
    gBattleWork.unk154 = a & m;
    gBattleWork.unk158 = b & m;
}

// Sprite 3 state 8: actor_dash: moves the actor, scrolling the camera once it passes the centre.
void battle_seq_spr_actor_dash(void) {
    u32 d;
    u8 shift;
    u32 x;
    shift = gBattleBg3ParallaxShift[gBattleWork.unk38];
    if (gSpriteEntries[gGameWork.unk12F].unk2C == 0) {
        struct SpriteEntry *q;
        gBattleWork.unk154 += gSpriteEntries[gGameWork.unk12F].unk2B;
        gBattleWork.unk154 &= 0x1FF;
        gSpriteEntries[gGameWork.unk12F].unk30 += gSpriteEntries[gGameWork.unk12F].unk2B;
        q = &gSpriteEntries[gGameWork.unk12F];
        x = q->unk30;
        if (x > 0x78) {
            register u32 lim asm("r5") = 0x188;
            if (x <= lim) {
                d = ((s16)gBattleWork.unk154) - 0x78;
                set_xy(gBattleWork.unk154 - d, gBattleWork.unk158 - d);
                gBg2Scroll.x += d;
                gBg3Scroll.x += d >> shift;
            } else {
                register u32 y asm("r1") = ((volatile struct SpriteEntry *)q)->unk30;
                if ((s32)(y - 0x188) < q->unk2B) {
                    {
                        register u32 e asm("r0") = q->unk2B + lim;
                        d = e - y;
                    }
                    set_xy(gBattleWork.unk154 - d, gBattleWork.unk158 - d);
                    gBg2Scroll.x += d;
                    gBg3Scroll.x += d >> shift;
                } else if (y > 0x18F) {
                    q->unk29 = 0;
                }
            }
        }
    } else {
        u32 t;
        register u32 m asm("r5");
        struct SpriteEntry *q;
        gBattleWork.unk158 -= gSpriteEntries[gGameWork.unk12F].unk2B;
        m = 0x1FF;
        gBattleWork.unk158 &= m;
        gSpriteEntries[gGameWork.unk12F].unk30 -= gSpriteEntries[gGameWork.unk12F].unk2B;
        q = &gSpriteEntries[gGameWork.unk12F];
        t = q->unk30 & m;
        if (((u16)(((volatile struct SpriteEntry *)q)->unk30 - 0x78)) > 0x78) {
            if ((t - 0x78) > 0xEF) {
                d = 0x78 - ((s16)gBattleWork.unk158);
                set_yx(gBattleWork.unk158 - (-d), gBattleWork.unk154 + d, m);
                gBg2Scroll.x -= d;
                gBg3Scroll.x -= d >> shift;
            } else if ((t <= 0x167) && ((0x168 - t) < gSpriteEntries[gGameWork.unk12F].unk2B)) {
                d = gSpriteEntries[gGameWork.unk12F].unk2B - (0x168 - t);
                set_yx(gBattleWork.unk158 - (-d), gBattleWork.unk154 + d, m);
                gBg2Scroll.x -= d;
                gBg3Scroll.x -= d >> shift;
            } else if (t <= 0x160) {
                gSpriteEntries[gGameWork.unk12F].unk29 = 0;
            }
        }
    }
}

// Sprite 3 state 9: actor_move: moves the sprite and copies its position to the actor.
void battle_seq_spr_actor_move(void) {
    if (gSpriteEntries[gGameWork.unk12F].unk2D != 0) {
        gSpriteEntries[gGameWork.unk12F].unk2D--;
        update_sprite_animation_position(gGameWork.unk12F);
        if (gSpriteEntries[3].unk2C == 0) {
            gBattleWork.unk154 = gSpriteEntries[gGameWork.unk12F].unk2;
            gBattleWork.unk156 = gSpriteEntries[gGameWork.unk12F].unk4;
        } else {
            gBattleWork.unk158 = gSpriteEntries[gGameWork.unk12F].unk2;
            gBattleWork.unk15A = gSpriteEntries[gGameWork.unk12F].unk4;
        }
    } else {
        clear_battle_sprite_slot(gGameWork.unk12F, 1);
    }
}

// Sprite 0x1E state 0xA: camera_track.
void battle_seq_spr_camera_track(void) {
    u32 d;
    u32 delta;
    u8 shift;

    if (gSpriteEntries[gGameWork.unk12F].unk2B != 0) {
        gSpriteEntries[gGameWork.unk12F].unk2B--;
        return;
    }
    shift = gBattleBg3ParallaxShift[gBattleWork.unk38];
    if ((u8)(gSpriteEntries[gGameWork.unk12F].unk25 - 1) <= 14) {
        delta = gSpriteEntries[gGameWork.unk12F].unk2;
        update_sprite_animation_position(gGameWork.unk12F);
        delta = gSpriteEntries[gGameWork.unk12F].unk2 - delta;
        gSpriteEntries[gGameWork.unk12F].unk30 += delta;
        if (gSpriteEntries[gGameWork.unk12F].unk30 > 0x78) {
            if (gSpriteEntries[gGameWork.unk12F].unk30 <= 0x188) {
                d = gSpriteEntries[gGameWork.unk12F].unk2 - 0x78;
                gBattleWork.unk154 = (gBattleWork.unk154 - d) & 0x1FF;
                gBattleWork.unk158 = (gBattleWork.unk158 - d) & 0x1FF;
                gSpriteEntries[gGameWork.unk12F].unk2 = (gSpriteEntries[gGameWork.unk12F].unk2 - d) & 0x1FF;
                battle_sprite_rotate_angles(1, d);
                gBg2Scroll.x += d;
                gBg3Scroll.x += d >> shift;
            } else if (gSpriteEntries[gGameWork.unk12F].unk30 - 0x188 < delta) {
                d = delta + (0x188 - gSpriteEntries[gGameWork.unk12F].unk30);
                gBattleWork.unk154 = (gBattleWork.unk154 - d) & 0x1FF;
                gBattleWork.unk158 = (gBattleWork.unk158 - d) & 0x1FF;
                gSpriteEntries[gGameWork.unk12F].unk2 = (gSpriteEntries[gGameWork.unk12F].unk2 - d) & 0x1FF;
                battle_sprite_rotate_angles(1, d);
                gBg2Scroll.x += d;
                gBg3Scroll.x += d >> shift;
            } else if (gSpriteEntries[gGameWork.unk12F].unk30 > 0x18F) {
                gSpriteEntries[gGameWork.unk12F].unk29 = 0;
            }
        }
    } else if ((u8)(gSpriteEntries[gGameWork.unk12F].unk25 - 0x11) <= 14) {
        u32 t;

        d = gSpriteEntries[gGameWork.unk12F].unk2;
        update_sprite_animation_position(gGameWork.unk12F);
        d = d - gSpriteEntries[gGameWork.unk12F].unk2;
        gSpriteEntries[gGameWork.unk12F].unk30 = (gSpriteEntries[gGameWork.unk12F].unk30 - d) & 0x1FF;
        t = gSpriteEntries[gGameWork.unk12F].unk30;
        if ((u16)(t - 0x78) > 0x78) {
            if (t - 0x78 > 0xEF) {
                d = 0x78 - gSpriteEntries[gGameWork.unk12F].unk2;
                gBattleWork.unk154 = (gBattleWork.unk154 + d) & 0x1FF;
                gBattleWork.unk158 = (gBattleWork.unk158 + d) & 0x1FF;
                gSpriteEntries[gGameWork.unk12F].unk2 = (gSpriteEntries[gGameWork.unk12F].unk2 + d) & 0x1FF;
                battle_sprite_rotate_angles(0, d);
                gBg2Scroll.x -= d;
                gBg3Scroll.x -= d >> shift;
            } else if (t <= 0x167 && 0x168 - t < d) {
                d = d - (0x168 - t);
                gBattleWork.unk154 = (gBattleWork.unk154 + d) & 0x1FF;
                gBattleWork.unk158 = (gBattleWork.unk158 + d) & 0x1FF;
                gSpriteEntries[gGameWork.unk12F].unk2 = (gSpriteEntries[gGameWork.unk12F].unk2 + d) & 0x1FF;
                battle_sprite_rotate_angles(0, d);
                gBg2Scroll.x -= d;
                gBg3Scroll.x -= d >> shift;
            } else if (t <= 0x160) {
                gSpriteEntries[gGameWork.unk12F].unk29 = 0;
            }
        }
    }
}

// Sprite 0x1E state 0xC: camera_track_all.
void battle_seq_spr_camera_track_all(void) {
    u32 d;
    u32 delta;
    u8 shift;

    if (gSpriteEntries[gGameWork.unk12F].unk2B != 0) {
        gSpriteEntries[gGameWork.unk12F].unk2B--;
        return;
    }
    shift = gBattleBg3ParallaxShift[gBattleWork.unk38];
    if ((u8)(gSpriteEntries[gGameWork.unk12F].unk25 - 1) <= 14) {
        delta = gSpriteEntries[gGameWork.unk12F].unk2;
        update_sprite_animation_position(gGameWork.unk12F);
        delta = gSpriteEntries[gGameWork.unk12F].unk2 - delta;
        gSpriteEntries[gGameWork.unk12F].unk30 += delta;
        if (gSpriteEntries[gGameWork.unk12F].unk30 > 0x78) {
            if (gSpriteEntries[gGameWork.unk12F].unk30 <= 0x188) {
                d = gSpriteEntries[gGameWork.unk12F].unk2 - 0x78;
                gBattleWork.unk154 = (gBattleWork.unk154 - d) & 0x1FF;
                gBattleWork.unk158 = (gBattleWork.unk158 - d) & 0x1FF;
                gSpriteEntries[gGameWork.unk12F].unk2 = (gSpriteEntries[gGameWork.unk12F].unk2 - d) & 0x1FF;
                battle_sprite_rotate_angles(1, d);
                gBg0Scroll.x += d;
                gBg1Scroll.x += d;
                gBg2Scroll.x += d;
                gBg3Scroll.x += d >> shift;
            } else if (gSpriteEntries[gGameWork.unk12F].unk30 - 0x188 < delta) {
                d = delta + (0x188 - gSpriteEntries[gGameWork.unk12F].unk30);
                gBattleWork.unk154 = (gBattleWork.unk154 - d) & 0x1FF;
                gBattleWork.unk158 = (gBattleWork.unk158 - d) & 0x1FF;
                gSpriteEntries[gGameWork.unk12F].unk2 = (gSpriteEntries[gGameWork.unk12F].unk2 - d) & 0x1FF;
                battle_sprite_rotate_angles(1, d);
                gBg0Scroll.x += d;
                gBg1Scroll.x += d;
                gBg2Scroll.x += d;
                gBg3Scroll.x += d >> shift;
            } else if (gSpriteEntries[gGameWork.unk12F].unk30 > 0x18F) {
                gSpriteEntries[gGameWork.unk12F].unk29 = 0;
            }
        }
    } else if ((u8)(gSpriteEntries[gGameWork.unk12F].unk25 - 0x11) <= 14) {
        u32 t;

        d = gSpriteEntries[gGameWork.unk12F].unk2;
        update_sprite_animation_position(gGameWork.unk12F);
        d = d - gSpriteEntries[gGameWork.unk12F].unk2;
        gSpriteEntries[gGameWork.unk12F].unk30 = (gSpriteEntries[gGameWork.unk12F].unk30 - d) & 0x1FF;
        t = gSpriteEntries[gGameWork.unk12F].unk30;
        if ((u16)(t - 0x78) > 0x78) {
            if (t - 0x78 > 0xEF) {
                d = 0x78 - gSpriteEntries[gGameWork.unk12F].unk2;
                gBattleWork.unk154 = (gBattleWork.unk154 + d) & 0x1FF;
                gBattleWork.unk158 = (gBattleWork.unk158 + d) & 0x1FF;
                gSpriteEntries[gGameWork.unk12F].unk2 = (gSpriteEntries[gGameWork.unk12F].unk2 + d) & 0x1FF;
                battle_sprite_rotate_angles(0, d);
                gBg0Scroll.x -= d;
                gBg1Scroll.x -= d;
                gBg2Scroll.x -= d;
                gBg3Scroll.x -= d >> shift;
            } else if (t <= 0x167 && 0x168 - t < d) {
                d = d - (0x168 - t);
                gBattleWork.unk154 = (gBattleWork.unk154 + d) & 0x1FF;
                gBattleWork.unk158 = (gBattleWork.unk158 + d) & 0x1FF;
                gSpriteEntries[gGameWork.unk12F].unk2 = (gSpriteEntries[gGameWork.unk12F].unk2 + d) & 0x1FF;
                battle_sprite_rotate_angles(0, d);
                gBg0Scroll.x -= d;
                gBg1Scroll.x -= d;
                gBg2Scroll.x -= d;
                gBg3Scroll.x -= d >> shift;
            } else if (t <= 0x160) {
                gSpriteEntries[gGameWork.unk12F].unk29 = 0;
            }
        }
    }
}

// State 0xB: an effect sprite: appears after unk2C frames, moves after unk2B frames.
void battle_seq_spr_effect(void) {
    if (gSpriteEntries[gGameWork.unk12F].unk2C != 0) {
        gSpriteEntries[gGameWork.unk12F].unk2C--;
    } else {
        gSpriteEntries[gGameWork.unk12F].unk0 |= 0x8000;
        process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gGameWork.unk12F].unk2D], gGameWork.unk12F);
    }
    if (gSpriteEntries[gGameWork.unk12F].unk2B != 0)
        gSpriteEntries[gGameWork.unk12F].unk2B--;
    else
        update_sprite_animation_position(gGameWork.unk12F);
}

// State 0xD: battle_seq_spr_effect plus a y offset from gBattleSeqWaveOffsets.
void battle_seq_spr_effect_wave(void) {
    if (gSpriteEntries[gGameWork.unk12F].unk2C != 0) {
        gSpriteEntries[gGameWork.unk12F].unk2C--;
    } else {
        gSpriteEntries[gGameWork.unk12F].unk0 |= 0x8000;
        process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gGameWork.unk12F].unk2D], gGameWork.unk12F);
    }
    if (gSpriteEntries[gGameWork.unk12F].unk2B != 0) {
        gSpriteEntries[gGameWork.unk12F].unk2B--;
    } else {
        update_sprite_animation_position(gGameWork.unk12F);
        gSpriteEntries[gGameWork.unk12F].unk4 += gBattleSeqWaveOffsets[gSpriteEntries[gGameWork.unk12F].unk23];
        gSpriteEntries[gGameWork.unk12F].unk23 = (gSpriteEntries[gGameWork.unk12F].unk23 + 1) & 0x1F;
    }
}

// State 0xE: battle_seq_spr_effect plus its tile animation.
void battle_seq_spr_effect_tiles(void) {
    if (gSpriteEntries[gGameWork.unk12F].unk2C != 0) {
        gSpriteEntries[gGameWork.unk12F].unk2C--;
    } else {
        gSpriteEntries[gGameWork.unk12F].unk0 |= 0x8000;
        process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gGameWork.unk12F].unk2D], gGameWork.unk12F);
        tile_anim_run_dup(gBattleSeqTileAnims[gSpriteEntries[gGameWork.unk12F].unk2E], 0);
    }
    if (gSpriteEntries[gGameWork.unk12F].unk2B != 0)
        gSpriteEntries[gGameWork.unk12F].unk2B--;
    else
        update_sprite_animation_position(gGameWork.unk12F);
}

// Sprite 4 state 0x10: bg_effect.
void battle_seq_spr_bg_effect(void) {
    if (gSpriteEntries[gGameWork.unk12F].unk30 != 0) {
        gSpriteEntries[gGameWork.unk12F].unk30--;
        return;
    }
    tile_anim_run(gBattleSeqTileAnims[gSpriteEntries[gGameWork.unk12F].unk2B], 0);
    if (gGameWork.tileAnims[0].state == 0xFF) {
        vram_fill_tilemap_rect(gSpriteEntries[gGameWork.unk12F].unk2E, gSpriteEntries[gGameWork.unk12F].unk2F,
                               gSpriteEntries[gGameWork.unk12F].unk2, gSpriteEntries[gGameWork.unk12F].unk4, REG_BG0CNT,
                               0);
        clear_battle_sprite_slot(gGameWork.unk12F, 1);
    } else if (gSpriteEntries[gGameWork.unk12F].unk2D == 0) {
        write_tilemap_rect(gSpriteEntries[gGameWork.unk12F].unk2E, gSpriteEntries[gGameWork.unk12F].unk2F,
                           gSpriteEntries[gGameWork.unk12F].unk2, gSpriteEntries[gGameWork.unk12F].unk4,
                           gUnk_083B4AE0[gSpriteEntries[gGameWork.unk12F].unk2C], REG_BG0CNT, 0);
    }
}

// Sprite 0x23 state 0x11: bg_sweep.
void battle_seq_spr_bg_sweep(void) {
    if (gSpriteEntries[gGameWork.unk12F].unk30 != 0) {
        gSpriteEntries[gGameWork.unk12F].unk30--;
        return;
    }
    tile_anim_run(gBattleSeqTileAnims[gSpriteEntries[gGameWork.unk12F].unk2B], 1);
    gSpriteEntries[gGameWork.unk12F].unk28++;
    if ((gSpriteEntries[gGameWork.unk12F].unk28 & 1) && gSpriteEntries[gGameWork.unk12F].unk27 == 0) {
        if (!(gBattleWork.unkF8 & 2))
            write_tilemap_to_vram_0803F1C8(
                gSpriteEntries[gGameWork.unk12F].unk2E, gSpriteEntries[gGameWork.unk12F].unk2F,
                (gSpriteEntries[gGameWork.unk12F].unk2 + gSpriteEntries[gGameWork.unk12F].unk2D) & 0x3F,
                gSpriteEntries[gGameWork.unk12F].unk4, gUnk_083B4AE0[gSpriteEntries[gGameWork.unk12F].unk2C],
                REG_BG0CNT, 0);
        else
            write_tilemap_to_vram_0803F1C8(
                gSpriteEntries[gGameWork.unk12F].unk2E, gSpriteEntries[gGameWork.unk12F].unk2F,
                (gSpriteEntries[gGameWork.unk12F].unk2 - gSpriteEntries[gGameWork.unk12F].unk2D) & 0x3F,
                gSpriteEntries[gGameWork.unk12F].unk4, gUnk_083B4AE0[gSpriteEntries[gGameWork.unk12F].unk2C],
                REG_BG0CNT, 0);
        gSpriteEntries[gGameWork.unk12F].unk2D++;
    }
}

// Sprite 4 state 0x12: bg_effect_at.
void battle_seq_spr_bg_effect_at(void) {
    if (gSpriteEntries[gGameWork.unk12F].unk30 != 0) {
        gSpriteEntries[gGameWork.unk12F].unk30--;
        return;
    }
    tile_anim_run(gBattleSeqTileAnims[gSpriteEntries[gGameWork.unk12F].unk2B], 0);
    if (gGameWork.tileAnims[0].state == 0xFF) {
        tilemap_fill_rect(gSpriteEntries[gGameWork.unk12F].unk2E, gSpriteEntries[gGameWork.unk12F].unk2F,
                          gSpriteEntries[gGameWork.unk12F].unk2, gSpriteEntries[gGameWork.unk12F].unk4, REG_BG0CNT, 0);
        clear_battle_sprite_slot(gGameWork.unk12F, 1);
    } else if (gSpriteEntries[gGameWork.unk12F].unk2D == 0) {
        write_tilemap_to_vram_0803F1C8(gSpriteEntries[gGameWork.unk12F].unk2E, gSpriteEntries[gGameWork.unk12F].unk2F,
                                       gSpriteEntries[gGameWork.unk12F].unk2, gSpriteEntries[gGameWork.unk12F].unk4,
                                       gUnk_083B4AE0[gSpriteEntries[gGameWork.unk12F].unk2C], REG_BG0CNT, 0);
    }
}

// Sprite 4 state 0x13: bg_effect_keep.
void battle_seq_spr_bg_effect_keep(void) {
    if (gSpriteEntries[gGameWork.unk12F].unk30 != 0) {
        gSpriteEntries[gGameWork.unk12F].unk30--;
        return;
    }
    tile_anim_run(gBattleSeqTileAnims[gSpriteEntries[gGameWork.unk12F].unk2B], 0);
    if (gGameWork.tileAnims[0].state == 0xFF) {
        clear_battle_sprite_slot(gGameWork.unk12F, 1);
    } else if (gSpriteEntries[gGameWork.unk12F].unk2D == 0) {
        write_tilemap_to_vram_0803F1C8(gSpriteEntries[gGameWork.unk12F].unk2E, gSpriteEntries[gGameWork.unk12F].unk2F,
                                       gSpriteEntries[gGameWork.unk12F].unk2, gSpriteEntries[gGameWork.unk12F].unk4,
                                       gUnk_083B4AE0[gSpriteEntries[gGameWork.unk12F].unk2C], REG_BG0CNT, 0);
    }
}

// State 0x18: plays sound unk2B unk2E times, unk2D frames apart.
void battle_seq_spr_sound(void) {
    if (gSpriteEntries[gGameWork.unk12F].unk30 != 0) {
        gSpriteEntries[gGameWork.unk12F].unk30--;
    } else if (gSpriteEntries[gGameWork.unk12F].unk2C != 0) {
        gSpriteEntries[gGameWork.unk12F].unk2C--;
    } else if (gSpriteEntries[gGameWork.unk12F].unk2E != 0) {
        play_sound_effect(gSpriteEntries[gGameWork.unk12F].unk2B);
        gSpriteEntries[gGameWork.unk12F].unk2C = gSpriteEntries[gGameWork.unk12F].unk2D;
        gSpriteEntries[gGameWork.unk12F].unk2E--;
    } else {
        clear_battle_sprite_slot(gGameWork.unk12F, 1);
    }
}

// State 0x20: after the delay, starts the animation on slot unk2E (state 0x21) and frees itself.
void battle_seq_spr_anim_delay(void) {
    u8 n;

    if (gSpriteEntries[gGameWork.unk12F].unk2B != 0) {
        gSpriteEntries[gGameWork.unk12F].unk2B--;
        return;
    }
    n = gSpriteEntries[gGameWork.unk12F].unk2E;
    gSpriteEntries[n].unkA = gSpriteEntries[gGameWork.unk12F].unkA;
    gSpriteEntries[n].unk2D = gSpriteEntries[gGameWork.unk12F].unk2D;
    gSpriteEntries[n].unk29 = 0x21;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[n].unk2D], n);
    clear_battle_sprite_slot(gGameWork.unk12F, 1);
}

// State 0x21: runs the sprite animation until it ends, then frees the slot.
void battle_seq_spr_anim_once(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gGameWork.unk12F].unk2D], gGameWork.unk12F);
    if (gSpriteEntries[gGameWork.unk12F].unk22 == 0xFF)
        clear_battle_sprite_slot(gGameWork.unk12F, 1);
}

// State 0x22: every unk2C + 1 frames drops a puff (state 0x23) at an offset from sprite unk2E.
void battle_seq_spr_trail(void) {
    u32 n;

    if (gSpriteEntries[gGameWork.unk12F].unk2B != 0) {
        gSpriteEntries[gGameWork.unk12F].unk2B--;
        return;
    }
    if (gSpriteEntries[gGameWork.unk12F].unk28 != gSpriteEntries[gGameWork.unk12F].unk2C) {
        gSpriteEntries[gGameWork.unk12F].unk28++;
        return;
    }
    gSpriteEntries[gGameWork.unk12F].unk28 = 0;
    n = find_next_free_sprite_slot(0xE, 0x10);
    gSpriteEntries[n].unk0 = 0xC404;
    gSpriteEntries[n].unk1C = 0;
    if (!(gBattleWork.unkF8 & 2))
        gSpriteEntries[n].unk2 =
            (gSpriteEntries[gSpriteEntries[gGameWork.unk12F].unk2E].unk2 + gSpriteEntries[gGameWork.unk12F].unk30) &
            0x1FF;
    else
        gSpriteEntries[n].unk2 = (gSpriteEntries[gSpriteEntries[gGameWork.unk12F].unk2E].unk2 +
                                  (gSpriteEntries[gGameWork.unk12F].unk30 * -1)) &
                                 0x1FF;
    gSpriteEntries[n].unk4 =
        (gSpriteEntries[gSpriteEntries[gGameWork.unk12F].unk2E].unk4 + gSpriteEntries[gGameWork.unk12F].unk32) & 0xFF;
    gSpriteEntries[n].unkA = gSpriteEntries[gGameWork.unk12F].unk27;
    gSpriteEntries[n].unkB = 0x80;
    gSpriteEntries[n].unk29 = 0x23;
    gSpriteEntries[n].unk2D = gSpriteEntries[gGameWork.unk12F].unk2D;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[gGameWork.unk12F].unk2D], n);
}

// State 0x23: a trail puff: plays its animation once.
void battle_seq_spr_trail_puff(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gGameWork.unk12F].unk2D], gGameWork.unk12F);
    if (gSpriteEntries[gGameWork.unk12F].unk22 == 0xFF)
        clear_battle_sprite_slot(gGameWork.unk12F, 1);
}

// State 0x28: blends all palettes one step further towards the colour, up to 16.
void battle_seq_spr_fade_in(void) {
    if (gSpriteEntries[gGameWork.unk12F].unk2B != 0) {
        gSpriteEntries[gGameWork.unk12F].unk2B--;
        return;
    }
    bg_palettes_blend_masked_now((gSpriteEntries[gGameWork.unk12F].unk2E << 10) |
                                     (gSpriteEntries[gGameWork.unk12F].unk2D << 5) |
                                     gSpriteEntries[gGameWork.unk12F].unk2C,
                                 gSpriteEntries[gGameWork.unk12F].unk2F, 0xFDFF);
    obj_palettes_blend_masked_now((gSpriteEntries[gGameWork.unk12F].unk2E << 10) |
                                      (gSpriteEntries[gGameWork.unk12F].unk2D << 5) |
                                      gSpriteEntries[gGameWork.unk12F].unk2C,
                                  gSpriteEntries[gGameWork.unk12F].unk2F, 0xB00F);
    if (gSpriteEntries[gGameWork.unk12F].unk2F == 0x10)
        gSpriteEntries[gGameWork.unk12F].unk29 = 0;
    else
        gSpriteEntries[gGameWork.unk12F].unk2F++;
}

// State 0x29: blends all palettes one step back from the colour, down to 0.
void battle_seq_spr_fade_out(void) {
    if (gSpriteEntries[gGameWork.unk12F].unk2B != 0) {
        gSpriteEntries[gGameWork.unk12F].unk2B--;
        return;
    }
    bg_palettes_blend_masked_now((gSpriteEntries[gGameWork.unk12F].unk2E << 10) |
                                     (gSpriteEntries[gGameWork.unk12F].unk2D << 5) |
                                     gSpriteEntries[gGameWork.unk12F].unk2C,
                                 gSpriteEntries[gGameWork.unk12F].unk2F, 0xFDFF);
    obj_palettes_blend_masked_now((gSpriteEntries[gGameWork.unk12F].unk2E << 10) |
                                      (gSpriteEntries[gGameWork.unk12F].unk2D << 5) |
                                      gSpriteEntries[gGameWork.unk12F].unk2C,
                                  gSpriteEntries[gGameWork.unk12F].unk2F, 0xB00F);
    if (gSpriteEntries[gGameWork.unk12F].unk2F == 0)
        gSpriteEntries[gGameWork.unk12F].unk29 = 0;
    else
        gSpriteEntries[gGameWork.unk12F].unk2F--;
}

// State 0x30: the centre sprite of spawn_orbit.
void battle_seq_spr_orbit_center(void) {
    if (gSpriteEntries[gGameWork.unk12F].unk2C)
        gSpriteEntries[gGameWork.unk12F].unk2C--;
    if (gSpriteEntries[gGameWork.unk12F].unk2B)
        gSpriteEntries[gGameWork.unk12F].unk2B--;
    else
        update_sprite_animation_position(gGameWork.unk12F);
}

// State 0x31: circles sprite 0xA at radius 16.
void battle_seq_spr_orbit(void) {
    struct Coords16 v;

    if (gSpriteEntries[gGameWork.unk12F].unk2C != 0)
        gSpriteEntries[gGameWork.unk12F].unk2C--;
    else {
        gSpriteEntries[gGameWork.unk12F].unk0 |= 0x8000;
        process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gGameWork.unk12F].unk2D], gGameWork.unk12F);
    }
    if (gSpriteEntries[gGameWork.unk12F].unk2B != 0) {
        gSpriteEntries[gGameWork.unk12F].unk2B--;
        return;
    }
    v = calc_polar_to_screen_coords(gSpriteEntries[gGameWork.unk12F].unk26, 0x10, gSpriteEntries[10].unk2,
                                    gSpriteEntries[10].unk4);
    gSpriteEntries[gGameWork.unk12F].unk2 = v.x;
    gSpriteEntries[gGameWork.unk12F].unk4 = v.y;
    if (!(gBattleWork.unkF8 & 2))
        gSpriteEntries[gGameWork.unk12F].unk26 += 0x10;
    else
        gSpriteEntries[gGameWork.unk12F].unk26 -= 0x10;
}

// State 0x34: shrinks the sprite until it vanishes (unk23 = 0) or grows it to 0x40.
void battle_seq_spr_scale(void) {
    struct SpriteEntry *s;
    u8 i;

    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gGameWork.unk12F].unk2D], gGameWork.unk12F);
    i = gGameWork.unk12F;
    s = &gSpriteEntries[i];
    if (s->unk23 == 0) {
        if (s->unk8 <= s->unk26) {
            clear_sprite_table_mask(i, 1);
            return;
        }
        s->unk8 -= s->unk26;
        gSpriteEntries[gGameWork.unk12F].unk9 -= gSpriteEntries[gGameWork.unk12F].unk26;
    } else if (s->unk8 == 0x40)
        s->unk29 = 0;
    else {
        s->unk8 += s->unk26;
        gSpriteEntries[gGameWork.unk12F].unk9 += gSpriteEntries[gGameWork.unk12F].unk26;
    }
}

// State 0x36: a spawn_ring sprite spiralling around sprite 0xA, growing then shrinking.
void battle_seq_spr_ring_spiral(void) {
    struct Coords16 v;

    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gGameWork.unk12F].unk2D], gGameWork.unk12F);
    if (gSpriteEntries[gGameWork.unk12F].unk2B <= 6) {
        gSpriteEntries[gGameWork.unk12F].unk8 += 8;
        gSpriteEntries[gGameWork.unk12F].unk9 += 8;
    }
    if (gSpriteEntries[gGameWork.unk12F].unk2B > 0x3C) {
        if (gSpriteEntries[gGameWork.unk12F].unk8 == 8)
            clear_battle_sprite_slot(gGameWork.unk12F, 1);
        else {
            gSpriteEntries[gGameWork.unk12F].unk8 -= 4;
            gSpriteEntries[gGameWork.unk12F].unk9 -= 4;
        }
    }
    if (gSpriteEntries[gGameWork.unk12F].unk23 == 0) {
        if (!(gSpriteEntries[gGameWork.unk12F].unk2B & 1))
            gSpriteEntries[gGameWork.unk12F].unk27--;
    } else {
        if (!(gSpriteEntries[gGameWork.unk12F].unk2B & 1))
            gSpriteEntries[gGameWork.unk12F].unk27++;
    }
    gSpriteEntries[gGameWork.unk12F].unk26 += 4;
    gSpriteEntries[gGameWork.unk12F].unk2B++;
    v = calc_polar_to_screen_coords(gSpriteEntries[gGameWork.unk12F].unk26, gSpriteEntries[gGameWork.unk12F].unk27,
                                    gSpriteEntries[10].unk2, gSpriteEntries[10].unk4);
    gSpriteEntries[gGameWork.unk12F].unk2 = v.x;
    gSpriteEntries[gGameWork.unk12F].unk4 = v.y;
}

// Sprite 9 state 0x38: draws the armor panel, then drains each part's shown armor to its new value.
void battle_seq_spr_armor_drain(void) {
    u32 done = 0;

    if (gSpriteEntries[gGameWork.unk12F].unk2B != 0) {
        gSpriteEntries[gGameWork.unk12F].unk2B--;
        return;
    }
    if (gSpriteEntries[gGameWork.unk12F].unk2E != 0) {
        armor_panel_draw_icons(gSpriteEntries[gGameWork.unk12F].unk2D);
        armor_panel_draw_frame(gSpriteEntries[gGameWork.unk12F].unk2D);
        armor_panel_draw_bars(gSpriteEntries[gGameWork.unk12F].unk2D, gBattleWork.unk87);
        armor_panel_draw_numbers(gSpriteEntries[gGameWork.unk12F].unk2D, gBattleWork.unk87);
        gSpriteEntries[gGameWork.unk12F].unk2E = 0;
    }
    if (gSpriteEntries[gGameWork.unk12F].unk2C != 0) {
        gSpriteEntries[gGameWork.unk12F].unk2C--;
        return;
    }
    done = armor_drain_step(&gBattleWork.unkD6[0], gBattleWork.unk87, 0);
    done += armor_drain_step(&gBattleWork.unkD6[1], gBattleWork.unk87, 1);
    done += armor_drain_step(&gBattleWork.unkD6[2], gBattleWork.unk87, 2);
    done += armor_drain_step(&gBattleWork.unkD6[3], gBattleWork.unk87, 3);
    armor_panel_draw_bars(gSpriteEntries[gGameWork.unk12F].unk2D, gBattleWork.unk87);
    armor_panel_draw_numbers(gSpriteEntries[gGameWork.unk12F].unk2D, gBattleWork.unk87);
    if (done == 4)
        clear_battle_sprite_slot(gGameWork.unk12F, 1);
}

// State 0x3A: hops, then shows its digit.
void battle_seq_spr_roll_hop(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gGameWork.unk12F].unk26], gGameWork.unk12F);
    if (sprite_hop_step(gGameWork.unk12F)) {
        gSpriteEntries[gGameWork.unk12F].unk6 = 0x6307 + gSpriteEntries[gGameWork.unk12F].unk28;
        gSpriteEntries[gGameWork.unk12F].unk29 = 0;
    }
}

s16 battle_seq_peek(void) {
    const s16 *seq = gBattleSeqScripts[gBattleWork.unkF9];
    return seq[gBattleWork.unk100];
}

void battle_seq_load_operands(void) {
    const s16 *seq = gBattleSeqScripts[gBattleWork.unkF9];
    u32 n = gBattleSeqOperandCounts[seq[gBattleWork.unk100]];
    u32 i;

    for (i = 0; i < n; i++)
        gBattleWork.unk102[i] = seq[gBattleWork.unk100 + i + 1];
}

void battle_seq_advance(void) {
    const s16 *seq = gBattleSeqScripts[gBattleWork.unkF9];
    const u8 *ops = gBattleSeqOperandCounts;
    s32 p = gBattleWork.unk100;

    gBattleWork.unk100 = p + 1 + ops[seq[p]];
}

static void battle_sprite_rotate_angles(u32 dir, u32 delta) {
    u32 i;
    for (i = 0; i <= 0x13; i++) {
        if (gSpriteEntries[i + 10].unk29 != 0) {
            if (dir)
                gSpriteEntries[i + 10].unk2 = (gSpriteEntries[i + 10].unk2 - delta) & 0x1FF;
            else
                gSpriteEntries[i + 10].unk2 = (gSpriteEntries[i + 10].unk2 + delta) & 0x1FF;
        }
    }
}
