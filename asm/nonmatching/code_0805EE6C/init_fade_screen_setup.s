	.syntax unified

	thumb_func_start init_fade_screen_setup
init_fade_screen_setup: @ 0x0805F1F0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _0805F29C @ =0x03006F74
	ldr r0, [r4]
	adds r0, #0x2b
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r4]
	strh r1, [r0, #0x2c]
	adds r0, #0x2b
	ldrb r0, [r0]
	subs r1, #2
	movs r2, #2
	mov r8, r2
	str r2, [sp]
	ldr r6, _0805F2A0 @ =0x0400000A
	ldrh r2, [r6]
	lsrs r2, r2, #8
	movs r5, #0x1f
	ands r2, r5
	str r2, [sp, #4]
	movs r2, #0x10
	movs r3, #4
	bl draw_tilemap_line
	ldr r0, [r4]
	ldrh r0, [r0, #0x2c]
	movs r1, #3
	rsbs r1, r1, #0
	mov r3, r8
	str r3, [sp]
	ldrh r2, [r6]
	lsrs r2, r2, #8
	ands r2, r5
	str r2, [sp, #4]
	movs r2, #0xf
	movs r3, #6
	bl draw_tilemap_line
	ldr r1, [r4]
	movs r0, #0x20
	strb r0, [r1]
	ldr r1, _0805F2A4 @ =0x04000054
	ldr r0, [r4]
	ldrb r0, [r0]
	lsrs r0, r0, #1
	strh r0, [r1]
	ldr r1, _0805F2A8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805F29C: .4byte 0x03006F74
_0805F2A0: .4byte 0x0400000A
_0805F2A4: .4byte 0x04000054
_0805F2A8: .4byte 0x0300137C
	.syntax divided
