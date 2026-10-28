// Sound sequencer: the first half of the game's own sound engine (not m4a). sound_engine_init sets up the
// work area at gSoundWork; per track it runs the volume envelope (sound_env_*: key-on, attack, decay,
// sustain, release), vibrato and volume fade, and reads the sequence byte stream (sound_track_run_command,
// opcodes 0xE0-0xFF). sound_engine_update is the per-frame entry, called from the driver
// (audio/sound_driver.c), which writes the results to the GBA sound registers.

#include "global.h"

static void sound_track_run_command(struct SoundTrack *track);

void sound_engine_init(struct SoundWork *work) {
    u32 zero;

    gSoundWork = work;
    zero = 0;
    CpuSet(&zero, work, 0x050001CD);
    sound_init_tracks();
    gSoundWork->fifoA.fifo = 1;
    gSoundWork->fifoB.fifo = 2;
    sound_init_wave_channel();
}

static void sound_env_off(struct SoundTrack *track) {
    track->envPhase = 0;
    track->envVolume = 0;
    track->dirty |= 2;
}

static void sound_env_start_release(struct SoundTrack *track) {
    if ((track->envRelease >> 4) == 0) {
        sound_env_off(track);
    } else {
        track->envCounter = 1;
        track->envStep = track->envRelease & 0xF;
        track->envPhase = 5;
    }
}

static void sound_env_tick_release(struct SoundTrack *track) {
    if (--track->envCounter == 0) {
        if (track->envStep == 0) {
            sound_env_off(track);
        } else {
            s32 old, vol;

            track->envStep--;
            vol = track->envVolume;
            old = vol;
            if (--vol < 0)
                vol = 0;
            if (old != vol) {
                track->envVolume = vol;
                track->dirty |= 2;
            }
            track->envCounter = track->envRelease >> 4;
        }
    }
}

static u32 sound_env_check_release(struct SoundTrack *track) {
    if (track->envReleaseAt >= track->wait) {
        sound_env_start_release(track);
        sound_env_tick_release(track);
        return 1;
    }
    return 0;
}

static void sound_env_start_sustain(struct SoundTrack *track) {
    if (sound_env_check_release(track) == 0) {
        track->envCounter = track->envReleaseAt;
        if (track->envCounter == 0)
            sound_env_start_release(track);
        else
            track->envPhase = 4;
    }
}

static void sound_env_start_decay(struct SoundTrack *track) {
    if (sound_env_check_release(track) == 0) {
        if ((track->envCounter = track->envDecay >> 4) == 0) {
            sound_env_start_sustain(track);
        } else {
            track->envStep = -(track->envDecay & 0xF);
            track->envPhase = 3;
        }
    }
}

static void sound_env_start_attack(struct SoundTrack *track) {
    if (sound_env_check_release(track) == 0) {
        if ((track->envCounter = track->envAttack >> 4) == 0) {
            sound_env_start_decay(track);
        } else {
            track->envStep = track->envAttack & 0xF;
            track->envPhase = 2;
        }
    }
}

static void sound_env_key_on(struct SoundTrack *track) {
    u32 releasing = sound_env_check_release(track);

    if (releasing == 0) {
        track->envCounter = 1;
        track->envStep = releasing;
        track->envPhase = 1;
    }
}

static void sound_env_tick_delay(struct SoundTrack *track) {
    if (--track->envCounter == 0)
        sound_env_start_attack(track);
}

static void sound_env_tick_attack(struct SoundTrack *track) {
    if (--track->envCounter == 0xFF) {
        sound_env_start_decay(track);
    } else {
        u8 *vol = &track->envVolume;
        s32 volume = track->envStep + *vol;

        if (volume > 15)
            volume = 15;
        *vol = volume;
        track->dirty |= 2;
    }
}

static void sound_env_tick_decay(struct SoundTrack *track) {
    if (--track->envCounter == 0xFF) {
        sound_env_start_sustain(track);
    } else {
        u8 *vol = &track->envVolume;
        s32 volume = track->envStep + *vol;

        if (volume < 0)
            volume = 0;
        *vol = volume;
        track->dirty |= 2;
    }
}

static void sound_env_tick_sustain(struct SoundTrack *track) {
    sound_env_check_release(track);
}

static void sound_env_update(struct SoundTrack *track) {
    if (track->envEnabled != 0) {
        switch (track->envPhase) {
        case 1:
            sound_env_tick_delay(track);
            break;
        case 2:
            sound_env_tick_attack(track);
            break;
        case 3:
            sound_env_tick_decay(track);
            break;
        case 4:
            sound_env_tick_sustain(track);
            break;
        case 5:
            sound_env_tick_release(track);
            break;
        }
    }
}

