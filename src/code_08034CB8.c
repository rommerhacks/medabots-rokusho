#include "global.h"

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034CB8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034CD4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034CF0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034D0C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034D28);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034D44);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034D60);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034D7C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034D98);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034DB4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034DD0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034DEC);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034E08);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034E24);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034E40);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034E5C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034E78);

s32 sub_08034E94(void)
{
    const u8 *script = gUnk_083C6B28[gUnk_03001800.unkA8];
    return script[gUnk_03001800.unkBC];
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034EB8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034F08);

u32 sub_08034F44(u32 rec)
{
    u32 i;
    for (i = 0; i <= 2; i++)
        if (gUnk_03000590[rec].parts[i].data[1] == 0x15)
            return 1;
    return 0;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", battle_set_damage_vs_armor);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", set_target_sprite_position);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080350E0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", update_target_cursor_position);

void reduce_bot_part_stat(u32 rec, u32 part, s32 amount)
{
    if (gUnk_03000590[rec].parts[part].unk11 < amount)
        gUnk_03000590[rec].parts[part].unk11 = 0;
    else
        gUnk_03000590[rec].parts[part].unk11 -= amount;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035194);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080351E8);

void add_bot_to_defeated_list(u32 rec)
{
    u32 i;
    if (gUnk_03000590[rec].parts[0].unk11 == 0)
    {
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03001800.unkE0[i] == 0)
            {
                gUnk_03001800.unkE0[i] = rec + 1;
                return;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sprite_move_toward_target);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", update_sprite_deceleration);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803536C);

void sub_080353AC(u32 a)
{
    if (a & 2)
        gBg3Scroll.y = 2;
    else
        gBg3Scroll.y = 0;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080353CC);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", battle_sprite_blink_update);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035478);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", calc_bot_evasion_modifier);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", get_random_battle_weight_entry);

u32 sub_08035590(u32 rec)
{
    u32 n = gUnk_03000590[rec].parts[1].unk11 != 0;
    if (gUnk_03000590[rec].parts[2].unk11 != 0)
        n += 3;
    if (gUnk_03000590[rec].parts[3].unk11 != 0)
        n += 5;
    return n;
}

void sub_080355C4(u32 rec)
{
    gUnk_03001800.unk88 = gUnk_03000590[rec].unkE0 - 1;
    gUnk_03001800.unk8B = gUnk_03000590[rec].unkE1 - 1;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", move_sprite_toward_target);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_sprite_in_range);

void sub_08035694(u32 slot)
{
    gUnk_03002C30[slot].unk0 |= 0x200;
    gUnk_03002C30[slot].unk8 = 0x40;
    gUnk_03002C30[slot].unk9 = 0x40;
}

void sub_080356B4(u32 slot)
{
    gUnk_03002C30[slot].unk0 &= ~0x200;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_sprite_overlap_and_adjust);

void sub_0803572C(u8 *val, s32 amount)
{
    if (*val < amount)
        *val = 0;
    else
        *val -= amount;
}

void sub_08035740(u8 *val, u32 amount, u32 max)
{
    u32 sum = *val + amount;
    if (sum > max)
        *val = max;
    else
        *val = sum;
}

void sub_08035754(s16 *val, s32 amount)
{
    if (*val < amount)
        *val = 0;
    else
        *val -= amount;
}

u32 calc_bot_matching_part_power(u32 rec)
{
    u32 sum = 0;
    u32 i;
    for (i = 0; i <= 3; i++)
        if (gUnk_03000590[rec].medal.unk4 == gUnk_03000590[rec].parts[i].data[0])
            sum += gUnk_03000590[rec].medal.unk7;
    return sum;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", calc_battle_action_speed);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", apply_battle_bot_damage_reduction);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", accumulate_battle_speed_value);

u32 check_bot_ability_type_strike(u32 rec, u32 part, u32 target)
{
    if (gUnk_03000590[rec].parts[part].data[1] == 0x22 && gUnk_03000590[target].parts[3].data[1] == 0x64)
        return 1;
    return 0;
}

u32 check_bot_ability_type_shoot(u32 rec, u32 part, u32 target)
{
    if (gUnk_03000590[rec].parts[part].data[1] == 0x23 && gUnk_03000590[target].parts[3].data[1] == 0x6A)
        return 1;
    return 0;
}

void sub_080358F0(u32 rec)
{
    u32 i;
    for (i = 0; i <= 2; i++)
        if (gUnk_03000590[rec].parts[i].unk11 != 0 && gUnk_03000590[rec].parts[i].data[1] == 0x35)
            gUnk_03001800.unkE8 += gUnk_03000590[rec].parts[i].data[5];
}

void sub_08035928(u32 rec, u32 target)
{
    gUnk_03000590[rec].unkE0 = target;
    gUnk_03001800.unk88 = target - 1;
}

void sub_08035944(u32 rec, u32 part)
{
    gUnk_03000590[rec].unkE1 = part;
    gUnk_03001800.unk8B = part - 1;
}

u32 sub_08035960(u32 rec, u32 skill)
{
    u32 i;
    for (i = 0; i <= 3; i++)
        if (gUnk_03000590[rec].parts[i].unk11 != 0 && gUnk_03000590[rec].parts[i].data[1] == skill)
            return 1;
    return 0;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_bot_can_shoot);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_bot_can_support);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_bot_can_use_shoot_part);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_bot_status_effect_4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_can_target_bot);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_battle_can_support_target);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", check_battle_can_special_target);

