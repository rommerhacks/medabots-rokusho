// The Robattle command ring: draws the selected command's name, sets up and rotates the ring icons, reads
// the input, pulses the selected icon and animates the battle sprites meanwhile. Called from battle/robattle.

#include "global.h"
#include "constants/sprites.h"

static void command_ring_init_icon_hidden(u32 a);
static u32 command_ring_rotate_icon(u32 i, u32 dir);

void command_ring_draw_name(void) {
    disable_sprites(30, 11);
    memcpy_bytes_08041D04(gCommandRingNames[gBattleWork.ringSlot], gGameWork.textBuf, 12);
    render_text_sprites_08040DB8(gGameWork.textBuf, 30, 21, 17, 8, 14, 0, 1);
}

void command_ring_init_icons(void) {
    u32 i;
    for (i = 0; i < 6; i++)
        command_ring_init_icon(i);
}

void command_ring_init_icon(u32 i) {
    u32 k;
    struct Vec16 p;

    clear_battle_sprite_slot(i, 1);
    gSpriteEntries[i].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    k = i - gBattleWork.ringSlot;
    if (k > 5)
        k += 6;
    p = compute_polar_to_screen_position(gCommandRingIconAngles[k], 24, 120, 128, 8, 0);
    gSpriteEntries[i].x = p.x;
    gSpriteEntries[i].y = p.y;
    gSpriteEntries[i].frame = i + 0x60C;
    if (p.y > 0x87)
        gSpriteEntries[i].palette = 8;
    else if (p.y > 0x77)
        gSpriteEntries[i].palette = 9;
    else
        gSpriteEntries[i].palette = 10;
    gSpriteEntries[i].frame_table = 0;
    gSpriteEntries[i].scale_y = 0x40 - (0x90 - gSpriteEntries[i].y) / 2;
    gSpriteEntries[i].scale_x = 0x40 - (0x90 - gSpriteEntries[i].y) / 2;
    gSpriteEntries[i].order = gSpriteEntries[i].y - 0x70;
    gSpriteEntries[i].unk20 = gCommandRingIconAngles[k];
    gSpriteEntries[i].unk21 = 0;
    gSpriteEntries[i].unk22 = 0;
}

void command_ring_init_icons_hidden(void) {
    u32 i;
    for (i = 0; i < 6; i++)
        command_ring_init_icon_hidden(i);
}

static void command_ring_init_icon_hidden(u32 i) {
    u32 k;
    struct Vec16 p;

    clear_battle_sprite_slot(i, 1);
    gSpriteEntries[i].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    k = i - gBattleWork.ringSlot;
    if (k > 5)
        k += 6;
    p = compute_polar_to_screen_position(gCommandRingIconAngles[k], 24, 120, 128, 8, 0);
    gSpriteEntries[i].x = p.x;
    gSpriteEntries[i].y = p.y;
    gSpriteEntries[i].frame = i + 0x60C;
    if (p.y > 0x87)
        gSpriteEntries[i].palette = 8;
    else if (p.y > 0x77)
        gSpriteEntries[i].palette = 9;
    else
        gSpriteEntries[i].palette = 10;
    gSpriteEntries[i].frame_table = 0;
    gSpriteEntries[i].scale_y = 1;
    gSpriteEntries[i].scale_x = 1;
    gSpriteEntries[i].order = gSpriteEntries[i].y - 0x70;
    gSpriteEntries[i].unk20 = gCommandRingIconAngles[k];
    gSpriteEntries[i].unk21 = 0;
    gSpriteEntries[i].unk22 = 0;
}

static u32 command_ring_rotate_step(u32 dir) {
    u32 i, done;
    for (i = 0; i <= 5; i++)
        done = command_ring_rotate_icon(i, dir);
    return done;
}

