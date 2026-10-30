#ifndef GUARD_VARIABLES_H
#define GUARD_VARIABLES_H

// RAM variables and ROM data. Addresses are in symbols.ld.

typedef void (*Func)(void);

// RAM
extern struct GameWork gGameWork;
extern struct BattleBot gBattleBots[];
extern u8
    gLinkPartnerBotData[]; // partner's 3 BattleBot records (0x48 bytes used per 0x100 row), received over the link
extern u8 gLinkPlayerId;   // multiplayer id from SIOCNT bits 4-5 (init_multiplayer_id); 0 = parent
extern struct MedalData gMedals[];
extern u32 gFrameCounter;
extern u32 gGameMode;
extern struct TeamSlot gTeamSlots[];
extern struct BattleWork gBattleWork;
extern struct SceneWork gSceneWork;       // same address as gBattleWork (game mode 3 scenes)
extern struct BombGameWork gBombGameWork; // same address as gBattleWork (game mode 3 state 5)
// A view through gBattleWork itself: the scene init also clears that block, and the literal pool shares one address.
#define gMedabotsWeekly (*(struct MedabotsWeeklyWork *)&gBattleWork)
extern u32 gMoney; // money, capped at 99999 (add_money)
extern u32 gGameState;
extern u32 gGameSubState;
extern struct SpriteEntry gSpriteEntries[];
extern struct SioLink gSioLink;
extern s32 gOamAffineZoomOverride; // OAM affine zoom override (-1 = off)
extern s16 gSineTableQ14[];        // Q14 sine table, 1024 steps per turn (cos at +0x100); not const: callers reload it
extern u8
    gBg2AffineScanlineBuffer2[]; // second half of the BG2 per-scanline affine double buffer (first: gDecompressBuffer)
extern u32 gLinkBufferSwapIwram[0x10];        // IWRAM copy of link_buffer_swap_arm
extern u32 gSerialTransferHandlerIwram[0x48]; // IWRAM copy of serial_multiplayer_transfer_handler
extern const Func gGameModeHandlers[];        // game mode handlers (AgbMain)
extern struct FieldEffectState gFieldEffect;
extern struct FieldDebugWork gFieldDebug;
extern u8 *gMapScriptData; // current map script data (banked, see read_map_script_byte)
extern struct FieldWork gFieldWork;
extern struct FieldScriptWork gFieldScriptWork;
extern struct ScriptCmdWork gScriptCmdWork;
extern struct SoundWork *gSoundWork;
extern struct SoundWork gSoundWorkArea; // sound work area (soft_reset_to_title passes it to sound_init)
extern struct Vec16 gBg1Scroll;         // BG1 scroll (field: map camera)
extern struct FieldState gFieldState;
extern struct BlendEffectState gBlendEffect;
extern struct MenuWork *gMenuWork;
extern struct EntityState gEntityStates[];
extern struct Vec16 gBg2Scroll; // BG2 scroll
extern struct Vec16 gBg3Scroll; // BG3 scroll
extern u8 *gEventFlags;         // two 4-bit entries per byte (bit 3 / bit 7: flag, bits 0-2 / 4-6: count)
extern u16 *gFieldTilemapBuf;
extern struct FieldSceneParams gFieldSceneParams;
extern struct LinkPackets gLinkPackets;
extern s8 gLinkMultiplayerActive;      // multiplayer link active (soft_reset)
extern vu16 gVBlankFlags;              // bit 0: vblank handler running
extern s8 gFramesSinceMainLoop;        // frames since the main loop last ran (vblank_irq)
extern Func gIntrTable[14];            // RAM copy of gIntrTableTemplate, used by irq_dispatch_arm
extern u32 gIntrMain[0x200];           // RAM copy of irq_dispatch_arm (the IRQ vector)
extern Func gVBlankCallback;           // called every vblank
extern Func gVBlankOnceCallback;       // called at the next vblank, then reset to empty_callback
extern Func gHBlankCallback;           // called by hblank_irq
extern struct OamData gOamBuffer[128]; // copied to OAM in vblank_body
extern struct SpriteWork *gSpriteWork;
extern struct MedabotSpriteSlot *gMedabotSpriteSlots;
extern u32 gVBlankOamMode;           // vblank_body OAM mode (0, 2)
extern u8 gVBlankBgFlags;            // bit 0: vblank_body skips the BG scroll registers
extern struct Vec16 gBgScrollOffset; // scroll added to every BG layer
extern struct Vec16 gBg0Scroll;      // BG0 scroll
extern u16 gTilemapBaseEntry;        // added to every tilemap entry by write_tilemap_to_vram_08000E94
extern u8 gDecompressBuffer[];       // EWRAM buffer the tilemap loaders decompress into
extern u16 gPaletteBackup[0x200];    // OBJ then BG palette (palette_backup_from_hardware)
extern u16 gPaletteBackupBg[0x100];  // = gPaletteBackup + 0x100
extern u16 gPaletteBuffer[0x200];    // OBJ then BG palette (palette_buffer_upload)
extern u16 gPaletteBufferBg[0x100];  // = gPaletteBuffer + 0x100

// Addresses of 16-color palette n in those copies, as integer constants: unlike the symbols they fold with nearby
// literals, so the original literal pools stay shared.
#define OBJ_PAL_BACKUP_ADDR(n) (0x0202F800 + (n) * 0x20)
#define BG_PAL_BACKUP_ADDR(n) (0x0202FA00 + (n) * 0x20)
#define OBJ_PAL_BUFFER_ADDR(n) (0x0202FC00 + (n) * 0x20)
#define BG_PAL_BUFFER_ADDR(n) (0x0202FE00 + (n) * 0x20)
// EWRAM work areas the menus and screens use by address, as integer constants (same reason as above).
#define LIST_WORK_BUFFER_ADDR 0x02023000                    // = gListWorkBuffer
#define LIST_SCROLL_TOP_ADDR (LIST_WORK_BUFFER_ADDR + 0x78) // = gListScrollTop
#define SPRITE_WORK_ADDR 0x02024000 // the struct SpriteWork the Medabot / part preview screens point gSpriteWork at
#define SPRITE_TREE_ADDR 0x02026000 // their struct SpriteTree
#define SPRITE_TREE_OAMS_ADDR(n) (0x020260D0 + (n) * 0x410)      // per-node OAM block of preview sprite n
#define SPRITE_TREE_POSE_FRAME_ADDR (SPRITE_TREE_ADDR + 0xCC)    // u8[2] per sprite: pose animation frame counter
#define SPRITE_TREE_POSE_KEY_ADDR (SPRITE_TREE_ADDR + 0xCE)      // u8[2] per sprite: current pose keyframe
#define SPRITE_SLOTS_ONE_ADDR (SPRITE_TREE_OAMS_ADDR(0) + 0x800) // gMedabotSpriteSlots after one 0x800 OAM block
#define SPRITE_SLOTS_TWO_ADDR SPRITE_TREE_OAMS_ADDR(2) // gMedabotSpriteSlots after two OAM blocks (0x820 cleared)
#define BATTLEFIELD_ANIM_TILES_ADDR 0x02027000 // decompressed battlefield animation tiles, copied to VRAM per frame
#define DECOMPRESS_BUFFER_ADDR 0x02030000      // = gDecompressBuffer; also the field tilemap buffer and the save image
#define MENU_LIST_ADDR 0x02040000              // item list / shop sell list (an EWRAM mirror of 0x02000000)
extern u32 gRngCounter;
extern u32 gRngValue;
extern u32 gRngState;
extern u8 gPlayTimeRunning; // 1 while gPlayerRecord.playTime counts (cleared on the save screen)

// ROM data
extern const Func gIntrTableTemplate[14];
extern const u32 gRngTable[16];
extern const struct PartSpriteLayer gHeadPartLayerTemplate; // part layer templates (setup_medabot_part_sprites)
extern const struct PartSpriteLayer gLeftArmPartLayerTemplate;
extern const struct PartSpriteLayer gRightArmPartLayerTemplate;
extern const struct PartSpriteLayer gLegPartLayerTemplate;
// Sprite tree node lists by part id: head, right arm, left arm, legs (non-const: needed to match)
// Sprite tree node list per Medapart id, one table per part kind (lists end with node 0)
extern struct SpriteTileRef gHeadPartSpriteNodes[][4];
extern struct SpriteTileRef gRightArmPartSpriteNodes[][4];
extern struct SpriteTileRef gLeftArmPartSpriteNodes[][4];
extern struct SpriteTileRef gLegPartSpriteNodes[][8];
extern struct SoundSongHeader *gSongTable[];        // song table (sound_init)
extern struct SoundSongHeader *gSoundEffectTable[]; // sound effect table (sound_init)
extern struct SoundDrumKit gDrumKit;
extern const u8 gInstrumentSamples[];  // sample pointers by SoundTrack.instrument
extern const u8 gDrumSamples[];        // sample pointers by drum index
extern const u8 gWalkSpeedFactors[];   // [0] 1, [1] 2: walk speed = factor[sprite] * factor[area] (sprite_walk_speed)
extern const u8 gPlayerFormSpeedIds[]; // player_form -> gWalkSpeedFactors index of sprites 47 / 48
extern const u8 gPlayerFormSpriteSheets[]; // player form -> map sprite sheet id (its palette in gFieldSpritePalettes)
extern const u8 gEventPictureSongs[];      // 4 per event picture: stop song?, song, after-mode (1 = play), song after
extern const u16 *const gFieldSpritePalettes[]; // 16-colour OBJ palette per map sprite sheet id (NULL: none)
extern const u8 gFormTileActions[][8];   // field tile actions per player form (copied to gFieldWork.tile_actions)
extern const u8 gSpriteSheetHasShadow[]; // per map sprite sheet id: give the sprite a shadow (sprite 0x90)
extern const u8 gDpadRemaps[][16];       // D-pad bits remapped by an area 0x53 tile (1 same, 2 reversed, 3 / 4 rotated)
extern const u8 gAreaMapSizes[][2];
extern const u8 gArea53DpadTiles[]; // area 0x53, per tile: 1-4 = the gDpadRemaps row + 1 (area53_remap_dpad)
extern const struct AreaWarp *const gAreaWarps[];
extern void (*const gMapScriptCommands[])(void); // map script command handlers
extern void (*const gMapScriptUpdates[])(void);  // per-command update handlers, run each frame while cmd_busy is set
extern const u8 gOppositeDirection[]; // indexed by the player's facing (gSpriteEntries[47].work[FIELD_SPR_ANIM_FACING])
extern const u8 gPlayerFormScriptSpeedIds[]; // walk speed id by gFieldWork.player_form for scripted player walks
                                             // (gPlayerFormSpeedIds but form 9 walks normally)
extern const u8 *const gAreaCollisionMaps[]; // per area: tile map
extern const struct AreaGfx gAreaBgTilemaps[];
extern const u8 gNpcFacingTowardPlayer[]; // NPC facing by the player's (gSpriteEntries[47].work[FIELD_SPR_FACING]): the
                                          // opposite one
extern const u8 gWarpSoundEffects[];      // sound played when stepping on a warp, by gFieldSceneParams.warp_sound
extern const u8 gShadowTilesLz[];         // the player's shadow (sprite 89), LZ77 OBJ tiles at 0x06017FC0
extern const struct MapExit *const gAreaExits[]; // per area: 8-byte map exit records, 0xFF-terminated
extern const u16 gSoundPsgNoteFreqs[];
extern const u16 gSoundFifoVolumeMasks[];
extern const u8 gSoundFifoVolumeBits[][16];
extern const u16 gSoundFifoOutputBits[][4];
extern const u16 gSoundFifoOutputMasks[];
extern const u8 gSoundWavePatterns[][16];   // 4-bit samples for the wave channel (sound 3)
extern const u8 gSoundWaveVolumes[16];      // envelope volume -> SOUND3CNT_H volume bits (>> 8)
extern const u16 gSoundSemitoneRatios[12];  // 2^(i/12) * 0x1000
extern const u16 gSoundFinetuneRatios[128]; // 2^(i/(12*128)) * 0x1000
extern const u32 gSoundEffectTracks[6];     // track indices of the sound effect tracks (4-7, 10, 11)
extern const Func gMenuBattleModeStates[];
extern const u32 gMedalNames[]; // Medal names by Medal id (0 KUWAGATA, 6 SNAKE...); +0x20: "Rokusho" / "Metabee"
// 16 bytes per Medal: [0-2] Medaforce ids (gMedaforceRecords), [3-6] Medal levels (guess: when each one unlocks),
// [7] icon, [8-15] guess: aptitude per skill type
extern const u8 gMedalRecords[][16];
extern const u8 gMedabotSpriteNodeDescs[];   // SpriteNodeDesc pointers of the Medabot sprite tree
extern const u32 gMedabotNames[];            // Medabot name strings by head part id (medabot_name)
extern const u8 gMedalAttributeBaseSkills[]; // 8 bytes per Medal attribute: base skill levels (init_enemy_bot_medal)
extern const u8 gAiPartOrders[][4];          // 32 part orders (0xFF = end) tried by select_bot_battle_action
extern const u32 gMedapartNames[][4];        // Medapart name pointers: [part id][kind: head, right arm, left arm, legs]
extern const u32 gItemNames[];               // item name strings by item id (17 bytes, item lists)
extern vu32 *const gSoundFifoAddrs[];        // REG_FIFO_A, REG_FIFO_B
extern vu32 *const gSoundTimerRegs[];        // REG_TM0CNT, REG_TM1CNT (sample rate timers of FIFO A / B)
extern const u8 gSoundFifoResetBits[];       // SOUNDCNT_H high byte: FIFO A / B reset
extern const u16 gSoundFifoEnableBits[];     // SOUNDCNT_H: FIFO A / B left+right enable
extern vu16 *const gSoundFifoDmaCnt[];
extern const struct SoundTrackConfig gSoundTrackConfigs[13];
extern const u8 gSoundOutputMasks[4];     // SOUNDCNT_L high byte: clears the left/right enables of PSG channel i
extern const u8 gSoundOutputBits[4][4];   // [channel][output: 0 off, 1, 2, 3 both] SOUNDCNT_L high byte bits //
                                          // REG_DMA1CNT_H, REG_DMA2CNT_H
extern u8 gCurrentMedalSlot;              // gMedals slot the Medal level-up / naming screens work on
extern s32 gRaceStep;                     // step counter of the current race sub-state
extern u8 gRaceRunner[];                  // per team: runner on the track (0-2), 3 = team finished
extern s32 gRaceNextSubState;             // sub-state to resume after a transition (code_08067160)
extern u8 gRaceField;                     // battlefield the race runs on (race_pick_field)
extern u8 gRaceStaticBg;                  // 0: race_dispatch_substate scrolls BG3 diagonally
extern u8 gRaceFinishOrder[3];            // team + 1 that finished 1st, 2nd, 3rd (0 = not yet)
extern u8 gRaceRunnerParts[3][4][3];      // [team][head/right/left/legs][runner]: part ids for the runner sprites
extern const Func gRaceSubStates[];       // race sub-states, by gGameSubState (race_dispatch_substate)
extern u8 gRaceLegTypes[3][3];            // per team and runner: leg type - SKILL_LEGS_AIR (gRaceLegDelays column)
extern s32 gRaceStepTimers[3];            // per team: frames since the runner last moved (race_advance_runners)
extern const u8 gRaceBgTiles[];           // race BG tiles (LZ77, race_load_frame_bgs)
extern const u8 gRaceBg2Tilemap[];        // race BG2 tilemap (LZ77)
extern const u8 gRaceBg3Tilemap[];        // race BG3 tilemap (LZ77)
extern const u16 gRaceBgPalette[];        // race BG palette
extern const u8 gMedalSceneObjPalettes[]; // Medal scene OBJ palettes (medal_transform_init)
extern const u32 gMedalSceneBgTiles[];    // Medal scene BG tiles (dma3_copy_or_decompress)
extern const u8 gMedalSceneBg1Tilemap[];  // Medal scene BG1 tilemap (decompress_and_write_tilemap)
extern const u8 gMedalSceneBg2Tilemap[];  // BG2 tilemap
extern const u8 gMedalSceneBg3Tilemap[];  // BG3 tilemap
extern const u8 gRaceObjTiles[];          // race OBJ tiles (LZ77, race_load_character_sprites)
extern const u8 gRaceFieldBgTiles[];      // race field BG tiles (LZ77, race_load_track_screen)
extern const u8 gRaceFieldBgTiles2[];     // race field BG tiles, parts 2-4 (LZ77, race_load_track_screen)
extern const u8 gRaceFieldBgTiles3[];
extern const u8 gRaceFieldBgTiles4[];
extern const u16 gRaceFieldBgPalettes[];  // race field BG palettes
extern const u16 gRaceFieldBgPalettes2[]; // race field BG palettes 9-11
extern const u16 gRaceFieldBgPalettes3[];
extern const u16 gRaceFieldBgPalettes4[];
extern const u8 gRaceStatusBarTiles[];      // race BG1 tiles (LZ77, race_load_track_status_bar)
extern const u8 gRaceStatusBarTiles2[];     // race BG1 tiles, second part (LZ77)
extern const u16 gRaceStatusBarPalettes[];  // race BG1 palettes
extern const u16 gRaceStatusBarPalettes2[]; // race BG1 palette 13
extern const u8 gSceneTextLineCounts[];     // scene text line counts by gMenuWork->cursor (text_scroll_lines)
extern u8 gRaceAnimDelay[3];                // per team: run animation frame delay (0x20 slowest, A presses lower it)
extern u8 gRaceAnimTimers[3];               // per team: frames since the run animation last stepped
extern s32 gRaceRivalTapTimers[2];          // rival teams: frames since their last simulated A press
extern s32 gRaceRivalTaps[2];               // rival teams: simulated A presses (phase into gRaceRivalPace)
extern const Func gGameStateHandlers[];     // by gGameState (dispatch_game_mode_handler)
extern const u8 gRaceRivalPace[]; // [rival * 11 + field]: phase of the rivals' tapping rhythm (race_update_speeds)
extern const struct ByteTable3 gRaceTeamSpriteParams; // guess: per team sprite parameter; 3 bytes copied to the stack,
                                                      // indexed by racer (race_refresh_runner_sprite)
