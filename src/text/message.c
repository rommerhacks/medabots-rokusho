// Message window: text_window_init sets it up, run_message steps the window state machine
// gMessageStates by gGameWork.msgState (open, dim palettes, show the frame, clear, print with
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

void text_window_init(u8 keep_palettes, u8 portrait_mode, u32 no_frame) {
    u8 no_frame_u8 = no_frame;

    mem_fill8((u8 *)&gGameWork, 0x28, 0);
    gGameWork.msgKeepPalettes = keep_palettes;
    gGameWork.portraitMode = portrait_mode;
    gGameWork.noWindowFrame = no_frame_u8;
    gGameWork.portraitSide = 0xFF;
    gGameWork.portraitSet = -1;
    gGameWork.portraitIndex = -1;
    decompress_bg_tiles_to_vram_bg();
    CpuFastSet(gTextWindowObjPalette, (void *)(OBJ_PLTT - 0x40), 8);
    if (no_frame_u8 == 1)
        setup_bg0_display_layer();
}

// Start the next message in an already open window (state 4 clears the text area first).
void message_next(void) {
    gGameWork.msgState = 4;
    gGameWork.msgPos = 0;
    gGameWork.penX = 0;
    gGameWork.wordPixelsLeft = 0;
    gGameWork.composePixels = 0;
    gGameWork.textLine = 0;
    gGameWork.wordFits = 0;
    gGameWork.lineFull = 0;
    gGameWork.msgWait = 0;
    gGameWork.endModeStep = 0;
    gGameWork.varPos = 0;
    gGameWork.cursorBlink = 0;
    gGameWork.altFont = 0;
}

u32 run_message(const void *msg) {
    gGameWork.msgText = msg;
    gMessageStates[gGameWork.msgState]();
    if (gGameWork.msgState > 7)
        return 1;
    return 0;
}

// run_message state 0: back up the palettes, then dim them (state 1); msgKeepPalettes != 0 skips to state 2.
void message_open(void) {
    u8 keep_palettes = gGameWork.msgKeepPalettes;
    if (keep_palettes == 0) {
        palette_backup_from_hardware();
        gGameWork.dimLevel = keep_palettes;
        gGameWork.msgState++;
    } else {
        gGameWork.msgState = 2;
    }
}

// run_message state 1: blend all palettes toward 0x01B2 by dimLevel * 2 / 32, 10 frames.
void message_dim_palettes_step(void) {
    bg_palettes_blend_masked_now(0x1B2, gGameWork.dimLevel * 2, 0x1FFF);
    obj_palettes_blend_masked_now(0x1B2, gGameWork.dimLevel * 2, 0x3FFF);
    if (gGameWork.dimLevel > 8)
        gGameWork.msgState++;
    else
        gGameWork.dimLevel++;
}

// run_message state 2: noWindowFrame == 1 jumps to state 4; else show BG0 (the window) at BG0CNT 0x500.
void message_show_window(void) {
    if (gGameWork.noWindowFrame == 1) {
        gGameWork.msgState = 4;
    } else {
        gGameWork.msgState++;
        gGameWork.frameAnimStep = 0;
        REG_DISPCNT |= 0x100;
        REG_BG0CNT = 0x500;
    }
}

