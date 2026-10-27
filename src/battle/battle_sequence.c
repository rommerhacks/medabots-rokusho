// Battle sequences: battle_sequence_update runs the script gUnk_083CDFE4[gUnk_03001800.unkF9] through the
// command table gUnk_083AF740 (sub_08039430..sub_0803B884, in ROM order); battle_sequence_update_sprites
// runs the sequence's sprite handlers gUnk_083AF96C (sub_0803B900..sub_0803D3C0). Ends with the loader
// load_battle_sequence_commands and the counter / rotation helpers. Entered from battle/action_script.

#include "global.h"

static void battle_sprite_rotate_angles(u32 dir, u32 delta);

void battle_sequence_update(void) {
    while (gSpriteEntries[0].unk2A == 0)
        battle_sequence_run_command();
    battle_sequence_update_sprites();
    gSpriteEntries[0].unk2A = 0;
}

void battle_sequence_run_command(void) {
    s8 *p;
    if ((s8)(gSpriteEntries[0].unk29 = sub_0803D424()) < 0) {
        p = (s8 *)&gSpriteEntries[0].unk29;
        do {
            battle_advance_sequence_counter();
            *p = sub_0803D424();
        } while (*p < 0);
    }
    gUnk_083AF740[gSpriteEntries[0].unk29]();
}

// guess: ends the battle sequence (yields and sets the step-done flag unkB5)
void sub_08039430(void) {
    gSpriteEntries[0].unk2A = 1;
    gUnk_03001800.unkB5 = 1;
}

void sub_08039448(void) {
    const s16 *seq;
    vu8 done = 0;

    load_battle_sequence_commands();
    battle_advance_sequence_counter();
    while (!done) {
        seq = gUnk_083CDFE4[gUnk_03001800.unkF9];
        if (gUnk_03001800.unk102[0] == seq[gUnk_03001800.unk100]) {
            battle_advance_sequence_counter();
            done = 1;
        } else {
            battle_advance_sequence_counter();
        }
    }
}

void sub_080394C4(void) {
    const s16 *seq;
    vu8 done = 0;

    load_battle_sequence_commands();
    battle_advance_sequence_counter();
    while (!done) {
        seq = gUnk_083CDFE4[gUnk_03001800.unkF9];
        if (gUnk_03001800.unk102[gUnk_03001800.unkFD] == seq[gUnk_03001800.unk100]) {
            battle_advance_sequence_counter();
            done = 1;
        } else {
            battle_advance_sequence_counter();
        }
    }
}

void sub_08039540(void) {
    if (gUnk_03001800.unkB7 == 1)
        gUnk_03001800.unkFD = 1;
    else
        gUnk_03001800.unkFD = 0;
    battle_advance_sequence_counter();
}

void sub_08039568(void) {
    if (gUnk_03001800.unkF6 & 1)
        gUnk_03001800.unkFD = 1;
    else
        gUnk_03001800.unkFD = gUnk_03001800.unkF6 & 1;
    battle_advance_sequence_counter();
}

void sub_08039598(void) {
    if (gUnk_03001800.unkB8 == 2)
        gUnk_03001800.unkFD = 1;
    else
        gUnk_03001800.unkFD = 0;
    battle_advance_sequence_counter();
}

void sub_080395C0(void) {
    if (gUnk_03001800.unkB8 == 4)
        gUnk_03001800.unkFD = 1;
    else
        gUnk_03001800.unkFD = 0;
    battle_advance_sequence_counter();
}

void sub_080395E8(void) {
    load_battle_sequence_commands();
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[1].unk2B = 1;
        if (gUnk_03001800.unkF6 & 2)
            gSpriteEntries[1].unk2C = gUnk_03001800.unk102[gUnk_03001800.unk162 + 1];
        else
            gSpriteEntries[1].unk2C = gUnk_03001800.unk102[gUnk_03001800.unkA7 + 1];
        gSpriteEntries[1].unk30 = gUnk_03001800.unk102[0];
        gSpriteEntries[1].unk2D = 0;
    } else {
        gSpriteEntries[2].unk2B = 1;
        if (gUnk_03001800.unkF6 & 2)
            gSpriteEntries[2].unk2C = gUnk_03001800.unk102[gUnk_03001800.unk162 + 4];
        else
            gSpriteEntries[2].unk2C = gUnk_03001800.unk102[gUnk_03001800.unkA7 + 4];
        gSpriteEntries[2].unk30 = gUnk_03001800.unk102[0];
        gSpriteEntries[2].unk2D = 0;
    }
    battle_advance_sequence_counter();
}

// guess: yields until the next frame without advancing
void sub_080396C4(void) {
    gSpriteEntries[0].unk2A = 1;
}

void sub_080396D4(void) {
    load_battle_sequence_commands();
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[2].unk2B = 1;
        if (gUnk_03001800.unkF6 & 2)
            gSpriteEntries[2].unk2C = gUnk_03001800.unk102[gUnk_03001800.unk162 + 4];
        else
            gSpriteEntries[2].unk2C = gUnk_03001800.unk102[gUnk_03001800.unkA7 + 4];
        gSpriteEntries[2].unk30 = gUnk_03001800.unk102[0];
        gSpriteEntries[2].unk2D = 0;
    } else {
        gSpriteEntries[1].unk2B = 1;
        if (gUnk_03001800.unkF6 & 2)
            gSpriteEntries[1].unk2C = gUnk_03001800.unk102[gUnk_03001800.unk162 + 1];
        else
            gSpriteEntries[1].unk2C = gUnk_03001800.unk102[gUnk_03001800.unkA7 + 1];
        gSpriteEntries[1].unk30 = gUnk_03001800.unk102[0];
        gSpriteEntries[1].unk2D = 0;
    }
    battle_advance_sequence_counter();
}

void sub_080397B0(void) {
    u8 f;

    load_battle_sequence_commands();
    gSpriteEntries[3].unk2B = gUnk_03001800.unk102[0];
    f = gUnk_03001800.unkF8 & 2;
    if (!f) {
        gSpriteEntries[3].unk2C = f;
        gSpriteEntries[3].unk30 = gUnk_03001800.unk154;
    } else {
        gSpriteEntries[3].unk2C = 1;
        gSpriteEntries[3].unk30 = gUnk_03001800.unk158;
    }
    gSpriteEntries[3].unk29 = 8;
    battle_advance_sequence_counter();
}

void battle_seq_cmd_wait_text(void) {
    load_battle_sequence_commands();
    switch (gUnk_03001800.unk102[0]) {
    case 0:
        if (!(gUnk_03001800.unkF8 & 2)) {
            if (gUnk_03001800.unk15F)
                battle_advance_sequence_counter();
        } else {
            if (gUnk_03001800.unk160)
                battle_advance_sequence_counter();
        }
        break;
    case 1:
        if (gUnk_03001800.unkF8 & 2) {
            if (gUnk_03001800.unk15F)
                battle_advance_sequence_counter();
        } else {
            if (gUnk_03001800.unk160)
                battle_advance_sequence_counter();
        }
        break;
    default:
        if (gUnk_03001800.unk15F && gUnk_03001800.unk160)
            battle_advance_sequence_counter();
        break;
    }
    gSpriteEntries[0].unk2A = 1;
}

void sub_080398AC(void) {
    u32 skill;
    u32 t;

    load_battle_sequence_commands();
    if (gUnk_03000590[gUnk_03001800.unk87].unkDD <= 3)
        skill = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
    else
        skill = gUnk_03000590[gUnk_03001800.unk87].unkA8[0] + 0x50;
    load_battle_entity_palette(skill, gUnk_03001800.unk102[4], 9);
    gSpriteEntries[4].unk2E = gUnk_03001800.unk102[0];
    gSpriteEntries[4].unk2F = gUnk_03001800.unk102[1];
    gSpriteEntries[4].unk2B = gUnk_03001800.unk102[6];
    gSpriteEntries[4].unk30 = gUnk_03001800.unk102[5];
    gSpriteEntries[4].unk29 = 0x10;
    tile_anim_init(gUnk_083CEC74[gSpriteEntries[4].unk2B], 0, 0);
    gSpriteEntries[4].unk4 = gUnk_03001800.unk102[3];
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[4].unk2 = gUnk_03001800.unk102[2];
        gSpriteEntries[4].unk2C = gUnk_03001800.unk102[7];
    } else {
        t = gSpriteEntries[4].unk2E >> 1;
        gSpriteEntries[4].unk2 = 0x1E - t - (gUnk_03001800.unk102[2] + t);
        gSpriteEntries[4].unk2C = gUnk_03001800.unk102[7] + 2;
    }
    gSpriteEntries[4].unk2D = 0;
    battle_advance_sequence_counter();
}

void battle_seq_cmd_wait_frames(void) {
    load_battle_sequence_commands();
    if (gSpriteEntries[0].unk30 != gUnk_03001800.unk102[0]) {
        gSpriteEntries[0].unk30++;
    } else {
        gSpriteEntries[0].unk30 = 0;
        battle_advance_sequence_counter();
    }
    gSpriteEntries[0].unk2A = 1;
}

void sub_08039A2C(void) {
    load_battle_sequence_commands();
    gSpriteEntries[gUnk_03001800.unk102[0] + 5].unk30 = gUnk_03001800.unk102[1];
    gSpriteEntries[gUnk_03001800.unk102[0] + 5].unk2B = gUnk_03001800.unk102[2];
    gSpriteEntries[gUnk_03001800.unk102[0] + 5].unk2C = 0;
    gSpriteEntries[gUnk_03001800.unk102[0] + 5].unk2D = gUnk_03001800.unk102[3];
    gSpriteEntries[gUnk_03001800.unk102[0] + 5].unk2E = gUnk_03001800.unk102[4];
    gSpriteEntries[gUnk_03001800.unk102[0] + 5].unk29 = 0x18;
    battle_advance_sequence_counter();
}

void sub_08039AC8(void) {
    u32 i;
    const u8 *set;

    load_battle_sequence_commands();
    gSpriteEntries[gUnk_03001800.unk102[0] + 5].unk30 = gUnk_03001800.unk102[1];
    gSpriteEntries[gUnk_03001800.unk102[0] + 5].unk2C = 0;
    gSpriteEntries[gUnk_03001800.unk102[0] + 5].unk2D = gUnk_03001800.unk102[3];
    gSpriteEntries[gUnk_03001800.unk102[0] + 5].unk2E = gUnk_03001800.unk102[4];
    gSpriteEntries[gUnk_03001800.unk102[0] + 5].unk29 = 0x18;
    if (gUnk_03001800.unkF6 & 2)
        get_bot_part_effective_values(gUnk_03001800.unk161, gUnk_03001800.unk64);
    else
        get_bot_part_effective_values(gUnk_03001800.unk87, gUnk_03001800.unk64);
    if (gUnk_03001800.unk64[3] > 0x77)
        i = 3;
    else if (gUnk_03001800.unkF6 & 2)
        i = gUnk_03000590[gUnk_03001800.unk161].parts[3].data[1] - 0x64;
    else
        i = gUnk_03000590[gUnk_03001800.unk87].parts[3].data[1] - 0x64;
    set = gUnk_083AF888[gUnk_03001800.unk102[2]];
    gSpriteEntries[gUnk_03001800.unk102[0] + 5].unk2B = set[i];
    battle_advance_sequence_counter();
}

