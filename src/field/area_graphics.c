// Field area graphics: per-frame BG scroll (update_battle_field_frame), animated area tiles, terrain tile
// decompression and palette loads keyed by the current area (gUnk_030057E0.unk7FE), blend registers and
// simple sprite-slot setup. Called by the field modules and the field / pre-battle menus.

#include "global.h"

void update_battle_field_frame(void) {
    gBg1Scroll.x = gUnk_03005310.unk1E;
    gBg1Scroll.y = gUnk_03005310.unk26;
    gBg2Scroll.x = gUnk_03005310.unk20;
    gBg2Scroll.y = gUnk_03005310.unk28;
    gBg3Scroll.x = gUnk_03005310.unk22;
    gBg3Scroll.y = gUnk_03005310.unk2A;
    sub_080482C0();
    dma_load_battle_palettes();
    load_room_graphics();
    gUnk_030057E0.unkC36 = 0;
    animate_area_bg_tiles();
    load_map_npc_sprites(gUnk_030057E0.unkCBA);
    update_entity_sprites_on_screen();
    init_battle_field_setup();
    update_bg_scroll_offsets_a();
    init_battle_medaforce_sprite();
    update_bg_scroll_offsets_b();
    decompress_battle_tile_graphics();
    gUnk_030057E0.unkC4C = 1;
    update_battle_entity_status_chars();
}

void animate_area_bg_tiles(void) {
    const u8 *anim = gUnk_084096F4[gUnk_030057E0.unk7FE];
    u8 n = anim[0];
    u8 *src;

    if (gUnk_030057E0.unkC34 != 0 && anim[2] != 0) {
        if (gUnk_030057E0.unkC36 != 0) {
            gUnk_030057E0.unkC36--;
        } else {
            if (anim[gUnk_030057E0.unkC35 + 3] == 0xFF)
                gUnk_030057E0.unkC35 = 0;
            src = gUnk_030057DC + anim[gUnk_030057E0.unkC35 + 3] * n * 32;
            DmaSet(3, src, 0x06009020, 0x80000000 | (n << 4));
            gUnk_030057E0.unkC35++;
            gUnk_030057E0.unkC36 = 2;
        }
    }
}

s32 sub_080481C4(s32 t) {
    s32 u;
    if (t == 0)
        t = gUnk_083D29A6[gUnk_030057E0.unkC5C];
    else if (t <= 0xAF)
        ;
    else if (t <= 0xBF)
        ;
    else if (t <= 0xCF)
        ;
    else if (t <= 0xFE) {
        const u8 *tbl = gUnk_08414394[t - 0xD0];
        t = tbl[gUnk_030057E0.unkC38[t - 0xD0]];
    } else
        t = 0xFF;
    if (t != 0xFF && t > 0xBF)
        t = (t - 0xC0) * 2 + (u = gUnk_03006D38.unk6 + 0x28);
    return t;
}

void decompress_battle_tile_graphics(void) {
    s32 i = 0;
    u8 *dst = (u8 *)0x06010000;
    u32 t;

    while ((t = resolve_tile_from_battle_state(i)) != 0xFF) {
        if (gUnk_083F80F4[t] == NULL)
            t = 1;
        LZ77UnCompVram(gUnk_083F80F4[t], dst);
        dst += 0x900;
        i++;
    }
}

void decompress_terrain_tiles_to_vram(s32 arg) {
    s32 i;
    u8 *dst;
    const u8 *const *tbl;
    s32 t = sub_080481C4(arg);

    tbl = gUnk_083F80F4;
    dst = (u8 *)0x06010000;
    for (i = 11; i >= 0; i--) {
        if (tbl[t] == NULL)
            t = 1;
        LZ77UnCompVram(tbl[t], dst);
        dst += 0x900;
    }
}

void sub_080482C0(void) {
    const u16 *pal = gUnk_083F9BF4[gUnk_030057E0.unk7FE];

    if (pal != NULL) {
        DmaSet(3, pal, 0x0202FA00, 0x84000068);
    } else {
        DmaSet(3, gUnk_080AC5B4, 0x0202FA00, 0x84000008);
        DmaSet(3, gUnk_080AC654, 0x0202FA20, 0x84000008);
        DmaSet(3, gUnk_080AC6F4, 0x0202FA40, 0x84000008);
        DmaSet(3, gUnk_080AC794, 0x0202FA60, 0x84000008);
        DmaSet(3, gUnk_080AC5B4, 0x0202FA80, 0x84000008);
        DmaSet(3, gUnk_080AC5B4, 0x0202FAA0, 0x84000008);
        DmaSet(3, gUnk_080AC5B4, 0x0202FAC0, 0x84000008);
        DmaSet(3, gUnk_080AC834, 0x0202FAE0, 0x84000008);
        DmaSet(3, gUnk_080AC8D4, 0x0202FB00, 0x84000008);
    }
}

u8 sub_080483AC(void) {
    if (gUnk_030057E0.unkC30 == 0xFF)
        return gUnk_030057E0.unkC31;
    return gUnk_0847EB80[gUnk_030057E0.unk7FE];
}

// sub_080483AC returns its u8 widened: the original uses r0 untruncated here.
#define sub_080483AC() ((u32(*)(void))sub_080483AC)()

