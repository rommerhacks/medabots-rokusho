	.section .rodata

	.global gData_08480000
gData_08480000:
	.incbin "baserom.gba", 0x480000, 0x37A0

	.global gUnk_084837A0
gUnk_084837A0:
	.incbin "baserom.gba", 0x4837A0, 0x300

	.global gUnk_08483AA0
gUnk_08483AA0:
	.incbin "baserom.gba", 0x483AA0, 0x20

	.global gItemUsable
gItemUsable:
	.incbin "baserom.gba", 0x483AC0, 0x40

	.global gMenuModeStates
gMenuModeStates:
	.incbin "baserom.gba", 0x483B00, 0x78

	.global gTitleMenuStates
gTitleMenuStates:
	.incbin "baserom.gba", 0x483B78, 0x28

	.global gItemMenuStates
gItemMenuStates:
	.incbin "baserom.gba", 0x483BA0, 0x3C

	.global gSaveScreenStates
gSaveScreenStates:
	.incbin "baserom.gba", 0x483BDC, 0x44

	.global gSaveMagic
gSaveMagic:
	.incbin "baserom.gba", 0x483C20, 0x11

	.global gSaveMagicErased
gSaveMagicErased:
	.incbin "baserom.gba", 0x483C31, 0x13

	.global gNameEntryStates
gNameEntryStates:
	.incbin "baserom.gba", 0x483C44, 0x24

	.global gDefaultPlayerName
gDefaultPlayerName:
	.incbin "baserom.gba", 0x483C68, 0x4

	.global gTestModeStates
gTestModeStates:
	.incbin "baserom.gba", 0x483C6C, 0x38

	.global gGameOverStates
gGameOverStates:
	.incbin "baserom.gba", 0x483CA4, 0x20

	.global gSaveLostStates
gSaveLostStates:
	.incbin "baserom.gba", 0x483CC4, 0x1C

	.global gAreaTownMapPlace
gAreaTownMapPlace:
	.incbin "baserom.gba", 0x483CE0, 0xC0

	.global gTownMapStates
gTownMapStates:
	.incbin "baserom.gba", 0x483DA0, 0x20

	.global gTownMapPlacePositions
gTownMapPlacePositions:
	.incbin "baserom.gba", 0x483DC0, 0x14

	.global gUnk_08483DD4
gUnk_08483DD4:
	.incbin "baserom.gba", 0x483DD4, 0x10

	.global gUnk_08483DE4
gUnk_08483DE4:
	.incbin "baserom.gba", 0x483DE4, 0x10

	.global gUnk_08483DF4
gUnk_08483DF4:
	.incbin "baserom.gba", 0x483DF4, 0x10

	.global gUnk_08483E04
gUnk_08483E04:
	.incbin "baserom.gba", 0x483E04, 0xC

	.global gShopMenuStates
gShopMenuStates:
	.incbin "baserom.gba", 0x483E10, 0x40

	.global gShopStock
gShopStock:
	.incbin "baserom.gba", 0x483E50, 0x3C

	.global gUnk_08483E8C
gUnk_08483E8C:
	.incbin "baserom.gba", 0x483E8C, 0x28

	.global gMedalRenameStates
gMedalRenameStates:
	.incbin "baserom.gba", 0x483EB4, 0x2C8

	.global gSceneTextLineCounts
gSceneTextLineCounts:
	.incbin "baserom.gba", 0x48417C, 0x2C8

	.global gItemNames
gItemNames:
	.incbin "baserom.gba", 0x484444, 0xD88

	.global gItemDescriptions
gItemDescriptions:
	.incbin "baserom.gba", 0x4851CC, 0x338

	.global gTownMapPlaceNames
gTownMapPlaceNames:
	.incbin "baserom.gba", 0x485504, 0x28

	.global gShopGreetingText
gShopGreetingText:
	.incbin "baserom.gba", 0x48552C, 0x25

	.global gShopBuyPartTypeText
gShopBuyPartTypeText:
	.incbin "baserom.gba", 0x485551, 0x2F

	.global gShopSellPartTypeText
gShopSellPartTypeText:
	.incbin "baserom.gba", 0x485580, 0xCF

	.global gUnk_0848564F
gUnk_0848564F:
	.incbin "baserom.gba", 0x48564F, 0x139

	.global gUnk_08485788
gUnk_08485788:
	.incbin "baserom.gba", 0x485788, 0x450

	.global gUnk_08485BD8
gUnk_08485BD8:
	.incbin "baserom.gba", 0x485BD8, 0x70

	.global gGameStateHandlers
gGameStateHandlers:
	.incbin "baserom.gba", 0x485C48, 0x20

	.global gSceneTransitionSteps
gSceneTransitionSteps:
	.incbin "baserom.gba", 0x485C68, 0x14

	.global gSceneSteps
gSceneSteps:
	.incbin "baserom.gba", 0x485C7C, 0x14

	.global gRaceSubStates
gRaceSubStates:
	.incbin "baserom.gba", 0x485C90, 0x34

	.global gRaceRunnerSlots
gRaceRunnerSlots:
	.incbin "baserom.gba", 0x485CC4, 0x9

	.global gRaceRivalPace
gRaceRivalPace:
	.incbin "baserom.gba", 0x485CCD, 0x16

	.global gRaceLegDelays
gRaceLegDelays:
	.incbin "baserom.gba", 0x485CE3, 0x4D

	.global gRaceSpriteMotions
gRaceSpriteMotions:
	.incbin "baserom.gba", 0x485D30, 0x2C

	.global gRaceSpriteAnims
gRaceSpriteAnims:
	.incbin "baserom.gba", 0x485D5C, 0x100

	.global gBombGameStates
gBombGameStates:
	.incbin "baserom.gba", 0x485E5C, 0x28

	.global gHalfSineArc
gHalfSineArc:
	.incbin "baserom.gba", 0x485E84, 0x40

	.global gTitleScreenStates
gTitleScreenStates:
	.incbin "baserom.gba", 0x485EC4, 0x30

	.global gTitleSpriteEffects
gTitleSpriteEffects:
	.incbin "baserom.gba", 0x485EF4, 0x20

	.global gTitleSpriteEffectPeriods
gTitleSpriteEffectPeriods:
	.incbin "baserom.gba", 0x485F14, 0x8

	.global gStoryIntroHandlers
gStoryIntroHandlers:
	.incbin "baserom.gba", 0x485F1C, 0x1C

	.global gBootLogosSubStates
gBootLogosSubStates:
	.incbin "baserom.gba", 0x485F38, 0x30

	.global gIntroSubStates
gIntroSubStates:
	.incbin "baserom.gba", 0x485F68, 0x50

	.global gIntroSilhouetteTiles
gIntroSilhouetteTiles:
	.incbin "baserom.gba", 0x485FB8, 0x8

	.global gIntroSilhouetteMaps
gIntroSilhouetteMaps:
	.incbin "baserom.gba", 0x485FC0, 0x8

	.global gIntroSilhouettePals
gIntroSilhouettePals:
	.incbin "baserom.gba", 0x485FC8, 0x8

	.global gIntroScanObjTiles
gIntroScanObjTiles:
	.incbin "baserom.gba", 0x485FD0, 0x8

	.global gIntroObjPals
gIntroObjPals:
	.incbin "baserom.gba", 0x485FD8, 0x54

	.global gIntroScanStrings
gIntroScanStrings:
	.incbin "baserom.gba", 0x48602C, 0x20

	.global gIntroPointerLines
gIntroPointerLines:
	.incbin "baserom.gba", 0x48604C, 0x60

	.global gIntroSpriteActions
gIntroSpriteActions:
	.incbin "baserom.gba", 0x4860AC, 0x14

	.global gIntroSpriteActionPeriods
gIntroSpriteActionPeriods:
	.incbin "baserom.gba", 0x4860C0, 0x8

	.global gMedabotsWeeklySubStates
gMedabotsWeeklySubStates:
	.incbin "baserom.gba", 0x4860C8, 0x4C

	.global gUnk_08486114
gUnk_08486114:
	.incbin "baserom.gba", 0x486114, 0x4

	.global gWeeklySpriteEffects
