// Robattle start helpers: per-Medal skill use counters (count_bot_skill_use, called for each team Medabot by
// count_team_skill_uses), opponent defaults, the battle music choice (select_battle_music) and the action-select UI
// windows. Called from battle/robattle.

#include "global.h"
#include "keys.h"
#include "constants/sprites.h"

static inline u32 sub1(u32 x) {
    return x - 1;
}

// Adds one to the bot's per-skill-type use counter (skillUseCount) for its chosen action: a part (action 1-3) or
// one of the three Medal skills (4-6, available from Medal level 10 / 30 / 60).
void count_bot_skill_use(u32 rec) {
    u8 k;
    struct BattleBot *base;
    struct BattleBot *bot;
    u32 off;

    if (rec > 2)
        return;
    base = gBattleBots;
    off = rec << 8;
    bot = (struct BattleBot *)((u8 *)base + off);
    if (bot->chosenAction == 0)
        return;
    if (bot->chosenAction <= 3) {
        // FAKEMATCH: bot->parts[chosenAction - 1].data[2] (the skill type) written out: the struct form folds
        // the 0x4A offset differently and does not match
        k = *(u8 *)(sub1(bot->chosenAction) * 24 + off + (u32)base + 0x4A);
    } else {
        switch (bot->chosenAction - 4) {
        case 0:
            if (bot->medal.level <= 9)
                return;
            copy_bytes_short(&gMedalMedaforceIds[bot->medal.graphicId * 3], &gGameWork.partAbility, 3);
            copy_bytes_short(&gMedaforceRecords[(&gGameWork.partAbility)[0] * 6], gGameWork.medalGfxRecord, 6);
            k = gGameWork.medalGfxRecord[1];
            break;
        case 1:
            if (bot->medal.level <= 29)
                return;
            copy_bytes_short(&gMedalMedaforceIds[bot->medal.graphicId * 3], &gGameWork.partAbility, 3);
            copy_bytes_short(&gMedaforceRecords[(&gGameWork.partAbility)[1] * 6], gGameWork.medalGfxRecord, 6);
            k = gGameWork.medalGfxRecord[1];
            break;
        case 2:
            if (bot->medal.level <= 59)
                return;
            copy_bytes_short(&gMedalMedaforceIds[bot->medal.graphicId * 3], &gGameWork.partAbility, 3);
            copy_bytes_short(&gMedaforceRecords[(&gGameWork.partAbility)[2] * 6], gGameWork.medalGfxRecord, 6);
            k = gGameWork.medalGfxRecord[1];
            break;
        default:
            return;
        }
    }
    {
        u32 counter_addr = k + off;
        // FAKEMATCH: pins the skillUseCount base address to r0
        register u32 counts_base asm("r0") = (u32)base->skillUseCount;
        counter_addr += counts_base;
        (*(u8 *)counter_addr)++;
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
        play_song(gBattleSongs[gOptionBattleMusic]);
}

void init_battle_action_select_ui(u32 hide) {
    if (hide != 0) {
        vram_fill_tilemap_rect(6, 5, 0xC, 0xF, REG_BG1CNT, 0);
        clear_battle_sprite_slot(0, 1);
        clear_battle_sprite_slot(1, 2);
    } else {
        set_tilemap_and_decompress_bg(0xC, 0xF, gActionSelectPanelTilemap, REG_BG1CNT, 0x230);
        gSpriteEntries[0].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0].frame_table = 0;
        gSpriteEntries[0].palette = 0xA;
        gSpriteEntries[0].order = 0x40;
        gSpriteEntries[0].x = 0x78;
        gSpriteEntries[0].y = 0x84;
        gSpriteEntries[0].frame = 0x623;
        gSpriteEntries[1].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[1].frame_table = 0;
        gSpriteEntries[1].palette = 0xA;
        gSpriteEntries[1].order = 0x40;
        gSpriteEntries[1].x = 0x70;
        gSpriteEntries[1].y = 0x90;
        gSpriteEntries[1].frame = (u8)(gBattleWork.timeLeft / 10) + 0x624;
        gSpriteEntries[2].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[2].frame_table = 0;
        gSpriteEntries[2].palette = 0xA;
        gSpriteEntries[2].order = 0x40;
        gSpriteEntries[2].x = 0x80;
        gSpriteEntries[2].y = 0x90;
        gSpriteEntries[2].frame = (u8)(gBattleWork.timeLeft % 10) + 0x624;
    }
}
