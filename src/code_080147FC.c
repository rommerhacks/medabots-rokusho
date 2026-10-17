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

void render_bot_name_sprites(u32 rec)
{
    if (rec <= 2)
    {
        clear_sprite_table_mask(10, 10);
        render_text_sprites_08040DB8(gUnk_03000590[rec].medal.unkA, 10, 1, 14, 10, 15, 0, 1);
    }
    else
    {
        clear_sprite_table_mask(20, 13);
        render_text_sprites_08040DB8(gUnk_03000590[rec].medal.unkA, 20, 19, 14, 10, 15, 0, 1);
    }
}

void draw_battle_panel_left_a(u32 rec)
{
    if (rec <= 2)
        fill_tilemap_rect_08042698(3, 1, 1, 18, REG_BG1CNT, 0xD20A);
    else
        fill_tilemap_rect_08042698(3, 1, 21, 18, REG_BG1CNT, 0xD20A);
}

void draw_battle_panel_left_b(u32 rec)
{
    if (rec <= 2)
        fill_tilemap_rect_08042698(3, 1, 1, 18, REG_BG1CNT, 0xD20D);
    else
        fill_tilemap_rect_08042698(3, 1, 21, 18, REG_BG1CNT, 0xD20D);
}

void draw_medaforce_gauge_bar(u32 rec)
{
    u32 x = 0;
    u32 i, full, partial;

    if (rec <= 2)
    {
        full = scale_to_bar_fill(64, 80, gUnk_03000590[rec].unkC1);
        partial = full & 0xFFFF;
        full >>= 16;
        if (gUnk_03000590[rec].unkC1 != 0 && full == 0 && partial == 0)
            partial = 1;
        for (i = 0; i < full; i++)
        {
            fill_tilemap_rect_08042698(1, 1, x + 1, 17, REG_BG1CNT, 0xD208);
            x++;
        }
        if (partial)
        {
            fill_tilemap_rect_08042698(1, 1, x + 1, 17, REG_BG1CNT, 0xD200 + partial);
            x++;
        }
        for (i = x; i <= 7; i++)
        {
            fill_tilemap_rect_08042698(1, 1, x + 1, 17, REG_BG1CNT, 0xD200);
            x++;
        }
    }
    else
    {
        full = scale_to_bar_fill(64, 80, gUnk_03000590[rec].unkC1);
        partial = full & 0xFFFF;
        full >>= 16;
        if (gUnk_03000590[rec].unkC1 != 0 && full == 0 && partial == 0)
            partial = 1;
        for (i = 0; i < full; i++)
        {
            fill_tilemap_rect_08042698(1, 1, x + 21, 17, REG_BG1CNT, 0xD208);
            x++;
        }
        if (partial)
        {
            fill_tilemap_rect_08042698(1, 1, x + 21, 17, REG_BG1CNT, 0xD200 + partial);
            x++;
        }
        for (i = x; i <= 7; i++)
        {
            fill_tilemap_rect_08042698(1, 1, x + 21, 17, REG_BG1CNT, 0xD200);
            x++;
        }
    }
}

u32 scale_to_bar_fill(u32 a, u32 b, u32 c)
{
    u32 v = (float)a / (float)b * (float)c;
    u32 ret = ((v >> 3) << 16) | (v & 7);
    if (c != 0 && ret == 0)
        ret = 1;
    return ret;
}

void draw_medaforce_gauge_value(u32 rec)
{
    if (rec <= 2)
    {
        divide_by_100000_08042838(gUnk_03000590[rec].unkC1, 4, 18, 2, REG_BG1CNT, 0xD220);
        fill_tilemap_rect_08042698(1, 1, 6, 18, REG_BG1CNT, 0xD21A);
        divide_by_100000_08042838(80, 7, 18, 2, REG_BG1CNT, 0xD220);
    }
    else
    {
        divide_by_100000_08042838(gUnk_03000590[rec].unkC1, 24, 18, 2, REG_BG1CNT, 0xD220);
        fill_tilemap_rect_08042698(1, 1, 26, 18, REG_BG1CNT, 0xD21A);
        divide_by_100000_08042838(80, 27, 18, 2, REG_BG1CNT, 0xD220);
    }
}

void command_ring_draw_name(void)
{
    clear_sprite_table_mask(30, 11);
    memcpy_bytes_08041D04(gUnk_083C466C[gUnk_03001800.unk81], gUnk_03000440.unk9E, 12);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 30, 21, 17, 8, 14, 0, 1);
}

void command_ring_init_icons(void)
{
    u32 i;
    for (i = 0; i < 6; i++)
        command_ring_init_icon(i);
}

void command_ring_init_icon(u32 i)
{
    u32 k;
    struct Vec16 p;

    clear_battle_sprite_slot(i, 1);
    gUnk_03002C30[i].unk0 = 0xC604;
    k = i - gUnk_03001800.unk81;
    if (k > 5)
        k += 6;
    p = compute_polar_to_screen_position(gUnk_083AD370[k], 24, 120, 128, 8, 0);
    gUnk_03002C30[i].unk2 = p.x;
    gUnk_03002C30[i].unk4 = p.y;
    gUnk_03002C30[i].unk6 = i + 0x60C;
    if (p.y > 0x87)
        gUnk_03002C30[i].unkA = 8;
    else if (p.y > 0x77)
        gUnk_03002C30[i].unkA = 9;
    else
        gUnk_03002C30[i].unkA = 10;
    gUnk_03002C30[i].unk1C = 0;
    gUnk_03002C30[i].unk9 = 0x40 - (0x90 - gUnk_03002C30[i].unk4) / 2;
    gUnk_03002C30[i].unk8 = 0x40 - (0x90 - gUnk_03002C30[i].unk4) / 2;
    gUnk_03002C30[i].unkB = gUnk_03002C30[i].unk4 - 0x70;
    gUnk_03002C30[i].unk20 = gUnk_083AD370[k];
    gUnk_03002C30[i].unk21 = 0;
    gUnk_03002C30[i].unk22 = 0;
}

void command_ring_init_icons_hidden(void)
{
    u32 i;
    for (i = 0; i < 6; i++)
        command_ring_init_icon_hidden(i);
}

