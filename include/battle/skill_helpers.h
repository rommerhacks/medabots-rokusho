#ifndef GUARD_BATTLE_SKILL_HELPERS_H
#define GUARD_BATTLE_SKILL_HELPERS_H

// Skill helpers: damage split, Medal exp, action parameters, skill timers and targets.

void reaction_counter_begin(void);
u32 part_broken_or_undamaged(u32 rec, u32 part); // 1 if the part is broken or at full armor
u32 decrement_battle_timer_and_check_zero(void);
void calc_battle_stat_ratio(u32 rec, u32 part); // unkEC = (unkE8 / 4 + part data[6]) / part data[0xC], at least 1
u32 clamp_1_99(u32 a);                          // clamps to 1..99
u8 pick_random_change_part(u32 a, u32 kind);    // random part id (by a and the part kind)
void medaforce_calc_success(u32 rec);
void medaforce_calc_damage(u32 rec);
u32 hit_list_set_part_damage(
    u32 rec, u32 part,
    u32 amount); // unkD6[part] = min(amount, part armor), unkD2[part] = 1 when the armor is all used
void calc_drain_amount(u32 a, u32 b);         // unkC8 = min(a, b) taken out of a (guess: drain clamp)
void calc_fill_amount(u32 a, u32 max, u32 b); // unkC8 = min(b, max - a) (add clamp)
void battle_bot_sprites_blink(
    u32 rec, u32 frame,
    u32 mask); // frame & mask != 0: sets bit 15 of unk0 on the bot's 4 part sprites (0x5A + rec * 4..)
void battle_bot_sprites_show(u32 rec); // sets bit 15 of unk0 on the bot's 4 part sprites
void sprite_bob_step(
    u32 slot); // y (unk4) += gUnk_083AF4E0[unk23] (& 0xFF), unk23 = (unk23 + 1) & 31 (guess: bob a sprite)
u32 staggered_sprites_update(u32 slot, u32 n);
void staggered_sprites_spawn(u32 slot, s16 x, s16 y, u32 n);
void battle_calc_damage_split(u32 rec, u32 part, s32 amount); // unkC8 = unkCC = min(amount, part data[4] - armor unk11)
u32 armor_heal_step(
    u16 *amount, u32 rec,
    u32 part); // moves one point from *amount (low byte) into the part's armor (max data[4]); 1 when done
u32 bot_has_status_guard(u32 rec,
                         u32 skill); // 1 if unkCF has the bit for Medaforce skill pair 0xD/0xE (1), 0xF/0x10 (8),
u32 sprite_slide_x_step(u32 slot, u32 n);
void battle_inflict_status(u32 rec, u32 skill, s32 a, u32 b);
void reset_battle_bot_state(u32 rec);
void battle_set_damage_display(u32 rec, u32 part, s32 amount);
void calc_head_uses_taken(u32 rec,
                          s32 amount); // gBattleWork.appliedAmount / unkCC = min(amount, head unk10), unkCA = the rest
void calc_head_uses_given(u32 rec, s32 amount); // same, clamped to head data[8] - unk10
u32 battle_find_enemy_same_legs(u32 base, u32 rec);
u32 battle_find_guarding_enemy(u32 base); // record on side base, or 0xFF

#endif // GUARD_BATTLE_SKILL_HELPERS_H
