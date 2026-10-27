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
        if (gBattleBots[i].teamState) {
            battle_bot_status_sprite_update(i);
            battle_update_status_effect_sprite(i);
            update_battle_status_effect_sprite(i);
        }
    }
}

void battle_bot_status_sprite_update(u32 rec) {
    if (gBattleBots[rec].buffType == 0)
        return;
    if (gBattleBots[rec].buffType == 0x1F) {
        if (gSpriteEntries[rec * 3 + 0x46].unk0 && gSpriteEntries[rec * 3 + 0x46].unk23 == 0x1F)
            process_sprite_anim_commands(gUnk_083B5F80[15], rec * 3 + 0x46);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[15], rec * 3 + 0x46);
        memcpy_bytes_08041D04(gUnk_083C4C88[0], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 0, 0, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    } else if (gBattleBots[rec].buffType == 0x26 || gBattleBots[rec].buffType == 0x29) {
        if (gSpriteEntries[rec * 3 + 0x46].unk0 && gSpriteEntries[rec * 3 + 0x46].unk23 == gBattleBots[rec].buffType)
            process_sprite_anim_commands(gUnk_083B5F80[8], rec * 3 + 0x46);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[8], rec * 3 + 0x46);
        memcpy_bytes_08041D04(gUnk_083C4C88[1], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 0, 0, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    }
}

static void battle_update_status_effect_sprite(u32 rec) {
    if (gBattleBots[rec].statusType == 0)
        return;
    if ((u8)(gBattleBots[rec].statusType - 0xD) <= 1) {
        if (gSpriteEntries[rec * 3 + 0x47].unk0 != 0 &&
            gSpriteEntries[rec * 3 + 0x47].unk23 == gBattleBots[rec].statusType)
            process_sprite_anim_commands(gUnk_083B5F80[6], rec * 3 + 0x47);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[6], rec * 3 + 0x47);
        memcpy_bytes_08041D04(gUnk_083C4C60[0], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    } else if ((u8)(gBattleBots[rec].statusType - 0x11) <= 1 || gBattleBots[rec].statusType == 0x29) {
        if (gSpriteEntries[rec * 3 + 0x47].unk0 != 0 &&
            gSpriteEntries[rec * 3 + 0x47].unk23 == gBattleBots[rec].statusType)
            process_sprite_anim_commands(gUnk_083B5F80[8], rec * 3 + 0x47);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[8], rec * 3 + 0x47);
        memcpy_bytes_08041D04(gUnk_083C4C60[3], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    } else if ((u8)(gBattleBots[rec].statusType - 0x13) <= 1) {
        if (gSpriteEntries[rec * 3 + 0x47].unk0 != 0 &&
            gSpriteEntries[rec * 3 + 0x47].unk23 == gBattleBots[rec].statusType) {
            if (gBattleBots[rec].statusType == 0x13)
                process_sprite_anim_commands(gUnk_083B5F80[9], rec * 3 + 0x47);
            else
                process_sprite_anim_commands(gUnk_083B5F80[10], rec * 3 + 0x47);
        } else {
            if (gBattleBots[rec].statusType == 0x13)
                init_battle_sprite_entry_08040B90(gUnk_083B5F80[9], rec * 3 + 0x47);
            else
                init_battle_sprite_entry_08040B90(gUnk_083B5F80[10], rec * 3 + 0x47);
        }
        if (gBattleBots[rec].statusType == 0x13)
            memcpy_bytes_08041D04(gUnk_083C4C60[4], &gGameWork.partAbility, 4);
        else
            memcpy_bytes_08041D04(gUnk_083C4C60[5], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].unkB - 2);
    } else if ((u8)(gBattleBots[rec].statusType - 0xF) <= 1) {
        if (gSpriteEntries[rec * 3 + 0x47].unk0 != 0 &&
            gSpriteEntries[rec * 3 + 0x47].unk23 == gBattleBots[rec].statusType)
            process_sprite_anim_commands(gUnk_083B5F80[7], rec * 3 + 0x47);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[7], rec * 3 + 0x47);
        if (gBattleBots[rec].statusType == 0xF)
            memcpy_bytes_08041D04(gUnk_083C4C60[1], &gGameWork.partAbility, 4);
        else
            memcpy_bytes_08041D04(gUnk_083C4C60[2], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    } else if (gBattleBots[rec].statusType == 0x2B) {
        if (gSpriteEntries[rec * 3 + 0x47].unk0 != 0 && gSpriteEntries[rec * 3 + 0x47].unk23 == 0x2B)
            process_sprite_anim_commands(gUnk_083B5F80[16], rec * 3 + 0x47);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[16], rec * 3 + 0x47);
        memcpy_bytes_08041D04(gUnk_083C4C60[12], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    } else if (gBattleBots[rec].statusType == 0x2C) {
        if (gSpriteEntries[rec * 3 + 0x47].unk0 != 0 && gSpriteEntries[rec * 3 + 0x47].unk23 == 0x2C)
            process_sprite_anim_commands(gUnk_083B5F80[17], rec * 3 + 0x47);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[17], rec * 3 + 0x47);
        memcpy_bytes_08041D04(gUnk_083C4C60[13], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    } else if (gBattleBots[rec].statusType == 0x2E) {
        if (gSpriteEntries[rec * 3 + 0x47].unk0 != 0 && gSpriteEntries[rec * 3 + 0x47].unk23 == 0x2E)
            process_sprite_anim_commands(gUnk_083B5F80[18], rec * 3 + 0x47);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[18], rec * 3 + 0x47);
        memcpy_bytes_08041D04(gUnk_083C4C60[14], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    } else if (gBattleBots[rec].statusType == 0x2F) {
        if (gSpriteEntries[rec * 3 + 0x47].unk0 != 0 && gSpriteEntries[rec * 3 + 0x47].unk23 == 0x2F)
            process_sprite_anim_commands(gUnk_083B5F80[19], rec * 3 + 0x47);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[19], rec * 3 + 0x47);
        memcpy_bytes_08041D04(gUnk_083C4C60[15], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    }
}

