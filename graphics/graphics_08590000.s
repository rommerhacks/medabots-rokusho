	.section .rodata

	.global gData_08590000
gData_08590000:
	.incbin "baserom.gba", 0x590000, 0x50A38

	.global gMapSpriteSheet37Palette
gMapSpriteSheet37Palette:
	.incbin "baserom.gba", 0x5E0A38, 0x20

	.global gMapSpriteSheet37Tiles
gMapSpriteSheet37Tiles:
	.incbin "baserom.gba", 0x5E0A58, 0xF94

	.global gMapSpriteSheet40Palette
gMapSpriteSheet40Palette:
	.incbin "baserom.gba", 0x5E19EC, 0x20

	.global gMapSpriteSheet40Tiles
gMapSpriteSheet40Tiles:
	.incbin "baserom.gba", 0x5E1A0C, 0x1894

	.global gMapSpriteSheet46Palette
gMapSpriteSheet46Palette:
	.incbin "baserom.gba", 0x5E32A0, 0x20

	.global gMapSpriteSheet46Tiles
gMapSpriteSheet46Tiles:
	.incbin "baserom.gba", 0x5E32C0, 0x7E8

	.global gMapSpriteSheet48Palette
gMapSpriteSheet48Palette:
	.incbin "baserom.gba", 0x5E3AA8, 0x20

	.global gMapSpriteSheet48Tiles
gMapSpriteSheet48Tiles:
	.incbin "baserom.gba", 0x5E3AC8, 0x1661C

	.global gFieldSharedSpritePalette
gFieldSharedSpritePalette:
	.incbin "baserom.gba", 0x5FA0E4, 0x20

	.global gUnk_085FA104
gUnk_085FA104:
	.incbin "baserom.gba", 0x5FA104, 0x40

	.global gVehicleMenuNameTiles
gVehicleMenuNameTiles:
	.incbin "baserom.gba", 0x5FA144, 0x394

	.global gVehicleMenuNamesTilemap
gVehicleMenuNamesTilemap:
	.incbin "baserom.gba", 0x5FA4D8, 0x100

	.global gVehicleMenuBlankRowTiles
gVehicleMenuBlankRowTiles:
	.incbin "baserom.gba", 0x5FA5D8, 0x48

	.global gVehicleMenuBlankRowTilemap
gVehicleMenuBlankRowTilemap:
	.incbin "baserom.gba", 0x5FA620, 0x20

	.global gVehicleIconPalette
gVehicleIconPalette:
	.incbin "baserom.gba", 0x5FA640, 0x20

	.global gMiniSWheelIconTiles
gMiniSWheelIconTiles:
	.incbin "baserom.gba", 0x5FA660, 0x88

	.global gSilverLocketIconTiles
gSilverLocketIconTiles:
	.incbin "baserom.gba", 0x5FA6E8, 0x8C

	.global gWingsOfWindIconTiles
gWingsOfWindIconTiles:
	.incbin "baserom.gba", 0x5FA774, 0x88

	.global gPeriscopeIconTiles
gPeriscopeIconTiles:
	.incbin "baserom.gba", 0x5FA7FC, 0x60

	.global gVehicleIconDimPalette
gVehicleIconDimPalette:
	.incbin "baserom.gba", 0x5FA85C, 0x20

	.global gMiniSWheelIconDimTiles
gMiniSWheelIconDimTiles:
	.incbin "baserom.gba", 0x5FA87C, 0x88

	.global gSilverLocketIconDimTiles
gSilverLocketIconDimTiles:
	.incbin "baserom.gba", 0x5FA904, 0x8C

	.global gWingsOfWindIconDimTiles
gWingsOfWindIconDimTiles:
	.incbin "baserom.gba", 0x5FA990, 0x88

	.global gPeriscopeIconDimTiles
gPeriscopeIconDimTiles:
	.incbin "baserom.gba", 0x5FAA18, 0x80

	.global gVehicleIconBlankTiles
gVehicleIconBlankTiles:
	.incbin "baserom.gba", 0x5FAA98, 0x16A218

	.global gMapScripts
gMapScripts:
	.incbin "baserom.gba", 0x764CB0, 0x20000

	.global gMenuDigitTilesLz
