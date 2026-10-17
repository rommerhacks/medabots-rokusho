#include "global.h"

int sub_08067160(u8 *s)
{
    int n = 0;
    int r;
    while (s[n] != 0)
        n++;
    r = 0;
    if (n != 1)
        r = n;
    return r;
}

INCLUDE_ASM("asm/nonmatching/code_08067160", clear_stack_buffer_64);
INCLUDE_ASM("asm/nonmatching/code_08067160", scroll_tilemap_column);
INCLUDE_ASM("asm/nonmatching/code_08067160", render_text_right_aligned);
INCLUDE_ASM("asm/nonmatching/code_08067160", copy_bg_tile_column);
INCLUDE_ASM("asm/nonmatching/code_08067160", bg_tilemap_scroll_up_row);
INCLUDE_ASM("asm/nonmatching/code_08067160", init_scene_with_palette_and_song_5);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_080676DC);
INCLUDE_ASM("asm/nonmatching/code_08067160", scene_text_scroll_step);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_080677E0);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_080678DC);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_08067938);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_08067994);
INCLUDE_ASM("asm/nonmatching/code_08067160", dispatch_scene_substate_and_scroll);

void sub_08067A48(u8 slot)
{
    gUnk_030017EC = slot;
    gGameMode = 2;
    gGameState = 0x18;
    gGameSubState = 0;
}

INCLUDE_ASM("asm/nonmatching/code_08067160", update_battle_sprite_explosions);
INCLUDE_ASM("asm/nonmatching/code_08067160", init_scene_with_palette_and_song_25);
INCLUDE_ASM("asm/nonmatching/code_08067160", decompress_medal_sprite_to_vram);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_080680A4);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_08068104);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_08068194);
INCLUDE_ASM("asm/nonmatching/code_08067160", battle_end_wait_for_confirm);
INCLUDE_ASM("asm/nonmatching/code_08067160", advance_fade_and_transition_state);
INCLUDE_ASM("asm/nonmatching/code_08067160", dispatch_battle_end_substate);

void dispatch_game_mode_handler(void)
{
    gUnk_08485C48[gGameState]();
}

INCLUDE_ASM("asm/nonmatching/code_08067160", setup_screen_transition_effect_080682CC);
INCLUDE_ASM("asm/nonmatching/code_08067160", setup_screen_transition_effect_080684F0);
INCLUDE_ASM("asm/nonmatching/code_08067160", scene_transition_step_080686F4);
INCLUDE_ASM("asm/nonmatching/code_08067160", execute_scene_step);
INCLUDE_ASM("asm/nonmatching/code_08067160", check_divisible_by_16);
INCLUDE_ASM("asm/nonmatching/code_08067160", bg0_dma_sync_check);
INCLUDE_ASM("asm/nonmatching/code_08067160", check_divisible_by_32);
INCLUDE_ASM("asm/nonmatching/code_08067160", check_divisible_by_16_b);
INCLUDE_ASM("asm/nonmatching/code_08067160", bg_layer_init_check);
INCLUDE_ASM("asm/nonmatching/code_08067160", check_divisible_by_32_b);
INCLUDE_ASM("asm/nonmatching/code_08067160", dispatch_game_substate_handler_08068C3C);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_08068C6C);

void sub_08068CF4(void)
{
    if (scene_transition_step_080686F4())
        gGameSubState = gUnk_03006F80;
}

INCLUDE_ASM("asm/nonmatching/code_08067160", sub_08068D14);

void sub_08068D74(void)
{
    if (sub_08069EF8()) {
        gUnk_03006F88 = 0;
        gUnk_03006F80 = 4;
        gGameSubState = 2;
    }
}

void sub_08068DA0(void)
{
    REG_BLDCNT = 0xFF;
    REG_BLDY = 0xF;
    race_enter_team_select();
}

INCLUDE_ASM("asm/nonmatching/code_08067160", sub_08068DBC);

void sub_08068FD4(void)
{
    if (sub_08069F80()) {
        gUnk_03006F88 = 0;
        gUnk_03006F80 = 7;
        gGameSubState = 2;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08067160", sub_08069000);

void sub_0806904C(void)
{
    update_sprite_animations_tick_0806AF40();
    update_sprite_animations_0806B334();
    if (sub_0806A4C0()) {
        gUnk_03006F88 = 0;
        gGameSubState = 9;
    }
}

INCLUDE_ASM("asm/nonmatching/code_08067160", sub_08069078);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_080690C4);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_08069114);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_08069158);

