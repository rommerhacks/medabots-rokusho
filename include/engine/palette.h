#ifndef GUARD_ENGINE_PALETTE_H
#define GUARD_ENGINE_PALETTE_H

// Palette backup, fades and blends.

void palette_backup_from_hardware(void);
void palettes_blend_to_color(u16 color, u32 amount);
void palette_buffer_upload(void);

#endif // GUARD_ENGINE_PALETTE_H
