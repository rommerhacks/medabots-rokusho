// Mode-3 state 4: the Medaroad race. Three teams (the player's and two rivals from gRaces) run a relay of
// three Medabots each; a runner's pace comes from its leg type on the field (gRaceLegDelays), and the player
// speeds up the run animation by pressing A (the rivals tap on a rhythm). race_dispatch_substate runs
// gRaceSubStates: field announcement, team select, team introductions, start signal, race, results.
// Sprites with a motion (gSpriteEntries[].unk20) are driven by gRaceSpriteMotions; clear_sprite_entry is
// shared with other scenes.
#include "global.h"

static void race_clear_screen(void);
static void race_load_field_bg(void);
static void race_place_all_runners(void);
static bool32 race_announce_field_step(void);
static bool32 race_results_step(void);
static bool32 race_check_all_finished(void);
static void race_draw_rankings(void);
static void race_update_next_runners(void);
static void race_update_finished_runners(void);
static void race_scroll_bg3(void);
static void race_set_sprite_motion(u8 sprite, u8 motion, u8 arg, u8 arg2);

void race_dispatch_substate(void) {
    if (gRaceStaticBg == 0)
        race_scroll_bg3();
    gRaceSubStates[gGameSubState]();
}

// Sub-state 0: load the field background and announce which field the race runs on.
void race_init(void) {
    race_clear_screen();
    play_song(0);
    gRaceId = gFieldSceneParams.race_id;
    race_pick_field();
    race_load_character_sprites();
    race_load_frame_bgs();
    race_load_field_bg();
    play_song(0x13);
    setup_screen_transition_effect_080682CC(4, 1, 0);
    REG_DISPCNT |= 0x1E00;
    gRaceStep = 0;
    gRaceFinishOrder[0] = 0;
    gRaceFinishOrder[1] = 0;
    gRaceFinishOrder[2] = 0;
    gRaceRunner[0] = 0;
    gRaceRunner[1] = 0;
    gRaceRunner[2] = 0;
    gRaceNextSubState = 3;
    gGameSubState = 1;
}

// Sub-state 1: wait for the fade in, then go to gRaceNextSubState.
void race_wait_fade_in(void) {
    if (scene_transition_step_080686F4())
        gGameSubState = gRaceNextSubState;
}

// Sub-state 2: wait for the fade out, clear the sprites, then go to gRaceNextSubState.
void race_wait_fade_out(void) {
    if (execute_scene_step()) {
        u32 zero = 0;
        DmaSet(3, &zero, gSpriteEntries, 0x85000800);
        gVBlankCallback = empty_callback;
        REG_DISPCNT &= 0x80FF;
        gGameSubState = gRaceNextSubState;
    }
}

void race_announce_field(void) {
    if (race_announce_field_step()) {
        gRaceStep = 0;
        gRaceNextSubState = 4;
        gGameSubState = 2;
    }
}

// Sub-state 4: the player picks the three Medabots that run (Medabots screen).
void race_open_team_select(void) {
    REG_BLDCNT = 0xFF;
    REG_BLDY = 0xF;
    race_enter_team_select();
}

// Sub-state 5: load the three teams' part ids and leg types (player's from gBattleWork, rivals' from their
// encounter setups) and the leader portraits.
void race_load_teams(void) {
    int i;
    const u8 *setup;

    race_clear_screen();
    race_load_character_sprites();
    race_load_leader_portraits();
    race_load_frame_bgs();
    play_song(0);
    for (i = 0; i < 3; i++) {
        gRaceLegTypes[0][i] = gBattleWork.unk8C[i];
        gRaceRunnerParts[0][0][i] = gBattleWork.unk8F[i][0];
        gRaceRunnerParts[0][1][i] = gBattleWork.unk8F[i][1];
        gRaceRunnerParts[0][2][i] = gBattleWork.unk8F[i][2];
        gRaceRunnerParts[0][3][i] = gBattleWork.unk8F[i][3];
        decompress_sprite_to_vram_08042D94(gRaceRunnerParts[0][0][i], gRaceRunnerParts[0][1][i],
                                           gRaceRunnerParts[0][2][i], gRaceRunnerParts[0][3][i], 2 - i);
    }
    setup = gEncounterSetups[gRaces[gRaceId].rival1Setup];
    setup += 4;
    for (i = 0; i < 3; i++) {
        gRaceRunnerParts[1][0][i] = *setup++;
        gRaceRunnerParts[1][1][i] = *setup++;
        gRaceRunnerParts[1][2][i] = *setup++;
        gRaceRunnerParts[1][3][i] = *setup;
        setup += 9;
        gRaceLegTypes[1][i] = gMedapartData[gRaceRunnerParts[1][3][i] * 64 + 0x31] - 0x64;
        decompress_sprite_to_vram_08042D94(gRaceRunnerParts[1][0][i], gRaceRunnerParts[1][1][i],
                                           gRaceRunnerParts[1][2][i], gRaceRunnerParts[1][3][i], 5 - i);
    }
    setup = gEncounterSetups[gRaces[gRaceId].rival2Setup];
    setup += 4;
    for (i = 0; i < 3; i++) {
        gRaceRunnerParts[2][0][i] = *setup++;
        gRaceRunnerParts[2][1][i] = *setup++;
        gRaceRunnerParts[2][2][i] = *setup++;
        gRaceRunnerParts[2][3][i] = *setup;
        setup += 9;
        gRaceLegTypes[2][i] = gMedapartData[gRaceRunnerParts[2][3][i] * 64 + 0x31] - 0x64;
        decompress_sprite_to_vram_08042D94(gRaceRunnerParts[2][0][i], gRaceRunnerParts[2][1][i],
                                           gRaceRunnerParts[2][2][i], gRaceRunnerParts[2][3][i], 8 - i);
    }
    play_song(0x13);
    setup_screen_transition_effect_080682CC(2, 2, 0);
    REG_DISPCNT |= 0x1E00;
    gRaceNextSubState = 6;
    gGameSubState = 1;
}

void race_introduce_teams(void) {
    if (race_introduce_teams_step()) {
        gRaceStep = 0;
        gRaceNextSubState = 7;
        gGameSubState = 2;
    }
}

// Sub-state 7: the track screen with all nine runners at their start positions.
void race_init_track(void) {
    race_load_track_screen();
    race_place_all_runners();
    race_load_track_status_bar();
    play_song(0);
    setup_screen_transition_effect_080682CC(4, 1, 0);
    play_song(0x17);
    REG_DISPCNT |= 0x1E00;
    gRaceNextSubState = 8;
    gGameSubState = 1;
}

