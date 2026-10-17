#include "global.h"

int sub_08067160(u8 *s)
{
    int n = 0;
    int r;
    while (s[n] != 0)
        n++;
    r = 0;
    if (n != 1)
        r = n;
    return r;
}

void clear_stack_buffer_64(s32 len, s32 step)
{
    u16 buf[32];
    u32 zero = 0;
    CpuFastSet(&zero, buf, 0x01000010);
    if (step <= 13) {
        u16 tile = *(u16 *)0x0600DD3E;
        int i;
        for (i = 0; i < len; i++) {
            int n = step * 29 / 13;
            if (n - i >= 0)
                buf[n - i] = tile;
        }
    }
    if (buf[0] == 0)
        buf[0] = *(u16 *)0x0600D8C0;
    else
        buf[0] = *(u16 *)0x0600D940;
    CpuFastSet(buf, (void *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x06000400), 0x10);
}

void scroll_tilemap_column(s32 row, s32 step)
{
    u16 buf[32];
    u8 x = gUnk_080AFE96[gUnk_03006F74->unk5];
    if (step <= 14) {
        CpuSet((u8 *)VRAM + ((REG_BG0CNT >> 8) & 0x1F) * 0x800 + x * 2 + 0x100, buf, (30 - x) & 0x1FFFFF);
        CpuSet(buf, (u8 *)VRAM + ((REG_BG0CNT >> 8) & 0x1F) * 0x800 + (x + 1) * 2 + 0x100, (29 - x) & 0x1FFFFF);
    } else {
        int i;
        u16 t;
        CpuFastSet((u8 *)VRAM + ((REG_BG1CNT >> 8) & 0x1F) * 0x800 + row * 64, buf, 0x10);
        buf[31] = *(u16 *)0x0600DD3E | 0x800;
        t = 0;
        for (i = 10; i < 30; i++) {
            if (buf[i] != 0)
                t = buf[31];
            buf[i] = t;
        }
        CpuSet(buf + x, (u8 *)VRAM + ((REG_BG0CNT >> 8) & 0x1F) * 0x800 + x * 2 + 0x100, (30 - x) & 0x1FFFFF);
    }
}

INCLUDE_ASM("asm/nonmatching/code_08067160", render_text_right_aligned);
INCLUDE_ASM("asm/nonmatching/code_08067160", copy_bg_tile_column);
INCLUDE_ASM("asm/nonmatching/code_08067160", bg_tilemap_scroll_up_row);

