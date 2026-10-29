// Robattle status screen (command ring slot 2): team sprites and cursors, the selected Medabot's name,
// Medal, parts, abilities and armor, its portrait, and the scroll to the other side's team (L/R).
// Called from battle/robattle.

#include "global.h"
#include "constants/sprites.h"

static void status_switch_side(void);

// Robattle Status screen (ring slot 2, sub-states 0x23-0x26; runtime-checked, re/scratch/b34_status_probe.txt):
// gGameWork.openedFrom = side shown (0 team, 1 opponents, R / L switches), shownId = selected Medabot, D-pad moves it.
// Draws the record's sprite if it is the selected one (shownId) or the one in pageCursor.
static void status_draw_bot_sprite(u32 rec, u32 x, u32 y) {
    u32 slot, side, k;

    if (rec <= 2) {
        slot = rec;
        side = 0;
    } else {
        slot = rec - 3;
        side = 1;
    }
    if (slot == gGameWork.shownId)
        k = 0;
    else if (slot == gGameWork.pageCursor)
        k = 1;
    else
        return;
    get_bot_part_effective_values(rec, gBattleWork.partIds);
    init_battle_medabot_sprites(gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                                gBattleWork.partIds[3], rec, k * 4, x, y, side, 2, k * 4);
}

void position_battle_team_cursors(u32 first, u32 flag) {
    u32 i;
    u32 x, y;

    for (i = 0; i < 3; i++) {
        if (gBattleBots[first + i].teamState) {
            x = gTeamBotScreenPositions[(first + i) * 2];
            y = gTeamBotScreenPositions[(first + i) * 2 + 1];
            if (first + i <= 2) {
                if (flag)
                    x -= 0x68;
            } else {
                if (flag)
                    x += 0x68;
            }
            status_draw_bot_sprite(first + i, x, y);
        }
    }
}

static void setup_bot_battle_sprites_08017A7C(u32 rec, u32 x, u32 y) {
    u32 slot, side, k;

    if (rec <= 2) {
        slot = rec;
        side = 0;
    } else {
        slot = rec - 3;
        side = 1;
    }
    if (slot == gGameWork.shownId)
        k = 0;
    else if (slot == gGameWork.pageCursor)
        k = 1;
    else
        return;
    get_bot_part_effective_values(rec, gBattleWork.partIds);
    setup_battle_sprite_group(gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                              gBattleWork.partIds[3], rec, k * 4, x, y, side, 2, k * 4);
    gSpriteEntries[k * 4 + 1].flags &= (u16)~SPRITE_FLAG_AFFINE;
    gSpriteEntries[k * 4 + 2].flags &= (u16)~SPRITE_FLAG_AFFINE;
}

void status_init_cursor(void) {
    u32 x, y, i;

    gSpriteEntries[8].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[8].frame_table = 0;
    gSpriteEntries[8].palette = 0xE;
    gSpriteEntries[8].order = 0xC0;
    x = gTeamBotScreenPositions[(gGameWork.shownId + gGameWork.openedFrom * 3) * 2];
    y = gTeamBotScreenPositions[(gGameWork.shownId + gGameWork.openedFrom * 3) * 2 + 1];
    if (gGameWork.openedFrom == 0) {
        gSpriteEntries[8].x = x + 16;
        gSpriteEntries[8].y = y;
        gSpriteEntries[8].frame = 0x306;
    } else {
        gSpriteEntries[8].x = x - 16;
        gSpriteEntries[8].y = y;
        gSpriteEntries[8].frame = 0x307;
    }
}

void status_draw_bot_name(void) {
    disable_sprites(9, 13);
    if (gGameWork.openedFrom == 0)
        render_text_sprites_08040DB8(gBattleBots[gGameWork.shownId + gGameWork.openedFrom * 3].medal.name, 9, 0x11, 0xE,
                                     10, 15, 0, 0);
    else
        render_text_sprites_08040DB8(gBattleBots[gGameWork.shownId + gGameWork.openedFrom * 3].medal.name, 9, 3, 0xE,
                                     10, 15, 0, 0);
}

