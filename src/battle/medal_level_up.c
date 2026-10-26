// Mode-2 state 24, started by sub_08067A48 from battle/prebattle.c after a won Robattle for each Medal with
// new stats. Sub-states gUnk_080AFEC4: decompress the Medal sprite, sparkle sprites, two messages, then back
// to mode 0 state 6 (after-battle). Name is a guess (Medal level-up).
#include "global.h"

void sub_08067A48(u8 slot) {
    gUnk_030017EC = slot;
    gGameMode = 2;
    gGameState = 0x18;
    gGameSubState = 0;
}

static void update_battle_sprite_explosions(void) {
    int i, j, k;
    u16 t;
    struct Unk_03002C30 *s;
    for (i = 0; i < 16; i = j) {
        struct Unk_03002C30 *base = gUnk_03002C30;
        k = i + 1;
        s = &base[k];
        t = s->unk1A;
        j = k;
        if (t == 0) {
            s->unk2 = 0x78;
            s->unk4 = 0x28;
            s->unkC_8 = s->unk2 << 8;
            s->unk10_8 = s->unk4 << 8;
            s->unkC_0 = rng_next_080424B8();
            s->unk10_0 = rng_next_080424B8();
            s->unk1A = 0x3F;
            s->unk8 = 0;
            s->unk9 = 0;
            s->unk0 &= ~8;
        } else {
            if (--s->unk1A <= 0xF)
                s->unk0 |= 8;
            s->unkC_8 += ((s8 *)s)[0xC] * 4;
            s->unk10_8 += ((s8 *)s)[0x10] * 4;
            s->unk2 = s->unkC_8 >> 8;
            s->unk4 = s->unk10_8 >> 8;
            s->unk8 = 0x40 - (u8)s->unk1A;
            s->unk9 = 0x40 - (u8)s->unk1A;
        }
    }
    REG_BLDCNT = 0xC40;
    REG_BLDALPHA = (gUnk_03006F74->unk48-- & 0xF) | 0x1000;
    REG_BLDY = 8;
}

void init_scene_with_palette_and_song_25(void) {
    u16 pal[16] = {0, 0x6FFF, 0x6B7A, 0x66D5, 0x622F, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    u8 slot = gUnk_030017EC;
    u32 zero;
    int i;
    u32 size;
    u8 *vram;
    play_song(0x19);
    zero = 0;
    CpuFastSet(&zero, vram = (u8 *)VRAM, 0x01006000);
    clear_battle_sprite_slot(0, 0x80);
    reset_bg_scroll();
    REG_DISPCNT = 0x60;
    REG_BG1CNT = 0x1E05;
    REG_BG2CNT = 0x3D06;
    REG_BG3CNT = 0x1C07;
    decompress_and_write_tilemap(gUnk_087A7F98, REG_BG1CNT);
    decompress_and_write_tilemap(gUnk_087A80E8, REG_BG2CNT);
    decompress_and_write_tilemap(gUnk_087A8324, REG_BG3CNT);
    size = dma3_copy_or_decompress(gUnk_087A46F8, (void *)0x02030000);
    CpuFastSet((void *)0x02030000, (void *)0x06004000, (size << 9) >> 11);
    size = 0x1800;
    gUnk_03006F74->unk36 = 0xC4;
    CpuFastSet(gUnk_084C21BC + gUnk_03000BE0[slot].unk1 * 0x80, vram + size, 0x20);
    lz_decompress_dispatch(gUnk_084C3208, (void *)(size + 0x06000080));
    {
        u16 t = 0x60C0;
        u32 bg = ((REG_BG0CNT >> 8) & 0x1F) * 0x800;
        u32 a = 0x06000286;
        u16 *d;
        d = (u16 *)(bg + a);
        *d = t;
        d = (u16 *)(bg + (a + 2));
        *d = t + 1;
        d = (u16 *)(bg + 0x060002C6);
        *d = t + 2;
        d = (u16 *)(bg + 0x060002C8);
        *d = t + 3;
    }
    CpuFastSet(gUnk_087A44F8, (void *)0x0202FA00, 0x80);
    CpuFastSet(gUnk_084E2E38, (void *)0x0202F9E0, 8);
    lz_decompress_dispatch(gUnk_08785F34, (void *)0x06010000);
    CpuFastSet(gUnk_084E2E98, (void *)0x0202F800, 8);
    CpuFastSet(gUnk_0850DD58, (void *)0x0202F820, 8);
    CpuFastSet(gUnk_0850DD58 - 0x20, (void *)0x0202F840, 8);
    CpuFastSet(pal, (void *)0x0202F860, 8);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    for (i = 0; i < 16; i++) {
        gUnk_03002C30[i + 1].unk0 = 0xCA00;
        gUnk_03002C30[i + 1].unk2 = 0x78;
        gUnk_03002C30[i + 1].unk4 = 0x28;
        gUnk_03002C30[i + 1].unk1C = 2;
        gUnk_03002C30[i + 1].unkA = 3;
        gUnk_03002C30[i + 1].unk6 = 0x117;
        gUnk_03002C30[i + 1].unk8 = 0x40;
        gUnk_03002C30[i + 1].unk9 = 0x40;
        gUnk_03002C30[i + 1].unk1A = (i & 3) << 4;
    }
    REG_BLDCNT = 0xC40;
    REG_BLDALPHA = 0x1010;
    REG_BLDY = 8;
    gGameSubState++;
}

void decompress_medal_sprite_to_vram(void) {
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
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x0600029A) =
            (gUnk_03006F74->unk36 + (u8)(gUnk_03000BE0[gUnk_030017EC].unk5 / 10u) * 2) | 0x7000;
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x060002DA) =
            (gUnk_03006F74->unk36 + (u8)(gUnk_03000BE0[gUnk_030017EC].unk5 / 10u) * 2 + 1) | 0x7000;
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x0600029C) =
            (gUnk_03006F74->unk36 + (u8)(gUnk_03000BE0[gUnk_030017EC].unk5 % 10u) * 2) | 0x7000;
        *(u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + 0x060002DC) =
            (gUnk_03006F74->unk36 + (u8)(gUnk_03000BE0[gUnk_030017EC].unk5 % 10u) * 2 + 1) | 0x7000;
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

void sub_080680A4(void) {
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

void sub_08068104(void) {
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

void sub_08068194(void) {
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

void battle_end_wait_for_confirm(void) {
    update_battle_sprite_explosions();
    if (run_message(gUnk_08485788[0x12]) && (*(u8 *)&gNewKeys & 1)) {
        init_blend_effect(gUnk_03006F74->unk50, 0, 0, 1, 0xC0);
        gGameSubState++;
    }
}

void advance_fade_and_transition_state(void) {
    if (blend_fade_step_08065598(gUnk_03006F74->unk50)) {
        gGameMode = 0;
        gGameState = 6;
        gGameSubState = 0x50;
    }
}

void dispatch_battle_end_substate(void) {
    struct FuncTable7 t = gUnk_080AFEC4;
    t.f[gGameSubState]();
    gBg2Scroll.y++;
}