extern u8 gRaceRunnerSlots[3][3];    // [team][runner]: sprite slot of the runner (ROM; not const, the code reloads it
                                     // after stores)
extern const u8 gRaceLegDelays[][7]; // [field][leg type]: frames per step of a runner
extern bool32 (*const gRaceSpriteMotions[])(
    u8);           // race sprite animations, by gSpriteEntries[].work[RACE_SPR_MOTION] - 1 (race_run_sprite_motions)
extern u8 gRaceId; // race (gRaces index), copied from gFieldSceneParams.race_id by race_init
extern s32 gSceneStepFrames;                // scene step frame counter, reset when a step finishes (execute_scene_step)
extern u8 gSceneStep;                       // scene step, gSceneSteps index
extern bool32 (*const gSceneSteps[])(void); // scene steps (execute_scene_step)
extern bool32 (*const gSceneTransitionSteps[])(void); // transition steps (scene_transition_step_080686F4)
extern const u16 gTitleObjPalettes[]; // title OBJ palettes (0x60 colours), then 0x1C bytes copied to gSceneWork + 0xC
                                      // (title_screen_load_graphics)
extern const Func gBombGameStates[];  // game mode 3 state 5 sub-states, by gGameSubState (bomb_game_dispatch)
extern const struct SpriteAnimFrame gRaceSpriteAnims[]; // sprite animation steps (race_step_sprite_anims)
extern const u8 gBombGameBgTiles[];      // game mode 3 state 5 (bomb_game_load_graphics): compressed BG tiles
extern const u8 gBombGameBgTilemap1[];   // compressed BG map (VRAM + 0x800)
extern const u8 gBombGameBgTilemap2[];   // compressed BG map (VRAM + 0x1000)
extern const u8 gBombGameBgTilemap3[];   // compressed BG map (VRAM + 0x1800)
extern const u16 gBombGameBgPalettes[];  // BG palettes (0x50 colours)
extern const u8 gBombGameObjTiles[];     // compressed OBJ tiles
extern const u16 gBombGameObjPalettes[]; // OBJ palettes (0xF0 colours)
extern const s8 gHalfSineArc[];          // 64 steps of a half sine, 0..47..2: bounce / hop heights (bomb game, race)
extern const Func
    gTitleScreenStates[]; // game mode 3 state 2 (title screen) sub-states, by gGameSubState (title_screen_update)
extern s32 (*const gTitleSpriteEffects[])(u8); // title sprite effects, by gSpriteEntries[].work[TITLE_SPR_EFFECT] - 1:
                                               // 0 = done, 0xFF = hide (title_screen_update_sprite_effects)
extern const u8 gTitleSpriteEffectPeriods[];   // title sprite effects: frame period, by work[TITLE_SPR_EFFECT] - 1
extern const Func gStoryIntroHandlers[];       // game mode 3 state 3 (story intro) sub-states, by gGameSubState
                                               // (dispatch_game_substate_handler_0806DFA4)
extern const Func
    gBootLogosSubStates[]; // game mode 3 state 0 (boot logos) sub-states, by gGameSubState (boot_logos_update)
extern const Func gIntroSubStates[]; // game mode 3 state 1 (the animated intro after the logos) sub-states, by
                                     // gGameSubState (intro_update)
extern const void
    *const gStoryIntroTexts[]; // story intro texts, by page gSceneWork.param.h (dispatch_battle_event_script)
extern const void *const gStoryIntroTiles[];       // story intro compressed tiles (to 0x06008000), by page
extern const void *const gStoryIntroTilemaps[];    // story intro compressed tilemaps (30x20), by page
extern const void *const gStoryIntroPalettes[];    // story intro palettes (0xE0 halfwords), by page
extern const u8 gLicensedByLogoTiles[];            // boot logo 1: compressed BG tiles (boot_logos_load_licensed_by)
extern const u8 gLicensedByLogoTilemap[];          // boot logo 1: compressed 30x20 tilemap
extern const u16 gLicensedByLogoPalette[];         // boot logo 1: palette (16 colours)
extern const u8 gNatsumeLogoTiles[];               // boot logo 2: compressed BG tiles (boot_logos_load_natsume)
extern const u8 gNatsumeLogoTilemap[];             // boot logo 2: compressed 30x20 tilemap
extern const u16 gNatsumeLogoPalette[];            // boot logo 2: palette
extern const u8 gBootOverlayTiles[];               // boot overlay: compressed BG1 tiles (boot_logos_load_overlay)
extern const u8 gBootOverlayTilemap[];             // boot overlay: compressed 30x20 tilemap (palette 1)
extern const u16 gBootOverlayPalette[];            // boot overlay: palette 1
extern const u8 gTitleObjTiles[];                  // title (title_screen_load_graphics): compressed OBJ tiles
extern const u8 gTitleBgTiles[];                   // title: compressed BG tiles
extern const u8 gTitleBg2Tiles[];                  // title: BG2 tiles (0x240 bytes, uncompressed)
extern const u16 gTitleBgPalettes[];               // title: BG palettes (0x60 colours)
extern const u8 gTitleBg0Tilemap[];                // title: compressed tilemap (to 0x06006800)
extern const u8 gTitleBg1Tilemap[];                // title: compressed tilemap (to 0x06007000)
extern const u8 gTitleBg2Tilemap[];                // title: BG2 affine tilemap (0x280 bytes)
extern const u8 gIntroSilhouetteBgTiles[];         // state 1 scene (intro_load_silhouette_scene): compressed BG tiles
extern const u16 gIntroSilhouetteBgPalettes[];     // BG palettes 0-15 (256 colours)
extern const u8 gIntroSilhouetteBg1Tilemap[];      // compressed tilemap (to 0x06007000)
extern const u8 gIntroSilhouetteBg3Tilemap[];      // compressed tilemap (to 0x06007800)
extern const u8 gIntroScanBgTiles[];               // state 1 scene (intro_load_scan_screen): compressed BG tiles
extern const u16 gIntroScanBgPalettes[];           // BG palettes 0-15 (256 colours)
extern const u8 gIntroScanBg2Tilemap[];            // compressed tilemap (to 0x06007000)
extern const u8 gIntroScanBg3Tilemap[];            // compressed tilemap (to 0x06007800)
extern const u8 gIntroSilhouetteBg2Tiles[];        // compressed BG2 tiles (to 0x06008020, from tile 1)
extern const u16 gIntroSilhouetteBg2Palette[];     // BG palette 0
extern const u8 gIntroSilhouetteBg2Tilemap[];      // compressed 10x12 BG2 tilemap
extern const u8 gIntroScanFontTiles[];             // compressed BG1 scan text font (tile 1+, palette 8)
extern const u8 gIntroPartNameFontTiles[];         // BG1 tile 0x64+: part name letters (palette 9)
extern const u8 gIntroCounterDigitTiles[];         // BG1 tile 0xC8+: digits of the frame / noise counters
extern const u8 gIntroPointerLineTiles[];          // BG1 tile 0xD2+: the scan pointer lines
extern const u16 gIntroScanTextPalette[];          // BG palette 8 (scan text)
extern const u16 gIntroScanLabelPalette[];         // BG palette 9 (part name, counters)
extern const u16 gIntroScanBgPalette0[];           // BG palette 0
extern const u8 gIntroScanTextGlyphs[];            // compressed glyph strings, to gSceneWork.scanTextGlyphs
extern const void *const gIntroSilhouetteTiles[2]; // compressed tiles ([1] to 0x06008C80, intro_load_silhouette_scene)
extern const void *const gIntroSilhouetteMaps[2];  // compressed 20x20 tilemaps ([1] in intro_load_silhouette_scene)
extern const void *const gIntroSilhouettePals[2];  // 16-colour palettes ([1] in intro_load_silhouette_scene)
extern const void *const gIntroScanObjTiles[2];    // compressed OBJ tiles (intro_load_scan_sprites)
extern const void *const gIntroObjPals[2];         // OBJ palettes (0x50 halfwords; [1] in intro_load_rokusho_sprite)
extern u8 gTransitionFramesPerLevel;               // scene step speed: frames per fade level
extern u16 gTransitionWipeRows[];                  // BG0 tilemap offsets of the rows the wipe steps clear / fill
extern u16 gTransitionFadeColor;                   // palette fade target color
extern u16 *gTransitionSourcePalette;              // palette fade source palette (0x200 colors)
extern u16 gTitleBg2PaTable[160];                  // title BG2 per-scanline values: BG2PA (title_screen_hblank, HBlank)
extern u16 gTitleBg2XLowTable[160];                // BG2X_L per scanline
extern u16 gTitleBg2XHighTable[160];               // BG2X_H per scanline
extern u16 gTitleBg2ScrollX;    // title BG2 scroll counter, += 0x80 per frame (title_screen_build_wave_tables)
extern u8 gTextArgBuffer[];     // scratch text: a name for a message argument, or a number rendered as text
extern const u8 gRandomBytes[]; // random bytes, indexed by the low byte of gFrameCounter
extern const void *const gRaceMessages[];  // referee lines of the race
extern const struct RaceInfo gRaces[];     // by gRaceId
extern const u16 gRacePointerObjPalette[]; // OBJ palettes (inside the 0x080750D8 data blob)
extern const u16 gRaceSignalObjPalettes[]; // OBJ palettes 12 and 11 (+0x30 entries) of the start signal
extern const u16 gRacePlaceObjPalette[];
extern const u16 gRaceWinnerObjPalette[];
extern const u16 gRaceRunnerObjPalette[]; // guess: OBJ palette 13 of the race runners (race_load_character_sprites)
extern u8 gNameEntryMode; // 0 player name, 1 new Medal (default name), 2 rename a Medal gMedals[gCurrentMedalSlot]
extern u8
    gNpcSpriteEntryBytes[]; // = (u8 *)&gSpriteEntries[49] (map object sprites), cleared by map_script_update_reload_map
extern u8 gNpcEntityStateBytes[]; // = (u8 *)&gEntityStates[49]
extern const void
    *const gScriptItemMessages[]; // got / gave item, Medapart, money, Medal, Tinpet messages (map_script_update_give_*)
extern const u32 *const gTextTable[];             // text pointers, banks 0-1 (guess)
extern const u32 *const *const gTextBankTables[]; // text pointer tables, bank 2+ (guess)
extern const s16 gJumpArcTable[][8];              // jump arc: [n][0] / 16 = sprite y offset at frame n (hops / jumps)
extern const u8 gScriptPlayerForms[];     // map script terrain/palette id -> player_form/saved_player_form/loaded_form
                                          // (map_script_update_set_player_form)
extern struct PlayerRecord gPlayerRecord; // gMoney is its first field
extern const Func gDevTestStates[];       // game state 0 (developer test screen) sub-state handlers
extern const Func gFieldMenuHandlers[];   // game state 1 (field pause menu) sub-state handlers
extern const void
    *const gMenuMessages[]; // menu messages: debug menu (0-3), Medals screen hints / help (4-15), pre-battle (20-21)
extern const void *const gLinkMessages[];             // message table (run_message)
extern const u8 gMedabotsCursorOrbitCenters[];        // orbit centre x, y per gGameWork.medabotsCursor
extern const u8 gMedabotsSlotSpritePriorities[];      // per slot sprite priority base
extern const u8 gMedabotsSlotPositions[];             // x, y per team select slot (9)
extern const u8 gTeamSelectNextSlot[];                // team select: cursor slot to move to after a pick, per slot
extern const u8 gMedabotsSlotPedestalTilePositions[]; // tile x, y per team select slot (9)
extern const u8 *const gMedabotSlotDpadMoves[]; // up, down, left, right: next slot (gGameWork.medabotsCursor) per slot
extern const void *const gUiTilemaps[];         // tilemaps (field menu rows: open/close animation frames)
extern const void *gBattleSpriteAnimScripts[];  // battle sprite animation command lists (battle_sprite_anim_init /
                                                // process_sprite_anim_commands)
extern const u8 gFieldMenuMedawatchLabelTiles[];
extern const u8 gFieldMenuItemLabelTiles[];
extern const u8 gFieldMenuVehicleLabelTiles[];
extern const u8 gFieldMenuSaveLabelTiles[];
extern const u8 gMenuSlideLineTile[]; // guess: the line tile drawn as the chosen field menu row slides
extern const u8 gMoneyWindowTiles[];
extern const u8 gMoneyWindowHalfTiles[]; // money window frame halfway open / closed
extern const u16 gMenuBgPalette[];
extern const u8 gMoneyWindowHalfTilemap[];
extern const u8 gMoneyWindowTilemap[];
extern const u8 gSpriteFontTiles[]; // 8x16 OBJ font (letters, digits, $) at 0x06017400, render_text_sprites
extern const u16 gSpriteFontPalette[];
extern const u8 gFieldMenuCursorTiles[];
extern const u16 gCursorArrowPalette[]; // OBJ palette 14 of the arrow cursor (gCursorArrowTiles)
extern const u16
    gHelpCursorPalette[]; // OBJ palette 14 while a Medals / Medaparts help page is open. guess: help cursor colours
extern const u8
    gTradeChoiceWindowTilemap[]; // Details / Trade / Cancel window of the Medals and Medaparts link trade choice
extern const void
    *const gAttributeHelpMessages[]; // messages (run_message), indexed by Medal record byte 4 (Medals help)
extern const void
    *const gSkillTypeHelpMessages[];  // messages (run_message), indexed by Medal record byte 6 (Medals help)
extern const u8 gMedalMedaforceIds[]; // 3 Medaforce ids per Medal graphic index (slots open at level 10/30/60)
extern const u8 gMedaforceRecords[];  // 6-byte Medaforce records: +1 skill type, +2 MF consumption, +5 icon
extern const void *const gMedaforceTypeHelpMessages[];  // messages (run_message), Medals help Medaforce page
extern const void *const gMedaforceSkillHelpMessages[]; // messages (run_message), Medals help page 5
extern u32 gLinkTradeData; // bit per Medal graphic index (medal_trade_check_medal); also (part kind << 16) + part id
                           // (medapart_trade_store_part)
extern const u8 gMedalSkillBgTiles[];
extern const u8 gMedalSkillBg0Tilemap[];
extern const u8 gMedalSkillBg1Tilemap[];
extern const u8 gMedalSkillBg2Tilemap[];
extern const u8 gMedalSkillBg3Tilemap[];
extern const u16 gMedalSkillBgPalette[];
extern const Func gMedawatchMenuHandlers[];    // game state 2 (Medawatch menu) sub-state handlers
extern const u8 gMedawatchBgTilesLz[];         // Medawatch menu BG tiles (LZ77)
extern const u8 gMedawatchBg1Tilemap[];        // Medawatch menu BG1 tilemap
extern const u8 gMedawatchBg2Tilemap[];        // BG2 tilemap
extern const u8 gMedawatchBg3Tilemap[];        // BG3 tilemap (scrolled by medawatch_scroll_bg3)
extern const u16 gMedawatchBgPalettes[];       // 12 BG palettes
extern const u8 gMedawatchIconMedabotsTiles[]; // watch face icon per gGameWork.medawatchCursor (LZ77)
extern const u8 gMedawatchIconMedalsTiles[];
extern const u8 gMedawatchIconMedapartsTiles[];
extern u8 gTextGlyphTile[];   // message text: the next glyph, shifted then ORed into gTextComposeTile
                              // (text_render_glyph_step)
extern u8 gTextComposeTile[]; // message text: the 8x16 tile being composed, flushed to the window tiles when full
extern u8 gBgTileBackup[];    // BG tile backup (0x800 bytes of VRAM 0x06002800 while a Medawatch submenu runs)
extern const Func gMedabotsScreenHandlers[];        // game state 3 sub-state handlers
extern const Func gMedalsScreenHandlers[];          // game state 4 (Medals screen) sub-state handlers
extern const Func gMedapartsScreenHandlers[];       // game state 5 (Medaparts screen) sub-state handlers
extern const Func gMedapartTradeChoiceCloseSteps[]; // sprite 4 sub-state handlers, by
                                                    // gSpriteEntries[4].work[MEDAPARTS_SPR_CLOSE_STEP]
                                                    // (medapart_trade_choice_close_step)
