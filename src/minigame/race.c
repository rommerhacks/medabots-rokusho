// Mode-3 state 4: the race minigame. race_dispatch_substate runs gRaceSubStates; the module loads the course
// BGs and racer sprites, plays the commentary messages and animates the racers until all finish. The tail
// (sprite_animation_dispatch, clear_sprite_entry) is a sprite animator other mode-3 scenes also call.
#include "global.h"

static void sub_0806918C(void);
static void init_battle_bg_layer(void);
static void init_battle_icon_positions(void);
static bool32 sub_08069EF8(void);
static bool32 sub_0806A230(void);
static bool32 race_check_all_finished(void);
static void update_battle_bot_turn_order_tiles(void);
static void update_battle_bot_death_animations(void);
static void update_battle_bot_damage_animations(void);
static void sub_0806B310(void);
static void sprite_animation_dispatch(u8 sprite, u8 a, u8 b, u8 c);

void race_dispatch_substate(void) {
    if (gUnk_03006F90 == 0)
        sub_0806B310();
    gRaceSubStates[gGameSubState]();
}

void sub_08068C6C(void) {
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

void sub_08068CF4(void) {
    if (scene_transition_step_080686F4())
        gGameSubState = gUnk_03006F80;
}

void sub_08068D14(void) {
    if (execute_scene_step()) {
        u32 zero = 0;
        DmaSet(3, &zero, gSpriteEntries, 0x85000800);
        gVBlankCallback = nullsub_08000840;
        REG_DISPCNT &= 0x80FF;
        gGameSubState = gUnk_03006F80;
    }
}

void sub_08068D74(void) {
    if (sub_08069EF8()) {
        gUnk_03006F88 = 0;
        gUnk_03006F80 = 4;
        gGameSubState = 2;
    }
}

void sub_08068DA0(void) {
    REG_BLDCNT = 0xFF;
    REG_BLDY = 0xF;
    race_enter_team_select();
}

void sub_08068DBC(void) {
    int i;
    const u8 *p;

    sub_0806918C();
    load_battle_sprite_graphics();
    init_battle_background_layers();
    load_bg_tilemaps_and_palette();
    play_song(0);
    for (i = 0; i < 3; i++) {
        gUnk_03006FD0[0][i] = gUnk_03001800.unk8C[i];
        gUnk_03006FA0[0][0][i] = gUnk_03001800.unk8F[i][0];
        gUnk_03006FA0[0][1][i] = gUnk_03001800.unk8F[i][1];
        gUnk_03006FA0[0][2][i] = gUnk_03001800.unk8F[i][2];
        gUnk_03006FA0[0][3][i] = gUnk_03001800.unk8F[i][3];
        decompress_sprite_to_vram_08042D94(gUnk_03006FA0[0][0][i], gUnk_03006FA0[0][1][i], gUnk_03006FA0[0][2][i],
                                           gUnk_03006FA0[0][3][i], 2 - i);
    }
    p = gUnk_083C1A00[gUnk_08486160[gUnk_03006FDC].unk2];
    p += 4;
    for (i = 0; i < 3; i++) {
        gUnk_03006FA0[1][0][i] = *p++;
        gUnk_03006FA0[1][1][i] = *p++;
        gUnk_03006FA0[1][2][i] = *p++;
        gUnk_03006FA0[1][3][i] = *p;
        p += 9;
        gUnk_03006FD0[1][i] = gUnk_083B827C[gUnk_03006FA0[1][3][i] * 64 + 0x31] - 0x64;
        decompress_sprite_to_vram_08042D94(gUnk_03006FA0[1][0][i], gUnk_03006FA0[1][1][i], gUnk_03006FA0[1][2][i],
                                           gUnk_03006FA0[1][3][i], 5 - i);
    }
    p = gUnk_083C1A00[gUnk_08486160[gUnk_03006FDC].unk6];
    p += 4;
    for (i = 0; i < 3; i++) {
        gUnk_03006FA0[2][0][i] = *p++;
        gUnk_03006FA0[2][1][i] = *p++;
        gUnk_03006FA0[2][2][i] = *p++;
        gUnk_03006FA0[2][3][i] = *p;
        p += 9;
        gUnk_03006FD0[2][i] = gUnk_083B827C[gUnk_03006FA0[2][3][i] * 64 + 0x31] - 0x64;
        decompress_sprite_to_vram_08042D94(gUnk_03006FA0[2][0][i], gUnk_03006FA0[2][1][i], gUnk_03006FA0[2][2][i],
                                           gUnk_03006FA0[2][3][i], 8 - i);
    }
    play_song(0x13);
    setup_screen_transition_effect_080682CC(2, 2, 0);
    REG_DISPCNT |= 0x1E00;
    gUnk_03006F80 = 6;
    gGameSubState = 1;
}

void sub_08068FD4(void) {
    if (sub_08069F80()) {
        gUnk_03006F88 = 0;
        gUnk_03006F80 = 7;
        gGameSubState = 2;
    }
}

void sub_08069000(void) {
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

void sub_0806904C(void) {
    update_sprite_animations_tick_0806AF40();
    update_sprite_animations_0806B334();
    if (sub_0806A4C0()) {
        gUnk_03006F88 = 0;
        gGameSubState = 9;
    }
}

void race_update(void) {
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

void sub_080690C4(void) {
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

void sub_08069114(void) {
    if (sub_0806A230()) {
        REG_BLDY = 0;
        REG_BLDCNT = 0xFF;
        gUnk_03006F88 = 0;
        sound_stop_all_with_fade_guard(0x20);
        gUnk_03006F80 = 12;
        gGameSubState = 2;
    }
}

void sub_08069158(void) {
    struct Unk_03005310 *p;
    sub_0806918C();
    play_song(0);
    p = &gUnk_03005310;
    p->sceneResult = gUnk_03006F94[0] == 1 ? 1 : 2;
    field_return_from_scene(0);
}

static void sub_0806918C(void) {
    u32 zero = 0;
    DmaSet(3, &zero, 0x06000000, 0x85006000);
    REG_DISPCNT = 0x60;
    zero = 0;
    DmaSet(3, &zero, gSpriteEntries, 0x85000800);
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
}

void init_battle_background_layers(void) {
    gUnk_03006F90 = 0;
    decompress_indexed_asset(0, 0, (void *)0x06004000, 9, 0);
    decompress_indexed_asset(gUnk_08486160[gUnk_03006FDC].unk4, 0, (void *)0x06004800, 10, 0);
    decompress_indexed_asset(gUnk_08486160[gUnk_03006FDC].unk8, 0, (void *)0x06005000, 11, 0);
    REG_BG2CNT = 0x1E02;
    gBg2Scroll.x = -24;
    gBg2Scroll.y = -96;
}

static void dma_copy_tilemap_strip(u8 n) {
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

static void init_battle_bg_layer(void) {
    gUnk_03006F90 = 1;
    REG_BG2CNT = 0x1E0A;
    REG_BG3CNT = 0x1F0B;
    gUnk_03001800.unk38 = gUnk_03006F84;
    decompress_tileset_to_vram(gUnk_03001800.unk38, 0);
    memcpy_bytes_0803F63C(gBattlefieldParams[gUnk_03001800.unk38], gUnk_03001800.unk39, 8);
    apply_battle_blend_effect_a();
    decompress_to_ewram_27000(gUnk_083B23F8[gUnk_03001800.unk38 * 5 + 1]);
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gVBlankCallback = battle_bg_scroll_vblank;
}

void init_battle_field_screen(void) {
    gUnk_03006F90 = 1;
    REG_BG2CNT = 0x1E0A;
    REG_BG3CNT = 0x1F0B;
    gUnk_03001800.unk38 = gUnk_03006F84;
    decompress_sprite_to_vram_08043C08(gUnk_03001800.unk38, 0);
    load_battle_script_entry_b();
    apply_battle_blend_effect_b();
    decompress_to_ewram_27000(gUnk_083B24A8[gUnk_03001800.unk38 * 5 + 1]);
    LZ77UnCompVram(gUnk_087C4EBC, (void *)0x0600C800);
    LZ77UnCompVram(gUnk_087C4F48, (void *)0x0600C880);
    LZ77UnCompVram(gUnk_087C4FDC, (void *)0x0600C9C0);
    LZ77UnCompVram(gUnk_087C51C0, (void *)0x0600CC40);
    DmaSet(3, gUnk_087C5248, 0x05000100, 0x84000008);
    DmaSet(3, gUnk_087C5268, 0x05000120, 0x84000008);
    DmaSet(3, gUnk_087C5288, 0x05000140, 0x84000008);
    DmaSet(3, gUnk_087C52A8, 0x05000160, 0x84000008);
    write_tilemap_tiles_dma(0, 2, 4);
    write_tilemap_tiles_dma(0, 2, 7);
    write_tilemap_tiles_dma(0, 2, 0xA);
    write_tilemap_tiles_dma(1, 6, 3);
    write_tilemap_tiles_dma(2, 0xE, 3);
    write_tilemap_tiles_dma(3, 0x1A, 4);
    write_tilemap_tiles_dma(3, 0x1A, 7);
    write_tilemap_tiles_dma(3, 0x1A, 0xA);
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
    gVBlankCallback = battle_vblank_update_bg;
}

void init_battle_bg_layer1(void) {
    vu16 zero = 0;
    DmaSet(3, &zero, 0x0600E800, 0x81000400);
    LZ77UnCompVram(gUnk_087C52C8, (void *)0x0600CD00);
    LZ77UnCompVram(gUnk_087C5518, (void *)0x0600D0A0);
    DmaSet(3, gUnk_087C55D0, 0x05000180, 0x84000008);
    DmaSet(3, gUnk_087C55F0, 0x050001A0, 0x84000008);
    write_tilemap_tiles_dma(4, 1, 0xE);
    write_tilemap_tiles_dma(4, 0xB, 0xE);
    write_tilemap_tiles_dma(4, 0x15, 0xE);
    REG_BG1CNT = 0x1D0D;
    sprite_entry_init(1, 0xC400, 0x6F, 8, 1);
    gSpriteEntries[1].unk2 = 0xF;
    gSpriteEntries[1].unk4 = 0x7F;
    sprite_entry_init(2, 0xC400, 0x7B, 9, 1);
    gSpriteEntries[2].unk2 = 0x5F;
    gSpriteEntries[2].unk4 = 0x7F;
    sprite_entry_init(3, 0xC400, 0x87, 10, 1);
    gSpriteEntries[3].unk2 = 0xAF;
    gSpriteEntries[3].unk4 = 0x7F;
}

static inline u32 tilemap_addr(u32 base, u16 col, u16 row) {
    base += col * 2;
    return row * 64 + base;
}

void write_tilemap_tiles_dma(u8 type, u8 x, u8 y) {
    u8 w[8];
    u8 h[8];
    u16 first[8];
    struct U16PtrArray8 lists;
    u16 pal[8];
    const u16 *p;
    int i, j;
    u16 tile;

    memcpy_optimized(w, gUnk_080AFEE0, 8);
    memcpy_optimized(h, gUnk_080AFEE8, 8);
    memcpy_optimized(first, gUnk_080AFEF0, 16);
    lists = gUnk_080AFF00;
    memcpy_optimized(pal, gUnk_080AFF20, 16);

    type &= 7;
    p = lists.v[type];
    for (i = 0; i < h[type]; i++) {
        for (j = 0; j < w[type]; j++) {
            if (type > 4)
                tile = i * 6 + j + first[type] + pal[type];
            else
                tile = *p + first[type] + pal[type];
            if (type <= 3)
                DmaSet(3, &tile, tilemap_addr(0x0600F800, x + j, i + y),
                       0x80000001) else DmaSet(3, &tile, tilemap_addr(0x0600E800, x + j, i + y), 0x80000001) p++;
        }
    }
}

void load_bg_tilemaps_and_palette(void) {
    u16 buf[0x400];
    vu32 zero;
    int i;
    LZ77UnCompVram(gUnk_087B2CCC, (void *)0x0600C000);
    zero = 0;
    DmaSet(3, &zero, buf, 0x85000200);
    LZ77UnCompVram(gUnk_087B3710, buf);
    for (i = 0; i < 0x280; i++)
        buf[i] += 0xC000;
    DmaSet(3, buf, 0x0600E800, 0x80000400);
    LZ77UnCompVram(gUnk_087B384C, buf);
    for (i = 0; i < 0x400; i++)
        buf[i] += 0xC000;
    DmaSet(3, buf, 0x0600F800, 0x80000400);
    DmaSet(3, gUnk_087B3AF0, 0x05000180, 0x80000020);
    REG_BG1CNT = 0x1D0D;
    REG_BG3CNT = 0x1F0F;
}

void load_battle_sprite_graphics(void) {
    const u8 *e;
    LZ77UnCompVram(gUnk_083F80F4[0x25], (void *)0x06012400);
    DmaSet(3, gUnk_083F8634[0x25], 0x05000200, 0x80000010);
    LZ77UnCompVram(gUnk_087AD4E4, (void *)0x06012E00);
    LZ77UnCompVram(gUnk_083F80F4[0], (void *)0x06015100);
    DmaSet(3, gUnk_083F8634[0], 0x05000300, 0x84000008);
    e = gUnk_083C1A00[gUnk_08486160[gUnk_03006FDC].unk2];
    LZ77UnCompVram(gUnk_083F80F4[e[0]], (void *)0x06015A00);
    DmaSet(3, gUnk_083F8634[e[0]], 0x05000320, 0x84000008);
    e = gUnk_083C1A00[gUnk_08486160[gUnk_03006FDC].unk6];
    LZ77UnCompVram(gUnk_083F80F4[e[0]], (void *)0x06016300);
    DmaSet(3, gUnk_083F8634[e[0]], 0x05000340, 0x84000008);
    DmaSet(3, gUnk_0807C300, 0x050003A0, 0x84000008);
}

void divide_by_3(u8 idx, u8 b) {
    u8 n = 3;
    int k;
    u8 q = idx / 3;
    u8 r = idx % 3;
    struct ByteTable3 t;
    memcpy_optimized(&t, &gUnk_080AFF30, 3);
    setup_battle_sprite_group(gUnk_03006FA0[q][0][r], gUnk_03006FA0[q][1][r], gUnk_03006FA0[q][2][r],
                              gUnk_03006FA0[q][3][r], q * 3 - (k = r - 2), gUnk_08485CC4[q][r] - 3,
                              gSpriteEntries[gUnk_08485CC4[q][r]].unk2, t.b[q], b, n, 5);
}

static void sub_08069A68(u8 idx, s16 x, s16 y, u8 h, u8 pal) {
    int k;
    u8 q = idx / 3;
    u8 r = idx % 3;
    init_battle_medabot_sprites(gUnk_03006FA0[q][0][r], gUnk_03006FA0[q][1][r], gUnk_03006FA0[q][2][r],
                                gUnk_03006FA0[q][3][r], q * 3 - (k = r - 2), gUnk_08485CC4[q][r] - 3, x, y, h, 3, 5);
    battle_sprite_group_set_anim(gUnk_08485CC4[q][r] - 3, pal);
}

static void init_battle_icon_positions(void) {
    int i;

    sub_08069A68(0, 0x2C, 0x22, 0, 4);
    sub_08069A68(1, -32, 0x22, 0, 4);
    sub_08069A68(2, -32, 0x22, 0, 4);
    i = 4;
    sub_08069A68(3, 0x2C, 0x3A, 0, i);
    i = 6;
    sub_08069A68(4, -32, 0x3A, 0, 4);
    sub_08069A68(5, -32, 0x3A, 0, 4);
    sub_08069A68(i, 0x2C, 0x52, 0, 4);
    sub_08069A68(7, -32, 0x52, 0, 4);
    sub_08069A68(8, -32, 0x52, 0, 4);
    // original passes i + 20 untruncated: compiled against an int prototype
    for (i = 0; i <= 8; i++)
        ((void (*)(int, int, int, int, int))sprite_entry_init)(i + 20, 0xCC00, 0x110, 0xD, 3);
    for (i = 0; i <= 2; i++) {
        gSpriteEntries[20 + i * 3].unk2 = 0x2C;
        gSpriteEntries[21 + i * 3].unk2 = -32;
        gSpriteEntries[22 + i * 3].unk2 = -32;
        gSpriteEntries[20 + i].unk4 = 0x2D;
        gSpriteEntries[23 + i].unk4 = 0x45;
        gSpriteEntries[26 + i].unk4 = 0x5D;
    }
    DmaSet(3, gUnk_0850DEF8, 0x05000200, 0x84000040);
}

static void init_battle_sprite_small(void) {
    sprite_entry_init(0, 0xC004, 0x33, 0, 1);
    gSpriteEntries[0].unk2 = -16;
}

static void init_battle_sprite_medium(void) {
    sprite_entry_init(1, 0xC404, 0x100, 1, 3);
    gSpriteEntries[1].unk2 = 0x28;
    gSpriteEntries[1].unk4 = 0x10;
    gSpriteEntries[1].unk1A = 0;
    DmaSet(3, gUnk_0807C260, 0x05000220, 0x84000008);
}

static void init_battle_sprite_c400(void) {
    sprite_entry_init(0, 0xC400, 0x104, 0xC, 3);
    gSpriteEntries[0].unk2 = 0x78;
    gSpriteEntries[0].unk4 = -16;
    gSpriteEntries[0].unk1A = 0;
    DmaSet(3, gUnk_0807C280, 0x05000380, 0x84000008);
    DmaSet(3, gUnk_0807C280 + 0x30, 0x05000360, 0x84000008);
}

static void init_battle_sprite_entry_1(void) {
    sprite_entry_init(1, 0xC808, 0x10B, 3, 3);
    gSpriteEntries[1].unk4 = 0x40;
    gSpriteEntries[1].unk1A = 0;
    DmaSet(3, gUnk_0807C2C0, 0x05000260, 0x84000008);
    REG_BLDCNT = 0xC40;
    REG_BLDALPHA = 0x10;
}

static void init_battle_sprite_large(void) {
    sprite_entry_init(2, 0xCB20, 0x108, 2, 3);
    gSpriteEntries[2].unk4 = 0xC8;
    gSpriteEntries[2].unk8 = 0x88;
    gSpriteEntries[2].unk9 = 0x88;
    gSpriteEntries[2].unk18 = 0;
    gSpriteEntries[2].unk1A = 0;
    sprite_entry_init(3, 0xCB20, 0x109, 2, 3);
    gSpriteEntries[3].unk4 = 0xC8;
    gSpriteEntries[3].unk8 = 0x88;
    gSpriteEntries[3].unk9 = 0x88;
    gSpriteEntries[3].unk18 = 0;
    gSpriteEntries[3].unk1A = 0;
    sprite_entry_init(4, 0xCB20, 0x10A, 2, 3);
    gSpriteEntries[4].unk4 = 0xC8;
    gSpriteEntries[4].unk8 = 0x88;
    gSpriteEntries[4].unk9 = 0x88;
    gSpriteEntries[4].unk18 = 0;
    gSpriteEntries[4].unk1A = 0;
    DmaSet(3, gUnk_0807C2A0, 0x05000240, 0x84000008);
}

void get_entity_speed_value(void) {
    if (gUnk_08486160[gUnk_03006FDC].unk0 != 0)
        gUnk_03006F84 = gUnk_08486160[gUnk_03006FDC].unk1;
    else
        gUnk_03006F84 = gRandomBytes[(u8)gFrameCounter] % 11;
}

static void sub_08069EE4(u8 *dst, u8 *src) {
    do {
        *dst = *src;
        dst++;
    } while (*src++ <= 0xF8);
}

static bool32 sub_08069EF8(void) {
    switch (gUnk_03006F88) {
    case 0:
        text_window_init(1, 2, 0);
        init_battle_sprite_small();
        sprite_animation_dispatch(0, 1, 0x20, 0x58);
        sub_08069EE4(gUnk_030004DE, (u8 *)gUnk_083BE9E8[gUnk_03006F84]);
        gUnk_03006F88++;
        return FALSE;
    case 1:
        if (run_message(gUnk_084864E8[0]) && gSpriteEntries[0].unk20 == 0)
            return TRUE;
        break;
    }
    update_sprite_animations_tick_0806AF40();
    update_sprite_animations_0806B334();
    return FALSE;
}

bool32 sub_08069F80(void) {
    const u8 *e;
    switch (gUnk_03006F88) {
    case 0:
        text_window_init(1, 2, 0);
        init_battle_sprite_small();
        sprite_animation_dispatch(0, 1, 0x18, 0x58);
        REG_DISPCNT |= 0x400;
        gUnk_03006F88++;
        return FALSE;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        dma_copy_tilemap_strip(gUnk_03006F88 - 6);
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        run_message(gUnk_084864E8[1]);
        gUnk_03006F88++;
        break;
    case 14:
        if (run_message(gUnk_084864E8[1])) {
            message_next();
            init_battle_sprite_medium();
            sprite_animation_dispatch(1, 4, 0, 0);
            gUnk_03006F88++;
        }
        break;
    case 15:
        if (run_message(gUnk_084864E8[2])) {
            message_next();
            gUnk_03006F88++;
        }
        break;
    case 16:
        if (gSpriteEntries[0].unk20 == 0)
            gUnk_03006F88++;
        break;
    case 17:
        if (run_message(gUnk_084864E8[5])) {
            message_next();
            e = gUnk_083C1A00[gUnk_08486160[gUnk_03006FDC].unk2];
            sub_08069EE4(gUnk_030004DE, (u8 *)gUnk_083C3F38[e[0]]);
            sprite_animation_dispatch(0, 2, 0x40, 0);
            gSpriteEntries[1].unk2 = 0x68;
            gUnk_03006F88++;
        }
        break;
    case 18:
        if (run_message(gUnk_084864E8[3]) && gSpriteEntries[0].unk20 == 0) {
            message_next();
            gUnk_03006F88++;
        }
        break;
    case 19:
        if (run_message(gUnk_084864E8[gUnk_08486160[gUnk_03006FDC].unk9])) {
            message_next();
            e = gUnk_083C1A00[gUnk_08486160[gUnk_03006FDC].unk6];
            sub_08069EE4(gUnk_030004DE, (u8 *)gUnk_083C3F38[e[0]]);
            sprite_animation_dispatch(0, 2, 0x40, 0);
            gSpriteEntries[1].unk2 = 0xA8;
            gUnk_03006F88++;
        }
        break;
    case 20:
        if (run_message(gUnk_084864E8[4]) && gSpriteEntries[0].unk20 == 0) {
            message_next();
            gUnk_03006F88++;
        }
        break;
    case 21:
        if (run_message(gUnk_084864E8[gUnk_08486160[gUnk_03006FDC].unk9 + 1])) {
            message_next();
            gUnk_03006F88++;
        }
        break;
    case 22:
        if (run_message(gUnk_084864E8[6]))
            return TRUE;
        break;
    }
    update_sprite_animations_tick_0806AF40();
    update_sprite_animations_0806B334();
    return FALSE;
}

static bool32 sub_0806A230(void) {
    const u8 *e;
    switch (gUnk_03006F88) {
    case 0:
        text_window_init(1, 2, 0);
        init_battle_sprite_small();
        play_sound_effect(0x15);
        if (gUnk_03006F94[0] == 1) {
            sprite_animation_dispatch(0, 1, 0x18, 0x58);
            sub_08069EE4(gUnk_030004DE, gUnk_03002B74);
        } else if (gUnk_03006F94[0] == 2) {
            sprite_animation_dispatch(0, 1, 0x58, 0x58);
            e = gUnk_083C1A00[gUnk_08486160[gUnk_03006FDC].unk2];
            sub_08069EE4(gUnk_030004DE, (u8 *)gUnk_083C3F38[e[0]]);
        } else if (gUnk_03006F94[0] == 3) {
            sprite_animation_dispatch(0, 1, 0x98, 0x58);
            e = gUnk_083C1A00[gUnk_08486160[gUnk_03006FDC].unk6];
            sub_08069EE4(gUnk_030004DE, (u8 *)gUnk_083C3F38[e[0]]);
        }
        REG_DISPCNT |= 0x400;
        gUnk_03006F88++;
        return FALSE;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        if (gUnk_03006F88 == 6) {
            init_battle_sprite_large();
            sprite_animation_dispatch(4, 7, 2, 0);
            gSpriteEntries[4].unk2 = (gUnk_03006F94[2] - 1) * 64 + 0x38;
            gSpriteEntries[4].unk4 = 0x18;
            sprite_animation_dispatch(3, 7, 1, 0);
            gSpriteEntries[3].unk2 = (gUnk_03006F94[1] - 1) * 64 + 0x38;
            gSpriteEntries[3].unk4 = 0x18;
            sprite_animation_dispatch(2, 7, 0, 0);
            gSpriteEntries[2].unk2 = (gUnk_03006F94[0] - 1) * 64 + 0x38;
            gSpriteEntries[2].unk4 = 0x18;
        }
        dma_copy_tilemap_strip(gUnk_03006F88 - 6);
    default:
        run_message(gUnk_084864E8[0x1E]);
        gUnk_03006F88++;
        break;
    case 0x96:
        play_sound_effect(0x16);
        REG_BLDCNT = 0x7F;
        init_battle_sprite_entry_1();
        sprite_animation_dispatch(1, 6, 0, 0);
        gSpriteEntries[1].unk2 = (gUnk_03006F94[0] - 1) * 64 + 0x18;
        message_next();
        gUnk_03006F88++;
        break;
    case 0x97:
        if (run_message(gUnk_084864E8[7]) && gSpriteEntries[1].unk20 == 0) {
            message_next();
            if (gUnk_03006F94[0] == 1)
                gUnk_03006F88++;
            else
                gUnk_03006F88 += 2;
        }
        break;
    case 0x98:
        if (run_message(gUnk_084864E8[8]))
            return TRUE;
        break;
    case 0x99:
        if (run_message(gUnk_084864E8[9]))
            return TRUE;
        break;
    }
    update_sprite_animations_tick_0806AF40();
    update_sprite_animations_0806B334();
    return FALSE;
}

bool32 sub_0806A4C0(void) {
    switch (gUnk_03006F88) {
    case 0:
        init_battle_sprite_c400();
        sprite_animation_dispatch(0, 5, 0, 0);
        gUnk_03006F88++;
        break;
    case 1:
        if (gSpriteEntries[0].unk1A == 0xB4) {
            play_sound_effect(0x42);
            battle_sprite_group_set_anim(0x26, 0xC);
            battle_sprite_group_set_anim(0x32, 0xC);
            battle_sprite_group_set_anim(0x3E, 0xC);
            sprite_animation_dispatch(1, 0xA, 0, 0);
            sprite_animation_dispatch(2, 0xA, 1, 0);
            sprite_animation_dispatch(3, 0xA, 2, 0);
            gUnk_03006FF8[0] = gUnk_03006FF8[1] = 0;
            gUnk_03007000[0] = gUnk_03007000[1] = 0;
            gUnk_03006FE0[0] = gUnk_03006FE0[1] = gUnk_03006FE0[2] = 0;
            gUnk_03006FEC[0] = gUnk_03006FEC[1] = gUnk_03006FEC[2] = 0x20;
            gUnk_03006FF0[0] = gUnk_03006FF0[1] = gUnk_03006FF0[2] = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static bool32 race_check_all_finished(void) {
    if (gUnk_03006F8C[0] > 2 && gUnk_03006F8C[1] > 2 && gUnk_03006F8C[2] > 2) {
        if (++gUnk_03006F88 > 0xF0)
            return TRUE;
    }
    return FALSE;
}

static void update_battle_bot_turn_order_tiles(void) {
    int i, j, rank;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03006F8C[i] > 2) {
            if (gUnk_03006F94[0] == i + 1)
                write_tilemap_tiles_dma(5, i * 10 + 5, 0xF);
            else if (gUnk_03006F94[1] == i + 1)
                write_tilemap_tiles_dma(6, i * 10 + 5, 0xF);
            else if (gUnk_03006F94[2] == i + 1)
                write_tilemap_tiles_dma(7, i * 10 + 5, 0xF);
        } else {
            for (j = 0, rank = 5; j <= 2; j++) {
                if (i != j) {
                    if (gUnk_03006F8C[i] < gUnk_03006F8C[j])
                        rank++;
                    else if (gUnk_03006F8C[i] == gUnk_03006F8C[j]) {
                        if (gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A ==
                            gSpriteEntries[gUnk_08485CC4[j][gUnk_03006F8C[j]]].unk1A) {
                            if (j < i)
                                rank++;
                        } else if (gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A <
                                   gSpriteEntries[gUnk_08485CC4[j][gUnk_03006F8C[j]]].unk1A)
                            rank++;
                    }
                }
            }
            write_tilemap_tiles_dma(rank, i * 10 + 5, 0xF);
        }
    }
}

void update_battle_icon_rotation(void) {
    int i, j;
    if (gUnk_03006F8C[0] <= 2 && (*(u8 *)&gNewKeys & 1)) {
        if ((u8)(gUnk_03006FEC[0] -= 4) < 4)
            gUnk_03006FEC[0] = 4;
        gSpriteEntries[gUnk_08485CC4[0][gUnk_03006F8C[0]]].unk1A += 3;
    }
    for (i = 1; i <= 2; i++) {
        if (gUnk_03006F8C[i] <= 2) {
            if ((((gJumpArcTable[0])[(gUnk_08485CCD[gUnk_03006F84 + (j = i - 1) * 11] + gUnk_03007000[i - 1]) & 0xFF] >>
                  5) &
                 7) +
                    6 <=
                ++gUnk_03006FF8[i - 1]) {
                if ((u8)(gUnk_03006FEC[i] -= 4) < 4)
                    gUnk_03006FEC[i] = 4;
                gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A += 3;
                gUnk_03006FF8[i - 1] = 0;
                gUnk_03007000[i - 1]++;
            }
        }
    }
    for (i = 0; i <= 2; i++) {
        if (gUnk_03006F8C[i] <= 2) {
            if (gUnk_03006FEC[i] == 0x20) {
                sprite_animation_dispatch(i + 1, 10, i, 0);
                gUnk_03006FF0[i] = 0;
            } else if (gUnk_03006FEC[i] <= gUnk_03006FF0[i]) {
                gSpriteEntries[i + 1].unk27 += 2;
                gUnk_03006FF0[i] = 0;
            } else
                gUnk_03006FF0[i]++;
        }
    }
    if (!(gFrameCounter & 7)) {
        for (i = 0; i <= 2; i++) {
            if ((u8)(gUnk_03006FEC[i] += 2) > 0x20)
                gUnk_03006FEC[i] = 0x20;
        }
    }
}

void race_update_racer_anim_counters(void) {
    int i;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03006F8C[i] <= 2) {
            if (gUnk_08485CE3[gUnk_03006F84][gUnk_03006FD0[i][gUnk_03006F8C[i]]] <= ++gUnk_03006FE0[i]) {
                gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A++;
                gUnk_03006FE0[i] = 0;
            }
        }
    }
}

static inline int sub2(int x) {
    return x - 2;
}
static inline int add14(int x) {
    return x + 0x14;
}

void update_battle_bot_entry_animations(void) {
    int i, k;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03006F8C[i] > 2)
            continue;
        if (gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A > 0x2AF) {
            battle_sprite_group_set_anim(gUnk_08485CC4[i][gUnk_03006F8C[i]] - 3, 4);
            gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk2A = 1;
            if (++gUnk_03006F8C[i] > 2) {
                sprite_animation_dispatch(i + 1, 0, 0, 0);
                if (gUnk_03006F94[0] == 0) {
                    gUnk_03006F94[0] = i + 1;
                    for (k = 0; k <= 15; k++) {
                        u8 r = gRandomBytes[(gFrameCounter + k) & 0xFF];
                        r &= 3;
                        // the original passes k + 4 untruncated: called without (or with an int-slot) prototype
                        ((void (*)())sprite_entry_init)(k + 4, 0xC400, r + 0x10C, 0xB, 3);
                        gSpriteEntries[k + 4].unkB = 0x64;
                        sprite_animation_dispatch(k + 4, 8, r, (k * 16) & 0x7F);
                    }
                } else if (gUnk_03006F94[1] == 0)
                    gUnk_03006F94[1] = i + 1;
                else if (gUnk_03006F94[2] == 0)
                    gUnk_03006F94[2] = i + 1;
                play_sound_effect(0x43);
                continue;
            }
            play_sound_effect(0x44);
            gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A = 0;
            gUnk_03006FEC[i] = 0x20;
            gUnk_03006FF0[i] = 0;
        }
        if (gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk3A <= 0x157 &&
            gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A > 0x157) {
            divide_by_3(i * 3 + gUnk_03006F8C[i], 1);
            gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]] - 3].unkB -= 4;
            gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]] - 2].unkB -= 4;
            gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]] - 1].unkB -= 4;
            gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unkB -= 4;
            if (gUnk_03006F8C[i] <= 1)
                gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2A = 2;
        }
        if (gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A > 0x158)
            gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk2 =
                0xD8 - ((gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A - 0x158) >> 1);
        else {
            gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk2 =
                (gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A >> 1) + 0x2C;
            if (gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk3A <= 0x97 &&
                gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A > 0x97 && gUnk_03006F8C[i] <= 1) {
                gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2A = 1;
                battle_sprite_group_set_anim(gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3, 4);
            }
        }
        gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk3A =
            gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A;
        gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk1A++;
        update_battle_sprite_orbiting_positions(gUnk_08485CC4[i][gUnk_03006F8C[i]] - 3, i * 3 - sub2(gUnk_03006F8C[i]),
                                                0);
        gSpriteEntries[i * 3 + add14(gUnk_03006F8C[i])].unk2 = gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i]]].unk2;
    }
}