// Sub-state 8: the start signal drops; the race begins when it rises.
void race_start_signal(void) {
    race_run_sprite_motions();
    race_step_sprite_anims();
    if (race_start_signal_step()) {
        gRaceStep = 0;
        gGameSubState = 9;
    }
}

void race_update(void) {
    race_update_speeds();
    race_advance_runners();
    race_update_runners();
    race_update_next_runners();
    race_update_finished_runners();
    race_draw_rankings();
    race_run_sprite_motions();
    race_step_sprite_anims();
    if (race_check_all_finished()) {
        gRaceStep = 0;
        gRaceNextSubState = 10;
        gGameSubState = 2;
    }
}

// Sub-state 10: back to the portrait screen for the results.
void race_init_results(void) {
    race_clear_screen();
    race_load_character_sprites();
    race_load_leader_portraits();
    race_load_frame_bgs();
    play_song(0);
    setup_screen_transition_effect_080682CC(2, 2, 0);
    play_song(0x13);
    REG_DISPCNT |= 0x1A00;
    gRaceNextSubState = 11;
    gGameSubState = 1;
}

void race_show_results(void) {
    if (race_results_step()) {
        REG_BLDY = 0;
        REG_BLDCNT = 0xFF;
        gRaceStep = 0;
        fade_out_music(0x20);
        gRaceNextSubState = 12;
        gGameSubState = 2;
    }
}

// Sub-state 12: back to the field; scene result 1 if the player's team won, else 2.
void race_exit(void) {
    struct FieldState *result;
    race_clear_screen();
    play_song(0);
    result = &gFieldState;
    result->sceneResult = gRaceFinishOrder[0] == 1 ? 1 : 2;
    field_return_from_scene(0);
}

static void race_clear_screen(void) {
    u32 zero = 0;
    DmaSet(3, &zero, 0x06000000, 0x85006000);
    REG_DISPCNT = 0x60;
    zero = 0;
    DmaSet(3, &zero, gSpriteEntries, 0x85000800);
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
}

// The three team leaders' 64x64 portraits on BG2 (revealed row by row by race_reveal_portrait_row).
void race_load_leader_portraits(void) {
    gRaceStaticBg = 0;
    decompress_indexed_asset(0, 0, (void *)0x06004000, 9, 0);
    decompress_indexed_asset(gRaces[gRaceId].rival1Portrait, 0, (void *)0x06004800, 10, 0);
    decompress_indexed_asset(gRaces[gRaceId].rival2Portrait, 0, (void *)0x06005000, 11, 0);
    REG_BG2CNT = 0x1E02;
    gBg2Scroll.x = -24;
    gBg2Scroll.y = -96;
}

static void race_reveal_portrait_row(u8 row) {
    u16 buf[24];
    int i;
    for (i = 0; i <= 7; i++) {
        buf[i] = row * 8 - 0x6E00 + i;
        buf[i + 8] = row * 8 - 0x5DC0 + i;
        buf[i + 16] = row * 8 - 0x4D80 + i;
    }
    DmaSet(3, buf, row * 64 + 0x0600F000, 0x80000018);
    gBg2Scroll.y = -((12 - row) * 8);
}

static void race_load_field_bg(void) {
    gRaceStaticBg = 1;
    REG_BG2CNT = 0x1E0A;
    REG_BG3CNT = 0x1F0B;
    gBattleWork.battlefield = gRaceField;
    decompress_tileset_to_vram(gBattleWork.battlefield, 0);
    memcpy_bytes_0803F63C(gBattlefieldParams[gBattleWork.battlefield], gBattleWork.battlefieldParams, 8);
    apply_battle_blend_effect_a();
    decompress_to_ewram_27000(gBattlefieldTilesets[gBattleWork.battlefield * 5 + 1]);
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gVBlankCallback = battle_bg_scroll_vblank;
}

void race_load_track_screen(void) {
    gRaceStaticBg = 1;
    REG_BG2CNT = 0x1E0A;
    REG_BG3CNT = 0x1F0B;
    gBattleWork.battlefield = gRaceField;
    decompress_sprite_to_vram_08043C08(gBattleWork.battlefield, 0);
    load_battle_script_entry_b();
    apply_battle_blend_effect_b();
    decompress_to_ewram_27000(gBattlefieldGraphics[gBattleWork.battlefield * 5 + 1]);
    LZ77UnCompVram(gRaceFieldBgTiles, (void *)0x0600C800);
    LZ77UnCompVram(gRaceFieldBgTiles2, (void *)0x0600C880);
    LZ77UnCompVram(gRaceFieldBgTiles3, (void *)0x0600C9C0);
    LZ77UnCompVram(gRaceFieldBgTiles4, (void *)0x0600CC40);
    DmaSet(3, gRaceFieldBgPalettes, 0x05000100, 0x84000008);
    DmaSet(3, gRaceFieldBgPalettes2, 0x05000120, 0x84000008);
    DmaSet(3, gRaceFieldBgPalettes3, 0x05000140, 0x84000008);
    DmaSet(3, gRaceFieldBgPalettes4, 0x05000160, 0x84000008);
    race_draw_tile_block(0, 2, 4);
    race_draw_tile_block(0, 2, 7);
    race_draw_tile_block(0, 2, 0xA);
    race_draw_tile_block(1, 6, 3);
    race_draw_tile_block(2, 0xE, 3);
    race_draw_tile_block(3, 0x1A, 4);
    race_draw_tile_block(3, 0x1A, 7);
    race_draw_tile_block(3, 0x1A, 0xA);
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gVBlankCallback = battle_vblank_update_bg;
}

void race_load_track_status_bar(void) {
    vu16 zero = 0;
    DmaSet(3, &zero, 0x0600E800, 0x81000400);
    LZ77UnCompVram(gRaceStatusBarTiles, (void *)0x0600CD00);
    LZ77UnCompVram(gRaceStatusBarTiles2, (void *)0x0600D0A0);
    DmaSet(3, gRaceStatusBarPalettes, 0x05000180, 0x84000008);
    DmaSet(3, gRaceStatusBarPalettes2, 0x050001A0, 0x84000008);
    race_draw_tile_block(4, 1, 0xE);
    race_draw_tile_block(4, 0xB, 0xE);
    race_draw_tile_block(4, 0x15, 0xE);
    REG_BG1CNT = 0x1D0D;
    sprite_entry_init(1, 0xC400, 0x6F, 8, 1);
    gSpriteEntries[1].unk2 = 0xF;
    gSpriteEntries[1].unk4 = 0x7F;
    sprite_entry_init(2, 0xC400, 0x7B, 9, 1);
    gSpriteEntries[2].unk2 = 0x5F;
    gSpriteEntries[2].unk4 = 0x7F;
    sprite_entry_init(3, 0xC400, 0x87, 10, 1);
    gSpriteEntries[3].unk2 = 0xAF;
    gSpriteEntries[3].unk4 = 0x7F;
}

