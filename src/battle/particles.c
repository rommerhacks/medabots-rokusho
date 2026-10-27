// Medaforce effect particles (sprite slots 0x21-0x3B). Each particle runs a small state machine: sprite unk29
// indexes one of four handler tables (gParticleOrbitHandlers, gParticleSparkHandlers, gParticleShotHandlers,
// gParticleSweepHandlers) and each state bumps unk29 when it is done. unk2D is the state's frame counter,
// unk8/unk9 the affine scale (shrinking to nothing ends a particle), unk18 the rotation. gBattleWork.unk51 picks the
// effect variant (sprite frames, sound). Called from battle/medaforce_effects.

#include "global.h"

void particle_slide_lead_sprite(void) {
    if (!(gBattleWork.actorSideFlags & 2))
        gSpriteEntries[0x21].unk2 = (gSpriteEntries[0x21].unk2 + 4) & 0x1FF;
    else
        gSpriteEntries[0x21].unk2 = (gSpriteEntries[0x21].unk2 - 4) & 0x1FF;
}

// Every 16 (variant 0) or 8 frames of the orbiting sprite src, drops a trail particle next to it.
static void particle_spawn_trail_a(u32 src) {
    u32 mask;
    u32 slot;
    struct SpriteEntry *orbiter, *particle;
    struct SpriteEntry *base;

    switch (gBattleWork.unk51) {
    case 0:
        mask = 0xF;
        break;
    case 1:
        mask = 7;
        break;
    case 2:
        mask = 7;
        break;
    case 3:
        mask = 7;
        break;
    case 4:
        mask = 7;
        break;
    case 5:
        mask = 7;
        break;
    }
    base = gSpriteEntries;
    orbiter = &base[src];
    if (!(orbiter->unk2D & mask)) {
        slot = find_next_free_sprite_slot(src + 1, 0x14);
        clear_battle_sprite_slot(slot, 1);
        particle = &base[slot];
        particle->unk0 = 0xC604;
        particle->unk1C = 0;
        particle->unk2 = (orbiter->unk2 + gParticleTrailOffsets[(rng_next_byte() & 3) * 2]) & 0x1FF;
        particle->unk4 = (orbiter->unk4 + gParticleTrailOffsets[(rng_next_byte() & 3) * 2 + 1]) & 0xFF;
        particle->unk8 = 0x40;
        particle->unk9 = 0x40;
        particle->unkA = 6;
        particle->unkB = 0xE0;
        switch (gBattleWork.unk51) {
        case 0:
            gSpriteEntries[slot].unk6 = (rng_next_byte() & 3) + 0x6B01;
            gSpriteEntries[slot].unk29 = 0x10;
            break;
        case 1:
            gSpriteEntries[slot].unk6 = 0x6C01;
            gSpriteEntries[slot].unk29 = 0x14;
            break;
        case 2:
            gSpriteEntries[slot].unk6 = 0x6D01;
            gSpriteEntries[slot].unk29 = 0x18;
            break;
        case 3:
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x5E], slot);
            gSpriteEntries[slot].unk29 = 0x1C;
            break;
        case 4:
            gSpriteEntries[slot].unk6 = 0x7001;
            gSpriteEntries[slot].unk29 = 0x20;
            break;
        case 5:
            break;
        }
    }
}

