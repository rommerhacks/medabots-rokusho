// Battle graphics: battle_load_graphics_step (staged decompression of the battle BG and sprite graphics),
// battle message window helpers, clear_battle_ui_tilemaps, Medaforce gauge fill / drain steps.
// Called from battle/robattle and battle/action_steps.

#include "global.h"

u32 battle_load_graphics_step(u32 direct) {
    switch (gGameWork.unk13A) {
    case 0:
        lz_decompress_dispatch(gGaugeFillTiles, (void *)0x06004000);
        lz_decompress_dispatch(gMedaforceLabelTiles, (void *)0x06004140);
        lz_decompress_dispatch(gMedaforceGaugeFrameTiles, (void *)0x06004200);
        gGameWork.unk13A++;
        break;
    case 1:
        lz_decompress_dispatch(gMedaforceGaugeFrameEndTiles, (void *)0x06004300);
        lz_decompress_dispatch(gMedaforceGaugeTiles, (void *)0x06004400);
        lz_decompress_dispatch(gBattlePillarTiles, (void *)0x0600C000);
        lz_decompress_dispatch(gBattlePillarCapTiles, (void *)0x0600C600);
        gGameWork.unk13A++;
        break;
    case 2:
        lz_decompress_dispatch(gRightBotPanelTiles, (void *)0x06004E00);
        lz_decompress_dispatch(gPartsMenuLeftPanelTiles, (void *)0x06005100);
        lz_decompress_dispatch(gMfMenuLeftPanelTiles, (void *)0x06005400);
        lz_decompress_dispatch(gMfMenuRightPanelTiles, (void *)0x06005700);
        lz_decompress_dispatch(gPartsMenuRightPanelTiles, (void *)0x06005A00);
        gGameWork.unk13A++;
        break;
    case 3:
        lz_decompress_dispatch(gBotActionIconTiles, (void *)0x0600C280);
        lz_decompress_dispatch(gBattleUiSpriteTiles, (void *)0x06012000);
        lz_decompress_dispatch(gMissPopupTiles, (void *)0x06014E00);
        lz_decompress_dispatch(gBotShadowTiles, (void *)0x06017F80);
        lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
        gGameWork.unk13A++;
        break;
    case 4:
        lz_decompress_dispatch(gActionSelectPanelTiles, (void *)0x06004600);
        lz_decompress_dispatch(gActionSelectSidePanelTiles, (void *)0x06004800);
        lz_decompress_dispatch(gLeftBotPanelTiles, (void *)0x06004B00);
        gGameWork.unk13A++;
        break;
    case 5:
        gGameWork.unk13A++;
        break;
    case 6:
        lz_decompress_dispatch(gBattleNumberSpriteTiles, (void *)0x06013000);
        lz_decompress_dispatch(gBattleMarkerTilesLz, (void *)0x06013C00);
        lz_decompress_dispatch(gBattleMarkerAltTilesLz, (void *)0x06014200);
        gGameWork.unk13A++;
        break;
    case 7:
        vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG1CNT, 0);
        gGameWork.unk13A++;
        break;
    case 8:
        if (direct == 0) {
            vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG0CNT, direct);
            decompress_sprite_to_vram_08043C08(gBattleWork.battlefield, 1);
            CpuFastSet(gBattleBgPalette8, (void *)0x0202FB00, 8);
            CpuFastSet(gBattleBgPalette10, (void *)0x0202FB40, 8);
            CpuFastSet(gBattleBgPalette11, (void *)0x0202FB60, 8);
            CpuFastSet(gBattleBgPalette12, (void *)0x0202FB80, 8);
            CpuFastSet(gBattleBgPalette13, (void *)0x0202FBA0, 8);
            CpuFastSet(gTargetLinePalette, (void *)0x0202F900, 8);
            CpuFastSet(gTargetArrowsPalette, (void *)0x0202F920, 8);
            CpuFastSet(gBattleObjPalette10, (void *)0x0202F940, 8);
            CpuFastSet(gHealNumberPalette, (void *)0x0202F960, 16);
            CpuFastSet(gBattleObjPalettes13, (void *)0x0202F9A0, 8);
            CpuFastSet(gBattleObjPalettes13 + 0x20, (void *)0x0202F9C0, 8);
            CpuFastSet(gBattleObjPalettes13 + 0x40, (void *)0x0202F9E0, 8);
            CpuFastSet(gBattleObjPalette5, (void *)0x0202F8A0, 8);
        } else {
            decompress_sprite_to_vram_08043C08(gBattleWork.battlefield, 0);
            CpuFastSet(gBattleBgPalette8, (void *)0x05000100, 8);
            CpuFastSet(gBattleBgPalette10, (void *)0x05000140, 8);
            CpuFastSet(gBattleBgPalette11, (void *)0x05000160, 8);
            CpuFastSet(gBattleBgPalette12, (void *)0x05000180, 8);
            CpuFastSet(gBattleBgPalette13, (void *)0x050001A0, 8);
            CpuFastSet(gTargetLinePalette, (void *)0x05000300, 8);
            CpuFastSet(gTargetArrowsPalette, (void *)0x05000320, 8);
            CpuFastSet(gBattleObjPalette10, (void *)0x05000340, 8);
            CpuFastSet(gHealNumberPalette, (void *)0x05000360, 16);
            CpuFastSet(gBattleObjPalettes13, (void *)0x050003A0, 8);
            CpuFastSet(gBattleObjPalettes13 + 0x20, (void *)0x050003C0, 8);
            CpuFastSet(gBattleObjPalettes13 + 0x40, (void *)0x050003E0, 8);
            CpuFastSet(gBattleObjPalette5, (void *)0x050002A0, 8);
        }
        gGameWork.unk13A = 0;
        return 1;
    }
    return 0;
}

