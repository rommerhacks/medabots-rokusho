#ifndef GUARD_BATTLE_BOT_MOVEMENT_H
#define GUARD_BATTLE_BOT_MOVEMENT_H

// Medabot movement on the battle field between the home and front lines

void sub_0801902C(void);
void sub_08019078(void);
void battle_bot_move(u32 rec);
void sub_08019544(u32 rec);
u32 sub_08019440(u32 rec); // battle_bot_move with the other direction; 1 when the line is reached
void sub_080191E4(u32 rec);
void sub_0801928C(u32 rec);

#endif // GUARD_BATTLE_BOT_MOVEMENT_H
