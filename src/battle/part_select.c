// Robattle part select (after choosing Attack on the command ring): the head / arms / legs icons around the
// centre, cursor input and blinking, the part's name, skill type and skill name, the head's uses left.
// Called from battle/robattle.

#include "global.h"

void part_select_init_center_icon(void) {
    gSpriteEntries[0].flags = 0xC404;
    gSpriteEntries[0].frame_table = 0;
    gSpriteEntries[0].x = 0x78;
    gSpriteEntries[0].y = 0x78;
    gSpriteEntries[0].palette = 0xA;
    gSpriteEntries[0].order = 0xC0;
    gSpriteEntries[0].frame = gPartSelectCenterFrames[gBattleWork.unk82] + 0x600;
}

void part_select_init_head_icon(u32 a) {
    gSpriteEntries[1].flags = 0xC404;
    gSpriteEntries[1].frame_table = 0;
    gSpriteEntries[1].x = 0x78;
    gSpriteEntries[1].y = 0x6C;
    gSpriteEntries[1].palette = 0xA;
    gSpriteEntries[1].order = 0xC0;
    gSpriteEntries[1].frame = a * 4 + 0x604;
}

void part_select_init_right_arm_icon(u32 a) {
    gSpriteEntries[2].flags = 0xC404;
    gSpriteEntries[2].frame_table = 0;
    gSpriteEntries[2].x = 0x6C;
    gSpriteEntries[2].y = 0x78;
    gSpriteEntries[2].palette = 0xA;
    gSpriteEntries[2].order = 0xC0;
    gSpriteEntries[2].frame = a * 4 + 0x605;
}

void part_select_init_left_arm_icon(u32 a) {
    gSpriteEntries[3].flags = 0xC404;
    gSpriteEntries[3].frame_table = 0;
    gSpriteEntries[3].x = 0x84;
    gSpriteEntries[3].y = 0x78;
    gSpriteEntries[3].palette = 0xA;
    gSpriteEntries[3].order = 0xC0;
    gSpriteEntries[3].frame = a * 4 + 0x606;
}

void part_select_init_bottom_icon(u32 a) {
    gSpriteEntries[4].flags = 0xC404;
    gSpriteEntries[4].frame_table = 0;
    gSpriteEntries[4].x = 0x78;
    gSpriteEntries[4].y = 0x84;
    gSpriteEntries[4].palette = 0xA;
    gSpriteEntries[4].order = 0xC0;
    gSpriteEntries[4].frame = a * 4 + 0x607;
}

void part_select_blink_selected_icon(void) {
    switch (gBattleWork.unk82) {
    case 0:
        if (gGameWork.unk84 & 8)
            part_select_init_bottom_icon(1);
        else
            part_select_init_bottom_icon(0);
        break;
    case 1:
        if (gGameWork.unk84 & 8)
            part_select_init_head_icon(1);
        else
            part_select_init_head_icon(0);
        break;
    case 2:
        if (gGameWork.unk84 & 8)
            part_select_init_right_arm_icon(1);
        else
            part_select_init_right_arm_icon(0);
        break;
    case 3:
        if (gGameWork.unk84 & 8)
            part_select_init_left_arm_icon(1);
        else
            part_select_init_left_arm_icon(0);
        break;
    }
}

// Robattle sub-state 0x12, Medapart select (runtime-checked from battle_start.ss0): UP head (1),
// LEFT right arm (2), RIGHT left arm (3), DOWN none (0) in gBattleWork.unk82.
void part_select_input(void) {
    u8 old = gBattleWork.unk82;

    if (KEYS_LO(gNewKeys) & 0x40)
        gBattleWork.unk82 = 1;
    if (KEYS_LO(gNewKeys) & 0x80)
        gBattleWork.unk82 = 0;
    if (KEYS_LO(gNewKeys) & 0x20)
        gBattleWork.unk82 = 2;
    if (KEYS_LO(gNewKeys) & 0x10)
        gBattleWork.unk82 = 3;
    if (gBattleWork.unk82 != old) {
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
    k = gBattleWork.unk82;
    if (k == 0)
        memcpy_bytes_08041D04(gBattleMenuTexts[3], gGameWork.textBuf, 14);
    else if (k >= 0) {
        if (k <= 3)
            memcpy_bytes_08041D04(
                (const void *)gMedapartNames[0][gBattleBots[gBattleWork.unk80].parts[k - 1].unk17 * 4 + k - 1],
                gGameWork.textBuf, 15);
    }
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x1F, 10, 0x11, 10, 13, 0, 0);
}