void battle_message_open(void) {
    if (gOptionSkipMessages == 0 || gGameWork.skipBotSetup == 1)
        text_window_init(1, 2, 0);
}

u32 battle_message_print(u32 msg) {
    u32 done;

    if (gOptionSkipMessages == 0 || gGameWork.skipBotSetup == 1) {
        done = run_message(gBattleMessages[msg]);
        if (done)
            gGameWork.endModeStep = 0;
        return done;
    }
    return 1;
}

u32 battle_message_finish(void) {
    if (gOptionSkipMessages == 0 || gGameWork.skipBotSetup == 1)
        return game_state_execute_handler_a();
    return 1;
}

void draw_bot_panel_frame(u32 bot) {
    if (bot <= 2) {
        set_tilemap_and_decompress_bg(0, 13, gLeftBotPanelTilemap, REG_BG1CNT, 0x258);
        set_tilemap_and_decompress_bg(0, 17, gMedaforceGaugeFrameTilemap, REG_BG1CNT, 0x210);
    } else {
        set_tilemap_and_decompress_bg(18, 13, gRightBotPanelTilemap, REG_BG1CNT, 0x270);
        set_tilemap_and_decompress_bg(20, 17, gMedaforceGaugeFrameTilemap, REG_BG1CNT, 0x210);
    }
}

void draw_bot_status_panel(u32 bot) {
    if (gBattleBots[bot].medaforceGauge == 0x50)
        draw_battle_panel_left_b(bot);
    else
        draw_battle_panel_left_a(bot);
    draw_medaforce_gauge_bar(bot);
    draw_medaforce_gauge_value(bot);
}

void target_arrows_init(u32 bot) {
    u32 i;

    clear_battle_sprite_slot(0x78, 8);
    for (i = 0; i <= 7; i++) {
        gSpriteEntries[0x78 + i].unk0 = 0xC404;
        gSpriteEntries[0x78 + i].unk1C = 0;
        gSpriteEntries[0x78 + i].unk4 = 0x78;
        gSpriteEntries[0x78 + i].unkA = 9;
        gSpriteEntries[0x78 + i].unkB = 0x80;
        gSpriteEntries[0x78 + i].unk6 = (i & 3) + 0x616;
        gSpriteEntries[0x78 + i].unk24 = 0;
        gSpriteEntries[0x78 + i].unk26 = 7 - i;
        gSpriteEntries[0x78 + i].unk28 = 0;
        gSpriteEntries[0x78 + i].unk27 = i * 2;
        gSpriteEntries[0x78 + i].unk21 = 0;
        gSpriteEntries[0x78 + i].unk22 = i & 3;
        if (bot <= 2) {
            gSpriteEntries[0x78 + i].unk0 |= 0x1000;
            gSpriteEntries[0x78 + i].unk2 = 0x5C;
        } else {
            gSpriteEntries[0x78 + i].unk0 &= ~0x1000;
            gSpriteEntries[0x78 + i].unk2 = 0x94;
        }
    }
}

