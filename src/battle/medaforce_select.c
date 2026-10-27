// Tilemap window helpers for the battle menus (save / restore a BG0 / BG1 region, scroll a window), then the
// MF (Medaforce) menu of the command ring, Robattle sub-states 0x18-0x1D (runtime-checked in the Koji battle):
// a cross of four icons, DOWN = slot 0 "Charge MF", UP / LEFT / RIGHT = the Medal's three Medaforces, learned
// at Medal level 10 / 30 / 60 ("Unmastered" before that). Called from battle/robattle.

#include "global.h"

static void mf_menu_draw_cost_bar(u32 a);

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

// The ring icons grow back to full size while the ring reopens.
void command_ring_grow_icons(void) {
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

void mf_menu_load_frame(void) {
    set_tilemap_and_decompress_bg(9, 0x15, gUnk_084888E4, REG_BG0CNT, 0x2A0);
    set_tilemap_and_decompress_bg(0x12, 0x15, gUnk_08488920, REG_BG1CNT, 0x2B8);
}

void mf_menu_slide_bg0(void) {
    if (gUnk_03000440.unk84 < 4)
        write_vram_tilemap_rect(0xC, 4, 9, 0x13 - gUnk_03000440.unk84, REG_BG0CNT, gUnk_02020800);
}

void mf_menu_slide_bg1(void) {
    if (gUnk_03000440.unk84 < 12) {
        read_vram_tilemap_rect(gUnk_03000440.unk84 + 1, 4, 0x12, 0x15, REG_BG1CNT, gUnk_02021000);
        write_vram_tilemap_rect(gUnk_03000440.unk84 + 1, 4, 0x1D - gUnk_03000440.unk84, 0xD, REG_BG1CNT, gUnk_02021000);
    }
}

// guess: starts on the slot of the Medaforce used last (unkDD).
void mf_menu_init_cursor(void) {
    u32 v = gUnk_03000590[gUnk_03001800.unk80].unkDD;
    if (v <= 3)
        v = 0;
    else
        v -= 5;
    gUnk_03001800.unk82 = v;
}

void mf_menu_init_center_icon(void) {
    gSpriteEntries[0].unk0 = 0xC404;
    gSpriteEntries[0].unk1C = 0;
    gSpriteEntries[0].unk2 = 0x78;
    gSpriteEntries[0].unk4 = 0x78;
    gSpriteEntries[0].unkA = 0xA;
    gSpriteEntries[0].unkB = 0xC0;
    gSpriteEntries[0].unk6 = 0x61A;
}

void mf_menu_init_charge_icon(u32 a) {
    gSpriteEntries[1].unk0 = 0xC404;
    gSpriteEntries[1].unk1C = 0;
    gSpriteEntries[1].unk2 = 0x78;
    gSpriteEntries[1].unk4 = 0x84;
    gSpriteEntries[1].unkA = 0xA;
    gSpriteEntries[1].unkB = 0xC0;
    gSpriteEntries[1].unk6 = a * 4 + 0x61E;
}

void mf_menu_init_top_icon(u32 a) {
    gSpriteEntries[2].unk0 = 0xC404;
    gSpriteEntries[2].unk1C = 0;
    gSpriteEntries[2].unk2 = 0x78;
    gSpriteEntries[2].unk4 = 0x6C;
    gSpriteEntries[2].unkA = 0xA;
    gSpriteEntries[2].unkB = 0xC0;
    gSpriteEntries[2].unk6 = a * 4 + 0x61B;
}

void mf_menu_init_left_icon(u32 a) {
    gSpriteEntries[3].unk0 = 0xC404;
    gSpriteEntries[3].unk1C = 0;
    gSpriteEntries[3].unk2 = 0x6C;
    gSpriteEntries[3].unk4 = 0x78;
    gSpriteEntries[3].unkA = 0xA;
    gSpriteEntries[3].unkB = 0xC0;
    gSpriteEntries[3].unk6 = a * 4 + 0x61C;
}

void mf_menu_init_right_icon(u32 a) {
    gSpriteEntries[4].unk0 = 0xC404;
    gSpriteEntries[4].unk1C = 0;
    gSpriteEntries[4].unk2 = 0x84;
    gSpriteEntries[4].unk4 = 0x78;
    gSpriteEntries[4].unkA = 0xA;
    gSpriteEntries[4].unkB = 0xC0;
    gSpriteEntries[4].unk6 = a * 4 + 0x61D;
}

// Name box of the selected slot: "Charge MF" for slot 0, else the Medaforce name, blank while unlearned.
void mf_menu_draw_medaforce_name(void) {
    clear_sprite_table_mask(0x14, 16);
    switch (gUnk_03001800.unk82) {
    case 0:
        memcpy_bytes_08041D04(gBattleMenuTexts[3], gUnk_03000440.unk9E, 14);
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

// Message box of the selected slot: the Medaforce's skill type, or "Unmastered" (Medal level too low) /
// "Unusable" (Medaforce blocked) / "MF low" (gauge not full); error messages blink when a != 0.
void mf_menu_draw_status(u32 a) {
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
                    mf_menu_draw_cost_bar(0);
                } else {
                    memcpy_bytes_08041D04(gBattleMenuTexts[4], gUnk_03000440.unk9E, 14);
                    err = 1;
                }
            } else {
                memcpy_bytes_08041D04(gBattleMenuTexts[1], gUnk_03000440.unk9E, 14);
                err = 1;
            }
        } else {
            memcpy_bytes_08041D04(gBattleMenuTexts[5], gUnk_03000440.unk9E, 14);
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
                    mf_menu_draw_cost_bar(0);
                } else {
                    memcpy_bytes_08041D04(gBattleMenuTexts[4], gUnk_03000440.unk9E, 14);
                    err = 1;
                }
            } else {
                memcpy_bytes_08041D04(gBattleMenuTexts[1], gUnk_03000440.unk9E, 14);
                err = 1;
            }
        } else {
            memcpy_bytes_08041D04(gBattleMenuTexts[5], gUnk_03000440.unk9E, 14);
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
                    mf_menu_draw_cost_bar(0);
                } else {
                    memcpy_bytes_08041D04(gBattleMenuTexts[4], gUnk_03000440.unk9E, 14);
                    err = 1;
                }
            } else {
                memcpy_bytes_08041D04(gBattleMenuTexts[1], gUnk_03000440.unk9E, 14);
                err = 1;
            }
        } else {
            memcpy_bytes_08041D04(gBattleMenuTexts[5], gUnk_03000440.unk9E, 14);
            err = 1;
        }
        break;
    }
    if (err == 1 || blank == 1)
        mf_menu_draw_cost_bar(1);
    if (a) {
        if (err) {
            if (!(gUnk_03000440.unk84 & 8))
                render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x24, 0x13, 0xE, 10, 14, 0, 0);
        } else
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x24, 0x13, 0xE, 10, 14, 0, 0);
    } else
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x24, 0x13, 0xE, 10, 14, 0, 0);
}

