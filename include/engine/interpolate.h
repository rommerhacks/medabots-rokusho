#ifndef GUARD_ENGINE_INTERPOLATE_H
#define GUARD_ENGINE_INTERPOLATE_H

// Per-frame interpolation of entity positions toward keyframes

s32 interpolate_entity_positions(struct InterpEnt *e, s16 *pos, s8 *off, u8 *tbl, u8 unused, u8 frame, u8 idx,
                                 s32 count, s32 stride);

#endif // GUARD_ENGINE_INTERPOLATE_H
