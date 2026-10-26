#ifndef GUARD_BATTLE_BATTLE_SEQUENCE_H
#define GUARD_BATTLE_BATTLE_SEQUENCE_H

// Battle sequence: script runner, commands (gUnk_083AF740) and sprite handlers (gUnk_083AF96C).

void battle_sequence_run_command(
    void); // runs the battle sequence command gUnk_083AF740[sub_0803D424()], skipping negative ones
void sub_08039430(void);
void battle_sequence_update_sprites(void);
void battle_sequence_update(
    void); // per frame during an attack animation: runs sequence commands until one yields (gUnk_03002C30[0].unk2A)
s16 sub_0803D424(void);                     // current battle sequence entry (gUnk_083CDFE4[unkF9][unk100])
void battle_advance_sequence_counter(void); // skips the current battle sequence command and its operands
void load_battle_sequence_commands(void);

#endif // GUARD_BATTLE_BATTLE_SEQUENCE_H
