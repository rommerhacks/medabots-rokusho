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

void sub_08024F90(void)
{
    play_sound_effect(0x33);
    gUnk_03002C30[0x21].unk0 |= 0x220;
    gUnk_03001800.unkAA++;
}

void sub_08024FC4(void)
{
    if (!(gUnk_03001800.unkF8 & 1))
        gUnk_03002C30[0x21].unk18 = (gUnk_03002C30[0x21].unk18 - 0x80) & 0x3FF;
    else
        gUnk_03002C30[0x21].unk18 = (gUnk_03002C30[0x21].unk18 + 0x80) & 0x3FF;
    if (gUnk_03002C30[0x21].unk8 == 0x80)
        gUnk_03001800.unkAA++;
    else
    {
        gUnk_03002C30[0x21].unk8++;
        gUnk_03002C30[0x21].unk9++;
    }
}

void sub_0802503C(void)
{
    if (gUnk_03001800.unkF8 & 1)
        gUnk_03002C30[0x21].unk0 &= ~0x1000;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk4 - 0xC;
    gUnk_03000440.unk84 = 0x47;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03000440.unk84], 0x21);
    play_sound_effect(0x4F);
    gUnk_03001800.unkAA++;
}

void sub_08025104(void)
{
    clear_battle_sprite_slot(0x21, 1);
    gUnk_03000590[gUnk_03001800.unk88].unkC9 = 0x2C;
    gUnk_03000590[gUnk_03001800.unk88].unkCA = 0;
    gUnk_03000590[gUnk_03001800.unk88].unkCB = sub_08036E54(gUnk_03001800.unkE8);
    gUnk_03000590[gUnk_03001800.unk88].unkCC = sub_08036E54(gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void sub_08025174(void)
{
    gUnk_03001800.unkA6 = 0x33;
    gUnk_03001800.unkAA++;
}

void sub_0802518C(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083ADFA4[gUnk_03001800.unkAA]();
}

void sub_080251B4(void)
{
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero())
    {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    }
    else if (gUnk_03000590[gUnk_03001800.unk88].parts[0].unk10 == 0)
    {
        gUnk_03001800.unkA6 = 0x34;
        gUnk_03001800.unkAA++;
    }
    else
    {
        sub_08036270();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void sub_08025230(void)
{
    lz_decompress_dispatch(gUnk_084D6AAC, (void *)0x06014800);
    CpuFastSet(gUnk_0850E8B8, (void *)0x050002C0, 0x10);
    gUnk_03002C30[0x21].unk0 |= 0x220;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unkA = 6;
    gUnk_03002C30[0x21].unk6 = 0x5000;
    gUnk_03002C30[0x21].unk30 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk2;
    gUnk_03002C30[0x21].unk32 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk4 - 4;
    gUnk_03002C30[0x21].unk24 = 3;
    gUnk_03002C30[0x21].unk23 = 0;
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void sub_08025308(void)
{
    sub_08037424(0x21);
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03001800.unkAA++;
    else if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else
        gUnk_03001800.unkAA++;
}

void sub_08025354(void)
{
    if (move_sprite_toward_target(0x21))
        gUnk_03001800.unkAA++;
    sub_08037424(0x21);
}

void sub_08025378(void)
{
    sub_08037424(0x21);
    gUnk_03002C30[0x22].unk0 = 0xC604;
    gUnk_03002C30[0x22].unk1C = 0;
    gUnk_03002C30[0x22].unk2 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk2;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk4 - 4;
    gUnk_03002C30[0x22].unk8 = 1;
    gUnk_03002C30[0x22].unk9 = 1;
    gUnk_03002C30[0x22].unkA = 7;
    gUnk_03002C30[0x22].unkB = 0xE0;
    gUnk_03002C30[0x22].unk6 = 0x5001;
    gUnk_03002C30[0x22].unk30 = gUnk_03002C30[0x5D + gUnk_03001800.unk87 * 4].unk2;
    gUnk_03002C30[0x22].unk32 = gUnk_03002C30[0x5D + gUnk_03001800.unk87 * 4].unk4 - 4;
    gUnk_03002C30[0x22].unk24 = 3;
    gUnk_03002C30[0x21].unk30 = gUnk_03002C30[0x5D + gUnk_03001800.unk87 * 4].unk2;
    gUnk_03002C30[0x21].unk32 = gUnk_03002C30[0x5D + gUnk_03001800.unk87 * 4].unk4 - 4;
    gUnk_03002C30[0x21].unk24 = 3;
    play_sound_effect(0x6F);
    gUnk_03001800.unkAA++;
}

void sub_0802549C(void)
{
    sub_08037424(0x21);
    if (gUnk_03002C30[0x22].unk8 == 0x40)
    {
        gUnk_03002C30[0x22].unk2 = gUnk_03002C30[0x21].unk2;
        gUnk_03002C30[0x22].unk4 = gUnk_03002C30[0x21].unk4;
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x22].unk8++;
        gUnk_03002C30[0x22].unk9++;
    }
}

void sub_08025500(void)
{
    if (move_sprite_toward_target(0x21))
    {
        gUnk_03002C30[0x22].unk2 = gUnk_03002C30[0x21].unk2;
        gUnk_03002C30[0x22].unk4 = gUnk_03002C30[0x21].unk4;
        play_sound_effect(0x2B);
        gUnk_03001800.unkAA++;
    }
    sub_08037424(0x21);
    gUnk_03002C30[0x22].unk2 = gUnk_03002C30[0x21].unk2;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[0x21].unk4;
}

void sub_08025570(void)
{
    sub_08037424(0x21);
    gUnk_03002C30[0x22].unk2 = gUnk_03002C30[0x21].unk2;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[0x21].unk4;
    if (gUnk_03002C30[0x21].unk8 == 1)
    {
        clear_battle_sprite_slot(0x21, 2);
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x21].unk8--;
        gUnk_03002C30[0x21].unk9--;
        gUnk_03002C30[0x22].unk8--;
        gUnk_03002C30[0x22].unk9--;
    }
}

void sub_080255F8(void)
{
    sub_08037458(gUnk_03001800.unk88, gUnk_03001800.unkEC);
    gUnk_03001800.unk51 = gUnk_03001800.unkC8;
    sub_0803572C(&gUnk_03000590[gUnk_03001800.unk88].parts[0].unk10, gUnk_03001800.unk51);
    sub_08037498(gUnk_03001800.unk87, gUnk_03001800.unk51);
    gUnk_03001800.unk52 = gUnk_03001800.unkC8;
    sub_08035740(&gUnk_03000590[gUnk_03001800.unk87].parts[0].unk10, gUnk_03001800.unk52,
                 gUnk_03000590[gUnk_03001800.unk87].parts[0].data[8]);
    gUnk_03001800.unkAA++;
}

void sub_08025674(void)
{
    lz_decompress_dispatch(gUnk_084D6BFC, (void *)0x06017E00);
    set_display_digit_type(&gUnk_03000440.unkEE, gUnk_03001800.unk51, 1);
    battle_setup_text_sprites_0801A418(&gUnk_03000440.unkEE, gUnk_03001800.unk88, 0x21);
    set_display_digit_type(&gUnk_03000440.unkEE + 0x20, gUnk_03001800.unk52, 0);
    battle_setup_text_sprites_0801A418(&gUnk_03000440.unkEE + 0x20, gUnk_03001800.unk87, 0x21);
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_080256EC(void)
{
    update_battle_sprite_animations(&gUnk_03000440.unkEE, gUnk_03001800.unk88, 0x21);
    update_battle_sprite_animations(&gUnk_03000440.unkEE + 0x20, gUnk_03001800.unk87, 0x21);
    if (++gUnk_03000440.unk84, gUnk_03000440.unk89 == 0 && (KEYS_LO(gRepeatKeys) & 1) && gUnk_03000440.unk84 > 0x32)
        gUnk_03000440.unk84 = 0x78;
    if (gUnk_03000440.unk84 == 0x78)
    {
        clear_battle_sprite_slot(gUnk_03001800.unk88 * 4 + 0x21, 4);
        clear_battle_sprite_slot(gUnk_03001800.unk87 * 4 + 0x21, 4);
        gUnk_03001800.unkAA++;
    }
}

void battle_set_action_0x35(void)
{
    divide_by_100000_b(gUnk_03000440.unk9E, gUnk_03001800.unk51, 0x35);
    gUnk_03001800.unkA6 = 0x35;
    gUnk_03001800.unkAA++;
}

void dispatch_battle_action_step(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE004[gUnk_03001800.unkAA]();
}

void process_battle_action_phase(void)
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

void battle_render_bot_status_icon(void)
{
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 0x2E)
    {
        lz_decompress_dispatch(gUnk_084D6CC4, (void *)0x06014800);
        CpuFastSet(gUnk_0850E8F8, (void *)0x050002E0, 0x10);
    }
    else
    {
        lz_decompress_dispatch(gUnk_084D6E20, (void *)0x06014800);
        CpuFastSet(gUnk_0850E918, (void *)0x050002E0, 0x10);
    }
    gUnk_03002C30[0x21].unk0 |= 0x220;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unk6 = 0x5200;
    gUnk_03002C30[0x21].unk30 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk2;
    gUnk_03002C30[0x21].unk32 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk4 - 4;
    gUnk_03002C30[0x21].unk24 = 6;
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void sub_08025974(void)
{
    clear_sprite_table_mask(0x21, 1);
    gUnk_03002C30[0x22].unk0 = 0xC404;
    gUnk_03002C30[0x22].unk1C = 0;
    gUnk_03002C30[0x22].unk2 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk2;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk4 - 4;
    gUnk_03002C30[0x22].unkA = 7;
    gUnk_03002C30[0x22].unkB = 0xE0;
    gUnk_03002C30[0x22].unk23 = 0;
    gUnk_03002C30[0x22].unk6 = 0x5201;
    play_sound_effect(0x6A);
    gUnk_03001800.unkAA++;
}

void sub_08025A18(void)
{
    gUnk_03000590[gUnk_03001800.unk88].unkCA = 0;
    gUnk_03000590[gUnk_03001800.unk88].unkCB = sub_08036E54(gUnk_03001800.unkE8);
    gUnk_03000590[gUnk_03001800.unk88].unkCC = sub_08036E54(gUnk_03001800.unkEC);
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 0x2E)
        gUnk_03000590[gUnk_03001800.unk88].unkC9 = 0x2E;
    else
        gUnk_03000590[gUnk_03001800.unk88].unkC9 = 0x2F;
    gUnk_03001800.unkAA++;
}

void sub_08025AAC(void)
{
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 0x2E)
        gUnk_03001800.unkA6 = 0x31;
    else
        gUnk_03001800.unkA6 = 0x32;
    gUnk_03001800.unkAA++;
}

void sub_08025AF8(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE064[gUnk_03001800.unkAA]();
}

void sub_08025B20(void)
{
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero())
    {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    }
    else if (gUnk_03000590[gUnk_03001800.unk88].unkC1 == 0)
    {
        gUnk_03001800.unkA6 = 0x74;
        gUnk_03001800.unkAA++;
    }
    else
    {
        sub_08036270();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void sub_08025B9C(void)
{
    lz_decompress_dispatch(gUnk_084D6F88, (void *)0x06014800);
    CpuFastSet(gUnk_0850E938, (void *)0x050002E0, 0x10);
    gUnk_03002C30[0x21].unk0 |= 0x220;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unk30 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk2;
    gUnk_03002C30[0x21].unk32 = gUnk_03002C30[0x5D + gUnk_03001800.unk88 * 4].unk4 - 4;
    gUnk_03002C30[0x21].unk24 = 6;
    gUnk_03002C30[0x21].unk23 = 0;
    gUnk_03000440.unk84 = 0x48;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03000440.unk84], 0x21);
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void sub_08025C84(void)
{
    sub_080374E0(gUnk_03000590[gUnk_03001800.unk88].unkC1, gUnk_03001800.unkEC);
    gUnk_03001800.unk51 = gUnk_03001800.unkC8;
    if (gUnk_03000590[gUnk_03001800.unk87].unkC0 & 8)
        sub_0803752C(gUnk_03000590[gUnk_03001800.unk87].unkC1, 0x50, gUnk_03001800.unk51 * 2);
    else
        sub_0803752C(gUnk_03000590[gUnk_03001800.unk87].unkC1, 0x50, gUnk_03001800.unk51);
    gUnk_03001800.unk52 = gUnk_03001800.unkC8;
    gUnk_03001800.unk64[0] = gUnk_03001800.unk87;
    gUnk_03001800.unk87 = gUnk_03001800.unk88;
    sub_0801AEB4();
    gUnk_03001800.unkAA++;
}

void sub_08025D2C(void)
{
    if (dispatch_battle_action_substate(0))
        gUnk_03001800.unkAA++;
}

void sub_08025D4C(void)
{
    dispatch_battle_action_substate(0);
    play_sound_effect(0x51);
    gUnk_03001800.unkAA++;
}

void sub_08025D6C(void)
{
    s32 n;

    dispatch_battle_action_substate(0);
    n = medaforce_gauge_drain_step(gUnk_03001800.unk87);
    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03000440.unk84], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
        n++;
    if (n == 2)
    {
        clear_battle_ui_tilemaps();
        sub_0801AEB4();
        gUnk_03001800.unkAA++;
    }
}

