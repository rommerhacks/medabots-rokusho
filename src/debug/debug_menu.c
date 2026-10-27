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
    DmaSet(3, gUnk_03002C30, gUnk_02020800, 0x84000400);
    zero = 0;
    DmaSet(3, &zero, gUnk_03002C30, 0x85000400);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    DmaSet(3, gUnk_084E2E38, 0x050003E0, 0x84000008);
    gGameSubState++;
}

void debug_menu_select_input(void) {
    u8 b;

    if (KEYS_LO(gNewKeys) & 0x10) {
        if (gUnk_03000440.unk32 == 10)
            gUnk_03000440.unk32 = 0;
        else
            gUnk_03000440.unk32++;
    }
    if (KEYS_LO(gNewKeys) & 0x20) {
        if (gUnk_03000440.unk32 == 0)
            gUnk_03000440.unk32 = 10;
        else
            gUnk_03000440.unk32--;
    }
    if (gFrameCounter & 4)
        clear_battle_sprite_slot(0, 8);
    else {
        memcpy_bytes_0803F63C(gDebugMenuLabels[gUnk_03000440.unk32], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0, 1, 0, 8, 15, 1, 0);
    }
    if ((b = KEYS_LO(gNewKeys) & 2))
        gGameSubState++;
    else if (KEYS_LO(gNewKeys) & 1) {
        memcpy_bytes_0803F63C(gDebugMenuLabels[gUnk_03000440.unk32], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0, 1, 0, 8, 15, 1, b);
        gUnk_03000440.unk33 = b;
        gUnk_03000440.unk34 = b;
        gUnk_03000440.unk35[0] = b;
        gUnk_03000440.unk35[1] = b;
        gUnk_03000440.unk35[2] = b;
        gGameSubState = 3;
    }
}

void debug_menu_exit(void) {
    DmaSet(3, gUnk_02020800, gUnk_03002C30, 0x84000400);
    gGameState = gUnk_03000440.unk30;
    gGameSubState = gUnk_03000440.unk31;
}

void debug_menu_run_entry(void) {
    gDebugMenuEntryHandlers[gUnk_03000440.unk32]();
}

void debug_process_update(void) {
    gDebugProcessHandlers[gUnk_03000440.unk33]();
}

void debug_process_input(void) {
    if (KEYS_LO(gNewKeys) & 0x40) {
        if (gUnk_03000440.unk34 == 0)
            gUnk_03000440.unk34 = 2;
        else
            gUnk_03000440.unk34--;
    }
    if (KEYS_LO(gNewKeys) & 0x80) {
        if (gUnk_03000440.unk34 == 2)
            gUnk_03000440.unk34 = 0;
        else
            gUnk_03000440.unk34++;
    }
    switch (gUnk_03000440.unk34) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugProcessLabels[0], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugProcessLabels[1], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugProcessLabels[2], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugProcessLabels[1], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugProcessLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugProcessLabels[2], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    default:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x18, 8);
        else {
            memcpy_bytes_0803F63C(gDebugProcessLabels[2], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugProcessLabels[1], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugProcessLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gUnk_03000440.unk35[gUnk_03000440.unk34]++;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gUnk_03000440.unk35[gUnk_03000440.unk34]--;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[0]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[1]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x23, 8, 4, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x26, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[2]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x26, 8, 6, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        DmaSet(3, gUnk_02020800, gUnk_03002C30, 0x84000400);
        gGameMode = gUnk_03000440.unk35[0];
        gGameState = gUnk_03000440.unk35[1];
        gGameSubState = gUnk_03000440.unk35[2];
    }
}

void debug_medal_update(void) {
    gDebugMedalHandlers[gUnk_03000440.unk33]();
}

