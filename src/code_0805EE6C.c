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

void sub_0805EE94(void)
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
        u32 zero;

        REG_DISPCNT &= 0xFDFF;
        zero = 0;
        CpuFastSet(&zero, (void *)VRAM, 0x01006000);
        switch (gUnk_03000584)
        {
        case 0:
            CpuSet(gUnk_03006F74->unk58, gUnk_03002B70.unk4, 8);
            dispatch_by_index_0476e8(0);
            break;
        case 1:
            CpuSet(gUnk_03006F74->unk58, gUnk_03000BE0[gUnk_030017EC].unkA, 7);
            dispatch_by_index_0476e8(1);
            break;
        case 2:
            CpuSet(gUnk_03006F74->unk58, gUnk_03000BE0[gUnk_030017EC].unkA, 7);
            gGameState = 0x12;
            gGameSubState = 10;
            break;
        }
    }
}

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

void init_fade_screen_setup(void)
{
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03006F74->unk2B = 0;
    gUnk_03006F74->unk2C = 0;
    draw_tilemap_line(gUnk_03006F74->unk2B, -2, 0x10, 4, 2, (REG_BG1CNT >> 8) & 0x1F);
    draw_tilemap_line(gUnk_03006F74->unk2C, -3, 0xF, 6, 2, (REG_BG1CNT >> 8) & 0x1F);
    gUnk_03006F74->unk0 = 0x20;
    REG_BLDY = gUnk_03006F74->unk0 >> 1;
    gGameSubState++;
}

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

void clear_or_fill_bg2_tilemap(s32 a)
{
    u16 buf[0x20];
    u16 *d;
    u16 *s;
    s32 i;

    if (a < 8)
    {
        u32 zero = 0;

        CpuFastSet(&zero, buf, 0x01000010);
        CpuSet((u8 *)VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800 + (7 - a) * 2, buf, (a + 1) & 0x1FFFFF);
        CpuSet((u8 *)VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800 + 0x2C, &buf[0x1D - a], (a + 1) & 0x1FFFFF);
    }
    else
    {
        a -= 8;
        CpuFastSet((u8 *)VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800, buf, 0x10);
        d = &buf[14];
        s = &buf[13 - a];
        for (i = 13; i >= 0; i--)
        {
            if (i <= a)
                *d = buf[0];
            else
                *d = *s--;
            d--;
        }
        d = &buf[15];
        s = &buf[16 + a];
        for (i = 13; i >= 0; i--)
        {
            if (i <= a)
                *d = buf[29];
            else
                *d = *s++;
            d++;
        }
    }
    for (i = 0; i < 20; i++)
        CpuFastSet(buf, (u8 *)VRAM + ((REG_BG1CNT >> 8) & 0x1F) * 0x800 + i * 0x40, 0x10);
}

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

void sub_080609C0(void)
{
    struct Unk_03000440 *s;
    u8 *n;

    update_battle_sprite_animation();
    update_animation_timer();
    s = &gUnk_03000440;
    n = &s->unk84;
    if (*n <= 8)
    {
        blend_obj_palettes_to_color_0803F684(0, *n * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, *n * 4, 0xFFFF);
        (*n)++;
    }
    else
    {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFEFF;
        CpuFastSet((void *)0x02020800, (void *)0x06002800, 0x28);
        if (gGameState == 10)
        {
            gGameState = 4;
            gGameSubState = 0;
        }
        else if (gUnk_03006F74->unk48)
        {
            gUnk_03006D38.unk5 = gUnk_03006F74->unk17;
            dispatch_by_index_0476e8(5);
        }
        else
        {
            dispatch_by_index_0476e8(6);
        }
    }
}

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

