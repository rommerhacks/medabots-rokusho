	.section .rodata

	.global gData_08480000
gData_08480000:
	.incbin "baserom.gba", 0x480000, 0x110000
