// Sprites and tilemap windows for action effects: the target's armor panel on BG1 (part icons, bars, current / max
// armor numbers: armor_panel_*), armor drain per frame, hit sparks and damage digits placed at a part through the
// offset tables gUnk_083AF380..gUnk_083AF4A0, and the OAM / animation-frame helpers used by every skill module.

#include "global.h"

static void armor_bar_draw(u32 x, u32 y, u32 w, u32 max, u32 cur);

void armor_panel_draw_icons(u32 side) {
    u32 x = 2;
    if (side == 0)
        x = 0x10;
    draw_tile_block(2, 2, x, 1, REG_BG1CNT, 0xB340);
    draw_tile_block(2, 2, x, 4, REG_BG1CNT, 0xB344);
    draw_tile_block(2, 2, x, 7, REG_BG1CNT, 0xB348);
    draw_tile_block(2, 2, x, 10, REG_BG1CNT, 0xB34C);
}

void armor_panel_draw_frame(u32 side) {
    u32 x = 4;
    if (side == 0)
        x = 0x12;
    set_tilemap_and_decompress_bg(x, 0, gUnk_084889B4, REG_BG1CNT, 0x329);
}

void armor_panel_draw_bars(u32 side, u32 rec) {
    u32 x = 5;
    if (side == 0)
        x = 0x13;
    armor_bar_draw(x, 1, 0x40, gBattleBots[rec].parts[0].data[4], gBattleBots[rec].parts[0].unk11);
    armor_bar_draw(x, 4, 0x40, gBattleBots[rec].parts[1].data[4], gBattleBots[rec].parts[1].unk11);
    armor_bar_draw(x, 7, 0x40, gBattleBots[rec].parts[2].data[4], gBattleBots[rec].parts[2].unk11);
    armor_bar_draw(x, 10, 0x40, gBattleBots[rec].parts[3].data[4], gBattleBots[rec].parts[3].unk11);
}

static void armor_bar_draw(u32 x, u32 y, u32 w, u32 max, u32 cur) {
    u32 full, rem, col, i;

    full = scale_to_bar_fill(w, max, cur);
    rem = full & 0xFFFF;
    full >>= 16;

    if (cur != 0 && full == 0 && rem == 0)
        rem = 1;
    col = 0;
    for (i = 0; i < full; i++) {
        draw_tile_block(1, 1, x + col, y, REG_BG1CNT, 0xA328);
        col++;
    }
    if (rem) {
        draw_tile_block(1, 1, x + col, y, REG_BG1CNT, 0xA320 + rem);
        col++;
    }
    for (i = col; i <= 7; i++) {
        draw_tile_block(1, 1, x + col, y, REG_BG1CNT, 0xA320);
        col++;
    }
}

void armor_panel_draw_numbers(u32 side, u32 rec) {
    u32 x;
    u32 y;

    x = 6;
    if (side == 0)
        x = 0x14;
    y = 2;
    if (gBattleBots[rec].parts[0].unk11 != 0) {
        draw_number_bgcnt(gBattleBots[rec].parts[0].unk11, x, y, 3, REG_BG1CNT, 0xA330);
        draw_number_bgcnt(gBattleBots[rec].parts[0].data[4], x + 4, y, 3, REG_BG1CNT, 0xA330);
    } else {
        draw_number_bgcnt(gBattleBots[rec].parts[0].unk11, x, y, 3, REG_BG1CNT, 0x8330);
        draw_number_bgcnt(gBattleBots[rec].parts[0].data[4], x + 4, y, 3, REG_BG1CNT, 0x8330);
    }
    if (gBattleBots[rec].parts[1].unk11 != 0) {
        draw_number_bgcnt(gBattleBots[rec].parts[1].unk11, x, y + 3, 3, REG_BG1CNT, 0xA330);
        draw_number_bgcnt(gBattleBots[rec].parts[1].data[4], x + 4, y + 3, 3, REG_BG1CNT, 0xA330);
    } else {
        draw_number_bgcnt(gBattleBots[rec].parts[1].unk11, x, y + 3, 3, REG_BG1CNT, 0x8330);
        draw_number_bgcnt(gBattleBots[rec].parts[1].data[4], x + 4, y + 3, 3, REG_BG1CNT, 0x8330);
    }
    if (gBattleBots[rec].parts[2].unk11 != 0) {
        draw_number_bgcnt(gBattleBots[rec].parts[2].unk11, x, y + 6, 3, REG_BG1CNT, 0xA330);
        draw_number_bgcnt(gBattleBots[rec].parts[2].data[4], x + 4, y + 6, 3, REG_BG1CNT, 0xA330);
    } else {
        draw_number_bgcnt(gBattleBots[rec].parts[2].unk11, x, y + 6, 3, REG_BG1CNT, 0x8330);
        draw_number_bgcnt(gBattleBots[rec].parts[2].data[4], x + 4, y + 6, 3, REG_BG1CNT, 0x8330);
    }
    if (gBattleBots[rec].parts[3].unk11 != 0) {
        draw_number_bgcnt(gBattleBots[rec].parts[3].unk11, x, y + 9, 3, REG_BG1CNT, 0xA330);
        draw_number_bgcnt(gBattleBots[rec].parts[3].data[4], x + 4, y + 9, 3, REG_BG1CNT, 0xA330);
    } else {
        draw_number_bgcnt(gBattleBots[rec].parts[3].unk11, x, y + 9, 3, REG_BG1CNT, 0x8330);
        draw_number_bgcnt(gBattleBots[rec].parts[3].data[4], x + 4, y + 9, 3, REG_BG1CNT, 0x8330);
    }
}

