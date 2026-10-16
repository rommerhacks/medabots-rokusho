	.syntax unified

	thumb_func_start setup_bot_render_label
	.global setup_bot_render_label
setup_bot_render_label: @ 0x08014F90
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	str r1, [sp]
	movs r0, #0
	str r0, [sp, #4]
	cmp r0, r1
	bhs _080150A6
	ldr r1, _080150B8 @ =0x03000590
	ldr r7, _080150BC @ =0x0300052E
	mov r0, r8
	lsls r2, r0, #8
	adds r0, r2, #0
	adds r0, #0xa1
	adds r6, r0, r1
	subs r0, #0xd
	adds r0, r0, r1
	str r0, [sp, #8]
	adds r0, r2, #0
	adds r0, #0x90
	adds r0, r0, r1
	str r0, [sp, #0xc]
	adds r0, r2, #0
	adds r0, #0x46
	adds r0, r0, r1
	str r0, [sp, #0x10]
	adds r0, r2, #0
	adds r0, #0x78
	adds r0, r0, r1
	str r0, [sp, #0x14]
	adds r0, r2, #0
	adds r0, #0x71
	adds r5, r0, r1
	subs r0, #0x11
	adds r0, r0, r1
	mov sl, r0
	adds r0, r2, #0
	adds r0, #0x43
	adds r4, r0, r1
	adds r0, #5
	adds r0, r0, r1
	mov sb, r0
_08014FEC:
	mov r1, r8
	strb r1, [r6, #0x17]
	movs r0, #1
	strb r0, [r6, #0x19]
	ldrb r0, [r4]
	movs r1, #0
	adds r2, r7, #0
	bl load_part_data
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0xd
	bl memcpy_bytes_0803F63C
	ldrb r0, [r4, #0xd]
	strb r0, [r4, #0x15]
	ldrb r0, [r4, #9]
	strb r0, [r4, #0x16]
	ldrb r0, [r4]
	strb r0, [r4, #0x1c]
	ldrb r0, [r4, #1]
	movs r1, #1
	adds r2, r7, #0
	bl load_part_data
	adds r0, r7, #0
	mov r1, sl
	movs r2, #0xd
	bl memcpy_bytes_0803F63C
	ldr r1, [sp, #0x10]
	ldrb r0, [r1, #0x1e]
	strb r0, [r5]
	ldrb r0, [r4, #1]
	strb r0, [r5, #6]
	ldrb r0, [r4, #2]
	movs r1, #2
	adds r2, r7, #0
	bl load_part_data
	adds r0, r7, #0
	ldr r1, [sp, #0x14]
	movs r2, #0xd
	bl memcpy_bytes_0803F63C
	ldrb r0, [r5, #0xb]
	strb r0, [r5, #0x18]
	ldrb r0, [r4, #2]
	strb r0, [r5, #0x1e]
	ldrb r0, [r4, #3]
	movs r1, #3
	adds r2, r7, #0
	bl load_part_data
	adds r0, r7, #0
	ldr r1, [sp, #0xc]
	movs r2, #0xd
	bl memcpy_bytes_0803F63C
	ldr r0, [sp, #8]
	adds r1, r6, #0
	movs r2, #6
	bl memcpy_bytes_0803F63C
	ldrb r0, [r4, #3]
	strb r0, [r6, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r6, r6, r0
	ldr r1, [sp, #8]
	adds r1, r1, r0
	str r1, [sp, #8]
	ldr r1, [sp, #0xc]
	adds r1, r1, r0
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x10]
	adds r1, r1, r0
	str r1, [sp, #0x10]
	ldr r1, [sp, #0x14]
	adds r1, r1, r0
	str r1, [sp, #0x14]
	adds r5, r5, r0
	add sl, r0
	adds r4, r4, r0
	add sb, r0
	movs r0, #1
	add r8, r0
	ldr r1, [sp, #4]
	adds r1, #1
	str r1, [sp, #4]
	ldr r0, [sp]
	cmp r1, r0
	blo _08014FEC
_080150A6:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080150B8: .4byte 0x03000590
_080150BC: .4byte 0x0300052E
	.syntax divided