void sub_08025DD4(void)
{
    gUnk_03001800.unk87 = gUnk_03001800.unk64[0];
    gUnk_03001800.unk51 = gUnk_03001800.unk52;
    gUnk_03002C30[0x21].unk0 |= 0x220;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unk30 = gUnk_03002C30[0x5D + gUnk_03001800.unk87 * 4].unk2;
    gUnk_03002C30[0x21].unk32 = gUnk_03002C30[0x5D + gUnk_03001800.unk87 * 4].unk4 - 4;
    gUnk_03002C30[0x21].unk24 = 6;
    gUnk_03002C30[0x21].unk23 = 0;
    gUnk_03001800.unkAA++;
}

void sub_08025E88(void)
{
    s32 n;

    dispatch_battle_action_substate(0);
    n = medaforce_gauge_fill_step(gUnk_03001800.unk87);
    if (gUnk_03002C30[0x21].unk0 & 0x8000)
    {
        gUnk_03002C30[0x21].unk0 |= 0x220;
        if (gUnk_03002C30[0x21].unk8 == 1)
        {
            clear_battle_sprite_slot(0x21, 1);
        }
        else
        {
            gUnk_03002C30[0x21].unk8--;
            gUnk_03002C30[0x21].unk9--;
        }
    }
    else
    {
        n++;
    }
    if (n == 2)
    {
        clear_battle_ui_tilemaps();
        sub_0801AEB4();
        gUnk_03001800.unkAA++;
    }
}

