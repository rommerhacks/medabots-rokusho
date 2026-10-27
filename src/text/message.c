// Message window: text_window_init sets it up, run_message steps the window state machine
// gMessageStates by gGameWork.unk4 (open, dim palettes, show the frame, clear, print with
// message_print_step, then the end mode from gMessageEndModes, close). Message text is font characters
// plus control codes: 0xF7 n wait n frames, 0xF8 toggle the alternate font, 0xF9 n print string variable
// n, 0xFA n wait n frames (A / B skips), 0xFB anim set idx portrait, 0xFC wait for A / B and clear the
// page, 0xFD new line, 0xFE ignored, 0xFF mode end of message (end modes 0-4). Draws through engine/tilemap and
// engine/palette_blend; used by every scene with text.

#include "global.h"

static void message_cmd_skip(void);
static void message_cmd_portrait(void);
static void message_cmd_wait_skippable(void);
static void message_cmd_wait(void);
static void message_cmd_end(void);

void text_window_init(u8 a, u8 b, u32 c) {
    u8 c8 = c;

    mem_fill8((u8 *)&gGameWork, 0x28, 0);
    gGameWork.unk0 = a;
    gGameWork.unk1 = b;
    gGameWork.unk2 = c8;
    gGameWork.unkF = 0xFF;
    gGameWork.unk10 = -1;
    gGameWork.unk11 = -1;
    decompress_bg_tiles_to_vram_bg();
    CpuFastSet(gTextWindowObjPalette, (void *)(OBJ_PLTT - 0x40), 8);
    if (c8 == 1)
        setup_bg0_display_layer();
}

// Start the next message in an already open window (state 4 clears the text area first).
void message_next(void) {
    gGameWork.unk4 = 4;
    gGameWork.unkC = 0;
    gGameWork.unk14 = 0;
    gGameWork.unk15 = 0;
    gGameWork.unk16 = 0;
    gGameWork.unk17 = 0;
    gGameWork.unk18 = 0;
    gGameWork.unk19 = 0;
    gGameWork.unk1A = 0;
    gGameWork.unk1B = 0;
    gGameWork.unk24 = 0;
    gGameWork.unk25 = 0;
    gGameWork.unk27 = 0;
}

u32 run_message(const void *msg) {
    gGameWork.unk8 = msg;
    gMessageStates[gGameWork.unk4]();
    if (gGameWork.unk4 > 7)
        return 1;
    return 0;
}

// run_message state 0: back up the palettes, then dim them (state 1); unk0 != 0 skips to state 2.
void message_open(void) {
    u8 v = gGameWork.unk0;
    if (v == 0) {
        palette_backup_from_hardware();
        gGameWork.unk1C = v;
        gGameWork.unk4++;
    } else {
        gGameWork.unk4 = 2;
    }
}

// run_message state 1: blend all palettes toward 0x01B2 by unk1C * 2 / 32, 10 frames.
void message_dim_palettes_step(void) {
    bg_palettes_blend_masked_now(0x1B2, gGameWork.unk1C * 2, 0x1FFF);
    obj_palettes_blend_masked_now(0x1B2, gGameWork.unk1C * 2, 0x3FFF);
    if (gGameWork.unk1C > 8)
        gGameWork.unk4++;
    else
        gGameWork.unk1C++;
}

// run_message state 2: unk2 == 1 jumps to state 4; else show BG0 (the window) at BG0CNT 0x500.
void message_show_window(void) {
    if (gGameWork.unk2 == 1) {
        gGameWork.unk4 = 4;
    } else {
        gGameWork.unk4++;
        gGameWork.unk26 = 0;
        REG_DISPCNT |= 0x100;
        REG_BG0CNT = 0x500;
    }
}

// run_message state 3: draws the window frame in three frames (unk26 0-2, reverse of message_close_window_frame), then
// state 4.
void message_open_window_frame(void) {
    switch (gGameWork.unk26) {
    case 0:
        lz_decompress_dispatch(gUnk_08487630, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gUnk_08488600, REG_BG0CNT, 1);
        gGameWork.unk26++;
        break;
    case 1:
        lz_decompress_dispatch(gUnk_08487524, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gUnk_084885A8, REG_BG0CNT, 1);
        gGameWork.unk26++;
        break;
    case 2:
        lz_decompress_dispatch(gUnk_084873D0, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gUnk_08488540, REG_BG0CNT, 1);
        gGameWork.unk26++;
        break;
    default:
        gGameWork.unk4++;
        break;
    }
}

