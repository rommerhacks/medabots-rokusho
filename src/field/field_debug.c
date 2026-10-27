// Debug battle-field screen: the field sub-states sub_0804AF4C..sub_0804AF80 in field/field_update call
// in here. sub_08058214 runs one page (gUnk_030057A0.unk14) a frame: the d-pad cycles values (R held = steps
// of 16) through the cyclers sub_0805889C..sub_08058A88, sub_08058B04 draws the page as hex-digit sprites,
// and init_battle_field_sprites previews the chosen battle field. State is gUnk_030057A0.
#include "global.h"

static void dispatch_by_index(u32 idx);
static void sub_08058908(u32 idx, s32 max);
static void sub_080589B0(u32 idx, s32 max);
static void update_anim_counter(u32 idx, s32 max);
static void sub_08058A88(u32 idx, u32 sub, s32 max);
static void sub_08058B04(u32 idx);
static void clear_all_battle_sprites(void);
static void load_battle_sprite_from_index(u32 value, s32 bits, s32 x, s32 y);

void sub_08058110(void) {
    dispatch_by_index(gUnk_030057A0.unk14);
}

static void dispatch_by_index(u32 idx) {
    switch (idx) {
    case 0:
        gUnk_030057A0.unk26 = gUnk_030057E0.unk7FE;
        break;
    case 1:
        gUnk_030057A0.unk28 = gUnk_030057E0.unkC90;
        gUnk_030057A0.unk2A = sub_08053194(gUnk_030057A0.unk28);
        gUnk_030057A0.unk2C = sub_08053288(gUnk_030057A0.unk28);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        gUnk_030057A0.unk32 = 0;
        break;
    case 6:
        gUnk_030057A0.unk32 = 0;
        gUnk_030057A0.unk24 = 0;
        break;
    }
}

static void sub_080581C0(u32 a, s32 b) {
    switch (a) {
    case 0:
        break;
    case 1:
        if (b == 0) {
            gUnk_030057A0.unk2A = sub_08053194(gUnk_030057A0.unk28);
            gUnk_030057A0.unk2C = sub_08053288(gUnk_030057A0.unk28);
        } else if (b < 0) {
        } else if (b <= 2) {
            sub_080531D0(gUnk_030057A0.unk28, gUnk_030057A0.unk2A);
            sub_080531EC(gUnk_030057A0.unk28, gUnk_030057A0.unk2C);
        }
        break;
    }
}

// Local view of gUnk_030057A0 (struct Unk_030057A0 would need unk0, unk12, unk15, s8 unk16[8], unk1E,

