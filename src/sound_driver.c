#include "global.h"

// Sample played by a Direct Sound channel.
#define SAMPLE(ch) ((struct SoundSampleHeader *)(ch)->unk0)

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

void sound_engine_tick(void)
{
    if (gUnk_03007014->unk730 == 0)
    {
        sound_lock();
        sound_engine_update_all_channels();
        sound_unlock();
    }
}

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

void sound_channel_set_note_attributes(struct SoundTrack *track, vu16 *cnt, vu8 *freqHi)
{
    if (track->unk50 & 6)
    {
        track->unk4A = (track->envVolume * track->unk40) & (s16)0xF000;
        *cnt = track->unk67 | track->unk4A | 0x800;
        *freqHi |= 0x80;
        track->unk50 = (track->unk50 & ~6) | 0x10;
    }
}

void update_wave_channel_params(struct SoundTrack *track, vu16 *cnt)
{
    u8 *flags = &track->unk50;

    if (*flags & 0x20)
    {
        load_wave_pattern(track->unk67);
        *flags &= ~0x20;
    }
    if (*flags & 2)
    {
        track->unk4A = (track->envVolume * track->unk40) & (s16)0xF000;
        *cnt = gUnk_083ABA62[track->unk4A >> 12] << 8;
        *flags &= ~2;
    }
}

void update_sound_channel_frequency_08073244(struct SoundTrack *track, vu16 *reg)
{
    if (track->unk50 & 2)
    {
        track->unk4A = (track->envVolume * track->unk40) & (s16)0xF000;
        *reg = track->unk4A;
        track->unk50 = (track->unk50 & ~2) | 1;
    }
}

void sound_channel_update_frequency(struct SoundTrack *track, vu16 *out)
{
    u16 trigger = 0;
    u8 *flags = &track->unk50;
    u16 freq;

    if (*flags & 0x10)
    {
        trigger = 0x8000;
        *flags &= ~0x10;
    }
    if (*(vu8 *)flags & 1)
    {
        freq = track->unk46 + track->unk55 + (track->unk38 >> 4);
        if ((s16)freq < 0)
            freq = 0;
        else if ((s16)freq > 0x7FF)
            freq = 0x7FF;
        *out = trigger | freq;
        *flags &= ~1;
    }
    else if (trigger)
    {
        *out = trigger | track->unk46;
    }
}

void sound_update_channel3_frequency(struct SoundTrack *track, vu16 *out)
{
    u8 *flags = &track->unk50;
    u16 trigger;
    u16 freq;

    *flags &= ~0x10;
    if (*flags & 1)
    {
        trigger = (*(vu16 *)0x04000084 & 4) ? 0 : 0x8000;
        freq = track->unk46 + track->unk55 + (track->unk38 >> 4);
        if ((s16)freq < 0)
            freq = 0;
        else if ((s16)freq > 0x7FF)
            freq = 0x7FF;
        *out = trigger | freq;
        *flags &= ~1;
    }
}

void sound_channel_check_note_change(struct SoundTrack *track, u16 *out)
{
    if (track->unk50 & 1)
    {
        *out = track->unk69 | 0x8000;
        track->unk50 &= ~1;
    }
}

INCLUDE_ASM("asm/nonmatching/sound_driver", update_sound_channel_frequency_080733AC);

void sound_update_channel_output_routing(struct SoundTrack *track)
{
    u8 *flags = &track->unk50;

    if (*flags & 0x40)
    {
        struct Unk_03007014 *work = gUnk_03007014;
        u8 pan;
        u32 mask, bits;

        if (work->unk72C & 4)
            pan = 3;
        else if (track->unk70)
            pan = track->unk70;
        else if (track->unk63 == 2)
            pan = ((u8 *)work->unk728->unk4)[track->unk48];
        else
            pan = track->unk6F;
        mask = gSoundOutputMasks[track->unk64];
        bits = gSoundOutputBits[track->unk64][pan];
        *(vu8 *)0x04000081 = (mask & *(vu8 *)0x04000081) | bits;
        *flags &= ~0x40;
    }
}

void sound_channel1_update(struct SoundTrack *track)
{
    if (track->unk8 && track->unk6B && !track->envVolume && !(track->unk50 & 0x10))
    {
        update_sound_channel_frequency_080733AC(track, (vu16 *)0x04000062, (vu16 *)0x04000064);
    }
    else
    {
        sound_channel_read_pending_note(track, (u16 *)0x04000060);
        sound_channel_set_note_attributes(track, (vu16 *)0x04000062, (vu8 *)0x04000065);
        sound_channel_update_frequency(track, (vu16 *)0x04000064);
        sound_update_channel_output_routing(track);
    }
}