void sub_08061080(void)
{
    if (gUnk_03006F74->unk6 == 1)
    {
        struct Unk_03000440 *s;
        u8 *n;

        battle_menu_highlight_icons(gUnk_03006F74->unk19, 8);
        s = &gUnk_03000440;
        n = &s->unk84;
        if (*n <= 8)
        {
            blend_obj_palettes_to_color_0803F684(0, 0x20 - *n * 4, 0x7FFE);
            blend_obj_palettes_to_color_0803F998(0, 0x20 - *n * 4, 0x7FFD);
            (*n)++;
        }
        else
        {
            gUnk_03006F74->unk2 = 0;
            text_window_init(1, 0, 0);
            gUnk_03006F74->unk2 = 0;
            gUnk_03006F74->unk0 = 0;
            gUnk_03006F74->unk6 = 0;
            gGameSubState = 9;
        }
    }
    else
    {
        struct Unk_03000440 *s = &gUnk_03000440;
        u8 *n = &s->unk84;

        if (*n <= 8)
        {
            blend_obj_palettes_to_color_0803F684(0, 0x20 - *n * 4, 0xFFFF);
            blend_obj_palettes_to_color_0803F998(0, 0x20 - *n * 4, 0xFFFF);
            (*n)++;
        }
        else
        {
            gUnk_03006F74->unk2 = 0;
            gUnk_03002C30[8].unk0 |= 0x4000;
            text_window_init(1, 0, 0);
            gUnk_03006F74->unk2 = 0;
            gUnk_03006F74->unk0 = 0;
            gGameSubState++;
        }
    }
}

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

void sub_080611D0(void)
{
    sub_08041C14(8, gFrameCounter, 8);
    if (KEYS_LO(gRepeatKeys) & 0x40)
    {
        play_sound_effect(2);
        if (gUnk_03006F74->unk5 != 0)
            gUnk_03006F74->unk5--;
        else
            gUnk_03006F74->unk5 = 2;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80)
    {
        play_sound_effect(2);
        if (gUnk_03006F74->unk5 <= 1)
            gUnk_03006F74->unk5++;
        else
            gUnk_03006F74->unk5 = 0;
    }
    gUnk_03002C30[8].unk4 = gUnk_03006F74->unk5 * 24 + 0x20;
    if (KEYS_LO(gNewKeys) & 1)
    {
        play_sound_effect(4);
        switch (gUnk_03006F74->unk5)
        {
        case 0:
            gUnk_03006F74->unk2 = 0;
            gGameSubState = 8;
            gUnk_03006F74->unk6 = 0;
            battle_menu_highlight_icons(0, 0);
            break;
        case 1:
            gUnk_03006F74->unk2 = 0;
            gGameSubState = 8;
            gUnk_03006F74->unk6 = 0;
            battle_menu_highlight_icons(0, 0);
            break;
        case 2:
        cancel:
            gUnk_03000440.unk84 = 0;
            gGameSubState = 6;
            break;
        }
    }
    else if (KEYS_LO(gNewKeys) & 2)
    {
        play_sound_effect(5);
        goto cancel;
    }
}

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

void sub_080626A4(void)
{
    s32 i;

    battle_menu_highlight_icons(gUnk_03006F74->unk19, 8);
    clear_battle_sprite_slot(0, 0x80);
    for (i = 0; i < 4; i++)
        gUnk_03002C30[12 + i].unk0 &= 0xBFFF;
    CpuFastSet(gUnk_084E2E58, (void *)0x0202F800, 8);
    CpuFastSet(gUnk_084E2E38, (void *)0x0202F9E0, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x0202F9C0, 8);
    CpuFastSet(gUnk_08488AA4, (void *)0x0202F820, 8);
    CpuFastSet(gUnk_0879671C, (void *)0x0202FA00, 0x80);
    gUnk_03000440.unk84 = 0;
    gUnk_03006F74->unk6 = 1;
    gGameSubState++;
    REG_DISPCNT |= 0x100;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03002C30[7].unk0 = 0xC000;
    gUnk_03002C30[7].unk1C = 2;
    gUnk_03002C30[7].unkA = 1;
    gUnk_03002C30[7].unk6 = 0x1A;
    gUnk_03002C30[7].unk2 = 0x98;
    gUnk_03002C30[7].unk4 = 0;
    divide_by_10000(gUnk_03000440.unk9E, gUnk_03002B70.money);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0, 0x15, 1, 7, 0xF, 1, 0);
}

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

void dispatch_substate_handler(void)
{
    struct FuncTable7 t = gUnk_080AFA20;
    t.f[gGameSubState]();
}

