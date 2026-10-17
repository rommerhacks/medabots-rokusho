#include "global.h"

// Robattle (game state 7) handlers 0x70/0x71 and 0x78/0x79: show a number over each Medabot with
// unkCE bit 2 (unkC8) / bit 3 (unkCD) for 90 frames (guess: damage / repair numbers).
void sub_080147FC(void)
{
    u32 i;

    update_all_battle_status_sprites();
    iterate_bots_setup_battle_sprites();
    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 4))
        {
            set_display_digit_type(&gUnk_03000440.unkEE, gUnk_03000590[i].unkC8, 0);
            sub_0801A144(&gUnk_03000440.unkEE, i);
        }
    }
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_08014870(void)
{
    u32 i;

    update_all_battle_status_sprites();
    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 4))
            sub_0801A228(i);
    }
    if (++gUnk_03000440.unk84 == 90)
    {
        for (i = 0; i <= 5; i++)
        {
            if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 4))
            {
                gUnk_03000590[i].unkCE &= ~4;
                clear_battle_sprite_slot(10 + i * 4, 3);
            }
        }
        gUnk_03001800.unk55 &= ~8;
        gGameSubState = 0x44;
    }
}

void sub_08014920(void)
{
    u32 i;

    update_all_battle_status_sprites();
    iterate_bots_setup_battle_sprites();
    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 8))
        {
            set_display_digit_type(&gUnk_03000440.unkEE, gUnk_03000590[i].unkCD, 1);
            sub_0801A144(&gUnk_03000440.unkEE, i);
        }
    }
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_08014994(void)
{
    u32 i;

    update_all_battle_status_sprites();
    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 8))
            sub_0801A228(i);
    }
    if (++gUnk_03000440.unk84 == 90)
    {
        for (i = 0; i <= 5; i++)
        {
            if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkCE & 8))
            {
                gUnk_03000590[i].unkCE &= ~8;
                clear_battle_sprite_slot(10 + i * 4, 3);
            }
        }
        gUnk_03001800.unk55 &= ~0x10;
        gGameSubState = 0x44;
    }
}

// Robattle handlers 0x90-0x99 and 0xA0-0xAF: exchange each side's chosen parts (unkDD) over the
// serial link (gUnk_03005010), guess: link Robattle (only when gUnk_03000440.unk89 = 1).
void sub_08014A44(void)
{
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void sub_08014A60(void)
{
    if (run_message(gUnk_083CF3B0[1]))
        gGameSubState++;
}

void sub_08014A84(void)
{
    if (sub_0803E79C())
    {
        gUnk_03005010.unk6 = 0;
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
}

void sub_08014AB4(void)
{
    if (gUnk_03000440.unk86 == 16)
        gGameSubState++;
    else
        gUnk_03000440.unk86++;
}

void sub_08014ADC(void)
{
    gUnk_03001800.unk51 = 0;
    gUnk_03001800.unk52 = 0;
    gUnk_03001800.unk53 = 0;
    gUnk_03001800.unk54 = 0;
    gUnk_03001800.unk1A6 = 0;
    gUnk_03001800.unk1AF = 0;
    gUnk_03001800.unk1B0 = 1;
    gUnk_03000440.unk86 = 0;
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08014B34);

void sub_08014C30(void)
{
    gUnk_03005010.unk6 = 0;
    battle_bot_select_part(3, gUnk_03000590[3].unkDD);
    battle_bot_select_part(4, gUnk_03000590[4].unkDD);
    battle_bot_select_part(5, gUnk_03000590[5].unkDD);
    gGameSubState++;
}

void sub_08014C84(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[i + 3].unkDD > 3)
            battle_bot_select_medaforce(i + 3, gUnk_03000590[i + 3].unkDD - 4);
    }
    gGameSubState++;
}

void sub_08014CC8(void)
{
    if (game_state_execute_handler_a())
        gGameSubState++;
}