void command_ring_init_icon_hidden(u32 i)
{
    u32 k;
    struct Vec16 p;

    clear_battle_sprite_slot(i, 1);
    gUnk_03002C30[i].unk0 = 0xC604;
    k = i - gUnk_03001800.unk81;
    if (k > 5)
        k += 6;
    p = compute_polar_to_screen_position(gUnk_083AD370[k], 24, 120, 128, 8, 0);
    gUnk_03002C30[i].unk2 = p.x;
    gUnk_03002C30[i].unk4 = p.y;
    gUnk_03002C30[i].unk6 = i + 0x60C;
    if (p.y > 0x87)
        gUnk_03002C30[i].unkA = 8;
    else if (p.y > 0x77)
        gUnk_03002C30[i].unkA = 9;
    else
        gUnk_03002C30[i].unkA = 10;
    gUnk_03002C30[i].unk1C = 0;
    gUnk_03002C30[i].unk9 = 1;
    gUnk_03002C30[i].unk8 = 1;
    gUnk_03002C30[i].unkB = gUnk_03002C30[i].unk4 - 0x70;
    gUnk_03002C30[i].unk20 = gUnk_083AD370[k];
    gUnk_03002C30[i].unk21 = 0;
    gUnk_03002C30[i].unk22 = 0;
}

u32 command_ring_rotate_step(u32 dir)
{
    u32 i, done;
    for (i = 0; i <= 5; i++)
        done = sub_08016154(i, dir);
    return done;
}

INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016154);

void command_ring_input(void)
{
    if (gUnk_03001800.unk83)
    {
        if (command_ring_rotate_step(gUnk_03001800.unk83 - 1))
        {
            if (gUnk_03001800.unk83 == 1)
                gUnk_03001800.unk81 = gUnk_083AD376[gUnk_03001800.unk81];
            else
                gUnk_03001800.unk81 = gUnk_083AD37C[gUnk_03001800.unk81];
            gUnk_03001800.unk83 = 0;
            command_ring_draw_name();
        }
    }
    else
    {
        if (KEYS_LO(gRepeatKeys) & 0x10)
        {
            play_sound_effect(2);
            gUnk_03001800.unk83 = 1;
        }
        if (KEYS_LO(gRepeatKeys) & 0x20)
        {
            play_sound_effect(2);
            gUnk_03001800.unk83 = 2;
        }
    }
}

void command_ring_pulse_selected(void)
{
    if (gUnk_03001800.unk83 == 0)
    {
        gUnk_03002C30[gUnk_03001800.unk81].unk0 |= 0x20;
        gUnk_03002C30[gUnk_03001800.unk81].unk22++;
        if (gUnk_03002C30[gUnk_03001800.unk81].unk22 & 8)
        {
            gUnk_03002C30[gUnk_03001800.unk81].unk9 = 0x50;
            gUnk_03002C30[gUnk_03001800.unk81].unk8 = 0x50;
        }
        else
        {
            gUnk_03002C30[gUnk_03001800.unk81].unk9 = 0x40;
            gUnk_03002C30[gUnk_03001800.unk81].unk8 = 0x40;
        }
    }
}

void sub_08016370(u32 kind)
{
    s32 count = gUnk_083AD382[kind * 4];
    u32 speed = gUnk_083AD382[kind * 4 + 1];
    u32 x = gUnk_083AD382[kind * 4 + 2];
    u32 y = gUnk_083AD382[kind * 4 + 3];
    s32 i;

    clear_battle_sprite_slot(60, 10);
    for (i = 0; i < (u32)count; i++)
    {
        gUnk_03002C30[60 + i].unk0 = 0xC404;
        gUnk_03002C30[60 + i].unk1C = 0;
        gUnk_03002C30[60 + i].unk2 = x;
        gUnk_03002C30[60 + i].unk4 = y;
        gUnk_03002C30[60 + i].unkA = 8;
        gUnk_03002C30[60 + i].unkB = 0x80;
        gUnk_03002C30[60 + i].unk6 = (i & 3) + 0x616;
        gUnk_03002C30[60 + i].unk25 = speed;
        gUnk_03002C30[60 + i].unk26 = count - 1 - i;
        gUnk_03002C30[60 + i].unk24 = 0;
        gUnk_03002C30[60 + i].unk27 = i * 2;
        gUnk_03002C30[60 + i].unk28 = 0;
        gUnk_03002C30[60 + i].unk21 = 0;
        gUnk_03002C30[60 + i].unk22 = i & 3;
        if (kind > 2)
            gUnk_03002C30[60 + i].unk0 |= 0x1000;
    }
}

INCLUDE_ASM("asm/nonmatching/code_080147FC", sub_08016438);

void animate_battle_sprites(u32 kind)
{
    u32 count = gUnk_083AD382[kind * 4];
    u32 i;

    for (i = 0; i < count; i++)
    {
        u32 base;
        if (gUnk_03002C30[60 + i].unk24)
            base = 0x12;
        else
            base = 0x16;
        gUnk_03002C30[60 + i].unk21++;
        if ((gUnk_03002C30[60 + i].unk21 & 3) == 0)
        {
            gUnk_03002C30[60 + i].unk6 = base + ((gUnk_03002C30[60 + i].unk22 = (gUnk_03002C30[60 + i].unk22 + 1) & 3) | 0x600);
        }
    }
}

void sub_08016554(void)
{
    gUnk_03002C30[gUnk_03001800.unk81].unk0 |= 0x20;
    gUnk_03002C30[gUnk_03001800.unk81].unk22++;
    if (gUnk_03002C30[gUnk_03001800.unk81].unk22 & 4)
    {
        gUnk_03002C30[gUnk_03001800.unk81].unk9 = 0x60;
        gUnk_03002C30[gUnk_03001800.unk81].unk8 = 0x60;
    }
    else
    {
        gUnk_03002C30[gUnk_03001800.unk81].unk9 = 0x40;
        gUnk_03002C30[gUnk_03001800.unk81].unk8 = 0x40;
    }
}

void command_ring_goto_selected(void)
{
    gGameSubState = gUnk_083AD39A[gUnk_03001800.unk81];
}

void sub_080165D0(void)
{
    u32 i;
    for (i = 0; i < 6; i++)
    {
        if (gUnk_03002C30[i].unk9 == 1)
            clear_sprite_table_mask(i, 1);
        else
        {
            s32 v = gUnk_03002C30[i].unk9 - 8;
            if (v <= 0)
            {
                gUnk_03002C30[i].unk9 = 1;
                gUnk_03002C30[i].unk8 = 1;
            }
            else
            {
                gUnk_03002C30[i].unk9 = v;
                gUnk_03002C30[i].unk8 -= 8;
            }
        }
    }
}