gMenuDigitTilesLz:
	.incbin "baserom.gba", 0x784CB0, 0xF4

	.global gMenuObjTilesLz
gMenuObjTilesLz:
	.incbin "baserom.gba", 0x784DA4, 0x1190

	.global gCommonObjTilesLz
gCommonObjTilesLz:
	.incbin "baserom.gba", 0x785F34, 0x12B0

	.global gTownMapBgPalettes
gTownMapBgPalettes:
	.incbin "baserom.gba", 0x7871E4, 0x1C0

	.global gTownMapAnimTiles
gTownMapAnimTiles:
	.incbin "baserom.gba", 0x7873A4, 0x420

	.global gTownMapBgTiles
gTownMapBgTiles:
	.incbin "baserom.gba", 0x7877C4, 0x3080

	.global gTownMapBg1Tilemap
gTownMapBg1Tilemap:
	.incbin "baserom.gba", 0x78A844, 0xD4

	.global gTownMapBg2Tilemap
gTownMapBg2Tilemap:
	.incbin "baserom.gba", 0x78A918, 0xF4

	.global gTownMapBg3Tilemap
gTownMapBg3Tilemap:
	.incbin "baserom.gba", 0x78AA0C, 0x46C

	.global gItemMenuBgPalettes
gItemMenuBgPalettes:
	.incbin "baserom.gba", 0x78AE78, 0x200

	.global gItemMenuBgTiles
gItemMenuBgTiles:
	.incbin "baserom.gba", 0x78B078, 0x140C

	.global gItemMenuBg1Tilemap
gItemMenuBg1Tilemap:
	.incbin "baserom.gba", 0x78C484, 0x130

	.global gItemMenuBg2Tilemap
gItemMenuBg2Tilemap:
	.incbin "baserom.gba", 0x78C5B4, 0x19C

	.global gItemMenuBg3Tilemap
gItemMenuBg3Tilemap:
	.incbin "baserom.gba", 0x78C750, 0x314

	.global gSaveScreenBgPalettes
gSaveScreenBgPalettes:
	.incbin "baserom.gba", 0x78CA64, 0x200

	.global gSaveScreenBgTiles
gSaveScreenBgTiles:
	.incbin "baserom.gba", 0x78CC64, 0x11AC

	.global gSaveScreenBg1Tilemap
gSaveScreenBg1Tilemap:
	.incbin "baserom.gba", 0x78DE10, 0x1D0

	.global gSaveScreenBg2Tilemap
gSaveScreenBg2Tilemap:
	.incbin "baserom.gba", 0x78DFE0, 0x124

	.global gSaveScreenBg3Tilemap
gSaveScreenBg3Tilemap:
	.incbin "baserom.gba", 0x78E104, 0x2F0

	.global gTitleMenuBgPalette
gTitleMenuBgPalette:
	.incbin "baserom.gba", 0x78E3F4, 0x200

	.global gTitleMenuBgTiles
gTitleMenuBgTiles:
	.incbin "baserom.gba", 0x78E5F4, 0x15C0

	.global gTitleMenuBg0Tilemap
gTitleMenuBg0Tilemap:
	.incbin "baserom.gba", 0x78FBB4, 0x1D0

	.global gTitleMenuBg1Tilemap
gTitleMenuBg1Tilemap:
	.incbin "baserom.gba", 0x78FD84, 0x244

	.global gTitleMenuBg2Tilemap
gTitleMenuBg2Tilemap:
	.incbin "baserom.gba", 0x78FFC8, 0x160

	.global gTitleMenuBg3Tilemap
gTitleMenuBg3Tilemap:
	.incbin "baserom.gba", 0x790128, 0x2D8

	.global gTestModeBgPalette
gTestModeBgPalette:
	.incbin "baserom.gba", 0x790400, 0x200

	.global gTestModeBgTiles
gTestModeBgTiles:
	.incbin "baserom.gba", 0x790600, 0x1094

	.global gTestModeBg1Tilemap
gTestModeBg1Tilemap:
	.incbin "baserom.gba", 0x791694, 0x160

	.global gTestModeBg2Tilemap
gTestModeBg2Tilemap:
	.incbin "baserom.gba", 0x7917F4, 0x1D0

	.global gTestModeBg3Tilemap
