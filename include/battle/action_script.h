#ifndef GUARD_BATTLE_ACTION_SCRIPT_H
#define GUARD_BATTLE_ACTION_SCRIPT_H

// Battle state 9: the action script runner and its commands (gActionScriptCommands).

void battle_script_load_operands(void); // copies the current action script command's operands to gUnk_03001800.unkAC
s32 battle_script_read_byte(
    void); // next byte of the Robattle action script (gActionScripts[gUnk_03001800.unkA8] + unkBC)
void battle_script_advance(void);

#endif // GUARD_BATTLE_ACTION_SCRIPT_H
