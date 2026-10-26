#include "global.h"

void sub_0801C988(void) {
    if ((gUnk_03002C30[0x21].unk8 += 8) == 0x40) {
        if (gUnk_03001800.unkAA < 0x20)
            play_sound_effect(0x3F);
        gUnk_03001800.unkAA++;
    }
}

void sub_0801C9C8(void) {
    set_target_sprite_position(gUnk_03001800.unk87, gFrameCounter, gUnk_03001800.unk51);
    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03001800.unk52], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF) {
        update_target_cursor_position(gUnk_03001800.unk87);
        gUnk_03001800.unkAA++;
    }
}

void sub_0801CA2C(void) {
    if (gUnk_03002C30[0x21].unk8 == 8) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    } else {
        gUnk_03002C30[0x21].unk8 -= 8;
    }
}

void sub_0801CA60(void) {
    set_display_digit_type(&gUnk_03000440.unkEE, gUnk_03001800.unkC8, 1);
    render_battle_text_sprites(&gUnk_03000440.unkEE, gUnk_03001800.unk87, 0x21);
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_0801CAA8(void) {
    update_battle_sprite_animations(&gUnk_03000440.unkEE, gUnk_03001800.unk87, 0x21);
    if (++gUnk_03000440.unk84, gUnk_03000440.unk89 == 0 && (KEYS_LO(gRepeatKeys) & 1) && gUnk_03000440.unk84 > 0x32)
        gUnk_03000440.unk84 = 0x78;
    if (gUnk_03000440.unk84 == 0x78) {
        clear_battle_sprite_slot(gUnk_03001800.unk87 * 4 + 0x21, 4);
        gUnk_03001800.unkAA++;
    }
}

void load_battle_script_data_d0(void) {
    memcpy_bytes_0803F63C(gUnk_083C6DE8[gUnk_03001800.unkD0], gUnk_03000440.unk9E, 0xE);
    divide_by_100000_b(gUnk_03000440.unk9E + 0x14, gUnk_03001800.unkC8, 0x35);
    gUnk_03001800.unkA6 = 0x12;
    gUnk_03001800.unkAA++;
}

void apply_battle_damage_tick(void) {
    reduce_bot_part_stat(gUnk_03001800.unk87, gUnk_03001800.unkD0, gUnk_03001800.unkC8);
    gUnk_03001800.unkAA++;
}

void battle_check_hit_and_set_timer(void) {
    if (gUnk_03001800.unkD1) {
        play_sound_effect(0x3B);
        sub_08035194(gUnk_03001800.unk87);
        gUnk_03001800.unkA6 = 0x13;
        gUnk_03001800.unkAA = 0x1A;
    } else {
        gUnk_03001800.unkAA = 0x20;
    }
}

void sub_0801CBE4(void) {
    if (gUnk_03000590[gUnk_03001800.unk87].parts[0].unk11 == 0) {
        add_bot_to_defeated_list(gUnk_03001800.unk87);
        gUnk_03001800.unkAA = 0x2F;
    } else {
        gUnk_03001800.unkAA = 0x20;
    }
}

void sub_0801CC24(void) {
    if (sprite_move_toward_target(0x21, 0x3C, 0x84)) {
        play_sound_effect(0x41);
        gUnk_03000440.unk84 = 0;
        gUnk_03001800.unkAA++;
    }
}

void sub_0801CC58(void) {
    sub_080353AC(gUnk_03000440.unk84);
    if (++gUnk_03000440.unk84 > 0x1D) {
        play_sound_effect(0x3F);
        gBg3Scroll.y = 0;
        gUnk_03000440.unk84 = 0;
        gUnk_03000440.unk86 = gUnk_03002C30[0x21].unk2;
        gUnk_03001800.unkAA++;
    }
}

void sub_0801CCB8(void) {
    sub_0803536C(0x21, gUnk_03000440.unk84, gUnk_03000440.unk86);
    if (++gUnk_03000440.unk84 == 0x5A) {
        gUnk_03002C30[0x21].unk2 = gUnk_03000440.unk86;
        gUnk_03001800.unkAA++;
    }
}

void sub_0801CD08(void) {
    if (gUnk_03001800.unk51 == 2)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA = 8;
}

void sub_0801CD28(void) {
    gUnk_03001800.unkA6 = 0x15;
    gUnk_03001800.unkAA++;
}

void sub_0801CD40(void) {
    gUnk_03001800.unkAA = 0x20;
}

void sub_0801CD50(void) {
    lz_decompress_dispatch(gUnk_084CDBD8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E378, (void *)0x050002E0, 8);
    setup_battle_cursor_sprite_08036FF8(0x21, gUnk_03002C30[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkD0].unk2,
                                        gUnk_03002C30[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkD0].unk4, 4);
    gUnk_03001800.unkAA++;
}

void sub_0801CDB4(void) {
    if (update_sprite_animations_tick_080370AC(0x21, 4))
        gUnk_03001800.unkAA++;
}

void sub_0801CDD4(void) {
    lz_decompress_dispatch(gUnk_084CC9A8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E338, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC004;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkD0].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkD0].unk4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x22], 0x21);
    gUnk_03001800.unkAA++;
}

void sub_0801CE94(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x22], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
        switch (gUnk_03001800.unk51) {
        case 0:
            lz_decompress_dispatch(gUnk_084C907C, (void *)0x06014800);
            CpuFastSet(gUnk_0850E058, (void *)0x050002C0, 8);
            break;
        case 1:
            lz_decompress_dispatch(gUnk_084C9288, (void *)0x06014800);
            CpuFastSet(gUnk_0850E078, (void *)0x050002C0, 8);
            break;
        case 2:
            lz_decompress_dispatch(gUnk_084C9624, (void *)0x06014800);
            CpuFastSet(gUnk_0850E098, (void *)0x050002C0, 8);
            break;
        case 3:
            lz_decompress_dispatch(gUnk_084C978C, (void *)0x06014800);
            CpuFastSet(gUnk_0850E0B8, (void *)0x050002C0, 8);
            break;
        }
        gUnk_03001800.unkAA = 0xE;
    }
}

void sub_0801CF78(void) {
    u8 v;

    if (gUnk_03001800.unk51 != 2) {
        v = gUnk_03000590[gUnk_03001800.unk87].parts[3].unk12 >> 1;
        if (v >= gUnk_03001800.unk28[gUnk_03001800.unk89].unk4) {
            gUnk_03001800.unkAA++;
        } else {
            gUnk_03001800.unk28[gUnk_03001800.unk89].unk4 -= v;
            gUnk_03001800.unkAA = 0x2D;
        }
    } else {
        gUnk_03001800.unk28[gUnk_03001800.unk89].unk4--;
        if (gUnk_03001800.unk28[gUnk_03001800.unk89].unk4 == 0)
            gUnk_03001800.unkAA++;
        else
            gUnk_03001800.unkAA = 0x2E;
    }
}

void sub_0801CFFC(void) {
    switch (gUnk_03001800.unk51) {
    case 0:
        lz_decompress_dispatch(gUnk_084C907C, (void *)0x06015400);
        break;
    case 1:
        lz_decompress_dispatch(gUnk_084C9288, (void *)0x06015400);
        break;
    case 2:
        lz_decompress_dispatch(gUnk_084C9624, (void *)0x06015400);
        break;
    case 3:
        lz_decompress_dispatch(gUnk_084C978C, (void *)0x06015400);
        break;
    }
    gUnk_03001800.unkAA++;
}

void sub_0801D06C(void) {
    gUnk_03002C30[0x21].unk0 = ((gUnk_03001800.unk39[3] + 2) << 10) | -0x3DFC;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unkA = 6;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk8 = 8;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk4 = 0x3C;
    if (gUnk_03001800.unk89 == 0) {
        gUnk_03002C30[0x21].unk0 |= 0x1000;
        gUnk_03002C30[0x21].unk2 = 0x68;
    } else
        gUnk_03002C30[0x21].unk2 = 0x88;
    switch (gUnk_03001800.unk51) {
    case 0:
        gUnk_03002C30[0x21].unk6 = 0xB00;
        break;
    case 1:
        gUnk_03002C30[0x21].unk6 = 0xC00;
        break;
    case 2:
        gUnk_03002C30[0x21].unk6 = 0xD00;
        break;
    case 3:
        gUnk_03002C30[0x21].unk6 = 0xE00;
        break;
    }
    gUnk_03001800.unkAA++;
}