void message_clear_text_area(void) {
    u32 i;
    u8 *dst;

    for (i = 0, dst = (u8 *)0x06000280; i <= 0x33; i++) {
        CpuFastSet(gFontGlyphs, dst, 0x10);
        dst += 0x40;
    }
    write_tilemap_rect(0x1A, 4, 2, 0xE, gUnk_083B4AE0[18], REG_BG0CNT, 0);
    gGameWork.unk4++;
    message_print_step();
}

void message_print_step(void) {
    gGameWork.unk13 = 0;
    do {
        switch (gGameWork.unk8[gGameWork.unkC]) {
        case 0xF9:
            if (gGameWork.unk19 == 1) {
                gGameWork.unk13 = 0;
                message_new_line();
            } else if (gGameWork.unk19 == 2) {
                gGameWork.unk13 = 1;
                message_wait_next_page();
            } else {
                gGameWork.unk13 = 0;
                message_print_var_step();
                if (gGameWork.unk1A == 0xFF)
                    gGameWork.unk13 = 0;
            }
            break;
        case 0xFA:
            message_cmd_wait_skippable();
            if (gGameWork.unk1A == 0xFF)
                gGameWork.unk13 = 0;
            else
                gGameWork.unk13 = 1;
            break;
        case 0xF7:
            message_cmd_wait();
            if (gGameWork.unk1A == 0xFF)
                gGameWork.unk13 = 0;
            else
                gGameWork.unk13 = 1;
            break;
        case 0xFB:
            message_cmd_portrait();
            gGameWork.unk13 = 1;
            break;
        case 0xFC:
            if (message_wait_next_page() == 1)
                gGameWork.unkC++;
            break;
        case 0xFD:
            if (gGameWork.unk19 == 2) {
                gGameWork.unk13 = 1;
                if (message_wait_next_page() == 1)
                    gGameWork.unkC++;
            } else {
                gGameWork.unk13 = 0;
                message_new_line();
                if (gGameWork.unk19 == 0)
                    gGameWork.unkC++;
            }
            break;
        case 0xFE:
            message_cmd_skip();
            break;
        case 0xF8:
            gGameWork.unk27 ^= 1;
            gGameWork.unkC++;
            break;
        case 0xFF:
            message_cmd_end();
            gGameWork.unk13 = 1;
            break;
        default:
            if (gGameWork.unk19 == 1) {
                gGameWork.unk13 = 0;
                message_new_line();
            } else if (gGameWork.unk19 == 2) {
                gGameWork.unk13 = 1;
                message_wait_next_page();
            } else {
                gGameWork.unk13 = 0;
                text_render_glyph_step();
                if (gGameWork.unk1A == 0xFF)
                    gGameWork.unk13 = 0;
            }
            break;
        }
    } while (gGameWork.unk13 == 0);
}

// 0xFE: ignored.
static void message_cmd_skip(void) {
    gGameWork.unkC++;
}

