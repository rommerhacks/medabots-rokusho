// Per-Medabot status sprites: update_all_battle_status_sprites and the status-effect sprite updates, and
// battle_setup_part_sprite. Called from battle/robattle and the battle action modules.

#include "global.h"
#include "constants/skill_sprites.h"
#include "constants/sprites.h"

static void battle_update_status_effect_sprite(u32 rec);
static void update_battle_status_effect_sprite(u32 rec);
static void battle_setup_part_sprite(u32 rec, u32 slot, u32 kind, u32 attr);

void update_all_battle_status_sprites(void) {
    u32 i;

    disable_sprites(0x46, 0x12);
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
        if (gSpriteEntries[rec * 3 + 0x46].flags && gSpriteEntries[rec * 3 + 0x46].work[STATUS_SPR_ID] == 0x1F)
            process_sprite_anim_commands(gBattleSpriteAnimScripts[15], rec * 3 + 0x46);
        else
            battle_sprite_anim_init(gBattleSpriteAnimScripts[15], rec * 3 + 0x46);
        memcpy_bytes_08041D04(gBuffSpriteParams[0], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 0, 0, gSpriteEntries[rec * 4 + 0x5D].order + 4);
    } else if (gBattleBots[rec].buffType == 0x26 || gBattleBots[rec].buffType == 0x29) {
        if (gSpriteEntries[rec * 3 + 0x46].flags &&
            gSpriteEntries[rec * 3 + 0x46].work[STATUS_SPR_ID] == gBattleBots[rec].buffType)
            process_sprite_anim_commands(gBattleSpriteAnimScripts[8], rec * 3 + 0x46);
        else
            battle_sprite_anim_init(gBattleSpriteAnimScripts[8], rec * 3 + 0x46);
        memcpy_bytes_08041D04(gBuffSpriteParams[1], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 0, 0, gSpriteEntries[rec * 4 + 0x5D].order + 4);
    }
}

