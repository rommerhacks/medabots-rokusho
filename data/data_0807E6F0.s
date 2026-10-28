	.section .rodata

	.global gData_0807E6F0
gData_0807E6F0:

	.global gIntrTableTemplate
gIntrTableTemplate:
	.incbin "baserom.gba", 0x7E6F0, 0x38

	.global gRngTable
gRngTable:
	.incbin "baserom.gba", 0x7E728, 0x54

	.global gPoseAnimIds
gPoseAnimIds:
	.incbin "baserom.gba", 0x7E77C, 0x524

	.global gHeadPartLayerTemplate
gHeadPartLayerTemplate:
	.incbin "baserom.gba", 0x7ECA0, 0x18

	.global gLeftArmPartLayerTemplate
gLeftArmPartLayerTemplate:
	.incbin "baserom.gba", 0x7ECB8, 0x18

	.global gRightArmPartLayerTemplate
gRightArmPartLayerTemplate:
	.incbin "baserom.gba", 0x7ECD0, 0x18

	.global gLegPartLayerTemplate
gLegPartLayerTemplate:
	.incbin "baserom.gba", 0x7ECE8, 0x18

	.global gHeadPartSpriteNodes
gHeadPartSpriteNodes:
	.incbin "baserom.gba", 0x7ED00, 0x7A0

	.global gRightArmPartSpriteNodes
gRightArmPartSpriteNodes:
	.incbin "baserom.gba", 0x7F4A0, 0x7A0

	.global gLeftArmPartSpriteNodes
gLeftArmPartSpriteNodes:
	.incbin "baserom.gba", 0x7FC40, 0x3C0
