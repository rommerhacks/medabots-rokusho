// Mode-2 state 12: the shop buy / sell list. shop_list_dispatch runs gShopListHandlers: list setup, cursor and
// cart (shop_purchase_menu_handler), the transaction, then shop_list_fade_out_exit starts a battle scene with the list
// id. The table continues into handlers in code_080628A8.c (0x08064C7C..).
#include "global.h"
#include "constants/sprites.h"

static inline void *vram_at(u32 off) {
    return (void *)(0x06004000 + off);
}

void shop_list_dispatch(void) {
    gShopListHandlers[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void shop_list_reset_scroll(void) {
    reset_bg_scroll();
    gGameSubState++;
}

void shop_list_init(void) {
    s8 i;

    REG_DISPCNT |= 0x200;
    REG_BG1CNT = 0x1B05;
    REG_BG2CNT = 0x1A06;
    lz_decompress_dispatch(gMenuObjTilesLz, (void *)0x06010000);
    gSpriteEntries[8].flags = SPRITE_FLAG_ENABLED | SPRITE_PRIORITY(1);
    gSpriteEntries[8].frame_table = 2;
    gSpriteEntries[8].palette = 2;
    gSpriteEntries[8].frame = 6;
    for (i = 0; i < 2; i++) {
        gSpriteEntries[11 + i].flags = SPRITE_FLAG_ENABLED;
        gSpriteEntries[11 + i].frame_table = 2;
        gSpriteEntries[11 + i].palette = 2;
        gSpriteEntries[11 + i].frame = 5;
        gSpriteEntries[11 + i].x = i * 24 + 0xD0;
        gSpriteEntries[11 + i].y = gMenuWork->list_cursor * 16 + 0x54;
    }
    gSpriteEntries[11].flags |= SPRITE_FLAG_HFLIP;
    for (i = 0; i < 2; i++) {
        gSpriteEntries[0x68 + i].flags = SPRITE_FLAG_ENABLED | SPRITE_PRIORITY(1);
        gSpriteEntries[0x68 + i].frame_table = 2;
        gSpriteEntries[0x68 + i].palette = 2;
        gSpriteEntries[0x68 + i].frame = 8;
        gSpriteEntries[0x68 + i].x = 0x1C;
        gSpriteEntries[0x68 + i].y = i ? 0x95 : 0x44;
    }
    gSpriteEntries[0x69].flags |= SPRITE_FLAG_VFLIP;
    for (i = 0; i < 4; i++) {
        gSpriteEntries[0x6A + i].flags = SPRITE_FLAG_ENABLED | SPRITE_PRIORITY(1);
        gSpriteEntries[0x6A + i].frame_table = 2;
        gSpriteEntries[0x6A + i].palette = 3;
        gSpriteEntries[0x6A + i].x = 0x78;
        gSpriteEntries[0x6A + i].y = i * 16 + 0x50;
    }
    for (i = 0; i < 4; i++) {
        gSpriteEntries[0x6E + i].flags = SPRITE_FLAG_ENABLED | SPRITE_PRIORITY(1);
        gSpriteEntries[0x6E + i].frame_table = 2;
        gSpriteEntries[0x6E + i].palette = 3;
        gSpriteEntries[0x6E + i].frame = i + 0x1D;
        gSpriteEntries[0x6E + i].x = 0x90;
        gSpriteEntries[0x6E + i].y = i * 16 + 0x50;
    }
    REG_BLDALPHA = 0x10;
    lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
    gSpriteEntries[8].x = 8;
    gSpriteEntries[8].y = gMenuWork->list_cursor * 16 + 0x54;
    if (gMenuWork->cursor == 1) {
        shop_build_sell_list();
    } else {
        struct ShopSellEntry *list;
        u32 *prices;
        const u8 *tbl;

        tbl = gShopStock;
        i = 0;
        list = (struct ShopSellEntry *)0x02040000;
        prices = (u32 *)0x02040004;
        for (; i < 4; i++) {
            const u8 *stock = (const u8 *)(gShopId * 4 + i + (u32)tbl);

            if (*stock != 0xFF && (*stock != 0x20 || gMenuWork->part_kind == 3)) {
                list[i].id = *stock;
                list[i].count = gMedapartInventory[list[i].id * 2 + gMenuWork->part_kind * 240];
                load_part_data(list[i].id, gMenuWork->part_kind, &gGameWork.partAbility);
                list[i].gender = (&gGameWork.partAbility)[3];
                prices[i * 2] = (&gGameWork.partAbility)[0xB] * 100;
            } else {
                break;
            }
        }
        ((struct ShopSellEntry *)0x02040000)[i].count = 0;
        gMenuWork->list_count = i;
    }
    for (i = 0; i < 4; i++) {
        if (gMenuWork->list_count > i)
            load_battle_sprite_tiles(((struct ShopSellEntry *)0x02040000)[i].id, gMenuWork->part_kind, i);
        else
            break;
    }
    gMenuWork->total = 0;
    for (i = 0; i < gMenuWork->list_count; i++)
        gMenuWork->total += ((u8 *)0x02023000)[i] * ((u32 *)0x02040004)[i * 2];
    if (gMenuWork->cursor)
        gMenuWork->total /= 2;
    if (gMenuWork->total > 99999)
        gMenuWork->total = 99999;
    gGameSubState++;
}

void enable_obj_layer_and_load_palette(void) {
    REG_DISPCNT |= 0x1000;
    CpuFastSet(gGradientPaletteOlive + 0x30, (void *)0x0202F9A0, 8);
    CpuFastSet(gCursorArrowPalette, (void *)0x0202F840, 8);
    CpuFastSet(gShopListObjPalette, (void *)0x0202F860, 8);
    CpuFastSet(gGradientPaletteOlive + 0xB0, (void *)0x0202F9C0, 8);
    CpuFastSet(gGradientPaletteOlive - 0x30, (void *)0x0202F9E0, 8);
    CpuFastSet(gGradientPaletteOlive - 0x30, (void *)0x0202F980, 8);
    CpuFastSet(gMenuObjPalettes, (void *)0x0202F880, 0x40);
    CpuFastSet(gShopListBgPalettes, (void *)0x0202FA00, 0x80);
    gGameWork.stepCounter = 0;
    render_battle_medapart_list(gMenuWork->cursor);
    if (gMenuWork->list_count != 0) {
        u8 *buf = (u8 *)0x02023000;
        draw_number_tall(buf[buf[0x78]], 2, 0x1B, 10, 6, BGCNT_SCREEN_BLOCK(REG_BG1CNT));
        gSpriteEntries[8].flags |= SPRITE_FLAG_VISIBLE;
    }
    if (gMenuWork->list_count > 1)
        draw_number_tall(((u8 *)0x02023000)[gListScrollTop + 1], 2, 0x1B, 12, 6, BGCNT_SCREEN_BLOCK(REG_BG1CNT));
    if (gMenuWork->list_count > 2)
        draw_number_tall(((u8 *)0x02023000)[gListScrollTop + 2], 2, 0x1B, 14, 6, BGCNT_SCREEN_BLOCK(REG_BG1CNT));
    if (gMenuWork->list_count > 3)
        draw_number_tall(((u8 *)0x02023000)[gListScrollTop + 3], 2, 0x1B, 16, 6, BGCNT_SCREEN_BLOCK(REG_BG1CNT));
    gGameSubState++;
}

void shop_list_fade_in(void) {
    struct GameWork *game = &gGameWork;
    u8 *n = &game->stepCounter;

    if (*n <= 8) {
        bg_palettes_blend_masked_now(0, 32 - *n * 4, 0xFFFE);
        obj_palettes_blend_masked_now(0, 32 - *n * 4, 0x7FFD);
        (*n)++;
    } else {
        update_battle_sprite_priority_flags();
        gMenuWork->timer = 0;
        gGameSubState++;
    }
}

#define CART gListWorkBuffer
#define SHOP ((struct ShopSellEntry *)0x02040000)
#define PRICE ((u32 *)0x02040004)

static inline u32 cart_cost(s32 i) {
    return ((u8 *)0x02023000)[i] * PRICE[i * 2];
}

void shop_purchase_menu_handler(void) {
    u8 idx;
    s8 i;

    sprite_bob_x(8, gFrameCounter, 4);
    update_battle_sprite_priority_flags();
    if (KEYS_LO(gRepeatKeys) & 8) {
        if (gMenuWork->list_count == 0)
            goto fail;
        play_sound_effect(4);
        gGameWork.stepCounter = 0;
        gGameSubState = 9;
        return;
    }
    if (gMenuWork->cursor == 0) {
        if (gFrameCounter & 8) {
            if (CART[gMenuWork->list_cursor] != 0)
                gSpriteEntries[11].flags |= SPRITE_FLAG_VISIBLE;
            {
                u32 *money = &gPlayerRecord.money;
                u32 sum = CART[0];
                u32 *list_words = (u32 *)0x02040000;
                u8 k;
                u32 off;

                sum = sum * list_words[1] + CART[1] * list_words[3] + CART[2] * list_words[5] + CART[3] * list_words[7];
                k = gMenuWork->list_cursor;
                off = k * 8;
                list_words++;
                sum += *(u32 *)((u8 *)list_words + off);
                if (*money >= sum && ((struct ShopSellEntry *)(list_words - 1))[k].count + CART[k] <= 0x62)
                    gSpriteEntries[12].flags |= SPRITE_FLAG_VISIBLE;
            }
        } else {
            gSpriteEntries[11].flags &= (u16)~SPRITE_FLAG_VISIBLE;
            gSpriteEntries[12].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        }
    } else {
        if (gFrameCounter & 8) {
            struct ShopSellEntry *list = SHOP;

            idx = gMenuWork->list_cursor + CART[0x78];
            if (CART[idx] != 0)
                gSpriteEntries[11].flags |= SPRITE_FLAG_VISIBLE;
            if (list[idx].count > CART[idx])
                gSpriteEntries[12].flags |= SPRITE_FLAG_VISIBLE;
        } else {
            gSpriteEntries[11].flags &= (u16)~SPRITE_FLAG_VISIBLE;
            gSpriteEntries[12].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        }
    }

    if (gMenuWork->list_count > 1) {
        if (KEYS_LO(gRepeatKeys) & 0x40) {
            if (gMenuWork->list_cursor == 0) {
                if (gListScrollTop == 0)
                    goto cursor;
                gListScrollTop--;
                goto scroll;
            }
            gMenuWork->list_cursor--;
            play_sound_effect(2);
            goto cursor;
        } else if (KEYS_LO(gRepeatKeys) & 0x80) {
            if (gMenuWork->list_cursor + gListScrollTop >= gMenuWork->list_count - 1)
                goto cursor;
            if (gMenuWork->list_cursor == 3) {
                gListScrollTop++;
            scroll:
                render_battle_medapart_list(1);
                update_battle_sprite_priority_flags();
                goto changed;
            }
            if (gMenuWork->list_cursor >= gMenuWork->list_count)
                goto cursor;
            gMenuWork->list_cursor++;
            play_sound_effect(2);
            goto cursor;
        }
    }

    if (KEYS_LO(gRepeatKeys) & 0x10) {
        struct MenuWork *menu = gMenuWork;
        u8 *buf = (u8 *)0x02023000;
        struct ShopSellEntry *list = SHOP;

        idx = menu->list_cursor + buf[0x78];
        if (menu->cursor == 0) {
            u32 *money = &gPlayerRecord.money;
            u32 total = buf[buf[0x78]] * PRICE[buf[0x78] * 2];

            total += cart_cost(buf[0x78] + 1);
            total += cart_cost(buf[0x78] + 2);
            total += cart_cost(buf[0x78] + 3);
            if (*money >= total + PRICE[idx * 2] && list[idx].count + buf[idx] <= 0x62) {
                buf[idx]++;
                goto changed;
            }
        } else if (list[idx].count > buf[idx]) {
            buf[idx]++;
            goto changed;
        }
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        idx = gMenuWork->list_cursor + CART[0x78];
        if (CART[idx] != 0) {
            CART[idx]--;
            goto changed;
        }
    }
    if (KEYS_LO(gNewKeys) & 1) {
        if (gMenuWork->total == 0) {
        fail:
            play_sound_effect(6);
            return;
        }
        play_sound_effect(4);
        for (i = 0; i <= 1; i++)
            gSpriteEntries[11 + i].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        open_choice_menu(1, 0x16, 7);
        text_window_init(1, 0, 0);
        gGameSubState = 6;
        return;
    }
    if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        disable_sprites(0x61, 7);
        disable_sprites(0xD, 0x34);
        disable_sprites(0x45, 0x1C);
        gGameWork.stepCounter = 0;
        gGameSubState++;
    }
    return;

cursor:
    gSpriteEntries[8].y = gMenuWork->list_cursor * 16 + 0x54;
    gSpriteEntries[11].y = gMenuWork->list_cursor * 16 + 0x54;
    gSpriteEntries[12].y = gMenuWork->list_cursor * 16 + 0x54;
    return;

changed:
    play_sound_effect(2);
    if (gMenuWork->list_count != 0)
        draw_number_tall(CART[CART[0x78]], 2, 0x1B, 0xA, 6, BGCNT_SCREEN_BLOCK(REG_BG1CNT));
    if (gMenuWork->list_count > 1)
        draw_number_tall(((u8 *)0x02023000)[gListScrollTop + 1], 2, 0x1B, 0xC, 6, BGCNT_SCREEN_BLOCK(REG_BG1CNT));
    if (gMenuWork->list_count > 2)
        draw_number_tall(((u8 *)0x02023000)[gListScrollTop + 2], 2, 0x1B, 0xE, 6, BGCNT_SCREEN_BLOCK(REG_BG1CNT));
    if (gMenuWork->list_count > 3)
        draw_number_tall(((u8 *)0x02023000)[gListScrollTop + 3], 2, 0x1B, 0x10, 6, BGCNT_SCREEN_BLOCK(REG_BG1CNT));
    gMenuWork->total = 0;
    for (i = 0; i < 0x78; i++) {
        if (gMenuWork->cursor == 0)
            gMenuWork->total += CART[i] * PRICE[i * 2];
        else
            gMenuWork->total += CART[i] * PRICE[i * 2] / 2;
    }
    if (gMenuWork->total > 99999)
        gMenuWork->total = 99999;
    disable_sprites(0x61, 7);
    divide_by_10000(gGameWork.textBuf, gMenuWork->total);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x61, 0x13, 5, 7, 0xC, 2, 0);
}