#define S gSpriteEntries[0x78 + i]
u32 target_arrows_slide(u32 bot) {
    u32 done = 1;
    u32 i;

    for (i = 0; i <= 7; i++) {
        S.unk21++;
        if ((S.unk21 & 3) == 0)
            S.unk6 = (S.unk22 = (S.unk22 + 1) & 3) + 0x616;
        if (S.unk26 != S.unk24) {
            done = 0;
            if (S.unk27 != 0)
                S.unk27--;
            else {
                if (bot <= 2)
                    S.unk2 += 4;
                else
                    S.unk2 -= 4;
                S.unk28++;
                if ((S.unk28 & 1) == 0)
                    S.unk24++;
            }
        }
    }
    return done;
}
#undef S

void target_arrows_animate(u32 bot) {
    u32 i;

    for (i = 0; i <= 7; i++) {
        gSpriteEntries[0x78 + i].unk21++;
        if ((gSpriteEntries[0x78 + i].unk21 & 3) == 0)
            gSpriteEntries[0x78 + i].unk6 =
                (gSpriteEntries[0x78 + i].unk22 = (gSpriteEntries[0x78 + i].unk22 + 1) & 3) + 0x616;
    }
}

void battle_substeps_reset(void) {
    gBattleWork.unk9C[0] = 0;
    gBattleWork.unk9C[1] = 0;
    gBattleWork.unk9C[2] = 0;
    gBattleWork.unk9C[3] = 0;
    gBattleWork.unk9C[4] = 0;
}

void battle_message_reset(void) {
    gBattleWork.unkA1[0] = 0;
    gBattleWork.unkA1[1] = 0;
    gBattleWork.unkA1[2] = 0;
    gBattleWork.unkA1[3] = 0;
    gBattleWork.unkA1[4] = 0;
}

