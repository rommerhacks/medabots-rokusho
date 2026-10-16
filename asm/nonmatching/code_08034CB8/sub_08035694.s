	.syntax unified

	thumb_func_start sub_08035694
	.global sub_08035694
sub_08035694: @ 0x08035694
	ldr r1, _080356B0 @ =0x03002C30
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r0]
	movs r1, #0x40
	strb r1, [r0, #8]
	strb r1, [r0, #9]
	bx lr
	.align 2, 0
_080356B0: .4byte 0x03002C30
	.syntax divided
