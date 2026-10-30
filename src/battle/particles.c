// Medaforce effect particles (sprite slots 0x21-0x3B). Each particle runs a small state machine: sprite
// work[PARTICLE_STATE] indexes one of four handler tables (gParticleOrbitHandlers, gParticleSparkHandlers,
// gParticleShotHandlers, gParticleSweepHandlers) and each state bumps it when it is done. work[PARTICLE_TIMER] is the
// state's frame counter, scale_x / scale_y the affine scale (shrinking to nothing ends a particle), angle the
// rotation. gBattleWork.scratch picks the effect variant (sprite frames, sound). Called from battle/medaforce_effects.

#include "global.h"
#include "constants/battle_seq_sprites.h"
#include "constants/sprites.h"

void particle_slide_lead_sprite(void) {
    if (!(gBattleWork.actorSideFlags & 2))
        gSpriteEntries[0x21].x = (gSpriteEntries[0x21].x + 4) & 0x1FF;
    else
        gSpriteEntries[0x21].x = (gSpriteEntries[0x21].x - 4) & 0x1FF;
}

// Every 16 (variant 0) or 8 frames of the orbiting sprite src, drops a trail particle next to it.
static void particle_spawn_trail_a(u32 src) {
    u32 mask;
    u32 slot;
    struct SpriteEntry *orbiter, *particle;
    struct SpriteEntry *base;

    switch (gBattleWork.scratch) {
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
    if (!(orbiter->work[PARTICLE_TIMER] & mask)) {
        slot = find_next_free_sprite_slot(src + 1, 0x14);
        clear_battle_sprite_slot(slot, 1);
        particle = &base[slot];
        particle->flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE |
                          SPRITE_FLAG_PART_PALETTE;
        particle->frame_table = 0;
        particle->x = (orbiter->x + gParticleTrailOffsets[(rng_next_byte() & 3) * 2]) & 0x1FF;
        particle->y = (orbiter->y + gParticleTrailOffsets[(rng_next_byte() & 3) * 2 + 1]) & 0xFF;
        particle->scale_x = 0x40;
        particle->scale_y = 0x40;
        particle->palette = 6;
        particle->order = 0xE0;
        switch (gBattleWork.scratch) {
        case 0:
            gSpriteEntries[slot].frame = (rng_next_byte() & 3) + 0x6B01;
            gSpriteEntries[slot].work[PARTICLE_STATE] = 0x10;
            break;
        case 1:
            gSpriteEntries[slot].frame = 0x6C01;
            gSpriteEntries[slot].work[PARTICLE_STATE] = 0x14;
            break;
        case 2:
            gSpriteEntries[slot].frame = 0x6D01;
            gSpriteEntries[slot].work[PARTICLE_STATE] = 0x18;
            break;
        case 3:
            battle_sprite_anim_init(gBattleSpriteAnimScripts[0x5E], slot);
            gSpriteEntries[slot].work[PARTICLE_STATE] = 0x1C;
            break;
        case 4:
            gSpriteEntries[slot].frame = 0x7001;
            gSpriteEntries[slot].work[PARTICLE_STATE] = 0x20;
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

    switch (gBattleWork.scratch) {
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
    if (!(orbiter->work[PARTICLE_TIMER] & mask)) {
        slot = find_next_free_sprite_slot(src + 1, 0x14);
        clear_battle_sprite_slot(slot, 1);
        particle = &base[slot];
        particle->flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE |
                          SPRITE_FLAG_PART_PALETTE;
        particle->frame_table = 0;
        particle->x = (orbiter->x + gParticleTrailOffsets[(rng_next_byte() & 3) * 2]) & 0x1FF;
        particle->y = (orbiter->y + gParticleTrailOffsets[(rng_next_byte() & 3) * 2 + 1]) & 0xFF;
        particle->scale_x = 0x40;
        particle->scale_y = 0x40;
        particle->palette = 6;
        particle->order = 0xE0;
        switch (gBattleWork.scratch) {
        case 0:
            particle->frame = 0x7201;
            particle->work[PARTICLE_STATE] = 0x30;
            break;
        case 1:
            particle->frame = 0x7302;
            particle->work[PARTICLE_STATE] = 0x34;
            break;
        case 2:
            particle->frame = 0x7402;
            particle->work[PARTICLE_STATE] = 0x34;
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
        if (gSpriteEntries[i + 0x21].work[PARTICLE_STATE])
            done = 0;
        state = gSpriteEntries[i + 0x21].work[PARTICLE_STATE];
        gParticleOrbitHandlers[state]();
    }
    return done;
}

// Orbit state 1: moves down 1 px a frame until y = 0x14.
void particle_descend_into_view(void) {
    process_sprite_anim_commands(
        gBattleSpriteAnimScripts[gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_ANIM]],
        gGameWork.runningSpriteSlot);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].y == 0x14)
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_STATE]++;
    else
        gSpriteEntries[gGameWork.runningSpriteSlot].y = (gSpriteEntries[gGameWork.runningSpriteSlot].y + 1) & 0xFF;
}

// Orbit state 2: circles the point (0xB8 or 0x38, 0x34) for 255 frames (angle PARTICLE_ORBIT_ANGLE, pulsing radius
// PARTICLE_ORBIT_RADIUS), spinning and dropping trail particles, with a variant sound every 64 frames.
void particle_orbit_a(void) {
    struct Coords16 pos;

    process_sprite_anim_commands(
        gBattleSpriteAnimScripts[gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_ANIM]],
        gGameWork.runningSpriteSlot);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER] == 0xFF) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_STATE]++;
        return;
    }
    if (!(gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER] & 0x3F)) {
        switch (gBattleWork.scratch) {
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
    gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_ORBIT_RADIUS] +=
        gParticleOrbitRadiusSteps[(gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER] & 0x1F) * 2];
    if (!(gBattleWork.actorSideFlags & 1)) {
        if (gBattleWork.scratch != 3)
            gSpriteEntries[gGameWork.runningSpriteSlot].angle =
                (gSpriteEntries[gGameWork.runningSpriteSlot].angle - 0x10) & 0x3FF;
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_ORBIT_ANGLE]--;
        pos = calc_polar_to_screen_coords(gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_ORBIT_ANGLE],
                                          gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_ORBIT_RADIUS], 0xB8,
                                          0x34);
    } else {
        if (gBattleWork.scratch != 3)
            gSpriteEntries[gGameWork.runningSpriteSlot].angle =
                (gSpriteEntries[gGameWork.runningSpriteSlot].angle + 0x10) & 0x3FF;
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_ORBIT_ANGLE]++;
        pos = calc_polar_to_screen_coords(gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_ORBIT_ANGLE],
                                          gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_ORBIT_RADIUS], 0x38,
                                          0x34);
    }
    gSpriteEntries[gGameWork.runningSpriteSlot].x = pos.x;
    gSpriteEntries[gGameWork.runningSpriteSlot].y = pos.y;
    particle_spawn_trail_a(gGameWork.runningSpriteSlot);
    gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER]++;
}

