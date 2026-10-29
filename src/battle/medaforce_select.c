// Tilemap window helpers for the battle menus (save / restore a BG0 / BG1 region, scroll a window), then the
// MF (Medaforce) menu of the command ring, Robattle sub-states 0x18-0x1D (runtime-checked in the Koji battle):
// a cross of four icons, DOWN = slot 0 "Charge MF", UP / LEFT / RIGHT = the Medal's three Medaforces, learned
// at Medal level 10 / 30 / 60 ("Unmastered" before that). Called from battle/robattle.

#include "global.h"
#include "constants/sprites.h"

static void mf_menu_draw_cost_bar(u32 a);

void save_restore_bg1_tilemap_region(void) {
    if (gGameWork.stepCounter < 12) {
        read_vram_tilemap_rect(0xD, 7, 0x11, 0xD, REG_BG1CNT, gBgTileBackupHigh);
        write_vram_tilemap_rect(0xD, 7, 0x12, 0xD, REG_BG1CNT, gBgTileBackupHigh);
    }
}

void save_restore_bg0_tilemap_region(void) {
    if (gGameWork.stepCounter < 4) {
        read_vram_tilemap_rect(0xC, 5, 9, 0xF, REG_BG0CNT, gBgTileBackup);
        write_vram_tilemap_rect(0xC, 5, 9, 0x10, REG_BG0CNT, gBgTileBackup);
    }
}

void draw_partial_bg1_column(void) {
    if (gGameWork.stepCounter <= 4)
        write_vram_tilemap_rect(6, 5, 0xC, 0x13 - gGameWork.stepCounter, REG_BG1CNT, gBgTileBackup);
}

void scroll_tilemap_window(void) {
    if (gGameWork.stepCounter <= 9) {
        read_vram_tilemap_rect(gGameWork.stepCounter + 1, 4, 0x14, 0x15, REG_BG1CNT, gBgTileBackupHigh);
        write_vram_tilemap_rect(gGameWork.stepCounter + 1, 4, 0x1D - gGameWork.stepCounter, 0x10, REG_BG1CNT,
                                gBgTileBackupHigh);
    }
}

// The ring icons grow back to full size while the ring reopens.
void command_ring_grow_icons(void) {
    u32 i;
    for (i = 0; i < 6; i++) {
        gSpriteEntries[i].scale_y += 8;
        gSpriteEntries[i].scale_x += 8;
        if (gSpriteEntries[i].scale_y > 0x40 - (0x90 - gSpriteEntries[i].y) / 2) {
            gSpriteEntries[i].scale_y = 0x40 - (0x90 - gSpriteEntries[i].y) / 2;
            gSpriteEntries[i].scale_x = 0x40 - (0x90 - gSpriteEntries[i].y) / 2;
        }
    }
}

void mf_menu_load_frame(void) {
    set_tilemap_and_decompress_bg(9, 0x15, gMfMenuLeftPanelTilemap, REG_BG0CNT, 0x2A0);
    set_tilemap_and_decompress_bg(0x12, 0x15, gMfMenuRightPanelTilemap, REG_BG1CNT, 0x2B8);
}

void mf_menu_slide_bg0(void) {
    if (gGameWork.stepCounter < 4)
        write_vram_tilemap_rect(0xC, 4, 9, 0x13 - gGameWork.stepCounter, REG_BG0CNT, gBgTileBackup);
}

void mf_menu_slide_bg1(void) {
    if (gGameWork.stepCounter < 12) {
        read_vram_tilemap_rect(gGameWork.stepCounter + 1, 4, 0x12, 0x15, REG_BG1CNT, gBgTileBackupHigh);
        write_vram_tilemap_rect(gGameWork.stepCounter + 1, 4, 0x1D - gGameWork.stepCounter, 0xD, REG_BG1CNT,
                                gBgTileBackupHigh);
    }
}

// guess: starts on the slot of the Medaforce used last (action).
void mf_menu_init_cursor(void) {
    u32 action = gBattleBots[gBattleWork.commandBot].chosenAction;
    if (action <= 3)
        action = 0;
    else
        action -= 5;
    gBattleWork.partCursor = action;
}

void mf_menu_init_center_icon(void) {
    gSpriteEntries[0].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0].frame_table = 0;
    gSpriteEntries[0].x = 0x78;
    gSpriteEntries[0].y = 0x78;
    gSpriteEntries[0].palette = 0xA;
    gSpriteEntries[0].order = 0xC0;
    gSpriteEntries[0].frame = 0x61A;
}

