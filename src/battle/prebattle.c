// Game state 6: the screens around a Robattle. Before it: the mosaic flash and stripe wipe over the field,
// loading the encounter (random encounter enemies, battlefield), the opponent's line, the Rubberobo option
// and team select. After it: the battle count, the part won (with its detail page), experience and Medal
// level-up, the loss path (part taken, no Medabots left), and the exit back to the field.
// Entry point prebattle_screen_update (sub-states in gPrebattleScreenHandlers). Hands over to state 7
// (battle/robattle) and back to the field (game mode 1).

#include "global.h"
#include "constants/skill_sprites.h"
#include "constants/sprites.h"

static void load_encounter_into_battle_setup(void);
static void prebattle_draw_opponent_name(void);
static void prebattle_draw_battlefield_name(void);
static void load_opponent_medabot_sprites(void);
static void update_all_battle_sprite_orbits(void);
static void prebattle_init_rubberobo_sprite(void);
static void afterbattle_choose_won_part(void);
static s32 afterbattle_broken_part_chance(void);
static void setup_battle_result_sprite(void);
static void afterbattle_pulse_new_sprite(void);
static void setup_battle_result_sprite_animation(void);
static void calc_average_bot_stat_080125B4(void);
static void accumulate_alive_bot_score(void);
static void calc_average_bot_stat_0801264C(void);
static void calc_medaforce_gauge_from_damage(void);
static void battle_score_add_time_bonus(void);
static void battle_check_medal_level_up(void);

// Game state 6, "Get ready to Robattle" (runtime-checked from the debug Battle entry): sub-states 0-5
// flash a mosaic over the field three times, 6-7 wipe the screen in stripes, 8 loads the encounter,
// 9 loads the pre-battle screen graphics.
void prebattle_screen_update(void) {
    u32 fill;

    if (gVBlankOamMode == 2) {
        fill = 0x200;
        DmaSet(3, &fill, gSpriteWork->oamBuf, 0x85000100);
    }
    gPrebattleScreenHandlers[gGameSubState]();
}

void prebattle_mosaic_start(void) {
    REG_BG0CNT |= 0x40;
    REG_BG1CNT |= 0x40;
    REG_BG2CNT |= 0x40;
    REG_BG3CNT |= 0x40;
    play_song(8);
    gGameWork.repeatCounter = 0;
    gGameSubState++;
}

void prebattle_mosaic_grow_init(void) {
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void prebattle_mosaic_grow(void) {
    REG_MOSAIC = gGameWork.stepCounter + (gGameWork.stepCounter << 4);
    gGameWork.stepCounter += 2;
    if (gGameWork.stepCounter == 16)
        gGameSubState = 5;
}

void prebattle_mosaic_shrink_init(void) {
    gGameWork.stepCounter = 16;
    gGameSubState++;
}

void prebattle_mosaic_shrink(void) {
    u32 mosaic_size = gGameWork.stepCounter - 2;

    gGameWork.stepCounter = mosaic_size;
    REG_MOSAIC = gGameWork.stepCounter + (gGameWork.stepCounter << 4);
    if ((u8)mosaic_size == 0)
        gGameSubState = 5;
}

void prebattle_mosaic_repeat(void) {
    if (gGameWork.repeatCounter <= 2) {
        if (gGameWork.repeatCounter & 1)
            gGameSubState = 1;
        else
            gGameSubState = 3;
        gGameWork.repeatCounter++;
    } else
        gGameSubState++;
}

void prebattle_wipe_init(void) {
    REG_DISPCNT |= 0x100;
    REG_BG0CNT = 0x500;
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    lz_decompress_dispatch(gPrebattleWipeTiles, (void *)0x06002600);
    DmaSet(3, gPrebattleWipePalette, 0x050001A0, 0x84000008);
    gGameWork.listTab = 0;
    gGameWork.subCounter = 0;
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void prebattle_wipe(void) {
    s32 start, i;

    if (gGameWork.subCounter <= 4)
        start = 0;
    else
        start = gGameWork.subCounter - 4;
    for (i = start; i <= gGameWork.subCounter; i++) {
        if (i <= 14)
            vram_fill_tilemap_rect(1, 20, i, 0, REG_BG0CNT, gGameWork.subCounter - i - 0x2ED0);
    }
    for (i = start; i <= gGameWork.subCounter; i++) {
        if (i <= 14)
            vram_fill_tilemap_rect(1, 20, 29 - i, 0, REG_BG0CNT, gGameWork.subCounter - i - 0x2ED0);
    }
    if (++gGameWork.subCounter > 19)
        gGameSubState++;
}

void prebattle_load_encounter(void) {
    u32 zero0, zero1;

    load_encounter_into_battle_setup();
    gGameWork.battleOver = 0;
    zero0 = 0;
    CpuFastSet(&zero0, (void *)0x05000200, 0x01000080);
    zero1 = 0;
    CpuFastSet(&zero1, (void *)0x05000000, 0x01000080);
    gGameSubState++;
}

void prebattle_load_gfx(void) {
    u32 zero;

    clear_bg_scroll();
    REG_DISPCNT &= 0xE0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x590A;
    REG_BG3CNT = 0x5B0B;
    lz_decompress_dispatch(gPrebattleBgTiles, (void *)0x06004000);
    lz_decompress_dispatch(gLegTypePedestalTiles, (void *)0x06006000);
    lz_decompress_dispatch(gLegTypePedestalTiles2, (void *)0x06006200);
    lz_decompress_dispatch(gPrebattleObjTiles, (void *)0x06012800);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG1CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gPrebattleBg1Tilemap, REG_BG1CNT, 0x200);
    DmaSet(3, gPrebattleBgPalette, 0x0202FA00, 0x84000070);
    DmaSet(3, gLegTypePedestalPalette, 0x0202FB00, 0x84000008);
    DmaSet(3, gLegTypePedestalPalette2, 0x0202FB20, 0x84000008);
    DmaSet(3, gMenuObjPalettes, 0x0202F800, 0x84000040);
    DmaSet(3, gGradientPaletteYellow + 0xB0, 0x0202F980, 0x84000008);
    DmaSet(3, gGradientPaletteYellow, 0x0202F9A0, 0x84000008);
    DmaSet(3, gPrebattleObjPalette, 0x0202F940, 0x84000008);
    DmaSet(3, gPartIconSpritePalette, 0x0202F960, 0x84000008);
    decompress_tileset_to_vram(gBattleWork.battlefield, 1);
    zero = 0;
    DmaSet(3, &zero, gSpriteEntries, 0x85000800);
    REG_DISPCNT |= 0x1F60;
    prebattle_draw_opponent_name();
    prebattle_draw_battlefield_name();
    load_opponent_medabot_sprites();
    init_opponent_medabot_sprites();
    draw_opponent_leg_type_icons();
    prebattle_init_rubberobo_sprite();
    battlefield_load_params();
    apply_battle_blend_effect_a();
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

// guess: fades the sprites in from white (state 6 sub 10)
void prebattle_fade_in(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gGameWork.stepCounter <= 8) {
        bg_palettes_blend_masked_now(0, 32 - gGameWork.stepCounter * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, 32 - gGameWork.stepCounter * 4, 0xFFFF);
        gGameWork.stepCounter++;
    } else
        gGameSubState++;
}

void prebattle_open_text_window(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void prebattle_show_opponent_line(void) {
    update_scroll_movement_a();
    if (run_message(gOpponentPreBattleMessages[gBattleWork.encounterMessage])) {
        update_all_battle_sprite_orbits();
        gGameWork.stepCounter = 8;
        gGameWork.repeatCounter = 8;
        gGameSubState++;
    }
    update_all_battle_sprite_orbits();
}

// START (with a Rubberobo Medal, item 50, outside debug battles) asks to use it; A starts the battle
void prebattle_wait_for_start_input(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if ((KEYS_LO(gNewKeys) & 8) && get_item_quantity_by_id(50) && gFieldWork.fixed_battle == 0) {
        play_sound_effect(4);
        gGameSubState++;
    } else if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        gGameSubState = 32;
    }
}

void prebattle_rubberobo_open_window(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (game_state_execute_handler_a()) {
        text_window_init(1, 2, 0);
        gGameSubState++;
    }
}

void prebattle_rubberobo_ask(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gMenuMessages[20])) {
        open_choice_menu(1, 22, 7);
        gGameSubState++;
    }
}

