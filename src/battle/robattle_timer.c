// Robattle time limit: robattle_time_init, the per-frame robattle_time_tick and robattle_time_draw (HUD
// digits). Called from battle/robattle.

#include "global.h"

void robattle_time_init(void) {
    if (gGameWork.unk89 == 1) {
        gBattleWork.unk57 = 40;
        return;
    }
    switch (gOptionTimeLimit) {
    case 0:
        gBattleWork.unk57 = 40;
        break;
    case 1:
        gBattleWork.unk57 = 30;
        break;
    case 2:
        gBattleWork.unk57 = 20;
        break;
    }
}

void robattle_time_tick(void) {
    if ((gBattleWork.unk56 = (gBattleWork.unk56 + 1) & 0x1F) == 0 && gBattleWork.unk57 != 0) {
        gBattleWork.unk57--;
        gBattleWork.unk16B++;
        battle_tick_timed_effects();
    }
}

void robattle_time_draw(void) {
    gSpriteEntries[1].unk6 = (u8)(gBattleWork.unk57 / 10) + 0x624;
    gSpriteEntries[2].unk6 = (u8)(gBattleWork.unk57 % 10) + 0x624;
}
