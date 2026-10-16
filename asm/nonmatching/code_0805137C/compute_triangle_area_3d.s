	.syntax unified

	thumb_func_start compute_triangle_area_3d
compute_triangle_area_3d: @ 0x0805357C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, [r2, #4]
	mov sb, r0
	ldr r7, [r2, #8]
	adds r1, r7, #0
	bl softfloat_subtract
	adds r1, r0, #0
	ldr r2, [sp, #4]
	ldr r2, [r2]
	str r2, [sp, #0x10]
	adds r0, r2, #0
	bl softfloat_multiply
	adds r5, r0, #0
	ldr r0, [sp, #8]
	ldr r4, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl softfloat_subtract
	adds r1, r0, #0
	ldr r2, [sp, #4]
	ldr r2, [r2, #4]
	str r2, [sp, #0x14]
	adds r0, r2, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r5, #0
	bl softfloat_add_f32
	adds r5, r0, #0
	adds r0, r4, #0
	mov r1, sb
	bl softfloat_subtract
	adds r1, r0, #0
	ldr r0, [sp, #4]
	ldr r0, [r0, #8]
	mov r8, r0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r5, #0
	bl softfloat_add_f32
	mov sl, r0
	ldr r1, [sp]
	ldr r6, [r1, #4]
	ldr r2, [r1, #8]
	str r2, [sp, #0x18]
	adds r0, r6, #0
	adds r1, r2, #0
	bl softfloat_subtract
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_multiply
	adds r5, r0, #0
	ldr r0, [sp]
	ldr r4, [r0]
	ldr r0, [sp, #0x18]
	adds r1, r4, #0
	bl softfloat_subtract
	adds r1, r0, #0
	mov r0, sb
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r5, #0
	bl softfloat_add_f32
	adds r5, r0, #0
	adds r0, r4, #0
	adds r1, r6, #0
	bl softfloat_subtract
	adds r1, r0, #0
	adds r0, r7, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r5, #0
	bl softfloat_add_f32
	adds r7, r0, #0
	ldr r0, [sp, #0x14]
	mov r1, r8
	bl softfloat_subtract
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_multiply
	adds r4, r0, #0
	mov r0, r8
	ldr r1, [sp, #0x10]
	bl softfloat_subtract
	adds r1, r0, #0
	adds r0, r6, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_add_f32
	adds r4, r0, #0
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	bl softfloat_subtract
	adds r1, r0, #0
	ldr r0, [sp, #0x18]
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_add_f32
	adds r6, r0, #0
	mov r0, sl
	mov r1, sl
	bl softfloat_multiply
	adds r4, r0, #0
	adds r0, r7, #0
	adds r1, r7, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_add_f32
	adds r4, r0, #0
	adds r0, r6, #0
	adds r1, r6, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_add_f32
	adds r5, r0, #0
	bl float_to_double
	bl compute_sqrt_scaled
	bl softfloat_double_round
	adds r5, r0, #0
	ldr r1, _08053768 @ =0x00000000
	bl soft_float_eq
	cmp r0, #0
	bne _080536CE
	ldr r5, _0805376C @ =0x3F800000
_080536CE:
	mov r0, sl
	bl float_to_int
	adds r4, r0, #0
	adds r0, r5, #0
	bl float_to_int
	adds r5, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	bl Div
	bl int_to_softfloat
	mov sl, r0
	adds r0, r7, #0
	bl float_to_int
	adds r1, r5, #0
	bl Div
	bl int_to_softfloat
	adds r7, r0, #0
	adds r0, r6, #0
	bl float_to_int
	adds r1, r5, #0
	bl Div
	bl int_to_softfloat
	adds r6, r0, #0
	mov r1, sl
	ldr r2, [sp, #0xc]
	str r1, [r2]
	ldr r0, [sp, #0x3c]
	str r7, [r0]
	ldr r0, [sp, #0x40]
	str r6, [r0]
	ldr r0, [sp]
	ldr r1, [r0]
	mov r0, sl
	bl softfloat_multiply
	adds r4, r0, #0
	ldr r2, [sp, #4]
	ldr r1, [r2]
	adds r0, r7, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_add_f32
	adds r4, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [r0]
	adds r0, r6, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_add_f32
	bl float_is_zero
	ldr r1, [sp, #0x44]
	str r0, [r1]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053768: .4byte 0x00000000
_0805376C: .4byte 0x3F800000
	.syntax divided