void sub_08014CE4(void)
{
    gGameSubState = 0x40;
}

void sub_08014CF0(void)
{
    u16 r;

    if (gUnk_03001800.unk87 <= 2)
    {
        gUnk_03005010.unk6 = gUnk_03000590[gUnk_03001800.unk87].unkDD + 0x8000;
        if (gUnk_03001800.unk1AF)
            goto next;
        gUnk_03001800.unk1AF = 1;
    }
    else
    {
        r = gUnk_03005010.unk8[gUnk_03000B90 ^ 1][1];
        if (r & 0x8000)
        {
            gUnk_03000590[gUnk_03001800.unk87].unkDD = r;
        next:
            gGameSubState++;
        }
    }
}

void sub_08014D84(void)
{
    gGameSubState++;
}

void sub_08014D94(void)
{
    if (gUnk_03001800.unk87 > 2)
        battle_bot_select_part(gUnk_03001800.unk87, gUnk_03000590[gUnk_03001800.unk87].unkDD);
    gGameSubState++;
}

void sub_08014DC8(void)
{
    if (gUnk_03001800.unk87 > 2 && gUnk_03000590[gUnk_03001800.unk87].unkDD > 3)
        battle_bot_select_medaforce(gUnk_03001800.unk87, gUnk_03000590[gUnk_03001800.unk87].unkDD - 4);
    gGameSubState++;
}

void sub_08014E08(void)
{
    gUnk_03005010.unk6 = 0;
    gGameSubState = 0x45;
}

void sub_08014E20(void)
{
    gUnk_03000440.unk86++;
    if (sub_0803E79C())
    {
        gUnk_03005010.unk6 = 0;
        gGameSubState++;
    }
}

void sub_08014E54(void)
{
    if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else
        gGameSubState++;
}

void clear_battle_bot_array(void)
{
    sub_0803F624((u8 *)gUnk_03000590, 0x600, 0);
}

void count_active_battle_bots(void)
{
    u32 i;
    u32 n;

    for (i = 0, n = 0; i <= 2; i++)
    {
        if (gUnk_03001800.unk41[i])
            n++;
    }
    gUnk_03001800.unk5A = n;
    gUnk_03001800.unk5B = gUnk_03001800.unk2;
}

void battle_setup_team_bots(void)
{
    copy_player_medals_to_battle_bots();
    copy_team_slots_to_battle_bots();
    battle_bots_load_parts(0, gUnk_03001800.unk5A);
}

void copy_player_medals_to_battle_bots(void)
{
    u32 i;

    for (i = 0; i < gUnk_03001800.unk5A; i++)
        memcpy_bytes_0803F63C(&gUnk_03000BE0[find_medal_slot_by_id(gUnk_030017A0[gUnk_03001800.unk41[i] & 0xF].unk2) - 1], &gUnk_03000590[i], 0x40);
}

void copy_team_slots_to_battle_bots(void)
{
    u32 i;

    for (i = 0; i < gUnk_03001800.unk5A; i++)
        memcpy_bytes_0803F63C(&gUnk_030017A0[gUnk_03001800.unk41[i] & 0xF], &gUnk_03000590[i].unk40, 8);
}

