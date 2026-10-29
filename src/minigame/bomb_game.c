// Mode-3 state 5: the bomb minigame (entered from a field script, switch_game_mode case 0x11; the Select Corps
// arcade game). A thrower at the top rolls bombs down three lanes; R / L shift the player Medabot at the bottom
// (BombGameWork.playerPos) to bat each bomb aside as it arrives. A bomb that reaches the bottom blows the
// player up and costs one of 3 lives; the round then restarts with 10 more bombs (at most 50) dropped more slowly.
// Batting all of them shows CONGRATULATIONS (gFieldState.sceneResult 1); losing every life shows GAME OVER (2).
// Sub-states (gBombGameStates): 0 init, 1 graphics, 2 fade in, 3 round intro, 4 pick lanes, 5 play, 6 cleared,
// 7 game over, 8 fade out, 9 back to the field. Runtime-checked in scenario 14_arcade.
#include "global.h"
#include "constants/sprites.h"

// gSpriteEntries slots
#define BOMB_SPR_BANNER 0        // round intro countdown, CONGRATULATIONS / GAME OVER
#define BOMB_SPR_BOMB_ICON 10    // BOMB counter icon
#define BOMB_SPR_COUNT_DIGITS 11 // 11-12: bombs left, two digits
#define BOMB_SPR_LIVES 13        // 13-15: LIFE icons
#define BOMB_SPR_HELP_BOT 16     // HOW TO PLAY panel: Medabot pose
#define BOMB_SPR_HELP_L 17       // HOW TO PLAY panel: L button
#define BOMB_SPR_HELP_R 18       // HOW TO PLAY panel: R button
#define BOMB_SPR_HELP_ARROW 19   // HOW TO PLAY panel: arrow over the button for the lowest bomb
#define BOMB_SPR_PLAYER 30       // the player's Medabot
#define BOMB_SPR_HELD_BOMB 31    // the bomb in the thrower's hands
#define BOMB_SPR_THROWER 32      // the bomb thrower
#define BOMB_SPR_SHADOW 33       // shadow under the player or thrower when they leave the ground
#define BOMB_SPR_BOMBS 40        // 40-47: the bombs
#define BOMB_SPR_BOMB_SHADOWS 48 // 48-55
#define BOMB_SPR_HIT_SPARK 56    // flash where a bomb was batted
#define BOMB_SPR_BASE 57         // the SELECT CORPS base at the bottom

// gSpriteEntries work[] indices
#define BOMB_SPR_BANNER_STEP 0x0      // banner: step of the round intro / CONGRATULATIONS / GAME OVER sequence
#define BOMB_SPR_BANNER_BOUNCE 0x1    // banner: GAME OVER bounce number (divides the bounce height)
#define BOMB_SPR_PLAYER_LIVES 0x0     // player: lives left
#define BOMB_SPR_PLAYER_HIT 0x1       // player: 1 while blown up by a bomb
#define BOMB_SPR_PLAYER_HIT_RIGHT 0x2 // player: blown to the right (else left)
#define BOMB_SPR_THROW_STATE 0x0      // thrower: throw state
#define BOMB_SPR_THROW_LANE 0x1       // thrower: lane of the next bomb
#define BOMB_SPR_BOMB_STATE 0x0       // bombs: 0 free, 1 rolling, 2 batted away, 3 exploding
#define BOMB_SPR_BOMB_LANE 0x1        // bombs: lane 0-2; batted away: 0 flies left, else right
#define BOMB_SPR_ARROW_STATE 0x0      // HOW TO PLAY arrow: state of the bomb it points at, 0 = none
#define BOMB_SPR_ARROW_LANE 0x1       // HOW TO PLAY arrow: lane of that bomb
#define BOMB_SPR_SPARK_ACTIVE 0x0     // hit spark: 1 while shown

static void bomb_game_update_hint_arrow(void);
static void bomb_game_update_thrower(void);
static void bomb_game_update_bombs(void);
static void bomb_game_update_hit_spark(void);
static u32 bomb_game_clear_banner(void);
static u32 bomb_game_over_banner(void);
static void bomb_game_animate_help_panel(void);
static void bomb_game_animate_player(void);
static void bomb_game_animate_thrower(void);
static void bomb_game_clear_effects(void);
static void bomb_game_over_effects(void);

void bomb_game_dispatch(void) {
    gBombGameStates[gGameSubState]();
}

void bomb_game_init(void) {
    u32 zero = 0;
    DmaSet(3, &zero, VRAM, 0x85006000);
    REG_DISPCNT = 0x60;
    zero = 0;
    DmaSet(3, &zero, gSpriteEntries, 0x85000800);
    zero = 0;
    DmaSet(3, &zero, &gSceneWork, 0x85000012);
    gSceneWork.nextMode = 3;
    gSceneWork.nextState = 5;
    gSceneWork.timer = 0;
    gSceneWork.param.s[1] = 12; // dropInterval
    gSceneWork.param.s[0] = 50; // roundBombs
    gSceneWork.param.s[2] = 0;  // bombsLeft
    play_song(0);
    setup_screen_transition_effect_080682CC(3, 2, 0);
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gGameSubState++;
}

