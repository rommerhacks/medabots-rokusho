#ifndef GUARD_BATTLE_EFFECT_SPRITES_H
#define GUARD_BATTLE_EFFECT_SPRITES_H

// Effect sprites: OAM entries and animation frames for action effects.

u32 advance_sprite_anim_frame(u32 sprite, u32 b);
u32 sub_08036B50(u8 *buf, u32 slot);
void setup_battle_sprite_oam_entries(u8 *buf, u32 slot, u32 b, s16 x, s16 y);
void sub_080362C4(u32 side);
void sub_08036340(u32 side);
void sub_08036370(u32 side, u32 rec); // draws the 4 parts' armor (data[4] max, unk11 left) via sub_080363E8
void sub_080364A8(u32 side, u32 rec);
void sub_08036B84(u32 rec, u32 part);
u32 sub_080366DC(u32 slot, u32 part);
u32 sub_0803684C(u32 slot);
void sub_08036784(u32 slot, u32 part, s16 x, s16 y);
void sub_080368C4(u8 *digits, u32 slot, u32 part, s16 x, s16 y);
u32 advance_sprite_group_anims(u8 *digits, u32 slot);
u32 sub_08036BB8(u16 *amount, u32 rec,
                 u32 part); // moves one point from *amount (low byte) out of the part's armor; 1 when done
void sub_08036BF4(u32 side);
void sub_08036C20(u32 slot, u32 part, s16 x, s16 y,
                  u32 n); // inits battle sprite slot at (x, y) + gUnk_083AF480[part] with animation gUnk_083B5F80[n]

#endif // GUARD_BATTLE_EFFECT_SPRITES_H