void sub_08058214(u32 mode) {
    gUnk_030057A0.unk15++;

    switch (mode) {
    case 0:
        sub_0805889C(6);
        switch (gUnk_030057A0.unk16[gUnk_030057A0.unk14]) {
        case 0:
            sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 0xC0);
            break;
        case 1:
            sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 0x10);
            break;
        case 3:
            sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 4);
            break;
        case 4:
            sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 10);
            break;
        case 2:
        case 5:
            sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 2);
            break;
        }
        break;
    case 1:
        sub_0805889C(3);
        switch (gUnk_030057A0.unk16[gUnk_030057A0.unk14]) {
        case 0:
            sub_08058908(0, 3000);
            break;
        case 1:
            sub_08058908(1, 2);
            break;
        case 2:
            sub_08058908(2, 8);
            break;
        }
        break;
    case 2:
        if (KEYS_LO(gRepeatKeys) & 0x40)
            gUnk_030057E0.unkC54 -= 0x10;
        if (KEYS_LO(gRepeatKeys) & 0x80)
            gUnk_030057E0.unkC54 += 0x10;
        if (KEYS_LO(gRepeatKeys) & 0x20)
            gUnk_030057E0.unkC52 -= 0x10;
        if (KEYS_LO(gRepeatKeys) & 0x10)
            gUnk_030057E0.unkC52 += 0x10;
        gUnk_030057E0.unkC56 = sub_080526F0(gUnk_030057E0.unkC52);
        gUnk_030057E0.unkC57 = sub_08052714(gUnk_030057E0.unkC54);
        field_center_camera_on_player();
        break;
    case 3:
        if (KEYS_LO(gRepeatKeys) & 0x20) {
            if (--gUnk_030057A0.unk12 == 0xFF)
                gUnk_030057A0.unk12 = 0x1F;
        }
        if (KEYS_LO(gRepeatKeys) & 0x10) {
            if (++gUnk_030057A0.unk12 > 0x1F)
                gUnk_030057A0.unk12 = 0;
        }
        break;
    case 4:
        sub_0805889C(6);
        switch (gUnk_030057A0.unk16[gUnk_030057A0.unk14]) {
        case 1:
            sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 3);
            break;
        case 2:
            sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 4);
            break;
        case 0:
        case 3:
        case 4:
            sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 2);
            break;
        case 5:
            sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 3);
            break;
        }
        REG_BLDALPHA = ((gBlendEffect.evb & 0x3F) << 8) | (gBlendEffect.eva & 0x3F);
        REG_BLDY = gBlendEffect.evy & 0x3F;
        break;
    case 5:
        sub_08058A88(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14], 0xB0);
        gUnk_030057A0.unk32 = 1;
        break;
    case 6:
        if (gUnk_030057A0.unk32 == 0) {
            const u32 *const *p;
            s32 n;

            sub_0805889C(3);
            switch (gUnk_030057A0.unk16[gUnk_030057A0.unk14]) {
            case 0:
                sub_080589B0(0, 0x10);
                break;
            case 1:
                sub_080589B0(1, gUnk_030057A0.unk1E);
                break;
            case 2:
                sub_080589B0(2, 2);
                break;
            }
            p = (const u32 *const *)gTextBankTables[gUnk_030057A0.unk20];
            n = 0;
            if (*p != 0) {
                do {
                    p++;
                    n++;
                    if (n > 0xFFF)
                        break;
                } while (*p != 0);
            }
            gUnk_030057A0.unk1E = n;
            if (gUnk_030057A0.unk30 >= (u16)n)
                gUnk_030057A0.unk30 = n - 1;
        }
        break;
    case 7:
        sub_0805889C(5);
        switch (gUnk_030057A0.unk16[gUnk_030057A0.unk14]) {
        case 0:
        case 1:
            update_anim_counter(gUnk_030057A0.unk16[gUnk_030057A0.unk14], 0x20);
            break;
        case 2:
            update_anim_counter(gUnk_030057A0.unk16[gUnk_030057A0.unk14], 0x80);
            break;
        case 3:
            update_anim_counter(gUnk_030057A0.unk16[gUnk_030057A0.unk14], 0xA0);
            break;
        case 4:
            update_anim_counter(gUnk_030057A0.unk16[gUnk_030057A0.unk14], 0x100);
            break;
        }
        switch (gUnk_030057A0.unk16[gUnk_030057A0.unk14]) {
        case 2:
            if (KEYS_LO(gRepeatKeys) & 1)
                field_play_song(gUnk_030057A0.unk33);
            break;
        case 3:
            if (KEYS_LO(gRepeatKeys) & 1)
                field_play_sound_effect(gUnk_030057A0.unk34);
            break;
        case 1:
            break;
        }
        break;
    }

    if (KEYS_LO(gNewKeys) & 4) {
        if (++gUnk_030057A0.unk14 > 7)
            gUnk_030057A0.unk14 = 0;
        clear_all_battle_sprites();
        dispatch_by_index(gUnk_030057A0.unk14);
    }
    if (KEYS_LO(gRepeatKeys) & 2)
        handle_battle_end_state_transition();
    if (KEYS_LO(gRepeatKeys) & 1) {
        switch (gUnk_030057A0.unk14) {
        case 3:
            gUnk_030057A0.unk10 = 0;
            clear_all_battle_sprites();
            init_sprite_affine_matrices_and_state(gUnk_030057A0.unk12, gUnk_030057E0.unkC52, gUnk_030057E0.unkC54, 0);
            if (gUnk_030057A0.unk12 == 0xE)
                gUnk_030057E0.unkC5C = 0xC;
            else if (gUnk_030057A0.unk12 == 0x12)
                gUnk_030057E0.unkC5C = 0xB;
            if (gUnk_030057A0.unk12 == 0xE || gUnk_030057A0.unk12 == 0x12) {
                area_load_sprite_sheets();
                DmaCopy32(3, gUnk_083F8634[gUnk_083D29A6[gUnk_030057E0.unkC5C]], OBJ_PLTT, 32);
                gUnk_030057E0.unkC28 = gUnk_030057E0.unkC5C;
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
            play_sound_effect(gUnk_030057A0.unk0);
            break;
        case 6:
            if (gUnk_030057A0.unk32 == 0) {
                if (gUnk_030057A0.unk24 != 0) {
                    gUnk_030057A0.unk30++;
                    if (gUnk_030057A0.unk30 >= gUnk_030057A0.unk1E) {
                        gUnk_030057A0.unk30 = 0;
                        gUnk_030057A0.unk2E++;
                        if (gUnk_030057A0.unk2E > 0xF)
                            gUnk_030057A0.unk2E = 0;
                    }
                }
                gUnk_030057A0.unk15 = 0;
                sub_08058B04(gUnk_030057A0.unk14);
                message_steps_reset();
                gUnk_030057A0.unk32++;
            }
            break;
        }
    }
}

