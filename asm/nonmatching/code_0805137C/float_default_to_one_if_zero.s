	.syntax unified

	thumb_func_start float_default_to_one_if_zero
	.global float_default_to_one_if_zero
float_default_to_one_if_zero: @ 0x08053314
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0805332C @ =0x00000000
	bl soft_float_eq
	cmp r0, #0
	bne _08053324
	ldr r4, _08053330 @ =0x3F800000
_08053324:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0805332C: .4byte 0x00000000
_08053330: .4byte 0x3F800000
	.syntax divided
