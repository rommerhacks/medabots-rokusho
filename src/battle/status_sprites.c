// Per-Medabot status sprites: update_all_battle_status_sprites and the status-effect sprite updates, and
// battle_setup_part_sprite. Called from battle/robattle and the battle action modules.

#include "global.h"

static void battle_update_status_effect_sprite(u32 rec);
static void update_battle_status_effect_sprite(u32 rec);
static void battle_setup_part_sprite(u32 rec, u32 slot, u32 kind, u32 attr);

void update_all_battle_status_sprites(void) {
    u32 i;

    clear_sprite_table_mask(0x46, 0x12);
    for (i = 0; i <= 5; i++) {
        if (gUnk_03000590[i].unk40) {
            battle_bot_status_sprite_update(i);
            battle_update_status_effect_sprite(i);
            update_battle_status_effect_sprite(i);
        }
    }
}

void battle_bot_status_sprite_update(u32 rec) {
    if (gUnk_03000590[rec].unkC4 == 0)
        return;
    if (gUnk_03000590[rec].unkC4 == 0x1F) {
        if (gSpriteEntries[rec * 3 + 0x46].unk0 && gSpriteEntries[rec * 3 + 0x46].unk23 == 0x1F)
            process_sprite_anim_commands(gUnk_083B5F80[15], rec * 3 + 0x46);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[15], rec * 3 + 0x46);
        memcpy_bytes_08041D04(gUnk_083C4C88[0], &gUnk_03000440.unkEE, 4);
        battle_setup_part_sprite(rec, 0, 0, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    } else if (gUnk_03000590[rec].unkC4 == 0x26 || gUnk_03000590[rec].unkC4 == 0x29) {
        if (gSpriteEntries[rec * 3 + 0x46].unk0 && gSpriteEntries[rec * 3 + 0x46].unk23 == gUnk_03000590[rec].unkC4)
            process_sprite_anim_commands(gUnk_083B5F80[8], rec * 3 + 0x46);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[8], rec * 3 + 0x46);
        memcpy_bytes_08041D04(gUnk_083C4C88[1], &gUnk_03000440.unkEE, 4);
        battle_setup_part_sprite(rec, 0, 0, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    }
}

