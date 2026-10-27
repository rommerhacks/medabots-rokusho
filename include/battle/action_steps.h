#ifndef GUARD_BATTLE_ACTION_STEPS_H
#define GUARD_BATTLE_ACTION_STEPS_H

// Per-action step handlers run through the gBattleMessageSteps step tables

void action_announce_run(void);
void sub_0801E2D8(void);
void sub_0801F484(void);
void sub_0801FDEC(void);
void sub_08020050(void);
void sub_0802057C(void);
void sub_080207A4(void);
void trap_hit_run(void);
void action_part_check_run(void);
void target_part_check_run(void);
void action_flash_run(void);
void guard_run(void);
u32 target_panels_show(u32 show_target); // actor panel (+ arrows to the target panel), 1 when up
u32 battle_message_show(u32 msg);        // steps the battle message msg (gBattleMessageSteps), 1 when done
u32 miss_popup_run(void);                // the "MISS!!" popup above the acting Medabot, 1 when done
void closeup_enter_run(void);
void sub_0801FA40(void);

#endif // GUARD_BATTLE_ACTION_STEPS_H
