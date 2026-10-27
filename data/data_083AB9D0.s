	.section .rodata

	.global gData_083AB9D0
gData_083AB9D0:

	.global gUnk_083AB9D0
gUnk_083AB9D0:
	.incbin "baserom.gba", 0x3AB9D0, 0x92

	.global gUnk_083ABA62
gUnk_083ABA62:
	.incbin "baserom.gba", 0x3ABA62, 0x10

	.global gSoundOutputMasks
gSoundOutputMasks:
	.incbin "baserom.gba", 0x3ABA72, 0x4

	.global gSoundOutputBits
gSoundOutputBits:
	.incbin "baserom.gba", 0x3ABA76, 0x12

	.global gUnk_083ABA88
gUnk_083ABA88:
	.incbin "baserom.gba", 0x3ABA88, 0x4

	.global gUnk_083ABA8C
gUnk_083ABA8C:
	.incbin "baserom.gba", 0x3ABA8C, 0x20

	.global gSoundFifoResetBits
gSoundFifoResetBits:
	.incbin "baserom.gba", 0x3ABAAC, 0x2

	.global gSoundFifoEnableBits
gSoundFifoEnableBits:
	.incbin "baserom.gba", 0x3ABAAE, 0x4

	.global gUnk_083ABAB2
gUnk_083ABAB2:
	.incbin "baserom.gba", 0x3ABAB2, 0x10

	.global gUnk_083ABAC2
gUnk_083ABAC2:
	.incbin "baserom.gba", 0x3ABAC2, 0x4

	.global gSoundSemitoneRatios
gSoundSemitoneRatios:
	.incbin "baserom.gba", 0x3ABAC6, 0x18

	.global gSoundFinetuneRatios
gSoundFinetuneRatios:
	.incbin "baserom.gba", 0x3ABADE, 0x102

	.global gSoundTrackConfigs
gSoundTrackConfigs:
	.incbin "baserom.gba", 0x3ABBE0, 0x9C

	.global gSoundEffectTracks
gSoundEffectTracks:
	.incbin "baserom.gba", 0x3ABC7C, 0x24

	.global gUnk_083ABCA0
gUnk_083ABCA0:
	.incbin "baserom.gba", 0x3ABCA0, 0xC

	.global gUnk_083ABCAC
gUnk_083ABCAC:
	.incbin "baserom.gba", 0x3ABCAC, 0xC

	.global gUnk_083ABCB8
gUnk_083ABCB8:
	.incbin "baserom.gba", 0x3ABCB8, 0x160

	.global gUnk_083ABE18
gUnk_083ABE18:
	.incbin "baserom.gba", 0x3ABE18, 0x18

	.global gUnk_083ABE30
gUnk_083ABE30:
	.incbin "baserom.gba", 0x3ABE30, 0x258

	.global gUnk_083AC088
gUnk_083AC088:
	.incbin "baserom.gba", 0x3AC088, 0x40

	.global gUnk_083AC0C8
gUnk_083AC0C8:
	.incbin "baserom.gba", 0x3AC0C8, 0x40

	.global gUnk_083AC108
gUnk_083AC108:
	.incbin "baserom.gba", 0x3AC108, 0x40

	.global gGameStateHandlers_083AC148
gGameStateHandlers_083AC148:
	.incbin "baserom.gba", 0x3AC148, 0x100

	.global gUnk_083AC248
gUnk_083AC248:
	.incbin "baserom.gba", 0x3AC248, 0x3C

	.global gFieldMenuHandlers
gFieldMenuHandlers:
	.incbin "baserom.gba", 0x3AC284, 0x50

	.global gMedawatchMenuHandlers
gMedawatchMenuHandlers:
	.incbin "baserom.gba", 0x3AC2D4, 0x4C

	.global gMedabotsScreenHandlers
gMedabotsScreenHandlers:
	.incbin "baserom.gba", 0x3AC320, 0x100

	.global gUnk_083AC420
gUnk_083AC420:
	.incbin "baserom.gba", 0x3AC420, 0x12

	.global gUnk_083AC432
gUnk_083AC432:
	.incbin "baserom.gba", 0x3AC432, 0x9

	.global gUnk_083AC43B
gUnk_083AC43B:
	.incbin "baserom.gba", 0x3AC43B, 0x12

	.global gUnk_083AC44D
gUnk_083AC44D:
	.incbin "baserom.gba", 0x3AC44D, 0x1B

	.global gUnk_083AC468
gUnk_083AC468:
	.incbin "baserom.gba", 0x3AC468, 0x1C

	.global gMedabotSlotDpadMoves
gMedabotSlotDpadMoves:
	.incbin "baserom.gba", 0x3AC484, 0x10

	.global gUnk_083AC494
gUnk_083AC494:
	.incbin "baserom.gba", 0x3AC494, 0x258

	.global gMedalsScreenHandlers
gMedalsScreenHandlers:
	.incbin "baserom.gba", 0x3AC6EC, 0x1C0

	.global gMedalSkillDebugCursorPos
gMedalSkillDebugCursorPos:
	.incbin "baserom.gba", 0x3AC8AC, 0x20

	.global gMedalTradeChoiceCloseSteps
gMedalTradeChoiceCloseSteps:
	.incbin "baserom.gba", 0x3AC8CC, 0x10

	.global gDebugMenuHandlers
gDebugMenuHandlers:
	.incbin "baserom.gba", 0x3AC8DC, 0x24

	.global gDebugMenuEntryHandlers
gDebugMenuEntryHandlers:
	.incbin "baserom.gba", 0x3AC900, 0x40

	.global gDebugProcessHandlers
gDebugProcessHandlers:
	.incbin "baserom.gba", 0x3AC940, 0xC

	.global gDebugMedalHandlers
gDebugMedalHandlers:
	.incbin "baserom.gba", 0x3AC94C, 0xC

	.global gDebugPartsHandlers
gDebugPartsHandlers:
	.incbin "baserom.gba", 0x3AC958, 0xC

	.global gDebugTinpetHandlers
