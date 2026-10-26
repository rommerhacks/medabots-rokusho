#ifndef GUARD_BATTLE_PART_STATS_H
#define GUARD_BATTLE_PART_STATS_H

// Medapart armor and stat changes with clamping

void sub_08018CBC(void);
void sub_08018D0C(u32 rec); // timed effect A tick (type 0x1F restores armor to damaged parts)
void sub_08018DF4(u32 rec); // timed effect B tick (types 0x13/0x14 lower a part's armor, not below 1)
u32 sub_08018F6C(u32 rec);  // part (1-4) with armor > 1, starting at unkCA and going down, 0 = none

#endif // GUARD_BATTLE_PART_STATS_H