// particle_spawn_trail_a for particle_orbit_b: every 8 frames, a trail particle next to src.
void particle_spawn_trail_b(u32 src) {
    u32 mask;
    u32 slot;
    struct SpriteEntry *orbiter, *particle;
    struct SpriteEntry *base;

    switch (gBattleWork.unk51) {
    case 0:
        mask = 7;
        break;
    case 1:
        mask = 7;
        break;
    case 2:
        mask = 7;
        break;
    }
    base = gSpriteEntries;
    orbiter = &base[src];
    if (!(orbiter->unk2D & mask)) {
        slot = find_next_free_sprite_slot(src + 1, 0x14);
        clear_battle_sprite_slot(slot, 1);
        particle = &base[slot];
        particle->unk0 = 0xC604;
        particle->unk1C = 0;
        particle->unk2 = (orbiter->unk2 + gParticleTrailOffsets[(rng_next_byte() & 3) * 2]) & 0x1FF;
        particle->unk4 = (orbiter->unk4 + gParticleTrailOffsets[(rng_next_byte() & 3) * 2 + 1]) & 0xFF;
        particle->unk8 = 0x40;
        particle->unk9 = 0x40;
        particle->unkA = 6;
        particle->unkB = 0xE0;
        switch (gBattleWork.unk51) {
        case 0:
            particle->unk6 = 0x7201;
            particle->unk29 = 0x30;
            break;
        case 1:
            particle->unk6 = 0x7302;
            particle->unk29 = 0x34;
            break;
        case 2:
            particle->unk6 = 0x7402;
            particle->unk29 = 0x34;
            break;
        }
    }
}

u32 particle_run_orbit_handlers(void) {
    u32 done = 1;
    u32 i;
    u32 state;

    for (i = 0; i <= 0x1A; i++) {
        gEffectSpriteSlot = i + 0x21;
        if (gSpriteEntries[i + 0x21].unk29)
            done = 0;
        state = gSpriteEntries[i + 0x21].unk29;
        gParticleOrbitHandlers[state]();
    }
    return done;
}

// Orbit state 1: moves down 1 px a frame until y = 0x14.
void particle_descend_into_view(void) {
    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gGameWork.runningSpriteSlot].unk2E],
                                 gGameWork.runningSpriteSlot);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].unk4 == 0x14)
        gSpriteEntries[gGameWork.runningSpriteSlot].unk29++;
    else
        gSpriteEntries[gGameWork.runningSpriteSlot].unk4 =
            (gSpriteEntries[gGameWork.runningSpriteSlot].unk4 + 1) & 0xFF;
}

// Orbit state 2: circles the point (0xB8 or 0x38, 0x34) for 255 frames (angle unk2C, pulsing radius unk2B),
// spinning and dropping trail particles, with a variant sound every 64 frames.
void particle_orbit_a(void) {
    struct Coords16 pos;

    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gGameWork.runningSpriteSlot].unk2E],
                                 gGameWork.runningSpriteSlot);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].unk2D == 0xFF) {
        gSpriteEntries[gGameWork.runningSpriteSlot].unk29++;
        return;
    }
    if (!(gSpriteEntries[gGameWork.runningSpriteSlot].unk2D & 0x3F)) {
        switch (gBattleWork.unk51) {
        case 0:
            play_sound_effect(0x36);
            break;
        case 1:
            play_sound_effect(0x28);
            break;
        case 2:
            play_sound_effect(0x31);
            break;
        case 3:
            play_sound_effect(0x71);
            break;
        case 4:
            play_sound_effect(0x4F);
            break;
        case 5:
            break;
        }
    }
    gSpriteEntries[gGameWork.runningSpriteSlot].unk2B +=
        gParticleOrbitRadiusSteps[(gSpriteEntries[gGameWork.runningSpriteSlot].unk2D & 0x1F) * 2];
    if (!(gBattleWork.actorSideFlags & 1)) {
        if (gBattleWork.unk51 != 3)
            gSpriteEntries[gGameWork.runningSpriteSlot].unk18 =
                (gSpriteEntries[gGameWork.runningSpriteSlot].unk18 - 0x10) & 0x3FF;
        gSpriteEntries[gGameWork.runningSpriteSlot].unk2C--;
        pos = calc_polar_to_screen_coords(gSpriteEntries[gGameWork.runningSpriteSlot].unk2C,
                                          gSpriteEntries[gGameWork.runningSpriteSlot].unk2B, 0xB8, 0x34);
    } else {
        if (gBattleWork.unk51 != 3)
            gSpriteEntries[gGameWork.runningSpriteSlot].unk18 =
                (gSpriteEntries[gGameWork.runningSpriteSlot].unk18 + 0x10) & 0x3FF;
        gSpriteEntries[gGameWork.runningSpriteSlot].unk2C++;
        pos = calc_polar_to_screen_coords(gSpriteEntries[gGameWork.runningSpriteSlot].unk2C,
                                          gSpriteEntries[gGameWork.runningSpriteSlot].unk2B, 0x38, 0x34);
    }
    gSpriteEntries[gGameWork.runningSpriteSlot].unk2 = pos.x;
    gSpriteEntries[gGameWork.runningSpriteSlot].unk4 = pos.y;
    particle_spawn_trail_a(gGameWork.runningSpriteSlot);
    gSpriteEntries[gGameWork.runningSpriteSlot].unk2D++;
}