void battle_bots_load_parts(u32 rec, u32 n)
{
    u32 i;

    for (i = 0; i < n; rec++, i++)
    {
        gUnk_03000590[rec].unkB8 = rec;
        gUnk_03000590[rec].unkBA = 1;
        load_part_data(gUnk_03000590[rec].unk43, 0, &gUnk_03000440.unkEE);
        memcpy_bytes_0803F63C(&gUnk_03000440.unkEE, gUnk_03000590[rec].parts[0].data, 0xD);
        gUnk_03000590[rec].parts[0].unk10 = gUnk_03000590[rec].parts[0].data[8];
        gUnk_03000590[rec].parts[0].unk11 = gUnk_03000590[rec].parts[0].data[4];
        gUnk_03000590[rec].parts[0].unk17 = gUnk_03000590[rec].unk43;
        load_part_data(gUnk_03000590[rec].unk44, 1, &gUnk_03000440.unkEE);
        memcpy_bytes_0803F63C(&gUnk_03000440.unkEE, gUnk_03000590[rec].parts[1].data, 0xD);
        gUnk_03000590[rec].parts[1].unk11 = gUnk_03000590[rec].parts[1].data[4];
        gUnk_03000590[rec].parts[1].unk17 = gUnk_03000590[rec].unk44;
        load_part_data(gUnk_03000590[rec].unk45, 2, &gUnk_03000440.unkEE);
        memcpy_bytes_0803F63C(&gUnk_03000440.unkEE, gUnk_03000590[rec].parts[2].data, 0xD);
        gUnk_03000590[rec].parts[2].unk11 = gUnk_03000590[rec].parts[2].data[4];
        gUnk_03000590[rec].parts[2].unk17 = gUnk_03000590[rec].unk45;
        load_part_data(gUnk_03000590[rec].unk46, 3, &gUnk_03000440.unkEE);
        memcpy_bytes_0803F63C(&gUnk_03000440.unkEE, gUnk_03000590[rec].parts[3].data, 0xD);
        memcpy_bytes_0803F63C(&gUnk_03000590[rec].parts[3].data[4], &gUnk_03000590[rec].parts[3].unk11, 6);
        gUnk_03000590[rec].parts[3].unk17 = gUnk_03000590[rec].unk46;
    }
}

void init_opponent_bots(void)
{
    u32 i;

    for (i = 0; i < gUnk_03001800.unk5B; i++)
        init_enemy_bot_medal(i);
    init_opponent_bot_slots();
    battle_bots_load_parts(3, gUnk_03001800.unk5B);
}

void init_enemy_bot_medal(u8 i)
{
    u32 k;
    u32 v;
    u32 lvl;

    memcpy_bytes_08041D04(gUnk_083B6158[gUnk_03001800.unk4[i].unk4], &gUnk_03000440.unkEE, 16);
    gUnk_03000590[i + 3].medal.unk0 = 0x80;
    gUnk_03000590[i + 3].medal.unk1 = (&gUnk_03000440.unkEE)[0];
    gUnk_03000590[i + 3].medal.unk4 = (&gUnk_03000440.unkEE)[1];
    gUnk_03000590[i + 3].medal.unk5 = gUnk_03001800.unk4[i].unk5;
    gUnk_03000590[i + 3].medal.unk6 = (&gUnk_03000440.unkEE)[2];
    gUnk_03000590[i + 3].medal.unk7 = (&gUnk_03000440.unkEE)[7];
    gUnk_03000590[i + 3].medal.unk9 = gUnk_03001800.unk4[i].unkA;
    memcpy_bytes_08041D04((const void *)gUnk_083BA4D8[gUnk_03001800.unk4[i].parts[0]], gUnk_03000590[i + 3].medal.unkA, 0xE);
    for (k = 0; k <= 3; k++)
    {
        gUnk_03000590[i + 3].medal.unk18[k * 2] = gUnk_03001800.unk4[i].unk6[k] >> 4;
        gUnk_03000590[i + 3].medal.unk18[k * 2 + 1] = gUnk_03001800.unk4[i].unk6[k] & 0xF;
    }
    for (k = 0; k <= 7; k++)
    {
        v = gUnk_083AD200[gUnk_03000590[i + 3].medal.unk4 * 8 + k];
        lvl = gUnk_03000590[i + 3].medal.unk5 >> 1;
        if (lvl)
            v *= lvl;
        if (v == 0)
            v = 1;
        else if (v > 100)
            v = 100;
        gUnk_03000590[i + 3].medal.unk20[k] = v;
    }
}

