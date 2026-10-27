// Thin wrappers the field event code calls: sound and music, data table lookups, message steps, text buffer
// fills (numbers, strings), money, items, Medals, Medaparts and team (inventory/inventory), plus checks on the
// player's team gTeamSlots (9 slots; unk0 == 3 = a complete Medabot) and the yes/no choice window
// (text/choice_menu). Name tables: gMedalNames Medals, gUnk_083BA4D8 Medabots (by head part id),
// gMedapartNames Medaparts, gItemNames items.

#include "global.h"

void field_play_sound_effect(u32 id) {
    play_sound_effect(id);
}

void field_play_song(u32 id) {
    play_song(id);
}

void field_stop_songs(u32 a) {
    fade_out_music(a);
}

u32 medal_name(u32 idx) {
    return gMedalNames[idx];
}

u32 medabot_name(u32 idx) {
    return gUnk_083BA4D8[idx];
}

u32 medapart_name(u32 a, u32 b) {
    const u32 *t = (const u32 *)gMedapartNames;
    return t[b * 4 + a];
}

// Resets the message_step_run state before a multi-message script step.
void message_steps_reset(void) {
    message_reset_hook();
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gFieldScriptWork.message_step = 0;
    gFieldScriptWork.message_count = 0;
}

// One step of a script message: opens the window for the first message, continues it for later ones;
// returns 1 when the message is done.
u32 message_step_run(u8 a, u8 b, u8 c, const void *text) {
    u32 ret = 0;

    switch (gFieldScriptWork.message_step) {
    case 0:
        if (gFieldScriptWork.message_count == 0)
            text_window_init(a, b, c);
        else
            message_next();
        gFieldScriptWork.message_step++;
        break;
    case 1:
        if (run_message(text)) {
            gFieldScriptWork.message_step = ret;
            gFieldScriptWork.message_count++;
            ret = 1;
        }
        break;
    }
    return ret;
}

void format_number_to_text_buffer(u32 slot, u32 n) {
    u8 buf[12];
    struct TextBufTable4 t = gUnk_080ABBFC;
    u8 *d = t.p[slot];
    s32 len = count_decimal_digits(n);
    s32 i;

    for (i = 0; i < len; i++)
        buf[i] = truncate_to_digit_count(n, len - 1 - i) + 0x35;
    memcpy_u8(buf, d, len);
    d[len] = 0xFE;
}

void copy_string_to_text_buffer(u32 slot, u32 str) {
    u8 *s = (u8 *)str;
    struct TextBufTable4 t = gUnk_080ABBFC;
    u8 *d = t.p[slot];
    s32 i;

    for (i = 0; i < 16 && *s != 0xFE; i++)
        *d++ = *s++;
    *d = 0xFE;
}

// Formats the money amount n into text buffer slot (used by the give / take money script steps).
void format_money_to_text_buffer(u32 slot, u32 n) {
    u8 buf[12];
    struct TextBufTable4 t = gUnk_080ABBFC;
    divide_by_10000_b(t.p[slot], n);
}

u32 get_money(void) {
    return gMoney;
}

void add_money(u32 n) {
    gMoney += n;
    if (gMoney > 99999)
        gMoney = 99999;
}

void subtract_money(u32 n) {
    s32 left = gMoney - n;

    if (left < 0)
        gMoney = 0;
    else
        gMoney = left;
}

u32 field_item_quantity(u8 id) {
    return get_item_quantity_by_id(id);
}

u32 field_medapart_counts(u8 a, u8 b) {
    return medapart_get_counts(a, b);
}

u32 field_find_medal_slot(u8 id) {
    return find_medal_slot_by_id(id);
}

void field_give_item(u8 id, u8 n) {
    if (n == 0)
        n = 1;
    item_add_quantity(id, n);
}

void field_take_item(u8 id, u8 n) {
    if (n == 0)
        n = 1;
    item_remove_quantity(id, n);
}

void field_give_medapart(u8 a, u8 b, u8 n) {
    medapart_add_quantity(a, b, n);
}

void field_take_medapart(u8 a, u8 b, u8 n) {
    reduce_medapart_stat(a, b, n);
}

u32 field_give_medal(u8 id) {
    return medal_add_by_id(id);
}