extern const Func gPrebattleScreenHandlers[];       // game state 6 ("Get ready to Robattle") sub-state handlers
extern const u8 gPrebattleWipeTiles[];
extern const void *const gOpponentPreBattleMessages[]; // pre-battle opponent lines, by gBattleWork.encounterMessage
extern const u16 gPrebattleWipePalette[];
extern const u8 gPrebattleBgTiles[];
extern const u8 gPrebattleObjTiles[]; // guess: OBJ tiles of the opponent screen (0x06012800)
extern const u8 gPrebattleBg1Tilemap[];
extern const u16 gPrebattleBgPalette[];
extern const u16 gLegTypePedestalPalette[];  // BG palette 8 (gLegTypePedestalTiles)
extern const u16 gLegTypePedestalPalette2[]; // BG palette 9 (gLegTypePedestalTiles2)
extern const u16
    gGradientPaletteYellow[]; // first of the 16-colour ramps up to gBlackObjPalettes; code indexes across them
extern const u16 gPrebattleObjPalette[];
extern u8
    gMedapartInventory[4 * 120 * 2]; // 2 bytes per Medapart, 120 per kind (head, right arm, left arm, legs): [0] count
                                     // owned (runtime-checked), [1] count equipped (team_lose_equipped_part)
// The Medaparts list shows 4 parts per page (part id = page * 4 + row); the game indexes it flat like this.
#define MEDAPART_INV(kind, page, row, byte) gMedapartInventory[(kind) * 240 + (page) * 8 + (row) * 2 + (byte)]
extern u8
    gItemInventory[64][2]; // item inventory (runtime-checked): [0] 0x80 | item id, [1] count (get_item_quantity_by_id)
extern const u8
    gLegWalkFrames[]; // 4 walk phases: legs tile offset, nonzero = body bobs (update_battle_sprite_orbiting_positions)
extern const u8 gPlayerFormSpriteSets[]; // indexed by gFieldWork.player_form (resolve_area_sprite_set)
extern const u8
    gMedapartData[]; // 16 bytes per part kind (head / arms / legs), 64 per part id; copied by load_part_data
extern const u8
    gReplayRandomBytes[]; // fixed random bytes, indexed by gGameWork.rngIndex when skipBotSetup is set (rng_next_byte)
extern const u8
    gMedapartsListBgTiles[]; // Medaparts list screen (medaparts_list_load_gfx; runtime: VRAM dump of the list)
extern const u8 gMedapartTypeLabelTiles[]; // HEAD / RIGHT ARM / LEFT ARM / LEGS title labels of the Medaparts list
extern const u8
    gPartGenderIconTiles[];        // 2x2 icons: male (blue), female (pink); Medaparts list SEX column and detail page
extern const u8 gTallDigitTiles[]; // 2-row digits for draw_number_tall_bgcnt (Medaparts list counts, Robattle)
extern const u8 gMedapartsListBg0Tilemap[];
extern const u8 gMedapartsListBg1Tilemap[];
extern const u8 gMedapartsListBg2Tilemap[];
extern const u8 gMedapartsListBg3Tilemap[];
extern const u8
    gMedapartDetailBgTiles[]; // Medapart detail page (medapart_detail_load_gfx; runtime: VRAM dump of the page)
extern const u8
    gMedapartStatLabelTiles[];          // ARMOR / RATE OF SUCCESS / POWER / AMOUNT OF USES / ... labels, 12 tiles each
extern const u8 gPartPowerMarkTiles[];  // 2 tiles beside POWER when gGameWork.partStat3 is set. guess: power bonus mark
extern const u8 gSkillRangeIconTiles[]; // 2x2 icons: proximity, remote (skill_type_is_remote); Medapart detail page
extern const u8 gBotActionIconTiles[];  // 2x2-tile icons beside each Medabot on the field (BG3 tiles 0x214+); also the
                                        // Medaparts screen. guess: action / skill type icons
extern const u8 gMedapartDetailBg0Tilemap[];
extern const u8 gMedapartDetailBg1Tilemap[];
extern const u8 gMedapartDetailBg2Tilemap[];
extern const u8 gMedapartDetailBg3Tilemap[];
extern const u16 gMedapartsListBgPalette[];                // BG palettes 0-6 of the Medaparts list
extern const u16 gMedapartDetailBgPalette[];               // BG palettes 0-6 of the Medapart detail page
extern const void *const gMedapartDetailHelpMessages[];    // messages (run_message), Medaparts detail help for head /
                                                           // arms, indexed by medapart_detail_skill_help_index()
extern const void *const gMedapartLegDetailHelpMessages[]; // messages (run_message), Medaparts detail help for legs,
                                                           // indexed by medapart_detail_skill_help_index()
extern const void *const gAbilityHelpMessages[];   // messages (run_message), ability help (e.g. "(Anti-Air) Damages Air
                                                   // Medabots greatly."), indexed by gGameWork.partAbility
extern const void *const gMedapartsHelpMessages[]; // messages (run_message), Medaparts help pages
extern const u8 gMedalsListBgTiles[];
extern const u8 gMedalsTabNumberTiles[];   // Medals list tab numbers 1-5 (runtime: blanking 0x06006000)
extern const u8 gTradeChoiceWindowTiles[]; // Details / Trade / Cancel window (runtime: tile base 0x380 of the Medaparts
                                           // trade choice)
extern const u8 gMedalsListBg0Tilemap[];
extern const u8 gMedalsListBg1Tilemap[];
extern const u8 gMedalsListBg2Tilemap[];
extern const u8 gMedalsListBg3Tilemap[];
extern const u16 gMedalsListBgPalette[];
extern const u16 gTradeChoiceWindowPalette[]; // BG palette 11 of the trade choice window
extern const u16 gCommonObjPalette[];         // OBJ palette loaded with gCommonObjTilesLz by several menus. guess
extern const u8 gMedalAbilityBgTiles[];
extern const u8 gMedalAbilityBg0Tilemap[];
extern const u8 gMedalAbilityBg1Tilemap[];
extern const u8 gMedalAbilityBg2Tilemap[];
extern const u8 gMedalAbilityBg3Tilemap[];
extern const u16 gMedalAbilityBgPalette[];
extern const u8 gMedalMedaforceBgTiles[];
extern const u8 gMedaforceTypeIconTiles[]; // Medaforce page type icons next to each Medaforce (runtime)
extern const u8 gMedaforceGaugeTiles[];    // Medaforce gauge pips (MF consumption; runtime on the Medaforce page)
extern const u8 gMedalMedaforceBg0Tilemap[];
extern const u8 gMedalMedaforceBg1Tilemap[];
extern const u8 gMedalMedaforceBg2Tilemap[];
extern const u8 gMedalMedaforceBg3Tilemap[];
extern const u16 gMedalMedaforceBgPalette[];
extern const u8 gMedalRotationBgTiles[];
extern const u8 gRotationActionIconTiles[]; // Rotation page action slot icons (runtime)
extern const u8 gRotationPathTiles[];       // Rotation page arrow path under the slots (runtime)
extern const u8 gMedalRotationBg0Tilemap[];
extern const u8 gMedalRotationBg1Tilemap[];
extern const u8 gMedalRotationBg2Tilemap[];
extern const u8 gMedalRotationBg3Tilemap[];
extern const u16 gMedalRotationBgPalette[];
extern const void *const gMedaforceDescMessages[];  // messages (run_message), indexed by medal_medaforce_get_selected()
extern const void *const gRotationActionMessages[]; // messages (run_message), indexed by a Medal record byte at +0x18
                                                    // (guess: rotation entries)
extern const u8 gMedabotsBgTiles[];
// BG tiles 0x300+: the 2x2 pedestals under each Medabot, picked by leg type (draw_tilemap_with_offset)
extern const u8 gLegTypePedestalTiles[];
extern const u8 gLegTypePedestalTiles2[];
extern const u8 gTeamRoleLabelTiles[]; // OBJ: "LEADER" / "PARTNER" over the team picks
extern const u8 gMedabotsBg0Tilemap[];
extern const u8 gMedabotsBg1Tilemap[];
extern const u8 gMedabotsBg2Tilemap[];
extern const u8 gMedabotsBg3Tilemap[];
extern const u16 gMedabotsBgPalette[];
extern const u16 gMenuObjPalettes[]; // OBJ palettes 0-7 of most menus (3 character palettes, then black)
extern const u16 gGradientPaletteGold[];
extern const u16 gMedabotsCursorObjPalette[];
extern const u16 gTeamRoleLabelObjPalette[];
extern const u8 gMedabotBuildBgTiles[];
extern const u8 gSmallDigitTiles[]; // small digits (Medal levels; runtime: blanking 0x06006280 on the Medals list)
extern const u8 gCompatibilityIconTiles[]; // Ability page compatibility icon (runtime)
extern const u8 gPartSlotIconTiles[];      // head / arm / legs icons beside the part names
extern const u8 gCursorArrowTiles[];       // arrow cursor OBJ tiles at 0x06017E00 (runtime: Medals list cursor)
extern const u8 gMedabotBuildBg0Tilemap[];
extern const u8 gMedabotBuildBg1Tilemap[];
extern const u8 gMedabotBuildBg2Tilemap[];
extern const u8 gMedabotBuildBg3Tilemap[];
extern const u16 gMedabotBuildBgPalette[];
extern const u16 gGradientPaletteOlive[];

extern const u8 gMedalIconTiles[];            // Medal icon tiles, 0x80 bytes per graphic index
extern const u8 gMedalIconBlankTiles[];       // blank Medal icon tile
extern const u8 *const gMedalSpriteGfx[][5];  // compressed Medal sprites (load_medal_sprite)
extern const u32 gAttributeNames[];           // Medal Attribute names, indexed by Medal record attribute (Ability page)
extern const u32 gSkillTypeNames[];           // skill type names (Shoot, Strike, ...): Medal Aim, Medaforce skill
extern const u8 *const gHelpCursorLayouts[];  // Medals / Medaparts help cursor layouts: count, then (x, y) tile pairs
                                              // (medals_help_init_cursor)
extern const u16 gMedalSkillDebugCursorPos[]; // (y, x) pairs per Medal skill row 0-7 (medal_skill_debug_init_cursor)
extern const Func
    gMedalTradeChoiceCloseSteps[];      // sprite 7 sub-state handlers, by gSpriteEntries[7].work[MEDALS_SPR_CLOSE_STEP]
                                        // (medal_trade_choice_close_step)
extern const Func gDebugMenuHandlers[]; // game state 63 sub-state handlers (debug_menu_update)
extern const Func gDebugMenuEntryHandlers[];  // game state 63: one handler per menu entry (debug_menu_run_entry)
extern const Func gDebugProcessHandlers[];    // game state 63 entry 0 sub-state handlers (debug_process_update)
extern const Func gDebugMedalHandlers[];      // entry 1 (debug_medal_update)
extern const Func gDebugPartsHandlers[];      // entry 2 (debug_parts_update)
extern const u8 *const gDebugMenuLabels[];    // game state 63 menu labels, 11 x 8 bytes: Process, Medal, Parts, Tinpet,
                                              // Item, Face, Mdlpic, Rnd.tk, Battle, Sound, Motion
extern const u8 *const gDebugProcessLabels[]; // game state 63 "Process" field labels "User", "Func.no", "S.func"
                                              // (gGameMode / gGameState / gGameSubState; debug_process_input)
extern const u8 *const gDebugMedalLabels[];   // game state 63 "Medal" field labels (3 x 8 bytes; debug_medal_input)
extern const u8 *const gDebugPartsLabels[];   // game state 63 "Parts" field labels (3 x 8 bytes; debug_parts_input)
extern const Func gDebugTinpetHandlers[];     // game state 63 entry 3 sub-state handlers (debug_tinpet_update)
extern const Func gDebugItemHandlers[];       // entry 4 (debug_item_update)
extern const Func gDebugFaceHandlers[];       // entry 5 (debug_face_update)
extern const Func gDebugMdlpicHandlers[];     // entry 6 (debug_mdlpic_update)
extern const Func gDebugRndTkHandlers[];      // entry 7 (debug_rndtk_update)
extern const Func gDebugBattleHandlers[];     // entry 8 (debug_battle_update)
extern const Func gDebugSoundHandlers[];      // entry 9 (debug_sound_update)
extern const Func gDebugMotionHandlers[];     // entry 10 (debug_motion_update; 4 sub-states)
extern const u8 *const gDebugTinpetLabels[];  // "Get"
extern const u8 *const gDebugItemLabels[];    // "Get", "Lost", "All"
extern const u8 *const gDebugFaceLabels[];    // "No", "Look" (also used by the Mdlpic entry)
extern const u8 *const gDebugMdlpicLabels[];  // "No", "Lv" (unused: debug_mdlpic_input reads gDebugFaceLabels)
extern const u8 *const gDebugRndTkLabels[];   // "Switch"
extern const u8 *const gDebugBattleLabels[];  // "No"
extern const u8 *const gDebugSoundLabels[];   // "Se", "Bgm"
extern const u8 *const gDebugMotionLabels[];  // "No"
extern const u8
    gMedalSkillShineTiles[];        // tiles, 5 rows of 0x100 bytes, 0x20 per Medals tab (medal_skill_load_shine_frame)
extern const u32 gMedaforceNames[]; // Medaforce names, indexed by Medaforce id
extern const u32 gLegTypeNames[];   // Medapart skill names for ids >= 100 (medapart_detail_draw_skill)
extern u16 gRobattleCounts[2];      // gPlayerRecord.robattleCounts: [0] fought, [1] won (gGameWork.battleResult == 1);
                                    // capped at 9999 (runtime-checked; guess: Robattles fought / won)
extern const void *const gOpponentAfterBattleMessages[]; // after-battle opponent lines, by gBattleWork.encounterMessage
extern const void *const gBattleMessages[]; // battle message pointers (after-battle screen uses 107, 109, 118)
extern const u8 *const gPartKindNames[];    // Medapart kind names, by kind
extern const u8 gNewPartSpriteTiles[];      // LZ tiles (after-battle screen sprite 1)
extern const u8 gPartIconSpriteTiles[];     // LZ tiles (after-battle screen sprite 2)
extern const u16 gResultSpritePalettes[];   // OBJ palettes, 0x20 bytes each (also indexed by a table at 0x083AF8E8)
extern const u16 gPartIconSpritePalette[];  // OBJ palette (sprite 2)

extern const u8 *const gOpponentNames[];    // opponent names, by gBattleWork.encounterMessage
extern const u8 *const gBattlefieldNames[]; // battlefield names, by gBattleWork.battlefield
extern const u8 gAreaBattleSettings[][8];   // per area: [1] = battlefield (load_area_battlefield)
extern const u8
    gAreaRandomEncounters[][4]; // per area: random encounter ids, picked 40/30/20/10% (setup_random_encounter_enemies)
extern const u8
    *const gEncounterSetups[]; // encounter setups (0x28 bytes copied to gBattleWork), by gFieldWork.battle_id
extern const u8 gOpponentSpritePositions[][2]; // per opponent Medabot: sprite position (init_opponent_medabot_sprites)
extern const u8
    gOpponentLegIconPositions[][2];       // per opponent Medabot: leg type icon position (draw_opponent_leg_type_icons)
extern const u8 gRandomBotSlotStarts[16]; // random starting opponent slot 0-2 (afterbattle_pick_unowned_part,
                                          // battle_pick_random_bot_part)
extern const u8 gBattlefieldParams[][8];  // per battlefield (battlefield_load_params)
extern const Func gRobattleHandlers[];    // game state 7 (Robattle) sub-state handlers
extern const void
    *const gBattlefieldGraphics[];       // 5 compressed graphics pointers per battlefield (gBattleWork.battlefield)
extern const u16 gPartsMenuObjPalette[]; // OBJ palette 10 for the Medaparts command (robattle_parts_menu_open)
extern const u16 gActionFlashPalette[];  // Robattle palette (OBJ palette 6, robattle_parts_menu_open)
extern const u16 gBattleObjPalette10[];  // OBJ palette 10 (battle_load_graphics_step, robattle)
extern const u16 gMfMenuObjPalette[];    // OBJ palette 10 for the MF command (robattle_mf_menu_open)

extern const u8 gStatusScreenBgTilesLz[];   // battle team status screen BG tiles (LZ77)
extern const u8 gStatusScreenCornerTiles[]; // 8 rounded panel corner tiles (LZ77)
extern const u8 gSlashTiles[];              // 2-tile "/" (LZ77)
extern const u8 gStatusScreenBg0Tilemap[];  // status screen BG0-BG3 tilemaps
extern const u8 gStatusScreenBg1Tilemap[];
extern const u8 gStatusScreenBg2Tilemap[];
extern const u8 gStatusScreenBg3Tilemap[];
extern const u16 gStatusScreenBgPalettes[]; // 14 BG palettes