void init_opponent_bot_slots(void)
{
    u32 i;

    for (i = 0; i < gUnk_03001800.unk5B; i++)
    {
        gUnk_03000590[i + 3].unk40 = 3;
        load_part_data(gUnk_03001800.unk4[i].parts[0], 0, &gUnk_03000440.unkEE);
        gUnk_03000590[i + 3].unk41 = (&gUnk_03000440.unkEE)[3];
        gUnk_03000590[i + 3].unk42 = gUnk_03000590[i + 3].medal.unk1;
        gUnk_03000590[i + 3].unk43 = gUnk_03001800.unk4[i].parts[0];
        gUnk_03000590[i + 3].unk44 = gUnk_03001800.unk4[i].parts[1];
        gUnk_03000590[i + 3].unk45 = gUnk_03001800.unk4[i].parts[2];
        gUnk_03000590[i + 3].unk46 = gUnk_03001800.unk4[i].parts[3];
    }
}

void battle_process_all_bots_actions(void)
{
    u32 i;

    if (gUnk_03000440.unk89 != 1 || gUnk_03000B90 == 0)
    {
        for (i = 0; i <= 5; i++)
        {
            if (gUnk_03000590[i].unk40)
                battle_process_all_bot_actions(i);
        }
    }
    else
    {
        for (i = 3; i <= 5; i++)
        {
            if (gUnk_03000590[i].unk40)
                battle_process_all_bot_actions(i);
        }
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03000590[i].unk40)
                battle_process_all_bot_actions(i);
        }
    }
}

void battle_process_bot_actions_for_side(u32 side)
{
    u32 i;
    u32 rec;

    for (i = 0; i <= 2; i++)
    {
        rec = side + i;
        if (gUnk_03000590[side + i].unk40 && battle_dispatch_action_by_type(rec))
            select_bot_battle_action(rec);
    }
}

void process_bot_battle_turn(u32 rec)
{
    if (gUnk_03000590[rec].unkC9 == 0x2C)
        select_bot_battle_action(rec);
    else if (battle_dispatch_action_by_type(rec))
        select_bot_battle_action(rec);
}

u32 battle_dispatch_action_by_type(u32 rec)
{
    u32 type = gUnk_03000590[rec].medal.unk18[gUnk_03000590[rec].medal.unk3F];

    switch (type)
    {
    case 0:
        return 1;
    case 1:
    case 2:
    case 3:
        if (battle_part_unusable(rec, type))
            return 1;
        battle_bot_select_part(rec, type);
        return 0;
    case 4:
        battle_bot_select_part(rec, 0);
        return 0;
    case 5:
    case 6:
    case 7:
        if (check_medaforce_availability(rec, type - 5, 0))
            return 1;
        return 0;
    }
}

void battle_bot_advance_rotation(u32 rec)
{
    if (++gUnk_03000590[rec].medal.unk3F == 8)
        gUnk_03000590[rec].medal.unk3F = gUnk_03000590[rec].medal.unk9;
}

void battle_advance_all_rotations(void)
{
    u32 i;

    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40)
            battle_bot_advance_rotation(i);
    }
}

void select_bot_battle_action(u32 rec)
{
    u32 i;

    if (gUnk_03000590[rec].unkC1 == 0x50 && (rng_next_080424B8() & 1)
        && !check_medaforce_availability(rec, 0, 1))
        return;
    battle_ai_roll_part_order();
    for (i = 0; i <= 3; i++)
    {
        if (gUnk_03001800.unk64[i] == 0xFF)
        {
            battle_bot_select_part(rec, 0);
            return;
        }
        if (!battle_part_unusable(rec, gUnk_03001800.unk64[i]))
        {
            battle_bot_select_part(rec, gUnk_03001800.unk64[i]);
            return;
        }
    }
    battle_bot_select_part(rec, 0);
}

u32 sub_080154E0(u32 rec, u32 part)
{
    if (gUnk_03000590[rec].unkC9 == 0x2B && gUnk_03000590[rec].unkCA == part)
        return 1;
    return 0;
}