void debug_medal_input(void) {
    u8 b;
    u8 slot;

    if (KEYS_LO(gNewKeys) & 0x40) {
        if (gUnk_03000440.unk34 == 0)
            gUnk_03000440.unk34 = 2;
        else
            gUnk_03000440.unk34--;
    }
    if (KEYS_LO(gNewKeys) & 0x80) {
        if (gUnk_03000440.unk34 == 2)
            gUnk_03000440.unk34 = 0;
        else
            gUnk_03000440.unk34++;
    }
    switch (gUnk_03000440.unk34) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugMedalLabels[0], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugMedalLabels[1], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugMedalLabels[2], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugMedalLabels[1], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugMedalLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugMedalLabels[2], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    default:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x18, 8);
        else {
            memcpy_bytes_0803F63C(gDebugMedalLabels[2], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugMedalLabels[1], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugMedalLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 29)
            gUnk_03000440.unk35[gUnk_03000440.unk34] = 0;
        else
            gUnk_03000440.unk35[gUnk_03000440.unk34]++;
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0)
            gUnk_03000440.unk35[gUnk_03000440.unk34] = 29;
        else
            gUnk_03000440.unk35[gUnk_03000440.unk34]--;
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[0]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[1]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x23, 8, 4, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x26, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[2]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x26, 8, 6, 3, 15, 1, 0);
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        switch (gUnk_03000440.unk34) {
        case 0:
            if (gUnk_03000440.unk35[0] < 30 && !find_medal_slot_by_id(gUnk_03000440.unk35[0])) {
                slot = medal_add_by_id(gUnk_03000440.unk35[gUnk_03000440.unk34]);
                memcpy_bytes_0803F63C((void *)gUnk_083B6410[gUnk_03000440.unk35[gUnk_03000440.unk34]],
                                      gUnk_03000BE0[slot].unkA, 11);
            }
            break;
        case 1:
            if (gUnk_03000440.unk35[1] < 30 && find_medal_slot_by_id(gUnk_03000440.unk35[1]))
                medal_remove_by_id(gUnk_03000440.unk35[gUnk_03000440.unk34]);
            break;
        default:
            for (gUnk_03000440.unk35[2] = b; gUnk_03000440.unk35[2] < 30; gUnk_03000440.unk35[2]++) {
                if (!find_medal_slot_by_id(gUnk_03000440.unk35[2])) {
                    slot = medal_add_by_id(gUnk_03000440.unk35[2]);
                    memcpy_bytes_0803F63C((void *)gUnk_083B6410[gUnk_03000440.unk35[2]], gUnk_03000BE0[slot].unkA, 11);
                }
            }
            break;
        }
    }
}

void debug_parts_update(void) {
    gDebugPartsHandlers[gUnk_03000440.unk33]();
}

void debug_parts_input(void) {
    u8 b;

    if (KEYS_LO(gNewKeys) & 0x40) {
        if (gUnk_03000440.unk34 == 0)
            gUnk_03000440.unk34 = 2;
        else
            gUnk_03000440.unk34--;
    }
    if (KEYS_LO(gNewKeys) & 0x80) {
        if (gUnk_03000440.unk34 == 2)
            gUnk_03000440.unk34 = 0;
        else
            gUnk_03000440.unk34++;
    }
    switch (gUnk_03000440.unk34) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugPartsLabels[0], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugPartsLabels[1], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugPartsLabels[2], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugPartsLabels[1], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugPartsLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugPartsLabels[2], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    default:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x18, 8);
        else {
            memcpy_bytes_0803F63C(gDebugPartsLabels[2], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugPartsLabels[1], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugPartsLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0x77)
            gUnk_03000440.unk35[gUnk_03000440.unk34] = 0;
        else
            gUnk_03000440.unk35[gUnk_03000440.unk34]++;
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0)
            gUnk_03000440.unk35[gUnk_03000440.unk34] = 0x77;
        else
            gUnk_03000440.unk35[gUnk_03000440.unk34]--;
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[0]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[1]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x23, 8, 4, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x26, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[2]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x26, 8, 6, 3, 15, 1, 0);
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        switch (gUnk_03000440.unk34) {
        case 0:
            if (gUnk_03000440.unk35[0] < 0x78) {
                medapart_add_quantity(gUnk_03000440.unk35[0], 0, 1);
                medapart_add_quantity(gUnk_03000440.unk35[gUnk_03000440.unk34], 1, 1);
                medapart_add_quantity(gUnk_03000440.unk35[gUnk_03000440.unk34], 2, 1);
                medapart_add_quantity(gUnk_03000440.unk35[gUnk_03000440.unk34], 3, 1);
            }
            break;
        case 1:
            if (gUnk_03000440.unk35[1] < 0x78) {
                reduce_medapart_stat(gUnk_03000440.unk35[1], 0, 1);
                reduce_medapart_stat(gUnk_03000440.unk35[gUnk_03000440.unk34], 1, 1);
                reduce_medapart_stat(gUnk_03000440.unk35[gUnk_03000440.unk34], 2, 1);
                reduce_medapart_stat(gUnk_03000440.unk35[gUnk_03000440.unk34], 3, 1);
            }
            break;
        default:
            for (gUnk_03000440.unk35[2] = b; gUnk_03000440.unk35[2] < 0x78; gUnk_03000440.unk35[2]++) {
                medapart_add_quantity(gUnk_03000440.unk35[2], 0, 1);
                medapart_add_quantity(gUnk_03000440.unk35[2], 1, 1);
                medapart_add_quantity(gUnk_03000440.unk35[2], 2, 1);
                medapart_add_quantity(gUnk_03000440.unk35[2], 3, 1);
            }
            break;
        }
    }
}