void sub_08016614(void)
{
    if (gUnk_03000440.unk84 < 10)
    {
        read_vram_tilemap_rect(0xB, 4, 0x13, 0x10, REG_BG1CNT, gUnk_02020800);
        write_vram_tilemap_rect(0xB, 4, 0x14, 0x10, REG_BG1CNT, gUnk_02020800);
    }
}

void sub_08016660(void)
{
    if (gUnk_03000440.unk84 < 5)
    {
        read_vram_tilemap_rect(6, 6, 0xC, 0xE, REG_BG1CNT, gUnk_02020800);
        write_vram_tilemap_rect(6, 6, 0xC, 0xF, REG_BG1CNT, gUnk_02020800);
    }
}

void sub_080166AC(void)
{
    set_tilemap_and_decompress_bg(9, 0x15, gUnk_084888A8, REG_BG0CNT, 0x288);
    set_tilemap_and_decompress_bg(0x12, 0x15, gUnk_0848895C, REG_BG1CNT, 0x2D0);
}

void sub_080166F0(void)
{
    if (gUnk_03000440.unk84 < 4)
        write_vram_tilemap_rect(0xC, 4, 9, 0x13 - gUnk_03000440.unk84, REG_BG0CNT, gUnk_02020800);
}

void sub_0801672C(void)
{
    if (gUnk_03000440.unk84 < 12)
    {
        read_vram_tilemap_rect(gUnk_03000440.unk84 + 1, 7, 0x12, 0x15, REG_BG1CNT, gUnk_02021000);
        write_vram_tilemap_rect(gUnk_03000440.unk84 + 1, 7, 0x1D - gUnk_03000440.unk84, 0xD, REG_BG1CNT, gUnk_02021000);
    }
}

void part_select_init_center_icon(void)
{
    gUnk_03002C30[0].unk0 = 0xC404;
    gUnk_03002C30[0].unk1C = 0;
    gUnk_03002C30[0].unk2 = 0x78;
    gUnk_03002C30[0].unk4 = 0x78;
    gUnk_03002C30[0].unkA = 0xA;
    gUnk_03002C30[0].unkB = 0xC0;
    gUnk_03002C30[0].unk6 = gUnk_083AD3A0[gUnk_03001800.unk82] + 0x600;
}

void part_select_init_head_icon(u32 a)
{
    gUnk_03002C30[1].unk0 = 0xC404;
    gUnk_03002C30[1].unk1C = 0;
    gUnk_03002C30[1].unk2 = 0x78;
    gUnk_03002C30[1].unk4 = 0x6C;
    gUnk_03002C30[1].unkA = 0xA;
    gUnk_03002C30[1].unkB = 0xC0;
    gUnk_03002C30[1].unk6 = a * 4 + 0x604;
}

void part_select_init_right_arm_icon(u32 a)
{
    gUnk_03002C30[2].unk0 = 0xC404;
    gUnk_03002C30[2].unk1C = 0;
    gUnk_03002C30[2].unk2 = 0x6C;
    gUnk_03002C30[2].unk4 = 0x78;
    gUnk_03002C30[2].unkA = 0xA;
    gUnk_03002C30[2].unkB = 0xC0;
    gUnk_03002C30[2].unk6 = a * 4 + 0x605;
}

void part_select_init_left_arm_icon(u32 a)
{
    gUnk_03002C30[3].unk0 = 0xC404;
    gUnk_03002C30[3].unk1C = 0;
    gUnk_03002C30[3].unk2 = 0x84;
    gUnk_03002C30[3].unk4 = 0x78;
    gUnk_03002C30[3].unkA = 0xA;
    gUnk_03002C30[3].unkB = 0xC0;
    gUnk_03002C30[3].unk6 = a * 4 + 0x606;
}

void part_select_init_bottom_icon(u32 a)
{
    gUnk_03002C30[4].unk0 = 0xC404;
    gUnk_03002C30[4].unk1C = 0;
    gUnk_03002C30[4].unk2 = 0x78;
    gUnk_03002C30[4].unk4 = 0x84;
    gUnk_03002C30[4].unkA = 0xA;
    gUnk_03002C30[4].unkB = 0xC0;
    gUnk_03002C30[4].unk6 = a * 4 + 0x607;
}

void part_select_blink_selected_icon(void)
{
    switch (gUnk_03001800.unk82)
    {
    case 0:
        if (gUnk_03000440.unk84 & 8)
            part_select_init_bottom_icon(1);
        else
            part_select_init_bottom_icon(0);
        break;
    case 1:
        if (gUnk_03000440.unk84 & 8)
            part_select_init_head_icon(1);
        else
            part_select_init_head_icon(0);
        break;
    case 2:
        if (gUnk_03000440.unk84 & 8)
            part_select_init_right_arm_icon(1);
        else
            part_select_init_right_arm_icon(0);
        break;
    case 3:
        if (gUnk_03000440.unk84 & 8)
            part_select_init_left_arm_icon(1);
        else
            part_select_init_left_arm_icon(0);
        break;
    }
}

// Robattle sub-state 0x12, Medapart select (runtime-checked from battle_start.ss0): UP head (1),
// LEFT right arm (2), RIGHT left arm (3), DOWN none (0) in gUnk_03001800.unk82.
void part_select_input(void)
{
    u8 old = gUnk_03001800.unk82;

    if (KEYS_LO(gNewKeys) & 0x40)
        gUnk_03001800.unk82 = 1;
    if (KEYS_LO(gNewKeys) & 0x80)
        gUnk_03001800.unk82 = 0;
    if (KEYS_LO(gNewKeys) & 0x20)
        gUnk_03001800.unk82 = 2;
    if (KEYS_LO(gNewKeys) & 0x10)
        gUnk_03001800.unk82 = 3;
    if (gUnk_03001800.unk82 != old)
    {
        play_sound_effect(2);
        part_select_init_center_icon();
        part_select_init_head_icon(1);
        part_select_init_right_arm_icon(1);
        part_select_init_left_arm_icon(1);
        part_select_init_bottom_icon(1);
        part_select_draw_part_name();
        part_select_draw_skill_type();
        part_select_draw_skill_name();
        part_select_draw_head_uses();
        sub_0801BACC();
        sub_0801B894();
    }
}

void part_select_draw_part_name(void)
{
    s32 k;

    clear_sprite_table_mask(0x1F, 14);
    k = gUnk_03001800.unk82;
    if (k == 0)
        memcpy_bytes_08041D04(gUnk_083C4A10[3], gUnk_03000440.unk9E, 14);
    else if (k >= 0)
    {
        if (k <= 3)
            memcpy_bytes_08041D04((const void *)gUnk_083BB9CC[0][gUnk_03000590[gUnk_03001800.unk80].parts[k - 1].unk17 * 4 + k - 1], gUnk_03000440.unk9E, 15);
    }
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x1F, 10, 0x11, 10, 13, 0, 0);
}

