#include "global.h"

void sub_08038D30(void)
{
    gUnk_03000590[gUnk_03001800.unk88].unkBC &= 3;
    gUnk_03000590[gUnk_03001800.unk88].unkBD |= 2;
    if (gUnk_03001800.unkDE) {
        gUnk_03000590[gUnk_03001800.unk88].unkBC |= 0xC;
        gUnk_03001800.unkF2 = gUnk_03001800.unkE8;
        gUnk_03001800.unkAB = 1;
        if ((gUnk_03000590[gUnk_03001800.unk88].unkC0 & 1) && (rng_next_080424B8() & 1)) {
            gUnk_03001800.unkF6 = 1;
            gUnk_03001800.unkB7 = 3;
        }
    } else if (!(gUnk_03000590[gUnk_03001800.unk87].unkC0 & 4)
               && (gUnk_03000590[gUnk_03001800.unk88].unkBD & 0x10)
               && gUnk_03000590[gUnk_03001800.unk88].parts[gUnk_03000590[gUnk_03001800.unk88].unkDE - 1].unk11) {
        gUnk_03000590[gUnk_03001800.unk88].unkBC |= 0xC;
        gUnk_03001800.unkF2 = gUnk_03001800.unkE8;
        sub_08035944(gUnk_03001800.unk87, gUnk_03000590[gUnk_03001800.unk88].unkDE);
        gUnk_03001800.unkF6 = 1;
        gUnk_03001800.unkAB = 1;
    } else {
        gUnk_03001800.unkAB = 0;
    }
}

void battle_begin_action_phase(void)
{
    gUnk_03001800.unkEE = 0;
    if ((gUnk_03000590[gUnk_03001800.unk88].unkBC & 4) && (gUnk_03000590[gUnk_03001800.unk88].unkBC & 8))
        battle_calculate_damage_modifier();
    else if (!battle_calculate_turn_speed())
        battle_process_speed_and_action();
}

u32 battle_calculate_damage_modifier(void)
{
    u8 type;

    if (check_bot_ability_type_strike(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88)) {
        if (battle_check_damage_threshold(gUnk_03001800.unkEE))
            return 1;
        return 0;
    }
    if (check_bot_ability_type_shoot(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88)) {
        if (battle_check_damage_threshold(gUnk_03001800.unkEE))
            return 1;
        return 0;
    }
    type = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[2];
    if (type == 3) {
        if (battle_check_damage_threshold(gUnk_03001800.unkEE * 2))
            return 1;
        return 0;
    }
    if (type == 0) {
        if (battle_check_damage_threshold(gUnk_03001800.unkEE * 4))
            return 1;
        return 0;
    }
    if (battle_check_damage_threshold(gUnk_03001800.unkEE * 8))
        return 1;
    return 0;
}

u32 battle_check_damage_threshold(s16 v)
{
    if (gUnk_03001800.unkE8 > v) {
        gUnk_03001800.unkEE = 0;
        gUnk_03000590[gUnk_03001800.unk88].unkBC |= 0x4C;
        gUnk_03001800.unkF2 = gUnk_03001800.unkE8;
        return 1;
    }
    return 0;
}

u32 battle_calculate_turn_speed(void)
{
    gUnk_03001800.unkEE = 0;
    if (!(gUnk_03000590[gUnk_03001800.unk88].unkBC & 4)) {
        accumulate_battle_speed_value(gUnk_03001800.unk88);
        gUnk_03001800.unkEE += gUnk_03000590[gUnk_03001800.unk88].parts[3].unk13;
        if (!(gUnk_03000590[gUnk_03001800.unk88].unkBC & 8))
            sub_08035754((s16 *)&gUnk_03001800.unkEE, 8);
        if (battle_calculate_damage_modifier())
            return 1;
        sub_08035754(&gUnk_03001800.unkE8, (s16)gUnk_03001800.unkEE);
        if ((gUnk_03001800.unkF2 = gUnk_03001800.unkE8) == 0) {
            u8 type = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
            if (type == 6)
                return 0;
            if (type == 7)
                return 0;
            if (!(gUnk_03000590[gUnk_03001800.unk87].unkD6 & 2)) {
                gUnk_03000590[gUnk_03001800.unk88].unkBC |= 0x10;
                return 1;
            }
        }
    }
    return 0;
}

void battle_process_speed_and_action(void)
{
    u32 part;

    gUnk_03001800.unkEE = 0;
    gUnk_03001800.unkF2 = gUnk_03001800.unkE8;
    if (!(gUnk_03000590[gUnk_03001800.unk88].unkBC & 8)) {
        accumulate_battle_speed_value(gUnk_03001800.unk88);
        gUnk_03001800.unkEE += gUnk_03000590[gUnk_03001800.unk88].parts[3].unk14;
        if (!(gUnk_03000590[gUnk_03001800.unk88].unkBC & 4))
            sub_08035754((s16 *)&gUnk_03001800.unkEE, 8);
        if (!battle_calculate_damage_modifier() && (s16)gUnk_03001800.unkEE > 0x1F) {
            sub_08035754(&gUnk_03001800.unkE8, (s16)gUnk_03001800.unkEE);
            gUnk_03001800.unkF2 = gUnk_03001800.unkE8;
            gUnk_03000590[gUnk_03001800.unk88].unkBC |= 0x20;
            if (sub_08039134(gUnk_03001800.unk88) == 1)
                part = 1;
            else
                part = battle_find_strongest_part(gUnk_03001800.unk88);
            sub_08035944(gUnk_03001800.unk87, part);
        }
    }
}

u32 sub_08039134(u32 rec)
{
    u32 n = 0;
    u32 i;

    for (i = 0; i <= 3; i++)
        if (gUnk_03000590[rec].parts[i].unk11)
            n++;
    return n;
}

u32 battle_find_strongest_part(u32 rec)
{
    u32 best = 0;
    u32 i;
    u32 idx;

    for (i = 3; i != 0; i--) {
        u8 a = gUnk_03000590[rec].parts[i].unk11;
        if (a && a > best) {
            idx = i;
            best = a;
        }
    }
    return idx + 1;
}

void sub_08039188(void)
{
    u8 f = gUnk_03000590[gUnk_03001800.unk88].unkBC & 0x10;
    if (f) {
        gUnk_03001800.unkAB = 1;
        gUnk_03001800.unkB7 = 1;
    } else {
        gUnk_03001800.unkAB = f;
    }
}

void sub_080391C4(void)
{
    if (check_bot_can_shoot(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88)) {
        gUnk_03001800.unkB8 = 2;
        gUnk_03001800.unkBE = 2;
    } else if (check_bot_can_support(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88)) {
        gUnk_03001800.unkB8 = 2;
        gUnk_03001800.unkBE = 3;
    } else if (check_bot_can_use_shoot_part(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88)) {
        gUnk_03001800.unkB8 = 2;
        gUnk_03001800.unkBE = 4;
    } else if (check_bot_status_effect_4(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88)) {
        gUnk_03001800.unkB8 = 2;
        gUnk_03001800.unkBE = 6;
    }
}

void select_ai_action_type(void)
{
    if (check_bot_can_shoot(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk87)) {
        gUnk_03001800.unkB8 = 2;
        gUnk_03001800.unkBE = 2;
    } else if (check_bot_can_support(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk87)) {
        gUnk_03001800.unkB8 = 2;
        gUnk_03001800.unkBE = 3;
    } else if (check_bot_can_use_shoot_part(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk87)) {
        gUnk_03001800.unkB8 = 2;
        gUnk_03001800.unkBE = 4;
    } else if (check_bot_status_effect_4(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk87)) {
        gUnk_03001800.unkB8 = 2;
        gUnk_03001800.unkBE = 6;
    }
}

void sub_080392D8(void)
{
    if (check_can_target_bot(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88)) {
        gUnk_03001800.unkB8 = 4;
        gUnk_03001800.unkBF = 2;
    } else if (check_battle_can_support_target(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88)) {
        gUnk_03001800.unkB8 = 4;
        gUnk_03001800.unkBF = 3;
    } else if (check_battle_can_special_target(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk88)) {
        gUnk_03001800.unkB8 = 4;
        gUnk_03001800.unkBF = 4;
    }
}

void determine_battle_target_mode(void)
{
    if (check_can_target_bot(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk87)) {
        gUnk_03001800.unkB8 = 4;
        gUnk_03001800.unkBF = 2;
    } else if (check_battle_can_support_target(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk87)) {
        gUnk_03001800.unkB8 = 4;
        gUnk_03001800.unkBF = 3;
    } else if (check_battle_can_special_target(gUnk_03001800.unk87, gUnk_03001800.unkA7, gUnk_03001800.unk87)) {
        gUnk_03001800.unkB8 = 4;
        gUnk_03001800.unkBF = 4;
    }
}

