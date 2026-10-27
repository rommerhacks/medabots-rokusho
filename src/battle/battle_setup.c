// Robattle start helpers: per-Medal skill use counters (count_bot_skill_use, called for each team Medabot by
// count_team_skill_uses), opponent defaults, the battle music choice (select_battle_music) and the action-select UI
// windows. Called from battle/robattle.

#include "global.h"
#include "keys.h"

static inline u32 sub1(u32 x) {
    return x - 1;
}

// Adds one to the bot's per-skill-type use counter (unkB0) for its chosen action: a part (action 1-3) or
// one of the three Medal skills (4-6, available from Medal level 10 / 30 / 60).
void count_bot_skill_use(u32 rec) {
    u8 k;
    struct BattleBot *base;
    struct BattleBot *r;
    u32 off;

    if (rec > 2)
        return;
    base = gBattleBots;
    off = rec << 8;
    r = (struct BattleBot *)((u8 *)base + off);
    if (r->chosenAction == 0)
        return;
    if (r->chosenAction <= 3) {
        k = *(u8 *)(sub1(r->chosenAction) * 24 + off + (u32)base + 0x4A);
    } else {
        switch (r->chosenAction - 4) {
        case 0:
            if (r->medal.level <= 9)
                return;
            memcpy_bytes_08041D04(&gMedalMedaforceIds[r->medal.graphicId * 3], &gGameWork.partAbility, 3);
            memcpy_bytes_08041D04(&gMedaforceRecords[(&gGameWork.partAbility)[0] * 6], gGameWork.medalGfxRecord, 6);
            k = gGameWork.medalGfxRecord[1];
            break;
        case 1:
            if (r->medal.level <= 29)
                return;
            memcpy_bytes_08041D04(&gMedalMedaforceIds[r->medal.graphicId * 3], &gGameWork.partAbility, 3);
            memcpy_bytes_08041D04(&gMedaforceRecords[(&gGameWork.partAbility)[1] * 6], gGameWork.medalGfxRecord, 6);
            k = gGameWork.medalGfxRecord[1];
            break;
        case 2:
            if (r->medal.level <= 59)
                return;
            memcpy_bytes_08041D04(&gMedalMedaforceIds[r->medal.graphicId * 3], &gGameWork.partAbility, 3);
            memcpy_bytes_08041D04(&gMedaforceRecords[(&gGameWork.partAbility)[2] * 6], gGameWork.medalGfxRecord, 6);
            k = gGameWork.medalGfxRecord[1];
            break;
        default:
            return;
        }
    }
    {
        u32 t = k + off;
        register u32 q asm("r0") = (u32)base->skillUseCount;
        t += q;
        (*(u8 *)t)++;
    }
}

void count_team_skill_uses(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleBots[i].teamState)
            count_bot_skill_use(i);
    }
}

// In battles of type 2 (gFieldWork.battle_flags high nibble) the opponents start with a full Medaforce gauge.
void fill_opponent_medaforce_for_battle_type(void) {
    u32 i;

    if ((gFieldWork.battle_flags & 0xF0) == 0x20) {
        for (i = 0; i <= 2; i++)
            gBattleBots[i + 3].medaforceGauge = 0x50;
    }
}

void select_battle_music(void) {
    if (gGameWork.skipBotSetup == 1)
        play_song(9);
    else if ((gFieldWork.battle_flags & 0xF0) != 0) {
        if ((gFieldWork.battle_flags & 0xF0) == 0x10)
            play_song(0xC);
        else
            play_song(0xD);
    } else
        play_song(gUnk_083AD3B0[gOptionBattleMusic]);
}

void init_battle_action_select_ui(u32 a) {
    if (a != 0) {
        vram_fill_tilemap_rect(6, 5, 0xC, 0xF, REG_BG1CNT, 0);
        clear_battle_sprite_slot(0, 1);
        clear_battle_sprite_slot(1, 2);
    } else {
        set_tilemap_and_decompress_bg(0xC, 0xF, gActionSelectPanelTilemap, REG_BG1CNT, 0x230);
        gSpriteEntries[0].unk0 = 0xC404;
        gSpriteEntries[0].unk1C = 0;
        gSpriteEntries[0].unkA = 0xA;
        gSpriteEntries[0].unkB = 0x40;
        gSpriteEntries[0].unk2 = 0x78;
        gSpriteEntries[0].unk4 = 0x84;
        gSpriteEntries[0].unk6 = 0x623;
        gSpriteEntries[1].unk0 = 0xC404;
        gSpriteEntries[1].unk1C = 0;
        gSpriteEntries[1].unkA = 0xA;
        gSpriteEntries[1].unkB = 0x40;
        gSpriteEntries[1].unk2 = 0x70;
        gSpriteEntries[1].unk4 = 0x90;
        gSpriteEntries[1].unk6 = (u8)(gBattleWork.timeLeft / 10) + 0x624;
        gSpriteEntries[2].unk0 = 0xC404;
        gSpriteEntries[2].unk1C = 0;
        gSpriteEntries[2].unkA = 0xA;
        gSpriteEntries[2].unkB = 0x40;
        gSpriteEntries[2].unk2 = 0x80;
        gSpriteEntries[2].unk4 = 0x90;
        gSpriteEntries[2].unk6 = (u8)(gBattleWork.timeLeft % 10) + 0x624;
    }
}
