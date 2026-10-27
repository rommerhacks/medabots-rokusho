// Link Robattle (game state 10, guess: entered when gGameWork.skipBotSetup == 1). link_robattle_update runs
// gLinkRobattleHandlers[gGameSubState]. Sub-states (messages from gLinkMessages / decoded text):
//   0x00-0x06  handshake: sync, player 0 sends the RNG seed (gGameWork.rngIndex), 0x50-0x54 swap player names
//              (link_robattle_exchange_names), pick a random battlefield
//   0x07-0x0E  intro screen "Okay let's Robattle!", fade out, gGameState = 3 (the Robattle)
//   0x10-0x18  link error: "A link error has occurred", soft reset to the title
//   0x20-0x2D  after the battle: "That was a great Robattle!", "Checking connection", then the prize game if
//              gGameWork.prizeGamePending is set, else back to the link menu
//   0x30-0x4B  prize game: the winner (gGameWork.unk9C == 1) stops a power gauge with A ("Get Medaparts by
//              pressing A Button with a good timing"); a ball flies up and lands on one of 6 rows
//              (prizeSlots); a part row moves that part from the loser to the winner ("You got / lost the
//              Medapart"), a miss row gives nothing ("Sorry! You missed!" / "Lucky! You didn't lose any").
// Also link_error_check (called by the battle and menu states) and soft_reset_to_title. Not runnable in the
// single-GBA harness: names come from the code and the decoded messages.

#include "global.h"

static void link_robattle_draw_partner_name(void);
static void link_robattle_draw_battlefield_name(void);
static void link_robattle_draw_frame(void);
static void link_robattle_load_battlefield_info(void);
static void prize_game_scroll_bg3(void);
static void prize_game_draw_slots(void);
static void prize_game_init_ball(void);
static void prize_game_init_launcher(void);
static void prize_game_init_row_marker(void);
static void prize_game_gauge_step(void);
static void prize_game_draw_gauge(void);
static void prize_game_blink_gauge(void);
static void prize_game_set_peak(void);
static void prize_game_set_landing_row(void);
static void prize_game_launch_ball(void);
static u32 prize_game_ball_rise(void);
static void prize_game_full_power_sfx(void);
static void prize_game_ball_start_fall(void);
static u32 prize_game_ball_fall(void);
static void prize_game_blink_landing_slot(void);

// Game state 10 handler: runs gLinkRobattleHandlers[gGameSubState]; outside sub-states 0x10-0x1F a link error
// (link_error_check) restarts it at 0x10. guess: link Robattle (entered when gGameWork.skipBotSetup == 1).
void link_robattle_update(void) {
    if (gGameSubState - 0x10 > 0xF && link_error_check())
        return;
    if (gVBlankOamMode == 2) {
        u32 fill = 0x200;
        CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
    }
    link_clear_send_word();
    gLinkRobattleHandlers[gGameSubState]();
}

void link_robattle_init(void) {
    u32 zero = 0;

    CpuFastSet(&zero, &gBattleWork, 0x01000100);
    gGameWork.unk86 = 0;
    gGameWork.unk84 = 0;
    gGameSubState++;
}

void link_robattle_wait_sync(void) {
    if (link_sync_both_ready()) {
        gGameWork.unk86 = 0;
        gGameSubState++;
    }
}

void link_robattle_delay(void) {
    if (gGameWork.unk86 == 8) {
        gGameWork.unk86 = 0;
        gGameSubState++;
    } else {
        gGameWork.unk86++;
    }
}

void link_robattle_send_seed(void) {
    if (gUnk_03000B90 == 0) {
        gGameWork.rngIndex = gFrameCounter;
        gUnk_03005010.unk6 = gGameWork.rngIndex + 0x8000;
    }
    gGameSubState++;
}

void link_robattle_receive_seed(void) {
    if (gUnk_03000B90 != 0) {
        u16 seed = gUnk_03005010.unk8[0][1];
        if (!(seed & 0x8000))
            return;
        gGameWork.rngIndex = seed;
    }
    gGameSubState++;
}