static u32 command_ring_rotate_icon(u32 i, u32 dir) {
    u32 done = 0;
    u32 k;
    u32 n;
    struct Vec16 p;

    gSpriteEntries[i].flags &= ~SPRITE_FLAG_DOUBLE_SIZE;
    if (dir == 0)
        n = gCommandRingNextSlotRight[gBattleWork.ringSlot];
    else
        n = gCommandRingNextSlotLeft[gBattleWork.ringSlot];
    k = i - n;
    if (k > 5)
        k += 6;
    if (dir == 0)
        gSpriteEntries[i].unk20 += 6;
    else
        gSpriteEntries[i].unk20 -= 6;
    gSpriteEntries[i].unk21++;
    if (gSpriteEntries[i].unk21 == 7) {
        done = 1;
        gSpriteEntries[i].unk20 = gCommandRingIconAngles[k];
        gSpriteEntries[i].unk21 = 0;
        gSpriteEntries[i].unk22 = 0;
    }
    p = compute_polar_to_screen_position(gSpriteEntries[i].unk20, 24, 120, 128, 8, 0);
    gSpriteEntries[i].x = p.x;
    gSpriteEntries[i].y = p.y;
    gSpriteEntries[i].frame = i + 0x60C;
    if (p.y > 0x87)
        gSpriteEntries[i].palette = 8;
    else if (p.y > 0x7B)
        gSpriteEntries[i].palette = 9;
    else
        gSpriteEntries[i].palette = 10;
    gSpriteEntries[i].frame_table = 0;
    gSpriteEntries[i].scale_y = 0x40 - (0x90 - gSpriteEntries[i].y) / 2;
    gSpriteEntries[i].scale_x = 0x40 - (0x90 - gSpriteEntries[i].y) / 2;
    gSpriteEntries[i].order = gSpriteEntries[i].y - 0x70;
    return done;
}

void command_ring_input(void) {
    if (gBattleWork.ringTurning) {
        if (command_ring_rotate_step(gBattleWork.ringTurning - 1)) {
            if (gBattleWork.ringTurning == 1)
                gBattleWork.ringSlot = gCommandRingNextSlotRight[gBattleWork.ringSlot];
            else
                gBattleWork.ringSlot = gCommandRingNextSlotLeft[gBattleWork.ringSlot];
            gBattleWork.ringTurning = 0;
            command_ring_draw_name();
        }
    } else {
        if (KEYS_LO(gRepeatKeys) & 0x10) {
            play_sound_effect(2);
            gBattleWork.ringTurning = 1;
        }
        if (KEYS_LO(gRepeatKeys) & 0x20) {
            play_sound_effect(2);
            gBattleWork.ringTurning = 2;
        }
    }
}

void command_ring_pulse_selected(void) {
    if (gBattleWork.ringTurning == 0) {
        gSpriteEntries[gBattleWork.ringSlot].flags |= SPRITE_FLAG_DOUBLE_SIZE;
        gSpriteEntries[gBattleWork.ringSlot].unk22++;
        if (gSpriteEntries[gBattleWork.ringSlot].unk22 & 8) {
            gSpriteEntries[gBattleWork.ringSlot].scale_y = 0x50;
            gSpriteEntries[gBattleWork.ringSlot].scale_x = 0x50;
        } else {
            gSpriteEntries[gBattleWork.ringSlot].scale_y = 0x40;
            gSpriteEntries[gBattleWork.ringSlot].scale_x = 0x40;
        }
    }
}

void bot_pointer_line_init(u32 kind) {
    s32 count = gBotPointerLineParams[kind * 4];
    u32 speed = gBotPointerLineParams[kind * 4 + 1];
    u32 x = gBotPointerLineParams[kind * 4 + 2];
    u32 y = gBotPointerLineParams[kind * 4 + 3];
    s32 i;

    clear_battle_sprite_slot(60, 10);
    for (i = 0; i < (u32)count; i++) {
        gSpriteEntries[60 + i].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[60 + i].frame_table = 0;
        gSpriteEntries[60 + i].x = x;
        gSpriteEntries[60 + i].y = y;
        gSpriteEntries[60 + i].palette = 8;
        gSpriteEntries[60 + i].order = 0x80;
        gSpriteEntries[60 + i].frame = (i & 3) + 0x616;
        gSpriteEntries[60 + i].unk25 = speed;
        gSpriteEntries[60 + i].unk26 = count - 1 - i;
        gSpriteEntries[60 + i].unk24 = 0;
        gSpriteEntries[60 + i].unk27 = i * 2;
        gSpriteEntries[60 + i].unk28 = 0;
        gSpriteEntries[60 + i].unk21 = 0;
        gSpriteEntries[60 + i].unk22 = i & 3;
        if (kind > 2)
            gSpriteEntries[60 + i].flags |= SPRITE_FLAG_HFLIP;
    }
}