void sub_0801D174(void) {
    gUnk_03002C30[0x21].unk23 = 0;
    gUnk_03000440.unk84 = 0;
    play_sound_effect(0x34);
    gUnk_03001800.unkAA++;
}

void sub_0801D1AC(void) {
    if (sub_080353CC(0x21) == 0) {
        if (!(gUnk_03000440.unk84 & 1)) {
            if (gUnk_03001800.unk89 == 0)
                gUnk_03002C30[0x21].unk2++;
            else
                gUnk_03002C30[0x21].unk2--;
        }
        gUnk_03000440.unk84++;
    } else if (gUnk_03002C30[0x21].unk8 == 8) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    } else {
        gUnk_03002C30[0x21].unk8 -= 8;
    }
}

void sub_0801D244(void) {
    if (gUnk_03001800.unk51 == 2)
        gUnk_03001800.unkAA = 0x2E;
    else
        gUnk_03001800.unkAA = 0x2D;
}

void sub_0801D264(void) {
    gUnk_03001800.unk28[gUnk_03001800.unk89].unk2 = 0;
    gUnk_03001800.unk28[gUnk_03001800.unk89].unk3 = 0;
    gUnk_03001800.unk28[gUnk_03001800.unk89].unk4 = 0;
    gUnk_03001800.unk28[gUnk_03001800.unk89].unk5 = 0;
    gUnk_03001800.unkA6 = 0x25;
    gUnk_03001800.unkAA++;
}

void sub_0801D2AC(void) {
    gUnk_03001800.unkB5 = 1;
    gUnk_03001800.unkAB = 0;
}

void sub_0801D2C4(void) {
    gUnk_03001800.unkB5 = 1;
    gUnk_03001800.unkAB = 1;
}

void sub_0801D2D8(void) {
    gUnk_03001800.unkB5 = 1;
    gUnk_03001800.unkAB = 2;
}

void battle_dispatch_phase_handler_0801D2F0(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD50C[gUnk_03001800.unkAA]();
}

void sub_0801D318(void) {
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03000590[gUnk_03001800.unk87].unkDD - 1].unk11) {
        gUnk_03001800.unkB5 = 1;
        gUnk_03001800.unkAB = 0;
    } else {
        gUnk_03001800.unkA6 = 5;
        gUnk_03001800.unkAA++;
    }
}

void sub_0801D36C(void) {
    gUnk_03001800.unkB5 = 1;
    gUnk_03001800.unkAB = 1;
}

void sub_0801D380(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD530[gUnk_03001800.unkAA]();
}

void sub_0801D3A8(void) {
    if (gUnk_03000590[gUnk_03001800.unk88].parts[gUnk_03001800.unk8B].unk11) {
        gUnk_03001800.unkB5 = 1;
        gUnk_03001800.unkAB = 0;
    } else {
        gUnk_03001800.unkA6 = 0xC;
        gUnk_03001800.unkAA++;
    }
}

void sub_0801D3F8(void) {
    gUnk_03001800.unkB5 = 1;
    gUnk_03001800.unkAB = 1;
}

void sub_0801D40C(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD550[gUnk_03001800.unkAA]();
}

void sub_0801D434(void) {
    CpuFastSet(gUnk_084E3038, (void *)0x050002C0, 8);
    gUnk_03001800.unkAA++;
}

void sub_0801D45C(void) {
    clear_battle_sprite_slot(9, 1);
    gUnk_03002C30[9].unk0 = 0xC404;
    gUnk_03002C30[9].unk1C = 0;
    gUnk_03002C30[9].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[9].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[9].unkA = 6;
    gUnk_03002C30[9].unkB = 0xF0;
    gUnk_03002C30[9].unk30 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gUnk_03002C30[9].unk32 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[9].unk24 = 6;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1B], 9);
    gUnk_03001800.unkAA++;
}

void sub_0801D524(void) {
    if (move_sprite_toward_target(9))
        gUnk_03001800.unkAA++;
}

void sub_0801D544(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x1B], 9);
    if (gUnk_03002C30[9].unk22 == 0xFF) {
        clear_battle_sprite_slot(9, 1);
        gUnk_03001800.unkB5 = 1;
    }
}

void sub_0801D580(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD570[gUnk_03001800.unkAA]();
}

void sub_0801D5A8(void) {
    u32 base;
    u32 i;

    if (gUnk_03000590[gUnk_03001800.unk87].unkC0 & 4) {
        gUnk_03001800.unkB5 = 1;
        return;
    }
    base = sub_08032FC4(gUnk_03001800.unk88);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[base + i].unk40 == 0)
            continue;
        if (!(gUnk_03000590[base + i].unkBD & 8))
            continue;
        if (gUnk_03001800.unk88 == base + i)
            continue;
        if (gUnk_03000590[base + i].unkC9 == 0x2F)
            continue;
        if (gUnk_03000590[base + i].parts[gUnk_03000590[base + i].unkDE - 1].unk11 == 0)
            continue;
        gUnk_03001800.unkDE = base + i + 1;
        gUnk_03001800.unkDF = gUnk_03000590[base + i].unkDF;
    }
    if (gUnk_03001800.unkDE)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkB5 = 1;
}

void sub_0801D6A4(void) {
    switch (gUnk_03001800.unkDF) {
    case 0x1B:
        lz_decompress_dispatch(gUnk_084C9880, (void *)0x06014800);
        CpuFastSet(gUnk_0850E0F8, (void *)0x050002C0, 8);
        break;
    case 0x1C:
        lz_decompress_dispatch(gUnk_084C9B88, (void *)0x06014800);
        CpuFastSet(gUnk_0850E118, (void *)0x050002C0, 8);
        break;
    case 0x1D:
        lz_decompress_dispatch(gUnk_084C9E9C, (void *)0x06014800);
        CpuFastSet(gUnk_0850E138, (void *)0x050002C0, 8);
        break;
    }
    gUnk_03001800.unkAA++;
}

void sub_0801D738(void) {
    memcpy_bytes_0803F63C(&gUnk_03002C30[(gUnk_03001800.unkDE - 1) * 4 + 0x5A], &gUnk_03002C30[0x21], 0x40);
    memcpy_bytes_0803F63C(&gUnk_03002C30[(gUnk_03001800.unkDE - 1) * 4 + 0x5B], &gUnk_03002C30[0x22], 0x40);
    memcpy_bytes_0803F63C(&gUnk_03002C30[(gUnk_03001800.unkDE - 1) * 4 + 0x5C], &gUnk_03002C30[0x23], 0x40);
    memcpy_bytes_0803F63C(&gUnk_03002C30[(gUnk_03001800.unkDE - 1) * 4 + 0x5D], &gUnk_03002C30[0x24], 0x40);
    clear_sprite_table_mask(0x21, 4);
    get_bot_part_effective_values(gUnk_03001800.unkDE - 1, gUnk_03001800.unk64);
    setup_battle_sprite_group(gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                              gUnk_03001800.unk64[3], gUnk_03001800.unkDE - 1, gUnk_03001800.unkDE * 4 + 0x56,
                              gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x59].unk2,
                              gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x59].unk4 - 4, (gUnk_03001800.unkF8 & 1) ^ 1,
                              gUnk_03001800.unk39[3] + 2, gUnk_03001800.unkDE * 4 + 0x56);
    battle_sprite_set_palette_index(gUnk_03001800.unkDE * 4 + 0x56, 8);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_0801D878(void) {
    update_battle_sprite_orbiting_positions((gUnk_03001800.unkDE - 1) * 4 + 0x5A, gUnk_03001800.unkDE - 1,
                                            (gUnk_03001800.unkF8 & 1) ^ 1);
    if (gUnk_03000440.unk84 & 4)
        clear_sprite_table_mask(gUnk_03001800.unkDE * 4 + 0x56, 4);
    else
        set_sprite_hidden_flags(gUnk_03001800.unkDE * 4 + 0x56, 4);
    if (++gUnk_03000440.unk84 == 0x3C) {
        set_sprite_hidden_flags(gUnk_03001800.unkDE * 4 + 0x56, 4);
        play_sound_effect(0x40);
        gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x59].unk24 = 4;
        gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x59].unk25 = 0;
        gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x59].unk30 = 0;
        sub_08035694(gUnk_03001800.unkDE + 0x71);
        gUnk_03001800.unkAA++;
    }
}