void sub_08025F14(void)
{
    gUnk_03001800.unkA6 = 0x75;
    gUnk_03001800.unkAA++;
}

void sub_08025F2C(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE0E4[gUnk_03001800.unkAA]();
}

void sub_08025F54(void)
{
    if (gUnk_03001800.unk28[gUnk_03001800.unk8A].unk2 && gUnk_03001800.unk28[gUnk_03001800.unk8A].unk3 == 0x33)
    {
        gUnk_03001800.unkAB = 0;
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03001800.unkA6 = 0x22;
        gUnk_03001800.unkAB = 1;
        gUnk_03001800.unkAA = 2;
    }
}

void sub_08025FA0(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE100[gUnk_03001800.unkAA]();
}

void sub_08025FC8(void)
{
    u32 i;

    lz_decompress_dispatch(gUnk_084D513C, (void *)0x06014800);
    CpuFastSet(gUnk_0850E678, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++)
    {
        gUnk_03002C30[i + 0x21].unk0 = 0xC404;
        gUnk_03002C30[i + 0x21].unk1C = 0;
        gUnk_03002C30[i + 0x21].unk4 = 0x58 - i * 0x18;
        gUnk_03002C30[i + 0x21].unkA = 7;
        gUnk_03002C30[i + 0x21].unkB = 0xF0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x38], i + 0x21);
        if (!(gUnk_03001800.unkF8 & 1))
        {
            gUnk_03002C30[i + 0x21].unk2 = 0x88;
        }
        else
        {
            gUnk_03002C30[i + 0x21].unk0 |= 0x1000;
            gUnk_03002C30[i + 0x21].unk2 = 0x68;
        }
    }
    play_sound_effect(0x52);
    gUnk_03001800.unkAA++;
}