u32 sub_08015508(u32 rec, u32 part)
{
    if (part == 1 && gUnk_03000590[rec].parts[0].unk10 == 0)
        return 1;
    return 0;
}

u32 sub_08015528(u32 rec, u32 part)
{
    if (gUnk_03000590[rec].parts[part - 1].unk11 == 0)
        return 1;
    return 0;
}

u32 sub_0801554C(u32 a, u32 b)
{
    if (b == 0)
    {
        if (a <= 2)
            return 0;
        return 1;
    }
    if (a <= 2)
        return 1;
    return 0;
}

void battle_bot_select_part(u32 rec, u32 part)
{
    gUnk_03000590[rec].unkDD = part;
    if (part == 0)
        return;
    if (part <= 3)
    {
        gUnk_03000590[rec].unkE0 = gUnk_03000590[rec].parts[part - 1].unkE;
        gUnk_03000590[rec].unkE1 = gUnk_03000590[rec].parts[part - 1].unkF;
    }
}

u32 check_medaforce_availability(u32 rec, u32 slot, u32 random)
{
    u32 i;

    if (sub_08015648(rec) || gUnk_03001800.unk58 || gUnk_03000590[rec].unkC1 != 0x50)
        return 1;
    if (random)
        slot = rng_lookup_table_value();
    for (i = 0; i <= 2; i++)
    {
        if (slot == 0)
        {
            if (gUnk_03000590[rec].medal.unk5 > 9)
            {
                battle_bot_select_medaforce(rec, 0);
                return 0;
            }
            if (!random)
                return 1;
        }
        if (slot == 1)
        {
            if (gUnk_03000590[rec].medal.unk5 > 29)
            {
                battle_bot_select_medaforce(rec, 1);
                return 0;
            }
            if (!random)
                return 1;
        }
        if (slot == 2)
        {
            if (gUnk_03000590[rec].medal.unk5 > 59)
            {
                battle_bot_select_medaforce(rec, 2);
                return 0;
            }
            if (!random)
                return 1;
        }
        if (slot == 0)
            return 1;
        slot--;
    }
}

u32 sub_08015648(u32 rec)
{
    if (rec <= 2 || gUnk_030057E0.unk7FF > 2)
        return 0;
    return 1;
}

void battle_bot_select_medaforce(u32 rec, u32 part)
{
    memcpy_bytes_08041D04(&gUnk_083B7E0C[gUnk_03000590[rec].medal.unk1 * 3], &gUnk_03000440.unkEE, 3);
    memcpy_bytes_08041D04(&gUnk_083B7CD4[(&gUnk_03000440.unkEE)[part] * 6], gUnk_03000590[rec].unkA8, 6);
    battle_bot_select_part(rec, part + 4);
}

void battle_ai_roll_part_order(void)
{
    memcpy_bytes_08041D04(gUnk_083AD2F0[rng_next_080424B8() & 0x1F], gUnk_03001800.unk64, 4);
}

u32 battle_part_unusable(u32 rec, u32 part)
{
    if (!sub_080154E0(rec, part) && !sub_08015508(rec, part) && !sub_08015528(rec, part)
        && !begin_battle_action_lookup(rec, part))
        return 0;
    return 1;
}

void load_bg3_tilemap_08488764(void)
{
    set_tilemap_and_decompress_bg(14, 3, gUnk_08488764, REG_BG3CNT, 0x200);
}

void draw_battle_bot_portraits(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[i].unk40)
            fill_tilemap_rect_08042698(2, 2, 2, i * 3 + 4, REG_BG3CNT, (gUnk_03000590[i].parts[3].data[1] << 2) + 0x8084);
        else
            fill_tilemap_rect_08042698(2, 2, 2, i * 3 + 4, REG_BG3CNT, 0x8230);
    }
    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[i + 3].unk40)
            fill_tilemap_rect_08042698(2, 2, 26, i * 3 + 4, REG_BG3CNT, (gUnk_03000590[i + 3].parts[3].data[1] << 2) + 0x8084);
        else
            fill_tilemap_rect_08042698(2, 2, 26, i * 3 + 4, REG_BG3CNT, 0x8230);
    }
}

