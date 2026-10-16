	.syntax unified

	thumb_func_start float_sign
	.global float_sign
float_sign: @ 0x08053334
	push {lr}
	ldr r1, _08053344 @ =0x00000000
	bl soft_float_ge
	cmp r0, #0
	blt _0805334C
	ldr r0, _08053348 @ =0x3F800000
	b _0805334E
	.align 2, 0
_08053344: .4byte 0x00000000
_08053348: .4byte 0x3F800000
_0805334C:
	ldr r0, _08053354 @ =0xBF800000
_0805334E:
	pop {r1}
	bx r1
	.align 2, 0
_08053354: .4byte 0xBF800000
	.syntax divided