void battle_sequence_update(void)
{
    while (gUnk_03002C30[0].unk2A == 0)
        battle_sequence_run_command();
    sub_0803B8C8();
    gUnk_03002C30[0].unk2A = 0;
}

void battle_sequence_run_command(void)
{
    s8 *p;
    if ((s8)(gUnk_03002C30[0].unk29 = sub_0803D424()) < 0) {
        p = (s8 *)&gUnk_03002C30[0].unk29;
        do {
            battle_advance_sequence_counter();
            *p = sub_0803D424();
        } while (*p < 0);
    }
    gUnk_083AF740[gUnk_03002C30[0].unk29]();
}

// guess: ends the battle sequence (yields and sets the step-done flag unkB5)
void sub_08039430(void)
{
    gUnk_03002C30[0].unk2A = 1;
    gUnk_03001800.unkB5 = 1;
}

void sub_08039448(void)
{
    const s16 *seq;
    vu8 done = 0;

    load_battle_sequence_commands();
    battle_advance_sequence_counter();
    while (!done) {
        seq = gUnk_083CDFE4[gUnk_03001800.unkF9];
        if (gUnk_03001800.unk102[0] == seq[gUnk_03001800.unk100]) {
            battle_advance_sequence_counter();
            done = 1;
        } else {
            battle_advance_sequence_counter();
        }
    }
}

void sub_080394C4(void)
{
    const s16 *seq;
    vu8 done = 0;

    load_battle_sequence_commands();
    battle_advance_sequence_counter();
    while (!done) {
        seq = gUnk_083CDFE4[gUnk_03001800.unkF9];
        if (gUnk_03001800.unk102[gUnk_03001800.unkFD] == seq[gUnk_03001800.unk100]) {
            battle_advance_sequence_counter();
            done = 1;
        } else {
            battle_advance_sequence_counter();
        }
    }
}

void sub_08039540(void)
{
    if (gUnk_03001800.unkB7 == 1)
        gUnk_03001800.unkFD = 1;
    else
        gUnk_03001800.unkFD = 0;
    battle_advance_sequence_counter();
}

void sub_08039568(void)
{
    if (gUnk_03001800.unkF6 & 1)
        gUnk_03001800.unkFD = 1;
    else
        gUnk_03001800.unkFD = gUnk_03001800.unkF6 & 1;
    battle_advance_sequence_counter();
}

void sub_08039598(void)
{
    if (gUnk_03001800.unkB8 == 2)
        gUnk_03001800.unkFD = 1;
    else
        gUnk_03001800.unkFD = 0;
    battle_advance_sequence_counter();
}

void sub_080395C0(void)
{
    if (gUnk_03001800.unkB8 == 4)
        gUnk_03001800.unkFD = 1;
    else
        gUnk_03001800.unkFD = 0;
    battle_advance_sequence_counter();
}

void sub_080395E8(void)
{
    load_battle_sequence_commands();
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[1].unk2B = 1;
        if (gUnk_03001800.unkF6 & 2)
            gUnk_03002C30[1].unk2C = gUnk_03001800.unk102[gUnk_03001800.unk162 + 1];
        else
            gUnk_03002C30[1].unk2C = gUnk_03001800.unk102[gUnk_03001800.unkA7 + 1];
        gUnk_03002C30[1].unk30 = gUnk_03001800.unk102[0];
        gUnk_03002C30[1].unk2D = 0;
    } else {
        gUnk_03002C30[2].unk2B = 1;
        if (gUnk_03001800.unkF6 & 2)
            gUnk_03002C30[2].unk2C = gUnk_03001800.unk102[gUnk_03001800.unk162 + 4];
        else
            gUnk_03002C30[2].unk2C = gUnk_03001800.unk102[gUnk_03001800.unkA7 + 4];
        gUnk_03002C30[2].unk30 = gUnk_03001800.unk102[0];
        gUnk_03002C30[2].unk2D = 0;
    }
    battle_advance_sequence_counter();
}

// guess: yields until the next frame without advancing
void sub_080396C4(void)
{
    gUnk_03002C30[0].unk2A = 1;
}

void sub_080396D4(void)
{
    load_battle_sequence_commands();
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[2].unk2B = 1;
        if (gUnk_03001800.unkF6 & 2)
            gUnk_03002C30[2].unk2C = gUnk_03001800.unk102[gUnk_03001800.unk162 + 4];
        else
            gUnk_03002C30[2].unk2C = gUnk_03001800.unk102[gUnk_03001800.unkA7 + 4];
        gUnk_03002C30[2].unk30 = gUnk_03001800.unk102[0];
        gUnk_03002C30[2].unk2D = 0;
    } else {
        gUnk_03002C30[1].unk2B = 1;
        if (gUnk_03001800.unkF6 & 2)
            gUnk_03002C30[1].unk2C = gUnk_03001800.unk102[gUnk_03001800.unk162 + 1];
        else
            gUnk_03002C30[1].unk2C = gUnk_03001800.unk102[gUnk_03001800.unkA7 + 1];
        gUnk_03002C30[1].unk30 = gUnk_03001800.unk102[0];
        gUnk_03002C30[1].unk2D = 0;
    }
    battle_advance_sequence_counter();
}

void sub_080397B0(void)
{
    u8 f;

    load_battle_sequence_commands();
    gUnk_03002C30[3].unk2B = gUnk_03001800.unk102[0];
    f = gUnk_03001800.unkF8 & 2;
    if (!f) {
        gUnk_03002C30[3].unk2C = f;
        gUnk_03002C30[3].unk30 = gUnk_03001800.unk154;
    } else {
        gUnk_03002C30[3].unk2C = 1;
        gUnk_03002C30[3].unk30 = gUnk_03001800.unk158;
    }
    gUnk_03002C30[3].unk29 = 8;
    battle_advance_sequence_counter();
}

void battle_seq_cmd_wait_text(void)
{
    load_battle_sequence_commands();
    switch (gUnk_03001800.unk102[0]) {
    case 0:
        if (!(gUnk_03001800.unkF8 & 2)) {
            if (gUnk_03001800.unk15F)
                battle_advance_sequence_counter();
        } else {
            if (gUnk_03001800.unk160)
                battle_advance_sequence_counter();
        }
        break;
    case 1:
        if (gUnk_03001800.unkF8 & 2) {
            if (gUnk_03001800.unk15F)
                battle_advance_sequence_counter();
        } else {
            if (gUnk_03001800.unk160)
                battle_advance_sequence_counter();
        }
        break;
    default:
        if (gUnk_03001800.unk15F && gUnk_03001800.unk160)
            battle_advance_sequence_counter();
        break;
    }
    gUnk_03002C30[0].unk2A = 1;
}

void sub_080398AC(void)
{
    u32 skill;
    u32 t;

    load_battle_sequence_commands();
    if (gUnk_03000590[gUnk_03001800.unk87].unkDD <= 3)
        skill = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
    else
        skill = gUnk_03000590[gUnk_03001800.unk87].unkA8[0] + 0x50;
    load_battle_entity_palette(skill, gUnk_03001800.unk102[4], 9);
    gUnk_03002C30[4].unk2E = gUnk_03001800.unk102[0];
    gUnk_03002C30[4].unk2F = gUnk_03001800.unk102[1];
    gUnk_03002C30[4].unk2B = gUnk_03001800.unk102[6];
    gUnk_03002C30[4].unk30 = gUnk_03001800.unk102[5];
    gUnk_03002C30[4].unk29 = 0x10;
    init_game_state_entry(gUnk_083CEC74[gUnk_03002C30[4].unk2B], 0, 0);
    gUnk_03002C30[4].unk4 = gUnk_03001800.unk102[3];
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[4].unk2 = gUnk_03001800.unk102[2];
        gUnk_03002C30[4].unk2C = gUnk_03001800.unk102[7];
    } else {
        t = gUnk_03002C30[4].unk2E >> 1;
        gUnk_03002C30[4].unk2 = 0x1E - t - (gUnk_03001800.unk102[2] + t);
        gUnk_03002C30[4].unk2C = gUnk_03001800.unk102[7] + 2;
    }
    gUnk_03002C30[4].unk2D = 0;
    battle_advance_sequence_counter();
}

void battle_seq_cmd_wait_frames(void)
{
    load_battle_sequence_commands();
    if (gUnk_03002C30[0].unk30 != gUnk_03001800.unk102[0]) {
        gUnk_03002C30[0].unk30++;
    } else {
        gUnk_03002C30[0].unk30 = 0;
        battle_advance_sequence_counter();
    }
    gUnk_03002C30[0].unk2A = 1;
}

