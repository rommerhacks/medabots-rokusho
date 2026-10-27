// Game state 1: the field pause menu (START on the field): Medawatch / Item / Vehicle / Save and the money
// display, its open / close animations and the return from the sub-screens.

#include "global.h"

static void field_menu_init_cursor(void);

// Game state 1: the field pause menu (Medawatch / Item / Vehicle / Save, money display).
void field_menu_update(void) {
    gFieldMenuHandlers[gGameSubState]();
}

void field_menu_load_gfx(void) {
    REG_DISPCNT = 0x1F60;
    REG_BG0CNT = 0x500;
    lz_decompress_dispatch(gUnk_084C1608, (void *)0x06001800);
    lz_decompress_dispatch(gUnk_084C17F0, (void *)0x06001B00);
    lz_decompress_dispatch(gUnk_084C1934, (void *)0x06001E00);
    lz_decompress_dispatch(gUnk_084C1ACC, (void *)0x06002100);
    lz_decompress_dispatch(gUnk_08487708, (void *)0x06002400);
    DmaSet(3, gUnk_08488A84, 0x050001E0, 0x80000010);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    DmaSet(3, gUnk_084E2E38, 0x050003E0, 0x80000010);
    play_song(6);
    gGameWork.unk84 = 0;
    gGameSubState++;
}

void field_menu_open_anim(void) {
    if (gGameWork.unk84 <= 12)
        write_tilemap_rect(12, 2, 18, 1, gUnk_083B4AE0[gGameWork.unk84 + 0x13], REG_BG0CNT, 0);
    if ((u8)(gGameWork.unk84 - 2) <= 12)
        write_tilemap_rect(12, 2, 18, 3, gUnk_083B4AE0[gGameWork.unk84 + 0x1E], REG_BG0CNT, 0);
    if ((u8)(gGameWork.unk84 - 4) <= 12)
        write_tilemap_rect(12, 2, 18, 5, gUnk_083B4AE0[gGameWork.unk84 + 0x29], REG_BG0CNT, 0);
    if ((u8)(gGameWork.unk84 - 6) <= 12)
        write_tilemap_rect(12, 2, 18, 7, gUnk_083B4AE0[gGameWork.unk84 + 0x34], REG_BG0CNT, 0);
    if (gGameWork.unk84 == 10) {
        lz_decompress_dispatch(gUnk_08487814, (void *)0x06002400);
        set_tilemap_and_decompress_bg(0x15, 9, gUnk_08488690, REG_BG0CNT, 0x120);
    }
    if (gGameWork.unk84 == 12) {
        lz_decompress_dispatch(gUnk_08487708, (void *)0x06002400);
        set_tilemap_and_decompress_bg(0x15, 9, gUnk_08488644, REG_BG0CNT, 0x120);
    }
    if (++gGameWork.unk84 > 18) {
        divide_by_10000(gGameWork.textBuf, gPlayerRecord.money);
        render_text_sprites_08040DB8(gGameWork.textBuf, 10, 0x17, 10, 5, 15, 2, 0);
        gGameWork.fieldMenuCursor = 0;
        field_menu_init_cursor();
        gGameSubState++;
    }
}

void field_menu_handle_input(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0], 0);
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        play_sound_effect(2);
        gGameWork.fieldMenuCursor = (gGameWork.fieldMenuCursor - 1) & 3;
        gSpriteEntries[0].unk4 = gGameWork.fieldMenuCursor * 16 + 8;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        play_sound_effect(2);
        gGameWork.fieldMenuCursor = (gGameWork.fieldMenuCursor + 1) & 3;
        gSpriteEntries[0].unk4 = gGameWork.fieldMenuCursor * 16 + 8;
    }
    if (KEYS_LO(gNewKeys) & 2) {
        fade_out_music(0x10);
        play_sound_effect(5);
        clear_battle_sprite_slot(0, 1);
        clear_battle_sprite_slot(10, 7);
        gGameWork.unk84 = 0;
        gGameSubState = 3;
    } else if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        gGameSubState = 6;
    }
}

