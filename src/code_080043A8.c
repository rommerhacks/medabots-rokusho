#include "global.h"

// Game state 3, sub-states 16-26: the Medabot detail ("Build") screen, runtime-checked from the
// Medabots list (A). 18 = input: B back to the list (19-21), L/R switch Medabot, A on a row opens
// its Medal (game state 4) or Medapart (game state 5) info screen (24-26).
// 32-35 / 40-43 leave for a battle / race, 48-60 exchange the team over the link (not checked).
void medabot_detail_fade_in(void)
{
    struct Unk_03000440 *st;
    u8 *done;
    u8 *frame;

    medabots_scroll_bg3();
    sub_08006764();
    medabot_detail_blink_row_arrows();
    medabot_detail_blink_row_icon();
    battle_update_medabot_display();
    sub_08006F14();
    st = &gUnk_03000440;
    done = &st->unk56;
    if (*done == 0)
    {
        frame = &st->unk84;
        if (*frame > 8)
            goto finish;
        blend_obj_palettes_to_color_0803F684(0, 32 - *frame * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - *frame * 4, 0xF0FF);
        (*frame)++;
    }
    else if (update_blend_effect())
    {
    finish:
        *done = 1;
        gGameSubState++;
    }
}

void medabot_detail_handle_input(void)
{
    u8 r;

    medabots_scroll_bg3();
    sub_08006764();
    medabot_detail_blink_row_arrows();
    medabot_detail_blink_row_icon();
    battle_update_medabot_display();
    sub_08006F14();
    if (medabot_detail_row_cursor_input() || medabot_detail_cycle_medal_input() || medabot_detail_cycle_head_input() || medabot_detail_cycle_rarm_input() || medabot_detail_cycle_larm_input() || medabot_detail_cycle_legs_input()
        || medabot_detail_equip_full_set_input())
        return;
    if (KEYS_LO(gNewKeys) & 2)
    {
        play_sound_effect(5);
        gGameSubState++;
    }
    else if (*((u8 *)&gNewKeys + 1) & 3)
    {
        play_sound_effect(2);
        gUnk_03000440.unk5E ^= 1;
        setup_scene_with_link_check();
        setup_battle_sprite_from_game_state();
    }
    else
    {
        r = medabot_detail_check_row_select();
        if (r == 2)
            play_sound_effect(6);
        else if (r == 1)
        {
            play_sound_effect(4);
            gGameSubState = 24;
        }
    }
}

void medabot_detail_exit_start(void)
{
    struct Unk_03000440 *st;
    u8 v;

    medabots_scroll_bg3();
    sub_08006764();
    medabot_detail_blink_row_arrows();
    medabot_detail_blink_row_icon();
    battle_update_medabot_display();
    sub_08006F14();
    st = &gUnk_03000440;
    v = st->unk50;
    if (v == 0)
    {
        copy_obj_palette_to_buffer();
        st->unk84 = v;
    }
    else
        set_blend_effect_mode(6, 0x3F, 0x20);
    gGameSubState++;
}

void medabot_detail_exit_fade(void)
{
    u8 *frame;

    medabots_scroll_bg3();
    sub_08006764();
    medabot_detail_blink_row_arrows();
    medabot_detail_blink_row_icon();
    battle_update_medabot_display();
    sub_08006F14();
    if (gUnk_03000440.unk50 == 0)
    {
        frame = &gUnk_03000440.unk84;
        if (*frame > 8)
            goto finish;
        blend_obj_palettes_to_color_0803F684(0, *frame * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, *frame * 4, 0xF0FF);
        (*frame)++;
    }
    else if (update_blend_effect())
    {
    finish:
        gGameSubState++;
    }
}

void medabot_detail_return_to_list(void)
{
    sub_08006764();
    assign_medal_to_team_slot();
    gGameSubState = 0;
}

void medabot_detail_open_info_start(void)
{
    medabots_scroll_bg3();
    sub_08006764();
    medabot_detail_blink_row_arrows();
    medabot_detail_blink_row_icon();
    battle_update_medabot_display();
    sub_08006F14();
    set_blend_effect_mode(6, 0x3F, 0x20);
    gGameSubState++;
}

void medabot_detail_open_info_fade(void)
{
    medabots_scroll_bg3();
    sub_08006764();
    medabot_detail_blink_row_arrows();
    medabot_detail_blink_row_icon();
    battle_update_medabot_display();
    sub_08006F14();
    if (update_blend_effect())
        gGameSubState++;
}

void medabot_detail_open_info(void)
{
    clear_battle_sprite_slot(0, 0x80);
    gUnk_03000440.unk96 = 0;
    gUnk_03000430 = 0;
    switch (gUnk_03000440.unk5A)
    {
    case 0:
        sub_0803F624(&gUnk_03000440.unk3C, 0x14, 0);
        gUnk_03000440.unk3C = 1;
        gUnk_03000440.unk3D = gUnk_03000440.unk97;
        count_unequipped_medals();
        gGameState = 4;
        gGameSubState = 8;
        break;
    case 1:
        sub_0803F624(&gUnk_03000440.unk3C, 0x14, 0);
        gUnk_03000440.unk3C = 1;
        gUnk_03000440.unk3D = gUnk_03000440.unk98;
        gUnk_03000440.unk3E = 0;
        gGameState = 5;
        gGameSubState = 16;
        break;
    case 2:
        sub_0803F624(&gUnk_03000440.unk3C, 0x14, 0);
        gUnk_03000440.unk3C = 1;
        gUnk_03000440.unk3D = gUnk_03000440.unk99;
        gUnk_03000440.unk3E = 1;
        gGameState = 5;
        gGameSubState = 16;
        break;
    case 3:
        sub_0803F624(&gUnk_03000440.unk3C, 0x14, 0);
        gUnk_03000440.unk3C = 1;
        gUnk_03000440.unk3D = gUnk_03000440.unk9A;
        gUnk_03000440.unk3E = 2;
        gGameState = 5;
        gGameSubState = 16;
        break;
    case 4:
        sub_0803F624(&gUnk_03000440.unk3C, 0x14, 0);
        gUnk_03000440.unk3C = 1;
        gUnk_03000440.unk3D = gUnk_03000440.unk9B;
        gUnk_03000440.unk3E = 3;
        gGameState = 5;
        gGameSubState = 16;
        break;
    }
}

void sub_08004764(void)
{
    medabots_scroll_bg3();
    sub_08005000();
    setup_overworld_scene_from_position();
    clear_sprite_table_mask(0, 4);
    gUnk_03000440.unk5C = 0;
    gGameSubState++;
}

void sub_08004798(void)
{
    medabots_scroll_bg3();
    setup_overworld_scene_from_position();
    sub_08007480();
    if (gUnk_03000440.unk5C > 60)
    {
        if (gUnk_03000440.unk50 == 1)
            gGameSubState = 48;
        else
        {
            copy_obj_palette_to_buffer();
            gUnk_03000440.unk84 = 0;
            gGameSubState++;
        }
    }
}

void sub_080047EC(void)
{
    struct Unk_03000440 *st;
    u8 *frame;

    medabots_scroll_bg3();
    setup_overworld_scene_from_position();
    sub_08007480();
    st = &gUnk_03000440;
    frame = &st->unk84;
    if (*frame <= 32)
    {
        blend_obj_palettes_to_color_0803F684(0, *frame, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, *frame, 0xFFFF);
        (*frame)++;
    }
    else
        gGameSubState++;
}

void team_select_exit_battle(void)
{
    clear_battle_sprite_slot(0, 0x80);
    gUnk_03000440.unk96 = 0;
    gUnk_03000430 = 0;
    gGameState = 7;
    gGameSubState = 0;
}

void sub_08004874(void)
{
    medabots_scroll_bg3();
    setup_overworld_scene_from_position();
    sub_08007480();
    if (gUnk_03000440.unk5C > 60)
    {
        sound_stop_all_with_fade_guard(8);
        set_blend_effect_mode(6, 0x3F, 8);
        gGameSubState++;
    }
}

void sub_080048B0(void)
{
    medabots_scroll_bg3();
    setup_overworld_scene_from_position();
    sub_08007480();
    if (update_blend_effect())
        gGameSubState++;
}

void team_select_exit_race(void)
{
    s32 i;

    clear_battle_sprite_slot(0, 0x80);
    gUnk_03000440.unk96 = 0;
    gUnk_03000430 = 0;
    for (i = 0; i <= 2; i++)
    {
        load_part_data(gUnk_030017A0[gUnk_03001800.unk41[i] & 0xF].unk6, 3, &gUnk_03000440.unkEE);
        gUnk_03001800.unk8C[i] = gUnk_03000440.unkEF - 100;
        gUnk_03001800.unk8F[i][0] = gUnk_030017A0[gUnk_03001800.unk41[i] & 0xF].unk3;
        gUnk_03001800.unk8F[i][1] = gUnk_030017A0[gUnk_03001800.unk41[i] & 0xF].unk4;
        gUnk_03001800.unk8F[i][2] = gUnk_030017A0[gUnk_03001800.unk41[i] & 0xF].unk5;
        gUnk_03001800.unk8F[i][3] = gUnk_030017A0[gUnk_03001800.unk41[i] & 0xF].unk6;
    }
    gGameMode = 3;
    gGameState = 4;
    gGameSubState = 5;
}

