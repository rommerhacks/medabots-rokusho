	.syntax unified

	thumb_func_start sub_080191A4
sub_080191A4: @ 0x080191A4
	ldr r2, _080191BC @ =0x03000590
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r2, r0, #0
	adds r2, #0xbb
	ldrb r0, [r2]
	subs r0, r0, r1
	cmp r0, #0
	bge _080191B8
	movs r0, #0
_080191B8:
	strb r0, [r2]
	bx lr
	.align 2, 0
_080191BC: .4byte 0x03000590
	.syntax divided
