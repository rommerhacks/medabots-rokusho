#include "global.h"

void sub_08063090(void)
{
    if (blend_fade_step_08065598(gUnk_03006F74->unk50))
    {
        gGameSubState++;
        gUnk_03006F74->unk3C = 0x258;
        text_window_init(1, 0, 1);
    }
    load_medapart_sprite_animation(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0);
}

void sub_080630DC(void)
{
    struct Unk_03005010 *s;
    struct Unk_03006F74 *w;
    u16 a, b;

    run_message(gUnk_08485BD8[15]);
    s = &gUnk_03005010;
    w = gUnk_03006F74;
    s->unk6 = w->unk31 | (w->unk33 << 8) | 0x4000;
    a = s->unk8[0][1];
    b = s->unk8[1][1];
    if ((a & 0xC000) == 0x4000 && (b & 0xC000) == (a & 0xC000))
    {
        if (gUnk_03000B90)
        {
            w->unk32 = a & 0x7F;
            gUnk_03006F74->unk34 = (a >> 8) & 3;
        }
        else
        {
            w->unk32 = b & 0x7F;
            gUnk_03006F74->unk34 = (b >> 8) & 3;
        }
        init_scene_rendering_context(1);
        sub_08062A74(gUnk_03006F74->unk32 * 4 + gUnk_03006F74->unk34, 1);
        render_text_string_to_sprites(gUnk_03000440.unk9E + 0x14, 0x10, 0xE, 0xA, 0x10, 0xD, 0, 1);
        text_window_init(1, 0, 1);
        gGameSubState++;
    }
    load_medapart_sprite_animation(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0);
}

void sub_080631DC(void)
{
    run_message(gUnk_08485BD8[19]);
    update_animated_tilemap();
    load_medapart_sprite_animation(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0);
    load_medapart_sprite_animation(gUnk_03006F74->unk32, gUnk_03006F74->unk34, 1);
    if ((s16)--gUnk_03006F74->unk3C < 0)
    {
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
        reduce_medapart_stat(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 1);
        medapart_add_quantity(gUnk_03006F74->unk32, gUnk_03006F74->unk34, 1);
        CpuFastSet((void *)0x05000200, gPaletteBackup, 0x100);
        play_sound_effect(0x4B);
    }
}

void sub_08063284(void)
{
    struct Unk_03000440 *g = &gUnk_03000440;
    u8 *t = &g->unk84;

    if (*t <= 0x40)
    {
        blend_obj_palettes_to_color_0803F998(0x7FFF, *t >> 1, 0xFF);
        (*t)++;
    }
    else
    {
        gUnk_03006F74->unk3C = 0;
        *t = 0;
        gGameSubState++;
    }
    load_medapart_sprite_animation(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0);
    load_medapart_sprite_animation(gUnk_03006F74->unk32, gUnk_03006F74->unk34, 1);
    update_animated_tilemap();
}

void sub_080632FC(void)
{
    struct Unk_03006F74 *w = gUnk_03006F74;
    s32 n;
    u16 zero;
    vu16 v;

    n = 16 - (s16)w->unk3C++;
    if (n != 0)
    {
        REG_BLDCNT = 0xE50;
        REG_BLDALPHA = ((16 - n) << 8) | n;
        REG_BLDY = 8;
        load_medapart_sprite_animation(w->unk31, w->unk33, 0);
        load_medapart_sprite_animation(gUnk_03006F74->unk32, gUnk_03006F74->unk34, 1);
        if (n == 1)
            clear_battle_sprite_slot(0, 0x80);
    }
    else
    {
        n = w->unk31;
        w->unk31 = w->unk32;
        zero = 0;
        gUnk_03006F74->unk32 = n;
        n = gUnk_03006F74->unk33;
        gUnk_03006F74->unk33 = gUnk_03006F74->unk34;
        gUnk_03006F74->unk34 = n;
        init_scene_rendering_context(0);
        init_scene_rendering_context(1);
        gUnk_03006F74->unk3C = zero;
        gGameSubState++;
        v = 0x200;
        CpuSet((void *)&v, gUnk_03002414->unkB84, 0x01000200);
    }
    update_animated_tilemap();
}

