#ifndef GUARD_LINK_LINK_ROBATTLE_H
#define GUARD_LINK_LINK_ROBATTLE_H

// Link Robattle (game state 10): handshake, sub-states, screen setup and link packet exchange

u32 link_sync_both_ready(void);
void soft_reset_to_title(void);
void prize_game_pick_slots(void);
void prize_game_pick_prize_part(void);
u32 link_error_check(void); // nonzero: waiting on the serial link (reads gUnk_03005010)
void link_clear_send_word(void);

#endif // GUARD_LINK_LINK_ROBATTLE_H
