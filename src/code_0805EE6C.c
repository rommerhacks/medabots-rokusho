#include "global.h"

void sub_0805EE6C(void)
{
    u32 r = is_sound_playing_with_lock(7);
    if (r == 0)
    {
        gUnk_03000440.unk84 = r;
        gGameSubState++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_0805EE94);

void dispatch_options_menu_and_update_counters(void)
{
    gUnk_08483C6C[gGameSubState]();
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void silence_and_clear_vram(void)
{
    u32 zero;

    play_song(0);
    zero = 0;
    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    reset_bg_scroll();
    clear_battle_sprite_slot(0, 0x80);
    REG_DISPCNT = 0x60;
    REG_BLDCNT = 0x2FF;
    REG_BLDY = 0x10;
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", load_battle_background_graphics);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", init_fade_screen_setup);

void update_fade_effect(void)
{
    struct Unk_03006F74 *p = gUnk_03006F74;

    if (p->unk0 != 0)
    {
        REG_BLDY = p->unk0-- >> 1;
    }
    else
    {
        p->unk2 = 0;
        p->unk0 = 0;
        gUnk_03006F74->unk6 = 0;
        gUnk_03006F74->unk48 = 0;
        gUnk_03006F74->unk49 = 0;
        gUnk_03006F74->unk4A = 0;
        gUnk_03006F74->unk4B = 0;
        gUnk_03002C30[0].unk0 |= 0x4000;
        gUnk_03002C30[1].unk0 |= 0x4000;
        gGameSubState++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", options_menu_handler);

void update_fade_transition_state_0805F778(void)
{
    if (gUnk_03006F74->unk0 == 1)
        play_sound_effect(gUnk_03006F74->unk49 ? 5 : 4);
    if (gUnk_03006F74->unk0 != 32)
    {
        gUnk_03006F74->unk0++;
        REG_BLDY = gUnk_03006F74->unk0 >> 1;
    }
    else
    {
        REG_DISPCNT &= 0xFDFF;
        gGameMode = 3;
        gGameState = 2;
        gGameSubState = 0;
        gUnk_03007008 = 1;
    }
}

void advance_substate_on_handler_complete(void)
{
    if (run_message(gUnk_08485788[3]))
        gGameSubState++;
}

void sub_0805F81C(void)
{
    if (poll_choice_menu())
    {
        gUnk_03006F74->unk2 = 0;
        sub_0803FB0C();
        if (gUnk_03000440.unk2A == 0)
            gGameSubState = 9;
        else
            gGameSubState++;
    }
}

void sub_0805F860(void)
{
    if (run_message(gUnk_08485788[16]))
    {
        if (gUnk_03006F74->unk2++ > 60)
            gGameSubState = 13;
    }
}

void sub_0805F898(void)
{
    if (game_state_execute_handler_a())
        gGameSubState = 4;
}

void sub_0805F8B0(void)
{
    if (run_message(gUnk_08485788[4]))
    {
        play_song(0);
        play_sound_effect(0);
        eeprom_setup_timer_irq();
        gUnk_03006F74->unk2 = 0;
        gGameSubState++;
    }
}

void sub_0805F8F0(void)
{
    u8 t = gUnk_03006F74->unk2++;
    u16 err = 0;
    s8 i;

    if (t > 29 && !is_sound_playing_with_lock(4))
    {
        for (i = 0; i <= 3; i++)
        {
            err = save_dispatch(2);
            if (err == 0)
                break;
        }
        if (err == 0)
        {
            sub_0803FB0C();
            gUnk_03006F74->unk2 = err;
            gGameSubState++;
        }
        else
        {
            sub_0803FB0C();
            gUnk_03006F74->unk2 = 0;
            gGameSubState = 12;
        }
    }
}

void sub_0805F974(void)
{
    if (run_message(gUnk_08485788[5]))
    {
        if (gUnk_03006F74->unk2++ > 60)
            gGameSubState = 8;
    }
}

void sub_0805F9AC(void)
{
    if (run_message(gUnk_08485788[6]))
    {
        if (gUnk_03006F74->unk2++ > 60)
            gGameSubState = 8;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", clear_or_fill_bg2_tilemap);

void sub_0805FAF0(void)
{
    gUnk_08483CA4[gGameSubState]();
    if (gFrameCounter & 1)
        gBg3Scroll.y++;
}

void sub_0805FB2C(void)
{
    u32 zero = 0;

    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    sub_08059D04();
    reset_bg_scroll();
    REG_WIN0H = 0xF0;
    REG_WIN0V = 0x80;
    REG_WININ = 0x3F3F;
    REG_WINOUT = 0x2F;
    REG_DISPCNT = 0x2060;
    REG_BLDCNT = 0x2BF;
    play_song(0x12);
    REG_BLDY = 0x10;
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_0805FBA8);

void sub_0805FD60(void)
{
    struct Unk_03006F74 *p = gUnk_03006F74;

    if (p->unk0 != 0)
    {
        REG_BLDY = p->unk0-- >> 1;
    }
    else
    {
        p->unk2 = 0;
        gUnk_03002C30[1].unk0 |= 0x4000;
        gUnk_03002C30[1].unk1A = 0;
        gGameSubState++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_0805FDB4);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_0805FE90);

void sub_0806006C(void)
{
    struct Unk_03006F74 *p = gUnk_03006F74;

    p->unk3A++;
    clear_or_fill_bg2_tilemap(p->unk3A + 8);
    if (++gUnk_03002C30[1].unk1A > 0x47)
        gUnk_03002C30[1].unk1A = 0;
    gUnk_03002C30[1].unk6 = gUnk_080AF968[(u16)(gUnk_03002C30[1].unk1A / 6)];
    p = gUnk_03006F74;
    if (p->unk3A > 13)
    {
        p->unk0 = 0;
        gGameSubState--;
    }
}

void sub_080600E0(void)
{
    if (++gUnk_03002C30[0].unk1A > 0x3F)
        gUnk_03002C30[0].unk1A = 0;
    gUnk_03002C30[0].unk6 = gUnk_080AF980[(gUnk_03002C30[0].unk1A >> 3) & 7] + 0x100;
}

void sub_08060118(void)
{
    gUnk_08483CC4[gGameSubState]();
    if (gFrameCounter & 1)
        gBg3Scroll.y--;
}

void sub_08060154(void)
{
    u32 zero = 0;

    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    reset_bg_scroll();
    clear_battle_sprite_slot(0, 0x80);
    REG_DISPCNT = 0x60;
    REG_BLDCNT = 0x2FF;
    REG_BLDY = 0x10;
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_080601A4);

void sub_08060324(void)
{
    sub_080600E0();
    if (KEYS_LO(gNewKeys) & 1)
    {
        play_sound_effect(4);
        gUnk_03006F74->unk0 = 0;
        gGameSubState++;
    }
}

void sub_0806035C(void)
{
    sub_080600E0();
    if (gUnk_03006F74->unk0 != 32)
    {
        gUnk_03006F74->unk0++;
        REG_BLDY = gUnk_03006F74->unk0 >> 1;
    }
    else
    {
        REG_DISPCNT &= 0xFDFF;
        gGameSubState++;
    }
}

void sub_080603A4(void)
{
    u16 buf[4];
    u32 r = is_sound_playing_with_lock(4);
    u16 ie;
    u32 zero;
    s32 i;

    if (r == 0)
    {
        REG_IME = r;
        ie = REG_IE;
        REG_IE = 0x2020;
        REG_IME = 1;
        zero = r;
        CpuSet(&zero, buf, 0x05000002);
        for (i = 0; i <= 3; i++)
        {
            if (ProgramEepromDwordEx(0, buf) == 0)
                break;
        }
        REG_IE |= ie;
        gGameMode = 3;
        gGameState = 2;
        gGameSubState = 0;
        gUnk_03007008 = 1;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", update_battle_sprite_animation);

void update_animation_timer(void)
{
    s32 t;

    if ((u16)++gUnk_03006F74->unk3A > 0x6D)
        gUnk_03006F74->unk3A = 0;
    t = gUnk_03006F74->unk3A;
    if ((s16)(t % 10) == 0)
        CpuSet(gDecompressBuffer + (gUnk_08483E04[(s16)(t / 10)] + 1) * 480, (void *)0x06004020, 0xF0);
}

void dispatch_battle_bg_substate(void)
{
    gUnk_08483DA0[gGameSubState]();
}

void copy_bg2_tilemap_to_ewram(void)
{
    u32 zero;

    CpuFastSet((void *)0x06002800, (void *)0x02020800, 0x28);
    zero = 0;
    CpuFastSet(&zero, (void *)0x06002800, 0x01000200);
    reset_bg_scroll();
    sub_08059D04();
    REG_DISPCNT = 0x60;
    REG_BLDCNT = 0x2FF;
    REG_BLDY = 0x10;
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", setup_battle_bg_layers);

void sub_08060804(void)
{
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03006F74->unk0 = 8;
    REG_BLDY = gUnk_03006F74->unk0 * 2;
    gUnk_03006F74->unk3A = 0;
    gGameSubState++;
}

void sub_0806086C(void)
{
    struct Unk_03006F74 *p = gUnk_03006F74;

    if (p->unk0 != 0)
    {
        REG_BLDY = --p->unk0 * 2;
    }
    else
    {
        p->unk2 = 0;
        text_window_init(1, 2, 0);
        gGameSubState++;
    }
    update_battle_sprite_animation();
    update_animation_timer();
}

void sub_080608B4(void)
{
    u8 i = gUnk_03006F74->unk17;
    if (run_message(gUnk_08485504[i]))
        gGameSubState++;
    update_battle_sprite_animation();
    update_animation_timer();
}

void sub_080608EC(void)
{
    u8 keys;

    update_battle_sprite_animation();
    update_animation_timer();
    if (sub_0805B7A0() == 0)
    {
        if (!((keys = KEYS_LO(gNewKeys)) & 3))
            return;
        if (gGameState == 10)
        {
            play_sound_effect(5);
            gUnk_03006F74->unk48 = 1;
        }
        else if (keys & 1)
        {
            play_sound_effect(4);
            gUnk_03006F74->unk48 = 1;
        }
        else
        {
            play_sound_effect(5);
            gUnk_03006F74->unk48 = 0;
        }
        gUnk_03006F74->unk0 = 0;
        gGameSubState++;
    }
    else
    {
        sub_0803FB0C();
        gGameSubState = 4;
    }
}

void sub_0806098C(void)
{
    update_battle_sprite_animation();
    update_animation_timer();
    if (game_state_execute_handler_a())
    {
        copy_obj_palette_to_buffer();
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_080609C0);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", battle_menu_highlight_icons);

void copy_text_with_lookup(dst, src, unused, i)
    u8 *dst;
    u8 *src;
    u32 unused;
    u32 i;
{
    do
    {
        dst[i] = src[i];
        i++;
    } while (src[i] != 0xFF);
    dst[i] = src[i];
    i++;
    dst[i] = src[i];
    dst[2] = gUnk_080AFA10[gUnk_03002420];
}

void execute_substate_and_tick_counters(void)
{
    gUnk_08483E10[gGameSubState]();
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_08060C44(void)
{
    gUnk_03006F74->unk5 = 0;
    gUnk_03006F74->unk6 = 0;
    gGameSubState = 14;
}

void sub_08060C60(void)
{
    gGameSubState = 1;
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_08060C6C);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", clear_vram_da80_region);

void sub_08060FD4(void)
{
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    CpuFastSet(gUnk_084E2E58, (void *)0x0202F800, 8);
    CpuFastSet(gUnk_084E2E38, (void *)0x0202F9E0, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x0202F9C0, 8);
    CpuFastSet(gUnk_08488AA4, (void *)0x0202F820, 8);
    CpuFastSet(gUnk_0879671C, (void *)0x0202FA00, 0x80);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_08061080);

void sub_08061180(void)
{
    u8 *buf = gUnk_03006F74->unk270;

    copy_text_with_lookup(buf, gUnk_0848552C);
    if (run_message(buf))
    {
        gUnk_03002C30[8].unk0 |= 0x4000;
        gGameSubState++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_080611D0);

void sub_080612D8(void)
{
    if (game_state_execute_handler_a())
    {
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

void sub_08061300(void)
{
    struct Unk_03000440 *s = &gUnk_03000440;
    u8 *n = &s->unk84;

    if (*n <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, *n * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, *n * 4, 0xFFFF);
        (*n)++;
    }
    else
    {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFBFF;
        REG_DISPCNT &= 0xF7FF;
        clear_battle_sprite_slot(0, 0x80);
        dispatch_by_index_0476e8(3);
    }
}

void sub_08061374(void)
{
    u8 t = gUnk_03006F74->unk2++;

    if (gUnk_03002C30[8].unk8 > 4)
    {
        gUnk_03002C30[8].unk8 -= 4;
        gUnk_03002C30[8].unk9 -= 4;
    }
    else
    {
        gUnk_03002C30[8].unk0 &= 0xBFFF;
    }
    if (t <= 16)
    {
        REG_BLDALPHA = (t << 8) | (16 - t);
    }
    else
    {
        REG_BLDALPHA = 0x1000;
        REG_DISPCNT &= 0xFDFF;
        gUnk_03002C30[8].unk0 &= 0xBFFF;
        sub_0803FB0C();
        gGameSubState++;
    }
    gUnk_03006F74->unk19 = 0;
}

void sub_0806142C(void)
{
    u8 buf[0x30];

    copy_text_with_lookup(buf, gUnk_03006F74->unk5 == 0 ? gUnk_08485551 : gUnk_08485580);
    if (run_message(buf))
        gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_0806146C);

void sub_08061678(void)
{
    u8 t = gUnk_03006F74->unk2--;

    if (gUnk_03002C30[8].unk8 < 0x40)
    {
        gUnk_03002C30[8].unk8 += 4;
        gUnk_03002C30[8].unk9 += 4;
    }
    else
    {
        gUnk_03002C30[8].unk9 = 0x40;
    }
    if (t != 0)
    {
        REG_BLDALPHA = (t << 8) | (16 - t);
    }
    else
    {
        REG_BLDALPHA = 16;
        sub_0803FB0C();
        gGameSubState = 4;
    }
}

void sub_080616F8(void)
{
    u8 *t;

    battle_menu_highlight_icons(gUnk_03006F74->unk19, gFrameCounter * 2);
    t = &gUnk_03006F74->unk48;
    if (*t != 0)
        (*t)--;
    else if (game_state_execute_handler_a())
    {
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_0806174C);

void sub_080617F0(void)
{
    gUnk_08483E8C[gGameSubState]();
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_08061830(void)
{
    reset_bg_scroll();
    gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", setup_bg1_and_decompress_tiles);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", enable_obj_layer_and_load_palette);

void sub_08061D30(void)
{
    struct Unk_03000440 *s = &gUnk_03000440;
    u8 *n = &s->unk84;

    if (*n <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, 32 - *n * 4, 0xFFFE);
        blend_obj_palettes_to_color_0803F998(0, 32 - *n * 4, 0x7FFD);
        (*n)++;
    }
    else
    {
        update_battle_sprite_priority_flags();
        gUnk_03006F74->unk2 = 0;
        gGameSubState++;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", shop_purchase_menu_handler);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", transition_fade_to_battle);

void advance_substate_on_handler_complete_1c(void)
{
    if (run_message(gUnk_08485788[7]))
        gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", shop_complete_transaction);

void sub_080625EC(void)
{
    if (game_state_execute_handler_a())
    {
        if (gUnk_03000440.unk2A == 0)
        {
            clear_sprite_table_mask(0x61, 7);
            clear_sprite_table_mask(0xD, 0x34);
            clear_sprite_table_mask(0x45, 0x1C);
            gGameSubState = 5;
        }
        else
        {
            gGameSubState = 4;
        }
    }
}

void sub_08062638(void)
{
    struct Unk_03000440 *s = &gUnk_03000440;
    u8 *n = &s->unk84;

    if (*n <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, *n * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, *n * 4, 0xFFFF);
        (*n)++;
    }
    else
    {
        struct Unk_03006F74 *p = gUnk_03006F74;
        u8 mode = p->unk19;
        struct ShopSellEntry *l = (struct ShopSellEntry *)0x02040000;
        init_battle_scene(mode, l[p->unk1A + gUnk_02023078].id);
        gGameMode = 0;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_080626A4);

void fade_out_transition_step(void)
{
    struct Unk_03000440 *s = &gUnk_03000440;
    u8 *n = &s->unk84;

    if (*n <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, 32 - *n * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - *n * 4, 0xFFFF);
        (*n)++;
    }
    else
    {
        update_battle_sprite_priority_flags();
        gUnk_03006F74->unk2 = 0;
        gGameState = 12;
        gGameSubState = 4;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", dispatch_substate_handler);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", init_scene_rendering_context);

void load_medapart_sprite_animation(u8 id, u8 kind, u32 which)
{
    struct Unk_08047414 *obj = (struct Unk_08047414 *)0x02026000;
    u8 x, y;

    obj->unk8 = 0x020260D0 + which * 0x410;
    x = gUnk_080AFA3C[which][kind][0];
    y = gUnk_080AFA3C[which][kind][1];
    if (which)
        load_sprite_animation_by_type(gUnk_03002414->unkB84, obj, id, kind, y, x, 0xC7, 4, 6);
    else
        load_sprite_animation_by_type(gUnk_03002414->unkB84, obj, id, kind, y, x, 0xC7, which, 5);
}

void sub_08062A74(u16 id, u8 second)
{
    const u8 *src;
    u8 *dst;
    u32 i;

    src = (const u8 *)gUnk_083BB9CC[0][id];
    dst = gUnk_03000440.unk9E;
    if (second)
        dst += 0x14;
    for (i = 0; i < 20; i++)
    {
        *dst++ = *src++;
        if (*src == 0xFE)
            break;
    }
    *dst = 0xFE;
}

void sub_08062AB0(u32 medal, u32 frame)
{
    struct Unk_03002C30 *s;
    u8 zero;

    lz_decompress_dispatch(gUnk_083AC494[medal][frame], (void *)0x06010000);
    s = gUnk_03002C30;
    zero = 0;
    s->unk0 = 0x8A24;
    if (gUnk_03006F74->unk7A == 0)
        s->unk0 |= 0x4000;
    s->unk2 = 0xB8;
    s->unk4 = 0x38;
    s->unk6 = 0x200;
    s->unkA = zero;
    s->unk1C = zero;
    s->unkB = 0x40;
    s->unk8 = 0x40;
    s->unk9 = 0x40;
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", update_animated_tilemap);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", animate_battle_scroll_tiles);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", update_scroll_animation_tiles);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", fade_update_tilemap_copy);
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_08062E3C);
