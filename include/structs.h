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
    u16 unk8; // base y of a sprite hop (sub_080508CC)
    u8 unkA; // sprite slot (gUnk_03002C30 index)
    u8 unkB;
    u8 unkC;
    u8 fillerD[0x3];
};

// 0x03001800 while game mode 3 (boot logos / story intro, code_0806B160) runs; the same RAM as gUnk_03001800.
struct Unk_03001800_s
{
    u16 nextMode; // gGameMode / gGameState / gGameSubState to go to when the scene ends
    u16 nextState;
    u16 nextSubState;
    u16 unk6;
    s32 timer; // frame counter of the current step
    union { // 4 bytes: agbcc pads unions to a word
        u16 h; // story intro: page (graphics gUnk_08487328 / text gUnk_08486EEC)
        u8 b;  // boot logos: nonzero once START may skip them (boot_logos_check_skip)
        s8 s[4]; // title: s[2] is a two-digit number shown with sprites 11 / 12 (get_battle_state_value_div10)
    } unkC;
    union {
        s32 w; // countdown: play_song(3) when it reaches 0
        struct {
            u8 state; // battle-end state machine: index into gUnk_08486138
            u8 step; // step counter of the current state
            u8 pos; // script position (sub_08072138)
            u8 pad;
        } end;
    } unk10;
    u8 filler14[0x1A];
    u8 unk2E; // cells drawn in the 40-cell grid (check_battle_timer_expired)
    u8 unk2F;
    u16 unk30[0x50]; // decompression buffer (load_battle_ui_assets); tile source of that grid
    u8 unkD0; // text cursor (process_text_tile_and_dma_transfer)
    u8 unkD1;
    u16 unkD2[13]; // text tile row, DMA'd to 0x0600FC44
    u8 unkEC; // column / row counters of battle_draw_tilemap_row_dma
    u8 unkED;
    s8 unkEE; // blend counter (scene_fade_out_and_restore_state)
    u8 unkEF;
    u16 unkF0;
    u16 unkF2;
    u16 unkF4;
    u16 unkF6;
};

// 0x03001800 while game mode 3 state 5 (gUnk_08485E5C, the bomb minigame) is active; the same RAM as
// gUnk_03001800.
struct Unk_03001800_bomb
{
    u8 filler0[8];
    s32 timer; // frame counter of the current step (sub_0806BBDC)
    s8 unkC; // bombs per round (50), the number of entries in unkF
    s8 unkD;
    s8 unkE; // bombs left this round, shown as BOMB (runtime: 50 -> 48, back to 50 in round 2)
    s8 unkF[0x32]; // 0..2 each (guess: lane per bomb), a random walk (sub_0806B9D0)
    s8 unk41; // -8..8, pushed by R / L, eases back to 0 (sub_0806BE58)
    u8 filler42[2];
    s32 unk44; // timer value of the next bomb drop (bomb_game_drop_bombs); unkC + unkD once the intro ends
};

// 0x03001800 during game mode 3 state 6, the "Medabots Weekly" TV show (medabots_weekly_update); the same RAM
// as gUnk_03001800.
struct Unk_03001800_bganim
{
    u16 unk0; // next mode? (cf. Unk_03001800_s.nextMode)
    u16 unk2; // next state?
    u8 filler4[8];
    u8 unkC; // nonzero: scroll BG3 every other frame (sub_0807068C)
    u8 unkD; // nonzero: animate BG tiles (sub_080706AC)
    u8 unkE; // tile animation frame 0..5 (every 4 frames)
    u8 unkF; // tile animation frame 0..5 (every 16 frames)
    u8 filler10[4];
};

// One step of a sprite animation (gUnk_08485D5C).
struct SpriteAnimFrame
{
    u16 frame; // copied to the sprite's unk6
    s16 duration; // frames
    u8 next; // index of the next step
    u8 filler5[3];
};

// 0x03002B70: money, then a 10-byte string (init_save_prompt_text writes a default one).
struct Unk_03002B70
{
    u32 money;
    u8 unk4[16]; // player name, 0xFE-terminated (validate_save_data rejects an empty one)
    u16 unk14[2]; // gUnk_03002B84: [0] counted on every Robattle, [1] only on some (guess: fought / won); both <= 9999, [0] >= [1]
    u32 unk18; // at most 0x014996FF (validate_save_data; guess: play time in frames, below 100 hours)
};

// 8-byte records at gUnk_03000440.unk64 (init_game_state_entry).
struct Unk_03000440_64
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u16 unk4;
    u16 unk6;
};

// Graphics list entry (gUnk_083CE480 lists, end at size 0): size in 32-byte tiles, gUnk_083B2584 index.
struct GfxListEntry
{
    u16 size;
    u16 index;
};

