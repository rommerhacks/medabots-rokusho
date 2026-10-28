#ifndef GUARD_CONSTANTS_FIELD_SPRITES_H
#define GUARD_CONSTANTS_FIELD_SPRITES_H

// SpriteEntry.work[] / work16[] indices of the field map sprites (player 47, follower 48, map objects 49-84),
// shared by the field modules. Index 4 is the animation script id (SPR_ANIM_SCRIPT, 0xFF = not animated).
#define FIELD_SPR_FACING 0x0 // facing / move direction: 0 up, 1 down, 2 left, 3 right
// facing of the last set_sprite_animation_state (a slide only changes FIELD_SPR_FACING)
#define FIELD_SPR_ANIM_FACING 0x1
#define FIELD_SPR_SCRIPT_FLAG 0x5  // player: set to 1 when a map script starts or ends and after a warp (never read)
#define FIELD_SPR_SCRIPT_STEP 0x6  // phase of a scripted hop / jump, or index in cmd_args of the current walk code
#define FIELD_SPR_STEPS_LEFT 0x7   // tiles left in a scripted walk
#define FIELD_SPR_STEP_TIMER 0x8   // frames left in the current tile step (walk), frames done (hop / jump)
#define FIELD_SPR_BLINK_PARAM 0x9  // written 8 by map_script_cmd_all_actors_blink, never read
#define FIELD_SPR_SPEED 0xA        // walk speed id (gWalkSpeedFactors, sprite_walk_speed)
#define FIELD_SPR_ANIM_SET 0xB     // animation / sprite set: walk animation set * 4 + facing, frames set * 12
#define FIELD_SPR_HEIGHT 0xC       // height above the ground during a hop / jump (shadow offset)
#define FIELD_SPR_BLINK_HIDDEN 0xD // 1 while a blink hides the sprite
#define FIELD_SPR_ON_SCREEN 0xE    // 1 while drawn (inside the screen and not hidden)
// work16[] indices
#define FIELD_SPR_SHEET 0    // sprite sheet id (area_sprite_sheet_id): shadow, blend kind, step sound
#define FIELD_SPR_FLAGS 1    // flags to show the sprite with (restored when on screen / after a blink)
#define FIELD_SPR_GROUND_Y 2 // ground y under a jumping sprite (pos_y = it minus the arc)

#endif // GUARD_CONSTANTS_FIELD_SPRITES_H