static inline u32 tilemap_addr(u32 base, u16 col, u16 row) {
    base += col * 2;
    return row * 64 + base;
}

// Draw tile block `block` at (x, y): 0-3 on BG1's map (track), 4-7 on BG3's (status bar; 5-7 the 1st-3rd
// place marks).
void race_draw_tile_block(u8 block, u8 x, u8 y) {
    u8 w[8];
    u8 h[8];
    u16 first[8];
    struct U16PtrArray8 lists;
    u16 pal[8];
    const u16 *tile_ptr;
    int i, j;
    u16 tile;

    memcpy_optimized(w, gRaceTileBlockWidths, 8);
    memcpy_optimized(h, gRaceTileBlockHeights, 8);
    memcpy_optimized(first, gRaceTileBlockFirstTiles, 16);
    lists = gRaceTileBlockLists;
    memcpy_optimized(pal, gRaceTileBlockPalettes, 16);

    block &= 7;
    tile_ptr = lists.v[block];
    for (i = 0; i < h[block]; i++) {
        for (j = 0; j < w[block]; j++) {
            if (block > 4)
                tile = i * 6 + j + first[block] + pal[block];
            else
                tile = *tile_ptr + first[block] + pal[block];
            if (block <= 3)
                DmaSet(3, &tile, tilemap_addr(0x0600F800, x + j, i + y),
                       0x80000001) else DmaSet(3, &tile, tilemap_addr(0x0600E800, x + j, i + y), 0x80000001) tile_ptr++;
        }
    }
}

void race_load_frame_bgs(void) {
    u16 buf[0x400];
    vu32 zero;
    int i;
    LZ77UnCompVram(gRaceBgTiles, (void *)0x0600C000);
    zero = 0;
    DmaSet(3, &zero, buf, 0x85000200);
    LZ77UnCompVram(gRaceBg2Tilemap, buf);
    for (i = 0; i < 0x280; i++)
        buf[i] += 0xC000;
    DmaSet(3, buf, 0x0600E800, 0x80000400);
    LZ77UnCompVram(gRaceBg3Tilemap, buf);
    for (i = 0; i < 0x400; i++)
        buf[i] += 0xC000;
    DmaSet(3, buf, 0x0600F800, 0x80000400);
    DmaSet(3, gRaceBgPalette, 0x05000180, 0x80000020);
    REG_BG1CNT = 0x1D0D;
    REG_BG3CNT = 0x1F0F;
}

void race_load_character_sprites(void) {
    const u8 *setup;
    LZ77UnCompVram(gFieldSpriteTiles[0x25], (void *)0x06012400);
    DmaSet(3, gFieldSpritePalettes[0x25], 0x05000200, 0x80000010);
    LZ77UnCompVram(gRaceObjTiles, (void *)0x06012E00);
    LZ77UnCompVram(gFieldSpriteTiles[0], (void *)0x06015100);
    DmaSet(3, gFieldSpritePalettes[0], 0x05000300, 0x84000008);
    setup = gEncounterSetups[gRaces[gRaceId].rival1Setup];
    LZ77UnCompVram(gFieldSpriteTiles[setup[0]], (void *)0x06015A00);
    DmaSet(3, gFieldSpritePalettes[setup[0]], 0x05000320, 0x84000008);
    setup = gEncounterSetups[gRaces[gRaceId].rival2Setup];
    LZ77UnCompVram(gFieldSpriteTiles[setup[0]], (void *)0x06016300);
    DmaSet(3, gFieldSpritePalettes[setup[0]], 0x05000340, 0x84000008);
    DmaSet(3, gRaceRunnerObjPalette, 0x050003A0, 0x84000008);
}

void race_refresh_runner_sprite(u8 idx, u8 anim) {
    u8 n = 3;
    int k; // FAKEMATCH: holds runner - 2, the original computes it separately
    u8 team = idx / 3;
    u8 runner = idx % 3;
    struct ByteTable3 params;
    memcpy_optimized(&params, &gRaceTeamSpriteParams, 3);
    setup_battle_sprite_group(gRaceRunnerParts[team][0][runner], gRaceRunnerParts[team][1][runner],
                              gRaceRunnerParts[team][2][runner], gRaceRunnerParts[team][3][runner],
                              team * 3 - (k = runner - 2), gRaceRunnerSlots[team][runner] - 3,
                              gSpriteEntries[gRaceRunnerSlots[team][runner]].unk2, params.b[team], anim, n, 5);
}

static void race_place_runner(u8 idx, s16 x, s16 y, u8 h, u8 anim) {
    int k; // FAKEMATCH: holds runner - 2, the original computes it separately
    u8 team = idx / 3;
    u8 runner = idx % 3;
    init_battle_medabot_sprites(gRaceRunnerParts[team][0][runner], gRaceRunnerParts[team][1][runner],
                                gRaceRunnerParts[team][2][runner], gRaceRunnerParts[team][3][runner],
                                team * 3 - (k = runner - 2), gRaceRunnerSlots[team][runner] - 3, x, y, h, 3, 5);
    battle_sprite_group_set_anim(gRaceRunnerSlots[team][runner] - 3, anim);
}

static void race_place_all_runners(void) {
    int i;

    race_place_runner(0, 0x2C, 0x22, 0, 4);
    race_place_runner(1, -32, 0x22, 0, 4);
    race_place_runner(2, -32, 0x22, 0, 4);
    i = 4;
    race_place_runner(3, 0x2C, 0x3A, 0, i);
    i = 6;
    race_place_runner(4, -32, 0x3A, 0, 4);
    race_place_runner(5, -32, 0x3A, 0, 4);
    race_place_runner(i, 0x2C, 0x52, 0, 4);
    race_place_runner(7, -32, 0x52, 0, 4);
    race_place_runner(8, -32, 0x52, 0, 4);
    // original passes i + 20 untruncated: compiled against an int prototype
    for (i = 0; i <= 8; i++)
        ((void (*)(int, int, int, int, int))sprite_entry_init)(i + 20, 0xCC00, 0x110, 0xD, 3);
    for (i = 0; i <= 2; i++) {
        gSpriteEntries[20 + i * 3].unk2 = 0x2C;
        gSpriteEntries[21 + i * 3].unk2 = -32;
        gSpriteEntries[22 + i * 3].unk2 = -32;
        gSpriteEntries[20 + i].unk4 = 0x2D;
        gSpriteEntries[23 + i].unk4 = 0x45;
        gSpriteEntries[26 + i].unk4 = 0x5D;
    }
    DmaSet(3, gMenuObjPalettes, 0x05000200, 0x84000040);
}