extern const u8 gBattleBannerTilesLz[];  // ROBATTLE start / win / time-up banner OBJ tiles (LZ77)
extern const u16 gBattleBannerPalette[]; // its OBJ palette 15

extern const u16 gGradientPaletteOrange[];

extern const u8 gBattleBg3TilemapLz[];  // Robattle screen tilemaps (compressed)
extern const u8 gLeftBotPanelTilemap[]; // left (player side) Medabot name panel at (0,13), tiles gLeftBotPanelTiles
extern const u8
    gMedaforceGaugeFrameTilemap[]; // Medaforce gauge strip at (0,17) / (20,17), tiles gMedaforceGaugeFrameTiles
extern const u8 gActionSelectPanelTilemap[];     // action select center panel at (12,15), tiles gActionSelectPanelTiles
extern const u8 gActionSelectSidePanelTilemap[]; // panel drawn at (20,16) with the action select panel. guess: role not
                                                 // seen at runtime
extern const u8 *const gCommandRingNames[];      // 12-byte name text, by gBattleWork.ringSlot (command_ring_draw_name)
extern const u8 gCommandRingIconAngles[];        // angles for compute_polar_to_screen_position, by sprite slot -
                                                 // gBattleWork.ringSlot (command_ring_init_icon)
extern const u8 gCommandRingNextSlotRight[];     // next slot after a right turn of the ring, by gBattleWork.ringSlot
                                                 // (command_ring_input)
extern const u8 gCommandRingNextSlotLeft[];      // next slot after a left turn
extern const u8 gBotPointerLineParams[];   // 4-byte records: sprite count, start value, x, y (bot_pointer_line_init,
                                           // bot_pointer_line_animate)
extern const u8 gPartSelectCenterFrames[]; // part select: centre sprite frame by gBattleWork.partCursor
                                           // (part_select_init_center_icon)
// Part / MF menu messages: Damaged, Unusable, Used Up, Charge MF, MF low, Unmastered
extern const u8 *const gBattleMenuTexts[];
// names by part skill id (part data[1]; part_select_draw_skill_name)
extern const u32 gSkillNames[]; // skill name text pointers, by skill id (SKILL_*)
extern const u8
    gPartsMenuLeftPanelTilemap[]; // command ring parts menu, left panel (BG0, action name, e.g. "Charge MF")
extern const u8 gPartsMenuRightPanelTilemap[]; // command ring parts menu, right panel (BG1)
extern const u8 gMfMenuLeftPanelTilemap[];     // Medaforce menu, left panel (BG0)
extern const u8 gMfMenuRightPanelTilemap[];    // Medaforce menu, right panel (BG1)
extern u8 gBgTileBackupHigh[];                 // BG tile backup, second half (see gBgTileBackup)
extern const u8 gCommandRingSubStates[];       // Robattle sub-state per command ring slot (command_ring_goto_selected)
extern const u8
    gTeamBotScreenPositions[]; // battle bot screen positions (x, y) per record 0-5 (position_battle_team_cursors)

extern const u32 gTitleMenuBlendAlphas[];   // BLDALPHA values by fade step / 8 (title_menu_blend_step)
extern const u16 gSaveScreenSpriteFrames[]; // sprite 0 tile by (frame >> 3) & 3 (save_screen_animate_sprite)
extern const u16 gNameEntrySpriteFrames[];  // sprite 20 tile by (frame >> 3) & 3 (name_entry_animate_sprite)

extern u8 gListScrollTop;                        // first visible list entry (update_list_scroll_arrows)
extern struct Vec16 gScanlineScrollEven[160][4]; // per-scanline BG0-3 scroll, even frames (start_scanline_wave_scroll)
extern struct Vec16 gScanlineScrollOdd[160][4];  // per-scanline BG0-3 scroll, odd frames (start_scanline_wave_scroll)

extern struct SaveStatus gSaveStatus;
extern const u8 gSaveMagic[17]; // save file signature (serialize_save_data, validate_save_data)
extern const u8
    gSaveMagicErased[17]; // written by save_dispatch(2) instead of gSaveMagic, so validate_save_data rejects the save

extern const void
    *const gSystemMessages[]; // shared menu messages: test mode, shop, save screen, Medal rename, Medal level-up
extern const void
    *const gLinkMenuMessages[]; // link menu / link start / link trade messages (save_screen_ask_overwrite uses 18)
extern const Func gSaveScreenStates[15]; // save screen states, by gGameSubState (save_screen_update): 6 stops the
                                         // music, 7 writes the save, 8 / 12 show the result

extern const u8 gSaveScreenBg1Tilemap[]; // save screen BG1 tilemap (LZ77, decompress_and_write_tilemap)
extern const u8 gSaveScreenBg2Tilemap[]; // save screen BG2 tilemap
extern const u8 gSaveScreenBg3Tilemap[]; // save screen BG3 tilemap
extern const u32 gSaveScreenBgTiles[];   // save screen BG tiles (dma3_copy_or_decompress)
extern const u8 gTownMapBg1Tilemap[];    // town map BG1-BG3 tilemaps
extern const u8 gTownMapBg2Tilemap[];
extern const u8 gTownMapBg3Tilemap[];
extern const u32 gTownMapBgTiles[];      // town map BG tiles (dma3_copy_or_decompress)
extern const u8 gTownMapBgPalettes[];    // 14 BG palettes
extern const u8 gTownMapObjPalettes[];   // 3 OBJ palettes
extern const u8 gAreaTownMapPlace[];     // town map place by area id (gFieldWork.area_id, town_map_load_graphics)
extern const u32 gTownMapAnimTiles[];    // animated BG tile frames, 480 bytes each (town_map_animate_tiles)
extern const u8 *gDefaultPlayerName;     // -> "Ikki" (stored in the tail of gNameEntryStates), name entry mode 0
extern const u16 gNameEntryObjPalette[]; // name entry OBJ palette (name_entry_load_name)
extern const u16 gNameEntryBgPalettes[]; // name entry BG palettes (name_entry_load_name)
extern const u8
    gMenuDigitTilesLz[]; // digit tiles loaded after a menu's BG tiles (draw_number uses bg_tile_base + 0x16; LZ77)
extern const u8
    gMenuObjTilesLz[]; // OBJ tiles shared by the menus (save, shop, item, name entry, link, title, test mode; LZ77)

extern const Func gTitleMenuStates[]; // state handlers by gGameSubState (title_menu_update)

extern const u8 gTitleMenuBg0Tilemap[];    // title menu BG0 tilemap (LZ77, decompress_and_write_tilemap)
extern const u8 gTitleMenuBg1Tilemap[];    // title menu BG1 tilemap
extern const u8 gTitleMenuBg2Tilemap[];    // title menu BG2 tilemap
extern const u8 gTitleMenuBg3Tilemap[];    // title menu BG3 tilemap
extern const u32 gTitleMenuBgTiles[];      // title menu BG tiles (dma3_copy_or_decompress)
extern const u8 gSaveLostBg0Tilemap[];     // BG0 tilemap (LZ77, save_lost_load_graphics)
extern const u8 gSaveLostBg1Tilemap[];     // BG1 tilemap (LZ77, save_lost_load_graphics)
extern const u8 gSaveLostBg3Tilemap[];     // BG3 tilemap (LZ77, save_lost_load_graphics)
extern const u32 gSaveLostBgTiles[];       // BG tiles (dma3_copy_or_decompress, save_lost_load_graphics)
extern const u16 gSaveLostBgPalette[];     // BG palette (save_lost_load_graphics)
extern const u16 gSaveLostSpritePalette[]; // OBJ palette 0 (save_lost_load_graphics)
extern const u8
    gCommonObjTilesLz[]; // OBJ tiles shared by town map, save lost, game over, Medal level-up, text scroll (LZ77)
extern const u8 gShopMenuPanelTilemap1[]; // BG1 tilemap (LZ77, shop_menu_load_graphics)
extern const u8 gShopMenuPanelTilemap2[]; // BG2 tilemap (LZ77, shop_menu_load_graphics)
extern const u8 gShopMenuBg1Tilemap[];    // BG1 tilemap (LZ77, shop_menu_load_graphics)
extern const u8 gShopMenuBg2Tilemap[];    // BG2 tilemap (LZ77, shop_menu_load_graphics)
extern const u8 gShopMenuBg3Tilemap[];    // BG3 tilemap (LZ77, shop_menu_load_graphics)
extern const u32 gShopMenuBgTiles[];      // BG tiles (dma3_copy_or_decompress, shop_menu_load_graphics)
extern const u32 gShopMenuBgTiles2[];     // BG tiles (dma3_copy_or_decompress, shop_menu_load_graphics)
extern const u8 gGameOverBg0Tilemap[];    // BG0 tilemap (LZ77, game_over_load_graphics)
extern const u8 gGameOverBg2Tilemap[];    // BG2 tilemap (LZ77, game_over_load_graphics)
extern const u8 gGameOverBg3Tilemap[];    // BG3 tilemap (LZ77, game_over_load_graphics)
extern const u32 gGameOverBgTiles[];      // BG tiles (dma3_copy_or_decompress, game_over_load_graphics)
extern const u16 gGameOverBgPalette[];    // BG palette (game_over_load_graphics)
extern const u16 gGameOverObjPalettes[];  // OBJ palettes 0-1 (game_over_load_graphics)
extern const u16 gGameOverIkkiFrames[];   // sprite 1 animation frames, by timer / 6 (game_over_logo_drop)
extern const s8 gGameOverLogoBounce[];    // sprite 0 y offsets, 13 steps (game_over_logo_drop)
extern const u16 gTitleMenuBgPalette[];   // title menu BG palette (0x100 colors)
extern u8 gOptionTimeLimit;               // picks the Robattle TIME limit: 0 = 40, 1 = 30, 2 = 20 (robattle_time_init)
extern u8 gOptionBattleMusic;             // index into gBattleSongs (battle music)
extern const u8 gBattleSongs[];           // battle song ids (select_battle_music)
// Per leg type (skill id - 100), 11 bytes: one per battlefield (gBattleWork.battlefield); added to moveDelay
// (bot_move_delay_add_terrain).
extern const u8 gTerrainMoveDelays[];
extern const s8 gNumberPopupYSteps[]; // 32 y steps of the number pop-up over a Medabot (battle_number_popup_update)
extern const u8 gRandomBotOrder[];    // 32 random record orders (find_next_active_bot)
extern const u8
    gLinkBotRecordSwap[]; // record remap when gLinkPlayerId is set in a link Robattle (find_next_active_bot)
extern const u8 gTargetSwapSideTable[];              // record + 1 -> same slot on the other side (bot_target_swap_side)
extern const struct GfxListEntry *const gGfxLists[]; // graphics lists (decompress_indexed_graphics_to_ewram)
extern const void *const gGfxListData[];             // pairs: compressed tiles [i * 2], palette [i * 2 + 1]
extern const Func gBattleMessageSteps[];   // message steps by gBattleWork.messageStep[0] (battle_message_show)
extern const Func gMissPopupSteps[];       // steps by gBattleWork.substep[0] (miss_popup_run)
extern const Func gTargetPanelSteps[];     // steps by gBattleWork.substep[0] (target_panels_show)
extern const Func gTrapHitSteps[];         // by gBattleWork.step (trap_hit_run)
extern const Func gActionPartCheckSteps[]; // by gBattleWork.step (action_part_check_run)
extern const Func gTargetPartCheckSteps[]; // by gBattleWork.step (target_part_check_run)
extern const Func gActionFlashSteps[];     // by gBattleWork.step (action_flash_run)
extern const Func gGuardSteps[];           // by gBattleWork.step (guard_run)
extern const Func gActionAnnounceSteps[];  // by gBattleWork.step (action_announce_run)
extern const Func gCloseupEnterSteps[];    // by gBattleWork.step (closeup_enter_run)
extern const Func gAttackHitSteps[];       // by gBattleWork.step (attack_hit_run)
extern const u8 gMissPopupTiles[];         // compressed OBJ tiles (miss_popup_load)
extern const u16 gMissPopupPalette[];      // OBJ palette (miss_popup_load)
extern const u16 gTargetLinePalette[];     // OBJ palette 8 (target_panels_line_init)
extern const u16 gTargetArrowsPalette[];   // OBJ palette 9 (target_panels_arrows_init)
extern const u8 gGrapTrapTiles[];          // compressed OBJ tiles, trap_hit_load_graphics case 0
extern const u8 gShotTrapTiles[];          // case 1
extern const u8 gAttackClrTrapTiles[];     // case 2
extern const u8 gMedaforceTrapTiles[];     // case 3
extern const u16 gGrapTrapPalette[];       // OBJ palettes for the same cases
extern const u16 gShotTrapPalette[];
extern const u16 gAttackClrTrapPalette[];
extern const u16 gMedaforceTrapPalette[];
extern const u8 gBreakRingTiles[];        // compressed OBJ tiles (trap_hit_break_cursor_init)
extern const u16 gBreakRingPalette[];     // its OBJ palette (palette 7)
extern const u8 gHitSparksTiles[];        // compressed OBJ tiles (trap_hit_break_burst_init)
extern const u16 gHitSparksPalette[];     // its OBJ palette (palette 7)
extern const u16 gActionFlashPalette[];   // OBJ palette 6 (action_flash_load_palette)
extern const u8 gDefenceShieldTiles[];    // compressed OBJ tiles, guard_load_graphics for guardSkill 0x1B
extern const u8 gFullBlockShieldTiles[];  // 0x1C
extern const u8 gHalfBlockShieldTiles[];  // 0x1D
extern const u16 gDefenceShieldPalette[]; // their OBJ palettes
extern const u16 gFullBlockShieldPalette[];
extern const u16 gHalfBlockShieldPalette[];
extern const u8 gRightBotPanelTilemap[]; // right (opponent side) Medabot panel at (18,13), tiles gRightBotPanelTiles
extern u8 gOptionSkipMessages; // Robattle: nonzero skips the message windows unless gGameWork.skipBotSetup == 1
                               // (battle_message_open..battle_message_finish)
extern const u8 gMfChargeSparklePalette[]; // 32-byte OBJ palette, copied to OBJ palette 6 (mf_charge_sparkles_init)
extern u32 gBattleWorkActionVars[16];      // = (u8 *)&gBattleWork + 0xA8: the per-action fields, cleared as words
                                           // (battle_action_cleanup, reset_bot_status_and_init_palette_transfers)
extern const u8 gGaugeFillTiles[];         // 9 tiles: an 8-px bar segment filled 0..8. guess: gauge fill steps
extern const u8
    gArmorPanelDecorTilesLz[]; // compressed BG tiles, 6 small frame pieces (attack_hit_load_graphics). guess