void bomb_game_load_graphics(void) {
    s32 i;

    LZ77UnCompVram(gBombGameBgTiles, (void *)(VRAM + 0x4000));
    LZ77UnCompVram(gBombGameBgTilemap1, (void *)(VRAM + 0x800));
    LZ77UnCompVram(gBombGameBgTilemap2, (void *)(VRAM + 0x1000));
    LZ77UnCompVram(gBombGameBgTilemap3, (void *)(VRAM + 0x1800));
    DmaSet(3, gBombGameBgPalettes, PLTT, 0x80000050);
    REG_BG1CNT = 0x105;
    REG_BG2CNT = 0x206;
    REG_BG3CNT = 0x307;
    LZ77UnCompVram(gBombGameObjTiles, (void *)(VRAM + 0x10000));
    DmaSet(3, gBombGameObjPalettes, PLTT + 0x200, 0x800000F0);

    sprite_entry_init(BOMB_SPR_PLAYER,
                      SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3) | SPRITE_FLAG_AFFINE |
                          SPRITE_FLAG_ROTATE | SPRITE_FLAG_DOUBLE_SIZE,
                      0, 0, 3);
    gSpriteEntries[BOMB_SPR_PLAYER].x = 0x78;
    gSpriteEntries[BOMB_SPR_PLAYER].y = 0x80;
    gSpriteEntries[BOMB_SPR_PLAYER].scale_x = 0x40;
    gSpriteEntries[BOMB_SPR_PLAYER].scale_y = 0x40;
    gSpriteEntries[BOMB_SPR_PLAYER].angle = 0;
    gBombGameWork.playerPos = 0;
    gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_LIVES] = 3;
    gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_HIT] = 0;

    sprite_entry_init(BOMB_SPR_THROWER, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3), 7, 1, 3);
    gSpriteEntries[BOMB_SPR_THROWER].x = 0x78;
    gSpriteEntries[BOMB_SPR_THROWER].y = 0x10;
    sprite_entry_init(BOMB_SPR_HELD_BOMB, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3), 0x10, 2, 3);
    gSpriteEntries[BOMB_SPR_HELD_BOMB].y = 0xC8;
    sprite_entry_init(BOMB_SPR_BOMB_ICON, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1), 0x10, 2, 3);
    gSpriteEntries[BOMB_SPR_BOMB_ICON].x = 0x10;
    gSpriteEntries[BOMB_SPR_BOMB_ICON].y = 0x30;
    for (i = 0; i < 2; i++) {
        sprite_entry_init(BOMB_SPR_COUNT_DIGITS + i, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1),
                          0x21, 8, 3);
        gSpriteEntries[BOMB_SPR_COUNT_DIGITS + i].x = 0x18 + i * 16;
        gSpriteEntries[BOMB_SPR_COUNT_DIGITS + i].y = 0x28;
    }
    sprite_entry_init(BOMB_SPR_BASE, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x2B, 9, 3);
    gSpriteEntries[BOMB_SPR_BASE].x = 0x78;
    gSpriteEntries[BOMB_SPR_BASE].y = 0x98;
    for (i = 0; i < 3; i++) {
        sprite_entry_init(BOMB_SPR_LIVES + i, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1), 0x18, 5,
                          3);
        gSpriteEntries[BOMB_SPR_LIVES + i].x = 8 + i * 16;
        gSpriteEntries[BOMB_SPR_LIVES + i].y = 0x78;
    }
    sprite_entry_init(BOMB_SPR_HELP_BOT, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1), 0x1E, 7, 3);
    gSpriteEntries[BOMB_SPR_HELP_BOT].x = 0xB8;
    gSpriteEntries[BOMB_SPR_HELP_BOT].y = 0x68;
    sprite_entry_init(BOMB_SPR_HELP_L, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1), 0x1A, 6, 3);
    gSpriteEntries[BOMB_SPR_HELP_L].x = 0xB8;
    gSpriteEntries[BOMB_SPR_HELP_L].y = 0x58;
    sprite_entry_init(BOMB_SPR_HELP_R, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1), 0x1C, 6, 3);
    gSpriteEntries[BOMB_SPR_HELP_R].x = 0xD8;
    gSpriteEntries[BOMB_SPR_HELP_R].y = 0x58;
    sprite_entry_init(BOMB_SPR_HELP_ARROW, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1), 0x19, 6, 3);
    gSpriteEntries[BOMB_SPR_HELP_ARROW].x = 0xB8;
    gSpriteEntries[BOMB_SPR_HELP_ARROW].y = 0xC8;
    REG_DISPCNT |= 0x1E00;
    gGameSubState++;
}

// Sub-state 2: waits for the fade-in, then starts the minigame song.
void bomb_game_fade_in_state(void) {
    if (scene_transition_step_080686F4()) {
        play_song(0x14);
        gGameSubState++;
    }
}

// Sub-state 3: the round intro banner (bomb_game_round_intro).
void bomb_game_round_intro_state(void) {
    if (bomb_game_round_intro())
        gGameSubState++;
    bomb_game_animate_round_banner();
}

// Sub-state 4: picks the lane of each bomb of the round, a random walk that never jumps two lanes.
void bomb_game_pick_lanes_state(void) {
    s32 i;

    gBombGameWork.bombLanes[0] = gRandomBytes[(gFrameCounter + i) & 0xFF] % 3;
    for (i = 1; i < gBombGameWork.roundBombs; i++) {
        switch ((u8)(gRandomBytes[(gFrameCounter + i) & 0xFF] % 7)) {
        case 0:
            gBombGameWork.bombLanes[i] = gBombGameWork.bombLanes[i - 1];
            break;
        case 1:
        case 2:
        case 3:
            gBombGameWork.bombLanes[i] = gBombGameWork.bombLanes[i - 1] == 0 ? 1 : gBombGameWork.bombLanes[i - 1] - 1;
            break;
        case 4:
        case 5:
        case 6:
            gBombGameWork.bombLanes[i] = gBombGameWork.bombLanes[i - 1] == 2 ? 1 : gBombGameWork.bombLanes[i - 1] + 1;
            break;
        }
    }
    gGameSubState++;
}

// Sub-state 5: one frame of play.
void bomb_game_play_state(void) {
    if (gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_HIT] == 0) {
        bomb_game_move_player();
        bomb_game_drop_bombs();
        bomb_game_update_hint_arrow();
    } else {
        bomb_game_player_blown_up();
    }
    bomb_game_update_thrower();
    bomb_game_update_bombs();
    bomb_game_update_hit_spark();
    bomb_game_draw_bomb_count();
    bomb_game_animate_bombs();
    bomb_game_animate_player();
    bomb_game_animate_thrower();
    bomb_game_animate_help_panel();
}

// Sub-state 6: all bombs batted; CONGRATULATIONS, then result 1.
void bomb_game_clear_state(void) {
    bomb_game_clear_effects();
    if (bomb_game_clear_banner()) {
        gFieldState.sceneResult = 1;
        fade_out_music(0x30);
        gGameSubState = 8;
    }
}

// Sub-state 7: no lives left; GAME OVER, then result 2.
void bomb_game_over_state(void) {
    bomb_game_update_bombs();
    bomb_game_over_effects();
    bomb_game_animate_bombs();
    if (bomb_game_over_banner()) {
        gFieldState.sceneResult = 2;
        fade_out_music(0x30);
        gGameSubState = 8;
    }
}

void bomb_game_fade_out_state(void) {
    if (execute_scene_step()) {
        u32 zero = 0;
        DmaSet(3, &zero, gSpriteEntries, 0x85000800);
        gGameSubState++;
    }
}

void bomb_game_exit_state(void) {
    REG_BLDCNT = 0xFF;
    REG_BLDY = 0x10;
    REG_DISPCNT &= 0x80FF;
    play_song(0);
    field_return_from_scene(1);
}

