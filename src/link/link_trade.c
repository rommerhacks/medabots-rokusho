// Link trade scenes (mode 2): state 16 (sub_080637D0, guess: Medapart trade) and state 17 (sub_080644C4,
// guess: Medal exchange, swaps serial packets through gUnk_03005010). Their sub-state tables gUnk_080AFA6C (13)
// and gUnk_080AFAA0 (12) are adjacent in ROM. The head holds the scene setup (init_scene_rendering_context),
// Medapart sprite loads and the animated tile / scroll helpers both states use. Both end in link_menu (state 20).
// Not runnable in the single-GBA harness, so the state names are guesses.
#include "global.h"

static void init_scene_rendering_context(u32 a) {
    if (a == 0) {
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
        gUnk_03005308 = (struct SceneSlot *)c;
        sub_08047414(obj, (u8 *)gUnk_03002414, (struct SpriteNodeDesc **)gUnk_083D1BF8, (struct SpriteNodeOam *)b);
        obj->oams = (struct SpriteNodeOam *)b;
        load_sprite_animation_by_type(gUnk_03002414->unkB84, obj, gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0x3C,
                                      0x28, 0xC7, a, 1);
    } else {
        struct Unk_08047414 *obj = (struct Unk_08047414 *)0x02026000;

        sub_08047414(obj, (u8 *)gUnk_03002414, (struct SpriteNodeDesc **)gUnk_083D1BF8,
                     (struct SpriteNodeOam *)0x020264E0);
        obj->oams = (struct SpriteNodeOam *)0x020264E0;
        load_sprite_animation_by_type(gUnk_03002414->unkB84, obj, gUnk_03006F74->unk32, gUnk_03006F74->unk34, 0x3C,
                                      0x28, 0xC7, 4, 2);
    }
}

void load_medapart_sprite_animation(u8 id, u8 kind, u32 which) {
    struct Unk_08047414 *obj = (struct Unk_08047414 *)0x02026000;
    u8 x, y;

    obj->oams = (struct SpriteNodeOam *)(0x020260D0 + which * 0x410);
    x = gUnk_080AFA3C[which][kind][0];
    y = gUnk_080AFA3C[which][kind][1];
    if (which)
        load_sprite_animation_by_type(gUnk_03002414->unkB84, obj, id, kind, y, x, 0xC7, 4, 6);
    else
        load_sprite_animation_by_type(gUnk_03002414->unkB84, obj, id, kind, y, x, 0xC7, which, 5);
}

static void sub_08062A74(u16 id, u8 second) {
    const u8 *src;
    u8 *dst;
    u32 i;

    src = (const u8 *)gUnk_083BB9CC[0][id];
    dst = gUnk_03000440.unk9E;
    if (second)
        dst += 0x14;
    for (i = 0; i < 20; i++) {
        *dst++ = *src++;
        if (*src == 0xFE)
            break;
    }
    *dst = 0xFE;
}

