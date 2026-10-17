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

INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_080391C4);
INCLUDE_ASM("asm/nonmatching/code_08038D30", select_ai_action_type);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_080392D8);
INCLUDE_ASM("asm/nonmatching/code_08038D30", determine_battle_target_mode);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_080393BC);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_080393EC);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_08039448);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_080394C4);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_08039540);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_08039568);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_08039598);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_080395C0);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_080395E8);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_080396D4);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_080397B0);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_0803981C);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_080398AC);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_080399EC);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_08039A2C);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_08039AC8);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_08039BFC);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_08039CB4);
INCLUDE_ASM("asm/nonmatching/code_08038D30", sub_08039CF8);
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