void sub_0801D95C(void) {
    if (update_sprite_deceleration(gUnk_03001800.unkDE * 4 + 0x59, -0x20, -0x10)) {
        check_sprite_overlap_and_adjust(gUnk_03001800.unkDE * 4 + 0x59, gUnk_03001800.unkDE + 0x71);
        update_battle_sprite_orbiting_positions((gUnk_03001800.unkDE - 1) * 4 + 0x5A, gUnk_03001800.unkDE - 1,
                                                (gUnk_03001800.unkF8 & 1) ^ 1);
        gUnk_03001800.unkAA++;
    } else {
        update_battle_sprite_orbiting_positions((gUnk_03001800.unkDE - 1) * 4 + 0x5A, gUnk_03001800.unkDE - 1,
                                                (gUnk_03001800.unkF8 & 1) ^ 1);
        check_sprite_overlap_and_adjust(gUnk_03001800.unkDE * 4 + 0x59, gUnk_03001800.unkDE + 0x71);
    }
}

void sub_0801D9DC(void) {
    u32 done = 0;

    if (!(gUnk_03001800.unkF8 & 1)) {
        gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x59].unk2 -= 2;
        if (gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x59].unk2 <= 0x78)
            done = 1;
    } else {
        gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x59].unk2 += 2;
        if (gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x59].unk2 > 0x77)
            done = 1;
    }
    update_battle_sprite_orbiting_positions((gUnk_03001800.unkDE - 1) * 4 + 0x5A, gUnk_03001800.unkDE - 1,
                                            (gUnk_03001800.unkF8 & 1) ^ 1);
    if (done) {
        gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x59].unk24 = 8;
        gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x59].unk25 = 0;
        gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x59].unk30 = 0;
        gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x59].unk2 = 0x78;
        gUnk_03002C30[gUnk_03001800.unkDE + 0x71].unk2 = 0x78;
        gUnk_03002C30[gUnk_03001800.unkDE + 0x71].unk4 = gUnk_03002C30[gUnk_03001800.unk87 + 0x72].unk4;
        gUnk_03001800.unkAA++;
    }
}

void sub_0801DAEC(void) {
    if (sprite_move_toward_target(gUnk_03001800.unkDE * 4 + 0x59, gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4,
                                  gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 + 0x10)) {
        check_sprite_overlap_and_adjust(gUnk_03001800.unkDE * 4 + 0x59, gUnk_03001800.unkDE + 0x71);
        update_battle_sprite_orbiting_positions((gUnk_03001800.unkDE - 1) * 4 + 0x5A, gUnk_03001800.unkDE - 1,
                                                (gUnk_03001800.unkF8 & 1) ^ 1);
        play_sound_effect(0x41);
        get_bot_part_effective_values(gUnk_03001800.unkDE - 1, gUnk_03001800.unk64);
        setup_battle_sprite_group(gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                  gUnk_03001800.unk64[3], gUnk_03001800.unkDE - 1, gUnk_03001800.unkDE * 4 + 0x56,
                                  gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x59].unk2,
                                  gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x59].unk4 - 4, (gUnk_03001800.unkF8 & 1) ^ 1,
                                  gUnk_03001800.unk39[3] + 2, gUnk_03001800.unkDE * 4 + 0x56);
        gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x57].unk18 = 0;
        gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x58].unk18 = 0;
        sub_080356B4(gUnk_03001800.unkDE + 0x71);
        gUnk_03000440.unk84 = 0;
        gUnk_03001800.unkAA++;
    } else {
        update_battle_sprite_orbiting_positions((gUnk_03001800.unkDE - 1) * 4 + 0x5A, gUnk_03001800.unkDE - 1,
                                                (gUnk_03001800.unkF8 & 1) ^ 1);
        check_sprite_overlap_and_adjust(gUnk_03001800.unkDE * 4 + 0x59, gUnk_03001800.unkDE + 0x71);
    }
}

void sub_0801DC74(void) {
    if (gUnk_03000440.unk84 != 0x1E) {
        gUnk_03000440.unk84++;
        return;
    }
    clear_battle_sprite_slot(0x21, 1);
    gUnk_03002C30[0x21].unk0 = 0xC624;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x59].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unkDE * 4 + 0x59].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 6;
    gUnk_03002C30[0x21].unk8 = 0x80;
    gUnk_03002C30[0x21].unk9 = 0x80;
    gUnk_03002C30[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x1C], 0x21);
    gUnk_03001800.unkAA++;
}

void sub_0801DD30(void) {
    if (gUnk_03002C30[0x21].unk8 == 0x40) {
        play_sound_effect(0x30);
        gUnk_03001800.unkAA++;
    } else {
        gUnk_03002C30[0x21].unk8 -= 4;
        gUnk_03002C30[0x21].unk9 -= 4;
    }
}

void sub_0801DD74(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x1C], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF) {
        memcpy_bytes_0803F63C(gUnk_03000590[gUnk_03001800.unkDE - 1].medal.unkA, gUnk_03000440.unk9E, 0xE);
        gUnk_03001800.unkA6 = 0x16;
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_0801DDDC(void) {
    sub_08035928(gUnk_03001800.unk87, gUnk_03001800.unkDE);
    sub_08035944(gUnk_03001800.unk87, gUnk_03000590[gUnk_03001800.unkDE - 1].unkDE);
    gUnk_03001800.unkB5 = 1;
}

void sub_0801DE1C(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD5B0[gUnk_03001800.unkAA]();
}

void sub_0801DE44(void) {
    memcpy_bytes_0803F63C((void *)gUnk_083B6EC8[gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[2]],
                          gUnk_03000440.unk9E, 0xE);
    memcpy_bytes_0803F63C((void *)gUnk_083BE6E8[gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1]],
                          gUnk_03000440.unk9E + 0x14, 0xE);
    gUnk_03001800.unkA6 = 0x17;
    gUnk_03001800.unkAA++;
}

void sub_0801DED4(void) {
    gUnk_03001800.unkB5 = 1;
}

void sub_0801DEE4(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD5D0[gUnk_03001800.unkAA]();
}

void sub_0801DF0C(void) {
    u32 zero;
    u32 fill;

    gUnk_03000440.unk84 = 0;
    zero = 0;
    CpuFastSet(&zero, (void *)0x05000120, 0x01000008);
    fill = 0x11111111;
    CpuFastSet(&fill, (void *)0x06004120, 0x01000008);
    gUnk_03001800.unkAA++;
}

void sub_0801DF60(void) {
    write_tilemap_rect(0x1E, 1, 0, gUnk_03000440.unk84, gUnk_083B4AE0_s.unk1A4, REG_BG0CNT, 0);
    write_tilemap_rect(0x1E, 1, 0, 0x13 - gUnk_03000440.unk84, gUnk_083B4AE0_s.unk1A4, REG_BG0CNT, 0);
    if (gUnk_03000440.unk84 == 9) {
        gUnk_03001800.unk1AE = 1;
        gUnk_03001800.unkAA++;
    } else {
        gUnk_03000440.unk84++;
    }
}

void sub_0801DFE0(void) {
    switch (gUnk_03000440.unk139) {
    case 0:
        CpuFastSet((void *)0x06002800, (void *)0x02020800, 0x200);
        CpuFastSet((void *)0x0600C800, (void *)0x02021000, 0x200);
        CpuFastSet((void *)0x0600D000, (void *)0x02021800, 0x200);
        CpuFastSet((void *)0x0600D800, (void *)0x02022000, 0x200);
        gUnk_03000440.unk139++;
        break;
    case 1:
        CpuFastSet(gUnk_03002C30, (void *)0x02028000, 0x800);
        gUnk_03000440.unk139++;
        break;
    case 2:
        gVBlankCallback = nullsub_08000840;
        clear_battle_sprite_slot(0, 0x80);
        gUnk_03000440.unk139 = 0;
        gUnk_03001800.unkAA++;
        break;
    }
}