static void battle_update_status_effect_sprite(u32 rec) {
    if (gBattleBots[rec].statusType == 0)
        return;
    if ((u8)(gBattleBots[rec].statusType - 0xD) <= 1) {
        if (gSpriteEntries[rec * 3 + 0x47].flags != 0 &&
            gSpriteEntries[rec * 3 + 0x47].work[STATUS_SPR_ID] == gBattleBots[rec].statusType)
            process_sprite_anim_commands(gBattleSpriteAnimScripts[6], rec * 3 + 0x47);
        else
            battle_sprite_anim_init(gBattleSpriteAnimScripts[6], rec * 3 + 0x47);
        memcpy_bytes_08041D04(gStatusSpriteParams[0], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].order + 4);
    } else if ((u8)(gBattleBots[rec].statusType - 0x11) <= 1 || gBattleBots[rec].statusType == 0x29) {
        if (gSpriteEntries[rec * 3 + 0x47].flags != 0 &&
            gSpriteEntries[rec * 3 + 0x47].work[STATUS_SPR_ID] == gBattleBots[rec].statusType)
            process_sprite_anim_commands(gBattleSpriteAnimScripts[8], rec * 3 + 0x47);
        else
            battle_sprite_anim_init(gBattleSpriteAnimScripts[8], rec * 3 + 0x47);
        memcpy_bytes_08041D04(gStatusSpriteParams[3], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].order + 4);
    } else if ((u8)(gBattleBots[rec].statusType - 0x13) <= 1) {
        if (gSpriteEntries[rec * 3 + 0x47].flags != 0 &&
            gSpriteEntries[rec * 3 + 0x47].work[STATUS_SPR_ID] == gBattleBots[rec].statusType) {
            if (gBattleBots[rec].statusType == 0x13)
                process_sprite_anim_commands(gBattleSpriteAnimScripts[9], rec * 3 + 0x47);
            else
                process_sprite_anim_commands(gBattleSpriteAnimScripts[10], rec * 3 + 0x47);
        } else {
            if (gBattleBots[rec].statusType == 0x13)
                battle_sprite_anim_init(gBattleSpriteAnimScripts[9], rec * 3 + 0x47);
            else
                battle_sprite_anim_init(gBattleSpriteAnimScripts[10], rec * 3 + 0x47);
        }
        if (gBattleBots[rec].statusType == 0x13)
            memcpy_bytes_08041D04(gStatusSpriteParams[4], &gGameWork.partAbility, 4);
        else
            memcpy_bytes_08041D04(gStatusSpriteParams[5], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].order - 2);
    } else if ((u8)(gBattleBots[rec].statusType - 0xF) <= 1) {
        if (gSpriteEntries[rec * 3 + 0x47].flags != 0 &&
            gSpriteEntries[rec * 3 + 0x47].work[STATUS_SPR_ID] == gBattleBots[rec].statusType)
            process_sprite_anim_commands(gBattleSpriteAnimScripts[7], rec * 3 + 0x47);
        else
            battle_sprite_anim_init(gBattleSpriteAnimScripts[7], rec * 3 + 0x47);
        if (gBattleBots[rec].statusType == 0xF)
            memcpy_bytes_08041D04(gStatusSpriteParams[1], &gGameWork.partAbility, 4);
        else
            memcpy_bytes_08041D04(gStatusSpriteParams[2], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].order + 4);
    } else if (gBattleBots[rec].statusType == 0x2B) {
        if (gSpriteEntries[rec * 3 + 0x47].flags != 0 && gSpriteEntries[rec * 3 + 0x47].work[STATUS_SPR_ID] == 0x2B)
            process_sprite_anim_commands(gBattleSpriteAnimScripts[16], rec * 3 + 0x47);
        else
            battle_sprite_anim_init(gBattleSpriteAnimScripts[16], rec * 3 + 0x47);
        memcpy_bytes_08041D04(gStatusSpriteParams[12], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].order + 4);
    } else if (gBattleBots[rec].statusType == 0x2C) {
        if (gSpriteEntries[rec * 3 + 0x47].flags != 0 && gSpriteEntries[rec * 3 + 0x47].work[STATUS_SPR_ID] == 0x2C)
            process_sprite_anim_commands(gBattleSpriteAnimScripts[17], rec * 3 + 0x47);
        else
            battle_sprite_anim_init(gBattleSpriteAnimScripts[17], rec * 3 + 0x47);
        memcpy_bytes_08041D04(gStatusSpriteParams[13], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].order + 4);
    } else if (gBattleBots[rec].statusType == 0x2E) {
        if (gSpriteEntries[rec * 3 + 0x47].flags != 0 && gSpriteEntries[rec * 3 + 0x47].work[STATUS_SPR_ID] == 0x2E)
            process_sprite_anim_commands(gBattleSpriteAnimScripts[18], rec * 3 + 0x47);
        else
            battle_sprite_anim_init(gBattleSpriteAnimScripts[18], rec * 3 + 0x47);
        memcpy_bytes_08041D04(gStatusSpriteParams[14], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].order + 4);
    } else if (gBattleBots[rec].statusType == 0x2F) {
        if (gSpriteEntries[rec * 3 + 0x47].flags != 0 && gSpriteEntries[rec * 3 + 0x47].work[STATUS_SPR_ID] == 0x2F)
            process_sprite_anim_commands(gBattleSpriteAnimScripts[19], rec * 3 + 0x47);
        else
            battle_sprite_anim_init(gBattleSpriteAnimScripts[19], rec * 3 + 0x47);
        memcpy_bytes_08041D04(gStatusSpriteParams[15], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 1, 1, gSpriteEntries[rec * 4 + 0x5D].order + 4);
    }
}

