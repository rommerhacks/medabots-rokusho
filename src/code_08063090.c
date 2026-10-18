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

void sub_08063D44(void)
{
    if (blend_fade_step_08065598(gUnk_03006F74->unk50))
    {
        CpuFastSet((void *)0x05000200, gPaletteBackup, 0x40);
        gGameSubState++;
        gUnk_03006F74->unk3C = 600;
        text_window_init(1, 0, 1);
    }
}

void sub_08063D90(void)
{
    if (gUnk_03006F74->unk7A)
        run_message(gUnk_08485BD8[24]);
    if (gUnk_03005010.unk8[gUnk_03000B90 == 0][1] == 0xFEDF)
        gGameState = 0x1A;
    else if (gUnk_03005010.unk8[0][1] == 0xFDEF && gUnk_03005010.unk8[1][1] == gUnk_03005010.unk8[0][1])
    {
        gGameSubState++;
        gUnk_03006F74->unk48 = 0;
        if (gUnk_03006F74->unk7A)
            text_window_init(1, 0, 1);
    }
    else
        gUnk_03005010.unk6 = 0xFDEF;
}

static inline s16 link_packet_hi(u16 pkt)
{
    return (pkt & 0xF) << 8 | 0xC000;
}

void sub_08063E38(void)
{
    u8 *buf;
    u8 *p;
    u16 pkt;
    u8 n;
    u16 v;
    struct Unk_03006F74 *s;

    run_message(gUnk_08485BD8[25]);
    s = gUnk_03006F74;
    buf = (u8 *)&s->unk230;
    pkt = gUnk_03005010.unk8[gUnk_03000B90 == 0][1];
    if (s->unk7A)
    {
        n = s->unk48;
        p = buf + n;
        if ((pkt & 0xF000) == 0xC000 && (n & 0xF) == ((pkt >> 8) & 0xF))
        {
            *p = pkt;
            gUnk_03006F74->unk48++;
        }
        if (gUnk_03006F74->unk48 > 0x3F)
            gUnk_03005010.unk6 = 0xFF00;
        else
            gUnk_03005010.unk6 = gUnk_03006F74->unk48 | 0xFE00;
    }
    else
    {
        u16 t = pkt & 0xFF00;
        if (t == 0xFF00)
            gUnk_03005010.unk6 = t;
        if (t == 0xFE00)
        {
            p = buf + (pkt & 0xFF);
            v = *p;
            gUnk_03005010.unk6 = v | link_packet_hi(pkt);
        }
    }
    if (gUnk_03005010.unk8[0][1] == 0xFF00 && gUnk_03005010.unk8[1][1] == gUnk_03005010.unk8[0][1])
    {
        if (gUnk_03006F74->unk7A)
        {
            export_medals_to_buffer(buf);
            sub_08062AB0(buf[1], buf[8]);
        }
        else
            medal_remove_by_id(buf[1]);
        gGameSubState++;
    }
}

void sub_08063F64(void)
{
    gGameSubState++;
}

