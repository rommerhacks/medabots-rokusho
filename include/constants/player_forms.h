#ifndef GUARD_CONSTANTS_PLAYER_FORMS_H
#define GUARD_CONSTANTS_PLAYER_FORMS_H

// gFieldWork.player_form: how the player looks and moves on the field (gPlayerFormSpriteSets picks the sprites).
// The vehicle forms toggle on and off (saved_player_form keeps the form to go back to). Values 3-5, 7, 8 and 0xD are
// the other disguise items of the item menu; 9 also plays the splash step sound. Runtime values come from the
// walkthrough (segment 64: the Landmotor drive and the costume in the sewer).

#define PLAYER_FORM_NORMAL 0
// Mini S. Wheel (Landmotor): no random encounter rolls; dropped on entering an area that forbids the car
#define PLAYER_FORM_CAR 1
#define PLAYER_FORM_SWIM 2       // Periscope (Aquamar)
#define PLAYER_FORM_HERO 5       // the Hero costume (put on by the underwater room's doors, seen at runtime)
#define PLAYER_FORM_RUBBEROBO 6  // the Rubberobo costume: item menu item 19, or put on by the sewer map script
#define PLAYER_FORM_MAP_WARP 0xB // while the map warp effect plays (field_map_warp_start_effect)
#define PLAYER_FORM_TELEPORT 0xC // while the teleport effect plays (field_teleport_start_effect; guess: effect only)

#endif // GUARD_CONSTANTS_PLAYER_FORMS_H
