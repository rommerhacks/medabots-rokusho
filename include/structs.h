#ifndef GUARD_STRUCTS_H
#define GUARD_STRUCTS_H

// Structures that are not understood yet. Fields are named by offset.

// Sound sequence track (sound_seq.c), 0x74 bytes; unk14 is the read pointer into the sequence data.
struct SoundTrack
{
    struct SoundTrack *unk0; // previous in the circular list at gUnk_03007014->unk5E4
    struct SoundTrack *unk4; // next in the circular list at gUnk_03007014->unk5E4
    u8 *unk8; // ring buffer of 0x30 bytes, write index at unk8[0x30]
    u32 unkC;
    void (*unk10)(struct SoundTrack *track);
    u8 *unk14;
    u8 *unk18;
    u8 *unk1C;
    u8 *unk20;
    u8 *unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    s32 unk34;
    s32 unk38;
    u32 unk3C; // fade: frames left
    u16 unk40; // fade: current volume scale (0x1000 = full)
    u16 unk42; // fade: target volume scale
    s16 unk44; // fade: step per frame
    u16 unk46;
    u16 unk48;
    u16 unk4A;
    u16 unk4C;
    u16 unk4E;
    u8 unk50; // dirty flags
    u8 unk51;
    u8 unk52;
    u8 unk53;
    u8 unk54;
    u8 unk55;
    u8 unk56;
    u8 unk57;
    u8 unk58;
    u8 unk59;
    u8 unk5A; // Medabot detail cursor: 0 Medal, 1-4 Medaparts (runtime-checked)
    u8 envAttack; // high nibble: frames per step, low nibble: volume step
    u8 envDecay; // same layout as envAttack
    u8 envReleaseAt; // release starts when this many frames of the note remain
    u8 envRelease; // high nibble: frames per step, low nibble: steps
    u8 envCounter; // frames until the next envelope step
    s8 envStep; // volume change per step / steps left in release
    u8 envPhase; // 0 off, 1 key-on delay, 2 attack, 3 decay, 4 sustain, 5 release
    u8 envEnabled;
    u8 unk63;
    u8 unk64;
    u8 volume;
    u8 envVolume; // current envelope volume (0..15)
    u8 unk67;
    u8 unk68;
    u8 unk69;
    u8 unk6A;
    u8 unk6B;
    u8 unk6C;
    u8 unk6D;
    u8 unk6E;
    u8 unk6F;
    u8 unk70;
    u8 filler71[0x3];
};

// Header of a Direct Sound sample (pointed to by SoundMixChannel.unk0).
struct SoundSampleHeader
{
    u32 unk0;
    u16 rate; // playback rate at baseNote
    u8 fineTune; // 1/128 semitones
    u8 baseNote;
    u32 unk8;
    u32 unkC;
    s8 data[1]; // 8-bit PCM
};

// Direct Sound channel (FIFO A / B) state, 0x48 bytes, two of them in the sound work area.
struct SoundMixChannel
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u8 unk30;
    u8 unk31;
    u8 filler32[0x2];
    u16 unk34;
    u16 unk36;
    u16 unk38;
    u8 unk3A; // 1 = FIFO A, 2 = FIFO B
    u8 unk3B;
    u8 unk3C;
    u8 filler3D[0x1];
    u8 unk3E; // state
    u8 unk3F; // Medals list: tab (6 Medals per tab)
    u8 unk40; // Medals list: row
    u8 filler41[0x3];
    u32 unk44; // counts frames while no sample is set
};

struct Unk_03006D20
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 filler4[0x4];
    s16 unk8;
    u8 unkA; // sprite slot (gUnk_03002C30 index)
    u8 unkB;
    u8 unkC;
    u8 fillerD[0x3];
};

// 0x03002B70: money, then a 10-byte string (init_save_prompt_text writes a default one).
struct Unk_03002B70
{
    u32 money;
    u8 unk4[10];
};