INCLUDE_ASM("asm/nonmatching/code_080147FC", get_bot_part_effective_values);

void load_bot_part_sprite(u32 rec)
{
    u8 *p = gUnk_03001800.unk64;
    get_bot_part_effective_values(rec, p);
    decompress_sprite_to_vram_08042D94(p[0], p[1], p[2], p[3], rec);
}

void load_all_bot_part_sprites(void)
{
    u32 i;
    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40)
            load_bot_part_sprite(i);
    }
}

u32 sub_08015924(u32 rec)
{
    if (rec <= 2)
    {
        if (gUnk_03000590[rec].unkBD & 4)
            return 1;
        return 0;
    }
    if (gUnk_03000590[rec].unkBD & 4)
        return 0;
    return 1;
}

void setup_battle_bot_sprites_08015960(u32 rec, u32 x, u32 y)
{
    u8 *p = gUnk_03001800.unk64;
    u32 flip;
    get_bot_part_effective_values(rec, p);
    flip = sub_08015924(rec);
    init_battle_medabot_sprites(p[0], p[1], p[2], p[3], rec, rec * 4 + 0x5A, x, y, flip,
                                gUnk_03001800.unk39[3] + 2, rec * 4 + 0x5A);
}

void setup_all_battle_bot_sprite_positions(void)
{
    u32 i;
    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40)
        {
            u32 x = 200;
            if (i <= 2)
                x = 40;
            setup_battle_bot_sprites_08015960(i, x, (i % 3) * 24 + 36);
        }
    }
}

void setup_bot_battle_sprites_08015A00(u32 rec, u32 x, u32 y)
{
    u8 *p = gUnk_03001800.unk64;
    u32 flip;
    get_bot_part_effective_values(rec, p);
    flip = sub_08015924(rec);
    setup_battle_sprite_group(p[0], p[1], p[2], p[3], rec, rec * 4 + 0x5A, x, y, flip,
                              gUnk_03001800.unk39[3] + 2, rec * 4 + 0x5A);
    gUnk_03002C30[rec * 4 + 0x5B].unk0 &= 0xFDFF;
    gUnk_03002C30[rec * 4 + 0x5C].unk0 &= 0xFDFF;
    gUnk_03002C30[rec * 4 + 0x5B].unk18 = 0;
    gUnk_03002C30[rec * 4 + 0x5C].unk18 = 0;
}

void load_battle_bg_layers(void)
{
    set_tilemap_and_decompress_bg(0, 13, gUnk_08488830, REG_BG1CNT, 0x258);
    set_tilemap_and_decompress_bg(0, 17, gUnk_08488744, REG_BG1CNT, 0x210);
    set_tilemap_and_decompress_bg(12, 15, gUnk_084887A4, REG_BG1CNT, 0x230);
    set_tilemap_and_decompress_bg(20, 16, gUnk_084887F4, REG_BG1CNT, 0x240);
}

void decompress_two_bg1_layers(void)
{
    set_tilemap_and_decompress_bg(12, 21, gUnk_084887A4, REG_BG1CNT, 0x230);
    set_tilemap_and_decompress_bg(20, 21, gUnk_084887F4, REG_BG1CNT, 0x240);
}

INCLUDE_ASM("asm/nonmatching/code_080147FC", render_bot_name_sprites);
INCLUDE_ASM("asm/nonmatching/code_080147FC", draw_battle_panel_left_a);
INCLUDE_ASM("asm/nonmatching/code_080147FC", draw_battle_panel_left_b);
INCLUDE_ASM("asm/nonmatching/code_080147FC", render_bot_health_bar);
INCLUDE_ASM("asm/nonmatching/code_080147FC", fixed_point_multiply_divide);
INCLUDE_ASM("asm/nonmatching/code_080147FC", render_bot_cash_display);
INCLUDE_ASM("asm/nonmatching/code_080147FC", battle_load_sprite_data);

