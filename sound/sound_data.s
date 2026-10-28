	.section .rodata

	.global gData_080AB000
gData_080AB000:
	.incbin "baserom.gba", 0xAB000, 0xBEC

	.global gAffineIdentityRotated
gAffineIdentityRotated:
	.incbin "baserom.gba", 0xABBEC, 0x8

	.global gAffineIdentity
gAffineIdentity:
	.incbin "baserom.gba", 0xABBF4, 0x8

	.global gUnk_080ABBFC
gUnk_080ABBFC:
	.incbin "baserom.gba", 0xABBFC, 0x898

	.global gFieldDebugLabelMd
gFieldDebugLabelMd:
	.incbin "baserom.gba", 0xAC494, 0x4

	.global gFieldDebugLabelMp
gFieldDebugLabelMp:
	.incbin "baserom.gba", 0xAC498, 0x4

	.global gFieldDebugLabelMn
gFieldDebugLabelMn:
	.incbin "baserom.gba", 0xAC49C, 0x4

	.global gFieldDebugLabelPt
gFieldDebugLabelPt:
	.incbin "baserom.gba", 0xAC4A0, 0x4

	.global gFieldDebugLabelNor
gFieldDebugLabelNor:
	.incbin "baserom.gba", 0xAC4A4, 0x4

	.global gFieldDebugLabelCar
gFieldDebugLabelCar:
	.incbin "baserom.gba", 0xAC4A8, 0x4

	.global gFieldDebugLabelSen
gFieldDebugLabelSen:
	.incbin "baserom.gba", 0xAC4AC, 0x4

	.global gFieldDebugLabelSka
gFieldDebugLabelSka:
	.incbin "baserom.gba", 0xAC4B0, 0x4

	.global gFieldDebugLabelKim
gFieldDebugLabelKim:
	.incbin "baserom.gba", 0xAC4B4, 0x4

	.global gFieldDebugLabelYus
gFieldDebugLabelYus:
	.incbin "baserom.gba", 0xAC4B8, 0x4

	.global gFieldDebugLabelRob
gFieldDebugLabelRob:
	.incbin "baserom.gba", 0xAC4BC, 0x4

	.global gFieldDebugLabelBan
gFieldDebugLabelBan:
	.incbin "baserom.gba", 0xAC4C0, 0x4

	.global gFieldDebugLabelDor
gFieldDebugLabelDor:
	.incbin "baserom.gba", 0xAC4C4, 0x4

	.global gFieldDebugLabelObo
gFieldDebugLabelObo:
	.incbin "baserom.gba", 0xAC4C8, 0x4

	.global gFieldDebugLabelMef
gFieldDebugLabelMef:
	.incbin "baserom.gba", 0xAC4CC, 0x4

	.global gFieldDebugLabelKaz
gFieldDebugLabelKaz:
	.incbin "baserom.gba", 0xAC4D0, 0x4

	.global gFieldDebugLabelGin
gFieldDebugLabelGin:
	.incbin "baserom.gba", 0xAC4D4, 0x4

	.global gFieldDebugLabelDog
gFieldDebugLabelDog:
	.incbin "baserom.gba", 0xAC4D8, 0x4

	.global gFieldDebugLabelKok
gFieldDebugLabelKok:
	.incbin "baserom.gba", 0xAC4DC, 0x4

	.global gFieldDebugLabelJet
gFieldDebugLabelJet:
	.incbin "baserom.gba", 0xAC4E0, 0x4

	.global gFieldDebugLabelMf
gFieldDebugLabelMf:
	.incbin "baserom.gba", 0xAC4E4, 0x4

	.global gFieldDebugLabelEf
gFieldDebugLabelEf:
	.incbin "baserom.gba", 0xAC4E8, 0x4

	.global gFieldDebugLabelEe
gFieldDebugLabelEe:
	.incbin "baserom.gba", 0xAC4EC, 0x4

	.global gFieldDebugLabelTe
gFieldDebugLabelTe:
	.incbin "baserom.gba", 0xAC4F0, 0x4

	.global gFieldDebugLabelEx
