// Battle graphics: battle_load_graphics_step (staged decompression of the battle BG and sprite graphics),
// battle message window helpers, clear_battle_ui_tilemaps, Medaforce gauge fill / drain steps.
// Called from battle/robattle and battle/action_steps.

#include "global.h"
#include "constants/battle_seq_sprites.h"
#include "constants/sprites.h"

u32 battle_load_graphics_step(u32 direct) {
    switch (gGameWork.gfxLoadStep) {
    case 0:
        lz_decompress_dispatch(gGaugeFillTiles, (void *)BG_CHAR_ADDR(1));
        lz_decompress_dispatch(gMedaforceLabelTiles, (void *)(BG_VRAM + 0x4140));
        lz_decompress_dispatch(gMedaforceGaugeFrameTiles, (void *)(BG_VRAM + 0x4200));
        gGameWork.gfxLoadStep++;
        break;
    case 1:
        lz_decompress_dispatch(gMedaforceGaugeFrameEndTiles, (void *)(BG_VRAM + 0x4300));
        lz_decompress_dispatch(gMedaforceGaugeTiles, (void *)(BG_VRAM + 0x4400));
        lz_decompress_dispatch(gBattlePillarTiles, (void *)BG_CHAR_ADDR(3));
        lz_decompress_dispatch(gBattlePillarCapTiles, (void *)(BG_VRAM + 0xC600));
        gGameWork.gfxLoadStep++;
        break;
    case 2:
        lz_decompress_dispatch(gRightBotPanelTiles, (void *)(BG_VRAM + 0x4E00));
        lz_decompress_dispatch(gPartsMenuLeftPanelTiles, (void *)(BG_VRAM + 0x5100));
        lz_decompress_dispatch(gMfMenuLeftPanelTiles, (void *)(BG_VRAM + 0x5400));
        lz_decompress_dispatch(gMfMenuRightPanelTiles, (void *)(BG_VRAM + 0x5700));
        lz_decompress_dispatch(gPartsMenuRightPanelTiles, (void *)(BG_VRAM + 0x5A00));
        gGameWork.gfxLoadStep++;
        break;
    case 3:
        lz_decompress_dispatch(gBotActionIconTiles, (void *)(BG_VRAM + 0xC280));
        lz_decompress_dispatch(gBattleUiSpriteTiles, (void *)(OBJ_VRAM0 + 0x2000));
        lz_decompress_dispatch(gMissPopupTiles, (void *)(OBJ_VRAM0 + 0x4E00));
        lz_decompress_dispatch(gBotShadowTiles, (void *)(OBJ_VRAM0 + 0x7F80));
        lz_decompress_dispatch(gSpriteFontTiles, (void *)(OBJ_VRAM0 + 0x7400));
        gGameWork.gfxLoadStep++;
        break;
    case 4:
        lz_decompress_dispatch(gActionSelectPanelTiles, (void *)(BG_VRAM + 0x4600));
        lz_decompress_dispatch(gActionSelectSidePanelTiles, (void *)(BG_VRAM + 0x4800));
        lz_decompress_dispatch(gLeftBotPanelTiles, (void *)(BG_VRAM + 0x4B00));
        gGameWork.gfxLoadStep++;
        break;
    case 5:
        gGameWork.gfxLoadStep++;
        break;
    case 6:
        lz_decompress_dispatch(gBattleNumberSpriteTiles, (void *)(OBJ_VRAM0 + 0x3000));
        lz_decompress_dispatch(gBattleMarkerTilesLz, (void *)(OBJ_VRAM0 + 0x3C00));
        lz_decompress_dispatch(gBattleMarkerAltTilesLz, (void *)(OBJ_VRAM0 + 0x4200));
        gGameWork.gfxLoadStep++;
        break;
    case 7:
        vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG1CNT, 0);
        gGameWork.gfxLoadStep++;
        break;
    case 8:
        if (direct == 0) {
            vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG0CNT, direct);
            load_battlefield_graphics(gBattleWork.battlefield, 1);
            CpuFastSet(gBattleBgPalette8, (void *)BG_PAL_BACKUP_ADDR(8), 8);
            CpuFastSet(gBattleBgPalette10, (void *)BG_PAL_BACKUP_ADDR(10), 8);
            CpuFastSet(gBattleBgPalette11, (void *)BG_PAL_BACKUP_ADDR(11), 8);
            CpuFastSet(gBattleBgPalette12, (void *)BG_PAL_BACKUP_ADDR(12), 8);
            CpuFastSet(gBattleBgPalette13, (void *)BG_PAL_BACKUP_ADDR(13), 8);
            CpuFastSet(gTargetLinePalette, (void *)OBJ_PAL_BACKUP_ADDR(8), 8);
            CpuFastSet(gTargetArrowsPalette, (void *)OBJ_PAL_BACKUP_ADDR(9), 8);
            CpuFastSet(gBattleObjPalette10, (void *)OBJ_PAL_BACKUP_ADDR(10), 8);
            CpuFastSet(gHealNumberPalette, (void *)OBJ_PAL_BACKUP_ADDR(11), 16);
            CpuFastSet(gBattleObjPalettes13, (void *)OBJ_PAL_BACKUP_ADDR(13), 8);
            CpuFastSet(gBattleObjPalettes13 + 0x20, (void *)OBJ_PAL_BACKUP_ADDR(14), 8);
            CpuFastSet(gBattleObjPalettes13 + 0x40, (void *)OBJ_PAL_BACKUP_ADDR(15), 8);
            CpuFastSet(gBattleObjPalette5, (void *)OBJ_PAL_BACKUP_ADDR(5), 8);
        } else {
            load_battlefield_graphics(gBattleWork.battlefield, 0);
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
        gGameWork.gfxLoadStep = 0;
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
        gSpriteEntries[0x78 + i].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0x78 + i].frame_table = 0;
        gSpriteEntries[0x78 + i].y = 0x78;
        gSpriteEntries[0x78 + i].palette = 9;
        gSpriteEntries[0x78 + i].order = 0x80;
        gSpriteEntries[0x78 + i].frame = (i & 3) + 0x616;
        gSpriteEntries[0x78 + i].work[TARGET_ARROW_STEPS] = 0;
        gSpriteEntries[0x78 + i].work[TARGET_ARROW_DISTANCE] = 7 - i;
        gSpriteEntries[0x78 + i].work[TARGET_ARROW_MOVE_FRAME] = 0;
        gSpriteEntries[0x78 + i].work[TARGET_ARROW_DELAY] = i * 2;
        gSpriteEntries[0x78 + i].work[TARGET_ARROW_ANIM_TIMER] = 0;
        gSpriteEntries[0x78 + i].work[TARGET_ARROW_ANIM_FRAME] = i & 3;
        if (bot <= 2) {
            gSpriteEntries[0x78 + i].flags |= SPRITE_FLAG_HFLIP;
            gSpriteEntries[0x78 + i].x = 0x5C;
        } else {
            gSpriteEntries[0x78 + i].flags &= ~SPRITE_FLAG_HFLIP;
            gSpriteEntries[0x78 + i].x = 0x94;
        }
    }
}