void sub_080049C8(void)
{
    medabots_scroll_bg3();
    setup_overworld_scene_from_position();
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void sub_080049EC(void)
{
    medabots_scroll_bg3();
    setup_overworld_scene_from_position();
    if (run_message(gUnk_083CF3B0[11]))
        gGameSubState++;
}

void sub_08004A18(void)
{
    medabots_scroll_bg3();
    setup_overworld_scene_from_position();
    clear_battle_bot_array();
    count_active_battle_bots();
    battle_setup_team_bots();
    gGameSubState++;
}

void sub_08004A40(void)
{
    medabots_scroll_bg3();
    setup_overworld_scene_from_position();
    if (sub_0803E79C())
    {
        gUnk_03005010.unk6 = 0;
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
}

void sub_08004A78(void)
{
    struct Unk_03000440 *st;
    u16 *timer;

    medabots_scroll_bg3();
    setup_overworld_scene_from_position();
    st = &gUnk_03000440;
    timer = &st->unk86;
    if (*timer == 24)
    {
        gUnk_03001800.unk51 = 0;
        gUnk_03001800.unk52 = 0;
        gUnk_03001800.unk53 = 0;
        gUnk_03001800.unk54 = 0;
        gUnk_03001800.unk1A6 = 0;
        gUnk_03001800.unk1A8 = 0;
        gUnk_03001800.unk1AA = 0;
        gUnk_03001800.unk1AC = 0;
        gUnk_03001800.unk1AF = 0;
        gUnk_03001800.unk1B0 = 1;
        *timer = 0;
        gGameSubState++;
    }
    else
        (*timer)++;
}

// guess: sends 3 x 0x48 bytes from gUnk_03000590 and receives into gUnk_03000890 over the link, one
// byte per packet (bit 15 = valid, bit 8 = toggle), summing the received bytes in unk1A8. Near miss:
// scratch/sub_08004AF8_nearmiss.c (one literal load order and an orrs/adds for the 0x8000 header).

void sub_08004AF8(void)
{
    struct Unk_03001800 *s;
    s16 flag;
    u8 *src;

    medabots_scroll_bg3();
    setup_overworld_scene_from_position();
    s = &gUnk_03001800;
    if (s->unk51 != 3)
    {
        src = (u8 *)&gUnk_03000590[s->unk51];
        gUnk_03005010.unk6 = src[s->unk52] + (flag = ((s->unk1AF << 8) & 0x100) + 0x8000);
        if (++gUnk_03000440.unk86 == 4)
        {
            gUnk_03000440.unk86 = 0;
            s->unk1AF ^= 1;
            if (++s->unk52 == 0x48)
            {
                s->unk51++;
                s->unk52 = 0;
            }
        }
    }
    if (gUnk_03001800.unk53 != 3)
    {
        u16 v = gUnk_03005010.unk8[gUnk_03000B90 ^ 1][1];

        if ((v & 0x8000) && (u16)(v & 0x100) >> 8 != gUnk_03001800.unk1B0)
        {
            gUnk_03001800.unk1B0 ^= 1;
            ((struct LinkRow256 *)gUnk_03000890)[gUnk_03001800.unk53].b[gUnk_03001800.unk54] = v;
            gUnk_03001800.unk1A8 = (gUnk_03001800.unk1A8 + (v & 0xFF)) & 0x7FFF;
            if (++gUnk_03001800.unk54 == 0x48)
            {
                gUnk_03001800.unk53++;
                gUnk_03001800.unk54 = 0;
            }
        }
    }
    if (gUnk_03001800.unk51 == 3)
        if (gUnk_03001800.unk53 == 3)
        {
            gGameSubState = 58;
            gUnk_03000440.unk86 = 0;
        }
}

void sub_08004C58(void)
{
    struct Unk_03000440 *st;
    u16 *timer;

    medabots_scroll_bg3();
    setup_overworld_scene_from_position();
    st = &gUnk_03000440;
    timer = &st->unk86;
    if (*timer == 16)
    {
        gUnk_03001800.unk51 = 0;
        gUnk_03001800.unk52 = 0;
        gUnk_03001800.unk53 = 0;
        gUnk_03001800.unk54 = 0;
        *timer = 0;
        gGameSubState++;
    }
    else
        (*timer)++;
}

void sub_08004CA4(void)
{
    u16 v;

    medabots_scroll_bg3();
    setup_overworld_scene_from_position();
    if (gUnk_03001800.unk51 < 2)
    {
        switch (gUnk_03001800.unk51)
        {
        case 0:
            gUnk_03005010.unk6 = 0x8000 + gUnk_03001800.unk1A6;
            break;
        case 1:
            gUnk_03005010.unk6 = 0x8000 + gUnk_03001800.unk1A8;
            break;
        }
        gUnk_03001800.unk51++;
    }
    v = gUnk_03005010.unk8[gUnk_03000B90 ^ 1][1];
    if (v & 0x8000)
    {
        switch (gUnk_03001800.unk52)
        {
        case 0:
            gUnk_03001800.unk1AA = v & 0x7FFF;
            break;
        case 1:
            gUnk_03001800.unk1AC = v & 0x7FFF;
            break;
        }
        if (++gUnk_03001800.unk52 == 2)
        {
            if (gUnk_03001800.unk1A6 == gUnk_03001800.unk1AC && gUnk_03001800.unk1A8 == gUnk_03001800.unk1AA)
                gGameSubState++;
            else
                gGameSubState = 50;
        }
    }
}

void sub_08004DB4(void)
{
    gUnk_03005010.unk6 = 0;
    medabots_scroll_bg3();
    setup_overworld_scene_from_position();
    sub_08007540();
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_08004DF0(void)
{
    struct Unk_03000440 *st;
    u8 *frame;

    medabots_scroll_bg3();
    setup_overworld_scene_from_position();
    st = &gUnk_03000440;
    frame = &st->unk84;
    if (*frame <= 32)
    {
        blend_obj_palettes_to_color_0803F684(0, *frame, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, *frame, 0xFFFF);
        (*frame)++;
    }
    else
        gGameSubState++;
}

void sub_08004E40(void)
{
    clear_battle_sprite_slot(0, 0x80);
    gUnk_03000440.unk96 = 0;
    gUnk_03000430 = 0;
    gGameState = 7;
    gGameSubState = 0;
}

void medabots_scroll_bg3(void)
{
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_08004E98(void)
{
    gUnk_03002C30[0].unk0 = 0xC604;
    gUnk_03002C30[0].unk23 = 0;
    update_battle_sprite_orbit_clockwise(0);
    gUnk_03002C30[1].unk0 = 0xC604;
    gUnk_03002C30[1].unk23 = 0x10;
    update_battle_sprite_orbit_clockwise(1);
    gUnk_03002C30[2].unk0 = 0xC604;
    gUnk_03002C30[2].unk23 = 0x20;
    update_battle_sprite_orbit_clockwise(2);
    gUnk_03002C30[3].unk0 = 0xC604;
    gUnk_03002C30[3].unk23 = 0x30;
    update_battle_sprite_orbit_clockwise(3);
}

void update_battle_sprite_orbit_clockwise(u32 i)
{
    u32 cx = gUnk_083AC420[gUnk_03000440.unk51 * 2];
    u32 cy = gUnk_083AC420[gUnk_03000440.unk51 * 2 + 1];
    struct Vec16 p = compute_polar_to_screen_position(((gUnk_03002C30[i].unk23 + 16) & 0x3F) * 4, 16, cx, cy, 8, 0);

    gUnk_03002C30[i].unk2 = p.x;
    gUnk_03002C30[i].unk4 = p.y;
    gUnk_03002C30[i].unk6 = 0x400;
    gUnk_03002C30[i].unkA = 12;
    gUnk_03002C30[i].unk1C = 0;
    gUnk_03002C30[i].unk9 = 0x40 - (cy + 8 - gUnk_03002C30[i].unk4) * 3;
    gUnk_03002C30[i].unk8 = 0x60 - (cy + 8 - gUnk_03002C30[i].unk4) * 3;
    if (cy > gUnk_03002C30[i].unk4)
        gUnk_03002C30[i].unkB = gUnk_083AC432[gUnk_03000440.unk51] - 1;
    else
        gUnk_03002C30[i].unkB = gUnk_083AC432[gUnk_03000440.unk51] + 4;
    gUnk_03002C30[i].unk18 = gUnk_03002C30[i].unk23 << 4;
    gUnk_03002C30[i].unk23 = (gUnk_03002C30[i].unk23 + 1) & 0x3F;
}

void sub_08004FD0(void)
{
    u32 i;
    struct Unk_030017A0 *bot;

    i = 0;
    bot = gUnk_030017A0;
    do
    {
        if (bot->unk0)
            decompress_sprite_to_vram_08042D94(bot->unk3, bot->unk4, bot->unk5, bot->unk6, i);
        bot++;
        i++;
    } while (i <= 8);
}

void sub_08005000(void)
{
    u32 i;

    for (i = 0; i <= 8; i++)
    {
        if (gUnk_030017A0[i].unk0)
            init_battle_medabot_sprites(gUnk_030017A0[i].unk3, gUnk_030017A0[i].unk4, gUnk_030017A0[i].unk5, gUnk_030017A0[i].unk6, i, 10 + i * 4,
                                        gUnk_083AC43B[i * 2], gUnk_083AC43B[i * 2 + 1], gUnk_03000440.unk5E, 1,
                                        gUnk_083AC432[i]);
        else
            clear_sprite_table_mask(10 + i * 4, 4);
    }
}

void sub_0800508C(void)
{
    u32 i;

    for (i = 0; i <= 8; i++)
    {
        if (gUnk_030017A0[i].unk0)
        {
            if (gUnk_030017A0[i].unk6 <= 0x77)
            {
                load_part_data(gUnk_030017A0[i].unk6, 3, &gUnk_03000440.unkEE);
                draw_tilemap_with_offset(gUnk_03000440.unkEF - 100, gUnk_083AC44D[i * 2], gUnk_083AC44D[i * 2 + 1],
                                         REG_BG1CNT, 0x8300);
            }
            else
                draw_tilemap_with_offset(0xFF, gUnk_083AC44D[i * 2], gUnk_083AC44D[i * 2 + 1], REG_BG1CNT, 0x8300);
        }
        else
            draw_tilemap_with_offset(0xFF, gUnk_083AC44D[i * 2], gUnk_083AC44D[i * 2 + 1], REG_BG1CNT, 0x8300);
    }
}

// guess: draws the selected Medabot's Medal name (or blanks).
void sub_08005118(void)
{
    clear_sprite_table_mask(0x32, 10);
    if (gUnk_030017A0[gUnk_03000440.unk51].unk0 > 1)
        render_text_sprites_08040DB8((u8 *)0x03000BAA + find_medal_slot_by_id(gUnk_030017A0[gUnk_03000440.unk51].unk2) * 64, 0x32, 1, 13, 10, 13, 0, 2);
    else
    {
        fill_text_blank(gUnk_03000440.unk9E, 10);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x32, 1, 13, 10, 13, 0, 2);
    }
}

// guess: draws the selected Medabot's Medal type name (gUnk_083B6410) (or blanks).
void sub_0800519C(void)
{
    clear_sprite_table_mask(0x3C, 10);
    if (gUnk_030017A0[gUnk_03000440.unk51].unk0 > 1)
    {
        memcpy_bytes_0803F63C((const void *)gUnk_083B6410[gUnk_030017A0[gUnk_03000440.unk51].unk2], gUnk_03000440.unk9E, 11);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x3C, 4, 16, 7, 14, 1, 2);
    }
    else
    {
        fill_text_blank(gUnk_03000440.unk9E, 9);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x3C, 4, 16, 7, 14, 1, 2);
    }
}

void sub_0800522C(void)
{
    if (gUnk_030017A0[gUnk_03000440.unk51].unk0 > 1)
        CpuFastSet((const u8 *)0x084C21BC + gUnk_030017A0[gUnk_03000440.unk51].unk2 * 0x80, (void *)0x06006600, 0x20);
    else
        CpuFastSet((const void *)0x084C30BC, (void *)0x06006600, 0x20);
    fill_tilemap_rect_08042698(2, 2, 1, 16, REG_BG1CNT, 0x6330);
}

void sub_0800529C(void)
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
    gUnk_03000430 = 2;
    gUnk_03002414 = (struct Unk_03002414 *)0x02024000;
    fill = 0;
    CpuFastSet(&fill, (void *)0x02024000, 0x01000426);
    gUnk_03005308 = (struct SceneSlot *)c;
    sub_08047414(obj, (u8 *)gUnk_03002414, (struct SpriteNodeDesc **)gUnk_083D1BF8, (struct SpriteNodeOam *)b);
    obj->oams = (struct SpriteNodeOam *)b;
    if (gUnk_03000440.unk5E)
        setup_scene_bg_layers_and_sprites(gUnk_03002414->unkB84, obj,
            gUnk_030017A0[gUnk_03000440.unk51].unk3, gUnk_030017A0[gUnk_03000440.unk51].unk4,
            gUnk_030017A0[gUnk_03000440.unk51].unk5, gUnk_030017A0[gUnk_03000440.unk51].unk6,
            0x28, 0x28, 0x1C2, 8, 1, 1);
    else
        setup_scene_bg_layers_and_sprites(gUnk_03002414->unkB84, obj,
            gUnk_030017A0[gUnk_03000440.unk51].unk3, gUnk_030017A0[gUnk_03000440.unk51].unk4,
            gUnk_030017A0[gUnk_03000440.unk51].unk5, gUnk_030017A0[gUnk_03000440.unk51].unk6,
            0x28, 0x28, 0x1C2, 8, 1, 0);
}

