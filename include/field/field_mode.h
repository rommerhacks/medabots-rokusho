#ifndef GUARD_FIELD_FIELD_MODE_H
#define GUARD_FIELD_FIELD_MODE_H

// Field mode dispatcher, field RAM reset and transitions out of the field

void dispatch_by_index_0476e8(u32 idx);
void field_return_from_scene(s32 a);
void switch_game_mode(u32 a, u32 b);
void field_resume(u32 a);

#endif // GUARD_FIELD_FIELD_MODE_H