void field_menu_close_anim(void) {
    if (gGameWork.unk84 <= 12)
        write_tilemap_rect(12, 2, 18, 1, gUnk_083B4AE0[0x1F - gGameWork.unk84], REG_BG0CNT, 0);
    if ((u8)(gGameWork.unk84 - 2) <= 12)
        write_tilemap_rect(12, 2, 18, 3, gUnk_083B4AE0[0x2E - gGameWork.unk84], REG_BG0CNT, 0);
    if ((u8)(gGameWork.unk84 - 4) <= 12)
        write_tilemap_rect(12, 2, 18, 5, gUnk_083B4AE0[0x3D - gGameWork.unk84], REG_BG0CNT, 0);
    if ((u8)(gGameWork.unk84 - 6) <= 12)
        write_tilemap_rect(12, 2, 18, 7, gUnk_083B4AE0[0x4C - gGameWork.unk84], REG_BG0CNT, 0);
    if (gGameWork.unk84 == 10) {
        lz_decompress_dispatch(gUnk_08487814, (void *)0x06002400);
        set_tilemap_and_decompress_bg(0x15, 9, gUnk_08488690, REG_BG0CNT, 0x120);
    }
    if (gGameWork.unk84 == 12)
        vram_fill_tilemap_rect(9, 4, 0x15, 9, REG_BG0CNT, 0);
    if (++gGameWork.unk84 > 18)
        return_to_field();
}

void field_menu_select_start(void) {
    switch (gGameWork.fieldMenuCursor) {
    case 0:
        vram_fill_tilemap_rect(13, 10, 17, 3, REG_BG0CNT, 0);
        gGameWork.menuRowAnim = 1;
        break;
    case 1:
        vram_fill_tilemap_rect(13, 2, 17, 1, REG_BG0CNT, 0);
        vram_fill_tilemap_rect(13, 8, 17, 5, REG_BG0CNT, 0);
        gGameWork.menuRowAnim = 3;
        break;
    case 2:
        vram_fill_tilemap_rect(13, 4, 17, 1, REG_BG0CNT, 0);
        vram_fill_tilemap_rect(13, 6, 17, 7, REG_BG0CNT, 0);
        gGameWork.menuRowAnim = 5;
        break;
    default:
        vram_fill_tilemap_rect(13, 6, 17, 1, REG_BG0CNT, 0);
        vram_fill_tilemap_rect(13, 4, 17, 9, REG_BG0CNT, 0);
        gGameWork.menuRowAnim = 7;
        break;
    }
    clear_battle_sprite_slot(0, 1);
    clear_battle_sprite_slot(10, 7);
    gGameSubState++;
}

void field_menu_select_collapse(void) {
    write_tilemap_rect(12, 2, 18, gGameWork.menuRowAnim - 1, gUnk_083B4AE0[gGameWork.fieldMenuCursor * 13 + 0x1F],
                       REG_BG0CNT, 0);
    vram_fill_tilemap_rect(12, 1, 18, gGameWork.menuRowAnim + 1, REG_BG0CNT, 0);
    if (--gGameWork.menuRowAnim == 0) {
        lz_decompress_dispatch(gUnk_084C1C14, (void *)0x060017E0);
        palette_backup_from_hardware();
        gGameWork.unk84 = 0;
        if (gGameWork.fieldMenuCursor == 0)
            fade_out_music(0x10);
        gGameSubState++;
    }
}

void field_menu_select_slide(void) {
    if (gGameWork.fieldMenuCursor != 2 && gGameWork.unk84 <= 16) {
        bg_palettes_blend_masked_now(0, gGameWork.unk84 * 2, 0x1FFF);
        obj_palettes_blend_masked_now(0, gGameWork.unk84 * 2, 0xFFFF);
        gGameWork.unk84++;
    }
    write_tilemap_rect(12, 2, 18 - gGameWork.menuRowAnim, 0, gUnk_083B4AE0[gGameWork.fieldMenuCursor * 13 + 0x1F],
                       REG_BG0CNT, 0);
    write_tilemap_rect(1, 2, 30 - gGameWork.menuRowAnim, 0, gUnk_083B4AE0[0x47], REG_BG0CNT, 0);
    if (++gGameWork.menuRowAnim == 19)
        gGameSubState++;
}

// Runs the chosen entry: Medawatch (game state 2), Item (mode 2 state 4), Vehicle, Save (mode 2 state 5).
void field_menu_run_choice(void) {
    switch (gGameWork.fieldMenuCursor) {
    case 0:
        play_song(7);
        gGameWork.medawatchCursor = 0;
        gGameState = 2;
        gGameSubState = 0;
        clear_battle_sprite_slot(0x28, 0x57);
        break;
    case 1:
        gGameMode = 2;
        gGameState = 4;
        gGameSubState = 0;
        clear_battle_sprite_slot(0x28, 0x57);
        break;
    case 2:
        field_resume(1);
        break;
    default:
        gUnk_03000588 = 0;
        gGameMode = 2;
        gGameState = 5;
        gGameSubState = 0;
        clear_battle_sprite_slot(0x28, 0x57);
        break;
    }
}