void sub_080053C8(void)
{
    struct Unk_08047414 *obj = (struct Unk_08047414 *)0x02026000;
    u32 fill;

    obj->oams = (struct SpriteNodeOam *)0x020260D0;
    if (gUnk_03000440.unk5E)
        setup_scene_bg_layers_and_sprites(gUnk_03002414->unkB84, obj,
            gUnk_030017A0[gUnk_03000440.unk51].unk3, gUnk_030017A0[gUnk_03000440.unk51].unk4,
            gUnk_030017A0[gUnk_03000440.unk51].unk5, gUnk_030017A0[gUnk_03000440.unk51].unk6,
            0x28, 0x28, 0x1C2, 8, 1, 1);
    else
        setup_scene_bg_layers_and_sprites(gUnk_03002414->unkB84, obj,
            gUnk_030017A0[gUnk_03000440.unk51].unk3, gUnk_030017A0[gUnk_03000440.unk51].unk4,
            gUnk_030017A0[gUnk_03000440.unk51].unk5, gUnk_030017A0[gUnk_03000440.unk51].unk6,
            0x28, 0x28, 0x1C2, 8, 1, 0);
    fill = 0x200;
    CpuFastSet(&fill, gUnk_03002414->unkB84, 0x01000100);
    gUnk_03002414->unk1094 = 0;
    gUnk_03002414->unk1095 = 0;
}

void setup_overworld_scene_from_position(void)
{
    if (gUnk_030017A0[gUnk_03000440.unk51].unk0)
    {
        if (gUnk_03000440.unk5E)
            setup_scene_bg_layers_and_sprites(gUnk_03002414->unkB84, (struct Unk_08047414 *)0x02026000,
                gUnk_030017A0[gUnk_03000440.unk51].unk3, gUnk_030017A0[gUnk_03000440.unk51].unk4,
                gUnk_030017A0[gUnk_03000440.unk51].unk5, gUnk_030017A0[gUnk_03000440.unk51].unk6,
                0x3C, 0x32, 0x1C2, 8, 5, 1);
        else
            setup_scene_bg_layers_and_sprites(gUnk_03002414->unkB84, (struct Unk_08047414 *)0x02026000,
                gUnk_030017A0[gUnk_03000440.unk51].unk3, gUnk_030017A0[gUnk_03000440.unk51].unk4,
                gUnk_030017A0[gUnk_03000440.unk51].unk5, gUnk_030017A0[gUnk_03000440.unk51].unk6,
                0x3C, 0x32, 0x1C2, 8, 5, 0);
    }
}

// D-pad moves the slot cursor (gUnk_03000440.unk51) through gMedabotSlotDpadMoves and redraws the
// selected Medabot's info. Runtime: RIGHT from slot 0 -> 3. Returns 1 if the cursor moved.
u32 medabots_screen_cursor_input(void)
{
    u32 moved = 0;
    const u8 *next;

    if (KEYS_LO(gRepeatKeys) & 0x40)
    {
        next = gMedabotSlotDpadMoves[0];
        moved = 1;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80)
    {
        next = gMedabotSlotDpadMoves[1];
        moved = 1;
    }
    if (KEYS_LO(gRepeatKeys) & 0x20)
    {
        next = gMedabotSlotDpadMoves[2];
        moved = 1;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10)
    {
        next = gMedabotSlotDpadMoves[3];
        moved = 1;
    }
    if (moved)
    {
        play_sound_effect(2);
        gUnk_03000440.unk51 = next[gUnk_03000440.unk51];
        update_battle_sprite_orbit_clockwise(0);
        update_battle_sprite_orbit_clockwise(1);
        update_battle_sprite_orbit_clockwise(2);
        update_battle_sprite_orbit_clockwise(3);
        sub_08005118();
        sub_0800519C();
        sub_0800522C();
        sub_080053C8();
        sub_08005000();
        sub_08005948();
        return 1;
    }
    return 0;
}

void medabots_screen_start_reorder_orbit(void)
{
    gUnk_03002C30[4].unk0 = 0xC604;
    gUnk_03002C30[4].unk23 = 0;
    update_battle_sprite_orbit_counterclockwise(4);
    gUnk_03002C30[5].unk0 = 0xC604;
    gUnk_03002C30[5].unk23 = 0x10;
    update_battle_sprite_orbit_counterclockwise(5);
    gUnk_03002C30[6].unk0 = 0xC604;
    gUnk_03002C30[6].unk23 = 0x20;
    update_battle_sprite_orbit_counterclockwise(6);
    gUnk_03002C30[7].unk0 = 0xC604;
    gUnk_03002C30[7].unk23 = 0x30;
    update_battle_sprite_orbit_counterclockwise(7);
}

void update_battle_sprite_orbit_counterclockwise(u32 i)
{
    u32 cx = gUnk_083AC420[(gUnk_03000440.unk52 & 0x7F) * 2];
    u32 cy = gUnk_083AC420[(gUnk_03000440.unk52 & 0x7F) * 2 + 1] - 4;
    struct Vec16 p = compute_polar_to_screen_position(((gUnk_03002C30[i].unk23 + 16) & 0x3F) * 4, 16, cx, cy, 8, 0);

    gUnk_03002C30[i].unk2 = p.x;
    gUnk_03002C30[i].unk4 = p.y;
    gUnk_03002C30[i].unk6 = 0x400;
    gUnk_03002C30[i].unkA = 12;
    gUnk_03002C30[i].unk1C = 0;
    gUnk_03002C30[i].unk9 = 0x40 - (cy + 8 - gUnk_03002C30[i].unk4) * 3;
    gUnk_03002C30[i].unk8 = 0x60 - (cy + 8 - gUnk_03002C30[i].unk4) * 3;
    if (cy > gUnk_03002C30[i].unk4)
        gUnk_03002C30[i].unkB = gUnk_083AC432[gUnk_03000440.unk52 & 0x7F] - 1;
    else
        gUnk_03002C30[i].unkB = gUnk_083AC432[gUnk_03000440.unk52 & 0x7F] + 4;
    gUnk_03002C30[i].unk18 = gUnk_03002C30[i].unk23 << 4;
    gUnk_03002C30[i].unk23 = (gUnk_03002C30[i].unk23 - 1) & 0x3F;
}

void update_battle_icon_blink_and_orbit(void)
{
    if (gUnk_03000440.unk52 & 0x80)
    {
        if (gFrameCounter & 1)
        {
            gUnk_03002C30[4].unk0 |= 0x4000;
            gUnk_03002C30[5].unk0 |= 0x4000;
            gUnk_03002C30[6].unk0 |= 0x4000;
            gUnk_03002C30[7].unk0 |= 0x4000;
        }
        else
        {
            gUnk_03002C30[4].unk0 &= 0xBFFF;
            gUnk_03002C30[5].unk0 &= 0xBFFF;
            gUnk_03002C30[6].unk0 &= 0xBFFF;
            gUnk_03002C30[7].unk0 &= 0xBFFF;
        }
        update_battle_sprite_orbit_counterclockwise(4);
        update_battle_sprite_orbit_counterclockwise(5);
        update_battle_sprite_orbit_counterclockwise(6);
        update_battle_sprite_orbit_counterclockwise(7);
    }
    else
    {
        gUnk_03002C30[4].unk0 &= 0xBFFF;
        gUnk_03002C30[5].unk0 &= 0xBFFF;
        gUnk_03002C30[6].unk0 &= 0xBFFF;
        gUnk_03002C30[7].unk0 &= 0xBFFF;
    }
}

// SELECT ("REORDER"): first press picks the slot (unk52 = slot | 0x80, icons orbit it), second press
// swaps the two gUnk_030017A0 entries. Runtime-checked: slot 3 picked (unk52 0x83), then swapped with 0.
u32 medabots_screen_reorder_input(void)
{
    if (gUnk_03000440.unk50 == 0 && (KEYS_LO(gNewKeys) & 4))
    {
        play_sound_effect(2);
        if (gUnk_03000440.unk52 & 0x80)
        {
            gUnk_03000440.unk52 &= 0x7F;
            if (gUnk_03000440.unk52 != gUnk_03000440.unk51)
            {
                memswap(&gUnk_030017A0[gUnk_03000440.unk52], &gUnk_030017A0[gUnk_03000440.unk51], 8);
                sub_08004FD0();
                sub_08005000();
                sub_0800508C();
                sub_08005118();
                sub_0800519C();
                sub_0800522C();
                sub_080053C8();
                sub_08005948();
            }
            gUnk_03000440.unk52 = 0;
        }
        else
        {
            gUnk_03000440.unk52 = gUnk_03000440.unk51 + 0x80;
            medabots_screen_start_reorder_orbit();
        }
        update_battle_icon_blink_and_orbit();
        return 1;
    }
    return 0;
}

