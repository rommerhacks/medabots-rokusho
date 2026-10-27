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
    DmaSet(3, gSpriteEntries, gUnk_02020800, 0x84000400);
    zero = 0;
    DmaSet(3, &zero, gSpriteEntries, 0x85000400);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    DmaSet(3, gUnk_084E2E38, 0x050003E0, 0x84000008);
    gGameSubState++;
}

void debug_menu_select_input(void) {
    u8 b;

    if (KEYS_LO(gNewKeys) & 0x10) {
        if (gGameWork.unk32 == 10)
            gGameWork.unk32 = 0;
        else
            gGameWork.unk32++;
    }
    if (KEYS_LO(gNewKeys) & 0x20) {
        if (gGameWork.unk32 == 0)
            gGameWork.unk32 = 10;
        else
            gGameWork.unk32--;
    }
    if (gFrameCounter & 4)
        clear_battle_sprite_slot(0, 8);
    else {
        memcpy_bytes_0803F63C(gDebugMenuLabels[gGameWork.unk32], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0, 1, 0, 8, 15, 1, 0);
    }
    if ((b = KEYS_LO(gNewKeys) & 2))
        gGameSubState++;
    else if (KEYS_LO(gNewKeys) & 1) {
        memcpy_bytes_0803F63C(gDebugMenuLabels[gGameWork.unk32], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0, 1, 0, 8, 15, 1, b);
        gGameWork.unk33 = b;
        gGameWork.unk34 = b;
        gGameWork.unk35[0] = b;
        gGameWork.unk35[1] = b;
        gGameWork.unk35[2] = b;
        gGameSubState = 3;
    }
}

void debug_menu_exit(void) {
    DmaSet(3, gUnk_02020800, gSpriteEntries, 0x84000400);
    gGameState = gGameWork.unk30;
    gGameSubState = gGameWork.unk31;
}

void debug_menu_run_entry(void) {
    gDebugMenuEntryHandlers[gGameWork.unk32]();
}

void debug_process_update(void) {
    gDebugProcessHandlers[gGameWork.unk33]();
}

void debug_process_input(void) {
    if (KEYS_LO(gNewKeys) & 0x40) {
        if (gGameWork.unk34 == 0)
            gGameWork.unk34 = 2;
        else
            gGameWork.unk34--;
    }
    if (KEYS_LO(gNewKeys) & 0x80) {
        if (gGameWork.unk34 == 2)
            gGameWork.unk34 = 0;
        else
            gGameWork.unk34++;
    }
    switch (gGameWork.unk34) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugProcessLabels[0], gGameWork.unk9E, 8);
            render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugProcessLabels[1], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugProcessLabels[2], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugProcessLabels[1], gGameWork.unk9E, 8);
            render_text_sprites_08040DB8(gGameWork.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugProcessLabels[0], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugProcessLabels[2], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    default:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x18, 8);
        else {
            memcpy_bytes_0803F63C(gDebugProcessLabels[2], gGameWork.unk9E, 8);
            render_text_sprites_08040DB8(gGameWork.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugProcessLabels[1], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugProcessLabels[0], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gGameWork.unk35[gGameWork.unk34]++;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gGameWork.unk35[gGameWork.unk34]--;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[0]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[1]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x23, 8, 4, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x26, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[2]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x26, 8, 6, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        DmaSet(3, gUnk_02020800, gSpriteEntries, 0x84000400);
        gGameMode = gGameWork.unk35[0];
        gGameState = gGameWork.unk35[1];
        gGameSubState = gGameWork.unk35[2];
    }
}

void debug_medal_update(void) {
    gDebugMedalHandlers[gGameWork.unk33]();
}