gDebugTinpetHandlers:
	.incbin "baserom.gba", 0x3AC964, 0xC

	.global gDebugItemHandlers
gDebugItemHandlers:
	.incbin "baserom.gba", 0x3AC970, 0xC

	.global gDebugFaceHandlers
gDebugFaceHandlers:
	.incbin "baserom.gba", 0x3AC97C, 0xC

	.global gDebugMdlpicHandlers
gDebugMdlpicHandlers:
	.incbin "baserom.gba", 0x3AC988, 0xC

	.global gDebugRndTkHandlers
gDebugRndTkHandlers:
	.incbin "baserom.gba", 0x3AC994, 0xC

	.global gDebugBattleHandlers
gDebugBattleHandlers:
	.incbin "baserom.gba", 0x3AC9A0, 0xC

	.global gDebugSoundHandlers
gDebugSoundHandlers:
	.incbin "baserom.gba", 0x3AC9AC, 0xC

	.global gDebugMotionHandlers
gDebugMotionHandlers:
	.incbin "baserom.gba", 0x3AC9B8, 0x68

	.global gDebugMenuLabels
gDebugMenuLabels:
	.incbin "baserom.gba", 0x3ACA20, 0x44

	.global gDebugProcessLabels
gDebugProcessLabels:
	.incbin "baserom.gba", 0x3ACA64, 0x24

	.global gDebugMedalLabels
gDebugMedalLabels:
	.incbin "baserom.gba", 0x3ACA88, 0x24

	.global gDebugPartsLabels
gDebugPartsLabels:
	.incbin "baserom.gba", 0x3ACAAC, 0x14

	.global gDebugTinpetLabels
gDebugTinpetLabels:
	.incbin "baserom.gba", 0x3ACAC0, 0x1C

	.global gDebugItemLabels
gDebugItemLabels:
	.incbin "baserom.gba", 0x3ACADC, 0x1C

	.global gDebugFaceLabels
gDebugFaceLabels:
	.incbin "baserom.gba", 0x3ACAF8, 0x18

	.global gDebugMdlpicLabels
gDebugMdlpicLabels:
	.incbin "baserom.gba", 0x3ACB10, 0x10

	.global gDebugRndTkLabels
gDebugRndTkLabels:
	.incbin "baserom.gba", 0x3ACB20, 0xC

	.global gDebugBattleLabels
gDebugBattleLabels:
	.incbin "baserom.gba", 0x3ACB2C, 0x14

	.global gDebugSoundLabels
gDebugSoundLabels:
	.incbin "baserom.gba", 0x3ACB40, 0x10

	.global gDebugMotionLabels
gDebugMotionLabels:
	.incbin "baserom.gba", 0x3ACB50, 0x4

	.global gMedapartsScreenHandlers
gMedapartsScreenHandlers:
	.incbin "baserom.gba", 0x3ACB54, 0x140

	.global gMedapartTradeChoiceCloseSteps
gMedapartTradeChoiceCloseSteps:
	.incbin "baserom.gba", 0x3ACC94, 0x10

	.global gPrebattleScreenHandlers
gPrebattleScreenHandlers:
	.incbin "baserom.gba", 0x3ACCA4, 0x240

	.global gUnk_083ACEE4
gUnk_083ACEE4:
	.incbin "baserom.gba", 0x3ACEE4, 0x6

	.global gUnk_083ACEEA
gUnk_083ACEEA:
	.incbin "baserom.gba", 0x3ACEEA, 0x6

	.global gRandomBotSlotStarts
gRandomBotSlotStarts:
	.incbin "baserom.gba", 0x3ACEF0, 0x10

	.global gRobattleHandlers
gRobattleHandlers:
	.incbin "baserom.gba", 0x3ACF00, 0x300

	.global gUnk_083AD200
gUnk_083AD200:
	.incbin "baserom.gba", 0x3AD200, 0xF0

	.global gUnk_083AD2F0
gUnk_083AD2F0:
	.incbin "baserom.gba", 0x3AD2F0, 0x80

	.global gUnk_083AD370
gUnk_083AD370:
	.incbin "baserom.gba", 0x3AD370, 0x6

	.global gUnk_083AD376
gUnk_083AD376:
	.incbin "baserom.gba", 0x3AD376, 0x6

	.global gUnk_083AD37C
gUnk_083AD37C:
	.incbin "baserom.gba", 0x3AD37C, 0x6

	.global gUnk_083AD382
gUnk_083AD382:
	.incbin "baserom.gba", 0x3AD382, 0x18

	.global gUnk_083AD39A
gUnk_083AD39A:
	.incbin "baserom.gba", 0x3AD39A, 0x6

	.global gUnk_083AD3A0
gUnk_083AD3A0:
	.incbin "baserom.gba", 0x3AD3A0, 0x4

	.global gUnk_083AD3A4
gUnk_083AD3A4:
	.incbin "baserom.gba", 0x3AD3A4, 0xC

	.global gUnk_083AD3B0
gUnk_083AD3B0:
	.incbin "baserom.gba", 0x3AD3B0, 0x3

	.global gUnk_083AD3B3
gUnk_083AD3B3:
	.incbin "baserom.gba", 0x3AD3B3, 0x20

	.global gUnk_083AD3D3
gUnk_083AD3D3:
	.incbin "baserom.gba", 0x3AD3D3, 0x20

	.global gUnk_083AD3F3
gUnk_083AD3F3:
	.incbin "baserom.gba", 0x3AD3F3, 0x6

	.global gUnk_083AD3F9
gUnk_083AD3F9:
	.incbin "baserom.gba", 0x3AD3F9, 0x7

	.global gBattleMessageSteps
gBattleMessageSteps:
	.incbin "baserom.gba", 0x3AD400, 0x10

	.global gMissPopupSteps
gMissPopupSteps:
	.incbin "baserom.gba", 0x3AD410, 0x14

	.global gTargetPanelSteps
