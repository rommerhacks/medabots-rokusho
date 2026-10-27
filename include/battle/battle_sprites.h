#ifndef GUARD_BATTLE_BATTLE_SPRITES_H
#define GUARD_BATTLE_BATTLE_SPRITES_H

// Battle sprite setup, graphics decompression, animation scripts, Medal skill levels

void load_battle_entity_palette(u32 list, u32 entry, u32 slot);
void tile_anim_init(const u16 *pos, u8 obj_tile, u32 slot);
void tile_anim_init_dup(const u16 *pos, u8 obj_tile, u32 slot); // same as tile_anim_init
void tile_anim_run_dup(const u16 *script, u32 slot);            // same as tile_anim_run
void tile_anim_run(const u16 *script, u32 slot);                // steps gUnk_03000440.tileAnims[slot]
void inc_u16_saturating(u16 *counter, u16 max);
void init_battle_bot_sprites(void);
void init_battle_sprite_entry_0801BC04(u32 rec);
void increment_medal_skill_level(u32 rec);
void copy_battle_entity_positions(void);
void decompress_indexed_graphics_to_ewram(u32 list);
void decompress_fixed_graphics_to_ewram(void);

#endif // GUARD_BATTLE_BATTLE_SPRITES_H
