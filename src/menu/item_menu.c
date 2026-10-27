// Mode-2 state 4: the item menu opened from the field menu (item_menu_update runs its gUnk_08483B78
// sub-states: load graphics, init, fade in, item descriptions, list input, swap / use, fade out). Lists are
// drawn by menu/item_list.c; uses text/ messages and engine/ sprites.
#include "global.h"

void item_menu_update(void) {
    gItemMenuStates[gGameSubState]();
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

static void sub_0805CA28(u32 a) {
    struct Unk_03006F74 *w = gUnk_03006F74;
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

void sub_0805CA94(void) {
    u32 zero = 0;
    CpuFastSet(&zero, gUnk_03006F74, 0x01000100);
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
    gUnk_03006F74->unk36 = (size >> 5) - 1;
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
    struct Unk_03006F74 *w;

    gUnk_03006F74->unk6 = 0;
    gUnk_03006F74->unkC = 0;
    gUnk_03006F74->unk11 = 0;
    unpack_item_inventory_to_buffer();
    update_battle_medapart_icons();
    if (gUnk_03006F74->unk10) {
        gSpriteEntries[0x53].unk0 |= 0x4000;
        item_menu_set_cursor_pos(&gSpriteEntries[0x53]);
    }
    w = gUnk_03006F74;
    if ((w->unk10 - 1) / 5) {
        gSpriteEntries[0x51].unk0 |= 0x4000;
        gSpriteEntries[0x52].unk0 |= 0x4000;
    }
    w->unk12 = 0;
    CpuFastSet(gUnk_0850DCF8, gPaletteBackup, 0x80);
    CpuFastSet(gUnk_084E2E58, gPaletteBackup, 8);
    CpuFastSet(gUnk_080AF7C0, (void *)0x0202F9C0, 8);
    CpuFastSet(gUnk_0878AE78, gPaletteBackupBg, 0x80);
    zero = 0;
    CpuFastSet(&zero, (void *)(PLTT + 0x1A0), 0x01000008);
    gUnk_03000440.unk84 = 0;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gGameSubState++;
}

void item_menu_fade_in(void) {
    struct Unk_03000440 *b = &gUnk_03000440;
    if (b->unk84 <= 8) {
        if (gUnk_03006F74->unk6 == 0)
            bg_palettes_blend_masked_now(0, 0x20 - b->unk84 * 4, 0x3FFF);
        else
            bg_palettes_blend_masked_now(0, 0x20 - b->unk84 * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, 0x20 - gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else {
        text_window_init(1, 2, 0);
        gGameSubState++;
    }
}

void item_menu_show_description(void) {
    u8 id;
    struct Unk_03006F74 *w;
    sub_0805CA28(gFrameCounter);
    sprite_bob_y(0x53, gFrameCounter, 0x54);
    w = gUnk_03006F74;
    if (w->unk10) {
        struct ItemListEntry *l = (struct ItemListEntry *)0x02040000;
        id = l[w->unkC].id;
    } else
        id = 0x3F;
    if (run_message(gItemDescriptions[id]))
        gGameSubState++;
}

#define ITEM_LIST ((struct ItemListEntry *)0x02040000)

// guess: item_menu_handle_input (5 items per page; D-pad moves / pages, SELECT reorders, A uses, B closes)
void sub_0805CE4C(void) {
    struct Unk_03006F74 *w;
    struct Unk_03006F74 *w2;
    struct Unk_03006F74 *w3;
    struct ItemListEntry *list;
    struct Unk_03006D38 *sel;
    u8 n = 5;
    u8 cnt;

    sprite_bob_y(0x53, gFrameCounter, 0x54);
    if ((gUnk_03006F74->unk10 - 1) / 5) {
        if ((gFrameCounter >> 4) & 1) {
            gSpriteEntries[0x51].unk0 |= 0x4000;
            gSpriteEntries[0x52].unk0 |= 0x4000;
        } else {
            gSpriteEntries[0x51].unk0 &= 0xBFFF;
            gSpriteEntries[0x52].unk0 &= 0xBFFF;
        }
    }

    w = gUnk_03006F74;
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
            gUnk_03006F74->unkC = gUnk_03006F74->unk11;
            update_battle_medapart_icons();
            sub_0805B470(&gSpriteEntries[0x54]);
            goto moved;
        }
    }

other:
    w2 = gUnk_03006F74;
    if (w2->unk12) {
        sub_0805CA28(gFrameCounter);
        if (KEYS_LO(gNewKeys) & 2) {
            gSpriteEntries[0x54].unk0 &= 0xBFFF;
            gUnk_03006F74->unk12 = 0;
            goto moved;
        }
        if (!(KEYS_LO(gNewKeys) & 5))
            return;
        gSpriteEntries[0x54].unk0 &= 0xBFFF;
        gUnk_03006F74->unk12 = 0;
        swap_inventory_items();
        unpack_item_inventory_to_buffer();
        update_battle_medapart_icons();
        goto moved;
    }
    if (w2->unk10 > 1 && (KEYS_LO(gNewKeys) & 4)) {
        w2->unk2 = 0;
        play_sound_effect(2);
        init_fade_sprite_and_start_fade();
    }
    w3 = gUnk_03006F74;
    if (w3->unk12)
        return;
    if (KEYS_LO(gNewKeys) & 1) {
        if (w3->unk10 == 0)
            goto cancel;
        sel = &gUnk_03006D38;
        list = ITEM_LIST;
        sel->unk4 = list[w3->unkC].id;
        switch ((s32)sub_08048914(list[w3->unkC].id)) {
        case 2:
        case 3:
        case 4:
            sub_0803FB0C();
            play_sound_effect(6);
            gSpriteEntries[0x51].unk0 &= 0xBFFF;
            gSpriteEntries[0x52].unk0 &= 0xBFFF;
            gGameSubState = 9;
            return;
        case 1:
            play_sound_effect(4);
            switch (ITEM_LIST[gUnk_03006F74->unkC].id) {
            case 0:
                gUnk_03006F74->unk0 = 0;
                gGameSubState = 0xB;
                return;
            case 1:
                gUnk_030057E0.unkC5C = 3;
                break;
            case 5:
                gUnk_030057E0.unkC5C = 4;
                break;
            case 12:
                gUnk_030057E0.unkC5C = 5;
                break;
            case 13:
                gUnk_030057E0.unkC5C = 8;
                break;
            case 19:
                gUnk_030057E0.unkC5C = 6;
                break;
            case 39:
                gUnk_030057E0.unkC5C = 7;
                break;
            case 40:
                gUnk_030057E0.unkC5C = 0xD;
                break;
            default:
                dispatch_by_index_0476e8(4);
                return;
            }
            gUnk_03000440.unk84 = 0;
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
        gUnk_03000440.unk84 = 0;
        gGameSubState = 7;
    }
    return;

moved:
    play_sound_effect(2);
    sub_0803FB0C();
    item_menu_set_cursor_pos(&gSpriteEntries[0x53]);
    gGameSubState = 4;
    sub_0805CA28(gFrameCounter);
}

// guess: starts the SELECT reorder: shows the second cursor (sprite 0x54) on the cursor item
void init_fade_sprite_and_start_fade(void) {
    struct Unk_03006F74 **pw = &gUnk_03006F74;
    item_menu_set_cursor_pos(&gSpriteEntries[0x54]);
    gSpriteEntries[0x54].unk0 |= 0x4000;
    gSpriteEntries[0x54].unk2++;
    gSpriteEntries[0x54].unk4++;
    (*pw)->unk12 = 1;
    (*pw)->unk13 = (*pw)->unkC;
}

void sub_0805D378(void) {
    if (game_state_execute_handler_a())
        gGameSubState++;
}

void sub_0805D394(void) {
    struct Unk_03000440 *b = &gUnk_03000440;
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

void sub_0805D418(void) {
    if (run_message(gUnk_08485788[8]))
        gGameSubState++;
}

void check_ab_press_play_confirm_sound(void) {
    if (*(u8 *)&gNewKeys & 3) {
        play_sound_effect(2);
        sub_0803FB0C();
        gGameSubState = 4;
    }
}

void sub_0805D468(void) {
    REG_BLDCNT = 0x2FF;
    gGameSubState++;
}

void sub_0805D488(void) {
    struct Unk_03006F74 *w = gUnk_03006F74;
    if (w->unk0 != 8) {
        REG_BLDY = ++w->unk0 * 2;
    } else {
        REG_DISPCNT &= 0xFDFF;
        REG_DISPCNT &= 0xFBFF;
        clear_battle_sprite_slot(0, 0x80);
        gUnk_03006F74->unk6 = 1;
        gGameState = 10;
        gGameSubState = 0;
    }
}

void sub_0805D4F0(void) {
    if (game_state_execute_handler_a())
        gGameSubState++;
}