void sub_08005948(void)
{
    if (validate_medapart_stats(gUnk_030017A0[gUnk_03000440.unk51].unk2, gUnk_030017A0[gUnk_03000440.unk51].unk3, gUnk_030017A0[gUnk_03000440.unk51].unk4, gUnk_030017A0[gUnk_03000440.unk51].unk5, gUnk_030017A0[gUnk_03000440.unk51].unk6))
        battle_sprite_set_palette_index(gUnk_03000440.unk51 * 4 + 10, 8);
}

void check_and_update_battle_sprite_orbit(void)
{
    if (validate_medapart_stats(gUnk_030017A0[gUnk_03000440.unk51].unk2, gUnk_030017A0[gUnk_03000440.unk51].unk3, gUnk_030017A0[gUnk_03000440.unk51].unk4, gUnk_030017A0[gUnk_03000440.unk51].unk5, gUnk_030017A0[gUnk_03000440.unk51].unk6))
        update_battle_sprite_orbiting_positions(gUnk_03000440.unk51 * 4 + 10, gUnk_03000440.unk51, 0);
}

// guess: takes the selected Medabot apart: Medal (unk97, 0x1E = none) and parts to unk98-9B, parts
// back into the inventory (modify_medapart_quantity), slot marked empty.
void sub_080059D0(void)
{
    if (gUnk_030017A0[gUnk_03000440.unk51].unk2 == 0x1E)
        gUnk_03000440.unk97 = 0x1E;
    else
        gUnk_03000440.unk97 = find_medal_slot_by_id(gUnk_030017A0[gUnk_03000440.unk51].unk2) - 1;
    gUnk_03000440.unk98 = gUnk_030017A0[gUnk_03000440.unk51].unk3;
    gUnk_03000440.unk99 = gUnk_030017A0[gUnk_03000440.unk51].unk4;
    gUnk_03000440.unk9A = gUnk_030017A0[gUnk_03000440.unk51].unk5;
    gUnk_03000440.unk9B = gUnk_030017A0[gUnk_03000440.unk51].unk6;
    if (gUnk_03000440.unk97 != 0x1E)
        gUnk_03000BE0[gUnk_03000440.unk97].unk0 &= 0xBF;
    gUnk_030017A0[gUnk_03000440.unk51].unk0 = 1;
    if (gUnk_03000440.unk98 <= 0x77)
        modify_medapart_quantity(gUnk_03000440.unk98, 0, 1, 1, 1);
    if (gUnk_03000440.unk99 <= 0x77)
        modify_medapart_quantity(gUnk_03000440.unk99, 1, 1, 1, 1);
    if (gUnk_03000440.unk9A <= 0x77)
        modify_medapart_quantity(gUnk_03000440.unk9A, 2, 1, 1, 1);
    if (gUnk_03000440.unk9B <= 0x77)
        modify_medapart_quantity(gUnk_03000440.unk9B, 3, 1, 1, 1);
}

void sub_08005AD0(void)
{
    clear_sprite_table_mask(10, 10);
    if (gUnk_03000440.unk97 < 30)
        render_text_sprites_08040DB8(gUnk_03000BE0[gUnk_03000440.unk97].unkA, 10, 1, 13, 10, 15, 0, 2);
    else
    {
        fill_text_blank(gUnk_03000440.unk9E, 10);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 10, 1, 13, 10, 15, 0, 2);
    }
}

void sub_08005B44(void)
{
    if (gUnk_03000440.unk97 < 30)
        CpuFastSet((const u8 *)0x084C21BC + gUnk_03000BE0[gUnk_03000440.unk97].unk1 * 0x80, (void *)0x06007800, 0x20);
    else
        CpuFastSet((const void *)0x084C30BC, (void *)0x06007800, 0x20);
    fill_tilemap_rect_08042698(2, 2, 16, 9, REG_BG1CNT, 0x63C0);
}

void sub_08005BB4(void)
{
    if (gUnk_03000440.unk97 < 30)
        fill_tilemap_pair_or_divide(gUnk_03000BE0[gUnk_03000440.unk97].unk5, 0x1A, 9, REG_BG1CNT, 0xD3A4);
    else
        fill_tilemap_pair_or_divide(0xFF, 0x1A, 9, REG_BG1CNT, 0xD3A4);
}

void sub_08005C10(void)
{
    clear_sprite_table_mask(0x14, 10);
    if (gUnk_03000440.unk97 < 30)
    {
        memcpy_bytes_0803F63C((const void *)gUnk_083B6410[gUnk_03000BE0[gUnk_03000440.unk97].unk1], gUnk_03000440.unk9E, 11);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x14, 0x12, 9, 7, 12, 1, 2);
    }
    else
    {
        fill_text_blank(gUnk_03000440.unk9E, 9);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x14, 0x12, 9, 7, 12, 1, 2);
    }
}

// Medapart names (gUnk_083BB9CC[part][kind]: head, right arm, left arm, legs) at rows 11-17 (runtime-checked).
void medabot_detail_draw_head_name(void)
{
    clear_sprite_table_mask(0x1E, 14);
    if (gUnk_03000440.unk98 < 120)
    {
        memcpy_bytes_08041D04((const void *)gUnk_083BB9CC[0][gUnk_03000440.unk98 * 4 + 0], gUnk_03000440.unk9E, 15);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x1E, 0x12, 11, 10, 13, 1, 2);
    }
    else
    {
        fill_text_blank(gUnk_03000440.unk9E, 13);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x1E, 0x12, 11, 10, 13, 1, 2);
    }
}

// Icon after the part name when the Medal's skill (gUnk_083B6158[...][1]) matches the part's (load_part_data byte 0).
void medabot_detail_draw_head_skill_icon(void)
{
    if (gUnk_03000440.unk98 < 120)
    {
        if (gUnk_03000440.unk97 < 30)
        {
            load_part_data(gUnk_03000440.unk98, 0, &gUnk_03000440.unkEE);
            memcpy_bytes_08041D04(gUnk_083B6158[gUnk_03000BE0[gUnk_03000440.unk97].unk1], gUnk_03000440.unk10E, 16);
            if (gUnk_03000440.unkEE == gUnk_03000440.unk10E[1])
                fill_tilemap_rect_08042698(2, 2, 16, 11, REG_BG1CNT, 0xD340 + gUnk_03000440.unk10E[7] * 4);
            else
                fill_tilemap_rect_08042698(2, 2, 16, 11, REG_BG1CNT, 0xD340);
        }
        else
        {
            vram_fill_tilemap_rect(2, 2, 16, 11, REG_BG1CNT, 0);
        }
    }
    else
    {
        vram_fill_tilemap_rect(2, 2, 16, 11, REG_BG1CNT, 0);
    }
}

void medabot_detail_draw_rarm_name(void)
{
    clear_sprite_table_mask(0x2C, 14);
    if (gUnk_03000440.unk99 < 120)
    {
        memcpy_bytes_08041D04((const void *)gUnk_083BB9CC[0][gUnk_03000440.unk99 * 4 + 1], gUnk_03000440.unk9E, 15);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x2C, 0x12, 13, 10, 13, 1, 2);
    }
    else
    {
        fill_text_blank(gUnk_03000440.unk9E, 13);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x2C, 0x12, 13, 10, 13, 1, 2);
    }
}

void medabot_detail_draw_rarm_skill_icon(void)
{
    if (gUnk_03000440.unk99 < 120)
    {
        if (gUnk_03000440.unk97 < 30)
        {
            load_part_data(gUnk_03000440.unk99, 1, &gUnk_03000440.unkEE);
            memcpy_bytes_08041D04(gUnk_083B6158[gUnk_03000BE0[gUnk_03000440.unk97].unk1], gUnk_03000440.unk10E, 16);
            if (gUnk_03000440.unkEE == gUnk_03000440.unk10E[1])
                fill_tilemap_rect_08042698(2, 2, 16, 13, REG_BG1CNT, 0xD340 + gUnk_03000440.unk10E[7] * 4);
            else
                fill_tilemap_rect_08042698(2, 2, 16, 13, REG_BG1CNT, 0xD340);
        }
        else
        {
            vram_fill_tilemap_rect(2, 2, 16, 13, REG_BG1CNT, 0);
        }
    }
    else
    {
        vram_fill_tilemap_rect(2, 2, 16, 13, REG_BG1CNT, 0);
    }
}

void medabot_detail_draw_larm_name(void)
{
    clear_sprite_table_mask(0x3A, 14);
    if (gUnk_03000440.unk9A < 120)
    {
        memcpy_bytes_08041D04((const void *)gUnk_083BB9CC[0][gUnk_03000440.unk9A * 4 + 2], gUnk_03000440.unk9E, 15);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x3A, 0x12, 15, 10, 13, 1, 2);
    }
    else
    {
        fill_text_blank(gUnk_03000440.unk9E, 13);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x3A, 0x12, 15, 10, 13, 1, 2);
    }
}

void medabot_detail_draw_larm_skill_icon(void)
{
    if (gUnk_03000440.unk9A < 120)
    {
        if (gUnk_03000440.unk97 < 30)
        {
            load_part_data(gUnk_03000440.unk9A, 2, &gUnk_03000440.unkEE);
            memcpy_bytes_08041D04(gUnk_083B6158[gUnk_03000BE0[gUnk_03000440.unk97].unk1], gUnk_03000440.unk10E, 16);
            if (gUnk_03000440.unkEE == gUnk_03000440.unk10E[1])
                fill_tilemap_rect_08042698(2, 2, 16, 15, REG_BG1CNT, 0xD340 + gUnk_03000440.unk10E[7] * 4);
            else
                fill_tilemap_rect_08042698(2, 2, 16, 15, REG_BG1CNT, 0xD340);
        }
        else
        {
            vram_fill_tilemap_rect(2, 2, 16, 15, REG_BG1CNT, 0);
        }
    }
    else
    {
        vram_fill_tilemap_rect(2, 2, 16, 15, REG_BG1CNT, 0);
    }
}

void medabot_detail_draw_legs_name(void)
{
    clear_sprite_table_mask(0x48, 14);
    if (gUnk_03000440.unk9B < 120)
    {
        memcpy_bytes_08041D04((const void *)gUnk_083BB9CC[0][gUnk_03000440.unk9B * 4 + 3], gUnk_03000440.unk9E, 15);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x48, 0x12, 17, 10, 13, 1, 2);
    }
    else
    {
        fill_text_blank(gUnk_03000440.unk9E, 13);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x48, 0x12, 17, 10, 13, 1, 2);
    }
}

