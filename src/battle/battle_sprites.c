// Battle sprite setup (positions, init_battle_bot_sprites), indexed / fixed graphics decompression to EWRAM,
// palettes, process_animation_script (sprite tile animation scripts) and the Medal skill level-up after
// a part is used (increment_medal_skill_level, sync_medal_stats_from_battle_bot).

#include "global.h"

static void sync_medal_stats_from_battle_bot(u32 rec);

void copy_battle_entity_positions(void) {
    u32 i;

    for (i = 0; i <= 5; i++) {
        gUnk_03001800.unk13C[i].x = gUnk_03002C30[0x5D + i * 4].unk2;
        gUnk_03001800.unk13C[i].y = gUnk_03002C30[0x5D + i * 4].unk4 - 4;
    }
}

void init_battle_bot_sprites(void) {
    u32 i;

    for (i = 0; i <= 5; i++) {
        if (gUnk_03000590[i].unk40)
            init_battle_sprite_entry_0801BC04(i);
        else
            clear_sprite_table_mask(0x72 + i, 1);
    }
}

void init_battle_sprite_entry_0801BC04(u32 rec) {
    gUnk_03002C30[rec + 0x72].unk0 = ((gUnk_03001800.unk39[3] + 2) << 10) | 0xC004;
    gUnk_03002C30[rec + 0x72].unk1C = 0;
    gUnk_03002C30[rec + 0x72].unk2 = gUnk_03002C30[rec * 4 + 0x5D].unk2;
    gUnk_03002C30[rec + 0x72].unk4 = gUnk_03002C30[rec * 4 + 0x5D].unk4 + 8;
    gUnk_03002C30[rec + 0x72].unkA = 5;
    gUnk_03002C30[rec + 0x72].unkB = 1;
    gUnk_03002C30[rec + 0x72].unk6 = 0xF00;
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

void init_game_state_entry(const u16 *pos, u8 arg, u32 slot) {
    gUnk_03000440.unk64[slot].unk0 = 0;
    gUnk_03000440.unk64[slot].unk1 = 2;
    gUnk_03000440.unk64[slot].unk2 = 0;
    gUnk_03000440.unk64[slot].unk4 = pos[0];
    gUnk_03000440.unk64[slot].unk6 = pos[1];
    gUnk_03000440.unk64[slot].unk3 = arg;
}

// tree folding happens before inlining: these keep the EWRAM base added after the multiply
static inline u32 tile_offset(u32 n) {
    return n * 32;
}
static inline u32 ewram_offset(u32 n, u32 m) {
    return n * m + 0x02000000;
}

void process_animation_script(const u16 *script, u32 slot) {
    u32 run = 1;

    if (gUnk_03000440.unk64[slot].unk2 == 0xFF)
        return;

    while (run) {
        if (gUnk_03000440.unk64[slot].unk0) {
            gUnk_03000440.unk64[slot].unk0--;
            return;
        }
        switch (*(u8 *)&script[gUnk_03000440.unk64[slot].unk1]) {
        case 0xFD:
            play_sound_effect(script[gUnk_03000440.unk64[slot].unk1 + 1]);
            gUnk_03000440.unk64[slot].unk1 += 2;
            break;
        case 0xFE:
            gUnk_03000440.unk64[slot].unk1 = script[gUnk_03000440.unk64[slot].unk1 + 1] * 2;
            break;
        case 0xFF:
            gUnk_03000440.unk64[slot].unk2 = 0xFF;
            return;
        default:
            gUnk_03000440.unk64[slot].unk0 = script[gUnk_03000440.unk64[slot].unk1];
            CpuSet(
                (void *)(tile_offset(gUnk_03000440.unk64[slot].unk4) +
                         ewram_offset(gUnk_03000440.unk64[slot].unk6, script[gUnk_03000440.unk64[slot].unk1 + 1] * 32)),
                (void *)(gUnk_03000440.unk64[slot].unk3 * 0x1200 + 0x06004000),
                (gUnk_03000440.unk64[slot].unk6 * 8) | 0x04000000);
            gUnk_03000440.unk64[slot].unk1 += 2;
            break;
        }
    }
}

void increment_medal_skill_level(u32 rec) {
    u32 skill;

    if (rec > 2)
        return;
    if (gUnk_03000440.unk89 == 1)
        return;
    if (gUnk_03000590[rec].medal.unk5 == 100)
        return;
    if (gUnk_03001800.unk164 == 0)
        return;
    if (gUnk_03000590[rec].unkDD > 3)
        skill = gUnk_03000590[rec].unkA8[1];
    else
        skill = gUnk_03000590[rec].parts[gUnk_03000590[rec].unkDD - 1].data[2];
    if (gUnk_03000590[rec].medal.unk20[skill] == 100) {
        if (gUnk_03000590[rec].medal.unk28[skill] <= 6)
            gUnk_03000590[rec].medal.unk28[skill]++;
    } else {
        gUnk_03000590[rec].medal.unk28[skill]++;
        if (gUnk_03000590[rec].medal.unk28[skill] > 7) {
            gUnk_03000590[rec].medal.unk28[skill] = 0;
            gUnk_03000590[rec].medal.unk20[skill]++;
            gUnk_03001800.unk165 = 1;
            gUnk_03001800.unk166 = skill;
            gUnk_03001800.unk167 = gUnk_03000590[rec].medal.unk20[skill];
        }
    }
    sync_medal_stats_from_battle_bot(rec);
}

static void sync_medal_stats_from_battle_bot(u32 rec) {
    u32 slot = find_medal_slot_by_id(gUnk_03000590[rec].medal.unk1) - 1;
    u32 i;

    for (i = 0; i <= 7; i++) {
        gUnk_03000BE0[slot].unk20[i] = gUnk_03000590[rec].medal.unk20[i];
        gUnk_03000BE0[slot].unk28[i] = gUnk_03000590[rec].medal.unk28[i];
    }
}

void sub_0801BF64(u16 *counter, u16 max) {
    if (*counter != max)
        (*counter)++;
}

void sub_0801BF78(const u16 *pos, u8 arg, u32 slot) {
    gUnk_03000440.unk64[slot].unk0 = 0;
    gUnk_03000440.unk64[slot].unk1 = 2;
    gUnk_03000440.unk64[slot].unk2 = 0;
    gUnk_03000440.unk64[slot].unk4 = pos[0];
    gUnk_03000440.unk64[slot].unk6 = pos[1];
    gUnk_03000440.unk64[slot].unk3 = arg;
}

// tree folding happens before inlining: these keep the EWRAM base added after the multiply

void sub_0801BFB4(const u16 *script, u32 slot) {
    u32 run = 1;

    if (gUnk_03000440.unk64[slot].unk2 == 0xFF)
        return;

    while (run) {
        if (gUnk_03000440.unk64[slot].unk0) {
            gUnk_03000440.unk64[slot].unk0--;
            return;
        }
        switch (*(u8 *)&script[gUnk_03000440.unk64[slot].unk1]) {
        case 0xFD:
            play_sound_effect(script[gUnk_03000440.unk64[slot].unk1 + 1]);
            gUnk_03000440.unk64[slot].unk1 += 2;
            break;
        case 0xFE:
            gUnk_03000440.unk64[slot].unk1 = script[gUnk_03000440.unk64[slot].unk1 + 1] * 2;
            break;
        case 0xFF:
            gUnk_03000440.unk64[slot].unk2 = 0xFF;
            return;
        default:
            gUnk_03000440.unk64[slot].unk0 = script[gUnk_03000440.unk64[slot].unk1];
            CpuSet(
                (void *)(tile_offset(gUnk_03000440.unk64[slot].unk4) +
                         ewram_offset(gUnk_03000440.unk64[slot].unk6, script[gUnk_03000440.unk64[slot].unk1 + 1] * 32)),
                (void *)(gUnk_03000440.unk64[slot].unk3 * 32 + 0x06010000),
                (gUnk_03000440.unk64[slot].unk6 * 8) | 0x04000000);
            gUnk_03000440.unk64[slot].unk1 += 2;
            break;
        }
    }
}
