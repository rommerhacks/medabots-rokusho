// Effect sequences of the Support abilities: action script opcodes 0x30-0x35, used by abilities 36, 37,
// 38, 39, 41 and 42.
// Each runner (sub_XXXXXXXX that clears unkB5 and calls entry [unkAA] of its gUnk_083AD400 sub-table) is
// one action script command (gUnk_083AF000, opcode order = ROM order); its step handlers follow it and
// the last step sets unkB5. Abilities are part data[1], and the script of ability n is gUnk_083C6B28[n].

#include "global.h"

void sub_08022FF0(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083ADC6C[gUnk_03001800.unkAA]();
}

void sub_08023018(void) {
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    } else {
        sub_08036270();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void sub_0802306C(void) {
    lz_decompress_dispatch(gUnk_084D5D78, (void *)0x06014800);
    CpuFastSet(gUnk_0850E778, (void *)0x050002C0, 0x10);
    gUnk_03001800.unkAA++;
}

void sub_080230A4(void) {
    copy_obj_palette_to_buffer();
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_080230C8(void) {
    blend_obj_palettes_to_color_0803F684(0x1084, gUnk_03000440.unk84, 0xFFFF);
    blend_obj_palettes_to_color_0803F998(0x1084, gUnk_03000440.unk84, 0xFF00);
    if (gUnk_03000440.unk84 == 0x10)
        gUnk_03001800.unkAA++;
    else
        gUnk_03000440.unk84++;
}

void sub_08023118(void) {
    gUnk_03002C30[0x21].unk0 = 0xC604;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 6;
    gUnk_03002C30[0x21].unkB = 0xF0;
    gUnk_03002C30[0x21].unk6 = 0x4800;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unk2D = 0;
    play_sound_effect(0x4C);
    gUnk_03001800.unkAA++;
}

void sub_080231D4(void) {
    if (gUnk_03002C30[0x21].unk2D == 0x40) {
        clear_battle_sprite_slot(0x21, 2);
        gUnk_03001800.unkAA++;
    } else {
        gUnk_03002C30[0x21].unk2D++;
        gUnk_03002C30[0x21].unk18 = (gUnk_03002C30[0x21].unk18 + 0x10) & 0x3FF;
    }
}

void sub_08023224(void) {
    blend_obj_palettes_to_color_0803F684(0x1084, gUnk_03000440.unk84, 0xFFFF);
    blend_obj_palettes_to_color_0803F998(0x1084, gUnk_03000440.unk84, 0xFF00);
    if (gUnk_03000440.unk84 == 0)
        gUnk_03001800.unkAA++;
    else
        gUnk_03000440.unk84--;
}

void sub_08023274(void) {
    u32 i;
    u32 first = sub_08032FC4(gUnk_03001800.unk87);

    for (i = 0; i < 3; i++) {
        if (gUnk_03000590[first + i].unk40) {
            gUnk_03002C30[0x21 + i].unk0 = 0xC624;
            gUnk_03002C30[0x21 + i].unk1C = 0;
            gUnk_03002C30[0x21 + i].unk2 = gUnk_03002C30[(first + i) * 4 + 0x5D].unk2;
            gUnk_03002C30[0x21 + i].unk4 = gUnk_03002C30[(first + i) * 4 + 0x5D].unk4;
            gUnk_03002C30[0x21 + i].unkA = 7;
            gUnk_03002C30[0x21 + i].unkB = 0xF0;
            gUnk_03002C30[0x21 + i].unk8 = 0x40;
            gUnk_03002C30[0x21 + i].unk9 = 0x40;
            gUnk_03002C30[0x21 + i].unk6 = 0x4801;
        }
    }
    gUnk_03000440.unk86 = 0;
    play_sound_effect(0x2E);
    gUnk_03001800.unkAA++;
}

void sub_08023328(void) {
    u32 i;

    if (gUnk_03000440.unk86 == 0x14) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    } else {
        gUnk_03000440.unk86++;
        for (i = 0; i < 3; i++) {
            if (gUnk_03002C30[0x21 + i].unk0 & 0x8000)
                gUnk_03002C30[0x21 + i].unk4--;
        }
    }
}

void sub_08023384(void) {
    u32 i;

    for (i = 0; i < 3; i++) {
        if (gUnk_03002C30[0x21 + i].unk0 & 0x8000) {
            gUnk_03002C30[0x21 + i].unk8 -= 8;
            gUnk_03002C30[0x21 + i].unk9 += 8;
        }
    }
    if (gUnk_03002C30[0x21].unk8 == 8) {
        clear_battle_sprite_slot(0x21, 3);
        gUnk_03001800.unkAA++;
    }
}

void sub_080233E0(void) {
    sub_08035740(&gUnk_03001800.unk28[gUnk_03001800.unk89].unk0, gUnk_03001800.unkEC, 0xA0);
    gUnk_03001800.unkAA++;
}

void sub_08023414(void) {
    gUnk_03001800.unkA6 = 0x1C;
    gUnk_03001800.unkAA++;
}

void sub_0802342C(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083ADCC0[gUnk_03001800.unkAA]();
}

void sub_08023454(void) {
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    } else {
        sub_08036270();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void sub_080234A8(void) {
    lz_decompress_dispatch(gUnk_084D5EBC, (void *)0x06014800);
    CpuFastSet(gUnk_0850E7B8, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC404;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x40], 0x21);
    play_sound_effect(0x4D);
    gUnk_03001800.unkAA++;
}

void sub_08023564(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x40], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF) {
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_080235AC(void) {
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x41], 0x21);
    play_sound_effect(0x4D);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_080235E8(void) {
    gUnk_03000440.unk84++;
    sub_08037330(gUnk_03001800.unk87, gUnk_03000440.unk84, 2);
    process_sprite_anim_commands(gUnk_083B5F80[0x41], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03000440.unk86 = 0x3C;
        gUnk_03001800.unkAA++;
    }
}

