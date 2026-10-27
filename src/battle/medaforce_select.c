// Tilemap window helpers for the battle menus (save / restore a BG0 / BG1 region, scroll a window), then the
// Medaforce select screen (names unlocked by Medal level, skill type, cost bar; guesses, see below).
// Called from battle/robattle.

#include "global.h"

static void sub_08017734(u32 a);

void save_restore_bg1_tilemap_region(void) {
    if (gUnk_03000440.unk84 < 12) {
        read_vram_tilemap_rect(0xD, 7, 0x11, 0xD, REG_BG1CNT, gUnk_02021000);
        write_vram_tilemap_rect(0xD, 7, 0x12, 0xD, REG_BG1CNT, gUnk_02021000);
    }
}

void save_restore_bg0_tilemap_region(void) {
    if (gUnk_03000440.unk84 < 4) {
        read_vram_tilemap_rect(0xC, 5, 9, 0xF, REG_BG0CNT, gUnk_02020800);
        write_vram_tilemap_rect(0xC, 5, 9, 0x10, REG_BG0CNT, gUnk_02020800);
    }
}

void draw_partial_bg1_column(void) {
    if (gUnk_03000440.unk84 <= 4)
        write_vram_tilemap_rect(6, 5, 0xC, 0x13 - gUnk_03000440.unk84, REG_BG1CNT, gUnk_02020800);
}

void scroll_tilemap_window(void) {
    if (gUnk_03000440.unk84 <= 9) {
        read_vram_tilemap_rect(gUnk_03000440.unk84 + 1, 4, 0x14, 0x15, REG_BG1CNT, gUnk_02021000);
        write_vram_tilemap_rect(gUnk_03000440.unk84 + 1, 4, 0x1D - gUnk_03000440.unk84, 0x10, REG_BG1CNT,
                                gUnk_02021000);
    }
}

void sub_08016FB4(void) {
    u32 i;
    for (i = 0; i < 6; i++) {
        gSpriteEntries[i].unk9 += 8;
        gSpriteEntries[i].unk8 += 8;
        if (gSpriteEntries[i].unk9 > 0x40 - (0x90 - gSpriteEntries[i].unk4) / 2) {
            gSpriteEntries[i].unk9 = 0x40 - (0x90 - gSpriteEntries[i].unk4) / 2;
            gSpriteEntries[i].unk8 = 0x40 - (0x90 - gSpriteEntries[i].unk4) / 2;
        }
    }
}

void sub_08017004(void) {
    set_tilemap_and_decompress_bg(9, 0x15, gUnk_084888E4, REG_BG0CNT, 0x2A0);
    set_tilemap_and_decompress_bg(0x12, 0x15, gUnk_08488920, REG_BG1CNT, 0x2B8);
}

void sub_08017048(void) {
    if (gUnk_03000440.unk84 < 4)
        write_vram_tilemap_rect(0xC, 4, 9, 0x13 - gUnk_03000440.unk84, REG_BG0CNT, gUnk_02020800);
}

void sub_08017084(void) {
    if (gUnk_03000440.unk84 < 12) {
        read_vram_tilemap_rect(gUnk_03000440.unk84 + 1, 4, 0x12, 0x15, REG_BG1CNT, gUnk_02021000);
        write_vram_tilemap_rect(gUnk_03000440.unk84 + 1, 4, 0x1D - gUnk_03000440.unk84, 0xD, REG_BG1CNT, gUnk_02021000);
    }
}

void sub_080170D4(void) {
    u32 v = gUnk_03000590[gUnk_03001800.unk80].unkDD;
    if (v <= 3)
        v = 0;
    else
        v -= 5;
    gUnk_03001800.unk82 = v;
}

void sub_08017104(void) {
    gSpriteEntries[0].unk0 = 0xC404;
    gSpriteEntries[0].unk1C = 0;
    gSpriteEntries[0].unk2 = 0x78;
    gSpriteEntries[0].unk4 = 0x78;
    gSpriteEntries[0].unkA = 0xA;
    gSpriteEntries[0].unkB = 0xC0;
    gSpriteEntries[0].unk6 = 0x61A;
}

