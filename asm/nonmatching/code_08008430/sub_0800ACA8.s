	.syntax unified

	thumb_func_start sub_0800ACA8
sub_0800ACA8: @ 0x0800ACA8
	ldr r3, _0800ACEC @ =0x03002C30
	adds r1, r3, #0
	adds r1, #0xc0
	movs r2, #0
	ldr r0, _0800ACF0 @ =0x0000C804
	strh r0, [r1]
	ldr r1, _0800ACF4 @ =0x03000BE0
	ldr r0, _0800ACF8 @ =0x03000440
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #9]
	lsls r0, r0, #4
	adds r0, #0x30
	adds r1, r3, #0
	adds r1, #0xc2
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x30
	strh r0, [r1]
	adds r1, #2
	ldr r0, _0800ACFC @ =0x00000305
	strh r0, [r1]
	adds r1, #4
	movs r0, #0xe
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xdc
	strb r2, [r0]
	adds r1, #1
	movs r0, #0x40
	strb r0, [r1]
	bx lr
	.align 2, 0
_0800ACEC: .4byte 0x03002C30
_0800ACF0: .4byte 0x0000C804
_0800ACF4: .4byte 0x03000BE0
_0800ACF8: .4byte 0x03000440
_0800ACFC: .4byte 0x00000305
	.syntax divided