gTestModeBg3Tilemap:
	.incbin "baserom.gba", 0x7919C4, 0x2E4

	.global gSaveLostBgPalette
gSaveLostBgPalette:
	.incbin "baserom.gba", 0x791CA8, 0xE0

	.global gSaveLostBgTiles
gSaveLostBgTiles:
	.incbin "baserom.gba", 0x791D88, 0xF48

	.global gSaveLostBg0Tilemap
gSaveLostBg0Tilemap:
	.incbin "baserom.gba", 0x792CD0, 0x19C

	.global gSaveLostBg1Tilemap
gSaveLostBg1Tilemap:
	.incbin "baserom.gba", 0x792E6C, 0x158

	.global gSaveLostBg3Tilemap
gSaveLostBg3Tilemap:
	.incbin "baserom.gba", 0x792FC4, 0x464

	.global gNameEntryBgPalettes
gNameEntryBgPalettes:
	.incbin "baserom.gba", 0x793428, 0x200

	.global gNameEntryBgTiles
gNameEntryBgTiles:
	.incbin "baserom.gba", 0x793628, 0x1844

	.global gNameEntryBg1Tilemap
gNameEntryBg1Tilemap:
	.incbin "baserom.gba", 0x794E6C, 0x2E0

	.global gNameEntryBg2Tilemap
gNameEntryBg2Tilemap:
	.incbin "baserom.gba", 0x79514C, 0x2CC

	.global gNameEntryBg3Tilemap
gNameEntryBg3Tilemap:
	.incbin "baserom.gba", 0x795418, 0x184

	.global gGameOverBgPalette
gGameOverBgPalette:
	.incbin "baserom.gba", 0x79559C, 0x200

	.global gGameOverBgTiles
gGameOverBgTiles:
	.incbin "baserom.gba", 0x79579C, 0xB4C

	.global gGameOverBg0Tilemap
gGameOverBg0Tilemap:
	.incbin "baserom.gba", 0x7962E8, 0x18C

	.global gGameOverBg2Tilemap
gGameOverBg2Tilemap:
	.incbin "baserom.gba", 0x796474, 0x124

	.global gGameOverBg3Tilemap
gGameOverBg3Tilemap:
	.incbin "baserom.gba", 0x796598, 0x184

	.global gShopMenuBgPalettes
gShopMenuBgPalettes:
	.incbin "baserom.gba", 0x79671C, 0x200

	.global gShopMenuBgTiles
gShopMenuBgTiles:
	.incbin "baserom.gba", 0x79691C, 0x1CEC

	.global gShopMenuBg1Tilemap
gShopMenuBg1Tilemap:
	.incbin "baserom.gba", 0x798608, 0x21C

	.global gShopMenuBg2Tilemap
gShopMenuBg2Tilemap:
	.incbin "baserom.gba", 0x798824, 0x210

	.global gShopMenuBg3Tilemap
gShopMenuBg3Tilemap:
	.incbin "baserom.gba", 0x798A34, 0x2F8

	.global gShopListBgPalettes
gShopListBgPalettes:
	.incbin "baserom.gba", 0x798D2C, 0x200

	.global gShopMenuBgTiles2
gShopMenuBgTiles2:
	.incbin "baserom.gba", 0x798F2C, 0x90C

	.global gShopMenuPanelTilemap1
gShopMenuPanelTilemap1:
	.incbin "baserom.gba", 0x799838, 0x1B4

	.global gShopMenuPanelTilemap2
gShopMenuPanelTilemap2:
	.incbin "baserom.gba", 0x7999EC, 0x1AC

	.global gMedalRenameBgPalettes
gMedalRenameBgPalettes:
	.incbin "baserom.gba", 0x799B98, 0x200

	.global gMedalRenameBgTiles
gMedalRenameBgTiles:
	.incbin "baserom.gba", 0x799D98, 0x89C

	.global gMedalRenameBg1Tilemap
gMedalRenameBg1Tilemap:
	.incbin "baserom.gba", 0x79A634, 0x158

	.global gMedalRenameBg2Tilemap
gMedalRenameBg2Tilemap:
	.incbin "baserom.gba", 0x79A78C, 0x130

	.global gMedalRenameBg3Tilemap
