#include "global.h"

s32 sub_0804D8A8(u16 id) {
    s32 i;
    for (i = 0; i < 64; i++)
        if ((gUnk_030057E0.unk5DC[i].unk2 & 0xFFF) == id)
            return i;
    if (i == 64)
        return -1;
}

struct MapObject *battle_find_entity_by_id(u16 id) {
    s32 i;
    for (i = 0; i < 64; i++)
        if ((gUnk_030057E0.unk5DC[i].unk2 & 0xFFF) == id)
            return &gUnk_030057E0.unk5DC[i];
    if (i == 64)
        return NULL;
}

void sub_0804D934(struct MapObject *obj) {
    u8 *raw = (u8 *)obj;
    const u8 *tiles = gUnk_084045A8[gUnk_030057E0.unk7FE];
    set_tile_data(obj->x, obj->y, tiles[obj->y * (gUnk_030057E0.unk800 >> 1) + obj->x]);
    if (obj->unk4_6) {
        clear_battle_sprite_entry(obj->unk4_0 + 49);
        clear_battle_sprite_entry(obj->unk4_0 + 91);
    }
    sub_080496C8(raw, 8);
}

void sub_0804D9AC(u8 i) {
    clear_battle_sprite_entry(48);
    clear_battle_sprite_entry(90);
    memcpy_u8(&gUnk_03002C30[i], &gUnk_03002C30[48], 0x40);
    memcpy_u8(&gUnk_030055A0[i], &gUnk_030055A0[48], 4);
    gUnk_030057E0.unkC76 = 1;
    gUnk_030057E0.unkC6E = gUnk_03002C30[48].unk2 + gBg1Scroll.x;
    gUnk_030057E0.unkC70 = gUnk_03002C30[48].unk4 + gBg1Scroll.y;
    gUnk_030057E0.unkC72 = sub_080526F0(gUnk_030057E0.unkC6E);
    gUnk_030057E0.unkC73 = sub_08052714(gUnk_030057E0.unkC70);
    gUnk_030057E0.unkC84 = gUnk_03002C30[48].unk2B;
    sub_08051E8C();
    sub_080493D4(48, sub_080502B4(48, gUnk_03002C30[48].unk2B * 4 + gUnk_03002C30[48].unk21));
    init_battle_sprite_entry_08048818(90, 0xCC0C, 0x90, 0xE, 1);
    gUnk_03002C30[90].unk2 = gUnk_03002C30[48].unk2;
    gUnk_03002C30[90].unk4 = gUnk_03002C30[48].unk4 - 5;
    gUnk_03002C30[90].unkC_8 = gUnk_03002C30[48].unkC_8;
    gUnk_03002C30[90].unk10_8 = gUnk_03002C30[48].unk10_8 - 5;
    update_battle_direction_indicator(1);
    gUnk_030057E0.unkC5E = gUnk_030057E0.unkC5D;
    gUnk_030057E0.unkC5D = 0xDF;
}

void sub_0804DB34(void) {
    clear_battle_sprite_entry(48);
    clear_battle_sprite_entry(90);
    gUnk_030057E0.unkC76 = 0;
    gUnk_030057E0.unkC5D = gUnk_030057E0.unkC5E;
}

void sub_0804DB68(u8 i) {
    gUnk_030057E0.unkCA4[i] = 0;
}

void sub_0804DB84(u8 i, u8 v) {
    gUnk_030057E0.unkCA4[i] = v + 1;
}

u32 sub_0804DBA4(u8 i) {
    return gUnk_030057E0.unkCA4[i] - 1;
}

void map_script_update_command(void) {
    gMapScriptUpdates[gUnk_030057E0.unkC92]();
}

void nullsub_0804DBE8(void) {}

// Opcode 1 update: shows message (C94[1] << 8 | C94[2]) of text bank C94[0] (runtime: bank 2, id 1
// is the lab intro "Good afternoon!"), finishes once the text window closes.
void map_script_update_message(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;
    const u32 *const *tbl;

    switch (s->unkC93) {
    case 0:
        init_cursor_state();
        gUnk_030057A0.unk2E = s->unkC94[0] - 2;
        gUnk_030057A0.unk30 = (s->unkC94[1] << 8) | s->unkC94[2];
        if (sub_0804B6EC())
            map_script_command_done();
        s->unkC93++;
        break;
    case 1:
        if (s->unkC94[0] < 2)
            tbl = (const u32 *const *)gTextTable;
        else
            tbl = gTextBankTables[s->unkC94[0] - 2];
        if (scene_transition_step_08047C24(0, 0, 0, tbl[(s->unkC94[1] << 8) | s->unkC94[2]]))
            map_script_command_done();
        break;
    }
}

void sub_0804DCAC(void) {
    map_script_command_done();
}

void sub_0804DCB8(void) {
    if (game_state_execute_handler_a())
        map_script_command_done();
}

void sub_0804DCCC(void) {
    if (gUnk_030057E0.unkC94[0] != 0)
        gUnk_030057E0.unkC94[0]--;
    else
        map_script_command_done();
}

void sub_0804DCF0(void) {
    if (KEY_BITS(gNewKeys).a | KEY_BITS(gNewKeys).start)
        map_script_command_done();
}

void sub_0804DD10(void) {
    if (run_blend_fade_transition(0))
        map_script_command_done();
}

void sub_0804DD24(void) {
    if (run_blend_fade_transition(0))
        map_script_command_done();
}

void sub_0804DD38(void) {
    if (run_blend_fade_transition(0x7FFF))
        map_script_command_done();
}

void sub_0804DD50(void) {
    if (run_blend_fade_transition(0x7FFF))
        map_script_command_done();
}

void sub_0804DD68(void) {
    sub_0804DD80();
}

void sub_0804DD74(void) {
    sub_0804DD80();
}

void sub_0804DD80(void) {
    sub_080482C0();
    dma_load_battle_palettes();
    load_room_graphics();
    load_battlefield_data_to_buffer();
    gUnk_030057E0.unkC35 = 0;
    gUnk_030057E0.unkC36 = 0;
    animate_area_bg_tiles();
    load_battle_terrain_data();
    gUnk_030057E0.unkC52 = gUnk_030057E0.unkC56 * 16 + gUnk_030057E0.unkC48;
    gUnk_030057E0.unkC54 = gUnk_030057E0.unkC57 * 16 + gUnk_030057E0.unkC4A;
    init_battle_field_setup();
    update_bg_scroll_offsets_a();
    gUnk_03002C30[47].unk25 = 1;
    field_set_player_facing(gUnk_030057E0.unkC67);
    update_cursor_tile_position();
    decompress_battle_tile_graphics();
    map_script_command_done();
}

void sub_0804DE28(void) {
    switch (gUnk_03002C30[47].unk26) {
    case 0:
        if (gUnk_03002C30[47].unk28 < 16) {
            gUnk_03002C30[47].unk4 = gUnk_030057E0.unkC94[0] - gUnk_083D69A0[gUnk_03002C30[47].unk28][0] / 16;
            gUnk_03002C30[47].unk28++;
            if (gUnk_03002C30[47].unk4 / 4 <= (gUnk_030057E0.unkC94[0] - 16) / 4)
                gUnk_03002C30[47].unkB = 0xFF;
            else
                sub_0804877C(47);
        } else {
            gUnk_03002C30[47].unk26 = 1;
            gUnk_03002C30[47].unk28 = 0;
        }
        break;
    case 1:
        sub_0804877C(47);
        gUnk_03002C30[47].unk4 = gUnk_030057E0.unkC94[0];
        map_script_command_done();
        break;
    }
}

