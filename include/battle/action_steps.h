#ifndef GUARD_BATTLE_ACTION_STEPS_H
#define GUARD_BATTLE_ACTION_STEPS_H

// Per-action step handlers run through the gBattleMessageSteps step tables

void sub_0801DE1C(void);
void sub_0801E2D8(void);
void sub_0801F484(void);
void sub_0801FDEC(void);
void sub_08020050(void);
void sub_0802057C(void);
void sub_080207A4(void);
void sub_0801C4FC(void);
void battle_dispatch_phase_handler_0801D2F0(void);
void sub_0801D380(void);
void sub_0801D40C(void);
void sub_0801D580(void);
u32 target_panels_show(u32 show_target); // actor panel (+ arrows to the target panel), 1 when up
u32 battle_message_show(u32 msg);        // steps the battle message msg (gBattleMessageSteps), 1 when done
u32 miss_popup_run(void);                // the "MISS!!" popup above the acting Medabot, 1 when done
void sub_0801DEE4(void);
void sub_0801FA40(void);

#endif // GUARD_BATTLE_ACTION_STEPS_H