// Vibrato restarts on every note: depth is in units of the frequency gap of 2 semitones per half period.
static void sound_vibrato_start_psg(struct SoundTrack *track) {
    s32 diff;
    track->vibratoWait = track->vibratoDelay;
    track->vibratoCounter = track->vibratoPeriod >> 1;
    diff = sound_psg_note_freq(track->note + 2) - sound_psg_note_freq(track->note);
    track->vibratoStep = (u32)(track->vibratoDepth * diff) / track->vibratoCounter;
    track->vibratoOffset = 0;
}

void sound_vibrato_start_direct(struct SoundTrack *track) {
    u8 *depth = &track->vibratoDepth;
    u8 depth_value = *depth;
    u8 *delay = &track->vibratoWait;
    u8 *count = &track->vibratoCounter;

    if (depth_value == 0) {
        *delay = 0;
        *count = 0;
        track->vibratoStep = 0;
        track->vibratoOffset = 0;
    } else {
        void *ch = &gSoundWork->fifoA;
        s32 diff;
        s32 acc;

        if (track->channelType != 4)
            ch = &gSoundWork->fifoB;
        {
            u8 start_delay = track->vibratoDelay;
            acc = 0;
            *delay = start_delay;
        }
        *count = track->vibratoPeriod >> 1;
        diff = sound_set_pitch_offset(ch, track->note + 2) - sound_set_pitch_offset(ch, track->note);
        track->vibratoStep = (u32)(*depth * diff) / *count;
        track->vibratoOffset = acc;
    }
}

static void sound_vibrato_tick(struct SoundTrack *track) {
    if (track->vibratoDepth != 0) {
        if (track->vibratoWait != 0) {
            track->vibratoWait--;
        } else {
            track->vibratoOffset += track->vibratoStep;
            track->dirty |= 1;
            if (track->vibratoCounter != 0) {
                track->vibratoCounter--;
            } else {
                track->vibratoCounter = track->vibratoPeriod;
                track->vibratoStep = -track->vibratoStep;
            }
        }
    }
}

static void sound_track_tick_fade(struct SoundTrack *track) {
    s16 *delta = &track->fadeStep;

    if (track->fadeStep != 0) {
        u32 frames_left = track->fadeFrames;
        u16 *cur = &track->fadeVolume;

        if (frames_left != 0 && (track->fadeFrames = frames_left - 1) != 0) {
            *cur += track->fadeStep;
            if (track->outVolume != ((track->envVolume * *cur) & 0xF000))
                track->dirty |= 2;
        } else {
            u16 target = track->fadeTarget;
            s16 zero = 0;

            *cur = target;
            *delta = zero;
            sound_track_stop(track);
        }
    }
}

static u32 sound_seq_read_u32(struct SoundTrack *track) {
    u8 *pos = track->seqPos;
    u32 val = pos[0] + (pos[1] << 8) + (pos[2] << 16) + (pos[3] << 24);

    track->seqPos = pos + 4;
    return val;
}

static void sound_track_start_drum(struct SoundTrack *track, u8 note) {
    struct SoundWork **pw = &gSoundWork;
    struct SoundDrumKit *tbl = (*pw)->drumKit;
    s32 idx = note - tbl->base;

    if (idx < 0)
        idx = 0;
    else if (tbl->count - 1 < idx)
        idx = tbl->count - 1;
    track->note = idx;
    track->echoNote = 0xFF;
    track->freq = 0;
    track->drumSeq = (*pw)->drumKit->entries[idx];
    track->drumWait = 0;
    track->dirty |= 0x52;
}