void init_scene_with_palette_and_song_5(void)
{
    u16 pal[64] = {
        0, 0x6B40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0x5EE0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0x5280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0x4A40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    u32 zero;
    u32 size;
    int i;

    play_song(5);
    zero = 0;
    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    clear_battle_sprite_slot(0, 0x80);
    reset_bg_scroll();
    REG_DISPCNT = 0x6060;
    REG_BG0CNT = 0x1B04;
    decompress_and_write_tilemap(gUnk_087A3CFC, REG_BG0CNT);
    REG_BG0CNT = 0x1F04;
    REG_BG1CNT = 0x1E05;
    REG_BG2CNT = 0x3D06;
    REG_BG3CNT = 0x1C07;
    decompress_and_write_tilemap(gUnk_087A3E64, REG_BG2CNT);
    decompress_and_write_tilemap(gUnk_087A40A0, REG_BG3CNT);
    size = dma3_copy_or_decompress(gUnk_087A1410, (void *)0x02030000);
    CpuFastSet((void *)0x02030000, (void *)0x06004000, (size << 9) >> 11);
    CpuFastSet(gUnk_087A13B0, (void *)0x0202FA00, 0x18);
    CpuFastSet(pal, (void *)0x0202F800, 0x20);
    lz_decompress_dispatch(gUnk_08785F34, (void *)0x06010000);
    CpuFastSet(gUnk_0850DEB8, (void *)0x05000200, 8);
    for (i = 0; i < sizeof(gUnk_03006F74->unkA2); i++) {
        gUnk_03006F74->unkA2[i] = 0x78;
        gUnk_03006F74->unkA7[i] = 0x50;
    }
    for (i = 0; i < sizeof(gUnk_03006F74->unk8A) / sizeof(gUnk_03006F74->unk8A[0]); i++) {
        struct Unk_03006F74 *p = gUnk_03006F74;
        p->unk8A[i] = 0;
        p->unk92[i] = 0;
        p->unk9A[i] = 0;
    }
    gUnk_03006F74->unk3C = 0;
    for (i = 0; i < 0x48; i++) {
        gUnk_03002C30[i + 1].unk0 = 0xC800;
        gUnk_03002C30[i + 1].unk1C = 2;
        gUnk_03002C30[i + 1].unkA = i / 18;
        gUnk_03002C30[i + 1].unk6 = 0x116;
    }
    init_fade_color_blend_params();
    battle_ui_setup_partial(0x32);
    REG_WIN1H = 0xF0;
    REG_WIN1V = 0x1888;
    REG_WIN0H = 0xF0;
    REG_WIN0V = 0x2880;
    REG_WININ = 0x3D3F;
    REG_WINOUT = 0;
    REG_DISPCNT |= 0x100;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    REG_BLDCNT = 0x844;
    REG_BLDALPHA = 0x1004;
    REG_BLDY = 8;
    gUnk_03006F74->unk3A = 0;
    gUnk_03006F74->unk48 = 0;
    gUnk_03006F74->unk49 = 0;
    gUnk_03006F74->unk4A = 0;
    gUnk_03006F74->unk4B = 0;
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_080676DC(void)
{
    struct Unk_03000440 *s;
    u8 *n;
    update_scene_animation_frame();
    s = &gUnk_03000440;
    n = &s->unk84;
    if (*n <= 0x40) {
        blend_obj_palettes_to_color_0803F684(0, 0x20 - (*n / 2), 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 0x20 - (*n / 2), 0xFFFF);
        s->unk84++;
        gUnk_03006F74->unk5 = 0;
    } else
        gGameSubState++;
}

void scene_text_scroll_step(void)
{
    struct PtrTable3 t = gUnk_080AFE9C;
    struct Unk_03006F74 *s;
    update_scene_animation_frame();
    s = gUnk_03006F74;
    if (++s->unk3A > 0xD) {
        if (copy_bg_tile_column(s->unk5, s->unk3A - 0xE)) {
            struct Unk_03006F74 *u = gUnk_03006F74;
            u->unkAC = t.p[u->unk5];
            u->unk3A = 0;
            gGameSubState++;
            gUnk_03006F74->unk7D = sub_08067160((u8 *)*u->unkAC);
        }
    } else
        ((u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + VRAM))[(s->unk3A + 2) * 32] = *(u16 *)0x0600D8C0;
}

void sub_080677E0(void)
{
    int lines;
    update_scene_animation_frame();
    lines = gUnk_0848417C[gUnk_03006F74->unk5];
    if ((u16)gUnk_03006F74->unk3A % 32 == 0) {
        if (lines > gUnk_03006F74->unk3A / 32) {
            render_text_right_aligned(*gUnk_03006F74->unkAC, (gUnk_03006F74->unk3A / 32 + 0x10) & 0x1F);
            if (lines == gUnk_03006F74->unk3A / 32)
                gUnk_03006F74->unk7D = 0;
            else
                gUnk_03006F74->unk7D = sub_08067160((u8 *)*gUnk_03006F74->unkAC);
            gUnk_03006F74->unkAC++;
        } else {
            gGameSubState++;
            gUnk_03006F74->unk3A = -1;
        }
    }
    clear_stack_buffer_64(gUnk_03006F74->unk7D, gUnk_03006F74->unk3A & 0x1F);
    scroll_tilemap_column((gUnk_03006F74->unk3A / 32 + 5) & 0x1F, (gUnk_03006F74->unk3A + 2) & 0x1F);
    if ((gUnk_03006F74->unk3A & 3) == 0)
        gBg1Scroll.y++;
    gUnk_03006F74->unk3A++;
}

void sub_080678DC(void)
{
    update_scene_animation_frame();
    if (bg_tilemap_scroll_up_row(gUnk_03006F74->unk3A++)) {
        gUnk_03006F74->unk3A = 0;
        if (++gUnk_03006F74->unk5 > 2)
            gGameSubState++;
        else {
            gBg1Scroll.y = 0;
            gGameSubState -= 2;
        }
    }
}

void sub_08067938(void)
{
    struct Unk_03006F74 *s;
    update_scene_animation_frame();
    s = gUnk_03006F74;
    if (++s->unk3A > 0xE) {
        gGameSubState++;
        s->unk3E = 0;
        sound_stop_all_with_fade_guard(0xC0);
    } else
        ((u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + VRAM))[(s->unk3A + 2) * 32] = 0;
}

void sub_08067994(void)
{
    update_scene_animation_frame();
    if (gUnk_03006F74->unk3E <= 0xC0) {
        blend_obj_palettes_to_color_0803F684(0, (s16)(gUnk_03006F74->unk3E / 6), 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, (s16)(gUnk_03006F74->unk3E / 6), 0xFFFF);
        gUnk_03006F74->unk3E++;
    } else if (sub_08074FB8() == 0) {
        gGameSubState = 0;
        dispatch_by_index_0476e8(0xC);
    }
}

void dispatch_scene_substate_and_scroll(void)
{
    struct FuncTable7 t = gUnk_080AFEA8;
    t.f[gGameSubState]();
    gBg2Scroll.y--;
}

void sub_08067A48(u8 slot)
{
    gUnk_030017EC = slot;
    gGameMode = 2;
    gGameState = 0x18;
    gGameSubState = 0;
}

INCLUDE_ASM("asm/nonmatching/code_08067160", update_battle_sprite_explosions);
INCLUDE_ASM("asm/nonmatching/code_08067160", init_scene_with_palette_and_song_25);

void decompress_medal_sprite_to_vram(void)
{
    struct Unk_03002C30 *s;
    u8 zero;
    int i;
    int id, fr;

    id = gUnk_03000BE0[gUnk_030017EC].unk1;
    fr = gUnk_03000BE0[gUnk_030017EC].unk8 - 1;
    lz_decompress_dispatch(gUnk_083AC494[id][fr], (void *)0x06010000);
    s = gUnk_03002C30;
    zero = 0;
    s->unk0 = 0xCA04;
    s->unk2 = 0x78;
    s->unk4 = 0x28;
    s->unk6 = 0x200;
    s->unkA = zero;
    s->unk1C = zero;
    s->unkB = 0x40;
    s->unk8 = 0x40;
    s->unk9 = 0x40;
    for (i = 0; i < 16; i++) {
        gUnk_030004DE[i] = ((const u8 *)gUnk_083B6410[gUnk_03000BE0[gUnk_030017EC].unk1])[i];
        if (gUnk_030004DE[i] == 0xFE)
            break;
    }
    render_text_sprites_08040DB8(gUnk_030004DE, 0x14, 5, 10, 10, 1, 1, 0);
    if (gUnk_03000BE0[gUnk_030017EC].unk5 == 100) {
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x0600029A) = (gUnk_03006F74->unk36 + 0x14) | 0x7000;
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x060002DA) = (gUnk_03006F74->unk36 + 0x15) | 0x7000;
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x0600029C) = (gUnk_03006F74->unk36 + 0x16) | 0x7000;
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x060002DC) = (gUnk_03006F74->unk36 + 0x17) | 0x7000;
    } else {
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x0600029A) = (gUnk_03006F74->unk36 + (u8)(gUnk_03000BE0[gUnk_030017EC].unk5 / 10u) * 2) | 0x7000;
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x060002DA) = (gUnk_03006F74->unk36 + (u8)(gUnk_03000BE0[gUnk_030017EC].unk5 / 10u) * 2 + 1) | 0x7000;
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x0600029C) = (gUnk_03006F74->unk36 + (u8)(gUnk_03000BE0[gUnk_030017EC].unk5 % 10u) * 2) | 0x7000;
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x060002DC) = (gUnk_03006F74->unk36 + (u8)(gUnk_03000BE0[gUnk_030017EC].unk5 % 10u) * 2 + 1) | 0x7000;
    }
    render_text_sprites_08040DB8(gUnk_03000BE0[gUnk_030017EC].unkA, 0x1E, 0x11, 10, 10, 2, 0, 0);
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03006F74->unk3A = 0;
    gUnk_03006F74->unk48 = 0;
    gUnk_03006F74->unk49 = 0;
    gUnk_03006F74->unk4A = 0;
    gUnk_03006F74->unk4B = 0;
    gUnk_03006F74->unk5 = 0;
    gGameSubState++;
    gUnk_03000440.unk84 = 0;
}

void sub_080680A4(void)
{
    struct Unk_03000440 *s;
    u8 *n;
    update_battle_sprite_explosions();
    s = &gUnk_03000440;
    n = &s->unk84;
    if (*n <= 8) {
        blend_obj_palettes_to_color_0803F684(0, 0x20 - *n * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 0x20 - *n * 4, 0xFFFF);
        (*n)++;
    } else {
        text_window_init(1, 2, 0);
        gGameSubState++;
    }
}

void sub_08068104(void)
{
    update_battle_sprite_explosions();
    if (run_message(gUnk_08485788[0x11])) {
        int t = (s16)gUnk_03006F74->unk3A++;
        if (t > 0x77) {
            t -= 0x78;
            if (t <= 0x80)
                blend_obj_palettes_to_color_0803F998(0x7FFF, t >> 2, 1);
            else {
                struct Unk_03000BE0 *b = gUnk_03000BE0;
                struct Unk_03000BE0 *m = &b[gUnk_030017EC];
                u8 id = m->unk1;
                lz_decompress_dispatch(gUnk_083AC494[id][m->unk8], (void *)0x06010000);
                gUnk_03006F74->unk3A = 0;
                gGameSubState++;
            }
        }
    }
}

void sub_08068194(void)
{
    int t;
    update_battle_sprite_explosions();
    t = (s16)gUnk_03006F74->unk3A++;
    if (t > 0x3B) {
        t -= 0x3C;
        if (t <= 0x80)
            blend_obj_palettes_to_color_0803F998(0x7FFF, 0x20 - (t >> 2), 1);
        else {
            sub_0803FB0C();
            gGameSubState++;
        }
    }
}

