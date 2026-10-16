	.syntax unified

	thumb_func_start float_abs_if_negative
	.global float_abs_if_negative
float_abs_if_negative: @ 0x08053358
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08053378 @ =0x00000000
	bl soft_float_ge
	cmp r0, #0
	bge _08053370
	ldr r1, _0805337C @ =0xBF800000
	adds r0, r4, #0
	bl softfloat_multiply
	adds r4, r0, #0
_08053370:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08053378: .4byte 0x00000000
_0805337C: .4byte 0xBF800000
	.syntax divided