gTargetPanelSteps:
	.incbin "baserom.gba", 0x3AD424, 0x28

	.global gTrapHitSteps
gTrapHitSteps:
	.incbin "baserom.gba", 0x3AD44C, 0xC0

	.global gActionPartCheckSteps
gActionPartCheckSteps:
	.incbin "baserom.gba", 0x3AD50C, 0x24

	.global gTargetPartCheckSteps
gTargetPartCheckSteps:
	.incbin "baserom.gba", 0x3AD530, 0x20

	.global gActionFlashSteps
gActionFlashSteps:
	.incbin "baserom.gba", 0x3AD550, 0x20

	.global gGuardSteps
gGuardSteps:
	.incbin "baserom.gba", 0x3AD570, 0x40

	.global gActionAnnounceSteps
gActionAnnounceSteps:
	.incbin "baserom.gba", 0x3AD5B0, 0x20

	.global gCloseupEnterSteps
gCloseupEnterSteps:
	.incbin "baserom.gba", 0x3AD5D0, 0x40

	.global gAttackHitSteps
gAttackHitSteps:
	.incbin "baserom.gba", 0x3AD610, 0x140

	.global gStatusAttackSteps
gStatusAttackSteps:
	.incbin "baserom.gba", 0x3AD750, 0x44

	.global gCloseupExitSteps
gCloseupExitSteps:
	.incbin "baserom.gba", 0x3AD794, 0x40

	.global gBotDefeatSteps
gBotDefeatSteps:
	.incbin "baserom.gba", 0x3AD7D4, 0x40

	.global gReactionSteps
gReactionSteps:
	.incbin "baserom.gba", 0x3AD814, 0x64

	.global gSacrificeSteps
gSacrificeSteps:
	.incbin "baserom.gba", 0x3AD878, 0x20

	.global gDestroyCheckSteps
gDestroyCheckSteps:
	.incbin "baserom.gba", 0x3AD898, 0x20

	.global gRecoverySteps
gRecoverySteps:
	.incbin "baserom.gba", 0x3AD8B8, 0x20

	.global gRecoveryHealSteps
gRecoveryHealSteps:
	.incbin "baserom.gba", 0x3AD8D8, 0x64

	.global gRepairSteps
gRepairSteps:
	.incbin "baserom.gba", 0x3AD93C, 0x20

	.global gRepairApplySteps
gRepairApplySteps:
	.incbin "baserom.gba", 0x3AD95C, 0x64

	.global gTrapSteps
gTrapSteps:
	.incbin "baserom.gba", 0x3AD9C0, 0xAC

	.global gBreakFormSteps
gBreakFormSteps:
	.incbin "baserom.gba", 0x3ADA6C, 0x80

	.global gStabilitySteps
gStabilitySteps:
	.incbin "baserom.gba", 0x3ADAEC, 0x40

	.global gForceBindSteps
gForceBindSteps:
	.incbin "baserom.gba", 0x3ADB2C, 0x40

	.global gDefenceSteps
gDefenceSteps:
	.incbin "baserom.gba", 0x3ADB6C, 0x40

	.global gAutoRecoverSteps
gAutoRecoverSteps:
	.incbin "baserom.gba", 0x3ADBAC, 0x60

	.global gReactivateSteps
gReactivateSteps:
	.incbin "baserom.gba", 0x3ADC0C, 0x60

	.global gScoutSteps
gScoutSteps:
	.incbin "baserom.gba", 0x3ADC6C, 0x54

	.global gConcealSteps
gConcealSteps:
	.incbin "baserom.gba", 0x3ADCC0, 0x60

	.global gBoostChargeSteps
gBoostChargeSteps:
	.incbin "baserom.gba", 0x3ADD20, 0x60

	.global gRapidChargeSteps
gRapidChargeSteps:
	.incbin "baserom.gba", 0x3ADD80, 0x60

	.global gDrainChargeSteps
gDrainChargeSteps:
	.incbin "baserom.gba", 0x3ADDE0, 0x80

	.global gPushoverSteps
gPushoverSteps:
	.incbin "baserom.gba", 0x3ADE60, 0x80

	.global gBurstSpriteDirections
gBurstSpriteDirections:
	.incbin "baserom.gba", 0x3ADEE0, 0x4

	.global gImpairSteps
gImpairSteps:
	.incbin "baserom.gba", 0x3ADEE4, 0x60

	.global gConfusionSteps
gConfusionSteps:
	.incbin "baserom.gba", 0x3ADF44, 0x60

	.global gUseDrainSteps
gUseDrainSteps:
	.incbin "baserom.gba", 0x3ADFA4, 0x60

	.global gNoEscapeDefenseSteps
gNoEscapeDefenseSteps:
	.incbin "baserom.gba", 0x3AE004, 0x60

	.global gForcedrainSteps
gForcedrainSteps:
	.incbin "baserom.gba", 0x3AE064, 0x80

	.global gTeamAttackCheckSteps
gTeamAttackCheckSteps:
	.incbin "baserom.gba", 0x3AE0E4, 0x1C

	.global gTeamAttackTurretSteps
gTeamAttackTurretSteps:
	.incbin "baserom.gba", 0x3AE100, 0x18

	.global gCounterAttackSteps
gCounterAttackSteps:
	.incbin "baserom.gba", 0x3AE118, 0x54

	.global gChangeSteps
gChangeSteps:
	.incbin "baserom.gba", 0x3AE16C, 0x54

	.global gUnk_083AE1C0
gUnk_083AE1C0:
	.incbin "baserom.gba", 0x3AE1C0, 0x80

	.global gUnk_083AE240
gUnk_083AE240:
	.incbin "baserom.gba", 0x3AE240, 0xC0

	.global gUnk_083AE300
gUnk_083AE300:
	.incbin "baserom.gba", 0x3AE300, 0x80

	.global gUnk_083AE380
gUnk_083AE380:
	.incbin "baserom.gba", 0x3AE380, 0x80

	.global gUnk_083AE400
