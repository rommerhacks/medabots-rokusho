// Battle sequences: the close-up skill animation scripts. script_op_skill_anim_start picks the script
// gBattleSeqScripts[gBattleWork.animSkill] (the skill: acting part's data[1], or Medaforce + 0x50) and
// script_op_skill_anim_run calls battle_sequence_update each frame. Each script entry is an opcode for
// gBattleSeqCommands (battle_seq_cmd_*, in opcode order 0x01-0x3A) followed by gBattleSeqOperandCounts[opcode]
// operands, copied to gBattleWork.seqOperands by battle_seq_load_operands; negative entries are labels for
// battle_seq_cmd_goto / battle_seq_cmd_branch. Commands mostly set up sprite slots, whose per-frame handler
// gBattleSeqSpriteHandlers[work[SEQ_SPR_STATE]] (battle_seq_spr_*) is run by battle_sequence_update_sprites.
// Slots: 1 / 2 left / right Medabot pose, 3 the actor's movement, 4 and 0x23 BG0 tile effects, 9 armor panel,
// 0xA-0x12 effect sprites, 0x1E camera. gBattleWork.actorSideFlags bit 1 = actor on the right: x positions and
// directions are mirrored. Runtime (re/states/battle_start.ss0, skill 22): actor_pose, bg_effect, sound,
// load_effect_gfx, spawn_effect x2, sprite_motion, trail, camera_track, test_missed, branch, target_pose, goto,
// clear_sprites, actor_home, end.

#include "global.h"
#include "constants/battle_seq_sprites.h"
#include "constants/sprites.h"

static void battle_sprite_rotate_angles(u32 dir, u32 delta);

void battle_sequence_update(void) {
    while (gSpriteEntries[0].work[SEQ_RUN_YIELD] == 0)
        battle_sequence_run_command();
    battle_sequence_update_sprites();
    gSpriteEntries[0].work[SEQ_RUN_YIELD] = 0;
}

void battle_sequence_run_command(void) {
    s8 *state;
    if ((s8)(gSpriteEntries[0].work[SEQ_RUN_OPCODE] = battle_seq_peek()) < 0) {
        state = (s8 *)&gSpriteEntries[0].work[SEQ_RUN_OPCODE];
        do {
            battle_seq_advance();
            *state = battle_seq_peek();
        } while (*state < 0);
    }
    gBattleSeqCommands[gSpriteEntries[0].work[SEQ_RUN_OPCODE]]();
}

// Opcode 0x01: ends the sequence (yields and sets the step-done flag stepDone).
void battle_seq_cmd_end(void) {
    gSpriteEntries[0].work[SEQ_RUN_YIELD] = 1;
    gBattleWork.stepDone = 1;
}

// Opcode 0x02: jumps past the label (negative entry) equal to operand 0.
void battle_seq_cmd_goto(void) {
    const s16 *seq;
    vu8 done = 0;

    battle_seq_load_operands();
    battle_seq_advance();
    while (!done) {
        seq = gBattleSeqScripts[gBattleWork.animSkill];
        if (gBattleWork.seqOperands[0] == seq[gBattleWork.seqOffset]) {
            battle_seq_advance();
            done = 1;
        } else {
            battle_seq_advance();
        }
    }
}

// Opcode 0x03: jumps to label operand[seqCondition], the condition set by the test_* commands.
void battle_seq_cmd_branch(void) {
    const s16 *seq;
    vu8 done = 0;

    battle_seq_load_operands();
    battle_seq_advance();
    while (!done) {
        seq = gBattleSeqScripts[gBattleWork.animSkill];
        if (gBattleWork.seqOperands[gBattleWork.seqCondition] == seq[gBattleWork.seqOffset]) {
            battle_seq_advance();
            done = 1;
        } else {
            battle_seq_advance();
        }
    }
}

// Opcode 0x04: condition = the attack missed (hitResult == 1).
void battle_seq_cmd_test_missed(void) {
    if (gBattleWork.hitResult == 1)
        gBattleWork.seqCondition = 1;
    else
        gBattleWork.seqCondition = 0;
    battle_seq_advance();
}

// Opcode 0x05: condition = the target has a reaction ready (reactionFlags bit 0).
void battle_seq_cmd_test_reaction(void) {
    if (gBattleWork.reactionFlags & 1)
        gBattleWork.seqCondition = 1;
    else
        gBattleWork.seqCondition = gBattleWork.reactionFlags & 1;
    battle_seq_advance();
}

// Opcode 0x06: condition = the attack was nullified (blockResult == 2).
void battle_seq_cmd_test_nullified(void) {
    if (gBattleWork.blockResult == 2)
        gBattleWork.seqCondition = 1;
    else
        gBattleWork.seqCondition = 0;
    battle_seq_advance();
}

// Opcode 0x07: condition = the attack was absorbed (blockResult == 4).
void battle_seq_cmd_test_absorbed(void) {
    if (gBattleWork.blockResult == 4)
        gBattleWork.seqCondition = 1;
    else
        gBattleWork.seqCondition = 0;
    battle_seq_advance();
}

// Opcode 0x08: the actor plays a pose (operands: delay, pose per part for left, for right).
void battle_seq_cmd_actor_pose(void) {
    battle_seq_load_operands();
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[1].work[SEQ_POSE_QUEUED] = 1;
        if (gBattleWork.reactionFlags & 2)
            gSpriteEntries[1].work[SEQ_POSE_ID] = gBattleWork.seqOperands[gBattleWork.swapPart + 1];
        else
            gSpriteEntries[1].work[SEQ_POSE_ID] = gBattleWork.seqOperands[gBattleWork.actorPart + 1];
        gSpriteEntries[1].work16[SEQ_POSE_DELAY] = gBattleWork.seqOperands[0];
        gSpriteEntries[1].work[SEQ_POSE_LOOP] = 0;
    } else {
        gSpriteEntries[2].work[SEQ_POSE_QUEUED] = 1;
        if (gBattleWork.reactionFlags & 2)
            gSpriteEntries[2].work[SEQ_POSE_ID] = gBattleWork.seqOperands[gBattleWork.swapPart + 4];
        else
            gSpriteEntries[2].work[SEQ_POSE_ID] = gBattleWork.seqOperands[gBattleWork.actorPart + 4];
        gSpriteEntries[2].work16[SEQ_POSE_DELAY] = gBattleWork.seqOperands[0];
        gSpriteEntries[2].work[SEQ_POSE_LOOP] = 0;
    }
    battle_seq_advance();
}

// Opcode 0x09: yields until the next frame without advancing.
void battle_seq_cmd_yield(void) {
    gSpriteEntries[0].work[SEQ_RUN_YIELD] = 1;
}

// Opcode 0x0A: the target plays a pose (same operands as actor_pose).
void battle_seq_cmd_target_pose(void) {
    battle_seq_load_operands();
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[2].work[SEQ_POSE_QUEUED] = 1;
        if (gBattleWork.reactionFlags & 2)
            gSpriteEntries[2].work[SEQ_POSE_ID] = gBattleWork.seqOperands[gBattleWork.swapPart + 4];
        else
            gSpriteEntries[2].work[SEQ_POSE_ID] = gBattleWork.seqOperands[gBattleWork.actorPart + 4];
        gSpriteEntries[2].work16[SEQ_POSE_DELAY] = gBattleWork.seqOperands[0];
        gSpriteEntries[2].work[SEQ_POSE_LOOP] = 0;
    } else {
        gSpriteEntries[1].work[SEQ_POSE_QUEUED] = 1;
        if (gBattleWork.reactionFlags & 2)
            gSpriteEntries[1].work[SEQ_POSE_ID] = gBattleWork.seqOperands[gBattleWork.swapPart + 1];
        else
            gSpriteEntries[1].work[SEQ_POSE_ID] = gBattleWork.seqOperands[gBattleWork.actorPart + 1];
        gSpriteEntries[1].work16[SEQ_POSE_DELAY] = gBattleWork.seqOperands[0];
        gSpriteEntries[1].work[SEQ_POSE_LOOP] = 0;
    }
    battle_seq_advance();
}

// Opcode 0x0B: the actor runs across the field at speed operand 0, the camera following.
void battle_seq_cmd_actor_dash(void) {
    u8 side_flag;

    battle_seq_load_operands();
    gSpriteEntries[3].work[SEQ_DASH_SPEED] = gBattleWork.seqOperands[0];
    side_flag = gBattleWork.actorSideFlags & 2;
    if (!side_flag) {
        gSpriteEntries[3].work[SEQ_DASH_SIDE] = side_flag;
        gSpriteEntries[3].work16[SEQ_DASH_X] = gBattleWork.closeupLeftX;
    } else {
        gSpriteEntries[3].work[SEQ_DASH_SIDE] = 1;
        gSpriteEntries[3].work16[SEQ_DASH_X] = gBattleWork.closeupRightX;
    }
    gSpriteEntries[3].work[SEQ_SPR_STATE] = 8;
    battle_seq_advance();
}

// Opcode 0x0C: waits for the actor (0), the target (1) or both to finish their pose.
void battle_seq_cmd_wait_pose(void) {
    battle_seq_load_operands();
    switch (gBattleWork.seqOperands[0]) {
    case 0:
        if (!(gBattleWork.actorSideFlags & 2)) {
            if (gBattleWork.closeupLeftPoseDone)
                battle_seq_advance();
        } else {
            if (gBattleWork.closeupRightPoseDone)
                battle_seq_advance();
        }
        break;
    case 1:
        if (gBattleWork.actorSideFlags & 2) {
            if (gBattleWork.closeupLeftPoseDone)
                battle_seq_advance();
        } else {
            if (gBattleWork.closeupRightPoseDone)
                battle_seq_advance();
        }
        break;
    default:
        if (gBattleWork.closeupLeftPoseDone && gBattleWork.closeupRightPoseDone)
            battle_seq_advance();
        break;
    }
    gSpriteEntries[0].work[SEQ_RUN_YIELD] = 1;
}

// Opcode 0x0D: a BG0 tile animation in the skill's palette (removed when it ends).
void battle_seq_cmd_bg_effect(void) {
    u32 skill;
    u32 half_width;

    battle_seq_load_operands();
    if (gBattleBots[gBattleWork.actor].chosenAction <= 3)
        skill = gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1];
    else
        skill = gBattleBots[gBattleWork.actor].medaforce[0] + 0x50;
    load_battle_entity_palette(skill, gBattleWork.seqOperands[4], 9);
    gSpriteEntries[4].work[SEQ_BG_WIDTH] = gBattleWork.seqOperands[0];
    gSpriteEntries[4].work[SEQ_BG_HEIGHT] = gBattleWork.seqOperands[1];
    gSpriteEntries[4].work[SEQ_BG_TILE_ANIM] = gBattleWork.seqOperands[6];
    gSpriteEntries[4].work16[SEQ_BG_DELAY] = gBattleWork.seqOperands[5];
    gSpriteEntries[4].work[SEQ_SPR_STATE] = 0x10;
    tile_anim_init(gBattleSeqTileAnims[gSpriteEntries[4].work[SEQ_BG_TILE_ANIM]], 0, 0);
    gSpriteEntries[4].y = gBattleWork.seqOperands[3];
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[4].x = gBattleWork.seqOperands[2];
        gSpriteEntries[4].work[SEQ_BG_TILEMAP] = gBattleWork.seqOperands[7];
    } else {
        half_width = gSpriteEntries[4].work[SEQ_BG_WIDTH] >> 1;
        gSpriteEntries[4].x = 0x1E - half_width - (gBattleWork.seqOperands[2] + half_width);
        gSpriteEntries[4].work[SEQ_BG_TILEMAP] = gBattleWork.seqOperands[7] + 2;
    }
    gSpriteEntries[4].work[SEQ_BG_NO_DRAW] = 0;
    battle_seq_advance();
}

// Opcode 0x0E: waits operand 0 frames.
void battle_seq_cmd_wait_frames(void) {
    battle_seq_load_operands();
    if (gSpriteEntries[0].work16[SEQ_RUN_WAIT] != gBattleWork.seqOperands[0]) {
        gSpriteEntries[0].work16[SEQ_RUN_WAIT]++;
    } else {
        gSpriteEntries[0].work16[SEQ_RUN_WAIT] = 0;
        battle_seq_advance();
    }
    gSpriteEntries[0].work[SEQ_RUN_YIELD] = 1;
}