// The round intro on the banner sprite: title zoom (A / START skips), the BOMB counter counting up to roundBombs,
// a 3-2-1 countdown and the start signal. Returns 1 when play starts. A lost life re-enters at step 3.
u32 bomb_game_round_intro(void) {
    switch (gSpriteEntries[BOMB_SPR_BANNER].work[BOMB_SPR_BANNER_STEP]) {
    case 0:
        sprite_entry_init(BOMB_SPR_BANNER,
                          SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_AFFINE, 0x2E, 10,
                          3);
        gSpriteEntries[BOMB_SPR_BANNER].x = 0x78;
        gSpriteEntries[BOMB_SPR_BANNER].y = 0x50;
        gSpriteEntries[BOMB_SPR_BANNER].timer = 0;
        gSpriteEntries[BOMB_SPR_BANNER].scale_x = 4;
        gSpriteEntries[BOMB_SPR_BANNER].scale_y = 4;
        gSpriteEntries[BOMB_SPR_BANNER].work[BOMB_SPR_BANNER_STEP]++;
        break;
    case 1:
        if (gSpriteEntries[BOMB_SPR_BANNER].timer < 0x18) {
            gSpriteEntries[BOMB_SPR_BANNER].timer++;
        } else if (++gSpriteEntries[BOMB_SPR_BANNER].timer > 0xB4 || (KEYS_LO(gNewKeys) & 9)) {
            gSpriteEntries[BOMB_SPR_BANNER].timer = 0;
            gSpriteEntries[BOMB_SPR_BANNER].work[BOMB_SPR_BANNER_STEP]++;
        }
        break;
    case 2:
        if (gSpriteEntries[BOMB_SPR_BANNER].timer < 0x18) {
            gSpriteEntries[BOMB_SPR_BANNER].timer++;
        } else {
            gSpriteEntries[BOMB_SPR_BANNER].timer = 0;
            gSpriteEntries[BOMB_SPR_BANNER].y = 0xC8;
            gSpriteEntries[BOMB_SPR_BANNER].work[BOMB_SPR_BANNER_STEP]++;
        }
        break;
    case 3:
        if (gBombGameWork.roundBombs == gBombGameWork.bombsLeft) {
            sprite_entry_init(BOMB_SPR_BANNER,
                              SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_AFFINE |
                                  SPRITE_OBJ_MODE(1),
                              0x2F, 11, 3);
            gSpriteEntries[BOMB_SPR_BANNER].x = 0x78;
            gSpriteEntries[BOMB_SPR_BANNER].y = 0x50;
            gSpriteEntries[BOMB_SPR_BANNER].scale_x = 0;
            gSpriteEntries[BOMB_SPR_BANNER].scale_y = 0x60;
            gSpriteEntries[BOMB_SPR_BANNER].timer = 0;
            gSpriteEntries[BOMB_SPR_BANNER].work[BOMB_SPR_BANNER_STEP]++;
            REG_BLDCNT = 0x840;
            REG_BLDALPHA = 0x10;
        } else {
            gBombGameWork.bombsLeft++;
        }
        break;
    case 4:
    case 5:
    case 6:
        if (gSpriteEntries[BOMB_SPR_BANNER].timer == 0)
            play_sound_effect(0x18);
        if (++gSpriteEntries[BOMB_SPR_BANNER].timer > 0x3C) {
            gSpriteEntries[BOMB_SPR_BANNER].frame++;
            gSpriteEntries[BOMB_SPR_BANNER].timer = 0;
            gSpriteEntries[BOMB_SPR_BANNER].work[BOMB_SPR_BANNER_STEP]++;
        }
        break;
    case 7:
        if (gSpriteEntries[BOMB_SPR_BANNER].timer == 0)
            play_sound_effect(7);
        if (++gSpriteEntries[BOMB_SPR_BANNER].timer > 0x1E) {
            clear_sprite_entry(BOMB_SPR_BANNER);
            gBombGameWork.timer = 0;
            gBombGameWork.nextDropTime = gBombGameWork.roundBombs + gBombGameWork.dropInterval;
            REG_BLDCNT = 0x840;
            REG_BLDALPHA = 0x808;
            return 1;
        }
        break;
    }
    return 0;
}

// Points the HOW TO PLAY arrow at the button (lane) of the lowest rolling bomb, bobbing.
static void bomb_game_update_hint_arrow(void) {
    s32 i;
    s32 lowest_y;

    if (gSpriteEntries[BOMB_SPR_HELP_ARROW].work[BOMB_SPR_ARROW_STATE] == 0) {
        lowest_y = 0;
        for (i = 0; i < 8; i++) {
            if (gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_STATE] == 1 &&
                lowest_y < gSpriteEntries[BOMB_SPR_BOMBS + i].y) {
                lowest_y = gSpriteEntries[BOMB_SPR_BOMBS + i].y;
                gSpriteEntries[BOMB_SPR_HELP_ARROW].work[BOMB_SPR_ARROW_STATE] =
                    gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_STATE];
                gSpriteEntries[BOMB_SPR_HELP_ARROW].work[BOMB_SPR_ARROW_LANE] =
                    gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_LANE];
                gSpriteEntries[BOMB_SPR_HELP_ARROW].timer = 0;
            }
        }
    } else {
        switch (gSpriteEntries[BOMB_SPR_HELP_ARROW].work[BOMB_SPR_ARROW_LANE]) {
        case 0:
            gSpriteEntries[BOMB_SPR_HELP_ARROW].x = 0xB8;
            break;
        case 1:
            gSpriteEntries[BOMB_SPR_HELP_ARROW].x = 0xC8;
            break;
        case 2:
            gSpriteEntries[BOMB_SPR_HELP_ARROW].x = 0xD8;
            break;
        }
        gSpriteEntries[BOMB_SPR_HELP_ARROW].y = (gSpriteEntries[BOMB_SPR_HELP_ARROW].timer & 4) ? 0x47 : 0x49;
        gSpriteEntries[BOMB_SPR_HELP_ARROW].timer++;
    }
}

// R / L move the player Medabot right / left (playerPos -8..8); it drifts back to the middle when released.
void bomb_game_move_player(void) {
    u32 dir = KEYS_HI(gHeldKeys) & 3;

    if (dir == 1) {
        if (++gBombGameWork.playerPos > 8)
            gBombGameWork.playerPos = 8;
    } else if (dir == 2) {
        if (--gBombGameWork.playerPos < -8)
            gBombGameWork.playerPos = -8;
    } else {
        if (gBombGameWork.playerPos > 0)
            gBombGameWork.playerPos--;
        if (gBombGameWork.playerPos < 0)
            gBombGameWork.playerPos++;
    }
    gSpriteEntries[BOMB_SPR_PLAYER].x = gBombGameWork.playerPos * 3 + 0x78;
}

// The thrower steps toward the next bomb's lane and swings; the held bomb follows the hands.
static void bomb_game_update_thrower(void) {
    switch (gSpriteEntries[BOMB_SPR_THROWER].work[BOMB_SPR_THROW_STATE]) {
    case 0:
        break;
    case 3:
        if (++gSpriteEntries[BOMB_SPR_THROWER].timer == 20) {
            gSpriteEntries[BOMB_SPR_THROWER].work[BOMB_SPR_THROW_STATE] = 0;
            gSpriteEntries[BOMB_SPR_THROWER].work[BOMB_SPR_THROW_LANE] = 0;
            gSpriteEntries[BOMB_SPR_THROWER].timer = 0;
            gSpriteEntries[BOMB_SPR_HELD_BOMB].y = 0xC8;
        }
        break;
    case 1:
        if (gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_HIT] == 0) {
            gSpriteEntries[BOMB_SPR_HELD_BOMB].x = gSpriteEntries[BOMB_SPR_THROWER].x;
            gSpriteEntries[BOMB_SPR_HELD_BOMB].y = 0x18;
        } else {
            gSpriteEntries[BOMB_SPR_THROWER].work[BOMB_SPR_THROW_STATE] = 3;
        }
        break;
    case 2:
        if (gSpriteEntries[BOMB_SPR_THROWER].timer++ <= 7) {
            switch (gSpriteEntries[BOMB_SPR_THROWER].work[BOMB_SPR_THROW_LANE]) {
            case 0:
                gSpriteEntries[BOMB_SPR_THROWER].x -= 2;
                if (gSpriteEntries[BOMB_SPR_THROWER].x < 0x6C)
                    gSpriteEntries[BOMB_SPR_THROWER].x = 0x6C;
                gSpriteEntries[BOMB_SPR_HELD_BOMB].x =
                    gSpriteEntries[BOMB_SPR_THROWER].x - gSpriteEntries[BOMB_SPR_THROWER].timer - 2;
                break;
            case 1:
                if (gSpriteEntries[BOMB_SPR_THROWER].x < 0x78) {
                    if ((gSpriteEntries[BOMB_SPR_THROWER].x += 2) > 0x78)
                        gSpriteEntries[BOMB_SPR_THROWER].x = 0x78;
                } else if (gSpriteEntries[BOMB_SPR_THROWER].x > 0x78) {
                    if ((gSpriteEntries[BOMB_SPR_THROWER].x -= 2) < 0x78)
                        gSpriteEntries[BOMB_SPR_THROWER].x = 0x78;
                }
                gSpriteEntries[BOMB_SPR_HELD_BOMB].x = gSpriteEntries[BOMB_SPR_THROWER].x;
                break;
            case 2:
                gSpriteEntries[BOMB_SPR_THROWER].x += 2;
                if (gSpriteEntries[BOMB_SPR_THROWER].x > 0x84)
                    gSpriteEntries[BOMB_SPR_THROWER].x = 0x84;
                gSpriteEntries[BOMB_SPR_HELD_BOMB].x =
                    gSpriteEntries[BOMB_SPR_THROWER].x + gSpriteEntries[BOMB_SPR_THROWER].timer + 2;
                break;
            }
            gSpriteEntries[BOMB_SPR_HELD_BOMB].y = gSpriteEntries[BOMB_SPR_THROWER].timer <= 3 ? 0x12 : 10;
        } else {
            gSpriteEntries[BOMB_SPR_THROWER].work[BOMB_SPR_THROW_STATE] = 3;
        }
        break;
    }
}