#define S gSpriteEntries[0x78 + i]
u32 target_arrows_slide(u32 bot) {
    u32 done = 1;
    u32 i;

    for (i = 0; i <= 7; i++) {
        S.work[TARGET_ARROW_ANIM_TIMER]++;
        if ((S.work[TARGET_ARROW_ANIM_TIMER] & 3) == 0)
            S.frame = (S.work[TARGET_ARROW_ANIM_FRAME] = (S.work[TARGET_ARROW_ANIM_FRAME] + 1) & 3) + 0x616;
        if (S.work[TARGET_ARROW_DISTANCE] != S.work[TARGET_ARROW_STEPS]) {
            done = 0;
            if (S.work[TARGET_ARROW_DELAY] != 0)
                S.work[TARGET_ARROW_DELAY]--;
            else {
                if (bot <= 2)
                    S.x += 4;
                else
                    S.x -= 4;
                S.work[TARGET_ARROW_MOVE_FRAME]++;
                if ((S.work[TARGET_ARROW_MOVE_FRAME] & 1) == 0)
                    S.work[TARGET_ARROW_STEPS]++;
            }
        }
    }
    return done;
}
#undef S

void target_arrows_animate(u32 bot) {
    u32 i;

    for (i = 0; i <= 7; i++) {
        gSpriteEntries[0x78 + i].work[TARGET_ARROW_ANIM_TIMER]++;
        if ((gSpriteEntries[0x78 + i].work[TARGET_ARROW_ANIM_TIMER] & 3) == 0)
            gSpriteEntries[0x78 + i].frame = (gSpriteEntries[0x78 + i].work[TARGET_ARROW_ANIM_FRAME] =
                                                  (gSpriteEntries[0x78 + i].work[TARGET_ARROW_ANIM_FRAME] + 1) & 3) +
                                             0x616;
    }
}