void link_robattle_start_name_exchange(void) {
    gGameWork.unk84 = 0;
    gBattleWork.unk51 = 0;
    gBattleWork.unk52 = 0;
    gBattleWork.unk53 = 0;
    gBattleWork.unk54 = 0;
    gBattleWork.unk1A6 = 0;
    gBattleWork.unk1A8 = 0;
    gBattleWork.unk1AA = 0;
    gBattleWork.unk1AC = 0;
    gBattleWork.unk1AF = 0;
    gBattleWork.unk1B0 = 1;
    gGameWork.unk86 = 0;
    gGameSubState = 0x50;
}

void link_robattle_pick_battlefield(void) {
    gBattleWork.battlefield = gLinkBattlefields[rng_next_byte() & 0x1F];
    gGameSubState++;
}

void link_robattle_screen_load(void) {
    u32 zero_obj_pal, zero_bg_pal, zero_sprites;

    clear_bg_scroll();
    zero_obj_pal = 0;
    CpuFastSet(&zero_obj_pal, (void *)OBJ_PLTT, 0x01000080);
    zero_bg_pal = 0;
    CpuFastSet(&zero_bg_pal, (void *)PLTT, 0x01000080);
    REG_DISPCNT &= 0xE0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x590A;
    REG_BG3CNT = 0x5B0B;
    lz_decompress_dispatch(gUnk_084E6C9C, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C48B4, (void *)0x06006000);
    lz_decompress_dispatch(gUnk_084C4A34, (void *)0x06006200);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG1CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EFA34, REG_BG1CNT, 0x200);
    CpuFastSet(gUnk_084F29E0, (void *)0x0202FA00, 0x70);
    CpuFastSet(gUnk_084C69D8, (void *)0x0202FB00, 8);
    CpuFastSet(gUnk_084C69F8, (void *)0x0202FB20, 8);
    CpuFastSet(gUnk_0850DEF8, (void *)0x0202F800, 0x40);
    CpuFastSet(gUnk_0850DCF8 + 0xB0, (void *)0x0202F980, 8);
    CpuFastSet(gUnk_0850DCF8, (void *)0x0202F9A0, 8);
    decompress_tileset_to_vram(gBattleWork.battlefield, 1);
    zero_sprites = 0;
    CpuFastSet(&zero_sprites, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    link_robattle_draw_partner_name();
    link_robattle_draw_battlefield_name();
    link_robattle_draw_frame();
    link_robattle_load_battlefield_info();
    apply_battle_blend_effect_a();
    play_song(8);
    gGameWork.unk84 = 0;
    gGameSubState++;
}

void link_robattle_fade_in(void) {
    update_scroll_movement_a();
    if (gGameWork.unk84 <= 8) {
        bg_palettes_blend_masked_now(0, 0x20 - gGameWork.unk84 * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, 0x20 - gGameWork.unk84 * 4, 0xFFFF);
        gGameWork.unk84++;
    } else
        gGameSubState++;
}

void link_robattle_open_text_window(void) {
    update_scroll_movement_a();
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void link_robattle_intro_message(void) {
    update_scroll_movement_a();
    if (run_message(gUnk_083C2BBC[1]))
        gGameSubState++;
}

void link_robattle_backup_palettes(void) {
    update_scroll_movement_a();
    palette_backup_from_hardware();
    gGameWork.unk84 = 0;
    gGameSubState++;
}

void link_robattle_fade_out(void) {
    update_scroll_movement_a();
    if (gGameWork.unk84 <= 8) {
        bg_palettes_blend_masked_now(0, gGameWork.unk84 * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, gGameWork.unk84 * 4, 0xFFFF);
        gGameWork.unk84++;
    } else
        gGameSubState++;
}

void link_robattle_fade_out_dup(void) {
    update_scroll_movement_a();
    if (gGameWork.unk84 <= 8) {
        bg_palettes_blend_masked_now(0, gGameWork.unk84 * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, gGameWork.unk84 * 4, 0xFFFF);
        gGameWork.unk84++;
    } else
        gGameSubState++;
}

void link_robattle_clear_screen(void) {
    set_blend_effect_mode(0, 0, 0);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG1CNT, 0);
    clear_battle_sprite_slot(0, 0x80);
    gGameSubState++;
}