void sub_08023658(void) {
    gUnk_03000440.unk84++;
    sub_08037330(gUnk_03001800.unk87, gUnk_03000440.unk84, 2);
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1)) {
        sub_080373D4(gUnk_03001800.unk87);
        gUnk_03001800.unkAA++;
    } else if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else {
        sub_080373D4(gUnk_03001800.unk87);
        gUnk_03001800.unkAA++;
    }
}

void sub_080236E0(void) {
    sub_08035740(&gUnk_03000590[gUnk_03001800.unk87].unkB8 + 1, gUnk_03001800.unkEC, 0x78);
    gUnk_03001800.unkAA++;
}

void sub_08023718(void) {
    gUnk_03001800.unkA6 = 0x1D;
    gUnk_03001800.unkAA++;
}

void sub_08023730(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083ADD20[gUnk_03001800.unkAA]();
}

void sub_08023758(void) {
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    } else if (sub_080331F8(gUnk_03001800.unk88) == 0) {
        gUnk_03001800.unkA6 = 0x39;
        gUnk_03001800.unkAA++;
    } else {
        sub_08036270();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void sub_080237C8(void) {
    lz_decompress_dispatch(gUnk_084D6098, (void *)0x06014800);
    CpuFastSet(gUnk_0850E7D8, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 |= 0x220;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unk30 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk32 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unk24 = 6;
    gUnk_03000440.unk84 = 0x42;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x42], 0x21);
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void sub_080238A0(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03000440.unk84], 0x21);
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03001800.unkAA++;
    else if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else
        gUnk_03001800.unkAA++;
}

void sub_08023900(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03000440.unk84], 0x21);
    if (!(gUnk_03001800.unkF8 & 1))
        gUnk_03002C30[0x21].unk18 = (gUnk_03002C30[0x21].unk18 - 0x40) & 0x3FF;
    else
        gUnk_03002C30[0x21].unk18 = (gUnk_03002C30[0x21].unk18 + 0x40) & 0x3FF;
    if (move_sprite_toward_target(0x21)) {
        gUnk_03002C30[0x21].unk18 = 0;
        gUnk_03001800.unkAA++;
    }
}