u32 effect_sprite_fly_to_part(u32 slot, u32 part) {
    s16 dx, dy;
    struct SpriteEntry *base = gSpriteEntries;
    struct SpriteEntry *s = &base[slot];
    u8 *frame;

    if (!(s->unk0 & 0x8000) || *(frame = &s->unk23) == 0x10)
        return 1;
    switch (part) {
    case 0:
        dx = gUnk_083AF380[*frame << 1];
        dy = gUnk_083AF380[*frame * 2 + 1];
        break;
    case 1:
        dx = gUnk_083AF3C0[*frame << 1];
        dy = gUnk_083AF3C0[*frame * 2 + 1];
        break;
    case 2:
        dx = gUnk_083AF400[*frame << 1];
        dy = gUnk_083AF400[*frame * 2 + 1];
        break;
    case 3:
        dx = gUnk_083AF440[*frame << 1];
        dy = gUnk_083AF440[*frame * 2 + 1];
        break;
    }
    gSpriteEntries[slot].unk2 = (dx + gSpriteEntries[slot].unk2) & 0x1FF;
    gSpriteEntries[slot].unk4 = (dy + gSpriteEntries[slot].unk4) & 0xFF;
    gSpriteEntries[slot].unk23++;
    return 0;
}

void hit_sparks_spawn(u32 slot, u32 part, s16 x, s16 y) {
    u32 i;
    s32 t, u;

    clear_battle_sprite_slot(slot, 4);
    for (i = 0; i <= 3; i++) {
        gSpriteEntries[slot + i].unk0 = 0x4404;
        gSpriteEntries[slot + i].unk1C = 0;
        gSpriteEntries[slot + i].unkA = 0xE;
        gSpriteEntries[slot + i].unkB = 0x80;
        gSpriteEntries[slot + i].unk2C = i * 8;
        u = gUnk_083AF480[part << 1] + x;
        t = gUnk_083AF490[i * 2];
        t += u;
        gSpriteEntries[slot + i].unk2 = t & 0x1FF;
        u = gUnk_083AF480[part * 2 + 1] + y;
        t = gUnk_083AF490[i * 2 + 1];
        t += u;
        gSpriteEntries[slot + i].unk4 = t & 0xFF;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[29], slot + i);
    }
}

u32 hit_sparks_update(u32 slot) {
    u32 done = 1;
    u32 i;
    u8 n;

    for (i = 0; i <= 3; i++) {
        if (gSpriteEntries[slot + i].unk0 != 0) {
            if (gSpriteEntries[slot + i].unk2C == 0) {
                gSpriteEntries[slot + i].unk0 |= 0x8004;
                gSpriteEntries[slot + i].unkA = 0xE;
                process_sprite_anim_commands(gUnk_083B5F80[29], n = slot + i);
                if (gSpriteEntries[slot + i].unk22 == 0xFF)
                    clear_battle_sprite_slot(n, 1);
                else
                    done = 0;
            } else {
                gSpriteEntries[slot + i].unk2C--;
                done = 0;
            }
        }
    }
    return done;
}

void damage_digits_spawn(u8 *digits, u32 slot, u32 part, s16 x, s16 y) {
    u32 i = 0;
    s32 t;
    s32 u;
    for (; i <= 4; i++) {
        if (digits[i] == 0xFE)
            return;
        gSpriteEntries[slot + i].unk0 = 0xC624;
        gSpriteEntries[slot + i].unk1C = 0;
        t = x;
        t += gUnk_083AF480[part << 1];
        gSpriteEntries[slot + i].unk2 = t & 0x1FF;
        u = y;
        u += gUnk_083AF480[part * 2 + 1];
        gSpriteEntries[slot + i].unk4 = u & 0xFF;
        gSpriteEntries[slot + i].unkB = 0x80;
        gSpriteEntries[slot + i].unk6 = digits[i] + 0x2D00;
        gSpriteEntries[slot + i].unk23 = 0;
        gSpriteEntries[slot + i].unk9 = 0x40;
        gSpriteEntries[slot + i].unk8 = 0x40;
        gSpriteEntries[slot + i].unkA = 0xE;
        switch (digits[6]) {
        case 2:
            gSpriteEntries[slot + i].unk2 = 0xFFFC + gSpriteEntries[slot + i].unk2 + i * 8;
            break;
        case 3:
            gSpriteEntries[slot + i].unk2 = 0xFFF8 + gSpriteEntries[slot + i].unk2 + i * 8;
            break;
        case 4:
            gSpriteEntries[slot + i].unk2 = 0xFFF4 + gSpriteEntries[slot + i].unk2 + i * 8;
            break;
        }
    }
}

