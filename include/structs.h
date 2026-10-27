#ifndef GUARD_STRUCTS_H
#define GUARD_STRUCTS_H

// Structures that are not understood yet. Fields are named by offset.

// Sound sequence track (sound_seq.c), 0x74 bytes; unk14 is the read pointer into the sequence data.
struct SoundTrack {
    struct SoundTrack *unk0; // previous in the circular list at gUnk_03007014->unk5E4
    struct SoundTrack *unk4; // next in the circular list at gUnk_03007014->unk5E4
    u8 *unk8;                // ring buffer of 0x30 bytes, write index at unk8[0x30]
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
    u8 unk5A;        // Medabot detail cursor: 0 Medal, 1-4 Medaparts (runtime-checked)
    u8 envAttack;    // high nibble: frames per step, low nibble: volume step
    u8 envDecay;     // same layout as envAttack
    u8 envReleaseAt; // release starts when this many frames of the note remain
    u8 envRelease;   // high nibble: frames per step, low nibble: steps
    u8 envCounter;   // frames until the next envelope step
    s8 envStep;      // volume change per step / steps left in release
    u8 envPhase;     // 0 off, 1 key-on delay, 2 attack, 3 decay, 4 sustain, 5 release
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
struct SoundSampleHeader {
    u32 unk0;
    u16 rate;    // playback rate at baseNote
    u8 fineTune; // 1/128 semitones
    u8 baseNote;
    u32 unk8;
    u32 unkC;
    s8 data[1]; // 8-bit PCM
};

// Direct Sound channel (FIFO A / B) state, 0x48 bytes, two of them in the sound work area.
struct SoundMixChannel {
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

struct Unk_03006D20 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 filler4[0x4];
    u16 unk8; // base y of a sprite hop (script_sprite_hop_step)
    u8 unkA;  // sprite slot (gSpriteEntries index)
    u8 unkB;
    u8 unkC;
    u8 fillerD[0x3];
};

// 0x03001800 while game mode 3 (boot logos / story intro, code_0806B160) runs; the same RAM as gUnk_03001800.
struct Unk_03001800_s {
    u16 nextMode; // gGameMode / gGameState / gGameSubState to go to when the scene ends
    u16 nextState;
    u16 nextSubState;
    u16 unk6;
    s32 timer;             // frame counter of the current step
    union {                // 4 bytes: agbcc pads unions to a word
        u16 h;             // story intro: page (graphics gUnk_08487328 / text gUnk_08486EEC)
        u16 afterSubState; // opening intro: sub-state to run after the next silhouette / scan step
        u8 b;              // boot logos: nonzero once START may skip them (boot_logos_check_skip)
        s8 s[4];           // bomb minigame: roundBombs / dropInterval / bombsLeft (struct Unk_03001800_bomb)
    } unkC;
    union {
        s32 w; // countdown: play_song(3) when it reaches 0
        struct {
            u8 state; // Medabots Lecture step: index into gWeeklyLectureSteps
            u8 step;  // step counter of the current state
            u8 pos;   // script position (weekly_lecture_run_pose)
            u8 pad;
        } lecture;
    } unk10;
    u8 filler14[0x1A];
    // The rest is the opening intro's Medapart scan screen (title/intro.c).
    u8 scanTextLen; // glyphs typed into the 10x4 scan text box (intro_type_scan_text)
    u8 unk2F;
    u16 scanTextGlyphs[0x50]; // scan text glyphs, decompressed by intro_load_scan_sprites
    u8 partNameLen;           // letters typed of the part name (intro_type_part_name)
    u8 unkD1;
    u16 partNameTiles[13]; // part name tile row, DMA'd to 0x0600FC44
    u8 lineStep;           // tile step of the pointer line being drawn (intro_draw_pointer_line)
    u8 lineIdx;            // pointer line being drawn (0-2)
    s8 flashAlpha;         // BLDALPHA fade of the lightning flash (intro_flash_state)
    u8 unkEF;
    u16 frameCounter; // counter readouts in the top right (intro_draw_counters)
    u16 noiseCounter;
    u16 unkF4; // guess: Rokusho pose scroll/scale values (only intro_init / intro_rokusho_pose_state)
    u16 unkF6;
};

// 0x03001800 while game mode 3 state 5 (gBombGameStates, the bomb minigame) is active; the same RAM as
// gUnk_03001800 (bomb_game_init sets the first three counters through Unk_03001800_s.unkC).
struct Unk_03001800_bomb {
    u8 filler0[8];
    s32 timer;          // frames since the round started; bombs drop when it passes nextDropTime
    s8 roundBombs;      // bombs this round (50; after a lost life: bombs left + 10, at most 50), entries in bombLanes
    s8 dropInterval;    // base frames between drops (12, +4 per lost life)
    s8 bombsLeft;       // bombs still to drop this round, shown as BOMB (bomb_game_draw_bomb_count)
    s8 bombLanes[0x32]; // lane of each bomb: 0 left, 1 middle, 2 right; a random walk (bomb_game_pick_lanes_state)
    s8 playerPos;       // -8..8, pushed by R / L, eases back to 0; lane = playerPos / 5 + 1 (bomb_game_move_player)
    u8 filler42[2];
    s32 nextDropTime; // timer value of the next bomb drop (bomb_game_drop_bombs)
};

// 0x03001800 during game mode 3 state 6, the "Medabots Weekly" TV show (medabots_weekly_update); the same RAM
// as gUnk_03001800.
struct MedabotsWeeklyWork {
    u16 unk0; // next mode? (cf. Unk_03001800_s.nextMode)
    u16 unk2; // next state?
    u8 filler4[8];
    u8 scrollBg3;  // nonzero: scroll BG3 every other frame (weekly_scroll_bg3)
    u8 animTiles;  // nonzero: animate BG tiles (weekly_update_studio)
    u8 tileFrame;  // tile animation frame 0..5 (every 4 frames)
    u8 tileFrame2; // tile animation frame 0..5 (every 16 frames)
    u8 filler10[4];
};

// One step of a sprite animation (gUnk_08485D5C).
struct SpriteAnimFrame {
    u16 frame;    // copied to the sprite's unk6
    s16 duration; // frames
    u8 next;      // index of the next step
    u8 filler5[3];
};

// 0x03002B70: money, then a 10-byte string (init_save_prompt_text writes a default one).
struct Unk_03002B70 {
    u32 money;
    u8 unk4[16];  // player name, 0xFE-terminated (validate_save_data rejects an empty one)
    u16 unk14[2]; // gUnk_03002B84: [0] counted on every Robattle, [1] only on some (guess: fought / won); both <= 9999,
                  // [0] >= [1]
    u32 unk18;    // at most 0x014996FF (validate_save_data; guess: play time in frames, below 100 hours)
};

// Tile animation slot at gUnk_03000440.tileAnims (tile_anim_init / tile_anim_run): each script step copies
// frameTiles tiles of frame N from the EWRAM sheet (at tile sheetTile) to OBJ tile objTile.
struct TileAnim {
    u8 wait;        // frames left on the current step
    u8 pos;         // script index (u16 units; starts at 2, after the x/y header)
    u8 state;       // 0xFF once the script has ended
    u8 objTile;     // destination OBJ tile
    u16 sheetTile;  // first tile of the sheet in EWRAM
    u16 frameTiles; // tiles per frame
};

// Graphics list entry (gUnk_083CE480 lists, end at size 0): size in 32-byte tiles, gUnk_083B2584 index.
struct GfxListEntry {
    u16 size;
    u16 index;
};

struct Unk_03000440 {
    u8 unk0; // message window: 0 = dim the palettes while open (text_window_init args a, b, c)
    u8 unk1; // portrait mode: 0 = animated, 1 = static, 2 = none
    u8 unk2; // 1 = no window frame
    u8 filler3;
    u8 unk4; // message handler state (run_message)
    u8 filler5[0x3];
    const u8 *unk8; // current message (run_message)
    u16 unkC;       // read position in unk8
    u8 unkE;
    u8 unkF;  // portrait: shown animation / side (0 = right)
    s8 unk10; // portrait: sprite set (-1 = none)
    s8 unk11; // portrait: index
    u8 unk12; // 1 = a portrait is shown
    u8 unk13; // 1 = stop printing this frame (message_print_step)
    u8 unk14; // text pen x in pixels
    u8 unk15; // pixels left in the current word
    u8 unk16; // pixels filled in gTextComposeTile
    u8 unk17; // text line 0-1
    u8 unk18; // 1 = the current word has been measured and fits
    u8 unk19; // 1 = line full, 2 = page full (wait for A / B)
    u8 unk1A; // wait counter (0xF7 / 0xFA codes)
    u8 unk1B; // end mode step
    u8 unk1C; // palette dim level 0-9
    u8 filler1D[0x3];
    u8 *unk20; // string being drawn (message name / number buffers, message_print_var_step)
    u8 unk24;  // read position in unk20
    u8 unk25;  // page cursor blink timer
    u8 unk26;  // window frame animation step
    u8 unk27;  // 1 = alternate font (0xF8 code)
    u8 unk28;
    u8 unk29; // choice menu state (poll_choice_menu)
    u8 unk2A;
    u8 unk2B; // sprite slot (advance_sprite_scroll_animation)
    u8 unk2C; // tilemap x (copy_transition_tiles_to_bg2)
    u8 unk2D; // tilemap y
    u8 filler2E[0x2];
    u8 unk30;    // game state to return to from game state 63 (debug_menu_exit)
    u8 unk31;    // its sub-state
    u8 unk32;    // game state 63 menu cursor, 0-10 (debug_menu_select_input)
    u8 unk33;    // game state 63 submenu sub-state
    u8 unk34;    // game state 63 submenu row
    u8 unk35[3]; // game state 63 submenu values, one per row
    u8 filler38;
    u8 unk39; // game state 63 "Motion" entry: scene / animation id 0-0x79 (START / SELECT)
    u8 filler3A[0x2];
    u8 unk3C; // where the Medals / Medaparts screen was opened from: 0 Medawatch, 1 Medabot detail
              // (medabot_detail_open_info), 2/4 others
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
    u16 unk48; // Medal record unk20/unk28 index 0-7 (medal_skill_debug_edit_input)
    u8 unk4A;  // Medals: choice from medal_trade_choice_input (0 A, 2 B)
    u8 unk4B;  // Medals screen: song 7 started (when opened with unk3C == 4)
    u8 filler4C[0x4];
    u8 unk50; // Medabots screen mode: 0 plain (from the Medawatch), 1-3 team select (guess: battle type; 3 needs all
              // three picks)
    u8 unk51; // Medabots screen: cursor slot (0-8)
    u8 unk52; // Medabots screen: reorder pick, slot | 0x80 while holding
    u8 unk53; // Medabot detail: the edited set fails validate_medapart_stats (icon shown in palette 8)
    u8 filler54[0x2];
    u8 unk56; // game state 3: 0 = entered from the field (fades from the backup palette), 1 = from a submenu
    u8 filler57[0x3];
    u8 unk5A; // Medabot detail: row cursor, 0 Medal, 1-4 head / right arm / left arm / legs (runtime-checked)
    u8 filler5B;
    u16 unk5C; // timer
    u8 unk5E;  // Medabot detail: which Medabot is shown, L/R toggle (runtime-checked)
    u8 filler5F[0x5];
    struct TileAnim tileAnims[4];
    u8 unk84; // field menu: animation frame counter
    u8 unk85;
    u16 unk86; // link exchange frame counter; also the current wave x offset of start_scanline_wave_scroll
    u8 unk88;  // field menu: row animation counter
    u8 unk89;  // Robattle: 1 skips the bot setup in robattle_setup_bots
    u16 unk8A; // rng seed (rng_next_byte)
    u8 unk8C;  // last rng_next_byte value
    u8 unk8D;  // rng table index when unk89 is set
    u8 unk8E;  // field menu cursor: 0 Medawatch, 1 Item, 2 Vehicle, 3 Save (runtime-checked)
    u8 unk8F;  // Medawatch menu cursor (0..2)
    u8 unk90;  // blend effect mode 1-6 (set_blend_effect_mode): odd fades the blend in, even out
    u8 filler91;
    u16 unk92; // blend effect speed, added to unk94 every frame
    u16 unk94; // blend effect progress (done at 0x100)
    u8 unk96;
    u8 unk97; // shown Medabot: Medal slot (0x1E none), then unk98-9B its four Medaparts (>= 120 none); the
              // detail screen's edit copy (medabot_detail_take_apart / assign_medal_to_team_slot)
    u8 unk98;
    u8 unk99;
    u8 unk9A;
    u8 unk9B;
    u8 unk9C; // game state 6: 1 picks song 14 and counts gUnk_03002B84[1] (guess: battle won)
    u8 filler9D;
    u8 unk9E[0x50]; // digit buffer (divide_by_10000); also four 0x14-byte name buffers for messages
                    // (message_print_var_step)
    u8 unkEE;       // start of a 16-byte part data record (load_part_data): ability (gUnk_083B656C name)
    u8 unkEF;       // skill id; >= 100: leg type (gUnk_083BE97C[unkEF - 100])
    u8 unkF0;       // skill type (gUnk_083B6EC8 name)
    u8 unkF1;       // gender: 0 male, 1 female (matched against gUnk_030017A0[].unk1)
    u8 unkF2;       // stats: head Armor, Success, Power, (F5 power icon flag), Uses; legs Armor, Propulsion,
    u8 unkF3;       // Evasion, Defense, Proximity, Remoteness (runtime-checked on the detail page)
    u8 unkF4;
    u8 unkF5;
    u8 unkF6;
    u8 unkF7;
    u8 fillerF8[0x16];
    u8 unk10E[0x10]; // 16-byte record from gUnk_083B6158 (per Medal graphic index)
    u8 filler11E[0x10];
    u8 unk12E; // set: copy gOamBuffer to OAM at the next vblank
    u8 unk12F; // sprite slot (sub_08028E84)
    u8 unk130; // Robattle: set to 1 around the action script commands script_op_closeup_enter .. script_op_closeup_exit
    u8 unk131; // set: vblank_body skips the OAM 88-127 upload in mode 2
    u8 unk132;
    u8 unk133; // after-battle Medal level-up: Medal slot (find_medal_slot_by_id - 1)
    u8 unk134;
    u8 unk135;
    u8 unk136;
    u8 unk137;
    u8 unk138; // nonzero: link_robattle_check_prize_game jumps to sub-state 0x30
    u8 unk139; // game state 3 setup step (medabots_screen_load_gfx); Robattle setup step
    u8 unk13A;
};

struct SpriteEntry {
    u16 unk0;
    s16 unk2;
    s16 unk4;
    u16 unk6; // animation frame
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u32 unkC_0 : 8;  // x, 24.8 fixed point: fraction
    s32 unkC_8 : 24; // integer part
    u32 unk10_0 : 8; // y, 24.8 fixed point
    s32 unk10_8 : 24;
    u32 unk14_0 : 8; // z / depth, 24.8 fixed point
    s32 unk14_8 : 24;
    u16 unk18;
    u16 unk1A;
    u8 unk1C;
    u8 filler1D[0x3];
    u8 unk20; // animation state (0-3)
    u8 unk21;
    u8 unk22; // position in the animation script (advance_sprite_animation_frame)
    u8 unk23; // frames shown of the current script frame
    u8 unk24; // animation script id, gSpriteAnimScripts (sprite_anim_start)
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
    u16 unk34; // frame target unk1A counts up to (weekly_set_sprite_effect)
    u8 filler36[0x4];
    u16 unk3A; // previous frame's unk1A (update_battle_bot_entry_animations)
    u8 filler3C[0x4];
};

struct Unk_030055A0 {
    u16 unk0;
    u16 unk2;
};

// One link packet as sent / checked (12 bytes): 4 halfwords sum to 0xFFFF when intact.
struct SioPacket {
    u8 frame;     // sender's frame counter
    u8 errFlags;  // players that were connected but not received
    u16 checksum; // ~sum of the first 4 halfwords
    u16 data[2];  // payload (gSioPlayers.send / .recv)
    u16 pad[2];
};

// Multiplayer serial link work area at 0x03005170 (serial_link_*; the IWRAM interrupt handler
// serial_multiplayer_transfer_handler and link_buffer_swap_arm in crt0.s use it too).
struct SioLink {
    u8 isParent;    // 8 once this unit drives the transfers with timer 3
    u8 running;     // 0 = waiting for the link, 1 = running
    u8 connected;   // per-player bits (main loop)
    u8 recvOk;      // per-player bits, packets received intact this frame
    u8 sendPending; // serial_prepare_send_packet filled nextSend
    u8 recvDone;    // all 4 words received (cleared by link_buffer_swap_arm)
    u8 started;     // set by sio_start_transfers
    u8 error;       // SIOCNT error bit
    u8 filler8[3];
    u8 frame; // frame counter, sent in each packet
    u8 fillerC[8];
    s32 sendIdx; // halfword being sent (6 = idle)
    s32 recvIdx; // halfword being received
    struct SioPacket *nextSend;
    struct SioPacket *curSend;
    u16 (*curRecv)[6]; // [player][halfword]
    u16 (*lastRecv)[6];
    struct SioPacket *recvCheck;
    struct SioPacket sendBuf[2];
    struct SioPacket recvBuf[3][4];
};

// SIOCNT (multiplayer mode) + SIOMLT_SEND as one 32-bit word.
struct SioMultiCnt {
    u32 baudRate : 2;
    u32 si : 1;
    u32 sd : 1;
    u32 id : 2;
    u32 error : 1;
    u32 enable : 1;
    u32 unk8 : 4;
    u32 mode : 2;
    u32 irq : 1;
    u32 unk15 : 1;
    u32 data : 16;
};

// The same two registers as u16 bitfields (serial_link_init_and_status reads them this way).
struct SioCnt {
    u16 baudRate : 2;
    u16 si : 1;
    u16 sd : 1;
    u16 id : 2;
    u16 error : 1;
    u16 enable : 1;
    u16 unk8 : 4;
    u16 mode : 2;
    u16 irq : 1;
    u16 unk15 : 1;
    u16 data;
};

// Serial (multiplayer link) state at 0x03005010.
struct Unk_03005010 {
    u32 unk0; // per-player "packet received" bits (serial_link_init_and_status)
    u16 unk4; // send packet (serial_prepare_send_packet)
    s16 unk6;
    u16 unk8[4][2]; // received packets, one per player
    u8 filler18;
    s8 unk19[4]; // per-player timeouts
    u8 unk1D;
    u8 unk1E;
};

// Decompressed tilemap (write_tilemap_to_vram_08000E94, load_tilemap_rows_to_vram).
struct Tilemap {
    u32 width;
    u32 height;
    u32 unk8;
    u32 unkC;
    u16 data[0];
};

struct OamData {
    u16 attr0;
    u16 attr1;
    u16 attr2;
    u16 affineParam;
};

// A 3-byte ROM table copied to the stack as a whole (divide_by_3).
struct ByteTable3 {
    u8 b[3];
};

// Bitfield view of gUnk_03000440.unk14 (text pen x): the text tile flush code tests the pixel offset in
// the current 8-pixel tile through it, which reloads unk14 (message_new_line and friends).
struct TextColBits {
    u8 filler0[0x14];
    u8 col : 3;
    u8 hi : 5;
};

// Struct view of the gUnk_083B4AE0 tilemap pointer table: the Robattle screen wipes read entry 0x69 as a
// field (base + 0x1A4, reloaded after each call: closeup_enter_wipe, closeup_exit_wipe).
struct Unk_083B4AE0 {
    const void *unk0[0x49];
    const void *unk124; // message "more text" cursor, blink off (message_wait_next_page)
    const void *unk128; // message cursor, blink on
    const void *unk12C[0x1E];
    const void *unk1A4; // blank tilemap row
};

// Sprite tree render buffer (gSpriteWork, usually at 0x02024000): render_sprite_node_recursive appends depth-sorted
// OAM entries and affine matrices here; the vblank code (engine/main) copies them to OAM.
struct SpriteWork {
    u8 filler0[0xB84];
    struct OamData oamBuf[129];
    u16 affineBuf[0x84]; // affine parameters, 4 per matrix (copy_oam_affine_params)
    u8 oamCount;         // OAM entries used in oamBuf
    u8 affineIdx;        // next affine matrix (wraps after 31); low bits also give the matrix / flip bits
    u8 unk1096;
    u8 unk1097;
};

// Opponent Medabot in an encounter setup (gUnk_03001800.unk4).
struct EncounterBot {
    u8 parts[4]; // head, right arm, left arm, legs part ids
    u8 unk4;     // Medal (gUnk_083B6158 record; init_enemy_bot_medal)
    u8 unk5;     // Medal level
    u8 unk6[4];  // two 4-bit Medal record unk18 entries per byte
    u8 unkA;     // Medal record unk9
    u8 fillerB;
};

// BG scroll offsets: gBg0Scroll..gBg3Scroll, added to gUnk_03002C2C and written to BGxHOFS/VOFS by vblank_body.
struct Vec16 {
    s16 x;
    s16 y;
};

// Battle Medapart record (0x18 bytes, 4 per gUnk_03000590 record from +0x48; battle_bots_load_parts).
// Screen position returned by value (a 4-byte struct, so in memory via a hidden pointer: calc_polar_to_screen_coords).
struct Coords16 {
    s16 x;
    s16 y;
};

// 4-byte sprite positions (gBattleSeqEffectSetPos, battle_seq_cmd_spawn_effect_set).
struct Unk_083AF94C {
    u16 x;
    u8 y;
    u8 filler3;
};

struct BattlePart {
    u8 data[0xD]; // part data record (load_part_data); data[0xA] summed as armor (accumulate_team_armor_stats)
    u8 fillerD;
    u8 unkE; // copied to the record's unkE0 / unkE1 when this part is chosen (battle_bot_select_part)
    u8 unkF;
    u8 unk10; // head: copy of data[8]
    u8 unk11; // current armor, starts as data[4] = max armor (Status screen, runtime-checked); 0 = broken
              // (legs: data[4..9] copied to unk11..unk16)
    u8 unk12; // legs: data[5] (Propulsion; bot_move_delay_sub_propulsion)
    u8 unk13; // legs: data[6..9] (unk12..unk16 restored by bot_restore_leg_stats, halved by bot_halve_broken_leg_stats
              // when broken)
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17; // part id
};

// 8-byte entry of the sort buffer at 0x02023000, sorted by key then key2, largest first (sort_buffer_descending).
struct SortEntry {
    u16 key;
    u16 key2;
    u16 value;
    u16 unk6;
};
// The game indexes it through the constant address (a symbol doesn't match find_most_damaged_part).
#define SORT_BUFFER ((struct SortEntry *)0x02023000)

// Per-side record at gUnk_03001800.unk28 (0 team, 1 opponents).
struct Unk_03001800_28 {
    u8 unk0;
    u8 unk1;       // compared between the sides when TIME runs out with a tie (robattle_judge_time_up)
    u8 active;     // a trap / Team Form is laid on this side (trap_apply)
    u8 skill;      // its skill id: 0xA Grap Trap, 0xB Shot Trap, 0xC Attack Clr, 0x33 Team Form, 0x5A Medaforce trap
    u8 durability; // traps: worn down by the caught Medabot's legs (trap_hit_wear); Attack Clr: uses left;
                   // Team Form: added to the attack power (action_calc)
    u8 power;      // trap: damage dealt when it springs (trap_hit_calc_damage)
    u8 unk6;
    u8 unk7;
};

struct Unk_03001800 {
    u8 unk0; // encounter: opponent message index (gUnk_083C2BBC)
    u8 unk1;
    u8 unk2; // opponent Medabot count
    u8 unk3; // nonzero: fixed opponent parts (else each part is re-rolled by random_pick_weighted4)
    struct EncounterBot unk4[3];
    struct Unk_03001800_28 unk28[2]; // per side (0 team, 1 opponents)
    u8 unk38;                        // battlefield
    u8 unk39[8];                     // copied from gBattlefieldParams[unk38] (battlefield_load_params)
    u8 unk41[3];                     // team select picks: 0x10 | Medabots screen slot, 0 = empty (runtime-checked)
    u8 unk44;                        // Robattle: bit (1 << team Medabot) set by robattle_command_auto
    u8 unk45[6][2];                  // Robattle action queue: record + 1 (0 = free), priority = legs Propulsion
                    // (battle_queue_add, sorted by battle_queue_sort; robattle_turn_next_action tests [0][0])
    u8 unk51; // Robattle: Medaforce gauge points left to add / remove one per frame (medaforce_gauge_fill_step /
              // _drain_step)
    u8 unk52;
    u8 unk53;
    u8 unk54;
    u8 unk55; // Robattle: result flags (2, 4, 8, 0x10 pick sub-states 0x60-0x78 in robattle_turn_loop)
    u8 unk56; // Robattle: frame counter, mod 32 (robattle_time_tick)
    u8 unk57; // Robattle: TIME left, 40/30/20 by gOptionTimeLimit (robattle_time_init), -1 every 32 frames
              // (robattle_time_tick)
    u8 unk58; // Robattle: nonzero blocks Medaforce (check_medaforce_availability)
    u8 unk59; // Robattle: effect amount left to apply (battle_tick_buff_effect / battle_tick_status_effect)
    u8 unk5A; // Robattle: team Medabot count (3 in battle_start.ss0)
    u8 unk5B;
    u8 unk5C;    // Robattle AI: record choosing its action (battle_process_all_bot_actions)
    u8 unk5D;    // Robattle AI: part being considered (0-2)
    u8 unk5E;    // Robattle AI: target record + 1
    u8 unk5F;    // Robattle AI: target part + 1
    u8 unk60;    // first record of the target side (battle_enemy_side_first_record, sub_08026FF8)
    u8 unk61[3]; // Robattle AI: candidate targets (record + 1, 0 = none; select_battle_targets_and_actions)
    u8 unk64[4]; // filled by get_bot_part_effective_values (robattle_status_screen_init); AI part order from
                 // gUnk_083AD2F0 (battle_ai_roll_part_order)
    u8 filler68[0xC];
    u8 unk74[8]; // copied from gUnk_083C3B5C[unk38] (load_battle_script_entry_b); [3] nonzero: [4] << 8 | [5] ->
                 // REG_BLDALPHA
    u8 unk7C;    // battlefield animation frame, 0-0x7F (advance_battle_animation_frame)
    u8 unk7D;    // battlefield animation tick, 0-2
    u8 unk7E;    // battlefield animation tile count / 8 (gUnk_083C40B8)
    u8 unk7F;    // battlefield animation tile block (gUnk_083C40C3), 0xFF ends the loop
    u8 unk80; // index of a 256-byte record in gUnk_03000590 (medal_rotation_store_to_battle_bot copies Medal rotation
              // data there)
    u8 unk81; // Robattle: selected command ring slot 0-5 (name gUnk_083C466C[unk81], runtime-checked)
    u8 unk82;
    u8 unk83; // Robattle: command ring turning, 1 right / 2 left (command_ring_input); nonzero blocks
              // robattle_command_input
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
    u8 unk9C[5]; // cleared by battle_substeps_reset
    u8 unkA1[5]; // cleared by battle_message_reset
    u8 unkA6;    // battle message id (gUnk_083C65C4) shown by effect_step_show_message; also the next handler
    u8 unkA7; // Robattle: part index (0-3) of the acting Medabot that unk11C is written back to (restore_changed_part)
    u8 unkA8; // Robattle: skill id (data[1]) of the acting Medabot's chosen part (action_phase_resolve_command)
    u8 fillerA9;
    u8 unkAA;      // sub-state of the gTrapHitSteps handlers (trap_hit_run) and gActionPartCheckSteps handlers
                   // (action_part_check_run)
    u8 unkAB;      // 0-2, set with unkB5 = 1 by the gActionPartCheckSteps handlers (trap_hit_end_continue..)
    u8 unkAC[0x9]; // Robattle action script: operands of the current command (battle_script_load_operands)
    // action effect step script done: cleared by each step dispatcher (trap_hit_run,
    // action_part_check_run..), set by the last step; the callers (script_op_trap_hit,
    // script_op_action_part_check) then call battle_script_advance
    u8 unkB5;
    u8 fillerB6[0x1];
    u8 unkB7; // attack result: 1 missed (target dodged, battle_check_dodged), 3 countered (reaction_check_counter)
    u8 unkB8; // attack result: 2 nullified (Full / Half Block, immunities), 4 absorbed as healing (attack_hit_branch)
    u8 unkB9; // raised by gUnk_03001800.unkEC up to 0x78 on the own side, lowered on the other (sub_0802C588, written
              // as &unkB8 + 1 to match)
    u8 unkBA;
    u8 unkBB;
    u16 unkBC; // Robattle action script: offset of the current command (battle_script_read_byte /
               // battle_script_advance)
    u8 unkBE;  // set with unkB7 / unkB8 by the script commands script_op_half_block_check / script_op_full_block_check
               // (1, 5)
    u8 unkBF;  // set with unkB8 = 4 by battle_check_absorbed / determine_battle_target_mode (2-4)
    u8 fillerC0[0x8];
    u16 unkC8; // Robattle: effect amount (shown by trap_hit_damage_popup_init, subtracted by trap_hit_apply_damage)
    u16 unkCA; // damage passed to battle_set_damage_vs_armor (attack_hit_carry_over_retarget)
    u16 unkCC; // copy of unkC8 (battle_set_damage_break_part)
    u8 fillerCE[0x2];
    u8 unkD0;     // last part (3..0) of the acting Medabot with armor left (trap_hit_calc_damage)
    u8 unkD1;     // nonzero: trap_hit_check_part_broken goes to sub-state 0x1A
    u8 unkD2[4];  // per part: nonzero shows an effect sprite (sub_08026AF4)
    u16 unkD6[4]; // per part: amounts shown by sub_08026924
    u8 unkDE;     // record + 1 of the teammate guarding unk88 with Defence / Full / Half Block (guard_find), 0 = none
    u8 unkDF;     // its block skill: 0x1B Defence, 0x1C Full Block, 0x1D Half Block (guard_load_graphics)
    u8 unkE0[3];  // per team record: record + 1 waiting for reset_battle_bot_state (bot_defeat_find)
    u8 fillerE3[0x5];
    s16 unkE8; // passed to battle_inflict_status with unkEC (status_attack_apply)
    s16 unkEA; // unkE8 / 4 (script command script_op_success_bonus)
    s16 unkEC; // amount for battle_calc_damage_split (attack_absorbed_find_part); counted down by
               // attack_hit_check_carry_over
    u16 unkEE; // + Medal level + matching parts power + rng & 7 (accumulate_battle_speed_value)
    u8 fillerF0[0x2];
    s16 unkF2; // copy of unkE8 when the action phase starts (battle_check_guard_or_cover,
               // battle_check_damage_threshold)
    u8 fillerF4[0x2];
    u8 unkF6; // bit 0: the target has a reaction ready (battle_check_guard_or_cover), run by reaction_check
    u8 fillerF7[0x1];
    u8 unkF8; // 0 when battle_set_actor_side gets a team record (0-2), 3 for an opponent
    u8 unkF9; // skill shown by the action script command script_op_skill_anim_start: chosen part's data[1], or
              // Medaforce unkA8[0] + 0x50
    u8 fillerFA;
    u8 unkFB; // cleared by script_op_skill_anim_start
    u8 unkFC;
    u8 unkFD; // skill animation condition (battle_seq_cmd_test_*), picks battle_seq_cmd_branch's label
    u8 unkFE;
    u8 unkFF;      // bits 0 / 1 set by script_op_target_self with unk114[0] / unk114[1] = 0x28
    u16 unk100;    // battle sequence: offset of the current command in gBattleSeqScripts[unkF9] (cleared by
                   // script_op_skill_anim_start)
    s16 unk102[8]; // battle sequence: operands of the current command (battle_seq_load_operands)
    u8 unk112;     // set to 0x29 with unk113 (closeup_reset_text_states)
    u8 unk113;     // right close-up Medabot pose (unk112: left; bit 7 = finished, medabot_pose_anim_step)
    u8 unk114[2];  // per side (0 team, 1 opponents): passed to draw_medabot_sprite (repair_redraw_bot)
    u8 filler116[0x2];
    u8 unk118; // nonzero: restore_changed_part writes unk11C back into the acting Medabot's part
    u8 unk119; // part data[1] - 0x37 of the swapped part (change_transform_part)
    u8 unk11A; // id of the part swapped in (change_transform_part)
    u8 filler11B[0x1];
    struct BattlePart unk11C; // saved part (data and id), restored by restore_changed_part
    u8 filler134[0x8];
    struct Vec16 unk13C[6]; // per record: x, y - 4 of its battle sprite (copy_battle_entity_positions)
    u16 unk154;             // effect sprite x, y when unkF8 bit 1 is set (attack_hit_critical_spawn)
    u16 unk156;
    u16 unk158; // effect sprite x, y when unkF8 bit 1 is clear (attack_hit_critical_spawn)
    u16 unk15A;
    u8 unk15C[3]; // per Medapart select slot (unk82 - 1): nonzero skips the part sprite (target_marker_show)
    u8 unk15F;    // left Medabot pose finished (closeup_left_pose_step), polled by battle_seq_cmd_wait_pose
    u8 unk160;    // right Medabot pose finished (closeup_right_pose_step)
    u8 unk161;
    u8 unk162;
    u8 unk163;  // set by a gUnk_083AF000 step to run the next step in the same frame (battle_run_action_script)
    u8 unk164;  // nonzero: Medal skill levels can grow (increment_medal_skill_level)
    u8 unk165;  // set to 1 when a Medal skill levels up (action_phase_time_check then goes to sub-state 0x60)
    u8 unk166;  // skill type that levelled up
    u8 unk167;  // its new level
    u8 unk168;  // won Medapart: kind (0 head, 1 right arm, 2 left arm, 3 legs)
    u8 unk169;  // won Medapart: id
    u8 unk16A;  // won Medapart: 1 = not owned before
    u8 unk16B;  // Robattle: TIME ticks elapsed (robattle_time_tick)
    u16 unk16C; // battle score (calculate_battle_score_summary), then experience points
    // After-battle result per team member (u8 array: a struct would be 4-byte aligned):
    // [0] Medal id + 1, 0 = none (name from gMedalNames), [1] nonzero: Medal level-up screen,
    // [2]-[5] copied to gUnk_03000440.unk134-137, [6] nonzero: [7] = Medaforce id (gUnk_083B7338)
    u8 unk16E[3][8];
    u8 unk186; // after-battle screen: team member being shown (0-2, 3 = done)
    u8 unk187; // gUnk_03000590 record index (battle_loss_take_part)
    u8 unk188; // two rolls from gUnk_083AF200 (script_op_roll_dice_damage); unkEC = (unk188 + unk189) * 10
    u8 unk189;
    u8 partnerName[0x10]; // link Robattle: the partner's player name (link_robattle_exchange_names)
    // Link prize game (after a link Robattle, link/link_robattle.c):
    u8 prizeSlots[6]; // part type per row (4 = miss); = gPrizeGameSlots (prize_game_pick_slots)
    u8 prizePower;    // gauge 0-0x60, stopped with A
    u8 prizePeakY;    // ball's highest y (0x68 - prizePower, at least 12)
    u8 prizeRow;      // landing row 0-5 (prizePower >> 4, reversed)
    u8 prizeLandY;    // ball's landing y (prizeRow * 16 + 0x18)
    u8 prizeMedal;    // losing bot's record unk47 (prize_game_pick_prize_part)
    u8 prizePart;     // part id taken from it
    u16 unk1A6;
    u16 unk1A8;
    u16 unk1AA;
    u16 unk1AC;
    u8 unk1AE; // set to 1 when the screen wipe of closeup_enter_wipe is done
    u8 unk1AF;
    u8 unk1B0;
};

struct Unk_03000BE0 {
    u8 unk0;      // flags (0x40 tested by medal_trade_check_medal)
    u8 unk1;      // Medal graphic index (0x80-byte tiles at 0x084C21BC)
    u16 unk2;     // shown as "NEXT Lv" on the Medals list (render_medal_level_display; blank at level 100)
    u8 unk4;      // Attribute (gUnk_083B656C name, Ability page); Medals help: gUnk_083B69C8 message index
    u8 unk5;      // level (Medals help: Medaforce slots open at 10 / 30 / 60)
    u8 unk6;      // Aim skill type (gUnk_083B6EC8 name, Ability page); Medals help: gUnk_083B70AC message index
    u8 unk7;      // Compatibility icon (tile 0xD340 + unk7 * 4, Ability page)
    u8 unk8;      // Medal sprite variant, 0-4 (gUnk_083AC494[unk1][unk8])
    u8 unk9;      // number of unk18 entries in use (medal_rotation_draw_actions draws the rest greyed out)
    u8 unkA[0xE]; // name text
    u8 unk18[8];  // indexed by Medals screen unk46 (gUnk_083B825C message ids; guess: rotation entries)
    u8 unk20[8];  // 0-100 (guess: skill levels, drawn by render_medal_skill_stats)
    u8 unk28[8];  // per skill: filled bar tiles, 0-8 (draw_medal_skill_bars)
    u8 filler30[0xF];
    u8 unk3F; // Robattle: current unk18 entry (battle_bot_advance_rotation advances it, wraps at 8 to unk9)
};

// 256-byte records at gUnk_03000590 (6 of them, cleared together); each starts with a Medal record copy.
struct Unk_03000590 {
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
    u8 unkA8[6];                // chosen Medaforce: gUnk_083B7CD4 record (battle_bot_select_medaforce)
    u8 fillerAE[0x2];
    u8 unkB0[8]; // per skill type: times used this battle (count_bot_skill_use)
    u8 unkB8;    // own record index (battle_bots_load_parts)
    u8 unkB9; // raised by gUnk_03001800.unkEC up to 0x78 on the own side, lowered on the other (sub_0802C588, written
              // as &unkB8 + 1 to match)
    u8 unkBA; // nonzero: Medabot present (records 0-2 player team, 3-5 opponents)
    u8 moveDelay; // movement delay 0-0x1F, rebuilt each frame by bot_calc_move_delay; speed = 0x20 - moveDelay
    u8 unkBC; // hit flags, high nibble cleared by battle_action_cleanup: bit 4 dodged, bit 5 evaded onto the strongest
              // part, bit 6 hit above the threshold (attack_hit_check_critical)
    u8 unkBD; // flags (bit 2 toggled by the Robattle handlers robattle_action_finished /
              // robattle_bot_ready_for_command; set = facing away, which Destroy needs: destroy_check, message 0x19)
    u8 fillerBE;
    u8 unkBF;
    u8 unkC0; // flags (bit 1: traps don't spring on this Medabot, trap_hit_check)
    u8 unkC1; // Medaforce gauge, 0-80 (0x50: Medaforce ready, check_medaforce_availability; drawn as "MF nn/80",
              // runtime-checked)
    u8 fillerC2[0x2];
    // Two timed effects, ticked every 32 frames by battle_tick_timed_effects (battle_tick_buff_effect /
    // battle_tick_status_effect): type, part, frames left (-4 per tick; at 0 the effect ends and unkCE bit 0 / 1 is
    // set), amount.
    u8 unkC4; // effect A type (0x1F: restores armor to damaged parts, battle_tick_buff_effect)
    u8 unkC5;
    u8 unkC6;
    u8 unkC7;
    u8 unkC8; // number shown by the Robattle handler 0x70 (robattle_effect_a_number_init)
    u8 unkC9; // effect B type (0x13/0x14: armor changes each tick, battle_tick_status_effect; 0x2C checked by
              // robattle_bot_ready_for_command / process_bot_battle_turn, 0x2B by part_blocked_by_effect)
    u8 unkCA; // effect B part (compared by part_blocked_by_effect; find_burnable_part starts there)
    u8 unkCB;
    u8 unkCC;
    u8 unkCD; // number shown by the Robattle handler 0x78 (robattle_effect_b_number_init)
    u8 unkCE; // flags: bit 0 / bit 1 = sprites 0x46 / 0x47 + 3 * record shown (robattle_effect_a_end_init ..
              // robattle_effect_b_end_anim), bit 2 / bit 3 = numbers shown by robattle_effect_a_number_init /
              // robattle_effect_b_number_init
    u8 unkCF; // flags: bits 0/1/2/3 set by sub_08029354 (by gUnk_03001800.unk51)
    u8 unkD0;
    u8 unkD1; // raised by gUnk_03001800.unkEC up to 0xFF (sub_0802AC7C, written as &unkD0 + 1 to match)
    u8 unkD2;
    u8 unkD3;        // added to gUnk_03001800.unkEC for parts with data[2] 0 / 1 (script_op_calc_damage)
    u8 unkD4;        // added for data[2] 2 / 3 (script_op_calc_damage)
    u8 unkD5;        // added to gUnk_03001800.unkEC for unk28[side].unk5 (trap_apply)
    u8 unkD6;        // flags (bit 1: +10 damage, attack_hit_carry_over_retarget)
    u8 moveSubpixel; // movement: sub-pixel accumulator, + (0x20 - moveDelay) per frame, 1/16 px (battle_bot_move)
    u16 unkD8;       // cleared, then raised by gUnk_03001800.unkEC up to 0xFF (defence_apply)
    u8 moveStep;     // movement: whole pixels moved this frame
    u8 fillerDB;
    u8 unkDC;        // unkDC..unkE3 cleared by reset_battle_bot_state
    u8 chosenAction; // chosen command: 0 none, 1-3 head / right arm / left arm, 4+ Medaforce 0..; exchanged over the
                     // serial link in link Robattles (robattle_link_exchange_commands)
    u8 unkDE;        // copy of chosenAction (battle_action_cleanup)
    u8 unkDF;        // skill of the part chosenAction (1-3), 0 otherwise (battle_action_cleanup)
    u8 unkE0;
    u8 unkE1;
    u8 fillerE2[0x1E];
};

struct Unk_030017A0 {
    u8 unk0; // slot in use (> 1: has a Medal)
    u8 unk1; // guess: Medabot gender (compared with the Medapart gender unkF1 in count_compatible_medaparts)
    u8 unk2; // Medal id
    u8 unk3; // Medaparts: head, right arm, left arm, legs (validate_medapart_stats)
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
};

// Field scratch state; mostly the debug screen (field/field_debug), which draws its pages as hex
// sprites. Page labels come from the ROM strings: 0 "MP" (map), 1 "EVENT", 2 "PLAYER", 3 "MAP_EFFECT",
// 4 "KWG", 5 "KOMA", 6 "MESS", 7 "LV" (sound). text_bank / text_id are also used by map_script_update_message.
struct Unk_030057A0 {
    u8 unk0; // sound effect played by A on page 4
    u8 filler1[0xF];
    u8 unk10;
    u8 unk11;
    u8 effect_id;   // MAP_EFFECT page: field effect to start (0-0x1F)
    u8 next_sprite; // next free debug sprite slot (field_debug_draw_label)
    u8 page;        // debug screen page 0-7 (SELECT cycles)
    u8 frame;       // frame counter; bit 0x10 blinks the selected value (field_debug_draw_value_blink)
    s8 rows[8];     // selected row of each page (field_debug_cycle_row)
    u16 text_count; // MESS page: number of messages in the bank
    u16 unk20;      // KOMA page: sprite set previewed (field_debug_draw_sprite_preview)
    u8 filler22[0x2];
    u16 text_auto_next; // MESS page: A steps to the next message first
    u16 area_id;        // MP page: area to warp to
    u16 event_id;       // EVENT page: event number (event_flag_get / event_counter_get)
    u16 event_flag;
    u16 event_counter;
    u16 text_bank; // text bank (map script opcode 0x8x argument - 2)
    u16 text_id;   // text id
    u8 showing;    // MESS page: message on screen; KOMA page: preview drawn
    s8 song_id;    // LV page: BGM
    s8 sound_id;   // LV page: SE
};

// Per-area record list (gUnk_0840FAF4), ends at mask 0. A record applies when the player steps
// from a neighbouring tile onto (x, y) in a direction whose bit is set in mask.
struct MapExit {
    u8 x;
    u8 y;
    u8 mask;  // direction 0: 2, 1: 1, 2: 8, 3: 4
    u8 value; // returned by check_room_exit_at_position (0 = none)
};

// Map object record (64 at gUnk_030057E0.unk5DC).
struct MapObject {
    u8 x;
    u8 y;
    u16 unk2;      // bits 12-15: type (8 = event), bits 0-11: event id
    u8 unk4_0 : 5; // sprite slot (gSpriteEntries index - 49)
    u8 unk4_5 : 1;
    u8 unk4_6 : 1; // has a sprite (slot + 49, shadow slot + 91)
    u8 unk4_7 : 1; // animates at random
    u8 unk5;       // animation state
    u8 filler6[0x2];
};

struct Unk_030064A0 {
    u8 unk0;
    u8 unk1;
    u8 unk2[8];
    u8 unkA[8];
    u8 unk12[8][8];
    u8 unk52;
    u8 unk53;
    u8 unk54[8];
    u8 unk5C[8];
    u8 unk64; // choice menu step (yes_no_menu_poll: 0 setup, 1 wait handler, 2 poll)
    // Vehicle menu (vehicle_menu_load_gfx .. vehicle_menu_reload) reuses the area after the choice menu.
    u8 cursor; // selected entry (enum VehicleId)
    u8 unk66;
    u8 frame; // counter for the cursor wobble
    u8 filler68[0x4];
    u8 cursorX; // cursor tile x
    u8 cursorY; // cursor tile y
    u8 unk6E;
    u8 slideStep; // window slide-in progress (0..16)
    u8 textPage;  // page of the missing-parts message (0..5)
    u8 filler71;
    u16 savedBg[30 * 20]; // BG tilemap saved before leaving through the town map
};

// One sprite of the snapshot at gUnk_030057E0.unk7DC (4 bytes)
struct ScriptSpriteSave {
    u8 x; // tile
    u8 y;
    u8 id : 5;
    u8 unk2_5 : 1;
    u8 unk2_6 : 1;
    u8 active : 1;
    u8 anim; // (unk2B & 0xF) << 4 | facing
};

struct Unk_030057E0 {
    u8 filler0[0x5DC];
    struct MapObject unk5DC[64];
    struct ScriptSpriteSave unk7DC[8]; // sprite snapshot (save_script_sprites)
    u8 unk7FC;
    u8 unk7FD;
    u8 unk7FE; // area id
    u8 unk7FF;
    u16 unk800; // map width * 2 (tiles are bytes, unk810 rows are unk800 / 2 long)
    u16 unk802; // map height * 2
    u16 unk804; // area tilemap header words (field_tilemap_header_word(area, 0 / 1))
    u16 unk806;
    u8 filler808[0x8];
    u8 unk810[0x400]; // tile map
    u8 unkC10[0x8];   // tile value -> result of check_tile_and_trigger_battle_action
    u8 unkC18[0x8];   // saved copy of unkC10
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
    u16 map_origin_x; // screen offset of a map smaller than the screen (field_load_area_tiles)
    u16 map_origin_y;
    u8 unkC4C;
    u8 unkC4D;
    u8 unkC4E;
    u8 unkC4F;
    u8 fillerC50[0x2];
    u16 player_x;
    u16 player_y;
    u8 player_tile_x;
    u8 player_tile_y;
    u8 unkC58;
    u8 unkC59;
    u8 fillerC5A[0x1];
    u8 unkC5B;
    u8 player_form;        // 0 normal, 1-2 the vehicle menu forms, 3-8 / 0xD disguise items, 0xB / 0xC effect forms
    u8 useBlockFlags;      // set bits block: 0 disguises, 1 Mini S. Wheel, 2 Wings of Wind, 3 Periscope,
                           // 4 Silver Locket, 5 the town map
    u8 savedUseBlockFlags; // copy of useBlockFlags while a script blocks all but bit 5 (0xDF)
    u8 unkC5F;
    u8 unkC60;
    u8 fillerC61[0x6];
    u8 player_facing;
    u8 fillerC68[0x1];
    u8 saved_player_form; // the form to go back to after a temporary one
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
// legs) are loaded from the ROM templates gUnk_0807ECA0.. and saved per side in struct SpriteTree.
struct Unk_03005290 {
    u8 filler0[0xD];
    u8 unkD; // toggled between x and -2 - x (toggle_bg_layer_visibility)
    u8 fillerE[2];
    u8 unk10; // root node of the part's sprite tree (0 = hidden)
    u8 filler11[7];
};

// BG blend / brightness fade state, gBlendEffect (setup_blend_effect, blend_effect_update)
struct BlendEffectState {
    u8 mode;   // BLDCNT effect bits (0x40 alpha, 0x80 brighten, 0xC0 darken)
    u8 type;   // effect type 0..6 (4/5/6: EVA/EVB from current/16/start toward target)
    u8 status; // 1 = running, 2 = done
    u8 eva;    // current EVA / EVB / EVY, written to BLDALPHA / BLDY in VBlank
    u8 evb;
    u8 evy;
    u8 target_eva; // end values (types 4-6)
    u8 target_evb;
    u8 target_evy;
    u8 start_eva; // BLDALPHA read at setup (type 6)
    u8 start_evb;
    u8 fillerB;
    float eva_level; // accumulated levels (blend_set_alpha_12_10: 12.0, 10.0)
    float evb_level;
    float evy_level;
    float eva_step; // added per frame
    float evb_step;
    float evy_step;
    float fade_amount; // palette fade amount (setup_palette_fade_to_color)
    float fade_start;
    float fade_end;
    float fade_step;
};

// Affine parameters, gAffineParams[32] (calculate_oam_affine_matrix)
struct AffineParam {
    s16 scaleX;
    s16 scaleY;
    s16 angle;
    s16 pa, pb, pc, pd;
    u16 pad;
};

// Sprite animation script entry (advance_sprite_animation_frame)
struct SpriteAnimCmd {
    u16 cmd; // 0xFFFA..0xFFFF: commands, else a frame
    u16 arg;
    u16 duration;
    u16 frame;
};

struct SpriteAnimGfx {
    u8 unk0;
    u8 filler1[3];
    const void *src;
    void *dst;
    u8 fillerC[4];
};

// Sprite descriptor word (setup_oam_sprite_entries, init_sprite_object_entry).
struct SpriteDesc {
    u32 unk0_0 : 4;
    u32 shape : 2; // OAM shape / size bits (oam_shape_size_dims)
    u32 size : 2;
    u32 w : 4; // OAM entries per row / column (guess)
    u32 h : 4;
    u32 unk0_16 : 16;
};

// Bitfield view of struct OamData.
struct OamBits {
    u16 y : 8;
    u16 attr0_8 : 8;
    u16 x : 9;
    u16 attr1_9 : 7;
    u16 tileNum : 10;
    u16 priority : 2;
    u16 paletteNum : 4;
    u16 affineParam;
};

// Interpolated value stepped once per frame (anim_interp_init sets it up, animation_interpolation_step
// runs it; modes 0x10-0x17).
struct AnimInterp {
    float unk0; // current value
    float unk4; // base value
    u8 filler8[4];
    s32 unkC; // mode, 0 = idle
    float unk10;
    float unk14; // phase (sine table index)
    float unk18;
    float unk1C; // frame counter
    s32 unk20;   // start frame
    s32 unk24;   // end frame, 0xFFFF = none
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
struct BgTileEntry {
    u16 tile : 10;
    u16 hflip : 1;
    u16 vflip : 1;
    u16 pal : 4;
};

struct SpriteAnchor {
    u8 filler0[2];
    u16 unk2; // y / x offsets (move_sprite_object)
    u16 unk4;
    s8 unk6; // initial depth (init_sprite_object_entry)
};

// OAM entry list of a sprite object (copy_oam_entries_with_priority, init_sprite_object_entry).
struct SpriteOamList {
    struct OamData *oams;
    const struct SpriteAnchor *unk4;
    u16 depth; // > 300 / 200 / 100: OAM priority 3 / 2 / 1
    u8 w;
    u8 h;
};

// Full bitfield view of struct OamData (pret layout).
struct OamFull {
    u32 y : 8;
    u32 affineMode : 2;
    u32 objMode : 2;
    u32 mosaic : 1;
    u32 bpp : 1;
    u32 shape : 2;
    u32 x : 9;
    u32 matrixNum : 3;
    u32 hFlip : 1;
    u32 vFlip : 1;
    u32 size : 2;
    u16 tileNum : 10;
    u16 priority : 2;
    u16 paletteNum : 4;
    u16 affineParam;
};

// BIOS ObjAffineSet source / destination (pret syscall.h layout).
struct ObjAffineSrcData {
    s16 xScale;
    s16 yScale;
    u16 rotation;
};

struct ObjAffineDstData {
    s16 pa;
    s16 pb;
    s16 pc;
    s16 pd;
};

// Sprite node descriptor: one node (body part piece) of a sprite tree; OAM attributes (init_oam_sprite_entry).
struct SpriteNodeDesc {
    const u32 **frames; // per frame two entries: OBJ tiles (dma3_copy_or_decompress), palette (or NULL)
    s32 unk4;
    s32 unk8;
    s8 unkC;
    s8 unkD;
    s8 unkE;
    u8 sibling;    // next sibling node (0 = none)
    u8 child;      // first child node (0 = none)
    u8 paletteNum; // added to the palette argument
    u8 width;
    u8 height;
    u8 wDiv : 4; // width / height dividers (> 1: divide)
    u8 hDiv : 4;
    u8 bpp : 1;
    u8 affineMode : 2;
    u8 objMode : 2;
    u8 hFlip : 1;
    u8 vFlip : 1;
};

// Sprite tree node reference (load_sprite_tree_recursive); lists end with node == 0.
struct SpriteTileRef {
    u8 node : 6; // read with ldrb
    u32 frame : 8;
    u32 affine : 1; // draw with an affine matrix
    u32 alt : 1;    // frame + 1 on the alternate side; skipped by the tile copy loops
    u32 unk0_16 : 16;
};

// Per-node OAM entry and transform of a sprite tree (16 bytes).
struct SpriteNodeOam {
    struct OamFull oam;
    s16 unk8;
    s16 unkA;
    u16 unkC;
    u16 unkE;
};

// A list of OAM entry lists (batch_copy_oam_entries).
struct SpriteOamBatch {
    struct SpriteOamList **lists;
    u16 count;
};

// 16-byte record stepped by interpolate_entity_positions (unkC: angle-like, wraps at 0x10000).
struct InterpEnt {
    u8 filler0[8];
    s16 unk8;
    s16 unkA;
    s16 unkC;
    u8 fillerE[2];
};

// Candidate difference and its absolute value (interpolate_entity_positions).
struct InterpCand {
    s32 val;
    s32 abs;
};

struct Unk_03005310 {
    u8 unk0;
    u8 unk1;
    u8 filler2[0x2];
    u32 unk4;  // frame counter
    s16 unk8;  // affine pa (identity 0x100, bg2_affine_reset)
    s16 unkA;  // pb
    s16 unkC;  // pc
    s16 unkE;  // pd
    s32 unk10; // affine x
    s32 unk14; // affine y
    u16 unk18; // cleared with the gAffineParams affine params (affine_params_reset)
    u16 unk1A;
    u16 unk1C; // BG0 x scroll (new_game_init)
    u16 unk1E; // BG1-3 x scroll (area_load_graphics)
    u16 unk20;
    u16 unk22;
    u16 unk24; // BG0 y scroll
    u16 unk26; // BG1-3 y scroll
    u16 unk28;
    u16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 unk32; // 0x100 (bg2_affine_reset)
    s16 unk34; // 0x100
    u16 unk36; // 0-255, stepped by RIGHT / LEFT in debug_bg_scroll_input
    u8 unk38;
    u8 sceneResult; // result of the last battle / minigame: 1 won, 2 lost (map script branch sub_0804CB48)
};

struct Unk_03006D38 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4; // selected item id (item menu, item_menu_handle_input)
    u8 unk5;
    u8 unk6;
};

struct Unk_03005350 {
    s32 unk0;    // viewport width (240)
    s32 unk4;    // viewport height (160)
    s32 unk8;    // viewport centre x
    s32 unkC;    // viewport centre y
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
    float unk60[4]; // projected points x, y, z (field_effect_project_objects)
    float unk70[4];
    float unk80[4];
    float unk90; // yaw / pitch base angles
    float unk94;
    float unk98;
    s32 unk9C;       // camera distance
    s32 unkA0;       // projection scale
    double unkA4[2]; // camera origin x, y (field_effect_reset_view)
    s32 unkB4;       // projected screen x, y
    s32 unkB8;
    u8 fillerBC[0x4];
    s32 unkC0[4]; // model points x, y, z (from gUnk_083D2DB0)
    s32 unkD0[4];
    s32 unkE0[4];
    s32 unkF0;
    u8 fillerF4[0x4];
    s32 unkF8; // model set index into gUnk_083D2DB0
    u8 fillerFC[0xD0];
    s32 unk1CC; // current entity (index into gUnk_03006D30)
    s32 unk1D0; // part count of the current entity
    u32 unk1D4; // flags
    s32 unk1D8; // x, y, d (field_effect_start)
    s32 unk1DC;
    u32 unk1E0;
    u8 filler1E4[0x26];
    u16 unk20A; // palette colour masks (run_blend_fade_transition)
    u16 unk20C;
    u8 filler20E[0x6];
    s32 unk214;
    s32 unk218;
    s32 unk21C;
    s32 unk220;
};

// 3-D entity, 0x300 bytes; gUnk_03006D30 points to an array of them (0x02039000, 16 entries).
struct BattleEntity3D {
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
    u8 unk1F0;  // y min
    u8 filler1F1[3];
    u8 unk1F4; // y max
    u8 filler1F5[3];
    s32 unk1F8; // depth range check enabled
    s32 unk1FC; // depth min
    s32 unk200; // depth max
    u8 filler204[8];
    s32 unk20C; // current part
    u8 filler210[0xCC];
    u8 unk2DC[4];  // sprite slot per part
    u16 unk2E0[4]; // x offset per part
    u8 unk2E8[4];  // y offset per part
    u8 filler2EC[0x14];
};

// Table pointed to by the sound work area at 0x728: note -> sample/frequency entry.
struct SoundNoteTable {
    u16 count;
    u16 base;
    u32 unk4;
    u8 *entries[1]; // count entries
};

// Per-track configuration (gSoundTrackConfigs, one per SoundTrack).
struct SoundTrackConfig {
    u32 unk0;                               // -> SoundTrack.unkC
    void (*unk4)(struct SoundTrack *track); // -> SoundTrack.unk10
    u8 unk8;                                // -> SoundTrack.unk64
    u8 unk9;                                // ring buffer index (work+0x5EC), 0xFF = none
    u8 fillerA[2];
};

// Song / sound effect header (tables at gUnk_03007014->unk688 / unk68C).
struct SoundSongHeader {
    u16 trackMask; // bit 11 - i set: track i is used (0x800 = track 0)
    u8 priority;   // copied to SoundTrack.unk6D
    u8 unk3;
    u8 *tracks[1]; // one sequence pointer per set bit, in track order
};

// Sound driver work area (0x734 bytes, cleared by sound_engine_init).
struct Unk_03007014 {
    struct SoundTrack tracks[13];
    struct SoundTrack *unk5E4;
    u32 unk5E8;
    u8 unk5EC[3][0x34];              // SoundTrack.unk8 ring buffers (0x30 bytes + write index)
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

// Area warp record (gAreaWarps, one 0xFF-terminated list per area): stepping onto (x, y)
// moves the player to (destX, destY) of area.
struct AreaWarp {
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
struct AreaGfx {
    const void *unk0; // LZ77 BG tilemaps, decompressed to gFieldTilemapBuf (layers to 0x06003000 / 5000 / 7000)
    const void *unk4;
    const void *unk8;
};

// Sprite tree object (at 0x02026000): node descriptors, per-node OAM and the per-side part layers.
struct SpriteTree {
    u8 *unk0; // gSpriteWork record
    struct SpriteNodeDesc **nodes;
    struct SpriteNodeOam *oams;
    struct Unk_03005290 layers[2][4]; // part layers saved per side (setup_medabot_part_sprites)
};

// struct SpriteTree padded to the 0xD0 bytes build_medabot_sprite clears
struct SpriteTreePadded {
    struct SpriteTree o;
    u32 pad;
};

// 48-byte records at gUnk_03005308, one per side (setup_medabot_part_sprites).
struct SceneSlot {
    u8 filler0[4];
    u32 unk4;  // head part
    u32 unk8;  // right arm part
    u32 unkC;  // left arm part
    u32 unk10; // legs part
    u8 filler14[0x14];
    u32 unk28; // side
    u32 unk2C; // flags: 1 pending, 2 load, 4 loaded, 8 visible
};

// Menu / save screen work area, reached through the pointer gUnk_03006F74 (layout as used by code_0805AB40)
// One of 18 points placed on a hexagon (ring_points_place_on_hexagon) or a circle (ring_points_place_on_circle)
struct RingPoint {
    s16 unk0; // radius
    s16 unk2; // x
    s16 unk4; // y
    s16 unk6;
    s16 unk8; // radius * sin
    s16 unkA; // radius * cos
    u8 fillerC[4];
};

struct Unk_03006F74 {
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
    u8 unk2E; // Medal list: first visible row (medal_rename_draw_list)
    u8 unk2F; // Medal list: cursor row
    u8 unk30; // Medal list: number of entries in unkB0
    u8 unk31;
    u8 unk32;
    u8 unk33;
    u8 unk34;
    u8 filler35;
    u16 unk36; // save screen: last BG tile index loaded (save_screen_load_graphics)
    u16 unk38;
    s16 unk3A; // title: blend step (title_menu_blend_step)
    u16 unk3C;
    s16 unk3E;
    u16 unk40[4];
    u8 unk48;
    u8 unk49;
    u8 unk4A;
    u8 unk4B;
    u8 unk4C; // message pending (medal_rename_no_money)
    u8 filler4D[0x3];
    u8 unk50[8];    // blend effect state (init_blend_effect, blend_fade_step_08065598)
    u8 unk58[0x20]; // name text buffer (name_entry_fade_out_store_name copies it to the player or Medal name)
    u16 unk78;      // link: the other player's keys last frame (keys_update_from)
    s8 unk7A;
    s8 unk7B;     // link: both sides OK flag, 0 / -1 (fade_state_dispatch)
    s8 unk7C;     // link: both sides OK flag, 0 / -1 (fade_state_dispatch)
    s8 unk7D;     // length of the text at *unkAC (text_scroll_page_start)
    u8 unk7E;     // rings: random rotation mode (update_scene_animation_frame)
    u8 unk7F;     // sound_current_song result (link_start_init); song played by battle_cutscene_dispatch
    s16 unk80[3]; // rings: rotation angles x / y / z
    s8 unk86[3];  // rings: rotation speeds, clamped to +-16
    u8 filler89;
    u16 unk8A[4]; // race: per-sprite values set by text_scroll_init
    u16 unk92[4];
    u16 unk9A[4];
    u8 unkA2[5];
    u8 unkA7[5];
    const u8 *const *unkAC; // scene text (text_scroll_page_start)
    u8 unkB0[0x20];         // Medal list: Medal indices (medal_rename_build_list)
    struct RingPoint
        unkD0[18];    // points on a hexagon / circle (ring_points_place_on_hexagon, ring_points_place_on_circle)
    s32 unk1F0[4][4]; // 8.8 fixed-point 4x4 transform matrix (matrix_set_identity, matrix_rotate_xyz)
    struct Unk_03000BE0 unk230; // link: Medal record received from the other player (medal_trade_transfer)
    u8 unk270[0x30];            // message text buffer (shop_menu_greeting)
};

// BLDY fade state (init_blend_effect / blend_fade_step_08065598; Unk_03006F74.unk50)
struct BlendEffect {
    u16 mode; // BLDCNT effect bits (| 0x3F)
    u8 unk2;  // BLDY level
    u8 unk3;  // frames per step
    u8 unk4;  // frame counter
    s8 unk5;  // level change per step
};

// Item list built at 0x02040000 (an EWRAM mirror) by unpack_item_inventory_to_buffer, one per inventory slot
struct ItemListEntry {
    u16 id;
    u16 count; // 0: empty slot
};

// Shop sell list built at 0x02040000 by shop_build_sell_list, one per sellable Medapart
struct ShopSellEntry {
    u16 id;    // Medapart id
    u8 count;  // owned - equipped (MEDAPART_INV bytes 0 - 1)
    u8 unk3;   // part data byte 3 (gender)
    u32 price; // part data byte 0xB * 100
};

// Game flags byte at 0x03001784
struct Unk_03001784 {
    u32 unk0_0 : 1; // save_screen_poll_save_choice: next game state 13 instead of 6
    u32 unk0_1 : 1; // saved in SaveData.flags bit 5
    u32 unk0_2 : 30;
};

// Battery save image (0x1CBC bytes), built by serialize_save_data and read back by load_save_data
struct SaveData {
    u8 magic[16];                   // copied from gSaveMagic
    struct Unk_03002B70 unk10;      // gUnk_03002B70 (money, name, ...)
    struct Unk_03000BE0 medals[30]; // gUnk_03000BE0
    u16 medaparts[4 * 120 * 2];     // gMedapartInventory, one byte per halfword
    struct Unk_030017A0 team[9];    // gUnk_030017A0
    u8 items[64][2];                // gItemInventory
    u16 checksum;                   // byte sum of the whole image, computed with this field 0
    u8 fillerFF6[2];
    u8 field[0xCC0]; // gUnk_030057E0
    u8 flags;        // bits 0-1 gOptionTimeLimit, bit 2 gOptionSkipMessages, bits 3-4 gOptionBattleMusic, bit 5
                     // gUnk_03001784.unk0_1
    u8 filler1CB9[3];
};

// Race course backgrounds (init_battle_background_layers), by gUnk_03006FDC
struct Unk_08486160 {
    u8 unk0; // nonzero: fixed field gUnk_03006F84 = unk1 (else random, get_entity_speed_value)
    u8 unk1;
    s16 unk2; // encounter setup (gUnk_083C1A00) of the second racer (load_battle_sprite_graphics)
    u8 unk4;  // decompress_indexed_asset set for the BG at 0x06004800
    u8 filler5[1];
    s16 unk6; // encounter setup of the third racer
    u8 unk8;  // ... for the BG at 0x06005000
    u8 unk9;  // race intro message index: gUnk_084864E8[unk9], [unk9 + 1] (sub_08069F80)
    u8 fillerA[2];
};

// Field effect interpreter views (field_effect_run)
// Rotation track (entity +0xE8 yaw, +0x100 pitch).
struct SeqTrack {
    s32 active;
    s32 timer;
    s32 start;
    s32 end; // 0xFFFF = none
    float value;
    float step;
};

// Oscillator (entity +0x118 affine scale x, +0x13C scale y).
struct SeqOsc {
    s32 type; // 1 linear, 2 sine, 3 cosine, 4 done
    float value;
    float amp;
    float angle;
    s32 timer;
    s32 start;
    s32 end;
    float angleStep;
    u32 unk20;
};

// Linear ramp (entity +0x160 / +0x178 / +0x190 3-D scale x/y/z, +0x1A8 affine angle).
struct SeqRamp {
    s32 active;
    float value;
    float step;
    s32 timer;
    s32 start;
    s32 end;
};

struct SeqTimer {
    s32 active;
    s32 timer;
    s32 start;
    s32 end;
};

struct SeqEntity {
    s32 unk0;                // state
    s32 unk4;                // timer
    s32 unk8;                // start
    s32 unkC;                // end
    struct AnimInterp unk10; // x
    struct AnimInterp unk58; // y
    struct AnimInterp unkA0; // z
    struct SeqTrack unkE8;
    struct SeqTrack unk100;
    struct SeqOsc unk118;
    struct SeqOsc unk13C;
    struct SeqRamp unk160;
    struct SeqRamp unk178;
    struct SeqRamp unk190;
    struct SeqRamp unk1A8;
    struct SeqTimer unk1C0; // hide, then free the sprites
    struct SeqTimer unk1D0; // blink
    s32 unk1E0;
    s32 unk1E4;
    s32 unk1E8;
    s32 unk1EC;
    s32 unk1F0;
    s32 unk1F4;
    s32 unk1F8;
    s32 unk1FC;
    s32 unk200;
    s32 unk204; // palette
    s32 unk208; // animate sprites
    s32 unk20C;
    s32 unk210;      // part count
    s32 unk214;      // parent entity
    s32 unk218;      // has triggers
    s32 unk21C[16];  // trigger time
    s32 unk25C[16];  // trigger entity
    s32 *unk29C[16]; // trigger script
    u8 unk2DC[4];
    u16 unk2E0[4];
    u8 unk2E8[4];
    struct SeqTimer unk2EC;
    u32 unk2FC;
};

struct SeqState {
    u8 filler0[0x90];
    float unk90;
    float unk94;
    float unk98;
    s32 unk9C;
    s32 unkA0;
    u8 fillerA4[0x4C];
    s32 unkF0;       // running
    s32 unkF4;       // opcode
    s32 unkF8;       // script index
    s32 unkFC;       // pc
    s32 unk100[16];  // saved pc
    s32 unk140;      // call depth
    s32 *unk144[16]; // saved script
    s32 unk184;      // current entity
    s32 unk188[16];  // saved entity
    u8 filler1C8[0xC];
    u32 unk1D4;
    s32 unk1D8;
    s32 unk1DC;
    s32 unk1E0;
    u8 filler1E4[0x10];
    s32 unk1F4; // fade mode
    s32 unk1F8;
    s32 unk1FC; // fade timer
    s32 unk200;
    s32 unk204;
    u8 unk208;
    u8 filler209;
    u16 unk20A;
    u16 unk20C;
    u8 unk20E;
    u8 unk20F;
    u8 unk210;
    u8 filler211[3];
    s32 unk214;
    s32 unk218;
    s32 unk21C;
    s32 unk220;
    s32 unk224;
    s32 unk228;
    s32 unk22C;
    s32 unk230;
    s32 unk234;
    s32 unk238;
    s32 unk23C;
};

/* One 256-byte row of the link exchange buffers (0x03000590 / 0x03000890). */
struct LinkRow256 {
    u8 b[256];
};

// One OAM part of a sprite frame (frame tables gUnk_083ABE30 etc., read by check_flag_and_fast_copy).
struct SpritePart {
    u8 shape;
    u8 size;
    u16 tile;
    s16 x;
    s16 y;
};

struct SpriteFrame {
    u16 count;
    u16 pad;
    struct SpritePart parts[0];
};

// (object index, sort key) pair sorted by shell_sort_by_second_byte.
struct ObjSortEntry {
    u8 idx;
    u8 key;
    u16 pad;
};

// Per-area NPC records (gUnk_084837A0[area]), end at x == 0xFF.
struct MapNpcRecord {
    u8 x;
    u8 y;
    u16 unk2; // copied to MapObject.unk2 (type << 12 | event id)
    u8 unk4;  // bits 4-7: animation set, bits 0-3: animation state; 0xFF = no sprite
    u8 unk5;  // load order
    u16 unk6; // bit n: present when the story phase gUnk_030057E0.unk7FF == n
};

#endif // GUARD_STRUCTS_H
