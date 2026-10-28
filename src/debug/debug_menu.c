// Game state 63: the developer debug menu (labels in gDebugMenuLabels; runtime-checked: "Process" sets
// gGameMode / gGameState / gGameSubState and jumps there) and its entries: Medal, Parts, Tinpet, Item,
// Face, Medal picture, random Robattle, Battle, Sound test and Motion viewer.

#include "global.h"

void debug_menu_update(void) {
    gDebugMenuHandlers[gGameSubState]();
}

void debug_menu_init(void) {
    vu32 zero;

    REG_DISPCNT |= 0x1000;
    DmaSet(3, gSpriteEntries, gBgTileBackup, 0x84000400);
    zero = 0;
    DmaSet(3, &zero, gSpriteEntries, 0x85000400);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
    DmaSet(3, gSpriteFontPalette, 0x050003E0, 0x84000008);
    gGameSubState++;
}

void debug_menu_select_input(void) {
    u8 b;

    if (KEYS_LO(gNewKeys) & 0x10) {
        if (gGameWork.debugCursor == 10)
            gGameWork.debugCursor = 0;
        else
            gGameWork.debugCursor++;
    }
    if (KEYS_LO(gNewKeys) & 0x20) {
        if (gGameWork.debugCursor == 0)
            gGameWork.debugCursor = 10;
        else
            gGameWork.debugCursor--;
    }
    if (gFrameCounter & 4)
        clear_battle_sprite_slot(0, 8);
    else {
        memcpy_bytes_0803F63C(gDebugMenuLabels[gGameWork.debugCursor], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0, 1, 0, 8, 15, 1, 0);
    }
    if ((b = KEYS_LO(gNewKeys) & 2))
        gGameSubState++;
    else if (KEYS_LO(gNewKeys) & 1) {
        memcpy_bytes_0803F63C(gDebugMenuLabels[gGameWork.debugCursor], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0, 1, 0, 8, 15, 1, b);
        gGameWork.debugSubState = b;
        gGameWork.debugRow = b;
        gGameWork.debugValues[0] = b;
        gGameWork.debugValues[1] = b;
        gGameWork.debugValues[2] = b;
        gGameSubState = 3;
    }
}

void debug_menu_exit(void) {
    DmaSet(3, gBgTileBackup, gSpriteEntries, 0x84000400);
    gGameState = gGameWork.debugReturnState;
    gGameSubState = gGameWork.debugReturnSubState;
}

void debug_menu_run_entry(void) {
    gDebugMenuEntryHandlers[gGameWork.debugCursor]();
}

void debug_process_update(void) {
    gDebugProcessHandlers[gGameWork.debugSubState]();
}

void debug_process_input(void) {
    if (KEYS_LO(gNewKeys) & 0x40) {
        if (gGameWork.debugRow == 0)
            gGameWork.debugRow = 2;
        else
            gGameWork.debugRow--;
    }
    if (KEYS_LO(gNewKeys) & 0x80) {
        if (gGameWork.debugRow == 2)
            gGameWork.debugRow = 0;
        else
            gGameWork.debugRow++;
    }
    switch (gGameWork.debugRow) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugProcessLabels[0], gGameWork.textBuf, 8);
            render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugProcessLabels[1], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugProcessLabels[2], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugProcessLabels[1], gGameWork.textBuf, 8);
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugProcessLabels[0], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugProcessLabels[2], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    default:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x18, 8);
        else {
            memcpy_bytes_0803F63C(gDebugProcessLabels[2], gGameWork.textBuf, 8);
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x18, 2, 6, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugProcessLabels[1], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugProcessLabels[0], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gGameWork.debugValues[gGameWork.debugRow]++;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gGameWork.debugValues[gGameWork.debugRow]--;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[0]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[1]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x23, 8, 4, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x26, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[2]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x26, 8, 6, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        DmaSet(3, gBgTileBackup, gSpriteEntries, 0x84000400);
        gGameMode = gGameWork.debugValues[0];
        gGameState = gGameWork.debugValues[1];
        gGameSubState = gGameWork.debugValues[2];
    }
}

