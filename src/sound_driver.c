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

void sound_update_channel_3(struct SoundTrack *track)
{
    update_sound_channel_frequency_08073244(track, (vu16 *)0x04000078);
    sound_channel_check_note_change(track, (u16 *)0x0400007C);
    sound_update_channel_output_routing(track);
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_update_note_08073698);

void sound_channel_6_update_note(struct SoundTrack *track)
{
    sound_channel_update_note_08073698(track, &gUnk_03007014->unk690);
}

void sound_channel_7_update_note(struct SoundTrack *track)
{
    sound_channel_update_note_08073698(track, &gUnk_03007014->unk6D8);
}

void sound_update_master_volume(void)
{
    struct Unk_03007014 *work = gUnk_03007014;

    if (work->unk72C & 1)
    {
        *(vu16 *)0x04000080 = (work->unk72D << 4) | 0xFF00 | work->unk72E;
        work->unk72C &= ~1;
    }
}

void load_wave_pattern(u32 n)
{
    vu16 cnt;

    CpuSet(gSoundWavePatterns[n], (void *)0x04000090, 0x04000004);
    cnt = *(vu16 *)0x04000070;
    *(vu16 *)0x04000070 = (cnt == 0x80) ? 0xC0 : 0x80;
}

void sound_init_wave_channel(void)
{
    *(vu16 *)0x04000084 = 0x80;
    *(vu16 *)0x04000082 = 0x400E;
    *(vu16 *)0x04000070 = 0xC0;
    load_wave_pattern(0);
    sound_set_volume(7, 7);
}

// Streams samples from src into FIFO A (n = 1) or B (n = 2) with DMA n, timed by the sound FIFO.
void sound_start_fifo_dma(s32 n, u32 src)
{
    vu32 *dma = (vu32 *)(0x040000B0 + n * 12);
    dma[0] = src;
    dma[1] = (u32)gSoundFifoAddrs[n - 1];
    dma[2] = 0xF6400004;
}

void configure_sound_channel(s32 n, u32 *src)
{
    vu32 *fifo;
    u32 *p;
    s32 i;

    *(vu8 *)0x04000083 |= gSoundFifoResetBits[n - 1];
    fifo = gSoundFifoAddrs[n - 1];
    p = src;
    for (i = 7; i >= 0; i--)
        *fifo = *p++;
    sound_start_fifo_dma(n, (u32)(src + 8));
}

// Stops the FIFO DMA n.
void sound_stop_fifo_dma(s32 n)
{
    vu16 *reg = gSoundFifoDmaCnt[n - 1];
    *reg = (*reg & 0x499F) | 0x8440;
    *reg = (*reg & 0x499F) | 0x440;
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sound_semitone_ratio);

u32 sound_finetune_ratio(s32 n)
{
    s32 q;
    s32 rem;

    if (n == 0)
        return 0;
    q = n / 128;
    rem = n - q * 128;
    return (sound_semitone_ratio(q) * gSoundFinetuneRatios[rem]) >> 12;
}

u32 sound_apply_finetune(u32 rate, u32 fine)
{
    return fine ? (sound_finetune_ratio(fine) * rate) >> 12 : rate;
}

u32 sound_calculate_playback_rate(struct SoundMixChannel *ch, u32 ratio)
{
    struct SoundSampleHeader *smp = (struct SoundSampleHeader *)ch->unk0;
    u32 rate = sound_apply_finetune((smp->rate * ratio) >> 12, smp->fineTune);

    if (rate > 0x78000)
        rate = 0x78000;
    ch->unk4 = rate;
    return rate;
}

u32 sound_set_pitch_offset(struct SoundMixChannel *ch, s32 note)
{
    return sound_calculate_playback_rate(ch, sound_semitone_ratio(note - ((struct SoundSampleHeader *)ch->unk0)->baseNote));
}

void sub_08073AE4(u32 val)
{
    gUnk_03007014->unk720 = val;
}

void sub_08073AF8(u32 val)
{
    gUnk_03007014->unk724 = val;
}

void sound_channel_stop_08073B0C(struct SoundMixChannel *ch)
{
    if (*gSoundTimerRegs[ch->unk3A - 1] & 0x800000)
    {
        sound_stop_fifo_dma(ch->unk3A);
        *gSoundTimerRegs[ch->unk3A - 1] = 0;
        *(vu16 *)0x04000082 &= ~gSoundFifoEnableBits[ch->unk3A - 1];
    }
}

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

void sound_channel_play(struct SoundMixChannel *ch, u32 offset)
{
    sound_channel_stop_08073B0C(ch);
    if (ch->unk3C)
    {
        u8 *n;

        sound_configure_mixing_channel(ch);
        n = &ch->unk3A;
        configure_sound_channel(*n, (u32 *)&((struct SoundSampleHeader *)ch->unk0)->data[offset]);
        *gSoundTimerRegs[*n - 1] = ch->unk10;
    }
}

