// Robattle status screen (command ring slot 2): team sprites and cursors, the selected Medabot's name,
// Medal, parts, abilities and armor, its portrait, and the scroll to the other side's team (L/R).
// Called from battle/robattle.

#include "global.h"

static void status_switch_side(void);

// Robattle Status screen (ring slot 2, sub-states 0x23-0x26; runtime-checked, re/scratch/b34_status_probe.txt):
// gUnk_03000440.unk3C = side shown (0 team, 1 opponents, R / L switches), unk3D = selected Medabot, D-pad moves it.
// Draws the record's sprite if it is the selected one (unk3D) or the one in unk46.
static void status_draw_bot_sprite(u32 rec, u32 x, u32 y) {
    u32 slot, side, k;

    if (rec <= 2) {
        slot = rec;
        side = 0;
    } else {
        slot = rec - 3;
        side = 1;
    }
    if (slot == gUnk_03000440.unk3D)
        k = 0;
    else if (slot == gUnk_03000440.unk46)
        k = 1;
    else
        return;
    get_bot_part_effective_values(rec, gUnk_03001800.unk64);
    init_battle_medabot_sprites(gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                gUnk_03001800.unk64[3], rec, k * 4, x, y, side, 2, k * 4);
}

void position_battle_team_cursors(u32 first, u32 flag) {
    u32 i;
    u32 x, y;

    for (i = 0; i < 3; i++) {
        if (gUnk_03000590[first + i].unk40) {
            x = gUnk_083AD3A4[(first + i) * 2];
            y = gUnk_083AD3A4[(first + i) * 2 + 1];
            if (first + i <= 2) {
                if (flag)
                    x -= 0x68;
            } else {
                if (flag)
                    x += 0x68;
            }
            status_draw_bot_sprite(first + i, x, y);
        }
    }
}

static void setup_bot_battle_sprites_08017A7C(u32 rec, u32 x, u32 y) {
    u32 slot, side, k;

    if (rec <= 2) {
        slot = rec;
        side = 0;
    } else {
        slot = rec - 3;
        side = 1;
    }
    if (slot == gUnk_03000440.unk3D)
        k = 0;
    else if (slot == gUnk_03000440.unk46)
        k = 1;
    else
        return;
    get_bot_part_effective_values(rec, gUnk_03001800.unk64);
    setup_battle_sprite_group(gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                              gUnk_03001800.unk64[3], rec, k * 4, x, y, side, 2, k * 4);
    gUnk_03002C30[k * 4 + 1].unk0 &= 0xFDFF;
    gUnk_03002C30[k * 4 + 2].unk0 &= 0xFDFF;
}

void status_init_cursor(void) {
    u32 x, y, i;

    gUnk_03002C30[8].unk0 = 0xC404;
    gUnk_03002C30[8].unk1C = 0;
    gUnk_03002C30[8].unkA = 0xE;
    gUnk_03002C30[8].unkB = 0xC0;
    x = gUnk_083AD3A4[(gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3) * 2];
    y = gUnk_083AD3A4[(gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3) * 2 + 1];
    if (gUnk_03000440.unk3C == 0) {
        gUnk_03002C30[8].unk2 = x + 16;
        gUnk_03002C30[8].unk4 = y;
        gUnk_03002C30[8].unk6 = 0x306;
    } else {
        gUnk_03002C30[8].unk2 = x - 16;
        gUnk_03002C30[8].unk4 = y;
        gUnk_03002C30[8].unk6 = 0x307;
    }
}

void status_draw_bot_name(void) {
    clear_sprite_table_mask(9, 13);
    if (gUnk_03000440.unk3C == 0)
        render_text_sprites_08040DB8(gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].medal.unkA, 9, 0x11,
                                     0xE, 10, 15, 0, 0);
    else
        render_text_sprites_08040DB8(gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].medal.unkA, 9, 3, 0xE,
                                     10, 15, 0, 0);
}