// particle_orbit_a mirrored (other side and direction), its own sounds and trail.
void particle_orbit_b(void) {
    struct Coords16 pos;

    process_sprite_anim_commands(
        gBattleSpriteAnimScripts[gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_ANIM]],
        gGameWork.runningSpriteSlot);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER] == 0xFF) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_STATE]++;
        return;
    }
    if (!(gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER] & 0x3F)) {
        switch (gBattleWork.scratch) {
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
    gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_ORBIT_RADIUS] +=
        gParticleOrbitRadiusSteps[(gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER] & 0x1F) * 2];
    if (gBattleWork.actorSideFlags & 1) {
        if (gBattleWork.scratch == 0)
            gSpriteEntries[gGameWork.runningSpriteSlot].angle =
                (gSpriteEntries[gGameWork.runningSpriteSlot].angle - 0x10) & 0x3FF;
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_ORBIT_ANGLE]--;
        pos = calc_polar_to_screen_coords(gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_ORBIT_ANGLE],
                                          gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_ORBIT_RADIUS], 0xB8,
                                          0x34);
    } else {
        if (gBattleWork.scratch == 0)
            gSpriteEntries[gGameWork.runningSpriteSlot].angle =
                (gSpriteEntries[gGameWork.runningSpriteSlot].angle + 0x10) & 0x3FF;
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_ORBIT_ANGLE]++;
        pos = calc_polar_to_screen_coords(gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_ORBIT_ANGLE],
                                          gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_ORBIT_RADIUS], 0x38,
                                          0x34);
    }
    gSpriteEntries[gGameWork.runningSpriteSlot].x = pos.x;
    gSpriteEntries[gGameWork.runningSpriteSlot].y = pos.y;
    particle_spawn_trail_b(gGameWork.runningSpriteSlot);
    gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER]++;
}

void particle_shrink_by_4(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].scale_x == 4) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_STATE]++;
    } else {
        gSpriteEntries[gGameWork.runningSpriteSlot].scale_x -= 4;
        gSpriteEntries[gGameWork.runningSpriteSlot].scale_y -= 4;
    }
}