// Starts the throw before each drop and rolls the next bomb when timer passes nextDropTime; the gap shrinks as
// bombsLeft goes down. When no bombs are left and none are rolling, the round is cleared (sub-state 6).
void bomb_game_drop_bombs(void) {
    s32 i;
    s32 shadow;
    struct BombGameWork *work;

    if (gBombGameWork.bombsLeft != 0 && gBombGameWork.nextDropTime - 0x12 < gBombGameWork.timer &&
        gBombGameWork.timer < gBombGameWork.nextDropTime - 9) {
        gSpriteEntries[BOMB_SPR_THROWER].work[BOMB_SPR_THROW_STATE] =
            (gBombGameWork.nextDropTime - 10 == gBombGameWork.timer) ? 2 : 1;
        gSpriteEntries[BOMB_SPR_THROWER].work[BOMB_SPR_THROW_LANE] =
            gBombGameWork.bombLanes[gBombGameWork.bombsLeft - 1];
        gSpriteEntries[BOMB_SPR_THROWER].timer = 0;
    }
    work = &gBombGameWork;
    if (work->nextDropTime < work->timer) {
        if (work->bombsLeft == 0) {
            for (i = 0; i < 8; i++) {
                if (gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_STATE] != 0)
                    return;
            }
            play_song(0);
            play_song(0xE);
            gGameSubState = 6;
            return;
        }
        work->bombsLeft--;
        bomb_game_draw_bomb_count();
        work->nextDropTime += work->bombsLeft * work->bombsLeft / 50 + work->dropInterval;
        for (i = 0; i < 8; i++) {
            if (gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_STATE] == 0) {
                ((void (*)())sprite_entry_init)(BOMB_SPR_BOMBS + i, 0xC800, 0x10, 2, 3);
                gSpriteEntries[BOMB_SPR_BOMBS + i].x = gSpriteEntries[BOMB_SPR_THROWER].x;
                gSpriteEntries[BOMB_SPR_BOMBS + i].y = 0xC;
                gSpriteEntries[BOMB_SPR_BOMBS + i].timer = 0;
                gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_STATE] = 1;
                gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_LANE] =
                    gBombGameWork.bombLanes[gBombGameWork.bombsLeft];
                shadow = BOMB_SPR_BOMB_SHADOWS + i;
                ((void (*)())sprite_entry_init)(shadow, 0xCC08, 0x12, 2, 3);
                gSpriteEntries[shadow].x = gSpriteEntries[BOMB_SPR_BOMBS + i].x;
                gSpriteEntries[shadow].y = 0x10;
                play_sound_effect(0x61);
                gSpriteEntries[BOMB_SPR_HELD_BOMB].y = 0xC8;
                break;
            }
        }
    }
    gBombGameWork.timer++;
}

// Moves the bombs: rolling bombs spread out along their lane as they come closer. Near the bottom a bomb in the
// player's lane is batted to the side (sound 0x68); one that reaches the bottom explodes and blows the player up.
static void bomb_game_update_bombs(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        switch (gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_STATE]) {
        case 0:
            break;
        case 1:
            gSpriteEntries[BOMB_SPR_BOMBS + i].x = (gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_LANE] - 1) *
                                                       ((gSpriteEntries[BOMB_SPR_BOMBS + i].timer >> 2) + 0x18) +
                                                   0x78;
            gSpriteEntries[BOMB_SPR_BOMBS + i].y = gSpriteEntries[BOMB_SPR_BOMBS + i].timer * 2 + 0xC;
            gSpriteEntries[BOMB_SPR_BOMB_SHADOWS + i].x = gSpriteEntries[BOMB_SPR_BOMBS + i].x;
            gSpriteEntries[BOMB_SPR_BOMB_SHADOWS + i].y = gSpriteEntries[BOMB_SPR_BOMBS + i].y + 4;
            if (gSpriteEntries[BOMB_SPR_BOMBS + i].timer > 0x38) {
                if (gSpriteEntries[BOMB_SPR_BOMBS + i].timer > 0x3F) {
                    gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_STATE] = 3;
                    gSpriteEntries[BOMB_SPR_BOMBS + i].timer = 0;
                    gSpriteEntries[BOMB_SPR_BOMBS + i].y = 0x90;
                    gSpriteEntries[BOMB_SPR_BOMB_SHADOWS + i].y = 0xC8;
                    if (gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_HIT] == 0) {
                        gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_HIT] = 1;
                        gSpriteEntries[BOMB_SPR_PLAYER].timer = 0;
                        if ((s8)(gBombGameWork.playerPos / 5) == 0)
                            gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_HIT_RIGHT] =
                                gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_LANE] != 2;
                        else
                            gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_HIT_RIGHT] =
                                gBombGameWork.playerPos > 0;
                        gSpriteEntries[BOMB_SPR_HELP_ARROW].work[BOMB_SPR_ARROW_STATE] = 0;
                        gSpriteEntries[BOMB_SPR_HELP_ARROW].work[BOMB_SPR_ARROW_LANE] = 0;
                        gSpriteEntries[BOMB_SPR_HELP_ARROW].y = 0xC8;
                        gSpriteEntries[BOMB_SPR_HELP_ARROW].timer = 0;
                        sprite_entry_init(BOMB_SPR_SHADOW,
                                          SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3) |
                                              SPRITE_OBJ_MODE(1),
                                          0x12, 2, 3);
                        gSpriteEntries[BOMB_SPR_SHADOW].x = gSpriteEntries[BOMB_SPR_PLAYER].x;
                        gSpriteEntries[BOMB_SPR_SHADOW].y = gSpriteEntries[BOMB_SPR_PLAYER].y + 0xC;
                    }
                    play_sound_effect(0x3B);
                } else if (gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_HIT] == 0) {
                    if ((s8)(gBombGameWork.playerPos / 5) + 1 ==
                        gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_LANE]) {
                        if (gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_LANE] == 1)
                            gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_LANE] = gBombGameWork.bombsLeft & 2;
                        gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_STATE] = 2;
                        sprite_entry_init(BOMB_SPR_HIT_SPARK,
                                          SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1), 0x17, 4, 3);
                        gSpriteEntries[BOMB_SPR_HIT_SPARK].x = gSpriteEntries[BOMB_SPR_BOMBS + i].x;
                        gSpriteEntries[BOMB_SPR_HIT_SPARK].y =
                            gSpriteEntries[BOMB_SPR_BOMBS + i].y -
                            gHalfSineArc[gSpriteEntries[BOMB_SPR_BOMBS + i].timer & 0x3F];
                        gSpriteEntries[BOMB_SPR_HIT_SPARK].work[BOMB_SPR_SPARK_ACTIVE] = 1;
                        gSpriteEntries[BOMB_SPR_HIT_SPARK].timer = 0;
                        gSpriteEntries[BOMB_SPR_HELP_ARROW].work[BOMB_SPR_ARROW_STATE] = 0;
                        play_sound_effect(0x68);
                    }
                }
            }
            gSpriteEntries[BOMB_SPR_BOMBS + i].timer++;
            break;
        case 2:
            if (gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_LANE] == 0)
                gSpriteEntries[BOMB_SPR_BOMBS + i].x -= 4;
            else
                gSpriteEntries[BOMB_SPR_BOMBS + i].x += 4;
            gSpriteEntries[BOMB_SPR_BOMBS + i].y = gSpriteEntries[BOMB_SPR_BOMBS + i].timer * 2 + 0xC;
            gSpriteEntries[BOMB_SPR_BOMB_SHADOWS + i].x = gSpriteEntries[BOMB_SPR_BOMBS + i].x;
            gSpriteEntries[BOMB_SPR_BOMB_SHADOWS + i].y = gSpriteEntries[BOMB_SPR_BOMBS + i].y + 4;
            if (gSpriteEntries[BOMB_SPR_BOMBS + i].timer < 0x28) {
                gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_LANE] = 0;
                gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_STATE] = 0;
                gSpriteEntries[BOMB_SPR_BOMBS + i].y = 0xC8;
                gSpriteEntries[BOMB_SPR_BOMB_SHADOWS + i].y = 0xC8;
            }
            gSpriteEntries[BOMB_SPR_BOMBS + i].timer--;
            break;
        case 3:
            if (gSpriteEntries[BOMB_SPR_BOMBS + i].timer == 0)
                ((void (*)())sprite_entry_init)(BOMB_SPR_BOMBS + i, 0xC400, 0x13, 3, 3);
            else if (gSpriteEntries[BOMB_SPR_BOMBS + i].timer > 0xF)
                clear_sprite_entry(BOMB_SPR_BOMBS + i);
            gSpriteEntries[BOMB_SPR_BOMBS + i].timer++;
            break;
        }
    }
}

