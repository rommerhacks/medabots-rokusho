#include "global.h"
#include "keys.h"

INCLUDE_ASM("asm/nonmatching/code_08018900", sub_08018900);

void sub_080189EC(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[i].unk40)
            sub_08018900(i);
    }
}

void sub_08018A18(void)
{
    u32 i;

    if ((gUnk_030057E0.unkC2E & 0xF0) == 0x20)
    {
        for (i = 0; i <= 2; i++)
            gUnk_03000590[i + 3].unkC1 = 0x50;
    }
}

void select_battle_music(void)
{
    if (gUnk_03000440.unk89 == 1)
        play_song(9);
    else if ((gUnk_030057E0.unkC2E & 0xF0) != 0)
    {
        if ((gUnk_030057E0.unkC2E & 0xF0) == 0x10)
            play_song(0xC);
        else
            play_song(0xD);
    }
    else
        play_song(gUnk_083AD3B0[gUnk_03000B94]);
}

INCLUDE_ASM("asm/nonmatching/code_08018900", init_battle_action_select_ui);

void robattle_time_init(void)
{
    if (gUnk_03000440.unk89 == 1)
    {
        gUnk_03001800.unk57 = 40;
        return;
    }
    switch (gUnk_03001788)
    {
    case 0:
        gUnk_03001800.unk57 = 40;
        break;
    case 1:
        gUnk_03001800.unk57 = 30;
        break;
    case 2:
        gUnk_03001800.unk57 = 20;
        break;
    }
}

void robattle_time_tick(void)
{
    if ((gUnk_03001800.unk56 = (gUnk_03001800.unk56 + 1) & 0x1F) == 0 && gUnk_03001800.unk57 != 0)
    {
        gUnk_03001800.unk57--;
        gUnk_03001800.unk16B++;
        sub_08018CBC();
    }
}

void robattle_time_draw(void)
{
    gUnk_03002C30[1].unk6 = (u8)(gUnk_03001800.unk57 / 10) + 0x624;
    gUnk_03002C30[2].unk6 = (u8)(gUnk_03001800.unk57 % 10) + 0x624;
}

void sub_08018CBC(void)
{
    u32 i;

    gUnk_03001800.unk55 = 0;
    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40)
        {
            if (gUnk_03000590[i].unkC4)
                sub_08018D0C(i);
            if (gUnk_03000590[i].unkC9)
                sub_08018DF4(i);
        }
    }
}

void sub_08018D0C(u32 rec)
{
    s32 t;
    u32 i, k, v, done;

    t = gUnk_03000590[rec].unkC6 - 4;
    if (t <= 0)
    {
        gUnk_03000590[rec].unkC4 = 0;
        gUnk_03000590[rec].unkC5 = 0;
        gUnk_03000590[rec].unkC6 = 0;
        gUnk_03000590[rec].unkC7 = 0;
        gUnk_03000590[rec].unkCE |= 1;
        gUnk_03001800.unk55 |= 2;
        return;
    }
    gUnk_03000590[rec].unkC6 = t;
    if (gUnk_03000590[rec].unkC4 != 0x1F)
        return;
    gUnk_03001800.unk59 = gUnk_03000590[rec].unkC7;
    gUnk_03001800.unk86 = 0;
    done = 0;
    for (i = 0; i <= 3; i++)
    {
        k = sub_08018EE0(rec);
        if (k != 0)
        {
            v = add_part_stat_clamped(rec, k - 1, gUnk_03001800.unk59);
            gUnk_03001800.unk86 += v;
            gUnk_03001800.unk59 = (v & 0xFF00) >> 8;
            done = 1;
            if (gUnk_03001800.unk59 == 0)
                break;
        }
        else
            break;
    }
    if (done)
    {
        gUnk_03000590[rec].unkC8 = gUnk_03001800.unk86;
        gUnk_03000590[rec].unkCE |= 4;
        gUnk_03001800.unk55 |= 8;
    }
}

void sub_08018DF4(u32 rec)
{
    s32 t;
    u32 i, k, v, done;

    t = gUnk_03000590[rec].unkCB - 4;
    if (t <= 0)
    {
        gUnk_03000590[rec].unkC9 = 0;
        gUnk_03000590[rec].unkCA = 0;
        gUnk_03000590[rec].unkCB = 0;
        gUnk_03000590[rec].unkCC = 0;
        gUnk_03000590[rec].unkCE |= 2;
        gUnk_03001800.unk55 |= 4;
        return;
    }
    gUnk_03000590[rec].unkCB = t;
    if ((u8)(gUnk_03000590[rec].unkC9 - 0x13) > 1)
        return;
    gUnk_03001800.unk59 = gUnk_03000590[rec].unkCC;
    gUnk_03001800.unk86 = 0;
    done = 0;
    for (i = 0; i <= 3; i++)
    {
        k = sub_08018F6C(rec);
        if (k != 0)
        {
            v = sub_08018FF0(rec, k - 1, gUnk_03001800.unk59);
            gUnk_03001800.unk86 += v;
            gUnk_03001800.unk59 = (v & 0xFF00) >> 8;
            done = 1;
            if (gUnk_03001800.unk59 == 0)
                break;
        }
        else
            break;
    }
    if (done)
    {
        gUnk_03000590[rec].unkCD = gUnk_03001800.unk86;
        gUnk_03000590[rec].unkCE |= 8;
        gUnk_03001800.unk55 |= 0x10;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08018900", sub_08018EE0);
INCLUDE_ASM("asm/nonmatching/code_08018900", add_part_stat_clamped);

u32 sub_08018F48(u32 rec)
{
    u32 i;

    for (i = 0; i <= 3; i++)
    {
        if (gUnk_03000590[rec].parts[3 - i].unk11)
            return i + 1;
    }
    return 0;
}

u32 sub_08018F6C(u32 rec)
{
    u32 k, i;

    if (gUnk_03000590[rec].unkCA == 0)
        k = 4;
    else
        k = gUnk_03000590[rec].unkCA;
    for (i = 0; i <= 3; i++)
    {
        if (gUnk_03000590[rec].parts[k - 1].unk11 > 1)
            return k;
        k--;
        if (k == 0)
            k = 4;
    }
    return 0;
}

u32 sub_08018FB8(u32 rec, u32 part, s32 amount)
{
    u32 cur = gUnk_03000590[rec].parts[part].unk11;
    s32 v = cur - amount;
    u32 ret;

    if (v >= 0)
    {
        gUnk_03000590[rec].parts[part].unk11 = v;
        ret = amount;
    }
    else
    {
        gUnk_03000590[rec].parts[part].unk11 = 0;
        ret = ((amount - cur) << 8) + cur;
    }
    return ret;
}

u32 sub_08018FF0(u32 rec, u32 part, s32 amount)
{
    u32 cur = gUnk_03000590[rec].parts[part].unk11;
    u32 m = cur - 1;
    u32 ret;

    if ((s32)(m - amount) >= 0)
    {
        gUnk_03000590[rec].parts[part].unk11 = cur - amount;
        ret = amount;
    }
    else
    {
        gUnk_03000590[rec].parts[part].unk11 = 1;
        ret = ((amount - m) << 8) + m;
    }
    return ret;
}

void sub_0801902C(void)
{
    u32 i;

    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40 && (u8)(gUnk_03000590[i].unkC9 - 0xF) > 1)
        {
            sub_080190B8(i);
            battle_bot_move(i);
            sub_08019544(i);
        }
    }
}

