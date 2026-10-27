// Thin wrappers the field event code calls: sound and music, data table lookups, message steps, text buffer
// fills (numbers, strings), money, items, Medals, Medaparts and team (inventory/inventory), plus the
// opponent-team position table checks and the yes/no choice window (text/choice_menu).

#include "global.h"

void sub_08047BA8(u32 id) {
    play_sound_effect(id);
}

void field_play_song(u32 id) {
    play_song(id);
}

void field_stop_songs(u32 a) {
    sound_stop_all_with_fade_guard(a);
}

u32 sub_08047BCC(u32 idx) {
    return gUnk_083B6410[idx];
}

u32 sub_08047BDC(u32 idx) {
    return gUnk_083BA4D8[idx];
}

u32 sub_08047BEC(u32 a, u32 b) {
    const u32 *t = (const u32 *)gUnk_083BB9CC;
    return t[b * 4 + a];
}

void init_cursor_state(void) {
    sub_08047E4C();
    gBg0Scroll.x = 0;
    gBg0Scroll.y = 0;
    gUnk_030064A0.unk0 = 0;
    gUnk_030064A0.unk1 = 0;
}

u32 scene_transition_step_08047C24(u8 a, u8 b, u8 c, const void *text) {
    u32 ret = 0;

    switch (gUnk_030064A0.unk0) {
    case 0:
        if (gUnk_030064A0.unk1 == 0)
            text_window_init(a, b, c);
        else
            sub_0803FB0C();
        gUnk_030064A0.unk0++;
        break;
    case 1:
        if (run_message(text)) {
            gUnk_030064A0.unk0 = ret;
            gUnk_030064A0.unk1++;
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

void sub_08047D24(u32 slot, u32 n) {
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

void sub_money(u32 n) {
    s32 left = gMoney - n;

    if (left < 0)
        gMoney = 0;
    else
        gMoney = left;
}

u32 sub_08047D8C(u8 id) {
    return get_item_quantity_by_id(id);
}

u32 sub_08047D9C(u8 a, u8 b) {
    return sub_08042114(a, b);
}

u32 sub_08047DB0(u8 id) {
    return find_medal_slot_by_id(id);
}

void sub_08047DC0(u8 id, u8 n) {
    if (n == 0)
        n = 1;
    item_add_quantity(id, n);
}

void sub_08047DD8(u8 id, u8 n) {
    if (n == 0)
        n = 1;
    sub_08042318(id, n);
}

void sub_08047DF0(u8 a, u8 b, u8 n) {
    medapart_add_quantity(a, b, n);
}

void sub_08047E08(u8 a, u8 b, u8 n) {
    reduce_medapart_stat(a, b, n);
}

u32 sub_08047E20(u8 id) {
    return medal_add_by_id(id);
}

u32 sub_08047E30(void) {
    return team_is_full();
}

void sub_08047E3C(u8 id) {
    team_add_tinpet(id);
}

void sub_08047E4C(void) {}

u32 lookup_position_table_value(u8 id, u8 which) {
    u8 buf[16];
    s32 v;
    s32 match = check_position_table_match(id, which);

    if (match) {
        u32 found = 0;
        s32 i;
        struct Unk_030017A0 *p;

        for (i = 0, p = gUnk_030017A0; i <= 8; i++) {
            if (p->unk0 == 3) {
                switch (which) {
                case 0:
                    if (p->unk3 == id)
                        found = 1;
                    break;
                case 1:
                    if (p->unk4 == id)
                        found = 1;
                    break;
                case 2:
                    if (p->unk5 == id)
                        found = 1;
                    break;
                case 3:
                    if (p->unk6 == id)
                        found = 1;
                    break;
                }
            }
            if (found)
                break;
            p++;
        }
        load_part_data(gUnk_030017A0[i].unk6, 3, buf);
        v = buf[1] - 100;
        gUnk_03006D38.unk6 = gUnk_030017A0[i].unk1;
    }
    if (match)
        return v;
    return -1;
}

u32 check_position_table_match(u8 id, u8 which) {
    u32 found = 0;
    s32 i;
    struct Unk_030017A0 *p;

    for (i = 0, p = gUnk_030017A0; i <= 8; i++) {
        if (p->unk0 == 3) {
            switch (which) {
            case 0:
                if (p->unk3 == id)
                    found = 1;
                break;
            case 1:
                if (p->unk4 == id)
                    found = 1;
                break;
            case 2:
                if (p->unk5 == id)
                    found = 1;
                break;
            case 3:
                if (p->unk6 == id)
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

s32 sub_08047F50(void) {
    s32 n = 0;
    struct Unk_030017A0 *p = gUnk_030017A0;
    s32 i;

    for (i = 8; i >= 0; i--) {
        if (p->unk0 == 3)
            n++;
        p++;
    }
    return n;
}

u32 sub_08047F70(u8 id) {
    u32 found = 0;
    s32 i;
    struct Unk_030017A0 *p;

    for (i = 0, p = gUnk_030017A0; i <= 8; i++) {
        if (p->unk0 == 3 && p->unk3 == id && p->unk4 == id && p->unk5 == id && p->unk6 == id)
            found = 1;
        if (found)
            break;
        p++;
    }
    return found;
}

void init_bg0_for_cursor(u32 mode) {
    REG_BG0CNT = 0x500;
    REG_DISPCNT = 0x1F60;
    open_choice_menu(mode, 0x16, 7);
    gUnk_030064A0.unk64 = 0;
}

u32 sub_08047FEC(void) {
    u32 ret = 0;
    struct Unk_030064A0 *m = &gUnk_030064A0;
    u8 *step = &m->unk64;

    switch (*step) {
    case 1:
        if (game_state_execute_handler_b() == 0)
            break;
    case 0:
        gUnk_03000440.unk1B = ret;
        (*step)++;
        break;
    case 2:
        ret = poll_choice_menu();
        break;
    }
    return ret;
}

u32 sub_0804803C(u32 arg) {
    u32 ret = 0;

    switch (arg) {
    case 0:
        ret = gUnk_083BEA90[0][gUnk_030057E0.unk7FE * 8 + 2];
        break;
    case 1:
        ret = gUnk_083BEA90[0][gUnk_030057E0.unk7FE * 8 + 3];
        break;
    }
    return ret;
}

u32 sub_08048088(u32 idx) {
    return gUnk_08484444[idx];
}