void sub_08015F78(void)
{
    u32 i;
    for (i = 0; i < 6; i++)
        sub_08015F90(i);
}

INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08015F90);

void sub_08016068(void)
{
    u32 i;
    for (i = 0; i < 6; i++)
        sub_08016080(i);
}

INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016080);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016138);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016154);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016288);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_0801630C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016370);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016438);
INCLUDE_ASM("asm/nonmatching/code_080147FC", animate_battle_sprites);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016554);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080165B0);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080165D0);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016614);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016660);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080166AC);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080166F0);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_0801672C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_0801677C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080167BC);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016804);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_0801684C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016894);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080168F4);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080169AC);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016A3C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016AD8);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016C0C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016D18);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016DA4);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016DCC);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016E5C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", save_restore_bg1_tilemap_region);
INCLUDE_ASM("asm/nonmatching/code_080147FC", save_restore_bg0_tilemap_region);
INCLUDE_ASM("asm/nonmatching/code_080147FC", draw_partial_bg1_column);
INCLUDE_ASM("asm/nonmatching/code_080147FC", scroll_tilemap_window);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016FB4);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017004);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017048);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017084);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080170D4);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017104);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017130);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017178);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080171C0);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017208);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017268);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080173B4);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080175FC);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_0801767C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017734);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080178CC);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017914);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017948);
INCLUDE_ASM("asm/nonmatching/code_080147FC", setup_battle_bot_sprites_08017994);
INCLUDE_ASM("asm/nonmatching/code_080147FC", position_battle_team_cursors);
INCLUDE_ASM("asm/nonmatching/code_080147FC", setup_bot_battle_sprites_08017A7C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", init_battle_cursor_sprite_08017B24);
INCLUDE_ASM("asm/nonmatching/code_080147FC", render_battle_bot_label);
INCLUDE_ASM("asm/nonmatching/code_080147FC", draw_bg_window_rect);
INCLUDE_ASM("asm/nonmatching/code_080147FC", animate_bg_window_blink);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08017D14);
INCLUDE_ASM("asm/nonmatching/code_080147FC", load_bot_sprite_tiles_to_vram);
INCLUDE_ASM("asm/nonmatching/code_080147FC", copy_battle_bot_data_to_state);
INCLUDE_ASM("asm/nonmatching/code_080147FC", battle_load_script_to_buffer);
INCLUDE_ASM("asm/nonmatching/code_080147FC", battle_setup_bot_font_tile);
INCLUDE_ASM("asm/nonmatching/code_080147FC", render_battle_bot_status_row);
INCLUDE_ASM("asm/nonmatching/code_080147FC", set_game_state_params);
INCLUDE_ASM("asm/nonmatching/code_080147FC", init_ewram_buffers_and_state);
INCLUDE_ASM("asm/nonmatching/code_080147FC", setup_scene_from_game_state);
INCLUDE_ASM("asm/nonmatching/code_080147FC", setup_scene_bg_from_game_state);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_0801827C);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080182AC);
INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_080182D0);
INCLUDE_ASM("asm/nonmatching/code_080147FC", setup_battle_bot_display);
INCLUDE_ASM("asm/nonmatching/code_080147FC", handle_battle_bot_selection);
INCLUDE_ASM("asm/nonmatching/code_080147FC", display_battle_cursor_on_bot);
INCLUDE_ASM("asm/nonmatching/code_080147FC", animate_battle_field_scroll);
INCLUDE_ASM("asm/nonmatching/code_080147FC", toggle_battle_team_side);
INCLUDE_ASM("asm/nonmatching/code_080147FC", animate_battle_bots_entry);