void prebattle_rubberobo_choice(void) {
    u32 choice;

    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    choice = poll_choice_menu();
    if (choice) {
        if ((choice >> 4) == 0) {
            message_next();
            gGameSubState++;
        } else
            gGameSubState = 32;
    }
}

void prebattle_rubberobo_use(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gMenuMessages[21])) {
        fade_out_music(8);
        item_remove_quantity(50, 1);
        gGameSubState++;
    }
}

void prebattle_fade_out_init(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    palette_backup_from_hardware();
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void prebattle_fade_out(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gGameWork.stepCounter <= 8) {
        bg_palettes_blend_masked_now(0, gGameWork.stepCounter * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, gGameWork.stepCounter * 4, 0xFFFF);
        gGameWork.stepCounter++;
    } else
        gGameSubState++;
}

void prebattle_clear_screen(void) {
    set_blend_effect_mode(0, 0, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG1CNT, 0);
    clear_battle_sprite_slot(0, 0x80);
    gGameSubState++;
}

void prebattle_rubberobo_load_field(void) {
    area_load_graphics();
    blend_set_alpha_12_10();
    setup_blend_effect(0x40, 0x2F00, 5, 16, 16, 16, 12, 10, 0);
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

// Rubberobo Medal used (runtime-checked: "You avoided the Robattle!", then back in the field): fade the field
// back in and skip the battle.
void prebattle_rubberobo_return_to_field(void) {
    if (gGameWork.stepCounter <= 16) {
        blend_effect_update();
        bg_palettes_blend_masked_now(0, 32 - gGameWork.stepCounter * 2, 0xFFFF);
        obj_palettes_blend_masked_now(0, 32 - gGameWork.stepCounter * 2, 0xFFFF);
        gGameWork.stepCounter++;
    } else {
        gVBlankCallback = empty_callback;
        return_to_field();
    }
}

// A on the pre-battle screen: Medabots screen in team select mode (game state 3, medabotsMode = 2)
void prebattle_open_team_select(void) {
    mem_fill8(&gGameWork.medabotsMode, 0x14, 0);
    gGameWork.medabotsMode = 2;
    gGameState = 3;
    gGameSubState = 0;
}

// Game state 6 sub-states 48+ = after the Robattle (runtime-checked from a debug battle,
// re/scratch/afterbattle_probe.txt): 53 opponent line, 55-61 Medapart won (START = details),
// 64-65 experience, 66+ Medal level-ups and Medaforces per team member (resultsMember)
void afterbattle_count_battle(void) {
    inc_u16_saturating(&gRobattleCounts[0], 9999);
    if (gGameWork.battleResult == 1) {
        inc_u16_saturating(&gRobattleCounts[1], 9999);
        play_song(14);
    } else
        play_song(15);
    gGameSubState++;
}

void afterbattle_check_won(void) {
    update_scroll_movement_a();
    if (gGameWork.battleResult == 1)
        gGameSubState++;
    else
        gGameSubState = 0x70;
}

void afterbattle_show_opponent_line(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gOpponentAfterBattleMessages[gBattleWork.encounterMessage]) && (KEYS_LO(gNewKeys) & 3)) {
        gGameWork.endModeStep = 0;
        play_sound_effect(13);
        gGameSubState++;
    }
}

void afterbattle_close_opponent_line(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (game_state_execute_handler_b()) {
        message_next();
        gGameSubState++;
    }
}

