// Sound driver: the second half of the sound engine. sound_engine_tick runs once a frame (from the VBlank
// handler): it advances the sequencer (audio/sound_seq.c), turns notes into frequencies for the PSG
// channels 1-4 and the Direct Sound FIFO channels, and handles music / sound-effect start, stop, fade and
// master volume for the game code.

#include "global.h"

static void load_wave_pattern(u32 n);
static void sound_mix_queue_stop(struct SoundMixChannel *ch);
static void sound_mix_queue_note(u32 a0, struct SoundMixChannel *ch, u32 a2, u32 a3, u32 a4, u32 a5, u8 a6, u8 a7);
static void sound_mix_queue_at_rate(u32 a0, struct SoundMixChannel *ch, u32 a2, u32 a3, u32 a4, u32 a5, u8 a6, u8 a7);
static void sound_mix_refill(struct SoundMixChannel *ch);
static u8 sound_track_echo_note(struct SoundTrack *track);
static void sound_track_link(struct SoundTrack *track);
static void sound_set_master_volume(u32 left, u32 right);
static struct SoundWork *sound_get_work(void);

// Sample played by a Direct Sound channel.
#define SAMPLE(ch) ((struct SoundSampleHeader *)(ch)->sample)

// Nesting counter at gSoundWork->lockCount around updates of the sound work area.
static inline void sound_lock(void) {
    if (gSoundWork->lockCount < 0xFFFF)
        gSoundWork->lockCount++;
}

static inline void sound_unlock(void) {
    if (gSoundWork->lockCount != 0)
        gSoundWork->lockCount--;
}

void sound_engine_tick(void) {
    if (gSoundWork->lockCount == 0) {
        sound_lock();
        sound_engine_update();
        sound_unlock();
    }
}

u16 sound_psg_note_freq(u32 idx) {
    return gSoundPsgNoteFreqs[idx];
}

static void sound_output_sweep(struct SoundTrack *track, u16 *out) {
    if (track->dirty & 8) {
        *out = track->sweep;
        track->dirty &= ~8;
    }
}

static void sound_output_psg_volume(struct SoundTrack *track, vu16 *cnt, vu8 *freqHi) {
    if (track->dirty & 6) {
        track->outVolume = (track->envVolume * track->fadeVolume) & (s16)0xF000;
        *cnt = track->instrument | track->outVolume | 0x800;
        *freqHi |= 0x80;
        track->dirty = (track->dirty & ~6) | 0x10;
    }
}

static void sound_output_wave_volume(struct SoundTrack *track, vu16 *cnt) {
    u8 *flags = &track->dirty;

    if (*flags & 0x20) {
        load_wave_pattern(track->instrument);
        *flags &= ~0x20;
    }
    if (*flags & 2) {
        track->outVolume = (track->envVolume * track->fadeVolume) & (s16)0xF000;
        *cnt = gSoundWaveVolumes[track->outVolume >> 12] << 8;
        *flags &= ~2;
    }
}

static void sound_output_noise_volume(struct SoundTrack *track, vu16 *reg) {
    if (track->dirty & 2) {
        track->outVolume = (track->envVolume * track->fadeVolume) & (s16)0xF000;
        *reg = track->outVolume;
        track->dirty = (track->dirty & ~2) | 1;
    }
}

static void sound_output_psg_freq(struct SoundTrack *track, vu16 *out) {
    u16 trigger = 0;
    u8 *flags = &track->dirty;
    u16 freq;

    if (*flags & 0x10) {
        trigger = 0x8000;
        *flags &= ~0x10;
    }
    if (*(vu8 *)flags & 1) {
        freq = track->freq + track->detune + (track->vibratoOffset >> 4);
        if ((s16)freq < 0)
            freq = 0;
        else if ((s16)freq > 0x7FF)
            freq = 0x7FF;
        *out = trigger | freq;
        *flags &= ~1;
    } else if (trigger) {
        *out = trigger | track->freq;
    }
}

static void sound_output_wave_freq(struct SoundTrack *track, vu16 *out) {
    u8 *flags = &track->dirty;
    u16 trigger;
    u16 freq;

    *flags &= ~0x10;
    if (*flags & 1) {
        trigger = (*(vu16 *)0x04000084 & 4) ? 0 : 0x8000;
        freq = track->freq + track->detune + (track->vibratoOffset >> 4);
        if ((s16)freq < 0)
            freq = 0;
        else if ((s16)freq > 0x7FF)
            freq = 0x7FF;
        *out = trigger | freq;
        *flags &= ~1;
    }
}

static void sound_output_noise_freq(struct SoundTrack *track, u16 *out) {
    if (track->dirty & 1) {
        *out = track->noiseParams | 0x8000;
        track->dirty &= ~1;
    }
}

