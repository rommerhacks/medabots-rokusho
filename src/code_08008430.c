#include "global.h"

void medal_rotation_wait_fade(void)
{
    sub_080093F8();
    sub_0800A180();
    if (update_blend_effect())
        gGameSubState++;
}

void medal_rotation_open_text_window(void)
{
    sub_080093F8();
    sub_0800A180();
    text_window_init(1, 2, 0);
    gGameSubState++;
}

void medal_rotation_show_hint(void)
{
    sub_080093F8();
    sub_0800A180();
    if (run_message(gUnk_083B53F8[12]))
        gGameSubState++;
}

void medal_rotation_handle_input(void)
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

void medal_rotation_start_fade_out(void)
{
    set_blend_effect_mode(6, 0x3F, 0x20);
    sub_080093F8();
    sub_0800A180();
    gGameSubState++;
}

void medal_rotation_edit_init(void)
{
    sub_080093F8();
    if (gUnk_03000440.unk3F == 0)
        sub_0800AC2C();
    else
        sub_0800ACA8();
    sub_0803FB0C();
    gGameSubState++;
}

void medal_rotation_edit_show_message(void)
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

void medal_rotation_edit_input(void)
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

void medal_skill_load_gfx(void)
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

void medal_skill_wait_fade(void)
{
    sub_080093F8();
    sub_0800A180();
    sub_0800B130();
    if (update_blend_effect())
        gGameSubState++;
}

void medal_skill_handle_input(void)
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

void medal_skill_start_fade_out(void)
{
    set_blend_effect_mode(6, 0x3F, 0x20);
    sub_080093F8();
    sub_0800A180();
    sub_0800B130();
    gGameSubState++;
}

// guess: debug skill level editor (sub-state 64; UP/DOWN pick a skill, RIGHT/LEFT change its level, SELECT, B -> 58)
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

void medals_help_load(void)
{
    sub_080093F8();
    clear_sprite_table_mask(1, 5);
    CpuFastSet(gUnk_084E2E78, (void *)0x050003C0, 8);
    sub_0800AA1C();
    sub_0803FB0C();
    gGameSubState++;
}

void medals_help_show_intro(void)
{
    sub_080093F8();
    if (run_message(gUnk_083B53F8[5]))
        gGameSubState++;
}

void medals_help_cursor_input(void)
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