void sub_08019078(void)
{
    u32 i;

    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40 && (u8)(gUnk_03000590[i].unkC9 - 0xF) > 1)
        {
            sub_08019544(i);
        }
    }
}

void sub_080190B8(u32 rec)
{
    gUnk_03000590[rec].unkBB = 0;
    sub_08019108(rec);
    sub_080191C0(rec);
    sub_080191E4(rec);
    sub_0801922C(rec);
    sub_08019264(rec);
    sub_0801928C(rec);
    sub_080192B8(rec);
    sub_080192E8(rec);
    sub_0801932C(rec);
}

void sub_08019108(u32 rec)
{
    if (gUnk_03000590[rec].unkDD == 0)
        return;
    if (gUnk_03000590[rec].unkDD > 3)
    {
        sub_08019184(rec, 12);
        return;
    }
    if (gUnk_03000590[rec].parts[gUnk_03000590[rec].unkDD - 1].unk11 == 0)
        return;
    if (gUnk_03000590[rec].unkDD == 1)
        sub_08019184(rec, 6);
    else if (!(gUnk_03000590[rec].unkBD & 4))
        sub_08019184(rec, gUnk_03000590[rec].parts[gUnk_03000590[rec].unkDD - 1].data[8]);
    else
        sub_08019184(rec, gUnk_03000590[rec].parts[gUnk_03000590[rec].unkDD - 1].data[9]);
}

void sub_08019184(u32 rec, u32 n)
{
    n += gUnk_03000590[rec].unkBB;
    if (n > 0xFF)
        n = 0xFF;
    gUnk_03000590[rec].unkBB = n;
}

void sub_080191A4(u32 rec, u32 n)
{
    s32 v = gUnk_03000590[rec].unkBB - n;

    if (v < 0)
        v = 0;
    gUnk_03000590[rec].unkBB = v;
}

void sub_080191C0(u32 rec)
{
    if (gUnk_03000590[rec].parts[3].unk11 == 0)
        sub_08019184(rec, 6);
}

void sub_080191E4(u32 rec)
{
    memcpy_bytes_08041D04(&gUnk_083C4C10[gUnk_03001800.unk38 + (gUnk_03000590[rec].parts[3].data[1] - 100) * 11], &gUnk_03000440.unkEE, 1);
    sub_08019184(rec, gUnk_03000440.unkEE);
}

void sub_0801922C(u32 rec)
{
    if (gUnk_03000590[rec].unkC9 != 0 && ((u8)(gUnk_03000590[rec].unkC9 - 0x11) <= 1 || gUnk_03000590[rec].unkC9 == 0x29))
        sub_08019184(rec, gUnk_03000590[rec].unkCC);
}

void sub_08019264(u32 rec)
{
    sub_080191A4(rec, (u8)(gUnk_03000590[rec].medal.unk5 / 10));
}

void sub_0801928C(u32 rec)
{
    sub_080191A4(rec, (u8)(gUnk_03000590[rec].parts[3].unk12 / 20));
}

void sub_080192B8(u32 rec)
{
    if (gUnk_03000590[rec].unkC4 != 0 && (gUnk_03000590[rec].unkC4 == 0x26 || gUnk_03000590[rec].unkC4 == 0x29))
        sub_080191A4(rec, gUnk_03000590[rec].unkC7);
}

void sub_080192E8(u32 rec)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[rec].parts[i].data[1] == 0x28 && gUnk_03000590[rec].parts[i].unk11 != 0)
            sub_080191A4(rec, gUnk_03000590[rec].parts[i].data[6]);
    }
}

void sub_0801932C(u32 rec)
{
    if (gUnk_03000590[rec].unkBB > 0x1F)
        gUnk_03000590[rec].unkBB = 0x1F;
}

void battle_bot_move(u32 rec)
{

    gUnk_03000590[rec].unkD7 += 0x20 - gUnk_03000590[rec].unkBB;
    gUnk_03000590[rec].unkDA = gUnk_03000590[rec].unkD7 / 16;
    gUnk_03000590[rec].unkD7 %= 16;
    if (rec <= 2)
    {
        if (!(gUnk_03000590[rec].unkBD & 4))
        {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 + gUnk_03000590[rec].unkDA > 0x68)
                gUnk_03002C30[rec * 4 + 0x5D].unk2 = 0x68;
            else
                gUnk_03002C30[rec * 4 + 0x5D].unk2 += gUnk_03000590[rec].unkDA;
        }
        else
        {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 - gUnk_03000590[rec].unkDA < 0x28)
                gUnk_03002C30[rec * 4 + 0x5D].unk2 = 0x28;
            else
                gUnk_03002C30[rec * 4 + 0x5D].unk2 -= gUnk_03000590[rec].unkDA;
        }
    }
    else
    {
        if (!(gUnk_03000590[rec].unkBD & 4))
        {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 - gUnk_03000590[rec].unkDA < 0x88)
                gUnk_03002C30[rec * 4 + 0x5D].unk2 = 0x88;
            else
                gUnk_03002C30[rec * 4 + 0x5D].unk2 -= gUnk_03000590[rec].unkDA;
        }
        else
        {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 + gUnk_03000590[rec].unkDA > 0xC8)
                gUnk_03002C30[rec * 4 + 0x5D].unk2 = 0xC8;
            else
                gUnk_03002C30[rec * 4 + 0x5D].unk2 += gUnk_03000590[rec].unkDA;
        }
    }
}

