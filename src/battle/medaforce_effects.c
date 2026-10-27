// Medaforce effect sequences: action script opcodes 0x40-0x6A. A Medaforce runs script 0x50 + its id
// (unkF9 = unkA8[0] + 0x50, sub_08034074), so scripts 80-131 use these; 0x45 (side_add_action_point) and a few
// script-side commands sit elsewhere.
// Each runner (sub_XXXXXXXX that clears unkB5 and calls entry [unkAA] of its gBattleMessageSteps sub-table) is
// one action script command (gUnk_083AF000, opcode order = ROM order); its step handlers follow it and
// the last step sets unkB5. Abilities are part data[1], and the script of ability n is gUnk_083C6B28[n].

#include "global.h"

void sub_08026884(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE1C0[gUnk_03001800.unkAA]();
}

void sub_080268AC(void) {
    sub_0803769C(gUnk_03001800.unk87);
    sub_080376F4(gUnk_03001800.unk87);
    gUnk_03001800.unkAA++;
}

void sub_080268D4(void) {
    sub_08037728(gUnk_03001800.unk88, 0, gUnk_03001800.unkEC);
    sub_08037728(gUnk_03001800.unk88, 1, gUnk_03001800.unkEC);
    sub_08037728(gUnk_03001800.unk88, 2, gUnk_03001800.unkEC);
    sub_08037728(gUnk_03001800.unk88, 3, gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void sub_08026924(void) {
    s16 x, y;

    lz_decompress_dispatch(gUnk_084D1824, (void *)0x06010000);
    CpuFastSet(gUnk_0850E018, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    set_display_digit_type(gUnk_03000440.unk9E, gUnk_03001800.unkD6[0], 1);
    setup_battle_sprite_oam_entries(gUnk_03000440.unk9E, 0xA, 0, x, y);
    set_display_digit_type(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkD6[1], 1);
    setup_battle_sprite_oam_entries(gUnk_03000440.unk9E + 0x14, 0xE, 1, x, y);
    set_display_digit_type(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unkD6[2], 1);
    setup_battle_sprite_oam_entries(gUnk_03000440.unk9E + 0x28, 0x12, 2, x, y);
    set_display_digit_type(gUnk_03000440.unk9E + 0x3C, gUnk_03001800.unkD6[3], 1);
    setup_battle_sprite_oam_entries(gUnk_03000440.unk9E + 0x3C, 0x16, 3, x, y);
    play_sound_effect(0x5B);
    gUnk_03001800.unkAA++;
}

void sub_08026A24(void) {
    sub_08036B50(gUnk_03000440.unk9E, 0xA);
    sub_08036B50(gUnk_03000440.unk9E + 0x14, 0xE);
    sub_08036B50(gUnk_03000440.unk9E + 0x28, 0x12);
    if (sub_08036B50(gUnk_03000440.unk9E + 0x3C, 0x16)) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_08026A74(void) {
    s32 n;
    u32 side;

    n = sub_08036BB8(&gUnk_03001800.unkD6[0], gUnk_03001800.unk88, 0);
    n += sub_08036BB8(&gUnk_03001800.unkD6[1], gUnk_03001800.unk88, 1);
    n += sub_08036BB8(&gUnk_03001800.unkD6[2], gUnk_03001800.unk88, 2);
    n += sub_08036BB8(&gUnk_03001800.unkD6[3], gUnk_03001800.unk88, 3);
    if (!(gUnk_03001800.unkF8 & 2))
        side = 1;
    else
        side = 0;
    sub_08036370(side, gUnk_03001800.unk88);
    sub_080364A8(side, gUnk_03001800.unk88);
    if (n == 4) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_08026AF4(void) {
    u16 x, y;
    s32 shown = 0;

    lz_decompress_dispatch(gUnk_084CCE48, (void *)0x06010800);
    CpuFastSet(gUnk_0850E358, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    if (gUnk_03001800.unkD2[0]) {
        sub_08036C20(0xA, 0, x, y, 0x1E);
        shown = 1;
    }
    if (gUnk_03001800.unkD2[1]) {
        sub_08036C20(0xB, 1, x, y, 0x1E);
        shown = 1;
    }
    if (gUnk_03001800.unkD2[2]) {
        sub_08036C20(0xC, 2, x, y, 0x1E);
        shown = 1;
    }
    if (gUnk_03001800.unkD2[3]) {
        sub_08036C20(0xD, 3, x, y, 0x1E);
        shown = 1;
    }
    if (shown) {
        sub_08035194(gUnk_03001800.unk88);
        gUnk_03001800.unkAA = 0xD;
    } else {
        gUnk_03001800.unkAA++;
    }
}

void sub_08026BF8(void) {
    s32 done = 0;

    if (gUnk_03001800.unkD2[0]) {
        process_sprite_anim_commands(gUnk_083B5F80[0x1E], 0xA);
        if (gSpriteEntries[0xA].unk22 == 0xFF)
            done = 1;
    }
    if (gUnk_03001800.unkD2[1]) {
        process_sprite_anim_commands(gUnk_083B5F80[0x1E], 0xB);
        if (gSpriteEntries[0xB].unk22 == 0xFF)
            done = 1;
    }
    if (gUnk_03001800.unkD2[2]) {
        process_sprite_anim_commands(gUnk_083B5F80[0x1E], 0xC);
        if (gSpriteEntries[0xC].unk22 == 0xFF)
            done = 1;
    }
    if (gUnk_03001800.unkD2[3]) {
        process_sprite_anim_commands(gUnk_083B5F80[0x1E], 0xD);
        if (gSpriteEntries[0xD].unk22 == 0xFF)
            done = 1;
    }
    if (done) {
        clear_battle_sprite_slot(0xA, 4);
        gUnk_03001800.unkAA++;
    }
}

void sub_08026CBC(void) {
    if (gUnk_03000590[gUnk_03001800.unk88].parts[0].unk11 == 0)
        add_bot_to_defeated_list(gUnk_03001800.unk88);
    gUnk_03001800.unkAA++;
}

void sub_08026CF4(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE240[gUnk_03001800.unkAA]();
}

void sub_08026D1C(void) {
    if (gUnk_03001800.unkB8 & 2)
        gUnk_03001800.unkAA = 0x20;
    else
        gUnk_03001800.unkAA++;
}

void sub_08026D44(void) {
    if (gUnk_03001800.unkCA) {
        calc_bot_evasion_modifier(gUnk_03001800.unk87);
        sub_080355C4(gUnk_03001800.unk87);
        gUnk_03001800.unkD0 = gUnk_03001800.unk8B;
        battle_set_damage_vs_armor(gUnk_03001800.unk88, gUnk_03001800.unk8B, gUnk_03001800.unkCA);
        gUnk_03001800.unkAA += 3;
    } else {
        gUnk_03001800.unkAA++;
    }
}

void sub_08026D98(void) {
    lz_decompress_dispatch(gUnk_084CA61C, (void *)0x06010000);
    CpuFastSet(gUnk_0850E198, (void *)0x050003C0, 8);
    gSpriteEntries[0xA].unk6 = 0x1500;
    play_sound_effect(0x2A);
    gSpriteEntries[0xA].unk0 = 0xC404;
    gSpriteEntries[0xA].unk1C = 0;
    gSpriteEntries[0xA].unkA = 0xE;
    gSpriteEntries[0xA].unkB = 0x80;
    gSpriteEntries[0xA].unk23 = 0;
    if (!(gUnk_03001800.unkF8 & 2)) {
        if (gUnk_03001800.unk8B == 2)
            gSpriteEntries[0xA].unk2 = gUnk_03001800.unk158 - 0x10;
        else
            gSpriteEntries[0xA].unk2 = gUnk_03001800.unk158;
        gSpriteEntries[0xA].unk4 = gUnk_03001800.unk15A;
    } else {
        if (gUnk_03001800.unk8B == 1)
            gSpriteEntries[0xA].unk2 = gUnk_03001800.unk154 + 0x10;
        else
            gSpriteEntries[0xA].unk2 = gUnk_03001800.unk154;
        gSpriteEntries[0xA].unk4 = gUnk_03001800.unk156;
    }
    gUnk_03001800.unkAA++;
}

void sub_08026EC0(void) {
    gUnk_03001800.unkAA = 2;
}

void sub_08026ED0(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE300[gUnk_03001800.unkAA]();
}

void sub_08026EF8(void) {
    u32 r = find_most_damaged_part(gUnk_03001800.unk87);
    if (r) {
        gUnk_03001800.unk8B = gUnk_03001800.unkD0 = r - 1;
        gUnk_03001800.unkAA = 2;
    } else {
        gUnk_03001800.unkAA++;
    }
}

void sub_08026F34(void) {
    clear_battle_sprite_slot(0, 0x80);
    battle_calc_damage_split(gUnk_03001800.unk87, gUnk_03001800.unkD0, gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void sub_08026F6C(void) {
    u32 r;
    struct Unk_03001800 *g = &gUnk_03001800;
    if (g->unkCA && (r = find_most_damaged_part(g->unk88))) {
        r--;
        g->unkD0 = r;
        g->unk8B = r;
        battle_calc_damage_split(g->unk87, g->unkD0, g->unkCA);
        g->unkAA = 0x10;
    } else {
        g->unkAA++;
    }
}

void sub_08026FC0(void) {
    gUnk_03001800.unkAA = 4;
}

void sub_08026FD0(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE380[gUnk_03001800.unkAA]();
}

void sub_08026FF8(void) {
    u32 i;
    struct Unk_03000590 *bots;
    for (i = 0; i <= 2; i++) {
        gUnk_03001800.unkD2[i] = 0;
        gUnk_03001800.unkD6[i] = 0;
    }
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    i = 0;
    bots = gUnk_03000590;
    for (; i <= 2; i++) {
        u32 rec = gUnk_03001800.unk60 + i;
        if (bots[rec].unk40 && bots[rec].parts[0].unk11) {
            gUnk_03001800.unkD2[i] = get_random_battle_weight_entry(rec);
            battle_set_damage_vs_armor(gUnk_03001800.unk60 + i, gUnk_03001800.unkD2[i], gUnk_03001800.unkEC);
            gUnk_03001800.unkD2[i] |= gUnk_03001800.unkD1 << 7;
            gUnk_03001800.unkD6[i] = gUnk_03001800.unkC8;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_080270BC(void) {
    lz_decompress_dispatch(gUnk_084DB788, (void *)0x06014800);
    CpuFastSet(gUnk_0850EB38, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC624;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = 0x78;
    gSpriteEntries[0x21].unk4 = 0x30;
    gSpriteEntries[0x21].unk8 = 0x80;
    gSpriteEntries[0x21].unk9 = 0x80;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk6 = 0x6500;
    gSpriteEntries[0x22].unk0 = 0x4624;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = 0x78;
    gSpriteEntries[0x22].unk4 = 0x50;
    gSpriteEntries[0x22].unk8 = 0x80;
    gSpriteEntries[0x22].unk9 = 0x80;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = 0xF0;
    gSpriteEntries[0x22].unk6 = 0x6501;
    gUnk_03001800.unkAA++;
}

void sub_080271C4(void) {
    if (gSpriteEntries[0x21].unk8 != 0x40) {
        gSpriteEntries[0x21].unk8 -= 8;
        gSpriteEntries[0x21].unk9 -= 8;
        if (gSpriteEntries[0x21].unk8 == 0x40)
            play_sound_effect(0x30);
    } else {
        gSpriteEntries[0x22].unk0 |= 0x8000;
        if (gSpriteEntries[0x22].unk8 != 0x40) {
            gSpriteEntries[0x22].unk8 -= 8;
            gSpriteEntries[0x22].unk9 -= 8;
            if (gSpriteEntries[0x22].unk8 == 0x40)
                play_sound_effect(0x30);
        } else {
            gUnk_03000440.unk86 = 0x3C;
            gUnk_03001800.unkAA++;
        }
    }
}

void sub_0802724C(void) {
    clear_battle_sprite_slot(0x21, 2);
    gSpriteEntries[0x21].unk0 = 0xC404;
    if (gUnk_03001800.unkF8 & 2)
        gSpriteEntries[0x21].unk0 |= 0x1000;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = 0x78;
    gSpriteEntries[0x21].unk4 = 0x40;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x5A], 0x21);
    gUnk_03001800.unkAA++;
}

void sub_080272EC(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x5A], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        gUnk_03000440.unk86 = 0;
        play_sound_effect(0x73);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802733C(void) {
    gUnk_03000440.unk86++;
    sub_080378A8();
    if (gUnk_03000440.unk86 == 0x10) {
        palette_backup_from_hardware();
        gUnk_03000440.unk84 = 0;
        gUnk_03001800.unkAA++;
    }
}

void sub_08027378(void) {
    gUnk_03000440.unk86++;
    sub_080378A8();
    if (gUnk_03000440.unk84 <= 4) {
        bg_palettes_blend_masked_now(0x7FFF, gUnk_03000440.unk84 * 8, 0xFFFF);
        obj_palettes_blend_masked_now(0x7FFF, gUnk_03000440.unk84 * 8, 0xFFFF);
        gUnk_03000440.unk84++;
    } else {
        gUnk_03000440.unk84 = 0;
        gUnk_03001800.unkAA++;
    }
}

void sub_080273DC(void) {
    gUnk_03000440.unk86++;
    sub_080378A8();
    if (gUnk_03000440.unk84 <= 8) {
        bg_palettes_blend_masked_now(0x7FFF, 0x20 - gUnk_03000440.unk84 * 4, 0xFFFF);
        obj_palettes_blend_masked_now(0x7FFF, 0x20 - gUnk_03000440.unk84 * 4, 0xFFFF);
        gUnk_03000440.unk84++;
    } else {
        gUnk_03001800.unkAA++;
    }
}

void sub_08027444(void) {
    gUnk_03000440.unk86++;
    sub_080378A8();
    if (gUnk_03000440.unk86 > 0x23) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802747C(void) {
    gUnk_03001800.unkA6 = 0x3A;
    gUnk_03001800.unkAA++;
}

void sub_08027494(void) {
    u32 i;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11) {
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[gUnk_03001800.unkD2[i] & 0x7F].unk11 -= gUnk_03001800.unkD6[i];
            sub_08035194(gUnk_03001800.unk60 + i);
            if ((gUnk_03001800.unkD2[i] & 0x7F) == 0 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
                add_bot_to_defeated_list(gUnk_03001800.unk60 + i);
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_08027544(void) {
    u32 i;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40) {
            switch (i) {
            case 0:
                set_display_digit_type(gUnk_03000440.unk9E, gUnk_03001800.unkD6[i], 1);
                battle_number_popup_init_slot(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
                break;
            case 1:
                set_display_digit_type(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkD6[1], 1);
                battle_number_popup_init_slot(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
                break;
            case 2:
                set_display_digit_type(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unkD6[2], 1);
                battle_number_popup_init_slot(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
                break;
            }
        }
    }
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_0802761C(void) {
    u32 i;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40) {
            switch (i) {
            case 0:
                battle_popup_update_slot(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
                break;
            case 1:
                battle_popup_update_slot(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
                break;
            case 2:
                battle_popup_update_slot(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
                break;
            }
        }
    }
    gUnk_03000440.unk84++;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1) && gUnk_03000440.unk84 > 0x32)
        gUnk_03000440.unk84 = 0x78;
    if (gUnk_03000440.unk84 == 0x78) {
        clear_battle_sprite_slot(gUnk_03001800.unk60 * 4 + 0x21, 0xC);
        gUnk_03001800.unkAA++;
    }
}

void decompress_sprite_tiles_to_vram_obj_4800_alt(void) {
    u32 done = 0;
    u32 i;

    lz_decompress_dispatch(gUnk_084CDBD8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E378, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] & 0x80) {
            setup_battle_cursor_sprite_08036FF8(
                i * 4 + 0x21,
                gSpriteEntries[0x5A + (gUnk_03001800.unk60 + i) * 4 + (gUnk_03001800.unkD2[i] & 0x7F)].unk2,
                gSpriteEntries[0x5A + (gUnk_03001800.unk60 + i) * 4 + (gUnk_03001800.unkD2[i] & 0x7F)].unk4, 4);
            done = 1;
        }
    }
    if (!done)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 3;
}

void sub_08027798(void) {
    u32 r = 0;
    u32 i;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] & 0x80)
            r = update_sprite_animations_tick_080370AC(i * 4 + 0x21, 4);
    }
    if (r)
        gUnk_03001800.unkAA++;
}

void sub_080277DC(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084CC9A8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E338, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] & 0x80) {
            gSpriteEntries[i + 0x21].unk0 = 0xC004;
            gSpriteEntries[i + 0x21].unk1C = 0;
            gSpriteEntries[i + 0x21].unk2 =
                gSpriteEntries[0x5A + (gUnk_03001800.unk60 + i) * 4 + (gUnk_03001800.unkD2[i] & 0x7F)].unk2;
            gSpriteEntries[i + 0x21].unk4 =
                gSpriteEntries[0x5A + (gUnk_03001800.unk60 + i) * 4 + (gUnk_03001800.unkD2[i] & 0x7F)].unk4;
            gSpriteEntries[i + 0x21].unkA = 7;
            gSpriteEntries[i + 0x21].unkB = 0xF0;
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x22], i + 0x21);
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_080278B8(void) {
    u32 done = 0;
    u32 i;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] & 0x80) {
            u8 slot;
            process_sprite_anim_commands(gUnk_083B5F80[0x22], slot = i + 0x21);
            if (gSpriteEntries[i + 0x21].unk22 == 0xFF) {
                clear_battle_sprite_slot(slot, 1);
                done = 1;
            }
        }
    }
    if (done) {
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
        gUnk_03001800.unkAA++;
    }
}

void sub_0802793C(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE400[gUnk_03001800.unkAA]();
}

void sub_08027964(void) {
    switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0]) {
    case 4:
        gUnk_03001800.unk51 = 0;
        break;
    case 5:
        gUnk_03001800.unk51 = 1;
        break;
    case 6:
        gUnk_03001800.unk51 = 2;
        break;
    case 7:
        gUnk_03001800.unk51 = 3;
        break;
    case 8:
        gUnk_03001800.unk51 = 4;
        break;
    default:
        gUnk_03001800.unk51 = 5;
        break;
    }
    gUnk_03001800.unkAA++;
}

void sub_080279E4(void) {
    lz_decompress_dispatch(gUnk_084DBB28, (void *)0x06014800);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0]) {
    case 4:
    case 5:
        lz_decompress_dispatch(gUnk_084DBCAC, (void *)0x06014C00);
        CpuFastSet(gUnk_0850EB58, (void *)0x050002E0, 8);
        play_sound_effect(0x27);
        break;
    case 6:
    case 7:
        lz_decompress_dispatch(gUnk_084DBD0C, (void *)0x06014C00);
        CpuFastSet(gUnk_0850EB78, (void *)0x050002E0, 8);
        play_sound_effect(0x45);
        break;
    case 8:
    default:
        lz_decompress_dispatch(gUnk_084DBD60, (void *)0x06014C00);
        CpuFastSet(gUnk_0850EB98, (void *)0x050002E0, 8);
        play_sound_effect(0x33);
        break;
    }
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[0x5D + gUnk_03001800.unk87 * 4].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[0x5D + gUnk_03001800.unk87 * 4].unk4 - 4;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unkB = 0xF0;
    if (gUnk_03001800.unk51 & 1)
        gSpriteEntries[0x21].unk6 = 0x6601;
    else
        gSpriteEntries[0x21].unk6 = 0x6600;
    gUnk_03000440.unk86 = 0;
    gUnk_03001800.unkAA++;
}