void battle_substeps_reset(void) {
    gBattleWork.substep[0] = 0;
    gBattleWork.substep[1] = 0;
    gBattleWork.substep[2] = 0;
    gBattleWork.substep[3] = 0;
    gBattleWork.substep[4] = 0;
}

void battle_message_reset(void) {
    gBattleWork.messageStep[0] = 0;
    gBattleWork.messageStep[1] = 0;
    gBattleWork.messageStep[2] = 0;
    gBattleWork.messageStep[3] = 0;
    gBattleWork.messageStep[4] = 0;
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
    if (gBattleWork.scratch != 0 && gBattleBots[bot].medaforceGauge != 0x50) {
        gBattleBots[bot].medaforceGauge++;
        gBattleWork.scratch--;
        draw_medaforce_gauge_bar(bot);
        draw_medaforce_gauge_value(bot);
        return 0;
    }
    return 1;
}

u32 medaforce_gauge_drain_step(u32 bot) {
    if (gBattleWork.scratch != 0 && gBattleBots[bot].medaforceGauge != 0) {
        gBattleBots[bot].medaforceGauge--;
        gBattleWork.scratch--;
        draw_medaforce_gauge_bar(bot);
        draw_medaforce_gauge_value(bot);
        return 0;
    }
    return 1;
}

void mf_charge_sparkles_init(u32 bot) {
    u32 i;
    struct Vec16 pos;

    CpuFastSet(gMfChargeSparklePalette, (void *)0x050002C0, 8);
    for (i = 0; i <= 7; i++) {
        clear_battle_sprite_slot(i + 0x21, 1);
        gSpriteEntries[0x21 + i].flags = SPRITE_PRIORITY(gBattleWork.battlefieldParams[3] + 2) | SPRITE_FLAG_VISIBLE |
                                         SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0x21 + i].frame_table = 0;
        gSpriteEntries[0x21 + i].palette = 6;
        gSpriteEntries[0x21 + i].order = 0x81;
        gSpriteEntries[0x21 + i].frame = 0xA10;
        gSpriteEntries[0x21 + i].work[MF_SPARKLE_ANGLE] = i << 5;
        gSpriteEntries[0x21 + i].work[MF_SPARKLE_Y] = gSpriteEntries[BOT_SPRITE_LEGS(bot)].y;
        gSpriteEntries[0x21 + i].work[MF_SPARKLE_FRAME] = 0;
        gSpriteEntries[0x21 + i].work[MF_SPARKLE_PARAM] = i * 4;
        gSpriteEntries[0x21 + i].work[MF_SPARKLE_RADIUS_ADD] = 0;
        pos = compute_polar_to_screen_position(gSpriteEntries[0x21 + i].work[MF_SPARKLE_ANGLE], 16,
                                               gSpriteEntries[BOT_SPRITE_LEGS(bot)].x,
                                               gSpriteEntries[0x21 + i].work[MF_SPARKLE_Y], 8, 0);
        gSpriteEntries[0x21 + i].x = pos.x;
        gSpriteEntries[0x21 + i].y = pos.y;
        gSpriteEntries[0x21 + i].scale_x = 4;
        gSpriteEntries[0x21 + i].scale_y = 4;
    }
}

