#include "global.h"

void sub_0801C988(void)
{
    if ((gUnk_03002C30[0x21].unk8 += 8) == 0x40)
    {
        if (gUnk_03001800.unkAA < 0x20)
            play_sound_effect(0x3F);
        gUnk_03001800.unkAA++;
    }
}

void sub_0801C9C8(void)
{
    set_target_sprite_position(gUnk_03001800.unk87, gFrameCounter, gUnk_03001800.unk51);
    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03001800.unk52], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        update_target_cursor_position(gUnk_03001800.unk87);
        gUnk_03001800.unkAA++;
    }
}

void sub_0801CA2C(void)
{
    if (gUnk_03002C30[0x21].unk8 == 8)
    {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x21].unk8 -= 8;
    }
}

void sub_0801CA60(void)
{
    set_display_digit_type(&gUnk_03000440.unkEE, gUnk_03001800.unkC8, 1);
    render_battle_text_sprites(&gUnk_03000440.unkEE, gUnk_03001800.unk87, 0x21);
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_0801CAA8(void)
{
    update_battle_sprite_animations(&gUnk_03000440.unkEE, gUnk_03001800.unk87, 0x21);
    if (++gUnk_03000440.unk84, gUnk_03000440.unk89 == 0 && (KEYS_LO(gRepeatKeys) & 1) && gUnk_03000440.unk84 > 0x32)
        gUnk_03000440.unk84 = 0x78;
    if (gUnk_03000440.unk84 == 0x78)
    {
        clear_battle_sprite_slot(gUnk_03001800.unk87 * 4 + 0x21, 4);
        gUnk_03001800.unkAA++;
    }
}

void load_battle_script_data_d0(void)
{
    memcpy_bytes_0803F63C(gUnk_083C6DE8[gUnk_03001800.unkD0], gUnk_03000440.unk9E, 0xE);
    divide_by_100000_b(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkC8, 0x35);
    gUnk_03001800.unkA6 = 0x12;
    gUnk_03001800.unkAA++;
}

void apply_battle_damage_tick(void)
{
    reduce_bot_part_stat(gUnk_03001800.unk87, gUnk_03001800.unkD0, gUnk_03001800.unkC8);
    gUnk_03001800.unkAA++;
}

void battle_check_hit_and_set_timer(void)
{
    if (gUnk_03001800.unkD1)
    {
        play_sound_effect(0x3B);
        sub_08035194(gUnk_03001800.unk87);
        gUnk_03001800.unkA6 = 0x13;
        gUnk_03001800.unkAA = 0x1A;
    }
    else
    {
        gUnk_03001800.unkAA = 0x20;
    }
}

void sub_0801CBE4(void)
{
    if (gUnk_03000590[gUnk_03001800.unk87].parts[0].unk11 == 0)
    {
        add_bot_to_defeated_list(gUnk_03001800.unk87);
        gUnk_03001800.unkAA = 0x2F;
    }
    else
    {
        gUnk_03001800.unkAA = 0x20;
    }
}

void sub_0801CC24(void)
{
    if (sprite_move_toward_target(0x21, 0x3C, 0x84))
    {
        play_sound_effect(0x41);
        gUnk_03000440.unk84 = 0;
        gUnk_03001800.unkAA++;
    }
}

void sub_0801CC58(void)
{
    sub_080353AC(gUnk_03000440.unk84);
    if (++gUnk_03000440.unk84 > 0x1D)
    {
        play_sound_effect(0x3F);
        gBg3Scroll.y = 0;
        gUnk_03000440.unk84 = 0;
        gUnk_03000440.unk86 = gUnk_03002C30[0x21].unk2;
        gUnk_03001800.unkAA++;
    }
}

void sub_0801CCB8(void)
{
    sub_0803536C(0x21, gUnk_03000440.unk84, gUnk_03000440.unk86);
    if (++gUnk_03000440.unk84 == 0x5A)
    {
        gUnk_03002C30[0x21].unk2 = gUnk_03000440.unk86;
        gUnk_03001800.unkAA++;
    }
}

void sub_0801CD08(void)
{
    if (gUnk_03001800.unk51 == 2)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA = 8;
}

void sub_0801CD28(void)
{
    gUnk_03001800.unkA6 = 0x15;
    gUnk_03001800.unkAA++;
}

void sub_0801CD40(void)
{
    gUnk_03001800.unkAA = 0x20;
}

void sub_0801CD50(void)
{
    lz_decompress_dispatch(gUnk_084CDBD8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E378, (void *)0x050002E0, 8);
    setup_battle_cursor_sprite_08036FF8(0x21,
        gUnk_03002C30[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkD0].unk2,
        gUnk_03002C30[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkD0].unk4, 4);
    gUnk_03001800.unkAA++;
}

void sub_0801CDB4(void)
{
    if (update_sprite_animations_tick_080370AC(0x21, 4))
        gUnk_03001800.unkAA++;
}

void sub_0801CDD4(void)
{
    lz_decompress_dispatch(gUnk_084CC9A8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E338, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC004;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkD0].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkD0].unk4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x22], 0x21);
    gUnk_03001800.unkAA++;
}