// Opcode 0x0F: plays a sound effect a number of times (slot 5 + operand 0).
void battle_seq_cmd_sound(void) {
    battle_seq_load_operands();
    gSpriteEntries[gBattleWork.seqOperands[0] + 5].work16[SEQ_SOUND_DELAY] = gBattleWork.seqOperands[1];
    gSpriteEntries[gBattleWork.seqOperands[0] + 5].work[SEQ_SOUND_ID] = gBattleWork.seqOperands[2];
    gSpriteEntries[gBattleWork.seqOperands[0] + 5].work[SEQ_SOUND_WAIT] = 0;
    gSpriteEntries[gBattleWork.seqOperands[0] + 5].work[SEQ_SOUND_INTERVAL] = gBattleWork.seqOperands[3];
    gSpriteEntries[gBattleWork.seqOperands[0] + 5].work[SEQ_SOUND_COUNT] = gBattleWork.seqOperands[4];
    gSpriteEntries[gBattleWork.seqOperands[0] + 5].work[SEQ_SPR_STATE] = 0x18;
    battle_seq_advance();
}

// Opcode 0x10: like sound, the effect picked by the actor's legs type. guess: footsteps.
void battle_seq_cmd_leg_sound(void) {
    u32 i;
    const u8 *set;

    battle_seq_load_operands();
    gSpriteEntries[gBattleWork.seqOperands[0] + 5].work16[SEQ_SOUND_DELAY] = gBattleWork.seqOperands[1];
    gSpriteEntries[gBattleWork.seqOperands[0] + 5].work[SEQ_SOUND_WAIT] = 0;
    gSpriteEntries[gBattleWork.seqOperands[0] + 5].work[SEQ_SOUND_INTERVAL] = gBattleWork.seqOperands[3];
    gSpriteEntries[gBattleWork.seqOperands[0] + 5].work[SEQ_SOUND_COUNT] = gBattleWork.seqOperands[4];
    gSpriteEntries[gBattleWork.seqOperands[0] + 5].work[SEQ_SPR_STATE] = 0x18;
    if (gBattleWork.reactionFlags & 2)
        get_bot_part_effective_values(gBattleWork.swapBot, gBattleWork.partIds);
    else
        get_bot_part_effective_values(gBattleWork.actor, gBattleWork.partIds);
    if (gBattleWork.partIds[3] > 0x77)
        i = 3;
    else if (gBattleWork.reactionFlags & 2)
        i = gBattleBots[gBattleWork.swapBot].parts[3].data[1] - 0x64;
    else
        i = gBattleBots[gBattleWork.actor].parts[3].data[1] - 0x64;
    set = gBattleSeqLegSoundSets[gBattleWork.seqOperands[2]];
    gSpriteEntries[gBattleWork.seqOperands[0] + 5].work[SEQ_SOUND_ID] = set[i];
    battle_seq_advance();
}

// Opcode 0x11: moves the actor for some frames (speed, direction, frames).
void battle_seq_cmd_actor_move(void) {
    u8 side_flag;

    battle_seq_load_operands();
    gSpriteEntries[3].work[SPR_MOTION_TABLE] = gBattleWork.seqOperands[0];
    gSpriteEntries[3].work[SEQ_MOVE_FRAMES] = gBattleWork.seqOperands[2];
    side_flag = gBattleWork.actorSideFlags & 2;
    if (!side_flag) {
        gSpriteEntries[3].work[SEQ_MOVE_SIDE] = side_flag;
        gSpriteEntries[3].work[SPR_MOTION_ROW] = gBattleWork.seqOperands[1];
        gSpriteEntries[3].x = gBattleWork.closeupLeftX;
        gSpriteEntries[3].y = gBattleWork.closeupLeftY;
    } else {
        gSpriteEntries[3].work[SEQ_MOVE_SIDE] = 1;
        gSpriteEntries[3].work[SPR_MOTION_ROW] = (0x20 - (u8)gBattleWork.seqOperands[1]) & 0x1F;
        gSpriteEntries[3].x = gBattleWork.closeupRightX;
        gSpriteEntries[3].y = gBattleWork.closeupRightY;
    }
    gSpriteEntries[3].work[SEQ_SPR_STATE] = 9;
    battle_seq_advance();
}

// Opcode 0x12: condition = target hitFlags bit 5 (guess: evaded onto its strongest part).
void battle_seq_cmd_test_evaded(void) {
    u8 evaded = gBattleBots[gBattleWork.target].hitFlags & 0x20;
    if (evaded)
        gBattleWork.seqCondition = 1;
    else
        gBattleWork.seqCondition = evaded;
    battle_seq_advance();
}

// Opcode 0x13: bg_effect with the fixed palette 0x3C.
void battle_seq_cmd_bg_effect_fixed(void) {
    u32 half_width;

    battle_seq_load_operands();
    load_battle_entity_palette(0x3C, gBattleWork.seqOperands[4], 9);
    gSpriteEntries[4].work[SEQ_BG_WIDTH] = gBattleWork.seqOperands[0];
    gSpriteEntries[4].work[SEQ_BG_HEIGHT] = gBattleWork.seqOperands[1];
    gSpriteEntries[4].work[SEQ_BG_TILE_ANIM] = gBattleWork.seqOperands[6];
    gSpriteEntries[4].work16[SEQ_BG_DELAY] = gBattleWork.seqOperands[5];
    gSpriteEntries[4].work[SEQ_SPR_STATE] = 0x10;
    tile_anim_init(gBattleSeqTileAnims[gSpriteEntries[4].work[SEQ_BG_TILE_ANIM]], 0, 0);
    gSpriteEntries[4].y = gBattleWork.seqOperands[3];
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[4].x = gBattleWork.seqOperands[2];
        gSpriteEntries[4].work[SEQ_BG_TILEMAP] = gBattleWork.seqOperands[7];
    } else {
        half_width = gSpriteEntries[4].work[SEQ_BG_WIDTH] >> 1;
        gSpriteEntries[4].x = 0x1E - half_width - (gBattleWork.seqOperands[2] + half_width);
        gSpriteEntries[4].work[SEQ_BG_TILEMAP] = gBattleWork.seqOperands[7] + 2;
    }
    gSpriteEntries[4].work[SEQ_BG_NO_DRAW] = 0;
    battle_seq_advance();
}

// Opcode 0x14: puts the actor back at its home position, standing (pose 0x29).
void battle_seq_cmd_actor_home(void) {
    if (!(gBattleWork.actorSideFlags & 2)) {
        gBattleWork.closeupLeftX = 0x12C;
        gBattleWork.closeupLeftY = 0x50;
        get_active_bot_part_index_and_load_values(0);
        draw_medabot_sprite(0, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                            gBattleWork.partIds[3], (s16)gBattleWork.closeupLeftX, (s16)gBattleWork.closeupLeftY,
                            gBattleWork.battlefieldParams[3] + 2, 4, 0, 2, 0, gBattleWork.closeupPoseBase[0]);
        draw_medabot_sprite(0, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                            gBattleWork.partIds[3], (s16)gBattleWork.closeupLeftX, (s16)gBattleWork.closeupLeftY,
                            gBattleWork.battlefieldParams[3] + 2, 4, 0, 1, 0, gBattleWork.closeupPoseBase[0]);
        gBattleWork.closeupLeftPose = 0x29;
        medabot_pose_anim_step(0, 0x29, gBattleWork.partIds[3]);
    } else {
        gBattleWork.closeupRightX = 0x1C4;
        gBattleWork.closeupRightY = 0x50;
        get_active_bot_part_index_and_load_values(1);
        draw_medabot_sprite(1, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                            gBattleWork.partIds[3], (s16)gBattleWork.closeupRightX, (s16)gBattleWork.closeupRightY,
                            gBattleWork.battlefieldParams[3] + 2, 8, 1, 2, 1, gBattleWork.closeupPoseBase[1]);
        draw_medabot_sprite(1, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                            gBattleWork.partIds[3], (s16)gBattleWork.closeupRightX, (s16)gBattleWork.closeupRightY,
                            gBattleWork.battlefieldParams[3] + 2, 8, 1, 1, 1, gBattleWork.closeupPoseBase[1]);
        gBattleWork.closeupRightPose = 0x29;
        medabot_pose_anim_step(1, 0x29, gBattleWork.partIds[3]);
    }
    battle_seq_advance();
}

// Opcode 0x15: a moving camera point (slot 0x1E): BG2/BG3 and both Medabots scroll to follow it.
void battle_seq_cmd_camera_track(void) {
    battle_seq_load_operands();
    clear_battle_sprite_slot(0x1E, 1);
    gSpriteEntries[0x1E].work[SEQ_CAMERA_DELAY] = gBattleWork.seqOperands[0];
    gSpriteEntries[0x1E].y = gBattleWork.seqOperands[2];
    gSpriteEntries[0x1E].work[SPR_MOTION_TABLE] = gBattleWork.seqOperands[4];
    gSpriteEntries[0x1E].work[SEQ_SPR_STATE] = 10;
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[0x1E].x = gBattleWork.seqOperands[1];
        gSpriteEntries[0x1E].work[SPR_MOTION_ROW] = gBattleWork.seqOperands[3];
    } else {
        gSpriteEntries[0x1E].x = 0xF0 - gBattleWork.seqOperands[1];
        gSpriteEntries[0x1E].work[SPR_MOTION_ROW] = (0x20 - (u8)gBattleWork.seqOperands[3]) & 0x1F;
    }
    gSpriteEntries[0x1E].work16[SEQ_CAMERA_X] = gSpriteEntries[0x1E].x;
    battle_seq_advance();
}

// Opcode 0x16: waits until the camera point has stopped.
void battle_seq_cmd_wait_camera(void) {
    if (!gSpriteEntries[0x1E].work[SEQ_SPR_STATE])
        battle_seq_advance();
    gSpriteEntries[0].work[SEQ_RUN_YIELD] = 1;
}

// Opcode 0x17: loads effect tiles gBattleSeqEffectGfx[operand 0] to OBJ VRAM and OBJ palette 14.
void battle_seq_cmd_load_effect_gfx(void) {
    battle_seq_load_operands();
    lz_decompress_dispatch(gBattleSeqEffectGfx[gBattleWork.seqOperands[0] * 2], (void *)OBJ_VRAM0);
    CpuFastSet(gBattleSeqEffectGfx[gBattleWork.seqOperands[0] * 2 + 1], (void *)0x050003C0, 8);
    battle_seq_advance();
}

// Opcode 0x18: spawns a moving effect sprite in the first free slot 0xA-0x12.
void battle_seq_cmd_spawn_effect(void) {
    u32 i;
    u32 slot;

    battle_seq_load_operands();
    for (i = 0; i <= 8; i++) {
        if (gSpriteEntries[i + 10].flags == 0) {
            slot = i + 10;
            break;
        }
    }
    clear_battle_sprite_slot(slot, 1);
    gSpriteEntries[slot].flags =
        SPRITE_PRIORITY(gBattleWork.seqOperands[6]) | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[slot].frame_table = 0;
    gSpriteEntries[slot].palette = 0xE;
    gSpriteEntries[slot].order = 0x80;
    gSpriteEntries[slot].work[SEQ_SPR_ANIM] = gBattleWork.seqOperands[7];
    battle_sprite_anim_init(gBattleSpriteAnimScripts[gSpriteEntries[slot].work[SEQ_SPR_ANIM]], slot);
    gSpriteEntries[slot].work[SEQ_EFFECT_MOVE_DELAY] = gBattleWork.seqOperands[0];
    gSpriteEntries[slot].y = gBattleWork.seqOperands[2];
    gSpriteEntries[slot].work[SPR_MOTION_TABLE] = gBattleWork.seqOperands[4];
    gSpriteEntries[slot].work[SEQ_EFFECT_SHOW_DELAY] = gBattleWork.seqOperands[5];
    gSpriteEntries[slot].work[SEQ_SPR_STATE] = 0xB;
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[slot].x = gBattleWork.seqOperands[1];
        gSpriteEntries[slot].work[SPR_MOTION_ROW] = gBattleWork.seqOperands[3];
    } else {
        gSpriteEntries[slot].flags |= SPRITE_FLAG_HFLIP;
        gSpriteEntries[slot].x = 0xF0 - gBattleWork.seqOperands[1];
        gSpriteEntries[slot].work[SPR_MOTION_ROW] = (0x20 - (u8)gBattleWork.seqOperands[3]) & 0x1F;
    }
    battle_seq_advance();
}

