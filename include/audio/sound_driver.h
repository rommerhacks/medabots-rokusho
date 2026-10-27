#ifndef GUARD_AUDIO_SOUND_DRIVER_H
#define GUARD_AUDIO_SOUND_DRIVER_H

// Sound driver: per-frame engine tick, note/frequency output to the GBA sound channels, music and sound-effect
// start/stop.

void sound_mix_refill_fifo_a(void);
void sound_mix_refill_fifo_b(void);
void sound_track_stop(struct SoundTrack *track);
void play_song(u32 id);
void play_sound_effect(u32 id);
u32 is_sound_effect_playing(u32 a);
void play_song(u32 id);
void fade_out_music(u32 a);
u16 sound_psg_note_freq(u32 idx);
void sound_init_tracks(void);
void sound_init_wave_channel(void);
u32 sound_set_pitch_offset(struct SoundMixChannel *ch, s32 note);
void sound_mix_tick(void);
void sound_engine_tick(void);
void sound_set_song_table(struct SoundSongHeader **val);
void sound_set_se_table(struct SoundSongHeader **val);
void sound_set_drum_kit(struct SoundDrumKit *val);
void sound_set_instrument_samples(u32 val);
void sound_set_drum_samples(u32 val);
void sound_output_sq1(struct SoundTrack *track);
void sound_output_sq2(struct SoundTrack *track);
void sound_output_wave(struct SoundTrack *track);
void sound_output_noise(struct SoundTrack *track);
void sound_output_fifo_a(struct SoundTrack *track);
void sound_output_fifo_b(struct SoundTrack *track);
void sound_track_record_echo(struct SoundTrack *track);
u32 sound_is_paused(void);
void sound_update_master_volume(void);
u32 is_music_fading(void);
u32 sound_current_song(void);

#endif // GUARD_AUDIO_SOUND_DRIVER_H
