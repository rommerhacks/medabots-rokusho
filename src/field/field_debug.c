// Debug screen inside the field: the field sub-states field_debug_open..field_debug_wait_effect in
// field/field_update call in here. field_debug_update_page runs the current page (gFieldDebug.page) once a
// frame: UP/DOWN pick a row (field_debug_cycle_row), LEFT/RIGHT change its value (R held = steps of 16 for
// the 16-bit ones), SELECT goes to the next page, B closes, A acts on the page (start a field effect, play a
// sound, show a message). field_debug_draw_page draws the page as label and hex-digit sprites. Pages (labels
// from the ROM strings): map / player form, EVENT flags, PLAYER position, MAP_EFFECT, KWG, KOMA (sprite
// preview), MESS (message viewer), sound test.
#include "global.h"

static void field_debug_enter_page(u32 idx);
static void field_debug_cycle_event_value(u32 idx, s32 max);
static void field_debug_cycle_message_value(u32 idx, s32 max);
static void field_debug_cycle_sound_value(u32 idx, s32 max);
static void field_debug_cycle_page_value(u32 idx, u32 sub, s32 max);
static void field_debug_draw_page(u32 idx);
static void field_debug_clear_sprites(void);
static void field_debug_draw_hex(u32 value, s32 bits, s32 x, s32 y);

void field_debug_init_page(void) {
    field_debug_enter_page(gFieldDebug.page);
}

static void field_debug_enter_page(u32 idx) {
    switch (idx) {
    case 0:
        gFieldDebug.area_id = gFieldWork.area_id;
        break;
    case 1:
        gFieldDebug.event_id = gFieldWork.last_script_id;
        gFieldDebug.event_flag = event_flag_get(gFieldDebug.event_id);
        gFieldDebug.event_counter = event_counter_get(gFieldDebug.event_id);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        gFieldDebug.showing = 0;
        break;
    case 6:
        gFieldDebug.showing = 0;
        gFieldDebug.text_auto_next = 0;
        break;
    }
}

// EVENT page: re-read the flag / counter when the event number changes, write them back otherwise.
static void field_debug_apply_event_value(u32 a, s32 b) {
    switch (a) {
    case 0:
        break;
    case 1:
        if (b == 0) {
            gFieldDebug.event_flag = event_flag_get(gFieldDebug.event_id);
            gFieldDebug.event_counter = event_counter_get(gFieldDebug.event_id);
        } else if (b < 0) {
        } else if (b <= 2) {
            event_flag_write(gFieldDebug.event_id, gFieldDebug.event_flag);
            event_counter_set(gFieldDebug.event_id, gFieldDebug.event_counter);
        }
        break;
    }
}