// Opcode 0x19: waits until sprite operand 1 has moved past x = operand 0 (mirrored).
void battle_seq_cmd_wait_sprite_x(void) {
    battle_seq_load_operands();
    if (!(gBattleWork.actorSideFlags & 2)) {
        if (gSpriteEntries[gBattleWork.seqOperands[1]].x >= gBattleWork.seqOperands[0])
            battle_seq_advance();
    } else {
        if (gSpriteEntries[gBattleWork.seqOperands[1]].x <= 0xF0 - gBattleWork.seqOperands[0])
            battle_seq_advance();
    }
    gSpriteEntries[0].work[SEQ_RUN_YIELD] = 1;
}

// Opcode 0x1A: clears operand 1 sprite slots from operand 0.
void battle_seq_cmd_clear_sprites(void) {
    battle_seq_load_operands();
    clear_battle_sprite_slot(gBattleWork.seqOperands[0], gBattleWork.seqOperands[1]);
    battle_seq_advance();
}

// Opcode 0x1B: after a delay, plays a sprite animation once on a slot.
void battle_seq_cmd_play_anim(void) {
    s32 n;

    battle_seq_load_operands();
    n = gBattleWork.seqOperands[2];
    gSpriteEntries[n].palette = gBattleWork.seqOperands[4];
    gSpriteEntries[n].work[SEQ_SPR_ANIM] = gBattleWork.seqOperands[1];
    gSpriteEntries[n].work[SEQ_PLAY_DELAY] = gBattleWork.seqOperands[0];
    gSpriteEntries[n].work[SEQ_SPR_STATE] = 0x20;
    gSpriteEntries[n].work[SEQ_PLAY_SLOT] = gBattleWork.seqOperands[3];
    battle_seq_advance();
}

// Opcode 0x1C: camera_track that also scrolls BG0 and BG1.
void battle_seq_cmd_camera_track_all(void) {
    battle_seq_load_operands();
    clear_battle_sprite_slot(0x1E, 1);
    gSpriteEntries[0x1E].work[SEQ_CAMERA_DELAY] = gBattleWork.seqOperands[0];
    gSpriteEntries[0x1E].y = gBattleWork.seqOperands[2];
    gSpriteEntries[0x1E].work[SPR_MOTION_TABLE] = gBattleWork.seqOperands[4];
    gSpriteEntries[0x1E].work[SEQ_SPR_STATE] = 12;
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[0x1E].x = gBattleWork.seqOperands[1];
        gSpriteEntries[0x1E].work[SPR_MOTION_ROW] = gBattleWork.seqOperands[3];
    } else {
        gSpriteEntries[0x1E].x = 0xF0 - gBattleWork.seqOperands[1];
        gSpriteEntries[0x1E].work[SPR_MOTION_ROW] = (0x20 - (u8)gBattleWork.seqOperands[3]) & 0x1F;
    }
    gSpriteEntries[0x1E].work16[SEQ_CAMERA_X] = gSpriteEntries[0x1E].x;
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
    u32 half_width;

    battle_seq_load_operands();
    clear_battle_sprite_slot(0x23, 1);
    if (gBattleBots[gBattleWork.actor].chosenAction <= 3)
        skill = gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1];
    else
        skill = gBattleBots[gBattleWork.actor].medaforce[0] + 0x50;
    load_battle_entity_palette(skill, gBattleWork.seqOperands[4], 9);
    gSpriteEntries[0x23].work[SEQ_BG_WIDTH] = gBattleWork.seqOperands[0];
    gSpriteEntries[0x23].work[SEQ_BG_HEIGHT] = gBattleWork.seqOperands[1];
    gSpriteEntries[0x23].work[SEQ_BG_TILE_ANIM] = gBattleWork.seqOperands[6];
    gSpriteEntries[0x23].work16[SEQ_BG_DELAY] = gBattleWork.seqOperands[5];
    gSpriteEntries[0x23].work[SEQ_SPR_STATE] = 0x11;
    tile_anim_init(gBattleSeqTileAnims[gSpriteEntries[0x23].work[SEQ_BG_TILE_ANIM]], 1, 1);
    gSpriteEntries[0x23].y = gBattleWork.seqOperands[3];
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[0x23].x = gBattleWork.seqOperands[2];
        gSpriteEntries[0x23].work[SEQ_BG_TILEMAP] = gBattleWork.seqOperands[7];
    } else {
        half_width = gSpriteEntries[0x23].work[SEQ_BG_WIDTH] >> 1;
        gSpriteEntries[0x23].x = (s16)(0x1E - half_width - (gBattleWork.seqOperands[2] + half_width)) - 1;
        gSpriteEntries[0x23].work[SEQ_BG_TILEMAP] = gBattleWork.seqOperands[7] + 2;
    }
    gSpriteEntries[0x23].work[SEQ_BG_SWEEP_COLUMN] = 0;
    gSpriteEntries[0x23].work[SEQ_BG_SWEEP_FRAME] = 0;
    battle_seq_advance();
}

// Opcode 0x1F: bg_effect at row 4 with a separate x for each side (cleared when it ends).
void battle_seq_cmd_bg_effect_at(void) {
    u32 skill;

    battle_seq_load_operands();
    if (gBattleBots[gBattleWork.actor].chosenAction <= 3)
        skill = gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1];
    else
        skill = gBattleBots[gBattleWork.actor].medaforce[0] + 0x50;
    load_battle_entity_palette(skill, gBattleWork.seqOperands[4], 9);
    gSpriteEntries[4].work[SEQ_BG_WIDTH] = gBattleWork.seqOperands[0];
    gSpriteEntries[4].work[SEQ_BG_HEIGHT] = gBattleWork.seqOperands[1];
    gSpriteEntries[4].work[SEQ_BG_TILE_ANIM] = gBattleWork.seqOperands[6];
    gSpriteEntries[4].work16[SEQ_BG_DELAY] = gBattleWork.seqOperands[5];
    gSpriteEntries[4].work[SEQ_SPR_STATE] = 0x12;
    tile_anim_init(gBattleSeqTileAnims[gSpriteEntries[4].work[SEQ_BG_TILE_ANIM]], 0, 0);
    gSpriteEntries[4].y = 4;
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[4].x = gBattleWork.seqOperands[2];
        gSpriteEntries[4].work[SEQ_BG_TILEMAP] = gBattleWork.seqOperands[7];
    } else {
        gSpriteEntries[4].x = gBattleWork.seqOperands[3];
        gSpriteEntries[4].work[SEQ_BG_TILEMAP] = gBattleWork.seqOperands[7] + 2;
    }
    gSpriteEntries[4].work[SEQ_BG_NO_DRAW] = 0;
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
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[1].work[SEQ_POSE_QUEUED] = 1;
        if (gBattleWork.reactionFlags & 2)
            gSpriteEntries[1].work[SEQ_POSE_ID] = gBattleWork.seqOperands[gBattleWork.swapPart + 1];
        else
            gSpriteEntries[1].work[SEQ_POSE_ID] = gBattleWork.seqOperands[gBattleWork.actorPart + 1];
        gSpriteEntries[1].work16[SEQ_POSE_DELAY] = gBattleWork.seqOperands[0];
        gSpriteEntries[1].work[SEQ_POSE_LOOP] = 1;
    } else {
        gSpriteEntries[2].work[SEQ_POSE_QUEUED] = 1;
        if (gBattleWork.reactionFlags & 2)
            gSpriteEntries[2].work[SEQ_POSE_ID] = gBattleWork.seqOperands[gBattleWork.swapPart + 4];
        else
            gSpriteEntries[2].work[SEQ_POSE_ID] = gBattleWork.seqOperands[gBattleWork.actorPart + 4];
        gSpriteEntries[2].work16[SEQ_POSE_DELAY] = gBattleWork.seqOperands[0];
        gSpriteEntries[2].work[SEQ_POSE_LOOP] = 1;
    }
    battle_seq_advance();
}

// Opcode 0x22: target_pose, repeated until changed.
void battle_seq_cmd_target_pose_loop(void) {
    battle_seq_load_operands();
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[2].work[SEQ_POSE_QUEUED] = 1;
        if (gBattleWork.reactionFlags & 2)
            gSpriteEntries[2].work[SEQ_POSE_ID] = gBattleWork.seqOperands[gBattleWork.swapPart + 4];
        else
            gSpriteEntries[2].work[SEQ_POSE_ID] = gBattleWork.seqOperands[gBattleWork.actorPart + 4];
        gSpriteEntries[2].work16[SEQ_POSE_DELAY] = gBattleWork.seqOperands[0];
        gSpriteEntries[2].work[SEQ_POSE_LOOP] = 1;
    } else {
        gSpriteEntries[1].work[SEQ_POSE_QUEUED] = 1;
        if (gBattleWork.reactionFlags & 2)
            gSpriteEntries[1].work[SEQ_POSE_ID] = gBattleWork.seqOperands[gBattleWork.swapPart + 1];
        else
            gSpriteEntries[1].work[SEQ_POSE_ID] = gBattleWork.seqOperands[gBattleWork.actorPart + 1];
        gSpriteEntries[1].work16[SEQ_POSE_DELAY] = gBattleWork.seqOperands[0];
        gSpriteEntries[1].work[SEQ_POSE_LOOP] = 1;
    }
    battle_seq_advance();
}

// Opcode 0x23: stops the bg_sweep from growing.
void battle_seq_cmd_bg_sweep_stop(void) {
    gSpriteEntries[0x23].work[SEQ_BG_SWEEP_STOP] = 1;
    battle_seq_advance();
}

// Opcode 0x24: a trail spawner (slot 0xC / 0xD) dropping puffs behind a sprite.
void battle_seq_cmd_trail(void) {
    u32 i;
    u32 slot;

    battle_seq_load_operands();
    for (i = 0; i < 2; i++) {
        if (gSpriteEntries[i + 0xC].work[SEQ_SPR_STATE] == 0) {
            slot = i + 0xC;
            break;
        }
    }
    clear_battle_sprite_slot(slot, 1);
    gSpriteEntries[slot].work[SEQ_TRAIL_DELAY] = gBattleWork.seqOperands[0];
    gSpriteEntries[slot].work[SEQ_TRAIL_SOURCE] = gBattleWork.seqOperands[1];
    gSpriteEntries[slot].work16[SEQ_TRAIL_OFFSET_X] = gBattleWork.seqOperands[2];
    gSpriteEntries[slot].work16[SEQ_TRAIL_OFFSET_Y] = gBattleWork.seqOperands[3];
    gSpriteEntries[slot].work[SEQ_TRAIL_INTERVAL] = gBattleWork.seqOperands[4];
    gSpriteEntries[slot].work[SEQ_SPR_ANIM] = gBattleWork.seqOperands[5];
    gSpriteEntries[slot].work[SEQ_TRAIL_PALETTE] = gBattleWork.seqOperands[6];
    gSpriteEntries[slot].work[SEQ_TRAIL_COUNTER] = 0;
    gSpriteEntries[slot].work[SEQ_SPR_STATE] = 0x22;
    battle_seq_advance();
}

// Opcode 0x25: sets sprite operand 0 direction (mirrored) and speed.
void battle_seq_cmd_sprite_motion(void) {
    battle_seq_load_operands();
    if (!(gBattleWork.actorSideFlags & 2))
        gSpriteEntries[gBattleWork.seqOperands[0]].work[SPR_MOTION_ROW] = gBattleWork.seqOperands[1];
    else
        gSpriteEntries[gBattleWork.seqOperands[0]].work[SPR_MOTION_ROW] =
            (0x20 - (u8)gBattleWork.seqOperands[1]) & 0x1F;
    gSpriteEntries[gBattleWork.seqOperands[0]].work[SPR_MOTION_TABLE] = gBattleWork.seqOperands[2];
    battle_seq_advance();
}

// Opcode 0x26: toggles the horizontal / vertical flip of a sprite.
void battle_seq_cmd_sprite_flip(void) {
    battle_seq_load_operands();
    if (gBattleWork.seqOperands[1] != 0)
        gSpriteEntries[gBattleWork.seqOperands[0]].flags ^= SPRITE_FLAG_HFLIP;
    if (gBattleWork.seqOperands[2] != 0)
        gSpriteEntries[gBattleWork.seqOperands[0]].flags ^= SPRITE_FLAG_VFLIP;
    battle_seq_advance();
}