void sub_0806918C(void)
{
    u32 zero = 0;
    DmaSet(3, &zero, 0x06000000, 0x85006000);
    REG_DISPCNT = 0x60;
    zero = 0;
    DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
}

INCLUDE_ASM("asm/nonmatching/code_08067160", init_battle_background_layers);

void dma_copy_tilemap_strip(u8 n)
{
    u16 buf[24];
    int i;
    for (i = 0; i <= 7; i++) {
        buf[i] = n * 8 - 0x6E00 + i;
        buf[i + 8] = n * 8 - 0x5DC0 + i;
        buf[i + 16] = n * 8 - 0x4D80 + i;
    }
    DmaSet(3, buf, n * 64 + 0x0600F000, 0x80000018);
    gBg2Scroll.y = -((12 - n) * 8);
}

INCLUDE_ASM("asm/nonmatching/code_08067160", init_battle_bg_layer);
INCLUDE_ASM("asm/nonmatching/code_08067160", init_battle_field_screen);
INCLUDE_ASM("asm/nonmatching/code_08067160", init_battle_bg_layer1);
INCLUDE_ASM("asm/nonmatching/code_08067160", write_tilemap_tiles_dma);
INCLUDE_ASM("asm/nonmatching/code_08067160", load_bg_tilemaps_and_palette);
INCLUDE_ASM("asm/nonmatching/code_08067160", load_battle_sprite_graphics);
INCLUDE_ASM("asm/nonmatching/code_08067160", divide_by_3);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_08069A68);
INCLUDE_ASM("asm/nonmatching/code_08067160", init_battle_icon_positions);

void init_battle_sprite_small(void)
{
    init_battle_sprite_entry_08048818(0, 0xC004, 0x33, 0, 1);
    gUnk_03002C30[0].unk2 = -16;
}

INCLUDE_ASM("asm/nonmatching/code_08067160", init_battle_sprite_medium);
INCLUDE_ASM("asm/nonmatching/code_08067160", init_battle_sprite_c400);
INCLUDE_ASM("asm/nonmatching/code_08067160", init_battle_sprite_entry_1);
INCLUDE_ASM("asm/nonmatching/code_08067160", init_battle_sprite_large);
INCLUDE_ASM("asm/nonmatching/code_08067160", get_entity_speed_value);

void sub_08069EE4(u8 *dst, u8 *src)
{
    do {
        *dst = *src;
        dst++;
    } while (*src++ <= 0xF8);
}

INCLUDE_ASM("asm/nonmatching/code_08067160", sub_08069EF8);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_08069F80);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_0806A230);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_0806A4C0);

bool32 sub_0806A584(void)
{
    if (gUnk_03006F8C[0] > 2 && gUnk_03006F8C[1] > 2 && gUnk_03006F8C[2] > 2) {
        if (++gUnk_03006F88 > 0xF0)
            return TRUE;
    }
    return FALSE;
}

INCLUDE_ASM("asm/nonmatching/code_08067160", update_battle_bot_turn_order_tiles);
INCLUDE_ASM("asm/nonmatching/code_08067160", update_battle_icon_rotation);

void battle_update_action_counters(void)
{
    int i;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03006F8C[i] <= 2) {
            if (gUnk_08485CE3[gUnk_03006F84][gUnk_03006FD0[i][gUnk_03006F8C[i]]] <= ++gUnk_03006FE0[i]) {
                gUnk_03002C30[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A++;
                gUnk_03006FE0[i] = 0;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatching/code_08067160", update_battle_bot_entry_animations);
INCLUDE_ASM("asm/nonmatching/code_08067160", update_battle_bot_death_animations);
INCLUDE_ASM("asm/nonmatching/code_08067160", update_battle_bot_damage_animations);
INCLUDE_ASM("asm/nonmatching/code_08067160", update_sprite_animations_tick_0806AF40);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_0806AFA0);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_0806B068);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_0806B0B4);