void transition_fade_to_battle(void) {
    struct GameWork *game = &gGameWork;
    u8 *n = &game->stepCounter;

    if (*n <= 8) {
        bg_palettes_blend_masked_now(0, *n * 4, 0xFFFE);
        obj_palettes_blend_masked_now(0, *n * 4, 0x7FFD);
        (*n)++;
    } else if (gMenuWork->counter != 0) {
        struct MenuWork *menu = gMenuWork;
        u8 mode = menu->part_kind;
        struct ShopSellEntry *list = (struct ShopSellEntry *)0x02040000;

        init_battle_scene(mode, list[menu->list_cursor].id);
        gGameMode = 0;
    } else {
        s8 i;

        REG_DISPCNT &= 0xFDFF;
        for (i = 0; i < 2; i++)
            gSpriteEntries[11 + i].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        for (i = 0; i < 2; i++)
            gSpriteEntries[0x68 + i].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        for (i = 0; i < 4; i++)
            gSpriteEntries[0x6A + i].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        for (i = 0; i < 4; i++)
            gSpriteEntries[0x6E + i].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        gSpriteEntries[8].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        REG_BLDALPHA = 0x1000;
        REG_BG1CNT = 0x1E05;
        REG_BG2CNT = 0x1D06;
        gGameState = 0xB;
        gGameSubState = 1;
    }
}

