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

    CpuSet(&zero, buf, 0x0500072E);
    REG_IME = ret;
    ie = REG_IE;
    REG_IE = 0x2020;
    REG_IME = 1;
    switch (mode) {
    case 0: {
        register u8 *p asm("r0") = (u8 *)&gUnk_03001784;
        *p |= 1;
    }
        serialize_save_data((struct SaveData *)buf);
        ret = write_save_to_eeprom((u16 *)0x02030000, 0);
        break;
    case 1:
        ret = validate_save_data((struct SaveData *)buf);
        load_save_data((struct SaveData *)buf);
        break;
    case 2:
        gUnk_03001784.unk0_0 = 0;
        for (i = 0; i < 16; i++)
            gDecompressBuffer[i] = gSaveMagicErased[i];
        ret = write_save_to_eeprom((u16 *)0x02030000, 0);
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
    u8 *p;
    u8 fe;
    register s32 r asm("r1");
    if ((r = is_sound_effect_playing(4)) != 0)
        return r;
    play_song(0);
    play_sound_effect(0);
    p = (u8 *)&gUnk_03002B70;
    fe = 0xFE;
    i = 15;
    p += 19;
    for (; i >= 0; i--)
        *p-- = fe;
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

    gUnk_03002B70 = save->unk10;
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
    gUnk_03001784.unk0_1 = (save->flags >> 5) & 1;
}

void serialize_save_data(struct SaveData *save) {
    s32 i;
    u16 sum;
    u8 *p;
    struct MedalData *medal;

    for (i = 0; i < 16; i++)
        save->magic[i] = gSaveMagic[i];
    save->unk10 = gUnk_03002B70;
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
        gOptionTimeLimit | (gOptionSkipMessages << 2) | (gOptionBattleMusic << 3) | (gUnk_03001784.unk0_1 << 5);
    save->checksum = 0;
    sum = 0;
    p = (u8 *)save;
    for (i = 0; i < sizeof(struct SaveData); i++)
        sum += *p++;
    save->checksum = sum;
}

s32 validate_save_data(struct SaveData *save) {
    u16 buf[4];
    u16 *p;
    s32 i;
    s32 n;
    u8 *b;
    u16 sum;
    u32 tmp; // the empty-name flag, then the stored checksum (one variable in the original)

    n = 920;
    p = (u16 *)save;
    for (i = 0; i < n; i++) {
        ReadEepromDword(i, buf);
        *p++ = buf[0];
        *p++ = buf[1];
        *p++ = buf[2];
        *p++ = buf[3];
    }
    for (i = 0; i < 16; i++) {
        if (gSaveMagic[i] != save->magic[i])
            return 1;
    }
    tmp = TRUE;
    for (i = 0; i < 16; i++) {
        if (save->unk10.unk4[i] == 0xFE)
            break;
        if (save->unk10.unk4[i] != 0) {
            tmp = FALSE;
            break;
        }
    }
    if (tmp)
        return -1;
    if (save->unk10.money > 99999)
        return -1;
    if (save->unk10.unk14[0] > 9999)
        return -1;
    if (save->unk10.unk14[0] < save->unk10.unk14[1])
        return -1;
    if (save->unk10.unk18 > 0x014996FF)
        return -1;
    if ((save->flags & 3) > 2)
        return -1;
    if (((save->flags >> 3) & 3) > 2)
        return -1;
    tmp = save->checksum;
    save->checksum = 0;
    sum = 0;
    b = (u8 *)save;
    for (i = 0; i < sizeof(struct SaveData); i++)
        sum += *b++;
    if (sum != tmp)
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
