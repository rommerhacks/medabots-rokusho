#ifndef GUARD_CONSTANTS_SPRITES_H
#define GUARD_CONSTANTS_SPRITES_H

// SpriteEntry.flags bits, from how check_flag_and_fast_copy reads them.
#define SPRITE_FLAG_MOSAIC 0x0001        // OAM attribute 0 mosaic bit
#define SPRITE_FLAG_OFFSCREEN 0x0002     // set by check_flag_and_fast_copy: world-mode sprite outside the screen
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
#define SPRITE_FLAG_ENABLED 0x8000 // processed (sorted, positioned) by check_flag_and_fast_copy

#define SPRITE_SCALE_ONE 0x40 // scale_x / scale_y of an unscaled sprite

#endif // GUARD_CONSTANTS_SPRITES_H