gWeeklySpriteEffects:
	.incbin "baserom.gba", 0x486118, 0x20

	.global gWeeklyLectureSteps
gWeeklyLectureSteps:
	.incbin "baserom.gba", 0x486138, 0x28

	.global gRaces
gRaces:
	.incbin "baserom.gba", 0x486160, 0x388

	.global gRaceMessages
gRaceMessages:
	.incbin "baserom.gba", 0x4864E8, 0xA04

	.global gStoryIntroTexts
gStoryIntroTexts:
	.incbin "baserom.gba", 0x486EEC, 0x3F0

	.global gWeeklyMessages
gWeeklyMessages:
	.incbin "baserom.gba", 0x4872DC, 0x4C

	.global gStoryIntroTiles
gStoryIntroTiles:
	.incbin "baserom.gba", 0x487328, 0x30

	.global gStoryIntroTilemaps
gStoryIntroTilemaps:
	.incbin "baserom.gba", 0x487358, 0x30

	.global gStoryIntroPalettes
gStoryIntroPalettes:
	.incbin "baserom.gba", 0x487388, 0x30

	.global gSoundFifoAddrs
gSoundFifoAddrs:
	.incbin "baserom.gba", 0x4873B8, 0x8

	.global gSoundTimerRegs
gSoundTimerRegs:
	.incbin "baserom.gba", 0x4873C0, 0x8

	.global gSoundFifoDmaCnt
gSoundFifoDmaCnt:
	.incbin "baserom.gba", 0x4873C8, 0x8

	.global gUnk_084873D0
gUnk_084873D0:
	.incbin "baserom.gba", 0x4873D0, 0x154

	.global gUnk_08487524
gUnk_08487524:
	.incbin "baserom.gba", 0x487524, 0x10C

	.global gUnk_08487630
gUnk_08487630:
	.incbin "baserom.gba", 0x487630, 0xD8

	.global gMoneyWindowTiles
gMoneyWindowTiles:
	.incbin "baserom.gba", 0x487708, 0x10C

	.global gMoneyWindowHalfTiles
gMoneyWindowHalfTiles:
	.incbin "baserom.gba", 0x487814, 0xD8

	.global gUnk_084878EC
gUnk_084878EC:
	.incbin "baserom.gba", 0x4878EC, 0x80

	.global gUnk_0848796C
gUnk_0848796C:
	.incbin "baserom.gba", 0x48796C, 0x84

	.global gMedaforceGaugeFrameTiles
gMedaforceGaugeFrameTiles:
	.incbin "baserom.gba", 0x4879F0, 0x34

	.global gBattlePillarTiles
gBattlePillarTiles:
	.incbin "baserom.gba", 0x487A24, 0x15C

	.global gActionSelectPanelTiles
gActionSelectPanelTiles:
	.incbin "baserom.gba", 0x487B80, 0x114

	.global gActionSelectSidePanelTiles
gActionSelectSidePanelTiles:
	.incbin "baserom.gba", 0x487C94, 0xD8

	.global gLeftBotPanelTiles
gLeftBotPanelTiles:
	.incbin "baserom.gba", 0x487D6C, 0xFC

	.global gRightBotPanelTiles
gRightBotPanelTiles:
	.incbin "baserom.gba", 0x487E68, 0xFC

	.global gPartsMenuLeftPanelTiles
gPartsMenuLeftPanelTiles:
	.incbin "baserom.gba", 0x487F64, 0xD8

	.global gMfMenuLeftPanelTiles
gMfMenuLeftPanelTiles:
	.incbin "baserom.gba", 0x48803C, 0xD8

	.global gMfMenuRightPanelTiles
gMfMenuRightPanelTiles:
	.incbin "baserom.gba", 0x488114, 0xD8

	.global gPartsMenuRightPanelTiles
gPartsMenuRightPanelTiles:
	.incbin "baserom.gba", 0x4881EC, 0x108

	.global gUnk_084882F4
gUnk_084882F4:
	.incbin "baserom.gba", 0x4882F4, 0x48

	.global gTradeChoiceWindowTiles
gTradeChoiceWindowTiles:
	.incbin "baserom.gba", 0x48833C, 0x204

	.global gUnk_08488540
gUnk_08488540:
	.incbin "baserom.gba", 0x488540, 0x68

	.global gUnk_084885A8
gUnk_084885A8:
	.incbin "baserom.gba", 0x4885A8, 0x58

	.global gUnk_08488600
gUnk_08488600:
	.incbin "baserom.gba", 0x488600, 0x44

	.global gMoneyWindowTilemap
gMoneyWindowTilemap:
	.incbin "baserom.gba", 0x488644, 0x4C

	.global gMoneyWindowHalfTilemap
gMoneyWindowHalfTilemap:
	.incbin "baserom.gba", 0x488690, 0x40

	.global gUnk_084886D0
gUnk_084886D0:
	.incbin "baserom.gba", 0x4886D0, 0x48

	.global gUnk_08488718
gUnk_08488718:
	.incbin "baserom.gba", 0x488718, 0x2C

	.global gMedaforceGaugeFrameTilemap
gMedaforceGaugeFrameTilemap:
	.incbin "baserom.gba", 0x488744, 0x20

	.global gUnk_08488764
gUnk_08488764:
	.incbin "baserom.gba", 0x488764, 0x40

	.global gActionSelectPanelTilemap
gActionSelectPanelTilemap:
	.incbin "baserom.gba", 0x4887A4, 0x50

	.global gActionSelectSidePanelTilemap
gActionSelectSidePanelTilemap:
	.incbin "baserom.gba", 0x4887F4, 0x3C

	.global gLeftBotPanelTilemap
gLeftBotPanelTilemap:
	.incbin "baserom.gba", 0x488830, 0x3C

	.global gRightBotPanelTilemap
gRightBotPanelTilemap:
	.incbin "baserom.gba", 0x48886C, 0x3C

	.global gPartsMenuLeftPanelTilemap
gPartsMenuLeftPanelTilemap:
	.incbin "baserom.gba", 0x4888A8, 0x3C

	.global gMfMenuLeftPanelTilemap
gMfMenuLeftPanelTilemap:
	.incbin "baserom.gba", 0x4888E4, 0x3C

	.global gMfMenuRightPanelTilemap
gMfMenuRightPanelTilemap:
	.incbin "baserom.gba", 0x488920, 0x3C

	.global gPartsMenuRightPanelTilemap
gPartsMenuRightPanelTilemap:
	.incbin "baserom.gba", 0x48895C, 0x58

	.global gUnk_084889B4
gUnk_084889B4:
	.incbin "baserom.gba", 0x4889B4, 0x44

	.global gTradeChoiceWindowTilemap
gTradeChoiceWindowTilemap:
	.incbin "baserom.gba", 0x4889F8, 0x8C

	.global gMenuBgPalette
gMenuBgPalette:
	.incbin "baserom.gba", 0x488A84, 0x20

	.global gUnk_08488AA4
gUnk_08488AA4:
	.incbin "baserom.gba", 0x488AA4, 0x20

	.global gBattleBgPalette10
gBattleBgPalette10:
	.incbin "baserom.gba", 0x488AC4, 0x20

	.global gBattleBgPalette12
gBattleBgPalette12:
	.incbin "baserom.gba", 0x488AE4, 0x20

	.global gBattleBgPalette11
gBattleBgPalette11:
	.incbin "baserom.gba", 0x488B04, 0x20

	.global gUnk_08488B24
gUnk_08488B24:
	.incbin "baserom.gba", 0x488B24, 0x20

	.global gTradeChoiceWindowPalette
gTradeChoiceWindowPalette:
	.incbin "baserom.gba", 0x488B44, 0x37684

	.global gFontGlyphs
gFontGlyphs:
	.incbin "baserom.gba", 0x4C01C8, 0x1440

	.global gFieldMenuMedawatchLabelTiles
gFieldMenuMedawatchLabelTiles:
	.incbin "baserom.gba", 0x4C1608, 0x1E8

	.global gFieldMenuItemLabelTiles
