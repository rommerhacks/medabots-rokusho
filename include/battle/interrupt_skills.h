#ifndef GUARD_BATTLE_INTERRUPT_SKILLS_H
#define GUARD_BATTLE_INTERRUPT_SKILLS_H

// Effect sequences of the Interrupt abilities (action script opcodes 0x36-0x3F)

void no_escape_defense_run(void);
void impair_run(void);
void confusion_run(void);
void use_drain_run(void);
void forcedrain_run(void);
void team_attack_check_run(void);
void team_attack_turrets_run(void);
void counter_attack_run(void);
void change_run(void);

#endif // GUARD_BATTLE_INTERRUPT_SKILLS_H
