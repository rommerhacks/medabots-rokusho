#ifndef GUARD_CONSTANTS_BATTLE_SEQ_SPRITES_H
#define GUARD_CONSTANTS_BATTLE_SEQ_SPRITES_H

// SpriteEntry.work[] / work16[] indices of the battle sequence sprites (battle/battle_sequence), the Medaforce
// particles (battle/particles) and a few battle UI sprites (battle/battle_graphics). Sequence and particle sprites
// that play gBattleSpriteAnimScripts streams also use SPR_CMD_* (0x0-0x2), and moving ones SPR_MOTION_* (0x4, 0x5,
// 0x7), from constants/sprites.h.

// Battle sequence runner, sprite 0 (battle_sequence_update, battle_sequence_run_command, the battle_seq_cmd_*).
#define SEQ_RUN_OPCODE 0x9 // opcode of the current command (labels skipped)
#define SEQ_RUN_YIELD 0xA  // set by a command to stop running commands until the next frame
#define SEQ_RUN_WAIT 0     // work16: battle_seq_cmd_wait_frames frame counter

// Every sequence sprite 1-0x27.
#define SEQ_SPR_STATE 0x9 // index into gBattleSeqSpriteHandlers, 0 = idle
#define SEQ_SPR_ANIM 0xD  // gBattleSpriteAnimScripts index (effect, play_anim, trail, scale and ring sprites)

// Sprites 1 / 2 (left / right Medabot), states 1-3: actor_pose / target_pose and their _loop variants.
#define SEQ_POSE_QUEUED 0xB // a pose is queued (cleared when the current pose finished)
#define SEQ_POSE_ID 0xC     // the queued pose
#define SEQ_POSE_LOOP 0xD   // non-zero: restart the pose each time it finishes (state 3)
#define SEQ_POSE_DELAY 0    // work16: frames before the pose starts

// Sprite 3, state 8: actor_dash.
#define SEQ_DASH_SPEED 0xB // pixels per frame
#define SEQ_DASH_SIDE 0xC  // 0 the left Medabot runs right, 1 the right one runs left
#define SEQ_DASH_X 0       // work16: the runner's x on the field (before scrolling)

// Sprite 3, state 9: actor_move (speed / direction in SPR_MOTION_TABLE / SPR_MOTION_ROW).
#define SEQ_MOVE_SIDE 0xC   // 0 moves the left Medabot, 1 the right one
#define SEQ_MOVE_FRAMES 0xD // frames left to move

// Sprites 4 / 0x23, states 0x10-0x13: BG0 tile effects (bg_effect*, bg_sweep).
#define SEQ_BG_TILE_ANIM 0xB    // gBattleSeqTileAnims index
#define SEQ_BG_TILEMAP 0xC      // gUiTilemaps index (+ 2 for the mirrored variant)
#define SEQ_BG_NO_DRAW 0xD      // bg_effect*: non-zero skips writing the tilemap (always 0)
#define SEQ_BG_SWEEP_COLUMN 0xD // bg_sweep: columns drawn so far
#define SEQ_BG_WIDTH 0xE        // tilemap rectangle width in tiles
#define SEQ_BG_HEIGHT 0xF       // tilemap rectangle height in tiles
#define SEQ_BG_SWEEP_STOP 0x7   // bg_sweep: set by bg_sweep_stop, no more columns
#define SEQ_BG_SWEEP_FRAME 0x8  // bg_sweep: frame counter (a column every other frame)
#define SEQ_BG_DELAY 0          // work16: frames before the effect starts

// Sprites 5+, state 0x18: sound / leg_sound.
#define SEQ_SOUND_ID 0xB       // sound effect
#define SEQ_SOUND_WAIT 0xC     // frames until the next play
#define SEQ_SOUND_INTERVAL 0xD // frames between plays
#define SEQ_SOUND_COUNT 0xE    // plays left
#define SEQ_SOUND_DELAY 0      // work16: frames before the first play

// Sprite 0x1E, states 0xA / 0xC: camera_track / camera_track_all (speed / direction in SPR_MOTION_*).
#define SEQ_CAMERA_DELAY 0xB // frames before the camera point moves
#define SEQ_CAMERA_X 0       // work16: the camera point's x on the field (before scrolling)

// Effect sprites 0xA-0x12, states 0xB / 0xD / 0xE / 0x30 / 0x31: spawn_effect*, spawn_orbit (motion in SPR_MOTION_*).
#define SEQ_EFFECT_WAVE_STEP 0x3  // state 0xD: gBattleSeqWaveOffsets index, 0-0x1F
#define SEQ_ORBIT_ANGLE 0x6       // state 0x31: angle around sprite 0xA
#define SEQ_EFFECT_MOVE_DELAY 0xB // frames before the sprite starts moving
#define SEQ_EFFECT_SHOW_DELAY 0xC // frames before the sprite appears and animates
#define SEQ_EFFECT_TILE_ANIM 0xE  // state 0xE: gBattleSeqTileAnims index (also set by set_tile_anim)

// States 0x20 / 0x21: play_anim.
#define SEQ_PLAY_DELAY 0xB // frames before the animation starts
#define SEQ_PLAY_SLOT 0xE  // sprite slot that plays the animation (state 0x21)