void field_debug_update_page(u32 mode) {
    gFieldDebug.frame++;

    switch (mode) {
    case 0:
        field_debug_cycle_row(6);
        switch (gFieldDebug.rows[gFieldDebug.page]) {
        case 0:
            field_debug_cycle_page_value(gFieldDebug.page, gFieldDebug.rows[gFieldDebug.page], 0xC0);
            break;
        case 1:
            field_debug_cycle_page_value(gFieldDebug.page, gFieldDebug.rows[gFieldDebug.page], 0x10);
            break;
        case 3:
            field_debug_cycle_page_value(gFieldDebug.page, gFieldDebug.rows[gFieldDebug.page], 4);
            break;
        case 4:
            field_debug_cycle_page_value(gFieldDebug.page, gFieldDebug.rows[gFieldDebug.page], 10);
            break;
        case 2:
        case 5:
            field_debug_cycle_page_value(gFieldDebug.page, gFieldDebug.rows[gFieldDebug.page], 2);
            break;
        }
        break;
    case 1:
        field_debug_cycle_row(3);
        switch (gFieldDebug.rows[gFieldDebug.page]) {
        case 0:
            field_debug_cycle_event_value(0, 3000);
            break;
        case 1:
            field_debug_cycle_event_value(1, 2);
            break;
        case 2:
            field_debug_cycle_event_value(2, 8);
            break;
        }
        break;
    case 2:
        if (KEYS_LO(gRepeatKeys) & 0x40)
            gFieldWork.player_y -= 0x10;
        if (KEYS_LO(gRepeatKeys) & 0x80)
            gFieldWork.player_y += 0x10;
        if (KEYS_LO(gRepeatKeys) & 0x20)
            gFieldWork.player_x -= 0x10;
        if (KEYS_LO(gRepeatKeys) & 0x10)
            gFieldWork.player_x += 0x10;
        gFieldWork.player_tile_x = field_pixel_x_to_tile(gFieldWork.player_x);
        gFieldWork.player_tile_y = field_pixel_y_to_tile(gFieldWork.player_y);
        field_center_camera_on_player();
        break;
    case 3:
        if (KEYS_LO(gRepeatKeys) & 0x20) {
            if (--gFieldDebug.effect_id == 0xFF)
                gFieldDebug.effect_id = 0x1F;
        }
        if (KEYS_LO(gRepeatKeys) & 0x10) {
            if (++gFieldDebug.effect_id > 0x1F)
                gFieldDebug.effect_id = 0;
        }
        break;
    case 4:
        field_debug_cycle_row(6);
        switch (gFieldDebug.rows[gFieldDebug.page]) {
        case 1:
            field_debug_cycle_page_value(gFieldDebug.page, gFieldDebug.rows[gFieldDebug.page], 3);
            break;
        case 2:
            field_debug_cycle_page_value(gFieldDebug.page, gFieldDebug.rows[gFieldDebug.page], 4);
            break;
        case 0:
        case 3:
        case 4:
            field_debug_cycle_page_value(gFieldDebug.page, gFieldDebug.rows[gFieldDebug.page], 2);
            break;
        case 5:
            field_debug_cycle_page_value(gFieldDebug.page, gFieldDebug.rows[gFieldDebug.page], 3);
            break;
        }
        REG_BLDALPHA = ((gBlendEffect.evb & 0x3F) << 8) | (gBlendEffect.eva & 0x3F);
        REG_BLDY = gBlendEffect.evy & 0x3F;
        break;
    case 5:
        field_debug_cycle_page_value(gFieldDebug.page, gFieldDebug.rows[gFieldDebug.page], 0xB0);
        gFieldDebug.showing = 1;
        break;
    case 6:
        if (gFieldDebug.showing == 0) {
            const u32 *const *p;
            s32 n;

            field_debug_cycle_row(3);
            switch (gFieldDebug.rows[gFieldDebug.page]) {
            case 0:
                field_debug_cycle_message_value(0, 0x10);
                break;
            case 1:
                field_debug_cycle_message_value(1, gFieldDebug.text_count);
                break;
            case 2:
                field_debug_cycle_message_value(2, 2);
                break;
            }
            p = (const u32 *const *)gTextBankTables[gFieldDebug.unk20];
            n = 0;
            if (*p != 0) {
                do {
                    p++;
                    n++;
                    if (n > 0xFFF)
                        break;
                } while (*p != 0);
            }
            gFieldDebug.text_count = n;
            if (gFieldDebug.text_id >= (u16)n)
                gFieldDebug.text_id = n - 1;
        }
        break;
    case 7:
        field_debug_cycle_row(5);
        switch (gFieldDebug.rows[gFieldDebug.page]) {
        case 0:
        case 1:
            field_debug_cycle_sound_value(gFieldDebug.rows[gFieldDebug.page], 0x20);
            break;
        case 2:
            field_debug_cycle_sound_value(gFieldDebug.rows[gFieldDebug.page], 0x80);
            break;
        case 3:
            field_debug_cycle_sound_value(gFieldDebug.rows[gFieldDebug.page], 0xA0);
            break;
        case 4:
            field_debug_cycle_sound_value(gFieldDebug.rows[gFieldDebug.page], 0x100);
            break;
        }
        switch (gFieldDebug.rows[gFieldDebug.page]) {
        case 2:
            if (KEYS_LO(gRepeatKeys) & 1)
                field_play_song(gFieldDebug.song_id);
            break;
        case 3:
            if (KEYS_LO(gRepeatKeys) & 1)
                field_play_sound_effect(gFieldDebug.sound_id);
            break;
        case 1:
            break;
        }
        break;
    }

    if (KEYS_LO(gNewKeys) & 4) {
        if (++gFieldDebug.page > 7)
            gFieldDebug.page = 0;
        field_debug_clear_sprites();
        field_debug_enter_page(gFieldDebug.page);
    }
    if (KEYS_LO(gRepeatKeys) & 2)
        field_debug_close();
    if (KEYS_LO(gRepeatKeys) & 1) {
        switch (gFieldDebug.page) {
        case 3:
            gFieldDebug.unk10 = 0;
            field_debug_clear_sprites();
            field_effect_start(gFieldDebug.effect_id, gFieldWork.player_x, gFieldWork.player_y, 0);
            if (gFieldDebug.effect_id == 0xE)
                gFieldWork.player_form = 0xC;
            else if (gFieldDebug.effect_id == 0x12)
                gFieldWork.player_form = 0xB;
            if (gFieldDebug.effect_id == 0xE || gFieldDebug.effect_id == 0x12) {
                area_load_sprite_sheets();
                DmaCopy32(3, gUnk_083F8634[gUnk_083D29A6[gFieldWork.player_form]], OBJ_PLTT, 32);
                gFieldWork.loaded_form = gFieldWork.player_form;
                load_battle_terrain_data();
            }
            gGameSubState++;
            break;
        case 0:
        case 1:
        case 2:
        case 5:
            break;
        case 4:
            play_sound_effect(gFieldDebug.unk0);
            break;
        case 6:
            if (gFieldDebug.showing == 0) {
                if (gFieldDebug.text_auto_next != 0) {
                    gFieldDebug.text_id++;
                    if (gFieldDebug.text_id >= gFieldDebug.text_count) {
                        gFieldDebug.text_id = 0;
                        gFieldDebug.text_bank++;
                        if (gFieldDebug.text_bank > 0xF)
                            gFieldDebug.text_bank = 0;
                    }
                }
                gFieldDebug.frame = 0;
                field_debug_draw_page(gFieldDebug.page);
                message_steps_reset();
                gFieldDebug.showing++;
            }
            break;
        }
    }
}