struct Unk_03000440
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 filler3;
    u8 unk4; // message handler state (run_message)
    u8 filler5[0x3];
    const u8 *unk8; // current message (run_message)
    u16 unkC;
    u8 unkE;
    u8 unkF;
    s8 unk10;
    s8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 filler1D[0x7];
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    u8 unk28;
    u8 unk29; // choice menu state (poll_choice_menu)
    u8 unk2A;
    u8 unk2B; // sprite slot (advance_sprite_scroll_animation)
    u8 unk2C; // tilemap x (copy_transition_tiles_to_bg2)
    u8 unk2D; // tilemap y
    u8 filler2E[0x2];
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
    u8 filler5F[0x5];
    struct Unk_03000440_64 unk64[4]; // set up by init_game_state_entry / sub_0801BF78
    u8 unk84; // field menu: animation frame counter
    u8 unk85;
    u16 unk86; // link exchange frame counter; also the current wave x offset of sub_08043960
    u8 unk88; // field menu: row animation counter
    u8 unk89; // Robattle: 1 skips the bot setup in battle_init_phase
    u16 unk8A; // rng seed (rng_next_080424B8)
    u8 unk8C; // last rng_next_080424B8 value
    u8 unk8D; // rng table index when unk89 is set
    u8 unk8E; // field menu cursor: 0 Medawatch, 1 Item, 2 Vehicle, 3 Save (runtime-checked)
    u8 unk8F; // Medawatch menu cursor (0..2)
    u8 unk90; // blend effect mode 1-6 (set_blend_effect_mode): odd fades the blend in, even out
    u8 filler91;
    u16 unk92; // blend effect speed, added to unk94 every frame
    u16 unk94; // blend effect progress (done at 0x100)
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
    u8 unk12F; // sprite slot (sub_08028E84)
    u8 unk130; // Robattle: set to 1 around the action script commands sub_08034048 .. sub_08034240
    u8 unk131; // set: vblank_body skips the OAM 88-127 upload in mode 2
    u8 unk132;
    u8 unk133; // after-battle Medal level-up: Medal slot (find_medal_slot_by_id - 1)
    u8 unk134;
    u8 unk135;
    u8 unk136;
    u8 unk137;
    u8 unk138; // nonzero: sub_0803DC58 jumps to sub-state 0x30
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
    u32 unk14_0:8; // z / depth, 24.8 fixed point
    s32 unk14_8:24;
    u16 unk18;
    u16 unk1A;
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
    u8 unk2F;
    u16 unk30;
    u16 unk32;
    u16 unk34; // frame target unk1A counts up to (sub_08071C40)
    u8 filler36[0x4];
    u16 unk3A; // previous frame's unk1A (update_battle_bot_entry_animations)
    u8 filler3C[0x4];
};

struct Unk_030055A0
{
    u16 unk0;
    u16 unk2;
};

// One link packet as sent / checked (12 bytes): 4 halfwords sum to 0xFFFF when intact.
struct SioPacket
{
    u8 frame;      // sender's frame counter
    u8 errFlags;   // players that were connected but not received
    u16 checksum;  // ~sum of the first 4 halfwords
    u16 data[2];   // payload (gSioPlayers.send / .recv)
    u16 pad[2];
};

// Multiplayer serial link work area at 0x03005170 (serial_link_*; the IWRAM interrupt handler
// serial_multiplayer_transfer_handler and link_buffer_swap_arm in crt0.s use it too).
struct SioLink
{
    u8 isParent;     // 8 once this unit drives the transfers with timer 3
    u8 running;      // 0 = waiting for the link, 1 = running
    u8 connected;    // per-player bits (main loop)
    u8 recvOk;       // per-player bits, packets received intact this frame
    u8 sendPending;  // serial_prepare_send_packet filled nextSend
    u8 recvDone;     // all 4 words received (cleared by link_buffer_swap_arm)
    u8 started;      // set by sub_08002190
    u8 error;        // SIOCNT error bit
    u8 filler8[3];
    u8 frame;        // frame counter, sent in each packet
    u8 fillerC[8];
    s32 sendIdx;     // halfword being sent (6 = idle)
    s32 recvIdx;     // halfword being received
    struct SioPacket *nextSend;
    struct SioPacket *curSend;
    u16 (*curRecv)[6];  // [player][halfword]
    u16 (*lastRecv)[6];
    struct SioPacket *recvCheck;
    struct SioPacket sendBuf[2];
    struct SioPacket recvBuf[3][4];
};

// SIOCNT (multiplayer mode) + SIOMLT_SEND as one 32-bit word.
struct SioMultiCnt
{
    u32 baudRate:2;
    u32 si:1;
    u32 sd:1;
    u32 id:2;
    u32 error:1;
    u32 enable:1;
    u32 unk8:4;
    u32 mode:2;
    u32 irq:1;
    u32 unk15:1;
    u32 data:16;
};