void sub_0801E09C(void) {
    u32 zero;

    switch (gUnk_03000440.unk139) {
    case 0:
        sub_08043CA8();
        REG_DISPCNT &= 0xE0FF;
        REG_BG0CNT = 0x500;
        REG_BG1CNT = 0x1801;
        REG_BG2CNT = 0x590A;
        REG_BG3CNT = 0x5B0B;
        lz_decompress_dispatch(gUnk_084C6A98, (void *)0x06017400);
        vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG1CNT, 0);
        decompress_tileset_to_vram(gUnk_03001800.unk38, 0);
        zero = 0;
        CpuFastSet(&zero, gUnk_03002C30, 0x01000800);
        gUnk_03000440.unk139++;
        break;
    case 1:
        REG_DISPCNT |= 0x1F40;
        REG_DISPCNT &= 0xFFDF;
        apply_battle_blend_effect_a();
        if (gUnk_03000590[gUnk_03001800.unk87].unkDD <= 3)
            decompress_indexed_graphics_to_ewram(gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1]);
        else
            decompress_indexed_graphics_to_ewram(gUnk_03000590[gUnk_03001800.unk87].unkA8[0] + 0x50);
        decompress_fixed_graphics_to_ewram();
        sub_08035C3C();
        gVBlankCallback = sub_08043E48;
        gUnk_03000440.unk84 = 0;
        gUnk_03000440.unk139 = 0;
        gUnk_03001800.unkAA++;
        break;
    }
}

void sub_0801E200(void) {
    u32 zero = 0;

    CpuFastSet(&zero, gUnk_03002C30, 0x01000800);
    init_battle_closeup_scene();
    init_battle_scene_backgrounds();
    sub_080361A8();
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_0801E248(void) {
    init_battle_scene_backgrounds();
    battle_advance_dialogue_text();
    battle_advance_action_text();
    vram_fill_tilemap_rect(0x1E, 1, 0, 9 - gUnk_03000440.unk84, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(0x1E, 1, 0, gUnk_03000440.unk84 + 10, REG_BG0CNT, 0);
    if (gUnk_03000440.unk84 == 9)
        gUnk_03001800.unkAA++;
    else
        gUnk_03000440.unk84++;
}

void sub_0801E2B8(void) {
    init_battle_scene_backgrounds();
    battle_advance_dialogue_text();
    battle_advance_action_text();
    gUnk_03001800.unkB5 = 1;
}

void sub_0801E2D8(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD610[gUnk_03001800.unkAA]();
}

void sub_0801E300(void) {
    u32 side;

    lz_decompress_dispatch(gUnk_084C4F00, (void *)0x06006400);
    lz_decompress_dispatch(gUnk_084882F4, (void *)0x06006520);
    lz_decompress_dispatch(gUnk_084C3648, (void *)0x06006600);
    lz_decompress_dispatch(gUnk_084C65C8, (void *)0x06006800);
    CpuFastSet(gUnk_08488B24, (void *)0x05000140, 8);
    CpuFastSet(gUnk_084E3098, (void *)0x05000100, 8);
    CpuFastSet(gUnk_084C6A58, (void *)0x05000160, 8);
    if (!(gUnk_03001800.unkF8 & 2))
        side = 1;
    else
        side = 0;
    sub_080362C4(side);
    sub_08036340(side);
    sub_08036370(side, gUnk_03001800.unk88);
    sub_080364A8(side, gUnk_03001800.unk88);
    gUnk_03001800.unkAA++;
}

void sub_0801E3C0(void) {
    gUnk_03001800.unkB9 = 0;
    if (gUnk_03001800.unkB7 & 1)
        gUnk_03001800.unkAA = 0x28;
    else if (gUnk_03001800.unkB7 & 3) {
        sub_0803628C();
        gUnk_03001800.unkAA = 10;
    } else if (gUnk_03001800.unkB8 & 2)
        gUnk_03001800.unkAA = 0x30;
    else if (gUnk_03001800.unkB8 & 4)
        gUnk_03001800.unkAA = 0x38;
    else {
        sub_08036270();
        sub_0803628C();
        gUnk_03001800.unkAA++;
    }
}

void sub_0801E43C(void) {
    if (gUnk_03000590[gUnk_03001800.unk88].unkBC & 0x40)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA = 6;
}

void sub_0801E474(void) {
    lz_decompress_dispatch(gUnk_084CC430, (void *)0x06010000);
    CpuFastSet(gUnk_0850E2D8, (void *)0x050003C0, 8);
    gUnk_03002C30[10].unk0 = 0xC404;
    gUnk_03002C30[10].unk1C = 0;
    gUnk_03002C30[10].unkA = 0xE;
    gUnk_03002C30[10].unkB = 0x80;
    gUnk_03002C30[10].unk6 = 0x1F00;
    gUnk_03002C30[10].unk23 = 0;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[10].unk2 = gUnk_03001800.unk158;
        gUnk_03002C30[10].unk4 = gUnk_03001800.unk15A;
    } else {
        gUnk_03002C30[10].unk2 = gUnk_03001800.unk154;
        gUnk_03002C30[10].unk4 = gUnk_03001800.unk156;
    }
    play_sound_effect(0x72);
    gUnk_03001800.unkAA++;
}

void sub_0801E54C(void) {
    if (sub_080353CC(10)) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0801E578(void) {
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 0x30)
        gUnk_03001800.unkAA++;
    else if (gUnk_03000590[gUnk_03001800.unk88].unkBC & 0x20)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA = 10;
}

void sub_0801E5DC(void) {
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 0x30) {
        sub_08036B84(gUnk_03001800.unk88, gUnk_03001800.unk8B);
        lz_decompress_dispatch(gUnk_084CC7C8, (void *)0x06010000);
        CpuFastSet(gUnk_0850E318, (void *)0x050003C0, 8);
        gUnk_03002C30[10].unk6 = 0x2100;
        play_sound_effect(0x54);
    } else {
        switch (gUnk_03001800.unk8B) {
        case 0:
            lz_decompress_dispatch(gUnk_084CB950, (void *)0x06010000);
            CpuFastSet(gUnk_0850E258, (void *)0x050003C0, 8);
            gUnk_03002C30[10].unk6 = 0x1B00;
            break;
        case 1:
            lz_decompress_dispatch(gUnk_084CBC10, (void *)0x06010000);
            CpuFastSet(gUnk_0850E278, (void *)0x050003C0, 8);
            gUnk_03002C30[10].unk6 = 0x1C00;
            break;
        case 2:
            lz_decompress_dispatch(gUnk_084CBF04, (void *)0x06010000);
            CpuFastSet(gUnk_0850E298, (void *)0x050003C0, 8);
            gUnk_03002C30[10].unk6 = 0x1D00;
            break;
        case 3:
            lz_decompress_dispatch(gUnk_084CC19C, (void *)0x06010000);
            CpuFastSet(gUnk_0850E2B8, (void *)0x050003C0, 8);
            gUnk_03002C30[10].unk6 = 0x1E00;
            break;
        }
        play_sound_effect(6);
    }
    gUnk_03002C30[10].unk0 = 0xC404;
    gUnk_03002C30[10].unk1C = 0;
    gUnk_03002C30[10].unkA = 0xE;
    gUnk_03002C30[10].unkB = 0x80;
    gUnk_03002C30[10].unk23 = 0;
    if (!(gUnk_03001800.unkF8 & 2)) {
        if (gUnk_03001800.unk8B == 2)
            gUnk_03002C30[10].unk2 = gUnk_03001800.unk158 - 0x10;
        else
            gUnk_03002C30[10].unk2 = gUnk_03001800.unk158;
        gUnk_03002C30[10].unk4 = gUnk_03001800.unk15A;
    } else {
        if (gUnk_03001800.unk8B == 1)
            gUnk_03002C30[10].unk2 = gUnk_03001800.unk154 + 0x10;
        else
            gUnk_03002C30[10].unk2 = gUnk_03001800.unk154;
        gUnk_03002C30[10].unk4 = gUnk_03001800.unk156;
    }
    gUnk_03001800.unkAA++;
}

