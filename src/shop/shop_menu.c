// Mode-2 state 11: the Medaparts shop menu (Buy / Sell / Exit). shop_menu_dispatch runs gUnk_08483E10.
// battle_menu_highlight_icons (4-icon menu highlight) and copy_text_with_lookup are shared with
// shop_list.c and shop_return.c.
#include "global.h"

static inline void *vram_at(u32 off) {
    return (void *)(0x06004000 + off);
}

void battle_menu_highlight_icons(u32 sel, u32 frame) {
    u16 t = (s16)(sel * 4 + gUnk_03006F74->unk38 + 5) | (s16)0xC000;
    s32 i, j;
    u16 *a, *b;
    u16 pal;

    *(u16 *)(((REG_BG2CNT >> 8) & 0x1F) * 0x800 + 0x06000152) = t++;
    *(u16 *)(((REG_BG2CNT >> 8) & 0x1F) * 0x800 + 0x06000154) = t++;
    *(u16 *)(((REG_BG2CNT >> 8) & 0x1F) * 0x800 + 0x06000192) = t++;
    *(u16 *)(((REG_BG2CNT >> 8) & 0x1F) * 0x800 + 0x06000194) = t;
    for (i = 0; i < 4; i++) {
        a = (u16 *)(VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800) + gUnk_080AFA08[i][0] + gUnk_080AFA08[i][1] * 32;
        b = (u16 *)(VRAM + ((REG_BG2CNT >> 8) & 0x1F) * 0x800) + gUnk_080AFA08[i][0] + (gUnk_080AFA08[i][1] + 1) * 32;
        if (frame & 8)
            pal = (i == sel) ? 0x6000 : 0x5000;
        else
            pal = 0x5000;
        for (j = 0; j < 8; j++) {
            *a = (*a & 0xFFF) | pal;
            a++;
            *b = (*b & 0xFFF) | pal;
            b++;
        }
    }
}

void copy_text_with_lookup(dst, src, unused, i) u8 *dst;
u8 *src;
u32 unused;
u32 i;
{
    do {
        dst[i] = src[i];
        i++;
    } while (src[i] != 0xFF);
    dst[i] = src[i];
    i++;
    dst[i] = src[i];
    dst[2] = gUnk_080AFA10[gUnk_03002420];
}

