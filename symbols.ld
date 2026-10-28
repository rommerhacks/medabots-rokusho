/* Absolute addresses of variables and data referenced from decompiled C.
   RAM: until the IWRAM/EWRAM layout is reconstructed. ROM: until the data is split out of baserom.gba. */

/* ===== RAM ===== */

/* main.c */
gFrameCounter       = 0x03001780;
gGameMode           = 0x0300178C;
gGameState          = 0x03002B8C;
gGameSubState       = 0x0300137C;

/* keys */
gPrevKeys           = 0x03001790;
gRepeatKeys         = 0x03001798;
gNewKeys            = 0x0300058C;
gReleasedKeys       = 0x03001C00;
gHeldKeys           = 0x03002B64;
gKeyRepeatTimer     = 0x03002418;
gMoney       = 0x03002B70;
gPlayerRecord       = 0x03002B70;
gScriptCmdWork       = 0x03006D20;
gGameWork       = 0x03000440;
gPlayTimeRunning       = 0x03000588;
gSpriteEntries       = 0x03002C30;
gSoundWork       = 0x03007014;
gSoundWorkArea       = 0x03002430;
gSioLink            = 0x03005170;
gOamAffineZoomOverride       = 0x03005048;
gBg2AffineScanlineBuffer2       = 0x02030A00;
gLinkBufferSwapIwram       = 0x03005250;
gSerialTransferHandlerIwram       = 0x03005050;
gBattleWork       = 0x03001800;
gSceneWork     = 0x03001800;
gBombGameWork = 0x03001800;
gMedals       = 0x03000BE0;
gTeamSlots       = 0x030017A0;
gFieldDebug       = 0x030057A0;
gMapScriptData      = 0x03005590;
gFieldWork       = 0x030057E0;

/* main.c / irq */
gLinkPackets       = 0x03005010;
gLinkMultiplayerActive       = 0x03005030;
gVBlankFlags       = 0x03002B90;
gFramesSinceMainLoop       = 0x03002410;
gIntrTable          = 0x03000BA0;
gIntrMain           = 0x03001C10;
gVBlankCallback     = 0x030017F0;
gVBlankOnceCallback = 0x03000B98;
gHBlankCallback     = 0x03002C20;
gOamBuffer          = 0x03001380;
gTilemapBaseEntry   = 0x03000580;
gSpriteWork       = 0x03002414;
gMedabotSpriteSlots       = 0x03005308;
gVBlankOamMode       = 0x03000430;
gVBlankBgFlags       = 0x03000434;
gBgScrollOffset       = 0x03002C2C;
gBg0Scroll       = 0x03005000;
gDecompressBuffer   = 0x02030000;
gPaletteBackup      = 0x0202F800;
gPaletteBuffer      = 0x0202FC00;
gPaletteBackupBg    = 0x0202FA00;
gPaletteBufferBg    = 0x0202FE00;
gRngCounter         = 0x03005034;
gRngValue           = 0x03005038;
gRngState           = 0x0300503C;
gFieldScriptWork       = 0x030064A0;
gFieldEffect       = 0x03005350;
gBattleBots       = 0x03000590;
gEffectSpriteSlot       = 0x0300056F;
gLinkPartnerBotData       = 0x03000890;
gLinkPlayerId       = 0x03000B90;
gOptionBattleMusic       = 0x03000B94;
gOptionTimeLimit       = 0x03001788;
gBg1Scroll       = 0x03004C30;
gFieldState       = 0x03005310;
gBlendEffect       = 0x03006F40;
gMenuWork       = 0x03006F74;
gEntityStates       = 0x030055A0;
gBg2Scroll       = 0x0300057C;
gBg3Scroll       = 0x03001C04;
gEventFlags       = 0x030057D8;
gFieldTilemapBuf       = 0x03006D14;
gFieldSceneParams       = 0x03006D38;

