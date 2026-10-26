#ifndef GUARD_BATTLE_COMMAND_RING_H
#define GUARD_BATTLE_COMMAND_RING_H

// Robattle command ring: icons, rotation, input

void command_ring_init_icon(u32 a);
void animate_battle_sprites(u32 idx);
void sub_08016370(u32 rec);
u32 sub_08016438(u32 rec);
void command_ring_draw_name(void);
void command_ring_init_icons(void);
void command_ring_input(void);
void command_ring_pulse_selected(void);
void sub_08016554(void);
void command_ring_goto_selected(void);
void sub_080165D0(void);
void sub_08016614(void);
void sub_08016660(void);
void command_ring_init_icons_hidden(void);
void sub_080166AC(void);
void sub_080166F0(void);
void sub_0801672C(void);

#endif // GUARD_BATTLE_COMMAND_RING_H
