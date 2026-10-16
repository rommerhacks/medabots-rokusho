	.syntax unified

	thumb_func_start affine_set_source_and_compute_transform
affine_set_source_and_compute_transform: @ 0x080538C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov r8, r1
	mov sb, r2
	str r3, [sp]
	ldr r4, _08053970 @ =0x03005350
	str r6, [r4, #0x20]
	str r1, [r4, #0x24]
	str r2, [r4, #0x28]
	ldr r0, [sp]
	str r0, [r4, #0x2c]
	mov r0, r8
	adds r1, r6, #0
	bl softfloat_subtract
	adds r5, r0, #0
	ldr r0, [r4, #0x14]
	ldr r1, [r4, #0x10]
	bl softfloat_subtract
	adds r7, r0, #0
	adds r0, r5, #0
	adds r1, r7, #0
	bl softfloat_divide
	str r0, [r4, #0x30]
	ldr r0, [sp]
	mov r1, sb
	bl softfloat_subtract
	adds r5, r0, #0
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x18]
	bl softfloat_subtract
	mov sl, r0
	adds r0, r5, #0
	mov r1, sl
	bl softfloat_divide
	str r0, [r4, #0x34]
	ldr r0, [r4, #0x14]
	adds r1, r6, #0
	bl softfloat_multiply
	adds r5, r0, #0
	ldr r0, [r4, #0x10]
	mov r1, r8
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r5, #0
	bl softfloat_subtract
	adds r1, r7, #0
	bl softfloat_divide
	str r0, [r4, #0x38]
	ldr r0, [r4, #0x1c]
	mov r1, sb
	bl softfloat_multiply
	adds r5, r0, #0
	ldr r0, [r4, #0x18]
	ldr r1, [sp]
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r5, #0
	bl softfloat_subtract
	mov r1, sl
	bl softfloat_divide
	str r0, [r4, #0x3c]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053970: .4byte 0x03005350
	.syntax divided