void mf_menu_init_charge_icon(u32 highlighted) {
    gSpriteEntries[1].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[1].frame_table = 0;
    gSpriteEntries[1].x = 0x78;
    gSpriteEntries[1].y = 0x84;
    gSpriteEntries[1].palette = 0xA;
    gSpriteEntries[1].order = 0xC0;
    gSpriteEntries[1].frame = highlighted * 4 + 0x61E;
}

void mf_menu_init_top_icon(u32 highlighted) {
    gSpriteEntries[2].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[2].frame_table = 0;
    gSpriteEntries[2].x = 0x78;
    gSpriteEntries[2].y = 0x6C;
    gSpriteEntries[2].palette = 0xA;
    gSpriteEntries[2].order = 0xC0;
    gSpriteEntries[2].frame = highlighted * 4 + 0x61B;
}

void mf_menu_init_left_icon(u32 highlighted) {
    gSpriteEntries[3].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[3].frame_table = 0;
    gSpriteEntries[3].x = 0x6C;
    gSpriteEntries[3].y = 0x78;
    gSpriteEntries[3].palette = 0xA;
    gSpriteEntries[3].order = 0xC0;
    gSpriteEntries[3].frame = highlighted * 4 + 0x61C;
}

void mf_menu_init_right_icon(u32 highlighted) {
    gSpriteEntries[4].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[4].frame_table = 0;
    gSpriteEntries[4].x = 0x84;
    gSpriteEntries[4].y = 0x78;
    gSpriteEntries[4].palette = 0xA;
    gSpriteEntries[4].order = 0xC0;
    gSpriteEntries[4].frame = highlighted * 4 + 0x61D;
}

// Name box of the selected slot: "Charge MF" for slot 0, else the Medaforce name, blank while unlearned.
void mf_menu_draw_medaforce_name(void) {
    disable_sprites(0x14, 16);
    switch (gBattleWork.partCursor) {
    case 0:
        memcpy_bytes_08041D04(gBattleMenuTexts[3], gGameWork.textBuf, 14);
        break;
    case 1:
        if (gBattleBots[gBattleWork.commandBot].medal.level > 9) {
            memcpy_bytes_08041D04(gMedalMedaforceIds + gBattleBots[gBattleWork.commandBot].medal.graphicId * 3,
                                  &gGameWork.partAbility, 3);
            memcpy_bytes_0803F63C((const void *)gMedaforceNames[gGameWork.partAbility], gGameWork.textBuf, 17);
        } else
            fill_text_blank(gGameWork.textBuf, 13);
        break;
    case 2:
        if (gBattleBots[gBattleWork.commandBot].medal.level > 29) {
            memcpy_bytes_08041D04(gMedalMedaforceIds + gBattleBots[gBattleWork.commandBot].medal.graphicId * 3,
                                  &gGameWork.partAbility, 3);
            memcpy_bytes_0803F63C((const void *)gMedaforceNames[gGameWork.partSkill], gGameWork.textBuf, 17);
        } else
            fill_text_blank(gGameWork.textBuf, 13);
        break;
    case 3:
        if (gBattleBots[gBattleWork.commandBot].medal.level > 59) {
            memcpy_bytes_08041D04(gMedalMedaforceIds + gBattleBots[gBattleWork.commandBot].medal.graphicId * 3,
                                  &gGameWork.partAbility, 3);
            memcpy_bytes_0803F63C((const void *)gMedaforceNames[gGameWork.partSkillType], gGameWork.textBuf, 17);
        } else
            fill_text_blank(gGameWork.textBuf, 13);
        break;
    }
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x14, 10, 0x11, 10, 13, 0, 0);
}