void link_robattle_start_battle(void) {
    mem_fill8(&gGameWork.medabotsMode, 0x14, 0);
    gGameWork.medabotsMode = 1;
    gGameState = 3;
    gGameSubState = 0;
}

void link_robattle_play_result_song(void) {
    if (gGameWork.unk9C == 1)
        play_song(14);
    else
        play_song(15);
    gGameSubState++;
}

void link_robattle_outro_message(void) {
    update_scroll_movement_a();
    if (run_message(gUnk_083C3984[1]) && (*(u8 *)&gNewKeys & 3)) {
        gGameWork.endModeStep = 0;
        play_sound_effect(0xD);
        gGameSubState++;
    }
}

void link_robattle_outro_close_message(void) {
    update_scroll_movement_a();
    if (game_state_execute_handler_b()) {
        message_next();
        gGameSubState++;
    }
}

void link_robattle_checking_connection(void) {
    update_scroll_movement_a();
    if (run_message(gLinkMessages[1]))
        gGameSubState++;
}

void link_robattle_outro_wait_sync(void) {
    update_scroll_movement_a();
    if (link_sync_both_ready()) {
        gGameWork.unk86 = 0;
        gGameSubState++;
    }
}

void link_robattle_outro_delay(void) {
    update_scroll_movement_a();
    if (gGameWork.unk86 == 8) {
        gGameWork.unk86 = 0;
        gGameSubState++;
    } else {
        gGameWork.unk86++;
    }
}

void link_robattle_fade_music(void) {
    update_scroll_movement_a();
    fade_out_music(8);
    gGameSubState++;
}

void link_robattle_check_prize_game(void) {
    update_scroll_movement_a();
    if (gGameWork.prizeGamePending == 0)
        gGameSubState++;
    else
        gGameSubState = 0x30;
}

void link_robattle_return_to_link_menu(void) {
    u32 zero_obj_pal, zero_bg_pal;

    clear_battle_sprite_slot(0, 0x80);
    clear_bg_scroll();
    zero_obj_pal = 0;
    CpuFastSet(&zero_obj_pal, (void *)(OBJ_PLTT), 0x01000080);
    zero_bg_pal = 0;
    CpuFastSet(&zero_bg_pal, (void *)PLTT, 0x01000080);
    set_blend_effect_mode(5, 0x3F, 0x20);
    goto_link_scene(3);
}

void prize_game_load(void) {
    u32 zero;

    clear_bg_scroll();
    set_blend_effect_mode(5, 0x3F, 0x20);
    REG_DISPCNT &= 0xE0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1B03;
    lz_decompress_dispatch(gUnk_084EDEF0, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C66B8, (void *)0x06007000);
    lz_decompress_dispatch(gUnk_084C68E0, (void *)0x06007A00);
    lz_decompress_dispatch(gSpriteFontTiles, (void *)0x06017400);
    lz_decompress_dispatch(gUnk_084E20F8, (void *)0x06010000);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF668, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0194, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0D9C, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F21E8, REG_BG3CNT, 0x200);
    CpuFastSet(gUnk_084F39A0, (void *)PLTT, 0x60);
    CpuFastSet(gUnk_0850EF58, (void *)OBJ_PLTT, 0x10);
    zero = 0;
    CpuFastSet(&zero, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    prize_game_pick_slots();
    prize_game_draw_slots();
    prize_game_init_ball();
    prize_game_init_launcher();
    prize_game_init_row_marker();
    gBattleWork.prizePower = 0;
    play_song(0x14);
    gGameSubState++;
}

