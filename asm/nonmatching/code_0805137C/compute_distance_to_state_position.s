	.syntax unified

	thumb_func_start compute_distance_to_state_position
compute_distance_to_state_position: @ 0x08053478
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	mov sl, r0
	str r1, [sp, #0x28]
	str r2, [sp, #0x2c]
	add r0, sp, #0x10
	str r0, [sp]
	add r0, sp, #0x14
	str r0, [sp, #4]
	add r0, sp, #0x18
	str r0, [sp, #8]
	mov r0, sl
	add r3, sp, #0xc
	bl compute_triangle_area_3d
	mov r0, sl
	ldr r4, [r0]
	ldr r0, [sp, #0x28]
	ldr r5, [r0]
	ldr r0, [sp, #0x2c]
	ldr r6, [r0]
	add r0, sp, #0x1c
	add r1, sp, #0x20
	add r2, sp, #0x24
	bl get_state_position_xyz
	ldr r1, [sp, #0x1c]
	adds r0, r4, #0
	bl softfloat_subtract
	adds r7, r0, #0
	ldr r1, [sp, #0x20]
	adds r0, r5, #0
	bl softfloat_subtract
	mov r8, r0
	ldr r1, [sp, #0x24]
	adds r0, r6, #0
	bl softfloat_subtract
	mov sb, r0
	adds r0, r7, #0
	adds r1, r7, #0
	bl softfloat_multiply
	adds r4, r0, #0
	mov r0, r8
	mov r1, r8
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_add_f32
	adds r4, r0, #0
	mov r0, sb
	mov r1, sb
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_add_f32
	adds r6, r0, #0
	bl float_to_double
	bl compute_sqrt_scaled
	bl softfloat_double_round
	adds r6, r0, #0
	ldr r1, _08053570 @ =0x00000000
	bl soft_float_eq
	cmp r0, #0
	bne _0805351A
	ldr r6, _08053574 @ =0x3F800000
_0805351A:
	adds r0, r7, #0
	bl float_to_int
	adds r5, r0, #0
	adds r0, r6, #0
	bl float_to_int
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl Div
	mov r0, r8
	bl float_to_int
	adds r1, r4, #0
	bl Div
	mov r0, sb
	bl float_to_int
	adds r1, r4, #0
	bl Div
	ldr r1, _08053578 @ =0x461C4000
	adds r0, r6, #0
	bl soft_float_ge
	cmp r0, #0
	bge _08053560
	mov r0, sl
	ldr r1, [sp, #0x28]
	ldr r2, [sp, #0x2c]
	bl sub_08053AB8
_08053560:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053570: .4byte 0x00000000
_08053574: .4byte 0x3F800000
_08053578: .4byte 0x461C4000
	.syntax divided
