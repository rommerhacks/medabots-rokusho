#ifndef GUARD_VARIABLES_H
#define GUARD_VARIABLES_H

// RAM variables and ROM data. Addresses are in symbols.ld.

typedef void (*Func)(void);

// RAM
extern struct Unk_03000440 gUnk_03000440;
extern struct Unk_03000590 gUnk_03000590[];
extern u8 gUnk_03000890[];
extern u8 gUnk_03000B90; // guess: link player id (0/1)
extern struct Unk_03000BE0 gUnk_03000BE0[];
extern u32 gFrameCounter;
extern u32 gGameMode;
extern struct Unk_030017A0 gUnk_030017A0[];
extern struct Unk_03001800 gUnk_03001800;
extern u32 gMoney; // money, capped at 99999 (add_money)
extern u32 gGameState;
extern u32 gGameSubState;
extern struct Unk_03002C30 gUnk_03002C30[];
extern struct Unk_03005170 gUnk_03005170;
extern struct Unk_03005350 gUnk_03005350;
extern struct Unk_030057A0 gUnk_030057A0;
extern u8 *gMapScriptData; // current map script data (banked, see read_map_script_byte)
extern struct Unk_030057E0 gUnk_030057E0;
extern struct Unk_030064A0 gUnk_030064A0;
extern struct Unk_03006D20 gUnk_03006D20;
extern struct Unk_03007014 *gUnk_03007014;
extern struct Unk_03007014 gUnk_03002430; // sound work area (soft_reset_to_title passes it to sound_init)
extern struct Vec16 gBg1Scroll;     // BG1 scroll (field: map camera)
extern struct Unk_03005310 gUnk_03005310;
extern u8 gUnk_03006F40[];
extern struct Unk_030055A0 gUnk_030055A0[];
extern struct Vec16 gBg2Scroll;     // BG2 scroll
extern struct Vec16 gBg3Scroll;     // BG3 scroll
extern u8 *gUnk_030057D8; // two 4-bit entries per byte (bit 3 / bit 7: flag, bits 0-2 / 4-6: count)
extern u16 *gUnk_03006D14;
extern struct Unk_03006D38 gUnk_03006D38;
extern u8 gUnk_03003810;
extern struct Unk_03005010 gUnk_03005010;
extern s8 gUnk_03005030;  // multiplayer link active (soft_reset)
extern vu16 gUnk_03002B90; // bit 0: vblank handler running
extern s8 gUnk_03002410;  // frames since the main loop last ran (vblank_irq)
extern Func gIntrTable[14];           // RAM copy of gIntrTableTemplate, used by irq_dispatch_arm
extern u32 gIntrMain[0x200];          // RAM copy of irq_dispatch_arm (the IRQ vector)
extern Func gVBlankCallback;          // called every vblank
extern Func gVBlankOnceCallback;      // called at the next vblank, then reset to nullsub_08000840
extern Func gHBlankCallback;          // called by hblank_irq
extern struct OamData gOamBuffer[128]; // copied to OAM in vblank_body
extern struct Unk_03002414 *gUnk_03002414;
extern u8 *gUnk_03005308;
extern u32 gUnk_03000430;              // vblank_body OAM mode (0, 2)
extern u8 gUnk_03000434;               // bit 0: vblank_body skips the BG scroll registers
extern struct Vec16 gUnk_03002C2C;     // scroll added to every BG layer
extern struct Vec16 gBg0Scroll;     // BG0 scroll
extern u16 gTilemapBaseEntry;          // added to every tilemap entry by write_tilemap_to_vram_08000E94
extern u8 gDecompressBuffer[];         // EWRAM buffer the tilemap loaders decompress into
extern u16 gPaletteBackup[0x200];      // OBJ then BG palette (copy_obj_palette_to_buffer)
extern u16 gPaletteBackupBg[0x100];    // = gPaletteBackup + 0x100
extern u16 gPaletteBuffer[0x200];      // OBJ then BG palette (dma_obj_palette_to_hardware)
extern u16 gPaletteBufferBg[0x100];    // = gPaletteBuffer + 0x100
extern u32 gRngCounter;
extern u32 gRngValue;
extern u32 gRngState;
extern u8 gUnk_03000588;

