#ifndef GUARD_CONSTANTS_GAME_STATES_H
#define GUARD_CONSTANTS_GAME_STATES_H

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

#endif // GUARD_CONSTANTS_GAME_STATES_H
