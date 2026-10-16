	.syntax unified

	thumb_func_start init_sound_channel_struct
init_sound_channel_struct: @ 0x08073C40
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r4, [sp, #0x14]
	ldr r0, [sp, #0x18]
	ldr r5, [sp, #0x1c]
	ldr r6, [sp, #0x20]
	mov r7, ip
	str r1, [r7]
	str r2, [r7, #8]
	movs r1, #0
	str r1, [r7, #0xc]
	str r1, [r7, #0x14]
	strh r0, [r7, #0x34]
	strh r1, [r7, #0x36]
	strh r1, [r7, #0x38]
	mov r0, ip
	adds r0, #0x3b
	strb r3, [r0]
	adds r0, #1
	strb r4, [r0]
	str r1, [r7, #4]
	str r1, [r7, #0x10]
	adds r0, #3
	strb r5, [r0]
	adds r0, #1
	strb r6, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