void sub_0801E830(void) {
    if (sub_080366DC(10, gUnk_03001800.unk8B)) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0801E864(void) {
    u16 x, y;

    lz_decompress_dispatch(gUnk_084CC9A8, (void *)0x06010800);
    CpuFastSet(gUnk_0850E338, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    sub_08036784(10, gUnk_03001800.unk8B, x, y);
    gUnk_03001800.unkAA++;
}

void sub_0801E8DC(void) {
    CpuFastSet(gUnk_0850E338, (void *)0x050003C0, 8);
    if (sub_0803684C(10)) {
        gUnk_03000440.unk86 = 10;
        gUnk_03001800.unkAA++;
    }
}

void sub_0801E918(void) {
    u16 x, y;

    lz_decompress_dispatch(gUnk_084D1824, (void *)0x06010000);
    CpuFastSet(gUnk_0850E018, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    set_display_digit_type(&gUnk_03000440.unkEE, gUnk_03001800.unkC8, 1);
    sub_080368C4(&gUnk_03000440.unkEE, 10, gUnk_03001800.unk8B, x, y);
    play_sound_effect(0x5B);
    gUnk_03001800.unkAA++;
}

void sub_0801E9B0(void) {
    if (advance_sprite_group_anims(&gUnk_03000440.unkEE, 10)) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0801E9E0(void) {
    play_sound_effect(0x2F);
    gUnk_03001800.unkAA++;
}

void sub_0801E9FC(void) {
    u32 done;
    u32 side;

    done = sub_08036BB8(&gUnk_03001800.unkC8, gUnk_03001800.unk88, gUnk_03001800.unk8B);
    if (!(gUnk_03001800.unkF8 & 2))
        side = 1;
    else
        side = 0;
    sub_08036370(side, gUnk_03001800.unk88);
    sub_080364A8(side, gUnk_03001800.unk88);
    if (done) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0801EA5C(void) {
    if (gUnk_03001800.unkD1) {
        sub_08035194(gUnk_03001800.unk88);
        gUnk_03001800.unkAA += 3;
    } else
        gUnk_03001800.unkAA++;
}

void sub_0801EA94(void) {
    u32 side;

    if (!(gUnk_03001800.unkF8 & 2))
        side = 1;
    else
        side = 0;
    sub_08036BF4(side);
    gUnk_03001800.unkAA++;
}

void sub_0801EAC4(void) {
    gUnk_03001800.unkB5 = 1;
}

void sub_0801EAD4(void) {
    u16 x, y;

    lz_decompress_dispatch(gUnk_084CCE48, (void *)0x06010800);
    CpuFastSet(gUnk_0850E358, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    gUnk_03000440.unk86 = 0;
    sub_08036C20(10, gUnk_03001800.unk8B, x, y, 0x1E);
    gUnk_03001800.unkAA++;
}

void sub_0801EB5C(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x1E], 10);
    if (gUnk_03002C30[10].unk22 == 0xFF) {
        clear_battle_sprite_slot(10, 1);
        gUnk_03001800.unkAA++;
    }
    if (gUnk_03000440.unk86 == 0x12)
        setup_battle_medapart_scenes();
    gUnk_03000440.unk86++;
}

void sub_0801EBB8(void) {
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void sub_0801EBD4(void) {
    setup_battle_medapart_scenes();
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void sub_0801EBF8(void) {
    if (gUnk_03000590[gUnk_03001800.unk88].parts[0].unk11)
        gUnk_03001800.unkAA += 3;
    else {
        add_bot_to_defeated_list(gUnk_03001800.unk88);
        gUnk_03001800.unkAA++;
    }
}

void sub_0801EC3C(void) {
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 0x30) {
        if (--gUnk_03001800.unkEC != 0) {
            gUnk_03001800.unkAA = 0x20;
            return;
        }
    } else if ((gUnk_03000590[gUnk_03001800.unk87].unkD6 & 2 ||
                gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[7]) &&
               gUnk_03001800.unkCA != 0) {
        gUnk_03001800.unkAA = 0x20;
        return;
    }
    gUnk_03001800.unkAA++;
}

void sub_0801ECC0(void) {
    calc_bot_evasion_modifier(gUnk_03001800.unk87);
    sub_080355C4(gUnk_03001800.unk87);
    gUnk_03001800.unkD0 = gUnk_03001800.unk8B;
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 0x30)
        sub_08036B84(gUnk_03001800.unk88, gUnk_03001800.unk8B);
    else {
        if (gUnk_03000590[gUnk_03001800.unk87].unkD6 & 2)
            gUnk_03001800.unkCA += 10;
        battle_set_damage_vs_armor(gUnk_03001800.unk88, gUnk_03001800.unk8B, gUnk_03001800.unkCA);
    }
    gUnk_03001800.unkAA++;
}

void sub_0801ED50(void) {
    if (gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1] == 0x30) {
        lz_decompress_dispatch(gUnk_084CC7C8, (void *)0x06010000);
        CpuFastSet(gUnk_0850E318, (void *)0x050003C0, 8);
        gUnk_03002C30[10].unk6 = 0x2100;
        play_sound_effect(0x54);
    } else {
        lz_decompress_dispatch(gUnk_084CA61C, (void *)0x06010000);
        CpuFastSet(gUnk_0850E198, (void *)0x050003C0, 8);
        gUnk_03002C30[10].unk6 = 0x1500;
        play_sound_effect(0x2A);
    }
    gUnk_03002C30[10].unk0 = 0xC404;
    gUnk_03002C30[10].unk1C = 0;
    gUnk_03002C30[10].unkA = 0xE;
    gUnk_03002C30[10].unkB = 0x80;
    gUnk_03002C30[10].unk23 = 0;
    if (!(gUnk_03001800.unkF8 & 2)) {
        if (gUnk_03001800.unk8B == 2)
            gUnk_03002C30[10].unk2 = gUnk_03001800.unk158 - 0x10;
        else
            gUnk_03002C30[10].unk2 = gUnk_03001800.unk158;
        gUnk_03002C30[10].unk4 = gUnk_03001800.unk15A;
    } else {
        if (gUnk_03001800.unk8B == 1)
            gUnk_03002C30[10].unk2 = gUnk_03001800.unk154 + 0x10;
        else
            gUnk_03002C30[10].unk2 = gUnk_03001800.unk154;
        gUnk_03002C30[10].unk4 = gUnk_03001800.unk156;
    }
    gUnk_03001800.unkAA++;
}

void sub_0801EED4(void) {
    gUnk_03001800.unkAA = 10;
}

void sub_0801EEE4(void) {
    lz_decompress_dispatch(gUnk_084CA428, (void *)0x06010000);
    CpuFastSet(gUnk_0850E178, (void *)0x050003C0, 8);
    gUnk_03002C30[10].unk0 = 0xC404;
    gUnk_03002C30[10].unk1C = 0;
    gUnk_03002C30[10].unkA = 0xE;
    gUnk_03002C30[10].unkB = 0x80;
    gUnk_03002C30[10].unk6 = 0x1400;
    gUnk_03002C30[10].unk23 = 0;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[10].unk2 = gUnk_03001800.unk158;
        gUnk_03002C30[10].unk4 = gUnk_03001800.unk15A - 0x10;
        gUnk_03002C30[10].unk30 = gUnk_03001800.unk15A;
    } else {
        gUnk_03002C30[10].unk2 = gUnk_03001800.unk154;
        gUnk_03002C30[10].unk4 = gUnk_03001800.unk156 - 0x10;
        gUnk_03002C30[10].unk30 = gUnk_03001800.unk156;
    }
    play_sound_effect(0x2F);
    gUnk_03001800.unkAA++;
}

void sub_0801EFC8(void) {
    if (gFrameCounter & 1) {
        gUnk_03002C30[10].unk4++;
        if (gUnk_03002C30[10].unk4 == gUnk_03002C30[10].unk30) {
            gUnk_03000440.unk86 = 0x3C;
            gUnk_03001800.unkAA++;
        }
    }
}

void sub_0801F018(void) {
    lz_decompress_dispatch(gUnk_084CC5F8, (void *)0x06010000);
    CpuFastSet(gUnk_0850E2F8, (void *)0x050003C0, 8);
    gUnk_03002C30[10].unk0 = 0xC404;
    gUnk_03002C30[10].unk1C = 0;
    gUnk_03002C30[10].unkA = 0xE;
    gUnk_03002C30[10].unkB = 0x80;
    gUnk_03002C30[10].unk6 = 0x2000;
    gUnk_03002C30[10].unk23 = 0;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[10].unk2 = gUnk_03001800.unk158;
        gUnk_03002C30[10].unk4 = gUnk_03001800.unk15A;
    } else {
        gUnk_03002C30[10].unk2 = gUnk_03001800.unk154;
        gUnk_03002C30[10].unk4 = gUnk_03001800.unk156;
    }
    play_sound_effect(0x2A);
    gUnk_03001800.unkAA++;
}

void decompress_sprite_tiles_to_vram_obj_0(void) {
    lz_decompress_dispatch(gUnk_084D18EC, (void *)0x06010000);
    CpuFastSet(gUnk_0850E498, (void *)0x050003C0, 8);
    gUnk_03002C30[10].unk0 = 0xC404;
    gUnk_03002C30[10].unk1C = 0;
    gUnk_03002C30[10].unkA = 0xE;
    gUnk_03002C30[10].unkB = 0x80;
    gUnk_03002C30[10].unk6 = 0x2E00;
    gUnk_03002C30[10].unk23 = 0;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03002C30[10].unk2 = gUnk_03001800.unk158;
        gUnk_03002C30[10].unk4 = gUnk_03001800.unk15A;
    } else {
        gUnk_03002C30[10].unk2 = gUnk_03001800.unk154;
        gUnk_03002C30[10].unk4 = gUnk_03001800.unk156;
    }
    play_sound_effect(0x2A);
    gUnk_03001800.unkAA++;
}