// Waits until PARTICLE_TIMER reaches 90.
void particle_wait_90(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER] == 0x5A)
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_STATE]++;
    else
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER]++;
}

void particle_shrink_by_8(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].scale_x == 8) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_STATE]++;
    } else {
        gSpriteEntries[gGameWork.runningSpriteSlot].scale_x -= 8;
        gSpriteEntries[gGameWork.runningSpriteSlot].scale_y -= 8;
    }
}

void particle_free(void) {
    clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
}

// Waits until PARTICLE_TIMER reaches 35.
void particle_wait_35(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER] == 0x23)
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_STATE]++;
    else
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER]++;
}

// Sways left and right (gParticleSwayOffsets) while drifting down, for 70 frames.
void particle_sway_down(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER] == 0x46) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_STATE]++;
    } else {
        gSpriteEntries[gGameWork.runningSpriteSlot].x =
            (gSpriteEntries[gGameWork.runningSpriteSlot].x +
             gParticleSwayOffsets[gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER] & 0xF]) &
            0x1FF;
        if (gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER] & 1)
            gSpriteEntries[gGameWork.runningSpriteSlot].y++;
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER]++;
    }
}

// Animates and rises 1 px every 8 frames, for 90 frames.
void particle_float_up(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x5E], gGameWork.runningSpriteSlot);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER] == 0x5A)
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_STATE]++;
    else {
        if (!(gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER] & 7))
            gSpriteEntries[gGameWork.runningSpriteSlot].y--;
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER]++;
    }
}

// Spins for 35 frames (direction by side).
void particle_spin_35(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER] == 0x23) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_STATE]++;
    } else {
        if (!(gBattleWork.actorSideFlags & 1))
            gSpriteEntries[gGameWork.runningSpriteSlot].angle =
                (gSpriteEntries[gGameWork.runningSpriteSlot].angle - 0x10) & 0x3FF;
        else
            gSpriteEntries[gGameWork.runningSpriteSlot].angle =
                (gSpriteEntries[gGameWork.runningSpriteSlot].angle + 0x10) & 0x3FF;
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER]++;
    }
}

// Spins while drifting down, for 70 frames.
void particle_spin_down(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER] == 0x46) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_STATE]++;
    } else {
        if (gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER] & 1)
            gSpriteEntries[gGameWork.runningSpriteSlot].y++;
        if (!(gBattleWork.actorSideFlags & 1))
            gSpriteEntries[gGameWork.runningSpriteSlot].angle =
                (gSpriteEntries[gGameWork.runningSpriteSlot].angle - 0x10) & 0x3FF;
        else
            gSpriteEntries[gGameWork.runningSpriteSlot].angle =
                (gSpriteEntries[gGameWork.runningSpriteSlot].angle + 0x10) & 0x3FF;
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER]++;
    }
}

// Spins the other way for 90 frames.
void particle_spin_back_90(void) {
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER] == 0x5A) {
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_STATE]++;
    } else {
        if (gBattleWork.actorSideFlags & 1)
            gSpriteEntries[gGameWork.runningSpriteSlot].angle =
                (gSpriteEntries[gGameWork.runningSpriteSlot].angle - 0x10) & 0x3FF;
        else
            gSpriteEntries[gGameWork.runningSpriteSlot].angle =
                (gSpriteEntries[gGameWork.runningSpriteSlot].angle + 0x10) & 0x3FF;
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_TIMER]++;
    }
}

void medaforce_clear_hit_list(void) {
    u32 i;
    for (i = 0; i <= 2; i++) {
        gBattleWork.partBreaks[i] = 0;
        gBattleWork.partDamage[i] = 0;
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
        gParticleSparkHandlers[gSpriteEntries[i + 0x21].work[PARTICLE_STATE]]();
    }
}