void afterbattle_give_part(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gFieldWork.battle_flags & 0xF) {
        gFieldWork.battle_flags = 0;
        gGameSubState = 62;
    } else {
        afterbattle_choose_won_part();
        if (medapart_get_counts(gBattleWork.wonPartId, gBattleWork.wonPartKind))
            gBattleWork.wonPartNew = 0;
        else
            gBattleWork.wonPartNew = 1;
        medapart_add_quantity(gBattleWork.wonPartId, gBattleWork.wonPartKind, 1);
        gGameSubState++;
    }
}

void afterbattle_load_part_name(void) {
    const u32 *tbl;

    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite_animation();
    memcpy_bytes_0803F63C(gPartKindNames[gBattleWork.wonPartKind], gGameWork.textBuf, 14);
    tbl = gMedapartNames[0];
    memcpy_bytes_0803F63C((const void *)tbl[gBattleWork.wonPartId * 4 + gBattleWork.wonPartKind],
                          gGameWork.textBuf + 20, 15);
    gGameSubState++;
}

void afterbattle_show_part_acquired(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    if (run_message(gBattleMessages[107])) {
        if (gBattleWork.wonPartNew)
            gGameSubState++;
        else
            gGameSubState = 60;
    }
}

// guess: new Medapart: "NEW" sprite (sprite 1, sound 0x2A)
void afterbattle_load_new_part_sprite(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    lz_decompress_dispatch(gNewPartSpriteTiles, (void *)0x06012400);
    DmaSet(3, gResultSpritePalettes, 0x05000340, 0x84000008);
    gSpriteEntries[1].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE |
                              SPRITE_FLAG_DOUBLE_SIZE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[1].frame_table = 0;
    gSpriteEntries[1].x = 0xC0;
    gSpriteEntries[1].y = 0x60;
    gSpriteEntries[1].palette = 10;
    gSpriteEntries[1].order = 0xC0;
    gSpriteEntries[1].frame = 0x5900;
    gSpriteEntries[1].scale_y = 0x40;
    gSpriteEntries[1].scale_x = 0x40;
    gSpriteEntries[1].work[FX_SPR_STEP] = 0;
    gSpriteEntries[1].work[NEW_SPR_SHRINK] = 0;
    play_sound_effect(0x2A);
    gGameSubState++;
}

void afterbattle_animate_new_part_sprite(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    if (advance_sprite_anim_frame(1, 0))
        gGameSubState++;
}

void afterbattle_load_part_icon_sprite(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    afterbattle_pulse_new_sprite();
    lz_decompress_dispatch(gPartIconSpriteTiles, (void *)0x06016C00);
    DmaSet(3, gPartIconSpritePalette, 0x05000360, 0x84000008);
    gSpriteEntries[2].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[2].frame_table = 0;
    gSpriteEntries[2].x = 8;
    gSpriteEntries[2].y = 0x50;
    gSpriteEntries[2].palette = 11;
    gSpriteEntries[2].order = 0xC0;
    gSpriteEntries[2].frame = 0x5A00;
    gGameSubState++;
}

void afterbattle_part_details_input(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    afterbattle_pulse_new_sprite();
    if (KEYS_LO(gNewKeys) & 3) {
        clear_battle_sprite_slot(1, 2);
        gVBlankOamMode = 0;
        play_sound_effect(13);
        gGameSubState++;
    } else if (KEYS_LO(gNewKeys) & 8) {
        play_sound_effect(4);
        gGameSubState = 0x60;
    }
}

// Some opponents (gBattleWork.rubberoboReward) also hand over a Rubberobo Medal (item 50) after the battle.
void afterbattle_check_rubberobo_reward(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gBattleWork.rubberoboReward) {
        message_next();
        gGameSubState++;
    } else
        gGameSubState = 0x40;
}

void afterbattle_give_rubberobo_medal(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gBattleMessages[118])) {
        item_add_quantity(50, 1);
        gGameSubState++;
    }
}

void afterbattle_load_experience(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    calculate_battle_score_summary();
    divide_by_100000_b(gGameWork.textBuf, gBattleWork.score, 0x35);
    message_next();
    gGameSubState++;
}

void afterbattle_show_experience(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gBattleMessages[109]))
        gGameSubState++;
}

void afterbattle_start_medal_level_up(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    battle_check_medal_level_up();
    gBattleWork.resultsMember = 0;
    gGameSubState++;
}

// guess: 0x43-0x45 announce, bot by bot (resultsMember = team slot), each Medal that levelled up (memberResults[i][0] =
// Medal id
// + 1); 0x47-0x49 then announce learned Medaforces (memberResults[i][6], name index [7]) and 0x4B-0x50 play the Medal
// transform for bots with memberResults[i][1] set.
void afterbattle_level_up_next_bot(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gBattleWork.resultsMember == 3) {
        gBattleWork.resultsMember = 0;
        gGameSubState = 0x47;
    } else if (gBattleWork.memberResults[gBattleWork.resultsMember][0]) {
        message_next();
        memcpy_bytes_0803F63C((const void *)gMedalNames[gBattleWork.memberResults[gBattleWork.resultsMember][0] - 1],
                              gGameWork.textBuf, 11);
        play_song(16);
        gGameSubState++;
    } else
        gBattleWork.resultsMember++;
}

void afterbattle_level_up_show_message(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gBattleMessages[119]))
        gGameSubState++;
}

void afterbattle_level_up_advance(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    gBattleWork.resultsMember++;
    gGameSubState = 0x43;
}

void afterbattle_medaforce_next_bot(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gBattleWork.resultsMember == 3) {
        gBattleWork.resultsMember = 0;
        gGameSubState = 0x4B;
    } else if (gBattleWork.memberResults[gBattleWork.resultsMember][6]) {
        message_next();
        memcpy_bytes_0803F63C((const void *)gMedalNames[gBattleWork.memberResults[gBattleWork.resultsMember][0] - 1],
                              gGameWork.textBuf, 11);
        memcpy_bytes_0803F63C((const void *)gMedaforceNames[gBattleWork.memberResults[gBattleWork.resultsMember][7]],
                              gGameWork.textBuf + 20, 17);
        play_song(16);
        gGameSubState++;
    } else
        gBattleWork.resultsMember++;
}