void sub_0804DEF4(void) {
    switch (gUnk_030057E0.unkC93) {
    case 0:
        memcpy_u8(gUnk_030057E0.unkC10, gUnk_030057E0.unkC18, 8);
        gUnk_030057E0.unkC10[0] = 0;
        gUnk_030057E0.unkC10[3] = 0;
        gUnk_030057E0.unkC10[7] = 0;
        field_set_player_facing(gUnk_030057E0.unkC94[0]);
        memcpy_u8(&gUnk_03002C30[47], &gUnk_03002C30[46], 0x40);
        gUnk_030057E0.unkC5B = 0;
        sub_08052BA0(0);
        gUnk_03002C30[89].unk0 = 0xCC0C;
        gUnk_03002C30[48].unk0 = 0;
        gUnk_03002C30[47].unk28 = 0;
        gUnk_030057E0.unkC5F = 1;
        sub_08050B50();
        sub_08047BA8(0x70);
        gUnk_030057E0.unkC93++;
        break;
    case 1:
        sub_08050B50();
        switch (gUnk_030057E0.unkC94[0]) {
        case 0:
            KEYS_LO(gHeldKeys) |= 0x40;
            break;
        case 1:
            KEYS_LO(gHeldKeys) |= 0x80;
            break;
        case 2:
            KEYS_LO(gHeldKeys) |= 0x20;
            break;
        case 3:
            KEYS_LO(gHeldKeys) |= 0x10;
            break;
        }
        gUnk_03002C30[46].unk2 = gUnk_03002C30[47].unk2;
        if (gUnk_03002C30[47].unk28 < 16 / sub_080518F4(47) * 2) {
            gUnk_03002C30[46].unk4 =
                gUnk_03002C30[47].unk4 - gUnk_083D69A0[0][gUnk_03002C30[47].unk28 * (sub_080518F4(47) << 2)] / 16;
            gUnk_03002C30[47].unk28++;
            if (gUnk_03002C30[46].unk4 / 4 <= (gUnk_03002C30[47].unk4 - 16) / 4)
                gUnk_03002C30[46].unkB = 0xFF;
            else
                sub_0804877C(46);
        } else {
            gUnk_03002C30[47].unk26++;
            gUnk_03002C30[47].unk28 = 0;
            memcpy_u8(gUnk_030057E0.unkC18, gUnk_030057E0.unkC10, 8);
            clear_battle_sprite_entry(46);
            gUnk_030057E0.unkC5B = 1;
            sub_08052BA0(1);
            gUnk_030057E0.unkC5F = 0;
            map_script_command_done();
        }
        break;
    }
}

void sub_0804E0E8(void) {
    switch (gUnk_030057E0.unkC93) {
    case 0:
        sub_08050B50();
        if (gUnk_030057E0.unkC94[gUnk_03002C30[47].unk26] == 0xFF) {
            gUnk_030057E0.unkC93++;
            break;
        }
        if (gUnk_03002C30[47].unk28 == 0)
            break;
        switch ((gUnk_030057E0.unkC94[gUnk_03002C30[47].unk26] & 0xF0) >> 4) {
        case 0:
            KEYS_LO(gHeldKeys) |= 0x40;
            break;
        case 1:
            KEYS_LO(gHeldKeys) |= 0x80;
            break;
        case 2:
            KEYS_LO(gHeldKeys) |= 0x20;
            break;
        case 3:
            KEYS_LO(gHeldKeys) |= 0x10;
            break;
        }
        gUnk_03002C30[47].unk28--;
        if (gUnk_03002C30[47].unk28 != 0)
            break;
        gUnk_03002C30[47].unk28 = 16 / sub_080518F4(47);
        gUnk_03002C30[47].unk27--;
        if (gUnk_03002C30[47].unk27 != 0)
            break;
        gUnk_030057E0.unkC56 = sub_080526F0(gUnk_030057E0.unkC52);
        gUnk_030057E0.unkC57 = sub_08052714(gUnk_030057E0.unkC54);
        if (gUnk_030057E0.unkC76 != 0) {
            gUnk_030057E0.unkC72 = sub_080526F0(gUnk_030057E0.unkC6E);
            gUnk_030057E0.unkC73 = sub_08052714(gUnk_030057E0.unkC70);
        }
        gUnk_03002C30[47].unk26++;
        if (gUnk_03002C30[47].unk26 > 3) {
            gUnk_030057E0.unkC93++;
            break;
        }
        if (gUnk_030057E0.unkC94[gUnk_03002C30[47].unk26] == 0xFF) {
            gUnk_030057E0.unkC93++;
            break;
        }
        setup_battle_sprite_terrain(47, gUnk_030057E0.unkC94[gUnk_03002C30[47].unk26], gUnk_03002C30[47].unk2A);
        switch (gUnk_030057E0.unkC94[gUnk_03002C30[47].unk26] >> 4) {
        case 0:
            KEYS_LO(gHeldKeys) |= 0x40;
            break;
        case 1:
            KEYS_LO(gHeldKeys) |= 0x80;
            break;
        case 2:
            KEYS_LO(gHeldKeys) |= 0x20;
            break;
        case 3:
            KEYS_LO(gHeldKeys) |= 0x10;
            break;
        }
        break;
    case 1:
        memcpy_u8(gUnk_030057E0.unkC20, gUnk_030057E0.unkC10, 8);
        gUnk_030057E0.unkC5F = 0;
        map_script_command_done();
        break;
    }
}

void sub_0804E324(void) {
    u8 obj;
    u32 i;

    gUnk_030057E0.unkC69 = gUnk_030057E0.unkC5C = gUnk_083D2998[gUnk_030057E0.unkC94[0]];
    gUnk_030057E0.unkC28 = gUnk_083D2998[gUnk_030057E0.unkC94[0]];
    load_battle_terrain_data();
    decompress_battle_tile_graphics();
    switch (gUnk_03006F40.unk1) {
    case 1:
    case 3:
    case 5:
    case 6:
        obj = 1;
        break;
    default:
        obj = 0;
        break;
    }
    i = resolve_tile_from_battle_state(0);
    if (gUnk_083F8634[i] == NULL)
        i = 1;
    if (obj)
        DmaCopy32(3, gUnk_083F8634[i], OBJ_PLTT, 32) else DmaCopy32(3, gUnk_083F8634[i], 0x0202F800, 32)
            map_script_command_done();
}

void sub_0804E3F0(void) {
    if (sub_08050868())
        map_script_command_done();
}

void sub_0804E404(void) {
    if (sub_080508CC())
        map_script_command_done();
}

void sub_0804E418(void) {
    if (sub_080507E0(gUnk_03006D20.unkA))
        map_script_command_done();
}

void sub_0804E434(void) {
    sub_0804E44C();
}

void sub_0804E440(void) {
    sub_0804E44C();
}

void sub_0804E44C(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        spawn_script_sprite(s->unkC94[0], s->unkC94[1], s->unkC94[2], s->unkC94[3]);
        setup_battle_sprite_terrain(gUnk_03006D20.unkA, s->unkC94[4], 0);
        s->unkC93++;
        break;
    case 1:
        if (update_battle_sprite_movement(gUnk_03006D20.unkA, 1))
            map_script_command_done();
        break;
    }
}

void sub_0804E4D0(void) {
    sub_0804E4E8();
}

void sub_0804E4DC(void) {
    sub_0804E4E8();
}

void sub_0804E4E8(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        setup_battle_sprite_terrain(gUnk_03006D20.unkA, s->unkC94[1], 0);
        s->unkC93++;
        break;
    case 1:
        if (update_battle_sprite_movement(gUnk_03006D20.unkA, 1))
            map_script_command_done();
        break;
    }
}

void sub_0804E540(void) {
    if (sub_080507E0(gUnk_03006D20.unkA))
        map_script_command_done();
}

void sub_0804E55C(void) {
    if (sub_08050868())
        map_script_command_done();
}

void sub_0804E570(void) {
    if (sub_080508CC())
        map_script_command_done();
}

void sub_0804E584(void) {
    sub_0804E5A4(0, 1);
}

void sub_0804E594(void) {
    sub_0804E5A4(1, 1);
}

void sub_0804E5A4(u8 b, u8 mode) {
    s32 empty = 0;
    s32 done = 0;
    s32 i;
    s32 slot;

    switch (gUnk_030057E0.unkC93) {
    case 0:
        for (i = 0; i <= 3; i++) {
            if (sub_0804DBA4(i) != -1 && gUnk_030055A0[sub_0804DBA4(i) + 79].unk0 != 0) {
                if (mode == 1)
                    setup_battle_sprite_terrain(sub_0804DBA4(i) + 79, gUnk_030057E0.unkC94[0], b);
                else
                    sub_080500D8(sub_0804DBA4(i) + 79, gUnk_030057E0.unkC94[0], b);
            }
        }
        gUnk_030057E0.unkC93++;
        break;
    case 1:
        for (i = 0; i <= 3; i++) {
            slot = sub_0804DBA4(i);
            if (slot != -1) {
                if (gUnk_030055A0[slot + 79].unk0 != 0)
                    done += update_battle_sprite_movement(slot + 79, mode);
                else
                    done++;
            } else
                empty++;
        }
        if (empty == 4)
            map_script_command_done();
        if (done)
            map_script_command_done();
        break;
    }
}

void sub_0804E6B4(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        spawn_script_sprite(s->unkC94[0], s->unkC94[1], s->unkC94[2], s->unkC94[3]);
        setup_battle_sprite_terrain(gUnk_03006D20.unkA, s->unkC94[4], 0);
        s->unkC93++;
        break;
    case 1:
        if (update_battle_sprite_movement(gUnk_03006D20.unkA, 0))
            map_script_command_done();
        break;
    }
}