// Opcode 0x27: fades all palettes towards a colour (0) or back (1).
void battle_seq_cmd_palette_fade(void) {
    battle_seq_load_operands();
    if (gBattleWork.seqOperands[0] == 0) {
        palette_backup_from_hardware();
        gSpriteEntries[0x27].work[SEQ_FADE_LEVEL] = 0;
        gSpriteEntries[0x27].work[SEQ_SPR_STATE] = 0x28;
    } else {
        gSpriteEntries[0x27].work[SEQ_SPR_STATE] = 0x29;
    }
    gSpriteEntries[0x27].work[SEQ_FADE_DELAY] = gBattleWork.seqOperands[1];
    gSpriteEntries[0x27].work[SEQ_FADE_RED] = gBattleWork.seqOperands[2];
    gSpriteEntries[0x27].work[SEQ_FADE_GREEN] = gBattleWork.seqOperands[3];
    gSpriteEntries[0x27].work[SEQ_FADE_BLUE] = gBattleWork.seqOperands[4];
    battle_seq_advance();
}

// Opcode 0x28: copies OBJ palettes 8-11 (actor on the left) or 4-7 to the backup buffer.
void battle_seq_cmd_backup_bot_palettes(void) {
    if (!(gBattleWork.actorSideFlags & 2)) {
        CpuFastSet((void *)0x05000300, (void *)OBJ_PAL_BACKUP_ADDR(8), 8);
        CpuFastSet((void *)0x05000320, (void *)OBJ_PAL_BACKUP_ADDR(9), 8);
        CpuFastSet((void *)0x05000340, (void *)OBJ_PAL_BACKUP_ADDR(10), 8);
        CpuFastSet((void *)0x05000360, (void *)OBJ_PAL_BACKUP_ADDR(11), 8);
    } else {
        CpuFastSet((void *)0x05000280, (void *)OBJ_PAL_BACKUP_ADDR(4), 8);
        CpuFastSet((void *)0x050002A0, (void *)OBJ_PAL_BACKUP_ADDR(5), 8);
        CpuFastSet((void *)0x050002C0, (void *)OBJ_PAL_BACKUP_ADDR(6), 8);
        CpuFastSet((void *)0x050002E0, (void *)OBJ_PAL_BACKUP_ADDR(7), 8);
    }
    battle_seq_advance();
}

// Opcode 0x2A: copies one BG (0) or OBJ (1) palette to the backup buffer.
void battle_seq_cmd_backup_palette(void) {
    battle_seq_load_operands();
    if (gBattleWork.seqOperands[0] == 0)
        CpuFastSet((void *)(gBattleWork.seqOperands[1] * 32 + 0x05000000),
                   (void *)(gBattleWork.seqOperands[1] * 32 + BG_PAL_BACKUP_ADDR(0)), 8);
    else
        CpuFastSet((void *)(gBattleWork.seqOperands[1] * 32 + 0x05000200),
                   (void *)(gBattleWork.seqOperands[1] * 32 + OBJ_PAL_BACKUP_ADDR(0)), 8);
    battle_seq_advance();
}

// Opcode 0x29: spawn_effect, bobbing up and down as it moves.
void battle_seq_cmd_spawn_effect_wave(void) {
    u32 i;
    u32 slot;

    battle_seq_load_operands();
    for (i = 0; i < 9; i++) {
        if (gSpriteEntries[i + 0xA].flags == 0) {
            slot = i + 0xA;
            break;
        }
    }
    clear_battle_sprite_slot(slot, 1);
    gSpriteEntries[slot].flags =
        SPRITE_PRIORITY(gBattleWork.seqOperands[6]) | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[slot].frame_table = 0;
    gSpriteEntries[slot].palette = 0xE;
    gSpriteEntries[slot].order = 0x80;
    gSpriteEntries[slot].work[SEQ_SPR_ANIM] = gBattleWork.seqOperands[7];
    battle_sprite_anim_init(gBattleSpriteAnimScripts[gSpriteEntries[slot].work[SEQ_SPR_ANIM]], slot);
    gSpriteEntries[slot].work[SEQ_EFFECT_MOVE_DELAY] = gBattleWork.seqOperands[0];
    gSpriteEntries[slot].y = gBattleWork.seqOperands[2];
    gSpriteEntries[slot].work[SPR_MOTION_TABLE] = gBattleWork.seqOperands[4];
    gSpriteEntries[slot].work[SEQ_EFFECT_SHOW_DELAY] = gBattleWork.seqOperands[5];
    gSpriteEntries[slot].work[SEQ_SPR_STATE] = 0xD;
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[slot].x = gBattleWork.seqOperands[1];
        gSpriteEntries[slot].work[SPR_MOTION_ROW] = gBattleWork.seqOperands[3];
    } else {
        gSpriteEntries[slot].flags |= SPRITE_FLAG_HFLIP;
        gSpriteEntries[slot].x = 0xF0 - gBattleWork.seqOperands[1];
        gSpriteEntries[slot].work[SPR_MOTION_ROW] = (0x20 - (u8)gBattleWork.seqOperands[3]) & 0x1F;
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
    if (gBattleBots[gBattleWork.actor].chosenAction <= 3)
        skill = gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1];
    else
        skill = gBattleBots[gBattleWork.actor].medaforce[0] + 0x50;
    load_battle_entity_palette(skill, gBattleWork.seqOperands[4], 9);
    gSpriteEntries[4].work[SEQ_BG_WIDTH] = gBattleWork.seqOperands[0];
    gSpriteEntries[4].work[SEQ_BG_HEIGHT] = gBattleWork.seqOperands[1];
    gSpriteEntries[4].work[SEQ_BG_TILE_ANIM] = gBattleWork.seqOperands[6];
    gSpriteEntries[4].work16[SEQ_BG_DELAY] = gBattleWork.seqOperands[5];
    gSpriteEntries[4].work[SEQ_SPR_STATE] = 0x13;
    tile_anim_init(gBattleSeqTileAnims[gSpriteEntries[4].work[SEQ_BG_TILE_ANIM]], 0, 0);
    gSpriteEntries[4].y = 4;
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[4].x = gBattleWork.seqOperands[2];
        gSpriteEntries[4].work[SEQ_BG_TILEMAP] = gBattleWork.seqOperands[7];
    } else {
        gSpriteEntries[4].x = gBattleWork.seqOperands[3];
        gSpriteEntries[4].work[SEQ_BG_TILEMAP] = (u8)gBattleWork.seqOperands[7] + 2;
    }
    gSpriteEntries[4].work[SEQ_BG_NO_DRAW] = 0;
    battle_seq_advance();
}

// Opcode 0x2D: a moving effect sprite (slot 0xA) with four sprites circling it.
void battle_seq_cmd_spawn_orbit(void) {
    u32 i;
    struct Coords16 pos;

    battle_seq_load_operands();
    gSpriteEntries[0xA].work[SEQ_EFFECT_MOVE_DELAY] = gBattleWork.seqOperands[0];
    gSpriteEntries[0xA].y = gBattleWork.seqOperands[2];
    gSpriteEntries[0xA].work[SPR_MOTION_TABLE] = gBattleWork.seqOperands[4];
    gSpriteEntries[0xA].work[SEQ_EFFECT_SHOW_DELAY] = gBattleWork.seqOperands[5];
    gSpriteEntries[0xA].work[SEQ_SPR_STATE] = 0x30;
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[0xA].x = gBattleWork.seqOperands[1];
        gSpriteEntries[0xA].work[SPR_MOTION_ROW] = gBattleWork.seqOperands[3];
    } else {
        gSpriteEntries[0xA].x = 0xF0 - gBattleWork.seqOperands[1];
        gSpriteEntries[0xA].work[SPR_MOTION_ROW] = (0x20 - (u8)gBattleWork.seqOperands[3]) & 0x1F;
    }
    for (i = 0; i < 4; i++) {
        gSpriteEntries[i + 0xB].flags =
            SPRITE_PRIORITY(gBattleWork.seqOperands[6]) | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[i + 0xB].frame_table = 0;
        gSpriteEntries[i + 0xB].palette = 0xE;
        gSpriteEntries[i + 0xB].order = 0x80;
        gSpriteEntries[i + 0xB].work[SEQ_SPR_ANIM] = gBattleWork.seqOperands[7];
        battle_sprite_anim_init(gBattleSpriteAnimScripts[gSpriteEntries[i + 0xB].work[SEQ_SPR_ANIM]], i + 0xB);
        gSpriteEntries[i + 0xB].work[SEQ_EFFECT_MOVE_DELAY] = gBattleWork.seqOperands[0];
        gSpriteEntries[i + 0xB].work[SEQ_EFFECT_SHOW_DELAY] = gBattleWork.seqOperands[5];
        gSpriteEntries[i + 0xB].work[SEQ_SPR_STATE] = 0x31;
        pos = calc_polar_to_screen_coords(i * 64, 0x10, gSpriteEntries[0xA].x, gSpriteEntries[0xA].y);
        gSpriteEntries[i + 0xB].x = pos.x;
        gSpriteEntries[i + 0xB].y = pos.y;
        gSpriteEntries[i + 0xB].work[SEQ_ORBIT_ANGLE] = i * 64 - 0x20;
    }
    battle_seq_advance();
}

// Opcode 0x2E: four effect sprites at the gBattleSeqEffectSetPos positions.
void battle_seq_cmd_spawn_effect_set(void) {
    u32 i;
    const struct Unk_083AF94C *tbl;
    struct BattleWork *work;
    u8 *side_flags;

    battle_seq_load_operands();
    i = 0;
    work = &gBattleWork;
    side_flags = &work->actorSideFlags;
    tbl = gBattleSeqEffectSetPos;
    do {
        gSpriteEntries[i + 0xA].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[i + 0xA].frame_table = 0;
        gSpriteEntries[i + 0xA].y = tbl->y;
        gSpriteEntries[i + 0xA].palette = 0xE;
        gSpriteEntries[i + 0xA].order = 0x80;
        gSpriteEntries[i + 0xA].work[SEQ_EFFECT_SHOW_DELAY] = work->seqOperands[0];
        gSpriteEntries[i + 0xA].work[SEQ_EFFECT_MOVE_DELAY] = work->seqOperands[0];
        gSpriteEntries[i + 0xA].work[SPR_MOTION_ROW] = work->seqOperands[1];
        gSpriteEntries[i + 0xA].work[SPR_MOTION_TABLE] = work->seqOperands[2];
        gSpriteEntries[i + 0xA].work[SEQ_SPR_STATE] = 0xB;
        gSpriteEntries[i + 0xA].work[SEQ_SPR_ANIM] = work->seqOperands[3];
        battle_sprite_anim_init(gBattleSpriteAnimScripts[gSpriteEntries[i + 0xA].work[SEQ_SPR_ANIM]], i + 0xA);
        if (!(*side_flags & 2))
            gSpriteEntries[i + 0xA].x = tbl->x;
        else
            gSpriteEntries[i + 0xA].x = (0xF6 - tbl->x) & 0x1FF;
        tbl++;
        i++;
    } while (i < 4);
    battle_seq_advance();
}

// Opcode 0x2F: decompresses gBattleSeqEwramGfx[operand 0] to EWRAM, palette to OBJ palette 14.
void battle_seq_cmd_load_effect_gfx_ewram(void) {
    battle_seq_load_operands();
    lz_decompress(gBattleSeqEwramGfx[gBattleWork.seqOperands[0] * 2], (void *)0x02000000);
    CpuFastSet(gBattleSeqEwramGfx[gBattleWork.seqOperands[0] * 2 + 1], (void *)0x050003C0, 8);
    battle_seq_advance();
}

