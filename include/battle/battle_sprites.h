#ifndef GUARD_BATTLE_BATTLE_SPRITES_H
#define GUARD_BATTLE_BATTLE_SPRITES_H

// Battle sprite setup, graphics decompression, animation scripts, Medal skill levels

void load_battle_entity_palette(u32 list, u32 entry, u32 slot);
void init_game_state_entry(const u16 *pos, u8 arg,
                           u32 slot);                // copies the current command's operands to gUnk_03001800.unk102
void sub_0801BF78(const u16 *pos, u8 arg, u32 slot); // same as init_game_state_entry
void sub_0801BFB4(const u16 *pos, u32 slot);         // steps the gUnk_03000440.unk64[slot] record
void process_animation_script(const u16 *pos, u32 slot); // steps the gUnk_03000440.unk64[slot] record
void sub_0801BF64(u16 *counter, u16 max);
void init_battle_bot_sprites(void);
void init_battle_sprite_entry_0801BC04(u32 rec);
void increment_medal_skill_level(u32 rec);
void copy_battle_entity_positions(void);
void decompress_indexed_graphics_to_ewram(u32 list);
void decompress_fixed_graphics_to_ewram(void);

#endif // GUARD_BATTLE_BATTLE_SPRITES_H
