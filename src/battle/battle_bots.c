// The Medabots in a battle (gUnk_03000590, 6 records: 0-2 player, 3-5 opponent): team setup from the
// player's Medals and parts, opponent setup, then each turn's action processing, part and Medaforce
// selection and the AI's part order. Called from battle/robattle and battle/prebattle.

#include "global.h"

static void copy_player_medals_to_battle_bots(void);
static u32 battle_dispatch_action_by_type(u32 rec);
static u32 sub_08015648(u32 rec);
static u32 battle_part_unusable(u32 rec, u32 part);

void clear_battle_bot_array(void) {
    mem_fill8((u8 *)gUnk_03000590, 0x600, 0);
}

void count_active_battle_bots(void) {
    u32 i;
    u32 n;

    for (i = 0, n = 0; i <= 2; i++) {
        if (gUnk_03001800.unk41[i])
            n++;
    }
    gUnk_03001800.unk5A = n;
    gUnk_03001800.unk5B = gUnk_03001800.unk2;
}

void battle_setup_team_bots(void) {
    copy_player_medals_to_battle_bots();
    copy_team_slots_to_battle_bots();
    battle_bots_load_parts(0, gUnk_03001800.unk5A);
}

static void copy_player_medals_to_battle_bots(void) {
    u32 i;

    for (i = 0; i < gUnk_03001800.unk5A; i++)
        memcpy_bytes_0803F63C(
            &gUnk_03000BE0[find_medal_slot_by_id(gUnk_030017A0[gUnk_03001800.unk41[i] & 0xF].unk2) - 1],
            &gUnk_03000590[i], 0x40);
}

void copy_team_slots_to_battle_bots(void) {
    u32 i;

    for (i = 0; i < gUnk_03001800.unk5A; i++)
        memcpy_bytes_0803F63C(&gUnk_030017A0[gUnk_03001800.unk41[i] & 0xF], &gUnk_03000590[i].unk40, 8);
}

void battle_bots_load_parts(u32 rec, u32 n) {
    u32 i;

    for (i = 0; i < n; rec++, i++) {
        gUnk_03000590[rec].unkB8 = rec;
        gUnk_03000590[rec].unkBA = 1;
        load_part_data(gUnk_03000590[rec].unk43, 0, &gUnk_03000440.unkEE);
        memcpy_bytes_0803F63C(&gUnk_03000440.unkEE, gUnk_03000590[rec].parts[0].data, 0xD);
        gUnk_03000590[rec].parts[0].unk10 = gUnk_03000590[rec].parts[0].data[8];
        gUnk_03000590[rec].parts[0].unk11 = gUnk_03000590[rec].parts[0].data[4];
        gUnk_03000590[rec].parts[0].unk17 = gUnk_03000590[rec].unk43;
        load_part_data(gUnk_03000590[rec].unk44, 1, &gUnk_03000440.unkEE);
        memcpy_bytes_0803F63C(&gUnk_03000440.unkEE, gUnk_03000590[rec].parts[1].data, 0xD);
        gUnk_03000590[rec].parts[1].unk11 = gUnk_03000590[rec].parts[1].data[4];
        gUnk_03000590[rec].parts[1].unk17 = gUnk_03000590[rec].unk44;
        load_part_data(gUnk_03000590[rec].unk45, 2, &gUnk_03000440.unkEE);
        memcpy_bytes_0803F63C(&gUnk_03000440.unkEE, gUnk_03000590[rec].parts[2].data, 0xD);
        gUnk_03000590[rec].parts[2].unk11 = gUnk_03000590[rec].parts[2].data[4];
        gUnk_03000590[rec].parts[2].unk17 = gUnk_03000590[rec].unk45;
        load_part_data(gUnk_03000590[rec].unk46, 3, &gUnk_03000440.unkEE);
        memcpy_bytes_0803F63C(&gUnk_03000440.unkEE, gUnk_03000590[rec].parts[3].data, 0xD);
        memcpy_bytes_0803F63C(&gUnk_03000590[rec].parts[3].data[4], &gUnk_03000590[rec].parts[3].unk11, 6);
        gUnk_03000590[rec].parts[3].unk17 = gUnk_03000590[rec].unk46;
    }
}

void init_opponent_bots(void) {
    u32 i;

    for (i = 0; i < gUnk_03001800.unk5B; i++)
        init_enemy_bot_medal(i);
    init_opponent_bot_slots();
    battle_bots_load_parts(3, gUnk_03001800.unk5B);
}