void init_sound_channel_struct(struct SoundMixChannel *ch, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u8 a6, u8 a7)
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

void sound_restart_channel(struct SoundMixChannel *ch)
{
    sound_channel_stop_08073B0C(ch);
    init_sound_channel_struct(ch, 0, 0, 0, 0, 0, 0, 0);
}

void sub_08073CA4(struct SoundMixChannel *ch)
{
    ch->unk3E = 3;
}

void sound_channel_init_full(struct SoundMixChannel *ch)
{
    sound_restart_channel(ch);
    init_sound_channel_struct(ch, ch->unk1C, 0x20, ch->unk24, ch->unk28, ch->unk2C, ch->unk30, ch->unk31);
    sound_set_pitch_offset(ch, ch->unk24);
    ch->unk10 = (0x10000 - 0x1000000 / ch->unk4) | 0x800000;
    sound_channel_play(ch, 0);
    sub_080725BC((struct SoundTrack *)ch->unk18);
}

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

void sound_start_channel_full(struct SoundMixChannel *ch)
{
    sound_restart_channel(ch);
    init_sound_channel_struct(ch, ch->unk1C, 0x20, 0, ch->unk28, ch->unk2C, ch->unk30, ch->unk31);
    ch->unk10 = (0x10000 - 0x1000000 / sound_calculate_playback_rate(ch, ch->unk20)) | 0x800000;
    sound_channel_play(ch, 0);
    sub_080725BC((struct SoundTrack *)ch->unk18);
}

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

void sound_channel_trigger_pending(struct SoundMixChannel *ch)
{
    if (ch->unkC & 1)
    {
        ch->unkC &= ~1;
        sound_channel_play(ch, ch->unk8 - 0x20);
    }
}

void sub_08073E18(struct SoundMixChannel *ch)
{
    ch->unk3E = 5;
}

void sound_channel_request_stop(struct SoundMixChannel *ch)
{
    if (ch->unk10)
    {
        sound_channel_stop_08073B0C(ch);
        ch->unkC |= 1;
    }
}

void sub_08073E40(struct SoundMixChannel *ch)
{
    ch->unk3E = 4;
}

void sound_channel_state_dispatch(struct SoundMixChannel *ch)
{
    u8 *state = &ch->unk3E;

    switch (*state)
    {
    case 1:
        sound_channel_init_full(ch);
        break;
    case 2:
        sound_start_channel_full(ch);
        break;
    case 3:
        sound_restart_channel(ch);
        break;
    case 4:
        sound_channel_request_stop(ch);
        break;
    case 5:
        sound_channel_trigger_pending(ch);
        break;
    default:
        return;
    }
    *state = 0;
}

void sub_08073EAC(void)
{
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_tick);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_tick_both_channels);

void sound_update_channel_at_690(void)
{
    sound_lock();
    sound_channel_update(&gUnk_03007014->unk690);
    sound_unlock();
}

void sound_update_channel_at_6d8(void)
{
    sound_lock();
    sound_channel_update(&gUnk_03007014->unk6D8);
    sound_unlock();
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sound_channel_update);

void clear_sound_channel_wave_data(struct SoundTrack *track)
{
    if (track->unk8 != NULL)
    {
        u32 fill = 0xFFFFFFFF;
        CpuSet(&fill, track->unk8, 0x0500000C);
        track->unk8[0x30] = 0;
    }
}

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

void sub_08074548(void)
{
    struct Unk_03007014 *work = gUnk_03007014;

    if (work->tracks[4].unk14 == NULL)
        sound_channel1_update(&work->tracks[0]);
}

void process_tone_channel_if_idle(void)
{
    struct Unk_03007014 *work = gUnk_03007014;

    if (work->tracks[5].unk14 == NULL)
        sound_channel_process_tone(&work->tracks[1]);
}

void sub_0807458C(void)
{
    struct Unk_03007014 *work = gUnk_03007014;

    if (work->tracks[6].unk14 == NULL)
        update_wave_channel(&work->tracks[2]);
}

void sound_tick_channel_3a(void)
{
    struct Unk_03007014 *work = gUnk_03007014;

    if (work->tracks[7].unk14 == NULL)
        sound_update_channel_3(&work->tracks[3]);
}

void sound_update_channel1_with_fallback(void)
{
    sound_channel1_update(&gUnk_03007014->tracks[4]);
    if (sub_080743C8() == 0)
    {
        gUnk_03007014->tracks[0].unk50 |= 0x5F;
        sound_channel1_update(&gUnk_03007014->tracks[0]);
    }
}

void sound_update_channel2_with_fallback(void)
{
    sound_channel_process_tone(&gUnk_03007014->tracks[5]);
    if (sub_080743C8() == 0)
    {
        gUnk_03007014->tracks[1].unk50 |= 0x5F;
        sound_channel_process_tone(&gUnk_03007014->tracks[1]);
    }
}