void sub_08035B9C(u32 rec)
{
    u32 i;
    for (i = 0; i <= 2; i++)
        if (gUnk_03000590[rec].parts[i].unk11 != 0 && gUnk_03000590[rec].parts[i].data[1] == 0x35)
            gUnk_03001800.unkEC += gUnk_03000590[rec].parts[i].data[6];
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035BD4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035BFC);

void sub_08035C3C(void)
{
    u32 t = gUnk_03001800.unkF8 & 1;
    if (t)
    {
        gBg2Scroll.x = 0x110;
        gBg3Scroll.x = 0x110;
    }
    else
    {
        gBg2Scroll.x = t;
        gBg3Scroll.x = t;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08035C70);

u32 sub_08035DD4(u32 a)
{
    if (a - 0x128 <= 0xA8)
        return 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", init_battle_scene_backgrounds);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", setup_battle_medapart_scenes);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", get_active_bot_part_index_and_load_values);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080361A8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", battle_advance_dialogue_text);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", battle_advance_action_text);

void sub_08036270(void)
{
    gUnk_03001800.unk28[gUnk_03001800.unk89].unk1++;
}

void sub_0803628C(void)
{
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

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080362C4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036340);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036370);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080363E8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080364A8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080366DC);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036784);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803684C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080368C4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", setup_battle_sprite_oam_entries);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", advance_sprite_anim_frame);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", advance_sprite_group_anims);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036B50);

void sub_08036B84(u32 rec, u32 part)
{
    gUnk_03001800.unkC8 = gUnk_03000590[rec].parts[part].unk11;
    gUnk_03001800.unkCC = gUnk_03000590[rec].parts[part].unk11;
    gUnk_03001800.unkD1 = 1;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036BB8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036BF4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036C20);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", battle_calc_damage_split);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", battle_check_action_counter);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036D64);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", medal_update_exp_progress);

u32 sub_08036E54(u32 a)
{
    if (a > 99)
        a = 99;
    else if (a == 0)
        a = 1;
    return a;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", battle_set_action_params);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", reset_battle_bot_state);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", setup_battle_cursor_sprite_08036FF8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", update_sprite_animations_tick_080370AC);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803713C);

u32 sub_08037230(u32 rec, u32 part)
{
    if (gUnk_03000590[rec].parts[part].unk11 != 0
        && gUnk_03000590[rec].parts[part].unk11 != gUnk_03000590[rec].parts[part].data[4])
        return 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", decrement_battle_timer_and_check_zero);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", calc_battle_stat_ratio);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", battle_set_damage_display);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037330);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080373D4);

void sub_08037424(u32 slot)
{
    gUnk_03002C30[slot].unk4 = (gUnk_03002C30[slot].unk4 + gUnk_083AF4E0[gUnk_03002C30[slot].unk23]) & 0xFF;
    gUnk_03002C30[slot].unk23 = (gUnk_03002C30[slot].unk23 + 1) & 31;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037458);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037498);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080374E0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803752C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037578);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803769C);

void sub_080376F4(u32 rec)
{
    gUnk_03001800.unkEC = gUnk_03001800.unkE8 >> 3;
    gUnk_03001800.unkEC += gUnk_03000590[rec].unkA8[4];
    if (gUnk_03001800.unkEC == 0)
        gUnk_03001800.unkEC = 1;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037728);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037798);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", battle_select_random_target);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080378A8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080378F0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", spawn_battle_particle_effect);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037B9C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037BF4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037C50);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037E2C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803809C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080380F0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038178);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080381E0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038258);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080382F4);

void sub_0803836C(void)
{
    u32 i;
    for (i = 0; i <= 2; i++)
    {
        gUnk_03001800.unkD2[i] = 0;
        gUnk_03001800.unkD6[i] = 0;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038394);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080383E8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038428);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803858C);

void sub_080385D0(u32 rec)
{
    u32 i;
    struct Unk_03001800 *b;
    for (i = 0, b = &gUnk_03001800; i <= 5; i++)
    {
        if (b->unk45[i][0] == rec + 1)
        {
            b->unk45[i][0] = 0;
            b->unk45[i][1] = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080385F8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038650);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038700);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038804);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803884C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080388A4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038AC0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038BC0);