// Removes the hit spark after 3 frames.
static void bomb_game_update_hit_spark(void) {
    if (gSpriteEntries[BOMB_SPR_HIT_SPARK].work[BOMB_SPR_SPARK_ACTIVE] == 1 &&
        ++gSpriteEntries[BOMB_SPR_HIT_SPARK].timer > 2)
        clear_sprite_entry(BOMB_SPR_HIT_SPARK);
}

// The player flies off amid explosions; then a life is lost and either the round restarts (10 more bombs, slower
// drops) or the game is over.
void bomb_game_player_blown_up(void) {
    struct S32Array3 debris_times;
    s32 i;

    debris_times = gBombGameDebrisTimes;
    if (gSpriteEntries[BOMB_SPR_PLAYER].timer < 0x50) {
        if (gSpriteEntries[BOMB_SPR_PLAYER].timer <=
                debris_times.v[gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_LIVES] - 1] &&
            (gSpriteEntries[BOMB_SPR_PLAYER].timer & 7) == 0) {
            for (i = 0; i < 8; i++) {
                if (gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_STATE] == 0) {
                    gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_STATE] = 3;
                    gSpriteEntries[BOMB_SPR_BOMBS + i].x = (gRandomBytes[(gFrameCounter + i) & 0xFF] & 0x3F) + 0x58;
                    gSpriteEntries[BOMB_SPR_BOMBS + i].y = 0x90;
                    gSpriteEntries[BOMB_SPR_BOMBS + i].timer = 0;
                    if (gSpriteEntries[BOMB_SPR_PLAYER].timer % 16 == 0)
                        play_sound_effect(0x3B);
                    break;
                }
            }
        }
        if (gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_HIT_RIGHT])
            gSpriteEntries[BOMB_SPR_PLAYER].x += 2;
        else
            gSpriteEntries[BOMB_SPR_PLAYER].x -= 2;
        gSpriteEntries[BOMB_SPR_PLAYER].y -= 2;
        gSpriteEntries[BOMB_SPR_PLAYER].timer++;
    } else {
        gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_LIVES]--;
        bomb_game_draw_lives();
        if (gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_LIVES] != 0) {
            u16 zero;

            gGameSubState = 3;
            gSpriteEntries[BOMB_SPR_BANNER].work[BOMB_SPR_BANNER_STEP] = 3;
            gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_HIT] = 0;
            gSpriteEntries[BOMB_SPR_PLAYER].frame = 0;
            gSpriteEntries[BOMB_SPR_PLAYER].angle = 0;
            gSpriteEntries[BOMB_SPR_PLAYER].x = 0x78;
            gSpriteEntries[BOMB_SPR_PLAYER].y = 0x80;
            gSpriteEntries[BOMB_SPR_PLAYER].scale_x = 0x40;
            gSpriteEntries[BOMB_SPR_PLAYER].scale_y = 0x40;
            gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_HIT_RIGHT] = 0;
            gBombGameWork.playerPos = 0;
            gSpriteEntries[BOMB_SPR_THROWER].frame = 7;
            gSpriteEntries[BOMB_SPR_THROWER].x = 0x78;
            gSpriteEntries[BOMB_SPR_THROWER].y = 0x10;
            gSpriteEntries[BOMB_SPR_THROWER].timer = 0;
            zero = 0;
            DmaSet(3, &zero, &gSpriteEntries[BOMB_SPR_THROWER].work[BOMB_SPR_THROW_STATE], 0x81000008);
            gBombGameWork.roundBombs = gBombGameWork.bombsLeft + 10;
            if (gBombGameWork.roundBombs > 0x32)
                gBombGameWork.roundBombs = 0x32;
            gBombGameWork.dropInterval += 4;
            gBombGameWork.timer = 0;
        } else {
            play_song(0);
            play_song(0xF);
            gGameSubState = 7;
            gBombGameWork.timer = 0;
        }
    }
}