gFieldMenuItemLabelTiles:
	.incbin "baserom.gba", 0x4C17F0, 0x144

	.global gFieldMenuVehicleLabelTiles
gFieldMenuVehicleLabelTiles:
	.incbin "baserom.gba", 0x4C1934, 0x198

	.global gFieldMenuSaveLabelTiles
gFieldMenuSaveLabelTiles:
	.incbin "baserom.gba", 0x4C1ACC, 0x148

	.global gMenuSlideLineTile
gMenuSlideLineTile:
	.incbin "baserom.gba", 0x4C1C14, 0x10

	.global gUnk_084C1C24
gUnk_084C1C24:
	.incbin "baserom.gba", 0x4C1C24, 0x1E0

	.global gUnk_084C1E04
gUnk_084C1E04:
	.incbin "baserom.gba", 0x4C1E04, 0x1D0

	.global gUnk_084C1FD4
gUnk_084C1FD4:
	.incbin "baserom.gba", 0x4C1FD4, 0x1E8

	.global gMedalIconTiles
gMedalIconTiles:
	.incbin "baserom.gba", 0x4C21BC, 0xF00

	.global gMedalIconBlankTiles
gMedalIconBlankTiles:
	.incbin "baserom.gba", 0x4C30BC, 0x100

	.global gUnk_084C31BC
gUnk_084C31BC:
	.incbin "baserom.gba", 0x4C31BC, 0x4C

	.global gSmallDigitTiles
gSmallDigitTiles:
	.incbin "baserom.gba", 0x4C3208, 0xD4

	.global gMedalsTabNumberTiles
gMedalsTabNumberTiles:
	.incbin "baserom.gba", 0x4C32DC, 0x100

	.global gCompatibilityIconTiles
gCompatibilityIconTiles:
	.incbin "baserom.gba", 0x4C33DC, 0x148

	.global gMedaforceTypeIconTiles
gMedaforceTypeIconTiles:
	.incbin "baserom.gba", 0x4C3524, 0x124

	.global gMedaforceGaugeTiles
gMedaforceGaugeTiles:
	.incbin "baserom.gba", 0x4C3648, 0xA8

	.global gTallDigitTiles
gTallDigitTiles:
	.incbin "baserom.gba", 0x4C36F0, 0xB4

	.global gRotationActionIconTiles
gRotationActionIconTiles:
	.incbin "baserom.gba", 0x4C37A4, 0x1EC

	.global gRotationPathTiles
gRotationPathTiles:
	.incbin "baserom.gba", 0x4C3990, 0x184

	.global gMedalSkillShineTiles
gMedalSkillShineTiles:
	.incbin "baserom.gba", 0x4C3B14, 0x500

	.global gMedapartTypeLabelTiles
gMedapartTypeLabelTiles:
	.incbin "baserom.gba", 0x4C4014, 0x31C

	.global gPartGenderIconTiles
gPartGenderIconTiles:
	.incbin "baserom.gba", 0x4C4330, 0x90

	.global gMedapartStatLabelTiles
gMedapartStatLabelTiles:
	.incbin "baserom.gba", 0x4C43C0, 0x3E0

	.global gPartPowerMarkTiles
gPartPowerMarkTiles:
	.incbin "baserom.gba", 0x4C47A0, 0x40

	.global gSkillRangeIconTiles
gSkillRangeIconTiles:
	.incbin "baserom.gba", 0x4C47E0, 0xD4

	.global gUnk_084C48B4
gUnk_084C48B4:
	.incbin "baserom.gba", 0x4C48B4, 0x180

	.global gUnk_084C4A34
gUnk_084C4A34:
	.incbin "baserom.gba", 0x4C4A34, 0x178

	.global gBotActionIconTiles
gBotActionIconTiles:
	.incbin "baserom.gba", 0x4C4BAC, 0x204

	.global gUnk_084C4DB0
gUnk_084C4DB0:
	.incbin "baserom.gba", 0x4C4DB0, 0x150

	.global gGaugeFillTiles
gGaugeFillTiles:
	.incbin "baserom.gba", 0x4C4F00, 0x8C

	.global gMedaforceLabelTiles
gMedaforceLabelTiles:
	.incbin "baserom.gba", 0x4C4F8C, 0x7C

	.global gBattlePillarCapTiles
gBattlePillarCapTiles:
	.incbin "baserom.gba", 0x4C5008, 0x78

	.global gMedaforceGaugeFrameEndTiles
gMedaforceGaugeFrameEndTiles:
	.incbin "baserom.gba", 0x4C5080, 0x3C

	.global gUnk_084C50BC
gUnk_084C50BC:
	.incbin "baserom.gba", 0x4C50BC, 0x1C

	.global gUnk_084C50D8
gUnk_084C50D8:
	.incbin "baserom.gba", 0x4C50D8, 0xB0

	.global gAltFontGlyphs
gAltFontGlyphs:
	.incbin "baserom.gba", 0x4C5188, 0x1440

	.global gUnk_084C65C8
gUnk_084C65C8:
	.incbin "baserom.gba", 0x4C65C8, 0xF0

	.global gUnk_084C66B8
gUnk_084C66B8:
	.incbin "baserom.gba", 0x4C66B8, 0x228

	.global gUnk_084C68E0
gUnk_084C68E0:
	.incbin "baserom.gba", 0x4C68E0, 0x8C

	.global gUnk_084C696C
gUnk_084C696C:
	.incbin "baserom.gba", 0x4C696C, 0x2C

	.global gTextWindowObjPalette
gTextWindowObjPalette:
	.incbin "baserom.gba", 0x4C6998, 0x20

	.global gUnk_084C69B8
gUnk_084C69B8:
	.incbin "baserom.gba", 0x4C69B8, 0x20

	.global gUnk_084C69D8
gUnk_084C69D8:
	.incbin "baserom.gba", 0x4C69D8, 0x20

	.global gUnk_084C69F8
gUnk_084C69F8:
	.incbin "baserom.gba", 0x4C69F8, 0x20

	.global gBattleBgPalette8
gBattleBgPalette8:
	.incbin "baserom.gba", 0x4C6A18, 0x20

	.global gBattleBgPalette13
gBattleBgPalette13:
	.incbin "baserom.gba", 0x4C6A38, 0x20

	.global gUnk_084C6A58
gUnk_084C6A58:
	.incbin "baserom.gba", 0x4C6A58, 0x20

	.global gUnk_084C6A78
gUnk_084C6A78:
	.incbin "baserom.gba", 0x4C6A78, 0x20

	.global gSpriteFontTiles
gSpriteFontTiles:
	.incbin "baserom.gba", 0x4C6A98, 0x6DC

	.global gFieldMenuCursorTiles
gFieldMenuCursorTiles:
	.incbin "baserom.gba", 0x4C7174, 0x1A4

	.global gCursorArrowTiles
gCursorArrowTiles:
	.incbin "baserom.gba", 0x4C7318, 0x110

	.global gUnk_084C7428
gUnk_084C7428:
	.incbin "baserom.gba", 0x4C7428, 0x20C

	.global gBattleUiSpriteTiles
gBattleUiSpriteTiles:
	.incbin "baserom.gba", 0x4C7634, 0x6DC

	.global gUnk_084C7D10
gUnk_084C7D10:
	.incbin "baserom.gba", 0x4C7D10, 0x2B0

	.global gBattleNumberSpriteTiles
gBattleNumberSpriteTiles:
	.incbin "baserom.gba", 0x4C7FC0, 0x524

	.global gUnk_084C84E4
gUnk_084C84E4:
	.incbin "baserom.gba", 0x4C84E4, 0x5E0

	.global gMissPopupTiles
gMissPopupTiles:
	.incbin "baserom.gba", 0x4C8AC4, 0x5B8

	.global gGrapTrapTiles
gGrapTrapTiles:
	.incbin "baserom.gba", 0x4C907C, 0x20C

	.global gShotTrapTiles
gShotTrapTiles:
	.incbin "baserom.gba", 0x4C9288, 0x39C

	.global gAttackClrTrapTiles
gAttackClrTrapTiles:
	.incbin "baserom.gba", 0x4C9624, 0x168

	.global gMedaforceTrapTiles