void sub_08027BA0(void) {
    gUnk_03000440.unk86++;
    gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x40) & 0x3FF;
    if (gUnk_03000440.unk86 > 0x3C)
        gUnk_03001800.unkAA++;
}

void sub_08027BEC(void) {
    gUnk_03000440.unk86++;
    gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x40) & 0x3FF;
    gSpriteEntries[0x22].unk0 = 0xC624;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = gSpriteEntries[0x5D + gUnk_03001800.unk87 * 4].unk2;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[0x5D + gUnk_03001800.unk87 * 4].unk4 - 4;
    gSpriteEntries[0x22].unk8 = 0x80;
    gSpriteEntries[0x22].unk9 = 0x80;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = 0xF1;
    gSpriteEntries[0x22].unk6 = 0x6700;
    gUnk_03001800.unkAA++;
}

void sub_08027CB0(void) {
    gUnk_03000440.unk86++;
    gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x40) & 0x3FF;
    if (gSpriteEntries[0x22].unk8 == 0x40) {
        play_sound_effect(0x30);
        gUnk_03000440.unk84 = 0x3C;
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x22].unk8 -= 8;
        gSpriteEntries[0x22].unk9 -= 8;
    }
}

void sub_08027D24(void) {
    gUnk_03000440.unk86++;
    gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x40) & 0x3FF;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1)) {
        play_sound_effect(0x2B);
        gUnk_03001800.unkAA++;
    } else if (gUnk_03000440.unk84) {
        gUnk_03000440.unk84--;
    } else {
        play_sound_effect(0x2B);
        gUnk_03001800.unkAA++;
    }
}

void sub_08027D98(void) {
    gUnk_03000440.unk86++;
    gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x40) & 0x3FF;
    if (gSpriteEntries[0x21].unk8 == 4) {
        clear_battle_sprite_slot(0x21, 2);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 4;
        gSpriteEntries[0x21].unk9 -= 4;
        gSpriteEntries[0x22].unk8 -= 4;
        gSpriteEntries[0x22].unk9 -= 4;
    }
}

void sub_08027E1C(void) {
    switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0]) {
    case 4:
        gUnk_03000590[gUnk_03001800.unk87].unkD6 |= 1;
        break;
    case 5:
        gUnk_03000590[gUnk_03001800.unk87].unkD6 |= 8;
        break;
    case 6:
        gUnk_03000590[gUnk_03001800.unk87].unkD6 |= 2;
        break;
    case 7:
        gUnk_03000590[gUnk_03001800.unk87].unkD6 |= 0x10;
        break;
    case 8:
        gUnk_03000590[gUnk_03001800.unk87].unkD6 |= 4;
        break;
    default:
        gUnk_03000590[gUnk_03001800.unk87].unkD6 |= 0x20;
        break;
    }
    gUnk_03001800.unkAA++;
}

void sub_08027EDC(void) {
    switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0]) {
    case 4:
        gUnk_03001800.unkA6 = 0x4A;
        break;
    case 5:
        gUnk_03001800.unkA6 = 0x61;
        break;
    case 6:
        gUnk_03001800.unkA6 = 0x4B;
        break;
    case 7:
        gUnk_03001800.unkA6 = 0x62;
        break;
    case 8:
        gUnk_03001800.unkA6 = 0x4C;
        break;
    default:
        gUnk_03001800.unkA6 = 0x63;
        break;
    }
    gUnk_03001800.unkAA++;
}

void sub_08027F5C(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE440[gUnk_03001800.unkAA]();
}

void sub_08027F84(void) {
    lz_decompress_dispatch(gUnk_084C978C, (void *)0x06014800);
    CpuFastSet(gUnk_0850E0B8, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 |= 0x220;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk8 = 8;
    gSpriteEntries[0x21].unk4 = 0x3C;
    gSpriteEntries[0x21].unk6 = 0xE00;
    if (gUnk_03001800.unkF8 & 1) {
        gSpriteEntries[0x21].unk0 |= 0x1000;
        gSpriteEntries[0x21].unk2--;
    }
    gUnk_03001800.unkAA++;
}

void sub_08028034(void) {
    gSpriteEntries[0x21].unk8 += 8;
    if (gSpriteEntries[0x21].unk8 == 0x40) {
        gUnk_03000440.unk86 = 0x3C;
        gSpriteEntries[0x21].unk27 = 0;
        gUnk_03001800.unkAA++;
    }
}

void sub_08028078(void) {
    if (gUnk_03001800.unk28[gUnk_03001800.unk8A].unk2 && gUnk_03001800.unk28[gUnk_03001800.unk8A].unk3 == 0x5A) {
        gSpriteEntries[0x21].unk27 = 0;
        gUnk_03001800.unkAA++;
    } else {
        play_sound_effect(0x3E);
        gUnk_03001800.unkAA += 2;
    }
}

void sub_080280D4(void) {
    if (gSpriteEntries[0x21].unk27 == 0x10) {
        play_sound_effect(0x3E);
        gUnk_03001800.unkAA++;
        return;
    }
    if (gSpriteEntries[0x21].unk27 < 8)
        gSpriteEntries[0x21].unk8 += 8;
    else
        gSpriteEntries[0x21].unk8 -= 8;
    gSpriteEntries[0x21].unk27++;
}

void sub_08028130(void) {
    if (gUnk_03001800.unk28[gUnk_03001800.unk8A].unk2 && gUnk_03001800.unk28[gUnk_03001800.unk8A].unk3 == 0x5A) {
        gUnk_03001800.unk53 = 1;
        add_u8_capped(&gUnk_03001800.unk28[gUnk_03001800.unk8A].unk4, gUnk_03001800.unkE8 >> 1, 0xFF);
        add_u8_capped(&gUnk_03001800.unk28[gUnk_03001800.unk8A].unk5,
                      (gUnk_03001800.unkEC + gUnk_03000590[gUnk_03001800.unk87].unkD5) >> 1, 0xFF);
        gUnk_03001800.unkAA++;
    } else {
        gUnk_03001800.unk53 = 0;
        gUnk_03001800.unk28[gUnk_03001800.unk8A].unk2 = 1;
        gUnk_03001800.unk28[gUnk_03001800.unk8A].unk3 = 0x5A;
        gUnk_03001800.unk28[gUnk_03001800.unk8A].unk4 = 0;
        gUnk_03001800.unk28[gUnk_03001800.unk8A].unk5 = 0;
        add_u8_capped(&gUnk_03001800.unk28[gUnk_03001800.unk8A].unk4, gUnk_03001800.unkE8, 0xFF);
        add_u8_capped(&gUnk_03001800.unk28[gUnk_03001800.unk8A].unk5,
                      gUnk_03001800.unkEC + gUnk_03000590[gUnk_03001800.unk87].unkD5, 0xFF);
        gUnk_03001800.unkAA++;
    }
}

void sub_08028230(void) {
    gUnk_03001800.unkA6 = 0x50;
    gUnk_03001800.unkAA++;
}

void sub_08028248(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE480[gUnk_03001800.unkAA]();
}

void sub_08028270(void) {
    lz_decompress_dispatch(gUnk_084DBDC8, (void *)0x06014800);
    CpuFastSet(gUnk_0850EBB8, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk6 = 0x6A00;
    gSpriteEntries[0x21].unk4 += 4;
    gSpriteEntries[0x21].unk27 = 0;
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void sub_080282E0(void) {
    if (gSpriteEntries[0x21].unk27 == 0x10) {
        play_sound_effect(0x28);
        gSpriteEntries[0x21].unk27 = 0;
        gUnk_03001800.unkAA++;
        return;
    }
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x21].unk2--;
    else
        gSpriteEntries[0x21].unk2++;
    gSpriteEntries[0x21].unk27++;
}

void sub_08028350(void) {
    gSpriteEntries[0x21].unk27++;
    if (gSpriteEntries[0x21].unk27 & 2)
        gSpriteEntries[0x21].unk0 |= 0x8000;
    else
        gSpriteEntries[0x21].unk0 &= 0x7FFF;
    if (gSpriteEntries[0x21].unk27 == 0x3C) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_080283C0(void) {
    gUnk_03000590[gUnk_03001800.unk87].unkC0 |= 2;
    gUnk_03001800.unkAA++;
}

void sub_080283EC(void) {
    gUnk_03001800.unkA6 = 0x64;
    gUnk_03001800.unkAA++;
}

void sub_08028404(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE4C0[gUnk_03001800.unkAA]();
}

void sub_0802842C(void) {
    switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0]) {
    case 0xC:
        gUnk_03001800.unk51 = 0;
        break;
    case 0xE:
        gUnk_03001800.unk51 = 1;
        break;
    case 0x10:
        gUnk_03001800.unk51 = 2;
        break;
    case 0x12:
        gUnk_03001800.unk51 = 3;
        break;
    case 0x28:
        gUnk_03001800.unk51 = 4;
        break;
    }
    gUnk_03001800.unkAA++;
}

void sub_08028504(void) {
    switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0]) {
    case 0xC:
        lz_decompress_dispatch(gUnk_084DBEE4, (void *)0x06014800);
        CpuFastSet(gUnk_0850EBD8, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk28 = 0;
        gSpriteEntries[0x21].unk2E = 0x5B;
        break;
    case 0xE:
        lz_decompress_dispatch(gUnk_084DC100, (void *)0x06014800);
        CpuFastSet(gUnk_0850EBF8, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk28 = 1;
        gSpriteEntries[0x21].unk2E = 0x5B;
        break;
    case 0x10:
        lz_decompress_dispatch(gUnk_084DC544, (void *)0x06014800);
        CpuFastSet(gUnk_0850EC18, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk28 = 2;
        gSpriteEntries[0x21].unk2E = 0x5B;
        break;
    case 0x12:
        lz_decompress_dispatch(gUnk_084DC7D0, (void *)0x06014800);
        CpuFastSet(gUnk_0850EC38, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk28 = 3;
        gSpriteEntries[0x21].unk2E = 0x5C;
        break;
    case 0x28:
        lz_decompress_dispatch(gUnk_084DD188, (void *)0x06014800);
        CpuFastSet(gUnk_0850EC78, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk28 = 4;
        gSpriteEntries[0x21].unk2E = 0x5B;
        break;
    }
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk4 = 0xE0;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk29 = 1;
    gSpriteEntries[0x21].unk2B = 0x20;
    gSpriteEntries[0x21].unk2C = 0xC0;
    gSpriteEntries[0x21].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[0x21].unk2E], 0x21);
    if (!(gUnk_03001800.unkF8 & 1)) {
        gSpriteEntries[0x21].unk2 = 0xB8;
    } else {
        gSpriteEntries[0x21].unk0 |= 0x1000;
        gSpriteEntries[0x21].unk2 = 0x38;
    }
    gUnk_03001800.unkAA++;
}

void sub_080287C0(void) {
    if (sub_08037B9C())
        gUnk_03001800.unkAA++;
}

void sub_080287DC(void) {
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        if (battle_bot_lacks_stability(gUnk_03001800.unk60 + i) == 0)
            continue;
        switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0]) {
        case 0xC:
            if (sub_08036D64(gUnk_03001800.unk60 + i, 0xD) == 0) {
                gUnk_03001800.unkD2[i] = 1;
                battle_set_action_params(gUnk_03001800.unk60 + i, 0xD, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            }
            break;
        case 0xE:
            if (sub_08036D64(gUnk_03001800.unk60 + i, 0x10) == 0) {
                gUnk_03001800.unkD2[i] = 1;
                battle_set_action_params(gUnk_03001800.unk60 + i, 0x10, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            }
            break;
        case 0x10:
            if (sub_08036D64(gUnk_03001800.unk60 + i, 0x12) == 0) {
                gUnk_03001800.unkD2[i] = 1;
                battle_set_action_params(gUnk_03001800.unk60 + i, 0x12, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            }
            break;
        case 0x12:
            if (sub_08036D64(gUnk_03001800.unk60 + i, 0x13) == 0) {
                gUnk_03001800.unkD2[i] = 1;
                battle_set_action_params(gUnk_03001800.unk60 + i, 0x13, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            }
            break;
        case 0x28:
            gUnk_03001800.unkD2[i] = 1;
            battle_set_action_params(gUnk_03001800.unk60 + i, 0x2C, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            break;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_08028A00(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            gUnk_03001800.unkAA += 2;
            return;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_08028A38(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084DCF54, (void *)0x06016000);
    CpuFastSet(gUnk_0850EC58, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk0 = 0xC404;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        gSpriteEntries[0x21 + i].unk23 = 0;
        switch (gUnk_03001800.unk51) {
        case 0:
            gSpriteEntries[0x21 + i].unk6 = 0x6F00;
            break;
        case 1:
            gSpriteEntries[0x21 + i].unk6 = 0x6F03;
            break;
        case 2:
            gSpriteEntries[0x21 + i].unk6 = 0x6F01;
            break;
        case 3:
            gSpriteEntries[0x21 + i].unk6 = 0x6F02;
            break;
        case 4:
            gSpriteEntries[0x21 + i].unk6 = 0x6F05;
            break;
        case 5:
            gSpriteEntries[0x21 + i].unk6 = 0x6F04;
            break;
        }
    }
    play_sound_effect(0x5B);
    gUnk_03001800.unkAA++;
}

void sub_08028B58(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] && advance_sprite_anim_frame(0x21 + i, 0))
            done = 1;
    }
    if (done) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_08028BA8(void) {
    clear_battle_sprite_slot(0x21, 3);
    switch (gUnk_03001800.unk51) {
    case 0:
        gUnk_03001800.unkA6 = 0x46;
        break;
    case 1:
        gUnk_03001800.unkA6 = 0x49;
        break;
    case 2:
        gUnk_03001800.unkA6 = 0x47;
        break;
    case 3:
        gUnk_03001800.unkA6 = 0x48;
        break;
    case 4:
        gUnk_03001800.unkA6 = 0x5D;
        break;
    case 5:
        gUnk_03001800.unkA6 = 0x5E;
        break;
    }
    gUnk_03001800.unkAA++;
}

void sub_08028C40(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE500[gUnk_03001800.unkAA]();
}

void sub_08028C68(void) {
    switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0]) {
    case 0xD:
        gUnk_03001800.unk51 = 0;
        break;
    case 0xF:
        gUnk_03001800.unk51 = 1;
        break;
    case 0x11:
        gUnk_03001800.unk51 = 2;
        break;
    case 0x13:
        gUnk_03001800.unk51 = 3;
        break;
    }
    gUnk_03001800.unkAA++;
}

void sub_08028CC8(void) {
    switch (gUnk_03001800.unk51) {
    case 0:
        lz_decompress_dispatch(gUnk_084DBEE4, (void *)0x06014800);
        CpuFastSet(gUnk_0850EBD8, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk2E = 0x5B;
        break;
    case 1:
        lz_decompress_dispatch(gUnk_084DC100, (void *)0x06014800);
        CpuFastSet(gUnk_0850EBF8, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk2E = 0x5B;
        break;
    case 2:
        lz_decompress_dispatch(gUnk_084DC544, (void *)0x06014800);
        CpuFastSet(gUnk_0850EC18, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk2E = 0x5B;
        break;
    case 3:
        lz_decompress_dispatch(gUnk_084DC7D0, (void *)0x06014800);
        CpuFastSet(gUnk_0850EC38, (void *)0x050002E0, 8);
        gSpriteEntries[0x21].unk2E = 0x5C;
        break;
    }
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk4 = 0xE0;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[0x21].unk2E], 0x21);
    if (gUnk_03001800.unkF8 & 1) {
        gSpriteEntries[0x21].unk2 = 0xB8;
    } else {
        gSpriteEntries[0x21].unk0 |= 0x1000;
        gSpriteEntries[0x21].unk2 = 0x38;
    }
    play_sound_effect(0x61);
    gUnk_03001800.unkAA++;
}

void sub_08028E84(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[0x21].unk2E], 0x21);
    if (gSpriteEntries[0x21].unk4 == 0x40) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
        return;
    }
    gSpriteEntries[0x21].unk4 = (gSpriteEntries[0x21].unk4 + 2) & 0xFF;
    if (gUnk_03001800.unkF8 & 1) {
        if (gUnk_03001800.unk51 != 3)
            gSpriteEntries[gUnk_03000440.unk12F].unk18 = (gSpriteEntries[gUnk_03000440.unk12F].unk18 - 0x10) & 0x3FF;
    } else {
        if (gUnk_03001800.unk51 != 3)
            gSpriteEntries[gUnk_03000440.unk12F].unk18 = (gSpriteEntries[gUnk_03000440.unk12F].unk18 + 0x10) & 0x3FF;
    }
}

void sub_08028F4C(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[0x21].unk2E], 0x21);
    if (gUnk_03001800.unkF8 & 1) {
        if (gUnk_03001800.unk51 != 3)
            gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 - 0x10) & 0x3FF;
    } else {
        if (gUnk_03001800.unk51 != 3)
            gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x10) & 0x3FF;
    }
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03001800.unkAA++;
    else if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else
        gUnk_03001800.unkAA++;
}