// Inline helpers: the original evaluates these offsets separately (no fold into the index).
static inline int sub1(int x) {
    return x - 1;
}

static void update_battle_bot_death_animations(void) {
    int i, t;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03006F8C[i] > 1)
            continue;
        if (gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2A == 1) {
            update_battle_sprite_orbiting_positions(gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3,
                                                    i * 3 - sub1(gUnk_03006F8C[i]), 0);
            gSpriteEntries[gUnk_03006F8C[i] + i * 3 + 0x15].unk2 =
                gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2;
            if (gFrameCounter & 1) {
                if (++gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2 == 0x18) {
                    gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2A = 0;
                    init_battle_medabot_sprites(
                        gUnk_03006FA0[i][0][gUnk_03006F8C[i] + 1], gUnk_03006FA0[i][1][gUnk_03006F8C[i] + 1],
                        gUnk_03006FA0[i][2][gUnk_03006F8C[i] + 1], gUnk_03006FA0[i][3][gUnk_03006F8C[i] + 1],
                        i * 3 - (t = gUnk_03006F8C[i] - 1), gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3,
                        gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3].unk2,
                        gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3].unk4 + 3, 0, 3, 5);
                    battle_sprite_group_set_anim(gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3, 8);
                }
            }
        } else if (gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2A == 2) {
            update_battle_sprite_orbiting_positions(gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3,
                                                    i * 3 - sub1(gUnk_03006F8C[i]), 0);
            gSpriteEntries[gUnk_03006F8C[i] + i * 3 + 0x15].unk2 =
                gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2;
            if (gFrameCounter & 1) {
                if (++gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2 == 0x2C) {
                    gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1]].unk2A = 0;
                    init_battle_medabot_sprites(
                        gUnk_03006FA0[i][0][gUnk_03006F8C[i] + 1], gUnk_03006FA0[i][1][gUnk_03006F8C[i] + 1],
                        gUnk_03006FA0[i][2][gUnk_03006F8C[i] + 1], gUnk_03006FA0[i][3][gUnk_03006F8C[i] + 1],
                        i * 3 - (t = gUnk_03006F8C[i] - 1), gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3,
                        gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3].unk2,
                        gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3].unk4 + 3, 0, 3, 5);
                    battle_sprite_group_set_anim(gUnk_08485CC4[i][gUnk_03006F8C[i] + 1] - 3, 0xC);
                }
            }
        }
    }
}