void sub_0804E738(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        setup_battle_sprite_terrain(gUnk_03006D20.unkA, s->unkC94[1], 0);
        s->unkC93++;
        break;
    case 1:
        if (update_battle_sprite_movement(gUnk_03006D20.unkA, 0))
            map_script_command_done();
        break;
    }
}

void nullsub_0804E790(void) {}

void nullsub_0804E794(void) {}

void nullsub_0804E798(void) {}

void sub_0804E79C(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;
    u32 r;

    switch (s->unkC93) {
    case 0:
        init_bg0_for_cursor(0);
        s->unkC93++;
        break;
    case 1:
        r = sub_08047FEC();
        if (r) {
            if (r & 0xF0)
                s->unkC8A = s->unkC8C + s->unkC94[0];
            s->unkC93++;
        }
        break;
    case 2:
        if (game_state_execute_handler_a())
            map_script_command_done();
        break;
    }
}

void sub_0804E814(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;
    u32 r;

    switch (s->unkC93) {
    case 0:
        init_bg0_for_cursor(1);
        s->unkC93++;
        break;
    case 1:
        r = sub_08047FEC();
        if (r) {
            if (r & 0xF0)
                s->unkC8A = s->unkC8C + s->unkC94[0];
            map_script_command_done();
        }
        break;
    }
}

void sub_0804E878(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        sub_08050C74();
        s->unkC93++;
        break;
    case 1:
        if (scene_state_dispatch(0x20, 0)) {
            u32 v = s->unkC4F;
            if (v == 1)
                gUnk_03005310.unk39 = v;
            else if (v == 2)
                gUnk_03005310.unk39 = v;
            map_script_command_done();
        }
        break;
    }
}

void nullsub_0804E8D4(void) {}

void nullsub_0804E8D8(void) {}

// guess: opcode 0x36, give arg1 of item arg0 (capped at 99) and show the text.
void sub_0804E8DC(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;
    s32 have;
    s32 n;

    switch (s->unkC93) {
    case 0:
        init_cursor_state();
        have = sub_08047D8C(s->unkC94[0]);
        if (have == 99) {
            sub_08047BA8(6);
            copy_string_to_text_buffer(0, sub_08048088(s->unkC94[0]));
            s->unkC93 = 1;
            break;
        }
        sub_08047BA8(14);
        if (s->unkC94[1] + have > 99)
            n = 99 - have;
        else
            n = s->unkC94[1];
        sub_08047DC0(gUnk_030057E0.unkC94[0], n);
        copy_string_to_text_buffer(0, sub_08048088(gUnk_030057E0.unkC94[0]));
        format_number_to_text_buffer(1, n);
        gUnk_030057E0.unkC93 = 2;
        break;
    case 1:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[0]))
            map_script_command_done();
        break;
    case 2:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[1]))
            map_script_command_done();
        break;
    }
}

// guess: opcode 0x37, take arg1 of item arg0 and show the text.
void sub_0804E9CC(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;
    s32 have;
    s32 n;

    switch (s->unkC93) {
    case 0:
        init_cursor_state();
        have = sub_08047D8C(s->unkC94[0]);
        if (have == 0) {
            sub_08047BA8(6);
            copy_string_to_text_buffer(0, sub_08048088(s->unkC94[0]));
            s->unkC93 = 1;
            break;
        }
        sub_08047BA8(5);
        if (have - s->unkC94[1] < 0)
            n = have;
        else
            n = s->unkC94[1];
        sub_08047DD8(s->unkC94[0], n);
        copy_string_to_text_buffer(0, sub_08048088(s->unkC94[0]));
        format_number_to_text_buffer(1, n);
        have = sub_08047D8C(s->unkC94[0]);
        if (have == 0)
            s->unkC93 = 3;
        else
            s->unkC93 = 2;
        break;
    case 1:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[2]))
            map_script_command_done();
        break;
    case 2:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[3]))
            map_script_command_done();
        break;
    case 3:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[4]))
            map_script_command_done();
        break;
    }
}

// Opcode 0x38: give arg2 of Medapart (arg0, arg1), capped at 99 (medapart_add_quantity), then show the text.
void map_script_update_give_medapart(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;
    s32 have;
    s32 n;

    switch (s->unkC93) {
    case 0:
        init_cursor_state();
        have = (s32)(sub_08047D9C(s->unkC94[0], s->unkC94[1]) & 0xFF00) >> 8;
        if (have == 99) {
            sub_08047BA8(6);
            copy_string_to_text_buffer(0, sub_08047BEC(s->unkC94[1], s->unkC94[0]));
            s->unkC93 = 1;
            break;
        }
        sub_08047BA8(14);
        if (s->unkC94[2] + have > 99)
            n = 99 - have;
        else
            n = s->unkC94[2];
        sub_08047DF0(gUnk_030057E0.unkC94[0], gUnk_030057E0.unkC94[1], n);
        copy_string_to_text_buffer(0, sub_08047BEC(gUnk_030057E0.unkC94[1], gUnk_030057E0.unkC94[0]));
        format_number_to_text_buffer(1, n);
        gUnk_030057E0.unkC93 = 2;
        break;
    case 1:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[5]))
            map_script_command_done();
        break;
    case 2:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[s->unkC94[1] + 6]))
            map_script_command_done();
        break;
    }
}

// guess: opcode 0x39, take arg2 of Medapart (arg0, arg1) and show the text.
void sub_0804EBEC(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;
    s32 have;
    s32 n;

    switch (s->unkC93) {
    case 0:
        init_cursor_state();
        have = (s32)(sub_08047D9C(s->unkC94[0], s->unkC94[1]) & 0xFF00) >> 8;
        if (have == 0) {
            sub_08047BA8(6);
            copy_string_to_text_buffer(0, sub_08047BEC(s->unkC94[1], s->unkC94[0]));
            s->unkC93 = 1;
            break;
        }
        sub_08047BA8(5);
        if (have - s->unkC94[2] < 0)
            n = have;
        else
            n = s->unkC94[2];
        sub_08047E08(s->unkC94[0], s->unkC94[1], n);
        copy_string_to_text_buffer(0, sub_08047BEC(s->unkC94[1], s->unkC94[0]));
        format_number_to_text_buffer(1, n);
        have = sub_08047D9C(s->unkC94[0], s->unkC94[1]) & 0xFF00;
        if (have == 0)
            s->unkC93 = 3;
        else
            s->unkC93 = 2;
        break;
    case 1:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[s->unkC94[1] + 14]))
            map_script_command_done();
        break;
    case 2:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[s->unkC94[1] + 18]))
            map_script_command_done();
        break;
    case 3:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[s->unkC94[1] + 18]))
            map_script_command_done();
        break;
    }
}

// Opcode 0x3A: add the 16-bit argument * 10 to gMoney and show the "got money" text (runtime: +5000 in the intro).
void map_script_update_give_money(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;
    u32 n;

    switch (s->unkC93) {
    case 0:
        init_cursor_state();
        n = ((s->unkC94[0] << 8) | s->unkC94[1]) * 10;
        sub_08047BA8(7);
        add_money(n);
        sub_08047D24(0, n);
        s->unkC93 = 1;
        break;
    case 1:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[26]))
            map_script_command_done();
        break;
    }
}

// Opcode 0x3B: subtract the 16-bit argument * 10 from gMoney, at most what is left (runtime: -4980 buying Rokusho).
void map_script_update_take_money(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;
    s32 n;
    s32 money;

    switch (s->unkC93) {
    case 0:
        init_cursor_state();
        n = ((s->unkC94[0] << 8) | s->unkC94[1]) * 10;
        sub_08047BA8(5);
        money = get_money();
        if (money - n <= 0)
            n = money;
        sub_08047BA8(5);
        sub_money(n);
        sub_08047D24(0, n);
        s->unkC93 = 1;
        break;
    case 1:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[27]))
            map_script_command_done();
        break;
    }
}

// Opcode 0x3C: give medal arg0 unless already owned (find_medal_slot_by_id), then run scene 1.
void map_script_update_give_medal(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        init_cursor_state();
        sub_08047BA8(14);
        copy_string_to_text_buffer(0, sub_08047BCC(s->unkC94[0]));
        if (sub_08047DB0(s->unkC94[0])) {
            s->unkC93 = 1;
            break;
        }
        gUnk_030017EC = sub_08047E20(s->unkC94[0]);
        s->unkC93 = 2;
        break;
    case 1:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[28]))
            map_script_command_done();
        break;
    case 2:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[29])) {
            sub_08050C74();
            s->unkC93++;
        }
        break;
    case 3:
        if (scene_state_dispatch(1, s->unkC94[0]))
            map_script_command_done();
        break;
    }
}

