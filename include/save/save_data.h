#ifndef GUARD_SAVE_SAVE_DATA_H
#define GUARD_SAVE_SAVE_DATA_H

// EEPROM save: save_dispatch, load / serialize / validate / write

u16 eeprom_setup_timer_irq(void);
s32 load_save_with_retries(
    void); // title: stops the music, clears the name, tries save_dispatch(1) 4 times; nonzero while sound 4 plays
s32 save_dispatch(s32 mode); // 0: save, 1: load (returns validate_save_data), 2: erase; all through gDecompressBuffer
void load_save_data(struct SaveData *save);
void serialize_save_data(struct SaveData *save);
s32 validate_save_data(struct SaveData *save); // reads the EEPROM into save: 0 ok, 1 wrong signature, -1 corrupt

#endif // GUARD_SAVE_SAVE_DATA_H
