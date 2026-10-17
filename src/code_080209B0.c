#include "global.h"

void sub_080209B0(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD93C[gUnk_03001800.unkAA]();
}

void sub_080209D8(void)
{
    u32 r;

    if (!gUnk_03000590[gUnk_03001800.unk88].parts[gUnk_03001800.unk8B].unk11)
    {
        calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
        r = decrement_battle_timer_and_check_zero();
        if (r)
        {
            gUnk_03001800.unkA6 = 0x1A;
            gUnk_03001800.unkAA = 2;
            gUnk_03001800.unkAB = 1;
        }
        else
        {
            calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
            sub_08036270();
            gUnk_03001800.unkAA++;
            gUnk_03001800.unkAB = r;
        }
    }
    else
    {
        gUnk_03001800.unkA6 = 0x27;
        gUnk_03001800.unkAA = 2;
        gUnk_03001800.unkAB = 1;
    }
}

void sub_08020A68(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD95C[gUnk_03001800.unkAA]();
}

void sub_08020A90(void)
{
    clear_battle_sprite_slot(0, 0x80);
    gUnk_03001800.unkD0 = gUnk_03001800.unk8B;
    battle_set_damage_display(gUnk_03001800.unk88, gUnk_03001800.unkD0, gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void sub_08020AD0(void)
{
    u32 part;
    struct Unk_03001800 *s = &gUnk_03001800;

    sub_080351E8(s->unk88);
    if (gUnk_03000590[s->unk87].parts[s->unkA7].data[7] && s->unkCA
        && (part = find_random_available_part_slot(s->unk88)))
    {
        part--;
        s->unkD0 = part;
        s->unk8B = part;
        battle_set_damage_display(s->unk88, s->unkD0, s->unkCA);
        s->unkAA = 0xF;
    }
    else
    {
        s->unkAA++;
    }
}

void sub_08020B4C(void)
{
    battle_check_action_counter(&gUnk_03001800.unkC8, gUnk_03001800.unk88, gUnk_03001800.unk8B);
    if (gUnk_03001800.unkF8 & 2)
    {
        get_active_bot_part_index_and_load_values(0);
        init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2], gUnk_03001800.unk64[3],
            (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156, gUnk_03001800.unk39[3] + 2, 4, 0, 2, 0, gUnk_03001800.unk114[0]);
        init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2], gUnk_03001800.unk64[3],
            (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156, gUnk_03001800.unk39[3] + 2, 4, 0, 1, 0, gUnk_03001800.unk114[0]);
    }
    else
    {
        get_active_bot_part_index_and_load_values(1);
        init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2], gUnk_03001800.unk64[3],
            (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A, gUnk_03001800.unk39[3] + 2, 8, 1, 2, 1, gUnk_03001800.unk114[1]);
        init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2], gUnk_03001800.unk64[3],
            (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A, gUnk_03001800.unk39[3] + 2, 8, 1, 1, 1, gUnk_03001800.unk114[1]);
    }
    gUnk_03001800.unkAA++;
}

void sub_08020CEC(void)
{
    gUnk_03001800.unkAA = 2;
}

void sub_08020CFC(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD9C0[gUnk_03001800.unkAA]();
}

void sub_08020D24(void)
{
    u32 r;

    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    r = decrement_battle_timer_and_check_zero();
    if (r)
    {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
        return;
    }
    calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    sub_08036270();
    switch (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1])
    {
    case 0xA:
        gUnk_03001800.unk51 = r;
        break;
    case 0xB:
        gUnk_03001800.unk51 = 1;
        break;
    case 0xC:
        gUnk_03001800.unk51 = 2;
        break;
    default:
        gUnk_03001800.unk51 = 3;
        break;
    }
    gUnk_03001800.unk52 = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
    gUnk_03001800.unkAA = 4;
}

void sub_08020DF8(void)
{
    lz_decompress_dispatch(gUnk_084D50DC, (void *)0x06015800);
    CpuFastSet(gUnk_0850E658, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC604;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[0x5D + gUnk_03001800.unk87 * 4].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[0x5D + gUnk_03001800.unk87 * 4].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unk6 = 0x4100;
    gUnk_03002C30[0x21].unk23 = 0;
    gUnk_03002C30[0x21].unk27 = 0;
    play_sound_effect(0x29);
    gUnk_03001800.unkAA++;
}

void sub_08020EDC(void)
{
    sub_080353CC(0x21);
    if (gUnk_03002C30[0x21].unk27 == 0x20)
    {
        gUnk_03002C30[0x21].unk0 &= ~0x200;
        gUnk_03002C30[0x21].unk18 = 0;
        gUnk_03001800.unkAA++;
        return;
    }
    if (!(gUnk_03001800.unkF8 & 1))
        gUnk_03002C30[0x21].unk18 = (gUnk_03002C30[0x21].unk18 + 0x20) & 0x3FF;
    else
        gUnk_03002C30[0x21].unk18 = (gUnk_03002C30[0x21].unk18 - 0x20) & 0x3FF;
    if (!(gUnk_03002C30[0x21].unk27 & 1))
    {
        if (!(gUnk_03001800.unkF8 & 1))
            gUnk_03002C30[0x21].unk2++;
        else
            gUnk_03002C30[0x21].unk2--;
    }
    gUnk_03002C30[0x21].unk27++;
}

void sub_08020FB8(void)
{
    lz_decompress_dispatch(gUnk_084CCE48, (void *)0x06014800);
    CpuFastSet(gUnk_0850E358, (void *)0x050002E0, 8);
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x23], 0x21);
    gUnk_03001800.unkAA++;
}