void sub_08039BFC(void) {
    u8 f;

    load_battle_sequence_commands();
    gSpriteEntries[3].unk24 = gUnk_03001800.unk102[0];
    gSpriteEntries[3].unk2D = gUnk_03001800.unk102[2];
    f = gUnk_03001800.unkF8 & 2;
    if (!f) {
        gSpriteEntries[3].unk2C = f;
        gSpriteEntries[3].unk25 = gUnk_03001800.unk102[1];
        gSpriteEntries[3].unk2 = gUnk_03001800.unk154;
        gSpriteEntries[3].unk4 = gUnk_03001800.unk156;
    } else {
        gSpriteEntries[3].unk2C = 1;
        gSpriteEntries[3].unk25 = (0x20 - (u8)gUnk_03001800.unk102[1]) & 0x1F;
        gSpriteEntries[3].unk2 = gUnk_03001800.unk158;
        gSpriteEntries[3].unk4 = gUnk_03001800.unk15A;
    }
    gSpriteEntries[3].unk29 = 9;
    battle_advance_sequence_counter();
}

void sub_08039CB4(void) {
    u8 f = gUnk_03000590[gUnk_03001800.unk88].unkBC & 0x20;
    if (f)
        gUnk_03001800.unkFD = 1;
    else
        gUnk_03001800.unkFD = f;
    battle_advance_sequence_counter();
}

void sub_08039CF8(void) {
    u32 t;

    load_battle_sequence_commands();
    load_battle_entity_palette(0x3C, gUnk_03001800.unk102[4], 9);
    gSpriteEntries[4].unk2E = gUnk_03001800.unk102[0];
    gSpriteEntries[4].unk2F = gUnk_03001800.unk102[1];
    gSpriteEntries[4].unk2B = gUnk_03001800.unk102[6];
    gSpriteEntries[4].unk30 = gUnk_03001800.unk102[5];
    gSpriteEntries[4].unk29 = 0x10;
    tile_anim_init(gUnk_083CEC74[gSpriteEntries[4].unk2B], 0, 0);
    gSpriteEntries[4].unk4 = gUnk_03001800.unk102[3];
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[4].unk2 = gUnk_03001800.unk102[2];
        gSpriteEntries[4].unk2C = gUnk_03001800.unk102[7];
    } else {
        t = gSpriteEntries[4].unk2E >> 1;
        gSpriteEntries[4].unk2 = 0x1E - t - (gUnk_03001800.unk102[2] + t);
        gSpriteEntries[4].unk2C = gUnk_03001800.unk102[7] + 2;
    }
    gSpriteEntries[4].unk2D = 0;
    battle_advance_sequence_counter();
}

void sub_08039E00(void) {
    if (!(gUnk_03001800.unkF8 & 2)) {
        gUnk_03001800.unk154 = 0x12C;
        gUnk_03001800.unk156 = 0x50;
        get_active_bot_part_index_and_load_values(0);
        init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                       gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156,
                                       gUnk_03001800.unk39[3] + 2, 4, 0, 2, 0, gUnk_03001800.unk114[0]);
        init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                       gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156,
                                       gUnk_03001800.unk39[3] + 2, 4, 0, 1, 0, gUnk_03001800.unk114[0]);
        gUnk_03001800.unk112 = 0x29;
        advance_text_display(0, 0x29, gUnk_03001800.unk64[3]);
    } else {
        gUnk_03001800.unk158 = 0x1C4;
        gUnk_03001800.unk15A = 0x50;
        get_active_bot_part_index_and_load_values(1);
        init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                       gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A,
                                       gUnk_03001800.unk39[3] + 2, 8, 1, 2, 1, gUnk_03001800.unk114[1]);
        init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                       gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A,
                                       gUnk_03001800.unk39[3] + 2, 8, 1, 1, 1, gUnk_03001800.unk114[1]);
        gUnk_03001800.unk113 = 0x29;
        advance_text_display(1, 0x29, gUnk_03001800.unk64[3]);
    }
    battle_advance_sequence_counter();
}

void sub_08039FE4(void) {
    load_battle_sequence_commands();
    clear_battle_sprite_slot(0x1E, 1);
    gSpriteEntries[0x1E].unk2B = gUnk_03001800.unk102[0];
    gSpriteEntries[0x1E].unk4 = gUnk_03001800.unk102[2];
    gSpriteEntries[0x1E].unk24 = gUnk_03001800.unk102[4];
    gSpriteEntries[0x1E].unk29 = 10;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[0x1E].unk2 = gUnk_03001800.unk102[1];
        gSpriteEntries[0x1E].unk25 = gUnk_03001800.unk102[3];
    } else {
        gSpriteEntries[0x1E].unk2 = 0xF0 - gUnk_03001800.unk102[1];
        gSpriteEntries[0x1E].unk25 = (0x20 - (u8)gUnk_03001800.unk102[3]) & 0x1F;
    }
    gSpriteEntries[0x1E].unk30 = gSpriteEntries[0x1E].unk2;
    battle_advance_sequence_counter();
}

void sub_0803A0B8(void) {
    if (!gSpriteEntries[0x1E].unk29)
        battle_advance_sequence_counter();
    gSpriteEntries[0].unk2A = 1;
}

void sub_0803A0E0(void) {
    load_battle_sequence_commands();
    lz_decompress_dispatch(gUnk_083AF88C[gUnk_03001800.unk102[0] * 2], (void *)0x06010000);
    CpuFastSet(gUnk_083AF88C[gUnk_03001800.unk102[0] * 2 + 1], (void *)0x050003C0, 8);
    battle_advance_sequence_counter();
}

void sub_0803A130(void) {
    u32 i;
    u32 slot;

    load_battle_sequence_commands();
    for (i = 0; i <= 8; i++) {
        if (gSpriteEntries[i + 10].unk0 == 0) {
            slot = i + 10;
            break;
        }
    }
    clear_battle_sprite_slot(slot, 1);
    gSpriteEntries[slot].unk0 = (gUnk_03001800.unk102[6] << 10) | 0x4004;
    gSpriteEntries[slot].unk1C = 0;
    gSpriteEntries[slot].unkA = 0xE;
    gSpriteEntries[slot].unkB = 0x80;
    gSpriteEntries[slot].unk2D = gUnk_03001800.unk102[7];
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[slot].unk2D], slot);
    gSpriteEntries[slot].unk2B = gUnk_03001800.unk102[0];
    gSpriteEntries[slot].unk4 = gUnk_03001800.unk102[2];
    gSpriteEntries[slot].unk24 = gUnk_03001800.unk102[4];
    gSpriteEntries[slot].unk2C = gUnk_03001800.unk102[5];
    gSpriteEntries[slot].unk29 = 0xB;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[slot].unk2 = gUnk_03001800.unk102[1];
        gSpriteEntries[slot].unk25 = gUnk_03001800.unk102[3];
    } else {
        gSpriteEntries[slot].unk0 |= 0x1000;
        gSpriteEntries[slot].unk2 = 0xF0 - gUnk_03001800.unk102[1];
        gSpriteEntries[slot].unk25 = (0x20 - (u8)gUnk_03001800.unk102[3]) & 0x1F;
    }
    battle_advance_sequence_counter();
}

void sub_0803A264(void) {
    load_battle_sequence_commands();
    if (!(gUnk_03001800.unkF8 & 2)) {
        if (gSpriteEntries[gUnk_03001800.unk102[1]].unk2 >= gUnk_03001800.unk102[0])
            battle_advance_sequence_counter();
    } else {
        if (gSpriteEntries[gUnk_03001800.unk102[1]].unk2 <= 0xF0 - gUnk_03001800.unk102[0])
            battle_advance_sequence_counter();
    }
    gSpriteEntries[0].unk2A = 1;
}

void sub_0803A2E8(void) {
    load_battle_sequence_commands();
    clear_battle_sprite_slot(gUnk_03001800.unk102[0], gUnk_03001800.unk102[1]);
    battle_advance_sequence_counter();
}

void sub_0803A310(void) {
    s32 n;

    load_battle_sequence_commands();
    n = gUnk_03001800.unk102[2];
    gSpriteEntries[n].unkA = gUnk_03001800.unk102[4];
    gSpriteEntries[n].unk2D = gUnk_03001800.unk102[1];
    gSpriteEntries[n].unk2B = gUnk_03001800.unk102[0];
    gSpriteEntries[n].unk29 = 0x20;
    gSpriteEntries[n].unk2E = gUnk_03001800.unk102[3];
    battle_advance_sequence_counter();
}

void sub_0803A370(void) {
    load_battle_sequence_commands();
    clear_battle_sprite_slot(0x1E, 1);
    gSpriteEntries[0x1E].unk2B = gUnk_03001800.unk102[0];
    gSpriteEntries[0x1E].unk4 = gUnk_03001800.unk102[2];
    gSpriteEntries[0x1E].unk24 = gUnk_03001800.unk102[4];
    gSpriteEntries[0x1E].unk29 = 12;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[0x1E].unk2 = gUnk_03001800.unk102[1];
        gSpriteEntries[0x1E].unk25 = gUnk_03001800.unk102[3];
    } else {
        gSpriteEntries[0x1E].unk2 = 0xF0 - gUnk_03001800.unk102[1];
        gSpriteEntries[0x1E].unk25 = (0x20 - (u8)gUnk_03001800.unk102[3]) & 0x1F;
    }
    gSpriteEntries[0x1E].unk30 = gSpriteEntries[0x1E].unk2;
    battle_advance_sequence_counter();
}

void sub_0803A444(void) {
    REG_BG0CNT = 0x4500;
    tilemap_fill_rect(0x40, 0x20, 0, 0, REG_BG0CNT, 0);
    battle_advance_sequence_counter();
}