void sub_08026080(void)
{
    u32 i;
    s32 done = 0;

    for (i = 0; i <= 2; i++)
    {
        process_sprite_anim_commands(gUnk_083B5F80[0x38], i + 0x21);
        if (gUnk_03002C30[i + 0x21].unk22 == 0xFF)
            done = 1;
    }
    if (done)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_080260EC(void)
{
    clear_battle_sprite_slot(0x21, 3);
    gUnk_03001800.unkAA++;
}

void sub_08026108(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE118[gUnk_03001800.unkAA]();
}

void sub_08026130(void)
{
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero())
    {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    }
    else
    {
        sub_08036270();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void sub_08026184(void)
{
    lz_decompress_dispatch(gUnk_084D71D8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E978, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC624;
    if (gUnk_03001800.unkF8 & 1)
        gUnk_03002C30[0x21].unk0 |= 0x1000;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[0x5D + gUnk_03001800.unk87 * 4].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[0x5D + gUnk_03001800.unk87 * 4].unk4 - 6;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk6 = 0x616;
    gUnk_03002C30[0x21].unk23 = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x4A], 0x21);
    gUnk_03001800.unkAA++;
}

void sub_08026284(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x4A], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        gUnk_03002C30[0x21].unk8 = 0x80;
        gUnk_03002C30[0x21].unk9 = 0x80;
        gUnk_03002C30[0x21].unk6 = 0x5604;
        gUnk_03002C30[0x21].unk4 = gUnk_03002C30[0x5D + gUnk_03001800.unk87 * 4].unk4 - 4;
        gUnk_03001800.unkAA++;
    }
}