void sub_0805889C(s32 max) {
    if (KEYS_LO(gRepeatKeys) & 0x40) {
        gUnk_030057A0.unk16[gUnk_030057A0.unk14]--;
        if (gUnk_030057A0.unk16[gUnk_030057A0.unk14] < 0)
            gUnk_030057A0.unk16[gUnk_030057A0.unk14] = max - 1;
    }
    if (KEYS_LO(gRepeatKeys) & 0x80) {
        gUnk_030057A0.unk16[gUnk_030057A0.unk14]++;
        if (gUnk_030057A0.unk16[gUnk_030057A0.unk14] >= max)
            gUnk_030057A0.unk16[gUnk_030057A0.unk14] = 0;
    }
}

static void sub_08058908(u32 idx, s32 max) {
    u8 left;
    u16 *p;
    s32 step = 1;

    if (KEYS_HI(gHeldKeys) & 1)
        step = 0x10;

    if ((left = KEYS_LO(gRepeatKeys) & 0x20)) {
        p = gUnk_083D6070[idx];
        if ((u16)(*p -= step) == 0xFFFF)
            *p = max - 1;
        sub_080581C0(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14]);
    } else if (KEYS_LO(gRepeatKeys) & 0x10) {
        p = gUnk_083D6070[idx];
        *p += step;
        if (*p >= max)
            *p = left;
        sub_080581C0(gUnk_030057A0.unk14, gUnk_030057A0.unk16[gUnk_030057A0.unk14]);
    }
}

static void sub_080589B0(u32 idx, s32 max) {
    s32 v;
    u16 *p;
    s32 step = 1;

    if (KEYS_HI(gHeldKeys) & 1)
        step = 0x10;

    if (KEYS_LO(gRepeatKeys) & 0x20) {
        p = gUnk_083D607C[idx];
        v = *p;
        v -= step;
        if (v == -1)
            v = max - 1;
        *p = v;
    } else if (KEYS_LO(gRepeatKeys) & 0x10) {
        p = gUnk_083D607C[idx];
        v = *p;
        v += step;
        if (v >= max)
            v = 0;
        *p = v;
    }
}

static void update_anim_counter(u32 idx, s32 max) {
    u8 left;
    u8 *p;

    if ((left = KEYS_LO(gRepeatKeys) & 0x20)) {
        p = gUnk_083D6088[idx];
        if ((s8)-- * p == -1)
            *p = max - 1;
    } else if (KEYS_LO(gRepeatKeys) & 0x10) {
        p = gUnk_083D6088[idx];
        (*p)++;
        if (*p >= max)
            *p = left;
    }
}

