#include "global.h"

void sub_08008430(void)
{
    sub_080093F8();
    sub_0800A180();
    if (update_blend_effect())
        gGameSubState++;
}

void sub_08008454(void)
{
    sub_080093F8();
    sub_0800A180();
    text_window_init(1, 2, 0);
    gGameSubState++;
}

void sub_08008478(void)
{
    sub_080093F8();
    sub_0800A180();
    if (run_message(gUnk_083B53F8[12]))
        gGameSubState++;
}

void sub_080084A4(void)
{
    sub_080093F8();
    sub_0800A180();
    sub_0800A1E4();
    sub_0800ABF0();
    if (KEYS_LO(gNewKeys) & 1)
    {
        play_sound_effect(4);
        clear_sprite_table_mask(1, 2);
        gUnk_03000440.unk46 = 0;
        gUnk_03000440.unk3F = 0;
        gGameSubState = 0x30;
    }
    else if (KEYS_LO(gNewKeys) & 2)
    {
        play_sound_effect(5);
        gGameSubState++;
    }
    else if (*((u8 *)&gNewKeys + 1) & 2)
    {
        play_sound_effect(2);
        gUnk_03000440.unk42 = (gUnk_03000440.unk42 - 1) & 3;
        gGameSubState = 0x34;
    }
    else if (*((u8 *)&gNewKeys + 1) & 1)
    {
        play_sound_effect(2);
        gUnk_03000440.unk42 = (gUnk_03000440.unk42 + 1) & 3;
        gGameSubState = 0x34;
    }
    else if (KEYS_LO(gNewKeys) & 8)
    {
        play_sound_effect(4);
        gUnk_03000440.unk43 = 2;
        gGameSubState = 0x48;
    }
}

void sub_08008590(void)
{
    set_blend_effect_mode(6, 0x3F, 0x20);
    sub_080093F8();
    sub_0800A180();
    gGameSubState++;
}

void sub_080085B4(void)
{
    sub_080093F8();
    if (gUnk_03000440.unk3F == 0)
        sub_0800AC2C();
    else
        sub_0800ACA8();
    sub_0803FB0C();
    gGameSubState++;
}

void sub_080085E8(void)
{
    const void *msg;

    sub_080093F8();
    if (gUnk_03000440.unk3F == 0)
    {
        sub_0800AD00();
        msg = gUnk_083B825C[gUnk_03000BE0[gUnk_03000440.unk3D].unk18[gUnk_03000440.unk46]];
    }
    else
    {
        msg = gUnk_083B53F8[15];
    }
    if (run_message(msg))
        gGameSubState++;
}

void sub_08008650(void)
{
    sub_080093F8();
    if (gUnk_03000440.unk3F == 0)
    {
        sub_0800AD00();
        if (sub_0800AD58())
        {
            sub_0800AB0C();
            sub_0803FB0C();
            gGameSubState--;
            return;
        }
        if (sub_0800ADE8())
        {
            sub_0803FB0C();
            gGameSubState--;
            return;
        }
        if (KEYS_LO(gNewKeys) & 1)
        {
            play_sound_effect(4);
            clear_sprite_table_mask(1, 2);
            sub_0800ACA8();
            sub_0803FB0C();
            gUnk_03000440.unk3F = 1;
            gGameSubState--;
            return;
        }
        if (KEYS_LO(gNewKeys) & 2)
        {
            play_sound_effect(5);
            clear_sprite_table_mask(1, 2);
            gUnk_03000440.unk46 = 0;
            sub_0800A0FC();
            sub_0803FB0C();
            gGameSubState = 0x2B;
            return;
        }
    }
    else
    {
        sub_08041C5C(3, gFrameCounter, 0x30);
        if (sub_0800AE54())
        {
            sub_0800AB0C();
            sub_0800ABA4();
            sub_0800ACA8();
            return;
        }
        if (KEYS_LO(gNewKeys) & 1)
        {
            play_sound_effect(4);
            clear_sprite_table_mask(3, 1);
            gUnk_03000440.unk46 = 0;
            sub_0800A0FC();
            sub_0803FB0C();
            gGameSubState = 0x2B;
            return;
        }
        if (KEYS_LO(gNewKeys) & 2)
        {
            play_sound_effect(5);
            clear_sprite_table_mask(3, 1);
            sub_0800AC2C();
            sub_0803FB0C();
            gUnk_03000440.unk3F = 0;
            gGameSubState--;
            return;
        }
    }
    if (KEYS_LO(gNewKeys) & 8)
    {
        play_sound_effect(4);
        gUnk_03000440.unk46 |= 0x80;
        gUnk_03000440.unk43 = 2;
        gGameSubState = 0x48;
    }
}