static void update_battle_bot_damage_animations(void) {
    int i, k;
    for (i = 0; i < 3; i++) {
        if (gUnk_03006F8C[i] != 0) {
            if (gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i] - 1]].unk2A == 1) {
                if (--gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i] - 1]].unk2 <= -16)
                    gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i] - 1]].unk2A = 0;
                update_battle_sprite_orbiting_positions(gUnk_08485CC4[i][gUnk_03006F8C[i] - 1] - 3,
                                                        i * 3 - (k = gUnk_03006F8C[i] - 3), 0);
                gSpriteEntries[gUnk_03006F8C[i] + i * 3 + 0x13].unk2 =
                    gSpriteEntries[gUnk_08485CC4[i][gUnk_03006F8C[i] - 1]].unk2;
            }
        }
    }
}

void update_sprite_animations_tick_0806AF40(void) {
    u8 i;
    for (i = 0; i <= 0x13; i++) {
        if (gSpriteEntries[i].unk20 != 0) {
            if (gUnk_08485D30[gSpriteEntries[i].unk20 - 1](i))
                gSpriteEntries[i].unk1A++;
            else if (gSpriteEntries[i].unk20 != 0)
                sprite_animation_dispatch(i, 0, 0, 0);
        }
    }
}

bool32 sub_0806AF9C(u8 sprite) {
    return FALSE;
}