void medals_help_show_text(void)
{
    u8 done;

    sub_080093F8();
    switch (gUnk_03000440.unk42)
    {
    case 0:
        switch (gUnk_03000440.unk44)
        {
        case 0:
            done = run_message(gUnk_083B53F8[6]);
            break;
        case 1:
            done = run_message(gUnk_083B53F8[7]);
            break;
        case 2:
            done = run_message(gUnk_083B69C8[gUnk_03000BE0[gUnk_03000440.unk3D].unk4]);
            break;
        case 3:
            done = run_message(gUnk_083B70AC[gUnk_03000BE0[gUnk_03000440.unk3D].unk6]);
            break;
        case 4:
            done = run_message(gUnk_083B53F8[8]);
            break;
        }
        break;
    case 1:
        switch (gUnk_03000440.unk44)
        {
        case 0:
            if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 > 9)
            {
                memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE, 3);
                memcpy_bytes_08041D04(gUnk_083B7CD4 + gUnk_03000440.unkEE * 6, gUnk_03000440.unk10E, 6);
                done = run_message(gUnk_083B7F40[gUnk_03000440.unk10E[5]]);
            }
            else
            {
                done = run_message(gUnk_083B7F40[4]);
            }
            break;
        case 1:
            if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 > 29)
            {
                memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE, 3);
                memcpy_bytes_08041D04(gUnk_083B7CD4 + gUnk_03000440.unkEF * 6, gUnk_03000440.unk10E, 6);
                done = run_message(gUnk_083B7F40[gUnk_03000440.unk10E[5]]);
            }
            else
            {
                done = run_message(gUnk_083B7F40[4]);
            }
            break;
        case 2:
            if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 > 59)
            {
                memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE, 3);
                memcpy_bytes_08041D04(gUnk_083B7CD4 + gUnk_03000440.unkF0 * 6, gUnk_03000440.unk10E, 6);
                done = run_message(gUnk_083B7F40[gUnk_03000440.unk10E[5]]);
            }
            else
            {
                done = run_message(gUnk_083B7F40[4]);
            }
            break;
        case 3:
            done = run_message(gUnk_083B53F8[9]);
            break;
        case 4:
            done = run_message(gUnk_083B53F8[10]);
            break;
        case 5:
            switch (gUnk_03000440.unk46)
            {
            case 0:
                if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 > 9)
                {
                    memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE, 3);
                    memcpy_bytes_08041D04(gUnk_083B7CD4 + (&gUnk_03000440.unkEE)[gUnk_03000440.unk46] * 6, gUnk_03000440.unk10E, 6);
                    done = run_message(gUnk_083B8170[gUnk_03000440.unk10E[1]]);
                }
                else
                {
                    done = run_message(gUnk_083B53F8[11]);
                }
                break;
            case 1:
                if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 > 29)
                {
                    memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE, 3);
                    memcpy_bytes_08041D04(gUnk_083B7CD4 + (&gUnk_03000440.unkEE)[gUnk_03000440.unk46] * 6, gUnk_03000440.unk10E, 6);
                    done = run_message(gUnk_083B8170[gUnk_03000440.unk10E[1]]);
                }
                else
                {
                    done = run_message(gUnk_083B53F8[11]);
                }
                break;
            case 2:
                if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 > 59)
                {
                    memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE, 3);
                    memcpy_bytes_08041D04(gUnk_083B7CD4 + (&gUnk_03000440.unkEE)[gUnk_03000440.unk46] * 6, gUnk_03000440.unk10E, 6);
                    done = run_message(gUnk_083B8170[gUnk_03000440.unk10E[1]]);
                }
                else
                {
                    done = run_message(gUnk_083B53F8[11]);
                }
                break;
            }
            break;
        }
        break;
    case 2:
        switch (gUnk_03000440.unk44)
        {
        case 0:
            done = run_message(gUnk_083B53F8[13]);
            break;
        case 1:
            done = run_message(gUnk_083B53F8[14]);
            break;
        }
        break;
    }
    if (done)
    {
        sub_0803FB0C();
        gGameSubState = 0x49;
    }
}

void medals_help_exit(void)
{
    sub_080093F8();
    clear_sprite_table_mask(6, 1);
    CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
    switch (gUnk_03000440.unk42)
    {
    case 0:
        sub_0803FB0C();
        sub_0800A0FC();
        gGameSubState = 0xB;
        break;
    case 1:
        sub_0803FB0C();
        sub_0800A0FC();
        sub_0800A854();
        gGameSubState = 0x1B;
        break;
    case 2:
        if (gUnk_03000440.unk46 & 0x80)
        {
            gUnk_03000440.unk46 &= 0x7F;
            gGameSubState = 0x30;
        }
        else
        {
            sub_0803FB0C();
            sub_0800A0FC();
            gGameSubState = 0x2B;
        }
        break;
    }
}

// Medals screen sub-states 96-107 (not reached at runtime yet; guess: Medal confirm / transfer dialog)
void sub_08009174(void)
{
    sub_080093F8();
    update_battle_sprite_visibility();
    gUnk_03002C30[1].unk0 &= 0xBFFF;
    gUnk_03002C30[2].unk0 &= 0xBFFF;
    set_tilemap_and_decompress_bg(0x12, 0xC, gUnk_084889F8, REG_BG0CNT, 0x350);
    gUnk_03000440.unk4A = 0;
    init_battle_cursor_sprite_0800B668();
    gGameSubState++;
}

void sub_080091E0(void)
{
    sub_080093F8();
    update_battle_sprite_visibility();
    sub_08041C14(7, gFrameCounter, 0xA8);
    handle_menu_cursor_updown();
    if (KEYS_LO(gNewKeys) & 1)
    {
        play_sound_effect(4);
    }
    else if (KEYS_LO(gNewKeys) & 2)
    {
        play_sound_effect(5);
        gUnk_03000440.unk4A = 2;
    }
    else
    {
        return;
    }
    init_battle_cursor_sprite_0800B668();
    gGameSubState++;
}

