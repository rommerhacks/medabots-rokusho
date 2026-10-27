// Link Robattle (game state 10, guess: entered from battle/action_phase when gUnk_03000440.unk89 == 1):
// sub_0803D538 runs the sub-state handlers gUnk_083AFAF8 (sub_0803D5A0 .. sub_0803E774): the player-0 /
// player-1 handshake seeding gUnk_03000440.unk8D, screen setups, palette fades, message steps and the link
// packet exchange through gUnk_03005010 (link/serial). Ends with the battle-screen helpers they use, the
// link Medapart exchange (sub_0803EE10), the link error check link_error_check (called by the battle and menu
// states) and soft_reset_to_title. Not runnable in the single-GBA harness, so names are guesses.

#include "global.h"

static void render_battle_text_label(void);
static void load_battle_anim_data_38(void);
static void draw_battle_ui_tiles_from_rom(void);
static void load_battle_script_entry_a(void);
static void sub_0803E894(void);
static void sub_0803E8EC(void);
static void sub_0803E934(void);
static void sub_0803E978(void);
static void sub_0803E9BC(void);
static void sub_0803EA18(void);
static void draw_battle_gauge_bar(void);
static void update_battle_gauge_display(void);
static void sub_0803EB30(void);
static void sub_0803EB5C(void);
static void sub_0803EC04(void);
static u32 sub_0803EC98(void);
static void sub_0803ECF0(void);
static void sub_0803ED10(void);
static u32 sub_0803ED28(void);
static void draw_battle_bg1_tilemap_row(void);

// Game state 10 handler: runs gUnk_083AFAF8[gGameSubState]; outside sub-states 0x10-0x1F a link error
// (link_error_check) restarts it at 0x10. guess: link Robattle (entered when gUnk_03000440.unk89 == 1).
void sub_0803D538(void) {
    if (gGameSubState - 0x10 > 0xF && link_error_check())
        return;
    if (gUnk_03000430 == 2) {
        u32 fill = 0x200;
        CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
    }
    sub_0803E780();
    gUnk_083AFAF8[gGameSubState]();
}