void afterbattle_medaforce_show_message(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gBattleMessages[120]))
        gGameSubState++;
}

void afterbattle_medaforce_advance(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    gBattleWork.resultsMember++;
    gGameSubState = 0x47;
}

void afterbattle_transform_next_bot(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gBattleWork.resultsMember == 3) {
        gBattleWork.resultsMember = 0;
        gGameSubState = 0x58;
    } else if (gBattleWork.memberResults[gBattleWork.resultsMember][1])
        gGameSubState++;
    else
        gBattleWork.resultsMember++;
}

void afterbattle_fade_out_init(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    palette_backup_from_hardware();
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void afterbattle_fade_out(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gGameWork.stepCounter <= 8) {
        bg_palettes_blend_masked_now(0, gGameWork.stepCounter * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, gGameWork.stepCounter * 4, 0xFFFF);
        gGameWork.stepCounter++;
    } else
        gGameSubState++;
}

void afterbattle_start_medal_transform(void) {
    vu32 zero;

    clear_battle_sprite_slot(0, 0x80);
    clear_bg_scroll();
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG1CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG2CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG3CNT, 0);
    set_blend_effect_mode(5, 0x3F, 0x20);
    gVBlankCallback = empty_callback;
    zero = 0;
    DmaSet(3, &zero, 0x05000200, 0x85000080);
    zero = 0;
    DmaSet(3, &zero, 0x05000000, 0x85000080);
    gGameWork.levelUpMedalSlot = find_medal_slot_by_id(gBattleWork.memberResults[gBattleWork.resultsMember][0] - 1) - 1;
    gGameWork.transformOldMedal = gBattleWork.memberResults[gBattleWork.resultsMember][2];
    gGameWork.transformOldVariant = gBattleWork.memberResults[gBattleWork.resultsMember][3];
    gGameWork.transformNewMedal = gBattleWork.memberResults[gBattleWork.resultsMember][4];
    gGameWork.transformNewVariant = gBattleWork.memberResults[gBattleWork.resultsMember][5];
    start_medal_transform(gGameWork.levelUpMedalSlot);
    gBattleWork.resultsMember++;
}

void afterbattle_transform_advance(void) {
    if (gBattleWork.resultsMember == 3) {
        gBattleWork.resultsMember = 0;
        gGameSubState = 0x5B;
    } else if (gBattleWork.memberResults[gBattleWork.resultsMember][1])
        gGameSubState = 0x4E;
    else
        gBattleWork.resultsMember++;
}

void afterbattle_stop_music(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    fade_out_music(8);
    gGameSubState++;
}

void afterbattle_resume_field(void) {
    play_song(1);
    clear_battle_sprite_slot(0, 0x80);
    clear_bg_scroll();
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG1CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG2CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG3CNT, 0);
    gFieldWork.fixed_battle = 0;
    gFieldWork.battle_flags = 0;
    gFieldWork.story_battle = 0;
    gVBlankCallback = empty_callback;
    field_resume(0);
}

