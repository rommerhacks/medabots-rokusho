// Step handlers shared by many ability and Medaforce effect sequences (entries of several step sub-tables, no
// direct callers): show the battle message unkA6, the "MISS!!" popup, wait for a timer (gUnk_03000440.unk86) or a
// press of A, play an animation on sprite 0x21, and effect_step_end, the last step of most lists (unkB5 = done).

#include "global.h"

void effect_step_show_message(void) {
    if (battle_message_show(gUnk_03001800.unkA6))
        gUnk_03001800.unkAA++;
}

void effect_step_miss_popup(void) {
    if (miss_popup_run())
        gUnk_03001800.unkAA++;
}

void effect_step_wait_clear_sprite(void) {
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

void effect_step_wait(void) {
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03001800.unkAA++;
    else if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else
        gUnk_03001800.unkAA++;
}

void effect_step_wait_clear_sprites(void) {
    u32 i;

    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1)) {
        for (i = 0; i < 0x14; i++) {
            if (gSpriteEntries[0xA + i].unk0 & 0x8000)
                clear_battle_sprite_slot(0xA + i, 1);
        }
        gUnk_03001800.unkAA++;
    }
    if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else {
        for (i = 0; i < 0x14; i++) {
            if (gSpriteEntries[0xA + i].unk0 & 0x8000)
                clear_battle_sprite_slot(0xA + i, 1);
        }
        gUnk_03001800.unkAA++;
    }
}

void effect_step_wait_spin(void) {
    if (!(gUnk_03001800.unkF8 & 1))
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 - 0x40) & 0x3FF;
    else
        gSpriteEntries[0x21].unk18 = (gSpriteEntries[0x21].unk18 + 0x40) & 0x3FF;
    if (gUnk_03000440.unk89 == 0 && (*(u8 *)&gRepeatKeys & 1))
        gUnk_03001800.unkAA++;
    else if (gUnk_03000440.unk86)
        gUnk_03000440.unk86--;
    else
        gUnk_03001800.unkAA++;
}

void effect_step_end(void) {
    gUnk_03001800.unkB5 = 1;
}

void effect_step_play_anim(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gUnk_03000440.unk84], 0x21);
    if (gSpriteEntries[0x21].unk22 == 0xFF)
        gUnk_03001800.unkAA++;
}