// The same two registers as u16 bitfields (serial_link_init_and_status reads them this way).
struct SioCnt
{
    u16 baudRate:2;
    u16 si:1;
    u16 sd:1;
    u16 id:2;
    u16 error:1;
    u16 enable:1;
    u16 unk8:4;
    u16 mode:2;
    u16 irq:1;
    u16 unk15:1;
    u16 data;
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

// Struct view of the gUnk_083B4AE0 tilemap pointer table: the Robattle screen wipes read entry 0x69 as a
// field (base + 0x1A4, reloaded after each call: sub_0801DF60, sub_0801FADC).
struct Unk_083B4AE0
{
    const void *unk0[0x69];
    const void *unk1A4; // blank tilemap row
};

// Pointed to by gUnk_03002414; holds its own copy of OAM slots and affine parameters.
struct Unk_03002414
{
    u8 filler0[0xB84];
    struct OamData unkB84[129];
    u16 unkF8C[0x84];   // affine parameters (copy_oam_affine_params)
    u8 unk1094;
    u8 unk1095;
    u8 unk1096;
    u8 unk1097;
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

// BG scroll offsets: gBg0Scroll..gBg3Scroll, added to gUnk_03002C2C and written to BGxHOFS/VOFS by vblank_body.
struct Vec16
{
    s16 x;
    s16 y;
};

// Battle Medapart record (0x18 bytes, 4 per gUnk_03000590 record from +0x48; battle_bots_load_parts).
// Screen position returned by value (a 4-byte struct, so in memory via a hidden pointer: calc_polar_to_screen_coords).
struct Coords16
{
    s16 x;
    s16 y;
};

// 4-byte sprite positions (gUnk_083AF94C, sub_0803B0C0).
struct Unk_083AF94C
{
    u16 x;
    u8 y;
    u8 filler3;
};

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
    u8 unk13; // legs: data[6..9] (unk12..unk16 restored by sub_080351E8, halved by sub_08035194 when broken)
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17; // part id
};

// 8-byte entry of the sort buffer at 0x02023000, sorted by key then key2, largest first (sub_0804242C).
struct SortEntry
{
    u16 key;
    u16 key2;
    u16 value;
    u16 unk6;
};
// The game indexes it through the constant address (a symbol doesn't match find_most_damaged_part).
#define SORT_BUFFER ((struct SortEntry *)0x02023000)

// Per-side record at gUnk_03001800.unk28 (0 team, 1 opponents).
struct Unk_03001800_28
{
    u8 unk0;
    u8 unk1; // compared between the sides when TIME runs out with a tie (robattle_judge_time_up)
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5; // damage amount (sub_0801C660)
    u8 unk6;
    u8 unk7;
};

struct Unk_03001800
{
    u8 unk0; // encounter: opponent message index (gUnk_083C2BBC)
    u8 unk1;
    u8 unk2; // opponent Medabot count
    u8 unk3; // nonzero: fixed opponent parts (else each part is re-rolled by random_pick_weighted4)
    struct EncounterBot unk4[3];
    struct Unk_03001800_28 unk28[2]; // per side (0 team, 1 opponents)
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
    u8 unk5C; // Robattle AI: record choosing its action (battle_process_all_bot_actions)
    u8 unk5D; // Robattle AI: part being considered (0-2)
    u8 unk5E; // Robattle AI: target record + 1
    u8 unk5F; // Robattle AI: target part + 1
    u8 unk60; // first record of the target side (sub_08032FB8, sub_08026FF8)
    u8 unk61[3]; // Robattle AI: candidate targets (record + 1, 0 = none; select_battle_targets_and_actions)
    u8 unk64[4]; // filled by get_bot_part_effective_values (sub_08013B8C); AI part order from gUnk_083AD2F0 (battle_ai_roll_part_order)
    u8 filler68[0xC];
    u8 unk74[8]; // copied from gUnk_083C3B5C[unk38] (load_battle_script_entry_b); [3] nonzero: [4] << 8 | [5] -> REG_BLDALPHA
    u8 unk7C; // battlefield animation frame, 0-0x7F (advance_battle_animation_frame)
    u8 unk7D; // battlefield animation tick, 0-2
    u8 unk7E; // battlefield animation tile count / 8 (gUnk_083C40B8)
    u8 unk7F; // battlefield animation tile block (gUnk_083C40C3), 0xFF ends the loop
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
    u8 unkA6; // Medaforce effect id 0xE-0x11 (sub_0801C524)
    u8 unkA7; // Robattle: part index (0-3) of the acting Medabot that unk11C is written back to (sub_0801B3AC)
    u8 unkA8; // Robattle: skill id (data[1]) of the acting Medabot's chosen part (resolve_battle_action_phase)
    u8 fillerA9;
    u8 unkAA; // sub-state of the gUnk_083AD44C handlers (sub_0801C4FC) and gUnk_083AD50C handlers (battle_dispatch_phase_handler_0801D2F0)
    u8 unkAB; // 0-2, set with unkB5 = 1 by the gUnk_083AD50C handlers (sub_0801D2AC..)
    u8 unkAC[0x9]; // Robattle action script: operands of the current command (battle_script_load_operands)
    u8 unkB5; // action effect step script done: cleared by each step dispatcher (sub_0801C4FC, battle_dispatch_phase_handler_0801D2F0..),
              // set by the last step; the callers (sub_080339F4, sub_08033A10) then call battle_script_advance
    u8 fillerB6[0x1];
    u8 unkB7; // effect result flags (bit 0, bit 1 checked by sub_0801E3C0)
    u8 unkB8; // effect result flags (bit 1, bit 2 checked by sub_0801E3C0)
    u8 unkB9; // raised by gUnk_03001800.unkEC up to 0x78 on the own side, lowered on the other (sub_0802C588, written as &unkB8 + 1 to match)
    u8 unkBA;
    u8 unkBB;
    u16 unkBC; // Robattle action script: offset of the current command (battle_script_read_byte / battle_script_advance)
    u8 unkBE; // set with unkB7 / unkB8 by the script commands sub_08033F04 / sub_08033F64 (1, 5)
    u8 unkBF; // set with unkB8 = 4 by sub_080392D8 / determine_battle_target_mode (2-4)
    u8 fillerC0[0x8];
    u16 unkC8; // Robattle: effect amount (shown by sub_0801CA60, subtracted by apply_battle_damage_tick)
    u16 unkCA; // damage passed to battle_set_damage_vs_armor (sub_0801ECC0)
    u16 unkCC; // copy of unkC8 (sub_08036B84)
    u8 fillerCE[0x2];
    u8 unkD0; // last part (3..0) of the acting Medabot with armor left (sub_0801C660)
    u8 unkD1; // nonzero: battle_check_hit_and_set_timer goes to sub-state 0x1A
    u8 unkD2[4]; // per part: nonzero shows an effect sprite (sub_08026AF4)
    u16 unkD6[4]; // per part: amounts shown by sub_08026924
    u8 unkDE; // record + 1 of a teammate of unk88 with unkBD bit 3 set (sub_0801D5A8), 0 = none
    u8 unkDF; // that teammate's unkDF (0x1B-0x1D pick the graphics in sub_0801D6A4)
    u8 unkE0[3]; // per team record: record + 1 waiting for reset_battle_bot_state (sub_0801FE14)
    u8 fillerE3[0x5];
    s16 unkE8; // passed to battle_set_action_params with unkEC (sub_0801F9EC)
    s16 unkEA; // unkE8 / 4 (script command sub_08033D10)
    s16 unkEC; // amount for battle_calc_damage_split (battle_resolve_action_target); counted down by sub_0801EC3C
    u16 unkEE; // + Medal level + matching parts power + rng & 7 (accumulate_battle_speed_value)
    u8 fillerF0[0x2];
    s16 unkF2; // copy of unkE8 when the action phase starts (sub_08038D30, battle_check_damage_threshold)
    u8 fillerF4[0x2];
    u8 unkF6; // bit 0 checked by sub_08020078
    u8 fillerF7[0x1];
    u8 unkF8; // 0 when sub_0801B67C gets a team record (0-2), 3 for an opponent
    u8 unkF9; // skill shown by the action script command sub_08034074: chosen part's data[1], or Medaforce unkA8[0] + 0x50
    u8 fillerFA;
    u8 unkFB; // cleared by sub_08034074
    u8 unkFC;
    u8 unkFD;
    u8 unkFE;
    u8 unkFF; // bits 0 / 1 set by sub_080347F8 with unk114[0] / unk114[1] = 0x28
    u16 unk100; // battle sequence: offset of the current command in gUnk_083CDFE4[unkF9] (cleared by sub_08034074)
    s16 unk102[8]; // battle sequence: operands of the current command (load_battle_sequence_commands)
    u8 unk112; // set to 0x29 with unk113 (sub_080361A8)
    u8 unk113;
    u8 unk114[2]; // per side (0 team, 1 opponents): passed to init_scene_with_bg_and_palette (sub_08020B4C)
    u8 filler116[0x2];
    u8 unk118; // nonzero: sub_0801B3AC writes unk11C back into the acting Medabot's part
    u8 unk119; // part data[1] - 0x37 of the swapped part (sub_08026678)
    u8 unk11A; // id of the part swapped in (sub_08026678)
    u8 filler11B[0x1];
    struct BattlePart unk11C; // saved part (data and id), restored by sub_0801B3AC
    u8 filler134[0x8];
    struct Vec16 unk13C[6]; // per record: x, y - 4 of its battle sprite (copy_battle_entity_positions)
    u16 unk154; // effect sprite x, y when unkF8 bit 1 is set (sub_0801E474)
    u16 unk156;
    u16 unk158; // effect sprite x, y when unkF8 bit 1 is clear (sub_0801E474)
    u16 unk15A;
    u8 unk15C[3]; // per Medapart select slot (unk82 - 1): nonzero skips the part sprite (sub_0801B894)
    u8 unk15F; // result of battle_advance_dialogue_text (sub_0801FA68)
    u8 unk160; // result of battle_advance_action_text (sub_0801FA68)
    u8 unk161;
    u8 unk162;
    u8 unk163; // set by a gUnk_083AF000 step to run the next step in the same frame (battle_run_action_script)
    u8 unk164; // nonzero: Medal skill levels can grow (increment_medal_skill_level)
    u8 unk165; // set to 1 when a Medal skill levels up (sub_08031120 then goes to sub-state 0x60)
    u8 unk166; // skill type that levelled up
    u8 unk167; // its new level
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
    u8 unk188; // two rolls from gUnk_083AF200 (sub_08034AA0); unkEC = (unk188 + unk189) * 10
    u8 unk189;
    u8 unk18A[0x10]; // link exchange: received bytes (sub_0803E680)
    u8 unk19A[6]; // = gUnk_0300199A (sub_0803E8B8); indexed by unk1A2
    u8 unk1A0;
    u8 unk1A1;
    u8 unk1A2;
    u8 unk1A3;
    u8 unk1A4;
    u8 unk1A5;
    u16 unk1A6;
    u16 unk1A8;
    u16 unk1AA;
    u16 unk1AC;
    u8 unk1AE; // set to 1 when the screen wipe of sub_0801DF60 is done
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
    u8 unkB9; // raised by gUnk_03001800.unkEC up to 0x78 on the own side, lowered on the other (sub_0802C588, written as &unkB8 + 1 to match)
    u8 unkBA; // nonzero: Medabot present (records 0-2 player team, 3-5 opponents)
    u8 unkBB;
    u8 unkBC; // high nibble cleared by sub_0801B274
    u8 unkBD; // flags (bit 2 toggled by the Robattle handlers sub_080143A0 / sub_08014404)
    u8 fillerBE;
    u8 unkBF;
    u8 unkC0; // flags (bit 1 skips the Medaforce effect, sub_0801C524)
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
    u8 unkCF; // flags: bits 0/1/2/3 set by sub_08029354 (by gUnk_03001800.unk51)
    u8 unkD0;
    u8 unkD1; // raised by gUnk_03001800.unkEC up to 0xFF (sub_0802AC7C, written as &unkD0 + 1 to match)
    u8 unkD2;
    u8 unkD3; // added to gUnk_03001800.unkEC for parts with data[2] 0 / 1 (sub_08033D30)
    u8 unkD4; // added for data[2] 2 / 3 (sub_08033D30)
    u8 unkD5; // added to gUnk_03001800.unkEC for unk28[side].unk5 (sub_08021418)
    u8 unkD6; // flags (bit 1: +10 damage, sub_0801ECC0)
    u8 unkD7; // movement: sub-pixel accumulator, + (0x20 - unkBB) per frame, 1/16 px (battle_bot_move)
    u16 unkD8; // cleared, then raised by gUnk_03001800.unkEC up to 0xFF (sub_08022748)
    u8 unkDA; // movement: whole pixels moved this frame
    u8 fillerDB;
    u8 unkDC; // unkDC..unkE3 cleared by reset_battle_bot_state
    u8 unkDD; // link Robattle: part choice exchanged over the serial link (sub_08014B34, sub_08014C30)
    u8 unkDE; // copy of unkDD (sub_0801B274)
    u8 unkDF; // skill of the part unkDD (1-3), 0 otherwise (sub_0801B274)
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
    u8 unk0;
    u8 filler1[0xF];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13; // next free battle sprite slot (load_battle_sprite_tile)
    u8 unk14; // debug battle-field screen page (sub_08058214)
    u8 unk15; // bit 0x10: clear instead of load (load_or_clear_battle_sprites)
    s8 unk16[8]; // per-page row values (sub_0805889C)
    u16 unk1E;
    u16 unk20; // battle field id (init_battle_field_sprites)
    u8 filler22[0x2];
    u16 unk24;
    u16 unk26;
    u16 unk28;
    u16 unk2A;
    u16 unk2C;
    u16 unk2E; // text bank (map script opcode 0x8x argument - 2)
    u16 unk30; // text id
    u8 unk32;
    s8 unk33;
    s8 unk34;
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
    u8 unk0;
    u8 unk1;
    u8 unk2[8];
    u8 unkA[8];
    u8 unk12[8][8];
    u8 unk52;
    u8 unk53;
    u8 unk54[8];
    u8 unk5C[8];
    u8 unk64; // choice menu step (sub_08047FEC: 0 setup, 1 wait handler, 2 poll)
    // Vehicle menu (sub_08057044 .. sub_08057598) reuses the area after the choice menu.
    u8 unk65; // cursor: selected vehicle
    u8 unk66;
    u8 unk67; // frame counter (cursor wobble)
    u8 filler68[0x4];
    u8 unk6C; // cursor tile x
    u8 unk6D; // cursor tile y
    u8 unk6E;
    u8 unk6F; // slide step (0..16)
    u8 unk70; // text page
    u8 filler71;
    u16 unk72[30 * 20]; // saved BG tilemap
};

// One sprite of the snapshot at gUnk_030057E0.unk7DC (4 bytes)
struct ScriptSpriteSave
{
    u8 x; // tile
    u8 y;
    u8 id:5;
    u8 unk2_5:1;
    u8 unk2_6:1;
    u8 active:1;
    u8 anim; // (unk2B & 0xF) << 4 | facing
};

struct Unk_030057E0
{
    u8 filler0[0x5DC];
    struct MapObject unk5DC[64];
    struct ScriptSpriteSave unk7DC[8]; // sprite snapshot (save_script_sprites)
    u8 unk7FC;
    u8 unk7FD;
    u8 unk7FE; // area id
    u8 unk7FF;
    u16 unk800; // map width * 2 (tiles are bytes, unk810 rows are unk800 / 2 long)
    u16 unk802; // map height * 2
    u16 unk804; // area tilemap header words (sub_08052990(area, 0 / 1))
    u16 unk806;
    u8 filler808[0x8];
    u8 unk810[0x400]; // tile map
    u8 unkC10[0x8]; // tile value -> result of check_tile_and_trigger_battle_action
    u8 unkC18[0x8]; // saved copy of unkC10
    u8 unkC20[0x8];
    u8 unkC28;
    u8 unkC29; // area byte 0 of gUnk_083BEA90 (load_battlefield_data_to_buffer)
    u8 unkC2A; // battle id (set by the debug menu "Battle" entry before game state 6; guess)
    u8 unkC2B;
    u8 unkC2C; // toggled by the debug menu "Rnd.tk" entry (guess: random encounters on)
    u8 unkC2D;
    u8 unkC2E;
    u8 unkC2F;
    u8 unkC30;
    u8 unkC31;
    u8 unkC32;
    u8 unkC33; // Medawatch menu enabled (B opens the field menu only if set)
    u8 unkC34; // area BG tile animation enabled (animate_area_bg_tiles)
    u8 unkC35; // its frame index
    u8 unkC36; // frames until the next one (2: every 3rd frame; runtime-checked)
    u8 unkC37; // random seed
    u8 unkC38[0x10];
    u16 unkC48;
    u16 unkC4A;
    u8 unkC4C;
    u8 unkC4D;
    u8 unkC4E;
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
    u8 fillerCB6;
    u8 unkCB7;
    u8 unkCB8;
    u8 unkCB9;
    u8 unkCBA;
    u8 fillerCBB[0x1];
    s8 unkCBC;
    s8 unkCBD;
};

// Four 0x20-byte records at 0x03005290 / 0x030052B0 / 0x030052D0 / 0x030052F0 (guess: BG layer state)
// Sprite part layer (24 bytes): gUnk_030052D0 / 03005290 / 030052B0 / 030052F0 (head, right arm, left arm,
// legs) are loaded from the ROM templates gUnk_0807ECA0.. and saved per side in struct Unk_08047414.
struct Unk_03005290
{
    u8 filler0[0xD];
    u8 unkD; // toggled between x and -2 - x (toggle_bg_layer_visibility)
    u8 fillerE[2];
    u8 unk10; // root node of the part's sprite tree (0 = hidden)
    u8 filler11[7];
};

// Blend effect state (setup_blend_effect / blend_effect_update)
struct Unk_03006F40
{
    u8 unk0; // BLDCNT target/mode bits
    u8 unk1; // effect type 0..6
    u8 unk2; // 1 = running, 2 = done
    u8 unk3; // EVA
    u8 unk4; // EVB
    u8 unk5; // EVY
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 fillerB;
    float unkC; // blend weights (sub_080487E4: 12.0, 10.0)
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24; // palette fade amount (setup_palette_fade_to_color)
    float unk28;
    float unk2C;
    float unk30;
};

// Affine parameters, gUnk_03006D40[32] (calculate_oam_affine_matrix)
struct AffineParam
{
    s16 scaleX;
    s16 scaleY;
    s16 angle;
    s16 pa, pb, pc, pd;
    u16 pad;
};

// Sprite animation script entry (advance_sprite_animation_frame)
struct SpriteAnimCmd
{
    u16 cmd; // 0xFFFA..0xFFFF: commands, else a frame
    u16 arg;
    u16 duration;
    u16 frame;
};

struct SpriteAnimGfx
{
    u8 unk0;
    u8 filler1[3];
    const void *src;
    void *dst;
    u8 fillerC[4];
};

// Sprite descriptor word (setup_oam_sprite_entries, init_sprite_object_entry).
struct SpriteDesc
{
    u32 unk0_0:4;
    u32 shape:2; // OAM shape / size bits (sub_08044E64)
    u32 size:2;
    u32 w:4; // OAM entries per row / column (guess)
    u32 h:4;
    u32 unk0_16:16;
};

// Bitfield view of struct OamData.
struct OamBits
{
    u16 y:8;
    u16 attr0_8:8;
    u16 x:9;
    u16 attr1_9:7;
    u16 tileNum:10;
    u16 priority:2;
    u16 paletteNum:4;
    u16 affineParam;
};

// Interpolated value stepped once per frame (sub_0805689C sets it up, animation_interpolation_step
// runs it; modes 0x10-0x17).
struct AnimInterp
{
    float unk0; // current value
    float unk4; // base value
    u8 filler8[4];
    s32 unkC; // mode, 0 = idle
    float unk10;
    float unk14; // phase (sine table index)
    float unk18;
    float unk1C; // frame counter
    s32 unk20; // start frame
    s32 unk24; // end frame, 0xFFFF = none
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
    u32 unk44;
};

// BG text-mode tilemap entry.
struct BgTileEntry
{
    u16 tile:10;
    u16 hflip:1;
    u16 vflip:1;
    u16 pal:4;
};

struct SpriteAnchor
{
    u8 filler0[2];
    u16 unk2; // y / x offsets (sub_08045A8C)
    u16 unk4;
    s8 unk6; // initial depth (init_sprite_object_entry)
};

// OAM entry list of a sprite object (copy_oam_entries_with_priority, init_sprite_object_entry).
struct SpriteOamList
{
    struct OamData *oams;
    const struct SpriteAnchor *unk4;
    u16 depth; // > 300 / 200 / 100: OAM priority 3 / 2 / 1
    u8 w;
    u8 h;
};

// Full bitfield view of struct OamData (pret layout).
struct OamFull
{
    u32 y:8;
    u32 affineMode:2;
    u32 objMode:2;
    u32 mosaic:1;
    u32 bpp:1;
    u32 shape:2;
    u32 x:9;
    u32 matrixNum:3;
    u32 hFlip:1;
    u32 vFlip:1;
    u32 size:2;
    u16 tileNum:10;
    u16 priority:2;
    u16 paletteNum:4;
    u16 affineParam;
};

// BIOS ObjAffineSet source / destination (pret syscall.h layout).
struct ObjAffineSrcData
{
    s16 xScale;
    s16 yScale;
    u16 rotation;
};

struct ObjAffineDstData
{
    s16 pa;
    s16 pb;
    s16 pc;
    s16 pd;
};

// Sprite node descriptor: one node (body part piece) of a sprite tree; OAM attributes (init_oam_sprite_entry).
struct SpriteNodeDesc
{
    const u32 **frames; // per frame two entries: OBJ tiles (dma3_copy_or_decompress), palette (or NULL)
    s32 unk4;
    s32 unk8;
    s8 unkC;
    s8 unkD;
    s8 unkE;
    u8 sibling; // next sibling node (0 = none)
    u8 child; // first child node (0 = none)
    u8 paletteNum; // added to the palette argument
    u8 width;
    u8 height;
    u8 wDiv:4; // width / height dividers (> 1: divide)
    u8 hDiv:4;
    u8 bpp:1;
    u8 affineMode:2;
    u8 objMode:2;
    u8 hFlip:1;
    u8 vFlip:1;
};

// Sprite tree node reference (load_sprite_tree_recursive); lists end with node == 0.
struct SpriteTileRef
{
    u8 node:6; // read with ldrb
    u32 frame:8;
    u32 affine:1; // draw with an affine matrix
    u32 alt:1; // frame + 1 on the alternate side; skipped by the tile copy loops
    u32 unk0_16:16;
};

// Per-node OAM entry and transform of a sprite tree (16 bytes).
struct SpriteNodeOam
{
    struct OamFull oam;
    s16 unk8;
    s16 unkA;
    u16 unkC;
    u16 unkE;
};

// A list of OAM entry lists (batch_copy_oam_entries).
struct SpriteOamBatch
{
    struct SpriteOamList **lists;
    u16 count;
};

// 16-byte record stepped by interpolate_entity_positions (unkC: angle-like, wraps at 0x10000).
struct InterpEnt
{
    u8 filler0[8];
    s16 unk8;
    s16 unkA;
    s16 unkC;
    u8 fillerE[2];
};

// Candidate difference and its absolute value (interpolate_entity_positions).
struct InterpCand
{
    s32 val;
    s32 abs;
};

struct Unk_03005310
{
    u8 unk0;
    u8 unk1;
    u8 filler2[0x2];
    u32 unk4; // frame counter
    s16 unk8; // affine pa (identity 0x100, sub_08048B6C)
    s16 unkA; // pb
    s16 unkC; // pc
    s16 unkE; // pd
    s32 unk10; // affine x
    s32 unk14; // affine y
    u16 unk18; // cleared with the gUnk_03006D40 affine params (sub_080492CC)
    u16 unk1A;
    u16 unk1C; // BG0 x scroll (new_game_init)
    u16 unk1E; // BG1-3 x scroll (update_battle_field_frame)
    u16 unk20;
    u16 unk22;
    u16 unk24; // BG0 y scroll
    u16 unk26; // BG1-3 y scroll
    u16 unk28;
    u16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 unk32; // 0x100 (sub_08048B6C)
    s16 unk34; // 0x100
    u16 unk36; // 0-255, stepped by RIGHT / LEFT in sub_08048B94
    u8 unk38;
    u8 unk39;
};

struct Unk_03006D38
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4; // selected item id (item menu, sub_0805CE4C)
    u8 unk5;
    u8 unk6;
};