extern const u8 gArmorPanelPartIconTilesLz[];   // compressed BG tiles, 2x2 part icons (attack_hit_load_graphics). guess
extern const u8 gArmorPanelDecorPalette[];      // BG palette 10 (attack_hit_load_graphics)
extern const u8 gArmorPanelGaugePalette[];      // BG palette 8 (attack_hit_load_graphics). guess: armor gauge
extern const u8 gArmorPanelPartIconPalette[];   // BG palette 11 (attack_hit_load_graphics)
extern const u8 gCriticalHitTiles[];            // compressed OBJ tiles (battle/action_steps)
extern const u8 gCriticalHitPalette[];          // OBJ palette (battle/action_steps)
extern const u8 gDestroyMarkerTiles[];          // compressed OBJ tiles (battle/action_steps)
extern const u8 gDestroyMarkerPalette[];        // OBJ palette (battle/action_steps)
extern const u8 gHeadMarkerTiles[];             // compressed OBJ tiles (battle/action_steps)
extern const u8 gHeadMarkerPalette[];           // OBJ palette (battle/action_steps)
extern const u8 gRightArmMarkerTiles[];         // compressed OBJ tiles (battle/action_steps)
extern const u8 gRightArmMarkerPalette[];       // OBJ palette (battle/action_steps)
extern const u8 gLeftArmMarkerTiles[];          // compressed OBJ tiles (battle/action_steps)
extern const u8 gLeftArmMarkerPalette[];        // OBJ palette (battle/action_steps)
extern const u8 gLegsMarkerTiles[];             // compressed OBJ tiles (battle/action_steps)
extern const u8 gLegsMarkerPalette[];           // OBJ palette (battle/action_steps)
extern const u8 gDamageNumberTiles[];           // compressed OBJ tiles (battle/action_steps)
extern const u8 gDamageNumberPalette[];         // OBJ palette (battle/action_steps)
extern const u8 gPartBreakBurstTiles[];         // compressed OBJ tiles (battle/action_steps)
extern const u8 gPartBreakBurstPalette[];       // OBJ palette (battle/action_steps)
extern const u8 gCarryOverMarkerTiles[];        // compressed OBJ tiles (battle/action_steps)
extern const u8 gCarryOverMarkerPalette[];      // OBJ palette (battle/action_steps)
extern const u8 gAttackMissTiles[];             // compressed OBJ tiles (battle/action_steps)
extern const u8 gAttackMissPalette[];           // OBJ palette (battle/action_steps)
extern const u8 gAttackNullifiedTiles[];        // compressed OBJ tiles (battle/action_steps)
extern const u8 gAttackNullifiedPalette[];      // OBJ palette (battle/action_steps)
extern const u8 gAttackAbsorbedTiles[];         // compressed OBJ tiles (battle/action_steps)
extern const u8 gAttackAbsorbedPalette[];       // OBJ palette (battle/action_steps)
extern const u8 gAbsorbSparkleTiles[];          // compressed OBJ tiles (battle/action_steps)
extern const u8 gAbsorbSparklePalette[];        // OBJ palette (battle/action_steps)
extern const u8 gHealNumberPalette[];           // OBJ palette (battle/action_steps)
extern const Func gStatusAttackSteps[];         // by gBattleWork.step (status_attack_run)
extern const u8 gStatusFlashTiles[];            // compressed OBJ tiles (battle/action_steps)
extern const u8 gStatusFlashPalette[];          // OBJ palette (battle/action_steps)
extern const u8 gBugEffectTiles[];              // compressed OBJ tiles (battle/action_steps)
extern const u8 gBugEffectPalette[];            // OBJ palette (battle/action_steps)
extern const u8 gThunderEffectTiles[];          // compressed OBJ tiles (battle/action_steps)
extern const u8 gThunderEffectPalette[];        // OBJ palette (battle/action_steps)
extern const u8 gWaveEffectTiles[];             // compressed OBJ tiles (battle/action_steps)
extern const u8 gWaveEffectPalette[];           // OBJ palette (battle/action_steps)
extern const u8 gFireEffectTiles[];             // compressed OBJ tiles (battle/action_steps)
extern const u8 gFireEffectPalette[];           // OBJ palette (battle/action_steps)
extern const u8 gBugIconTiles[];                // compressed OBJ tiles (battle/action_steps)
extern const u8 gBugIconPalette[];              // OBJ palette (battle/action_steps)
extern const u8 gThunderIconTiles[];            // compressed OBJ tiles (battle/action_steps)
extern const u8 gThunderIconPalette[];          // OBJ palette (battle/action_steps)
extern const u8 gWaveIconTiles[];               // compressed OBJ tiles (battle/action_steps)
extern const u8 gWaveIconPalette[];             // OBJ palette (battle/action_steps)
extern const u8 gFireIconTiles[];               // compressed OBJ tiles (battle/action_steps)
extern const u8 gFireIconPalette[];             // OBJ palette (battle/action_steps)
extern const Func gCloseupExitSteps[];          // by gBattleWork.step (closeup_exit_run)
extern struct UiTilemapTable gUiTilemapsNamed;  // same address as gUiTilemaps
extern const Func gBotDefeatSteps[];            // by gBattleWork.step (bot_defeat_run)
extern const u8 gReactionRiseTiles[];           // compressed OBJ tiles (battle/action_steps)
extern const u8 gReactionRiseFxTiles[];         // compressed OBJ tiles (battle/action_steps)
extern const u8 gReactionNullifyTiles[];        // compressed OBJ tiles (battle/action_steps)
extern const u8 gReactionAbsorbTiles[];         // compressed OBJ tiles (battle/action_steps)
extern const u8 gReactionRisePalette[];         // OBJ palette (battle/action_steps)
extern const u8 gReactionRiseFxPalette[];       // OBJ palette (battle/action_steps)
extern const u8 gReactionNullifyPalette[];      // OBJ palette (battle/action_steps)
extern const u8 gReactionAbsorbPalette[];       // OBJ palette (battle/action_steps)
extern const Func gReactionSteps[];             // by gBattleWork.step (reaction_run)
extern const Func gSacrificeSteps[];            // by gBattleWork.step (sacrifice_run)
extern const Func gDestroyCheckSteps[];         // by gBattleWork.step (destroy_check_run)
extern const Func gRecoverySteps[];             // by gBattleWork.step (recovery_run)
extern const Func gRecoveryHealSteps[];         // by gBattleWork.step (recovery_heal_run)
extern const Func gRepairSteps[];               // by gBattleWork.step (repair_run)
extern const Func gRepairApplySteps[];          // by gBattleWork.step (repair_apply_run)
extern const Func gTrapSteps[];                 // by gBattleWork.step (trap_run)
extern const Func gBreakFormSteps[];            // by gBattleWork.step (break_form_run)
extern const u8 gSkillCastHopTiles[];           // compressed tiles (battle skill effects)
extern const u8 gSkillCastHopPalette[];         // 32-byte OBJ palette (battle skill effects)
extern const u8 gTeamAttackTurretTilesLz[];     // compressed tiles (interrupt skill effect)
extern const u8 gTeamAttackTurretPalette[];     // 32-byte OBJ palette (interrupt skill effect)
extern const u8 gBreakFormTilesLz[];            // compressed OBJ tiles (break_form_sprite_spawn)
extern const u8 gBreakFormPalette[];            // OBJ palette 7 (break_form_sprite_spawn)
extern const Func gStabilitySteps[];            // by gBattleWork.step (stability_run)
extern const Func gForceBindSteps[];            // by gBattleWork.step (force_bind_run)
extern const Func gDefenceSteps[];              // by gBattleWork.step (defence_run)
extern const u8 gStabilitySparkleTiles[];       // compressed tiles (battle skill effects)
extern const u8 gStabilitySparklePalette[];     // 32-byte OBJ palette (battle skill effects)
extern const u8 gForceBindOrbTilesLz[];         // compressed OBJ tiles (force_bind_orbs_spawn)
extern const u8 gForceBindOrbPalette[];         // OBJ palette 7 (force_bind_orbs_spawn)
extern const Func gAutoRecoverSteps[];          // by gBattleWork.step (autorecover_run)
extern const u8 gAutorecoverOrbTilesLz[];       // compressed OBJ tiles (autorecover_orb_spawn)
extern const u8 gAutorecoverOrbPalettes[];      // OBJ palettes 6-7 (autorecover_orb_spawn)
extern const Func gReactivateSteps[];           // by gBattleWork.step (reactivate_run)
extern const u8 gReactivateOrbTilesLz[];        // compressed OBJ tiles (reactivate_orb_spawn)
extern const u8 gReactivateOrbPalettes[];       // OBJ palettes 6-7 (reactivate_orb_spawn)
extern const Func gScoutSteps[];                // by gBattleWork.step (scout_run)
extern const u8 gScoutTilesLz[];                // compressed OBJ tiles (scout_load_graphics)
extern const u8 gScoutPalettes[];               // OBJ palettes 6-7 (scout_load_graphics)
extern const Func gConcealSteps[];              // by gBattleWork.step (conceal_run)
extern const u8 gConcealDomeTiles[];            // compressed tiles (battle skill effects)
extern const u8 gConcealDomePalette[];          // 32-byte OBJ palette (battle skill effects)
extern const Func gBoostChargeSteps[];          // by gBattleWork.step (boost_charge_run)
extern const u8 gChargeHourglassTiles[];        // compressed tiles (battle skill effects)
extern const u8 gChargeHourglassPalette[];      // 32-byte OBJ palette (battle skill effects)
extern const Func gRapidChargeSteps[];          // by gBattleWork.step (rapid_charge_run)
extern const u8 gRapidChargeHourglassTilesLz[]; // compressed OBJ tiles (rapid_charge_hourglass_spawn)
extern const u8 gRapidChargeHourglassPalette[]; // OBJ palette 7 (rapid_charge_hourglass_spawn)
extern const Func gDrainChargeSteps[];          // by gBattleWork.step (drain_charge_run)
extern const u8 gDrainChargeHourglassTilesLz[]; // compressed OBJ tiles (drain_charge_hourglass_spawn)
extern const u8 gDrainChargeHourglassPalette[]; // OBJ palette 7 (drain_charge_hourglass_spawn)
extern const Func gPushoverSteps[];             // by gBattleWork.step (pushover_run)
extern const u8 gPushoverBananaTiles[];         // compressed tiles (battle skill effects)
extern const u8 gPushoverBananaPalette[];       // 32-byte OBJ palette (battle skill effects)
extern const u8
    gBurstSpriteDirections[];     // 4 bytes, sprite work[SPR_MOTION_ROW] for slots 0x26-0x29 (pushover_burst_spawn)
extern const Func gImpairSteps[]; // by gBattleWork.step (impair_run)
extern const u8 gImpairPortraitTiles[];             // compressed tiles (battle skill effects)
extern const u8 gImpairPortraitPalette[];           // 32-byte OBJ palette (battle skill effects)
extern const u8 gConfusionBallTilesLz[];            // compressed tiles (interrupt skill effect)
extern const u8 gConfusionBallPalettes[];           // 64-byte OBJ palettes (interrupt skill effect)
extern const Func gConfusionSteps[];                // by gBattleWork.step (confusion_run)
extern const Func gUseDrainSteps[];                 // by gBattleWork.step (use_drain_run)
extern const u8 gDrainBubbleTilesLz[];              // compressed tiles (interrupt skill effect)
extern const u8 gDrainBubblePalettes[];             // 64-byte OBJ palettes (interrupt skill effect)
extern const u8 gBattlePopupDigitTiles[];           // compressed tiles (battle skill effects)
extern const Func gNoEscapeDefenseSteps[];          // by gBattleWork.step (no_escape_defense_run)
extern const u8 gNoEscapeIconTilesLz[];             // compressed tiles (interrupt skill effect)
extern const u8 gNoEscapeIconPalette[];             // 32-byte OBJ palette (interrupt skill effect)
extern const u8 gDefenseIconTilesLz[];              // compressed tiles (interrupt skill effect)
extern const u8 gDefenseIconPalette[];              // 32-byte OBJ palette (interrupt skill effect)
extern const Func gForcedrainSteps[];               // by gBattleWork.step (forcedrain_run)
extern const u8 gForcedrainGlassTiles[];            // compressed tiles (battle skill effects)
extern const u8 gForcedrainGlassPalettes[];         // 32-byte OBJ palette (battle skill effects)
extern const Func gTeamAttackCheckSteps[];          // by gBattleWork.step (team_attack_check_run)
extern const Func gTeamAttackTurretSteps[];         // by gBattleWork.step (team_attack_turrets_run)
extern const Func gCounterAttackSteps[];            // by gBattleWork.step (counter_attack_run)
extern const u8 gCounterAttackBallTilesLz[];        // compressed tiles (interrupt skill effect)
extern const u8 gCounterAttackBallPalette[];        // 32-byte OBJ palette (interrupt skill effect)
extern const Func gChangeSteps[];                   // by gBattleWork.step (change_run)
extern const u8 gChangeEffectTilesLz[];             // compressed tiles (interrupt skill effect)
extern const u8 gChangeEffectPalettes[];            // 64-byte OBJ palettes (interrupt skill effect)
extern const Func gMedaforceSpiralBoltSteps[];      // by gBattleWork.step (medaforce_spiral_bolt_run)
extern const Func gMedaforceHitSteps[];             // by gBattleWork.step (medaforce_hit_run)
extern const Func gMedaforceLifeDrainHealSteps[];   // by gBattleWork.step (medaforce_life_drain_heal_run)
extern const Func gMedaforceSideBoltSteps[];        // by gBattleWork.step (medaforce_side_bolt_run)
extern const u8 gMedaforceSideBoltTiles[];          // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceSideBoltPalette[];        // 64-byte OBJ palettes (battle/medaforce_effects)
extern const Func gMedaforceFormSteps[];            // by gBattleWork.step (medaforce_form_run)
extern const Func gMedaforceAntiAttackTrapSteps[];  // by gBattleWork.step (medaforce_anti_attack_trap_run)
extern const u8 gMedaforceFormEmblemTiles[];        // compressed tiles (battle/medaforce_effects)
extern const u8 gEffectCommonPalette[];             // 64-byte OBJ palettes shared by many skill and Medaforce effects
extern const u8 gMedaforceOpticFormTiles[];         // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceOpticFormPalette[];       // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceBombFormTiles[];          // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceBombFormPalette[];        // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceGravityFormTiles[];       // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceGravityFormPalette[];     // 64-byte OBJ palettes (battle/medaforce_effects)
extern const Func gMedaforceCancelFormationSteps[]; // by gBattleWork.step (medaforce_cancel_formation_run)
extern const u8 gMedaforceCancelFormationTiles[];   // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceCancelFormationPalette[]; // 64-byte OBJ palettes (battle/medaforce_effects)
extern const Func gMedaforceInflictStatusSteps[];   // by gBattleWork.step (medaforce_inflict_status_run)
extern const u8 gMedaforceMovementEmblemTiles[];    // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceMovementEmblemPalette[];  // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceStopEmblemTiles[];        // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceStopEmblemPalette[];      // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceBindEmblemTiles[];        // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceBindEmblemPalette[];      // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceFlowEmblemTiles[];        // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceFlowEmblemPalette[];      // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceChaosEmblemTiles[];       // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceChaosEmblemPalette[];     // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u16 gBattleObjPalette5[];              // OBJ palette 5 (battle_load_graphics_step)
extern const u8 gBattleObjPalettes13[];             // 3 OBJ palettes, 13-15 (battle_load_graphics_step)
extern const u16 gBattleBgPalette13[];              // BG palette 13: gauge fill / MF label tiles
extern const u16 gBattleBgPalette12[];              // BG palette 12: left Medabot panel, menu panels
extern const u16 gBattleBgPalette11[];              // BG palette 11: right Medabot panel, parts menu left panel
extern const u16 gBattleBgPalette10[];              // BG palette 10: Medaforce gauge frame / label
extern const u16 gBattleBgPalette8[];               // BG palette 8: center pillar, Medabot icons (BG3)
extern const u8 gBattleMarkerAltTilesLz[];          // OBJ tiles at 0x06014200, 48 small marks in 4 colours
                                                    // (battle_load_graphics_step). guess
extern const u8
    gBattleMarkerTilesLz[]; // OBJ tiles at 0x06013C00, 48 small marks in 4 colours (battle_load_graphics_step). guess
extern const u8 gBattleNumberSpriteTiles[];     // OBJ 0x06013000: digits 0-9, + and -, hit effect frames. guess
extern const u8 gLeftBotPanelTiles[];           // VRAM 0x06004B00 (tile 0x258)
extern const u8 gActionSelectSidePanelTiles[];  // VRAM 0x06004800 (tile 0x240)
extern const u8 gActionSelectPanelTiles[];      // VRAM 0x06004600 (tile 0x230)
extern const u8 gBotShadowTiles[];              // OBJ 0x06017F80, 4 dithered tiles. guess: shadow under a Medabot
extern const u8 gBattleUiSpriteTiles[];         // OBJ 0x06012000: battle cursors, MF / F / ! badges, TIME label
extern const u8 gPartsMenuRightPanelTiles[];    // VRAM 0x06005A00 (tile 0x2D0)
extern const u8 gMfMenuRightPanelTiles[];       // VRAM 0x06005700 (tile 0x2B8); same data as gMfMenuLeftPanelTiles
extern const u8 gMfMenuLeftPanelTiles[];        // VRAM 0x06005400 (tile 0x2A0)
extern const u8 gPartsMenuLeftPanelTiles[];     // VRAM 0x06005100 (tile 0x288)
extern const u8 gRightBotPanelTiles[];          // VRAM 0x06004E00 (tile 0x270)
extern const u8 gBattlePillarCapTiles[];        // BG3 0x0600C600, two framed boxes. guess: pillar ends
extern const u8 gBattlePillarTiles[];           // BG3 0x0600C000: the column in the middle of the battlefield
extern const u8 gMedaforceGaugeFrameEndTiles[]; // VRAM 0x06004300 (tile 0x218). guess: gauge frame end
extern const u8 gMedaforceGaugeFrameTiles[];    // VRAM 0x06004200 (tile 0x210)
extern const u8 gMedaforceLabelTiles[];         // "MF>" label, two colors (VRAM 0x06004140)
// buff sprite params (= gStatusSpriteParams[10..11]): 4 bytes copied to gGameWork.partAbility, palette, x offset + 4
extern const u8 gBuffSpriteParams[][4];
// status / action sprite params, 4 bytes each, by status kind (battle_setup_part_sprite reads them)
extern const u8 gStatusSpriteParams[][4];
extern const u16 gStaggeredSpriteOffsets[]; // (x, y) per sprite of the staggered burst (staggered_sprites_spawn)
extern const u8 *const
    gPortraitTiles[][9]; // message window portraits: LZ tiles by character and expression (message_portrait_anim_step)
