// Mode-2 state 12: the shop buy / sell list. shop_list_dispatch runs gUnk_08483E8C: list setup, cursor and
// cart (shop_purchase_menu_handler), the transaction, then shop_list_fade_out_exit starts a battle scene with the list
// id. The table continues into handlers in code_080628A8.c (0x08064C7C..).
#include "global.h"

static inline void *vram_at(u32 off) {
    return (void *)(0x06004000 + off);
}

void shop_list_dispatch(void) {
    gUnk_08483E8C[gGameSubState]();
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
    lz_decompress_dispatch(gUnk_08784DA4, (void *)0x06010000);
    gSpriteEntries[8].unk0 = 0x8400;
    gSpriteEntries[8].unk1C = 2;
    gSpriteEntries[8].unkA = 2;
    gSpriteEntries[8].unk6 = 6;
    for (i = 0; i < 2; i++) {
        gSpriteEntries[11 + i].unk0 = 0x8000;
        gSpriteEntries[11 + i].unk1C = 2;
        gSpriteEntries[11 + i].unkA = 2;
        gSpriteEntries[11 + i].unk6 = 5;
        gSpriteEntries[11 + i].unk2 = i * 24 + 0xD0;
        gSpriteEntries[11 + i].unk4 = gMenuWork->unk1A * 16 + 0x54;
    }
    gSpriteEntries[11].unk0 |= 0x1000;
    for (i = 0; i < 2; i++) {
        gSpriteEntries[0x68 + i].unk0 = 0x8400;
        gSpriteEntries[0x68 + i].unk1C = 2;
        gSpriteEntries[0x68 + i].unkA = 2;
        gSpriteEntries[0x68 + i].unk6 = 8;
        gSpriteEntries[0x68 + i].unk2 = 0x1C;
        gSpriteEntries[0x68 + i].unk4 = i ? 0x95 : 0x44;
    }
    gSpriteEntries[0x69].unk0 |= 0x2000;
    for (i = 0; i < 4; i++) {
        gSpriteEntries[0x6A + i].unk0 = 0x8400;
        gSpriteEntries[0x6A + i].unk1C = 2;
        gSpriteEntries[0x6A + i].unkA = 3;
        gSpriteEntries[0x6A + i].unk2 = 0x78;
        gSpriteEntries[0x6A + i].unk4 = i * 16 + 0x50;
    }
    for (i = 0; i < 4; i++) {
        gSpriteEntries[0x6E + i].unk0 = 0x8400;
        gSpriteEntries[0x6E + i].unk1C = 2;
        gSpriteEntries[0x6E + i].unkA = 3;
        gSpriteEntries[0x6E + i].unk6 = i + 0x1D;
        gSpriteEntries[0x6E + i].unk2 = 0x90;
        gSpriteEntries[0x6E + i].unk4 = i * 16 + 0x50;
    }
    REG_BLDALPHA = 0x10;
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    gSpriteEntries[8].unk2 = 8;
    gSpriteEntries[8].unk4 = gMenuWork->unk1A * 16 + 0x54;
    if (gMenuWork->unk5 == 1) {
        shop_build_sell_list();
    } else {
        struct ShopSellEntry *l;
        u32 *prices;
        const u8 *tbl;

        tbl = gShopStock;
        i = 0;
        l = (struct ShopSellEntry *)0x02040000;
        prices = (u32 *)0x02040004;
        for (; i < 4; i++) {
            const u8 *e = (const u8 *)(gShopId * 4 + i + (u32)tbl);

            if (*e != 0xFF && (*e != 0x20 || gMenuWork->unk19 == 3)) {
                l[i].id = *e;
                l[i].count = gMedapartInventory[l[i].id * 2 + gMenuWork->unk19 * 240];
                load_part_data(l[i].id, gMenuWork->unk19, &gGameWork.partAbility);
                l[i].unk3 = (&gGameWork.partAbility)[3];
                prices[i * 2] = (&gGameWork.partAbility)[0xB] * 100;
            } else {
                break;
            }
        }
        ((struct ShopSellEntry *)0x02040000)[i].count = 0;
        gMenuWork->unk20 = i;
    }
    for (i = 0; i < 4; i++) {
        if (gMenuWork->unk20 > i)
            load_battle_sprite_tiles(((struct ShopSellEntry *)0x02040000)[i].id, gMenuWork->unk19, i);
        else
            break;
    }
    gMenuWork->unk1C = 0;
    for (i = 0; i < gMenuWork->unk20; i++)
        gMenuWork->unk1C += ((u8 *)0x02023000)[i] * ((u32 *)0x02040004)[i * 2];
    if (gMenuWork->unk5)
        gMenuWork->unk1C /= 2;
    if (gMenuWork->unk1C > 99999)
        gMenuWork->unk1C = 99999;
    gGameSubState++;
}

