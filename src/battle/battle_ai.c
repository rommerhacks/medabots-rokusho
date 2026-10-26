// Battle AI and action checks. battle_process_all_bot_actions runs, for each of a Medabot's three parts,
// the target picker gUnk_083AED20[ability] (enemy / ally / most damaged / broken part / status pickers,
// select_*_battle_target). begin_battle_action_lookup runs the usability check gUnk_083AEF10[ability]
// (sub_08033364..sub_080337CC set unk51 = 1 when the action can't be used). Called from battle_bots
// (turn actions) and the action phase; reads the bot records gUnk_03000590.

#include "global.h"

static void clear_battle_action_selection(void);
static u32 sub_08032FD0(u32 rec, u32 val);
static u32 sub_08032FFC(void);
static u32 select_battle_pending_action(void);
static void sub_08033154(u32 rec, u32 part);
static u32 sub_08033224(u32 rec);
static u32 sub_08033240(u32 rec);
static u32 sub_080332B4(u32 rec);
static u32 sub_080332D0(u32 rec);

void battle_process_all_bot_actions(u32 rec) {
    u32 i;

    gUnk_03001800.unk5C = rec;
    gUnk_03001800.unk5D = 0;
    for (i = 0; i <= 2; i++) {
        battle_execute_action_selection();
        call_bot_action_handler();
        gUnk_03001800.unk5D++;
    }
}

void battle_execute_action_selection(void) {
    clear_battle_action_selection();
    sub_0803F624(gUnk_03001800.unk61, 3, 0);
    gUnk_083AED20[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].data[1]]();
}

void call_bot_action_handler(void) {
    gUnk_083AEE10[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].data[1]]();
}