extern const u16 *const gPortraitPalettes[]; // one palette per portrait character (decompress_indexed_asset)
extern const u16 gTextWindowObjPalette[];    // text window OBJ palette (text_window_init)
extern const u8 gMessageWindowTilemap[];     // LZ text window graphics (text/message)
extern const u8 gMessageWindowIconTiles[];   // guess: 2-tile LZ icon at BG tile 0xBC, loaded with the text window
extern const u8 gMessageWindowTiles[];       // LZ text window graphics (text/message)
extern const u16 gPrizeGameObjPalettes[];    // OBJ palettes (link Robattle screen, prize_game_load)
extern const u16 gPrizeGameBgPalettes[];     // BG palettes (link Robattle screen, prize_game_load)
extern const u8 gPrizeGameBg3Tilemap[];      // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gPrizeGameBg2Tilemap[];      // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gPrizeGameBg1Tilemap[];      // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gPrizeGameBg0Tilemap[];      // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gPrizeGameObjTiles[];        // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gPrizeGameBgTiles3[];        // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gPrizeGameBgTiles2[];        // LZ graphics (link Robattle screen, prize_game_load)
extern const u8 gPrizeGameBgTiles[];         // LZ graphics (link Robattle screen, prize_game_load)
extern const s16
    gBattleSeqWaveOffsets[]; // y offsets by sprite work[SEQ_EFFECT_WAVE_STEP] (0-31; battle_seq_spr_effect_wave)
extern const u8
    gBattleBg3ParallaxShift[]; // BG3 parallax shift by battlefield gBattleWork.battlefield (battle_seq_spr_actor_dash)
extern const Func
    gBattleSeqSpriteHandlers[]; // sprite handlers by work[SEQ_SPR_STATE], slots 1-0x27 (battle_sequence_update_sprites)
extern const u8 *const gBattleSeqEwramGfx[]; // pairs: compressed OBJ tiles (lz_decompress to 0x02000000), OBJ palette
                                             // 14 (battle_seq_cmd_load_effect_gfx_ewram)
extern const struct Unk_083AF94C gBattleSeqEffectSetPos[]; // 4 sprite positions (battle_seq_cmd_spawn_effect_set)
extern const Func
    gParticleSweepHandlers[]; // sweep particle states by sprite work[PARTICLE_STATE] (particle_run_sweep_handlers)
extern const u16 gParticleTrailOffsets[]; // 4 (x, y) trail offsets, x and y picked by separate rng & 3 rolls
extern const u16 gParticleSparkOffsets[]; // 4 (x, y) spark offsets from the emitter, picked by rng & 3
extern const u8 gChangeHeadPartIds[]; // Change family (actor part data[1] - 0x37 = 0-4: Change, ItrpChange, AttkChange,
// DEF Change, HealChange): 128 (Change) or 64 random part ids per acting part (head, right arm, left arm) that
// pick_random_change_part draws from
extern const u8 gChangeRightArmPartIds[];
extern const u8 gChangeLeftArmPartIds[];
extern const u8 gItrpChangeHeadPartIds[];
extern const u8 gItrpChangeRightArmPartIds[];
extern const u8 gItrpChangeLeftArmPartIds[];
extern const u8 gAttackChangeHeadPartIds[];
extern const u8 gAttackChangeRightArmPartIds[];
extern const u8 gAttackChangeLeftArmPartIds[];
extern const u8 gDefenseChangeHeadPartIds[];
extern const u8 gDefenseChangeRightArmPartIds[];
extern const u8 gDefenseChangeLeftArmPartIds[];
extern const u8 gHealChangeHeadPartIds[];
extern const u8 gHealChangeRightArmPartIds[];
extern const u8 gHealChangeLeftArmPartIds[];
extern const void
    *gStaggeredSpriteAnimScripts[];      // [0]: animation script every staggered sprite runs (staggered_sprites_update)
extern const u16 gHitSparkOffsets[];     // x, y offset pairs per sprite of a 4-sprite group (hit_sparks_spawn)
extern const u16 gPartFlyStepsLegs[];    // (dx, dy) s16 pairs by sprite work[FX_SPR_STEP], added to the sprite position
                                         // (effect_sprite_fly_to_part)
extern const u16 gPartFlyStepsLeftArm[]; // (dx, dy) s16 pairs by sprite work[FX_SPR_STEP], added to the sprite position
                                         // (effect_sprite_fly_to_part)
extern const u16 gPartFlyStepsRightArm[]; // (dx, dy) s16 pairs by sprite work[FX_SPR_STEP], added to the sprite
                                          // position (effect_sprite_fly_to_part)
extern const u16 gPartFlyStepsHead[];    // (dx, dy) s16 pairs by sprite work[FX_SPR_STEP], added to the sprite position
                                         // (effect_sprite_fly_to_part)
extern const u16 gSpriteBobYSteps[];     // 32 y offsets added to a sprite's y by sprite_bob_step
extern const u8 gSpriteHopYSteps[];      // 16 y offsets added to a sprite's y by advance_sprite_anim_frame
extern const u8 gSpriteSlideXSteps[];    // 16 x offsets added to / subtracted from a sprite's x by sprite_slide_x_step
extern const u8 gSpriteSpeedSteps[];     // 256 speed steps (quarter pixels) by work16[FX_FALL_SPEED]
                                         // (sprite_move_toward_target, update_sprite_deceleration)
extern const u16 gParticleSwayOffsets[]; // 16 x steps by a sprite's work[PARTICLE_TIMER] & 15 (particle_sway_down)
extern const u8
    gParticleOrbitRadiusSteps[]; // orbit radius steps (+1 / -1, byte pairs) by a sprite's work[PARTICLE_TIMER] & 31
extern const u8 gRandomPartByIntactClass[]; // 8 entries per bot_intact_parts_class result, one picked at random
                                            // (get_random_battle_weight_entry)
extern const u8 gArmorPanelFrameTilemap[];  // compressed tilemap (armor_panel_draw_frame)
extern u8 gEffectSpriteSlot;                // sprite slot whose handler is running (= gGameWork.runningSpriteSlot)
extern const Func gParticleSparkHandlers[]; // spark states by sprite work[PARTICLE_STATE] (particle_run_spark_handlers,
                                            // slots 0x2B-0x3B)
extern const Func
    gParticleOrbitHandlers[]; // orbit / trail states by sprite work[PARTICLE_STATE] (particle_run_orbit_handlers)
extern const s16
    *const gBattleSeqScripts[]; // battle sequence scripts, by gBattleWork.animSkill (battle_seq_load_operands)
extern const u8 gBattleSeqOperandCounts[];       // operand count per battle sequence command (battle_seq_advance)
extern const u16 *const gBattleSeqTileAnims[];   // x, y passed to tile_anim_init, by sprite 4 work[SEQ_BG_TILE_ANIM]
                                                 // (battle_seq_cmd_bg_effect)
extern const u8 *const gBattleSeqLegSoundSets[]; // by sequence operand: 4 animation sets, by legs data[1] - 0x64 (3
                                                 // when gBattleWork.partIds[3] > 0x77; battle_seq_cmd_leg_sound)
extern const u8
    *const gBattleSeqEffectGfx[];       // pairs: compressed OBJ tiles, OBJ palette 14 (battle_seq_cmd_load_effect_gfx)
extern const Func gBattleSeqCommands[]; // battle sequence commands, by battle_seq_peek() (battle_sequence_run_command)
extern const Func gParticleShotHandlers[]; // shot states by sprite work[PARTICLE_STATE] (particle_run_shot_handlers)
extern u16 gPartSpriteOffsets[]; // x, y offset pairs by part (effect_sprite_spawn_at_part); not const: hit_sparks_spawn
                                 // reloads it per iteration
extern const u8 gDiceRollValues[];  // 16 values, two random picks summed into gBattleWork.dice1 / dice2
                                    // (script_op_roll_dice_damage)
extern u8 gGuardSpriteEntryBytes[]; // = (u8 *)&gSpriteEntries[33]: script_op_guard_restore copies the guarding
                                    // Medabot's 4 saved part sprites (entries 90 + 4 * rec) back over 33-36
extern const u8
    gActionScriptOperandCounts[];    // Robattle action script: operand count per command byte (battle_script_advance)
extern const u8 gSpriteHopOffsets[]; // 32 y offsets added to a sprite's y by sprite_hop_step
extern const u8
    *const gActionScripts[]; // Robattle action scripts by skill id gBattleWork.actorSkill (battle_script_read_byte)
extern const Func
    gActionScriptCommands[]; // Robattle action script commands by script byte < 0x80 (battle_run_action_script; script
                             // from gActionScripts[gBattleWork.actorSkill] at offset scriptOffset,
                             // battle_script_read_byte)
extern const Func gAiActionChecks[];     // Robattle AI: action validity checks by part skill id data[1]; set
                                         // gBattleWork.scratch = 1 to reject (ai_action_unusable)
extern const u8 gRandomSlots[];          // 16 slot numbers 0-2 picked by rng & 15 (rng_random_slot)
extern const Func gAiAfterPick[];        // Robattle AI: action handlers by part skill id data[1] (ai_run_after_pick)
extern const Func gAiTargetPickers[];    // Robattle AI: action selection handlers by part skill id data[1]
                                         // (ai_pick_part_target)
extern const u8 gLevelUpSkillPalettes[]; // sprite 0x22 palette bits (SpriteEntry.palette) by the levelled-up skill type
                                         // gBattleWork.levelUpSkill (action_phase_level_up_skill_init)
extern const u8 gSkillLevelUpTilesLz[];  // compressed OBJ tiles at 0x06014800: Medal skill level-up popup
                                         // (action_phase_level_up_init)
extern u8 gLinkPartnerName[]; // = gBattleWork.partnerName: link partner's player name (link_robattle_exchange_names)
extern u8 gPlayerName[];      // gPlayerRecord.name; copied for message 2 when gGameWork.battleResult == 1
                              // (action_phase_show_winner_message; guess: player name)
extern const u8 gActionPhaseObjPalette[];           // OBJ palette 6 (action_phase_load_gfx)
extern const Func gActionPhaseSteps[];              // by gGameSubState (battle_action_state_update)
extern const u8 gMedaforceAntiProtectionTiles[];    // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceAntiProtectionSteps[];  // by gBattleWork.step (medaforce_anti_protection_run)
extern const u8 gMedaforceProtectorPalettes[];      // 32-byte OBJ palette (battle/medaforce_effects)
extern const u8 gMedaforceProtectorTiles[];         // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceProtectorSteps[];       // by gBattleWork.step (medaforce_protector_run)
extern const u8 gMedaforceLegCrashPalette[];        // 32-byte OBJ palette (battle/medaforce_effects)
extern const u8 gMedaforceLegCrashTiles[];          // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceLegCrashSteps[];        // by gBattleWork.step (medaforce_leg_crash_run)
extern const Func gMedaforceFormationOrdersSteps[]; // by gBattleWork.step (medaforce_formation_orders_run)
extern const u8 gMedaforceUpTiles[];                // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceUpSteps[];              // by gBattleWork.step (medaforce_up_run)
extern const u8 gMedaforceActivatePalette[];        // 32-byte OBJ palette (battle/medaforce_effects)
extern const u8 gMedaforceCrazyShotPalette[];       // 32-byte OBJ palette (battle/medaforce_effects)
extern const u8 gMedaforceCrazyShotTiles[];         // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceCrazySteps[];           // by gBattleWork.step (medaforce_crazy_run)
extern const u8 gDestroyerSwingFrames[];           // pairs (work[SPR_MOTION_ROW] direction or 0xFF end, wait frames) by
                                                   // work[FX_SWING_POS] (medaforce_destroyer_swing)
extern const u8 gMedaforceDestroyerPalette[];      // 32-byte OBJ palette (battle/medaforce_effects)
extern const u8 gMedaforceDestroyerTiles[];        // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceDestroyerSteps[];      // by gBattleWork.step (medaforce_destroyer_run)
extern const u8 gMedaforceUselessPalette[];        // 32-byte OBJ palette (battle/medaforce_effects)
extern const u8 gMedaforceUselessTiles[];          // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceUselessSteps[];        // by gBattleWork.step (medaforce_useless_run)
extern const Func gMedaforcePushoverAttackSteps[]; // by gBattleWork.step (medaforce_pushover_attack_run)
extern const u8 gMedaforceChargeTiles[];           // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceChargePalette[];         // 32-byte OBJ palette (battle/medaforce_effects)
extern const Func gMedaforceChargeSteps[];         // by gBattleWork.step (medaforce_charge_run)
extern const Func gMedaforceHideNSeekSteps[];      // by gBattleWork.step (medaforce_hide_n_seek_run)
extern const u8 gSpyGameBeamSpinFrames[];          // frame counts (medaforce_spy_game_beam_spin)
extern const Func gMedaforceSpyGameSteps[];        // by gBattleWork.step (medaforce_spy_game_run)
extern const u8 gMedaforceUpArrowTiles[];          // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceUpArrowPalettes[];       // 64-byte OBJ palettes (battle/medaforce_effects)
extern const Func gMedaforceLegsStatUpSteps[];     // by gBattleWork.step (medaforce_legs_stat_up_run)
extern const u8 gMedaforceAntiTerrainBoltTiles[];  // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceAntiTerrainBoltPalettes[];     // 64-byte OBJ palettes (battle/medaforce_effects)
extern const Func gMedaforceAntiTerrainSteps[];          // by gBattleWork.step (medaforce_anti_terrain_run)
extern const u8 gMedaforceAntiTerrainBeamTiles[];        // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceAntiTerrainBeamPalettes[];     // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforcePowerUpPalette[];              // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforcePowerUpTiles[];                // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforcePowerUpSteps[];              // by gBattleWork.step (medaforce_power_up_run)
extern const u8 gMedaforceIronWallPalette[];             // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceIronWallTiles[];               // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceIronWallSteps[];             // by gBattleWork.step (medaforce_iron_wall_run)
extern const u8 gMedaforceFullBodyRadPalette[];          // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceFullBodyRadTiles[];            // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceFullBodyRadSteps[];          // by gBattleWork.step (medaforce_full_body_rad_run)
extern const u8 gMedaforceFullBodyUpPalette[];           // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceFullBodyUpTiles[];             // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceFullBodyUpSteps[];           // by gBattleWork.step (medaforce_full_body_up_run)
extern const u8 gMedaforceFullBodyRepairPalette[];       // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceFullBodyRepairTiles[];         // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceFullBodyRepairSteps[];       // by gBattleWork.step (medaforce_full_body_repair_run)
extern const u8 gMedaforceTotalRecoverySparklePalette[]; // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceTotalRecoverySparkleTiles[];   // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceTotalRecoveryPalette[];        // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceTotalRecoveryTiles[];          // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceTotalRecoverySteps[];        // by gBattleWork.step (medaforce_total_recovery_run)
extern const u8 gMedaforceStatusRestorePalette[];        // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceStatusRestoreTiles[];          // compressed tiles (battle/medaforce_effects)
extern const Func gMedaforceCancelStatusSteps[];         // by gBattleWork.step (medaforce_cancel_status_run)
extern const Func gMedaforceStatusRestoreSteps[];        // by gBattleWork.step (medaforce_status_restore_run)
extern const u8 gMedaforceCancelStatusSparkleTiles[];    // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceCancelStatusSparklePalette[];  // 64-byte OBJ palettes (battle/medaforce_effects)
extern const u8 gMedaforceTargetBurstTiles[];            // compressed tiles (battle/medaforce_effects)
extern const u8 gMedaforceTargetBurstPalette[];          // 64-byte OBJ palettes (battle/medaforce_effects)
extern const Func
    gMessageEndWaitCloseSteps[]; // end mode 0 steps by gGameWork.endModeStep: portrait, window, frame, palettes, done
extern const Func gMessageEndCloseSteps[];     // end mode 1 steps (same as mode 0, no wait for A / B)
extern const Func gMessageEndWaitKeepSteps[];  // end mode 2 steps: message_close only (window stays open)
extern const Func gMessageEndWaitClearSteps[]; // end mode 3 steps: clear the text tiles, then message_close
extern const Func gMessageEndKeepSteps[];      // end mode 4 steps: message_close only, no wait
extern const u8 gLinkBattlefields[32];         // battlefields, picked at random into gBattleWork.battlefield
                                               // (link_robattle_pick_battlefield)
extern const Func
    gMessageStates[]; // run_message states by gGameWork.msgState: message_open, message_dim_palettes_step,
                      // message_show_window, ..., message_run_command (runtime-checked in 03_new_game_intro)
extern const Func gMessageEndModes[];      // end modes 0-4, by the byte after the 0xFF end code (message_run_command)
extern const u8 gPrizeGameSlotSets[16][6]; // prize rows per set, one set picked at random into gPrizeGameSlots
                                           // (prize_game_pick_slots)
extern const u8 gFontGlyphs[]; // message font, 64 bytes (two 4bpp tiles, 8x16) per character; character 0 is blank
extern u8 gPrizeGameSlots[6];  // 6 bytes from gPrizeGameSlotSets (prize_game_pick_slots); = gBattleWork.prizeSlots
extern const u8 gPrizeGameBotPicks[16]; // record index 0-2 picked at random (prize_game_pick_prize_part)
extern const u8 gAltFontWidths[][2];    // alternate font widths, used after a 0xF8 code (gGameWork.altFont)
extern const u8 gAltFontGlyphs[];       // alternate font glyphs, 64 bytes per character
extern const u8 gFontWidths[][2];       // message font: per character code, [0] width in pixels
extern const Func
    gLinkRobattleHandlers[]; // link Robattle game state: sub-state handlers by gGameSubState (link_robattle_update)