// 0xFB anim set idx: show / change the speaker portrait (set 0xFF = none); waits for its animation.
static void message_cmd_portrait(void) {
    u32 anim, set, idx;
    u32 x;
    u8 zero;
    u8 m;
    u8 r;
    struct GameWork *s;
    u8 n;
    if (((struct TextColBits *)&gGameWork)->col) {
        u8 col = (gGameWork.unk14 + 8) / 8 - 1;
        CpuFastSet(gTextComposeTile, (void *)(col * 0x40 + VRAM + 0x280 + gGameWork.unk17 * 0x680), 16);
    }
    s = &gGameWork;
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
                gGameWork.unkF = anim;
                gGameWork.unk10 = set;
                gGameWork.unk11 = idx;
                gGameWork.unkC += 4;
            } else {
                struct GameWork *p = &gGameWork;
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

    if (gGameWork.unk18 == 0) {
        u8 done;

        width = 0;
        shift = 0;
        done = 0;
        while (!done) {
            ch = gGameWork.unk8[gGameWork.unkC + shift++];
            if (gGameWork.unk27)
                width += gAltFontWidths[ch][0];
            else
                width += gFontWidths[ch][0];
            ch = gGameWork.unk8[gGameWork.unkC + shift];
            if (ch > 0xF7)
                break;
            if (ch == 0) {
                done = 1;
                if (gGameWork.unk27)
                    width += gAltFontWidths[0][0];
                else
                    width += gFontWidths[0][0];
            }
        }
        gGameWork.unk15 = width;
        if (gGameWork.unk14 + width > 0xD0)
            gGameWork.unk19 = 1;
        else
            gGameWork.unk18 = 1;
    }
    if (gGameWork.unk19 != 0)
        return;

    ch = gGameWork.unk8[gGameWork.unkC];
    if (gGameWork.unk27)
        width = gAltFontWidths[ch][0];
    else
        width = gFontWidths[ch][0];
    gGameWork.unk14 += width;
    gGameWork.unk15 -= width;
    if (gGameWork.unk16 == 0) {
        if (gGameWork.unk27) {
            gGameWork.unk16 = gAltFontWidths[ch][0];
            CpuSet(gAltFontGlyphs + ch * 64, gTextComposeTile, 0x20);
        } else {
            gGameWork.unk16 = gFontWidths[ch][0];
            CpuSet(gFontGlyphs + ch * 64, gTextComposeTile, 0x20);
        }
    } else {
        shift = gGameWork.unk16;
        if (gGameWork.unk27)
            CpuSet(gAltFontGlyphs + ch * 64, gTextGlyphTile, 0x20);
        else
            CpuSet(gFontGlyphs + ch * 64, gTextGlyphTile, 0x20);
        for (i = 0; i < 16; i++)
            ((u32 *)gTextComposeTile)[i] |= ((u32 *)gTextGlyphTile)[i] << (shift * 4);
        gGameWork.unk16 += width;
    }
    if (gGameWork.unk16 > 7) {
        u8 col = (gGameWork.unk14 >> 3) - 1;
        CpuSet(gTextComposeTile, (void *)(col * 0x40 + VRAM + 0x280 + gGameWork.unk17 * 0x680), 0x20);
        gGameWork.unk13 = 1;
        if (gGameWork.unk16 == 8)
            gGameWork.unk16 = 0;
        else {
            gGameWork.unk16 -= 8;
            shift = 8 - shift;
            if (gGameWork.unk27)
                CpuSet(gAltFontGlyphs, gTextComposeTile, 0x20);
            else
                CpuSet(gFontGlyphs, gTextComposeTile, 0x20);
            for (i = 0; i < 16; i++)
                ((u32 *)gTextComposeTile)[i] |= ((u32 *)gTextGlyphTile)[i] >> (shift * 4);
        }
    }
    if (gGameWork.unk15 == 0)
        gGameWork.unk18 = 0;
    gGameWork.unkC++;
}

// 0xF9 n: print string variable n (0 = gUnk_03002B74, 1-4 = 20-byte buffers from unk9E), one glyph a call.
void message_print_var_step(void) {
    u8 w;
    u8 n;
    u8 i;
    u8 c;
    u8 done;

    if (gGameWork.unk18 == 0) {
        w = 0;
        n = 0;
        done = 0;
        gGameWork.unk24 = n;
        do {
            switch (gGameWork.unk8[gGameWork.unkC + 1]) {
            case 1:
                gGameWork.unk20 = gGameWork.unk9E;
                break;
            case 2:
                gGameWork.unk20 = gGameWork.unk9E + 0x14;
                break;
            case 3:
                gGameWork.unk20 = gGameWork.unk9E + 0x28;
                break;
            case 4:
                gGameWork.unk20 = gGameWork.unk9E + 0x3C;
                break;
            case 0:
            default:
                gGameWork.unk20 = gUnk_03002B74;
                break;
            }
            c = gGameWork.unk20[gGameWork.unk24 + n++];
            if (gGameWork.unk27)
                w += gAltFontWidths[c][0];
            else
                w += gFontWidths[c][0];
            c = gGameWork.unk20[gGameWork.unk24 + n];
            if (c > 0xF7)
                done = 1;
        } while (!done);
        gGameWork.unk15 = w;
        if (gGameWork.unk14 + w > 0xD0)
            gGameWork.unk19 = 1;
        else
            gGameWork.unk18 = 1;
    }
    if (gGameWork.unk19 == 0) {
        c = gGameWork.unk20[gGameWork.unk24];
        if (gGameWork.unk27)
            w = gAltFontWidths[c][0];
        else
            w = gFontWidths[c][0];
        gGameWork.unk14 += w;
        gGameWork.unk15 -= w;
        if (gGameWork.unk16 == 0) {
            if (gGameWork.unk27)
                gGameWork.unk16 = gAltFontWidths[c][0];
            else
                gGameWork.unk16 = gFontWidths[c][0];
            if (gGameWork.unk27)
                CpuSet(&gAltFontGlyphs[c * 64], gTextComposeTile, 0x20);
            else
                CpuSet(&gFontGlyphs[c * 64], gTextComposeTile, 0x20);
        } else {
            n = gGameWork.unk16;
            if (gGameWork.unk27)
                CpuSet(gAltFontGlyphs + c * 64, gTextGlyphTile, 0x20);
            else
                CpuSet(gFontGlyphs + c * 64, gTextGlyphTile, 0x20);
            for (i = 0; i <= 15; i++)
                ((u32 *)gTextComposeTile)[i] |= ((u32 *)gTextGlyphTile)[i] << (n * 4);
            gGameWork.unk16 += w;
        }
        if (gGameWork.unk16 > 7) {
            i = (gGameWork.unk14 >> 3) - 1;
            CpuSet(gTextComposeTile, (void *)(VRAM + 0x280 + i * 0x40 + gGameWork.unk17 * 0x680), 0x20);
            gGameWork.unk13 = 1;
            if (gGameWork.unk16 == 8) {
                gGameWork.unk16 = 0;
            } else {
                gGameWork.unk16 -= 8;
                n = 8 - n;
                if (gGameWork.unk27)
                    CpuSet(gAltFontGlyphs, gTextComposeTile, 0x20);
                else
                    CpuSet(gFontGlyphs, gTextComposeTile, 0x20);
                for (i = 0; i <= 15; i++)
                    ((u32 *)gTextComposeTile)[i] |= ((u32 *)gTextGlyphTile)[i] >> (n * 4);
            }
        }
        if (gGameWork.unk15 == 0) {
            gGameWork.unk18 = 0;
            gGameWork.unkC += 2;
        }
        gGameWork.unk24++;
    }
}

