// Robattle time limit: robattle_time_init, the per-frame robattle_time_tick and robattle_time_draw (HUD
// digits). Called from battle/robattle.

#include "global.h"

void robattle_time_init(void) {
    if (gGameWork.unk89 == 1) {
        gBattleWork.timeLeft = 40;
        return;
    }
    switch (gOptionTimeLimit) {
    case 0:
        gBattleWork.timeLeft = 40;
        break;
    case 1:
        gBattleWork.timeLeft = 30;
        break;
    case 2:
        gBattleWork.timeLeft = 20;
        break;
    }
}

void robattle_time_tick(void) {
    if ((gBattleWork.timeFrame = (gBattleWork.timeFrame + 1) & 0x1F) == 0 && gBattleWork.timeLeft != 0) {
        gBattleWork.timeLeft--;
        gBattleWork.timeTicks++;
        battle_tick_timed_effects();
    }
}

void robattle_time_draw(void) {
    gSpriteEntries[1].unk6 = (u8)(gBattleWork.timeLeft / 10) + 0x624;
    gSpriteEntries[2].unk6 = (u8)(gBattleWork.timeLeft % 10) + 0x624;
}