bool32 sub_0806AFA0(u8 sprite) {
    if (gSpriteEntries[sprite].unk1A < 0x20) {
        gSpriteEntries[sprite].unk2++;
        gSpriteEntries[sprite].unk4 =
            gSpriteEntries[sprite].unk23 + 3 - gHalfSineArc[gSpriteEntries[sprite].unk1A + 0x20];
    } else if (gSpriteEntries[sprite].unk1A < 0x30) {
        gSpriteEntries[sprite].unk4 = gSpriteEntries[sprite].unk23 + 3;
    } else {
        gSpriteEntries[sprite].unk2 += 2;
    }
    if (gSpriteEntries[sprite].unk22 <= gSpriteEntries[sprite].unk2)
        return FALSE;
    return TRUE;
}

bool32 sub_0806B014(u8 sprite) {
    gSpriteEntries[sprite].unk2 += 2;
    if (gSpriteEntries[sprite].unk22 < gSpriteEntries[sprite].unk1A)
        return FALSE;
    return TRUE;
}

bool32 sub_0806B03C(u8 sprite) {
    gSpriteEntries[sprite].unk2 -= 2;
    if (gSpriteEntries[sprite].unk22 < gSpriteEntries[sprite].unk1A)
        return FALSE;
    return TRUE;
}

