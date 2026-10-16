	.syntax unified

	thumb_func_start sub_08033154
sub_08033154: @ 0x08033154
	ldr r3, _0803317C @ =0x03000590
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #3
	lsls r0, r0, #8
	adds r2, r2, r0
	adds r2, r2, r3
	ldr r0, _08033180 @ =0x03001800
	adds r1, r0, #0
	adds r1, #0x5e
	ldrb r1, [r1]
	adds r3, r2, #0
	adds r3, #0x56
	strb r1, [r3]
	adds r0, #0x5f
	ldrb r0, [r0]
	adds r2, #0x57
	strb r0, [r2]
	bx lr
	.align 2, 0
_0803317C: .4byte 0x03000590
_08033180: .4byte 0x03001800
	.syntax divided