static void sound_output_echo(struct SoundTrack *track, vu16 *cnt_, vu16 *freq_) {
    register vu16 *cnt asm("r6") = cnt_;
    register vu16 *freq asm("r5") = freq_;
    u8 note = sound_track_echo_note(track);

    if (track->echoNote != note) {
        u8 *mode;

        track->echoNote = note;
        mode = &track->channelType;
        if (note != 0xFF) {
            u16 f = sound_psg_note_freq(note) + track->detune;
            u16 *vol;
            u8 m;

            if ((s16)f < 0)
                f = 0;
            else if ((s16)f > 0x7FF)
                f = 0x7FF;
            m = *mode;
            vol = &track->fadeVolume;
            if (m == 2) {
                vu16 tmp;

                *cnt = gSoundWaveVolumes[(*vol * 3) >> 12] << 8;
                tmp = (*(vu16 *)0x04000084 & 4) ? 0 : 0x8000;
                *freq = f | tmp;
            } else {
                *cnt = ((*vol * 3) & (s16)0xF000) | track->instrument;
                *freq = f | 0x8000;
            }
        } else {
            u16 v;
            if (*mode == 2)
                v = 0;
            else
                v = track->instrument;
            *cnt = v;
            *freq |= 0x8000;
        }
    }
}

static void sound_output_pan(struct SoundTrack *track) {
    u8 *flags = &track->dirty;

    if (*flags & 0x40) {
        struct SoundWork *work = gSoundWork;
        u8 pan;
        u32 mask, bits;

        if (work->flags & 4)
            pan = 3;
        else if (track->panOverride)
            pan = track->panOverride;
        else if (track->noteMode == 2)
            pan = ((u8 *)work->drumKit->pans)[track->note];
        else
            pan = track->pan;
        mask = gSoundOutputMasks[track->channelType];
        bits = gSoundOutputBits[track->channelType][pan];
        *(vu8 *)0x04000081 = (mask & *(vu8 *)0x04000081) | bits;
        *flags &= ~0x40;
    }
}

void sound_output_sq1(struct SoundTrack *track) {
    if (track->echoBuffer && track->echoDelay && !track->envVolume && !(track->dirty & 0x10)) {
        sound_output_echo(track, (vu16 *)0x04000062, (vu16 *)0x04000064);
    } else {
        sound_output_sweep(track, (u16 *)0x04000060);
        sound_output_psg_volume(track, (vu16 *)0x04000062, (vu8 *)0x04000065);
        sound_output_psg_freq(track, (vu16 *)0x04000064);
        sound_output_pan(track);
    }
}

void sound_output_sq2(struct SoundTrack *track) {
    if (track->echoBuffer && track->echoDelay && !track->envVolume && !(track->dirty & 0x10)) {
        sound_output_echo(track, (vu16 *)0x04000068, (vu16 *)0x0400006C);
    } else {
        sound_output_psg_volume(track, (vu16 *)0x04000068, (vu8 *)0x0400006D);
        sound_output_psg_freq(track, (vu16 *)0x0400006C);
        sound_output_pan(track);
    }
}

void sound_output_wave(struct SoundTrack *track) {
    if (track->echoBuffer && track->echoDelay && !track->envVolume && !(track->dirty & 0x10)) {
        sound_output_echo(track, (vu16 *)0x04000072, (vu16 *)0x04000074);
    } else {
        sound_output_wave_volume(track, (vu16 *)0x04000072);
        sound_output_wave_freq(track, (vu16 *)0x04000074);
        sound_output_pan(track);
    }
}

void sound_output_noise(struct SoundTrack *track) {
    sound_output_noise_volume(track, (vu16 *)0x04000078);
    sound_output_noise_freq(track, (u16 *)0x0400007C);
    sound_output_pan(track);
}

static void sound_output_direct(struct SoundTrack *track, struct SoundMixChannel *ch) {
    u16 *vol;
    u8 *flags;

    {
        u16 v = (track->envVolume * track->fadeVolume) & (s16)0xF000;
        vol = &track->outVolume;
        *vol = v;
    }
    flags = &track->dirty;
    if (*flags & 0x10) {
        if (track->envVolume != 0) {
            struct SoundWork *work = gSoundWork;
            u32 len = track->wait;

            if (track->envEnabled) {
                if (len > track->envRelease)
                    len -= track->envRelease;
                else
                    len = 1;
            }
            switch (track->noteMode) {
            case 0:
                sound_mix_queue_note((u32)track, ch, ((u32 *)work->instrumentSamples)[track->instrument],
                                     track->note + (s8)track->transpose, *vol >> 12, len, track->pan,
                                     track->panOverride);
                break;
            case 1:
                sound_mix_queue_at_rate((u32)track, ch, ((u32 *)work->instrumentSamples)[track->instrument],
                                        track->note, *vol >> 12, len, track->pan, track->panOverride);
                break;
            case 2:
                sound_mix_queue_note((u32)track, ch, ((u32 *)work->drumSamples)[track->note],
                                     work->drumKit->base + track->note, *vol >> 12, len,
                                     ((u8 *)work->drumKit->pans)[track->note], track->panOverride);
                break;
            }
        } else {
            sound_mix_queue_stop(ch);
        }
        *flags &= ~0x10;
    }
    if (track->vibratoDepth) {
        ch->rateOffset = track->vibratoOffset >> 4;
        ch->flags |= 2;
    }
    if (track->dirty & 0x40) {
        ch->pan = track->pan;
        ch->panOverride = track->panOverride;
        ch->flags |= 4;
        track->dirty &= ~0x40;
    }
}

void sound_output_fifo_a(struct SoundTrack *track) {
    sound_output_direct(track, &gSoundWork->fifoA);
}