u32 mf_charge_sparkles_update(u32 bot) {
    u32 i;
    u32 done = 0;
    struct Vec16 pos;

    for (i = 0; i <= 7; i++) {
        if (gSpriteEntries[0x21 + i].flags == 0) {
            done++;
            continue;
        }
        gSpriteEntries[0x21 + i].flags |= SPRITE_FLAG_ENABLED;
        gSpriteEntries[0x21 + i].work[MF_SPARKLE_FRAME]++;
        gSpriteEntries[0x21 + i].work[MF_SPARKLE_ANGLE] -= 8;
        if ((gSpriteEntries[0x21 + i].work[MF_SPARKLE_FRAME] & 7) == 0)
            gSpriteEntries[0x21 + i].work[MF_SPARKLE_Y]--;
        pos = compute_polar_to_screen_position(
            gSpriteEntries[0x21 + i].work[MF_SPARKLE_ANGLE], gSpriteEntries[0x21 + i].work[MF_SPARKLE_RADIUS_ADD] + 16,
            gSpriteEntries[BOT_SPRITE_LEGS(bot)].x, gSpriteEntries[0x21 + i].work[MF_SPARKLE_Y], 8, 0);
        gSpriteEntries[0x21 + i].x = pos.x;
        gSpriteEntries[0x21 + i].y = pos.y;
        if (gSpriteEntries[0x21 + i].work[MF_SPARKLE_ANGLE] > 0x80)
            gSpriteEntries[0x21 + i].order = bot * 4 + 0x59;
        else
            gSpriteEntries[0x21 + i].order = 0x81;
        if (gSpriteEntries[0x21 + i].work[MF_SPARKLE_Y] > gSpriteEntries[BOT_SPRITE_LEGS(bot)].y - 8 &&
            gSpriteEntries[0x21 + i].scale_x != 0x40) {
            gSpriteEntries[0x21 + i].scale_x += 4;
            gSpriteEntries[0x21 + i].scale_y += 4;
        }
        if (gSpriteEntries[0x21 + i].work[MF_SPARKLE_Y] < gSpriteEntries[BOT_SPRITE_LEGS(bot)].y - 12 &&
            gSpriteEntries[0x21 + i].scale_x != 4) {
            gSpriteEntries[0x21 + i].scale_x -= 4;
            gSpriteEntries[0x21 + i].scale_y -= 4;
        }
        if (gSpriteEntries[0x21 + i].work[MF_SPARKLE_ANGLE] == 0xC0 &&
            gSpriteEntries[0x21 + i].work[MF_SPARKLE_Y] < gSpriteEntries[BOT_SPRITE_LEGS(bot)].y - 16)
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
        gBattleBots[bot].parts[i].aiTargetBot = 0;
        gBattleBots[bot].parts[i].aiTargetPart = 0;
    }
    zero = 0;
    CpuSet(&zero, gBattleWorkActionVars, CPU_SET_SRC_FIXED | CPU_SET_32BIT | 0x8);
    zero2 = 0;
    CpuSet(&zero2, gBattleWorkActionVars + 8, CPU_SET_SRC_FIXED | CPU_SET_32BIT | 0x8);
    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].teamState && (gBattleBots[i].stateFlags & 0x18) &&
            (u8)(gBattleBots[i].lastAction - 1) <= 2 && gBattleBots[i].parts[gBattleBots[i].lastAction - 1].armor == 0)
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

    if (gBattleWork.partChanged) {
        gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[0] = gBattleWork.savedPart.data[0];
        gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[1] = gBattleWork.savedPart.data[1];
        gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[5] = gBattleWork.savedPart.data[5];
        gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[6] = gBattleWork.savedPart.data[6];
        gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[7] = gBattleWork.savedPart.data[7];
        gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].data[0xC] = gBattleWork.savedPart.data[0xC];
        gBattleBots[gBattleWork.actor].parts[gBattleWork.actorPart].partId = gBattleWork.savedPart.partId;
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
    }
    zero = 0;
    CpuSet(&zero, &gBattleWork.partChanged, CPU_SET_SRC_FIXED | CPU_SET_32BIT | 0x9);
}