struct Unk_03005350
{
    s32 unk0; // viewport width (240)
    s32 unk4; // viewport height (160)
    s32 unk8; // viewport centre x
    s32 unkC; // viewport centre y
    float unk10; // destination range x0, x1, y0, y1
    float unk14;
    float unk18;
    float unk1C;
    float unk20; // source range x0, x1, y0, y1
    float unk24;
    float unk28;
    float unk2C;
    float unk30; // x / y scale of the destination -> source map
    float unk34;
    float unk38; // x / y offset
    float unk3C;
    float unk40; // camera position x, y, z (set_state_float_field)
    float unk44;
    float unk48;
    float unk4C; // camera distance
    float unk50; // sin / cos of the yaw angle
    float unk54;
    float unk58; // sin / cos of the pitch angle
    float unk5C;
    float unk60[4]; // projected points x, y, z (update_3d_entity_projections)
    float unk70[4];
    float unk80[4];
    float unk90; // yaw / pitch base angles
    float unk94;
    float unk98;
    s32 unk9C; // camera distance
    s32 unkA0; // projection scale
    double unkA4[2]; // camera origin x, y (sub_08053418)
    s32 unkB4; // projected screen x, y
    s32 unkB8;
    u8 fillerBC[0x4];
    s32 unkC0[4]; // model points x, y, z (from gUnk_083D2DB0)
    s32 unkD0[4];
    s32 unkE0[4];
    u8 fillerF0[0x8];
    s32 unkF8; // model set index into gUnk_083D2DB0
    u8 fillerFC[0xD0];
    s32 unk1CC; // current entity (index into gUnk_03006D30)
    s32 unk1D0; // part count of the current entity
    u32 unk1D4; // flags
    s32 unk1D8; // x, y, d (init_sprite_affine_matrices_and_state)
    s32 unk1DC;
    u32 unk1E0;
    u8 filler1E4[0x26];
    u16 unk20A; // palette colour masks (run_blend_fade_transition)
    u16 unk20C;
};

