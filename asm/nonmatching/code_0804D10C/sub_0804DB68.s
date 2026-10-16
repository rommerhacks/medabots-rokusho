	.syntax unified

	thumb_func_start sub_0804DB68
sub_0804DB68: @ 0x0804DB68
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0804DB7C @ =0x030057E0
	ldr r2, _0804DB80 @ =0x00000CA4
	adds r1, r1, r2
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	bx lr
	.align 2, 0
_0804DB7C: .4byte 0x030057E0
_0804DB80: .4byte 0x00000CA4
	.syntax divided