void sub_08029004(void) {
    lz_decompress_dispatch(gUnk_084CCE48, (void *)0x06014800);
    CpuFastSet(gUnk_0850E358, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x23], 0x21);
    CpuSet(&gSpriteEntries[0x21], &gSpriteEntries[0x22], 0x20);
    CpuSet(&gSpriteEntries[0x21], &gSpriteEntries[0x23], 0x20);
    CpuSet(&gSpriteEntries[0x21], &gSpriteEntries[0x24], 0x20);
    CpuSet(&gSpriteEntries[0x21], &gSpriteEntries[0x25], 0x20);
    gSpriteEntries[0x21].unk24 = 0;
    gSpriteEntries[0x22].unk24 = 2;
    gSpriteEntries[0x22].unk25 = 0x1C;
    gSpriteEntries[0x22].unk2 -= 0x10;
    gSpriteEntries[0x22].unk4 -= 0x10;
    gSpriteEntries[0x23].unk24 = 2;
    gSpriteEntries[0x23].unk25 = 4;
    gSpriteEntries[0x23].unk2 += 0x10;
    gSpriteEntries[0x23].unk4 -= 0x10;
    gSpriteEntries[0x24].unk24 = 2;
    gSpriteEntries[0x24].unk25 = 0x14;
    gSpriteEntries[0x24].unk2 -= 0x10;
    gSpriteEntries[0x24].unk4 += 0x10;
    gSpriteEntries[0x25].unk24 = 2;
    gSpriteEntries[0x25].unk25 = 0xC;
    gSpriteEntries[0x25].unk2 += 0x10;
    gSpriteEntries[0x25].unk4 += 0x10;
    gUnk_03001800.unkAA++;
}

void sub_08029178(void) {
    u32 i;

    for (i = 0; i <= 4; i++) {
        process_sprite_anim_commands(gUnk_083B5F80[0x23], 0x21 + i);
        update_sprite_animation_position(0x21 + i);
    }
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 5);
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_080291E0(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084DD45C, (void *)0x06014800);
    CpuFastSet(gUnk_0850EC98, (void *)0x050002E0, 8);
    sub_0803836C();
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        gUnk_03001800.unkD2[i] = 1;
        gSpriteEntries[0x21 + i].unk0 = 0xC404;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x5F], 0x21 + i);
    }
    gUnk_03001800.unkAA++;
}

void sub_080292D4(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            process_sprite_anim_commands(gUnk_083B5F80[0x5F], 0x21 + i);
            if (gSpriteEntries[0x21 + i].unk22 == 0xFF)
                done = 1;
        }
    }
    if (done) {
        clear_battle_sprite_slot(0x21, 3);
        gUnk_03001800.unkAA++;
    }
}

void sub_08029354(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        switch (gUnk_03001800.unk51) {
        case 0:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCF |= 1;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 == 0xD)
                goto call_0xD;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 != 0xE)
                break;
        call_0xD:
            sub_08038394(gUnk_03001800.unk60 + i, 1);
            break;
        case 1:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCF |= 8;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 == 0xF)
                goto call_0xF;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 != 0x10)
                break;
        call_0xF:
            sub_08038394(gUnk_03001800.unk60 + i, 1);
            break;
        case 2:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCF |= 2;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 == 0x11)
                goto call_0x11;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 != 0x12)
                break;
        call_0x11:
            sub_08038394(gUnk_03001800.unk60 + i, 1);
            break;
        case 3:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCF |= 4;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 == 0x13)
                goto call_0x13;
            if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 != 0x14)
                break;
        call_0x13:
            sub_08038394(gUnk_03001800.unk60 + i, 1);
            break;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_08029464(void) {
    switch (gUnk_03001800.unk51) {
    case 0:
        gUnk_03001800.unkA6 = 0x55;
        break;
    case 1:
        gUnk_03001800.unkA6 = 0x58;
        break;
    case 2:
        gUnk_03001800.unkA6 = 0x56;
        break;
    case 3:
        gUnk_03001800.unkA6 = 0x57;
        break;
    }
    gUnk_03001800.unkAA++;
}

void sub_080294B4(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE540[gUnk_03001800.unkAA]();
}

void sub_080294DC(void) {
    lz_decompress_dispatch(gUnk_084DD648, (void *)0x06014800);
    CpuFastSet(gUnk_0850ECB8, (void *)0x050002E0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk4 = 0xE0;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk28 = 0;
    gSpriteEntries[0x21].unk2E = 0x5B;
    gSpriteEntries[0x21].unk29 = 6;
    gSpriteEntries[0x21].unk2B = 0x20;
    gSpriteEntries[0x21].unk2C = 0xC0;
    gSpriteEntries[0x21].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[0x21].unk2E], 0x21);
    if (gUnk_03001800.unkF8 & 1)
        gSpriteEntries[0x21].unk2 = 0xB8;
    else
        gSpriteEntries[0x21].unk2 = 0x38;
    gUnk_03001800.unk51 = 0;
    gUnk_03001800.unkAA++;
}

void sub_08029600(void) {
    u32 found = 0;
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 == 0)
            continue;
        found = 1;
        gUnk_03001800.unkD2[i] = found;
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 2;
}

void sub_08029680(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084D55D0, (void *)0x06014800);
    CpuFastSet(gUnk_0850E6B8, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk0 = 0xC404;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x3C], 0x21 + i);
        if (gUnk_03001800.unkF8 & 1)
            gSpriteEntries[0x21 + i].unk0 |= 0x1000;
    }
    play_sound_effect(0x37);
    gUnk_03001800.unkAA++;
}

void sub_0802976C(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            process_sprite_anim_commands(gUnk_083B5F80[0x3C], 0x21 + i);
            if (gSpriteEntries[0x21 + i].unk22 == 0xFF)
                done = 1;
        }
    }
    if (done) {
        clear_battle_sprite_slot(0x21, 3);
        gUnk_03001800.unkAA++;
    }
}

void sub_080297EC(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i])
            sub_08038394(gUnk_03001800.unk60 + i, 1);
    }
    gUnk_03001800.unkAA++;
}

void sub_08029828(void) {
    gUnk_03001800.unkA6 = 0x53;
    gUnk_03001800.unkAA++;
}

void sub_08029840(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE580[gUnk_03001800.unkAA]();
}

void sub_08029868(void) {
    lz_decompress_dispatch(gUnk_084DD894, (void *)0x06014800);
    CpuFastSet(gUnk_0850ECD8, (void *)0x050002E0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk4 = 0xE0;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk28 = 0;
    gSpriteEntries[0x21].unk2E = 0x5C;
    gSpriteEntries[0x21].unk29 = 6;
    gSpriteEntries[0x21].unk2B = 0x20;
    gSpriteEntries[0x21].unk2C = 0xC0;
    gSpriteEntries[0x21].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[0x21].unk2E], 0x21);
    if (gUnk_03001800.unkF8 & 1)
        gSpriteEntries[0x21].unk2 = 0xB8;
    else
        gSpriteEntries[0x21].unk2 = 0x38;
    gUnk_03001800.unk51 = 1;
    gUnk_03001800.unkAA++;
}

void sub_08029984(void) {
    u32 found = 0;
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        if (find_most_damaged_part(gUnk_03001800.unk60 + i) == 0)
            continue;
        found = 1;
        gUnk_03001800.unkD2[i] = found;
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 2;
}

void sub_08029A14(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084DE4BC, (void *)0x06014800);
    CpuFastSet(gUnk_0850ED18, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk0 = 0xC404;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x60], 0x21 + i);
        if (gUnk_03001800.unkF8 & 1)
            gSpriteEntries[0x21 + i].unk0 |= 0x1000;
    }
    play_sound_effect(0x2A);
    gUnk_03001800.unkAA++;
}

void sub_08029B04(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            process_sprite_anim_commands(gUnk_083B5F80[0x60], 0x21 + i);
            if (gSpriteEntries[0x21 + i].unk22 == 0xFF)
                done = 1;
        }
    }
    if (done) {
        clear_battle_sprite_slot(0x21, 3);
        gUnk_03001800.unkAA++;
    }
}

void sub_08029B84(void) {
    u32 i, j;
    u32 r;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        for (j = 0; j <= 3; j++) {
            r = find_most_damaged_part(gUnk_03001800.unk60 + i);
            if (r == 0)
                goto next;
            gUnk_03001800.unkD0 = r - 1;
            battle_calc_damage_split(gUnk_03001800.unk60 + i, gUnk_03001800.unkD0, gUnk_03001800.unkEC);
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[gUnk_03001800.unkD0].unk11 += gUnk_03001800.unkC8;
            gUnk_03001800.unkD6[i] += gUnk_03001800.unkC8;
            if (gUnk_03001800.unkCA == 0)
                goto next;
            gUnk_03001800.unkEC = gUnk_03001800.unkCA;
        }
    next:;
    }
    gUnk_03001800.unkAA++;
}

void init_battle_bot_display_digits(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        switch (i) {
        case 0:
            set_display_digit_type(gUnk_03000440.unk9E, gUnk_03001800.unkD6[i], 0);
            battle_number_popup_init_slot(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
            break;
        case 1:
            set_display_digit_type(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkD6[1], 0);
            battle_number_popup_init_slot(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
            break;
        case 2:
            set_display_digit_type(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unkD6[2], 0);
            battle_number_popup_init_slot(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
            break;
        }
    }
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_08029D28(void) {
    u32 i;
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            switch (i) {
            case 0:
                battle_popup_update_slot(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
                break;
            case 1:
                battle_popup_update_slot(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
                break;
            case 2:
                battle_popup_update_slot(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
                break;
            }
        }
    }
    gUnk_03000440.unk84++;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1) && gUnk_03000440.unk84 > 0x32)
        gUnk_03000440.unk84 = 0x78;
    if (gUnk_03000440.unk84 == 0x78) {
        clear_battle_sprite_slot(gUnk_03001800.unk60 * 4 + 0x21, 0xC);
        gUnk_03001800.unkAA++;
    }
}

void sub_08029DF4(void) {
    gUnk_03001800.unkA6 = 0x3B;
    gUnk_03001800.unkAA++;
}

void sub_08029E0C(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE5C0[gUnk_03001800.unkAA]();
}

void sub_08029E34(void) {
    lz_decompress_dispatch(gUnk_084DDEA4, (void *)0x06014800);
    CpuFastSet(gUnk_0850ECF8, (void *)0x050002E0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk4 = 0xE0;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk28 = 0;
    gSpriteEntries[0x21].unk2E = 0x5C;
    gSpriteEntries[0x21].unk29 = 6;
    gSpriteEntries[0x21].unk2B = 0x20;
    gSpriteEntries[0x21].unk2C = 0xC0;
    gSpriteEntries[0x21].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[0x21].unk2E], 0x21);
    if (gUnk_03001800.unkF8 & 1)
        gSpriteEntries[0x21].unk2 = 0xB8;
    else
        gSpriteEntries[0x21].unk2 = 0x38;
    gUnk_03001800.unk51 = 2;
    gUnk_03001800.unkAA++;
}

void sub_08029F50(void) {
    u32 found = 0;
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        if (find_random_broken_part(gUnk_03001800.unk60 + i) == 0)
            continue;
        found = 1;
        gUnk_03001800.unkD2[i] = found;
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 2;
}

void sub_08029FE0(void) {
    u32 i, j;
    u32 r;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        for (j = 0; j <= 3; j++) {
            r = find_random_broken_part(gUnk_03001800.unk60 + i);
            if (r == 0)
                goto next;
            gUnk_03001800.unkD0 = r - 1;
            battle_set_damage_display(gUnk_03001800.unk60 + i, gUnk_03001800.unkD0, gUnk_03001800.unkEC);
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[gUnk_03001800.unkD0].unk11 += gUnk_03001800.unkC8;
            gUnk_03001800.unkD6[i] += gUnk_03001800.unkC8;
            sub_080351E8(gUnk_03001800.unk60 + i);
            if (gUnk_03001800.unkCA == 0)
                goto next;
            gUnk_03001800.unkEC = gUnk_03001800.unkCA;
        }
    next:;
    }
    load_all_bot_part_sprites();
    iterate_bots_setup_battle_sprites();
    gUnk_03001800.unkAA++;
}