gMedaforceTrapTiles:
	.incbin "baserom.gba", 0x4C978C, 0xC0

	.global gBotShadowTiles
gBotShadowTiles:
	.incbin "baserom.gba", 0x4C984C, 0x34

	.global gDefenceShieldTiles
gDefenceShieldTiles:
	.incbin "baserom.gba", 0x4C9880, 0x308

	.global gFullBlockShieldTiles
gFullBlockShieldTiles:
	.incbin "baserom.gba", 0x4C9B88, 0x314

	.global gHalfBlockShieldTiles
gHalfBlockShieldTiles:
	.incbin "baserom.gba", 0x4C9E9C, 0x308

	.global gReactionRiseTiles
gReactionRiseTiles:
	.incbin "baserom.gba", 0x4CA1A4, 0x284

	.global gAttackMissTiles
gAttackMissTiles:
	.incbin "baserom.gba", 0x4CA428, 0x1F4

	.global gCarryOverMarkerTiles
gCarryOverMarkerTiles:
	.incbin "baserom.gba", 0x4CA61C, 0x280

	.global gStatusFlashTiles
gStatusFlashTiles:
	.incbin "baserom.gba", 0x4CA89C, 0x2BC

	.global gBugIconTiles
gBugIconTiles:
	.incbin "baserom.gba", 0x4CAB58, 0x480

	.global gThunderIconTiles
gThunderIconTiles:
	.incbin "baserom.gba", 0x4CAFD8, 0x394

	.global gWaveIconTiles
gWaveIconTiles:
	.incbin "baserom.gba", 0x4CB36C, 0x318

	.global gFireIconTiles
gFireIconTiles:
	.incbin "baserom.gba", 0x4CB684, 0x2CC

	.global gHeadMarkerTiles
gHeadMarkerTiles:
	.incbin "baserom.gba", 0x4CB950, 0x2C0

	.global gRightArmMarkerTiles
gRightArmMarkerTiles:
	.incbin "baserom.gba", 0x4CBC10, 0x2F4

	.global gLeftArmMarkerTiles
gLeftArmMarkerTiles:
	.incbin "baserom.gba", 0x4CBF04, 0x298

	.global gLegsMarkerTiles
gLegsMarkerTiles:
	.incbin "baserom.gba", 0x4CC19C, 0x294

	.global gCriticalHitTiles
gCriticalHitTiles:
	.incbin "baserom.gba", 0x4CC430, 0x1C8

	.global gAttackNullifiedTiles
gAttackNullifiedTiles:
	.incbin "baserom.gba", 0x4CC5F8, 0x1D0

	.global gDestroyMarkerTiles
gDestroyMarkerTiles:
	.incbin "baserom.gba", 0x4CC7C8, 0x1E0

	.global gHitSparksTiles
gHitSparksTiles:
	.incbin "baserom.gba", 0x4CC9A8, 0x4A0

	.global gPartBreakBurstTiles
gPartBreakBurstTiles:
	.incbin "baserom.gba", 0x4CCE48, 0xD90

	.global gBreakRingTiles
gBreakRingTiles:
	.incbin "baserom.gba", 0x4CDBD8, 0xFC

	.global gAbsorbSparkleTiles
gAbsorbSparkleTiles:
	.incbin "baserom.gba", 0x4CDCD4, 0x480

	.global gBugEffectTiles
gBugEffectTiles:
	.incbin "baserom.gba", 0x4CE154, 0x4F0

	.global gThunderEffectTiles
gThunderEffectTiles:
	.incbin "baserom.gba", 0x4CE644, 0x8D0

	.global gWaveEffectTiles
gWaveEffectTiles:
	.incbin "baserom.gba", 0x4CEF14, 0x42C

	.global gFireEffectTiles
gFireEffectTiles:
	.incbin "baserom.gba", 0x4CF340, 0xEAC

	.global gReactionNullifyTiles
gReactionNullifyTiles:
	.incbin "baserom.gba", 0x4D01EC, 0x550

	.global gReactionAbsorbTiles
gReactionAbsorbTiles:
	.incbin "baserom.gba", 0x4D073C, 0x938

	.global gReactionRiseFxTiles
gReactionRiseFxTiles:
	.incbin "baserom.gba", 0x4D1074, 0x7B0

	.global gDamageNumberTiles
gDamageNumberTiles:
	.incbin "baserom.gba", 0x4D1824, 0xC8

	.global gAttackAbsorbedTiles
gAttackAbsorbedTiles:
	.incbin "baserom.gba", 0x4D18EC, 0x37F0

	.global gSkillCastHopTiles
gSkillCastHopTiles:
	.incbin "baserom.gba", 0x4D50DC, 0x60

	.global gUnk_084D513C
gUnk_084D513C:
	.incbin "baserom.gba", 0x4D513C, 0x380

	.global gUnk_084D54BC
gUnk_084D54BC:
	.incbin "baserom.gba", 0x4D54BC, 0x114

	.global gStabilitySparkleTiles
gStabilitySparkleTiles:
	.incbin "baserom.gba", 0x4D55D0, 0x1B8

	.global gUnk_084D5788
gUnk_084D5788:
	.incbin "baserom.gba", 0x4D5788, 0xD8

	.global gUnk_084D5860
gUnk_084D5860:
	.incbin "baserom.gba", 0x4D5860, 0x2A8

	.global gUnk_084D5B08
gUnk_084D5B08:
	.incbin "baserom.gba", 0x4D5B08, 0x270

	.global gUnk_084D5D78
gUnk_084D5D78:
	.incbin "baserom.gba", 0x4D5D78, 0x144

	.global gConcealDomeTiles
gConcealDomeTiles:
	.incbin "baserom.gba", 0x4D5EBC, 0x1DC

	.global gChargeHourglassTiles
gChargeHourglassTiles:
	.incbin "baserom.gba", 0x4D6098, 0x144

	.global gUnk_084D61DC
gUnk_084D61DC:
	.incbin "baserom.gba", 0x4D61DC, 0x144

	.global gUnk_084D6320
gUnk_084D6320:
	.incbin "baserom.gba", 0x4D6320, 0x144

	.global gPushoverBananaTiles
gPushoverBananaTiles:
	.incbin "baserom.gba", 0x4D6464, 0xB8

	.global gImpairPortraitTiles
gImpairPortraitTiles:
	.incbin "baserom.gba", 0x4D651C, 0x264

	.global gUnk_084D6780
gUnk_084D6780:
	.incbin "baserom.gba", 0x4D6780, 0x32C

	.global gUnk_084D6AAC
gUnk_084D6AAC:
	.incbin "baserom.gba", 0x4D6AAC, 0x150

	.global gBattlePopupDigitTiles
gBattlePopupDigitTiles:
	.incbin "baserom.gba", 0x4D6BFC, 0xC8

	.global gUnk_084D6CC4
gUnk_084D6CC4:
	.incbin "baserom.gba", 0x4D6CC4, 0x15C

	.global gUnk_084D6E20
gUnk_084D6E20:
	.incbin "baserom.gba", 0x4D6E20, 0x168

	.global gForcedrainGlassTiles
gForcedrainGlassTiles:
	.incbin "baserom.gba", 0x4D6F88, 0x250

	.global gUnk_084D71D8
gUnk_084D71D8:
	.incbin "baserom.gba", 0x4D71D8, 0x350

	.global gUnk_084D7528
gUnk_084D7528:
	.incbin "baserom.gba", 0x4D7528, 0x444

	.global gUnk_084D796C
gUnk_084D796C:
	.incbin "baserom.gba", 0x4D796C, 0x330

	.global gUnk_084D7C9C
gUnk_084D7C9C:
	.incbin "baserom.gba", 0x4D7C9C, 0x114

	.global gUnk_084D7DB0
gUnk_084D7DB0:
	.incbin "baserom.gba", 0x4D7DB0, 0x39D8

	.global gMedaforceSideBoltTiles
gMedaforceSideBoltTiles:
	.incbin "baserom.gba", 0x4DB788, 0x3A0

	.global gMedaforceFormEmblemTiles