// Spark state 1: every 8 frames (gGameWork.stepTimer) launches a spark from near the emitter toward a point
// just in front of it.
void particle_spark_emitter(void) {
    u32 roll, slot;
    struct SpriteEntry *particle;
    struct SpriteEntry *base;

    if ((roll = gGameWork.stepTimer & 7) == 0) {
        slot = find_next_free_sprite_slot(gGameWork.runningSpriteSlot + 1, 10);
        clear_battle_sprite_slot(slot, 1);
        base = gSpriteEntries;
        particle = &base[slot];
        particle->flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_AFFINE |
                          SPRITE_FLAG_PART_PALETTE;
        particle->frame_table = 0;
        particle->x = 0x78;
        particle->y = 0x78;
        particle->scale_x = 0x40;
        particle->scale_y = 0x40;
        particle->angle = roll;
        particle->palette = 6;
        particle->order = 0xF0;
        particle->frame = 0x7706;
        particle->work[PARTICLE_STATE] = 2;
        particle->work[SPR_MOTION_TABLE] = 3;
        particle->work[PARTICLE_SPARK_PARAM] = 0;
        roll = rng_next_byte() & 3;
        if (!(gBattleWork.actorSideFlags & 1)) {
            particle->x = (base[gGameWork.runningSpriteSlot].x + gParticleSparkOffsets[roll << 1]) & 0x1FF;
            particle->y = (base[gGameWork.runningSpriteSlot].y + gParticleSparkOffsets[roll * 2 + 1]) & 0xFF;
            particle->work16[PARTICLE_TARGET_X] = base[gGameWork.runningSpriteSlot].x + 0x10;
            particle->work16[PARTICLE_TARGET_Y] = base[gGameWork.runningSpriteSlot].y + 4;
        } else {
            particle->x = (0xF0 - (base[gGameWork.runningSpriteSlot].x + gParticleSparkOffsets[roll << 1])) & 0x1FF;
            particle->y = (base[gGameWork.runningSpriteSlot].y + gParticleSparkOffsets[roll * 2 + 1]) & 0xFF;
            particle->work16[PARTICLE_TARGET_X] = base[gGameWork.runningSpriteSlot].x - 0x10;
            particle->work16[PARTICLE_TARGET_Y] = base[gGameWork.runningSpriteSlot].y + 6;
        }
    }
}

// Spark state 2: spins and flies to its target, then disappears.
void particle_spark_fly(void) {
    gSpriteEntries[gGameWork.runningSpriteSlot].angle =
        (gSpriteEntries[gGameWork.runningSpriteSlot].angle + 0x10) & 0x3FF;
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
        if (gSpriteEntries[i + 0x21].work[PARTICLE_STATE])
            done = 0;
        state = gSpriteEntries[i + 0x21].work[PARTICLE_STATE];
        gParticleShotHandlers[state]();
    }
    return done;
}

// Shot state 1: flies to the target; on arrival plays the impact animation and starts a second impact sprite
// 3 slots on (state 3).
void particle_shot_fly(void) {
    if (move_sprite_toward_target(gGameWork.runningSpriteSlot)) {
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x6B], gGameWork.runningSpriteSlot);
        gSpriteEntries[gGameWork.runningSpriteSlot].palette = 6;
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_SHAKE_FRAME] = 0;
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_STATE]++;
        copy_bytes(&gSpriteEntries[gGameWork.runningSpriteSlot], &gSpriteEntries[gGameWork.runningSpriteSlot + 3],
                   0x40);
        battle_sprite_anim_init(gBattleSpriteAnimScripts[0x6C], gGameWork.runningSpriteSlot + 3);
        gSpriteEntries[gGameWork.runningSpriteSlot + 3].order =
            (gGameWork.runningSpriteSlot + (gBattleWork.targetSideFirst + 0xDF)) * 4 + 0x59;
        gSpriteEntries[gGameWork.runningSpriteSlot + 3].work[PARTICLE_STATE] = 3;
    }
}

// Shot state 2: shakes the hit Medabot's sprite up and down until the impact animation ends.
void particle_shot_shake_target(void) {
    gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_SHAKE_FRAME]++;
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_SHAKE_FRAME] & 2)
        gSpriteEntries[((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21))) * 4 + 0x5D].y =
            gBattleWork.botPositions[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21))].y + 2;
    else
        gSpriteEntries[((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21))) * 4 + 0x5D].y =
            gBattleWork.botPositions[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21))].y + 4;
    target_cursor_place_markers((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21)));
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x6B], gGameWork.runningSpriteSlot);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SPR_CMD_STATE] == SPR_CMD_ENDED) {
        gSpriteEntries[((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21))) * 4 + 0x5D].y =
            gBattleWork.botPositions[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21))].y + 4;
        target_cursor_place_markers((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21)));
        clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
    }
}

void particle_play_anim_then_free(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x6C], gGameWork.runningSpriteSlot);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SPR_CMD_STATE] == SPR_CMD_ENDED)
        clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
}