gFieldDebugLabelEx:
	.incbin "baserom.gba", 0xAC4F4, 0x4

	.global gFieldDebugLabelSt
gFieldDebugLabelSt:
	.incbin "baserom.gba", 0xAC4F8, 0x4

	.global gFieldDebugLabelCm
gFieldDebugLabelCm:
	.incbin "baserom.gba", 0xAC4FC, 0x4

	.global gFieldDebugLabelEvent
gFieldDebugLabelEvent:
	.incbin "baserom.gba", 0xAC500, 0x8

	.global gFieldDebugLabelEno
gFieldDebugLabelEno:
	.incbin "baserom.gba", 0xAC508, 0x4

	.global gFieldDebugLabelFlg
gFieldDebugLabelFlg:
	.incbin "baserom.gba", 0xAC50C, 0x4

	.global gFieldDebugLabelX
gFieldDebugLabelX:
	.incbin "baserom.gba", 0xAC510, 0x4

	.global gFieldDebugLabelLv
gFieldDebugLabelLv:
	.incbin "baserom.gba", 0xAC514, 0x4

	.global gFieldDebugLabelPlayer
gFieldDebugLabelPlayer:
	.incbin "baserom.gba", 0xAC518, 0x8

	.global gFieldDebugLabelPlx
gFieldDebugLabelPlx:
	.incbin "baserom.gba", 0xAC520, 0x4

	.global gFieldDebugLabelPly
gFieldDebugLabelPly:
	.incbin "baserom.gba", 0xAC524, 0x4

	.global gFieldDebugLabelMapEffect
gFieldDebugLabelMapEffect:
	.incbin "baserom.gba", 0xAC528, 0xC

	.global gFieldDebugLabelMen
gFieldDebugLabelMen:
	.incbin "baserom.gba", 0xAC534, 0x4

	.global gFieldDebugLabelKwg
gFieldDebugLabelKwg:
	.incbin "baserom.gba", 0xAC538, 0x4

	.global gFieldDebugLabelDc
gFieldDebugLabelDc:
	.incbin "baserom.gba", 0xAC53C, 0x4

	.global gFieldDebugLabelMl
gFieldDebugLabelMl:
	.incbin "baserom.gba", 0xAC540, 0x4

	.global gFieldDebugLabelBt
gFieldDebugLabelBt:
	.incbin "baserom.gba", 0xAC544, 0x4

	.global gFieldDebugLabelR
gFieldDebugLabelR:
	.incbin "baserom.gba", 0xAC548, 0x4

	.global gFieldDebugLabelBlank
gFieldDebugLabelBlank:
	.incbin "baserom.gba", 0xAC54C, 0x4

	.global gFieldDebugLabelE
gFieldDebugLabelE:
	.incbin "baserom.gba", 0xAC550, 0x4

	.global gFieldDebugLabelSk
gFieldDebugLabelSk:
	.incbin "baserom.gba", 0xAC554, 0x4

	.global gFieldDebugLabelSp
gFieldDebugLabelSp:
	.incbin "baserom.gba", 0xAC558, 0x4

	.global gFieldDebugLabelWl
gFieldDebugLabelWl:
	.incbin "baserom.gba", 0xAC55C, 0x4

	.global gFieldDebugLabelN
gFieldDebugLabelN:
	.incbin "baserom.gba", 0xAC560, 0x4

	.global gFieldDebugLabelW
gFieldDebugLabelW:
	.incbin "baserom.gba", 0xAC564, 0x4

	.global gFieldDebugLabelL
gFieldDebugLabelL:
	.incbin "baserom.gba", 0xAC568, 0x4

	.global gFieldDebugLabelKoma
gFieldDebugLabelKoma:
	.incbin "baserom.gba", 0xAC56C, 0x8

	.global gFieldDebugLabelKno
gFieldDebugLabelKno:
	.incbin "baserom.gba", 0xAC574, 0x4

	.global gFieldDebugLabelMess
gFieldDebugLabelMess:
	.incbin "baserom.gba", 0xAC578, 0x8

	.global gFieldDebugLabelMsb