void part_select_draw_skill_type(void)
{
    s32 k;

    clear_sprite_table_mask(0x2D, 13);
    k = gUnk_03001800.unk82;
    if (k == 0)
        fill_text_blank(gUnk_03000440.unk9E, 13);
    else if (k >= 0)
    {
        if (k <= 3)
        {
            if (gUnk_03000590[gUnk_03001800.unk80].parts[k - 1].unk11 == 0)
                memcpy_bytes_08041D04(gUnk_083C4A10[0], gUnk_03000440.unk9E, 14);
            else if (gUnk_03000590[gUnk_03001800.unk80].unkC9 == 0x2B && k == gUnk_03000590[gUnk_03001800.unk80].unkCA)
                memcpy_bytes_08041D04(gUnk_083C4A10[1], gUnk_03000440.unk9E, 14);
            else if (sub_08016E5C(gUnk_03001800.unk80, gUnk_03001800.unk82 - 1))
                memcpy_bytes_08041D04(gUnk_083C4A10[1], gUnk_03000440.unk9E, 14);
            else if (gUnk_03001800.unk82 == 1 && gUnk_03000590[gUnk_03001800.unk80].parts[0].unk10 == 0)
                memcpy_bytes_08041D04(gUnk_083C4A10[2], gUnk_03000440.unk9E, 14);
            else
                memcpy_bytes_08041D04((const void *)gUnk_083B6EC8[gUnk_03000590[gUnk_03001800.unk80].parts[gUnk_03001800.unk82 - 1].data[2]], gUnk_03000440.unk9E, 14);
        }
    }
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x2D, 0x13, 0xE, 10, 14, 0, 0);
}

void part_select_blink_status(void)
{
    u32 show = 0;
    s32 k = gUnk_03001800.unk82;

    if (k == 0)
        ;
    else if (k >= 0)
    {
        if (k <= 3)
        {
            if (gUnk_03000590[gUnk_03001800.unk80].parts[k - 1].unk11 == 0)
            {
                memcpy_bytes_08041D04(gUnk_083C4A10[0], gUnk_03000440.unk9E, 14);
                show = 1;
            }
            else if (gUnk_03000590[gUnk_03001800.unk80].unkC9 == 0x2B && k == gUnk_03000590[gUnk_03001800.unk80].unkCA)
            {
                memcpy_bytes_08041D04(gUnk_083C4A10[1], gUnk_03000440.unk9E, 14);
                show = 1;
            }
            else if (sub_08016E5C(gUnk_03001800.unk80, gUnk_03001800.unk82 - 1))
            {
                memcpy_bytes_08041D04(gUnk_083C4A10[1], gUnk_03000440.unk9E, 14);
                show = 1;
            }
            else if (gUnk_03001800.unk82 == 1 && gUnk_03000590[gUnk_03001800.unk80].parts[0].unk10 == 0)
            {
                memcpy_bytes_08041D04(gUnk_083C4A10[2], gUnk_03000440.unk9E, 14);
                show = 1;
            }
        }
    }
    if (show)
    {
        if (gUnk_03000440.unk84 & 8)
            clear_sprite_table_mask(0x2D, 13);
        else
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x2D, 0x13, 0xE, 10, 14, 0, 0);
    }
}

void part_select_draw_skill_name(void)
{
    s32 k;

    clear_sprite_table_mask(0x14, 11);
    k = gUnk_03001800.unk82;
    if (k == 0)
        fill_text_blank(gUnk_03000440.unk9E, 10);
    else if (k >= 0)
    {
        if (k <= 3)
            memcpy_bytes_08041D04((const void *)gUnk_083BE6E8[gUnk_03000590[gUnk_03001800.unk80].parts[k - 1].data[1]], gUnk_03000440.unk9E, 12);
    }
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x14, 0x15, 0x11, 8, 14, 0, 0);
}

void part_select_init_cursor(void)
{
    u8 v = gUnk_03000590[gUnk_03001800.unk80].unkDD;
    if (v > 3)
        v = 0;
    gUnk_03001800.unk82 = v;
}

void part_select_draw_head_uses(void)
{
    if (gUnk_03001800.unk82 == 1)
    {
        fill_tilemap_rect_08042698(2, 1, 0xE, 0xC, REG_BG0CNT, 0xD218);
        sub_08042A90(gUnk_03000590[gUnk_03001800.unk80].parts[0].unk10, gUnk_03000590[gUnk_03001800.unk80].parts[0].data[8], 0x10, 0xC, 0xD21A, REG_BG0CNT, 0xD220);
    }
    else
        vram_fill_tilemap_rect(7, 1, 0xE, 0xC, REG_BG0CNT, 0);
}

u32 sub_08016E5C(u32 rec, u32 part)
{
    switch (gUnk_03000590[rec].parts[part].data[1])
    {
    case 0x18:
    case 0x19:
    case 0x1A:
    case 0x28:
    case 0x35:
        return 1;
    default:
        return 0;
    }
}

INCLUDE_ASM("asm/nonmatching/code_080147FC", save_restore_bg1_tilemap_region);
INCLUDE_ASM("asm/nonmatching/code_080147FC", save_restore_bg0_tilemap_region);
INCLUDE_ASM("asm/nonmatching/code_080147FC", draw_partial_bg1_column);
INCLUDE_ASM("asm/nonmatching/code_080147FC", scroll_tilemap_window);

void sub_08016FB4(void)
{
    u32 i;
    for (i = 0; i < 6; i++)
    {
        gUnk_03002C30[i].unk9 += 8;
        gUnk_03002C30[i].unk8 += 8;
        if (gUnk_03002C30[i].unk9 > 0x40 - (0x90 - gUnk_03002C30[i].unk4) / 2)
        {
            gUnk_03002C30[i].unk9 = 0x40 - (0x90 - gUnk_03002C30[i].unk4) / 2;
            gUnk_03002C30[i].unk8 = 0x40 - (0x90 - gUnk_03002C30[i].unk4) / 2;
        }
    }
}

void sub_08017004(void)
{
    set_tilemap_and_decompress_bg(9, 0x15, gUnk_084888E4, REG_BG0CNT, 0x2A0);
    set_tilemap_and_decompress_bg(0x12, 0x15, gUnk_08488920, REG_BG1CNT, 0x2B8);
}