void battle_end_wait_for_confirm(void)
{
    update_battle_sprite_explosions();
    if (run_message(gUnk_08485788[0x12]) && (*(u8 *)&gNewKeys & 1)) {
        init_blend_effect(gUnk_03006F74->unk50, 0, 0, 1, 0xC0);
        gGameSubState++;
    }
}

void advance_fade_and_transition_state(void)
{
    if (blend_fade_step_08065598(gUnk_03006F74->unk50)) {
        gGameMode = 0;
        gGameState = 6;
        gGameSubState = 0x50;
    }
}

void dispatch_battle_end_substate(void)
{
    struct FuncTable7 t = gUnk_080AFEC4;
    t.f[gGameSubState]();
    gBg2Scroll.y++;
}

void dispatch_game_mode_handler(void)
{
    gUnk_08485C48[gGameState]();
}

INCLUDE_ASM("asm/nonmatching/code_08067160", setup_screen_transition_effect_080682CC);
INCLUDE_ASM("asm/nonmatching/code_08067160", setup_screen_transition_effect_080684F0);

// Unused (nothing calls it): copies the saved palette back to PLTT.
void sub_080686D0(void)
{
    DmaSet(3, gUnk_0300002C, PLTT, 0x80000200);
}

bool32 scene_transition_step_080686F4(void)
{
    if (gUnk_08485C68[gUnk_03000004]()) {
        gUnk_03000000 = 0;
        if (gUnk_03000004 == 3)
            REG_DISPCNT &= 0xFEFF;
        return TRUE;
    }
    gUnk_03000000++;
    return FALSE;
}

bool32 execute_scene_step(void)
{
    if (gUnk_08485C7C[gUnk_03000004]()) {
        gUnk_03000000 = 0;
        return TRUE;
    }
    gUnk_03000000++;
    return FALSE;
}

bool32 sub_0806878C(void)
{
    return TRUE;
}

bool32 scene_step_fade_in_bldy(void)
{
    s32 *c = &gUnk_03000000;
    u8 *np = &gUnk_03000005;
    u8 n = *np;
    s32 t = *c;
    if (t % n == 0)
        REG_BLDY = 16 - t / n;
    if (*c == *np * 16)
        return TRUE;
    return FALSE;
}

bool32 scene_step_wipe_clear_bg0(void)
{
    u16 zero = 0;
    s32 *c;
    u8 *np;
    s32 t;
    REG_DISPCNT |= 0x100;
    c = &gUnk_03000000;
    np = &gUnk_03000005;
    {
    u8 n = *np;
    t = *c;
    if (t % n == 0) {
        DmaSet(3, &zero, gUnk_03000008[t / *np] + 0x0600C000, 0x80000001);
        DmaSet(3, &zero, gUnk_03000008[t / *np] + 0x0600C004, 0x80000001);
        DmaSet(3, &zero, gUnk_03000008[t / *np] + 0x0600C008, 0x80000001);
        DmaSet(3, &zero, gUnk_03000008[t / *np] + 0x0600C00C, 0x80000001);
    }
    }
    if (*c == *np * 16) {
        REG_DISPCNT &= 0xFEFF;
        return TRUE;
    }
    return FALSE;
}

bool32 scene_step_palette_fade_in(void)
{
    s32 *c = &gUnk_03000000;
    s32 n = gUnk_03000005;
    s32 m = n * 32;
    s32 t = *c;
    if (t == m)
        return TRUE;
    if (t % n == 0) {
        int i, k, inv;
        k = t / n;
        inv = 0x20 - k;
        for (i = 0; i < 0x200; i++) {
            gPaletteBuffer[i] = (((gUnk_0300002C[i] & 0x1F) * k + (gUnk_03000028 & 0x1F) * inv) >> 5)
                   + ((((gUnk_0300002C[i] & 0x3E0) * k + (gUnk_03000028 & 0x3E0) * inv) >> 5) & 0x3E0)
                   + ((((gUnk_0300002C[i] & 0x7C00) * k + (gUnk_03000028 & 0x7C00) * inv) >> 5) & 0x7C00);
        }
        DmaSet(3, gPaletteBuffer, PLTT, 0x84000100);
    }
    return FALSE;
}

bool32 scene_step_fade_out_bldy(void)
{
    s32 *c = &gUnk_03000000;
    u8 *np = &gUnk_03000005;
    u8 n = *np;
    s32 t = *c;
    if (t % n == 0)
        REG_BLDY = t / n;
    if (*c == *np * 16)
        return TRUE;
    return FALSE;
}

INCLUDE_ASM("asm/nonmatching/code_08067160", scene_step_wipe_fill_bg0);

bool32 scene_step_palette_fade_out(void)
{
    s32 *c = &gUnk_03000000;
    s32 n = gUnk_03000005;
    s32 m = n * 32;
    s32 t = *c;
    if (t == m)
        return TRUE;
    if (t % n == 0) {
        int i, k, inv;
        u16 *dst;
        k = t / n;
        inv = 0x20 - k;
        if (k <= 0) {
            DmaSet(3, PLTT, gUnk_0300002C, 0x84000100);
        } else {
            for (i = 0; i < 0x200; i++) {
                gPaletteBuffer[i] = (((gUnk_0300002C[i] & 0x1F) * inv + (gUnk_03000028 & 0x1F) * k) >> 5)
                       + ((((gUnk_0300002C[i] & 0x3E0) * inv + (gUnk_03000028 & 0x3E0) * k) >> 5) & 0x3E0)
                       + ((((gUnk_0300002C[i] & 0x7C00) * inv + (gUnk_03000028 & 0x7C00) * k) >> 5) & 0x7C00);
            }
            DmaSet(3, gPaletteBuffer, PLTT, 0x84000100);
        }
    }
    return FALSE;
}

void race_dispatch_substate(void)
{
    if (gUnk_03006F90 == 0)
        sub_0806B310();
    gRaceSubStates[gGameSubState]();
}

void sub_08068C6C(void)
{
    sub_0806918C();
    play_song(0);
    gUnk_03006FDC = gUnk_03006D38.unk0;
    get_entity_speed_value();
    load_battle_sprite_graphics();
    load_bg_tilemaps_and_palette();
    init_battle_bg_layer();
    play_song(0x13);
    setup_screen_transition_effect_080682CC(4, 1, 0);
    REG_DISPCNT |= 0x1E00;
    gUnk_03006F88 = 0;
    gUnk_03006F94[0] = 0;
    gUnk_03006F94[1] = 0;
    gUnk_03006F94[2] = 0;
    gUnk_03006F8C[0] = 0;
    gUnk_03006F8C[1] = 0;
    gUnk_03006F8C[2] = 0;
    gUnk_03006F80 = 3;
    gGameSubState = 1;
}

void sub_08068CF4(void)
{
    if (scene_transition_step_080686F4())
        gGameSubState = gUnk_03006F80;
}

void sub_08068D14(void)
{
    if (execute_scene_step()) {
        u32 zero = 0;
        DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
        gVBlankCallback = nullsub_08000840;
        REG_DISPCNT &= 0x80FF;
        gGameSubState = gUnk_03006F80;
    }
}

void sub_08068D74(void)
{
    if (sub_08069EF8()) {
        gUnk_03006F88 = 0;
        gUnk_03006F80 = 4;
        gGameSubState = 2;
    }
}