void medabot_detail_draw_legs_skill_icon(void)
{
    if (gUnk_03000440.unk9B < 120)
    {
        if (gUnk_03000440.unk97 < 30)
        {
            load_part_data(gUnk_03000440.unk9B, 3, &gUnk_03000440.unkEE);
            memcpy_bytes_08041D04(gUnk_083B6158[gUnk_03000BE0[gUnk_03000440.unk97].unk1], gUnk_03000440.unk10E, 16);
            if (gUnk_03000440.unkEE == gUnk_03000440.unk10E[1])
                fill_tilemap_rect_08042698(2, 2, 16, 17, REG_BG1CNT, 0xD340 + gUnk_03000440.unk10E[7] * 4);
            else
                fill_tilemap_rect_08042698(2, 2, 16, 17, REG_BG1CNT, 0xD340);
        }
        else
        {
            vram_fill_tilemap_rect(2, 2, 16, 17, REG_BG1CNT, 0);
        }
    }
    else
    {
        vram_fill_tilemap_rect(2, 2, 16, 17, REG_BG1CNT, 0);
    }
}

// Icon left of detail row 0-4 (Medal, head, right arm, left arm, legs); medabot_detail_blink_row_icon
// alternates a = 0 / 1 on the selected row every 8 frames.
void medabot_detail_draw_row_icon_0(u32 a)
{
    if (a == 0)
        fill_tilemap_rect_08042698(2, 2, 14, 9, REG_BG1CNT, 0xC370);
    else
        fill_tilemap_rect_08042698(2, 2, 14, 9, REG_BG1CNT, 0xC384);
}

void medabot_detail_draw_row_icon_1(u32 a)
{
    if (a == 0)
        fill_tilemap_rect_08042698(2, 2, 14, 11, REG_BG1CNT, 0xC374);
    else
        fill_tilemap_rect_08042698(2, 2, 14, 11, REG_BG1CNT, 0xC388);
}

void medabot_detail_draw_row_icon_2(u32 a)
{
    if (a == 0)
        fill_tilemap_rect_08042698(2, 2, 14, 13, REG_BG1CNT, 0xC378);
    else
        fill_tilemap_rect_08042698(2, 2, 14, 13, REG_BG1CNT, 0xC388);
}

void medabot_detail_draw_row_icon_3(u32 a)
{
    if (a == 0)
        fill_tilemap_rect_08042698(2, 2, 14, 15, REG_BG1CNT, 0xC37C);
    else
        fill_tilemap_rect_08042698(2, 2, 14, 15, REG_BG1CNT, 0xC388);
}

void medabot_detail_draw_row_icon_4(u32 a)
{
    if (a == 0)
        fill_tilemap_rect_08042698(2, 2, 14, 17, REG_BG1CNT, 0xC380);
    else
        fill_tilemap_rect_08042698(2, 2, 14, 17, REG_BG1CNT, 0xC388);
}

// Legs type icon above the Medal row (part data byte 1 - 100, 0xFF = none).
void medabot_detail_draw_legs_type_icon(void)
{
    if (gUnk_03000440.unk9B < 120)
    {
        load_part_data(gUnk_03000440.unk9B, 3, &gUnk_03000440.unkEE);
        draw_tilemap_with_offset(gUnk_03000440.unkEF - 100, 20, 6, REG_BG1CNT, 0x8300);
    }
    else
    {
        draw_tilemap_with_offset(0xFF, 20, 6, REG_BG1CNT, 0x8300);
    }
}

void decompress_sprite_from_game_state(void)
{
    decompress_sprite_to_vram_08042D94(gUnk_03000440.unk98, gUnk_03000440.unk99, gUnk_03000440.unk9A, gUnk_03000440.unk9B, 0);
}

void setup_battle_sprite_from_game_state(void)
{
    setup_battle_sprite_group(gUnk_03000440.unk98, gUnk_03000440.unk99, gUnk_03000440.unk9A, gUnk_03000440.unk9B,
                              0, 6, 0xA8, 0x20, gUnk_03000440.unk5E, 1, 5);
}

void medabot_detail_place_row_arrows(void)
{
    gUnk_03002C30[1].unk0 = 0xC804;
    gUnk_03002C30[1].unk2 = 0x6C;
    gUnk_03002C30[1].unk4 = gUnk_03000440.unk5A * 16 + 0x50;
    gUnk_03002C30[1].unk6 = 0x302;
    gUnk_03002C30[1].unkA = 14;
    gUnk_03002C30[1].unk1C = 0;
    gUnk_03002C30[1].unkB = 0x40;
    gUnk_03002C30[2].unk0 = 0xC804;
    gUnk_03002C30[2].unk2 = 0xE4;
    gUnk_03002C30[2].unk4 = gUnk_03000440.unk5A * 16 + 0x50;
    gUnk_03002C30[2].unk6 = 0x303;
    gUnk_03002C30[2].unkA = 14;
    gUnk_03002C30[2].unk1C = 0;
    gUnk_03002C30[2].unkB = 0x40;
}

void medabot_detail_blink_row_arrows(void)
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

void init_scene_state(void)
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
    gUnk_03000430 = 2;
    gUnk_03002414 = (struct Unk_03002414 *)0x02024000;
    fill = 0;
    CpuFastSet(&fill, (void *)0x02024000, 0x01000426);
    gUnk_03005308 = (struct SceneSlot *)c;
    sub_08047414(obj, (u8 *)gUnk_03002414, (struct SpriteNodeDesc **)gUnk_083D1BF8, (struct SpriteNodeOam *)b);
    obj->oams = (struct SpriteNodeOam *)b;
    if (gUnk_03000440.unk5E)
        setup_scene_bg_layers_and_sprites(gUnk_03002414->unkB84, obj,
            gUnk_03000440.unk98, gUnk_03000440.unk99, gUnk_03000440.unk9A, gUnk_03000440.unk9B,
            0x28, 0x28, 0x1C2, 8, 1, 1);
    else
        setup_scene_bg_layers_and_sprites(gUnk_03002414->unkB84, obj,
            gUnk_03000440.unk98, gUnk_03000440.unk99, gUnk_03000440.unk9A, gUnk_03000440.unk9B,
            0x28, 0x28, 0x1C2, 8, 1, 0);
}

void setup_scene_with_link_check(void)
{
    struct Unk_08047414 *obj = (struct Unk_08047414 *)0x02026000;
    u32 fill;

    obj->oams = (struct SpriteNodeOam *)0x020260D0;
    if (gUnk_03000440.unk5E)
        setup_scene_bg_layers_and_sprites(gUnk_03002414->unkB84, obj,
            gUnk_03000440.unk98, gUnk_03000440.unk99, gUnk_03000440.unk9A, gUnk_03000440.unk9B,
            0x28, 0x28, 0x1C2, 8, 1, 1);
    else
        setup_scene_bg_layers_and_sprites(gUnk_03002414->unkB84, obj,
            gUnk_03000440.unk98, gUnk_03000440.unk99, gUnk_03000440.unk9A, gUnk_03000440.unk9B,
            0x28, 0x28, 0x1C2, 8, 1, 0);
    fill = 0x200;
    CpuFastSet(&fill, gUnk_03002414->unkB84, 0x01000100);
    gUnk_03002414->unk1094 = 0;
    gUnk_03002414->unk1095 = 0;
}

void sub_08006764(void)
{
    if (gUnk_03000440.unk5E)
        setup_scene_bg_layers_and_sprites(gUnk_03002414->unkB84, (struct Unk_08047414 *)0x02026000,
            gUnk_03000440.unk98, gUnk_03000440.unk99, gUnk_03000440.unk9A, gUnk_03000440.unk9B,
            0x3C, 0x32, 0x1C2, 8, 5, 1);
    else
        setup_scene_bg_layers_and_sprites(gUnk_03002414->unkB84, (struct Unk_08047414 *)0x02026000,
            gUnk_03000440.unk98, gUnk_03000440.unk99, gUnk_03000440.unk9A, gUnk_03000440.unk9B,
            0x3C, 0x32, 0x1C2, 8, 5, 0);
}

void medabot_detail_blink_row_icon(void)
{
    if (gFrameCounter & 8)
    {
        switch (gUnk_03000440.unk5A)
        {
        case 0:
            medabot_detail_draw_row_icon_0(0);
            break;
        case 1:
            medabot_detail_draw_row_icon_1(0);
            break;
        case 2:
            medabot_detail_draw_row_icon_2(0);
            break;
        case 3:
            medabot_detail_draw_row_icon_3(0);
            break;
        case 4:
            medabot_detail_draw_row_icon_4(0);
            break;
        }
    }
    else
    {
        switch (gUnk_03000440.unk5A)
        {
        case 0:
            medabot_detail_draw_row_icon_0(1);
            break;
        case 1:
            medabot_detail_draw_row_icon_1(1);
            break;
        case 2:
            medabot_detail_draw_row_icon_2(1);
            break;
        case 3:
            medabot_detail_draw_row_icon_3(1);
            break;
        case 4:
            medabot_detail_draw_row_icon_4(1);
            break;
        }
    }
}

u32 medabot_detail_row_cursor_input(void)
{
    if (KEYS_LO(gRepeatKeys) & 0x40)
    {
        if (gUnk_03000440.unk5A == 0)
            gUnk_03000440.unk5A = 4;
        else
            gUnk_03000440.unk5A--;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80)
    {
        if (gUnk_03000440.unk5A == 4)
            gUnk_03000440.unk5A = 0;
        else
            gUnk_03000440.unk5A++;
    }
    if (KEY_BITS(gRepeatKeys).up | KEY_BITS(gRepeatKeys).down)
    {
    play_sound_effect(2);
    medabot_detail_draw_row_icon_0(0);
    medabot_detail_draw_row_icon_1(0);
    medabot_detail_draw_row_icon_2(0);
    medabot_detail_draw_row_icon_3(0);
    medabot_detail_draw_row_icon_4(0);
    medabot_detail_place_row_arrows();
    return 1;
    }
    else
        return 0;
}