void sound_output_fifo_b(struct SoundTrack *track) {
    sound_output_direct(track, &gSoundWork->fifoB);
}

void sound_update_master_volume(void) {
    struct SoundWork *work = gSoundWork;

    if (work->flags & 1) {
        *(vu16 *)0x04000080 = (work->volumeLeft << 4) | 0xFF00 | work->volumeRight;
        work->flags &= ~1;
    }
}

static void load_wave_pattern(u32 n) {
    vu16 cnt;

    CpuSet(gSoundWavePatterns[n], (void *)0x04000090, 0x04000004);
    cnt = *(vu16 *)0x04000070;
    *(vu16 *)0x04000070 = (cnt == 0x80) ? 0xC0 : 0x80;
}

void sound_init_wave_channel(void) {
    *(vu16 *)0x04000084 = 0x80;
    *(vu16 *)0x04000082 = 0x400E;
    *(vu16 *)0x04000070 = 0xC0;
    load_wave_pattern(0);
    sound_set_master_volume(7, 7);
}

// Streams samples from src into FIFO A (n = 1) or B (n = 2) with DMA n, timed by the sound FIFO.
static void sound_start_fifo_dma(s32 n, u32 src) {
    vu32 *dma = (vu32 *)(0x040000B0 + n * 12);
    dma[0] = src;
    dma[1] = (u32)gSoundFifoAddrs[n - 1];
    dma[2] = 0xF6400004;
}