// Sprites 0xC / 0xD, state 0x22: trail spawner (puffs: state 0x23).
#define SEQ_TRAIL_PALETTE 0x7  // puff palette
#define SEQ_TRAIL_COUNTER 0x8  // frames since the last puff
#define SEQ_TRAIL_DELAY 0xB    // frames before the first puff
#define SEQ_TRAIL_INTERVAL 0xC // a puff every SEQ_TRAIL_INTERVAL + 1 frames
#define SEQ_TRAIL_SOURCE 0xE   // slot of the sprite followed
#define SEQ_TRAIL_OFFSET_X 0   // work16: puff x offset from the source (negated when mirrored)
#define SEQ_TRAIL_OFFSET_Y 1   // work16: puff y offset from the source

// Sprite 0x27, states 0x28 / 0x29: palette_fade.
#define SEQ_FADE_DELAY 0xB // frames before the fade
#define SEQ_FADE_RED 0xC   // target colour, 0-0x1F per component
#define SEQ_FADE_GREEN 0xD
#define SEQ_FADE_BLUE 0xE
#define SEQ_FADE_LEVEL 0xF // blend amount, 0-0x10

// State 0x34: scale_sprite.
#define SEQ_SCALE_GROW 0x3 // 0 shrinks until gone, else grows to SPRITE_SCALE_ONE
#define SEQ_SCALE_STEP 0x6 // scale change per frame

// Sprites 0xB-0x12, state 0x36: spawn_ring.
#define SEQ_RING_EXPAND 0x3 // 0 the radius shrinks, else grows (every other frame)
#define SEQ_RING_ANGLE 0x6  // angle around sprite 0xA
#define SEQ_RING_RADIUS 0x7
#define SEQ_RING_FRAME 0xB // frame counter

// Sprite 9, state 0x38: armor_panel.
#define SEQ_ARMOR_DELAY 0xB       // frames before the panel is drawn
#define SEQ_ARMOR_DRAIN_DELAY 0xC // frames between drawing and draining
#define SEQ_ARMOR_SIDE 0xD        // 0 left panel, 1 right (mirrored)
#define SEQ_ARMOR_REDRAW 0xE      // non-zero: the panel still has to be drawn

// Sprites 0xA / 0xB, state 0x3A: show_rolls.
#define SEQ_ROLL_HOP_STEP 0x3 // sprite_hop_step position
#define SEQ_ROLL_ANIM 0x6     // gBattleSpriteAnimScripts index
#define SEQ_ROLL_DIGIT 0x8    // digit shown when the hop ends

// Medaforce particles 0x21-0x3B (battle/particles: gParticleOrbitHandlers, gParticleSparkHandlers,
// gParticleShotHandlers, gParticleSweepHandlers).
#define PARTICLE_STATE 0x9        // index into the handler table, 0 = idle; each state bumps it when done
#define PARTICLE_TIMER 0xD        // frame counter of the orbit / wait / sway / spin states
#define PARTICLE_ANIM 0xE         // orbit states: gBattleSpriteAnimScripts index
#define PARTICLE_ORBIT_RADIUS 0xB // orbit: radius, pulsing by gParticleOrbitRadiusSteps
#define PARTICLE_ORBIT_ANGLE 0xC  // orbit: angle around the centre
#define PARTICLE_SPARK_PARAM 0x3  // spark: set to 0, not read by the spark handlers
#define PARTICLE_SWEEP_TIMER 0x7  // sweep: frames moved (freed after 0x28)
#define PARTICLE_SWEEP_HIT 0x8    // sweep: set once the hit sprite was started
#define PARTICLE_SHAKE_FRAME 0x8  // shot / sweep state 2: frame counter of the target shake
#define PARTICLE_TARGET_X 0       // work16: move_sprite_toward_target destination
#define PARTICLE_TARGET_Y 1       // work16

// Target arrows, sprites 0x78-0x7F (battle/battle_graphics: target_arrows_*).
#define TARGET_ARROW_ANIM_TIMER 0x1 // frame counter, the frame advances every 4
#define TARGET_ARROW_ANIM_FRAME 0x2 // 0-3
#define TARGET_ARROW_STEPS 0x4      // steps moved
#define TARGET_ARROW_DISTANCE 0x6   // steps to move
#define TARGET_ARROW_DELAY 0x7      // frames before moving
#define TARGET_ARROW_MOVE_FRAME 0x8 // frames moved (a step every 2, 4 px a frame)

// Medaforce charge sparkles, sprites 0x21-0x28 (battle/battle_graphics: mf_charge_sparkles_*).
#define MF_SPARKLE_ANGLE 0x0      // angle around the Medabot, -8 a frame
#define MF_SPARKLE_Y 0x1          // centre y, rising 1 px every 8 frames
#define MF_SPARKLE_RADIUS_ADD 0x6 // added to the radius 16
#define MF_SPARKLE_PARAM 0x7      // set to i * 4, not read by mf_charge_sparkles_update
#define MF_SPARKLE_FRAME 0x8      // frame counter

#endif // GUARD_CONSTANTS_BATTLE_SEQ_SPRITES_H