void shop_menu_dispatch(void) {
    gUnk_08483E10[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_08060C44(void) {
    gUnk_03006F74->unk5 = 0;
    gUnk_03006F74->unk6 = 0;
    gGameSubState = 14;
}

void sub_08060C60(void) {
    gGameSubState = 1;
}

void sub_08060C6C(void) {
    u32 zero;
    vu16 *bg1, *bg2, *bg3;
    u16 v;
    u32 size;
    u32 n;
    u32 vram;
    u32 off;
    u8 *dst;

    zero = 0;
    vram = VRAM;
    CpuFastSet(&zero, (void *)vram, 0x01006000);
    reset_bg_scroll();
    clear_battle_sprite_slot(0, 0x80);
    REG_DISPCNT = 0x60;
    REG_BLDCNT = 0xC42;
    REG_BLDALPHA = 0x10;
    bg1 = &REG_BG1CNT;
    v = 0x1B05;
    *bg1 = v;
    decompress_and_write_tilemap(gUnk_08799838, *bg1);
    bg2 = &REG_BG2CNT;
    v = 0x1A06;
    *bg2 = v;
    decompress_and_write_tilemap(gUnk_087999EC, *bg2);
    v = 0x1E05;
    *bg1 = v;
    v -= 0xFF;
    *bg2 = v;
    bg3 = &REG_BG3CNT;
    v -= 0xFF;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_08798608, *bg1);
    decompress_and_write_tilemap(gUnk_08798824, *bg2);
    decompress_and_write_tilemap(gUnk_08798A34, *bg3);
    size = dma3_copy_or_decompress(gUnk_0879691C, gDecompressBuffer);
    off = 0x4000;
    CpuCopy16(gDecompressBuffer, (void *)(off + vram), size);
    n = lz_decompress_dispatch(gUnk_084C4DB0, vram_at(size));
    gUnk_03006F74->unk38 = (size >> 5) - 1;
    size += n;
    tilemap_offset_tiles_and_palette(size >> 5, 0, 0x1B);
    tilemap_offset_tiles_and_palette(size >> 5, 0, 0x1A);
    n = dma3_copy_or_decompress(gUnk_08798F2C, gDecompressBuffer);
    dst = vram_at(size);
    CpuCopy16(gDecompressBuffer, dst, n);
    gUnk_03006F74->unk36 = ((size + n) >> 5) - 1;
    lz_decompress_dispatch(gUnk_08784CB0, dst += n);
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    lz_decompress_dispatch(gUnk_084C7318, (void *)0x06017E00);
    gGameSubState++;
}

void shop_menu_init(void) {
    u32 zero;
    u8 i;

    zero = 0;
    CpuFastSet(&zero, (void *)0x0600DA80, 0x01000080);
    clear_battle_sprite_slot(0, 0x80);
    gUnk_03002C30[8].unk0 = 0x8004;
    gUnk_03002C30[8].unk1C = 0;
    gUnk_03002C30[8].unkA = 0xE;
    gUnk_03002C30[8].unk6 = 0x307;
    gUnk_03002C30[8].unk2 = 8;
    gUnk_03002C30[8].unk4 = gUnk_03006F74->unk5 * 24 + 0x20;
    gUnk_03002C30[8].unk0 |= 0x1200;
    gUnk_03002C30[8].unk8 = 0x40;
    gUnk_03002C30[8].unk9 = 0x40;
    gUnk_03002C30[7].unk0 = 0xC000;
    gUnk_03002C30[7].unk1C = 2;
    gUnk_03002C30[7].unkA = 1;
    gUnk_03002C30[7].unk6 = 0x1A;
    gUnk_03002C30[7].unk2 = 0x98;
    gUnk_03002C30[7].unk4 = 0;
    for (i = 0; i < 4; i++) {
        gUnk_03002C30[i + 12].unk0 = 0x8000;
        gUnk_03002C30[i + 12].unk1C = 2;
        gUnk_03002C30[i + 12].unkA = 0;
    }
    gUnk_03002C30[13].unk0 |= 0x1000;
    gUnk_03002C30[15].unk0 |= 0x2000;
    gUnk_03002C30[13].unk6 = 5;
    gUnk_03002C30[14].unk6 = 5;
    gUnk_03002C30[12].unk6 = 8;
    gUnk_03002C30[15].unk6 = 8;
    gUnk_03002C30[13].unk2 = 0x48;
    gUnk_03002C30[13].unk4 = 0x2C;
    gUnk_03002C30[14].unk2 = 0x58;
    gUnk_03002C30[14].unk4 = 0x2C;
    gUnk_03002C30[12].unk2 = 0x50;
    gUnk_03002C30[12].unk4 = 0x22;
    gUnk_03002C30[15].unk2 = 0x50;
    gUnk_03002C30[15].unk4 = 0x3E;
    divide_by_10000(gUnk_030004DE, gUnk_03002B70.money);
    render_text_sprites_08040DB8(gUnk_030004DE, 0, 0x15, 1, 7, 0xF, 1, 0);
    gGameSubState++;
}

void sub_08060FD4(void) {
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

void sub_08061080(void) {
    if (gUnk_03006F74->unk6 == 1) {
        struct Unk_03000440 *s;
        u8 *n;

        battle_menu_highlight_icons(gUnk_03006F74->unk19, 8);
        s = &gUnk_03000440;
        n = &s->unk84;
        if (*n <= 8) {
            blend_obj_palettes_to_color_0803F684(0, 0x20 - *n * 4, 0x7FFE);
            blend_obj_palettes_to_color_0803F998(0, 0x20 - *n * 4, 0x7FFD);
            (*n)++;
        } else {
            gUnk_03006F74->unk2 = 0;
            text_window_init(1, 0, 0);
            gUnk_03006F74->unk2 = 0;
            gUnk_03006F74->unk0 = 0;
            gUnk_03006F74->unk6 = 0;
            gGameSubState = 9;
        }
    } else {
        struct Unk_03000440 *s = &gUnk_03000440;
        u8 *n = &s->unk84;

        if (*n <= 8) {
            blend_obj_palettes_to_color_0803F684(0, 0x20 - *n * 4, 0xFFFF);
            blend_obj_palettes_to_color_0803F998(0, 0x20 - *n * 4, 0xFFFF);
            (*n)++;
        } else {
            gUnk_03006F74->unk2 = 0;
            gUnk_03002C30[8].unk0 |= 0x4000;
            text_window_init(1, 0, 0);
            gUnk_03006F74->unk2 = 0;
            gUnk_03006F74->unk0 = 0;
            gGameSubState++;
        }
    }
}

void sub_08061180(void) {
    u8 *buf = gUnk_03006F74->unk270;

    copy_text_with_lookup(buf, gUnk_0848552C);
    if (run_message(buf)) {
        gUnk_03002C30[8].unk0 |= 0x4000;
        gGameSubState++;
    }
}

void sub_080611D0(void) {
    sprite_bob_y(8, gFrameCounter, 8);
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        play_sound_effect(2);
        if (gUnk_03006F74->unk5 != 0)
            gUnk_03006F74->unk5--;
        else
            gUnk_03006F74->unk5 = 2;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        play_sound_effect(2);
        if (gUnk_03006F74->unk5 <= 1)
            gUnk_03006F74->unk5++;
        else
            gUnk_03006F74->unk5 = 0;
    }
    gUnk_03002C30[8].unk4 = gUnk_03006F74->unk5 * 24 + 0x20;
    if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        switch (gUnk_03006F74->unk5) {
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
    } else if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        goto cancel;
    }
}