gMedaforceFormEmblemTiles:
	.incbin "baserom.gba", 0x4DBB28, 0x184

	.global gMedaforceOpticFormTiles
gMedaforceOpticFormTiles:
	.incbin "baserom.gba", 0x4DBCAC, 0x60

	.global gMedaforceBombFormTiles
gMedaforceBombFormTiles:
	.incbin "baserom.gba", 0x4DBD0C, 0x54

	.global gMedaforceGravityFormTiles
gMedaforceGravityFormTiles:
	.incbin "baserom.gba", 0x4DBD60, 0x68

	.global gMedaforceCancelFormationTiles
gMedaforceCancelFormationTiles:
	.incbin "baserom.gba", 0x4DBDC8, 0x11C

	.global gMedaforceMovementEmblemTiles
gMedaforceMovementEmblemTiles:
	.incbin "baserom.gba", 0x4DBEE4, 0x21C

	.global gMedaforceStopEmblemTiles
gMedaforceStopEmblemTiles:
	.incbin "baserom.gba", 0x4DC100, 0x444

	.global gMedaforceBindEmblemTiles
gMedaforceBindEmblemTiles:
	.incbin "baserom.gba", 0x4DC544, 0x28C

	.global gMedaforceFlowEmblemTiles
gMedaforceFlowEmblemTiles:
	.incbin "baserom.gba", 0x4DC7D0, 0x784

	.global gMedaforceTargetBurstTiles
gMedaforceTargetBurstTiles:
	.incbin "baserom.gba", 0x4DCF54, 0x234

	.global gMedaforceChaosEmblemTiles
gMedaforceChaosEmblemTiles:
	.incbin "baserom.gba", 0x4DD188, 0x2D4

	.global gMedaforceCancelStatusSparkleTiles
gMedaforceCancelStatusSparkleTiles:
	.incbin "baserom.gba", 0x4DD45C, 0x1EC

	.global gMedaforceStatusRestoreTiles
gMedaforceStatusRestoreTiles:
	.incbin "baserom.gba", 0x4DD648, 0x24C

	.global gMedaforceTotalRecoveryTiles
gMedaforceTotalRecoveryTiles:
	.incbin "baserom.gba", 0x4DD894, 0x610

	.global gMedaforceFullBodyRepairTiles
gMedaforceFullBodyRepairTiles:
	.incbin "baserom.gba", 0x4DDEA4, 0x618

	.global gMedaforceTotalRecoverySparkleTiles
gMedaforceTotalRecoverySparkleTiles:
	.incbin "baserom.gba", 0x4DE4BC, 0x16C

	.global gMedaforceFullBodyUpTiles
gMedaforceFullBodyUpTiles:
	.incbin "baserom.gba", 0x4DE628, 0x6F4

	.global gMedaforceFullBodyRadTiles
gMedaforceFullBodyRadTiles:
	.incbin "baserom.gba", 0x4DED1C, 0x308

	.global gMedaforceIronWallTiles
gMedaforceIronWallTiles:
	.incbin "baserom.gba", 0x4DF024, 0x3DC

	.global gMedaforcePowerUpTiles
gMedaforcePowerUpTiles:
	.incbin "baserom.gba", 0x4DF400, 0x688

	.global gMedaforceAntiTerrainBeamTiles
gMedaforceAntiTerrainBeamTiles:
	.incbin "baserom.gba", 0x4DFA88, 0x14C

	.global gMedaforceAntiTerrainBoltTiles
gMedaforceAntiTerrainBoltTiles:
	.incbin "baserom.gba", 0x4DFBD4, 0x44

	.global gMedaforceUpArrowTiles
gMedaforceUpArrowTiles:
	.incbin "baserom.gba", 0x4DFC18, 0x3CC

	.global gMedaforceChargeTiles
gMedaforceChargeTiles:
	.incbin "baserom.gba", 0x4DFFE4, 0x37C

	.global gMedaforceUselessTiles
gMedaforceUselessTiles:
	.incbin "baserom.gba", 0x4E0360, 0x10C

	.global gMedaforceDestroyerTiles
gMedaforceDestroyerTiles:
	.incbin "baserom.gba", 0x4E046C, 0x10AC

	.global gMedaforceCrazyShotTiles
gMedaforceCrazyShotTiles:
	.incbin "baserom.gba", 0x4E1518, 0x2C8

	.global gMedaforceUpTiles
gMedaforceUpTiles:
	.incbin "baserom.gba", 0x4E17E0, 0xA4

	.global gMedaforceLegCrashTiles
gMedaforceLegCrashTiles:
	.incbin "baserom.gba", 0x4E1884, 0x314

	.global gMedaforceProtectorTiles
gMedaforceProtectorTiles:
	.incbin "baserom.gba", 0x4E1B98, 0x30C

	.global gMedaforceAntiProtectionTiles
gMedaforceAntiProtectionTiles:
	.incbin "baserom.gba", 0x4E1EA4, 0x254

	.global gUnk_084E20F8
gUnk_084E20F8:
	.incbin "baserom.gba", 0x4E20F8, 0x858

	.global gUnk_084E2950
gUnk_084E2950:
	.incbin "baserom.gba", 0x4E2950, 0x2C8

	.global gUnk_084E2C18
gUnk_084E2C18:
	.incbin "baserom.gba", 0x4E2C18, 0x220

	.global gSpriteFontPalette
gSpriteFontPalette:
	.incbin "baserom.gba", 0x4E2E38, 0x20

	.global gCursorArrowPalette
gCursorArrowPalette:
	.incbin "baserom.gba", 0x4E2E58, 0x20

	.global gHelpCursorPalette
gHelpCursorPalette:
	.incbin "baserom.gba", 0x4E2E78, 0x20

	.global gUnk_084E2E98
gUnk_084E2E98:
	.incbin "baserom.gba", 0x4E2E98, 0x20

	.global gUnk_084E2EB8
gUnk_084E2EB8:
	.incbin "baserom.gba", 0x4E2EB8, 0x20

	.global gUnk_084E2ED8
gUnk_084E2ED8:
	.incbin "baserom.gba", 0x4E2ED8, 0x20

	.global gTargetLinePalette
gTargetLinePalette:
	.incbin "baserom.gba", 0x4E2EF8, 0x20

	.global gTargetArrowsPalette
gTargetArrowsPalette:
	.incbin "baserom.gba", 0x4E2F18, 0x20

	.global gBattleObjPalette10
gBattleObjPalette10:
	.incbin "baserom.gba", 0x4E2F38, 0x20

	.global gUnk_084E2F58
gUnk_084E2F58:
	.incbin "baserom.gba", 0x4E2F58, 0x20

	.global gUnk_084E2F78
gUnk_084E2F78:
	.incbin "baserom.gba", 0x4E2F78, 0x20

	.global gUnk_084E2F98
gUnk_084E2F98:
	.incbin "baserom.gba", 0x4E2F98, 0x20

	.global gUnk_084E2FB8
gUnk_084E2FB8:
	.incbin "baserom.gba", 0x4E2FB8, 0x20

	.global gUnk_084E2FD8
gUnk_084E2FD8:
	.incbin "baserom.gba", 0x4E2FD8, 0x20

	.global gUnk_084E2FF8
gUnk_084E2FF8:
	.incbin "baserom.gba", 0x4E2FF8, 0x20

	.global gMedaforceActivatePalette
gMedaforceActivatePalette:
	.incbin "baserom.gba", 0x4E3018, 0x20

	.global gActionFlashPalette
gActionFlashPalette:
	.incbin "baserom.gba", 0x4E3038, 0x20

	.global gMfChargeSparklePalette
gMfChargeSparklePalette:
	.incbin "baserom.gba", 0x4E3058, 0x20

	.global gMissPopupPalette
gMissPopupPalette:
	.incbin "baserom.gba", 0x4E3078, 0x20

	.global gUnk_084E3098
gUnk_084E3098:
	.incbin "baserom.gba", 0x4E3098, 0x20

	.global gEffectCommonPalette
gEffectCommonPalette:
	.incbin "baserom.gba", 0x4E30B8, 0x20

	.global gUnk_084E30D8