void field_debug_cycle_row(s32 max) {
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        gFieldDebug.rows[gFieldDebug.page]--;
        if (gFieldDebug.rows[gFieldDebug.page] < 0)
            gFieldDebug.rows[gFieldDebug.page] = max - 1;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        gFieldDebug.rows[gFieldDebug.page]++;
        if (gFieldDebug.rows[gFieldDebug.page] >= max)
            gFieldDebug.rows[gFieldDebug.page] = 0;
    }
}

static void field_debug_cycle_event_value(u32 idx, s32 max) {
    u8 left;
    u16 *p;
    s32 step = 1;

    if (KEYS_HI(gHeldKeys) & 1)
        step = 0x10;

    if ((left = KEYS_LO(gRepeatKeys) & 0x20)) {
        p = gFieldDebugEventValues[idx];
        if ((u16)(*p -= step) == 0xFFFF)
            *p = max - 1;
        field_debug_apply_event_value(gFieldDebug.page, gFieldDebug.rows[gFieldDebug.page]);
    } else if (KEYS_LO(gRepeatKeys) & 0x10) {
        p = gFieldDebugEventValues[idx];
        *p += step;
        if (*p >= max)
            *p = left;
        field_debug_apply_event_value(gFieldDebug.page, gFieldDebug.rows[gFieldDebug.page]);
    }
}

static void field_debug_cycle_message_value(u32 idx, s32 max) {
    s32 v;
    u16 *p;
    s32 step = 1;

    if (KEYS_HI(gHeldKeys) & 1)
        step = 0x10;

    if (KEYS_LO(gRepeatKeys) & 0x20) {
        p = gFieldDebugMessageValues[idx];
        v = *p;
        v -= step;
        if (v == -1)
            v = max - 1;
        *p = v;
    } else if (KEYS_LO(gRepeatKeys) & 0x10) {
        p = gFieldDebugMessageValues[idx];
        v = *p;
        v += step;
        if (v >= max)
            v = 0;
        *p = v;
    }
}

static void field_debug_cycle_sound_value(u32 idx, s32 max) {
    u8 left;
    u8 *p;

    if ((left = KEYS_LO(gRepeatKeys) & 0x20)) {
        p = gFieldDebugSoundValues[idx];
        if ((s8)-- * p == -1)
            *p = max - 1;
    } else if (KEYS_LO(gRepeatKeys) & 0x10) {
        p = gFieldDebugSoundValues[idx];
        (*p)++;
        if (*p >= max)
            *p = left;
    }
}