void message_new_line(void) {
    if (((struct TextColBits *)&gGameWork)->col) {
        u8 col = (gGameWork.unk14 + 8) / 8 - 1;
        CpuSet(gTextComposeTile, (void *)(col * 0x40 + VRAM + 0x280 + gGameWork.unk17 * 0x680), 0x20);
    }
    gGameWork.unk14 = 0;
    gGameWork.unk16 = 0;
    gGameWork.unk18 = 0;
    gGameWork.unk19 = 0;
    if (gGameWork.unk17 == 1)
        gGameWork.unk19 = 2;
    else
        gGameWork.unk17 = 1;
}

u8 message_wait_next_page(void) {
    u8 i;
    u8 blink;

    if (((struct TextColBits *)&gGameWork)->col) {
        u8 col = (gGameWork.unk14 + 8) / 8 - 1;
        CpuSet(gTextComposeTile, (void *)(col * 0x40 + VRAM + 0x280 + gGameWork.unk17 * 0x680), 0x20);
    }
    blink = gGameWork.unk25 & 8;
    if (blink)
        write_tilemap_rect(2, 1, 0xE, 0x12, gUnk_083B4AE0_s.unk124, REG_BG0CNT, 0);
    else
        write_tilemap_rect(2, 1, 0xE, 0x12, gUnk_083B4AE0_s.unk128, REG_BG0CNT, blink);
    gGameWork.unk25++;
    gGameWork.unk13 = 1;
    if (*(u8 *)&gRepeatKeys & 3) {
        play_sound_effect(0xD);
        gGameWork.unk14 = 0;
        gGameWork.unk16 = 0;
        gGameWork.unk18 = 0;
        gGameWork.unk19 = 0;
        gGameWork.unk17 = 0;
        gGameWork.unk25 = 0;
        write_tilemap_rect(2, 1, 0xE, 0x12, gUnk_083B4AE0_s.unk124, REG_BG0CNT, 0);
        for (i = 0; i <= 0x33; i++)
            CpuSet(gFontGlyphs, (void *)(0x06000280 + i * 0x40), 0x20);
        gGameWork.unk13 = 0;
        return 1;
    }
    return 0;
}

// 0xFA n: wait n frames (0xFF = forever); A or B ends the wait early unless unk89 (demo) is set.
static void message_cmd_wait_skippable(void) {
    u16 c;
    if (gGameWork.unk1A == 0) {
        if (((struct TextColBits *)&gGameWork)->col) {
            u8 col = (gGameWork.unk14 + 8) / 8 - 1;
            CpuFastSet(gTextComposeTile, (void *)(col * 0x40 + VRAM + 0x280 + gGameWork.unk17 * 0x680), 16);
        }
        c = gGameWork.unkC;
        gGameWork.unk1A = gGameWork.unk8[*(vu16 *)&gGameWork.unkC + 1];
        if (*(vu8 *)&gGameWork.unk1A == 0xFF)
            gGameWork.unkC = c + 2;
    } else if (gGameWork.unk1A == 0xFF || --gGameWork.unk1A == 0)
        gGameWork.unkC += 2;
    else if (gGameWork.unk89 == 0 && (*(u8 *)&gRepeatKeys & 3)) {
        gGameWork.unk1A = 0;
        gGameWork.unkC += 2;
    }
}