void init_scene_rendering_context(u32 a)
{
    if (a == 0)
    {
        struct Unk_08047414 *obj = (struct Unk_08047414 *)0x02026000;
        u8 *b;
        u8 *c;
        u32 fill;

        sub_0803F624((u8 *)obj, 0xD0, 0);
        b = (u8 *)0x020260D0;
        sub_0803F624(b, 0x820, 0);
        sub_0803F624((u8 *)0x020264E0, 0x820, 0);
        c = (u8 *)0x020268F0;
        sub_0803F624(c, 0x60, 0);
        gUnk_03000430 = 2;
        gUnk_03002414 = (struct Unk_03002414 *)0x02024000;
        fill = a;
        CpuFastSet(&fill, (void *)0x02024000, 0x01000426);
        gUnk_03005308 = c;
        sub_08047414(obj, (u8 *)gUnk_03002414, (u32)gUnk_083D1BF8, (u32)b);
        obj->unk8 = (u32)b;
        load_sprite_animation_by_type(gUnk_03002414->unkB84, obj, gUnk_03006F74->unk31, gUnk_03006F74->unk33,
            0x3C, 0x28, 0xC7, a, 1);
    }
    else
    {
        struct Unk_08047414 *obj = (struct Unk_08047414 *)0x02026000;

        sub_08047414(obj, (u8 *)gUnk_03002414, (u32)gUnk_083D1BF8, 0x020264E0);
        obj->unk8 = 0x020264E0;
        load_sprite_animation_by_type(gUnk_03002414->unkB84, obj, gUnk_03006F74->unk32, gUnk_03006F74->unk34,
            0x3C, 0x28, 0xC7, 4, 2);
    }
}

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

void animate_battle_scroll_tiles(void)
{
    s32 v;
    s32 i;
    u8 *src;
    u8 *dst;

    switch (gUnk_03006F74->unk3A / 128)
    {
    case 0:
        v = gUnk_03006F74->unk3A >> 1;
        break;
    case 1:
        v = gUnk_03006F74->unk3A >> 2;
        break;
    case 2:
        v = gUnk_03006F74->unk3A >> 3;
        break;
    case 3:
        v = gUnk_03006F74->unk3A >> 4;
        break;
    default:
        v = gUnk_03006F74->unk3A >> 5;
        break;
    }
    v &= 3;
    if (--gUnk_03006F74->unk3A < 0)
        gUnk_03006F74->unk3A = 0x3F;
    dst = (u8 *)0x0600E9E2;
    v <<= 9;
    src = (u8 *)0x0600D800 + v;
    for (i = 0; i < 8; i++)
    {
        CpuSet(src, dst, 0xC);
        dst += 0x40;
        src += 0x40;
    }
}

INCLUDE_ASM("asm/nonmatching/code_0805EE6C", update_scroll_animation_tiles);

void fade_update_tilemap_copy(void)
{
    s32 v;
    s32 i;
    u8 *src;
    u8 *dst;

    switch (gUnk_03006F74->unk3A / 128)
    {
    case 0:
    case 1:
        v = gUnk_03006F74->unk3A >> 5;
        break;
    case 2:
        v = gUnk_03006F74->unk3A >> 4;
        break;
    case 3:
        v = gUnk_03006F74->unk3A >> 3;
        break;
    case 4:
        v = gUnk_03006F74->unk3A >> 2;
        break;
    default:
        v = gUnk_03006F74->unk3A >> 1;
        break;
    }
    v &= 3;
    if (--gUnk_03006F74->unk3A < 0)
        gUnk_03006F74->unk3A = 0x3F;
    dst = (u8 *)0x0600E9E2;
    v <<= 9;
    src = (u8 *)0x0600D800 + v;
    for (i = 0; i < 8; i++)
    {
        CpuSet(src, dst, 0xC);
        dst += 0x40;
        src += 0x40;
    }
}

void sub_08062E10(void)
{
    gUnk_03006F74->unk31 = gUnk_03002B68;
    gUnk_03006F74->unk33 = ((u16 *)&gUnk_03002B68)[1];
    gGameSubState++;
}
INCLUDE_ASM("asm/nonmatching/code_0805EE6C", sub_08062E3C);
