// Mode-2 state 25: entered from the Medaparts screen (menu/medaparts_screen.c) to go back to the shop.
// dispatch_substate_handler runs gUnk_080AFA20, which mixes shop_menu.c and shop_list.c sub-states with the
// two here (redraw the money / icons, fade out). Name is a guess.
#include "global.h"

void shop_return_init(void) {
    s32 i;

    battle_menu_highlight_icons(gUnk_03006F74->unk19, 8);
    clear_battle_sprite_slot(0, 0x80);
    for (i = 0; i < 4; i++)
        gUnk_03002C30[12 + i].unk0 &= 0xBFFF;
    CpuFastSet(gUnk_084E2E58, (void *)0x0202F800, 8);
    CpuFastSet(gUnk_084E2E38, (void *)0x0202F9E0, 8);
    CpuFastSet(gUnk_084E2E58, (void *)0x0202F9C0, 8);
    CpuFastSet(gUnk_08488AA4, (void *)0x0202F820, 8);
    CpuFastSet(gUnk_0879671C, (void *)0x0202FA00, 0x80);
    gUnk_03000440.unk84 = 0;
    gUnk_03006F74->unk6 = 1;
    gGameSubState++;
    REG_DISPCNT |= 0x100;
    REG_DISPCNT |= 0x200;
    REG_DISPCNT |= 0x400;
    REG_DISPCNT |= 0x800;
    REG_DISPCNT |= 0x1000;
    gUnk_03002C30[7].unk0 = 0xC000;
    gUnk_03002C30[7].unk1C = 2;
    gUnk_03002C30[7].unkA = 1;
    gUnk_03002C30[7].unk6 = 0x1A;
    gUnk_03002C30[7].unk2 = 0x98;
    gUnk_03002C30[7].unk4 = 0;
    divide_by_10000(gUnk_03000440.unk9E, gUnk_03002B70.money);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0, 0x15, 1, 7, 0xF, 1, 0);
}

void fade_out_transition_step(void) {
    struct Unk_03000440 *s = &gUnk_03000440;
    u8 *n = &s->unk84;

    if (*n <= 8) {
        blend_obj_palettes_to_color_0803F684(0, 32 - *n * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 32 - *n * 4, 0xFFFF);
        (*n)++;
    } else {
        update_battle_sprite_priority_flags();
        gUnk_03006F74->unk2 = 0;
        gGameState = 12;
        gGameSubState = 4;
    }
}

void dispatch_substate_handler(void) {
    struct FuncTable7 t = gUnk_080AFA20;
    t.f[gGameSubState]();
}
