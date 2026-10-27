// Message window: text_window_init sets it up, run_message steps the window state machine
// gUnk_083B279C by gUnk_03000440.unk4 (open, dim palettes, show the frame, clear, print with
// message_print_step, run commands gUnk_083B27C0, close). Includes the glyph renderer and the text tile
// flush helpers. Draws through engine/tilemap and engine/palette_blend; used by every scene with text.

#include "global.h"

static void sub_0803FEA8(void);
static void sub_0803FEB8(void);
static void sub_0804070C(void);
static void sub_080407A4(void);
static void sub_08040820(void);

void text_window_init(u8 a, u8 b, u32 c) {
    u8 c8 = c;

    mem_fill8((u8 *)&gUnk_03000440, 0x28, 0);
    gUnk_03000440.unk0 = a;
    gUnk_03000440.unk1 = b;
    gUnk_03000440.unk2 = c8;
    gUnk_03000440.unkF = 0xFF;
    gUnk_03000440.unk10 = -1;
    gUnk_03000440.unk11 = -1;
    decompress_bg_tiles_to_vram_bg();
    CpuFastSet(gUnk_084C6998, (void *)(OBJ_PLTT - 0x40), 8);
    if (c8 == 1)
        setup_bg0_display_layer();
}

void sub_0803FB0C(void) {
    gUnk_03000440.unk4 = 4;
    gUnk_03000440.unkC = 0;
    gUnk_03000440.unk14 = 0;
    gUnk_03000440.unk15 = 0;
    gUnk_03000440.unk16 = 0;
    gUnk_03000440.unk17 = 0;
    gUnk_03000440.unk18 = 0;
    gUnk_03000440.unk19 = 0;
    gUnk_03000440.unk1A = 0;
    gUnk_03000440.unk1B = 0;
    gUnk_03000440.unk24 = 0;
    gUnk_03000440.unk25 = 0;
    gUnk_03000440.unk27 = 0;
}

u32 run_message(const void *msg) {
    gUnk_03000440.unk8 = msg;
    gUnk_083B279C[gUnk_03000440.unk4]();
    if (gUnk_03000440.unk4 > 7)
        return 1;
    return 0;
}

// run_message state 0: back up the palettes, then dim them (state 1); unk0 != 0 skips to state 2.
void message_open(void) {
    u8 v = gUnk_03000440.unk0;
    if (v == 0) {
        palette_backup_from_hardware();
        gUnk_03000440.unk1C = v;
        gUnk_03000440.unk4++;
    } else {
        gUnk_03000440.unk4 = 2;
    }
}

// run_message state 1: blend all palettes toward 0x01B2 by unk1C * 2 / 32, 10 frames.
void message_dim_palettes_step(void) {
    bg_palettes_blend_masked_now(0x1B2, gUnk_03000440.unk1C * 2, 0x1FFF);
    obj_palettes_blend_masked_now(0x1B2, gUnk_03000440.unk1C * 2, 0x3FFF);
    if (gUnk_03000440.unk1C > 8)
        gUnk_03000440.unk4++;
    else
        gUnk_03000440.unk1C++;
}

// run_message state 2: unk2 == 1 jumps to state 4; else show BG0 (the window) at BG0CNT 0x500.
void message_show_window(void) {
    if (gUnk_03000440.unk2 == 1) {
        gUnk_03000440.unk4 = 4;
    } else {
        gUnk_03000440.unk4++;
        gUnk_03000440.unk26 = 0;
        REG_DISPCNT |= 0x100;
        REG_BG0CNT = 0x500;
    }
}

// run_message state 3: draws the window frame in three frames (unk26 0-2, reverse of sub_08040A40), then state 4.
void message_open_window_frame(void) {
    switch (gUnk_03000440.unk26) {
    case 0:
        lz_decompress_dispatch(gUnk_08487630, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gUnk_08488600, REG_BG0CNT, 1);
        gUnk_03000440.unk26++;
        break;
    case 1:
        lz_decompress_dispatch(gUnk_08487524, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gUnk_084885A8, REG_BG0CNT, 1);
        gUnk_03000440.unk26++;
        break;
    case 2:
        lz_decompress_dispatch(gUnk_084873D0, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gUnk_08488540, REG_BG0CNT, 1);
        gUnk_03000440.unk26++;
        break;
    default:
        gUnk_03000440.unk4++;
        break;
    }
}

