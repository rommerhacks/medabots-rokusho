// Debug screen inside the field: the field sub-states field_debug_open..field_debug_wait_effect in
// field/field_update call in here. field_debug_update_page runs the current page (gFieldDebug.page) once a
// frame: UP/DOWN pick a row (field_debug_cycle_row), LEFT/RIGHT change its value (R held = steps of 16 for
// the 16-bit ones), SELECT goes to the next page, B closes, A acts on the page (start a field effect, play a
// sound, show a message). field_debug_draw_page draws the page as label and hex-digit sprites. Pages (labels
// from the ROM strings): map / player form, EVENT flags, PLAYER position, MAP_EFFECT, KWG, KOMA (sprite
// preview), MESS (message viewer), sound test.
#include "global.h"
#include "constants/field_sprites.h"
#include "constants/sprites.h"

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
static void field_debug_apply_event_value(u32 page, s32 row) {
    switch (page) {
    case 0:
        break;
    case 1:
        if (row == 0) {
            gFieldDebug.event_flag = event_flag_get(gFieldDebug.event_id);
            gFieldDebug.event_counter = event_counter_get(gFieldDebug.event_id);
        } else if (row < 0) {
        } else if (row <= 2) {
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
            const u32 *const *entry;
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
            entry = (const u32 *const *)gTextBankTables[gFieldDebug.preview_sprite_set];
            n = 0;
            if (*entry != 0) {
                do {
                    entry++;
                    n++;
                    if (n > 0xFFF)
                        break;
                } while (*entry != 0);
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
            gFieldDebug.labels_drawn = 0;
            field_debug_clear_sprites();
            field_effect_start(gFieldDebug.effect_id, gFieldWork.player_x, gFieldWork.player_y, 0);
            if (gFieldDebug.effect_id == 0xE)
                gFieldWork.player_form = 0xC;
            else if (gFieldDebug.effect_id == 0x12)
                gFieldWork.player_form = 0xB;
            if (gFieldDebug.effect_id == 0xE || gFieldDebug.effect_id == 0x12) {
                area_load_sprite_sheets();
                DmaCopy32(3, gFieldSpritePalettes[gPlayerFormSpriteSheets[gFieldWork.player_form]], OBJ_PLTT, 32);
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
            play_sound_effect(gFieldDebug.test_sound);
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
    u16 *value_ptr;
    s32 step = 1;

    if (KEYS_HI(gHeldKeys) & 1)
        step = 0x10;

    if ((left = KEYS_LO(gRepeatKeys) & 0x20)) {
        value_ptr = gFieldDebugEventValues[idx];
        if ((u16)(*value_ptr -= step) == 0xFFFF)
            *value_ptr = max - 1;
        field_debug_apply_event_value(gFieldDebug.page, gFieldDebug.rows[gFieldDebug.page]);
    } else if (KEYS_LO(gRepeatKeys) & 0x10) {
        value_ptr = gFieldDebugEventValues[idx];
        *value_ptr += step;
        if (*value_ptr >= max)
            *value_ptr = left;
        field_debug_apply_event_value(gFieldDebug.page, gFieldDebug.rows[gFieldDebug.page]);
    }
}

static void field_debug_cycle_message_value(u32 idx, s32 max) {
    s32 value;
    u16 *value_ptr;
    s32 step = 1;

    if (KEYS_HI(gHeldKeys) & 1)
        step = 0x10;

    if (KEYS_LO(gRepeatKeys) & 0x20) {
        value_ptr = gFieldDebugMessageValues[idx];
        value = *value_ptr;
        value -= step;
        if (value == -1)
            value = max - 1;
        *value_ptr = value;
    } else if (KEYS_LO(gRepeatKeys) & 0x10) {
        value_ptr = gFieldDebugMessageValues[idx];
        value = *value_ptr;
        value += step;
        if (value >= max)
            value = 0;
        *value_ptr = value;
    }
}

static void field_debug_cycle_sound_value(u32 idx, s32 max) {
    u8 left;
    u8 *value_ptr;

    if ((left = KEYS_LO(gRepeatKeys) & 0x20)) {
        value_ptr = gFieldDebugSoundValues[idx];
        if ((s8)-- * value_ptr == -1)
            *value_ptr = max - 1;
    } else if (KEYS_LO(gRepeatKeys) & 0x10) {
        value_ptr = gFieldDebugSoundValues[idx];
        (*value_ptr)++;
        if (*value_ptr >= max)
            *value_ptr = left;
    }
}

static void field_debug_cycle_page_value(u32 idx, u32 sub, s32 max) {
    u8 changed = 0;
    s32 value;
    u8 **row;

    if (KEYS_LO(gRepeatKeys) & 0x20) {
        u8 *value_ptr;
        row = gFieldDebugPageValues[idx];
        value_ptr = row[sub];
        value = *value_ptr;
        value -= 1;
        if (value == -1)
            value = max - 1;
        *value_ptr = value;
        changed = 1;
    } else if (KEYS_LO(gRepeatKeys) & 0x10) {
        u8 *value_ptr;
        row = gFieldDebugPageValues[idx];
        value_ptr = row[sub];
        value = *value_ptr;
        value += 1;
        if (value >= max)
            value = 0;
        *value_ptr = value;
        changed = 1;
    }
    if (changed && idx == 5)
        field_debug_draw_sprite_preview();
}

static void field_debug_draw_page(u32 mode) {
    gFieldDebug.next_sprite = 0;
    update_bg_scroll_offsets_a();
    field_debug_draw_label(gFieldDebugLabelMd, 2, 0x28, 0x18);
    field_debug_draw_hex(gFieldDebug.page, 8, 0x50, 0x18);
    switch (mode) {
    case 0:
        field_debug_draw_label(gFieldDebugLabelMp, 2, 0x68, 0x18);
        field_debug_draw_label(gFieldDebugLabelMn, 2, 0x30, 0x20);
        field_debug_draw_value_blink(0, gFieldDebug.area_id, 8, 0x50, 0x20);
        field_debug_draw_label(gFieldDebugLabelPt, 2, 0x30, 0x28);
        field_debug_draw_value_blink(1, gFieldWork.player_form, 8, 0x50, 0x28);
        switch (gFieldWork.player_form) {
        case 0:
            field_debug_draw_label(gFieldDebugLabelNor, 3, 0x70, 0x28);
            break;
        case 1:
            field_debug_draw_label(gFieldDebugLabelCar, 3, 0x70, 0x28);
            break;
        case 2:
            field_debug_draw_label(gFieldDebugLabelSen, 3, 0x70, 0x28);
            break;
        case 3:
            field_debug_draw_label(gFieldDebugLabelSka, 3, 0x70, 0x28);
            break;
        case 4:
            field_debug_draw_label(gFieldDebugLabelKim, 3, 0x70, 0x28);
            break;
        case 5:
            field_debug_draw_label(gFieldDebugLabelYus, 3, 0x70, 0x28);
            break;
        case 6:
            field_debug_draw_label(gFieldDebugLabelRob, 3, 0x70, 0x28);
            break;
        case 7:
            field_debug_draw_label(gFieldDebugLabelBan, 3, 0x70, 0x28);
            break;
        case 8:
            field_debug_draw_label(gFieldDebugLabelDor, 3, 0x70, 0x28);
            break;
        case 9:
            field_debug_draw_label(gFieldDebugLabelObo, 3, 0x70, 0x28);
            break;
        case 10:
            field_debug_draw_label(gFieldDebugLabelMef, 3, 0x70, 0x28);
            break;
        case 11:
            field_debug_draw_label(gFieldDebugLabelKaz, 3, 0x70, 0x28);
            break;
        case 12:
            field_debug_draw_label(gFieldDebugLabelGin, 3, 0x70, 0x28);
            break;
        case 13:
            field_debug_draw_label(gFieldDebugLabelDog, 3, 0x70, 0x28);
            break;
        case 14:
            field_debug_draw_label(gFieldDebugLabelKok, 3, 0x70, 0x28);
            break;
        case 15:
            field_debug_draw_label(gFieldDebugLabelJet, 3, 0x70, 0x28);
            break;
        }
        field_debug_draw_label(gFieldDebugLabelMf, 2, 0x30, 0x30);
        field_debug_draw_value_blink(2, gFieldWork.debug_mf, 8, 0x50, 0x30);
        field_debug_draw_label(gFieldDebugLabelEf, 2, 0x30, 0x38);
        field_debug_draw_value_blink(3, gFieldWork.debug_ef, 8, 0x50, 0x38);
        switch (gFieldWork.debug_ef) {
        case 0:
            field_debug_draw_label(gFieldDebugLabelEe, 2, 0x70, 0x38);
            break;
        case 1:
            field_debug_draw_label(gFieldDebugLabelMp, 2, 0x70, 0x38);
            break;
        case 2:
            field_debug_draw_label(gFieldDebugLabelTe, 2, 0x70, 0x38);
            break;
        case 3:
            field_debug_draw_label(gFieldDebugLabelEx, 2, 0x70, 0x38);
            break;
        }
        field_debug_draw_label(gFieldDebugLabelSt, 2, 0x30, 0x40);
        field_debug_draw_value_blink(4, gFieldWork.story_phase, 8, 0x50, 0x40);
        field_debug_draw_label(gFieldDebugLabelCm, 2, 0x30, 0x48);
        field_debug_draw_value_blink(5, gFieldWork.medawatch_enabled, 8, 0x50, 0x48);
        break;
    case 1:
        field_debug_draw_label(gFieldDebugLabelEvent, 5, 0x68, 0x18);
        field_debug_draw_label(gFieldDebugLabelEno, 3, 0x30, 0x20);
        field_debug_draw_value_blink(0, *gFieldDebugEventValues[0], 16, 0x50, 0x20);
        field_debug_draw_label(gFieldDebugLabelFlg, 3, 0x30, 0x28);
        field_debug_draw_value_blink(1, *gFieldDebugEventValues[1], 8, 0x50, 0x28);
        field_debug_draw_label(gFieldDebugLabelX, 1, 0x70, 0x28);
        field_debug_draw_label(gFieldDebugLabelLv, 2, 0x30, 0x30);
        field_debug_draw_value_blink(2, *gFieldDebugEventValues[2], 8, 0x50, 0x30);
        field_debug_draw_label(gFieldDebugLabelX, 1, 0x70, 0x30);
        break;
    case 2:
        field_debug_draw_label(gFieldDebugLabelPlayer, 6, 0x68, 0x18);
        field_debug_draw_label(gFieldDebugLabelPlx, 3, 0x30, 0x20);
        field_debug_draw_value_blink(0, gFieldWork.player_x, 16, 0x50, 0x20);
        field_debug_draw_label(gFieldDebugLabelPly, 3, 0x30, 0x28);
        field_debug_draw_value_blink(0, gFieldWork.player_y, 16, 0x50, 0x28);
        break;
    case 3:
        field_debug_draw_label(gFieldDebugLabelMapEffect, 10, 0x68, 0x18);
        field_debug_draw_label(gFieldDebugLabelMen, 3, 0x30, 0x20);
        field_debug_draw_value_blink(0, gFieldDebug.effect_id, 16, 0x50, 0x20);
        break;
    case 4:
        field_debug_draw_label(gFieldDebugLabelKwg, 3, 0x68, 0x18);
        field_debug_draw_label(gFieldDebugLabelDc, 2, 0x30, 0x20);
        field_debug_draw_value_blink(0, gFieldDebug.debug_dc, 8, 0x50, 0x20);
        field_debug_draw_label(gFieldDebugLabelMl, 2, 0x30, 0x28);
        field_debug_draw_value_blink(1, gFieldSceneParams.area_speed_id, 8, 0x50, 0x28);
        field_debug_draw_label(gFieldDebugLabelBt, 2, 0x30, 0x30);
        field_debug_draw_value_blink(2, gFieldWork.debug_bt_flags, 8, 0x50, 0x30);
        if (gFieldWork.debug_bt_flags & 1)
            field_debug_draw_label(gFieldDebugLabelR, 1, 0x70, 0x30);
        else
            field_debug_draw_label(gFieldDebugLabelBlank, 1, 0x70, 0x30);
        if (gFieldWork.debug_bt_flags & 2)
            field_debug_draw_label(gFieldDebugLabelE, 1, 0x90, 0x30);
        else
            field_debug_draw_label(gFieldDebugLabelBlank, 1, 0x90, 0x30);
        field_debug_draw_label(gFieldDebugLabelSk, 2, 0x30, 0x38);
        field_debug_draw_value_blink(3, gFieldWork.debug_sk, 8, 0x50, 0x38);
        field_debug_draw_label(gFieldDebugLabelSp, 2, 0x30, 0x40);
        field_debug_draw_value_blink(4, gFieldWork.debug_sp, 8, 0x50, 0x40);
        field_debug_draw_label(gFieldDebugLabelX, 1, 0x70, 0x40);
        field_debug_draw_label(gFieldDebugLabelWl, 2, 0x30, 0x48);
        field_debug_draw_value_blink(5, gFieldWork.robattle_result, 8, 0x50, 0x48);
        switch (gFieldWork.robattle_result) {
        case 0:
            field_debug_draw_label(gFieldDebugLabelN, 1, 0x70, 0x48);
            break;
        case 1:
            field_debug_draw_label(gFieldDebugLabelW, 1, 0x70, 0x48);
            break;
        case 2:
            field_debug_draw_label(gFieldDebugLabelL, 1, 0x70, 0x48);
            break;
        }
        break;
    case 5:
        field_debug_draw_label(gFieldDebugLabelKoma, 4, 0x68, 0x18);
        field_debug_draw_label(gFieldDebugLabelKno, 3, 0x30, 0x20);
        field_debug_draw_value_blink(0, gFieldDebug.preview_sprite_set, 16, 0x50, 0x20);
        if (gFieldDebug.showing != 0) {
            advance_sprite_animation_frame(0x31);
            advance_sprite_animation_frame(0x32);
            advance_sprite_animation_frame(0x33);
            advance_sprite_animation_frame(0x34);
            if (gSpriteSheetPreviewKinds[gFieldDebug.preview_sprite_set] == 3)
                advance_sprite_animation_frame(0x39);
        }
        break;
    case 6:
        switch (gFieldDebug.showing) {
        case 0:
            field_debug_draw_label(gFieldDebugLabelMess, 4, 0x68, 0x18);
            field_debug_draw_label(gFieldDebugLabelMsb, 3, 0x30, 0x20);
            field_debug_draw_value_blink(0, gFieldDebug.text_bank, 16, 0x50, 0x20);
            field_debug_draw_label(gFieldDebugLabelMsn, 3, 0x30, 0x28);
            field_debug_draw_value_blink(1, gFieldDebug.text_id, 16, 0x50, 0x28);
            field_debug_draw_label(gFieldDebugLabelMsf, 3, 0x30, 0x30);
            field_debug_draw_value_blink(2, gFieldDebug.text_auto_next, 16, 0x50, 0x30);
            field_debug_draw_label(gFieldDebugLabelMax, 3, 0x30, 0x38);
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
        field_debug_draw_label(gFieldDebugLabelLv, 2, 0x68, 0x18);
        field_debug_draw_label(gFieldDebugLabelAr, 2, 0x30, 0x20);
        field_debug_draw_value_blink(0, gFieldWork.affinity_ar, 8, 0x50, 0x20);
        field_debug_draw_label(gFieldDebugLabelKa, 2, 0x30, 0x28);
        field_debug_draw_value_blink(1, gFieldWork.affinity_ka, 8, 0x50, 0x28);
        field_debug_draw_label(gFieldDebugLabelBgm, 3, 0x30, 0x30);
        field_debug_draw_value_blink(2, gFieldDebug.song_id, 8, 0x50, 0x30);
        field_debug_draw_label(gFieldDebugLabelSe, 2, 0x30, 0x38);
        field_debug_draw_value_blink(3, gFieldDebug.sound_id, 8, 0x50, 0x38);
        field_debug_draw_label(gFieldDebugLabelPnt, 3, 0x30, 0x40);
        field_debug_draw_value_blink(4, gFieldWork.useBlockFlags, 8, 0x50, 0x40);
        field_debug_draw_label(gFieldDebugLabelX, 1, 0x70, 0x40);
        break;
    }
}

void field_debug_draw_value_blink(s8 key, s32 value, u8 width, u8 x, u8 y) {
    struct FieldDebugWork *dbg = &gFieldDebug;

    if (key != dbg->rows[dbg->page]) {
        field_debug_draw_hex(value, width, x, y);
    } else if (dbg->frame & 0x10) {
        s32 i;
        for (i = 0; i < width >> 3; i++) {
            sprite_entry_clear(dbg->next_sprite);
            dbg->next_sprite++;
            sprite_entry_clear(dbg->next_sprite);
            dbg->next_sprite++;
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
                DmaCopy32(3, gFieldSpritePalettes[gPlayerFormSpriteSheets[gFieldWork.player_form]],
                          (void *)PLTT + 0x200, 0x20);
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
    if (gFieldDebug.debug_dc == 0) {
        gFieldDebug.labels_drawn = 0;
        field_debug_clear_sprites();
    }
    gFieldDebug.frame = 0;
    switch (gFieldDebug.page) {
    case 0:
    case 2:
        gFieldState.step = 0;
        gGameSubState = 0x33;
        break;
    case 1:
        gFieldState.step = 0;
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
    sprite_entry_init(gFieldDebug.next_sprite, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE,
                      gFieldDebug.next_sprite + 0x99, 14, 1);
    gSpriteEntries[gFieldDebug.next_sprite].x = x;
    gSpriteEntries[gFieldDebug.next_sprite].y = y;
    gFieldDebug.next_sprite++;

    DmaSet(3, &gFieldDebugFont[(tens + '0') * 32], 0x06017A00 + gFieldDebug.next_sprite * 32, 0x84000008);
    sprite_entry_init(gFieldDebug.next_sprite, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE,
                      gFieldDebug.next_sprite + 0x99, 14, 1);
    gSpriteEntries[gFieldDebug.next_sprite].x = x + 8;
    gSpriteEntries[gFieldDebug.next_sprite].y = y;
    gFieldDebug.next_sprite++;

    DmaSet(3, &gFieldDebugFont[(ones + '0') * 32], 0x06017A00 + gFieldDebug.next_sprite * 32, 0x84000008);
    sprite_entry_init(gFieldDebug.next_sprite, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE,
                      gFieldDebug.next_sprite + 0x99, 14, 1);
    gSpriteEntries[gFieldDebug.next_sprite].x = x + 16;
    gSpriteEntries[gFieldDebug.next_sprite].y = y;
    gFieldDebug.next_sprite++;
}

static void field_debug_draw_hex(u32 value, s32 bits, s32 x, s32 y) {
    u8 hex[16];
    s32 i;
    u8 byte;
    u8 hi, lo;

    memcpy_optimized(hex, gFieldDebugHexDigits, 16);
    for (i = 0; i < bits / 8; i++) {
        if (bits / 8 == 4) {
            if (i == 0)
                byte = value >> 24;
            if (i == 1)
                byte = (value & 0xFF0000) >> 16;
            if (i == 2)
                byte = (value & 0xFF00) >> 8;
            if (i == 3)
                byte = value;
        } else if (bits / 8 == 2) {
            if (i == 0)
                byte = (value & 0xFF00) >> 8;
            if (i == 1)
                byte = value;
        } else if (bits / 8 == 1) {
            if (i == 0)
                byte = value;
        }
        hi = byte >> 4;
        lo = byte - hi * 16;

        DmaSet(3, &gFieldDebugFont[hex[hi] * 32], 0x06017A00 + gFieldDebug.next_sprite * 32, 0x84000008);
        sprite_entry_init(gFieldDebug.next_sprite, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE,
                          gFieldDebug.next_sprite + 0x99, 14, 1);
        gSpriteEntries[gFieldDebug.next_sprite].x = x + i * 16;
        gSpriteEntries[gFieldDebug.next_sprite].y = y;
        gFieldDebug.next_sprite++;

        DmaSet(3, &gFieldDebugFont[hex[lo] * 32], 0x06017A00 + gFieldDebug.next_sprite * 32, 0x84000008);
        sprite_entry_init(gFieldDebug.next_sprite, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE,
                          gFieldDebug.next_sprite + 0x99, 14, 1);
        gSpriteEntries[gFieldDebug.next_sprite].x = x + i * 16 + 8;
        gSpriteEntries[gFieldDebug.next_sprite].y = y;
        gFieldDebug.next_sprite++;
    }
}

void field_debug_draw_label(const u8 *digits, s32 count, s32 x, s32 y) {
    s32 i;

    for (i = 0; i < count; i++) {
        DmaSet(3, &gFieldDebugFont[*digits * 32], 0x06017A00 + gFieldDebug.next_sprite * 32, 0x84000008);
        sprite_entry_init(gFieldDebug.next_sprite, SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE,
                          gFieldDebug.next_sprite + 0x99, 14, 1);
        gSpriteEntries[gFieldDebug.next_sprite].x = x;
        gSpriteEntries[gFieldDebug.next_sprite].y = y;
        x += 8;
        gFieldDebug.next_sprite++;
        digits++;
    }
}

// battle field 4x2 grid: sprites 49-56 with shadows 91-98, then sprite 57 / shadow 99
static inline void init_field_sprite(u8 row, u8 col) {
    u8 slot = 49 + row * 4 + col;
    u8 j = slot + 42;

    gSpriteEntries[slot].work16[FIELD_SPR_SHEET] = gFieldDebug.preview_sprite_set;
    gSpriteEntries[slot].pos_x = gFieldPlayerX + (col * 32 - 48);
    gSpriteEntries[slot].pos_y = gFieldPlayerY + (16 - row * 32);
    gSpriteEntries[slot].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[slot].work[FIELD_SPR_ON_SCREEN] = 1;
    gSpriteEntries[j].flags =
        SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3) | SPRITE_OBJ_MODE(1) | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[slot].x = gSpriteEntries[slot].pos_x - (u16)gBg1Scroll.x;
    gSpriteEntries[slot].y = gSpriteEntries[slot].pos_y - (u16)gBg1Scroll.y;
    gSpriteEntries[j].x = gSpriteEntries[slot].x;
    gSpriteEntries[j].y = gSpriteEntries[slot].y + (s16)(gSpriteEntries[slot].work[FIELD_SPR_HEIGHT] - 5);
    gSpriteEntries[slot].frame = row * 48 + col * 15;
    sprite_anim_start(slot, 4 + row * 16 + col * 5);
}

void field_debug_draw_sprite_preview(void) {
    s16 zero; // FAKEMATCH: only set inside the first if, read after it (uninitialised on the other path)

    fill_sprite_sheets(gFieldDebug.preview_sprite_set);
    fill_sprite_palettes(gFieldDebug.preview_sprite_set);
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
        gSpriteEntries[slot].work16[FIELD_SPR_SHEET] = gFieldDebug.preview_sprite_set;
        if (gSpriteSheetPreviewKinds[gFieldDebug.preview_sprite_set] == 3) {
            sprite_entry_init(slot,
                              SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(2) | SPRITE_FLAG_PART_PALETTE,
                              sprite_code_anim_index(0), sprite_code_kind(0), 1);
            gSpriteEntries[slot].work[FIELD_SPR_ANIM_SET] = sprite_code_kind(0);
            gSpriteEntries[slot].pos_x = gFieldPlayerX - 0x30;
            gSpriteEntries[slot].pos_y = gFieldPlayerY + 0x30;
            gEntityStates[slot].active = 0xFFFF;
            gSpriteEntries[slot].work[FIELD_SPR_HEIGHT] = zero = 0;
            sprite_anim_start(slot, 0x60);
        }
        gSpriteEntries[j].flags = zero;
        if (gSpriteSheetHasShadow[gFieldDebug.preview_sprite_set] != 0) {
            gSpriteEntries[j].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(3) |
                                      SPRITE_OBJ_MODE(1) | SPRITE_FLAG_PART_PALETTE;
            gSpriteEntries[j].x = gSpriteEntries[slot].x;
            gSpriteEntries[j].y = gSpriteEntries[slot].y + (s16)(gSpriteEntries[slot].work[FIELD_SPR_HEIGHT] - 5);
        }
    }
}