static void race_init_referee_sprite(void) {
    sprite_entry_init(0, 0xC004, 0x33, 0, 1);
    gSpriteEntries[0].unk2 = -16;
}

static void race_init_pointer_sprite(void) {
    sprite_entry_init(1, 0xC404, 0x100, 1, 3);
    gSpriteEntries[1].unk2 = 0x28;
    gSpriteEntries[1].unk4 = 0x10;
    gSpriteEntries[1].unk1A = 0;
    DmaSet(3, gRacePointerObjPalette, 0x05000220, 0x84000008);
}

static void race_init_signal_sprite(void) {
    sprite_entry_init(0, 0xC400, 0x104, 0xC, 3);
    gSpriteEntries[0].unk2 = 0x78;
    gSpriteEntries[0].unk4 = -16;
    gSpriteEntries[0].unk1A = 0;
    DmaSet(3, gRaceSignalObjPalettes, 0x05000380, 0x84000008);
    DmaSet(3, gRaceSignalObjPalettes + 0x30, 0x05000360, 0x84000008);
}

static void race_init_winner_sprite(void) {
    sprite_entry_init(1, 0xC808, 0x10B, 3, 3);
    gSpriteEntries[1].unk4 = 0x40;
    gSpriteEntries[1].unk1A = 0;
    DmaSet(3, gRaceWinnerObjPalette, 0x05000260, 0x84000008);
    REG_BLDCNT = 0xC40;
    REG_BLDALPHA = 0x10;
}

static void race_init_place_sprites(void) {
    sprite_entry_init(2, 0xCB20, 0x108, 2, 3);
    gSpriteEntries[2].unk4 = 0xC8;
    gSpriteEntries[2].unk8 = 0x88;
    gSpriteEntries[2].unk9 = 0x88;
    gSpriteEntries[2].unk18 = 0;
    gSpriteEntries[2].unk1A = 0;
    sprite_entry_init(3, 0xCB20, 0x109, 2, 3);
    gSpriteEntries[3].unk4 = 0xC8;
    gSpriteEntries[3].unk8 = 0x88;
    gSpriteEntries[3].unk9 = 0x88;
    gSpriteEntries[3].unk18 = 0;
    gSpriteEntries[3].unk1A = 0;
    sprite_entry_init(4, 0xCB20, 0x10A, 2, 3);
    gSpriteEntries[4].unk4 = 0xC8;
    gSpriteEntries[4].unk8 = 0x88;
    gSpriteEntries[4].unk9 = 0x88;
    gSpriteEntries[4].unk18 = 0;
    gSpriteEntries[4].unk1A = 0;
    DmaSet(3, gRacePlaceObjPalette, 0x05000240, 0x84000008);
}

// The race's field, or a random one of the 11.
void race_pick_field(void) {
    if (gRaces[gRaceId].fixedField != 0)
        gRaceField = gRaces[gRaceId].field;
    else
        gRaceField = gRandomBytes[(u8)gFrameCounter] % 11;
}

// Copy a 0xF9..0xFF-terminated name into the message argument buffer.
static void race_set_message_name(u8 *dst, u8 *src) {
    do {
        *dst = *src;
        dst++;
    } while (*src++ <= 0xF8);
}

static bool32 race_announce_field_step(void) {
    switch (gRaceStep) {
    case 0:
        text_window_init(1, 2, 0);
        race_init_referee_sprite();
        race_set_sprite_motion(0, 1, 0x20, 0x58);
        race_set_message_name(gTextArgBuffer, (u8 *)gBattlefieldNames[gRaceField]);
        gRaceStep++;
        return FALSE;
    case 1:
        if (run_message(gRaceMessages[0]) && gSpriteEntries[0].unk20 == 0)
            return TRUE;
        break;
    }
    race_run_sprite_motions();
    race_step_sprite_anims();
    return FALSE;
}

bool32 race_introduce_teams_step(void) {
    const u8 *setup;
    switch (gRaceStep) {
    case 0:
        text_window_init(1, 2, 0);
        race_init_referee_sprite();
        race_set_sprite_motion(0, 1, 0x18, 0x58);
        REG_DISPCNT |= 0x400;
        gRaceStep++;
        return FALSE;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        race_reveal_portrait_row(gRaceStep - 6);
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        run_message(gRaceMessages[1]);
        gRaceStep++;
        break;
    case 14:
        if (run_message(gRaceMessages[1])) {
            message_next();
            race_init_pointer_sprite();
            race_set_sprite_motion(1, 4, 0, 0);
            gRaceStep++;
        }
        break;
    case 15:
        if (run_message(gRaceMessages[2])) {
            message_next();
            gRaceStep++;
        }
        break;
    case 16:
        if (gSpriteEntries[0].unk20 == 0)
            gRaceStep++;
        break;
    case 17:
        if (run_message(gRaceMessages[5])) {
            message_next();
            setup = gEncounterSetups[gRaces[gRaceId].rival1Setup];
            race_set_message_name(gTextArgBuffer, (u8 *)gOpponentNames[setup[0]]);
            race_set_sprite_motion(0, 2, 0x40, 0);
            gSpriteEntries[1].unk2 = 0x68;
            gRaceStep++;
        }
        break;
    case 18:
        if (run_message(gRaceMessages[3]) && gSpriteEntries[0].unk20 == 0) {
            message_next();
            gRaceStep++;
        }
        break;
    case 19:
        if (run_message(gRaceMessages[gRaces[gRaceId].rivalMessage])) {
            message_next();
            setup = gEncounterSetups[gRaces[gRaceId].rival2Setup];
            race_set_message_name(gTextArgBuffer, (u8 *)gOpponentNames[setup[0]]);
            race_set_sprite_motion(0, 2, 0x40, 0);
            gSpriteEntries[1].unk2 = 0xA8;
            gRaceStep++;
        }
        break;
    case 20:
        if (run_message(gRaceMessages[4]) && gSpriteEntries[0].unk20 == 0) {
            message_next();
            gRaceStep++;
        }
        break;
    case 21:
        if (run_message(gRaceMessages[gRaces[gRaceId].rivalMessage + 1])) {
            message_next();
            gRaceStep++;
        }
        break;
    case 22:
        if (run_message(gRaceMessages[6]))
            return TRUE;
        break;
    }
    race_run_sprite_motions();
    race_step_sprite_anims();
    return FALSE;
}