u32 field_team_is_full(void) {
    return team_is_full();
}

void field_team_add_tinpet(u8 id) {
    team_add_tinpet(id);
}

// guess: a hook whose body was compiled out; called by message_steps_reset and when the town map closes.
void message_reset_hook(void) {}

// guess: if a team Medabot has part id equipped in slot which, returns that bot's legs part byte 1 - 100
// (load_part_data) and stores the bot's unk1 in gUnk_03006D38.unk6; else -1.
u32 team_equipped_part_legs_value(u8 id, u8 which) {
    u8 buf[16];
    s32 v;
    s32 match = team_has_part_equipped(id, which);

    if (match) {
        u32 found = 0;
        s32 i;
        struct TeamSlot *p;

        for (i = 0, p = gTeamSlots; i <= 8; i++) {
            if (p->state == 3) {
                switch (which) {
                case 0:
                    if (p->head == id)
                        found = 1;
                    break;
                case 1:
                    if (p->rightArm == id)
                        found = 1;
                    break;
                case 2:
                    if (p->leftArm == id)
                        found = 1;
                    break;
                case 3:
                    if (p->legs == id)
                        found = 1;
                    break;
                }
            }
            if (found)
                break;
            p++;
        }
        load_part_data(gTeamSlots[i].legs, 3, buf);
        v = buf[1] - 100;
        gUnk_03006D38.unk6 = gTeamSlots[i].gender;
    }
    if (match)
        return v;
    return -1;
}

u32 team_has_part_equipped(u8 id, u8 which) {
    u32 found = 0;
    s32 i;
    struct TeamSlot *p;

    for (i = 0, p = gTeamSlots; i <= 8; i++) {
        if (p->state == 3) {
            switch (which) {
            case 0:
                if (p->head == id)
                    found = 1;
                break;
            case 1:
                if (p->rightArm == id)
                    found = 1;
                break;
            case 2:
                if (p->leftArm == id)
                    found = 1;
                break;
            case 3:
                if (p->legs == id)
                    found = 1;
                break;
            }
        }
        if (found)
            break;
        p++;
    }
    return found;
}

s32 team_count_complete_bots(void) {
    s32 n = 0;
    struct TeamSlot *p = gTeamSlots;
    s32 i;

    for (i = 8; i >= 0; i--) {
        if (p->state == 3)
            n++;
        p++;
    }
    return n;
}

// Whether a team Medabot wears all four parts of set id.
u32 team_has_full_part_set(u8 id) {
    u32 found = 0;
    s32 i;
    struct TeamSlot *p;

    for (i = 0, p = gTeamSlots; i <= 8; i++) {
        if (p->state == 3 && p->head == id && p->rightArm == id && p->leftArm == id && p->legs == id)
            found = 1;
        if (found)
            break;
        p++;
    }
    return found;
}

void yes_no_menu_open(u32 mode) {
    REG_BG0CNT = 0x500;
    REG_DISPCNT = 0x1F60;
    open_choice_menu(mode, 0x16, 7);
    gFieldScriptWork.choice_step = 0;
}

u32 yes_no_menu_poll(void) {
    u32 ret = 0;
    struct FieldScriptWork *m = &gFieldScriptWork;
    u8 *step = &m->choice_step;

    switch (*step) {
    case 1:
        if (game_state_execute_handler_b() == 0)
            break;
    case 0:
        gGameWork.endModeStep = ret;
        (*step)++;
        break;
    case 2:
        ret = poll_choice_menu();
        break;
    }
    return ret;
}

// Bytes 2 / 3 of the current area's gUnk_083BEA90 record: whether the Landmotor car (0) / the Femjet flight (1)
// may be used here (vehicle_check_usable; check_and_update_battlefield_palette drops the car form when 0).
u32 area_allows_vehicle(u32 arg) {
    u32 ret = 0;

    switch (arg) {
    case 0:
        ret = gUnk_083BEA90[0][gFieldWork.area_id * 8 + 2];
        break;
    case 1:
        ret = gUnk_083BEA90[0][gFieldWork.area_id * 8 + 3];
        break;
    }
    return ret;
}

u32 item_name(u32 idx) {
    return gItemNames[idx];
}