static void status_draw_lr_button(u32 a) {
    if (a == 0) {
        if (gUnk_03000440.unk3C == 0)
            draw_tile_block(2, 2, 0x1A, 0x11, REG_BG0CNT, 0x8304);
        else
            draw_tile_block(2, 2, 2, 0x11, REG_BG0CNT, 0x8300);
    } else {
        if (gUnk_03000440.unk3C == 0)
            vram_fill_tilemap_rect(2, 2, 0x1A, 0x11, REG_BG0CNT, 0);
        else
            vram_fill_tilemap_rect(2, 2, 2, 0x11, REG_BG0CNT, 0);
    }
}

void status_blink_lr_button(void) {
    gUnk_03000440.unk86++;
    if (gUnk_03000440.unk86 & 8)
        status_draw_lr_button(0);
    else
        status_draw_lr_button(1);
}

// Status screen: column of 5 row icons at BG1 (9, 2..10)
void status_draw_row_icons(void) {
    u32 i, y;

    for (i = 0, y = 2; i <= 4; y += 2, i++)
        draw_tile_block(2, 2, 9, y, REG_BG1CNT, i * 4 + 0xC370);
}

void status_load_medal_icon(void) {
    CpuFastSet(gUnk_084C21BC + gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].medal.unk1 * 0x80,
               (void *)0x06007800, 0x20);
}

void status_draw_medal_name(void) {
    clear_sprite_table_mask(0x16, 10);
    memcpy_bytes_0803F63C(
        (const void *)gUnk_083B6410[gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].medal.unk1],
        gUnk_03000440.unk9E, 11);
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x16, 0xD, 2, 7, 12, 1, 2);
}

void status_draw_part_names(void) {
    u32 i;

    clear_sprite_table_mask(0x20, 0x38);
    for (i = 0; i <= 3; i++) {
        memcpy_bytes_08041D04(
            (const void *)
                gUnk_083BB9CC[0][gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].parts[i].unk17 * 4 + i],
            gUnk_03000440.unk9E, 15);
        render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x20 + i * 14, 0xD, 4 + i * 2, 10, 13, 1, 2);
    }
}

void status_draw_part_ability_icons(void) {
    u32 i;

    for (i = 0; i <= 3; i++) {
        load_part_data(gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].parts[i].unk17, i,
                       &gUnk_03000440.unkEE);
        memcpy_bytes_08041D04(gUnk_083B6158[gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].medal.unk1],
                              gUnk_03000440.unk10E, 16);
        if (gUnk_03000440.unkEE == gUnk_03000440.unk10E[1])
            draw_tile_block(2, 2, 0xB, i * 2 + 4, REG_BG1CNT, gUnk_03000440.unk10E[7] * 4 + 0xD340);
        else
            draw_tile_block(2, 2, 0xB, i * 2 + 4, REG_BG1CNT, 0xD340);
    }
}

// Status screen ARMOR column: parts[i].unk11 (current) / data[4] (max), grey when broken (runtime-checked "35/35")
void status_draw_part_armor(void) {
    u32 i;
    u16 pal;

    for (i = 0; i <= 3; i++) {
        pal = gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].parts[i].unk11 ? 0xA000 : 0xB000;
        draw_number_tall_bgcnt(gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].parts[i].unk11, 0x17,
                               i * 2 + 4, 3, REG_BG1CNT, pal | 0x390);
        draw_tile_block(1, 2, 0x1A, i * 2 + 4, REG_BG1CNT, pal | 0x3A4);
        draw_number_tall_bgcnt(gUnk_03000590[gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3].parts[i].data[4], 0x1B,
                               i * 2 + 4, 3, REG_BG1CNT, pal | 0x390);
    }
}

void set_portrait_parts(u8 a, u8 b, u8 c, u8 d) {
    gUnk_03000440.unk98 = a;
    gUnk_03000440.unk99 = b;
    gUnk_03000440.unk9A = c;
    gUnk_03000440.unk9B = d;
}