void sub_0802A0D0(void) {
    gUnk_03001800.unkA6 = 0x3C;
    gUnk_03001800.unkAA++;
}

void sub_0802A0E8(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE600[gUnk_03001800.unkAA]();
}

void sub_0802A110(void) {
    lz_decompress_dispatch(gUnk_084DE628, (void *)0x06014800);
    CpuFastSet(gUnk_0850ED38, (void *)0x050002E0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = 0x78;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk8 = 4;
    gSpriteEntries[0x21].unk9 = 4;
    gSpriteEntries[0x21].unk18 = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x61], 0x21);
    gSpriteEntries[0x22].unk0 = 0xC604;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = 0x78;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x22].unkA = 6;
    gSpriteEntries[0x22].unkB = 0xE0;
    gSpriteEntries[0x22].unk8 = 4;
    gSpriteEntries[0x22].unk9 = 4;
    gSpriteEntries[0x22].unk18 = 0;
    gSpriteEntries[0x22].unk6 = 0x7604;
    play_sound_effect(0x67);
    gUnk_03001800.unkAA++;
}

void sub_0802A274(void) {
    if (gSpriteEntries[0x21].unk8 == 0x40) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 += 4;
        gSpriteEntries[0x21].unk9 += 4;
        gSpriteEntries[0x22].unk8 += 4;
        gSpriteEntries[0x22].unk9 += 4;
    }
}

void sub_0802A2D4(void) {
    if (gSpriteEntries[0x21].unk4 == 0x20) {
        play_sound_effect(0x42);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk4--;
        gSpriteEntries[0x22].unk4--;
    }
}

void sub_0802A31C(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x61], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802A360(void) {
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        memcpy_bytes_0803F63C(&gSpriteEntries[0x22], &gSpriteEntries[0x23 + i], 0x40);
        gSpriteEntries[0x23 + i].unk30 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x23 + i].unk32 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x23 + i].unk24 = 3;
        gSpriteEntries[0x23 + i].unk23 = 0;
        gUnk_03001800.unkD2[i] = 1;
    }
    clear_battle_sprite_slot(0x22, 1);
    gUnk_03001800.unkAA++;
}

void sub_0802A440(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            gSpriteEntries[0x23 + i].unk18 = (gSpriteEntries[0x23 + i].unk18 + 0x20) & 0x3FF;
            if (move_sprite_toward_target(0x23 + i))
                done++;
        }
    }
    if (count == done) {
        play_sound_effect(0x2B);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802A4C4(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            gSpriteEntries[0x23 + i].unk18 = (gSpriteEntries[0x23 + i].unk18 + 0x20) & 0x3FF;
            gSpriteEntries[0x23 + i].unk8 -= 4;
            gSpriteEntries[0x23 + i].unk9 -= 4;
            if (gSpriteEntries[0x23 + i].unk9 == 4)
                done = 1;
        }
    }
    if (done) {
        clear_battle_sprite_slot(0x24, 3);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802A534(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            calc_head_uses_given(gUnk_03001800.unk60 + i, gUnk_03001800.unkEC);
            gUnk_03001800.unkD6[i] = gUnk_03001800.unkC8;
            add_u8_capped(&gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk10, gUnk_03001800.unkD6[i],
                          gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].data[8]);
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0802A5C0(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084D6BFC, (void *)0x06017E00);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        switch (i) {
        case 0:
            set_display_digit_type(gUnk_03000440.unk9E, gUnk_03001800.unkD6[i], 0);
            battle_text_popup_init_slot(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
            break;
        case 1:
            set_display_digit_type(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkD6[1], 0);
            battle_text_popup_init_slot(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
            break;
        case 2:
            set_display_digit_type(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unkD6[2], 0);
            battle_text_popup_init_slot(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
            break;
        }
    }
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_0802A694(void) {
    gUnk_03001800.unkA6 = 0x54;
    gUnk_03001800.unkAA++;
}

void sub_0802A6AC(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE640[gUnk_03001800.unkAA]();
}

void sub_0802A6D4(void) {
    lz_decompress_dispatch(gUnk_084DED1C, (void *)0x06014800);
    CpuFastSet(gUnk_0850ED58, (void *)0x050002E0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk8 = 4;
    gSpriteEntries[0x21].unk9 = 4;
    gSpriteEntries[0x21].unk18 = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x62], 0x21);
    if (!(gUnk_03001800.unkF8 & 1)) {
        gSpriteEntries[0x21].unk2 = 0x70;
    } else {
        gSpriteEntries[0x21].unk0 |= 0x1000;
        gSpriteEntries[0x21].unk2 = 0x80;
    }
    play_sound_effect(0x6A);
    gUnk_03001800.unkAA++;
}

void sub_0802A7E0(void) {
    if (gSpriteEntries[0x21].unk8 == 0x40) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 += 4;
        gSpriteEntries[0x21].unk9 += 4;
    }
}

void sub_0802A824(void) {
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            continue;
        gUnk_03000590[gUnk_03001800.unk60 + i].unkBD |= 4;
        gUnk_03001800.unkD2[i] = 1;
        sub_080385D0(gUnk_03001800.unk60 + i);
        gUnk_03000590[gUnk_03001800.unk60 + i].unkD7 = 0;
        gUnk_03000590[gUnk_03001800.unk60 + i].unkBB = 0x14;
        gUnk_03000590[gUnk_03001800.unk60 + i].unkDA = 0;
        gSpriteEntries[0x22 + i].unk0 = 0xC404;
        gSpriteEntries[0x22 + i].unk1C = 0;
        gSpriteEntries[0x22 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x22 + i].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 0x10;
        gSpriteEntries[0x22 + i].unkA = 7;
        gSpriteEntries[0x22 + i].unkB = 0xE0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x63], 0x22 + i);
        if (gUnk_03001800.unkF8 & 1)
            gSpriteEntries[0x22 + i].unk0 |= 0x1000;
    }
    iterate_bots_setup_battle_sprites();
    gUnk_03000440.unk86 = 0;
    gSpriteEntries[0x21].unk0 &= 0xFDFF;
    gSpriteEntries[0x2B].unk29 = 1;
    gSpriteEntries[0x2B].unk2 = gSpriteEntries[0x21].unk2;
    gSpriteEntries[0x2B].unk4 = gSpriteEntries[0x21].unk4;
    battle_queue_sort();
    gUnk_03001800.unkAA++;
}

void sub_0802A9B8(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        count++;
        sub_08019544(gUnk_03001800.unk60 + i);
        if (sub_08019440(gUnk_03001800.unk60 + i))
            done++;
        process_sprite_anim_commands(gUnk_083B5F80[0x63], 0x22 + i);
        gSpriteEntries[0x22 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x22 + i].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 0x10;
        init_battle_sprite_entry_0801BC04(gUnk_03001800.unk60 + i);
    }
    process_sprite_anim_commands(gUnk_083B5F80[0x62], 0x21);
    if (!(gUnk_03000440.unk86 & 0x3F))
        play_sound_effect(0x33);
    gUnk_03000440.unk86++;
    sub_080383E8();
    if (done == count && gUnk_03000440.unk86 > 0x3C) {
        clear_battle_sprite_slot(0x21, 0x1B);
        iterate_bots_setup_battle_sprites();
        gUnk_03001800.unkAA++;
    }
}

void sub_0802AAB8(void) {
    gUnk_03001800.unkA6 = 0x65;
    gUnk_03001800.unkAA++;
}

void sub_0802AAD0(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE680[gUnk_03001800.unkAA]();
}

void sub_0802AAF8(void) {
    lz_decompress_dispatch(gUnk_084DF024, (void *)0x06014800);
    CpuFastSet(gUnk_0850ED78, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = -0x39DC;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x20;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = -0x10;
    gSpriteEntries[0x21].unk8 = 0x80;
    gSpriteEntries[0x21].unk9 = 0x80;
    gSpriteEntries[0x21].unk2B = 0x1C;
    gSpriteEntries[0x21].unk2C = 0;
    gSpriteEntries[0x21].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1C], 0x21);
    gSpriteEntries[0x22].unk0 = -0x39DC;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x20;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = -0x10;
    gSpriteEntries[0x22].unk8 = 0x80;
    gSpriteEntries[0x22].unk9 = 0x80;
    gSpriteEntries[0x22].unk2B = 0x1C;
    gSpriteEntries[0x22].unk2C = 0x80;
    gSpriteEntries[0x22].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1C], 0x22);
    play_sound_effect(0x33);
    gUnk_03001800.unkAA++;
}

void sub_0802AC7C(void) {
    add_u8_capped(&gUnk_03000590[gUnk_03001800.unk87].unkD0 + 1, gUnk_03001800.unkEC, 0xFF);
    gUnk_03001800.unkAA++;
}

void sub_0802ACB4(void) {
    gUnk_03001800.unkA6 = 0x45;
    gUnk_03001800.unkAA++;
}

void sub_0802ACCC(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE6C0[gUnk_03001800.unkAA]();
}

void sub_0802ACF4(void) {
    lz_decompress_dispatch(gUnk_084DF400, (void *)0x06014800);
    CpuFastSet(gUnk_0850ED98, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = -0x39DC;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x20;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk8 = 0x80;
    gSpriteEntries[0x21].unk9 = 0x80;
    gSpriteEntries[0x21].unk2B = 0x1C;
    gSpriteEntries[0x21].unk2C = 0;
    gSpriteEntries[0x21].unk2D = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x64], 0x21);
    gSpriteEntries[0x22].unk0 = -0x39DC;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x20;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = 0xF0;
    gSpriteEntries[0x22].unk8 = 0x80;
    gSpriteEntries[0x22].unk9 = 0x80;
    gSpriteEntries[0x22].unk6 = 0x7901;
    gSpriteEntries[0x22].unk2B = 0x1C;
    gSpriteEntries[0x22].unk2C = 0x80;
    gSpriteEntries[0x22].unk2D = 0;
    play_sound_effect(0x33);
    gUnk_03001800.unkAA++;
}

void sub_0802AE88(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x64], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802AECC(void) {
    gSpriteEntries[0x21].unk0 = 0xCC04;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x65], 0x21);
    play_sound_effect(0x71);
    gUnk_03001800.unkAA++;
}

void sub_0802AF6C(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x65], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802AFB0(void) {
    add_u8_capped(&gUnk_03000590[gUnk_03001800.unk87].unkD0, gUnk_03001800.unkEC, 0xFF);
    gUnk_03001800.unkAA++;
}

void sub_0802AFE8(void) {
    gUnk_03001800.unkA6 = 0x44;
    gUnk_03001800.unkAA++;
}

void sub_0802B000(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE700[gUnk_03001800.unkAA]();
}

void sub_0802B028(void) {
    lz_decompress_dispatch(gUnk_084DFA88, (void *)0x06014800);
    CpuFastSet(gUnk_0850EDB8, (void *)0x050002C0, 0x10);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk6 = 0x7A00;
    gSpriteEntries[0x22].unk0 = 0xC404;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = 0xE0;
    gSpriteEntries[0x22].unk2D = 0;
    if (gUnk_03000590[gUnk_03001800.unk87].unkA8[0] == 0x1E)
        gSpriteEntries[0x22].unk6 = 0x7A01;
    else
        gSpriteEntries[0x22].unk6 = 0x7A02;
    play_sound_effect(0x4C);
    gUnk_03001800.unkAA++;
}

void sub_0802B184(void) {
    u32 i;
    u32 found = 0;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 == 0 ||
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0 ||
            battle_bot_lacks_stability(gUnk_03001800.unk60 + i) == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk87].unkA8[0] == 0x1E) {
            if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].data[1] == 0x64) {
                gUnk_03001800.unkD2[i] = 1;
                found = 1;
            }
        } else if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].data[1] == 0x6A) {
            gUnk_03001800.unkD2[i] = 2;
            found = 1;
        }
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 2;
}

void sub_0802B258(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084DFBD4, (void *)0x06014800);
    CpuFastSet(gUnk_0850EDF8, (void *)0x050002C0, 0x10);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].unk0 = 0xC404;
        gSpriteEntries[i + 0x21].unk1C = 0;
        gSpriteEntries[i + 0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
        gSpriteEntries[i + 0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[i + 0x21].unk30 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[i + 0x21].unk32 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[i + 0x21].unk24 = 6;
        gSpriteEntries[i + 0x21].unk23 = 0;
        gSpriteEntries[i + 0x21].unkB = 0xF0;
        if (gUnk_03001800.unkF8 & 1)
            gSpriteEntries[i + 0x21].unk0 |= 0x1000;
        if (gUnk_03001800.unkD2[i] == 1) {
            gSpriteEntries[i + 0x21].unkA = 6;
            gSpriteEntries[i + 0x21].unk6 = 0x7B00;
        } else {
            gSpriteEntries[i + 0x21].unkA = 7;
            gSpriteEntries[i + 0x21].unk6 = 0x7B01;
        }
    }
    play_sound_effect(0x24);
    gUnk_03001800.unkAA++;
}

void sub_0802B388(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        count++;
        if (move_sprite_toward_target(i + 0x21))
            done++;
    }
    if (done == count)
        gUnk_03001800.unkAA++;
}

void sub_0802B3CC(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084DCF54, (void *)0x06016000);
    CpuFastSet(gUnk_0850EC58, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].unkA = 7;
        gSpriteEntries[i + 0x21].unk0 &= 0xEFFF;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x66], i + 0x21);
    }
    gUnk_03001800.unkAA++;
}

void sub_0802B460(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        process_sprite_anim_commands(gUnk_083B5F80[0x66], i + 0x21);
        if (gSpriteEntries[i + 0x21].unk22 == 0xFF)
            done = 1;
    }
    if (done)
        gUnk_03001800.unkAA++;
}

void sub_0802B4D8(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03001800.unkD6[i] = rng_next_byte() & 7;
        switch (gUnk_03001800.unkD6[i]) {
        case 0:
            if (sub_08036D64(gUnk_03001800.unk60 + i, 0xD))
                gUnk_03001800.unkD6[i] = 5;
            break;
        case 1:
            if (sub_08036D64(gUnk_03001800.unk60 + i, 0x11))
                gUnk_03001800.unkD6[i] = 5;
            break;
        case 2:
            if (sub_08036D64(gUnk_03001800.unk60 + i, 0x13))
                gUnk_03001800.unkD6[i] = 5;
            break;
        case 3:
            if (sub_08036D64(gUnk_03001800.unk60 + i, 0x10))
                gUnk_03001800.unkD6[i] = 5;
            break;
        }
        gSpriteEntries[i + 0x21].unk6 = 0x6F00 + gUnk_03001800.unkD6[i];
        gSpriteEntries[i + 0x21].unk23 = 0;
    }
    play_sound_effect(0x5B);
    gUnk_03001800.unkAA++;
}

