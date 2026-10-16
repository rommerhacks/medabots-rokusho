	.syntax unified

	thumb_func_start affine_set_destination_and_compute_transform
affine_set_destination_and_compute_transform: @ 0x0805380C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r0
	adds r6, r1, #0
	str r2, [sp]
	mov sb, r3
	ldr r4, _080538BC @ =0x03005350
	str r0, [r4, #0x10]
	str r6, [r4, #0x14]
	ldr r0, [sp]
	str r0, [r4, #0x18]
	str r3, [r4, #0x1c]
	ldr r0, [r4, #0x24]
	ldr r1, [r4, #0x20]
	bl softfloat_subtract
	adds r5, r0, #0
	adds r0, r6, #0
	mov r1, r8
	bl softfloat_subtract
	adds r7, r0, #0
	adds r0, r5, #0
	adds r1, r7, #0
	bl softfloat_divide
	str r0, [r4, #0x30]
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x28]
	bl softfloat_subtract
	adds r5, r0, #0
	mov r0, sb
	ldr r1, [sp]
	bl softfloat_subtract
	mov sl, r0
	adds r0, r5, #0
	mov r1, sl
	bl softfloat_divide
	str r0, [r4, #0x34]
	adds r0, r6, #0
	ldr r1, [r4, #0x20]
	bl softfloat_multiply
	adds r5, r0, #0
	mov r0, r8
	ldr r1, [r4, #0x24]
	bl softfloat_multiply
	adds r1, r0, #0
	adds r0, r5, #0
	bl softfloat_subtract
	adds r1, r7, #0
	bl softfloat_divide
	str r0, [r4, #0x38]
	mov r0, sb
	ldr r1, [r4, #0x28]
	bl softfloat_multiply
	adds r5, r0, #0
	ldr r0, [sp]
	ldr r1, [r4, #0x2c]
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
_080538BC: .4byte 0x03005350
	.syntax divided