void init_enemy_bot_medal(u8 i) {
    u32 k;
    u32 v;
    u32 lvl;

    memcpy_bytes_08041D04(gUnk_083B6158[gUnk_03001800.unk4[i].unk4], &gUnk_03000440.unkEE, 16);
    gUnk_03000590[i + 3].medal.unk0 = 0x80;
    gUnk_03000590[i + 3].medal.unk1 = (&gUnk_03000440.unkEE)[0];
    gUnk_03000590[i + 3].medal.unk4 = (&gUnk_03000440.unkEE)[1];
    gUnk_03000590[i + 3].medal.unk5 = gUnk_03001800.unk4[i].unk5;
    gUnk_03000590[i + 3].medal.unk6 = (&gUnk_03000440.unkEE)[2];
    gUnk_03000590[i + 3].medal.unk7 = (&gUnk_03000440.unkEE)[7];
    gUnk_03000590[i + 3].medal.unk9 = gUnk_03001800.unk4[i].unkA;
    memcpy_bytes_08041D04((const void *)gUnk_083BA4D8[gUnk_03001800.unk4[i].parts[0]], gUnk_03000590[i + 3].medal.unkA,
                          0xE);
    for (k = 0; k <= 3; k++) {
        gUnk_03000590[i + 3].medal.unk18[k * 2] = gUnk_03001800.unk4[i].unk6[k] >> 4;
        gUnk_03000590[i + 3].medal.unk18[k * 2 + 1] = gUnk_03001800.unk4[i].unk6[k] & 0xF;
    }
    for (k = 0; k <= 7; k++) {
        v = gUnk_083AD200[gUnk_03000590[i + 3].medal.unk4 * 8 + k];
        lvl = gUnk_03000590[i + 3].medal.unk5 >> 1;
        if (lvl)
            v *= lvl;
        if (v == 0)
            v = 1;
        else if (v > 100)
            v = 100;
        gUnk_03000590[i + 3].medal.unk20[k] = v;
    }
}

void init_opponent_bot_slots(void) {
    u32 i;

    for (i = 0; i < gUnk_03001800.unk5B; i++) {
        gUnk_03000590[i + 3].unk40 = 3;
        load_part_data(gUnk_03001800.unk4[i].parts[0], 0, &gUnk_03000440.unkEE);
        gUnk_03000590[i + 3].unk41 = (&gUnk_03000440.unkEE)[3];
        gUnk_03000590[i + 3].unk42 = gUnk_03000590[i + 3].medal.unk1;
        gUnk_03000590[i + 3].unk43 = gUnk_03001800.unk4[i].parts[0];
        gUnk_03000590[i + 3].unk44 = gUnk_03001800.unk4[i].parts[1];
        gUnk_03000590[i + 3].unk45 = gUnk_03001800.unk4[i].parts[2];
        gUnk_03000590[i + 3].unk46 = gUnk_03001800.unk4[i].parts[3];
    }
}

void battle_process_all_bots_actions(void) {
    u32 i;

    if (gUnk_03000440.unk89 != 1 || gUnk_03000B90 == 0) {
        for (i = 0; i <= 5; i++) {
            if (gUnk_03000590[i].unk40)
                battle_process_all_bot_actions(i);
        }
    } else {
        for (i = 3; i <= 5; i++) {
            if (gUnk_03000590[i].unk40)
                battle_process_all_bot_actions(i);
        }
        for (i = 0; i <= 2; i++) {
            if (gUnk_03000590[i].unk40)
                battle_process_all_bot_actions(i);
        }
    }
}

void battle_process_bot_actions_for_side(u32 side) {
    u32 i;
    u32 rec;

    for (i = 0; i <= 2; i++) {
        rec = side + i;
        if (gUnk_03000590[side + i].unk40 && battle_dispatch_action_by_type(rec))
            select_bot_battle_action(rec);
    }
}

void process_bot_battle_turn(u32 rec) {
    if (gUnk_03000590[rec].unkC9 == 0x2C)
        select_bot_battle_action(rec);
    else if (battle_dispatch_action_by_type(rec))
        select_bot_battle_action(rec);
}

static u32 battle_dispatch_action_by_type(u32 rec) {
    u32 type = gUnk_03000590[rec].medal.unk18[gUnk_03000590[rec].medal.unk3F];

    switch (type) {
    case 0:
        return 1;
    case 1:
    case 2:
    case 3:
        if (battle_part_unusable(rec, type))
            return 1;
        battle_bot_select_part(rec, type);
        return 0;
    case 4:
        battle_bot_select_part(rec, 0);
        return 0;
    case 5:
    case 6:
    case 7:
        if (check_medaforce_availability(rec, type - 5, 0))
            return 1;
        return 0;
    }
}