// particle_orbit_a mirrored (other side and direction), its own sounds and trail.
void particle_orbit_b(void) {
    struct Coords16 pos;

    process_sprite_anim_commands(gUnk_083B5F80[gSpriteEntries[gGameWork.runningSpriteSlot].unk2E],
                                 gGameWork.runningSpriteSlot);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].unk2D == 0xFF) {
        gSpriteEntries[gGameWork.runningSpriteSlot].unk29++;
        return;
    }
    if (!(gSpriteEntries[gGameWork.runningSpriteSlot].unk2D & 0x3F)) {
        switch (gBattleWork.unk51) {
        case 0:
            play_sound_effect(0x5D);
            break;
        case 1:
            play_sound_effect(0x2E);
            break;
        case 2:
            play_sound_effect(0x4B);
            break;
        }
    }
    gSpriteEntries[gGameWork.runningSpriteSlot].unk2B +=
        gParticleOrbitRadiusSteps[(gSpriteEntries[gGameWork.runningSpriteSlot].unk2D & 0x1F) * 2];
    if (gBattleWork.actorSideFlags & 1) {
        if (gBattleWork.unk51 == 0)
            gSpriteEntries[gGameWork.runningSpriteSlot].unk18 =
                (gSpriteEntries[gGameWork.runningSpriteSlot].unk18 - 0x10) & 0x3FF;
        gSpriteEntries[gGameWork.runningSpriteSlot].unk2C--;
        pos = calc_polar_to_screen_coords(gSpriteEntries[gGameWork.runningSpriteSlot].unk2C,
                                          gSpriteEntries[gGameWork.runningSpriteSlot].unk2B, 0xB8, 0x34);
    } else {
        if (gBattleWork.unk51 == 0)
            gSpriteEntries[gGameWork.runningSpriteSlot].unk18 =
                (gSpriteEntries[gGameWork.runningSpriteSlot].unk18 + 0x10) & 0x3FF;
        gSpriteEntries[gGameWork.runningSpriteSlot].unk2C++;
        pos = calc_polar_to_screen_coords(gSpriteEntries[gGameWork.runningSpriteSlot].unk2C,
                                          gSpriteEntries[gGameWork.runningSpriteSlot].unk2B, 0x38, 0x34);
    }
    gSpriteEntries[gGameWork.runningSpriteSlot].unk2 = pos.x;
    gSpriteEntries[gGameWork.runningSpriteSlot].unk4 = pos.y;
    particle_spawn_trail_b(gGameWork.runningSpriteSlot);
    gSpriteEntries[gGameWork.runningSpriteSlot].unk2D++;
}

void particle_shrink_by_4(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].unk8 == 4) {
        gSpriteEntries[gGameWork.runningSpriteSlot].unk29++;
    } else {
        gSpriteEntries[gGameWork.runningSpriteSlot].unk8 -= 4;
        gSpriteEntries[gGameWork.runningSpriteSlot].unk9 -= 4;
    }
}

