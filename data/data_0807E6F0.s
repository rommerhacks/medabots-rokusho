	.section .rodata

@ data at 0x7E6F0

	.global gData_0807E6F0
gData_0807E6F0:

	.global gIntrTableTemplate
gIntrTableTemplate:
	.4byte serial_multiplayer_transfer_handler
	.4byte vblank_irq
	.4byte nullsub_08000840
	.4byte hblank_irq
	.4byte nullsub_08000840
	.4byte dma1_irq_sound
	.4byte dma2_irq_sound
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840
	.4byte nullsub_08000840

	.global gRngTable
gRngTable:
	.incbin "baserom.gba", 0x7E728, 0x54

	.global gUnk_0807E77C
gUnk_0807E77C:
	.incbin "baserom.gba", 0x7E77C, 0x524

	.global gUnk_0807ECA0
gUnk_0807ECA0:
	.incbin "baserom.gba", 0x7ECA0, 0x18

	.global gUnk_0807ECB8
gUnk_0807ECB8:
	.incbin "baserom.gba", 0x7ECB8, 0x18

	.global gUnk_0807ECD0
gUnk_0807ECD0:
	.incbin "baserom.gba", 0x7ECD0, 0x18

	.global gUnk_0807ECE8
gUnk_0807ECE8:
	.incbin "baserom.gba", 0x7ECE8, 0x18

	.global gUnk_0807ED00
gUnk_0807ED00:
	.incbin "baserom.gba", 0x7ED00, 0x7A0

	.global gUnk_0807F4A0
gUnk_0807F4A0:
	.incbin "baserom.gba", 0x7F4A0, 0x7A0

	.global gUnk_0807FC40
gUnk_0807FC40:
	.incbin "baserom.gba", 0x7FC40, 0x3C0
