#ifndef GUARD_STRUCTS_H
#define GUARD_STRUCTS_H

// Structures that are not understood yet. Fields are named by offset.

// Sound sequence track (sound_seq.c), 0x74 bytes; unk14 is the read pointer into the sequence data.
struct SoundTrack {
    struct SoundTrack *prev; // circular list of active tracks at gSoundWork->activeTracks
    struct SoundTrack *next;
    u8 *echoBuffer; // last 0x30 notes played (0xFF = silent), write index at echoBuffer[0x30]; NULL = no echo
    u32 onEnd;      // called by sound_track_stop (gSoundTrackConfigs)
    void (*tick)(struct SoundTrack *track); // per-frame envelope / vibrato / fade update
    u8 *seqPos;                             // sequence read position, NULL = track stopped
    u8 *loopPos;                            // 0xF0 / 0xF1 loop
    u8 *loop2Pos;                           // 0xF2 / 0xF3 loop
    u8 *returnPos;                          // 0xF5 call / 0xF6 return
    u8 *drumSeq;                            // noise channel: sub-sequence of the current drum
    u32 wait;                               // frames until the next sequence command
    u32 fixedLength;                        // note length for note mode 1 (0xE1)
    u32 drumWait;
    s32 vibratoStep;
    s32 vibratoOffset; // added to the frequency (>> 4)
    u32 fadeFrames;    // fade: frames left
    u16 fadeVolume;    // fade: current volume scale (0x1000 = full)
    u16 fadeTarget;    // fade: target volume scale
    s16 fadeStep;      // fade: step per frame
    u16 freq;          // PSG frequency register value
    u16 note;          // note / drum index, 0xFF = rest
    u16 outVolume;     // envVolume * fadeVolume, top 4 bits
    u16 markerCount;   // counts 0xEB markers
    u16 soundId;       // sound effect playing on the track, 0xFFFF = none
    u8 dirty;          // registers to rewrite: 1 freq, 2 volume, 4 duty, 8 sweep, 0x10 trigger, 0x20 wave, 0x40 pan
    u8 index;          // 0-3 music PSG 1-4, 4-7 sound effect PSG 1-4, 8/9 music FIFO A/B, 10/11 sound
                       // effect FIFO A/B, 12 music drums on the noise channel (follows track 9)
    u8 loopCount;
    u8 loop2Count;
    u8 sweep;        // SOUND1CNT_L (0xF7)
    u8 detune;       // added to the frequency (0xF8)
    u8 vibratoDelay; // 0xF9: frames before the vibrato starts
    u8 vibratoPeriod;
    u8 vibratoDepth; // in units of 2 semitones / period, 0 = off
    u8 vibratoWait;
    u8 vibratoCounter;
    u8 envAttack;    // high nibble: frames per step, low nibble: volume step
    u8 envDecay;     // same layout as envAttack
    u8 envReleaseAt; // release starts when this many frames of the note remain
    u8 envRelease;   // high nibble: frames per step, low nibble: steps
    u8 envCounter;   // frames until the next envelope step
    s8 envStep;      // volume change per step / steps left in release
    u8 envPhase;     // 0 off, 1 key-on delay, 2 attack, 3 decay, 4 sustain, 5 release
    u8 envEnabled;
    u8 noteMode;    // 0xFE: 0 notes, 1 raw frequencies, 2 drum kit
    u8 channelType; // 0 square 1, 1 square 2, 2 wave, 3 noise, 4 FIFO A, 5 FIFO B
    u8 volume;
    u8 envVolume;  // current envelope volume (0..15)
    u8 instrument; // duty bits (PSG), wave pattern (wave), sample index (FIFO)
    u8 unk68;
    u8 noiseParams; // SOUND4CNT_H low byte (0xE2)
    u8 transpose;   // 0xE8, signed
    u8 echoDelay;   // 0xE9: frames back in echoBuffer the echo note is taken from, 0 = off
    u8 echoNote;    // last echo note written
    u8 priority;    // from SoundSongHeader.priority
    u8 lengthHigh;  // 0xFA: high byte of the next note length
    u8 pan;         // 0xEA: 0 off, 1, 2, 3 both
    u8 panOverride; // set by play_song_panned / play_sound_effect_panned, 0 = use pan
    u8 filler71[0x3];
};

// Header of a Direct Sound sample (pointed to by SoundMixChannel.unk0).
struct SoundSampleHeader {
    u32 length;  // in bytes
    u16 rate;    // playback rate at baseNote
    u8 fineTune; // 1/128 semitones
    u8 baseNote;
    u32 flags; // bit 0: loop
    u32 loopStart;
    s8 data[1]; // 8-bit PCM
};

// Direct Sound channel (FIFO A / B) state, 0x48 bytes, two of them in the sound work area.
struct SoundMixChannel {
    u32 sample;      // struct SoundSampleHeader *, 0 = idle
    u32 rate;        // playback rate
    u32 position;    // bytes of the sample streamed so far
    u32 flags;       // 1 paused, 2 rate changed, 4 output changed
    u32 timerReload; // TMxCNT value
    u32 rateOffset;  // vibrato
    u32 track;       // struct SoundTrack * that queued the note
    u32 queuedSample;
    u32 queuedRatio;
    u32 queuedNote;
    u32 queuedVolume;
    u32 queuedLength;
    u8 queuedPan;
    u8 queuedPanOverride;
    u8 filler32[0x2];
    u16 length; // note length in frames
    u16 elapsed;
    u16 pendingFrames; // frames counted by sound_mix_tick since the last refill
    u8 fifo;           // 1 = FIFO A, 2 = FIFO B
    u8 note;
    u8 volume; // 0..15
    u8 filler3D[0x1];
    u8 request; // for sound_mix_run_request: 1 start note, 2 start at rate, 3 stop, 4 pause, 5 resume
    u8 pan;
    u8 panOverride;
    u8 filler41[0x3];
    u32 idleFrames; // counts frames while no sample is set
};

// Work area of the running map script command (gScriptCmdWork, 16 bytes, cleared when a script ends).
struct ScriptCmdWork {
    u8 counter;      // frames / steps left (blink, walk-in-place state, step countdown)
    u8 blink_phase;  // odd = sprite hidden (script_sprite_blink_step)
    u8 timer;        // frames until the next blink toggle / walk animation frames left
    u8 timer_reload; // blink toggle period
    u8 filler4[0x4];
    u16 hop_base_y;     // base y of a sprite hop (script_sprite_hop_step)
    u8 sprite_slot;     // sprite the command moves (gSpriteEntries index: map object + 49, script object + 79)
    u8 transition_step; // step of scene_state_dispatch (fade out of the field into another mode)
    u8 mode_result;     // result code of a mode left from a script (field_resume: 7 / 8), read by
                        // map_script_update_link_start (7 = go on)
    u8 fillerD[0x3];
};

