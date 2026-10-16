	.section .rodata

	.global gData_08080000
gData_08080000:
	.incbin "baserom.gba", 0x80000, 0x2B000