void clear_battle_ui_tilemaps(void) {
    vram_fill_tilemap_rect(12, 7, 0, 13, REG_BG1CNT, 0);
    vram_fill_tilemap_rect(12, 7, 18, 13, REG_BG1CNT, 0);
    vram_fill_tilemap_rect(12, 7, 0, 13, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(12, 7, 18, 13, REG_BG0CNT, 0);
    clear_battle_sprite_slot(0x3C, 10);
    clear_battle_sprite_slot(0x78, 8);
    clear_battle_sprite_slot(10, 0x17);
}

u32 medaforce_gauge_fill_step(u32 bot) {
    if (gBattleWork.unk51 != 0 && gBattleBots[bot].medaforceGauge != 0x50) {
        gBattleBots[bot].medaforceGauge++;
        gBattleWork.unk51--;
        draw_medaforce_gauge_bar(bot);
        draw_medaforce_gauge_value(bot);
        return 0;
    }
    return 1;
}

u32 medaforce_gauge_drain_step(u32 bot) {
    if (gBattleWork.unk51 != 0 && gBattleBots[bot].medaforceGauge != 0) {
        gBattleBots[bot].medaforceGauge--;
        gBattleWork.unk51--;
        draw_medaforce_gauge_bar(bot);
        draw_medaforce_gauge_value(bot);
        return 0;
    }
    return 1;
}

void mf_charge_sparkles_init(u32 bot) {
    u32 i;
    struct Vec16 p;

    CpuFastSet(gMfChargeSparklePalette, (void *)0x050002C0, 8);
    for (i = 0; i <= 7; i++) {
        clear_battle_sprite_slot(i + 0x21, 1);
        gSpriteEntries[0x21 + i].unk0 = ((gBattleWork.battlefieldParams[3] + 2) << 10) | 0x4204;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unkA = 6;
        gSpriteEntries[0x21 + i].unkB = 0x81;
        gSpriteEntries[0x21 + i].unk6 = 0xA10;
        gSpriteEntries[0x21 + i].unk20 = i << 5;
        gSpriteEntries[0x21 + i].unk21 = gSpriteEntries[bot * 4 + 0x5D].unk4;
        gSpriteEntries[0x21 + i].unk28 = 0;
        gSpriteEntries[0x21 + i].unk27 = i * 4;
        gSpriteEntries[0x21 + i].unk26 = 0;
        p = compute_polar_to_screen_position(gSpriteEntries[0x21 + i].unk20, 16, gSpriteEntries[bot * 4 + 0x5D].unk2,
                                             gSpriteEntries[0x21 + i].unk21, 8, 0);
        gSpriteEntries[0x21 + i].unk2 = p.x;
        gSpriteEntries[0x21 + i].unk4 = p.y;
        gSpriteEntries[0x21 + i].unk8 = 4;
        gSpriteEntries[0x21 + i].unk9 = 4;
    }
}

u32 mf_charge_sparkles_update(u32 bot) {
    u32 i;
    u32 done = 0;
    struct Vec16 p;

    for (i = 0; i <= 7; i++) {
        if (gSpriteEntries[0x21 + i].unk0 == 0) {
            done++;
            continue;
        }
        gSpriteEntries[0x21 + i].unk0 |= 0x8000;
        gSpriteEntries[0x21 + i].unk28++;
        gSpriteEntries[0x21 + i].unk20 -= 8;
        if ((gSpriteEntries[0x21 + i].unk28 & 7) == 0)
            gSpriteEntries[0x21 + i].unk21--;
        p = compute_polar_to_screen_position(gSpriteEntries[0x21 + i].unk20, gSpriteEntries[0x21 + i].unk26 + 16,
                                             gSpriteEntries[bot * 4 + 0x5D].unk2, gSpriteEntries[0x21 + i].unk21, 8, 0);
        gSpriteEntries[0x21 + i].unk2 = p.x;
        gSpriteEntries[0x21 + i].unk4 = p.y;
        if (gSpriteEntries[0x21 + i].unk20 > 0x80)
            gSpriteEntries[0x21 + i].unkB = bot * 4 + 0x59;
        else
            gSpriteEntries[0x21 + i].unkB = 0x81;
        if (gSpriteEntries[0x21 + i].unk21 > gSpriteEntries[bot * 4 + 0x5D].unk4 - 8 &&
            gSpriteEntries[0x21 + i].unk8 != 0x40) {
            gSpriteEntries[0x21 + i].unk8 += 4;
            gSpriteEntries[0x21 + i].unk9 += 4;
        }
        if (gSpriteEntries[0x21 + i].unk21 < gSpriteEntries[bot * 4 + 0x5D].unk4 - 12 &&
            gSpriteEntries[0x21 + i].unk8 != 4) {
            gSpriteEntries[0x21 + i].unk8 -= 4;
            gSpriteEntries[0x21 + i].unk9 -= 4;
        }
        if (gSpriteEntries[0x21 + i].unk20 == 0xC0 &&
            gSpriteEntries[0x21 + i].unk21 < gSpriteEntries[bot * 4 + 0x5D].unk4 - 16)
            clear_battle_sprite_slot(0x21 + i, 1);
    }
    if (done == 8)
        return 1;
    return 0;
}

void battle_action_cleanup(u32 bot) {
    u32 i;
    u32 zero;
    u32 zero2;

    gBattleBots[bot].stateFlags &= ~1;
    gBattleBots[bot].lastAction = gBattleBots[bot].chosenAction;
    if (gBattleBots[bot].chosenAction == 0)
        gBattleBots[bot].lastActionSkill = 0;
    else if (gBattleBots[bot].chosenAction > 3)
        gBattleBots[bot].lastActionSkill = 0;
    else
        gBattleBots[bot].lastActionSkill = gBattleBots[bot].parts[gBattleBots[bot].chosenAction - 1].data[1];
    for (i = 0; i <= 3; i++) {
        gBattleBots[bot].parts[i].unkE = 0;
        gBattleBots[bot].parts[i].unkF = 0;
    }
    zero = 0;
    CpuSet(&zero, gBattleWorkActionVars, 0x05000008);
    zero2 = 0;
    CpuSet(&zero2, gBattleWorkActionVars + 8, 0x05000008);
    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].teamState && (gBattleBots[i].stateFlags & 0x18) &&
            (u8)(gBattleBots[i].lastAction - 1) <= 2 && gBattleBots[i].parts[gBattleBots[i].lastAction - 1].unk11 == 0)
            gBattleBots[i].stateFlags &= 0xE7;
    }
    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].present)
            gBattleBots[i].hitFlags &= 0xF;
    }
    restore_changed_part(bot);
}

void restore_changed_part(u32 bot) {
    u32 zero;

    if (gBattleWork.unk118) {
        gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[0] = gBattleWork.unk11C.data[0];
        gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1] = gBattleWork.unk11C.data[1];
        gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[5] = gBattleWork.unk11C.data[5];
        gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[6] = gBattleWork.unk11C.data[6];
        gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[7] = gBattleWork.unk11C.data[7];
        gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[0xC] = gBattleWork.unk11C.data[0xC];
        gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].unk17 = gBattleWork.unk11C.unk17;
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
    }
    zero = 0;
    CpuSet(&zero, &gBattleWork.unk118, 0x05000009);
}