void debug_medal_input(void) {
    u8 b;
    u8 slot;

    if (KEYS_LO(gNewKeys) & 0x40) {
        if (gGameWork.unk34 == 0)
            gGameWork.unk34 = 2;
        else
            gGameWork.unk34--;
    }
    if (KEYS_LO(gNewKeys) & 0x80) {
        if (gGameWork.unk34 == 2)
            gGameWork.unk34 = 0;
        else
            gGameWork.unk34++;
    }
    switch (gGameWork.unk34) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugMedalLabels[0], gGameWork.unk9E, 8);
            render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugMedalLabels[1], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugMedalLabels[2], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugMedalLabels[1], gGameWork.unk9E, 8);
            render_text_sprites_08040DB8(gGameWork.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugMedalLabels[0], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugMedalLabels[2], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    default:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x18, 8);
        else {
            memcpy_bytes_0803F63C(gDebugMedalLabels[2], gGameWork.unk9E, 8);
            render_text_sprites_08040DB8(gGameWork.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugMedalLabels[1], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugMedalLabels[0], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gGameWork.unk35[gGameWork.unk34] == 29)
            gGameWork.unk35[gGameWork.unk34] = 0;
        else
            gGameWork.unk35[gGameWork.unk34]++;
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gGameWork.unk35[gGameWork.unk34] == 0)
            gGameWork.unk35[gGameWork.unk34] = 29;
        else
            gGameWork.unk35[gGameWork.unk34]--;
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[0]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[1]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x23, 8, 4, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x26, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[2]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x26, 8, 6, 3, 15, 1, 0);
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        switch (gGameWork.unk34) {
        case 0:
            if (gGameWork.unk35[0] < 30 && !find_medal_slot_by_id(gGameWork.unk35[0])) {
                slot = medal_add_by_id(gGameWork.unk35[gGameWork.unk34]);
                memcpy_bytes_0803F63C((void *)gMedalNames[gGameWork.unk35[gGameWork.unk34]], gMedals[slot].name, 11);
            }
            break;
        case 1:
            if (gGameWork.unk35[1] < 30 && find_medal_slot_by_id(gGameWork.unk35[1]))
                medal_remove_by_id(gGameWork.unk35[gGameWork.unk34]);
            break;
        default:
            for (gGameWork.unk35[2] = b; gGameWork.unk35[2] < 30; gGameWork.unk35[2]++) {
                if (!find_medal_slot_by_id(gGameWork.unk35[2])) {
                    slot = medal_add_by_id(gGameWork.unk35[2]);
                    memcpy_bytes_0803F63C((void *)gMedalNames[gGameWork.unk35[2]], gMedals[slot].name, 11);
                }
            }
            break;
        }
    }
}

void debug_parts_update(void) {
    gDebugPartsHandlers[gGameWork.unk33]();
}

void debug_parts_input(void) {
    u8 b;

    if (KEYS_LO(gNewKeys) & 0x40) {
        if (gGameWork.unk34 == 0)
            gGameWork.unk34 = 2;
        else
            gGameWork.unk34--;
    }
    if (KEYS_LO(gNewKeys) & 0x80) {
        if (gGameWork.unk34 == 2)
            gGameWork.unk34 = 0;
        else
            gGameWork.unk34++;
    }
    switch (gGameWork.unk34) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugPartsLabels[0], gGameWork.unk9E, 8);
            render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugPartsLabels[1], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugPartsLabels[2], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugPartsLabels[1], gGameWork.unk9E, 8);
            render_text_sprites_08040DB8(gGameWork.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugPartsLabels[0], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugPartsLabels[2], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    default:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x18, 8);
        else {
            memcpy_bytes_0803F63C(gDebugPartsLabels[2], gGameWork.unk9E, 8);
            render_text_sprites_08040DB8(gGameWork.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugPartsLabels[1], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugPartsLabels[0], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gGameWork.unk35[gGameWork.unk34] == 0x77)
            gGameWork.unk35[gGameWork.unk34] = 0;
        else
            gGameWork.unk35[gGameWork.unk34]++;
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gGameWork.unk35[gGameWork.unk34] == 0)
            gGameWork.unk35[gGameWork.unk34] = 0x77;
        else
            gGameWork.unk35[gGameWork.unk34]--;
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[0]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[1]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x23, 8, 4, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x26, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[2]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x26, 8, 6, 3, 15, 1, 0);
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        switch (gGameWork.unk34) {
        case 0:
            if (gGameWork.unk35[0] < 0x78) {
                medapart_add_quantity(gGameWork.unk35[0], 0, 1);
                medapart_add_quantity(gGameWork.unk35[gGameWork.unk34], 1, 1);
                medapart_add_quantity(gGameWork.unk35[gGameWork.unk34], 2, 1);
                medapart_add_quantity(gGameWork.unk35[gGameWork.unk34], 3, 1);
            }
            break;
        case 1:
            if (gGameWork.unk35[1] < 0x78) {
                reduce_medapart_stat(gGameWork.unk35[1], 0, 1);
                reduce_medapart_stat(gGameWork.unk35[gGameWork.unk34], 1, 1);
                reduce_medapart_stat(gGameWork.unk35[gGameWork.unk34], 2, 1);
                reduce_medapart_stat(gGameWork.unk35[gGameWork.unk34], 3, 1);
            }
            break;
        default:
            for (gGameWork.unk35[2] = b; gGameWork.unk35[2] < 0x78; gGameWork.unk35[2]++) {
                medapart_add_quantity(gGameWork.unk35[2], 0, 1);
                medapart_add_quantity(gGameWork.unk35[2], 1, 1);
                medapart_add_quantity(gGameWork.unk35[2], 2, 1);
                medapart_add_quantity(gGameWork.unk35[2], 3, 1);
            }
            break;
        }
    }
}