void sub_08039A2C(void)
{
    load_battle_sequence_commands();
    gUnk_03002C30[gUnk_03001800.unk102[0] + 5].unk30 = gUnk_03001800.unk102[1];
    gUnk_03002C30[gUnk_03001800.unk102[0] + 5].unk2B = gUnk_03001800.unk102[2];
    gUnk_03002C30[gUnk_03001800.unk102[0] + 5].unk2C = 0;
    gUnk_03002C30[gUnk_03001800.unk102[0] + 5].unk2D = gUnk_03001800.unk102[3];
    gUnk_03002C30[gUnk_03001800.unk102[0] + 5].unk2E = gUnk_03001800.unk102[4];
    gUnk_03002C30[gUnk_03001800.unk102[0] + 5].unk29 = 0x18;
    battle_advance_sequence_counter();
}

void sub_08039AC8(void)
{
    u32 i;
    const u8 *set;

    load_battle_sequence_commands();
    gUnk_03002C30[gUnk_03001800.unk102[0] + 5].unk30 = gUnk_03001800.unk102[1];
    gUnk_03002C30[gUnk_03001800.unk102[0] + 5].unk2C = 0;
    gUnk_03002C30[gUnk_03001800.unk102[0] + 5].unk2D = gUnk_03001800.unk102[3];
    gUnk_03002C30[gUnk_03001800.unk102[0] + 5].unk2E = gUnk_03001800.unk102[4];
    gUnk_03002C30[gUnk_03001800.unk102[0] + 5].unk29 = 0x18;
    if (gUnk_03001800.unkF6 & 2)
        get_bot_part_effective_values(gUnk_03001800.unk161, gUnk_03001800.unk64);
    else
        get_bot_part_effective_values(gUnk_03001800.unk87, gUnk_03001800.unk64);
    if (gUnk_03001800.unk64[3] > 0x77)
        i = 3;
    else if (gUnk_03001800.unkF6 & 2)
        i = gUnk_03000590[gUnk_03001800.unk161].parts[3].data[1] - 0x64;
    else
        i = gUnk_03000590[gUnk_03001800.unk87].parts[3].data[1] - 0x64;
    set = gUnk_083AF888[gUnk_03001800.unk102[2]];
    gUnk_03002C30[gUnk_03001800.unk102[0] + 5].unk2B = set[i];
    battle_advance_sequence_counter();
}

void sub_08039BFC(void)
{
    u8 f;

    load_battle_sequence_commands();
    gUnk_03002C30[3].unk24 = gUnk_03001800.unk102[0];
    gUnk_03002C30[3].unk2D = gUnk_03001800.unk102[2];
    f = gUnk_03001800.unkF8 & 2;
    if (!f) {
        gUnk_03002C30[3].unk2C = f;
        gUnk_03002C30[3].unk25 = gUnk_03001800.unk102[1];
        gUnk_03002C30[3].unk2 = gUnk_03001800.unk154;
        gUnk_03002C30[3].unk4 = gUnk_03001800.unk156;
    } else {
        gUnk_03002C30[3].unk2C = 1;
        gUnk_03002C30[3].unk25 = (0x20 - (u8)gUnk_03001800.unk102[1]) & 0x1F;
        gUnk_03002C30[3].unk2 = gUnk_03001800.unk158;
        gUnk_03002C30[3].unk4 = gUnk_03001800.unk15A;
    }
    gUnk_03002C30[3].unk29 = 9;
    battle_advance_sequence_counter();
}

void sub_08039CB4(void)
{
    u8 f = gUnk_03000590[gUnk_03001800.unk88].unkBC & 0x20;
    if (f)
        gUnk_03001800.unkFD = 1;
    else
        gUnk_03001800.unkFD = f;
    battle_advance_sequence_counter();
}

void sub_08039CF8(void)
{
    u32 t;

    load_battle_sequence_commands();
    load_battle_entity_palette(0x3C, gUnk_03001800.unk102[4], 9);
    gUnk_03002C30[4].unk2E = gUnk_03001800.unk102[0];
    gUnk_03002C30[4].unk2F = gUnk_03001800.unk102[1];
    gUnk_03002C30[4].unk2B = gUnk_03001800.unk102[6];
    gUnk_03002C30[4].unk30 = gUnk_03001800.unk102[5];
    gUnk_03002C30[4].unk29 = 0x10;
    init_game_state_entry(gUnk_083CEC74[gUnk_03002C30[4].unk2B], 0, 0);
    gUnk_03002C30[4].unk4 = gUnk_03001800.unk102[3];
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[4].unk2 = gUnk_03001800.unk102[2];
        gUnk_03002C30[4].unk2C = gUnk_03001800.unk102[7];
    } else {
        t = gUnk_03002C30[4].unk2E >> 1;
        gUnk_03002C30[4].unk2 = 0x1E - t - (gUnk_03001800.unk102[2] + t);
        gUnk_03002C30[4].unk2C = gUnk_03001800.unk102[7] + 2;
    }
    gUnk_03002C30[4].unk2D = 0;
    battle_advance_sequence_counter();
}

void sub_08039E00(void)
{
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03001800.unk154 = 0x12C;
        gUnk_03001800.unk156 = 0x50;
        get_active_bot_part_index_and_load_values(0);
        init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2], gUnk_03001800.unk64[3],
            (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156, gUnk_03001800.unk39[3] + 2, 4, 0, 2, 0, gUnk_03001800.unk114[0]);
        init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2], gUnk_03001800.unk64[3],
            (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156, gUnk_03001800.unk39[3] + 2, 4, 0, 1, 0, gUnk_03001800.unk114[0]);
        gUnk_03001800.unk112 = 0x29;
        advance_text_display(0, 0x29, gUnk_03001800.unk64[3]);
    } else {
        gUnk_03001800.unk158 = 0x1C4;
        gUnk_03001800.unk15A = 0x50;
        get_active_bot_part_index_and_load_values(1);
        init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2], gUnk_03001800.unk64[3],
            (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A, gUnk_03001800.unk39[3] + 2, 8, 1, 2, 1, gUnk_03001800.unk114[1]);
        init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2], gUnk_03001800.unk64[3],
            (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A, gUnk_03001800.unk39[3] + 2, 8, 1, 1, 1, gUnk_03001800.unk114[1]);
        gUnk_03001800.unk113 = 0x29;
        advance_text_display(1, 0x29, gUnk_03001800.unk64[3]);
    }
    battle_advance_sequence_counter();
}

void sub_08039FE4(void)
{
    load_battle_sequence_commands();
    clear_battle_sprite_slot(0x1E, 1);
    gUnk_03002C30[0x1E].unk2B = gUnk_03001800.unk102[0];
    gUnk_03002C30[0x1E].unk4 = gUnk_03001800.unk102[2];
    gUnk_03002C30[0x1E].unk24 = gUnk_03001800.unk102[4];
    gUnk_03002C30[0x1E].unk29 = 10;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[0x1E].unk2 = gUnk_03001800.unk102[1];
        gUnk_03002C30[0x1E].unk25 = gUnk_03001800.unk102[3];
    } else {
        gUnk_03002C30[0x1E].unk2 = 0xF0 - gUnk_03001800.unk102[1];
        gUnk_03002C30[0x1E].unk25 = (0x20 - (u8)gUnk_03001800.unk102[3]) & 0x1F;
    }
    gUnk_03002C30[0x1E].unk30 = gUnk_03002C30[0x1E].unk2;
    battle_advance_sequence_counter();
}

void sub_0803A0B8(void)
{
    if (!gUnk_03002C30[0x1E].unk29)
        battle_advance_sequence_counter();
    gUnk_03002C30[0].unk2A = 1;
}

void sub_0803A0E0(void)
{
    load_battle_sequence_commands();
    lz_decompress_dispatch(gUnk_083AF88C[gUnk_03001800.unk102[0] * 2], (void *)0x06010000);
    CpuFastSet(gUnk_083AF88C[gUnk_03001800.unk102[0] * 2 + 1], (void *)0x050003C0, 8);
    battle_advance_sequence_counter();
}