void sub_080262FC(void)
{
    if (gUnk_03002C30[0x21].unk8 == 0x40)
    {
        play_sound_effect(0x53);
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x21].unk8 -= 8;
        gUnk_03002C30[0x21].unk9 -= 8;
    }
}

void sub_08026340(void)
{
    if (gUnk_03002C30[0x21].unk8 == 0x50)
    {
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x21].unk8 += 4;
        gUnk_03002C30[0x21].unk9 += 4;
    }
}

void sub_08026378(void)
{
    if (gUnk_03002C30[0x21].unk8 == 0x40)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x21].unk8 -= 4;
        gUnk_03002C30[0x21].unk9 -= 4;
    }
}

void sub_080263BC(void)
{
    clear_battle_sprite_slot(0x21, 1);
    gUnk_03000590[gUnk_03001800.unk87].unkBD |= 0x10;
    gUnk_03000590[gUnk_03001800.unk87].unkDF = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
    gUnk_03000590[gUnk_03001800.unk87].unkD8 = 0;
    sub_08035740(&gUnk_03000590[gUnk_03001800.unk87].unkD7 + 1, gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[6], 0xFF);
    gUnk_03001800.unkAA++;
}

void sub_08026444(void)
{
    gUnk_03001800.unkA6 = 0x2A;
    gUnk_03001800.unkAA++;
}

void sub_0802645C(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE16C[gUnk_03001800.unkAA]();
}

void sub_08026484(void)
{
    u32 r;

    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    r = decrement_battle_timer_and_check_zero();
    if (r)
    {
        gUnk_03001800.unkAB = 1;
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    }
    else
    {
        sub_08036270();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAB = r;
        gUnk_03001800.unkAA = 4;
    }
}

void sub_080264E4(void)
{
    lz_decompress_dispatch(gUnk_084D7528, (void *)0x06014800);
    CpuFastSet(gUnk_0850E998, (void *)0x050002C0, 0x10);
    gUnk_03002C30[0x21].unk0 = 0xC404;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[0x5D + gUnk_03001800.unk87 * 4].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[0x5D + gUnk_03001800.unk87 * 4].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 6;
    gUnk_03002C30[0x21].unkB = 0xE0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x4B], 0x21);
    gUnk_03002C30[0x22].unk0 = 0xC404;
    gUnk_03002C30[0x22].unk1C = 0;
    gUnk_03002C30[0x22].unk2 = gUnk_03002C30[0x5D + gUnk_03001800.unk87 * 4].unk2;
    gUnk_03002C30[0x22].unk4 = gUnk_03002C30[0x5D + gUnk_03001800.unk87 * 4].unk4 - 6;
    gUnk_03002C30[0x22].unkA = 7;
    gUnk_03002C30[0x22].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x4C], 0x22);
    play_sound_effect(0x5E);
    gUnk_03000440.unk86 = 0;
    gUnk_03001800.unkAA++;
}