void sub_080612D8(void) {
    if (game_state_execute_handler_a()) {
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

void sub_08061300(void) {
    struct Unk_03000440 *s = &gUnk_03000440;
    u8 *n = &s->unk84;

    if (*n <= 8) {
        blend_obj_palettes_to_color_0803F684(0, *n * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, *n * 4, 0xFFFF);
        (*n)++;
    } else {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFBFF;
        REG_DISPCNT &= 0xF7FF;
        clear_battle_sprite_slot(0, 0x80);
        dispatch_by_index_0476e8(3);
    }
}

void sub_08061374(void) {
    u8 t = gUnk_03006F74->unk2++;

    if (gUnk_03002C30[8].unk8 > 4) {
        gUnk_03002C30[8].unk8 -= 4;
        gUnk_03002C30[8].unk9 -= 4;
    } else {
        gUnk_03002C30[8].unk0 &= 0xBFFF;
    }
    if (t <= 16) {
        REG_BLDALPHA = (t << 8) | (16 - t);
    } else {
        REG_BLDALPHA = 0x1000;
        REG_DISPCNT &= 0xFDFF;
        gUnk_03002C30[8].unk0 &= 0xBFFF;
        sub_0803FB0C();
        gGameSubState++;
    }
    gUnk_03006F74->unk19 = 0;
}

void sub_0806142C(void) {
    u8 buf[0x30];

    copy_text_with_lookup(buf, gUnk_03006F74->unk5 == 0 ? gUnk_08485551 : gUnk_08485580);
    if (run_message(buf))
        gGameSubState++;
}

void sub_0806146C(void) {
    s8 i;

    for (i = 0; i < 4; i++) {
        if ((gFrameCounter >> 3) & 1)
            gUnk_03002C30[12 + i].unk0 |= 0x4000;
        else if (gUnk_03006F74->unk19 == i)
            gUnk_03002C30[12 + gUnk_03006F74->unk19].unk0 &= 0xBFFF;
    }
    if (KEYS_LO(gNewKeys) & 0x40) {
        play_sound_effect(2);
        gUnk_03006F74->unk19 = 0;
        battle_menu_highlight_icons(0, gFrameCounter);
    }
    if (KEYS_LO(gNewKeys) & 0x80) {
        play_sound_effect(2);
        gUnk_03006F74->unk19 = 3;
        battle_menu_highlight_icons(3, gFrameCounter);
    }
    if (KEYS_LO(gNewKeys) & 0x20) {
        play_sound_effect(2);
        gUnk_03006F74->unk19 = 1;
        battle_menu_highlight_icons(1, gFrameCounter);
    }
    if (KEYS_LO(gNewKeys) & 0x10) {
        play_sound_effect(2);
        gUnk_03006F74->unk19 = 2;
        battle_menu_highlight_icons(2, gFrameCounter);
    }
    if (!(gFrameCounter & 7))
        battle_menu_highlight_icons(gUnk_03006F74->unk19, gFrameCounter);
    if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        for (i = 0; i < 4; i++)
            gUnk_03002C30[12 + i].unk0 |= 0x4000;
        if (gUnk_03006F74->unk19 == 4) {
        back:
            gGameSubState = 0xB;
        } else {
            gUnk_03000440.unk84 = 0;
            gUnk_03006F74->unk48 = 0x2D;
            gGameSubState = 0xC;
        }
    } else if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        for (i = 0; i < 4; i++)
            gUnk_03002C30[12 + i].unk0 &= 0xBFFF;
        REG_DISPCNT |= 0x200;
        gUnk_03002C30[8].unk0 |= 0x4000;
        gUnk_03006F74->unk2 = 0x10;
        goto back;
    }
}

void sub_08061678(void) {
    u8 t = gUnk_03006F74->unk2--;

    if (gUnk_03002C30[8].unk8 < 0x40) {
        gUnk_03002C30[8].unk8 += 4;
        gUnk_03002C30[8].unk9 += 4;
    } else {
        gUnk_03002C30[8].unk9 = 0x40;
    }
    if (t != 0) {
        REG_BLDALPHA = (t << 8) | (16 - t);
    } else {
        REG_BLDALPHA = 16;
        sub_0803FB0C();
        gGameSubState = 4;
    }
}

void sub_080616F8(void) {
    u8 *t;

    battle_menu_highlight_icons(gUnk_03006F74->unk19, gFrameCounter * 2);
    t = &gUnk_03006F74->unk48;
    if (*t != 0)
        (*t)--;
    else if (game_state_execute_handler_a()) {
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

void sub_0806174C(void) {
    struct Unk_03000440 *s = &gUnk_03000440;
    u8 *n = &s->unk84;
    s32 i;

    if (*n <= 8) {
        blend_obj_palettes_to_color_0803F684(0, *n * 4, 0xFFFE);
        blend_obj_palettes_to_color_0803F998(0, *n * 4, 0x7FFD);
        (*n)++;
    } else {
        for (i = 0; i < 4; i++)
            gUnk_03002C30[12 + i].unk0 &= 0xBFFF;
        gUnk_03006F74->unk6 = 1;
        gUnk_03006F74->unk1A = 0;
        *(u8 *)0x02023078 = 0;
        {
            u8 *b;
            u32 z = 0;
            i = 0x77;
            b = (u8 *)0x02023077;
            for (; i >= 0; i--)
                *b-- = z;
        }
        gGameState = 12;
        gGameSubState = 0;
    }
}