gFieldDebugLabelMsb:
	.incbin "baserom.gba", 0xAC580, 0x4

	.global gFieldDebugLabelMsn
gFieldDebugLabelMsn:
	.incbin "baserom.gba", 0xAC584, 0x4

	.global gFieldDebugLabelMsf
gFieldDebugLabelMsf:
	.incbin "baserom.gba", 0xAC588, 0x4

	.global gFieldDebugLabelMax
gFieldDebugLabelMax:
	.incbin "baserom.gba", 0xAC58C, 0x4

	.global gFieldDebugLabelAr
gFieldDebugLabelAr:
	.incbin "baserom.gba", 0xAC590, 0x4

	.global gFieldDebugLabelKa
gFieldDebugLabelKa:
	.incbin "baserom.gba", 0xAC594, 0x4

	.global gFieldDebugLabelBgm
gFieldDebugLabelBgm:
	.incbin "baserom.gba", 0xAC598, 0x4

	.global gFieldDebugLabelSe
gFieldDebugLabelSe:
	.incbin "baserom.gba", 0xAC59C, 0x4

	.global gFieldDebugLabelPnt
gFieldDebugLabelPnt:
	.incbin "baserom.gba", 0xAC5A0, 0x4

	.global gFieldDebugHexDigits
gFieldDebugHexDigits:
	.incbin "baserom.gba", 0xAC5A4, 0x10

	.global gFallbackAreaPalette0
gFallbackAreaPalette0:
	.incbin "baserom.gba", 0xAC5B4, 0x20

	.global gFallbackAreaTiles0
gFallbackAreaTiles0:
	.incbin "baserom.gba", 0xAC5D4, 0x80

	.global gFallbackAreaPalette1
gFallbackAreaPalette1:
	.incbin "baserom.gba", 0xAC654, 0x20

	.global gFallbackAreaTiles1
gFallbackAreaTiles1:
	.incbin "baserom.gba", 0xAC674, 0x80

	.global gFallbackAreaPalette2
gFallbackAreaPalette2:
	.incbin "baserom.gba", 0xAC6F4, 0x20

	.global gFallbackAreaTiles2
gFallbackAreaTiles2:
	.incbin "baserom.gba", 0xAC714, 0x80

	.global gFallbackAreaPalette3
gFallbackAreaPalette3:
	.incbin "baserom.gba", 0xAC794, 0x20

	.global gFallbackAreaTiles3
gFallbackAreaTiles3:
	.incbin "baserom.gba", 0xAC7B4, 0x80

	.global gFallbackAreaPalette4
gFallbackAreaPalette4:
	.incbin "baserom.gba", 0xAC834, 0x20

	.global gFallbackAreaTiles4
gFallbackAreaTiles4:
	.incbin "baserom.gba", 0xAC854, 0x80

	.global gFallbackAreaPalette5
gFallbackAreaPalette5:
	.incbin "baserom.gba", 0xAC8D4, 0x20

	.global gFallbackAreaTiles5
gFallbackAreaTiles5:
	.incbin "baserom.gba", 0xAC8F4, 0x288

	.global gFieldDebugFont
gFieldDebugFont:
	.incbin "baserom.gba", 0xACB7C, 0x1C00

	.global gSineTable
gSineTable:
	.incbin "baserom.gba", 0xAE77C, 0x280

	.global gSpriteAnimGfx
gSpriteAnimGfx:
	.incbin "baserom.gba", 0xAE9FC, 0xC00

	.global gUnk_080AF5FC
gUnk_080AF5FC:
	.incbin "baserom.gba", 0xAF5FC, 0x78

	.global gUnk_080AF674
gUnk_080AF674:
	.incbin "baserom.gba", 0xAF674, 0x78

	.global gUnk_080AF6EC
gUnk_080AF6EC:
	.incbin "baserom.gba", 0xAF6EC, 0x4

	.global gTitleMenuBlendAlphas
gTitleMenuBlendAlphas:
	.incbin "baserom.gba", 0xAF6F0, 0x50

	.global gTitleOptionValueMasks