void sub_0802B5AC(void) {
    u32 i;

    clear_battle_sprite_slot(0x21, 3);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        switch (gUnk_03001800.unkD6[i]) {
        case 0:
            battle_set_action_params(gUnk_03001800.unk60 + i, 0xD, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            break;
        case 1:
            battle_set_action_params(gUnk_03001800.unk60 + i, 0x11, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            break;
        case 2:
            battle_set_action_params(gUnk_03001800.unk60 + i, 0x13, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            break;
        case 3:
            battle_set_action_params(gUnk_03001800.unk60 + i, 0x10, gUnk_03001800.unkE8, gUnk_03001800.unkEC);
            break;
        case 4:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 = 0x2B;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCB = clamp_1_99(gUnk_03001800.unkE8);
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCC = clamp_1_99(gUnk_03001800.unkEC);
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 1;
            break;
        case 5:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 = 0x2C;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 0;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCB = clamp_1_99(gUnk_03001800.unkE8);
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCC = clamp_1_99(gUnk_03001800.unkEC);
            break;
        case 6:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 = 0x2E;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 0;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCB = clamp_1_99(gUnk_03001800.unkE8);
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCC = clamp_1_99(gUnk_03001800.unkEC);
            break;
        case 7:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 = 0x2F;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 0;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCB = clamp_1_99(gUnk_03001800.unkE8);
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCC = clamp_1_99(gUnk_03001800.unkEC);
            break;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0802B7AC(void) {
    if (gUnk_03000590[gUnk_03001800.unk87].unkA8[0] == 0x1E)
        gUnk_03001800.unkA6 = 0x4D;
    else
        gUnk_03001800.unkA6 = 0x4E;
    gUnk_03001800.unkAA++;
}

void sub_0802B7E8(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE750[gUnk_03001800.unkAA]();
}

void sub_0802B810(void) {
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 != 0 &&
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 != 0)
            gUnk_03001800.unkD2[i] = 1;
    }
    switch (gUnk_03000590[gUnk_03001800.unk87].unkA8[0]) {
    case 0x1F:
        gUnk_03001800.unk51 = 0;
        break;
    case 0x21:
        gUnk_03001800.unk51 = 1;
        break;
    case 0x23:
        gUnk_03001800.unk51 = 2;
        break;
    case 0x25:
        gUnk_03001800.unk51 = 3;
        break;
    }
    gUnk_03001800.unkAA++;
}

void sub_0802B8BC(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084DFC18, (void *)0x06014800);
    CpuFastSet(gUnk_0850EE38, (void *)0x050002C0, 0x10);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].unk0 = 0xC404;
        gSpriteEntries[i + 0x21].unk1C = 0;
        gSpriteEntries[i + 0x21].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[i + 0x21].unk4 = 0xF0;
        gSpriteEntries[i + 0x21].unkA = 6;
        gSpriteEntries[i + 0x21].unkB = 0xF0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x67], i + 0x21);
    }
    play_sound_effect(0x2C);
    gUnk_03001800.unkAA++;
}

void sub_0802B980(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        count++;
        process_sprite_anim_commands(gUnk_083B5F80[0x67], i + 0x21);
        if (gSpriteEntries[i + 0x21].unk4 == gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4)
            done++;
        else
            gSpriteEntries[i + 0x21].unk4 = (gSpriteEntries[i + 0x21].unk4 + 1) & 0xFF;
    }
    if (done == count)
        gUnk_03001800.unkAA++;
}

void sub_0802BA2C(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].unk0 = 0xCC04;
        gSpriteEntries[i + 0x21].unkB = 0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x68], i + 0x21);
    }
    play_sound_effect(0x30);
    gUnk_03001800.unkAA++;
}

void sub_0802BAAC(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        process_sprite_anim_commands(gUnk_083B5F80[0x68], i + 0x21);
        if (gSpriteEntries[i + 0x21].unk22 == 0xFF)
            done = 1;
    }
    if (done)
        gUnk_03001800.unkAA++;
}

void sub_0802BB24(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].unk0 = 0xC404;
        gSpriteEntries[i + 0x21].unkB = 0xE0;
        gSpriteEntries[i + 0x21].unk4 += 8;
        gSpriteEntries[i + 0x21].unkA = 7;
        gSpriteEntries[i + 0x21].unk6 = 0x7C04 + gUnk_03001800.unk51;
    }
    gUnk_03000440.unk86 = 0;
    play_sound_effect(0x2E);
    gUnk_03001800.unkAA++;
}

void sub_0802BBA8(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] != 0 && !(gUnk_03000440.unk86 & 1))
            gSpriteEntries[i + 0x21].unk4--;
    }
    if (++gUnk_03000440.unk86 == 0x20) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802BC1C(void) {
    u32 i;

    clear_battle_sprite_slot(0x21, 3);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] != 0)
            gUnk_03001800.unkD6[i] = gUnk_03001800.unkEC;
    }
    gUnk_03001800.unkAA++;
}

void sub_0802BC60(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        switch (gUnk_03001800.unk51) {
        case 0:
            add_u8_capped(&gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].data[5], gUnk_03001800.unkEC, 0xFF);
            break;
        case 1:
            add_u8_capped(&gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].data[6], gUnk_03001800.unkEC, 0xFF);
            break;
        case 2:
            add_u8_capped(&gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].data[8], gUnk_03001800.unkEC, 0xFF);
            break;
        case 3:
            add_u8_capped(&gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].data[9], gUnk_03001800.unkEC, 0xFF);
            break;
        }
        sub_08035194(gUnk_03001800.unk60 + i);
        sub_080351E8(gUnk_03001800.unk60 + i);
    }
    gUnk_03001800.unkAA++;
}

void sub_0802BD1C(void) {
    switch (gUnk_03001800.unk51) {
    case 0:
        gUnk_03001800.unkA6 = 0x3D;
        break;
    case 1:
        gUnk_03001800.unkA6 = 0x3E;
        break;
    case 2:
        gUnk_03001800.unkA6 = 0x40;
        break;
    case 3:
        gUnk_03001800.unkA6 = 0x41;
        break;
    }
    gUnk_03001800.unkAA++;
}

void sub_0802BD6C(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE790[gUnk_03001800.unkAA]();
}

void sub_0802BD94(void) {
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = 0x78;
    gSpriteEntries[0x21].unk4 = 0x40;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk6 = 0x4800;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk2D = 0;
    gSpriteEntries[0x21].unk2E = 1;
    gUnk_03000440.unk86 = 0;
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_0802BE44(void) {
    u32 v;

    if (gUnk_03000440.unk84 <= 2) {
        if (gUnk_03000440.unk86 == 0) {
            gUnk_03000440.unk84++;
            play_sound_effect(0x4C);
        }
        if (++gUnk_03000440.unk86 == gUnk_083AE7D0[gUnk_03000440.unk84 - 1])
            gUnk_03000440.unk86 = 0;
    }
    if (gSpriteEntries[0x21].unk18 == 0)
        gSpriteEntries[0x21].unk2E++;
    v = (u16)(gSpriteEntries[0x21].unk2E * 16 + gSpriteEntries[0x21].unk18) & 0x3FF;
    gSpriteEntries[0x21].unk18 = v;
    if (gSpriteEntries[0x21].unk2E == 5 && v == 0) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802BEEC(void) {
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 != 0 &&
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 != 0)
            gUnk_03001800.unkD2[i] = 1;
    }
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 != 0 &&
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 != 0)
            gUnk_03001800.unkD6[i] = 1;
    }
    gUnk_03001800.unkAA++;
}

void sub_0802BF9C(void) {
    u32 i;

    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].unk0 = 0xC624;
        gSpriteEntries[i + 0x21].unk1C = 0;
        gSpriteEntries[i + 0x21].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[i + 0x21].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4;
        gSpriteEntries[i + 0x21].unkA = 7;
        gSpriteEntries[i + 0x21].unkB = 0xF0;
        gSpriteEntries[i + 0x21].unk8 = 0x40;
        gSpriteEntries[i + 0x21].unk9 = 0x40;
        gSpriteEntries[i + 0x21].unk6 = 0x4801;
    }
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD6[i] == 0)
            continue;
        gSpriteEntries[i + 0x24].unk0 = 0xC624;
        gSpriteEntries[i + 0x24].unk1C = 0;
        gSpriteEntries[i + 0x24].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[i + 0x24].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 0x10;
        gSpriteEntries[i + 0x24].unkA = 7;
        gSpriteEntries[i + 0x24].unkB = 0xF0;
        gSpriteEntries[i + 0x24].unk8 = 0x40;
        gSpriteEntries[i + 0x24].unk9 = 0x40;
        gSpriteEntries[i + 0x24].unk6 = 0x4802;
    }
    gUnk_03000440.unk84 = 0;
    play_sound_effect(0x2E);
    gUnk_03001800.unkAA++;
}

void sub_0802C0DC(void) {
    u32 i;

    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] != 0 && !(gUnk_03000440.unk84 & 1))
            gSpriteEntries[i + 0x21].unk4--;
    }
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD6[i] != 0 && !(gUnk_03000440.unk84 & 1))
            gSpriteEntries[i + 0x24].unk4++;
    }
    if (gUnk_03000440.unk84 == 0x20) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    } else
        gUnk_03000440.unk84++;
}

void sub_0802C1A4(void) {
    u32 i;

    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] != 0) {
            gSpriteEntries[i + 0x21].unk8 -= 8;
            gSpriteEntries[i + 0x21].unk9 += 8;
        }
    }
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD6[i] != 0) {
            gSpriteEntries[i + 0x24].unk8 -= 8;
            gSpriteEntries[i + 0x24].unk9 += 8;
        }
    }
    if (gSpriteEntries[0x21].unk8 == 8) {
        clear_battle_sprite_slot(0x21, 6);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802C24C(void) {
    add_u8_capped(&gUnk_03001800.unk28[gUnk_03001800.unk89].unk0, gUnk_03001800.unkEC, 0xA0);
    subtract_u8_floored(&gUnk_03001800.unk28[gUnk_03001800.unk8A].unk0, gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void sub_0802C294(void) {
    gUnk_03001800.unkA6 = 0x5B;
    gUnk_03001800.unkAA++;
}

void sub_0802C2AC(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE7D4[gUnk_03001800.unkAA]();
}

void sub_0802C2D4(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084D5EBC, (void *)0x06014800);
    CpuFastSet(gUnk_0850E7B8, (void *)0x050002E0, 8);
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].unk0 = 0xC404;
        gSpriteEntries[i + 0x21].unk1C = 0;
        gSpriteEntries[i + 0x21].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[i + 0x21].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[i + 0x21].unkA = 7;
        gSpriteEntries[i + 0x21].unkB = 0xF0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x40], i + 0x21);
    }
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD6[i] == 0)
            continue;
        gSpriteEntries[i + 0x24].unk0 = 0xC404;
        gSpriteEntries[i + 0x24].unk1C = 0;
        gSpriteEntries[i + 0x24].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[i + 0x24].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[i + 0x24].unkA = 7;
        gSpriteEntries[i + 0x24].unkB = 0xF0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x41], i + 0x24);
    }
    play_sound_effect(0x4D);
    gUnk_03001800.unkAA++;
}

void sub_0802C440(void) {
    u32 i;

    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] != 0)
            process_sprite_anim_commands(gUnk_083B5F80[0x40], i + 0x21);
    }
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD6[i] != 0)
            process_sprite_anim_commands(gUnk_083B5F80[0x41], i + 0x24);
    }
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 6);
        gUnk_03000440.unk84 = 0;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802C4F8(void) {
    u32 i;

    gUnk_03000440.unk84++;
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] != 0)
            battle_bot_sprites_blink(gUnk_03001800.unk60 + i, gUnk_03000440.unk84, 2);
    }
    if (gUnk_03000440.unk84 == 0x3C) {
        for (i = 0; i <= 2; i++) {
            if (gUnk_03001800.unkD2[i] != 0)
                battle_bot_sprites_show(gUnk_03001800.unk60 + i);
        }
        gUnk_03001800.unkAA++;
    }
}

void sub_0802C588(void) {
    u32 i;

    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] != 0)
            add_u8_capped(&gUnk_03000590[gUnk_03001800.unk60 + i].unkB8 + 1, gUnk_03001800.unkEC, 0x78);
    }
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD6[i] != 0)
            subtract_u8_floored(&gUnk_03000590[gUnk_03001800.unk60 + i].unkB8 + 1, gUnk_03001800.unkEC);
    }
    gUnk_03001800.unkAA++;
}

void sub_0802C62C(void) {
    gUnk_03001800.unkA6 = 0x5C;
    gUnk_03001800.unkAA++;
}

void sub_0802C644(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE814[gUnk_03001800.unkAA]();
}

void sub_0802C66C(void) {
    lz_decompress_dispatch(gUnk_084DFFE4, (void *)0x06014800);
    CpuFastSet(gUnk_0850EE78, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = 0x78;
    gSpriteEntries[0x21].unk4 = 0x40;
    gSpriteEntries[0x21].unk8 = 4;
    gSpriteEntries[0x21].unk9 = 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk6 = 0x7D00;
    play_sound_effect(0x6E);
    gUnk_03001800.unkAA++;
}

void sub_0802C714(void) {
    if (gSpriteEntries[0x21].unk8 == 0x40) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 += 4;
        gSpriteEntries[0x21].unk9 += 4;
    }
}

void sub_0802C758(void) {
    if (gSpriteEntries[0x21].unk8 == 0x20) {
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 4;
        gSpriteEntries[0x21].unk9 -= 4;
    }
}

void sub_0802C790(void) {
    u32 i;
    u32 found = 0;

    sub_0803836C();
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 != 0 &&
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 != 0 &&
            battle_bot_lacks_stability(gUnk_03001800.unk60 + i) != 0) {
            gUnk_03001800.unkD2[i] = 1;
            found = 1;
        }
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 3;
}

void sub_0802C820(void) {
    if (gSpriteEntries[0x21].unk8 == 4) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 4;
        gSpriteEntries[0x21].unk9 -= 4;
    }
}

void sub_0802C864(void) {
    u32 i;

    clear_battle_sprite_slot(0x21, 1);
    lz_decompress_dispatch(gUnk_084D6098, (void *)0x06014800);
    CpuFastSet(gUnk_0850E7D8, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[i + 0x21].unk0 = 0xC624;
        gSpriteEntries[i + 0x21].unk1C = 0;
        gSpriteEntries[i + 0x21].unk2 = 0x78;
        gSpriteEntries[i + 0x21].unk4 = 0x40;
        gSpriteEntries[i + 0x21].unkA = 7;
        gSpriteEntries[i + 0x21].unkB = 0xF0;
        gSpriteEntries[i + 0x21].unk8 = 0x40;
        gSpriteEntries[i + 0x21].unk9 = 0x40;
        gSpriteEntries[i + 0x21].unk18 = 0;
        gSpriteEntries[i + 0x21].unk30 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[i + 0x21].unk32 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[i + 0x21].unk24 = 6;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x42], i + 0x21);
    }
    gUnk_03001800.unkAA++;
}

void sub_0802C960(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        count++;
        process_sprite_anim_commands(gUnk_083B5F80[0x42], i + 0x21);
        if (!(gUnk_03001800.unkF8 & 1))
            gSpriteEntries[i + 0x21].unk18 = (u16)(gSpriteEntries[i + 0x21].unk18 - 0x40) & 0x3FF;
        else
            gSpriteEntries[i + 0x21].unk18 = (u16)(gSpriteEntries[i + 0x21].unk18 + 0x40) & 0x3FF;
        if (move_sprite_toward_target(i + 0x21))
            done++;
    }
    if (done == count) {
        gSpriteEntries[0x21].unk18 = 0;
        gSpriteEntries[0x22].unk18 = 0;
        gSpriteEntries[0x23].unk18 = 0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x43], 0x21);
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x43], 0x22);
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x43], 0x23);
        play_sound_effect(0x4E);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802CA5C(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            process_sprite_anim_commands(gUnk_083B5F80[0x43], 0x21 + i);
            if (gSpriteEntries[0x21 + i].unk22 == 0xFF)
                done = 1;
        }
    }
    if (done)
        gUnk_03001800.unkAA++;
}

void sub_0802CAD4(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            gSpriteEntries[0x21 + i].unk8 -= 4;
            gSpriteEntries[0x21 + i].unk9 -= 4;
            if (gSpriteEntries[0x21 + i].unk8 == 4)
                done = 1;
        }
    }
    if (done) {
        clear_battle_sprite_slot(0x21, 3);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802CB34(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC4 = 0x26;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC5 = 0;
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC6 = clamp_1_99(gUnk_03001800.unkE8);
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC7 = clamp_1_99(gUnk_03001800.unkEC);
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0802CBD0(void) {
    gUnk_03001800.unkA6 = 0x59;
    gUnk_03001800.unkAA++;
}

void sub_0802CBE8(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE854[gUnk_03001800.unkAA]();
}

void sub_0802CC10(void) {
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11)
            gUnk_03001800.unkD2[i] = 1;
    }
    gUnk_03001800.unkAA++;
}