void message_clear_text_area(void) {
    u32 i;
    u8 *dst;

    for (i = 0, dst = (u8 *)0x06000280; i <= 0x33; i++) {
        CpuFastSet(gUnk_084C01C8, dst, 0x10);
        dst += 0x40;
    }
    write_tilemap_rect(0x1A, 4, 2, 0xE, gUnk_083B4AE0[18], REG_BG0CNT, 0);
    gUnk_03000440.unk4++;
    message_print_step();
}

void message_print_step(void) {
    gUnk_03000440.unk13 = 0;
    do {
        switch (gUnk_03000440.unk8[gUnk_03000440.unkC]) {
        case 0xF9:
            if (gUnk_03000440.unk19 == 1) {
                gUnk_03000440.unk13 = 0;
                reset_text_tile_state();
            } else if (gUnk_03000440.unk19 == 2) {
                gUnk_03000440.unk13 = 1;
                update_text_compose_and_input();
            } else {
                gUnk_03000440.unk13 = 0;
                sub_080402B4();
                if (gUnk_03000440.unk1A == 0xFF)
                    gUnk_03000440.unk13 = 0;
            }
            break;
        case 0xFA:
            sub_0804070C();
            if (gUnk_03000440.unk1A == 0xFF)
                gUnk_03000440.unk13 = 0;
            else
                gUnk_03000440.unk13 = 1;
            break;
        case 0xF7:
            sub_080407A4();
            if (gUnk_03000440.unk1A == 0xFF)
                gUnk_03000440.unk13 = 0;
            else
                gUnk_03000440.unk13 = 1;
            break;
        case 0xFB:
            sub_0803FEB8();
            gUnk_03000440.unk13 = 1;
            break;
        case 0xFC:
            if (update_text_compose_and_input() == 1)
                gUnk_03000440.unkC++;
            break;
        case 0xFD:
            if (gUnk_03000440.unk19 == 2) {
                gUnk_03000440.unk13 = 1;
                if (update_text_compose_and_input() == 1)
                    gUnk_03000440.unkC++;
            } else {
                gUnk_03000440.unk13 = 0;
                reset_text_tile_state();
                if (gUnk_03000440.unk19 == 0)
                    gUnk_03000440.unkC++;
            }
            break;
        case 0xFE:
            sub_0803FEA8();
            break;
        case 0xF8:
            gUnk_03000440.unk27 ^= 1;
            gUnk_03000440.unkC++;
            break;
        case 0xFF:
            sub_08040820();
            gUnk_03000440.unk13 = 1;
            break;
        default:
            if (gUnk_03000440.unk19 == 1) {
                gUnk_03000440.unk13 = 0;
                reset_text_tile_state();
            } else if (gUnk_03000440.unk19 == 2) {
                gUnk_03000440.unk13 = 1;
                update_text_compose_and_input();
            } else {
                gUnk_03000440.unk13 = 0;
                text_render_glyph_step();
                if (gUnk_03000440.unk1A == 0xFF)
                    gUnk_03000440.unk13 = 0;
            }
            break;
        }
    } while (gUnk_03000440.unk13 == 0);
}

static void sub_0803FEA8(void) {
    gUnk_03000440.unkC++;
}