void sub_08063F74(void)
{
    if (run_message(gUnk_08485BD8[25]))
    {
        struct Unk_03006F74 *s;
        animate_battle_scroll_tiles();
        s = gUnk_03006F74;
        if ((s16)--s->unk3C < 0)
        {
            gGameSubState++;
            s->unk3C = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_08063090", sub_08063FB4);

void sub_080642E4(void)
{
    struct Unk_03006F74 *s;
    s16 t;

    animate_battle_scroll_tiles();
    s = gUnk_03006F74;
    t = --s->unk3C;
    if (t < 0)
    {
        s->unk3A = 0x280;
        gGameSubState++;
        return;
    }
    if (t <= 7)
        gUnk_03002C30[0].unk8 = 0x40 - (s16)s->unk3C * 8;
    else
        gUnk_03002C30[0].unk8 = 1;
    s = gUnk_03006F74;
    if ((s16)s->unk3C > 1)
    {
        gUnk_03002C30[0].unk9 = (s16)s->unk3C * 4 + 0x38;
        gUnk_03002C30[0].unk4 = 0x38 - ((s16)s->unk3C - 2) * 8;
    }
}

void sub_08064360(void)
{
    fade_update_tilemap_copy();
    if (gUnk_03006F74->unk3A == 0)
    {
        text_window_init(1, 0, 1);
        gGameSubState++;
        play_sound_effect(gUnk_03006F74->unk7A ? 0xE : 5);
    }
}

void sub_080643AC(void)
{
    if (run_message(gUnk_08485BD8[gUnk_03006F74->unk7A ? 26 : 27]))
    {
        if (KEYS_LO(gRepeatKeys) & 1)
        {
            play_sound_effect(0xD);
            gGameSubState++;
        }
        else if (gUnk_03005010.unk8[gUnk_03000B90 == 0][1] == 0xFEFF)
            gGameSubState++;
    }
}

void sub_08064428(void)
{
    if (run_message(gUnk_08485BD8[gUnk_03006F74->unk7A ? 26 : 27]))
    {
        gUnk_03005010.unk6 = 0xFEFF;
        if (gUnk_03005010.unk8[0][1] == 0xFEFF && gUnk_03005010.unk8[1][1] == gUnk_03005010.unk8[0][1])
        {
            gGameSubState++;
            init_blend_effect(gUnk_03006F74->unk50, 0, 0, 1, 0xC0);
        }
    }
}

void sub_08064498(void)
{
    if (blend_fade_step_08065598(gUnk_03006F74->unk50))
    {
        gGameState = 0x14;
        gGameSubState = 0;
    }
}

void sub_080644C4(void)
{
    struct FuncTable12 t = gUnk_080AFAA0;

    if (gUnk_03000430 == 2)
    {
        u32 fill = 0x200;
        CpuFastSet(&fill, gUnk_03002414->unkB84, 0x01000100);
    }
    t.f[gGameSubState]();
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_0806454C(void)
{
    u8 *src;
    u8 *dst;
    s32 i;
    u32 size;
    u32 size2;

    clear_battle_sprite_slot(0, 0x80);
    reset_bg_scroll();
    REG_DISPCNT = 0x2060;
    REG_BG2CNT = 0xDB06;
    REG_BG3CNT = 0x1F07;
    dma3_copy_or_decompress(gUnk_087A88CC, gDecompressBuffer);
    dst = (u8 *)0x0600D800;
    src = gDecompressBuffer;
    for (i = 31; i >= 0; i--)
    {
        CpuFastSet(src, dst, 0x10);
        dst += 0x40;
        src += 0x80;
    }
    src = (u8 *)0x02030040;
    for (i = 31; i >= 0; i--)
    {
        CpuFastSet(src, dst, 0x10);
        dst += 0x40;
        src += 0x80;
    }
    src = (u8 *)0x02031000;
    for (i = 31; i >= 0; i--)
    {
        CpuFastSet(src, dst, 0x10);
        dst += 0x40;
        src += 0x80;
    }
    src = (u8 *)0x02031040;
    for (i = 31; i >= 0; i--)
    {
        CpuFastSet(src, dst, 0x10);
        dst += 0x40;
        src += 0x80;
    }
    decompress_and_write_tilemap(gUnk_087A1084, REG_BG3CNT);
    size = dma3_copy_or_decompress(gUnk_087A92D4, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)0x06004000, size);
    size2 = dma3_copy_or_decompress(gUnk_087A046C, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)(size + 0x06004000), size2);
    tilemap_offset_tiles_and_palette(size >> 5, 0, 0x1F);
    CpuFastSet(gUnk_087A034C, (void *)PLTT, 0x48);
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_WIN0H = 0xF0;
    REG_WIN0V = 0x4858;
    REG_WININ = 0x3F3F;
    REG_WINOUT = 0x3B3B;
    gBg2Scroll.y = 0x58;
    gUnk_03006F74->unk3A = 0;
    init_blend_effect(gUnk_03006F74->unk50, 0x10, 0, -1, 0xC0);
    gGameSubState++;
}

void scene_scroll_with_fade(void)
{
    struct Unk_03006F74 *s;
    struct Vec16 *b;

    if (blend_fade_step_08065598(gUnk_03006F74->unk50))
        gGameSubState++;
    b = &gBg2Scroll;
    s = gUnk_03006F74;
    b->y = (u32)(s->unk3A * 16 + 0x1B8) % 512;
    b->x = (s16)(s->unk3A & 0x20) ? 0x100 : 0;
    s->unk3A++;
}

void update_scroll_animation_step(void)
{
    struct Unk_03006F74 *s;
    struct Vec16 *b;

    b = &gBg2Scroll;
    s = gUnk_03006F74;
    b->y = (u32)(s->unk3A * 16 + 0x1B8) % 512;
    b->x = (s16)(s->unk3A & 0x20) ? 0x100 : 0;
    s->unk3A++;
    if (KEYS_LO(gRepeatKeys) & 1)
    {
        init_blend_effect(s->unk50, 0, 0, 1, 0xC0);
        gGameSubState++;
    }
}

void scene_fade_and_scroll_camera(void)
{
    struct Unk_03006F74 *s;
    struct Vec16 *b;

    if (blend_fade_step_08065598(gUnk_03006F74->unk50))
        gGameSubState = 0;
    b = &gBg2Scroll;
    s = gUnk_03006F74;
    b->y = (u32)(s->unk3A * 16 + 0x1B8) % 512;
    b->x = (s16)(s->unk3A & 0x20) ? 0x100 : 0;
    s->unk3A++;
}

void scene_dispatch_and_tick(void)
{
    struct FuncTable4 t = gUnk_080AFAD0;

    t.f[gGameSubState]();
    if (gFrameCounter & 1)
        gBg3Scroll.x++;
}

void sub_08064890(void)
{
    u32 mask = 0;
    s32 i;

    for (i = 0; i < 30; i++)
    {
        if (gUnk_03000BE0[i].unk0 & 0x80)
            mask |= 1 << gUnk_03000BE0[i].unk1;
    }
    gUnk_03006F74->unk48 = 0;
    gUnk_03006F74->unk49 = 0;
    gUnk_03006F74->unk4A = 0;
    gUnk_03006F74->unk4B = 0;
    gUnk_03006F74->unk1C = gUnk_03006F74->unk7A ? mask : 0;
    gGameSubState++;
}

void process_fade_transition_step(void)
{
    struct Unk_03006F74 *s;
    s32 pkt;
    u32 m;
    s32 i;

    pkt = gUnk_03005010.unk8[gUnk_03000B90 == 0][1];
    s = gUnk_03006F74;
    if (!s->unk7A)
    {
        if ((pkt & 0xFC00) == 0xF400)
        {
            m = ((u32)pkt >> 8) & 3;
            s->unk1C |= (pkt & 0xFF) << (m * 8);
            s->unk48 |= 1 << m;
        }
        gUnk_03005010.unk6 = gUnk_03006F74->unk48 | 0xFC00;
    }
    else if ((pkt & 0xFF00) == 0xFC00)
    {
        if (pkt == 0xFC0F)
            gUnk_03005010.unk6 = pkt;
        else
        {
            m = s->unk1C;
            for (i = 0; i <= 3; i++)
            {
                if (!((pkt >> i) & 1))
                {
                    gUnk_03005010.unk6 = (m & 0xFF) | (i << 8 | 0xF400);
                    break;
                }
                m >>= 8;
            }
        }
    }
    if (gUnk_03005010.unk8[0][1] == 0xFC0F && gUnk_03005010.unk8[1][1] == gUnk_03005010.unk8[0][1])
    {
        if (gUnk_03006F74->unk7A)
        {
            gGameState = 0x11;
            gGameSubState = 0;
        }
        else
        {
            gUnk_03002B68 = gUnk_03006F74->unk1C;
            init_game_mode(0);
        }
    }
}

void dispatch_fade_substate(void)
{
    struct FuncTable2 t = gUnk_080AFAE0;

    t.f[gGameSubState]();
}

void sub_08064A44(void)
{
    gUnk_03005010.unk6 = 0xFEDF;
    if (gUnk_03005010.unk8[0][1] == 0xFEDF && gUnk_03005010.unk8[1][1] == gUnk_03005010.unk8[0][1])
    {
        gGameState = 0x14;
        gGameSubState = 0;
    }
}

void sub_08064A74(void)
{
    gGameMode = 2;
    gGameState = 0x1a;
    gGameSubState = 0;
}

void sub_08064A94(void)
{
    gGameMode = 2;
    gGameState = 0x11;
    gGameSubState = 0;
}

void sub_08064AB4(void)
{
    gGameMode = 2;
    gGameState = 0x10;
    gGameSubState = 0;
}

void sub_08064AD4(void)
{
    gGameMode = 2;
    gGameState = 0x14;
    gGameSubState = 0;
}

void render_battle_medal_names(u8 start)
{
    s32 i, j;
    s32 n;
    u8 *p = &gUnk_03006F74->unk30;
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
            gUnk_03006F74->unk58[j] = gUnk_03000BE0[gUnk_03006F74->unkB0[i + start]].unkA[j];
            if (gUnk_03006F74->unk58[j] == 0xFE)
                break;
        }
        render_text_sprites_08040DB8(gUnk_03006F74->unk58, i * 10 + 12, 6, i * 2 + 3, 10, 13, 1, 1);
        v = gUnk_03006F74->unk36 + (gUnk_03000BE0[gUnk_03006F74->unkB0[i + start]].unk1 * 4 + 1);
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
    gUnk_03006F74->unk2E = 0;
    gUnk_03006F74->unk2F = 0;
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
            gUnk_03006F74->unkB0[n] = i;
            n++;
        }
    }
    gUnk_03006F74->unk30 = n;
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

