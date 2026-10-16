	.syntax unified

	thumb_func_start sound_channel_setup
sound_channel_setup: @ 0x08073D10
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r1
	ldr r4, [sp, #0x18]
	ldr r5, [sp, #0x1c]
	ldr r6, [sp, #0x20]
	ldr r1, [sp, #0x24]
	mov r8, r1
	mov r7, ip
	adds r7, #0x3e
	movs r1, #0
	strb r1, [r7]
	mov r1, ip
	str r0, [r1, #0x18]
	str r2, [r1, #0x1c]
	str r3, [r1, #0x24]
	str r4, [r1, #0x28]
	str r5, [r1, #0x2c]
	mov r0, ip
	adds r0, #0x30
	strb r6, [r0]
	adds r0, #1
	mov r1, r8
	strb r1, [r0]
	movs r0, #1
	strb r0, [r7]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