void debug_medal_update(void) {
    gDebugMedalHandlers[gGameWork.debugSubState]();
}

void debug_medal_input(void) {
    u8 b;
    u8 slot;

    if (KEYS_LO(gNewKeys) & 0x40) {
        if (gGameWork.debugRow == 0)
            gGameWork.debugRow = 2;
        else
            gGameWork.debugRow--;
    }
    if (KEYS_LO(gNewKeys) & 0x80) {
        if (gGameWork.debugRow == 2)
            gGameWork.debugRow = 0;
        else
            gGameWork.debugRow++;
    }
    switch (gGameWork.debugRow) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugMedalLabels[0], gGameWork.textBuf, 8);
            render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugMedalLabels[1], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugMedalLabels[2], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugMedalLabels[1], gGameWork.textBuf, 8);
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugMedalLabels[0], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugMedalLabels[2], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    default:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x18, 8);
        else {
            memcpy_bytes_0803F63C(gDebugMedalLabels[2], gGameWork.textBuf, 8);
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x18, 2, 6, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugMedalLabels[1], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugMedalLabels[0], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gGameWork.debugValues[gGameWork.debugRow] == 29)
            gGameWork.debugValues[gGameWork.debugRow] = 0;
        else
            gGameWork.debugValues[gGameWork.debugRow]++;
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gGameWork.debugValues[gGameWork.debugRow] == 0)
            gGameWork.debugValues[gGameWork.debugRow] = 29;
        else
            gGameWork.debugValues[gGameWork.debugRow]--;
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[0]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[1]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x23, 8, 4, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x26, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[2]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x26, 8, 6, 3, 15, 1, 0);
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        switch (gGameWork.debugRow) {
        case 0:
            if (gGameWork.debugValues[0] < 30 && !find_medal_slot_by_id(gGameWork.debugValues[0])) {
                slot = medal_add_by_id(gGameWork.debugValues[gGameWork.debugRow]);
                memcpy_bytes_0803F63C((void *)gMedalNames[gGameWork.debugValues[gGameWork.debugRow]],
                                      gMedals[slot].name, 11);
            }
            break;
        case 1:
            if (gGameWork.debugValues[1] < 30 && find_medal_slot_by_id(gGameWork.debugValues[1]))
                medal_remove_by_id(gGameWork.debugValues[gGameWork.debugRow]);
            break;
        default:
            for (gGameWork.debugValues[2] = b; gGameWork.debugValues[2] < 30; gGameWork.debugValues[2]++) {
                if (!find_medal_slot_by_id(gGameWork.debugValues[2])) {
                    slot = medal_add_by_id(gGameWork.debugValues[2]);
                    memcpy_bytes_0803F63C((void *)gMedalNames[gGameWork.debugValues[2]], gMedals[slot].name, 11);
                }
            }
            break;
        }
    }
}

void debug_parts_update(void) {
    gDebugPartsHandlers[gGameWork.debugSubState]();
}

