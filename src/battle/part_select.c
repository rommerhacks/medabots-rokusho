// Robattle part select (after choosing Attack on the command ring): the head / arms / legs icons around the
// centre, cursor input and blinking, the part's name, skill type and skill name, the head's uses left.
// Called from battle/robattle.

#include "global.h"
#include "constants/sprites.h"

void part_select_init_center_icon(void) {
    gSpriteEntries[0].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[0].frame_table = 0;
    gSpriteEntries[0].x = 0x78;
    gSpriteEntries[0].y = 0x78;
    gSpriteEntries[0].palette = 0xA;
    gSpriteEntries[0].order = 0xC0;
    gSpriteEntries[0].frame = gPartSelectCenterFrames[gBattleWork.partCursor] + 0x600;
}

void part_select_init_head_icon(u32 lit) {
    gSpriteEntries[1].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[1].frame_table = 0;
    gSpriteEntries[1].x = 0x78;
    gSpriteEntries[1].y = 0x6C;
    gSpriteEntries[1].palette = 0xA;
    gSpriteEntries[1].order = 0xC0;
    gSpriteEntries[1].frame = lit * 4 + 0x604;
}

void part_select_init_right_arm_icon(u32 lit) {
    gSpriteEntries[2].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[2].frame_table = 0;
    gSpriteEntries[2].x = 0x6C;
    gSpriteEntries[2].y = 0x78;
    gSpriteEntries[2].palette = 0xA;
    gSpriteEntries[2].order = 0xC0;
    gSpriteEntries[2].frame = lit * 4 + 0x605;
}

void part_select_init_left_arm_icon(u32 lit) {
    gSpriteEntries[3].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[3].frame_table = 0;
    gSpriteEntries[3].x = 0x84;
    gSpriteEntries[3].y = 0x78;
    gSpriteEntries[3].palette = 0xA;
    gSpriteEntries[3].order = 0xC0;
    gSpriteEntries[3].frame = lit * 4 + 0x606;
}

void part_select_init_bottom_icon(u32 lit) {
    gSpriteEntries[4].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[4].frame_table = 0;
    gSpriteEntries[4].x = 0x78;
    gSpriteEntries[4].y = 0x84;
    gSpriteEntries[4].palette = 0xA;
    gSpriteEntries[4].order = 0xC0;
    gSpriteEntries[4].frame = lit * 4 + 0x607;
}

void part_select_blink_selected_icon(void) {
    switch (gBattleWork.partCursor) {
    case 0:
        if (gGameWork.stepCounter & 8)
            part_select_init_bottom_icon(1);
        else
            part_select_init_bottom_icon(0);
        break;
    case 1:
        if (gGameWork.stepCounter & 8)
            part_select_init_head_icon(1);
        else
            part_select_init_head_icon(0);
        break;
    case 2:
        if (gGameWork.stepCounter & 8)
            part_select_init_right_arm_icon(1);
        else
            part_select_init_right_arm_icon(0);
        break;
    case 3:
        if (gGameWork.stepCounter & 8)
            part_select_init_left_arm_icon(1);
        else
            part_select_init_left_arm_icon(0);
        break;
    }
}

// Robattle sub-state 0x12, Medapart select (runtime-checked from battle_start.ss0): UP head (1),
// LEFT right arm (2), RIGHT left arm (3), DOWN none (0) in gBattleWork.partCursor.
void part_select_input(void) {
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
        part_select_init_center_icon();
        part_select_init_head_icon(1);
        part_select_init_right_arm_icon(1);
        part_select_init_left_arm_icon(1);
        part_select_init_bottom_icon(1);
        part_select_draw_part_name();
        part_select_draw_skill_type();
        part_select_draw_skill_name();
        part_select_draw_head_uses();
        target_marker_hide();
        target_marker_show();
    }
}

void part_select_draw_part_name(void) {
    s32 k;

    disable_sprites(0x1F, 14);
    k = gBattleWork.partCursor;
    if (k == 0)
        memcpy_bytes_08041D04(gBattleMenuTexts[3], gGameWork.textBuf, 14);
    else if (k >= 0) {
        if (k <= 3)
            memcpy_bytes_08041D04(
                (const void *)gMedapartNames[0][gBattleBots[gBattleWork.commandBot].parts[k - 1].partId * 4 + k - 1],
                gGameWork.textBuf, 15);
    }
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x1F, 10, 0x11, 10, 13, 0, 0);
}

