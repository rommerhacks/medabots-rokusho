#ifndef GUARD_MINIGAME_BOMB_GAME_H
#define GUARD_MINIGAME_BOMB_GAME_H

// Bomb minigame (mode 3, state 5)

u32 bomb_game_round_intro(void);
void bomb_game_animate_round_banner(void);
void bomb_game_move_player(void);
void bomb_game_drop_bombs(void);
void bomb_game_player_blown_up(void);
void bomb_game_draw_bomb_count(void);
void bomb_game_animate_bombs(void);
void bomb_game_draw_lives(void);

#endif // GUARD_MINIGAME_BOMB_GAME_H
