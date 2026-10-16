	.syntax unified

	thumb_func_start sub_080355C4
	.global sub_080355C4
sub_080355C4: @ 0x080355C4
	ldr r3, _080355E8 @ =0x03001800
	ldr r1, _080355EC @ =0x03000590
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0xe0
	ldrb r1, [r1]
	subs r1, #1
	adds r2, r3, #0
	adds r2, #0x88
	strb r1, [r2]
	adds r0, #0xe1
	ldrb r0, [r0]
	subs r0, #1
	adds r3, #0x8b
	strb r0, [r3]
	bx lr
	.align 2, 0
_080355E8: .4byte 0x03001800
_080355EC: .4byte 0x03000590
	.syntax divided