void sub_08023988(void) {
    gUnk_03000440.unk84 = 0x43;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x43], 0x21);
    play_sound_effect(0x4E);
    gUnk_03001800.unkAA++;
}

void sub_080239C0(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03000440.unk84], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
        gUnk_03001800.unkAA++;
}

void sub_08023A04(void) {
    if (gUnk_03002C30[0x21].unk8 == 8) {
        clear_battle_sprite_slot(0x21, 1);
        gUnk_03001800.unkAA++;
    } else {
        gUnk_03002C30[0x21].unk8 -= 8;
        gUnk_03002C30[0x21].unk9 += 8;
    }
}

void sub_08023A48(void) {
    gUnk_03000590[gUnk_03001800.unk88].unkC4 = 0x26;
    gUnk_03000590[gUnk_03001800.unk88].unkC5 = 0;
    gUnk_03000590[gUnk_03001800.unk88].unkC6 = sub_08036E54(gUnk_03001800.unkE8);
    gUnk_03000590[gUnk_03001800.unk88].unkC7 = sub_08036E54(gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void sub_08023AB0(void) {
    gUnk_03001800.unkA6 = 0x2C;
    gUnk_03001800.unkAA++;
}

void sub_08023AC8(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083ADD80[gUnk_03001800.unkAA]();
}

void sub_08023AF0(void) {
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    } else {
        sub_08036270();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void sub_08023B44(void) {
    lz_decompress_dispatch(gUnk_084D61DC, (void *)0x06014800);
    CpuFastSet(gUnk_0850E7F8, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 |= 0x220;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unk30 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk32 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unk24 = 6;
    gUnk_03000440.unk84 = 0x45;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03000440.unk84], 0x21);
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void sub_08023C18(void) {
    gUnk_03000440.unk84 = 0x46;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x46], 0x21);
    play_sound_effect(0x4E);
    gUnk_03001800.unkAA++;
}

void sub_08023C50(void) {
    gUnk_03000590[gUnk_03001800.unk88].unkBF = 1;
    gUnk_03001800.unkAA++;
}

void sub_08023C78(void) {
    gUnk_03001800.unkA6 = 0x2B;
    gUnk_03001800.unkAA++;
}

void sub_08023C90(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083ADDE0[gUnk_03001800.unkAA]();
}

void sub_08023CB8(void) {
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    } else if (sub_080331F8(gUnk_03001800.unk88) == 0) {
        gUnk_03001800.unkA6 = 0x39;
        gUnk_03001800.unkAA++;
    } else if (sub_080331F8(gUnk_03001800.unk87) == 0) {
        gUnk_03001800.unkA6 = 0x39;
        gUnk_03001800.unkAA++;
    } else {
        sub_08036270();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void sub_08023D44(void) {
    lz_decompress_dispatch(gUnk_084D6320, (void *)0x06014800);
    CpuFastSet(gUnk_0850E818, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 |= 0x220;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unk30 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk32 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unk24 = 6;
    gUnk_03000440.unk84 = 0x42;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03000440.unk84], 0x21);
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void sub_08023E18(void) {
    gUnk_03000440.unk84 = 0x44;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x44], 0x21);
    play_sound_effect(0x4E);
    gUnk_03001800.unkAA++;
}

void sub_08023E50(void) {
    if (gUnk_03002C30[0x21].unk8 == 8) {
        clear_sprite_table_mask(0x21, 1);
        gUnk_03001800.unkAA++;
    } else {
        gUnk_03002C30[0x21].unk8 -= 8;
        gUnk_03002C30[0x21].unk9 -= 8;
    }
}