void debug_parts_input(void) {
    u8 b;

    if (KEYS_LO(gNewKeys) & 0x40) {
        if (gGameWork.debugRow == 0)
            gGameWork.debugRow = 2;
        else
            gGameWork.debugRow--;
    }
    if (KEYS_LO(gNewKeys) & 0x80) {
        if (gGameWork.debugRow == 2)
            gGameWork.debugRow = 0;
        else
            gGameWork.debugRow++;
    }
    switch (gGameWork.debugRow) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugPartsLabels[0], gGameWork.textBuf, 8);
            render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugPartsLabels[1], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugPartsLabels[2], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugPartsLabels[1], gGameWork.textBuf, 8);
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugPartsLabels[0], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugPartsLabels[2], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    default:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x18, 8);
        else {
            memcpy_bytes_0803F63C(gDebugPartsLabels[2], gGameWork.textBuf, 8);
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x18, 2, 6, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugPartsLabels[1], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugPartsLabels[0], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gGameWork.debugValues[gGameWork.debugRow] == 0x77)
            gGameWork.debugValues[gGameWork.debugRow] = 0;
        else
            gGameWork.debugValues[gGameWork.debugRow]++;
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gGameWork.debugValues[gGameWork.debugRow] == 0)
            gGameWork.debugValues[gGameWork.debugRow] = 0x77;
        else
            gGameWork.debugValues[gGameWork.debugRow]--;
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[0]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[1]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x23, 8, 4, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x26, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[2]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x26, 8, 6, 3, 15, 1, 0);
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        switch (gGameWork.debugRow) {
        case 0:
            if (gGameWork.debugValues[0] < 0x78) {
                medapart_add_quantity(gGameWork.debugValues[0], 0, 1);
                medapart_add_quantity(gGameWork.debugValues[gGameWork.debugRow], 1, 1);
                medapart_add_quantity(gGameWork.debugValues[gGameWork.debugRow], 2, 1);
                medapart_add_quantity(gGameWork.debugValues[gGameWork.debugRow], 3, 1);
            }
            break;
        case 1:
            if (gGameWork.debugValues[1] < 0x78) {
                reduce_medapart_stat(gGameWork.debugValues[1], 0, 1);
                reduce_medapart_stat(gGameWork.debugValues[gGameWork.debugRow], 1, 1);
                reduce_medapart_stat(gGameWork.debugValues[gGameWork.debugRow], 2, 1);
                reduce_medapart_stat(gGameWork.debugValues[gGameWork.debugRow], 3, 1);
            }
            break;
        default:
            for (gGameWork.debugValues[2] = b; gGameWork.debugValues[2] < 0x78; gGameWork.debugValues[2]++) {
                medapart_add_quantity(gGameWork.debugValues[2], 0, 1);
                medapart_add_quantity(gGameWork.debugValues[2], 1, 1);
                medapart_add_quantity(gGameWork.debugValues[2], 2, 1);
                medapart_add_quantity(gGameWork.debugValues[2], 3, 1);
            }
            break;
        }
    }
}

void debug_tinpet_update(void) {
    gDebugTinpetHandlers[gGameWork.debugSubState]();
}

void debug_tinpet_input(void) {
    if (gFrameCounter & 4)
        clear_battle_sprite_slot(8, 8);
    else {
        memcpy_bytes_0803F63C(gDebugTinpetLabels[0], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
    }
    if (KEYS_LO(gRepeatKeys) & 0x30)
        gGameWork.debugValues[gGameWork.debugRow] ^= 1;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[0]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x20, 8, 2, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        if (!team_is_full())
            team_add_tinpet(gGameWork.debugValues[0]);
    }
}

void debug_item_update(void) {
    gDebugItemHandlers[gGameWork.debugSubState]();
}

void debug_item_input(void) {
    u8 b;

    if (KEYS_LO(gNewKeys) & 0x40) {
        if (gGameWork.debugRow == 0)
            gGameWork.debugRow = 2;
        else
            gGameWork.debugRow--;
    }
    if (KEYS_LO(gNewKeys) & 0x80) {
        if (gGameWork.debugRow == 2)
            gGameWork.debugRow = 0;
        else
            gGameWork.debugRow++;
    }
    switch (gGameWork.debugRow) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugItemLabels[0], gGameWork.textBuf, 8);
            render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugItemLabels[1], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugItemLabels[2], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugItemLabels[1], gGameWork.textBuf, 8);
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugItemLabels[0], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugItemLabels[2], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    default:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x18, 8);
        else {
            memcpy_bytes_0803F63C(gDebugItemLabels[2], gGameWork.textBuf, 8);
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x18, 2, 6, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugItemLabels[1], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugItemLabels[0], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gGameWork.debugValues[gGameWork.debugRow] == 0x3E)
            gGameWork.debugValues[gGameWork.debugRow] = 0;
        else
            gGameWork.debugValues[gGameWork.debugRow]++;
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gGameWork.debugValues[gGameWork.debugRow] == 0)
            gGameWork.debugValues[gGameWork.debugRow] = 0x3E;
        else
            gGameWork.debugValues[gGameWork.debugRow]--;
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[0]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[1]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x23, 8, 4, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x26, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[2]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x26, 8, 6, 3, 15, 1, 0);
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        switch (gGameWork.debugRow) {
        case 0:
            if (gGameWork.debugValues[0] < 0x40)
                item_add_quantity(gGameWork.debugValues[0], 1);
            break;
        case 1:
            if (gGameWork.debugValues[1] < 0x40)
                item_remove_quantity(gGameWork.debugValues[1], 1);
            break;
        default:
            for (gGameWork.debugValues[2] = b; gGameWork.debugValues[2] < 0x3F; gGameWork.debugValues[2]++)
                item_add_quantity(gGameWork.debugValues[2], 1);
            break;
        }
    }
}