gMedalRenameBg3Tilemap:
	.incbin "baserom.gba", 0x79A8BC, 0x184

	.global gLinkMenuBgPalette
gLinkMenuBgPalette:
	.incbin "baserom.gba", 0x79AA40, 0x200

	.global gLinkMenuBgTiles
gLinkMenuBgTiles:
	.incbin "baserom.gba", 0x79AC40, 0x142C

	.global gLinkMenuBg1Tilemap
gLinkMenuBg1Tilemap:
	.incbin "baserom.gba", 0x79C06C, 0x1F4

	.global gLinkMenuBg2Tilemap
gLinkMenuBg2Tilemap:
	.incbin "baserom.gba", 0x79C260, 0x140

	.global gLinkMenuBg3Tilemap
gLinkMenuBg3Tilemap:
	.incbin "baserom.gba", 0x79C3A0, 0x2FC

	.global gPartTradeBgPalette
gPartTradeBgPalette:
	.incbin "baserom.gba", 0x79C69C, 0x200

	.global gPartTradeBgTiles
gPartTradeBgTiles:
	.incbin "baserom.gba", 0x79C89C, 0x1530

	.global gPartTradeBg1Tilemap
gPartTradeBg1Tilemap:
	.incbin "baserom.gba", 0x79DDCC, 0x178

	.global gPartTradeAnimFramesTilemap
gPartTradeAnimFramesTilemap:
	.incbin "baserom.gba", 0x79DF44, 0x298

	.global gPartTradeBg3Tilemap
gPartTradeBg3Tilemap:
	.incbin "baserom.gba", 0x79E1DC, 0x2FC

	.global gMedalTradeBgPalettes
gMedalTradeBgPalettes:
	.incbin "baserom.gba", 0x79E4D8, 0x140

	.global gMedalTradeBgTiles
gMedalTradeBgTiles:
	.incbin "baserom.gba", 0x79E618, 0x14F8

	.global gMedalTradeAnimFramesTilemap
gMedalTradeAnimFramesTilemap:
	.incbin "baserom.gba", 0x79FB10, 0x2B0

	.global gMedalTradeBg1Tilemap
gMedalTradeBg1Tilemap:
	.incbin "baserom.gba", 0x79FDC0, 0x13C

	.global gMedalTradeBg2Tilemap
gMedalTradeBg2Tilemap:
	.incbin "baserom.gba", 0x79FEFC, 0x154

	.global gMedalTradeBg3Tilemap
gMedalTradeBg3Tilemap:
	.incbin "baserom.gba", 0x7A0050, 0x2FC

	.global gScrollBannerBgPalette
gScrollBannerBgPalette:
	.incbin "baserom.gba", 0x7A034C, 0x120

	.global gScrollBannerBgTiles2
gScrollBannerBgTiles2:
	.incbin "baserom.gba", 0x7A046C, 0xC18

	.global gScrollBannerBg3Tilemap
gScrollBannerBg3Tilemap:
	.incbin "baserom.gba", 0x7A1084, 0x32C

	.global gTextScrollBgPalettes
gTextScrollBgPalettes:
	.incbin "baserom.gba", 0x7A13B0, 0x60

	.global gTextScrollBgTiles
gTextScrollBgTiles:
	.incbin "baserom.gba", 0x7A1410, 0x28EC

	.global gTextScrollBg0Tilemap
gTextScrollBg0Tilemap:
	.incbin "baserom.gba", 0x7A3CFC, 0x168

	.global gTextScrollBg2Tilemap
gTextScrollBg2Tilemap:
	.incbin "baserom.gba", 0x7A3E64, 0x23C

	.global gTextScrollBg3Tilemap
gTextScrollBg3Tilemap:
	.incbin "baserom.gba", 0x7A40A0, 0x458

	.global gMedalSceneObjPalettes
gMedalSceneObjPalettes:
	.incbin "baserom.gba", 0x7A44F8, 0x200

	.global gMedalSceneBgTiles
gMedalSceneBgTiles:
	.incbin "baserom.gba", 0x7A46F8, 0x38A0

	.global gMedalSceneBg1Tilemap