void sub_0803A474(void) {
    u32 skill;
    u32 t;

    load_battle_sequence_commands();
    clear_battle_sprite_slot(0x23, 1);
    if (gUnk_03000590[gUnk_03001800.unk87].unkDD <= 3)
        skill = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
    else
        skill = gUnk_03000590[gUnk_03001800.unk87].unkA8[0] + 0x50;
    load_battle_entity_palette(skill, gUnk_03001800.unk102[4], 9);
    gSpriteEntries[0x23].unk2E = gUnk_03001800.unk102[0];
    gSpriteEntries[0x23].unk2F = gUnk_03001800.unk102[1];
    gSpriteEntries[0x23].unk2B = gUnk_03001800.unk102[6];
    gSpriteEntries[0x23].unk30 = gUnk_03001800.unk102[5];
    gSpriteEntries[0x23].unk29 = 0x11;
    tile_anim_init(gUnk_083CEC74[gSpriteEntries[0x23].unk2B], 1, 1);
    gSpriteEntries[0x23].unk4 = gUnk_03001800.unk102[3];
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[0x23].unk2 = gUnk_03001800.unk102[2];
        gSpriteEntries[0x23].unk2C = gUnk_03001800.unk102[7];
    } else {
        t = gSpriteEntries[0x23].unk2E >> 1;
        gSpriteEntries[0x23].unk2 = (s16)(0x1E - t - (gUnk_03001800.unk102[2] + t)) - 1;
        gSpriteEntries[0x23].unk2C = gUnk_03001800.unk102[7] + 2;
    }
    gSpriteEntries[0x23].unk2D = 0;
    gSpriteEntries[0x23].unk28 = 0;
    battle_advance_sequence_counter();
}

void sub_0803A5CC(void) {
    u32 skill;

    load_battle_sequence_commands();
    if (gUnk_03000590[gUnk_03001800.unk87].unkDD <= 3)
        skill = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
    else
        skill = gUnk_03000590[gUnk_03001800.unk87].unkA8[0] + 0x50;
    load_battle_entity_palette(skill, gUnk_03001800.unk102[4], 9);
    gSpriteEntries[4].unk2E = gUnk_03001800.unk102[0];
    gSpriteEntries[4].unk2F = gUnk_03001800.unk102[1];
    gSpriteEntries[4].unk2B = gUnk_03001800.unk102[6];
    gSpriteEntries[4].unk30 = gUnk_03001800.unk102[5];
    gSpriteEntries[4].unk29 = 0x12;
    tile_anim_init(gUnk_083CEC74[gSpriteEntries[4].unk2B], 0, 0);
    gSpriteEntries[4].unk4 = 4;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[4].unk2 = gUnk_03001800.unk102[2];
        gSpriteEntries[4].unk2C = gUnk_03001800.unk102[7];
    } else {
        gSpriteEntries[4].unk2 = gUnk_03001800.unk102[3];
        gSpriteEntries[4].unk2C = gUnk_03001800.unk102[7] + 2;
    }
    gSpriteEntries[4].unk2D = 0;
    battle_advance_sequence_counter();
}

void sub_0803A6FC(void) {
    tilemap_fill_rect(0x20, 0x20, 0, 0, REG_BG0CNT, 0);
    tilemap_fill_rect(0x20, 0x20, 0x20, 0, REG_BG0CNT, 0);
    REG_BG0CNT = 0x500;
    gBg0Scroll.x = 0;
    gBg1Scroll.x = 0;
    clear_battle_sprite_slot(4, 1);
    clear_battle_sprite_slot(0x23, 1);
    battle_advance_sequence_counter();
}

void sub_0803A760(void) {
    load_battle_sequence_commands();
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[1].unk2B = 1;
        if (gUnk_03001800.unkF6 & 2)
            gSpriteEntries[1].unk2C = gUnk_03001800.unk102[gUnk_03001800.unk162 + 1];
        else
            gSpriteEntries[1].unk2C = gUnk_03001800.unk102[gUnk_03001800.unkA7 + 1];
        gSpriteEntries[1].unk30 = gUnk_03001800.unk102[0];
        gSpriteEntries[1].unk2D = 1;
    } else {
        gSpriteEntries[2].unk2B = 1;
        if (gUnk_03001800.unkF6 & 2)
            gSpriteEntries[2].unk2C = gUnk_03001800.unk102[gUnk_03001800.unk162 + 4];
        else
            gSpriteEntries[2].unk2C = gUnk_03001800.unk102[gUnk_03001800.unkA7 + 4];
        gSpriteEntries[2].unk30 = gUnk_03001800.unk102[0];
        gSpriteEntries[2].unk2D = 1;
    }
    battle_advance_sequence_counter();
}

void sub_0803A840(void) {
    load_battle_sequence_commands();
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[2].unk2B = 1;
        if (gUnk_03001800.unkF6 & 2)
            gSpriteEntries[2].unk2C = gUnk_03001800.unk102[gUnk_03001800.unk162 + 4];
        else
            gSpriteEntries[2].unk2C = gUnk_03001800.unk102[gUnk_03001800.unkA7 + 4];
        gSpriteEntries[2].unk30 = gUnk_03001800.unk102[0];
        gSpriteEntries[2].unk2D = 1;
    } else {
        gSpriteEntries[1].unk2B = 1;
        if (gUnk_03001800.unkF6 & 2)
            gSpriteEntries[1].unk2C = gUnk_03001800.unk102[gUnk_03001800.unk162 + 1];
        else
            gSpriteEntries[1].unk2C = gUnk_03001800.unk102[gUnk_03001800.unkA7 + 1];
        gSpriteEntries[1].unk30 = gUnk_03001800.unk102[0];
        gSpriteEntries[1].unk2D = 1;
    }
    battle_advance_sequence_counter();
}

void sub_0803A920(void) {
    gSpriteEntries[0x23].unk27 = 1;
    battle_advance_sequence_counter();
}

void sub_0803A93C(void) {
    u32 i;
    u32 slot;

    load_battle_sequence_commands();
    for (i = 0; i < 2; i++) {
        if (gSpriteEntries[i + 0xC].unk29 == 0) {
            slot = i + 0xC;
            break;
        }
    }
    clear_battle_sprite_slot(slot, 1);
    gSpriteEntries[slot].unk2B = gUnk_03001800.unk102[0];
    gSpriteEntries[slot].unk2E = gUnk_03001800.unk102[1];
    gSpriteEntries[slot].unk30 = gUnk_03001800.unk102[2];
    gSpriteEntries[slot].unk32 = gUnk_03001800.unk102[3];
    gSpriteEntries[slot].unk2C = gUnk_03001800.unk102[4];
    gSpriteEntries[slot].unk2D = gUnk_03001800.unk102[5];
    gSpriteEntries[slot].unk27 = gUnk_03001800.unk102[6];
    gSpriteEntries[slot].unk28 = 0;
    gSpriteEntries[slot].unk29 = 0x22;
    battle_advance_sequence_counter();
}

void sub_0803AA00(void) {
    load_battle_sequence_commands();
    if (!(gUnk_03001800.unkF8 & 2))
        gSpriteEntries[gUnk_03001800.unk102[0]].unk25 = gUnk_03001800.unk102[1];
    else
        gSpriteEntries[gUnk_03001800.unk102[0]].unk25 = (0x20 - (u8)gUnk_03001800.unk102[1]) & 0x1F;
    gSpriteEntries[gUnk_03001800.unk102[0]].unk24 = gUnk_03001800.unk102[2];
    battle_advance_sequence_counter();
}

void sub_0803AA90(void) {
    load_battle_sequence_commands();
    if (gUnk_03001800.unk102[1] != 0)
        gSpriteEntries[gUnk_03001800.unk102[0]].unk0 ^= 0x1000;
    if (gUnk_03001800.unk102[2] != 0)
        gSpriteEntries[gUnk_03001800.unk102[0]].unk0 ^= 0x2000;
    battle_advance_sequence_counter();
}

void sub_0803AB00(void) {
    load_battle_sequence_commands();
    if (gUnk_03001800.unk102[0] == 0) {
        palette_backup_from_hardware();
        gSpriteEntries[0x27].unk2F = 0;
        gSpriteEntries[0x27].unk29 = 0x28;
    } else {
        gSpriteEntries[0x27].unk29 = 0x29;
    }
    gSpriteEntries[0x27].unk2B = gUnk_03001800.unk102[1];
    gSpriteEntries[0x27].unk2C = gUnk_03001800.unk102[2];
    gSpriteEntries[0x27].unk2D = gUnk_03001800.unk102[3];
    gSpriteEntries[0x27].unk2E = gUnk_03001800.unk102[4];
    battle_advance_sequence_counter();
}

void sub_0803AB9C(void) {
    if (!(gUnk_03001800.unkF8 & 2)) {
        CpuFastSet((void *)0x05000300, (void *)0x0202F900, 8);
        CpuFastSet((void *)0x05000320, (void *)0x0202F920, 8);
        CpuFastSet((void *)0x05000340, (void *)0x0202F940, 8);
        CpuFastSet((void *)0x05000360, (void *)0x0202F960, 8);
    } else {
        CpuFastSet((void *)0x05000280, (void *)0x0202F880, 8);
        CpuFastSet((void *)0x050002A0, (void *)0x0202F8A0, 8);
        CpuFastSet((void *)0x050002C0, (void *)0x0202F8C0, 8);
        CpuFastSet((void *)0x050002E0, (void *)0x0202F8E0, 8);
    }
    battle_advance_sequence_counter();
}

void sub_0803AC4C(void) {
    load_battle_sequence_commands();
    if (gUnk_03001800.unk102[0] == 0)
        CpuFastSet((void *)(gUnk_03001800.unk102[1] * 32 + 0x05000000),
                   (void *)(gUnk_03001800.unk102[1] * 32 + 0x0202FA00), 8);
    else
        CpuFastSet((void *)(gUnk_03001800.unk102[1] * 32 + 0x05000200),
                   (void *)(gUnk_03001800.unk102[1] * 32 + 0x0202F800), 8);
    battle_advance_sequence_counter();
}

void sub_0803ACB4(void) {
    u32 i;
    u32 slot;

    load_battle_sequence_commands();
    for (i = 0; i < 9; i++) {
        if (gSpriteEntries[i + 0xA].unk0 == 0) {
            slot = i + 0xA;
            break;
        }
    }
    clear_battle_sprite_slot(slot, 1);
    gSpriteEntries[slot].unk0 = (gUnk_03001800.unk102[6] << 10) | 0x4004;
    gSpriteEntries[slot].unk1C = 0;
    gSpriteEntries[slot].unkA = 0xE;
    gSpriteEntries[slot].unkB = 0x80;
    gSpriteEntries[slot].unk2D = gUnk_03001800.unk102[7];
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[slot].unk2D], slot);
    gSpriteEntries[slot].unk2B = gUnk_03001800.unk102[0];
    gSpriteEntries[slot].unk4 = gUnk_03001800.unk102[2];
    gSpriteEntries[slot].unk24 = gUnk_03001800.unk102[4];
    gSpriteEntries[slot].unk2C = gUnk_03001800.unk102[5];
    gSpriteEntries[slot].unk29 = 0xD;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[slot].unk2 = gUnk_03001800.unk102[1];
        gSpriteEntries[slot].unk25 = gUnk_03001800.unk102[3];
    } else {
        gSpriteEntries[slot].unk0 |= 0x1000;
        gSpriteEntries[slot].unk2 = 0xF0 - gUnk_03001800.unk102[1];
        gSpriteEntries[slot].unk25 = (0x20 - (u8)gUnk_03001800.unk102[3]) & 0x1F;
    }
    battle_advance_sequence_counter();
}

