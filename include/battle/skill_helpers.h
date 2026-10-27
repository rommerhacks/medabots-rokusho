#ifndef GUARD_BATTLE_SKILL_HELPERS_H
#define GUARD_BATTLE_SKILL_HELPERS_H

// Skill helpers: damage split, Medal exp, action parameters, skill timers and targets.

void sub_0803713C(void);
u32 sub_08037230(u32 rec, u32 part); // 1 if the part is broken or at full armor
u32 decrement_battle_timer_and_check_zero(void);
void calc_battle_stat_ratio(u32 rec, u32 part); // unkEC = (unkE8 / 4 + part data[6]) / part data[0xC], at least 1
u32 clamp_1_99(u32 a);                          // clamps to 1..99
u8 sub_08037578(u32 a, u32 kind);               // random part id (by a and the part kind)
void sub_0803769C(u32 rec);
void sub_080376F4(u32 rec);
u32 sub_08037728(u32 rec, u32 part,
                 u32 amount);    // unkD6[part] = min(amount, part armor), unkD2[part] = 1 when the armor is all used
void sub_080374E0(u32 a, u32 b); // unkC8 = min(a, b) taken out of a (guess: drain clamp)
void sub_0803752C(u32 a, u32 max, u32 b); // unkC8 = min(b, max - a) (add clamp)
void battle_bot_sprites_blink(
    u32 rec, u32 frame,
    u32 mask); // frame & mask != 0: sets bit 15 of unk0 on the bot's 4 part sprites (0x5A + rec * 4..)
void battle_bot_sprites_show(u32 rec); // sets bit 15 of unk0 on the bot's 4 part sprites
void sub_08037424(
    u32 slot); // y (unk4) += gUnk_083AF4E0[unk23] (& 0xFF), unk23 = (unk23 + 1) & 31 (guess: bob a sprite)
u32 update_sprite_animations_tick_080370AC(u32 slot, u32 n);
void setup_battle_cursor_sprite_08036FF8(u32 slot, s16 x, s16 y, u32 n);
void battle_calc_damage_split(u32 rec, u32 part, s32 amount); // unkC8 = unkCC = min(amount, part data[4] - armor unk11)
u32 battle_check_action_counter(
    u16 *amount, u32 rec,
    u32 part); // moves one point from *amount (low byte) into the part's armor (max data[4]); 1 when done
u32 sub_08036D64(u32 rec, u32 skill); // 1 if unkCF has the bit for Medaforce skill pair 0xD/0xE (1), 0xF/0x10 (8),
u32 medal_update_exp_progress(u32 slot, u32 n);
void battle_set_action_params(u32 rec, u32 skill, s32 a, u32 b);
void reset_battle_bot_state(u32 rec);
void battle_set_damage_display(u32 rec, u32 part, s32 amount);
void sub_08037458(u32 rec, s32 amount); // gUnk_03001800.unkC8 / unkCC = min(amount, head unk10), unkCA = the rest
void sub_08037498(u32 rec, s32 amount); // same, clamped to head data[8] - unk10
u32 battle_select_random_target(u32 base, u32 rec);
u32 sub_08037798(u32 base); // record on side base, or 0xFF

#endif // GUARD_BATTLE_SKILL_HELPERS_H