void sub_08017048(void)
{
    if (gUnk_03000440.unk84 < 4)
        write_vram_tilemap_rect(0xC, 4, 9, 0x13 - gUnk_03000440.unk84, REG_BG0CNT, gUnk_02020800);
}

void sub_08017084(void)
{
    if (gUnk_03000440.unk84 < 12)
    {
        read_vram_tilemap_rect(gUnk_03000440.unk84 + 1, 4, 0x12, 0x15, REG_BG1CNT, gUnk_02021000);
        write_vram_tilemap_rect(gUnk_03000440.unk84 + 1, 4, 0x1D - gUnk_03000440.unk84, 0xD, REG_BG1CNT, gUnk_02021000);
    }
}

void sub_080170D4(void)
{
    u32 v = gUnk_03000590[gUnk_03001800.unk80].unkDD;
    if (v <= 3)
        v = 0;
    else
        v -= 5;
    gUnk_03001800.unk82 = v;
}

void sub_08017104(void)
{
    gUnk_03002C30[0].unk0 = 0xC404;
    gUnk_03002C30[0].unk1C = 0;
    gUnk_03002C30[0].unk2 = 0x78;
    gUnk_03002C30[0].unk4 = 0x78;
    gUnk_03002C30[0].unkA = 0xA;
    gUnk_03002C30[0].unkB = 0xC0;
    gUnk_03002C30[0].unk6 = 0x61A;
}

void sub_08017130(u32 a)
{
    gUnk_03002C30[1].unk0 = 0xC404;
    gUnk_03002C30[1].unk1C = 0;
    gUnk_03002C30[1].unk2 = 0x78;
    gUnk_03002C30[1].unk4 = 0x84;
    gUnk_03002C30[1].unkA = 0xA;
    gUnk_03002C30[1].unkB = 0xC0;
    gUnk_03002C30[1].unk6 = a * 4 + 0x61E;
}

void sub_08017178(u32 a)
{
    gUnk_03002C30[2].unk0 = 0xC404;
    gUnk_03002C30[2].unk1C = 0;
    gUnk_03002C30[2].unk2 = 0x78;
    gUnk_03002C30[2].unk4 = 0x6C;
    gUnk_03002C30[2].unkA = 0xA;
    gUnk_03002C30[2].unkB = 0xC0;
    gUnk_03002C30[2].unk6 = a * 4 + 0x61B;
}

void sub_080171C0(u32 a)
{
    gUnk_03002C30[3].unk0 = 0xC404;
    gUnk_03002C30[3].unk1C = 0;
    gUnk_03002C30[3].unk2 = 0x6C;
    gUnk_03002C30[3].unk4 = 0x78;
    gUnk_03002C30[3].unkA = 0xA;
    gUnk_03002C30[3].unkB = 0xC0;
    gUnk_03002C30[3].unk6 = a * 4 + 0x61C;
}

void sub_08017208(u32 a)
{
    gUnk_03002C30[4].unk0 = 0xC404;
    gUnk_03002C30[4].unk1C = 0;
    gUnk_03002C30[4].unk2 = 0x84;
    gUnk_03002C30[4].unk4 = 0x78;
    gUnk_03002C30[4].unkA = 0xA;
    gUnk_03002C30[4].unkB = 0xC0;
    gUnk_03002C30[4].unk6 = a * 4 + 0x61D;
}

// guess: Medaforce select names (cases 1-3 open at Medal level 10/30/60), same layout as the part select
void sub_08017268(void)
{
    clear_sprite_table_mask(0x14, 16);
    switch (gUnk_03001800.unk82)
    {
    case 0:
        memcpy_bytes_08041D04(gUnk_083C4A10[3], gUnk_03000440.unk9E, 14);
        break;
    case 1:
        if (gUnk_03000590[gUnk_03001800.unk80].medal.unk5 > 9)
        {
            memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000590[gUnk_03001800.unk80].medal.unk1 * 3, &gUnk_03000440.unkEE, 3);
            memcpy_bytes_0803F63C((const void *)gUnk_083B7338[gUnk_03000440.unkEE], gUnk_03000440.unk9E, 17);
        }
        else
            fill_text_blank(gUnk_03000440.unk9E, 13);
        break;
    case 2:
        if (gUnk_03000590[gUnk_03001800.unk80].medal.unk5 > 29)
        {
            memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000590[gUnk_03001800.unk80].medal.unk1 * 3, &gUnk_03000440.unkEE, 3);
            memcpy_bytes_0803F63C((const void *)gUnk_083B7338[gUnk_03000440.unkEF], gUnk_03000440.unk9E, 17);
        }
        else
            fill_text_blank(gUnk_03000440.unk9E, 13);
        break;
    case 3:
        if (gUnk_03000590[gUnk_03001800.unk80].medal.unk5 > 59)
        {
            memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000590[gUnk_03001800.unk80].medal.unk1 * 3, &gUnk_03000440.unkEE, 3);
            memcpy_bytes_0803F63C((const void *)gUnk_083B7338[gUnk_03000440.unkF0], gUnk_03000440.unk9E, 17);
        }
        else
            fill_text_blank(gUnk_03000440.unk9E, 13);
        break;
    }
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x14, 10, 0x11, 10, 13, 0, 0);
}

