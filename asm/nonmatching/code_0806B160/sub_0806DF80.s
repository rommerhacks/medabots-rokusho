	.syntax unified

	thumb_func_start sub_0806DF80
sub_0806DF80: @ 0x0806DF80
	lsls r1, r1, #0x18
	ldr r2, _0806DFA0 @ =0x03002C30
	lsrs r1, r1, #0x12
	adds r3, r1, r2
	adds r1, r3, #0
	adds r1, #0x20
	movs r2, #0
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrh r0, [r3, #6]
	strh r0, [r3, #0x30]
	strh r2, [r3, #0x1a]
	bx lr
	.align 2, 0
_0806DFA0: .4byte 0x03002C30
	.syntax divided