static void field_debug_cycle_page_value(u32 idx, u32 sub, s32 max) {
    u8 changed = 0;
    s32 v;
    u8 **row;

    if (KEYS_LO(gRepeatKeys) & 0x20) {
        u8 *p;
        row = gFieldDebugPageValues[idx];
        p = row[sub];
        v = *p;
        v -= 1;
        if (v == -1)
            v = max - 1;
        *p = v;
        changed = 1;
    } else if (KEYS_LO(gRepeatKeys) & 0x10) {
        u8 *p;
        row = gFieldDebugPageValues[idx];
        p = row[sub];
        v = *p;
        v += 1;
        if (v >= max)
            v = 0;
        *p = v;
        changed = 1;
    }
    if (changed && idx == 5)
        field_debug_draw_sprite_preview();
}

static void field_debug_draw_page(u32 mode) {
    gFieldDebug.next_sprite = 0;
    update_bg_scroll_offsets_a();
    field_debug_draw_label(gUnk_080AC494, 2, 0x28, 0x18);
    field_debug_draw_hex(gFieldDebug.page, 8, 0x50, 0x18);
    switch (mode) {
    case 0:
        field_debug_draw_label(gUnk_080AC498, 2, 0x68, 0x18);
        field_debug_draw_label(gUnk_080AC49C, 2, 0x30, 0x20);
        field_debug_draw_value_blink(0, gFieldDebug.area_id, 8, 0x50, 0x20);
        field_debug_draw_label(gUnk_080AC4A0, 2, 0x30, 0x28);
        field_debug_draw_value_blink(1, gFieldWork.player_form, 8, 0x50, 0x28);
        switch (gFieldWork.player_form) {
        case 0:
            field_debug_draw_label(gUnk_080AC4A4, 3, 0x70, 0x28);
            break;
        case 1:
            field_debug_draw_label(gUnk_080AC4A8, 3, 0x70, 0x28);
            break;
        case 2:
            field_debug_draw_label(gUnk_080AC4AC, 3, 0x70, 0x28);
            break;
        case 3:
            field_debug_draw_label(gUnk_080AC4B0, 3, 0x70, 0x28);
            break;
        case 4:
            field_debug_draw_label(gUnk_080AC4B4, 3, 0x70, 0x28);
            break;
        case 5:
            field_debug_draw_label(gUnk_080AC4B8, 3, 0x70, 0x28);
            break;
        case 6:
            field_debug_draw_label(gUnk_080AC4BC, 3, 0x70, 0x28);
            break;
        case 7:
            field_debug_draw_label(gUnk_080AC4C0, 3, 0x70, 0x28);
            break;
        case 8:
            field_debug_draw_label(gUnk_080AC4C4, 3, 0x70, 0x28);
            break;
        case 9:
            field_debug_draw_label(gUnk_080AC4C8, 3, 0x70, 0x28);
            break;
        case 10:
            field_debug_draw_label(gUnk_080AC4CC, 3, 0x70, 0x28);
            break;
        case 11:
            field_debug_draw_label(gUnk_080AC4D0, 3, 0x70, 0x28);
            break;
        case 12:
            field_debug_draw_label(gUnk_080AC4D4, 3, 0x70, 0x28);
            break;
        case 13:
            field_debug_draw_label(gUnk_080AC4D8, 3, 0x70, 0x28);
            break;
        case 14:
            field_debug_draw_label(gUnk_080AC4DC, 3, 0x70, 0x28);
            break;
        case 15:
            field_debug_draw_label(gUnk_080AC4E0, 3, 0x70, 0x28);
            break;
        }
        field_debug_draw_label(gUnk_080AC4E4, 2, 0x30, 0x30);
        field_debug_draw_value_blink(2, gFieldWork.unkC4D, 8, 0x50, 0x30);
        field_debug_draw_label(gUnk_080AC4E8, 2, 0x30, 0x38);
        field_debug_draw_value_blink(3, gFieldWork.unkCB7, 8, 0x50, 0x38);
        switch (gFieldWork.unkCB7) {
        case 0:
            field_debug_draw_label(gUnk_080AC4EC, 2, 0x70, 0x38);
            break;
        case 1:
            field_debug_draw_label(gUnk_080AC498, 2, 0x70, 0x38);
            break;
        case 2:
            field_debug_draw_label(gUnk_080AC4F0, 2, 0x70, 0x38);
            break;
        case 3:
            field_debug_draw_label(gUnk_080AC4F4, 2, 0x70, 0x38);
            break;
        }
        field_debug_draw_label(gUnk_080AC4F8, 2, 0x30, 0x40);
        field_debug_draw_value_blink(4, gFieldWork.story_phase, 8, 0x50, 0x40);
        field_debug_draw_label(gUnk_080AC4FC, 2, 0x30, 0x48);
        field_debug_draw_value_blink(5, gFieldWork.unkC33, 8, 0x50, 0x48);
        break;
    case 1:
        field_debug_draw_label(gUnk_080AC500, 5, 0x68, 0x18);
        field_debug_draw_label(gUnk_080AC508, 3, 0x30, 0x20);
        field_debug_draw_value_blink(0, *gFieldDebugEventValues[0], 16, 0x50, 0x20);
        field_debug_draw_label(gUnk_080AC50C, 3, 0x30, 0x28);
        field_debug_draw_value_blink(1, *gFieldDebugEventValues[1], 8, 0x50, 0x28);
        field_debug_draw_label(gUnk_080AC510, 1, 0x70, 0x28);
        field_debug_draw_label(gUnk_080AC514, 2, 0x30, 0x30);
        field_debug_draw_value_blink(2, *gFieldDebugEventValues[2], 8, 0x50, 0x30);
        field_debug_draw_label(gUnk_080AC510, 1, 0x70, 0x30);
        break;
    case 2:
        field_debug_draw_label(gUnk_080AC518, 6, 0x68, 0x18);
        field_debug_draw_label(gUnk_080AC520, 3, 0x30, 0x20);
        field_debug_draw_value_blink(0, gFieldWork.player_x, 16, 0x50, 0x20);
        field_debug_draw_label(gUnk_080AC524, 3, 0x30, 0x28);
        field_debug_draw_value_blink(0, gFieldWork.player_y, 16, 0x50, 0x28);
        break;
    case 3:
        field_debug_draw_label(gUnk_080AC528, 10, 0x68, 0x18);
        field_debug_draw_label(gUnk_080AC534, 3, 0x30, 0x20);
        field_debug_draw_value_blink(0, gFieldDebug.effect_id, 16, 0x50, 0x20);
        break;
    case 4:
        field_debug_draw_label(gUnk_080AC538, 3, 0x68, 0x18);
        field_debug_draw_label(gUnk_080AC53C, 2, 0x30, 0x20);
        field_debug_draw_value_blink(0, gFieldDebug.unk11, 8, 0x50, 0x20);
        field_debug_draw_label(gUnk_080AC540, 2, 0x30, 0x28);
        field_debug_draw_value_blink(1, gUnk_03006D38.unk2, 8, 0x50, 0x28);
        field_debug_draw_label(gUnk_080AC544, 2, 0x30, 0x30);
        field_debug_draw_value_blink(2, gFieldWork.unkC4E, 8, 0x50, 0x30);
        if (gFieldWork.unkC4E & 1)
            field_debug_draw_label(gUnk_080AC548, 1, 0x70, 0x30);
        else
            field_debug_draw_label(gUnk_080AC54C, 1, 0x70, 0x30);
        if (gFieldWork.unkC4E & 2)
            field_debug_draw_label(gUnk_080AC550, 1, 0x90, 0x30);
        else
            field_debug_draw_label(gUnk_080AC54C, 1, 0x90, 0x30);
        field_debug_draw_label(gUnk_080AC554, 2, 0x30, 0x38);
        field_debug_draw_value_blink(3, gFieldWork.unkCB8, 8, 0x50, 0x38);
        field_debug_draw_label(gUnk_080AC558, 2, 0x30, 0x40);
        field_debug_draw_value_blink(4, gFieldWork.unkCB9, 8, 0x50, 0x40);
        field_debug_draw_label(gUnk_080AC510, 1, 0x70, 0x40);
        field_debug_draw_label(gUnk_080AC55C, 2, 0x30, 0x48);
        field_debug_draw_value_blink(5, gFieldWork.unkC4F, 8, 0x50, 0x48);
        switch (gFieldWork.unkC4F) {
        case 0:
            field_debug_draw_label(gUnk_080AC560, 1, 0x70, 0x48);
            break;
        case 1:
            field_debug_draw_label(gUnk_080AC564, 1, 0x70, 0x48);
            break;
        case 2:
            field_debug_draw_label(gUnk_080AC568, 1, 0x70, 0x48);
            break;
        }
        break;
    case 5:
        field_debug_draw_label(gUnk_080AC56C, 4, 0x68, 0x18);
        field_debug_draw_label(gUnk_080AC574, 3, 0x30, 0x20);
        field_debug_draw_value_blink(0, gFieldDebug.unk20, 16, 0x50, 0x20);
        if (gFieldDebug.showing != 0) {
            advance_sprite_animation_frame(0x31);
            advance_sprite_animation_frame(0x32);
            advance_sprite_animation_frame(0x33);
            advance_sprite_animation_frame(0x34);
            if (gUnk_083D2C3D[gFieldDebug.unk20] == 3)
                advance_sprite_animation_frame(0x39);
        }
        break;
    case 6:
        switch (gFieldDebug.showing) {
        case 0:
            field_debug_draw_label(gUnk_080AC578, 4, 0x68, 0x18);
            field_debug_draw_label(gUnk_080AC580, 3, 0x30, 0x20);
            field_debug_draw_value_blink(0, gFieldDebug.text_bank, 16, 0x50, 0x20);
            field_debug_draw_label(gUnk_080AC584, 3, 0x30, 0x28);
            field_debug_draw_value_blink(1, gFieldDebug.text_id, 16, 0x50, 0x28);
            field_debug_draw_label(gUnk_080AC588, 3, 0x30, 0x30);
            field_debug_draw_value_blink(2, gFieldDebug.text_auto_next, 16, 0x50, 0x30);
            field_debug_draw_label(gUnk_080AC58C, 3, 0x30, 0x38);
            field_debug_draw_value_blink(3, gFieldDebug.text_count, 16, 0x50, 0x38);
            break;
        case 1: {
            const u32 *const *bank = gTextBankTables[gFieldDebug.text_bank];
            if (message_step_run(0, 0, 0, bank[gFieldDebug.text_id]))
                gFieldDebug.showing = 0;
        } break;
        }
        break;
    case 7:
        field_debug_draw_label(gUnk_080AC514, 2, 0x68, 0x18);
        field_debug_draw_label(gUnk_080AC590, 2, 0x30, 0x20);
        field_debug_draw_value_blink(0, gFieldWork.affinity_ar, 8, 0x50, 0x20);
        field_debug_draw_label(gUnk_080AC594, 2, 0x30, 0x28);
        field_debug_draw_value_blink(1, gFieldWork.affinity_ka, 8, 0x50, 0x28);
        field_debug_draw_label(gUnk_080AC598, 3, 0x30, 0x30);
        field_debug_draw_value_blink(2, gFieldDebug.song_id, 8, 0x50, 0x30);
        field_debug_draw_label(gUnk_080AC59C, 2, 0x30, 0x38);
        field_debug_draw_value_blink(3, gFieldDebug.sound_id, 8, 0x50, 0x38);
        field_debug_draw_label(gUnk_080AC5A0, 3, 0x30, 0x40);
        field_debug_draw_value_blink(4, gFieldWork.useBlockFlags, 8, 0x50, 0x40);
        field_debug_draw_label(gUnk_080AC510, 1, 0x70, 0x40);
        break;
    }
}

