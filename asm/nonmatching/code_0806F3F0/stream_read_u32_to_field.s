	.syntax unified

	thumb_func_start stream_read_u32_to_field
stream_read_u32_to_field: @ 0x08072A98
	push {r4, lr}
	adds r4, r0, #0
	bl sub_08072708
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
