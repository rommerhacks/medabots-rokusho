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
    gUnk_03002C30[8].unk0 = 0x8400;
    gUnk_03002C30[8].unk1C = 2;
    gUnk_03002C30[8].unkA = 2;
    gUnk_03002C30[8].unk6 = 6;
    for (i = 0; i < 2; i++) {
        gUnk_03002C30[11 + i].unk0 = 0x8000;
        gUnk_03002C30[11 + i].unk1C = 2;
        gUnk_03002C30[11 + i].unkA = 2;
        gUnk_03002C30[11 + i].unk6 = 5;
        gUnk_03002C30[11 + i].unk2 = i * 24 + 0xD0;
        gUnk_03002C30[11 + i].unk4 = gUnk_03006F74->unk1A * 16 + 0x54;
    }
    gUnk_03002C30[11].unk0 |= 0x1000;
    for (i = 0; i < 2; i++) {
        gUnk_03002C30[0x68 + i].unk0 = 0x8400;
        gUnk_03002C30[0x68 + i].unk1C = 2;
        gUnk_03002C30[0x68 + i].unkA = 2;
        gUnk_03002C30[0x68 + i].unk6 = 8;
        gUnk_03002C30[0x68 + i].unk2 = 0x1C;
        gUnk_03002C30[0x68 + i].unk4 = i ? 0x95 : 0x44;
    }
    gUnk_03002C30[0x69].unk0 |= 0x2000;
    for (i = 0; i < 4; i++) {
        gUnk_03002C30[0x6A + i].unk0 = 0x8400;
        gUnk_03002C30[0x6A + i].unk1C = 2;
        gUnk_03002C30[0x6A + i].unkA = 3;
        gUnk_03002C30[0x6A + i].unk2 = 0x78;
        gUnk_03002C30[0x6A + i].unk4 = i * 16 + 0x50;
    }
    for (i = 0; i < 4; i++) {
        gUnk_03002C30[0x6E + i].unk0 = 0x8400;
        gUnk_03002C30[0x6E + i].unk1C = 2;
        gUnk_03002C30[0x6E + i].unkA = 3;
        gUnk_03002C30[0x6E + i].unk6 = i + 0x1D;
        gUnk_03002C30[0x6E + i].unk2 = 0x90;
        gUnk_03002C30[0x6E + i].unk4 = i * 16 + 0x50;
    }
    REG_BLDALPHA = 0x10;
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    gUnk_03002C30[8].unk2 = 8;
    gUnk_03002C30[8].unk4 = gUnk_03006F74->unk1A * 16 + 0x54;
    if (gUnk_03006F74->unk5 == 1) {
        shop_build_sell_list();
    } else {
        struct ShopSellEntry *l;
        u32 *prices;
        const u8 *tbl;

        tbl = gUnk_08483E50;
        i = 0;
        l = (struct ShopSellEntry *)0x02040000;
        prices = (u32 *)0x02040004;
        for (; i < 4; i++) {
            const u8 *e = (const u8 *)(gUnk_03002420 * 4 + i + (u32)tbl);

            if (*e != 0xFF && (*e != 0x20 || gUnk_03006F74->unk19 == 3)) {
                l[i].id = *e;
                l[i].count = gMedapartInventory[l[i].id * 2 + gUnk_03006F74->unk19 * 240];
                load_part_data(l[i].id, gUnk_03006F74->unk19, &gUnk_03000440.unkEE);
                l[i].unk3 = (&gUnk_03000440.unkEE)[3];
                prices[i * 2] = (&gUnk_03000440.unkEE)[0xB] * 100;
            } else {
                break;
            }
        }
        ((struct ShopSellEntry *)0x02040000)[i].count = 0;
        gUnk_03006F74->unk20 = i;
    }
    for (i = 0; i < 4; i++) {
        if (gUnk_03006F74->unk20 > i)
            load_battle_sprite_tiles(((struct ShopSellEntry *)0x02040000)[i].id, gUnk_03006F74->unk19, i);
        else
            break;
    }
    gUnk_03006F74->unk1C = 0;
    for (i = 0; i < gUnk_03006F74->unk20; i++)
        gUnk_03006F74->unk1C += ((u8 *)0x02023000)[i] * ((u32 *)0x02040004)[i * 2];
    if (gUnk_03006F74->unk5)
        gUnk_03006F74->unk1C /= 2;
    if (gUnk_03006F74->unk1C > 99999)
        gUnk_03006F74->unk1C = 99999;
    gGameSubState++;
}