gMedalSceneBg1Tilemap:
	.incbin "baserom.gba", 0x7A7F98, 0x150

	.global gMedalSceneBg2Tilemap
gMedalSceneBg2Tilemap:
	.incbin "baserom.gba", 0x7A80E8, 0x23C

	.global gMedalSceneBg3Tilemap
gMedalSceneBg3Tilemap:
	.incbin "baserom.gba", 0x7A8324, 0x5A8

	.global gScrollBannerStripTiles
gScrollBannerStripTiles:
	.incbin "baserom.gba", 0x7A88CC, 0xA08

	.global gScrollBannerBgTiles
gScrollBannerBgTiles:
	.incbin "baserom.gba", 0x7A92D4, 0xEC8

	.global gBombGameObjTiles
gBombGameObjTiles:
	.incbin "baserom.gba", 0x7AA19C, 0x3348

	.global gRaceObjTiles
gRaceObjTiles:
	.incbin "baserom.gba", 0x7AD4E4, 0x8F8

	.global gTitleObjTiles
gTitleObjTiles:
	.incbin "baserom.gba", 0x7ADDDC, 0x3F10

	.global gWeeklyObjTiles
gWeeklyObjTiles:
	.incbin "baserom.gba", 0x7B1CEC, 0xFE0

	.global gRaceBgTiles
gRaceBgTiles:
	.incbin "baserom.gba", 0x7B2CCC, 0xA44

	.global gRaceBg2Tilemap
gRaceBg2Tilemap:
	.incbin "baserom.gba", 0x7B3710, 0x13C

	.global gRaceBg3Tilemap
gRaceBg3Tilemap:
	.incbin "baserom.gba", 0x7B384C, 0x2A4

	.global gRaceBgPalette
gRaceBgPalette:
	.incbin "baserom.gba", 0x7B3AF0, 0x40

	.global gBombGameBgTiles
gBombGameBgTiles:
	.incbin "baserom.gba", 0x7B3B30, 0x157C

	.global gBombGameBgTilemap1
gBombGameBgTilemap1:
	.incbin "baserom.gba", 0x7B50AC, 0x168

	.global gBombGameBgTilemap2
gBombGameBgTilemap2:
	.incbin "baserom.gba", 0x7B5214, 0xD0

	.global gBombGameBgTilemap3
gBombGameBgTilemap3:
	.incbin "baserom.gba", 0x7B52E4, 0x238

	.global gBombGameBgPalettes
gBombGameBgPalettes:
	.incbin "baserom.gba", 0x7B551C, 0xA0

	.global gTitleBgTiles
gTitleBgTiles:
	.incbin "baserom.gba", 0x7B55BC, 0x45B0

	.global gTitleBg2Tiles
gTitleBg2Tiles:
	.incbin "baserom.gba", 0x7B9B6C, 0x240

	.global gTitleBgPalettes
gTitleBgPalettes:
	.incbin "baserom.gba", 0x7B9DAC, 0xC0

	.global gTitleBg0Tilemap
gTitleBg0Tilemap:
	.incbin "baserom.gba", 0x7B9E6C, 0x240

	.global gTitleBg1Tilemap
gTitleBg1Tilemap:
	.incbin "baserom.gba", 0x7BA0AC, 0x540

	.global gTitleBg2Tilemap
gTitleBg2Tilemap:
	.incbin "baserom.gba", 0x7BA5EC, 0x280

	.global gIntroSilhouetteBgTiles
gIntroSilhouetteBgTiles:
	.incbin "baserom.gba", 0x7BA86C, 0x33A4

	.global gIntroSilhouetteBgPalettes
gIntroSilhouetteBgPalettes:
	.incbin "baserom.gba", 0x7BDC10, 0x200

	.global gIntroSilhouetteBg1Tilemap
gIntroSilhouetteBg1Tilemap:
	.incbin "baserom.gba", 0x7BDE10, 0x37C

	.global gIntroSilhouetteBg3Tilemap
gIntroSilhouetteBg3Tilemap:
	.incbin "baserom.gba", 0x7BE18C, 0x308

	.global gIntroScanBgTiles
gIntroScanBgTiles:
	.incbin "baserom.gba", 0x7BE494, 0x252C

	.global gIntroScanBgPalettes