static void sub_08058A88(u32 idx, u32 sub, s32 max) {
    u8 changed = 0;
    s32 v;
    u8 **row;

    if (KEYS_LO(gRepeatKeys) & 0x20) {
        u8 *p;
        row = gUnk_083D60DC[idx];
        p = row[sub];
        v = *p;
        v -= 1;
        if (v == -1)
            v = max - 1;
        *p = v;
        changed = 1;
    } else if (KEYS_LO(gRepeatKeys) & 0x10) {
        u8 *p;
        row = gUnk_083D60DC[idx];
        p = row[sub];
        v = *p;
        v += 1;
        if (v >= max)
            v = 0;
        *p = v;
        changed = 1;
    }
    if (changed && idx == 5)
        init_battle_field_sprites();
}

static void sub_08058B04(u32 mode) {
    gUnk_030057A0.unk13 = 0;
    update_bg_scroll_offsets_a();
    load_battle_sprite_tile(gUnk_080AC494, 2, 0x28, 0x18);
    load_battle_sprite_from_index(gUnk_030057A0.unk14, 8, 0x50, 0x18);
    switch (mode) {
    case 0:
        load_battle_sprite_tile(gUnk_080AC498, 2, 0x68, 0x18);
        load_battle_sprite_tile(gUnk_080AC49C, 2, 0x30, 0x20);
        load_or_clear_battle_sprites(0, gUnk_030057A0.unk26, 8, 0x50, 0x20);
        load_battle_sprite_tile(gUnk_080AC4A0, 2, 0x30, 0x28);
        load_or_clear_battle_sprites(1, gUnk_030057E0.unkC5C, 8, 0x50, 0x28);
        switch (gUnk_030057E0.unkC5C) {
        case 0:
            load_battle_sprite_tile(gUnk_080AC4A4, 3, 0x70, 0x28);
            break;
        case 1:
            load_battle_sprite_tile(gUnk_080AC4A8, 3, 0x70, 0x28);
            break;
        case 2:
            load_battle_sprite_tile(gUnk_080AC4AC, 3, 0x70, 0x28);
            break;
        case 3:
            load_battle_sprite_tile(gUnk_080AC4B0, 3, 0x70, 0x28);
            break;
        case 4:
            load_battle_sprite_tile(gUnk_080AC4B4, 3, 0x70, 0x28);
            break;
        case 5:
            load_battle_sprite_tile(gUnk_080AC4B8, 3, 0x70, 0x28);
            break;
        case 6:
            load_battle_sprite_tile(gUnk_080AC4BC, 3, 0x70, 0x28);
            break;
        case 7:
            load_battle_sprite_tile(gUnk_080AC4C0, 3, 0x70, 0x28);
            break;
        case 8:
            load_battle_sprite_tile(gUnk_080AC4C4, 3, 0x70, 0x28);
            break;
        case 9:
            load_battle_sprite_tile(gUnk_080AC4C8, 3, 0x70, 0x28);
            break;
        case 10:
            load_battle_sprite_tile(gUnk_080AC4CC, 3, 0x70, 0x28);
            break;
        case 11:
            load_battle_sprite_tile(gUnk_080AC4D0, 3, 0x70, 0x28);
            break;
        case 12:
            load_battle_sprite_tile(gUnk_080AC4D4, 3, 0x70, 0x28);
            break;
        case 13:
            load_battle_sprite_tile(gUnk_080AC4D8, 3, 0x70, 0x28);
            break;
        case 14:
            load_battle_sprite_tile(gUnk_080AC4DC, 3, 0x70, 0x28);
            break;
        case 15:
            load_battle_sprite_tile(gUnk_080AC4E0, 3, 0x70, 0x28);
            break;
        }
        load_battle_sprite_tile(gUnk_080AC4E4, 2, 0x30, 0x30);
        load_or_clear_battle_sprites(2, gUnk_030057E0.unkC4D, 8, 0x50, 0x30);
        load_battle_sprite_tile(gUnk_080AC4E8, 2, 0x30, 0x38);
        load_or_clear_battle_sprites(3, gUnk_030057E0.unkCB7, 8, 0x50, 0x38);
        switch (gUnk_030057E0.unkCB7) {
        case 0:
            load_battle_sprite_tile(gUnk_080AC4EC, 2, 0x70, 0x38);
            break;
        case 1:
            load_battle_sprite_tile(gUnk_080AC498, 2, 0x70, 0x38);
            break;
        case 2:
            load_battle_sprite_tile(gUnk_080AC4F0, 2, 0x70, 0x38);
            break;
        case 3:
            load_battle_sprite_tile(gUnk_080AC4F4, 2, 0x70, 0x38);
            break;
        }
        load_battle_sprite_tile(gUnk_080AC4F8, 2, 0x30, 0x40);
        load_or_clear_battle_sprites(4, gUnk_030057E0.unk7FF, 8, 0x50, 0x40);
        load_battle_sprite_tile(gUnk_080AC4FC, 2, 0x30, 0x48);
        load_or_clear_battle_sprites(5, gUnk_030057E0.unkC33, 8, 0x50, 0x48);
        break;
    case 1:
        load_battle_sprite_tile(gUnk_080AC500, 5, 0x68, 0x18);
        load_battle_sprite_tile(gUnk_080AC508, 3, 0x30, 0x20);
        load_or_clear_battle_sprites(0, *gUnk_083D6070[0], 16, 0x50, 0x20);
        load_battle_sprite_tile(gUnk_080AC50C, 3, 0x30, 0x28);
        load_or_clear_battle_sprites(1, *gUnk_083D6070[1], 8, 0x50, 0x28);
        load_battle_sprite_tile(gUnk_080AC510, 1, 0x70, 0x28);
        load_battle_sprite_tile(gUnk_080AC514, 2, 0x30, 0x30);
        load_or_clear_battle_sprites(2, *gUnk_083D6070[2], 8, 0x50, 0x30);
        load_battle_sprite_tile(gUnk_080AC510, 1, 0x70, 0x30);
        break;
    case 2:
        load_battle_sprite_tile(gUnk_080AC518, 6, 0x68, 0x18);
        load_battle_sprite_tile(gUnk_080AC520, 3, 0x30, 0x20);
        load_or_clear_battle_sprites(0, gUnk_030057E0.unkC52, 16, 0x50, 0x20);
        load_battle_sprite_tile(gUnk_080AC524, 3, 0x30, 0x28);
        load_or_clear_battle_sprites(0, gUnk_030057E0.unkC54, 16, 0x50, 0x28);
        break;
    case 3:
        load_battle_sprite_tile(gUnk_080AC528, 10, 0x68, 0x18);
        load_battle_sprite_tile(gUnk_080AC534, 3, 0x30, 0x20);
        load_or_clear_battle_sprites(0, gUnk_030057A0.unk12, 16, 0x50, 0x20);
        break;
    case 4:
        load_battle_sprite_tile(gUnk_080AC538, 3, 0x68, 0x18);
        load_battle_sprite_tile(gUnk_080AC53C, 2, 0x30, 0x20);
        load_or_clear_battle_sprites(0, gUnk_030057A0.unk11, 8, 0x50, 0x20);
        load_battle_sprite_tile(gUnk_080AC540, 2, 0x30, 0x28);
        load_or_clear_battle_sprites(1, gUnk_03006D38.unk2, 8, 0x50, 0x28);
        load_battle_sprite_tile(gUnk_080AC544, 2, 0x30, 0x30);
        load_or_clear_battle_sprites(2, gUnk_030057E0.unkC4E, 8, 0x50, 0x30);
        if (gUnk_030057E0.unkC4E & 1)
            load_battle_sprite_tile(gUnk_080AC548, 1, 0x70, 0x30);
        else
            load_battle_sprite_tile(gUnk_080AC54C, 1, 0x70, 0x30);
        if (gUnk_030057E0.unkC4E & 2)
            load_battle_sprite_tile(gUnk_080AC550, 1, 0x90, 0x30);
        else
            load_battle_sprite_tile(gUnk_080AC54C, 1, 0x90, 0x30);
        load_battle_sprite_tile(gUnk_080AC554, 2, 0x30, 0x38);
        load_or_clear_battle_sprites(3, gUnk_030057E0.unkCB8, 8, 0x50, 0x38);
        load_battle_sprite_tile(gUnk_080AC558, 2, 0x30, 0x40);
        load_or_clear_battle_sprites(4, gUnk_030057E0.unkCB9, 8, 0x50, 0x40);
        load_battle_sprite_tile(gUnk_080AC510, 1, 0x70, 0x40);
        load_battle_sprite_tile(gUnk_080AC55C, 2, 0x30, 0x48);
        load_or_clear_battle_sprites(5, gUnk_030057E0.unkC4F, 8, 0x50, 0x48);
        switch (gUnk_030057E0.unkC4F) {
        case 0:
            load_battle_sprite_tile(gUnk_080AC560, 1, 0x70, 0x48);
            break;
        case 1:
            load_battle_sprite_tile(gUnk_080AC564, 1, 0x70, 0x48);
            break;
        case 2:
            load_battle_sprite_tile(gUnk_080AC568, 1, 0x70, 0x48);
            break;
        }
        break;
    case 5:
        load_battle_sprite_tile(gUnk_080AC56C, 4, 0x68, 0x18);
        load_battle_sprite_tile(gUnk_080AC574, 3, 0x30, 0x20);
        load_or_clear_battle_sprites(0, gUnk_030057A0.unk20, 16, 0x50, 0x20);
        if (gUnk_030057A0.unk32 != 0) {
            advance_sprite_animation_frame(0x31);
            advance_sprite_animation_frame(0x32);
            advance_sprite_animation_frame(0x33);
            advance_sprite_animation_frame(0x34);
            if (gUnk_083D2C3D[gUnk_030057A0.unk20] == 3)
                advance_sprite_animation_frame(0x39);
        }
        break;
    case 6:
        switch (gUnk_030057A0.unk32) {
        case 0:
            load_battle_sprite_tile(gUnk_080AC578, 4, 0x68, 0x18);
            load_battle_sprite_tile(gUnk_080AC580, 3, 0x30, 0x20);
            load_or_clear_battle_sprites(0, gUnk_030057A0.unk2E, 16, 0x50, 0x20);
            load_battle_sprite_tile(gUnk_080AC584, 3, 0x30, 0x28);
            load_or_clear_battle_sprites(1, gUnk_030057A0.unk30, 16, 0x50, 0x28);
            load_battle_sprite_tile(gUnk_080AC588, 3, 0x30, 0x30);
            load_or_clear_battle_sprites(2, gUnk_030057A0.unk24, 16, 0x50, 0x30);
            load_battle_sprite_tile(gUnk_080AC58C, 3, 0x30, 0x38);
            load_or_clear_battle_sprites(3, gUnk_030057A0.unk1E, 16, 0x50, 0x38);
            break;
        case 1: {
            const u32 *const *bank = gTextBankTables[gUnk_030057A0.unk2E];
            if (message_step_run(0, 0, 0, bank[gUnk_030057A0.unk30]))
                gUnk_030057A0.unk32 = 0;
        } break;
        }
        break;
    case 7:
        load_battle_sprite_tile(gUnk_080AC514, 2, 0x68, 0x18);
        load_battle_sprite_tile(gUnk_080AC590, 2, 0x30, 0x20);
        load_or_clear_battle_sprites(0, gUnk_030057E0.unkCBC, 8, 0x50, 0x20);
        load_battle_sprite_tile(gUnk_080AC594, 2, 0x30, 0x28);
        load_or_clear_battle_sprites(1, gUnk_030057E0.unkCBD, 8, 0x50, 0x28);
        load_battle_sprite_tile(gUnk_080AC598, 3, 0x30, 0x30);
        load_or_clear_battle_sprites(2, gUnk_030057A0.unk33, 8, 0x50, 0x30);
        load_battle_sprite_tile(gUnk_080AC59C, 2, 0x30, 0x38);
        load_or_clear_battle_sprites(3, gUnk_030057A0.unk34, 8, 0x50, 0x38);
        load_battle_sprite_tile(gUnk_080AC5A0, 3, 0x30, 0x40);
        load_or_clear_battle_sprites(4, gUnk_030057E0.unkC5D, 8, 0x50, 0x40);
        load_battle_sprite_tile(gUnk_080AC510, 1, 0x70, 0x40);
        break;
    }
}