void sub_0803A130(void)
{
    u32 i;
    u32 slot;

    load_battle_sequence_commands();
    for (i = 0; i <= 8; i++) {
        if (gUnk_03002C30[i + 10].unk0 == 0) {
            slot = i + 10;
            break;
        }
    }
    clear_battle_sprite_slot(slot, 1);
    gUnk_03002C30[slot].unk0 = (gUnk_03001800.unk102[6] << 10) | 0x4004;
    gUnk_03002C30[slot].unk1C = 0;
    gUnk_03002C30[slot].unkA = 0xE;
    gUnk_03002C30[slot].unkB = 0x80;
    gUnk_03002C30[slot].unk2D = gUnk_03001800.unk102[7];
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03002C30[slot].unk2D], slot);
    gUnk_03002C30[slot].unk2B = gUnk_03001800.unk102[0];
    gUnk_03002C30[slot].unk4 = gUnk_03001800.unk102[2];
    gUnk_03002C30[slot].unk24 = gUnk_03001800.unk102[4];
    gUnk_03002C30[slot].unk2C = gUnk_03001800.unk102[5];
    gUnk_03002C30[slot].unk29 = 0xB;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[slot].unk2 = gUnk_03001800.unk102[1];
        gUnk_03002C30[slot].unk25 = gUnk_03001800.unk102[3];
    } else {
        gUnk_03002C30[slot].unk0 |= 0x1000;
        gUnk_03002C30[slot].unk2 = 0xF0 - gUnk_03001800.unk102[1];
        gUnk_03002C30[slot].unk25 = (0x20 - (u8)gUnk_03001800.unk102[3]) & 0x1F;
    }
    battle_advance_sequence_counter();
}

void sub_0803A264(void)
{
    load_battle_sequence_commands();
    if (!(gUnk_03001800.unkF8 & 2)) {
        if (gUnk_03002C30[gUnk_03001800.unk102[1]].unk2 >= gUnk_03001800.unk102[0])
            battle_advance_sequence_counter();
    } else {
        if (gUnk_03002C30[gUnk_03001800.unk102[1]].unk2 <= 0xF0 - gUnk_03001800.unk102[0])
            battle_advance_sequence_counter();
    }
    gUnk_03002C30[0].unk2A = 1;
}

void sub_0803A2E8(void)
{
    load_battle_sequence_commands();
    clear_battle_sprite_slot(gUnk_03001800.unk102[0], gUnk_03001800.unk102[1]);
    battle_advance_sequence_counter();
}

void sub_0803A310(void)
{
    s32 n;

    load_battle_sequence_commands();
    n = gUnk_03001800.unk102[2];
    gUnk_03002C30[n].unkA = gUnk_03001800.unk102[4];
    gUnk_03002C30[n].unk2D = gUnk_03001800.unk102[1];
    gUnk_03002C30[n].unk2B = gUnk_03001800.unk102[0];
    gUnk_03002C30[n].unk29 = 0x20;
    gUnk_03002C30[n].unk2E = gUnk_03001800.unk102[3];
    battle_advance_sequence_counter();
}

void sub_0803A370(void)
{
    load_battle_sequence_commands();
    clear_battle_sprite_slot(0x1E, 1);
    gUnk_03002C30[0x1E].unk2B = gUnk_03001800.unk102[0];
    gUnk_03002C30[0x1E].unk4 = gUnk_03001800.unk102[2];
    gUnk_03002C30[0x1E].unk24 = gUnk_03001800.unk102[4];
    gUnk_03002C30[0x1E].unk29 = 12;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[0x1E].unk2 = gUnk_03001800.unk102[1];
        gUnk_03002C30[0x1E].unk25 = gUnk_03001800.unk102[3];
    } else {
        gUnk_03002C30[0x1E].unk2 = 0xF0 - gUnk_03001800.unk102[1];
        gUnk_03002C30[0x1E].unk25 = (0x20 - (u8)gUnk_03001800.unk102[3]) & 0x1F;
    }
    gUnk_03002C30[0x1E].unk30 = gUnk_03002C30[0x1E].unk2;
    battle_advance_sequence_counter();
}

void sub_0803A444(void)
{
    REG_BG0CNT = 0x4500;
    tilemap_fill_rect(0x40, 0x20, 0, 0, REG_BG0CNT, 0);
    battle_advance_sequence_counter();
}

void sub_0803A474(void)
{
    u32 skill;
    u32 t;

    load_battle_sequence_commands();
    clear_battle_sprite_slot(0x23, 1);
    if (gUnk_03000590[gUnk_03001800.unk87].unkDD <= 3)
        skill = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
    else
        skill = gUnk_03000590[gUnk_03001800.unk87].unkA8[0] + 0x50;
    load_battle_entity_palette(skill, gUnk_03001800.unk102[4], 9);
    gUnk_03002C30[0x23].unk2E = gUnk_03001800.unk102[0];
    gUnk_03002C30[0x23].unk2F = gUnk_03001800.unk102[1];
    gUnk_03002C30[0x23].unk2B = gUnk_03001800.unk102[6];
    gUnk_03002C30[0x23].unk30 = gUnk_03001800.unk102[5];
    gUnk_03002C30[0x23].unk29 = 0x11;
    init_game_state_entry(gUnk_083CEC74[gUnk_03002C30[0x23].unk2B], 1, 1);
    gUnk_03002C30[0x23].unk4 = gUnk_03001800.unk102[3];
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[0x23].unk2 = gUnk_03001800.unk102[2];
        gUnk_03002C30[0x23].unk2C = gUnk_03001800.unk102[7];
    } else {
        t = gUnk_03002C30[0x23].unk2E >> 1;
        gUnk_03002C30[0x23].unk2 = (s16)(0x1E - t - (gUnk_03001800.unk102[2] + t)) - 1;
        gUnk_03002C30[0x23].unk2C = gUnk_03001800.unk102[7] + 2;
    }
    gUnk_03002C30[0x23].unk2D = 0;
    gUnk_03002C30[0x23].unk28 = 0;
    battle_advance_sequence_counter();
}

void sub_0803A5CC(void)
{
    u32 skill;

    load_battle_sequence_commands();
    if (gUnk_03000590[gUnk_03001800.unk87].unkDD <= 3)
        skill = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
    else
        skill = gUnk_03000590[gUnk_03001800.unk87].unkA8[0] + 0x50;
    load_battle_entity_palette(skill, gUnk_03001800.unk102[4], 9);
    gUnk_03002C30[4].unk2E = gUnk_03001800.unk102[0];
    gUnk_03002C30[4].unk2F = gUnk_03001800.unk102[1];
    gUnk_03002C30[4].unk2B = gUnk_03001800.unk102[6];
    gUnk_03002C30[4].unk30 = gUnk_03001800.unk102[5];
    gUnk_03002C30[4].unk29 = 0x12;
    init_game_state_entry(gUnk_083CEC74[gUnk_03002C30[4].unk2B], 0, 0);
    gUnk_03002C30[4].unk4 = 4;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[4].unk2 = gUnk_03001800.unk102[2];
        gUnk_03002C30[4].unk2C = gUnk_03001800.unk102[7];
    } else {
        gUnk_03002C30[4].unk2 = gUnk_03001800.unk102[3];
        gUnk_03002C30[4].unk2C = gUnk_03001800.unk102[7] + 2;
    }
    gUnk_03002C30[4].unk2D = 0;
    battle_advance_sequence_counter();
}

void sub_0803A6FC(void)
{
    tilemap_fill_rect(0x20, 0x20, 0, 0, REG_BG0CNT, 0);
    tilemap_fill_rect(0x20, 0x20, 0x20, 0, REG_BG0CNT, 0);
    REG_BG0CNT = 0x500;
    gBg0Scroll.x = 0;
    gBg1Scroll.x = 0;
    clear_battle_sprite_slot(4, 1);
    clear_battle_sprite_slot(0x23, 1);
    battle_advance_sequence_counter();
}

void sub_0803A760(void)
{
    load_battle_sequence_commands();
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[1].unk2B = 1;
        if (gUnk_03001800.unkF6 & 2)
            gUnk_03002C30[1].unk2C = gUnk_03001800.unk102[gUnk_03001800.unk162 + 1];
        else
            gUnk_03002C30[1].unk2C = gUnk_03001800.unk102[gUnk_03001800.unkA7 + 1];
        gUnk_03002C30[1].unk30 = gUnk_03001800.unk102[0];
        gUnk_03002C30[1].unk2D = 1;
    } else {
        gUnk_03002C30[2].unk2B = 1;
        if (gUnk_03001800.unkF6 & 2)
            gUnk_03002C30[2].unk2C = gUnk_03001800.unk102[gUnk_03001800.unk162 + 4];
        else
            gUnk_03002C30[2].unk2C = gUnk_03001800.unk102[gUnk_03001800.unkA7 + 4];
        gUnk_03002C30[2].unk30 = gUnk_03001800.unk102[0];
        gUnk_03002C30[2].unk2D = 1;
    }
    battle_advance_sequence_counter();
}

