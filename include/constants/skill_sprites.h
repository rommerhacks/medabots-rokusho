#ifndef GUARD_CONSTANTS_SKILL_SPRITES_H
#define GUARD_CONSTANTS_SKILL_SPRITES_H

// SpriteEntry.work[] / work16[] indices of the battle effect sprites (skill, Medaforce and action step effects)
// and of the other battle-screen sprites. The engine-wide ones (SPR_CMD_*, SPR_ANIM_*, SPR_MOTION_*, SPR_WALK_*)
// are in constants/sprites.h; an index can mean different things to different effects.

// Effect sprites, shared helpers and effect steps.
#define FX_SPR_FLAG 0x0 // one-shot flag of the effect (status attack flash: 1 once grown, now shrinking)
#define FX_SPR_STEP                                                                                                    \
    0x3                   // step in a per-frame offset table: sprite_hop_step, sprite_slide_x_step, sprite_bob_step,
                          // advance_sprite_anim_frame, effect_sprite_fly_to_part; 0 restarts the motion
#define FX_SPR_FRAMES 0x7 // frames counted by the current effect step (pulse / slide / blink / hop lengths)
#define FX_SPR_DELAY 0xC  // frames before a staggered sprite starts its animation (staggered_sprites_*, hit sparks)
#define FX_SPR_TIMER 0xD  // frame counter, cleared at spawn (scout beam: spins 0x40 frames)
#define FX_SPR_ANIM 0xE   // gBattleSpriteAnimScripts index the sprite plays (Cancel Status emblem)
#define FX_SPR_SPIN_SPEED 0xE // Spy Game beam: angle step / 16, +1 every full turn, done at 5

// Flying to a point with move_sprite_toward_target: direction in SPR_MOTION_ROW, motion table in SPR_MOTION_TABLE.
#define FX_SPR_TARGET_X 0 // work16: target x
#define FX_SPR_TARGET_Y 1 // work16: target y
// Accelerated vertical moves (sprite_move_toward_target falls, update_sprite_deceleration rises).
#define FX_FALL_ACCEL 0x4 // added to FX_FALL_SPEED every frame
#define FX_FALL_FRAC 0x5  // quarter-pixel remainder of the move
#define FX_FALL_SPEED 0   // work16: index into gSpriteSpeedSteps (0-0xFF)
// MISS!! popup (attack_miss_sprite_*).
#define FX_SPR_LAND_Y 0 // work16: y where the dropping popup stops

// Sprites circling a point with calc_polar_to_screen_coords (defence shields, heal rings, Force Bind orbs).
#define FX_ORBIT_RADIUS 0xB
#define FX_ORBIT_ANGLE 0xC // 256 steps per turn
#define FX_ORBIT_TIMER 0xD // frames since the orbit started
// Sprites run by the particle handlers (particle_run_*_handlers) use PARTICLE_* from constants/battle_seq_sprites.h.
// Medaforce status orbs (inflict status, status restore, total recovery, full body repair) also set:
#define FX_ORB_EMBLEM 0x8 // inflict status: emblem (0 Movement, 1 Stop, 2 Bind, 3 Flow, 4 Chaos), else 0; not read

// Destroyer (medaforce_destroyer_*): swing path from gDestroyerSwingFrames.
#define FX_SWING_POS 0x3  // pair index in gDestroyerSwingFrames
#define FX_SWING_WAIT 0x8 // frames left on the current direction

// Counter / reaction sprite rising or dropping (reaction_rise / reaction_drop).
#define FX_REACT_MOVED 0xB  // pixels moved, done at 0x28
#define FX_REACT_FRAMES 0xC // frames counted (the rise moves every other frame)

// Status / buff / last-skill icons over the Medabots (status_sprites.c, slots 0x46 + rec * 3 + 0-2).
#define STATUS_SPR_ID 0x3 // buffType, statusType or lastActionSkill the icon shows

// Command ring icons (command_ring.c).
#define RING_SPR_ANGLE 0x0  // position on the ring (gCommandRingIconAngles)
#define RING_SPR_ROTATE 0x1 // frames of the current rotation, 7 per icon step
#define RING_SPR_BLINK 0x2  // frame counter of the selected icon's pulse / flash

// Pointer line from a Medabot to its panel (bot_pointer_line_*, slots 60+).
#define POINTER_SPR_ANIM_TIMER 0x1 // frames; the arrow frame advances every 4
#define POINTER_SPR_ANIM_FRAME 0x2 // 0-3, arrow frame
#define POINTER_SPR_SEGMENT 0x4    // segments moved: 0 = horizontal part, then it goes down
#define POINTER_SPR_RIGHT 0x5      // horizontal direction: nonzero right, 0 left
#define POINTER_SPR_LENGTH 0x6     // segments this arrow travels
#define POINTER_SPR_DELAY 0x7      // frames before this arrow starts moving
#define POINTER_SPR_MOVES 0x8      // 4-pixel moves made; every second one is a segment

// Target marker (sprite 9, target_marker_*): pulses the targeted part's sprite.
#define MARKER_SPR_PART 0x4   // targeted part + 1 (aiTargetPart), 0 = none
#define MARKER_SPR_BOT 0x5    // targeted Medabot + 1 (aiTargetBot)
#define MARKER_SPR_SHRINK 0x6 // 0 growing, 1 shrinking
#define MARKER_SPR_FRAMES 0x7 // frames of the current grow / shrink

// Number and text popups (battle_*_popup_*).
#define POPUP_SPR_DELAY 0x0 // frames before this character starts moving
#define POPUP_SPR_STEP 0x1  // index into gNumberPopupYSteps, done at 0x20; 0xFF = unused character

// Robattle start banner (robattle_start_banner, sprite 3).
#define BANNER_SPR_MOSAIC 0x0 // mosaic size, counts down from 8

// Battle result "NEW" sprite (sprite 1, afterbattle_pulse_new_sprite).
#define NEW_SPR_SHRINK 0x8 // 0 growing, 1 shrinking

// Link prize game ball (sprite 2, prize_game_*).
#define PRIZE_SPR_FRAC 0x0    // quarter-pixel remainder of the move
#define PRIZE_SPR_SPEED 0x4   // quarter pixels per frame
#define PRIZE_SPR_FALLING 0x5 // 0 rising, 1 falling
#define PRIZE_SPR_FRAMES 0x7  // frames of the rise; the speed drops every 4

#endif // GUARD_CONSTANTS_SKILL_SPRITES_H