void field_menu_return_init(void) {
    gUnk_03000588 = 1;
    if (gGameWork.fieldMenuCursor != 2) {
        REG_DISPCNT &= 0xF1FF;
        DmaSet(3, gUnk_084E2E38, 0x0202F9E0, 0x84000008);
        area_load_graphics();
        blend_set_alpha_12_10();
        setup_blend_effect(0x40, 0x2F00, 5, 16, 16, 16, 12, 10, 0);
        REG_DISPCNT |= 0xF60;
    }
    gGameWork.menuRowAnim = 18;
    gGameWork.unk84 = 0;
    gGameSubState++;
}

void field_menu_return_slide(void) {
    if (gGameWork.fieldMenuCursor != 2 && gGameWork.unk84 <= 16) {
        blend_effect_update();
        bg_palettes_blend_masked_now(0, 32 - gGameWork.unk84 * 2, 0x1FFF);
        obj_palettes_blend_masked_now(0, 32 - gGameWork.unk84 * 2, 0xFFFF);
        gGameWork.unk84++;
    }
    gGameWork.menuRowAnim--;
    write_tilemap_rect(12, 2, 18 - gGameWork.menuRowAnim, 0, gUnk_083B4AE0[gGameWork.fieldMenuCursor * 13 + 0x1F],
                       REG_BG0CNT, 0);
    vram_fill_tilemap_rect(1, 2, 17 - gGameWork.menuRowAnim, 0, REG_BG0CNT, 0);
    if (gGameWork.menuRowAnim == 0) {
        gVBlankCallback = empty_callback;
        gGameWork.menuRowAnim = gGameWork.fieldMenuCursor * 2 + 1;
        gGameWork.unk84 = 0;
        gGameSubState++;
    }
}

void field_menu_return_expand(void) {
    write_tilemap_rect(12, 2, 18, gGameWork.unk84 + 1, gUnk_083B4AE0[gGameWork.fieldMenuCursor * 13 + 0x1F], REG_BG0CNT,
                       0);
    vram_fill_tilemap_rect(12, 1, 18, gGameWork.unk84, REG_BG0CNT, 0);
    if (gGameWork.unk84 + 1 == gGameWork.menuRowAnim) {
        switch (gGameWork.fieldMenuCursor) {
        case 0:
            write_tilemap_rect(12, 2, 18, 3, gUnk_083B4AE0[0x2C], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 5, gUnk_083B4AE0[0x39], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 7, gUnk_083B4AE0[0x46], REG_BG0CNT, 0);
            break;
        case 1:
            write_tilemap_rect(12, 2, 18, 1, gUnk_083B4AE0[0x1F], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 5, gUnk_083B4AE0[0x39], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 7, gUnk_083B4AE0[0x46], REG_BG0CNT, 0);
            break;
        case 2:
            write_tilemap_rect(12, 2, 18, 1, gUnk_083B4AE0[0x1F], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 3, gUnk_083B4AE0[0x2C], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 7, gUnk_083B4AE0[0x46], REG_BG0CNT, 0);
            break;
        default:
            write_tilemap_rect(12, 2, 18, 1, gUnk_083B4AE0[0x1F], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 3, gUnk_083B4AE0[0x2C], REG_BG0CNT, 0);
            write_tilemap_rect(12, 2, 18, 5, gUnk_083B4AE0[0x39], REG_BG0CNT, 0);
            break;
        }
        set_tilemap_and_decompress_bg(0x15, 9, gUnk_08488644, REG_BG0CNT, 0x120);
        divide_by_10000(gGameWork.textBuf, gPlayerRecord.money);
        render_text_sprites_08040DB8(gGameWork.textBuf, 10, 0x17, 10, 5, 15, 2, 0);
        field_menu_init_cursor();
        gGameSubState = 2;
    } else {
        gGameWork.unk84++;
    }
}

static void field_menu_init_cursor(void) {
    lz_decompress_dispatch(gUnk_084C7174, (void *)0x06016C00);
    DmaSet(3, gCursorArrowPalette, 0x050003C0, 0x84000008);
    gSpriteEntries[0].unk0 = 0xC004;
    gSpriteEntries[0].unk2 = 0x88;
    gSpriteEntries[0].unk4 = gGameWork.fieldMenuCursor * 16 + 8;
    gSpriteEntries[0].unkA = 14;
    gSpriteEntries[0].unk1C = 0;
    gSpriteEntries[0].unkB = 0xFF;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0], 0);
}
