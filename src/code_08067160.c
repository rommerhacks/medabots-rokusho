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

void sub_080676DC(void)
{
    struct Unk_03000440 *s;
    u8 *n;
    update_scene_animation_frame();
    s = &gUnk_03000440;
    n = &s->unk84;
    if (*n <= 0x40) {
        blend_obj_palettes_to_color_0803F684(0, 0x20 - (*n / 2), 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 0x20 - (*n / 2), 0xFFFF);
        s->unk84++;
        gUnk_03006F74->unk5 = 0;
    } else
        gGameSubState++;
}

INCLUDE_ASM("asm/nonmatching/code_08067160", scene_text_scroll_step);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_080677E0);

void sub_080678DC(void)
{
    update_scene_animation_frame();
    if (bg_tilemap_scroll_up_row(gUnk_03006F74->unk3A++)) {
        gUnk_03006F74->unk3A = 0;
        if (++gUnk_03006F74->unk5 > 2)
            gGameSubState++;
        else {
            gBg1Scroll.y = 0;
            gGameSubState -= 2;
        }
    }
}

void sub_08067938(void)
{
    struct Unk_03006F74 *s;
    update_scene_animation_frame();
    s = gUnk_03006F74;
    if (++s->unk3A > 0xE) {
        gGameSubState++;
        s->unk3E = 0;
        sound_stop_all_with_fade_guard(0xC0);
    } else
        ((u16 *)(((REG_BG0CNT >> 8) & 0x1F) * 0x800 + VRAM))[(s->unk3A + 2) * 32] = 0;
}

void sub_08067994(void)
{
    update_scene_animation_frame();
    if (gUnk_03006F74->unk3E <= 0xC0) {
        blend_obj_palettes_to_color_0803F684(0, (s16)(gUnk_03006F74->unk3E / 6), 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, (s16)(gUnk_03006F74->unk3E / 6), 0xFFFF);
        gUnk_03006F74->unk3E++;
    } else if (sub_08074FB8() == 0) {
        gGameSubState = 0;
        dispatch_by_index_0476e8(0xC);
    }
}

void dispatch_scene_substate_and_scroll(void)
{
    struct FuncTable7 t = gUnk_080AFEA8;
    t.f[gGameSubState]();
    gBg2Scroll.y--;
}

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

void sub_080680A4(void)
{
    struct Unk_03000440 *s;
    u8 *n;
    update_battle_sprite_explosions();
    s = &gUnk_03000440;
    n = &s->unk84;
    if (*n <= 8) {
        blend_obj_palettes_to_color_0803F684(0, 0x20 - *n * 4, 0xFFFF);
        blend_obj_palettes_to_color_0803F998(0, 0x20 - *n * 4, 0xFFFF);
        (*n)++;
    } else {
        text_window_init(1, 2, 0);
        gGameSubState++;
    }
}

void sub_08068104(void)
{
    update_battle_sprite_explosions();
    if (run_message(gUnk_08485788[0x11])) {
        int t = (s16)gUnk_03006F74->unk3A++;
        if (t > 0x77) {
            t -= 0x78;
            if (t <= 0x80)
                blend_obj_palettes_to_color_0803F998(0x7FFF, t >> 2, 1);
            else {
                struct Unk_03000BE0 *b = gUnk_03000BE0;
                struct Unk_03000BE0 *m = &b[gUnk_030017EC];
                u8 id = m->unk1;
                lz_decompress_dispatch(gUnk_083AC494[id][m->unk8], (void *)0x06010000);
                gUnk_03006F74->unk3A = 0;
                gGameSubState++;
            }
        }
    }
}

void sub_08068194(void)
{
    int t;
    update_battle_sprite_explosions();
    t = (s16)gUnk_03006F74->unk3A++;
    if (t > 0x3B) {
        t -= 0x3C;
        if (t <= 0x80)
            blend_obj_palettes_to_color_0803F998(0x7FFF, 0x20 - (t >> 2), 1);
        else {
            sub_0803FB0C();
            gGameSubState++;
        }
    }
}

