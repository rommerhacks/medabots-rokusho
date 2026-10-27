// Robattle turn queue: Medabots that reach the front or home line are queued (battle_queue_add), then
// sorted and popped (battle_queue_sort / _take_head / _pop); also the number and text popup sprites
// (battle_number_popup_*). Called from battle/robattle and the battle action modules.

#include "global.h"

// Queues every Medabot standing on its front or home line (link player 1 queues the opponents first);
// returns 1 if any did.
u32 battle_queue_bots_at_lines(void) {
    u32 i;
    u32 a = 0;
    u32 b = 0;

    if (gGameWork.unk89 != 1 || gUnk_03000B90 == 0) {
        for (i = 0; i <= 5; i++) {
            if (gBattleBots[i].teamState) {
                a += battle_bot_at_front_line(i, 0);
                b += battle_bot_at_home_line(i, 0);
            }
        }
    } else {
        for (i = 3; i <= 5; i++) {
            if (gBattleBots[i].teamState) {
                a += battle_bot_at_front_line(i, 0);
                b += battle_bot_at_home_line(i, 0);
            }
        }
        for (i = 0; i <= 2; i++) {
            if (gBattleBots[i].teamState) {
                a += battle_bot_at_front_line(i, 0);
                b += battle_bot_at_home_line(i, 0);
            }
        }
    }
    if (a != 0 || b != 0)
        return 1;
    return 0;
}

u32 battle_bot_at_front_line(u32 rec, u32 peek) {
    u32 reached = 0;

    if (!(gBattleBots[rec].stateFlags & 4)) {
        if (rec <= 2) {
            if (gSpriteEntries[rec * 4 + 0x5D].unk2 == 0x68)
                reached = 1;
        } else {
            if (gSpriteEntries[rec * 4 + 0x5D].unk2 == 0x88)
                reached = 1;
        }
        if (peek == 0 && reached)
            battle_queue_add(rec, gBattleBots[rec].parts[3].unk12);
    }
    return reached;
}

u32 battle_bot_at_home_line(u32 rec, u32 peek) {
    u32 reached = 0;

    if (gBattleBots[rec].stateFlags & 4) {
        if (rec <= 2) {
            if (gSpriteEntries[rec * 4 + 0x5D].unk2 == 0x28)
                reached = 1;
        } else {
            if (gSpriteEntries[rec * 4 + 0x5D].unk2 == 0xC8)
                reached = 1;
        }
        if (peek == 0 && reached)
            battle_queue_add(rec, gBattleBots[rec].parts[3].unk12);
    }
    return reached;
}

void battle_queue_add(u32 rec, u32 prio) {
    u32 i;
    struct BattleWork *g;

    i = 0;
    g = &gBattleWork;
    for (; i <= 5; i++) {
        if (g->actionQueue[i][0] == 0) {
            g->actionQueue[i][0] = rec + 1;
            g->actionQueue[i][1] = prio;
            return;
        }
    }
}

void iterate_bots_setup_battle_sprites(void) {
    u32 i;

    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].teamState)
            setup_battle_bot_sprite_group(i, gSpriteEntries[0x5D + i * 4].unk2, gSpriteEntries[0x5D + i * 4].unk4 - 4);
    }
}

// Hidden function (no callers): 2-digit number buffer, [0] = 0xB when neg else 0xA (sign tile), [1] tens, [2] ones.
static void number_to_sign_digits(u8 *buf, u32 n, u32 neg) {
    if (neg)
        buf[0] = 0xB;
    else
        buf[0] = 0xA;
    buf[1] = n / 10;
    buf[2] = n % 10;
}

void battle_number_popup_init(u8 *buf, u32 rec) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (buf[i] == 0xFE) {
            gSpriteEntries[rec * 4 + 10 + i].unk21 = 0xFF;
            return;
        }
        gSpriteEntries[rec * 4 + 10 + i].unk0 = 0xC224;
        gSpriteEntries[rec * 4 + 10 + i].unk1C = 0;
        gSpriteEntries[rec * 4 + 10 + i].unk4 = gSpriteEntries[rec * 4 + 0x5D].unk4 + 4;
        gSpriteEntries[rec * 4 + 10 + i].unkB = 0x90;
        gSpriteEntries[rec * 4 + 10 + i].unk6 = buf[i] + 0x800;
        gSpriteEntries[rec * 4 + 10 + i].unk20 = i * 4;
        gSpriteEntries[rec * 4 + 10 + i].unk21 = 0;
        gSpriteEntries[rec * 4 + 10 + i].unk9 = 0x40;
        gSpriteEntries[rec * 4 + 10 + i].unk8 = 0x40;
        gSpriteEntries[rec * 4 + 10 + i].unkA = buf[0] + 1;
        switch (buf[6]) {
        case 1:
            gSpriteEntries[rec * 4 + 10 + i].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2 + i * 8;
            break;
        case 2:
            gSpriteEntries[rec * 4 + 10 + i].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2 - 4 + i * 8;
            break;
        case 3:
            gSpriteEntries[rec * 4 + 10 + i].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2 - 8 + i * 8;
            break;
        case 4:
            gSpriteEntries[rec * 4 + 10 + i].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2 - 12 + i * 8;
            break;
        }
    }
}

