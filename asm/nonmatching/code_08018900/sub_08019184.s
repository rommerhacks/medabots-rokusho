	.syntax unified

	thumb_func_start sub_08019184
sub_08019184: @ 0x08019184
	adds r2, r1, #0
	ldr r1, _080191A0 @ =0x03000590
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0xbb
	ldrb r0, [r1]
	adds r2, r2, r0
	cmp r2, #0xff
	bls _0801919A
	movs r2, #0xff
_0801919A:
	strb r2, [r1]
	bx lr
	.align 2, 0
_080191A0: .4byte 0x03000590
	.syntax divided
