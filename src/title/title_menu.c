// Mode 2 (title side): dispatch_game_state_handler_0805BA94 runs gUnk_08483B00[gGameState], and state 3 is
// the title menu (sub_0805BF88 runs the sub-states at gUnk_08483B78: load graphics, New Game / Continue /
// options input, the options menu, loading the save through save/save_data.c). Leaves to the field (mode 1),
// the new-game prompt (state 28) or mode 0.
#include "global.h"

void dispatch_game_state_handler_0805BA94(void) {
    gUnk_03005010.unk4 = gHeldKeys;
    gUnk_03005010.unk6 = 0;
    gUnk_03006F74 = (struct Unk_03006F74 *)&gUnk_03001800;
    if (gUnk_03005030 != 0 && (*(u32 *)&gUnk_03005010.unk19[3] & 0x00FFFF00)) {
        gGameMode = 0;
        gGameState = 10;
        gGameSubState = 0x10;
    } else {
        gUnk_08483B00[gGameState]();
    }
}

s16 sub_0805BB10(s16 step) {
    u16 a = step;
    s16 n;

    if (a > 0xA0)
        a = 0;
    REG_BLDCNT = 0x844;
    n = a;
    REG_BLDALPHA = gUnk_080AF6F0[n / 8] | 0x1000;
    REG_BLDY = 8;
    return n + 1;
}

static void sub_0805BB64(u8 sel, u8 count) {
    s32 i, j, x, y;
    s32 mask, lo;
    for (i = 0, mask = 0xFFF, lo = 0x6000; i <= 2; i++) {
        x = 6;
        y = i * 3 + 10;
        for (j = 0; j <= 19; j++) {
            u16 *p = (u16 *)(VRAM + (((REG_BG0CNT >> 8) & 0x1F) << 11)) + x + y * 32;
            u16 v = *p & mask;
            u16 c;
            if (sel == i && j < count)
                c = 0x7000;
            else
                c = lo;
            *p = v | c;
            if (j <= 1)
                y++;
            else
                x++;
        }
    }
}

static void sub_0805BBF8(u8 sel) {
    s32 i, j;
    u16 *p;
    u32 v, r;

    for (i = 0; i <= 2; i++) {
        p = (u16 *)(VRAM + (((REG_BG0CNT >> 8) & 0x1F) << 11)) + 7 + (i * 3 + 10) * 32;
        for (j = 0; j <= 10; j++) {
            v = *p;
            v &= 0xFFF;
            if (i == sel)
                r = 0x7000 | v;
            else {
                v |= 0x6000;
                r = v << 16;
                r >>= 16;
            }
            *p = r;
            p++;
        }
    }
}

static void sub_0805BC6C(void) {
    s32 i, j;
    for (i = 0; i <= 2; i++) {
        u16 *p = (u16 *)(VRAM + (((REG_BG0CNT >> 8) & 0x1F) << 11)) + 0x167 + i * 96;
        for (j = 0; j < 16; j++) {
            *p = (*p & 0xFFF) | 0x8000;
            p++;
        }
    }
}

void sub_0805BCC0(u8 sel) {
    u8 cur[3] = {gUnk_03001788, gUnk_03001360, gUnk_03000B94};
    s32 i, j, k;
    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 2; j++) {
            u16 *p = (u16 *)(VRAM + 0xE + (((REG_BG0CNT >> 8) & 0x1F) << 11) + (i * 3 + 11) * 64);
            u16 mask = gUnk_080AF740[i][j];
            for (k = 0; k < 16; k++) {
                if (mask & 0x8000) {
                    u16 v = *p & 0xFFF;
                    if (sel == i)
                        *p = v | (cur[i] == j ? 0xA000 : 0x8000);
                    else
                        *p = v | (cur[i] == j ? 0x9000 : 0x8000);
                }
                mask <<= 1;
                p++;
            }
        }
    }
}

