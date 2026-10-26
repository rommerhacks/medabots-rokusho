#ifndef GUARD_AUDIO_SOUND_SEQ_H
#define GUARD_AUDIO_SOUND_SEQ_H

// Sound sequencer: engine init, per-track volume envelope, vibrato / pitch sweep and sequence commands.

void sound_engine_init(struct Unk_03007014 *work);
void sub_080725BC(struct SoundTrack *track);
void sound_engine_update_all_channels(void);

#endif // GUARD_AUDIO_SOUND_SEQ_H