// ROM data
extern const Func gIntrTableTemplate[14];
extern const u32 gRngTable[16];
extern struct SoundSongHeader *gUnk_080AFFB8[]; // song table (sound_init)
extern struct SoundSongHeader *gUnk_080B06EC[]; // sound effect table (sound_init)
extern struct SoundNoteTable gUnk_080B1788;
extern const u8 gUnk_080B1570[];
extern const u8 gUnk_080B1718[];
extern const u8 gUnk_083D28C0[];
extern const u8 gUnk_083D2908[];
extern const u8 gUnk_083D29A6[];
extern const u16 *const gUnk_083F8634[]; // 16-colour palettes
extern const u8 gUnk_083D2918[][8];
extern const u8 gUnk_083D2B8D[];
extern const u8 gUnk_083D28C3[][16];
extern const u8 gUnk_083F8B74[][2];
extern const u8 gUnk_0847E948[];
extern const struct AreaWarp *const gUnk_08413114[];
extern void (*const gMapScriptCommands[])(void); // map script command handlers
extern void (*const gMapScriptUpdates[])(void); // per-command update handlers, run each frame while unkC89 is set
extern const u8 gUnk_083D24AC[]; // indexed by the player's facing (gUnk_03002C30[47].unk21)
extern const u8 gUnk_083D28B0[]; // indexed by gUnk_030057E0.unkC5C, passed to setup_battle_sprite_terrain
extern const u8 *const gUnk_084045A8[]; // per area: tile map
extern const struct AreaGfx gUnk_083F92F4[];
extern const u8 gUnk_083D2903[];
extern const u8 gUnk_083D29E6[];
extern const u8 gUnk_085FA104[]; // LZ77 sprite tiles
extern const struct MapExit *const gUnk_0840FAF4[]; // per area: 8-byte map exit records, 0xFF-terminated
extern const u16 gUnk_083AB9D0[];
extern const u16 gUnk_083ABA88[];
extern const u8 gUnk_083ABA8C[][16];
extern const u16 gUnk_083ABAB2[][4];
extern const u16 gUnk_083ABAC2[];
extern const u8 gSoundWavePatterns[][16]; // 4-bit samples for the wave channel (sound 3)
extern const u8 gUnk_083ABA62[16]; // envelope volume -> SOUND3CNT_H volume bits (>> 8)
extern const u16 gSoundSemitoneRatios[12]; // 2^(i/12) * 0x1000
extern const u16 gSoundFinetuneRatios[128]; // 2^(i/(12*128)) * 0x1000
extern const u32 gSoundEffectTracks[6]; // track indices of the sound effect tracks (4-7, 10, 11)
extern const Func gGameStateHandlers_083AC148[];
extern const u32 gUnk_083B6410[];
extern const u8 gUnk_083B6158[][16]; // 16-byte records per Medal graphic index (byte 1 compared with a Medapart's skill, byte 7 icon)
extern const u8 gUnk_083D1BF8[];
extern const u32 gUnk_083BA4D8[];
extern const u8 gUnk_083AD200[]; // 8 bytes per Medal attribute: base skill levels (init_enemy_bot_medal)
extern const u8 gUnk_083AD2F0[][4]; // 32 part orders (0xFF = end) tried by select_bot_battle_action
extern const u32 gUnk_083BB9CC[][4]; // Medapart name pointers: [part id][kind: head, right arm, left arm, legs]
extern const u32 gUnk_08484444[];
extern vu32 *const gSoundFifoAddrs[]; // REG_FIFO_A, REG_FIFO_B
extern vu32 *const gSoundTimerRegs[]; // REG_TM0CNT, REG_TM1CNT (sample rate timers of FIFO A / B)
extern const u8 gSoundFifoResetBits[]; // SOUNDCNT_H high byte: FIFO A / B reset
extern const u16 gSoundFifoEnableBits[]; // SOUNDCNT_H: FIFO A / B left+right enable
extern vu16 *const gSoundFifoDmaCnt[];
extern const struct SoundTrackConfig gSoundTrackConfigs[13];
extern const u8 gSoundOutputMasks[4]; // SOUNDCNT_L high byte: clears the left/right enables of PSG channel i
extern const u8 gSoundOutputBits[4][4]; // [channel][output: 0 off, 1, 2, 3 both] SOUNDCNT_L high byte bits // REG_DMA1CNT_H, REG_DMA2CNT_H
extern u8 gUnk_030017EC;
extern u8 gUnk_03003870[];
extern u8 gUnk_03005664[];
extern const void *const gUnk_0847E8C4[]; // text pointers (guess)
extern const u32 *const gTextTable[]; // text pointers, banks 0-1 (guess)
extern const u32 *const *const gTextBankTables[]; // text pointer tables, bank 2+ (guess)
extern const s16 gUnk_083D69A0[][8]; // 16 steps; [n][0] / 16 = player sprite y offset (sub_0804DE28, guess: jump arc)
extern const u8 gUnk_083D2998[]; // map script terrain/palette id -> unkC5C/unkC69/unkC28 (sub_0804E324)
extern struct Unk_03002B70 gUnk_03002B70; // = gMoney, with the bytes after it
extern const Func gUnk_083AC248[]; // game state 0 sub-state handlers (guess: debug map viewer)
extern const Func gFieldMenuHandlers[]; // game state 1 (field pause menu) sub-state handlers
extern const void *const gUnk_083B53F8[]; // messages used by game state 0 (guess: debug menu)
extern const void *const gUnk_083CF3B0[]; // message table (run_message)
extern const u8 gUnk_083AC420[]; // orbit centre x, y per gUnk_03000440.unk51
extern const u8 gUnk_083AC432[]; // per slot sprite priority base
extern const u8 gUnk_083AC43B[]; // x, y per team select slot (9)
extern const u8 gUnk_083AC468[]; // team select: cursor slot to move to after a pick, per slot
extern const u8 gUnk_083AC44D[]; // tile x, y per team select slot (9)
extern const u8 *const gMedabotSlotDpadMoves[]; // up, down, left, right: next slot (gUnk_03000440.unk51) per slot
extern const void *const gUnk_083B4AE0[]; // tilemaps (field menu rows: open/close animation frames)
extern const void *gUnk_083B5F80[]; // sprite animation commands (field menu cursor)
extern const u8 gUnk_084C1608[];
extern const u8 gUnk_084C17F0[];
extern const u8 gUnk_084C1934[];
extern const u8 gUnk_084C1ACC[];
extern const u8 gUnk_084C1C14[];
extern const u8 gUnk_08487708[];
extern const u8 gUnk_08487814[];
extern const u16 gUnk_08488A84[];
extern const u8 gUnk_08488690[];
extern const u8 gUnk_08488644[];
extern const u8 gUnk_084C6A98[];
extern const u16 gUnk_084E2E38[];
extern const u8 gUnk_084C7174[];
extern const u16 gUnk_084E2E58[];
extern const u16 gUnk_084E2E78[];
extern const u8 gUnk_084889F8[];
extern const void *const gUnk_083B69C8[]; // messages (run_message), indexed by Medal record byte 4 (Medals help)
extern const void *const gUnk_083B70AC[]; // messages (run_message), indexed by Medal record byte 6 (Medals help)
extern const u8 gUnk_083B7E0C[]; // 3 Medaforce ids per Medal graphic index (slots open at level 10/30/60)
extern const u8 gUnk_083B7CD4[]; // 6-byte Medaforce records: +1 skill type, +2 MF consumption, +5 icon
extern const void *const gUnk_083B7F40[]; // messages (run_message), Medals help Medaforce page
extern const void *const gUnk_083B8170[]; // messages (run_message), Medals help page 5
extern u32 gUnk_03002B68; // bit per Medal graphic index (sub_080092D4); also (part kind << 16) + part id (sub_0800EBB8)
extern const u8 gUnk_084EAC58[];
extern const u8 gUnk_084EF4E0[];
extern const u8 gUnk_084EFE28[];
extern const u8 gUnk_084F0A00[];
extern const u8 gUnk_084F1BA0[];
extern const u16 gUnk_084F32A0[];
extern const Func gMedawatchMenuHandlers[]; // game state 2 (Medawatch menu) sub-state handlers
extern const u8 gUnk_084E30D8[];
extern const u8 gUnk_084EF6A0[];
extern const u8 gUnk_084F023C[];
extern const u8 gUnk_084F0F2C[];
extern const u16 gUnk_084F24E0[];
extern const u8 gUnk_084C1C24[];
extern const u8 gUnk_084C1E04[];
extern const u8 gUnk_084C1FD4[];
extern u8 gUnk_02020000[]; // tilemap rect buffer for the Robattle team-side scroll (status_side_change_scroll_out)
extern u8 gUnk_02020800[]; // BG tile backup (0x800 bytes of VRAM 0x06002800 while a Medawatch submenu runs)
extern const Func gMedabotsScreenHandlers[]; // game state 3 sub-state handlers
extern const Func gMedalsScreenHandlers[]; // game state 4 (Medals screen) sub-state handlers
extern const Func gMedapartsScreenHandlers[]; // game state 5 (Medaparts screen) sub-state handlers
extern const Func gUnk_083ACC94[]; // sprite 4 sub-state handlers, by gUnk_03002C30[4].unk29 (sub_0801013C)
extern const Func gPrebattleScreenHandlers[]; // game state 6 ("Get ready to Robattle") sub-state handlers
extern const u8 gUnk_084C696C[];
extern const void *const gUnk_083C2BBC[]; // pre-battle opponent lines, by gUnk_03001800.unk0
extern const u16 gUnk_084C6A78[];
extern const u8 gUnk_084E6C9C[];
extern const u8 gUnk_084C7D10[];
extern const u8 gUnk_084EFA34[];
extern const u16 gUnk_084F29E0[];
extern const u16 gUnk_084C69D8[];
extern const u16 gUnk_084C69F8[];
extern const u16 gUnk_0850DCF8[];
extern const u16 gUnk_084E2FB8[];
extern const u16 gUnk_084E2F98[];
extern u8 gMedapartInventory[4 * 120 * 2]; // 2 bytes per Medapart, 120 per kind (head, right arm, left arm, legs): [0] count owned (runtime-checked), [1] second count shown on the Medaparts list
// The Medaparts list shows 4 parts per page (part id = page * 4 + row); the game indexes it flat like this.
#define MEDAPART_INV(kind, page, row, byte) gMedapartInventory[(kind) * 240 + (page) * 8 + (row) * 2 + (byte)]
extern u8 gItemInventory[64][2]; // item inventory (runtime-checked): [0] 0x80 | item id, [1] count (get_item_quantity_by_id)
extern const u8 gUnk_083B2970[]; // indexed by gUnk_030057E0.unkC5C (sub_08044B34)
extern const u8 gUnk_083B827C[]; // 16 bytes per Medapart (part id * 64 + kind * 16), copied by load_part_data
extern const u8 gUnk_083B286C[]; // random bytes, indexed by gUnk_03000440.unk8D when unk89 is set (rng_next_080424B8)
extern const u8 gUnk_084EBF50[];
extern const u8 gUnk_084C4014[];
extern const u8 gUnk_084C4330[];
extern const u8 gUnk_084C36F0[];
extern const u8 gUnk_084EF550[];
extern const u8 gUnk_084EFF74[];
extern const u8 gUnk_084F0BF0[];
extern const u8 gUnk_084F1D34[];
extern const u8 gUnk_084ECB3C[];
extern const u8 gUnk_084C43C0[];
extern const u8 gUnk_084C47A0[];
extern const u8 gUnk_084C47E0[];
extern const u8 gUnk_084C4BAC[];
extern const u8 gUnk_084EF5A4[];
extern const u8 gUnk_084F0068[];
extern const u8 gUnk_084F0CA4[];
extern const u8 gUnk_084F1EC8[];
extern const u16 gUnk_084F3460[];
extern const u16 gUnk_084F3620[];
extern const void *const gUnk_083BE3E4[]; // messages (run_message), Medaparts detail help for head / arms, indexed by sub_0800F6CC()
extern const void *const gUnk_083BE92C[]; // messages (run_message), Medaparts detail help for legs, indexed by sub_0800F6CC()
extern const void *const gUnk_083B6E24[]; // messages (run_message), indexed by the part record byte unkEE
extern const void *const gUnk_083BD884[]; // messages (run_message), Medaparts help pages
extern const u8 gUnk_084E7264[];
extern const u8 gUnk_084C32DC[];
extern const u8 gUnk_0848833C[];
extern const u8 gUnk_084EF348[];
extern const u8 gUnk_084EFB5C[];
extern const u8 gUnk_084F04F0[];
extern const u8 gUnk_084F1554[];
extern const u16 gUnk_084F2BA0[];
extern const u16 gUnk_08488B44[];
extern const u16 gUnk_084E2E98[];
extern const u8 gUnk_084E80B0[];
extern const u8 gUnk_084EF380[];
extern const u8 gUnk_084EFBE0[];
extern const u8 gUnk_084F0688[];
extern const u8 gUnk_084F16E8[];
extern const u16 gUnk_084F2D60[];
extern const u8 gUnk_084E9020[];
extern const u8 gUnk_084C3524[];
extern const u8 gUnk_084C3648[];
extern const u8 gUnk_084EF3F4[];
extern const u8 gUnk_084EFCDC[];
extern const u8 gUnk_084F07B8[];
extern const u8 gUnk_084F187C[];
extern const u16 gUnk_084F2F20[];
extern const u8 gUnk_084E9E68[];
extern const u8 gUnk_084C37A4[];
extern const u8 gUnk_084C3990[];
extern const u8 gUnk_084EF46C[];
extern const u8 gUnk_084EFD74[];
extern const u8 gUnk_084F08F0[];
extern const u8 gUnk_084F1A10[];
extern const u16 gUnk_084F30E0[];
extern const void *const gUnk_083B7C00[]; // messages (run_message), indexed by medal_medaforce_get_selected()
extern const void *const gUnk_083B825C[]; // messages (run_message), indexed by a Medal record byte at +0x18 (guess: rotation entries)
extern const u8 gUnk_084E5650[];
extern const u8 gUnk_084C48B4[];
extern const u8 gUnk_084C4A34[];
extern const u8 gUnk_084C7428[];
extern const u8 gUnk_084EF2D8[];
extern const u8 gUnk_084EF95C[];
extern const u8 gUnk_084F02B8[];
extern const u8 gUnk_084F122C[];
extern const u16 gUnk_084F2680[];
extern const u16 gUnk_0850DEF8[];
extern const u16 gUnk_0850DD18[];
extern const u16 gUnk_084E2EB8[];
extern const u16 gUnk_084E2ED8[];
extern const u8 gUnk_084E61CC[];
extern const u8 gUnk_084C3208[];
extern const u8 gUnk_084C33DC[];
extern const u8 gUnk_084C4DB0[];
extern const u8 gUnk_084C7318[];
extern const u8 gUnk_084EF310[];
extern const u8 gUnk_084EF9C8[];
extern const u8 gUnk_084F03EC[];
extern const u8 gUnk_084F13C0[];
extern const u16 gUnk_084F2820[];
extern const u16 gUnk_0850DD58[];

