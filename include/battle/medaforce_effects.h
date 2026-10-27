#ifndef GUARD_BATTLE_MEDAFORCE_EFFECTS_H
#define GUARD_BATTLE_MEDAFORCE_EFFECTS_H

// Medaforce effect sequences (action script opcodes 0x40-0x6A)

void medaforce_spiral_bolt_run(void);
void medaforce_hit_run(void);
void medaforce_life_drain_heal_run(void);
void medaforce_side_bolt_run(void);
void medaforce_form_run(void);
void medaforce_anti_attack_trap_run(void);
void medaforce_cancel_formation_run(void);
void medaforce_inflict_status_run(void);
void medaforce_cancel_status_run(void);
void medaforce_status_restore_run(void);
void medaforce_total_recovery_run(void);
void medaforce_full_body_repair_run(void);
void medaforce_full_body_up_run(void);
void medaforce_full_body_rad_run(void);    // step dispatcher by gBattleWork.step, sets unkB5 when done
void medaforce_iron_wall_run(void);        // step dispatcher by gBattleWork.step, sets unkB5 when done
void medaforce_power_up_run(void);         // step dispatcher by gBattleWork.step, sets unkB5 when done
void medaforce_anti_terrain_run(void);     // step dispatcher by gBattleWork.step, sets unkB5 when done
void medaforce_legs_stat_up_run(void);     // step dispatcher by gBattleWork.step, sets unkB5 when done
void medaforce_spy_game_run(void);         // step dispatcher by gBattleWork.step, sets unkB5 when done
void medaforce_hide_n_seek_run(void);      // step dispatcher by gBattleWork.step, sets unkB5 when done
void medaforce_charge_run(void);           // step dispatcher by gBattleWork.step, sets unkB5 when done
void medaforce_pushover_attack_run(void);  // step dispatcher by gBattleWork.step, sets unkB5 when done
void medaforce_useless_run(void);          // step dispatcher by gBattleWork.step, sets unkB5 when done
void medaforce_destroyer_run(void);        // step dispatcher by gBattleWork.step, sets unkB5 when done
void medaforce_crazy_run(void);            // step dispatcher by gBattleWork.step, sets unkB5 when done
void medaforce_up_run(void);               // step dispatcher by gBattleWork.step, sets unkB5 when done
void medaforce_formation_orders_run(void); // step dispatcher by gBattleWork.step, sets unkB5 when done
void medaforce_leg_crash_run(void);        // step dispatcher by gBattleWork.step, sets unkB5 when done
void medaforce_protector_run(void);        // step dispatcher by gBattleWork.step, sets unkB5 when done
void medaforce_anti_protection_run(void);  // step dispatcher by gBattleWork.step, sets unkB5 when done

#endif // GUARD_BATTLE_MEDAFORCE_EFFECTS_H
