	.syntax unified

	thumb_func_start sub_08002574
sub_08002574: @ 0x08002574
	ldr r0, _080025A4 @ =0x04000050
	movs r1, #0
	strh r1, [r0]
	adds r0, #4
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0x93
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #0xa
	ldr r0, _080025A8 @ =0x00005E09
	strh r0, [r1]
	ldr r0, _080025AC @ =0x03000440
	adds r0, #0x85
	movs r1, #1
	strb r1, [r0]
	ldr r1, _080025B0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
_080025A4: .4byte 0x04000050
_080025A8: .4byte 0x00005E09
_080025AC: .4byte 0x03000440
_080025B0: .4byte 0x0300137C
	.syntax divided