void enable_obj_layer_and_load_palette(void) {
    REG_DISPCNT |= 0x1000;
    CpuFastSet(gUnk_0850DD58 + 0x30, (void *)0x0202F9A0, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x0202F840, 8);
    CpuFastSet(gUnk_084C69B8, (void *)0x0202F860, 8);
    CpuFastSet(gUnk_0850DD58 + 0xB0, (void *)0x0202F9C0, 8);
    CpuFastSet(gUnk_0850DD58 - 0x30, (void *)0x0202F9E0, 8);
    CpuFastSet(gUnk_0850DD58 - 0x30, (void *)0x0202F980, 8);
    CpuFastSet(gUnk_0850DEF8, (void *)0x0202F880, 0x40);
    CpuFastSet(gUnk_08798D2C, (void *)0x0202FA00, 0x80);
    gUnk_03000440.unk84 = 0;
    render_battle_medapart_list(gUnk_03006F74->unk5);
    if (gUnk_03006F74->unk20 != 0) {
        u8 *buf = (u8 *)0x02023000;
        draw_number_tall(buf[buf[0x78]], 2, 0x1B, 10, 6, (REG_BG1CNT >> 8) & 0x1F);
        gUnk_03002C30[8].unk0 |= 0x4000;
    }
    if (gUnk_03006F74->unk20 > 1)
        draw_number_tall(((u8 *)0x02023000)[gUnk_02023078 + 1], 2, 0x1B, 12, 6, (REG_BG1CNT >> 8) & 0x1F);
    if (gUnk_03006F74->unk20 > 2)
        draw_number_tall(((u8 *)0x02023000)[gUnk_02023078 + 2], 2, 0x1B, 14, 6, (REG_BG1CNT >> 8) & 0x1F);
    if (gUnk_03006F74->unk20 > 3)
        draw_number_tall(((u8 *)0x02023000)[gUnk_02023078 + 3], 2, 0x1B, 16, 6, (REG_BG1CNT >> 8) & 0x1F);
    gGameSubState++;
}