void battle_number_popup_update(u32 rec) {
    u32 i;

    for (i = 0; i <= 2; i++) {
        if (gSpriteEntries[rec * 4 + 10 + i].unk21 == 0xFF)
            return;
        if (gSpriteEntries[rec * 4 + 10 + i].unk21 <= 0x1F) {
            if (gSpriteEntries[rec * 4 + 10 + i].unk20 == 0) {
                gSpriteEntries[rec * 4 + 10 + i].unk4 += gUnk_083AD3B3[gSpriteEntries[rec * 4 + 10 + i].unk21];
                gSpriteEntries[rec * 4 + 10 + i].unk9 += 2;
                gSpriteEntries[rec * 4 + 10 + i].unk21++;
            } else
                gSpriteEntries[rec * 4 + 10 + i].unk20--;
        }
    }
}

void set_display_digit_type(u8 *buf, u32 value, u32 type) {
    u8 n;
    u8 i;
    u8 started;
    u8 d[3];
    vu32 rem;

    if (type != 0) {
        if (type == 1) {
            buf[0] = 0xB;
            n = 1;
        } else
            n = 0;
    } else {
        buf[0] = 0xA;
        n = 1;
    }
    d[0] = value / 100;
    rem = value - (value / 100) * 100;
    d[1] = rem / 10;
    rem = rem - rem / 10 * 10;
    d[2] = rem;
    started = 0;
    for (i = 0; i <= 2; i++) {
        if (i <= 1) {
            if (d[i] == 0) {
                if (started) {
                    buf[n] = d[i];
                    n++;
                }
            } else {
                buf[n] = d[i];
                started = 1;
                n++;
            }
        } else {
            buf[n] = d[i];
            n++;
        }
    }
    buf[n] = 0xFE;
    buf[6] = n;
}

void battle_number_popup_init_slot(u8 *buf, u32 rec, u32 slot) {
    u32 i;

    for (i = 0; i <= 4; i++) {
        if (buf[i] == 0xFE)
            return;
        gSpriteEntries[rec * 4 + slot + i].unk0 = 0xC224;
        gSpriteEntries[rec * 4 + slot + i].unk1C = 0;
        gSpriteEntries[rec * 4 + slot + i].unk4 = gSpriteEntries[rec * 4 + 0x5D].unk4 + 4;
        gSpriteEntries[rec * 4 + slot + i].unkB = 0x90;
        gSpriteEntries[rec * 4 + slot + i].unk6 = buf[i] + 0x800;
        gSpriteEntries[rec * 4 + slot + i].unk20 = i * 4;
        gSpriteEntries[rec * 4 + slot + i].unk21 = 0;
        gSpriteEntries[rec * 4 + slot + i].unk9 = 0x40;
        gSpriteEntries[rec * 4 + slot + i].unk8 = 0x40;
        gSpriteEntries[rec * 4 + slot + i].unkA = buf[0] + 1;
        switch (buf[6]) {
        case 1:
            gSpriteEntries[rec * 4 + slot + i].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2 + i * 8;
            break;
        case 2:
            gSpriteEntries[rec * 4 + slot + i].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2 - 4 + i * 8;
            break;
        case 3:
            gSpriteEntries[rec * 4 + slot + i].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2 - 8 + i * 8;
            break;
        case 4:
            gSpriteEntries[rec * 4 + slot + i].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2 - 12 + i * 8;
            break;
        }
    }
}

void battle_text_popup_init_slot(u8 *buf, u32 rec, u32 slot) {
    u32 i;

    for (i = 0; i <= 4; i++) {
        if (buf[i] == 0xFE)
            return;
        gSpriteEntries[rec * 4 + slot + i].unk0 = 0xC224;
        gSpriteEntries[rec * 4 + slot + i].unk1C = 0;
        gSpriteEntries[rec * 4 + slot + i].unk4 = gSpriteEntries[rec * 4 + 0x5D].unk4 + 4;
        gSpriteEntries[rec * 4 + slot + i].unkB = 0x90;
        gSpriteEntries[rec * 4 + slot + i].unk6 = buf[i] + 0x5100;
        gSpriteEntries[rec * 4 + slot + i].unk20 = i * 4;
        gSpriteEntries[rec * 4 + slot + i].unk21 = 0;
        gSpriteEntries[rec * 4 + slot + i].unk9 = 0x40;
        gSpriteEntries[rec * 4 + slot + i].unk8 = 0x40;
        gSpriteEntries[rec * 4 + slot + i].unkA = 0xC;
        switch (buf[6]) {
        case 1:
            gSpriteEntries[rec * 4 + slot + i].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2 + i * 8;
            break;
        case 2:
            gSpriteEntries[rec * 4 + slot + i].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2 - 4 + i * 8;
            break;
        case 3:
            gSpriteEntries[rec * 4 + slot + i].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2 - 8 + i * 8;
            break;
        case 4:
            gSpriteEntries[rec * 4 + slot + i].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2 - 12 + i * 8;
            break;
        }
    }
}