void prize_game_fade_in(void) {
    prize_game_scroll_bg3();
    if (update_blend_effect())
        gGameSubState++;
}

void prize_game_open_text_window(void) {
    prize_game_scroll_bg3();
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void prize_game_intro_message(void) {
    prize_game_scroll_bg3();
    if (run_message(gGameWork.unk9C == 1 ? gLinkMessages[2] : gLinkMessages[3]))
        gGameSubState++;
}

void prize_game_gauge_input(void) {
    u16 pkt;

    prize_game_scroll_bg3();
    if (gGameWork.unk9C == 1) {
        prize_game_gauge_step();
        prize_game_draw_gauge();
        if (!(*(u8 *)&gNewKeys & 1))
            return;
        play_sound_effect(4);
        gUnk_03005010.unk6 = gBattleWork.prizePower + 0x8000;
        gGameWork.unk86 = 0;
        gGameSubState++;
    } else {
        pkt = gUnk_03005010.unk8[gUnk_03000B90 ^ 1][1];
        if (!(pkt & 0x8000))
            return;
        play_sound_effect(4);
        gBattleWork.prizePower = pkt;
        gGameWork.endModeStep = 0;
        gGameWork.unk86 = 0;
        gGameSubState++;
    }
}

void prize_game_gauge_blink(void) {
    u16 frames;

    prize_game_scroll_bg3();
    if (gGameWork.unk9C == 1) {
        gUnk_03005010.unk6 = gBattleWork.prizePower + 0x8000;
        prize_game_blink_gauge();
        frames = ++gGameWork.unk86;
    } else {
        prize_game_blink_gauge();
        gGameWork.unk86++;
        if (!game_state_execute_handler_a())
            return;
        frames = gGameWork.unk86;
    }
    if (frames == 0x3C) {
        play_sound_effect(0x39);
        prize_game_draw_gauge();
        gGameSubState++;
    }
}

void prize_game_launch(void) {
    prize_game_scroll_bg3();
    prize_game_set_peak();
    prize_game_set_landing_row();
    prize_game_launch_ball();
    gGameSubState++;
}

void prize_game_launch_anim(void) {
    prize_game_scroll_bg3();
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x75 - gBattleWork.prizeRow], 4);
    if (gSpriteEntries[4].unk22 == 0xFF) {
        gSpriteEntries[3].unk6 = 0x8505;
        play_sound_effect(0x54);
        gGameSubState++;
    }
}

void prize_game_ball_rise_step(void) {
    prize_game_scroll_bg3();
    if (prize_game_ball_rise()) {
        prize_game_full_power_sfx();
        prize_game_ball_start_fall();
        gGameSubState++;
    }
}

void prize_game_ball_fall_step(void) {
    prize_game_scroll_bg3();
    if (prize_game_ball_fall()) {
        play_sound_effect(0x2A);
        gGameWork.unk86 = 0;
        gGameSubState++;
    }
}

void prize_game_result_blink(void) {
    prize_game_scroll_bg3();
    prize_game_blink_landing_slot();
    if (gGameWork.unk86 == 0x78)
        gGameSubState++;
    else
        gGameWork.unk86++;
}

void prize_game_check_miss(void) {
    prize_game_scroll_bg3();
    prize_game_blink_landing_slot();
    gGameWork.unk86++;
    if (gBattleWork.prizeSlots[gBattleWork.prizeRow] == 4)
        gGameSubState++;
    else
        gGameSubState = 0x48;
}

