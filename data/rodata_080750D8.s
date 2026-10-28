	.section .rodata

	.global gData_080750D8
gData_080750D8:
	.incbin "baserom.gba", 0x750D8, 0x8

	.global gSineTableQ14
gSineTableQ14:
	.incbin "baserom.gba", 0x750E0, 0x6FC0

	.global gBombGameObjPalettes
gBombGameObjPalettes:
	.incbin "baserom.gba", 0x7C0A0, 0x1C0

	.global gRacePointerObjPalette
gRacePointerObjPalette:
	.incbin "baserom.gba", 0x7C260, 0x20

	.global gRaceSignalObjPalettes
gRaceSignalObjPalettes:
	.incbin "baserom.gba", 0x7C280, 0x20

	.global gRacePlaceObjPalette
gRacePlaceObjPalette:
	.incbin "baserom.gba", 0x7C2A0, 0x20

	.global gRaceWinnerObjPalette
gRaceWinnerObjPalette:
	.incbin "baserom.gba", 0x7C2C0, 0x40

	.global gRaceRunnerObjPalette
gRaceRunnerObjPalette:
	.incbin "baserom.gba", 0x7C300, 0x20

	.global gTitleObjPalettes
gTitleObjPalettes:
	.incbin "baserom.gba", 0x7C320, 0x220

	.global gWeeklyObjPalettes
gWeeklyObjPalettes:
	.incbin "baserom.gba", 0x7C540, 0x200