void sub_08009248(void)
{
    sub_080093F8();
    update_battle_sprite_visibility();
    if (update_battle_sprite_and_check_done())
    {
        clear_sprite_table_mask(7, 1);
        gGameSubState++;
    }
}

void sub_08009274(void)
{
    sub_080093F8();
    update_battle_sprite_visibility();
    switch (gUnk_03000440.unk4A)
    {
    case 0:
        gUnk_03000440.unk42 = gUnk_03000440.unk4A;
        set_blend_effect_mode(6, 0x3F, 0x20);
        gGameSubState = 7;
        break;
    case 1:
        gGameSubState++;
        break;
    case 2:
        gGameSubState = gUnk_03000440.unk4A;
        break;
    }
}

void sub_080092D4(void)
{
    u32 bit;

    sub_080093F8();
    update_battle_sprite_visibility();
    if (gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x40)
    {
        text_window_init(1, 2, 0);
        gUnk_03000440.unk84 = 9;
        gGameSubState++;
    }
    else if ((bit = (1 << gUnk_03000BE0[gUnk_03000440.unk3D].unk1) & gUnk_03002B68))
    {
        text_window_init(1, 2, 0);
        gUnk_03000440.unk84 = 8;
        gGameSubState++;
    }
    else
    {
        clear_battle_sprite_slot(5, 1);
        sound_stop_all_with_fade_guard(8);
        gUnk_03000440.unk3E = bit;
        gGameSubState = 0x68;
    }
}

void sub_08009374(void)
{
    sub_080093F8();
    update_battle_sprite_visibility();
    if (run_message(gUnk_083CF3B0[gUnk_03000440.unk84]))
        gGameSubState = 2;
}

void sub_080093AC(void)
{
    memcpy_bytes_0803F63C(&gUnk_03000BE0[gUnk_03000440.unk3D], (void *)0x02023000, 0x40);
    gGameSubState++;
}

void sub_080093E0(void)
{
    clear_battle_sprite_slot(0, 0x80);
    sub_08043CA8();
    sub_08044CDC(1);
}

void sub_080093F8(void)
{
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_0800941C(void)
{
    gUnk_03000440.unk3F = gUnk_03000440.unk3D / 6;
    gUnk_03000440.unk40 = gUnk_03000440.unk3D % 6;
}

void sub_0800944C(void)
{
    u32 i;

    gUnk_03000440.unk41 = 0;
    for (i = 0; i < 30; i++)
    {
        if (gUnk_03000BE0[i].unk0 & 0x80)
            gUnk_03000440.unk41++;
    }
}

void render_medal_sprite_tile(void)
{
    u8 n = 0;
    u8 i;

    for (i = gUnk_03000440.unk3F * 6; i < gUnk_03000440.unk3F * 6 + 6; n++, i++)
    {
        if (gUnk_03000BE0[i].unk0 & 0x80)
            CpuFastSet(gUnk_084C21BC + gUnk_03000BE0[i].unk1 * 0x80, (void *)0x06006600 + n * 0x80, 0x20);
        else
            CpuFastSet(gUnk_084C30BC, (void *)0x06006600 + n * 0x80, 0x20);
    }
    write_tilemap_rect(2, 12, 4, 4, gUnk_083B4AE0[0x50], REG_BG1CNT, 0x200);
}

void render_medal_list_entries(void)
{
    u8 n = 0;
    u8 i;

    clear_sprite_table_mask(10, 0x3C);
    for (i = gUnk_03000440.unk3F * 6; i < gUnk_03000440.unk3F * 6 + 6; n++, i++)
    {
        if (gUnk_03000BE0[i].unk0 & 0x80)
        {
            memcpy_bytes_0803F63C((void *)gUnk_083B6410[gUnk_03000BE0[i].unk1], gUnk_03000440.unk9E, 11);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, n * 10 + 10, 6, n * 2 + 4, 7, 8, 1, 2);
        }
        else
        {
            fill_text_blank(gUnk_03000440.unk9E, 9);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, n * 10 + 10, 6, n * 2 + 4, 7, 8, 1, 2);
        }
    }
}