// D-pad picks the slot (gUnk_03001800.unk82), like part_select_input.
void mf_menu_input(void) {
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
        mf_menu_init_top_icon(1);
        mf_menu_init_left_icon(1);
        mf_menu_init_right_icon(1);
        mf_menu_init_charge_icon(1);
        mf_menu_draw_medaforce_name();
        mf_menu_draw_status(0);
    }
}

void mf_menu_blink_selected_icon(void) {
    switch (gUnk_03001800.unk82) {
    case 0:
        if (gUnk_03000440.unk84 & 8)
            mf_menu_init_charge_icon(1);
        else
            mf_menu_init_charge_icon(0);
        break;
    case 1:
        if (gUnk_03000440.unk84 & 8)
            mf_menu_init_top_icon(1);
        else
            mf_menu_init_top_icon(0);
        break;
    case 2:
        if (gUnk_03000440.unk84 & 8)
            mf_menu_init_left_icon(1);
        else
            mf_menu_init_left_icon(0);
        break;
    case 3:
        if (gUnk_03000440.unk84 & 8)
            mf_menu_init_right_icon(1);
        else
            mf_menu_init_right_icon(0);
        break;
    }
}

// Cost bar of the selected Medaforce: 8-tile bar at BG0 (1..8, 17), lit tiles = unk10E[2] / 10, and the number;
// a != 0 puts the gauge back.
static void mf_menu_draw_cost_bar(u32 a) {
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

// The Medabot's panel blinks while its Medaforce gauge is full (80).
void mf_gauge_full_blink_panel(void) {
    if (gUnk_03000590[gUnk_03001800.unk80].unkC1 == 0x50) {
        gUnk_03001800.unk85++;
        if (gUnk_03001800.unk85 & 8)
            draw_battle_panel_left_b(gUnk_03001800.unk80);
        else
            draw_battle_panel_left_a(gUnk_03001800.unk80);
    }
}

void mf_gauge_draw_panel(void) {
    if (gUnk_03000590[gUnk_03001800.unk80].unkC1 == 0x50)
        draw_battle_panel_left_b(gUnk_03001800.unk80);
    else
        draw_battle_panel_left_a(gUnk_03001800.unk80);
}

void mf_menu_slide_out_bg1(void) {
    if (gUnk_03000440.unk84 <= 11) {
        read_vram_tilemap_rect(13, 4, 0x11, 13, REG_BG1CNT, gUnk_02021000);
        write_vram_tilemap_rect(13, 4, 0x12, 13, REG_BG1CNT, gUnk_02021000);
    }
}