// Message box of the selected slot: the Medaforce's skill type, or "Unmastered" (Medal level too low) /
// "Unusable" (Medaforce blocked) / "MF low" (gauge not full); error messages blink when a != 0.
void mf_menu_draw_status(u32 blink_errors) {
    u8 err = 0;
    u8 blank = 0;

    disable_sprites(0x24, 13);
    switch (gBattleWork.partCursor) {
    case 0:
        fill_text_blank(gGameWork.textBuf, 13);
        blank = 1;
        break;
    case 1:

        if (gBattleBots[gBattleWork.commandBot].medal.level > 9) {
            if (gBattleWork.medaforceBlocked == 0) {
                if (gBattleBots[gBattleWork.commandBot].medaforceGauge == 0x50) {
                    memcpy_bytes_08041D04(gMedalMedaforceIds + gBattleBots[gBattleWork.commandBot].medal.graphicId * 3,
                                          &gGameWork.partAbility, 3);
                    memcpy_bytes_08041D04(gMedaforceRecords + gGameWork.partAbility * 6, gGameWork.medalGfxRecord, 6);
                    memcpy_bytes_0803F63C((const void *)gSkillTypeNames[gGameWork.medalGfxRecord[1]], gGameWork.textBuf,
                                          14);
                    mf_menu_draw_cost_bar(0);
                } else {
                    memcpy_bytes_08041D04(gBattleMenuTexts[4], gGameWork.textBuf, 14);
                    err = 1;
                }
            } else {
                memcpy_bytes_08041D04(gBattleMenuTexts[1], gGameWork.textBuf, 14);
                err = 1;
            }
        } else {
            memcpy_bytes_08041D04(gBattleMenuTexts[5], gGameWork.textBuf, 14);
            err = 1;
        }
        break;
    case 2:

        if (gBattleBots[gBattleWork.commandBot].medal.level > 29) {
            if (gBattleWork.medaforceBlocked == 0) {
                if (gBattleBots[gBattleWork.commandBot].medaforceGauge == 0x50) {
                    memcpy_bytes_08041D04(gMedalMedaforceIds + gBattleBots[gBattleWork.commandBot].medal.graphicId * 3,
                                          &gGameWork.partAbility, 3);
                    memcpy_bytes_08041D04(gMedaforceRecords + gGameWork.partSkill * 6, gGameWork.medalGfxRecord, 6);
                    memcpy_bytes_0803F63C((const void *)gSkillTypeNames[gGameWork.medalGfxRecord[1]], gGameWork.textBuf,
                                          14);
                    mf_menu_draw_cost_bar(0);
                } else {
                    memcpy_bytes_08041D04(gBattleMenuTexts[4], gGameWork.textBuf, 14);
                    err = 1;
                }
            } else {
                memcpy_bytes_08041D04(gBattleMenuTexts[1], gGameWork.textBuf, 14);
                err = 1;
            }
        } else {
            memcpy_bytes_08041D04(gBattleMenuTexts[5], gGameWork.textBuf, 14);
            err = 1;
        }
        break;
    case 3:

        if (gBattleBots[gBattleWork.commandBot].medal.level > 59) {
            if (gBattleWork.medaforceBlocked == 0) {
                if (gBattleBots[gBattleWork.commandBot].medaforceGauge == 0x50) {
                    memcpy_bytes_08041D04(gMedalMedaforceIds + gBattleBots[gBattleWork.commandBot].medal.graphicId * 3,
                                          &gGameWork.partAbility, 3);
                    memcpy_bytes_08041D04(gMedaforceRecords + gGameWork.partSkillType * 6, gGameWork.medalGfxRecord, 6);
                    memcpy_bytes_0803F63C((const void *)gSkillTypeNames[gGameWork.medalGfxRecord[1]], gGameWork.textBuf,
                                          14);
                    mf_menu_draw_cost_bar(0);
                } else {
                    memcpy_bytes_08041D04(gBattleMenuTexts[4], gGameWork.textBuf, 14);
                    err = 1;
                }
            } else {
                memcpy_bytes_08041D04(gBattleMenuTexts[1], gGameWork.textBuf, 14);
                err = 1;
            }
        } else {
            memcpy_bytes_08041D04(gBattleMenuTexts[5], gGameWork.textBuf, 14);
            err = 1;
        }
        break;
    }
    if (err == 1 || blank == 1)
        mf_menu_draw_cost_bar(1);
    if (blink_errors) {
        if (err) {
            if (!(gGameWork.stepCounter & 8))
                render_text_sprites_08040DB8(gGameWork.textBuf, 0x24, 0x13, 0xE, 10, 14, 0, 0);
        } else
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x24, 0x13, 0xE, 10, 14, 0, 0);
    } else
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x24, 0x13, 0xE, 10, 14, 0, 0);
}