void battle_resolve_action_target(void) {
    u32 part = find_most_damaged_part(gUnk_03001800.unk88);

    if (part) {
        gUnk_03001800.unk8B = gUnk_03001800.unkD0 = part - 1;
        battle_calc_damage_split(gUnk_03001800.unk88, gUnk_03001800.unkD0, gUnk_03001800.unkEC);
        gUnk_03001800.unkAA = 0x3E;
    } else
        gUnk_03001800.unkAA++;
}

void decompress_sprite_tiles_to_vram_obj_800(void) {
    u16 x, y;

    lz_decompress_dispatch(gUnk_084CDCD4, (void *)0x06010800);
    CpuFastSet(gUnk_0850E398, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    sub_08036C20(10, gUnk_03001800.unk8B, x, y, 0x20);
    gUnk_03001800.unkAA++;
}

void start_battle_transition_anim(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x20], 10);
    if (gUnk_03002C30[10].unk22 == 0xFF) {
        clear_battle_sprite_slot(10, 1);
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void decompress_sprite_tiles_to_vram_obj_0_alt(void) {
    u16 x, y;

    lz_decompress_dispatch(gUnk_084D1824, (void *)0x06010000);
    CpuFastSet(gUnk_0850DFF8, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    set_display_digit_type(&gUnk_03000440.unkEE, gUnk_03001800.unkC8, 0);
    sub_080368C4(&gUnk_03000440.unkEE, 10, gUnk_03001800.unk8B, x, y);
    play_sound_effect(0x5B);
    gUnk_03001800.unkAA++;
}

void sub_0801F374(void) {
    play_sound_effect(0x2E);
    gUnk_03001800.unkAA++;
}

void sub_0801F390(void) {
    u32 done;
    u32 side;

    done = battle_check_action_counter(&gUnk_03001800.unkC8, gUnk_03001800.unk88, gUnk_03001800.unk8B);
    if (!(gUnk_03001800.unkF8 & 2))
        side = 1;
    else
        side = 0;
    sub_08036370(side, gUnk_03001800.unk88);
    sub_080364A8(side, gUnk_03001800.unk88);
    if (done) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_0801F3F0(void) {
    u32 part;
    struct Unk_03001800 *s;

    if ((gUnk_03000590[(s = &gUnk_03001800)->unk87].unkD6 & 2 || gUnk_03000590[s->unk87].parts[s->unkA7].data[7]) &&
        s->unkCA && (part = find_most_damaged_part(s->unk88))) {
        part--;
        s->unkD0 = part;
        s->unk8B = part;
        battle_calc_damage_split(s->unk88, s->unkD0, s->unkCA);
        s->unkAA = 0x4A;
    } else {
        s->unkAA++;
    }
}

void sub_0801F474(void) {
    gUnk_03001800.unkAA = 0x3E;
}

void sub_0801F484(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD750[gUnk_03001800.unkAA]();
}

void sub_0801F4AC(void) {
    struct Unk_03001800 *s = &gUnk_03001800;
    u8 skill;

    if (s->unkB7 & 1)
        s->unkAA++;
    else if (s->unkB8 & 2)
        s->unkAA++;
    else if (s->unkB8 & 4)
        s->unkAA++;
    else if (!gUnk_03000590[s->unk88].parts[0].unk11)
        s->unkAA++;
    else if (!sub_080331F8(s->unk88))
        s->unkAA++;
    else if (sub_08036D64(s->unk88, gUnk_03000590[s->unk87].parts[s->unkA7].data[1]))
        s->unkAA++;
    else {
        skill = gUnk_03000590[s->unk87].parts[s->unkA7].data[1];
        if (skill == 0xD)
            goto s0;
        if (skill != 0xE)
            goto c1;
    s0:
        s->unk51 = 0;
        s->unkAA = 2;
        return;
    c1:
        if (skill == 0xF)
            goto s1;
        if (skill != 0x10)
            goto c2;
    s1:
        s->unk51 = 1;
        s->unkAA = 2;
        return;
    c2:
        if (skill == 0x11)
            goto s2;
        if (skill != 0x12)
            goto c3;
    s2:
        s->unk51 = 2;
        s->unkAA = 2;
        return;
    c3:
        if (skill == 0x13)
            goto s3;
        if (skill != 0x14)
            goto nx;
    s3:
        s->unk51 = 3;
        s->unkAA = 2;
        return;
    nx:
        s->unkAA++;
    }
}

void sub_0801F5AC(void) {
    gUnk_03001800.unkB5 = 1;
}

void sub_0801F5BC(void) {
    u16 x, y;

    lz_decompress_dispatch(gUnk_084CA89C, (void *)0x06010000);
    CpuFastSet(gUnk_0850E1B8, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    gUnk_03002C30[10].unk0 = 0xC624;
    gUnk_03002C30[10].unk1C = 0;
    gUnk_03002C30[10].unk2 = x;
    gUnk_03002C30[10].unk4 = y;
    gUnk_03002C30[10].unk8 = 0x40;
    gUnk_03002C30[10].unk9 = 4;
    gUnk_03002C30[10].unkA = 0xE;
    gUnk_03002C30[10].unkB = 0xF0;
    gUnk_03002C30[10].unk6 = 0x1600;
    gUnk_03002C30[10].unk20 = 0;
    switch (gUnk_03001800.unk51) {
    case 0:
        lz_decompress_dispatch(gUnk_084CE154, (void *)0x06010800);
        CpuFastSet(gUnk_0850E3B8, (void *)0x050003A0, 8);
        break;
    case 1:
        lz_decompress_dispatch(gUnk_084CE644, (void *)0x06010800);
        CpuFastSet(gUnk_0850E3D8, (void *)0x050003A0, 8);
        break;
    case 2:
        lz_decompress_dispatch(gUnk_084CEF14, (void *)0x06010800);
        CpuFastSet(gUnk_0850E3F8, (void *)0x050003A0, 8);
        break;
    case 3:
        lz_decompress_dispatch(gUnk_084CF340, (void *)0x06010800);
        CpuFastSet(gUnk_0850E418, (void *)0x050003A0, 8);
        break;
    }
    gUnk_03002C30[11].unk0 = 0xC404;
    gUnk_03002C30[11].unk1C = 0;
    gUnk_03002C30[11].unk2 = x;
    gUnk_03002C30[11].unk4 = y;
    gUnk_03002C30[11].unkA = 0xD;
    gUnk_03002C30[11].unkB = 0x80;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x21], 11);
    play_sound_effect(0x2F);
    gUnk_03001800.unkAA++;
}

void sub_0801F780(void) {
    if (gUnk_03002C30[10].unk20 == 0) {
        if ((gUnk_03002C30[10].unk9 += 4) == 0x80)
            gUnk_03002C30[10].unk20 = 1;
    } else if (gUnk_03002C30[10].unk9 != 0x40)
        gUnk_03002C30[10].unk9 -= 4;
    process_sprite_anim_commands(gUnk_083B5F80[0x21], 11);
    if (gUnk_03002C30[11].unk22 == 0xFF) {
        clear_battle_sprite_slot(10, 2);
        gUnk_03001800.unkAA++;
    }
}

void sub_0801F800(void) {
    u16 x, y;
    s16 sx, sy;

    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158 - 4;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154 + 4;
        y = gUnk_03001800.unk156;
    }
    switch (gUnk_03001800.unk51) {
    case 0:
        lz_decompress_dispatch(gUnk_084CAB58, (void *)0x06010000);
        CpuFastSet(gUnk_0850E1D8, (void *)0x050003C0, 8);
        break;
    case 1:
        lz_decompress_dispatch(gUnk_084CAFD8, (void *)0x06010000);
        CpuFastSet(gUnk_0850E1F8, (void *)0x050003C0, 8);
        break;
    case 2:
        lz_decompress_dispatch(gUnk_084CB36C, (void *)0x06010000);
        CpuFastSet(gUnk_0850E218, (void *)0x050003C0, 8);
        break;
    case 3:
        lz_decompress_dispatch(gUnk_084CB684, (void *)0x06010000);
        CpuFastSet(gUnk_0850E238, (void *)0x050003C0, 8);
        break;
    }
    sx = x;
    sy = y;
    gUnk_03002C30[10].unk0 = 0xC404;
    gUnk_03002C30[10].unk1C = 0;
    gUnk_03002C30[10].unk2 = sx - 0x10;
    gUnk_03002C30[10].unk4 = sy - 8;
    gUnk_03002C30[10].unkA = 0xE;
    gUnk_03002C30[10].unkB = 0x80;
    gUnk_03002C30[10].unk6 = 0x1700;
    gUnk_03002C30[11].unk0 = 0xC404;
    gUnk_03002C30[11].unk1C = 0;
    gUnk_03002C30[11].unk2 = sx + 0x10;
    gUnk_03002C30[11].unk4 = sy + 8;
    gUnk_03002C30[11].unkA = 0xE;
    gUnk_03002C30[11].unkB = 0x80;
    gUnk_03002C30[11].unk6 = 0x1701;
    gUnk_03001800.unkAA++;
}

void sub_0801F9B0(void) {
    medal_update_exp_progress(10, 0);
    if (medal_update_exp_progress(11, 1)) {
        play_sound_effect(0x2A);
        gUnk_03000440.unk86 = 0x5A;
        gUnk_03001800.unkAA++;
    }
}

void sub_0801F9EC(void) {
    battle_set_action_params(gUnk_03001800.unk88, gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1],
                             gUnk_03001800.unkE8, gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void sub_0801FA40(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD794[gUnk_03001800.unkAA]();
}

void sub_0801FA68(void) {
    u32 zero;
    u32 fill;

    init_battle_scene_backgrounds();
    gUnk_03001800.unk15F = battle_advance_dialogue_text();
    gUnk_03001800.unk160 = battle_advance_action_text();
    gUnk_03000440.unk84 = 0;
    zero = 0;
    CpuFastSet(&zero, (void *)0x05000120, 0x01000008);
    fill = 0x11111111;
    CpuFastSet(&fill, (void *)0x06004120, 0x01000008);
    gUnk_03001800.unkAA++;
}

void sub_0801FADC(void) {
    u32 v;

    init_battle_scene_backgrounds();
    gUnk_03001800.unk15F = battle_advance_dialogue_text();
    gUnk_03001800.unk160 = battle_advance_action_text();
    write_tilemap_rect(0x1E, 1, 0, gUnk_03000440.unk84, gUnk_083B4AE0_s.unk1A4, REG_BG0CNT, 0);
    write_tilemap_rect(0x1E, 1, 0, 0x13 - gUnk_03000440.unk84, gUnk_083B4AE0_s.unk1A4, REG_BG0CNT, 0);
    if (gUnk_03000440.unk84 == 9) {
        v = 0x200;
        CpuFastSet(&v, gUnk_03002414->unkB84, 0x01000100);
        gUnk_03002414->unk1094 = 0;
        gUnk_03002414->unk1095 = 0;
        gVBlankCallback = nullsub_08000840;
        gUnk_03001800.unkAA++;
    } else {
        gUnk_03000440.unk84++;
    }
}

void sub_0801FBC4(void) {
    switch (gUnk_03000440.unk139) {
    case 0:
        gUnk_03000440.unk96 = 0;
        gUnk_03000430 = 0;
        sub_08043CA8();
        load_battle_script_entry_b();
        REG_DISPCNT &= 0xF0FF;
        REG_BG0CNT = 0x500;
        REG_BG1CNT = 0x1901;
        REG_BG2CNT = 0x1A0A;
        REG_BG3CNT = 0x1B0B;
        if (battle_load_graphics_step(1)) {
            gUnk_03000440.unk84 = 0;
            gUnk_03000440.unk139++;
        }
        break;
    case 1:
        REG_DISPCNT |= 0x1F40;
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
        apply_battle_blend_effect_b();
        decompress_to_ewram_27000(gUnk_083B24A8[gUnk_03001800.unk38 * 5 + 1]);
        gUnk_03000440.unk139++;
        break;
    case 2:
        CpuFastSet((void *)0x02021000, (void *)0x0600C800, 0x200);
        CpuFastSet((void *)0x02021800, (void *)0x0600D000, 0x200);
        CpuFastSet((void *)0x02022000, (void *)0x0600D800, 0x200);
        gUnk_03000440.unk139++;
        break;
    case 3:
        CpuFastSet((void *)0x02028000, gUnk_03002C30, 0x800);
        gUnk_03000440.unk139++;
        break;
    case 4:
        load_all_bot_part_sprites();
        iterate_bots_setup_battle_sprites();
        gVBlankCallback = battle_vblank_update_bg;
        gUnk_03000440.unk84 = 0;
        gUnk_03001800.unk1AE = 0;
        gUnk_03001800.unkAA++;
        gUnk_03000440.unk139 = 0;
        break;
    }
}

void sub_0801FD88(void) {
    vram_fill_tilemap_rect(0x1E, 1, 0, 9 - gUnk_03000440.unk84, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(0x1E, 1, 0, gUnk_03000440.unk84 + 10, REG_BG0CNT, 0);
    if (gUnk_03000440.unk84 == 9)
        gUnk_03001800.unkAA++;
    else
        gUnk_03000440.unk84++;
}

void sub_0801FDEC(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD7D4[gUnk_03001800.unkAA]();
}

void sub_0801FE14(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unkE0[i]) {
            gUnk_03001800.unk51 = gUnk_03001800.unkE0[i] - 1;
            gUnk_03001800.unkE0[i] = 0;
            load_all_bot_part_sprites();
            iterate_bots_setup_battle_sprites();
            reset_battle_bot_state(gUnk_03001800.unk51);
            gUnk_03001800.unkAA = 2;
            return;
        }
    }
    gUnk_03001800.unkAA++;
}

void sub_0801FE64(void) {
    lz_decompress_dispatch(gUnk_084CDBD8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E378, (void *)0x050002E0, 8);
    setup_battle_cursor_sprite_08036FF8(0x21, gUnk_03002C30[gUnk_03001800.unk51 * 4 + 0x5D].unk2,
                                        gUnk_03002C30[gUnk_03001800.unk51 * 4 + 0x5D].unk4 - 4, 8);
    gUnk_03001800.unkAA++;
}

void sub_0801FEC8(void) {
    if (update_sprite_animations_tick_080370AC(0x21, 8))
        gUnk_03001800.unkAA++;
}

void sub_0801FEE8(void) {
    lz_decompress_dispatch(gUnk_084CC9A8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E338, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC004;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk51 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk51 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x22], 0x21);
    gUnk_03001800.unkAA++;
}