u32 dispatch_jump_table_29(u32 a, u32 b) {
    u32 t;
    u32 v;
    u32 w;

    switch (a) {
    case 0:
    case 10:
    case 12:
        if (gUnk_030057E0.unkC30 != 0xFF) {
            v = sub_080483AC();
            if (gUnk_030057E0.unkC30 != v) {
                gUnk_030057E0.unkC30 = v;
                sub_08047BB4(v);
            }
        }
        break;
    case 1:
        gUnk_030057E0.unkC30 = b;
        sub_08047BB4(b);
        break;
    case 2:
        gUnk_030057E0.unkC30 = 0;
        sub_08047BB4(0);
        break;
    case 3:
        if (gUnk_030057E0.unkC30 == 0xFF) {
            if (b & 0x80) {
                gUnk_030057E0.unkC31 = b & 0x7F;
                gUnk_030057E0.unkC30 |= 0xFF;
            }
            break;
        }
        if (!(b & 0x80)) {
            gUnk_030057E0.unkC31 = b & 0x7F;
            sub_08047BB4(b);
            gUnk_030057E0.unkC30 = 0xFF;
            break;
        }
        gUnk_030057E0.unkC31 = b & 0x7F;
        gUnk_030057E0.unkC30 |= 0xFF;
        break;
    case 4:
        t = gUnk_030057E0.unkC30;
        gUnk_030057E0.unkC30 = 0;
        v = sub_080483AC();
        if (t != v) {
            gUnk_030057E0.unkC30 = v;
            sub_08047BB4(v);
        } else
            gUnk_030057E0.unkC30 = v;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 19:
    case 28:
        v = sub_080483AC();
        gUnk_030057E0.unkC30 = v;
        sub_08047BB4(v);
        break;
    case 11:
    case 13:
    case 14:
    case 15:
    case 21:
    case 22:
    case 26:
        if (gUnk_030057E0.unkC30 != 0xFF) {
            v = sub_080483AC();
            gUnk_030057E0.unkC30 = v;
            sub_08047BB4(v);
        } else
            sub_08047BB4(gUnk_030057E0.unkC31);
        break;
    case 23:
        if (gUnk_083D29B6[gUnk_03006D38.unk1 * 4])
            sub_08047BC0(0x1E);
        break;
    case 24:
        if (gUnk_083D29B6[gUnk_03006D38.unk1 * 4]) {
            w = gUnk_083D29B6[gUnk_03006D38.unk1 * 4 + 1];
            gUnk_030057E0.unkC30 = w;
            sub_08047BB4(w);
        }
        break;
    case 25:
        switch (gUnk_083D29B6[gUnk_03006D38.unk1 * 4 + 2]) {
        case 1:
            w = gUnk_083D29B6[gUnk_03006D38.unk1 * 4 + 3];
            gUnk_030057E0.unkC30 = w;
            sub_08047BB4(w);
            break;
        case 2:
            w = sub_080483AC();
            gUnk_030057E0.unkC30 = w;
            sub_08047BB4(w);
            break;
        }
        break;
    }
}

#undef sub_080483AC

u32 resolve_tile_from_battle_state(u32 arg) {
    return sub_080481C4(gUnk_08413514[gUnk_030057E0.unk7FE][arg]);
}

void dma_load_obj_palettes_08048664(void) {
    s32 i;
    u32 t;

    for (i = 0; (t = resolve_tile_from_battle_state(i)) != 0xFF; i++) {
        t = resolve_tile_from_battle_state(i);
        if (gUnk_083F8634[t] == NULL)
            t = 1;
        DmaSet(3, gUnk_083F8634[t], 0x05000200 + i * 0x20, 0x84000008);
    }
}

void dma_load_battle_palettes(void) {
    s32 i;
    u32 t;

    for (i = 0; (t = resolve_tile_from_battle_state(i)) != 0xFF; i++) {
        t = resolve_tile_from_battle_state(i);
        if (gUnk_083F8634[t] == NULL)
            t = 1;
        DmaSet(3, gUnk_083F8634[t], 0x0202F800 + i * 0x20, 0x84000008);
    }
    DmaSet(3, gUnk_085FA0E4, 0x0202F9C0, 0x84000008);
}

void dma_load_obj_palettes_08048730(s32 arg) {
    s32 i = 0;
    s32 t = sub_080481C4(arg);

    for (; i <= 11; i++) {
        if (gUnk_083F8634[t] == NULL)
            t = 1;
        DmaSet(3, gUnk_083F8634[t], 0x05000200 + i * 0x20, 0x84000008);
    }
}

void sub_0804877C(u8 idx) {
    u8 v = gUnk_083D2ADD[gUnk_03002C30[idx].unk30];

    if (v == 2)
        gUnk_03002C30[idx].unkB = 0xFF;
    else if (v == 1)
        gUnk_03002C30[idx].unkB = 0;
    else
        gUnk_03002C30[idx].unkB = 0x40;
}

static void sub_080487AC(void) {
    vu16 *bldalpha;
    u16 v;

    REG_BLDCNT = 0x1F41;
    gUnk_03006F40.unkC = 12.0f;
    gUnk_03006F40.unk10 = 8.0f;
    bldalpha = &REG_BLDALPHA;
    v = 0x80C;
    *bldalpha = v;
}

void sub_080487E4(void) {
    vu16 *bldalpha;
    u16 v;

    REG_BLDCNT = 0xF40;
    gUnk_03006F40.unkC = 12.0f;
    gUnk_03006F40.unk10 = 10.0f;
    bldalpha = &REG_BLDALPHA;
    v = 0xA0C;
    *bldalpha = v;
}

void init_battle_sprite_entry_08048818(u8 slot, u16 a, u32 frame, u8 c, u8 d) {
    gUnk_03002C30[slot].unk0 = a;
    gUnk_03002C30[slot].unk32 = a;
    gUnk_03002C30[slot].unk6 = frame;
    gUnk_03002C30[slot].unkA = c;
    gUnk_03002C30[slot].unk1C = d;
}

void clear_battle_sprite_entry(u8 slot) {
    sub_080496C8((u8 *)&gUnk_03002C30[slot], 0x40);
    clear_entity_state(slot);
}