struct Unk_03000440
{
    u8 filler0[0x4];
    u8 unk4; // message handler state (run_message)
    u8 filler5[0x3];
    const u8 *unk8; // current message (run_message)
    u16 unkC;
    u8 unkE;
    u8 fillerF[0xC];
    u8 unk1B;
    u8 filler1C[0xC];
    u8 unk28;
    u8 unk29; // choice menu state (poll_choice_menu)
    u8 filler2A[0x6];
    u8 unk30; // game state to return to from game state 63 (debug_menu_exit)
    u8 unk31; // its sub-state
    u8 unk32; // game state 63 menu cursor, 0-10 (debug_menu_select_input)
    u8 unk33; // game state 63 submenu sub-state
    u8 unk34; // game state 63 submenu row
    u8 unk35[3]; // game state 63 submenu values, one per row
    u8 filler38;
    u8 unk39; // game state 63 "Motion" entry: scene / animation id 0-0x79 (START / SELECT)
    u8 filler3A[0x2];
    u8 unk3C; // where the Medals / Medaparts screen was opened from: 0 Medawatch, 1 Medabot detail (medabot_detail_open_info), 2/4 others
    u8 unk3D; // Medal / Medapart id to show
    u8 unk3E; // Medapart slot 0-3
    u8 unk3F; // Medals list: tab (6 Medals per tab)
    u8 unk40; // Medals list: row
    u8 unk41; // count of owned, unequipped Medals (count_unequipped_medals)
    u8 unk42; // Medal pages: 0 Ability, 1 Medaforce, 2 Rotation, 3 Skill (L/R, runtime-checked)
    u8 unk43; // Medal pages: help opened from 0 Ability, 1 Medaforce
    u8 unk44; // Medals help: page cursor
    u8 unk45; // Medals help: page count
    u8 unk46;
    u8 filler47;
    u16 unk48; // Medal record unk20/unk28 index 0-7 (sub_08008A5C)
    u8 unk4A; // Medals: choice from sub_080091E0 (0 A, 2 B)
    u8 unk4B; // Medals screen: song 7 started (when opened with unk3C == 4)
    u8 filler4C[0x4];
    u8 unk50; // Medabots screen mode: 0 plain (from the Medawatch), 1-3 team select (guess: battle type; 3 needs all three picks)
    u8 unk51; // Medabots screen: cursor slot (0-8)
    u8 unk52; // Medabots screen: reorder pick, slot | 0x80 while holding
    u8 unk53;
    u8 filler54[0x2];
    u8 unk56; // game state 3: 0 = entered from the field (fades from the backup palette), 1 = from a submenu
    u8 filler57[0x3];
    u8 unk5A; // Medabot detail: row cursor, 0 Medal, 1-4 head / right arm / left arm / legs (runtime-checked)
    u8 filler5B;
    u16 unk5C; // timer
    u8 unk5E; // Medabot detail: which Medabot is shown, L/R toggle (runtime-checked)
    u8 filler5F[0x25];
    u8 unk84; // field menu: animation frame counter
    u8 unk85;
    u16 unk86; // link exchange frame counter
    u8 unk88; // field menu: row animation counter
    u8 unk89; // Robattle: 1 skips the bot setup in battle_init_phase
    u8 filler8A[0x4];
    u8 unk8E; // field menu cursor: 0 Medawatch, 1 Item, 2 Vehicle, 3 Save (runtime-checked)
    u8 unk8F; // Medawatch menu cursor (0..2)
    u8 filler90[0x6];
    u8 unk96;
    u8 unk97; // shown Medabot: Medal, then unk98-9B its four Medaparts
    u8 unk98;
    u8 unk99;
    u8 unk9A;
    u8 unk9B;
    u8 unk9C; // game state 6: 1 picks song 14 and counts gUnk_03002B84[1] (guess: battle won)
    u8 filler9D;
    u8 unk9E[0x50]; // digit buffer (divide_by_10000)
    u8 unkEE; // start of a 16-byte part data record (load_part_data): ability (gUnk_083B656C name)
    u8 unkEF; // skill id; >= 100: leg type (gUnk_083BE97C[unkEF - 100])
    u8 unkF0; // skill type (gUnk_083B6EC8 name)
    u8 unkF1; // gender: 0 male, 1 female (matched against gUnk_030017A0[].unk1)
    u8 unkF2; // stats: head Armor, Success, Power, (F5 power icon flag), Uses; legs Armor, Propulsion,
    u8 unkF3; // Evasion, Defense, Proximity, Remoteness (runtime-checked on the detail page)
    u8 unkF4;
    u8 unkF5;
    u8 unkF6;
    u8 unkF7;
    u8 fillerF8[0x16];
    u8 unk10E[0x10]; // 16-byte record from gUnk_083B6158 (per Medal graphic index)
    u8 filler11E[0x10];
    u8 unk12E; // set: copy gOamBuffer to OAM at the next vblank
    u8 filler12F[2];
    u8 unk131; // set: vblank_body skips the OAM 88-127 upload in mode 2
    u8 unk132;
    u8 unk133; // after-battle Medal level-up: Medal slot (find_medal_slot_by_id - 1)
    u8 unk134;
    u8 unk135;
    u8 unk136;
    u8 unk137;
    u8 filler138;
    u8 unk139; // game state 3 setup step (medabots_screen_load_gfx); Robattle setup step
    u8 unk13A;
};