void sub_08017130(u32 a) {
    gSpriteEntries[1].unk0 = 0xC404;
    gSpriteEntries[1].unk1C = 0;
    gSpriteEntries[1].unk2 = 0x78;
    gSpriteEntries[1].unk4 = 0x84;
    gSpriteEntries[1].unkA = 0xA;
    gSpriteEntries[1].unkB = 0xC0;
    gSpriteEntries[1].unk6 = a * 4 + 0x61E;
}

void sub_08017178(u32 a) {
    gSpriteEntries[2].unk0 = 0xC404;
    gSpriteEntries[2].unk1C = 0;
    gSpriteEntries[2].unk2 = 0x78;
    gSpriteEntries[2].unk4 = 0x6C;
    gSpriteEntries[2].unkA = 0xA;
    gSpriteEntries[2].unkB = 0xC0;
    gSpriteEntries[2].unk6 = a * 4 + 0x61B;
}

void sub_080171C0(u32 a) {
    gSpriteEntries[3].unk0 = 0xC404;
    gSpriteEntries[3].unk1C = 0;
    gSpriteEntries[3].unk2 = 0x6C;
    gSpriteEntries[3].unk4 = 0x78;
    gSpriteEntries[3].unkA = 0xA;
    gSpriteEntries[3].unkB = 0xC0;
    gSpriteEntries[3].unk6 = a * 4 + 0x61C;
}

void sub_08017208(u32 a) {
    gSpriteEntries[4].unk0 = 0xC404;
    gSpriteEntries[4].unk1C = 0;
    gSpriteEntries[4].unk2 = 0x84;
    gSpriteEntries[4].unk4 = 0x78;
    gSpriteEntries[4].unkA = 0xA;
    gSpriteEntries[4].unkB = 0xC0;
    gSpriteEntries[4].unk6 = a * 4 + 0x61D;
}

// guess: Medaforce select names (cases 1-3 open at Medal level 10/30/60), same layout as the part select
void sub_08017268(void) {
    clear_sprite_table_mask(0x14, 16);
    switch (gUnk_03001800.unk82) {
    case 0:
        memcpy_bytes_08041D04(gUnk_083C4A10[3], gUnk_03000440.unk9E, 14);
        break;
    case 1:
        if (gUnk_03000590[gUnk_03001800.unk80].medal.unk5 > 9) {
            memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000590[gUnk_03001800.unk80].medal.unk1 * 3,
                                  &gUnk_03000440.unkEE, 3);
            memcpy_bytes_0803F63C((const void *)gUnk_083B7338[gUnk_03000440.unkEE], gUnk_03000440.unk9E, 17);
        } else
            fill_text_blank(gUnk_03000440.unk9E, 13);
        break;
    case 2:
        if (gUnk_03000590[gUnk_03001800.unk80].medal.unk5 > 29) {
            memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000590[gUnk_03001800.unk80].medal.unk1 * 3,
                                  &gUnk_03000440.unkEE, 3);
            memcpy_bytes_0803F63C((const void *)gUnk_083B7338[gUnk_03000440.unkEF], gUnk_03000440.unk9E, 17);
        } else
            fill_text_blank(gUnk_03000440.unk9E, 13);
        break;
    case 3:
        if (gUnk_03000590[gUnk_03001800.unk80].medal.unk5 > 59) {
            memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000590[gUnk_03001800.unk80].medal.unk1 * 3,
                                  &gUnk_03000440.unkEE, 3);
            memcpy_bytes_0803F63C((const void *)gUnk_083B7338[gUnk_03000440.unkF0], gUnk_03000440.unk9E, 17);
        } else
            fill_text_blank(gUnk_03000440.unk9E, 13);
        break;
    }
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x14, 10, 0x11, 10, 13, 0, 0);
}