void render_medal_slots_in_menu(void)
{
    u32 i;
    u32 n;

    for (n = 0, i = gUnk_03000440.unk3F * 6; i < gUnk_03000440.unk3F * 6 + 6; n++, i++)
    {
        if (gUnk_03000BE0[i].unk0 & 0x80)
        {
            fill_tilemap_pair_or_divide(gUnk_03000BE0[i].unk5, 14, (u8)(n * 2 + 4), REG_BG1CNT, 0xD314);
        }
        else
        {
            fill_tilemap_rect_08042698(1, 2, 14, n * 2 + 4, REG_BG1CNT, 0xD32C);
            fill_tilemap_rect_08042698(1, 2, 15, n * 2 + 4, REG_BG1CNT, 0xD32C);
        }
    }
}

void render_medal_name_display(void)
{
    u8 has;

    gUnk_03000440.unk3D = gUnk_03000440.unk3F * 6 + gUnk_03000440.unk40;
    clear_sprite_table_mask(0x46, 10);
    if ((has = gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x80))
    {
        render_text_sprites_08040DB8(gUnk_03000BE0[gUnk_03000440.unk3D].unkA, 0x46, 0x13, 3, 10, 9, 0, 2);
    }
    else
    {
        fill_text_blank(gUnk_03000440.unk9E, 10);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x46, 0x13, 3, 10, 9, has, 2);
    }
}

void load_medal_sprite(void)
{
    gUnk_03000440.unk3D = gUnk_03000440.unk3F * 6 + gUnk_03000440.unk40;
    if (gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x80)
    {
        lz_decompress_dispatch(gUnk_083AC494[gUnk_03000BE0[gUnk_03000440.unk3D].unk1][gUnk_03000BE0[gUnk_03000440.unk3D].unk8], (void *)0x06010000);
        gUnk_03002C30[0].unk0 = 0xC804;
        gUnk_03002C30[0].unk2 = 0xC0;
        gUnk_03002C30[0].unk4 = 0x50;
        gUnk_03002C30[0].unk6 = 0x200;
        gUnk_03002C30[0].unkA = 13;
        gUnk_03002C30[0].unk1C = 0;
        gUnk_03002C30[0].unkB = 0x40;
    }
    else
    {
        clear_sprite_table_mask(0, 1);
    }
}

void render_medal_level_display(void)
{
    u8 *buf;

    gUnk_03000440.unk3D = gUnk_03000440.unk3F * 6 + gUnk_03000440.unk40;
    clear_sprite_table_mask(0x50, 6);
    if (gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x80)
    {
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 != 100)
        {
            buf = gUnk_03000440.unk9E;
            divide_by_100000_08041370(buf, gUnk_03000BE0[gUnk_03000440.unk3D].unk2);
        }
        else
        {
            buf = gUnk_03000440.unk9E;
            fill_text_blank(buf, 5);
        }
        render_text_sprites_08040DB8(buf, 0x50, 0x13, 0x11, 6, 10, 2, 2);
    }
    else
    {
        buf = gUnk_03000440.unk9E;
        fill_text_blank(buf, 5);
        render_text_sprites_08040DB8(buf, 0x50, 0x13, 0x11, 6, 10, 2, 2);
    }
}

void sub_0800988C(void)
{
    gUnk_03002C30[1].unk0 = 0xC804;
    gUnk_03002C30[1].unk2 = 0x24;
    gUnk_03002C30[1].unk4 = 0x18;
    gUnk_03002C30[1].unk6 = 0x302;
    gUnk_03002C30[1].unkA = 14;
    gUnk_03002C30[1].unk1C = 0;
    gUnk_03002C30[1].unkB = 0x40;
    gUnk_03002C30[2].unk0 = 0xC804;
    gUnk_03002C30[2].unk2 = 0x7C;
    gUnk_03002C30[2].unk4 = 0x18;
    gUnk_03002C30[2].unk6 = 0x303;
    gUnk_03002C30[2].unkA = 14;
    gUnk_03002C30[2].unk1C = 0;
    gUnk_03002C30[2].unkB = 0x40;
}