void sub_0802CC74(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084D6464, (void *)0x06014800);
    CpuFastSet(gUnk_0850E838, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk0 = 0xC624;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = 0x78;
        gSpriteEntries[0x21 + i].unk4 = 0xF0;
        gSpriteEntries[0x21 + i].unk8 = 0x40;
        gSpriteEntries[0x21 + i].unk9 = 0x40;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        gSpriteEntries[0x21 + i].unk6 = 0x4D00;
        gSpriteEntries[0x21 + i].unk24 = 4;
        gSpriteEntries[0x21 + i].unk25 = 0;
        gSpriteEntries[0x21 + i].unk30 = 0;
        if (gUnk_03001800.unkF8 & 1)
            gSpriteEntries[0x21 + i].unk0 |= 0x1000;
    }
    play_sound_effect(0x61);
    gUnk_03001800.unkAA++;
}

void sub_0802CD48(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            if (sprite_move_toward_target(0x21 + i, gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4,
                                          gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 + 0x10)) {
                gSpriteEntries[0x21 + i].unk30 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
                gSpriteEntries[0x21 + i].unk32 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
                gSpriteEntries[0x21 + i].unk24 = 6;
                done++;
            }
        }
    }
    if (done == count) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802CE08(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            if (move_sprite_toward_target(0x21 + i))
                done++;
        }
    }
    if (done == count)
        gUnk_03001800.unkAA++;
}

void sub_0802CE4C(void) {
    u32 i;
    u32 j;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk23 = 0;
        memcpy_bytes_0803F63C(&gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5A],
                              &gSpriteEntries[(j = i * 4) + 0x24], 0x40);
        memcpy_bytes_0803F63C(&gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5B], &gSpriteEntries[j + 0x25], 0x40);
        memcpy_bytes_0803F63C(&gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5C], &gSpriteEntries[j + 0x26], 0x40);
        memcpy_bytes_0803F63C(&gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D], &gSpriteEntries[j + 0x27], 0x40);
        clear_sprite_table_mask(j + 0x24, 4);
        gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5A].unk23 = 0;
        gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5B].unk23 = 0;
        gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5C].unk23 = 0;
        gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk23 = 0;
        sub_08035694(gUnk_03001800.unk60 + 0x72 + i);
    }
    play_sound_effect(0x34);
    gUnk_03001800.unkAA++;
}

void sub_0802CFAC(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i, j;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        count++;
        if (gSpriteEntries[0x21 + i].unk0 & 0x8000) {
            if (advance_sprite_anim_frame(0x21 + i, 0))
                clear_battle_sprite_slot(0x21 + i, 1);
            else if (!(gUnk_03001800.unkF8 & 1)) {
                gSpriteEntries[0x21 + i].unk2--;
                gSpriteEntries[0x21 + i].unk18 = (gSpriteEntries[0x21 + i].unk18 - 0x10) & 0x3FF;
            } else {
                gSpriteEntries[0x21 + i].unk2++;
                gSpriteEntries[0x21 + i].unk18 = (gSpriteEntries[0x21 + i].unk18 + 0x10) & 0x3FF;
            }
        }
        sprite_hop_step((gUnk_03001800.unk60 + i) * 4 + 0x5A);
        sprite_hop_step((gUnk_03001800.unk60 + i) * 4 + 0x5B);
        sprite_hop_step((gUnk_03001800.unk60 + i) * 4 + 0x5C);
        done += sprite_hop_step((gUnk_03001800.unk60 + i) * 4 + 0x5D);
        if (gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk23 == 0x10) {
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5A].unk4 += 8;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5B].unk4 -= 8;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5C].unk4 -= 8;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 -= 8;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5A].unk0 |= 0x2000;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5B].unk0 |= 0x2000;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5C].unk0 |= 0x2000;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk0 |= 0x2000;
        }
        check_sprite_overlap_and_adjust((gUnk_03001800.unk60 + i) * 4 + 0x5D, gUnk_03001800.unk60 + (j = i + 0x72));
    }
    if (done == count) {
        for (i = 0; i <= 2; i++) {
            if (gUnk_03001800.unkD2[i])
                sub_080356B4((j = i + 0x72) + gUnk_03001800.unk60);
        }
        play_sound_effect(0x41);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802D198(void) {
    u32 i, j;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        for (j = 0; j < 4; j++) {
            gSpriteEntries[0x30 + j + i * 4].unk0 = 0xC404;
            gSpriteEntries[0x30 + j + i * 4].unk1C = 0;
            gSpriteEntries[0x30 + j + i * 4].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5A].unk2;
            gSpriteEntries[0x30 + j + i * 4].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5A].unk4 + 4;
            gSpriteEntries[0x30 + j + i * 4].unkA = 7;
            gSpriteEntries[0x30 + j + i * 4].unkB = 0xF0;
            gSpriteEntries[0x30 + j + i * 4].unk24 = 6;
            gSpriteEntries[0x30 + j + i * 4].unk25 = gBurstSpriteDirections[j];
            gSpriteEntries[0x30 + j + i * 4].unk6 = 0x4D01;
        }
    }
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_0802D270(void) {
    u32 i, j;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        for (j = 0; j < 4; j++)
            update_sprite_animation_position(0x30 + j + i * 4);
    }
    if (gUnk_03000440.unk84 == 0x10) {
        for (i = 0; i <= 2; i++) {
            if (gUnk_03001800.unkD2[i] == 0)
                continue;
            memcpy_bytes_0803F63C(&gSpriteEntries[0x24 + i * 4], &gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5A],
                                  0x40);
            memcpy_bytes_0803F63C(&gSpriteEntries[0x25 + i * 4], &gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5B],
                                  0x40);
            memcpy_bytes_0803F63C(&gSpriteEntries[0x26 + i * 4], &gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5C],
                                  0x40);
            memcpy_bytes_0803F63C(&gSpriteEntries[0x27 + i * 4], &gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D],
                                  0x40);
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5A].unk0 |= 0x8000;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5B].unk0 |= 0x8000;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5C].unk0 |= 0x8000;
            gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk0 |= 0x8000;
        }
        clear_battle_sprite_slot(0x21, 0x1B);
        gUnk_03001800.unkAA++;
    } else
        gUnk_03000440.unk84++;
}

void apply_battle_damage_and_render(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unkBD & 4)
            battle_set_damage_vs_armor(gUnk_03001800.unk60 + i, 0, 1);
        else
            battle_set_damage_vs_armor(gUnk_03001800.unk60 + i, 0, gUnk_03001800.unkEC);
        gUnk_03001800.unkD6[i] = gUnk_03001800.unkC8;
        switch (i) {
        case 0:
            set_display_digit_type(gUnk_03000440.unk9E, gUnk_03001800.unkC8, 1);
            battle_number_popup_init_slot(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
            break;
        case 1:
            set_display_digit_type(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkC8, 1);
            battle_number_popup_init_slot(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
            break;
        case 2:
            set_display_digit_type(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unkC8, 1);
            battle_number_popup_init_slot(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
            break;
        }
    }
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_0802D4D8(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            switch (i) {
            case 0:
                battle_popup_update_slot(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
                break;
            case 1:
                battle_popup_update_slot(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
                break;
            case 2:
                battle_popup_update_slot(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
                break;
            }
        }
    }
    gUnk_03000440.unk84++;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1) && gUnk_03000440.unk84 > 0x32)
        gUnk_03000440.unk84 = 0x78;
    if (gUnk_03000440.unk84 == 0x78) {
        for (i = 0; i <= 2; i++) {
            if (gUnk_03001800.unkD2[i])
                clear_battle_sprite_slot((gUnk_03001800.unk60 + i) * 4 + 0x21, 4);
        }
        gUnk_03001800.unkAA++;
    }
}

void apply_battle_damage_to_team(void) {
    u32 defeated = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        reduce_bot_part_stat(gUnk_03001800.unk60 + i, 0, gUnk_03001800.unkD6[i]);
        if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0) {
            add_bot_to_defeated_list(gUnk_03001800.unk60 + i);
            gUnk_03001800.unkD2[i] = 0x80;
            defeated = 1;
        } else if (!(gUnk_03000590[gUnk_03001800.unk60 + i].unkBD & 4))
            gUnk_03000590[gUnk_03001800.unk60 + i].unkBD |= 1;
    }
    if (defeated)
        gUnk_03001800.unkAA = 0x10;
    else
        gUnk_03001800.unkAA++;
}

void sub_0802D670(void) {
    gUnk_03001800.unkA6 = 0x42;
    gUnk_03001800.unkAA++;
}

void sub_0802D688(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE8B0[gUnk_03001800.unkAA]();
}

void sub_0802D6B0(void) {
    lz_decompress_dispatch(gUnk_084E0360, (void *)0x06014800);
    CpuFastSet(gUnk_0850EE98, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC604;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = 0x78;
    gSpriteEntries[0x21].unk4 = 0x40;
    gSpriteEntries[0x21].unk8 = 4;
    gSpriteEntries[0x21].unk9 = 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk6 = 0x7E00;
    play_sound_effect(0x6E);
    gUnk_03001800.unkAA++;
}

void sub_0802D758(void) {
    u32 found = 0;
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 &&
            battle_bot_lacks_stability(gUnk_03001800.unk60 + i)) {
            gUnk_03001800.unkD2[i] = (s8)battle_find_next_active_bot(gUnk_03001800.unk60 + i) - 0x80;
            found = 1;
        }
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 3;
}

void sub_0802D7EC(void) {
    u32 i;

    clear_battle_sprite_slot(0x21, 1);
    lz_decompress_dispatch(gUnk_084D651C, (void *)0x06014800);
    CpuFastSet(gUnk_0850E858, (void *)0x050002E0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk0 = 0xC624;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = 0x78;
        gSpriteEntries[0x21 + i].unk4 = 0x40;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        gSpriteEntries[0x21 + i].unk8 = 0x40;
        gSpriteEntries[0x21 + i].unk9 = 0x40;
        gSpriteEntries[0x21 + i].unk18 = 0;
        gSpriteEntries[0x21 + i].unk30 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk32 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unk24 = 6;
        gSpriteEntries[0x21 + i].unk6 = 0x4E00;
    }
    gUnk_03001800.unkAA++;
}

void sub_0802D8D0(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            if (!(gUnk_03001800.unkF8 & 1))
                gSpriteEntries[0x21 + i].unk18 = (gSpriteEntries[0x21 + i].unk18 - 0x40) & 0x3FF;
            else
                gSpriteEntries[0x21 + i].unk18 = (gSpriteEntries[0x21 + i].unk18 + 0x40) & 0x3FF;
            if (move_sprite_toward_target(0x21 + i))
                done++;
        }
    }
    if (done == count) {
        struct SpriteEntry *spr;
        s16 *p;

        for (i = 0, spr = gSpriteEntries; i <= 2; i++) {
            if (gUnk_03001800.unkD2[i] == 0)
                continue;
            clear_sprite_table_mask(0x21 + i, 1);
            gSpriteEntries[0x24 + i].unk0 = 0xC404;
            spr[0x24 + i].unk1C = 0;
            p = &gSpriteEntries[0x21 + i].unk2;
            gSpriteEntries[0x24 + i].unk2 = p[0];
            spr[0x24 + i].unk4 = p[1];
            spr[0x24 + i].unkA = 7;
            spr[0x24 + i].unkB = 0xE0;
            spr[0x24 + i].unk18 = 0;
            spr[0x24 + i].unk23 = 0;
            switch (gUnk_03001800.unkD2[i] & 0x7F) {
            case 1:
                gSpriteEntries[0x24 + i].unk6 = 0x4E02;
                break;
            case 2:
                gSpriteEntries[0x24 + i].unk6 = 0x4E03;
                break;
            default:
                spr[0x24 + i].unk6 = 0x4E01;
                break;
            }
        }
        play_sound_effect(0x6A);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802DA0C(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            if (advance_sprite_anim_frame(0x24 + i, 0))
                done++;
        }
    }
    if (done == count) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802DA60(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            set_sprite_hidden_flags(0x21 + i, 1);
            gSpriteEntries[0x21 + i].unk0 |= 0x220;
            gSpriteEntries[0x21 + i].unk8 = 0x80;
            gSpriteEntries[0x21 + i].unk9 = 0x80;
            gSpriteEntries[0x21 + i].unk18 = 0;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0802DAD0(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            if (gSpriteEntries[0x21 + i].unk8 == 0x40)
                done++;
            else {
                gSpriteEntries[0x21 + i].unk8 -= 8;
                gSpriteEntries[0x21 + i].unk9 -= 8;
            }
        }
    }
    if (done == count) {
        play_sound_effect(0x3C);
        gUnk_03000440.unk86 = 0;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802DB3C(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            if (gUnk_03000440.unk86 & 4)
                gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2 - 2;
            else
                gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2 + 2;
        }
    }
    if (gUnk_03000440.unk86 == 0x3C) {
        clear_battle_sprite_slot(0x21, 6);
        gUnk_03001800.unkAA++;
    } else
        gUnk_03000440.unk86++;
}

void sub_0802DBD8(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03000590[gUnk_03001800.unk60 + i].unkC9 = 0x2B;
        gUnk_03000590[gUnk_03001800.unk60 + i].unkCB = clamp_1_99(gUnk_03001800.unkE8);
        gUnk_03000590[gUnk_03001800.unk60 + i].unkCC = clamp_1_99(gUnk_03001800.unkEC);
        switch (gUnk_03001800.unkD2[i] & 0x7F) {
        case 1:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 2;
            break;
        case 2:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 3;
            break;
        default:
            gUnk_03000590[gUnk_03001800.unk60 + i].unkCA = 1;
            break;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0802DC9C(void) {
    gUnk_03001800.unkA6 = 0x5E;
    gUnk_03001800.unkAA++;
}

void sub_0802DCB4(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE908[gUnk_03001800.unkAA]();
}

void sub_0802DCDC(void) {
    lz_decompress_dispatch(gUnk_084E046C, (void *)0x06014800);
    CpuFastSet(gUnk_0850EEB8, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC404;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk4 = 0xE0;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x21].unk2 = 0xB8;
    else
        gSpriteEntries[0x21].unk2 = 0x40;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x69], 0x21);
    gUnk_03001800.unkAA++;
}

void sub_0802DD98(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x69], 0x21);
    if (gSpriteEntries[0x21].unk4 == 0x40) {
        gUnk_03000440.unk86 = 0;
        gSpriteEntries[0x21].unk25 = 0x14;
        gSpriteEntries[0x21].unk24 = 0;
        gSpriteEntries[0x21].unk28 = 0;
        gSpriteEntries[0x21].unk23 = 0;
        gUnk_03001800.unkAA++;
    } else
        gSpriteEntries[0x21].unk4 = (gSpriteEntries[0x21].unk4 + 1) & 0xFF;
}

void sub_0802DE1C(void) {
    const u8 *tbl;

    if ((gUnk_03000440.unk86 & 0x1F) == 0 && gSpriteEntries[0x21].unk23 <= 7) {
        gUnk_03001800.unkAA++;
        gUnk_03000440.unk86++;
        return;
    }
    gUnk_03000440.unk86++;
    process_sprite_anim_commands(gUnk_083B5F80[0x69], 0x21);
    update_sprite_animation_position(0x21);
    gSpriteEntries[0x21].unk24 = 4;
    if (gSpriteEntries[0x21].unk28) {
        gSpriteEntries[0x21].unk28--;
        return;
    }
    tbl = gUnk_083AE988;
    gSpriteEntries[0x21].unk25 = tbl[gSpriteEntries[0x21].unk23 * 2];
    if (gSpriteEntries[0x21].unk25 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA = 0xA;
        return;
    }
    if (gUnk_03001800.unkF8 & 1)
        gSpriteEntries[0x21].unk25 = (0x20 - gSpriteEntries[0x21].unk25) & 0x1F;
    gSpriteEntries[0x21].unk28 = gUnk_083AE988[gSpriteEntries[0x21].unk23 * 2 + 1];
    gSpriteEntries[0x21].unk23++;
}