void battle_end_wait_for_confirm(void)
{
    update_battle_sprite_explosions();
    if (run_message(gUnk_08485788[0x12]) && (*(u8 *)&gNewKeys & 1)) {
        init_blend_effect(gUnk_03006F74->unk50, 0, 0, 1, 0xC0);
        gGameSubState++;
    }
}

void advance_fade_and_transition_state(void)
{
    if (blend_fade_step_08065598(gUnk_03006F74->unk50)) {
        gGameMode = 0;
        gGameState = 6;
        gGameSubState = 0x50;
    }
}

void dispatch_battle_end_substate(void)
{
    struct FuncTable7 t = gUnk_080AFEC4;
    t.f[gGameSubState]();
    gBg2Scroll.y++;
}

void dispatch_game_mode_handler(void)
{
    gUnk_08485C48[gGameState]();
}

INCLUDE_ASM("asm/nonmatching/code_08067160", setup_screen_transition_effect_080682CC);
INCLUDE_ASM("asm/nonmatching/code_08067160", setup_screen_transition_effect_080684F0);

bool32 scene_transition_step_080686F4(void)
{
    if (gUnk_08485C68[gUnk_03000004]()) {
        gUnk_03000000 = 0;
        if (gUnk_03000004 == 3)
            REG_DISPCNT &= 0xFEFF;
        return TRUE;
    }
    gUnk_03000000++;
    return FALSE;
}

bool32 execute_scene_step(void)
{
    if (gUnk_08485C7C[gUnk_03000004]()) {
        gUnk_03000000 = 0;
        return TRUE;
    }
    gUnk_03000000++;
    return FALSE;
}

bool32 sub_0806878C(void)
{
    return TRUE;
}

bool32 check_divisible_by_16(void)
{
    s32 *c = &gUnk_03000000;
    u8 *np = &gUnk_03000005;
    u8 n = *np;
    s32 t = *c;
    if (t % n == 0)
        REG_BLDY = 16 - t / n;
    if (*c == *np * 16)
        return TRUE;
    return FALSE;
}

bool32 bg0_dma_sync_check(void)
{
    u16 zero = 0;
    s32 *c;
    u8 *np;
    s32 t;
    REG_DISPCNT |= 0x100;
    c = &gUnk_03000000;
    np = &gUnk_03000005;
    {
    u8 n = *np;
    t = *c;
    if (t % n == 0) {
        DmaSet(3, &zero, gUnk_03000008[t / *np] + 0x0600C000, 0x80000001);
        DmaSet(3, &zero, gUnk_03000008[t / *np] + 0x0600C004, 0x80000001);
        DmaSet(3, &zero, gUnk_03000008[t / *np] + 0x0600C008, 0x80000001);
        DmaSet(3, &zero, gUnk_03000008[t / *np] + 0x0600C00C, 0x80000001);
    }
    }
    if (*c == *np * 16) {
        REG_DISPCNT &= 0xFEFF;
        return TRUE;
    }
    return FALSE;
}

INCLUDE_ASM("asm/nonmatching/code_08067160", check_divisible_by_32);

bool32 check_divisible_by_16_b(void)
{
    s32 *c = &gUnk_03000000;
    u8 *np = &gUnk_03000005;
    u8 n = *np;
    s32 t = *c;
    if (t % n == 0)
        REG_BLDY = t / n;
    if (*c == *np * 16)
        return TRUE;
    return FALSE;
}

INCLUDE_ASM("asm/nonmatching/code_08067160", bg_layer_init_check);
INCLUDE_ASM("asm/nonmatching/code_08067160", check_divisible_by_32_b);

void race_dispatch_substate(void)
{
    if (gUnk_03006F90 == 0)
        sub_0806B310();
    gRaceSubStates[gGameSubState]();
}

void sub_08068C6C(void)
{
    sub_0806918C();
    play_song(0);
    gUnk_03006FDC = gUnk_03006D38.unk0;
    get_entity_speed_value();
    load_battle_sprite_graphics();
    load_bg_tilemaps_and_palette();
    init_battle_bg_layer();
    play_song(0x13);
    setup_screen_transition_effect_080682CC(4, 1, 0);
    REG_DISPCNT |= 0x1E00;
    gUnk_03006F88 = 0;
    gUnk_03006F94[0] = 0;
    gUnk_03006F94[1] = 0;
    gUnk_03006F94[2] = 0;
    gUnk_03006F8C[0] = 0;
    gUnk_03006F8C[1] = 0;
    gUnk_03006F8C[2] = 0;
    gUnk_03006F80 = 3;
    gGameSubState = 1;
}