gUnk_083AE400:
	.incbin "baserom.gba", 0x3AE400, 0x40

	.global gUnk_083AE440
gUnk_083AE440:
	.incbin "baserom.gba", 0x3AE440, 0x40

	.global gUnk_083AE480
gUnk_083AE480:
	.incbin "baserom.gba", 0x3AE480, 0x40

	.global gUnk_083AE4C0
gUnk_083AE4C0:
	.incbin "baserom.gba", 0x3AE4C0, 0x40

	.global gUnk_083AE500
gUnk_083AE500:
	.incbin "baserom.gba", 0x3AE500, 0x40

	.global gUnk_083AE540
gUnk_083AE540:
	.incbin "baserom.gba", 0x3AE540, 0x40

	.global gUnk_083AE580
gUnk_083AE580:
	.incbin "baserom.gba", 0x3AE580, 0x40

	.global gUnk_083AE5C0
gUnk_083AE5C0:
	.incbin "baserom.gba", 0x3AE5C0, 0x40

	.global gUnk_083AE600
gUnk_083AE600:
	.incbin "baserom.gba", 0x3AE600, 0x40

	.global gUnk_083AE640
gUnk_083AE640:
	.incbin "baserom.gba", 0x3AE640, 0x40

	.global gUnk_083AE680
gUnk_083AE680:
	.incbin "baserom.gba", 0x3AE680, 0x40

	.global gUnk_083AE6C0
gUnk_083AE6C0:
	.incbin "baserom.gba", 0x3AE6C0, 0x40

	.global gUnk_083AE700
gUnk_083AE700:
	.incbin "baserom.gba", 0x3AE700, 0x50

	.global gUnk_083AE750
gUnk_083AE750:
	.incbin "baserom.gba", 0x3AE750, 0x40

	.global gUnk_083AE790
gUnk_083AE790:
	.incbin "baserom.gba", 0x3AE790, 0x40

	.global gUnk_083AE7D0
gUnk_083AE7D0:
	.incbin "baserom.gba", 0x3AE7D0, 0x4

	.global gUnk_083AE7D4
gUnk_083AE7D4:
	.incbin "baserom.gba", 0x3AE7D4, 0x40

	.global gUnk_083AE814
gUnk_083AE814:
	.incbin "baserom.gba", 0x3AE814, 0x40

	.global gUnk_083AE854
gUnk_083AE854:
	.incbin "baserom.gba", 0x3AE854, 0x5C

	.global gUnk_083AE8B0
gUnk_083AE8B0:
	.incbin "baserom.gba", 0x3AE8B0, 0x58

	.global gUnk_083AE908
gUnk_083AE908:
	.incbin "baserom.gba", 0x3AE908, 0x80

	.global gUnk_083AE988
gUnk_083AE988:
	.incbin "baserom.gba", 0x3AE988, 0x14

	.global gUnk_083AE99C
gUnk_083AE99C:
	.incbin "baserom.gba", 0x3AE99C, 0x6C

	.global gUnk_083AEA08
gUnk_083AEA08:
	.incbin "baserom.gba", 0x3AEA08, 0x3C

	.global gUnk_083AEA44
gUnk_083AEA44:
	.incbin "baserom.gba", 0x3AEA44, 0x40

	.global gUnk_083AEA84
gUnk_083AEA84:
	.incbin "baserom.gba", 0x3AEA84, 0x54

	.global gUnk_083AEAD8
gUnk_083AEAD8:
	.incbin "baserom.gba", 0x3AEAD8, 0x40

	.global gUnk_083AEB18
gUnk_083AEB18:
	.incbin "baserom.gba", 0x3AEB18, 0x40

	.global gActionPhaseSteps
gActionPhaseSteps:
	.incbin "baserom.gba", 0x3AEB58, 0x1C0

	.global gLevelUpSkillPalettes
gLevelUpSkillPalettes:
	.incbin "baserom.gba", 0x3AED18, 0x8

	.global gUnk_083AED20
gUnk_083AED20:
	.incbin "baserom.gba", 0x3AED20, 0xF0

	.global gUnk_083AEE10
gUnk_083AEE10:
	.incbin "baserom.gba", 0x3AEE10, 0xF0

	.global gUnk_083AEF00
gUnk_083AEF00:
	.incbin "baserom.gba", 0x3AEF00, 0x10

	.global gUnk_083AEF10
gUnk_083AEF10:
	.incbin "baserom.gba", 0x3AEF10, 0xF0

	.global gUnk_083AF000
gUnk_083AF000:
	.incbin "baserom.gba", 0x3AF000, 0x200

	.global gUnk_083AF200
gUnk_083AF200:
	.incbin "baserom.gba", 0x3AF200, 0x10

	.global gUnk_083AF210
gUnk_083AF210:
	.incbin "baserom.gba", 0x3AF210, 0x100

	.global gSpriteHopOffsets
gSpriteHopOffsets:
	.incbin "baserom.gba", 0x3AF310, 0x20

	.global gUnk_083AF330
gUnk_083AF330:
	.incbin "baserom.gba", 0x3AF330, 0x50

	.global gUnk_083AF380
gUnk_083AF380:
	.incbin "baserom.gba", 0x3AF380, 0x40

	.global gUnk_083AF3C0
gUnk_083AF3C0:
	.incbin "baserom.gba", 0x3AF3C0, 0x40

	.global gUnk_083AF400
gUnk_083AF400:
	.incbin "baserom.gba", 0x3AF400, 0x40

	.global gUnk_083AF440
gUnk_083AF440:
	.incbin "baserom.gba", 0x3AF440, 0x40

	.global gUnk_083AF480
gUnk_083AF480:
	.incbin "baserom.gba", 0x3AF480, 0x10

	.global gUnk_083AF490
gUnk_083AF490:
	.incbin "baserom.gba", 0x3AF490, 0x10

	.global gUnk_083AF4A0
gUnk_083AF4A0:
	.incbin "baserom.gba", 0x3AF4A0, 0x10

	.global gUnk_083AF4B0
