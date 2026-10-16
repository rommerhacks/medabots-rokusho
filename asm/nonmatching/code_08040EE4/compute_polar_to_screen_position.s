	.syntax unified

	thumb_func_start compute_polar_to_screen_position
	.global compute_polar_to_screen_position
compute_polar_to_screen_position: @ 0x08042CA0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	adds r6, r2, #0
	mov sl, r3
	ldr r0, [sp, #0x28]
	mov r8, r0
	ldr r7, [sp, #0x2c]
	ldr r5, [sp, #0x30]
	cmp r6, r7
	bhs _08042CC0
	adds r7, r6, #0
_08042CC0:
	cmp r6, r5
	bhs _08042CC6
	adds r5, r6, #0
_08042CC6:
	ldr r0, _08042CE4 @ =0x083D6BA0
	lsls r4, r1, #1
	adds r0, r4, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl int_to_softfloat
	str r0, [sp, #4]
	subs r1, r6, r5
	cmp r1, #0
	blt _08042CE8
	adds r0, r1, #0
	bl int_to_softfloat
	b _08042CFC
	.align 2, 0
_08042CE4: .4byte 0x083D6BA0
_08042CE8:
	movs r0, #1
	ands r0, r1
	lsrs r1, r1, #1
	orrs r0, r1
	bl int_to_softfloat
	adds r2, r0, #0
	adds r1, r2, #0
	bl softfloat_add_f32
_08042CFC:
	adds r2, r0, #0
	ldr r1, _08042D30 @ =0x3B800000
	adds r0, r2, #0
	bl softfloat_multiply
	adds r1, r0, #0
	ldr r0, [sp, #4]
	bl softfloat_multiply
	bl float_clamp_to_int
	add sl, r0
	ldr r0, _08042D34 @ =0x083D69A0
	adds r0, r4, r0
	movs r2, #0
	ldrsh r0, [r0, r2]
	bl int_to_softfloat
	adds r4, r0, #0
	subs r1, r6, r7
	cmp r1, #0
	blt _08042D38
	adds r0, r1, #0
	bl int_to_softfloat
	b _08042D4C
	.align 2, 0
_08042D30: .4byte 0x3B800000
_08042D34: .4byte 0x083D69A0
_08042D38:
	movs r0, #1
	ands r0, r1
	lsrs r1, r1, #1
	orrs r0, r1
	bl int_to_softfloat
	adds r2, r0, #0
	adds r1, r2, #0
	bl softfloat_add_f32
_08042D4C:
	adds r2, r0, #0
	ldr r1, _08042D8C @ =0x3B800000
	adds r0, r2, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_multiply
	bl float_clamp_to_int
	add r8, r0
	ldr r0, _08042D90 @ =0x000001FF
	adds r1, r0, #0
	movs r0, #0xff
	mov r2, r8
	ands r2, r0
	lsls r0, r2, #0x10
	mov r2, sl
	ands r2, r1
	orrs r2, r0
	ldr r0, [sp]
	str r2, [r0]
	ldr r0, [sp]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08042D8C: .4byte 0x3B800000
_08042D90: .4byte 0x000001FF
	.syntax divided