static void sub_0803FEB8(void) {
    u32 anim, set, idx;
    u32 x;
    u8 zero;
    u8 m;
    u8 r;
    struct Unk_03000440 *s;
    u8 n;
    if (((struct TextColBits *)&gUnk_03000440)->col) {
        u8 col = (gUnk_03000440.unk14 + 8) / 8 - 1;
        CpuFastSet(gUnk_02020000, (void *)(col * 0x40 + VRAM + 0x280 + gUnk_03000440.unk17 * 0x680), 16);
    }
    s = &gUnk_03000440;
    zero = 0;
    s->unk14 = zero;
    if (s->unk1 != 2) {
        anim = s->unk8[s->unkC + 1];
        set = (u8)resolve_area_sprite_set(s->unk8[s->unkC + 2]);
        idx = s->unk8[s->unkC + 3];
        if (s->unk12 == 1) {
            if (s->unkF == 0)
                x = 0x13;
            else
                x = 3;
            if ((u8)s->unkF == (u8)anim && (u8)s->unk10 == set) {
                if (set == 0xFF)
                    vram_fill_tilemap_rect(8, 8, x, 5, REG_BG0CNT, zero);
                else
                    load_bg0_tilemap(set, idx, x, 5, anim);
                gUnk_03000440.unkF = anim;
                gUnk_03000440.unk10 = set;
                gUnk_03000440.unk11 = idx;
                gUnk_03000440.unkC += 4;
            } else {
                struct Unk_03000440 *p = &gUnk_03000440;
                if ((n = p->unk1) == 0) {
                    if ((u8)message_portrait_anim_step((u8)p->unk10, (u8)p->unk11, x, 5, p->unkF, 1) != 1)
                        return;
                } else
                    vram_fill_tilemap_rect(8, 8, x, 5, REG_BG0CNT, n = 0);
                p->unkE = n;
                p->unk12 = n;
            }
            return;
        }
        x = 3;
        if (anim == 0)
            x = 0x13;
        if (set == 0xFF) {
            s->unkF = anim;
            s->unk10 = set;
            s->unk11 = idx;
            goto inc;
        }
        if ((m = s->unk1) != 0) {
            load_bg0_tilemap(set, idx, x, 5, anim);
            s->unk12 = 1;
            s->unkF = anim;
            s->unk10 = set;
            s->unk11 = idx;
            goto inc;
        }
        if ((r = message_portrait_anim_step(set, idx, x, 5, anim, m)) != 1)
            return;
        s->unkE = m;
        s->unk12 = r;
        s->unkF = anim;
        s->unk10 = set;
        s->unk11 = idx;
    }
inc:
    s->unkC += 4;
}

void text_render_glyph_step(void) {
    u8 width;
    u8 shift;
    u8 i;
    u8 ch;

    if (gUnk_03000440.unk18 == 0) {
        u8 done;

        width = 0;
        shift = 0;
        done = 0;
        while (!done) {
            ch = gUnk_03000440.unk8[gUnk_03000440.unkC + shift++];
            if (gUnk_03000440.unk27)
                width += gUnk_083B4E88[ch][0];
            else
                width += gUnk_083B4C88[ch][0];
            ch = gUnk_03000440.unk8[gUnk_03000440.unkC + shift];
            if (ch > 0xF7)
                break;
            if (ch == 0) {
                done = 1;
                if (gUnk_03000440.unk27)
                    width += gUnk_083B4E88[0][0];
                else
                    width += gUnk_083B4C88[0][0];
            }
        }
        gUnk_03000440.unk15 = width;
        if (gUnk_03000440.unk14 + width > 0xD0)
            gUnk_03000440.unk19 = 1;
        else
            gUnk_03000440.unk18 = 1;
    }
    if (gUnk_03000440.unk19 != 0)
        return;

    ch = gUnk_03000440.unk8[gUnk_03000440.unkC];
    if (gUnk_03000440.unk27)
        width = gUnk_083B4E88[ch][0];
    else
        width = gUnk_083B4C88[ch][0];
    gUnk_03000440.unk14 += width;
    gUnk_03000440.unk15 -= width;
    if (gUnk_03000440.unk16 == 0) {
        if (gUnk_03000440.unk27) {
            gUnk_03000440.unk16 = gUnk_083B4E88[ch][0];
            CpuSet(gUnk_084C5188 + ch * 64, gUnk_02020000, 0x20);
        } else {
            gUnk_03000440.unk16 = gUnk_083B4C88[ch][0];
            CpuSet(gUnk_084C01C8 + ch * 64, gUnk_02020000, 0x20);
        }
    } else {
        shift = gUnk_03000440.unk16;
        if (gUnk_03000440.unk27)
            CpuSet(gUnk_084C5188 + ch * 64, gUnk_02020040, 0x20);
        else
            CpuSet(gUnk_084C01C8 + ch * 64, gUnk_02020040, 0x20);
        for (i = 0; i < 16; i++)
            ((u32 *)gUnk_02020000)[i] |= ((u32 *)gUnk_02020040)[i] << (shift * 4);
        gUnk_03000440.unk16 += width;
    }
    if (gUnk_03000440.unk16 > 7) {
        u8 col = (gUnk_03000440.unk14 >> 3) - 1;
        CpuSet(gUnk_02020000, (void *)(col * 0x40 + VRAM + 0x280 + gUnk_03000440.unk17 * 0x680), 0x20);
        gUnk_03000440.unk13 = 1;
        if (gUnk_03000440.unk16 == 8)
            gUnk_03000440.unk16 = 0;
        else {
            gUnk_03000440.unk16 -= 8;
            shift = 8 - shift;
            if (gUnk_03000440.unk27)
                CpuSet(gUnk_084C5188, gUnk_02020000, 0x20);
            else
                CpuSet(gUnk_084C01C8, gUnk_02020000, 0x20);
            for (i = 0; i < 16; i++)
                ((u32 *)gUnk_02020000)[i] |= ((u32 *)gUnk_02020040)[i] >> (shift * 4);
        }
    }
    if (gUnk_03000440.unk15 == 0)
        gUnk_03000440.unk18 = 0;
    gUnk_03000440.unkC++;
}

