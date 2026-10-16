	.syntax unified

	thumb_func_start set_state_float_field
set_state_float_field: @ 0x08053974
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov sl, r1
	str r2, [sp]
	adds r0, r3, #0
	ldr r1, _08053AA4 @ =0x03005350
	str r2, [r1, #0x4c]
	adds r4, r1, #0
	adds r4, #0xa0
	bl float_to_int
	str r0, [r4]
	ldr r4, _08053AA8 @ =0x083D6EA0
	adds r0, r5, #0
	bl float_to_int
	movs r6, #0xff
	ands r0, r6
	lsls r0, r0, #2
	adds r1, r0, r4
	ldr r1, [r1]
	mov r8, r1
	ldr r2, _08053AA4 @ =0x03005350
	str r1, [r2, #0x50]
	ldr r5, _08053AAC @ =0x083D72A0
	adds r0, r0, r5
	ldr r0, [r0]
	mov sb, r0
	str r0, [r2, #0x54]
	mov r0, sl
	bl float_to_int
	ands r0, r6
	lsls r0, r0, #2
	adds r4, r0, r4
	ldr r4, [r4]
	ldr r1, _08053AA4 @ =0x03005350
	str r4, [r1, #0x58]
	adds r0, r0, r5
	ldr r0, [r0]
	mov sl, r0
	str r0, [r1, #0x5c]
	adds r0, r4, #0
	mov r1, r8
	bl softfloat_multiply
	adds r6, r0, #0
	adds r0, r4, #0
	mov r1, sb
	bl softfloat_multiply
	adds r7, r0, #0
	mov r5, sl
	adds r0, r6, #0
	adds r1, r6, #0
	bl softfloat_multiply
	adds r4, r0, #0
	adds r0, r7, #0
	adds r1, r7, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_add_f32
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r5, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_add_f32
	bl float_to_double
	bl compute_sqrt_scaled
	bl softfloat_double_round
	adds r5, r0, #0
	ldr r1, _08053AB0 @ =0x00000000
	bl soft_float_eq
	cmp r0, #0
	bne _08053A2E
	ldr r5, _08053AB4 @ =0x3F800000
_08053A2E:
	adds r0, r6, #0
	bl float_to_int
	adds r4, r0, #0
	adds r0, r5, #0
	bl float_to_int
	adds r5, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	bl Div
	bl int_to_softfloat
	adds r6, r0, #0
	adds r0, r7, #0
	bl float_to_int
	adds r1, r5, #0
	bl Div
	bl int_to_softfloat
	adds r7, r0, #0
	mov r0, sl
	bl float_to_int
	adds r1, r5, #0
	bl Div
	bl int_to_softfloat
	adds r5, r0, #0
	ldr r0, [sp]
	adds r1, r6, #0
	bl softfloat_multiply
	ldr r2, _08053AA4 @ =0x03005350
	str r0, [r2, #0x40]
	ldr r0, [sp]
	adds r1, r7, #0
	bl softfloat_multiply
	ldr r1, _08053AA4 @ =0x03005350
	str r0, [r1, #0x44]
	ldr r0, [sp]
	adds r1, r5, #0
	bl softfloat_multiply
	ldr r2, _08053AA4 @ =0x03005350
	str r0, [r2, #0x48]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053AA4: .4byte 0x03005350
_08053AA8: .4byte 0x083D6EA0
_08053AAC: .4byte 0x083D72A0
_08053AB0: .4byte 0x00000000
_08053AB4: .4byte 0x3F800000
	.syntax divided
