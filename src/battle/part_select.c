// Robattle part select (after choosing Attack on the command ring): the head / arms / legs icons around the
// centre, cursor input and blinking, the part's name, skill type and skill name, the head's uses left.
// Called from battle/robattle.

#include "global.h"

void part_select_init_center_icon(void) {
    gUnk_03002C30[0].unk0 = 0xC404;
    gUnk_03002C30[0].unk1C = 0;
    gUnk_03002C30[0].unk2 = 0x78;
    gUnk_03002C30[0].unk4 = 0x78;
    gUnk_03002C30[0].unkA = 0xA;
    gUnk_03002C30[0].unkB = 0xC0;
    gUnk_03002C30[0].unk6 = gUnk_083AD3A0[gUnk_03001800.unk82] + 0x600;
}

void part_select_init_head_icon(u32 a) {
    gUnk_03002C30[1].unk0 = 0xC404;
    gUnk_03002C30[1].unk1C = 0;
    gUnk_03002C30[1].unk2 = 0x78;
    gUnk_03002C30[1].unk4 = 0x6C;
    gUnk_03002C30[1].unkA = 0xA;
    gUnk_03002C30[1].unkB = 0xC0;
    gUnk_03002C30[1].unk6 = a * 4 + 0x604;
}

void part_select_init_right_arm_icon(u32 a) {
    gUnk_03002C30[2].unk0 = 0xC404;
    gUnk_03002C30[2].unk1C = 0;
    gUnk_03002C30[2].unk2 = 0x6C;
    gUnk_03002C30[2].unk4 = 0x78;
    gUnk_03002C30[2].unkA = 0xA;
    gUnk_03002C30[2].unkB = 0xC0;
    gUnk_03002C30[2].unk6 = a * 4 + 0x605;
}

void part_select_init_left_arm_icon(u32 a) {
    gUnk_03002C30[3].unk0 = 0xC404;
    gUnk_03002C30[3].unk1C = 0;
    gUnk_03002C30[3].unk2 = 0x84;
    gUnk_03002C30[3].unk4 = 0x78;
    gUnk_03002C30[3].unkA = 0xA;
    gUnk_03002C30[3].unkB = 0xC0;
    gUnk_03002C30[3].unk6 = a * 4 + 0x606;
}

void part_select_init_bottom_icon(u32 a) {
    gUnk_03002C30[4].unk0 = 0xC404;
    gUnk_03002C30[4].unk1C = 0;
    gUnk_03002C30[4].unk2 = 0x78;
    gUnk_03002C30[4].unk4 = 0x84;
    gUnk_03002C30[4].unkA = 0xA;
    gUnk_03002C30[4].unkB = 0xC0;
    gUnk_03002C30[4].unk6 = a * 4 + 0x607;
}

void part_select_blink_selected_icon(void) {
    switch (gUnk_03001800.unk82) {
    case 0:
        if (gUnk_03000440.unk84 & 8)
            part_select_init_bottom_icon(1);
        else
            part_select_init_bottom_icon(0);
        break;
    case 1:
        if (gUnk_03000440.unk84 & 8)
            part_select_init_head_icon(1);
        else
            part_select_init_head_icon(0);
        break;
    case 2:
        if (gUnk_03000440.unk84 & 8)
            part_select_init_right_arm_icon(1);
        else
            part_select_init_right_arm_icon(0);
        break;
    case 3:
        if (gUnk_03000440.unk84 & 8)
            part_select_init_left_arm_icon(1);
        else
            part_select_init_left_arm_icon(0);
        break;
    }
}

// Robattle sub-state 0x12, Medapart select (runtime-checked from battle_start.ss0): UP head (1),
// LEFT right arm (2), RIGHT left arm (3), DOWN none (0) in gUnk_03001800.unk82.
void part_select_input(void) {
    u8 old = gUnk_03001800.unk82;

    if (KEYS_LO(gNewKeys) & 0x40)
        gUnk_03001800.unk82 = 1;
    if (KEYS_LO(gNewKeys) & 0x80)
        gUnk_03001800.unk82 = 0;
    if (KEYS_LO(gNewKeys) & 0x20)
        gUnk_03001800.unk82 = 2;
    if (KEYS_LO(gNewKeys) & 0x10)
        gUnk_03001800.unk82 = 3;
    if (gUnk_03001800.unk82 != old) {
        play_sound_effect(2);
        part_select_init_center_icon();
        part_select_init_head_icon(1);
        part_select_init_right_arm_icon(1);
        part_select_init_left_arm_icon(1);
        part_select_init_bottom_icon(1);
        part_select_draw_part_name();
        part_select_draw_skill_type();
        part_select_draw_skill_name();
        part_select_draw_head_uses();
        sub_0801BACC();
        sub_0801B894();
    }
}

void part_select_draw_part_name(void) {
    s32 k;

    clear_sprite_table_mask(0x1F, 14);
    k = gUnk_03001800.unk82;
    if (k == 0)
        memcpy_bytes_08041D04(gUnk_083C4A10[3], gUnk_03000440.unk9E, 14);
    else if (k >= 0) {
        if (k <= 3)
            memcpy_bytes_08041D04(
                (const void *)gUnk_083BB9CC[0][gUnk_03000590[gUnk_03001800.unk80].parts[k - 1].unk17 * 4 + k - 1],
                gUnk_03000440.unk9E, 15);
    }
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x1F, 10, 0x11, 10, 13, 0, 0);
}

