#include "global.h"

// Sound sequencer: per-track envelope, vibrato and sequence command handlers.
// Built with agbcc -fprologue-bugfix (see Makefile), unlike the game code before it.

void sound_engine_init(struct Unk_03007014 *work)
{
    u32 zero;

    gUnk_03007014 = work;
    zero = 0;
    CpuSet(&zero, work, 0x050001CD);
    init_all_sound_channels();
    gUnk_03007014->unk6CA = 1;
    gUnk_03007014->unk712 = 2;
    sound_init_wave_channel();
}

void sub_08072280(struct SoundTrack *track)
{
    track->unk61 = 0;
    track->unk66 = 0;
    track->unk50 |= 2;
}

void sound_channel_parse_note_param(struct SoundTrack *track)
{
    if ((track->unk5E >> 4) == 0)
    {
        sub_08072280(track);
    }
    else
    {
        track->unk5F = 1;
        track->unk60 = track->unk5E & 0xF;
        track->unk61 = 5;
    }
}

void sound_channel_tick_decay(struct SoundTrack *track)
{
    if (--track->unk5F == 0)
    {
        if (track->unk60 == 0)
        {
            sub_08072280(track);
        }
        else
        {
            s32 old, vol;

            track->unk60--;
            vol = track->unk66;
            old = vol;
            if (--vol < 0)
                vol = 0;
            if (old != vol)
            {
                track->unk66 = vol;
                track->unk50 |= 2;
            }
            track->unk5F = track->unk5E >> 4;
        }
    }
}

u32 sound_channel_check_and_advance(struct SoundTrack *track)
{
    if (track->unk5D >= track->unk28)
    {
        sound_channel_parse_note_param(track);
        sound_channel_tick_decay(track);
        return 1;
    }
    return 0;
}

void sound_channel_update_position(struct SoundTrack *track)
{
    if (sound_channel_check_and_advance(track) == 0)
    {
        track->unk5F = track->unk5D;
        if (track->unk5F == 0)
            sound_channel_parse_note_param(track);
        else
            track->unk61 = 4;
    }
}

void sound_channel_init_vibrato(struct SoundTrack *track)
{
    if (sound_channel_check_and_advance(track) == 0)
    {
        if ((track->unk5F = track->unk5C >> 4) == 0)
        {
            sound_channel_update_position(track);
        }
        else
        {
            track->unk60 = -(track->unk5C & 0xF);
            track->unk61 = 3;
        }
    }
}

void sound_channel_process_command_080723D4(struct SoundTrack *track)
{
    if (sound_channel_check_and_advance(track) == 0)
    {
        if ((track->unk5F = track->unk5B >> 4) == 0)
        {
            sound_channel_init_vibrato(track);
        }
        else
        {
            track->unk60 = track->unk5B & 0xF;
            track->unk61 = 2;
        }
    }
}

void sound_channel_handle_end(struct SoundTrack *track)
{
    u32 r = sound_channel_check_and_advance(track);

    if (r == 0)
    {
        track->unk5F = 1;
        track->unk60 = r;
        track->unk61 = 1;
    }
}

void sound_channel_tick_duration(struct SoundTrack *track)
{
    if (--track->unk5F == 0)
        sound_channel_process_command_080723D4(track);
}

void sub_08072458(struct SoundTrack *track)
{
    if (--track->unk5F == 0xFF)
    {
        sound_channel_init_vibrato(track);
    }
    else
    {
        u8 *vol = &track->unk66;
        s32 v = track->unk60 + *vol;

        if (v > 15)
            v = 15;
        *vol = v;
        track->unk50 |= 2;
    }
}

void sub_080724A0(struct SoundTrack *track)
{
    if (--track->unk5F == 0xFF)
    {
        sound_channel_update_position(track);
    }
    else
    {
        u8 *vol = &track->unk66;
        s32 v = track->unk60 + *vol;

        if (v < 0)
            v = 0;
        *vol = v;
        track->unk50 |= 2;
    }
}

void sub_080724E8(struct SoundTrack *track)
{
    sound_channel_check_and_advance(track);
}

void sound_dispatch_command(struct SoundTrack *track)
{
    if (track->unk62 != 0)
    {
        switch (track->unk61)
        {
        case 1:
            sound_channel_tick_duration(track);
            break;
        case 2:
            sub_08072458(track);
            break;
        case 3:
            sub_080724A0(track);
            break;
        case 4:
            sub_080724E8(track);
            break;
        case 5:
            sound_channel_tick_decay(track);
            break;
        }
    }
}

void sub_0807255C(struct SoundTrack *track)
{
    s32 diff;
    track->unk59 = track->unk56;
    track->unk5A = track->unk57 >> 1;
    diff = sub_08073140(track->unk48 + 2) - sub_08073140(track->unk48);
    track->unk34 = (u32)(track->unk58 * diff) / track->unk5A;
    track->unk38 = 0;
}