bool32 sub_0806B064(u8 sprite) {
    return TRUE;
}

bool32 sub_0806B068(u8 sprite) {
    if (gSpriteEntries[sprite].unk1A < 0x10)
        gSpriteEntries[sprite].unk4 += 2;
    if ((u16)(gSpriteEntries[sprite].unk1A - 0xD2) < 0x10)
        gSpriteEntries[sprite].unk4 -= 2;
    if (gSpriteEntries[sprite].unk1A > 0xE1) {
        clear_sprite_entry(sprite);
        return FALSE;
    }
    return TRUE;
}

bool32 sub_0806B0B4(u8 sprite) {
    if (gSpriteEntries[sprite].unk1A < 0x10)
        REG_BLDALPHA = 0x1000 | gSpriteEntries[sprite].unk1A;
    else if (gSpriteEntries[sprite].unk1A < 0x20)
        REG_BLDALPHA = ((0x20 - gSpriteEntries[sprite].unk1A) << 8) | 0x10;
    if (gSpriteEntries[sprite].unk1A & 1)
        gSpriteEntries[sprite].unk4--;
    if (gSpriteEntries[sprite].unk1A > 0x3F) {
        REG_BLDCNT = 0;
        return FALSE;
    }
    return TRUE;
}

bool32 sub_0806B124(u8 sprite) {
    if (gSpriteEntries[sprite].unk1A & 1) {
        gSpriteEntries[sprite].unk8--;
        gSpriteEntries[sprite].unk9--;
    }
    gSpriteEntries[sprite].unk18 += 0x40;
    if (gSpriteEntries[sprite].unk1A > 0x8F) {
        gSpriteEntries[sprite].unk18 = 0;
        return FALSE;
    }
    return TRUE;
}