static bool32 race_results_step(void) {
    const u8 *e;
    switch (gRaceStep) {
    case 0:
        text_window_init(1, 2, 0);
        race_init_referee_sprite();
        play_sound_effect(0x15);
        if (gRaceFinishOrder[0] == 1) {
            race_set_sprite_motion(0, 1, 0x18, 0x58);
            race_set_message_name(gTextArgBuffer, gPlayerName);
        } else if (gRaceFinishOrder[0] == 2) {
            race_set_sprite_motion(0, 1, 0x58, 0x58);
            e = gEncounterSetups[gRaces[gRaceId].rival1Setup];
            race_set_message_name(gTextArgBuffer, (u8 *)gOpponentNames[e[0]]);
        } else if (gRaceFinishOrder[0] == 3) {
            race_set_sprite_motion(0, 1, 0x98, 0x58);
            e = gEncounterSetups[gRaces[gRaceId].rival2Setup];
            race_set_message_name(gTextArgBuffer, (u8 *)gOpponentNames[e[0]]);
        }
        REG_DISPCNT |= 0x400;
        gRaceStep++;
        return FALSE;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        if (gRaceStep == 6) {
            race_init_place_sprites();
            race_set_sprite_motion(4, 7, 2, 0);
            gSpriteEntries[4].unk2 = (gRaceFinishOrder[2] - 1) * 64 + 0x38;
            gSpriteEntries[4].unk4 = 0x18;
            race_set_sprite_motion(3, 7, 1, 0);
            gSpriteEntries[3].unk2 = (gRaceFinishOrder[1] - 1) * 64 + 0x38;
            gSpriteEntries[3].unk4 = 0x18;
            race_set_sprite_motion(2, 7, 0, 0);
            gSpriteEntries[2].unk2 = (gRaceFinishOrder[0] - 1) * 64 + 0x38;
            gSpriteEntries[2].unk4 = 0x18;
        }
        race_reveal_portrait_row(gRaceStep - 6);
    default:
        run_message(gRaceMessages[0x1E]);
        gRaceStep++;
        break;
    case 0x96:
        play_sound_effect(0x16);
        REG_BLDCNT = 0x7F;
        race_init_winner_sprite();
        race_set_sprite_motion(1, 6, 0, 0);
        gSpriteEntries[1].unk2 = (gRaceFinishOrder[0] - 1) * 64 + 0x18;
        message_next();
        gRaceStep++;
        break;
    case 0x97:
        if (run_message(gRaceMessages[7]) && gSpriteEntries[1].unk20 == 0) {
            message_next();
            if (gRaceFinishOrder[0] == 1)
                gRaceStep++;
            else
                gRaceStep += 2;
        }
        break;
    case 0x98:
        if (run_message(gRaceMessages[8]))
            return TRUE;
        break;
    case 0x99:
        if (run_message(gRaceMessages[9]))
            return TRUE;
        break;
    }
    race_run_sprite_motions();
    race_step_sprite_anims();
    return FALSE;
}