// CONGRATULATIONS banner; returns 1 after about 4 seconds or A / START.
static bool32 bomb_game_clear_banner(void) {
    u8 buf[0x20]; // unused, but the original reserves the stack space
    struct SpriteEntry *banner = gSpriteEntries;

    switch (banner->work[BOMB_SPR_BANNER_STEP]) {
    case 0:
        sprite_entry_init(BOMB_SPR_BANNER, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE, 0x33, 0xC, 3);
        banner->x = 0x78;
        banner->y = 0x50;
        banner->timer = 0;
        banner->work[BOMB_SPR_BANNER_STEP]++;
        gSpriteEntries[BOMB_SPR_PLAYER].frame = 0;
        sprite_entry_init(BOMB_SPR_SHADOW,
                          SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3) | SPRITE_OBJ_MODE(1), 0x12, 2,
                          3);
        gSpriteEntries[BOMB_SPR_SHADOW].x = gSpriteEntries[BOMB_SPR_PLAYER].x;
        gSpriteEntries[BOMB_SPR_SHADOW].y = gSpriteEntries[BOMB_SPR_PLAYER].y + 10;
        break;
    case 1:
        banner->timer++;
        if (banner->timer % 8 == 0)
            gSpriteEntries[BOMB_SPR_THROWER].y -= 2;
        if (banner->timer > 0xEB || (KEYS_LO(gNewKeys) & 9)) {
            clear_sprite_entry(BOMB_SPR_BANNER);
            return 1;
        }
        break;
    }
    return 0;
}

// GAME OVER banner, with explosions over the sinking base; returns 1 after about 4 seconds or A / START.
static u32 bomb_game_over_banner(void) {
    s32 i;

    switch (gSpriteEntries[BOMB_SPR_BANNER].work[BOMB_SPR_BANNER_STEP]) {
    case 0:
        sprite_entry_init(BOMB_SPR_BANNER, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE, 0x34, 0xD, 3);
        gSpriteEntries[BOMB_SPR_BANNER].x = 0x78;
        gSpriteEntries[BOMB_SPR_BANNER].y = -0x10;
        gSpriteEntries[BOMB_SPR_BANNER].timer = 0;
        gSpriteEntries[BOMB_SPR_BANNER].work[BOMB_SPR_BANNER_BOUNCE] = 1;
        gSpriteEntries[BOMB_SPR_BANNER].work[BOMB_SPR_BANNER_STEP]++;
        if (gBombGameWork.bombsLeft > 0x23) {
            sprite_entry_init(BOMB_SPR_BOMBS + 6, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x10,
                              2, 3);
            sprite_entry_init(BOMB_SPR_BOMB_SHADOWS + 6,
                              SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3) | SPRITE_OBJ_MODE(1), 0x12,
                              2, 3);
            gSpriteEntries[BOMB_SPR_BOMB_SHADOWS + 6].y = 0x1E;
        } else if (gBombGameWork.bombsLeft > 0) {
            sprite_entry_init(BOMB_SPR_SHADOW,
                              SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3) | SPRITE_OBJ_MODE(1), 0x12,
                              2, 3);
            gSpriteEntries[BOMB_SPR_SHADOW].x = gSpriteEntries[BOMB_SPR_THROWER].x;
            gSpriteEntries[BOMB_SPR_SHADOW].y = gSpriteEntries[BOMB_SPR_THROWER].y + 8;
        }
        break;
    case 1:
        if (gSpriteEntries[BOMB_SPR_BANNER].timer <= 0x90 && !(gSpriteEntries[BOMB_SPR_BANNER].timer % 4)) {
            for (i = 0; i <= 5; i++) {
                if (gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_STATE] == 0) {
                    gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_STATE] = 3;
                    gSpriteEntries[BOMB_SPR_BOMBS + i].x = (gRandomBytes[(gFrameCounter + i) & 0xFF] & 0x3F) + 0x58;
                    gSpriteEntries[BOMB_SPR_BOMBS + i].y = gSpriteEntries[BOMB_SPR_BASE].y - 0x10;
                    gSpriteEntries[BOMB_SPR_BOMBS + i].timer = 0;
                    if (!(gSpriteEntries[BOMB_SPR_BANNER].timer % 16))
                        play_sound_effect(0x3D);
                    break;
                }
            }
            gSpriteEntries[BOMB_SPR_BASE].x = (gSpriteEntries[BOMB_SPR_BANNER].timer & 4) ? 0x7A : 0x76;
            gSpriteEntries[BOMB_SPR_BASE].y++;
        }
        if (gSpriteEntries[BOMB_SPR_BANNER].timer > 0xEB || (KEYS_LO(gNewKeys) & 9)) {
            clear_sprite_entry(BOMB_SPR_BANNER);
            clear_sprite_entry(BOMB_SPR_BASE);
            return 1;
        }
        if (++gSpriteEntries[BOMB_SPR_BANNER].timer == 0x20) {
            sprite_entry_init(BOMB_SPR_BOMBS + 7, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2), 0x10,
                              2, 3);
            sprite_entry_init(BOMB_SPR_BOMB_SHADOWS + 7,
                              SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3) | SPRITE_OBJ_MODE(1), 0x12,
                              2, 3);
            gSpriteEntries[BOMB_SPR_BOMB_SHADOWS + 7].y = 0x1E;
        }
        break;
    }
    return 0;
}

// Zooms and fades the round intro banner (scale in scale_x / scale_y).
void bomb_game_animate_round_banner(void) {
    u8 alpha_a[8];
    u8 alpha_b[8];

    memcpy(alpha_a, gBombGameBannerEva, 8);
    memcpy(alpha_b, gBombGameBannerEvb, 8);

    switch (gSpriteEntries[BOMB_SPR_BANNER].work[BOMB_SPR_BANNER_STEP]) {
    case 1:
        if (gSpriteEntries[BOMB_SPR_BANNER].timer <= 0x17) {
            if (gSpriteEntries[BOMB_SPR_BANNER].timer <= 0xF) {
                gSpriteEntries[BOMB_SPR_BANNER].scale_x += 4;
                if (gSpriteEntries[BOMB_SPR_BANNER].scale_x > 0x40)
                    gSpriteEntries[BOMB_SPR_BANNER].scale_x = 0x40;
            } else {
                gSpriteEntries[BOMB_SPR_BANNER].scale_y += 8;
                if (gSpriteEntries[BOMB_SPR_BANNER].scale_y > 0x40)
                    gSpriteEntries[BOMB_SPR_BANNER].scale_y = 0x40;
            }
        }
        break;
    case 2:
        if (gSpriteEntries[BOMB_SPR_BANNER].timer <= 0x17) {
            if (gSpriteEntries[BOMB_SPR_BANNER].timer <= 7) {
                gSpriteEntries[BOMB_SPR_BANNER].scale_y -= 8;
                if (gSpriteEntries[BOMB_SPR_BANNER].scale_y < 4)
                    gSpriteEntries[BOMB_SPR_BANNER].scale_y = 4;
            } else {
                gSpriteEntries[BOMB_SPR_BANNER].scale_x -= 4;
                if (gSpriteEntries[BOMB_SPR_BANNER].scale_x < 4)
                    gSpriteEntries[BOMB_SPR_BANNER].scale_x = 4;
            }
        }
        break;
    case 3:
        bomb_game_draw_bomb_count();
        break;
    case 4:
    case 5:
    case 6:
        if (gSpriteEntries[BOMB_SPR_BANNER].timer <= 8) {
            if (((gSpriteEntries[BOMB_SPR_BANNER].scale_x += 8) & 0xFF) > 0x40)
                gSpriteEntries[BOMB_SPR_BANNER].scale_x = 0x40;
            if (((gSpriteEntries[BOMB_SPR_BANNER].scale_y -= 4) & 0xFF) < 0x40)
                gSpriteEntries[BOMB_SPR_BANNER].scale_y = 0x40;
        } else if (gSpriteEntries[BOMB_SPR_BANNER].timer > 0x33) {
            if (gSpriteEntries[BOMB_SPR_BANNER].scale_x > 8)
                gSpriteEntries[BOMB_SPR_BANNER].scale_x -= 8;
            gSpriteEntries[BOMB_SPR_BANNER].scale_y += 4;
            if (gSpriteEntries[BOMB_SPR_BANNER].scale_y > 0x60)
                gSpriteEntries[BOMB_SPR_BANNER].scale_y = 0x60;
        }
        break;
    case 7:
        if (gSpriteEntries[BOMB_SPR_BANNER].timer <= 8) {
            if (((gSpriteEntries[BOMB_SPR_BANNER].scale_x += 8) & 0xFF) > 0x40)
                gSpriteEntries[BOMB_SPR_BANNER].scale_x = 0x40;
            if (((gSpriteEntries[BOMB_SPR_BANNER].scale_y -= 4) & 0xFF) < 0x40)
                gSpriteEntries[BOMB_SPR_BANNER].scale_y = 0x40;
        } else if (gSpriteEntries[BOMB_SPR_BANNER].timer > 0x15) {
            REG_BLDALPHA = (alpha_b[gSpriteEntries[BOMB_SPR_BANNER].timer - 0x16] << 8) |
                           alpha_a[gSpriteEntries[BOMB_SPR_BANNER].timer - 0x16];
        }
        break;
    }
}