void advance_substate_on_handler_complete_1c(void) {
    if (run_message(gSystemMessages[7]))
        gGameSubState++;
}

void shop_complete_transaction(void) {
    s8 i;

    if (!poll_choice_menu())
        return;
    gGameWork.stepCounter = 0;
    gGameWork.endModeStep = 0;
    if (gGameWork.choiceCursor == 0) {
        if (gMenuWork->cursor == 0) {
            gPlayerRecord.money -= gMenuWork->total;
            for (i = 0; i < 120; i++) {
                u8 *inv = gMedapartInventory;
                struct ShopSellEntry *list = (struct ShopSellEntry *)0x02040000;
                u8 *count_ptr = &inv[list[i].id * 2 + gMenuWork->part_kind * 240];
                *count_ptr += ((u8 *)0x02023000)[i];
            }
        } else {
            u32 money = gPlayerRecord.money + gMenuWork->total;

            if (money <= 99998)
                gPlayerRecord.money = money;
            else
                gPlayerRecord.money = 99999;
            for (i = 0; i < 120; i++) {
                u8 *inv = gMedapartInventory;
                struct ShopSellEntry *list = (struct ShopSellEntry *)0x02040000;
                u8 *count_ptr = &inv[list[i].id * 2 + gMenuWork->part_kind * 240];
                *count_ptr -= ((u8 *)0x02023000)[i];
            }
        }
        disable_sprites(0, 7);
        divide_by_10000(gGameWork.textBuf, gPlayerRecord.money);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0, 0x15, 1, 7, 0xF, 1, 0);
        gGameWork.stepCounter = 0;
    }
    gGameSubState++;
}

void shop_list_confirm_choice(void) {
    if (game_state_execute_handler_a()) {
        if (gGameWork.choiceCursor == 0) {
            disable_sprites(0x61, 7);
            disable_sprites(0xD, 0x34);
            disable_sprites(0x45, 0x1C);
            gGameSubState = 5;
        } else {
            gGameSubState = 4;
        }
    }
}

void shop_list_fade_out_exit(void) {
    struct GameWork *game = &gGameWork;
    u8 *n = &game->stepCounter;

    if (*n <= 8) {
        bg_palettes_blend_masked_now(0, *n * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, *n * 4, 0xFFFF);
        (*n)++;
    } else {
        struct MenuWork *menu = gMenuWork;
        u8 mode = menu->part_kind;
        struct ShopSellEntry *list = (struct ShopSellEntry *)0x02040000;
        init_battle_scene(mode, list[menu->list_cursor + gListScrollTop].id);
        gGameMode = 0;
    }
}
