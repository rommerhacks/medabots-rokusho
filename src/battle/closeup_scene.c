// The action close-up scene: init_battle_closeup_scene and init_battle_scene_backgrounds set up the BG
// layers, setup_battle_medapart_scenes the acting parts, and battle_advance_dialogue_text /
// battle_advance_action_text step the message text. Called from battle/action_steps and action_script.

#include "global.h"

void init_battle_closeup_scene(void) {
    init_scene_buffers_080445F4();
    if (!(gUnk_03001800.unkF8 & 1)) {
        gUnk_03001800.unk154 = 0x3C;
        gUnk_03001800.unk114[0] = 0;
    } else {
        gUnk_03001800.unk154 = 0x12C;
        gUnk_03001800.unk114[0] = 0x28;
        gUnk_03001800.unkFF |= 1;
    }
    get_active_bot_part_index_and_load_values(0);
    gUnk_03001800.unk156 = 0x50;
    init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                   gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156,
                                   gUnk_03001800.unk39[3] + 2, 4, 0, 0, 0, gUnk_03001800.unk114[0]);
    if (!(gUnk_03001800.unkF8 & 1)) {
        gUnk_03001800.unk158 = 0x1C4;
        gUnk_03001800.unk114[1] = 0x28;
        gUnk_03001800.unkFF |= 2;
    } else {
        gUnk_03001800.unk158 = 0xB4;
        gUnk_03001800.unk114[1] = 0;
    }
    get_active_bot_part_index_and_load_values(1);
    gUnk_03001800.unk15A = 0x50;
    init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                   gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A,
                                   gUnk_03001800.unk39[3] + 2, 8, 1, 0, 1, gUnk_03001800.unk114[1]);
}

// The close-up scene parks a side outside x 0x128-0x1D0 when it is not shown.
static u32 closeup_x_on_screen(u32 x) {
    if (x - 0x128 <= 0xA8)
        return 0;
    return 1;
}

void init_battle_scene_backgrounds(void) {
    if (gUnk_03001800.unkFF & 1)
        gUnk_03000440.unk96 = 1;
    else
        gUnk_03000440.unk96 = 0;
    if (closeup_x_on_screen((s16)gUnk_03001800.unk154)) {
        get_active_bot_part_index_and_load_values(0);
        init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                       gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156,
                                       gUnk_03001800.unk39[3] + 2, 4, 0, 1, 0, gUnk_03001800.unk114[0]);
    }
    if (gUnk_03001800.unkFF & 2)
        gUnk_03000440.unk96 = 1;
    else
        gUnk_03000440.unk96 = 0;
    if (closeup_x_on_screen((s16)gUnk_03001800.unk158)) {
        get_active_bot_part_index_and_load_values(1);
        init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                       gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A,
                                       gUnk_03001800.unk39[3] + 2, 8, 1, 1, 1, gUnk_03001800.unk114[1]);
    }
    gUnk_03000440.unk96 = 0;
}

void setup_battle_medapart_scenes(void) {
    if (gUnk_03001800.unkFF & 1)
        gUnk_03000440.unk96 = 1;
    else
        gUnk_03000440.unk96 = 0;
    if (closeup_x_on_screen((s16)gUnk_03001800.unk154)) {
        get_active_bot_part_index_and_load_values(0);
        init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                       gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156,
                                       gUnk_03001800.unk39[3] + 2, 4, 0, 2, 0, gUnk_03001800.unk114[0]);
        init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                       gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156,
                                       gUnk_03001800.unk39[3] + 2, 4, 0, 1, 0, gUnk_03001800.unk114[0]);
    }
    if (gUnk_03001800.unkFF & 2)
        gUnk_03000440.unk96 = 1;
    else
        gUnk_03000440.unk96 = 0;
    if (closeup_x_on_screen((s16)gUnk_03001800.unk158)) {
        get_active_bot_part_index_and_load_values(1);
        init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                       gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A,
                                       gUnk_03001800.unk39[3] + 2, 8, 1, 2, 1, gUnk_03001800.unk114[1]);
        init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                       gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A,
                                       gUnk_03001800.unk39[3] + 2, 8, 1, 1, 1, gUnk_03001800.unk114[1]);
    }
    gUnk_03000440.unk96 = 0;
}

void get_active_bot_part_index_and_load_values(u32 side) {
    if (side == 0) {
        if (!(gUnk_03001800.unkF8 & 1))
            get_bot_part_effective_values(gUnk_03001800.unk87, gUnk_03001800.unk64);
        else if (gUnk_03001800.unkF6 & 2)
            get_bot_part_effective_values(gUnk_03001800.unk161, gUnk_03001800.unk64);
        else
            get_bot_part_effective_values(gUnk_03001800.unk88, gUnk_03001800.unk64);
    } else {
        if (!(gUnk_03001800.unkF8 & 1)) {
            if (gUnk_03001800.unkF6 & 2)
                get_bot_part_effective_values(gUnk_03001800.unk161, gUnk_03001800.unk64);
            else
                get_bot_part_effective_values(gUnk_03001800.unk88, gUnk_03001800.unk64);
        } else {
            get_bot_part_effective_values(gUnk_03001800.unk87, gUnk_03001800.unk64);
        }
    }
}

// r0 stays live through the function: it passes its (unused) argument through.
// guess: 0x29 is the starting pose/text state for both close-up sides.
u32 closeup_reset_text_states(passthrough)
u32 passthrough; // FAKEMATCH: returned unchanged to keep r0 live
{
    struct Unk_03001800 *b = &gUnk_03001800;
    b->unk112 = 0x29;
    b->unk113 = 0x29;
    return passthrough;
}

u32 battle_advance_dialogue_text(void) {
    struct Unk_03001800 *b = &gUnk_03001800;
    u8 *state = &b->unk112;
    u32 done;
    if (!(*state & 0x80) && !(b->unkFF & 1)) {
        get_active_bot_part_index_and_load_values(0);
        done = advance_text_display(0, *state, b->unk64[3]);
        if (done)
            b->unk112 |= 0x80;
        return done;
    }
    return 1;
}

u32 battle_advance_action_text(void) {
    struct Unk_03001800 *b = &gUnk_03001800;
    u8 *state = &b->unk113;
    u32 done;
    if (!(*state & 0x80) && !(b->unkFF & 2)) {
        get_active_bot_part_index_and_load_values(1);
        done = advance_text_display(1, *state, b->unk64[3]);
        if (done)
            b->unk113 |= 0x80;
        return done;
    }
    return 1;
}

// guess: per-side tally of successful actions, compared when TIME runs out (robattle_judge_time_up).
void side_add_action_point(void) {
    gUnk_03001800.unk28[gUnk_03001800.unk89].unk1++;
}

// The Medabot in unk88 gains 20 Medaforce (40 with unkC0 bit 3), up to the full 80.
void charge_target_medaforce(void) {
    u32 add;
    u32 v;
    if (gUnk_03000590[gUnk_03001800.unk88].unkC0 & 8)
        add = 0x28;
    else
        add = 0x14;
    v = gUnk_03000590[gUnk_03001800.unk88].unkC1 + add;
    if (v > 0x4F)
        v = 0x50;
    gUnk_03000590[gUnk_03001800.unk88].unkC1 = v;
}