void debug_tinpet_update(void) {
    gDebugTinpetHandlers[gGameWork.unk33]();
}

void debug_tinpet_input(void) {
    if (gFrameCounter & 4)
        clear_battle_sprite_slot(8, 8);
    else {
        memcpy_bytes_0803F63C(gDebugTinpetLabels[0], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
    }
    if (KEYS_LO(gRepeatKeys) & 0x30)
        gGameWork.unk35[gGameWork.unk34] ^= 1;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[0]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        if (!team_is_full())
            team_add_tinpet(gGameWork.unk35[0]);
    }
}

void debug_item_update(void) {
    gDebugItemHandlers[gGameWork.unk33]();
}

void debug_item_input(void) {
    u8 b;

    if (KEYS_LO(gNewKeys) & 0x40) {
        if (gGameWork.unk34 == 0)
            gGameWork.unk34 = 2;
        else
            gGameWork.unk34--;
    }
    if (KEYS_LO(gNewKeys) & 0x80) {
        if (gGameWork.unk34 == 2)
            gGameWork.unk34 = 0;
        else
            gGameWork.unk34++;
    }
    switch (gGameWork.unk34) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugItemLabels[0], gGameWork.unk9E, 8);
            render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugItemLabels[1], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugItemLabels[2], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugItemLabels[1], gGameWork.unk9E, 8);
            render_text_sprites_08040DB8(gGameWork.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugItemLabels[0], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugItemLabels[2], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    default:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x18, 8);
        else {
            memcpy_bytes_0803F63C(gDebugItemLabels[2], gGameWork.unk9E, 8);
            render_text_sprites_08040DB8(gGameWork.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugItemLabels[1], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugItemLabels[0], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gGameWork.unk35[gGameWork.unk34] == 0x3E)
            gGameWork.unk35[gGameWork.unk34] = 0;
        else
            gGameWork.unk35[gGameWork.unk34]++;
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gGameWork.unk35[gGameWork.unk34] == 0)
            gGameWork.unk35[gGameWork.unk34] = 0x3E;
        else
            gGameWork.unk35[gGameWork.unk34]--;
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[0]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[1]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x23, 8, 4, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x26, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[2]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x26, 8, 6, 3, 15, 1, 0);
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        switch (gGameWork.unk34) {
        case 0:
            if (gGameWork.unk35[0] < 0x40)
                item_add_quantity(gGameWork.unk35[0], 1);
            break;
        case 1:
            if (gGameWork.unk35[1] < 0x40)
                item_remove_quantity(gGameWork.unk35[1], 1);
            break;
        default:
            for (gGameWork.unk35[2] = b; gGameWork.unk35[2] < 0x3F; gGameWork.unk35[2]++)
                item_add_quantity(gGameWork.unk35[2], 1);
            break;
        }
    }
}

void debug_face_update(void) {
    gDebugFaceHandlers[gGameWork.unk33]();
}

void debug_face_input(void) {
    u8 b;

    if (KEY_BITS(gNewKeys).up | KEY_BITS(gNewKeys).down)
        gGameWork.unk34 ^= 1;
    switch (gGameWork.unk34) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugFaceLabels[0], gGameWork.unk9E, 8);
            render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugFaceLabels[1], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugFaceLabels[1], gGameWork.unk9E, 8);
            render_text_sprites_08040DB8(gGameWork.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugFaceLabels[0], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gGameWork.unk34 == 0) {
            if (gGameWork.unk35[gGameWork.unk34] == 0xAF)
                gGameWork.unk35[gGameWork.unk34] = 0;
            else
                gGameWork.unk35[gGameWork.unk34]++;
        } else {
            if (gGameWork.unk35[gGameWork.unk34] == 8)
                gGameWork.unk35[gGameWork.unk34] = 0;
            else
                gGameWork.unk35[gGameWork.unk34]++;
        }
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gGameWork.unk34 == 0) {
            if (gGameWork.unk35[gGameWork.unk34] == 0)
                gGameWork.unk35[gGameWork.unk34] = 0xAF;
            else
                gGameWork.unk35[gGameWork.unk34]--;
        } else {
            if (gGameWork.unk35[gGameWork.unk34] == 0)
                gGameWork.unk35[gGameWork.unk34] = 8;
            else
                gGameWork.unk35[gGameWork.unk34]--;
        }
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[0]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[1]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x23, 8, 4, 3, 15, 1, 0);
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        vram_fill_tilemap_rect(0x11, 8, 0, 7, REG_BG0CNT, 0);
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        load_bg0_tilemap(gGameWork.unk35[0], gGameWork.unk35[1], 0, 7, 1);
        load_bg0_tilemap(gGameWork.unk35[0], gGameWork.unk35[1], 9, 7, b);
    }
}