static void sub_08062AB0(u32 medal, u32 frame) {
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

static void update_animated_tilemap(void) {
    s32 v;
    s32 i;
    u32 s;
    u32 d;
    s32 t;
    s32 w;
    u32 tiles;

    switch (gUnk_03006F74->unk3A / 128) {
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
    i = 0;
    w = v + 2;
    tiles = 0x0600D800;
    d = 0x1C0;
    s = v << 9;
    for (; i < 8; i++) {
        t = v;
        CpuSet((void *)(s + tiles), (void *)(0x0600E804 + d), 0xC);
        t = w & 3;
        CpuSet((void *)((t * 8 + i) * 0x40 + tiles), (void *)(0x0600E820 + d), 0xC);
        d += 0x40;
        s += 0x40;
    }
}

static void animate_battle_scroll_tiles(void) {
    s32 v;
    s32 i;
    u8 *src;
    u8 *dst;

    switch (gUnk_03006F74->unk3A / 128) {
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
    for (i = 0; i < 8; i++) {
        CpuSet(src, dst, 0xC);
        dst += 0x40;
        src += 0x40;
    }
}

static void update_scroll_animation_tiles(void) {
    s32 v;
    s32 i;
    u32 s;
    u32 d;
    s32 t;
    s32 w;
    u32 tiles;

    switch (gUnk_03006F74->unk3A / 128) {
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
    i = 0;
    w = v + 2;
    tiles = 0x0600D800;
    d = 0x1C0;
    s = v << 9;
    for (; i < 8; i++) {
        t = v;
        CpuSet((void *)(s + tiles), (void *)(0x0600E804 + d), 0xC);
        t = w & 3;
        CpuSet((void *)((t * 8 + i) * 0x40 + tiles), (void *)(0x0600E820 + d), 0xC);
        d += 0x40;
        s += 0x40;
    }
}

static void fade_update_tilemap_copy(void) {
    s32 v;
    s32 i;
    u8 *src;
    u8 *dst;

    switch (gUnk_03006F74->unk3A / 128) {
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
    for (i = 0; i < 8; i++) {
        CpuSet(src, dst, 0xC);
        dst += 0x40;
        src += 0x40;
    }
}

void sub_08062E10(void) {
    gUnk_03006F74->unk31 = gUnk_03002B68;
    gUnk_03006F74->unk33 = ((u16 *)&gUnk_03002B68)[1];
    gGameSubState++;
}

void sub_08062E3C(void) {
    u32 size;
    u32 zero;
    u32 z;

    if (sub_08074B68() != 0x18)
        play_song(0x18);
    zero = z = 0;
    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    reset_bg_scroll();
    clear_battle_sprite_slot(0, 0x80);
    REG_DISPCNT = 0x60;
    REG_BLDCNT = 0x2FF;
    REG_BLDY = 0x10;
    REG_BG1CNT = 0x1E05;
    REG_BG2CNT = 0x1B06;
    REG_BG3CNT = 0x3C07;
    decompress_and_write_tilemap(gUnk_0879DDCC, REG_BG1CNT);
    decompress_and_write_tilemap(gUnk_0879DF44, REG_BG2CNT);
    decompress_and_write_tilemap(gUnk_0879E1DC, REG_BG3CNT);
    REG_BG2CNT = 0x1D06;
    size = dma3_copy_or_decompress(gUnk_0879C89C, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)0x06004000, size);
    lz_decompress_dispatch(gUnk_08784CB0, (void *)(0x06004000 + size));
    gUnk_03006F74->unk36 = size / 32 - 1;
    CpuFastSet(gUnk_0879C69C, (void *)PLTT, 0x80);
    CpuFastSet(gUnk_0850DD78, (void *)(PLTT + 0x3A0), 8);
    CpuFastSet(gUnk_0850DD78, &gPaletteBackup[0xD0], 8);
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06011E00);
    gUnk_03006F74->unk3A = 0x280;
    sub_08062A74(gUnk_03006F74->unk31 * 4 + gUnk_03006F74->unk33, 0);
    render_text_string_to_sprites(gUnk_03000440.unk9E, 0, 0, 10, 16, 13, z, 1);
    init_scene_rendering_context(0);
    load_medapart_sprite_animation(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0);
    update_animated_tilemap();
    init_blend_effect(gUnk_03006F74->unk50, 0x10, 0, -1, 0xC0);
    gUnk_03002C30[0x21].unk0 = 0x8000;
    gUnk_03002C30[0x21].unk1C = 2;
    gUnk_03002C30[0x21].unk2 = 0x28;
    gUnk_03002C30[0x21].unk4 = 0x40;
    gUnk_03002C30[0x21].unkA = 8;
    gUnk_03002C30[0x21].unk6 = 0x2A;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gGameSubState++;
}

static inline void *vram_at(u32 off) {
    return (void *)(0x06004000 + off);
}

void sub_08063090(void) {
    if (blend_fade_step_08065598(gUnk_03006F74->unk50)) {
        gGameSubState++;
        gUnk_03006F74->unk3C = 0x258;
        text_window_init(1, 0, 1);
    }
    load_medapart_sprite_animation(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0);
}

void sub_080630DC(void) {
    struct Unk_03005010 *s;
    struct Unk_03006F74 *w;
    u16 a, b;

    run_message(gUnk_08485BD8[15]);
    s = &gUnk_03005010;
    w = gUnk_03006F74;
    s->unk6 = w->unk31 | (w->unk33 << 8) | 0x4000;
    a = s->unk8[0][1];
    b = s->unk8[1][1];
    if ((a & 0xC000) == 0x4000 && (b & 0xC000) == (a & 0xC000)) {
        if (gUnk_03000B90) {
            w->unk32 = a & 0x7F;
            gUnk_03006F74->unk34 = (a >> 8) & 3;
        } else {
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

void sub_080631DC(void) {
    run_message(gUnk_08485BD8[19]);
    update_animated_tilemap();
    load_medapart_sprite_animation(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0);
    load_medapart_sprite_animation(gUnk_03006F74->unk32, gUnk_03006F74->unk34, 1);
    if ((s16)--gUnk_03006F74->unk3C < 0) {
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
        reduce_medapart_stat(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 1);
        medapart_add_quantity(gUnk_03006F74->unk32, gUnk_03006F74->unk34, 1);
        CpuFastSet((void *)0x05000200, gPaletteBackup, 0x100);
        play_sound_effect(0x4B);
    }
}

void sub_08063284(void) {
    struct Unk_03000440 *g = &gUnk_03000440;
    u8 *t = &g->unk84;

    if (*t <= 0x40) {
        blend_obj_palettes_to_color_0803F998(0x7FFF, *t >> 1, 0xFF);
        (*t)++;
    } else {
        gUnk_03006F74->unk3C = 0;
        *t = 0;
        gGameSubState++;
    }
    load_medapart_sprite_animation(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0);
    load_medapart_sprite_animation(gUnk_03006F74->unk32, gUnk_03006F74->unk34, 1);
    update_animated_tilemap();
}

void sub_080632FC(void) {
    struct Unk_03006F74 *w = gUnk_03006F74;
    s32 n;
    u16 zero;
    vu16 v;

    n = 16 - (s16)w->unk3C++;
    if (n != 0) {
        REG_BLDCNT = 0xE50;
        REG_BLDALPHA = ((16 - n) << 8) | n;
        REG_BLDY = 8;
        load_medapart_sprite_animation(w->unk31, w->unk33, 0);
        load_medapart_sprite_animation(gUnk_03006F74->unk32, gUnk_03006F74->unk34, 1);
        if (n == 1)
            clear_battle_sprite_slot(0, 0x80);
    } else {
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

void sub_080633E4(void) {
    u8 buf[0x20];
    s32 i;
    u16 *a, *b;
    u32 zero, one;

    a = (u16 *)0x0202F880;
    b = gPaletteBackup;
    for (i = 3; i >= 0; i--) {
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

void update_fade_in_blend_effect(void) {
    struct Unk_03006F74 *w = gUnk_03006F74;
    s32 n = (s16)w->unk3C++;

    if (n <= 16) {
        blend_obj_palettes_to_color_0803F998(0x7FFF, 0x20, 0xFF);
        REG_BLDCNT = 0xE50;
        REG_BLDALPHA = ((16 - n) << 8) | n;
        REG_BLDY = 8;
    } else {
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

void fade_screen_and_update_sprites(void) {
    struct Unk_03000440 *g = &gUnk_03000440;
    u8 *t = &g->unk84;

    if (*t <= 0x40) {
        blend_obj_palettes_to_color_0803F998(0x7FFF, 0x20 - (*t >> 1), 0xFF);
        (*t)++;
    } else {
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

void init_medapart_detail_view(void) {
    load_medapart_sprite_animation(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0);
    load_medapart_sprite_animation(gUnk_03006F74->unk32, gUnk_03006F74->unk34, 1);
    update_scroll_animation_tiles();
    if (gUnk_03006F74->unk3A == 0) {
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

void menu_confirm_selection_with_fade(void) {
    load_medapart_sprite_animation(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0);
    load_medapart_sprite_animation(gUnk_03006F74->unk32, gUnk_03006F74->unk34, 1);
    if (run_message(gUnk_08485BD8[gUnk_03006F74->unk33 + 0x14]) && (KEYS_LO(gNewKeys) & 1)) {
        gUnk_03005010.unk6 = 0xFF07;
        play_sound_effect(0xD);
    }
    if (gUnk_03005010.unk8[0][1] == 0xFF07 || gUnk_03005010.unk8[1][1] == 0xFF07) {
        init_blend_effect(gUnk_03006F74->unk50, 0, 0, 1, 0xC0);
        gGameSubState++;
    }
}

void scene_fade_or_transition(void) {
    if (blend_fade_step_08065598(gUnk_03006F74->unk50)) {
        clear_battle_sprite_slot(0, 0x80);
        gGameState = 0x14;
        gGameSubState = 0;
    } else {
        load_medapart_sprite_animation(gUnk_03006F74->unk31, gUnk_03006F74->unk33, 0);
        load_medapart_sprite_animation(gUnk_03006F74->unk32, gUnk_03006F74->unk34, 1);
    }
}

// guess: link Medapart trade scene, sub-states gUnk_080AFA6C by gGameSubState
void sub_080637D0(void) {
    struct FuncTable13 t = gUnk_080AFA6C;

    if (gUnk_03000430 == 2) {
        u32 v = 0x200;
        CpuFastSet(&v, gUnk_03002414->unkB84, 0x01000100);
    }
    t.f[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

#define TM(cnt, i) (*(u16 *)(((((cnt) >> 8) & 0x1F) << 11) + (0x06000000 + (i) * 2)))

void sub_0806384C(void) {
    u8 *src;
    u8 *dst;
    u32 i;
    u32 zero;
    u32 size;
    struct Unk_03006F74 *w;
    struct Unk_03006F74 *w2;
    s32 f;
    s32 j;
    vu16 *bg2, *bg3;

    src = (u8 *)0x02023000;
    dst = (u8 *)&gUnk_03006F74->unk230;
    for (i = 0; i < 0x40; i++)
        *dst++ = *src++;
    if (sub_08074B68() != 0x18)
        play_song(0x18);
    zero = 0;
    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    reset_bg_scroll();
    clear_battle_sprite_slot(0, 0x80);
    REG_DISPCNT = 0x60;
    REG_BLDCNT = 0x2FF;
    REG_BLDY = 0x10;
    REG_BG1CNT = 0x1E05;
    bg2 = &REG_BG2CNT;
    *bg2 = 0x1B06;
    bg3 = &REG_BG3CNT;
    *bg3 = 0x3C07;
    decompress_and_write_tilemap(gUnk_0879FDC0, REG_BG1CNT);
    decompress_and_write_tilemap(gUnk_0879FB10, *bg2);
    decompress_and_write_tilemap(gUnk_087A0050, *bg3);
    *bg2 = 0x1D06;
    decompress_and_write_tilemap(gUnk_0879FEFC, *bg2);
    size = dma3_copy_or_decompress(gUnk_0879E618, (void *)0x02030000);
    CpuCopy16((void *)0x02030000, (void *)0x06004000, size);
    lz_decompress_dispatch(gUnk_08784CB0, (void *)(size + 0x06004000));
    gUnk_03006F74->unk36 = (size >> 5) + 4;
    lz_decompress_dispatch(gUnk_084C3208, (void *)(size + 0x06004080));
    CpuFastSet(gUnk_0879E4D8, (void *)PLTT, 0x50);
    CpuFastSet(gUnk_0850DD18 + 0x30, (void *)0x050003A0, 8);
    CpuFastSet(gUnk_0850DD18 + 0x30, (void *)0x0202F9A0, 8);
    CpuFastSet(gUnk_084E2E98, (void *)0x05000200, 8);
    CpuFastSet(gUnk_0850DD18 + 0x20, (void *)0x05000220, 8);
    CpuFastSet(gUnk_0850DD18, (void *)0x05000240, 8);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    w = gUnk_03006F74;
    w->unk3A = 0x280;
    f = w->unk7A;
    if (f == 0) {
        u32 medal;
        u32 t;
        u32 buf;
        const u8 *const *names;
        s32 lvl;
        u16 e;
        u16 tt;
        u16 *p;

        medal = w->unk230.unk1;
        sub_08062AB0(medal, w->unk230.unk8);
        render_text_sprites_08040DB8(gUnk_03006F74->unk230.unkA, 0x20, 4, 4, 0xA, 2, f, 1);
        j = 0;
        t = size >> 5;
        buf = (u32)gUnk_03000440.unk9E;
        names = (const u8 *const *)gUnk_083B6410;
        for (; j <= 9; j++)
            *(u8 *)(j + buf) = names[medal][j];
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 5, 8, 0xA, 1, 1, 1);
        w2 = gUnk_03006F74;
        lvl = w2->unk230.unk5;
        if (lvl == 100) {
            TM(REG_BG1CNT, 0x10D) = (w2->unk36 + 0x14) | 0x7000;
            TM(REG_BG1CNT, 0x12D) = (gUnk_03006F74->unk36 + 0x15) | 0x7000;
            TM(REG_BG1CNT, 0x10E) = (gUnk_03006F74->unk36 + 0x16) | 0x7000;
            TM(REG_BG1CNT, 0x12E) = (gUnk_03006F74->unk36 + 0x17) | 0x7000;
        } else {
            TM(REG_BG1CNT, 0x10D) = (w2->unk36 + lvl / 10 * 2) | 0x7000;
            TM(REG_BG1CNT, 0x12D) = (gUnk_03006F74->unk36 + lvl / 10 * 2 + 1) | 0x7000;
            TM(REG_BG1CNT, 0x10E) = (gUnk_03006F74->unk36 + lvl % 10 * 2) | 0x7000;
            TM(REG_BG1CNT, 0x12E) = (gUnk_03006F74->unk36 + lvl % 10 * 2 + 1) | 0x7000;
        }
        CpuSet(gUnk_084C21BC + medal * 0x80, (void *)(size + 0x06004000), 0x40);
        tt = t;
        e = tt | 0x6000;
        p = (u16 *)(VRAM + (((REG_BG1CNT >> 8) & 0x1F) << 11)) + 3 + 8 * 32;
        *p = e;
        p++;
        *p = e + 1;
        p += 31;
        *p = e + 2;
        p++;
        *p = e + 3;
    } else {
        w->unk40[0] = TM(*bg2, 0x10C);
        w->unk40[1] = TM(*bg2, 0x10D);
        w->unk40[2] = TM(*bg2, 0x12C);
        w->unk40[3] = TM(*bg2, 0x12D);
        TM(*bg2, 0x10C) = TM(*bg2, 0x10B);
        TM(*bg2, 0x10D) = TM(*bg2, 0x10B);
        TM(*bg2, 0x12C) = TM(*bg2, 0x12B);
        TM(*bg2, 0x12D) = TM(*bg2, 0x12B);
    }
    animate_battle_scroll_tiles();
    init_blend_effect(gUnk_03006F74->unk50, 0x10, 0, -1, 0xC0);
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gGameSubState++;
}

void sub_08063D44(void) {
    if (blend_fade_step_08065598(gUnk_03006F74->unk50)) {
        CpuFastSet((void *)0x05000200, gPaletteBackup, 0x40);
        gGameSubState++;
        gUnk_03006F74->unk3C = 600;
        text_window_init(1, 0, 1);
    }
}

void sub_08063D90(void) {
    if (gUnk_03006F74->unk7A)
        run_message(gUnk_08485BD8[24]);
    if (gUnk_03005010.unk8[gUnk_03000B90 == 0][1] == 0xFEDF)
        gGameState = 0x1A;
    else if (gUnk_03005010.unk8[0][1] == 0xFDEF && gUnk_03005010.unk8[1][1] == gUnk_03005010.unk8[0][1]) {
        gGameSubState++;
        gUnk_03006F74->unk48 = 0;
        if (gUnk_03006F74->unk7A)
            text_window_init(1, 0, 1);
    } else
        gUnk_03005010.unk6 = 0xFDEF;
}

static inline s16 link_packet_hi(u16 pkt) {
    return (pkt & 0xF) << 8 | 0xC000;
}

void sub_08063E38(void) {
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
    if (s->unk7A) {
        n = s->unk48;
        p = buf + n;
        if ((pkt & 0xF000) == 0xC000 && (n & 0xF) == ((pkt >> 8) & 0xF)) {
            *p = pkt;
            gUnk_03006F74->unk48++;
        }
        if (gUnk_03006F74->unk48 > 0x3F)
            gUnk_03005010.unk6 = 0xFF00;
        else
            gUnk_03005010.unk6 = gUnk_03006F74->unk48 | 0xFE00;
    } else {
        u16 t = pkt & 0xFF00;
        if (t == 0xFF00)
            gUnk_03005010.unk6 = t;
        if (t == 0xFE00) {
            p = buf + (pkt & 0xFF);
            v = *p;
            gUnk_03005010.unk6 = v | link_packet_hi(pkt);
        }
    }
    if (gUnk_03005010.unk8[0][1] == 0xFF00 && gUnk_03005010.unk8[1][1] == gUnk_03005010.unk8[0][1]) {
        if (gUnk_03006F74->unk7A) {
            export_medals_to_buffer(buf);
            sub_08062AB0(buf[1], buf[8]);
        } else
            medal_remove_by_id(buf[1]);
        gGameSubState++;
    }
}

void sub_08063F64(void) {
    gGameSubState++;
}

void sub_08063F74(void) {
    if (run_message(gUnk_08485BD8[25])) {
        struct Unk_03006F74 *s;
        animate_battle_scroll_tiles();
        s = gUnk_03006F74;
        if ((s16)--s->unk3C < 0) {
            gGameSubState++;
            s->unk3C = 0;
        }
    }
}

#define BG1(o) (*(u16 *)(VRAM + (o) + (((REG_BG1CNT >> 8) & 0x1F) << 11)))
#define BG2(o) (*(u16 *)(VRAM + (o) + (((REG_BG2CNT >> 8) & 0x1F) << 11)))

void sub_08063FB4(void) {
    struct Unk_03006F74 *s;
    s16 t;
    u8 lvl;
    s32 i;

    animate_battle_scroll_tiles();
    s = gUnk_03006F74;
    t = ++s->unk3C;
    if (t > 0xF) {
        gGameSubState++;
        if (s->unk7A == 0) {
            gUnk_03002C30[0].unk0 &= 0xBFFF;
            return;
        }
        gUnk_03002C30[0].unk0 |= 0x4000;
        lvl = s->unk230.unk5;
        render_text_sprites_08040DB8(s->unk230.unkA, 0x20, 4, 4, 10, 2, 0, 1);
        for (i = 0; i <= 9; i++)
            gUnk_03000440.unk9E[i] = ((const u8 *)gUnk_083B6410[gUnk_03006F74->unk230.unk1])[i];
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 5, 8, 10, 1, 1, 1);
        BG2(0x218) = gUnk_03006F74->unk40[0];
        BG2(0x21A) = gUnk_03006F74->unk40[1];
        BG2(0x258) = gUnk_03006F74->unk40[2];
        BG2(0x25A) = gUnk_03006F74->unk40[3];
        if (lvl == 100) {
            BG1(0x21A) = (gUnk_03006F74->unk36 + 0x14) | 0x7000;
            BG1(0x25A) = (gUnk_03006F74->unk36 + 0x15) | 0x7000;
            BG1(0x21C) = (gUnk_03006F74->unk36 + 0x16) | 0x7000;
            BG1(0x25C) = (gUnk_03006F74->unk36 + 0x17) | 0x7000;
        } else {
            BG1(0x21A) = (gUnk_03006F74->unk36 + (u8)(lvl / 10) * 2) | 0x7000;
            BG1(0x25A) = (gUnk_03006F74->unk36 + (u8)(lvl / 10) * 2 + 1) | 0x7000;
            BG1(0x21C) = (gUnk_03006F74->unk36 + (u8)(lvl % 10) * 2) | 0x7000;
            BG1(0x25C) = (gUnk_03006F74->unk36 + (u8)(lvl % 10) * 2 + 1) | 0x7000;
        }
        CpuFastSet(gUnk_084C21BC + gUnk_03006F74->unk230.unk1 * 0x80,
                   (void *)(VRAM + 0x3F80 + gUnk_03006F74->unk36 * 32), 0x20);
        {
            u16 v;
            u16 *dst;
            v = gUnk_03006F74->unk36 - 4;
            v |= 0x6000;
            dst = (u16 *)(VRAM + (((REG_BG1CNT >> 8) & 0x1F) << 11)) + 3 + 8 * 32;
            *dst = v;
            dst++;
            *dst = v + 1;
            dst += 31;
            *dst = v + 2;
            dst++;
            *dst = v + 3;
        }
        return;
    }
    if (t <= 7)
        gUnk_03002C30[0].unk8 = 0x40 - (s16)s->unk3C * 8;
    else
        gUnk_03002C30[0].unk8 = 1;
    if ((s16)gUnk_03006F74->unk3C > 1) {
        gUnk_03002C30[0].unk9 = (s16)gUnk_03006F74->unk3C * 4 + 0x38;
        gUnk_03002C30[0].unk4 = 0x38 - ((s16)gUnk_03006F74->unk3C - 2) * 8;
    }
}

void sub_080642E4(void) {
    struct Unk_03006F74 *s;
    s16 t;

    animate_battle_scroll_tiles();
    s = gUnk_03006F74;
    t = --s->unk3C;
    if (t < 0) {
        s->unk3A = 0x280;
        gGameSubState++;
        return;
    }
    if (t <= 7)
        gUnk_03002C30[0].unk8 = 0x40 - (s16)s->unk3C * 8;
    else
        gUnk_03002C30[0].unk8 = 1;
    s = gUnk_03006F74;
    if ((s16)s->unk3C > 1) {
        gUnk_03002C30[0].unk9 = (s16)s->unk3C * 4 + 0x38;
        gUnk_03002C30[0].unk4 = 0x38 - ((s16)s->unk3C - 2) * 8;
    }
}

void sub_08064360(void) {
    fade_update_tilemap_copy();
    if (gUnk_03006F74->unk3A == 0) {
        text_window_init(1, 0, 1);
        gGameSubState++;
        play_sound_effect(gUnk_03006F74->unk7A ? 0xE : 5);
    }
}

void sub_080643AC(void) {
    if (run_message(gUnk_08485BD8[gUnk_03006F74->unk7A ? 26 : 27])) {
        if (KEYS_LO(gRepeatKeys) & 1) {
            play_sound_effect(0xD);
            gGameSubState++;
        } else if (gUnk_03005010.unk8[gUnk_03000B90 == 0][1] == 0xFEFF)
            gGameSubState++;
    }
}

void sub_08064428(void) {
    if (run_message(gUnk_08485BD8[gUnk_03006F74->unk7A ? 26 : 27])) {
        gUnk_03005010.unk6 = 0xFEFF;
        if (gUnk_03005010.unk8[0][1] == 0xFEFF && gUnk_03005010.unk8[1][1] == gUnk_03005010.unk8[0][1]) {
            gGameSubState++;
            init_blend_effect(gUnk_03006F74->unk50, 0, 0, 1, 0xC0);
        }
    }
}

void sub_08064498(void) {
    if (blend_fade_step_08065598(gUnk_03006F74->unk50)) {
        gGameState = 0x14;
        gGameSubState = 0;
    }
}

// guess: link Medal exchange scene, sub-states gUnk_080AFAA0 by gGameSubState
void sub_080644C4(void) {
    struct FuncTable12 t = gUnk_080AFAA0;

    if (gUnk_03000430 == 2) {
        u32 fill = 0x200;
        CpuFastSet(&fill, gUnk_03002414->unkB84, 0x01000100);
    }
    t.f[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}