void status_init_portrait(void) {
    struct SpriteTree *obj = (struct SpriteTree *)0x02026000;
    u8 *b;
    u8 *c;
    u32 fill;

    mem_fill8((u8 *)obj, 0xD0, 0);
    b = (u8 *)0x020260D0;
    mem_fill8(b, 0x800, 0);
    c = (u8 *)0x020268D0;
    mem_fill8(c, 0x60, 0);
    gUnk_03000440.unk96 = 1;
    gUnk_03000430 = 2;
    gSpriteWork = (struct SpriteWork *)0x02024000;
    fill = 0;
    CpuFastSet(&fill, (void *)0x02024000, 0x01000426);
    gUnk_03005308 = (struct SceneSlot *)c;
    init_sprite_tree(obj, (u8 *)gSpriteWork, (struct SpriteNodeDesc **)gUnk_083D1BF8, (struct SpriteNodeOam *)b);
    obj->oams = (struct SpriteNodeOam *)b;
    setup_scene_bg_layers_and_sprites(gSpriteWork->oamBuf, obj, gUnk_03000440.unk98, gUnk_03000440.unk99,
                                      gUnk_03000440.unk9A, gUnk_03000440.unk9B, 0x28, 0x28, 0x1C2, 8, 1, 0);
}

void status_reset_portrait(void) {
    struct SpriteTree *obj = (struct SpriteTree *)0x02026000;
    u32 fill;

    obj->oams = (struct SpriteNodeOam *)0x020260D0;
    setup_scene_bg_layers_and_sprites(gSpriteWork->oamBuf, obj, gUnk_03000440.unk98, gUnk_03000440.unk99,
                                      gUnk_03000440.unk9A, gUnk_03000440.unk9B, 0x28, 0x28, 0x1C2, 8, 1, 0);
    fill = 0x200;
    CpuFastSet(&fill, gSpriteWork->oamBuf, 0x01000100);
    gSpriteWork->oamCount = 0;
    gSpriteWork->affineIdx = 0;
}

void status_update_portrait(void) {
    setup_scene_bg_layers_and_sprites(gSpriteWork->oamBuf, (struct SpriteTree *)0x02026000, gUnk_03000440.unk98,
                                      gUnk_03000440.unk99, gUnk_03000440.unk9A, gUnk_03000440.unk9B, 0x44, 0x2A, 0x1C2,
                                      8, 5, 0);
}

u32 status_cursor_x(void) {
    u8 x = gUnk_083AD3A4[(gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3) * 2];

    if (gUnk_03000440.unk3C == 0)
        return x + 16;
    else
        return x - 16;
}

void scroll_bg3_diagonal(void) {
    if (gFrameCounter & 1) {
        gBg3Scroll.x++;
        gBg3Scroll.y++;
    }
}

// Status screen: advance unk46 to the next Medabot slot (0-2), skipping the selected one
void status_next_other_slot(void) {
    if (gUnk_03000440.unk46 == 2)
        gUnk_03000440.unk46 = 0;
    else
        gUnk_03000440.unk46++;
    if (gUnk_03000440.unk3D == gUnk_03000440.unk46) {
        if (gUnk_03000440.unk3D == 2)
            gUnk_03000440.unk46 = 0;
        else
            gUnk_03000440.unk46++;
    }
}

void status_draw_team_sprites(void) {
    u32 i, rec;
    struct Unk_03000590 *recs;

    clear_sprite_table_mask(4, 1);
    clear_sprite_table_mask(5, 1);
    clear_sprite_table_mask(6, 1);
    clear_sprite_table_mask(7, 1);
    for (i = 0, recs = gUnk_03000590; i <= 2; i++) {
        rec = gUnk_03000440.unk3C * 3 + i;
        if (recs[rec].unk40 && i != gUnk_03000440.unk3D)
            status_draw_bot_sprite(rec, gUnk_083AD3A4[rec * 2], gUnk_083AD3A4[rec * 2 + 1]);
    }
    update_battle_sprite_orbiting_positions(0, gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3, gUnk_03000440.unk3C);
}