void part_select_draw_skill_type(void) {
    s32 k;

    clear_sprite_table_mask(0x2D, 13);
    k = gUnk_03001800.unk82;
    if (k == 0)
        fill_text_blank(gUnk_03000440.unk9E, 13);
    else if (k >= 0) {
        if (k <= 3) {
            if (gUnk_03000590[gUnk_03001800.unk80].parts[k - 1].unk11 == 0)
                memcpy_bytes_08041D04(gUnk_083C4A10[0], gUnk_03000440.unk9E, 14);
            else if (gUnk_03000590[gUnk_03001800.unk80].unkC9 == 0x2B && k == gUnk_03000590[gUnk_03001800.unk80].unkCA)
                memcpy_bytes_08041D04(gUnk_083C4A10[1], gUnk_03000440.unk9E, 14);
            else if (part_skill_is_passive(gUnk_03001800.unk80, gUnk_03001800.unk82 - 1))
                memcpy_bytes_08041D04(gUnk_083C4A10[1], gUnk_03000440.unk9E, 14);
            else if (gUnk_03001800.unk82 == 1 && gUnk_03000590[gUnk_03001800.unk80].parts[0].unk10 == 0)
                memcpy_bytes_08041D04(gUnk_083C4A10[2], gUnk_03000440.unk9E, 14);
            else
                memcpy_bytes_08041D04(
                    (const void *)
                        gUnk_083B6EC8[gUnk_03000590[gUnk_03001800.unk80].parts[gUnk_03001800.unk82 - 1].data[2]],
                    gUnk_03000440.unk9E, 14);
        }
    }
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x2D, 0x13, 0xE, 10, 14, 0, 0);
}

void part_select_blink_status(void) {
    u32 show = 0;
    s32 k = gUnk_03001800.unk82;

    if (k == 0)
        ;
    else if (k >= 0) {
        if (k <= 3) {
            if (gUnk_03000590[gUnk_03001800.unk80].parts[k - 1].unk11 == 0) {
                memcpy_bytes_08041D04(gUnk_083C4A10[0], gUnk_03000440.unk9E, 14);
                show = 1;
            } else if (gUnk_03000590[gUnk_03001800.unk80].unkC9 == 0x2B &&
                       k == gUnk_03000590[gUnk_03001800.unk80].unkCA) {
                memcpy_bytes_08041D04(gUnk_083C4A10[1], gUnk_03000440.unk9E, 14);
                show = 1;
            } else if (part_skill_is_passive(gUnk_03001800.unk80, gUnk_03001800.unk82 - 1)) {
                memcpy_bytes_08041D04(gUnk_083C4A10[1], gUnk_03000440.unk9E, 14);
                show = 1;
            } else if (gUnk_03001800.unk82 == 1 && gUnk_03000590[gUnk_03001800.unk80].parts[0].unk10 == 0) {
                memcpy_bytes_08041D04(gUnk_083C4A10[2], gUnk_03000440.unk9E, 14);
                show = 1;
            }
        }
    }
    if (show) {
        if (gUnk_03000440.unk84 & 8)
            clear_sprite_table_mask(0x2D, 13);
        else
            render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x2D, 0x13, 0xE, 10, 14, 0, 0);
    }
}

void part_select_draw_skill_name(void) {
    s32 k;

    clear_sprite_table_mask(0x14, 11);
    k = gUnk_03001800.unk82;
    if (k == 0)
        fill_text_blank(gUnk_03000440.unk9E, 10);
    else if (k >= 0) {
        if (k <= 3)
            memcpy_bytes_08041D04((const void *)gUnk_083BE6E8[gUnk_03000590[gUnk_03001800.unk80].parts[k - 1].data[1]],
                                  gUnk_03000440.unk9E, 12);
    }
    render_text_sprites_08040DB8(gUnk_03000440.unk9E, 0x14, 0x15, 0x11, 8, 14, 0, 0);
}

void part_select_init_cursor(void) {
    u8 v = gUnk_03000590[gUnk_03001800.unk80].unkDD;
    if (v > 3)
        v = 0;
    gUnk_03001800.unk82 = v;
}

void part_select_draw_head_uses(void) {
    if (gUnk_03001800.unk82 == 1) {
        draw_tile_block(2, 1, 0xE, 0xC, REG_BG0CNT, 0xD218);
        draw_count_over_max(gUnk_03000590[gUnk_03001800.unk80].parts[0].unk10,
                            gUnk_03000590[gUnk_03001800.unk80].parts[0].data[8], 0x10, 0xC, 0xD21A, REG_BG0CNT, 0xD220);
    } else
        vram_fill_tilemap_rect(7, 1, 0xE, 0xC, REG_BG0CNT, 0);
}

// Skills that work on their own and cannot be chosen as an action (Cancel Optic/Bomb/Grav, Accel Chrg,
// Strengthen: names from the skill name table); part select shows them with the "sealed" text.
u32 part_skill_is_passive(u32 rec, u32 part) {
    switch (gUnk_03000590[rec].parts[part].data[1]) {
    case 0x18:
    case 0x19:
    case 0x1A:
    case 0x28:
    case 0x35:
        return 1;
    default:
        return 0;
    }
}