void sub_080633E4(void)
{
    u8 buf[0x20];
    s32 i;
    u16 *a, *b;
    u32 zero, one;

    a = (u16 *)0x0202F880;
    b = gPaletteBackup;
    for (i = 3; i >= 0; i--)
    {
        CpuFastSet(b, buf, 8);
        CpuFastSet(a, b, 8);
        CpuFastSet(buf, a, 8);
        a += 16;
        b += 16;
    }
    gGameSubState++;
    gUnk_03006F74->unk3C = (zero = 0, one = 1);
    clear_battle_sprite_slot(0, 0x80);
    sub_08062A74(gUnk_03006F74->unk31 * 4 + gUnk_03006F74->unk33, 0);
    sub_08062A74(gUnk_03006F74->unk32 * 4 + gUnk_03006F74->unk34, 1);
    render_text_string_to_sprites(gUnk_03000440.unk9E, 0, 0, 10, 16, 13, zero, one);
    render_text_string_to_sprites(gUnk_03000440.unk9E + 0x14, 16, 14, 10, 16, 13, zero, one);
    play_sound_effect(0x2A);
    update_animated_tilemap();
}

void update_fade_in_blend_effect(void)
{
    struct Unk_03006F74 *w = gUnk_03006F74;
    s32 n = (s16)w->unk3C++;

    if (n <= 16)
    {
        blend_obj_palettes_to_color_0803F998(0x7FFF, 0x20, 0xFF);
        REG_BLDCNT = 0xE50;
        REG_BLDALPHA = ((16 - n) << 8) | n;
        REG_BLDY = 8;
    }
    else
    {
        REG_BLDCNT = 0xE10;
        REG_BLDALPHA = ((16 - n) << 8) | n;
        REG_BLDY = 8;
        w->unk3C = 0;
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
    load_medapart_sprite_animation(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0);
    load_medapart_sprite_animation(gUnk_03006F74->unk32, gUnk_03006F74->unk34, 1);
    update_animated_tilemap();
}

void fade_screen_and_update_sprites(void)
{
    struct Unk_03000440 *g = &gUnk_03000440;
    u8 *t = &g->unk84;

    if (*t <= 0x40)
    {
        blend_obj_palettes_to_color_0803F998(0x7FFF, 0x20 - (*t >> 1), 0xFF);
        (*t)++;
    }
    else
    {
        CpuFastSet(gUnk_080AFA4C, (void *)0x05000300, 8);
        CpuFastSet(gUnk_080AFA4C, gPaletteBackup + 0x80, 8);
        *t = 0;
        gGameSubState++;
        gUnk_03006F74->unk3A = 0x280;
    }
    load_medapart_sprite_animation(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0);
    load_medapart_sprite_animation(gUnk_03006F74->unk32, gUnk_03006F74->unk34, 1);
    update_animated_tilemap();
}

void init_medapart_detail_view(void)
{
    load_medapart_sprite_animation(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0);
    load_medapart_sprite_animation(gUnk_03006F74->unk32, gUnk_03006F74->unk34, 1);
    update_scroll_animation_tiles();
    if (gUnk_03006F74->unk3A == 0)
    {
        gUnk_03002C30[0x21].unk0 = 0xC000;
        gUnk_03002C30[0x21].unk1C = 2;
        gUnk_03002C30[0x21].unk2 = 0x28;
        gUnk_03002C30[0x21].unk4 = 0x40;
        gUnk_03002C30[0x21].unkA = 8;
        gUnk_03002C30[0x21].unk6 = 0x2A;
        text_window_init(1, 0, 1);
        gGameSubState++;
    }
}

void menu_confirm_selection_with_fade(void)
{
    load_medapart_sprite_animation(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0);
    load_medapart_sprite_animation(gUnk_03006F74->unk32, gUnk_03006F74->unk34, 1);
    if (run_message(gUnk_08485BD8[gUnk_03006F74->unk33 + 0x14]) && (KEYS_LO(gNewKeys) & 1))
    {
        gUnk_03005010.unk6 = 0xFF07;
        play_sound_effect(0xD);
    }
    if (gUnk_03005010.unk8[0][1] == 0xFF07 || gUnk_03005010.unk8[1][1] == 0xFF07)
    {
        init_blend_effect(gUnk_03006F74->unk50, 0, 0, 1, 0xC0);
        gGameSubState++;
    }
}

void scene_fade_or_transition(void)
{
    if (blend_fade_step_08065598(gUnk_03006F74->unk50))
    {
        clear_battle_sprite_slot(0, 0x80);
        gGameState = 0x14;
        gGameSubState = 0;
    }
    else
    {
        load_medapart_sprite_animation(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0);
        load_medapart_sprite_animation(gUnk_03006F74->unk32, gUnk_03006F74->unk34, 1);
    }
}

void sub_080637D0(void)
{
    struct FuncTable13 t = gUnk_080AFA6C;

    if (gUnk_03000430 == 2)
    {
        u32 v = 0x200;
        CpuFastSet(&v, gUnk_03002414->unkB84, 0x01000100);
    }
    t.f[gGameSubState]();
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08063090", sub_0806384C);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08063D44);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08063D90);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08063E38);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08063F74);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08063FB4);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080642E4);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064360);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080643AC);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064428);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064498);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080644C4);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_0806454C);
INCLUDE_ASM("asm/nonmatching/code_08063090", scene_scroll_with_fade);
INCLUDE_ASM("asm/nonmatching/code_08063090", update_scroll_animation_step);
INCLUDE_ASM("asm/nonmatching/code_08063090", scene_fade_and_scroll_camera);
INCLUDE_ASM("asm/nonmatching/code_08063090", scene_dispatch_and_tick);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064890);
INCLUDE_ASM("asm/nonmatching/code_08063090", process_fade_transition_step);
INCLUDE_ASM("asm/nonmatching/code_08063090", dispatch_fade_substate);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064A74);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064A94);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064AB4);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064AD4);
INCLUDE_ASM("asm/nonmatching/code_08063090", render_battle_medal_names);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064C3C);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064CA0);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064D3C);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064EFC);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08065020);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08065090);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08065348);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080653B4);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08065418);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08065484);
INCLUDE_ASM("asm/nonmatching/code_08063090", init_blend_effect);
INCLUDE_ASM("asm/nonmatching/code_08063090", blend_fade_step_08065598);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08065618);
INCLUDE_ASM("asm/nonmatching/code_08063090", battle_cutscene_dispatch);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08065894);