gUnk_084E30D8:
	.incbin "baserom.gba", 0x4E30D8, 0x2578

	.global gUnk_084E5650
gUnk_084E5650:
	.incbin "baserom.gba", 0x4E5650, 0xB7C

	.global gUnk_084E61CC
gUnk_084E61CC:
	.incbin "baserom.gba", 0x4E61CC, 0xAD0

	.global gUnk_084E6C9C
gUnk_084E6C9C:
	.incbin "baserom.gba", 0x4E6C9C, 0x5C8

	.global gMedalsListBgTiles
gMedalsListBgTiles:
	.incbin "baserom.gba", 0x4E7264, 0xE4C

	.global gMedalAbilityBgTiles
gMedalAbilityBgTiles:
	.incbin "baserom.gba", 0x4E80B0, 0xF70

	.global gMedalMedaforceBgTiles
gMedalMedaforceBgTiles:
	.incbin "baserom.gba", 0x4E9020, 0xE48

	.global gMedalRotationBgTiles
gMedalRotationBgTiles:
	.incbin "baserom.gba", 0x4E9E68, 0xDF0

	.global gMedalSkillBgTiles
gMedalSkillBgTiles:
	.incbin "baserom.gba", 0x4EAC58, 0x12F8

	.global gMedapartsListBgTiles
gMedapartsListBgTiles:
	.incbin "baserom.gba", 0x4EBF50, 0xBEC

	.global gMedapartDetailBgTiles
gMedapartDetailBgTiles:
	.incbin "baserom.gba", 0x4ECB3C, 0x988

	.global gUnk_084ED4C4
gUnk_084ED4C4:
	.incbin "baserom.gba", 0x4ED4C4, 0xA2C

	.global gUnk_084EDEF0
gUnk_084EDEF0:
	.incbin "baserom.gba", 0x4EDEF0, 0x13E8

	.global gUnk_084EF2D8
gUnk_084EF2D8:
	.incbin "baserom.gba", 0x4EF2D8, 0x38

	.global gUnk_084EF310
gUnk_084EF310:
	.incbin "baserom.gba", 0x4EF310, 0x38

	.global gMedalsListBg0Tilemap
gMedalsListBg0Tilemap:
	.incbin "baserom.gba", 0x4EF348, 0x38

	.global gMedalAbilityBg0Tilemap
gMedalAbilityBg0Tilemap:
	.incbin "baserom.gba", 0x4EF380, 0x74

	.global gMedalMedaforceBg0Tilemap
gMedalMedaforceBg0Tilemap:
	.incbin "baserom.gba", 0x4EF3F4, 0x78

	.global gMedalRotationBg0Tilemap
gMedalRotationBg0Tilemap:
	.incbin "baserom.gba", 0x4EF46C, 0x74

	.global gMedalSkillBg0Tilemap
gMedalSkillBg0Tilemap:
	.incbin "baserom.gba", 0x4EF4E0, 0x70

	.global gMedapartsListBg0Tilemap
gMedapartsListBg0Tilemap:
	.incbin "baserom.gba", 0x4EF550, 0x54

	.global gMedapartDetailBg0Tilemap
gMedapartDetailBg0Tilemap:
	.incbin "baserom.gba", 0x4EF5A4, 0x38

	.global gUnk_084EF5DC
gUnk_084EF5DC:
	.incbin "baserom.gba", 0x4EF5DC, 0x8C

	.global gUnk_084EF668
gUnk_084EF668:
	.incbin "baserom.gba", 0x4EF668, 0x38

	.global gUnk_084EF6A0
gUnk_084EF6A0:
	.incbin "baserom.gba", 0x4EF6A0, 0x2BC

	.global gUnk_084EF95C
gUnk_084EF95C:
	.incbin "baserom.gba", 0x4EF95C, 0x6C

	.global gUnk_084EF9C8
gUnk_084EF9C8:
	.incbin "baserom.gba", 0x4EF9C8, 0x6C

	.global gUnk_084EFA34
gUnk_084EFA34:
	.incbin "baserom.gba", 0x4EFA34, 0x128

	.global gMedalsListBg1Tilemap
gMedalsListBg1Tilemap:
	.incbin "baserom.gba", 0x4EFB5C, 0x84

	.global gMedalAbilityBg1Tilemap
gMedalAbilityBg1Tilemap:
	.incbin "baserom.gba", 0x4EFBE0, 0xFC

	.global gMedalMedaforceBg1Tilemap
gMedalMedaforceBg1Tilemap:
	.incbin "baserom.gba", 0x4EFCDC, 0x98

	.global gMedalRotationBg1Tilemap
gMedalRotationBg1Tilemap:
	.incbin "baserom.gba", 0x4EFD74, 0xB4

	.global gMedalSkillBg1Tilemap
gMedalSkillBg1Tilemap:
	.incbin "baserom.gba", 0x4EFE28, 0x14C

	.global gMedapartsListBg1Tilemap
gMedapartsListBg1Tilemap:
	.incbin "baserom.gba", 0x4EFF74, 0xF4

	.global gMedapartDetailBg1Tilemap
gMedapartDetailBg1Tilemap:
	.incbin "baserom.gba", 0x4F0068, 0xC0

	.global gUnk_084F0128
gUnk_084F0128:
	.incbin "baserom.gba", 0x4F0128, 0x6C

	.global gUnk_084F0194
gUnk_084F0194:
	.incbin "baserom.gba", 0x4F0194, 0xA8

	.global gUnk_084F023C
gUnk_084F023C:
	.incbin "baserom.gba", 0x4F023C, 0x7C

	.global gUnk_084F02B8
gUnk_084F02B8:
	.incbin "baserom.gba", 0x4F02B8, 0x134

	.global gUnk_084F03EC
gUnk_084F03EC:
	.incbin "baserom.gba", 0x4F03EC, 0x104

	.global gMedalsListBg2Tilemap
gMedalsListBg2Tilemap:
	.incbin "baserom.gba", 0x4F04F0, 0x198

	.global gMedalAbilityBg2Tilemap
gMedalAbilityBg2Tilemap:
	.incbin "baserom.gba", 0x4F0688, 0x130

	.global gMedalMedaforceBg2Tilemap
gMedalMedaforceBg2Tilemap:
	.incbin "baserom.gba", 0x4F07B8, 0x138

	.global gMedalRotationBg2Tilemap
gMedalRotationBg2Tilemap:
	.incbin "baserom.gba", 0x4F08F0, 0x110

	.global gMedalSkillBg2Tilemap
gMedalSkillBg2Tilemap:
	.incbin "baserom.gba", 0x4F0A00, 0x1F0

	.global gMedapartsListBg2Tilemap
gMedapartsListBg2Tilemap:
	.incbin "baserom.gba", 0x4F0BF0, 0xB4

	.global gMedapartDetailBg2Tilemap
gMedapartDetailBg2Tilemap:
	.incbin "baserom.gba", 0x4F0CA4, 0x80

	.global gUnk_084F0D24
gUnk_084F0D24:
	.incbin "baserom.gba", 0x4F0D24, 0x78

	.global gUnk_084F0D9C
gUnk_084F0D9C:
	.incbin "baserom.gba", 0x4F0D9C, 0x190

	.global gUnk_084F0F2C
gUnk_084F0F2C:
	.incbin "baserom.gba", 0x4F0F2C, 0x300

	.global gUnk_084F122C
gUnk_084F122C:
	.incbin "baserom.gba", 0x4F122C, 0x194

	.global gUnk_084F13C0
gUnk_084F13C0:
	.incbin "baserom.gba", 0x4F13C0, 0x194

	.global gMedalsListBg3Tilemap
gMedalsListBg3Tilemap:
	.incbin "baserom.gba", 0x4F1554, 0x194

	.global gMedalAbilityBg3Tilemap
gMedalAbilityBg3Tilemap:
	.incbin "baserom.gba", 0x4F16E8, 0x194

	.global gMedalMedaforceBg3Tilemap
gMedalMedaforceBg3Tilemap:
	.incbin "baserom.gba", 0x4F187C, 0x194

	.global gMedalRotationBg3Tilemap