u32 bot_pointer_line_extend(u32 kind) {
    u32 done = 1;
    u32 count = gBotPointerLineParams[kind * 4];
    u32 i;

    for (i = 0; i < count; i++) {
        u32 base;
        if (gSpriteEntries[60 + i].unk24)
            base = 0x12;
        else
            base = 0x16;
        gSpriteEntries[60 + i].unk21++;
        if ((gSpriteEntries[60 + i].unk21 & 3) == 0) {
            gSpriteEntries[60 + i].frame =
                base + ((gSpriteEntries[60 + i].unk22 = (gSpriteEntries[60 + i].unk22 + 1) & 3) | 0x600);
        }
        if (gSpriteEntries[60 + i].unk26 != gSpriteEntries[60 + i].unk24) {
            done = 0;
            if (gSpriteEntries[60 + i].unk27)
                gSpriteEntries[60 + i].unk27--;
            else {
                if (gSpriteEntries[60 + i].unk24 == 0) {
                    if (gSpriteEntries[60 + i].unk25)
                        gSpriteEntries[60 + i].x += 4;
                    else
                        gSpriteEntries[60 + i].x -= 4;
                } else
                    gSpriteEntries[60 + i].y += 4;
                gSpriteEntries[60 + i].unk28++;
                if ((gSpriteEntries[60 + i].unk28 & 1) == 0)
                    gSpriteEntries[60 + i].unk24++;
            }
        }
    }
    return done;
}

void bot_pointer_line_animate(u32 kind) {
    u32 count = gBotPointerLineParams[kind * 4];
    u32 i;

    for (i = 0; i < count; i++) {
        u32 base;
        if (gSpriteEntries[60 + i].unk24)
            base = 0x12;
        else
            base = 0x16;
        gSpriteEntries[60 + i].unk21++;
        if ((gSpriteEntries[60 + i].unk21 & 3) == 0) {
            gSpriteEntries[60 + i].frame =
                base + ((gSpriteEntries[60 + i].unk22 = (gSpriteEntries[60 + i].unk22 + 1) & 3) | 0x600);
        }
    }
}

void command_ring_flash_selected(void) {
    gSpriteEntries[gBattleWork.ringSlot].flags |= SPRITE_FLAG_DOUBLE_SIZE;
    gSpriteEntries[gBattleWork.ringSlot].unk22++;
    if (gSpriteEntries[gBattleWork.ringSlot].unk22 & 4) {
        gSpriteEntries[gBattleWork.ringSlot].scale_y = 0x60;
        gSpriteEntries[gBattleWork.ringSlot].scale_x = 0x60;
    } else {
        gSpriteEntries[gBattleWork.ringSlot].scale_y = 0x40;
        gSpriteEntries[gBattleWork.ringSlot].scale_x = 0x40;
    }
}

void command_ring_goto_selected(void) {
    gGameSubState = gCommandRingSubStates[gBattleWork.ringSlot];
}

void command_ring_shrink_icons(void) {
    u32 i;
    for (i = 0; i < 6; i++) {
        if (gSpriteEntries[i].scale_y == 1)
            disable_sprites(i, 1);
        else {
            s32 v = gSpriteEntries[i].scale_y - 8;
            if (v <= 0) {
                gSpriteEntries[i].scale_y = 1;
                gSpriteEntries[i].scale_x = 1;
            } else {
                gSpriteEntries[i].scale_y = v;
                gSpriteEntries[i].scale_x -= 8;
            }
        }
    }
}

void command_ring_close_scroll_right(void) {
    if (gGameWork.stepCounter < 10) {
        read_vram_tilemap_rect(0xB, 4, 0x13, 0x10, REG_BG1CNT, gBgTileBackup);
        write_vram_tilemap_rect(0xB, 4, 0x14, 0x10, REG_BG1CNT, gBgTileBackup);
    }
}

void command_ring_close_scroll_down(void) {
    if (gGameWork.stepCounter < 5) {
        read_vram_tilemap_rect(6, 6, 0xC, 0xE, REG_BG1CNT, gBgTileBackup);
        write_vram_tilemap_rect(6, 6, 0xC, 0xF, REG_BG1CNT, gBgTileBackup);
    }
}

void parts_menu_load_frame(void) {
    set_tilemap_and_decompress_bg(9, 0x15, gPartsMenuLeftPanelTilemap, REG_BG0CNT, 0x288);
    set_tilemap_and_decompress_bg(0x12, 0x15, gPartsMenuRightPanelTilemap, REG_BG1CNT, 0x2D0);
}

void parts_menu_slide_bg0(void) {
    if (gGameWork.stepCounter < 4)
        write_vram_tilemap_rect(0xC, 4, 9, 0x13 - gGameWork.stepCounter, REG_BG0CNT, gBgTileBackup);
}

void parts_menu_slide_bg1(void) {
    if (gGameWork.stepCounter < 12) {
        read_vram_tilemap_rect(gGameWork.stepCounter + 1, 7, 0x12, 0x15, REG_BG1CNT, gBgTileBackupHigh);
        write_vram_tilemap_rect(gGameWork.stepCounter + 1, 7, 0x1D - gGameWork.stepCounter, 0xD, REG_BG1CNT,
                                gBgTileBackupHigh);
    }
}