gUnk_083AF4B0:
	.incbin "baserom.gba", 0x3AF4B0, 0x10

	.global gUnk_083AF4C0
gUnk_083AF4C0:
	.incbin "baserom.gba", 0x3AF4C0, 0x20

	.global gUnk_083AF4E0
gUnk_083AF4E0:
	.incbin "baserom.gba", 0x3AF4E0, 0x40

	.global gUnk_083AF520
gUnk_083AF520:
	.incbin "baserom.gba", 0x3AF520, 0x10

	.global gUnk_083AF530
gUnk_083AF530:
	.incbin "baserom.gba", 0x3AF530, 0x100

	.global gUnk_083AF630
gUnk_083AF630:
	.incbin "baserom.gba", 0x3AF630, 0x40

	.global gUnk_083AF670
gUnk_083AF670:
	.incbin "baserom.gba", 0x3AF670, 0x20

	.global gUnk_083AF690
gUnk_083AF690:
	.incbin "baserom.gba", 0x3AF690, 0x40

	.global gUnk_083AF6D0
gUnk_083AF6D0:
	.incbin "baserom.gba", 0x3AF6D0, 0x10

	.global gUnk_083AF6E0
gUnk_083AF6E0:
	.incbin "baserom.gba", 0x3AF6E0, 0x40

	.global gUnk_083AF720
gUnk_083AF720:
	.incbin "baserom.gba", 0x3AF720, 0x20

	.global gBattleSeqCommands
gBattleSeqCommands:
	.incbin "baserom.gba", 0x3AF740, 0x148

	.global gBattleSeqLegSoundSets
gBattleSeqLegSoundSets:
	.incbin "baserom.gba", 0x3AF888, 0x4

	.global gBattleSeqEffectGfx
gBattleSeqEffectGfx:
	.incbin "baserom.gba", 0x3AF88C, 0xC0

	.global gBattleSeqEffectSetPos
gBattleSeqEffectSetPos:
	.incbin "baserom.gba", 0x3AF94C, 0x10

	.global gBattleSeqEwramGfx
gBattleSeqEwramGfx:
	.incbin "baserom.gba", 0x3AF95C, 0x10

	.global gBattleSeqSpriteHandlers
gBattleSeqSpriteHandlers:
	.incbin "baserom.gba", 0x3AF96C, 0x140

	.global gBattleBg3ParallaxShift
gBattleBg3ParallaxShift:
	.incbin "baserom.gba", 0x3AFAAC, 0xC

	.global gBattleSeqWaveOffsets
gBattleSeqWaveOffsets:
	.incbin "baserom.gba", 0x3AFAB8, 0x40

	.global gLinkRobattleHandlers
gLinkRobattleHandlers:
	.incbin "baserom.gba", 0x3AFAF8, 0x180

	.global gLinkBattlefields
gLinkBattlefields:
	.incbin "baserom.gba", 0x3AFC78, 0x20

	.global gPrizeGameSlotSets
gPrizeGameSlotSets:
	.incbin "baserom.gba", 0x3AFC98, 0x60

	.global gPrizeGameBotPicks
gPrizeGameBotPicks:
	.incbin "baserom.gba", 0x3AFCF8, 0x10

	.global gUnk_083AFD08
gUnk_083AFD08:
	.incbin "baserom.gba", 0x3AFD08, 0x18C0

	.global gUnk_083B15C8
gUnk_083B15C8:
	.incbin "baserom.gba", 0x3B15C8, 0x2C0

	.global gUnk_083B1888
gUnk_083B1888:
	.incbin "baserom.gba", 0x3B1888, 0xB70

	.global gUnk_083B23F8
gUnk_083B23F8:
	.incbin "baserom.gba", 0x3B23F8, 0xB0

	.global gUnk_083B24A8
gUnk_083B24A8:
	.incbin "baserom.gba", 0x3B24A8, 0xDC

	.global gUnk_083B2584
gUnk_083B2584:
	.incbin "baserom.gba", 0x3B2584, 0x218

	.global gMessageStates
gMessageStates:
	.incbin "baserom.gba", 0x3B279C, 0x24

	.global gMessageEndModes
gMessageEndModes:
	.incbin "baserom.gba", 0x3B27C0, 0x14

	.global gMessageEndWaitCloseSteps
gMessageEndWaitCloseSteps:
	.incbin "baserom.gba", 0x3B27D4, 0x18

	.global gMessageEndCloseSteps
gMessageEndCloseSteps:
	.incbin "baserom.gba", 0x3B27EC, 0x18

	.global gMessageEndWaitKeepSteps
gMessageEndWaitKeepSteps:
	.incbin "baserom.gba", 0x3B2804, 0x4

	.global gMessageEndWaitClearSteps
gMessageEndWaitClearSteps:
	.incbin "baserom.gba", 0x3B2808, 0x8

	.global gMessageEndKeepSteps
gMessageEndKeepSteps:
	.incbin "baserom.gba", 0x3B2810, 0x4

	.global gUnk_083B2814
gUnk_083B2814:
	.incbin "baserom.gba", 0x3B2814, 0x38

	.global gUnk_083B284C
gUnk_083B284C:
	.incbin "baserom.gba", 0x3B284C, 0x18

	.global gUnk_083B2864
gUnk_083B2864:
	.incbin "baserom.gba", 0x3B2864, 0x8

	.global gUnk_083B286C
gUnk_083B286C:
	.incbin "baserom.gba", 0x3B286C, 0x100

	.global gUnk_083B296C
gUnk_083B296C:
	.incbin "baserom.gba", 0x3B296C, 0x4

	.global gUnk_083B2970
gUnk_083B2970:
	.incbin "baserom.gba", 0x3B2970, 0x2170

	.global gUnk_083B4AE0
gUnk_083B4AE0:

	.global gUnk_083B4AE0_s
gUnk_083B4AE0_s:
	.incbin "baserom.gba", 0x3B4AE0, 0x1A8

	.global gFontWidths
