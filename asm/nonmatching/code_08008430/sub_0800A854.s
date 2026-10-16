	.syntax unified

	thumb_func_start sub_0800A854
	.global sub_0800A854
sub_0800A854: @ 0x0800A854
	ldr r3, _0800A890 @ =0x03002C30
	adds r1, r3, #0
	adds r1, #0xc0
	movs r2, #0
	ldr r0, _0800A894 @ =0x0000C804
	strh r0, [r1]
	adds r1, #2
	movs r0, #8
	strh r0, [r1]
	ldr r0, _0800A898 @ =0x03000440
	adds r0, #0x46
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, #0x38
	adds r1, #2
	strh r0, [r1]
	adds r1, #2
	ldr r0, _0800A89C @ =0x00000307
	strh r0, [r1]
	adds r1, #4
	movs r0, #0xe
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xdc
	strb r2, [r0]
	adds r1, #1
	movs r0, #0x41
	strb r0, [r1]
	bx lr
	.align 2, 0
_0800A890: .4byte 0x03002C30
_0800A894: .4byte 0x0000C804
_0800A898: .4byte 0x03000440
_0800A89C: .4byte 0x00000307
	.syntax divided
