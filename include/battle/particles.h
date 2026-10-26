#ifndef GUARD_BATTLE_PARTICLES_H
#define GUARD_BATTLE_PARTICLES_H

// Particle sprites: spawners and the per-sprite handler tables (gUnk_083AF530, gUnk_083AF690, gUnk_083AF6E0,
// gUnk_083AF720).

u32 sub_080385F8(void);                // 1 once no sprite 0x21+ has unk29 set (steps their animations)
u32 sub_0803884C(void);                // like sub_080385F8 with the gUnk_083AF720 table
void sub_08038394(u32 rec, u32 flags); // flags bit 0: clears effect B (unkC9..)
void sub_080383E8(void);
void sub_080385D0(u32 rec);
void spawn_battle_particle_effect(u32 src);
void sub_080378A8(void); // moves sprite 0x21 4 px (right if gUnk_03001800.unkF8 bit 1 clear, else left)
u32 sub_08037B9C(void);  // runs the sprite handlers of slots 0x21-0x3B; 1 when none is active
void sub_0803836C(void); // clears gUnk_03001800.unkD2[0..2] / unkD6[0..2]

#endif // GUARD_BATTLE_PARTICLES_H