void sub_0803ADE8(void) {
    clear_battle_sprite_slot(0xC, 2);
    battle_advance_sequence_counter();
}

void sub_0803ADFC(void) {
    u32 skill;

    load_battle_sequence_commands();
    if (gUnk_03000590[gUnk_03001800.unk87].unkDD <= 3)
        skill = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
    else
        skill = gUnk_03000590[gUnk_03001800.unk87].unkA8[0] + 0x50;
    load_battle_entity_palette(skill, gUnk_03001800.unk102[4], 9);
    gSpriteEntries[4].unk2E = gUnk_03001800.unk102[0];
    gSpriteEntries[4].unk2F = gUnk_03001800.unk102[1];
    gSpriteEntries[4].unk2B = gUnk_03001800.unk102[6];
    gSpriteEntries[4].unk30 = gUnk_03001800.unk102[5];
    gSpriteEntries[4].unk29 = 0x13;
    tile_anim_init(gUnk_083CEC74[gSpriteEntries[4].unk2B], 0, 0);
    gSpriteEntries[4].unk4 = 4;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[4].unk2 = gUnk_03001800.unk102[2];
        gSpriteEntries[4].unk2C = gUnk_03001800.unk102[7];
    } else {
        gSpriteEntries[4].unk2 = gUnk_03001800.unk102[3];
        gSpriteEntries[4].unk2C = (u8)gUnk_03001800.unk102[7] + 2;
    }
    gSpriteEntries[4].unk2D = 0;
    battle_advance_sequence_counter();
}

void sub_0803AF2C(void) {
    u32 i;
    struct Coords16 v;

    load_battle_sequence_commands();
    gSpriteEntries[0xA].unk2B = gUnk_03001800.unk102[0];
    gSpriteEntries[0xA].unk4 = gUnk_03001800.unk102[2];
    gSpriteEntries[0xA].unk24 = gUnk_03001800.unk102[4];
    gSpriteEntries[0xA].unk2C = gUnk_03001800.unk102[5];
    gSpriteEntries[0xA].unk29 = 0x30;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[0xA].unk2 = gUnk_03001800.unk102[1];
        gSpriteEntries[0xA].unk25 = gUnk_03001800.unk102[3];
    } else {
        gSpriteEntries[0xA].unk2 = 0xF0 - gUnk_03001800.unk102[1];
        gSpriteEntries[0xA].unk25 = (0x20 - (u8)gUnk_03001800.unk102[3]) & 0x1F;
    }
    for (i = 0; i < 4; i++) {
        gSpriteEntries[i + 0xB].unk0 = (gUnk_03001800.unk102[6] << 10) | 0x4004;
        gSpriteEntries[i + 0xB].unk1C = 0;
        gSpriteEntries[i + 0xB].unkA = 0xE;
        gSpriteEntries[i + 0xB].unkB = 0x80;
        gSpriteEntries[i + 0xB].unk2D = gUnk_03001800.unk102[7];
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[i + 0xB].unk2D], i + 0xB);
        gSpriteEntries[i + 0xB].unk2B = gUnk_03001800.unk102[0];
        gSpriteEntries[i + 0xB].unk2C = gUnk_03001800.unk102[5];
        gSpriteEntries[i + 0xB].unk29 = 0x31;
        v = calc_polar_to_screen_coords(i * 64, 0x10, gSpriteEntries[0xA].unk2, gSpriteEntries[0xA].unk4);
        gSpriteEntries[i + 0xB].unk2 = v.x;
        gSpriteEntries[i + 0xB].unk4 = v.y;
        gSpriteEntries[i + 0xB].unk26 = i * 64 - 0x20;
    }
    battle_advance_sequence_counter();
}

void sub_0803B0C0(void) {
    u32 i;
    const struct Unk_083AF94C *tbl;
    struct Unk_03001800 *b;
    u8 *f;

    load_battle_sequence_commands();
    i = 0;
    b = &gUnk_03001800;
    f = &b->unkF8;
    tbl = gUnk_083AF94C;
    do {
        gSpriteEntries[i + 0xA].unk0 = 0xC004;
        gSpriteEntries[i + 0xA].unk1C = 0;
        gSpriteEntries[i + 0xA].unk4 = tbl->y;
        gSpriteEntries[i + 0xA].unkA = 0xE;
        gSpriteEntries[i + 0xA].unkB = 0x80;
        gSpriteEntries[i + 0xA].unk2C = b->unk102[0];
        gSpriteEntries[i + 0xA].unk2B = b->unk102[0];
        gSpriteEntries[i + 0xA].unk25 = b->unk102[1];
        gSpriteEntries[i + 0xA].unk24 = b->unk102[2];
        gSpriteEntries[i + 0xA].unk29 = 0xB;
        gSpriteEntries[i + 0xA].unk2D = b->unk102[3];
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[i + 0xA].unk2D], i + 0xA);
        if (!(*f & 2))
            gSpriteEntries[i + 0xA].unk2 = tbl->x;
        else
            gSpriteEntries[i + 0xA].unk2 = (0xF6 - tbl->x) & 0x1FF;
        tbl++;
        i++;
    } while (i < 4);
    battle_advance_sequence_counter();
}

void sub_0803B19C(void) {
    load_battle_sequence_commands();
    lz_decompress(gUnk_083AF95C[gUnk_03001800.unk102[0] * 2], (void *)0x02000000);
    CpuFastSet(gUnk_083AF95C[gUnk_03001800.unk102[0] * 2 + 1], (void *)0x050003C0, 8);
    battle_advance_sequence_counter();
}

void sub_0803B1EC(void) {
    u32 i;
    u32 slot;

    load_battle_sequence_commands();
    for (i = 0; i < 9; i++) {
        if (gSpriteEntries[i + 0xA].unk0 == 0) {
            slot = i + 0xA;
            break;
        }
    }
    clear_battle_sprite_slot(slot, 1);
    gSpriteEntries[slot].unk0 = (gUnk_03001800.unk102[6] << 10) | 0x4004;
    gSpriteEntries[slot].unk1C = 0;
    gSpriteEntries[slot].unkA = 0xE;
    gSpriteEntries[slot].unkB = 0x80;
    gSpriteEntries[slot].unk2D = gUnk_03001800.unk102[7];
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[slot].unk2D], slot);
    gSpriteEntries[slot].unk2B = gUnk_03001800.unk102[0];
    gSpriteEntries[slot].unk4 = gUnk_03001800.unk102[2];
    gSpriteEntries[slot].unk24 = gUnk_03001800.unk102[4];
    gSpriteEntries[slot].unk2C = gUnk_03001800.unk102[5];
    gSpriteEntries[slot].unk29 = 0xE;
    if (!(gUnk_03001800.unkF8 & 2)) {
        gSpriteEntries[slot].unk2 = gUnk_03001800.unk102[1];
        gSpriteEntries[slot].unk25 = gUnk_03001800.unk102[3];
    } else {
        gSpriteEntries[slot].unk0 |= 0x1000;
        gSpriteEntries[slot].unk2 = 0xF0 - gUnk_03001800.unk102[1];
        gSpriteEntries[slot].unk25 = (0x20 - (u8)gUnk_03001800.unk102[3]) & 0x1F;
    }
    battle_advance_sequence_counter();
}

void sub_0803B328(void) {
    load_battle_sequence_commands();
    gSpriteEntries[gUnk_03001800.unk102[1]].unk2E = gUnk_03001800.unk102[0];
    tile_anim_init_dup(gUnk_083CEC74[gUnk_03001800.unk102[0]], 0, 0);
    battle_advance_sequence_counter();
}

void sub_0803B374(void) {
    if (gUnk_03000590[gUnk_03001800.unk87].unkDD <= 3)
        decompress_indexed_graphics_to_ewram(gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1]);
    else
        decompress_indexed_graphics_to_ewram(gUnk_03000590[gUnk_03001800.unk87].unkA8[0] + 0x50);
    battle_advance_sequence_counter();
}

void sub_0803B3C8(void) {
    load_battle_sequence_commands();
    lz_decompress_dispatch(gUnk_083AF88C[gUnk_03001800.unk102[0] * 2],
                           (void *)(gUnk_03001800.unk102[1] * 32 + 0x06010000));
    CpuFastSet(gUnk_083AF88C[gUnk_03001800.unk102[0] * 2 + 1], (void *)0x050003C0, 8);
    battle_advance_sequence_counter();
}

void sub_0803B428(void) {
    load_battle_sequence_commands();
    gSpriteEntries[gUnk_03001800.unk102[0]].unk0 |= 0x200;
    gSpriteEntries[gUnk_03001800.unk102[0]].unk8 = gUnk_03001800.unk102[4];
    gSpriteEntries[gUnk_03001800.unk102[0]].unk9 = gUnk_03001800.unk102[5];
    gSpriteEntries[gUnk_03001800.unk102[0]].unk18 = 0;
    gSpriteEntries[gUnk_03001800.unk102[0]].unk26 = gUnk_03001800.unk102[3];
    gSpriteEntries[gUnk_03001800.unk102[0]].unk2D = gUnk_03001800.unk102[2];
    gSpriteEntries[gUnk_03001800.unk102[0]].unk23 = gUnk_03001800.unk102[1];
    gSpriteEntries[gUnk_03001800.unk102[0]].unk29 = 0x34;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[gUnk_03001800.unk102[0]].unk2D],
                                      gUnk_03001800.unk102[0]);
    battle_advance_sequence_counter();
}

void sub_0803B4F8(void) {
    u32 i;
    struct Coords16 v;

    load_battle_sequence_commands();
    for (i = 0; i < 8; i++) {
        gSpriteEntries[i + 0xB].unk0 = 0xC604;
        gSpriteEntries[i + 0xB].unk1C = 0;
        v = calc_polar_to_screen_coords(i * 32, gUnk_03001800.unk102[3], gSpriteEntries[gUnk_03001800.unk102[0]].unk2,
                                        gSpriteEntries[gUnk_03001800.unk102[0]].unk4);
        gSpriteEntries[i + 0xB].unk2 = v.x;
        gSpriteEntries[i + 0xB].unk4 = v.y;
        gSpriteEntries[i + 0xB].unk8 = 8;
        gSpriteEntries[i + 0xB].unk9 = 8;
        gSpriteEntries[i + 0xB].unkA = 0xE;
        gSpriteEntries[i + 0xB].unkB = 0x80;
        gSpriteEntries[i + 0xB].unk29 = 0x36;
        gSpriteEntries[i + 0xB].unk26 = i * 32;
        gSpriteEntries[i + 0xB].unk27 = gUnk_03001800.unk102[3];
        gSpriteEntries[i + 0xB].unk2B = 0;
        gSpriteEntries[i + 0xB].unk23 = gUnk_03001800.unk102[1];
        gSpriteEntries[i + 0xB].unk2D = gUnk_03001800.unk102[2];
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[i + 0xB].unk2D], i + 0xB);
    }
    battle_advance_sequence_counter();
}