void field_debug_draw_value_blink(s8 key, s32 value, u8 width, u8 x, u8 y) {
    struct FieldDebugWork *s = &gFieldDebug;

    if (key != s->rows[s->page]) {
        field_debug_draw_hex(value, width, x, y);
    } else if (s->frame & 0x10) {
        s32 i;
        for (i = 0; i < width >> 3; i++) {
            sprite_entry_clear(s->next_sprite);
            s->next_sprite++;
            sprite_entry_clear(s->next_sprite);
            s->next_sprite++;
        }
    } else {
        field_debug_draw_hex(value, width, x, y);
    }
}

u32 field_debug_page_done(void) {
    switch (gFieldDebug.page) {
    case 0:
    case 1:
    case 2:
    case 4:
        return 1;
    case 3:
        if (field_effect_run() == 4) {
            gFieldWork.player_form = 0;
            if (gFieldDebug.effect_id == 0xE || gFieldDebug.effect_id == 0x12) {
                area_load_sprite_sheets();
                DmaCopy32(3, gUnk_083F8634[gUnk_083D29A6[gFieldWork.player_form]], (void *)PLTT + 0x200, 0x20);
                gFieldWork.loaded_form = gFieldWork.player_form;
                load_battle_terrain_data();
            }
            init_battle_sprites();
            return 1;
        }
        return 0;
    }
}