bool32 race_start_signal_step(void) {
    switch (gRaceStep) {
    case 0:
        race_init_signal_sprite();
        race_set_sprite_motion(0, 5, 0, 0);
        gRaceStep++;
        break;
    case 1:
        if (gSpriteEntries[0].unk1A == 0xB4) {
            play_sound_effect(0x42);
            battle_sprite_group_set_anim(0x26, 0xC);
            battle_sprite_group_set_anim(0x32, 0xC);
            battle_sprite_group_set_anim(0x3E, 0xC);
            race_set_sprite_motion(1, 0xA, 0, 0);
            race_set_sprite_motion(2, 0xA, 1, 0);
            race_set_sprite_motion(3, 0xA, 2, 0);
            gRaceRivalTapTimers[0] = gRaceRivalTapTimers[1] = 0;
            gRaceRivalTaps[0] = gRaceRivalTaps[1] = 0;
            gRaceStepTimers[0] = gRaceStepTimers[1] = gRaceStepTimers[2] = 0;
            gRaceAnimDelay[0] = gRaceAnimDelay[1] = gRaceAnimDelay[2] = 0x20;
            gRaceAnimTimers[0] = gRaceAnimTimers[1] = gRaceAnimTimers[2] = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

// TRUE 240 frames after the last team finished.
static bool32 race_check_all_finished(void) {
    if (gRaceRunner[0] > 2 && gRaceRunner[1] > 2 && gRaceRunner[2] > 2) {
        if (++gRaceStep > 0xF0)
            return TRUE;
    }
    return FALSE;
}

// The place mark under each team: final place once finished, else the current one (runner, then distance).
static void race_draw_rankings(void) {
    int i, j, rank;
    for (i = 0; i <= 2; i++) {
        if (gRaceRunner[i] > 2) {
            if (gRaceFinishOrder[0] == i + 1)
                race_draw_tile_block(5, i * 10 + 5, 0xF);
            else if (gRaceFinishOrder[1] == i + 1)
                race_draw_tile_block(6, i * 10 + 5, 0xF);
            else if (gRaceFinishOrder[2] == i + 1)
                race_draw_tile_block(7, i * 10 + 5, 0xF);
        } else {
            for (j = 0, rank = 5; j <= 2; j++) {
                if (i != j) {
                    if (gRaceRunner[i] < gRaceRunner[j])
                        rank++;
                    else if (gRaceRunner[i] == gRaceRunner[j]) {
                        if (gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk1A ==
                            gSpriteEntries[gRaceRunnerSlots[j][gRaceRunner[j]]].unk1A) {
                            if (j < i)
                                rank++;
                        } else if (gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk1A <
                                   gSpriteEntries[gRaceRunnerSlots[j][gRaceRunner[j]]].unk1A)
                            rank++;
                    }
                }
            }
            race_draw_tile_block(rank, i * 10 + 5, 0xF);
        }
    }
}

// A presses (the player) and the rivals' tapping rhythm lower the run animation delay; it recovers by 2
// every 8 frames.
void race_update_speeds(void) {
    int i, j;
    if (gRaceRunner[0] <= 2 && (*(u8 *)&gNewKeys & 1)) {
        if ((u8)(gRaceAnimDelay[0] -= 4) < 4)
            gRaceAnimDelay[0] = 4;
        gSpriteEntries[gRaceRunnerSlots[0][gRaceRunner[0]]].unk1A += 3;
    }
    for (i = 1; i <= 2; i++) {
        if (gRaceRunner[i] <= 2) {
            if ((((gJumpArcTable[0])[(gRaceRivalPace[gRaceField + (j = i - 1) * 11] + gRaceRivalTaps[i - 1]) & 0xFF] >>
                  5) &
                 7) +
                    6 <=
                ++gRaceRivalTapTimers[i - 1]) {
                if ((u8)(gRaceAnimDelay[i] -= 4) < 4)
                    gRaceAnimDelay[i] = 4;
                gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk1A += 3;
                gRaceRivalTapTimers[i - 1] = 0;
                gRaceRivalTaps[i - 1]++;
            }
        }
    }
    for (i = 0; i <= 2; i++) {
        if (gRaceRunner[i] <= 2) {
            if (gRaceAnimDelay[i] == 0x20) {
                race_set_sprite_motion(i + 1, 10, i, 0);
                gRaceAnimTimers[i] = 0;
            } else if (gRaceAnimDelay[i] <= gRaceAnimTimers[i]) {
                gSpriteEntries[i + 1].unk27 += 2;
                gRaceAnimTimers[i] = 0;
            } else
                gRaceAnimTimers[i]++;
        }
    }
    if (!(gFrameCounter & 7)) {
        for (i = 0; i <= 2; i++) {
            if ((u8)(gRaceAnimDelay[i] += 2) > 0x20)
                gRaceAnimDelay[i] = 0x20;
        }
    }
}

// Each runner moves one step every gRaceLegDelays[field][leg type] frames.
void race_advance_runners(void) {
    int i;
    for (i = 0; i <= 2; i++) {
        if (gRaceRunner[i] <= 2) {
            if (gRaceLegDelays[gRaceField][gRaceLegTypes[i][gRaceRunner[i]]] <= ++gRaceStepTimers[i]) {
                gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk1A++;
                gRaceStepTimers[i] = 0;
            }
        }
    }
}

static inline int sub2(int x) {
    return x - 2;
}
static inline int add14(int x) {
    return x + 0x14;
}

// Move the running Medabots; at the end of the lap hand over to the next runner, or finish the team (the
// first finisher gets confetti).
void race_update_runners(void) {
    int i, k;
    for (i = 0; i <= 2; i++) {
        if (gRaceRunner[i] > 2)
            continue;
        if (gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk1A > 0x2AF) {
            battle_sprite_group_set_anim(gRaceRunnerSlots[i][gRaceRunner[i]] - 3, 4);
            gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk2A = 1;
            if (++gRaceRunner[i] > 2) {
                race_set_sprite_motion(i + 1, 0, 0, 0);
                if (gRaceFinishOrder[0] == 0) {
                    gRaceFinishOrder[0] = i + 1;
                    for (k = 0; k <= 15; k++) {
                        u8 variant = gRandomBytes[(gFrameCounter + k) & 0xFF];
                        variant &= 3;
                        // the original passes k + 4 untruncated: called without (or with an int-slot) prototype
                        ((void (*)())sprite_entry_init)(k + 4, 0xC400, variant + 0x10C, 0xB, 3);
                        gSpriteEntries[k + 4].unkB = 0x64;
                        race_set_sprite_motion(k + 4, 8, variant, (k * 16) & 0x7F);
                    }
                } else if (gRaceFinishOrder[1] == 0)
                    gRaceFinishOrder[1] = i + 1;
                else if (gRaceFinishOrder[2] == 0)
                    gRaceFinishOrder[2] = i + 1;
                play_sound_effect(0x43);
                continue;
            }
            play_sound_effect(0x44);
            gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk1A = 0;
            gRaceAnimDelay[i] = 0x20;
            gRaceAnimTimers[i] = 0;
        }
        if (gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk3A <= 0x157 &&
            gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk1A > 0x157) {
            race_refresh_runner_sprite(i * 3 + gRaceRunner[i], 1);
            gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]] - 3].unkB -= 4;
            gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]] - 2].unkB -= 4;
            gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]] - 1].unkB -= 4;
            gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unkB -= 4;
            if (gRaceRunner[i] <= 1)
                gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i] + 1]].unk2A = 2;
        }
        if (gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk1A > 0x158)
            gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk2 =
                0xD8 - ((gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk1A - 0x158) >> 1);
        else {
            gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk2 =
                (gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk1A >> 1) + 0x2C;
            if (gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk3A <= 0x97 &&
                gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk1A > 0x97 && gRaceRunner[i] <= 1) {
                gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i] + 1]].unk2A = 1;
                battle_sprite_group_set_anim(gRaceRunnerSlots[i][gRaceRunner[i] + 1] - 3, 4);
            }
        }
        gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk3A =
            gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk1A;
        gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk1A++;
        update_battle_sprite_orbiting_positions(gRaceRunnerSlots[i][gRaceRunner[i]] - 3, i * 3 - sub2(gRaceRunner[i]),
                                                0);
        gSpriteEntries[i * 3 + add14(gRaceRunner[i])].unk2 = gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i]]].unk2;
    }
}

// Inline helpers: the original evaluates these offsets separately (no fold into the index).
static inline int sub1(int x) {
    return x - 1;
}