void debug_mdlpic_update(void) {
    gDebugMdlpicHandlers[gGameWork.unk33]();
}

void debug_mdlpic_input(void) {
    if (KEY_BITS(gNewKeys).up | KEY_BITS(gNewKeys).down)
        gGameWork.unk34 ^= 1;
    switch (gGameWork.unk34) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugFaceLabels[0], gGameWork.unk9E, 8);
            render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugFaceLabels[1], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugFaceLabels[1], gGameWork.unk9E, 8);
            render_text_sprites_08040DB8(gGameWork.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugFaceLabels[0], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gGameWork.unk34 == 0) {
            if (gGameWork.unk35[gGameWork.unk34] == 0x1D)
                gGameWork.unk35[gGameWork.unk34] = 0;
            else
                gGameWork.unk35[gGameWork.unk34]++;
        } else {
            if (gGameWork.unk35[gGameWork.unk34] == 4)
                gGameWork.unk35[gGameWork.unk34] = 0;
            else
                gGameWork.unk35[gGameWork.unk34]++;
        }
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gGameWork.unk34 == 0) {
            if (gGameWork.unk35[gGameWork.unk34] == 0)
                gGameWork.unk35[gGameWork.unk34] = 0x1D;
            else
                gGameWork.unk35[gGameWork.unk34]--;
        } else {
            if (gGameWork.unk35[gGameWork.unk34] == 0)
                gGameWork.unk35[gGameWork.unk34] = 4;
            else
                gGameWork.unk35[gGameWork.unk34]--;
        }
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[0]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[1]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x23, 8, 4, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2) {
        clear_battle_sprite_slot(0, 1);
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        DmaSet(3, gUnk_084E2E98, 0x050003E0, 0x84000008);
        lz_decompress_dispatch(gUnk_083AC494[gGameWork.unk35[0]][gGameWork.unk35[1]], (void *)0x06010000);
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
    gDebugRndTkHandlers[gGameWork.unk33]();
}

void debug_rndtk_input(void) {
    if (gFrameCounter & 4)
        clear_battle_sprite_slot(8, 8);
    else {
        memcpy_bytes_0803F63C(gDebugRndTkLabels[0], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
    }
    if (KEYS_LO(gRepeatKeys) & 0x30)
        gUnk_030057E0.encounters_off ^= 1;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gUnk_030057E0.encounters_off);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    }
}

void debug_battle_update(void) {
    gDebugBattleHandlers[gGameWork.unk33]();
}

void debug_battle_input(void) {
    u8 b;

    if (gFrameCounter & 4)
        clear_battle_sprite_slot(8, 8);
    else {
        memcpy_bytes_0803F63C(gDebugBattleLabels[0], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
    }
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gGameWork.unk35[gGameWork.unk34]++;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gGameWork.unk35[gGameWork.unk34]--;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[gGameWork.unk34]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        clear_battle_sprite_slot(8, 0x21);
        gUnk_030057E0.unkC2E = b;
        gUnk_030057E0.unkC2F = b;
        gUnk_030057E0.unkC2D = 1;
        gUnk_030057E0.unkC2A = gGameWork.unk35[gGameWork.unk34];
        gGameState = 6;
        gGameSubState = b;
    }
}

void debug_sound_update(void) {
    gDebugSoundHandlers[gGameWork.unk33]();
}