void sound_channel_process_tone(struct SoundTrack *track)
{
    if (track->unk8 && track->unk6B && !track->envVolume && !(track->unk50 & 0x10))
    {
        update_sound_channel_frequency_080733AC(track, (vu16 *)0x04000068, (vu16 *)0x0400006C);
    }
    else
    {
        sound_channel_set_note_attributes(track, (vu16 *)0x04000068, (vu8 *)0x0400006D);
        sound_channel_update_frequency(track, (vu16 *)0x0400006C);
        sound_update_channel_output_routing(track);
    }
}

void update_wave_channel(struct SoundTrack *track)
{
    if (track->unk8 && track->unk6B && !track->envVolume && !(track->unk50 & 0x10))
    {
        update_sound_channel_frequency_080733AC(track, (vu16 *)0x04000072, (vu16 *)0x04000074);
    }
    else
    {
        update_wave_channel_params(track, (vu16 *)0x04000072);
        sound_update_channel3_frequency(track, (vu16 *)0x04000074);
        sound_update_channel_output_routing(track);
    }
}

void sound_update_channel_3(struct SoundTrack *track)
{
    update_sound_channel_frequency_08073244(track, (vu16 *)0x04000078);
    sound_channel_check_note_change(track, (u16 *)0x0400007C);
    sound_update_channel_output_routing(track);
}

void sound_channel_update_note_08073698(struct SoundTrack *track, struct SoundMixChannel *ch)
{
    u16 *vol;
    u8 *flags;

    {
        u16 v = (track->envVolume * track->unk40) & (s16)0xF000;
        vol = &track->unk4A;
        *vol = v;
    }
    flags = &track->unk50;
    if (*flags & 0x10)
    {
        if (track->envVolume != 0)
        {
            struct Unk_03007014 *work = gUnk_03007014;
            u32 len = track->unk28;

            if (track->envEnabled)
            {
                if (len > track->envRelease)
                    len -= track->envRelease;
                else
                    len = 1;
            }
            switch (track->unk63)
            {
            case 0:
                sound_channel_setup((u32)track, ch, ((u32 *)work->unk720)[track->unk67],
                                    track->unk48 + (s8)track->unk6A, *vol >> 12, len,
                                    track->unk6F, track->unk70);
                break;
            case 1:
                sound_channel_setup_alt((u32)track, ch, ((u32 *)work->unk720)[track->unk67],
                                        track->unk48, *vol >> 12, len,
                                        track->unk6F, track->unk70);
                break;
            case 2:
                sound_channel_setup((u32)track, ch, ((u32 *)work->unk724)[track->unk48],
                                    work->unk728->base + track->unk48, *vol >> 12, len,
                                    ((u8 *)work->unk728->unk4)[track->unk48], track->unk70);
                break;
            }
        }
        else
        {
            sub_08073CA4(ch);
        }
        *flags &= ~0x10;
    }
    if (track->unk58)
    {
        ch->unk14 = track->unk38 >> 4;
        ch->unkC |= 2;
    }
    if (track->unk50 & 0x40)
    {
        ch->unk3F = track->unk6F;
        ch->unk40 = track->unk70;
        ch->unkC |= 4;
        track->unk50 &= ~0x40;
    }
}

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

u32 sound_semitone_ratio(s32 n)
{
    const u16 *tbl = gSoundSemitoneRatios;
    u32 ret;

    if (n > 0)
    {
        s32 rem = n % 12;
        s32 oct = n / 12;
        ret = tbl[rem] << oct;
    }
    else if (n < 0)
    {
        s32 oct, rem;
        n = -n;
        oct = n / 12;
        rem = n % 12;
        if (rem != 0)
        {
            rem = 12 - rem;
            oct++;
        }
        ret = tbl[rem] >> oct;
    }
    else
        ret = tbl[0];
    return ret;
}

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

void sub_08073EAC(struct SoundMixChannel *ch)
{
}

void sound_tick_both_channels(void)
{
    void sound_channel_tick(u32 i)
    {
        struct SoundMixChannel *ch = &gUnk_03007014->unk690 + i;

        if (ch->unk0 && !(ch->unkC & 1))
            ch->unk38++;
        sound_channel_state_dispatch(ch);
    }

    sound_channel_tick(0);
    sound_channel_tick(1);
}

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