struct Unk_03002C30
{
    u16 unk0;
    s16 unk2;
    s16 unk4;
    u16 unk6; // animation frame
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u32 unkC_0:8; // x, 24.8 fixed point: fraction
    s32 unkC_8:24; // integer part
    u32 unk10_0:8; // y, 24.8 fixed point
    s32 unk10_8:24;
    u8 filler14[0x4];
    u16 unk18;
    u8 filler1A[0x2];
    u8 unk1C;
    u8 filler1D[0x3];
    u8 unk20; // animation state (0-3)
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    u8 unk2B; // animation set
    u8 unk2C;
    u8 unk2D;
    u8 unk2E; // on screen
    u8 filler2F[0x1];
    u16 unk30;
    u16 unk32;
    u8 filler34[0xC];
};

struct Unk_030055A0
{
    u16 unk0;
    u16 unk2;
};

struct Unk_03005170
{
    u8 unk0;
    u8 filler1;
    u8 unk2; // per-player bits (main loop)
    u8 filler3;
    u8 unk4;
    u8 filler5;
    u8 unk6;
};

// Serial (multiplayer link) state at 0x03005010.
struct Unk_03005010
{
    u32 unk0;          // per-player "packet received" bits (serial_link_init_and_status)
    u16 unk4;          // send packet (serial_prepare_send_packet)
    s16 unk6;
    u16 unk8[4][2];    // received packets, one per player
    u8 filler18;
    s8 unk19[4];       // per-player timeouts
    u8 unk1D;
    u8 unk1E;
};

// Decompressed tilemap (write_tilemap_to_vram_08000E94, load_tilemap_rows_to_vram).
struct Tilemap
{
    u32 width;
    u32 height;
    u32 unk8;
    u32 unkC;
    u16 data[0];
};

struct OamData
{
    u16 attr0;
    u16 attr1;
    u16 attr2;
    u16 affineParam;
};

// Pointed to by gUnk_03002414; holds its own copy of OAM slots and affine parameters.
struct Unk_03002414
{
    u8 filler0[0xB84];
    struct OamData unkB84[129];
    u16 unkF8C[0x84];   // affine parameters (copy_oam_affine_params)
    u8 unk1094;
    u8 unk1095;
};

// Opponent Medabot in an encounter setup (gUnk_03001800.unk4).
struct EncounterBot
{
    u8 parts[4]; // head, right arm, left arm, legs part ids
    u8 unk4; // Medal (gUnk_083B6158 record; init_enemy_bot_medal)
    u8 unk5; // Medal level
    u8 unk6[4]; // two 4-bit Medal record unk18 entries per byte
    u8 unkA; // Medal record unk9
    u8 fillerB;
};

