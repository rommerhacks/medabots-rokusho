// Robattle turn order: robattle_judge_time_up (winner when TIME runs out), select_next_bot_and_action,
// find_next_active_bot, determine_battle_part_action_priority. Called from the battle action state code.

#include "global.h"

static u32 sub_0801B4C8(u32 first) {
    u32 n = 0;
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[first + i].unkBA == 2)
            n++;
    }
    return n;
}

static u32 battle_count_broken_parts(u32 first) {
    u32 n = 0;
    u32 i, j;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[first + i].unkBA) {
            for (j = 0; j <= 3; j++) {
                if (gUnk_03000590[first + i].parts[j].unk11 == 0)
                    n++;
            }
        }
    }
    return n;
}

// Decides the Robattle winner from the team / opponent records: fewer Medabots with unkBA == 2, then fewer
// broken parts, then the larger gUnk_03001800.unk28[side].unk1, then a coin flip (mirrored on link player 1).
// gUnk_03000440.unk9C = 1 team wins, 2 opponents win. Called by sub_08031120 when TIME (unk57) is 0.
void robattle_judge_time_up(void) {
    u32 team = sub_0801B4C8(0);
    u32 opp = sub_0801B4C8(3);

    if (team < opp)
        gUnk_03000440.unk9C = 1;
    else if (opp < team)
        gUnk_03000440.unk9C = 2;
    else {
        team = battle_count_broken_parts(0);
        opp = battle_count_broken_parts(3);
        if (team < opp)
            gUnk_03000440.unk9C = 1;
        else if (opp < team)
            gUnk_03000440.unk9C = 2;
        else if (gUnk_03001800.unk28[0].unk1 > gUnk_03001800.unk28[1].unk1)
            gUnk_03000440.unk9C = 1;
        else if (gUnk_03001800.unk28[0].unk1 < gUnk_03001800.unk28[1].unk1)
            gUnk_03000440.unk9C = 2;
        else if (gUnk_03000440.unk89 != 1) {
            if (rng_next_080424B8() & 1)
                gUnk_03000440.unk9C = 1;
            else
                gUnk_03000440.unk9C = 2;
        } else if (gUnk_03000B90 == 0) {
            if (rng_next_080424B8() & 1)
                gUnk_03000440.unk9C = 1;
            else
                gUnk_03000440.unk9C = 2;
        } else {
            if (rng_next_080424B8() & 1)
                gUnk_03000440.unk9C = 2;
            else
                gUnk_03000440.unk9C = 1;
        }
    }
}

void reset_bot_status_and_init_palette_transfers(u32 rec) {
    u32 z0, z1, z2, z3, z4;

    gUnk_03000590[rec].unkBC = 0;
    gUnk_03000590[rec].unkBD &= 0xE5;
    z0 = 0;
    CpuSet(&z0, gUnk_030018A8, 0x05000008);
    z1 = 0;
    CpuSet(&z1, gUnk_030018A8 + 8, 0x05000008);
    z2 = 0;
    CpuSet(&z2, gUnk_030018A8 + 16, 0x05000004);
    z3 = 0;
    CpuSet(&z3, gUnk_030018A8 + 20, 0x05000008);
    z4 = 0;
    CpuSet(&z4, gUnk_030018A8 + 47, 0x05000001);
}

void sub_0801B67C(u32 rec) {
    if (rec <= 2)
        gUnk_03001800.unkF8 = 0;
    else
        gUnk_03001800.unkF8 = 3;
}

void select_next_bot_and_action(u32 rec) {
    if (gUnk_03000590[rec].unkC9 == 0x2C) {
        if (gUnk_03000590[rec].parts[gUnk_03000590[rec].unkDD - 1].data[2] <= 3 ||
            gUnk_03000590[rec].parts[gUnk_03000590[rec].unkDD - 1].data[1] == 0x34) {
            gUnk_03000590[rec].unkE0 = find_next_active_bot(rec) + 1;
            gUnk_03000590[rec].unkE1 = sub_080330E8(gUnk_03000590[rec].unkE0 - 1) + 1;
        }
    }
}

u32 find_next_active_bot(u32 rec) {
    u32 k = rng_next_080424B8() & 0x1F;
    u32 i;
    u32 r;

    for (i = 0; i <= 5; i++) {
        r = gUnk_083AD3D3[k];
        if (gUnk_03000440.unk89 == 1 && gUnk_03000B90)
            r = gUnk_083AD3F3[r];
        if (gUnk_03000590[r].unk40 && rec != r)
            return r;
        k = (k + 1) & 0x1F;
    }
    return 0;
}