// 3-D entity, 0x300 bytes; gUnk_03006D30 points to an array of them (0x02039000, 16 entries).
struct BattleEntity3D
{
    s32 unk0; // state (2 = left its range)
    s32 unk4;
    s32 unk8;
    u8 fillerC[0x4];
    float unk10; // x
    u8 filler14[0x8];
    s32 unk1C;
    u8 filler20[0x38];
    float unk58; // y
    u8 filler5C[0x8];
    s32 unk64;
    u8 filler68[0x38];
    float unkA0; // depth (z)
    u8 fillerA4[0x8];
    s32 unkAC;
    u8 fillerB0[0x48];
    float unkF8; // yaw / pitch offsets
    u8 fillerFC[0x14];
    float unk110;
    u8 filler114[0x50];
    float unk164; // x / y / z scale
    u8 filler168[0x14];
    float unk17C;
    u8 filler180[0x14];
    float unk194;
    u8 filler198[0x28];
    s32 unk1C0;
    s32 unk1C4;
    s32 unk1C8;
    u8 filler1CC[0x14];
    s32 unk1E0; // x range check enabled
    u16 unk1E4; // x min
    u8 filler1E6[2];
    u16 unk1E8; // x max
    u8 filler1EA[2];
    s32 unk1EC; // y range check enabled
    u8 unk1F0; // y min
    u8 filler1F1[3];
    u8 unk1F4; // y max
    u8 filler1F5[3];
    s32 unk1F8; // depth range check enabled
    s32 unk1FC; // depth min
    s32 unk200; // depth max
    u8 filler204[8];
    s32 unk20C; // current part
    u8 filler210[0xCC];
    u8 unk2DC[4]; // sprite slot per part
    u16 unk2E0[4]; // x offset per part
    u8 unk2E8[4]; // y offset per part
    u8 filler2EC[0x14];
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
    const void *unk0; // LZ77 BG tilemaps, decompressed to gUnk_03006D14 (layers to 0x06003000 / 5000 / 7000)
    const void *unk4;
    const void *unk8;
};