void enable_obj_layer_and_load_palette(void) {
    REG_DISPCNT |= 0x1000;
    CpuFastSet(gUnk_0850DD58 + 0x30, (void *)0x0202F9A0, 8);
    CpuFastSet(gCursorArrowPalette, (void *)0x0202F840, 8);
    CpuFastSet(gUnk_084C69B8, (void *)0x0202F860, 8);
    CpuFastSet(gUnk_0850DD58 + 0xB0, (void *)0x0202F9C0, 8);
    CpuFastSet(gUnk_0850DD58 - 0x30, (void *)0x0202F9E0, 8);
    CpuFastSet(gUnk_0850DD58 - 0x30, (void *)0x0202F980, 8);
    CpuFastSet(gUnk_0850DEF8, (void *)0x0202F880, 0x40);
    CpuFastSet(gUnk_08798D2C, (void *)0x0202FA00, 0x80);
    gGameWork.unk84 = 0;
    render_battle_medapart_list(gMenuWork->unk5);
    if (gMenuWork->unk20 != 0) {
        u8 *buf = (u8 *)0x02023000;
        draw_number_tall(buf[buf[0x78]], 2, 0x1B, 10, 6, (REG_BG1CNT >> 8) & 0x1F);
        gSpriteEntries[8].unk0 |= 0x4000;
    }
    if (gMenuWork->unk20 > 1)
        draw_number_tall(((u8 *)0x02023000)[gUnk_02023078 + 1], 2, 0x1B, 12, 6, (REG_BG1CNT >> 8) & 0x1F);
    if (gMenuWork->unk20 > 2)
        draw_number_tall(((u8 *)0x02023000)[gUnk_02023078 + 2], 2, 0x1B, 14, 6, (REG_BG1CNT >> 8) & 0x1F);
    if (gMenuWork->unk20 > 3)
        draw_number_tall(((u8 *)0x02023000)[gUnk_02023078 + 3], 2, 0x1B, 16, 6, (REG_BG1CNT >> 8) & 0x1F);
    gGameSubState++;
}

void shop_list_fade_in(void) {
    struct GameWork *s = &gGameWork;
    u8 *n = &s->unk84;

    if (*n <= 8) {
        bg_palettes_blend_masked_now(0, 32 - *n * 4, 0xFFFE);
        obj_palettes_blend_masked_now(0, 32 - *n * 4, 0x7FFD);
        (*n)++;
    } else {
        update_battle_sprite_priority_flags();
        gMenuWork->unk2 = 0;
        gGameSubState++;
    }
}

#define CART gUnk_02023000
#define SHOP ((struct ShopSellEntry *)0x02040000)
#define PRICE ((u32 *)0x02040004)

static inline u32 cart_cost(s32 i) {
    return ((u8 *)0x02023000)[i] * PRICE[i * 2];
}