void sub_08023E94(void) {
    lz_decompress_dispatch(gUnk_084D6098, (void *)0x06014800);
    CpuFastSet(gUnk_0850E7D8, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 |= 0x8000;
    gUnk_03002C30[0x21].unk30 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk32 = gUnk_03002C30[gUnk_03001800.unk87 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unk24 = 6;
    gUnk_03000440.unk84 = 0x42;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gUnk_03000440.unk84], 0x21);
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void sub_08023F48(void) {
    if (gUnk_03002C30[0x21].unk8 == 0x40)
        gUnk_03001800.unkAA++;
    else {
        gUnk_03002C30[0x21].unk8 += 8;
        gUnk_03002C30[0x21].unk9 += 8;
    }
}

void sub_08023F80(void) {
    gUnk_03000440.unk84 = 0x43;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x43], 0x21);
    play_sound_effect(0x4E);
    gUnk_03001800.unkAA++;
}

void sub_08023FB8(void) {
    gUnk_03000590[gUnk_03001800.unk88].unkC9 = 0x29;
    gUnk_03000590[gUnk_03001800.unk88].unkCA = 0;
    gUnk_03000590[gUnk_03001800.unk88].unkCB = sub_08036E54(gUnk_03001800.unkE8);
    gUnk_03000590[gUnk_03001800.unk88].unkCC = sub_08036E54(gUnk_03001800.unkEC);
    gUnk_03000590[gUnk_03001800.unk87].unkC4 = 0x29;
    gUnk_03000590[gUnk_03001800.unk87].unkC5 = 0;
    gUnk_03000590[gUnk_03001800.unk87].unkC6 = sub_08036E54(gUnk_03001800.unkE8);
    gUnk_03000590[gUnk_03001800.unk87].unkC7 = sub_08036E54(gUnk_03001800.unkEC);
    gUnk_03001800.unkAA++;
}

void sub_08024078(void) {
    gUnk_03001800.unkA6 = 0x2D;
    gUnk_03001800.unkAA++;
}

void sub_08024090(void) {
    gUnk_03001800.unkB5 = 0;
    gUnk_083ADE60[gUnk_03001800.unkAA]();
}

void sub_080240B8(void) {
    calc_battle_action_speed(gUnk_03001800.unk87, gUnk_03001800.unkA7);
    apply_battle_bot_damage_reduction(gUnk_03001800.unk87);
    if (decrement_battle_timer_and_check_zero()) {
        gUnk_03001800.unkA6 = 0x1A;
        gUnk_03001800.unkAA++;
    } else {
        sub_08036270();
        calc_battle_stat_ratio(gUnk_03001800.unk87, gUnk_03001800.unkA7);
        gUnk_03001800.unkAA = 4;
    }
}

void sub_0802410C(void) {
    lz_decompress_dispatch(gUnk_084D6464, (void *)0x06014800);
    CpuFastSet(gUnk_0850E838, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 |= 0x220;
    gUnk_03002C30[0x21].unk8 = 0x40;
    gUnk_03002C30[0x21].unk9 = 0x40;
    gUnk_03002C30[0x21].unk18 = 0;
    gUnk_03002C30[0x21].unk6 = 0x4D00;
    gUnk_03002C30[0x21].unk30 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk2;
    gUnk_03002C30[0x21].unk32 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk4 - 4;
    gUnk_03002C30[0x21].unk24 = 6;
    if (gUnk_03001800.unkF8 & 1)
        gUnk_03002C30[0x21].unk0 |= 0x1000;
    gUnk_03000440.unk86 = 0x3C;
    gUnk_03001800.unkAA++;
}

void sub_080241F0(void) {
    if (move_sprite_toward_target(0x21))
        gUnk_03001800.unkAA++;
}

void sub_08024210(void) {
    gUnk_03002C30[0x21].unk23 = 0;
    memcpy_bytes_0803F63C(&gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5A], &gUnk_03002C30[0x22], 0x40);
    memcpy_bytes_0803F63C(&gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5B], &gUnk_03002C30[0x23], 0x40);
    memcpy_bytes_0803F63C(&gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5C], &gUnk_03002C30[0x24], 0x40);
    memcpy_bytes_0803F63C(&gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D], &gUnk_03002C30[0x25], 0x40);
    clear_sprite_table_mask(0x22, 4);
    gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5A].unk23 = 0;
    gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5B].unk23 = 0;
    gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5C].unk23 = 0;
    gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk23 = 0;
    sub_08035694(gUnk_03001800.unk88 + 0x72);
    play_sound_effect(0x34);
    gUnk_03001800.unkAA++;
}

