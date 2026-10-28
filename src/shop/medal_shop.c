// Mode-2 state 18 (medal_rename_main): the screen before name entry. For the player name and a new Medal
// (gNameEntryMode 0 / 1) it goes straight to name entry (state 6); for mode 2 it is the Medal rename service:
// "Do you want to change a Medal name?", pick an owned Medal, pay 100, then rename it in name entry.
// Its sub-state table gMedalRenameStates directly follows the shop list's (gShopListHandlers, shop/shop_list.c).
#include "global.h"
#include "constants/sprites.h"

static inline void *vram_at(u32 off) {
    return (void *)(0x06004000 + off);
}

// Draws up to 4 Medal names (and their icons) of the owned list, from entry start.
void medal_rename_draw_list(u8 start) {
    s32 i, j;
    s32 n;
    u8 *p = &gMenuWork->medal_list_count;
    if (*p > 3)
        n = 4;
    else
        n = *p;
    i = 0;
    while (i < n) {
        u16 v;
        u16 *dst;
        for (j = 0; j <= 10; j++)
            gSpriteEntries[i * 10 + 12 + j].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        for (j = 0; j <= 10; j++) {
            gMenuWork->name_buf[j] = gMedals[gMenuWork->medal_list[i + start]].name[j];
            if (gMenuWork->name_buf[j] == 0xFE)
                break;
        }
        render_text_sprites_08040DB8(gMenuWork->name_buf, i * 10 + 12, 6, i * 2 + 3, 10, 13, 1, 1);
        v = gMenuWork->bg_tile_base + (gMedals[gMenuWork->medal_list[i + start]].graphicId * 4 + 1);
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

// Last sub-state: back to building the list.
void medal_rename_restart_list(void) {
    gGameSubState = 1;
}

void medal_rename_main(void) {
    gMedalRenameStates[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void medal_rename_reset_cursor(void) {
    gMenuWork->medal_list_top = 0;
    gMenuWork->medal_list_cursor = 0;
    gGameSubState++;
}

// Builds the owned Medal list in unkB0; outside rename mode it hands over to name entry at once.
void medal_rename_build_list(void) {
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
        if (gMedals[i].flags & 0x80) {
            gMenuWork->medal_list[n] = i;
            n++;
        }
    }
    gMenuWork->medal_list_count = n;
    if (gNameEntryMode != 2) {
        gGameState = 6;
        gGameSubState = 0;
    } else {
        reset_bg_scroll();
        REG_DISPCNT = 0x60;
        gGameSubState++;
    }
}

void medal_rename_load_graphics(void) {
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
    decompress_and_write_tilemap(gMedalRenameBg1Tilemap, *bg1);
    decompress_and_write_tilemap(gMedalRenameBg2Tilemap, *bg2);
    decompress_and_write_tilemap(gMedalRenameBg3Tilemap, *bg3);
    size = dma3_copy_or_decompress(gMedalRenameBgTiles, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, vram_at(0), size);
    gMenuWork->bg_tile_base = (size >> 5) - 1;
    zero = 0;
    CpuFastSet(gMedalIconTiles, vram_at(size), 0x400);
    lz_decompress_dispatch(gMenuObjTilesLz, (void *)0x06010000);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
    gSpriteEntries[8].flags = SPRITE_FLAG_ENABLED;
    gSpriteEntries[8].frame_table = 2;
    gSpriteEntries[8].palette = zero;
    gSpriteEntries[8].frame = 6;
    gSpriteEntries[8].x = 0xC;
    gSpriteEntries[8].y = gMenuWork->medal_list_top * 16 + 0x1C;
    for (i = 0; i <= 1; i++) {
        gSpriteEntries[i + 10].flags = SPRITE_FLAG_ENABLED;
        gSpriteEntries[i + 10].frame_table = 2;
        gSpriteEntries[i + 10].palette = 0;
        gSpriteEntries[i + 10].frame = 8;
        gSpriteEntries[i + 10].x = 0x20;
        gSpriteEntries[i + 10].y = i * 72 + 0x14;
    }
    gSpriteEntries[11].flags |= SPRITE_FLAG_VFLIP;
    z2 = 0;
    gSpriteEntries[7].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE;
    gSpriteEntries[7].frame_table = 2;
    gSpriteEntries[7].palette = 10;
    gSpriteEntries[7].frame = 0x1A;
    gSpriteEntries[7].x = 0x98;
    gSpriteEntries[7].y = z2;
    divide_by_10000(gTextArgBuffer, gMoney);
    render_text_sprites_08040DB8(gTextArgBuffer, 0, 0x15, 1, 7, 0xF, 1, z2);
    gGameSubState++;
}

void medal_rename_load_palettes(void) {
    s8 i;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    for (i = 0; i <= 15; i++)
        gMenuWork->name_buf[i] = 0xFE;
    if (gNameEntryMode == 0) {
        for (i = 0; i <= 15 && gMenuWork->name_buf[i] != 0xFE; i++)
            ;
    } else
        medal_rename_draw_list(gMenuWork->medal_list_cursor);
    CpuFastSet(gMenuDigitPalette, (void *)0x0202FA20, 8);
    CpuFastSet(gCursorArrowPalette, gPaletteBackup, 8);
    CpuFastSet(gSpriteFontPalette, (void *)0x0202F9E0, 8);
    CpuFastSet(gGradientPaletteGold, (void *)0x0202F9A0, 8);
    CpuFastSet(gMedalRenameBgPalettes, gPaletteBackupBg, 0x80);
    CpuFastSet(gMedalRenameObjPalette, (void *)0x0202F940, 8);
    gGameWork.unk84 = 0;
    gGameSubState++;
}

void medal_rename_fade_in(void) {
    struct GameWork *s = &gGameWork;
    if (s->unk84 <= 8) {
        bg_palettes_blend_masked_now(0, 32 - s->unk84 * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, 32 - s->unk84 * 4, 0xFFFF);
        s->unk84++;
    } else {
        gMenuWork->message_pending = 0;
        text_window_init(1, 0, 0);
        gMenuWork->returning = 0;
        gGameSubState++;
    }
}

void medal_rename_select_medal(void) {
    u32 r = 1;
    u8 keys;
    u32 se;
    if (gMenuWork->message_pending) {
        if (game_state_execute_handler_a()) {
            gMenuWork->message_pending = 0;
            text_window_init(1, 0, 0);
        }
    } else if (run_message(gSystemMessages[13]))
        r = 0;
    if (r != 0)
        return;
    sprite_bob_x(8, gFrameCounter, 12);
    gSpriteEntries[8].flags |= SPRITE_FLAG_VISIBLE;
    if (gMenuWork->medal_list_count > 4) {
        if (gMenuWork->medal_list_cursor != 0) {
            if ((gFrameCounter & 0xF) <= 9)
                gSpriteEntries[10].flags |= SPRITE_FLAG_VISIBLE;
            else
                gSpriteEntries[10].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        } else
            gSpriteEntries[10].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        if (gMenuWork->medal_list_cursor + 4 >= gMenuWork->medal_list_count)
            gSpriteEntries[11].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        else if ((gFrameCounter & 0xF) <= 9)
            gSpriteEntries[11].flags |= SPRITE_FLAG_VISIBLE;
        else
            gSpriteEntries[11].flags &= (u16)~SPRITE_FLAG_VISIBLE;
    }
    if ((keys = KEYS_LO(gRepeatKeys) & 0x40)) {
        se = 2;
        if (gMenuWork->medal_list_top != 0)
            gMenuWork->medal_list_top--;
        else if (gMenuWork->medal_list_cursor != 0)
            gMenuWork->medal_list_cursor--;
        else if (gMenuWork->medal_list_count <= 3)
            gMenuWork->medal_list_top = gMenuWork->medal_list_count - 1;
        else
            goto skip;
        if (se != 0)
            play_sound_effect(se);
    skip:
        medal_rename_draw_list(gMenuWork->medal_list_cursor);
    } else if (KEYS_LO(gRepeatKeys) & 0x80) {
        se = 2;
        if (gMenuWork->medal_list_count <= 3) {
            if (gMenuWork->medal_list_top == gMenuWork->medal_list_count - 1)
                gMenuWork->medal_list_top = keys;
            else
                gMenuWork->medal_list_top++;
        } else if (gMenuWork->medal_list_top == 3) {
            if (gMenuWork->medal_list_cursor == gMenuWork->medal_list_count - 4)
                se = 0;
            else
                gMenuWork->medal_list_cursor++;
        } else
            gMenuWork->medal_list_top++;
        if (se != 0)
            play_sound_effect(se);
        medal_rename_draw_list(gMenuWork->medal_list_cursor);
    } else if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        gSpriteEntries[10].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        gSpriteEntries[11].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        gSpriteEntries[8].x = 12;
        gMenuWork->message_pending = 1;
        gGameWork.endModeStep = 0;
        gGameSubState = 9;
        open_choice_menu(1, 0x16, 7);
        return;
    } else {
        if (KEYS_LO(gNewKeys) & 2) {
            play_sound_effect(5);
            gSpriteEntries[8].flags &= (u16)~SPRITE_FLAG_VISIBLE;
            gGameWork.endModeStep = 0;
            gGameWork.unk84 = 0;
            gGameSubState = 7;
        }
        return;
    }
    gSpriteEntries[8].x = 12;
    gSpriteEntries[8].y = gMenuWork->medal_list_top * 16 + 0x1C;
}

void medal_rename_fade_to_name_entry(void) {
    if (game_state_execute_handler_a()) {
        struct GameWork *s = &gGameWork;
        if (s->unk84 <= 8) {
            bg_palettes_blend_masked_now(0, s->unk84 * 4, 0xFFFF);
            obj_palettes_blend_masked_now(0, s->unk84 * 4, 0xFFFF);
            s->unk84++;
        } else {
            REG_DISPCNT &= ~0x200;
            gGameState = 6;
            gGameSubState = 0;
        }
    }
}

void medal_rename_fade_to_field(void) {
    if (game_state_execute_handler_a()) {
        struct GameWork *s = &gGameWork;
        if (s->unk84 <= 8) {
            bg_palettes_blend_masked_now(0, s->unk84 * 4, 0xFFFF);
            obj_palettes_blend_masked_now(0, s->unk84 * 4, 0xFFFF);
            s->unk84++;
        } else {
            REG_DISPCNT &= ~0x200;
            clear_battle_sprite_slot(0, 0x80);
            dispatch_by_index_0476e8(2);
        }
    }
}

void medal_rename_no_money(void) {
    u32 r = 1;
    if (gMenuWork->message_pending) {
        if (game_state_execute_handler_a()) {
            gMenuWork->message_pending = 0;
            text_window_init(1, 0, 0);
        }
    } else if (run_message(gSystemMessages[15]))
        r = 0;
    if (r == 0 && KEYS_LO(gNewKeys) & 3) {
        message_next();
        gGameSubState = 5;
    }
}

// "It'll cost you 100. Is that OK?": Yes pays and goes on to name entry for gCurrentMedalSlot.
void medal_rename_confirm_payment(void) {
    u32 r = 1;
    u32 sel;
    if (gMenuWork->message_pending) {
        if (game_state_execute_handler_a()) {
            gMenuWork->message_pending = 0;
            text_window_init(1, 0, 0);
        }
    } else if (run_message(gSystemMessages[14]))
        r = 0;
    if (r == 0 && (r = poll_choice_menu()) != 0) {
        u32 c = r & 0xF0;
        if (c) {
            gMenuWork->message_pending = 1;
            gGameSubState = 5;
        } else if (gMoney <= 99) {
            gGameSubState = 8;
            gMenuWork->frame = 0xB4;
            gMenuWork->message_pending = 1;
        } else {
            gMoney -= 100;
            gCurrentMedalSlot = gMenuWork->medal_list[gMenuWork->medal_list_top + gMenuWork->medal_list_cursor];
            gGameWork.unk84 = c;
            gGameSubState = 6;
        }
    }
}