void sub_08026628(void)
{
    if (gUnk_03000440.unk86 == 0x5A)
    {
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03000440.unk86++;
        process_sprite_anim_commands(gUnk_083B5F80[0x4B], 0x21);
        process_sprite_anim_commands(gUnk_083B5F80[0x4C], 0x22);
    }
}

void sub_08026678(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x4B], 0x21);
    process_sprite_anim_commands(gUnk_083B5F80[0x4C], 0x22);
    gUnk_03001800.unk118 = 1;
    gUnk_03001800.unk119 = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] - 0x37;
    gUnk_03001800.unk11A = sub_08037578(gUnk_03001800.unk119, gUnk_03001800.unkA7);
    memcpy_bytes_0803F63C(&gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7], &gUnk_03001800.unk11C, 0x18);
    load_part_data(gUnk_03001800.unk11A, gUnk_03001800.unkA7, &gUnk_03000440.unkEE);
    gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[0] = (&gUnk_03000440.unkEE)[0];
    gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] = (&gUnk_03000440.unkEE)[1];
    gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[5] = (&gUnk_03000440.unkEE)[5];
    gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[6] = (&gUnk_03000440.unkEE)[6];
    gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[7] = (&gUnk_03000440.unkEE)[7];
    gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[0xC] = (&gUnk_03000440.unkEE)[0xC];
    gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[2] = 7;
    gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].unk17 = gUnk_03001800.unk11A;
    battle_process_all_bot_actions(gUnk_03001800.unk87);
    battle_bot_select_part(gUnk_03001800.unk87, gUnk_03001800.unkA7 + 1);
    load_all_bot_part_sprites();
    iterate_bots_setup_battle_sprites();
    gUnk_03001800.unkAA++;
}

void sub_08026810(void)
{
    clear_battle_sprite_slot(0x21, 2);
    memcpy_bytes_08041D04((const void *)gUnk_083BB9CC[0][gUnk_03001800.unk11C.unk17 * 4 + gUnk_03001800.unkA7], gUnk_03000440.unk9E, 0xF);
    memcpy_bytes_08041D04((const void *)gUnk_083BB9CC[0][gUnk_03001800.unk11A * 4 + gUnk_03001800.unkA7], gUnk_03000440.unk9E + 0x14, 0xF);
    gUnk_03001800.unkA6 = 0x2F;
    gUnk_03001800.unkAA++;
}

void sub_08026884(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE1C0[gUnk_03001800.unkAA]();
}

void sub_080268AC(void)
{
    sub_0803769C(gUnk_03001800.unk87);
    sub_080376F4(gUnk_03001800.unk87);
    gUnk_03001800.unkAA++;
}