struct Unk_03001800
{
    u8 unk0; // encounter: opponent message index (gUnk_083C2BBC)
    u8 unk1;
    u8 unk2; // opponent Medabot count
    u8 unk3; // nonzero: fixed opponent parts (else each part is re-rolled by random_pick_weighted4)
    struct EncounterBot unk4[3];
    u8 filler28[0x10];
    u8 unk38; // battlefield
    u8 unk39[8]; // copied from gUnk_083C3B04[unk38] (sub_080121A8)
    u8 unk41[3]; // team select picks: 0x10 | Medabots screen slot, 0 = empty (runtime-checked)
    u8 unk44; // Robattle: bit (1 << team Medabot) set by sub_08013AE4
    u8 unk45[6][2]; // Robattle action queue: record + 1 (0 = free), priority = legs Propulsion
                    // (battle_queue_add, sorted by battle_queue_sort; sub_08014314 tests [0][0])
    u8 unk51; // Robattle: Medaforce gauge points left to add / remove one per frame (medaforce_gauge_fill_step / _drain_step)
    u8 unk52;
    u8 unk53;
    u8 unk54;
    u8 unk55; // Robattle: result flags (2, 4, 8, 0x10 pick sub-states 0x60-0x78 in sub_0801427C)
    u8 unk56; // Robattle: frame counter, mod 32 (robattle_time_tick)
    u8 unk57; // Robattle: TIME left, 40/30/20 by gUnk_03001788 (robattle_time_init), -1 every 32 frames (robattle_time_tick)
    u8 unk58; // Robattle: nonzero blocks Medaforce (check_medaforce_availability)
    u8 unk59; // Robattle: effect amount left to apply (sub_08018D0C / sub_08018DF4)
    u8 unk5A; // Robattle: team Medabot count (3 in battle_start.ss0)
    u8 unk5B;
    u8 filler5C[0x8];
    u8 unk64[4]; // filled by get_bot_part_effective_values (sub_08013B8C); AI part order from gUnk_083AD2F0 (battle_ai_roll_part_order)
    u8 filler68[0x18];
    u8 unk80; // index of a 256-byte record in gUnk_03000590 (sub_0800B498 copies Medal rotation data there)
    u8 unk81; // Robattle: selected command ring slot 0-5 (name gUnk_083C466C[unk81], runtime-checked)
    u8 unk82;
    u8 unk83; // Robattle: command ring turning, 1 right / 2 left (command_ring_input); nonzero blocks robattle_command_input
    u8 unk84;
    u8 unk85;
    u8 unk86;
    u8 unk87; // Robattle: gUnk_03000590 record of the acting Medabot
    u8 unk88;
    u8 unk89; // Robattle: side of the acting Medabot (unk87 / 3: 0 team, 1 opponents)
    u8 unk8A; // Robattle: the other side (unk89 ^ 1)
    u8 unk8B;
    u8 unk8C[3];
    u8 unk8F[3][4]; // per team member: gUnk_030017A0 bytes 3-6
    u8 filler9B;
    u8 unk9C[5]; // cleared by sub_0801AEB4
    u8 unkA1[5]; // cleared by sub_0801AED4
    u8 fillerA6[0xC2];
    u8 unk168; // won Medapart: kind (0 head, 1 right arm, 2 left arm, 3 legs)
    u8 unk169; // won Medapart: id
    u8 unk16A; // won Medapart: 1 = not owned before
    u8 unk16B; // Robattle: TIME ticks elapsed (robattle_time_tick)
    u16 unk16C; // battle score (calculate_battle_score_summary), then experience points
    // After-battle result per team member (u8 array: a struct would be 4-byte aligned):
    // [0] Medal id + 1, 0 = none (name from gUnk_083B6410), [1] nonzero: Medal level-up screen,
    // [2]-[5] copied to gUnk_03000440.unk134-137, [6] nonzero: [7] = Medaforce id (gUnk_083B7338)
    u8 unk16E[3][8];
    u8 unk186; // after-battle screen: team member being shown (0-2, 3 = done)
    u8 unk187; // gUnk_03000590 record index (battle_loss_take_part)
    u8 filler188[0x1E];
    u16 unk1A6;
    u16 unk1A8;
    u16 unk1AA;
    u16 unk1AC;
    u8 filler1AE;
    u8 unk1AF;
    u8 unk1B0;
};

struct Unk_03000BE0
{
    u8 unk0; // flags (0x40 tested by sub_080092D4)
    u8 unk1; // Medal graphic index (0x80-byte tiles at 0x084C21BC)
    u16 unk2; // shown as "NEXT Lv" on the Medals list (render_medal_level_display; blank at level 100)
    u8 unk4; // Attribute (gUnk_083B656C name, Ability page); Medals help: gUnk_083B69C8 message index
    u8 unk5; // level (Medals help: Medaforce slots open at 10 / 30 / 60)
    u8 unk6; // Aim skill type (gUnk_083B6EC8 name, Ability page); Medals help: gUnk_083B70AC message index
    u8 unk7; // Compatibility icon (tile 0xD340 + unk7 * 4, Ability page)
    u8 unk8; // Medal sprite variant, 0-4 (gUnk_083AC494[unk1][unk8])
    u8 unk9; // number of unk18 entries in use (sub_0800AB0C draws the rest greyed out)
    u8 unkA[0xE]; // name text
    u8 unk18[8]; // indexed by Medals screen unk46 (gUnk_083B825C message ids; guess: rotation entries)
    u8 unk20[8]; // 0-100 (guess: skill levels, drawn by render_medal_skill_stats)
    u8 unk28[8]; // per skill: filled bar tiles, 0-8 (draw_medal_skill_bars)
    u8 filler30[0xF];
    u8 unk3F; // Robattle: current unk18 entry (battle_bot_advance_rotation advances it, wraps at 8 to unk9)

};

