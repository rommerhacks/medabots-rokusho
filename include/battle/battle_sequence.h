#ifndef GUARD_BATTLE_BATTLE_SEQUENCE_H
#define GUARD_BATTLE_BATTLE_SEQUENCE_H

// Battle sequence: script runner, commands (gBattleSeqCommands) and sprite handlers (gBattleSeqSpriteHandlers).

void battle_sequence_run_command(
    void); // runs the battle sequence command gBattleSeqCommands[battle_seq_peek()], skipping negative ones
void battle_seq_cmd_end(void);
void battle_sequence_update_sprites(void);
void battle_sequence_update(void); // per frame during an attack animation: runs sequence commands until one yields
                                   // (gSpriteEntries[0].work[SEQ_RUN_YIELD])
s16 battle_seq_peek(void);         // current battle sequence entry (gBattleSeqScripts[unkF9][unk100])
void battle_seq_advance(void);     // skips the current battle sequence command and its operands
void battle_seq_load_operands(void);

#endif // GUARD_BATTLE_BATTLE_SEQUENCE_H