void update_wave_channels_pair(void)
{
    update_wave_channel(&gUnk_03007014->tracks[6]);
    if (sub_080743C8() == 0)
    {
        gUnk_03007014->tracks[2].unk50 |= 0x7F;
        update_wave_channel(&gUnk_03007014->tracks[2]);
    }
}

void sound_update_wave_channels(void)
{
    sound_update_channel_3(&gUnk_03007014->tracks[7]);
    if (sub_080743C8() == 0)
    {
        gUnk_03007014->tracks[3].unk50 |= 0x5F;
        sound_update_channel_3(&gUnk_03007014->tracks[3]);
    }
}

void reset_sound_channel_if_idle(void)
{
    struct Unk_03007014 *work = gUnk_03007014;

    if (work->tracks[10].unk14 == NULL)
        sub_08073CA4(&work->unk690);
}

void sound_update_channel_finish(void)
{
    struct Unk_03007014 *work = gUnk_03007014;

    if (work->tracks[11].unk14 == NULL)
        sub_08073CA4(&work->unk6D8);
    sound_channel_finish_and_callback(&gUnk_03007014->tracks[12]);
}

void reset_sound_channel_at_690(void)
{
    sub_08073CA4(&gUnk_03007014->unk690);
    gUnk_03007014->tracks[10].unk50 = 0;
}

void sound_reset_channel_9_and_stop_12(void)
{
    sub_08073CA4(&gUnk_03007014->unk6D8);
    gUnk_03007014->tracks[11].unk50 = 0;
    sound_stop_channel_by_index(12);
}

void sound_tick_channel_3c(void)
{
    struct Unk_03007014 *work = gUnk_03007014;

    if (work->tracks[7].unk14 == NULL)
        sound_update_channel_3(&work->tracks[12]);
}

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

void sound_channel_finish_and_callback(struct SoundTrack *track)
{
    if (track->unk14 != NULL)
    {
        sound_channel_reset(track);
        ((void (*)(void))track->unkC)();
    }
}

// Inserts the track into the circular list of active tracks (gUnk_03007014->unk5E4) as its new head.
void sound_track_link(struct SoundTrack *track)
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

void play_song(u32 id)
{
    sound_lock();
    load_song_channels(id, 0);
    sound_unlock();
}

void play_song_alt(u32 id, u32 arg)
{
    sound_lock();
    load_song_channels(id, arg);
    sound_unlock();
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08074A94);
INCLUDE_ASM("asm/nonmatching/sound_driver", set_all_sound_channels_flag_0x40);

void sound_update_with_lock(u32 a)
{
    sound_lock();
    set_all_sound_channels_flag_0x40(a);
    sound_unlock();
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08074B68);

void sub_08074BC4(u32 val)
{
    gUnk_03007014->unk68C = val;
}

INCLUDE_ASM("asm/nonmatching/sound_driver", play_sound_from_command);

void play_sound_effect(u32 id)
{
    sound_lock();
    play_sound_from_command(id, 0);
    sound_unlock();
}

void play_sound_effect_alt(u32 id, u32 arg)
{
    sound_lock();
    play_sound_from_command(id, arg);
    sound_unlock();
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08074CEC);
INCLUDE_ASM("asm/nonmatching/sound_driver", sound_reset_channel_callbacks);

void sound_reset_callbacks_with_lock(u32 a, u32 b)
{
    sound_lock();
    sound_reset_channel_callbacks(a, b);
    sound_unlock();
}

s32 get_sound_channel_position(u32 idx)
{
    struct SoundTrack *track = &sub_080750CC()->tracks[idx];
    s32 ret;

    if (track->unk14 != NULL)
        ret = track->unk4E;
    else
        ret = -1;
    return ret;
}

INCLUDE_ASM("asm/nonmatching/sound_driver", is_sound_playing_at_position);

u32 is_sound_playing_with_lock(u32 a)
{
    u32 ret;

    sound_lock();
    ret = is_sound_playing_at_position(a);
    sound_unlock();
    return ret;
}

void sub_08074E70(struct SoundNoteTable *val)
{
    gUnk_03007014->unk728 = val;
}

void sub_08074E84(struct SoundTrack *track, u32 target, u32 frames)
{
    s32 step = (s32)(target - track->unk40) / (s32)frames;

    if (step != 0)
    {
        track->unk42 = target;
        track->unk44 = step;
        track->unk3C = frames;
    }
}

void sound_play_with_lock(struct SoundTrack *track, u32 target, u32 frames)
{
    sound_lock();
    sub_08074E84(track, target, frames);
    sound_unlock();
}

INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08074EF4);
INCLUDE_ASM("asm/nonmatching/sound_driver", sub_08074F34);

void sound_stop_all_with_fade_guard(u32 a)
{
    sound_lock();
    sub_08074F34(a);
    sound_unlock();
}

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