void prize_game_reopen_text_window(void) {
    prize_game_scroll_bg3();
    prize_game_blink_landing_slot();
    gGameWork.unk86++;
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void prize_game_miss_message(void) {
    prize_game_scroll_bg3();
    prize_game_blink_landing_slot();
    gGameWork.unk86++;
    if (run_message(gGameWork.unk9C == 1 ? gLinkMessages[4] : gLinkMessages[5])) {
        text_window_init(1, 0, 0);
        gGameSubState++;
    }
}

void prize_game_checking_connection(void) {
    prize_game_scroll_bg3();
    prize_game_blink_landing_slot();
    gGameWork.unk86++;
    if (run_message(gLinkMessages[1]))
        gGameSubState++;
}

void prize_game_wait_sync(void) {
    prize_game_scroll_bg3();
    prize_game_blink_landing_slot();
    gGameWork.unk86++;
    if (link_sync_both_ready()) {
        gGameWork.unk84 = 0;
        gGameSubState++;
    }
}

void prize_game_delay(void) {
    prize_game_scroll_bg3();
    prize_game_blink_landing_slot();
    gGameWork.unk86++;
    if (gGameWork.unk84 == 4) {
        gGameWork.unk84 = 0;
        gGameSubState++;
    } else
        gGameWork.unk84++;
}

void prize_game_fade_music(void) {
    prize_game_scroll_bg3();
    prize_game_blink_landing_slot();
    gGameWork.unk86++;
    fade_out_music(8);
    gGameSubState++;
}

void prize_game_backup_palettes(void) {
    prize_game_scroll_bg3();
    prize_game_blink_landing_slot();
    gGameWork.unk86++;
    palette_backup_from_hardware();
    gGameWork.unk84 = 0;
    gGameSubState++;
}

void prize_game_fade_out(void) {
    prize_game_scroll_bg3();
    prize_game_blink_landing_slot();
    gGameWork.unk86++;
    if (gGameWork.unk84 <= 8) {
        bg_palettes_blend_masked_now(0, gGameWork.unk84 * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, gGameWork.unk84 * 4, 0xFFFF);
        gGameWork.unk84++;
    } else
        gGameSubState++;
}

void prize_game_transfer_part(void) {
    prize_game_scroll_bg3();
    prize_game_blink_landing_slot();
    gGameWork.unk86++;
    prize_game_pick_prize_part();
    if (gGameWork.unk9C == 1)
        medapart_add_quantity(gBattleWork.prizePart, (gBattleWork.prizeSlots + 0)[gBattleWork.prizeRow], 1);
    else
        team_lose_equipped_part(gBattleWork.prizeMedal, (gBattleWork.prizeSlots + 0)[gBattleWork.prizeRow]);
    memcpy_bytes_08041D04(
        (const void *)gUnk_083BB9CC[0][gBattleWork.prizePart * 4 + gBattleWork.prizeSlots[gBattleWork.prizeRow]],
        gGameWork.textBuf, 0xF);
    gGameSubState++;
}

void prize_game_part_message(void) {
    prize_game_scroll_bg3();
    prize_game_blink_landing_slot();
    gGameWork.unk86++;
    if (run_message(gGameWork.unk9C == 1 ? gLinkMessages[6] : gLinkMessages[7])) {
        text_window_init(1, 0, 0);
        gGameSubState++;
    }
}

void prize_game_goto_checking(void) {
    prize_game_scroll_bg3();
    prize_game_blink_landing_slot();
    gGameWork.unk86++;
    gGameSubState = 0x3E;
}

void link_error_fade_out(void) {
    fade_out_music(8);
    set_blend_effect_mode(6, 0x3F, 0x20);
    gGameSubState++;
}

void link_robattle_wait_blend(void) {
    if (update_blend_effect())
        gGameSubState++;
}

void link_error_screen_load(void) {
    u32 zero_pal, fill_tiles, zero_sprites;

    clear_bg_scroll();
    REG_DISPCNT &= 0xE0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1B03;
    zero_pal = 0;
    CpuFastSet(&zero_pal, (void *)(PLTT + 0x120), 0x01000008);
    fill_tiles = 0x11111111;
    CpuFastSet(&fill_tiles, (void *)0x06004120, 0x01000008);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG0CNT, 0x9209);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG1CNT, 0x9209);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG2CNT, 0x9209);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG3CNT, 0x9209);
    zero_sprites = 0;
    CpuFastSet(&zero_sprites, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    set_blend_effect_mode(5, 0x3F, 0x20);
    gGameSubState++;
}