void part_select_draw_skill_type(void) {
    s32 k;

    disable_sprites(0x2D, 13);
    k = gBattleWork.partCursor;
    if (k == 0)
        fill_text_blank(gGameWork.textBuf, 13);
    else if (k >= 0) {
        if (k <= 3) {
            if (gBattleBots[gBattleWork.commandBot].parts[k - 1].armor == 0)
                memcpy_bytes_08041D04(gBattleMenuTexts[0], gGameWork.textBuf, 14);
            else if (gBattleBots[gBattleWork.commandBot].statusType == 0x2B &&
                     k == gBattleBots[gBattleWork.commandBot].statusPart)
                memcpy_bytes_08041D04(gBattleMenuTexts[1], gGameWork.textBuf, 14);
            else if (part_skill_is_passive(gBattleWork.commandBot, gBattleWork.partCursor - 1))
                memcpy_bytes_08041D04(gBattleMenuTexts[1], gGameWork.textBuf, 14);
            else if (gBattleWork.partCursor == 1 && gBattleBots[gBattleWork.commandBot].parts[0].headUses == 0)
                memcpy_bytes_08041D04(gBattleMenuTexts[2], gGameWork.textBuf, 14);
            else
                memcpy_bytes_08041D04(
                    (const void *)
                        gSkillTypeNames[gBattleBots[gBattleWork.commandBot].parts[gBattleWork.partCursor - 1].data[2]],
                    gGameWork.textBuf, 14);
        }
    }
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x2D, 0x13, 0xE, 10, 14, 0, 0);
}

void part_select_blink_status(void) {
    u32 show = 0;
    s32 k = gBattleWork.partCursor;

    if (k == 0)
        ;
    else if (k >= 0) {
        if (k <= 3) {
            if (gBattleBots[gBattleWork.commandBot].parts[k - 1].armor == 0) {
                memcpy_bytes_08041D04(gBattleMenuTexts[0], gGameWork.textBuf, 14);
                show = 1;
            } else if (gBattleBots[gBattleWork.commandBot].statusType == 0x2B &&
                       k == gBattleBots[gBattleWork.commandBot].statusPart) {
                memcpy_bytes_08041D04(gBattleMenuTexts[1], gGameWork.textBuf, 14);
                show = 1;
            } else if (part_skill_is_passive(gBattleWork.commandBot, gBattleWork.partCursor - 1)) {
                memcpy_bytes_08041D04(gBattleMenuTexts[1], gGameWork.textBuf, 14);
                show = 1;
            } else if (gBattleWork.partCursor == 1 && gBattleBots[gBattleWork.commandBot].parts[0].headUses == 0) {
                memcpy_bytes_08041D04(gBattleMenuTexts[2], gGameWork.textBuf, 14);
                show = 1;
            }
        }
    }
    if (show) {
        if (gGameWork.stepCounter & 8)
            disable_sprites(0x2D, 13);
        else
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x2D, 0x13, 0xE, 10, 14, 0, 0);
    }
}

void part_select_draw_skill_name(void) {
    s32 k;

    disable_sprites(0x14, 11);
    k = gBattleWork.partCursor;
    if (k == 0)
        fill_text_blank(gGameWork.textBuf, 10);
    else if (k >= 0) {
        if (k <= 3)
            memcpy_bytes_08041D04((const void *)gSkillNames[gBattleBots[gBattleWork.commandBot].parts[k - 1].data[1]],
                                  gGameWork.textBuf, 12);
    }
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x14, 0x15, 0x11, 8, 14, 0, 0);
}

void part_select_init_cursor(void) {
    u8 cursor = gBattleBots[gBattleWork.commandBot].chosenAction;
    if (cursor > 3)
        cursor = 0;
    gBattleWork.partCursor = cursor;
}

void part_select_draw_head_uses(void) {
    if (gBattleWork.partCursor == 1) {
        draw_tile_block(2, 1, 0xE, 0xC, REG_BG0CNT, 0xD218);
        draw_count_over_max(gBattleBots[gBattleWork.commandBot].parts[0].headUses,
                            gBattleBots[gBattleWork.commandBot].parts[0].data[8], 0x10, 0xC, 0xD21A, REG_BG0CNT,
                            0xD220);
    } else
        vram_fill_tilemap_rect(7, 1, 0xE, 0xC, REG_BG0CNT, 0);
}

// Skills that work on their own and cannot be chosen as an action (Cancel Optic/Bomb/Grav, Accel Chrg,
// Strengthen: names from the skill name table); part select shows them with the "sealed" text.
u32 part_skill_is_passive(u32 rec, u32 part) {
    switch (gBattleBots[rec].parts[part].data[1]) {
    case 0x18:
    case 0x19:
    case 0x1A:
    case 0x28:
    case 0x35:
        return 1;
    default:
        return 0;
    }
}