static void sound_track_play_note(struct SoundTrack *track, u8 note) {
    s32 n;

    track->envVolume = track->volume;
    switch (track->noteMode) {
    case 0:
        track->wait = (track->lengthHigh << 8) + *track->seqPos++ + 1;
        track->lengthHigh = 0;
        switch (track->channelType) {
        case 0:
        case 1:
        case 2: {
            n = note + (s8)track->transpose - 36;
            if (n < 0)
                n = 0;
            else if (n > 0x47)
                n = 0x47;
            track->note = n;
            track->echoNote = 0xFF;
            track->freq = sound_psg_note_freq(track->note);
            track->dirty |= 0x53;
            sound_vibrato_start_psg(track);
            sound_env_key_on(track);
            break;
        }
        case 3:
            sound_track_start_drum(track, note);
            break;
        case 4:
        case 5:
            track->note = note;
            track->dirty |= 0x50;
            break;
        }
        break;
    case 1:
        track->wait = track->fixedLength;
        track->echoNote = 0xFF;
        switch (track->channelType) {
        case 0:
        case 1:
        case 2:
            track->note = 0;
            track->freq = (note << 8) | *track->seqPos++;
            track->dirty |= 0x53;
            break;
        case 4:
        case 5:
            track->note = (note << 8) | *track->seqPos++;
            track->freq = 0;
            track->dirty |= 0x50;
            break;
        }
        break;
    case 2:
        track->wait = (track->lengthHigh << 8) + *track->seqPos++ + 1;
        track->lengthHigh = 0;
        switch (track->channelType) {
        case 3:
            sound_track_start_drum(track, note);
            break;
        case 4:
        case 5: {
            n = note - gSoundWork->drumKit->base;
            if (n < 0)
                n = 0;
            else if (gSoundWork->drumKit->count - 1 < n)
                n = gSoundWork->drumKit->count - 1;
            track->note = n;
            track->dirty |= 0x50;
            break;
        }
        }
        break;
    }
}

static void sound_cmd_rest(struct SoundTrack *track) {
    track->note = 0xFF;
    track->echoNote = 0xFF;
    track->freq = 0;
    track->wait = *track->seqPos++ + 1;
    track->envVolume = 0;
    track->dirty |= 0x52;
}

static void sound_track_set_volume(struct SoundTrack *track, u8 val) {
    track->volume = val;
    track->envVolume = val;
    track->dirty |= 2;
}

static void sound_cmd_set_fixed_length(struct SoundTrack *obj, u8 val) {
    obj->fixedLength = val;
}

static void sound_cmd_set_noise_params(struct SoundTrack *track, u32 val) {
    track->noiseParams = val;
    track->dirty |= 0x51;
}

static void sound_cmd_set_instrument(struct SoundTrack *track) {
    track->instrument = *track->seqPos++;
    track->dirty |= 0x20;
}

static void sound_cmd_set_duty(struct SoundTrack *track, u32 val) {
    track->instrument = val;
    track->dirty |= 4;
}

static void sound_cmd_set_transpose(struct SoundTrack *track) {
    track->transpose = *track->seqPos++;
}

static void sound_cmd_set_echo_delay(struct SoundTrack *track) {
    track->echoDelay = *track->seqPos++;
    if (track->echoDelay > 0x30)
        track->echoDelay = 0x30;
}

static void sound_cmd_set_pan(struct SoundTrack *track) {
    track->pan = *track->seqPos++;
    track->dirty |= 0x40;
}

static void sound_cmd_marker(struct SoundTrack *track) {
    track->markerCount++;
}

static void sound_cmd_loop_start(struct SoundTrack *track) {
    track->loopCount = *track->seqPos++;
    track->loopPos = track->seqPos;
}

static void sound_cmd_loop_end(struct SoundTrack *track) {
    if (--track->loopCount != 0)
        track->seqPos = track->loopPos;
}

static void sound_cmd_loop2_start(struct SoundTrack *track) {
    track->loop2Count = *track->seqPos++;
    track->loop2Pos = track->seqPos;
}

static void sound_cmd_loop2_end(struct SoundTrack *track) {
    if (--track->loop2Count != 0)
        track->seqPos = track->loop2Pos;
}

static void sound_cmd_jump(struct SoundTrack *track) {
    track->seqPos = (u8 *)sound_seq_read_u32(track);
}

static void sound_cmd_call(struct SoundTrack *track) {
    u8 *ptr = (u8 *)sound_seq_read_u32(track);
    track->returnPos = track->seqPos;
    track->seqPos = ptr;
}

static void sound_cmd_return(struct SoundTrack *obj) {
    obj->seqPos = obj->returnPos;
}

static void sound_cmd_set_sweep(struct SoundTrack *track) {
    track->sweep = *track->seqPos++;
    if (track->sweep == 0)
        track->sweep = 8;
    track->dirty |= 8;
}

static void sound_cmd_set_detune(struct SoundTrack *track) {
    track->detune = *track->seqPos++;
}

static void sound_cmd_set_vibrato(struct SoundTrack *track) {
    u8 val;

    track->vibratoDelay = *track->seqPos++;
    val = *track->seqPos++;
    track->vibratoDepth = val >> 4;
    track->vibratoPeriod = val & 0xF;
}

