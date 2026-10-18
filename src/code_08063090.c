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

void render_battle_medal_names(u8 start)
{
    s32 i, j;
    s32 n;
    u8 *p = &gUnk_03006F74->filler2E[2];
    if (*p > 3)
        n = 4;
    else
        n = *p;
    i = 0;
    while (i < n)
    {
        u16 v;
        u16 *dst;
        for (j = 0; j <= 10; j++)
            gUnk_03002C30[i * 10 + 12 + j].unk0 &= 0xBFFF;
        for (j = 0; j <= 10; j++)
        {
            gUnk_03006F74->unk58[j] = gUnk_03000BE0[gUnk_03006F74->fillerB0[i + start]].unkA[j];
            if (gUnk_03006F74->unk58[j] == 0xFE)
                break;
        }
        render_text_sprites_08040DB8(gUnk_03006F74->unk58, i * 10 + 12, 6, i * 2 + 3, 10, 13, 1, 1);
        v = gUnk_03006F74->unk36 + (gUnk_03000BE0[gUnk_03006F74->fillerB0[i + start]].unk1 * 4 + 1);
        v |= 0x6000;
        dst = (u16 *)(VRAM + (((REG_BG1CNT >> 8) & 0x1F) << 11)) + 3 + (i * 2 + 3) * 32;
        *dst = v;
        dst++;
        *dst = v + 1;
        dst += 31;
        dst[0] = v + 2;
        dst[1] = v + 3;
        i++;
    }
}

void sub_08064C30(void)
{
    gGameSubState = 1;
}