void sub_0803D5A0(void) {
    u32 zero = 0;

    CpuFastSet(&zero, &gUnk_03001800, 0x01000100);
    gUnk_03000440.unk86 = 0;
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_0803D5E0(void) {
    if (link_sync_both_ready()) {
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
}

void sub_0803D608(void) {
    if (gUnk_03000440.unk86 == 8) {
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    } else {
        gUnk_03000440.unk86++;
    }
}

void sub_0803D634(void) {
    if (gUnk_03000B90 == 0) {
        gUnk_03000440.unk8D = gFrameCounter;
        gUnk_03005010.unk6 = gUnk_03000440.unk8D + 0x8000;
    }
    gGameSubState++;
}

void sub_0803D674(void) {
    if (gUnk_03000B90 != 0) {
        u16 v = gUnk_03005010.unk8[0][1];
        if (!(v & 0x8000))
            return;
        gUnk_03000440.unk8D = v;
    }
    gGameSubState++;
}

void sub_0803D6AC(void) {
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unk51 = 0;
    gUnk_03001800.unk52 = 0;
    gUnk_03001800.unk53 = 0;
    gUnk_03001800.unk54 = 0;
    gUnk_03001800.unk1A6 = 0;
    gUnk_03001800.unk1A8 = 0;
    gUnk_03001800.unk1AA = 0;
    gUnk_03001800.unk1AC = 0;
    gUnk_03001800.unk1AF = 0;
    gUnk_03001800.unk1B0 = 1;
    gUnk_03000440.unk86 = 0;
    gGameSubState = 0x50;
}

void sub_0803D71C(void) {
    gUnk_03001800.unk38 = gUnk_083AFC78[rng_next_byte() & 0x1F];
    gGameSubState++;
}

void sub_0803D74C(void) {
    u32 a, b, c;

    clear_bg_scroll();
    a = 0;
    CpuFastSet(&a, (void *)OBJ_PLTT, 0x01000080);
    b = 0;
    CpuFastSet(&b, (void *)PLTT, 0x01000080);
    REG_DISPCNT &= 0xE0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x590A;
    REG_BG3CNT = 0x5B0B;
    lz_decompress_dispatch(gUnk_084E6C9C, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C48B4, (void *)0x06006000);
    lz_decompress_dispatch(gUnk_084C4A34, (void *)0x06006200);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG1CNT, 0);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EFA34, REG_BG1CNT, 0x200);
    CpuFastSet(gUnk_084F29E0, (void *)0x0202FA00, 0x70);
    CpuFastSet(gUnk_084C69D8, (void *)0x0202FB00, 8);
    CpuFastSet(gUnk_084C69F8, (void *)0x0202FB20, 8);
    CpuFastSet(gUnk_0850DEF8, (void *)0x0202F800, 0x40);
    CpuFastSet(gUnk_0850DCF8 + 0xB0, (void *)0x0202F980, 8);
    CpuFastSet(gUnk_0850DCF8, (void *)0x0202F9A0, 8);
    decompress_tileset_to_vram(gUnk_03001800.unk38, 1);
    c = 0;
    CpuFastSet(&c, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    render_battle_text_label();
    load_battle_anim_data_38();
    draw_battle_ui_tiles_from_rom();
    load_battle_script_entry_a();
    apply_battle_blend_effect_a();
    play_song(8);
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_0803D928(void) {
    update_scroll_movement_a();
    if (gUnk_03000440.unk84 <= 8) {
        bg_palettes_blend_masked_now(0, 0x20 - gUnk_03000440.unk84 * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, 0x20 - gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else
        gGameSubState++;
}

void sub_0803D980(void) {
    update_scroll_movement_a();
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void sub_0803D9A0(void) {
    update_scroll_movement_a();
    if (run_message(gUnk_083C2BBC[1]))
        gGameSubState++;
}

void sub_0803D9C8(void) {
    update_scroll_movement_a();
    palette_backup_from_hardware();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_0803D9F0(void) {
    update_scroll_movement_a();
    if (gUnk_03000440.unk84 <= 8) {
        bg_palettes_blend_masked_now(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else
        gGameSubState++;
}

void sub_0803DA40(void) {
    update_scroll_movement_a();
    if (gUnk_03000440.unk84 <= 8) {
        bg_palettes_blend_masked_now(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else
        gGameSubState++;
}

void sub_0803DA90(void) {
    set_blend_effect_mode(0, 0, 0);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG1CNT, 0);
    clear_battle_sprite_slot(0, 0x80);
    gGameSubState++;
}

void sub_0803DAEC(void) {
    mem_fill8(&gUnk_03000440.unk50, 0x14, 0);
    gUnk_03000440.unk50 = 1;
    gGameState = 3;
    gGameSubState = 0;
}

void sub_0803DB1C(void) {
    if (gUnk_03000440.unk9C == 1)
        play_song(14);
    else
        play_song(15);
    gGameSubState++;
}

void sub_0803DB4C(void) {
    update_scroll_movement_a();
    if (run_message(gUnk_083C3984[1]) && (*(u8 *)&gNewKeys & 3)) {
        gUnk_03000440.unk1B = 0;
        play_sound_effect(0xD);
        gGameSubState++;
    }
}

void sub_0803DB94(void) {
    update_scroll_movement_a();
    if (game_state_execute_handler_b()) {
        sub_0803FB0C();
        gGameSubState++;
    }
}

void sub_0803DBB8(void) {
    update_scroll_movement_a();
    if (run_message(gUnk_083CF3B0[1]))
        gGameSubState++;
}

void sub_0803DBE0(void) {
    update_scroll_movement_a();
    if (link_sync_both_ready()) {
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
}

void sub_0803DC0C(void) {
    update_scroll_movement_a();
    if (gUnk_03000440.unk86 == 8) {
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    } else {
        gUnk_03000440.unk86++;
    }
}

void sub_0803DC3C(void) {
    update_scroll_movement_a();
    sound_stop_all_with_fade_guard(8);
    gGameSubState++;
}

void sub_0803DC58(void) {
    update_scroll_movement_a();
    if (gUnk_03000440.unk138 == 0)
        gGameSubState++;
    else
        gGameSubState = 0x30;
}

void sub_0803DC8C(void) {
    u32 a, b;

    clear_battle_sprite_slot(0, 0x80);
    clear_bg_scroll();
    a = 0;
    CpuFastSet(&a, (void *)(OBJ_PLTT), 0x01000080);
    b = 0;
    CpuFastSet(&b, (void *)PLTT, 0x01000080);
    set_blend_effect_mode(5, 0x3F, 0x20);
    goto_link_scene(3);
}

void sub_0803DCDC(void) {
    u32 zero;

    clear_bg_scroll();
    set_blend_effect_mode(5, 0x3F, 0x20);
    REG_DISPCNT &= 0xE0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1B03;
    lz_decompress_dispatch(gUnk_084EDEF0, (void *)0x06004000);
    lz_decompress_dispatch(gUnk_084C66B8, (void *)0x06007000);
    lz_decompress_dispatch(gUnk_084C68E0, (void *)0x06007A00);
    lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
    lz_decompress_dispatch(gUnk_084E20F8, (void *)0x06010000);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084EF668, REG_BG0CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0194, REG_BG1CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F0D9C, REG_BG2CNT, 0x200);
    set_tilemap_and_decompress_bg(0, 0, gUnk_084F21E8, REG_BG3CNT, 0x200);
    CpuFastSet(gUnk_084F39A0, (void *)PLTT, 0x60);
    CpuFastSet(gUnk_0850EF58, (void *)OBJ_PLTT, 0x10);
    zero = 0;
    CpuFastSet(&zero, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    sub_0803E8B8();
    sub_0803E8EC();
    sub_0803E934();
    sub_0803E978();
    sub_0803E9BC();
    gUnk_03001800.unk1A0 = 0;
    play_song(0x14);
    gGameSubState++;
}

void sub_0803DE70(void) {
    sub_0803E894();
    if (update_blend_effect())
        gGameSubState++;
}

void sub_0803DE90(void) {
    sub_0803E894();
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void sub_0803DEB0(void) {
    sub_0803E894();
    if (run_message(gUnk_03000440.unk9C == 1 ? gUnk_083CF3B0[2] : gUnk_083CF3B0[3]))
        gGameSubState++;
}

void sub_0803DEF0(void) {
    u16 pkt;

    sub_0803E894();
    if (gUnk_03000440.unk9C == 1) {
        sub_0803EA18();
        draw_battle_gauge_bar();
        if (!(*(u8 *)&gNewKeys & 1))
            return;
        play_sound_effect(4);
        gUnk_03005010.unk6 = gUnk_03001800.unk1A0 + 0x8000;
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    } else {
        pkt = gUnk_03005010.unk8[gUnk_03000B90 ^ 1][1];
        if (!(pkt & 0x8000))
            return;
        play_sound_effect(4);
        gUnk_03001800.unk1A0 = pkt;
        gUnk_03000440.unk1B = 0;
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
}

void sub_0803DF98(void) {
    u16 n;

    sub_0803E894();
    if (gUnk_03000440.unk9C == 1) {
        gUnk_03005010.unk6 = gUnk_03001800.unk1A0 + 0x8000;
        update_battle_gauge_display();
        n = ++gUnk_03000440.unk86;
    } else {
        update_battle_gauge_display();
        gUnk_03000440.unk86++;
        if (!game_state_execute_handler_a())
            return;
        n = gUnk_03000440.unk86;
    }
    if (n == 0x3C) {
        play_sound_effect(0x39);
        draw_battle_gauge_bar();
        gGameSubState++;
    }
}

void sub_0803E018(void) {
    sub_0803E894();
    sub_0803EB30();
    sub_0803EB5C();
    sub_0803EC04();
    gGameSubState++;
}

void sub_0803E03C(void) {
    sub_0803E894();
    process_sprite_anim_commands(gUnk_083B5F80[0x75 - gUnk_03001800.unk1A2], 4);
    if (gSpriteEntries[4].unk22 == 0xFF) {
        gSpriteEntries[3].unk6 = 0x8505;
        play_sound_effect(0x54);
        gGameSubState++;
    }
}

void sub_0803E098(void) {
    sub_0803E894();
    if (sub_0803EC98()) {
        sub_0803ECF0();
        sub_0803ED10();
        gGameSubState++;
    }
}

void sub_0803E0C0(void) {
    sub_0803E894();
    if (sub_0803ED28()) {
        play_sound_effect(0x2A);
        gUnk_03000440.unk86 = 0;
        gGameSubState++;
    }
}

void sub_0803E0F0(void) {
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    if (gUnk_03000440.unk86 == 0x78)
        gGameSubState++;
    else
        gUnk_03000440.unk86++;
}

void sub_0803E120(void) {
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    if (gUnk_03001800.unk19A[gUnk_03001800.unk1A2] == 4)
        gGameSubState++;
    else
        gGameSubState = 0x48;
}

void sub_0803E170(void) {
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void sub_0803E1A4(void) {
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    if (run_message(gUnk_03000440.unk9C == 1 ? gUnk_083CF3B0[4] : gUnk_083CF3B0[5])) {
        text_window_init(1, 0, 0);
        gGameSubState++;
    }
}

void sub_0803E1FC(void) {
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    if (run_message(gUnk_083CF3B0[1]))
        gGameSubState++;
}

void sub_0803E234(void) {
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    if (link_sync_both_ready()) {
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    }
}

void sub_0803E270(void) {
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    if (gUnk_03000440.unk84 == 4) {
        gUnk_03000440.unk84 = 0;
        gGameSubState++;
    } else
        gUnk_03000440.unk84++;
}

void sub_0803E2AC(void) {
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    sound_stop_all_with_fade_guard(8);
    gGameSubState++;
}

void sub_0803E2DC(void) {
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    palette_backup_from_hardware();
    gUnk_03000440.unk84 = 0;
    gGameSubState++;
}

void sub_0803E314(void) {
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    if (gUnk_03000440.unk84 <= 8) {
        bg_palettes_blend_masked_now(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0, gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else
        gGameSubState++;
}

void sub_0803E374(void) {
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    sub_0803EE10();
    if (gUnk_03000440.unk9C == 1)
        medapart_add_quantity(gUnk_03001800.unk1A5, (gUnk_03001800.unk19A + 0)[gUnk_03001800.unk1A2], 1);
    else
        sub_080421B4(gUnk_03001800.unk1A4, (gUnk_03001800.unk19A + 0)[gUnk_03001800.unk1A2]);
    memcpy_bytes_08041D04(
        (const void *)gUnk_083BB9CC[0][gUnk_03001800.unk1A5 * 4 + gUnk_03001800.unk19A[gUnk_03001800.unk1A2]],
        gUnk_03000440.unk9E, 0xF);
    gGameSubState++;
}

void sub_0803E434(void) {
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    if (run_message(gUnk_03000440.unk9C == 1 ? gUnk_083CF3B0[6] : gUnk_083CF3B0[7])) {
        text_window_init(1, 0, 0);
        gGameSubState++;
    }
}

void sub_0803E48C(void) {
    sub_0803E894();
    draw_battle_bg1_tilemap_row();
    gUnk_03000440.unk86++;
    gGameSubState = 0x3E;
}

void sub_0803E4B4(void) {
    sound_stop_all_with_fade_guard(8);
    set_blend_effect_mode(6, 0x3F, 0x20);
    gGameSubState++;
}

void sub_0803E4D8(void) {
    if (update_blend_effect())
        gGameSubState++;
}

void sub_0803E4F4(void) {
    u32 a, b, c;

    clear_bg_scroll();
    REG_DISPCNT &= 0xE0FF;
    REG_BG0CNT = 0x500;
    REG_BG1CNT = 0x1801;
    REG_BG2CNT = 0x1902;
    REG_BG3CNT = 0x1B03;
    a = 0;
    CpuFastSet(&a, (void *)(PLTT + 0x120), 0x01000008);
    b = 0x11111111;
    CpuFastSet(&b, (void *)0x06004120, 0x01000008);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG0CNT, 0x9209);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG1CNT, 0x9209);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG2CNT, 0x9209);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG3CNT, 0x9209);
    c = 0;
    CpuFastSet(&c, gSpriteEntries, 0x01000800);
    REG_DISPCNT |= 0x1F60;
    set_blend_effect_mode(5, 0x3F, 0x20);
    gGameSubState++;
}

void sub_0803E618(void) {
    text_window_init(1, 0, 0);
    gGameSubState++;
}

void sub_0803E634(void) {
    if (run_message(gUnk_083CF3B0[12]))
        gGameSubState++;
}

static void sub_0803E658(void) {
    set_blend_effect_mode(4, 0x3F, 0x20);
    gGameSubState++;
}

void sub_0803E674(void) {
    soft_reset_to_title();
}

void sub_0803E680(void) {
    struct Unk_03005010 *link = &gUnk_03005010;
    u16 v;
    s16 flag;
    link->unk6 = gUnk_03002B70.unk4[gUnk_03001800.unk51] + (flag = ((gUnk_03001800.unk1AF << 8) & 0x100) + 0x8000);
    gUnk_03000440.unk86++;
    if (!(gUnk_03000440.unk86 & 1)) {
        gUnk_03001800.unk1AF ^= 1;
        gUnk_03001800.unk51++;
    }
    v = link->unk8[gUnk_03000B90 ^ 1][1];
    if (v & 0x8000) {
        if ((u16)(v & 0x100) >> 8 != gUnk_03001800.unk1B0) {
            gUnk_03001800.unk1B0 ^= 1;
            gUnk_03001800.unk18A[gUnk_03001800.unk52] = v;
            if (++gUnk_03001800.unk52 > 10) {
                gUnk_03000440.unk86 = 0;
                gGameSubState++;
            }
        }
    }
}

void sub_0803E768(void) {
    gGameSubState = 6;
}

void sub_0803E774(void) {
    gGameSubState = 5;
}

void sub_0803E780(void) {
    if (gUnk_03000440.unk89 == 1)
        gUnk_03005010.unk6 = 0;
}

u32 link_sync_both_ready(void) {
    gUnk_03005010.unk6 = 0xFFFE;
    if (gUnk_03005010.unk8[0][1] == 0xFFFE && gUnk_03005010.unk8[1][1] == gUnk_03005010.unk8[0][1])
        return 1;
    return 0;
}

static void render_battle_text_label(void) {
    render_text_sprites_08040EE4(gUnk_0300198A, 10, 0x12, 3, 10, 13, 0, 1, 0, -4);
}

static void load_battle_anim_data_38(void) {
    memcpy_bytes_0803F63C(gUnk_083BE9E8[gUnk_03001800.unk38], gUnk_03000440.unk9E, 0xB);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x1E, 1, 3, 8, 0xC, 0, 1);
}

static void draw_battle_ui_tiles_from_rom(void) {
    u32 i;
    for (i = 0; i <= 2; i++)
        draw_tilemap_with_offset(0xFF, gUnk_083ACEEA[i][0], gUnk_083ACEEA[i][1], REG_BG0CNT, 0x8300);
}

static void load_battle_script_entry_a(void) {
    memcpy_bytes_0803F63C(gUnk_083C3B04[gUnk_03001800.unk38], gUnk_03001800.unk39, 8);
}

static void sub_0803E894(void) {
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

void sub_0803E8B8(void) {
    u32 r = rng_next_byte() & 0xF;
    u32 i;
    for (i = 0; i <= 5; i++)
        gUnk_0300199A[i] = gUnk_083AFC98[r][i];
}

static void sub_0803E8EC(void) {
    u32 i;

    for (i = 0; i <= 5; i++) {
        u8 *p = gUnk_0300199A;
        draw_tile_block(7, 2, 4, i * 2 + 2, REG_BG1CNT, p[i] * 14 + 0x3380);
    }
}

static void sub_0803E934(void) {
    clear_battle_sprite_slot(2, 1);
    gSpriteEntries[2].unk0 = 0xC400;
    gSpriteEntries[2].unk2 = 0x68;
    gSpriteEntries[2].unk4 = 0x78;
    gSpriteEntries[2].unk6 = 0x8506;
    gSpriteEntries[2].unk1C = 0;
    gSpriteEntries[2].unkB = 0x82;
}

static void sub_0803E978(void) {
    clear_battle_sprite_slot(3, 1);
    gSpriteEntries[3].unk0 = 0xC400;
    gSpriteEntries[3].unk2 = 0x78;
    gSpriteEntries[3].unk4 = 0x7C;
    gSpriteEntries[3].unk6 = 0x8504;
    gSpriteEntries[3].unk1C = 0;
    gSpriteEntries[3].unkB = 0x81;
}

static void sub_0803E9BC(void) {
    clear_battle_sprite_slot(4, 1);
    gSpriteEntries[4].unk0 = 0xC400;
    gSpriteEntries[4].unk2 = 0x9A;
    gSpriteEntries[4].unk4 = 0x58;
    gSpriteEntries[4].unk1C = 0;
    gSpriteEntries[4].unkB = 0x80;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x70], 4);
}

static void sub_0803EA18(void) {
    if (gUnk_03001800.unk1A0 == 0x60)
        gUnk_03001800.unk1A0 = 0;
    else
        gUnk_03001800.unk1A0 += 4;
}

static void draw_battle_gauge_bar(void) {
    u32 x = 0;
    u32 i, n;

    n = gUnk_03001800.unk1A0 >> 3;
    for (i = 0; i < n; i++) {
        draw_tile_block(1, 1, x + 7, 0x12, REG_BG1CNT, 0x53D8);
        x++;
    }
    n = gUnk_03001800.unk1A0;
    n &= 7;
    if (n != 0) {
        draw_tile_block(1, 1, x + 7, 0x12, REG_BG1CNT, n | 0x53D0);
        x++;
    }
    for (i = x; i < 12; i++) {
        draw_tile_block(1, 1, x + 7, 0x12, REG_BG1CNT, 0x53D0);
        x++;
    }
}

static void fill_bg1_tilemap_column(void) {
    u32 i;
    for (i = 0; i <= 11; i++)
        draw_tile_block(1, 1, i + 7, 0x12, REG_BG1CNT, 0x53D0);
}

static void update_battle_gauge_display(void) {
    if (gUnk_03000440.unk86 & 4)
        draw_battle_gauge_bar();
    else
        fill_bg1_tilemap_column();
}

static void sub_0803EB30(void) {
    gUnk_03001800.unk1A1 = 0x68 - gUnk_03001800.unk1A0;
    if (gUnk_03001800.unk1A1 <= 12)
        gUnk_03001800.unk1A1 = 12;
}

static void sub_0803EB5C(void) {
    gUnk_03001800.unk1A2 = gUnk_03001800.unk1A0 >> 4;
    switch (gUnk_03001800.unk1A2) {
    case 0:
        gUnk_03001800.unk1A2 = 5;
        break;
    case 1:
        gUnk_03001800.unk1A2 = 4;
        break;
    case 2:
        gUnk_03001800.unk1A2 = 3;
        break;
    case 3:
        gUnk_03001800.unk1A2 = 2;
        break;
    case 4:
        gUnk_03001800.unk1A2 = 1;
        break;
    case 5:
        gUnk_03001800.unk1A2 = 0;
        break;
    case 6:
        gUnk_03001800.unk1A2 = 0;
        break;
    }
    gUnk_03001800.unk1A3 = gUnk_03001800.unk1A2 * 16 + 0x18;
}

static void sub_0803EC04(void) {
    gSpriteEntries[2].unk24 = (gUnk_03001800.unk1A0 >> 2) + 4;
    gSpriteEntries[2].unk25 = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x75 - gUnk_03001800.unk1A2], 4);
}

static void sub_0803EC50(void) {
    u32 v = gSpriteEntries[2].unk24 + gSpriteEntries[2].unk20;
    u32 d = v >> 2;
    gSpriteEntries[2].unk20 = v & 3;
    if (gSpriteEntries[2].unk25 == 0)
        gSpriteEntries[2].unk4 = (gSpriteEntries[2].unk4 - d) & 0xFF;
    else
        gSpriteEntries[2].unk4 = (gSpriteEntries[2].unk4 + d) & 0xFF;
}

static u32 sub_0803EC98(void) {
    sub_0803EC50();
    if (gSpriteEntries[2].unk4 <= gUnk_03001800.unk1A1) {
        gSpriteEntries[2].unk4 = gUnk_03001800.unk1A1;
        return 1;
    }
    gSpriteEntries[2].unk27++;
    if (!(gSpriteEntries[2].unk27 & 3) && gSpriteEntries[2].unk24 != 1)
        gSpriteEntries[2].unk24--;
    return 0;
}

static void sub_0803ECF0(void) {
    if (gUnk_03001800.unk1A0 == 0x60)
        play_sound_effect(7);
}

static void sub_0803ED10(void) {
    gSpriteEntries[2].unk24 = 0;
    gSpriteEntries[2].unk25 = 1;
}

static u32 sub_0803ED28(void) {
    u32 r;

    sub_0803EC50();
    if (gSpriteEntries[2].unk4 < gUnk_03001800.unk1A3) {
        gSpriteEntries[2].unk24++;
        r = 0;
    } else {
        gSpriteEntries[2].unk4 = gUnk_03001800.unk1A3;
        r = 1;
    }
    return r;
}

static void draw_battle_bg1_tilemap_row(void) {
    if (gUnk_03000440.unk86 & 4)
        draw_tile_block(7, 2, 4, gUnk_03001800.unk1A2 * 2 + 2, REG_BG1CNT,
                        gUnk_03001800.unk19A[gUnk_03001800.unk1A2] * 14 + 0x3380);
    else
        draw_tile_block(7, 2, 4, gUnk_03001800.unk1A2 * 2 + 2, REG_BG1CNT,
                        gUnk_03001800.unk19A[gUnk_03001800.unk1A2] * 14 + 0x4380);
}

void sub_0803EE10(void) {
    u32 base;
    u32 r, i;

    if (gUnk_03000440.unk9C == 1)
        base = 3;
    else
        base = 0;
    r = gUnk_083AFCF8[rng_next_byte() & 0xF];
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[base + r].unkBA != 0) {
            gUnk_03001800.unk1A4 = gUnk_03000590[base + r].unk47;
            gUnk_03001800.unk1A5 = gUnk_03000590[base + r].parts[gUnk_03001800.unk19A[gUnk_03001800.unk1A2]].unk17;
            return;
        }
        if (r == 2)
            r = 0;
        else
            r++;
    }
}

u32 link_error_check(void) {
    // unk1C..unk1F read as one word (the struct has no u32 there)
    if (gUnk_03000440.unk89 == 1 && (((struct {
                                         u8 f[0x1C];
                                         u32 x;
                                     } *)&gUnk_03005010)
                                         ->x &
                                     0xFFFF00)) {
        gGameMode = 0;
        gGameState = 10;
        gGameSubState = 0x10;
        return 1;
    }
    return 0;
}

void soft_reset_to_title(void) {
    gUnk_03005030 = 0;
    serial_multiplayer_init();
    VBlankIntrWait();
    REG_SOUNDCNT_X = 0;
    REG_IME = 0;
    hw_reset_init();
    irq_init();
    serial_link_init();
    gGameMode = 3;
    gGameState = 0;
    gGameSubState = 0;
    REG_DMA0CNT_H = 0;
    VBlankIntrWait();
    sound_init(&gUnk_03002430);
    VBlankIntrWait();
}
