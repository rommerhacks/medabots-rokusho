	.syntax unified

	thumb_func_start render_medal_skill_stats
render_medal_skill_stats: @ 0x0800AFF8
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	ldr r0, _0800B0E8 @ =0x03000BE0
	mov r8, r0
	ldr r4, _0800B0EC @ =0x03000440
	adds r4, #0x3d
	ldrb r0, [r4]
	lsls r0, r0, #6
	add r0, r8
	adds r0, #0x20
	ldrb r0, [r0]
	ldr r6, _0800B0F0 @ =0x0400000A
	ldrh r1, [r6]
	str r1, [sp]
	ldr r5, _0800B0F4 @ =0x0000C3C4
	str r5, [sp, #4]
	movs r1, #0xb
	movs r2, #9
	movs r3, #3
	bl divide_by_100000_08042838
	ldrb r0, [r4]
	lsls r0, r0, #6
	add r0, r8
	adds r0, #0x21
	ldrb r0, [r0]
	ldrh r1, [r6]
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0xb
	movs r2, #0xc
	movs r3, #3
	bl divide_by_100000_08042838
	ldrb r0, [r4]
	lsls r0, r0, #6
	add r0, r8
	adds r0, #0x22
	ldrb r0, [r0]
	ldrh r1, [r6]
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0x19
	movs r2, #9
	movs r3, #3
	bl divide_by_100000_08042838
	ldrb r0, [r4]
	lsls r0, r0, #6
	add r0, r8
	adds r0, #0x23
	ldrb r0, [r0]
	ldrh r1, [r6]
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0x19
	movs r2, #0xc
	movs r3, #3
	bl divide_by_100000_08042838
	ldrb r0, [r4]
	lsls r0, r0, #6
	add r0, r8
	adds r0, #0x24
	ldrb r0, [r0]
	ldrh r1, [r6]
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0xb
	movs r2, #0xf
	movs r3, #3
	bl divide_by_100000_08042838
	ldrb r0, [r4]
	lsls r0, r0, #6
	add r0, r8
	adds r0, #0x25
	ldrb r0, [r0]
	ldrh r1, [r6]
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0xb
	movs r2, #0x12
	movs r3, #3
	bl divide_by_100000_08042838
	ldrb r0, [r4]
	lsls r0, r0, #6
	add r0, r8
	adds r0, #0x26
	ldrb r0, [r0]
	ldrh r1, [r6]
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0x19
	movs r2, #0xf
	movs r3, #3
	bl divide_by_100000_08042838
	ldrb r0, [r4]
	lsls r0, r0, #6
	add r0, r8
	adds r0, #0x27
	ldrb r0, [r0]
	ldrh r1, [r6]
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0x19
	movs r2, #0x12
	movs r3, #3
	bl divide_by_100000_08042838
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800B0E8: .4byte 0x03000BE0
_0800B0EC: .4byte 0x03000440
_0800B0F0: .4byte 0x0400000A
_0800B0F4: .4byte 0x0000C3C4
	.syntax divided
