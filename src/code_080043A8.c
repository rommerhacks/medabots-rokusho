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
    toggle_sprite_pair_visibility();
    dispatch_game_substate_handler_08006824();
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
    toggle_sprite_pair_visibility();
    dispatch_game_substate_handler_08006824();
    battle_update_medabot_display();
    sub_08006F14();
    if (sub_080068EC() || sub_08006980() || sub_08006A00() || sub_08006A98() || sub_08006B30() || sub_08006BC8()
        || sub_08006C64())
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
        r = sub_08006F34();
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
    toggle_sprite_pair_visibility();
    dispatch_game_substate_handler_08006824();
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
    toggle_sprite_pair_visibility();
    dispatch_game_substate_handler_08006824();
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
    toggle_sprite_pair_visibility();
    dispatch_game_substate_handler_08006824();
    battle_update_medabot_display();
    sub_08006F14();
    set_blend_effect_mode(6, 0x3F, 0x20);
    gGameSubState++;
}

void medabot_detail_open_info_fade(void)
{
    medabots_scroll_bg3();
    sub_08006764();
    toggle_sprite_pair_visibility();
    dispatch_game_substate_handler_08006824();
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
        sub_080070F0();
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
    battle_setup_bot_entry();
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
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08004AF8);

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
    gUnk_03005308 = c;
    sub_08047414(obj, (u8 *)gUnk_03002414, (u32)gUnk_083D1BF8, (u32)b);
    obj->unk8 = (u32)b;
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

    obj->unk8 = 0x020260D0;
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

// guess: icon left of detail row 0-4 (Medal, head, arms, legs); a != 0 draws the alternate (highlighted?) tile.
void sub_08006238(u32 a)
{
    if (a == 0)
        fill_tilemap_rect_08042698(2, 2, 14, 9, REG_BG1CNT, 0xC370);
    else
        fill_tilemap_rect_08042698(2, 2, 14, 9, REG_BG1CNT, 0xC384);
}

void sub_08006284(u32 a)
{
    if (a == 0)
        fill_tilemap_rect_08042698(2, 2, 14, 11, REG_BG1CNT, 0xC374);
    else
        fill_tilemap_rect_08042698(2, 2, 14, 11, REG_BG1CNT, 0xC388);
}

void sub_080062D0(u32 a)
{
    if (a == 0)
        fill_tilemap_rect_08042698(2, 2, 14, 13, REG_BG1CNT, 0xC378);
    else
        fill_tilemap_rect_08042698(2, 2, 14, 13, REG_BG1CNT, 0xC388);
}

void sub_0800631C(u32 a)
{
    if (a == 0)
        fill_tilemap_rect_08042698(2, 2, 14, 15, REG_BG1CNT, 0xC37C);
    else
        fill_tilemap_rect_08042698(2, 2, 14, 15, REG_BG1CNT, 0xC388);
}

void sub_08006368(u32 a)
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

INCLUDE_ASM("asm/nonmatching/code_080043A8", decompress_sprite_from_game_state);
INCLUDE_ASM("asm/nonmatching/code_080043A8", setup_battle_sprite_from_game_state);
INCLUDE_ASM("asm/nonmatching/code_080043A8", setup_battle_cursor_sprites);
INCLUDE_ASM("asm/nonmatching/code_080043A8", toggle_sprite_pair_visibility);
INCLUDE_ASM("asm/nonmatching/code_080043A8", init_scene_state);
INCLUDE_ASM("asm/nonmatching/code_080043A8", setup_scene_with_link_check);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006764);
INCLUDE_ASM("asm/nonmatching/code_080043A8", dispatch_game_substate_handler_08006824);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_080068EC);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006980);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006A00);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006A98);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006B30);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006BC8);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006C64);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006E08);
INCLUDE_ASM("asm/nonmatching/code_080043A8", battle_update_medabot_display);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006F14);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08006F34);
INCLUDE_ASM("asm/nonmatching/code_080043A8", assign_medal_to_team_slot);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_080070F0);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_0800712C);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_0800725C);
INCLUDE_ASM("asm/nonmatching/code_080043A8", team_select_confirm_pick);
INCLUDE_ASM("asm/nonmatching/code_080043A8", battle_play_alert_sound);
INCLUDE_ASM("asm/nonmatching/code_080043A8", check_target_not_in_battle_list);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007480);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_0800750C);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007540);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007584);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_080075AC);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007834);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007868);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007964);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007998);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_080079CC);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007A04);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007BD8);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007BFC);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007C20);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007C4C);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007D04);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007D28);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007DDC);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08007E38);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_0800801C);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08008050);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08008084);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_080080C8);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_080081BC);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08008200);
INCLUDE_ASM("asm/nonmatching/code_080043A8", sub_08008234);