gFontWidths:
	.incbin "baserom.gba", 0x3B4C88, 0x200

	.global gAltFontWidths
gAltFontWidths:
	.incbin "baserom.gba", 0x3B4E88, 0x570

	.global gUnk_083B53F8
gUnk_083B53F8:
	.incbin "baserom.gba", 0x3B53F8, 0xB88

	.global gUnk_083B5F80
gUnk_083B5F80:
	.incbin "baserom.gba", 0x3B5F80, 0x90

	.global gUnk_083B6010
gUnk_083B6010:
	.incbin "baserom.gba", 0x3B6010, 0x148

	.global gUnk_083B6158
gUnk_083B6158:
	.incbin "baserom.gba", 0x3B6158, 0x2B8

	.global gMedalNames
gMedalNames:
	.incbin "baserom.gba", 0x3B6410, 0x15C

	.global gUnk_083B656C
gUnk_083B656C:
	.incbin "baserom.gba", 0x3B656C, 0x45C

	.global gUnk_083B69C8
gUnk_083B69C8:
	.incbin "baserom.gba", 0x3B69C8, 0x45C

	.global gUnk_083B6E24
gUnk_083B6E24:
	.incbin "baserom.gba", 0x3B6E24, 0xA4

	.global gUnk_083B6EC8
gUnk_083B6EC8:
	.incbin "baserom.gba", 0x3B6EC8, 0x1E4

	.global gUnk_083B70AC
gUnk_083B70AC:
	.incbin "baserom.gba", 0x3B70AC, 0x28C

	.global gUnk_083B7338
gUnk_083B7338:
	.incbin "baserom.gba", 0x3B7338, 0x8C8

	.global gUnk_083B7C00
gUnk_083B7C00:
	.incbin "baserom.gba", 0x3B7C00, 0xD4

	.global gUnk_083B7CD4
gUnk_083B7CD4:
	.incbin "baserom.gba", 0x3B7CD4, 0x138

	.global gUnk_083B7E0C
gUnk_083B7E0C:
	.incbin "baserom.gba", 0x3B7E0C, 0xB0

	.global gHelpCursorLayouts
gHelpCursorLayouts:
	.incbin "baserom.gba", 0x3B7EBC, 0x84

	.global gUnk_083B7F40
gUnk_083B7F40:
	.incbin "baserom.gba", 0x3B7F40, 0x230

	.global gUnk_083B8170
gUnk_083B8170:
	.incbin "baserom.gba", 0x3B8170, 0xEC

	.global gUnk_083B825C
gUnk_083B825C:
	.incbin "baserom.gba", 0x3B825C, 0x20

	.global gUnk_083B827C
gUnk_083B827C:
	.incbin "baserom.gba", 0x3B827C, 0x225C

	.global gUnk_083BA4D8
gUnk_083BA4D8:
	.incbin "baserom.gba", 0x3BA4D8, 0x14F4

	.global gUnk_083BB9CC
gUnk_083BB9CC:
	.incbin "baserom.gba", 0x3BB9CC, 0x1EB8

	.global gUnk_083BD884
gUnk_083BD884:
	.incbin "baserom.gba", 0x3BD884, 0xB60

	.global gUnk_083BE3E4
gUnk_083BE3E4:
	.incbin "baserom.gba", 0x3BE3E4, 0x304

	.global gUnk_083BE6E8
gUnk_083BE6E8:
	.incbin "baserom.gba", 0x3BE6E8, 0x244

	.global gUnk_083BE92C
gUnk_083BE92C:
	.incbin "baserom.gba", 0x3BE92C, 0x50

	.global gUnk_083BE97C
gUnk_083BE97C:
	.incbin "baserom.gba", 0x3BE97C, 0x6C

	.global gUnk_083BE9E8
gUnk_083BE9E8:
	.incbin "baserom.gba", 0x3BE9E8, 0x2C

	.global gUnk_083BEA14
gUnk_083BEA14:
	.incbin "baserom.gba", 0x3BEA14, 0x7C

	.global gUnk_083BEA90
gUnk_083BEA90:
	.incbin "baserom.gba", 0x3BEA90, 0x600

	.global gUnk_083BF090
gUnk_083BF090:
	.incbin "baserom.gba", 0x3BF090, 0x2970

	.global gUnk_083C1A00
gUnk_083C1A00:
	.incbin "baserom.gba", 0x3C1A00, 0x11BC

	.global gUnk_083C2BBC
gUnk_083C2BBC:
	.incbin "baserom.gba", 0x3C2BBC, 0xDC8

	.global gUnk_083C3984
gUnk_083C3984:
	.incbin "baserom.gba", 0x3C3984, 0x180

	.global gBattlefieldParams
gBattlefieldParams:
	.incbin "baserom.gba", 0x3C3B04, 0x58

	.global gUnk_083C3B5C
gUnk_083C3B5C:
	.incbin "baserom.gba", 0x3C3B5C, 0x3DC

	.global gUnk_083C3F38
gUnk_083C3F38:
	.incbin "baserom.gba", 0x3C3F38, 0x180

	.global gUnk_083C40B8
gUnk_083C40B8:
	.incbin "baserom.gba", 0x3C40B8, 0xB

	.global gUnk_083C40C3
gUnk_083C40C3:
	.incbin "baserom.gba", 0x3C40C3, 0x5A9

	.global gUnk_083C466C
gUnk_083C466C:
	.incbin "baserom.gba", 0x3C466C, 0x3A4

	.global gBattleMenuTexts
gBattleMenuTexts:
	.incbin "baserom.gba", 0x3C4A10, 0x200

	.global gTerrainMoveDelays
gTerrainMoveDelays:
	.incbin "baserom.gba", 0x3C4C10, 0x50

	.global gUnk_083C4C60
gUnk_083C4C60:
	.incbin "baserom.gba", 0x3C4C60, 0x28

	.global gUnk_083C4C88