void debug_face_update(void) {
    gDebugFaceHandlers[gGameWork.debugSubState]();
}

void debug_face_input(void) {
    u8 b;

    if (KEY_BITS(gNewKeys).up | KEY_BITS(gNewKeys).down)
        gGameWork.debugRow ^= 1;
    switch (gGameWork.debugRow) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugFaceLabels[0], gGameWork.textBuf, 8);
            render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugFaceLabels[1], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 2, 4, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugFaceLabels[1], gGameWork.textBuf, 8);
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugFaceLabels[0], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gGameWork.debugRow == 0) {
            if (gGameWork.debugValues[gGameWork.debugRow] == 0xAF)
                gGameWork.debugValues[gGameWork.debugRow] = 0;
            else
                gGameWork.debugValues[gGameWork.debugRow]++;
        } else {
            if (gGameWork.debugValues[gGameWork.debugRow] == 8)
                gGameWork.debugValues[gGameWork.debugRow] = 0;
            else
                gGameWork.debugValues[gGameWork.debugRow]++;
        }
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gGameWork.debugRow == 0) {
            if (gGameWork.debugValues[gGameWork.debugRow] == 0)
                gGameWork.debugValues[gGameWork.debugRow] = 0xAF;
            else
                gGameWork.debugValues[gGameWork.debugRow]--;
        } else {
            if (gGameWork.debugValues[gGameWork.debugRow] == 0)
                gGameWork.debugValues[gGameWork.debugRow] = 8;
            else
                gGameWork.debugValues[gGameWork.debugRow]--;
        }
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[0]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[1]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x23, 8, 4, 3, 15, 1, 0);
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        vram_fill_tilemap_rect(0x11, 8, 0, 7, REG_BG0CNT, 0);
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        load_bg0_tilemap(gGameWork.debugValues[0], gGameWork.debugValues[1], 0, 7, 1);
        load_bg0_tilemap(gGameWork.debugValues[0], gGameWork.debugValues[1], 9, 7, b);
    }
}

void debug_mdlpic_update(void) {
    gDebugMdlpicHandlers[gGameWork.debugSubState]();
}

void debug_mdlpic_input(void) {
    if (KEY_BITS(gNewKeys).up | KEY_BITS(gNewKeys).down)
        gGameWork.debugRow ^= 1;
    switch (gGameWork.debugRow) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugFaceLabels[0], gGameWork.textBuf, 8);
            render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugFaceLabels[1], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 2, 4, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugFaceLabels[1], gGameWork.textBuf, 8);
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugFaceLabels[0], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gGameWork.debugRow == 0) {
            if (gGameWork.debugValues[gGameWork.debugRow] == 0x1D)
                gGameWork.debugValues[gGameWork.debugRow] = 0;
            else
                gGameWork.debugValues[gGameWork.debugRow]++;
        } else {
            if (gGameWork.debugValues[gGameWork.debugRow] == 4)
                gGameWork.debugValues[gGameWork.debugRow] = 0;
            else
                gGameWork.debugValues[gGameWork.debugRow]++;
        }
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gGameWork.debugRow == 0) {
            if (gGameWork.debugValues[gGameWork.debugRow] == 0)
                gGameWork.debugValues[gGameWork.debugRow] = 0x1D;
            else
                gGameWork.debugValues[gGameWork.debugRow]--;
        } else {
            if (gGameWork.debugValues[gGameWork.debugRow] == 0)
                gGameWork.debugValues[gGameWork.debugRow] = 4;
            else
                gGameWork.debugValues[gGameWork.debugRow]--;
        }
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[0]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[1]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x23, 8, 4, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2) {
        clear_battle_sprite_slot(0, 1);
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        DmaSet(3, gUnk_084E2E98, 0x050003E0, 0x84000008);
        lz_decompress_dispatch(gMedalSpriteGfx[gGameWork.debugValues[0]][gGameWork.debugValues[1]], (void *)0x06010000);
        gSpriteEntries[0].unk0 = 0xC004;
        gSpriteEntries[0].unk2 = 0x40;
        gSpriteEntries[0].unk4 = 0x50;
        gSpriteEntries[0].unk6 = 0x200;
        gSpriteEntries[0].unkA = 15;
        gSpriteEntries[0].unk1C = 0;
        gSpriteEntries[0].unkB = 0xC0;
    }
}