void debug_tinpet_update(void) {
    gDebugTinpetHandlers[gUnk_03000440.unk33]();
}

void debug_tinpet_input(void) {
    if (gFrameCounter & 4)
        clear_battle_sprite_slot(8, 8);
    else {
        memcpy_bytes_0803F63C(gDebugTinpetLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
    }
    if (KEYS_LO(gRepeatKeys) & 0x30)
        gUnk_03000440.unk35[gUnk_03000440.unk34] ^= 1;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[0]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        if (!team_is_full())
            team_add_tinpet(gUnk_03000440.unk35[0]);
    }
}

void debug_item_update(void) {
    gDebugItemHandlers[gUnk_03000440.unk33]();
}

void debug_item_input(void) {
    u8 b;

    if (KEYS_LO(gNewKeys) & 0x40) {
        if (gUnk_03000440.unk34 == 0)
            gUnk_03000440.unk34 = 2;
        else
            gUnk_03000440.unk34--;
    }
    if (KEYS_LO(gNewKeys) & 0x80) {
        if (gUnk_03000440.unk34 == 2)
            gUnk_03000440.unk34 = 0;
        else
            gUnk_03000440.unk34++;
    }
    switch (gUnk_03000440.unk34) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugItemLabels[0], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugItemLabels[1], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugItemLabels[2], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugItemLabels[1], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugItemLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugItemLabels[2], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        break;
    default:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x18, 8);
        else {
            memcpy_bytes_0803F63C(gDebugItemLabels[2], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x18, 2, 6, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugItemLabels[1], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        memcpy_bytes_0803F63C(gDebugItemLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0x3E)
            gUnk_03000440.unk35[gUnk_03000440.unk34] = 0;
        else
            gUnk_03000440.unk35[gUnk_03000440.unk34]++;
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0)
            gUnk_03000440.unk35[gUnk_03000440.unk34] = 0x3E;
        else
            gUnk_03000440.unk35[gUnk_03000440.unk34]--;
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[0]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[1]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x23, 8, 4, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x26, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[2]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x26, 8, 6, 3, 15, 1, 0);
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        switch (gUnk_03000440.unk34) {
        case 0:
            if (gUnk_03000440.unk35[0] < 0x40)
                item_add_quantity(gUnk_03000440.unk35[0], 1);
            break;
        case 1:
            if (gUnk_03000440.unk35[1] < 0x40)
                sub_08042318(gUnk_03000440.unk35[1], 1);
            break;
        default:
            for (gUnk_03000440.unk35[2] = b; gUnk_03000440.unk35[2] < 0x3F; gUnk_03000440.unk35[2]++)
                item_add_quantity(gUnk_03000440.unk35[2], 1);
            break;
        }
    }
}

void debug_face_update(void) {
    gDebugFaceHandlers[gUnk_03000440.unk33]();
}

void debug_face_input(void) {
    u8 b;

    if (KEY_BITS(gNewKeys).up | KEY_BITS(gNewKeys).down)
        gUnk_03000440.unk34 ^= 1;
    switch (gUnk_03000440.unk34) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugFaceLabels[0], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugFaceLabels[1], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugFaceLabels[1], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugFaceLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gUnk_03000440.unk34 == 0) {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0xAF)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]++;
        } else {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 8)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]++;
        }
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gUnk_03000440.unk34 == 0) {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0xAF;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]--;
        } else {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 8;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]--;
        }
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[0]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[1]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x23, 8, 4, 3, 15, 1, 0);
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        vram_fill_tilemap_rect(0x11, 8, 0, 7, REG_BG0CNT, 0);
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        load_bg0_tilemap(gUnk_03000440.unk35[0], gUnk_03000440.unk35[1], 0, 7, 1);
        load_bg0_tilemap(gUnk_03000440.unk35[0], gUnk_03000440.unk35[1], 9, 7, b);
    }
}

void debug_mdlpic_update(void) {
    gDebugMdlpicHandlers[gUnk_03000440.unk33]();
}