gUnk_083C4C88:
	.incbin "baserom.gba", 0x3C4C88, 0x193C

	.global gUnk_083C65C4
gUnk_083C65C4:
	.incbin "baserom.gba", 0x3C65C4, 0x564

	.global gUnk_083C6B28
gUnk_083C6B28:
	.incbin "baserom.gba", 0x3C6B28, 0x210

	.global gUnk_083C6D38
gUnk_083C6D38:
	.incbin "baserom.gba", 0x3C6D38, 0xB0

	.global gPartKindNames
gPartKindNames:
	.incbin "baserom.gba", 0x3C6DE8, 0x10

	.global gUnk_083C6DF8
gUnk_083C6DF8:
	.incbin "baserom.gba", 0x3C6DF8, 0x3E00

	.global gUnk_083CABF8
gUnk_083CABF8:
	.incbin "baserom.gba", 0x3CABF8, 0x33EC

	.global gBattleSeqScripts
gBattleSeqScripts:
	.incbin "baserom.gba", 0x3CDFE4, 0x210

	.global gBattleSeqOperandCounts
gBattleSeqOperandCounts:
	.incbin "baserom.gba", 0x3CE1F4, 0x28C

	.global gUnk_083CE480
gUnk_083CE480:
	.incbin "baserom.gba", 0x3CE480, 0x7F4

	.global gBattleSeqTileAnims
gBattleSeqTileAnims:
	.incbin "baserom.gba", 0x3CEC74, 0x94

	.global gUnk_083CED08
gUnk_083CED08:
	.incbin "baserom.gba", 0x3CED08, 0x80

	.global gUnk_083CED88
gUnk_083CED88:
	.incbin "baserom.gba", 0x3CED88, 0x80

	.global gUnk_083CEE08
gUnk_083CEE08:
	.incbin "baserom.gba", 0x3CEE08, 0x80

	.global gUnk_083CEE88
gUnk_083CEE88:
	.incbin "baserom.gba", 0x3CEE88, 0x40

	.global gUnk_083CEEC8
gUnk_083CEEC8:
	.incbin "baserom.gba", 0x3CEEC8, 0x40

	.global gUnk_083CEF08
gUnk_083CEF08:
	.incbin "baserom.gba", 0x3CEF08, 0x40

	.global gUnk_083CEF48
gUnk_083CEF48:
	.incbin "baserom.gba", 0x3CEF48, 0x40

	.global gUnk_083CEF88
gUnk_083CEF88:
	.incbin "baserom.gba", 0x3CEF88, 0x40

	.global gUnk_083CEFC8
gUnk_083CEFC8:
	.incbin "baserom.gba", 0x3CEFC8, 0x40

	.global gUnk_083CF008
gUnk_083CF008:
	.incbin "baserom.gba", 0x3CF008, 0x40

	.global gUnk_083CF048
gUnk_083CF048:
	.incbin "baserom.gba", 0x3CF048, 0x40

	.global gUnk_083CF088
gUnk_083CF088:
	.incbin "baserom.gba", 0x3CF088, 0x40

	.global gUnk_083CF0C8
gUnk_083CF0C8:
	.incbin "baserom.gba", 0x3CF0C8, 0x40

	.global gUnk_083CF108
gUnk_083CF108:
	.incbin "baserom.gba", 0x3CF108, 0x40

	.global gUnk_083CF148
gUnk_083CF148:
	.incbin "baserom.gba", 0x3CF148, 0x268

	.global gLinkMessages
gLinkMessages:
	.incbin "baserom.gba", 0x3CF3B0, 0x2848

	.global gUnk_083D1BF8
gUnk_083D1BF8:
	.incbin "baserom.gba", 0x3D1BF8, 0xC8

	.global gUnk_083D1CC0
gUnk_083D1CC0:
	.incbin "baserom.gba", 0x3D1CC0, 0xEC

	.global gUnk_083D1DAC
gUnk_083D1DAC:
	.incbin "baserom.gba", 0x3D1DAC, 0xEC

	.global gUnk_083D1E98
gUnk_083D1E98:
	.incbin "baserom.gba", 0x3D1E98, 0xEC

	.global gUnk_083D1F84
gUnk_083D1F84:
	.incbin "baserom.gba", 0x3D1F84, 0x28

	.global gFieldSubStates
gFieldSubStates:
	.incbin "baserom.gba", 0x3D1FAC, 0x100

	.global gMapScriptCommands
gMapScriptCommands:
	.incbin "baserom.gba", 0x3D20AC, 0x400

	.global gUnk_083D24AC
gUnk_083D24AC:
	.incbin "baserom.gba", 0x3D24AC, 0x4

	.global gMapScriptUpdates
gMapScriptUpdates:
	.incbin "baserom.gba", 0x3D24B0, 0x400

	.global gUnk_083D28B0
gUnk_083D28B0:
	.incbin "baserom.gba", 0x3D28B0, 0x10

	.global gUnk_083D28C0
gUnk_083D28C0:
	.incbin "baserom.gba", 0x3D28C0, 0x3

	.global gUnk_083D28C3
gUnk_083D28C3:
	.incbin "baserom.gba", 0x3D28C3, 0x40

	.global gUnk_083D2903
gUnk_083D2903:
	.incbin "baserom.gba", 0x3D2903, 0x5

	.global gUnk_083D2908
gUnk_083D2908:
	.incbin "baserom.gba", 0x3D2908, 0x10

	.global gUnk_083D2918
gUnk_083D2918:
	.incbin "baserom.gba", 0x3D2918, 0x80

	.global gUnk_083D2998
gUnk_083D2998:
	.incbin "baserom.gba", 0x3D2998, 0xE

	.global gUnk_083D29A6
gUnk_083D29A6:
	.incbin "baserom.gba", 0x3D29A6, 0x10

	.global gUnk_083D29B6
gUnk_083D29B6:
	.incbin "baserom.gba", 0x3D29B6, 0x30

	.global gUnk_083D29E6
