#ifndef GUARD_BATTLE_EFFECT_SPRITES_H
#define GUARD_BATTLE_EFFECT_SPRITES_H

// Effect sprites: OAM entries and animation frames for action effects.

u32 advance_sprite_anim_frame(u32 sprite, u32 b);
u32 sprite_group_rise_step(u8 *buf, u32 slot);
void setup_battle_sprite_oam_entries(u8 *buf, u32 slot, u32 b, s16 x, s16 y);
void armor_panel_draw_icons(u32 side);
void armor_panel_draw_frame(u32 side);
void armor_panel_draw_bars(u32 side, u32 rec); // draws the 4 parts' armor (data[4] max, armor left) via armor_bar_draw
void armor_panel_draw_numbers(u32 side, u32 rec);
void battle_set_damage_break_part(u32 rec, u32 part);
u32 effect_sprite_fly_to_part(u32 slot, u32 part);
u32 hit_sparks_update(u32 slot);
void hit_sparks_spawn(u32 slot, u32 part, s16 x, s16 y);
void damage_digits_spawn(u8 *digits, u32 slot, u32 part, s16 x, s16 y);
u32 advance_sprite_group_anims(u8 *digits, u32 slot);
u32 armor_drain_step(u16 *amount, u32 rec,
                     u32 part); // moves one point from *amount (low byte) out of the part's armor; 1 when done
void armor_panel_clear(u32 side);
void effect_sprite_spawn_at_part(
    u32 slot, u32 part, s16 x, s16 y,
    u32 n); // inits battle sprite slot at (x, y) + gPartSpriteOffsets[part] with animation gBattleSpriteAnimScripts[n]

#endif // GUARD_BATTLE_EFFECT_SPRITES_H