// The next runner of each team walks to the start line.
static void race_update_next_runners(void) {
    int i, t;
    for (i = 0; i <= 2; i++) {
        if (gRaceRunner[i] > 1)
            continue;
        if (gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i] + 1]].unk2A == 1) {
            update_battle_sprite_orbiting_positions(gRaceRunnerSlots[i][gRaceRunner[i] + 1] - 3,
                                                    i * 3 - sub1(gRaceRunner[i]), 0);
            gSpriteEntries[gRaceRunner[i] + i * 3 + 0x15].unk2 =
                gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i] + 1]].unk2;
            if (gFrameCounter & 1) {
                if (++gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i] + 1]].unk2 == 0x18) {
                    gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i] + 1]].unk2A = 0;
                    init_battle_medabot_sprites(
                        gRaceRunnerParts[i][0][gRaceRunner[i] + 1], gRaceRunnerParts[i][1][gRaceRunner[i] + 1],
                        gRaceRunnerParts[i][2][gRaceRunner[i] + 1], gRaceRunnerParts[i][3][gRaceRunner[i] + 1],
                        i * 3 - (t = gRaceRunner[i] - 1), gRaceRunnerSlots[i][gRaceRunner[i] + 1] - 3,
                        gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i] + 1] - 3].unk2,
                        gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i] + 1] - 3].unk4 + 3, 0, 3, 5);
                    battle_sprite_group_set_anim(gRaceRunnerSlots[i][gRaceRunner[i] + 1] - 3, 8);
                }
            }
        } else if (gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i] + 1]].unk2A == 2) {
            update_battle_sprite_orbiting_positions(gRaceRunnerSlots[i][gRaceRunner[i] + 1] - 3,
                                                    i * 3 - sub1(gRaceRunner[i]), 0);
            gSpriteEntries[gRaceRunner[i] + i * 3 + 0x15].unk2 =
                gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i] + 1]].unk2;
            if (gFrameCounter & 1) {
                if (++gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i] + 1]].unk2 == 0x2C) {
                    gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i] + 1]].unk2A = 0;
                    init_battle_medabot_sprites(
                        gRaceRunnerParts[i][0][gRaceRunner[i] + 1], gRaceRunnerParts[i][1][gRaceRunner[i] + 1],
                        gRaceRunnerParts[i][2][gRaceRunner[i] + 1], gRaceRunnerParts[i][3][gRaceRunner[i] + 1],
                        i * 3 - (t = gRaceRunner[i] - 1), gRaceRunnerSlots[i][gRaceRunner[i] + 1] - 3,
                        gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i] + 1] - 3].unk2,
                        gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i] + 1] - 3].unk4 + 3, 0, 3, 5);
                    battle_sprite_group_set_anim(gRaceRunnerSlots[i][gRaceRunner[i] + 1] - 3, 0xC);
                }
            }
        }
    }
}

// A runner that handed over walks off the left edge.
static void race_update_finished_runners(void) {
    int i, k;
    for (i = 0; i < 3; i++) {
        if (gRaceRunner[i] != 0) {
            if (gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i] - 1]].unk2A == 1) {
                if (--gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i] - 1]].unk2 <= -16)
                    gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i] - 1]].unk2A = 0;
                update_battle_sprite_orbiting_positions(gRaceRunnerSlots[i][gRaceRunner[i] - 1] - 3,
                                                        i * 3 - (k = gRaceRunner[i] - 3), 0);
                gSpriteEntries[gRaceRunner[i] + i * 3 + 0x13].unk2 =
                    gSpriteEntries[gRaceRunnerSlots[i][gRaceRunner[i] - 1]].unk2;
            }
        }
    }
}

// Run the motion of sprites 0-19; a motion that returns FALSE is stopped.
void race_run_sprite_motions(void) {
    u8 i;
    for (i = 0; i <= 0x13; i++) {
        if (gSpriteEntries[i].unk20 != 0) {
            if (gRaceSpriteMotions[gSpriteEntries[i].unk20 - 1](i))
                gSpriteEntries[i].unk1A++;
            else if (gSpriteEntries[i].unk20 != 0)
                race_set_sprite_motion(i, 0, 0, 0);
        }
    }
}

bool32 race_motion_none(u8 sprite) {
    return FALSE;
}

// Motion 1: the referee hops in, then walks right to x = unk22.
bool32 race_motion_hop_in(u8 sprite) {
    if (gSpriteEntries[sprite].unk1A < 0x20) {
        gSpriteEntries[sprite].unk2++;
        gSpriteEntries[sprite].unk4 =
            gSpriteEntries[sprite].unk23 + 3 - gHalfSineArc[gSpriteEntries[sprite].unk1A + 0x20];
    } else if (gSpriteEntries[sprite].unk1A < 0x30) {
        gSpriteEntries[sprite].unk4 = gSpriteEntries[sprite].unk23 + 3;
    } else {
        gSpriteEntries[sprite].unk2 += 2;
    }
    if (gSpriteEntries[sprite].unk22 <= gSpriteEntries[sprite].unk2)
        return FALSE;
    return TRUE;
}

bool32 race_motion_move_right(u8 sprite) {
    gSpriteEntries[sprite].unk2 += 2;
    if (gSpriteEntries[sprite].unk22 < gSpriteEntries[sprite].unk1A)
        return FALSE;
    return TRUE;
}

bool32 race_motion_move_left(u8 sprite) {
    gSpriteEntries[sprite].unk2 -= 2;
    if (gSpriteEntries[sprite].unk22 < gSpriteEntries[sprite].unk1A)
        return FALSE;
    return TRUE;
}

bool32 race_motion_hold(u8 sprite) {
    return TRUE;
}

// Motion 5: the start signal drops in, waits, rises and clears itself.
bool32 race_motion_signal(u8 sprite) {
    if (gSpriteEntries[sprite].unk1A < 0x10)
        gSpriteEntries[sprite].unk4 += 2;
    if ((u16)(gSpriteEntries[sprite].unk1A - 0xD2) < 0x10)
        gSpriteEntries[sprite].unk4 -= 2;
    if (gSpriteEntries[sprite].unk1A > 0xE1) {
        clear_sprite_entry(sprite);
        return FALSE;
    }
    return TRUE;
}

// Motion 6: alpha-blend in and out while rising (winner mark).
bool32 race_motion_fade_rise(u8 sprite) {
    if (gSpriteEntries[sprite].unk1A < 0x10)
        REG_BLDALPHA = 0x1000 | gSpriteEntries[sprite].unk1A;
    else if (gSpriteEntries[sprite].unk1A < 0x20)
        REG_BLDALPHA = ((0x20 - gSpriteEntries[sprite].unk1A) << 8) | 0x10;
    if (gSpriteEntries[sprite].unk1A & 1)
        gSpriteEntries[sprite].unk4--;
    if (gSpriteEntries[sprite].unk1A > 0x3F) {
        REG_BLDCNT = 0;
        return FALSE;
    }
    return TRUE;
}

// Motion 7: shrink and rotate (place marks).
bool32 race_motion_shrink_spin(u8 sprite) {
    if (gSpriteEntries[sprite].unk1A & 1) {
        gSpriteEntries[sprite].unk8--;
        gSpriteEntries[sprite].unk9--;
    }
    gSpriteEntries[sprite].unk18 += 0x40;
    if (gSpriteEntries[sprite].unk1A > 0x8F) {
        gSpriteEntries[sprite].unk18 = 0;
        return FALSE;
    }
    return TRUE;
}