void battle_text_popup_init_at(u8 *buf, u32 rec, u32 slot, u32 x, u32 y) {
    u32 i;

    for (i = 0; i <= 4; i++) {
        if (buf[i] == 0xFE)
            return;
        gSpriteEntries[slot + rec * 4 + i].unk0 = 0xC224;
        gSpriteEntries[slot + rec * 4 + i].unk1C = 0;
        gSpriteEntries[slot + rec * 4 + i].unk4 = y;
        gSpriteEntries[slot + rec * 4 + i].unk2 = x + i * 8;
        gSpriteEntries[slot + rec * 4 + i].unkB = 0x90;
        gSpriteEntries[slot + rec * 4 + i].unk6 = buf[i] + 0x5100;
        gSpriteEntries[slot + rec * 4 + i].unk20 = i * 4;
        gSpriteEntries[slot + rec * 4 + i].unk21 = 0;
        gSpriteEntries[slot + rec * 4 + i].unk9 = 0x40;
        gSpriteEntries[slot + rec * 4 + i].unk8 = 0x40;
        gSpriteEntries[slot + rec * 4 + i].unkA = 0xC;
    }
}

void battle_popup_update_slot(u8 *buf, u32 rec, u32 slot) {
    u32 i;

    for (i = 0; i <= 4; i++) {
        if (buf[i] == 0xFE)
            return;
        if (gSpriteEntries[slot + rec * 4 + i].unk21 <= 0x1F) {
            if (gSpriteEntries[slot + rec * 4 + i].unk20 == 0) {
                gSpriteEntries[slot + rec * 4 + i].unk4 += gUnk_083AD3B3[gSpriteEntries[slot + rec * 4 + i].unk21];
                gSpriteEntries[slot + rec * 4 + i].unk9 += 2;
                gSpriteEntries[slot + rec * 4 + i].unk21++;
            } else
                gSpriteEntries[slot + rec * 4 + i].unk20--;
        }
    }
}

void battle_queue_sort(void) {
    u32 n, i;
    u8 r, p;

    for (n = 5; n != 0; n--) {
        for (i = 0; i < n; i++) {
            if (gBattleWork.actionQueue[0][i * 2 + 1] < gBattleWork.actionQueue[0][(i + 1) * 2 + 1]) {
                r = gBattleWork.actionQueue[0][(i + 1) * 2];
                p = gBattleWork.actionQueue[0][(i + 1) * 2 + 1];
                gBattleWork.actionQueue[0][(i + 1) * 2] = gBattleWork.actionQueue[0][i * 2];
                gBattleWork.actionQueue[0][(i + 1) * 2 + 1] = gBattleWork.actionQueue[0][i * 2 + 1];
                gBattleWork.actionQueue[0][i * 2] = r;
                gBattleWork.actionQueue[0][i * 2 + 1] = p;
            }
        }
    }
}

void battle_queue_take_head(void) {
    gBattleWork.actor = gBattleWork.actionQueue[0][0] - 1;
    gBattleWork.actorSide = (gBattleWork.actionQueue[0][0] - 1) / 3;
    gBattleWork.otherSide = gBattleWork.actorSide ^ 1;
}

void battle_queue_pop(void) {
    u32 i;

    for (i = 0; i <= 4; i++) {
        gBattleWork.actionQueue[0][i * 2] = gBattleWork.actionQueue[0][(i + 1) * 2];
        gBattleWork.actionQueue[0][i * 2 + 1] = gBattleWork.actionQueue[0][(i + 1) * 2 + 1];
    }
    gBattleWork.actionQueue[0][i * 2] = 0;
    gBattleWork.actionQueue[0][i * 2 + 1] = 0;
}

// guess: unkBF is set by a support skill (rapid_charge_apply); such Medabots keep moving in sub-state 0x4C.
u32 any_bot_extra_move_pending(void) {
    u32 i;

    for (i = 0; i <= 5; i++) {
        if (gBattleBots[i].teamState && gBattleBots[i].unkBF)
            return 1;
    }
    return 0;
}

// guess: bit set by robattle_command_auto from the command ring; when set, robattle_bot_ready_for_command runs the
// Medabot's turn without the command menu unless B is held.
u32 team_bot_command_kept(u32 rec) {
    if (rec <= 2) {
        switch (rec) {
        case 0:
            if (gBattleWork.autoCommandBits & 1)
                return 1;
            return 0;
        case 1:
            if (gBattleWork.autoCommandBits & 2)
                return 1;
            return 0;
        case 2:
            if (gBattleWork.autoCommandBits & 4)
                return 1;
            return 0;
        }
    }
}

void team_bot_clear_command_kept(u32 rec) {
    if (rec <= 2) {
        switch (rec) {
        case 0:
            gBattleWork.autoCommandBits &= ~1;
            break;
        case 1:
            gBattleWork.autoCommandBits &= ~2;
            break;
        case 2:
            gBattleWork.autoCommandBits &= ~4;
            break;
        }
    }
}
