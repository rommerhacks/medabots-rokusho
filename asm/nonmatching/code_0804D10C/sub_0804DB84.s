	.syntax unified

	thumb_func_start sub_0804DB84
	.global sub_0804DB84
sub_0804DB84: @ 0x0804DB84
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _0804DB9C @ =0x030057E0
	ldr r3, _0804DBA0 @ =0x00000CA4
	adds r2, r2, r3
	adds r0, r0, r2
	adds r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_0804DB9C: .4byte 0x030057E0
_0804DBA0: .4byte 0x00000CA4
	.syntax divided