static void update_battle_status_effect_sprite(u32 rec) {
    if (gBattleBots[rec].stateFlags & 8) {
        if (gBattleBots[rec].parts[gBattleBots[rec].lastAction - 1].armor == 0) {
            disable_sprites(rec * 3 + 0x48, 1);
            return;
        }
        if (gSpriteEntries[rec * 3 + 0x48].flags != 0 &&
            gSpriteEntries[rec * 3 + 0x48].work[STATUS_SPR_ID] == gBattleBots[rec].lastActionSkill) {
            switch (gBattleBots[rec].lastActionSkill) {
            case 0x1B:
                process_sprite_anim_commands(gBattleSpriteAnimScripts[12], rec * 3 + 0x48);
                break;
            case 0x1C:
                process_sprite_anim_commands(gBattleSpriteAnimScripts[13], rec * 3 + 0x48);
                break;
            case 0x1D:
                process_sprite_anim_commands(gBattleSpriteAnimScripts[14], rec * 3 + 0x48);
                break;
            default:
                process_sprite_anim_commands(gBattleSpriteAnimScripts[11], rec * 3 + 0x48);
                break;
            }
        } else {
            switch (gBattleBots[rec].lastActionSkill) {
            case 0x1B:
                battle_sprite_anim_init(gBattleSpriteAnimScripts[12], rec * 3 + 0x48);
                break;
            case 0x1C:
                battle_sprite_anim_init(gBattleSpriteAnimScripts[13], rec * 3 + 0x48);
                break;
            case 0x1D:
                battle_sprite_anim_init(gBattleSpriteAnimScripts[14], rec * 3 + 0x48);
                break;
            default:
                battle_sprite_anim_init(gBattleSpriteAnimScripts[11], rec * 3 + 0x48);
                break;
            }
        }
        switch (gBattleBots[rec].lastActionSkill) {
        case 0x1B:
            memcpy_bytes_08041D04(gStatusSpriteParams[7], &gGameWork.partAbility, 4);
            break;
        case 0x1C:
            memcpy_bytes_08041D04(gStatusSpriteParams[8], &gGameWork.partAbility, 4);
            break;
        case 0x1D:
            memcpy_bytes_08041D04(gStatusSpriteParams[9], &gGameWork.partAbility, 4);
            break;
        default:
            memcpy_bytes_08041D04(gStatusSpriteParams[6], &gGameWork.partAbility, 4);
            break;
        }
        battle_setup_part_sprite(rec, 2, 2, gSpriteEntries[rec * 4 + 0x5D].order + 4);
    } else if (gBattleBots[rec].stateFlags & 0x10) {
        if (gBattleBots[rec].parts[gBattleBots[rec].lastAction - 1].armor == 0) {
            disable_sprites(rec * 3 + 0x48, 1);
            return;
        }
        if (gSpriteEntries[rec * 3 + 0x48].flags != 0 &&
            gSpriteEntries[rec * 3 + 0x48].work[STATUS_SPR_ID] == gBattleBots[rec].lastActionSkill)
            process_sprite_anim_commands(gBattleSpriteAnimScripts[20], rec * 3 + 0x48);
        else
            battle_sprite_anim_init(gBattleSpriteAnimScripts[20], rec * 3 + 0x48);
        memcpy_bytes_08041D04(gStatusSpriteParams[16], &gGameWork.partAbility, 4);
        battle_setup_part_sprite(rec, 2, 2, gSpriteEntries[rec * 4 + 0x5D].order + 4);
    }
}

static void battle_setup_part_sprite(u32 rec, u32 slot, u32 kind, u32 attr) {
    u16 off;
    s16 raw_off;
    s32 signed_off; // FAKEMATCH: assigned inside the x expression to force the s16 sign-extension

    gSpriteEntries[rec * 3 + 0x46 + slot].flags = SPRITE_PRIORITY(gBattleWork.battlefieldParams[3] + 2) |
                                                  SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_FLAG_PART_PALETTE;
    gSpriteEntries[rec * 3 + 0x46 + slot].frame_table = 0;
    gSpriteEntries[rec * 3 + 0x46 + slot].palette = gGameWork.partSkillType + 0xB;
    gSpriteEntries[rec * 3 + 0x46 + slot].order = attr;
    gSpriteEntries[rec * 3 + 0x46 + slot].y = gSpriteEntries[rec * 4 + 0x5D].y + (s16)(gGameWork.partSkill - 4);
    gSpriteEntries[rec * 3 + 0x46 + slot].flags &= ~SPRITE_FLAG_HFLIP;
    switch (kind) {
    case 0:
        gSpriteEntries[rec * 3 + 0x46 + slot].work[STATUS_SPR_ID] = gBattleBots[rec].buffType;
        break;
    case 1:
        gSpriteEntries[rec * 3 + 0x46 + slot].work[STATUS_SPR_ID] = gBattleBots[rec].statusType;
        break;
    case 2:
        gSpriteEntries[rec * 3 + 0x46 + slot].work[STATUS_SPR_ID] = gBattleBots[rec].lastActionSkill;
        break;
    }
    off = raw_off = gGameWork.partAbility;
    if (raw_off & 0x80)
        off = raw_off - 0x100;
    if (bot_sprite_is_flipped(rec)) {
        gSpriteEntries[rec * 3 + 0x46 + slot].x = gSpriteEntries[rec * 4 + 0x5D].x - off;
        if (gGameWork.partGender)
            gSpriteEntries[rec * 3 + 0x46 + slot].flags |= SPRITE_FLAG_HFLIP;
    } else {
        gSpriteEntries[rec * 3 + 0x46 + slot].x = gSpriteEntries[rec * 4 + 0x5D].x + (signed_off = (s16)off);
    }
}
