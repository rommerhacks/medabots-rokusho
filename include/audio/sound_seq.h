#ifndef GUARD_AUDIO_SOUND_SEQ_H
#define GUARD_AUDIO_SOUND_SEQ_H

// Sound sequencer: engine init, per-track volume envelope, vibrato / pitch sweep and sequence commands.

void sound_engine_init(struct SoundWork *work);
void sound_vibrato_start_direct(struct SoundTrack *track);
void sound_engine_update(void);

#endif // GUARD_AUDIO_SOUND_SEQ_H
