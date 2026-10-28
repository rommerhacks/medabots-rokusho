#ifndef GUARD_BATTLE_PARTICLES_H
#define GUARD_BATTLE_PARTICLES_H

// Medaforce effect particles (sprite slots 0x21-0x3B): spawners and the per-sprite state handler tables
// (gParticleOrbitHandlers, gParticleSparkHandlers, gParticleShotHandlers, gParticleSweepHandlers).

// Each runner steps every particle slot through its table by sprite work[PARTICLE_STATE]; 1 once all slots are idle.
u32 particle_run_orbit_handlers(void);
u32 particle_run_shot_handlers(void);
u32 particle_run_sweep_handlers(void);
void particle_run_spark_handlers(void); // slots 0x2B-0x3B, no idle check

void particle_slide_lead_sprite(
    void); // moves sprite 0x21 4 px (right if gBattleWork.actorSideFlags bit 1 clear, else left)
void particle_spawn_trail_b(u32 src);

void medaforce_clear_hit_list(void);        // clears gBattleWork.partBreaks[0..2] / partDamage[0..2]
void bot_clear_effects(u32 rec, u32 flags); // flags bit 0: clears effect B (unkC9-unkCC), bit 1: effect A (unkC4-unkC7)
void battle_queue_remove_bot(u32 rec);      // frees every action queue entry of record rec

#endif // GUARD_BATTLE_PARTICLES_H
