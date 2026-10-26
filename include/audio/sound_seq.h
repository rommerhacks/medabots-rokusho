#ifndef GUARD_AUDIO_SOUND_SEQ_H
#define GUARD_AUDIO_SOUND_SEQ_H

// Sound sequencer: engine init, per-track volume envelope, vibrato / pitch sweep and sequence commands.

u32 sound_env_check_release(struct SoundTrack *track);
void sub_08072658(struct SoundTrack *track);
void sound_channel_update_pitch_sweep(struct SoundTrack *track);
u32 sub_08072708(struct SoundTrack *track);
void sound_engine_init(struct Unk_03007014 *work);
void sound_env_off(struct SoundTrack *track);
void sound_env_start_release(struct SoundTrack *track);
void sound_env_tick_release(struct SoundTrack *track);
void sound_env_start_sustain(struct SoundTrack *track);
void sound_env_start_decay(struct SoundTrack *track);
void sound_env_start_attack(struct SoundTrack *track);
void sound_env_key_on(struct SoundTrack *track);
void sound_env_tick_delay(struct SoundTrack *track);
void sound_env_tick_attack(struct SoundTrack *track);
void sound_env_tick_decay(struct SoundTrack *track);
void sound_env_tick_sustain(struct SoundTrack *track);
void sub_08072984(struct SoundTrack *track, u8 val);
void sub_080729A0(struct SoundTrack *track, u8 val);
void sub_080729A8(struct SoundTrack *track, u32 val);
void sound_env_update(struct SoundTrack *track);
void sound_channel_process_command_08072E04(struct SoundTrack *track);
void sound_channel_process_event(struct SoundTrack *track);
void sub_08072948(struct SoundTrack *track);
void sub_080729BC(struct SoundTrack *track);
void sub_080729D8(struct SoundTrack *track, u32 val);
void sub_080729EC(struct SoundTrack *track);
void sub_080729FC(struct SoundTrack *track);
void sub_08072A18(struct SoundTrack *track);
void sub_08072A34(struct SoundTrack *track);
void sub_08072A40(struct SoundTrack *track);
void sub_08072A54(struct SoundTrack *track);
void sub_08072A6C(struct SoundTrack *track);
void sub_08072A80(struct SoundTrack *track);
void stream_read_u32_to_field(struct SoundTrack *track);
void stream_read_and_shift_u32(struct SoundTrack *track);
void sub_08072ABC(struct SoundTrack *track);
void sub_08072AC4(struct SoundTrack *track);
void sub_08072AEC(struct SoundTrack *track);
void sub_08072AFC(struct SoundTrack *track);
void sub_08072B28(struct SoundTrack *track);
void sound_read_envelope_params(struct SoundTrack *track);
void sound_channel_enable(struct SoundTrack *track);
void sound_channel_disable(struct SoundTrack *track);
void sub_08072BD4(struct SoundTrack *track);
void sub_08072BE4(struct SoundTrack *track);
void sound_channel_update_note_08072798(struct SoundTrack *track, u8 cmd);
void sound_set_channel_note(struct SoundTrack *track, u8 note);
void sub_0807255C(struct SoundTrack *track);
void sub_080725BC(struct SoundTrack *track);
void sound_engine_update_all_channels(void);
void sound_channel_advance_sequence(struct SoundTrack *track);

#endif // GUARD_AUDIO_SOUND_SEQ_H