void load_or_clear_battle_sprites(s8 key, s32 value, u8 width, u8 x, u8 y) {
    struct Unk_030057A0 *s = &gUnk_030057A0;

    if (key != s->unk16[s->unk14]) {
        load_battle_sprite_from_index(value, width, x, y);
    } else if (s->unk15 & 0x10) {
        s32 i;
        for (i = 0; i < width >> 3; i++) {
            sprite_entry_clear(s->unk13);
            s->unk13++;
            sprite_entry_clear(s->unk13);
            s->unk13++;
        }
    } else {
        load_battle_sprite_from_index(value, width, x, y);
    }
}

u32 sub_0805937C(void) {
    switch (gUnk_030057A0.unk14) {
    case 0:
    case 1:
    case 2:
    case 4:
        return 1;
    case 3:
        if (battle_sequence_dispatch() == 4) {
            gUnk_030057E0.unkC5C = 0;
            if (gUnk_030057A0.unk12 == 0xE || gUnk_030057A0.unk12 == 0x12) {
                area_load_sprite_sheets();
                DmaCopy32(3, gUnk_083F8634[gUnk_083D29A6[gUnk_030057E0.unkC5C]], (void *)PLTT + 0x200, 0x20);
                gUnk_030057E0.unkC28 = gUnk_030057E0.unkC5C;
                load_battle_terrain_data();
            }
            init_battle_sprites();
            return 1;
        }
        return 0;
    }
}