void sub_080725BC(struct SoundTrack *track)
{
    u8 *depth = &track->unk58;
    u8 d = *depth;
    u8 *delay = &track->unk59;
    u8 *count = &track->unk5A;

    if (d == 0)
    {
        *delay = 0;
        *count = 0;
        track->unk34 = 0;
        track->unk38 = 0;
    }
    else
    {
        void *ch = gUnk_03007014->unk690;
        s32 diff;
        s32 acc;

        if (track->unk64 != 4)
            ch = gUnk_03007014->unk6D8;
        {
            u8 v = track->unk56;
            acc = 0;
            *delay = v;
        }
        *count = track->unk57 >> 1;
        diff = sound_set_pitch_offset(ch, track->unk48 + 2) - sound_set_pitch_offset(ch, track->unk48);
        track->unk34 = (u32)(*depth * diff) / *count;
        track->unk38 = acc;
    }
}

void sub_08072658(struct SoundTrack *track)
{
    if (track->unk58 != 0)
    {
        if (track->unk59 != 0)
        {
            track->unk59--;
        }
        else
        {
            track->unk38 += track->unk34;
            track->unk50 |= 1;
            if (track->unk5A != 0)
            {
                track->unk5A--;
            }
            else
            {
                track->unk5A = track->unk57;
                track->unk34 = -track->unk34;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatching/sound_seq", sound_channel_update_pitch_sweep);

u32 sub_08072708(struct SoundTrack *track)
{
    u8 *p = track->unk14;
    u32 val = p[0] + (p[1] << 8) + (p[2] << 16) + (p[3] << 24);

    track->unk14 = p + 4;
    return val;
}

INCLUDE_ASM("asm/nonmatching/sound_seq", sound_set_channel_note);
INCLUDE_ASM("asm/nonmatching/sound_seq", sound_channel_update_note_08072798);

void sub_08072948(struct SoundTrack *track)
{
    track->unk48 = 0xFF;
    track->unk6C = 0xFF;
    track->unk46 = 0;
    track->unk28 = *track->unk14++ + 1;
    track->unk66 = 0;
    track->unk50 |= 0x52;
}

void sub_08072984(struct SoundTrack *track, u8 val)
{
    track->unk65 = val;
    track->unk66 = val;
    track->unk50 |= 2;
}

void sub_080729A0(struct SoundTrack *obj, u8 val)
{
    obj->unk2C = val;
}

void sub_080729A8(struct SoundTrack *track, u32 val)
{
    track->unk69 = val;
    track->unk50 |= 0x51;
}

void sub_080729BC(struct SoundTrack *track)
{
    track->unk67 = *track->unk14++;
    track->unk50 |= 0x20;
}

void sub_080729D8(struct SoundTrack *track, u32 val)
{
    track->unk67 = val;
    track->unk50 |= 4;
}

void sub_080729EC(struct SoundTrack *track)
{
    track->unk6A = *track->unk14++;
}

void sub_080729FC(struct SoundTrack *track)
{
    track->unk6B = *track->unk14++;
    if (track->unk6B > 0x30)
        track->unk6B = 0x30;
}

void sub_08072A18(struct SoundTrack *track)
{
    track->unk6F = *track->unk14++;
    track->unk50 |= 0x40;
}

void sub_08072A34(struct SoundTrack *track)
{
    track->unk4C++;
}

void sub_08072A40(struct SoundTrack *track)
{
    track->unk52 = *track->unk14++;
    track->unk18 = track->unk14;
}

void sub_08072A54(struct SoundTrack *track)
{
    if (--track->unk52 != 0)
        track->unk14 = track->unk18;
}

void sub_08072A6C(struct SoundTrack *track)
{
    track->unk53 = *track->unk14++;
    track->unk1C = track->unk14;
}

void sub_08072A80(struct SoundTrack *track)
{
    if (--track->unk53 != 0)
        track->unk14 = track->unk1C;
}

void stream_read_u32_to_field(struct SoundTrack *track)
{
    track->unk14 = (u8 *)sub_08072708(track);
}

void stream_read_and_shift_u32(struct SoundTrack *track)
{
    u8 *ptr = (u8 *)sub_08072708(track);
    track->unk20 = track->unk14;
    track->unk14 = ptr;
}

void sub_08072ABC(struct SoundTrack *obj)
{
    obj->unk14 = obj->unk20;
}

void sub_08072AC4(struct SoundTrack *track)
{
    track->unk54 = *track->unk14++;
    if (track->unk54 == 0)
        track->unk54 = 8;
    track->unk50 |= 8;
}

void sub_08072AEC(struct SoundTrack *track)
{
    track->unk55 = *track->unk14++;
}

void sub_08072AFC(struct SoundTrack *track)
{
    u8 val;

    track->unk56 = *track->unk14++;
    val = *track->unk14++;
    track->unk58 = val >> 4;
    track->unk57 = val & 0xF;
}

void sub_08072B28(struct SoundTrack *track)
{
    track->unk6E = *track->unk14++;
}

void sound_read_envelope_params(struct SoundTrack *track)
{
    track->unk5B = *track->unk14++;
    track->unk5C = *track->unk14++;
    track->unk5D = *track->unk14++;
    track->unk5E = *track->unk14++;
    track->unk62 = 1;
    switch (track->unk64)
    {
    case 0:
    case 1:
    case 2:
        sound_channel_handle_end(track);
        break;
    }
}

void sound_channel_enable(struct SoundTrack *track)
{
    track->unk62 = 1;
    switch (track->unk64)
    {
    case 0:
    case 1:
    case 2:
        sound_channel_handle_end(track);
        break;
    }
}

void sound_channel_disable(struct SoundTrack *track)
{
    track->unk62 = 0;
    switch (track->unk64)
    {
    case 0:
    case 1:
    case 2:
        sound_channel_handle_end(track);
        break;
    }
}

void sub_08072BD4(struct SoundTrack *track)
{
    track->unk63 = *track->unk14++;
}

void sub_08072BE4(struct SoundTrack *track)
{
    sound_channel_finish_and_callback(track);
}

void sound_channel_process_event(struct SoundTrack *track)
{
    u8 cmd;

    if (track->unk14 == NULL)
        return;
    cmd = *track->unk14++;
    switch (cmd)
    {
    case 0xE0:
        sub_08072948(track);
        break;
    case 0xE1:
        sub_080729A0(track, *track->unk14++);
        break;
    case 0xE2:
        sub_080729A8(track, *track->unk14++);
        break;
    case 0xE3:
        sub_080729BC(track);
        break;
    case 0xE4:
        sub_080729D8(track, 0);
        break;
    case 0xE5:
        sub_080729D8(track, 0x40);
        break;
    case 0xE6:
        sub_080729D8(track, 0x80);
        break;
    case 0xE7:
        sub_080729D8(track, 0xC0);
        break;
    case 0xE8:
        sub_080729EC(track);
        break;
    case 0xE9:
        sub_080729FC(track);
        break;
    case 0xEA:
        sub_08072A18(track);
        break;
    case 0xEB:
        sub_08072A34(track);
        break;
    case 0xF0:
        sub_08072A40(track);
        break;
    case 0xF1:
        sub_08072A54(track);
        break;
    case 0xF2:
        sub_08072A6C(track);
        break;
    case 0xF3:
        sub_08072A80(track);
        break;
    case 0xF4:
        stream_read_u32_to_field(track);
        break;
    case 0xF5:
        stream_read_and_shift_u32(track);
        break;
    case 0xF6:
        sub_08072ABC(track);
        break;
    case 0xF7:
        sub_08072AC4(track);
        break;
    case 0xF8:
        sub_08072AEC(track);
        break;
    case 0xF9:
        sub_08072AFC(track);
        break;
    case 0xFA:
        sub_08072B28(track);
        break;
    case 0xFB:
        sound_read_envelope_params(track);
        break;
    case 0xFC:
        sound_channel_enable(track);
        break;
    case 0xFD:
        sound_channel_disable(track);
        break;
    case 0xFE:
        sub_08072BD4(track);
        break;
    case 0xFF:
        sub_08072BE4(track);
        break;
    default:
        switch (cmd & 0xF0)
        {
        case 0x80:
            sub_08072948(track);
            break;
        case 0x90:
        case 0xA0:
        case 0xB0:
        case 0xC0:
            break;
        case 0xD0:
            sub_08072984(track, cmd & 0xF);
            if (track->unk63 == 1 && track->unk64 == 3 && track->unk24 == NULL)
            {
                track->unk28 = track->unk2C;
                track->unk50 |= 0x50;
            }
            break;
        default:
            sound_channel_update_note_08072798(track, cmd);
            break;
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatching/sound_seq", sound_channel_process_command_08072E04);

void sub_08072E7C(struct SoundTrack *track)
{
    sub_08072658(track);
    sound_dispatch_command(track);
    sound_channel_update_pitch_sweep(track);
}

void sub_08072E98(struct SoundTrack *track)
{
    if (track->unk24 != NULL)
    {
        if (track->unk30 != 0)
            track->unk30--;
        while (track->unk30 == 0)
        {
            sound_channel_process_command_08072E04(track);
            if (track->unk24 == NULL)
                break;
        }
    }
    sound_channel_update_pitch_sweep(track);
}

void sub_08072ECC(struct SoundTrack *track)
{
    sub_08072658(track);
    sound_channel_update_pitch_sweep(track);
}

void sound_channel_advance_sequence(struct SoundTrack *track)
{
    if (track->unk14 != NULL)
    {
        track->unk6E = 0;
        if (track->unk28 != 0)
            track->unk28--;
        while (track->unk28 == 0)
        {
            sound_channel_process_event(track);
            if (track->unk14 == NULL)
                break;
        }
        track->unk10(track);
    }
}

INCLUDE_ASM("asm/nonmatching/sound_seq", sound_engine_update_all_channels);
