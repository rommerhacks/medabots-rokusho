	.syntax unified

	thumb_func_start sub_080165B0
	.global sub_080165B0
sub_080165B0: @ 0x080165B0
	ldr r2, _080165C4 @ =0x0300137C
	ldr r1, _080165C8 @ =0x083AD39A
	ldr r0, _080165CC @ =0x03001800
	adds r0, #0x81
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	str r0, [r2]
	bx lr
	.align 2, 0
_080165C4: .4byte 0x0300137C
_080165C8: .4byte 0x083AD39A
_080165CC: .4byte 0x03001800
	.syntax divided