static void clear_all_battle_sprites(void) {
    s32 i;

    for (i = 0; i < 40; i++)
        sprite_entry_clear(i);
}

void handle_battle_end_state_transition(void) {
    if (gUnk_030057A0.unk11 == 0) {
        gUnk_030057A0.unk10 = 0;
        clear_all_battle_sprites();
    }
    gUnk_030057A0.unk15 = 0;
    switch (gUnk_030057A0.unk14) {
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
// load_battle_sprite_tile with the ASCII digits '0' + d.
static void sub_08059490(u8 *value, s32 x, s32 y) {
    u8 hundreds, tens, ones;

    hundreds = *value / 100;
    tens = (*value - hundreds * 100) / 10;
    ones = *value - hundreds * 100 - tens * 10;

    DmaSet(3, &gUnk_080ACB7C[(hundreds + '0') * 32], 0x06017A00 + gUnk_030057A0.unk13 * 32, 0x84000008);
    sprite_entry_init(gUnk_030057A0.unk13, 0xC004, gUnk_030057A0.unk13 + 0x99, 14, 1);
    gSpriteEntries[gUnk_030057A0.unk13].unk2 = x;
    gSpriteEntries[gUnk_030057A0.unk13].unk4 = y;
    gUnk_030057A0.unk13++;

    DmaSet(3, &gUnk_080ACB7C[(tens + '0') * 32], 0x06017A00 + gUnk_030057A0.unk13 * 32, 0x84000008);
    sprite_entry_init(gUnk_030057A0.unk13, 0xC004, gUnk_030057A0.unk13 + 0x99, 14, 1);
    gSpriteEntries[gUnk_030057A0.unk13].unk2 = x + 8;
    gSpriteEntries[gUnk_030057A0.unk13].unk4 = y;
    gUnk_030057A0.unk13++;

    DmaSet(3, &gUnk_080ACB7C[(ones + '0') * 32], 0x06017A00 + gUnk_030057A0.unk13 * 32, 0x84000008);
    sprite_entry_init(gUnk_030057A0.unk13, 0xC004, gUnk_030057A0.unk13 + 0x99, 14, 1);
    gSpriteEntries[gUnk_030057A0.unk13].unk2 = x + 16;
    gSpriteEntries[gUnk_030057A0.unk13].unk4 = y;
    gUnk_030057A0.unk13++;
}

static void load_battle_sprite_from_index(u32 value, s32 bits, s32 x, s32 y) {
    u8 hex[16];
    s32 i;
    u8 b;
    u8 hi, lo;

    memcpy_optimized(hex, gUnk_080AC5A4, 16);
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

        DmaSet(3, &gUnk_080ACB7C[hex[hi] * 32], 0x06017A00 + gUnk_030057A0.unk13 * 32, 0x84000008);
        sprite_entry_init(gUnk_030057A0.unk13, 0xC004, gUnk_030057A0.unk13 + 0x99, 14, 1);
        gSpriteEntries[gUnk_030057A0.unk13].unk2 = x + i * 16;
        gSpriteEntries[gUnk_030057A0.unk13].unk4 = y;
        gUnk_030057A0.unk13++;

        DmaSet(3, &gUnk_080ACB7C[hex[lo] * 32], 0x06017A00 + gUnk_030057A0.unk13 * 32, 0x84000008);
        sprite_entry_init(gUnk_030057A0.unk13, 0xC004, gUnk_030057A0.unk13 + 0x99, 14, 1);
        gSpriteEntries[gUnk_030057A0.unk13].unk2 = x + i * 16 + 8;
        gSpriteEntries[gUnk_030057A0.unk13].unk4 = y;
        gUnk_030057A0.unk13++;
    }
}

void load_battle_sprite_tile(const u8 *digits, s32 count, s32 x, s32 y) {
    s32 i;

    for (i = 0; i < count; i++) {
        DmaSet(3, &gUnk_080ACB7C[*digits * 32], 0x06017A00 + gUnk_030057A0.unk13 * 32, 0x84000008);
        sprite_entry_init(gUnk_030057A0.unk13, 0xC004, gUnk_030057A0.unk13 + 0x99, 14, 1);
        gSpriteEntries[gUnk_030057A0.unk13].unk2 = x;
        gSpriteEntries[gUnk_030057A0.unk13].unk4 = y;
        x += 8;
        gUnk_030057A0.unk13++;
        digits++;
    }
}

// battle field 4x2 grid: sprites 49-56 with shadows 91-98, then sprite 57 / shadow 99
static inline void init_field_sprite(u8 row, u8 col) {
    u8 slot = 49 + row * 4 + col;
    u8 j = slot + 42;

    gSpriteEntries[slot].unk30 = gUnk_030057A0.unk20;
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

void init_battle_field_sprites(void) {
    s16 zero; // FAKEMATCH: only set inside the first if, read after it (uninitialised on the other path)

    fill_sprite_sheets(gUnk_030057A0.unk20);
    fill_sprite_palettes(gUnk_030057A0.unk20);
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
        gSpriteEntries[slot].unk30 = gUnk_030057A0.unk20;
        if (gUnk_083D2C3D[gUnk_030057A0.unk20] == 3) {
            sprite_entry_init(slot, 0xC804, calc_medapart_table_index(0), sub_08050264(0), 1);
            gSpriteEntries[slot].unk2B = sub_08050264(0);
            gSpriteEntries[slot].unkC_8 = gUnk_03006432 - 0x30;
            gSpriteEntries[slot].unk10_8 = gUnk_03006434 + 0x30;
            gUnk_030055A0[slot].unk0 = 0xFFFF;
            gSpriteEntries[slot].unk2C = zero = 0;
            sprite_anim_start(slot, 0x60);
        }
        gSpriteEntries[j].unk0 = zero;
        if (gUnk_083D2B8D[gUnk_030057A0.unk20] != 0) {
            gSpriteEntries[j].unk0 = 0xCC0C;
            gSpriteEntries[j].unk2 = gSpriteEntries[slot].unk2;
            gSpriteEntries[j].unk4 = gSpriteEntries[slot].unk4 + (s16)(gSpriteEntries[slot].unk2C - 5);
        }
    }
}