void shop_purchase_menu_handler(void) {
    u8 idx;
    s8 i;

    sprite_bob_y(8, gFrameCounter, 4);
    update_battle_sprite_priority_flags();
    if (KEYS_LO(gRepeatKeys) & 8) {
        if (gMenuWork->unk20 == 0)
            goto fail;
        play_sound_effect(4);
        gGameWork.unk84 = 0;
        gGameSubState = 9;
        return;
    }
    if (gMenuWork->unk5 == 0) {
        if (gFrameCounter & 8) {
            if (CART[gMenuWork->unk1A] != 0)
                gSpriteEntries[11].unk0 |= 0x4000;
            {
                u32 *m = &gPlayerRecord.money;
                u32 sum = CART[0];
                u32 *p = (u32 *)0x02040000;
                u8 k;
                u32 off;

                sum = sum * p[1] + CART[1] * p[3] + CART[2] * p[5] + CART[3] * p[7];
                k = gMenuWork->unk1A;
                off = k * 8;
                p++;
                sum += *(u32 *)((u8 *)p + off);
                if (*m >= sum && ((struct ShopSellEntry *)(p - 1))[k].count + CART[k] <= 0x62)
                    gSpriteEntries[12].unk0 |= 0x4000;
            }
        } else {
            gSpriteEntries[11].unk0 &= 0xBFFF;
            gSpriteEntries[12].unk0 &= 0xBFFF;
        }
    } else {
        if (gFrameCounter & 8) {
            struct ShopSellEntry *l = SHOP;

            idx = gMenuWork->unk1A + CART[0x78];
            if (CART[idx] != 0)
                gSpriteEntries[11].unk0 |= 0x4000;
            if (l[idx].count > CART[idx])
                gSpriteEntries[12].unk0 |= 0x4000;
        } else {
            gSpriteEntries[11].unk0 &= 0xBFFF;
            gSpriteEntries[12].unk0 &= 0xBFFF;
        }
    }

    if (gMenuWork->unk20 > 1) {
        if (KEYS_LO(gRepeatKeys) & 0x40) {
            if (gMenuWork->unk1A == 0) {
                if (gUnk_02023078 == 0)
                    goto cursor;
                gUnk_02023078--;
                goto scroll;
            }
            gMenuWork->unk1A--;
            play_sound_effect(2);
            goto cursor;
        } else if (KEYS_LO(gRepeatKeys) & 0x80) {
            if (gMenuWork->unk1A + gUnk_02023078 >= gMenuWork->unk20 - 1)
                goto cursor;
            if (gMenuWork->unk1A == 3) {
                gUnk_02023078++;
            scroll:
                render_battle_medapart_list(1);
                update_battle_sprite_priority_flags();
                goto changed;
            }
            if (gMenuWork->unk1A >= gMenuWork->unk20)
                goto cursor;
            gMenuWork->unk1A++;
            play_sound_effect(2);
            goto cursor;
        }
    }

    if (KEYS_LO(gRepeatKeys) & 0x10) {
        struct MenuWork *t = gMenuWork;
        u8 *buf = (u8 *)0x02023000;
        struct ShopSellEntry *l = SHOP;

        idx = t->unk1A + buf[0x78];
        if (t->unk5 == 0) {
            u32 *m = &gPlayerRecord.money;
            u32 total = buf[buf[0x78]] * PRICE[buf[0x78] * 2];

            total += cart_cost(buf[0x78] + 1);
            total += cart_cost(buf[0x78] + 2);
            total += cart_cost(buf[0x78] + 3);
            if (*m >= total + PRICE[idx * 2] && l[idx].count + buf[idx] <= 0x62) {
                buf[idx]++;
                goto changed;
            }
        } else if (l[idx].count > buf[idx]) {
            buf[idx]++;
            goto changed;
        }
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        idx = gMenuWork->unk1A + CART[0x78];
        if (CART[idx] != 0) {
            CART[idx]--;
            goto changed;
        }
    }
    if (KEYS_LO(gNewKeys) & 1) {
        if (gMenuWork->unk1C == 0) {
        fail:
            play_sound_effect(6);
            return;
        }
        play_sound_effect(4);
        for (i = 0; i <= 1; i++)
            gSpriteEntries[11 + i].unk0 &= 0xBFFF;
        open_choice_menu(1, 0x16, 7);
        text_window_init(1, 0, 0);
        gGameSubState = 6;
        return;
    }
    if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        clear_sprite_table_mask(0x61, 7);
        clear_sprite_table_mask(0xD, 0x34);
        clear_sprite_table_mask(0x45, 0x1C);
        gGameWork.unk84 = 0;
        gGameSubState++;
    }
    return;

cursor:
    gSpriteEntries[8].unk4 = gMenuWork->unk1A * 16 + 0x54;
    gSpriteEntries[11].unk4 = gMenuWork->unk1A * 16 + 0x54;
    gSpriteEntries[12].unk4 = gMenuWork->unk1A * 16 + 0x54;
    return;

changed:
    play_sound_effect(2);
    if (gMenuWork->unk20 != 0)
        draw_number_tall(CART[CART[0x78]], 2, 0x1B, 0xA, 6, (REG_BG1CNT >> 8) & 0x1F);
    if (gMenuWork->unk20 > 1)
        draw_number_tall(((u8 *)0x02023000)[gUnk_02023078 + 1], 2, 0x1B, 0xC, 6, (REG_BG1CNT >> 8) & 0x1F);
    if (gMenuWork->unk20 > 2)
        draw_number_tall(((u8 *)0x02023000)[gUnk_02023078 + 2], 2, 0x1B, 0xE, 6, (REG_BG1CNT >> 8) & 0x1F);
    if (gMenuWork->unk20 > 3)
        draw_number_tall(((u8 *)0x02023000)[gUnk_02023078 + 3], 2, 0x1B, 0x10, 6, (REG_BG1CNT >> 8) & 0x1F);
    gMenuWork->unk1C = 0;
    for (i = 0; i < 0x78; i++) {
        if (gMenuWork->unk5 == 0)
            gMenuWork->unk1C += CART[i] * PRICE[i * 2];
        else
            gMenuWork->unk1C += CART[i] * PRICE[i * 2] / 2;
    }
    if (gMenuWork->unk1C > 99999)
        gMenuWork->unk1C = 99999;
    clear_sprite_table_mask(0x61, 7);
    divide_by_10000(gGameWork.textBuf, gMenuWork->unk1C);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x61, 0x13, 5, 7, 0xC, 2, 0);
}

