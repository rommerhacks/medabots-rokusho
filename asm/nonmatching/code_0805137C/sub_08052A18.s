	.syntax unified

	thumb_func_start sub_08052A18
	.global sub_08052A18
sub_08052A18: @ 0x08052A18
	ldr r0, _08052A24 @ =0x030057E0
	ldr r1, _08052A28 @ =0x00000C4A
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_08052A24: .4byte 0x030057E0
_08052A28: .4byte 0x00000C4A
	.syntax divided