void sub_08068CF4(void)
{
    if (scene_transition_step_080686F4())
        gGameSubState = gUnk_03006F80;
}

void sub_08068D14(void)
{
    if (execute_scene_step()) {
        u32 zero = 0;
        DmaSet(3, &zero, gUnk_03002C30, 0x85000800);
        gVBlankCallback = nullsub_08000840;
        REG_DISPCNT &= 0x80FF;
        gGameSubState = gUnk_03006F80;
    }
}

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

void sub_08069000(void)
{
    init_battle_field_screen();
    init_battle_icon_positions();
    init_battle_bg_layer1();
    play_song(0);
    setup_screen_transition_effect_080682CC(4, 1, 0);
    play_song(0x17);
    REG_DISPCNT |= 0x1E00;
    gUnk_03006F80 = 8;
    gGameSubState = 1;
}

void sub_0806904C(void)
{
    update_sprite_animations_tick_0806AF40();
    update_sprite_animations_0806B334();
    if (sub_0806A4C0()) {
        gUnk_03006F88 = 0;
        gGameSubState = 9;
    }
}

void race_update(void)
{
    update_battle_icon_rotation();
    race_update_racer_anim_counters();
    update_battle_bot_entry_animations();
    update_battle_bot_death_animations();
    update_battle_bot_damage_animations();
    update_battle_bot_turn_order_tiles();
    update_sprite_animations_tick_0806AF40();
    update_sprite_animations_0806B334();
    if (race_check_all_finished()) {
        gUnk_03006F88 = 0;
        gUnk_03006F80 = 10;
        gGameSubState = 2;
    }
}

void sub_080690C4(void)
{
    sub_0806918C();
    load_battle_sprite_graphics();
    init_battle_background_layers();
    load_bg_tilemaps_and_palette();
    play_song(0);
    setup_screen_transition_effect_080682CC(2, 2, 0);
    play_song(0x13);
    REG_DISPCNT |= 0x1A00;
    gUnk_03006F80 = 11;
    gGameSubState = 1;
}

void sub_08069114(void)
{
    if (sub_0806A230()) {
        REG_BLDY = 0;
        REG_BLDCNT = 0xFF;
        gUnk_03006F88 = 0;
        sound_stop_all_with_fade_guard(0x20);
        gUnk_03006F80 = 12;
        gGameSubState = 2;
    }
}

void sub_08069158(void)
{
    struct Unk_03005310 *p;
    sub_0806918C();
    play_song(0);
    p = &gUnk_03005310;
    p->unk39 = gUnk_03006F94[0] == 1 ? 1 : 2;
    sub_08047850(0);
}

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

void init_battle_background_layers(void)
{
    gUnk_03006F90 = 0;
    decompress_indexed_asset(0, 0, (void *)0x06004000, 9, 0);
    decompress_indexed_asset(gUnk_08486160[gUnk_03006FDC].unk4, 0, (void *)0x06004800, 10, 0);
    decompress_indexed_asset(gUnk_08486160[gUnk_03006FDC].unk8, 0, (void *)0x06005000, 11, 0);
    REG_BG2CNT = 0x1E02;
    gBg2Scroll.x = -24;
    gBg2Scroll.y = -96;
}

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

void init_battle_bg_layer(void)
{
    gUnk_03006F90 = 1;
    REG_BG2CNT = 0x1E0A;
    REG_BG3CNT = 0x1F0B;
    gUnk_03001800.unk38 = gUnk_03006F84;
    decompress_tileset_to_vram(gUnk_03001800.unk38, 0);
    memcpy_bytes_0803F63C(gUnk_083C3B04[gUnk_03001800.unk38], gUnk_03001800.unk39, 8);
    apply_battle_blend_effect_a();
    decompress_to_ewram_27000(gUnk_083B23F8[gUnk_03001800.unk38 * 5 + 1]);
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gVBlankCallback = sub_08043E48;
}

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