gTitleOptionValueMasks:
	.incbin "baserom.gba", 0xAF740, 0x12

	.global gBattleMusicOptionSongs
gBattleMusicOptionSongs:
	.incbin "baserom.gba", 0xAF752, 0x3

	.global gUnk_080AF755
gUnk_080AF755:
	.incbin "baserom.gba", 0xAF755, 0x53

	.global gUnk_080AF7A8
gUnk_080AF7A8:
	.incbin "baserom.gba", 0xAF7A8, 0x18

	.global gUnk_080AF7C0
gUnk_080AF7C0:
	.incbin "baserom.gba", 0xAF7C0, 0x20

	.global gSaveScreenSpriteFrames
gSaveScreenSpriteFrames:
	.incbin "baserom.gba", 0xAF7E0, 0x8

	.global gUnk_080AF7E8
gUnk_080AF7E8:
	.incbin "baserom.gba", 0xAF7E8, 0x20

	.global gNameEntrySpriteFrames
gNameEntrySpriteFrames:
	.incbin "baserom.gba", 0xAF808, 0x8

	.global gNameEntryObjPalette
gNameEntryObjPalette:
	.incbin "baserom.gba", 0xAF810, 0x40

	.global gNameEntryColumnRemap
gNameEntryColumnRemap:
	.incbin "baserom.gba", 0xAF850, 0x4

	.global gSoundTestSongs
gSoundTestSongs:
	.incbin "baserom.gba", 0xAF854, 0x34

	.global gSoundTestEffects
gSoundTestEffects:
	.incbin "baserom.gba", 0xAF888, 0x78

	.global gUnk_080AF900
gUnk_080AF900:
	.incbin "baserom.gba", 0xAF900, 0x42

	.global gGameOverIkkiFrames
gGameOverIkkiFrames:
	.incbin "baserom.gba", 0xAF942, 0x18

	.global gGameOverLogoBounce
gGameOverLogoBounce:
	.incbin "baserom.gba", 0xAF95A, 0xE

	.global gGameOverIkkiFramesExit
gGameOverIkkiFramesExit:
	.incbin "baserom.gba", 0xAF968, 0x18

	.global gSaveLostSpriteFrames
gSaveLostSpriteFrames:
	.incbin "baserom.gba", 0xAF980, 0x8

	.global gSaveLostSpritePalette
gSaveLostSpritePalette:
	.incbin "baserom.gba", 0xAF988, 0x20

	.global gTownMapObjPalettes
gTownMapObjPalettes:
	.incbin "baserom.gba", 0xAF9A8, 0x60

	.global gShopPartTypeIconPos
gShopPartTypeIconPos:
	.incbin "baserom.gba", 0xAFA08, 0x8

	.global gShopkeeperPortraitSets
gShopkeeperPortraitSets:
	.incbin "baserom.gba", 0xAFA10, 0x10

	.global gUnk_080AFA20
gUnk_080AFA20:
	.incbin "baserom.gba", 0xAFA20, 0x1C

	.global gPartTradeSpritePositions
gPartTradeSpritePositions:
	.incbin "baserom.gba", 0xAFA3C, 0x10

	.global gPartTradeObjPalette
gPartTradeObjPalette:
	.incbin "baserom.gba", 0xAFA4C, 0x20

	.global gPartTradeStates
gPartTradeStates:
	.incbin "baserom.gba", 0xAFA6C, 0x34

	.global gMedalTradeStates
gMedalTradeStates:
	.incbin "baserom.gba", 0xAFAA0, 0x30

	.global gUnk_080AFAD0
gUnk_080AFAD0:
	.incbin "baserom.gba", 0xAFAD0, 0x10

	.global gUnk_080AFAE0
gUnk_080AFAE0:
	.incbin "baserom.gba", 0xAFAE0, 0x8

	.global gUnk_080AFAE8
gUnk_080AFAE8:
	.incbin "baserom.gba", 0xAFAE8, 0x20

	.global gLinkIntroMessageIds
gLinkIntroMessageIds:
	.incbin "baserom.gba", 0xAFB08, 0x3

	.global gLinkStartMessageIds