void debug_mdlpic_input(void) {
    if (KEY_BITS(gNewKeys).up | KEY_BITS(gNewKeys).down)
        gUnk_03000440.unk34 ^= 1;
    switch (gUnk_03000440.unk34) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugFaceLabels[0], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugFaceLabels[1], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugFaceLabels[1], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugFaceLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gUnk_03000440.unk34 == 0) {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0x1D)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]++;
        } else {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 4)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]++;
        }
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gUnk_03000440.unk34 == 0) {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0x1D;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]--;
        } else {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 4;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]--;
        }
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[0]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[1]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x23, 8, 4, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2) {
        clear_battle_sprite_slot(0, 1);
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        DmaSet(3, gUnk_084E2E98, 0x050003E0, 0x84000008);
        lz_decompress_dispatch(gUnk_083AC494[gUnk_03000440.unk35[0]][gUnk_03000440.unk35[1]], (void *)0x06010000);
        gUnk_03002C30[0].unk0 = 0xC004;
        gUnk_03002C30[0].unk2 = 0x40;
        gUnk_03002C30[0].unk4 = 0x50;
        gUnk_03002C30[0].unk6 = 0x200;
        gUnk_03002C30[0].unkA = 15;
        gUnk_03002C30[0].unk1C = 0;
        gUnk_03002C30[0].unkB = 0xC0;
    }
}

void debug_rndtk_update(void) {
    gDebugRndTkHandlers[gUnk_03000440.unk33]();
}

void debug_rndtk_input(void) {
    if (gFrameCounter & 4)
        clear_battle_sprite_slot(8, 8);
    else {
        memcpy_bytes_0803F63C(gDebugRndTkLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
    }
    if (KEYS_LO(gRepeatKeys) & 0x30)
        gUnk_030057E0.unkC2C ^= 1;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_030057E0.unkC2C);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    }
}

void debug_battle_update(void) {
    gDebugBattleHandlers[gUnk_03000440.unk33]();
}

void debug_battle_input(void) {
    u8 b;

    if (gFrameCounter & 4)
        clear_battle_sprite_slot(8, 8);
    else {
        memcpy_bytes_0803F63C(gDebugBattleLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
    }
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gUnk_03000440.unk35[gUnk_03000440.unk34]++;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gUnk_03000440.unk35[gUnk_03000440.unk34]--;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[gUnk_03000440.unk34]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    if ((b = KEYS_LO(gNewKeys) & 2)) {
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        clear_battle_sprite_slot(8, 0x21);
        gUnk_030057E0.unkC2E = b;
        gUnk_030057E0.unkC2F = b;
        gUnk_030057E0.unkC2D = 1;
        gUnk_030057E0.unkC2A = gUnk_03000440.unk35[gUnk_03000440.unk34];
        gGameState = 6;
        gGameSubState = b;
    }
}

void debug_sound_update(void) {
    gDebugSoundHandlers[gUnk_03000440.unk33]();
}

void debug_sound_input(void) {
    if (KEY_BITS(gNewKeys).up | KEY_BITS(gNewKeys).down)
        gUnk_03000440.unk34 ^= 1;
    switch (gUnk_03000440.unk34) {
    case 0:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(8, 8);
        else {
            memcpy_bytes_0803F63C(gDebugSoundLabels[0], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugSoundLabels[1], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        break;
    case 1:
        if (gFrameCounter & 4)
            clear_battle_sprite_slot(0x10, 8);
        else {
            memcpy_bytes_0803F63C(gDebugSoundLabels[1], gUnk_03000440.unk9E, 8);
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x10, 2, 4, 8, 15, 1, 0);
        }
        memcpy_bytes_0803F63C(gDebugSoundLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
        break;
    }
    if (KEYS_LO(gRepeatKeys) & 0x10) {
        if (gUnk_03000440.unk34 == 0) {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0x7F)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]++;
        } else {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0x35)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]++;
        }
    }
    if (KEYS_LO(gRepeatKeys) & 0x20) {
        if (gUnk_03000440.unk34 == 0) {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0x7F;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]--;
        } else {
            if (gUnk_03000440.unk35[gUnk_03000440.unk34] == 0)
                gUnk_03000440.unk35[gUnk_03000440.unk34] = 0x35;
            else
                gUnk_03000440.unk35[gUnk_03000440.unk34]--;
        }
    }
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[0]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    clear_battle_sprite_slot(0x23, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[1]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x23, 8, 4, 3, 15, 1, 0);
    if (KEYS_LO(gNewKeys) & 2) {
        play_song(0);
        clear_battle_sprite_slot(8, 0x21);
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1) {
        if (gUnk_03000440.unk34 == 0)
            play_sound_effect(gUnk_03000440.unk35[gUnk_03000440.unk34]);
        else
            play_song(gUnk_03000440.unk35[gUnk_03000440.unk34]);
    }
}