// Opcode 0x30: spawn_effect that also runs a tile animation.
void battle_seq_cmd_spawn_effect_tiles(void) {
    u32 i;
    u32 slot;

    battle_seq_load_operands();
    for (i = 0; i < 9; i++) {
        if (gSpriteEntries[i + 0xA].flags == 0) {
            slot = i + 0xA;
            break;
        }
    }
    clear_battle_sprite_slot(slot, 1);
    gSpriteEntries[slot].flags =
        SPRITE_PRIORITY(gBattleWork.seqOperands[6]) | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[slot].frame_table = 0;
    gSpriteEntries[slot].palette = 0xE;
    gSpriteEntries[slot].order = 0x80;
    gSpriteEntries[slot].work[SEQ_SPR_ANIM] = gBattleWork.seqOperands[7];
    battle_sprite_anim_init(gBattleSpriteAnimScripts[gSpriteEntries[slot].work[SEQ_SPR_ANIM]], slot);
    gSpriteEntries[slot].work[SEQ_EFFECT_MOVE_DELAY] = gBattleWork.seqOperands[0];
    gSpriteEntries[slot].y = gBattleWork.seqOperands[2];
    gSpriteEntries[slot].work[SPR_MOTION_TABLE] = gBattleWork.seqOperands[4];
    gSpriteEntries[slot].work[SEQ_EFFECT_SHOW_DELAY] = gBattleWork.seqOperands[5];
    gSpriteEntries[slot].work[SEQ_SPR_STATE] = 0xE;
    if (!(gBattleWork.actorSideFlags & 2)) {
        gSpriteEntries[slot].x = gBattleWork.seqOperands[1];
        gSpriteEntries[slot].work[SPR_MOTION_ROW] = gBattleWork.seqOperands[3];
    } else {
        gSpriteEntries[slot].flags |= SPRITE_FLAG_HFLIP;
        gSpriteEntries[slot].x = 0xF0 - gBattleWork.seqOperands[1];
        gSpriteEntries[slot].work[SPR_MOTION_ROW] = (0x20 - (u8)gBattleWork.seqOperands[3]) & 0x1F;
    }
    battle_seq_advance();
}

// Opcode 0x31: starts tile animation operand 0 for sprite operand 1.
void battle_seq_cmd_set_tile_anim(void) {
    battle_seq_load_operands();
    gSpriteEntries[gBattleWork.seqOperands[1]].work[SEQ_EFFECT_TILE_ANIM] = gBattleWork.seqOperands[0];
    tile_anim_init_dup(gBattleSeqTileAnims[gBattleWork.seqOperands[0]], 0, 0);
    battle_seq_advance();
}

// Opcode 0x32: decompresses the skill's graphics to EWRAM.
void battle_seq_cmd_load_skill_gfx(void) {
    if (gBattleBots[gBattleWork.actor].chosenAction <= 3)
        decompress_indexed_graphics_to_ewram(gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1]);
    else
        decompress_indexed_graphics_to_ewram(gBattleBots[gBattleWork.actor].medaforce[0] + 0x50);
    battle_seq_advance();
}

// Opcode 0x33: load_effect_gfx at OBJ tile operand 1.
void battle_seq_cmd_load_effect_gfx_at(void) {
    battle_seq_load_operands();
    lz_decompress_dispatch(gBattleSeqEffectGfx[gBattleWork.seqOperands[0] * 2],
                           (void *)(gBattleWork.seqOperands[1] * 32 + OBJ_VRAM0));
    CpuFastSet(gBattleSeqEffectGfx[gBattleWork.seqOperands[0] * 2 + 1], (void *)0x050003C0, 8);
    battle_seq_advance();
}

// Opcode 0x34: makes a sprite affine and shrinks or grows it.
void battle_seq_cmd_scale_sprite(void) {
    battle_seq_load_operands();
    gSpriteEntries[gBattleWork.seqOperands[0]].flags |= SPRITE_FLAG_AFFINE;
    gSpriteEntries[gBattleWork.seqOperands[0]].scale_x = gBattleWork.seqOperands[4];
    gSpriteEntries[gBattleWork.seqOperands[0]].scale_y = gBattleWork.seqOperands[5];
    gSpriteEntries[gBattleWork.seqOperands[0]].angle = 0;
    gSpriteEntries[gBattleWork.seqOperands[0]].work[SEQ_SCALE_STEP] = gBattleWork.seqOperands[3];
    gSpriteEntries[gBattleWork.seqOperands[0]].work[SEQ_SPR_ANIM] = gBattleWork.seqOperands[2];
    gSpriteEntries[gBattleWork.seqOperands[0]].work[SEQ_SCALE_GROW] = gBattleWork.seqOperands[1];
    gSpriteEntries[gBattleWork.seqOperands[0]].work[SEQ_SPR_STATE] = 0x34;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[gSpriteEntries[gBattleWork.seqOperands[0]].work[SEQ_SPR_ANIM]],
                            gBattleWork.seqOperands[0]);
    battle_seq_advance();
}

// Opcode 0x35: eight sprites in a ring around a sprite, spiralling.
void battle_seq_cmd_spawn_ring(void) {
    u32 i;
    struct Coords16 pos;

    battle_seq_load_operands();
    for (i = 0; i < 8; i++) {
        gSpriteEntries[i + 0xB].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                        SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[i + 0xB].frame_table = 0;
        pos = calc_polar_to_screen_coords(i * 32, gBattleWork.seqOperands[3],
                                          gSpriteEntries[gBattleWork.seqOperands[0]].x,
                                          gSpriteEntries[gBattleWork.seqOperands[0]].y);
        gSpriteEntries[i + 0xB].x = pos.x;
        gSpriteEntries[i + 0xB].y = pos.y;
        gSpriteEntries[i + 0xB].scale_x = 8;
        gSpriteEntries[i + 0xB].scale_y = 8;
        gSpriteEntries[i + 0xB].palette = 0xE;
        gSpriteEntries[i + 0xB].order = 0x80;
        gSpriteEntries[i + 0xB].work[SEQ_SPR_STATE] = 0x36;
        gSpriteEntries[i + 0xB].work[SEQ_RING_ANGLE] = i * 32;
        gSpriteEntries[i + 0xB].work[SEQ_RING_RADIUS] = gBattleWork.seqOperands[3];
        gSpriteEntries[i + 0xB].work[SEQ_RING_FRAME] = 0;
        gSpriteEntries[i + 0xB].work[SEQ_RING_EXPAND] = gBattleWork.seqOperands[1];
        gSpriteEntries[i + 0xB].work[SEQ_SPR_ANIM] = gBattleWork.seqOperands[2];
        battle_sprite_anim_init(gBattleSpriteAnimScripts[gSpriteEntries[i + 0xB].work[SEQ_SPR_ANIM]], i + 0xB);
    }
    battle_seq_advance();
}

// Opcode 0x36: shows the armor panel and drains the actor's armor values.
void battle_seq_cmd_armor_panel(void) {
    u8 mirrored;

    battle_seq_load_operands();
    lz_decompress_dispatch(gGaugeFillTiles, (void *)(BG_VRAM + 0x6400));
    lz_decompress_dispatch(gArmorPanelDecorTilesLz, (void *)(BG_VRAM + 0x6520));
    lz_decompress_dispatch(gMedaforceGaugeTiles, (void *)(BG_VRAM + 0x6600));
    lz_decompress_dispatch(gArmorPanelPartIconTilesLz, (void *)(BG_VRAM + 0x6800));
    CpuFastSet(gArmorPanelDecorPalette, (void *)0x05000140, 8);
    CpuFastSet(gArmorPanelGaugePalette, (void *)0x05000100, 8);
    CpuFastSet(gArmorPanelPartIconPalette, (void *)0x05000160, 8);
    mirrored = gBattleWork.actorSideFlags & 2;
    if (mirrored == 0)
        gSpriteEntries[9].work[SEQ_ARMOR_SIDE] = mirrored;
    else
        gSpriteEntries[9].work[SEQ_ARMOR_SIDE] = 1;
    gSpriteEntries[9].work[SEQ_ARMOR_REDRAW] = 1;
    gSpriteEntries[9].work[SEQ_ARMOR_DELAY] = gBattleWork.seqOperands[0];
    gSpriteEntries[9].work[SEQ_ARMOR_DRAIN_DELAY] = gBattleWork.seqOperands[1];
    gSpriteEntries[9].work[SEQ_SPR_STATE] = 0x38;
    battle_seq_advance();
}

// Opcode 0x37: waits until the armor panel is done.
void battle_seq_cmd_wait_armor_panel(void) {
    if (gSpriteEntries[9].work[SEQ_SPR_STATE] == 0)
        battle_seq_advance();
    gSpriteEntries[0].work[SEQ_RUN_YIELD] = 1;
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
    if (gBattleBots[gBattleWork.actor].chosenAction <= 3)
        skill = gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1];
    else
        skill = gBattleBots[gBattleWork.actor].medaforce[0] + 0x50;
    load_battle_entity_palette(skill, gBattleWork.seqOperands[4], 9);
    gSpriteEntries[4].work[SEQ_BG_WIDTH] = gBattleWork.seqOperands[0];
    gSpriteEntries[4].work[SEQ_BG_HEIGHT] = gBattleWork.seqOperands[1];
    gSpriteEntries[4].work[SEQ_BG_TILE_ANIM] = gBattleWork.seqOperands[6];
    gSpriteEntries[4].work16[SEQ_BG_DELAY] = gBattleWork.seqOperands[5];
    gSpriteEntries[4].work[SEQ_SPR_STATE] = 0x10;
    tile_anim_init(gBattleSeqTileAnims[gSpriteEntries[4].work[SEQ_BG_TILE_ANIM]], 0, 0);
    gSpriteEntries[4].y = gBattleWork.seqOperands[3];
    gSpriteEntries[4].work[SEQ_BG_TILEMAP] = gBattleWork.seqOperands[7];
    if (!(gBattleWork.actorSideFlags & 2))
        gSpriteEntries[4].x = gBattleWork.seqOperands[2];
    else
        gSpriteEntries[4].x = 0x1E - (gSpriteEntries[4].work[SEQ_BG_WIDTH] >> 1) -
                              (gBattleWork.seqOperands[2] + (gSpriteEntries[4].work[SEQ_BG_WIDTH] >> 1));
    gSpriteEntries[4].work[SEQ_BG_NO_DRAW] = 0;
    battle_seq_advance();
}

// Opcode 0x3A: two sprites hop and show the digits dice1 / dice2. guess: the two rolls.
void battle_seq_cmd_show_rolls(void) {
    u32 i;

    for (i = 0; i < 2; i++) {
        gSpriteEntries[i + 0xA].work[SEQ_ROLL_DIGIT] = (&gBattleWork.dice1)[i];
        gSpriteEntries[i + 0xA].work[SEQ_ROLL_HOP_STEP] = 0;
        gSpriteEntries[i + 0xA].work[SEQ_SPR_STATE] = 0x3A;
        gSpriteEntries[i + 0xA].work[SEQ_ROLL_ANIM] = i + 0x56;
    }
    play_sound_effect(0x10);
    battle_seq_advance();
}

void battle_sequence_update_sprites(void) {
    u32 i;

    for (i = 0; i <= 0x26; i++) {
        gEffectSpriteSlot = i + 1;
        gBattleSeqSpriteHandlers[gSpriteEntries[i + 1].work[SEQ_SPR_STATE]]();
    }
}

// Sprite 1 / 2 state 1: waits for the pose to finish before the queued one (state 2, or 3 to loop).
void battle_seq_spr_pose_wait(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_POSE_QUEUED] != 0) {
        if (gGameWork.runningSpriteSlot == 1) {
            if (gBattleWork.closeupLeftPoseDone != 0) {
                gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_POSE_QUEUED] = 0;
                if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_POSE_LOOP] != 0) {
                    gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_STATE]++;
                    gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_STATE]++;
                } else {
                    gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_STATE]++;
                }
            }
        } else if (gBattleWork.closeupRightPoseDone != 0) {
            gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_POSE_QUEUED] = 0;
            if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_POSE_LOOP] != 0) {
                gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_STATE]++;
                gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_STATE]++;
            } else {
                gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_STATE]++;
            }
        }
    }
}

