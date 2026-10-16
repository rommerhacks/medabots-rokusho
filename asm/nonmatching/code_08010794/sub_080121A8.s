	.syntax unified

	thumb_func_start sub_080121A8
	.global sub_080121A8
sub_080121A8: @ 0x080121A8
	push {lr}
	ldr r1, _080121C4 @ =0x03001800
	adds r0, r1, #0
	adds r0, #0x38
	ldrb r0, [r0]
	lsls r0, r0, #3
	ldr r2, _080121C8 @ =0x083C3B04
	adds r0, r0, r2
	adds r1, #0x39
	movs r2, #8
	bl memcpy_bytes_0803F63C
	pop {r0}
	bx r0
	.align 2, 0
_080121C4: .4byte 0x03001800
_080121C8: .4byte 0x083C3B04
	.syntax divided