void sub_08064C3C(void)
{
    gUnk_08483EB4[gGameSubState]();
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_08064C7C(void)
{
    gUnk_03006F74->filler2E[0] = 0;
    gUnk_03006F74->filler2E[1] = 0;
    gGameSubState++;
}

void sub_08064CA0(void)
{
    u32 zero;
    u32 z = 0;
    s32 i;
    u32 n;
    zero = z;
    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    clear_battle_sprite_slot(0, 0x80);
    *(u16 *)PLTT = z;
    n = 0;
    for (i = 0; i < 30; i++)
    {
        if (gUnk_03000BE0[i].unk0 & 0x80)
        {
            gUnk_03006F74->fillerB0[n] = i;
            n++;
        }
    }
    gUnk_03006F74->filler2E[2] = n;
    if (gUnk_03000584 != 2)
    {
        gGameState = 6;
        gGameSubState = 0;
    }
    else
    {
        reset_bg_scroll();
        REG_DISPCNT = 0x60;
        gGameSubState++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064D3C);
INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08064EFC);

void sub_08065020(void)
{
    struct Unk_03000440 *s = &gUnk_03000440;
    if (s->unk84 <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, 32 - s->unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - s->unk84 * 4, 0xFFFF);
        s->unk84++;
    }
    else
    {
        gUnk_03006F74->filler4C[0] = 0;
        text_window_init(1, 0, 0);
        gUnk_03006F74->unk6 = 0;
        gGameSubState++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08065090);

void sub_08065348(void)
{
    if (game_state_execute_handler_a())
    {
        struct Unk_03000440 *s = &gUnk_03000440;
        if (s->unk84 <= 8)
        {
            blend_obj_palettes_to_color_0803F684(0, s->unk84 * 4, 0xFFFF);
            blend_obj_palettes_to_color_0803F998(0, s->unk84 * 4, 0xFFFF);
            s->unk84++;
        }
        else
        {
            REG_DISPCNT &= ~0x200;
            gGameState = 6;
            gGameSubState = 0;
        }
    }
}

void sub_080653B4(void)
{
    if (game_state_execute_handler_a())
    {
        struct Unk_03000440 *s = &gUnk_03000440;
        if (s->unk84 <= 8)
        {
            blend_obj_palettes_to_color_0803F684(0, s->unk84 * 4, 0xFFFF);
            blend_obj_palettes_to_color_0803F998(0, s->unk84 * 4, 0xFFFF);
            s->unk84++;
        }
        else
        {
            REG_DISPCNT &= ~0x200;
            clear_battle_sprite_slot(0, 0x80);
            dispatch_by_index_0476e8(2);
        }
    }
}

void sub_08065418(void)
{
    u32 r = 1;
    if (gUnk_03006F74->filler4C[0])
    {
        if (game_state_execute_handler_a())
        {
            gUnk_03006F74->filler4C[0] = 0;
            text_window_init(1, 0, 0);
        }
    }
    else if (run_message(gUnk_08485788[15]))
        r = 0;
    if (r == 0 && KEYS_LO(gNewKeys) & 3)
    {
        sub_0803FB0C();
        gGameSubState = 5;
    }
}

void sub_08065484(void)
{
    u32 r = 1;
    u32 sel;
    if (gUnk_03006F74->filler4C[0])
    {
        if (game_state_execute_handler_a())
        {
            gUnk_03006F74->filler4C[0] = 0;
            text_window_init(1, 0, 0);
        }
    }
    else if (run_message(gUnk_08485788[14]))
        r = 0;
    if (r == 0 && (r = poll_choice_menu()) != 0)
    {
        u32 c = r & 0xF0;
        if (c)
        {
            gUnk_03006F74->filler4C[0] = 1;
            gGameSubState = 5;
        }
        else if (gMoney <= 99)
        {
            gGameSubState = 8;
            gUnk_03006F74->unk3A = 0xB4;
            gUnk_03006F74->filler4C[0] = 1;
        }
        else
        {
            gMoney -= 100;
            gUnk_030017EC = gUnk_03006F74->fillerB0[gUnk_03006F74->filler2E[0] + gUnk_03006F74->filler2E[1]];
            gUnk_03000440.unk84 = c;
            gGameSubState = 6;
        }
    }
}

void init_blend_effect(void *state, u8 a, u8 b, s8 c, u16 mode)
{
    struct BlendEffect *s = state;
    u16 zero = 0;
    vu16 *r;
    s->mode = mode;
    s->unk2 = a;
    s->unk3 = b;
    s->unk5 = c;
    REG_BLDCNT = mode | 0x3F;
    r = &REG_BLDALPHA;
    *r = zero;
    r++;
    *r = s->unk2;
}

u32 blend_fade_step_08065598(void *state)
{
    struct BlendEffect *s = state;
    u32 done = 0;
    if (s->unk5 == 0)
    {
        done = 1;
    }
    else
    {
    REG_BLDCNT = s->mode | 0x3F;
    REG_BLDALPHA = done;
    REG_BLDY = s->unk2;
    if (++s->unk4 >= s->unk3)
    {
        s->unk4 = 0;
        if (s->unk5 > 0 && s->unk2 > 0xF)
        {
            s->unk5 = 0;
            done = 1;
        }
        if (s->unk5 < 0 && s->unk2 == 0)
        {
            s->unk5 = 0;
            done = 1;
        }
        if (done == 0)
            s->unk2 += s->unk5;
    }
    }
    return done;
}

void sub_08065618(void)
{
    gUnk_03006F74->filler7E[1] = sub_08074B68();
    text_window_init(1, 0, 0);
    gUnk_03006F74->unk8 = 0;
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_08063090", battle_cutscene_dispatch);

void sub_08065894(void)
{
    if (run_message(gUnk_08485BD8[gUnk_03006F74->unk8 ? 7 : 6]) && KEYS_LO(gNewKeys) & 1)
    {
        play_sound_effect(0xD);
        if ((s32)++gUnk_03006F74->unk8 > 1)
        {
            gUnk_03000440.unk84 = 0;
            gUnk_03000440.unk1B = 0;
            gGameSubState--;
        }
        else
            sub_0803FB0C();
    }
}

void sub_08065908(void)
{
    if (game_state_execute_handler_a())
        dispatch_by_index_0476e8(8);
}

void fade_transition_and_input_check(void)
{
    if (run_message(gUnk_08485BD8[gUnk_03006F74->unk8 ? 5 : 4]))
    {
        struct Unk_03006F74 *w = gUnk_03006F74;
        if (w->unk8 == 0)
        {
            gGameSubState++;
            w->unk3A = w->unk8;
        }
        else if (KEYS_LO(gNewKeys) & 1)
        {
            play_sound_effect(0xD);
            gUnk_03000440.unk84 = 0;
            gUnk_03000440.unk1B = 0;
            gGameSubState -= 2;
        }
    }
}

void multiplayer_battle_sync_update(void)
{
    struct Unk_03006F74 *w;
    u8 *ready;
    u32 zero;
    struct Unk_03005010 *link;

    if (!(gUnk_03005010.unk0 & 0xF00) && !(gFrameCounter & 0xF))
        serial_link_init();
    sub_08002190();
    init_multiplayer_id();
    link = &gUnk_03005010;
    w = gUnk_03006F74;
    ready = &w->unk49;
    link->unk6 = *ready | 0xFF00;
    zero = 0;
    if (link->unk8[gUnk_03000B90][1] == 0xFF01)
    {
        if (link->unk8[gUnk_03000B90 == 0][1] == 0xFF01)
        {
            if (gUnk_03000B90 <= 1)
            {
                gGameSubState++;
                w->unk3A = zero;
                gUnk_03005030 = -1;
                return;
            }
            sub_0803FB0C();
            gUnk_03006F74->unk8 = 1;
            gGameSubState--;
            link->unk6 = zero;
        }
    }
    else if ((link->unk0 & 3) == 3 && (u16)(link->unk8[gUnk_03000B90 == 0][1] + 0x100) <= 1)
    {
        link->unk6 = 0xFF01;
        *ready = 1;
        return;
    }
    if (++gUnk_03006F74->unk3A > 300)
    {
        sub_0803FB0C();
        gUnk_03006F74->unk8 = 1;
        gGameSubState--;
        gUnk_03005010.unk6 = 0;
    }
    else if (gUnk_03006F74->unk3A > 0x10C)
    {
        if (gUnk_03005010.unk8[gUnk_03000B90 == 0][1] == 0xFF00)
            gUnk_03006F74->unk3A = 0;
        else
            gUnk_03005010.unk6 = 0;
    }
}

void handle_battle_fade_transition(void)
{
    if (gUnk_03000B90 > 1)
    {
        sub_0803FB0C();
        gUnk_03006F74->unk8 = 1;
        gGameSubState -= 2;
    }
    else if (gUnk_03005010.unk0 & (1 << gUnk_03000B90))
    {
        gGameSubState++;
    }
    else
    {
        sub_0803FB0C();
        gUnk_03006F74->unk8 = 1;
        gGameSubState -= 2;
    }
}

void sub_08065B68(void)
{
    if (game_state_execute_handler_a())
        dispatch_by_index_0476e8(7);
}

void dispatch_battle_cutscene_substate(void)
{
    struct FuncTable8 t = gUnk_080AFB10;
    t.f[gGameSubState]();
}

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