void sub_080402B4(void) {
    u8 w;
    u8 n;
    u8 i;
    u8 c;
    u8 done;

    if (gUnk_03000440.unk18 == 0) {
        w = 0;
        n = 0;
        done = 0;
        gUnk_03000440.unk24 = n;
        do {
            switch (gUnk_03000440.unk8[gUnk_03000440.unkC + 1]) {
            case 1:
                gUnk_03000440.unk20 = gUnk_03000440.unk9E;
                break;
            case 2:
                gUnk_03000440.unk20 = gUnk_03000440.unk9E + 0x14;
                break;
            case 3:
                gUnk_03000440.unk20 = gUnk_03000440.unk9E + 0x28;
                break;
            case 4:
                gUnk_03000440.unk20 = gUnk_03000440.unk9E + 0x3C;
                break;
            case 0:
            default:
                gUnk_03000440.unk20 = gUnk_03002B74;
                break;
            }
            c = gUnk_03000440.unk20[gUnk_03000440.unk24 + n++];
            if (gUnk_03000440.unk27)
                w += gUnk_083B4E88[c][0];
            else
                w += gUnk_083B4C88[c][0];
            c = gUnk_03000440.unk20[gUnk_03000440.unk24 + n];
            if (c > 0xF7)
                done = 1;
        } while (!done);
        gUnk_03000440.unk15 = w;
        if (gUnk_03000440.unk14 + w > 0xD0)
            gUnk_03000440.unk19 = 1;
        else
            gUnk_03000440.unk18 = 1;
    }
    if (gUnk_03000440.unk19 == 0) {
        c = gUnk_03000440.unk20[gUnk_03000440.unk24];
        if (gUnk_03000440.unk27)
            w = gUnk_083B4E88[c][0];
        else
            w = gUnk_083B4C88[c][0];
        gUnk_03000440.unk14 += w;
        gUnk_03000440.unk15 -= w;
        if (gUnk_03000440.unk16 == 0) {
            if (gUnk_03000440.unk27)
                gUnk_03000440.unk16 = gUnk_083B4E88[c][0];
            else
                gUnk_03000440.unk16 = gUnk_083B4C88[c][0];
            if (gUnk_03000440.unk27)
                CpuSet(&gUnk_084C5188[c * 64], gUnk_02020000, 0x20);
            else
                CpuSet(&gUnk_084C01C8[c * 64], gUnk_02020000, 0x20);
        } else {
            n = gUnk_03000440.unk16;
            if (gUnk_03000440.unk27)
                CpuSet(gUnk_084C5188 + c * 64, gUnk_02020040, 0x20);
            else
                CpuSet(gUnk_084C01C8 + c * 64, gUnk_02020040, 0x20);
            for (i = 0; i <= 15; i++)
                ((u32 *)gUnk_02020000)[i] |= ((u32 *)gUnk_02020040)[i] << (n * 4);
            gUnk_03000440.unk16 += w;
        }
        if (gUnk_03000440.unk16 > 7) {
            i = (gUnk_03000440.unk14 >> 3) - 1;
            CpuSet(gUnk_02020000, (void *)(VRAM + 0x280 + i * 0x40 + gUnk_03000440.unk17 * 0x680), 0x20);
            gUnk_03000440.unk13 = 1;
            if (gUnk_03000440.unk16 == 8) {
                gUnk_03000440.unk16 = 0;
            } else {
                gUnk_03000440.unk16 -= 8;
                n = 8 - n;
                if (gUnk_03000440.unk27)
                    CpuSet(gUnk_084C5188, gUnk_02020000, 0x20);
                else
                    CpuSet(gUnk_084C01C8, gUnk_02020000, 0x20);
                for (i = 0; i <= 15; i++)
                    ((u32 *)gUnk_02020000)[i] |= ((u32 *)gUnk_02020040)[i] >> (n * 4);
            }
        }
        if (gUnk_03000440.unk15 == 0) {
            gUnk_03000440.unk18 = 0;
            gUnk_03000440.unkC += 2;
        }
        gUnk_03000440.unk24++;
    }
}