void link_error_open_text_window(void) {
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void link_error_message(void) {
    if (run_message(gLinkMessages[12]))
        gGameSubState++;
}

static void link_error_fade_in(void) {
    set_blend_effect_mode(4, 0x3F, 0x20);
    gGameSubState++;
}

void link_error_reset(void) {
    soft_reset_to_title();
}

void link_robattle_exchange_names(void) {
    struct Unk_03005010 *link = &gUnk_03005010;
    u16 packet;
    s16 flag;
    link->unk6 = gPlayerRecord.name[gBattleWork.unk51] + (flag = ((gBattleWork.unk1AF << 8) & 0x100) + 0x8000);
    gGameWork.unk86++;
    if (!(gGameWork.unk86 & 1)) {
        gBattleWork.unk1AF ^= 1;
        gBattleWork.unk51++;
    }
    packet = link->unk8[gUnk_03000B90 ^ 1][1];
    if (packet & 0x8000) {
        if ((u16)(packet & 0x100) >> 8 != gBattleWork.unk1B0) {
            gBattleWork.unk1B0 ^= 1;
            gBattleWork.partnerName[gBattleWork.unk52] = packet;
            if (++gBattleWork.unk52 > 10) {
                gGameWork.unk86 = 0;
                gGameSubState++;
            }
        }
    }
}

void link_robattle_goto_battlefield(void) {
    gGameSubState = 6;
}

void link_robattle_goto_name_exchange(void) {
    gGameSubState = 5;
}

void link_clear_send_word(void) {
    if (gGameWork.skipBotSetup == 1)
        gUnk_03005010.unk6 = 0;
}

u32 link_sync_both_ready(void) {
    gUnk_03005010.unk6 = 0xFFFE;
    if (gUnk_03005010.unk8[0][1] == 0xFFFE && gUnk_03005010.unk8[1][1] == gUnk_03005010.unk8[0][1])
        return 1;
    return 0;
}

static void link_robattle_draw_partner_name(void) {
    render_text_sprites_08040EE4(gLinkPartnerName, 10, 0x12, 3, 10, 13, 0, 1, 0, -4);
}

static void link_robattle_draw_battlefield_name(void) {
    memcpy_bytes_0803F63C(gUnk_083BE9E8[gBattleWork.battlefield], gGameWork.textBuf, 0xB);
    render_text_sprites_08040DB8(gGameWork.textBuf, 0x1E, 1, 3, 8, 0xC, 0, 1);
}

static void link_robattle_draw_frame(void) {
    u32 i;
    for (i = 0; i <= 2; i++)
        draw_tilemap_with_offset(0xFF, gUnk_083ACEEA[i][0], gUnk_083ACEEA[i][1], REG_BG0CNT, 0x8300);
}

static void link_robattle_load_battlefield_info(void) {
    memcpy_bytes_0803F63C(gBattlefieldParams[gBattleWork.battlefield], gBattleWork.battlefieldParams, 8);
}

static void prize_game_scroll_bg3(void) {
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void prize_game_pick_slots(void) {
    u32 set = rng_next_byte() & 0xF;
    u32 i;
    for (i = 0; i <= 5; i++)
        gPrizeGameSlots[i] = gPrizeGameSlotSets[set][i];
}

static void prize_game_draw_slots(void) {
    u32 i;

    for (i = 0; i <= 5; i++) {
        u8 *slots = gPrizeGameSlots;
        draw_tile_block(7, 2, 4, i * 2 + 2, REG_BG1CNT, slots[i] * 14 + 0x3380);
    }
}

static void prize_game_init_ball(void) {
    clear_battle_sprite_slot(2, 1);
    gSpriteEntries[2].unk0 = 0xC400;
    gSpriteEntries[2].unk2 = 0x68;
    gSpriteEntries[2].unk4 = 0x78;
    gSpriteEntries[2].unk6 = 0x8506;
    gSpriteEntries[2].unk1C = 0;
    gSpriteEntries[2].unkB = 0x82;
}

static void prize_game_init_launcher(void) {
    clear_battle_sprite_slot(3, 1);
    gSpriteEntries[3].unk0 = 0xC400;
    gSpriteEntries[3].unk2 = 0x78;
    gSpriteEntries[3].unk4 = 0x7C;
    gSpriteEntries[3].unk6 = 0x8504;
    gSpriteEntries[3].unk1C = 0;
    gSpriteEntries[3].unkB = 0x81;
}

static void prize_game_init_row_marker(void) {
    clear_battle_sprite_slot(4, 1);
    gSpriteEntries[4].unk0 = 0xC400;
    gSpriteEntries[4].unk2 = 0x9A;
    gSpriteEntries[4].unk4 = 0x58;
    gSpriteEntries[4].unk1C = 0;
    gSpriteEntries[4].unkB = 0x80;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x70], 4);
}