// Waits until unk2D reaches 90.
void particle_wait_90(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].unk2D == 0x5A)
        gSpriteEntries[gGameWork.runningSpriteSlot].unk29++;
    else
        gSpriteEntries[gGameWork.runningSpriteSlot].unk2D++;
}

void particle_shrink_by_8(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].unk8 == 8) {
        gSpriteEntries[gGameWork.runningSpriteSlot].unk29++;
    } else {
        gSpriteEntries[gGameWork.runningSpriteSlot].unk8 -= 8;
        gSpriteEntries[gGameWork.runningSpriteSlot].unk9 -= 8;
    }
}

void particle_free(void) {
    clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
}

// Waits until unk2D reaches 35.
void particle_wait_35(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].unk2D == 0x23)
        gSpriteEntries[gGameWork.runningSpriteSlot].unk29++;
    else
        gSpriteEntries[gGameWork.runningSpriteSlot].unk2D++;
}

// Sways left and right (gParticleSwayOffsets) while drifting down, for 70 frames.
void particle_sway_down(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].unk2D == 0x46) {
        gSpriteEntries[gGameWork.runningSpriteSlot].unk29++;
    } else {
        gSpriteEntries[gGameWork.runningSpriteSlot].unk2 =
            (gSpriteEntries[gGameWork.runningSpriteSlot].unk2 +
             gParticleSwayOffsets[gSpriteEntries[gGameWork.runningSpriteSlot].unk2D & 0xF]) &
            0x1FF;
        if (gSpriteEntries[gGameWork.runningSpriteSlot].unk2D & 1)
            gSpriteEntries[gGameWork.runningSpriteSlot].unk4++;
        gSpriteEntries[gGameWork.runningSpriteSlot].unk2D++;
    }
}

// Animates and rises 1 px every 8 frames, for 90 frames.
void particle_float_up(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x5E], gGameWork.runningSpriteSlot);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].unk2D == 0x5A)
        gSpriteEntries[gGameWork.runningSpriteSlot].unk29++;
    else {
        if (!(gSpriteEntries[gGameWork.runningSpriteSlot].unk2D & 7))
            gSpriteEntries[gGameWork.runningSpriteSlot].unk4--;
        gSpriteEntries[gGameWork.runningSpriteSlot].unk2D++;
    }
}

// Spins for 35 frames (direction by side).
void particle_spin_35(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].unk2D == 0x23) {
        gSpriteEntries[gGameWork.runningSpriteSlot].unk29++;
    } else {
        if (!(gBattleWork.actorSideFlags & 1))
            gSpriteEntries[gGameWork.runningSpriteSlot].unk18 =
                (gSpriteEntries[gGameWork.runningSpriteSlot].unk18 - 0x10) & 0x3FF;
        else
            gSpriteEntries[gGameWork.runningSpriteSlot].unk18 =
                (gSpriteEntries[gGameWork.runningSpriteSlot].unk18 + 0x10) & 0x3FF;
        gSpriteEntries[gGameWork.runningSpriteSlot].unk2D++;
    }
}

// Spins while drifting down, for 70 frames.
void particle_spin_down(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].unk2D == 0x46) {
        gSpriteEntries[gGameWork.runningSpriteSlot].unk29++;
    } else {
        if (gSpriteEntries[gGameWork.runningSpriteSlot].unk2D & 1)
            gSpriteEntries[gGameWork.runningSpriteSlot].unk4++;
        if (!(gBattleWork.actorSideFlags & 1))
            gSpriteEntries[gGameWork.runningSpriteSlot].unk18 =
                (gSpriteEntries[gGameWork.runningSpriteSlot].unk18 - 0x10) & 0x3FF;
        else
            gSpriteEntries[gGameWork.runningSpriteSlot].unk18 =
                (gSpriteEntries[gGameWork.runningSpriteSlot].unk18 + 0x10) & 0x3FF;
        gSpriteEntries[gGameWork.runningSpriteSlot].unk2D++;
    }
}

