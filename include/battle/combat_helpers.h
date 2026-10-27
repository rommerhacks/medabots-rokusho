#ifndef GUARD_BATTLE_COMBAT_HELPERS_H
#define GUARD_BATTLE_COMBAT_HELPERS_H

// Combat helpers: armor damage, target cursor, sprite movement, evasion, part/ability checks.

void battle_target_nearest_enemy(u32 rec);
void sub_080350E0(u32 rec);
u32 bot_intact_parts_class(u32 rec);
u32 calc_bot_matching_part_power(u32 rec);
void accumulate_battle_speed_value(u32 rec);
u32 get_random_battle_weight_entry(u32 idx);
void calc_battle_action_speed(u32 rec, u32 part);
void apply_battle_bot_damage_reduction(u32 rec);
u32 check_bot_ability_type_strike(u32 rec, u32 part, u32 target);
u32 check_bot_ability_type_shoot(u32 rec, u32 part, u32 target);
void success_add_strengthen_parts(u32 rec);
u32 check_bot_can_shoot(u32 rec, u32 part, u32 target);
u32 check_bot_can_support(u32 rec, u32 part, u32 target);
u32 check_bot_can_use_shoot_part(u32 rec, u32 part, u32 target);
u32 check_bot_status_effect_4(u32 rec, u32 part, u32 target);
u32 check_can_target_bot(u32 rec, u32 part, u32 target);
u32 check_battle_can_support_target(u32 rec, u32 part, u32 target);
u32 check_battle_can_special_target(u32 rec, u32 part, u32 target);
void battle_set_damage_vs_armor(u32 rec, u32 part, s32 amount);
u32 sub_08034F44(u32 rec);
void add_bot_to_defeated_list(u32 rec);
u32 sprite_hop_step(u32 slot);
u32 move_sprite_toward_target(u32 slot);
void sub_08035694(u32 slot);
u32 update_sprite_deceleration(u32 slot, s16 a, s16 b);
void check_sprite_overlap_and_adjust(u32 slot, u32 b);
void sub_080356B4(u32 slot);
void sub_08035C3C(void);
void battle_set_action_target(u32 rec,
                              u32 target); // guess: record rec targets record target - 1 (unkE0, gUnk_03001800.unk88)
void battle_set_action_target_part(u32 rec,
                                   u32 part); // guess: record rec targets part part - 1 (unkE1, gUnk_03001800.unk8B)
u32 sprite_move_toward_target(u32 slot, s16 x, s16 y);
void bg3_shake_step(u32 frame);
void sprite_shake_x_step(u32 slot, u32 frame, u32 y);     // sprite unk2 = y, +1 / -1 on frames 2-3 / 6-7 of 8
void reduce_bot_part_stat(u32 rec, u32 part, s32 amount); // part armor (unk11) -= amount, not below 0
void bot_halve_broken_leg_stats(u32 rec);
void set_target_sprite_position(u32 rec, u32 frame, u32 flag);
void update_target_cursor_position(u32 rec);
void battle_pick_random_target_part(u32 rec);
void battle_load_action_target(u32 rec);
void sub_080351E8(u32 rec);
void add_u8_capped(u8 *val, u32 amount, u32 max); // *val = min(*val + amount, max)
void subtract_u8_floored(u8 *val, s32 amount);    // *val = max(*val - amount, 0)
void damage_add_small_random(void);
void damage_divide_by_part_divisor(u32 rec, u32 part);
void subtract_s16_floored(s16 *amount, s32 sub); // *amount -= sub, not below 0
void damage_add_strengthen_parts(u32 rec);

#endif // GUARD_BATTLE_COMBAT_HELPERS_H
