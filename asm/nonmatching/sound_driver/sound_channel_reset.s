	.syntax unified

	thumb_func_start sound_channel_reset
sound_channel_reset: @ 0x08074794
	push {r4, lr}
	mov ip, r0
	movs r3, #0
	str r3, [r0, #0x14]
	adds r0, #0x54
	strb r3, [r0]
	adds r0, #0x17
	strb r3, [r0]
	subs r0, #5
	strb r3, [r0]
	mov r1, ip
	adds r1, #0x48
	movs r4, #0
	movs r0, #0xff
	strh r0, [r1]
	mov r2, ip
	adds r2, #0x50
	ldrb r1, [r2]
	movs r0, #0xa
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x6d
	strb r4, [r0]
	subs r0, #0x15
	strb r4, [r0]
	mov r0, ip
	str r3, [r0, #0x38]
	mov r1, ip
	adds r1, #0x4e
	ldr r0, _080747E0 @ =0x0000FFFF
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x44
	strh r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080747E0: .4byte 0x0000FFFF
	.syntax divided