void sub_0803A840(void)
{
    load_battle_sequence_commands();
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[2].unk2B = 1;
        if (gUnk_03001800.unkF6 & 2)
            gUnk_03002C30[2].unk2C = gUnk_03001800.unk102[gUnk_03001800.unk162 + 4];
        else
            gUnk_03002C30[2].unk2C = gUnk_03001800.unk102[gUnk_03001800.unkA7 + 4];
        gUnk_03002C30[2].unk30 = gUnk_03001800.unk102[0];
        gUnk_03002C30[2].unk2D = 1;
    } else {
        gUnk_03002C30[1].unk2B = 1;
        if (gUnk_03001800.unkF6 & 2)
            gUnk_03002C30[1].unk2C = gUnk_03001800.unk102[gUnk_03001800.unk162 + 1];
        else
            gUnk_03002C30[1].unk2C = gUnk_03001800.unk102[gUnk_03001800.unkA7 + 1];
        gUnk_03002C30[1].unk30 = gUnk_03001800.unk102[0];
        gUnk_03002C30[1].unk2D = 1;
    }
    battle_advance_sequence_counter();
}

void sub_0803A920(void)
{
    gUnk_03002C30[0x23].unk27 = 1;
    battle_advance_sequence_counter();
}

void sub_0803A93C(void)
{
    u32 i;
    u32 slot;

    load_battle_sequence_commands();
    for (i = 0; i < 2; i++) {
        if (gUnk_03002C30[i + 0xC].unk29 == 0) {
            slot = i + 0xC;
            break;
        }
    }
    clear_battle_sprite_slot(slot, 1);
    gUnk_03002C30[slot].unk2B = gUnk_03001800.unk102[0];
    gUnk_03002C30[slot].unk2E = gUnk_03001800.unk102[1];
    gUnk_03002C30[slot].unk30 = gUnk_03001800.unk102[2];
    gUnk_03002C30[slot].unk32 = gUnk_03001800.unk102[3];
    gUnk_03002C30[slot].unk2C = gUnk_03001800.unk102[4];
    gUnk_03002C30[slot].unk2D = gUnk_03001800.unk102[5];
    gUnk_03002C30[slot].unk27 = gUnk_03001800.unk102[6];
    gUnk_03002C30[slot].unk28 = 0;
    gUnk_03002C30[slot].unk29 = 0x22;
    battle_advance_sequence_counter();
}

void sub_0803AA00(void)
{
    load_battle_sequence_commands();
    if (!(gUnk_03001800.unkF8 & 2))
        gUnk_03002C30[gUnk_03001800.unk102[0]].unk25 = gUnk_03001800.unk102[1];
    else
        gUnk_03002C30[gUnk_03001800.unk102[0]].unk25 = (0x20 - (u8)gUnk_03001800.unk102[1]) & 0x1F;
    gUnk_03002C30[gUnk_03001800.unk102[0]].unk24 = gUnk_03001800.unk102[2];
    battle_advance_sequence_counter();
}

void sub_0803AA90(void)
{
    load_battle_sequence_commands();
    if (gUnk_03001800.unk102[1] != 0)
        gUnk_03002C30[gUnk_03001800.unk102[0]].unk0 ^= 0x1000;
    if (gUnk_03001800.unk102[2] != 0)
        gUnk_03002C30[gUnk_03001800.unk102[0]].unk0 ^= 0x2000;
    battle_advance_sequence_counter();
}

void sub_0803AB00(void)
{
    load_battle_sequence_commands();
    if (gUnk_03001800.unk102[0] == 0) {
        copy_obj_palette_to_buffer();
        gUnk_03002C30[0x27].unk2F = 0;
        gUnk_03002C30[0x27].unk29 = 0x28;
    } else {
        gUnk_03002C30[0x27].unk29 = 0x29;
    }
    gUnk_03002C30[0x27].unk2B = gUnk_03001800.unk102[1];
    gUnk_03002C30[0x27].unk2C = gUnk_03001800.unk102[2];
    gUnk_03002C30[0x27].unk2D = gUnk_03001800.unk102[3];
    gUnk_03002C30[0x27].unk2E = gUnk_03001800.unk102[4];
    battle_advance_sequence_counter();
}

void sub_0803AB9C(void)
{
    if (!(gUnk_03001800.unkF8 & 2)) {
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
    battle_advance_sequence_counter();
}

void sub_0803AC4C(void)
{
    load_battle_sequence_commands();
    if (gUnk_03001800.unk102[0] == 0)
        CpuFastSet((void *)(gUnk_03001800.unk102[1] * 32 + 0x05000000), (void *)(gUnk_03001800.unk102[1] * 32 + 0x0202FA00), 8);
    else
        CpuFastSet((void *)(gUnk_03001800.unk102[1] * 32 + 0x05000200), (void *)(gUnk_03001800.unk102[1] * 32 + 0x0202F800), 8);
    battle_advance_sequence_counter();
}

void sub_0803ACB4(void)
{
    u32 i;
    u32 slot;

    load_battle_sequence_commands();
    for (i = 0; i < 9; i++) {
        if (gUnk_03002C30[i + 0xA].unk0 == 0) {
            slot = i + 0xA;
            break;
        }
    }
    clear_battle_sprite_slot(slot, 1);
    gUnk_03002C30[slot].unk0 = (gUnk_03001800.unk102[6] << 10) | 0x4004;
    gUnk_03002C30[slot].unk1C = 0;
    gUnk_03002C30[slot].unkA = 0xE;
    gUnk_03002C30[slot].unkB = 0x80;
    gUnk_03002C30[slot].unk2D = gUnk_03001800.unk102[7];
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03002C30[slot].unk2D], slot);
    gUnk_03002C30[slot].unk2B = gUnk_03001800.unk102[0];
    gUnk_03002C30[slot].unk4 = gUnk_03001800.unk102[2];
    gUnk_03002C30[slot].unk24 = gUnk_03001800.unk102[4];
    gUnk_03002C30[slot].unk2C = gUnk_03001800.unk102[5];
    gUnk_03002C30[slot].unk29 = 0xD;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[slot].unk2 = gUnk_03001800.unk102[1];
        gUnk_03002C30[slot].unk25 = gUnk_03001800.unk102[3];
    } else {
        gUnk_03002C30[slot].unk0 |= 0x1000;
        gUnk_03002C30[slot].unk2 = 0xF0 - gUnk_03001800.unk102[1];
        gUnk_03002C30[slot].unk25 = (0x20 - (u8)gUnk_03001800.unk102[3]) & 0x1F;
    }
    battle_advance_sequence_counter();
}

void sub_0803ADE8(void)
{
    clear_battle_sprite_slot(0xC, 2);
    battle_advance_sequence_counter();
}

void sub_0803ADFC(void)
{
    u32 skill;

    load_battle_sequence_commands();
    if (gUnk_03000590[gUnk_03001800.unk87].unkDD <= 3)
        skill = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
    else
        skill = gUnk_03000590[gUnk_03001800.unk87].unkA8[0] + 0x50;
    load_battle_entity_palette(skill, gUnk_03001800.unk102[4], 9);
    gUnk_03002C30[4].unk2E = gUnk_03001800.unk102[0];
    gUnk_03002C30[4].unk2F = gUnk_03001800.unk102[1];
    gUnk_03002C30[4].unk2B = gUnk_03001800.unk102[6];
    gUnk_03002C30[4].unk30 = gUnk_03001800.unk102[5];
    gUnk_03002C30[4].unk29 = 0x13;
    init_game_state_entry(gUnk_083CEC74[gUnk_03002C30[4].unk2B], 0, 0);
    gUnk_03002C30[4].unk4 = 4;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[4].unk2 = gUnk_03001800.unk102[2];
        gUnk_03002C30[4].unk2C = gUnk_03001800.unk102[7];
    } else {
        gUnk_03002C30[4].unk2 = gUnk_03001800.unk102[3];
        gUnk_03002C30[4].unk2C = (u8)gUnk_03001800.unk102[7] + 2;
    }
    gUnk_03002C30[4].unk2D = 0;
    battle_advance_sequence_counter();
}

