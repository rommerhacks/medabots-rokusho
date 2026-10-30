#ifndef GUARD_CONSTANTS_SPRITES_H
#define GUARD_CONSTANTS_SPRITES_H

// SpriteEntry.flags bits, from how build_sprite_oam reads them.
#define SPRITE_FLAG_MOSAIC 0x0001        // OAM attribute 0 mosaic bit
#define SPRITE_FLAG_OFFSCREEN 0x0002     // set by build_sprite_oam: world-mode sprite outside the screen
#define SPRITE_FLAG_PART_PALETTE 0x0004  // frame parts with palette bits in their tile keep that palette
#define SPRITE_FLAG_OBJ_MODE_MASK 0x0018 // OAM attribute 0 OBJ mode (semi-transparent / window), << 7
#define SPRITE_FLAG_DOUBLE_SIZE 0x0020   // affine double-size area
#define SPRITE_POS_MASK 0x00C0           // position mode:
#define SPRITE_POS_SCREEN 0x0000         //   x / y are screen coordinates
#define SPRITE_POS_WORLD 0x0040          //   x / y from pos_x / pos_y + pos_z minus the camera (gSpriteCameraPos)
#define SPRITE_POS_PERSPECTIVE 0x0080    //   x / y / scale projected from pos_x / pos_y / pos_z
#define SPRITE_POS_SHARED_AFFINE 0x00C0  //   screen coordinates, affine matrix affine_idx set up elsewhere
#define SPRITE_FLAG_ROTATE 0x0100        // rotate the parts' offsets by angle
#define SPRITE_FLAG_AFFINE 0x0200        // affine sprite (scale_x / scale_y / angle)
#define SPRITE_FLAG_PRIORITY_MASK 0x0C00 // OAM priority, << 10
#define SPRITE_FLAG_HFLIP 0x1000
#define SPRITE_FLAG_VFLIP 0x2000
#define SPRITE_FLAG_VISIBLE 0x4000 // drawn into OAM
#define SPRITE_FLAG_ENABLED 0x8000 // processed (sorted, positioned) by build_sprite_oam

#define SPRITE_OBJ_MODE(mode) ((mode) << 3)  // 1 semi-transparent, 2 OBJ window
#define SPRITE_PRIORITY(prio) ((prio) << 10) // OAM priority 0 (front) to 3

#define SPRITE_SCALE_ONE 0x40 // scale_x / scale_y of an unscaled sprite

// SpriteEntry.work[] indices with the same meaning in every module that uses the shared engine code.
// Animation command streams (battle_sprite_anim_init / process_sprite_anim_commands, opcodes 0xFB-0xFF):
#define SPR_CMD_WAIT 0x0  // frames left on the current frame
#define SPR_CMD_POS 0x1   // byte offset of the next 3-byte command
#define SPR_CMD_STATE 0x2 // SPR_CMD_ENDED once the end command (0xFF) ran
#define SPR_CMD_ENDED 0xFF
// Animation scripts (sprite_anim_start / advance_sprite_animation_frame, gSpriteAnimScripts):
#define SPR_ANIM_POS 0x2          // index of the current script command
#define SPR_ANIM_FRAMES 0x3       // frames the current command has been shown
#define SPR_ANIM_SCRIPT 0x4       // script id
#define SPR_ANIM_FRAME_OFFSET 0xF // added to the frame of command 0xFFFA
// Step motions (update_sprite_animation_position, gSpriteMotionSteps):
#define SPR_MOTION_TABLE 0x4 // 1-based table, 0 = no motion
#define SPR_MOTION_ROW 0x5
#define SPR_MOTION_STEP 0x7 // & 3 = step in the row
// Battle Medabot sprite groups walking in place (battle_sprite_group_set_anim,
// update_battle_sprite_orbiting_positions): body, arms, legs.
#define SPR_WALK_STEP 0x1  // 0-3: step of the walk cycle
#define SPR_WALK_SPEED 0x4 // added to SPR_WALK_PHASE every frame
#define SPR_WALK_PHASE 0x6 // 0-0x3F, the step advances when it wraps

// Robattle Medabot sprites: four gSpriteEntries per battle slot rec (0-2 player team, 3-5 opponents), set up by
// setup_battle_sprite_group. The legs sprite sits at the bot's position, so the battle code reads its x / y as
// where the bot stands; the head is drawn 8 px higher.
#define BOT_SPRITE_HEAD(rec) ((rec) * 4 + 0x5A)
#define BOT_SPRITE_RIGHT_ARM(rec) ((rec) * 4 + 0x5B)
#define BOT_SPRITE_LEFT_ARM(rec) ((rec) * 4 + 0x5C)
#define BOT_SPRITE_LEGS(rec) ((rec) * 4 + 0x5D)
// The bot's shadow, 8 px below the legs sprite (init_bot_shadow_sprite).
#define BOT_SPRITE_SHADOW(rec) ((rec) + 0x72)

#endif // GUARD_CONSTANTS_SPRITES_H
