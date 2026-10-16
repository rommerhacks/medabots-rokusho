	.syntax unified

	thumb_func_start sub_080493D4
	.global sub_080493D4
sub_080493D4: @ 0x080493D4
	lsls r0, r0, #0x18
	ldr r2, _080493F0 @ =0x03002C30
	lsrs r0, r0, #0x12
	adds r3, r0, r2
	adds r0, r3, #0
	adds r0, #0x24
	movs r2, #0
	strb r1, [r0]
	subs r0, #1
	strb r2, [r0]
	subs r0, #1
	strb r2, [r0]
	bx lr
	.align 2, 0
_080493F0: .4byte 0x03002C30
	.syntax divided
