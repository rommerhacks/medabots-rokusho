// Mode-2 state 4: the item menu opened from the field menu. item_menu_update runs gItemMenuStates:
//   0 reset, 1 load graphics, 2 init, 3 fade in, 4 item description, 5 list input, 6 start a SELECT swap,
//   7-8 close the message and fade out to the field, 9-10 "can't use" message, 11-12 white fade to the town
//   map (item 0), 13-14 close the message and fade out wearing a disguise (item_menu_fade_out_use_item is in
//   save/save_screen.c). Lists are drawn by menu/item_list.c; uses text/ messages and engine/ sprites.
#include "global.h"
#include "constants/sprites.h"

void item_menu_update(void) {
    gItemMenuStates[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

// While a SELECT swap is active, blinks the swap marker (sprite 84) if the marked item is on this page.
static void item_menu_blink_swap_marker(u32 frame) {
    struct MenuWork *w = gMenuWork;
    if (w->swap_pending) {
        if (w->swap_from >= w->list_top && w->swap_from < w->list_top + 5) {
            if (frame & 1)
                gSpriteEntries[84].flags &= (u16)~SPRITE_FLAG_VISIBLE;
            else
                gSpriteEntries[84].flags |= SPRITE_FLAG_VISIBLE;
        } else
            gSpriteEntries[84].flags &= (u16)~SPRITE_FLAG_VISIBLE;
    }
}

void item_menu_reset(void) {
    u32 zero = 0;
    CpuFastSet(&zero, gMenuWork, 0x01000100);
    reset_bg_scroll();
    REG_DISPCNT = 0x160;
    gGameSubState++;
}

static inline void *vram_at(u32 off) {
    return (void *)(BG_CHAR_ADDR(1) + off);
}

void item_menu_load_graphics(void) {
    u32 size;
    u8 i;
    vu16 *bg1, *bg2, *bg3;
    u16 bgcnt;

    bg1 = &REG_BG1CNT;
    bgcnt = 0x1E05;
    *bg1 = bgcnt;
    bg2 = &REG_BG2CNT;
    bgcnt = 0x1C06;
    *bg2 = bgcnt;
    bg3 = &REG_BG3CNT;
    bgcnt = 0x3D07;
    *bg3 = bgcnt;
    decompress_and_write_tilemap(gItemMenuBg1Tilemap, *bg1);
    decompress_and_write_tilemap(gItemMenuBg2Tilemap, *bg2);
    decompress_and_write_tilemap(gItemMenuBg3Tilemap, *bg3);
    size = dma3_copy_or_decompress(gItemMenuBgTiles, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, vram_at(0), size);
    lz_decompress_dispatch(gMenuDigitTilesLz, vram_at(size));
    gMenuWork->bg_tile_base = (size >> 5) - 1;
    lz_decompress_dispatch(gMenuObjTilesLz, (void *)OBJ_VRAM0);
    for (i = 0; i <= 1; i++) {
        gSpriteEntries[i + 0x51].flags = SPRITE_FLAG_ENABLED;
        gSpriteEntries[i + 0x51].frame_table = 2;
        gSpriteEntries[i + 0x51].x = i * 40 + 0x18;
        gSpriteEntries[i + 0x51].y = 0x18;
        gSpriteEntries[i + 0x51].palette = 0;
        gSpriteEntries[i + 0x51].frame = 5;
    }
    gSpriteEntries[0x51].flags |= SPRITE_FLAG_HFLIP;
    for (i = 0; i <= 1; i++) {
        gSpriteEntries[i + 0x53].flags = SPRITE_FLAG_ENABLED;
        gSpriteEntries[i + 0x53].frame_table = 2;
        gSpriteEntries[i + 0x53].palette = 0;
        gSpriteEntries[i + 0x53].frame = 6;
    }
    for (i = 0; i <= 4; i++) {
        gSpriteEntries[i + 0x55].flags = SPRITE_FLAG_ENABLED;
        gSpriteEntries[i + 0x55].frame_table = 2;
        gSpriteEntries[i + 0x55].palette = 0xE;
        gSpriteEntries[i + 0x55].frame = 7;
        gSpriteEntries[i + 0x55].x = 0xE0;
        gSpriteEntries[i + 0x55].y = i * 16 + 0x20;
    }
    lz_decompress_dispatch(gSpriteFontTiles, (void *)(OBJ_VRAM0 + 0x7400));
    gGameSubState++;
}

void item_menu_init(void) {
    u32 zero;
    struct MenuWork *w;

    gMenuWork->returning = 0;
    gMenuWork->item_cursor = 0;
    gMenuWork->list_top = 0;
    unpack_item_inventory_to_buffer();
    update_battle_medapart_icons();
    if (gMenuWork->item_count) {
        gSpriteEntries[0x53].flags |= SPRITE_FLAG_VISIBLE;
        item_menu_set_cursor_pos(&gSpriteEntries[0x53]);
    }
    w = gMenuWork;
    if ((w->item_count - 1) / 5) {
        gSpriteEntries[0x51].flags |= SPRITE_FLAG_VISIBLE;
        gSpriteEntries[0x52].flags |= SPRITE_FLAG_VISIBLE;
    }
    w->swap_pending = 0;
    CpuFastSet(gGradientPaletteYellow, gPaletteBackup, 0x80);
    CpuFastSet(gCursorArrowPalette, gPaletteBackup, 8);
    CpuFastSet(gItemMenuObjPalette, (void *)OBJ_PAL_BACKUP_ADDR(14), 8);
    CpuFastSet(gItemMenuBgPalettes, gPaletteBackupBg, 0x80);
    zero = 0;
    CpuFastSet(&zero, (void *)(PLTT + 0x1A0), 0x01000008);
    gGameWork.stepCounter = 0;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gGameSubState++;
}

void item_menu_fade_in(void) {
    struct GameWork *game = &gGameWork;
    if (game->stepCounter <= 8) {
        if (gMenuWork->returning == 0)
            bg_palettes_blend_masked_now(0, 0x20 - game->stepCounter * 4, 0x3FFF);
        else
            bg_palettes_blend_masked_now(0, 0x20 - game->stepCounter * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, 0x20 - gGameWork.stepCounter * 4, 0xFFFF);
        gGameWork.stepCounter++;
    } else {
        text_window_init(1, 2, 0);
        gGameSubState++;
    }
}

void item_menu_show_description(void) {
    u8 id;
    struct MenuWork *w;
    item_menu_blink_swap_marker(gFrameCounter);
    sprite_bob_x(0x53, gFrameCounter, 0x54);
    w = gMenuWork;
    if (w->item_count) {
        struct ItemListEntry *list = (struct ItemListEntry *)MENU_LIST_ADDR;
        id = list[w->item_cursor].id;
    } else
        id = 0x3F;
    if (run_message(gItemDescriptions[id]))
        gGameSubState++;
}

#define ITEM_LIST ((struct ItemListEntry *)MENU_LIST_ADDR)

// Item list input: 5 items per page; UP/DOWN move, LEFT/RIGHT page, SELECT starts a swap, A uses, B closes.
void item_menu_handle_input(void) {
    struct MenuWork *w;
    struct MenuWork *w2;
    struct MenuWork *w3;
    struct ItemListEntry *list;
    struct FieldSceneParams *sel;
    u8 n = 5;
    u8 cnt;

    sprite_bob_x(0x53, gFrameCounter, 0x54);
    if ((gMenuWork->item_count - 1) / 5) {
        if ((gFrameCounter >> 4) & 1) {
            gSpriteEntries[0x51].flags |= SPRITE_FLAG_VISIBLE;
            gSpriteEntries[0x52].flags |= SPRITE_FLAG_VISIBLE;
        } else {
            gSpriteEntries[0x51].flags &= (u16)~SPRITE_FLAG_VISIBLE;
            gSpriteEntries[0x52].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        }
    }

    w = gMenuWork;
    if (w->item_count > 1) {
        if (KEYS_LO(gRepeatKeys) & DPAD_UP) {
            if (w->item_cursor == w->list_top) {
                if ((u8)(w->list_top / n) == (u8)(w->item_count / n))
                    w->item_cursor = w->list_top + w->item_count % n - 1;
                else
                    w->item_cursor = n + w->list_top - 1;
            } else
                w->item_cursor--;
            goto moved;
        } else if (KEYS_LO(gRepeatKeys) & DPAD_DOWN) {
            if ((u8)(w->list_top / n) == (u8)(w->item_count / n)) {
                if (w->item_cursor == w->list_top + (u8)(w->item_count % n) - 1)
                    w->item_cursor = w->list_top;
                else
                    w->item_cursor++;
            } else {
                if (w->item_cursor == w->list_top + n - 1)
                    w->item_cursor = w->list_top;
                else
                    w->item_cursor++;
            }
            goto moved;
        } else if ((cnt = w->item_count) >= n + 1) {
            if (KEYS_LO(gRepeatKeys) & DPAD_RIGHT) {
                if (w->list_top + n >= cnt)
                    w->list_top = 0;
                else
                    w->list_top += n;
            } else if (KEYS_LO(gRepeatKeys) & DPAD_LEFT) {
                if (w->list_top >= n)
                    w->list_top -= n;
                else if ((u8)(cnt % n) == 0)
                    w->list_top = cnt - n;
                else
                    w->list_top = cnt / n * n;
            } else
                goto other;
            gMenuWork->item_cursor = gMenuWork->list_top;
            update_battle_medapart_icons();
            item_menu_update_swap_marker(&gSpriteEntries[0x54]);
            goto moved;
        }
    }

other:
    w2 = gMenuWork;
    if (w2->swap_pending) {
        item_menu_blink_swap_marker(gFrameCounter);
        if (KEYS_LO(gNewKeys) & B_BUTTON) {
            gSpriteEntries[0x54].flags &= (u16)~SPRITE_FLAG_VISIBLE;
            gMenuWork->swap_pending = 0;
            goto moved;
        }
        if (!(KEYS_LO(gNewKeys) & (A_BUTTON | SELECT_BUTTON)))
            return;
        gSpriteEntries[0x54].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        gMenuWork->swap_pending = 0;
        swap_inventory_items();
        unpack_item_inventory_to_buffer();
        update_battle_medapart_icons();
        goto moved;
    }
    if (w2->item_count > 1 && (KEYS_LO(gNewKeys) & SELECT_BUTTON)) {
        w2->timer = 0;
        play_sound_effect(2);
        item_menu_start_swap();
    }
    w3 = gMenuWork;
    if (w3->swap_pending)
        return;
    if (KEYS_LO(gNewKeys) & A_BUTTON) {
        if (w3->item_count == 0)
            goto cancel;
        sel = &gFieldSceneParams;
        list = ITEM_LIST;
        sel->selected_item = list[w3->item_cursor].id;
        switch ((s32)item_get_use_result(list[w3->item_cursor].id)) {
        case 2:
        case 3:
        case 4:
            message_next();
            play_sound_effect(6);
            gSpriteEntries[0x51].flags &= (u16)~SPRITE_FLAG_VISIBLE;
            gSpriteEntries[0x52].flags &= (u16)~SPRITE_FLAG_VISIBLE;
            gGameSubState = 9;
            return;
        case 1:
            play_sound_effect(4);
            switch (ITEM_LIST[gMenuWork->item_cursor].id) {
            case 0:
                gMenuWork->fade_level = 0;
                gGameSubState = 0xB;
                return;
            case 1:
                gFieldWork.player_form = 3;
                break;
            case 5:
                gFieldWork.player_form = 4;
                break;
            case 12:
                gFieldWork.player_form = 5;
                break;
            case 13:
                gFieldWork.player_form = 8;
                break;
            case 19:
                gFieldWork.player_form = 6;
                break;
            case 39:
                gFieldWork.player_form = 7;
                break;
            case 40:
                gFieldWork.player_form = 0xD;
                break;
            default:
                dispatch_by_index_0476e8(4);
                return;
            }
            gGameWork.stepCounter = 0;
            gGameSubState = 0xD;
            return;
        case 0:
            play_sound_effect(6);
            return;
        }
    }
    if (KEYS_LO(gNewKeys) & B_BUTTON) {
    cancel:
        play_sound_effect(5);
        palette_backup_from_hardware();
        gGameWork.stepCounter = 0;
        gGameSubState = 7;
    }
    return;

moved:
    play_sound_effect(2);
    message_next();
    item_menu_set_cursor_pos(&gSpriteEntries[0x53]);
    gGameSubState = 4;
    item_menu_blink_swap_marker(gFrameCounter);
}

// Starts the SELECT reorder: shows the swap marker (sprite 0x54) on the cursor item and remembers it in swap_from.
void item_menu_start_swap(void) {
    struct MenuWork **pw = &gMenuWork;
    item_menu_set_cursor_pos(&gSpriteEntries[0x54]);
    gSpriteEntries[0x54].flags |= SPRITE_FLAG_VISIBLE;
    gSpriteEntries[0x54].x++;
    gSpriteEntries[0x54].y++;
    (*pw)->swap_pending = 1;
    (*pw)->swap_from = (*pw)->item_cursor;
}

void item_menu_close_message(void) {
    if (game_state_execute_handler_a())
        gGameSubState++;
}

void item_menu_fade_out_exit(void) {
    struct GameWork *game = &gGameWork;
    if (game->stepCounter <= 8) {
        bg_palettes_blend_masked_now(0, game->stepCounter * 4, 0x3FFF);
        obj_palettes_blend_masked_now(0, game->stepCounter * 4, 0xFFFF);
        game->stepCounter++;
    } else {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFBFF;
        clear_battle_sprite_slot(0, 0x80);
        gGameMode = 0;
        gGameState = MODE0_STATE_FIELD_MENU;
        gGameSubState = 0x10;
    }
}

// item_get_use_result 2-4: the item can't be used here (message 8 of gSystemMessages).
void item_menu_show_cannot_use(void) {
    if (run_message(gSystemMessages[8]))
        gGameSubState++;
}

void item_menu_wait_message_key(void) {
    if (KEYS_LO(gNewKeys) & (A_BUTTON | B_BUTTON)) {
        play_sound_effect(2);
        message_next();
        gGameSubState = 4;
    }
}

void item_menu_start_town_map_fade(void) {
    REG_BLDCNT = 0x2FF;
    gGameSubState++;
}

void item_menu_fade_to_town_map(void) {
    struct MenuWork *w = gMenuWork;
    if (w->fade_level != 8) {
        REG_BLDY = ++w->fade_level * 2;
    } else {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFBFF;
        clear_battle_sprite_slot(0, 0x80);
        gMenuWork->returning = 1;
        gGameState = 10;
        gGameSubState = 0;
    }
}

void item_menu_close_use_message(void) {
    if (game_state_execute_handler_a())
        gGameSubState++;
}
