// Mode-2 state 18 (sub_08064C3C, guess: Medal shop): its sub-state table gUnk_08483EB4 directly follows the
// shop list's (gUnk_08483E8C, shop/shop_list.c). Lists the owned Medals (render_battle_medal_names) and charges
// for one (sub_08065484). Name is a guess.
#include "global.h"

static inline void *vram_at(u32 off) {
    return (void *)(0x06004000 + off);
}

void render_battle_medal_names(u8 start) {
    s32 i, j;
    s32 n;
    u8 *p = &gUnk_03006F74->unk30;
    if (*p > 3)
        n = 4;
    else
        n = *p;
    i = 0;
    while (i < n) {
        u16 v;
        u16 *dst;
        for (j = 0; j <= 10; j++)
            gUnk_03002C30[i * 10 + 12 + j].unk0 &= 0xBFFF;
        for (j = 0; j <= 10; j++) {
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

void sub_08064C30(void) {
    gGameSubState = 1;
}

void sub_08064C3C(void) {
    gUnk_08483EB4[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_08064C7C(void) {
    gUnk_03006F74->unk2E = 0;
    gUnk_03006F74->unk2F = 0;
    gGameSubState++;
}

// guess: Medal list screen (pay 100 for a Medal, sub_08065484): builds the owned Medal list in unkB0
void sub_08064CA0(void) {
    u32 zero;
    u32 z = 0;
    s32 i;
    u32 n;
    zero = z;
    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    clear_battle_sprite_slot(0, 0x80);
    *(u16 *)PLTT = z;
    n = 0;
    for (i = 0; i < 30; i++) {
        if (gUnk_03000BE0[i].unk0 & 0x80) {
            gUnk_03006F74->unkB0[n] = i;
            n++;
        }
    }
    gUnk_03006F74->unk30 = n;
    if (gUnk_03000584 != 2) {
        gGameState = 6;
        gGameSubState = 0;
    } else {
        reset_bg_scroll();
        REG_DISPCNT = 0x60;
        gGameSubState++;
    }
}

void sub_08064D3C(void) {
    u32 size;
    u16 v;
    vu16 *bg1, *bg2, *bg3;
    u32 zero;
    u8 i;
    u32 z2;

    bg1 = &REG_BG1CNT;
    v = 0x1F05;
    *bg1 = v;
    bg2 = &REG_BG2CNT;
    v -= 0xFF;
    *bg2 = v;
    bg3 = &REG_BG3CNT;
    v -= 0xFF;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_0879A634, *bg1);
    decompress_and_write_tilemap(gUnk_0879A78C, *bg2);
    decompress_and_write_tilemap(gUnk_0879A8BC, *bg3);
    size = dma3_copy_or_decompress(gUnk_08799D98, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, vram_at(0), size);
    gUnk_03006F74->unk36 = (size >> 5) - 1;
    zero = 0;
    CpuFastSet(gUnk_084C21BC, vram_at(size), 0x400);
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    gUnk_03002C30[8].unk0 = 0x8000;
    gUnk_03002C30[8].unk1C = 2;
    gUnk_03002C30[8].unkA = zero;
    gUnk_03002C30[8].unk6 = 6;
    gUnk_03002C30[8].unk2 = 0xC;
    gUnk_03002C30[8].unk4 = gUnk_03006F74->unk2E * 16 + 0x1C;
    for (i = 0; i <= 1; i++) {
        gUnk_03002C30[i + 10].unk0 = 0x8000;
        gUnk_03002C30[i + 10].unk1C = 2;
        gUnk_03002C30[i + 10].unkA = 0;
        gUnk_03002C30[i + 10].unk6 = 8;
        gUnk_03002C30[i + 10].unk2 = 0x20;
        gUnk_03002C30[i + 10].unk4 = i * 72 + 0x14;
    }
    gUnk_03002C30[11].unk0 |= 0x2000;
    z2 = 0;
    gUnk_03002C30[7].unk0 = 0xC000;
    gUnk_03002C30[7].unk1C = 2;
    gUnk_03002C30[7].unkA = 10;
    gUnk_03002C30[7].unk6 = 0x1A;
    gUnk_03002C30[7].unk2 = 0x98;
    gUnk_03002C30[7].unk4 = z2;
    divide_by_10000(gUnk_030004DE, gMoney);
    render_text_sprites_08040DB8(gUnk_030004DE, 0, 0x15, 1, 7, 0xF, 1, z2);
    gGameSubState++;
}

void sub_08064EFC(void) {
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

void sub_08065020(void) {
    struct Unk_03000440 *s = &gUnk_03000440;
    if (s->unk84 <= 8) {
        blend_obj_palettes_to_color_0803F684(0, 32 - s->unk84 * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - s->unk84 * 4, 0xFFFF);
        s->unk84++;
    } else {
        gUnk_03006F74->unk4C = 0;
        text_window_init(1, 0, 0);
        gUnk_03006F74->unk6 = 0;
        gGameSubState++;
    }
}

void sub_08065090(void) {
    u32 r = 1;
    u8 keys;
    u32 se;
    if (gUnk_03006F74->unk4C) {
        if (game_state_execute_handler_a()) {
            gUnk_03006F74->unk4C = 0;
            text_window_init(1, 0, 0);
        }
    } else if (run_message(gUnk_08485788[13]))
        r = 0;
    if (r != 0)
        return;
    sprite_bob_y(8, gFrameCounter, 12);
    gUnk_03002C30[8].unk0 |= 0x4000;
    if (gUnk_03006F74->unk30 > 4) {
        if (gUnk_03006F74->unk2F != 0) {
            if ((gFrameCounter & 0xF) <= 9)
                gUnk_03002C30[10].unk0 |= 0x4000;
            else
                gUnk_03002C30[10].unk0 &= 0xBFFF;
        } else
            gUnk_03002C30[10].unk0 &= 0xBFFF;
        if (gUnk_03006F74->unk2F + 4 >= gUnk_03006F74->unk30)
            gUnk_03002C30[11].unk0 &= 0xBFFF;
        else if ((gFrameCounter & 0xF) <= 9)
            gUnk_03002C30[11].unk0 |= 0x4000;
        else
            gUnk_03002C30[11].unk0 &= 0xBFFF;
    }
    if ((keys = KEYS_LO(gRepeatKeys) & 0x40)) {
        se = 2;
        if (gUnk_03006F74->unk2E != 0)
            gUnk_03006F74->unk2E--;
        else if (gUnk_03006F74->unk2F != 0)
            gUnk_03006F74->unk2F--;
        else if (gUnk_03006F74->unk30 <= 3)
            gUnk_03006F74->unk2E = gUnk_03006F74->unk30 - 1;
        else
            goto skip;
        if (se != 0)
            play_sound_effect(se);
    skip:
        render_battle_medal_names(gUnk_03006F74->unk2F);
    } else if (KEYS_LO(gRepeatKeys) & 0x80) {
        se = 2;
        if (gUnk_03006F74->unk30 <= 3) {
            if (gUnk_03006F74->unk2E == gUnk_03006F74->unk30 - 1)
                gUnk_03006F74->unk2E = keys;
            else
                gUnk_03006F74->unk2E++;
        } else if (gUnk_03006F74->unk2E == 3) {
            if (gUnk_03006F74->unk2F == gUnk_03006F74->unk30 - 4)
                se = 0;
            else
                gUnk_03006F74->unk2F++;
        } else
            gUnk_03006F74->unk2E++;
        if (se != 0)
            play_sound_effect(se);
        render_battle_medal_names(gUnk_03006F74->unk2F);
    } else if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        gUnk_03002C30[10].unk0 &= 0xBFFF;
        gUnk_03002C30[11].unk0 &= 0xBFFF;
        gUnk_03002C30[8].unk2 = 12;
        gUnk_03006F74->unk4C = 1;
        gUnk_03000440.unk1B = 0;
        gGameSubState = 9;
        open_choice_menu(1, 0x16, 7);
        return;
    } else {
        if (KEYS_LO(gNewKeys) & 2) {
            play_sound_effect(5);
            gUnk_03002C30[8].unk0 &= 0xBFFF;
            gUnk_03000440.unk1B = 0;
            gUnk_03000440.unk84 = 0;
            gGameSubState = 7;
        }
        return;
    }
    gUnk_03002C30[8].unk2 = 12;
    gUnk_03002C30[8].unk4 = gUnk_03006F74->unk2E * 16 + 0x1C;
}

void sub_08065348(void) {
    if (game_state_execute_handler_a()) {
        struct Unk_03000440 *s = &gUnk_03000440;
        if (s->unk84 <= 8) {
            blend_obj_palettes_to_color_0803F684(0, s->unk84 * 4, 0xFFFF);
            blend_obj_palettes_to_color_0803F998(0, s->unk84 * 4, 0xFFFF);
            s->unk84++;
        } else {
            REG_DISPCNT &= ~0x200;
            gGameState = 6;
            gGameSubState = 0;
        }
    }
}

void sub_080653B4(void) {
    if (game_state_execute_handler_a()) {
        struct Unk_03000440 *s = &gUnk_03000440;
        if (s->unk84 <= 8) {
            blend_obj_palettes_to_color_0803F684(0, s->unk84 * 4, 0xFFFF);
            blend_obj_palettes_to_color_0803F998(0, s->unk84 * 4, 0xFFFF);
            s->unk84++;
        } else {
            REG_DISPCNT &= ~0x200;
            clear_battle_sprite_slot(0, 0x80);
            dispatch_by_index_0476e8(2);
        }
    }
}

void sub_08065418(void) {
    u32 r = 1;
    if (gUnk_03006F74->unk4C) {
        if (game_state_execute_handler_a()) {
            gUnk_03006F74->unk4C = 0;
            text_window_init(1, 0, 0);
        }
    } else if (run_message(gUnk_08485788[15]))
        r = 0;
    if (r == 0 && KEYS_LO(gNewKeys) & 3) {
        sub_0803FB0C();
        gGameSubState = 5;
    }
}

void sub_08065484(void) {
    u32 r = 1;
    u32 sel;
    if (gUnk_03006F74->unk4C) {
        if (game_state_execute_handler_a()) {
            gUnk_03006F74->unk4C = 0;
            text_window_init(1, 0, 0);
        }
    } else if (run_message(gUnk_08485788[14]))
        r = 0;
    if (r == 0 && (r = poll_choice_menu()) != 0) {
        u32 c = r & 0xF0;
        if (c) {
            gUnk_03006F74->unk4C = 1;
            gGameSubState = 5;
        } else if (gMoney <= 99) {
            gGameSubState = 8;
            gUnk_03006F74->unk3A = 0xB4;
            gUnk_03006F74->unk4C = 1;
        } else {
            gMoney -= 100;
            gUnk_030017EC = gUnk_03006F74->unkB0[gUnk_03006F74->unk2E + gUnk_03006F74->unk2F];
            gUnk_03000440.unk84 = c;
            gGameSubState = 6;
        }
    }
}
