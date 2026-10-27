// Battle screen drawing: BG layers, Medabot part sprites and positions, portraits, the name sprites, side
// panels and the Medaforce gauge (bar and value). Called from battle/robattle and the battle menus.

#include "global.h"

void load_bg3_tilemap_08488764(void) {
    set_tilemap_and_decompress_bg(14, 3, gUnk_08488764, REG_BG3CNT, 0x200);
}

void draw_battle_bot_portraits(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[i].unk40)
            draw_tile_block(2, 2, 2, i * 3 + 4, REG_BG3CNT, (gUnk_03000590[i].parts[3].data[1] << 2) + 0x8084);
        else
            draw_tile_block(2, 2, 2, i * 3 + 4, REG_BG3CNT, 0x8230);
    }
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[i + 3].unk40)
            draw_tile_block(2, 2, 26, i * 3 + 4, REG_BG3CNT, (gUnk_03000590[i + 3].parts[3].data[1] << 2) + 0x8084);
        else
            draw_tile_block(2, 2, 26, i * 3 + 4, REG_BG3CNT, 0x8230);
    }
}

void get_bot_part_effective_values(u32 bot, u8 *out) {
    if (gUnk_03000590[bot].parts[0].unk11)
        *out++ = gUnk_03000590[bot].parts[0].unk17;
    else
        *out++ = gUnk_03000590[bot].unk41 + 0x78;
    if (gUnk_03000590[bot].parts[1].unk11)
        *out++ = gUnk_03000590[bot].parts[1].unk17;
    else
        *out++ = gUnk_03000590[bot].unk41 + 0x78;
    if (gUnk_03000590[bot].parts[2].unk11)
        *out++ = gUnk_03000590[bot].parts[2].unk17;
    else
        *out++ = gUnk_03000590[bot].unk41 + 0x78;
    if (gUnk_03000590[bot].parts[3].unk11)
        *out = gUnk_03000590[bot].parts[3].unk17;
    else
        *out = gUnk_03000590[bot].unk41 + 0x78;
}

void load_bot_part_sprite(u32 rec) {
    u8 *p = gUnk_03001800.unk64;
    get_bot_part_effective_values(rec, p);
    decompress_sprite_to_vram_08042D94(p[0], p[1], p[2], p[3], rec);
}

void load_all_bot_part_sprites(void) {
    u32 i;
    for (i = 0; i <= 5; i++) {
        if (gUnk_03000590[i].unk40)
            load_bot_part_sprite(i);
    }
}

// Team sprites face right, opponents left; flag bit 2 of unkBD turns a Medabot round.
u32 bot_sprite_is_flipped(u32 rec) {
    if (rec <= 2) {
        if (gUnk_03000590[rec].unkBD & 4)
            return 1;
        return 0;
    }
    if (gUnk_03000590[rec].unkBD & 4)
        return 0;
    return 1;
}

static void init_battle_bot_sprite(u32 rec, u32 x, u32 y) {
    u8 *p = gUnk_03001800.unk64;
    u32 flip;
    get_bot_part_effective_values(rec, p);
    flip = bot_sprite_is_flipped(rec);
    init_battle_medabot_sprites(p[0], p[1], p[2], p[3], rec, rec * 4 + 0x5A, x, y, flip, gUnk_03001800.unk39[3] + 2,
                                rec * 4 + 0x5A);
}

void setup_all_battle_bot_sprite_positions(void) {
    u32 i;
    for (i = 0; i <= 5; i++) {
        if (gUnk_03000590[i].unk40) {
            u32 x = 200;
            if (i <= 2)
                x = 40;
            init_battle_bot_sprite(i, x, (i % 3) * 24 + 36);
        }
    }
}

void setup_battle_bot_sprite_group(u32 rec, u32 x, u32 y) {
    u8 *p = gUnk_03001800.unk64;
    u32 flip;
    get_bot_part_effective_values(rec, p);
    flip = bot_sprite_is_flipped(rec);
    setup_battle_sprite_group(p[0], p[1], p[2], p[3], rec, rec * 4 + 0x5A, x, y, flip, gUnk_03001800.unk39[3] + 2,
                              rec * 4 + 0x5A);
    gUnk_03002C30[rec * 4 + 0x5B].unk0 &= 0xFDFF;
    gUnk_03002C30[rec * 4 + 0x5C].unk0 &= 0xFDFF;
    gUnk_03002C30[rec * 4 + 0x5B].unk18 = 0;
    gUnk_03002C30[rec * 4 + 0x5C].unk18 = 0;
}

