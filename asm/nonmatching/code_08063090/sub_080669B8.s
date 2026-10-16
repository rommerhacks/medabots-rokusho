	.syntax unified

	thumb_func_start sub_080669B8
sub_080669B8: @ 0x080669B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x140
	adds r4, r0, #0
	mov r8, r1
	mov sl, r2
	mov r0, sp
	movs r1, #0
	movs r2, #0x10
	bl custom_memset
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp]
	movs r6, #0
	str r6, [sp, #0x10]
	ldr r1, _08066AF0 @ =0x080AE77C
	mov sb, r1
	adds r0, r4, #0
	adds r0, #0x40
	lsls r0, r0, #1
	add r0, sb
	movs r2, #0
	ldrsh r1, [r0, r2]
	str r1, [sp, #0x14]
	lsls r4, r4, #1
	add r4, sb
	movs r2, #0
	ldrsh r0, [r4, r2]
	str r0, [sp, #0x18]
	str r6, [sp, #0x1c]
	str r6, [sp, #0x20]
	rsbs r0, r0, #0
	str r0, [sp, #0x24]
	str r1, [sp, #0x28]
	str r6, [sp, #0x2c]
	add r0, sp, #0x30
	movs r1, #0
	movs r2, #0x10
	bl custom_memset
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp, #0x3c]
	add r5, sp, #0x40
	mov r0, r8
	adds r0, #0x40
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r7, [r0, r1]
	str r7, [sp, #0x40]
	str r6, [r5, #4]
	mov r2, r8
	lsls r2, r2, #1
	mov r8, r2
	add r8, sb
	mov r0, r8
	movs r1, #0
	ldrsh r4, [r0, r1]
	rsbs r0, r4, #0
	str r0, [r5, #8]
	str r6, [r5, #0xc]
	add r0, sp, #0x50
	movs r1, #0
	movs r2, #0x10
	bl custom_memset
	movs r2, #0x80
	lsls r2, r2, #1
	str r2, [r5, #0x14]
	str r4, [r5, #0x20]
	str r6, [r5, #0x24]
	str r7, [r5, #0x28]
	str r6, [r5, #0x2c]
	add r0, sp, #0x70
	movs r1, #0
	movs r2, #0x10
	bl custom_memset
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r5, #0x3c]
	add r4, sp, #0x80
	mov r0, sl
	adds r0, #0x40
	lsls r0, r0, #1
	add r0, sb
	movs r2, #0
	ldrsh r1, [r0, r2]
	str r1, [r4]
	mov r2, sl
	lsls r0, r2, #1
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [r4, #4]
	str r6, [r4, #8]
	str r6, [r4, #0xc]
	rsbs r0, r0, #0
	str r0, [r4, #0x10]
	str r1, [r4, #0x14]
	str r6, [r4, #0x18]
	str r6, [r4, #0x1c]
	add r0, sp, #0xa0
	movs r1, #0
	movs r2, #0x10
	bl custom_memset
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r4, #0x28]
	add r0, sp, #0xb0
	movs r1, #0
	movs r2, #0x10
	bl custom_memset
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r4, #0x3c]
	add r2, sp, #0xc0
	mov r8, r2
	ldr r7, _08066AF4 @ =0x03006F74
	ldr r2, [r7]
	movs r0, #0xf8
	lsls r0, r0, #1
	mov sb, r0
	add r2, sb
	mov r0, r8
	mov r1, sp
	bl matrix_multiply_4x4_fixed
	add r6, sp, #0x100
	adds r0, r6, #0
	adds r1, r5, #0
	mov r2, r8
	bl matrix_multiply_4x4_fixed
	ldr r0, [r7]
	add r0, sb
	adds r1, r4, #0
	adds r2, r6, #0
	bl matrix_multiply_4x4_fixed
	add sp, #0x140
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08066AF0: .4byte 0x080AE77C
_08066AF4: .4byte 0x03006F74
	.syntax divided