// Sub-states 0x60-0x67: START on "Medapart was acquired" opens the won part's Medaparts detail page
// (0x62 saves BG tiles and sprites, 0x63 enters game state 5, 0x65 restores the screen on return).
void afterbattle_part_detail_init_fade(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    afterbattle_pulse_new_sprite();
    palette_backup_from_hardware();
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void afterbattle_part_detail_fade_out(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    afterbattle_pulse_new_sprite();
    if (gGameWork.stepCounter <= 8) {
        bg_palettes_blend_masked_now(0, gGameWork.stepCounter * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, gGameWork.stepCounter * 4, 0xFFFF);
        gGameWork.stepCounter++;
    } else
        gGameSubState++;
}

void afterbattle_part_detail_save_screen(void) {
    DmaSet(3, 0x06002800, gBgTileBackup, 0x84000200);
    DmaSet(3, 0x06000280, 0x02021000, 0x84000380);
    DmaSet(3, gSpriteEntries, 0x02028000, 0x84000800);
    set_blend_effect_mode(5, 0x3F, 0x20);
    gVBlankCallback = empty_callback;
    gGameSubState++;
}

// Guess: START on "Medapart was acquired": open the Medaparts detail page (game state 5 sub 0x10) of the
// won part (gBattleWork.wonPartKind = part kind, wonPartId = part id).
void afterbattle_part_detail_open_screen(void) {
    struct GameWork *game;
    struct BattleWork *battle;
    u8 kind;

    clear_bg_scroll();
    clear_battle_sprite_slot(0, 0x80);
    game = &gGameWork;
    game->noAffineSprites = 0;
    gVBlankOamMode = 0;
    battle = &gBattleWork;
    kind = battle->wonPartKind;
    switch (kind) {
    case 0:
        mem_fill8(&game->openedFrom, 0x14, 0);
        game->openedFrom = 2;
        game->shownId = battle->wonPartId;
        game->partSlot = kind;
        gGameState = 5;
        gGameSubState = 0x10;
        break;
    case 1:
        mem_fill8(&game->openedFrom, 0x14, 0);
        game->openedFrom = 2;
        game->shownId = battle->wonPartId;
        game->partSlot = kind;
        gGameState = 5;
        gGameSubState = 0x10;
        break;
    case 2:
        mem_fill8(&game->openedFrom, 0x14, 0);
        game->openedFrom = 2;
        game->shownId = battle->wonPartId;
        game->partSlot = kind;
        gGameState = 5;
        gGameSubState = 0x10;
        break;
    case 3:
        mem_fill8(&game->openedFrom, 0x14, 0);
        game->openedFrom = 2;
        game->shownId = battle->wonPartId;
        game->partSlot = kind;
        gGameState = 5;
        gGameSubState = 0x10;
        break;
    }
}

void afterbattle_part_detail_restore_screen(void) {
    const u32 *tbl;
    u32 zero;

    clear_bg_scroll();
    REG_DISPCNT &= 0xE0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x590A;
    REG_BG3CNT = 0x5B0B;
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG1CNT, 0);
    lz_decompress_dispatch(gPrebattleBgTiles, (void *)0x06004000);
    lz_decompress_dispatch(gLegTypePedestalTiles, (void *)0x06006000);
    lz_decompress_dispatch(gLegTypePedestalTiles2, (void *)0x06006200);
    lz_decompress_dispatch(gPrebattleObjTiles, (void *)0x06012800);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
    set_tilemap_and_decompress_bg(0, 0, gPrebattleBg1Tilemap, REG_BG1CNT, 0x200);
    DmaSet(3, gPrebattleBgPalette, 0x0202FA00, 0x84000070);
    DmaSet(3, gLegTypePedestalPalette, 0x0202FB00, 0x84000008);
    DmaSet(3, gLegTypePedestalPalette2, 0x0202FB20, 0x84000008);
    DmaSet(3, gMenuObjPalettes, 0x0202F800, 0x84000040);
    DmaSet(3, gGradientPaletteYellow + 0xB0, 0x0202F980, 0x84000008);
    DmaSet(3, gGradientPaletteYellow, 0x0202F9A0, 0x84000008);
    DmaSet(3, gPrebattleObjPalette, 0x0202F940, 0x84000008);
    DmaSet(3, gPartIconSpritePalette, 0x0202F960, 0x84000008);
    decompress_tileset_to_vram(gBattleWork.battlefield, 1);
    lz_decompress_dispatch(gNewPartSpriteTiles, (void *)0x06012400);
    DmaSet(3, gResultSpritePalettes, 0x0202F940, 0x84000008);
    lz_decompress_dispatch(gPartIconSpriteTiles, (void *)0x06016C00);
    DmaSet(3, gPartIconSpritePalette, 0x0202F960, 0x84000008);
    zero = 0;
    DmaSet(3, &zero, gSpriteEntries, 0x85000800);
    DmaSet(3, gBgTileBackup, 0x06002800, 0x84000200);
    DmaSet(3, 0x02021000, 0x06000280, 0x84000380);
    DmaSet(3, 0x02028000, gSpriteEntries, 0x84000800);
    REG_DISPCNT |= 0x1F60;
    prebattle_draw_opponent_name();
    prebattle_draw_battlefield_name();
    load_opponent_medabot_sprites();
    init_opponent_medabot_sprites();
    draw_opponent_leg_type_icons();
    prebattle_init_rubberobo_sprite();
    battlefield_load_params();
    apply_battle_blend_effect_a();
    setup_battle_result_sprite_animation();
    memcpy_bytes_0803F63C(gPartKindNames[gBattleWork.wonPartKind], gGameWork.textBuf, 14);
    tbl = gMedapartNames[0];
    memcpy_bytes_0803F63C((const void *)tbl[gBattleWork.wonPartId * 4 + gBattleWork.wonPartKind],
                          gGameWork.textBuf + 20, 15);
    gGameWork.stepCounter = 0;
    gGameSubState++;
}

void afterbattle_part_detail_fade_in(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    afterbattle_pulse_new_sprite();
    if (gGameWork.stepCounter <= 8) {
        bg_palettes_blend_masked_now(0, 32 - gGameWork.stepCounter * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, 32 - gGameWork.stepCounter * 4, 0xFFFF);
        gGameWork.stepCounter++;
    } else
        gGameSubState++;
}

void afterbattle_part_detail_return(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    afterbattle_pulse_new_sprite();
    gGameSubState = 0x3D;
}

// Sub-states 0x70+: lost Robattle ("You lost the Robattle").
void afterbattle_show_lost_message(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gBattleMessages[110])) {
        gGameWork.endModeStep = 0;
        gGameSubState++;
    }
}

// 0x71, after the loss message: a map-script battle (story_battle set) just fades out (0x72); a random battle goes on
// to 0x77, where a Medapart is taken.
void afterbattle_lost_check_story_battle(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (game_state_execute_handler_b()) {
        if (gFieldWork.story_battle)
            gGameSubState++;
        else
            gGameSubState = 0x77;
    }
}

void afterbattle_fade_to_white(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gGameWork.stepCounter <= 8) {
        bg_palettes_blend_masked_now(0x7FFF, gGameWork.stepCounter * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0x7FFF, gGameWork.stepCounter * 4, 0xFFFF);
        gGameWork.stepCounter++;
    } else
        gGameSubState++;
}

void afterbattle_exit_to_field(void) {
    clear_battle_sprite_slot(0, 0x80);
    clear_bg_scroll();
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG1CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG2CNT, 0);
    vram_fill_tilemap_rect(32, 32, 0, 0, REG_BG3CNT, 0);
    gFieldWork.fixed_battle = 0;
    gFieldWork.battle_flags = 0;
    gFieldWork.story_battle = 0;
    gVBlankCallback = empty_callback;
    set_blend_effect_mode(3, 0x3F, 0x20);
    gGameMode = 2;
    gGameState = 8;
    gGameSubState = 0;
}

// 0x77: picks one of the player's parts (battle_pick_random_bot_part(0): slots 0-2) and removes it
// (team_lose_equipped_part).
void battle_loss_take_part(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (gFieldWork.battle_flags & 0xF) {
        gFieldWork.battle_flags = 0;
        gGameSubState = 0x40;
    } else {
        battle_pick_random_bot_part(0);
        team_lose_equipped_part(gBattleBots[gBattleWork.lossBot].teamSlot, gBattleWork.wonPartKind);
        message_next();
        gGameSubState++;
    }
}

void battle_loss_show_part_taken(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    setup_battle_result_sprite();
    if (run_message(gBattleMessages[108]) && (KEYS_LO(gNewKeys) & 3)) {
        gVBlankOamMode = 0;
        play_sound_effect(13);
        gGameSubState++;
    }
}

