	.syntax unified

	thumb_func_start sub_08052A2C
	.global sub_08052A2C
sub_08052A2C: @ 0x08052A2C
	ldr r2, _08052A4C @ =0x03004C30
	ldrh r1, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, r1
	strh r1, [r2]
	ldr r2, _08052A50 @ =0x0300057C
	ldrh r1, [r2]
	adds r1, r0, r1
	strh r1, [r2]
	ldr r2, _08052A54 @ =0x03001C04
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_08052A4C: .4byte 0x03004C30
_08052A50: .4byte 0x0300057C
_08052A54: .4byte 0x03001C04
	.syntax divided
