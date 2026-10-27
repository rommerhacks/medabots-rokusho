// Robattle time limit: robattle_time_init, the per-frame robattle_time_tick and robattle_time_draw (HUD
// digits). Called from battle/robattle.

#include "global.h"

void robattle_time_init(void) {
    if (gUnk_03000440.unk89 == 1) {
        gUnk_03001800.unk57 = 40;
        return;
    }
    switch (gOptionTimeLimit) {
    case 0:
        gUnk_03001800.unk57 = 40;
        break;
    case 1:
        gUnk_03001800.unk57 = 30;
        break;
    case 2:
        gUnk_03001800.unk57 = 20;
        break;
    }
}

void robattle_time_tick(void) {
    if ((gUnk_03001800.unk56 = (gUnk_03001800.unk56 + 1) & 0x1F) == 0 && gUnk_03001800.unk57 != 0) {
        gUnk_03001800.unk57--;
        gUnk_03001800.unk16B++;
        sub_08018CBC();
    }
}

void robattle_time_draw(void) {
    gSpriteEntries[1].unk6 = (u8)(gUnk_03001800.unk57 / 10) + 0x624;
    gSpriteEntries[2].unk6 = (u8)(gUnk_03001800.unk57 % 10) + 0x624;
}