// guess: count_assembled_medabots() nonzero = a Medabot is still assembled
void battle_loss_check_team(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (count_assembled_medabots())
        gGameSubState = 0x40;
    else {
        message_next();
        gGameSubState++;
    }
}

void battle_loss_show_no_medabots(void) {
    update_all_battle_sprite_orbits();
    update_scroll_movement_a();
    if (run_message(gBattleMessages[111]))
        gGameSubState = 0x72;
}

static void load_encounter_into_battle_setup(void) {
    u32 zero = 0;

    DmaSet(3, &zero, &gBattleWork, 0x85000100);
    load_area_battlefield();
    setup_random_encounter_enemies();
}

void load_area_battlefield(void) {
    memcpy_bytes_08041D04(gAreaBattleSettings[gFieldWork.area_id], &gGameWork.partAbility, 2);
    gBattleWork.battlefield = (&gGameWork.partAbility)[1];
}

// Picks the encounter (area table unless a debug battle set battle_id), copies its setup and re-rolls
// each opponent part with random_pick_weighted4 unless the setup has fixed parts (fixedParts).
void setup_random_encounter_enemies(void) {
    struct FieldWork *st;
    u8 flag;
    u32 roll;
    u8 id;
    u32 i;
    u8 head_id, rarm_id, larm_id, legs_id;

    flag = gFieldWork.fixed_battle;
    st = &gFieldWork;
    if (!flag) {
        memcpy_bytes_08041D04(gAreaRandomEncounters[st->area_id], &gGameWork.partAbility, 4);
        roll = rng_percent();
        if (roll < 40)
            id = (&gGameWork.partAbility)[0];
        else if (roll < 70)
            id = (&gGameWork.partAbility)[1];
        else if (roll < 90)
            id = (&gGameWork.partAbility)[2];
        else
            id = (&gGameWork.partAbility)[3];
        st->battle_id = id;
    }
    memcpy_bytes_08041D04(gEncounterSetups[st->battle_id], &gBattleWork, 0x28);
    if (!gBattleWork.fixedParts) {
        for (i = 0; i < 3; i++) {
            head_id =
                random_pick_weighted4(gBattleWork.encounterBots[i].parts[0], gBattleWork.encounterBots[i].parts[1],
                                      gBattleWork.encounterBots[i].parts[2], gBattleWork.encounterBots[i].parts[3]);
            rarm_id =
                random_pick_weighted4(gBattleWork.encounterBots[i].parts[0], gBattleWork.encounterBots[i].parts[1],
                                      gBattleWork.encounterBots[i].parts[2], gBattleWork.encounterBots[i].parts[3]);
            larm_id =
                random_pick_weighted4(gBattleWork.encounterBots[i].parts[0], gBattleWork.encounterBots[i].parts[1],
                                      gBattleWork.encounterBots[i].parts[2], gBattleWork.encounterBots[i].parts[3]);
            legs_id =
                random_pick_weighted4(gBattleWork.encounterBots[i].parts[0], gBattleWork.encounterBots[i].parts[1],
                                      gBattleWork.encounterBots[i].parts[2], gBattleWork.encounterBots[i].parts[3]);
            gBattleWork.encounterBots[i].parts[0] = head_id;
            gBattleWork.encounterBots[i].parts[1] = rarm_id;
            gBattleWork.encounterBots[i].parts[2] = larm_id;
            gBattleWork.encounterBots[i].parts[3] = legs_id;
        }
    }
}

// Returns a, b, c or d with 40/30/20/10% probability.
u32 random_pick_weighted4(u32 common, u32 uncommon, u32 rare, u32 very_rare) {
    u32 roll = rng_percent();

    if (roll < 40)
        return common;
    if (roll < 70)
        return uncommon;
    if (roll < 90)
        return rare;
    return very_rare;
}

static void prebattle_draw_opponent_name(void) {
    memcpy_bytes_0803F63C(gOpponentNames[gBattleWork.encounterMessage], gGameWork.textBuf, 18);
    render_text_sprites_08040EE4(gGameWork.textBuf, 10, 18, 3, 10, 13, 0, 1, 0, -4);
}

static void prebattle_draw_battlefield_name(void) {
    memcpy_bytes_0803F63C(gBattlefieldNames[gBattleWork.battlefield], gGameWork.textBuf, 11);
    render_text_sprites_08040DB8(gGameWork.textBuf, 30, 1, 3, 8, 12, 0, 1);
}

static void load_opponent_medabot_sprites(void) {
    u32 i;

    for (i = 0; i < gBattleWork.opponentCount; i++)
        decompress_sprite_to_vram_08042D94(gBattleWork.encounterBots[i].parts[0], gBattleWork.encounterBots[i].parts[1],
                                           gBattleWork.encounterBots[i].parts[2], gBattleWork.encounterBots[i].parts[3],
                                           i);
}

void init_opponent_medabot_sprites(void) {
    u32 i;

    for (i = 0; i < gBattleWork.opponentCount; i++) {
        init_battle_medabot_sprites(gBattleWork.encounterBots[i].parts[0], gBattleWork.encounterBots[i].parts[1],
                                    gBattleWork.encounterBots[i].parts[2], gBattleWork.encounterBots[i].parts[3], i,
                                    40 + i * 4, gOpponentSpritePositions[i][0], gOpponentSpritePositions[i][1], 1, 1,
                                    0);
        battle_sprite_group_set_anim(40 + i * 4, 8);
    }
}

static void update_all_battle_sprite_orbits(void) {
    u32 i;

    for (i = 0; i < gBattleWork.opponentCount; i++)
        update_battle_sprite_orbiting_positions(40 + i * 4, i, 1);
}