void sub_08068DA0(void)
{
    REG_BLDCNT = 0xFF;
    REG_BLDY = 0xF;
    race_enter_team_select();
}

void sub_08068DBC(void)
{
    int i;
    const u8 *p;

    sub_0806918C();
    load_battle_sprite_graphics();
    init_battle_background_layers();
    load_bg_tilemaps_and_palette();
    play_song(0);
    for (i = 0; i < 3; i++) {
        gUnk_03006FD0[0][i] = gUnk_03001800.unk8C[i];
        gUnk_03006FA0[0][0][i] = gUnk_03001800.unk8F[i][0];
        gUnk_03006FA0[0][1][i] = gUnk_03001800.unk8F[i][1];
        gUnk_03006FA0[0][2][i] = gUnk_03001800.unk8F[i][2];
        gUnk_03006FA0[0][3][i] = gUnk_03001800.unk8F[i][3];
        decompress_sprite_to_vram_08042D94(gUnk_03006FA0[0][0][i], gUnk_03006FA0[0][1][i], gUnk_03006FA0[0][2][i], gUnk_03006FA0[0][3][i], 2 - i);
    }
    p = gUnk_083C1A00[gUnk_08486160[gUnk_03006FDC].unk2];
    p += 4;
    for (i = 0; i < 3; i++) {
        gUnk_03006FA0[1][0][i] = *p++;
        gUnk_03006FA0[1][1][i] = *p++;
        gUnk_03006FA0[1][2][i] = *p++;
        gUnk_03006FA0[1][3][i] = *p;
        p += 9;
        gUnk_03006FD0[1][i] = gUnk_083B827C[gUnk_03006FA0[1][3][i] * 64 + 0x31] - 0x64;
        decompress_sprite_to_vram_08042D94(gUnk_03006FA0[1][0][i], gUnk_03006FA0[1][1][i], gUnk_03006FA0[1][2][i], gUnk_03006FA0[1][3][i], 5 - i);
    }
    p = gUnk_083C1A00[gUnk_08486160[gUnk_03006FDC].unk6];
    p += 4;
    for (i = 0; i < 3; i++) {
        gUnk_03006FA0[2][0][i] = *p++;
        gUnk_03006FA0[2][1][i] = *p++;
        gUnk_03006FA0[2][2][i] = *p++;
        gUnk_03006FA0[2][3][i] = *p;
        p += 9;
        gUnk_03006FD0[2][i] = gUnk_083B827C[gUnk_03006FA0[2][3][i] * 64 + 0x31] - 0x64;
        decompress_sprite_to_vram_08042D94(gUnk_03006FA0[2][0][i], gUnk_03006FA0[2][1][i], gUnk_03006FA0[2][2][i], gUnk_03006FA0[2][3][i], 8 - i);
    }
    play_song(0x13);
    setup_screen_transition_effect_080682CC(2, 2, 0);
    REG_DISPCNT |= 0x1E00;
    gUnk_03006F80 = 6;
    gGameSubState = 1;
}

void sub_08068FD4(void)
{
    if (sub_08069F80()) {
        gUnk_03006F88 = 0;
        gUnk_03006F80 = 7;
        gGameSubState = 2;
    }
}

void sub_08069000(void)
{
    init_battle_field_screen();
    init_battle_icon_positions();
    init_battle_bg_layer1();
    play_song(0);
    setup_screen_transition_effect_080682CC(4, 1, 0);
    play_song(0x17);
    REG_DISPCNT |= 0x1E00;
    gUnk_03006F80 = 8;
    gGameSubState = 1;
}

void sub_0806904C(void)
{
    update_sprite_animations_tick_0806AF40();
    update_sprite_animations_0806B334();
    if (sub_0806A4C0()) {
        gUnk_03006F88 = 0;
        gGameSubState = 9;
    }
}

void race_update(void)
{
    update_battle_icon_rotation();
    race_update_racer_anim_counters();
    update_battle_bot_entry_animations();
    update_battle_bot_death_animations();
    update_battle_bot_damage_animations();
    update_battle_bot_turn_order_tiles();
    update_sprite_animations_tick_0806AF40();
    update_sprite_animations_0806B334();
    if (race_check_all_finished()) {
        gUnk_03006F88 = 0;
        gUnk_03006F80 = 10;
        gGameSubState = 2;
    }
}

void sub_080690C4(void)
{
    sub_0806918C();
    load_battle_sprite_graphics();
    init_battle_background_layers();
    load_bg_tilemaps_and_palette();
    play_song(0);
    setup_screen_transition_effect_080682CC(2, 2, 0);
    play_song(0x13);
    REG_DISPCNT |= 0x1A00;
    gUnk_03006F80 = 11;
    gGameSubState = 1;
}

void sub_08069114(void)
{
    if (sub_0806A230()) {
        REG_BLDY = 0;
        REG_BLDCNT = 0xFF;
        gUnk_03006F88 = 0;
        sound_stop_all_with_fade_guard(0x20);
        gUnk_03006F80 = 12;
        gGameSubState = 2;
    }
}

void sub_08069158(void)
{
    struct Unk_03005310 *p;
    sub_0806918C();
    play_song(0);
    p = &gUnk_03005310;
    p->unk39 = gUnk_03006F94[0] == 1 ? 1 : 2;
    sub_08047850(0);
}

void sub_0806918C(void)
{
    u32 zero = 0;
    DmaSet(3, &zero, 0x06000000, 0x85006000);
    REG_DISPCNT = 0x60;
    zero = 0;
    DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
}

void init_battle_background_layers(void)
{
    gUnk_03006F90 = 0;
    decompress_indexed_asset(0, 0, (void *)0x06004000, 9, 0);
    decompress_indexed_asset(gUnk_08486160[gUnk_03006FDC].unk4, 0, (void *)0x06004800, 10, 0);
    decompress_indexed_asset(gUnk_08486160[gUnk_03006FDC].unk8, 0, (void *)0x06005000, 11, 0);
    REG_BG2CNT = 0x1E02;
    gBg2Scroll.x = -24;
    gBg2Scroll.y = -96;
}

void dma_copy_tilemap_strip(u8 n)
{
    u16 buf[24];
    int i;
    for (i = 0; i <= 7; i++) {
        buf[i] = n * 8 - 0x6E00 + i;
        buf[i + 8] = n * 8 - 0x5DC0 + i;
        buf[i + 16] = n * 8 - 0x4D80 + i;
    }
    DmaSet(3, buf, n * 64 + 0x0600F000, 0x80000018);
    gBg2Scroll.y = -((12 - n) * 8);
}

void init_battle_bg_layer(void)
{
    gUnk_03006F90 = 1;
    REG_BG2CNT = 0x1E0A;
    REG_BG3CNT = 0x1F0B;
    gUnk_03001800.unk38 = gUnk_03006F84;
    decompress_tileset_to_vram(gUnk_03001800.unk38, 0);
    memcpy_bytes_0803F63C(gUnk_083C3B04[gUnk_03001800.unk38], gUnk_03001800.unk39, 8);
    apply_battle_blend_effect_a();
    decompress_to_ewram_27000(gUnk_083B23F8[gUnk_03001800.unk38 * 5 + 1]);
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gVBlankCallback = sub_08043E48;
}

