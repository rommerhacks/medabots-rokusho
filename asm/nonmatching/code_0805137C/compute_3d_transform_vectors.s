	.syntax unified

	thumb_func_start compute_3d_transform_vectors
compute_3d_transform_vectors: @ 0x08053C30
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov sb, r1
	mov sl, r2
	str r3, [sp]
	ldr r0, _08053D20 @ =0x03005350
	ldr r0, [r0, #0x50]
	mov r8, r0
	adds r0, r6, #0
	mov r1, r8
	bl softfloat_multiply
	adds r4, r0, #0
	ldr r1, _08053D20 @ =0x03005350
	ldr r5, [r1, #0x54]
	mov r0, sb
	adds r1, r5, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_add_f32
	adds r7, r0, #0
	adds r0, r6, #0
	bl float_is_zero
	adds r1, r5, #0
	bl softfloat_multiply
	adds r4, r0, #0
	mov r0, sb
	mov r1, r8
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_add_f32
	mov sb, r0
	ldr r2, _08053D20 @ =0x03005350
	ldr r6, [r2, #0x58]
	mov r0, sl
	adds r1, r6, #0
	bl softfloat_multiply
	adds r4, r0, #0
	ldr r0, _08053D20 @ =0x03005350
	ldr r5, [r0, #0x5c]
	adds r0, r7, #0
	adds r1, r5, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_subtract
	mov r8, r0
	adds r0, r7, #0
	adds r1, r6, #0
	bl softfloat_multiply
	adds r4, r0, #0
	mov r0, sl
	adds r1, r5, #0
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r4, #0
	bl softfloat_add_f32
	adds r1, r0, #0
	ldr r2, _08053D20 @ =0x03005350
	ldr r0, [r2, #0x4c]
	bl softfloat_subtract
	adds r4, r0, #0
	ldr r1, _08053D24 @ =0x00000000
	bl soft_float_eq
	cmp r0, #0
	bne _08053CE0
	ldr r4, _08053D28 @ =0x3F800000
_08053CE0:
	ldr r0, _08053D20 @ =0x03005350
	adds r0, #0xa0
	ldr r0, [r0]
	bl int_to_softfloat
	adds r1, r4, #0
	bl softfloat_divide
	adds r7, r0, #0
	mov r0, sb
	adds r1, r7, #0
	bl softfloat_multiply
	ldr r1, [sp]
	str r0, [r1]
	mov r0, r8
	adds r1, r7, #0
	bl softfloat_multiply
	ldr r1, [sp, #0x24]
	str r0, [r1]
	ldr r0, [sp, #0x28]
	str r4, [r0]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053D20: .4byte 0x03005350
_08053D24: .4byte 0x00000000
_08053D28: .4byte 0x3F800000
	.syntax divided
