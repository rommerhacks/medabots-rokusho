	.section .rodata

	.global gData_08080000
gData_08080000:
	.incbin "baserom.gba", 0x80000, 0x3E0

	.global gUnk_080803E0
gUnk_080803E0:
	.incbin "baserom.gba", 0x803E0, 0x2AC20