void sub_0801CE94(void)
{
    process_sprite_anim_commands(gUnk_083B5F80[0x22], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
    {
        clear_battle_sprite_slot(0x21, 1);
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
        switch (gUnk_03001800.unk51)
        {
        case 0:
            lz_decompress_dispatch(gUnk_084C907C, (void *)0x06014800);
            CpuFastSet(gUnk_0850E058, (void *)0x050002C0, 8);
            break;
        case 1:
            lz_decompress_dispatch(gUnk_084C9288, (void *)0x06014800);
            CpuFastSet(gUnk_0850E078, (void *)0x050002C0, 8);
            break;
        case 2:
            lz_decompress_dispatch(gUnk_084C9624, (void *)0x06014800);
            CpuFastSet(gUnk_0850E098, (void *)0x050002C0, 8);
            break;
        case 3:
            lz_decompress_dispatch(gUnk_084C978C, (void *)0x06014800);
            CpuFastSet(gUnk_0850E0B8, (void *)0x050002C0, 8);
            break;
        }
        gUnk_03001800.unkAA = 0xE;
    }
}

void sub_0801CF78(void)
{
    u8 v;

    if (gUnk_03001800.unk51 != 2)
    {
        v = gUnk_03000590[gUnk_03001800.unk87].parts[3].unk12 >> 1;
        if (v >= gUnk_03001800.unk28[gUnk_03001800.unk89].unk4)
        {
            gUnk_03001800.unkAA++;
        }
        else
        {
            gUnk_03001800.unk28[gUnk_03001800.unk89].unk4 -= v;
            gUnk_03001800.unkAA = 0x2D;
        }
    }
    else
    {
        gUnk_03001800.unk28[gUnk_03001800.unk89].unk4--;
        if (gUnk_03001800.unk28[gUnk_03001800.unk89].unk4 == 0)
            gUnk_03001800.unkAA++;
        else
            gUnk_03001800.unkAA = 0x2E;
    }
}

void sub_0801CFFC(void)
{
    switch (gUnk_03001800.unk51)
    {
    case 0:
        lz_decompress_dispatch(gUnk_084C907C, (void *)0x06015400);
        break;
    case 1:
        lz_decompress_dispatch(gUnk_084C9288, (void *)0x06015400);
        break;
    case 2:
        lz_decompress_dispatch(gUnk_084C9624, (void *)0x06015400);
        break;
    case 3:
        lz_decompress_dispatch(gUnk_084C978C, (void *)0x06015400);
        break;
    }
    gUnk_03001800.unkAA++;
}

INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801D06C);

void sub_0801D174(void)
{
    gUnk_03002C30[0x21].unk23 = 0;
    gUnk_03000440.unk84 = 0;
    play_sound_effect(0x34);
    gUnk_03001800.unkAA++;
}

