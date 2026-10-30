#ifndef GUARD_CONSTANTS_GAME_STATES_H
#define GUARD_CONSTANTS_GAME_STATES_H

// gGameMode values: indices into gGameModeHandlers, run once a frame by AgbMain.
enum {
    GAME_MODE_MENU_BATTLE, // menu_battle_mode_update: field menu, Medawatch screens, Robattle (MODE0_STATE_*)
    GAME_MODE_FIELD,       // field_mode_dispatch: walking the map (MODE1_STATE_*)
    GAME_MODE_MENU,        // menu_mode_update: title menu, save, shops, link scenes (MODE2_STATE_*)
    GAME_MODE_SCENE        // dispatch_game_mode_handler: boot logos, intro, title, minigames (MODE3_STATE_*)
};

// gGameState values in game mode 0 (menus and Robattle): indices into gMenuBattleModeStates, run by
// menu_battle_mode_update. States 11-62 are empty_callback.
enum {
    MODE0_STATE_DEV_TEST,       // developer test screen (devtest_dispatch), not reachable in normal play
    MODE0_STATE_FIELD_MENU,     // field_menu_update
    MODE0_STATE_MEDAWATCH,      // medawatch_menu_update
    MODE0_STATE_MEDABOTS,       // medabots_screen_update (also the Robattle team select)
    MODE0_STATE_MEDALS,         // medals_screen_update
    MODE0_STATE_MEDAPARTS,      // medaparts_screen_update
    MODE0_STATE_PREBATTLE,      // prebattle_screen_update: intro, results and prize part
    MODE0_STATE_ROBATTLE,       // robattle_update: command ring and turn order
    MODE0_STATE_ACTION_PHASE,   // battle_action_state_update: action phase, end and time checks
    MODE0_STATE_ACTION_SCRIPT,  // battle_run_action_script: the acting part's action script
    MODE0_STATE_LINK_ROBATTLE,  // link_robattle_update
    MODE0_STATE_DEBUG_MENU = 63 // debug_menu_update
};

// gGameState values in game mode 1 (field): indices into gFieldModeStates, run by field_mode_dispatch.
// The other states are empty_callback.
enum {
    MODE1_STATE_FIELD = 1,   // field_update
    MODE1_STATE_VEHICLE_MENU // vehicle_menu_update
};

// gGameState values in game mode 2: indices into gMenuModeStates, run by menu_mode_update. States 0-2, 13-15
// and 29 are empty_callback.
enum {
    MODE2_STATE_TITLE_MENU = 3,      // title_menu_update: Continue / New Game / options
    MODE2_STATE_ITEM_MENU,           // item_menu_update
    MODE2_STATE_SAVE_SCREEN,         // save_screen_update
    MODE2_STATE_NAME_ENTRY,          // name_entry_screen_update
    MODE2_STATE_TEST_MODE,           // test_mode_dispatch
    MODE2_STATE_GAME_OVER,           // game_over_update
    MODE2_STATE_SAVE_LOST,           // save_lost_dispatch
    MODE2_STATE_TOWN_MAP,            // town_map_dispatch
    MODE2_STATE_SHOP_MENU,           // shop_menu_dispatch
    MODE2_STATE_SHOP_LIST,           // shop_list_dispatch
    MODE2_STATE_MEDAPART_TRADE = 16, // medapart_trade_update
    MODE2_STATE_MEDAL_TRADE,         // medal_trade_update
    MODE2_STATE_MEDAL_RENAME,        // medal_rename_main
    MODE2_STATE_SCROLL_BANNER,       // scene_dispatch_and_tick (no writer found)
    MODE2_STATE_LINK_MENU,           // dispatch_battle_menu_and_update_counters
    MODE2_STATE_LINK_START,          // dispatch_battle_cutscene_substate
    MODE2_STATE_TEXT_SCROLL,         // text_scroll_update
    MODE2_STATE_TOWN_MAP_2,          // town_map_dispatch again (field_mode case 6)
    MODE2_STATE_MEDAL_TRANSFORM,     // medal_transform_update
    MODE2_STATE_SHOP_RETURN,         // dispatch_substate_handler: back to the shop from the Medaparts screen
    MODE2_STATE_LINK_HANDSHAKE,      // link_handshake_update
    MODE2_STATE_LINK_MEDAL_SYNC,     // link_medal_sync_update
    MODE2_STATE_NEW_GAME_PROMPT      // new_game_prompt_update
};

// gGameState values in game mode 3 (scenes): indices into gGameStateHandlers, run by dispatch_game_mode_handler.
enum {
    MODE3_STATE_BOOT_LOGOS,     // boot_logos_update
    MODE3_STATE_INTRO,          // intro_update
    MODE3_STATE_TITLE_SCREEN,   // title_screen_update
    MODE3_STATE_STORY_INTRO,    // story_intro_dispatch
    MODE3_STATE_RACE,           // race_dispatch_substate
    MODE3_STATE_BOMB_GAME,      // bomb_game_dispatch
    MODE3_STATE_MEDABOTS_WEEKLY // medabots_weekly_update
};

#endif // GUARD_CONSTANTS_GAME_STATES_H