void draw_opponent_leg_type_icons(void) {
    u32 i;

    for (i = 0; i < 3; i++) {
        if (gBattleWork.opponentCount > i) {
            load_part_data(gBattleWork.encounterBots[i].parts[3], 3, &gGameWork.partAbility);
            draw_tilemap_with_offset((&gGameWork.partAbility)[1] - 100, gOpponentLegIconPositions[i][0],
                                     gOpponentLegIconPositions[i][1], REG_BG0CNT, 0x8300);
        } else
            draw_tilemap_with_offset(0xFF, gOpponentLegIconPositions[i][0], gOpponentLegIconPositions[i][1], REG_BG0CNT,
                                     0x8300);
    }
}

// Shows sprite 0 when the player owns a Rubberobo Medal (item 50) outside debug battles.
static void prebattle_init_rubberobo_sprite(void) {
    if (!gGameWork.battleOver && get_item_quantity_by_id(50) && !gFieldWork.fixed_battle) {
        gSpriteEntries[0].flags =
            SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
        gSpriteEntries[0].x = 8;
        gSpriteEntries[0].y = 0x50;
        gSpriteEntries[0].palette = 11;
        gSpriteEntries[0].order = 0xC0;
        gSpriteEntries[0].frame = 0x700;
    }
}

// guess: copies the battlefield's 8 parameter bytes (gBattlefieldParams[battlefield]) into
// gBattleWork.battlefieldParams.
void battlefield_load_params(void) {
    memcpy_bytes_0803F63C(gBattlefieldParams[gBattleWork.battlefield], gBattleWork.battlefieldParams, 8);
}

// Chooses the won Medapart (wonPartKind kind, wonPartId id): afterbattle_broken_part_chance (10 per broken opponent
// part) against a 0-100 roll, then afterbattle_pick_unowned_part (a part the player doesn't own yet), else any opponent
// part (battle_pick_random_bot_part(3)).
static void afterbattle_choose_won_part(void) {
    s32 n = afterbattle_broken_part_chance();

    if (n < rng_percent() || !afterbattle_pick_unowned_part())
        battle_pick_random_bot_part(3);
}

// Chance (percent) of winning a part the player doesn't own: 10 per broken (armor 0) arm / legs part of the
// present opponents (records 3-5).
static s32 afterbattle_broken_part_chance(void) {
    s32 sum = 0;
    u32 i = 0, j, k;
    struct BattleBot *base = gBattleBots;
    u8 *armor = &base->parts[0].armor;
    u8 *part_armor;

loop:
    k = (i + 3) << 8;
    if (!*(&base->present + k))
        goto end;
    j = 1;
    i++;
    part_armor = (u8 *)(k + (u32)armor) + 0x18;
inner:
    if (!*part_armor)
        sum += 10;
    part_armor += 0x18;
    j++;
    if (j <= 3)
        goto inner;
    if (i <= 2)
        goto loop;
end:
    return sum;
}

// Looks for an opponent part the player owns none of, from a random opponent and kind; 1 and sets wonPartKind /
// wonPartId when found.
u32 afterbattle_pick_unowned_part(void) {
    u32 slot, n, j, part, k;
    u8 *part_id;
    struct BattleBot *bb;

    slot = gRandomBotSlotStarts[rng_next_byte() & 0xF];
    for (n = 0; n < 3; n++) {
        register struct BattleBot *base asm("r5") = gBattleBots;
        if (base[k = slot + 3].present) {
            part = rng_next_byte() & 3;
            for (j = 0, bb = base; j < 4; j++) {
                part_id = (u8 *)(part * 24 + ((slot + 3) << 8) + (u32)bb) + 0x5F;
                if (!medapart_get_counts(*part_id, part)) {
                    gBattleWork.wonPartKind = part;
                    gBattleWork.wonPartId = *part_id;
                    return 1;
                }
                part = (part + 1) & 3;
            }
        }
        if (slot == 2)
            slot = 0;
        else
            slot++;
    }
    return 0;
}

// Picks a random part of a present Medabot of one side (first = 0 player, 3 opponents): wonPartKind kind, wonPartId id,
// lossBot the Medabot record.
void battle_pick_random_bot_part(u32 first) {
    u32 slot, dir, i, k;

    slot = gRandomBotSlotStarts[rng_next_byte() & 0xF];
    dir = rng_next_byte() & 1;
    for (i = 0; i < 3; i++) {
        k = first + slot;
        if (gBattleBots[k].present) {
            gBattleWork.wonPartKind = rng_next_byte() & 3;
            gBattleWork.wonPartId = gBattleBots[k].parts[gBattleWork.wonPartKind].partId;
            gBattleWork.lossBot = k;
            return;
        }
        if (dir) {
            if (++slot > 2)
                slot = 0;
        } else {
            if (slot == 0)
                slot = 2;
            else
                slot--;
        }
    }
}

static void setup_battle_result_sprite(void) {
    switch (gBattleWork.wonPartKind) {
    case 0:
        setup_sprite_animation_entry(0, gBattleWork.wonPartId, 0, 0xC2, 0x50, 1, 8, 0, 1);
        break;
    case 1:
        setup_sprite_animation_entry(0, gBattleWork.wonPartId, 1, 0xCC, 0x38, 1, 7, 0, 1);
        break;
    case 2:
        setup_sprite_animation_entry(0, gBattleWork.wonPartId, 2, 0xB8, 0x38, 1, 6, 1, 1);
        break;
    case 3:
        setup_sprite_animation_entry(0, gBattleWork.wonPartId, 3, 0xC2, 0x2E, 1, 5, 0, 1);
        break;
    }
}

// Pulses the "NEW" sprite (sprite 1, scale_y between 0x40 and 0x80) while the won part is a new one.
static void afterbattle_pulse_new_sprite(void) {
    if (gBattleWork.wonPartNew) {
        if (!gSpriteEntries[1].work[NEW_SPR_SHRINK]) {
            if ((u8)(gSpriteEntries[1].scale_y += 2) == 0x80)
                gSpriteEntries[1].work[NEW_SPR_SHRINK] = 1;
        } else {
            if ((u8)(gSpriteEntries[1].scale_y -= 2) == 0x40)
                gSpriteEntries[1].work[NEW_SPR_SHRINK] = 0;
        }
    }
}

