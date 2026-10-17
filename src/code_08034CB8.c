#include "global.h"

void sub_08034CB8(void)
{
    sub_0802A6AC();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08034CD4(void)
{
    sub_0802AAD0();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08034CF0(void)
{
    sub_0802ACCC();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08034D0C(void)
{
    sub_0802B000();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08034D28(void)
{
    sub_0802B7E8();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08034D44(void)
{
    sub_0802BD6C();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08034D60(void)
{
    sub_0802C2AC();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08034D7C(void)
{
    sub_0802C644();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08034D98(void)
{
    sub_0802CBE8();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08034DB4(void)
{
    sub_0802D688();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08034DD0(void)
{
    sub_0802DCB4();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08034DEC(void)
{
    battle_dispatch_phase_handler_0802E424();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08034E08(void)
{
    sub_0802EBC0();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08034E24(void)
{
    sub_0802F030();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08034E40(void)
{
    sub_0802F628();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08034E5C(void)
{
    sub_0802F990();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

void sub_08034E78(void)
{
    sub_0802FE50();
    if (gUnk_03001800.unkB5)
        sub_08034F08();
}

s32 sub_08034E94(void)
{
    const u8 *script = gUnk_083C6B28[gUnk_03001800.unkA8];
    return script[gUnk_03001800.unkBC];
}

void sub_08034EB8(void)
{
    const u8 *script = gUnk_083C6B28[gUnk_03001800.unkA8];
    u32 n = gUnk_083C6D38[script[gUnk_03001800.unkBC]];
    u32 i;
    for (i = 0; i < n; i++)
        gUnk_03001800.unkAC[i] = script[gUnk_03001800.unkBC + i + 1];
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08034F08);

u32 sub_08034F44(u32 rec)
{
    u32 i;
    for (i = 0; i <= 2; i++)
        if (gUnk_03000590[rec].parts[i].data[1] == 0x15)
            return 1;
    return 0;
}

void battle_set_damage_vs_armor(u32 rec, u32 part, s32 amount)
{
    s32 armor = gUnk_03000590[rec].parts[part].unk11;
    if (armor > amount)
    {
        gUnk_03001800.unkC8 = amount;
        gUnk_03001800.unkCC = amount;
        gUnk_03001800.unkCA = 0;
        gUnk_03001800.unkD1 = 0;
    }
    else
    {
        gUnk_03001800.unkC8 = armor;
        gUnk_03001800.unkCC = armor;
        gUnk_03001800.unkCA = amount - armor;
        gUnk_03001800.unkD1 = 1;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", set_target_sprite_position);

void sub_080350E0(u32 rec)
{
    gUnk_03002C30[rec * 4 + 0x5A].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2;
    gUnk_03002C30[rec * 4 + 0x5A].unk4 = gUnk_03002C30[rec * 4 + 0x5D].unk4 - 8;
    gUnk_03002C30[rec * 4 + 0x5B].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 8;
    gUnk_03002C30[rec * 4 + 0x5B].unk4 = gUnk_03002C30[rec * 4 + 0x5D].unk4;
    gUnk_03002C30[rec * 4 + 0x5C].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 + 8;
    gUnk_03002C30[rec * 4 + 0x5C].unk4 = gUnk_03002C30[rec * 4 + 0x5D].unk4;
}

void update_target_cursor_position(u32 rec)
{
    gUnk_03002C30[rec * 4 + 0x5D].unk2 = gUnk_03001800.unk13C[rec].x;
    gUnk_03002C30[rec * 4 + 0x5D].unk4 = gUnk_03001800.unk13C[rec].y + 4;
    sub_080350E0(rec);
}

void reduce_bot_part_stat(u32 rec, u32 part, s32 amount)
{
    if (gUnk_03000590[rec].parts[part].unk11 < amount)
        gUnk_03000590[rec].parts[part].unk11 = 0;
    else
        gUnk_03000590[rec].parts[part].unk11 -= amount;
}

void sub_08035194(u32 rec)
{
    if (gUnk_03000590[rec].parts[3].unk11 == 0)
    {
        gUnk_03000590[rec].parts[3].unk12 = gUnk_03000590[rec].parts[3].data[5] >> 1;
        gUnk_03000590[rec].parts[3].unk13 = gUnk_03000590[rec].parts[3].data[6] >> 1;
        gUnk_03000590[rec].parts[3].unk14 = gUnk_03000590[rec].parts[3].data[7] >> 1;
        gUnk_03000590[rec].parts[3].unk15 = gUnk_03000590[rec].parts[3].data[8] >> 1;
        gUnk_03000590[rec].parts[3].unk16 = gUnk_03000590[rec].parts[3].data[9] >> 1;
    }
}

void sub_080351E8(u32 rec)
{
    if (gUnk_03000590[rec].parts[3].unk11 != 0)
    {
        gUnk_03000590[rec].parts[3].unk12 = gUnk_03000590[rec].parts[3].data[5];
        gUnk_03000590[rec].parts[3].unk13 = gUnk_03000590[rec].parts[3].data[6];
        gUnk_03000590[rec].parts[3].unk14 = gUnk_03000590[rec].parts[3].data[7];
        gUnk_03000590[rec].parts[3].unk15 = gUnk_03000590[rec].parts[3].data[8];
        gUnk_03000590[rec].parts[3].unk16 = gUnk_03000590[rec].parts[3].data[9];
    }
}

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

void sub_0803536C(u32 slot, u32 frame, u32 y)
{
    switch ((frame & 6) >> 1)
    {
    case 1:
        gUnk_03002C30[slot].unk2 = y + 1;
        break;
    case 3:
        gUnk_03002C30[slot].unk2 = y - 1;
        break;
    default:
        gUnk_03002C30[slot].unk2 = y;
        break;
    }
}

void sub_080353AC(u32 a)
{
    if (a & 2)
        gBg3Scroll.y = 2;
    else
        gBg3Scroll.y = 0;
}

u32 sub_080353CC(u32 slot)
{
    if ((gUnk_03002C30[slot].unk0 & 0x8000) && gUnk_03002C30[slot].unk23 != 0x20)
    {
        gUnk_03002C30[slot].unk4 = (gUnk_03002C30[slot].unk4 + gUnk_083AF310[gUnk_03002C30[slot].unk23]) & 0xFF;
        gUnk_03002C30[slot].unk23++;
        return 0;
    }
    return 1;
}

void battle_sprite_blink_update(u32 slot, u8 *counter, u8 *n)
{
    gUnk_03002C30[slot].unk0 |= 0x8000;
    if (*n == 0)
    {
        if (++*counter & 1)
            gUnk_03002C30[slot].unk0 &= 0x7FFF;
    }
    else if (*counter == *n)
    {
        *counter = 0;
        gUnk_03002C30[slot].unk0 &= 0x7FFF;
        (*n)--;
    }
    else
    {
        (*counter)++;
    }
}

void sub_08035478(u32 rec)
{
    u32 best_x;
    s32 i;
    s32 best;
    if (rec <= 2)
    {
        best_x = 0xFF;
        for (i = 5, best = 5; i > 2; i--)
        {
            if (gUnk_03000590[i].unk40 != 0 && gUnk_03002C30[i * 4 + 0x5D].unk2 < best_x)
            {
                best_x = gUnk_03002C30[i * 4 + 0x5D].unk2;
                best = i;
            }
        }
    }
    else
    {
        best_x = 0;
        for (i = 2, best = 2; i >= 0; i--)
        {
            if (gUnk_03000590[i].unk40 != 0 && gUnk_03002C30[i * 4 + 0x5D].unk2 > best_x)
            {
                best_x = gUnk_03002C30[i * 4 + 0x5D].unk2;
                best = i;
            }
        }
    }
    gUnk_03000590[rec].unkE0 = best + 1;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", calc_bot_evasion_modifier);

u32 get_random_battle_weight_entry(u32 rec)
{
    return gUnk_083AF330[sub_08035590(rec) * 8 + (rng_next_080424B8() & 7)];
}

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

u32 check_sprite_in_range(u32 slot)
{
    s32 y = gUnk_03002C30[slot].unk2;
    s32 x = gUnk_03002C30[slot].unk4;
    u16 tx = gUnk_03002C30[slot].unk30;
    u16 ty = gUnk_03002C30[slot].unk32;
    if (ty - 2 <= x && ty + 2 >= x && tx - 2 <= y && tx + 2 >= y)
        return 1;
    return 0;
}

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

void apply_battle_bot_damage_reduction(u32 rec)
{
    if ((u8)(gUnk_03000590[rec].unkC9 - 0xD) <= 1)
        sub_08035754(&gUnk_03001800.unkE8, gUnk_03000590[rec].unkCC);
}

void accumulate_battle_speed_value(u32 rec)
{
    struct Unk_03001800 *b = &gUnk_03001800;
    b->unkEE += gUnk_03000590[rec].medal.unk5;
    b->unkEE += calc_bot_matching_part_power(rec);
    b->unkEE += rng_next_080424B8() & 7;
}

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

u32 check_bot_can_shoot(u32 rec, u32 part, u32 target)
{
    if (((u8)(gUnk_03000590[rec].parts[part].data[1] - 4) <= 1 || (gUnk_03000590[rec].unkD6 & 1))
        && sub_08035960(target, 0x18))
        return 1;
    return 0;
}

u32 check_bot_can_support(u32 rec, u32 part, u32 target)
{
    if (((u8)(gUnk_03000590[rec].parts[part].data[1] - 6) <= 1 || (gUnk_03000590[rec].unkD6 & 2))
        && sub_08035960(target, 0x19))
        return 1;
    return 0;
}

u32 check_bot_can_use_shoot_part(u32 rec, u32 part, u32 target)
{
    if (((u8)(gUnk_03000590[rec].parts[part].data[1] - 8) <= 1 || (gUnk_03000590[rec].unkD6 & 4))
        && sub_08035960(target, 0x1A))
        return 1;
    return 0;
}

u32 check_bot_status_effect_4(u32 rec, u32 part, u32 target)
{
    if ((gUnk_03000590[target].unkC0 & 2) && gUnk_03000590[rec].parts[part].data[1] == 0x34)
        return 1;
    return 0;
}

u32 check_can_target_bot(u32 rec, u32 part, u32 target)
{
    if (((u8)(gUnk_03000590[rec].parts[part].data[1] - 4) <= 1 || (gUnk_03000590[rec].unkD6 & 1))
        && (gUnk_03000590[target].unkD6 & 8))
        return 1;
    return 0;
}

u32 check_battle_can_support_target(u32 rec, u32 part, u32 target)
{
    if (((u8)(gUnk_03000590[rec].parts[part].data[1] - 6) <= 1 || (gUnk_03000590[rec].unkD6 & 2))
        && (gUnk_03000590[target].unkD6 & 0x10))
        return 1;
    return 0;
}

u32 check_battle_can_special_target(u32 rec, u32 part, u32 target)
{
    if (((u8)(gUnk_03000590[rec].parts[part].data[1] - 8) <= 1 || (gUnk_03000590[rec].unkD6 & 4))
        && (gUnk_03000590[target].unkD6 & 0x20))
        return 1;
    return 0;
}

void sub_08035B9C(u32 rec)
{
    u32 i;
    for (i = 0; i <= 2; i++)
        if (gUnk_03000590[rec].parts[i].unk11 != 0 && gUnk_03000590[rec].parts[i].data[1] == 0x35)
            gUnk_03001800.unkEC += gUnk_03000590[rec].parts[i].data[6];
}

void sub_08035BD4(void)
{
    struct Unk_03001800 *b = &gUnk_03001800;
    if (b->unkEC <= 2)
        b->unkEC += rng_next_080424B8() & 3;
}

void sub_08035BFC(u32 rec, u32 part)
{
    struct Unk_03001800 *b = &gUnk_03001800;
    b->unkEC = b->unkEC / gUnk_03000590[rec].parts[part].data[0xC];
    if (b->unkEC == 0)
        b->unkEC = 1;
}

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

void sub_08036340(u32 side)
{
    u32 x = 4;
    if (side == 0)
        x = 0x12;
    set_tilemap_and_decompress_bg(x, 0, gUnk_084889B4, REG_BG1CNT, 0x329);
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036370);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080363E8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080364A8);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080366DC);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036784);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803684C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080368C4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", setup_battle_sprite_oam_entries);

u32 advance_sprite_anim_frame(u32 sprite, u32 b)
{
    s32 f;
    if (!(gUnk_03002C30[sprite].unk0 & 0x8000) || gUnk_03002C30[sprite].unk23 == 0x10)
        return 1;
    gUnk_03002C30[sprite].unk4 = (gUnk_03002C30[sprite].unk4 + gUnk_083AF4A0[gUnk_03002C30[sprite].unk23]) & 0xFF;
    f = gUnk_03002C30[sprite].unk23 + 1;
    gUnk_03002C30[sprite].unk23 = f;
    if (b)
        gUnk_03002C30[sprite].unk9 = f * 4 + 0x40;
    return 0;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", advance_sprite_group_anims);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036B50);

void sub_08036B84(u32 rec, u32 part)
{
    gUnk_03001800.unkC8 = gUnk_03000590[rec].parts[part].unk11;
    gUnk_03001800.unkCC = gUnk_03000590[rec].parts[part].unk11;
    gUnk_03001800.unkD1 = 1;
}

u32 sub_08036BB8(u16 *amount, u32 rec, u32 part)
{
    u8 *n = (u8 *)amount;
    if (gUnk_03000590[rec].parts[part].unk11 != 0 && *n != 0)
    {
        (*n)--;
        gUnk_03000590[rec].parts[part].unk11--;
        return 0;
    }
    return 1;
}

void sub_08036BF4(u32 side)
{
    u32 y = 2;
    if (side == 0)
        y = 0x10;
    vram_fill_tilemap_rect(0xC, 0xD, y, 0, REG_BG1CNT, 0);
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08036C20);

void battle_calc_damage_split(u32 rec, u32 part, s32 amount)
{
    s32 room = gUnk_03000590[rec].parts[part].data[4] - gUnk_03000590[rec].parts[part].unk11;
    if (room > amount)
    {
        gUnk_03001800.unkC8 = amount;
        gUnk_03001800.unkCC = amount;
        gUnk_03001800.unkCA = 0;
    }
    else
    {
        gUnk_03001800.unkC8 = room;
        gUnk_03001800.unkCC = room;
        gUnk_03001800.unkCA = amount - room;
    }
}

u32 battle_check_action_counter(u16 *amount, u32 rec, u32 part)
{
    u8 *n = (u8 *)amount;
    if (gUnk_03000590[rec].parts[part].unk11 != gUnk_03000590[rec].parts[part].data[4])
    {
        gUnk_03000590[rec].parts[part].unk11++;
        if (--*n != 0)
            return 0;
    }
    return 1;
}

u32 sub_08036D64(u32 rec, u32 skill)
{
    if (skill - 0xd <= 1)
    {
        if (gUnk_03000590[rec].unkCF & 1) return 1; return 0;
    }
    else if (skill - 0xf <= 1)
    {
        if (gUnk_03000590[rec].unkCF & 8) return 1; return 0;
    }
    else if (skill - 0x11 <= 1)
    {
        if (gUnk_03000590[rec].unkCF & 2) return 1; return 0;
    }
    else if (skill - 0x13 <= 1)
    {
        if (gUnk_03000590[rec].unkCF & 4) return 1; return 0;
    }
    return 0;
}

u32 medal_update_exp_progress(u32 slot, u32 n)
{
    if (!(gUnk_03002C30[slot].unk0 & 0x8000) || gUnk_03002C30[slot].unk23 == 0x10)
        return 1;
    if (n == 0)
        gUnk_03002C30[slot].unk2 = gUnk_03002C30[slot].unk2 + gUnk_083AF4B0[gUnk_03002C30[slot].unk23];
    else
        gUnk_03002C30[slot].unk2 = gUnk_03002C30[slot].unk2 - gUnk_083AF4B0[gUnk_03002C30[slot].unk23];
    gUnk_03002C30[slot].unk23++;
    return 0;
}

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

u32 decrement_battle_timer_and_check_zero(void)
{
    sub_08035754(&gUnk_03001800.unkE8, 0x20);
    if (gUnk_03001800.unkE8 != 0)
        return 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", calc_battle_stat_ratio);

void battle_set_damage_display(u32 rec, u32 part, s32 amount)
{
    if (gUnk_03000590[rec].parts[part].data[4] >= amount)
    {
        gUnk_03001800.unkC8 = amount;
        gUnk_03001800.unkCC = amount;
        gUnk_03001800.unkCA = 0;
    }
    else
    {
        gUnk_03001800.unkC8 = gUnk_03000590[rec].parts[part].data[4];
        gUnk_03001800.unkCC = gUnk_03000590[rec].parts[part].data[4];
        gUnk_03001800.unkCA = amount - gUnk_03000590[rec].parts[part].data[4];
    }
}

void sub_08037330(u32 rec, u32 frame, u32 mask)
{
    if (frame & mask)
    {
        gUnk_03002C30[rec * 4 + 0x5A].unk0 |= 0x8000;
        gUnk_03002C30[rec * 4 + 0x5B].unk0 |= 0x8000;
        gUnk_03002C30[rec * 4 + 0x5C].unk0 |= 0x8000;
        gUnk_03002C30[rec * 4 + 0x5D].unk0 |= 0x8000;
    }
    else
    {
        gUnk_03002C30[rec * 4 + 0x5A].unk0 &= 0x7FFF;
        gUnk_03002C30[rec * 4 + 0x5B].unk0 &= 0x7FFF;
        gUnk_03002C30[rec * 4 + 0x5C].unk0 &= 0x7FFF;
        gUnk_03002C30[rec * 4 + 0x5D].unk0 &= 0x7FFF;
    }
}

void sub_080373D4(u32 rec)
{
    gUnk_03002C30[rec * 4 + 0x5A].unk0 |= 0x8000;
    gUnk_03002C30[rec * 4 + 0x5B].unk0 |= 0x8000;
    gUnk_03002C30[rec * 4 + 0x5C].unk0 |= 0x8000;
    gUnk_03002C30[rec * 4 + 0x5D].unk0 |= 0x8000;
}

void sub_08037424(u32 slot)
{
    gUnk_03002C30[slot].unk4 = (gUnk_03002C30[slot].unk4 + gUnk_083AF4E0[gUnk_03002C30[slot].unk23]) & 0xFF;
    gUnk_03002C30[slot].unk23 = (gUnk_03002C30[slot].unk23 + 1) & 31;
}

void sub_08037458(u32 rec, s32 amount)
{
    s32 head = gUnk_03000590[rec].parts[0].unk10;
    if (head > amount)
    {
        gUnk_03001800.unkC8 = amount;
        gUnk_03001800.unkCC = amount;
        gUnk_03001800.unkCA = 0;
    }
    else
    {
        gUnk_03001800.unkC8 = head;
        gUnk_03001800.unkCC = head;
        gUnk_03001800.unkCA = amount - head;
    }
}

void sub_08037498(u32 rec, s32 amount)
{
    s32 room = gUnk_03000590[rec].parts[0].data[8] - gUnk_03000590[rec].parts[0].unk10;
    if (room > amount)
    {
        gUnk_03001800.unkC8 = amount;
        gUnk_03001800.unkCC = amount;
        gUnk_03001800.unkCA = 0;
    }
    else
    {
        gUnk_03001800.unkC8 = room;
        gUnk_03001800.unkCC = room;
        gUnk_03001800.unkCA = amount - room;
    }
}

void sub_080374E0(u32 a, u32 b)
{
    if (a > b)
    {
        gUnk_03001800.unkC8 = b;
        gUnk_03001800.unkCC = b;
        gUnk_03001800.unkCA = 0;
        gUnk_03001800.unkD1 = 0;
    }
    else
    {
        gUnk_03001800.unkC8 = a;
        gUnk_03001800.unkCC = a;
        gUnk_03001800.unkCA = b - a;
        gUnk_03001800.unkD1 = 1;
    }
}

void sub_0803752C(u32 a, u32 max, u32 b)
{
    u32 room = max - a;
    if (room > b)
    {
        gUnk_03001800.unkC8 = b;
        gUnk_03001800.unkCC = b;
        gUnk_03001800.unkCA = 0;
        gUnk_03001800.unkD1 = 0;
    }
    else
    {
        gUnk_03001800.unkC8 = room;
        gUnk_03001800.unkCC = room;
        gUnk_03001800.unkCA = b - room;
        gUnk_03001800.unkD1 = 1;
    }
}

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

void sub_080378A8(void)
{
    if (!(gUnk_03001800.unkF8 & 2))
        gUnk_03002C30[0x21].unk2 = (gUnk_03002C30[0x21].unk2 + 4) & 0x1FF;
    else
        gUnk_03002C30[0x21].unk2 = (gUnk_03002C30[0x21].unk2 - 4) & 0x1FF;
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080378F0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", spawn_battle_particle_effect);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037B9C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037BF4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037C50);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08037E2C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803809C);

void sub_080380F0(void)
{
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D == 0x46)
    {
        gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
    }
    else
    {
        gUnk_03002C30[gUnk_03000440.unk12F].unk2 = (gUnk_03002C30[gUnk_03000440.unk12F].unk2 + gUnk_083AF670[gUnk_03002C30[gUnk_03000440.unk12F].unk2D & 0xF]) & 0x1FF;
        if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D & 1)
            gUnk_03002C30[gUnk_03000440.unk12F].unk4++;
        gUnk_03002C30[gUnk_03000440.unk12F].unk2D++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038178);

void sub_080381E0(void)
{
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D == 0x23)
    {
        gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
    }
    else
    {
        if (!(gUnk_03001800.unkF8 & 1))
            gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 - 0x10) & 0x3FF;
        else
            gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
        gUnk_03002C30[gUnk_03000440.unk12F].unk2D++;
    }
}

void sub_08038258(void)
{
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D == 0x46)
    {
        gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
    }
    else
    {
        if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D & 1)
            gUnk_03002C30[gUnk_03000440.unk12F].unk4++;
        if (!(gUnk_03001800.unkF8 & 1))
            gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 - 0x10) & 0x3FF;
        else
            gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
        gUnk_03002C30[gUnk_03000440.unk12F].unk2D++;
    }
}

void sub_080382F4(void)
{
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk2D == 0x5A)
    {
        gUnk_03002C30[gUnk_03000440.unk12F].unk29++;
    }
    else
    {
        if (gUnk_03001800.unkF8 & 1)
            gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 - 0x10) & 0x3FF;
        else
            gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
        gUnk_03002C30[gUnk_03000440.unk12F].unk2D++;
    }
}

void sub_0803836C(void)
{
    u32 i;
    for (i = 0; i <= 2; i++)
    {
        gUnk_03001800.unkD2[i] = 0;
        gUnk_03001800.unkD6[i] = 0;
    }
}

void sub_08038394(u32 rec, u32 flags)
{
    if (flags & 1)
    {
        gUnk_03000590[rec].unkC9 = 0;
        gUnk_03000590[rec].unkCA = 0;
        gUnk_03000590[rec].unkCB = 0;
        gUnk_03000590[rec].unkCC = 0;
    }
    if (flags & 2)
    {
        gUnk_03000590[rec].unkC4 = 0;
        gUnk_03000590[rec].unkC5 = 0;
        gUnk_03000590[rec].unkC6 = 0;
        gUnk_03000590[rec].unkC7 = 0;
    }
}

void sub_080383E8(void)
{
    u32 i;
    for (i = 10; i <= 0x1A; i++)
    {
        gUnk_0300056F = i + 0x21;
        gUnk_083AF690[gUnk_03002C30[i + 0x21].unk29]();
    }
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038428);

void sub_0803858C(void)
{
    gUnk_03002C30[gUnk_03000440.unk12F].unk18 = (gUnk_03002C30[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
    if (move_sprite_toward_target(gUnk_03000440.unk12F))
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
}

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

void sub_08038804(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x6C], gUnk_03000440.unk12F);
    if (gUnk_03002C30[gUnk_03000440.unk12F].unk22 == 0xFF)
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
}

INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_0803884C);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_080388A4);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038AC0);
INCLUDE_ASM("asm/nonmatching/code_08034CB8", sub_08038BC0);