/* ===== ROM data ===== */
gCurrentMedalSlot    = 0x030017EC;
gNpcSpriteEntryBytes    = 0x03003870;
gNpcEntityStateBytes    = 0x03005664;

/* code_0800025C: debug state 0, field menu (game state 1) */
gLinkTradeData       = 0x03002B68;

/* code_0800025C: Medawatch menu (game state 2) */
gTextComposeTile       = 0x02020000;
gTextGlyphTile       = 0x02020040;
gBgTileBackup       = 0x02020800;

/* code_0800025C: game state 3 */

/* code_080043A8: game state 4 (Medals screen) */

/* code_0800C6D8: game state 5 (Medaparts screen) */
gMedapartInventory  = 0x03004C40;
gItemInventory       = 0x03002BA0;
gRobattleCounts      = 0x03002B84;

/* code_08010794: game state 7 (Robattle) */

/* code_080147FC: Robattle screen tilemaps */
gBgTileBackupHigh       = 0x02021000;
gOptionSkipMessages       = 0x03001360;
gBattleWorkActionVars       = 0x030018A8;
gGuardSpriteEntryBytes       = 0x03003470;
gLinkPartnerName       = 0x0300198A;
gPlayerName       = 0x03002B74;
gPrizeGameSlots       = 0x0300199A;
gRightArmPartLayer       = 0x03005290;
gLeftArmPartLayer       = 0x030052B0;
gHeadPartLayer       = 0x030052D0;
gLegPartLayer       = 0x030052F0;
gAreaAnimTileSrc       = 0x030057DC;
gFieldUnusedWord       = 0x0300534C;
gAffineParams       = 0x03006D40;
gFieldEffectEntities       = 0x03006D30;
gListWorkBuffer       = 0x02023000;
gListScrollTop       = 0x02023078;
gSaveStatus       = 0x03001784;
gShopId = 0x03002420;
gTitleSkipIntro = 0x03007008;
gRaceRunnerParts = 0x03006FA0;
gRaceAnimDelay = 0x03006FEC;
gRaceAnimTimers = 0x03006FF0;
gRaceRivalTapTimers = 0x03006FF8;
gRaceRivalTaps = 0x03007000;
gNameEntryMode = 0x03000584;
gRaceStep = 0x03006F88;
gRaceRunner = 0x03006F8C;
gRaceNextSubState = 0x03006F80;
gRaceField = 0x03006F84;
gRaceLegTypes = 0x03006FD0;
gRaceStepTimers = 0x03006FE0;
gRaceStaticBg = 0x03006F90;
gRaceFinishOrder = 0x03006F94;
gRaceId = 0x03006FDC;
gSceneStepFrames = 0x03000000;
gSceneStep = 0x03000004;
gTransitionFramesPerLevel = 0x03000005;
gTransitionWipeRows = 0x03000008;
gTransitionFadeColor = 0x03000028;
gTransitionSourcePalette = 0x0300002C;
gTitleBg2PaTable = 0x03000030;
gTitleBg2XLowTable = 0x03000170;
gTitleBg2XHighTable = 0x030002B0;
gTitleBg2ScrollX = 0x030003F0;
gTextArgBuffer = 0x030004DE;
gWeeklyAnimTiles = 0x02031000;
gWeeklyAnimTiles2 = 0x02031100;
gWeeklyCycleAnimMask = 0x03007010;
gWeeklyFlashPalette = 0x0300700C;
gScanlineScrollEven       = 0x02023200;
gScanlineScrollOdd       = 0x02023C00;
gOamBuildFlags       = 0x03000438;
gSpritePerspCenterX       = 0x03005040;
gSpritePerspOffsetY       = 0x03005044;
gSpritePerspCenterY       = 0x0300504C;
gSpriteCameraPos       = 0x03002C24;
gSpriteScreenOffset       = 0x03001794;
gFieldPlayerX       = 0x03006432;
gFieldPlayerY       = 0x03006434;
