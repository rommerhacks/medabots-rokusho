// Step handlers shared by many ability and Medaforce effect sequences (entries of several gUnk_083AD400
// sub-tables, no direct callers): show the battle message unkA6, wait for a timer (unk86) or a press of A,
// and sub_0803080C, the last step of most lists (sets unkB5 = sequence done).

#include "global.h"

void sub_080305E0(void) {
    if (sub_0801C0BC(gUnk_03001800.unkA6))
        gUnk_03001800.unkAA++;
}

void sub_08030608(void) {
    if (sub_0801C154())
        gUnk_03001800.unkAA++;
}

void sub_08030624(void) {
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1)) {
        clear_battle_sprite_slot(0xA, 1);
        gUnk_03001800.unkAA++;
    } else if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else {
        clear_battle_sprite_slot(0xA, 1);
        gUnk_03001800.unkAA++;
    }
}

void sub_08030674(void) {
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03001800.unkAA++;
    else if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else
        gUnk_03001800.unkAA++;
}

void sub_080306B8(void) {
    u32 i;

    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1)) {
        for (i = 0; i < 0x14; i++) {
            if (gUnk_03002C30[0xA + i].unk0 & 0x8000)
                clear_battle_sprite_slot(0xA + i, 1);
        }
        gUnk_03001800.unkAA++;
    }
    if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else {
        for (i = 0; i < 0x14; i++) {
            if (gUnk_03002C30[0xA + i].unk0 & 0x8000)
                clear_battle_sprite_slot(0xA + i, 1);
        }
        gUnk_03001800.unkAA++;
    }
}

void sub_08030780(void) {
    if (!(gUnk_03001800.unkF8 & 1))
        gUnk_03002C30[0x21].unk18 = (gUnk_03002C30[0x21].unk18 - 0x40) & 0x3FF;
    else
        gUnk_03002C30[0x21].unk18 = (gUnk_03002C30[0x21].unk18 + 0x40) & 0x3FF;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03001800.unkAA++;
    else if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else
        gUnk_03001800.unkAA++;
}

void sub_0803080C(void) {
    gUnk_03001800.unkB5 = 1;
}

void sub_0803081C(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03000440.unk84], 0x21);
    if (gUnk_03002C30[0x21].unk22 == 0xFF)
        gUnk_03001800.unkAA++;
}