u32 update_sprite_position_sincos(u8 i) {
#define S gSpriteEntries[i]
    S.unkC_8 += gJumpArcTable[0][(S.unk23 + 0x40) & 0xFF];
    S.unk10_8 += gJumpArcTable[0][S.unk23];
    if (i > 11) {
        S.unk2 = S.unkC_8 / 256 + 0x20;
        S.unk4 = 0x10 - S.unk10_8 / 256;
    } else {
        S.unk2 = S.unkC_8 / 128 + 0x20;
        S.unk4 = 0x10 - S.unk10_8 / 128;
    }
    if (S.unk1A > 8) {
        S.unk1A = gRandomBytes[(gFrameCounter + i) & 0xFF] >> 3;
        S.unk20 = 9;
    }
    return 1;
#undef S
}

u32 sub_0806B244(u8 i) {
#define S gSpriteEntries[i]
    u32 phase = (S.unk1A + 0x10) & 0x3F;

    if (S.unk4 > 0x60) {
        S.unk4 = 0xC8;
        return 0;
    }
    if (S.unk1A & 1)
        S.unk4++;
    if (phase & 0x10) {
        if (S.unk1A & 1) {
            if (i & 1)
                S.unk2++;
            else
                S.unk2--;
        }
    } else {
        if (S.unk1A & 1) {
            if (i & 1)
                S.unk2--;
            else
                S.unk2++;
        }
    }
    if (S.unk1A & 8)
        S.unk0 |= 0x1000;
    else
        S.unk0 &= 0xEFFF;
    return 1;
#undef S
}

