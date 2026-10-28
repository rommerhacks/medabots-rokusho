// Sprites and tilemap windows for action effects: the target's armor panel on BG1 (part icons, bars, current / max
// armor numbers: armor_panel_*), armor drain per frame, hit sparks and damage digits placed at a part through the
// offset tables gPartFlyStepsHead..gSpriteHopYSteps, and the OAM / animation-frame helpers used by every skill module.

#include "global.h"
#include "constants/skill_sprites.h"
#include "constants/sprites.h"

static void armor_bar_draw(u32 x, u32 y, u32 w, u32 max, u32 cur);

void armor_panel_draw_icons(u32 side) {
    u32 x = 2;
    if (side == 0)
        x = 0x10;
    draw_tile_block(2, 2, x, 1, REG_BG1CNT, 0xB340);
    draw_tile_block(2, 2, x, 4, REG_BG1CNT, 0xB344);
    draw_tile_block(2, 2, x, 7, REG_BG1CNT, 0xB348);
    draw_tile_block(2, 2, x, 10, REG_BG1CNT, 0xB34C);
}

void armor_panel_draw_frame(u32 side) {
    u32 x = 4;
    if (side == 0)
        x = 0x12;
    set_tilemap_and_decompress_bg(x, 0, gArmorPanelFrameTilemap, REG_BG1CNT, 0x329);
}

void armor_panel_draw_bars(u32 side, u32 rec) {
    u32 x = 5;
    if (side == 0)
        x = 0x13;
    armor_bar_draw(x, 1, 0x40, gBattleBots[rec].parts[0].data[4], gBattleBots[rec].parts[0].armor);
    armor_bar_draw(x, 4, 0x40, gBattleBots[rec].parts[1].data[4], gBattleBots[rec].parts[1].armor);
    armor_bar_draw(x, 7, 0x40, gBattleBots[rec].parts[2].data[4], gBattleBots[rec].parts[2].armor);
    armor_bar_draw(x, 10, 0x40, gBattleBots[rec].parts[3].data[4], gBattleBots[rec].parts[3].armor);
}

static void armor_bar_draw(u32 x, u32 y, u32 w, u32 max, u32 cur) {
    u32 full, rem, col, i;

    full = scale_to_bar_fill(w, max, cur);
    rem = full & 0xFFFF;
    full >>= 16;

    if (cur != 0 && full == 0 && rem == 0)
        rem = 1;
    col = 0;
    for (i = 0; i < full; i++) {
        draw_tile_block(1, 1, x + col, y, REG_BG1CNT, 0xA328);
        col++;
    }
    if (rem) {
        draw_tile_block(1, 1, x + col, y, REG_BG1CNT, 0xA320 + rem);
        col++;
    }
    for (i = col; i <= 7; i++) {
        draw_tile_block(1, 1, x + col, y, REG_BG1CNT, 0xA320);
        col++;
    }
}

void armor_panel_draw_numbers(u32 side, u32 rec) {
    u32 x;
    u32 y;

    x = 6;
    if (side == 0)
        x = 0x14;
    y = 2;
    if (gBattleBots[rec].parts[0].armor != 0) {
        draw_number_bgcnt(gBattleBots[rec].parts[0].armor, x, y, 3, REG_BG1CNT, 0xA330);
        draw_number_bgcnt(gBattleBots[rec].parts[0].data[4], x + 4, y, 3, REG_BG1CNT, 0xA330);
    } else {
        draw_number_bgcnt(gBattleBots[rec].parts[0].armor, x, y, 3, REG_BG1CNT, 0x8330);
        draw_number_bgcnt(gBattleBots[rec].parts[0].data[4], x + 4, y, 3, REG_BG1CNT, 0x8330);
    }
    if (gBattleBots[rec].parts[1].armor != 0) {
        draw_number_bgcnt(gBattleBots[rec].parts[1].armor, x, y + 3, 3, REG_BG1CNT, 0xA330);
        draw_number_bgcnt(gBattleBots[rec].parts[1].data[4], x + 4, y + 3, 3, REG_BG1CNT, 0xA330);
    } else {
        draw_number_bgcnt(gBattleBots[rec].parts[1].armor, x, y + 3, 3, REG_BG1CNT, 0x8330);
        draw_number_bgcnt(gBattleBots[rec].parts[1].data[4], x + 4, y + 3, 3, REG_BG1CNT, 0x8330);
    }
    if (gBattleBots[rec].parts[2].armor != 0) {
        draw_number_bgcnt(gBattleBots[rec].parts[2].armor, x, y + 6, 3, REG_BG1CNT, 0xA330);
        draw_number_bgcnt(gBattleBots[rec].parts[2].data[4], x + 4, y + 6, 3, REG_BG1CNT, 0xA330);
    } else {
        draw_number_bgcnt(gBattleBots[rec].parts[2].armor, x, y + 6, 3, REG_BG1CNT, 0x8330);
        draw_number_bgcnt(gBattleBots[rec].parts[2].data[4], x + 4, y + 6, 3, REG_BG1CNT, 0x8330);
    }
    if (gBattleBots[rec].parts[3].armor != 0) {
        draw_number_bgcnt(gBattleBots[rec].parts[3].armor, x, y + 9, 3, REG_BG1CNT, 0xA330);
        draw_number_bgcnt(gBattleBots[rec].parts[3].data[4], x + 4, y + 9, 3, REG_BG1CNT, 0xA330);
    } else {
        draw_number_bgcnt(gBattleBots[rec].parts[3].armor, x, y + 9, 3, REG_BG1CNT, 0x8330);
        draw_number_bgcnt(gBattleBots[rec].parts[3].data[4], x + 4, y + 9, 3, REG_BG1CNT, 0x8330);
    }
}