static void setup_battle_result_sprite_animation(void) {
    init_scene_buffers_080445F4();
    switch (gBattleWork.wonPartKind) {
    case 0:
        setup_sprite_animation_entry(0, gBattleWork.wonPartId, 0, 0xC2, 0x3C, 1, 8, 0, 0);
        break;
    case 1:
        setup_sprite_animation_entry(0, gBattleWork.wonPartId, 1, 0xCC, 0x28, 1, 7, 0, 0);
        break;
    case 2:
        setup_sprite_animation_entry(0, gBattleWork.wonPartId, 2, 0xB8, 0x28, 1, 6, 1, 0);
        break;
    case 3:
        setup_sprite_animation_entry(0, gBattleWork.wonPartId, 3, 0xC2, 0x1E, 1, 5, 0, 0);
        break;
    }
}

// Experience points for the won Robattle (gBattleWork.score), from the opponents' Medal levels,
// their count, the level gap to the team, their parts (guess: broken ones), timeTicks and armor.
void calculate_battle_score_summary(void) {
    gBattleWork.score = 0;
    calc_average_bot_stat_080125B4();
    accumulate_alive_bot_score();
    calc_average_bot_stat_0801264C();
    calc_medaforce_gauge_from_damage();
    battle_score_add_time_bonus();
    accumulate_team_armor_stats();
}

static void calc_average_bot_stat_080125B4(void) {
    u32 sum = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleBots[i + 3].present)
            sum += gBattleBots[i + 3].medal.level;
    }
    gBattleWork.score += sum / 3;
}

static void accumulate_alive_bot_score(void) {
    u32 n = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gBattleBots[i + 3].present)
            n++;
    }
    gBattleWork.score += n * 8;
}

static void calc_average_bot_stat_0801264C(void) {
    u32 opp = 0;
    u32 team = 0;
    u32 i;
    u32 nopp;
    u32 nteam;

    for (i = 0, nopp = 0; i <= 2; i++) {
        if (gBattleBots[i + 3].present) {
            opp += gBattleBots[i + 3].medal.level;
            nopp++;
        }
    }
    opp = opp / nopp;
    for (i = 0, nteam = 0; i <= 2; i++) {
        if (gBattleBots[i].present) {
            team += gBattleBots[i].medal.level;
            nteam++;
        }
    }
    team = team / nteam;
    if (team < opp)
        gBattleWork.score += (opp - team) * (nopp << 4);
}

static void calc_medaforce_gauge_from_damage(void) {
    u32 i;
    u32 score;

    for (i = 0, score = 0; i <= 2; i++) {
        if (gBattleBots[i + 3].present) {
            if (!gBattleBots[i + 3].parts[0].armor)
                score += 8;
            if (!gBattleBots[i + 3].parts[1].armor)
                score += 16;
            if (!gBattleBots[i + 3].parts[2].armor)
                score += 16;
            if (!gBattleBots[i + 3].parts[3].armor)
                score += 16;
        }
    }
    gBattleWork.score += score * 2;
}

// 5 experience points per Robattle TIME tick.
static void battle_score_add_time_bonus(void) {
    gBattleWork.score += gBattleWork.timeTicks * 5;
}

void accumulate_team_armor_stats(void) {
    u32 i;
    u32 sum;

    for (i = 0, sum = 0; i <= 2; i++) {
        if (gBattleBots[i + 3].present) {
            sum += gBattleBots[i + 3].parts[0].data[0xA];
            sum += gBattleBots[i + 3].parts[1].data[0xA];
            sum += gBattleBots[i + 3].parts[2].data[0xA];
            sum += gBattleBots[i + 3].parts[3].data[0xA];
        }
    }
    gBattleWork.score += sum;
}

static void battle_check_medal_level_up(void) {
    u32 i;
    struct MedalData *medal;
    u32 tier;
    u32 slot;

    mem_fill8(&gBattleWork.memberResults[0][0], 0x18, 0);
    for (i = 0; i <= 2; i++) {
        if (!gBattleBots[i].present)
            continue;
        slot = find_medal_slot_by_id(gBattleBots[i].medal.graphicId) - 1;
        {
            struct MedalData *medals = gMedals;
            medal = &medals[slot];
        }
        if (medal->level == 100)
            continue;
        if (medal->nextLevelExp > gBattleWork.score) {
            medal->nextLevelExp -= gBattleWork.score;
            continue;
        }
        medal->level++;
        medal->nextLevelExp = (medal->level + 1) * 100;
        gBattleWork.memberResults[i][0] = medal->graphicId + 1;
        memcpy_bytes_08041D04(gMedalRecords[medal->graphicId], &gGameWork.partAbility, 16);
        tier = medal_tier_for_level(medal->level, (&gGameWork.partAbility)[3], (&gGameWork.partAbility)[4],
                                    (&gGameWork.partAbility)[5], (&gGameWork.partAbility)[6]);
        if (tier != medal->spriteVariant) {
            gBattleWork.memberResults[i][1] = 1;
            gBattleWork.memberResults[i][2] = medal->graphicId;
            gBattleWork.memberResults[i][3] = medal->spriteVariant;
            gBattleWork.memberResults[i][4] = medal->graphicId;
            gBattleWork.memberResults[i][5] = tier;
            medal->spriteVariant = tier;
        }
        memcpy_bytes_08041D04(&gMedalMedaforceIds[medal->graphicId * 3], &gGameWork.partAbility, 3);
        if (medal->level == 10) {
            gBattleWork.memberResults[i][6] = 1;
            gBattleWork.memberResults[i][7] = (&gGameWork.partAbility)[0];
        }
        if (medal->level == 30) {
            gBattleWork.memberResults[i][6] = 1;
            gBattleWork.memberResults[i][7] = (&gGameWork.partAbility)[1];
        }
        if (medal->level == 60) {
            gBattleWork.memberResults[i][6] = 1;
            gBattleWork.memberResults[i][7] = (&gGameWork.partAbility)[2];
        }
    }
}