void init_battle_field_screen(void)
{
    gUnk_03006F90 = 1;
    REG_BG2CNT = 0x1E0A;
    REG_BG3CNT = 0x1F0B;
    gUnk_03001800.unk38 = gUnk_03006F84;
    decompress_sprite_to_vram_08043C08(gUnk_03001800.unk38, 0);
    load_battle_script_entry_b();
    apply_battle_blend_effect_b();
    decompress_to_ewram_27000(gUnk_083B24A8[gUnk_03001800.unk38 * 5 + 1]);
    LZ77UnCompVram(gUnk_087C4EBC, (void *)0x0600C800);
    LZ77UnCompVram(gUnk_087C4F48, (void *)0x0600C880);
    LZ77UnCompVram(gUnk_087C4FDC, (void *)0x0600C9C0);
    LZ77UnCompVram(gUnk_087C51C0, (void *)0x0600CC40);
    DmaSet(3, gUnk_087C5248, 0x05000100, 0x84000008);
    DmaSet(3, gUnk_087C5268, 0x05000120, 0x84000008);
    DmaSet(3, gUnk_087C5288, 0x05000140, 0x84000008);
    DmaSet(3, gUnk_087C52A8, 0x05000160, 0x84000008);
    write_tilemap_tiles_dma(0, 2, 4);
    write_tilemap_tiles_dma(0, 2, 7);
    write_tilemap_tiles_dma(0, 2, 0xA);
    write_tilemap_tiles_dma(1, 6, 3);
    write_tilemap_tiles_dma(2, 0xE, 3);
    write_tilemap_tiles_dma(3, 0x1A, 4);
    write_tilemap_tiles_dma(3, 0x1A, 7);
    write_tilemap_tiles_dma(3, 0x1A, 0xA);
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gVBlankCallback = battle_vblank_update_bg;
}

void init_battle_bg_layer1(void)
{
    vu16 zero = 0;
    DmaSet(3, &zero, 0x0600E800, 0x81000400);
    LZ77UnCompVram(gUnk_087C52C8, (void *)0x0600CD00);
    LZ77UnCompVram(gUnk_087C5518, (void *)0x0600D0A0);
    DmaSet(3, gUnk_087C55D0, 0x05000180, 0x84000008);
    DmaSet(3, gUnk_087C55F0, 0x050001A0, 0x84000008);
    write_tilemap_tiles_dma(4, 1, 0xE);
    write_tilemap_tiles_dma(4, 0xB, 0xE);
    write_tilemap_tiles_dma(4, 0x15, 0xE);
    REG_BG1CNT = 0x1D0D;
    init_battle_sprite_entry_08048818(1, 0xC400, 0x6F, 8, 1);
    gUnk_03002C30[1].unk2 = 0xF;
    gUnk_03002C30[1].unk4 = 0x7F;
    init_battle_sprite_entry_08048818(2, 0xC400, 0x7B, 9, 1);
    gUnk_03002C30[2].unk2 = 0x5F;
    gUnk_03002C30[2].unk4 = 0x7F;
    init_battle_sprite_entry_08048818(3, 0xC400, 0x87, 10, 1);
    gUnk_03002C30[3].unk2 = 0xAF;
    gUnk_03002C30[3].unk4 = 0x7F;
}

static inline u32 tilemap_addr(u32 base, u16 col, u16 row)
{
    base += col * 2;
    return row * 64 + base;
}

void write_tilemap_tiles_dma(u8 type, u8 x, u8 y)
{
    u8 w[8];
    u8 h[8];
    u16 first[8];
    struct U16PtrArray8 lists;
    u16 pal[8];
    const u16 *p;
    int i, j;
    u16 tile;

    memcpy_optimized(w, gUnk_080AFEE0, 8);
    memcpy_optimized(h, gUnk_080AFEE8, 8);
    memcpy_optimized(first, gUnk_080AFEF0, 16);
    lists = gUnk_080AFF00;
    memcpy_optimized(pal, gUnk_080AFF20, 16);

    type &= 7;
    p = lists.v[type];
    for (i = 0; i < h[type]; i++) {
        for (j = 0; j < w[type]; j++) {
            if (type > 4)
                tile = i * 6 + j + first[type] + pal[type];
            else
                tile = *p + first[type] + pal[type];
            if (type <= 3)
                DmaSet(3, &tile, tilemap_addr(0x0600F800, x + j, i + y), 0x80000001)
            else
                DmaSet(3, &tile, tilemap_addr(0x0600E800, x + j, i + y), 0x80000001)
            p++;
        }
    }
}

void load_bg_tilemaps_and_palette(void)
{
    u16 buf[0x400];
    vu32 zero;
    int i;
    LZ77UnCompVram(gUnk_087B2CCC, (void *)0x0600C000);
    zero = 0;
    DmaSet(3, &zero, buf, 0x85000200);
    LZ77UnCompVram(gUnk_087B3710, buf);
    for (i = 0; i < 0x280; i++)
        buf[i] += 0xC000;
    DmaSet(3, buf, 0x0600E800, 0x80000400);
    LZ77UnCompVram(gUnk_087B384C, buf);
    for (i = 0; i < 0x400; i++)
        buf[i] += 0xC000;
    DmaSet(3, buf, 0x0600F800, 0x80000400);
    DmaSet(3, gUnk_087B3AF0, 0x05000180, 0x80000020);
    REG_BG1CNT = 0x1D0D;
    REG_BG3CNT = 0x1F0F;
}

void load_battle_sprite_graphics(void)
{
    const u8 *e;
    LZ77UnCompVram(gUnk_083F80F4[0x25], (void *)0x06012400);
    DmaSet(3, gUnk_083F8634[0x25], 0x05000200, 0x80000010);
    LZ77UnCompVram(gUnk_087AD4E4, (void *)0x06012E00);
    LZ77UnCompVram(gUnk_083F80F4[0], (void *)0x06015100);
    DmaSet(3, gUnk_083F8634[0], 0x05000300, 0x84000008);
    e = gUnk_083C1A00[gUnk_08486160[gUnk_03006FDC].unk2];
    LZ77UnCompVram(gUnk_083F80F4[e[0]], (void *)0x06015A00);
    DmaSet(3, gUnk_083F8634[e[0]], 0x05000320, 0x84000008);
    e = gUnk_083C1A00[gUnk_08486160[gUnk_03006FDC].unk6];
    LZ77UnCompVram(gUnk_083F80F4[e[0]], (void *)0x06016300);
    DmaSet(3, gUnk_083F8634[e[0]], 0x05000340, 0x84000008);
    DmaSet(3, gUnk_0807C300, 0x050003A0, 0x84000008);
}

INCLUDE_ASM("asm/nonmatching/code_08067160", divide_by_3);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_08069A68);
INCLUDE_ASM("asm/nonmatching/code_08067160", init_battle_icon_positions);

void init_battle_sprite_small(void)
{
    init_battle_sprite_entry_08048818(0, 0xC004, 0x33, 0, 1);
    gUnk_03002C30[0].unk2 = -16;
}

