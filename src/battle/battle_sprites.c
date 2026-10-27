// Battle sprite setup (positions, init_battle_bot_sprites), indexed / fixed graphics decompression to EWRAM,
// palettes, tile_anim_run (sprite tile animation scripts) and the Medal skill level-up after
// a part is used (increment_medal_skill_level, sync_medal_stats_from_battle_bot).

#include "global.h"

static void sync_medal_stats_from_battle_bot(u32 rec);

void copy_battle_entity_positions(void) {
    u32 i;

    for (i = 0; i <= 5; i++) {
        gBattleWork.unk13C[i].x = gSpriteEntries[0x5D + i * 4].unk2;
        gBattleWork.unk13C[i].y = gSpriteEntries[0x5D + i * 4].unk4 - 4;
    }
}

void init_battle_bot_sprites(void) {
    u32 i;

    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].teamState)
            init_battle_sprite_entry_0801BC04(i);
        else
            clear_sprite_table_mask(0x72 + i, 1);
    }
}

void init_battle_sprite_entry_0801BC04(u32 rec) {
    gSpriteEntries[rec + 0x72].unk0 = ((gBattleWork.unk39[3] + 2) << 10) | 0xC004;
    gSpriteEntries[rec + 0x72].unk1C = 0;
    gSpriteEntries[rec + 0x72].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2;
    gSpriteEntries[rec + 0x72].unk4 = gSpriteEntries[rec * 4 + 0x5D].unk4 + 8;
    gSpriteEntries[rec + 0x72].unkA = 5;
    gSpriteEntries[rec + 0x72].unkB = 1;
    gSpriteEntries[rec + 0x72].unk6 = 0xF00;
}

void decompress_indexed_graphics_to_ewram(u32 list) {
    const struct GfxListEntry *e = gUnk_083CE480[list];
    u8 *dst = (u8 *)0x02000000;
    u32 i;

    for (i = 0; e[i].size != 0; i++) {
        lz_decompress(gUnk_083B2584[e[i].index * 2], dst);
        dst += e[i].size * 32;
    }
}

void decompress_fixed_graphics_to_ewram(void) {
    const struct GfxListEntry *e = gUnk_083CE480[0x3C];
    u8 *dst = (u8 *)0x02016000;
    u32 i;

    for (i = 0; e[i].size != 0; i++) {
        lz_decompress(gUnk_083B2584[e[i].index * 2], dst);
        dst += e[i].size * 32;
    }
}

void load_battle_entity_palette(u32 list, u32 entry, u32 slot) {
    const struct GfxListEntry *l = gUnk_083CE480[list];

    CpuFastSet(gUnk_083B2584[l[entry].index * 2 + 1], (void *)(0x05000000 + slot * 32), 8);
}

// Tile animation slots (gGameWork.tileAnims): tile_anim_run steps a script of (frames, tile) pairs that
// copies frames of a sheet into OBJ VRAM; 0xFD plays a sound, 0xFE jumps, 0xFF ends.
void tile_anim_init(const u16 *pos, u8 obj_tile, u32 slot) {
    gGameWork.tileAnims[slot].wait = 0;
    gGameWork.tileAnims[slot].pos = 2;
    gGameWork.tileAnims[slot].state = 0;
    gGameWork.tileAnims[slot].sheetTile = pos[0];
    gGameWork.tileAnims[slot].frameTiles = pos[1];
    gGameWork.tileAnims[slot].objTile = obj_tile;
}

// tree folding happens before inlining: these keep the EWRAM base added after the multiply
static inline u32 tile_offset(u32 n) {
    return n * 32;
}
static inline u32 ewram_offset(u32 n, u32 m) {
    return n * m + 0x02000000;
}

void tile_anim_run(const u16 *script, u32 slot) {
    u32 run = 1;

    if (gGameWork.tileAnims[slot].state == 0xFF)
        return;

    while (run) {
        if (gGameWork.tileAnims[slot].wait) {
            gGameWork.tileAnims[slot].wait--;
            return;
        }
        switch (*(u8 *)&script[gGameWork.tileAnims[slot].pos]) {
        case 0xFD:
            play_sound_effect(script[gGameWork.tileAnims[slot].pos + 1]);
            gGameWork.tileAnims[slot].pos += 2;
            break;
        case 0xFE:
            gGameWork.tileAnims[slot].pos = script[gGameWork.tileAnims[slot].pos + 1] * 2;
            break;
        case 0xFF:
            gGameWork.tileAnims[slot].state = 0xFF;
            return;
        default:
            gGameWork.tileAnims[slot].wait = script[gGameWork.tileAnims[slot].pos];
            CpuSet((void *)(tile_offset(gGameWork.tileAnims[slot].sheetTile) +
                            ewram_offset(gGameWork.tileAnims[slot].frameTiles,
                                         script[gGameWork.tileAnims[slot].pos + 1] * 32)),
                   (void *)(gGameWork.tileAnims[slot].objTile * 0x1200 + 0x06004000),
                   (gGameWork.tileAnims[slot].frameTiles * 8) | 0x04000000);
            gGameWork.tileAnims[slot].pos += 2;
            break;
        }
    }
}