static void sub_0805BDC8(u8 a) {
    u16 buf[32];
    s32 i;
    a = a > 15 ? a - 16 : 0;
    CpuSet((void *)0x0202FB00, buf, 0x04000010);
    for (i = 0; i < 16; i++) {
        u16 c = buf[i];
        u16 t = buf[i + 16];
        s32 r = c & 0x1F;
        s32 g = (c >> 5) & 0x1F;
        s32 b = (c >> 10) & 0x1F;
        s32 r2 = t & 0x1F;
        s32 g2 = (t >> 5) & 0x1F;
        s32 b2 = (t >> 10) & 0x1F;
        r = (r - r2) * a / 32 + r2;
        g = (g - g2) * a / 32 + g2;
        b = (b - b2) * a / 32 + b2;
        buf[i] = (b << 10) | (g << 5) | r;
    }
    CpuSet(buf, (void *)0x05000140, 0x04000008);
}

static void sub_0805BEA0(u8 sel, u8 f) {
    u16 buf[32];
    s32 i, j;
    for (j = 0; j <= 2; j++) {
        CpuSet((void *)(j * 0x40 + 0x0202FA00), buf, 0x04000010);
        if (j == sel) {
            for (i = 0; i < 16; i++) {
                u16 c = buf[i];
                u16 t = buf[i + 16];
                s32 r = c & 0x1F;
                s32 g = (c >> 5) & 0x1F;
                s32 b = (c >> 10) & 0x1F;
                s32 r2 = t & 0x1F;
                s32 g2 = (t >> 5) & 0x1F;
                s32 b2 = (t >> 10) & 0x1F;
                r = (r - r2) * f / 32 + r2;
                g = (g - g2) * f / 32 + g2;
                b = (b - b2) * f / 32 + b2;
                buf[i] = (b << 10) | (g << 5) | r;
            }
        }
        CpuSet(buf, (void *)(j * 0x40 + PLTT), 0x04000008);
    }
}

void sub_0805BF88(void) {
    gUnk_08483B78[gGameSubState]();
    gBg2Scroll.x++;
    gBg2Scroll.y++;
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_0805BFDC(void) {
    u32 zero = 0;
    CpuFastSet(&zero, (void *)VRAM, 0x01006000);
    reset_bg_scroll();
    free_all_sprites();
    REG_DISPCNT = 0x60;
    init_blend_effect(gUnk_03006F74->unk50, 0x10, 0, -1, 0xC0);
    gGameSubState++;
}

void sub_0805C030(void) {
    u32 size;
    u16 v;
    vu16 *bg0, *bg1, *bg2, *bg3;
    u8 one;

    bg0 = &REG_BG0CNT;
    one = 1;
    v = 0x1F04;
    *bg0 = v;
    bg1 = &REG_BG1CNT;
    v -= 0xFF;
    *bg1 = v;
    bg2 = &REG_BG2CNT;
    v = 0x3D06;
    *bg2 = v;
    bg3 = &REG_BG3CNT;
    v -= 0xFF;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_0878FBB4, *bg0);
    decompress_and_write_tilemap(gUnk_0878FD84, *bg1);
    decompress_and_write_tilemap(gUnk_0878FFC8, *bg2);
    decompress_and_write_tilemap(gUnk_08790128, *bg3);
    size = dma3_copy_or_decompress(gUnk_0878E5F4, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, (void *)0x06004000, size);
    gUnk_03006F74->unk36 = (size >> 5) - 1;
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    CpuFastSet(gUnk_0878E3F4, gPaletteBackupBg, 0x80);
    CpuFastSet(gUnk_0878E3F4, (void *)PLTT, 0x80);
    CpuFastSet(gUnk_084E2E58, gPaletteBackup, 0x80);
    CpuFastSet(gUnk_084E2E58, (void *)(PLTT + 0x200), 0x80);
    gUnk_03002C30[14].unk0 = 0x8000;
    gUnk_03002C30[14].unkB = one;
    gUnk_03002C30[14].unk1C = 2;
    gUnk_03002C30[14].unkA = 0;
    gUnk_03002C30[14].unk6 = 6;
    gUnk_03002C30[14].unk2 = 0x20;
    gUnk_03002C30[14].unk4 = 0x50;
    gUnk_03006F74->unk5 = 0;
    gGameSubState++;
}