static void sound_cmd_set_length_high(struct SoundTrack *track) {
    track->lengthHigh = *track->seqPos++;
}

static void sound_cmd_set_envelope(struct SoundTrack *track) {
    track->envAttack = *track->seqPos++;
    track->envDecay = *track->seqPos++;
    track->envReleaseAt = *track->seqPos++;
    track->envRelease = *track->seqPos++;
    track->envEnabled = 1;
    switch (track->channelType) {
    case 0:
    case 1:
    case 2:
        sound_env_key_on(track);
        break;
    }
}

static void sound_cmd_envelope_on(struct SoundTrack *track) {
    track->envEnabled = 1;
    switch (track->channelType) {
    case 0:
    case 1:
    case 2:
        sound_env_key_on(track);
        break;
    }
}

static void sound_cmd_envelope_off(struct SoundTrack *track) {
    track->envEnabled = 0;
    switch (track->channelType) {
    case 0:
    case 1:
    case 2:
        sound_env_key_on(track);
        break;
    }
}

static void sound_cmd_set_note_mode(struct SoundTrack *track) {
    track->noteMode = *track->seqPos++;
}

static void sound_cmd_end(struct SoundTrack *track) {
    sound_track_stop(track);
}

// One sequence command: 0x00-0x7F a note (followed by its length), 0x80-0x8F a rest, 0xD0-0xDF set volume,
// 0xE0-0xFF the commands below (0xF0-0xF3 two loop levels, 0xF4 jump, 0xF5 call / 0xF6 return, 0xFF end).
static void sound_track_run_command(struct SoundTrack *track) {
    u8 cmd;

    if (track->seqPos == NULL)
        return;
    cmd = *track->seqPos++;
    switch (cmd) {
    case 0xE0:
        sound_cmd_rest(track);
        break;
    case 0xE1:
        sound_cmd_set_fixed_length(track, *track->seqPos++);
        break;
    case 0xE2:
        sound_cmd_set_noise_params(track, *track->seqPos++);
        break;
    case 0xE3:
        sound_cmd_set_instrument(track);
        break;
    case 0xE4:
        sound_cmd_set_duty(track, 0);
        break;
    case 0xE5:
        sound_cmd_set_duty(track, 0x40);
        break;
    case 0xE6:
        sound_cmd_set_duty(track, 0x80);
        break;
    case 0xE7:
        sound_cmd_set_duty(track, 0xC0);
        break;
    case 0xE8:
        sound_cmd_set_transpose(track);
        break;
    case 0xE9:
        sound_cmd_set_echo_delay(track);
        break;
    case 0xEA:
        sound_cmd_set_pan(track);
        break;
    case 0xEB:
        sound_cmd_marker(track);
        break;
    case 0xF0:
        sound_cmd_loop_start(track);
        break;
    case 0xF1:
        sound_cmd_loop_end(track);
        break;
    case 0xF2:
        sound_cmd_loop2_start(track);
        break;
    case 0xF3:
        sound_cmd_loop2_end(track);
        break;
    case 0xF4:
        sound_cmd_jump(track);
        break;
    case 0xF5:
        sound_cmd_call(track);
        break;
    case 0xF6:
        sound_cmd_return(track);
        break;
    case 0xF7:
        sound_cmd_set_sweep(track);
        break;
    case 0xF8:
        sound_cmd_set_detune(track);
        break;
    case 0xF9:
        sound_cmd_set_vibrato(track);
        break;
    case 0xFA:
        sound_cmd_set_length_high(track);
        break;
    case 0xFB:
        sound_cmd_set_envelope(track);
        break;
    case 0xFC:
        sound_cmd_envelope_on(track);
        break;
    case 0xFD:
        sound_cmd_envelope_off(track);
        break;
    case 0xFE:
        sound_cmd_set_note_mode(track);
        break;
    case 0xFF:
        sound_cmd_end(track);
        break;
    default:
        switch (cmd & 0xF0) {
        case 0x80:
            sound_cmd_rest(track);
            break;
        case 0x90:
        case 0xA0:
        case 0xB0:
        case 0xC0:
            break;
        case 0xD0:
            sound_track_set_volume(track, cmd & 0xF);
            if (track->noteMode == 1 && track->channelType == 3 && track->drumSeq == NULL) {
                track->wait = track->fixedLength;
                track->dirty |= 0x50;
            }
            break;
        default:
            sound_track_play_note(track, cmd);
            break;
        }
        break;
    }
}

