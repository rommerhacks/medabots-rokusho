#ifndef GUARD_AUDIO_SOUND_DRIVER_H
#define GUARD_AUDIO_SOUND_DRIVER_H

// Sound driver: per-frame engine tick, note/frequency output to the GBA sound channels, music and sound-effect
// start/stop.

void sound_update_channel_at_690(void);
void sound_update_channel_at_6d8(void);
void sound_channel_finish_and_callback(struct SoundTrack *track);
void play_song(u32 id);
void play_sound_effect(u32 id);
u32 is_sound_playing_with_lock(u32 a);
void play_song(u32 id);
void sound_stop_all_with_fade_guard(u32 a);
u16 sub_08073140(u32 idx);
void init_all_sound_channels(void);
void sound_init_wave_channel(void);
u32 sound_set_pitch_offset(struct SoundMixChannel *ch, s32 note);
void sound_tick_both_channels(void);
void sound_engine_tick(void);
void sub_08074900(struct SoundSongHeader **val);
void sub_08074BC4(struct SoundSongHeader **val);
void sub_08074E70(struct SoundNoteTable *val);
void sub_08073AE4(u32 val);
void sub_08073AF8(u32 val);
void sound_channel1_update(struct SoundTrack *track);
void sound_channel_process_tone(struct SoundTrack *track);
void update_wave_channel(struct SoundTrack *track);
void sound_update_channel_3(struct SoundTrack *track);
void sound_channel_6_update_note(struct SoundTrack *track);
void sound_channel_7_update_note(struct SoundTrack *track);
void sub_080740D4(struct SoundTrack *track);
u32 sound_is_paused(void);
void sound_update_master_volume(void);
u32 sub_08074FB8(void);
u32 sub_08074B68(void);

#endif // GUARD_AUDIO_SOUND_DRIVER_H
