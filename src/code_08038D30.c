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

void sub_080393BC(void)
{
    while (gUnk_03002C30[0].unk2A == 0)
        sub_080393EC();
    sub_0803B8C8();
    gUnk_03002C30[0].unk2A = 0;
}

void sub_080393EC(void)
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

void sub_0803981C(void)
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

void sub_080399EC(void)
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

INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_08039E00);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_08039FE4);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803A0B8);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803A0E0);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803A130);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803A264);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803A2E8);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803A310);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803A370);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803A444);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803A474);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803A5CC);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803A6FC);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803A760);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803A840);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803A920);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803A93C);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803AA00);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803AA90);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803AB00);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803AB9C);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803AC4C);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803ACB4);

void sub_0803ADE8(void)
{
    clear_battle_sprite_slot(0xC, 2);
    battle_advance_sequence_counter();
}

INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803ADFC);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803AF2C);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803B0C0);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803B19C);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803B1EC);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803B328);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803B374);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803B3C8);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803B428);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803B4F8);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803B5DC);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803B6D8);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803B700);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803B754);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803B884);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803B8C8);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803B900);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803B9A4);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803BBE0);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803BE44);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803C044);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803C0CC);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803C33C);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803C5F8);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803C680);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803C738);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803C7DC);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803C8AC);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803C9E0);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803CAB0);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803CB54);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803CBD0);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803CC40);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803CC8C);