// guess: opcode 0x3D, add position entry arg0 unless all slots are occupied (runs in walkthrough 01).
void sub_0804EF10(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        init_cursor_state();
        sub_08047BA8(14);
        if (sub_08047E30()) {
            s->unkC93 = 1;
            break;
        }
        sub_08047E3C(s->unkC94[0]);
        s->unkC93 = 2;
        break;
    case 1:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[30]))
            map_script_command_done();
        break;
    case 2:
        if (scene_transition_step_08047C24(0, 0, 0, gUnk_0847E8C4[s->unkC94[0] + 31]))
            map_script_command_done();
        break;
    }
}

// guess: opcode 0x40, flash the screen white arg0 times.
void sub_0804EFB0(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, 8.0f);
        s->unkC93++;
        break;
    case 1:
        if (run_blend_fade_transition(0x7FFF)) {
            setup_palette_fade_to_color(0x7FFF, 32.0f, 0.0f, 8.0f);
            s->unkC93++;
        }
        break;
    case 2:
        if (run_blend_fade_transition(0x7FFF)) {
            if (--s->unkC94[0] != 0)
                s->unkC93 = 0;
            else
                map_script_command_done();
        }
        break;
    }
}

void sub_0804F058(void) {
    s32 empty = 0;
    s32 done = 0;
    s32 i;

    for (i = 0; i <= 3; i++) {
        if (sub_0804DBA4(i) != -1) {
            if (gUnk_030055A0[sub_0804DBA4(i) + 79].unk0 != 0)
                done += sub_080507E0(sub_0804DBA4(i) + 79);
            else
                empty++;
        }
    }
    if (empty == 4)
        done = 1;
    if (done)
        map_script_command_done();
}

void sub_0804F0C4(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        s->unkC8A = 16 / sub_080518F4(47);
        sub_080500D8(47, (s->unkC94[0] << 4) | s->unkC94[1], 0);
        s->unkC93++;
        break;
    case 1:
        if (sub_0804F13C(s->unkC94[0]))
            map_script_command_done();
        break;
    }
}

// guess: scripted player step in dir (field_player_step without the input checks); returns 1 when the step ends.
u32 sub_0804F13C(u8 dir) {
    u32 ret;

    switch (dir) {
    case 0:
        if (gUnk_030057E0.unkC54 - gUnk_030057E0.unkC4A != 0) {
            gUnk_030057E0.unkC54 -= sub_080518F4(47);
            if (!sub_08052A18() && gUnk_030057E0.unkC54 - gUnk_030057E0.unkC4A < gUnk_030057E0.unk802 * 8 - 0x60 &&
                gBg1Scroll.y != 0) {
                sub_08052AF8(-sub_080518F4(47));
                gUnk_03002C30[0].unk4 += sub_080518F4(47);
            }
        }
        break;
    case 1:
        if (gUnk_030057E0.unkC54 - gUnk_030057E0.unkC4A + 16 < gUnk_030057E0.unk802 * 8) {
            gUnk_030057E0.unkC54 += sub_080518F4(47);
            if (!sub_08052A18() && gUnk_030057E0.unkC54 - gUnk_030057E0.unkC4A + 16 > 0x50 &&
                gBg1Scroll.y + 0xA0 < gUnk_030057E0.unk802 * 8) {
                sub_08052AF8(sub_080518F4(47));
                gUnk_03002C30[0].unk4 -= sub_080518F4(47);
            }
        }
        break;
    case 2:
        if (gUnk_030057E0.unkC52 - gUnk_030057E0.unkC48 != 0) {
            gUnk_030057E0.unkC52 -= sub_080518F4(47);
            if (!sub_08052A04() && gUnk_030057E0.unkC52 - gUnk_030057E0.unkC48 < gUnk_030057E0.unk800 * 8 - 0x80 &&
                gBg1Scroll.x != 0) {
                sub_08052A2C(-sub_080518F4(47));
                gUnk_03002C30[0].unk2 += sub_080518F4(47);
            }
        }
        break;
    case 3:
        if (gUnk_030057E0.unkC52 - gUnk_030057E0.unkC48 + 16 < gUnk_030057E0.unk800 * 8) {
            gUnk_030057E0.unkC52 += sub_080518F4(47);
            if (!sub_08052A04() && gUnk_030057E0.unkC52 - gUnk_030057E0.unkC48 + 16 > 0x80 &&
                gBg1Scroll.x + 0xF0 < gUnk_030057E0.unk800 * 8) {
                sub_08052A2C(sub_080518F4(47));
                gUnk_03002C30[0].unk2 -= sub_080518F4(47);
            }
        }
        break;
    }
    gUnk_03006D20.unk0--;
    ret = 0;
    if (gUnk_03006D20.unk0 == 0) {
        gUnk_030057E0.unkC56 = sub_080526F0(gUnk_030057E0.unkC52);
        gUnk_030057E0.unkC57 = sub_08052714(gUnk_030057E0.unkC54);
        ret = 1;
    }
    return ret;
}

void sub_0804F3AC(void) {
    s32 idx;
    u8 phase;
    u16 off;
    u8 div;
    u8 n;

    switch (gUnk_030057E0.unkC93) {
    case 0:
        if (gUnk_030057E0.unkC94[0] == 0)
            gUnk_03005310.unk1E = gBg1Scroll.x;
        else
            gUnk_03005310.unk26 = gBg1Scroll.y;
        gUnk_030057E0.unkC94[2] = 0;
        gUnk_030057E0.unkC94[4] = gUnk_030057E0.unkC94[1];
        gUnk_030057E0.unkC93++;
        break;
    case 1:
        if (gUnk_030057E0.unkC94[1] != 0) {
            gUnk_030057E0.unkC94[1]--;
            div = gUnk_030057E0.unkC94[4];
            n = gUnk_030057E0.unkC94[2];
            idx = 256 / div * n / 2;
            if (gUnk_030057E0.unkC94[0] == 0) {
                off = gUnk_083D69A0[0][idx] / (128 - ((phase = n & 3) + 1) * 16);
                if (phase <= 1)
                    sub_080529C4(gUnk_03005310.unk1E - off);
                else
                    sub_080529C4(off + gUnk_03005310.unk1E);
            } else {
                off = gUnk_083D69A0[0][idx] / (128 - ((phase = n & 3) + 1) * 16);
                if (phase <= 1)
                    sub_080529E4(gUnk_03005310.unk26 - off);
                else
                    sub_080529E4(off + gUnk_03005310.unk26);
            }
            update_bg_scroll_offsets_a();
            if (gUnk_030057E0.unkC76)
                update_bg_scroll_offsets_b();
            gUnk_030057E0.unkC94[2]++;
        } else {
            if (gUnk_030057E0.unkC94[0] == 0)
                sub_080529C4(gUnk_03005310.unk1E);
            else
                sub_080529E4(gUnk_03005310.unk26);
            update_bg_scroll_offsets_a();
            if (gUnk_030057E0.unkC76)
                update_bg_scroll_offsets_b();
            map_script_command_done();
        }
        break;
    }
}

void nullsub_0804F57C(void) {}

void nullsub_0804F580(void) {}

void nullsub_0804F584(void) {}

void nullsub_0804F588(void) {}

void nullsub_0804F58C(void) {}

// guess: opcode 0x56, reload the map (clears tile buffers, recopies the collision map, reloads NPC sprites).
void sub_0804F590(void) {
    save_script_sprites();
    sub_080496C8(gUnk_03003870, 0x900);
    sub_080496C8(gUnk_03003870 + 0xA80, 0x900);
    sub_080496C8(gUnk_03005664, 0x90);
    sub_080496C8(gUnk_03005664 + 0xA8, 0x90);
    restore_script_sprites();
    sub_080496C8(gUnk_030057E0.unk810, 0x400);
    memcpy_u8(gUnk_084045A8[gUnk_030057E0.unk7FE], gUnk_030057E0.unk810,
              (gUnk_030057E0.unk802 >> 1) * (gUnk_030057E0.unk800 >> 1));
    gUnk_030057E0.unkCBA = 1;
    load_map_npc_sprites();
    update_entity_sprites_on_screen();
    map_script_command_done();
}

void nullsub_0804F628(void) {}

void nullsub_0804F62C(void) {}

void sub_0804F630(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        sub_08050C74();
        s->unkC93++;
        break;
    case 1:
        if (scene_state_dispatch(3, s->unkC94[0]))
            map_script_command_done();
        break;
    }
}

void nullsub_0804F678(void) {}

void nullsub_0804F67C(void) {}

void nullsub_0804F680(void) {}

void nullsub_0804F684(void) {}

void nullsub_0804F688(void) {}

void nullsub_0804F68C(void) {}

void nullsub_0804F690(void) {}