static void battle_update_status_effect_sprite(u32 rec) {
    if (gUnk_03000590[rec].unkC9 == 0)
        return;
    if ((u8)(gUnk_03000590[rec].unkC9 - 0xD) <= 1) {
        if (gSpriteEntries[rec * 3 + 0x47].unk0 != 0 &&
            gSpriteEntries[rec * 3 + 0x47].unk23 == gUnk_03000590[rec].unkC9)
            process_sprite_anim_commands(gUnk_083B5F80[6], rec * 3 + 0x47);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[6], rec * 3 + 0x47);
        memcpy_bytes_08041D04(gUnk_083C4C60[0], &gUnk_03000440.unkEE, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    } else if ((u8)(gUnk_03000590[rec].unkC9 - 0x11) <= 1 || gUnk_03000590[rec].unkC9 == 0x29) {
        if (gSpriteEntries[rec * 3 + 0x47].unk0 != 0 &&
            gSpriteEntries[rec * 3 + 0x47].unk23 == gUnk_03000590[rec].unkC9)
            process_sprite_anim_commands(gUnk_083B5F80[8], rec * 3 + 0x47);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[8], rec * 3 + 0x47);
        memcpy_bytes_08041D04(gUnk_083C4C60[3], &gUnk_03000440.unkEE, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    } else if ((u8)(gUnk_03000590[rec].unkC9 - 0x13) <= 1) {
        if (gSpriteEntries[rec * 3 + 0x47].unk0 != 0 &&
            gSpriteEntries[rec * 3 + 0x47].unk23 == gUnk_03000590[rec].unkC9) {
            if (gUnk_03000590[rec].unkC9 == 0x13)
                process_sprite_anim_commands(gUnk_083B5F80[9], rec * 3 + 0x47);
            else
                process_sprite_anim_commands(gUnk_083B5F80[10], rec * 3 + 0x47);
        } else {
            if (gUnk_03000590[rec].unkC9 == 0x13)
                init_battle_sprite_entry_08040B90(gUnk_083B5F80[9], rec * 3 + 0x47);
            else
                init_battle_sprite_entry_08040B90(gUnk_083B5F80[10], rec * 3 + 0x47);
        }
        if (gUnk_03000590[rec].unkC9 == 0x13)
            memcpy_bytes_08041D04(gUnk_083C4C60[4], &gUnk_03000440.unkEE, 4);
        else
            memcpy_bytes_08041D04(gUnk_083C4C60[5], &gUnk_03000440.unkEE, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].unkB - 2);
    } else if ((u8)(gUnk_03000590[rec].unkC9 - 0xF) <= 1) {
        if (gSpriteEntries[rec * 3 + 0x47].unk0 != 0 &&
            gSpriteEntries[rec * 3 + 0x47].unk23 == gUnk_03000590[rec].unkC9)
            process_sprite_anim_commands(gUnk_083B5F80[7], rec * 3 + 0x47);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[7], rec * 3 + 0x47);
        if (gUnk_03000590[rec].unkC9 == 0xF)
            memcpy_bytes_08041D04(gUnk_083C4C60[1], &gUnk_03000440.unkEE, 4);
        else
            memcpy_bytes_08041D04(gUnk_083C4C60[2], &gUnk_03000440.unkEE, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    } else if (gUnk_03000590[rec].unkC9 == 0x2B) {
        if (gSpriteEntries[rec * 3 + 0x47].unk0 != 0 && gSpriteEntries[rec * 3 + 0x47].unk23 == 0x2B)
            process_sprite_anim_commands(gUnk_083B5F80[16], rec * 3 + 0x47);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[16], rec * 3 + 0x47);
        memcpy_bytes_08041D04(gUnk_083C4C60[12], &gUnk_03000440.unkEE, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    } else if (gUnk_03000590[rec].unkC9 == 0x2C) {
        if (gSpriteEntries[rec * 3 + 0x47].unk0 != 0 && gSpriteEntries[rec * 3 + 0x47].unk23 == 0x2C)
            process_sprite_anim_commands(gUnk_083B5F80[17], rec * 3 + 0x47);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[17], rec * 3 + 0x47);
        memcpy_bytes_08041D04(gUnk_083C4C60[13], &gUnk_03000440.unkEE, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    } else if (gUnk_03000590[rec].unkC9 == 0x2E) {
        if (gSpriteEntries[rec * 3 + 0x47].unk0 != 0 && gSpriteEntries[rec * 3 + 0x47].unk23 == 0x2E)
            process_sprite_anim_commands(gUnk_083B5F80[18], rec * 3 + 0x47);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[18], rec * 3 + 0x47);
        memcpy_bytes_08041D04(gUnk_083C4C60[14], &gUnk_03000440.unkEE, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    } else if (gUnk_03000590[rec].unkC9 == 0x2F) {
        if (gSpriteEntries[rec * 3 + 0x47].unk0 != 0 && gSpriteEntries[rec * 3 + 0x47].unk23 == 0x2F)
            process_sprite_anim_commands(gUnk_083B5F80[19], rec * 3 + 0x47);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[19], rec * 3 + 0x47);
        memcpy_bytes_08041D04(gUnk_083C4C60[15], &gUnk_03000440.unkEE, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    }
}

