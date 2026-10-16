#include "global.h"

// Nesting counter at gUnk_03007014->unk730 around updates of the sound work area.
static inline void sound_lock(void)
{
    if (gUnk_03007014->unk730 < 0xFFFF)
        gUnk_03007014->unk730++;
}

static inline void sound_unlock(void)
{
    if (gUnk_03007014->unk730 != 0)
        gUnk_03007014->unk730--;
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sound_engine_tick);

u16 sub_08073140(u32 idx)
{
    return gUnk_083AB9D0[idx];
}

void sound_channel_read_pending_note(struct SoundTrack *track, u16 *out)
{
    if (track->unk50 & 8)
    {
        *out = track->unk54;
        track->unk50 &= ~8;
    }
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_set_note_attributes);
INCLUDE_ASM("asm/nonmatching/sound_driver", update_wave_channel_params);
INCLUDE_ASM("asm/nonmatching/sound_driver", update_sound_channel_frequency_08073244);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_update_frequency);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_update_channel3_frequency);

void sound_channel_check_note_change(struct SoundTrack *track, u16 *out)
{
    if (track->unk50 & 1)
    {
        *out = track->unk69 | 0x8000;
        track->unk50 &= ~1;
    }
}

INCLUDE_ASM("asm/nonmatching/sound_driver", update_sound_channel_frequency_080733AC);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_update_channel_output_routing);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel1_update);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_process_tone);
INCLUDE_ASM("asm/nonmatching/sound_driver", update_wave_channel);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_update_channel_3);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_update_note_08073698);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_6_update_note);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_7_update_note);

void sound_update_master_volume(void)
{
    struct Unk_03007014 *work = gUnk_03007014;

    if (work->unk72C & 1)
    {
        *(vu16 *)0x04000080 = (work->unk72D << 4) | 0xFF00 | work->unk72E;
        work->unk72C &= ~1;
    }
}

INCLUDE_ASM("asm/nonmatching/sound_driver", load_wave_pattern);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_init_wave_channel);

void sub_08073940(s32 n, u32 src)
{
    vu32 *dma = (vu32 *)(0x040000B0 + n * 12);
    dma[0] = src;
    dma[1] = (u32)gSoundFifoAddrs[n - 1];
    dma[2] = 0xF6400004;
}

INCLUDE_ASM("asm/nonmatching/sound_driver", configure_sound_channel);

void timer_control_set_mode(s32 n)
{
    vu16 *reg = gSoundFifoDmaCnt[n - 1];
    *reg = (*reg & 0x499F) | 0x8440;
    *reg = (*reg & 0x499F) | 0x440;
}

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

void sound_configure_mixing_channel(struct SoundMixChannel *ch)
{
    u32 route;

    if (gUnk_03007014->unk72C & 4)
        route = 3;
    else if (ch->unk40)
        route = ch->unk40;
    else
        route = ch->unk3F;
    *(vu16 *)0x04000082 = (*(vu16 *)0x04000082 & gUnk_083ABAC2[ch->unk3A - 1] & gUnk_083ABA88[ch->unk3A - 1])
                        | gUnk_083ABAB2[ch->unk3A - 1][route] | gUnk_083ABA8C[ch->unk3A - 1][ch->unk3C];
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_play);

void init_sound_channel_struct(struct SoundMixChannel *ch, u32 a1, u32 a2, u8 a3, u8 a4, u16 a5, u8 a6, u8 a7)
{
    ch->unk0 = a1;
    ch->unk8 = a2;
    ch->unkC = 0;
    ch->unk14 = 0;
    ch->unk34 = a5;
    ch->unk36 = 0;
    ch->unk38 = 0;
    ch->unk3B = a3;
    ch->unk3C = a4;
    ch->unk4 = 0;
    ch->unk10 = 0;
    ch->unk3F = a6;
    ch->unk40 = a7;
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sound_restart_channel);

void sub_08073CA4(struct SoundMixChannel *ch)
{
    ch->unk3E = 3;
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_init_full);