u32 sub_08019440(u32 rec)
{
    u32 done = 0;

    gUnk_03000590[rec].unkD7 += 0x20 - gUnk_03000590[rec].unkBB;
    gUnk_03000590[rec].unkDA = gUnk_03000590[rec].unkD7 / 16;
    gUnk_03000590[rec].unkD7 %= 16;
    if (rec <= 2)
    {
        if (gUnk_03000590[rec].unkBD & 4)
        {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 + gUnk_03000590[rec].unkDA > 0x68)
            {
                gUnk_03002C30[rec * 4 + 0x5D].unk2 = 0x68;
                done = 1;
            }
            else
                gUnk_03002C30[rec * 4 + 0x5D].unk2 += gUnk_03000590[rec].unkDA;
        }
        else
        {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 - gUnk_03000590[rec].unkDA < 0x28)
            {
                gUnk_03002C30[rec * 4 + 0x5D].unk2 = 0x28;
                done = 1;
            }
            else
                gUnk_03002C30[rec * 4 + 0x5D].unk2 -= gUnk_03000590[rec].unkDA;
        }
    }
    else
    {
        if (gUnk_03000590[rec].unkBD & 4)
        {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 - gUnk_03000590[rec].unkDA < 0x88)
            {
                gUnk_03002C30[rec * 4 + 0x5D].unk2 = 0x88;
                done = 1;
            }
            else
                gUnk_03002C30[rec * 4 + 0x5D].unk2 -= gUnk_03000590[rec].unkDA;
        }
        else
        {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 + gUnk_03000590[rec].unkDA > 0xC8)
            {
                gUnk_03002C30[rec * 4 + 0x5D].unk2 = 0xC8;
                done = 1;
            }
            else
                gUnk_03002C30[rec * 4 + 0x5D].unk2 += gUnk_03000590[rec].unkDA;
        }
    }
    return done;
}

void sub_08019544(u32 rec)
{
    if (gUnk_03002C30[rec * 4 + 0x5B].unk0 & 0x200)
    {
        gUnk_03002C30[rec * 4 + 0x5D].unk24 = ((s32)(0x20 - gUnk_03000590[rec].unkBB) >> 1) + 1;
        update_battle_sprite_orbiting_positions(rec * 4 + 0x5A, rec, sub_08015924(rec));
    }
    else
    {
        battle_sprite_set_palette_index(rec * 4 + 0x5A, ((s32)(0x20 - gUnk_03000590[rec].unkBB) >> 1) + 1);
    }
}

void update_all_battle_status_sprites(void)
{
    u32 i;

    clear_sprite_table_mask(0x46, 0x12);
    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40)
        {
            battle_bot_status_sprite_update(i);
            battle_update_status_effect_sprite(i);
            update_battle_status_effect_sprite(i);
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_08018900", battle_bot_status_sprite_update);
INCLUDE_ASM("asm/nonmatching/code_08018900", battle_update_status_effect_sprite);
INCLUDE_ASM("asm/nonmatching/code_08018900", update_battle_status_effect_sprite);
INCLUDE_ASM("asm/nonmatching/code_08018900", battle_setup_part_sprite);

u32 sub_08019EF0(void)
{
    u32 i;
    u32 a = 0;
    u32 b = 0;

    if (gUnk_03000440.unk89 != 1 || gUnk_03000B90 == 0)
    {
        for (i = 0; i <= 5; i++)
        {
            if (gUnk_03000590[i].unk40)
            {
                a += battle_bot_at_front_line(i, 0);
                b += battle_bot_at_home_line(i, 0);
            }
        }
    }
    else
    {
        for (i = 3; i <= 5; i++)
        {
            if (gUnk_03000590[i].unk40)
            {
                a += battle_bot_at_front_line(i, 0);
                b += battle_bot_at_home_line(i, 0);
            }
        }
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03000590[i].unk40)
            {
                a += battle_bot_at_front_line(i, 0);
                b += battle_bot_at_home_line(i, 0);
            }
        }
    }
    if (a != 0 || b != 0)
        return 1;
    return 0;
}

u32 battle_bot_at_front_line(u32 rec, u32 peek)
{
    u32 reached = 0;

    if (!(gUnk_03000590[rec].unkBD & 4))
    {
        if (rec <= 2)
        {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 == 0x68)
                reached = 1;
        }
        else
        {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 == 0x88)
                reached = 1;
        }
        if (peek == 0 && reached)
            battle_queue_add(rec, gUnk_03000590[rec].parts[3].unk12);
    }
    return reached;
}

u32 battle_bot_at_home_line(u32 rec, u32 peek)
{
    u32 reached = 0;

    if (gUnk_03000590[rec].unkBD & 4)
    {
        if (rec <= 2)
        {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 == 0x28)
                reached = 1;
        }
        else
        {
            if (gUnk_03002C30[rec * 4 + 0x5D].unk2 == 0xC8)
                reached = 1;
        }
        if (peek == 0 && reached)
            battle_queue_add(rec, gUnk_03000590[rec].parts[3].unk12);
    }
    return reached;
}