void part_select_draw_skill_type(void) {
    s32 k;

    disable_sprites(0x2D, 13);
    k = gBattleWork.unk82;
    if (k == 0)
        fill_text_blank(gGameWork.textBuf, 13);
    else if (k >= 0) {
        if (k <= 3) {
            if (gBattleBots[gBattleWork.unk80].parts[k - 1].unk11 == 0)
                memcpy_bytes_08041D04(gBattleMenuTexts[0], gGameWork.textBuf, 14);
            else if (gBattleBots[gBattleWork.unk80].statusType == 0x2B &&
                     k == gBattleBots[gBattleWork.unk80].statusPart)
                memcpy_bytes_08041D04(gBattleMenuTexts[1], gGameWork.textBuf, 14);
            else if (part_skill_is_passive(gBattleWork.unk80, gBattleWork.unk82 - 1))
                memcpy_bytes_08041D04(gBattleMenuTexts[1], gGameWork.textBuf, 14);
            else if (gBattleWork.unk82 == 1 && gBattleBots[gBattleWork.unk80].parts[0].unk10 == 0)
                memcpy_bytes_08041D04(gBattleMenuTexts[2], gGameWork.textBuf, 14);
            else
                memcpy_bytes_08041D04(
                    (const void *)gSkillTypeNames[gBattleBots[gBattleWork.unk80].parts[gBattleWork.unk82 - 1].data[2]],
                    gGameWork.textBuf, 14);
        }
    }
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x2D, 0x13, 0xE, 10, 14, 0, 0);
}

void part_select_blink_status(void) {
    u32 show = 0;
    s32 k = gBattleWork.unk82;

    if (k == 0)
        ;
    else if (k >= 0) {
        if (k <= 3) {
            if (gBattleBots[gBattleWork.unk80].parts[k - 1].unk11 == 0) {
                memcpy_bytes_08041D04(gBattleMenuTexts[0], gGameWork.textBuf, 14);
                show = 1;
            } else if (gBattleBots[gBattleWork.unk80].statusType == 0x2B &&
                       k == gBattleBots[gBattleWork.unk80].statusPart) {
                memcpy_bytes_08041D04(gBattleMenuTexts[1], gGameWork.textBuf, 14);
                show = 1;
            } else if (part_skill_is_passive(gBattleWork.unk80, gBattleWork.unk82 - 1)) {
                memcpy_bytes_08041D04(gBattleMenuTexts[1], gGameWork.textBuf, 14);
                show = 1;
            } else if (gBattleWork.unk82 == 1 && gBattleBots[gBattleWork.unk80].parts[0].unk10 == 0) {
                memcpy_bytes_08041D04(gBattleMenuTexts[2], gGameWork.textBuf, 14);
                show = 1;
            }
        }
    }
    if (show) {
        if (gGameWork.unk84 & 8)
            disable_sprites(0x2D, 13);
        else
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x2D, 0x13, 0xE, 10, 14, 0, 0);
    }
}

void part_select_draw_skill_name(void) {
    s32 k;

    disable_sprites(0x14, 11);
    k = gBattleWork.unk82;
    if (k == 0)
        fill_text_blank(gGameWork.textBuf, 10);
    else if (k >= 0) {
        if (k <= 3)
            memcpy_bytes_08041D04((const void *)gSkillNames[gBattleBots[gBattleWork.unk80].parts[k - 1].data[1]],
                                  gGameWork.textBuf, 12);
    }
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x14, 0x15, 0x11, 8, 14, 0, 0);
}

void part_select_init_cursor(void) {
    u8 v = gBattleBots[gBattleWork.unk80].chosenAction;
    if (v > 3)
        v = 0;
    gBattleWork.unk82 = v;
}

void part_select_draw_head_uses(void) {
    if (gBattleWork.unk82 == 1) {
        draw_tile_block(2, 1, 0xE, 0xC, REG_BG0CNT, 0xD218);
        draw_count_over_max(gBattleBots[gBattleWork.unk80].parts[0].unk10,
                            gBattleBots[gBattleWork.unk80].parts[0].data[8], 0x10, 0xC, 0xD21A, REG_BG0CNT, 0xD220);
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