// Spins the other way for 90 frames.
void particle_spin_back_90(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].unk2D == 0x5A) {
        gSpriteEntries[gGameWork.runningSpriteSlot].unk29++;
    } else {
        if (gBattleWork.actorSideFlags & 1)
            gSpriteEntries[gGameWork.runningSpriteSlot].unk18 =
                (gSpriteEntries[gGameWork.runningSpriteSlot].unk18 - 0x10) & 0x3FF;
        else
            gSpriteEntries[gGameWork.runningSpriteSlot].unk18 =
                (gSpriteEntries[gGameWork.runningSpriteSlot].unk18 + 0x10) & 0x3FF;
        gSpriteEntries[gGameWork.runningSpriteSlot].unk2D++;
    }
}

void medaforce_clear_hit_list(void) {
    u32 i;
    for (i = 0; i <= 2; i++) {
        gBattleWork.unkD2[i] = 0;
        gBattleWork.unkD6[i] = 0;
    }
}

void bot_clear_effects(u32 rec, u32 flags) {
    if (flags & 1) {
        gBattleBots[rec].statusType = 0;
        gBattleBots[rec].statusPart = 0;
        gBattleBots[rec].statusTimer = 0;
        gBattleBots[rec].statusAmount = 0;
    }
    if (flags & 2) {
        gBattleBots[rec].buffType = 0;
        gBattleBots[rec].buffPart = 0;
        gBattleBots[rec].buffTimer = 0;
        gBattleBots[rec].buffAmount = 0;
    }
}

void particle_run_spark_handlers(void) {
    u32 i;
    for (i = 10; i <= 0x1A; i++) {
        gEffectSpriteSlot = i + 0x21;
        gParticleSparkHandlers[gSpriteEntries[i + 0x21].unk29]();
    }
}

// Spark state 1: every 8 frames (gGameWork.unk86) launches a spark from near the emitter toward a point
// just in front of it.
void particle_spark_emitter(void) {
    u32 roll, slot;
    struct SpriteEntry *particle;
    struct SpriteEntry *base;

    if ((roll = gGameWork.unk86 & 7) == 0) {
        slot = find_next_free_sprite_slot(gGameWork.runningSpriteSlot + 1, 10);
        clear_battle_sprite_slot(slot, 1);
        base = gSpriteEntries;
        particle = &base[slot];
        particle->unk0 = 0xC604;
        particle->unk1C = 0;
        particle->unk2 = 0x78;
        particle->unk4 = 0x78;
        particle->unk8 = 0x40;
        particle->unk9 = 0x40;
        particle->unk18 = roll;
        particle->unkA = 6;
        particle->unkB = 0xF0;
        particle->unk6 = 0x7706;
        particle->unk29 = 2;
        particle->unk24 = 3;
        particle->unk23 = 0;
        roll = rng_next_byte() & 3;
        if (!(gBattleWork.actorSideFlags & 1)) {
            particle->unk2 = (base[gGameWork.runningSpriteSlot].unk2 + gParticleSparkOffsets[roll << 1]) & 0x1FF;
            particle->unk4 = (base[gGameWork.runningSpriteSlot].unk4 + gParticleSparkOffsets[roll * 2 + 1]) & 0xFF;
            particle->unk30 = base[gGameWork.runningSpriteSlot].unk2 + 0x10;
            particle->unk32 = base[gGameWork.runningSpriteSlot].unk4 + 4;
        } else {
            particle->unk2 =
                (0xF0 - (base[gGameWork.runningSpriteSlot].unk2 + gParticleSparkOffsets[roll << 1])) & 0x1FF;
            particle->unk4 = (base[gGameWork.runningSpriteSlot].unk4 + gParticleSparkOffsets[roll * 2 + 1]) & 0xFF;
            particle->unk30 = base[gGameWork.runningSpriteSlot].unk2 - 0x10;
            particle->unk32 = base[gGameWork.runningSpriteSlot].unk4 + 6;
        }
    }
}

