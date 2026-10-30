// Choice menu: open_choice_menu / poll_choice_menu run the yes/no prompt state table gChoiceMenuStates by
// gGameWork.choiceState (decompress the BG, slide the tile strip in, move the cursor sprite, slide out; the
// last entry is choice_menu_finish). Then two sprite jitter helpers and game_state_execute_handler_a/b, which
// run the text/message window tables gMessageCloseSteps / gMessageCloseQuickSteps by gGameWork.endModeStep. Shares the
// window state gGameWork with text/message; used by menus, the save screen and battles.

#include "global.h"
#include "constants/sprites.h"

void reset_bg_scroll(void) {
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
}

void open_choice_menu(u8 cursor, u8 tile_x, u8 tile_y) {
    mem_fill8(&gGameWork.choiceResult, 8, 0);
    gGameWork.choiceCursor = cursor;
    gGameWork.scrollSpriteSlot = 0x7F;
    gGameWork.transTileX = tile_x;
    gGameWork.transTileY = tile_y;
}

static void init_window_params(u8 cursor, u8 tile_x, u8 tile_y, u8 sprite_slot) {
    mem_fill8(&gGameWork.choiceResult, 8, 0);
    gGameWork.choiceCursor = cursor;
    gGameWork.scrollSpriteSlot = sprite_slot;
    gGameWork.transTileX = tile_x;
    gGameWork.transTileY = tile_y;
}

u32 poll_choice_menu(void) {
    gChoiceMenuStates[gGameWork.choiceState]();
    return gGameWork.choiceResult;
}

void decompress_bg_tilemap_to_vram(void) {
    lz_decompress_dispatch(gChoiceMenuFrameTiles, (void *)(VRAM + 0x2600));
    lz_decompress_dispatch(gChoiceMenuLabelTiles, (void *)(VRAM + 0x26E0));
    lz_decompress_dispatch(gCursorArrowTiles, (void *)(VRAM + 0x17E00));
    set_tilemap_and_decompress_bg(0, 0x15, gChoiceMenuFrameTilemap, REG_BG0CNT, 0x130);
    set_tilemap_and_decompress_bg(2, 0x16, gChoiceMenuLabelTilemap, REG_BG0CNT, 0x137);
    CpuFastSet(gCursorArrowPalette, (void *)(PLTT + 0x3C0), 8);
    gGameWork.choiceState++;
}

void clear_tilemap_and_advance_state(void) {
    vram_fill_tilemap_rect(8, 6, gGameWork.transTileX, gGameWork.transTileY, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(8, 6, 0, 0x15, REG_BG0CNT, 0);
    gGameWork.choiceState++;
}

void clear_and_copy_tilemap_rows(void) {
    u32 i, j;
    u16 *dst = (u16 *)(VRAM + 0x2800) + gGameWork.transTileY * 32 + gGameWork.transTileX;
    u16 *row = dst;
    u16 *src;

    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++)
            *dst++ = 0;
        row += 32;
        dst = row;
    }
    src = (u16 *)(VRAM + 0x2D40);
    for (i = 0; i < 8; i++)
        *dst++ = *src++;
    row += 32;
    dst = row;
    src = (u16 *)(VRAM + 0x2E80);
    for (i = 0; i < 8; i++)
        *dst++ = *src++;
    row += 32;
    dst = row;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++)
            *dst++ = 0;
        row += 32;
        dst = row;
    }
    gGameWork.choiceState++;
}

void transition_draw_tile_strip(void) {
    u32 i, j;
    u16 *dst = (u16 *)(VRAM + 0x2800) + gGameWork.transTileY * 32 + gGameWork.transTileX;
    u16 *row = dst;
    u16 *src;
    u16 *srow;

    for (i = 0; i < 8; i++)
        *dst++ = 0;
    row += 32;
    src = (u16 *)(VRAM + 0x2D40);
    srow = src;
    dst = row;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++)
            *dst++ = *src++;
        row += 32;
        dst = row;
        srow += 32;
        src = srow;
    }
    src = (u16 *)(VRAM + 0x2E40);
    srow = src;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++)
            *dst++ = *src++;
        row += 32;
        dst = row;
        srow += 32;
        src = srow;
    }
    for (i = 0; i < 8; i++)
        *dst++ = 0;
    gGameWork.choiceState++;
}

void copy_transition_tiles_to_bg2(void) {
    u32 i, j;
    u16 *dst = (u16 *)(VRAM + 0x2800) + gGameWork.transTileY * 32 + gGameWork.transTileX;
    u16 *src = (u16 *)(VRAM + 0x2D40);
    u16 *srow = src;
    u16 *row = dst;

    for (j = 0; j < 6; j++) {
        for (i = 0; i < 8; i++)
            *dst++ = *src++;
        row += 32;
        dst = row;
        srow += 32;
        src = srow;
    }
    gGameWork.choiceState++;
}