void select_battle_targets_and_actions(void) {
    u32 i;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40 &&
            sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else {
        gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
        gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
    }
    gUnk_03001800.unk5F = sub_080330E8(gUnk_03001800.unk5E - 1) + 1;
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void battle_ai_select_target_defend(void) {
    u32 i;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40 && gUnk_03000590[gUnk_03001800.unk60].parts[3].data[1] == 0x64 &&
            sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else {
        gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40 && gUnk_03000590[gUnk_03001800.unk60].parts[3].data[1] == 0x64)
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else {
            gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40 &&
                    sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else {
                gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    gUnk_03001800.unk5F = sub_080330E8(gUnk_03001800.unk5E - 1) + 1;
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void battle_ai_select_target_jump(void) {
    u32 i;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40 && gUnk_03000590[gUnk_03001800.unk60].parts[3].data[1] == 0x6A &&
            sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else {
        gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40 && gUnk_03000590[gUnk_03001800.unk60].parts[3].data[1] == 0x6A)
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else {
            gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40 &&
                    sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else {
                gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    gUnk_03001800.unk5F = sub_080330E8(gUnk_03001800.unk5E - 1) + 1;
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void ai_select_target_enemy_side_ability22_status(void) {
    u32 i;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40 && sub_080331F8(gUnk_03001800.unk60) &&
            gUnk_03000590[gUnk_03001800.unk60].unkC9 &&
            sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else {
        gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40 && sub_080331F8(gUnk_03001800.unk60) &&
                gUnk_03000590[gUnk_03001800.unk60].unkC9)
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else {
            gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40 && sub_080331F8(gUnk_03001800.unk60) &&
                    sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else {
                gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    gUnk_03001800.unk5F = sub_080330E8(gUnk_03001800.unk5E - 1) + 1;
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void ai_pick_ally_most_damaged(void) {
    u32 i;
    u32 part;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40 && find_most_damaged_part(gUnk_03001800.unk60) &&
            sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else {
        gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40 && find_most_damaged_part(gUnk_03001800.unk60))
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else {
            gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40 &&
                    sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else {
                gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    part = find_most_damaged_part(gUnk_03001800.unk5E - 1);
    if (part)
        gUnk_03001800.unk5F = part;
    else
        gUnk_03001800.unk5F = sub_080330E8(gUnk_03001800.unk5E - 1) + 1;
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void battle_ai_select_target_ability22_enemy(void) {
    u32 i;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40 && sub_080331F8(gUnk_03001800.unk60) &&
            sub_08033224(gUnk_03001800.unk60) &&
            sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else {
        gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40 && sub_080331F8(gUnk_03001800.unk60) &&
                sub_08033224(gUnk_03001800.unk60))
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else {
            gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40 &&
                    sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else {
                gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void ai_pick_ally_with_broken_part(void) {
    u32 i;
    u32 part;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40 && find_random_broken_part(gUnk_03001800.unk60) &&
            sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else {
        gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40 && find_random_broken_part(gUnk_03001800.unk60))
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else {
            gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40 &&
                    sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else {
                gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    part = find_random_broken_part(gUnk_03001800.unk5E - 1);
    if (part)
        gUnk_03001800.unk5F = part;
    else
        gUnk_03001800.unk5F = sub_080330E8(gUnk_03001800.unk5E - 1) + 1;
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void select_enemy_battle_target(void) {
    u32 i;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60].unkBA == 2 &&
            sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else {
        gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gUnk_03000590[gUnk_03001800.unk60].unkBA == 2)
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else {
            gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++) {
                if (sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else {
                gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void select_battle_target_for_bot(void) {
    u32 i;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40 && gUnk_03001800.unk60 != gUnk_03001800.unk5C &&
            sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else {
        gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40 && gUnk_03001800.unk60 != gUnk_03001800.unk5C)
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else {
            gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
            gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
        }
    }
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void battle_ai_select_target_ability22_ally(void) {
    u32 i;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40 && sub_080331F8(gUnk_03001800.unk60) &&
            sub_08033240(gUnk_03001800.unk60) &&
            sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else {
        gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40 && sub_080331F8(gUnk_03001800.unk60) &&
                sub_08033240(gUnk_03001800.unk60))
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else {
            gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40 &&
                    sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else {
                gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void battle_ai_select_target_status58(void) {
    u32 i;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40 && sub_080332B4(gUnk_03001800.unk60) &&
            sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else {
        gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40 && sub_080332B4(gUnk_03001800.unk60))
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else {
            gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40 &&
                    sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else {
                gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    gUnk_03001800.unk5F = 1;
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void select_player_battle_target(void) {
    u32 i;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40 && sub_080332D0(gUnk_03001800.unk60) &&
            sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else {
        gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40 && sub_080332D0(gUnk_03001800.unk60))
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else {
            gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40 &&
                    sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else {
                gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

void ai_select_target_player_side_ability22(void) {
    u32 i;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60].unk40 && sub_080331F8(gUnk_03001800.unk60) &&
            sub_08033240(gUnk_03001800.unk60) &&
            sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
            gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
        gUnk_03001800.unk60++;
    }
    if (sub_08032FFC())
        gUnk_03001800.unk5E = select_battle_pending_action() + 1;
    else {
        gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
        for (i = 0; i <= 2; i++) {
            if (gUnk_03000590[gUnk_03001800.unk60].unk40 && sub_080331F8(gUnk_03001800.unk60) &&
                sub_08033240(gUnk_03001800.unk60))
                gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
            gUnk_03001800.unk60++;
        }
        if (sub_08032FFC())
            gUnk_03001800.unk5E = select_battle_pending_action() + 1;
        else {
            gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
            for (i = 0; i <= 2; i++) {
                if (gUnk_03000590[gUnk_03001800.unk60].unk40 &&
                    sub_08032FD0(gUnk_03001800.unk60, gUnk_03000590[gUnk_03001800.unk5C].medal.unk6))
                    gUnk_03001800.unk61[i] = gUnk_03001800.unk60 + 1;
                gUnk_03001800.unk60++;
            }
            if (sub_08032FFC())
                gUnk_03001800.unk5E = select_battle_pending_action() + 1;
            else {
                gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
                gUnk_03001800.unk5E = select_random_battle_target(gUnk_03001800.unk60) + 1;
            }
        }
    }
    gUnk_03001800.unk5F = battle_find_next_active_bot(gUnk_03001800.unk5E - 1) + 1;
    sub_08033154(gUnk_03001800.unk5C, gUnk_03001800.unk5D);
}

static void clear_battle_action_selection(void) {
    gUnk_03001800.unk5E = 0;
    gUnk_03001800.unk5F = 0;
    gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE = 0;
    gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkF = 0;
}

u32 sub_08032FB8(u32 a) {
    switch (a) {
    case 0:
    case 1:
    case 2:
        return 3;
    default:
        return 0;
    }
}

u32 sub_08032FC4(u32 a) {
    switch (a) {
    case 0:
    case 1:
    case 2:
        return 0;
    default:
        return 3;
    }
}

static u32 sub_08032FD0(u32 rec, u32 val) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[rec].parts[i].unk11 && gUnk_03000590[rec].parts[i].data[2] == val)
            return 1;
    }
    return 0;
}

static u32 sub_08032FFC(void) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03001800.unk61[i])
            return 1;
    }
    return 0;
}

static u32 select_battle_pending_action(void) {
    u32 i, j, dir;

    i = rng_lookup_table_value();
    dir = rng_next_080424B8() & 1;
    for (j = 0; j <= 2; j++) {
        if (gUnk_03001800.unk61[i])
            return gUnk_03001800.unk61[i] - 1;
        if (dir) {
            if (++i > 2)
                i = 0;
        } else if (i == 0)
            i = 2;
        else
            i--;
    }
    return gUnk_03001800.unk61[i];
}

u32 rng_lookup_table_value(void) {
    return gUnk_083AEF00[rng_next_080424B8() & 0xF];
}

u32 select_random_battle_target(u32 base) {
    u32 i, j, dir;

    i = rng_lookup_table_value();
    dir = rng_next_080424B8() & 1;
    for (j = 0; j <= 2; j++) {
        if (gUnk_03000590[base + i].unk40)
            return base + i;
        if (dir) {
            if (++i > 2)
                i = 0;
        } else if (i == 0)
            i = 2;
        else
            i--;
    }
    return base + i;
}

u32 sub_080330E8(u32 idx) {
    return get_random_battle_weight_entry(idx);
}

u32 battle_find_next_active_bot(u32 rec) {
    u32 i, j, dir;

    i = rng_lookup_table_value();
    dir = rng_next_080424B8() & 1;
    for (j = 0; j <= 2; j++) {
        if (gUnk_03000590[rec].parts[i].unk11)
            return i;
        if (dir) {
            if (++i > 2)
                i = 0;
        } else if (i == 0)
            i = 2;
        else
            i--;
    }
    return i;
}

static void sub_08033154(u32 rec, u32 part) {
    gUnk_03000590[rec].parts[part].unkE = gUnk_03001800.unk5E;
    gUnk_03000590[rec].parts[part].unkF = gUnk_03001800.unk5F;
}

u32 find_most_damaged_part(u32 rec) {
    u32 zero = 0;
    u32 i;

    CpuFastSet(&zero, (void *)0x02023000, 0x01000080);
    for (i = 0; i <= 3; i++) {
        SORT_BUFFER[i].value = i;
        if (gUnk_03000590[rec].parts[i].unk11 != 0 &&
            gUnk_03000590[rec].parts[i].unk11 != gUnk_03000590[rec].parts[i].data[4])
            SORT_BUFFER[i].key = gUnk_03000590[rec].parts[i].data[4] - gUnk_03000590[rec].parts[i].unk11;
    }
    sub_0804242C(4);
    if (SORT_BUFFER[0].key != 0)
        return SORT_BUFFER[0].value + 1;
    else
        return 0;
}

u32 sub_080331F8(u32 rec) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[rec].parts[i].unk11 && gUnk_03000590[rec].parts[i].data[1] == 0x16)
            return 0;
    }
    return 1;
}

static u32 sub_08033224(u32 rec) {
    if (gUnk_03000590[rec].unkC4 != 0)
        return 0;
    else
        return 1;
}

static u32 sub_08033240(u32 rec) {
    if (gUnk_03000590[rec].unkC9 != 0)
        return 0;
    else
        return 1;
}

u32 find_random_broken_part(u32 rec) {
    u32 i, slot, dir;

    slot = rng_next_080424B8() & 3;
    dir = rng_next_080424B8() & 1;
    for (i = 0; i <= 3; i++) {
        if (gUnk_03000590[rec].parts[slot].unk11 == 0)
            return slot + 1;
        if (dir)
            slot = (slot + 1) & 3;
        else
            slot = (slot - 1) & 3;
    }
    return 0;
}

static u32 sub_080332B4(u32 rec) {
    if (gUnk_03000590[rec].parts[0].unk10 != 0)
        return 1;
    else
        return 0;
}

static u32 sub_080332D0(u32 rec) {
    if (gUnk_03000590[rec].unkC1 != 0)
        return 1;
    else
        return 0;
}

void sub_080332EC(void) {
    gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkF = 0;
}

u32 begin_battle_action_lookup(u32 rec, u32 part) {
    gUnk_03001800.unk51 = 0;
    gUnk_03001800.unk5C = rec;
    gUnk_03001800.unk5D = --part;
    gUnk_083AEF10[gUnk_03000590[rec].parts[part].data[1]]();
    return gUnk_03001800.unk51;
}

void check_battle_bot_defeated_set_flag(void) {
    if (gUnk_03001800.unk28[sub_0801554C(gUnk_03001800.unk5C, 0)].unk2 == 0)
        gUnk_03001800.unk51 = 1;
}

void sub_08033394(void) {
    if (gUnk_03000590[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1].unkC9 == 0)
        gUnk_03001800.unk51 = 1;
}

void sub_080333D4(void) {
    gUnk_03001800.unk51 = 1;
}

void sub_080333E4(void) {
    u32 i, n;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
    for (i = 0, n = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40)
            n++;
    }
    if (n <= 1)
        gUnk_03001800.unk51 = 1;
}

void sub_08033434(void) {
    if (gUnk_03000590[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1]
                .parts[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkF - 1]
                .unk11 == 0 ||
        gUnk_03000590[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1]
                .parts[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkF - 1]
                .unk11 == gUnk_03000590[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1]
                              .parts[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkF - 1]
                              .data[4])
        gUnk_03001800.unk51 = 1;
}

void sub_08033490(void) {
    u32 rec = gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1;

    if (gUnk_03000590[rec].unkC4 != 0 || sub_080331F8(rec) == 0)
        gUnk_03001800.unk51 = 1;
}

void sub_080334E0(void) {
    if (gUnk_03000590[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1].unkC9 != 0)
        gUnk_03001800.unk51 = 1;
    if (sub_080331F8(gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1) == 0)
        gUnk_03001800.unk51 = 1;
}

void sub_08033550(void) {
    if (gUnk_03000590[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1]
            .parts[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkF - 1]
            .unk11 != 0)
        gUnk_03001800.unk51 = 1;
}

void sub_080335A0(void) {
    if (gUnk_03000590[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1].unkBA != 2)
        gUnk_03001800.unk51 = 1;
}

void sub_080335E0(void) {
    if (gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1 == gUnk_03001800.unk5C)
        gUnk_03001800.unk51 = 1;
}

void sub_08033618(void) {
    if (gUnk_03000590[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1].parts[0].unk10 == 0)
        gUnk_03001800.unk51 = 1;
}

void sub_08033658(void) {
    if (gUnk_03000590[gUnk_03000590[gUnk_03001800.unk5C].parts[gUnk_03001800.unk5D].unkE - 1].unkC1 == 0)
        gUnk_03001800.unk51 = 1;
}

void sub_08033698(void) {
    if (gUnk_03001800.unk28[sub_0801554C(gUnk_03001800.unk5C, 1)].unk2 == 0 ||
        gUnk_03001800.unk28[sub_0801554C(gUnk_03001800.unk5C, 1)].unk3 != 0x33)
        gUnk_03001800.unk51 = 1;
}

void sub_080336DC(void) {
    u32 i, j;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40) {
            for (j = 0; j <= 2; j++) {
                if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[j].unk11) {
                    if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[j].data[2] == 0)
                        return;
                    if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[j].data[2] == 1)
                        return;
                }
            }
        }
    }
    gUnk_03001800.unk51 = 1;
}

void sub_08033754(void) {
    u32 i, j;

    gUnk_03001800.unk60 = sub_08032FB8(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40) {
            for (j = 0; j <= 2; j++) {
                if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[j].unk11) {
                    if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[j].data[2] == 2)
                        return;
                    if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[j].data[2] == 3)
                        return;
                }
            }
        }
    }
    gUnk_03001800.unk51 = 1;
}

void sub_080337CC(void) {
    u32 i, j;

    gUnk_03001800.unk60 = sub_08032FC4(gUnk_03001800.unk5C);
    for (i = 0; i <= 2; i++) {
        if (gUnk_03000590[gUnk_03001800.unk60 + i].unk40) {
            for (j = 0; j <= 2; j++) {
                if (gUnk_03000590[gUnk_03001800.unk60 + i].parts[j].unk11 &&
                    gUnk_03000590[gUnk_03001800.unk60 + i].parts[j].data[1] == 0x34)
                    return;
            }
        }
    }
    gUnk_03001800.unk51 = 1;
}
