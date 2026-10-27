#ifndef GUARD_BATTLE_PART_STATS_H
#define GUARD_BATTLE_PART_STATS_H

// Timed battle effects: AutoRecover (effect A) and the Fire / Melt burn (effect B)

void battle_tick_timed_effects(void);
void battle_tick_buff_effect(u32 rec);   // timed effect A tick (AutoRecover 0x1F restores armor to damaged parts)
void battle_tick_status_effect(u32 rec); // timed effect B tick (Fire / Melt 0x13/0x14 burn a part's armor, not below 1)
u32 find_burnable_part(u32 rec);         // part (1-4) with armor > 1, starting at unkCA and going down, 0 = none

#endif // GUARD_BATTLE_PART_STATS_H