void sub_080173B4(u32 a)
{
    u8 err = 0;
    u8 blank = 0;

    clear_sprite_table_mask(0x24, 13);
    switch (gUnk_03001800.unk82)
    {
    case 0:
        fill_text_blank(gUnk_03000440.unk9E, 13);
        blank = 1;
        break;
    case 1:
        
        if (gUnk_03000590[gUnk_03001800.unk80].medal.unk5 > 9)
        {
            if (gUnk_03001800.unk58 == 0)
            {
                if (gUnk_03000590[gUnk_03001800.unk80].unkC1 == 0x50)
                {
                    memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000590[gUnk_03001800.unk80].medal.unk1 * 3, &gUnk_03000440.unkEE, 3);
                    memcpy_bytes_08041D04(gUnk_083B7CD4 + gUnk_03000440.unkEE * 6, gUnk_03000440.unk10E, 6);
                    memcpy_bytes_0803F63C((const void *)gUnk_083B6EC8[gUnk_03000440.unk10E[1]], gUnk_03000440.unk9E, 14);
                    sub_08017734(0);
                }
                else
                {
                    memcpy_bytes_08041D04(gUnk_083C4A10[4], gUnk_03000440.unk9E, 14);
                    err = 1;
                }
            }
            else
            {
                memcpy_bytes_08041D04(gUnk_083C4A10[1], gUnk_03000440.unk9E, 14);
                err = 1;
            }
        }
        else
        {
            memcpy_bytes_08041D04(gUnk_083C4A10[5], gUnk_03000440.unk9E, 14);
            err = 1;
        }
        break;
    case 2:
        
        if (gUnk_03000590[gUnk_03001800.unk80].medal.unk5 > 29)
        {
            if (gUnk_03001800.unk58 == 0)
            {
                if (gUnk_03000590[gUnk_03001800.unk80].unkC1 == 0x50)
                {
                    memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000590[gUnk_03001800.unk80].medal.unk1 * 3, &gUnk_03000440.unkEE, 3);
                    memcpy_bytes_08041D04(gUnk_083B7CD4 + gUnk_03000440.unkEF * 6, gUnk_03000440.unk10E, 6);
                    memcpy_bytes_0803F63C((const void *)gUnk_083B6EC8[gUnk_03000440.unk10E[1]], gUnk_03000440.unk9E, 14);
                    sub_08017734(0);
                }
                else
                {
                    memcpy_bytes_08041D04(gUnk_083C4A10[4], gUnk_03000440.unk9E, 14);
                    err = 1;
                }
            }
            else
            {
                memcpy_bytes_08041D04(gUnk_083C4A10[1], gUnk_03000440.unk9E, 14);
                err = 1;
            }
        }
        else
        {
            memcpy_bytes_08041D04(gUnk_083C4A10[5], gUnk_03000440.unk9E, 14);
            err = 1;
        }
        break;
    case 3:
        
        if (gUnk_03000590[gUnk_03001800.unk80].medal.unk5 > 59)
        {
            if (gUnk_03001800.unk58 == 0)
            {
                if (gUnk_03000590[gUnk_03001800.unk80].unkC1 == 0x50)
                {
                    memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000590[gUnk_03001800.unk80].medal.unk1 * 3, &gUnk_03000440.unkEE, 3);
                    memcpy_bytes_08041D04(gUnk_083B7CD4 + gUnk_03000440.unkF0 * 6, gUnk_03000440.unk10E, 6);
                    memcpy_bytes_0803F63C((const void *)gUnk_083B6EC8[gUnk_03000440.unk10E[1]], gUnk_03000440.unk9E, 14);
                    sub_08017734(0);
                }
                else
                {
                    memcpy_bytes_08041D04(gUnk_083C4A10[4], gUnk_03000440.unk9E, 14);
                    err = 1;
                }
            }
            else
            {
                memcpy_bytes_08041D04(gUnk_083C4A10[1], gUnk_03000440.unk9E, 14);
                err = 1;
            }
        }
        else
        {
            memcpy_bytes_08041D04(gUnk_083C4A10[5], gUnk_03000440.unk9E, 14);
            err = 1;
        }
        break;
    }
    if (err == 1 || blank == 1)
        sub_08017734(1);
    if (a)
    {
        if (err)
        {
            if (!(gUnk_03000440.unk84 & 8))
                render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x24, 0x13, 0xE, 10, 14, 0, 0);
        }
        else
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x24, 0x13, 0xE, 10, 14, 0, 0);
    }
    else
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x24, 0x13, 0xE, 10, 14, 0, 0);
}

void sub_080175FC(void)
{
    u8 old = gUnk_03001800.unk82;

    if (KEYS_LO(gNewKeys) & 0x40)
        gUnk_03001800.unk82 = 1;
    if (KEYS_LO(gNewKeys) & 0x80)
        gUnk_03001800.unk82 = 0;
    if (KEYS_LO(gNewKeys) & 0x20)
        gUnk_03001800.unk82 = 2;
    if (KEYS_LO(gNewKeys) & 0x10)
        gUnk_03001800.unk82 = 3;
    if (gUnk_03001800.unk82 != old)
    {
        play_sound_effect(2);
        sub_08017178(1);
        sub_080171C0(1);
        sub_08017208(1);
        sub_08017130(1);
        sub_08017268();
        sub_080173B4(0);
    }
}

void sub_0801767C(void)
{
    switch (gUnk_03001800.unk82)
    {
    case 0:
        if (gUnk_03000440.unk84 & 8)
            sub_08017130(1);
        else
            sub_08017130(0);
        break;
    case 1:
        if (gUnk_03000440.unk84 & 8)
            sub_08017178(1);
        else
            sub_08017178(0);
        break;
    case 2:
        if (gUnk_03000440.unk84 & 8)
            sub_080171C0(1);
        else
            sub_080171C0(0);
        break;
    case 3:
        if (gUnk_03000440.unk84 & 8)
            sub_08017208(1);
        else
            sub_08017208(0);
        break;
    }
}

void sub_08017734(u32 a)
{
    u32 i = 0;
    u32 j;
    u8 n;
    int k;

    if (a == 0)
    {
        memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000590[gUnk_03001800.unk80].medal.unk1 * 3, &gUnk_03000440.unkEE, 3);
        k = gUnk_03001800.unk82 - 1;
        memcpy_bytes_08041D04(gUnk_083B7CD4 + (&gUnk_03000440.unkEE)[k] * 6, gUnk_03000440.unk10E, 6);
        n = gUnk_03000440.unk10E[2] / 10;
        for (j = 0; j < 8 - n; j++)
        {
            vram_fill_tilemap_rect(1, 1, i + 1, 0x11, REG_BG0CNT, 0);
            i++;
        }
        for (j = i; j <= 7; j++)
        {
            if (!(gUnk_03000440.unk84 & 4))
                fill_tilemap_rect_08042698(1, 1, i + 1, 0x11, REG_BG0CNT, 0xB208);
            else
                fill_tilemap_rect_08042698(1, 1, i + 1, 0x11, REG_BG0CNT, 0xC208);
            i++;
        }
        vram_fill_tilemap_rect(5, 1, 4, 0x12, REG_BG1CNT, 0);
        divide_by_100000_08042838(gUnk_03000440.unk10E[2], 4, 0x12, 2, REG_BG1CNT, 0xD220);
        draw_battle_panel_left_b(gUnk_03001800.unk80);
    }
    else
    {
        vram_fill_tilemap_rect(8, 1, 1, 0x11, REG_BG0CNT, i);
        draw_medaforce_gauge_value(gUnk_03001800.unk80);
        if (gUnk_03000590[gUnk_03001800.unk80].unkC1 != 0x50)
            draw_battle_panel_left_a(gUnk_03001800.unk80);
    }
}