void sound_channel_update(struct SoundMixChannel *ch)
{
    if (ch->unk0 == 0)
    {
        ch->unk44++;
        return;
    }
    if (ch->unkC & 1)
        return;
    sub_08073EAC(ch);
    ch->unk8 += 0x10;
    if (ch->unk38)
    {
        ch->unk36 += ch->unk38;
        ch->unk38 = 0;
    }
    if (SAMPLE(ch)->unk0 <= ch->unk8)
    {
        if (!(SAMPLE(ch)->unk8 & 1))
            goto restart;
        sound_stop_fifo_dma(ch->unk3A);
        ch->unk8 = SAMPLE(ch)->unkC;
        sound_start_fifo_dma(ch->unk3A, (u32)&SAMPLE(ch)->data[SAMPLE(ch)->unkC]);
    }
    if (ch->unk34 <= ch->unk36)
    {
    restart:
        sound_restart_channel(ch);
        return;
    }
    if (ch->unkC & 2)
    {
        u32 reload = (0x10000 - 0x1000000 / (ch->unk4 + ch->unk14)) | 0x800000;

        ch->unk10 = reload;
        *gSoundTimerRegs[ch->unk3A - 1] = reload;
        ch->unkC &= ~2;
    }
    if (ch->unkC & 4)
    {
        sound_configure_mixing_channel(ch);
        ch->unkC &= ~4;
    }
}

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

void sub_080740D4(struct SoundTrack *track)
{
    u8 *buf = track->unk8;

    if (buf)
    {
        u8 vol = track->envVolume;
        u8 *pos = &buf[0x30];

        if (vol)
            buf[*pos] = track->unk48;
        else
            buf[*pos] = 0xFF;
        if (++*pos >= 0x30)
            *pos = 0;
    }
}

// Pause (nonzero) or resume the sound: sets bit 1 of the flags at 0x72C (see sound_is_paused),
// silences the PSG channels and stops the sound effect tracks; resuming re-triggers the music tracks.
void sound_set_paused_nolock(u32 pause)
{
    struct Unk_03007014 **pw = &gUnk_03007014;

    if (pause)
    {
        (*pw)->unk72C |= 2;
        *(vu16 *)0x04000062 &= 0x0FFF;
        *(vu16 *)0x04000064 |= 0x8000;
        *(vu16 *)0x04000068 &= 0x0FFF;
        *(vu16 *)0x0400006C |= 0x8000;
        *(vu16 *)0x04000072 &= 0x1FFF;
        *(vu16 *)0x04000078 &= 0x0FFF;
        *(vu16 *)0x0400007C |= 0x8000;
        if ((*pw)->tracks[10].unk14)
            sub_08073CA4(&(*pw)->unk690);
        else if ((*pw)->tracks[8].unk14)
            sub_08073E40(&(*pw)->unk690);
        if (gUnk_03007014->tracks[11].unk14)
            sub_08073CA4(&gUnk_03007014->unk6D8);
        else if (gUnk_03007014->tracks[9].unk14)
            sub_08073E40(&gUnk_03007014->unk6D8);
        sound_channel_finish_and_callback(&gUnk_03007014->tracks[4]);
        sound_channel_finish_and_callback(&gUnk_03007014->tracks[5]);
        sound_channel_finish_and_callback(&gUnk_03007014->tracks[6]);
        sound_channel_finish_and_callback(&gUnk_03007014->tracks[7]);
        sound_channel_finish_and_callback(&gUnk_03007014->tracks[10]);
        sound_channel_finish_and_callback(&gUnk_03007014->tracks[11]);
    }
    else
    {
        (*pw)->unk72C &= ~2;
        if (gUnk_03007014->tracks[4].unk14 == NULL && gUnk_03007014->tracks[0].unk14)
        {
            gUnk_03007014->tracks[0].unk50 |= 0x5F;
            sound_channel1_update(&gUnk_03007014->tracks[0]);
        }
        if (gUnk_03007014->tracks[5].unk14 == NULL && gUnk_03007014->tracks[1].unk14)
        {
            gUnk_03007014->tracks[1].unk50 |= 0x5F;
            sound_channel_process_tone(&gUnk_03007014->tracks[1]);
        }
        if (gUnk_03007014->tracks[6].unk14 == NULL && gUnk_03007014->tracks[2].unk14)
        {
            gUnk_03007014->tracks[2].unk50 |= 0x7F;
            update_wave_channel(&gUnk_03007014->tracks[2]);
        }
        if (gUnk_03007014->tracks[7].unk14 == NULL && gUnk_03007014->tracks[3].unk14)
        {
            gUnk_03007014->tracks[3].unk50 |= 0x5F;
            sound_update_channel_3(&gUnk_03007014->tracks[3]);
        }
        if (gUnk_03007014->tracks[10].unk14 == NULL && gUnk_03007014->tracks[8].unk14)
        {
            sub_08073E18(&gUnk_03007014->unk690);
            gUnk_03007014->tracks[8].unk50 = 0;
        }
        if (gUnk_03007014->tracks[11].unk14 == NULL && gUnk_03007014->tracks[9].unk14)
        {
            sub_08073E18(&gUnk_03007014->unk6D8);
            gUnk_03007014->tracks[9].unk50 = 0;
        }
    }
}