void sub_080268D4(void)
{
    sub_08037728(gUnk_03001800.unk88, 0, gUnk_03001800.unkEC);
    sub_08037728(gUnk_03001800.unk88, 1, gUnk_03001800.unkEC);
    sub_08037728(gUnk_03001800.unk88, 2, gUnk_03001800.unkEC);
    sub_08037728(gUnk_03001800.unk88, 3, gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void sub_08026924(void)
{
    s16 x, y;

    lz_decompress_dispatch(gUnk_084D1824, (void *)0x06010000);
    CpuFastSet(gUnk_0850E018, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2))
    {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    }
    else
    {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    set_display_digit_type(gUnk_03000440.unk9E, gUnk_03001800.unkD6[0], 1);
    setup_battle_sprite_oam_entries(gUnk_03000440.unk9E, 0xA, 0, x, y);
    set_display_digit_type(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkD6[1], 1);
    setup_battle_sprite_oam_entries(gUnk_03000440.unk9E + 0x14, 0xE, 1, x, y);
    set_display_digit_type(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unkD6[2], 1);
    setup_battle_sprite_oam_entries(gUnk_03000440.unk9E + 0x28, 0x12, 2, x, y);
    set_display_digit_type(gUnk_03000440.unk9E + 0x3C, gUnk_03001800.unkD6[3], 1);
    setup_battle_sprite_oam_entries(gUnk_03000440.unk9E + 0x3C, 0x16, 3, x, y);
    play_sound_effect(0x5B);
    gUnk_03001800.unkAA++;
}

void sub_08026A24(void)
{
    sub_08036B50(gUnk_03000440.unk9E, 0xA);
    sub_08036B50(gUnk_03000440.unk9E + 0x14, 0xE);
    sub_08036B50(gUnk_03000440.unk9E + 0x28, 0x12);
    if (sub_08036B50(gUnk_03000440.unk9E + 0x3C, 0x16))
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_08026A74(void)
{
    s32 n;
    u32 side;

    n = sub_08036BB8(&gUnk_03001800.unkD6[0], gUnk_03001800.unk88, 0);
    n += sub_08036BB8(&gUnk_03001800.unkD6[1], gUnk_03001800.unk88, 1);
    n += sub_08036BB8(&gUnk_03001800.unkD6[2], gUnk_03001800.unk88, 2);
    n += sub_08036BB8(&gUnk_03001800.unkD6[3], gUnk_03001800.unk88, 3);
    if (!(gUnk_03001800.unkF8 & 2))
        side = 1;
    else
        side = 0;
    sub_08036370(side, gUnk_03001800.unk88);
    sub_080364A8(side, gUnk_03001800.unk88);
    if (n == 4)
    {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_08026AF4(void)
{
    u16 x, y;
    s32 shown = 0;

    lz_decompress_dispatch(gUnk_084CCE48, (void *)0x06010800);
    CpuFastSet(gUnk_0850E358, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2))
    {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    }
    else
    {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    if (gUnk_03001800.unkD2[0])
    {
        sub_08036C20(0xA, 0, x, y, 0x1E);
        shown = 1;
    }
    if (gUnk_03001800.unkD2[1])
    {
        sub_08036C20(0xB, 1, x, y, 0x1E);
        shown = 1;
    }
    if (gUnk_03001800.unkD2[2])
    {
        sub_08036C20(0xC, 2, x, y, 0x1E);
        shown = 1;
    }
    if (gUnk_03001800.unkD2[3])
    {
        sub_08036C20(0xD, 3, x, y, 0x1E);
        shown = 1;
    }
    if (shown)
    {
        sub_08035194(gUnk_03001800.unk88);
        gUnk_03001800.unkAA = 0xD;
    }
    else
    {
        gUnk_03001800.unkAA++;
    }
}

void sub_08026BF8(void)
{
    s32 done = 0;

    if (gUnk_03001800.unkD2[0])
    {
        process_sprite_anim_commands(gUnk_083B5F80[0x1E], 0xA);
        if (gUnk_03002C30[0xA].unk22 == 0xFF)
            done = 1;
    }
    if (gUnk_03001800.unkD2[1])
    {
        process_sprite_anim_commands(gUnk_083B5F80[0x1E], 0xB);
        if (gUnk_03002C30[0xB].unk22 == 0xFF)
            done = 1;
    }
    if (gUnk_03001800.unkD2[2])
    {
        process_sprite_anim_commands(gUnk_083B5F80[0x1E], 0xC);
        if (gUnk_03002C30[0xC].unk22 == 0xFF)
            done = 1;
    }
    if (gUnk_03001800.unkD2[3])
    {
        process_sprite_anim_commands(gUnk_083B5F80[0x1E], 0xD);
        if (gUnk_03002C30[0xD].unk22 == 0xFF)
            done = 1;
    }
    if (done)
    {
        clear_battle_sprite_slot(0xA, 4);
        gUnk_03001800.unkAA++;
    }
}

void sub_08026CBC(void)
{
    if (gUnk_03000590[gUnk_03001800.unk88].parts[0].unk11 == 0)
        add_bot_to_defeated_list(gUnk_03001800.unk88);
    gUnk_03001800.unkAA++;
}

void sub_08026CF4(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE240[gUnk_03001800.unkAA]();
}

void sub_08026D1C(void)
{
    if (gUnk_03001800.unkB8 & 2)
        gUnk_03001800.unkAA = 0x20;
    else
        gUnk_03001800.unkAA++;
}

void sub_08026D44(void)
{
    if (gUnk_03001800.unkCA)
    {
        calc_bot_evasion_modifier(gUnk_03001800.unk87);
        sub_080355C4(gUnk_03001800.unk87);
        gUnk_03001800.unkD0 = gUnk_03001800.unk8B;
        battle_set_damage_vs_armor(gUnk_03001800.unk88, gUnk_03001800.unk8B, gUnk_03001800.unkCA);
        gUnk_03001800.unkAA += 3;
    }
    else
    {
        gUnk_03001800.unkAA++;
    }
}

void sub_08026D98(void)
{
    lz_decompress_dispatch(gUnk_084CA61C, (void *)0x06010000);
    CpuFastSet(gUnk_0850E198, (void *)0x050003C0, 8);
    gUnk_03002C30[0xA].unk6 = 0x1500;
    play_sound_effect(0x2A);
    gUnk_03002C30[0xA].unk0 = 0xC404;
    gUnk_03002C30[0xA].unk1C = 0;
    gUnk_03002C30[0xA].unkA = 0xE;
    gUnk_03002C30[0xA].unkB = 0x80;
    gUnk_03002C30[0xA].unk23 = 0;
    if (!(gUnk_03001800.unkF8 & 2))
    {
        if (gUnk_03001800.unk8B == 2)
            gUnk_03002C30[0xA].unk2 = gUnk_03001800.unk158 - 0x10;
        else
            gUnk_03002C30[0xA].unk2 = gUnk_03001800.unk158;
        gUnk_03002C30[0xA].unk4 = gUnk_03001800.unk15A;
    }
    else
    {
        if (gUnk_03001800.unk8B == 1)
            gUnk_03002C30[0xA].unk2 = gUnk_03001800.unk154 + 0x10;
        else
            gUnk_03002C30[0xA].unk2 = gUnk_03001800.unk154;
        gUnk_03002C30[0xA].unk4 = gUnk_03001800.unk156;
    }
    gUnk_03001800.unkAA++;
}

void sub_08026EC0(void)
{
    gUnk_03001800.unkAA = 2;
}

void sub_08026ED0(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE300[gUnk_03001800.unkAA]();
}

void sub_08026EF8(void)
{
    u32 r = clear_ewram_buffer_02023000_b(gUnk_03001800.unk87);
    if (r)
    {
        gUnk_03001800.unk8B = gUnk_03001800.unkD0 = r - 1;
        gUnk_03001800.unkAA = 2;
    }
    else
    {
        gUnk_03001800.unkAA++;
    }
}

void sub_08026F34(void)
{
    clear_battle_sprite_slot(0, 0x80);
    battle_calc_damage_split(gUnk_03001800.unk87, gUnk_03001800.unkD0, gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void sub_08026F6C(void)
{
    u32 r;
    struct Unk_03001800 *g = &gUnk_03001800;
    if (g->unkCA && (r = clear_ewram_buffer_02023000_b(g->unk88)))
    {
        r--;
        g->unkD0 = r;
        g->unk8B = r;
        battle_calc_damage_split(g->unk87, g->unkD0, g->unkCA);
        g->unkAA = 0x10;
    }
    else
    {
        g->unkAA++;
    }
}

void sub_08026FC0(void)
{
    gUnk_03001800.unkAA = 4;
}

void sub_08026FD0(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE380[gUnk_03001800.unkAA]();
}

void sub_08026FF8(void)
{
    u32 i;
    struct Unk_03000590 *bots;
    for (i = 0; i <= 2; i++)
    {
        gUnk_03001800.unkD2[i] = 0;
        gUnk_03001800.unkD6[i] = 0;
    }
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    i = 0;
    bots = gUnk_03000590;
    for (; i <= 2; i++)
    {
        u32 rec = gUnk_03001800.unk60 + i;
        if (bots[rec].unk40 && bots[rec].parts[0].unk11)
        {
            gUnk_03001800.unkD2[i] = get_random_battle_weight_entry(rec);
            battle_set_damage_vs_armor(gUnk_03001800.unk60 + i, gUnk_03001800.unkD2[i], gUnk_03001800.unkEC);
            gUnk_03001800.unkD2[i] |= gUnk_03001800.unkD1 << 7;
            gUnk_03001800.unkD6[i] = gUnk_03001800.unkC8;
        }
    }
    gUnk_03001800.unkAA++;
}

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