gUnk_083D29E6:
	.incbin "baserom.gba", 0x3D29E6, 0x5

	.global gUnk_083D29EB
gUnk_083D29EB:
	.incbin "baserom.gba", 0x3D29EB, 0xC0

	.global gUnk_083D2AAB
gUnk_083D2AAB:
	.incbin "baserom.gba", 0x3D2AAB, 0x9

	.global gUnk_083D2AB4
gUnk_083D2AB4:
	.incbin "baserom.gba", 0x3D2AB4, 0x24

	.global gUnk_083D2AD8
gUnk_083D2AD8:
	.incbin "baserom.gba", 0x3D2AD8, 0x1

	.global gUnk_083D2AD9
gUnk_083D2AD9:
	.incbin "baserom.gba", 0x3D2AD9, 0x4

	.global gUnk_083D2ADD
gUnk_083D2ADD:
	.incbin "baserom.gba", 0x3D2ADD, 0xB0

	.global gUnk_083D2B8D
gUnk_083D2B8D:
	.incbin "baserom.gba", 0x3D2B8D, 0xB0

	.global gUnk_083D2C3D
gUnk_083D2C3D:
	.incbin "baserom.gba", 0x3D2C3D, 0x173

	.global gUnk_083D2DB0
gUnk_083D2DB0:
	.incbin "baserom.gba", 0x3D2DB0, 0x2FD4

	.global gUnk_083D5D84
gUnk_083D5D84:
	.incbin "baserom.gba", 0x3D5D84, 0x84

	.global gVehicleMenuStates
gVehicleMenuStates:
	.incbin "baserom.gba", 0x3D5E08, 0x124

	.global gVehicleMenuCursorRows
gVehicleMenuCursorRows:
	.incbin "baserom.gba", 0x3D5F2C, 0x4

	.global gVehicleMenuWindowTilemap
gVehicleMenuWindowTilemap:
	.incbin "baserom.gba", 0x3D5F30, 0x140

	.global gFieldDebugEventValues
gFieldDebugEventValues:
	.incbin "baserom.gba", 0x3D6070, 0xC

	.global gFieldDebugMessageValues
gFieldDebugMessageValues:
	.incbin "baserom.gba", 0x3D607C, 0xC

	.global gFieldDebugSoundValues
gFieldDebugSoundValues:
	.incbin "baserom.gba", 0x3D6088, 0x54

	.global gFieldDebugPageValues
gFieldDebugPageValues:
	.incbin "baserom.gba", 0x3D60DC, 0x8C4

	.global gJumpArcTable
gJumpArcTable:
	.incbin "baserom.gba", 0x3D69A0, 0x200

	.global gUnk_083D6BA0
gUnk_083D6BA0:
	.incbin "baserom.gba", 0x3D6BA0, 0x300

	.global gUnk_083D6EA0
gUnk_083D6EA0:
	.incbin "baserom.gba", 0x3D6EA0, 0x400

	.global gUnk_083D72A0
gUnk_083D72A0:
	.incbin "baserom.gba", 0x3D72A0, 0x20954

	.global gSpriteAnimScripts
gSpriteAnimScripts:
	.incbin "baserom.gba", 0x3F7BF4, 0x400

	.global gRandomBytes
gRandomBytes:
	.incbin "baserom.gba", 0x3F7FF4, 0x100

	.global gUnk_083F80F4
gUnk_083F80F4:
	.incbin "baserom.gba", 0x3F80F4, 0x540

	.global gUnk_083F8634
gUnk_083F8634:
	.incbin "baserom.gba", 0x3F8634, 0x540

	.global gAreaMapSizes
gAreaMapSizes:
	.incbin "baserom.gba", 0x3F8B74, 0x180

	.global gUnk_083F8CF4
gUnk_083F8CF4:
	.incbin "baserom.gba", 0x3F8CF4, 0x300

	.global gUnk_083F8FF4
gUnk_083F8FF4:
	.incbin "baserom.gba", 0x3F8FF4, 0x300

	.global gUnk_083F92F4
gUnk_083F92F4:
	.incbin "baserom.gba", 0x3F92F4, 0x900

	.global gUnk_083F9BF4
gUnk_083F9BF4:
	.incbin "baserom.gba", 0x3F9BF4, 0xA9B4

	.global gUnk_084045A8
gUnk_084045A8:
	.incbin "baserom.gba", 0x4045A8, 0x514C

	.global gUnk_084096F4
gUnk_084096F4:
	.incbin "baserom.gba", 0x4096F4, 0x6400

	.global gUnk_0840FAF4
gUnk_0840FAF4:
	.incbin "baserom.gba", 0x40FAF4, 0x2260

	.global gRoomExitMessages
gRoomExitMessages:
	.incbin "baserom.gba", 0x411D54, 0x13C0

	.global gAreaWarps
gAreaWarps:
	.incbin "baserom.gba", 0x413114, 0x400

	.global gUnk_08413514
gUnk_08413514:
	.incbin "baserom.gba", 0x413514, 0xE80

	.global gUnk_08414394
gUnk_08414394:
	.incbin "baserom.gba", 0x414394, 0x5D4

	.global gTextTable
gTextTable:
	.incbin "baserom.gba", 0x414968, 0x69AF4

	.global gTextBankTables
gTextBankTables:
	.incbin "baserom.gba", 0x47E45C, 0x468

	.global gUnk_0847E8C4
gUnk_0847E8C4:
	.incbin "baserom.gba", 0x47E8C4, 0x84

	.global gUnk_0847E948
gUnk_0847E948:
	.incbin "baserom.gba", 0x47E948, 0x238

	.global gUnk_0847EB80
gUnk_0847EB80:
	.incbin "baserom.gba", 0x47EB80, 0xC0

	.global gUnk_0847EC40
gUnk_0847EC40:
	.incbin "baserom.gba", 0x47EC40, 0x80

	.global gUnk_0847ECC0
gUnk_0847ECC0:
	.incbin "baserom.gba", 0x47ECC0, 0x1340