// Sprite tree object (at 0x02026000).
struct Unk_08047414
{
    u8 *unk0; // gUnk_03002414 record
    struct SpriteNodeDesc **nodes;
    struct SpriteNodeOam *oams;
    struct Unk_03005290 layers[2][4]; // part layers saved per side (setup_scene_bg_layers_and_sprites)
};

// 48-byte records at gUnk_03005308, one per side (setup_scene_bg_layers_and_sprites).
struct SceneSlot
{
    u8 filler0[4];
    u32 unk4; // head part
    u32 unk8; // right arm part
    u32 unkC; // left arm part
    u32 unk10; // legs part
    u8 filler14[0x14];
    u32 unk28; // side
    u32 unk2C; // flags: 1 pending, 2 load, 4 loaded, 8 visible
};

// Menu / save screen work area, reached through the pointer gUnk_03006F74 (layout as used by code_0805AB40)
// One of 18 points placed on a hexagon (ring_points_place_on_hexagon) or a circle (ring_points_place_on_circle)
struct RingPoint
{
    s16 unk0; // radius
    s16 unk2; // x
    s16 unk4; // y
    s16 unk6;
    s16 unk8; // radius * sin
    s16 unkA; // radius * cos
    u8 fillerC[4];
};

struct Unk_03006F74
{
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u8 unk4; // title menu: first selectable entry (1 without a valid save)
    u8 unk5; // title menu: cursor (0-2)
    u8 unk6;
    u8 unk7;
    u32 unk8;
    u8 unkC; // Item screen: cursor item index (page = unkC / 5)
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10; // number of items unpacked by unpack_item_inventory_to_buffer
    u8 unk11; // first visible list row
    u8 unk12;
    u8 unk13; // cursor row
    u8 filler14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 filler1B;
    u32 unk1C;
    u8 unk20; // number of save / link slots shown (update_battle_sprite_priority_flags)
    u8 filler21[0xA];
    u8 unk2B;
    u16 unk2C;
    u8 unk2E; // Medal list: first visible row (render_battle_medal_names)
    u8 unk2F; // Medal list: cursor row
    u8 unk30; // Medal list: number of entries in unkB0
    u8 unk31;
    u8 unk32;
    u8 unk33;
    u8 unk34;
    u8 filler35;
    u16 unk36; // save screen: last BG tile index loaded (sub_0805D628)
    u16 unk38;
    s16 unk3A; // title: blend step (sub_0805BB10)
    u16 unk3C;
    s16 unk3E;
    u16 unk40[4];
    u8 unk48;
    u8 unk49;
    u8 unk4A;
    u8 unk4B;
    u8 unk4C; // message pending (sub_08065418)
    u8 filler4D[0x3];
    u8 unk50[8]; // blend effect state (init_blend_effect, blend_fade_step_08065598)
    u8 unk58[0x20]; // name text buffer (sub_0805EE94 copies it to the player or Medal name)
    u16 unk78; // link: the other player's keys last frame (sub_0805B9EC)
    s8 unk7A;
    s8 unk7B; // link: both sides OK flag, 0 / -1 (fade_state_dispatch)
    s8 unk7C; // link: both sides OK flag, 0 / -1 (fade_state_dispatch)
    s8 unk7D; // length of the text at *unkAC (scene_text_scroll_step)
    u8 unk7E; // rings: random rotation mode (update_scene_animation_frame)
    u8 unk7F; // sub_08074B68 result (sub_08065618); song played by battle_cutscene_dispatch
    s16 unk80[3]; // rings: rotation angles x / y / z
    s8 unk86[3]; // rings: rotation speeds, clamped to +-16
    u8 filler89;
    u16 unk8A[4]; // race: per-sprite values set by init_scene_with_palette_and_song_5
    u16 unk92[4];
    u16 unk9A[4];
    u8 unkA2[5];
    u8 unkA7[5];
    const u8 *const *unkAC; // scene text (scene_text_scroll_step)
    u8 unkB0[0x20]; // Medal list: Medal indices (sub_08064CA0)
    struct RingPoint unkD0[18]; // points on a hexagon / circle (ring_points_place_on_hexagon, ring_points_place_on_circle)
    s32 unk1F0[4][4]; // 8.8 fixed-point 4x4 transform matrix (matrix_set_identity, matrix_rotate_xyz)
    struct Unk_03000BE0 unk230; // link: Medal record received from the other player (sub_08063E38)
    u8 unk270[0x30]; // message text buffer (sub_08061180)
};

