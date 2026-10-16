	.syntax unified

	thumb_func_start stream_read_and_shift_u32
stream_read_and_shift_u32: @ 0x08072AA8
	push {r4, lr}
	adds r4, r0, #0
	bl sub_08072708
	ldr r1, [r4, #0x14]
	str r1, [r4, #0x20]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