// Battle Medapart record (0x18 bytes, 4 per gUnk_03000590 record from +0x48; battle_bots_load_parts).
struct BattlePart
{
    u8 data[0xD]; // part data record (load_part_data); data[0xA] summed as armor (accumulate_team_armor_stats)
    u8 fillerD;
    u8 unkE; // copied to the record's unkE0 / unkE1 when this part is chosen (battle_bot_select_part)
    u8 unkF;
    u8 unk10; // head: copy of data[8]
    u8 unk11; // current armor, starts as data[4] = max armor (Status screen, runtime-checked); 0 = broken
              // (legs: data[4..9] copied to unk11..unk16)
    u8 unk12; // legs: data[5] (Propulsion; sub_0801928C)
    u8 filler13[4];
    u8 unk17; // part id
};

// 256-byte records at gUnk_03000590 (6 of them, cleared together); each starts with a Medal record copy.
struct Unk_03000590
{
    struct Unk_03000BE0 medal;
    // 0x40-0x47: copy of the team slot (struct Unk_030017A0, copy_team_slots_to_battle_bots);
    // opponents: unk40 = 3, unk41 = head part byte 3, unk42 = Medal graphic (init_opponent_bot_slots)
    u8 unk40; // nonzero: record in use
    u8 unk41;
    u8 unk42;
    u8 unk43; // part ids: head, right arm, left arm, legs (battle_bots_load_parts)
    u8 unk44;
    u8 unk45;
    u8 unk46;
    u8 unk47;
    struct BattlePart parts[4]; // head, right arm, left arm, legs
    u8 unkA8[6]; // chosen Medaforce: gUnk_083B7CD4 record (battle_bot_select_medaforce)
    u8 fillerAE[0x2];
    u8 unkB0[8]; // per skill type: times used this battle (sub_08018900)
    u8 unkB8; // own record index (battle_bots_load_parts)
    u8 unkB9;
    u8 unkBA; // nonzero: Medabot present (records 0-2 player team, 3-5 opponents)
    u8 unkBB;
    u8 fillerBC;
    u8 unkBD; // flags (bit 2 toggled by the Robattle handlers sub_080143A0 / sub_08014404)
    u8 fillerBE;
    u8 unkBF;
    u8 fillerC0;
    u8 unkC1; // Medaforce gauge, 0-80 (0x50: Medaforce ready, check_medaforce_availability; drawn as "MF nn/80", runtime-checked)
    u8 fillerC2[0x2];
    // Two timed effects, ticked every 32 frames by sub_08018CBC (sub_08018D0C / sub_08018DF4):
    // type, part, frames left (-4 per tick; at 0 the effect ends and unkCE bit 0 / 1 is set), amount.
    u8 unkC4; // effect A type (0x1F: restores armor to damaged parts, sub_08018D0C)
    u8 unkC5;
    u8 unkC6;
    u8 unkC7;
    u8 unkC8; // number shown by the Robattle handler 0x70 (sub_080147FC)
    u8 unkC9; // effect B type (0x13/0x14: armor changes each tick, sub_08018DF4; 0x2C checked by sub_08014404 / process_bot_battle_turn, 0x2B by sub_080154E0)
    u8 unkCA; // effect B part (compared by sub_080154E0; sub_08018F6C starts there)
    u8 unkCB;
    u8 unkCC;
    u8 unkCD; // number shown by the Robattle handler 0x78 (sub_08014920)
    u8 unkCE; // flags: bit 0 / bit 1 = sprites 0x46 / 0x47 + 3 * record shown (sub_080145BC .. sub_08014754),
              // bit 2 / bit 3 = numbers shown by sub_080147FC / sub_08014920
    u8 fillerCF[0x8];
    u8 unkD7; // movement: sub-pixel accumulator, + (0x20 - unkBB) per frame, 1/16 px (battle_bot_move)
    u8 fillerD8[0x2];
    u8 unkDA; // movement: whole pixels moved this frame
    u8 fillerDB[0x2];
    u8 unkDD; // link Robattle: part choice exchanged over the serial link (sub_08014B34, sub_08014C30)
    u8 fillerDE[0x2];
    u8 unkE0;
    u8 unkE1;
    u8 fillerE2[0x1E];
};