void sub_0803B5DC(void) {
    u8 mirrored;

    load_battle_sequence_commands();
    lz_decompress_dispatch(gUnk_084C4F00, (void *)0x06006400);
    lz_decompress_dispatch(gUnk_084882F4, (void *)0x06006520);
    lz_decompress_dispatch(gUnk_084C3648, (void *)0x06006600);
    lz_decompress_dispatch(gUnk_084C65C8, (void *)0x06006800);
    CpuFastSet(gUnk_08488B24, (void *)0x05000140, 8);
    CpuFastSet(gUnk_084E3098, (void *)0x05000100, 8);
    CpuFastSet(gUnk_084C6A58, (void *)0x05000160, 8);
    mirrored = gUnk_03001800.unkF8 & 2;
    if (mirrored == 0)
        gSpriteEntries[9].unk2D = mirrored;
    else
        gSpriteEntries[9].unk2D = 1;
    gSpriteEntries[9].unk2E = 1;
    gSpriteEntries[9].unk2B = gUnk_03001800.unk102[0];
    gSpriteEntries[9].unk2C = gUnk_03001800.unk102[1];
    gSpriteEntries[9].unk29 = 0x38;
    battle_advance_sequence_counter();
}

void sub_0803B6D8(void) {
    if (gSpriteEntries[9].unk29 == 0)
        battle_advance_sequence_counter();
    gSpriteEntries[0].unk2A = 1;
}

void sub_0803B700(void) {
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG0CNT, 0);
    vram_fill_tilemap_rect(0x20, 0x20, 0, 0, REG_BG1CNT, 0);
    clear_battle_sprite_slot(4, 1);
    clear_battle_sprite_slot(0x23, 1);
    battle_advance_sequence_counter();
}

void sub_0803B754(void) {
    u32 skill;

    load_battle_sequence_commands();
    if (gUnk_03000590[gUnk_03001800.unk87].unkDD <= 3)
        skill = gUnk_03000590[gUnk_03001800.unk87].parts[gUnk_03001800.unkA7].data[1];
    else
        skill = gUnk_03000590[gUnk_03001800.unk87].unkA8[0] + 0x50;
    load_battle_entity_palette(skill, gUnk_03001800.unk102[4], 9);
    gSpriteEntries[4].unk2E = gUnk_03001800.unk102[0];
    gSpriteEntries[4].unk2F = gUnk_03001800.unk102[1];
    gSpriteEntries[4].unk2B = gUnk_03001800.unk102[6];
    gSpriteEntries[4].unk30 = gUnk_03001800.unk102[5];
    gSpriteEntries[4].unk29 = 0x10;
    tile_anim_init(gUnk_083CEC74[gSpriteEntries[4].unk2B], 0, 0);
    gSpriteEntries[4].unk4 = gUnk_03001800.unk102[3];
    gSpriteEntries[4].unk2C = gUnk_03001800.unk102[7];
    if (!(gUnk_03001800.unkF8 & 2))
        gSpriteEntries[4].unk2 = gUnk_03001800.unk102[2];
    else
        gSpriteEntries[4].unk2 =
            0x1E - (gSpriteEntries[4].unk2E >> 1) - (gUnk_03001800.unk102[2] + (gSpriteEntries[4].unk2E >> 1));
    gSpriteEntries[4].unk2D = 0;
    battle_advance_sequence_counter();
}

void sub_0803B884(void) {
    u32 i;

    for (i = 0; i < 2; i++) {
        gSpriteEntries[i + 0xA].unk28 = (&gUnk_03001800.unk188)[i];
        gSpriteEntries[i + 0xA].unk23 = 0;
        gSpriteEntries[i + 0xA].unk29 = 0x3A;
        gSpriteEntries[i + 0xA].unk26 = i + 0x56;
    }
    play_sound_effect(0x10);
    battle_advance_sequence_counter();
}

void battle_sequence_update_sprites(void) {
    u32 i;

    for (i = 0; i <= 0x26; i++) {
        gUnk_0300056F = i + 1;
        gUnk_083AF96C[gSpriteEntries[i + 1].unk29]();
    }
}

void sub_0803B900(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2B != 0) {
        if (gUnk_03000440.unk12F == 1) {
            if (gUnk_03001800.unk15F != 0) {
                gSpriteEntries[gUnk_03000440.unk12F].unk2B = 0;
                if (gSpriteEntries[gUnk_03000440.unk12F].unk2D != 0) {
                    gSpriteEntries[gUnk_03000440.unk12F].unk29++;
                    gSpriteEntries[gUnk_03000440.unk12F].unk29++;
                } else {
                    gSpriteEntries[gUnk_03000440.unk12F].unk29++;
                }
            }
        } else if (gUnk_03001800.unk160 != 0) {
            gSpriteEntries[gUnk_03000440.unk12F].unk2B = 0;
            if (gSpriteEntries[gUnk_03000440.unk12F].unk2D != 0) {
                gSpriteEntries[gUnk_03000440.unk12F].unk29++;
                gSpriteEntries[gUnk_03000440.unk12F].unk29++;
            } else {
                gSpriteEntries[gUnk_03000440.unk12F].unk29++;
            }
        }
    }
}

void sub_0803B9A4(void) {
    if (gSpriteEntries[gUnk_0300056F].unk30 != 0) {
        gSpriteEntries[gUnk_0300056F].unk30--;
        return;
    }
    if (gUnk_0300056F == 1) {
        if (gUnk_03001800.unkFF & 1) {
            get_active_bot_part_index_and_load_values(0);
            init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                           gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156,
                                           gUnk_03001800.unk39[3] + 2, 4, 0, 0, 0, gUnk_03001800.unk114[0]);
            init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                           gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156,
                                           gUnk_03001800.unk39[3] + 2, 4, 0, 1, 0, gUnk_03001800.unk114[0]);
        }
        gUnk_03001800.unkFF &= ~1;
        gUnk_03001800.unk112 = gSpriteEntries[gUnk_0300056F].unk2C;
    } else {
        if (gUnk_03001800.unkFF & 2) {
            get_active_bot_part_index_and_load_values(1);
            init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                           gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A,
                                           gUnk_03001800.unk39[3] + 2, 8, 1, 0, 1, gUnk_03001800.unk114[1]);
            init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                           gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A,
                                           gUnk_03001800.unk39[3] + 2, 8, 1, 1, 1, gUnk_03001800.unk114[1]);
        }
        gUnk_03001800.unkFF &= ~2;
        gUnk_03001800.unk113 = gSpriteEntries[gUnk_0300056F].unk2C;
    }
    gSpriteEntries[gUnk_03000440.unk12F].unk29 = 1;
}

void sub_0803BBE0(void) {
    struct SpriteEntry *base = gSpriteEntries;
    register u32 i asm("r4") = gUnk_0300056F;
    u8 slot;
    struct Unk_03000440 *p;
    register struct SpriteEntry *q asm("r1") = &base[i];
    register u16 t asm("r3");
    if ((t = q->unk30) != 0) {
        register u16 n asm("r0") = t - 1;
        q->unk30 = n;
        return;
    }
    slot = i;
    p = &gUnk_03000440;
    if (slot == 1) {
        if (gUnk_03001800.unk15F != 0) {
            if (gUnk_03001800.unkFF & 1) {
                get_active_bot_part_index_and_load_values(0);
                init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1],
                                               gUnk_03001800.unk64[2], gUnk_03001800.unk64[3],
                                               (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156,
                                               gUnk_03001800.unk39[3] + 2, 4, 0, 0, 0, gUnk_03001800.unk114[0]);
                init_scene_with_bg_and_palette(0, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1],
                                               gUnk_03001800.unk64[2], gUnk_03001800.unk64[3],
                                               (s16)gUnk_03001800.unk154, (s16)gUnk_03001800.unk156,
                                               gUnk_03001800.unk39[3] + 2, 4, 0, 1, 0, gUnk_03001800.unk114[0]);
            }
            gUnk_03001800.unkFF &= ~1;
            gUnk_03001800.unk112 = gSpriteEntries[gUnk_0300056F].unk2C;
        }
    } else if (gUnk_03001800.unk160 != 0) {
        if (gUnk_03001800.unkFF & 2) {
            get_active_bot_part_index_and_load_values(1);
            init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                           gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A,
                                           gUnk_03001800.unk39[3] + 2, 8, 1, 0, 1, gUnk_03001800.unk114[1]);
            init_scene_with_bg_and_palette(1, gUnk_03001800.unk64[0], gUnk_03001800.unk64[1], gUnk_03001800.unk64[2],
                                           gUnk_03001800.unk64[3], (s16)gUnk_03001800.unk158, (s16)gUnk_03001800.unk15A,
                                           gUnk_03001800.unk39[3] + 2, 8, 1, 1, 1, gUnk_03001800.unk114[1]);
        }
        gUnk_03001800.unkFF &= ~2;
        gUnk_03001800.unk113 = gSpriteEntries[gUnk_0300056F].unk2C;
    }
    if (gSpriteEntries[p->unk12F].unk2D == 0)
        gSpriteEntries[p->unk12F].unk29 = 1;
}

static inline void set_xy(u32 a, u32 b) {
    gUnk_03001800.unk154 = a & 0x1FF;
    gUnk_03001800.unk158 = b & 0x1FF;
}

static inline void set_yx(u32 b, u32 a, u32 m) {
    gUnk_03001800.unk154 = a & m;
    gUnk_03001800.unk158 = b & m;
}