void debug_motion_update(void) {
    gDebugMotionHandlers[gUnk_03000440.unk33]();
}

void debug_motion_init(void) {
    clear_battle_sprite_slot(0, 0x80);
    gUnk_03000440.unk39 = 0;
    gUnk_03000440.unk33++;
}

void debug_motion_load(void) {
    init_scene_buffers_080445F4();
    setup_scene_with_bg_and_sprites(0, gUnk_03000440.unk39, gUnk_03000440.unk39, gUnk_03000440.unk39,
                                    gUnk_03000440.unk39, 0x38, 0x68, 0, 4, 0, 0, 0);
    setup_scene_with_bg_and_sprites(1, gUnk_03000440.unk39, gUnk_03000440.unk39, gUnk_03000440.unk39,
                                    gUnk_03000440.unk39, 0xB8, 0x30, 0, 8, 1, 0, 1);
    gUnk_03000440.unk33++;
}

void debug_motion_input(void) {
    vu32 fill;
    u8 b;

    fill = 0x200;
    DmaSet(3, &fill, gSpriteWork->oamBuf, 0x85000100);
    init_scene_with_bg_and_palette(0, gUnk_03000440.unk39, gUnk_03000440.unk39, gUnk_03000440.unk39,
                                   gUnk_03000440.unk39, 0x38, 0x68, 0, 4, 0, 1, 0, 0);
    init_scene_with_bg_and_palette(1, gUnk_03000440.unk39, gUnk_03000440.unk39, gUnk_03000440.unk39,
                                   gUnk_03000440.unk39, 0xB8, 0x30, 0, 8, 1, 1, 1, 0x28);
    if (gFrameCounter & 4)
        clear_battle_sprite_slot(8, 8);
    else {
        memcpy_bytes_0803F63C(gDebugMotionLabels[0], gUnk_03000440.unk9E, 8);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 8, 2, 2, 8, 15, 1, 0);
    }
    if (KEYS_LO(gRepeatKeys) & 0x10)
        gUnk_03000440.unk35[gUnk_03000440.unk34]++;
    if (KEYS_LO(gRepeatKeys) & 0x20)
        gUnk_03000440.unk35[gUnk_03000440.unk34]--;
    clear_battle_sprite_slot(0x20, 3);
    divide_by_100000_08041370(gUnk_03000440.unk9E, gUnk_03000440.unk35[gUnk_03000440.unk34]);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20, 8, 2, 3, 15, 1, 0);
    if (KEYS_LO(gRepeatKeys) & 8) {
        if (gUnk_03000440.unk39 == 0x79)
            gUnk_03000440.unk39 = 0;
        else
            gUnk_03000440.unk39++;
        gUnk_03000440.unk33--;
    } else if ((b = KEYS_LO(gRepeatKeys) & 4)) {
        if (gUnk_03000440.unk39 == 0)
            gUnk_03000440.unk39 = 0x79;
        else
            gUnk_03000440.unk39--;
        gUnk_03000440.unk33--;
    } else if (KEYS_LO(gNewKeys) & 2) {
        clear_battle_sprite_slot(8, 0x21);
        gUnk_03000430 = b;
        gGameSubState = 1;
    } else if (KEYS_LO(gNewKeys) & 1)
        gUnk_03000440.unk33++;
}

void debug_motion_play(void) {
    vu32 fill;

    fill = 0x200;
    DmaSet(3, &fill, gSpriteWork->oamBuf, 0x85000100);
    init_scene_with_bg_and_palette(0, gUnk_03000440.unk39, gUnk_03000440.unk39, gUnk_03000440.unk39,
                                   gUnk_03000440.unk39, 0x38, 0x68, 0, 4, 0, 1, 0, 0);
    init_scene_with_bg_and_palette(1, gUnk_03000440.unk39, gUnk_03000440.unk39, gUnk_03000440.unk39,
                                   gUnk_03000440.unk39, 0xB8, 0x30, 0, 8, 1, 1, 1, 0x28);
    advance_text_display(0, gUnk_03000440.unk35[gUnk_03000440.unk34], gUnk_03000440.unk39);
    advance_text_display(1, gUnk_03000440.unk35[gUnk_03000440.unk34], gUnk_03000440.unk39);
    if (KEYS_LO(gNewKeys) & 2)
        gUnk_03000440.unk33 -= 2;
}