u32 effect_sprite_fly_to_part(u32 slot, u32 part) {
    s16 dx, dy;
    struct SpriteEntry *base = gSpriteEntries;
    struct SpriteEntry *sprite = &base[slot];
    u8 *frame;

    if (!(sprite->flags & SPRITE_FLAG_ENABLED) || *(frame = &sprite->work[FX_SPR_STEP]) == 0x10)
        return 1;
    switch (part) {
    case 0:
        dx = gPartFlyStepsHead[*frame << 1];
        dy = gPartFlyStepsHead[*frame * 2 + 1];
        break;
    case 1:
        dx = gPartFlyStepsRightArm[*frame << 1];
        dy = gPartFlyStepsRightArm[*frame * 2 + 1];
        break;
    case 2:
        dx = gPartFlyStepsLeftArm[*frame << 1];
        dy = gPartFlyStepsLeftArm[*frame * 2 + 1];
        break;
    case 3:
        dx = gPartFlyStepsLegs[*frame << 1];
        dy = gPartFlyStepsLegs[*frame * 2 + 1];
        break;
    }
    gSpriteEntries[slot].x = (dx + gSpriteEntries[slot].x) & 0x1FF;
    gSpriteEntries[slot].y = (dy + gSpriteEntries[slot].y) & 0xFF;
    gSpriteEntries[slot].work[FX_SPR_STEP]++;
    return 0;
}

void hit_sparks_spawn(u32 slot, u32 part, s16 x, s16 y) {
    u32 i;
    s32 spark_pos, part_pos;

    clear_battle_sprite_slot(slot, 4);
    for (i = 0; i <= 3; i++) {
        gSpriteEntries[slot + i].flags = SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[slot + i].frame_table = 0;
        gSpriteEntries[slot + i].palette = 0xE;
        gSpriteEntries[slot + i].order = 0x80;
        gSpriteEntries[slot + i].work[FX_SPR_DELAY] = i * 8;
        part_pos = gPartSpriteOffsets[part << 1] + x;
        spark_pos = gHitSparkOffsets[i * 2];
        spark_pos += part_pos;
        gSpriteEntries[slot + i].x = spark_pos & 0x1FF;
        part_pos = gPartSpriteOffsets[part * 2 + 1] + y;
        spark_pos = gHitSparkOffsets[i * 2 + 1];
        spark_pos += part_pos;
        gSpriteEntries[slot + i].y = spark_pos & 0xFF;
        battle_sprite_anim_init(gBattleSpriteAnimScripts[29], slot + i);
    }
}

u32 hit_sparks_update(u32 slot) {
    u32 done = 1;
    u32 i;
    u8 n;

    for (i = 0; i <= 3; i++) {
        if (gSpriteEntries[slot + i].flags != 0) {
            if (gSpriteEntries[slot + i].work[FX_SPR_DELAY] == 0) {
                gSpriteEntries[slot + i].flags |= SPRITE_FLAG_ENABLED | SPRITE_FLAG_PART_PALETTE;
                gSpriteEntries[slot + i].palette = 0xE;
                process_sprite_anim_commands(gBattleSpriteAnimScripts[29], n = slot + i);
                if (gSpriteEntries[slot + i].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
                    clear_battle_sprite_slot(n, 1);
                else
                    done = 0;
            } else {
                gSpriteEntries[slot + i].work[FX_SPR_DELAY]--;
                done = 0;
            }
        }
    }
    return done;
}

void damage_digits_spawn(u8 *digits, u32 slot, u32 part, s16 x, s16 y) {
    u32 i = 0;
    s32 pos_x;
    s32 pos_y;
    for (; i <= 4; i++) {
        if (digits[i] == 0xFE)
            return;
        gSpriteEntries[slot + i].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) |
                                         SPRITE_FLAG_AFFINE | SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[slot + i].frame_table = 0;
        pos_x = x;
        pos_x += gPartSpriteOffsets[part << 1];
        gSpriteEntries[slot + i].x = pos_x & 0x1FF;
        pos_y = y;
        pos_y += gPartSpriteOffsets[part * 2 + 1];
        gSpriteEntries[slot + i].y = pos_y & 0xFF;
        gSpriteEntries[slot + i].order = 0x80;
        gSpriteEntries[slot + i].frame = digits[i] + 0x2D00;
        gSpriteEntries[slot + i].work[FX_SPR_STEP] = 0;
        gSpriteEntries[slot + i].scale_y = 0x40;
        gSpriteEntries[slot + i].scale_x = 0x40;
        gSpriteEntries[slot + i].palette = 0xE;
        switch (digits[6]) {
        case 2:
            gSpriteEntries[slot + i].x = 0xFFFC + gSpriteEntries[slot + i].x + i * 8;
            break;
        case 3:
            gSpriteEntries[slot + i].x = 0xFFF8 + gSpriteEntries[slot + i].x + i * 8;
            break;
        case 4:
            gSpriteEntries[slot + i].x = 0xFFF4 + gSpriteEntries[slot + i].x + i * 8;
            break;
        }
    }
}