void sub_0804F694(void) {
    u32 kind;

    switch (gUnk_030057E0.unkC93) {
    case 0:
        kind = gUnk_03005350.unk1D4 & 0x3F;
        if (kind == 0xD || kind == 0x16) {
            if (battle_scene_state_dispatch())
                gUnk_030057E0.unkC93++;
        } else if (battle_scene_state_dispatch())
            map_script_command_done();
        break;
    case 1:
        gUnk_03006D20.unk0 = 16 / sub_080518F4(47);
        sub_080500D8(47, (gUnk_030057E0.unkC94[0] << 4) | gUnk_030057E0.unkC94[1], 0);
        gUnk_030057E0.unkC93++;
        break;
    case 2:
        if ((gUnk_03005350.unk1D4 & 0x3F) == 0xD)
            gUnk_030057E0.unkC67 = 2;
        else
            gUnk_030057E0.unkC67 = 3;
        if (sub_0804F13C(gUnk_030057E0.unkC67)) {
            gUnk_030057E0.unkC5B = 1;
            gUnk_03002C30[47].unk2A = gUnk_083D2908[gUnk_030057E0.unkC5C];
            gUnk_030057E0.unkC56 = sub_080526F0(gUnk_030057E0.unkC52);
            gUnk_030057E0.unkC57 = sub_08052714(gUnk_030057E0.unkC54);
            field_center_camera_on_player();
            sub_08052BA0(gUnk_030057E0.unkC5B);
            field_set_player_facing(gUnk_030057E0.unkC67);
            update_bg_scroll_offsets_a();
            init_battle_sprites();
            map_script_command_done();
        }
        break;
    }
}

void sub_0804F7F0(void) {
    if (sub_080509A0())
        map_script_command_done();
}

void sub_0804F804(void) {
    map_script_command_done();
}

void nullsub_0804F810(void) {}

void nullsub_0804F814(void) {}

void sub_0804F818(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        spawn_script_sprite(s->unkC94[0], s->unkC94[1], s->unkC94[2], s->unkC94[3]);
        setup_battle_sprite_terrain(gUnk_03006D20.unkA, s->unkC94[4], 1);
        s->unkC93++;
        break;
    case 1:
        if (update_battle_sprite_movement(gUnk_03006D20.unkA, 1))
            map_script_command_done();
        break;
    }
}

void sub_0804F89C(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        setup_battle_sprite_terrain(gUnk_03006D20.unkA, s->unkC94[1], 1);
        s->unkC93++;
        break;
    case 1:
        if (update_battle_sprite_movement(gUnk_03006D20.unkA, 1))
            map_script_command_done();
        break;
    }
}

void sub_0804F8F4(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        spawn_script_sprite(s->unkC94[0], s->unkC94[1], s->unkC94[2], s->unkC94[3]);
        setup_battle_sprite_terrain(gUnk_03006D20.unkA, s->unkC94[4], 1);
        s->unkC93++;
        break;
    case 1:
        if (update_battle_sprite_movement(gUnk_03006D20.unkA, 0))
            map_script_command_done();
        break;
    }
}

void sub_0804F978(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        setup_battle_sprite_terrain(gUnk_03006D20.unkA, s->unkC94[1], 1);
        s->unkC93++;
        break;
    case 1:
        if (update_battle_sprite_movement(gUnk_03006D20.unkA, 0))
            map_script_command_done();
        break;
    }
}

void sub_0804F9D0(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        sub_08050C74();
        s->unkC93++;
        break;
    case 1:
        if (scene_state_dispatch(0x13, 0))
            map_script_command_done();
        break;
    }
}

void sub_0804FA10(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        sub_08050C74();
        s->unkC93++;
        break;
    case 1:
        if (scene_state_dispatch(0, 0))
            map_script_command_done();
        break;
    }
}

void sub_0804FA50(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        sub_08050C74();
        s->unkC93++;
        break;
    case 1:
        if (scene_state_dispatch(2, 0))
            map_script_command_done();
        break;
    }
}

// guess: opcode 0x73, run scene 8 until it ends (coverage: runs in the shop scenario).
void sub_0804FA90(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        sub_08050C74();
        s->unkC93++;
        break;
    case 1:
        if (scene_state_dispatch(8, 0))
            map_script_command_done();
        break;
    }
}

void sub_0804FAD0(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        switch_game_mode(4, 0);
        s->unkC93++;
        break;
    case 1:
        if (gUnk_03006D20.unkC == 7)
            s->unkC93 = 2;
        else
            map_script_command_done();
        break;
    case 2:
        sub_08050C74();
        s->unkC93++;
        break;
    case 3:
        if (scene_state_dispatch(5, 0))
            map_script_command_done();
        break;
    }
}

void sub_0804FB40(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        sub_08050C74();
        s->unkC93++;
        break;
    case 1:
        if (scene_state_dispatch(0x10, 0)) {
            if (sub_0804B6EC())
                gUnk_03005310.unk39 = 1;
            map_script_command_done();
        }
        break;
    }
}

void sub_0804FB90(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        sub_08050C74();
        s->unkC93++;
        break;
    case 1:
        if (scene_state_dispatch(0x12, 0))
            map_script_command_done();
        break;
    }
}

void sub_0804FBD0(void) {
    struct Unk_030057E0 *s = &gUnk_030057E0;

    switch (s->unkC93) {
    case 0:
        sub_08050C74();
        s->unkC93++;
        break;
    case 1:
        if (scene_state_dispatch(0x11, 0)) {
            if (sub_0804B6EC())
                gUnk_03005310.unk39 = 1;
            map_script_command_done();
        }
        break;
    }
}

void sub_0804FC20(void) {
    sub_0804E5A4(0, 0);
}

// guess: opcode 0x7F, end the follower: copy sprite 48 and its shadow back to map object arg0.
void sub_0804FC30(void) {
    gUnk_03002C30[48].unkC_8 = gUnk_030057E0.unkC6E;
    gUnk_03002C30[48].unk10_8 = gUnk_030057E0.unkC70;
    memcpy_u8(&gUnk_03002C30[48], &gUnk_03002C30[gUnk_030057E0.unkC94[0] + 79], 0x40);
    gUnk_030055A0[gUnk_030057E0.unkC94[0] + 79].unk0 = 0xFFFF;
    memcpy_u8(&gUnk_03002C30[90], &gUnk_03002C30[gUnk_030057E0.unkC94[0] + 121], 0x40);
    map_script_command_done();
}

void sub_0804FCC4(void) {
    s32 done = 0;
    s32 i;
    u8 b;

    for (i = 0; i < gUnk_030064A0.unk52; i++) {
        if (gUnk_030064A0.unkA[i] > 1)
            done++;
        else {
            switch (gUnk_030064A0.unk12[i][gUnk_030064A0.unkA[i] * 4]) {
            case 1:
                set_battle_sprite_animation(gUnk_030064A0.unk12[i][gUnk_030064A0.unkA[i] * 4 + 1],
                                            gUnk_030064A0.unk12[i][gUnk_030064A0.unkA[i] * 4 + 2]);
                gUnk_030064A0.unkA[i]++;
                break;
            case 2:
                gUnk_030064A0.unk54[i] = gUnk_030064A0.unk12[i][gUnk_030064A0.unkA[i] * 4 + 1];
                sub_08050508(gUnk_030064A0.unk54[i]);
                gUnk_030064A0.unkA[i]++;
                break;
            case 3:
            case 4:
                switch (gUnk_030064A0.unk12[i][gUnk_030064A0.unkA[i] * 4]) {
                case 3:
                default:
                    b = 0;
                    break;
                case 4:
                    b = 1;
                    break;
                }
                switch (gUnk_030064A0.unk5C[i]) {
                case 0:
                    gUnk_030064A0.unk54[i] = sub_0804DBA4(gUnk_030064A0.unk12[i][gUnk_030064A0.unkA[i] * 4 + 1]) + 79;
                    setup_battle_sprite_terrain(gUnk_030064A0.unk54[i],
                                                gUnk_030064A0.unk12[i][gUnk_030064A0.unkA[i] * 4 + 2], b);
                    gUnk_030064A0.unk5C[i]++;
                    break;
                case 1:
                    if (update_battle_sprite_movement(gUnk_030064A0.unk54[i], 1))
                        gUnk_030064A0.unk5C[i]++;
                    break;
                case 2:
                    gUnk_030064A0.unk5C[i] = 0;
                    gUnk_030064A0.unkA[i]++;
                    break;
                }
                break;
            case 0xFF:
                done++;
                break;
            default:
                done++;
                break;
            }
            if (gUnk_030064A0.unkA[i] > 1)
                done++;
        }
    }
    if (done == gUnk_030064A0.unk52) {
        gUnk_030064A0.unk52 = 0;
        sub_080496C8(gUnk_030064A0.unk12[0], 64);
        map_script_command_done();
    }
}

