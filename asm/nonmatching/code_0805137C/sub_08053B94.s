	.syntax unified

	thumb_func_start sub_08053B94
sub_08053B94: @ 0x08053B94
	push {lr}
	sub sp, #0x14
	add r3, sp, #0xc
	str r3, [sp]
	add r3, sp, #0x10
	str r3, [sp, #4]
	add r3, sp, #8
	bl compute_3d_transform_vectors
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl sub_08053BB4
	add sp, #0x14
	pop {r0}
	bx r0
	.syntax divided