void sub_080242F8(void) {
    u32 r;

    if (gUnk_03002C30[0x21].unk0 & 0x8000) {
        if (advance_sprite_anim_frame(0x21, 0))
            clear_battle_sprite_slot(0x21, 1);
        else if (!(gUnk_03001800.unkF8 & 1)) {
            gUnk_03002C30[0x21].unk2--;
            gUnk_03002C30[0x21].unk18 = (gUnk_03002C30[0x21].unk18 - 0x10) & 0x3FF;
        } else {
            gUnk_03002C30[0x21].unk2++;
            gUnk_03002C30[0x21].unk18 = (gUnk_03002C30[0x21].unk18 + 0x10) & 0x3FF;
        }
    }
    sub_080353CC(gUnk_03001800.unk88 * 4 + 0x5A);
    sub_080353CC(gUnk_03001800.unk88 * 4 + 0x5B);
    sub_080353CC(gUnk_03001800.unk88 * 4 + 0x5C);
    r = sub_080353CC(gUnk_03001800.unk88 * 4 + 0x5D);
    if (gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk23 == 0x10) {
        gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5A].unk4 += 8;
        gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5B].unk4 -= 8;
        gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5C].unk4 -= 8;
        gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk4 -= 8;
        gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5A].unk0 |= 0x2000;
        gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5B].unk0 |= 0x2000;
        gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5C].unk0 |= 0x2000;
        gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk0 |= 0x2000;
    }
    check_sprite_overlap_and_adjust(gUnk_03001800.unk88 * 4 + 0x5D, gUnk_03001800.unk88 + 0x72);
    if (r) {
        sub_080356B4(gUnk_03001800.unk88 + 0x72);
        play_sound_effect(0x41);
        gUnk_03001800.unkAA++;
    }
}

void sub_08024488(void) {
    u32 i;

    for (i = 0; i < 4; i++) {
        gUnk_03002C30[0x26 + i].unk0 = 0xC404;
        gUnk_03002C30[0x26 + i].unk1C = 0;
        gUnk_03002C30[0x26 + i].unk2 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5A].unk2;
        gUnk_03002C30[0x26 + i].unk4 = gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5A].unk4 + 4;
        gUnk_03002C30[0x26 + i].unkA = 7;
        gUnk_03002C30[0x26 + i].unkB = 0xF0;
        gUnk_03002C30[0x26 + i].unk24 = 6;
        gUnk_03002C30[0x26 + i].unk25 = gUnk_083ADEE0[i];
        gUnk_03002C30[0x26 + i].unk6 = 0x4D01;
    }
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_08024538(void) {
    u32 i;

    for (i = 0; i < 4; i++)
        update_sprite_animation_position(0x26 + i);
    if (gUnk_03000440.unk84 == 0x10) {
        clear_battle_sprite_slot(0x26, 4);
        memcpy_bytes_0803F63C(&gUnk_03002C30[0x22], &gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5A], 0x40);
        memcpy_bytes_0803F63C(&gUnk_03002C30[0x23], &gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5B], 0x40);
        memcpy_bytes_0803F63C(&gUnk_03002C30[0x24], &gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5C], 0x40);
        memcpy_bytes_0803F63C(&gUnk_03002C30[0x25], &gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D], 0x40);
        gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5A].unk0 |= 0x8000;
        gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5B].unk0 |= 0x8000;
        gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5C].unk0 |= 0x8000;
        gUnk_03002C30[gUnk_03001800.unk88 * 4 + 0x5D].unk0 |= 0x8000;
        clear_battle_sprite_slot(0x21, 4);
        gUnk_03001800.unkAA++;
    } else
        gUnk_03000440.unk84++;
}