void sub_0802DF18(void) {
    gSpriteEntries[0x21].unk6 = 0x7F02;
    play_sound_effect(0x38);
    gUnk_03001800.unkAA++;
}

void sub_0802DF48(void) {
    bg_palettes_blend_masked_now(0x7FFF, gUnk_03000440.unk84, 0xFFFF);
    obj_palettes_blend_masked_now(0x7FFF, gUnk_03000440.unk84, 0xFF00);
    if (gUnk_03000440.unk84 == 0x20)
        gUnk_03001800.unkAA++;
    else
        gUnk_03000440.unk84 += 2;
}

void sub_0802DF98(void) {
    bg_palettes_blend_masked_now(0x1084, gUnk_03000440.unk84, 0xFFFF);
    obj_palettes_blend_masked_now(0x1084, gUnk_03000440.unk84, 0xFF00);
    if (gUnk_03000440.unk84 == 0x10)
        gUnk_03001800.unkAA++;
    else
        gUnk_03000440.unk84 -= 2;
}

void sub_0802DFE8(void) {
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x69], 0x21);
    gUnk_03001800.unkAA = 4;
}

void sub_0802E010(void) {
    u32 found = 0;
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 &&
            (gUnk_03000590[gUnk_03001800.unk60 + i].unkBD & 4)) {
            gUnk_03001800.unkD2[i] = 1;
            found = 1;
        }
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 2;
}

void sub_0802E098(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk0 = 0xC624;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unk8 = 0x80;
        gSpriteEntries[0x21 + i].unk9 = 0x80;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        gSpriteEntries[0x21 + i].unk6 = 0x7F03;
    }
    play_sound_effect(0x54);
    gUnk_03001800.unkAA++;
}

void sub_0802E140(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            if (gSpriteEntries[0x21 + i].unk8 == 0x40)
                done = 1;
            else {
                gSpriteEntries[0x21 + i].unk8 -= 8;
                gSpriteEntries[0x21 + i].unk9 -= 8;
            }
        }
    }
    if (done) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802E1A4(void) {
    clear_battle_sprite_slot(0x21, 3);
    gUnk_03001800.unkA6 = 0x43;
    gUnk_03001800.unkAA++;
}

void sub_0802E1C8(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03001800.unkD2[i] = get_random_battle_weight_entry(gUnk_03001800.unk60 + i);
        battle_set_damage_vs_armor(gUnk_03001800.unk60 + i, gUnk_03001800.unkD2[i], 0xC8);
        gUnk_03001800.unkD2[i] |= gUnk_03001800.unkD1 << 7;
        gUnk_03001800.unkD6[i] = gUnk_03001800.unkC8;
        gUnk_03000590[gUnk_03001800.unk60 + i].parts[gUnk_03001800.unkD2[i] & 0x7F].unk11 -= gUnk_03001800.unkD6[i];
        sub_08035194(gUnk_03001800.unk60 + i);
        if ((gUnk_03001800.unkD2[i] & 0x7F) == 0 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            add_bot_to_defeated_list(gUnk_03001800.unk60 + i);
    }
    gUnk_03001800.unkAA++;
}

void sub_0802E294(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            switch (i) {
            case 0:
                set_display_digit_type(gUnk_03000440.unk9E, gUnk_03001800.unkD6[i], 1);
                battle_number_popup_init_slot(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
                break;
            case 1:
                set_display_digit_type(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkD6[1], 1);
                battle_number_popup_init_slot(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
                break;
            case 2:
                set_display_digit_type(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unkD6[2], 1);
                battle_number_popup_init_slot(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
                break;
            }
        }
    }
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_0802E358(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            switch (i) {
            case 0:
                battle_popup_update_slot(gUnk_03000440.unk9E, gUnk_03001800.unk60 + i, 0x21);
                break;
            case 1:
                battle_popup_update_slot(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unk60 + 1, 0x21);
                break;
            case 2:
                battle_popup_update_slot(gUnk_03000440.unk9E + 0x28, gUnk_03001800.unk60 + 2, 0x21);
                break;
            }
        }
    }
    gUnk_03000440.unk84++;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1) && gUnk_03000440.unk84 > 0x32)
        gUnk_03000440.unk84 = 0x78;
    if (gUnk_03000440.unk84 == 0x78) {
        clear_battle_sprite_slot(gUnk_03001800.unk60 * 4 + 0x21, 0xC);
        gUnk_03001800.unkAA++;
    }
}

void battle_dispatch_phase_handler_0802E424(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AE99C[gUnk_03001800.unkAA]();
}

void sub_0802E44C(void) {
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11) {
            gUnk_03001800.unkD2[i] = 1;
            gUnk_03001800.unkD6[i] = gUnk_03000590[gUnk_03001800.unk60 + i].unkC1;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0802E4C8(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084D6F88, (void *)0x06014800);
    CpuFastSet(gUnk_0850E938, (void *)0x050002E0, 0x10);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0xA + i].unk0 = 0xC624;
        gSpriteEntries[0xA + i].unk1C = 0;
        gSpriteEntries[0xA + i].unk2 = 0x78;
        gSpriteEntries[0xA + i].unk4 = 0x40;
        gSpriteEntries[0xA + i].unk8 = 4;
        gSpriteEntries[0xA + i].unk9 = 4;
        gSpriteEntries[0xA + i].unk18 = 0;
        gSpriteEntries[0xA + i].unk30 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0xA + i].unk32 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0xA + i].unk24 = 6;
        gSpriteEntries[0xA + i].unk23 = 0;
        gSpriteEntries[0xA + i].unkA = 7;
        gSpriteEntries[0xA + i].unkB = 0xE0;
        gUnk_03000440.unk84 = 0x48;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03000440.unk84], i + 0xA);
    }
    play_sound_effect(0x6A);
    gUnk_03001800.unkAA++;
}

void sub_0802E5D4(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            if (gSpriteEntries[0xA + i].unk8 == 0x40)
                done = 1;
            else {
                gSpriteEntries[0xA + i].unk8 += 4;
                gSpriteEntries[0xA + i].unk9 += 4;
            }
        }
    }
    if (done) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802E638(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            if (!(gUnk_03001800.unkF8 & 1))
                gSpriteEntries[0xA + i].unk18 = (gSpriteEntries[0xA + i].unk18 - 0x40) & 0x3FF;
            else
                gSpriteEntries[0xA + i].unk18 = (gSpriteEntries[0xA + i].unk18 + 0x40) & 0x3FF;
            if (move_sprite_toward_target(0xA + i)) {
                gSpriteEntries[0xA + i].unk18 = 0;
                done++;
            }
        }
    }
    if (done == count) {
        for (i = 0; i <= 2; i++) {
            if (gUnk_03001800.unkD2[i] && gUnk_03001800.unkD6[i])
                play_sound_effect(0x51);
        }
        gUnk_03001800.unkAA++;
    }
}

void sub_0802E70C(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            if (gUnk_03001800.unkD6[i] == 0)
                done++;
            else {
                process_sprite_anim_commands(gUnk_083B5F80[gUnk_03000440.unk84], 0xA + i);
                if (gSpriteEntries[0xA + i].unk22 == 0xFF)
                    done++;
            }
        }
    }
    if (done == count)
        gUnk_03001800.unkAA++;
}

void sub_0802E7A0(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            gSpriteEntries[0xA + i].unk30 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
            gSpriteEntries[0xA + i].unk32 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
            gSpriteEntries[0xA + i].unk23 = 0;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0802E820(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            if (gUnk_03001800.unkF8 & 1)
                gSpriteEntries[0xA + i].unk18 = (gSpriteEntries[0xA + i].unk18 - 0x40) & 0x3FF;
            else
                gSpriteEntries[0xA + i].unk18 = (gSpriteEntries[0xA + i].unk18 + 0x40) & 0x3FF;
            if (move_sprite_toward_target(0xA + i)) {
                gSpriteEntries[0xA + i].unk18 = 0;
                done++;
            }
        }
    }
    if (done == count) {
        play_sound_effect(0x2B);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802E8D4(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            if (gSpriteEntries[0xA + i].unk8 == 2) {
                done = 1;
                clear_battle_sprite_slot(0xA + i, 1);
            } else {
                gSpriteEntries[0xA + i].unk8 -= 2;
                gSpriteEntries[0xA + i].unk9 -= 2;
            }
        }
    }
    if (done)
        gUnk_03001800.unkAA++;
}

void sub_0802E948(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084E1518, (void *)0x06017000);
    CpuFastSet(gUnk_0850EED8, (void *)0x050002E0, 8);
    lz_decompress_dispatch(gUnk_084C8AC4, (void *)0x06014E00);
    CpuFastSet(gUnk_084E3018, (void *)0x050002C0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk0 = ((gUnk_03001800.unk39[3] + 2) << 10) | 0xC004;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0x81;
        gSpriteEntries[0x21 + i].unk30 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk32 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unk24 = 6;
        gSpriteEntries[0x21 + i].unk23 = 0;
        gSpriteEntries[0x21 + i].unk29 = 1;
        if (gUnk_03001800.unkF8 & 1)
            gSpriteEntries[0x21 + i].unk0 |= 0x1000;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6A], 0x21 + i);
    }
    gUnk_03001800.unkAA++;
}

void sub_0802EAA4(void) {
    if (sub_080385F8())
        gUnk_03001800.unkAA++;
}

void sub_0802EAC0(void) {
    gUnk_03001800.unkA6 = 0x67;
    gUnk_03001800.unkAA++;
}

void sub_0802EAD8(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gUnk_03000590[gUnk_03001800.unk60 + i].unkC1 = 0;
        gUnk_03001800.unkD2[i] = get_random_battle_weight_entry(gUnk_03001800.unk60 + i);
        battle_set_damage_vs_armor(gUnk_03001800.unk60 + i, gUnk_03001800.unkD2[i], gUnk_03001800.unkD6[i]);
        gUnk_03001800.unkD2[i] |= gUnk_03001800.unkD1 << 7;
        gUnk_03001800.unkD6[i] = gUnk_03001800.unkC8;
        gUnk_03000590[gUnk_03001800.unk60 + i].parts[gUnk_03001800.unkD2[i] & 0x7F].unk11 -= gUnk_03001800.unkD6[i];
        sub_08035194(gUnk_03001800.unk60 + i);
        if ((gUnk_03001800.unkD2[i] & 0x7F) == 0 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11 == 0)
            add_bot_to_defeated_list(gUnk_03001800.unk60 + i);
    }
    gUnk_03001800.unkAA++;
}

void sub_0802EBC0(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AEA08[gUnk_03001800.unkAA]();
}

void sub_0802EBE8(void) {
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = battle_side_first_record(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11)
            gUnk_03001800.unkD2[i] = 1;
    }
    gUnk_03001800.unkAA++;
}

void sub_0802EC4C(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084D6F88, (void *)0x06014800);
    CpuFastSet(gUnk_0850E938, (void *)0x050002E0, 0x10);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk0 = 0xC624;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x21 + i].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x21 + i].unk8 = 0x80;
        gSpriteEntries[0x21 + i].unk9 = 0x80;
        gSpriteEntries[0x21 + i].unk18 = 0;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xE0;
        gUnk_03000440.unk84 = 0x48;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03000440.unk84], i + 0x21);
    }
    play_sound_effect(0x6A);
    gUnk_03001800.unkAA++;
}

void sub_0802ED34(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            if (gSpriteEntries[0x21 + i].unk8 == 0x40)
                done = 1;
            else {
                gSpriteEntries[0x21 + i].unk8 -= 4;
                gSpriteEntries[0x21 + i].unk9 -= 4;
            }
        }
    }
    if (done) {
        play_sound_effect(0x51);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802ED90(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            process_sprite_anim_commands(gUnk_083B5F80[gUnk_03000440.unk84], 0x21 + i);
            if (gSpriteEntries[0x21 + i].unk22 == 0xFF)
                done = 1;
        }
    }
    if (done) {
        gUnk_03000440.unk86 = 0x20;
        gUnk_03001800.unkAA++;
    }
}

void decrement_timer_and_decompress_sprite(void) {
    u32 i;

    if (gUnk_03000440.unk86) {
        gUnk_03000440.unk86--;
        return;
    }
    lz_decompress_dispatch(gUnk_084E17E0, (void *)0x06015400);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x24 + i].unk0 = 0xC624;
        gSpriteEntries[0x24 + i].unk1C = 0;
        gSpriteEntries[0x24 + i].unk2 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk2;
        gSpriteEntries[0x24 + i].unk4 = gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4;
        gSpriteEntries[0x24 + i].unk8 = 0x40;
        gSpriteEntries[0x24 + i].unk9 = 0x40;
        gSpriteEntries[0x24 + i].unk18 = 0;
        gSpriteEntries[0x24 + i].unkA = 6;
        gSpriteEntries[0x24 + i].unkB = 0xF0;
        gSpriteEntries[0x24 + i].unk23 = 0;
        gSpriteEntries[0x24 + i].unk6 = 0x8100;
    }
    play_sound_effect(0x2A);
    gUnk_03001800.unkAA++;
}

void sub_0802EF0C(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] && medal_update_exp_progress(0x24 + i, 0))
            done = 1;
    }
    if (done) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802EF5C(void) {
    u32 done = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            if (gSpriteEntries[0x21 + i].unk8 == 4)
                done = 1;
            else {
                gSpriteEntries[0x21 + i].unk8 -= 4;
                gSpriteEntries[0x21 + i].unk9 -= 4;
                gSpriteEntries[0x24 + i].unk8 -= 4;
                gSpriteEntries[0x24 + i].unk9 -= 4;
            }
        }
    }
    if (done) {
        clear_battle_sprite_slot(0x21, 6);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802EFD0(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i])
            gUnk_03000590[gUnk_03001800.unk60 + i].unkC0 |= 8;
    }
    gUnk_03001800.unkAA++;
}

void sub_0802F018(void) {
    gUnk_03001800.unkA6 = 0x68;
    gUnk_03001800.unkAA++;
}

void sub_0802F030(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AEA44[gUnk_03001800.unkAA]();
}

void sub_0802F058(void) {
    lz_decompress_dispatch(gUnk_084D50DC, (void *)0x06015800);
    CpuFastSet(gUnk_0850E658, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC624;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk8 = 0x40;
    gSpriteEntries[0x21].unk9 = 0x40;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unk6 = 0x4100;
    gSpriteEntries[0x21].unk23 = 0;
    gSpriteEntries[0x21].unk27 = 0;
    play_sound_effect(0x29);
    gUnk_03001800.unkAA++;
}

void sub_0802F13C(void) {
    sprite_hop_step(0x21);
    if (gSpriteEntries[0x21].unk27 == 0x20) {
        gSpriteEntries[0x21].unk18 = 0;
        gUnk_03000440.unk84 = 1;
        gUnk_03001800.unkAA++;
        return;
    }
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x20) & 0x3FF;
    else
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 - 0x20) & 0x3FF;
    if (!(gSpriteEntries[0x21].unk27 & 1)) {
        if (!(gUnk_03001800.unkF8 & 1))
            gSpriteEntries[0x21].unk2++;
        else
            gSpriteEntries[0x21].unk2--;
    }
    gSpriteEntries[0x21].unk27++;
}

void sub_0802F214(void) {
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk0 = 0xC604;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk1C = 0;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unkA = 7;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unkB = 0xF0;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk8 = 0x40;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk9 = 0x40;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk18 = 0;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk6 = 0x4100;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk23 = 0;
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk27 = 0;
    play_sound_effect(0x29);
    gUnk_03001800.unkAA++;
}