// 0xF7 n: wait n frames (0xFF = forever).
static void message_cmd_wait(void) {
    u16 c;
    if (gGameWork.unk1A == 0) {
        if (((struct TextColBits *)&gGameWork)->col) {
            u8 col = (gGameWork.unk14 + 8) / 8 - 1;
            CpuFastSet(gTextComposeTile, (void *)(col * 0x40 + VRAM + 0x280 + gGameWork.unk17 * 0x680), 16);
        }
        c = gGameWork.unkC;
        gGameWork.unk1A = gGameWork.unk8[*(vu16 *)&gGameWork.unkC + 1];
        if (*(vu8 *)&gGameWork.unk1A == 0xFF)
            gGameWork.unkC = c + 2;
    } else if (gGameWork.unk1A == 0xFF || --gGameWork.unk1A == 0)
        gGameWork.unkC += 2;
}

// 0xFF mode: end of message. Modes 0, 2, 3 wait for A / B; then run_message state 6 runs the end mode.
static void message_cmd_end(void) {
    if (((struct TextColBits *)&gGameWork)->col) {
        u8 col = (gGameWork.unk14 + 8) / 8 - 1;
        CpuFastSet(gTextComposeTile, (void *)(col * 0x40 + VRAM + 0x280 + gGameWork.unk17 * 0x680), 16);
    }
    gGameWork.unk14 = 0;
    switch (gGameWork.unk8[gGameWork.unkC + 1]) {
    case 0:
    case 2:
    case 3:
        if (*(u8 *)&gRepeatKeys & 3) {
            play_sound_effect(0xD);
            gGameWork.unk4++;
        }
        break;
    case 1:
    case 4:
        gGameWork.unk4++;
        break;
    default:
        gGameWork.unk4++;
        break;
    }
}

// run_message state 6: run end mode gMessageEndModes[unk8[unkC + 1]] (each steps through its own table by unk1B).
void message_run_command(void) {
    gMessageEndModes[gGameWork.unk8[gGameWork.unkC + 1]]();
}

void message_end_wait_close(void) {
    gMessageEndWaitCloseSteps[gGameWork.unk1B]();
}

void message_end_close(void) {
    gMessageEndCloseSteps[gGameWork.unk1B]();
}

void message_end_wait_keep(void) {
    gMessageEndWaitKeepSteps[gGameWork.unk1B]();
}

void message_end_wait_clear(void) {
    gMessageEndWaitClearSteps[gGameWork.unk1B]();
}

void message_end_keep(void) {
    gMessageEndKeepSteps[gGameWork.unk1B]();
}

// End step 0: clear the speaker portrait.
void message_close_portrait(void) {
    struct GameWork *p = &gGameWork;
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

// End step 1: a frameless window (unk2 == 1) is just cleared, skipping the frame animation.
void message_close_check_frame(void) {
    if (gGameWork.unk2 == 1) {
        vram_fill_tilemap_rect(0x1E, 6, 0, 0xD, REG_BG0CNT, 0);
        gGameWork.unk1B += 2;
    } else
        gGameWork.unk1B++;
}

// End step 2: closes the window frame in three frames (reverse of message_open_window_frame).
void message_close_window_frame(void) {
    switch (gGameWork.unk26) {
    case 3:
        lz_decompress_dispatch(gUnk_08487524, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gUnk_084885A8, REG_BG0CNT, 1);
        gGameWork.unk26--;
        break;
    case 2:
        lz_decompress_dispatch(gUnk_08487630, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gUnk_08488600, REG_BG0CNT, 1);
        gGameWork.unk26--;
        break;
    case 1:
        vram_fill_tilemap_rect(0x1E, 6, 0, 0xD, REG_BG0CNT, 0);
        gGameWork.unk26--;
        break;
    default:
        gGameWork.unk1B++;
        break;
    }
}

// End step 3: undim the palettes only if message_open dimmed them (unk0 == 0).
void message_close_check_dim(void) {
    if (gGameWork.unk0 == 0)
        gGameWork.unk1B += 1;
    else
        gGameWork.unk1B += 2;
}

// Message close step: undo message_dim_palettes_step one frame at a time (unk1C down to 0).
void message_undim_palettes_step(void) {
    bg_palettes_blend_masked_now(0x1B2, gGameWork.unk1C * 2, 0x1FFF);
    obj_palettes_blend_masked_now(0x1B2, gGameWork.unk1C * 2, 0x1FFF);
    if (gGameWork.unk1C == 0)
        gGameWork.unk1B++;
    else
        gGameWork.unk1C--;
}

// Last message close step: run_message state 8 (done, run_message returns 1).
void message_close(void) {
    gGameWork.unk4 = 8;
}