void sub_0805C190(void) {
    s32 ret, i, j;
    u16 *p;

    REG_DISPCNT |= 0x100;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03001784.unk0_0 = 0;
    ret = load_save_with_retries();
    if (ret != 0) {
        if (ret < 0) {
            gGameState = 9;
            gGameSubState = 0;
            return;
        }
        for (i = 0; i <= 1; i++) {
            p = (u16 *)(VRAM + (((REG_BG0CNT >> 8) & 0x1F) << 11)) + 9 + (i + 1) * 32;
            for (j = 0; j < 12; j++)
                *p++ = 0;
        }
        gUnk_03006F74->unk5 = 1;
        gUnk_03006F74->unk4 = 1;
        gUnk_03001788 = 0;
        gUnk_03001360 = 0;
        gUnk_03000B94 = 0;
    } else {
        gUnk_03006F74->unk5 = ret;
        gUnk_03006F74->unk4 = ret;
        gUnk_03001784.unk0_0 = 1;
    }
    sub_0805BEA0(gUnk_03006F74->unk5, gFrameCounter & 0x1F);
    sub_0805BCC0(3);
    gGameSubState++;
}

void sub_0805C2C4(void) {
    if (blend_fade_step_08065598(gUnk_03006F74->unk50)) {
        gGameSubState++;
        gUnk_03006F74->unk3A = 0;
        gUnk_03006F74->unk3A = sub_0805BB10(0);
        REG_DISPCNT |= 0x400;
    }
}

void sub_0805C308(void) {
    struct Unk_03006F74 *w;

    gUnk_03006F74->unk3A = sub_0805BB10(gUnk_03006F74->unk3A);
    sub_0805BEA0(gUnk_03006F74->unk5, gFrameCounter & 0x1F);
    if (KEYS_LO(gNewKeys) & 0x40) {
        play_sound_effect(2);
        w = gUnk_03006F74;
        if (w->unk5 == w->unk4)
            w->unk5 = 2;
        else
            w->unk5--;
    }
    if (KEYS_LO(gNewKeys) & 0x80) {
        play_sound_effect(2);
        w = gUnk_03006F74;
        if (w->unk5 == 2)
            w->unk5 = w->unk4;
        else
            w->unk5++;
    }
    if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        if (gUnk_03006F74->unk5 == 2) {
            gUnk_03006F74->unk5 = 0;
            gUnk_03006F74->unk2 = 20;
            sub_0805BDC8(gFrameCounter & 0x1F);
            sub_0805BBF8(gUnk_03006F74->unk5);
            sub_0805BCC0(gUnk_03006F74->unk5);
            sub_0805BEA0(3, 0);
            gUnk_03002C30[14].unk4 = gUnk_03006F74->unk5 * 24 + 0x50;
            gUnk_03002C30[14].unk0 |= 0x4000;
            gGameSubState++;
        } else {
            gUnk_03006F74->unk48 = 45;
            gGameSubState = 6;
        }
    }
}