void sub_0803BE44(void) {
    u32 d;
    u8 shift;
    u32 x;
    shift = gUnk_083AFAAC[gUnk_03001800.unk38];
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2C == 0) {
        struct SpriteEntry *q;
        gUnk_03001800.unk154 += gSpriteEntries[gUnk_03000440.unk12F].unk2B;
        gUnk_03001800.unk154 &= 0x1FF;
        gSpriteEntries[gUnk_03000440.unk12F].unk30 += gSpriteEntries[gUnk_03000440.unk12F].unk2B;
        q = &gSpriteEntries[gUnk_03000440.unk12F];
        x = q->unk30;
        if (x > 0x78) {
            register u32 lim asm("r5") = 0x188;
            if (x <= lim) {
                d = ((s16)gUnk_03001800.unk154) - 0x78;
                set_xy(gUnk_03001800.unk154 - d, gUnk_03001800.unk158 - d);
                gBg2Scroll.x += d;
                gBg3Scroll.x += d >> shift;
            } else {
                register u32 y asm("r1") = ((volatile struct SpriteEntry *)q)->unk30;
                if ((s32)(y - 0x188) < q->unk2B) {
                    {
                        register u32 e asm("r0") = q->unk2B + lim;
                        d = e - y;
                    }
                    set_xy(gUnk_03001800.unk154 - d, gUnk_03001800.unk158 - d);
                    gBg2Scroll.x += d;
                    gBg3Scroll.x += d >> shift;
                } else if (y > 0x18F) {
                    q->unk29 = 0;
                }
            }
        }
    } else {
        u32 t;
        register u32 m asm("r5");
        struct SpriteEntry *q;
        gUnk_03001800.unk158 -= gSpriteEntries[gUnk_03000440.unk12F].unk2B;
        m = 0x1FF;
        gUnk_03001800.unk158 &= m;
        gSpriteEntries[gUnk_03000440.unk12F].unk30 -= gSpriteEntries[gUnk_03000440.unk12F].unk2B;
        q = &gSpriteEntries[gUnk_03000440.unk12F];
        t = q->unk30 & m;
        if (((u16)(((volatile struct SpriteEntry *)q)->unk30 - 0x78)) > 0x78) {
            if ((t - 0x78) > 0xEF) {
                d = 0x78 - ((s16)gUnk_03001800.unk158);
                set_yx(gUnk_03001800.unk158 - (-d), gUnk_03001800.unk154 + d, m);
                gBg2Scroll.x -= d;
                gBg3Scroll.x -= d >> shift;
            } else if ((t <= 0x167) && ((0x168 - t) < gSpriteEntries[gUnk_03000440.unk12F].unk2B)) {
                d = gSpriteEntries[gUnk_03000440.unk12F].unk2B - (0x168 - t);
                set_yx(gUnk_03001800.unk158 - (-d), gUnk_03001800.unk154 + d, m);
                gBg2Scroll.x -= d;
                gBg3Scroll.x -= d >> shift;
            } else if (t <= 0x160) {
                gSpriteEntries[gUnk_03000440.unk12F].unk29 = 0;
            }
        }
    }
}

void sub_0803C044(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2D != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk2D--;
        update_sprite_animation_position(gUnk_03000440.unk12F);
        if (gSpriteEntries[3].unk2C == 0) {
            gUnk_03001800.unk154 = gSpriteEntries[gUnk_03000440.unk12F].unk2;
            gUnk_03001800.unk156 = gSpriteEntries[gUnk_03000440.unk12F].unk4;
        } else {
            gUnk_03001800.unk158 = gSpriteEntries[gUnk_03000440.unk12F].unk2;
            gUnk_03001800.unk15A = gSpriteEntries[gUnk_03000440.unk12F].unk4;
        }
    } else {
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
    }
}

void sub_0803C0CC(void) {
    u32 d;
    u32 delta;
    u8 shift;

    if (gSpriteEntries[gUnk_03000440.unk12F].unk2B != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk2B--;
        return;
    }
    shift = gUnk_083AFAAC[gUnk_03001800.unk38];
    if ((u8)(gSpriteEntries[gUnk_03000440.unk12F].unk25 - 1) <= 14) {
        delta = gSpriteEntries[gUnk_03000440.unk12F].unk2;
        update_sprite_animation_position(gUnk_03000440.unk12F);
        delta = gSpriteEntries[gUnk_03000440.unk12F].unk2 - delta;
        gSpriteEntries[gUnk_03000440.unk12F].unk30 += delta;
        if (gSpriteEntries[gUnk_03000440.unk12F].unk30 > 0x78) {
            if (gSpriteEntries[gUnk_03000440.unk12F].unk30 <= 0x188) {
                d = gSpriteEntries[gUnk_03000440.unk12F].unk2 - 0x78;
                gUnk_03001800.unk154 = (gUnk_03001800.unk154 - d) & 0x1FF;
                gUnk_03001800.unk158 = (gUnk_03001800.unk158 - d) & 0x1FF;
                gSpriteEntries[gUnk_03000440.unk12F].unk2 = (gSpriteEntries[gUnk_03000440.unk12F].unk2 - d) & 0x1FF;
                battle_sprite_rotate_angles(1, d);
                gBg2Scroll.x += d;
                gBg3Scroll.x += d >> shift;
            } else if (gSpriteEntries[gUnk_03000440.unk12F].unk30 - 0x188 < delta) {
                d = delta + (0x188 - gSpriteEntries[gUnk_03000440.unk12F].unk30);
                gUnk_03001800.unk154 = (gUnk_03001800.unk154 - d) & 0x1FF;
                gUnk_03001800.unk158 = (gUnk_03001800.unk158 - d) & 0x1FF;
                gSpriteEntries[gUnk_03000440.unk12F].unk2 = (gSpriteEntries[gUnk_03000440.unk12F].unk2 - d) & 0x1FF;
                battle_sprite_rotate_angles(1, d);
                gBg2Scroll.x += d;
                gBg3Scroll.x += d >> shift;
            } else if (gSpriteEntries[gUnk_03000440.unk12F].unk30 > 0x18F) {
                gSpriteEntries[gUnk_03000440.unk12F].unk29 = 0;
            }
        }
    } else if ((u8)(gSpriteEntries[gUnk_03000440.unk12F].unk25 - 0x11) <= 14) {
        u32 t;

        d = gSpriteEntries[gUnk_03000440.unk12F].unk2;
        update_sprite_animation_position(gUnk_03000440.unk12F);
        d = d - gSpriteEntries[gUnk_03000440.unk12F].unk2;
        gSpriteEntries[gUnk_03000440.unk12F].unk30 = (gSpriteEntries[gUnk_03000440.unk12F].unk30 - d) & 0x1FF;
        t = gSpriteEntries[gUnk_03000440.unk12F].unk30;
        if ((u16)(t - 0x78) > 0x78) {
            if (t - 0x78 > 0xEF) {
                d = 0x78 - gSpriteEntries[gUnk_03000440.unk12F].unk2;
                gUnk_03001800.unk154 = (gUnk_03001800.unk154 + d) & 0x1FF;
                gUnk_03001800.unk158 = (gUnk_03001800.unk158 + d) & 0x1FF;
                gSpriteEntries[gUnk_03000440.unk12F].unk2 = (gSpriteEntries[gUnk_03000440.unk12F].unk2 + d) & 0x1FF;
                battle_sprite_rotate_angles(0, d);
                gBg2Scroll.x -= d;
                gBg3Scroll.x -= d >> shift;
            } else if (t <= 0x167 && 0x168 - t < d) {
                d = d - (0x168 - t);
                gUnk_03001800.unk154 = (gUnk_03001800.unk154 + d) & 0x1FF;
                gUnk_03001800.unk158 = (gUnk_03001800.unk158 + d) & 0x1FF;
                gSpriteEntries[gUnk_03000440.unk12F].unk2 = (gSpriteEntries[gUnk_03000440.unk12F].unk2 + d) & 0x1FF;
                battle_sprite_rotate_angles(0, d);
                gBg2Scroll.x -= d;
                gBg3Scroll.x -= d >> shift;
            } else if (t <= 0x160) {
                gSpriteEntries[gUnk_03000440.unk12F].unk29 = 0;
            }
        }
    }
}

void sub_0803C33C(void) {
    u32 d;
    u32 delta;
    u8 shift;

    if (gSpriteEntries[gUnk_03000440.unk12F].unk2B != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk2B--;
        return;
    }
    shift = gUnk_083AFAAC[gUnk_03001800.unk38];
    if ((u8)(gSpriteEntries[gUnk_03000440.unk12F].unk25 - 1) <= 14) {
        delta = gSpriteEntries[gUnk_03000440.unk12F].unk2;
        update_sprite_animation_position(gUnk_03000440.unk12F);
        delta = gSpriteEntries[gUnk_03000440.unk12F].unk2 - delta;
        gSpriteEntries[gUnk_03000440.unk12F].unk30 += delta;
        if (gSpriteEntries[gUnk_03000440.unk12F].unk30 > 0x78) {
            if (gSpriteEntries[gUnk_03000440.unk12F].unk30 <= 0x188) {
                d = gSpriteEntries[gUnk_03000440.unk12F].unk2 - 0x78;
                gUnk_03001800.unk154 = (gUnk_03001800.unk154 - d) & 0x1FF;
                gUnk_03001800.unk158 = (gUnk_03001800.unk158 - d) & 0x1FF;
                gSpriteEntries[gUnk_03000440.unk12F].unk2 = (gSpriteEntries[gUnk_03000440.unk12F].unk2 - d) & 0x1FF;
                battle_sprite_rotate_angles(1, d);
                gBg0Scroll.x += d;
                gBg1Scroll.x += d;
                gBg2Scroll.x += d;
                gBg3Scroll.x += d >> shift;
            } else if (gSpriteEntries[gUnk_03000440.unk12F].unk30 - 0x188 < delta) {
                d = delta + (0x188 - gSpriteEntries[gUnk_03000440.unk12F].unk30);
                gUnk_03001800.unk154 = (gUnk_03001800.unk154 - d) & 0x1FF;
                gUnk_03001800.unk158 = (gUnk_03001800.unk158 - d) & 0x1FF;
                gSpriteEntries[gUnk_03000440.unk12F].unk2 = (gSpriteEntries[gUnk_03000440.unk12F].unk2 - d) & 0x1FF;
                battle_sprite_rotate_angles(1, d);
                gBg0Scroll.x += d;
                gBg1Scroll.x += d;
                gBg2Scroll.x += d;
                gBg3Scroll.x += d >> shift;
            } else if (gSpriteEntries[gUnk_03000440.unk12F].unk30 > 0x18F) {
                gSpriteEntries[gUnk_03000440.unk12F].unk29 = 0;
            }
        }
    } else if ((u8)(gSpriteEntries[gUnk_03000440.unk12F].unk25 - 0x11) <= 14) {
        u32 t;

        d = gSpriteEntries[gUnk_03000440.unk12F].unk2;
        update_sprite_animation_position(gUnk_03000440.unk12F);
        d = d - gSpriteEntries[gUnk_03000440.unk12F].unk2;
        gSpriteEntries[gUnk_03000440.unk12F].unk30 = (gSpriteEntries[gUnk_03000440.unk12F].unk30 - d) & 0x1FF;
        t = gSpriteEntries[gUnk_03000440.unk12F].unk30;
        if ((u16)(t - 0x78) > 0x78) {
            if (t - 0x78 > 0xEF) {
                d = 0x78 - gSpriteEntries[gUnk_03000440.unk12F].unk2;
                gUnk_03001800.unk154 = (gUnk_03001800.unk154 + d) & 0x1FF;
                gUnk_03001800.unk158 = (gUnk_03001800.unk158 + d) & 0x1FF;
                gSpriteEntries[gUnk_03000440.unk12F].unk2 = (gSpriteEntries[gUnk_03000440.unk12F].unk2 + d) & 0x1FF;
                battle_sprite_rotate_angles(0, d);
                gBg0Scroll.x -= d;
                gBg1Scroll.x -= d;
                gBg2Scroll.x -= d;
                gBg3Scroll.x -= d >> shift;
            } else if (t <= 0x167 && 0x168 - t < d) {
                d = d - (0x168 - t);
                gUnk_03001800.unk154 = (gUnk_03001800.unk154 + d) & 0x1FF;
                gUnk_03001800.unk158 = (gUnk_03001800.unk158 + d) & 0x1FF;
                gSpriteEntries[gUnk_03000440.unk12F].unk2 = (gSpriteEntries[gUnk_03000440.unk12F].unk2 + d) & 0x1FF;
                battle_sprite_rotate_angles(0, d);
                gBg0Scroll.x -= d;
                gBg1Scroll.x -= d;
                gBg2Scroll.x -= d;
                gBg3Scroll.x -= d >> shift;
            } else if (t <= 0x160) {
                gSpriteEntries[gUnk_03000440.unk12F].unk29 = 0;
            }
        }
    }
}