static void field_debug_clear_sprites(void) {
    s32 i;

    for (i = 0; i < 40; i++)
        sprite_entry_clear(i);
}

void field_debug_close(void) {
    if (gFieldDebug.unk11 == 0) {
        gFieldDebug.unk10 = 0;
        field_debug_clear_sprites();
    }
    gFieldDebug.frame = 0;
    switch (gFieldDebug.page) {
    case 0:
    case 2:
        gUnk_03005310.unk1 = 0;
        gGameSubState = 0x33;
        break;
    case 1:
        gUnk_03005310.unk1 = 0;
        gGameSubState = 0x33;
        break;
    default:
        gGameSubState = 5;
        break;
    }
}

// Dead code (nothing calls it): draws *value as three decimal digit sprites at (x, y), like
// field_debug_draw_label with the ASCII digits '0' + d.
static void field_debug_draw_decimal3(u8 *value, s32 x, s32 y) {
    u8 hundreds, tens, ones;

    hundreds = *value / 100;
    tens = (*value - hundreds * 100) / 10;
    ones = *value - hundreds * 100 - tens * 10;

    DmaSet(3, &gFieldDebugFont[(hundreds + '0') * 32], 0x06017A00 + gFieldDebug.next_sprite * 32, 0x84000008);
    sprite_entry_init(gFieldDebug.next_sprite, 0xC004, gFieldDebug.next_sprite + 0x99, 14, 1);
    gSpriteEntries[gFieldDebug.next_sprite].unk2 = x;
    gSpriteEntries[gFieldDebug.next_sprite].unk4 = y;
    gFieldDebug.next_sprite++;

    DmaSet(3, &gFieldDebugFont[(tens + '0') * 32], 0x06017A00 + gFieldDebug.next_sprite * 32, 0x84000008);
    sprite_entry_init(gFieldDebug.next_sprite, 0xC004, gFieldDebug.next_sprite + 0x99, 14, 1);
    gSpriteEntries[gFieldDebug.next_sprite].unk2 = x + 8;
    gSpriteEntries[gFieldDebug.next_sprite].unk4 = y;
    gFieldDebug.next_sprite++;

    DmaSet(3, &gFieldDebugFont[(ones + '0') * 32], 0x06017A00 + gFieldDebug.next_sprite * 32, 0x84000008);
    sprite_entry_init(gFieldDebug.next_sprite, 0xC004, gFieldDebug.next_sprite + 0x99, 14, 1);
    gSpriteEntries[gFieldDebug.next_sprite].unk2 = x + 16;
    gSpriteEntries[gFieldDebug.next_sprite].unk4 = y;
    gFieldDebug.next_sprite++;
}

