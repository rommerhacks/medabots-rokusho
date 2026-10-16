	.syntax unified

	thumb_func_start sub_0803D71C
sub_0803D71C: @ 0x0803D71C
	push {lr}
	bl rng_next_080424B8
	ldr r2, _0803D740 @ =0x03001800
	ldr r3, _0803D744 @ =0x083AFC78
	movs r1, #0x1f
	ands r1, r0
	adds r1, r1, r3
	ldrb r0, [r1]
	adds r2, #0x38
	strb r0, [r2]
	ldr r1, _0803D748 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0803D740: .4byte 0x03001800
_0803D744: .4byte 0x083AFC78
_0803D748: .4byte 0x0300137C
	.syntax divided
