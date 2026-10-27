#ifndef GUARD_ENGINE_MAIN_H
#define GUARD_ENGINE_MAIN_H

void vblank_irq(void);
void hblank_irq(void);
void empty_callback(void);
void clear_oam(void);
void hw_reset_init(void);
void irq_init(void);
void vblank_body(void);
void soft_reset(void);
void read_keys(void);
void sound_init(struct SoundWork *work);

#endif // GUARD_ENGINE_MAIN_H
