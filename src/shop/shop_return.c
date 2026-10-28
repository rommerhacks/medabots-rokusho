// Mode-2 state 25: entered from the Medaparts screen (menu/medaparts_screen.c) to go back to the shop.
// dispatch_substate_handler runs gShopSubStates, which mixes shop_menu.c and shop_list.c sub-states with the
// two here (redraw the money / icons, fade out). Name is a guess.
#include "global.h"
#include "constants/sprites.h"

void shop_return_init(void) {
    s32 i;

    shop_highlight_part_type_icon(gMenuWork->part_kind, 8);
    clear_battle_sprite_slot(0, 0x80);
    for (i = 0; i < 4; i++)
        gSpriteEntries[12 + i].flags &= (u16)~SPRITE_FLAG_VISIBLE;
    CpuFastSet(gCursorArrowPalette, (void *)0x0202F800, 8);
    CpuFastSet(gSpriteFontPalette, (void *)0x0202F9E0, 8);
    CpuFastSet(gCursorArrowPalette, (void *)0x0202F9C0, 8);
    CpuFastSet(gShopObjPalette, (void *)0x0202F820, 8);
    CpuFastSet(gShopMenuBgPalettes, (void *)0x0202FA00, 0x80);
    gGameWork.stepCounter = 0;
    gMenuWork->returning = 1;
    gGameSubState++;
    REG_DISPCNT |= 0x100;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gSpriteEntries[7].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE;
    gSpriteEntries[7].frame_table = 2;
    gSpriteEntries[7].palette = 1;
    gSpriteEntries[7].frame = 0x1A;
    gSpriteEntries[7].x = 0x98;
    gSpriteEntries[7].y = 0;
    divide_by_10000(gGameWork.textBuf, gPlayerRecord.money);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0, 0x15, 1, 7, 0xF, 1, 0);
}

void fade_out_transition_step(void) {
    struct GameWork *game = &gGameWork;
    u8 *n = &game->stepCounter;

    if (*n <= 8) {
        bg_palettes_blend_masked_now(0, 32 - *n * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, 32 - *n * 4, 0xFFFF);
        (*n)++;
    } else {
        update_battle_sprite_priority_flags();
        gMenuWork->timer = 0;
        gGameState = 12;
        gGameSubState = 4;
    }
}

void dispatch_substate_handler(void) {
    struct FuncTable7 states = gShopSubStates;
    states.f[gGameSubState]();
}