// BLDY fade state (init_blend_effect / blend_fade_step_08065598; Unk_03006F74.unk50)
struct BlendEffect
{
    u16 mode; // BLDCNT effect bits (| 0x3F)
    u8 unk2; // BLDY level
    u8 unk3; // frames per step
    u8 unk4; // frame counter
    s8 unk5; // level change per step
};

// Item list built at 0x02040000 (an EWRAM mirror) by unpack_item_inventory_to_buffer, one per inventory slot
struct ItemListEntry
{
    u16 id;
    u16 count; // 0: empty slot
};

// Shop sell list built at 0x02040000 by shop_build_sell_list, one per sellable Medapart
struct ShopSellEntry
{
    u16 id; // Medapart id
    u8 count; // owned - equipped (MEDAPART_INV bytes 0 - 1)
    u8 unk3; // part data byte 3 (gender)
    u32 price; // part data byte 0xB * 100
};

// Game flags byte at 0x03001784
struct Unk_03001784
{
    u32 unk0_0:1; // sub_0805D96C: next game state 13 instead of 6
    u32 unk0_1:1; // saved in SaveData.flags bit 5
    u32 unk0_2:30;
};

// Battery save image (0x1CBC bytes), built by serialize_save_data and read back by load_save_data
struct SaveData
{
    u8 magic[16]; // copied from gSaveMagic
    struct Unk_03002B70 unk10; // gUnk_03002B70 (money, name, ...)
    struct Unk_03000BE0 medals[30]; // gUnk_03000BE0
    u16 medaparts[4 * 120 * 2]; // gMedapartInventory, one byte per halfword
    struct Unk_030017A0 team[9]; // gUnk_030017A0
    u8 items[64][2]; // gItemInventory
    u16 checksum; // byte sum of the whole image, computed with this field 0
    u8 fillerFF6[2];
    u8 field[0xCC0]; // gUnk_030057E0
    u8 flags; // bits 0-1 gUnk_03001788, bit 2 gUnk_03001360, bits 3-4 gUnk_03000B94, bit 5 gUnk_03001784.unk0_1
    u8 filler1CB9[3];
};

// Race course backgrounds (init_battle_background_layers), by gUnk_03006FDC
struct Unk_08486160
{
    u8 unk0; // nonzero: fixed field gUnk_03006F84 = unk1 (else random, get_entity_speed_value)
    u8 unk1;
    s16 unk2; // encounter setup (gUnk_083C1A00) of the second racer (load_battle_sprite_graphics)
    u8 unk4; // decompress_indexed_asset set for the BG at 0x06004800
    u8 filler5[1];
    s16 unk6; // encounter setup of the third racer
    u8 unk8; // ... for the BG at 0x06005000
    u8 unk9; // race intro message index: gUnk_084864E8[unk9], [unk9 + 1] (sub_08069F80)
    u8 fillerA[2];
};

#endif // GUARD_STRUCTS_H