void sound_channel_setup(u32 a0, struct SoundMixChannel *ch, u32 a2, u32 a3, u32 a4, u32 a5, u8 a6, u8 a7)
{
    ch->unk3E = 0;
    ch->unk18 = a0;
    ch->unk1C = a2;
    ch->unk24 = a3;
    ch->unk28 = a4;
    ch->unk2C = a5;
    ch->unk30 = a6;
    ch->unk31 = a7;
    ch->unk3E = 1;
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sound_start_channel_full);

void sound_channel_setup_alt(u32 a0, struct SoundMixChannel *ch, u32 a2, u32 a3, u32 a4, u32 a5, u8 a6, u8 a7)
{
    ch->unk3E = 0;
    ch->unk18 = a0;
    ch->unk1C = a2;
    ch->unk20 = a3;
    ch->unk28 = a4;
    ch->unk2C = a5;
    ch->unk30 = a6;
    ch->unk31 = a7;
    ch->unk3E = 1;
}

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

u8 sub_080740AC(struct SoundTrack *track)
{
    u8 *buf = track->unk8;
    s32 i;

    if (buf == NULL)
        return 0xFF;
    i = buf[0x30] - track->unk6B;
    if (i < 0)
        i += 0x30;
    return buf[i];
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sub_080740D4);

u32 sub_080743C8(void)
{
    return (gUnk_03007014->unk72C >> 1) & 1;
}

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

void sound_channel_reset(struct SoundTrack *track)
{
    track->unk14 = 0;
    track->unk54 = 0;
    track->unk6B = 0;
    track->envVolume = 0;
    track->unk48 = 0xFF;
    track->unk50 |= 0xA;
    track->unk6D = 0;
    track->unk58 = 0;
    track->unk38 = 0;
    track->unk4E = 0xFFFF;
    track->unk44 = 0;
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_finish_and_callback);

void sub_08074800(struct SoundTrack *track)
{
    struct SoundTrack **head;

    if (track->unk4 == NULL && track->unk0 == NULL)
    {
        head = &gUnk_03007014->unk5E4;
        if (*head == NULL)
        {
            track->unk4 = track;
            track->unk0 = track;
        }
        else
        {
            struct SoundTrack *prev = (*head)->unk0;

            track->unk0 = prev;
            track->unk4 = *head;
            prev->unk4 = track;
            track->unk4->unk0 = track;
        }
        *head = track;
    }
}

void audio_unlink_channel_node(struct SoundTrack *track)
{
    struct SoundTrack **head;

    if (track->unk4 != NULL || track->unk0 != NULL)
    {
        head = &gUnk_03007014->unk5E4;
        if ((*head)->unk4 == *head)
        {
            *head = NULL;
        }
        else
        {
            track->unk0->unk4 = track->unk4;
            track->unk4->unk0 = track->unk0;
            if (*head == track)
                *head = track->unk4;
        }
        track->unk4 = NULL;
        track->unk0 = NULL;
    }
}

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

void sub_08074E70(struct SoundNoteTable *val)
{
    gUnk_03007014->unk728 = val;
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08074E84);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_play_with_lock);
INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08074EF4);
INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08074F34);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_stop_all_with_fade_guard);

u32 sub_08074FB8(void)
{
    u32 ret = 0;
    struct Unk_03007014 *work = gUnk_03007014;

    if (work->tracks[0].unk44 || work->tracks[1].unk44 || work->tracks[2].unk44
     || work->tracks[3].unk44 || work->tracks[8].unk44 || work->tracks[9].unk44)
        ret = 1;
    return ret;
}

void audio_get_volume_and_tick_fade(u32 *a, u32 *b)
{
    sound_lock();
    *a = gUnk_03007014->unk72D;
    *b = gUnk_03007014->unk72E;
    sound_unlock();
}

void sound_set_volume(u32 a, u32 b)
{
    sound_lock();
    gUnk_03007014->unk72D = a;
    gUnk_03007014->unk72E = b;
    gUnk_03007014->unk72C |= 1;
    sound_unlock();
}

struct Unk_03007014 *sub_080750CC(void)
{
    return gUnk_03007014;
}