// Not called anywhere in the game.
void sound_set_paused(u32 pause)
{
    sound_lock();
    sound_set_paused_nolock(pause);
    sound_unlock();
}

u32 sound_is_paused(void)
{
    return (gUnk_03007014->unk72C >> 1) & 1;
}

void init_sound_channel(struct SoundTrack *track, u8 *seq)
{
    clear_sound_channel_wave_data(track);
    track->unk14 = seq;
    track->unk18 = NULL;
    track->unk1C = NULL;
    track->unk20 = NULL;
    track->unk24 = NULL;
    track->unk28 = 0;
    track->unk2C = 0;
    track->unk30 = 0;
    track->unk50 = 0x5F;
    track->unk52 = 0;
    track->unk53 = 0;
    track->unk54 = 8;
    track->unk55 = 0;
    track->unk56 = 0;
    track->unk57 = 0;
    track->unk58 = 0;
    track->unk59 = 0;
    track->unk5A = 0;
    track->unk34 = 0;
    track->unk38 = 0;
    track->unk63 = 0;
    track->unk48 = 0xFF;
    track->volume = 15;
    track->envVolume = 0;
    track->unk67 = 0;
    track->unk68 = 0;
    track->unk69 = 0;
    track->unk6A = 0;
    track->unk6B = 0;
    track->unk6C = 0xFF;
    track->envEnabled = 0;
    track->unk6D = 0;
    track->unk6E = 0;
    track->unk40 = 0x1000;
    track->unk42 = 0x1000;
    track->unk44 = 0;
    track->unk3C = 0;
    track->unk6F = 3;
    track->unk70 = 0;
    track->unk4C = 0;
    track->unk4E = 0xFFFF;
    sound_track_link(track);
}

void sound_stop_channel_by_index(u32 idx)
{
    if (gUnk_03007014->tracks[idx].unk14 && !sound_is_paused())
    {
        if (gUnk_03007014->tracks[7].unk14)
        {
            gUnk_03007014->tracks[7].unk50 |= 0x5F;
            sound_update_channel_3(&gUnk_03007014->tracks[7]);
        }
        else if (gUnk_03007014->tracks[3].unk14)
        {
            gUnk_03007014->tracks[3].unk50 |= 0x5F;
            sound_update_channel_3(&gUnk_03007014->tracks[3]);
        }
        else
        {
            gUnk_03007014->tracks[idx].envVolume = 0;
            gUnk_03007014->tracks[idx].unk50 |= 2;
            sound_update_channel_3(&gUnk_03007014->tracks[idx]);
        }
    }
}

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
    if (sound_is_paused() == 0)
    {
        gUnk_03007014->tracks[0].unk50 |= 0x5F;
        sound_channel1_update(&gUnk_03007014->tracks[0]);
    }
}

void sound_update_channel2_with_fallback(void)
{
    sound_channel_process_tone(&gUnk_03007014->tracks[5]);
    if (sound_is_paused() == 0)
    {
        gUnk_03007014->tracks[1].unk50 |= 0x5F;
        sound_channel_process_tone(&gUnk_03007014->tracks[1]);
    }
}

void update_wave_channels_pair(void)
{
    update_wave_channel(&gUnk_03007014->tracks[6]);
    if (sound_is_paused() == 0)
    {
        gUnk_03007014->tracks[2].unk50 |= 0x7F;
        update_wave_channel(&gUnk_03007014->tracks[2]);
    }
}