void sub_08009900(void)
{
    gUnk_03002C30[3].unk0 = 0xC804;
    gUnk_03002C30[3].unk2 = 0x18;
    gUnk_03002C30[3].unk4 = gUnk_03000440.unk40 * 16 + 0x28;
    gUnk_03002C30[3].unk6 = 0x307;
    gUnk_03002C30[3].unkA = 14;
    gUnk_03002C30[3].unk1C = 0;
    gUnk_03002C30[3].unkB = 0x41;
}

void sub_0800994C(void)
{
    if (gFrameCounter & 8)
    {
        gUnk_03002C30[1].unk0 &= 0xBFFF;
        gUnk_03002C30[2].unk0 &= 0xBFFF;
    }
    else
    {
        gUnk_03002C30[1].unk0 |= 0x4000;
        gUnk_03002C30[2].unk0 |= 0x4000;
    }
}

void sub_080099A4(void)
{
    if (KEYS_LO(gRepeatKeys) & 0x40)
    {
        if (gUnk_03000440.unk40 == 0)
            gUnk_03000440.unk40 = 5;
        else
            gUnk_03000440.unk40--;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80)
    {
        if (gUnk_03000440.unk40 == 5)
            gUnk_03000440.unk40 = 0;
        else
            gUnk_03000440.unk40++;
    }
    if (KEYS_LO(gRepeatKeys) & 0xC0)
    {
        play_sound_effect(2);
        gUnk_03002C30[3].unk4 = gUnk_03000440.unk40 * 16 + 0x28;
        render_medal_name_display();
        load_medal_sprite();
        render_medal_level_display();
        decompress_active_medal_sprite();
        init_active_medal_battle_sprites();
        draw_medal_position_tile();
    }
}

void sub_08009A38(void)
{
    if (KEYS_LO(gRepeatKeys) & 0x20)
    {
        if (gUnk_03000440.unk3F == 0)
            gUnk_03000440.unk3F = 4;
        else
            gUnk_03000440.unk3F--;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10)
    {
        if (gUnk_03000440.unk3F == 4)
            gUnk_03000440.unk3F = 0;
        else
            gUnk_03000440.unk3F++;
    }
    if (KEYS_LO(gRepeatKeys) & 0x30)
    {
        play_sound_effect(2);
        write_tilemap_rect(10, 2, 5, 2, gUnk_083B4AE0[gUnk_03000440.unk3F + 0x4B], REG_BG1CNT, 0x200);
        render_medal_sprite_tile();
        render_medal_list_entries();
        render_medal_slots_in_menu();
        render_medal_name_display();
        load_medal_sprite();
        render_medal_level_display();
        decompress_active_medal_sprite();
        init_active_medal_battle_sprites();
        draw_medal_position_tile();
    }
}

INCLUDE_ASM("asm/nonmatching/code_08008430", update_battle_sprite_visibility);