void reset_text_tile_state(void) {
    if (((struct TextColBits *)&gUnk_03000440)->col) {
        u8 col = (gUnk_03000440.unk14 + 8) / 8 - 1;
        CpuSet(gUnk_02020000, (void *)(col * 0x40 + VRAM + 0x280 + gUnk_03000440.unk17 * 0x680), 0x20);
    }
    gUnk_03000440.unk14 = 0;
    gUnk_03000440.unk16 = 0;
    gUnk_03000440.unk18 = 0;
    gUnk_03000440.unk19 = 0;
    if (gUnk_03000440.unk17 == 1)
        gUnk_03000440.unk19 = 2;
    else
        gUnk_03000440.unk17 = 1;
}

u8 update_text_compose_and_input(void) {
    u8 i;
    u8 blink;

    if (((struct TextColBits *)&gUnk_03000440)->col) {
        u8 col = (gUnk_03000440.unk14 + 8) / 8 - 1;
        CpuSet(gUnk_02020000, (void *)(col * 0x40 + VRAM + 0x280 + gUnk_03000440.unk17 * 0x680), 0x20);
    }
    blink = gUnk_03000440.unk25 & 8;
    if (blink)
        write_tilemap_rect(2, 1, 0xE, 0x12, gUnk_083B4AE0_s.unk124, REG_BG0CNT, 0);
    else
        write_tilemap_rect(2, 1, 0xE, 0x12, gUnk_083B4AE0_s.unk128, REG_BG0CNT, blink);
    gUnk_03000440.unk25++;
    gUnk_03000440.unk13 = 1;
    if (*(u8 *)&gRepeatKeys & 3) {
        play_sound_effect(0xD);
        gUnk_03000440.unk14 = 0;
        gUnk_03000440.unk16 = 0;
        gUnk_03000440.unk18 = 0;
        gUnk_03000440.unk19 = 0;
        gUnk_03000440.unk17 = 0;
        gUnk_03000440.unk25 = 0;
        write_tilemap_rect(2, 1, 0xE, 0x12, gUnk_083B4AE0_s.unk124, REG_BG0CNT, 0);
        for (i = 0; i <= 0x33; i++)
            CpuSet(gUnk_084C01C8, (void *)(0x06000280 + i * 0x40), 0x20);
        gUnk_03000440.unk13 = 0;
        return 1;
    }
    return 0;
}

static void sub_0804070C(void) {
    u16 c;
    if (gUnk_03000440.unk1A == 0) {
        if (((struct TextColBits *)&gUnk_03000440)->col) {
            u8 col = (gUnk_03000440.unk14 + 8) / 8 - 1;
            CpuFastSet(gUnk_02020000, (void *)(col * 0x40 + VRAM + 0x280 + gUnk_03000440.unk17 * 0x680), 16);
        }
        c = gUnk_03000440.unkC;
        gUnk_03000440.unk1A = gUnk_03000440.unk8[*(vu16 *)&gUnk_03000440.unkC + 1];
        if (*(vu8 *)&gUnk_03000440.unk1A == 0xFF)
            gUnk_03000440.unkC = c + 2;
    } else if (gUnk_03000440.unk1A == 0xFF || --gUnk_03000440.unk1A == 0)
        gUnk_03000440.unkC += 2;
    else if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 3)) {
        gUnk_03000440.unk1A = 0;
        gUnk_03000440.unkC += 2;
    }
}

static void sub_080407A4(void) {
    u16 c;
    if (gUnk_03000440.unk1A == 0) {
        if (((struct TextColBits *)&gUnk_03000440)->col) {
            u8 col = (gUnk_03000440.unk14 + 8) / 8 - 1;
            CpuFastSet(gUnk_02020000, (void *)(col * 0x40 + VRAM + 0x280 + gUnk_03000440.unk17 * 0x680), 16);
        }
        c = gUnk_03000440.unkC;
        gUnk_03000440.unk1A = gUnk_03000440.unk8[*(vu16 *)&gUnk_03000440.unkC + 1];
        if (*(vu8 *)&gUnk_03000440.unk1A == 0xFF)
            gUnk_03000440.unkC = c + 2;
    } else if (gUnk_03000440.unk1A == 0xFF || --gUnk_03000440.unk1A == 0)
        gUnk_03000440.unkC += 2;
}

