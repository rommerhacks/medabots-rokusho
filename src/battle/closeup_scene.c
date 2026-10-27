// The action close-up scene: init_battle_closeup_scene and init_battle_scene_backgrounds set up the BG
// layers, setup_battle_medapart_scenes the acting parts, and closeup_left_pose_step /
// closeup_right_pose_step step the message text. Called from battle/action_steps and action_script.

#include "global.h"

void init_battle_closeup_scene(void) {
    init_scene_buffers_080445F4();
    if (!(gBattleWork.unkF8 & 1)) {
        gBattleWork.unk154 = 0x3C;
        gBattleWork.unk114[0] = 0;
    } else {
        gBattleWork.unk154 = 0x12C;
        gBattleWork.unk114[0] = 0x28;
        gBattleWork.unkFF |= 1;
    }
    get_active_bot_part_index_and_load_values(0);
    gBattleWork.unk156 = 0x50;
    draw_medabot_sprite(0, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3],
                        (s16)gBattleWork.unk154, (s16)gBattleWork.unk156, gBattleWork.unk39[3] + 2, 4, 0, 0, 0,
                        gBattleWork.unk114[0]);
    if (!(gBattleWork.unkF8 & 1)) {
        gBattleWork.unk158 = 0x1C4;
        gBattleWork.unk114[1] = 0x28;
        gBattleWork.unkFF |= 2;
    } else {
        gBattleWork.unk158 = 0xB4;
        gBattleWork.unk114[1] = 0;
    }
    get_active_bot_part_index_and_load_values(1);
    gBattleWork.unk15A = 0x50;
    draw_medabot_sprite(1, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3],
                        (s16)gBattleWork.unk158, (s16)gBattleWork.unk15A, gBattleWork.unk39[3] + 2, 8, 1, 0, 1,
                        gBattleWork.unk114[1]);
}

// The close-up scene parks a side outside x 0x128-0x1D0 when it is not shown.
static u32 closeup_x_on_screen(u32 x) {
    if (x - 0x128 <= 0xA8)
        return 0;
    return 1;
}

void init_battle_scene_backgrounds(void) {
    if (gBattleWork.unkFF & 1)
        gGameWork.unk96 = 1;
    else
        gGameWork.unk96 = 0;
    if (closeup_x_on_screen((s16)gBattleWork.unk154)) {
        get_active_bot_part_index_and_load_values(0);
        draw_medabot_sprite(0, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3],
                            (s16)gBattleWork.unk154, (s16)gBattleWork.unk156, gBattleWork.unk39[3] + 2, 4, 0, 1, 0,
                            gBattleWork.unk114[0]);
    }
    if (gBattleWork.unkFF & 2)
        gGameWork.unk96 = 1;
    else
        gGameWork.unk96 = 0;
    if (closeup_x_on_screen((s16)gBattleWork.unk158)) {
        get_active_bot_part_index_and_load_values(1);
        draw_medabot_sprite(1, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3],
                            (s16)gBattleWork.unk158, (s16)gBattleWork.unk15A, gBattleWork.unk39[3] + 2, 8, 1, 1, 1,
                            gBattleWork.unk114[1]);
    }
    gGameWork.unk96 = 0;
}