void status_select_input(void) {
    u8 moved = 0;
    u32 x, y;
    s32 slot;
    u32 base;

    x = gUnk_083AD3A4[(gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3) * 2];
    y = gUnk_083AD3A4[(gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3) * 2 + 1];
    slot = gUnk_03000440.unk3D;
    base = gUnk_03000440.unk3C * 3;
    if (gUnk_03000440.unk3C == 0) {
        if (KEYS_LO(gRepeatKeys) & 0xA0) {
            if (gUnk_03000440.unk3D != 2) {
                if (gUnk_03000590[slot + 1 + base].unk40) {
                    setup_bot_battle_sprites_08017A7C(0, x, y);
                    gUnk_03000440.unk3D++;
                    moved = 1;
                } else if (gUnk_03000440.unk3D == 0 && gUnk_03000590[slot + 2 + base].unk40) {
                    setup_bot_battle_sprites_08017A7C(0, x, y);
                    gUnk_03000440.unk3D = 2;
                    moved = 1;
                }
            }
        } else if (KEYS_LO(gRepeatKeys) & 0x50) {
            if (gUnk_03000440.unk3D != 0) {
                if (gUnk_03000590[slot - 1 + base].unk40) {
                    setup_bot_battle_sprites_08017A7C(0, x, y);
                    gUnk_03000440.unk3D--;
                    moved = 1;
                } else if (gUnk_03000440.unk3D == 2 && gUnk_03000590[slot - 2 + base].unk40) {
                    setup_bot_battle_sprites_08017A7C(0, x, y);
                    gUnk_03000440.unk3D = 0;
                    moved = 1;
                }
            }
        }
    } else {
        if (KEYS_LO(gRepeatKeys) & 0x60) {
            if (gUnk_03000440.unk3D != 0) {
                if (gUnk_03000590[slot - 1 + base].unk40) {
                    setup_bot_battle_sprites_08017A7C(0, x, y);
                    gUnk_03000440.unk3D--;
                    moved = 1;
                } else if (gUnk_03000440.unk3D == 2 && gUnk_03000590[slot - 2 + base].unk40) {
                    setup_bot_battle_sprites_08017A7C(0, x, y);
                    gUnk_03000440.unk3D = 0;
                    moved = 1;
                }
            }
        } else if (KEYS_LO(gRepeatKeys) & 0x90) {
            if (gUnk_03000440.unk3D != 2) {
                if (gUnk_03000590[slot + 1 + base].unk40) {
                    setup_bot_battle_sprites_08017A7C(0, x, y);
                    gUnk_03000440.unk3D++;
                    moved = 1;
                } else if (gUnk_03000440.unk3D == 0 && gUnk_03000590[slot + 2 + base].unk40) {
                    setup_bot_battle_sprites_08017A7C(0, x, y);
                    gUnk_03000440.unk3D = 2;
                    moved = 1;
                }
            }
        }
    }
    if (moved) {
        play_sound_effect(2);
        status_init_cursor();
        status_draw_bot_name();
        status_load_medal_icon();
        status_draw_medal_name();
        status_draw_part_names();
        status_draw_part_ability_icons();
        status_draw_part_armor();
        get_bot_part_effective_values(gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3, gUnk_03001800.unk64);
        set_portrait_parts(gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                           gUnk_03001800.unk64[3]);
        status_reset_portrait();
        position_battle_team_cursors(gUnk_03000440.unk3C * 3, 0);
        battle_sprite_set_palette_index(0, 8);
        draw_tile_block(2, 2, 0xB, 2, REG_BG1CNT, 0x63C0);
    }
}

void status_begin_side_change(void) {
    u32 x = gUnk_083AD3A4[(gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3) * 2];
    u32 y = gUnk_083AD3A4[(gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3) * 2 + 1];

    setup_bot_battle_sprites_08017A7C(gUnk_03000440.unk3D + gUnk_03000440.unk3C * 3, x, y);
    clear_battle_sprite_slot(8, 1);
    status_draw_lr_button(1);
}