gLinkStartMessageIds:
	.incbin "baserom.gba", 0xAFB0B, 0x5

	.global gLinkStartStates
gLinkStartStates:
	.incbin "baserom.gba", 0xAFB10, 0x20

	.global gLinkAnswersDifferMessage
gLinkAnswersDifferMessage:
	.incbin "baserom.gba", 0xAFB30, 0xF

	.global gLinkMenuHelpMessageIds
gLinkMenuHelpMessageIds:
	.incbin "baserom.gba", 0xAFB3F, 0x6

	.global gLinkMenuGameModes
gLinkMenuGameModes:
	.incbin "baserom.gba", 0xAFB45, 0x3

	.global gLinkMenuStates
gLinkMenuStates:
	.incbin "baserom.gba", 0xAFB48, 0x34E

	.global gTextScrollHeadingX
gTextScrollHeadingX:
	.incbin "baserom.gba", 0xAFE96, 0x6

	.global gTextScrollPages
gTextScrollPages:
	.incbin "baserom.gba", 0xAFE9C, 0xC

	.global gTextScrollStates
gTextScrollStates:
	.incbin "baserom.gba", 0xAFEA8, 0x1C

	.global gUnk_080AFEC4
gUnk_080AFEC4:
	.incbin "baserom.gba", 0xAFEC4, 0x1C

	.global gRaceTileBlockWidths
gRaceTileBlockWidths:
	.incbin "baserom.gba", 0xAFEE0, 0x8

	.global gRaceTileBlockHeights
gRaceTileBlockHeights:
	.incbin "baserom.gba", 0xAFEE8, 0x8

	.global gRaceTileBlockFirstTiles
gRaceTileBlockFirstTiles:
	.incbin "baserom.gba", 0xAFEF0, 0x10

	.global gRaceTileBlockLists
gRaceTileBlockLists:
	.incbin "baserom.gba", 0xAFF00, 0x20

	.global gRaceTileBlockPalettes
gRaceTileBlockPalettes:
	.incbin "baserom.gba", 0xAFF20, 0x10

	.global gRaceTeamSpriteParams
gRaceTeamSpriteParams:
	.incbin "baserom.gba", 0xAFF30, 0x4

	.global gBombGameDebrisTimes
gBombGameDebrisTimes:
	.incbin "baserom.gba", 0xAFF34, 0xC

	.global gBombGameBannerEva
gBombGameBannerEva:
	.incbin "baserom.gba", 0xAFF40, 0x8

	.global gBombGameBannerEvb
gBombGameBannerEvb:
	.incbin "baserom.gba", 0xAFF48, 0x8

	.global gIntroBobOffsets
gIntroBobOffsets:
	.incbin "baserom.gba", 0xAFF50, 0x40

	.global gCycleAnimFrameOffsets
gCycleAnimFrameOffsets:
	.incbin "baserom.gba", 0xAFF90, 0x4

	.global gWeeklyCurtainOpenTimes
gWeeklyCurtainOpenTimes:
	.incbin "baserom.gba", 0xAFF94, 0x8

	.global gWeeklyCurtainCloseTimes
gWeeklyCurtainCloseTimes:
	.incbin "baserom.gba", 0xAFF9C, 0xC

	.global gWeeklyLectureSfxScript
gWeeklyLectureSfxScript:
	.incbin "baserom.gba", 0xAFFA8, 0x10

	.global gSongTable
gSongTable:
	.incbin "baserom.gba", 0xAFFB8, 0x6F4

	.global gSoundWavePatterns
gSoundWavePatterns:
	.incbin "baserom.gba", 0xB06AC, 0x40

	.global gSoundEffectTable
gSoundEffectTable:
	.incbin "baserom.gba", 0xB06EC, 0xE84

	.global gInstrumentSamples
gInstrumentSamples:
	.incbin "baserom.gba", 0xB1570, 0x1A8

	.global gDrumSamples
gDrumSamples:
	.incbin "baserom.gba", 0xB1718, 0x70

	.global gDrumKit
gDrumKit:
	.incbin "baserom.gba", 0xB1788, 0x2FA248
