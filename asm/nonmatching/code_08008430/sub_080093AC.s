	.syntax unified

	thumb_func_start sub_080093AC
sub_080093AC: @ 0x080093AC
	push {lr}
	ldr r0, _080093D0 @ =0x03000440
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	ldr r1, _080093D4 @ =0x03000BE0
	adds r0, r0, r1
	ldr r1, _080093D8 @ =0x02023000
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	ldr r1, _080093DC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080093D0: .4byte 0x03000440
_080093D4: .4byte 0x03000BE0
_080093D8: .4byte 0x02023000
_080093DC: .4byte 0x0300137C
	.syntax divided