// Sprite 1 / 2 state 2: after the delay, starts the queued pose (redrawing the Medabot if needed).
void battle_seq_spr_pose_set(void) {
    if (gSpriteEntries[gEffectSpriteSlot].work16[SEQ_POSE_DELAY] != 0) {
        gSpriteEntries[gEffectSpriteSlot].work16[SEQ_POSE_DELAY]--;
        return;
    }
    if (gEffectSpriteSlot == 1) {
        if (gBattleWork.closeupRedraw & 1) {
            get_active_bot_part_index_and_load_values(0);
            draw_medabot_sprite(0, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                                gBattleWork.partIds[3], (s16)gBattleWork.closeupLeftX, (s16)gBattleWork.closeupLeftY,
                                gBattleWork.battlefieldParams[3] + 2, 4, 0, 0, 0, gBattleWork.closeupPoseBase[0]);
            draw_medabot_sprite(0, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                                gBattleWork.partIds[3], (s16)gBattleWork.closeupLeftX, (s16)gBattleWork.closeupLeftY,
                                gBattleWork.battlefieldParams[3] + 2, 4, 0, 1, 0, gBattleWork.closeupPoseBase[0]);
        }
        gBattleWork.closeupRedraw &= ~1;
        gBattleWork.closeupLeftPose = gSpriteEntries[gEffectSpriteSlot].work[SEQ_POSE_ID];
    } else {
        if (gBattleWork.closeupRedraw & 2) {
            get_active_bot_part_index_and_load_values(1);
            draw_medabot_sprite(1, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                                gBattleWork.partIds[3], (s16)gBattleWork.closeupRightX, (s16)gBattleWork.closeupRightY,
                                gBattleWork.battlefieldParams[3] + 2, 8, 1, 0, 1, gBattleWork.closeupPoseBase[1]);
            draw_medabot_sprite(1, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                                gBattleWork.partIds[3], (s16)gBattleWork.closeupRightX, (s16)gBattleWork.closeupRightY,
                                gBattleWork.battlefieldParams[3] + 2, 8, 1, 1, 1, gBattleWork.closeupPoseBase[1]);
        }
        gBattleWork.closeupRedraw &= ~2;
        gBattleWork.closeupRightPose = gSpriteEntries[gEffectSpriteSlot].work[SEQ_POSE_ID];
    }
    gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_STATE] = 1;
}

// Sprite 1 / 2 state 3: restarts the queued pose each time it finishes.
void battle_seq_spr_pose_repeat(void) {
    struct SpriteEntry *base = gSpriteEntries;
    register u32 i asm("r4") = gEffectSpriteSlot;
    u8 slot;
    struct GameWork *game;
    register struct SpriteEntry *sprite asm("r1") = &base[i];
    register u16 timer asm("r3");
    if ((timer = sprite->work16[SEQ_POSE_DELAY]) != 0) {
        register u16 n asm("r0") = timer - 1;
        sprite->work16[SEQ_POSE_DELAY] = n;
        return;
    }
    slot = i;
    game = &gGameWork;
    if (slot == 1) {
        if (gBattleWork.closeupLeftPoseDone != 0) {
            if (gBattleWork.closeupRedraw & 1) {
                get_active_bot_part_index_and_load_values(0);
                draw_medabot_sprite(0, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                                    gBattleWork.partIds[3], (s16)gBattleWork.closeupLeftX,
                                    (s16)gBattleWork.closeupLeftY, gBattleWork.battlefieldParams[3] + 2, 4, 0, 0, 0,
                                    gBattleWork.closeupPoseBase[0]);
                draw_medabot_sprite(0, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                                    gBattleWork.partIds[3], (s16)gBattleWork.closeupLeftX,
                                    (s16)gBattleWork.closeupLeftY, gBattleWork.battlefieldParams[3] + 2, 4, 0, 1, 0,
                                    gBattleWork.closeupPoseBase[0]);
            }
            gBattleWork.closeupRedraw &= ~1;
            gBattleWork.closeupLeftPose = gSpriteEntries[gEffectSpriteSlot].work[SEQ_POSE_ID];
        }
    } else if (gBattleWork.closeupRightPoseDone != 0) {
        if (gBattleWork.closeupRedraw & 2) {
            get_active_bot_part_index_and_load_values(1);
            draw_medabot_sprite(1, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                                gBattleWork.partIds[3], (s16)gBattleWork.closeupRightX, (s16)gBattleWork.closeupRightY,
                                gBattleWork.battlefieldParams[3] + 2, 8, 1, 0, 1, gBattleWork.closeupPoseBase[1]);
            draw_medabot_sprite(1, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                                gBattleWork.partIds[3], (s16)gBattleWork.closeupRightX, (s16)gBattleWork.closeupRightY,
                                gBattleWork.battlefieldParams[3] + 2, 8, 1, 1, 1, gBattleWork.closeupPoseBase[1]);
        }
        gBattleWork.closeupRedraw &= ~2;
        gBattleWork.closeupRightPose = gSpriteEntries[gEffectSpriteSlot].work[SEQ_POSE_ID];
    }
    if (gSpriteEntries[game->runningSpriteSlot].work[SEQ_POSE_LOOP] == 0)
        gSpriteEntries[game->runningSpriteSlot].work[SEQ_SPR_STATE] = 1;
}

static inline void set_xy(u32 left_x, u32 right_x) {
    gBattleWork.closeupLeftX = left_x & 0x1FF;
    gBattleWork.closeupRightX = right_x & 0x1FF;
}

static inline void set_yx(u32 right_x, u32 left_x, u32 mask) {
    gBattleWork.closeupLeftX = left_x & mask;
    gBattleWork.closeupRightX = right_x & mask;
}

// Sprite 3 state 8: actor_dash: moves the actor, scrolling the camera once it passes the centre.
void battle_seq_spr_actor_dash(void) {
    u32 scroll;
    u8 shift;
    u32 x;
    shift = gBattleBg3ParallaxShift[gBattleWork.battlefield];
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_DASH_SIDE] == 0) {
        struct SpriteEntry *sprite;
        gBattleWork.closeupLeftX += gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_DASH_SPEED];
        gBattleWork.closeupLeftX &= 0x1FF;
        gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_DASH_X] +=
            gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_DASH_SPEED];
        sprite = &gSpriteEntries[gGameWork.runningSpriteSlot];
        x = sprite->work16[SEQ_DASH_X];
        if (x > 0x78) {
            register u32 lim asm("r5") = 0x188;
            if (x <= lim) {
                scroll = ((s16)gBattleWork.closeupLeftX) - 0x78;
                set_xy(gBattleWork.closeupLeftX - scroll, gBattleWork.closeupRightX - scroll);
                gBg2Scroll.x += scroll;
                gBg3Scroll.x += scroll >> shift;
            } else {
                register u32 y asm("r1") = ((volatile struct SpriteEntry *)sprite)->work16[SEQ_DASH_X];
                if ((s32)(y - 0x188) < sprite->work[SEQ_DASH_SPEED]) {
                    {
                        register u32 scroll_end asm("r0") = sprite->work[SEQ_DASH_SPEED] + lim;
                        scroll = scroll_end - y;
                    }
                    set_xy(gBattleWork.closeupLeftX - scroll, gBattleWork.closeupRightX - scroll);
                    gBg2Scroll.x += scroll;
                    gBg3Scroll.x += scroll >> shift;
                } else if (y > 0x18F) {
                    sprite->work[SEQ_SPR_STATE] = 0;
                }
            }
        }
    } else {
        u32 pos_x;
        register u32 mask asm("r5");
        struct SpriteEntry *sprite;
        gBattleWork.closeupRightX -= gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_DASH_SPEED];
        mask = 0x1FF;
        gBattleWork.closeupRightX &= mask;
        gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_DASH_X] -=
            gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_DASH_SPEED];
        sprite = &gSpriteEntries[gGameWork.runningSpriteSlot];
        pos_x = sprite->work16[SEQ_DASH_X] & mask;
        if (((u16)(((volatile struct SpriteEntry *)sprite)->work16[SEQ_DASH_X] - 0x78)) > 0x78) {
            if ((pos_x - 0x78) > 0xEF) {
                scroll = 0x78 - ((s16)gBattleWork.closeupRightX);
                set_yx(gBattleWork.closeupRightX - (-scroll), gBattleWork.closeupLeftX + scroll, mask);
                gBg2Scroll.x -= scroll;
                gBg3Scroll.x -= scroll >> shift;
            } else if ((pos_x <= 0x167) &&
                       ((0x168 - pos_x) < gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_DASH_SPEED])) {
                scroll = gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_DASH_SPEED] - (0x168 - pos_x);
                set_yx(gBattleWork.closeupRightX - (-scroll), gBattleWork.closeupLeftX + scroll, mask);
                gBg2Scroll.x -= scroll;
                gBg3Scroll.x -= scroll >> shift;
            } else if (pos_x <= 0x160) {
                gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_STATE] = 0;
            }
        }
    }
}

// Sprite 3 state 9: actor_move: moves the sprite and copies its position to the actor.
void battle_seq_spr_actor_move(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_MOVE_FRAMES] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_MOVE_FRAMES]--;
        update_sprite_animation_position(gGameWork.runningSpriteSlot);
        if (gSpriteEntries[3].work[SEQ_MOVE_SIDE] == 0) {
            gBattleWork.closeupLeftX = gSpriteEntries[gGameWork.runningSpriteSlot].x;
            gBattleWork.closeupLeftY = gSpriteEntries[gGameWork.runningSpriteSlot].y;
        } else {
            gBattleWork.closeupRightX = gSpriteEntries[gGameWork.runningSpriteSlot].x;
            gBattleWork.closeupRightY = gSpriteEntries[gGameWork.runningSpriteSlot].y;
        }
    } else {
        clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
    }
}

// Sprite 0x1E state 0xA: camera_track.
void battle_seq_spr_camera_track(void) {
    u32 scroll;
    u32 delta;
    u8 shift;

    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_CAMERA_DELAY] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_CAMERA_DELAY]--;
        return;
    }
    shift = gBattleBg3ParallaxShift[gBattleWork.battlefield];
    if ((u8)(gSpriteEntries[gGameWork.runningSpriteSlot].work[SPR_MOTION_ROW] - 1) <= 14) {
        delta = gSpriteEntries[gGameWork.runningSpriteSlot].x;
        update_sprite_animation_position(gGameWork.runningSpriteSlot);
        delta = gSpriteEntries[gGameWork.runningSpriteSlot].x - delta;
        gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_CAMERA_X] += delta;
        if (gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_CAMERA_X] > 0x78) {
            if (gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_CAMERA_X] <= 0x188) {
                scroll = gSpriteEntries[gGameWork.runningSpriteSlot].x - 0x78;
                gBattleWork.closeupLeftX = (gBattleWork.closeupLeftX - scroll) & 0x1FF;
                gBattleWork.closeupRightX = (gBattleWork.closeupRightX - scroll) & 0x1FF;
                gSpriteEntries[gGameWork.runningSpriteSlot].x =
                    (gSpriteEntries[gGameWork.runningSpriteSlot].x - scroll) & 0x1FF;
                battle_sprite_rotate_angles(1, scroll);
                gBg2Scroll.x += scroll;
                gBg3Scroll.x += scroll >> shift;
            } else if (gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_CAMERA_X] - 0x188 < delta) {
                scroll = delta + (0x188 - gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_CAMERA_X]);
                gBattleWork.closeupLeftX = (gBattleWork.closeupLeftX - scroll) & 0x1FF;
                gBattleWork.closeupRightX = (gBattleWork.closeupRightX - scroll) & 0x1FF;
                gSpriteEntries[gGameWork.runningSpriteSlot].x =
                    (gSpriteEntries[gGameWork.runningSpriteSlot].x - scroll) & 0x1FF;
                battle_sprite_rotate_angles(1, scroll);
                gBg2Scroll.x += scroll;
                gBg3Scroll.x += scroll >> shift;
            } else if (gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_CAMERA_X] > 0x18F) {
                gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_STATE] = 0;
            }
        }
    } else if ((u8)(gSpriteEntries[gGameWork.runningSpriteSlot].work[SPR_MOTION_ROW] - 0x11) <= 14) {
        u32 pos_x;

        scroll = gSpriteEntries[gGameWork.runningSpriteSlot].x;
        update_sprite_animation_position(gGameWork.runningSpriteSlot);
        scroll = scroll - gSpriteEntries[gGameWork.runningSpriteSlot].x;
        gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_CAMERA_X] =
            (gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_CAMERA_X] - scroll) & 0x1FF;
        pos_x = gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_CAMERA_X];
        if ((u16)(pos_x - 0x78) > 0x78) {
            if (pos_x - 0x78 > 0xEF) {
                scroll = 0x78 - gSpriteEntries[gGameWork.runningSpriteSlot].x;
                gBattleWork.closeupLeftX = (gBattleWork.closeupLeftX + scroll) & 0x1FF;
                gBattleWork.closeupRightX = (gBattleWork.closeupRightX + scroll) & 0x1FF;
                gSpriteEntries[gGameWork.runningSpriteSlot].x =
                    (gSpriteEntries[gGameWork.runningSpriteSlot].x + scroll) & 0x1FF;
                battle_sprite_rotate_angles(0, scroll);
                gBg2Scroll.x -= scroll;
                gBg3Scroll.x -= scroll >> shift;
            } else if (pos_x <= 0x167 && 0x168 - pos_x < scroll) {
                scroll = scroll - (0x168 - pos_x);
                gBattleWork.closeupLeftX = (gBattleWork.closeupLeftX + scroll) & 0x1FF;
                gBattleWork.closeupRightX = (gBattleWork.closeupRightX + scroll) & 0x1FF;
                gSpriteEntries[gGameWork.runningSpriteSlot].x =
                    (gSpriteEntries[gGameWork.runningSpriteSlot].x + scroll) & 0x1FF;
                battle_sprite_rotate_angles(0, scroll);
                gBg2Scroll.x -= scroll;
                gBg3Scroll.x -= scroll >> shift;
            } else if (pos_x <= 0x160) {
                gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_STATE] = 0;
            }
        }
    }
}

