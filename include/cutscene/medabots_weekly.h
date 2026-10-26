#ifndef GUARD_CUTSCENE_MEDABOTS_WEEKLY_H
#define GUARD_CUTSCENE_MEDABOTS_WEEKLY_H

// Medabots Weekly (mode 3, state 6)

void sub_0807068C(void);
void sub_080706AC(void);
void sub_08071614(void);
void sub_0807168C(void);
// sprite (0x16+): unk23 = arg2, unk30 = unk6 = frame; sets bit (sprite - 0x16) in byte 0x03007010
void sprite_cycle_anim_start(u8 sprite, u16 frame, u8 arg2);
// clears that bit, unk23 = 0, unk6 = frame
void sprite_cycle_anim_stop(u8 sprite, u16 frame);
// gUnk_03002C30[sprite]: unk20 = state, unk21 = 0, unk34 = arg2, unk1A = 0
void sub_08071C40(u8 state, u8 sprite, u16 arg2);
u32 call_battle_handler_by_state_08071C64(void);

#endif // GUARD_CUTSCENE_MEDABOTS_WEEKLY_H