void sub_08021000(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x23], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
        gUnk_03001800.unkAA++;
}

void sub_08021038(void)
{
    switch (gUnk_03001800.unk51)
    {
    case 0:
        lz_decompress_dispatch(gUnk_084C907C, (void *)0x06014800);
        CpuFastSet(gUnk_0850E058, (void *)0x050002E0, 8);
        gUnk_03002C30[0x21].unk4 = 0x3C;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x19], 0x21);
        break;
    case 1:
        lz_decompress_dispatch(gUnk_084C9288, (void *)0x06014800);
        CpuFastSet(gUnk_0850E078, (void *)0x050002E0, 8);
        gUnk_03002C30[0x21].unk4 = 0x3C;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1A], 0x21);
        break;
    case 2:
        lz_decompress_dispatch(gUnk_084C9624, (void *)0x06014800);
        CpuFastSet(gUnk_0850E098, (void *)0x050002E0, 8);
        gUnk_03002C30[0x21].unk4 = 0x3C;
        gUnk_03002C30[0x21].unk6 = 0xD00;
        break;
    case 3:
        lz_decompress_dispatch(gUnk_084D513C, (void *)0x06014800);
        CpuFastSet(gUnk_0850E678, (void *)0x050002E0, 8);
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x38], 0x21);
        break;
    }
    gUnk_03002C30[0x21].unk0 |= 0x220;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk8 = 8;
    if (gUnk_03001800.unkF8 & 1)
    {
        gUnk_03002C30[0x21].unk0 |= 0x1000;
        gUnk_03002C30[0x21].unk2--;
    }
    gUnk_03001800.unkAA++;
}

void sub_080211C8(void)
{
    if ((gUnk_03002C30[0x21].unk8 += 8) == 0x40)
    {
        if (gUnk_03001800.unk51 == 3)
            gUnk_03000440.unk86 = 1;
        else
            gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802121C(void)
{
    gUnk_03000440.unk86--;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03000440.unk86 = 0;
    if (gUnk_03000440.unk86 == 0)
    {
        switch (gUnk_03001800.unk51)
        {
        case 0:
        case 1:
        case 2:
            gUnk_03002C30[0x21].unk27 = 0;
            gUnk_03001800.unkAA++;
            break;
        case 3:
            play_sound_effect(0x52);
            gUnk_03001800.unkAA = 0x20;
            break;
        }
    }
}

void sub_080212A0(void)
{
    if (gUnk_03002C30[0x21].unk27 == 0x10)
    {
        gUnk_03001800.unkAA++;
        return;
    }
    if (!(gUnk_03001800.unkF8 & 1))
        gUnk_03002C30[0x21].unk2++;
    else
        gUnk_03002C30[0x21].unk2--;
    gUnk_03002C30[0x21].unk27++;
}

INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021300);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021370);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080213E4);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021418);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080215C8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021608);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021638);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_0802167C);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021734);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021774);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080217D8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_0802186C);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080218BC);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080218E4);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021950);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080219C0);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021A14);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021A6C);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021AFC);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021B78);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021BD8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021C94);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021E04);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021E2C);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021EA0);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08021F90);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022010);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080220A0);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022154);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_0802217C);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080221C8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080222A8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022380);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080223BC);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080223E4);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022480);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022648);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022708);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022748);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080227D8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022800);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022870);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022938);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022990);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080229C0);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022A04);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022B40);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022C28);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022CA8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022CD0);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022D4C);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022E14);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022F50);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022FB4);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08022FF0);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023018);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_0802306C);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080230A4);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080230C8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023118);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080231D4);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023224);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023274);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023328);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023384);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080233E0);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_0802342C);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023454);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080234A8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023564);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080235AC);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080235E8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023658);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080236E0);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023730);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023758);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080237C8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080238A0);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023900);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023988);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080239C0);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023A04);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023A48);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023AC8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023AF0);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023B44);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023C18);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023C90);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023CB8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023D44);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023E18);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023E50);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023E94);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023F80);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08023FB8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08024090);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080240B8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_0802410C);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080241F0);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08024210);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080242F8);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08024488);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08024538);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_0802463C);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_080246C0);
INCLUDE_ASM("asm/nonmatching/code_080209B0", battle_process_bot_defeat);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_0802480C);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08024870);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08024890);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_0802494C);
INCLUDE_ASM("asm/nonmatching/code_080209B0", sub_08024998);