struct Unk_030017A0
{
    u8 unk0; // slot in use (> 1: has a Medal)
    u8 unk1; // guess: Medabot gender (compared with the Medapart gender unkF1 in count_compatible_medaparts)
    u8 unk2; // Medal id
    u8 unk3; // Medaparts: head, right arm, left arm, legs (validate_medapart_stats)
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
};

struct Unk_030057A0
{
    u8 filler0[0x14];
    u8 unk14;
    u8 filler15[0x19];
    u16 unk2E; // text bank (map script opcode 0x8x argument - 2)
    u16 unk30; // text id
};

// Per-area record list (gUnk_0840FAF4), ends at mask 0. A record applies when the player steps
// from a neighbouring tile onto (x, y) in a direction whose bit is set in mask.
struct MapExit
{
    u8 x;
    u8 y;
    u8 mask; // direction 0: 2, 1: 1, 2: 8, 3: 4
    u8 value; // returned by check_room_exit_at_position (0 = none)
};

// Map object record (64 at gUnk_030057E0.unk5DC).
struct MapObject
{
    u8 x;
    u8 y;
    u16 unk2; // bits 12-15: type (8 = event), bits 0-11: event id
    u8 unk4_0:5; // sprite slot (gUnk_03002C30 index - 49)
    u8 unk4_5:1;
    u8 unk4_6:1; // has a sprite (slot + 49, shadow slot + 91)
    u8 unk4_7:1; // animates at random
    u8 unk5; // animation state
    u8 filler6[0x2];
};

struct Unk_030064A0
{
    u8 filler0[0x2];
    u8 unk2[8];
    u8 unkA[8];
    u8 unk12[8][8];
    u8 unk52;
    u8 unk53;
    u8 unk54[8];
    u8 unk5C[8];
};

struct Unk_030057E0
{
    u8 filler0[0x5DC];
    struct MapObject unk5DC[64];
    u8 filler7DC[0x20];
    u8 unk7FC;
    u8 unk7FD;
    u8 unk7FE; // area id
    u8 unk7FF;
    u16 unk800; // map width * 2 (tiles are bytes, unk810 rows are unk800 / 2 long)
    u16 unk802; // map height * 2
    u8 filler804[0xC];
    u8 unk810[0x400]; // tile map
    u8 unkC10[0x8]; // tile value -> result of check_tile_and_trigger_battle_action
    u8 unkC18[0x8]; // saved copy of unkC10
    u8 unkC20[0x8];
    u8 unkC28;
    u8 fillerC29[0x1];
    u8 unkC2A; // battle id (set by the debug menu "Battle" entry before game state 6; guess)
    u8 unkC2B;
    u8 unkC2C; // toggled by the debug menu "Rnd.tk" entry (guess: random encounters on)
    u8 unkC2D;
    u8 unkC2E;
    u8 unkC2F;
    u8 fillerC30[0x2];
    u8 unkC32;
    u8 unkC33; // Medawatch menu enabled (B opens the field menu only if set)
    u8 unkC34;
    u8 unkC35;
    u8 unkC36;
    u8 unkC37; // random seed
    u8 unkC38[0x10];
    u16 unkC48;
    u16 unkC4A;
    u8 fillerC4C[0x3];
    u8 unkC4F;
    u8 fillerC50[0x2];
    u16 unkC52;
    u16 unkC54;
    u8 unkC56; // player tile x
    u8 unkC57; // player tile y
    u8 unkC58;
    u8 unkC59;
    u8 fillerC5A[0x1];
    u8 unkC5B;
    u8 unkC5C;
    u8 unkC5D;
    u8 unkC5E;
    u8 unkC5F;
    u8 unkC60;
    u8 fillerC61[0x6];
    u8 unkC67;
    u8 fillerC68[0x1];
    u8 unkC69;
    u8 fillerC6A[0x4];
    u16 unkC6E;
    u16 unkC70;
    u8 unkC72;
    u8 unkC73;
    u8 unkC74;
    u8 unkC75;
    u8 unkC76;
    u8 fillerC77[0xC];
    u8 unkC83;
    u8 unkC84;
    u8 fillerC85[0x3];
    u8 unkC88;
    u8 unkC89;
    u16 unkC8A; // map script read offset
    u16 unkC8C;
    u16 unkC8E; // current map script id
    u16 unkC90;
    u8 unkC92; // current map script command (gMapScriptCommands index)
    u8 unkC93;
    u8 unkC94[0x10]; // map script command arguments (read_map_script_bytes)
    u8 unkCA4[0x10];
    u8 unkCB4; // index of the map object running the script (unk5DC)
    u8 unkCB5;
    u8 fillerCB6[0x4];
    u8 unkCBA;
    u8 fillerCBB[0x1];
    s8 unkCBC;
    s8 unkCBD;
};