void init_battle_sprite_medium(void)
{
    init_battle_sprite_entry_08048818(1, 0xC404, 0x100, 1, 3);
    gUnk_03002C30[1].unk2 = 0x28;
    gUnk_03002C30[1].unk4 = 0x10;
    gUnk_03002C30[1].unk1A = 0;
    DmaSet(3, gUnk_0807C260, 0x05000220, 0x84000008);
}

void init_battle_sprite_c400(void)
{
    init_battle_sprite_entry_08048818(0, 0xC400, 0x104, 0xC, 3);
    gUnk_03002C30[0].unk2 = 0x78;
    gUnk_03002C30[0].unk4 = -16;
    gUnk_03002C30[0].unk1A = 0;
    DmaSet(3, gUnk_0807C280, 0x05000380, 0x84000008);
    DmaSet(3, gUnk_0807C280 + 0x30, 0x05000360, 0x84000008);
}

void init_battle_sprite_entry_1(void)
{
    init_battle_sprite_entry_08048818(1, 0xC808, 0x10B, 3, 3);
    gUnk_03002C30[1].unk4 = 0x40;
    gUnk_03002C30[1].unk1A = 0;
    DmaSet(3, gUnk_0807C2C0, 0x05000260, 0x84000008);
    REG_BLDCNT = 0xC40;
    REG_BLDALPHA = 0x10;
}

void init_battle_sprite_large(void)
{
    init_battle_sprite_entry_08048818(2, 0xCB20, 0x108, 2, 3);
    gUnk_03002C30[2].unk4 = 0xC8;
    gUnk_03002C30[2].unk8 = 0x88;
    gUnk_03002C30[2].unk9 = 0x88;
    gUnk_03002C30[2].unk18 = 0;
    gUnk_03002C30[2].unk1A = 0;
    init_battle_sprite_entry_08048818(3, 0xCB20, 0x109, 2, 3);
    gUnk_03002C30[3].unk4 = 0xC8;
    gUnk_03002C30[3].unk8 = 0x88;
    gUnk_03002C30[3].unk9 = 0x88;
    gUnk_03002C30[3].unk18 = 0;
    gUnk_03002C30[3].unk1A = 0;
    init_battle_sprite_entry_08048818(4, 0xCB20, 0x10A, 2, 3);
    gUnk_03002C30[4].unk4 = 0xC8;
    gUnk_03002C30[4].unk8 = 0x88;
    gUnk_03002C30[4].unk9 = 0x88;
    gUnk_03002C30[4].unk18 = 0;
    gUnk_03002C30[4].unk1A = 0;
    DmaSet(3, gUnk_0807C2A0, 0x05000240, 0x84000008);
}

void get_entity_speed_value(void)
{
    if (gUnk_08486160[gUnk_03006FDC].unk0 != 0)
        gUnk_03006F84 = gUnk_08486160[gUnk_03006FDC].unk1;
    else
        gUnk_03006F84 = gUnk_083F7FF4[(u8)gFrameCounter] % 11;
}

void sub_08069EE4(u8 *dst, u8 *src)
{
    do {
        *dst = *src;
        dst++;
    } while (*src++ <= 0xF8);
}

bool32 sub_08069EF8(void)
{
    switch (gUnk_03006F88) {
    case 0:
        text_window_init(1, 2, 0);
        init_battle_sprite_small();
        sprite_animation_dispatch(0, 1, 0x20, 0x58);
        sub_08069EE4(gUnk_030004DE, (u8 *)gUnk_083BE9E8[gUnk_03006F84]);
        gUnk_03006F88++;
        return FALSE;
    case 1:
        if (run_message(gUnk_084864E8[0]) && gUnk_03002C30[0].unk20 == 0)
            return TRUE;
        break;
    }
    update_sprite_animations_tick_0806AF40();
    update_sprite_animations_0806B334();
    return FALSE;
}

bool32 sub_08069F80(void)
{
    const u8 *e;
    switch (gUnk_03006F88) {
    case 0:
        text_window_init(1, 2, 0);
        init_battle_sprite_small();
        sprite_animation_dispatch(0, 1, 0x18, 0x58);
        REG_DISPCNT |= 0x400;
        gUnk_03006F88++;
        return FALSE;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        dma_copy_tilemap_strip(gUnk_03006F88 - 6);
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        run_message(gUnk_084864E8[1]);
        gUnk_03006F88++;
        break;
    case 14:
        if (run_message(gUnk_084864E8[1])) {
            sub_0803FB0C();
            init_battle_sprite_medium();
            sprite_animation_dispatch(1, 4, 0, 0);
            gUnk_03006F88++;
        }
        break;
    case 15:
        if (run_message(gUnk_084864E8[2])) {
            sub_0803FB0C();
            gUnk_03006F88++;
        }
        break;
    case 16:
        if (gUnk_03002C30[0].unk20 == 0)
            gUnk_03006F88++;
        break;
    case 17:
        if (run_message(gUnk_084864E8[5])) {
            sub_0803FB0C();
            e = gUnk_083C1A00[gUnk_08486160[gUnk_03006FDC].unk2];
            sub_08069EE4(gUnk_030004DE, (u8 *)gUnk_083C3F38[e[0]]);
            sprite_animation_dispatch(0, 2, 0x40, 0);
            gUnk_03002C30[1].unk2 = 0x68;
            gUnk_03006F88++;
        }
        break;
    case 18:
        if (run_message(gUnk_084864E8[3]) && gUnk_03002C30[0].unk20 == 0) {
            sub_0803FB0C();
            gUnk_03006F88++;
        }
        break;
    case 19:
        if (run_message(gUnk_084864E8[gUnk_08486160[gUnk_03006FDC].unk9])) {
            sub_0803FB0C();
            e = gUnk_083C1A00[gUnk_08486160[gUnk_03006FDC].unk6];
            sub_08069EE4(gUnk_030004DE, (u8 *)gUnk_083C3F38[e[0]]);
            sprite_animation_dispatch(0, 2, 0x40, 0);
            gUnk_03002C30[1].unk2 = 0xA8;
            gUnk_03006F88++;
        }
        break;
    case 20:
        if (run_message(gUnk_084864E8[4]) && gUnk_03002C30[0].unk20 == 0) {
            sub_0803FB0C();
            gUnk_03006F88++;
        }
        break;
    case 21:
        if (run_message(gUnk_084864E8[gUnk_08486160[gUnk_03006FDC].unk9 + 1])) {
            sub_0803FB0C();
            gUnk_03006F88++;
        }
        break;
    case 22:
        if (run_message(gUnk_084864E8[6]))
            return TRUE;
        break;
    }
    update_sprite_animations_tick_0806AF40();
    update_sprite_animations_0806B334();
    return FALSE;
}