// guess: title options menu input (rows: Robattle time limit gUnk_03001788, message skip gUnk_03001360,
// battle music gUnk_03000B94 with a preview); A / B leave the menu
void sub_0805C428(void) {
    gUnk_03006F74->unk3A = sub_0805BB10(gUnk_03006F74->unk3A);
    sub_08041C14(14, gFrameCounter, 32);
    sub_0805BDC8(gFrameCounter & 0x1F);
    sub_0805BB64(gUnk_03006F74->unk5, 20 - gUnk_03006F74->unk2);
    if (gUnk_03006F74->unk2)
        gUnk_03006F74->unk2--;

    if (KEYS_LO(gNewKeys) & 0x40) {
        play_song(1);
        play_sound_effect(2);
        if (gUnk_03006F74->unk5 == 0)
            gUnk_03006F74->unk5 = 2;
        else
            gUnk_03006F74->unk5--;
        if (gUnk_03006F74->unk5 == 2)
            play_song(gUnk_080AF752[gUnk_03000B94]);
        gUnk_03006F74->unk2 = 20;
    } else if (KEYS_LO(gNewKeys) & 0x80) {
        play_song(1);
        play_sound_effect(2);
        if (gUnk_03006F74->unk5 == 2)
            gUnk_03006F74->unk5 = 0;
        else
            gUnk_03006F74->unk5++;
        if (gUnk_03006F74->unk5 == 2)
            play_song(gUnk_080AF752[gUnk_03000B94]);
        gUnk_03006F74->unk2 = 20;
    } else {
        switch (gUnk_03006F74->unk5) {
        case 0:
            if (KEYS_LO(gNewKeys) & 0x20) {
                play_sound_effect(2);
                if (gUnk_03001788 == 0)
                    gUnk_03001788 = 2;
                else
                    gUnk_03001788--;
            }
            if (KEYS_LO(gNewKeys) & 0x10) {
                play_sound_effect(2);
                if (gUnk_03001788 == 2)
                    gUnk_03001788 = 0;
                else
                    gUnk_03001788++;
            }
            break;
        case 1:
            if (KEY_BITS(gNewKeys).left | KEY_BITS(gNewKeys).right) {
                play_sound_effect(2);
                gUnk_03001360 ^= 1;
            }
            break;
        case 2:
            if (KEYS_LO(gNewKeys) & 0x20) {
                if (gUnk_03000B94 == 0)
                    gUnk_03000B94 = 2;
                else
                    gUnk_03000B94--;
                play_song(gUnk_080AF752[gUnk_03000B94]);
            }
            if (KEYS_LO(gNewKeys) & 0x10) {
                if (gUnk_03000B94 == 2)
                    gUnk_03000B94 = 0;
                else
                    gUnk_03000B94++;
                play_song(gUnk_080AF752[gUnk_03000B94]);
            }
            break;
        }
        if (KEYS_LO(gNewKeys) & 0x30)
            sub_0805BCC0(gUnk_03006F74->unk5);
        if (KEY_BITS(gNewKeys).a | KEY_BITS(gNewKeys).b) {
            play_song(1);
            play_sound_effect(4);
            gUnk_03006F74->unk5 = 2;
            gUnk_03002C30[14].unk0 &= 0xBFFF;
            gGameSubState--;
            sub_0805BBF8(3);
            sub_0805BB64(3, 0);
            sub_0805BCC0(3);
        }
        return;
    }
    sub_0805BBF8(gUnk_03006F74->unk5);
    sub_0805BCC0(gUnk_03006F74->unk5);
    gUnk_03002C30[14].unk2 = 32;
    gUnk_03002C30[14].unk4 = gUnk_03006F74->unk5 * 24 + 0x50;
}

void sub_0805C6AC(void) {
    u8 *t = &gUnk_03006F74->unk48;
    if (*t) {
        u8 n = --*t;
        if (n)
            sub_0805BEA0(gUnk_03006F74->unk5, ((gUnk_03006F74->unk48 * 4) & 0x1F) <= 15 ? 0x20 : 0);
        else {
            copy_obj_palette_to_buffer();
            gUnk_03000440.unk84 = n;
        }
    } else if (!is_sound_playing_with_lock(4)) {
        struct Unk_03000440 *b = &gUnk_03000440;
        if (b->unk84 <= 8) {
            s32 w = 31;
            s32 c = (w << 10) | (w << 5) | w;
            blend_obj_palettes_to_color_0803F684(c, b->unk84 * 4, 0xFFFF);
            blend_obj_palettes_to_color_0803F998(c, b->unk84 * 4, 0xFFFF);
            b->unk84++;
        } else {
            REG_DISPCNT &= 0xFDFF;
            switch (gUnk_03006F74->unk5) {
            case 0:
                gUnk_03001784.unk0_0 = 1;
                gGameSubState = 8;
                break;
            case 1:
                gUnk_03001784.unk0_1 = 0;
                gGameSubState = 7;
                break;
            }
        }
    }
}

void sub_0805C7A0(void) {
    s8 i;

    play_song(0);
    play_sound_effect(0);
    eeprom_setup_timer_irq();
    for (i = 0; i <= 15; i++)
        gUnk_03002B74[i] = 0xFE;
    gGameState = 28;
    gGameSubState = 0;
}

void sub_0805C7E8(void) {
    u32 zero = 0;

    play_song(0);
    play_sound_effect(0);
    gGameMode = 1;
    gGameState = 1;
    gGameSubState = zero;
    dispatch_by_index_0476e8(11);
}

void sub_0805C820(void) {
    if (gUnk_03006F74->unk0 != 32) {
        gUnk_03006F74->unk0++;
        REG_BLDY = gUnk_03006F74->unk0 >> 1;
    } else {
        gGameState = 9;
        gGameSubState = 0;
    }
}