void sub_0804FE20(void) {
    if (gUnk_030057E0.unkC36 == 0) {
        gUnk_030057E0.unkC34 = gUnk_030057E0.unkC94[0];
        map_script_command_done();
    }
}

void sub_0804FE50(void) {
    s32 done = 0;
    s32 i;
    struct MapObject *obj;
    u32 id;

    for (i = 0; i < gUnk_030064A0.unk52; i++) {
        switch (gUnk_030064A0.unk12[i][0]) {
        case 0:
            done = 1;
            break;
        case 1:
            if (++gUnk_030064A0.unk2[i] > 5) {
                id = (gUnk_030064A0.unk12[i][1] << 8) | gUnk_030064A0.unk12[i][2];
                obj = battle_find_entity_by_id(id);
                if (obj != NULL && obj->unk4_6) {
                    set_sprite_anim_and_store(obj->unk4_0 + 49, gUnk_030064A0.unkA[i], obj);
                    if (gUnk_030064A0.unkA[i] == 0 && gUnk_030064A0.unk12[i][3] == 1 &&
                        find_map_event_by_coords(obj->x, obj->y) && gUnk_03006D38.unk3)
                        sub_08047BA8(gUnk_083D29E6[gUnk_03006D38.unk3]);
                }
                gUnk_030064A0.unkA[i]++;
                gUnk_030064A0.unk2[i] = 0;
                if (gUnk_030064A0.unkA[i] > 3) {
                    gUnk_03002C30[obj->unk4_0 + 49].unk24 = 0xFF;
                    done = 1;
                }
            }
            break;
        case 2:
            if (++gUnk_030064A0.unk2[i] > 5) {
                id = (gUnk_030064A0.unk12[i][1] << 8) | gUnk_030064A0.unk12[i][2];
                obj = battle_find_entity_by_id(id);
                if (obj != NULL && obj->unk4_6)
                    set_sprite_anim_and_store(obj->unk4_0 + 49, 3 - gUnk_030064A0.unkA[i], obj);
                gUnk_030064A0.unkA[i]++;
                gUnk_030064A0.unk2[i] = 0;
                if (gUnk_030064A0.unkA[i] > 3) {
                    gUnk_03002C30[obj->unk4_0 + 49].unk24 = 0xFF;
                    gUnk_03002C30[obj->unk4_0 + 49].unk20 = 0;
                    sub_080493D4(obj->unk4_0 + 49,
                                 sub_080502B4(obj->unk4_0 + 49, gUnk_03002C30[obj->unk4_0 + 49].unk20));
                    done = 1;
                }
            }
            break;
        default:
            done = 1;
            break;
        }
    }
    if (done) {
        gUnk_030064A0.unk52 = 0;
        sub_080496C8(gUnk_030064A0.unk12[0], 64);
        map_script_command_done();
    }
}

void setup_battle_sprite_terrain(u8 slot, u8 a, u8 b) {
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *spr = &base[slot];

    spr->unk27 = a & 0xF;
    a = (a & 0xF0) >> 4;
    set_sprite_animation_state(slot, a);
    spr->unk2A = b;
    spr->unk28 = 16 / sub_080518F4(slot);
    sub_080493D4(slot, sub_080502B4(slot, a));
}

void sub_080500D8(u8 slot, u8 a, u8 b) {
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *spr = &base[slot];

    spr->unk27 = a & 0xF;
    spr->unk20 = (a & 0xF0) >> 4;
    spr->unk2A = b;
    spr->unk28 = 16 / sub_080518F4(slot);
}

void advance_sprite_by_terrain_modifier(u8 slot) {
    s32 i;

    for (i = 0; i < sub_080518F4(slot); i++)
        advance_sprite_animation_frame(slot);
}

u32 update_battle_sprite_movement(u8 slot, u8 mode) {
    u32 done = 0;
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *spr = &base[slot];

    if (spr->unk28 != 0) {
        switch (spr->unk20) {
        case 0:
            spr->unk10_8 -= sub_080518F4(slot);
            break;
        case 1:
            spr->unk10_8 += sub_080518F4(slot);
            break;
        case 2:
            spr->unkC_8 -= sub_080518F4(slot);
            break;
        case 3:
            spr->unkC_8 += sub_080518F4(slot);
            break;
        }
        if (mode)
            advance_sprite_by_terrain_modifier(slot);
        if (--gUnk_03002C30[slot].unk28 == 0) {
            switch (gUnk_03002C30[slot].unk30) {
            case 0x71:
            case 0x78:
            case 0x82:
            case 0x83:
            case 0x84:
                sub_08047BA8(0x57);
                break;
            }
            gUnk_03002C30[slot].unk28 = 16 / sub_080518F4(slot);
            if (--gUnk_03002C30[slot].unk27 == 0)
                done = 1;
        }
    }
    return done;
}

// Ends the current command: the next frame runs the next one (map_script_run_command).
void map_script_command_done(void) {
    gUnk_030057E0.unkC93 = 0;
    gUnk_030057E0.unkC89 = 0;
}

u8 sub_08050264(u8 a) {
    return a >> 4;
}

u8 sub_0805026C(u8 a) {
    return a & 3;
}

u8 calc_medapart_table_index(u8 a) {
    return sub_08050264(a) * 12 + sub_0805026C(a) * 3;
}

u8 sub_080502B4(u8 slot, u8 v) {
    return v + gUnk_03002C30[slot].unk2B * 4;
}

u8 compute_battle_sprite_anim_offset(u8 id, u8 a) {
    return gUnk_03002C30[sub_0804DBA4(id) + 79].unk2B * 12 + a * 3;
}

// Map script opcodes: sprite slot flags & 0xF (+0x4F), graphics id, tile x / y; bit 0x40 = 5 px lower.
void spawn_script_sprite(u8 flags, u8 part, u8 x, u8 y) {
    u32 idx = flags & 0xF;

    if ((flags & 0xF0) && find_map_event_by_coords(x, y) && gUnk_03006D38.unk3)
        sub_08047BA8(gUnk_083D29E6[gUnk_03006D38.unk3]);
    sub_0804DB84(idx, find_next_available_battle_sprite_slot());
    init_script_sprite(sub_0804DBA4(idx), part, x, y);
    if (flags & 0x40)
        gUnk_03002C30[sub_0804DBA4(idx) + 0x4F].unk10_8 += 5;
}

// Sets up script sprite idx + 0x4F at tile (x, y), plus an overlay sprite at idx + 0x79 on some tiles.
void init_script_sprite(u8 idx, u8 part, u8 x, u8 y) {
    u32 slot = idx + 0x4F;
    struct Unk_03002C30 *spr;
    u32 tile;
    u8 anim;

    clear_battle_sprite_entry(slot);
    init_battle_sprite_entry_08048818(slot, 0xC804, calc_medapart_table_index(part), sub_08050264(part), 1);
    anim = sub_08050264(part);
    spr = &gUnk_03002C30[slot];
    spr->unk2B = anim;
    spr->unk20 = sub_0805026C(part);
    spr->unkC_8 = x * 16 + gUnk_030057E0.unkC48;
    spr->unk10_8 = y * 16 + gUnk_030057E0.unkC4A;
    gUnk_030055A0[slot].unk0 = 0xFFFF;
    spr->unk2C = 0;
    tile = resolve_tile_from_battle_state(spr->unk2B);
    spr->unk30 = tile;
    sub_0804877C(slot);
    if (gUnk_083D2B8D[tile]) {
        init_battle_sprite_entry_08048818(idx + 0x79, 0xCC0C, 0x90, 0xE, 1);
        gUnk_03002C30[idx + 0x79].unkC_8 = spr->unkC_8;
        gUnk_03002C30[idx + 0x79].unk10_8 = spr->unk10_8 - 5;
    }
}

// guess: remove the sprite of map object (arg & 0xF); if arg & 0xF0, play the exit sound when it stands on an exit.
void sub_08050508(u8 arg) {
    u32 id = arg & 0xF;

    if (arg & 0xF0) {
        u8 x = sub_080526F0(gUnk_03002C30[sub_0804DBA4(id) + 79].unkC_8);
        u8 y = sub_08052714(gUnk_03002C30[sub_0804DBA4(id) + 79].unk10_8);

        if (find_map_event_by_coords(x, y) && gUnk_03006D38.unk3)
            sub_08047BA8(gUnk_083D29E6[gUnk_03006D38.unk3]);
    }
    clear_battle_sprite_entry(sub_0804DBA4(id) + 79);
    clear_battle_sprite_entry(sub_0804DBA4(id) + 121);
    sub_0804DB68(id);
}

