	.syntax unified

	thumb_func_start sub_08052AF8
	.global sub_08052AF8
sub_08052AF8: @ 0x08052AF8
	ldr r2, _08052B18 @ =0x03004C30
	ldrh r1, [r2, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, r1
	strh r1, [r2, #2]
	ldr r2, _08052B1C @ =0x0300057C
	ldrh r1, [r2, #2]
	adds r1, r0, r1
	strh r1, [r2, #2]
	ldr r2, _08052B20 @ =0x03001C04
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	bx lr
	.align 2, 0
_08052B18: .4byte 0x03004C30
_08052B1C: .4byte 0x0300057C
_08052B20: .4byte 0x03001C04
	.syntax divided
