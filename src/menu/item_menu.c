// Mode-2 state 4: the item menu opened from the field menu. item_menu_update runs gItemMenuStates:
//   0 reset, 1 load graphics, 2 init, 3 fade in, 4 item description, 5 list input, 6 start a SELECT swap,
//   7-8 close the message and fade out to the field, 9-10 "can't use" message, 11-12 white fade to the town
//   map (item 0), 13-14 close the message and fade out wearing a disguise (item_menu_fade_out_use_item is in
//   save/save_screen.c). Lists are drawn by menu/item_list.c; uses text/ messages and engine/ sprites.
#include "global.h"

void item_menu_update(void) {
    gItemMenuStates[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

// While a SELECT swap is active, blinks the swap marker (sprite 84) if the marked item is on this page.
static void item_menu_blink_swap_marker(u32 a) {
    struct MenuWork *w = gMenuWork;
    if (w->unk12) {
        if (w->unk13 >= w->unk11 && w->unk13 < w->unk11 + 5) {
            if (a & 1)
                gSpriteEntries[84].unk0 &= 0xBFFF;
            else
                gSpriteEntries[84].unk0 |= 0x4000;
        } else
            gSpriteEntries[84].unk0 &= 0xBFFF;
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
    return (void *)(0x06004000 + off);
}

void item_menu_load_graphics(void) {
    u32 size;
    u8 i;
    vu16 *bg1, *bg2, *bg3;
    u16 v;

    bg1 = &REG_BG1CNT;
    v = 0x1E05;
    *bg1 = v;
    bg2 = &REG_BG2CNT;
    v = 0x1C06;
    *bg2 = v;
    bg3 = &REG_BG3CNT;
    v = 0x3D07;
    *bg3 = v;
    decompress_and_write_tilemap(gUnk_0878C484, *bg1);
    decompress_and_write_tilemap(gUnk_0878C5B4, *bg2);
    decompress_and_write_tilemap(gUnk_0878C750, *bg3);
    size = dma3_copy_or_decompress(gUnk_0878B078, gDecompressBuffer);
    CpuCopy16(gDecompressBuffer, vram_at(0), size);
    lz_decompress_dispatch(gUnk_08784CB0, vram_at(size));
    gMenuWork->unk36 = (size >> 5) - 1;
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    for (i = 0; i <= 1; i++) {
        gSpriteEntries[i + 0x51].unk0 = 0x8000;
        gSpriteEntries[i + 0x51].unk1C = 2;
        gSpriteEntries[i + 0x51].unk2 = i * 40 + 0x18;
        gSpriteEntries[i + 0x51].unk4 = 0x18;
        gSpriteEntries[i + 0x51].unkA = 0;
        gSpriteEntries[i + 0x51].unk6 = 5;
    }
    gSpriteEntries[0x51].unk0 |= 0x1000;
    for (i = 0; i <= 1; i++) {
        gSpriteEntries[i + 0x53].unk0 = 0x8000;
        gSpriteEntries[i + 0x53].unk1C = 2;
        gSpriteEntries[i + 0x53].unkA = 0;
        gSpriteEntries[i + 0x53].unk6 = 6;
    }
    for (i = 0; i <= 4; i++) {
        gSpriteEntries[i + 0x55].unk0 = 0x8000;
        gSpriteEntries[i + 0x55].unk1C = 2;
        gSpriteEntries[i + 0x55].unkA = 0xE;
        gSpriteEntries[i + 0x55].unk6 = 7;
        gSpriteEntries[i + 0x55].unk2 = 0xE0;
        gSpriteEntries[i + 0x55].unk4 = i * 16 + 0x20;
    }
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    gGameSubState++;
}

void item_menu_init(void) {
    u32 zero;
    struct MenuWork *w;

    gMenuWork->unk6 = 0;
    gMenuWork->unkC = 0;
    gMenuWork->unk11 = 0;
    unpack_item_inventory_to_buffer();
    update_battle_medapart_icons();
    if (gMenuWork->unk10) {
        gSpriteEntries[0x53].unk0 |= 0x4000;
        item_menu_set_cursor_pos(&gSpriteEntries[0x53]);
    }
    w = gMenuWork;
    if ((w->unk10 - 1) / 5) {
        gSpriteEntries[0x51].unk0 |= 0x4000;
        gSpriteEntries[0x52].unk0 |= 0x4000;
    }
    w->unk12 = 0;
    CpuFastSet(gUnk_0850DCF8, gPaletteBackup, 0x80);
    CpuFastSet(gCursorArrowPalette, gPaletteBackup, 8);
    CpuFastSet(gUnk_080AF7C0, (void *)0x0202F9C0, 8);
    CpuFastSet(gUnk_0878AE78, gPaletteBackupBg, 0x80);
    zero = 0;
    CpuFastSet(&zero, (void *)(PLTT + 0x1A0), 0x01000008);
    gGameWork.unk84 = 0;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gGameSubState++;
}

void item_menu_fade_in(void) {
    struct GameWork *b = &gGameWork;
    if (b->unk84 <= 8) {
        if (gMenuWork->unk6 == 0)
            bg_palettes_blend_masked_now(0, 0x20 - b->unk84 * 4, 0x3FFF);
        else
            bg_palettes_blend_masked_now(0, 0x20 - b->unk84 * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, 0x20 - gGameWork.unk84 * 4, 0xFFFF);
        gGameWork.unk84++;
    } else {
        text_window_init(1, 2, 0);
        gGameSubState++;
    }
}

void item_menu_show_description(void) {
    u8 id;
    struct MenuWork *w;
    item_menu_blink_swap_marker(gFrameCounter);
    sprite_bob_y(0x53, gFrameCounter, 0x54);
    w = gMenuWork;
    if (w->unk10) {
        struct ItemListEntry *l = (struct ItemListEntry *)0x02040000;
        id = l[w->unkC].id;
    } else
        id = 0x3F;
    if (run_message(gItemDescriptions[id]))
        gGameSubState++;
}

#define ITEM_LIST ((struct ItemListEntry *)0x02040000)

// Item list input: 5 items per page; UP/DOWN move, LEFT/RIGHT page, SELECT starts a swap, A uses, B closes.
void item_menu_handle_input(void) {
    struct MenuWork *w;
    struct MenuWork *w2;
    struct MenuWork *w3;
    struct ItemListEntry *list;
    struct Unk_03006D38 *sel;
    u8 n = 5;
    u8 cnt;

    sprite_bob_y(0x53, gFrameCounter, 0x54);
    if ((gMenuWork->unk10 - 1) / 5) {
        if ((gFrameCounter >> 4) & 1) {
            gSpriteEntries[0x51].unk0 |= 0x4000;
            gSpriteEntries[0x52].unk0 |= 0x4000;
        } else {
            gSpriteEntries[0x51].unk0 &= 0xBFFF;
            gSpriteEntries[0x52].unk0 &= 0xBFFF;
        }
    }

    w = gMenuWork;
    if (w->unk10 > 1) {
        if (KEYS_LO(gRepeatKeys) & 0x40) {
            if (w->unkC == w->unk11) {
                if ((u8)(w->unk11 / n) == (u8)(w->unk10 / n))
                    w->unkC = w->unk11 + w->unk10 % n - 1;
                else
                    w->unkC = n + w->unk11 - 1;
            } else
                w->unkC--;
            goto moved;
        } else if (KEYS_LO(gRepeatKeys) & 0x80) {
            if ((u8)(w->unk11 / n) == (u8)(w->unk10 / n)) {
                if (w->unkC == w->unk11 + (u8)(w->unk10 % n) - 1)
                    w->unkC = w->unk11;
                else
                    w->unkC++;
            } else {
                if (w->unkC == w->unk11 + n - 1)
                    w->unkC = w->unk11;
                else
                    w->unkC++;
            }
            goto moved;
        } else if ((cnt = w->unk10) >= n + 1) {
            if (KEYS_LO(gRepeatKeys) & 0x10) {
                if (w->unk11 + n >= cnt)
                    w->unk11 = 0;
                else
                    w->unk11 += n;
            } else if (KEYS_LO(gRepeatKeys) & 0x20) {
                if (w->unk11 >= n)
                    w->unk11 -= n;
                else if ((u8)(cnt % n) == 0)
                    w->unk11 = cnt - n;
                else
                    w->unk11 = cnt / n * n;
            } else
                goto other;
            gMenuWork->unkC = gMenuWork->unk11;
            update_battle_medapart_icons();
            item_menu_update_swap_marker(&gSpriteEntries[0x54]);
            goto moved;
        }
    }

other:
    w2 = gMenuWork;
    if (w2->unk12) {
        item_menu_blink_swap_marker(gFrameCounter);
        if (KEYS_LO(gNewKeys) & 2) {
            gSpriteEntries[0x54].unk0 &= 0xBFFF;
            gMenuWork->unk12 = 0;
            goto moved;
        }
        if (!(KEYS_LO(gNewKeys) & 5))
            return;
        gSpriteEntries[0x54].unk0 &= 0xBFFF;
        gMenuWork->unk12 = 0;
        swap_inventory_items();
        unpack_item_inventory_to_buffer();
        update_battle_medapart_icons();
        goto moved;
    }
    if (w2->unk10 > 1 && (KEYS_LO(gNewKeys) & 4)) {
        w2->unk2 = 0;
        play_sound_effect(2);
        item_menu_start_swap();
    }
    w3 = gMenuWork;
    if (w3->unk12)
        return;
    if (KEYS_LO(gNewKeys) & 1) {
        if (w3->unk10 == 0)
            goto cancel;
        sel = &gUnk_03006D38;
        list = ITEM_LIST;
        sel->unk4 = list[w3->unkC].id;
        switch ((s32)item_get_use_result(list[w3->unkC].id)) {
        case 2:
        case 3:
        case 4:
            message_next();
            play_sound_effect(6);
            gSpriteEntries[0x51].unk0 &= 0xBFFF;
            gSpriteEntries[0x52].unk0 &= 0xBFFF;
            gGameSubState = 9;
            return;
        case 1:
            play_sound_effect(4);
            switch (ITEM_LIST[gMenuWork->unkC].id) {
            case 0:
                gMenuWork->unk0 = 0;
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
            gGameWork.unk84 = 0;
            gGameSubState = 0xD;
            return;
        case 0:
            play_sound_effect(6);
            return;
        }
    }
    if (KEYS_LO(gNewKeys) & 2) {
    cancel:
        play_sound_effect(5);
        palette_backup_from_hardware();
        gGameWork.unk84 = 0;
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

// Starts the SELECT reorder: shows the swap marker (sprite 0x54) on the cursor item and remembers it in unk13.
void item_menu_start_swap(void) {
    struct MenuWork **pw = &gMenuWork;
    item_menu_set_cursor_pos(&gSpriteEntries[0x54]);
    gSpriteEntries[0x54].unk0 |= 0x4000;
    gSpriteEntries[0x54].unk2++;
    gSpriteEntries[0x54].unk4++;
    (*pw)->unk12 = 1;
    (*pw)->unk13 = (*pw)->unkC;
}

void item_menu_close_message(void) {
    if (game_state_execute_handler_a())
        gGameSubState++;
}

void item_menu_fade_out_exit(void) {
    struct GameWork *b = &gGameWork;
    if (b->unk84 <= 8) {
        bg_palettes_blend_masked_now(0, b->unk84 * 4, 0x3FFF);
        obj_palettes_blend_masked_now(0, b->unk84 * 4, 0xFFFF);
        b->unk84++;
    } else {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFBFF;
        clear_battle_sprite_slot(0, 0x80);
        gGameMode = 0;
        gGameState = 1;
        gGameSubState = 0x10;
    }
}

// item_get_use_result 2-4: the item can't be used here (message 8 of gUnk_08485788).
void item_menu_show_cannot_use(void) {
    if (run_message(gUnk_08485788[8]))
        gGameSubState++;
}

void item_menu_wait_message_key(void) {
    if (*(u8 *)&gNewKeys & 3) {
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
    if (w->unk0 != 8) {
        REG_BLDY = ++w->unk0 * 2;
    } else {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFBFF;
        clear_battle_sprite_slot(0, 0x80);
        gMenuWork->unk6 = 1;
        gGameState = 10;
        gGameSubState = 0;
    }
}

void item_menu_close_use_message(void) {
    if (game_state_execute_handler_a())
        gGameSubState++;
}
