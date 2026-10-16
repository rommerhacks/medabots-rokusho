	.syntax unified

	thumb_func_start compute_sqrt_scaled
compute_sqrt_scaled: @ 0x08053380
	push {lr}
	bl double_to_int
	lsls r0, r0, #3
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x13
	bl softfloat_int_to_double
	pop {r2}
	bx r2
	.syntax divided