void sub_08009BC8(void)
{
    u32 cur;

    if (KEYS_LO(gNewKeys) & 4)
    {
        play_sound_effect(2);
        if (gUnk_03000440.unk3E & 0x80)
        {
            gUnk_03000440.unk3E &= 0x7F;
            if (gUnk_03000440.unk3E != (cur = gUnk_03000440.unk3F * 6 + gUnk_03000440.unk40))
            {
                memswap(&gUnk_03000BE0[gUnk_03000440.unk3E], &gUnk_03000BE0[cur], 0x40);
                write_tilemap_rect(10, 2, 5, 2, gUnk_083B4AE0[gUnk_03000440.unk3F + 0x4B], REG_BG1CNT, 0x200);
                render_medal_sprite_tile();
                render_medal_list_entries();
                render_medal_slots_in_menu();
                render_medal_name_display();
                load_medal_sprite();
                render_medal_level_display();
                decompress_active_medal_sprite();
                init_active_medal_battle_sprites();
                draw_medal_position_tile();
            }
            gUnk_03000440.unk3E = 0;
            update_battle_sprite_visibility();
        }
        else
        {
            gUnk_03000440.unk3E = gUnk_03000440.unk3F * 6 + gUnk_03000440.unk40 + 0x80;
            update_battle_sprite_visibility();
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_08008430", get_medal_active_slot);
INCLUDE_ASM("asm/nonmatching/code_08008430", decompress_active_medal_sprite);
INCLUDE_ASM("asm/nonmatching/code_08008430", init_active_medal_battle_sprites);
INCLUDE_ASM("asm/nonmatching/code_08008430", draw_medal_position_tile);

void sub_08009E4C(void)
{
    CpuFastSet(gUnk_084C21BC + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 0x80, (void *)0x06006600, 0x20);
    fill_tilemap_rect_08042698(2, 2, 2, 3, REG_BG1CNT, 0x6330);
}

void sub_08009EA0(void)
{
    CpuFastSet(gUnk_084C21BC + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 0x80, (void *)0x06007800, 0x20);
    fill_tilemap_rect_08042698(2, 2, 2, 3, REG_BG1CNT, 0x63C0);
}

void sub_08009EF4(void)
{
    clear_sprite_table_mask(10, 10);
    memcpy_bytes_0803F63C((void *)gUnk_083B6410[gUnk_03000BE0[gUnk_03000440.unk3D].unk1], gUnk_03000440.unk9E, 11);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 10, 4, 3, 7, 13, 1, 1);
}

void sub_08009F50(void)
{
    clear_sprite_table_mask(0x14, 10);
    render_text_sprites_08040DB8(gUnk_03000BE0[gUnk_03000440.unk3D].unkA, 0x14, 0x12, 3, 10, 12, 0, 1);
}

void sub_08009F90(void)
{
    fill_tilemap_pair_or_divide(gUnk_03000BE0[gUnk_03000440.unk3D].unk5, 12, 3, REG_BG1CNT, 0xC314);
}

void sub_08009FC8(void)
{
    fill_tilemap_pair_or_divide(gUnk_03000BE0[gUnk_03000440.unk3D].unk5, 12, 3, REG_BG1CNT, 0xC3A4);
}

void sub_0800A000(void)
{
    clear_sprite_table_mask(0x1E, 15);
    memcpy_bytes_0803F63C((void *)gUnk_083B656C[gUnk_03000BE0[gUnk_03000440.unk3D].unk4], gUnk_03000440.unk9E, 14);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x1E, 10, 7, 8, 11, 1, 1);
}

void sub_0800A05C(void)
{
    clear_sprite_table_mask(0x2D, 13);
    memcpy_bytes_0803F63C((void *)gUnk_083B6EC8[gUnk_03000BE0[gUnk_03000440.unk3D].unk6], gUnk_03000440.unk9E, 14);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x2D, 10, 10, 10, 10, 1, 1);
}

void sub_0800A0B8(void)
{
    fill_tilemap_rect_08042698(2, 2, 0x1B, 7, REG_BG1CNT, gUnk_03000BE0[gUnk_03000440.unk3D].unk7 * 4 + 0xD340);
}

void sub_0800A0FC(void)
{
    if (gUnk_03000440.unk41 > 1)
    {
        gUnk_03002C30[1].unk0 = 0xC804;
        gUnk_03002C30[1].unk2 = 4;
        gUnk_03002C30[1].unk4 = 0x20;
        gUnk_03002C30[1].unk6 = 0x302;
        gUnk_03002C30[1].unkA = 14;
        gUnk_03002C30[1].unk1C = 0;
        gUnk_03002C30[1].unkB = 0x40;
        gUnk_03002C30[2].unk0 = 0xC804;
        gUnk_03002C30[2].unk2 = 0x7C;
        gUnk_03002C30[2].unk4 = 0x20;
        gUnk_03002C30[2].unk6 = 0x303;
        gUnk_03002C30[2].unkA = 14;
        gUnk_03002C30[2].unk1C = 0;
        gUnk_03002C30[2].unkB = 0x40;
    }
}