// guess: Medaforce select (sub-states 0x10-0x12 path, not reached at runtime): draws the selected slot's
// skill type, or gUnk_083C4A10[5] (level too low) / [1] (Medaforce blocked) / [4] (gauge not full); blinks when a != 0
void sub_080173B4(u32 a) {
    u8 err = 0;
    u8 blank = 0;

    clear_sprite_table_mask(0x24, 13);
    switch (gUnk_03001800.unk82) {
    case 0:
        fill_text_blank(gUnk_03000440.unk9E, 13);
        blank = 1;
        break;
    case 1:

        if (gUnk_03000590[gUnk_03001800.unk80].medal.unk5 > 9) {
            if (gUnk_03001800.unk58 == 0) {
                if (gUnk_03000590[gUnk_03001800.unk80].unkC1 == 0x50) {
                    memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000590[gUnk_03001800.unk80].medal.unk1 * 3,
                                          &gUnk_03000440.unkEE, 3);
                    memcpy_bytes_08041D04(gUnk_083B7CD4 + gUnk_03000440.unkEE * 6, gUnk_03000440.unk10E, 6);
                    memcpy_bytes_0803F63C((const void *)gUnk_083B6EC8[gUnk_03000440.unk10E[1]], gUnk_03000440.unk9E,
                                          14);
                    sub_08017734(0);
                } else {
                    memcpy_bytes_08041D04(gUnk_083C4A10[4], gUnk_03000440.unk9E, 14);
                    err = 1;
                }
            } else {
                memcpy_bytes_08041D04(gUnk_083C4A10[1], gUnk_03000440.unk9E, 14);
                err = 1;
            }
        } else {
            memcpy_bytes_08041D04(gUnk_083C4A10[5], gUnk_03000440.unk9E, 14);
            err = 1;
        }
        break;
    case 2:

        if (gUnk_03000590[gUnk_03001800.unk80].medal.unk5 > 29) {
            if (gUnk_03001800.unk58 == 0) {
                if (gUnk_03000590[gUnk_03001800.unk80].unkC1 == 0x50) {
                    memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000590[gUnk_03001800.unk80].medal.unk1 * 3,
                                          &gUnk_03000440.unkEE, 3);
                    memcpy_bytes_08041D04(gUnk_083B7CD4 + gUnk_03000440.unkEF * 6, gUnk_03000440.unk10E, 6);
                    memcpy_bytes_0803F63C((const void *)gUnk_083B6EC8[gUnk_03000440.unk10E[1]], gUnk_03000440.unk9E,
                                          14);
                    sub_08017734(0);
                } else {
                    memcpy_bytes_08041D04(gUnk_083C4A10[4], gUnk_03000440.unk9E, 14);
                    err = 1;
                }
            } else {
                memcpy_bytes_08041D04(gUnk_083C4A10[1], gUnk_03000440.unk9E, 14);
                err = 1;
            }
        } else {
            memcpy_bytes_08041D04(gUnk_083C4A10[5], gUnk_03000440.unk9E, 14);
            err = 1;
        }
        break;
    case 3:

        if (gUnk_03000590[gUnk_03001800.unk80].medal.unk5 > 59) {
            if (gUnk_03001800.unk58 == 0) {
                if (gUnk_03000590[gUnk_03001800.unk80].unkC1 == 0x50) {
                    memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000590[gUnk_03001800.unk80].medal.unk1 * 3,
                                          &gUnk_03000440.unkEE, 3);
                    memcpy_bytes_08041D04(gUnk_083B7CD4 + gUnk_03000440.unkF0 * 6, gUnk_03000440.unk10E, 6);
                    memcpy_bytes_0803F63C((const void *)gUnk_083B6EC8[gUnk_03000440.unk10E[1]], gUnk_03000440.unk9E,
                                          14);
                    sub_08017734(0);
                } else {
                    memcpy_bytes_08041D04(gUnk_083C4A10[4], gUnk_03000440.unk9E, 14);
                    err = 1;
                }
            } else {
                memcpy_bytes_08041D04(gUnk_083C4A10[1], gUnk_03000440.unk9E, 14);
                err = 1;
            }
        } else {
            memcpy_bytes_08041D04(gUnk_083C4A10[5], gUnk_03000440.unk9E, 14);
            err = 1;
        }
        break;
    }
    if (err == 1 || blank == 1)
        sub_08017734(1);
    if (a) {
        if (err) {
            if (!(gUnk_03000440.unk84 & 8))
                render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x24, 0x13, 0xE, 10, 14, 0, 0);
        } else
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x24, 0x13, 0xE, 10, 14, 0, 0);
    } else
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x24, 0x13, 0xE, 10, 14, 0, 0);
}