void init_battle_sprite_medium(void)
{
    init_battle_sprite_entry_08048818(1, 0xC404, 0x100, 1, 3);
    gUnk_03002C30[1].unk2 = 0x28;
    gUnk_03002C30[1].unk4 = 0x10;
    gUnk_03002C30[1].unk1A = 0;
    DmaSet(3, gUnk_0807C260, 0x05000220, 0x84000008);
}

void init_battle_sprite_c400(void)
{
    init_battle_sprite_entry_08048818(0, 0xC400, 0x104, 0xC, 3);
    gUnk_03002C30[0].unk2 = 0x78;
    gUnk_03002C30[0].unk4 = -16;
    gUnk_03002C30[0].unk1A = 0;
    DmaSet(3, gUnk_0807C280, 0x05000380, 0x84000008);
    DmaSet(3, gUnk_0807C280 + 0x30, 0x05000360, 0x84000008);
}

void init_battle_sprite_entry_1(void)
{
    init_battle_sprite_entry_08048818(1, 0xC808, 0x10B, 3, 3);
    gUnk_03002C30[1].unk4 = 0x40;
    gUnk_03002C30[1].unk1A = 0;
    DmaSet(3, gUnk_0807C2C0, 0x05000260, 0x84000008);
    REG_BLDCNT = 0xC40;
    REG_BLDALPHA = 0x10;
}

void init_battle_sprite_large(void)
{
    init_battle_sprite_entry_08048818(2, 0xCB20, 0x108, 2, 3);
    gUnk_03002C30[2].unk4 = 0xC8;
    gUnk_03002C30[2].unk8 = 0x88;
    gUnk_03002C30[2].unk9 = 0x88;
    gUnk_03002C30[2].unk18 = 0;
    gUnk_03002C30[2].unk1A = 0;
    init_battle_sprite_entry_08048818(3, 0xCB20, 0x109, 2, 3);
    gUnk_03002C30[3].unk4 = 0xC8;
    gUnk_03002C30[3].unk8 = 0x88;
    gUnk_03002C30[3].unk9 = 0x88;
    gUnk_03002C30[3].unk18 = 0;
    gUnk_03002C30[3].unk1A = 0;
    init_battle_sprite_entry_08048818(4, 0xCB20, 0x10A, 2, 3);
    gUnk_03002C30[4].unk4 = 0xC8;
    gUnk_03002C30[4].unk8 = 0x88;
    gUnk_03002C30[4].unk9 = 0x88;
    gUnk_03002C30[4].unk18 = 0;
    gUnk_03002C30[4].unk1A = 0;
    DmaSet(3, gUnk_0807C2A0, 0x05000240, 0x84000008);
}

void get_entity_speed_value(void)
{
    if (gUnk_08486160[gUnk_03006FDC].unk0 != 0)
        gUnk_03006F84 = gUnk_08486160[gUnk_03006FDC].unk1;
    else
        gUnk_03006F84 = gUnk_083F7FF4[(u8)gFrameCounter] % 11;
}

void sub_08069EE4(u8 *dst, u8 *src)
{
    do {
        *dst = *src;
        dst++;
    } while (*src++ <= 0xF8);
}

bool32 sub_08069EF8(void)
{
    switch (gUnk_03006F88) {
    case 0:
        text_window_init(1, 2, 0);
        init_battle_sprite_small();
        sprite_animation_dispatch(0, 1, 0x20, 0x58);
        sub_08069EE4(gUnk_030004DE, (u8 *)gUnk_083BE9E8[gUnk_03006F84]);
        gUnk_03006F88++;
        return FALSE;
    case 1:
        if (run_message(gUnk_084864E8[0]) && gUnk_03002C30[0].unk20 == 0)
            return TRUE;
        break;
    }
    update_sprite_animations_tick_0806AF40();
    update_sprite_animations_0806B334();
    return FALSE;
}

INCLUDE_ASM("asm/nonmatching/code_08067160", sub_08069F80);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_0806A230);
INCLUDE_ASM("asm/nonmatching/code_08067160", sub_0806A4C0);