u32 particle_run_sweep_handlers(void) {
    u32 done = 1;
    u32 i;
    u32 state;

    for (i = 0; i <= 0x1A; i++) {
        gEffectSpriteSlot = i + 0x21;
        if (gSpriteEntries[i + 0x21].work[PARTICLE_STATE])
            done = 0;
        state = gSpriteEntries[i + 0x21].work[PARTICLE_STATE];
        gParticleSweepHandlers[state]();
    }
    return done;
}

// Sweep state 1: moves 4 px a frame across the screen; passing a Medabot that takes damage (partDamage) plays a
// hit sound and starts a hit sprite 3 slots on. Freed after 41 frames.
void particle_sweep_across(void) {
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x6D], gGameWork.runningSpriteSlot);
    if (!(gBattleWork.actorSideFlags & 1)) {
        gSpriteEntries[gGameWork.runningSpriteSlot].x = (gSpriteEntries[gGameWork.runningSpriteSlot].x + 4) & 0x1FF;
        if (gSpriteEntries[gGameWork.runningSpriteSlot].x >
                gSpriteEntries[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21)) * 4 + 0x5D].x &&
            gBattleWork.partDamage[gGameWork.runningSpriteSlot - 0x21] != 0 &&
            gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_SWEEP_HIT] == 0) {
            play_sound_effect(0x54);
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].flags =
                SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE | SPRITE_PRIORITY(1) | SPRITE_FLAG_PART_PALETTE;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].frame_table = 0;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].x =
                gSpriteEntries[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21)) * 4 + 0x5D].x;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].y =
                gSpriteEntries[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21)) * 4 + 0x5D].y - 4;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].palette = 6;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].order = 0xF1;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].work[PARTICLE_STATE] = 2;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].work[PARTICLE_SWEEP_HIT] = 0;
            battle_sprite_anim_init(gBattleSpriteAnimScripts[0x6E], gGameWork.runningSpriteSlot + 3);
            gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_SWEEP_HIT] = 1;
        }
    } else {
        gSpriteEntries[gGameWork.runningSpriteSlot].x = (gSpriteEntries[gGameWork.runningSpriteSlot].x - 4) & 0x1FF;
        if (gSpriteEntries[gGameWork.runningSpriteSlot].x <
                gSpriteEntries[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21)) * 4 + 0x5D].x &&
            gBattleWork.partDamage[gGameWork.runningSpriteSlot - 0x21] != 0 &&
            gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_SWEEP_HIT] == 0) {
            play_sound_effect(0x54);
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].flags = SPRITE_FLAG_ENABLED | SPRITE_FLAG_VISIBLE |
                                                                    SPRITE_FLAG_HFLIP | SPRITE_PRIORITY(1) |
                                                                    SPRITE_FLAG_PART_PALETTE;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].frame_table = 0;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].x =
                gSpriteEntries[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21)) * 4 + 0x5D].x;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].y =
                gSpriteEntries[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x21)) * 4 + 0x5D].y - 4;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].palette = 6;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].order = 0xF1;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].work[PARTICLE_STATE] = 2;
            gSpriteEntries[gGameWork.runningSpriteSlot + 3].work[PARTICLE_SWEEP_HIT] = 0;
            battle_sprite_anim_init(gBattleSpriteAnimScripts[0x6E], gGameWork.runningSpriteSlot + 3);
            gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_SWEEP_HIT] = 1;
        }
    }
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_SWEEP_TIMER] > 0x28)
        clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
    else
        gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_SWEEP_TIMER]++;
}

// Sweep state 2: shakes the hit Medabot's sprite sideways until the hit animation ends.
void particle_sweep_shake_target(void) {
    gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_SHAKE_FRAME]++;
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[PARTICLE_SHAKE_FRAME] & 2)
        gSpriteEntries[((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x24))) * 4 + 0x5D].x =
            gBattleWork.botPositions[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x24))].x + 2;
    else
        gSpriteEntries[((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x24))) * 4 + 0x5D].x =
            gBattleWork.botPositions[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x24))].x - 2;
    target_cursor_place_markers((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x24)));
    process_sprite_anim_commands(gBattleSpriteAnimScripts[0x6E], gGameWork.runningSpriteSlot);
    if (gSpriteEntries[gGameWork.runningSpriteSlot].work[SPR_CMD_STATE] == SPR_CMD_ENDED) {
        gSpriteEntries[((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x24))) * 4 + 0x5D].x =
            gBattleWork.botPositions[(gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x24))].x;
        target_cursor_place_markers((gBattleWork.targetSideFirst + (gGameWork.runningSpriteSlot - 0x24)));
        clear_battle_sprite_slot(gGameWork.runningSpriteSlot, 1);
    }
}