static void status_draw_lr_button(u32 hidden) {
    if (hidden == 0) {
        if (gGameWork.openedFrom == 0)
            draw_tile_block(2, 2, 0x1A, 0x11, REG_BG0CNT, 0x8304);
        else
            draw_tile_block(2, 2, 2, 0x11, REG_BG0CNT, 0x8300);
    } else {
        if (gGameWork.openedFrom == 0)
            vram_fill_tilemap_rect(2, 2, 0x1A, 0x11, REG_BG0CNT, 0);
        else
            vram_fill_tilemap_rect(2, 2, 2, 0x11, REG_BG0CNT, 0);
    }
}

void status_blink_lr_button(void) {
    gGameWork.stepTimer++;
    if (gGameWork.stepTimer & 8)
        status_draw_lr_button(0);
    else
        status_draw_lr_button(1);
}

// Status screen: column of 5 row icons at BG1 (9, 2..10)
void status_draw_row_icons(void) {
    u32 i, y;

    for (i = 0, y = 2; i <= 4; y += 2, i++)
        draw_tile_block(2, 2, 9, y, REG_BG1CNT, i * 4 + 0xC370);
}

void status_load_medal_icon(void) {
    CpuFastSet(gMedalIconTiles + gBattleBots[gGameWork.shownId + gGameWork.openedFrom * 3].medal.graphicId * 0x80,
               (void *)(BG_VRAM + 0x7800), 0x20);
}

void status_draw_medal_name(void) {
    disable_sprites(0x16, 10);
    memcpy_bytes_0803F63C(
        (const void *)gMedalNames[gBattleBots[gGameWork.shownId + gGameWork.openedFrom * 3].medal.graphicId],
        gGameWork.textBuf, 11);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x16, 0xD, 2, 7, 12, 1, 2);
}

void status_draw_part_names(void) {
    u32 i;

    disable_sprites(0x20, 0x38);
    for (i = 0; i <= 3; i++) {
        memcpy_bytes_08041D04(
            (const void *)
                gMedapartNames[0][gBattleBots[gGameWork.shownId + gGameWork.openedFrom * 3].parts[i].partId * 4 + i],
            gGameWork.textBuf, 15);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x20 + i * 14, 0xD, 4 + i * 2, 10, 13, 1, 2);
    }
}

void status_draw_part_ability_icons(void) {
    u32 i;

    for (i = 0; i <= 3; i++) {
        load_part_data(gBattleBots[gGameWork.shownId + gGameWork.openedFrom * 3].parts[i].partId, i,
                       &gGameWork.partAbility);
        memcpy_bytes_08041D04(gMedalRecords[gBattleBots[gGameWork.shownId + gGameWork.openedFrom * 3].medal.graphicId],
                              gGameWork.medalGfxRecord, 16);
        if (gGameWork.partAbility == gGameWork.medalGfxRecord[1])
            draw_tile_block(2, 2, 0xB, i * 2 + 4, REG_BG1CNT, gGameWork.medalGfxRecord[7] * 4 + 0xD340);
        else
            draw_tile_block(2, 2, 0xB, i * 2 + 4, REG_BG1CNT, 0xD340);
    }
}

// Status screen ARMOR column: parts[i].armor (current) / data[4] (max), grey when broken (runtime-checked "35/35")
void status_draw_part_armor(void) {
    u32 i;
    u16 pal;

    for (i = 0; i <= 3; i++) {
        pal = gBattleBots[gGameWork.shownId + gGameWork.openedFrom * 3].parts[i].armor ? 0xA000 : 0xB000;
        draw_number_tall_bgcnt(gBattleBots[gGameWork.shownId + gGameWork.openedFrom * 3].parts[i].armor, 0x17,
                               i * 2 + 4, 3, REG_BG1CNT, pal | 0x390);
        draw_tile_block(1, 2, 0x1A, i * 2 + 4, REG_BG1CNT, pal | 0x3A4);
        draw_number_tall_bgcnt(gBattleBots[gGameWork.shownId + gGameWork.openedFrom * 3].parts[i].data[4], 0x1B,
                               i * 2 + 4, 3, REG_BG1CNT, pal | 0x390);
    }
}