void sub_0803AF2C(void)
{
    u32 i;
    struct Coords16 v;

    load_battle_sequence_commands();
    gUnk_03002C30[0xA].unk2B = gUnk_03001800.unk102[0];
    gUnk_03002C30[0xA].unk4 = gUnk_03001800.unk102[2];
    gUnk_03002C30[0xA].unk24 = gUnk_03001800.unk102[4];
    gUnk_03002C30[0xA].unk2C = gUnk_03001800.unk102[5];
    gUnk_03002C30[0xA].unk29 = 0x30;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[0xA].unk2 = gUnk_03001800.unk102[1];
        gUnk_03002C30[0xA].unk25 = gUnk_03001800.unk102[3];
    } else {
        gUnk_03002C30[0xA].unk2 = 0xF0 - gUnk_03001800.unk102[1];
        gUnk_03002C30[0xA].unk25 = (0x20 - (u8)gUnk_03001800.unk102[3]) & 0x1F;
    }
    for (i = 0; i < 4; i++) {
        gUnk_03002C30[i + 0xB].unk0 = (gUnk_03001800.unk102[6] << 10) | 0x4004;
        gUnk_03002C30[i + 0xB].unk1C = 0;
        gUnk_03002C30[i + 0xB].unkA = 0xE;
        gUnk_03002C30[i + 0xB].unkB = 0x80;
        gUnk_03002C30[i + 0xB].unk2D = gUnk_03001800.unk102[7];
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03002C30[i + 0xB].unk2D], i + 0xB);
        gUnk_03002C30[i + 0xB].unk2B = gUnk_03001800.unk102[0];
        gUnk_03002C30[i + 0xB].unk2C = gUnk_03001800.unk102[5];
        gUnk_03002C30[i + 0xB].unk29 = 0x31;
        v = calc_polar_to_screen_coords(i * 64, 0x10, gUnk_03002C30[0xA].unk2, gUnk_03002C30[0xA].unk4);
        gUnk_03002C30[i + 0xB].unk2 = v.x;
        gUnk_03002C30[i + 0xB].unk4 = v.y;
        gUnk_03002C30[i + 0xB].unk26 = i * 64 - 0x20;
    }
    battle_advance_sequence_counter();
}

void sub_0803B0C0(void)
{
    u32 i;
    const struct Unk_083AF94C *tbl;
    struct Unk_03001800 *b;
    u8 *f;

    load_battle_sequence_commands();
    i = 0;
    b = &gUnk_03001800;
    f = &b->unkF8;
    tbl = gUnk_083AF94C;
    do {
        gUnk_03002C30[i + 0xA].unk0 = 0xC004;
        gUnk_03002C30[i + 0xA].unk1C = 0;
        gUnk_03002C30[i + 0xA].unk4 = tbl->y;
        gUnk_03002C30[i + 0xA].unkA = 0xE;
        gUnk_03002C30[i + 0xA].unkB = 0x80;
        gUnk_03002C30[i + 0xA].unk2C = b->unk102[0];
        gUnk_03002C30[i + 0xA].unk2B = b->unk102[0];
        gUnk_03002C30[i + 0xA].unk25 = b->unk102[1];
        gUnk_03002C30[i + 0xA].unk24 = b->unk102[2];
        gUnk_03002C30[i + 0xA].unk29 = 0xB;
        gUnk_03002C30[i + 0xA].unk2D = b->unk102[3];
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03002C30[i + 0xA].unk2D], i + 0xA);
        if (!(*f & 2))
            gUnk_03002C30[i + 0xA].unk2 = tbl->x;
        else
            gUnk_03002C30[i + 0xA].unk2 = (0xF6 - tbl->x) & 0x1FF;
        tbl++;
        i++;
    } while (i < 4);
    battle_advance_sequence_counter();
}

void sub_0803B19C(void)
{
    load_battle_sequence_commands();
    sub_08044B28(gUnk_083AF95C[gUnk_03001800.unk102[0] * 2], (void *)0x02000000);
    CpuFastSet(gUnk_083AF95C[gUnk_03001800.unk102[0] * 2 + 1], (void *)0x050003C0, 8);
    battle_advance_sequence_counter();
}

void sub_0803B1EC(void)
{
    u32 i;
    u32 slot;

    load_battle_sequence_commands();
    for (i = 0; i < 9; i++) {
        if (gUnk_03002C30[i + 0xA].unk0 == 0) {
            slot = i + 0xA;
            break;
        }
    }
    clear_battle_sprite_slot(slot, 1);
    gUnk_03002C30[slot].unk0 = (gUnk_03001800.unk102[6] << 10) | 0x4004;
    gUnk_03002C30[slot].unk1C = 0;
    gUnk_03002C30[slot].unkA = 0xE;
    gUnk_03002C30[slot].unkB = 0x80;
    gUnk_03002C30[slot].unk2D = gUnk_03001800.unk102[7];
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03002C30[slot].unk2D], slot);
    gUnk_03002C30[slot].unk2B = gUnk_03001800.unk102[0];
    gUnk_03002C30[slot].unk4 = gUnk_03001800.unk102[2];
    gUnk_03002C30[slot].unk24 = gUnk_03001800.unk102[4];
    gUnk_03002C30[slot].unk2C = gUnk_03001800.unk102[5];
    gUnk_03002C30[slot].unk29 = 0xE;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[slot].unk2 = gUnk_03001800.unk102[1];
        gUnk_03002C30[slot].unk25 = gUnk_03001800.unk102[3];
    } else {
        gUnk_03002C30[slot].unk0 |= 0x1000;
        gUnk_03002C30[slot].unk2 = 0xF0 - gUnk_03001800.unk102[1];
        gUnk_03002C30[slot].unk25 = (0x20 - (u8)gUnk_03001800.unk102[3]) & 0x1F;
    }
    battle_advance_sequence_counter();
}

void sub_0803B328(void)
{
    load_battle_sequence_commands();
    gUnk_03002C30[gUnk_03001800.unk102[1]].unk2E = gUnk_03001800.unk102[0];
    sub_0801BF78(gUnk_083CEC74[gUnk_03001800.unk102[0]], 0, 0);
    battle_advance_sequence_counter();
}

void sub_0803B374(void)
{
    if (gUnk_03000590[gUnk_03001800.unk87].unkDD <= 3)
        decompress_indexed_graphics_to_ewram(gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1]);
    else
        decompress_indexed_graphics_to_ewram(gUnk_03000590[gUnk_03001800.unk87].unkA8[0] + 0x50);
    battle_advance_sequence_counter();
}

void sub_0803B3C8(void)
{
    load_battle_sequence_commands();
    lz_decompress_dispatch(gUnk_083AF88C[gUnk_03001800.unk102[0] * 2], (void *)(gUnk_03001800.unk102[1] * 32 + 0x06010000));
    CpuFastSet(gUnk_083AF88C[gUnk_03001800.unk102[0] * 2 + 1], (void *)0x050003C0, 8);
    battle_advance_sequence_counter();
}

void sub_0803B428(void)
{
    load_battle_sequence_commands();
    gUnk_03002C30[gUnk_03001800.unk102[0]].unk0 |= 0x200;
    gUnk_03002C30[gUnk_03001800.unk102[0]].unk8 = gUnk_03001800.unk102[4];
    gUnk_03002C30[gUnk_03001800.unk102[0]].unk9 = gUnk_03001800.unk102[5];
    gUnk_03002C30[gUnk_03001800.unk102[0]].unk18 = 0;
    gUnk_03002C30[gUnk_03001800.unk102[0]].unk26 = gUnk_03001800.unk102[3];
    gUnk_03002C30[gUnk_03001800.unk102[0]].unk2D = gUnk_03001800.unk102[2];
    gUnk_03002C30[gUnk_03001800.unk102[0]].unk23 = gUnk_03001800.unk102[1];
    gUnk_03002C30[gUnk_03001800.unk102[0]].unk29 = 0x34;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03002C30[gUnk_03001800.unk102[0]].unk2D], gUnk_03001800.unk102[0]);
    battle_advance_sequence_counter();
}

void sub_0803B4F8(void)
{
    u32 i;
    struct Coords16 v;

    load_battle_sequence_commands();
    for (i = 0; i < 8; i++) {
        gUnk_03002C30[i + 0xB].unk0 = 0xC604;
        gUnk_03002C30[i + 0xB].unk1C = 0;
        v = calc_polar_to_screen_coords(i * 32, gUnk_03001800.unk102[3], gUnk_03002C30[gUnk_03001800.unk102[0]].unk2, gUnk_03002C30[gUnk_03001800.unk102[0]].unk4);
        gUnk_03002C30[i + 0xB].unk2 = v.x;
        gUnk_03002C30[i + 0xB].unk4 = v.y;
        gUnk_03002C30[i + 0xB].unk8 = 8;
        gUnk_03002C30[i + 0xB].unk9 = 8;
        gUnk_03002C30[i + 0xB].unkA = 0xE;
        gUnk_03002C30[i + 0xB].unkB = 0x80;
        gUnk_03002C30[i + 0xB].unk29 = 0x36;
        gUnk_03002C30[i + 0xB].unk26 = i * 32;
        gUnk_03002C30[i + 0xB].unk27 = gUnk_03001800.unk102[3];
        gUnk_03002C30[i + 0xB].unk2B = 0;
        gUnk_03002C30[i + 0xB].unk23 = gUnk_03001800.unk102[1];
        gUnk_03002C30[i + 0xB].unk2D = gUnk_03001800.unk102[2];
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03002C30[i + 0xB].unk2D], i + 0xB);
    }
    battle_advance_sequence_counter();
}

