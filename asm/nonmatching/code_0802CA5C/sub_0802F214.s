	.syntax unified

	thumb_func_start sub_0802F214
sub_0802F214: @ 0x0802F214
	push {r4, r5, r6, r7, lr}
	ldr r3, _0802F2E4 @ =0x03002C30
	ldr r2, _0802F2E8 @ =0x03000440
	adds r2, #0x84
	ldrb r0, [r2]
	adds r0, #0x21
	lsls r0, r0, #6
	adds r0, r0, r3
	movs r5, #0
	movs r6, #0
	ldr r1, _0802F2EC @ =0x0000C604
	strh r1, [r0]
	ldrb r0, [r2]
	adds r0, #0x21
	lsls r0, r0, #6
	adds r0, r0, r3
	strb r5, [r0, #0x1c]
	ldrb r1, [r2]
	adds r1, #0x21
	lsls r1, r1, #6
	adds r1, r1, r3
	ldr r4, _0802F2F0 @ =0x03001800
	movs r0, #0x87
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r0]
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	strh r0, [r1, #2]
	ldrb r1, [r2]
	adds r1, #0x21
	lsls r1, r1, #6
	adds r1, r1, r3
	mov r7, ip
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r3
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r1, #4]
	ldrb r0, [r2]
	adds r0, #0x21
	lsls r0, r0, #6
	adds r0, r0, r3
	movs r1, #7
	strb r1, [r0, #0xa]
	ldrb r0, [r2]
	adds r0, #0x21
	lsls r0, r0, #6
	adds r0, r0, r3
	movs r1, #0xf0
	strb r1, [r0, #0xb]
	ldrb r0, [r2]
	adds r0, #0x21
	lsls r0, r0, #6
	adds r0, r0, r3
	movs r1, #0x40
	strb r1, [r0, #8]
	ldrb r0, [r2]
	adds r0, #0x21
	lsls r0, r0, #6
	adds r0, r0, r3
	strb r1, [r0, #9]
	ldrb r0, [r2]
	adds r0, #0x21
	lsls r0, r0, #6
	adds r0, r0, r3
	strh r6, [r0, #0x18]
	ldrb r0, [r2]
	adds r0, #0x21
	lsls r0, r0, #6
	adds r0, r0, r3
	movs r1, #0x82
	lsls r1, r1, #7
	strh r1, [r0, #6]
	ldrb r0, [r2]
	adds r0, #0x21
	lsls r0, r0, #6
	adds r0, r0, r3
	adds r0, #0x23
	strb r5, [r0]
	ldrb r0, [r2]
	adds r0, #0x21
	lsls r0, r0, #6
	adds r0, r0, r3
	adds r0, #0x27
	strb r5, [r0]
	movs r0, #0x29
	bl play_sound_effect
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802F2E4: .4byte 0x03002C30
_0802F2E8: .4byte 0x03000440
_0802F2EC: .4byte 0x0000C604
_0802F2F0: .4byte 0x03001800
	.syntax divided