void determine_battle_part_action_priority(void) {
    gUnk_03001800.unk15C[0] = 0;
    gUnk_03001800.unk15C[1] = 0;
    gUnk_03001800.unk15C[2] = 0;

    if (gUnk_03000590[gUnk_03001800.unk80].parts[0].unk10 == 0)
        gUnk_03001800.unk15C[0] = 4;
    if (sub_08016E5C(gUnk_03001800.unk80, 0))
        gUnk_03001800.unk15C[0] = 3;
    if (gUnk_03000590[gUnk_03001800.unk80].unkC9 == 0x2B && gUnk_03000590[gUnk_03001800.unk80].unkCA == 1)
        gUnk_03001800.unk15C[0] = 2;

    if (sub_08016E5C(gUnk_03001800.unk80, 1))
        gUnk_03001800.unk15C[1] = 3;
    if (gUnk_03000590[gUnk_03001800.unk80].unkC9 == 0x2B && gUnk_03000590[gUnk_03001800.unk80].unkCA == 2)
        gUnk_03001800.unk15C[1] = 2;
    if (gUnk_03000590[gUnk_03001800.unk80].parts[1].unk11 == 0)
        gUnk_03001800.unk15C[1] = 1;

    if (sub_08016E5C(gUnk_03001800.unk80, 2))
        gUnk_03001800.unk15C[2] = 3;
    if (gUnk_03000590[gUnk_03001800.unk80].unkC9 == 0x2B && gUnk_03000590[gUnk_03001800.unk80].unkCA == 3)
        gUnk_03001800.unk15C[2] = 2;
    if (gUnk_03000590[gUnk_03001800.unk80].parts[2].unk11 == 0)
        gUnk_03001800.unk15C[2] = 1;
}

void sub_0801B894(void) {
    clear_battle_sprite_slot(9, 1);
    if (gUnk_03001800.unk82 != 0 && gUnk_03001800.unk15C[gUnk_03001800.unk82 - 1] == 0 &&
        gUnk_03000590[gUnk_03001800.unk80].parts[gUnk_03001800.unk82 - 1].unkE) {
        gUnk_03002C30[9].unk0 = 0xC404;
        gUnk_03002C30[9].unk1C = 0;
        gUnk_03002C30[9].unk4 =
            gUnk_03002C30[gUnk_03000590[gUnk_03001800.unk80].parts[gUnk_03001800.unk82 - 1].unkE * 4 + 0x59].unk4 - 4;
        gUnk_03002C30[9].unk2 =
            gUnk_03002C30[gUnk_03000590[gUnk_03001800.unk80].parts[gUnk_03001800.unk82 - 1].unkE * 4 + 0x59].unk2;
        gUnk_03002C30[9].unkA = 6;
        gUnk_03002C30[9].unkB = 0xF0;
        gUnk_03002C30[9].unk24 = gUnk_03000590[gUnk_03001800.unk80].parts[gUnk_03001800.unk82 - 1].unkF;
        gUnk_03002C30[9].unk25 = gUnk_03000590[gUnk_03001800.unk80].parts[gUnk_03001800.unk82 - 1].unkE;
        gUnk_03002C30[9].unk26 = 0;
        gUnk_03002C30[9].unk27 = 0;
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[24], 9);
    }
}

void sub_0801B9C4(void) {
    if (gUnk_03002C30[9].unk0 & 0x8000) {
        process_sprite_anim_commands(gUnk_083B5F80[24], 9);
        if (gUnk_03002C30[9].unk24) {
            gUnk_03002C30[9].unk27++;
            gUnk_03002C30[(gUnk_03002C30[9].unk25 - 1) * 4 + gUnk_03002C30[9].unk24 + 0x59].unk0 |= 0x220;
            if (gUnk_03002C30[9].unk26 == 0) {
                gUnk_03002C30[(gUnk_03002C30[9].unk25 - 1) * 4 + gUnk_03002C30[9].unk24 + 0x59].unk8 =
                    gUnk_03002C30[9].unk27 * 2 + 0x40;
                gUnk_03002C30[(gUnk_03002C30[9].unk25 - 1) * 4 + gUnk_03002C30[9].unk24 + 0x59].unk9 =
                    gUnk_03002C30[9].unk27 * 2 + 0x40;
            } else {
                gUnk_03002C30[(gUnk_03002C30[9].unk25 - 1) * 4 + gUnk_03002C30[9].unk24 + 0x59].unk8 =
                    0x60 - gUnk_03002C30[9].unk27 * 2;
                gUnk_03002C30[(gUnk_03002C30[9].unk25 - 1) * 4 + gUnk_03002C30[9].unk24 + 0x59].unk9 =
                    0x60 - gUnk_03002C30[9].unk27 * 2;
            }
            if (gUnk_03002C30[9].unk27 > 0x10) {
                gUnk_03002C30[9].unk26 ^= 1;
                gUnk_03002C30[9].unk27 = 0;
            }
        }
    }
}

void sub_0801BACC(void) {
    if (gUnk_03002C30[9].unk0 & 0x8000) {
        if (gUnk_03002C30[9].unk24) {
            gUnk_03002C30[(gUnk_03002C30[9].unk25 - 1) * 4 + gUnk_03002C30[9].unk24 + 0x59].unk8 = 0x40;
            gUnk_03002C30[(gUnk_03002C30[9].unk25 - 1) * 4 + gUnk_03002C30[9].unk24 + 0x59].unk9 = 0x40;
            if (gUnk_03001800.unk80 == gUnk_03002C30[9].unk25 - 1) {
                if ((u8)(gUnk_03002C30[9].unk24 - 2) <= 1)
                    gUnk_03002C30[gUnk_03001800.unk80 * 4 + gUnk_03002C30[9].unk24 + 0x59].unk0 &= 0xFFDF;
                else
                    gUnk_03002C30[gUnk_03001800.unk80 * 4 + gUnk_03002C30[9].unk24 + 0x59].unk0 &= 0xFDDF;
            }
        }
        clear_battle_sprite_slot(9, 1);
    }
}