static void update_battle_status_effect_sprite(u32 rec) {
    if (gBattleBots[rec].stateFlags & 8) {
        if (gBattleBots[rec].parts[gBattleBots[rec].lastAction - 1].unk11 == 0) {
            clear_sprite_table_mask(rec * 3 + 0x48, 1);
            return;
        }
        if (gSpriteEntries[rec * 3 + 0x48].unk0 != 0 &&
            gSpriteEntries[rec * 3 + 0x48].unk23 == gBattleBots[rec].lastActionSkill) {
            switch (gBattleBots[rec].lastActionSkill) {
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
            switch (gBattleBots[rec].lastActionSkill) {
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
        switch (gBattleBots[rec].lastActionSkill) {
        case 0x1B:
            memcpy_bytes_08041D04(gUnk_083C4C60[7], &gGameWork.partAbility, 4);
            break;
        case 0x1C:
            memcpy_bytes_08041D04(gUnk_083C4C60[8], &gGameWork.partAbility, 4);
            break;
        case 0x1D:
            memcpy_bytes_08041D04(gUnk_083C4C60[9], &gGameWork.partAbility, 4);
            break;
        default:
            memcpy_bytes_08041D04(gUnk_083C4C60[6], &gGameWork.partAbility, 4);
            break;
        }
        battle_setup_part_sprite(rec, 2, 2, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    } else if (gBattleBots[rec].stateFlags & 0x10) {
        if (gBattleBots[rec].parts[gBattleBots[rec].lastAction - 1].unk11 == 0) {
            clear_sprite_table_mask(rec * 3 + 0x48, 1);
            return;
        }
        if (gSpriteEntries[rec * 3 + 0x48].unk0 != 0 &&
            gSpriteEntries[rec * 3 + 0x48].unk23 == gBattleBots[rec].lastActionSkill)
            process_sprite_anim_commands(gUnk_083B5F80[20], rec * 3 + 0x48);
        else
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[20], rec * 3 + 0x48);
        memcpy_bytes_08041D04(gUnk_083C4C60[16], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 2, 2, gSpriteEntries[rec * 4 + 0x5D].unkB + 4);
    }
}

static void battle_setup_part_sprite(u32 rec, u32 slot, u32 kind, u32 attr) {
    u16 off;
    s16 v;
    s32 t;

    gSpriteEntries[rec * 3 + 0x46 + slot].unk0 = ((gBattleWork.battlefieldParams[3] + 2) << 10) | 0xC004;
    gSpriteEntries[rec * 3 + 0x46 + slot].unk1C = 0;
    gSpriteEntries[rec * 3 + 0x46 + slot].unkA = gGameWork.partSkillType + 0xB;
    gSpriteEntries[rec * 3 + 0x46 + slot].unkB = attr;
    gSpriteEntries[rec * 3 + 0x46 + slot].unk4 = gSpriteEntries[rec * 4 + 0x5D].unk4 + (s16)(gGameWork.partSkill - 4);
    gSpriteEntries[rec * 3 + 0x46 + slot].unk0 &= ~0x1000;
    switch (kind) {
    case 0:
        gSpriteEntries[rec * 3 + 0x46 + slot].unk23 = gBattleBots[rec].buffType;
        break;
    case 1:
        gSpriteEntries[rec * 3 + 0x46 + slot].unk23 = gBattleBots[rec].statusType;
        break;
    case 2:
        gSpriteEntries[rec * 3 + 0x46 + slot].unk23 = gBattleBots[rec].lastActionSkill;
        break;
    }
    off = v = gGameWork.partAbility;
    if (v & 0x80)
        off = v - 0x100;
    if (bot_sprite_is_flipped(rec)) {
        gSpriteEntries[rec * 3 + 0x46 + slot].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2 - off;
        if (gGameWork.partGender)
            gSpriteEntries[rec * 3 + 0x46 + slot].unk0 |= 0x1000;
    } else {
        gSpriteEntries[rec * 3 + 0x46 + slot].unk2 = gSpriteEntries[rec * 4 + 0x5D].unk2 + (t = (s16)off);
    }
}