void sub_0803C5F8(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2C != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk2C--;
    } else {
        gSpriteEntries[gUnk_03000440.unk12F].unk0 |= 0x8000;
        process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gUnk_03000440.unk12F].unk2D], gUnk_03000440.unk12F);
    }
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2B != 0)
        gSpriteEntries[gUnk_03000440.unk12F].unk2B--;
    else
        update_sprite_animation_position(gUnk_03000440.unk12F);
}

void sub_0803C680(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2C != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk2C--;
    } else {
        gSpriteEntries[gUnk_03000440.unk12F].unk0 |= 0x8000;
        process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gUnk_03000440.unk12F].unk2D], gUnk_03000440.unk12F);
    }
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2B != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk2B--;
    } else {
        update_sprite_animation_position(gUnk_03000440.unk12F);
        gSpriteEntries[gUnk_03000440.unk12F].unk4 += gUnk_083AFAB8[gSpriteEntries[gUnk_03000440.unk12F].unk23];
        gSpriteEntries[gUnk_03000440.unk12F].unk23 = (gSpriteEntries[gUnk_03000440.unk12F].unk23 + 1) & 0x1F;
    }
}

void sub_0803C738(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2C != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk2C--;
    } else {
        gSpriteEntries[gUnk_03000440.unk12F].unk0 |= 0x8000;
        process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gUnk_03000440.unk12F].unk2D], gUnk_03000440.unk12F);
        tile_anim_run_dup(gUnk_083CEC74[gSpriteEntries[gUnk_03000440.unk12F].unk2E], 0);
    }
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2B != 0)
        gSpriteEntries[gUnk_03000440.unk12F].unk2B--;
    else
        update_sprite_animation_position(gUnk_03000440.unk12F);
}

void sub_0803C7DC(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk30 != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk30--;
        return;
    }
    tile_anim_run(gUnk_083CEC74[gSpriteEntries[gUnk_03000440.unk12F].unk2B], 0);
    if (gUnk_03000440.tileAnims[0].state == 0xFF) {
        vram_fill_tilemap_rect(gSpriteEntries[gUnk_03000440.unk12F].unk2E, gSpriteEntries[gUnk_03000440.unk12F].unk2F,
                               gSpriteEntries[gUnk_03000440.unk12F].unk2, gSpriteEntries[gUnk_03000440.unk12F].unk4,
                               REG_BG0CNT, 0);
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
    } else if (gSpriteEntries[gUnk_03000440.unk12F].unk2D == 0) {
        write_tilemap_rect(gSpriteEntries[gUnk_03000440.unk12F].unk2E, gSpriteEntries[gUnk_03000440.unk12F].unk2F,
                           gSpriteEntries[gUnk_03000440.unk12F].unk2, gSpriteEntries[gUnk_03000440.unk12F].unk4,
                           gUnk_083B4AE0[gSpriteEntries[gUnk_03000440.unk12F].unk2C], REG_BG0CNT, 0);
    }
}

void sub_0803C8AC(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk30 != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk30--;
        return;
    }
    tile_anim_run(gUnk_083CEC74[gSpriteEntries[gUnk_03000440.unk12F].unk2B], 1);
    gSpriteEntries[gUnk_03000440.unk12F].unk28++;
    if ((gSpriteEntries[gUnk_03000440.unk12F].unk28 & 1) && gSpriteEntries[gUnk_03000440.unk12F].unk27 == 0) {
        if (!(gUnk_03001800.unkF8 & 2))
            write_tilemap_to_vram_0803F1C8(
                gSpriteEntries[gUnk_03000440.unk12F].unk2E, gSpriteEntries[gUnk_03000440.unk12F].unk2F,
                (gSpriteEntries[gUnk_03000440.unk12F].unk2 + gSpriteEntries[gUnk_03000440.unk12F].unk2D) & 0x3F,
                gSpriteEntries[gUnk_03000440.unk12F].unk4, gUnk_083B4AE0[gSpriteEntries[gUnk_03000440.unk12F].unk2C],
                REG_BG0CNT, 0);
        else
            write_tilemap_to_vram_0803F1C8(
                gSpriteEntries[gUnk_03000440.unk12F].unk2E, gSpriteEntries[gUnk_03000440.unk12F].unk2F,
                (gSpriteEntries[gUnk_03000440.unk12F].unk2 - gSpriteEntries[gUnk_03000440.unk12F].unk2D) & 0x3F,
                gSpriteEntries[gUnk_03000440.unk12F].unk4, gUnk_083B4AE0[gSpriteEntries[gUnk_03000440.unk12F].unk2C],
                REG_BG0CNT, 0);
        gSpriteEntries[gUnk_03000440.unk12F].unk2D++;
    }
}

void sub_0803C9E0(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk30 != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk30--;
        return;
    }
    tile_anim_run(gUnk_083CEC74[gSpriteEntries[gUnk_03000440.unk12F].unk2B], 0);
    if (gUnk_03000440.tileAnims[0].state == 0xFF) {
        tilemap_fill_rect(gSpriteEntries[gUnk_03000440.unk12F].unk2E, gSpriteEntries[gUnk_03000440.unk12F].unk2F,
                          gSpriteEntries[gUnk_03000440.unk12F].unk2, gSpriteEntries[gUnk_03000440.unk12F].unk4,
                          REG_BG0CNT, 0);
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
    } else if (gSpriteEntries[gUnk_03000440.unk12F].unk2D == 0) {
        write_tilemap_to_vram_0803F1C8(
            gSpriteEntries[gUnk_03000440.unk12F].unk2E, gSpriteEntries[gUnk_03000440.unk12F].unk2F,
            gSpriteEntries[gUnk_03000440.unk12F].unk2, gSpriteEntries[gUnk_03000440.unk12F].unk4,
            gUnk_083B4AE0[gSpriteEntries[gUnk_03000440.unk12F].unk2C], REG_BG0CNT, 0);
    }
}

void sub_0803CAB0(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk30 != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk30--;
        return;
    }
    tile_anim_run(gUnk_083CEC74[gSpriteEntries[gUnk_03000440.unk12F].unk2B], 0);
    if (gUnk_03000440.tileAnims[0].state == 0xFF) {
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
    } else if (gSpriteEntries[gUnk_03000440.unk12F].unk2D == 0) {
        write_tilemap_to_vram_0803F1C8(
            gSpriteEntries[gUnk_03000440.unk12F].unk2E, gSpriteEntries[gUnk_03000440.unk12F].unk2F,
            gSpriteEntries[gUnk_03000440.unk12F].unk2, gSpriteEntries[gUnk_03000440.unk12F].unk4,
            gUnk_083B4AE0[gSpriteEntries[gUnk_03000440.unk12F].unk2C], REG_BG0CNT, 0);
    }
}

void sub_0803CB54(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk30 != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk30--;
    } else if (gSpriteEntries[gUnk_03000440.unk12F].unk2C != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk2C--;
    } else if (gSpriteEntries[gUnk_03000440.unk12F].unk2E != 0) {
        play_sound_effect(gSpriteEntries[gUnk_03000440.unk12F].unk2B);
        gSpriteEntries[gUnk_03000440.unk12F].unk2C = gSpriteEntries[gUnk_03000440.unk12F].unk2D;
        gSpriteEntries[gUnk_03000440.unk12F].unk2E--;
    } else {
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
    }
}

void sub_0803CBD0(void) {
    u8 n;

    if (gSpriteEntries[gUnk_03000440.unk12F].unk2B != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk2B--;
        return;
    }
    n = gSpriteEntries[gUnk_03000440.unk12F].unk2E;
    gSpriteEntries[n].unkA = gSpriteEntries[gUnk_03000440.unk12F].unkA;
    gSpriteEntries[n].unk2D = gSpriteEntries[gUnk_03000440.unk12F].unk2D;
    gSpriteEntries[n].unk29 = 0x21;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[n].unk2D], n);
    clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
}

void sub_0803CC40(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gUnk_03000440.unk12F].unk2D], gUnk_03000440.unk12F);
    if (gSpriteEntries[gUnk_03000440.unk12F].unk22 == 0xFF)
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
}

void sub_0803CC8C(void) {
    u32 n;

    if (gSpriteEntries[gUnk_03000440.unk12F].unk2B != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk2B--;
        return;
    }
    if (gSpriteEntries[gUnk_03000440.unk12F].unk28 != gSpriteEntries[gUnk_03000440.unk12F].unk2C) {
        gSpriteEntries[gUnk_03000440.unk12F].unk28++;
        return;
    }
    gSpriteEntries[gUnk_03000440.unk12F].unk28 = 0;
    n = find_next_free_sprite_slot(0xE, 0x10);
    gSpriteEntries[n].unk0 = 0xC404;
    gSpriteEntries[n].unk1C = 0;
    if (!(gUnk_03001800.unkF8 & 2))
        gSpriteEntries[n].unk2 = (gSpriteEntries[gSpriteEntries[gUnk_03000440.unk12F].unk2E].unk2 +
                                  gSpriteEntries[gUnk_03000440.unk12F].unk30) &
                                 0x1FF;
    else
        gSpriteEntries[n].unk2 = (gSpriteEntries[gSpriteEntries[gUnk_03000440.unk12F].unk2E].unk2 +
                                  (gSpriteEntries[gUnk_03000440.unk12F].unk30 * -1)) &
                                 0x1FF;
    gSpriteEntries[n].unk4 =
        (gSpriteEntries[gSpriteEntries[gUnk_03000440.unk12F].unk2E].unk4 + gSpriteEntries[gUnk_03000440.unk12F].unk32) &
        0xFF;
    gSpriteEntries[n].unkA = gSpriteEntries[gUnk_03000440.unk12F].unk27;
    gSpriteEntries[n].unkB = 0x80;
    gSpriteEntries[n].unk29 = 0x23;
    gSpriteEntries[n].unk2D = gSpriteEntries[gUnk_03000440.unk12F].unk2D;
    init_battle_sprite_entry_08040B90(gUnk_083B5F80[gSpriteEntries[gUnk_03000440.unk12F].unk2D], n);
}

