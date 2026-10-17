#include "global.h"

void sub_080249C0(void)
{
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero())
    {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    }
    else if (sub_080331F8(gUnk_03001800.unk88) == 0)
    {
        gUnk_03001800.unkA6 = 0x39;
        gUnk_03001800.unkAA++;
    }
    else
    {
        sub_08036270();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void sub_08024A30(void)
{
    lz_decompress_dispatch(gUnk_084D651C, (void *)0x06014800);
    CpuFastSet(gUnk_0850E858, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 |= 0x220;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unk6 = 0x4E00;
    gUnk_03002C30[0x21].unk30 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk2;
    gUnk_03002C30[0x21].unk32 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk4 - 4;
    gUnk_03002C30[0x21].unk24 = 6;
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void sub_08024AF4(void)
{
    clear_sprite_table_mask(0x21, 1);
    gUnk_03002C30[0x22].unk0 = 0xC404;
    gUnk_03002C30[0x22].unk1C = 0;
    gUnk_03002C30[0x22].unk2 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk2;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk4 - 4;
    gUnk_03002C30[0x22].unkA = 7;
    gUnk_03002C30[0x22].unkB = 0xE0;
    gUnk_03002C30[0x22].unk23 = 0;
    switch (gUnk_03001800.unk8B)
    {
    case 1:
        gUnk_03002C30[0x22].unk6 = 0x4E02;
        break;
    case 2:
        gUnk_03002C30[0x22].unk6 = 0x4E03;
        break;
    default:
        gUnk_03002C30[0x22].unk6 = 0x4E01;
        break;
    }
    play_sound_effect(0x6A);
    gUnk_03001800.unkAA++;
}

void sub_08024BCC(void)
{
    if (advance_sprite_anim_frame(0x22, 0))
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_08024BF8(void)
{
    set_sprite_hidden_flags(0x21, 1);
    gUnk_03002C30[0x21].unk0 |= 0x220;
    gUnk_03002C30[0x21].unk8 = 0x80;
    gUnk_03002C30[0x21].unk9 = 0x80;
    gUnk_03001800.unkAA++;
}

void sub_08024C44(void)
{
    if (gUnk_03002C30[0x21].unk8 == 0x40)
    {
        play_sound_effect(0x3C);
        gUnk_03000440.unk86 = 0;
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x21].unk8 -= 8;
        gUnk_03002C30[0x21].unk9 -= 8;
    }
}

void sub_08024C94(void)
{
    if (gUnk_03000440.unk86 == 0x3C)
    {
        clear_battle_sprite_slot(0x21, 2);
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03000440.unk86++;
        if (gUnk_03000440.unk86 & 4)
            gUnk_03002C30[0x21].unk2 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk2 - 2;
        else
            gUnk_03002C30[0x21].unk2 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk2 + 2;
    }
}

void sub_08024D18(void)
{
    gUnk_03000590[gUnk_03001800.unk88].unkC9 = 0x2B;
    gUnk_03000590[gUnk_03001800.unk88].unkCB = sub_08036E54(gUnk_03001800.unkE8);
    gUnk_03000590[gUnk_03001800.unk88].unkCC = sub_08036E54(gUnk_03001800.unkEC);
    switch (gUnk_03001800.unk8B)
    {
    case 1:
        gUnk_03000590[gUnk_03001800.unk88].unkCA = 2;
        break;
    case 2:
        gUnk_03000590[gUnk_03001800.unk88].unkCA = 3;
        break;
    default:
        gUnk_03000590[gUnk_03001800.unk88].unkCA = 1;
        break;
    }
    gUnk_03001800.unkAA++;
}

void sub_08024DA8(void)
{
    const u8 *s;

    switch (gUnk_03001800.unk8B)
    {
    case 1:
        s = gUnk_083C6DE8[1];
        break;
    case 2:
        s = gUnk_083C6DE8[2];
        break;
    default:
        s = gUnk_083C6DE8[0];
        break;
    }
    memcpy_bytes_0803F63C(s, gUnk_03000440.unk9E, 0xE);
    gUnk_03001800.unkA6 = 0x30;
    gUnk_03001800.unkAA++;
}

void sub_08024E04(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083ADF44[gUnk_03001800.unkAA]();
}

void sub_08024E2C(void)
{
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero())
    {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    }
    else if (sub_080331F8(gUnk_03001800.unk88) == 0)
    {
        gUnk_03001800.unkA6 = 0x39;
        gUnk_03001800.unkAA++;
    }
    else
    {
        sub_08036270();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void sub_08024E9C(void)
{
    lz_decompress_dispatch(gUnk_084D6780, (void *)0x06014800);
    CpuFastSet(gUnk_0850E878, (void *)0x050002C0, 0x10);
    if (gUnk_03001800.unkF8 & 1)
        gUnk_03002C30[0x21].unk0 |= 0x1000;
    gUnk_03002C30[0x21].unk0 |= 0x220;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unkA = 6;
    gUnk_03002C30[0x21].unk6 = 0x4F00;
    gUnk_03002C30[0x21].unk30 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk2;
    gUnk_03002C30[0x21].unk32 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk4 - 4;
    gUnk_03002C30[0x21].unk24 = 6;
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08024F90);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08024FC4);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_0802503C);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025104);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_0802518C);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080251B4);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025230);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025308);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025354);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025378);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_0802549C);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025500);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025570);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080255F8);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025674);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080256EC);
INCLUDE_ASM("asm/nonmatching/code_080249C0", battle_set_action_0x35);
INCLUDE_ASM("asm/nonmatching/code_080249C0", dispatch_battle_action_step);
INCLUDE_ASM("asm/nonmatching/code_080249C0", process_battle_action_phase);
INCLUDE_ASM("asm/nonmatching/code_080249C0", battle_render_bot_status_icon);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025974);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025A18);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025AF8);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025B20);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025B9C);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025C84);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025D2C);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025D4C);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025D6C);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025DD4);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025E88);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025F2C);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025FA0);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08025FC8);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026080);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080260EC);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026108);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026130);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026184);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026284);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080262FC);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080263BC);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_0802645C);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026484);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080264E4);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026628);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026678);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026810);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026884);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080268AC);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080268D4);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026924);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026A24);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026A74);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026AF4);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026BF8);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026CBC);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026CF4);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026D44);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026D98);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026ED0);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026EF8);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026F34);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026F6C);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026FD0);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08026FF8);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080270BC);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080271C4);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_0802724C);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080272EC);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_0802733C);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08027378);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080273DC);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08027444);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08027494);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08027544);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_0802761C);
INCLUDE_ASM("asm/nonmatching/code_080249C0", decompress_sprite_tiles_to_vram_obj_4800_alt);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08027798);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080277DC);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080278B8);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_0802793C);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080279E4);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08027BA0);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08027BEC);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08027CB0);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08027D24);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08027D98);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08027E1C);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08027F5C);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08027F84);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08028078);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080280D4);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08028130);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08028248);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08028270);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080282E0);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08028350);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08028404);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_08028504);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080287C0);
INCLUDE_ASM("asm/nonmatching/code_080249C0", sub_080287DC);