void sub_080178CC(void)
{
    if (gUnk_03000590[gUnk_03001800.unk80].unkC1 == 0x50)
    {
        gUnk_03001800.unk85++;
        if (gUnk_03001800.unk85 & 8)
            draw_battle_panel_left_b(gUnk_03001800.unk80);
        else
            draw_battle_panel_left_a(gUnk_03001800.unk80);
    }
}

void sub_08017914(void)
{
    if (gUnk_03000590[gUnk_03001800.unk80].unkC1 == 0x50)
        draw_battle_panel_left_b(gUnk_03001800.unk80);
    else
        draw_battle_panel_left_a(gUnk_03001800.unk80);
}

void sub_08017948(void)
{
    if (gUnk_03000440.unk84 <= 11)
    {
        read_vram_tilemap_rect(13, 4, 0x11, 13, REG_BG1CNT, gUnk_02021000);
        write_vram_tilemap_rect(13, 4, 0x12, 13, REG_BG1CNT, gUnk_02021000);
    }
}

void setup_battle_bot_sprites_08017994(u32 rec, u32 x, u32 y)
{
    u32 slot, side, k;

    if (rec <= 2)
    {
        slot = rec;
        side = 0;
    }
    else
    {
        slot = rec - 3;
        side = 1;
    }
    if (slot == gUnk_03000440.unk3D)
        k = 0;
    else if (slot == gUnk_03000440.unk46)
        k = 1;
    else
        return;
    get_bot_part_effective_values(rec, gUnk_03001800.unk64);
    init_battle_medabot_sprites(gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2], gUnk_03001800.unk64[3],
                                rec, k * 4, x, y, side, 2, k * 4);
}

void position_battle_team_cursors(u32 first, u32 flag)
{
    u32 i;
    u32 x, y;

    for (i = 0; i < 3; i++)
    {
        if (gUnk_03000590[first + i].unk40)
        {
            x = gUnk_083AD3A4[(first + i) * 2];
            y = gUnk_083AD3A4[(first + i) * 2 + 1];
            if (first + i <= 2)
            {
                if (flag)
                    x -= 0x68;
            }
            else
            {
                if (flag)
                    x += 0x68;
            }
            setup_battle_bot_sprites_08017994(first + i, x, y);
        }
    }
}

void setup_bot_battle_sprites_08017A7C(u32 rec, u32 x, u32 y)
{
    u32 slot, side, k;

    if (rec <= 2)
    {
        slot = rec;
        side = 0;
    }
    else
    {
        slot = rec - 3;
        side = 1;
    }
    if (slot == gUnk_03000440.unk3D)
        k = 0;
    else if (slot == gUnk_03000440.unk46)
        k = 1;
    else
        return;
    get_bot_part_effective_values(rec, gUnk_03001800.unk64);
    setup_battle_sprite_group(gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2], gUnk_03001800.unk64[3],
                              rec, k * 4, x, y, side, 2, k * 4);
    gUnk_03002C30[k * 4 + 1].unk0 &= 0xFDFF;
    gUnk_03002C30[k * 4 + 2].unk0 &= 0xFDFF;
}

void init_battle_cursor_sprite_08017B24(void)
{
    u32 x, y, i;

    gUnk_03002C30[8].unk0 = 0xC404;
    gUnk_03002C30[8].unk1C = 0;
    gUnk_03002C30[8].unkA = 0xE;
    gUnk_03002C30[8].unkB = 0xC0;
    x = gUnk_083AD3A4[(gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3) * 2];
    y = gUnk_083AD3A4[(gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3) * 2 + 1];
    if (gUnk_03000440.unk3C == 0)
    {
        gUnk_03002C30[8].unk2 = x + 16;
        gUnk_03002C30[8].unk4 = y;
        gUnk_03002C30[8].unk6 = 0x306;
    }
    else
    {
        gUnk_03002C30[8].unk2 = x - 16;
        gUnk_03002C30[8].unk4 = y;
        gUnk_03002C30[8].unk6 = 0x307;
    }
}

void render_battle_bot_label(void)
{
    clear_sprite_table_mask(9, 13);
    if (gUnk_03000440.unk3C == 0)
        render_text_sprites_08040DB8(gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].medal.unkA, 9, 0x11, 0xE, 10, 15, 0, 0);
    else
        render_text_sprites_08040DB8(gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].medal.unkA, 9, 3, 0xE, 10, 15, 0, 0);
}

void draw_bg_window_rect(u32 a)
{
    if (a == 0)
    {
        if (gUnk_03000440.unk3C == 0)
            fill_tilemap_rect_08042698(2, 2, 0x1A, 0x11, REG_BG0CNT, 0x8304);
        else
            fill_tilemap_rect_08042698(2, 2, 2, 0x11, REG_BG0CNT, 0x8300);
    }
    else
    {
        if (gUnk_03000440.unk3C == 0)
            vram_fill_tilemap_rect(2, 2, 0x1A, 0x11, REG_BG0CNT, 0);
        else
            vram_fill_tilemap_rect(2, 2, 2, 0x11, REG_BG0CNT, 0);
    }
}

void animate_bg_window_blink(void)
{
    gUnk_03000440.unk86++;
    if (gUnk_03000440.unk86 & 8)
        draw_bg_window_rect(0);
    else
        draw_bg_window_rect(1);
}

void sub_08017D14(void)
{
    u32 i, y;

    for (i = 0, y = 2; i <= 4; y += 2, i++)
        fill_tilemap_rect_08042698(2, 2, 9, y, REG_BG1CNT, i * 4 + 0xC370);
}

void load_bot_sprite_tiles_to_vram(void)
{
    CpuFastSet(gUnk_084C21BC + gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].medal.unk1 * 0x80, (void *)0x06007800, 0x20);
}

void copy_battle_bot_data_to_state(void)
{
    clear_sprite_table_mask(0x16, 10);
    memcpy_bytes_0803F63C((const void *)gUnk_083B6410[gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].medal.unk1], gUnk_03000440.unk9E, 11);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x16, 0xD, 2, 7, 12, 1, 2);
}

void battle_load_script_to_buffer(void)
{
    u32 i;

    clear_sprite_table_mask(0x20, 0x38);
    for (i = 0; i <= 3; i++)
    {
        memcpy_bytes_08041D04((const void *)gUnk_083BB9CC[0][gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].parts[i].unk17 * 4 + i], gUnk_03000440.unk9E, 15);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20 + i * 14, 0xD, 4 + i * 2, 10, 13, 1, 2);
    }
}

