	.syntax unified

	thumb_func_start sub_08052714
	.global sub_08052714
sub_08052714: @ 0x08052714
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08052730 @ =0x030057E0
	ldr r2, _08052734 @ =0x00000C4A
	adds r1, r1, r2
	ldrh r1, [r1]
	subs r0, r0, r1
	cmp r0, #0
	bge _08052728
	adds r0, #0xf
_08052728:
	asrs r0, r0, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bx lr
	.align 2, 0
_08052730: .4byte 0x030057E0
_08052734: .4byte 0x00000C4A
	.syntax divided
