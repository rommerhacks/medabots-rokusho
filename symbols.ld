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
gUnk_03006D20       = 0x03006D20;
gGameWork       = 0x03000440;
gUnk_03000588       = 0x03000588;
gSpriteEntries       = 0x03002C30;
gSoundWork       = 0x03007014;
gSoundWorkArea       = 0x03002430;
gSioLink            = 0x03005170;
gUnk_03005048       = 0x03005048;
gUnk_02030A00       = 0x02030A00;
gUnk_03005250       = 0x03005250;
gUnk_03005050       = 0x03005050;
gBattleWork       = 0x03001800;
gSceneWork     = 0x03001800;
gBombGameWork = 0x03001800;
gMedals       = 0x03000BE0;
gTeamSlots       = 0x030017A0;
gFieldDebug       = 0x030057A0;
gMapScriptData      = 0x03005590;
gFieldWork       = 0x030057E0;

/* main.c / irq */
gUnk_03005010       = 0x03005010;
gUnk_03005030       = 0x03005030;
gUnk_03002B90       = 0x03002B90;
gUnk_03002410       = 0x03002410;
gIntrTable          = 0x03000BA0;
gIntrMain           = 0x03001C10;
gVBlankCallback     = 0x030017F0;
gVBlankOnceCallback = 0x03000B98;
gHBlankCallback     = 0x03002C20;
gOamBuffer          = 0x03001380;
gTilemapBaseEntry   = 0x03000580;
gSpriteWork       = 0x03002414;
gUnk_03005308       = 0x03005308;
gVBlankOamMode       = 0x03000430;
gUnk_03000434       = 0x03000434;
gUnk_03002C2C       = 0x03002C2C;
gBg0Scroll       = 0x03005000;
gDecompressBuffer   = 0x02030000;
gPaletteBackup      = 0x0202F800;
gPaletteBuffer      = 0x0202FC00;
gPaletteBackupBg    = 0x0202FA00;
gPaletteBufferBg    = 0x0202FE00;
gRngCounter         = 0x03005034;
gRngValue           = 0x03005038;
gRngState           = 0x0300503C;
gUnk_03006432       = 0x03006432;
gUnk_03006434       = 0x03006434;
gUnk_030064A0       = 0x030064A0;
gUnk_03005350       = 0x03005350;
gBattleBots       = 0x03000590;
gEffectSpriteSlot       = 0x0300056F;
gUnk_03000890       = 0x03000890;
gUnk_03000B90       = 0x03000B90;
gOptionBattleMusic       = 0x03000B94;
gOptionTimeLimit       = 0x03001788;
gBg1Scroll       = 0x03004C30;
gUnk_03005310       = 0x03005310;
gBlendEffect       = 0x03006F40;
gMenuWork       = 0x03006F74;
gUnk_030055A0       = 0x030055A0;
gBg2Scroll       = 0x0300057C;
gBg3Scroll       = 0x03001C04;
gEventFlags       = 0x030057D8;
gFieldTilemapBuf       = 0x03006D14;
gUnk_03006D38       = 0x03006D38;
gUnk_03003810       = 0x03003810;

/* ===== ROM data ===== */
gCurrentMedalSlot    = 0x030017EC;
gUnk_03003870    = 0x03003870;
gUnk_03005664    = 0x03005664;

/* code_0800025C: debug state 0, field menu (game state 1) */
gUnk_03002B68       = 0x03002B68;

/* code_0800025C: Medawatch menu (game state 2) */
gTextComposeTile       = 0x02020000;
gTextGlyphTile       = 0x02020040;
gUnk_02020800       = 0x02020800;

/* code_0800025C: game state 3 */

/* code_080043A8: game state 4 (Medals screen) */

/* code_0800C6D8: game state 5 (Medaparts screen) */
gMedapartInventory  = 0x03004C40;
gItemInventory       = 0x03002BA0;
gRobattleCounts      = 0x03002B84;

/* code_08010794: game state 7 (Robattle) */

/* code_080147FC: Robattle screen tilemaps */
gUnk_02021000       = 0x02021000;
gOptionSkipMessages       = 0x03001360;
gUnk_030018A8       = 0x030018A8;
gUnk_03003470       = 0x03003470;
gLinkPartnerName       = 0x0300198A;
gPlayerName       = 0x03002B74;
gPrizeGameSlots       = 0x0300199A;
gUnk_03005290       = 0x03005290;
gUnk_030052B0       = 0x030052B0;
gUnk_030052D0       = 0x030052D0;
gUnk_030052F0       = 0x030052F0;
gUnk_030057DC       = 0x030057DC;
gUnk_0300534C       = 0x0300534C;
gAffineParams       = 0x03006D40;
gUnk_03006D30       = 0x03006D30;
gUnk_02023000       = 0x02023000;
gUnk_02023078       = 0x02023078;
gUnk_03001784       = 0x03001784;
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
gUnk_03000000 = 0x03000000;
gUnk_03000004 = 0x03000004;
gUnk_03000005 = 0x03000005;
gUnk_03000008 = 0x03000008;
gUnk_03000028 = 0x03000028;
gUnk_0300002C = 0x0300002C;
gUnk_03000030 = 0x03000030;
gUnk_03000170 = 0x03000170;
gUnk_030002B0 = 0x030002B0;
gUnk_030003F0 = 0x030003F0;
gUnk_030004DE = 0x030004DE;
gWeeklyAnimTiles = 0x02031000;
gWeeklyAnimTiles2 = 0x02031100;
gWeeklyCycleAnimMask = 0x03007010;
gWeeklyFlashPalette = 0x0300700C;
gUnk_03005590 = 0x03005590;
gUnk_02023200       = 0x02023200;
gUnk_02023C00       = 0x02023C00;
gUnk_03000438       = 0x03000438;
gUnk_03005040       = 0x03005040;
gUnk_03005044       = 0x03005044;
gUnk_0300504C       = 0x0300504C;
gUnk_03002C24       = 0x03002C24;
gUnk_03001794       = 0x03001794;