void load_battle_bg_layers(void) {
    set_tilemap_and_decompress_bg(0, 13, gUnk_08488830, REG_BG1CNT, 0x258);
    set_tilemap_and_decompress_bg(0, 17, gUnk_08488744, REG_BG1CNT, 0x210);
    set_tilemap_and_decompress_bg(12, 15, gUnk_084887A4, REG_BG1CNT, 0x230);
    set_tilemap_and_decompress_bg(20, 16, gUnk_084887F4, REG_BG1CNT, 0x240);
}

void decompress_two_bg1_layers(void) {
    set_tilemap_and_decompress_bg(12, 21, gUnk_084887A4, REG_BG1CNT, 0x230);
    set_tilemap_and_decompress_bg(20, 21, gUnk_084887F4, REG_BG1CNT, 0x240);
}

void render_bot_name_sprites(u32 rec) {
    if (rec <= 2) {
        clear_sprite_table_mask(10, 10);
        render_text_sprites_08040DB8(gUnk_03000590[rec].medal.unkA, 10, 1, 14, 10, 15, 0, 1);
    } else {
        clear_sprite_table_mask(20, 13);
        render_text_sprites_08040DB8(gUnk_03000590[rec].medal.unkA, 20, 19, 14, 10, 15, 0, 1);
    }
}

void draw_battle_panel_left_a(u32 rec) {
    if (rec <= 2)
        draw_tile_block(3, 1, 1, 18, REG_BG1CNT, 0xD20A);
    else
        draw_tile_block(3, 1, 21, 18, REG_BG1CNT, 0xD20A);
}

void draw_battle_panel_left_b(u32 rec) {
    if (rec <= 2)
        draw_tile_block(3, 1, 1, 18, REG_BG1CNT, 0xD20D);
    else
        draw_tile_block(3, 1, 21, 18, REG_BG1CNT, 0xD20D);
}

void draw_medaforce_gauge_bar(u32 rec) {
    u32 x = 0;
    u32 i, full, partial;

    if (rec <= 2) {
        full = scale_to_bar_fill(64, 80, gUnk_03000590[rec].unkC1);
        partial = full & 0xFFFF;
        full >>= 16;
        if (gUnk_03000590[rec].unkC1 != 0 && full == 0 && partial == 0)
            partial = 1;
        for (i = 0; i < full; i++) {
            draw_tile_block(1, 1, x + 1, 17, REG_BG1CNT, 0xD208);
            x++;
        }
        if (partial) {
            draw_tile_block(1, 1, x + 1, 17, REG_BG1CNT, 0xD200 + partial);
            x++;
        }
        for (i = x; i <= 7; i++) {
            draw_tile_block(1, 1, x + 1, 17, REG_BG1CNT, 0xD200);
            x++;
        }
    } else {
        full = scale_to_bar_fill(64, 80, gUnk_03000590[rec].unkC1);
        partial = full & 0xFFFF;
        full >>= 16;
        if (gUnk_03000590[rec].unkC1 != 0 && full == 0 && partial == 0)
            partial = 1;
        for (i = 0; i < full; i++) {
            draw_tile_block(1, 1, x + 21, 17, REG_BG1CNT, 0xD208);
            x++;
        }
        if (partial) {
            draw_tile_block(1, 1, x + 21, 17, REG_BG1CNT, 0xD200 + partial);
            x++;
        }
        for (i = x; i <= 7; i++) {
            draw_tile_block(1, 1, x + 21, 17, REG_BG1CNT, 0xD200);
            x++;
        }
    }
}

u32 scale_to_bar_fill(u32 a, u32 b, u32 c) {
    u32 v = (float)a / (float)b * (float)c;
    u32 ret = ((v >> 3) << 16) | (v & 7);
    if (c != 0 && ret == 0)
        ret = 1;
    return ret;
}

void draw_medaforce_gauge_value(u32 rec) {
    if (rec <= 2) {
        draw_number_bgcnt(gUnk_03000590[rec].unkC1, 4, 18, 2, REG_BG1CNT, 0xD220);
        draw_tile_block(1, 1, 6, 18, REG_BG1CNT, 0xD21A);
        draw_number_bgcnt(80, 7, 18, 2, REG_BG1CNT, 0xD220);
    } else {
        draw_number_bgcnt(gUnk_03000590[rec].unkC1, 24, 18, 2, REG_BG1CNT, 0xD220);
        draw_tile_block(1, 1, 26, 18, REG_BG1CNT, 0xD21A);
        draw_number_bgcnt(80, 27, 18, 2, REG_BG1CNT, 0xD220);
    }
}