void set_portrait_parts(u8 head, u8 right_arm, u8 left_arm, u8 legs) {
    gGameWork.shownHead = head;
    gGameWork.shownRightArm = right_arm;
    gGameWork.shownLeftArm = left_arm;
    gGameWork.shownLegs = legs;
}

void status_init_portrait(void) {
    struct SpriteTree *obj = (struct SpriteTree *)SPRITE_TREE_ADDR;
    u8 *oam_buf;
    u8 *slots;
    u32 fill;

    mem_fill8((u8 *)obj, 0xD0, 0);
    oam_buf = (u8 *)SPRITE_TREE_OAMS_ADDR(0);
    mem_fill8(oam_buf, 0x800, 0);
    slots = (u8 *)0x020268D0;
    mem_fill8(slots, 0x60, 0);
    gGameWork.noAffineSprites = 1;
    gVBlankOamMode = 2;
    gSpriteWork = (struct SpriteWork *)SPRITE_WORK_ADDR;
    fill = 0;
    CpuFastSet(&fill, (void *)SPRITE_WORK_ADDR, 0x01000426);
    gMedabotSpriteSlots = (struct MedabotSpriteSlot *)slots;
    init_sprite_tree(obj, (u8 *)gSpriteWork, (struct SpriteNodeDesc **)gMedabotSpriteNodeDescs,
                     (struct SpriteNodeOam *)oam_buf);
    obj->oams = (struct SpriteNodeOam *)oam_buf;
    setup_medabot_part_sprites(gSpriteWork->oamBuf, obj, gGameWork.shownHead, gGameWork.shownRightArm,
                               gGameWork.shownLeftArm, gGameWork.shownLegs, 0x28, 0x28, 0x1C2, 8, 1, 0);
}

void status_reset_portrait(void) {
    struct SpriteTree *obj = (struct SpriteTree *)SPRITE_TREE_ADDR;
    u32 fill;

    obj->oams = (struct SpriteNodeOam *)SPRITE_TREE_OAMS_ADDR(0);
    setup_medabot_part_sprites(gSpriteWork->oamBuf, obj, gGameWork.shownHead, gGameWork.shownRightArm,
                               gGameWork.shownLeftArm, gGameWork.shownLegs, 0x28, 0x28, 0x1C2, 8, 1, 0);
    fill = 0x200;
    CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
    gSpriteWork->oamCount = 0;
    gSpriteWork->affineIdx = 0;
}

void status_update_portrait(void) {
    setup_medabot_part_sprites(gSpriteWork->oamBuf, (struct SpriteTree *)SPRITE_TREE_ADDR, gGameWork.shownHead,
                               gGameWork.shownRightArm, gGameWork.shownLeftArm, gGameWork.shownLegs, 0x44, 0x2A, 0x1C2,
                               8, 5, 0);
}

u32 status_cursor_x(void) {
    u8 x = gTeamBotScreenPositions[(gGameWork.shownId + gGameWork.openedFrom * 3) * 2];

    if (gGameWork.openedFrom == 0)
        return x + 16;
    else
        return x - 16;
}