// Motion 8: confetti flies out along angle unk23, then switches to motion 9.
u32 race_motion_confetti_burst(u8 i) {
#define S gSpriteEntries[i]
    S.unkC_8 += gJumpArcTable[0][(S.unk23 + 0x40) & 0xFF];
    S.unk10_8 += gJumpArcTable[0][S.unk23];
    if (i > 11) {
        S.unk2 = S.unkC_8 / 256 + 0x20;
        S.unk4 = 0x10 - S.unk10_8 / 256;
    } else {
        S.unk2 = S.unkC_8 / 128 + 0x20;
        S.unk4 = 0x10 - S.unk10_8 / 128;
    }
    if (S.unk1A > 8) {
        S.unk1A = gRandomBytes[(gFrameCounter + i) & 0xFF] >> 3;
        S.unk20 = 9;
    }
    return 1;
#undef S
}

// Motion 9: confetti flutters down and stops below the screen.
u32 race_motion_confetti_fall(u8 i) {
#define S gSpriteEntries[i]
    u32 phase = (S.unk1A + 0x10) & 0x3F;

    if (S.unk4 > 0x60) {
        S.unk4 = 0xC8;
        return 0;
    }
    if (S.unk1A & 1)
        S.unk4++;
    if (phase & 0x10) {
        if (S.unk1A & 1) {
            if (i & 1)
                S.unk2++;
            else
                S.unk2--;
        }
    } else {
        if (S.unk1A & 1) {
            if (i & 1)
                S.unk2--;
            else
                S.unk2++;
        }
    }
    if (S.unk1A & 8)
        S.unk0 |= 0x1000;
    else
        S.unk0 &= 0xEFFF;
    return 1;
#undef S
}

// Motion 10 (running Medabot icons): counts down unk27, holding the animation frame.
u32 race_motion_slow_anim(u8 i) {
    if (gSpriteEntries[i].unk27)
        gSpriteEntries[i].unk27--;
    return 1;
}

static void race_scroll_bg3(void) {
    if (gFrameCounter & 1) {
        gBg3Scroll.x--;
        gBg3Scroll.y++;
    }
}

void race_step_sprite_anims(void) {
    u8 i;

    for (i = 0; i < 20; i++) {
        struct SpriteEntry *s = &gSpriteEntries[i];
        if (s->unk21 != 0) {
            const struct SpriteAnimFrame *tbl = gRaceSpriteAnims;
            if (tbl[s->unk21].duration <= s->unk27++) {
                s->unk27 = 0;
                s->unk21 = tbl[s->unk21].next;
                s->unk6 = tbl[s->unk21].frame;
            }
        }
    }
}

// Start motion `motion` (0 stops it) on a sprite that has none; arg and arg2 depend on the motion.
static void race_set_sprite_motion(u8 sprite, u8 motion, u8 arg, u8 arg2) {
    if (motion == 0) {
        gSpriteEntries[sprite].unk20 = 0;
        gSpriteEntries[sprite].unk21 = 0;
        gSpriteEntries[sprite].unk22 = 0;
        gSpriteEntries[sprite].unk6 = gSpriteEntries[sprite].unk30;
        gSpriteEntries[sprite].unk1A = 0;
        return;
    }
    if (gSpriteEntries[sprite].unk20 != 0)
        return;
    switch (motion) {
    case 1:
        gSpriteEntries[sprite].unk20 = 1;
        gSpriteEntries[sprite].unk21 = 1;
        gSpriteEntries[sprite].unk22 = arg;
        gSpriteEntries[sprite].unk23 = arg2;
        gSpriteEntries[sprite].unk30 = 0x33;
        gSpriteEntries[sprite].unk6 = gRaceSpriteAnims[1].frame;
        break;
    case 2:
        gSpriteEntries[sprite].unk20 = 2;
        gSpriteEntries[sprite].unk21 = 3;
        gSpriteEntries[sprite].unk22 = arg >> 1;
        gSpriteEntries[sprite].unk30 = 0x33;
        gSpriteEntries[sprite].unk6 = gRaceSpriteAnims[3].frame;
        break;
    case 3:
        gSpriteEntries[sprite].unk20 = 3;
        gSpriteEntries[sprite].unk21 = 7;
        gSpriteEntries[sprite].unk22 = arg >> 1;
        gSpriteEntries[sprite].unk30 = 0x33;
        gSpriteEntries[sprite].unk6 = gRaceSpriteAnims[7].frame;
        break;
    case 4:
        gSpriteEntries[sprite].unk20 = 4;
        gSpriteEntries[sprite].unk21 = 0xB;
        gSpriteEntries[sprite].unk22 = arg;
        gSpriteEntries[sprite].unk30 = 0x100;
        gSpriteEntries[sprite].unk6 = gRaceSpriteAnims[0xB].frame;
        break;
    case 5:
        gSpriteEntries[sprite].unk20 = 5;
        gSpriteEntries[sprite].unk21 = 0xF;
        gSpriteEntries[sprite].unk22 = arg;
        gSpriteEntries[sprite].unk30 = 0x107;
        gSpriteEntries[sprite].unk6 = gRaceSpriteAnims[0xF].frame;
        break;
    case 6:
        gSpriteEntries[sprite].unk20 = 6;
        gSpriteEntries[sprite].unk21 = 0;
        gSpriteEntries[sprite].unk22 = arg;
        gSpriteEntries[sprite].unk30 = 0x10B;
        gSpriteEntries[sprite].unk6 = gSpriteEntries[sprite].unk30;
        break;
    case 7:
        gSpriteEntries[sprite].unk20 = 7;
        gSpriteEntries[sprite].unk21 = 0;
        gSpriteEntries[sprite].unk30 = arg + 0x108;
        gSpriteEntries[sprite].unk6 = gSpriteEntries[sprite].unk30;
        break;
    case 8:
        gSpriteEntries[sprite].unk20 = 8;
        gSpriteEntries[sprite].unk21 = 0;
        gSpriteEntries[sprite].unk23 = arg2;
        gSpriteEntries[sprite].unk30 = arg + 0x10C;
        gSpriteEntries[sprite].unk6 = gSpriteEntries[sprite].unk30;
        break;
    case 10:
        gSpriteEntries[sprite].unk20 = 10;
        gSpriteEntries[sprite].unk21 = arg * 4 + 0x14;
        gSpriteEntries[sprite].unk27 = 0;
        gSpriteEntries[sprite].unk30 = arg * 12 + 0x6F;
        gSpriteEntries[sprite].unk6 = gSpriteEntries[sprite].unk30;
        break;
    }
    gSpriteEntries[sprite].unk1A = 0;
}

void clear_sprite_entry(u8 sprite) {
    u32 zero = 0;
    DmaSet(3, &zero, &gSpriteEntries[sprite], 0x85000010);
}