extern const u8 gUnk_084C21BC[]; // Medal icon tiles, 0x80 bytes per graphic index
extern const u8 gUnk_084C30BC[]; // blank Medal icon tile
extern const u8 *const gUnk_083AC494[][5]; // compressed Medal sprites (load_medal_sprite)
extern const u32 gUnk_083B656C[]; // Medal Attribute names, indexed by Medal record unk4 (Ability page)
extern const u32 gUnk_083B6EC8[]; // skill type names (Shoot, Strike, ...): Medal Aim, Medaforce skill
extern const u8 *const gUnk_083B7EBC[]; // Medals help cursor layouts: count, then (x, y) tile pairs (sub_0800AA1C)
extern const u16 gUnk_083AC8AC[]; // (y, x) pairs per Medal skill row 0-7 (setup_battle_cursor_sprite_0800B5E8)
extern const Func gUnk_083AC8CC[]; // sprite 7 sub-state handlers, by gUnk_03002C30[7].unk29 (update_battle_sprite_and_check_done)
extern const Func gDebugMenuHandlers[]; // game state 63 sub-state handlers (debug_menu_update)
extern const Func gDebugMenuEntryHandlers[]; // game state 63: one handler per menu entry (debug_menu_run_entry)
extern const Func gDebugProcessHandlers[]; // game state 63 entry 0 sub-state handlers (debug_process_update)
extern const Func gDebugMedalHandlers[]; // entry 1 (debug_medal_update)
extern const Func gDebugPartsHandlers[]; // entry 2 (debug_parts_update)
extern const u8 *const gDebugMenuLabels[]; // game state 63 menu labels, 11 x 8 bytes: Process, Medal, Parts, Tinpet, Item, Face, Mdlpic, Rnd.tk, Battle, Sound, Motion
extern const u8 *const gDebugProcessLabels[]; // game state 63 "Process" field labels "User", "Func.no", "S.func" (gGameMode / gGameState / gGameSubState; debug_process_input)
extern const u8 *const gDebugMedalLabels[]; // game state 63 "Medal" field labels (3 x 8 bytes; debug_medal_input)
extern const u8 *const gDebugPartsLabels[]; // game state 63 "Parts" field labels (3 x 8 bytes; debug_parts_input)
extern const Func gDebugTinpetHandlers[]; // game state 63 entry 3 sub-state handlers (debug_tinpet_update)
extern const Func gDebugItemHandlers[]; // entry 4 (debug_item_update)
extern const Func gDebugFaceHandlers[]; // entry 5 (debug_face_update)
extern const Func gDebugMdlpicHandlers[]; // entry 6 (debug_mdlpic_update)
extern const Func gDebugRndTkHandlers[]; // entry 7 (debug_rndtk_update)
extern const Func gDebugBattleHandlers[]; // entry 8 (debug_battle_update)
extern const Func gDebugSoundHandlers[]; // entry 9 (debug_sound_update)
extern const Func gDebugMotionHandlers[]; // entry 10 (debug_motion_update; 4 sub-states)
extern const u8 *const gDebugTinpetLabels[]; // "Get"
extern const u8 *const gDebugItemLabels[]; // "Get", "Lost", "All"
extern const u8 *const gDebugFaceLabels[]; // "No", "Look" (also used by the Mdlpic entry)
extern const u8 *const gDebugMdlpicLabels[]; // "No", "Lv" (unused: debug_mdlpic_input reads gDebugFaceLabels)
extern const u8 *const gDebugRndTkLabels[]; // "Switch"
extern const u8 *const gDebugBattleLabels[]; // "No"
extern const u8 *const gDebugSoundLabels[]; // "Se", "Bgm"
extern const u8 *const gDebugMotionLabels[]; // "No"
extern const u8 gUnk_084C3B14[]; // tiles, 5 rows of 0x100 bytes, 0x20 per Medals tab (sub_0800B0F8)
extern const u32 gUnk_083B7338[]; // Medaforce names, indexed by Medaforce id
extern const u32 gUnk_083BE97C[]; // Medapart skill names for ids >= 100 (medapart_detail_draw_skill)
extern u16 gUnk_03002B84[2]; // capped at 9999: [0] every game state 6 battle, [1] when gUnk_03000440.unk9C == 1 (runtime-checked; guess: Robattles fought / won)
extern const void *const gUnk_083C3984[]; // after-battle opponent lines, by gUnk_03001800.unk0
extern const void *const gUnk_083C65C4[]; // messages (after-battle screen uses 107, 109, 118)
extern const u8 *const gUnk_083C6DE8[]; // Medapart kind names, by kind
extern const u8 gUnk_084D7C9C[]; // LZ tiles (after-battle screen sprite 1)
extern const u8 gUnk_084D7DB0[]; // LZ tiles (after-battle screen sprite 2)
extern const u16 gUnk_0850E9D8[]; // OBJ palette (sprite 1)
extern const u16 gUnk_084E2F98[]; // OBJ palette (sprite 2)

