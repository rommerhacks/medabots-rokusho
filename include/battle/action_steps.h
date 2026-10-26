#ifndef GUARD_BATTLE_ACTION_STEPS_H
#define GUARD_BATTLE_ACTION_STEPS_H

// Per-action step handlers run through the gUnk_083AD400 step tables

void sub_0801DE1C(void);
void sub_0801E2D8(void);
void sub_0801F484(void);
void sub_0801FDEC(void);
void sub_08020050(void);
void sub_0802057C(void);
void sub_080207A4(void);
void sub_0802081C(void);
void sub_080208C0(void);
void sub_0801C4FC(void);
void battle_dispatch_phase_handler_0801D2F0(void);
void sub_0801D380(void);
void sub_0801D40C(void);
void sub_0801D580(void);
u32 dispatch_battle_action_substate(u32 arg);
u32 sub_0801C0BC(u32 msg); // steps the battle message msg (gUnk_083AD400), 1 when done
u32 sub_0801C154(void);    // steps gUnk_083AD410, 1 when done
void sub_0801DEE4(void);
void sub_0801FA40(void);

#endif // GUARD_BATTLE_ACTION_STEPS_H