void battle_sprite_setup_cursor(void) {
    gSpriteEntries[gGameWork.scrollSpriteSlot].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_HFLIP | SPRITE_FLAG_AFFINE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[gGameWork.scrollSpriteSlot].x = gGameWork.transTileX * 8 + 0x14;
    gSpriteEntries[gGameWork.scrollSpriteSlot].y = gGameWork.transTileY * 8 + gGameWork.choiceCursor * 16 + 0x10;
    gSpriteEntries[gGameWork.scrollSpriteSlot].frame = 0x307;
    gSpriteEntries[gGameWork.scrollSpriteSlot].palette = 0xE;
    gSpriteEntries[gGameWork.scrollSpriteSlot].frame_table = 0;
    gSpriteEntries[gGameWork.scrollSpriteSlot].scale_x = 1;
    gSpriteEntries[gGameWork.scrollSpriteSlot].scale_y = 1;
    gSpriteEntries[gGameWork.scrollSpriteSlot].order = 0xFF;
    gGameWork.stepCounter = 1;
    gGameWork.choiceState++;
}

void advance_sprite_scroll_animation(void) {
    gSpriteEntries[gGameWork.scrollSpriteSlot].scale_x += 8;
    gSpriteEntries[gGameWork.scrollSpriteSlot].scale_y += 8;
    if (gSpriteEntries[gGameWork.scrollSpriteSlot].scale_x >= 0x40) {
        gSpriteEntries[gGameWork.scrollSpriteSlot].scale_x = 0x40;
        gSpriteEntries[gGameWork.scrollSpriteSlot].scale_y = 0x40;
        gGameWork.choiceState++;
    }
    gGameWork.stepCounter = 0;
}

void handle_battle_sprite_scroll_input(void) {
    if (KEYS_LO(gNewKeys) & (DPAD_UP | DPAD_DOWN)) {
        play_sound_effect(2);
        gGameWork.choiceCursor ^= 1;
        gSpriteEntries[gGameWork.scrollSpriteSlot].y = gGameWork.choiceCursor * 16 + 0x48;
    }
    sprite_bob_x(gGameWork.scrollSpriteSlot, gGameWork.stepCounter, gGameWork.transTileX * 8 + 0x14);
    gGameWork.stepCounter++;
    if (KEYS_LO(gNewKeys) & B_BUTTON) {
        play_sound_effect(5);
        gGameWork.choiceCursor = 1;
        gSpriteEntries[gGameWork.scrollSpriteSlot].x = gGameWork.transTileX * 8 + 0x14;
        gSpriteEntries[gGameWork.scrollSpriteSlot].y = gGameWork.choiceCursor * 16 + 0x48;
        gGameWork.stepCounter = 0;
        gGameWork.choiceState++;
    }
    if (KEYS_LO(gNewKeys) & A_BUTTON) {
        play_sound_effect(4);
        gSpriteEntries[gGameWork.scrollSpriteSlot].x = gGameWork.transTileX * 8 + 0x14;
        gGameWork.stepCounter = 0;
        gGameWork.choiceState++;
    }
}

void update_sprite_hflip_by_animation_phase(void) {
    if (gGameWork.stepCounter != 0x1E) {
        if (gGameWork.stepCounter & 4)
            gSpriteEntries[gGameWork.scrollSpriteSlot].flags &= (u16)~SPRITE_FLAG_VISIBLE;
        else
            gSpriteEntries[gGameWork.scrollSpriteSlot].flags |= SPRITE_FLAG_VISIBLE;
        gGameWork.stepCounter++;
    } else {
        gSpriteEntries[gGameWork.scrollSpriteSlot].flags |= SPRITE_FLAG_VISIBLE;
        gGameWork.choiceState++;
    }
}

void animate_battle_sprite_shrink(void) {
    gSpriteEntries[gGameWork.scrollSpriteSlot].scale_x -= 8;
    gSpriteEntries[gGameWork.scrollSpriteSlot].scale_y -= 8;
    if (gSpriteEntries[gGameWork.scrollSpriteSlot].scale_x == 0) {
        clear_battle_sprite_slot(gGameWork.scrollSpriteSlot, 1);
        gGameWork.choiceState++;
    }
}

void choice_menu_finish(void) {
    gGameWork.choiceResult = (gGameWork.choiceCursor << 4) + 1;
    gGameWork.choiceState++;
}

void sprite_bob_x(u8 sprite, u8 frame, u16 x) {
    switch ((frame & 0xC) >> 2) {
    case 1:
        gSpriteEntries[sprite].x = x + 1;
        break;
    case 3:
        gSpriteEntries[sprite].x = x - 1;
        break;
    default:
        gSpriteEntries[sprite].x = x;
        break;
    }
}

void sprite_bob_y(u8 sprite, u8 frame, u16 y) {
    switch ((frame & 0xC) >> 2) {
    case 1:
        gSpriteEntries[sprite].y = y + 1;
        break;
    case 3:
        gSpriteEntries[sprite].y = y - 1;
        break;
    default:
        gSpriteEntries[sprite].y = y;
        break;
    }
}

u32 game_state_execute_handler_a(void) {
    gGameWork.msgState = 0;
    gMessageCloseSteps[gGameWork.endModeStep]();
    if (gGameWork.msgState > 7)
        return 1;
    return 0;
}

u32 game_state_execute_handler_b(void) {
    gGameWork.msgState = 0;
    gMessageCloseQuickSteps[gGameWork.endModeStep]();
    if (gGameWork.msgState > 7)
        return 1;
    return 0;
}

void copy_bytes_short(const void *src, void *dst, u8 n) {
    u32 i;

    for (i = 0; i < n; i++) {
        *(u8 *)dst = *(const u8 *)src;
        src = (const u8 *)src + 1;
        dst = (u8 *)dst + 1;
    }
}