void setup_battle_sprite_oam_entries(u8 *buf, u32 slot, u32 part, s16 x, s16 y) {
    u32 i = 0;
    s32 pos_x;
    s32 pos_y;
    for (; i <= 4; i++) {
        if (buf[i] == 0xFE)
            return;
        gSpriteEntries[slot + i].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[slot + i].frame_table = 0;
        pos_x = x;
        pos_x += gPartSpriteOffsets[part << 1];
        gSpriteEntries[slot + i].x = pos_x & 0x1FF;
        pos_y = y;
        pos_y += gPartSpriteOffsets[part * 2 + 1];
        gSpriteEntries[slot + i].y = pos_y & 0xFF;
        gSpriteEntries[slot + i].order = 0x80;
        gSpriteEntries[slot + i].frame = buf[i] + 0x2D00;
        gSpriteEntries[slot + i].work[FX_SPR_STEP] = 0;
        gSpriteEntries[slot + i].palette = 0xE;
        switch (buf[6]) {
        case 2:
            gSpriteEntries[slot + i].x = 0xFFFC + gSpriteEntries[slot + i].x + i * 8;
            break;
        case 3:
            gSpriteEntries[slot + i].x = 0xFFF8 + gSpriteEntries[slot + i].x + i * 8;
            break;
        case 4:
            gSpriteEntries[slot + i].x = 0xFFF4 + gSpriteEntries[slot + i].x + i * 8;
            break;
        }
    }
}

u32 advance_sprite_anim_frame(u32 sprite, u32 stretch) {
    s32 frame;
    if (!(gSpriteEntries[sprite].flags & SPRITE_FLAG_ENABLED) || gSpriteEntries[sprite].work[FX_SPR_STEP] == 0x10)
        return 1;
    gSpriteEntries[sprite].y =
        (gSpriteEntries[sprite].y + gSpriteHopYSteps[gSpriteEntries[sprite].work[FX_SPR_STEP]]) & 0xFF;
    frame = gSpriteEntries[sprite].work[FX_SPR_STEP] + 1;
    gSpriteEntries[sprite].work[FX_SPR_STEP] = frame;
    if (stretch)
        gSpriteEntries[sprite].scale_y = frame * 4 + 0x40;
    return 0;
}

u32 advance_sprite_group_anims(u8 *digits, u32 slot) {
    u32 busy = 0;
    u32 i = 0;

    goto test;
    for (;;) {
        i++;
    test:
        if (i > 4 || digits[i] == 0xFE)
            goto done;
        if (advance_sprite_anim_frame(slot + i, 1))
            busy = 1;
    }
done:
    return busy;
}

u32 sprite_group_rise_step(u8 *buf, u32 slot) {
    u32 busy = 0;
    u32 i = 0;

    goto test;
    for (;;) {
        i++;
    test:
        if (i > 4 || buf[i] == 0xFE)
            goto done;
        if (advance_sprite_anim_frame(slot + i, 0))
            busy = 1;
    }
done:
    return busy;
}

void battle_set_damage_break_part(u32 rec, u32 part) {
    gBattleWork.appliedAmount = gBattleBots[rec].parts[part].armor;
    gBattleWork.cappedAmount = gBattleBots[rec].parts[part].armor;
    gBattleWork.partBroken = 1;
}

u32 armor_drain_step(u16 *amount, u32 rec, u32 part) {
    u8 *n = (u8 *)amount;
    if (gBattleBots[rec].parts[part].armor != 0 && *n != 0) {
        (*n)--;
        gBattleBots[rec].parts[part].armor--;
        return 0;
    }
    return 1;
}

void armor_panel_clear(u32 side) {
    u32 y = 2;
    if (side == 0)
        y = 0x10;
    vram_fill_tilemap_rect(0xC, 0xD, y, 0, REG_BG1CNT, 0);
}

void effect_sprite_spawn_at_part(u32 slot, u32 part, s16 x, s16 y, u32 n) {
    struct SpriteEntry *sprite;
    struct SpriteEntry *base;
    s32 pos_x, pos_y;

    clear_battle_sprite_slot(slot, 1);
    base = gSpriteEntries;
    sprite = &base[slot];
    sprite->flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    sprite->frame_table = 0;
    sprite->palette = 0xE;
    sprite->order = 0x80;
    pos_x = gPartSpriteOffsets[part << 1] + x;
    sprite->x = pos_x & 0x1FF;
    pos_y = gPartSpriteOffsets[part * 2 + 1] + y;
    sprite->y = pos_y & 0xFF;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[n], slot);
}