extern const u8 *const gUnk_083C3F38[]; // opponent names, by gUnk_03001800.unk0
extern const u8 *const gUnk_083BE9E8[]; // battlefield names, by gUnk_03001800.unk38
extern const u8 gUnk_083BEA90[][8]; // per area: [1] = battlefield (load_area_battlefield)
extern const u8 gUnk_083BF090[][4]; // per area: random encounter ids, picked 40/30/20/10% (setup_random_encounter_enemies)
extern const u8 *const gUnk_083C1A00[]; // encounter setups (0x28 bytes copied to gUnk_03001800), by gUnk_030057E0.unkC2A
extern const u8 gUnk_083ACEE4[][2]; // per opponent Medabot: sprite position (init_opponent_medabot_sprites)
extern const u8 gUnk_083ACEEA[][2]; // per opponent Medabot: leg type icon position (draw_opponent_leg_type_icons)
extern const u8 gUnk_083ACEF0[16]; // random starting opponent slot 0-2 (sub_08012234, sub_080122F4)
extern const u8 gUnk_083C3B04[][8]; // per battlefield (sub_080121A8)
extern const Func gRobattleHandlers[]; // game state 7 (Robattle) sub-state handlers
extern const void *const gUnk_083B24A8[]; // 5 compressed graphics pointers per battlefield (gUnk_03001800.unk38)
extern const u16 gUnk_084E2F58[]; // Robattle palette (OBJ palette 10, sub_0801303C)
extern const u16 gUnk_084E3038[]; // Robattle palette (OBJ palette 6, sub_0801303C)
extern const u16 gUnk_084E2F38[]; // Robattle palette (OBJ palette 10)
extern const u16 gUnk_084E2F78[]; // Robattle palette (OBJ palette 10)

extern const u8 gUnk_084ED4C4[];
extern const u8 gUnk_084C50D8[];
extern const u8 gUnk_084C50BC[];
extern const u8 gUnk_084EF5DC[];
extern const u8 gUnk_084F0128[];
extern const u8 gUnk_084F0D24[];
extern const u8 gUnk_084F205C[];
extern const u16 gUnk_084F37E0[];

extern const u8 gUnk_084C84E4[];
extern const u16 gUnk_084E2FD8[];

extern const u16 gUnk_0850DDF8[];

extern const u8 gUnk_08488764[]; // Robattle screen tilemaps (compressed)
extern const u8 gUnk_08488830[];
extern const u8 gUnk_08488744[];
extern const u8 gUnk_084887A4[];
extern const u8 gUnk_084887F4[];
extern const u8 *const gUnk_083C466C[]; // 12-byte name text, by gUnk_03001800.unk81 (command_ring_draw_name)
extern const u8 gUnk_083AD370[]; // angles for compute_polar_to_screen_position, by sprite slot - gUnk_03001800.unk81 (command_ring_init_icon)
extern const u8 gUnk_083AD376[]; // next slot after a right turn of the ring, by gUnk_03001800.unk81 (command_ring_input)
extern const u8 gUnk_083AD37C[]; // next slot after a left turn
extern const u8 gUnk_083AD382[]; // 4-byte records: sprite count, start value, x, y (sub_08016370, animate_battle_sprites)
extern const u8 gUnk_083AD3A0[]; // part select: centre sprite frame by gUnk_03001800.unk82 (part_select_init_center_icon)
extern const u8 *const gUnk_083C4A10[]; // part select status texts: [0] part broken (unk11 == 0), [1] sealed, [2] head out of uses, [3] unk82 == 0
extern const u32 gUnk_083BE6E8[]; // names by part skill id (part data[1]; part_select_draw_skill_name)
extern const u8 gUnk_084888A8[];
extern const u8 gUnk_0848895C[];
extern const u8 gUnk_084888E4[];
extern const u8 gUnk_08488920[];
extern u8 gUnk_02021000[]; // BG tile backup, second half (see gUnk_02020800)
extern const u8 gUnk_083AD39A[]; // Robattle sub-state per command ring slot (command_ring_goto_selected)
extern const u8 gUnk_083AD3A4[]; // battle bot screen positions (x, y) per record 0-5 (position_battle_team_cursors)