bool32 race_check_all_finished(void)
{
    if (gUnk_03006F8C[0] > 2 && gUnk_03006F8C[1] > 2 && gUnk_03006F8C[2] > 2) {
        if (++gUnk_03006F88 > 0xF0)
            return TRUE;
    }
    return FALSE;
}

INCLUDE_ASM("asm/nonmatching/code_08067160", update_battle_bot_turn_order_tiles);
INCLUDE_ASM("asm/nonmatching/code_08067160", update_battle_icon_rotation);

void race_update_racer_anim_counters(void)
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

void update_sprite_animations_tick_0806AF40(void)
{
    u8 i;
    for (i = 0; i <= 0x13; i++) {
        if (gUnk_03002C30[i].unk20 != 0) {
            if (gUnk_08485D30[gUnk_03002C30[i].unk20 - 1](i))
                gUnk_03002C30[i].unk1A++;
            else if (gUnk_03002C30[i].unk20 != 0)
                sprite_animation_dispatch(i, 0, 0, 0);
        }
    }
}

bool32 sub_0806AF9C(u8 sprite)
{
    return FALSE;
}

bool32 sub_0806AFA0(u8 sprite)
{
    if (gUnk_03002C30[sprite].unk1A < 0x20) {
        gUnk_03002C30[sprite].unk2++;
        gUnk_03002C30[sprite].unk4 = gUnk_03002C30[sprite].unk23 + 3 - gUnk_08485E84[gUnk_03002C30[sprite].unk1A + 0x20];
    } else if (gUnk_03002C30[sprite].unk1A < 0x30) {
        gUnk_03002C30[sprite].unk4 = gUnk_03002C30[sprite].unk23 + 3;
    } else {
        gUnk_03002C30[sprite].unk2 += 2;
    }
    if (gUnk_03002C30[sprite].unk22 <= gUnk_03002C30[sprite].unk2)
        return FALSE;
    return TRUE;
}

bool32 sub_0806B014(u8 sprite)
{
    gUnk_03002C30[sprite].unk2 += 2;
    if (gUnk_03002C30[sprite].unk22 < gUnk_03002C30[sprite].unk1A)
        return FALSE;
    return TRUE;
}

bool32 sub_0806B03C(u8 sprite)
{
    gUnk_03002C30[sprite].unk2 -= 2;
    if (gUnk_03002C30[sprite].unk22 < gUnk_03002C30[sprite].unk1A)
        return FALSE;
    return TRUE;
}

bool32 sub_0806B064(u8 sprite)
{
    return TRUE;
}

bool32 sub_0806B068(u8 sprite)
{
    if (gUnk_03002C30[sprite].unk1A < 0x10)
        gUnk_03002C30[sprite].unk4 += 2;
    if ((u16)(gUnk_03002C30[sprite].unk1A - 0xD2) < 0x10)
        gUnk_03002C30[sprite].unk4 -= 2;
    if (gUnk_03002C30[sprite].unk1A > 0xE1) {
        sub_0806B584(sprite);
        return FALSE;
    }
    return TRUE;
}

bool32 sub_0806B0B4(u8 sprite)
{
    if (gUnk_03002C30[sprite].unk1A < 0x10)
        REG_BLDALPHA = 0x1000 | gUnk_03002C30[sprite].unk1A;
    else if (gUnk_03002C30[sprite].unk1A < 0x20)
        REG_BLDALPHA = ((0x20 - gUnk_03002C30[sprite].unk1A) << 8) | 0x10;
    if (gUnk_03002C30[sprite].unk1A & 1)
        gUnk_03002C30[sprite].unk4--;
    if (gUnk_03002C30[sprite].unk1A > 0x3F) {
        REG_BLDCNT = 0;
        return FALSE;
    }
    return TRUE;
}

bool32 sub_0806B124(u8 sprite)
{
    if (gUnk_03002C30[sprite].unk1A & 1) {
        gUnk_03002C30[sprite].unk8--;
        gUnk_03002C30[sprite].unk9--;
    }
    gUnk_03002C30[sprite].unk18 += 0x40;
    if (gUnk_03002C30[sprite].unk1A > 0x8F) {
        gUnk_03002C30[sprite].unk18 = 0;
        return FALSE;
    }
    return TRUE;
}