gIntroScanBgPalettes:
	.incbin "baserom.gba", 0x7C09C0, 0x200

	.global gIntroScanBg2Tilemap
gIntroScanBg2Tilemap:
	.incbin "baserom.gba", 0x7C0BC0, 0x24C

	.global gIntroScanBg3Tilemap
gIntroScanBg3Tilemap:
	.incbin "baserom.gba", 0x7C0E0C, 0x3B8

	.global gWeeklyStudioBgTiles
gWeeklyStudioBgTiles:
	.incbin "baserom.gba", 0x7C11C4, 0x13D4

	.global gWeeklyLectureBgTiles
gWeeklyLectureBgTiles:
	.incbin "baserom.gba", 0x7C2598, 0x1390

	.global gWeeklyStudioBg1Tilemap
gWeeklyStudioBg1Tilemap:
	.incbin "baserom.gba", 0x7C3928, 0x1CC

	.global gWeeklyStudioBg2Tilemap
gWeeklyStudioBg2Tilemap:
	.incbin "baserom.gba", 0x7C3AF4, 0x24C

	.global gWeeklyStudioBg3Tilemap
gWeeklyStudioBg3Tilemap:
	.incbin "baserom.gba", 0x7C3D40, 0x370

	.global gWeeklyLectureBg1Tilemap
gWeeklyLectureBg1Tilemap:
	.incbin "baserom.gba", 0x7C40B0, 0x160

	.global gWeeklyLectureBg2Tilemap
gWeeklyLectureBg2Tilemap:
	.incbin "baserom.gba", 0x7C4210, 0x288

	.global gWeeklyLectureBg3Tilemap
gWeeklyLectureBg3Tilemap:
	.incbin "baserom.gba", 0x7C4498, 0x384

	.global gWeeklyAnimTilesLz
gWeeklyAnimTilesLz:
	.incbin "baserom.gba", 0x7C481C, 0x440

	.global gWeeklyStudioBgPalettes
gWeeklyStudioBgPalettes:
	.incbin "baserom.gba", 0x7C4C5C, 0x1A0

	.global gWeeklyLectureBgPalettes
gWeeklyLectureBgPalettes:
	.incbin "baserom.gba", 0x7C4DFC, 0xC0

	.global gRaceFieldBgTiles
gRaceFieldBgTiles:
	.incbin "baserom.gba", 0x7C4EBC, 0x8C

	.global gRaceFieldBgTiles2
gRaceFieldBgTiles2:
	.incbin "baserom.gba", 0x7C4F48, 0x94

	.global gRaceFieldBgTiles3
gRaceFieldBgTiles3:
	.incbin "baserom.gba", 0x7C4FDC, 0x1E4

	.global gRaceFieldBgTiles4
gRaceFieldBgTiles4:
	.incbin "baserom.gba", 0x7C51C0, 0x88

	.global gRaceFieldBgPalettes
gRaceFieldBgPalettes:
	.incbin "baserom.gba", 0x7C5248, 0x20

	.global gRaceFieldBgPalettes2
gRaceFieldBgPalettes2:
	.incbin "baserom.gba", 0x7C5268, 0x20

	.global gRaceFieldBgPalettes3
gRaceFieldBgPalettes3:
	.incbin "baserom.gba", 0x7C5288, 0x20

	.global gRaceFieldBgPalettes4
gRaceFieldBgPalettes4:
	.incbin "baserom.gba", 0x7C52A8, 0x20

	.global gRaceStatusBarTiles
gRaceStatusBarTiles:
	.incbin "baserom.gba", 0x7C52C8, 0x250

	.global gRaceStatusBarTiles2
gRaceStatusBarTiles2:
	.incbin "baserom.gba", 0x7C5518, 0xB8

	.global gRaceStatusBarPalettes
gRaceStatusBarPalettes:
	.incbin "baserom.gba", 0x7C55D0, 0x20

	.global gRaceStatusBarPalettes2
gRaceStatusBarPalettes2:
	.incbin "baserom.gba", 0x7C55F0, 0x2D78

	.global gIntroSilhouetteBg2Tiles
gIntroSilhouetteBg2Tiles:
	.incbin "baserom.gba", 0x7C8368, 0x4B0

	.global gIntroSilhouetteBg2Palette