void setup_battle_medapart_scenes(void) {
    if (gBattleWork.unkFF & 1)
        gGameWork.unk96 = 1;
    else
        gGameWork.unk96 = 0;
    if (closeup_x_on_screen((s16)gBattleWork.unk154)) {
        get_active_bot_part_index_and_load_values(0);
        draw_medabot_sprite(0, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3],
                            (s16)gBattleWork.unk154, (s16)gBattleWork.unk156, gBattleWork.unk39[3] + 2, 4, 0, 2, 0,
                            gBattleWork.unk114[0]);
        draw_medabot_sprite(0, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3],
                            (s16)gBattleWork.unk154, (s16)gBattleWork.unk156, gBattleWork.unk39[3] + 2, 4, 0, 1, 0,
                            gBattleWork.unk114[0]);
    }
    if (gBattleWork.unkFF & 2)
        gGameWork.unk96 = 1;
    else
        gGameWork.unk96 = 0;
    if (closeup_x_on_screen((s16)gBattleWork.unk158)) {
        get_active_bot_part_index_and_load_values(1);
        draw_medabot_sprite(1, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3],
                            (s16)gBattleWork.unk158, (s16)gBattleWork.unk15A, gBattleWork.unk39[3] + 2, 8, 1, 2, 1,
                            gBattleWork.unk114[1]);
        draw_medabot_sprite(1, gBattleWork.unk64[0], gBattleWork.unk64[1], gBattleWork.unk64[2], gBattleWork.unk64[3],
                            (s16)gBattleWork.unk158, (s16)gBattleWork.unk15A, gBattleWork.unk39[3] + 2, 8, 1, 1, 1,
                            gBattleWork.unk114[1]);
    }
    gGameWork.unk96 = 0;
}

void get_active_bot_part_index_and_load_values(u32 side) {
    if (side == 0) {
        if (!(gBattleWork.unkF8 & 1))
            get_bot_part_effective_values(gBattleWork.unk87, gBattleWork.unk64);
        else if (gBattleWork.unkF6 & 2)
            get_bot_part_effective_values(gBattleWork.unk161, gBattleWork.unk64);
        else
            get_bot_part_effective_values(gBattleWork.unk88, gBattleWork.unk64);
    } else {
        if (!(gBattleWork.unkF8 & 1)) {
            if (gBattleWork.unkF6 & 2)
                get_bot_part_effective_values(gBattleWork.unk161, gBattleWork.unk64);
            else
                get_bot_part_effective_values(gBattleWork.unk88, gBattleWork.unk64);
        } else {
            get_bot_part_effective_values(gBattleWork.unk87, gBattleWork.unk64);
        }
    }
}

// r0 stays live through the function: it passes its (unused) argument through.
// guess: 0x29 is the starting pose/text state for both close-up sides.
u32 closeup_reset_text_states(passthrough)
u32 passthrough; // FAKEMATCH: returned unchanged to keep r0 live
{
    struct BattleWork *b = &gBattleWork;
    b->unk112 = 0x29;
    b->unk113 = 0x29;
    return passthrough;
}

u32 closeup_left_pose_step(void) {
    struct BattleWork *b = &gBattleWork;
    u8 *state = &b->unk112;
    u32 done;
    if (!(*state & 0x80) && !(b->unkFF & 1)) {
        get_active_bot_part_index_and_load_values(0);
        done = medabot_pose_anim_step(0, *state, b->unk64[3]);
        if (done)
            b->unk112 |= 0x80;
        return done;
    }
    return 1;
}

u32 closeup_right_pose_step(void) {
    struct BattleWork *b = &gBattleWork;
    u8 *state = &b->unk113;
    u32 done;
    if (!(*state & 0x80) && !(b->unkFF & 2)) {
        get_active_bot_part_index_and_load_values(1);
        done = medabot_pose_anim_step(1, *state, b->unk64[3]);
        if (done)
            b->unk113 |= 0x80;
        return done;
    }
    return 1;
}

// guess: per-side tally of successful actions, compared when TIME runs out (robattle_judge_time_up).
void side_add_action_point(void) {
    gBattleWork.unk28[gBattleWork.unk89].unk1++;
}

// The Medabot in unk88 gains 20 Medaforce (40 with unkC0 bit 3), up to the full 80.
void charge_target_medaforce(void) {
    u32 add;
    u32 v;
    if (gBattleBots[gBattleWork.unk88].unkC0 & 8)
        add = 0x28;
    else
        add = 0x14;
    v = gBattleBots[gBattleWork.unk88].unkC1 + add;
    if (v > 0x4F)
        v = 0x50;
    gBattleBots[gBattleWork.unk88].unkC1 = v;
}
