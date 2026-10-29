// Battery save on EEPROM: save_dispatch (load / save with the timer IRQ from eeprom_setup_timer_irq),
// load_save_with_retries, and the (de)serialisation and validation of the game's save block. Called by the
// title menu, the save screen and the link scenes.
#include "global.h"

static s32 write_save_to_eeprom(u16 *src, u32 force);

s32 save_dispatch(s32 mode) {
    s32 ret = 0;
    u32 zero = ret;
    u8 *buf = gDecompressBuffer;
    u16 ie;
    s32 i;

    CpuSet(&zero, buf, CPU_SET_SRC_FIXED | CPU_SET_32BIT | 0x72E);
    REG_IME = ret;
    ie = REG_IE;
    REG_IE = 0x2020;
    REG_IME = 1;
    switch (mode) {
    case 0: {
        // FAKEMATCH: pins the gSaveStatus pointer to r0
        register u8 *status_ptr asm("r0") = (u8 *)&gSaveStatus;
        *status_ptr |= 1;
    }
        serialize_save_data((struct SaveData *)buf);
        ret = write_save_to_eeprom((u16 *)DECOMPRESS_BUFFER_ADDR, 0);
        break;
    case 1:
        ret = validate_save_data((struct SaveData *)buf);
        load_save_data((struct SaveData *)buf);
        break;
    case 2:
        gSaveStatus.saveExists = 0;
        for (i = 0; i < 16; i++)
            gDecompressBuffer[i] = gSaveMagicErased[i];
        ret = write_save_to_eeprom((u16 *)DECOMPRESS_BUFFER_ADDR, 0);
        break;
    }
    REG_IE |= ie;
    return ret;
}

u16 eeprom_setup_timer_irq(void) {
    return sub_0807C7A8(2, &gIntrTable[11]);
}

s32 load_save_with_retries(void) {
    s32 i, ret;
    u8 *name_ptr;
    u8 fe;
    // FAKEMATCH: pins the sound-busy result to r1
    register s32 sfx_busy asm("r1");
    if ((sfx_busy = is_sound_effect_playing(4)) != 0)
        return sfx_busy;
    play_song(0);
    play_sound_effect(0);
    name_ptr = (u8 *)&gPlayerRecord;
    fe = 0xFE;
    i = 15;
    name_ptr += 19;
    for (; i >= 0; i--)
        *name_ptr-- = fe;
    for (i = 0; i <= 3; i++) {
        ret = save_dispatch(1);
        if (ret == 0)
            break;
    }
    return ret;
}

void load_save_data(struct SaveData *save) {
    s32 i;
    struct MedalData *medal;

    gPlayerRecord = save->player;
    medal = save->medals;
    for (i = 0; i < 30; i++) {
        memcpy_optimized(&gMedals[i], medal, sizeof(struct MedalData));
        medal++;
    }
    for (i = 0; i < 0x3C0; i++)
        gMedapartInventory[i] = save->medaparts[i];
    for (i = 0; i < 9; i++)
        gTeamSlots[i] = save->team[i];
    CpuSet(save->items, gItemInventory, 0x40);
    CpuSet(save->field, &gFieldWork, 0x660);
    gOptionTimeLimit = save->flags & 3;
    gOptionSkipMessages = (save->flags >> 2) & 1;
    gOptionBattleMusic = (save->flags >> 3) & 3;
    gSaveStatus.linkIntroSeen = (save->flags >> 5) & 1;
}

void serialize_save_data(struct SaveData *save) {
    s32 i;
    u16 sum;
    u8 *bytes;
    struct MedalData *medal;

    for (i = 0; i < 16; i++)
        save->magic[i] = gSaveMagic[i];
    save->player = gPlayerRecord;
    medal = save->medals;
    for (i = 0; i < 30; i++) {
        memcpy_optimized(medal, &gMedals[i], sizeof(struct MedalData));
        medal++;
    }
    for (i = 0; i < 0x3C0; i++)
        save->medaparts[i] = gMedapartInventory[i];
    for (i = 0; i < 9; i++)
        save->team[i] = gTeamSlots[i];
    CpuSet(gItemInventory, save->items, 0x40);
    CpuSet(&gFieldWork, save->field, 0x660);
    save->flags =
        gOptionTimeLimit | (gOptionSkipMessages << 2) | (gOptionBattleMusic << 3) | (gSaveStatus.linkIntroSeen << 5);
    save->checksum = 0;
    sum = 0;
    bytes = (u8 *)save;
    for (i = 0; i < sizeof(struct SaveData); i++)
        sum += *bytes++;
    save->checksum = sum;
}

s32 validate_save_data(struct SaveData *save) {
    u16 buf[4];
    u16 *dst;
    s32 i;
    s32 n;
    u8 *bytes;
    u16 sum;
    u32 check_value; // the empty-name flag, then the stored checksum (one variable in the original)

    n = 920;
    dst = (u16 *)save;
    for (i = 0; i < n; i++) {
        ReadEepromDword(i, buf);
        *dst++ = buf[0];
        *dst++ = buf[1];
        *dst++ = buf[2];
        *dst++ = buf[3];
    }
    for (i = 0; i < 16; i++) {
        if (gSaveMagic[i] != save->magic[i])
            return 1;
    }
    check_value = TRUE;
    for (i = 0; i < 16; i++) {
        if (save->player.name[i] == 0xFE)
            break;
        if (save->player.name[i] != 0) {
            check_value = FALSE;
            break;
        }
    }
    if (check_value)
        return -1;
    if (save->player.money > 99999)
        return -1;
    if (save->player.robattleCounts[0] > 9999)
        return -1;
    if (save->player.robattleCounts[0] < save->player.robattleCounts[1])
        return -1;
    if (save->player.playTime > 0x014996FF)
        return -1;
    if ((save->flags & 3) > 2)
        return -1;
    if (((save->flags >> 3) & 3) > 2)
        return -1;
    check_value = save->checksum;
    save->checksum = 0;
    sum = 0;
    bytes = (u8 *)save;
    for (i = 0; i < sizeof(struct SaveData); i++)
        sum += *bytes++;
    if (sum != check_value)
        return -1;
    return 0;
}

static s32 write_save_to_eeprom(u16 *src, u32 force) {
    u16 buf[4];
    s32 i;
    s32 n;
    u16 changed;
    u32 j;

    n = 920;
    if ((u8)force) {
        for (i = 0; i < n; i++) {
            buf[0] = *src++;
            buf[1] = *src++;
            buf[2] = *src++;
            buf[3] = *src++;
            ProgramEepromDwordEx(i, buf);
        }
    } else {
        for (i = 0; i < n; i++) {
            changed = ReadEepromDword(i, buf);
            for (j = 0; j < 4; j++) {
                if (buf[j] != *src) {
                    buf[j] = *src;
                    changed = 1;
                }
                src++;
            }
            if (changed)
                ProgramEepromDwordEx(i, buf);
        }
    }
    return 0;
}