void sub_0803CDCC(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gUnk_03000440.unk12F].unk2D], gUnk_03000440.unk12F);
    if (gSpriteEntries[gUnk_03000440.unk12F].unk22 == 0xFF)
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
}

void sub_0803CE18(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2B != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk2B--;
        return;
    }
    bg_palettes_blend_masked_now((gSpriteEntries[gUnk_03000440.unk12F].unk2E << 10) |
                                     (gSpriteEntries[gUnk_03000440.unk12F].unk2D << 5) |
                                     gSpriteEntries[gUnk_03000440.unk12F].unk2C,
                                 gSpriteEntries[gUnk_03000440.unk12F].unk2F, 0xFDFF);
    obj_palettes_blend_masked_now((gSpriteEntries[gUnk_03000440.unk12F].unk2E << 10) |
                                      (gSpriteEntries[gUnk_03000440.unk12F].unk2D << 5) |
                                      gSpriteEntries[gUnk_03000440.unk12F].unk2C,
                                  gSpriteEntries[gUnk_03000440.unk12F].unk2F, 0xB00F);
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2F == 0x10)
        gSpriteEntries[gUnk_03000440.unk12F].unk29 = 0;
    else
        gSpriteEntries[gUnk_03000440.unk12F].unk2F++;
}

void sub_0803CECC(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2B != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk2B--;
        return;
    }
    bg_palettes_blend_masked_now((gSpriteEntries[gUnk_03000440.unk12F].unk2E << 10) |
                                     (gSpriteEntries[gUnk_03000440.unk12F].unk2D << 5) |
                                     gSpriteEntries[gUnk_03000440.unk12F].unk2C,
                                 gSpriteEntries[gUnk_03000440.unk12F].unk2F, 0xFDFF);
    obj_palettes_blend_masked_now((gSpriteEntries[gUnk_03000440.unk12F].unk2E << 10) |
                                      (gSpriteEntries[gUnk_03000440.unk12F].unk2D << 5) |
                                      gSpriteEntries[gUnk_03000440.unk12F].unk2C,
                                  gSpriteEntries[gUnk_03000440.unk12F].unk2F, 0xB00F);
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2F == 0)
        gSpriteEntries[gUnk_03000440.unk12F].unk29 = 0;
    else
        gSpriteEntries[gUnk_03000440.unk12F].unk2F--;
}

void sub_0803CF7C(void) {
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2C)
        gSpriteEntries[gUnk_03000440.unk12F].unk2C--;
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2B)
        gSpriteEntries[gUnk_03000440.unk12F].unk2B--;
    else
        update_sprite_animation_position(gUnk_03000440.unk12F);
}

void sub_0803CFC8(void) {
    struct Coords16 v;

    if (gSpriteEntries[gUnk_03000440.unk12F].unk2C != 0)
        gSpriteEntries[gUnk_03000440.unk12F].unk2C--;
    else {
        gSpriteEntries[gUnk_03000440.unk12F].unk0 |= 0x8000;
        process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gUnk_03000440.unk12F].unk2D], gUnk_03000440.unk12F);
    }
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2B != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk2B--;
        return;
    }
    v = calc_polar_to_screen_coords(gSpriteEntries[gUnk_03000440.unk12F].unk26, 0x10, gSpriteEntries[10].unk2,
                                    gSpriteEntries[10].unk4);
    gSpriteEntries[gUnk_03000440.unk12F].unk2 = v.x;
    gSpriteEntries[gUnk_03000440.unk12F].unk4 = v.y;
    if (!(gUnk_03001800.unkF8 & 2))
        gSpriteEntries[gUnk_03000440.unk12F].unk26 += 0x10;
    else
        gSpriteEntries[gUnk_03000440.unk12F].unk26 -= 0x10;
}

void sub_0803D0BC(void) {
    struct SpriteEntry *s;
    u8 i;

    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gUnk_03000440.unk12F].unk2D], gUnk_03000440.unk12F);
    i = gUnk_03000440.unk12F;
    s = &gSpriteEntries[i];
    if (s->unk23 == 0) {
        if (s->unk8 <= s->unk26) {
            clear_sprite_table_mask(i, 1);
            return;
        }
        s->unk8 -= s->unk26;
        gSpriteEntries[gUnk_03000440.unk12F].unk9 -= gSpriteEntries[gUnk_03000440.unk12F].unk26;
    } else if (s->unk8 == 0x40)
        s->unk29 = 0;
    else {
        s->unk8 += s->unk26;
        gSpriteEntries[gUnk_03000440.unk12F].unk9 += gSpriteEntries[gUnk_03000440.unk12F].unk26;
    }
}

void sub_0803D15C(void) {
    struct Coords16 v;

    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gUnk_03000440.unk12F].unk2D], gUnk_03000440.unk12F);
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2B <= 6) {
        gSpriteEntries[gUnk_03000440.unk12F].unk8 += 8;
        gSpriteEntries[gUnk_03000440.unk12F].unk9 += 8;
    }
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2B > 0x3C) {
        if (gSpriteEntries[gUnk_03000440.unk12F].unk8 == 8)
            clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
        else {
            gSpriteEntries[gUnk_03000440.unk12F].unk8 -= 4;
            gSpriteEntries[gUnk_03000440.unk12F].unk9 -= 4;
        }
    }
    if (gSpriteEntries[gUnk_03000440.unk12F].unk23 == 0) {
        if (!(gSpriteEntries[gUnk_03000440.unk12F].unk2B & 1))
            gSpriteEntries[gUnk_03000440.unk12F].unk27--;
    } else {
        if (!(gSpriteEntries[gUnk_03000440.unk12F].unk2B & 1))
            gSpriteEntries[gUnk_03000440.unk12F].unk27++;
    }
    gSpriteEntries[gUnk_03000440.unk12F].unk26 += 4;
    gSpriteEntries[gUnk_03000440.unk12F].unk2B++;
    v = calc_polar_to_screen_coords(gSpriteEntries[gUnk_03000440.unk12F].unk26,
                                    gSpriteEntries[gUnk_03000440.unk12F].unk27, gSpriteEntries[10].unk2,
                                    gSpriteEntries[10].unk4);
    gSpriteEntries[gUnk_03000440.unk12F].unk2 = v.x;
    gSpriteEntries[gUnk_03000440.unk12F].unk4 = v.y;
}

void sub_0803D2A8(void) {
    u32 done = 0;

    if (gSpriteEntries[gUnk_03000440.unk12F].unk2B != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk2B--;
        return;
    }
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2E != 0) {
        sub_080362C4(gSpriteEntries[gUnk_03000440.unk12F].unk2D);
        sub_08036340(gSpriteEntries[gUnk_03000440.unk12F].unk2D);
        sub_08036370(gSpriteEntries[gUnk_03000440.unk12F].unk2D, gUnk_03001800.unk87);
        sub_080364A8(gSpriteEntries[gUnk_03000440.unk12F].unk2D, gUnk_03001800.unk87);
        gSpriteEntries[gUnk_03000440.unk12F].unk2E = 0;
    }
    if (gSpriteEntries[gUnk_03000440.unk12F].unk2C != 0) {
        gSpriteEntries[gUnk_03000440.unk12F].unk2C--;
        return;
    }
    done = sub_08036BB8(&gUnk_03001800.unkD6[0], gUnk_03001800.unk87, 0);
    done += sub_08036BB8(&gUnk_03001800.unkD6[1], gUnk_03001800.unk87, 1);
    done += sub_08036BB8(&gUnk_03001800.unkD6[2], gUnk_03001800.unk87, 2);
    done += sub_08036BB8(&gUnk_03001800.unkD6[3], gUnk_03001800.unk87, 3);
    sub_08036370(gSpriteEntries[gUnk_03000440.unk12F].unk2D, gUnk_03001800.unk87);
    sub_080364A8(gSpriteEntries[gUnk_03000440.unk12F].unk2D, gUnk_03001800.unk87);
    if (done == 4)
        clear_battle_sprite_slot(gUnk_03000440.unk12F, 1);
}

void sub_0803D3C0(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gUnk_03000440.unk12F].unk26], gUnk_03000440.unk12F);
    if (sprite_hop_step(gUnk_03000440.unk12F)) {
        gSpriteEntries[gUnk_03000440.unk12F].unk6 = 0x6307 + gSpriteEntries[gUnk_03000440.unk12F].unk28;
        gSpriteEntries[gUnk_03000440.unk12F].unk29 = 0;
    }
}

s16 sub_0803D424(void) {
    const s16 *seq = gUnk_083CDFE4[gUnk_03001800.unkF9];
    return seq[gUnk_03001800.unk100];
}

void load_battle_sequence_commands(void) {
    const s16 *seq = gUnk_083CDFE4[gUnk_03001800.unkF9];
    u32 n = gUnk_083CE1F4[seq[gUnk_03001800.unk100]];
    u32 i;

    for (i = 0; i < n; i++)
        gUnk_03001800.unk102[i] = seq[gUnk_03001800.unk100 + i + 1];
}

void battle_advance_sequence_counter(void) {
    const s16 *seq = gUnk_083CDFE4[gUnk_03001800.unkF9];
    const u8 *ops = gUnk_083CE1F4;
    s32 p = gUnk_03001800.unk100;

    gUnk_03001800.unk100 = p + 1 + ops[seq[p]];
}

static void battle_sprite_rotate_angles(u32 dir, u32 delta) {
    u32 i;
    for (i = 0; i <= 0x13; i++) {
        if (gSpriteEntries[i + 10].unk29 != 0) {
            if (dir)
                gSpriteEntries[i + 10].unk2 = (gSpriteEntries[i + 10].unk2 - delta) & 0x1FF;
            else
                gSpriteEntries[i + 10].unk2 = (gSpriteEntries[i + 10].unk2 + delta) & 0x1FF;
        }
    }
}