void transition_fade_to_battle(void) {
    struct GameWork *s = &gGameWork;
    u8 *n = &s->unk84;

    if (*n <= 8) {
        bg_palettes_blend_masked_now(0, *n * 4, 0xFFFE);
        obj_palettes_blend_masked_now(0, *n * 4, 0x7FFD);
        (*n)++;
    } else if (gMenuWork->unk48 != 0) {
        struct MenuWork *p = gMenuWork;
        u8 mode = p->unk19;
        struct ShopSellEntry *l = (struct ShopSellEntry *)0x02040000;

        init_battle_scene(mode, l[p->unk1A].id);
        gGameMode = 0;
    } else {
        s8 i;

        REG_DISPCNT &= 0xFDFF;
        for (i = 0; i < 2; i++)
            gSpriteEntries[11 + i].unk0 &= 0xBFFF;
        for (i = 0; i < 2; i++)
            gSpriteEntries[0x68 + i].unk0 &= 0xBFFF;
        for (i = 0; i < 4; i++)
            gSpriteEntries[0x6A + i].unk0 &= 0xBFFF;
        for (i = 0; i < 4; i++)
            gSpriteEntries[0x6E + i].unk0 &= 0xBFFF;
        gSpriteEntries[8].unk0 &= 0xBFFF;
        REG_BLDALPHA = 0x1000;
        REG_BG1CNT = 0x1E05;
        REG_BG2CNT = 0x1D06;
        gGameState = 0xB;
        gGameSubState = 1;
    }
}

void advance_substate_on_handler_complete_1c(void) {
    if (run_message(gUnk_08485788[7]))
        gGameSubState++;
}

void shop_complete_transaction(void) {
    s8 i;

    if (!poll_choice_menu())
        return;
    gGameWork.unk84 = 0;
    gGameWork.endModeStep = 0;
    if (gGameWork.unk2A == 0) {
        if (gMenuWork->unk5 == 0) {
            gPlayerRecord.money -= gMenuWork->unk1C;
            for (i = 0; i < 120; i++) {
                u8 *inv = gMedapartInventory;
                struct ShopSellEntry *l = (struct ShopSellEntry *)0x02040000;
                u8 *p = &inv[l[i].id * 2 + gMenuWork->unk19 * 240];
                *p += ((u8 *)0x02023000)[i];
            }
        } else {
            u32 m = gPlayerRecord.money + gMenuWork->unk1C;

            if (m <= 99998)
                gPlayerRecord.money = m;
            else
                gPlayerRecord.money = 99999;
            for (i = 0; i < 120; i++) {
                u8 *inv = gMedapartInventory;
                struct ShopSellEntry *l = (struct ShopSellEntry *)0x02040000;
                u8 *p = &inv[l[i].id * 2 + gMenuWork->unk19 * 240];
                *p -= ((u8 *)0x02023000)[i];
            }
        }
        clear_sprite_table_mask(0, 7);
        divide_by_10000(gGameWork.textBuf, gPlayerRecord.money);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0, 0x15, 1, 7, 0xF, 1, 0);
        gGameWork.unk84 = 0;
    }
    gGameSubState++;
}

void shop_list_confirm_choice(void) {
    if (game_state_execute_handler_a()) {
        if (gGameWork.unk2A == 0) {
            clear_sprite_table_mask(0x61, 7);
            clear_sprite_table_mask(0xD, 0x34);
            clear_sprite_table_mask(0x45, 0x1C);
            gGameSubState = 5;
        } else {
            gGameSubState = 4;
        }
    }
}

void shop_list_fade_out_exit(void) {
    struct GameWork *s = &gGameWork;
    u8 *n = &s->unk84;

    if (*n <= 8) {
        bg_palettes_blend_masked_now(0, *n * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, *n * 4, 0xFFFF);
        (*n)++;
    } else {
        struct MenuWork *p = gMenuWork;
        u8 mode = p->unk19;
        struct ShopSellEntry *l = (struct ShopSellEntry *)0x02040000;
        init_battle_scene(mode, l[p->unk1A + gUnk_02023078].id);
        gGameMode = 0;
    }
}
