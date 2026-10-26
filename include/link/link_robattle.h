#ifndef GUARD_LINK_LINK_ROBATTLE_H
#define GUARD_LINK_LINK_ROBATTLE_H

// Link Robattle (game state 10): handshake, sub-states, screen setup and link packet exchange

u32 sub_0803E79C(void);
void soft_reset_to_title(void);
void sub_0803E8B8(void);
void sub_0803EE10(void);
u32 sub_0803EED8(void); // nonzero: waiting on the serial link (reads gUnk_03005010)
void sub_0803E780(void);

#endif // GUARD_LINK_LINK_ROBATTLE_H