void shop_list_fade_in(void) {
    struct Unk_03000440 *s = &gUnk_03000440;
    u8 *n = &s->unk84;

    if (*n <= 8) {
        blend_obj_palettes_to_color_0803F684(0, 32 - *n * 4, 0xFFFE);
        blend_obj_palettes_to_color_0803F998(0, 32 - *n * 4, 0x7FFD);
        (*n)++;
    } else {
        update_battle_sprite_priority_flags();
        gUnk_03006F74->unk2 = 0;
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
        if (gUnk_03006F74->unk20 == 0)
            goto fail;
        play_sound_effect(4);
        gUnk_03000440.unk84 = 0;
        gGameSubState = 9;
        return;
    }
    if (gUnk_03006F74->unk5 == 0) {
        if (gFrameCounter & 8) {
            if (CART[gUnk_03006F74->unk1A] != 0)
                gUnk_03002C30[11].unk0 |= 0x4000;
            {
                u32 *m = &gUnk_03002B70.money;
                u32 sum = CART[0];
                u32 *p = (u32 *)0x02040000;
                u8 k;
                u32 off;

                sum = sum * p[1] + CART[1] * p[3] + CART[2] * p[5] + CART[3] * p[7];
                k = gUnk_03006F74->unk1A;
                off = k * 8;
                p++;
                sum += *(u32 *)((u8 *)p + off);
                if (*m >= sum && ((struct ShopSellEntry *)(p - 1))[k].count + CART[k] <= 0x62)
                    gUnk_03002C30[12].unk0 |= 0x4000;
            }
        } else {
            gUnk_03002C30[11].unk0 &= 0xBFFF;
            gUnk_03002C30[12].unk0 &= 0xBFFF;
        }
    } else {
        if (gFrameCounter & 8) {
            struct ShopSellEntry *l = SHOP;

            idx = gUnk_03006F74->unk1A + CART[0x78];
            if (CART[idx] != 0)
                gUnk_03002C30[11].unk0 |= 0x4000;
            if (l[idx].count > CART[idx])
                gUnk_03002C30[12].unk0 |= 0x4000;
        } else {
            gUnk_03002C30[11].unk0 &= 0xBFFF;
            gUnk_03002C30[12].unk0 &= 0xBFFF;
        }
    }

    if (gUnk_03006F74->unk20 > 1) {
        if (KEYS_LO(gRepeatKeys) & 0x40) {
            if (gUnk_03006F74->unk1A == 0) {
                if (gUnk_02023078 == 0)
                    goto cursor;
                gUnk_02023078--;
                goto scroll;
            }
            gUnk_03006F74->unk1A--;
            play_sound_effect(2);
            goto cursor;
        } else if (KEYS_LO(gRepeatKeys) & 0x80) {
            if (gUnk_03006F74->unk1A + gUnk_02023078 >= gUnk_03006F74->unk20 - 1)
                goto cursor;
            if (gUnk_03006F74->unk1A == 3) {
                gUnk_02023078++;
            scroll:
                render_battle_medapart_list(1);
                update_battle_sprite_priority_flags();
                goto changed;
            }
            if (gUnk_03006F74->unk1A >= gUnk_03006F74->unk20)
                goto cursor;
            gUnk_03006F74->unk1A++;
            play_sound_effect(2);
            goto cursor;
        }
    }

    if (KEYS_LO(gRepeatKeys) & 0x10) {
        struct Unk_03006F74 *t = gUnk_03006F74;
        u8 *buf = (u8 *)0x02023000;
        struct ShopSellEntry *l = SHOP;

        idx = t->unk1A + buf[0x78];
        if (t->unk5 == 0) {
            u32 *m = &gUnk_03002B70.money;
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
        idx = gUnk_03006F74->unk1A + CART[0x78];
        if (CART[idx] != 0) {
            CART[idx]--;
            goto changed;
        }
    }
    if (KEYS_LO(gNewKeys) & 1) {
        if (gUnk_03006F74->unk1C == 0) {
        fail:
            play_sound_effect(6);
            return;
        }
        play_sound_effect(4);
        for (i = 0; i <= 1; i++)
            gUnk_03002C30[11 + i].unk0 &= 0xBFFF;
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
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
    return;

cursor:
    gUnk_03002C30[8].unk4 = gUnk_03006F74->unk1A * 16 + 0x54;
    gUnk_03002C30[11].unk4 = gUnk_03006F74->unk1A * 16 + 0x54;
    gUnk_03002C30[12].unk4 = gUnk_03006F74->unk1A * 16 + 0x54;
    return;

changed:
    play_sound_effect(2);
    if (gUnk_03006F74->unk20 != 0)
        draw_number_tall(CART[CART[0x78]], 2, 0x1B, 0xA, 6, (REG_BG1CNT >> 8) & 0x1F);
    if (gUnk_03006F74->unk20 > 1)
        draw_number_tall(((u8 *)0x02023000)[gUnk_02023078 + 1], 2, 0x1B, 0xC, 6, (REG_BG1CNT >> 8) & 0x1F);
    if (gUnk_03006F74->unk20 > 2)
        draw_number_tall(((u8 *)0x02023000)[gUnk_02023078 + 2], 2, 0x1B, 0xE, 6, (REG_BG1CNT >> 8) & 0x1F);
    if (gUnk_03006F74->unk20 > 3)
        draw_number_tall(((u8 *)0x02023000)[gUnk_02023078 + 3], 2, 0x1B, 0x10, 6, (REG_BG1CNT >> 8) & 0x1F);
    gUnk_03006F74->unk1C = 0;
    for (i = 0; i < 0x78; i++) {
        if (gUnk_03006F74->unk5 == 0)
            gUnk_03006F74->unk1C += CART[i] * PRICE[i * 2];
        else
            gUnk_03006F74->unk1C += CART[i] * PRICE[i * 2] / 2;
    }
    if (gUnk_03006F74->unk1C > 99999)
        gUnk_03006F74->unk1C = 99999;
    clear_sprite_table_mask(0x61, 7);
    divide_by_10000(gUnk_03000440.unk9E, gUnk_03006F74->unk1C);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x61, 0x13, 5, 7, 0xC, 2, 0);
}

void transition_fade_to_battle(void) {
    struct Unk_03000440 *s = &gUnk_03000440;
    u8 *n = &s->unk84;

    if (*n <= 8) {
        blend_obj_palettes_to_color_0803F684(0, *n * 4, 0xFFFE);
        blend_obj_palettes_to_color_0803F998(0, *n * 4, 0x7FFD);
        (*n)++;
    } else if (gUnk_03006F74->unk48 != 0) {
        struct Unk_03006F74 *p = gUnk_03006F74;
        u8 mode = p->unk19;
        struct ShopSellEntry *l = (struct ShopSellEntry *)0x02040000;

        init_battle_scene(mode, l[p->unk1A].id);
        gGameMode = 0;
    } else {
        s8 i;

        REG_DISPCNT &= 0xFDFF;
        for (i = 0; i < 2; i++)
            gUnk_03002C30[11 + i].unk0 &= 0xBFFF;
        for (i = 0; i < 2; i++)
            gUnk_03002C30[0x68 + i].unk0 &= 0xBFFF;
        for (i = 0; i < 4; i++)
            gUnk_03002C30[0x6A + i].unk0 &= 0xBFFF;
        for (i = 0; i < 4; i++)
            gUnk_03002C30[0x6E + i].unk0 &= 0xBFFF;
        gUnk_03002C30[8].unk0 &= 0xBFFF;
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
    gUnk_03000440.unk84 = 0;
    gUnk_03000440.unk1B = 0;
    if (gUnk_03000440.unk2A == 0) {
        if (gUnk_03006F74->unk5 == 0) {
            gUnk_03002B70.money -= gUnk_03006F74->unk1C;
            for (i = 0; i < 120; i++) {
                u8 *inv = gMedapartInventory;
                struct ShopSellEntry *l = (struct ShopSellEntry *)0x02040000;
                u8 *p = &inv[l[i].id * 2 + gUnk_03006F74->unk19 * 240];
                *p += ((u8 *)0x02023000)[i];
            }
        } else {
            u32 m = gUnk_03002B70.money + gUnk_03006F74->unk1C;

            if (m <= 99998)
                gUnk_03002B70.money = m;
            else
                gUnk_03002B70.money = 99999;
            for (i = 0; i < 120; i++) {
                u8 *inv = gMedapartInventory;
                struct ShopSellEntry *l = (struct ShopSellEntry *)0x02040000;
                u8 *p = &inv[l[i].id * 2 + gUnk_03006F74->unk19 * 240];
                *p -= ((u8 *)0x02023000)[i];
            }
        }
        clear_sprite_table_mask(0, 7);
        divide_by_10000(gUnk_03000440.unk9E, gUnk_03002B70.money);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0, 0x15, 1, 7, 0xF, 1, 0);
        gUnk_03000440.unk84 = 0;
    }
    gGameSubState++;
}

void shop_list_confirm_choice(void) {
    if (game_state_execute_handler_a()) {
        if (gUnk_03000440.unk2A == 0) {
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
    struct Unk_03000440 *s = &gUnk_03000440;
    u8 *n = &s->unk84;

    if (*n <= 8) {
        blend_obj_palettes_to_color_0803F684(0, *n * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, *n * 4, 0xFFFF);
        (*n)++;
    } else {
        struct Unk_03006F74 *p = gUnk_03006F74;
        u8 mode = p->unk19;
        struct ShopSellEntry *l = (struct ShopSellEntry *)0x02040000;
        init_battle_scene(mode, l[p->unk1A + gUnk_02023078].id);
        gGameMode = 0;
    }
}
