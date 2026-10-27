	.section .rodata

	.global gData_08080000
gData_08080000:
	.incbin "baserom.gba", 0x80000, 0x3E0

	.global gLegPartSpriteNodes
gLegPartSpriteNodes:
	.incbin "baserom.gba", 0x803E0, 0xF40

	.global gMirroredPartNode
gMirroredPartNode:
	.incbin "baserom.gba", 0x81320, 0x29CE0