void sub_0801FF9C(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x22], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        clear_sprite_table_mask(0x5A + gUnk_03001800.unk51 * 4, 4);
        clear_sprite_table_mask(gUnk_03001800.unk51 + 0x72, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_08020004(void) {
    memcpy_bytes_0803F63C(gUnk_03000590[gUnk_03001800.unk51].medal.unkA, gUnk_03000440.unk9E, 0xE);
    gUnk_03001800.unkA6 = 0x14;
    gUnk_03001800.unkAA++;
}

void sub_08020040(void) {
    gUnk_03001800.unkAA = 0;
}

void sub_08020050(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD814[gUnk_03001800.unkAA]();
}

void sub_08020078(void) {
    if (gUnk_03001800.unkF6 & 1) {
        gUnk_03001800.unkAA = 2;
    } else {
        gUnk_03001800.unkAB = 0;
        gUnk_03001800.unkAA++;
    }
}

void sub_080200A8(void) {
    u16 x, y;

    lz_decompress_dispatch(gUnk_084CA1A4, (void *)0x06010000);
    CpuFastSet(gUnk_0850E158, (void *)0x050003C0, 8);
    lz_decompress_dispatch(gUnk_084D1074, (void *)0x06010800);
    CpuFastSet(gUnk_0850E478, (void *)0x050003A0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    gUnk_03002C30[10].unk0 = 0xC404;
    gUnk_03002C30[10].unk1C = 0;
    gUnk_03002C30[10].unk2 = x;
    gUnk_03002C30[10].unk4 = y;
    gUnk_03002C30[10].unkA = 0xE;
    gUnk_03002C30[10].unkB = 0x80;
    gUnk_03002C30[10].unk6 = 0x1300;
    gUnk_03002C30[10].unk2B = 0;
    gUnk_03002C30[10].unk2C = 0;
    gUnk_03002C30[11].unk0 = 0xC404;
    gUnk_03002C30[11].unk1C = 0;
    gUnk_03002C30[11].unk2 = x;
    gUnk_03002C30[11].unk4 = y;
    gUnk_03002C30[11].unkA = 0xD;
    gUnk_03002C30[11].unkB = 0x80;
    gUnk_03002C30[11].unk6 = 0x2C00;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x37], 11);
    play_sound_effect(0x53);
    gUnk_03001800.unkAA++;
}