static void prize_game_gauge_step(void) {
    if (gBattleWork.prizePower == 0x60)
        gBattleWork.prizePower = 0;
    else
        gBattleWork.prizePower += 4;
}

static void prize_game_draw_gauge(void) {
    u32 x = 0;
    u32 i, cnt;

    cnt = gBattleWork.prizePower >> 3;
    for (i = 0; i < cnt; i++) {
        draw_tile_block(1, 1, x + 7, 0x12, REG_BG1CNT, 0x53D8);
        x++;
    }
    cnt = gBattleWork.prizePower;
    cnt &= 7;
    if (cnt != 0) {
        draw_tile_block(1, 1, x + 7, 0x12, REG_BG1CNT, cnt | 0x53D0);
        x++;
    }
    for (i = x; i < 12; i++) {
        draw_tile_block(1, 1, x + 7, 0x12, REG_BG1CNT, 0x53D0);
        x++;
    }
}

static void prize_game_clear_gauge(void) {
    u32 i;
    for (i = 0; i <= 11; i++)
        draw_tile_block(1, 1, i + 7, 0x12, REG_BG1CNT, 0x53D0);
}

static void prize_game_blink_gauge(void) {
    if (gGameWork.unk86 & 4)
        prize_game_draw_gauge();
    else
        prize_game_clear_gauge();
}

static void prize_game_set_peak(void) {
    gBattleWork.prizePeakY = 0x68 - gBattleWork.prizePower;
    if (gBattleWork.prizePeakY <= 12)
        gBattleWork.prizePeakY = 12;
}

static void prize_game_set_landing_row(void) {
    gBattleWork.prizeRow = gBattleWork.prizePower >> 4;
    switch (gBattleWork.prizeRow) {
    case 0:
        gBattleWork.prizeRow = 5;
        break;
    case 1:
        gBattleWork.prizeRow = 4;
        break;
    case 2:
        gBattleWork.prizeRow = 3;
        break;
    case 3:
        gBattleWork.prizeRow = 2;
        break;
    case 4:
        gBattleWork.prizeRow = 1;
        break;
    case 5:
        gBattleWork.prizeRow = 0;
        break;
    case 6:
        gBattleWork.prizeRow = 0;
        break;
    }
    gBattleWork.prizeLandY = gBattleWork.prizeRow * 16 + 0x18;
}

static void prize_game_launch_ball(void) {
    gSpriteEntries[2].unk24 = (gBattleWork.prizePower >> 2) + 4;
    gSpriteEntries[2].unk25 = 0;
    battle_sprite_anim_init(gBattleSpriteAnimScripts[0x75 - gBattleWork.prizeRow], 4);
}