void sub_0800A180(void)
{
    if (gUnk_03000440.unk41 > 1)
    {
        if (gFrameCounter & 8)
        {
            gUnk_03002C30[1].unk0 &= 0xBFFF;
            gUnk_03002C30[2].unk0 &= 0xBFFF;
        }
        else
        {
            gUnk_03002C30[1].unk0 |= 0x4000;
            gUnk_03002C30[2].unk0 |= 0x4000;
        }
    }
}

void sub_0800A1E4(void)
{
    u32 found;

    if (gUnk_03000440.unk41 > 1)
    {
        if (KEYS_LO(gRepeatKeys) & 0x20)
        {
            play_sound_effect(2);
            found = 0;
            do
            {
                if (gUnk_03000440.unk3D == 0)
                    gUnk_03000440.unk3D = 29;
                else
                    gUnk_03000440.unk3D--;
                if (gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x80)
                {
                    if (gUnk_03000440.unk3C != 1)
                        found = 1;
                    else if (!(gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x40))
                        found = 1;
                }
            } while (!found);
        }
        if (KEYS_LO(gRepeatKeys) & 0x10)
        {
            play_sound_effect(2);
            found = 0;
            do
            {
                if (gUnk_03000440.unk3D == 29)
                    gUnk_03000440.unk3D = 0;
                else
                    gUnk_03000440.unk3D++;
                if (gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x80)
                {
                    if (gUnk_03000440.unk3C != 1)
                        found = 1;
                    else if (!(gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x40))
                        found = 1;
                }
            } while (!found);
        }
    }
}

void sub_0800A2B4(void)
{
    if (KEYS_LO(gRepeatKeys) & 0x30)
    {
        sub_08009E4C();
        sub_08009EF4();
        sub_08009F50();
        sub_08009F90();
        sub_0800A000();
        sub_0800A05C();
        sub_0800A0B8();
    }
}

INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800A2E8);
INCLUDE_ASM("asm/nonmatching/code_08008430", sub_0800A594);

void sub_0800A854(void)
{
    gUnk_03002C30[3].unk0 = 0xC804;
    gUnk_03002C30[3].unk2 = 8;
    gUnk_03002C30[3].unk4 = gUnk_03000440.unk46 * 16 + 0x38;
    gUnk_03002C30[3].unk6 = 0x307;
    gUnk_03002C30[3].unkA = 14;
    gUnk_03002C30[3].unk1C = 0;
    gUnk_03002C30[3].unkB = 0x41;
}

u32 sub_0800A8A0(void)
{
    if (KEYS_LO(gRepeatKeys) & 0x40)
    {
        if (gUnk_03000440.unk46 == 0)
            gUnk_03000440.unk46 = 2;
        else
            gUnk_03000440.unk46--;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80)
    {
        if (gUnk_03000440.unk46 == 2)
            gUnk_03000440.unk46 = 0;
        else
            gUnk_03000440.unk46++;
    }
    if (KEYS_LO(gRepeatKeys) & 0xC0)
    {
        play_sound_effect(2);
        gUnk_03002C30[3].unk4 = gUnk_03000440.unk46 * 16 + 0x38;
        sub_0800A594();
        return 1;
    }
    return 0;
}

u32 sub_0800A928(void)
{
    if (KEYS_LO(gRepeatKeys) & 0x30)
    {
        sub_08009E4C();
        sub_08009EF4();
        sub_08009F50();
        sub_08009F90();
        sub_0800A2E8();
        sub_0800A594();
        return 1;
    }
    return 0;
}

u32 sub_0800A960(void)
{
    switch (gUnk_03000440.unk46)
    {
    default:
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 >= 60)
            goto slot2;
    none:
        return 0x34;
    case 0:
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 < 10)
            goto none;
        memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE, 3);
        return gUnk_03000440.unkEE;
    case 1:
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk5 < 30)
            goto none;
        memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE, 3);
        return gUnk_03000440.unkEF;
    }
slot2:
    memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000BE0[gUnk_03000440.unk3D].unk1 * 3, &gUnk_03000440.unkEE, 3);
    return gUnk_03000440.unkF0;
}

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