// Snapshot of the 6 script sprites into gUnk_030057E0.unk7DC (runtime: opening the field menu).
void save_script_sprites(void) {
    s32 i;

    sub_080496C8((u8 *)gUnk_030057E0.unk7DC, sizeof(gUnk_030057E0.unk7DC));
    for (i = 0; i <= 5; i++) {
        if (gUnk_030055A0[i + 79].unk0) {
            gUnk_030057E0.unk7DC[i].x = sub_080526F0(gUnk_03002C30[i + 79].unkC_8);
            gUnk_030057E0.unk7DC[i].y = sub_08052714(gUnk_03002C30[i + 79].unk10_8);
            gUnk_030057E0.unk7DC[i].anim =
                ((gUnk_03002C30[i + 79].unk2B & 0xF) << 4) | (gUnk_03002C30[i + 79].unk20 & 3);
            gUnk_030057E0.unk7DC[i].id = i;
            gUnk_030057E0.unk7DC[i].unk2_6 = gUnk_03002C30[i + 79].unk2D;
            gUnk_030057E0.unk7DC[i].active = 1;
        }
    }
}

// Re-creates the script sprites from that snapshot (runtime: returning from the field menu).
void restore_script_sprites(void) {
    s32 i;

    for (i = 0; i <= 5; i++) {
        if (gUnk_030057E0.unk7DC[i].active && !gUnk_030057E0.unk7DC[i].unk2_6)
            init_script_sprite(i, gUnk_030057E0.unk7DC[i].anim, gUnk_030057E0.unk7DC[i].x, gUnk_030057E0.unk7DC[i].y);
    }
}

u32 find_next_available_battle_sprite_slot(void) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (!(gUnk_03002C30[i + 79].unk0 & 0x4000) && !gUnk_03002C30[i + 79].unk2E)
            break;
    }
    if (i == 6)
        return 5;
    return i;
}

void set_battle_sprite_animation(u8 id, u8 state) {
    gUnk_03002C30[sub_0804DBA4(id) + 79].unk20 = state;
    gUnk_03002C30[sub_0804DBA4(id) + 79].unk6 = compute_battle_sprite_anim_offset(id, state);
}

void sub_08050770(u32 idx, u8 val) {
    gUnk_03002C30[idx].unkB = val;
}

void sub_08050780(u8 i, u32 val) {
    gUnk_03002C30[sub_0804DBA4(i) + 79].unkB = val;
}

void sub_080507A0(u32 idx, u32 val) {
    u32 v = (gUnk_03002C30[idx].unk32 & 0xF3FF) | (val << 10);
    gUnk_03002C30[idx].unk0 = v;
    gUnk_03002C30[idx].unk32 = v;
}

void sub_080507C0(u8 i, u8 val) {
    sub_080507A0(sub_0804DBA4(i) + 79, val);
}

u32 sub_080507E0(u8 slot) {
    u32 ret = 0;

    if (gUnk_03006D20.unk0) {
        if (gUnk_03006D20.unk2)
            gUnk_03006D20.unk2--;
        else {
            gUnk_03006D20.unk1++;
            gUnk_03006D20.unk2 = gUnk_03006D20.unk3;
        }
        if (gUnk_03006D20.unk1 & 1) {
            gUnk_03002C30[slot].unk2D = 1;
            gUnk_03002C30[slot].unk0 = 0;
        } else {
            gUnk_03002C30[slot].unk2D = 0;
            gUnk_03002C30[slot].unk0 = gUnk_03002C30[slot].unk32;
        }
        gUnk_03006D20.unk0--;
    } else {
        gUnk_03002C30[slot].unk2D = 0;
        gUnk_03002C30[slot].unk0 = gUnk_03002C30[slot].unk32;
        ret = 1;
    }
    return ret;
}

u32 sub_08050868(void) {
    u32 ret = 0;

    switch (gUnk_03006D20.unk0) {
    case 0:
        sub_080493D4(gUnk_03006D20.unkA, sub_080502B4(gUnk_03006D20.unkA, gUnk_03002C30[gUnk_03006D20.unkA].unk20));
        gUnk_03006D20.unk0++;
        break;
    case 1:
        if (gUnk_03006D20.unk2) {
            advance_sprite_animation_frame(gUnk_03006D20.unkA);
            gUnk_03006D20.unk2--;
        } else
            ret = 1;
        break;
    }
    return ret;
}

u32 sub_080508CC(void) {
    u32 ret = 0;

    if (gUnk_03002C30[gUnk_03006D20.unkA].unk28 < 16) {
        gUnk_03002C30[gUnk_03006D20.unkA].unk10_8 =
            gUnk_03006D20.unk8 - gUnk_083D69A0[gUnk_03002C30[gUnk_03006D20.unkA].unk28][0] / 16;
        gUnk_03002C30[gUnk_03006D20.unkA].unk2C = gUnk_083D69A0[gUnk_03002C30[gUnk_03006D20.unkA].unk28][0] / 16;
        gUnk_03002C30[gUnk_03006D20.unkA].unk28++;
        if (gUnk_03002C30[gUnk_03006D20.unkA].unk10_8 / 4 <= (gUnk_03006D20.unk8 - 16) / 4)
            gUnk_03002C30[gUnk_03006D20.unkA].unkB = 0xFF;
        else
            sub_0804877C(gUnk_03006D20.unkA);
    } else {
        sub_0804877C(gUnk_03006D20.unkA);
        gUnk_03002C30[gUnk_03006D20.unkA].unk10_8 = gUnk_03006D20.unk8;
        gUnk_03002C30[gUnk_03006D20.unkA].unk2C = 0;
        ret = 1;
    }
    return ret;
}

u32 sub_080509A0(void) {
    u32 ret = 0;
    u8 slot = gUnk_03006D20.unkA;
    struct Unk_03002C30 *base = gUnk_03002C30;
    struct Unk_03002C30 *s = &base[slot];

    switch (s->unk26) {
    case 0:
        s->unk28 = 0;
        s->unk2A = 0;
        s->unk20 = gUnk_030057E0.unkC94[1];
        sub_080493D4(slot, sub_080502B4(slot, gUnk_030057E0.unkC94[1]));
        s->unk34 = s->unk10_8;
        sub_08047BA8(0x70);
        s->unk26++;
        break;
    case 1:
        if (s->unk28 < 16 / sub_080518F4(slot) * 2) {
            switch (s->unk20) {
            case 0:
                s->unk34 -= sub_080518F4(slot);
                break;
            case 1:
                s->unk34 += sub_080518F4(slot);
                break;
            case 2:
                s->unkC_8 -= sub_080518F4(slot);
                break;
            case 3:
                s->unkC_8 += sub_080518F4(slot);
                break;
            }
            gUnk_03002C30[slot].unk10_8 = gUnk_03002C30[slot].unk34 -
                                          gUnk_083D69A0[0][gUnk_03002C30[slot].unk28 * (sub_080518F4(slot) << 2)] / 16;
            gUnk_03002C30[slot].unk2C = gUnk_083D69A0[0][gUnk_03002C30[slot].unk28 * (sub_080518F4(slot) << 2)] / 16;
            gUnk_03002C30[slot].unk28++;
            if (gUnk_03002C30[slot].unkB != 0xFF) {
                if (gUnk_03002C30[slot].unk10_8 / 4 <= (gUnk_03002C30[slot].unk34 - 16) / 4)
                    gUnk_03002C30[slot].unkB = 0xFE;
                else
                    sub_0804877C(slot);
            }
        } else {
            sub_0804877C(slot);
            s->unk10_8 = s->unk34;
            s->unk2C = 0;
            ret = 1;
        }
        break;
    }
    return ret;
}

// Clears gNewKeys, gRepeatKeys and gHeldKeys (called every frame by sub_0804E0E8 during scripted scenes).
void sub_08050B50(void) {
    sub_080496C8((u8 *)&gNewKeys, 4);
    sub_080496C8((u8 *)&gRepeatKeys, 4);
    sub_080496C8((u8 *)&gHeldKeys, 4);
}

u32 battle_scene_state_dispatch(void) {
    if ((gUnk_03005350.unk1D4 & 0x3F) == 0xD || (gUnk_03005350.unk1D4 & 0x3F) == 0x16) {
        gUnk_030057E0.unkC5B = 0;
        sub_08052BA0(0);
        update_bg_scroll_offsets_a();
    }
    if (battle_sequence_dispatch() == 4) {
        switch (gUnk_03005350.unk1D4 & 0x3F) {
        case 0:
        case 13:
        case 15:
        case 16:
        case 19:
        case 22:
            break;
        default:
            init_battle_sprites();
            break;
        }
        return 1;
    }
    return 0;
}

void init_battle_sprites(void) {
    s32 i;

    sub_080496C8((u8 *)gUnk_03002C30, 0xA00);
    sub_080492CC();
    for (i = 0; i < 32; i++)
        calculate_oam_affine_matrix(i);
}