void sub_0802463C(void) {
    if (gUnk_03000590[gUnk_03001800.unk88].unkBD & 4)
        battle_set_damage_vs_armor(gUnk_03001800.unk88, 0, 1);
    else
        battle_set_damage_vs_armor(gUnk_03001800.unk88, 0, gUnk_03001800.unkEC);
    set_display_digit_type(&gUnk_03000440.unkEE, gUnk_03001800.unkC8, 1);
    render_battle_text_sprites(&gUnk_03000440.unkEE, gUnk_03001800.unk88, 0x21);
    play_sound_effect(0x5B);
    gUnk_03000440.unk84 = 0;
    gUnk_03001800.unkAA++;
}

void sub_080246C0(void) {
    update_battle_sprite_animations(&gUnk_03000440.unkEE, gUnk_03001800.unk88, 0x21);
    if (++gUnk_03000440.unk84, gUnk_03000440.unk89 == 0 && (KEYS_LO(gRepeatKeys) & 1) && gUnk_03000440.unk84 > 0x32)
        gUnk_03000440.unk84 = 0x78;
    if (gUnk_03000440.unk84 == 0x78) {
        clear_battle_sprite_slot(gUnk_03001800.unk88 * 4 + 0x21, 4);
        gUnk_03001800.unkAA++;
    }
}

void battle_process_bot_defeat(void) {
    u8 armor;

    reduce_bot_part_stat(gUnk_03001800.unk88, 0, gUnk_03001800.unkC8);
    armor = gUnk_03000590[gUnk_03001800.unk88].parts[0].unk11;
    if (armor == 0) {
        add_bot_to_defeated_list(gUnk_03001800.unk88);
        gUnk_03001800.unkD0 = armor;
        gUnk_03001800.unkAA = 0x1A;
    } else
        gUnk_03001800.unkAA = 0x13;
}

void sub_08024790(void) {
    if (gUnk_03000590[gUnk_03001800.unk88].unkBD & 4)
        gUnk_03001800.unkAA++;
    else
        gUnk_03001800.unkAA = 0x15;
}

void sub_080247C8(void) {
    gUnk_03000590[gUnk_03001800.unk88].unkBD |= 1;
    gUnk_03001800.unkAA++;
}

void sub_080247F4(void) {
    gUnk_03001800.unkA6 = 0x2E;
    gUnk_03001800.unkAA++;
}

void sub_0802480C(void) {
    lz_decompress_dispatch(gUnk_084CDBD8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E378, (void *)0x050002E0, 8);
    setup_battle_cursor_sprite_08036FF8(0x21, gUnk_03002C30[0x5A + gUnk_03001800.unk88 * 4 + gUnk_03001800.unkD0].unk2,
                                        gUnk_03002C30[0x5A + gUnk_03001800.unk88 * 4 + gUnk_03001800.unkD0].unk4, 4);
    gUnk_03001800.unkAA++;
}

void sub_08024870(void) {
    if (update_sprite_animations_tick_080370AC(0x21, 4))
        gUnk_03001800.unkAA++;
}

void sub_08024890(void) {
    lz_decompress_dispatch(gUnk_084CC9A8, (void *)0x06014800);
    CpuFastSet(gUnk_0850E338, (void *)0x050002E0, 8);
    gUnk_03002C30[0x21].unk0 = 0xC004;
    gUnk_03002C30[0x21].unk1C = 0;
    gUnk_03002C30[0x21].unk2 = gUnk_03002C30[0x5A + gUnk_03001800.unk88 * 4 + gUnk_03001800.unkD0].unk2;
    gUnk_03002C30[0x21].unk4 = gUnk_03002C30[0x5A + gUnk_03001800.unk88 * 4 + gUnk_03001800.unkD0].unk4;
    gUnk_03002C30[0x21].unkA = 7;
    gUnk_03002C30[0x21].unkB = 0xF0;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x22], 0x21);
    gUnk_03001800.unkAA++;
}

void sub_0802494C(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x22], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF) {
        clear_battle_sprite_slot(0x21, 1);
        load_bot_part_sprite(gUnk_03001800.unk88);
        gUnk_03001800.unkAA++;
    }
}
