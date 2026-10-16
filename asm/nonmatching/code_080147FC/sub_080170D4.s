	.syntax unified

	thumb_func_start sub_080170D4
	.global sub_080170D4
sub_080170D4: @ 0x080170D4
	ldr r2, _080170F0 @ =0x03000590
	ldr r1, _080170F4 @ =0x03001800
	adds r0, r1, #0
	adds r0, #0x80
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r0, #0xdd
	ldrb r2, [r0]
	cmp r2, #3
	bhi _080170F8
	movs r2, #0
	b _080170FA
	.align 2, 0
_080170F0: .4byte 0x03000590
_080170F4: .4byte 0x03001800
_080170F8:
	subs r2, #5
_080170FA:
	adds r0, r1, #0
	adds r0, #0x82
	strb r2, [r0]
	bx lr
	.align 2, 0
	.syntax divided