// run_message state 3: draws the window frame in three frames (frameAnimStep 0-2, reverse of
// message_close_window_frame), then state 4.
void message_open_window_frame(void) {
    switch (gGameWork.frameAnimStep) {
    case 0:
        lz_decompress_dispatch(gMessageWindowOpenTiles1, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gMessageWindowOpenTilemap1, REG_BG0CNT, 1);
        gGameWork.frameAnimStep++;
        break;
    case 1:
        lz_decompress_dispatch(gMessageWindowOpenTiles2, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gMessageWindowOpenTilemap2, REG_BG0CNT, 1);
        gGameWork.frameAnimStep++;
        break;
    case 2:
        lz_decompress_dispatch(gMessageWindowTiles, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gMessageWindowTilemap, REG_BG0CNT, 1);
        gGameWork.frameAnimStep++;
        break;
    default:
        gGameWork.msgState++;
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
    write_tilemap_rect(0x1A, 4, 2, 0xE, gUiTilemaps[18], REG_BG0CNT, 0);
    gGameWork.msgState++;
    message_print_step();
}

void message_print_step(void) {
    gGameWork.msgStopPrint = 0;
    do {
        switch (gGameWork.msgText[gGameWork.msgPos]) {
        case 0xF9:
            if (gGameWork.lineFull == 1) {
                gGameWork.msgStopPrint = 0;
                message_new_line();
            } else if (gGameWork.lineFull == 2) {
                gGameWork.msgStopPrint = 1;
                message_wait_next_page();
            } else {
                gGameWork.msgStopPrint = 0;
                message_print_var_step();
                if (gGameWork.msgWait == 0xFF)
                    gGameWork.msgStopPrint = 0;
            }
            break;
        case 0xFA:
            message_cmd_wait_skippable();
            if (gGameWork.msgWait == 0xFF)
                gGameWork.msgStopPrint = 0;
            else
                gGameWork.msgStopPrint = 1;
            break;
        case 0xF7:
            message_cmd_wait();
            if (gGameWork.msgWait == 0xFF)
                gGameWork.msgStopPrint = 0;
            else
                gGameWork.msgStopPrint = 1;
            break;
        case 0xFB:
            message_cmd_portrait();
            gGameWork.msgStopPrint = 1;
            break;
        case 0xFC:
            if (message_wait_next_page() == 1)
                gGameWork.msgPos++;
            break;
        case 0xFD:
            if (gGameWork.lineFull == 2) {
                gGameWork.msgStopPrint = 1;
                if (message_wait_next_page() == 1)
                    gGameWork.msgPos++;
            } else {
                gGameWork.msgStopPrint = 0;
                message_new_line();
                if (gGameWork.lineFull == 0)
                    gGameWork.msgPos++;
            }
            break;
        case 0xFE:
            message_cmd_skip();
            break;
        case 0xF8:
            gGameWork.altFont ^= 1;
            gGameWork.msgPos++;
            break;
        case 0xFF:
            message_cmd_end();
            gGameWork.msgStopPrint = 1;
            break;
        default:
            if (gGameWork.lineFull == 1) {
                gGameWork.msgStopPrint = 0;
                message_new_line();
            } else if (gGameWork.lineFull == 2) {
                gGameWork.msgStopPrint = 1;
                message_wait_next_page();
            } else {
                gGameWork.msgStopPrint = 0;
                text_render_glyph_step();
                if (gGameWork.msgWait == 0xFF)
                    gGameWork.msgStopPrint = 0;
            }
            break;
        }
    } while (gGameWork.msgStopPrint == 0);
}

// 0xFE: ignored.
static void message_cmd_skip(void) {
    gGameWork.msgPos++;
}

// 0xFB anim set idx: show / change the speaker portrait (set 0xFF = none); waits for its animation.
static void message_cmd_portrait(void) {
    u32 anim, set, idx;
    u32 x;
    u8 zero;
    u8 mode;
    u8 anim_result;
    struct GameWork *work;
    u8 n;
    if (((struct TextColBits *)&gGameWork)->col) {
        u8 col = (gGameWork.penX + 8) / 8 - 1;
        CpuFastSet(gTextComposeTile, (void *)(col * 0x40 + VRAM + 0x280 + gGameWork.textLine * 0x680), 16);
    }
    work = &gGameWork;
    zero = 0;
    work->penX = zero;
    if (work->portraitMode != 2) {
        anim = work->msgText[work->msgPos + 1];
        set = (u8)resolve_area_sprite_set(work->msgText[work->msgPos + 2]);
        idx = work->msgText[work->msgPos + 3];
        if (work->portraitShown == 1) {
            if (work->portraitSide == 0)
                x = 0x13;
            else
                x = 3;
            if ((u8)work->portraitSide == (u8)anim && (u8)work->portraitSet == set) {
                if (set == 0xFF)
                    vram_fill_tilemap_rect(8, 8, x, 5, REG_BG0CNT, zero);
                else
                    load_bg0_tilemap(set, idx, x, 5, anim);
                gGameWork.portraitSide = anim;
                gGameWork.portraitSet = set;
                gGameWork.portraitIndex = idx;
                gGameWork.msgPos += 4;
            } else {
                struct GameWork *game = &gGameWork;
                if ((n = game->portraitMode) == 0) {
                    if ((u8)message_portrait_anim_step((u8)game->portraitSet, (u8)game->portraitIndex, x, 5,
                                                       game->portraitSide, 1) != 1)
                        return;
                } else
                    vram_fill_tilemap_rect(8, 8, x, 5, REG_BG0CNT, n = 0);
                game->portraitAnimFrame = n;
                game->portraitShown = n;
            }
            return;
        }
        x = 3;
        if (anim == 0)
            x = 0x13;
        if (set == 0xFF) {
            work->portraitSide = anim;
            work->portraitSet = set;
            work->portraitIndex = idx;
            goto inc;
        }
        if ((mode = work->portraitMode) != 0) {
            load_bg0_tilemap(set, idx, x, 5, anim);
            work->portraitShown = 1;
            work->portraitSide = anim;
            work->portraitSet = set;
            work->portraitIndex = idx;
            goto inc;
        }
        if ((anim_result = message_portrait_anim_step(set, idx, x, 5, anim, mode)) != 1)
            return;
        work->portraitAnimFrame = mode;
        work->portraitShown = anim_result;
        work->portraitSide = anim;
        work->portraitSet = set;
        work->portraitIndex = idx;
    }
inc:
    work->msgPos += 4;
}

void text_render_glyph_step(void) {
    u8 width;
    u8 shift;
    u8 i;
    u8 ch;

    if (gGameWork.wordFits == 0) {
        u8 done;

        width = 0;
        shift = 0;
        done = 0;
        while (!done) {
            ch = gGameWork.msgText[gGameWork.msgPos + shift++];
            if (gGameWork.altFont)
                width += gAltFontWidths[ch][0];
            else
                width += gFontWidths[ch][0];
            ch = gGameWork.msgText[gGameWork.msgPos + shift];
            if (ch > 0xF7)
                break;
            if (ch == 0) {
                done = 1;
                if (gGameWork.altFont)
                    width += gAltFontWidths[0][0];
                else
                    width += gFontWidths[0][0];
            }
        }
        gGameWork.wordPixelsLeft = width;
        if (gGameWork.penX + width > 0xD0)
            gGameWork.lineFull = 1;
        else
            gGameWork.wordFits = 1;
    }
    if (gGameWork.lineFull != 0)
        return;

    ch = gGameWork.msgText[gGameWork.msgPos];
    if (gGameWork.altFont)
        width = gAltFontWidths[ch][0];
    else
        width = gFontWidths[ch][0];
    gGameWork.penX += width;
    gGameWork.wordPixelsLeft -= width;
    if (gGameWork.composePixels == 0) {
        if (gGameWork.altFont) {
            gGameWork.composePixels = gAltFontWidths[ch][0];
            CpuSet(gAltFontGlyphs + ch * 64, gTextComposeTile, 0x20);
        } else {
            gGameWork.composePixels = gFontWidths[ch][0];
            CpuSet(gFontGlyphs + ch * 64, gTextComposeTile, 0x20);
        }
    } else {
        shift = gGameWork.composePixels;
        if (gGameWork.altFont)
            CpuSet(gAltFontGlyphs + ch * 64, gTextGlyphTile, 0x20);
        else
            CpuSet(gFontGlyphs + ch * 64, gTextGlyphTile, 0x20);
        for (i = 0; i < 16; i++)
            ((u32 *)gTextComposeTile)[i] |= ((u32 *)gTextGlyphTile)[i] << (shift * 4);
        gGameWork.composePixels += width;
    }
    if (gGameWork.composePixels > 7) {
        u8 col = (gGameWork.penX >> 3) - 1;
        CpuSet(gTextComposeTile, (void *)(col * 0x40 + VRAM + 0x280 + gGameWork.textLine * 0x680), 0x20);
        gGameWork.msgStopPrint = 1;
        if (gGameWork.composePixels == 8)
            gGameWork.composePixels = 0;
        else {
            gGameWork.composePixels -= 8;
            shift = 8 - shift;
            if (gGameWork.altFont)
                CpuSet(gAltFontGlyphs, gTextComposeTile, 0x20);
            else
                CpuSet(gFontGlyphs, gTextComposeTile, 0x20);
            for (i = 0; i < 16; i++)
                ((u32 *)gTextComposeTile)[i] |= ((u32 *)gTextGlyphTile)[i] >> (shift * 4);
        }
    }
    if (gGameWork.wordPixelsLeft == 0)
        gGameWork.wordFits = 0;
    gGameWork.msgPos++;
}

// 0xF9 n: print string variable n (0 = gPlayerName, 1-4 = 20-byte buffers from textBuf), one glyph a call.
void message_print_var_step(void) {
    u8 w;
    u8 n;
    u8 i;
    u8 glyph;
    u8 done;

    if (gGameWork.wordFits == 0) {
        w = 0;
        n = 0;
        done = 0;
        gGameWork.varPos = n;
        do {
            switch (gGameWork.msgText[gGameWork.msgPos + 1]) {
            case 1:
                gGameWork.varText = gGameWork.textBuf;
                break;
            case 2:
                gGameWork.varText = gGameWork.textBuf + 0x14;
                break;
            case 3:
                gGameWork.varText = gGameWork.textBuf + 0x28;
                break;
            case 4:
                gGameWork.varText = gGameWork.textBuf + 0x3C;
                break;
            case 0:
            default:
                gGameWork.varText = gPlayerName;
                break;
            }
            glyph = gGameWork.varText[gGameWork.varPos + n++];
            if (gGameWork.altFont)
                w += gAltFontWidths[glyph][0];
            else
                w += gFontWidths[glyph][0];
            glyph = gGameWork.varText[gGameWork.varPos + n];
            if (glyph > 0xF7)
                done = 1;
        } while (!done);
        gGameWork.wordPixelsLeft = w;
        if (gGameWork.penX + w > 0xD0)
            gGameWork.lineFull = 1;
        else
            gGameWork.wordFits = 1;
    }
    if (gGameWork.lineFull == 0) {
        glyph = gGameWork.varText[gGameWork.varPos];
        if (gGameWork.altFont)
            w = gAltFontWidths[glyph][0];
        else
            w = gFontWidths[glyph][0];
        gGameWork.penX += w;
        gGameWork.wordPixelsLeft -= w;
        if (gGameWork.composePixels == 0) {
            if (gGameWork.altFont)
                gGameWork.composePixels = gAltFontWidths[glyph][0];
            else
                gGameWork.composePixels = gFontWidths[glyph][0];
            if (gGameWork.altFont)
                CpuSet(&gAltFontGlyphs[glyph * 64], gTextComposeTile, 0x20);
            else
                CpuSet(&gFontGlyphs[glyph * 64], gTextComposeTile, 0x20);
        } else {
            n = gGameWork.composePixels;
            if (gGameWork.altFont)
                CpuSet(gAltFontGlyphs + glyph * 64, gTextGlyphTile, 0x20);
            else
                CpuSet(gFontGlyphs + glyph * 64, gTextGlyphTile, 0x20);
            for (i = 0; i <= 15; i++)
                ((u32 *)gTextComposeTile)[i] |= ((u32 *)gTextGlyphTile)[i] << (n * 4);
            gGameWork.composePixels += w;
        }
        if (gGameWork.composePixels > 7) {
            i = (gGameWork.penX >> 3) - 1;
            CpuSet(gTextComposeTile, (void *)(VRAM + 0x280 + i * 0x40 + gGameWork.textLine * 0x680), 0x20);
            gGameWork.msgStopPrint = 1;
            if (gGameWork.composePixels == 8) {
                gGameWork.composePixels = 0;
            } else {
                gGameWork.composePixels -= 8;
                n = 8 - n;
                if (gGameWork.altFont)
                    CpuSet(gAltFontGlyphs, gTextComposeTile, 0x20);
                else
                    CpuSet(gFontGlyphs, gTextComposeTile, 0x20);
                for (i = 0; i <= 15; i++)
                    ((u32 *)gTextComposeTile)[i] |= ((u32 *)gTextGlyphTile)[i] >> (n * 4);
            }
        }
        if (gGameWork.wordPixelsLeft == 0) {
            gGameWork.wordFits = 0;
            gGameWork.msgPos += 2;
        }
        gGameWork.varPos++;
    }
}

void message_new_line(void) {
    if (((struct TextColBits *)&gGameWork)->col) {
        u8 col = (gGameWork.penX + 8) / 8 - 1;
        CpuSet(gTextComposeTile, (void *)(col * 0x40 + VRAM + 0x280 + gGameWork.textLine * 0x680), 0x20);
    }
    gGameWork.penX = 0;
    gGameWork.composePixels = 0;
    gGameWork.wordFits = 0;
    gGameWork.lineFull = 0;
    if (gGameWork.textLine == 1)
        gGameWork.lineFull = 2;
    else
        gGameWork.textLine = 1;
}

u8 message_wait_next_page(void) {
    u8 i;
    u8 blink;

    if (((struct TextColBits *)&gGameWork)->col) {
        u8 col = (gGameWork.penX + 8) / 8 - 1;
        CpuSet(gTextComposeTile, (void *)(col * 0x40 + VRAM + 0x280 + gGameWork.textLine * 0x680), 0x20);
    }
    blink = gGameWork.cursorBlink & 8;
    if (blink)
        write_tilemap_rect(2, 1, 0xE, 0x12, gUiTilemapsNamed.more_cursor_off, REG_BG0CNT, 0);
    else
        write_tilemap_rect(2, 1, 0xE, 0x12, gUiTilemapsNamed.more_cursor_on, REG_BG0CNT, blink);
    gGameWork.cursorBlink++;
    gGameWork.msgStopPrint = 1;
    if (KEYS_LO(gRepeatKeys) & (A_BUTTON | B_BUTTON)) {
        play_sound_effect(0xD);
        gGameWork.penX = 0;
        gGameWork.composePixels = 0;
        gGameWork.wordFits = 0;
        gGameWork.lineFull = 0;
        gGameWork.textLine = 0;
        gGameWork.cursorBlink = 0;
        write_tilemap_rect(2, 1, 0xE, 0x12, gUiTilemapsNamed.more_cursor_off, REG_BG0CNT, 0);
        for (i = 0; i <= 0x33; i++)
            CpuSet(gFontGlyphs, (void *)(0x06000280 + i * 0x40), 0x20);
        gGameWork.msgStopPrint = 0;
        return 1;
    }
    return 0;
}

// 0xFA n: wait n frames (0xFF = forever); A or B ends the wait early unless gGameWork.skipBotSetup (demo) is set.
static void message_cmd_wait_skippable(void) {
    u16 pos;
    if (gGameWork.msgWait == 0) {
        if (((struct TextColBits *)&gGameWork)->col) {
            u8 col = (gGameWork.penX + 8) / 8 - 1;
            CpuFastSet(gTextComposeTile, (void *)(col * 0x40 + VRAM + 0x280 + gGameWork.textLine * 0x680), 16);
        }
        pos = gGameWork.msgPos;
        gGameWork.msgWait = gGameWork.msgText[*(vu16 *)&gGameWork.msgPos + 1];
        if (*(vu8 *)&gGameWork.msgWait == 0xFF)
            gGameWork.msgPos = pos + 2;
    } else if (gGameWork.msgWait == 0xFF || --gGameWork.msgWait == 0)
        gGameWork.msgPos += 2;
    else if (gGameWork.skipBotSetup == 0 && (KEYS_LO(gRepeatKeys) & (A_BUTTON | B_BUTTON))) {
        gGameWork.msgWait = 0;
        gGameWork.msgPos += 2;
    }
}

// 0xF7 n: wait n frames (0xFF = forever).
static void message_cmd_wait(void) {
    u16 pos;
    if (gGameWork.msgWait == 0) {
        if (((struct TextColBits *)&gGameWork)->col) {
            u8 col = (gGameWork.penX + 8) / 8 - 1;
            CpuFastSet(gTextComposeTile, (void *)(col * 0x40 + VRAM + 0x280 + gGameWork.textLine * 0x680), 16);
        }
        pos = gGameWork.msgPos;
        gGameWork.msgWait = gGameWork.msgText[*(vu16 *)&gGameWork.msgPos + 1];
        if (*(vu8 *)&gGameWork.msgWait == 0xFF)
            gGameWork.msgPos = pos + 2;
    } else if (gGameWork.msgWait == 0xFF || --gGameWork.msgWait == 0)
        gGameWork.msgPos += 2;
}

// 0xFF mode: end of message. Modes 0, 2, 3 wait for A / B; then run_message state 6 runs the end mode.
static void message_cmd_end(void) {
    if (((struct TextColBits *)&gGameWork)->col) {
        u8 col = (gGameWork.penX + 8) / 8 - 1;
        CpuFastSet(gTextComposeTile, (void *)(col * 0x40 + VRAM + 0x280 + gGameWork.textLine * 0x680), 16);
    }
    gGameWork.penX = 0;
    switch (gGameWork.msgText[gGameWork.msgPos + 1]) {
    case 0:
    case 2:
    case 3:
        if (KEYS_LO(gRepeatKeys) & (A_BUTTON | B_BUTTON)) {
            play_sound_effect(0xD);
            gGameWork.msgState++;
        }
        break;
    case 1:
    case 4:
        gGameWork.msgState++;
        break;
    default:
        gGameWork.msgState++;
        break;
    }
}

// run_message state 6: run end mode gMessageEndModes[msgText[msgPos + 1]] (each steps through its own table by
// endModeStep).
void message_run_command(void) {
    gMessageEndModes[gGameWork.msgText[gGameWork.msgPos + 1]]();
}

void message_end_wait_close(void) {
    gMessageEndWaitCloseSteps[gGameWork.endModeStep]();
}

void message_end_close(void) {
    gMessageEndCloseSteps[gGameWork.endModeStep]();
}

void message_end_wait_keep(void) {
    gMessageEndWaitKeepSteps[gGameWork.endModeStep]();
}

void message_end_wait_clear(void) {
    gMessageEndWaitClearSteps[gGameWork.endModeStep]();
}

void message_end_keep(void) {
    gMessageEndKeepSteps[gGameWork.endModeStep]();
}

// End step 0: clear the speaker portrait.
void message_close_portrait(void) {
    struct GameWork *game = &gGameWork;
    u8 x;
    u8 mode;
    u32 shown;

    if ((mode = game->portraitMode) != 2 && (shown = game->portraitShown) == 1) {
        x = game->portraitSide == 0 ? 0x13 : 3;
        if (mode == 0) {
            if ((u8)message_portrait_anim_step((u8)game->portraitSet, (u8)game->portraitIndex, x, 5, game->portraitSide,
                                               shown) != 1)
                return;
        } else
            vram_fill_tilemap_rect(8, 8, x, 5, REG_BG0CNT, mode = 0);
        game->portraitAnimFrame = mode;
        game->portraitShown = mode;
    }
    game->endModeStep++;
}

// End step 1: a frameless window (noWindowFrame == 1) is just cleared, skipping the frame animation.
void message_close_check_frame(void) {
    if (gGameWork.noWindowFrame == 1) {
        vram_fill_tilemap_rect(0x1E, 6, 0, 0xD, REG_BG0CNT, 0);
        gGameWork.endModeStep += 2;
    } else
        gGameWork.endModeStep++;
}

// End step 2: closes the window frame in three frames (reverse of message_open_window_frame).
void message_close_window_frame(void) {
    switch (gGameWork.frameAnimStep) {
    case 3:
        lz_decompress_dispatch(gMessageWindowOpenTiles2, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gMessageWindowOpenTilemap2, REG_BG0CNT, 1);
        gGameWork.frameAnimStep--;
        break;
    case 2:
        lz_decompress_dispatch(gMessageWindowOpenTiles1, (void *)(VRAM + 0x20));
        set_tilemap_and_decompress_bg(0, 0xD, gMessageWindowOpenTilemap1, REG_BG0CNT, 1);
        gGameWork.frameAnimStep--;
        break;
    case 1:
        vram_fill_tilemap_rect(0x1E, 6, 0, 0xD, REG_BG0CNT, 0);
        gGameWork.frameAnimStep--;
        break;
    default:
        gGameWork.endModeStep++;
        break;
    }
}

// End step 3: undim the palettes only if message_open dimmed them (msgKeepPalettes == 0).
void message_close_check_dim(void) {
    if (gGameWork.msgKeepPalettes == 0)
        gGameWork.endModeStep += 1;
    else
        gGameWork.endModeStep += 2;
}

// Message close step: undo message_dim_palettes_step one frame at a time (dimLevel down to 0).
void message_undim_palettes_step(void) {
    bg_palettes_blend_masked_now(0x1B2, gGameWork.dimLevel * 2, 0x1FFF);
    obj_palettes_blend_masked_now(0x1B2, gGameWork.dimLevel * 2, 0x1FFF);
    if (gGameWork.dimLevel == 0)
        gGameWork.endModeStep++;
    else
        gGameWork.dimLevel--;
}

// Last message close step: run_message state 8 (done, run_message returns 1).
void message_close(void) {
    gGameWork.msgState = 8;
}
