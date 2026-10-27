// Mode-2 state 25: entered from the Medaparts screen (menu/medaparts_screen.c) to go back to the shop.
// dispatch_substate_handler runs gUnk_080AFA20, which mixes shop_menu.c and shop_list.c sub-states with the
// two here (redraw the money / icons, fade out). Name is a guess.
#include "global.h"

void shop_return_init(void) {
    s32 i;

    shop_highlight_part_type_icon(gMenuWork->part_kind, 8);
    clear_battle_sprite_slot(0, 0x80);
    for (i = 0; i < 4; i++)
        gSpriteEntries[12 + i].unk0 &= 0xBFFF;
    CpuFastSet(gCursorArrowPalette, (void *)0x0202F800, 8);
    CpuFastSet(gUnk_084E2E38, (void *)0x0202F9E0, 8);
    CpuFastSet(gCursorArrowPalette, (void *)0x0202F9C0, 8);
    CpuFastSet(gUnk_08488AA4, (void *)0x0202F820, 8);
    CpuFastSet(gUnk_0879671C, (void *)0x0202FA00, 0x80);
    gGameWork.unk84 = 0;
    gMenuWork->returning = 1;
    gGameSubState++;
    REG_DISPCNT |= 0x100;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gSpriteEntries[7].unk0 = 0xC000;
    gSpriteEntries[7].unk1C = 2;
    gSpriteEntries[7].unkA = 1;
    gSpriteEntries[7].unk6 = 0x1A;
    gSpriteEntries[7].unk2 = 0x98;
    gSpriteEntries[7].unk4 = 0;
    divide_by_10000(gGameWork.textBuf, gPlayerRecord.money);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0, 0x15, 1, 7, 0xF, 1, 0);
}

void fade_out_transition_step(void) {
    struct GameWork *s = &gGameWork;
    u8 *n = &s->unk84;

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
    struct FuncTable7 t = gUnk_080AFA20;
    t.f[gGameSubState]();
}
