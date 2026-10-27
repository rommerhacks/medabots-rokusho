// Choice menu: open_choice_menu / poll_choice_menu run the yes/no prompt state table gUnk_083B2814 by
// gUnk_03000440.unk29 (decompress the BG, slide the tile strip in, move the cursor sprite, slide out; the
// last entry is choice_menu_finish). Then two sprite jitter helpers and game_state_execute_handler_a/b, which
// run the text/message window tables gUnk_083B284C / gUnk_083B2864 by gUnk_03000440.unk1B. Shares the
// window state gUnk_03000440 with text/message; used by menus, the save screen and battles.

#include "global.h"

void reset_bg_scroll(void) {
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gBg1Scroll.x = 0;
    gBg1Scroll.y = 0;
    gBg2Scroll.x = 0;
    gBg2Scroll.y = 0;
    gBg3Scroll.x = 0;
    gBg3Scroll.y = 0;
}

void open_choice_menu(u8 a, u8 b, u8 c) {
    mem_fill8(&gUnk_03000440.unk28, 8, 0);
    gUnk_03000440.unk2A = a;
    gUnk_03000440.unk2B = 0x7F;
    gUnk_03000440.unk2C = b;
    gUnk_03000440.unk2D = c;
}

static void init_window_params(u8 a, u8 b, u8 c, u8 d) {
    mem_fill8(&gUnk_03000440.unk28, 8, 0);
    gUnk_03000440.unk2A = a;
    gUnk_03000440.unk2B = d;
    gUnk_03000440.unk2C = b;
    gUnk_03000440.unk2D = c;
}

u32 poll_choice_menu(void) {
    gUnk_083B2814[gUnk_03000440.unk29]();
    return gUnk_03000440.unk28;
}

void decompress_bg_tilemap_to_vram(void) {
    lz_decompress_dispatch(gUnk_084878EC, (void *)(VRAM + 0x2600));
    lz_decompress_dispatch(gUnk_0848796C, (void *)(VRAM + 0x26E0));
    lz_decompress_dispatch(gUnk_084C7318, (void *)(VRAM + 0x17E00));
    set_tilemap_and_decompress_bg(0, 0x15, gUnk_084886D0, REG_BG0CNT, 0x130);
    set_tilemap_and_decompress_bg(2, 0x16, gUnk_08488718, REG_BG0CNT, 0x137);
    CpuFastSet(gUnk_084E2E58, (void *)(PLTT + 0x3C0), 8);
    gUnk_03000440.unk29++;
}

void clear_tilemap_and_advance_state(void) {
    vram_fill_tilemap_rect(8, 6, gUnk_03000440.unk2C, gUnk_03000440.unk2D, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(8, 6, 0, 0x15, REG_BG0CNT, 0);
    gUnk_03000440.unk29++;
}

void clear_and_copy_tilemap_rows(void) {
    u32 i, j;
    u16 *d = (u16 *)(VRAM + 0x2800) + gUnk_03000440.unk2D * 32 + gUnk_03000440.unk2C;
    u16 *row = d;
    u16 *s;

    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++)
            *d++ = 0;
        row += 32;
        d = row;
    }
    s = (u16 *)(VRAM + 0x2D40);
    for (i = 0; i < 8; i++)
        *d++ = *s++;
    row += 32;
    d = row;
    s = (u16 *)(VRAM + 0x2E80);
    for (i = 0; i < 8; i++)
        *d++ = *s++;
    row += 32;
    d = row;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++)
            *d++ = 0;
        row += 32;
        d = row;
    }
    gUnk_03000440.unk29++;
}

void transition_draw_tile_strip(void) {
    u32 i, j;
    u16 *d = (u16 *)(VRAM + 0x2800) + gUnk_03000440.unk2D * 32 + gUnk_03000440.unk2C;
    u16 *row = d;
    u16 *s;
    u16 *srow;

    for (i = 0; i < 8; i++)
        *d++ = 0;
    row += 32;
    s = (u16 *)(VRAM + 0x2D40);
    srow = s;
    d = row;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++)
            *d++ = *s++;
        row += 32;
        d = row;
        srow += 32;
        s = srow;
    }
    s = (u16 *)(VRAM + 0x2E40);
    srow = s;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++)
            *d++ = *s++;
        row += 32;
        d = row;
        srow += 32;
        s = srow;
    }
    for (i = 0; i < 8; i++)
        *d++ = 0;
    gUnk_03000440.unk29++;
}

void copy_transition_tiles_to_bg2(void) {
    u32 i, j;
    u16 *d = (u16 *)(VRAM + 0x2800) + gUnk_03000440.unk2D * 32 + gUnk_03000440.unk2C;
    u16 *s = (u16 *)(VRAM + 0x2D40);
    u16 *srow = s;
    u16 *row = d;

    for (j = 0; j < 6; j++) {
        for (i = 0; i < 8; i++)
            *d++ = *s++;
        row += 32;
        d = row;
        srow += 32;
        s = srow;
    }
    gUnk_03000440.unk29++;
}