u32 status_side_change_scroll_out(void) {
    u32 i, rec, x;
    struct Unk_03000590 *recs;

    clear_sprite_table_mask(4, 1);
    clear_sprite_table_mask(5, 1);
    clear_sprite_table_mask(6, 1);
    clear_sprite_table_mask(7, 1);
    if (gUnk_03000440.unk3C == 0) {
        for (i = 0, recs = gUnk_03000590; i <= 2; i++) {
            rec = gUnk_03000440.unk3C * 3 + i;
            if (recs[rec].unk40) {
                x = gUnk_083AD3A4[rec * 2] - gUnk_03000440.unk40 * 8;
                status_draw_bot_sprite(rec, x, gUnk_083AD3A4[rec * 2 + 1]);
            }
        }
        for (i = 0; i <= 12; i++)
            gUnk_03002C30[9 + i].unk2 -= 8;
        read_vram_tilemap_rect(13, 6, 16 - gUnk_03000440.unk40, 13, REG_BG0CNT, (void *)0x02020000);
        write_vram_tilemap_rect(13, 6, 15 - gUnk_03000440.unk40, 13, REG_BG0CNT, (void *)0x02020000);
    } else {
        for (i = 0, recs = gUnk_03000590; i <= 2; i++) {
            rec = gUnk_03000440.unk3C * 3 + i;
            if (recs[rec].unk40) {
                register u32 k asm("r0") = rec * 2;
                x = gUnk_083AD3A4[k] + gUnk_03000440.unk40 * 8;
                status_draw_bot_sprite(rec, x, gUnk_083AD3A4[k + 1]);
            }
        }
        for (i = 0; i <= 12; i++)
            gUnk_03002C30[9 + i].unk2 += 8;
        read_vram_tilemap_rect(13, 6, gUnk_03000440.unk40 + 1, 13, REG_BG0CNT, (void *)0x02020000);
        write_vram_tilemap_rect(13, 6, gUnk_03000440.unk40 + 2, 13, REG_BG0CNT, (void *)0x02020000);
    }
    if (++gUnk_03000440.unk40 == 14) {
        status_switch_side();
        return 1;
    }
    return 0;
}

static void status_switch_side(void) {
    gUnk_03000440.unk3D = 0;
    gUnk_03000440.unk3C ^= 1;
    position_battle_team_cursors(gUnk_03000440.unk3C * 3, 1);
}

u32 status_side_change_scroll_in(void) {
    u32 i, rec, x;
    struct Unk_03000590 *recs;

    clear_sprite_table_mask(4, 1);
    clear_sprite_table_mask(5, 1);
    clear_sprite_table_mask(6, 1);
    clear_sprite_table_mask(7, 1);
    if (gUnk_03000440.unk3C == 0) {
        for (i = 0, recs = gUnk_03000590; i <= 2; i++) {
            rec = gUnk_03000440.unk3C * 3 + i;
            if (recs[rec].unk40) {
                x = gUnk_083AD3A4[rec * 2] - (13 - gUnk_03000440.unk40) * 8;
                status_draw_bot_sprite(rec, x, gUnk_083AD3A4[rec * 2 + 1]);
            }
        }
    } else {
        for (i = 0, recs = gUnk_03000590; i <= 2; i++) {
            rec = gUnk_03000440.unk3C * 3 + i;
            if (recs[rec].unk40) {
                x = gUnk_083AD3A4[rec * 2] + (13 - gUnk_03000440.unk40) * 8;
                status_draw_bot_sprite(rec, x, gUnk_083AD3A4[rec * 2 + 1]);
            }
        }
    }
    if (++gUnk_03000440.unk40 == 14) {
        status_init_cursor();
        status_draw_bot_name();
        status_load_medal_icon();
        status_draw_medal_name();
        status_draw_part_names();
        status_draw_part_ability_icons();
        status_draw_part_armor();
        return 1;
    }
    return 0;
}