void setup_battle_sprite_oam_entries(u8 *buf, u32 slot, u32 part, s16 x, s16 y) {
    u32 i = 0;
    s32 t;
    s32 u;
    for (; i <= 4; i++) {
        if (buf[i] == 0xFE)
            return;
        gSpriteEntries[slot + i].unk0 = 0xC404;
        gSpriteEntries[slot + i].unk1C = 0;
        t = x;
        t += gUnk_083AF480[part << 1];
        gSpriteEntries[slot + i].unk2 = t & 0x1FF;
        u = y;
        u += gUnk_083AF480[part * 2 + 1];
        gSpriteEntries[slot + i].unk4 = u & 0xFF;
        gSpriteEntries[slot + i].unkB = 0x80;
        gSpriteEntries[slot + i].unk6 = buf[i] + 0x2D00;
        gSpriteEntries[slot + i].unk23 = 0;
        gSpriteEntries[slot + i].unkA = 0xE;
        switch (buf[6]) {
        case 2:
            gSpriteEntries[slot + i].unk2 = 0xFFFC + gSpriteEntries[slot + i].unk2 + i * 8;
            break;
        case 3:
            gSpriteEntries[slot + i].unk2 = 0xFFF8 + gSpriteEntries[slot + i].unk2 + i * 8;
            break;
        case 4:
            gSpriteEntries[slot + i].unk2 = 0xFFF4 + gSpriteEntries[slot + i].unk2 + i * 8;
            break;
        }
    }
}

u32 advance_sprite_anim_frame(u32 sprite, u32 b) {
    s32 f;
    if (!(gSpriteEntries[sprite].unk0 & 0x8000) || gSpriteEntries[sprite].unk23 == 0x10)
        return 1;
    gSpriteEntries[sprite].unk4 = (gSpriteEntries[sprite].unk4 + gUnk_083AF4A0[gSpriteEntries[sprite].unk23]) & 0xFF;
    f = gSpriteEntries[sprite].unk23 + 1;
    gSpriteEntries[sprite].unk23 = f;
    if (b)
        gSpriteEntries[sprite].unk9 = f * 4 + 0x40;
    return 0;
}

u32 advance_sprite_group_anims(u8 *digits, u32 slot) {
    u32 busy = 0;
    u32 i = 0;

    goto test;
    for (;;) {
        i++;
    test:
        if (i > 4 || digits[i] == 0xFE)
            goto done;
        if (advance_sprite_anim_frame(slot + i, 1))
            busy = 1;
    }
done:
    return busy;
}

u32 sprite_group_rise_step(u8 *buf, u32 slot) {
    u32 busy = 0;
    u32 i = 0;

    goto test;
    for (;;) {
        i++;
    test:
        if (i > 4 || buf[i] == 0xFE)
            goto done;
        if (advance_sprite_anim_frame(slot + i, 0))
            busy = 1;
    }
done:
    return busy;
}

void battle_set_damage_break_part(u32 rec, u32 part) {
    gBattleWork.unkC8 = gBattleBots[rec].parts[part].unk11;
    gBattleWork.unkCC = gBattleBots[rec].parts[part].unk11;
    gBattleWork.unkD1 = 1;
}

u32 armor_drain_step(u16 *amount, u32 rec, u32 part) {
    u8 *n = (u8 *)amount;
    if (gBattleBots[rec].parts[part].unk11 != 0 && *n != 0) {
        (*n)--;
        gBattleBots[rec].parts[part].unk11--;
        return 0;
    }
    return 1;
}

void armor_panel_clear(u32 side) {
    u32 y = 2;
    if (side == 0)
        y = 0x10;
    vram_fill_tilemap_rect(0xC, 0xD, y, 0, REG_BG1CNT, 0);
}

void effect_sprite_spawn_at_part(u32 slot, u32 part, s16 x, s16 y, u32 n) {
    struct SpriteEntry *s;
    struct SpriteEntry *base;
    s32 t1, t2;

    clear_battle_sprite_slot(slot, 1);
    base = gSpriteEntries;
    s = &base[slot];
    s->unk0 = 0xC404;
    s->unk1C = 0;
    s->unkA = 0xE;
    s->unkB = 0x80;
    t1 = gUnk_083AF480[part << 1] + x;
    s->unk2 = t1 & 0x1FF;
    t2 = gUnk_083AF480[part * 2 + 1] + y;
    s->unk4 = t2 & 0xFF;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[n], slot);
}