// guess: Medaforce select input (D-pad picks gUnk_03001800.unk82 like part_select_input)
void sub_080175FC(void) {
    u8 old = gUnk_03001800.unk82;

    if (KEYS_LO(gNewKeys) & 0x40)
        gUnk_03001800.unk82 = 1;
    if (KEYS_LO(gNewKeys) & 0x80)
        gUnk_03001800.unk82 = 0;
    if (KEYS_LO(gNewKeys) & 0x20)
        gUnk_03001800.unk82 = 2;
    if (KEYS_LO(gNewKeys) & 0x10)
        gUnk_03001800.unk82 = 3;
    if (gUnk_03001800.unk82 != old) {
        play_sound_effect(2);
        sub_08017178(1);
        sub_080171C0(1);
        sub_08017208(1);
        sub_08017130(1);
        sub_08017268();
        sub_080173B4(0);
    }
}

void sub_0801767C(void) {
    switch (gUnk_03001800.unk82) {
    case 0:
        if (gUnk_03000440.unk84 & 8)
            sub_08017130(1);
        else
            sub_08017130(0);
        break;
    case 1:
        if (gUnk_03000440.unk84 & 8)
            sub_08017178(1);
        else
            sub_08017178(0);
        break;
    case 2:
        if (gUnk_03000440.unk84 & 8)
            sub_080171C0(1);
        else
            sub_080171C0(0);
        break;
    case 3:
        if (gUnk_03000440.unk84 & 8)
            sub_08017208(1);
        else
            sub_08017208(0);
        break;
    }
}

// guess: Medaforce select cost bar: 8-tile bar at BG0 (1..8, 17), lit tiles = unk10E[2] / 10, and the number
static void sub_08017734(u32 a) {
    u32 i = 0;
    u32 j;
    u8 n;
    int k;

    if (a == 0) {
        memcpy_bytes_08041D04(gUnk_083B7E0C + gUnk_03000590[gUnk_03001800.unk80].medal.unk1 * 3, &gUnk_03000440.unkEE,
                              3);
        k = gUnk_03001800.unk82 - 1;
        memcpy_bytes_08041D04(gUnk_083B7CD4 + (&gUnk_03000440.unkEE)[k] * 6, gUnk_03000440.unk10E, 6);
        n = gUnk_03000440.unk10E[2] / 10;
        for (j = 0; j < 8 - n; j++) {
            vram_fill_tilemap_rect(1, 1, i + 1, 0x11, REG_BG0CNT, 0);
            i++;
        }
        for (j = i; j <= 7; j++) {
            if (!(gUnk_03000440.unk84 & 4))
                draw_tile_block(1, 1, i + 1, 0x11, REG_BG0CNT, 0xB208);
            else
                draw_tile_block(1, 1, i + 1, 0x11, REG_BG0CNT, 0xC208);
            i++;
        }
        vram_fill_tilemap_rect(5, 1, 4, 0x12, REG_BG1CNT, 0);
        draw_number_bgcnt(gUnk_03000440.unk10E[2], 4, 0x12, 2, REG_BG1CNT, 0xD220);
        draw_battle_panel_left_b(gUnk_03001800.unk80);
    } else {
        vram_fill_tilemap_rect(8, 1, 1, 0x11, REG_BG0CNT, i);
        draw_medaforce_gauge_value(gUnk_03001800.unk80);
        if (gUnk_03000590[gUnk_03001800.unk80].unkC1 != 0x50)
            draw_battle_panel_left_a(gUnk_03001800.unk80);
    }
}

void sub_080178CC(void) {
    if (gUnk_03000590[gUnk_03001800.unk80].unkC1 == 0x50) {
        gUnk_03001800.unk85++;
        if (gUnk_03001800.unk85 & 8)
            draw_battle_panel_left_b(gUnk_03001800.unk80);
        else
            draw_battle_panel_left_a(gUnk_03001800.unk80);
    }
}

void sub_08017914(void) {
    if (gUnk_03000590[gUnk_03001800.unk80].unkC1 == 0x50)
        draw_battle_panel_left_b(gUnk_03001800.unk80);
    else
        draw_battle_panel_left_a(gUnk_03001800.unk80);
}

void sub_08017948(void) {
    if (gUnk_03000440.unk84 <= 11) {
        read_vram_tilemap_rect(13, 4, 0x11, 13, REG_BG1CNT, gUnk_02021000);
        write_vram_tilemap_rect(13, 4, 0x12, 13, REG_BG1CNT, gUnk_02021000);
    }
}