static void sub_08040820(void) {
    if (((struct TextColBits *)&gUnk_03000440)->col) {
        u8 col = (gUnk_03000440.unk14 + 8) / 8 - 1;
        CpuFastSet(gUnk_02020000, (void *)(col * 0x40 + VRAM + 0x280 + gUnk_03000440.unk17 * 0x680), 16);
    }
    gUnk_03000440.unk14 = 0;
    switch (gUnk_03000440.unk8[gUnk_03000440.unkC + 1]) {
    case 0:
    case 2:
    case 3:
        if (*(u8 *)&gRepeatKeys & 3) {
            play_sound_effect(0xD);
            gUnk_03000440.unk4++;
        }
        break;
    case 1:
    case 4:
        gUnk_03000440.unk4++;
        break;
    default:
        gUnk_03000440.unk4++;
        break;
    }
}

// run_message state 6: run message command gUnk_083B27C0[unk8[unkC + 1]] (each steps through its own table by unk1B).
void message_run_command(void) {
    gUnk_083B27C0[gUnk_03000440.unk8[gUnk_03000440.unkC + 1]]();
}

void sub_080408F4(void) {
    gUnk_083B27D4[gUnk_03000440.unk1B]();
}

void sub_08040914(void) {
    gUnk_083B27EC[gUnk_03000440.unk1B]();
}

void sub_08040934(void) {
    gUnk_083B2804[gUnk_03000440.unk1B]();
}

void sub_08040954(void) {
    gUnk_083B2808[gUnk_03000440.unk1B]();
}

void sub_08040974(void) {
    gUnk_083B2810[gUnk_03000440.unk1B]();
}

void sub_08040994(void) {
    struct Unk_03000440 *p = &gUnk_03000440;
    u8 x;
    u8 m;
    u32 r;

    if ((m = p->unk1) != 2 && (r = p->unk12) == 1) {
        x = p->unkF == 0 ? 0x13 : 3;
        if (m == 0) {
            if ((u8)message_portrait_anim_step((u8)p->unk10, (u8)p->unk11, x, 5, p->unkF, r) != 1)
                return;
        } else
            vram_fill_tilemap_rect(8, 8, x, 5, REG_BG0CNT, m = 0);
        p->unkE = m;
        p->unk12 = m;
    }
    p->unk1B++;
}

void sub_08040A00(void) {
    if (gUnk_03000440.unk2 == 1) {
        vram_fill_tilemap_rect(0x1E, 6, 0, 0xD, REG_BG0CNT, 0);
        gUnk_03000440.unk1B += 2;
    } else
        gUnk_03000440.unk1B++;
}

void sub_08040A40(void) {
    switch (gUnk_03000440.unk26) {
    case 3:
        lz_decompress_dispatch(gUnk_08487524, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gUnk_084885A8, REG_BG0CNT, 1);
        gUnk_03000440.unk26--;
        break;
    case 2:
        lz_decompress_dispatch(gUnk_08487630, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gUnk_08488600, REG_BG0CNT, 1);
        gUnk_03000440.unk26--;
        break;
    case 1:
        vram_fill_tilemap_rect(0x1E, 6, 0, 0xD, REG_BG0CNT, 0);
        gUnk_03000440.unk26--;
        break;
    default:
        gUnk_03000440.unk1B++;
        break;
    }
}

void sub_08040AF0(void) {
    if (gUnk_03000440.unk0 == 0)
        gUnk_03000440.unk1B += 1;
    else
        gUnk_03000440.unk1B += 2;
}

// Message close step: undo message_dim_palettes_step one frame at a time (unk1C down to 0).
void message_undim_palettes_step(void) {
    bg_palettes_blend_masked_now(0x1B2, gUnk_03000440.unk1C * 2, 0x1FFF);
    obj_palettes_blend_masked_now(0x1B2, gUnk_03000440.unk1C * 2, 0x1FFF);
    if (gUnk_03000440.unk1C == 0)
        gUnk_03000440.unk1B++;
    else
        gUnk_03000440.unk1C--;
}

// Last message close step: run_message state 8 (done, run_message returns 1).
void message_close(void) {
    gUnk_03000440.unk4 = 8;
}