static void field_debug_draw_hex(u32 value, s32 bits, s32 x, s32 y) {
    u8 hex[16];
    s32 i;
    u8 b;
    u8 hi, lo;

    memcpy_optimized(hex, gFieldDebugHexDigits, 16);
    for (i = 0; i < bits / 8; i++) {
        if (bits / 8 == 4) {
            if (i == 0)
                b = value >> 24;
            if (i == 1)
                b = (value & 0xFF0000) >> 16;
            if (i == 2)
                b = (value & 0xFF00) >> 8;
            if (i == 3)
                b = value;
        } else if (bits / 8 == 2) {
            if (i == 0)
                b = (value & 0xFF00) >> 8;
            if (i == 1)
                b = value;
        } else if (bits / 8 == 1) {
            if (i == 0)
                b = value;
        }
        hi = b >> 4;
        lo = b - hi * 16;

        DmaSet(3, &gFieldDebugFont[hex[hi] * 32], 0x06017A00 + gFieldDebug.next_sprite * 32, 0x84000008);
        sprite_entry_init(gFieldDebug.next_sprite, 0xC004, gFieldDebug.next_sprite + 0x99, 14, 1);
        gSpriteEntries[gFieldDebug.next_sprite].unk2 = x + i * 16;
        gSpriteEntries[gFieldDebug.next_sprite].unk4 = y;
        gFieldDebug.next_sprite++;

        DmaSet(3, &gFieldDebugFont[hex[lo] * 32], 0x06017A00 + gFieldDebug.next_sprite * 32, 0x84000008);
        sprite_entry_init(gFieldDebug.next_sprite, 0xC004, gFieldDebug.next_sprite + 0x99, 14, 1);
        gSpriteEntries[gFieldDebug.next_sprite].unk2 = x + i * 16 + 8;
        gSpriteEntries[gFieldDebug.next_sprite].unk4 = y;
        gFieldDebug.next_sprite++;
    }
}