void sub_08050C74(void) {
    gUnk_03006D20.unkB = 0;
}

u32 scene_state_dispatch(u32 a, u32 b) {
    u32 zero;
    u32 ret = 0;

    switch (gUnk_03006D20.unkB) {
    case 0:
        if (a != 0x20) {
            s32 n;
            if (a == 0x12)
                dispatch_jump_table_29(0x17, 0);
            n = 8;
            if (a == 8)
                n = 0xFF;
            setup_palette_fade_to_color_with_obj(0, 0.0f, 32.0f, n);
        }
        gUnk_03006D20.unkB++;
        break;
    case 1:
        if (a == 0x20) {
            save_script_sprites();
            switch_game_mode(0x20, b);
            gUnk_03006D20.unkB++;
        } else if (run_blend_fade_transition(0)) {
            if (a == 0x12)
                dispatch_jump_table_29(0x18, 0);
            save_script_sprites();
            switch_game_mode(a, b);
            gUnk_03006D20.unkB++;
        }
        break;
    case 2:
        sub_080496C8((u8 *)gUnk_03002C30, 0x2000);
        sub_080496C8((u8 *)gUnk_030055A0, 0x200);
        zero = 0;
        DmaSet(3, &zero, OAM, 0x85000100);
        zero = 0;
        DmaSet(3, &zero, PLTT, 0x85000100);
        REG_BLDCNT = 0;
        REG_BLDY = 0;
        sub_0804B1FC();
        restore_script_sprites();
        REG_DISPCNT = 0x1E40;
        if (a == 0x10 || a == 0x20)
            gUnk_030057E0.unkCBA = 2;
        else
            gUnk_030057E0.unkCBA = 1;
        update_battle_field_frame();
        field_center_camera_on_player();
        sub_080487E4();
        if (a == 0x13) {
            init_sprite_affine_matrices_and_state(0x93, gUnk_03005350.unk1D8, gUnk_03005350.unk1DC, 0);
            while (!battle_scene_state_dispatch())
                ;
        }
        if (a != 8)
            setup_palette_fade_to_color(0, 32.0f, 0.0f, 8.0f);
        switch (a) {
        case 0x20:
            dispatch_jump_table_29(0xD, 0);
            break;
        case 1:
            dispatch_jump_table_29(0x11, 0);
            break;
        case 3:
            dispatch_jump_table_29(0x14, 0);
            break;
        case 0x13:
            dispatch_jump_table_29(0x13, 0);
            break;
        case 0:
            dispatch_jump_table_29(0x10, 0);
            break;
        case 2:
            dispatch_jump_table_29(0x12, 0);
            break;
        case 8:
            dispatch_jump_table_29(0x1B, 0);
            break;
        case 5:
            dispatch_jump_table_29(0x1A, 0);
            break;
        case 0x10:
            dispatch_jump_table_29(0x15, 0);
            break;
        case 0x12:
            dispatch_jump_table_29(0x19, 0);
            break;
        case 0x11:
            dispatch_jump_table_29(0x16, 0);
            break;
        case 0x14:
            dispatch_jump_table_29(0xF, 0);
            break;
        }
        gUnk_03006D20.unkB++;
        break;
    case 3:
        gUnk_03006D20.unkB++;
        break;
    case 4:
        if (a == 8 || run_blend_fade_transition(0))
            ret = 1;
        break;
    }
    return ret;
}

void sub_08050F10(void) {
    u32 done;
    u32 npc;
    u32 warp;

    switch (gUnk_03005310.unk1) {
    case 0:
        set_battle_state_cancel_flag();
        if (find_map_event_by_coords(gUnk_030057E0.unkC56, gUnk_030057E0.unkC57)) {
            gUnk_030057E0.unkC58 = 16 / sub_080518F4(47);
            field_set_player_facing(gUnk_03002C30[47].unk20);
            sub_080493D4(47, gUnk_03002C30[47].unk20);
            if (gUnk_030057E0.unkC76) {
                gUnk_030057E0.unkC6E = gUnk_030057E0.unkC52;
                gUnk_030057E0.unkC70 = gUnk_030057E0.unkC54;
                set_battle_state_byte_c83(gUnk_03002C30[47].unk20);
                sub_080493D4(48, gUnk_03002C30[48].unk2B * 4 + gUnk_03002C30[48].unk20);
            }
            update_battle_direction_indicator(3);
            gUnk_03005310.unk1 = 1;
        } else {
            if (gUnk_03006D38.unk3 == 4)
                sub_08047BA8(0);
            gUnk_03005310.unk1 = 2;
        }
        break;
    case 1:
        field_player_step(gUnk_03002C30[47].unk20);
        if (gUnk_030057E0.unkC58 == 0) {
            if (gUnk_03006D38.unk3 == 4)
                sub_08047BA8(0);
            gUnk_03005310.unk1++;
        }
        break;
    case 2:
        done = 0;
        npc = 0;
        warp = 0;
        if (gUnk_030057E0.unkC58 == 0 && gUnk_030057E0.unkC88 == 0) {
            update_npc_random_animation();
            if (find_npc_event_match()) {
                npc = 1;
            } else {
                if (find_map_event_by_coords(gUnk_030057E0.unkC56, gUnk_030057E0.unkC57)) {
                    gUnk_03005310.unk1 = 3;
                    if (gUnk_03006D38.unk3)
                        sub_08047BA8(gUnk_083D29E6[gUnk_03006D38.unk3]);
                    setup_palette_fade_to_color_with_obj(0x7FFF, 0.0f, 32.0f, 8.0f);
                    warp = 1;
                }
                if (!npc && !warp) {
                    if (KEYS_LO(gHeldKeys) & 1) {
                        gUnk_03002C30[47].unk2A = 1;
                        gUnk_03002C30[48].unk2A = 1;
                    } else {
                        gUnk_03002C30[48].unk2A = gUnk_03002C30[47].unk2A = gUnk_083D2908[gUnk_030057E0.unkC5C];
                    }
                    if (KEYS_LO(gNewKeys) & 1) {
                        if (map_cursor_move_and_check_event())
                            done = 1;
                        else if (check_room_exit_at_position() != -1) {
                            gGameSubState = 8;
                            done = 1;
                        }
                    } else if (KEYS_LO(gNewKeys) & 2) {
                        if (gUnk_030057E0.unkC33) {
                            sub_08047E4C();
                            gGameMode = 0;
                            gGameState = 1;
                            gGameSubState = 0;
                            gUnk_03005310.unk1C = gBg0Scroll.x;
                            gUnk_03005310.unk24 = gBg0Scroll.y;
                            gUnk_03005310.unk1E = gBg1Scroll.x;
                            gUnk_03005310.unk26 = gBg1Scroll.y;
                            gUnk_03005310.unk20 = gBg2Scroll.x;
                            gUnk_03005310.unk28 = gBg2Scroll.y;
                            gUnk_03005310.unk22 = gBg3Scroll.x;
                            gUnk_03005310.unk2A = gBg3Scroll.y;
                            gBg0Scroll.x = 0;
                            gBg0Scroll.y = 0;
                            gUnk_030057E0.unkC67 = gUnk_03002C30[47].unk20;
                            gUnk_030057E0.unkC83 = gUnk_03002C30[48].unk20;
                            gUnk_030057E0.unkC84 = gUnk_03002C30[48].unk2B;
                            save_script_sprites();
                            gUnk_030057E0.unkCBA = 2;
                            done = 1;
                        }
                    } else if (KEYS_HI(gNewKeys) & 1 && gUnk_030057E0.unkC5C == 1) {
                        sub_08047BA8(0x74);
                    }
                }
            }
        }
        if (!done && !npc && !warp) {
            if (KEYS_HI(gNewKeys) & 1 && gUnk_030057E0.unkC5C == 1)
                sub_08047BA8(0x74);
            field_player_walk_input();
        } else {
            field_set_player_facing(gUnk_03002C30[47].unk20);
            set_battle_state_byte_c83(gUnk_03002C30[48].unk20);
        }
        break;
    case 3:
        if (run_blend_fade_transition(0x7FFF))
            gUnk_03005310.unk1 = 4;
        break;
    case 4:
        field_warp_to_area();
        gUnk_03005310.unk1 = 0;
        gGameMode = 1;
        gGameState = 1;
        gGameSubState = 1;
        gUnk_030057E0.unkCBA = 1;
        break;
    }
    update_bg_scroll_offsets_a();
    update_bg_scroll_offsets_b();
    update_entity_sprites_on_screen();
}

// guess: resets the field frame handler (sub_08050F10 runs a state machine on unk1)
void sub_0805136C(void) {
    gUnk_03005310.unk0 = 1;
    gUnk_03005310.unk1 = 0;
}