extern const u8
    gMessageWindowOpenTiles2[]; // compressed tiles, message window frame style 3 (message_close_window_frame)
extern const u8
    gMessageWindowOpenTilemap2[]; // compressed tilemap, message window frame style 3 (message_close_window_frame)
extern const u8
    gMessageWindowOpenTiles1[]; // compressed tiles, message window frame style 2 (message_close_window_frame)
extern const u8
    gMessageWindowOpenTilemap1[]; // compressed tilemap, message window frame style 2 (message_close_window_frame)
extern const u8 gBattlefieldEffectParams[][8]; // per battlefield, copied to gBattleWork.battlefieldEffect
                                               // (load_battle_script_entry_b)
extern const Func gChoiceMenuStates[];         // choice menu states by gGameWork.choiceState (poll_choice_menu)
extern const Func gMessageCloseSteps[];        // by gGameWork.endModeStep (game_state_execute_handler_a)
extern const Func gMessageCloseQuickSteps[];   // by gGameWork.endModeStep (game_state_execute_handler_b)
extern const u8 *const gBattlefieldTilesets[]; // 4 compressed pointers per battlefield: tiles, BG palette, BG2 / BG3
                                               // tilemaps (decompress_tileset_to_vram)
extern const u8 gChoiceMenuFrameTiles[];       // compressed tiles (decompress_bg_tilemap_to_vram)
extern const u8 gChoiceMenuLabelTiles[];       // guess: yes/no labels of the choice menu, compressed tiles
extern const u8 gChoiceMenuFrameTilemap[];     // compressed tilemap
extern const u8 gChoiceMenuLabelTilemap[];     // compressed tilemap
extern const u8
    gBattlefieldAnimTileCounts[];         // per battlefield: animation tile count / 8 (advance_battle_animation_frame)
extern const u8 gBattlefieldAnimFrames[]; // [battlefield][0x80]: animation tile block per frame, 0xFF = loop
extern const u8 *const
    gMedabotPartSpriteTiles[];  // 6 compressed sprite tile pointers per Medabot (decompress_sprite_to_vram_08042D94)
extern const s16 gCosTableQ8[]; // cosine x256 per angle 0-0xFF (calc_polar_to_screen_coords x;
                                // gJumpArcTable is the y factor)
extern const u8 gAreaSongs[];   // per area id (gFieldWork.area_id), used unless song == 0xFF (area_song_id)
extern struct PartSpriteLayer gRightArmPartLayer;
extern struct PartSpriteLayer gLeftArmPartLayer;
extern struct PartSpriteLayer gHeadPartLayer;
extern struct PartSpriteLayer gLegPartLayer;
extern const u8 gSpriteSheetBlendKinds[]; // per sprite sheet id (gSpriteEntries[].work16[FIELD_SPR_SHEET]): 2 -> order
                                          // = 0xFF, 1 -> 0, else 0x40 (sprite_set_blend_from_kind)
extern const u8 *const gSpriteSheetVariantTables[]; // sheet ids by id - 0xD0, indexed by gFieldWork.sheet_variants[id -
                                                    // 0xD0] (resolve_sprite_sheet_id)
extern u8 *gAreaAnimTileSrc;                        // animated tile source for the area (animate_area_bg_tiles)
extern const u8 *const gAreaTileAnims[];   // per area id: tile animation [0] tiles per frame, [2] enabled, [3..] frame
                                           // list ending 0xFF (animate_area_bg_tiles)
extern const u16 *const gAreaBgPalettes[]; // per area id: 0xD0-color palette for 0x0202FA00, NULL = default set from
                                           // gFallbackAreaPalette0 (area_load_bg_palettes)
extern const u16 gFallbackAreaPalette0[];  // fallback BG palette (area_load_bg_palettes)
extern const u16 gFallbackAreaPalette1[];  // fallback BG palette (area_load_bg_palettes)
extern const u16 gFallbackAreaPalette2[];  // fallback BG palette (area_load_bg_palettes)
extern const u16 gFallbackAreaPalette3[];  // fallback BG palette (area_load_bg_palettes)
extern const u16 gFallbackAreaPalette4[];  // fallback BG palette (area_load_bg_palettes)
extern const u16 gFallbackAreaPalette5[];  // fallback BG palette (area_load_bg_palettes)
extern const Func gFieldModeStates[];      // by gGameState (field_mode_dispatch)
extern const u8 *const
    gAreaSpriteSheetIds[]; // per area id: tile ids, resolved through resolve_sprite_sheet_id (area_sprite_sheet_id)
extern const u8 *const
    gFieldSpriteTiles[]; // per sprite sheet id: LZ77 OBJ tiles, NULL entries fall back to 1 (area_load_sprite_sheets)
extern const u16 gFieldSharedSpritePalette[]; // palette copied to 0x0202F9C0 (area_load_sprite_palettes)
extern u32 gFieldUnusedWord;                  // cleared by field_clear_ram, never used otherwise
extern struct AffineParam gAffineParams[32];
extern struct FieldEffectEntity *gFieldEffectEntities;
extern const s32 *const *const
    gFieldEffectModels[]; // per model set, per entity: s32 count, x[4], y[4], z[4] (field_effect_project_objects)
extern const float gCosTableF32[256]; // cos(i * 2pi / 256) as floats (set_state_float_field; [0] = 1.0)
extern const float gSinTableF32[256]; // sin(i * 2pi / 256) as floats ([64] = 1.0)
extern const Func gItemMenuStates[];  // field menu Item screen states, by gGameSubState (item_menu_update)
extern const Func gNameEntryStates[]; // 7 name entry sub-states, by gGameSubState (name_entry_screen_update)
extern const u8
    *const gItemDescriptions[]; // item description messages by item id (runtime: item 1 Skirt -> "Transform Goods No.1
                                // / A frilly mini-skirt."); 0x3F with an empty list (item_menu_show_description)
extern const u8
    gNewGamePromptMessage[]; // "start a new game? saved data will be erased" text (new_game_prompt_show_message)
extern const Func gMenuModeStates[];         // by gGameState (menu_mode_update)
extern const u8 gMultiplayerIdUnusedBytes[]; // 4 bytes copied to an unused local (init_multiplayer_id)
extern const u8 gTownMapNeighbours[]; // per gFieldWork.town_map_phase: 10 x 4 next-entry bytes (right, left, up, down)
                                      // by gMenuWork->town_map_place (town_map_move_cursor)
extern const u8 gTownMapNeighboursAlt[];       // same, used when gMenuWork->cursor_style is set (town_map_move_cursor)
extern const u8 gMedabotSpritePalettes[];      // per Medabot (gMedabotPartSpriteTiles index): sprite palette - 4
                                               // (load_battle_sprite_tiles)
extern const u16 gTitleOptionValueMasks[3][3]; // 3 x 3 tile masks (bit 15 first) of the title option rows
                                               // (title_options_draw_values)
extern const u8 gItemMenuBg1Tilemap[];         // field menu item list BG1 tilemap (LZ77, item_menu_load_graphics)
extern const u8 gItemMenuBg2Tilemap[];         // field menu item list BG2 tilemap (LZ77, item_menu_load_graphics)
extern const u8 gItemMenuBg3Tilemap[];         // field menu item list BG3 tilemap (LZ77, item_menu_load_graphics)
extern const u32 gItemMenuBgTiles[]; // field menu item list BG tiles (dma3_copy_or_decompress, item_menu_load_graphics)
extern const u16 gItemMenuObjPalette[16];    // OBJ palette 14 of the field menu item list (item_menu_init)
extern const u16 gItemMenuBgPalettes[0x100]; // BG palettes of the field menu item list (item_menu_init)
// code_0805EE6C
extern const u8 gSaveLostSpriteFrames[8];      // sprite 0 frame offsets (save_lost_animate_sprite)
extern const u8 gShopkeeperPortraitSets[];     // 0xFB portrait set by gShopId (shop_copy_text_with_portrait)
extern u8 gShopId;                             // Medaparts shop id: stock row in gShopStock, shopkeeper portrait
extern const Func gTownMapStates[];            // sub-state handlers (town_map_dispatch)
extern const Func gGameOverStates[];           // sub-state handlers (game_over_update)
extern const Func gSaveLostStates[];           // sub-state handlers (save_lost_dispatch)
extern const Func gTestModeStates[];           // sub-state handlers (test_mode_dispatch)
extern const Func gShopListHandlers[];         // sub-state handlers (shop_list_dispatch)
extern const void *const gTownMapPlaceNames[]; // messages by gMenuWork->town_map_place (town_map_show_place_name)
extern const u8 gShopSellPartTypeText[];       // message text (shop_menu_part_type_prompt, gMenuWork->cursor set)
extern const u8 gShopBuyPartTypeText[];        // message text (shop_menu_part_type_prompt, gMenuWork->cursor clear)
extern const u8 gTownMapPlacePositions[][2];   // x, y in tiles by gMenuWork->town_map_place (town_map_update_cursor)
extern const u16 gTownMapCursorOffsetX[][4];   // cursor x offsets [cursor_style][frame]
extern const u16 gTownMapCursorOffsetY[][4];   // cursor y offsets [cursor_style][frame]
extern const u16 gTownMapCursorFrames[][4];    // cursor tile numbers [cursor_style][frame]
extern const u8 gTownMapAnimFrameOrder[];      // gTownMapAnimTiles frame by gMenuWork->frame / 10
extern const u8 gShopGreetingText[];           // message text (shop_menu_greeting)
extern const Func gShopMenuStates[];           // sub-state handlers (shop_menu_dispatch)
extern const u16 gGameOverIkkiFramesExit[];    // sprite 1 animation frames by timer / 6 (game_over_wipe_out)
extern u8 gTitleSkipIntro;
extern const u8 gPartTradeSpritePositions[][4][2]; // x, y by [which][kind] (load_medapart_sprite_animation)
extern const u16 gShopObjPalette[];                // OBJ palette 1 (shop_menu_show_layers)
extern const u16 gShopMenuBgPalettes[];            // BG palettes (shop_menu_show_layers)
extern const u8 gShopPartTypeIconPos[4][2];        // icon x, y in BG2 tiles (shop_highlight_part_type_icon)
// A function table that the code copies to the stack before indexing it (agbcc emits ldm / stm for
// the struct copy), like a local initialized array whose initializer lives in ROM.
struct FuncTable7 {
    Func f[7];
};
extern const struct FuncTable7 gShopSubStates;    // sub-state handlers by gGameSubState (dispatch_substate_handler)
extern const struct FuncTable7 gTextScrollStates; // sub-state handlers by gGameSubState (text_scroll_update)
struct TextBufTable4 {
    u8 *p[4];
};
extern const struct ObjAffineDstData
    gAffineIdentityRotated;                           // identity affine matrix (render_sprite_if_visible_rotated)
extern const struct ObjAffineDstData gAffineIdentity; // identity affine matrix (render_sprite_node_recursive)
extern const u8 gMirroredPartNode[]; // mirrored sprite node index per node (render_sprite_node_recursive)
extern const struct TextBufTable4
    gTextBufferPtrs;                   // the 4 text buffers 0x030004DE + 0x14 * n (copy_string_to_text_buffer)
extern const u8 gTextScrollHeadingX[]; // first tilemap column by gMenuWork->cursor (text_scroll_shift_row)
struct U16PtrArray8 {
    const u16 *v[8];
};
extern const u8 gRaceTileBlockWidths[8];              // guess: tile block widths by type (race_draw_tile_block)
extern const u8 gRaceTileBlockHeights[8];             // guess: tile block heights by type (race_draw_tile_block)
extern const u16 gRaceTileBlockFirstTiles[8];         // first tile by type (race_draw_tile_block)
extern const struct U16PtrArray8 gRaceTileBlockLists; // tile index lists by type (race_draw_tile_block)
extern const u16 gRaceTileBlockPalettes[8];           // palette bits by type (race_draw_tile_block)
extern const u8 gTextScrollBg0Tilemap[];              // race scene BG0 tilemap (decompress_and_write_tilemap)
extern const u8 gTextScrollBg2Tilemap[];              // race scene BG2 tilemap (decompress_and_write_tilemap)
extern const u8 gTextScrollBg3Tilemap[];              // race scene BG3 tilemap (decompress_and_write_tilemap)
extern const u32 gTextScrollBgTiles[];                // race scene BG tiles (dma3_copy_or_decompress)
extern const u8 gTextScrollBgPalettes[];              // race scene BG palettes (0x60 bytes to 0x0202FA00)
extern const u8 gBlackObjPalettes[];                  // OBJ palette (0x20 bytes to 0x05000200)
struct PtrTable3 {
    const u8 *const *p[3];
};
extern const struct PtrTable3 gTextScrollPages; // scene texts by gMenuWork->cursor (text_scroll_page_start)
extern const u16 gPartTradeObjPalette[16]; // OBJ palette for the link Medapart trade scene (medapart_trade_fade_in)
struct FuncTable13 {
    Func f[13];
};
extern const struct FuncTable13
    gPartTradeStates;                 // link Medapart trade sub-states by gGameSubState (medapart_trade_update)
extern const s16 gSineTable[0x140];   // sin(i * 2pi / 256) * 0x100, 256 + 64 entries (cos(x) = [x + 0x40])
extern const s8 gLinkMenuGameModes[]; // game mode by gMenuWork->cursor (link_menu_fade_out_exit)
extern const struct FuncTable13
    gLinkMenuStates; // link menu sub-states by gGameSubState (dispatch_battle_menu_and_update_counters)
extern const u8
    gLinkSavePromptMessage[]; // guess: yes/no question before saving and linking (setup_dialogue_script_from_rom)
extern const u8 gLinkMenuBg1Tilemap[];    // link menu BG1-3 tilemaps, tiles at 0x06004000, BG palette (clear_vram_bg)
extern const u8 gMedalRenameBg1Tilemap[]; // Medal list BG1 tilemap (medal_rename_load_graphics)
extern const u8 gMedalRenameBg2Tilemap[]; // Medal list BG2 tilemap (medal_rename_load_graphics)
extern const u8 gMedalRenameBg3Tilemap[]; // Medal list BG3 tilemap (medal_rename_load_graphics)
extern const u32 gMedalRenameBgTiles[];   // Medal list BG tiles, compressed (medal_rename_load_graphics)
extern const u8 gMedalTradeBg1Tilemap[];  // BG1 tilemap (medal_trade_init_screen)
extern const u8 gMedalTradeAnimFramesTilemap[]; // 4 frames (0x200 bytes each) at screen 27, copied into BG2 to animate
extern const u8 gMedalTradeBg3Tilemap[];        // BG3 tilemap (medal_trade_init_screen)
extern const u8 gMedalTradeBg2Tilemap[];        // BG2 tilemap at screen 29 (medal_trade_init_screen)
extern const u32 gMedalTradeBgTiles[];          // BG tiles, compressed (medal_trade_init_screen)
extern const u16 gMedalTradeBgPalettes[];       // BG palettes (medal_trade_init_screen)
extern const u8 gLinkMenuBg2Tilemap[];
extern const u8 gLinkMenuBg3Tilemap[];
extern const u32 gLinkMenuBgTiles[];
extern const u16 gLinkMenuBgPalette[];
extern const u16
    gMenuDigitPalette[]; // guess: palette for gMenuDigitTilesLz (BG pal 1 next to it in clear_vram_bg2_tilemap)
extern const u16 gMedalRenameBgPalettes[];
extern const u16 gMedalRenameObjPalette[];
extern const u8 gLinkIntroMessageIds[]; // message indices (battle_cutscene_dispatch)
extern const u8 gLinkStartMessageIds[];
extern const u8 gLinkAnswersDifferMessage[]; // cursor 6: the two players answered the yes/no prompt differently
extern const u8 gLinkMenuHelpMessageIds[];   // message index per cursor position (handle_battle_menu_selection)
extern const u32 gScrollBannerStripTiles[];  // graphics (scroll_banner_init)
extern const u8 gScrollBannerBg3Tilemap[];
extern const u32 gScrollBannerBgTiles[];
extern const u32 gScrollBannerBgTiles2[];
extern const u16 gScrollBannerBgPalette[];
struct FuncTable2 {
    Func f[2];
};
struct FuncTable4 {
    Func f[4];
};
struct FuncTable6 {
    Func f[6];
};
struct FuncTable12 {
    Func f[12];
};
extern const struct FuncTable12
    gMedalTradeStates; // link Medal exchange sub-states by gGameSubState (medal_trade_update)
extern const struct FuncTable4 gScrollBannerStates;     // sub-states by gGameSubState (scene_dispatch_and_tick)
extern const struct FuncTable2 gLinkMedalSyncSubStates; // sub-states by gGameSubState (link_medal_sync_update)
struct FuncTable8 {
    Func f[8];
};
extern const struct FuncTable8
    gLinkStartStates;                   // sub-state handlers by gGameSubState (dispatch_battle_cutscene_substate)