static void sound_track_run_drum_command(struct SoundTrack *track) {
    if (track->drumSeq != NULL) {
        u8 cmd = *track->drumSeq++;

        if ((cmd & 0xF0) == 0xD0) {
            sound_track_set_volume(track, cmd & 0xF);
            track->drumWait = track->fixedLength;
            track->dirty |= 1;
        } else {
            switch (cmd) {
            case 0xFF:
                sound_track_set_volume(track, 0);
                track->drumSeq = NULL;
                break;
            case 0xE0:
                break;
            case 0xE1:
                sound_cmd_set_fixed_length(track, *track->drumSeq++);
                break;
            case 0xE2:
                sound_cmd_set_noise_params(track, *track->drumSeq++);
                break;
            }
        }
    }
}

// Per-frame tick callbacks (SoundTrack.tick, from gSoundTrackConfigs): PSG square / wave tracks, noise tracks
// (which play the drum sub-sequences) and Direct Sound tracks.
void sound_track_tick_psg(struct SoundTrack *track) {
    sound_vibrato_tick(track);
    sound_env_update(track);
    sound_track_tick_fade(track);
}

void sound_track_tick_noise(struct SoundTrack *track) {
    if (track->drumSeq != NULL) {
        if (track->drumWait != 0)
            track->drumWait--;
        while (track->drumWait == 0) {
            sound_track_run_drum_command(track);
            if (track->drumSeq == NULL)
                break;
        }
    }
    sound_track_tick_fade(track);
}

void sound_track_tick_direct(struct SoundTrack *track) {
    sound_vibrato_tick(track);
    sound_track_tick_fade(track);
}

static void sound_track_advance(struct SoundTrack *track) {
    if (track->seqPos != NULL) {
        track->lengthHigh = 0;
        if (track->wait != 0)
            track->wait--;
        while (track->wait == 0) {
            sound_track_run_command(track);
            if (track->seqPos == NULL)
                break;
        }
        track->tick(track);
    }
}

static inline u8 *track_ptr(struct SoundTrack *track) {
    return track->seqPos;
}

static inline u8 track_note_mode(struct SoundTrack *track) {
    return track->noteMode;
}

void sound_engine_update(void) {
    struct SoundTrack *track = gSoundWork->activeTracks;
    struct SoundTrack *next;
    struct SoundTrack *override;

    if (track != NULL) {
        do {
            next = track->next;
            if (gSoundWork->flags & 2) {
                switch (track->index) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 8:
                case 9:
                case 12:
                    break;
                default:
                    sound_track_advance(track);
                    break;
                }
            } else {
                sound_track_advance(track);
            }
            track = next;
        } while (track != gSoundWork->activeTracks);
    }

    {
        register struct SoundWork **wp asm("r0") = &gSoundWork;
        track = (*wp)->tracks;
    }
    override = &track[4];
    if (override->seqPos != NULL)
        sound_output_sq1(override);
    else if (sound_is_paused() == 0)
        sound_output_sq1(&track[0]);

    override = &track[5];
    if (override->seqPos != NULL)
        sound_output_sq2(override);
    else if (sound_is_paused() == 0)
        sound_output_sq2(&track[1]);

    override = &track[6];
    if (override->seqPos != NULL)
        sound_output_wave(override);
    else if (sound_is_paused() == 0)
        sound_output_wave(&track[2]);

    override = &track[7];
    if (override->seqPos != NULL)
        sound_output_noise(override);
    else if (sound_is_paused() == 0) {
        override = &track[12];
        if (override->seqPos != NULL && track_ptr(&track[9]) != NULL && track_note_mode(&track[9]) == 2 &&
            track_ptr(&track[11]) != NULL)
            sound_output_noise(override);
        else
            sound_output_noise(&track[3]);
    }

    override = &track[10];
    if (override->seqPos != NULL)
        sound_output_fifo_a(override);
    else if (sound_is_paused() == 0)
        sound_output_fifo_a(&track[8]);

    override = &track[11];
    if (override->seqPos != NULL)
        sound_output_fifo_b(override);
    else if (sound_is_paused() == 0)
        sound_output_fifo_b(&track[9]);

    if (sound_is_paused() == 0) {
        sound_track_record_echo(&track[0]);
        sound_track_record_echo(&track[1]);
        sound_track_record_echo(&track[2]);
    }
    sound_update_master_volume();
}
