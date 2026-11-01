#ifndef GUARD_CONSTANTS_MAP_OBJECTS_H
#define GUARD_CONSTANTS_MAP_OBJECTS_H

// Map object kinds: bits 12-15 of MapObject.event / MapNpcRecord.event (bits 0-11 are the event id). Seen at
// runtime in Hachiro Awano's house and on Rosewood's 2F (walkthrough segment 56): people are MAP_OBJ_NPC, the
// gate intercoms, display Medabots and the photograph are MAP_OBJ_EXAMINE, door and scene tiles MAP_OBJ_STEP.
#define MAP_OBJ_KIND_SHIFT 12
#define MAP_OBJ_KIND_MASK 0xF000
#define MAP_OBJ_EVENT_ID_MASK 0xFFF
#define MAP_OBJ_NPC 0      // sprite, blocks its tile, A runs its event; turns to the player and idles at random
#define MAP_OBJ_SPRITE 2   // sprite only: no collision, no event
#define MAP_OBJ_EXAMINE 4  // blocks its tile, A runs its event; keeps its facing (sprite optional)
#define MAP_OBJ_ANIMATED 6 // like MAP_OBJ_EXAMINE, its sprite animates every frame
#define MAP_OBJ_STEP 8     // no sprite or collision: stepping onto its tile runs its event

#endif // GUARD_CONSTANTS_MAP_OBJECTS_H