bool32 sub_0806A230(void)
{
    const u8 *e;
    switch (gUnk_03006F88) {
    case 0:
        text_window_init(1, 2, 0);
        init_battle_sprite_small();
        play_sound_effect(0x15);
        if (gUnk_03006F94[0] == 1) {
            sprite_animation_dispatch(0, 1, 0x18, 0x58);
            sub_08069EE4(gUnk_030004DE, gUnk_03002B74);
        } else if (gUnk_03006F94[0] == 2) {
            sprite_animation_dispatch(0, 1, 0x58, 0x58);
            e = gUnk_083C1A00[gUnk_08486160[gUnk_03006FDC].unk2];
            sub_08069EE4(gUnk_030004DE, (u8 *)gUnk_083C3F38[e[0]]);
        } else if (gUnk_03006F94[0] == 3) {
            sprite_animation_dispatch(0, 1, 0x98, 0x58);
            e = gUnk_083C1A00[gUnk_08486160[gUnk_03006FDC].unk6];
            sub_08069EE4(gUnk_030004DE, (u8 *)gUnk_083C3F38[e[0]]);
        }
        REG_DISPCNT |= 0x400;
        gUnk_03006F88++;
        return FALSE;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        if (gUnk_03006F88 == 6) {
            init_battle_sprite_large();
            sprite_animation_dispatch(4, 7, 2, 0);
            gUnk_03002C30[4].unk2 = (gUnk_03006F94[2] - 1) * 64 + 0x38;
            gUnk_03002C30[4].unk4 = 0x18;
            sprite_animation_dispatch(3, 7, 1, 0);
            gUnk_03002C30[3].unk2 = (gUnk_03006F94[1] - 1) * 64 + 0x38;
            gUnk_03002C30[3].unk4 = 0x18;
            sprite_animation_dispatch(2, 7, 0, 0);
            gUnk_03002C30[2].unk2 = (gUnk_03006F94[0] - 1) * 64 + 0x38;
            gUnk_03002C30[2].unk4 = 0x18;
        }
        dma_copy_tilemap_strip(gUnk_03006F88 - 6);
    default:
        run_message(gUnk_084864E8[0x1E]);
        gUnk_03006F88++;
        break;
    case 0x96:
        play_sound_effect(0x16);
        REG_BLDCNT = 0x7F;
        init_battle_sprite_entry_1();
        sprite_animation_dispatch(1, 6, 0, 0);
        gUnk_03002C30[1].unk2 = (gUnk_03006F94[0] - 1) * 64 + 0x18;
        sub_0803FB0C();
        gUnk_03006F88++;
        break;
    case 0x97:
        if (run_message(gUnk_084864E8[7]) && gUnk_03002C30[1].unk20 == 0) {
            sub_0803FB0C();
            if (gUnk_03006F94[0] == 1)
                gUnk_03006F88++;
            else
                gUnk_03006F88 += 2;
        }
        break;
    case 0x98:
        if (run_message(gUnk_084864E8[8]))
            return TRUE;
        break;
    case 0x99:
        if (run_message(gUnk_084864E8[9]))
            return TRUE;
        break;
    }
    update_sprite_animations_tick_0806AF40();
    update_sprite_animations_0806B334();
    return FALSE;
}

bool32 sub_0806A4C0(void)
{
    switch (gUnk_03006F88) {
    case 0:
        init_battle_sprite_c400();
        sprite_animation_dispatch(0, 5, 0, 0);
        gUnk_03006F88++;
        break;
    case 1:
        if (gUnk_03002C30[0].unk1A == 0xB4) {
            play_sound_effect(0x42);
            battle_sprite_set_palette_index(0x26, 0xC);
            battle_sprite_set_palette_index(0x32, 0xC);
            battle_sprite_set_palette_index(0x3E, 0xC);
            sprite_animation_dispatch(1, 0xA, 0, 0);
            sprite_animation_dispatch(2, 0xA, 1, 0);
            sprite_animation_dispatch(3, 0xA, 2, 0);
            gUnk_03006FF8[0] = gUnk_03006FF8[1] = 0;
            gUnk_03007000[0] = gUnk_03007000[1] = 0;
            gUnk_03006FE0[0] = gUnk_03006FE0[1] = gUnk_03006FE0[2] = 0;
            gUnk_03006FEC[0] = gUnk_03006FEC[1] = gUnk_03006FEC[2] = 0x20;
            gUnk_03006FF0[0] = gUnk_03006FF0[1] = gUnk_03006FF0[2] = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

bool32 race_check_all_finished(void)
{
    if (gUnk_03006F8C[0] > 2 && gUnk_03006F8C[1] > 2 && gUnk_03006F8C[2] > 2) {
        if (++gUnk_03006F88 > 0xF0)
            return TRUE;
    }
    return FALSE;
}

void update_battle_bot_turn_order_tiles(void)
{
    int i, j, rank;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03006F8C[i] > 2) {
            if (gUnk_03006F94[0] == i + 1)
                write_tilemap_tiles_dma(5, i * 10 + 5, 0xF);
            else if (gUnk_03006F94[1] == i + 1)
                write_tilemap_tiles_dma(6, i * 10 + 5, 0xF);
            else if (gUnk_03006F94[2] == i + 1)
                write_tilemap_tiles_dma(7, i * 10 + 5, 0xF);
        } else {
            for (j = 0, rank = 5; j <= 2; j++) {
                if (i != j) {
                    if (gUnk_03006F8C[i] < gUnk_03006F8C[j])
                        rank++;
                    else if (gUnk_03006F8C[i] == gUnk_03006F8C[j]) {
                        if (gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A == gUnk_03002C30[gUnk_08485CC4[j][gUnk_03006F8C[j]]].unk1A) {
                            if (j < i)
                                rank++;
                        } else if (gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A < gUnk_03002C30[gUnk_08485CC4[j][gUnk_03006F8C[j]]].unk1A)
                            rank++;
                    }
                }
            }
            write_tilemap_tiles_dma(rank, i * 10 + 5, 0xF);
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_08067160", update_battle_icon_rotation);

void race_update_racer_anim_counters(void)
{
    int i;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03006F8C[i] <= 2) {
            if (gUnk_08485CE3[gUnk_03006F84][gUnk_03006FD0[i][gUnk_03006F8C[i]]] <= ++gUnk_03006FE0[i]) {
                gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A++;
                gUnk_03006FE0[i] = 0;
            }
        }
    }
}

static inline int sub2(int x) { return x - 2; }
static inline int add14(int x) { return x + 0x14; }

void update_battle_bot_entry_animations(void)
{
    int i, k;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03006F8C[i] > 2)
            continue;
        if (gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A > 0x2AF) {
            battle_sprite_set_palette_index(gUnk_08485CC4[i][gUnk_03006F8C[i]] - 3, 4);
            gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk2A = 1;
            if (++gUnk_03006F8C[i] > 2) {
                sprite_animation_dispatch(i + 1, 0, 0, 0);
                if (gUnk_03006F94[0] == 0) {
                    gUnk_03006F94[0] = i + 1;
                    for (k = 0; k <= 15; k++) {
                        u8 r = gUnk_083F7FF4[(gFrameCounter + k) & 0xFF];
                        r &= 3;
                        // the original passes k + 4 untruncated: called without (or with an int-slot) prototype
                        ((void (*)())init_battle_sprite_entry_08048818)(k + 4, 0xC400, r + 0x10C, 0xB, 3);
                        gUnk_03002C30[k + 4].unkB = 0x64;
                        sprite_animation_dispatch(k + 4, 8, r, (k * 16) & 0x7F);
                    }
                } else if (gUnk_03006F94[1] == 0)
                    gUnk_03006F94[1] = i + 1;
                else if (gUnk_03006F94[2] == 0)
                    gUnk_03006F94[2] = i + 1;
                play_sound_effect(0x43);
                continue;
            }
            play_sound_effect(0x44);
            gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A = 0;
            gUnk_03006FEC[i] = 0x20;
            gUnk_03006FF0[i] = 0;
        }
        if (gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk3A <= 0x157 && gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A > 0x157) {
            divide_by_3(i * 3 + gUnk_03006F8C[i], 1);
            gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]] - 3].unkB -= 4;
            gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]] - 2].unkB -= 4;
            gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]] - 1].unkB -= 4;
            gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unkB -= 4;
            if (gUnk_03006F8C[i] <= 1)
                gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2A = 2;
        }
        if (gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A > 0x158)
            gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk2 = 0xD8 - ((gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A - 0x158) >> 1);
        else {
            gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk2 = (gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A >> 1) + 0x2C;
            if (gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk3A <= 0x97 && gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A > 0x97 && gUnk_03006F8C[i] <= 1) {
                gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2A = 1;
                battle_sprite_set_palette_index(gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3, 4);
            }
        }
        gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk3A = gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A;
        gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A++;
        update_battle_sprite_orbiting_positions(gUnk_08485CC4[i][gUnk_03006F8C[i]] - 3, i * 3 - sub2(gUnk_03006F8C[i]), 0);
        gUnk_03002C30[i * 3 + add14(gUnk_03006F8C[i])].unk2 = gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk2;
    }
}