u32 sub_0806B2F0(u8 i) {
    if (gSpriteEntries[i].unk27)
        gSpriteEntries[i].unk27--;
    return 1;
}

static void sub_0806B310(void) {
    if (gFrameCounter & 1) {
        gBg3Scroll.x--;
        gBg3Scroll.y++;
    }
}

void update_sprite_animations_0806B334(void) {
    u8 i;

    for (i = 0; i < 20; i++) {
        struct SpriteEntry *s = &gSpriteEntries[i];
        if (s->unk21 != 0) {
            const struct SpriteAnimFrame *tbl = gUnk_08485D5C;
            if (tbl[s->unk21].duration <= s->unk27++) {
                s->unk27 = 0;
                s->unk21 = tbl[s->unk21].next;
                s->unk6 = tbl[s->unk21].frame;
            }
        }
    }
}

static void sprite_animation_dispatch(u8 sprite, u8 type, u8 a, u8 b) {
    if (type == 0) {
        gSpriteEntries[sprite].unk20 = 0;
        gSpriteEntries[sprite].unk21 = 0;
        gSpriteEntries[sprite].unk22 = 0;
        gSpriteEntries[sprite].unk6 = gSpriteEntries[sprite].unk30;
        gSpriteEntries[sprite].unk1A = 0;
        return;
    }
    if (gSpriteEntries[sprite].unk20 != 0)
        return;
    switch (type) {
    case 1:
        gSpriteEntries[sprite].unk20 = 1;
        gSpriteEntries[sprite].unk21 = 1;
        gSpriteEntries[sprite].unk22 = a;
        gSpriteEntries[sprite].unk23 = b;
        gSpriteEntries[sprite].unk30 = 0x33;
        gSpriteEntries[sprite].unk6 = gUnk_08485D5C[1].frame;
        break;
    case 2:
        gSpriteEntries[sprite].unk20 = 2;
        gSpriteEntries[sprite].unk21 = 3;
        gSpriteEntries[sprite].unk22 = a >> 1;
        gSpriteEntries[sprite].unk30 = 0x33;
        gSpriteEntries[sprite].unk6 = gUnk_08485D5C[3].frame;
        break;
    case 3:
        gSpriteEntries[sprite].unk20 = 3;
        gSpriteEntries[sprite].unk21 = 7;
        gSpriteEntries[sprite].unk22 = a >> 1;
        gSpriteEntries[sprite].unk30 = 0x33;
        gSpriteEntries[sprite].unk6 = gUnk_08485D5C[7].frame;
        break;
    case 4:
        gSpriteEntries[sprite].unk20 = 4;
        gSpriteEntries[sprite].unk21 = 0xB;
        gSpriteEntries[sprite].unk22 = a;
        gSpriteEntries[sprite].unk30 = 0x100;
        gSpriteEntries[sprite].unk6 = gUnk_08485D5C[0xB].frame;
        break;
    case 5:
        gSpriteEntries[sprite].unk20 = 5;
        gSpriteEntries[sprite].unk21 = 0xF;
        gSpriteEntries[sprite].unk22 = a;
        gSpriteEntries[sprite].unk30 = 0x107;
        gSpriteEntries[sprite].unk6 = gUnk_08485D5C[0xF].frame;
        break;
    case 6:
        gSpriteEntries[sprite].unk20 = 6;
        gSpriteEntries[sprite].unk21 = 0;
        gSpriteEntries[sprite].unk22 = a;
        gSpriteEntries[sprite].unk30 = 0x10B;
        gSpriteEntries[sprite].unk6 = gSpriteEntries[sprite].unk30;
        break;
    case 7:
        gSpriteEntries[sprite].unk20 = 7;
        gSpriteEntries[sprite].unk21 = 0;
        gSpriteEntries[sprite].unk30 = a + 0x108;
        gSpriteEntries[sprite].unk6 = gSpriteEntries[sprite].unk30;
        break;
    case 8:
        gSpriteEntries[sprite].unk20 = 8;
        gSpriteEntries[sprite].unk21 = 0;
        gSpriteEntries[sprite].unk23 = b;
        gSpriteEntries[sprite].unk30 = a + 0x10C;
        gSpriteEntries[sprite].unk6 = gSpriteEntries[sprite].unk30;
        break;
    case 10:
        gSpriteEntries[sprite].unk20 = 10;
        gSpriteEntries[sprite].unk21 = a * 4 + 0x14;
        gSpriteEntries[sprite].unk27 = 0;
        gSpriteEntries[sprite].unk30 = a * 12 + 0x6F;
        gSpriteEntries[sprite].unk6 = gSpriteEntries[sprite].unk30;
        break;
    }
    gSpriteEntries[sprite].unk1A = 0;
}

void clear_sprite_entry(u8 sprite) {
    u32 zero = 0;
    DmaSet(3, &zero, &gSpriteEntries[sprite], 0x85000010);
}