void field_debug_draw_label(const u8 *digits, s32 count, s32 x, s32 y) {
    s32 i;

    for (i = 0; i < count; i++) {
        DmaSet(3, &gFieldDebugFont[*digits * 32], 0x06017A00 + gFieldDebug.next_sprite * 32, 0x84000008);
        sprite_entry_init(gFieldDebug.next_sprite, 0xC004, gFieldDebug.next_sprite + 0x99, 14, 1);
        gSpriteEntries[gFieldDebug.next_sprite].unk2 = x;
        gSpriteEntries[gFieldDebug.next_sprite].unk4 = y;
        x += 8;
        gFieldDebug.next_sprite++;
        digits++;
    }
}

// battle field 4x2 grid: sprites 49-56 with shadows 91-98, then sprite 57 / shadow 99
static inline void init_field_sprite(u8 row, u8 col) {
    u8 slot = 49 + row * 4 + col;
    u8 j = slot + 42;

    gSpriteEntries[slot].unk30 = gFieldDebug.unk20;
    gSpriteEntries[slot].unkC_8 = gUnk_03006432 + (col * 32 - 48);
    gSpriteEntries[slot].unk10_8 = gUnk_03006434 + (16 - row * 32);
    gSpriteEntries[slot].unk0 = 0xC804;
    gSpriteEntries[slot].unk2E = 1;
    gSpriteEntries[j].unk0 = 0xCC0C;
    gSpriteEntries[slot].unk2 = gSpriteEntries[slot].unkC_8 - (u16)gBg1Scroll.x;
    gSpriteEntries[slot].unk4 = gSpriteEntries[slot].unk10_8 - (u16)gBg1Scroll.y;
    gSpriteEntries[j].unk2 = gSpriteEntries[slot].unk2;
    gSpriteEntries[j].unk4 = gSpriteEntries[slot].unk4 + (s16)(gSpriteEntries[slot].unk2C - 5);
    gSpriteEntries[slot].unk6 = row * 48 + col * 15;
    sprite_anim_start(slot, 4 + row * 16 + col * 5);
}

void field_debug_draw_sprite_preview(void) {
    s16 zero; // FAKEMATCH: only set inside the first if, read after it (uninitialised on the other path)

    fill_sprite_sheets(gFieldDebug.unk20);
    fill_sprite_palettes(gFieldDebug.unk20);
    init_field_sprite(0, 0);
    init_field_sprite(0, 1);
    init_field_sprite(0, 2);
    init_field_sprite(0, 3);
    init_field_sprite(1, 0);
    init_field_sprite(1, 1);
    init_field_sprite(1, 2);
    init_field_sprite(1, 3);
    {
        u8 slot = 57;
        u8 j = slot + 42;

        sprite_entry_clear(slot);
        sprite_entry_clear(j);
        gSpriteEntries[slot].unk30 = gFieldDebug.unk20;
        if (gUnk_083D2C3D[gFieldDebug.unk20] == 3) {
            sprite_entry_init(slot, 0xC804, sprite_code_anim_index(0), sprite_code_kind(0), 1);
            gSpriteEntries[slot].unk2B = sprite_code_kind(0);
            gSpriteEntries[slot].unkC_8 = gUnk_03006432 - 0x30;
            gSpriteEntries[slot].unk10_8 = gUnk_03006434 + 0x30;
            gUnk_030055A0[slot].unk0 = 0xFFFF;
            gSpriteEntries[slot].unk2C = zero = 0;
            sprite_anim_start(slot, 0x60);
        }
        gSpriteEntries[j].unk0 = zero;
        if (gUnk_083D2B8D[gFieldDebug.unk20] != 0) {
            gSpriteEntries[j].unk0 = 0xCC0C;
            gSpriteEntries[j].unk2 = gSpriteEntries[slot].unk2;
            gSpriteEntries[j].unk4 = gSpriteEntries[slot].unk4 + (s16)(gSpriteEntries[slot].unk2C - 5);
        }
    }
}