// HOW TO PLAY panel: flashes the button to press for the lowest bomb and shows the matching pose.
static void bomb_game_animate_help_panel(void) {
    if (gSpriteEntries[BOMB_SPR_HELP_ARROW].work[BOMB_SPR_ARROW_STATE] != 0) {
        switch (gSpriteEntries[BOMB_SPR_HELP_ARROW].work[BOMB_SPR_ARROW_LANE]) {
        case 0:
            gSpriteEntries[BOMB_SPR_HELP_L].frame = (gSpriteEntries[BOMB_SPR_HELP_ARROW].timer & 4) ? 0x1A : 0x1B;
            gSpriteEntries[BOMB_SPR_HELP_R].frame = 0x1C;
            gSpriteEntries[BOMB_SPR_HELP_BOT].frame = 0x1F;
            break;
        case 1:
            gSpriteEntries[BOMB_SPR_HELP_L].frame = 0x1A;
            gSpriteEntries[BOMB_SPR_HELP_R].frame = 0x1C;
            gSpriteEntries[BOMB_SPR_HELP_BOT].frame = 0x1E;
            break;
        case 2:
            gSpriteEntries[BOMB_SPR_HELP_L].frame = 0x1A;
            gSpriteEntries[BOMB_SPR_HELP_R].frame = (gSpriteEntries[BOMB_SPR_HELP_ARROW].timer & 4) ? 0x1C : 0x1D;
            gSpriteEntries[BOMB_SPR_HELP_BOT].frame = 0x20;
            break;
        }
    } else {
        gSpriteEntries[BOMB_SPR_HELP_L].frame = 0x1A;
        gSpriteEntries[BOMB_SPR_HELP_R].frame = 0x1C;
        gSpriteEntries[BOMB_SPR_HELP_BOT].frame = 0x1E;
    }
}

// Player Medabot frame by position; while blown up it spins, and the base flashes once the bomb has hit.
static void bomb_game_animate_player(void) {
    s8 pos = gBombGameWork.playerPos;

    if (pos > 3)
        gSpriteEntries[BOMB_SPR_PLAYER].frame = (pos == 8) ? 4 : 3;
    else if (pos < -3)
        gSpriteEntries[BOMB_SPR_PLAYER].frame = (pos == -8) ? 2 : 1;
    else
        gSpriteEntries[BOMB_SPR_PLAYER].frame = 0;

    if (gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_HIT] != 0) {
        gSpriteEntries[BOMB_SPR_PLAYER].frame = (gSpriteEntries[BOMB_SPR_PLAYER].timer & 8) ? 5 : 6;
        if (gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_HIT_RIGHT] != 0)
            gSpriteEntries[BOMB_SPR_PLAYER].angle += 0x20;
        else
            gSpriteEntries[BOMB_SPR_PLAYER].angle -= 0x20;
        gSpriteEntries[BOMB_SPR_SHADOW].x = gSpriteEntries[BOMB_SPR_PLAYER].x;
        gSpriteEntries[BOMB_SPR_SHADOW].y =
            gSpriteEntries[BOMB_SPR_PLAYER].y + ((u32)gSpriteEntries[BOMB_SPR_PLAYER].timer / 10 + 0xC);
        if (gSpriteEntries[BOMB_SPR_PLAYER].timer < 0x20) {
            gSpriteEntries[BOMB_SPR_PLAYER].scale_x = (gHalfSineArc[gSpriteEntries[BOMB_SPR_PLAYER].timer] >> 1) + 0x40;
            gSpriteEntries[BOMB_SPR_PLAYER].scale_y = (gHalfSineArc[gSpriteEntries[BOMB_SPR_PLAYER].timer] >> 1) + 0x40;
        } else if (gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_LIVES] == 3) {
            gSpriteEntries[BOMB_SPR_BASE].frame = (gSpriteEntries[BOMB_SPR_PLAYER].timer & 4) ? 0x2B : 0x2C;
        } else if (gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_LIVES] == 2) {
            gSpriteEntries[BOMB_SPR_BASE].frame = (gSpriteEntries[BOMB_SPR_PLAYER].timer & 4) ? 0x2C : 0x2D;
        }
    }
}

// Thrower frame for the current throw.
static void bomb_game_animate_thrower(void) {
    s32 step = gSpriteEntries[BOMB_SPR_THROWER].timer;

    if (step != 0) {
        if (gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_HIT] != 0) {
            gSpriteEntries[BOMB_SPR_THROWER].frame = 8;
            gSpriteEntries[BOMB_SPR_HELD_BOMB].y = 0x12;
        } else if (step <= 3) {
            gSpriteEntries[BOMB_SPR_THROWER].frame = 8;
        } else {
            switch (gSpriteEntries[BOMB_SPR_THROWER].work[BOMB_SPR_THROW_LANE]) {
            case 0:
                gSpriteEntries[BOMB_SPR_THROWER].frame = step <= 7 ? 0xA : 0xB;
                break;
            case 1:
                gSpriteEntries[BOMB_SPR_THROWER].frame = step <= 0xE ? 9 : 8;
                break;
            case 2:
                gSpriteEntries[BOMB_SPR_THROWER].frame = step <= 7 ? 0xC : 0xD;
                break;
            }
        }
    } else {
        gSpriteEntries[BOMB_SPR_THROWER].frame = 7;
    }
}

// Bomb frames: a rolling bomb bounces (gHalfSineArc); an exploding one plays the blast frames.
void bomb_game_animate_bombs(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        switch (gSpriteEntries[BOMB_SPR_BOMBS + i].work[BOMB_SPR_BOMB_STATE]) {
        case 1:
        case 2:
            gSpriteEntries[BOMB_SPR_BOMBS + i].frame = (gSpriteEntries[BOMB_SPR_BOMBS + i].timer & 8) ? 0x10 : 0x11;
            gSpriteEntries[BOMB_SPR_BOMBS + i].y -= gHalfSineArc[gSpriteEntries[BOMB_SPR_BOMBS + i].timer & 0x3F];
            break;
        case 3:
            gSpriteEntries[BOMB_SPR_BOMBS + i].frame = (gSpriteEntries[BOMB_SPR_BOMBS + i].timer - 1) / 4 + 0x13;
            break;
        }
    }
}