static void prize_game_move_ball(void) {
    u32 sub_pos = gSpriteEntries[2].unk24 + gSpriteEntries[2].unk20;
    u32 step = sub_pos >> 2;
    gSpriteEntries[2].unk20 = sub_pos & 3;
    if (gSpriteEntries[2].unk25 == 0)
        gSpriteEntries[2].unk4 = (gSpriteEntries[2].unk4 - step) & 0xFF;
    else
        gSpriteEntries[2].unk4 = (gSpriteEntries[2].unk4 + step) & 0xFF;
}

static u32 prize_game_ball_rise(void) {
    prize_game_move_ball();
    if (gSpriteEntries[2].unk4 <= gBattleWork.prizePeakY) {
        gSpriteEntries[2].unk4 = gBattleWork.prizePeakY;
        return 1;
    }
    gSpriteEntries[2].unk27++;
    if (!(gSpriteEntries[2].unk27 & 3) && gSpriteEntries[2].unk24 != 1)
        gSpriteEntries[2].unk24--;
    return 0;
}

static void prize_game_full_power_sfx(void) {
    if (gBattleWork.prizePower == 0x60)
        play_sound_effect(7);
}

static void prize_game_ball_start_fall(void) {
    gSpriteEntries[2].unk24 = 0;
    gSpriteEntries[2].unk25 = 1;
}

static u32 prize_game_ball_fall(void) {
    u32 landed;

    prize_game_move_ball();
    if (gSpriteEntries[2].unk4 < gBattleWork.prizeLandY) {
        gSpriteEntries[2].unk24++;
        landed = 0;
    } else {
        gSpriteEntries[2].unk4 = gBattleWork.prizeLandY;
        landed = 1;
    }
    return landed;
}

static void prize_game_blink_landing_slot(void) {
    if (gGameWork.unk86 & 4)
        draw_tile_block(7, 2, 4, gBattleWork.prizeRow * 2 + 2, REG_BG1CNT,
                        gBattleWork.prizeSlots[gBattleWork.prizeRow] * 14 + 0x3380);
    else
        draw_tile_block(7, 2, 4, gBattleWork.prizeRow * 2 + 2, REG_BG1CNT,
                        gBattleWork.prizeSlots[gBattleWork.prizeRow] * 14 + 0x4380);
}

void prize_game_pick_prize_part(void) {
    u32 base;
    u32 pick, i;

    if (gGameWork.unk9C == 1)
        base = 3;
    else
        base = 0;
    pick = gPrizeGameBotPicks[rng_next_byte() & 0xF];
    for (i = 0; i <= 2; i++) {
        if (gBattleBots[base + pick].present != 0) {
            gBattleWork.prizeMedal = gBattleBots[base + pick].teamSlot;
            gBattleWork.prizePart = gBattleBots[base + pick].parts[gBattleWork.prizeSlots[gBattleWork.prizeRow]].unk17;
            return;
        }
        if (pick == 2)
            pick = 0;
        else
            pick++;
    }
}

u32 link_error_check(void) {
    // unk1C..unk1F read as one word (the struct has no u32 there)
    if (gGameWork.skipBotSetup == 1 && (((struct {
                                            u8 f[0x1C];
                                            u32 x;
                                        } *)&gUnk_03005010)
                                            ->x &
                                        0xFFFF00)) {
        gGameMode = 0;
        gGameState = 10;
        gGameSubState = 0x10;
        return 1;
    }
    return 0;
}

void soft_reset_to_title(void) {
    gUnk_03005030 = 0;
    serial_multiplayer_init();
    VBlankIntrWait();
    REG_SOUNDCNT_X = 0;
    REG_IME = 0;
    hw_reset_init();
    irq_init();
    serial_link_init();
    gGameMode = 3;
    gGameState = 0;
    gGameSubState = 0;
    REG_DMA0CNT_H = 0;
    VBlankIntrWait();
    sound_init(&gSoundWorkArea);
    VBlankIntrWait();
}