void sub_0802F2F4(void) {
    sprite_hop_step(gUnk_03000440.unk84 + 0x21);
    if (gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk27 == 0x20) {
        clear_battle_sprite_slot(gUnk_03000440.unk84 + 0x21, 1);
        gSpriteEntries[0x21].unk8 += gUnk_03000440.unk84 << 4;
        gSpriteEntries[0x21].unk9 += gUnk_03000440.unk84 << 4;
        if (++gUnk_03000440.unk84 == 4)
            gUnk_03001800.unkAA++;
        else
            gUnk_03001800.unkAA = 2;
        return;
    }
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk18 =
            (gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk18 + 0x20) & 0x3FF;
    else
        gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk18 =
            (gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk18 - 0x20) & 0x3FF;
    if (!(gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk27 & 1)) {
        if (!(gUnk_03001800.unkF8 & 1))
            gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk2++;
        else
            gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk2--;
    }
    gSpriteEntries[gUnk_03000440.unk84 + 0x21].unk27++;
}

void sub_0802F3FC(void) {
    gSpriteEntries[0x21].unk30 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk32 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unk24 = 4;
    gSpriteEntries[0x21].unk23 = 0;
    gUnk_03001800.unkAA++;
}

void sub_0802F468(void) {
    if (move_sprite_toward_target(0x21)) {
        play_sound_effect(0x2B);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802F48C(void) {
    if (gSpriteEntries[0x21].unk8 == 4) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 4;
        gSpriteEntries[0x21].unk9 -= 4;
    }
}

void sub_0802F4D0(void) {
    lz_decompress_dispatch(gUnk_084DFC18, (void *)0x06014800);
    CpuFastSet(gUnk_0850EE38, (void *)0x050002E0, 0x10);
    gSpriteEntries[0x21].unk0 = 0xCC04;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unkB = 0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x68], 0x21);
    play_sound_effect(0x2C);
    gUnk_03001800.unkAA++;
}

void sub_0802F594(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x68], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802F5D8(void) {
    add_u8_capped(&gUnk_03000590[gUnk_03001800.unk87].unkD0 + 5, gUnk_03001800.unkEC, 0xFF);
    gUnk_03001800.unkAA++;
}

void sub_0802F610(void) {
    gUnk_03001800.unkA6 = 0x51;
    gUnk_03001800.unkAA++;
}

void sub_0802F628(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AEA84[gUnk_03001800.unkAA]();
}

void sub_0802F650(void) {
    u32 i;

    sub_0803836C();
    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk87);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40 && gUnk_03000590[gUnk_03001800.unk60 + i].parts[0].unk11) {
            gUnk_03001800.unkD2[i] = 1;
            gUnk_03001800.unkD6[i] = gUnk_03000590[gUnk_03001800.unk60 + i].parts[3].unk11;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0802F6CC(void) {
    u32 i;

    lz_decompress_dispatch(gUnk_084E1884, (void *)0x06014800);
    CpuFastSet(gUnk_0850EEF8, (void *)0x050002E0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002C0, 8);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] == 0)
            continue;
        gSpriteEntries[0x21 + i].unk0 = 0xC404;
        gSpriteEntries[0x21 + i].unk1C = 0;
        gSpriteEntries[0x21 + i].unk2 = 0x78;
        gSpriteEntries[0x21 + i].unk4 = 0xF0;
        gSpriteEntries[0x21 + i].unkA = 7;
        gSpriteEntries[0x21 + i].unkB = 0xF0;
        gSpriteEntries[0x21 + i].unk24 = 4;
        gSpriteEntries[0x21 + i].unk25 = 0;
        gSpriteEntries[0x21 + i].unk30 = 0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6D], 0x21 + i);
        if (gUnk_03001800.unkF8 & 1)
            gSpriteEntries[0x21 + i].unk0 |= 0x1000;
    }
    play_sound_effect(0x61);
    gUnk_03001800.unkAA++;
}

void sub_0802F7B8(void) {
    u32 done = 0;
    u32 count = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i]) {
            count++;
            if (sprite_move_toward_target(0x21 + i, gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 - 4,
                                          gSpriteEntries[(gUnk_03001800.unk60 + i) * 4 + 0x5D].unk4 + 0x10)) {
                gSpriteEntries[0x21 + i].unk27 = 0;
                gSpriteEntries[0x21 + i].unk28 = 0;
                gSpriteEntries[0x21 + i].unk29 = 1;
                done++;
            }
        }
    }
    if (done == count) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0802F864(void) {
    play_sound_effect(0x22);
    gUnk_03001800.unkAA++;
}

void sub_0802F880(void) {
    if (sub_0803884C())
        gUnk_03001800.unkAA++;
}

void sub_0802F89C(void) {
    u32 found = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] && gUnk_03001800.unkD6[i])
            found = 1;
    }
    if (!found)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA += 2;
}

void sub_0802F8E4(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkD2[i] && gUnk_03001800.unkD6[i]) {
            gUnk_03001800.unkD2[i] = 3;
            battle_set_damage_vs_armor(gUnk_03001800.unk60 + i, 3, gUnk_03001800.unkD6[i]);
            gUnk_03001800.unkD2[i] |= gUnk_03001800.unkD1 << 7;
            gUnk_03001800.unkD6[i] = gUnk_03001800.unkC8;
            gUnk_03000590[gUnk_03001800.unk60 + i].parts[gUnk_03001800.unkD2[i] & 0x7F].unk11 -= gUnk_03001800.unkD6[i];
            sub_08035194(gUnk_03001800.unk60 + i);
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0802F990(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AEAD8[gUnk_03001800.unkAA]();
}

void sub_0802F9B8(void) {
    lz_decompress_dispatch(gUnk_084E1B98, (void *)0x06014800);
    CpuFastSet(gUnk_0850EF18, (void *)0x050002C0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC404;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 0x1C;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk6 = 0x8300;
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x18;
    else
        gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18;
    gSpriteEntries[0x22].unk0 = 0xC404;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 0x1C;
    gSpriteEntries[0x22].unkA = 7;
    gSpriteEntries[0x22].unkB = 0xF1;
    gSpriteEntries[0x22].unk6 = 0x8301;
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x22].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18;
    else {
        gSpriteEntries[0x22].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x18;
        gSpriteEntries[0x22].unk0 |= 0x1000;
    }
    gUnk_03000440.unk86 = 0;
    play_sound_effect(0x2B);
    gUnk_03001800.unkAA++;
}

void sub_0802FB74(void) {
    if (gUnk_03000440.unk86 == 0x18) {
        gUnk_03000440.unk86 = 0;
        gUnk_03001800.unkAA++;
        return;
    }
    gUnk_03000440.unk86++;
    if (!(gUnk_03001800.unkF8 & 1)) {
        gSpriteEntries[0x21].unk2++;
        gSpriteEntries[0x22].unk2--;
    } else {
        gSpriteEntries[0x21].unk2--;
        gSpriteEntries[0x22].unk2++;
    }
}

void sub_0802FBF4(void) {
    if (gUnk_03000440.unk86 == 0xC) {
        gUnk_03001800.unkAA++;
        return;
    }
    gUnk_03000440.unk86++;
    gSpriteEntries[0x21].unk4 += 2;
    gSpriteEntries[0x22].unk4 += 2;
}

void sub_0802FC3C(void) {
    clear_battle_sprite_slot(0x21, 2);
    CpuFastSet(gUnk_0850EF18, (void *)0x050002C0, 0x10);
    gSpriteEntries[0x21].unk0 = 0xC624;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x21].unkA = 7;
    gSpriteEntries[0x21].unk8 = 0x80;
    gSpriteEntries[0x21].unk9 = 0x80;
    gSpriteEntries[0x21].unk18 = 0;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk6 = 0x8302;
    gUnk_03001800.unkAA++;
}

void sub_0802FD08(void) {
    if (gSpriteEntries[0x21].unk8 == 0x40) {
        play_sound_effect(0x54);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 8;
        gSpriteEntries[0x21].unk9 -= 8;
    }
}

void sub_0802FD4C(void) {
    if (gSpriteEntries[0x21].unk8 == 0x60)
        gUnk_03001800.unkAA++;
    else {
        gSpriteEntries[0x21].unk8 += 4;
        gSpriteEntries[0x21].unk9 += 4;
    }
}

void sub_0802FD84(void) {
    if (gSpriteEntries[0x21].unk8 == 0x40) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 4;
        gSpriteEntries[0x21].unk9 -= 4;
    }
}

void sub_0802FDC8(void) {
    if (gSpriteEntries[0x21].unk8 == 4) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    } else {
        gSpriteEntries[0x21].unk8 -= 4;
        gSpriteEntries[0x21].unk9 -= 4;
    }
}

void sub_0802FE0C(void) {
    gUnk_03000590[gUnk_03001800.unk87].unkC0 |= 1;
    gUnk_03001800.unkAA++;
}

void sub_0802FE38(void) {
    gUnk_03001800.unkA6 = 0x4F;
    gUnk_03001800.unkAA++;
}

void sub_0802FE50(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AEB18[gUnk_03001800.unkAA]();
}

void sub_0802FE78(void) {
    lz_decompress_dispatch(gUnk_084E1EA4, (void *)0x06014800);
    CpuFastSet(gUnk_0850EF18, (void *)0x050002C0, 8);
    CpuFastSet(gUnk_084E30B8, (void *)0x050002E0, 8);
    gSpriteEntries[0x21].unk0 = 0xC404;
    gSpriteEntries[0x21].unk1C = 0;
    gSpriteEntries[0x21].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 0x1C;
    gSpriteEntries[0x21].unkA = 6;
    gSpriteEntries[0x21].unkB = 0xF0;
    gSpriteEntries[0x21].unk6 = 0x8400;
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x18;
    else
        gSpriteEntries[0x21].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18;
    gSpriteEntries[0x22].unk0 = 0xC404;
    gSpriteEntries[0x22].unk1C = 0;
    gSpriteEntries[0x22].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 0x1C;
    gSpriteEntries[0x22].unkA = 6;
    gSpriteEntries[0x22].unkB = 0xF0;
    gSpriteEntries[0x22].unk6 = 0x8401;
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x22].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x18;
    else
        gSpriteEntries[0x22].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18;
    gSpriteEntries[0x23].unk0 = 0xC404;
    gSpriteEntries[0x23].unk1C = 0;
    gSpriteEntries[0x23].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 0x1C;
    gSpriteEntries[0x23].unkA = 7;
    gSpriteEntries[0x23].unkB = 0xF1;
    gSpriteEntries[0x23].unk6 = 0x8402;
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x23].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18;
    else {
        gSpriteEntries[0x23].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x18;
        gSpriteEntries[0x23].unk0 |= 0x1000;
    }
    gSpriteEntries[0x24].unk0 = 0xC404;
    gSpriteEntries[0x24].unk1C = 0;
    gSpriteEntries[0x24].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 0x1C;
    gSpriteEntries[0x24].unkA = 7;
    gSpriteEntries[0x24].unkB = 0xF1;
    gSpriteEntries[0x24].unk6 = 0x8403;
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x24].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 + 0x18;
    else {
        gSpriteEntries[0x24].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2 - 0x18;
        gSpriteEntries[0x24].unk0 |= 0x1000;
    }
    gUnk_03000440.unk86 = 0;
    play_sound_effect(0x2B);
    gUnk_03001800.unkAA++;
}

void sub_08030180(void) {
    if (gUnk_03000440.unk86 == 0x18) {
        gUnk_03000440.unk86 = 0;
        gUnk_03001800.unkAA++;
        return;
    }
    gUnk_03000440.unk86++;
    if (!(gUnk_03001800.unkF8 & 1)) {
        gSpriteEntries[0x21].unk2++;
        gSpriteEntries[0x22].unk2++;
        gSpriteEntries[0x23].unk2--;
        gSpriteEntries[0x24].unk2--;
    } else {
        gSpriteEntries[0x21].unk2--;
        gSpriteEntries[0x22].unk2--;
        gSpriteEntries[0x23].unk2++;
        gSpriteEntries[0x24].unk2++;
    }
}

void sub_08030238(void) {
    if (gUnk_03000440.unk86 == 0xC) {
        gUnk_03001800.unkAA++;
        return;
    }
    gUnk_03000440.unk86++;
    gSpriteEntries[0x21].unk4 += 2;
    gSpriteEntries[0x22].unk4 += 2;
    gSpriteEntries[0x23].unk4 += 2;
    gSpriteEntries[0x24].unk4 += 2;
}

void sub_0803029C(void) {
    gSpriteEntries[0x25].unk0 = 0xC404;
    gSpriteEntries[0x25].unk1C = 0;
    gSpriteEntries[0x25].unk2 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gSpriteEntries[0x25].unk4 = gSpriteEntries[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gSpriteEntries[0x25].unkA = 7;
    gSpriteEntries[0x25].unkB = 0xF2;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6F], 0x25);
    if (gUnk_03001800.unkF8 & 1)
        gSpriteEntries[0x25].unk0 |= 0x1000;
    play_sound_effect(0x30);
    gUnk_03001800.unkAA++;
}

void sub_08030354(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x6F], 0x25);
    if (gSpriteEntries[0x25].unk22 == 0xFF) {
        gUnk_03000440.unk86 = 0;
        clear_battle_sprite_slot(0x25, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_080303A4(void) {
    if (gUnk_03000440.unk86 == 0x20) {
        gUnk_03000440.unk86 = 0;
        gUnk_03001800.unkAA++;
        return;
    }
    if (gUnk_03000440.unk86 & 1) {
        if (!(gUnk_03001800.unkF8 & 1)) {
            gSpriteEntries[0x21].unk2 = (gSpriteEntries[0x21].unk2 - 1) & 0x1FF;
            gSpriteEntries[0x22].unk2 = (gSpriteEntries[0x22].unk2 + 1) & 0x1FF;
            gSpriteEntries[0x23].unk2 = (gSpriteEntries[0x23].unk2 - 1) & 0x1FF;
            gSpriteEntries[0x24].unk2 = (gSpriteEntries[0x24].unk2 + 1) & 0x1FF;
        } else {
            gSpriteEntries[0x21].unk2 = (gSpriteEntries[0x21].unk2 + 1) & 0x1FF;
            gSpriteEntries[0x22].unk2 = (gSpriteEntries[0x22].unk2 - 1) & 0x1FF;
            gSpriteEntries[0x23].unk2 = (gSpriteEntries[0x23].unk2 + 1) & 0x1FF;
            gSpriteEntries[0x24].unk2 = (gSpriteEntries[0x24].unk2 - 1) & 0x1FF;
        }
    }
    gUnk_03000440.unk86++;
}

void sub_08030494(void) {
    if (gUnk_03000440.unk86 == 0x20) {
        clear_battle_sprite_slot(0x21, 4);
        gUnk_03000440.unk86 = 0;
        gUnk_03001800.unkAA++;
        return;
    }
    if (!(gUnk_03000440.unk86 & 3)) {
        gSpriteEntries[0x21].unk4 = (gSpriteEntries[0x21].unk4 - 1) & 0xFF;
        gSpriteEntries[0x22].unk4 = (gSpriteEntries[0x22].unk4 + 1) & 0xFF;
        gSpriteEntries[0x23].unk4 = (gSpriteEntries[0x23].unk4 - 1) & 0xFF;
        gSpriteEntries[0x24].unk4 = (gSpriteEntries[0x24].unk4 + 1) & 0xFF;
    }
    if (gUnk_03000440.unk86 & 1) {
        gSpriteEntries[0x21].unk0 |= 0x8000;
        gSpriteEntries[0x22].unk0 |= 0x8000;
        gSpriteEntries[0x23].unk0 |= 0x8000;
        gSpriteEntries[0x24].unk0 |= 0x8000;
    } else {
        gSpriteEntries[0x21].unk0 &= 0x7FFF;
        gSpriteEntries[0x22].unk0 &= 0x7FFF;
        gSpriteEntries[0x23].unk0 &= 0x7FFF;
        gSpriteEntries[0x24].unk0 &= 0x7FFF;
    }
    gUnk_03000440.unk86++;
}

void sub_0803059C(void) {
    gUnk_03000590[gUnk_03001800.unk87].unkC0 |= 4;
    gUnk_03001800.unkAA++;
}

void sub_080305C8(void) {
    gUnk_03001800.unkA6 = 0x6A;
    gUnk_03001800.unkAA++;
}