void debug_rndtk_update(void) {
    gDebugRndTkHandlers[gGameWork.debugSubState]();
}

void debug_rndtk_input(void) {
    if (gFrameCounter & 4)
        clear_battle_sprite_slot(8, 8);
    else {
        memcpy_bytes_0803F63C(gDebugRndTkLabels[0], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
    }
    if (KEYS_LO(gRepeatKeys) & 0x30)
        gFieldWork.encounters_off ^= 1;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gFieldWork.encounters_off);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x20, 8, 2, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    }
}

void debug_battle_update(void) {
    gDebugBattleHandlers[gGameWork.debugSubState]();
}

void debug_battle_input(void) {
    u8 b;

    if (gFrameCounter & 4)
        clear_battle_sprite_slot(8, 8);
    else {
        memcpy_bytes_0803F63C(gDebugBattleLabels[0], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
    }
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gGameWork.debugValues[gGameWork.debugRow]++;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gGameWork.debugValues[gGameWork.debugRow]--;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[gGameWork.debugRow]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x20, 8, 2, 3, 15, 1, 0);
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        clear_battle_sprite_slot(8, 0x21);
        gFieldWork.battle_flags = b;
        gFieldWork.story_battle = b;
        gFieldWork.fixed_battle = 1;
        gFieldWork.battle_id = gGameWork.debugValues[gGameWork.debugRow];
        gGameState = 6;
        gGameSubState = b;
    }
}

void debug_sound_update(void) {
    gDebugSoundHandlers[gGameWork.debugSubState]();
}

void debug_sound_input(void) {
    if (KEY_BITS(gNewKeys).up | KEY_BITS(gNewKeys).down)
        gGameWork.debugRow ^= 1;
    switch (gGameWork.debugRow) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugSoundLabels[0], gGameWork.textBuf, 8);
            render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugSoundLabels[1], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 2, 4, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugSoundLabels[1], gGameWork.textBuf, 8);
            render_text_sprites_08040DB8(gGameWork.textBuf, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugSoundLabels[0], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gGameWork.debugRow == 0) {
            if (gGameWork.debugValues[gGameWork.debugRow] == 0x7F)
                gGameWork.debugValues[gGameWork.debugRow] = 0;
            else
                gGameWork.debugValues[gGameWork.debugRow]++;
        } else {
            if (gGameWork.debugValues[gGameWork.debugRow] == 0x35)
                gGameWork.debugValues[gGameWork.debugRow] = 0;
            else
                gGameWork.debugValues[gGameWork.debugRow]++;
        }
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gGameWork.debugRow == 0) {
            if (gGameWork.debugValues[gGameWork.debugRow] == 0)
                gGameWork.debugValues[gGameWork.debugRow] = 0x7F;
            else
                gGameWork.debugValues[gGameWork.debugRow]--;
        } else {
            if (gGameWork.debugValues[gGameWork.debugRow] == 0)
                gGameWork.debugValues[gGameWork.debugRow] = 0x35;
            else
                gGameWork.debugValues[gGameWork.debugRow]--;
        }
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[0]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[1]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x23, 8, 4, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2) {
        play_song(0);
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        if (gGameWork.debugRow == 0)
            play_sound_effect(gGameWork.debugValues[gGameWork.debugRow]);
        else
            play_song(gGameWork.debugValues[gGameWork.debugRow]);
    }
}

