// Choice menu: open_choice_menu / poll_choice_menu run the yes/no prompt state table gChoiceMenuStates by
// gGameWork.choiceState (decompress the BG, slide the tile strip in, move the cursor sprite, slide out; the
// last entry is choice_menu_finish). Then two sprite jitter helpers and game_state_execute_handler_a/b, which
// run the text/message window tables gMessageCloseSteps / gMessageCloseQuickSteps by gGameWork.endModeStep. Shares the
// window state gGameWork with text/message; used by menus, the save screen and battles.

#include "global.h"

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

void open_choice_menu(u8 a, u8 b, u8 c) {
    mem_fill8(&gGameWork.unk28, 8, 0);
    gGameWork.unk2A = a;
    gGameWork.scrollSpriteSlot = 0x7F;
    gGameWork.transTileX = b;
    gGameWork.transTileY = c;
}

static void init_window_params(u8 a, u8 b, u8 c, u8 d) {
    mem_fill8(&gGameWork.unk28, 8, 0);
    gGameWork.unk2A = a;
    gGameWork.scrollSpriteSlot = d;
    gGameWork.transTileX = b;
    gGameWork.transTileY = c;
}

u32 poll_choice_menu(void) {
    gChoiceMenuStates[gGameWork.choiceState]();
    return gGameWork.unk28;
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
    u16 *d = (u16 *)(VRAM + 0x2800) + gGameWork.transTileY * 32 + gGameWork.transTileX;
    u16 *row = d;
    u16 *s;

    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++)
            *d++ = 0;
        row += 32;
        d = row;
    }
    s = (u16 *)(VRAM + 0x2D40);
    for (i = 0; i < 8; i++)
        *d++ = *s++;
    row += 32;
    d = row;
    s = (u16 *)(VRAM + 0x2E80);
    for (i = 0; i < 8; i++)
        *d++ = *s++;
    row += 32;
    d = row;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++)
            *d++ = 0;
        row += 32;
        d = row;
    }
    gGameWork.choiceState++;
}

void transition_draw_tile_strip(void) {
    u32 i, j;
    u16 *d = (u16 *)(VRAM + 0x2800) + gGameWork.transTileY * 32 + gGameWork.transTileX;
    u16 *row = d;
    u16 *s;
    u16 *srow;

    for (i = 0; i < 8; i++)
        *d++ = 0;
    row += 32;
    s = (u16 *)(VRAM + 0x2D40);
    srow = s;
    d = row;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++)
            *d++ = *s++;
        row += 32;
        d = row;
        srow += 32;
        s = srow;
    }
    s = (u16 *)(VRAM + 0x2E40);
    srow = s;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++)
            *d++ = *s++;
        row += 32;
        d = row;
        srow += 32;
        s = srow;
    }
    for (i = 0; i < 8; i++)
        *d++ = 0;
    gGameWork.choiceState++;
}

void copy_transition_tiles_to_bg2(void) {
    u32 i, j;
    u16 *d = (u16 *)(VRAM + 0x2800) + gGameWork.transTileY * 32 + gGameWork.transTileX;
    u16 *s = (u16 *)(VRAM + 0x2D40);
    u16 *srow = s;
    u16 *row = d;

    for (j = 0; j < 6; j++) {
        for (i = 0; i < 8; i++)
            *d++ = *s++;
        row += 32;
        d = row;
        srow += 32;
        s = srow;
    }
    gGameWork.choiceState++;
}

void battle_sprite_setup_cursor(void) {
    gSpriteEntries[gGameWork.scrollSpriteSlot].flags = 0xD204;
    gSpriteEntries[gGameWork.scrollSpriteSlot].x = gGameWork.transTileX * 8 + 0x14;
    gSpriteEntries[gGameWork.scrollSpriteSlot].y = gGameWork.transTileY * 8 + gGameWork.unk2A * 16 + 0x10;
    gSpriteEntries[gGameWork.scrollSpriteSlot].frame = 0x307;
    gSpriteEntries[gGameWork.scrollSpriteSlot].palette = 0xE;
    gSpriteEntries[gGameWork.scrollSpriteSlot].frame_table = 0;
    gSpriteEntries[gGameWork.scrollSpriteSlot].scale_x = 1;
    gSpriteEntries[gGameWork.scrollSpriteSlot].scale_y = 1;
    gSpriteEntries[gGameWork.scrollSpriteSlot].order = 0xFF;
    gGameWork.unk84 = 1;
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
    gGameWork.unk84 = 0;
}

void handle_battle_sprite_scroll_input(void) {
    if (KEYS_LO(gNewKeys) & 0xC0) {
        play_sound_effect(2);
        gGameWork.unk2A ^= 1;
        gSpriteEntries[gGameWork.scrollSpriteSlot].y = gGameWork.unk2A * 16 + 0x48;
    }
    sprite_bob_x(gGameWork.scrollSpriteSlot, gGameWork.unk84, gGameWork.transTileX * 8 + 0x14);
    gGameWork.unk84++;
    if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        gGameWork.unk2A = 1;
        gSpriteEntries[gGameWork.scrollSpriteSlot].x = gGameWork.transTileX * 8 + 0x14;
        gSpriteEntries[gGameWork.scrollSpriteSlot].y = gGameWork.unk2A * 16 + 0x48;
        gGameWork.unk84 = 0;
        gGameWork.choiceState++;
    }
    if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        gSpriteEntries[gGameWork.scrollSpriteSlot].x = gGameWork.transTileX * 8 + 0x14;
        gGameWork.unk84 = 0;
        gGameWork.choiceState++;
    }
}

void update_sprite_hflip_by_animation_phase(void) {
    if (gGameWork.unk84 != 0x1E) {
        if (gGameWork.unk84 & 4)
            gSpriteEntries[gGameWork.scrollSpriteSlot].flags &= 0xBFFF;
        else
            gSpriteEntries[gGameWork.scrollSpriteSlot].flags |= 0x4000;
        gGameWork.unk84++;
    } else {
        gSpriteEntries[gGameWork.scrollSpriteSlot].flags |= 0x4000;
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
    gGameWork.unk28 = (gGameWork.unk2A << 4) + 1;
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

void memcpy_bytes_08041D04(const void *src, void *dst, u8 n) {
    u32 i;

    for (i = 0; i < n; i++) {
        *(u8 *)dst = *(const u8 *)src;
        src = (const u8 *)src + 1;
        dst = (u8 *)dst + 1;
    }
}