// Sprite 0x1E state 0xC: camera_track_all.
void battle_seq_spr_camera_track_all(void) {
    u32 scroll;
    u32 delta;
    u8 shift;

    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_CAMERA_DELAY] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_CAMERA_DELAY]--;
        return;
    }
    shift = gBattleBg3ParallaxShift[gBattleWork.battlefield];
    if ((u8)(gSpriteEntries[gGameWork.runningSpriteSlot].work[SPR_MOTION_ROW] - 1) <= 14) {
        delta = gSpriteEntries[gGameWork.runningSpriteSlot].x;
        update_sprite_animation_position(gGameWork.runningSpriteSlot);
        delta = gSpriteEntries[gGameWork.runningSpriteSlot].x - delta;
        gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_CAMERA_X] += delta;
        if (gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_CAMERA_X] > 0x78) {
            if (gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_CAMERA_X] <= 0x188) {
                scroll = gSpriteEntries[gGameWork.runningSpriteSlot].x - 0x78;
                gBattleWork.closeupLeftX = (gBattleWork.closeupLeftX - scroll) & 0x1FF;
                gBattleWork.closeupRightX = (gBattleWork.closeupRightX - scroll) & 0x1FF;
                gSpriteEntries[gGameWork.runningSpriteSlot].x =
                    (gSpriteEntries[gGameWork.runningSpriteSlot].x - scroll) & 0x1FF;
                battle_sprite_rotate_angles(1, scroll);
                gBg0Scroll.x += scroll;
                gBg1Scroll.x += scroll;
                gBg2Scroll.x += scroll;
                gBg3Scroll.x += scroll >> shift;
            } else if (gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_CAMERA_X] - 0x188 < delta) {
                scroll = delta + (0x188 - gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_CAMERA_X]);
                gBattleWork.closeupLeftX = (gBattleWork.closeupLeftX - scroll) & 0x1FF;
                gBattleWork.closeupRightX = (gBattleWork.closeupRightX - scroll) & 0x1FF;
                gSpriteEntries[gGameWork.runningSpriteSlot].x =
                    (gSpriteEntries[gGameWork.runningSpriteSlot].x - scroll) & 0x1FF;
                battle_sprite_rotate_angles(1, scroll);
                gBg0Scroll.x += scroll;
                gBg1Scroll.x += scroll;
                gBg2Scroll.x += scroll;
                gBg3Scroll.x += scroll >> shift;
            } else if (gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_CAMERA_X] > 0x18F) {
                gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_STATE] = 0;
            }
        }
    } else if ((u8)(gSpriteEntries[gGameWork.runningSpriteSlot].work[SPR_MOTION_ROW] - 0x11) <= 14) {
        u32 pos_x;

        scroll = gSpriteEntries[gGameWork.runningSpriteSlot].x;
        update_sprite_animation_position(gGameWork.runningSpriteSlot);
        scroll = scroll - gSpriteEntries[gGameWork.runningSpriteSlot].x;
        gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_CAMERA_X] =
            (gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_CAMERA_X] - scroll) & 0x1FF;
        pos_x = gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_CAMERA_X];
        if ((u16)(pos_x - 0x78) > 0x78) {
            if (pos_x - 0x78 > 0xEF) {
                scroll = 0x78 - gSpriteEntries[gGameWork.runningSpriteSlot].x;
                gBattleWork.closeupLeftX = (gBattleWork.closeupLeftX + scroll) & 0x1FF;
                gBattleWork.closeupRightX = (gBattleWork.closeupRightX + scroll) & 0x1FF;
                gSpriteEntries[gGameWork.runningSpriteSlot].x =
                    (gSpriteEntries[gGameWork.runningSpriteSlot].x + scroll) & 0x1FF;
                battle_sprite_rotate_angles(0, scroll);
                gBg0Scroll.x -= scroll;
                gBg1Scroll.x -= scroll;
                gBg2Scroll.x -= scroll;
                gBg3Scroll.x -= scroll >> shift;
            } else if (pos_x <= 0x167 && 0x168 - pos_x < scroll) {
                scroll = scroll - (0x168 - pos_x);
                gBattleWork.closeupLeftX = (gBattleWork.closeupLeftX + scroll) & 0x1FF;
                gBattleWork.closeupRightX = (gBattleWork.closeupRightX + scroll) & 0x1FF;
                gSpriteEntries[gGameWork.runningSpriteSlot].x =
                    (gSpriteEntries[gGameWork.runningSpriteSlot].x + scroll) & 0x1FF;
                battle_sprite_rotate_angles(0, scroll);
                gBg0Scroll.x -= scroll;
                gBg1Scroll.x -= scroll;
                gBg2Scroll.x -= scroll;
                gBg3Scroll.x -= scroll >> shift;
            } else if (pos_x <= 0x160) {
                gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_STATE] = 0;
            }
        }
    }
}

// State 0xB: an effect sprite: appears after SEQ_EFFECT_SHOW_DELAY frames, moves after
// SEQ_EFFECT_MOVE_DELAY frames.
void battle_seq_spr_effect(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_SHOW_DELAY] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_SHOW_DELAY]--;
    } else {
        gSpriteEntries[gGameWork.runningSpriteSlot].flags |= SPRITE_FLAG_ENABLED;
        process_sprite_anim_commands(
            gBattleSpriteAnimScripts[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_ANIM]],
            gGameWork.runningSpriteSlot);
    }
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_MOVE_DELAY] != 0)
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_MOVE_DELAY]--;
    else
        update_sprite_animation_position(gGameWork.runningSpriteSlot);
}

// State 0xD: battle_seq_spr_effect plus a y offset from gBattleSeqWaveOffsets.
void battle_seq_spr_effect_wave(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_SHOW_DELAY] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_SHOW_DELAY]--;
    } else {
        gSpriteEntries[gGameWork.runningSpriteSlot].flags |= SPRITE_FLAG_ENABLED;
        process_sprite_anim_commands(
            gBattleSpriteAnimScripts[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_ANIM]],
            gGameWork.runningSpriteSlot);
    }
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_MOVE_DELAY] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_MOVE_DELAY]--;
    } else {
        update_sprite_animation_position(gGameWork.runningSpriteSlot);
        gSpriteEntries[gGameWork.runningSpriteSlot].y +=
            gBattleSeqWaveOffsets[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_WAVE_STEP]];
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_WAVE_STEP] =
            (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_WAVE_STEP] + 1) & 0x1F;
    }
}

// State 0xE: battle_seq_spr_effect plus its tile animation.
void battle_seq_spr_effect_tiles(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_SHOW_DELAY] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_SHOW_DELAY]--;
    } else {
        gSpriteEntries[gGameWork.runningSpriteSlot].flags |= SPRITE_FLAG_ENABLED;
        process_sprite_anim_commands(
            gBattleSpriteAnimScripts[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_ANIM]],
            gGameWork.runningSpriteSlot);
        tile_anim_run_dup(gBattleSeqTileAnims[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_TILE_ANIM]],
                          0);
    }
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_MOVE_DELAY] != 0)
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_MOVE_DELAY]--;
    else
        update_sprite_animation_position(gGameWork.runningSpriteSlot);
}

// Sprite 4 state 0x10: bg_effect.
void battle_seq_spr_bg_effect(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_BG_DELAY] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_BG_DELAY]--;
        return;
    }
    tile_anim_run(gBattleSeqTileAnims[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_TILE_ANIM]], 0);
    if (gGameWork.tileAnims[0].state == 0xFF) {
        vram_fill_tilemap_rect(gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_WIDTH],
                               gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_HEIGHT],
                               gSpriteEntries[gGameWork.runningSpriteSlot].x,
                               gSpriteEntries[gGameWork.runningSpriteSlot].y, REG_BG0CNT, 0);
        clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
    } else if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_NO_DRAW] == 0) {
        write_tilemap_rect(gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_WIDTH],
                           gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_HEIGHT],
                           gSpriteEntries[gGameWork.runningSpriteSlot].x, gSpriteEntries[gGameWork.runningSpriteSlot].y,
                           gUiTilemaps[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_TILEMAP]], REG_BG0CNT,
                           0);
    }
}

// Sprite 0x23 state 0x11: bg_sweep.
void battle_seq_spr_bg_sweep(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_BG_DELAY] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_BG_DELAY]--;
        return;
    }
    tile_anim_run(gBattleSeqTileAnims[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_TILE_ANIM]], 1);
    gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_SWEEP_FRAME]++;
    if ((gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_SWEEP_FRAME] & 1) &&
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_SWEEP_STOP] == 0) {
        if (!(gBattleWork.actorSideFlags & 2))
            write_tilemap_block_at(gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_WIDTH],
                                   gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_HEIGHT],
                                   (gSpriteEntries[gGameWork.runningSpriteSlot].x +
                                    gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_SWEEP_COLUMN]) &
                                       0x3F,
                                   gSpriteEntries[gGameWork.runningSpriteSlot].y,
                                   gUiTilemaps[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_TILEMAP]],
                                   REG_BG0CNT, 0);
        else
            write_tilemap_block_at(gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_WIDTH],
                                   gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_HEIGHT],
                                   (gSpriteEntries[gGameWork.runningSpriteSlot].x -
                                    gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_SWEEP_COLUMN]) &
                                       0x3F,
                                   gSpriteEntries[gGameWork.runningSpriteSlot].y,
                                   gUiTilemaps[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_TILEMAP]],
                                   REG_BG0CNT, 0);
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_SWEEP_COLUMN]++;
    }
}

// Sprite 4 state 0x12: bg_effect_at.
void battle_seq_spr_bg_effect_at(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_BG_DELAY] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_BG_DELAY]--;
        return;
    }
    tile_anim_run(gBattleSeqTileAnims[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_TILE_ANIM]], 0);
    if (gGameWork.tileAnims[0].state == 0xFF) {
        tilemap_fill_rect(gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_WIDTH],
                          gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_HEIGHT],
                          gSpriteEntries[gGameWork.runningSpriteSlot].x, gSpriteEntries[gGameWork.runningSpriteSlot].y,
                          REG_BG0CNT, 0);
        clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
    } else if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_NO_DRAW] == 0) {
        write_tilemap_block_at(
            gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_WIDTH],
            gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_HEIGHT],
            gSpriteEntries[gGameWork.runningSpriteSlot].x, gSpriteEntries[gGameWork.runningSpriteSlot].y,
            gUiTilemaps[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_TILEMAP]], REG_BG0CNT, 0);
    }
}

// Sprite 4 state 0x13: bg_effect_keep.
void battle_seq_spr_bg_effect_keep(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_BG_DELAY] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_BG_DELAY]--;
        return;
    }
    tile_anim_run(gBattleSeqTileAnims[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_TILE_ANIM]], 0);
    if (gGameWork.tileAnims[0].state == 0xFF) {
        clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
    } else if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_NO_DRAW] == 0) {
        write_tilemap_block_at(
            gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_WIDTH],
            gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_HEIGHT],
            gSpriteEntries[gGameWork.runningSpriteSlot].x, gSpriteEntries[gGameWork.runningSpriteSlot].y,
            gUiTilemaps[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_BG_TILEMAP]], REG_BG0CNT, 0);
    }
}