void battle_bot_advance_rotation(u32 rec) {
    if (++gUnk_03000590[rec].medal.unk3F == 8)
        gUnk_03000590[rec].medal.unk3F = gUnk_03000590[rec].medal.unk9;
}

static void battle_advance_all_rotations(void) {
    u32 i;

    for (i = 0; i <= 5; i++) {
        if (gUnk_03000590[i].unk40)
            battle_bot_advance_rotation(i);
    }
}

void select_bot_battle_action(u32 rec) {
    u32 i;

    if (gUnk_03000590[rec].unkC1 == 0x50 && (rng_next_byte() & 1) && !check_medaforce_availability(rec, 0, 1))
        return;
    battle_ai_roll_part_order();
    for (i = 0; i <= 3; i++) {
        if (gUnk_03001800.unk64[i] == 0xFF) {
            battle_bot_select_part(rec, 0);
            return;
        }
        if (!battle_part_unusable(rec, gUnk_03001800.unk64[i])) {
            battle_bot_select_part(rec, gUnk_03001800.unk64[i]);
            return;
        }
    }
    battle_bot_select_part(rec, 0);
}

u32 sub_080154E0(u32 rec, u32 part) {
    if (gUnk_03000590[rec].unkC9 == 0x2B && gUnk_03000590[rec].unkCA == part)
        return 1;
    return 0;
}

static u32 sub_08015508(u32 rec, u32 part) {
    if (part == 1 && gUnk_03000590[rec].parts[0].unk10 == 0)
        return 1;
    return 0;
}

static u32 sub_08015528(u32 rec, u32 part) {
    if (gUnk_03000590[rec].parts[part - 1].unk11 == 0)
        return 1;
    return 0;
}

u32 sub_0801554C(u32 a, u32 b) {
    if (b == 0) {
        if (a <= 2)
            return 0;
        return 1;
    }
    if (a <= 2)
        return 1;
    return 0;
}

void battle_bot_select_part(u32 rec, u32 part) {
    gUnk_03000590[rec].unkDD = part;
    if (part == 0)
        return;
    if (part <= 3) {
        gUnk_03000590[rec].unkE0 = gUnk_03000590[rec].parts[part - 1].unkE;
        gUnk_03000590[rec].unkE1 = gUnk_03000590[rec].parts[part - 1].unkF;
    }
}

u32 check_medaforce_availability(u32 rec, u32 slot, u32 random) {
    u32 i;

    if (sub_08015648(rec) || gUnk_03001800.unk58 || gUnk_03000590[rec].unkC1 != 0x50)
        return 1;
    if (random)
        slot = rng_lookup_table_value();
    for (i = 0; i <= 2; i++) {
        if (slot == 0) {
            if (gUnk_03000590[rec].medal.unk5 > 9) {
                battle_bot_select_medaforce(rec, 0);
                return 0;
            }
            if (!random)
                return 1;
        }
        if (slot == 1) {
            if (gUnk_03000590[rec].medal.unk5 > 29) {
                battle_bot_select_medaforce(rec, 1);
                return 0;
            }
            if (!random)
                return 1;
        }
        if (slot == 2) {
            if (gUnk_03000590[rec].medal.unk5 > 59) {
                battle_bot_select_medaforce(rec, 2);
                return 0;
            }
            if (!random)
                return 1;
        }
        if (slot == 0)
            return 1;
        slot--;
    }
}

static u32 sub_08015648(u32 rec) {
    if (rec <= 2 || gUnk_030057E0.unk7FF > 2)
        return 0;
    return 1;
}

void battle_bot_select_medaforce(u32 rec, u32 part) {
    memcpy_bytes_08041D04(&gUnk_083B7E0C[gUnk_03000590[rec].medal.unk1 * 3], &gUnk_03000440.unkEE, 3);
    memcpy_bytes_08041D04(&gUnk_083B7CD4[(&gUnk_03000440.unkEE)[part] * 6], gUnk_03000590[rec].unkA8, 6);
    battle_bot_select_part(rec, part + 4);
}

void battle_ai_roll_part_order(void) {
    memcpy_bytes_08041D04(gUnk_083AD2F0[rng_next_byte() & 0x1F], gUnk_03001800.unk64, 4);
}

static u32 battle_part_unusable(u32 rec, u32 part) {
    if (!sub_080154E0(rec, part) && !sub_08015508(rec, part) && !sub_08015528(rec, part) &&
        !begin_battle_action_lookup(rec, part))
        return 0;
    return 1;
}