// D-pad picks the slot (gBattleWork.partCursor), like part_select_input.
void mf_menu_input(void) {
    u8 old = gBattleWork.partCursor;

    if (KEYS_LO(gNewKeys) & DPAD_UP)
        gBattleWork.partCursor = 1;
    if (KEYS_LO(gNewKeys) & DPAD_DOWN)
        gBattleWork.partCursor = 0;
    if (KEYS_LO(gNewKeys) & DPAD_LEFT)
        gBattleWork.partCursor = 2;
    if (KEYS_LO(gNewKeys) & DPAD_RIGHT)
        gBattleWork.partCursor = 3;
    if (gBattleWork.partCursor != old) {
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
    switch (gBattleWork.partCursor) {
    case 0:
        if (gGameWork.stepCounter & 8)
            mf_menu_init_charge_icon(1);
        else
            mf_menu_init_charge_icon(0);
        break;
    case 1:
        if (gGameWork.stepCounter & 8)
            mf_menu_init_top_icon(1);
        else
            mf_menu_init_top_icon(0);
        break;
    case 2:
        if (gGameWork.stepCounter & 8)
            mf_menu_init_left_icon(1);
        else
            mf_menu_init_left_icon(0);
        break;
    case 3:
        if (gGameWork.stepCounter & 8)
            mf_menu_init_right_icon(1);
        else
            mf_menu_init_right_icon(0);
        break;
    }
}

// Cost bar of the selected Medaforce: 8-tile bar at BG0 (1..8, 17), lit tiles = medalGfxRecord[2] / 10, and the number;
// a != 0 puts the gauge back.
static void mf_menu_draw_cost_bar(u32 clear) {
    u32 i = 0;
    u32 j;
    u8 n;
    int k;

    if (clear == 0) {
        memcpy_bytes_08041D04(gMedalMedaforceIds + gBattleBots[gBattleWork.commandBot].medal.graphicId * 3,
                              &gGameWork.partAbility, 3);
        k = gBattleWork.partCursor - 1;
        memcpy_bytes_08041D04(gMedaforceRecords + (&gGameWork.partAbility)[k] * 6, gGameWork.medalGfxRecord, 6);
        n = gGameWork.medalGfxRecord[2] / 10;
        for (j = 0; j < 8 - n; j++) {
            vram_fill_tilemap_rect(1, 1, i + 1, 0x11, REG_BG0CNT, 0);
            i++;
        }
        for (j = i; j <= 7; j++) {
            if (!(gGameWork.stepCounter & 4))
                draw_tile_block(1, 1, i + 1, 0x11, REG_BG0CNT, 0xB208);
            else
                draw_tile_block(1, 1, i + 1, 0x11, REG_BG0CNT, 0xC208);
            i++;
        }
        vram_fill_tilemap_rect(5, 1, 4, 0x12, REG_BG1CNT, 0);
        draw_number_bgcnt(gGameWork.medalGfxRecord[2], 4, 0x12, 2, REG_BG1CNT, 0xD220);
        draw_battle_panel_left_b(gBattleWork.commandBot);
    } else {
        vram_fill_tilemap_rect(8, 1, 1, 0x11, REG_BG0CNT, i);
        draw_medaforce_gauge_value(gBattleWork.commandBot);
        if (gBattleBots[gBattleWork.commandBot].medaforceGauge != 0x50)
            draw_battle_panel_left_a(gBattleWork.commandBot);
    }
}

// The Medabot's panel blinks while its Medaforce gauge is full (80).
void mf_gauge_full_blink_panel(void) {
    if (gBattleBots[gBattleWork.commandBot].medaforceGauge == 0x50) {
        gBattleWork.gaugeBlinkTimer++;
        if (gBattleWork.gaugeBlinkTimer & 8)
            draw_battle_panel_left_b(gBattleWork.commandBot);
        else
            draw_battle_panel_left_a(gBattleWork.commandBot);
    }
}

void mf_gauge_draw_panel(void) {
    if (gBattleBots[gBattleWork.commandBot].medaforceGauge == 0x50)
        draw_battle_panel_left_b(gBattleWork.commandBot);
    else
        draw_battle_panel_left_a(gBattleWork.commandBot);
}

void mf_menu_slide_out_bg1(void) {
    if (gGameWork.stepCounter <= 11) {
        read_vram_tilemap_rect(13, 4, 0x11, 13, REG_BG1CNT, gBgTileBackupHigh);
        write_vram_tilemap_rect(13, 4, 0x12, 13, REG_BG1CNT, gBgTileBackupHigh);
    }
}