void scroll_bg3_diagonal(void) {
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

// Status screen: advance pageCursor to the next Medabot slot (0-2), skipping the selected one
void status_next_other_slot(void) {
    if (gGameWork.pageCursor == 2)
        gGameWork.pageCursor = 0;
    else
        gGameWork.pageCursor++;
    if (gGameWork.shownId == gGameWork.pageCursor) {
        if (gGameWork.shownId == 2)
            gGameWork.pageCursor = 0;
        else
            gGameWork.pageCursor++;
    }
}

void status_draw_team_sprites(void) {
    u32 i, rec;
    struct BattleBot *recs;

    disable_sprites(4, 1);
    disable_sprites(5, 1);
    disable_sprites(6, 1);
    disable_sprites(7, 1);
    for (i = 0, recs = gBattleBots; i <= 2; i++) {
        rec = gGameWork.openedFrom * 3 + i;
        if (recs[rec].teamState && i != gGameWork.shownId)
            status_draw_bot_sprite(rec, gTeamBotScreenPositions[rec * 2], gTeamBotScreenPositions[rec * 2 + 1]);
    }
    update_battle_sprite_orbiting_positions(0, gGameWork.shownId + gGameWork.openedFrom * 3, gGameWork.openedFrom);
}

void status_select_input(void) {
    u8 moved = 0;
    u32 x, y;
    s32 slot;
    u32 base;

    x = gTeamBotScreenPositions[(gGameWork.shownId + gGameWork.openedFrom * 3) * 2];
    y = gTeamBotScreenPositions[(gGameWork.shownId + gGameWork.openedFrom * 3) * 2 + 1];
    slot = gGameWork.shownId;
    base = gGameWork.openedFrom * 3;
    if (gGameWork.openedFrom == 0) {
        if (KEYS_LO(gRepeatKeys) & (DPAD_LEFT | DPAD_DOWN)) {
            if (gGameWork.shownId != 2) {
                if (gBattleBots[slot + 1 + base].teamState) {
                    setup_bot_battle_sprites_08017A7C(0, x, y);
                    gGameWork.shownId++;
                    moved = 1;
                } else if (gGameWork.shownId == 0 && gBattleBots[slot + 2 + base].teamState) {
                    setup_bot_battle_sprites_08017A7C(0, x, y);
                    gGameWork.shownId = 2;
                    moved = 1;
                }
            }
        } else if (KEYS_LO(gRepeatKeys) & (DPAD_RIGHT | DPAD_UP)) {
            if (gGameWork.shownId != 0) {
                if (gBattleBots[slot - 1 + base].teamState) {
                    setup_bot_battle_sprites_08017A7C(0, x, y);
                    gGameWork.shownId--;
                    moved = 1;
                } else if (gGameWork.shownId == 2 && gBattleBots[slot - 2 + base].teamState) {
                    setup_bot_battle_sprites_08017A7C(0, x, y);
                    gGameWork.shownId = 0;
                    moved = 1;
                }
            }
        }
    } else {
        if (KEYS_LO(gRepeatKeys) & (DPAD_LEFT | DPAD_UP)) {
            if (gGameWork.shownId != 0) {
                if (gBattleBots[slot - 1 + base].teamState) {
                    setup_bot_battle_sprites_08017A7C(0, x, y);
                    gGameWork.shownId--;
                    moved = 1;
                } else if (gGameWork.shownId == 2 && gBattleBots[slot - 2 + base].teamState) {
                    setup_bot_battle_sprites_08017A7C(0, x, y);
                    gGameWork.shownId = 0;
                    moved = 1;
                }
            }
        } else if (KEYS_LO(gRepeatKeys) & (DPAD_RIGHT | DPAD_DOWN)) {
            if (gGameWork.shownId != 2) {
                if (gBattleBots[slot + 1 + base].teamState) {
                    setup_bot_battle_sprites_08017A7C(0, x, y);
                    gGameWork.shownId++;
                    moved = 1;
                } else if (gGameWork.shownId == 0 && gBattleBots[slot + 2 + base].teamState) {
                    setup_bot_battle_sprites_08017A7C(0, x, y);
                    gGameWork.shownId = 2;
                    moved = 1;
                }
            }
        }
    }
    if (moved) {
        play_sound_effect(2);
        status_init_cursor();
        status_draw_bot_name();
        status_load_medal_icon();
        status_draw_medal_name();
        status_draw_part_names();
        status_draw_part_ability_icons();
        status_draw_part_armor();
        get_bot_part_effective_values(gGameWork.shownId + gGameWork.openedFrom * 3, gBattleWork.partIds);
        set_portrait_parts(gBattleWork.partIds[0], gBattleWork.partIds[1], gBattleWork.partIds[2],
                           gBattleWork.partIds[3]);
        status_reset_portrait();
        position_battle_team_cursors(gGameWork.openedFrom * 3, 0);
        battle_sprite_group_set_anim(0, 8);
        draw_tile_block(2, 2, 0xB, 2, REG_BG1CNT, 0x63C0);
    }
}

void status_begin_side_change(void) {
    u32 x = gTeamBotScreenPositions[(gGameWork.shownId + gGameWork.openedFrom * 3) * 2];
    u32 y = gTeamBotScreenPositions[(gGameWork.shownId + gGameWork.openedFrom * 3) * 2 + 1];

    setup_bot_battle_sprites_08017A7C(gGameWork.shownId + gGameWork.openedFrom * 3, x, y);
    clear_battle_sprite_slot(8, 1);
    status_draw_lr_button(1);
}

u32 status_side_change_scroll_out(void) {
    u32 i, rec, x;
    struct BattleBot *recs;

    disable_sprites(4, 1);
    disable_sprites(5, 1);
    disable_sprites(6, 1);
    disable_sprites(7, 1);
    if (gGameWork.openedFrom == 0) {
        for (i = 0, recs = gBattleBots; i <= 2; i++) {
            rec = gGameWork.openedFrom * 3 + i;
            if (recs[rec].teamState) {
                x = gTeamBotScreenPositions[rec * 2] - gGameWork.medalRow * 8;
                status_draw_bot_sprite(rec, x, gTeamBotScreenPositions[rec * 2 + 1]);
            }
        }
        for (i = 0; i <= 12; i++)
            gSpriteEntries[9 + i].x -= 8;
        read_vram_tilemap_rect(13, 6, 16 - gGameWork.medalRow, 13, REG_BG0CNT, (void *)0x02020000);
        write_vram_tilemap_rect(13, 6, 15 - gGameWork.medalRow, 13, REG_BG0CNT, (void *)0x02020000);
    } else {
        for (i = 0, recs = gBattleBots; i <= 2; i++) {
            rec = gGameWork.openedFrom * 3 + i;
            if (recs[rec].teamState) {
                register u32 k asm("r0") = rec * 2;
                x = gTeamBotScreenPositions[k] + gGameWork.medalRow * 8;
                status_draw_bot_sprite(rec, x, gTeamBotScreenPositions[k + 1]);
            }
        }
        for (i = 0; i <= 12; i++)
            gSpriteEntries[9 + i].x += 8;
        read_vram_tilemap_rect(13, 6, gGameWork.medalRow + 1, 13, REG_BG0CNT, (void *)0x02020000);
        write_vram_tilemap_rect(13, 6, gGameWork.medalRow + 2, 13, REG_BG0CNT, (void *)0x02020000);
    }
    if (++gGameWork.medalRow == 14) {
        status_switch_side();
        return 1;
    }
    return 0;
}

static void status_switch_side(void) {
    gGameWork.shownId = 0;
    gGameWork.openedFrom ^= 1;
    position_battle_team_cursors(gGameWork.openedFrom * 3, 1);
}

u32 status_side_change_scroll_in(void) {
    u32 i, rec, x;
    struct BattleBot *recs;

    disable_sprites(4, 1);
    disable_sprites(5, 1);
    disable_sprites(6, 1);
    disable_sprites(7, 1);
    if (gGameWork.openedFrom == 0) {
        for (i = 0, recs = gBattleBots; i <= 2; i++) {
            rec = gGameWork.openedFrom * 3 + i;
            if (recs[rec].teamState) {
                x = gTeamBotScreenPositions[rec * 2] - (13 - gGameWork.medalRow) * 8;
                status_draw_bot_sprite(rec, x, gTeamBotScreenPositions[rec * 2 + 1]);
            }
        }
    } else {
        for (i = 0, recs = gBattleBots; i <= 2; i++) {
            rec = gGameWork.openedFrom * 3 + i;
            if (recs[rec].teamState) {
                x = gTeamBotScreenPositions[rec * 2] + (13 - gGameWork.medalRow) * 8;
                status_draw_bot_sprite(rec, x, gTeamBotScreenPositions[rec * 2 + 1]);
            }
        }
    }
    if (++gGameWork.medalRow == 14) {
        status_init_cursor();
        status_draw_bot_name();
        status_load_medal_icon();
        status_draw_medal_name();
        status_draw_part_names();
        status_draw_part_ability_icons();
        status_draw_part_armor();
        return 1;
    }
    return 0;
}