u32 medabot_detail_cycle_medal_input(void)
{
    u32 old;

    if (gUnk_03000440.unk5A != 0)
        goto none;
    old = gUnk_03000440.unk97;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gUnk_03000440.unk97 = sub_0804361C(old, 1);
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gUnk_03000440.unk97 = sub_0804361C(gUnk_03000440.unk97, 0);
    if (old == gUnk_03000440.unk97)
    {
    none:
        return 0;
    }
    play_sound_effect(2);
    sub_08005AD0();
    sub_08005B44();
    sub_08005C10();
    sub_08005BB4();
    medabot_detail_draw_head_skill_icon();
    medabot_detail_draw_rarm_skill_icon();
    medabot_detail_draw_larm_skill_icon();
    medabot_detail_draw_legs_skill_icon();
    return 1;
}

u32 medabot_detail_cycle_head_input(void)
{
    u32 old;

    if (gUnk_03000440.unk5A != 1)
        goto none;
    old = gUnk_03000440.unk98;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gUnk_03000440.unk98 = find_next_available_medapart_slot(old, 0, 1, gUnk_030017A0[gUnk_03000440.unk51].unk1);
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gUnk_03000440.unk98 = find_next_available_medapart_slot(gUnk_03000440.unk98, 0, 0, gUnk_030017A0[gUnk_03000440.unk51].unk1);
    if (old == gUnk_03000440.unk98)
    {
    none:
        return 0;
    }
    play_sound_effect(2);
    medabot_detail_draw_head_name();
    medabot_detail_draw_head_skill_icon();
    decompress_sprite_from_game_state();
    setup_battle_sprite_from_game_state();
    setup_scene_with_link_check();
    return 1;
}

u32 medabot_detail_cycle_rarm_input(void)
{
    u32 old;

    if (gUnk_03000440.unk5A != 2)
        goto none;
    old = gUnk_03000440.unk99;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gUnk_03000440.unk99 = find_next_available_medapart_slot(old, 1, 1, gUnk_030017A0[gUnk_03000440.unk51].unk1);
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gUnk_03000440.unk99 = find_next_available_medapart_slot(gUnk_03000440.unk99, 1, 0, gUnk_030017A0[gUnk_03000440.unk51].unk1);
    if (old == gUnk_03000440.unk99)
    {
    none:
        return 0;
    }
    play_sound_effect(2);
    medabot_detail_draw_rarm_name();
    medabot_detail_draw_rarm_skill_icon();
    decompress_sprite_from_game_state();
    setup_battle_sprite_from_game_state();
    setup_scene_with_link_check();
    return 1;
}

u32 medabot_detail_cycle_larm_input(void)
{
    u32 old;

    if (gUnk_03000440.unk5A != 3)
        goto none;
    old = gUnk_03000440.unk9A;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gUnk_03000440.unk9A = find_next_available_medapart_slot(old, 2, 1, gUnk_030017A0[gUnk_03000440.unk51].unk1);
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gUnk_03000440.unk9A = find_next_available_medapart_slot(gUnk_03000440.unk9A, 2, 0, gUnk_030017A0[gUnk_03000440.unk51].unk1);
    if (old == gUnk_03000440.unk9A)
    {
    none:
        return 0;
    }
    play_sound_effect(2);
    medabot_detail_draw_larm_name();
    medabot_detail_draw_larm_skill_icon();
    decompress_sprite_from_game_state();
    setup_battle_sprite_from_game_state();
    setup_scene_with_link_check();
    return 1;
}

u32 medabot_detail_cycle_legs_input(void)
{
    u32 old;

    if (gUnk_03000440.unk5A != 4)
        goto none;
    old = gUnk_03000440.unk9B;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gUnk_03000440.unk9B = find_next_available_medapart_slot(old, 3, 1, gUnk_030017A0[gUnk_03000440.unk51].unk1);
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gUnk_03000440.unk9B = find_next_available_medapart_slot(gUnk_03000440.unk9B, 3, 0, gUnk_030017A0[gUnk_03000440.unk51].unk1);
    if (old == gUnk_03000440.unk9B)
    {
    none:
        return 0;
    }
    play_sound_effect(2);
    medabot_detail_draw_legs_name();
    medabot_detail_draw_legs_skill_icon();
    medabot_detail_draw_legs_type_icon();
    decompress_sprite_from_game_state();
    setup_battle_sprite_from_game_state();
    setup_scene_with_link_check();
    return 1;
}

u32 medabot_detail_equip_full_set_input(void)
{
    volatile u32 kind;
    volatile u32 part;

    if (KEYS_LO(gNewKeys) & 8)
    {
        play_sound_effect(4);
        kind = 0;
        if (gUnk_03000440.unk5A)
            kind = gUnk_03000440.unk5A - 1;
        switch (kind)
        {
    case 0:
            part = gUnk_03000440.unk98;
            break;
    case 1:
            part = gUnk_03000440.unk99;
            break;
    case 2:
            part = gUnk_03000440.unk9A;
            break;
    case 3:
            part = gUnk_03000440.unk9B;
            break;
        }
        if (medabot_detail_is_full_set())
            part = find_next_available_medapart_slot(part, kind, 0, gUnk_030017A0[gUnk_03000440.unk51].unk1);
        goto next;
done:
        medabot_detail_draw_head_name();
        medabot_detail_draw_head_skill_icon();
        medabot_detail_draw_rarm_name();
        medabot_detail_draw_rarm_skill_icon();
        medabot_detail_draw_larm_name();
        medabot_detail_draw_larm_skill_icon();
        medabot_detail_draw_legs_name();
        medabot_detail_draw_legs_skill_icon();
        medabot_detail_draw_legs_type_icon();
        decompress_sprite_from_game_state();
        setup_battle_sprite_from_game_state();
        setup_scene_with_link_check();
        return 1;
next:
        part = medabot_detail_prev_part_id(part);
        while (1)
        {
            gUnk_03000440.unk98 = find_next_available_medapart_slot(part, 0, 0, gUnk_030017A0[gUnk_03000440.unk51].unk1);
            gUnk_03000440.unk99 = find_next_available_medapart_slot(part, 1, 0, gUnk_030017A0[gUnk_03000440.unk51].unk1);
            gUnk_03000440.unk9A = find_next_available_medapart_slot(part, 2, 0, gUnk_030017A0[gUnk_03000440.unk51].unk1);
            gUnk_03000440.unk9B = find_next_available_medapart_slot(part, 3, 0, gUnk_030017A0[gUnk_03000440.unk51].unk1);
            if (medabot_detail_is_full_set())
                goto done;
            switch (kind)
            {
        case 0:
                part = gUnk_03000440.unk98;
                break;
        case 1:
                part = gUnk_03000440.unk99;
                break;
        case 2:
                part = gUnk_03000440.unk9A;
                break;
        case 3:
                part = gUnk_03000440.unk9B;
                break;
            }
            part = find_next_available_medapart_slot(part, kind, 0, gUnk_030017A0[gUnk_03000440.unk51].unk1);
            part = medabot_detail_prev_part_id(part);
        }
    }
    return 0;
}

u32 medabot_detail_prev_part_id(volatile u32 part)
{
    if (part == 0)
        part = gUnk_030017A0[gUnk_03000440.unk51].unk1 + 120;
    else if (part > 119)
        part = 119;
    else
        part = part - 1;
    return part;
}

// unk53 set while validate_medapart_stats rejects the shown Medal + Medaparts: the Medabot sprite
// switches to palette 8 (and sub_08006F14 animates it); cleared and redrawn once valid again.
void battle_update_medabot_display(void)
{
    u32 r;

    if (gUnk_03000440.unk53)
    {
        r = validate_medapart_stats(gUnk_03000440.unk97, gUnk_03000440.unk98, gUnk_03000440.unk99, gUnk_03000440.unk9A, gUnk_03000440.unk9B);
        if (r == 0)
        {
            init_battle_medabot_sprites(gUnk_03000440.unk98, gUnk_03000440.unk99, gUnk_03000440.unk9A, gUnk_03000440.unk9B,
                                        r, 6, 0xA8, 0x20, gUnk_03000440.unk5E, 1, 5);
            gUnk_03000440.unk53 = r;
        }
    }
    else
    {
        if (validate_medapart_stats(gUnk_03000440.unk97, gUnk_03000440.unk98, gUnk_03000440.unk99, gUnk_03000440.unk9A, gUnk_03000440.unk9B))
        {
            battle_sprite_set_palette_index(6, 8);
            gUnk_03000440.unk53 = 1;
        }
    }
}

void sub_08006F14(void)
{
    if (gUnk_03000440.unk53)
        update_battle_sprite_orbiting_positions(6, 0, 0);
}

// A on the detail screen: 1 if the selected row holds a Medal / Medapart, 2 if it is empty.
// No A press falls off the end (no return value, r0 is left as is; the caller tests 1 / 2).
u8 medabot_detail_check_row_select(void)
{
    if (KEYS_LO(gNewKeys) & 1)
    {
        switch (gUnk_03000440.unk5A)
        {
        case 0:
            if (gUnk_03000440.unk97 == 30)
                return 2;
            return 1;
        case 1:
            if (gUnk_03000440.unk98 > 119)
                return 2;
            return 1;
        case 2:
            if (gUnk_03000440.unk99 > 119)
                return 2;
            return 1;
        case 3:
            if (gUnk_03000440.unk9A > 119)
                return 2;
            return 1;
        case 4:
            if (gUnk_03000440.unk9B > 119)
                return 2;
            return 1;
        }
    }
}

void assign_medal_to_team_slot(void)
{
    u8 n = 0;

    if (gUnk_03000440.unk97 == 30)
    {
        gUnk_030017A0[gUnk_03000440.unk51].unk0 = 1;
        gUnk_030017A0[gUnk_03000440.unk51].unk2 = 30;
    }
    else
    {
        gUnk_030017A0[gUnk_03000440.unk51].unk0 = 2;
        gUnk_030017A0[gUnk_03000440.unk51].unk2 = gUnk_03000BE0[gUnk_03000440.unk97].unk1;
        gUnk_03000BE0[gUnk_03000440.unk97].unk0 |= 0x40;
        n = 1;
    }
    gUnk_030017A0[gUnk_03000440.unk51].unk3 = gUnk_03000440.unk98;
    if (gUnk_03000440.unk98 < 120)
    {
        modify_medapart_quantity(gUnk_03000440.unk98, 0, 1, 0, 1);
        n++;
    }
    gUnk_030017A0[gUnk_03000440.unk51].unk4 = gUnk_03000440.unk99;
    if (gUnk_03000440.unk99 < 120)
    {
        modify_medapart_quantity(gUnk_03000440.unk99, 1, 1, 0, 1);
        n++;
    }
    gUnk_030017A0[gUnk_03000440.unk51].unk5 = gUnk_03000440.unk9A;
    if (gUnk_03000440.unk9A < 120)
    {
        modify_medapart_quantity(gUnk_03000440.unk9A, 2, 1, 0, 1);
        n++;
    }
    gUnk_030017A0[gUnk_03000440.unk51].unk6 = gUnk_03000440.unk9B;
    if (gUnk_03000440.unk9B < 120)
    {
        modify_medapart_quantity(gUnk_03000440.unk9B, 3, 1, 0, 1);
        n++;
    }
    if (n == 5)
        gUnk_030017A0[gUnk_03000440.unk51].unk0 = 3;
}

