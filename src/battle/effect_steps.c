// Step handlers shared by many ability and Medaforce effect sequences (entries of several step sub-tables, no
// direct callers): show the battle message messageId, the "MISS!!" popup, wait for a timer (gGameWork.stepTimer) or a
// press of A, play an animation on sprite 0x21, and effect_step_end, the last step of most lists (stepDone = done).

#include "global.h"
#include "constants/sprites.h"

void effect_step_show_message(void) {
    if (battle_message_show(gBattleWork.messageId))
        gBattleWork.step++;
}

void effect_step_miss_popup(void) {
    if (miss_popup_run())
        gBattleWork.step++;
}

void effect_step_wait_clear_sprite(void) {
    if (gGameWork.skipBotSetup == 0 && (*(u8 *)&gRepeatKeys & 1)) {
        clear_battle_sprite_slot(0xA, 1);
        gBattleWork.step++;
    } else if (gGameWork.stepTimer)
        gGameWork.stepTimer--;
    else {
        clear_battle_sprite_slot(0xA, 1);
        gBattleWork.step++;
    }
}

void effect_step_wait(void) {
    if (gGameWork.skipBotSetup == 0 && (*(u8 *)&gRepeatKeys & 1))
        gBattleWork.step++;
    else if (gGameWork.stepTimer)
        gGameWork.stepTimer--;
    else
        gBattleWork.step++;
}

void effect_step_wait_clear_sprites(void) {
    u32 i;

    if (gGameWork.skipBotSetup == 0 && (*(u8 *)&gRepeatKeys & 1)) {
        for (i = 0; i < 0x14; i++) {
            if (gSpriteEntries[0xA + i].flags & SPRITE_FLAG_ENABLED)
                clear_battle_sprite_slot(0xA + i, 1);
        }
        gBattleWork.step++;
    }
    if (gGameWork.stepTimer)
        gGameWork.stepTimer--;
    else {
        for (i = 0; i < 0x14; i++) {
            if (gSpriteEntries[0xA + i].flags & SPRITE_FLAG_ENABLED)
                clear_battle_sprite_slot(0xA + i, 1);
        }
        gBattleWork.step++;
    }
}

void effect_step_wait_spin(void) {
    if (!(gBattleWork.actorSideFlags & 1))
        gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle - 0x40) & 0x3FF;
    else
        gSpriteEntries[0x21].angle = (gSpriteEntries[0x21].angle + 0x40) & 0x3FF;
    if (gGameWork.skipBotSetup == 0 && (*(u8 *)&gRepeatKeys & 1))
        gBattleWork.step++;
    else if (gGameWork.stepTimer)
        gGameWork.stepTimer--;
    else
        gBattleWork.step++;
}

void effect_step_end(void) {
    gBattleWork.stepDone = 1;
}

void effect_step_play_anim(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[gGameWork.stepCounter], 0x21);
    if (gSpriteEntries[0x21].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
        gBattleWork.step++;
}