// CONGRATULATIONS: cycles the banner palette, the player hops and the thrower cheers.
static void bomb_game_clear_effects(void) {
    u16 buf[16];

    if (gSpriteEntries[BOMB_SPR_BANNER].work[BOMB_SPR_BANNER_STEP] == 1) {
        if (!(gSpriteEntries[BOMB_SPR_BANNER].timer % 8)) {
            if (gSpriteEntries[BOMB_SPR_BANNER].timer & 0x20) {
                DmaSet(3, 0x05000380, buf, 0x80000010);
                DmaSet(3, buf + 1, 0x05000384, 0x8000000B);
                DmaSet(3, buf + 4, 0x05000382, 0x80000001);
                DmaSet(3, buf + 8, 0x0500038A, 0x80000001);
                DmaSet(3, buf + 12, 0x05000392, 0x80000001);
            } else {
                DmaSet(3, 0x05000380, buf, 0x80000010);
                DmaSet(3, buf + 2, 0x05000382, 0x8000000B);
                DmaSet(3, buf + 1, 0x05000388, 0x80000001);
                DmaSet(3, buf + 5, 0x05000390, 0x80000001);
                DmaSet(3, buf + 9, 0x05000398, 0x80000001);
            }
        }
        if (gSpriteEntries[BOMB_SPR_BANNER].timer & 0x10)
            gSpriteEntries[BOMB_SPR_PLAYER].y =
                0x80 - (gHalfSineArc[(gSpriteEntries[BOMB_SPR_BANNER].timer & 0xF) * 4] >> 2);
        gSpriteEntries[BOMB_SPR_THROWER].frame = (gSpriteEntries[BOMB_SPR_BANNER].timer & 8) ? 0xE : 0xF;
    }
}

// GAME OVER: the banner drops and bounces; the thrower juggles two bombs if more than 35 were left, hops if any
// were, and laughs otherwise.
static void bomb_game_over_effects(void) {
    s32 step = gSpriteEntries[BOMB_SPR_BANNER].timer;
    s32 phase;

    if (gSpriteEntries[BOMB_SPR_BANNER].work[BOMB_SPR_BANNER_STEP] != 1)
        return;

    if (step > 0x2F) {
        if (step <= 0x3F) {
            gSpriteEntries[BOMB_SPR_BANNER].y += 6;
        } else if (step <= 0x5F) {
            phase = step & 0xF;
            if (phase == 0)
                gSpriteEntries[BOMB_SPR_BANNER].work[BOMB_SPR_BANNER_BOUNCE]++;
            gSpriteEntries[BOMB_SPR_BANNER].y =
                0x50 - gHalfSineArc[phase * 4] / gSpriteEntries[BOMB_SPR_BANNER].work[BOMB_SPR_BANNER_BOUNCE];
        }
    }

    if (gBombGameWork.bombsLeft > 0x23) {
        if (step & 0x10) {
            if (step & 8)
                gSpriteEntries[BOMB_SPR_THROWER].frame = 0xA;
        } else {
            gSpriteEntries[BOMB_SPR_THROWER].frame = 8;
        }
        if (step & 0x20) {
            if ((step & 0x1F) <= 7)
                gSpriteEntries[BOMB_SPR_BOMBS + 6].x = gSpriteEntries[BOMB_SPR_THROWER].x + 0x10;
            else if ((step & 0x1F) > 0x17)
                gSpriteEntries[BOMB_SPR_BOMBS + 6].x = gSpriteEntries[BOMB_SPR_THROWER].x - 0x10;
            else
                gSpriteEntries[BOMB_SPR_BOMBS + 6].x =
                    gSpriteEntries[BOMB_SPR_THROWER].x - (s16)((((step - 8) * 2) & 0x1F) - 0x10);
            gSpriteEntries[BOMB_SPR_BOMBS + 6].y = 0x12;
            gSpriteEntries[BOMB_SPR_BOMBS + 7].x = gSpriteEntries[BOMB_SPR_THROWER].x + (s16)((step & 0x1F) - 0x10);
            gSpriteEntries[BOMB_SPR_BOMBS + 7].y = 0x12 - (gHalfSineArc[(step * 2) & 0x3F] >> 1);
        } else {
            gSpriteEntries[BOMB_SPR_BOMBS + 6].x = gSpriteEntries[BOMB_SPR_THROWER].x + (s16)((step & 0x1F) - 0x10);
            gSpriteEntries[BOMB_SPR_BOMBS + 6].y = 0x12 - (gHalfSineArc[(step * 2) & 0x3F] >> 1);
            if ((step & 0x1F) <= 7)
                gSpriteEntries[BOMB_SPR_BOMBS + 7].x = gSpriteEntries[BOMB_SPR_THROWER].x + 0x10;
            else if ((step & 0x1F) > 0x17)
                gSpriteEntries[BOMB_SPR_BOMBS + 7].x = gSpriteEntries[BOMB_SPR_THROWER].x - 0x10;
            else
                gSpriteEntries[BOMB_SPR_BOMBS + 7].x =
                    gSpriteEntries[BOMB_SPR_THROWER].x - (s16)((((step - 8) * 2) & 0x1F) - 0x10);
            gSpriteEntries[BOMB_SPR_BOMBS + 7].y = 0x12;
        }
        gSpriteEntries[BOMB_SPR_BOMB_SHADOWS + 6].x = gSpriteEntries[BOMB_SPR_BOMBS + 6].x;
        gSpriteEntries[BOMB_SPR_BOMB_SHADOWS + 7].x = gSpriteEntries[BOMB_SPR_BOMBS + 7].x;
    } else if (gBombGameWork.bombsLeft > 0) {
        if (step & 0x10)
            gSpriteEntries[BOMB_SPR_THROWER].y = 0x10 - gHalfSineArc[(step & 0xF) * 4] / 4;
        gSpriteEntries[BOMB_SPR_THROWER].frame = (step & 0x10) ? 9 : (step & 8) ? 8 : 7;
    } else {
        gSpriteEntries[BOMB_SPR_THROWER].frame = (step & 8) ? 8 : (step & 0x10) ? 0xA : 0xC;
    }
}

// Shows bombsLeft in the two BOMB counter digits.
void bomb_game_draw_bomb_count(void) {
    u16 flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1);
    sprite_entry_init(BOMB_SPR_COUNT_DIGITS, flags, (s8)(gBombGameWork.bombsLeft / 10) + 0x21, 8, 3);
    sprite_entry_init(BOMB_SPR_COUNT_DIGITS + 1, flags, (s8)(gBombGameWork.bombsLeft % 10) + 0x21, 8, 3);
}

// Shows one LIFE icon per life left (the player sprite's work[BOMB_SPR_PLAYER_LIVES]); the others are moved off screen.
void bomb_game_draw_lives(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        s16 y = 0xC8;
        if (i < gSpriteEntries[BOMB_SPR_PLAYER].work[BOMB_SPR_PLAYER_LIVES])
            y = 0x78;
        gSpriteEntries[BOMB_SPR_LIVES + i].y = y;
    }
}
