	.syntax unified

	thumb_func_start sub_0800F218
sub_0800F218: @ 0x0800F218
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	ldr r7, _0800F2D4 @ =0x03000440
	adds r0, r7, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	adds r1, r7, #0
	adds r1, #0x40
	lsls r0, r0, #2
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r1, #0x3d
	adds r1, r1, r7
	mov sl, r1
	movs r1, #0
	mov sb, r1
	mov r1, sl
	strb r0, [r1]
	ldr r6, _0800F2D8 @ =0x02026000
	adds r0, r6, #0
	movs r1, #0xd0
	movs r2, #0
	bl sub_0803F624
	ldr r5, _0800F2DC @ =0x020260D0
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r5, #0
	movs r2, #0
	bl sub_0803F624
	ldr r0, _0800F2E0 @ =0x020268D0
	mov r8, r0
	movs r1, #0x60
	movs r2, #0
	bl sub_0803F624
	ldr r1, _0800F2E4 @ =0x03000430
	movs r0, #2
	str r0, [r1]
	ldr r4, _0800F2E8 @ =0x03002414
	ldr r1, _0800F2EC @ =0x02024000
	str r1, [r4]
	mov r0, sb
	str r0, [sp, #0x14]
	ldr r2, _0800F2F0 @ =0x01000426
	add r0, sp, #0x14
	bl CpuFastSet
	ldr r0, _0800F2F4 @ =0x03005308
	mov r1, r8
	str r1, [r0]
	ldr r1, [r4]
	ldr r2, _0800F2F8 @ =0x083D1BF8
	adds r0, r6, #0
	adds r3, r5, #0
	bl sub_08047414
	str r5, [r6, #8]
	ldr r0, [r4]
	ldr r1, _0800F2FC @ =0x00000B84
	adds r0, r0, r1
	mov r1, sl
	ldrb r2, [r1]
	adds r1, r7, #0
	adds r1, #0x3e
	ldrb r3, [r1]
	movs r1, #0x3c
	str r1, [sp]
	movs r1, #0x28
	str r1, [sp, #4]
	movs r1, #0xe1
	lsls r1, r1, #1
	str r1, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	movs r1, #1
	str r1, [sp, #0x10]
	adds r1, r6, #0
	bl load_sprite_animation_by_type
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F2D4: .4byte 0x03000440
_0800F2D8: .4byte 0x02026000
_0800F2DC: .4byte 0x020260D0
_0800F2E0: .4byte 0x020268D0
_0800F2E4: .4byte 0x03000430
_0800F2E8: .4byte 0x03002414
_0800F2EC: .4byte 0x02024000
_0800F2F0: .4byte 0x01000426
_0800F2F4: .4byte 0x03005308
_0800F2F8: .4byte 0x083D1BF8
_0800F2FC: .4byte 0x00000B84
	.syntax divided
