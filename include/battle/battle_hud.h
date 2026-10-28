#ifndef GUARD_BATTLE_BATTLE_HUD_H
#define GUARD_BATTLE_BATTLE_HUD_H

// Battle screen drawing: backgrounds, Medabot sprites and portraits, panels, Medaforce gauge

void load_battle_bg_layers(void);
void render_bot_name_sprites(u32 rec);
void draw_battle_panel_left_a(u32 rec);
void draw_battle_panel_left_b(u32 rec);
u32 scale_to_bar_fill(u32 value, u32 max,
                      u32 bar_len); // (float)value / max * bar_len, packed: full 8-pixel tiles << 16 | remaining pixels
void draw_medaforce_gauge_bar(u32 rec);
void draw_medaforce_gauge_value(u32 rec);
void load_bg3_tilemap_08488764(void);
void draw_battle_bot_portraits(void);
void load_all_bot_part_sprites(void);
void setup_all_battle_bot_sprite_positions(void);
void load_bot_part_sprite(u32 rec);
u32 bot_sprite_is_flipped(u32 rec);
void setup_battle_bot_sprite_group(u32 rec, u32 x, u32 y);
void decompress_two_bg1_layers(void);
void get_bot_part_effective_values(u32 bot, u8 *out);

#endif // GUARD_BATTLE_BATTLE_HUD_H