void sub_08065908(void)
{
    if (game_state_execute_handler_a())
        dispatch_by_index_0476e8(8);
}

INCLUDE_ASM("asm/nonmatching/code_08063090", fade_transition_and_input_check);
INCLUDE_ASM("asm/nonmatching/code_08063090", multiplayer_battle_sync_update);
INCLUDE_ASM("asm/nonmatching/code_08063090", handle_battle_fade_transition);

void sub_08065B68(void)
{
    if (game_state_execute_handler_a())
        dispatch_by_index_0476e8(7);
}

INCLUDE_ASM("asm/nonmatching/code_08063090", dispatch_battle_cutscene_substate);
INCLUDE_ASM("asm/nonmatching/code_08063090", clear_vram_bg);
INCLUDE_ASM("asm/nonmatching/code_08063090", fade_state_dispatch);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080660AC);
INCLUDE_ASM("asm/nonmatching/code_08063090", handle_battle_menu_selection);
INCLUDE_ASM("asm/nonmatching/code_08063090", update_fade_transition_state_080662CC);
INCLUDE_ASM("asm/nonmatching/code_08063090", advance_fade_and_play_music);
INCLUDE_ASM("asm/nonmatching/code_08063090", init_link_save_and_connect);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_0806641C);
INCLUDE_ASM("asm/nonmatching/code_08063090", setup_dialogue_script_from_rom);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080664F8);
INCLUDE_ASM("asm/nonmatching/code_08063090", advance_substate_with_sound_ch1);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08066560);
INCLUDE_ASM("asm/nonmatching/code_08063090", menu_yes_no_confirmation_handler);
INCLUDE_ASM("asm/nonmatching/code_08063090", dispatch_battle_menu_and_update_counters);
INCLUDE_ASM("asm/nonmatching/code_08063090", compute_difference_div3);
INCLUDE_ASM("asm/nonmatching/code_08063090", battle_ui_setup_partial);
INCLUDE_ASM("asm/nonmatching/code_08063090", u8_difference_divide);
INCLUDE_ASM("asm/nonmatching/code_08063090", copy_block_64bytes);
INCLUDE_ASM("asm/nonmatching/code_08063090", init_fade_color_blend_params);
INCLUDE_ASM("asm/nonmatching/code_08063090", matrix_multiply_4x4_fixed);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_080669B8);
INCLUDE_ASM("asm/nonmatching/code_08063090", fade_init_divide_setup);
INCLUDE_ASM("asm/nonmatching/code_08063090", fade_init_divide_setup_b);
INCLUDE_ASM("asm/nonmatching/code_08063090", update_scene_animation_frame);