void count_unequipped_medals(void)
{
    u32 i;

    for (i = 0; i < 30; i++)
    {
        if (gUnk_03000BE0[i].unk0 & 0x80)
        {
            if (!(gUnk_03000BE0[i].unk0 & 0x40))
                gUnk_03000440.unk41++;
        }
    }
}

void team_select_draw_pick_markers(void)
{
    u32 i;

    switch (gUnk_03000440.unk50)
    {
    case 1:
    case 2:
        for (i = 0; i < 3; i++)
        {
            if (gUnk_03001800.unk41[i])
            {
                gUnk_03002C30[i + 4].unk0 = 0xC004;
                gUnk_03002C30[i + 4].unk2 = gUnk_083AC43B[(gUnk_03001800.unk41[i] & 0xF) * 2];
                gUnk_03002C30[i + 4].unk4 = gUnk_083AC43B[(gUnk_03001800.unk41[i] & 0xF) * 2 + 1];
                gUnk_03002C30[i + 4].unk6 = i + 0x401;
                gUnk_03002C30[i + 4].unkA = 15;
                gUnk_03002C30[i + 4].unk1C = 0;
                gUnk_03002C30[i + 4].unkB = 0xC0;
            }
            else
            {
                clear_sprite_table_mask(i + 4, 1);
            }
        }
        break;
    case 3:
        for (i = 0; i < 3; i++)
        {
            if (gUnk_03001800.unk41[i])
            {
                gUnk_03002C30[i + 4].unk0 = 0xC004;
                gUnk_03002C30[i + 4].unk2 = gUnk_083AC43B[(gUnk_03001800.unk41[i] & 0xF) * 2];
                gUnk_03002C30[i + 4].unk4 = gUnk_083AC43B[(gUnk_03001800.unk41[i] & 0xF) * 2 + 1];
                gUnk_03002C30[i + 4].unk6 = i + 0x404;
                gUnk_03002C30[i + 4].unkA = 15;
                gUnk_03002C30[i + 4].unk1C = 0;
                gUnk_03002C30[i + 4].unkB = 0xC0;
            }
            else
            {
                clear_sprite_table_mask(i + 4, 1);
            }
        }
        break;
    }
}

void medabots_screen_cancel_input(void)
{
    s32 i;

    switch (gUnk_03000440.unk50)
    {
    case 1:
    case 2:
    case 3:
        for (i = 2; i >= 0; i--)
        {
            if (gUnk_03001800.unk41[i])
            {
                gUnk_03001800.unk41[i] = 0;
                team_select_draw_pick_markers();
                play_sound_effect(5);
                return;
            }
        }
        break;
    default:
        if (gUnk_03000440.unk52 & 0x80)
        {
            play_sound_effect(2);
            gUnk_03000440.unk52 = 0;
            update_battle_icon_blink_and_orbit();
        }
        else if (sub_080440B4())
        {
            play_sound_effect(5);
            gGameSubState++;
        }
        else
        {
            play_sound_effect(6);
            gGameSubState = 11;
        }
        break;
    }
}

void team_select_confirm_pick(void)
{
    u32 i;

    switch (gUnk_03000440.unk50)
    {
    case 1:
    case 2:
    case 3:
        for (i = 0; i < 3; i++)
        {
            if (gUnk_03001800.unk41[i] == 0)
            {
                if (team_select_slot_not_picked(i) && gUnk_030017A0[gUnk_03000440.unk51].unk0 == 3)
                {
                    play_sound_effect(4);
                    gUnk_03001800.unk41[i] = gUnk_03000440.unk51 + 0x10;
                    team_select_draw_pick_markers();
                    if (i == 2)
                    {
                        switch (gUnk_03000440.unk50)
                        {
                        case 1:
                        case 2:
                            gGameSubState = 0x20;
                            break;
                        default:
                            gGameSubState = 0x28;
                            break;
                        }
                    }
                    else if (sub_080440B4() == i + 1)
                    {
                        gGameSubState = 0x20;
                    }
                    else
                    {
                        gUnk_03000440.unk51 = gUnk_083AC468[gUnk_03000440.unk51];
                        update_battle_sprite_orbit_clockwise(0);
                        update_battle_sprite_orbit_clockwise(1);
                        update_battle_sprite_orbit_clockwise(2);
                        update_battle_sprite_orbit_clockwise(3);
                        sub_08005118();
                        sub_0800519C();
                        sub_0800522C();
                        sub_080053C8();
                        sub_08005000();
                        sub_08005948();
                    }
                }
                else
                {
                    play_sound_effect(6);
                }
                return;
            }
            play_sound_effect(6);
        }
        break;
    default:
        if (gUnk_030017A0[gUnk_03000440.unk51].unk0)
        {
            play_sound_effect(4);
            gGameSubState = 8;
        }
        else
        {
            play_sound_effect(6);
        }
        break;
    }
}

void team_select_finish_input(void)
{
    switch (gUnk_03000440.unk50)
    {
    case 1:
    case 2:
        if (gUnk_03001800.unk41[0])
        {
            play_sound_effect(4);
            gGameSubState = 0x20;
        }
        break;
    }
}

u32 team_select_slot_not_picked(u32 n)
{
    u32 i;

    if (n == 0)
        return 1;
    for (i = 0; i < n; i++)
    {
        if ((gUnk_03001800.unk41[i] & 0xF) == gUnk_03000440.unk51)
            return 0;
    }
    return 1;
}

// guess: blinks the team select pick markers (sprites 4-6) every 4 frames
void sub_08007480(void)
{
    u32 i;

    if (gUnk_03000440.unk5C & 4)
    {
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03001800.unk41[i])
                gUnk_03002C30[i + 4].unk0 &= 0xBFFF;
        }
    }
    else
    {
        for (i = 0; i <= 2; i++)
        {
            if (gUnk_03001800.unk41[i])
                gUnk_03002C30[i + 4].unk0 |= 0x4000;
        }
    }
    gUnk_03000440.unk5C++;
}

void sub_0800750C(void)
{
    if (gUnk_03000440.unk50)
        vram_fill_tilemap_rect(16, 4, 13, 16, REG_BG2CNT, 0);
}

// guess: counts the battle bots in use and draws their label
void sub_08007540(void)
{
    u32 i;

    for (i = 0; i <= 2; i++)
    {
        if (gUnk_03000590[i + 3].unk40)
            gUnk_03001800.unk5B++;
    }
    battle_bots_load_parts(3, gUnk_03001800.unk5B);
}

// Game state 4: the Medals screen (runtime-checked from Medawatch > Medals). Sub-states 0-5 = Medal
// list (unk3F tab, unk40 row); A opens a Medal's pages, L/R cycle unk42: 8.. Ability, 24.. Medaforce,
// 40.. Rotation, 56.. Skill (the last two handlers live in code_08008430). START = help (0x48..).
void medals_screen_update(void)
{
    if (sub_0803EED8() == 0)
        gMedalsScreenHandlers[gGameSubState]();
}

