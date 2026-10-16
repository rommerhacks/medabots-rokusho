	.syntax unified

	thumb_func_start sub_0800AC2C
sub_0800AC2C: @ 0x0800AC2C
	push {r4, r5, r6, lr}
	ldr r0, _0800AC98 @ =0x03002C30
	mov ip, r0
	adds r0, #0x40
	movs r6, #0
	ldr r5, _0800AC9C @ =0x0000C804
	strh r5, [r0]
	ldr r2, _0800ACA0 @ =0x03000440
	adds r2, #0x46
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r0, #0x38
	mov r1, ip
	adds r1, #0x42
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x34
	strh r0, [r1]
	adds r1, #2
	movs r0, #0xc0
	lsls r0, r0, #2
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x4a
	movs r4, #0xe
	strb r4, [r0]
	adds r0, #0x12
	strb r6, [r0]
	subs r0, #0x11
	movs r3, #0x40
	strb r3, [r0]
	adds r0, #0x35
	strh r5, [r0]
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r0, #0x38
	adds r1, #0x3c
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x4c
	strh r0, [r1]
	adds r1, #2
	ldr r0, _0800ACA4 @ =0x00000301
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x8a
	strb r4, [r0]
	adds r0, #0x12
	strb r6, [r0]
	subs r0, #0x11
	strb r3, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800AC98: .4byte 0x03002C30
_0800AC9C: .4byte 0x0000C804
_0800ACA0: .4byte 0x03000440
_0800ACA4: .4byte 0x00000301
	.syntax divided
