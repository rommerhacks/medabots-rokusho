// The action close-up scene: init_battle_closeup_scene and init_battle_scene_backgrounds set up the BG
// layers, setup_battle_medapart_scenes the acting parts, and closeup_left_pose_step /
// closeup_right_pose_step step the message text. Called from battle/action_steps and action_script.

#include "global.h"

void init_battle_closeup_scene(void) {
    init_medabot_sprite_tree();
    if (!(gBattleWork.actorSideFlags & 1)) {
        gBattleWork.closeupLeftX = 0x3C;
        gBattleWork.closeupPoseBase[0] = 0;
    } else {
        gBattleWork.closeupLeftX = 0x12C;
        gBattleWork.closeupPoseBase[0] = 0x28;
        gBattleWork.closeupRedraw |= 1;
    }
    get_active_bot_part_index_and_load_values(0);
    gBattleWork.closeupLeftY = 0x50;
    draw_medabot_sprite(0, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                        gBattleWork.partIds[3], (s16)gBattleWork.closeupLeftX, (s16)gBattleWork.closeupLeftY,
                        gBattleWork.battlefieldParams[3] + 2, 4, 0, 0, 0, gBattleWork.closeupPoseBase[0]);
    if (!(gBattleWork.actorSideFlags & 1)) {
        gBattleWork.closeupRightX = 0x1C4;
        gBattleWork.closeupPoseBase[1] = 0x28;
        gBattleWork.closeupRedraw |= 2;
    } else {
        gBattleWork.closeupRightX = 0xB4;
        gBattleWork.closeupPoseBase[1] = 0;
    }
    get_active_bot_part_index_and_load_values(1);
    gBattleWork.closeupRightY = 0x50;
    draw_medabot_sprite(1, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                        gBattleWork.partIds[3], (s16)gBattleWork.closeupRightX, (s16)gBattleWork.closeupRightY,
                        gBattleWork.battlefieldParams[3] + 2, 8, 1, 0, 1, gBattleWork.closeupPoseBase[1]);
}

// The close-up scene parks a side outside x 0x128-0x1D0 when it is not shown.
static u32 closeup_x_on_screen(u32 x) {
    if (x - 0x128 <= 0xA8)
        return 0;
    return 1;
}

void init_battle_scene_backgrounds(void) {
    if (gBattleWork.closeupRedraw & 1)
        gGameWork.noAffineSprites = 1;
    else
        gGameWork.noAffineSprites = 0;
    if (closeup_x_on_screen((s16)gBattleWork.closeupLeftX)) {
        get_active_bot_part_index_and_load_values(0);
        draw_medabot_sprite(0, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                            gBattleWork.partIds[3], (s16)gBattleWork.closeupLeftX, (s16)gBattleWork.closeupLeftY,
                            gBattleWork.battlefieldParams[3] + 2, 4, 0, 1, 0, gBattleWork.closeupPoseBase[0]);
    }
    if (gBattleWork.closeupRedraw & 2)
        gGameWork.noAffineSprites = 1;
    else
        gGameWork.noAffineSprites = 0;
    if (closeup_x_on_screen((s16)gBattleWork.closeupRightX)) {
        get_active_bot_part_index_and_load_values(1);
        draw_medabot_sprite(1, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                            gBattleWork.partIds[3], (s16)gBattleWork.closeupRightX, (s16)gBattleWork.closeupRightY,
                            gBattleWork.battlefieldParams[3] + 2, 8, 1, 1, 1, gBattleWork.closeupPoseBase[1]);
    }
    gGameWork.noAffineSprites = 0;
}