#endif // GUARD_VARIABLES_H
extern u8 gUnk_03001788; // picks the Robattle TIME limit: 0 = 40, 1 = 30, 2 = 20 (robattle_time_init)
extern u8 gUnk_03000B94; // index into gUnk_083AD3B0 (battle music)
extern const u8 gUnk_083AD3B0[]; // battle song ids (select_battle_music)
extern const u8 gUnk_083C4C10[]; // per leg type (skill id - 100), 11 bytes: one per battlefield (gUnk_03001800.unk38); added to unkBB (sub_080191E4)
extern const s8 gUnk_083AD3B3[]; // 32 y steps of the number pop-up over a Medabot (battle_number_popup_update)
extern const u8 gUnk_083AD3D3[]; // 32 random record orders (find_next_active_bot)
extern const u8 gUnk_083AD3F3[]; // record remap when gUnk_03000B90 is set in a link Robattle (find_next_active_bot)
extern const u8 gUnk_083AD3F9[]; // record remap for unkE0 (sub_0801C0A0)
extern const struct GfxListEntry *const gUnk_083CE480[]; // graphics lists (decompress_indexed_graphics_to_ewram)
extern const void *const gUnk_083B2584[]; // pairs: compressed tiles [i * 2], palette [i * 2 + 1]
extern const Func gUnk_083AD400[]; // message steps by gUnk_03001800.unkA1[0] (sub_0801C0BC)
extern const Func gUnk_083AD410[]; // steps by gUnk_03001800.unk9C[0] (sub_0801C154)
extern const Func gUnk_083AD424[]; // steps by gUnk_03001800.unk9C[0] (dispatch_battle_action_substate)
extern const Func gUnk_083AD44C[]; // by gUnk_03001800.unkAA (sub_0801C4FC)
extern const Func gUnk_083AD50C[]; // by gUnk_03001800.unkAA (battle_dispatch_phase_handler_0801D2F0)
extern const Func gUnk_083AD530[]; // by gUnk_03001800.unkAA (sub_0801D380)
extern const Func gUnk_083AD550[]; // by gUnk_03001800.unkAA (sub_0801D40C)
extern const Func gUnk_083AD570[]; // by gUnk_03001800.unkAA (sub_0801D580)
extern const Func gUnk_083AD5B0[]; // by gUnk_03001800.unkAA (sub_0801DE1C)
extern const Func gUnk_083AD5D0[]; // by gUnk_03001800.unkAA (sub_0801DEE4)
extern const Func gUnk_083AD610[]; // by gUnk_03001800.unkAA (sub_0801E2D8)
extern const u8 gUnk_084C8AC4[]; // compressed OBJ tiles (sub_0801C188)
extern const u16 gUnk_084E3078[]; // OBJ palette (sub_0801C188)
extern const u16 gUnk_084E2EF8[]; // OBJ palette 8 (sub_0801C32C)
extern const u16 gUnk_084E2F18[]; // OBJ palette 9 (sub_0801C40C)
extern const u8 gUnk_084C907C[]; // compressed OBJ tiles, sub_0801C6C4 case 0
extern const u8 gUnk_084C9288[]; // case 1
extern const u8 gUnk_084C9624[]; // case 2
extern const u8 gUnk_084C978C[]; // case 3
extern const u16 gUnk_0850E058[]; // OBJ palettes for the same cases
extern const u16 gUnk_0850E078[];
extern const u16 gUnk_0850E098[];
extern const u16 gUnk_0850E0B8[];
extern const u8 gUnk_084CDBD8[]; // compressed OBJ tiles (sub_0801CD50)
extern const u16 gUnk_0850E378[]; // its OBJ palette (palette 7)
extern const u8 gUnk_084CC9A8[]; // compressed OBJ tiles (sub_0801CDD4)
extern const u16 gUnk_0850E338[]; // its OBJ palette (palette 7)
extern const u8 gUnk_084C6A98[]; // compressed OBJ tiles at 0x06017400 (sub_0801E09C)
extern const u16 gUnk_084E3038[]; // OBJ palette 6 (sub_0801D434)
extern const u8 gUnk_084C9880[]; // compressed OBJ tiles, sub_0801D6A4 for unkDF 0x1B
extern const u8 gUnk_084C9B88[]; // 0x1C
extern const u8 gUnk_084C9E9C[]; // 0x1D
extern const u16 gUnk_0850E0F8[]; // their OBJ palettes
extern const u16 gUnk_0850E118[];
extern const u16 gUnk_0850E138[];
extern const u8 gUnk_0848886C[]; // Robattle screen tilemap (compressed), opponent side of gUnk_08488830 (sub_0801AC98)
extern u8 gUnk_03001360; // Robattle: nonzero skips the message windows unless gUnk_03000440.unk89 == 1 (sub_0801ABF8..sub_0801AC6C)
extern const u8 gUnk_084E3058[]; // 32-byte OBJ palette, copied to OBJ palette 6 (sub_0801B004)
extern u32 gUnk_030018A8[16]; // cleared in two 32-byte halves by sub_0801B274
extern const u8 gUnk_084C4F00[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_084882F4[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_084C65C8[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_08488B24[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084E3098[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084C6A58[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CC430[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E2D8[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CC7C8[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E318[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CB950[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E258[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CBC10[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E278[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CBF04[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E298[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CC19C[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E2B8[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084D1824[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E018[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CCE48[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E358[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CA61C[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E198[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CA428[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E178[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CC5F8[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E2F8[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084D18EC[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E498[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CDCD4[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E398[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_0850DFF8[]; // 32-byte OBJ palette (code_0801C988)
extern const Func gUnk_083AD750[]; // by gUnk_03001800.unkAA (sub_0801F484)
extern const u8 gUnk_084CA89C[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E1B8[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CE154[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E3B8[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CE644[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E3D8[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CEF14[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E3F8[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CF340[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E418[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CAB58[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E1D8[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CAFD8[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E1F8[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CB36C[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E218[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_084CB684[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E238[]; // 32-byte OBJ palette (code_0801C988)
extern const Func gUnk_083AD794[]; // by gUnk_03001800.unkAA (sub_0801FA40)
extern struct Unk_083B4AE0 gUnk_083B4AE0_s; // same address as gUnk_083B4AE0
extern const Func gUnk_083AD7D4[]; // by gUnk_03001800.unkAA (sub_0801FDEC)
extern const u8 gUnk_084CA1A4[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_084D1074[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_084D01EC[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_084D073C[]; // compressed tiles (code_0801C988)
extern const u8 gUnk_0850E158[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_0850E478[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_0850E438[]; // 32-byte OBJ palette (code_0801C988)
extern const u8 gUnk_0850E458[]; // 32-byte OBJ palette (code_0801C988)
extern const Func gUnk_083AD814[]; // by gUnk_03001800.unkAA (sub_08020050)
extern const Func gUnk_083AD878[]; // by gUnk_03001800.unkAA (sub_0802057C)
extern const Func gUnk_083AD898[]; // by gUnk_03001800.unkAA (sub_080207A4)
extern const Func gUnk_083AD8B8[]; // by gUnk_03001800.unkAA (sub_0802081C)
extern const Func gUnk_083AD8D8[]; // by gUnk_03001800.unkAA (sub_080208C0)
extern const Func gUnk_083AD93C[]; // by gUnk_03001800.unkAA (sub_080209B0)
extern const Func gUnk_083AD95C[]; // by gUnk_03001800.unkAA (sub_08020A68)
extern const Func gUnk_083AD9C0[]; // by gUnk_03001800.unkAA (sub_08020CFC)
extern const Func gUnk_083ADA6C[]; // by gUnk_03001800.unkAA (sub_080218BC)
extern const u8 gUnk_084D50DC[]; // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E658[]; // 32-byte OBJ palette (code_080209B0)
extern const u8 gUnk_084D513C[]; // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E678[]; // 32-byte OBJ palette (code_080209B0)
extern const u8 gUnk_084D54BC[]; // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E698[]; // 32-byte OBJ palette (code_080209B0)
extern const Func gUnk_083ADAEC[]; // by gUnk_03001800.unkAA (sub_08021E04)
extern const Func gUnk_083ADB2C[]; // by gUnk_03001800.unkAA (sub_08022154)
extern const Func gUnk_083ADB6C[]; // by gUnk_03001800.unkAA (sub_080223BC)
extern const u8 gUnk_084D55D0[]; // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E6B8[]; // 32-byte OBJ palette (code_080209B0)
extern const u8 gUnk_084D5788[]; // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E6D8[]; // 32-byte OBJ palette (code_080209B0)
extern const Func gUnk_083ADBAC[]; // by gUnk_03001800.unkAA (sub_080227D8)
extern const u8 gUnk_084D5860[]; // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E6F8[]; // 2 OBJ palettes (code_080209B0)
extern const Func gUnk_083ADC0C[]; // by gUnk_03001800.unkAA (sub_08022CA8)
extern const u8 gUnk_084D5B08[]; // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E738[]; // 2 OBJ palettes (code_080209B0)
extern const Func gUnk_083ADC6C[]; // by gUnk_03001800.unkAA (sub_08022FF0)
extern const u8 gUnk_084D5D78[]; // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E778[]; // 2 OBJ palettes (code_080209B0)
extern const Func gUnk_083ADCC0[]; // by gUnk_03001800.unkAA (sub_0802342C)
extern const u8 gUnk_084D5EBC[]; // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E7B8[]; // 32-byte OBJ palette (code_080209B0)
extern const Func gUnk_083ADD20[]; // by gUnk_03001800.unkAA (sub_08023730)
extern const u8 gUnk_084D6098[]; // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E7D8[]; // 32-byte OBJ palette (code_080209B0)
extern const Func gUnk_083ADD80[]; // by gUnk_03001800.unkAA (sub_08023AC8)
extern const u8 gUnk_084D61DC[]; // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E7F8[]; // 32-byte OBJ palette (code_080209B0)
extern const Func gUnk_083ADDE0[]; // by gUnk_03001800.unkAA (sub_08023C90)
extern const u8 gUnk_084D6320[]; // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E818[]; // 32-byte OBJ palette (code_080209B0)
extern const Func gUnk_083ADE60[]; // by gUnk_03001800.unkAA (sub_08024090)
extern const u8 gUnk_084D6464[]; // compressed tiles (code_080209B0)
extern const u8 gUnk_0850E838[]; // 32-byte OBJ palette (code_080209B0)
extern const u8 gUnk_083ADEE0[]; // 4 bytes, sprite unk25 for slots 0x26-0x29 (sub_08024488)
extern const Func gUnk_083ADEE4[]; // by gUnk_03001800.unkAA (sub_08024998)
extern const u8 gUnk_084D651C[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E858[]; // 32-byte OBJ palette (code_080249C0)
extern const u8 gUnk_084D6780[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E878[]; // 64-byte OBJ palettes (code_080249C0)
extern const Func gUnk_083ADF44[]; // by gUnk_03001800.unkAA (sub_08024E04)
extern const Func gUnk_083ADFA4[]; // by gUnk_03001800.unkAA (sub_0802518C)
extern const u8 gUnk_084D6AAC[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E8B8[]; // 64-byte OBJ palettes (code_080249C0)
extern const u8 gUnk_084D6BFC[]; // compressed tiles (code_080249C0)
extern const Func gUnk_083AE004[]; // by gUnk_03001800.unkAA (dispatch_battle_action_step)
extern const u8 gUnk_084D6CC4[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E8F8[]; // 32-byte OBJ palette (code_080249C0)
extern const u8 gUnk_084D6E20[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E918[]; // 32-byte OBJ palette (code_080249C0)
extern const Func gUnk_083AE064[]; // by gUnk_03001800.unkAA (sub_08025AF8)
extern const u8 gUnk_084D6F88[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E938[]; // 32-byte OBJ palette (code_080249C0)
extern const Func gUnk_083AE0E4[]; // by gUnk_03001800.unkAA (sub_08025F2C)
extern const Func gUnk_083AE100[]; // by gUnk_03001800.unkAA (sub_08025FA0)
extern const Func gUnk_083AE118[]; // by gUnk_03001800.unkAA (sub_08026108)
extern const u8 gUnk_084D71D8[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E978[]; // 32-byte OBJ palette (code_080249C0)
extern const Func gUnk_083AE16C[]; // by gUnk_03001800.unkAA (sub_0802645C)
extern const u8 gUnk_084D7528[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_0850E998[]; // 64-byte OBJ palettes (code_080249C0)
extern const Func gUnk_083AE1C0[]; // by gUnk_03001800.unkAA (sub_08026884)
extern const Func gUnk_083AE240[]; // by gUnk_03001800.unkAA (sub_08026CF4)
extern const Func gUnk_083AE300[]; // by gUnk_03001800.unkAA (sub_08026ED0)
extern const Func gUnk_083AE380[]; // by gUnk_03001800.unkAA (sub_08026FD0)
extern const u8 gUnk_084DB788[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EB38[]; // 64-byte OBJ palettes (code_080249C0)
extern const Func gUnk_083AE400[]; // by gUnk_03001800.unkAA (sub_0802793C)
extern const Func gUnk_083AE440[]; // by gUnk_03001800.unkAA (sub_08027F5C)
extern const u8 gUnk_084DBB28[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_084E30B8[]; // 64-byte OBJ palettes (code_080249C0)
extern const u8 gUnk_084DBCAC[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EB58[]; // 64-byte OBJ palettes (code_080249C0)
extern const u8 gUnk_084DBD0C[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EB78[]; // 64-byte OBJ palettes (code_080249C0)
extern const u8 gUnk_084DBD60[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EB98[]; // 64-byte OBJ palettes (code_080249C0)
extern const Func gUnk_083AE480[]; // by gUnk_03001800.unkAA (sub_08028248)
extern const u8 gUnk_084DBDC8[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EBB8[]; // 64-byte OBJ palettes (code_080249C0)
extern const Func gUnk_083AE4C0[]; // by gUnk_03001800.unkAA (sub_08028404)
extern const u8 gUnk_084DBEE4[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EBD8[]; // 64-byte OBJ palettes (code_080249C0)
extern const u8 gUnk_084DC100[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EBF8[]; // 64-byte OBJ palettes (code_080249C0)
extern const u8 gUnk_084DC544[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EC18[]; // 64-byte OBJ palettes (code_080249C0)
extern const u8 gUnk_084DC7D0[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EC38[]; // 64-byte OBJ palettes (code_080249C0)
extern const u8 gUnk_084DD188[]; // compressed tiles (code_080249C0)
extern const u8 gUnk_0850EC78[]; // 64-byte OBJ palettes (code_080249C0)
extern const u8 *const gUnk_083AFD08[][9]; // LZ assets by set and index (decompress_indexed_asset)
extern const u16 *const gUnk_083B15C8[]; // palettes by asset set (decompress_indexed_asset)
extern const u16 gUnk_084C6998[]; // text window OBJ palette (text_window_init)
extern const u8 gUnk_08488540[]; // LZ text window graphics (code_0803CDCC)
extern const u8 gUnk_084C31BC[]; // LZ text window graphics (code_0803CDCC)
extern const u8 gUnk_084873D0[]; // LZ text window graphics (code_0803CDCC)
extern const u16 gUnk_0850EF58[]; // OBJ palettes (link Robattle screen, sub_0803DCDC)
extern const u16 gUnk_084F39A0[]; // BG palettes (link Robattle screen, sub_0803DCDC)
extern const u8 gUnk_084F21E8[]; // LZ graphics (link Robattle screen, sub_0803DCDC)
extern const u8 gUnk_084F0D9C[]; // LZ graphics (link Robattle screen, sub_0803DCDC)
extern const u8 gUnk_084F0194[]; // LZ graphics (link Robattle screen, sub_0803DCDC)
extern const u8 gUnk_084EF668[]; // LZ graphics (link Robattle screen, sub_0803DCDC)
extern const u8 gUnk_084E20F8[]; // LZ graphics (link Robattle screen, sub_0803DCDC)
extern const u8 gUnk_084C68E0[]; // LZ graphics (link Robattle screen, sub_0803DCDC)
extern const u8 gUnk_084C66B8[]; // LZ graphics (link Robattle screen, sub_0803DCDC)
extern const u8 gUnk_084EDEF0[]; // LZ graphics (link Robattle screen, sub_0803DCDC)
extern const s16 gUnk_083AFAB8[]; // y offsets by sprite unk23 (0-31; sub_0803C680)
extern const u8 gUnk_083AFAAC[]; // BG3 parallax shift by battlefield gUnk_03001800.unk38 (sub_0803BE44)
extern const Func gUnk_083AF96C[]; // sprite handlers by unk29, slots 1-0x27 (battle_sequence_update_sprites)
extern const u8 *const gUnk_083AF95C[]; // pairs: compressed OBJ tiles (sub_08044B28 to 0x02000000), OBJ palette 14 (sub_0803B19C)
extern const struct Unk_083AF94C gUnk_083AF94C[]; // 4 sprite positions (sub_0803B0C0)
extern const Func gUnk_083AF720[]; // sprite handlers by unk29 for slots 0x21-0x3B (sub_0803884C)
extern const u16 gUnk_083AF520[]; // 4 (x, y) particle offsets, x and y picked by separate rng & 3 rolls (spawn_battle_particle_effect)
extern const u16 gUnk_083AF6D0[]; // 4 (x, y) offsets from the source sprite, picked by rng & 3 (sub_08038428)
extern const u8 gUnk_083CED08[]; // random part ids (sub_08037578)
extern const u8 gUnk_083CED88[]; // random part ids (sub_08037578)
extern const u8 gUnk_083CEE08[]; // random part ids (sub_08037578)
extern const u8 gUnk_083CEE88[]; // random part ids (sub_08037578)
extern const u8 gUnk_083CEEC8[]; // random part ids (sub_08037578)
extern const u8 gUnk_083CEF08[]; // random part ids (sub_08037578)
extern const u8 gUnk_083CEF48[]; // random part ids (sub_08037578)
extern const u8 gUnk_083CEF88[]; // random part ids (sub_08037578)
extern const u8 gUnk_083CEFC8[]; // random part ids (sub_08037578)
extern const u8 gUnk_083CF008[]; // random part ids (sub_08037578)
extern const u8 gUnk_083CF048[]; // random part ids (sub_08037578)
extern const u8 gUnk_083CF088[]; // random part ids (sub_08037578)
extern const u8 gUnk_083CF0C8[]; // random part ids (sub_08037578)
extern const u8 gUnk_083CF108[]; // random part ids (sub_08037578)
extern const u8 gUnk_083CF148[]; // random part ids (sub_08037578)
extern const void *gUnk_083B6010[]; // sprite animation commands (update_sprite_animations_tick_080370AC)
extern const u16 gUnk_083AF490[]; // x, y offset pairs per sprite of a 4-sprite group (sub_08036784)
extern const u16 gUnk_083AF440[]; // (dx, dy) s16 pairs by sprite unk23, added to the sprite position (sub_080366DC)
extern const u16 gUnk_083AF400[]; // (dx, dy) s16 pairs by sprite unk23, added to the sprite position (sub_080366DC)
extern const u16 gUnk_083AF3C0[]; // (dx, dy) s16 pairs by sprite unk23, added to the sprite position (sub_080366DC)
extern const u16 gUnk_083AF380[]; // (dx, dy) s16 pairs by sprite unk23, added to the sprite position (sub_080366DC)
extern const u16 gUnk_083AF4E0[]; // 32 y offsets added to a sprite's unk4 by sub_08037424
extern const u8 gUnk_083AF4A0[]; // 16 y offsets added to a sprite's unk4 by advance_sprite_anim_frame
extern const u8 gUnk_083AF4B0[]; // 16 x offsets added to / subtracted from a sprite's unk2 by medal_update_exp_progress
extern const u8 gUnk_083AF210[]; // 256 speed steps (quarter pixels) by a sprite's unk30 (sprite_move_toward_target, update_sprite_deceleration)
extern const u16 gUnk_083AF670[]; // 16 x offsets by a sprite's unk2D & 15 (sub_080380F0)
extern const u8 gUnk_083AF630[]; // radius steps (byte pairs) by a sprite's unk2D & 31 (sub_08037C50)
extern const u8 gUnk_083AF330[]; // 8 entries per sub_08035590 result, one picked at random (get_random_battle_weight_entry)
extern const u8 gUnk_084889B4[]; // compressed tilemap (sub_08036340)
extern u8 gUnk_0300056F; // sprite slot whose handler is running (sub_080383E8)
extern const Func gUnk_083AF690[]; // battle effect sprite handlers by sprite unk29 (sub_080383E8, sprites 0x2B-0x3B)
extern const Func gUnk_083AF530[]; // sprite handlers by sprite unk29 (sub_08037B9C, sprites 0x21-0x3B)
extern const s16 *const gUnk_083CDFE4[]; // battle sequence scripts, by gUnk_03001800.unkF9 (load_battle_sequence_commands)
extern const u8 gUnk_083CE1F4[]; // operand count per battle sequence command (battle_advance_sequence_counter)
extern const u16 *const gUnk_083CEC74[]; // x, y passed to init_game_state_entry, by sprite 4 unk2B (sub_080398AC)
extern const u8 *const gUnk_083AF888[]; // by sequence operand: 4 animation sets, by legs data[1] - 0x64 (3 when gUnk_03001800.unk64[3] > 0x77; sub_08039AC8)
extern const u8 *const gUnk_083AF88C[]; // pairs: compressed OBJ tiles, OBJ palette 14 (sub_0803A0E0)
extern const Func gUnk_083AF740[]; // battle sequence commands, by sub_0803D424() (battle_sequence_run_command)
extern const Func gUnk_083AF6E0[]; // sprite handlers by sprite unk29 (sub_080385F8, sprites 0x21-0x3B)
extern const u16 gUnk_083AF480[]; // x, y offset pairs by part (sub_08036C20)
extern const u8 gUnk_083AF200[]; // 16 values, two random picks summed into gUnk_03001800.unk188 / unk189 (sub_08034AA0)
extern u8 gUnk_03003470[]; // IWRAM buffer; sub_08033ACC copies 4 x 0x40 bytes from +0xE40 + (rec * 0x100) to its start
extern const u8 gUnk_083C6D38[]; // Robattle action script: operand count per command byte (battle_script_advance)
extern const u8 gUnk_083AF310[]; // 32 y offsets added to a sprite's unk4 by sub_080353CC
extern const u8 *const gUnk_083C6B28[]; // Robattle action scripts by skill id gUnk_03001800.unkA8 (battle_script_read_byte)
extern const Func gUnk_083AF000[]; // Robattle action script commands by script byte < 0x80 (battle_run_action_script; script from gUnk_083C6B28[gUnk_03001800.unkA8] at offset unkBC, battle_script_read_byte)
extern const Func gUnk_083AEF10[]; // Robattle AI: action validity checks by part skill id data[1]; set gUnk_03001800.unk51 = 1 to reject (begin_battle_action_lookup)
extern const u8 gUnk_083AEF00[]; // 16 slot numbers 0-2 picked by rng & 15 (rng_lookup_table_value)
extern const Func gUnk_083AEE10[]; // Robattle AI: action handlers by part skill id data[1] (call_bot_action_handler)
extern const Func gUnk_083AED20[]; // Robattle AI: action selection handlers by part skill id data[1] (battle_execute_action_selection)
extern const u8 gUnk_083AED18[]; // sprite 0x22 palette bits (unkA) by the levelled-up skill type gUnk_03001800.unk166 (sub_08031458)
extern const u8 gUnk_084D796C[]; // compressed OBJ tiles at 0x06014800 (sub_08031390)
extern u8 gUnk_0300198A[]; // 18-byte name copied when gUnk_03000440.unk89 == 1 (sub_080310A0; guess: link opponent name)
extern u8 gUnk_03002B74[]; // 14-byte name copied for message 2 when gUnk_03000440.unk9C == 1 (sub_080310A0; guess: player name)
extern const u8 gUnk_084E2FF8[]; // 32-byte OBJ palette (code_0802CA5C)
extern const Func gUnk_083AEB58[]; // by gGameSubState (battle_action_state_update)
extern const u8 gUnk_084E1EA4[]; // compressed tiles (code_0802CA5C)
extern const Func gUnk_083AEB18[]; // by gUnk_03001800.unkAA (sub_0802FE50)
extern const u8 gUnk_0850EF18[]; // 32-byte OBJ palette (code_0802CA5C)
extern const u8 gUnk_084E1B98[]; // compressed tiles (code_0802CA5C)
extern const Func gUnk_083AEAD8[]; // by gUnk_03001800.unkAA (sub_0802F990)
extern const u8 gUnk_0850EEF8[]; // 32-byte OBJ palette (code_0802CA5C)
extern const u8 gUnk_084E1884[]; // compressed tiles (code_0802CA5C)
extern const Func gUnk_083AEA84[]; // by gUnk_03001800.unkAA (sub_0802F628)
extern const Func gUnk_083AEA44[]; // by gUnk_03001800.unkAA (sub_0802F030)
extern const u8 gUnk_084E17E0[]; // compressed tiles (code_0802CA5C)
extern const Func gUnk_083AEA08[]; // by gUnk_03001800.unkAA (sub_0802EBC0)
extern const u8 gUnk_084E3018[]; // 32-byte OBJ palette (code_0802CA5C)
extern const u8 gUnk_0850EED8[]; // 32-byte OBJ palette (code_0802CA5C)
extern const u8 gUnk_084E1518[]; // compressed tiles (code_0802CA5C)
extern const Func gUnk_083AE99C[]; // by gUnk_03001800.unkAA (battle_dispatch_phase_handler_0802E424)
extern const u8 gUnk_083AE988[]; // pairs (sprite unk25 frame or 0xFF end, wait frames) by sprite unk23 (sub_0802DE1C)
extern const u8 gUnk_0850EEB8[]; // 32-byte OBJ palette (code_0802CA5C)
extern const u8 gUnk_084E046C[]; // compressed tiles (code_0802CA5C)
extern const Func gUnk_083AE908[]; // by gUnk_03001800.unkAA (sub_0802DCB4)
extern const u8 gUnk_0850EE98[]; // 32-byte OBJ palette (code_0802CA5C)
extern const u8 gUnk_084E0360[]; // compressed tiles (code_0802CA5C)
extern const Func gUnk_083AE8B0[]; // by gUnk_03001800.unkAA (sub_0802D688)
extern const Func gUnk_083AE854[]; // by gUnk_03001800.unkAA (sub_0802CBE8)
extern const u8 gUnk_084DFFE4[]; // compressed tiles (code_08028A00)
extern const u8 gUnk_0850EE78[]; // 32-byte OBJ palette (code_08028A00)
extern const Func gUnk_083AE814[]; // by gUnk_03001800.unkAA (sub_0802C644)
extern const Func gUnk_083AE7D4[]; // by gUnk_03001800.unkAA (sub_0802C2AC)
extern const u8 gUnk_083AE7D0[]; // frame counts (sub_0802BE44)
extern const Func gUnk_083AE790[]; // by gUnk_03001800.unkAA (sub_0802BD6C)
extern const u8 gUnk_084DFC18[]; // compressed tiles (code_08028A00)
extern const u8 gUnk_0850EE38[]; // 64-byte OBJ palettes (code_08028A00)
extern const Func gUnk_083AE750[]; // by gUnk_03001800.unkAA (sub_0802B7E8)
extern const u8 gUnk_084DFBD4[]; // compressed tiles (code_08028A00)
extern const u8 gUnk_0850EDF8[]; // 64-byte OBJ palettes (code_08028A00)
extern const Func gUnk_083AE700[]; // by gUnk_03001800.unkAA (sub_0802B000)
extern const u8 gUnk_084DFA88[]; // compressed tiles (code_08028A00)
extern const u8 gUnk_0850EDB8[]; // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_0850ED98[]; // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_084DF400[]; // compressed tiles (code_08028A00)
extern const Func gUnk_083AE6C0[]; // by gUnk_03001800.unkAA (sub_0802ACCC)
extern const u8 gUnk_0850ED78[]; // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_084DF024[]; // compressed tiles (code_08028A00)
extern const Func gUnk_083AE680[]; // by gUnk_03001800.unkAA (sub_0802AAD0)
extern const u8 gUnk_0850ED58[]; // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_084DED1C[]; // compressed tiles (code_08028A00)
extern const Func gUnk_083AE640[]; // by gUnk_03001800.unkAA (sub_0802A6AC)
extern const u8 gUnk_0850ED38[]; // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_084DE628[]; // compressed tiles (code_08028A00)
extern const Func gUnk_083AE600[]; // by gUnk_03001800.unkAA (sub_0802A0E8)
extern const u8 gUnk_0850ECF8[]; // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_084DDEA4[]; // compressed tiles (code_08028A00)
extern const Func gUnk_083AE5C0[]; // by gUnk_03001800.unkAA (sub_08029E0C)
extern const u8 gUnk_0850ED18[]; // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_084DE4BC[]; // compressed tiles (code_08028A00)
extern const u8 gUnk_0850ECD8[]; // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_084DD894[]; // compressed tiles (code_08028A00)
extern const Func gUnk_083AE580[]; // by gUnk_03001800.unkAA (sub_08029840)
extern const u8 gUnk_0850ECB8[]; // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_084DD648[]; // compressed tiles (code_08028A00)
extern const Func gUnk_083AE500[]; // by gUnk_03001800.unkAA (sub_08028C40)
extern const Func gUnk_083AE540[]; // by gUnk_03001800.unkAA (sub_080294B4)
extern const u8 gUnk_084DD45C[]; // compressed tiles (code_08028A00)
extern const u8 gUnk_0850EC98[]; // 64-byte OBJ palettes (code_08028A00)
extern const u8 gUnk_084DCF54[]; // compressed tiles (code_08028A00)
extern const u8 gUnk_0850EC58[]; // 64-byte OBJ palettes (code_08028A00)
extern const Func gUnk_083B27D4[]; // by gUnk_03000440.unk1B (sub_080408F4)
extern const Func gUnk_083B27EC[]; // by gUnk_03000440.unk1B (sub_08040914)
extern const Func gUnk_083B2804[]; // by gUnk_03000440.unk1B (sub_08040934)
extern const Func gUnk_083B2808[]; // by gUnk_03000440.unk1B (sub_08040954)
extern const Func gUnk_083B2810[]; // by gUnk_03000440.unk1B (sub_08040974)
extern const u8 gUnk_083AFC78[32]; // battlefields, picked at random into gUnk_03001800.unk38 (sub_0803D71C)
extern const Func gUnk_083B279C[]; // run_message states by gUnk_03000440.unk4: message_open, message_dim_palettes_step, message_show_window, ..., message_run_command (runtime-checked in 03_new_game_intro)
extern const Func gUnk_083B27C0[]; // message commands, by the byte after gUnk_03000440.unk8[unkC] (message_run_command)
extern const u8 gUnk_083AFC98[16][6]; // 6 bytes picked at random into gUnk_03001800.unk18A[0x10] (sub_0803E8B8)
extern const u8 gUnk_084C01C8[]; // 64 bytes of tiles copied 52 times to VRAM 0x280 (sub_08040B5C)
extern u8 gUnk_0300199A[6]; // 6 bytes from gUnk_083AFC98 (sub_0803E8B8); = gUnk_03001800.unk18A + 0x10
extern const u8 gUnk_083AFCF8[16]; // record index 0-2 picked at random (sub_0803EE10)
extern const u8 gUnk_083B4C88[][2]; // per character code: [0] width in pixels (render_text_sprites_08040DB8)
extern const Func gUnk_083AFAF8[]; // link Robattle game state: sub-state handlers by gGameSubState (sub_0803D538)
extern const u8 gUnk_08487524[]; // compressed tiles, message window frame style 3 (sub_08040A40)
extern const u8 gUnk_084885A8[]; // compressed tilemap, message window frame style 3 (sub_08040A40)
extern const u8 gUnk_08487630[]; // compressed tiles, message window frame style 2 (sub_08040A40)
extern const u8 gUnk_08488600[]; // compressed tilemap, message window frame style 2 (sub_08040A40)
extern const u8 gUnk_083C3B5C[][8]; // per battlefield, copied to gUnk_03001800.unk74 (load_battle_script_entry_b)
extern const Func gUnk_083B2814[]; // choice menu states by gUnk_03000440.unk29 (poll_choice_menu)
extern const Func gUnk_083B284C[]; // by gUnk_03000440.unk1B (game_state_execute_handler_a)
extern const Func gUnk_083B2864[]; // by gUnk_03000440.unk1B (game_state_execute_handler_b)
extern const u8 *const gUnk_083B23F8[]; // 4 compressed graphics pointers per entry: tiles, BG palette, BG2 / BG3 tilemaps (decompress_tileset_to_vram)
extern const u8 gUnk_084878EC[]; // compressed tiles (decompress_bg_tilemap_to_vram)
extern const u8 gUnk_0848796C[]; // compressed tiles
extern const u8 gUnk_084886D0[]; // compressed tilemap
extern const u8 gUnk_08488718[]; // compressed tilemap
extern const u8 gUnk_083C40B8[]; // per battlefield: animation tile count / 8 (advance_battle_animation_frame)
extern const u8 gUnk_083C40C3[]; // [battlefield][0x80]: animation tile block per frame, 0xFF = loop