static void sound_start_fifo(s32 n, u32 *src) {
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
static void sound_stop_fifo_dma(s32 n) {
    vu16 *reg = gSoundFifoDmaCnt[n - 1];
    *reg = (*reg & 0x499F) | 0x8440;
    *reg = (*reg & 0x499F) | 0x440;
}

static u32 sound_semitone_ratio(s32 n) {
    const u16 *tbl = gSoundSemitoneRatios;
    u32 ret;

    if (n > 0) {
        s32 rem = n % 12;
        s32 oct = n / 12;
        ret = tbl[rem] << oct;
    } else if (n < 0) {
        s32 oct, rem;
        n = -n;
        oct = n / 12;
        rem = n % 12;
        if (rem != 0) {
            rem = 12 - rem;
            oct++;
        }
        ret = tbl[rem] >> oct;
    } else
        ret = tbl[0];
    return ret;
}

static u32 sound_finetune_ratio(s32 n) {
    s32 q;
    s32 rem;

    if (n == 0)
        return 0;
    q = n / 128;
    rem = n - q * 128;
    return (sound_semitone_ratio(q) * gSoundFinetuneRatios[rem]) >> 12;
}

static u32 sound_apply_finetune(u32 rate, u32 fine) {
    return fine ? (sound_finetune_ratio(fine) * rate) >> 12 : rate;
}

static u32 sound_calculate_playback_rate(struct SoundMixChannel *ch, u32 ratio) {
    struct SoundSampleHeader *smp = (struct SoundSampleHeader *)ch->sample;
    u32 rate = sound_apply_finetune((smp->rate * ratio) >> 12, smp->fineTune);

    if (rate > 0x78000)
        rate = 0x78000;
    ch->rate = rate;
    return rate;
}

u32 sound_set_pitch_offset(struct SoundMixChannel *ch, s32 note) {
    return sound_calculate_playback_rate(
        ch, sound_semitone_ratio(note - ((struct SoundSampleHeader *)ch->sample)->baseNote));
}

void sound_set_instrument_samples(u32 val) {
    gSoundWork->instrumentSamples = val;
}

void sound_set_drum_samples(u32 val) {
    gSoundWork->drumSamples = val;
}

static void sound_mix_stop_dma(struct SoundMixChannel *ch) {
    if (*gSoundTimerRegs[ch->fifo - 1] & 0x800000) {
        sound_stop_fifo_dma(ch->fifo);
        *gSoundTimerRegs[ch->fifo - 1] = 0;
        *(vu16 *)0x04000082 &= ~gSoundFifoEnableBits[ch->fifo - 1];
    }
}

static void sound_mix_apply_output(struct SoundMixChannel *ch) {
    u32 route;

    if (gSoundWork->flags & 4)
        route = 3;
    else if (ch->panOverride)
        route = ch->panOverride;
    else
        route = ch->pan;
    *(vu16 *)0x04000082 =
        (*(vu16 *)0x04000082 & gSoundFifoOutputMasks[ch->fifo - 1] & gSoundFifoVolumeMasks[ch->fifo - 1]) |
        gSoundFifoOutputBits[ch->fifo - 1][route] | gSoundFifoVolumeBits[ch->fifo - 1][ch->volume];
}

static void sound_mix_play_from(struct SoundMixChannel *ch, u32 offset) {
    sound_mix_stop_dma(ch);
    if (ch->volume) {
        u8 *n;

        sound_mix_apply_output(ch);
        n = &ch->fifo;
        sound_start_fifo(*n, (u32 *)&((struct SoundSampleHeader *)ch->sample)->data[offset]);
        *gSoundTimerRegs[*n - 1] = ch->timerReload;
    }
}

static void sound_mix_init(struct SoundMixChannel *ch, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u8 a6, u8 a7) {
    ch->sample = a1;
    ch->position = a2;
    ch->flags = 0;
    ch->rateOffset = 0;
    ch->length = a5;
    ch->elapsed = 0;
    ch->pendingFrames = 0;
    ch->note = a3;
    ch->volume = a4;
    ch->rate = 0;
    ch->timerReload = 0;
    ch->pan = a6;
    ch->panOverride = a7;
}

static void sound_mix_stop(struct SoundMixChannel *ch) {
    sound_mix_stop_dma(ch);
    sound_mix_init(ch, 0, 0, 0, 0, 0, 0, 0);
}

static void sound_mix_queue_stop(struct SoundMixChannel *ch) {
    ch->request = 3;
}

static void sound_mix_start_note(struct SoundMixChannel *ch) {
    sound_mix_stop(ch);
    sound_mix_init(ch, ch->queuedSample, 0x20, ch->queuedNote, ch->queuedVolume, ch->queuedLength, ch->queuedPan,
                   ch->queuedPanOverride);
    sound_set_pitch_offset(ch, ch->queuedNote);
    ch->timerReload = (0x10000 - 0x1000000 / ch->rate) | 0x800000;
    sound_mix_play_from(ch, 0);
    sound_vibrato_start_direct((struct SoundTrack *)ch->track);
}

static void sound_mix_queue_note(u32 a0, struct SoundMixChannel *ch, u32 a2, u32 a3, u32 a4, u32 a5, u8 a6, u8 a7) {
    ch->request = 0;
    ch->track = a0;
    ch->queuedSample = a2;
    ch->queuedNote = a3;
    ch->queuedVolume = a4;
    ch->queuedLength = a5;
    ch->queuedPan = a6;
    ch->queuedPanOverride = a7;
    ch->request = 1;
}

static void sound_mix_start_at_rate(struct SoundMixChannel *ch) {
    sound_mix_stop(ch);
    sound_mix_init(ch, ch->queuedSample, 0x20, 0, ch->queuedVolume, ch->queuedLength, ch->queuedPan,
                   ch->queuedPanOverride);
    ch->timerReload = (0x10000 - 0x1000000 / sound_calculate_playback_rate(ch, ch->queuedRatio)) | 0x800000;
    sound_mix_play_from(ch, 0);
    sound_vibrato_start_direct((struct SoundTrack *)ch->track);
}

static void sound_mix_queue_at_rate(u32 a0, struct SoundMixChannel *ch, u32 a2, u32 a3, u32 a4, u32 a5, u8 a6, u8 a7) {
    ch->request = 0;
    ch->track = a0;
    ch->queuedSample = a2;
    ch->queuedRatio = a3;
    ch->queuedVolume = a4;
    ch->queuedLength = a5;
    ch->queuedPan = a6;
    ch->queuedPanOverride = a7;
    ch->request = 1;
}

static void sound_mix_resume(struct SoundMixChannel *ch) {
    if (ch->flags & 1) {
        ch->flags &= ~1;
        sound_mix_play_from(ch, ch->position - 0x20);
    }
}

static void sound_mix_queue_resume(struct SoundMixChannel *ch) {
    ch->request = 5;
}

static void sound_mix_pause(struct SoundMixChannel *ch) {
    if (ch->timerReload) {
        sound_mix_stop_dma(ch);
        ch->flags |= 1;
    }
}

static void sound_mix_queue_pause(struct SoundMixChannel *ch) {
    ch->request = 4;
}

static void sound_mix_run_request(struct SoundMixChannel *ch) {
    u8 *state = &ch->request;

    switch (*state) {
    case 1:
        sound_mix_start_note(ch);
        break;
    case 2:
        sound_mix_start_at_rate(ch);
        break;
    case 3:
        sound_mix_stop(ch);
        break;
    case 4:
        sound_mix_pause(ch);
        break;
    case 5:
        sound_mix_resume(ch);
        break;
    default:
        return;
    }
    *state = 0;
}

static void sound_mix_update_hook(struct SoundMixChannel *ch) {}

void sound_mix_tick(void) {
    void sound_mix_tick_channel(u32 i) {
        struct SoundMixChannel *ch = &gSoundWork->fifoA + i;

        if (ch->sample && !(ch->flags & 1))
            ch->pendingFrames++;
        sound_mix_run_request(ch);
    }

    sound_mix_tick_channel(0);
    sound_mix_tick_channel(1);
}

void sound_mix_refill_fifo_a(void) {
    sound_lock();
    sound_mix_refill(&gSoundWork->fifoA);
    sound_unlock();
}

void sound_mix_refill_fifo_b(void) {
    sound_lock();
    sound_mix_refill(&gSoundWork->fifoB);
    sound_unlock();
}

static void sound_mix_refill(struct SoundMixChannel *ch) {
    if (ch->sample == 0) {
        ch->idleFrames++;
        return;
    }
    if (ch->flags & 1)
        return;
    sound_mix_update_hook(ch);
    ch->position += 0x10;
    if (ch->pendingFrames) {
        ch->elapsed += ch->pendingFrames;
        ch->pendingFrames = 0;
    }
    if (SAMPLE(ch)->length <= ch->position) {
        if (!(SAMPLE(ch)->flags & 1))
            goto restart;
        sound_stop_fifo_dma(ch->fifo);
        ch->position = SAMPLE(ch)->loopStart;
        sound_start_fifo_dma(ch->fifo, (u32)&SAMPLE(ch)->data[SAMPLE(ch)->loopStart]);
    }
    if (ch->length <= ch->elapsed) {
    restart:
        sound_mix_stop(ch);
        return;
    }
    if (ch->flags & 2) {
        u32 reload = (0x10000 - 0x1000000 / (ch->rate + ch->rateOffset)) | 0x800000;

        ch->timerReload = reload;
        *gSoundTimerRegs[ch->fifo - 1] = reload;
        ch->flags &= ~2;
    }
    if (ch->flags & 4) {
        sound_mix_apply_output(ch);
        ch->flags &= ~4;
    }
}

static void sound_track_clear_echo(struct SoundTrack *track) {
    if (track->echoBuffer != NULL) {
        u32 fill = 0xFFFFFFFF;
        CpuSet(&fill, track->echoBuffer, 0x0500000C);
        track->echoBuffer[0x30] = 0;
    }
}

// Echo: while a PSG track is silent, sound_output_echo replays the note it played echoDelay frames ago
// at 3/16 of the volume.
static u8 sound_track_echo_note(struct SoundTrack *track) {
    u8 *buf = track->echoBuffer;
    s32 i;

    if (buf == NULL)
        return 0xFF;
    i = buf[0x30] - track->echoDelay;
    if (i < 0)
        i += 0x30;
    return buf[i];
}

void sound_track_record_echo(struct SoundTrack *track) {
    u8 *buf = track->echoBuffer;

    if (buf) {
        u8 vol = track->envVolume;
        u8 *pos = &buf[0x30];

        if (vol)
            buf[*pos] = track->note;
        else
            buf[*pos] = 0xFF;
        if (++*pos >= 0x30)
            *pos = 0;
    }
}

// Pause (nonzero) or resume the sound: sets bit 1 of the flags at 0x72C (see sound_is_paused),
// silences the PSG channels and stops the sound effect tracks; resuming re-triggers the music tracks.
static void sound_set_paused_nolock(u32 pause) {
    struct SoundWork **pw = &gSoundWork;

    if (pause) {
        (*pw)->flags |= 2;
        *(vu16 *)0x04000062 &= 0x0FFF;
        *(vu16 *)0x04000064 |= 0x8000;
        *(vu16 *)0x04000068 &= 0x0FFF;
        *(vu16 *)0x0400006C |= 0x8000;
        *(vu16 *)0x04000072 &= 0x1FFF;
        *(vu16 *)0x04000078 &= 0x0FFF;
        *(vu16 *)0x0400007C |= 0x8000;
        if ((*pw)->tracks[10].seqPos)
            sound_mix_queue_stop(&(*pw)->fifoA);
        else if ((*pw)->tracks[8].seqPos)
            sound_mix_queue_pause(&(*pw)->fifoA);
        if (gSoundWork->tracks[11].seqPos)
            sound_mix_queue_stop(&gSoundWork->fifoB);
        else if (gSoundWork->tracks[9].seqPos)
            sound_mix_queue_pause(&gSoundWork->fifoB);
        sound_track_stop(&gSoundWork->tracks[4]);
        sound_track_stop(&gSoundWork->tracks[5]);
        sound_track_stop(&gSoundWork->tracks[6]);
        sound_track_stop(&gSoundWork->tracks[7]);
        sound_track_stop(&gSoundWork->tracks[10]);
        sound_track_stop(&gSoundWork->tracks[11]);
    } else {
        (*pw)->flags &= ~2;
        if (gSoundWork->tracks[4].seqPos == NULL && gSoundWork->tracks[0].seqPos) {
            gSoundWork->tracks[0].dirty |= 0x5F;
            sound_output_sq1(&gSoundWork->tracks[0]);
        }
        if (gSoundWork->tracks[5].seqPos == NULL && gSoundWork->tracks[1].seqPos) {
            gSoundWork->tracks[1].dirty |= 0x5F;
            sound_output_sq2(&gSoundWork->tracks[1]);
        }
        if (gSoundWork->tracks[6].seqPos == NULL && gSoundWork->tracks[2].seqPos) {
            gSoundWork->tracks[2].dirty |= 0x7F;
            sound_output_wave(&gSoundWork->tracks[2]);
        }
        if (gSoundWork->tracks[7].seqPos == NULL && gSoundWork->tracks[3].seqPos) {
            gSoundWork->tracks[3].dirty |= 0x5F;
            sound_output_noise(&gSoundWork->tracks[3]);
        }
        if (gSoundWork->tracks[10].seqPos == NULL && gSoundWork->tracks[8].seqPos) {
            sound_mix_queue_resume(&gSoundWork->fifoA);
            gSoundWork->tracks[8].dirty = 0;
        }
        if (gSoundWork->tracks[11].seqPos == NULL && gSoundWork->tracks[9].seqPos) {
            sound_mix_queue_resume(&gSoundWork->fifoB);
            gSoundWork->tracks[9].dirty = 0;
        }
    }
}

// Not called anywhere in the game.
static void sound_set_paused(u32 pause) {
    sound_lock();
    sound_set_paused_nolock(pause);
    sound_unlock();
}

u32 sound_is_paused(void) {
    return (gSoundWork->flags >> 1) & 1;
}

static void sound_track_start(struct SoundTrack *track, u8 *seq) {
    sound_track_clear_echo(track);
    track->seqPos = seq;
    track->loopPos = NULL;
    track->loop2Pos = NULL;
    track->returnPos = NULL;
    track->drumSeq = NULL;
    track->wait = 0;
    track->fixedLength = 0;
    track->drumWait = 0;
    track->dirty = 0x5F;
    track->loopCount = 0;
    track->loop2Count = 0;
    track->sweep = 8;
    track->detune = 0;
    track->vibratoDelay = 0;
    track->vibratoPeriod = 0;
    track->vibratoDepth = 0;
    track->vibratoWait = 0;
    track->vibratoCounter = 0;
    track->vibratoStep = 0;
    track->vibratoOffset = 0;
    track->noteMode = 0;
    track->note = 0xFF;
    track->volume = 15;
    track->envVolume = 0;
    track->instrument = 0;
    track->unk68 = 0;
    track->noiseParams = 0;
    track->transpose = 0;
    track->echoDelay = 0;
    track->echoNote = 0xFF;
    track->envEnabled = 0;
    track->priority = 0;
    track->lengthHigh = 0;
    track->fadeVolume = 0x1000;
    track->fadeTarget = 0x1000;
    track->fadeStep = 0;
    track->fadeFrames = 0;
    track->pan = 3;
    track->panOverride = 0;
    track->markerCount = 0;
    track->soundId = 0xFFFF;
    sound_track_link(track);
}

static void sound_silence_drum_noise(u32 idx) {
    if (gSoundWork->tracks[idx].seqPos && !sound_is_paused()) {
        if (gSoundWork->tracks[7].seqPos) {
            gSoundWork->tracks[7].dirty |= 0x5F;
            sound_output_noise(&gSoundWork->tracks[7]);
        } else if (gSoundWork->tracks[3].seqPos) {
            gSoundWork->tracks[3].dirty |= 0x5F;
            sound_output_noise(&gSoundWork->tracks[3]);
        } else {
            gSoundWork->tracks[idx].envVolume = 0;
            gSoundWork->tracks[idx].dirty |= 2;
            sound_output_noise(&gSoundWork->tracks[idx]);
        }
    }
}

// SoundTrack.onEnd callbacks (gSoundTrackConfigs): when a music track ends it is output only if no sound
// effect owns the channel; when a sound effect ends the channel goes back to the music track.
void sound_on_music_sq1_end(void) {
    struct SoundWork *work = gSoundWork;

    if (work->tracks[4].seqPos == NULL)
        sound_output_sq1(&work->tracks[0]);
}

void sound_on_music_sq2_end(void) {
    struct SoundWork *work = gSoundWork;

    if (work->tracks[5].seqPos == NULL)
        sound_output_sq2(&work->tracks[1]);
}

void sound_on_music_wave_end(void) {
    struct SoundWork *work = gSoundWork;

    if (work->tracks[6].seqPos == NULL)
        sound_output_wave(&work->tracks[2]);
}

void sound_on_music_noise_end(void) {
    struct SoundWork *work = gSoundWork;

    if (work->tracks[7].seqPos == NULL)
        sound_output_noise(&work->tracks[3]);
}

void sound_on_se_sq1_end(void) {
    sound_output_sq1(&gSoundWork->tracks[4]);
    if (sound_is_paused() == 0) {
        gSoundWork->tracks[0].dirty |= 0x5F;
        sound_output_sq1(&gSoundWork->tracks[0]);
    }
}

void sound_on_se_sq2_end(void) {
    sound_output_sq2(&gSoundWork->tracks[5]);
    if (sound_is_paused() == 0) {
        gSoundWork->tracks[1].dirty |= 0x5F;
        sound_output_sq2(&gSoundWork->tracks[1]);
    }
}

void sound_on_se_wave_end(void) {
    sound_output_wave(&gSoundWork->tracks[6]);
    if (sound_is_paused() == 0) {
        gSoundWork->tracks[2].dirty |= 0x7F;
        sound_output_wave(&gSoundWork->tracks[2]);
    }
}

void sound_on_se_noise_end(void) {
    sound_output_noise(&gSoundWork->tracks[7]);
    if (sound_is_paused() == 0) {
        gSoundWork->tracks[3].dirty |= 0x5F;
        sound_output_noise(&gSoundWork->tracks[3]);
    }
}

void sound_on_music_fifo_a_end(void) {
    struct SoundWork *work = gSoundWork;

    if (work->tracks[10].seqPos == NULL)
        sound_mix_queue_stop(&work->fifoA);
}

void sound_on_music_fifo_b_end(void) {
    struct SoundWork *work = gSoundWork;

    if (work->tracks[11].seqPos == NULL)
        sound_mix_queue_stop(&work->fifoB);
    sound_track_stop(&gSoundWork->tracks[12]);
}

void sound_on_se_fifo_a_end(void) {
    sound_mix_queue_stop(&gSoundWork->fifoA);
    gSoundWork->tracks[10].dirty = 0;
}

void sound_on_se_fifo_b_end(void) {
    sound_mix_queue_stop(&gSoundWork->fifoB);
    gSoundWork->tracks[11].dirty = 0;
    sound_silence_drum_noise(12);
}

void sound_on_drum_noise_end(void) {
    struct SoundWork *work = gSoundWork;

    if (work->tracks[7].seqPos == NULL)
        sound_output_noise(&work->tracks[12]);
}

static void sound_track_reset(struct SoundTrack *track) {
    track->seqPos = 0;
    track->sweep = 0;
    track->echoDelay = 0;
    track->envVolume = 0;
    track->note = 0xFF;
    track->dirty |= 0xA;
    track->priority = 0;
    track->vibratoDepth = 0;
    track->vibratoOffset = 0;
    track->soundId = 0xFFFF;
    track->fadeStep = 0;
}

void sound_track_stop(struct SoundTrack *track) {
    if (track->seqPos != NULL) {
        sound_track_reset(track);
        ((void (*)(void))track->onEnd)();
    }
}

// Inserts the track into the circular list of active tracks (gSoundWork->activeTracks) as its new head.
static void sound_track_link(struct SoundTrack *track) {
    struct SoundTrack **head;

    if (track->next == NULL && track->prev == NULL) {
        head = &gSoundWork->activeTracks;
        if (*head == NULL) {
            track->next = track;
            track->prev = track;
        } else {
            struct SoundTrack *prev = (*head)->prev;

            track->prev = prev;
            track->next = *head;
            prev->next = track;
            track->next->prev = track;
        }
        *head = track;
    }
}

static void sound_track_unlink(struct SoundTrack *track) {
    struct SoundTrack **head;

    if (track->next != NULL || track->prev != NULL) {
        head = &gSoundWork->activeTracks;
        if ((*head)->next == *head) {
            *head = NULL;
        } else {
            track->prev->next = track->next;
            track->next->prev = track->prev;
            if (*head == track)
                *head = track->next;
        }
        track->next = NULL;
        track->prev = NULL;
    }
}

void sound_init_tracks(void) {
    s32 i;
    struct SoundTrack *track;
    for (i = 0, track = gSoundWork->tracks; i < 13; i++, track++) {
        const struct SoundTrackConfig *cfg = &gSoundTrackConfigs[i];
        register void *zero asm("r2") = NULL;
        u8 *p = &track->dirty;
        p[1] = i;
        track->onEnd = cfg->onEnd;
        track->tick = cfg->tick;
        p[0x14] = cfg->channelType;
        track->dirty |= 0x5F;
        track->next = zero;
        track->prev = zero;
        if (cfg->echoBuffer != 0xFF) {
            register struct SoundWork **wp asm("r2") = &gSoundWork;
            track->echoBuffer = (*wp)->echoBuffers[cfg->echoBuffer];
            sound_track_clear_echo(track);
        }
        sound_track_start(track, NULL);
    }
}

void sound_set_song_table(struct SoundSongHeader **val) {
    gSoundWork->songs = val;
}

static void sound_start_song(u32 id, u32 arg) {
    struct SoundWork *work = sound_get_work();
    struct SoundSongHeader *song = work->songs[id];
    u32 i;
    u32 bit;
    u8 **seq;

    sound_track_stop(&work->tracks[0]);
    sound_track_stop(&work->tracks[1]);
    sound_track_stop(&work->tracks[2]);
    sound_track_stop(&work->tracks[3]);
    sound_track_stop(&work->tracks[8]);
    sound_track_stop(&work->tracks[9]);
    sound_track_stop(&work->tracks[12]);

    i = 0;
    bit = 0x800;
    seq = (u8 **)song;
loop:
    if (song->trackMask & bit) {
        struct SoundTrack *track = &work->tracks[i];

        sound_track_start(track, seq[1]);
        track->priority = song->priority;
        track->panOverride = arg;
        seq++;
    }
    bit >>= 1;
    i++;
    if (bit)
        goto loop;

    if (song->trackMask & 4) {
        sound_track_start(&work->tracks[12], work->tracks[9].seqPos);
        work->tracks[12].priority = song->priority;
        work->tracks[12].panOverride = arg;
    }
    work->songId = id;
}

void play_song(u32 id) {
    sound_lock();
    sound_start_song(id, 0);
    sound_unlock();
}

static void play_song_panned(u32 id, u32 arg) {
    sound_lock();
    sound_start_song(id, arg);
    sound_unlock();
}

static void sound_set_music_pan(u32 val) {
    struct SoundWork *work = gSoundWork;

    void sound_track_set_music_pan(struct SoundTrack * track) {
        track->panOverride = val;
        track->dirty |= 0x40;
    }

    sound_track_set_music_pan(&work->tracks[0]);
    sound_track_set_music_pan(&work->tracks[1]);
    sound_track_set_music_pan(&work->tracks[2]);
    sound_track_set_music_pan(&work->tracks[3]);
    sound_track_set_music_pan(&work->tracks[8]);
    sound_track_set_music_pan(&work->tracks[9]);
    sound_track_set_music_pan(&work->tracks[12]);
}

static void set_music_pan(u32 a) {
    sound_lock();
    sound_set_music_pan(a);
    sound_unlock();
}

// guess: the playing song id (songId) while any music track is active, else -1.
u32 sound_current_song(void) {
    struct SoundWork **pw = &gSoundWork;

    if ((*pw)->tracks[0].seqPos || (*pw)->tracks[1].seqPos || (&(*pw)->tracks[2])->seqPos ||
        (&(*pw)->tracks[3])->seqPos || (&(*pw)->tracks[8])->seqPos || (&(*pw)->tracks[9])->seqPos)
        return (*pw)->songId;
    return -1;
}

void sound_set_se_table(struct SoundSongHeader **val) {
    gSoundWork->soundEffects = val;
}

static void sound_start_se(u32 id, u32 arg) {
    struct SoundWork *work = sound_get_work();
    struct SoundSongHeader *song = work->soundEffects[id];
    u32 i;
    u32 bit;
    u8 **seq;

    i = 0;
    bit = 0x800;
    seq = (u8 **)song;
loop:
    if (song->trackMask & bit) {
        struct SoundTrack *track = &work->tracks[i];

        if (track->priority <= song->priority) {
            sound_track_start(track, seq[1]);
            track->priority = song->priority;
            track->soundId = id;
            track->panOverride = arg;
        }
        seq++;
    }
    bit >>= 1;
    i++;
    if (bit)
        goto loop;
}

void play_sound_effect(u32 id) {
    sound_lock();
    sound_start_se(id, 0);
    sound_unlock();
}

static void play_sound_effect_panned(u32 id, u32 arg) {
    sound_lock();
    sound_start_se(id, arg);
    sound_unlock();
}

static void sound_set_se_pan(u32 id, u32 val) {
    struct SoundWork *work = gSoundWork;

    void sound_track_set_se_pan(struct SoundTrack * track) {
        if (track->soundId == id && track->seqPos) {
            track->panOverride = val;
            track->dirty |= 0x40;
        }
    }

    sound_track_set_se_pan(&work->tracks[4]);
    sound_track_set_se_pan(&work->tracks[5]);
    sound_track_set_se_pan(&work->tracks[6]);
    sound_track_set_se_pan(&work->tracks[7]);
    sound_track_set_se_pan(&work->tracks[10]);
    sound_track_set_se_pan(&work->tracks[11]);
}

static void set_sound_effect_pan(u32 a, u32 b) {
    sound_lock();
    sound_set_se_pan(a, b);
    sound_unlock();
}

static s32 sound_track_se_id(u32 idx) {
    struct SoundTrack *track = &sound_get_work()->tracks[idx];
    s32 ret;

    if (track->seqPos != NULL)
        ret = track->soundId;
    else
        ret = -1;
    return ret;
}

static u32 sound_se_is_playing(s32 a) {
    u32 i;
    const u32 *t;

    for (i = 0; i < 6; i++) {
        const u32 **pt = &t;

        t = gSoundEffectTracks;
        t += i;
        if (a == sound_track_se_id(**pt))
            return TRUE;
    }
    return FALSE;
}

u32 is_sound_effect_playing(u32 a) {
    u32 ret;

    sound_lock();
    ret = sound_se_is_playing(a);
    sound_unlock();
    return ret;
}

void sound_set_drum_kit(struct SoundDrumKit *val) {
    gSoundWork->drumKit = val;
}

static void sound_track_start_fade(struct SoundTrack *track, u32 target, u32 frames) {
    s32 step = (s32)(target - track->fadeVolume) / (s32)frames;

    if (step != 0) {
        track->fadeTarget = target;
        track->fadeStep = step;
        track->fadeFrames = frames;
    }
}

static void sound_track_fade_locked(struct SoundTrack *track, u32 target, u32 frames) {
    sound_lock();
    sound_track_start_fade(track, target, frames);
    sound_unlock();
}

static void sound_fade_out_music(u32 frames) {
    void sound_fade_out_track(u32 idx) {
        if (gSoundWork->tracks[idx].seqPos)
            sound_track_fade_locked(&gSoundWork->tracks[idx], 0, frames);
    }

    sound_fade_out_track(0);
    sound_fade_out_track(1);
    sound_fade_out_track(2);
    sound_fade_out_track(3);
    sound_fade_out_track(8);
    sound_fade_out_track(9);
}

void fade_out_music(u32 a) {
    sound_lock();
    sound_fade_out_music(a);
    sound_unlock();
}

u32 is_music_fading(void) {
    u32 ret = 0;
    struct SoundWork *work = gSoundWork;

    if (work->tracks[0].fadeStep || work->tracks[1].fadeStep || work->tracks[2].fadeStep || work->tracks[3].fadeStep ||
        work->tracks[8].fadeStep || work->tracks[9].fadeStep)
        ret = 1;
    return ret;
}

static void sound_get_master_volume(u32 *a, u32 *b) {
    sound_lock();
    *a = gSoundWork->volumeLeft;
    *b = gSoundWork->volumeRight;
    sound_unlock();
}

static void sound_set_master_volume(u32 a, u32 b) {
    sound_lock();
    gSoundWork->volumeLeft = a;
    gSoundWork->volumeRight = b;
    gSoundWork->flags |= 1;
    sound_unlock();
}

static struct SoundWork *sound_get_work(void) {
    return gSoundWork;
}