void debug_sound_input(void) {
    if (KEY_BITS(gNewKeys).up | KEY_BITS(gNewKeys).down)
        gGameWork.unk34 ^= 1;
    switch (gGameWork.unk34) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugSoundLabels[0], gGameWork.unk9E, 8);
            render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugSoundLabels[1], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugSoundLabels[1], gGameWork.unk9E, 8);
            render_text_sprites_08040DB8(gGameWork.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugSoundLabels[0], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gGameWork.unk34 == 0) {
            if (gGameWork.unk35[gGameWork.unk34] == 0x7F)
                gGameWork.unk35[gGameWork.unk34] = 0;
            else
                gGameWork.unk35[gGameWork.unk34]++;
        } else {
            if (gGameWork.unk35[gGameWork.unk34] == 0x35)
                gGameWork.unk35[gGameWork.unk34] = 0;
            else
                gGameWork.unk35[gGameWork.unk34]++;
        }
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gGameWork.unk34 == 0) {
            if (gGameWork.unk35[gGameWork.unk34] == 0)
                gGameWork.unk35[gGameWork.unk34] = 0x7F;
            else
                gGameWork.unk35[gGameWork.unk34]--;
        } else {
            if (gGameWork.unk35[gGameWork.unk34] == 0)
                gGameWork.unk35[gGameWork.unk34] = 0x35;
            else
                gGameWork.unk35[gGameWork.unk34]--;
        }
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[0]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[1]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x23, 8, 4, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2) {
        play_song(0);
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        if (gGameWork.unk34 == 0)
            play_sound_effect(gGameWork.unk35[gGameWork.unk34]);
        else
            play_song(gGameWork.unk35[gGameWork.unk34]);
    }
}

void debug_motion_update(void) {
    gDebugMotionHandlers[gGameWork.unk33]();
}

void debug_motion_init(void) {
    clear_battle_sprite_slot(0, 0x80);
    gGameWork.unk39 = 0;
    gGameWork.unk33++;
}

void debug_motion_load(void) {
    init_scene_buffers_080445F4();
    setup_scene_with_bg_and_sprites(0, gGameWork.unk39, gGameWork.unk39, gGameWork.unk39, gGameWork.unk39, 0x38, 0x68,
                                    0, 4, 0, 0, 0);
    setup_scene_with_bg_and_sprites(1, gGameWork.unk39, gGameWork.unk39, gGameWork.unk39, gGameWork.unk39, 0xB8, 0x30,
                                    0, 8, 1, 0, 1);
    gGameWork.unk33++;
}

void debug_motion_input(void) {
    vu32 fill;
    u8 b;

    fill = 0x200;
    DmaSet(3, &fill, gSpriteWork->oamBuf, 0x85000100);
    draw_medabot_sprite(0, gGameWork.unk39, gGameWork.unk39, gGameWork.unk39, gGameWork.unk39, 0x38, 0x68, 0, 4, 0, 1,
                        0, 0);
    draw_medabot_sprite(1, gGameWork.unk39, gGameWork.unk39, gGameWork.unk39, gGameWork.unk39, 0xB8, 0x30, 0, 8, 1, 1,
                        1, 0x28);
    if (gFrameCounter & 4)
        clear_battle_sprite_slot(8, 8);
    else {
        memcpy_bytes_0803F63C(gDebugMotionLabels[0], gGameWork.unk9E, 8);
        render_text_sprites_08040DB8(gGameWork.unk9E, 8, 2, 2, 8, 15, 1, 0);
    }
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gGameWork.unk35[gGameWork.unk34]++;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gGameWork.unk35[gGameWork.unk34]--;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gGameWork.unk9E, gGameWork.unk35[gGameWork.unk34]);
    render_text_sprites_08040DB8(gGameWork.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    if (KEYS_LO(gRepeatKeys) & 8) {
        if (gGameWork.unk39 == 0x79)
            gGameWork.unk39 = 0;
        else
            gGameWork.unk39++;
        gGameWork.unk33--;
    } else if ((b = KEYS_LO(gRepeatKeys) & 4)) {
        if (gGameWork.unk39 == 0)
            gGameWork.unk39 = 0x79;
        else
            gGameWork.unk39--;
        gGameWork.unk33--;
    } else if (KEYS_LO(gNewKeys) & 2) {
        clear_battle_sprite_slot(8, 0x21);
        gUnk_03000430 = b;
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1)
        gGameWork.unk33++;
}

void debug_motion_play(void) {
    vu32 fill;

    fill = 0x200;
    DmaSet(3, &fill, gSpriteWork->oamBuf, 0x85000100);
    draw_medabot_sprite(0, gGameWork.unk39, gGameWork.unk39, gGameWork.unk39, gGameWork.unk39, 0x38, 0x68, 0, 4, 0, 1,
                        0, 0);
    draw_medabot_sprite(1, gGameWork.unk39, gGameWork.unk39, gGameWork.unk39, gGameWork.unk39, 0xB8, 0x30, 0, 8, 1, 1,
                        1, 0x28);
    medabot_pose_anim_step(0, gGameWork.unk35[gGameWork.unk34], gGameWork.unk39);
    medabot_pose_anim_step(1, gGameWork.unk35[gGameWork.unk34], gGameWork.unk39);
    if (KEYS_LO(gNewKeys) & 2)
        gGameWork.unk33 -= 2;
}