void increment_medal_skill_level(u32 rec) {
    u32 skill;

    if (rec > 2)
        return;
    if (gGameWork.unk89 == 1)
        return;
    if (gBattleBots[rec].medal.level == 100)
        return;
    if (gBattleWork.unk164 == 0)
        return;
    if (gBattleBots[rec].chosenAction > 3)
        skill = gBattleBots[rec].medaforce[1];
    else
        skill = gBattleBots[rec].parts[gBattleBots[rec].chosenAction - 1].data[2];
    if (gBattleBots[rec].medal.skillLevel[skill] == 100) {
        if (gBattleBots[rec].medal.skillExp[skill] <= 6)
            gBattleBots[rec].medal.skillExp[skill]++;
    } else {
        gBattleBots[rec].medal.skillExp[skill]++;
        if (gBattleBots[rec].medal.skillExp[skill] > 7) {
            gBattleBots[rec].medal.skillExp[skill] = 0;
            gBattleBots[rec].medal.skillLevel[skill]++;
            gBattleWork.unk165 = 1;
            gBattleWork.unk166 = skill;
            gBattleWork.unk167 = gBattleBots[rec].medal.skillLevel[skill];
        }
    }
    sync_medal_stats_from_battle_bot(rec);
}

static void sync_medal_stats_from_battle_bot(u32 rec) {
    u32 slot = find_medal_slot_by_id(gBattleBots[rec].medal.graphicId) - 1;
    u32 i;

    for (i = 0; i <= 7; i++) {
        gMedals[slot].skillLevel[i] = gBattleBots[rec].medal.skillLevel[i];
        gMedals[slot].skillExp[i] = gBattleBots[rec].medal.skillExp[i];
    }
}

void inc_u16_saturating(u16 *counter, u16 max) {
    if (*counter != max)
        (*counter)++;
}

// Identical copies of tile_anim_init / tile_anim_run (the original has both).
void tile_anim_init_dup(const u16 *pos, u8 obj_tile, u32 slot) {
    gGameWork.tileAnims[slot].wait = 0;
    gGameWork.tileAnims[slot].pos = 2;
    gGameWork.tileAnims[slot].state = 0;
    gGameWork.tileAnims[slot].sheetTile = pos[0];
    gGameWork.tileAnims[slot].frameTiles = pos[1];
    gGameWork.tileAnims[slot].objTile = obj_tile;
}

// tree folding happens before inlining: these keep the EWRAM base added after the multiply

void tile_anim_run_dup(const u16 *script, u32 slot) {
    u32 run = 1;

    if (gGameWork.tileAnims[slot].state == 0xFF)
        return;

    while (run) {
        if (gGameWork.tileAnims[slot].wait) {
            gGameWork.tileAnims[slot].wait--;
            return;
        }
        switch (*(u8 *)&script[gGameWork.tileAnims[slot].pos]) {
        case 0xFD:
            play_sound_effect(script[gGameWork.tileAnims[slot].pos + 1]);
            gGameWork.tileAnims[slot].pos += 2;
            break;
        case 0xFE:
            gGameWork.tileAnims[slot].pos = script[gGameWork.tileAnims[slot].pos + 1] * 2;
            break;
        case 0xFF:
            gGameWork.tileAnims[slot].state = 0xFF;
            return;
        default:
            gGameWork.tileAnims[slot].wait = script[gGameWork.tileAnims[slot].pos];
            CpuSet((void *)(tile_offset(gGameWork.tileAnims[slot].sheetTile) +
                            ewram_offset(gGameWork.tileAnims[slot].frameTiles,
                                         script[gGameWork.tileAnims[slot].pos + 1] * 32)),
                   (void *)(gGameWork.tileAnims[slot].objTile * 32 + 0x06010000),
                   (gGameWork.tileAnims[slot].frameTiles * 8) | 0x04000000);
            gGameWork.tileAnims[slot].pos += 2;
            break;
        }
    }
}