void battle_queue_add(u32 rec, u32 prio)
{
    u32 i;
    struct Unk_03001800 *g;

    i = 0;
    g = &gUnk_03001800;
    for (; i <= 5; i++)
    {
        if (g->unk45[i][0] == 0)
        {
            g->unk45[i][0] = rec + 1;
            g->unk45[i][1] = prio;
            return;
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_08018900", iterate_bots_setup_battle_sprites);

void battle_number_popup_init(u8 *buf, u32 rec)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (buf[i] == 0xFE)
        {
            gUnk_03002C30[rec * 4 + 10 + i].unk21 = 0xFF;
            return;
        }
        gUnk_03002C30[rec * 4 + 10 + i].unk0 = 0xC224;
        gUnk_03002C30[rec * 4 + 10 + i].unk1C = 0;
        gUnk_03002C30[rec * 4 + 10 + i].unk4 = gUnk_03002C30[rec * 4 + 0x5D].unk4 + 4;
        gUnk_03002C30[rec * 4 + 10 + i].unkB = 0x90;
        gUnk_03002C30[rec * 4 + 10 + i].unk6 = buf[i] + 0x800;
        gUnk_03002C30[rec * 4 + 10 + i].unk20 = i * 4;
        gUnk_03002C30[rec * 4 + 10 + i].unk21 = 0;
        gUnk_03002C30[rec * 4 + 10 + i].unk9 = 0x40;
        gUnk_03002C30[rec * 4 + 10 + i].unk8 = 0x40;
        gUnk_03002C30[rec * 4 + 10 + i].unkA = buf[0] + 1;
        switch (buf[6])
        {
        case 1:
            gUnk_03002C30[rec * 4 + 10 + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 + i * 8;
            break;
        case 2:
            gUnk_03002C30[rec * 4 + 10 + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 4 + i * 8;
            break;
        case 3:
            gUnk_03002C30[rec * 4 + 10 + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 8 + i * 8;
            break;
        case 4:
            gUnk_03002C30[rec * 4 + 10 + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 12 + i * 8;
            break;
        }
    }
}

void battle_number_popup_update(u32 rec)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03002C30[rec * 4 + 10 + i].unk21 == 0xFF)
            return;
        if (gUnk_03002C30[rec * 4 + 10 + i].unk21 <= 0x1F)
        {
            if (gUnk_03002C30[rec * 4 + 10 + i].unk20 == 0)
            {
                gUnk_03002C30[rec * 4 + 10 + i].unk4 += gUnk_083AD3B3[gUnk_03002C30[rec * 4 + 10 + i].unk21];
                gUnk_03002C30[rec * 4 + 10 + i].unk9 += 2;
                gUnk_03002C30[rec * 4 + 10 + i].unk21++;
            }
            else
                gUnk_03002C30[rec * 4 + 10 + i].unk20--;
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_08018900", set_display_digit_type);

void render_battle_text_sprites(u8 *buf, u32 rec, u32 slot)
{
    u32 i;

    for (i = 0; i <= 4; i++)
    {
        if (buf[i] == 0xFE)
            return;
        gUnk_03002C30[rec * 4 + slot + i].unk0 = 0xC224;
        gUnk_03002C30[rec * 4 + slot + i].unk1C = 0;
        gUnk_03002C30[rec * 4 + slot + i].unk4 = gUnk_03002C30[rec * 4 + 0x5D].unk4 + 4;
        gUnk_03002C30[rec * 4 + slot + i].unkB = 0x90;
        gUnk_03002C30[rec * 4 + slot + i].unk6 = buf[i] + 0x800;
        gUnk_03002C30[rec * 4 + slot + i].unk20 = i * 4;
        gUnk_03002C30[rec * 4 + slot + i].unk21 = 0;
        gUnk_03002C30[rec * 4 + slot + i].unk9 = 0x40;
        gUnk_03002C30[rec * 4 + slot + i].unk8 = 0x40;
        gUnk_03002C30[rec * 4 + slot + i].unkA = buf[0] + 1;
        switch (buf[6])
        {
        case 1:
            gUnk_03002C30[rec * 4 + slot + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 + i * 8;
            break;
        case 2:
            gUnk_03002C30[rec * 4 + slot + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 4 + i * 8;
            break;
        case 3:
            gUnk_03002C30[rec * 4 + slot + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 8 + i * 8;
            break;
        case 4:
            gUnk_03002C30[rec * 4 + slot + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 12 + i * 8;
            break;
        }
    }
}

void battle_setup_text_sprites_0801A418(u8 *buf, u32 rec, u32 slot)
{
    u32 i;

    for (i = 0; i <= 4; i++)
    {
        if (buf[i] == 0xFE)
            return;
        gUnk_03002C30[rec * 4 + slot + i].unk0 = 0xC224;
        gUnk_03002C30[rec * 4 + slot + i].unk1C = 0;
        gUnk_03002C30[rec * 4 + slot + i].unk4 = gUnk_03002C30[rec * 4 + 0x5D].unk4 + 4;
        gUnk_03002C30[rec * 4 + slot + i].unkB = 0x90;
        gUnk_03002C30[rec * 4 + slot + i].unk6 = buf[i] + 0x5100;
        gUnk_03002C30[rec * 4 + slot + i].unk20 = i * 4;
        gUnk_03002C30[rec * 4 + slot + i].unk21 = 0;
        gUnk_03002C30[rec * 4 + slot + i].unk9 = 0x40;
        gUnk_03002C30[rec * 4 + slot + i].unk8 = 0x40;
        gUnk_03002C30[rec * 4 + slot + i].unkA = 0xC;
        switch (buf[6])
        {
        case 1:
            gUnk_03002C30[rec * 4 + slot + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 + i * 8;
            break;
        case 2:
            gUnk_03002C30[rec * 4 + slot + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 4 + i * 8;
            break;
        case 3:
            gUnk_03002C30[rec * 4 + slot + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 8 + i * 8;
            break;
        case 4:
            gUnk_03002C30[rec * 4 + slot + i].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2 - 12 + i * 8;
            break;
        }
    }
}

void battle_setup_text_sprites_0801A4F4(u8 *buf, u32 rec, u32 slot, u32 x, u32 y)
{
    u32 i;

    for (i = 0; i <= 4; i++)
    {
        if (buf[i] == 0xFE)
            return;
        gUnk_03002C30[slot + rec * 4 + i].unk0 = 0xC224;
        gUnk_03002C30[slot + rec * 4 + i].unk1C = 0;
        gUnk_03002C30[slot + rec * 4 + i].unk4 = y;
        gUnk_03002C30[slot + rec * 4 + i].unk2 = x + i * 8;
        gUnk_03002C30[slot + rec * 4 + i].unkB = 0x90;
        gUnk_03002C30[slot + rec * 4 + i].unk6 = buf[i] + 0x5100;
        gUnk_03002C30[slot + rec * 4 + i].unk20 = i * 4;
        gUnk_03002C30[slot + rec * 4 + i].unk21 = 0;
        gUnk_03002C30[slot + rec * 4 + i].unk9 = 0x40;
        gUnk_03002C30[slot + rec * 4 + i].unk8 = 0x40;
        gUnk_03002C30[slot + rec * 4 + i].unkA = 0xC;
    }
}

void update_battle_sprite_animations(u8 *buf, u32 rec, u32 slot)
{
    u32 i;

    for (i = 0; i <= 4; i++)
    {
        if (buf[i] == 0xFE)
            return;
        if (gUnk_03002C30[slot + rec * 4 + i].unk21 <= 0x1F)
        {
            if (gUnk_03002C30[slot + rec * 4 + i].unk20 == 0)
            {
                gUnk_03002C30[slot + rec * 4 + i].unk4 += gUnk_083AD3B3[gUnk_03002C30[slot + rec * 4 + i].unk21];
                gUnk_03002C30[slot + rec * 4 + i].unk9 += 2;
                gUnk_03002C30[slot + rec * 4 + i].unk21++;
            }
            else
                gUnk_03002C30[slot + rec * 4 + i].unk20--;
        }
    }
}

void battle_queue_sort(void)
{
    u32 n, i;
    u8 r, p;

    for (n = 5; n != 0; n--)
    {
        for (i = 0; i < n; i++)
        {
            if (gUnk_03001800.unk45[0][i * 2 + 1] < gUnk_03001800.unk45[0][(i + 1) * 2 + 1])
            {
                r = gUnk_03001800.unk45[0][(i + 1) * 2];
                p = gUnk_03001800.unk45[0][(i + 1) * 2 + 1];
                gUnk_03001800.unk45[0][(i + 1) * 2] = gUnk_03001800.unk45[0][i * 2];
                gUnk_03001800.unk45[0][(i + 1) * 2 + 1] = gUnk_03001800.unk45[0][i * 2 + 1];
                gUnk_03001800.unk45[0][i * 2] = r;
                gUnk_03001800.unk45[0][i * 2 + 1] = p;
            }
        }
    }
}

void battle_queue_take_head(void)
{
    gUnk_03001800.unk87 = gUnk_03001800.unk45[0][0] - 1;
    gUnk_03001800.unk89 = (gUnk_03001800.unk45[0][0] - 1) / 3;
    gUnk_03001800.unk8A = gUnk_03001800.unk89 ^ 1;
}

void battle_queue_pop(void)
{
    u32 i;

    for (i = 0; i <= 4; i++)
    {
        gUnk_03001800.unk45[0][i * 2] = gUnk_03001800.unk45[0][(i + 1) * 2];
        gUnk_03001800.unk45[0][i * 2 + 1] = gUnk_03001800.unk45[0][(i + 1) * 2 + 1];
    }
    gUnk_03001800.unk45[0][i * 2] = 0;
    gUnk_03001800.unk45[0][i * 2 + 1] = 0;
}

u32 sub_0801A6B0(void)
{
    u32 i;

    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40 && gUnk_03000590[i].unkBF)
            return 1;
    }
    return 0;
}

u32 sub_0801A6EC(u32 rec)
{
    if (rec <= 2)
    {
        switch (rec)
        {
        case 0:
            if (gUnk_03001800.unk44 & 1)
                return 1;
            return 0;
        case 1:
            if (gUnk_03001800.unk44 & 2)
                return 1;
            return 0;
        case 2:
            if (gUnk_03001800.unk44 & 4)
                return 1;
            return 0;
        }
    }
}

void sub_0801A744(u32 rec)
{
    if (rec <= 2)
    {
        switch (rec)
        {
        case 0:
            gUnk_03001800.unk44 &= ~1;
            break;
        case 1:
            gUnk_03001800.unk44 &= ~2;
            break;
        case 2:
            gUnk_03001800.unk44 &= ~4;
            break;
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_08018900", battle_phase_dispatch_0801A788);

void sub_0801ABF8(void)
{
    if (gUnk_03001360 == 0 || gUnk_03000440.unk89 == 1)
        text_window_init(1, 2, 0);
}

u32 sub_0801AC24(u32 msg)
{
    u32 done;

    if (gUnk_03001360 == 0 || gUnk_03000440.unk89 == 1)
    {
        done = run_message(gUnk_083C65C4[msg]);
        if (done)
            gUnk_03000440.unk1B = 0;
        return done;
    }
    return 1;
}

u32 sub_0801AC6C(void)
{
    if (gUnk_03001360 == 0 || gUnk_03000440.unk89 == 1)
        return game_state_execute_handler_a();
    return 1;
}

void sub_0801AC98(u32 rec)
{
    if (rec <= 2)
    {
        set_tilemap_and_decompress_bg(0, 13, gUnk_08488830, REG_BG1CNT, 0x258);
        set_tilemap_and_decompress_bg(0, 17, gUnk_08488744, REG_BG1CNT, 0x210);
    }
    else
    {
        set_tilemap_and_decompress_bg(18, 13, gUnk_0848886C, REG_BG1CNT, 0x270);
        set_tilemap_and_decompress_bg(20, 17, gUnk_08488744, REG_BG1CNT, 0x210);
    }
}

void sub_0801AD10(u32 rec)
{
    if (gUnk_03000590[rec].unkC1 == 0x50)
        draw_battle_panel_left_b(rec);
    else
        draw_battle_panel_left_a(rec);
    draw_medaforce_gauge_bar(rec);
    draw_medaforce_gauge_value(rec);
}

void sub_0801AD48(u32 rec)
{
    u32 i;

    clear_battle_sprite_slot(0x78, 8);
    for (i = 0; i <= 7; i++)
    {
        gUnk_03002C30[0x78 + i].unk0 = 0xC404;
        gUnk_03002C30[0x78 + i].unk1C = 0;
        gUnk_03002C30[0x78 + i].unk4 = 0x78;
        gUnk_03002C30[0x78 + i].unkA = 9;
        gUnk_03002C30[0x78 + i].unkB = 0x80;
        gUnk_03002C30[0x78 + i].unk6 = (i & 3) + 0x616;
        gUnk_03002C30[0x78 + i].unk24 = 0;
        gUnk_03002C30[0x78 + i].unk26 = 7 - i;
        gUnk_03002C30[0x78 + i].unk28 = 0;
        gUnk_03002C30[0x78 + i].unk27 = i * 2;
        gUnk_03002C30[0x78 + i].unk21 = 0;
        gUnk_03002C30[0x78 + i].unk22 = i & 3;
        if (rec <= 2)
        {
            gUnk_03002C30[0x78 + i].unk0 |= 0x1000;
            gUnk_03002C30[0x78 + i].unk2 = 0x5C;
        }
        else
        {
            gUnk_03002C30[0x78 + i].unk0 &= ~0x1000;
            gUnk_03002C30[0x78 + i].unk2 = 0x94;
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801ADE8);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801AE70);

void sub_0801AEB4(void)
{
    gUnk_03001800.unk9C[0] = 0;
    gUnk_03001800.unk9C[1] = 0;
    gUnk_03001800.unk9C[2] = 0;
    gUnk_03001800.unk9C[3] = 0;
    gUnk_03001800.unk9C[4] = 0;
}

void sub_0801AED4(void)
{
    gUnk_03001800.unkA1[0] = 0;
    gUnk_03001800.unkA1[1] = 0;
    gUnk_03001800.unkA1[2] = 0;
    gUnk_03001800.unkA1[3] = 0;
    gUnk_03001800.unkA1[4] = 0;
}

void clear_battle_ui_tilemaps(void)
{
    vram_fill_tilemap_rect(12, 7, 0, 13, REG_BG1CNT, 0);
    vram_fill_tilemap_rect(12, 7, 18, 13, REG_BG1CNT, 0);
    vram_fill_tilemap_rect(12, 7, 0, 13, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(12, 7, 18, 13, REG_BG0CNT, 0);
    clear_battle_sprite_slot(0x3C, 10);
    clear_battle_sprite_slot(0x78, 8);
    clear_battle_sprite_slot(10, 0x17);
}

u32 medaforce_gauge_fill_step(u32 rec)
{
    if (gUnk_03001800.unk51 != 0 && gUnk_03000590[rec].unkC1 != 0x50)
    {
        gUnk_03000590[rec].unkC1++;
        gUnk_03001800.unk51--;
        draw_medaforce_gauge_bar(rec);
        draw_medaforce_gauge_value(rec);
        return 0;
    }
    return 1;
}

u32 medaforce_gauge_drain_step(u32 rec)
{
    if (gUnk_03001800.unk51 != 0 && gUnk_03000590[rec].unkC1 != 0)
    {
        gUnk_03000590[rec].unkC1--;
        gUnk_03001800.unk51--;
        draw_medaforce_gauge_bar(rec);
        draw_medaforce_gauge_value(rec);
        return 0;
    }
    return 1;
}

void sub_0801B004(u32 rec)
{
    u32 i;
    struct Vec16 p;

    CpuFastSet(gUnk_084E3058, (void *)0x050002C0, 8);
    for (i = 0; i <= 7; i++)
    {
        clear_battle_sprite_slot(i + 0x21, 1);
        gUnk_03002C30[0x21 + i].unk0 = ((gUnk_03001800.unk39[3] + 2) << 10) | 0x4204;
        gUnk_03002C30[0x21 + i].unk1C = 0;
        gUnk_03002C30[0x21 + i].unkA = 6;
        gUnk_03002C30[0x21 + i].unkB = 0x81;
        gUnk_03002C30[0x21 + i].unk6 = 0xA10;
        gUnk_03002C30[0x21 + i].unk20 = i << 5;
        gUnk_03002C30[0x21 + i].unk21 = gUnk_03002C30[rec * 4 + 0x5D].unk4;
        gUnk_03002C30[0x21 + i].unk28 = 0;
        gUnk_03002C30[0x21 + i].unk27 = i * 4;
        gUnk_03002C30[0x21 + i].unk26 = 0;
        p = compute_polar_to_screen_position(gUnk_03002C30[0x21 + i].unk20, 16, gUnk_03002C30[rec * 4 + 0x5D].unk2, gUnk_03002C30[0x21 + i].unk21, 8, 0);
        gUnk_03002C30[0x21 + i].unk2 = p.x;
        gUnk_03002C30[0x21 + i].unk4 = p.y;
        gUnk_03002C30[0x21 + i].unk8 = 4;
        gUnk_03002C30[0x21 + i].unk9 = 4;
    }
}

u32 sub_0801B0E8(u32 rec)
{
    u32 i;
    u32 done = 0;
    struct Vec16 p;

    for (i = 0; i <= 7; i++)
    {
        if (gUnk_03002C30[0x21 + i].unk0 == 0)
        {
            done++;
            continue;
        }
        gUnk_03002C30[0x21 + i].unk0 |= 0x8000;
        gUnk_03002C30[0x21 + i].unk28++;
        gUnk_03002C30[0x21 + i].unk20 -= 8;
        if ((gUnk_03002C30[0x21 + i].unk28 & 7) == 0)
            gUnk_03002C30[0x21 + i].unk21--;
        p = compute_polar_to_screen_position(gUnk_03002C30[0x21 + i].unk20, gUnk_03002C30[0x21 + i].unk26 + 16, gUnk_03002C30[rec * 4 + 0x5D].unk2, gUnk_03002C30[0x21 + i].unk21, 8, 0);
        gUnk_03002C30[0x21 + i].unk2 = p.x;
        gUnk_03002C30[0x21 + i].unk4 = p.y;
        if (gUnk_03002C30[0x21 + i].unk20 > 0x80)
            gUnk_03002C30[0x21 + i].unkB = rec * 4 + 0x59;
        else
            gUnk_03002C30[0x21 + i].unkB = 0x81;
        if (gUnk_03002C30[0x21 + i].unk21 > gUnk_03002C30[rec * 4 + 0x5D].unk4 - 8 && gUnk_03002C30[0x21 + i].unk8 != 0x40)
        {
            gUnk_03002C30[0x21 + i].unk8 += 4;
            gUnk_03002C30[0x21 + i].unk9 += 4;
        }
        if (gUnk_03002C30[0x21 + i].unk21 < gUnk_03002C30[rec * 4 + 0x5D].unk4 - 12 && gUnk_03002C30[0x21 + i].unk8 != 4)
        {
            gUnk_03002C30[0x21 + i].unk8 -= 4;
            gUnk_03002C30[0x21 + i].unk9 -= 4;
        }
        if (gUnk_03002C30[0x21 + i].unk20 == 0xC0 && gUnk_03002C30[0x21 + i].unk21 < gUnk_03002C30[rec * 4 + 0x5D].unk4 - 16)
            clear_battle_sprite_slot(0x21 + i, 1);
    }
    if (done == 8)
        return 1;
    return 0;
}

void sub_0801B274(u32 rec)
{
    u32 i;
    u32 zero;
    u32 zero2;

    gUnk_03000590[rec].unkBD &= ~1;
    gUnk_03000590[rec].unkDE = gUnk_03000590[rec].unkDD;
    if (gUnk_03000590[rec].unkDD == 0)
        gUnk_03000590[rec].unkDF = 0;
    else if (gUnk_03000590[rec].unkDD > 3)
        gUnk_03000590[rec].unkDF = 0;
    else
        gUnk_03000590[rec].unkDF = gUnk_03000590[rec].parts[gUnk_03000590[rec].unkDD - 1].data[1];
    for (i = 0; i <= 3; i++)
    {
        gUnk_03000590[rec].parts[i].unkE = 0;
        gUnk_03000590[rec].parts[i].unkF = 0;
    }
    zero = 0;
    CpuSet(&zero, gUnk_030018A8, 0x05000008);
    zero2 = 0;
    CpuSet(&zero2, gUnk_030018A8 + 8, 0x05000008);
    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40 && (gUnk_03000590[i].unkBD & 0x18)
         && (u8)(gUnk_03000590[i].unkDE - 1) <= 2
         && gUnk_03000590[i].parts[gUnk_03000590[i].unkDE - 1].unk11 == 0)
            gUnk_03000590[i].unkBD &= 0xE7;
    }
    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unkBA)
            gUnk_03000590[i].unkBC &= 0xF;
    }
    sub_0801B3AC(rec);
}

void sub_0801B3AC(u32 rec)
{
    u32 zero;

    if (gUnk_03001800.unk118)
    {
        gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[0] = gUnk_03001800.unk11C.data[0];
        gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] = gUnk_03001800.unk11C.data[1];
        gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[5] = gUnk_03001800.unk11C.data[5];
        gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[6] = gUnk_03001800.unk11C.data[6];
        gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[7] = gUnk_03001800.unk11C.data[7];
        gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[0xC] = gUnk_03001800.unk11C.data[0xC];
        gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].unk17 = gUnk_03001800.unk11C.unk17;
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
    }
    zero = 0;
    CpuSet(&zero, &gUnk_03001800.unk118, 0x05000009);
}

u32 sub_0801B4C8(u32 first)
{
    u32 n = 0;
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[first + i].unkBA == 2)
            n++;
    }
    return n;
}

u32 sub_0801B4F8(u32 first)
{
    u32 n = 0;
    u32 i, j;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[first + i].unkBA)
        {
            for (j = 0; j <= 3; j++)
            {
                if (gUnk_03000590[first + i].parts[j].unk11 == 0)
                    n++;
            }
        }
    }
    return n;
}

INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801B53C);
INCLUDE_ASM("asm/nonmatching/code_08018900", reset_bot_status_and_init_palette_transfers);

void sub_0801B67C(u32 rec)
{
    if (rec <= 2)
        gUnk_03001800.unkF8 = 0;
    else
        gUnk_03001800.unkF8 = 3;
}

void select_next_bot_and_action(u32 rec)
{
    if (gUnk_03000590[rec].unkC9 == 0x2C)
    {
        if (gUnk_03000590[rec].parts[gUnk_03000590[rec].unkDD - 1].data[2] <= 3
         || gUnk_03000590[rec].parts[gUnk_03000590[rec].unkDD - 1].data[1] == 0x34)
        {
            gUnk_03000590[rec].unkE0 = find_next_active_bot(rec) + 1;
            gUnk_03000590[rec].unkE1 = sub_080330E8(gUnk_03000590[rec].unkE0 - 1) + 1;
        }
    }
}

u32 find_next_active_bot(u32 rec)
{
    u32 k = rng_next_080424B8() & 0x1F;
    u32 i;
    u32 r;

    for (i = 0; i <= 5; i++)
    {
        r = gUnk_083AD3D3[k];
        if (gUnk_03000440.unk89 == 1 && gUnk_03000B90)
            r = gUnk_083AD3F3[r];
        if (gUnk_03000590[r].unk40 && rec != r)
            return r;
        k = (k + 1) & 0x1F;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatching/code_08018900", determine_battle_part_action_priority);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801B894);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801B9C4);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801BACC);

void copy_battle_entity_positions(void)
{
    u32 i;

    for (i = 0; i <= 5; i++)
    {
        gUnk_03001800.unk13C[i].x = gUnk_03002C30[0x5D + i * 4].unk2;
        gUnk_03001800.unk13C[i].y = gUnk_03002C30[0x5D + i * 4].unk4 - 4;
    }
}

void init_battle_bot_sprites(void)
{
    u32 i;

    for (i = 0; i <= 5; i++)
    {
        if (gUnk_03000590[i].unk40)
            init_battle_sprite_entry_0801BC04(i);
        else
            clear_sprite_table_mask(0x72 + i, 1);
    }
}

void init_battle_sprite_entry_0801BC04(u32 rec)
{
    gUnk_03002C30[rec + 0x72].unk0 = ((gUnk_03001800.unk39[3] + 2) << 10) | 0xC004;
    gUnk_03002C30[rec + 0x72].unk1C = 0;
    gUnk_03002C30[rec + 0x72].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2;
    gUnk_03002C30[rec + 0x72].unk4 = gUnk_03002C30[rec * 4 + 0x5D].unk4 + 8;
    gUnk_03002C30[rec + 0x72].unkA = 5;
    gUnk_03002C30[rec + 0x72].unkB = 1;
    gUnk_03002C30[rec + 0x72].unk6 = 0xF00;
}

void decompress_indexed_graphics_to_ewram(u32 list)
{
    const struct GfxListEntry *e = gUnk_083CE480[list];
    u8 *dst = (u8 *)0x02000000;
    u32 i;

    for (i = 0; e[i].size != 0; i++)
    {
        sub_08044B28(gUnk_083B2584[e[i].index * 2], dst);
        dst += e[i].size * 32;
    }
}

void decompress_fixed_graphics_to_ewram(void)
{
    const struct GfxListEntry *e = gUnk_083CE480[0x3C];
    u8 *dst = (u8 *)0x02016000;
    u32 i;

    for (i = 0; e[i].size != 0; i++)
    {
        sub_08044B28(gUnk_083B2584[e[i].index * 2], dst);
        dst += e[i].size * 32;
    }
}

void load_battle_entity_palette(u32 list, u32 entry, u32 slot)
{
    const struct GfxListEntry *l = gUnk_083CE480[list];

    CpuFastSet(gUnk_083B2584[l[entry].index * 2 + 1], (void *)(0x05000000 + slot * 32), 8);
}

void init_game_state_entry(const u16 *pos, u8 arg, u32 slot)
{
    gUnk_03000440.unk64[slot].unk0 = 0;
    gUnk_03000440.unk64[slot].unk1 = 2;
    gUnk_03000440.unk64[slot].unk2 = 0;
    gUnk_03000440.unk64[slot].unk4 = pos[0];
    gUnk_03000440.unk64[slot].unk6 = pos[1];
    gUnk_03000440.unk64[slot].unk3 = arg;
}

INCLUDE_ASM("asm/nonmatching/code_08018900", process_animation_script);
INCLUDE_ASM("asm/nonmatching/code_08018900", increment_medal_skill_level);

void sync_medal_stats_from_battle_bot(u32 rec)
{
    u32 slot = find_medal_slot_by_id(gUnk_03000590[rec].medal.unk1) - 1;
    u32 i;

    for (i = 0; i <= 7; i++)
    {
        gUnk_03000BE0[slot].unk20[i] = gUnk_03000590[rec].medal.unk20[i];
        gUnk_03000BE0[slot].unk28[i] = gUnk_03000590[rec].medal.unk28[i];
    }
}

void sub_0801BF64(u16 *counter, u16 max)
{
    if (*counter != max)
        (*counter)++;
}

void sub_0801BF78(const u16 *pos, u8 arg, u32 slot)
{
    gUnk_03000440.unk64[slot].unk0 = 0;
    gUnk_03000440.unk64[slot].unk1 = 2;
    gUnk_03000440.unk64[slot].unk2 = 0;
    gUnk_03000440.unk64[slot].unk4 = pos[0];
    gUnk_03000440.unk64[slot].unk6 = pos[1];
    gUnk_03000440.unk64[slot].unk3 = arg;
}

INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801BFB4);

u32 sub_0801C0BC(u32 msg)
{
    gUnk_03001800.unkA1[1] = msg;
    gUnk_083AD400[gUnk_03001800.unkA1[0]]();
    if (gUnk_03001800.unkA1[0] == 3)
    {
        gUnk_03001800.unkA1[0] = 0;
        return 1;
    }
    return 0;
}

void sub_0801C0F8(void)
{
    sub_0801ABF8();
    gUnk_03001800.unkA1[0]++;
}

void sub_0801C110(void)
{
    if (sub_0801AC24(gUnk_03001800.unkA1[1]))
        gUnk_03001800.unkA1[0]++;
}

void sub_0801C138(void)
{
    if (sub_0801AC6C())
        gUnk_03001800.unkA1[0]++;
}

u32 sub_0801C154(void)
{
    gUnk_083AD410[gUnk_03001800.unk9C[0]]();
    if (gUnk_03001800.unk9C[0] == 4)
    {
        gUnk_03001800.unk9C[0] = 0;
        return 1;
    }
    return 0;
}

void sub_0801C188(void)
{
    lz_decompress_dispatch(gUnk_084C8AC4, (void *)0x06014E00);
    CpuFastSet(gUnk_084E3078, (void *)0x050002C0, 8);
    gUnk_03001800.unk9C[0]++;
}

void sub_0801C1C0(void)
{
    gUnk_03002C30[3].unk0 = 0xC004;
    gUnk_03002C30[3].unk1C = 0;
    gUnk_03002C30[3].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[3].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 12;
    gUnk_03002C30[3].unkA = 6;
    gUnk_03002C30[3].unk6 = 0xA11;
    gUnk_03002C30[3].unkB = 0x81;
    play_sound_effect(0x2F);
    gUnk_03001800.unk9C[0]++;
}

void sub_0801C23C(void)
{
    if (gFrameCounter & 1)
    {
        gUnk_03002C30[3].unk4++;
        if (gUnk_03002C30[3].unk4 == gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 + 4)
        {
            gUnk_03001800.unk9C[1] = 0;
            gUnk_03001800.unk9C[0]++;
        }
    }
}

void sub_0801C298(void)
{
    gUnk_03001800.unk9C[1]++;
    if (gUnk_03000440.unk89 == 0 && (KEYS_LO(gRepeatKeys) & 1))
        gUnk_03001800.unk9C[1] = 60;
    if (gUnk_03001800.unk9C[1] == 60)
    {
        clear_battle_sprite_slot(3, 1);
        gUnk_03001800.unk9C[0]++;
    }
}

u32 dispatch_battle_action_substate(u32 arg)
{
    gUnk_03001800.unk9C[1] = arg;
    gUnk_083AD424[gUnk_03001800.unk9C[0]]();
    if (gUnk_03001800.unk9C[2] != 0)
        return 1;
    return 0;
}

void sub_0801C32C(void)
{
    CpuFastSet(gUnk_084E2EF8, (void *)0x05000300, 8);
    sub_08016370(gUnk_03001800.unk87);
    gUnk_03001800.unk9C[0]++;
}

void sub_0801C360(void)
{
    if (sub_08016438(gUnk_03001800.unk87))
        gUnk_03001800.unk9C[0]++;
}

void sub_0801C388(void)
{
    animate_battle_sprites(gUnk_03001800.unk87);
    sub_0801AC98(gUnk_03001800.unk87);
    gUnk_03001800.unk9C[0]++;
}

void sub_0801C3B0(void)
{
    animate_battle_sprites(gUnk_03001800.unk87);
    render_bot_name_sprites(gUnk_03001800.unk87);
    sub_0801AD10(gUnk_03001800.unk87);
    if (gUnk_03001800.unk9C[1] == 0)
    {
        gUnk_03001800.unk9C[2] = 1;
        gUnk_03001800.unk9C[0]++;
    }
    else
        gUnk_03001800.unk9C[0] = 5;
}

void sub_0801C3F8(void)
{
    animate_battle_sprites(gUnk_03001800.unk87);
}

void sub_0801C40C(void)
{
    CpuFastSet(gUnk_084E2F18, (void *)0x05000320, 8);
    animate_battle_sprites(gUnk_03001800.unk87);
    sub_0801AD48(gUnk_03001800.unk87);
    gUnk_03001800.unk9C[0]++;
}

void sub_0801C444(void)
{
    animate_battle_sprites(gUnk_03001800.unk87);
    if (sub_0801ADE8(gUnk_03001800.unk87))
        gUnk_03001800.unk9C[0]++;
}

void sub_0801C470(void)
{
    animate_battle_sprites(gUnk_03001800.unk87);
    sub_0801AE70(gUnk_03001800.unk87);
    sub_0801AC98(gUnk_03001800.unk88);
    gUnk_03001800.unk9C[0]++;
}

void sub_0801C4A4(void)
{
    animate_battle_sprites(gUnk_03001800.unk87);
    sub_0801AE70(gUnk_03001800.unk87);
    render_bot_name_sprites(gUnk_03001800.unk88);
    sub_0801AD10(gUnk_03001800.unk88);
    gUnk_03001800.unk9C[2] = 1;
    gUnk_03001800.unk9C[0]++;
}

void sub_0801C4E0(void)
{
    animate_battle_sprites(gUnk_03001800.unk87);
    sub_0801AE70(gUnk_03001800.unk87);
}

void sub_0801C4FC(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD44C[gUnk_03001800.unkAA]();
}

INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C524);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C660);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C6C4);
INCLUDE_ASM("asm/nonmatching/code_08018900", sub_0801C774);