// State 0x18: plays sound SEQ_SOUND_ID SEQ_SOUND_COUNT times, SEQ_SOUND_INTERVAL frames apart.
void battle_seq_spr_sound(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_SOUND_DELAY] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_SOUND_DELAY]--;
    } else if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SOUND_WAIT] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SOUND_WAIT]--;
    } else if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SOUND_COUNT] != 0) {
        play_sound_effect(gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SOUND_ID]);
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SOUND_WAIT] =
            gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SOUND_INTERVAL];
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SOUND_COUNT]--;
    } else {
        clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
    }
}

// State 0x20: after the delay, starts the animation on slot SEQ_PLAY_SLOT (state 0x21) and frees itself.
void battle_seq_spr_anim_delay(void) {
    u8 n;

    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_PLAY_DELAY] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_PLAY_DELAY]--;
        return;
    }
    n = gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_PLAY_SLOT];
    gSpriteEntries[n].palette = gSpriteEntries[gGameWork.runningSpriteSlot].palette;
    gSpriteEntries[n].work[SEQ_SPR_ANIM] = gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_ANIM];
    gSpriteEntries[n].work[SEQ_SPR_STATE] = 0x21;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[gSpriteEntries[n].work[SEQ_SPR_ANIM]], n);
    clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
}

// State 0x21: runs the sprite animation until it ends, then frees the slot.
void battle_seq_spr_anim_once(void) {
    process_sprite_anim_commands(
        gBattleSpriteAnimScripts[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_ANIM]],
        gGameWork.runningSpriteSlot);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
        clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
}

// State 0x22: every SEQ_TRAIL_INTERVAL + 1 frames drops a puff (state 0x23) at an offset from sprite
// SEQ_TRAIL_SOURCE.
void battle_seq_spr_trail(void) {
    u32 n;

    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_TRAIL_DELAY] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_TRAIL_DELAY]--;
        return;
    }
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_TRAIL_COUNTER] !=
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_TRAIL_INTERVAL]) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_TRAIL_COUNTER]++;
        return;
    }
    gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_TRAIL_COUNTER] = 0;
    n = find_next_free_sprite_slot(0xE, 0x10);
    gSpriteEntries[n].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[n].frame_table = 0;
    if (!(gBattleWork.actorSideFlags & 2))
        gSpriteEntries[n].x = (gSpriteEntries[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_TRAIL_SOURCE]].x +
                               gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_TRAIL_OFFSET_X]) &
                              0x1FF;
    else
        gSpriteEntries[n].x = (gSpriteEntries[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_TRAIL_SOURCE]].x +
                               (gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_TRAIL_OFFSET_X] * -1)) &
                              0x1FF;
    gSpriteEntries[n].y = (gSpriteEntries[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_TRAIL_SOURCE]].y +
                           gSpriteEntries[gGameWork.runningSpriteSlot].work16[SEQ_TRAIL_OFFSET_Y]) &
                          0xFF;
    gSpriteEntries[n].palette = gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_TRAIL_PALETTE];
    gSpriteEntries[n].order = 0x80;
    gSpriteEntries[n].work[SEQ_SPR_STATE] = 0x23;
    gSpriteEntries[n].work[SEQ_SPR_ANIM] = gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_ANIM];
    battle_sprite_anim_init(gBattleSpriteAnimScripts[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_ANIM]],
                            n);
}

// State 0x23: a trail puff: plays its animation once.
void battle_seq_spr_trail_puff(void) {
    process_sprite_anim_commands(
        gBattleSpriteAnimScripts[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_ANIM]],
        gGameWork.runningSpriteSlot);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
        clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
}

// State 0x28: blends all palettes one step further towards the colour, up to 16.
void battle_seq_spr_fade_in(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_DELAY] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_DELAY]--;
        return;
    }
    bg_palettes_blend_masked_now((gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_BLUE] << 10) |
                                     (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_GREEN] << 5) |
                                     gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_RED],
                                 gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_LEVEL], 0xFDFF);
    obj_palettes_blend_masked_now((gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_BLUE] << 10) |
                                      (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_GREEN] << 5) |
                                      gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_RED],
                                  gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_LEVEL], 0xB00F);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_LEVEL] == 0x10)
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_STATE] = 0;
    else
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_LEVEL]++;
}

// State 0x29: blends all palettes one step back from the colour, down to 0.
void battle_seq_spr_fade_out(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_DELAY] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_DELAY]--;
        return;
    }
    bg_palettes_blend_masked_now((gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_BLUE] << 10) |
                                     (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_GREEN] << 5) |
                                     gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_RED],
                                 gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_LEVEL], 0xFDFF);
    obj_palettes_blend_masked_now((gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_BLUE] << 10) |
                                      (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_GREEN] << 5) |
                                      gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_RED],
                                  gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_LEVEL], 0xB00F);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_LEVEL] == 0)
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_STATE] = 0;
    else
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_FADE_LEVEL]--;
}

// State 0x30: the centre sprite of spawn_orbit.
void battle_seq_spr_orbit_center(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_SHOW_DELAY])
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_SHOW_DELAY]--;
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_MOVE_DELAY])
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_MOVE_DELAY]--;
    else
        update_sprite_animation_position(gGameWork.runningSpriteSlot);
}

// State 0x31: circles sprite 0xA at radius 16.
void battle_seq_spr_orbit(void) {
    struct Coords16 pos;

    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_SHOW_DELAY] != 0)
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_SHOW_DELAY]--;
    else {
        gSpriteEntries[gGameWork.runningSpriteSlot].flags |= SPRITE_FLAG_ENABLED;
        process_sprite_anim_commands(
            gBattleSpriteAnimScripts[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_ANIM]],
            gGameWork.runningSpriteSlot);
    }
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_MOVE_DELAY] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_EFFECT_MOVE_DELAY]--;
        return;
    }
    pos = calc_polar_to_screen_coords(gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_ORBIT_ANGLE], 0x10,
                                      gSpriteEntries[10].x, gSpriteEntries[10].y);
    gSpriteEntries[gGameWork.runningSpriteSlot].x = pos.x;
    gSpriteEntries[gGameWork.runningSpriteSlot].y = pos.y;
    if (!(gBattleWork.actorSideFlags & 2))
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_ORBIT_ANGLE] += 0x10;
    else
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_ORBIT_ANGLE] -= 0x10;
}

// State 0x34: shrinks the sprite until it vanishes (SEQ_SCALE_GROW = 0) or grows it to 0x40.
void battle_seq_spr_scale(void) {
    struct SpriteEntry *sprite;
    u8 i;

    process_sprite_anim_commands(
        gBattleSpriteAnimScripts[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_ANIM]],
        gGameWork.runningSpriteSlot);
    i = gGameWork.runningSpriteSlot;
    sprite = &gSpriteEntries[i];
    if (sprite->work[SEQ_SCALE_GROW] == 0) {
        if (sprite->scale_x <= sprite->work[SEQ_SCALE_STEP]) {
            disable_sprites(i, 1);
            return;
        }
        sprite->scale_x -= sprite->work[SEQ_SCALE_STEP];
        gSpriteEntries[gGameWork.runningSpriteSlot].scale_y -=
            gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SCALE_STEP];
    } else if (sprite->scale_x == 0x40)
        sprite->work[SEQ_SPR_STATE] = 0;
    else {
        sprite->scale_x += sprite->work[SEQ_SCALE_STEP];
        gSpriteEntries[gGameWork.runningSpriteSlot].scale_y +=
            gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SCALE_STEP];
    }
}

// State 0x36: a spawn_ring sprite spiralling around sprite 0xA, growing then shrinking.
void battle_seq_spr_ring_spiral(void) {
    struct Coords16 pos;

    process_sprite_anim_commands(
        gBattleSpriteAnimScripts[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_ANIM]],
        gGameWork.runningSpriteSlot);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_RING_FRAME] <= 6) {
        gSpriteEntries[gGameWork.runningSpriteSlot].scale_x += 8;
        gSpriteEntries[gGameWork.runningSpriteSlot].scale_y += 8;
    }
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_RING_FRAME] > 0x3C) {
        if (gSpriteEntries[gGameWork.runningSpriteSlot].scale_x == 8)
            clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
        else {
            gSpriteEntries[gGameWork.runningSpriteSlot].scale_x -= 4;
            gSpriteEntries[gGameWork.runningSpriteSlot].scale_y -= 4;
        }
    }
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_RING_EXPAND] == 0) {
        if (!(gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_RING_FRAME] & 1))
            gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_RING_RADIUS]--;
    } else {
        if (!(gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_RING_FRAME] & 1))
            gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_RING_RADIUS]++;
    }
    gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_RING_ANGLE] += 4;
    gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_RING_FRAME]++;
    pos = calc_polar_to_screen_coords(gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_RING_ANGLE],
                                      gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_RING_RADIUS],
                                      gSpriteEntries[10].x, gSpriteEntries[10].y);
    gSpriteEntries[gGameWork.runningSpriteSlot].x = pos.x;
    gSpriteEntries[gGameWork.runningSpriteSlot].y = pos.y;
}

// Sprite 9 state 0x38: draws the armor panel, then drains each part's shown armor to its new value.
void battle_seq_spr_armor_drain(void) {
    u32 done = 0;

    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_ARMOR_DELAY] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_ARMOR_DELAY]--;
        return;
    }
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_ARMOR_REDRAW] != 0) {
        armor_panel_draw_icons(gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_ARMOR_SIDE]);
        armor_panel_draw_frame(gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_ARMOR_SIDE]);
        armor_panel_draw_bars(gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_ARMOR_SIDE], gBattleWork.actor);
        armor_panel_draw_numbers(gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_ARMOR_SIDE], gBattleWork.actor);
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_ARMOR_REDRAW] = 0;
    }
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_ARMOR_DRAIN_DELAY] != 0) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_ARMOR_DRAIN_DELAY]--;
        return;
    }
    done = armor_drain_step(&gBattleWork.partDamage[0], gBattleWork.actor, 0);
    done += armor_drain_step(&gBattleWork.partDamage[1], gBattleWork.actor, 1);
    done += armor_drain_step(&gBattleWork.partDamage[2], gBattleWork.actor, 2);
    done += armor_drain_step(&gBattleWork.partDamage[3], gBattleWork.actor, 3);
    armor_panel_draw_bars(gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_ARMOR_SIDE], gBattleWork.actor);
    armor_panel_draw_numbers(gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_ARMOR_SIDE], gBattleWork.actor);
    if (done == 4)
        clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
}

// State 0x3A: hops, then shows its digit.
void battle_seq_spr_roll_hop(void) {
    process_sprite_anim_commands(
        gBattleSpriteAnimScripts[gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_ROLL_ANIM]],
        gGameWork.runningSpriteSlot);
    if (sprite_hop_step(gGameWork.runningSpriteSlot)) {
        gSpriteEntries[gGameWork.runningSpriteSlot].frame =
            0x6307 + gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_ROLL_DIGIT];
        gSpriteEntries[gGameWork.runningSpriteSlot].work[SEQ_SPR_STATE] = 0;
    }
}

s16 battle_seq_peek(void) {
    const s16 *seq = gBattleSeqScripts[gBattleWork.animSkill];
    return seq[gBattleWork.seqOffset];
}

void battle_seq_load_operands(void) {
    const s16 *seq = gBattleSeqScripts[gBattleWork.animSkill];
    u32 n = gBattleSeqOperandCounts[seq[gBattleWork.seqOffset]];
    u32 i;

    for (i = 0; i < n; i++)
        gBattleWork.seqOperands[i] = seq[gBattleWork.seqOffset + i + 1];
}

void battle_seq_advance(void) {
    const s16 *seq = gBattleSeqScripts[gBattleWork.animSkill];
    const u8 *ops = gBattleSeqOperandCounts;
    s32 offset = gBattleWork.seqOffset;

    gBattleWork.seqOffset = offset + 1 + ops[seq[offset]];
}

static void battle_sprite_rotate_angles(u32 dir, u32 delta) {
    u32 i;
    for (i = 0; i <= 0x13; i++) {
        if (gSpriteEntries[i + 10].work[SEQ_SPR_STATE] != 0) {
            if (dir)
                gSpriteEntries[i + 10].x = (gSpriteEntries[i + 10].x - delta) & 0x1FF;
            else
                gSpriteEntries[i + 10].x = (gSpriteEntries[i + 10].x + delta) & 0x1FF;
        }
    }
}