// 0x03001800 while game mode 3 (boot logos / story intro, code_0806B160) runs; the same RAM as gBattleWork.
struct SceneWork {
    u16 nextMode; // gGameMode / gGameState / gGameSubState to go to when the scene ends
    u16 nextState;
    u16 nextSubState;
    u16 unk6;
    s32 timer;             // frame counter of the current step
    union {                // 4 bytes: agbcc pads unions to a word
        u16 h;             // story intro: page (graphics gStoryIntroTiles / text gStoryIntroTexts)
        u16 afterSubState; // opening intro: sub-state to run after the next silhouette / scan step
        u8 b;              // boot logos: nonzero once START may skip them (boot_logos_check_skip)
        s8 s[4];           // bomb minigame: roundBombs / dropInterval / bombsLeft (struct BombGameWork)
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
// gBattleWork (bomb_game_init sets the first three counters through SceneWork.unkC).
struct BombGameWork {
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
// as gBattleWork.
struct MedabotsWeeklyWork {
    u16 unk0; // next mode? (cf. SceneWork.nextMode)
    u16 unk2; // next state?
    u8 filler4[8];
    u8 scrollBg3;  // nonzero: scroll BG3 every other frame (weekly_scroll_bg3)
    u8 animTiles;  // nonzero: animate BG tiles (weekly_update_studio)
    u8 tileFrame;  // tile animation frame 0..5 (every 4 frames)
    u8 tileFrame2; // tile animation frame 0..5 (every 16 frames)
    u8 filler10[4];
};

// One step of a sprite animation (gRaceSpriteAnims).
struct SpriteAnimFrame {
    u16 frame;    // copied to the sprite's unk6
    s16 duration; // frames
    u8 next;      // index of the next step
    u8 filler5[3];
};

// 0x03002B70 (gPlayerRecord): what the save screen shows and the save file keeps in its header.
struct PlayerRecord {
    u32 money;             // in cents ($0.20 = 20), capped at 99999 (add_money)
    u8 name[16];           // player name, 0xFE-terminated (validate_save_data rejects an empty one)
    u16 robattleCounts[2]; // gRobattleCounts: [0] Robattles fought, [1] won (save screen WINS / TOTAL); <= 9999
    u32 playTime;          // play time in frames (save screen GAME TIME = / 3600 min); < 0x014996FF (100 hours)
};

// Tile animation slot at gGameWork.tileAnims (tile_anim_init / tile_anim_run): each script step copies
// frameTiles tiles of frame N from the EWRAM sheet (at tile sheetTile) to OBJ tile objTile.
struct TileAnim {
    u8 wait;        // frames left on the current step
    u8 pos;         // script index (u16 units; starts at 2, after the x/y header)
    u8 state;       // 0xFF once the script has ended
    u8 objTile;     // destination OBJ tile
    u16 sheetTile;  // first tile of the sheet in EWRAM
    u16 frameTiles; // tiles per frame
};

// Graphics list entry (gGfxLists lists, end at size 0): size in 32-byte tiles, gGfxListData index.
struct GfxListEntry {
    u16 size;
    u16 index;
};

struct GameWork {
    u8 msgKeepPalettes; // message window: 0 = dim the palettes while open (text_window_init args a, b, c)
    u8 portraitMode;    // portrait mode: 0 = animated, 1 = static, 2 = none
    u8 noWindowFrame;   // 1 = no window frame
    u8 filler3;
    u8 msgState; // message handler state (run_message)
    u8 filler5[0x3];
    const u8 *msgText;    // current message (run_message)
    u16 msgPos;           // read position in msgText
    u8 portraitAnimFrame; // portrait open / close animation frame 0-8 (message_portrait_anim_step)
    u8 portraitSide;      // portrait: shown animation / side (0 = right)
    s8 portraitSet;       // portrait: sprite set (-1 = none)
    s8 portraitIndex;     // portrait: index
    u8 portraitShown;     // 1 = a portrait is shown
    u8 msgStopPrint;      // 1 = stop printing this frame (message_print_step)
    u8 penX;              // text pen x in pixels
    u8 wordPixelsLeft;    // pixels left in the current word
    u8 composePixels;     // pixels filled in gTextComposeTile
    u8 textLine;          // text line 0-1
    u8 wordFits;          // 1 = the current word has been measured and fits
    u8 lineFull;          // 1 = line full, 2 = page full (wait for A / B)
    u8 msgWait;           // wait counter (0xF7 / 0xFA codes)
    u8 endModeStep;       // end mode step
    u8 dimLevel;          // palette dim level 0-9
    u8 filler1D[0x3];
    u8 *varText;         // string being drawn (message name / number buffers, message_print_var_step)
    u8 varPos;           // read position in varText
    u8 cursorBlink;      // page cursor blink timer
    u8 frameAnimStep;    // window frame animation step
    u8 altFont;          // 1 = alternate font (0xF8 code)
    u8 choiceResult;     // choice menu result: (choiceCursor << 4) + 1 once A is pressed, 0 while open
    u8 choiceState;      // choice menu state (poll_choice_menu)
    u8 choiceCursor;     // choice menu cursor: 0 = first (yes) row
    u8 scrollSpriteSlot; // sprite slot (advance_sprite_scroll_animation)
    u8 transTileX;       // tilemap x (copy_transition_tiles_to_bg2)
    u8 transTileY;       // tilemap y
    u8 filler2E[0x2];
    u8 debugReturnState;    // game state to return to from game state 63 (debug_menu_exit)
    u8 debugReturnSubState; // its sub-state
    u8 debugCursor;         // game state 63 menu cursor, 0-10 (debug_menu_select_input)
    u8 debugSubState;       // game state 63 submenu sub-state
    u8 debugRow;            // game state 63 submenu row
    u8 debugValues[3];      // game state 63 submenu values, one per row
    u8 filler38;
    u8 debugMotion; // game state 63 "Motion" entry: scene / animation id 0-0x79 (START / SELECT)
    u8 filler3A[0x2];
    u8 openedFrom;     // where the Medals / Medaparts screen was opened from: 0 Medawatch, 1 Medabot detail
                       // (medabot_detail_open_info), 2/4 others; Robattle status screen: side shown (shownId: member)
    u8 shownId;        // Medal / Medapart id to show
    u8 partSlot;       // Medapart slot 0-3
    u8 listTab;        // Medals list / Medaparts list: tab (6 entries per tab); robattle / prebattle: a step counter
    u8 medalRow;       // Medals list: row
    u8 freeMedalCount; // count of owned, unequipped Medals (count_unequipped_medals)
    u8 medalPage;      // Medal pages: 0 Ability, 1 Medaforce, 2 Rotation, 3 Skill (L/R, runtime-checked)
    u8 helpFromPage;   // Medal pages: help opened from 0 Ability, 1 Medaforce
    u8 helpPage;       // Medals help: page cursor
    u8 helpPageCount;  // Medals help: page count
    u8 pageCursor;     // Medal pages: row / slot cursor (Medaforce entry, Rotation slot; | 0x80 while editing);
                       // Robattle status screen: highlighted member
    u8 filler47;
    u16 subCounter;       // pre-battle wipe column counter; Medals: skill debug row 0-7 (medal_skill_debug_edit_input),
                          // Medal transform frame counter
    u8 tradeChoice;       // Medals: choice from medal_trade_choice_input (0 A, 2 B)
    u8 medalsSongStarted; // Medals screen: song 7 started (when opened with openedFrom == 4)
    u8 filler4C[0x4];
    u8 medabotsMode; // Medabots screen mode: 0 plain (from the Medawatch), 1-3 team select (guess: battle type; 3 needs
                     // all three picks)
    u8 medabotsCursor; // Medabots screen: cursor slot (0-8)
    u8 reorderPick;    // Medabots screen: reorder pick, slot | 0x80 while holding
    u8 detailInvalid;  // Medabot detail: the edited set fails validate_medapart_stats (icon shown in palette 8)
    u8 filler54[0x2];
    u8 enteredFromSubmenu; // game state 3: 0 = entered from the field (fades from the backup palette), 1 = from a
                           // submenu
    u8 filler57[0x3];
    u8 detailRow; // Medabot detail: row cursor, 0 Medal, 1-4 head / right arm / left arm / legs (runtime-checked)
    u8 filler5B;
    u16 timer;    // timer
    u8 detailBot; // Medabot detail: which Medabot is shown, L/R toggle (runtime-checked)
    u8 filler5F[0x5];
    struct TileAnim tileAnims[4];
    u8 stepCounter;     // general per-step frame / animation counter (mosaic level, blend level, menu row, tile row...)
    u8 repeatCounter;   // pre-battle mosaic repeat count; portrait test: reverse the animation
    u16 stepTimer;      // general step timer: waits (60 frames...) counted down or up; link exchange frame
                        // counter; the current wave x offset of start_scanline_wave_scroll
    u8 menuRowAnim;     // field menu: row animation counter
    u8 skipBotSetup;    // Robattle: 1 skips the bot setup in robattle_setup_bots
    u16 rngSeed;        // rng seed (rng_next_byte)
    u8 rngLast;         // last rng_next_byte value
    u8 rngIndex;        // rng table index when skipBotSetup is set
    u8 fieldMenuCursor; // field menu cursor: 0 Medawatch, 1 Item, 2 Vehicle, 3 Save (runtime-checked)
    u8 medawatchCursor; // Medawatch menu cursor (0..2)
    u8 blendMode;       // blend effect mode 1-6 (set_blend_effect_mode): odd fades the blend in, even out
    u8 filler91;
    u16 blendSpeed;     // blend effect speed, added to blendProgress every frame
    u16 blendProgress;  // blend effect progress (done at 0x100)
    u8 noAffineSprites; // set: the Medabot sprite builder (sprite_engine) turns affine mode off for the parts
    u8 shownMedal; // shown Medabot: Medal slot (0x1E none), then shownHead-9B its four Medaparts (>= 120 none); the
                   // detail screen's edit copy (medabot_detail_take_apart / assign_medal_to_team_slot)
    u8 shownHead;
    u8 shownRightArm;
    u8 shownLeftArm;
    u8 shownLegs;
    u8 battleResult; // Robattle result: 0 undecided, 1 won (song 14, counts gRobattleCounts[1]), 2 lost
    u8 filler9D;
    u8 textBuf[0x50]; // digit buffer (divide_by_10000); also four 0x14-byte name buffers for messages
                      // (message_print_var_step)
    u8 partAbility;   // start of a 16-byte part data record (load_part_data): ability (gAttributeNames name)
    u8 partSkill;     // skill id; >= 100: leg type (gLegTypeNames[partSkill - 100])
    u8 partSkillType; // skill type (gSkillTypeNames name)
    u8 partGender;    // gender: 0 male, 1 female (matched against gTeamSlots[].portraitMode)
    u8 partStat0;     // stats: head Armor, Success, Power, (partStat3 power icon flag), Uses; legs Armor, Propulsion,
    u8 partStat1;     // Evasion, Defense, Proximity, Remoteness (runtime-checked on the detail page). Medal record:
    u8 partStat2;     // partStat0-2 tier thresholds (medal_tier_for_level), partStat3 compatibility,
    u8 partStat3;     // partStat4 / partStat5 / fillerF8[0] skill level step per 10 levels (medal_add_by_id)
    u8 partStat4;
    u8 partStat5;
    u8 fillerF8[0x16];
    u8 medalGfxRecord[0x10]; // 16-byte record from gMedalRecords (per Medal graphic index)
    u8 filler11E[0x10];
    u8 oamUploadPending;  // set: copy gOamBuffer to OAM at the next vblank
    u8 runningSpriteSlot; // sprite slot whose handler is running (also gEffectSpriteSlot;
                          // medaforce_cancel_status_emblem_rise)
    u8 inCloseup;         // Robattle: set to 1 around the action script commands script_op_closeup_enter ..
                          // script_op_closeup_exit
    u8 skipOamHigh;       // set: vblank_body skips the OAM 88-127 upload in mode 2
    u8 battleOver;        // set when the Robattle is left (action_phase_exit), cleared when an encounter loads
    u8 levelUpMedalSlot;  // after-battle Medal level-up: Medal slot (find_medal_slot_by_id - 1)
    u8 transformOldMedal; // Medal transform after a level-up: old graphic / sprite variant, new ones
    u8 transformOldVariant;
    u8 transformNewMedal;
    u8 transformNewVariant;
    u8 prizeGamePending; // nonzero: link_robattle_check_prize_game jumps to sub-state 0x30
    u8 setupStep;        // game state 3 setup step (medabots_screen_load_gfx); Robattle setup step
    u8 gfxLoadStep;      // battle_load_graphics_step: step 0-8
};

// One of the 128 hardware sprite objects (gSpriteEntries); build_sprite_oam turns the enabled ones into OAM
// each frame. Bytes 0x1A and 0x20-0x3F are per-module work space (animation counters, angles, timers...).
struct SpriteEntry {
    u16 flags;          // SPRITE_FLAG_*: enabled, visible, flips, OBJ priority (bits 10-11), affine, position mode
    s16 x;              // screen x (written by build_sprite_oam in the world / perspective position modes)
    s16 y;              // screen y
    u16 frame;          // frame set (high byte) and frame (low byte) in the frame_table tables
    u8 scale_x;         // affine scale, 0x40 = 1.0
    u8 scale_y;         // affine scale, 0x40 = 1.0
    u8 palette;         // OBJ palette (attribute 2 bits 12-15)
    u8 order;           // draw order: entries are sorted by it, lowest first
    u32 pos_x_frac : 8; // world x, 24.8 fixed point: fraction
    s32 pos_x : 24;     // integer part
    u32 pos_y_frac : 8; // world y, 24.8 fixed point
    s32 pos_y : 24;
    u32 pos_z_frac : 8; // world z / depth, 24.8 fixed point
    s32 pos_z : 24;
    u16 angle; // affine rotation, 1024 steps per turn
    u16 unk1A;
    u8 frame_table; // low nibble: 0 gSpriteFrameSets, 1 gSpriteFrameSets1, 2 gMenuSpriteFrameSets, 3 gSpriteFrameSets3
    u8 affine_idx;  // shared affine matrix (SPRITE_POS_SHARED_AFFINE mode)
    u8 filler1E[0x2];
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
    u8 unk2F; // field: added to the frames of animation command 0xFFFA (advance_sprite_animation_frame)
    u16 unk30;
    u16 unk32;
    u16 unk34; // frame target unk1A counts up to (weekly_set_sprite_effect)
    u8 filler36[0x4];
    u16 unk3A; // previous frame's unk1A (race_update_runners)
    u8 filler3C[0x4];
};

// Per-sprite entity state (gEntityStates, one per gSpriteEntries slot, 0x200 bytes).
struct EntityState {
    u16 active; // non-zero (0xFFFF) while the slot holds a field entity; drawn by update_entity_sprites_on_screen
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

// Per-frame link packet exchange (main loop: serial_link_init_and_status fills recv, serial_prepare_send_packet
// sends sendKeys + sendData). Each packet is { keys, data }; data carries the menus' 0xFFxx / 0xFExx commands.
struct LinkPackets {
    u32 status;     // bits 0-3: packet received from player i; 0x80 parent; bits 8-11 connected players
    u16 sendKeys;   // word 0 of the packet we send (held keys in menus)
    s16 sendData;   // word 1: command / value for the other side
    u16 recv[4][2]; // received packets, [player][0 keys, 1 data]
    u8 filler18;
    s8 recvTimeouts[4]; // frames since player i's last packet (dropped after 10)
    u8 playerJoined;    // 0xFF on the frame a player connects
    u8 linkLost;        // 0xFF on the frame a player drops or the send stalls
};

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

// A 3-byte ROM table copied to the stack as a whole (race_refresh_runner_sprite).
struct ByteTable3 {
    u8 b[3];
};

// Bitfield view of gGameWork.penX (text pen x): the text tile flush code tests the pixel offset in
// the current 8-pixel tile through it, which reloads unk14 (message_new_line and friends).
struct TextColBits {
    u8 filler0[0x14];
    u8 col : 3;
    u8 hi : 5;
};

// Struct view of the gUiTilemaps tilemap pointer table: the Robattle screen wipes read entry 0x69 as a
// field (base + 0x1A4, reloaded after each call: closeup_enter_wipe, closeup_exit_wipe).
struct UiTilemapTable {
    const void *unk0[0x49];
    const void *more_cursor_off; // message "more text" cursor, blink off (message_wait_next_page)
    const void *more_cursor_on;  // message cursor, blink on
    const void *unk12C[0x1E];
    const void *blank_row; // blank tilemap row
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

// Opponent Medabot in an encounter setup (gBattleWork.encounterBots).
struct EncounterBot {
    u8 parts[4]; // head, right arm, left arm, legs part ids
    u8 unk4;     // Medal (gMedalRecords record; init_enemy_bot_medal)
    u8 unk5;     // Medal level
    u8 unk6[4];  // two 4-bit Medal record unk18 entries per byte
    u8 unkA;     // Medal record unk9
    u8 fillerB;
};

// BG scroll offsets: gBg0Scroll..gBg3Scroll, added to gBgScrollOffset and written to BGxHOFS/VOFS by vblank_body.
struct Vec16 {
    s16 x;
    s16 y;
};

// Battle Medapart record (0x18 bytes, 4 per gBattleBots record from +0x48; battle_bots_load_parts).
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
    u8 data[0xD]; // part data record (load_part_data): [1] skill id (SKILL_*), [2] skill type (SKILL_TYPE_*),
                  // [4] max armor; data[0xA] summed as armor (accumulate_team_armor_stats)
    u8 fillerD;
    u8 aiTargetBot;  // AI target record + 1, copied to the record's targetBot / targetPart when this part is chosen
                     // (battle_bot_select_part)
    u8 aiTargetPart; // AI target part + 1 (0 = whole Medabot, ai_clear_target_part)
    u8 headUses;     // head: copy of data[8], uses left (head_out_of_uses; Use Drain needs it nonzero)
    u8 armor;        // current armor, starts as data[4] = max armor (Status screen, runtime-checked); 0 = broken
    // Legs only: data[5..9] copied here, restored by bot_restore_leg_stats, halved by bot_halve_broken_leg_stats
    // when the legs break. Names follow the Medabots leg stats (propulsion, mobility, defence, proximity, remoteness).
    u8 propulsion; // movement speed (bot_move_delay_sub_propulsion), turn order (battle_queue_add), half added to
                   // charge damage (script_op_calc_damage) and trap wear (trap_hit_wear)
    u8 evasion;    // added to gBattleWork.evasion for a dodge check (battle_calculate_turn_speed)
    u8 defence;    // added to gBattleWork.evasion for the "hit taken on the strongest part" check
                   // (battle_process_speed_and_action)
    u8 proximity;  // success bonus for melee skill types (calc_battle_action_speed)
    u8 remoteness; // success bonus for ranged skill types (calc_battle_action_speed)
    u8 partId;     // part id (battle_bots_load_parts)
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

// Per-side record at gBattleWork.traps (0 team, 1 opponents).
struct BattleSideTrap {
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

struct BattleWork {
    u8 encounterMessage; // encounter: opponent message index (gOpponentPreBattleMessages)
    u8 rubberoboReward;  // encounter: nonzero, the opponent also hands over a Rubberobo Medal
                         // (afterbattle_check_rubberobo_reward)
    u8 opponentCount;    // opponent Medabot count
    u8 fixedParts;       // nonzero: fixed opponent parts (else each part is re-rolled by random_pick_weighted4)
    struct EncounterBot encounterBots[3];
    struct BattleSideTrap traps[2]; // per side (0 team, 1 opponents)
    u8 battlefield;                 // battlefield
    u8 battlefieldParams[8];        // copied from gBattlefieldParams[battlefield] (battlefield_load_params)
    u8 teamPicks[3];                // team select picks: 0x10 | Medabots screen slot, 0 = empty (runtime-checked)
    u8 autoCommandBits;             // Robattle: bit (1 << team Medabot) set by robattle_command_auto
    u8 actionQueue[6][2];           // Robattle action queue: record + 1 (0 = free), priority = legs Propulsion
                          // (battle_queue_add, sorted by battle_queue_sort; robattle_turn_next_action tests [0][0])
    u8 unk51; // Robattle: Medaforce gauge points left to add / remove one per frame (medaforce_gauge_fill_step /
              // _drain_step)
              // also the AI result: 1 = skill unusable (gAiActionChecks, ai_action_unusable)
    u8 unk52;
    u8 unk53;
    u8 linkRecvPos;      // link exchange: byte position in the record being received (team_select_link_exchange_bots)
    u8 resultFlags;      // Robattle: result flags (2, 4, 8, 0x10 pick sub-states 0x60-0x78 in robattle_turn_loop)
    u8 timeFrame;        // Robattle: frame counter, mod 32 (robattle_time_tick)
    u8 timeLeft;         // Robattle: TIME left, 40/30/20 by gOptionTimeLimit (robattle_time_init), -1 every 32 frames
                         // (robattle_time_tick)
    u8 medaforceBlocked; // Robattle: nonzero blocks Medaforce (check_medaforce_availability)
    u8 effectAmountLeft; // Robattle: effect amount left to apply (battle_tick_buff_effect / battle_tick_status_effect)
    u8 teamCount;        // Robattle: team Medabot count (3 in battle_start.ss0)
    u8 loadedOpponents;  // opponent Medabots to load (count_active_battle_bots; link: team_select_link_load_opponents)
    u8 aiBot;            // Robattle AI: record choosing its action (ai_pick_bot_targets)
    u8 aiPart;           // Robattle AI: part being considered (0-2)
    u8 aiTarget;         // Robattle AI: target record + 1
    u8 aiTargetPart;     // Robattle AI: target part + 1
    u8 targetSideFirst;  // first record of the target side (battle_enemy_side_first_record, medaforce_side_bolt_calc)
    u8 aiCandidates[3];  // Robattle AI: candidate targets (record + 1, 0 = none; ai_target_attack)
    u8 partIds[4]; // scratch: a Medabot's 4 shown part ids (get_bot_part_effective_values, for draw_medabot_sprite);
                   // also the AI part order (gAiPartOrders, battle_ai_roll_part_order) and a saved actor
                   // (interrupt_skills)
    u8 filler68[0xC];
    u8 battlefieldEffect[8]; // copied from gBattlefieldEffectParams[battlefield] (load_battle_script_entry_b): BG
                             // scroll movement; [3] nonzero: [4] << 8 | [5] -> REG_BLDALPHA
    u8 fieldAnimFrame;       // battlefield animation frame, 0-0x7F (advance_battle_animation_frame)
    u8 fieldAnimTick;        // battlefield animation tick, 0-2
    u8 fieldAnimTiles;       // battlefield animation tile count / 8 (gBattlefieldAnimTileCounts)
    u8 fieldAnimBlock;       // battlefield animation tile block (gBattlefieldAnimFrames), 0xFF ends the loop
    u8 commandBot;      // Robattle: team Medabot (record) whose command is being chosen (command ring, part / Medaforce
                        // select); also the record medal_rotation_store_to_battle_bot writes
    u8 ringSlot;        // Robattle: selected command ring slot 0-5 (name gCommandRingNames[ringSlot], runtime-checked)
    u8 partCursor;      // part / Medaforce select cursor: 0 none, 1 head, 2 right arm, 3 left arm (part_select_input)
    u8 ringTurning;     // Robattle: command ring turning, 1 right / 2 left (command_ring_input); nonzero blocks
                        // robattle_command_input
    u8 battleStarted;   // set by robattle_start_banner_init: the first command round is over (B no longer goes back to
                        // the previous Medabot)
    u8 gaugeBlinkTimer; // frame counter: the panel blinks while the Medaforce gauge is full (mf_gauge_full_blink_panel)
    u8 effectAmountTotal; // amount applied over all parts by battle_tick_buff_effect / battle_tick_status_effect (shown
                          // number)
    u8 actor;             // Robattle: gBattleBots record of the acting Medabot
    u8 target;
    u8 actorSide; // Robattle: side of the acting Medabot (actor / 3: 0 team, 1 opponents)
    u8 otherSide; // Robattle: the other side (actorSide ^ 1)
    u8 targetPart;
    u8 raceLegTypes[3]; // race: team legs types (team_select_exit_race -> race_load_teams)
    u8 raceParts[3][4]; // race: per team member, gTeamSlots head / right arm / left arm / legs
    u8 filler9B;
    u8 substep[5];     // [0] step of miss_popup_run / target_panels_show, [1] timer / argument, [2] done
                       // (battle_substeps_reset)
    u8 messageStep[5]; // [0] step of battle_message_show, [1] message id (battle_message_reset)
    u8 messageId;      // battle message id (gBattleMessages) shown by effect_step_show_message; also the next handler
    u8 actorPart;      // Robattle: part index (0-3) of the acting Medabot that savedPart is written back to
                       // (restore_changed_part)
    u8 actorSkill; // Robattle: skill id (data[1]) of the acting Medabot's chosen part (action_phase_resolve_command)
    u8 fillerA9;
    u8 step;                // sub-state of the gTrapHitSteps handlers (trap_hit_run) and gActionPartCheckSteps handlers
                            // (action_part_check_run)
    u8 stepResult;          // result of the last check: 0-2, picks operand [stepResult] in script_op_branch_on_result
    u8 scriptOperands[0x9]; // Robattle action script: operands of the current command (battle_script_load_operands)
    // action effect step script done: cleared by each step dispatcher (trap_hit_run,
    // action_part_check_run..), set by the last step; the callers (script_op_trap_hit,
    // script_op_action_part_check) then call battle_script_advance
    u8 stepDone;
    u8 fillerB6[0x1];
    u8 hitResult; // attack result: 1 missed (target dodged, battle_check_dodged), 3 countered (reaction_check_counter)
    u8 blockResult; // attack result: 2 nullified (Full / Half Block, immunities), 4 absorbed as healing
                    // (attack_hit_branch)
    u8 unkB9;       // raised by gBattleWork.amount up to 0x78 on the own side, lowered on the other
                    // (medaforce_hide_n_seek_apply_evasion, written as &index + 1 to match)
    u8 unkBA;
    u8 unkBB;
    u16 scriptOffset; // Robattle action script: offset of the current command (battle_script_read_byte /
                      // battle_script_advance)
    u8 nullifyReason; // why the attack was nullified: 1 Half Block, 5 Full Block, 2-4 / 6 immunities
                      // (battle_check_nullified)
    u8 absorbReason;  // why the attack was absorbed as healing (2-4; battle_check_absorbed)
    u8 fillerC0[0x8];
    u16 appliedAmount;  // Robattle: effect amount (shown by trap_hit_damage_popup_init, subtracted by
                        // trap_hit_apply_damage)
    u16 overflowAmount; // damage passed to battle_set_damage_vs_armor (attack_hit_carry_over_retarget)
    u16 cappedAmount;   // amount actually applied: min(amount, armor / room left) (battle_calc_damage_split,
                        // battle_set_damage_vs_armor)
    u8 fillerCE[0x2];
    u8 damagePart;     // last part (3..0) of the acting Medabot with armor left (trap_hit_calc_damage)
    u8 partBroken;     // nonzero: trap_hit_check_part_broken goes to sub-state 0x1A
    u8 partBreaks[4];  // Medaforce hit list: per part, 1 when the damage breaks it (hit_list_set_part_damage)
    u16 partDamage[4]; // Medaforce hit list: per part, damage it takes capped at its armor (hit_list_set_part_damage)
    u8 guardBot;   // record + 1 of the teammate guarding target with Defence / Full / Half Block (guard_find), 0 = none
    u8 guardSkill; // its block skill: 0x1B Defence, 0x1C Full Block, 0x1D Half Block (guard_load_graphics)
    u8 defeatedQueue[3]; // per slot: record + 1 of a defeated Medabot waiting for its defeat animation
                         // (add_bot_to_defeated_list, bot_defeat_find)
    u8 fillerE3[0x5];
    s16 success;      // passed to battle_inflict_status with amount (status_attack_apply)
    s16 successBonus; // success / 4, added to the damage (script_op_success_bonus, script_op_calc_damage)
    s16 amount;       // amount for battle_calc_damage_split (attack_absorbed_find_part); counted down by
                      // attack_hit_check_carry_over
    u16 evasion;      // target evasion: legs stat + Medal level + matching parts power + rng & 7
                      // (accumulate_battle_speed_value), taken off success
    u8 fillerF0[0x2];
    s16 finalSuccess; // success after the evasion check (battle_check_guard_or_cover, battle_check_damage_threshold)
    u8 fillerF4[0x2];
    u8 reactionFlags; // bit 0: the target has a reaction ready (battle_check_guard_or_cover, reaction_check); bit 1:
                      // counterattack, the roles are swapped (reaction_counter_begin; 3 script_op_target_self)
    u8 fillerF7[0x1];
    u8 actorSideFlags; // 0 when battle_set_actor_side gets a team record (0-2), 3 for an opponent
    u8 animSkill;      // skill shown by the action script command script_op_skill_anim_start: chosen part's data[1], or
                       // Medaforce actorSkill[0] + 0x50
    u8 fillerFA;
    u8 unkFB; // cleared by script_op_skill_anim_start
    u8 unkFC;
    u8 seqCondition; // skill animation condition (battle_seq_cmd_test_*), picks battle_seq_cmd_branch's label
    u8 unkFE;
    u8 closeupRedraw;   // bits 0 / 1: left / right close-up Medabot must be redrawn with pose base 0x28 before its pose
                        // plays (battle_seq_spr_pose_set)
    u16 seqOffset;      // battle sequence: offset of the current command in gBattleSeqScripts[animSkill] (cleared by
                        // script_op_skill_anim_start)
    s16 seqOperands[8]; // battle sequence: operands of the current command (battle_seq_load_operands)
    u8 closeupLeftPose; // left close-up Medabot pose (0x29 at start, closeup_reset_text_states); bit 7 = finished
                        // (closeup_left_pose_step)
    u8 closeupRightPose;   // right close-up Medabot pose; bit 7 = finished (closeup_right_pose_step)
    u8 closeupPoseBase[2]; // per close-up side (0 left, 1 right): pose base 0 or 0x28, passed to draw_medabot_sprite
    u8 filler116[0x2];
    u8 partChanged;  // nonzero: restore_changed_part writes savedPart back into the acting Medabot's part
    u8 changeSkill;  // Change skill family: part data[1] - 0x37 (0 Change ... 4 HealChange; change_transform_part)
    u8 changePartId; // id of the part swapped in by a Change skill (change_transform_part)
    u8 filler11B[0x1];
    struct BattlePart savedPart; // acting part before a Change skill swapped it, restored by restore_changed_part
    u8 filler134[0x8];
    struct Vec16 botPositions[6]; // per record: x, y - 4 of its battle sprite (copy_battle_entity_positions)
    u16 closeupLeftX;             // left close-up Medabot x (effect sprites start there; init_battle_closeup_scene)
    u16 closeupLeftY;             // left close-up Medabot y
    u16 closeupRightX;            // right close-up Medabot x
    u16 closeupRightY;            // right close-up Medabot y
    u8 partBlockReason[3];   // part select, per arm / head slot (partCursor - 1): 0 usable, 1 broken, 2 status 0x2B on
                             // it, 3 passive skill, 4 no head uses left
    u8 closeupLeftPoseDone;  // left close-up pose finished (closeup_left_pose_step), polled by battle_seq_cmd_wait_pose
    u8 closeupRightPoseDone; // right close-up pose finished (closeup_right_pose_step)
    u8 swapBot;              // record shown instead of the target while the roles are swapped (reactionFlags bit 1;
                             // reaction_counter_begin)
    u8 swapPart;             // part whose pose operands are used while the roles are swapped (targetPart, legs -> 0)
    u8 runNextStep;          // set by a gActionScriptCommands step to run the next step in the same frame
                             // (battle_run_action_script)
    u8 skillGrowthOn;        // nonzero: Medal skill levels can grow (increment_medal_skill_level)
    u8 skillLevelledUp; // set to 1 when a Medal skill levels up (action_phase_time_check then goes to sub-state 0x60)
    u8 levelUpSkill;    // skill type that levelled up
    u8 levelUpLevel;    // its new level
    u8 wonPartKind;     // won Medapart: kind (0 head, 1 right arm, 2 left arm, 3 legs)
    u8 wonPartId;       // won Medapart: id
    u8 wonPartNew;      // won Medapart: 1 = not owned before
    u8 timeTicks;       // Robattle: TIME ticks elapsed (robattle_time_tick)
    u16 score;          // battle score (calculate_battle_score_summary), then experience points
    // After-battle result per team member (u8 array: a struct would be 4-byte aligned):
    // [0] Medal id + 1, 0 = none (name from gMedalNames), [1] nonzero: Medal level-up screen,
    // [2]-[5] copied to gGameWork.transformOldMedal-137, [6] nonzero: [7] = Medaforce id (gMedaforceNames)
    u8 memberResults[3][8];
    u8 resultsMember; // after-battle screen: team member being shown (0-2, 3 = done)
    u8 lossBot;       // gBattleBots record index (battle_loss_take_part)
    u8 dice1;         // two rolls from gDiceRollValues (script_op_roll_dice_damage); amount = (dice1 + dice2) * 10
    u8 dice2;
    u8 partnerName[0x10]; // link Robattle: the partner's player name (link_robattle_exchange_names)
    // Link prize game (after a link Robattle, link/link_robattle.c):
    u8 prizeSlots[6];       // part type per row (4 = miss); = gPrizeGameSlots (prize_game_pick_slots)
    u8 prizePower;          // gauge 0-0x60, stopped with A
    u8 prizePeakY;          // ball's highest y (0x68 - prizePower, at least 12)
    u8 prizeRow;            // landing row 0-5 (prizePower >> 4, reversed)
    u8 prizeLandY;          // ball's landing y (prizeRow * 16 + 0x18)
    u8 prizeMedal;          // losing bot's record unk47 (prize_game_pick_prize_part)
    u8 prizePart;           // part id taken from it
    u16 linkSentSum;        // link exchange: checksum of the sent bytes (never summed in C, stays 0), compared with
                            // linkPartnerRecvSum
    u16 linkRecvSum;        // link exchange: sum of the received bytes & 0x7FFF, compared with linkPartnerSentSum
    u16 linkPartnerSentSum; // link exchange: the partner's linkSentSum (team_select_link_compare_checksums)
    u16 linkPartnerRecvSum; // link exchange: the partner's linkRecvSum
    u8 closeupWipeDone; // set to 1 when the screen wipe of closeup_enter_wipe is done (battle_run_action_script waits
                        // for it)
    u8 linkSendToggle;  // link exchange: bit 8 of the packet being sent, flipped for each new byte
    u8 linkRecvToggle;  // link exchange: bit 8 expected in the next new packet
};

struct MedalData {
    u8 flags;         // bit 7: owned, bit 6: in a Medabot (0x40 tested by medal_trade_check_medal)
    u8 graphicId;     // Medal graphic index (0x80-byte tiles at 0x084C21BC)
    u16 nextLevelExp; // shown as "NEXT Lv" on the Medals list (render_medal_level_display; blank at level 100)
    u8 attribute; // Attribute (gAttributeNames name, Ability page); Medals help: gAttributeHelpMessages message index
    u8 level;     // level (Medals help: Medaforce slots open at 10 / 30 / 60)
    u8 aimSkillType; // Aim skill type (gSkillTypeNames name, Ability page); Medals help: gSkillTypeHelpMessages message
                     // index
    u8 compatibility; // Compatibility icon (tile 0xD340 + compatibility * 4, Ability page)
    u8 spriteVariant; // Medal sprite variant, 0-4 (gMedalSpriteGfx[graphicId][spriteVariant])
    u8 rotationLen;   // rotation entries in use (medal_rotation_draw_actions draws the rest greyed out)
    u8 name[0xE];     // name text
    u8 rotation[8];   // Rotation page actions (gRotationActionMessages message ids)
    u8 skillLevel[8]; // per skill type: level 0-100 (render_medal_skill_stats)
    u8 skillExp[8];   // per skill type: progress to the next level, 0-7, drawn as bar tiles (draw_medal_skill_bars)
    u8 filler30[0xF];
    u8 rotationPos; // Robattle: current rotation entry (battle_bot_advance_rotation advances it, wraps at 8 to
                    // rotationLen)
};

// 256-byte records at gBattleBots (6 of them, cleared together); each starts with a Medal record copy.
struct BattleBot {
    struct MedalData medal;
    // 0x40-0x47: copy of the team slot (struct TeamSlot, copy_team_slots_to_battle_bots);
    // opponents: teamState = 3, gender = head part byte 3, medalId = Medal graphic (init_opponent_bot_slots)
    u8 teamState; // nonzero: record in use
    u8 gender;
    u8 medalId;
    u8 head; // part ids: head, right arm, left arm, legs (battle_bots_load_parts)
    u8 rightArm;
    u8 leftArm;
    u8 legs;
    u8 teamSlot;                // TeamSlot.slotId
    struct BattlePart parts[4]; // head, right arm, left arm, legs
    u8 medaforce[6];            // chosen Medaforce: gMedaforceRecords record (battle_bot_select_medaforce)
    u8 fillerAE[0x2];
    u8 skillUseCount[8]; // per skill type: times used this battle (count_bot_skill_use)
    u8 index;            // own record index (battle_bots_load_parts)
    u8 evasionBonus;     // raised by gBattleWork.amount up to 0x78 on the own side, lowered on the other
                         // (medaforce_hide_n_seek_apply_evasion, written as &index + 1 to match)
    u8 present;    // nonzero: Medabot present (records 0-2 player team, 3-5 opponents); 2 = out of action (Reactivate)
    u8 moveDelay;  // movement delay 0-0x1F, rebuilt each frame by bot_calc_move_delay; speed = 0x20 - moveDelay
    u8 hitFlags;   // hit flags, high nibble cleared by battle_action_cleanup: bit 4 dodged, bit 5 evaded onto the
                   // strongest part, bit 6 hit above the threshold (attack_hit_check_critical)
    u8 stateFlags; // flags (bit 2 toggled by the Robattle handlers robattle_action_finished /
                   // robattle_bot_ready_for_command; set = facing away, which Destroy needs: destroy_check, message
                   // 0x19)
    u8 fillerBE;
    u8 rapidCharge;    // set by Rapid Charge (rapid_charge_apply): the Medabot runs to a line in sub-state 0x4C
                       // (robattle_bots_extra_move), cleared when it gets there
    u8 guardFlags;     // flags (bit 1: traps don't spring on this Medabot, trap_hit_check)
    u8 medaforceGauge; // Medaforce gauge, 0-80 (0x50: Medaforce ready, check_medaforce_availability; drawn as "MF
                       // nn/80", runtime-checked)
    u8 fillerC2[0x2];
    // Two timed effects, ticked every 32 frames by battle_tick_timed_effects (battle_tick_buff_effect /
    // battle_tick_status_effect): type, part, frames left (-4 per tick; at 0 the effect ends and effectShownFlags bit 0
    // / 1 is set), amount.
    u8 buffType; // effect A type (0x1F: restores armor to damaged parts, battle_tick_buff_effect)
    u8 buffPart;
    u8 buffTimer;
    u8 buffAmount;
    u8 buffNumber; // number shown by the Robattle handler 0x70 (robattle_effect_a_number_init)
    u8 statusType; // effect B type (0x13/0x14: armor changes each tick, battle_tick_status_effect; 0x2C checked by
                   // robattle_bot_ready_for_command / process_bot_battle_turn, 0x2B by part_blocked_by_effect)
    u8 statusPart; // effect B part (compared by part_blocked_by_effect; find_burnable_part starts there)
    u8 statusTimer;
    u8 statusAmount;
    u8 statusNumber;     // number shown by the Robattle handler 0x78 (robattle_effect_b_number_init)
    u8 effectShownFlags; // flags: bit 0 / bit 1 = sprites 0x46 / 0x47 + 3 * record shown (robattle_effect_a_end_init ..
                         // robattle_effect_b_end_anim), bit 2 / bit 3 = numbers shown by robattle_effect_a_number_init
                         // / robattle_effect_b_number_init
    u8 statusGuardFlags; // flags: bits 0/1/2/3 set by medaforce_cancel_status_apply (by gBattleWork.unk51); guard
                         // against status skill pairs 0xD/0xE, 0x11/0x12, 0x13/0x14, 0xF/0x10 (bot_has_status_guard)
    u8 powerBonus;       // added to gBattleWork.amount by script_op_calc_damage (Power Up)
    u8 ironWallBonus;    // raised by gBattleWork.amount up to 0xFF (medaforce_iron_wall_apply_defence, written as
                         // &powerBonus + 1 to match)
    u8 unkD2;
    u8 meleeBonus;   // added to gBattleWork.amount for parts with data[2] 0 / 1 (script_op_calc_damage)
    u8 rangedBonus;  // added for data[2] 2 / 3 (script_op_calc_damage)
    u8 trapBonus;    // added to gBattleWork.amount for unk28[side].power (trap_apply; Formation Orders)
    u8 formFlags;    // Medaforce "form" flags, set by medaforce_form_apply from medaforce[0] 4..9: bits 0/1/2 make
                     // any skill count as skill pair 4/5, 6/7, 8/9 (bit 1 also carries leftover damage over, +10);
                     // bits 3/4/5 are the matching guards (check_can_target_bot and friends)
    u8 moveSubpixel; // movement: sub-pixel accumulator, + (0x20 - moveDelay) per frame, 1/16 px (battle_bot_move)
    u16 defence;     // cleared, then raised by gBattleWork.amount up to 0xFF (defence_apply)
    u8 moveStep;     // movement: whole pixels moved this frame
    u8 fillerDB;
    u8 unkDC;           // unkDC..unkE3 cleared by reset_battle_bot_state
    u8 chosenAction;    // chosen command: 0 none, 1-3 head / right arm / left arm, 4+ Medaforce 0..; exchanged over the
                        // serial link in link Robattles (robattle_link_exchange_commands)
    u8 lastAction;      // copy of chosenAction (battle_action_cleanup)
    u8 lastActionSkill; // skill of the part chosenAction (1-3), 0 otherwise (battle_action_cleanup)
    u8 targetBot;       // chosen target record + 1 (0 = none; battle_load_action_target)
    u8 targetPart;      // chosen target part + 1 (0 = pick one; battle_pick_random_target_part)
    u8 fillerE2[0x1E];
};

struct TeamSlot {
    u8 state;  // 0 empty, 1 bare Tinpet (team_add_tinpet), 2 has a Medal, 3 assembled (count_assembled_medabots)
    u8 gender; // Tinpet gender, 0 male / 1 female (team_add_tinpet; Medapart gender unkF1 must match)
    u8 medal;  // Medal id (0x1E none)
    u8 head;   // Medapart ids (validate_medapart_stats); a bare Tinpet part is 0x78 + gender
    u8 rightArm;
    u8 leftArm;
    u8 legs;
    u8 slotId; // own slot index (team_init_order); battle bots keep it at BattleBot.teamSlot
};

// Field scratch state; mostly the debug screen (field/field_debug), which draws its pages as hex
// sprites. Page labels come from the ROM strings: 0 "MP" (map), 1 "EVENT", 2 "PLAYER", 3 "MAP_EFFECT",
// 4 "KWG", 5 "KOMA", 6 "MESS", 7 "LV" (sound). text_bank / text_id are also used by map_script_update_message.
struct FieldDebugWork {
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

// Per-area record list (gAreaExits), ends at mask 0. A record applies when the player steps
// from a neighbouring tile onto (x, y) in a direction whose bit is set in mask.
struct MapExit {
    u8 x;
    u8 y;
    u8 mask;  // direction 0: 2, 1: 1, 2: 8, 3: 4
    u8 value; // returned by check_room_exit_at_position (0 = none)
};

// Map object record (64 at gFieldWork.objects).
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

// Field work at 0x030064A0 shared by the map script helpers, the choice menu and the vehicle menu.
struct FieldScriptWork {
    u8 message_step;  // message_step_run: 0 open / continue the window, 1 run the message
    u8 message_count; // messages shown since message_steps_reset
    // Map script move / anim queues (opcodes 0x80-0x82): one 8-byte list per actor, run together.
    u8 queue_timer[8];     // frames since the last anim frame (anim queue)
    u8 queue_pos[8];       // current step in each list (anim frame for the anim queue)
    u8 queue[8][8];        // the queued lists
    u8 queue_len;          // number of lists queued
    u8 unk53;              // only cleared
    u8 queue_sprite[8];    // sprite slot of each list's actor
    u8 queue_walk_step[8]; // walk sub-step (0 start, 1 walking, 2 done)
    u8 choice_step;        // choice menu step (yes_no_menu_poll: 0 setup, 1 wait handler, 2 poll)
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

// One sprite of the snapshot at gFieldWork.sprite_snapshot (4 bytes)
struct ScriptSpriteSave {
    u8 x; // tile
    u8 y;
    u8 id : 5;
    u8 unk2_5 : 1;
    u8 unk2_6 : 1;
    u8 active : 1;
    u8 anim; // (unk2B & 0xF) << 4 | facing
};

// Field state, gFieldWork (0x030057E0): the area, the player and the follower, the map script runner
// and the battle a script or random encounter sets up.
struct FieldWork {
    u8 filler0[0x5DC];
    struct MapObject objects[64];
    struct ScriptSpriteSave sprite_snapshot[8]; // sprite snapshot (save_script_sprites)
    u8 unk7FC;
    u8 unk7FD;
    u8 area_id;
    u8 story_phase; // story chapter (map script opcode 0x6B; map object unk6 bit n = present in phase n)
    u16 map_width;  // in 8-px tiles (twice the 16-px tile count; tile_map rows are map_width / 2 long)
    u16 map_height; // in 8-px tiles
    u16 unk804;     // area tilemap header words (field_tilemap_header_word(area, 0 / 1))
    u16 unk806;
    u8 filler808[0x8];
    u8 tile_map[0x400];          // one byte per 16-px tile
    u8 tile_actions[0x8];        // tile value -> result of check_tile_and_trigger_battle_action
    u8 saved_tile_actions[0x8];  // saved copy of tile_actions
    u8 script_tile_actions[0x8]; // tile_actions kept aside while a scripted walk clears them
    u8 loaded_form;              // player form whose palette and tile actions are loaded (gFormTileActions)
    u8 encounter_rate;           // area byte 0 of gAreaBattleSettings (area_load_encounter_rate)
    u8 battle_id;                // battle to set up (map script Robattle command, debug menu "Battle" entry)
    u8 encounter_steps;          // steps since the last random encounter (one at 32, chance 1/32 per step after 16)
    u8 encounters_off;           // bit 0: no random encounters (map script opcode 0x5F, debug menu "Rnd.tk")
    u8 fixed_battle; // the battle is battle_id, not rolled from the area (no Rubberobo Medal use, no encounters)
    u8 battle_flags; // high nibble: battle type (2: opponents start with full Medaforce); low nibble: prize part
    u8 story_battle; // set by the map script Robattle command: a loss just fades out, no part is taken
    u8 song;         // song playing (0xFF: the script override in script_song)
    u8 script_song;  // song set by a map script (field_update_music event 3)
    u8 unkC32;
    u8 medawatch_enabled;    // Medawatch menu enabled (B opens the field menu only if set; field debug "CM")
    u8 bg_anim_enabled;      // area BG tile animation enabled (animate_area_bg_tiles)
    u8 bg_anim_frame;        // its frame index
    u8 bg_anim_timer;        // frames until the next one (2: every 3rd frame; runtime-checked)
    u8 rng_seed;             // random seed
    u8 sheet_variants[0x10]; // variant picked for sprite sheet ids 0xD0+ (map_script_cmd_set_area_sprite_sheet)
    u16 map_origin_x;        // screen offset of a map smaller than the screen (field_load_area_tiles)
    u16 map_origin_y;
    u8 unkC4C;
    u8 unkC4D;          // field debug page 0 "MF"
    u8 unkC4E;          // field debug page 4 "BT" (bit 0 "R", bit 1 "E")
    u8 robattle_result; // last map script Robattle: 0 none, 1 won, 2 lost (field debug "WL": N / W / L)
    u8 fillerC50[0x2];
    u16 player_x;
    u16 player_y;
    u8 player_tile_x;
    u8 player_tile_y;
    u8 player_step_frames; // frames left in the current step
    u8 player_move_dir;
    u8 fillerC5A[0x1];
    u8 player_visible;      // player sprite shown (scripts hide it for jumps, warps and cutscenes)
    u8 player_form;         // 0 normal, 1-2 the vehicle menu forms, 3-8 / 0xD disguise items, 0xB / 0xC effect forms
    u8 useBlockFlags;       // set bits block: 0 disguises, 1 Mini S. Wheel, 2 Wings of Wind, 3 Periscope,
                            // 4 Silver Locket, 5 the town map
    u8 savedUseBlockFlags;  // copy of useBlockFlags while a script blocks all but bit 5 (0xDF)
    u8 script_field_update; // the field sub-states keep running under the script (scripted walks)
    u8 unkC60;
    u8 fillerC61[0x6];
    u8 player_facing;
    u8 fillerC68[0x1];
    u8 saved_player_form; // the form to go back to after a temporary one
    u8 fillerC6A[0x4];
    // follower: a script turns a map sprite into sprite 48 (shadow 90) that walks behind the player
    u16 follower_x; // map pixels
    u16 follower_y;
    u8 follower_tile_x;
    u8 follower_tile_y;
    u8 follower_step_frames; // frames left in its current step
    u8 follower_move_dir;    // 0 up, 1 down, 2 left, 3 right; 0xFF none
    u8 follower_active;
    u8 fillerC77[0xC];
    u8 follower_facing;
    u8 follower_sprite_set; // its sprite set (gSpriteEntries.unk2B)
    u8 fillerC85[0x3];
    u8 script_running;            // a map script runs (the field update steps it instead of reading input)
    u8 cmd_busy;                  // the current map script command still runs its gMapScriptUpdates handler
    u16 script_pos;               // map script read offset
    u16 branch_base;              // read offset just after the opcode; conditional jumps add their offset to it
    u16 script_id;                // current map script id (0 once it ends)
    u16 last_script_id;           // the last script started (kept after it ends; field debug EVENT page)
    u8 cmd;                       // current map script command (gMapScriptCommands index)
    u8 cmd_step;                  // step of the running command update
    u8 cmd_args[0x10];            // map script command arguments (read_map_script_bytes)
    u8 script_object_slots[0x10]; // script object slot + 1 (script_object_set_slot)
    u8 script_object;             // index of the map object running the script (objects)
    u8 unkCB5;
    u8 fillerCB6;
    u8 unkCB7;        // field debug page 0 "EF" (0 EE, 1 MP, 2 TE, 3 EX)
    u8 unkCB8;        // field debug page 4 "SK"
    u8 unkCB9;        // field debug page 4 "SP"
    u8 npc_load_mode; // load_map_npc_sprites mode: 0 fresh area, 2 back from a menu or battle
    u8 fillerCBB[0x1];
    // guess: two friendship scores 0-32 (start 16, opcodes 0x3E / 0x3F / 0x50); the field debug page labels
    // them "AR" and "KA" (Arika and Karin?)
    s8 affinity_ar;
    s8 affinity_ka;
};

// Medapart sprite layer (0x20 bytes apart in IWRAM): gHeadPartLayer / gRightArmPartLayer / gLeftArmPartLayer /
// gLegPartLayer are loaded from the ROM templates g*PartLayerTemplate and saved per side in struct SpriteTree.
struct PartSpriteLayer {
    u8 filler0[0xD];
    u8 mirror_pos; // guess: x offset; toggled between x and -2 - x (part_layers_toggle_mirror)
    u8 fillerE[2];
    u8 root_node; // root node of the part's sprite tree (0 = hidden)
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
    float value;
    float base; // value before the move (modes > 1)
    u8 filler8[4];
    s32 mode; // 0 = idle; 0x10-0x14 (anim_interp_init) pick the curve
    float unk10;
    float phase; // sine table index
    float unk18;
    float frame; // frame counter
    s32 start;   // frame the move starts
    s32 end;     // frame it ends, 0xFFFF = none
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

// Field state (gFieldState, 0x3C bytes, cleared by field_clear_ram): the current field state handler's step,
// the frame counter, the BG2 affine matrix, and the BG scrolls saved while a menu or scene covers the field.
struct FieldState {
    u8 unk0; // set to 1 by field_walk_reset, never read in C
    u8 step; // step of the current field sub-state handler (field_walk_update, field_update_*)
    u8 filler2[0x2];
    u32 frame_counter; // +1 per field frame (field_update); NPC idle animations, random rolls
    s16 bg2_pa;        // BG2 affine matrix (identity 0x100, bg2_affine_reset)
    s16 bg2_pb;
    s16 bg2_pc;
    s16 bg2_pd;
    s32 bg2_x; // BG2 affine reference point
    s32 bg2_y;
    u16 affine_debug_flag;  // toggled by A in affine_debug_input
    u16 affine_debug_level; // 0-15, R / L in affine_debug_input
    u16 saved_bg0_x;        // BG scrolls saved when the Medawatch menu opens (field_walk_update),
    u16 saved_bg1_x;        // restored by area_load_graphics; saved_bg1_x / y are also the
    u16 saved_bg2_x;        // base of the screen shake (map_script_update_shake_screen)
    u16 saved_bg3_x;
    u16 saved_bg0_y;
    u16 saved_bg1_y;
    u16 saved_bg2_y;
    u16 saved_bg3_y;
    s16 bg2_center_x; // BG2 rotation centre offset (bg2_affine_update_matrix)
    s16 bg2_center_y;
    s16 unk30;       // cleared by bg2_affine_reset, never read
    s16 bg2_scale_x; // 0x100 = 1.0 (bg2_affine_reset)
    s16 bg2_scale_y;
    u16 bg2_angle;  // 0-255, stepped by RIGHT / LEFT in debug_bg_scroll_input
    u8 unk38;       // cleared when a map script ends, never read in C
    u8 sceneResult; // result of the last battle / minigame: 1 won, 2 lost (map script branch
                    // map_script_cmd_jump_if_lost)
};

// Parameters passed between the field, its scripts and the scenes they start (gFieldSceneParams, 8 bytes).
struct FieldSceneParams {
    u8 race_id;          // race to run (map_script_cmd_race -> race_init)
    u8 event_picture_id; // event picture to show (map_script_cmd_event_picture); also gEventPictureSongs row
    u8 area_speed_id;    // the area's walk speed factor (gWalkSpeedFactors index, sprite_walk_speed)
    u8 warp_sound;       // high nibble of the warp's dir byte: gWarpSoundEffects index (4 = also a step sound)
    u8 selected_item;    // selected item id (item menu, item_menu_handle_input)
    u8 town_map_place;   // place chosen on the town map: gTownMapWarpAreas / Positions index (field effect 0x12)
    u8 bot_gender;       // gender of the team bot found by the script helper; picks palettes 0x28+ in area tiles
};

// Field effect state (gFieldEffect, 0x240 bytes, cleared by field_effect_start); field_effect_run views the
// same memory as struct SeqState.
struct FieldEffectState {
    s32 viewport_w; // 240
    s32 viewport_h; // 160
    s32 viewport_cx;
    s32 viewport_cy;
    float dst_x0; // destination range x0, x1, y0, y1
    float dst_x1;
    float dst_y0;
    float dst_y1;
    float src_x0; // source range x0, x1, y0, y1
    float src_x1;
    float src_y0;
    float src_y1;
    float scale_x; // x / y scale of the destination -> source map
    float scale_y;
    float offset_x; // x / y offset
    float offset_y;
    float camera_x; // camera position x, y, z (set_state_float_field)
    float camera_y;
    float camera_z;
    float camera_dist;
    float cos_yaw; // from gCosTableF32 / gSinTableF32
    float sin_yaw;
    float cos_pitch;
    float sin_pitch;
    float point_x[4]; // projected points x, y, z (field_effect_project_objects)
    float point_y[4];
    float point_z[4];
    float base_yaw; // script yaw / pitch, plus each entity's offsets
    float base_pitch;
    float unk98;
    s32 base_camera_dist; // also the depth at which sprites have scale 1
    s32 projection_scale;
    double origin[2]; // camera origin x, y (field_effect_reset_view)
    s32 screen_x;     // projected screen x, y
    s32 screen_y;
    u8 fillerBC[0x4];
    s32 model_x[4]; // model points x, y, z (from gFieldEffectModels)
    s32 model_y[4];
    s32 model_z[4];
    s32 unkF0;
    u8 fillerF4[0x4];
    s32 effect_id; // flags & 0x3F: script and model set (gFieldEffectModels) index
    u8 fillerFC[0xD0];
    s32 cur_entity; // current entity (index into gFieldEffectEntities)
    s32 part_count; // part count of the current entity
    u32 flags;      // effect id (0x3F), 0x40 = at the player
    s32 pos_x;      // field_effect_start arguments; warps: destination x, y (gFieldWork.player_x units) and area
    s32 pos_y;
    u32 area_id;
    u8 filler1E4[0x26];
    u16 bg_blend_mask; // palette colour masks (run_blend_fade_transition)
    u16 obj_blend_mask;
    u8 filler20E[0x6];
    s32 near_order_base;
    s32 far_order;
    s32 near_priority;
    s32 far_priority;
};

// 3-D entity, 0x300 bytes; gFieldEffectEntities points to an array of them (0x02039000, 16 entries).
struct FieldEffectEntity {
    s32 state; // 0 = free, 2 = left its range (counts as finished); SeqEntity.state
    s32 unk4;
    s32 unk8;
    u8 fillerC[0x4];
    float x; // SeqEntity.x.value
    u8 filler14[0x8];
    s32 x_mode; // SeqEntity.x.mode: cleared to stop the move
    u8 filler20[0x38];
    float y; // SeqEntity.y.value
    u8 filler5C[0x8];
    s32 y_mode;
    u8 filler68[0x38];
    float z; // depth; SeqEntity.z.value
    u8 fillerA4[0x8];
    s32 z_mode;
    u8 fillerB0[0x48];
    float yaw; // yaw / pitch offsets added to the camera (SeqEntity.yaw.value)
    u8 fillerFC[0x14];
    float pitch;
    u8 filler114[0x50];
    float scale_x; // model x / y / z scale (SeqEntity.scale_x.value ...)
    u8 filler168[0x14];
    float scale_y;
    u8 filler180[0x14];
    float scale_z;
    u8 filler198[0x28];
    s32 unk1C0;
    s32 unk1C4;
    s32 unk1C8;
    u8 filler1CC[0x14];
    s32 x_check; // leave when screen x is in [x_min, x_max]
    u16 x_min;
    u8 filler1E6[2];
    u16 x_max;
    u8 filler1EA[2];
    s32 y_check; // leave when screen y is in [y_min, y_max]
    u8 y_min;
    u8 filler1F1[3];
    u8 y_max;
    u8 filler1F5[3];
    s32 z_check; // leave when depth <= z_min or >= z_max
    s32 z_min;
    s32 z_max;
    u8 filler204[8];
    s32 cur_part; // part being projected
    u8 filler210[0xCC];
    u8 part_sprite[4]; // gSpriteEntries slot per part
    u16 part_x[4];     // screen x offset per part
    u8 part_y[4];      // screen y offset per part
    u8 filler2EC[0x14];
};

// Drum kit (gSoundWork->drumKit): notes base..base+count-1 map to a drum; entries are the noise channel
// sub-sequences, pans the per-drum pan, the samples are in gSoundWork->drumSamples.
struct SoundDrumKit {
    u16 count;
    u16 base;
    u32 pans;       // u8 [count]: pan per drum
    u8 *entries[1]; // count entries
};

// Per-track configuration (gSoundTrackConfigs, one per SoundTrack).
struct SoundTrackConfig {
    u32 onEnd;                              // -> SoundTrack.onEnd
    void (*tick)(struct SoundTrack *track); // -> SoundTrack.tick
    u8 channelType;                         // -> SoundTrack.channelType
    u8 echoBuffer;                          // index into SoundWork.echoBuffers, 0xFF = none
    u8 fillerA[2];
};

// Song / sound effect header (tables at gSoundWork->songs / soundEffects).
struct SoundSongHeader {
    u16 trackMask; // bit 11 - i set: track i is used (0x800 = track 0)
    u8 priority;   // copied to SoundTrack.priority
    u8 unk3;
    u8 *tracks[1]; // one sequence pointer per set bit, in track order
};

// Sound driver work area (0x734 bytes, cleared by sound_engine_init).
struct SoundWork {
    struct SoundTrack tracks[13];
    struct SoundTrack *activeTracks;
    u32 unk5E8;
    u8 echoBuffers[3][0x34]; // SoundTrack.echoBuffer (0x30 notes + write index)
    struct SoundSongHeader **songs;
    struct SoundSongHeader **soundEffects;
    struct SoundMixChannel fifoA;
    struct SoundMixChannel fifoB;
    u32 instrumentSamples; // struct SoundSampleHeader *[], by SoundTrack.instrument
    u32 drumSamples;       // struct SoundSampleHeader *[], by drum index
    struct SoundDrumKit *drumKit;
    u8 flags;      // 1 master volume changed, 2 paused, 4 mono (pan forced to both)
    u8 volumeLeft; // SOUNDCNT_L 0-7
    u8 volumeRight;
    u8 songId;
    u16 lockCount; // nonzero while the game updates the work area (sound_engine_tick skips the frame)
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

// Per-area graphics record (gAreaBgTilemaps, indexed by area id).
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
    struct PartSpriteLayer layers[2][4]; // part layers saved per side (setup_medabot_part_sprites)
};

// struct SpriteTree padded to the 0xD0 bytes build_medabot_sprite clears
struct SpriteTreePadded {
    struct SpriteTree o;
    u32 pad;
};

// One per side (gMedabotSpriteSlots): the parts shown and the load state (setup_medabot_part_sprites).
struct MedabotSpriteSlot {
    u8 filler0[4];
    u32 head; // part ids (index the g*PartSpriteNodes tables)
    u32 right_arm;
    u32 left_arm;
    u32 legs;
    u8 filler14[0x14];
    u32 side;
    u32 flags; // 1 pending, 2 load, 4 loaded, 8 visible
};

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

// Work area shared by the menus and screens, reached through the pointer gMenuWork. Each screen clears it
// and uses the fields it needs, so several fields have one meaning per screen (noted where it differs).
struct MenuWork {
    u8 fade_level; // BLDY fade 0-32 (title / test mode / game over / Save Lost), 0-8 (item menu, town map)
    u8 unk1;
    u16 timer;      // frame counter of the current sub-state; name entry: cursor blink frames
    u8 first_entry; // title menu: first selectable entry (1 without a valid save)
    u8 cursor;      // menu cursor (title menu 0-2, shop, link menu, test mode); text scroll: page
    u8 returning;   // 1: back from a sub-screen (item / shop menus); name entry: cursor blink direction
    u8 unk7;
    u32 step;        // link start: message step; name entry: cursor bounce offset
    u8 item_cursor;  // Item screen: cursor item index (page = item_cursor / 5)
    u8 grid_col;     // name entry: letter column (row 3: Space / Back / End)
    u8 grid_row;     // name entry: letter row 0-2, 3 = Space / Back / End
    u8 name_len;     // name entry: letters typed (max 10)
    u8 item_count;   // number of items unpacked by unpack_item_inventory_to_buffer
    u8 list_top;     // first visible list row
    u8 swap_pending; // Item screen: an item is picked up for swapping
    u8 swap_from;    // Item screen: index of the picked-up item
    u8 filler14;
    u8 shake_amplitude; // screen shake amplitude, counts down (game over)
    u8 shake_speed;     // screen shake speed, counts up
    u8 town_map_place;  // Town Map: place under the cursor
    u8 cursor_style;    // Town Map: cursor animation set / palette
    u8 part_kind;       // shop: Medapart kind (head / right arm / left arm / legs; 4 = exit)
    u8 list_cursor;     // shop list: cursor row
    u8 filler1B;
    u32 total;     // shop list: cart total price; link Medal sync: Medal mask
    u8 list_count; // entries in the shop / item / save list
    u8 filler21[0xA];
    u8 sound_test_song;    // test mode: song number (0-51)
    u16 sound_test_effect; // test mode: sound effect number (0-117)
    u8 medal_list_top;     // Medal list: first visible row (medal_rename_draw_list)
    u8 medal_list_cursor;  // Medal list: cursor row
    u8 medal_list_count;   // Medal list: number of entries in medal_list
    u8 own_part_id;        // link trade: Medapart offered by this side
    u8 partner_part_id;    // link trade: Medapart offered by the other side
    u8 own_part_kind;      // link trade: kind of own_part_id
    u8 partner_part_kind;  // link trade: kind of partner_part_id
    u8 filler35;
    u16 bg_tile_base;   // first BG tile of the screen's extra graphics (digits, icons)
    u16 obj_tile_base;  // shop menu: last tile of the part type icons
    s16 frame;          // frame / animation counter (title blend step, link trade tile animation, text scroll)
    u16 ticks;          // rings: frame counter; link trade: timeout countdown
    s16 fade_step;      // text scroll: fade-out step (0-192)
    u16 saved_tiles[4]; // link trade: BG2 tilemap entries restored under the Medal icon
    u8 counter;         // per-screen counter (blink timer, ring radius, link Medal mask, key repeat delay)
    u8 unk49;           // rings: second radius; test mode: cancel sound flag
    u8 pending_sound;   // test mode: sound effect to play once sound_delay runs out
    u8 sound_delay;
    u8 message_pending; // message pending (medal_rename_no_money)
    u8 filler4D[0x3];
    u8 blend[8];         // struct BlendEffect (init_blend_effect, blend_fade_step_08065598)
    u8 name_buf[0x20];   // name text buffer (name_entry_fade_out_store_name copies it to the player or Medal name)
    u16 prev_keys;       // link: the other player's keys last frame (keys_update_from)
    s8 partner_chose;    // link menu: 1 the choice came from the other GBA, 0 this side chose (-1 at start)
    s8 link_battle_ok;   // link menu: Robattle selectable on both sides (0 / -1 or 1)
    s8 link_trade_ok;    // link menu: Medapart trade selectable on both sides
    s8 text_len;         // length of the text at *scene_text (text_scroll_page_start)
    u8 ring_random_mode; // rings: random rotation mode (update_scene_animation_frame)
    u8 saved_song;       // sound_current_song result (link_start_init); song played by battle_cutscene_dispatch
    s16 ring_angles[3];  // rings: rotation angles x / y / z
    s8 ring_speeds[3];   // rings: rotation speeds, clamped to +-16
    u8 filler89;
    u16 ring_rot_x[4]; // rings: per-ring x angle, each trailing the previous one by 1/16 per frame
    u16 ring_rot_y[4];
    u16 ring_rot_z[4];
    u8 ring_center_x[5]; // rings: per-ring screen centre, trailing like ring_rot_*
    u8 ring_center_y[5];
    const u8 *const *scene_text; // scene text (text_scroll_page_start)
    u8 medal_list[0x20];         // Medal list: Medal indices (medal_rename_build_list)
    struct RingPoint
        ring_points[18]; // points on a hexagon / circle (ring_points_place_on_hexagon, ring_points_place_on_circle)
    s32 matrix[4][4];    // 8.8 fixed-point 4x4 transform matrix (matrix_set_identity, matrix_rotate_xyz)
    struct MedalData trade_medal; // link: Medal record received from the other player (medal_trade_transfer)
    u8 message_buf[0x30];         // message text buffer (shop_menu_greeting)
};

// BLDY fade state (init_blend_effect / blend_fade_step_08065598; MenuWork.blend)
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
// Save / first-time flags kept in IWRAM (cleared at boot).
struct SaveStatus {
    u32 saveExists : 1;    // a save was loaded or written (save_dispatch); save screen and link start ask to overwrite
    u32 linkIntroSeen : 1; // link start's 3 intro messages were shown; saved in SaveData.flags bit 5
    u32 unk0_2 : 30;
};

// Battery save image (0x1CBC bytes), built by serialize_save_data and read back by load_save_data
struct SaveData {
    u8 magic[16];                // copied from gSaveMagic
    struct PlayerRecord unk10;   // gPlayerRecord (money, name, ...)
    struct MedalData medals[30]; // gMedals
    u16 medaparts[4 * 120 * 2];  // gMedapartInventory, one byte per halfword
    struct TeamSlot team[9];     // gTeamSlots
    u8 items[64][2];             // gItemInventory
    u16 checksum;                // byte sum of the whole image, computed with this field 0
    u8 fillerFF6[2];
    u8 field[0xCC0]; // gFieldWork
    u8 flags;        // bits 0-1 gOptionTimeLimit, bit 2 gOptionSkipMessages, bits 3-4 gOptionBattleMusic, bit 5
                     // gSaveStatus.linkIntroSeen
    u8 filler1CB9[3];
};

// One Medaroad race (gRaces, by gRaceId): the field and the two rival teams.
struct RaceInfo {
    u8 fixedField;     // nonzero: the race runs on field; else a random one (race_pick_field)
    u8 field;          // battlefield id
    s16 rival1Setup;   // encounter setup (gEncounterSetups) of the second team
    u8 rival1Portrait; // decompress_indexed_asset set for the second leader's portrait (0x06004800)
    u8 filler5[1];
    s16 rival2Setup;   // encounter setup of the third team
    u8 rival2Portrait; // ... third leader's portrait (0x06005000)
    u8 rivalMessage;   // intro lines for the rivals: gRaceMessages[rivalMessage], [rivalMessage + 1]
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
    s32 state; // 0 = free, else active; 2 = left its range
    s32 timer; // frames since it was set up
    s32 start; // tracks step once timer >= start
    s32 end;   // timer at which it is finished, 0xFFFF = never
    struct AnimInterp x;
    struct AnimInterp y;
    struct AnimInterp z;
    struct SeqTrack yaw;
    struct SeqTrack pitch;
    struct SeqOsc affine_scale_x;
    struct SeqOsc affine_scale_y;
    struct SeqRamp scale_x;
    struct SeqRamp scale_y;
    struct SeqRamp scale_z;
    struct SeqRamp affine_angle;
    struct SeqTimer hide_timer; // hide, then free the sprites
    struct SeqTimer blink_timer;
    s32 x_check; // leave its range: see FieldEffectEntity
    s32 x_min;
    s32 x_max;
    s32 y_check;
    s32 y_min;
    s32 y_max;
    s32 z_check;
    s32 z_min;
    s32 z_max;
    s32 anim_id; // sprite_anim_start animation
    s32 animate; // advance the part sprites' animation each frame
    s32 cur_part;
    s32 part_count;
    s32 parent;
    s32 has_triggers; // trigger k runs trigger_script[k] on trigger_entity[k] at timer >= trigger_time[k]
    s32 trigger_time[16];
    s32 trigger_entity[16];
    s32 *trigger_script[16];
    u8 part_sprite[4];
    u16 part_x[4];
    u8 part_y[4];
    struct SeqTimer sound_timer; // plays sound_id every frame while active
    u32 sound_id;
};

struct SeqState {
    u8 filler0[0x90];
    float base_yaw;
    float base_pitch;
    float unk98;
    s32 base_camera_dist;
    s32 projection_scale;
    u8 fillerA4[0x4C];
    s32 running;           // running
    s32 opcode;            // opcode
    s32 effect_id;         // script index
    s32 pc;                // pc
    s32 saved_pc[16];      // saved pc
    s32 call_depth;        // call depth
    s32 *saved_script[16]; // saved script
    s32 cur_entity;        // current entity
    s32 saved_entity[16];  // saved entity
    u8 filler1C8[0xC];
    u32 flags;
    s32 pos_x;
    s32 pos_y;
    s32 area_id;
    u8 filler1E4[0x10];
    s32 fade_mode; // fade mode
    s32 blend_step;
    s32 fade_timer; // fade timer
    s32 fade_start;
    s32 fade_end;
    u8 blend_level;
    u8 filler209;
    u16 bg_blend_mask;
    u16 obj_blend_mask;
    u8 blend_r;
    u8 blend_g;
    u8 blend_b;
    u8 filler211[3];
    s32 near_order_base;
    s32 far_order;
    s32 near_priority;
    s32 far_priority;
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

// One OAM part of a sprite frame (frame tables gSpriteFrameSets etc., read by build_sprite_oam).
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

// Per-area NPC records (gAreaNpcRecords[area]), end at x == 0xFF.
struct MapNpcRecord {
    u8 x;
    u8 y;
    u16 unk2; // copied to MapObject.unk2 (type << 12 | event id)
    u8 unk4;  // bits 4-7: animation set, bits 0-3: animation state; 0xFF = no sprite
    u8 unk5;  // load order
    u16 unk6; // bit n: present when the story phase gFieldWork.story_phase == n
};

#endif // GUARD_STRUCTS_H
