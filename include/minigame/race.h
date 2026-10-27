#ifndef GUARD_MINIGAME_RACE_H
#define GUARD_MINIGAME_RACE_H

// Mode-3 state 4: race minigame

void divide_by_3(u8 a, u8 b); // guess: refreshes racer a's 4-part sprite group at its current position (not a divide)
void sub_08068DA0(void);
void sub_08068CF4(void);
void sub_08068D74(void);
void sub_08068FD4(void);
void sub_0806904C(void);
void race_update_racer_anim_counters(
    void); // per racer: gUnk_03006FE0[i] counts frames, steps the racer sprite's unk1A at the gUnk_08485CE3 delay
bool32 sub_08069F80(void);
bool32 sub_0806A4C0(void);
void update_sprite_animations_tick_0806AF40(void);
void update_sprite_animations_0806B334(void);
void clear_sprite_entry(u8 sprite); // zeroes gSpriteEntries[sprite] (0x40 bytes)
void init_battle_field_screen(void);
void init_battle_bg_layer1(void);
void write_tilemap_tiles_dma(u8 a, u8 b, u8 c);
void load_battle_sprite_graphics(void);
void init_battle_background_layers(void);
void load_bg_tilemaps_and_palette(void);
void update_battle_icon_rotation(void);
void update_battle_bot_entry_animations(void);
void race_dispatch_substate(void); // gRaceSubStates[gGameSubState]()
void sub_08069000(void);
void race_update(void); // race sub-state 9: the race itself, every frame (runtime-checked)
void sub_080690C4(void);
void sub_08069114(void);
void sub_08069158(void);
void get_entity_speed_value(void);

#endif // GUARD_MINIGAME_RACE_H
