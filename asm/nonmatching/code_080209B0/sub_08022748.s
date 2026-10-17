	.syntax unified

	thumb_func_start sub_08022748
sub_08022748: @ 0x08022748
	push {r4, r5, r6, lr}
	ldr r0, _080227B8 @ =0x03000590
	ldr r6, _080227BC @ =0x03001800
	movs r1, #0x87
	adds r1, r1, r6
	mov ip, r1
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r1, r1, r0
	adds r1, #0xbd
	ldrb r3, [r1]
	movs r2, #8
	movs r5, #0
	orrs r2, r3
	strb r2, [r1]
	mov r2, ip
	ldrb r3, [r2]
	lsls r3, r3, #8
	adds r4, r3, r0
	adds r1, r6, #0
	adds r1, #0xa7
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r1, r1, r3
	adds r1, r1, r0
	adds r1, #0x49
	ldrb r1, [r1]
	adds r4, #0xdf
	strb r1, [r4]
	mov r2, ip
	ldrb r1, [r2]
	lsls r1, r1, #8
	adds r1, r1, r0
	adds r1, #0xd8
	strh r5, [r1]
	ldrb r1, [r2]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, #0xd8
	adds r1, r6, #0
	adds r1, #0xec
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #0xff
	bl sub_08035740
	adds r1, r6, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080227B8: .4byte 0x03000590
_080227BC: .4byte 0x03001800
	.syntax divided