void sub_0801D1AC(void)
{
    if (sub_080353CC(0x21) == 0)
    {
        if (!(gUnk_03000440.unk84 & 1))
        {
            if (gUnk_03001800.unk89 == 0)
                gUnk_03002C30[0x21].unk2++;
            else
                gUnk_03002C30[0x21].unk2--;
        }
        gUnk_03000440.unk84++;
    }
    else if (gUnk_03002C30[0x21].unk8 == 8)
    {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
    else
    {
        gUnk_03002C30[0x21].unk8 -= 8;
    }
}

void sub_0801D244(void)
{
    if (gUnk_03001800.unk51 == 2)
        gUnk_03001800.unkAA = 0x2E;
    else
        gUnk_03001800.unkAA = 0x2D;
}

void sub_0801D264(void)
{
    gUnk_03001800.unk28[gUnk_03001800.unk89].unk2 = 0;
    gUnk_03001800.unk28[gUnk_03001800.unk89].unk3 = 0;
    gUnk_03001800.unk28[gUnk_03001800.unk89].unk4 = 0;
    gUnk_03001800.unk28[gUnk_03001800.unk89].unk5 = 0;
    gUnk_03001800.unkA6 = 0x25;
    gUnk_03001800.unkAA++;
}

void sub_0801D2AC(void)
{
    gUnk_03001800.unkB5 = 1;
    gUnk_03001800.unkAB = 0;
}

void sub_0801D2C4(void)
{
    gUnk_03001800.unkB5 = 1;
    gUnk_03001800.unkAB = 1;
}

void sub_0801D2D8(void)
{
    gUnk_03001800.unkB5 = 1;
    gUnk_03001800.unkAB = 2;
}

void battle_dispatch_phase_handler_0801D2F0(void)
{
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD50C[gUnk_03001800.unkAA]();
}

void sub_0801D318(void)
{
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03000590[gUnk_03001800.unk87].unkDD - 1].unk11)
    {
        gUnk_03001800.unkB5 = 1;
        gUnk_03001800.unkAB = 0;
    }
    else
    {
        gUnk_03001800.unkA6 = 5;
        gUnk_03001800.unkAA++;
    }
}

void sub_0801D36C(void)
{
    gUnk_03001800.unkB5 = 1;
    gUnk_03001800.unkAB = 1;
}

INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801D380);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801D40C);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801D434);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801D45C);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801D524);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801D544);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801D580);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801D5A8);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801D6A4);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801D738);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801D878);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801D95C);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801D9DC);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801DAEC);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801DC74);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801DD30);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801DD74);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801DDDC);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801DE1C);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801DE44);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801DEE4);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801DF0C);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801DF60);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801DFE0);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801E09C);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801E200);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801E248);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801E2B8);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801E2D8);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801E300);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801E3C0);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801E474);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801E54C);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801E5DC);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801E830);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801E864);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801E8DC);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801E918);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801E9B0);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801E9E0);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801E9FC);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801EA5C);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801EA94);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801EAD4);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801EB5C);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801EBD4);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801EBF8);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801EC3C);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801ECC0);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801ED50);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801EEE4);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801F018);
INCLUDE_ASM("asm/nonmatching/code_0801C988", decompress_sprite_tiles_to_vram_obj_0);
INCLUDE_ASM("asm/nonmatching/code_0801C988", battle_resolve_action_target);
INCLUDE_ASM("asm/nonmatching/code_0801C988", decompress_sprite_tiles_to_vram_obj_800);
INCLUDE_ASM("asm/nonmatching/code_0801C988", start_battle_transition_anim);
INCLUDE_ASM("asm/nonmatching/code_0801C988", decompress_sprite_tiles_to_vram_obj_0_alt);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801F374);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801F390);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801F3F0);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801F484);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801F4AC);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801F5BC);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801F780);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801F800);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801F9B0);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801F9EC);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801FA40);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801FA68);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801FADC);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801FBC4);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801FD88);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801FDEC);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801FE14);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801FE64);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801FEC8);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801FEE8);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0801FF9C);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_08020004);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_08020050);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_080200A8);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_080201DC);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_08020248);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_08020288);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_080202E0);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0802036C);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_08020428);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_08020474);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_08020530);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0802057C);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_080205A4);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_08020608);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_08020628);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_080206E8);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_08020728);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_08020768);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_080207A4);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_0802081C);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_08020844);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_080208C0);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_080208E8);
INCLUDE_ASM("asm/nonmatching/code_0801C988", sub_08020928);