struct Unk_03005310
{
    u8 filler0[0x1];
    u8 unk1;
    u8 filler2[0x2];
    u32 unk4; // frame counter
    u8 filler8[0x16];
    u16 unk1E;
    u8 filler20[0x6];
    u16 unk26;
    u8 filler28[0x10];
    u8 unk38;
    u8 unk39;
};

struct Unk_03006D38
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 filler4[0x2];
    u8 unk6;
};

// BG scroll offsets: gBg0Scroll..gBg3Scroll, added to gUnk_03002C2C and written to BGxHOFS/VOFS by vblank_body.
struct Vec16
{
    s16 x;
    s16 y;
};

struct Unk_03005350
{
    u8 filler0[0x40];
    s32 unk40; // position x, y, z
    s32 unk44;
    s32 unk48;
    u8 filler4C[0x68];
    s32 unkB4;
    s32 unkB8;
    u8 fillerBC[0x118];
    u32 unk1D4;
};

// Table pointed to by the sound work area at 0x728: note -> sample/frequency entry.
struct SoundNoteTable
{
    u16 count;
    u16 base;
    u32 unk4;
    u8 *entries[1]; // count entries
};

// Per-track configuration (gSoundTrackConfigs, one per SoundTrack).
struct SoundTrackConfig
{
    u32 unk0; // -> SoundTrack.unkC
    void (*unk4)(struct SoundTrack *track); // -> SoundTrack.unk10
    u8 unk8; // -> SoundTrack.unk64
    u8 unk9; // ring buffer index (work+0x5EC), 0xFF = none
    u8 fillerA[2];
};

// Song / sound effect header (tables at gUnk_03007014->unk688 / unk68C).
struct SoundSongHeader
{
    u16 trackMask; // bit 11 - i set: track i is used (0x800 = track 0)
    u8 priority; // copied to SoundTrack.unk6D
    u8 unk3;
    u8 *tracks[1]; // one sequence pointer per set bit, in track order
};

// Sound driver work area (0x734 bytes, cleared by sound_engine_init).
struct Unk_03007014
{
    struct SoundTrack tracks[13];
    struct SoundTrack *unk5E4;
    u32 unk5E8;
    u8 unk5EC[3][0x34]; // SoundTrack.unk8 ring buffers (0x30 bytes + write index)
    struct SoundSongHeader **unk688; // songs
    struct SoundSongHeader **unk68C; // sound effects
    struct SoundMixChannel unk690;
    struct SoundMixChannel unk6D8;
    u32 unk720;
    u32 unk724;
    struct SoundNoteTable *unk728;
    u8 unk72C; // flags
    u8 unk72D;
    u8 unk72E;
    u8 unk72F;
    u16 unk730;
    u8 filler732[0x2];
};

// Area warp record (gUnk_08413114, one 0xFF-terminated list per area): stepping onto (x, y)
// moves the player to (destX, destY) of area.
struct AreaWarp
{
    u8 x;
    u8 y;
    u8 area;
    u8 dir; // low 3 bits: facing after the warp
    u8 unk4;
    u8 unk5;
    u8 destX;
    u8 destY;
};

// Per-area graphics record (gUnk_083F92F4, indexed by area id).
struct AreaGfx
{
    const void *unk0; // LZ77 data, decompressed to gUnk_03006D14
    u32 unk4;
    u32 unk8;
};

struct Unk_08047414
{
    u8 *unk0;
    u32 unk4;
    u32 unk8;
};

#endif // GUARD_STRUCTS_H