void medals_list_load_gfx(void)
{
    u32 zero;

    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1A03;
    lz_decompress_dispatch(gUnk_084E7264, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C32DC, (void *)0x06006000);
    lz_decompress_dispatch(gUnk_084C3208, (void *)0x06006280);
    lz_decompress_dispatch(gUnk_084C48B4, (void *)0x06007400);
    lz_decompress_dispatch(gUnk_084C4A34, (void *)0x06007600);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    lz_decompress_dispatch(gUnk_0848833C, (void *)0x06006A00);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF348, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EFB5C, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F04F0, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F1554, REG_BG3CNT, 0x200);
    CpuFastSet(gUnk_084F2BA0, (void *)0x05000000, 0x70);
    CpuFastSet(gUnk_08488B44, (void *)0x05000160, 8);
    CpuFastSet(gUnk_0850DEF8, (void *)0x05000200, 0x40);
    CpuFastSet(gUnk_0850DD58, (void *)0x05000300, 8);
    CpuFastSet(gUnk_0850DD58 - 0x20, (void *)0x05000320, 8);
    CpuFastSet(gUnk_084E2E98, (void *)0x050003A0, 8);
    CpuFastSet(gUnk_0850DD58 + 0x60, (void *)0x05000340, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
    zero = 0;
    CpuFastSet(&zero, gUnk_03002C30, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    medals_list_set_cursor_from_medal();
    write_tilemap_rect(10, 2, 5, 2, gUnk_083B4AE0[gUnk_03000440.unk3F + 0x4B], REG_BG1CNT, 0x200);
    render_medal_sprite_tile();
    render_medal_list_entries();
    render_medal_slots_in_menu();
    render_medal_name_display();
    load_medal_sprite();
    render_medal_level_display();
    medals_list_init_tab_arrows();
    medals_list_init_cursor();
    count_owned_medals();
    decompress_active_medal_sprite();
    init_active_medal_battle_sprites();
    draw_medal_position_tile();
    set_blend_effect_mode(5, 0x3F, 0x20);
    if (gUnk_03000440.unk3C == 4 && gUnk_03000440.unk4B == 0)
    {
        gUnk_03000440.unk4B = 1;
        play_song(7);
    }
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void medals_list_fade_in(void)
{
    medals_scroll_bg();
    medals_list_blink_tab_arrows();
    sub_08041C14(3, gFrameCounter, 0x18);
    if (update_blend_effect())
        gGameSubState++;
}

void medals_list_handle_input(void)
{
    u8 b;

    medals_scroll_bg();
    medals_list_blink_tab_arrows();
    sub_08041C14(3, gFrameCounter, 0x18);
    update_battle_sprite_visibility();
    medals_list_row_input();
    medals_list_tab_input();
    medals_list_swap_input();
    if ((b = KEYS_LO(gNewKeys) & 2))
    {
        if (gUnk_03000440.unk3E & 0x80)
        {
            play_sound_effect(2);
            gUnk_03000440.unk3E = 0;
            update_battle_sprite_visibility();
        }
        else
        {
            play_sound_effect(5);
            gGameSubState++;
        }
    }
    else if (KEYS_LO(gNewKeys) & 1)
    {
        gUnk_03000440.unk3D = gUnk_03000440.unk3F * 6 + gUnk_03000440.unk40;
        if (gUnk_03000BE0[gUnk_03000440.unk3D].unk0 & 0x80)
        {
            play_sound_effect(4);
            if (gUnk_03000440.unk3C == 4)
                gGameSubState = 0x60;
            else
            {
                gUnk_03000440.unk42 = b;
                set_blend_effect_mode(6, 0x3F, 0x20);
                gGameSubState = 7;
            }
        }
        else
        {
            play_sound_effect(6);
        }
    }
}

void medals_list_start_fade_out(void)
{
    set_blend_effect_mode(6, 0x3F, 0x20);
    medals_scroll_bg();
    medals_list_blink_tab_arrows();
    sub_08041C14(3, gFrameCounter, 0x18);
    gGameSubState++;
}

void medals_list_wait_fade(void)
{
    medals_scroll_bg();
    medals_list_blink_tab_arrows();
    sub_08041C14(3, gFrameCounter, 0x18);
    if (update_blend_effect())
        gGameSubState++;
}

void medals_list_exit(void)
{
    clear_battle_sprite_slot(0, 0x80);
    if (gUnk_03000440.unk3C == 4)
        sub_08044CDC(0);
    else
    {
        gGameState = 2;
        gGameSubState = 0x10;
    }
}

void medal_ability_load_gfx(void)
{
    u32 zero;

    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1A03;
    lz_decompress_dispatch(gUnk_084E80B0, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C3208, (void *)0x06006280);
    lz_decompress_dispatch(gUnk_084C33DC, (void *)0x06006800);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF380, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EFBE0, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0688, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F16E8, REG_BG3CNT, 0x200);
    CpuFastSet(gUnk_084F2D60, (void *)0x05000000, 0x70);
    CpuFastSet(gUnk_0850DD58 + 0x70, (void *)0x05000340, 8);
    CpuFastSet(gUnk_0850DD58 + 0x40, (void *)0x05000360, 8);
    CpuFastSet(gUnk_0850DD58 - 0x20, (void *)0x05000380, 8);
    CpuFastSet(gUnk_0850DD58 - 0x10, (void *)0x050003A0, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
    zero = 0;
    CpuFastSet(&zero, gUnk_03002C30, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    gUnk_03000440.unk44 = 0;
    medal_page_draw_icon();
    medal_page_draw_kind_name();
    medal_page_draw_name();
    medal_page_draw_level();
    medal_ability_draw_attribute();
    medal_ability_draw_aim();
    medal_ability_draw_compatibility();
    medal_page_init_medal_arrows();
    set_blend_effect_mode(5, 0x3F, 0x20);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void medal_page_wait_fade(void)
{
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    if (update_blend_effect())
        gGameSubState++;
}

void medal_page_open_text_window(void)
{
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    text_window_init(1, 2, 0);
    gGameSubState++;
}

void medal_ability_show_hint(void)
{
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    if (run_message(gUnk_083B53F8[4]))
        gGameSubState++;
}

void medal_ability_handle_input(void)
{
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    medal_page_cycle_medal_input();
    medal_ability_redraw();
    if (KEYS_LO(gNewKeys) & 2)
    {
        play_sound_effect(5);
        gGameSubState++;
    }
    else if (*((u8 *)&gNewKeys + 1) & 2)
    {
        play_sound_effect(2);
        gUnk_03000440.unk42 = (gUnk_03000440.unk42 - 1) & 3;
        gGameSubState = 0x14;
    }
    else if (*((u8 *)&gNewKeys + 1) & 1)
    {
        play_sound_effect(2);
        gUnk_03000440.unk42 = (gUnk_03000440.unk42 + 1) & 3;
        gGameSubState = 0x14;
    }
    else if (KEYS_LO(gNewKeys) & 8)
    {
        play_sound_effect(4);
        gUnk_03000440.unk43 = 0;
        gGameSubState = 0x48;
    }
}

void medal_page_start_fade_out(void)
{
    set_blend_effect_mode(6, 0x3F, 0x20);
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    gGameSubState++;
}

void medal_page_exit(void)
{
    u32 zero;
    u32 zero2;

    clear_battle_sprite_slot(0, 0x80);
    switch (gUnk_03000440.unk3C)
    {
    case 1:
        gUnk_03000440.unk97 = gUnk_03000440.unk3D;
        gGameState = 3;
        gGameSubState = 0x10;
        break;
    case 2:
        sub_0800B498();
        zero = 0;
        CpuFastSet(&zero, (void *)0x05000200, 0x01000080);
        zero2 = 0;
        CpuFastSet(&zero2, (void *)0x05000000, 0x01000080);
        gGameState = 7;
        gGameSubState = 0x3C;
        break;
    case 0:
    case 3:
    case 4:
        gGameSubState = 0;
        break;
    }
}

void medal_page_switch(void)
{
    clear_battle_sprite_slot(0, 0x80);
    switch (gUnk_03000440.unk42)
    {
    case 0:
        gGameSubState = 8;
        break;
    case 1:
        gGameSubState = 0x18;
        break;
    case 2:
        gGameSubState = 0x28;
        break;
    default:
        gGameSubState = 0x38;
        break;
    }
}

void medal_medaforce_load_gfx(void)
{
    u32 zero;

    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1A03;
    lz_decompress_dispatch(gUnk_084E9020, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C3208, (void *)0x06006280);
    lz_decompress_dispatch(gUnk_084C3524, (void *)0x06006000);
    lz_decompress_dispatch(gUnk_084C3648, (void *)0x06006680);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF3F4, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EFCDC, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F07B8, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F187C, REG_BG3CNT, 0x200);
    CpuFastSet(gUnk_084F2F20, (void *)0x05000000, 0x70);
    CpuFastSet(gUnk_0850DD58 + 0x30, (void *)0x05000340, 8);
    CpuFastSet(gUnk_0850DD58 + 0x40, (void *)0x05000360, 8);
    CpuFastSet(gUnk_0850DD58 - 0x20, (void *)0x05000380, 8);
    CpuFastSet(gUnk_0850DD58 - 0x10, (void *)0x050003A0, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
    zero = 0;
    CpuFastSet(&zero, gUnk_03002C30, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    gUnk_03000440.unk44 = 0;
    gUnk_03000440.unk46 = 0;
    medal_page_draw_icon();
    medal_page_draw_kind_name();
    medal_page_draw_name();
    medal_page_draw_level();
    medal_page_init_medal_arrows();
    medal_medaforce_draw_list();
    medal_medaforce_draw_selected();
    medal_medaforce_init_cursor();
    set_blend_effect_mode(5, 0x3F, 0x20);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void medal_medaforce_wait_fade(void)
{
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sub_08041C14(3, gFrameCounter, 8);
    if (update_blend_effect())
        gGameSubState++;
}

void medal_medaforce_open_text_window(void)
{
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sub_08041C14(3, gFrameCounter, 8);
    text_window_init(1, 2, 0);
    gGameSubState++;
}

void medal_medaforce_show_message(void)
{
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sub_08041C14(3, gFrameCounter, 8);
    if (run_message(gUnk_083B7C00[medal_medaforce_get_selected()]))
        gGameSubState++;
}

void medal_medaforce_handle_input(void)
{
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sub_08041C14(3, gFrameCounter, 8);
    if (medal_medaforce_cursor_input())
    {
        sub_0803FB0C();
        gGameSubState++;
        return;
    }
    medal_page_cycle_medal_input();
    if (medal_medaforce_redraw())
    {
        sub_0803FB0C();
        gGameSubState++;
    }
    else if (KEYS_LO(gNewKeys) & 2)
    {
        play_sound_effect(5);
        gGameSubState = 0x1E;
    }
    else if (*((u8 *)&gNewKeys + 1) & 2)
    {
        play_sound_effect(2);
        gUnk_03000440.unk42 = (gUnk_03000440.unk42 - 1) & 3;
        gGameSubState = 0x24;
    }
    else if (*((u8 *)&gNewKeys + 1) & 1)
    {
        play_sound_effect(2);
        gUnk_03000440.unk42 = (gUnk_03000440.unk42 + 1) & 3;
        gGameSubState = 0x24;
    }
    else if (KEYS_LO(gNewKeys) & 8)
    {
        play_sound_effect(4);
        gUnk_03000440.unk43 = 1;
        gGameSubState = 0x48;
    }
}

void medal_medaforce_show_message_back(void)
{
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sub_08041C14(3, gFrameCounter, 8);
    if (run_message(gUnk_083B7C00[medal_medaforce_get_selected()]))
        gGameSubState--;
}

void medal_medaforce_start_fade_out(void)
{
    set_blend_effect_mode(6, 0x3F, 0x20);
    medals_scroll_bg();
    medal_page_blink_medal_arrows();
    sub_08041C14(3, gFrameCounter, 8);
    gGameSubState++;
}

void medal_rotation_load_gfx(void)
{
    u32 zero;

    REG_DISPCNT &= 0xF0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1A03;
    lz_decompress_dispatch(gUnk_084E9E68, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C3208, (void *)0x06006280);
    lz_decompress_dispatch(gUnk_084C37A4, (void *)0x06006800);
    lz_decompress_dispatch(gUnk_084C3990, (void *)0x06006C00);
    lz_decompress_dispatch(gUnk_084C48B4, (void *)0x06007400);
    lz_decompress_dispatch(gUnk_084C4A34, (void *)0x06007600);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF46C, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EFD74, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F08F0, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F1A10, REG_BG3CNT, 0x200);
    CpuFastSet(gUnk_084F30E0, (void *)0x05000000, 0x70);
    CpuFastSet(gUnk_0850DEF8, (void *)0x05000200, 0x40);
    CpuFastSet(gUnk_0850DD18, (void *)0x05000380, 8);
    CpuFastSet(gUnk_0850DD18 + 0x10, (void *)0x050003A0, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
    zero = 0;
    CpuFastSet(&zero, gUnk_03002C30, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    gUnk_03000440.unk44 = 0;
    gUnk_03000440.unk46 = 0;
    medal_page_draw_icon();
    medal_page_draw_kind_name();
    medal_page_draw_name();
    medal_page_draw_level();
    medal_page_init_medal_arrows();
    sub_0800AB0C();
    sub_0800ABA4();
    sub_0800AED0();
    sub_0800AF0C();
    sub_0800AF64();
    set_blend_effect_mode(5, 0x3F, 0x20);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