void debug_motion_update(void) {
    gDebugMotionHandlers[gGameWork.debugSubState]();
}

void debug_motion_init(void) {
    clear_battle_sprite_slot(0, 0x80);
    gGameWork.debugMotion = 0;
    gGameWork.debugSubState++;
}

void debug_motion_load(void) {
    init_scene_buffers_080445F4();
    setup_scene_with_bg_and_sprites(0, gGameWork.debugMotion, gGameWork.debugMotion, gGameWork.debugMotion,
                                    gGameWork.debugMotion, 0x38, 0x68, 0, 4, 0, 0, 0);
    setup_scene_with_bg_and_sprites(1, gGameWork.debugMotion, gGameWork.debugMotion, gGameWork.debugMotion,
                                    gGameWork.debugMotion, 0xB8, 0x30, 0, 8, 1, 0, 1);
    gGameWork.debugSubState++;
}

void debug_motion_input(void) {
    vu32 fill;
    u8 b;

    fill = 0x200;
    DmaSet(3, &fill, gSpriteWork->oamBuf, 0x85000100);
    draw_medabot_sprite(0, gGameWork.debugMotion, gGameWork.debugMotion, gGameWork.debugMotion, gGameWork.debugMotion,
                        0x38, 0x68, 0, 4, 0, 1, 0, 0);
    draw_medabot_sprite(1, gGameWork.debugMotion, gGameWork.debugMotion, gGameWork.debugMotion, gGameWork.debugMotion,
                        0xB8, 0x30, 0, 8, 1, 1, 1, 0x28);
    if (gFrameCounter & 4)
        clear_battle_sprite_slot(8, 8);
    else {
        memcpy_bytes_0803F63C(gDebugMotionLabels[0], gGameWork.textBuf, 8);
        render_text_sprites_08040DB8(gGameWork.textBuf, 8, 2, 2, 8, 15, 1, 0);
    }
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gGameWork.debugValues[gGameWork.debugRow]++;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gGameWork.debugValues[gGameWork.debugRow]--;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.textBuf, gGameWork.debugValues[gGameWork.debugRow]);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x20, 8, 2, 3, 15, 1, 0);
    if (KEYS_LO(gRepeatKeys) & 8) {
        if (gGameWork.debugMotion == 0x79)
            gGameWork.debugMotion = 0;
        else
            gGameWork.debugMotion++;
        gGameWork.debugSubState--;
    } else if ((b = KEYS_LO(gRepeatKeys) & 4)) {
        if (gGameWork.debugMotion == 0)
            gGameWork.debugMotion = 0x79;
        else
            gGameWork.debugMotion--;
        gGameWork.debugSubState--;
    } else if (KEYS_LO(gNewKeys) & 2) {
        clear_battle_sprite_slot(8, 0x21);
        gVBlankOamMode = b;
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1)
        gGameWork.debugSubState++;
}

void debug_motion_play(void) {
    vu32 fill;

    fill = 0x200;
    DmaSet(3, &fill, gSpriteWork->oamBuf, 0x85000100);
    draw_medabot_sprite(0, gGameWork.debugMotion, gGameWork.debugMotion, gGameWork.debugMotion, gGameWork.debugMotion,
                        0x38, 0x68, 0, 4, 0, 1, 0, 0);
    draw_medabot_sprite(1, gGameWork.debugMotion, gGameWork.debugMotion, gGameWork.debugMotion, gGameWork.debugMotion,
                        0xB8, 0x30, 0, 8, 1, 1, 1, 0x28);
    medabot_pose_anim_step(0, gGameWork.debugValues[gGameWork.debugRow], gGameWork.debugMotion);
    medabot_pose_anim_step(1, gGameWork.debugValues[gGameWork.debugRow], gGameWork.debugMotion);
    if (KEYS_LO(gNewKeys) & 2)
        gGameWork.debugSubState -= 2;
}