void sub_0803B5DC(void)
{
    u8 mirrored;

    load_battle_sequence_commands();
    lz_decompress_dispatch(gUnk_084C4F00, (void *)0x06006400);
    lz_decompress_dispatch(gUnk_084882F4, (void *)0x06006520);
    lz_decompress_dispatch(gUnk_084C3648, (void *)0x06006600);
    lz_decompress_dispatch(gUnk_084C65C8, (void *)0x06006800);
    CpuFastSet(gUnk_08488B24, (void *)0x05000140, 8);
    CpuFastSet(gUnk_084E3098, (void *)0x05000100, 8);
    CpuFastSet(gUnk_084C6A58, (void *)0x05000160, 8);
    mirrored = gUnk_03001800.unkF8 & 2;
    if (mirrored == 0)
        gUnk_03002C30[9].unk2D = mirrored;
    else
        gUnk_03002C30[9].unk2D = 1;
    gUnk_03002C30[9].unk2E = 1;
    gUnk_03002C30[9].unk2B = gUnk_03001800.unk102[0];
    gUnk_03002C30[9].unk2C = gUnk_03001800.unk102[1];
    gUnk_03002C30[9].unk29 = 0x38;
    battle_advance_sequence_counter();
}

void sub_0803B6D8(void)
{
    if (gUnk_03002C30[9].unk29 == 0)
        battle_advance_sequence_counter();
    gUnk_03002C30[0].unk2A = 1;
}

void sub_0803B700(void)
{
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG1CNT, 0);
    clear_battle_sprite_slot(4, 1);
    clear_battle_sprite_slot(0x23, 1);
    battle_advance_sequence_counter();
}

void sub_0803B754(void)
{
    u32 skill;

    load_battle_sequence_commands();
    if (gUnk_03000590[gUnk_03001800.unk87].unkDD <= 3)
        skill = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
    else
        skill = gUnk_03000590[gUnk_03001800.unk87].unkA8[0] + 0x50;
    load_battle_entity_palette(skill, gUnk_03001800.unk102[4], 9);
    gUnk_03002C30[4].unk2E = gUnk_03001800.unk102[0];
    gUnk_03002C30[4].unk2F = gUnk_03001800.unk102[1];
    gUnk_03002C30[4].unk2B = gUnk_03001800.unk102[6];
    gUnk_03002C30[4].unk30 = gUnk_03001800.unk102[5];
    gUnk_03002C30[4].unk29 = 0x10;
    init_game_state_entry(gUnk_083CEC74[gUnk_03002C30[4].unk2B], 0, 0);
    gUnk_03002C30[4].unk4 = gUnk_03001800.unk102[3];
    gUnk_03002C30[4].unk2C = gUnk_03001800.unk102[7];
    if (!(gUnk_03001800.unkF8 & 2))
        gUnk_03002C30[4].unk2 = gUnk_03001800.unk102[2];
    else
        gUnk_03002C30[4].unk2 = 0x1E - (gUnk_03002C30[4].unk2E >> 1) - (gUnk_03001800.unk102[2] + (gUnk_03002C30[4].unk2E >> 1));
    gUnk_03002C30[4].unk2D = 0;
    battle_advance_sequence_counter();
}

void sub_0803B884(void)
{
    u32 i;

    for (i = 0; i < 2; i++) {
        gUnk_03002C30[i + 0xA].unk28 = (&gUnk_03001800.unk188)[i];
        gUnk_03002C30[i + 0xA].unk23 = 0;
        gUnk_03002C30[i + 0xA].unk29 = 0x3A;
        gUnk_03002C30[i + 0xA].unk26 = i + 0x56;
    }
    play_sound_effect(0x10);
    battle_advance_sequence_counter();
}

void sub_0803B8C8(void)
{
    u32 i;

    for (i = 0; i <= 0x26; i++) {
        gUnk_0300056F = i + 1;
        gUnk_083AF96C[gUnk_03002C30[i + 1].unk29]();
    }
}

void sub_0803B900(void)
{
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2B != 0) {
        if (gUnk_03000440.unk12F == 1) {
            if (gUnk_03001800.unk15F != 0) {
                gUnk_03002C30[gUnk_03000440.unk12F].unk2B = 0;
                if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D != 0) {
                    gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
                    gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
                } else {
                    gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
                }
            }
        } else if (gUnk_03001800.unk160 != 0) {
            gUnk_03002C30[gUnk_03000440.unk12F].unk2B = 0;
            if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D != 0) {
                gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
                gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
            } else {
                gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
            }
        }
    }
}

void sub_0803B9A4(void)
{
    if (gUnk_03002C30[gUnk_0300056F].unk30 != 0) {
        gUnk_03002C30[gUnk_0300056F].unk30--;
        return;
    }
    if (gUnk_0300056F == 1) {
        if (gUnk_03001800.unkFF & 1) {
            get_active_bot_part_index_and_load_values(0);
            init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156,
                gUnk_03001800.unk39[3] + 2, 4, 0, 0, 0, gUnk_03001800.unk114[0]);
            init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156,
                gUnk_03001800.unk39[3] + 2, 4, 0, 1, 0, gUnk_03001800.unk114[0]);
        }
        gUnk_03001800.unkFF &= ~1;
        gUnk_03001800.unk112 = gUnk_03002C30[gUnk_0300056F].unk2C;
    } else {
        if (gUnk_03001800.unkFF & 2) {
            get_active_bot_part_index_and_load_values(1);
            init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A,
                gUnk_03001800.unk39[3] + 2, 8, 1, 0, 1, gUnk_03001800.unk114[1]);
            init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A,
                gUnk_03001800.unk39[3] + 2, 8, 1, 1, 1, gUnk_03001800.unk114[1]);
        }
        gUnk_03001800.unkFF &= ~2;
        gUnk_03001800.unk113 = gUnk_03002C30[gUnk_0300056F].unk2C;
    }
    gUnk_03002C30[gUnk_03000440.unk12F].unk29 = 1;
}

INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803BBE0);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803BE44);

void sub_0803C044(void)
{
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D != 0) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk2D--;
        update_sprite_animation_position(gUnk_03000440.unk12F);
        if (gUnk_03002C30[3].unk2C == 0) {
            gUnk_03001800.unk154 = gUnk_03002C30[gUnk_03000440.unk12F].unk2;
            gUnk_03001800.unk156 = gUnk_03002C30[gUnk_03000440.unk12F].unk4;
        } else {
            gUnk_03001800.unk158 = gUnk_03002C30[gUnk_03000440.unk12F].unk2;
            gUnk_03001800.unk15A = gUnk_03002C30[gUnk_03000440.unk12F].unk4;
        }
    } else {
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
    }
}

INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803C0CC);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803C33C);

void sub_0803C5F8(void)
{
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2C != 0) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk2C--;
    } else {
        gUnk_03002C30[gUnk_03000440.unk12F].unk0 |= 0x8000;
        process_sprite_anim_commands(gUnk_083B5F80[gUnk_03002C30[gUnk_03000440.unk12F].unk2D], gUnk_03000440.unk12F);
    }
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2B != 0)
        gUnk_03002C30[gUnk_03000440.unk12F].unk2B--;
    else
        update_sprite_animation_position(gUnk_03000440.unk12F);
}

void sub_0803C680(void)
{
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2C != 0) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk2C--;
    } else {
        gUnk_03002C30[gUnk_03000440.unk12F].unk0 |= 0x8000;
        process_sprite_anim_commands(gUnk_083B5F80[gUnk_03002C30[gUnk_03000440.unk12F].unk2D], gUnk_03000440.unk12F);
    }
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2B != 0) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk2B--;
    } else {
        update_sprite_animation_position(gUnk_03000440.unk12F);
        gUnk_03002C30[gUnk_03000440.unk12F].unk4 += gUnk_083AFAB8[gUnk_03002C30[gUnk_03000440.unk12F].unk23];
        gUnk_03002C30[gUnk_03000440.unk12F].unk23 = (gUnk_03002C30[gUnk_03000440.unk12F].unk23 + 1) & 0x1F;
    }
}

