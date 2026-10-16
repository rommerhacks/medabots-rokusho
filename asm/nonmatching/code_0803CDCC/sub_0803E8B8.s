	.syntax unified

	thumb_func_start sub_0803E8B8
sub_0803E8B8: @ 0x0803E8B8
	push {r4, lr}
	bl rng_next_080424B8
	movs r1, #0xf
	ands r0, r1
	movs r3, #0
	ldr r4, _0803E8E4 @ =0x0300199A
	ldr r2, _0803E8E8 @ =0x083AFC98
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r2, r1, r2
_0803E8D0:
	adds r1, r3, r4
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, #1
	adds r3, #1
	cmp r3, #5
	bls _0803E8D0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803E8E4: .4byte 0x0300199A
_0803E8E8: .4byte 0x083AFC98
	.syntax divided