// Spark state 2: spins and flies to its target, then disappears.
void particle_spark_fly(void) {
    gSpriteEntries[gGameWork.runningSpriteSlot].unk18 =
        (gSpriteEntries[gGameWork.runningSpriteSlot].unk18 + 0x10) & 0x3FF;
    if (move_sprite_toward_target(gGameWork.runningSpriteSlot))
        clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
}

void battle_queue_remove_bot(u32 rec) {
    u32 i;
    struct BattleWork *battle;
    for (i = 0, battle = &gBattleWork; i <= 5; i++) {
        if (battle->actionQueue[i][0] == rec + 1) {
            battle->actionQueue[i][0] = 0;
            battle->actionQueue[i][1] = 0;
        }
    }
}

u32 particle_run_shot_handlers(void) {
    u32 done = 1;
    u32 i;
    u32 state;

    for (i = 0; i <= 0x1A; i++) {
        gEffectSpriteSlot = i + 0x21;
        if (gSpriteEntries[i + 0x21].unk29)
            done = 0;
        state = gSpriteEntries[i + 0x21].unk29;
        gParticleShotHandlers[state]();
    }
    return done;
}

// Shot state 1: flies to the target; on arrival plays the impact animation and starts a second impact sprite
// 3 slots on (state 3).
void particle_shot_fly(void) {
    if (move_sprite_toward_target(gGameWork.runningSpriteSlot)) {
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6B], gGameWork.runningSpriteSlot);
        gSpriteEntries[gGameWork.runningSpriteSlot].unkA = 6;
        gSpriteEntries[gGameWork.runningSpriteSlot].unk28 = 0;
        gSpriteEntries[gGameWork.runningSpriteSlot].unk29++;
        memcpy_bytes_0803F63C(&gSpriteEntries[gGameWork.runningSpriteSlot],
                              &gSpriteEntries[gGameWork.runningSpriteSlot + 3], 0x40);
        init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6C], gGameWork.runningSpriteSlot + 3);
        gSpriteEntries[gGameWork.runningSpriteSlot + 3].unkB =
            (gGameWork.runningSpriteSlot + (gBattleWork.targetSideFirst + 0xDF)) * 4 + 0x59;
        gSpriteEntries[gGameWork.runningSpriteSlot + 3].unk29 = 3;
    }
}

// Shot state 2: shakes the hit Medabot's sprite up and down until the impact animation ends.
void particle_shot_shake_target(void) {
    gSpriteEntries[gGameWork.runningSpriteSlot].unk28++;
    if (gSpriteEntries[gGameWork.runningSpriteSlot].unk28 & 2)
        gSpriteEntries[((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21))) * 4 + 0x5D].unk4 =
            gBattleWork.botPositions[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21))].y + 2;
    else
        gSpriteEntries[((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21))) * 4 + 0x5D].unk4 =
            gBattleWork.botPositions[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21))].y + 4;
    target_cursor_place_markers((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21)));
    process_sprite_anim_commands(gUnk_083B5F80[0x6B], gGameWork.runningSpriteSlot);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].unk22 == 0xFF) {
        gSpriteEntries[((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21))) * 4 + 0x5D].unk4 =
            gBattleWork.botPositions[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21))].y + 4;
        target_cursor_place_markers((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21)));
        clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
    }
}

void particle_play_anim_then_free(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x6C], gGameWork.runningSpriteSlot);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].unk22 == 0xFF)
        clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
}

u32 particle_run_sweep_handlers(void) {
    u32 done = 1;
    u32 i;
    u32 state;

    for (i = 0; i <= 0x1A; i++) {
        gEffectSpriteSlot = i + 0x21;
        if (gSpriteEntries[i + 0x21].unk29)
            done = 0;
        state = gSpriteEntries[i + 0x21].unk29;
        gParticleSweepHandlers[state]();
    }
    return done;
}