gIntroSilhouetteBg2Palette:
	.incbin "baserom.gba", 0x7C8818, 0x20

	.global gIntroSilhouetteBg2Tilemap
gIntroSilhouetteBg2Tilemap:
	.incbin "baserom.gba", 0x7C8838, 0xBC

	.global gIntroScanFontTiles
gIntroScanFontTiles:
	.incbin "baserom.gba", 0x7C88F4, 0x2E4

	.global gIntroPartNameFontTiles
gIntroPartNameFontTiles:
	.incbin "baserom.gba", 0x7C8BD8, 0xBC

	.global gIntroCounterDigitTiles
gIntroCounterDigitTiles:
	.incbin "baserom.gba", 0x7C8C94, 0x50

	.global gIntroPointerLineTiles
gIntroPointerLineTiles:
	.incbin "baserom.gba", 0x7C8CE4, 0x10

	.global gIntroScanTextPalette
gIntroScanTextPalette:
	.incbin "baserom.gba", 0x7C8CF4, 0x20

	.global gIntroScanLabelPalette
gIntroScanLabelPalette:
	.incbin "baserom.gba", 0x7C8D14, 0x20

	.global gIntroScanBgPalette0
gIntroScanBgPalette0:
	.incbin "baserom.gba", 0x7C8D34, 0x20

	.global gIntroScanTextGlyphs
gIntroScanTextGlyphs:
	.incbin "baserom.gba", 0x7C8D54, 0xAC

	.global gIntroUnusedArtTilesLz
gIntroUnusedArtTilesLz:
	.incbin "baserom.gba", 0x7C8E00, 0x39BC

	.global gIntroUnusedArtTilemapLz
gIntroUnusedArtTilemapLz:
	.incbin "baserom.gba", 0x7CC7BC, 0x330

	.global gIntroUnusedArtPalette
gIntroUnusedArtPalette:
	.incbin "baserom.gba", 0x7CCAEC, 0x200

	.global gIntroVersusArtTilesLz
gIntroVersusArtTilesLz:
	.incbin "baserom.gba", 0x7CCCEC, 0x3C68

	.global gIntroVersusArtTilemapLz
gIntroVersusArtTilemapLz:
	.incbin "baserom.gba", 0x7D0954, 0x32C

	.global gIntroVersusArtPalette
gIntroVersusArtPalette:
	.incbin "baserom.gba", 0x7D0C80, 0x200

	.global gIntroCloseupArtTilesLz
gIntroCloseupArtTilesLz:
	.incbin "baserom.gba", 0x7D0E80, 0x33CC

	.global gIntroCloseupArtTilemapLz
gIntroCloseupArtTilemapLz:
	.incbin "baserom.gba", 0x7D424C, 0x318

	.global gIntroCloseupArtPalette
gIntroCloseupArtPalette:
	.incbin "baserom.gba", 0x7D4564, 0x1D5E8

	.global gLicensedByLogoTiles
gLicensedByLogoTiles:
	.incbin "baserom.gba", 0x7F1B4C, 0x300

	.global gLicensedByLogoTilemap
gLicensedByLogoTilemap:
	.incbin "baserom.gba", 0x7F1E4C, 0xEC

	.global gLicensedByLogoPalette
gLicensedByLogoPalette:
	.incbin "baserom.gba", 0x7F1F38, 0x20

	.global gNatsumeLogoTiles
gNatsumeLogoTiles:
	.incbin "baserom.gba", 0x7F1F58, 0x700

	.global gNatsumeLogoTilemap
gNatsumeLogoTilemap:
	.incbin "baserom.gba", 0x7F2658, 0x180

	.global gNatsumeLogoPalette
gNatsumeLogoPalette:
	.incbin "baserom.gba", 0x7F27D8, 0x20

	.global gBootOverlayTiles
gBootOverlayTiles:
	.incbin "baserom.gba", 0x7F27F8, 0x878

	.global gBootOverlayTilemap
gBootOverlayTilemap:
	.incbin "baserom.gba", 0x7F3070, 0x1E0

	.global gBootOverlayPalette
gBootOverlayPalette:
	.incbin "baserom.gba", 0x7F3250, 0x20
