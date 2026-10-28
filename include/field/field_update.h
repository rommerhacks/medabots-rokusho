#ifndef GUARD_FIELD_FIELD_UPDATE_H
#define GUARD_FIELD_FIELD_UPDATE_H

// Field game mode: per-frame update, gFieldSubStates handlers, room graphics load

void load_room_graphics(void);
void field_sort_sprites_by_depth(void);
void clear_vram_tiles_1000(void);

#endif // GUARD_FIELD_FIELD_UPDATE_H