void battle_setup_bot_font_tile(void)
{
    u32 i;

    for (i = 0; i <= 3; i++)
    {
        load_part_data(gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].parts[i].unk17, i, &gUnk_03000440.unkEE);
        memcpy_bytes_08041D04(gUnk_083B6158[gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].medal.unk1], gUnk_03000440.unk10E, 16);
        if (gUnk_03000440.unkEE == gUnk_03000440.unk10E[1])
            fill_tilemap_rect_08042698(2, 2, 0xB, i * 2 + 4, REG_BG1CNT, gUnk_03000440.unk10E[7] * 4 + 0xD340);
        else
            fill_tilemap_rect_08042698(2, 2, 0xB, i * 2 + 4, REG_BG1CNT, 0xD340);
    }
}

void render_battle_bot_status_row(void)
{
    u32 i;
    u16 pal;

    for (i = 0; i <= 3; i++)
    {
        pal = gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].parts[i].unk11 ? 0xA000 : 0xB000;
        sub_08042950(gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].parts[i].unk11, 0x17, i * 2 + 4, 3, REG_BG1CNT, pal | 0x390);
        fill_tilemap_rect_08042698(1, 2, 0x1A, i * 2 + 4, REG_BG1CNT, pal | 0x3A4);
        sub_08042950(gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].parts[i].data[4], 0x1B, i * 2 + 4, 3, REG_BG1CNT, pal | 0x390);
    }
}

void set_game_state_params(u8 a, u8 b, u8 c, u8 d)
{
    gUnk_03000440.unk98 = a;
    gUnk_03000440.unk99 = b;
    gUnk_03000440.unk9A = c;
    gUnk_03000440.unk9B = d;
}

void init_ewram_buffers_and_state(void)
{
    struct Unk_08047414 *obj = (struct Unk_08047414 *)0x02026000;
    u8 *b;
    u8 *c;
    u32 fill;

    sub_0803F624((u8 *)obj, 0xD0, 0);
    b = (u8 *)0x020260D0;
    sub_0803F624(b, 0x800, 0);
    c = (u8 *)0x020268D0;
    sub_0803F624(c, 0x60, 0);
    gUnk_03000440.unk96 = 1;
    gUnk_03000430 = 2;
    gUnk_03002414 = (struct Unk_03002414 *)0x02024000;
    fill = 0;
    CpuFastSet(&fill, (void *)0x02024000, 0x01000426);
    gUnk_03005308 = c;
    sub_08047414(obj, (u8 *)gUnk_03002414, (u32)gUnk_083D1BF8, (u32)b);
    obj->unk8 = (u32)b;
    setup_scene_bg_layers_and_sprites(gUnk_03002414->unkB84, obj,
        gUnk_03000440.unk98, gUnk_03000440.unk99, gUnk_03000440.unk9A, gUnk_03000440.unk9B,
        0x28, 0x28, 0x1C2, 8, 1, 0);
}

void setup_scene_from_game_state(void)
{
    struct Unk_08047414 *obj = (struct Unk_08047414 *)0x02026000;
    u32 fill;

    obj->unk8 = 0x020260D0;
    setup_scene_bg_layers_and_sprites(gUnk_03002414->unkB84, obj,
        gUnk_03000440.unk98, gUnk_03000440.unk99, gUnk_03000440.unk9A, gUnk_03000440.unk9B,
        0x28, 0x28, 0x1C2, 8, 1, 0);
    fill = 0x200;
    CpuFastSet(&fill, gUnk_03002414->unkB84, 0x01000100);
    gUnk_03002414->unk1094 = 0;
    gUnk_03002414->unk1095 = 0;
}

void setup_scene_bg_from_game_state(void)
{
    setup_scene_bg_layers_and_sprites(gUnk_03002414->unkB84, (struct Unk_08047414 *)0x02026000,
        gUnk_03000440.unk98, gUnk_03000440.unk99, gUnk_03000440.unk9A, gUnk_03000440.unk9B,
        0x44, 0x2A, 0x1C2, 8, 5, 0);
}

u32 sub_0801827C(void)
{
    u8 x = gUnk_083AD3A4[(gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3) * 2];

    if (gUnk_03000440.unk3C == 0)
        return x + 16;
    else
        return x - 16;
}

void sub_080182AC(void)
{
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_080182D0(void)
{
    if (gUnk_03000440.unk46 == 2)
        gUnk_03000440.unk46 = 0;
    else
        gUnk_03000440.unk46++;
    if (gUnk_03000440.unk3D == gUnk_03000440.unk46)
    {
        if (gUnk_03000440.unk3D == 2)
            gUnk_03000440.unk46 = 0;
        else
            gUnk_03000440.unk46++;
    }
}

void setup_battle_bot_display(void)
{
    u32 i, rec;
    struct Unk_03000590 *recs;

    clear_sprite_table_mask(4, 1);
    clear_sprite_table_mask(5, 1);
    clear_sprite_table_mask(6, 1);
    clear_sprite_table_mask(7, 1);
    for (i = 0, recs = gUnk_03000590; i <= 2; i++)
    {
        rec = gUnk_03000440.unk3C * 3 + i;
        if (recs[rec].unk40 && i != gUnk_03000440.unk3D)
            setup_battle_bot_sprites_08017994(rec, gUnk_083AD3A4[rec * 2], gUnk_083AD3A4[rec * 2 + 1]);
    }
    update_battle_sprite_orbiting_positions(0, gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3, gUnk_03000440.unk3C);
}

INCLUDE_ASM("asm/nonmatching/code_080147FC", handle_battle_bot_selection);

void display_battle_cursor_on_bot(void)
{
    u32 x = gUnk_083AD3A4[(gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3) * 2];
    u32 y = gUnk_083AD3A4[(gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3) * 2 + 1];

    setup_bot_battle_sprites_08017A7C(gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3, x, y);
    clear_battle_sprite_slot(8, 1);
    draw_bg_window_rect(1);
}

INCLUDE_ASM("asm/nonmatching/code_080147FC", animate_battle_field_scroll);

void toggle_battle_team_side(void)
{
    gUnk_03000440.unk3D = 0;
    gUnk_03000440.unk3C ^= 1;
    position_battle_team_cursors(gUnk_03000440.unk3C * 3, 1);
}

INCLUDE_ASM("asm/nonmatching/code_080147FC", animate_battle_bots_entry);