void sub_080087CC(void)
{
    u32 zero;

    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1A03;
    lz_decompress_dispatch(gUnk_084EAC58, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C3208, (void *)0x06007480);
    lz_decompress_dispatch(gUnk_084C3648, (void *)0x06007880);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF4E0, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EFE28, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0A00, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F1BA0, REG_BG3CNT, 0x200);
    CpuFastSet(gUnk_084F32A0, (void *)0x05000000, 0x70);
    CpuFastSet(gUnk_0850DD18, (void *)0x05000380, 8);
    CpuFastSet(gUnk_0850DD18 + 0x10, (void *)0x050003A0, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
    zero = 0;
    CpuFastSet(&zero, gUnk_03002C30, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    gUnk_03000440.unk48 = 0;
    gUnk_03000440.unk3F = 0;
    sub_08009EA0();
    sub_08009EF4();
    sub_08009F50();
    sub_08009FC8();
    sub_0800A0FC();
    render_medal_skill_stats();
    sub_0800B0F8();
    draw_medal_skill_bars();
    set_blend_effect_mode(5, 0x3F, 0x20);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_08008980(void)
{
    sub_080093F8();
    sub_0800A180();
    sub_0800B130();
    if (update_blend_effect())
        gGameSubState++;
}

void sub_080089A8(void)
{
    sub_080093F8();
    sub_0800A180();
    sub_0800B130();
    sub_0800A1E4();
    sub_0800B468();
    if (KEYS_LO(gNewKeys) & 2)
    {
        play_sound_effect(5);
        gGameSubState++;
    }
    else if (*((u8 *)&gNewKeys + 1) & 2)
    {
        play_sound_effect(2);
        gUnk_03000440.unk42 = (gUnk_03000440.unk42 - 1) & 3;
        gGameSubState = 0x44;
    }
    else if (*((u8 *)&gNewKeys + 1) & 1)
    {
        play_sound_effect(2);
        gUnk_03000440.unk42 = (gUnk_03000440.unk42 + 1) & 3;
        gGameSubState = 0x44;
    }
}

void sub_08008A34(void)
{
    set_blend_effect_mode(6, 0x3F, 0x20);
    sub_080093F8();
    sub_0800A180();
    sub_0800B130();
    gGameSubState++;
}

void sub_08008A5C(void)
{
    u8 b;

    setup_battle_cursor_sprite_0800B5E8();
    if ((b = KEYS_LO(gRepeatKeys) & 0x40))
    {
        if (gUnk_03000440.unk48 == 0)
            gUnk_03000440.unk48 = 7;
        else
            gUnk_03000440.unk48--;
    }
    else if (KEYS_LO(gRepeatKeys) & 0x80)
    {
        if (gUnk_03000440.unk48 == 7)
            gUnk_03000440.unk48 = b;
        else
            gUnk_03000440.unk48++;
    }
    else if (KEYS_LO(gRepeatKeys) & 0x10 && gUnk_03000BE0[gUnk_03000440.unk3D].unk20[gUnk_03000440.unk48] != 100)
    {
        gUnk_03000BE0[gUnk_03000440.unk3D].unk20[gUnk_03000440.unk48]++;
        render_medal_skill_stats();
    }
    else if (KEYS_LO(gRepeatKeys) & 0x20 && gUnk_03000BE0[gUnk_03000440.unk3D].unk20[gUnk_03000440.unk48] != 0)
    {
        gUnk_03000BE0[gUnk_03000440.unk3D].unk20[gUnk_03000440.unk48]--;
        render_medal_skill_stats();
    }
    else if (KEYS_LO(gNewKeys) & 4)
    {
        gUnk_03000BE0[gUnk_03000440.unk3D].unk28[gUnk_03000440.unk48] = 7;
        draw_medal_skill_bars();
    }
    else if (KEYS_LO(gNewKeys) & 2)
    {
        clear_battle_sprite_slot(0x7F, 1);
        gGameSubState = 0x3A;
    }
}

void sub_08008B80(void)
{
    sub_080093F8();
    clear_sprite_table_mask(1, 5);
    CpuFastSet(gUnk_084E2E78, (void *)0x050003C0, 8);
    sub_0800AA1C();
    sub_0803FB0C();
    gGameSubState++;
}

void sub_08008BB8(void)
{
    sub_080093F8();
    if (run_message(gUnk_083B53F8[5]))
        gGameSubState++;
}

void sub_08008BE0(void)
{
    u8 b;

    sub_080093F8();
    process_sprite_anim_commands(gUnk_083B5F80[3], 6);
    if ((b = KEYS_LO(gRepeatKeys) & 0x40))
    {
        if (gUnk_03000440.unk44 == 0)
            gUnk_03000440.unk44 = gUnk_03000440.unk45 - 1;
        else
            gUnk_03000440.unk44--;
        goto moved;
    }
    else if (KEYS_LO(gRepeatKeys) & 0x80)
    {
        if (gUnk_03000440.unk44 == gUnk_03000440.unk45 - 1)
            gUnk_03000440.unk44 = b;
        else
            gUnk_03000440.unk44++;
    moved:
        play_sound_effect(2);
        sub_0800AAC0();
    }
    else if (KEYS_LO(gNewKeys) & 1)
    {
        play_sound_effect(4);
        sub_0800AA1C();
        sub_0803FB0C();
        gGameSubState++;
    }
    else if (KEYS_LO(gNewKeys) & 0xA)
    {
        play_sound_effect(5);
        gGameSubState = 0x4E;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08008430", sub_08008CA0);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_080090D0);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_08009174);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_080091E0);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_08009248);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_08009274);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_080092D4);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_08009374);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_080093AC);

void sub_080093E0(void)
{
    clear_battle_sprite_slot(0, 0x80);
    sub_08043CA8();
    sub_08044CDC(1);
}

INCLUDE_ASM("asm/nonmatching/code_08008430", sub_080093F8);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800941C);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800944C);
INCLUDE_ASM("asm/nonmatching/code_08008430", render_medal_sprite_tile);
INCLUDE_ASM("asm/nonmatching/code_08008430", render_medal_list_entries);
INCLUDE_ASM("asm/nonmatching/code_08008430", render_medal_slots_in_menu);
INCLUDE_ASM("asm/nonmatching/code_08008430", render_medal_name_display);
INCLUDE_ASM("asm/nonmatching/code_08008430", load_medal_sprite);
INCLUDE_ASM("asm/nonmatching/code_08008430", render_medal_level_display);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800988C);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_08009900);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800994C);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_080099A4);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_08009A38);
INCLUDE_ASM("asm/nonmatching/code_08008430", update_battle_sprite_visibility);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_08009BC8);
INCLUDE_ASM("asm/nonmatching/code_08008430", get_medal_active_slot);
INCLUDE_ASM("asm/nonmatching/code_08008430", decompress_active_medal_sprite);
INCLUDE_ASM("asm/nonmatching/code_08008430", init_active_medal_battle_sprites);
INCLUDE_ASM("asm/nonmatching/code_08008430", draw_medal_position_tile);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_08009E4C);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_08009EA0);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_08009EF4);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_08009F50);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_08009F90);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_08009FC8);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800A000);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800A05C);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800A0B8);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800A0FC);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800A180);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800A1E4);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800A2B4);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800A2E8);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800A594);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800A854);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800A8A0);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800A928);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800A960);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800AA1C);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800AAC0);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800AB0C);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800ABA4);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800ABF0);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800AC2C);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800ACA8);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800AD00);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800AD58);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800ADE8);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800AE54);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800AED0);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800AF0C);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800AF64);
INCLUDE_ASM("asm/nonmatching/code_08008430", render_medal_skill_stats);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800B0F8);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800B130);
INCLUDE_ASM("asm/nonmatching/code_08008430", draw_medal_skill_bars);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800B468);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800B498);
INCLUDE_ASM("asm/nonmatching/code_08008430", increment_medal_level_on_input);
INCLUDE_ASM("asm/nonmatching/code_08008430", handle_medal_level_down_input);
INCLUDE_ASM("asm/nonmatching/code_08008430", setup_battle_cursor_sprite_0800B5E8);
INCLUDE_ASM("asm/nonmatching/code_08008430", init_battle_cursor_sprite_0800B668);
INCLUDE_ASM("asm/nonmatching/code_08008430", handle_menu_cursor_updown);
INCLUDE_ASM("asm/nonmatching/code_08008430", update_battle_sprite_and_check_done);
INCLUDE_ASM("asm/nonmatching/code_08008430", update_sprite_blink_animation);
INCLUDE_ASM("asm/nonmatching/code_08008430", update_battle_sprite_scroll);
INCLUDE_ASM("asm/nonmatching/code_08008430", fill_bg0_rect_and_advance_sprite_state);
INCLUDE_ASM("asm/nonmatching/code_08008430", dispatch_menu_substate_handler);
INCLUDE_ASM("asm/nonmatching/code_08008430", init_battle_sprite_vram);
INCLUDE_ASM("asm/nonmatching/code_08008430", menu_handle_selection_input);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800BAB8);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800BAD8);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800BAF8);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800BE6C);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800BE8C);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800C29C);
INCLUDE_ASM("asm/nonmatching/code_08008430", menu_tab_select_handler_b);