gMedalRotationBg3Tilemap:
	.incbin "baserom.gba", 0x4F1A10, 0x190

	.global gMedalSkillBg3Tilemap
gMedalSkillBg3Tilemap:
	.incbin "baserom.gba", 0x4F1BA0, 0x194

	.global gMedapartsListBg3Tilemap
gMedapartsListBg3Tilemap:
	.incbin "baserom.gba", 0x4F1D34, 0x194

	.global gMedapartDetailBg3Tilemap
gMedapartDetailBg3Tilemap:
	.incbin "baserom.gba", 0x4F1EC8, 0x194

	.global gUnk_084F205C
gUnk_084F205C:
	.incbin "baserom.gba", 0x4F205C, 0x18C

	.global gUnk_084F21E8
gUnk_084F21E8:
	.incbin "baserom.gba", 0x4F21E8, 0x2F8

	.global gUnk_084F24E0
gUnk_084F24E0:
	.incbin "baserom.gba", 0x4F24E0, 0x1A0

	.global gUnk_084F2680
gUnk_084F2680:
	.incbin "baserom.gba", 0x4F2680, 0x1A0

	.global gUnk_084F2820
gUnk_084F2820:
	.incbin "baserom.gba", 0x4F2820, 0x1C0

	.global gUnk_084F29E0
gUnk_084F29E0:
	.incbin "baserom.gba", 0x4F29E0, 0x1C0

	.global gMedalsListBgPalette
gMedalsListBgPalette:
	.incbin "baserom.gba", 0x4F2BA0, 0x1C0

	.global gMedalAbilityBgPalette
gMedalAbilityBgPalette:
	.incbin "baserom.gba", 0x4F2D60, 0x1C0

	.global gMedalMedaforceBgPalette
gMedalMedaforceBgPalette:
	.incbin "baserom.gba", 0x4F2F20, 0x1C0

	.global gMedalRotationBgPalette
gMedalRotationBgPalette:
	.incbin "baserom.gba", 0x4F30E0, 0x1C0

	.global gMedalSkillBgPalette
gMedalSkillBgPalette:
	.incbin "baserom.gba", 0x4F32A0, 0x1C0

	.global gMedapartsListBgPalette
gMedapartsListBgPalette:
	.incbin "baserom.gba", 0x4F3460, 0x1C0

	.global gMedapartDetailBgPalette
gMedapartDetailBgPalette:
	.incbin "baserom.gba", 0x4F3620, 0x1C0

	.global gUnk_084F37E0
gUnk_084F37E0:
	.incbin "baserom.gba", 0x4F37E0, 0x1C0

	.global gUnk_084F39A0
gUnk_084F39A0:
	.incbin "baserom.gba", 0x4F39A0, 0x1A358

	.global gUnk_0850DCF8
gUnk_0850DCF8:
	.incbin "baserom.gba", 0x50DCF8, 0x20

	.global gUnk_0850DD18
gUnk_0850DD18:
	.incbin "baserom.gba", 0x50DD18, 0x40

	.global gUnk_0850DD58
gUnk_0850DD58:
	.incbin "baserom.gba", 0x50DD58, 0x20

	.global gUnk_0850DD78
gUnk_0850DD78:
	.incbin "baserom.gba", 0x50DD78, 0x40

	.global gBattleObjPalettes13
gBattleObjPalettes13:
	.incbin "baserom.gba", 0x50DDB8, 0x40

	.global gUnk_0850DDF8
gUnk_0850DDF8:
	.incbin "baserom.gba", 0x50DDF8, 0xC0

	.global gUnk_0850DEB8
gUnk_0850DEB8:
	.incbin "baserom.gba", 0x50DEB8, 0x40

	.global gUnk_0850DEF8
gUnk_0850DEF8:
	.incbin "baserom.gba", 0x50DEF8, 0x100

	.global gHealNumberPalette
gHealNumberPalette:
	.incbin "baserom.gba", 0x50DFF8, 0x20

	.global gDamageNumberPalette
gDamageNumberPalette:
	.incbin "baserom.gba", 0x50E018, 0x40

	.global gGrapTrapPalette
gGrapTrapPalette:
	.incbin "baserom.gba", 0x50E058, 0x20

	.global gShotTrapPalette
gShotTrapPalette:
	.incbin "baserom.gba", 0x50E078, 0x20

	.global gAttackClrTrapPalette
gAttackClrTrapPalette:
	.incbin "baserom.gba", 0x50E098, 0x20

	.global gMedaforceTrapPalette
gMedaforceTrapPalette:
	.incbin "baserom.gba", 0x50E0B8, 0x20

	.global gBattleObjPalette5
gBattleObjPalette5:
	.incbin "baserom.gba", 0x50E0D8, 0x20

	.global gDefenceShieldPalette
gDefenceShieldPalette:
	.incbin "baserom.gba", 0x50E0F8, 0x20

	.global gFullBlockShieldPalette
gFullBlockShieldPalette:
	.incbin "baserom.gba", 0x50E118, 0x20

	.global gHalfBlockShieldPalette
gHalfBlockShieldPalette:
	.incbin "baserom.gba", 0x50E138, 0x20

	.global gReactionRisePalette
gReactionRisePalette:
	.incbin "baserom.gba", 0x50E158, 0x20

	.global gAttackMissPalette
gAttackMissPalette:
	.incbin "baserom.gba", 0x50E178, 0x20

	.global gCarryOverMarkerPalette
gCarryOverMarkerPalette:
	.incbin "baserom.gba", 0x50E198, 0x20

	.global gStatusFlashPalette
gStatusFlashPalette:
	.incbin "baserom.gba", 0x50E1B8, 0x20

	.global gBugIconPalette
gBugIconPalette:
	.incbin "baserom.gba", 0x50E1D8, 0x20

	.global gThunderIconPalette
gThunderIconPalette:
	.incbin "baserom.gba", 0x50E1F8, 0x20

	.global gWaveIconPalette
gWaveIconPalette:
	.incbin "baserom.gba", 0x50E218, 0x20

	.global gFireIconPalette
gFireIconPalette:
	.incbin "baserom.gba", 0x50E238, 0x20

	.global gHeadMarkerPalette
gHeadMarkerPalette:
	.incbin "baserom.gba", 0x50E258, 0x20

	.global gRightArmMarkerPalette
gRightArmMarkerPalette:
	.incbin "baserom.gba", 0x50E278, 0x20

	.global gLeftArmMarkerPalette
gLeftArmMarkerPalette:
	.incbin "baserom.gba", 0x50E298, 0x20

	.global gLegsMarkerPalette
gLegsMarkerPalette:
	.incbin "baserom.gba", 0x50E2B8, 0x20

	.global gCriticalHitPalette
gCriticalHitPalette:
	.incbin "baserom.gba", 0x50E2D8, 0x20

	.global gAttackNullifiedPalette
gAttackNullifiedPalette:
	.incbin "baserom.gba", 0x50E2F8, 0x20

	.global gDestroyMarkerPalette
gDestroyMarkerPalette:
	.incbin "baserom.gba", 0x50E318, 0x20

	.global gHitSparksPalette
gHitSparksPalette:
	.incbin "baserom.gba", 0x50E338, 0x20

	.global gPartBreakBurstPalette
gPartBreakBurstPalette:
	.incbin "baserom.gba", 0x50E358, 0x20

	.global gBreakRingPalette
gBreakRingPalette:
	.incbin "baserom.gba", 0x50E378, 0x20

	.global gAbsorbSparklePalette
gAbsorbSparklePalette:
	.incbin "baserom.gba", 0x50E398, 0x20

	.global gBugEffectPalette
gBugEffectPalette:
	.incbin "baserom.gba", 0x50E3B8, 0x20

	.global gThunderEffectPalette
gThunderEffectPalette:
	.incbin "baserom.gba", 0x50E3D8, 0x20

	.global gWaveEffectPalette
gWaveEffectPalette:
	.incbin "baserom.gba", 0x50E3F8, 0x20

	.global gFireEffectPalette
gFireEffectPalette:
	.incbin "baserom.gba", 0x50E418, 0x20

	.global gReactionNullifyPalette