void sound_update_wave_channels(void)
{
    sound_update_channel_3(&gUnk_03007014->tracks[7]);
    if (sound_is_paused() == 0)
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

void sub_08074900(struct SoundSongHeader **val)
{
    gUnk_03007014->unk688 = val;
}

void load_song_channels(u32 id, u32 arg)
{
    struct Unk_03007014 *work = sub_080750CC();
    struct SoundSongHeader *song = work->unk688[id];
    u32 i;
    u32 bit;
    u8 **seq;

    sound_channel_finish_and_callback(&work->tracks[0]);
    sound_channel_finish_and_callback(&work->tracks[1]);
    sound_channel_finish_and_callback(&work->tracks[2]);
    sound_channel_finish_and_callback(&work->tracks[3]);
    sound_channel_finish_and_callback(&work->tracks[8]);
    sound_channel_finish_and_callback(&work->tracks[9]);
    sound_channel_finish_and_callback(&work->tracks[12]);

    i = 0;
    bit = 0x800;
    seq = (u8 **)song;
loop:
    if (song->trackMask & bit)
    {
        struct SoundTrack *track = &work->tracks[i];

        init_sound_channel(track, seq[1]);
        track->unk6D = song->priority;
        track->unk70 = arg;
        seq++;
    }
    bit >>= 1;
    i++;
    if (bit)
        goto loop;

    if (song->trackMask & 4)
    {
        init_sound_channel(&work->tracks[12], work->tracks[9].unk14);
        work->tracks[12].unk6D = song->priority;
        work->tracks[12].unk70 = arg;
    }
    work->unk72F = id;
}

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

void set_all_sound_channels_flag_0x40(u32 val)
{
    struct Unk_03007014 *work = gUnk_03007014;

    void sub_08074A94(struct SoundTrack *track)
    {
        track->unk70 = val;
        track->unk50 |= 0x40;
    }

    sub_08074A94(&work->tracks[0]);
    sub_08074A94(&work->tracks[1]);
    sub_08074A94(&work->tracks[2]);
    sub_08074A94(&work->tracks[3]);
    sub_08074A94(&work->tracks[8]);
    sub_08074A94(&work->tracks[9]);
    sub_08074A94(&work->tracks[12]);
}

void sound_update_with_lock(u32 a)
{
    sound_lock();
    set_all_sound_channels_flag_0x40(a);
    sound_unlock();
}

u32 sub_08074B68(void)
{
    struct Unk_03007014 **pw = &gUnk_03007014;

    if ((*pw)->tracks[0].unk14 || (*pw)->tracks[1].unk14 || (&(*pw)->tracks[2])->unk14
     || (&(*pw)->tracks[3])->unk14 || (&(*pw)->tracks[8])->unk14 || (&(*pw)->tracks[9])->unk14)
        return (*pw)->unk72F;
    return -1;
}

void sub_08074BC4(struct SoundSongHeader **val)
{
    gUnk_03007014->unk68C = val;
}

void play_sound_from_command(u32 id, u32 arg)
{
    struct Unk_03007014 *work = sub_080750CC();
    struct SoundSongHeader *song = work->unk68C[id];
    u32 i;
    u32 bit;
    u8 **seq;

    i = 0;
    bit = 0x800;
    seq = (u8 **)song;
loop:
    if (song->trackMask & bit)
    {
        struct SoundTrack *track = &work->tracks[i];

        if (track->unk6D <= song->priority)
        {
            init_sound_channel(track, seq[1]);
            track->unk6D = song->priority;
            track->unk4E = id;
            track->unk70 = arg;
        }
        seq++;
    }
    bit >>= 1;
    i++;
    if (bit)
        goto loop;
}

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

void sound_reset_channel_callbacks(u32 id, u32 val)
{
    struct Unk_03007014 *work = gUnk_03007014;

    void sub_08074CEC(struct SoundTrack *track)
    {
        if (track->unk4E == id && track->unk14)
        {
            track->unk70 = val;
            track->unk50 |= 0x40;
        }
    }

    sub_08074CEC(&work->tracks[4]);
    sub_08074CEC(&work->tracks[5]);
    sub_08074CEC(&work->tracks[6]);
    sub_08074CEC(&work->tracks[7]);
    sub_08074CEC(&work->tracks[10]);
    sub_08074CEC(&work->tracks[11]);
}

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

void sound_track_start_fade(struct SoundTrack *track, u32 target, u32 frames)
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
    sound_track_start_fade(track, target, frames);
    sound_unlock();
}

void sound_fade_out_music(u32 frames)
{
    void sound_fade_out_track(u32 idx)
    {
        if (gUnk_03007014->tracks[idx].unk14)
            sound_play_with_lock(&gUnk_03007014->tracks[idx], 0, frames);
    }

    sound_fade_out_track(0);
    sound_fade_out_track(1);
    sound_fade_out_track(2);
    sound_fade_out_track(3);
    sound_fade_out_track(8);
    sound_fade_out_track(9);
}

void sound_stop_all_with_fade_guard(u32 a)
{
    sound_lock();
    sound_fade_out_music(a);
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