void sub_080201DC(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x37], 11);
    if (gUnk_03002C30[10].unk2B == 0x28) {
        clear_battle_sprite_slot(11, 1);
        gUnk_03001800.unkAA++;
    } else {
        gUnk_03002C30[10].unk2C++;
        if (gUnk_03002C30[10].unk2C & 1) {
            gUnk_03002C30[10].unk4--;
            gUnk_03002C30[10].unk2B++;
        }
    }
}

void sub_08020248(void) {
    if (gUnk_03001800.unkB7 == 3) {
        sub_0803713C();
        clear_battle_sprite_slot(10, 1);
        gUnk_03001800.unkAB = 1;
        gUnk_03001800.unkAA++;
    } else {
        gUnk_03001800.unkAA = 6;
    }
}

void sub_08020288(void) {
    lz_decompress_dispatch(gUnk_084CA428, (void *)0x06010000);
    CpuFastSet(gUnk_0850E178, (void *)0x050003C0, 8);
    gUnk_03002C30[10].unk2B = 0;
    gUnk_03002C30[10].unk2C = 0;
    play_sound_effect(0x2F);
    gUnk_03001800.unkAA++;
}

void sub_080202E0(void) {
    if (gUnk_03002C30[10].unk2B == 0x28) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAB = 0;
        gUnk_03001800.unkAA++;
    } else {
        gUnk_03002C30[10].unk2C++;
        gUnk_03002C30[10].unk4++;
        gUnk_03002C30[10].unk2B++;
    }
}

void sub_08020340(void) {
    if (gUnk_03001800.unkB8 == 2)
        gUnk_03001800.unkAA = 0xB;
    else if (gUnk_03001800.unkB8 == 4)
        gUnk_03001800.unkAA = 0xF;
    else
        gUnk_03001800.unkAA++;
}

void sub_0802036C(void) {
    u16 x, y;

    lz_decompress_dispatch(gUnk_084D01EC, (void *)0x06010800);
    CpuFastSet(gUnk_0850E438, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    gUnk_03002C30[10].unk0 = 0xC404;
    gUnk_03002C30[10].unk1C = 0;
    gUnk_03002C30[10].unk2 = x;
    gUnk_03002C30[10].unk4 = y;
    gUnk_03002C30[10].unkA = 0xE;
    gUnk_03002C30[10].unkB = 0x80;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x25], 10);
    play_sound_effect(0x37);
    gUnk_03001800.unkAA++;
}

void sub_08020428(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x25], 10);
    if (gUnk_03002C30[10].unk22 == 0xFF) {
        gUnk_03000440.unk86 = 0x3C;
        clear_battle_sprite_slot(10, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_08020474(void) {
    u16 x, y;

    lz_decompress_dispatch(gUnk_084D073C, (void *)0x06010800);
    CpuFastSet(gUnk_0850E458, (void *)0x050003C0, 8);
    if (!(gUnk_03001800.unkF8 & 2)) {
        x = gUnk_03001800.unk158;
        y = gUnk_03001800.unk15A;
    } else {
        x = gUnk_03001800.unk154;
        y = gUnk_03001800.unk156;
    }
    gUnk_03002C30[10].unk0 = 0xC404;
    gUnk_03002C30[10].unk1C = 0;
    gUnk_03002C30[10].unk2 = x;
    gUnk_03002C30[10].unk4 = y;
    gUnk_03002C30[10].unkA = 0xE;
    gUnk_03002C30[10].unkB = 0x80;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x26], 10);
    play_sound_effect(0x2B);
    gUnk_03001800.unkAA++;
}

void sub_08020530(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x26], 10);
    if (gUnk_03002C30[10].unk22 == 0xFF) {
        gUnk_03000440.unk86 = 0x3C;
        clear_battle_sprite_slot(10, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_0802057C(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD878[gUnk_03001800.unkAA]();
}

void sub_080205A4(void) {
    lz_decompress_dispatch(gUnk_084CDBD8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E378, (void *)0x050002E0, 8);
    setup_battle_cursor_sprite_08036FF8(0x21, gUnk_03002C30[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkA7].unk2,
                                        gUnk_03002C30[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkA7].unk4, 4);
    gUnk_03001800.unkAA++;
}

void sub_08020608(void) {
    if (update_sprite_animations_tick_080370AC(0x21, 4))
        gUnk_03001800.unkAA++;
}

void sub_08020628(void) {
    lz_decompress_dispatch(gUnk_084CC9A8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E338, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC004;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkA7].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[0x5A + gUnk_03001800.unk87 * 4 + gUnk_03001800.unkA7].unk4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x22], 0x21);
    gUnk_03001800.unkAA++;
}

void sub_080206E8(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x22], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_08020728(void) {
    reduce_bot_part_stat(gUnk_03001800.unk87, gUnk_03001800.unkA7, 0xFF);
    load_all_bot_part_sprites();
    iterate_bots_setup_battle_sprites();
    if (gUnk_03001800.unkA7 == 0)
        add_bot_to_defeated_list(gUnk_03001800.unk87);
    gUnk_03001800.unkAA++;
}

void sub_08020768(void) {
    memcpy_bytes_0803F63C(gUnk_083C6DE8[gUnk_03001800.unkA7], gUnk_03000440.unk9E, 0xE);
    gUnk_03001800.unkA6 = 0x18;
    gUnk_03001800.unkAA++;
}

void sub_080207A4(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD898[gUnk_03001800.unkAA]();
}

void sub_080207CC(void) {
    if (gUnk_03000590[gUnk_03001800.unk88].unkBD & 4) {
        gUnk_03001800.unkAA++;
        gUnk_03001800.unkAB = 0;
    } else {
        gUnk_03001800.unkA6 = 0x19;
        gUnk_03001800.unkAA = 2;
        gUnk_03001800.unkAB = 1;
    }
}

void sub_0802081C(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD8B8[gUnk_03001800.unkAA]();
}

void sub_08020844(void) {
    u32 r;

    if (!sub_08037230(gUnk_03001800.unk88, gUnk_03001800.unk8B)) {
        calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
        r = decrement_battle_timer_and_check_zero();
        if (r) {
            gUnk_03001800.unkA6 = 0x1A;
            gUnk_03001800.unkAA = 2;
            gUnk_03001800.unkAB = 1;
        } else {
            calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
            sub_08036270();
            gUnk_03001800.unkAA++;
            gUnk_03001800.unkAB = r;
        }
    } else {
        gUnk_03001800.unkA6 = 0x26;
        gUnk_03001800.unkAA = 2;
        gUnk_03001800.unkAB = 1;
    }
}

void sub_080208C0(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083AD8D8[gUnk_03001800.unkAA]();
}

void sub_080208E8(void) {
    clear_battle_sprite_slot(0, 0x80);
    gUnk_03001800.unkD0 = gUnk_03001800.unk8B;
    battle_calc_damage_split(gUnk_03001800.unk88, gUnk_03001800.unkD0, gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void sub_08020928(void) {
    u32 part;
    struct Unk_03001800 *s;

    if (gUnk_03000590[gUnk_03001800.unk87].parts[(s = &gUnk_03001800)->unkA7].data[7] && s->unkCA &&
        (part = find_most_damaged_part(s->unk88))) {
        part--;
        s->unkD0 = part;
        s->unk8B = part;
        battle_calc_damage_split(s->unk88, s->unkD0, s->unkCA);
        s->unkAA = 0xE;
    } else {
        s->unkAA++;
    }
}

void sub_080209A0(void) {
    gUnk_03001800.unkAA = 2;
}