static void update_battle_status_effect_sprite(u32 rec) {
    if (gUnk_03000590[rec].unkBD & 8) {
        if (gUnk_03000590[rec].parts[gUnk_03000590[rec].unkDE - 1].unk11 == 0) {
            clear_sprite_table_mask(rec * 3 + 0x48, 1);
            return;
        }
        if (gSpriteEntries[rec * 3 + 0x48].unk0 != 0 &&
            gSpriteEntries[rec * 3 + 0x48].unk23 == gUnk_03000590[rec].unkDF) {
            switch (gUnk_03000590[rec].unkDF) {
            case 0x1B:
                process_sprite_anim_commands(gUnk_083B5F80[12], rec * 3 + 0x48);
                break;
            case 0x1C:
                process_sprite_anim_commands(gUnk_083B5F80[13], rec * 3 + 0x48);
                break;
            case 0x1D:
                process_sprite_anim_commands(gUnk_083B5F80[14], rec * 3 + 0x48);
                break;
            default:
                process_sprite_anim_commands(gUnk_083B5F80[11], rec * 3 + 0x48);
                break;
            }
        } else {
            switch (gUnk_03000590[rec].unkDF) {
            case 0x1B:
                init_battle_sprite_entry_08040B90(gUnk_083B5F80[12], rec * 3 + 0x48);
                break;
            case 0x1C:
                init_battle_sprite_entry_08040B90(gUnk_083B5F80[13], rec * 3 + 0x48);
                break;
            case 0x1D:
                init_battle_sprite_entry_08040B90(gUnk_083B5F80[14], rec * 3 + 0x48);
                break;
            default:
                init_battle_sprite_entry_08040B90(gUnk_083B5F80[11], rec * 3 + 0x48);
                break;
            }
        }
        switch (gUnk_03000590[rec].unkDF) {
        case 0x1B:
            memcpy_bytes_08041D04(gUnk_083C4C60[7], &gUnk_03000440.unkEE, 4);
            break;
        case 0x1C:
            memcpy_bytes_08041D04(gUnk_083C4C60[8], &gUnk_03000440.unkEE, 4);
            break;
        case 0x1D:
            memcpy_bytes_08041D04(gUnk_083C4C60[9], &gUnk_03000440.unkEE, 4);
            break;
        default:
            memcpy_bytes_08041D04(gUnk_083C4C60[6], &gUnk_03000440.unkEE, 4);
            break;
        }
        battle_setup_part_sprite(rec, 2, 2, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    } else if (gUnk_03000590[rec].unkBD & 0x10) {
        if (gUnk_03000590[rec].parts[gUnk_03000590[rec].unkDE - 1].unk11 == 0) {
            clear_sprite_table_mask(rec * 3 + 0x48, 1);
            return;
        }
        if (gSpriteEntries[rec * 3 + 0x48].unk0 != 0 &&
            gSpriteEntries[rec * 3 + 0x48].unk23 == gUnk_03000590[rec].unkDF)
            process_sprite_anim_commands(gUnk_083B5F80[20], rec * 3 + 0x48);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[20], rec * 3 + 0x48);
        memcpy_bytes_08041D04(gUnk_083C4C60[16], &gUnk_03000440.unkEE, 4);
        battle_setup_part_sprite(rec, 2, 2, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    }
}

static void battle_setup_part_sprite(u32 rec, u32 slot, u32 kind, u32 attr) {
    u16 off;
    s16 v;
    s32 t;

    gSpriteEntries[rec * 3 + 0x46 + slot].unk0 = ((gUnk_03001800.unk39[3] + 2) << 10) | 0xC004;
    gSpriteEntries[rec * 3 + 0x46 + slot].unk1C = 0;
    gSpriteEntries[rec * 3 + 0x46 + slot].unkA = gUnk_03000440.unkF0 + 0xB;
    gSpriteEntries[rec * 3 + 0x46 + slot].unkB = attr;
    gSpriteEntries[rec * 3 + 0x46 + slot].unk4 = gSpriteEntries[rec * 4 + 0x5D].unk4 + (s16)(gUnk_03000440.unkEF - 4);
    gSpriteEntries[rec * 3 + 0x46 + slot].unk0 &= ~0x1000;
    switch (kind) {
    case 0:
        gSpriteEntries[rec * 3 + 0x46 + slot].unk23 = gUnk_03000590[rec].unkC4;
        break;
    case 1:
        gSpriteEntries[rec * 3 + 0x46 + slot].unk23 = gUnk_03000590[rec].unkC9;
        break;
    case 2:
        gSpriteEntries[rec * 3 + 0x46 + slot].unk23 = gUnk_03000590[rec].unkDF;
        break;
    }
    off = v = gUnk_03000440.unkEE;
    if (v & 0x80)
        off = v - 0x100;
    if (bot_sprite_is_flipped(rec)) {
        gSpriteEntries[rec * 3 + 0x46 + slot].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2 - off;
        if (gUnk_03000440.unkF1)
            gSpriteEntries[rec * 3 + 0x46 + slot].unk0 |= 0x1000;
    } else {
        gSpriteEntries[rec * 3 + 0x46 + slot].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2 + (t = (s16)off);
    }
}
