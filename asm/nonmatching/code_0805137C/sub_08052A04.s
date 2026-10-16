	.syntax unified

	thumb_func_start sub_08052A04
	.global sub_08052A04
sub_08052A04: @ 0x08052A04
	ldr r0, _08052A10 @ =0x030057E0
	ldr r1, _08052A14 @ =0x00000C48
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_08052A10: .4byte 0x030057E0
_08052A14: .4byte 0x00000C48
	.syntax divided