void battle_sprite_setup_cursor(void) {
    gUnk_03002C30[gUnk_03000440.unk2B].unk0 = 0xD204;
    gUnk_03002C30[gUnk_03000440.unk2B].unk2 = gUnk_03000440.unk2C * 8 + 0x14;
    gUnk_03002C30[gUnk_03000440.unk2B].unk4 = gUnk_03000440.unk2D * 8 + gUnk_03000440.unk2A * 16 + 0x10;
    gUnk_03002C30[gUnk_03000440.unk2B].unk6 = 0x307;
    gUnk_03002C30[gUnk_03000440.unk2B].unkA = 0xE;
    gUnk_03002C30[gUnk_03000440.unk2B].unk1C = 0;
    gUnk_03002C30[gUnk_03000440.unk2B].unk8 = 1;
    gUnk_03002C30[gUnk_03000440.unk2B].unk9 = 1;
    gUnk_03002C30[gUnk_03000440.unk2B].unkB = 0xFF;
    gUnk_03000440.unk84 = 1;
    gUnk_03000440.unk29++;
}

void advance_sprite_scroll_animation(void) {
    gUnk_03002C30[gUnk_03000440.unk2B].unk8 += 8;
    gUnk_03002C30[gUnk_03000440.unk2B].unk9 += 8;
    if (gUnk_03002C30[gUnk_03000440.unk2B].unk8 >= 0x40) {
        gUnk_03002C30[gUnk_03000440.unk2B].unk8 = 0x40;
        gUnk_03002C30[gUnk_03000440.unk2B].unk9 = 0x40;
        gUnk_03000440.unk29++;
    }
    gUnk_03000440.unk84 = 0;
}

void handle_battle_sprite_scroll_input(void) {
    if (KEYS_LO(gNewKeys) & 0xC0) {
        play_sound_effect(2);
        gUnk_03000440.unk2A ^= 1;
        gUnk_03002C30[gUnk_03000440.unk2B].unk4 = gUnk_03000440.unk2A * 16 + 0x48;
    }
    sprite_bob_y(gUnk_03000440.unk2B, gUnk_03000440.unk84, gUnk_03000440.unk2C * 8 + 0x14);
    gUnk_03000440.unk84++;
    if (KEYS_LO(gNewKeys) & 2) {
        play_sound_effect(5);
        gUnk_03000440.unk2A = 1;
        gUnk_03002C30[gUnk_03000440.unk2B].unk2 = gUnk_03000440.unk2C * 8 + 0x14;
        gUnk_03002C30[gUnk_03000440.unk2B].unk4 = gUnk_03000440.unk2A * 16 + 0x48;
        gUnk_03000440.unk84 = 0;
        gUnk_03000440.unk29++;
    }
    if (KEYS_LO(gNewKeys) & 1) {
        play_sound_effect(4);
        gUnk_03002C30[gUnk_03000440.unk2B].unk2 = gUnk_03000440.unk2C * 8 + 0x14;
        gUnk_03000440.unk84 = 0;
        gUnk_03000440.unk29++;
    }
}

void update_sprite_hflip_by_animation_phase(void) {
    if (gUnk_03000440.unk84 != 0x1E) {
        if (gUnk_03000440.unk84 & 4)
            gUnk_03002C30[gUnk_03000440.unk2B].unk0 &= 0xBFFF;
        else
            gUnk_03002C30[gUnk_03000440.unk2B].unk0 |= 0x4000;
        gUnk_03000440.unk84++;
    } else {
        gUnk_03002C30[gUnk_03000440.unk2B].unk0 |= 0x4000;
        gUnk_03000440.unk29++;
    }
}

void animate_battle_sprite_shrink(void) {
    gUnk_03002C30[gUnk_03000440.unk2B].unk8 -= 8;
    gUnk_03002C30[gUnk_03000440.unk2B].unk9 -= 8;
    if (gUnk_03002C30[gUnk_03000440.unk2B].unk8 == 0) {
        clear_battle_sprite_slot(gUnk_03000440.unk2B, 1);
        gUnk_03000440.unk29++;
    }
}

void choice_menu_finish(void) {
    gUnk_03000440.unk28 = (gUnk_03000440.unk2A << 4) + 1;
    gUnk_03000440.unk29++;
}

void sprite_bob_y(u8 sprite, u8 frame, u16 y) {
    switch ((frame & 0xC) >> 2) {
    case 1:
        gUnk_03002C30[sprite].unk2 = y + 1;
        break;
    case 3:
        gUnk_03002C30[sprite].unk2 = y - 1;
        break;
    default:
        gUnk_03002C30[sprite].unk2 = y;
        break;
    }
}

void sprite_bob_x(u8 sprite, u8 frame, u16 x) {
    switch ((frame & 0xC) >> 2) {
    case 1:
        gUnk_03002C30[sprite].unk4 = x + 1;
        break;
    case 3:
        gUnk_03002C30[sprite].unk4 = x - 1;
        break;
    default:
        gUnk_03002C30[sprite].unk4 = x;
        break;
    }
}

u32 game_state_execute_handler_a(void) {
    gUnk_03000440.unk4 = 0;
    gUnk_083B284C[gUnk_03000440.unk1B]();
    if (gUnk_03000440.unk4 > 7)
        return 1;
    return 0;
}

u32 game_state_execute_handler_b(void) {
    gUnk_03000440.unk4 = 0;
    gUnk_083B2864[gUnk_03000440.unk1B]();
    if (gUnk_03000440.unk4 > 7)
        return 1;
    return 0;
}

void memcpy_bytes_08041D04(const void *src, void *dst, u8 n) {
    u32 i;

    for (i = 0; i < n; i++) {
        *(u8 *)dst = *(const u8 *)src;
        src = (const u8 *)src + 1;
        dst = (u8 *)dst + 1;
    }
}