void setup_battle_medapart_scenes(void) {
    if (gBattleWork.closeupRedraw & 1)
        gGameWork.noAffineSprites = 1;
    else
        gGameWork.noAffineSprites = 0;
    if (closeup_x_on_screen((s16)gBattleWork.closeupLeftX)) {
        get_active_bot_part_index_and_load_values(0);
        draw_medabot_sprite(0, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                            gBattleWork.partIds[3], (s16)gBattleWork.closeupLeftX, (s16)gBattleWork.closeupLeftY,
                            gBattleWork.battlefieldParams[3] + 2, 4, 0, 2, 0, gBattleWork.closeupPoseBase[0]);
        draw_medabot_sprite(0, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                            gBattleWork.partIds[3], (s16)gBattleWork.closeupLeftX, (s16)gBattleWork.closeupLeftY,
                            gBattleWork.battlefieldParams[3] + 2, 4, 0, 1, 0, gBattleWork.closeupPoseBase[0]);
    }
    if (gBattleWork.closeupRedraw & 2)
        gGameWork.noAffineSprites = 1;
    else
        gGameWork.noAffineSprites = 0;
    if (closeup_x_on_screen((s16)gBattleWork.closeupRightX)) {
        get_active_bot_part_index_and_load_values(1);
        draw_medabot_sprite(1, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                            gBattleWork.partIds[3], (s16)gBattleWork.closeupRightX, (s16)gBattleWork.closeupRightY,
                            gBattleWork.battlefieldParams[3] + 2, 8, 1, 2, 1, gBattleWork.closeupPoseBase[1]);
        draw_medabot_sprite(1, gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                            gBattleWork.partIds[3], (s16)gBattleWork.closeupRightX, (s16)gBattleWork.closeupRightY,
                            gBattleWork.battlefieldParams[3] + 2, 8, 1, 1, 1, gBattleWork.closeupPoseBase[1]);
    }
    gGameWork.noAffineSprites = 0;
}

void get_active_bot_part_index_and_load_values(u32 side) {
    if (side == 0) {
        if (!(gBattleWork.actorSideFlags & 1))
            get_bot_part_effective_values(gBattleWork.actor, gBattleWork.partIds);
        else if (gBattleWork.reactionFlags & 2)
            get_bot_part_effective_values(gBattleWork.swapBot, gBattleWork.partIds);
        else
            get_bot_part_effective_values(gBattleWork.target, gBattleWork.partIds);
    } else {
        if (!(gBattleWork.actorSideFlags & 1)) {
            if (gBattleWork.reactionFlags & 2)
                get_bot_part_effective_values(gBattleWork.swapBot, gBattleWork.partIds);
            else
                get_bot_part_effective_values(gBattleWork.target, gBattleWork.partIds);
        } else {
            get_bot_part_effective_values(gBattleWork.actor, gBattleWork.partIds);
        }
    }
}

// r0 stays live through the function: it passes its (unused) argument through.
// guess: 0x29 is the starting pose/text state for both close-up sides.
u32 closeup_reset_text_states(passthrough)
u32 passthrough; // FAKEMATCH: returned unchanged to keep r0 live
{
    struct BattleWork *battle = &gBattleWork;
    battle->closeupLeftPose = 0x29;
    battle->closeupRightPose = 0x29;
    return passthrough;
}

u32 closeup_left_pose_step(void) {
    struct BattleWork *battle = &gBattleWork;
    u8 *state = &battle->closeupLeftPose;
    u32 done;
    if (!(*state & 0x80) && !(battle->closeupRedraw & 1)) {
        get_active_bot_part_index_and_load_values(0);
        done = medabot_pose_anim_step(0, *state, battle->partIds[3]);
        if (done)
            battle->closeupLeftPose |= 0x80;
        return done;
    }
    return 1;
}

u32 closeup_right_pose_step(void) {
    struct BattleWork *battle = &gBattleWork;
    u8 *state = &battle->closeupRightPose;
    u32 done;
    if (!(*state & 0x80) && !(battle->closeupRedraw & 2)) {
        get_active_bot_part_index_and_load_values(1);
        done = medabot_pose_anim_step(1, *state, battle->partIds[3]);
        if (done)
            battle->closeupRightPose |= 0x80;
        return done;
    }
    return 1;
}

// guess: per-side tally of successful actions, compared when TIME runs out (robattle_judge_time_up).
void side_add_action_point(void) {
    gBattleWork.traps[gBattleWork.actorSide].actionPoints++;
}

// The Medabot in gBattleWork.target gains 20 Medaforce (40 with guardFlags bit 3), up to the full 80.
void charge_target_medaforce(void) {
    u32 add;
    u32 gauge;
    if (gBattleBots[gBattleWork.target].guardFlags & 8)
        add = 0x28;
    else
        add = 0x14;
    gauge = gBattleBots[gBattleWork.target].medaforceGauge + add;
    if (gauge > 0x4F)
        gauge = 0x50;
    gBattleBots[gBattleWork.target].medaforceGauge = gauge;
}
