	.syntax unified

	thumb_func_start calc_polar_to_screen_coords
	.global calc_polar_to_screen_coords
calc_polar_to_screen_coords: @ 0x08042BC0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	mov sb, r1
	adds r4, r2, #0
	adds r6, r3, #0
	ldr r5, [sp, #0x20]
	ldr r0, _08042BF0 @ =0x083D6BA0
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl int_to_softfloat
	mov r8, r0
	cmp r4, #0
	blt _08042BF4
	adds r0, r4, #0
	bl int_to_softfloat
	b _08042C08
	.align 2, 0
_08042BF0: .4byte 0x083D6BA0
_08042BF4:
	movs r0, #1
	ands r0, r4
	lsrs r1, r4, #1
	orrs r0, r1
	bl int_to_softfloat
	adds r2, r0, #0
	adds r1, r2, #0
	bl softfloat_add_f32
_08042C08:
	adds r2, r0, #0
	ldr r1, _08042C40 @ =0x3B800000
	adds r0, r2, #0
	bl softfloat_multiply
	adds r1, r0, #0
	mov r0, r8
	bl softfloat_multiply
	bl float_clamp_to_int
	adds r6, r6, r0
	ldr r1, _08042C44 @ =0x083D69A0
	mov r2, sb
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl int_to_softfloat
	mov r8, r0
	cmp r4, #0
	blt _08042C48
	adds r0, r4, #0
	bl int_to_softfloat
	b _08042C5C
	.align 2, 0
_08042C40: .4byte 0x3B800000
_08042C44: .4byte 0x083D69A0
_08042C48:
	movs r0, #1
	ands r0, r4
	lsrs r1, r4, #1
	orrs r0, r1
	bl int_to_softfloat
	adds r2, r0, #0
	adds r1, r2, #0
	bl softfloat_add_f32
_08042C5C:
	adds r2, r0, #0
	ldr r1, _08042C98 @ =0x3B800000
	adds r0, r2, #0
	bl softfloat_multiply
	adds r1, r0, #0
	mov r0, r8
	bl softfloat_multiply
	bl float_clamp_to_int
	adds r5, r5, r0
	ldr r2, _08042C9C @ =0x000001FF
	adds r1, r2, #0
	movs r0, #0xff
	ands r5, r0
	lsls r0, r5, #0x10
	adds r7, r1, #0
	ands r7, r6
	orrs r7, r0
	mov r0, sl
	str r7, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08042C98: .4byte 0x3B800000
_08042C9C: .4byte 0x000001FF
	.syntax divided