// Inline helpers: the original evaluates these offsets separately (no fold into the index).
static inline int sub1(int x) { return x - 1; }

void update_battle_bot_death_animations(void)
{
    int i, t;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03006F8C[i] > 1)
            continue;
        if (gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2A == 1) {
            update_battle_sprite_orbiting_positions(gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3, i * 3 - sub1(gUnk_03006F8C[i]), 0);
            gUnk_03002C30[gUnk_03006F8C[i] + i * 3 + 0x15].unk2 = gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2;
            if (gFrameCounter & 1) {
                if (++gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2 == 0x18) {
                    gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2A = 0;
                    init_battle_medabot_sprites(gUnk_03006FA0[i][0][gUnk_03006F8C[i] + 1], gUnk_03006FA0[i][1][gUnk_03006F8C[i] + 1],
                        gUnk_03006FA0[i][2][gUnk_03006F8C[i] + 1], gUnk_03006FA0[i][3][gUnk_03006F8C[i] + 1],
                        i * 3 - (t = gUnk_03006F8C[i] - 1), gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3,
                        gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3].unk2,
                        gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3].unk4 + 3, 0, 3, 5);
                    battle_sprite_set_palette_index(gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3, 8);
                }
            }
        } else if (gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2A == 2) {
            update_battle_sprite_orbiting_positions(gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3, i * 3 - sub1(gUnk_03006F8C[i]), 0);
            gUnk_03002C30[gUnk_03006F8C[i] + i * 3 + 0x15].unk2 = gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2;
            if (gFrameCounter & 1) {
                if (++gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2 == 0x2C) {
                    gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2A = 0;
                    init_battle_medabot_sprites(gUnk_03006FA0[i][0][gUnk_03006F8C[i] + 1], gUnk_03006FA0[i][1][gUnk_03006F8C[i] + 1],
                        gUnk_03006FA0[i][2][gUnk_03006F8C[i] + 1], gUnk_03006FA0[i][3][gUnk_03006F8C[i] + 1],
                        i * 3 - (t = gUnk_03006F8C[i] - 1), gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3,
                        gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3].unk2,
                        gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3].unk4 + 3, 0, 3, 5);
                    battle_sprite_set_palette_index(gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3, 0xC);
                }
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_08067160", update_battle_bot_damage_animations);

void update_sprite_animations_tick_0806AF40(void)
{
    u8 i;
    for (i = 0; i <= 0x13; i++) {
        if (gUnk_03002C30[i].unk20 != 0) {
            if (gUnk_08485D30[gUnk_03002C30[i].unk20 - 1](i))
                gUnk_03002C30[i].unk1A++;
            else if (gUnk_03002C30[i].unk20 != 0)
                sprite_animation_dispatch(i, 0, 0, 0);
        }
    }
}

bool32 sub_0806AF9C(u8 sprite)
{
    return FALSE;
}

bool32 sub_0806AFA0(u8 sprite)
{
    if (gUnk_03002C30[sprite].unk1A < 0x20) {
        gUnk_03002C30[sprite].unk2++;
        gUnk_03002C30[sprite].unk4 = gUnk_03002C30[sprite].unk23 + 3 - gUnk_08485E84[gUnk_03002C30[sprite].unk1A + 0x20];
    } else if (gUnk_03002C30[sprite].unk1A < 0x30) {
        gUnk_03002C30[sprite].unk4 = gUnk_03002C30[sprite].unk23 + 3;
    } else {
        gUnk_03002C30[sprite].unk2 += 2;
    }
    if (gUnk_03002C30[sprite].unk22 <= gUnk_03002C30[sprite].unk2)
        return FALSE;
    return TRUE;
}

bool32 sub_0806B014(u8 sprite)
{
    gUnk_03002C30[sprite].unk2 += 2;
    if (gUnk_03002C30[sprite].unk22 < gUnk_03002C30[sprite].unk1A)
        return FALSE;
    return TRUE;
}

bool32 sub_0806B03C(u8 sprite)
{
    gUnk_03002C30[sprite].unk2 -= 2;
    if (gUnk_03002C30[sprite].unk22 < gUnk_03002C30[sprite].unk1A)
        return FALSE;
    return TRUE;
}

bool32 sub_0806B064(u8 sprite)
{
    return TRUE;
}

bool32 sub_0806B068(u8 sprite)
{
    if (gUnk_03002C30[sprite].unk1A < 0x10)
        gUnk_03002C30[sprite].unk4 += 2;
    if ((u16)(gUnk_03002C30[sprite].unk1A - 0xD2) < 0x10)
        gUnk_03002C30[sprite].unk4 -= 2;
    if (gUnk_03002C30[sprite].unk1A > 0xE1) {
        clear_sprite_entry(sprite);
        return FALSE;
    }
    return TRUE;
}

bool32 sub_0806B0B4(u8 sprite)
{
    if (gUnk_03002C30[sprite].unk1A < 0x10)
        REG_BLDALPHA = 0x1000 | gUnk_03002C30[sprite].unk1A;
    else if (gUnk_03002C30[sprite].unk1A < 0x20)
        REG_BLDALPHA = ((0x20 - gUnk_03002C30[sprite].unk1A) << 8) | 0x10;
    if (gUnk_03002C30[sprite].unk1A & 1)
        gUnk_03002C30[sprite].unk4--;
    if (gUnk_03002C30[sprite].unk1A > 0x3F) {
        REG_BLDCNT = 0;
        return FALSE;
    }
    return TRUE;
}

bool32 sub_0806B124(u8 sprite)
{
    if (gUnk_03002C30[sprite].unk1A & 1) {
        gUnk_03002C30[sprite].unk8--;
        gUnk_03002C30[sprite].unk9--;
    }
    gUnk_03002C30[sprite].unk18 += 0x40;
    if (gUnk_03002C30[sprite].unk1A > 0x8F) {
        gUnk_03002C30[sprite].unk18 = 0;
        return FALSE;
    }
    return TRUE;
}