extern const Func gMedalRenameStates[]; // Medal list screen sub-states (medal_rename_main)
extern const struct FuncTable7 gMedalLevelUpSubStates; // sub-state handlers by gGameSubState (medal_transform_update)
struct S32Array3 {
    s32 v[3];
};
extern const struct S32Array3
    gBombGameDebrisTimes;              // {0x50, 0x40, 0x20}: bomb minigame debris intervals (bomb_game_player_blown_up)
extern const u8 gBombGameBannerEva[8]; // bomb minigame BLDALPHA EVA steps (bomb_game_animate_round_banner)
extern const u8 gBombGameBannerEvb[8]; // bomb minigame BLDALPHA EVB steps (bomb_game_animate_round_banner)
extern const u8 gWeeklyStudioBgTiles[];    // LZ77, studio BG tiles (char base 1)
extern const u8 gWeeklyLectureBgTiles[];   // LZ77, "Medabots Lecture" BG tiles (char base 2)
extern const u8 gWeeklyStudioBg1Tilemap[]; // LZ77, studio BG1-3 tilemaps (screen bases 0xD-0xF)
extern const u8 gWeeklyStudioBg2Tilemap[];
extern const u8 gWeeklyStudioBg3Tilemap[];
extern const u8 gWeeklyLectureBg1Tilemap[]; // LZ77, lecture BG1-3 tilemaps (screen bases 0x15-0x17)
extern const u8 gWeeklyLectureBg2Tilemap[];
extern const u8 gWeeklyLectureBg3Tilemap[];
extern const u8 gWeeklyObjTiles[];         // LZ77, curtain and Medabot OBJ tiles (OBJ VRAM 0x10000)
extern const u8 gWeeklyAnimTilesLz[];      // LZ77, unpacked to gWeeklyAnimTiles (weekly_show_studio)
extern const u8 gWeeklyStudioBgPalettes[]; // 13 BG palettes of the studio
extern const u8 gMapSpriteSheet48Tiles[];  // LZ77 map sprite sheets 48 / 46 / 40 / 37 (gFieldSpriteTiles), the four
                                           // Weekly characters
extern const u8 gMapSpriteSheet46Tiles[];
extern const u8 gMapSpriteSheet40Tiles[];
extern const u8 gMapSpriteSheet37Tiles[];
extern const u16 gMapSpriteSheet48Palette[]; // their palettes (gFieldSpritePalettes 48 / 46 / 40 / 37)
extern const u16 gMapSpriteSheet46Palette[];
extern const u16 gMapSpriteSheet40Palette[];
extern const u16 gMapSpriteSheet37Palette[];
extern const u16 gWeeklyObjPalettes[];         // 16 OBJ palettes of the studio and lecture sprites
extern const u16 gWeeklyLectureBgPalettes[];   // 6 BG palettes of the lecture corner
extern const u8 gIntroUnusedArtTilesLz[];      // LZ77 BG tiles (intro_load_art_unused)
extern const u8 gIntroUnusedArtTilemapLz[];    // LZ77 30x20 tilemap (intro_load_art_unused)
extern const u16 gIntroUnusedArtPalette[];     // BG palette, 256 colours (intro_load_art_unused)
extern const u8 gIntroVersusArtTilesLz[];      // LZ77 BG tiles (intro_load_versus_art)
extern const u8 gIntroVersusArtTilemapLz[];    // LZ77 30x20 tilemap (intro_load_versus_art)
extern const u16 gIntroVersusArtPalette[];     // BG palette, 256 colours (intro_load_versus_art)
extern const u8 gIntroCloseupArtTilesLz[];     // LZ77 BG tiles (intro_load_closeup_art)
extern const u8 gIntroCloseupArtTilemapLz[];   // LZ77 30x20 tilemap (intro_load_closeup_art)
extern const u16 gIntroCloseupArtPalette[];    // BG palette, 256 colours (intro_load_closeup_art)
extern s32 (*const gIntroSpriteActions[])(u8); // sprite actions, by gSpriteEntries[].work[INTRO_SPR_ACTION] - 1: 0 =
                                               // done, 0xFF = clear (intro_update_sprite_actions)
extern const u8 gIntroSpriteActionPeriods[];   // sprite actions: frame period, by work[INTRO_SPR_ACTION] - 1
extern const s8
    gIntroBobOffsets[]; // 64-entry wave offsets, by gSpriteEntries[].work[INTRO_SPR_STEP] & 0x3F (intro_action_bob)
extern u8 gWeeklyAnimTiles[];  // animated BG tiles: 6 frames of 0x280 bytes, 0x100 copied (weekly_update_studio)
extern u8 gWeeklyAnimTiles2[]; // animated BG tiles: 6 frames of 0x280 bytes, 0x180 copied (weekly_update_studio)
extern u8 gWeeklyCycleAnimMask;
extern const Func
    gMedabotsWeeklySubStates[]; // sub-states by gGameSubState (medabots_weekly_update); [0] = medabots_weekly_init
extern s32 (*const gWeeklySpriteEffects[])(u8);
extern const s8 gWeeklyCurtainOpenTimes[8];
extern const void *const gWeeklyMessages[];
extern const u8 gMessageWaitKeyKeep[]; // empty message: 0xFF end mode 2 (wait for A / B, keep the window)
extern const u8 gIntroPointerLines[];  // 12 bytes per scan part, from +0x30: 3 lines (lineIdx) of x, y, end x, end row
extern const u8 *const
    gIntroScanStrings[]; // intro scan screen strings; [part + 4] are the part names typed by intro_type_part_name
extern const s8 gWeeklyCurtainCloseTimes[12]; // 12 frame counts (timer values) at which weekly_fx_right_curtain_close /
                                              // weekly_fx_left_curtain_close step
extern const u8 gCycleAnimFrameOffsets[];     // sprite_cycle_anim_update table
extern u16
    *gWeeklyFlashPalette; // palette the fade in weekly_lecture_flash reads from (set to gPaletteBackupBg = 0x0202FA00)
extern const u8 gWeeklyLectureSfxScript[13]; // weekly_lecture_run_pose script: pairs (0, n) = wait n frames, (1, id) =
                                             // play_sound_effect(id)
extern u32 (*const gWeeklyLectureSteps[])(
    void); // Medabots Lecture steps by gSceneWork.progress.lecture.state (weekly_lecture_run_step); 1 = done
extern const struct SpriteAnimCmd *const gSpriteAnimScripts[];
extern const struct SpriteAnimGfx gSpriteAnimGfx[];
extern const u8 gMapScripts[]; // banked map script data, the base of gMapScriptData (read_map_script_byte)
extern const Func gFieldSubStates[];
extern const void *const gRoomExitMessages[];
extern const void *const gAreaBgTiles[];     // per area id: LZ77 BG tiles for 0x06009000 (load_room_graphics)
extern const void *const gAreaAnimBgTiles[]; // per area id: LZ77 animated tile frames for gAreaAnimTileSrc
extern const u8 gFallbackAreaTiles0[];       // BG tiles for areas with no graphics (follow gFallbackAreaPalette0..5)
extern const u8 gFallbackAreaTiles1[];
extern const u8 gFallbackAreaTiles2[];
extern const u8 gFallbackAreaTiles3[];
extern const u8 gFallbackAreaTiles4[];
extern const u8 gFallbackAreaTiles5[];
extern const u8 gAreaTypes[]; // per area_id; type 0xA forbids the town map and Wings of Wind (guess: indoor/past)
extern const u8 gVehicleMenuCursorRows[];
extern const u8 gVehicleMenuNameTiles[];
extern const u8 gVehicleMenuBlankRowTiles[];
extern const u16 gVehicleMenuNamesTilemap[];
extern const u16 gVehicleMenuBlankRowTilemap[];
extern const u16 gVehicleMenuWindowTilemap[];
extern const u8 gMiniSWheelIconTiles[];
extern const u8 gMiniSWheelIconDimTiles[];
extern const u8 gVehicleIconBlankTiles[];
extern const u8 gSilverLocketIconTiles[];
extern const u8 gSilverLocketIconDimTiles[];
extern const u8 gWingsOfWindIconTiles[];
extern const u8 gWingsOfWindIconDimTiles[];
extern const u8 gPeriscopeIconTiles[];
extern const u8 gPeriscopeIconDimTiles[];
extern const u16 gVehicleIconPalette[];
extern const u16 gVehicleIconDimPalette[];
extern u16 *gFieldDebugEventValues[];
extern u16 *gFieldDebugMessageValues[];
extern u8 **gFieldDebugPageValues[];
extern const u8 gSpriteSheetPreviewKinds[]; // per sprite sheet id; 3: the field debug preview adds the player
                                            // sprite (slot 57) beside it. guess: rideable / carried sheets
// Field debug screen labels: NUL-terminated ASCII, drawn glyph by glyph from gFieldDebugFont
extern const u8 gFieldDebugLabelMd[];
extern const u8 gFieldDebugLabelMp[];
extern const u8 gFieldDebugLabelMn[];
extern const u8 gFieldDebugLabelPt[];
extern const u8 gFieldDebugLabelNor[];
extern const u8 gFieldDebugLabelCar[];
extern const u8 gFieldDebugLabelSen[];
extern const u8 gFieldDebugLabelSka[];
extern const u8 gFieldDebugLabelKim[];
extern const u8 gFieldDebugLabelYus[];
extern const u8 gFieldDebugLabelRob[];
extern const u8 gFieldDebugLabelBan[];
extern const u8 gFieldDebugLabelDor[];
extern const u8 gFieldDebugLabelObo[];
extern const u8 gFieldDebugLabelMef[];
extern const u8 gFieldDebugLabelKaz[];
extern const u8 gFieldDebugLabelGin[];
extern const u8 gFieldDebugLabelDog[];
extern const u8 gFieldDebugLabelKok[];
extern const u8 gFieldDebugLabelJet[];
extern const u8 gFieldDebugLabelMf[];
extern const u8 gFieldDebugLabelEf[];
extern const u8 gFieldDebugLabelEe[];
extern const u8 gFieldDebugLabelTe[];
extern const u8 gFieldDebugLabelEx[];
extern const u8 gFieldDebugLabelSt[];
extern const u8 gFieldDebugLabelCm[];
extern const u8 gFieldDebugLabelEvent[];
extern const u8 gFieldDebugLabelEno[];
extern const u8 gFieldDebugLabelFlg[];
extern const u8 gFieldDebugLabelX[];
extern const u8 gFieldDebugLabelLv[];
extern const u8 gFieldDebugLabelPlayer[];
extern const u8 gFieldDebugLabelPlx[];
extern const u8 gFieldDebugLabelPly[];
extern const u8 gFieldDebugLabelMapEffect[];
extern const u8 gFieldDebugLabelMen[];
extern const u8 gFieldDebugLabelKwg[];
extern const u8 gFieldDebugLabelDc[];
extern const u8 gFieldDebugLabelMl[];
extern const u8 gFieldDebugLabelBt[];
extern const u8 gFieldDebugLabelR[];
extern const u8 gFieldDebugLabelBlank[];
extern const u8 gFieldDebugLabelE[];
extern const u8 gFieldDebugLabelSk[];
extern const u8 gFieldDebugLabelSp[];
extern const u8 gFieldDebugLabelWl[];
extern const u8 gFieldDebugLabelN[];
extern const u8 gFieldDebugLabelW[];
extern const u8 gFieldDebugLabelL[];
extern const u8 gFieldDebugLabelKoma[];
extern const u8 gFieldDebugLabelKno[];
extern const u8 gFieldDebugLabelMess[];
extern const u8 gFieldDebugLabelMsb[];
extern const u8 gFieldDebugLabelMsn[];
extern const u8 gFieldDebugLabelMsf[];
extern const u8 gFieldDebugLabelMax[];
extern const u8 gFieldDebugLabelAr[];
extern const u8 gFieldDebugLabelKa[];
extern const u8 gFieldDebugLabelBgm[];
extern const u8 gFieldDebugLabelSe[];
extern const u8 gFieldDebugLabelPnt[];
extern u8 *gFieldDebugSoundValues[];
extern const Func gVehicleMenuStates[];
extern const u8 gFieldDebugFont[];
extern const u8 gFieldDebugHexDigits[];

// code_0805AB40 (session 91)
extern const struct FuncTable6 gNewGamePromptStates; // sub-states by gGameSubState (new_game_prompt_update)
extern const u8 gItemUsable[];             // per item id: 1 if usable from the item menu (town map 0 and the disguises)
extern const u8 gBattleMusicOptionSongs[]; // song per battle music option (title_options_input preview)
extern const u16 gSaveScreenBgPalettes[];
extern const u16 gSaveScreenObjPalette[];

// code_0805EE6C (session 94)
extern const u8 gSoundTestSongs[];
extern const u8 gSoundTestEffects[];
extern const u16 gShopListObjPalette[]; // OBJ palette 3 of the shop list
extern const u16 gShopListBgPalettes[]; // 16 BG palettes of the shop list
extern const u8 gTestModeBg1Tilemap[];
extern const u8 gTestModeBg2Tilemap[];
extern const u8 gTestModeBg3Tilemap[];
extern const u32 gTestModeBgTiles[];
extern const u16 gTestModeBgPalette[];
extern const u16 gSpriteMotionSteps[]; // per-step (x, y) offsets for update_sprite_animation_position
extern const u8 gPartTradeBg1Tilemap[];
extern const u8 gPartTradeAnimFramesTilemap[]; // 4 frames at screen 27, copied into BG2 to animate
extern const u8 gPartTradeBg3Tilemap[];
extern const u32 gPartTradeBgTiles[];
extern const u8 gPartTradeBgPalette[];
extern const u8 gGradientPaletteCyan[];

extern s32 *gFieldEffectScripts[]; // field effect scripts, picked by gFieldEffect.flags & 0x3F (field_effect_run)
extern const void *gFieldEffectObjTiles[];    // battle sequence sprite graphics (opcode 27)
extern const void *gFieldEffectObjPalettes[]; // battle sequence sprite palettes (opcode 27)
extern const u8 gTownMapWarpAreas[];          // area id by town map place (field effect 0x12 = town map travel)
extern const u8 gTownMapWarpPositions[];      // 4 per town map place: [2], [3] = arrival x, y in tiles
extern const u8 gTeleportWarpArea;            // field effect 0xE (teleport): destination area
extern const u8 gTeleportWarpPosition[];      // [2] / [3]: its tile x / y
extern u32 gPoseAnimIds[][7];      // [pose][gLegPartPoseSets[legs]]: keyframe animation id (medabot_pose_anim_step)
extern u8 gLegPartPoseSets[];      // per legs part id: pose set column of gPoseAnimIds
extern u8 *gPoseKeyframeEnds[];    // per animation: end frame of each keyframe, 0-terminated
extern s16 *gPoseKeyframeAngles[]; // per animation: 0x40 joint angles per keyframe (wrap at 0x10000)
extern s8 *gPoseKeyframeOffsets[]; // per animation: 0x40 (x, y) joint offsets per keyframe
extern const u8 gNameEntryBg1Tilemap[]; // name entry screen tilemaps (name_entry_init_graphics)
extern const u8 gNameEntryBg2Tilemap[];
extern const u8 gNameEntryBg3Tilemap[];
extern const u32 gNameEntryBgTiles[];    // name entry screen tiles
extern const u8 gNameEntryColumnRemap[]; // name entry: bottom-row button column -> letter-row column

extern u8 gOamBuildFlags; // bit 0: skip one OAM rebuild, bit 1: don't sort sprites
// perspective sprites (SpriteEntry.flags & 0xC0 == 0x80): screen = center + (pos + offset) * 4 / depth
extern s32 gSpritePerspCenterX;
extern s32 gSpritePerspOffsetY;
extern s32 gSpritePerspCenterY;
extern struct Vec16 gSpriteCameraPos;    // sprite camera position
extern struct Vec16 gSpriteScreenOffset; // added to every sprite's screen position (guess: screen shake)
// frame set tables by SpriteEntry.frame_table & 0xF: 0 default, 2 menu sprites, 1 / 3 not seen set in C
extern struct SpriteFrame *const *const gSpriteFrameSets[];
extern struct SpriteFrame *const *const gSpriteFrameSets1[];
extern struct SpriteFrame *const *const gMenuSpriteFrameSets[];
extern struct SpriteFrame *const *const gSpriteFrameSets3[];
extern const struct MapNpcRecord *const gAreaNpcRecords[];
extern u8 gListWorkBuffer[];  // shared work buffer; the shop list keeps the cart there (quantity per sell-list entry)
extern const u8 gShopStock[]; // 4 Medapart ids per shop (gShopId * 4 + i); 0xFF ends

extern u16 gFieldPlayerX; // FAKEMATCH: = gFieldWork.player_x; field_debug only matches with a separate symbol (the
                          // literal is loaded on its own)
extern u16 gFieldPlayerY; // FAKEMATCH: = gFieldWork.player_y, same
#endif                    // GUARD_VARIABLES_H