// Sweep state 1: moves 4 px a frame across the screen; passing a Medabot that takes damage (unkD6) plays a
// hit sound and starts a hit sprite 3 slots on. Freed after 41 frames.
void particle_sweep_across(void) {
    process_sprite_anim_commands(gUnk_083B5F80[0x6D], gGameWork.runningSpriteSlot);
    if (!(gBattleWork.actorSideFlags & 1)) {
        gSpriteEntries[gGameWork.runningSpriteSlot].unk2 =
            (gSpriteEntries[gGameWork.runningSpriteSlot].unk2 + 4) & 0x1FF;
        if (gSpriteEntries[gGameWork.runningSpriteSlot].unk2 >
                gSpriteEntries[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21)) * 4 + 0x5D].unk2 &&
            gBattleWork.unkD6[gGameWork.runningSpriteSlot - 0x21] != 0 &&
            gSpriteEntries[gGameWork.runningSpriteSlot].unk28 == 0) {
            play_sound_effect(0x54);
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].unk0 = 0xC404;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].unk1C = 0;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].unk2 =
                gSpriteEntries[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21)) * 4 + 0x5D].unk2;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].unk4 =
                gSpriteEntries[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21)) * 4 + 0x5D].unk4 -
                4;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].unkA = 6;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].unkB = 0xF1;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].unk29 = 2;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].unk28 = 0;
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6E], gGameWork.runningSpriteSlot + 3);
            gSpriteEntries[gGameWork.runningSpriteSlot].unk28 = 1;
        }
    } else {
        gSpriteEntries[gGameWork.runningSpriteSlot].unk2 =
            (gSpriteEntries[gGameWork.runningSpriteSlot].unk2 - 4) & 0x1FF;
        if (gSpriteEntries[gGameWork.runningSpriteSlot].unk2 <
                gSpriteEntries[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21)) * 4 + 0x5D].unk2 &&
            gBattleWork.unkD6[gGameWork.runningSpriteSlot - 0x21] != 0 &&
            gSpriteEntries[gGameWork.runningSpriteSlot].unk28 == 0) {
            play_sound_effect(0x54);
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].unk0 = 0xD404;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].unk1C = 0;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].unk2 =
                gSpriteEntries[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21)) * 4 + 0x5D].unk2;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].unk4 =
                gSpriteEntries[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21)) * 4 + 0x5D].unk4 -
                4;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].unkA = 6;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].unkB = 0xF1;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].unk29 = 2;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].unk28 = 0;
            init_battle_sprite_entry_08040B90(gUnk_083B5F80[0x6E], gGameWork.runningSpriteSlot + 3);
            gSpriteEntries[gGameWork.runningSpriteSlot].unk28 = 1;
        }
    }
    if (gSpriteEntries[gGameWork.runningSpriteSlot].unk27 > 0x28)
        clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
    else
        gSpriteEntries[gGameWork.runningSpriteSlot].unk27++;
}

// Sweep state 2: shakes the hit Medabot's sprite sideways until the hit animation ends.
void particle_sweep_shake_target(void) {
    gSpriteEntries[gGameWork.runningSpriteSlot].unk28++;
    if (gSpriteEntries[gGameWork.runningSpriteSlot].unk28 & 2)
        gSpriteEntries[((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x24))) * 4 + 0x5D].unk2 =
            gBattleWork.botPositions[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x24))].x + 2;
    else
        gSpriteEntries[((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x24))) * 4 + 0x5D].unk2 =
            gBattleWork.botPositions[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x24))].x - 2;
    target_cursor_place_markers((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x24)));
    process_sprite_anim_commands(gUnk_083B5F80[0x6E], gGameWork.runningSpriteSlot);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].unk22 == 0xFF) {
        gSpriteEntries[((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x24))) * 4 + 0x5D].unk2 =
            gBattleWork.botPositions[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x24))].x;
        target_cursor_place_markers((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x24)));
        clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
    }
}
