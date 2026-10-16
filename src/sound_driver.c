#include "global.h"

INCLUDE_ASM("asm/nonmatching/sound_driver", sound_engine_tick);

u16 sub_08073140(u32 idx)
{
    return gUnk_083AB9D0[idx];
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_read_pending_note);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_set_note_attributes);
INCLUDE_ASM("asm/nonmatching/sound_driver", update_wave_channel_params);
INCLUDE_ASM("asm/nonmatching/sound_driver", update_sound_channel_frequency_08073244);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_update_frequency);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_update_channel3_frequency);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_check_note_change);
INCLUDE_ASM("asm/nonmatching/sound_driver", update_sound_channel_frequency_080733AC);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_update_channel_output_routing);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel1_update);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_process_tone);
INCLUDE_ASM("asm/nonmatching/sound_driver", update_wave_channel);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_update_channel_3);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_update_note_08073698);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_6_update_note);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_7_update_note);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_update_master_volume);
INCLUDE_ASM("asm/nonmatching/sound_driver", load_wave_pattern);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_init_wave_channel);
INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08073940);
INCLUDE_ASM("asm/nonmatching/sound_driver", configure_sound_channel);
INCLUDE_ASM("asm/nonmatching/sound_driver", timer_control_set_mode);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_volume_lookup);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_volume_scale);
INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08073A84);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_calculate_playback_rate);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_set_pitch_offset);

void sub_08073AE4(u32 val)
{
    gUnk_03007014->unk720 = val;
}

void sub_08073AF8(u32 val)
{
    gUnk_03007014->unk724 = val;
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_stop_08073B0C);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_configure_mixing_channel);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_play);
INCLUDE_ASM("asm/nonmatching/sound_driver", init_sound_channel_struct);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_restart_channel);

void sub_08073CA4(struct UnkSound_08073CA4 *ch)
{
    ch->unk3E = 3;
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_init_full);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_setup);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_start_channel_full);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_setup_alt);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_trigger_pending);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_request_stop);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_state_dispatch);

void sub_08073EAC(void)
{
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_tick);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_tick_both_channels);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_update_channel_at_690);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_update_channel_at_6d8);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_update);
INCLUDE_ASM("asm/nonmatching/sound_driver", clear_sound_channel_wave_data);
INCLUDE_ASM("asm/nonmatching/sound_driver", sub_080740AC);
INCLUDE_ASM("asm/nonmatching/sound_driver", sub_080740D4);
INCLUDE_ASM("asm/nonmatching/sound_driver", sub_080743C8);
INCLUDE_ASM("asm/nonmatching/sound_driver", init_sound_channel);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_stop_channel_by_index);
INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08074548);
INCLUDE_ASM("asm/nonmatching/sound_driver", process_tone_channel_if_idle);
INCLUDE_ASM("asm/nonmatching/sound_driver", sub_0807458C);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_tick_channel_3a);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_update_channel1_with_fallback);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_update_channel2_with_fallback);
INCLUDE_ASM("asm/nonmatching/sound_driver", update_wave_channels_pair);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_update_wave_channels);
INCLUDE_ASM("asm/nonmatching/sound_driver", reset_sound_channel_if_idle);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_update_channel_finish);
INCLUDE_ASM("asm/nonmatching/sound_driver", reset_sound_channel_at_690);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_reset_channel_9_and_stop_12);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_tick_channel_3c);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_reset);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_finish_and_callback);
INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08074800);
INCLUDE_ASM("asm/nonmatching/sound_driver", audio_unlink_channel_node);
INCLUDE_ASM("asm/nonmatching/sound_driver", init_all_sound_channels);

void sub_08074900(u32 val)
{
    gUnk_03007014->unk688 = val;
}

INCLUDE_ASM("asm/nonmatching/sound_driver", load_song_channels);
INCLUDE_ASM("asm/nonmatching/sound_driver", play_song);
INCLUDE_ASM("asm/nonmatching/sound_driver", play_song_alt);
INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08074A94);
INCLUDE_ASM("asm/nonmatching/sound_driver", set_all_sound_channels_flag_0x40);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_update_with_lock);
INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08074B68);

void sub_08074BC4(u32 val)
{
    gUnk_03007014->unk68C = val;
}

INCLUDE_ASM("asm/nonmatching/sound_driver", play_sound_from_command);
INCLUDE_ASM("asm/nonmatching/sound_driver", play_sound_effect);
INCLUDE_ASM("asm/nonmatching/sound_driver", play_sound_effect_alt);
INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08074CEC);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_reset_channel_callbacks);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_reset_callbacks_with_lock);
INCLUDE_ASM("asm/nonmatching/sound_driver", get_sound_channel_position);
INCLUDE_ASM("asm/nonmatching/sound_driver", is_sound_playing_at_position);
INCLUDE_ASM("asm/nonmatching/sound_driver", is_sound_playing_with_lock);

void sub_08074E70(u32 val)
{
    gUnk_03007014->unk728 = val;
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08074E84);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_play_with_lock);
INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08074EF4);
INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08074F34);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_stop_all_with_fade_guard);
INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08074FB8);
INCLUDE_ASM("asm/nonmatching/sound_driver", audio_get_volume_and_tick_fade);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_set_volume);

struct Unk_03007014 *sub_080750CC(void)
{
    return gUnk_03007014;
}