void sub_08064EFC(void)
{
    s8 i;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    for (i = 0; i <= 15; i++)
        gUnk_03006F74->unk58[i] = 0xFE;
    if (gUnk_03000584 == 0) {
        for (i = 0; i <= 15 && gUnk_03006F74->unk58[i] != 0xFE; i++)
            ;
    } else
        render_battle_medal_names(gUnk_03006F74->unk2F);
    CpuFastSet(gUnk_08483AA0, (void *)0x0202FA20, 8);
    CpuFastSet(gUnk_084E2E58, gPaletteBackup, 8);
    CpuFastSet(gUnk_084E2E38, (void *)0x0202F9E0, 8);
    CpuFastSet(gUnk_0850DD18, (void *)0x0202F9A0, 8);
    CpuFastSet(gUnk_08799B98, gPaletteBackupBg, 0x80);
    CpuFastSet(gUnk_080AFAE8, (void *)0x0202F940, 8);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

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
        gUnk_03006F74->unk4C = 0;
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
    if (gUnk_03006F74->unk4C)
    {
        if (game_state_execute_handler_a())
        {
            gUnk_03006F74->unk4C = 0;
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
    if (gUnk_03006F74->unk4C)
    {
        if (game_state_execute_handler_a())
        {
            gUnk_03006F74->unk4C = 0;
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
            gUnk_03006F74->unk4C = 1;
            gGameSubState = 5;
        }
        else if (gMoney <= 99)
        {
            gGameSubState = 8;
            gUnk_03006F74->unk3A = 0xB4;
            gUnk_03006F74->unk4C = 1;
        }
        else
        {
            gMoney -= 100;
            gUnk_030017EC = gUnk_03006F74->unkB0[gUnk_03006F74->unk2E + gUnk_03006F74->unk2F];
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
    gUnk_03006F74->unk7F = sub_08074B68();
    text_window_init(1, 0, 0);
    gUnk_03006F74->unk8 = 0;
    gGameSubState++;
}

void battle_cutscene_dispatch(void)
{
    u8 t;
    u16 r;
    s8 i;

    t = gUnk_03006F74->unk2++;
    r = 0;
    if (!(*(u8 *)&gUnk_03001784 & 2))
    {
        if (run_message(gUnk_08485BD8[gUnk_080AFB08[gUnk_03006F74->unk8]]) && KEYS_LO(gNewKeys) & 1)
        {
            play_sound_effect(0xD);
            if (++gUnk_03006F74->unk8 > 2)
            {
                gUnk_03000440.unk84 = r;
                gUnk_03000440.unk1B = r;
                gGameSubState++;
                *(u8 *)&gUnk_03001784 |= 2;
            }
            else
                sub_0803FB0C();
        }
        return;
    }
    switch (gUnk_03006F74->unk8)
    {
    case 0:
        if (run_message(gUnk_08485BD8[gUnk_080AFB0B[gUnk_03006F74->unk8]]) && KEYS_LO(gNewKeys) & 1)
        {
            play_sound_effect(0xD);
            gUnk_03006F74->unk8++;
            sub_0803FB0C();
            open_choice_menu(1, 0, 7);
        }
        break;
    case 1:
    case 2:
    case 3:
        if (run_message(gUnk_08485BD8[gUnk_080AFB0B[gUnk_03006F74->unk8]]) && poll_choice_menu())
        {
            if (gUnk_03000440.unk2A == 0)
            {
                if (*(u8 *)&gUnk_03001784 & 1)
                {
                    if (++gUnk_03006F74->unk8 <= 3)
                        open_choice_menu(1, 0, 7);
                }
                else
                {
                    if (++gUnk_03006F74->unk8 <= 2)
                        open_choice_menu(1, 0, 7);
                    else
                        gUnk_03006F74->unk8++;
                }
            }
            else
            {
                gUnk_03006F74->unk8 = 0;
                gGameSubState += 2;
            }
            sub_0803FB0C();
        }
        break;
    case 4:
        if (run_message(gUnk_08485BD8[gUnk_080AFB0B[gUnk_03006F74->unk8]]))
        {
            play_song(0);
            play_sound_effect(0);
            eeprom_setup_timer_irq();
            gUnk_03006F74->unk2 = 0;
            gUnk_03006F74->unk8++;
        }
        break;
    case 5:
        if (t > 0x1D && !is_sound_playing_with_lock(4))
        {
            for (i = 0; i < 4; i++)
            {
                r = save_dispatch(0);
                if (r == 0)
                    break;
            }
            play_song(gUnk_03006F74->unk7F);
            gUnk_03006F74->unk8 = r;
            gGameSubState += 3;
            sub_0803FB0C();
            serial_link_init();
        }
        break;
    }
}

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

void clear_vram_bg(void)
{
    u32 zero;
    u32 size;

    zero = 0;
    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    clear_battle_sprite_slot(0, 0x80);
    reset_bg_scroll();
    REG_DISPCNT = 0x60;
    REG_BG1CNT = 0x1E05;
    REG_BG2CNT = 0x1D06;
    REG_BG3CNT = 0x3C07;
    decompress_and_write_tilemap(gUnk_0879C06C, REG_BG1CNT);
    decompress_and_write_tilemap(gUnk_0879C260, REG_BG2CNT);
    decompress_and_write_tilemap(gUnk_0879C3A0, REG_BG3CNT);
    size = dma3_copy_or_decompress(gUnk_0879AC40, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)0x06004000, size);
    CpuFastSet(gUnk_0879AA40, (void *)PLTT, 0x80);
    CpuFastSet(gUnk_084E2E58, (void *)0x050003C0, 8);
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    CpuFastSet(gUnk_0850DEB8, (void *)0x05000200, 8);
    gUnk_03002C30[0].unk0 = 0x8000;
    gUnk_03002C30[0].unk1C = 2;
    gUnk_03002C30[0].unkA = 0xE;
    gUnk_03002C30[0].unk6 = 6;
    gUnk_03002C30[0].unk2 = 0xC;
    gUnk_03002C30[0].unk4 = 0x1C;
    init_blend_effect(gUnk_03006F74->unk50, 0x10, 0, -1, 0xC0);
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03006F74->unk3A = 0;
    gUnk_03006F74->unk5 = 0;
    gUnk_03006F74->unk7A = -1;
    if (sub_08074B68() != 0x18)
        play_song(0x18);
    gGameSubState++;
}

void fade_state_dispatch(void)
{

    if (gUnk_03000B90 != 0)
    {
        switch (gUnk_03006F74->unk3A)
        {
        case 0:
            if ((s32)sub_080440B4() <= 1)
            {
                gUnk_03006F74->unk7B = 0;
                gUnk_03005010.unk6 = 0xFF02;
            }
            else
            {
                gUnk_03006F74->unk7B = -1;
                gUnk_03005010.unk6 = 0xFF03;
            }
            if (gUnk_03005010.unk8[0][1] == 0xFF04)
                gUnk_03006F74->unk3A++;
            break;
        case 1:
            gUnk_03005010.unk6 = 0xFF05;
            if (gUnk_03005010.unk8[0][1] == 0xFF02 || gUnk_03005010.unk8[0][1] == 0xFF03)
            {
                gUnk_03006F74->unk7B = gUnk_03005010.unk8[0][1] != 0xFF02;
                gUnk_03005010.unk6 = 0xFF04;
            }
            if (gUnk_03005010.unk8[0][1] == 0xFF05)
                gUnk_03006F74->unk3A++;
            break;
        case 2:
            gUnk_03005010.unk6 = 0xFF06;
            if (gUnk_03005010.unk8[0][1] == 0xFF06)
                gUnk_03006F74->unk3A++;
            break;
        case 3:
            if (sub_080440D4())
            {
                gUnk_03006F74->unk7C = 0;
                gUnk_03005010.unk6 = 0xFF02;
            }
            else
            {
                gUnk_03006F74->unk7C = -1;
                gUnk_03005010.unk6 = 0xFF03;
            }
            if (gUnk_03005010.unk8[0][1] == 0xFF04)
                gUnk_03006F74->unk3A++;
            break;
        case 4:
            gUnk_03005010.unk6 = 0xFF05;
            if (gUnk_03005010.unk8[0][1] == 0xFF02 || gUnk_03005010.unk8[0][1] == 0xFF03)
            {
                gUnk_03006F74->unk7C = gUnk_03005010.unk8[0][1] != 0xFF02;
                gUnk_03005010.unk6 = 0xFF04;
            }
            if (gUnk_03005010.unk8[0][1] == 0xFF05)
                gUnk_03006F74->unk3A++;
            break;
        case 5:
            gUnk_03005010.unk6 = 0xFF06;
            if (gUnk_03005010.unk8[0][1] == 0xFF06)
                gGameSubState++;
            break;
        }
    }
    else
    {
        switch (gUnk_03006F74->unk3A)
        {
        case 0:
            if (gUnk_03005010.unk8[1][1] == 0xFF02 || gUnk_03005010.unk8[1][1] == 0xFF03)
            {
                gUnk_03006F74->unk7B = gUnk_03005010.unk8[1][1] != 0xFF02;
                gUnk_03005010.unk6 = 0xFF04;
            }
            if (gUnk_03005010.unk8[1][1] == 0xFF05)
                gUnk_03006F74->unk3A++;
            break;
        case 1:
            if (gUnk_03006F74->unk7B == 0 || (s32)sub_080440B4() <= 1)
            {
                gUnk_03005010.unk6 = 0xFF02;
                gUnk_03006F74->unk7B = 0;
            }
            else
            {
                gUnk_03005010.unk6 = 0xFF03;
            }
            if (gUnk_03005010.unk8[1][1] == 0xFF04)
                gUnk_03006F74->unk3A++;
            break;
        case 2:
            gUnk_03005010.unk6 = 0xFF05;
            if (gUnk_03005010.unk8[0][1] == 0xFF05 && gUnk_03005010.unk8[1][1] == 0xFF06)
                gUnk_03005010.unk6 = gUnk_03005010.unk8[1][1];
            if (gUnk_03005010.unk8[0][1] == 0xFF06)
                gUnk_03006F74->unk3A++;
            break;
        case 3:
            if (gUnk_03005010.unk8[1][1] == 0xFF02 || gUnk_03005010.unk8[1][1] == 0xFF03)
            {
                gUnk_03006F74->unk7C = gUnk_03005010.unk8[1][1] != 0xFF02;
                gUnk_03005010.unk6 = 0xFF04;
            }
            if (gUnk_03005010.unk8[1][1] == 0xFF05)
                gUnk_03006F74->unk3A++;
            break;
        case 4:
            if (gUnk_03006F74->unk7C == 0 || sub_080440D4())
            {
                gUnk_03005010.unk6 = 0xFF02;
                gUnk_03006F74->unk7C = 0;
            }
            else
            {
                gUnk_03005010.unk6 = 0xFF03;
            }
            if (gUnk_03005010.unk8[1][1] == 0xFF04)
                gUnk_03006F74->unk3A++;
            break;
        case 5:
            gUnk_03005010.unk6 = 0xFF05;
            if (gUnk_03005010.unk8[0][1] == 0xFF05 && gUnk_03005010.unk8[1][1] == 0xFF06)
                gUnk_03005010.unk6 = gUnk_03005010.unk8[1][1];
            if (gUnk_03005010.unk8[0][1] == 0xFF06)
                gGameSubState++;
            break;
        }
    }
}

void sub_080660AC(void)
{
    if (blend_fade_step_08065598(gUnk_03006F74->unk50))
    {
        gGameSubState++;
        text_window_init(1, 0, 1);
        gUnk_03002C30[0].unk0 |= 0x4000;
    }
}

void handle_battle_menu_selection(void)
{
    if ((gUnk_03005010.unk8[gUnk_03000B90 == 0][1] & 0xFF00) == 0xEF00)
    {
        gUnk_03006F74->unk5 = gUnk_03005010.unk8[gUnk_03000B90 == 0][1];
        gUnk_03006F74->unk7A = 1;
        gGameSubState++;
        play_sound_effect(4);
        gUnk_03002C30[0].unk4 = gUnk_03006F74->unk5 * 16 + 0x1C;
        return;
    }

    sub_08041C14(0, gFrameCounter, 0xC);
    if (gUnk_03006F74->unk5 == 6)
        run_message(gUnk_080AFB30);
    else
        run_message(gUnk_08485BD8[gUnk_080AFB3F[gUnk_03006F74->unk5]]);

    if (gUnk_03006F74->unk5 > 4)
    {
        if (KEYS_LO(gRepeatKeys) & 0xC1)
        {
            gUnk_03006F74->unk5 = gUnk_03006F74->unk5 == 5 ? 1 : 4;
            sub_0803FB0C();
        }
        return;
    }

    if (KEYS_LO(gRepeatKeys) & 0x40)
    {
        gUnk_03006F74->unk5 = gUnk_03006F74->unk5 != 0 ? gUnk_03006F74->unk5 - 1 : 4;
        sub_0803FB0C();
        play_sound_effect(2);
    }
    if (KEYS_LO(gRepeatKeys) & 0x80)
    {
        gUnk_03006F74->unk5 = gUnk_03006F74->unk5 <= 3 ? gUnk_03006F74->unk5 + 1 : 0;
        sub_0803FB0C();
        play_sound_effect(2);
    }
    gUnk_03002C30[0].unk4 = gUnk_03006F74->unk5 * 16 + 0x1C;
    if (KEYS_LO(gRepeatKeys) & 1)
    {
        if (gUnk_03006F74->unk5 == 1 && gUnk_03006F74->unk7B == 0)
        {
            gUnk_03006F74->unk5 = 5;
            sub_0803FB0C();
            play_sound_effect(6);
        }
        else if (gUnk_03006F74->unk5 == 2 && gUnk_03006F74->unk7C == 0)
        {
            play_sound_effect(6);
        }
        else
        {
            gUnk_03006F74->unk7A = 0;
            gUnk_03005010.unk6 = gUnk_03006F74->unk5 | 0xEF00;
            gGameSubState++;
            play_sound_effect(4);
        }
    }
}

void update_fade_transition_state_080662CC(void)
{
    struct Unk_03006F74 *p = gUnk_03006F74;

    if (p->unk7A != 0)
    {
        gUnk_03005010.unk6 = 0xFE0F;
    }
    else if (gUnk_03000B90 != 0)
    {
        if ((gUnk_03005010.unk8[0][1] & 0xFF00) == 0xEF00)
        {
            p->unk5 = gUnk_03005010.unk8[0][1];
            gUnk_03006F74->unk7A = 1;
        }
        else if (gUnk_03005010.unk8[0][1] == 0xFE0F)
        {
            gUnk_03005010.unk6 = 0xFE0F;
        }
    }
    else
    {
        p->unk7A = 0;
        gUnk_03005010.unk6 = gUnk_03006F74->unk5 | 0xEF00;
    }
    if (gUnk_03005010.unk8[1][1] == 0xFE0F)
    {
        if (gUnk_03006F74->unk5 == 4)
        {
            gGameSubState = 8;
            sub_0803FB0C();
        }
        else
        {
            init_blend_effect(gUnk_03006F74->unk50, 0, 0, 1, 0xC0);
            gGameSubState += 2;
        }
    }
}

void advance_fade_and_play_music(void)
{
    if (blend_fade_step_08065598(gUnk_03006F74->unk50) && !is_sound_playing_with_lock(4))
    {
        play_song(0);
        play_sound_effect(0);
        eeprom_setup_timer_irq();
        gGameSubState += 2;
    }
}

void init_link_save_and_connect(void)
{
    s32 i;

    gGameSubState = 0;
    if (gUnk_03006F74->unk4A == 0)
    {
        for (i = 0; i <= 3; i++)
        {
            if (save_dispatch(0) == 0)
                break;
        }
    }
    init_linking_mode();
}

void sub_0806641C(void)
{
    if (blend_fade_step_08065598(gUnk_03006F74->unk50))
    {
        if (gUnk_03006F74->unk5 <= 2)
            init_game_mode(gUnk_080AFB45[gUnk_03006F74->unk5]);
        else
        {
            gGameState = 0x1B;
            gGameSubState = 0;
        }
    }
}

void setup_dialogue_script_from_rom(void)
{
    struct Unk_03006F74 *p = gUnk_03006F74;
    u8 *d;
    const u8 *s;

    d = &p->unk270[0];
    *d = 0xFB;
    d = &p->unk270[1];
    *d = 1;
    d = &p->unk270[2];
    *d = 0xC;
    d = &p->unk270[3];
    *d = 0;
    d = &p->unk270[4];
    s = gUnk_0848564F;
    while ((*d = *s) != 0xFF)
    {
        d++;
        s++;
    }
    *d = 0xFF;
    d[1] = 4;
    d = gUnk_03006F74->unk270;
    if (run_message(d))
    {
        sub_0803FB0C();
        open_choice_menu(1, 0x16, 7);
        gGameSubState++;
    }
}

void sub_080664F8(void)
{
    if (poll_choice_menu())
    {
        if (gUnk_03000440.unk2A == 0)
        {
            gGameSubState++;
            sub_0803FB0C();
        }
        else
            gGameSubState += 3;
    }
}

void advance_substate_with_sound_ch1(void)
{
    if (run_message(gUnk_08485BD8[18]))
    {
        open_choice_menu(1, 0x16, 7);
        gGameSubState++;
    }
}

void sub_08066560(void)
{
    if (poll_choice_menu())
    {
        gGameSubState++;
        sub_0803FB0C();
    }
}

void menu_yes_no_confirmation_handler(void)
{
    const u8 *s = gUnk_08485BD8[15];
    struct Unk_03006F74 *p = gUnk_03006F74;
    u8 *d;
    s32 i;
    u16 a, b;

    d = &p->unk270[0];
    *d = 0xFB;
    d = &p->unk270[1];
    *d = 0;
    d = &p->unk270[2];
    *d = 0xC;
    d = &p->unk270[3];
    *d = 0;
    d = &p->unk270[4];
    i = 0;
    do
    {
        d[i] = s[i];
        i++;
    } while (d[i] != 0xFF);
    d[i] = s[i];
    i++;
    d[i] = s[i];
    if (run_message(gUnk_03006F74->unk270))
    {
        if (gUnk_03000440.unk2A == 0)
            gUnk_03005010.unk6 = 0xFF00;
        else
            gUnk_03005010.unk6 = 0xFF01;
        a = gUnk_03005010.unk8[0][1];
        b = gUnk_03005010.unk8[1][1];
        if ((a & 0xFF00) == 0xFF00 && (b & 0xFF00) == 0xFF00)
        {
            sub_0803FB0C();
            if (a == b)
            {
                init_blend_effect(gUnk_03006F74->unk50, 0, 0, 1, 0xC0);
                gGameSubState = 5;
                gUnk_03006F74->unk4A = a != 0xFF00;
            }
            else
            {
                gGameSubState = 3;
                gUnk_03006F74->unk5 = 6;
            }
        }
    }
}

void dispatch_battle_menu_and_update_counters(void)
{
    struct FuncTable13 t = gUnk_080AFB48;
    t.f[gGameSubState]();
    if (gFrameCounter & 1)
    {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void compute_difference_div3(s32 *a, s32 *b, s32 *c, s32 *d)
{
    s32 x, y, t;

    t = b[0];
    x = a[0];
    c[0] = (t - x) / 3 + x;
    t = b[1];
    y = a[1];
    c[1] = (t - y) / 3 + y;
    d[0] = (b[0] - x) * 2 / 3 + x;
    d[1] = (b[1] - y) * 2 / 3 + y;
}

void ring_points_place_on_hexagon(u32 r)
{
    s32 pts[7][2];
    s32 out[18][2];
    s32 m1[2];
    s32 m2[2];
    s32 *p;
    s32 *q;
    s32 *o;
    s32 i;
    s32 a;

    q = pts[0];
    for (i = 0; i <= 5; i++)
    {
        a = (i << 8) / 6;
        *q++ = gSineTable[a] * r;
        *q++ = gSineTable[a + 0x40] * r;
    }
    *q++ = pts[0][0];
    *q = pts[0][1];

    p = pts[0];
    q = pts[1];
    o = out[0];
    for (i = 0; i <= 5; i++)
    {
        compute_difference_div3(p, q, m1, m2);
        *o++ = *p++;
        *o++ = *p++;
        *o++ = m1[0];
        *o++ = m1[1];
        *o++ = m2[0];
        *o++ = m2[1];
        q += 2;
    }

    o = out[0];
    for (i = 0; i <= 17; i++)
    {
        gUnk_03006F74->unkD0[i].unk2 = *o++ >> 8;
        gUnk_03006F74->unkD0[i].unk4 = *o++ >> 8;
        gUnk_03006F74->unkD0[i].unk6 = 0x1E;
    }
}

u8 u8_difference_divide(u8 a, u8 b, u8 n)
{
    s32 d = (a - b) / n;

    if (d != 0)
        return b + d;
    if (a == b)
        return b;
    if (a <= b)
        return b - 1;
    return b + 1;
}

void copy_block_64bytes(s32 dst[4][4], s32 src[4][4])
{
    s32 i, j;

    for (i = 0; i <= 3; i++)
        for (j = 0; j <= 3; j++)
            dst[i][j] = src[i][j];
}

void matrix_set_identity(void)
{
    s32 m[4][4];

    custom_memset(m, 0, sizeof(m));
    m[0][0] = 0x100;
    m[1][1] = 0x100;
    m[2][2] = 0x100;
    m[3][3] = 0x100;
    copy_block_64bytes(gUnk_03006F74->unk1F0, m);
}

void matrix_multiply_4x4_fixed(s32 dst[4][4], s32 a[4][4], s32 b[4][4])
{
    s32 i, j, k;

    for (i = 0; i <= 3; i++)
        for (j = 0; j <= 3; j++)
        {
            dst[i][j] = 0;
            for (k = 0; k <= 3; k++)
                dst[i][j] += (a[i][k] * b[k][j]) >> 8;
        }
}

void matrix_scale(s32 s)
{
    s32 m[4][4];
    s32 t[4][4];

    custom_memset(m, 0, sizeof(m));
    m[0][0] = s;
    m[1][1] = s;
    m[2][2] = s;
    m[3][3] = 0x100;
    matrix_multiply_4x4_fixed(t, m, gUnk_03006F74->unk1F0);
    copy_block_64bytes(gUnk_03006F74->unk1F0, t);
}

void matrix_translate(s32 x, s32 y, s32 z)
{
    s32 m[4][4];
    s32 t[4][4];

    custom_memset(m, 0, sizeof(m));
    m[0][0] = 0x100;
    m[1][1] = 0x100;
    m[2][2] = 0x100;
    m[3][0] = x;
    m[3][1] = y;
    m[3][2] = z;
    m[3][3] = 0x100;
    matrix_multiply_4x4_fixed(t, gUnk_03006F74->unk1F0, m);
    copy_block_64bytes(gUnk_03006F74->unk1F0, t);
}

void matrix_rotate_xyz(s32 a, s32 b, s32 c)
{
    s32 rx[4][4] = {
        { 0x100, 0, 0, 0 },
        { 0, gSineTable[a + 0x40], gSineTable[a], 0 },
        { 0, -gSineTable[a], gSineTable[a + 0x40], 0 },
        { 0, 0, 0, 0x100 },
    };
    s32 ry[4][4] = {
        { gSineTable[b + 0x40], 0, -gSineTable[b], 0 },
        { 0, 0x100, 0, 0 },
        { gSineTable[b], 0, gSineTable[b + 0x40], 0 },
        { 0, 0, 0, 0x100 },
    };
    s32 rz[4][4] = {
        { gSineTable[c + 0x40], gSineTable[c], 0, 0 },
        { -gSineTable[c], gSineTable[c + 0x40], 0, 0 },
        { 0, 0, 0x100, 0 },
        { 0, 0, 0, 0x100 },
    };
    s32 t1[4][4];
    s32 t2[4][4];

    matrix_multiply_4x4_fixed(t1, rx, gUnk_03006F74->unk1F0);
    matrix_multiply_4x4_fixed(t2, ry, t1);
    matrix_multiply_4x4_fixed(gUnk_03006F74->unk1F0, rz, t2);
}

void ring_points_place_on_circle(u16 phase)
{
    s32 i;

    for (i = 0; i <= 17; i++)
    {
        s32 r = gUnk_03006F74->unkD0[i].unk0;
        u32 idx = ((i << 8) / 18 + phase) & 0xFF;

        gUnk_03006F74->unkD0[i].unk8 = (r * gSineTable[idx]) >> 8;
        gUnk_03006F74->unkD0[i].unkA = (gUnk_03006F74->unkD0[i].unk0 * gSineTable[idx + 0x40]) >> 8;
    }
}

void ring_points_place_on_circle_b(u16 phase)
{
    s32 i;

    for (i = 0; i <= 17; i++)
    {
        s32 r = gUnk_03006F74->unkD0[i].unk0;
        u32 idx = ((i << 8) / 18 + phase) & 0xFF;

        gUnk_03006F74->unkD0[i].unk8 = (r * gSineTable[idx]) >> 8;
        gUnk_03006F74->unkD0[i].unkA = (gUnk_03006F74->unkD0[i].unk0 * gSineTable[idx + 0x40]) >> 8;
    }
}

static inline s32 half(u8 d) { return d >> 1; }
static inline s32 quarter20(u8 c) { return (c >> 2) - 0x14; }

static inline void rings_set_radius(u8 *p, u8 *q)
{
    u32 a = *p, b = *q;
    u8 c = a, d = b;
    if (c < d)
        ring_points_place_on_hexagon((c >> 2) + 0x14);
    else
        ring_points_place_on_hexagon(half(d) - quarter20(c));
}

void update_scene_animation_frame(void)
{
    s32 i, n;

    rng_next_080424B8();
    if (gUnk_03006F74->unk48 == 0)
    {
        gUnk_03006F74->unk48 = rng_next_080424B8();
        if (gUnk_03006F74->unk48 == 0)
            gUnk_03006F74->unk48++;
        gUnk_03006F74->unk49 = gUnk_03006F74->unk48 >> 1;
    }
    else
    {
        gUnk_03006F74->unk48--;
        rings_set_radius(&gUnk_03006F74->unk48, &gUnk_03006F74->unk49);
    }

    gUnk_03006F74->unk8A[0] = (gUnk_03006F74->unk80[0] - (s16)gUnk_03006F74->unk8A[0]) / 16 + gUnk_03006F74->unk8A[0];
    gUnk_03006F74->unk92[0] = (gUnk_03006F74->unk80[1] - (s16)gUnk_03006F74->unk92[0]) / 16 + gUnk_03006F74->unk92[0];
    gUnk_03006F74->unk9A[0] = (gUnk_03006F74->unk80[2] - (s16)gUnk_03006F74->unk9A[0]) / 16 + gUnk_03006F74->unk9A[0];
    gUnk_03006F74->unk8A[1] = ((s16)gUnk_03006F74->unk8A[0] - (s16)gUnk_03006F74->unk8A[1]) / 16 + gUnk_03006F74->unk8A[1];
    gUnk_03006F74->unk92[1] = ((s16)gUnk_03006F74->unk92[0] - (s16)gUnk_03006F74->unk92[1]) / 16 + gUnk_03006F74->unk92[1];
    gUnk_03006F74->unk9A[1] = ((s16)gUnk_03006F74->unk9A[0] - (s16)gUnk_03006F74->unk9A[1]) / 16 + gUnk_03006F74->unk9A[1];
    gUnk_03006F74->unk8A[2] = ((s16)gUnk_03006F74->unk8A[1] - (s16)gUnk_03006F74->unk8A[2]) / 16 + gUnk_03006F74->unk8A[2];
    gUnk_03006F74->unk92[2] = ((s16)gUnk_03006F74->unk92[1] - (s16)gUnk_03006F74->unk92[2]) / 16 + gUnk_03006F74->unk92[2];
    gUnk_03006F74->unk9A[2] = ((s16)gUnk_03006F74->unk9A[1] - (s16)gUnk_03006F74->unk9A[2]) / 16 + gUnk_03006F74->unk9A[2];
    gUnk_03006F74->unk8A[3] = ((s16)gUnk_03006F74->unk8A[2] - (s16)gUnk_03006F74->unk8A[3]) / 16 + gUnk_03006F74->unk8A[3];
    gUnk_03006F74->unk92[3] = ((s16)gUnk_03006F74->unk92[2] - (s16)gUnk_03006F74->unk92[3]) / 16 + gUnk_03006F74->unk92[3];
    gUnk_03006F74->unk9A[3] = ((s16)gUnk_03006F74->unk9A[2] - (s16)gUnk_03006F74->unk9A[3]) / 16 + gUnk_03006F74->unk9A[3];

    gUnk_03006F74->unkA2[4] = u8_difference_divide(gUnk_03006F74->unkA2[3], gUnk_03006F74->unkA2[4], 0x7F);
    gUnk_03006F74->unkA2[3] = u8_difference_divide(gUnk_03006F74->unkA2[2], gUnk_03006F74->unkA2[3], 0x7F);
    gUnk_03006F74->unkA2[2] = u8_difference_divide(gUnk_03006F74->unkA2[1], gUnk_03006F74->unkA2[2], 0x7F);
    gUnk_03006F74->unkA2[1] = u8_difference_divide(gUnk_03006F74->unkA2[0], gUnk_03006F74->unkA2[1], 0x7F);
    gUnk_03006F74->unkA7[4] = u8_difference_divide(gUnk_03006F74->unkA7[3], gUnk_03006F74->unkA7[4], 0x7F);
    gUnk_03006F74->unkA7[3] = u8_difference_divide(gUnk_03006F74->unkA7[2], gUnk_03006F74->unkA7[3], 0x7F);
    gUnk_03006F74->unkA7[2] = u8_difference_divide(gUnk_03006F74->unkA7[1], gUnk_03006F74->unkA7[2], 0x7F);
    gUnk_03006F74->unkA7[1] = u8_difference_divide(gUnk_03006F74->unkA7[0], gUnk_03006F74->unkA7[1], 0x7F);

    matrix_set_identity();
    gUnk_03006F74->unk3C++;
    if ((gUnk_03006F74->unk3C & 0xFF) == 0)
    {
        s32 r = rng_next_080424B8() & 0xFF;
        gUnk_03006F74->unkA2[0] = gSineTable[r] * 5 >> 5;
        gUnk_03006F74->unkA7[0] = gSineTable[r + 0x40] * 5 >> 5;
        gUnk_03006F74->unkA2[0] += 0x78;
        gUnk_03006F74->unkA7[0] += 0x50;
    }
    if ((gUnk_03006F74->unk3C & 0x3F) == 0)
        gUnk_03006F74->unk7E = rng_next_080424B8() & 3;

    switch (gUnk_03006F74->unk7E & 3)
    {
    case 0:
        gUnk_03006F74->unk86[0] += 2;
        gUnk_03006F74->unk86[1] += 1;
        break;
    case 1:
        gUnk_03006F74->unk86[0] -= 2;
        gUnk_03006F74->unk86[1] += 2;
        gUnk_03006F74->unk86[2] += 3;
        break;
    case 2:
        gUnk_03006F74->unk86[0] += 1;
        gUnk_03006F74->unk86[2] += 2;
        break;
    case 3:
        gUnk_03006F74->unk86[0] += 5;
        gUnk_03006F74->unk86[1] += 1;
        gUnk_03006F74->unk86[2] -= 2;
        break;
    }

    if (gUnk_03006F74->unk86[0] < -16)
        gUnk_03006F74->unk86[0] = -16;
    if (gUnk_03006F74->unk86[1] < -16)
        gUnk_03006F74->unk86[1] = -16;
    if (gUnk_03006F74->unk86[2] < -16)
        gUnk_03006F74->unk86[2] = -16;
    if (gUnk_03006F74->unk86[0] > 16)
        gUnk_03006F74->unk86[0] = 16;
    if (gUnk_03006F74->unk86[1] > 16)
        gUnk_03006F74->unk86[1] = 16;
    if (gUnk_03006F74->unk86[2] > 16)
        gUnk_03006F74->unk86[2] = 16;

    {
        struct Unk_03006F74 *v = gUnk_03006F74;
        v->unk80[0] += v->unk86[0];
        v->unk80[1] += v->unk86[1];
        v->unk80[2] += v->unk86[2];
    }

    for (i = 0; i <= 0x47; i = n)
    {
        s32 j = i % 18;
        struct Unk_03006F74 *w;
        s32 x, y;
        s32 px, py, pz;
        struct Unk_03002C30 *spr;
        s32 k;

        if (j == 0)
        {
            matrix_set_identity();
            matrix_rotate_xyz(((s16)gUnk_03006F74->unk8A[i / 18] >> 4) & 0xFF, ((s16)gUnk_03006F74->unk92[i / 18] >> 4) & 0xFF, ((s16)gUnk_03006F74->unk9A[i / 18] >> 4) & 0xFF);
        }
        w = gUnk_03006F74;
        px = w->unkD0[j].unk2;
        py = w->unkD0[j].unk4;
        pz = w->unkD0[j].unk6;
        x = px * w->unk1F0[0][0] + py * w->unk1F0[1][0] + pz * w->unk1F0[2][0] + w->unk1F0[3][0];
        y = px * w->unk1F0[0][2] + py * w->unk1F0[1][2] + pz * w->unk1F0[2][2] + w->unk1F0[3][2];
        x >>= 8;
        y >>= 8;
        {
            struct Unk_03002C30 *b = gUnk_03002C30;
            n = i + 1;
            spr = &b[n];
        }
        k = i / 18 + 1;
        spr->unk2 = w->unkA2[k] + x;
        spr->unk4 = w->unkA7[k] + y;
    }
}