void sub_0803C738(void)
{
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2C != 0) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk2C--;
    } else {
        gUnk_03002C30[gUnk_03000440.unk12F].unk0 |= 0x8000;
        process_sprite_anim_commands(gUnk_083B5F80[gUnk_03002C30[gUnk_03000440.unk12F].unk2D], gUnk_03000440.unk12F);
        sub_0801BFB4(gUnk_083CEC74[gUnk_03002C30[gUnk_03000440.unk12F].unk2E], 0);
    }
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2B != 0)
        gUnk_03002C30[gUnk_03000440.unk12F].unk2B--;
    else
        update_sprite_animation_position(gUnk_03000440.unk12F);
}

void sub_0803C7DC(void)
{
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk30 != 0) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk30--;
        return;
    }
    process_animation_script(gUnk_083CEC74[gUnk_03002C30[gUnk_03000440.unk12F].unk2B], 0);
    if (gUnk_03000440.unk64[0].unk2 == 0xFF) {
        vram_fill_tilemap_rect(gUnk_03002C30[gUnk_03000440.unk12F].unk2E, gUnk_03002C30[gUnk_03000440.unk12F].unk2F,
            gUnk_03002C30[gUnk_03000440.unk12F].unk2, gUnk_03002C30[gUnk_03000440.unk12F].unk4, REG_BG0CNT, 0);
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
    } else if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D == 0) {
        write_tilemap_rect(gUnk_03002C30[gUnk_03000440.unk12F].unk2E, gUnk_03002C30[gUnk_03000440.unk12F].unk2F,
            gUnk_03002C30[gUnk_03000440.unk12F].unk2, gUnk_03002C30[gUnk_03000440.unk12F].unk4,
            gUnk_083B4AE0[gUnk_03002C30[gUnk_03000440.unk12F].unk2C], REG_BG0CNT, 0);
    }
}

void sub_0803C8AC(void)
{
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk30 != 0) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk30--;
        return;
    }
    process_animation_script(gUnk_083CEC74[gUnk_03002C30[gUnk_03000440.unk12F].unk2B], 1);
    gUnk_03002C30[gUnk_03000440.unk12F].unk28++;
    if ((gUnk_03002C30[gUnk_03000440.unk12F].unk28 & 1) && gUnk_03002C30[gUnk_03000440.unk12F].unk27 == 0) {
        if (!(gUnk_03001800.unkF8 & 2))
            write_tilemap_to_vram_0803F1C8(gUnk_03002C30[gUnk_03000440.unk12F].unk2E, gUnk_03002C30[gUnk_03000440.unk12F].unk2F,
                (gUnk_03002C30[gUnk_03000440.unk12F].unk2 + gUnk_03002C30[gUnk_03000440.unk12F].unk2D) & 0x3F,
                gUnk_03002C30[gUnk_03000440.unk12F].unk4,
                gUnk_083B4AE0[gUnk_03002C30[gUnk_03000440.unk12F].unk2C], REG_BG0CNT, 0);
        else
            write_tilemap_to_vram_0803F1C8(gUnk_03002C30[gUnk_03000440.unk12F].unk2E, gUnk_03002C30[gUnk_03000440.unk12F].unk2F,
                (gUnk_03002C30[gUnk_03000440.unk12F].unk2 - gUnk_03002C30[gUnk_03000440.unk12F].unk2D) & 0x3F,
                gUnk_03002C30[gUnk_03000440.unk12F].unk4,
                gUnk_083B4AE0[gUnk_03002C30[gUnk_03000440.unk12F].unk2C], REG_BG0CNT, 0);
        gUnk_03002C30[gUnk_03000440.unk12F].unk2D++;
    }
}

void sub_0803C9E0(void)
{
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk30 != 0) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk30--;
        return;
    }
    process_animation_script(gUnk_083CEC74[gUnk_03002C30[gUnk_03000440.unk12F].unk2B], 0);
    if (gUnk_03000440.unk64[0].unk2 == 0xFF) {
        tilemap_fill_rect(gUnk_03002C30[gUnk_03000440.unk12F].unk2E, gUnk_03002C30[gUnk_03000440.unk12F].unk2F,
            gUnk_03002C30[gUnk_03000440.unk12F].unk2, gUnk_03002C30[gUnk_03000440.unk12F].unk4, REG_BG0CNT, 0);
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
    } else if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D == 0) {
        write_tilemap_to_vram_0803F1C8(gUnk_03002C30[gUnk_03000440.unk12F].unk2E, gUnk_03002C30[gUnk_03000440.unk12F].unk2F,
            gUnk_03002C30[gUnk_03000440.unk12F].unk2, gUnk_03002C30[gUnk_03000440.unk12F].unk4,
            gUnk_083B4AE0[gUnk_03002C30[gUnk_03000440.unk12F].unk2C], REG_BG0CNT, 0);
    }
}

void sub_0803CAB0(void)
{
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk30 != 0) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk30--;
        return;
    }
    process_animation_script(gUnk_083CEC74[gUnk_03002C30[gUnk_03000440.unk12F].unk2B], 0);
    if (gUnk_03000440.unk64[0].unk2 == 0xFF) {
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
    } else if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D == 0) {
        write_tilemap_to_vram_0803F1C8(gUnk_03002C30[gUnk_03000440.unk12F].unk2E, gUnk_03002C30[gUnk_03000440.unk12F].unk2F,
            gUnk_03002C30[gUnk_03000440.unk12F].unk2, gUnk_03002C30[gUnk_03000440.unk12F].unk4,
            gUnk_083B4AE0[gUnk_03002C30[gUnk_03000440.unk12F].unk2C], REG_BG0CNT, 0);
    }
}

void sub_0803CB54(void)
{
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk30 != 0) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk30--;
    } else if (gUnk_03002C30[gUnk_03000440.unk12F].unk2C != 0) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk2C--;
    } else if (gUnk_03002C30[gUnk_03000440.unk12F].unk2E != 0) {
        play_sound_effect(gUnk_03002C30[gUnk_03000440.unk12F].unk2B);
        gUnk_03002C30[gUnk_03000440.unk12F].unk2C = gUnk_03002C30[gUnk_03000440.unk12F].unk2D;
        gUnk_03002C30[gUnk_03000440.unk12F].unk2E--;
    } else {
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
    }
}

void sub_0803CBD0(void)
{
    u8 n;

    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2B != 0) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk2B--;
        return;
    }
    n = gUnk_03002C30[gUnk_03000440.unk12F].unk2E;
    gUnk_03002C30[n].unkA = gUnk_03002C30[gUnk_03000440.unk12F].unkA;
    gUnk_03002C30[n].unk2D = gUnk_03002C30[gUnk_03000440.unk12F].unk2D;
    gUnk_03002C30[n].unk29 = 0x21;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03002C30[n].unk2D], n);
    clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
}

void sub_0803CC40(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03002C30[gUnk_03000440.unk12F].unk2D], gUnk_03000440.unk12F);
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk22 == 0xFF)
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
}

void sub_0803CC8C(void)
{
    u32 n;

    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2B != 0) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk2B--;
        return;
    }
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk28 != gUnk_03002C30[gUnk_03000440.unk12F].unk2C) {
        gUnk_03002C30[gUnk_03000440.unk12F].unk28++;
        return;
    }
    gUnk_03002C30[gUnk_03000440.unk12F].unk28 = 0;
    n = find_next_free_sprite_slot(0xE, 0x10);
    gUnk_03002C30[n].unk0 = 0xC404;
    gUnk_03002C30[n].unk1C = 0;
    if (!(gUnk_03001800.unkF8 & 2))
        gUnk_03002C30[n].unk2 = (gUnk_03002C30[gUnk_03002C30[gUnk_03000440.unk12F].unk2E].unk2 + gUnk_03002C30[gUnk_03000440.unk12F].unk30) & 0x1FF;
    else
        gUnk_03002C30[n].unk2 = (gUnk_03002C30[gUnk_03002C30[gUnk_03000440.unk12F].unk2E].unk2 + (gUnk_03002C30[gUnk_03000440.unk12F].unk30 * -1)) & 0x1FF;
    gUnk_03002C30[n].unk4 = (gUnk_03002C30[gUnk_03002C30[gUnk_03000440.unk12F].unk2E].unk4 + gUnk_03002C30[gUnk_03000440.unk12F].unk32) & 0xFF;
    gUnk_03002C30[n].unkA = gUnk_03002C30[gUnk_03000440.unk12F].unk27;
    gUnk_03002C30[n].unkB = 0x80;
    gUnk_03002C30[n].unk29 = 0x23;
    gUnk_03002C30[n].unk2D = gUnk_03002C30[gUnk_03000440.unk12F].unk2D;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03002C30[gUnk_03000440.unk12F].unk2D], n);
}

