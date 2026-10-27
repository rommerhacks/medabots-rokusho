#ifndef GUARD_CUTSCENE_MEDABOTS_WEEKLY_H
#define GUARD_CUTSCENE_MEDABOTS_WEEKLY_H

// Medabots Weekly (mode 3, state 6), the in-game TV show

void weekly_scroll_bg3(void);
void weekly_update_studio(void);
void weekly_run_sprite_effects(void);
void sprite_cycle_anim_update(void);
// Starts a looping 4-frame animation on sprite 0x16..0x19 (base frame, one step every `period` frames); sets bit
// (sprite - 0x16) in gWeeklyCycleAnimMask.
void sprite_cycle_anim_start(u8 sprite, u16 frame, u8 period);
// Clears that bit and shows `frame`.
void sprite_cycle_anim_stop(u8 sprite, u16 frame);
// Starts sprite effect `effect` (gWeeklySpriteEffects[effect - 1]) on a sprite; `duration` is its frame count.
void weekly_set_sprite_effect(u8 effect, u8 sprite, u16 duration);
u32 weekly_lecture_run_step(void);

#endif // GUARD_CUTSCENE_MEDABOTS_WEEKLY_H