gReactionNullifyPalette:
	.incbin "baserom.gba", 0x50E438, 0x20

	.global gReactionAbsorbPalette
gReactionAbsorbPalette:
	.incbin "baserom.gba", 0x50E458, 0x20

	.global gReactionRiseFxPalette
gReactionRiseFxPalette:
	.incbin "baserom.gba", 0x50E478, 0x20

	.global gAttackAbsorbedPalette
gAttackAbsorbedPalette:
	.incbin "baserom.gba", 0x50E498, 0x1C0

	.global gSkillCastHopPalette
gSkillCastHopPalette:
	.incbin "baserom.gba", 0x50E658, 0x20

	.global gUnk_0850E678
gUnk_0850E678:
	.incbin "baserom.gba", 0x50E678, 0x20

	.global gUnk_0850E698
gUnk_0850E698:
	.incbin "baserom.gba", 0x50E698, 0x20

	.global gStabilitySparklePalette
gStabilitySparklePalette:
	.incbin "baserom.gba", 0x50E6B8, 0x20

	.global gUnk_0850E6D8
gUnk_0850E6D8:
	.incbin "baserom.gba", 0x50E6D8, 0x20

	.global gUnk_0850E6F8
gUnk_0850E6F8:
	.incbin "baserom.gba", 0x50E6F8, 0x40

	.global gUnk_0850E738
gUnk_0850E738:
	.incbin "baserom.gba", 0x50E738, 0x40

	.global gUnk_0850E778
gUnk_0850E778:
	.incbin "baserom.gba", 0x50E778, 0x40

	.global gConcealDomePalette
gConcealDomePalette:
	.incbin "baserom.gba", 0x50E7B8, 0x20

	.global gChargeHourglassPalette
gChargeHourglassPalette:
	.incbin "baserom.gba", 0x50E7D8, 0x20

	.global gUnk_0850E7F8
gUnk_0850E7F8:
	.incbin "baserom.gba", 0x50E7F8, 0x20

	.global gUnk_0850E818
gUnk_0850E818:
	.incbin "baserom.gba", 0x50E818, 0x20

	.global gPushoverBananaPalette
gPushoverBananaPalette:
	.incbin "baserom.gba", 0x50E838, 0x20

	.global gImpairPortraitPalette
gImpairPortraitPalette:
	.incbin "baserom.gba", 0x50E858, 0x20

	.global gUnk_0850E878
gUnk_0850E878:
	.incbin "baserom.gba", 0x50E878, 0x40

	.global gUnk_0850E8B8
gUnk_0850E8B8:
	.incbin "baserom.gba", 0x50E8B8, 0x40

	.global gUnk_0850E8F8
gUnk_0850E8F8:
	.incbin "baserom.gba", 0x50E8F8, 0x20

	.global gUnk_0850E918
gUnk_0850E918:
	.incbin "baserom.gba", 0x50E918, 0x20

	.global gForcedrainGlassPalettes
gForcedrainGlassPalettes:
	.incbin "baserom.gba", 0x50E938, 0x40

	.global gUnk_0850E978
gUnk_0850E978:
	.incbin "baserom.gba", 0x50E978, 0x20

	.global gUnk_0850E998
gUnk_0850E998:
	.incbin "baserom.gba", 0x50E998, 0x40

	.global gUnk_0850E9D8
gUnk_0850E9D8:
	.incbin "baserom.gba", 0x50E9D8, 0x160

	.global gMedaforceSideBoltPalette
gMedaforceSideBoltPalette:
	.incbin "baserom.gba", 0x50EB38, 0x20

	.global gMedaforceOpticFormPalette
gMedaforceOpticFormPalette:
	.incbin "baserom.gba", 0x50EB58, 0x20

	.global gMedaforceBombFormPalette
gMedaforceBombFormPalette:
	.incbin "baserom.gba", 0x50EB78, 0x20

	.global gMedaforceGravityFormPalette
gMedaforceGravityFormPalette:
	.incbin "baserom.gba", 0x50EB98, 0x20

	.global gMedaforceCancelFormationPalette
gMedaforceCancelFormationPalette:
	.incbin "baserom.gba", 0x50EBB8, 0x20

	.global gMedaforceMovementEmblemPalette
gMedaforceMovementEmblemPalette:
	.incbin "baserom.gba", 0x50EBD8, 0x20

	.global gMedaforceStopEmblemPalette
gMedaforceStopEmblemPalette:
	.incbin "baserom.gba", 0x50EBF8, 0x20

	.global gMedaforceBindEmblemPalette
gMedaforceBindEmblemPalette:
	.incbin "baserom.gba", 0x50EC18, 0x20

	.global gMedaforceFlowEmblemPalette
gMedaforceFlowEmblemPalette:
	.incbin "baserom.gba", 0x50EC38, 0x20

	.global gMedaforceTargetBurstPalette
gMedaforceTargetBurstPalette:
	.incbin "baserom.gba", 0x50EC58, 0x20

	.global gMedaforceChaosEmblemPalette
gMedaforceChaosEmblemPalette:
	.incbin "baserom.gba", 0x50EC78, 0x20

	.global gMedaforceCancelStatusSparklePalette
gMedaforceCancelStatusSparklePalette:
	.incbin "baserom.gba", 0x50EC98, 0x20

	.global gMedaforceStatusRestorePalette
gMedaforceStatusRestorePalette:
	.incbin "baserom.gba", 0x50ECB8, 0x20

	.global gMedaforceTotalRecoveryPalette
gMedaforceTotalRecoveryPalette:
	.incbin "baserom.gba", 0x50ECD8, 0x20

	.global gMedaforceFullBodyRepairPalette
gMedaforceFullBodyRepairPalette:
	.incbin "baserom.gba", 0x50ECF8, 0x20

	.global gMedaforceTotalRecoverySparklePalette
gMedaforceTotalRecoverySparklePalette:
	.incbin "baserom.gba", 0x50ED18, 0x20

	.global gMedaforceFullBodyUpPalette
gMedaforceFullBodyUpPalette:
	.incbin "baserom.gba", 0x50ED38, 0x20

	.global gMedaforceFullBodyRadPalette
gMedaforceFullBodyRadPalette:
	.incbin "baserom.gba", 0x50ED58, 0x20

	.global gMedaforceIronWallPalette
gMedaforceIronWallPalette:
	.incbin "baserom.gba", 0x50ED78, 0x20

	.global gMedaforcePowerUpPalette
gMedaforcePowerUpPalette:
	.incbin "baserom.gba", 0x50ED98, 0x20

	.global gMedaforceAntiTerrainBeamPalettes
gMedaforceAntiTerrainBeamPalettes:
	.incbin "baserom.gba", 0x50EDB8, 0x40

	.global gMedaforceAntiTerrainBoltPalettes
gMedaforceAntiTerrainBoltPalettes:
	.incbin "baserom.gba", 0x50EDF8, 0x40

	.global gMedaforceUpArrowPalettes
gMedaforceUpArrowPalettes:
	.incbin "baserom.gba", 0x50EE38, 0x40

	.global gMedaforceChargePalette
gMedaforceChargePalette:
	.incbin "baserom.gba", 0x50EE78, 0x20

	.global gMedaforceUselessPalette
gMedaforceUselessPalette:
	.incbin "baserom.gba", 0x50EE98, 0x20

	.global gMedaforceDestroyerPalette
gMedaforceDestroyerPalette:
	.incbin "baserom.gba", 0x50EEB8, 0x20

	.global gMedaforceCrazyShotPalette
gMedaforceCrazyShotPalette:
	.incbin "baserom.gba", 0x50EED8, 0x20

	.global gMedaforceLegCrashPalette
gMedaforceLegCrashPalette:
	.incbin "baserom.gba", 0x50EEF8, 0x20

	.global gMedaforceProtectorPalettes
gMedaforceProtectorPalettes:
	.incbin "baserom.gba", 0x50EF18, 0x40

	.global gUnk_0850EF58
gUnk_0850EF58:
	.incbin "baserom.gba", 0x50EF58, 0x810A8
