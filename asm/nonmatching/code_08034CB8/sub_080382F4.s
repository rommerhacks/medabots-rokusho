	.syntax unified

	thumb_func_start sub_080382F4
sub_080382F4: @ 0x080382F4
	push {r4, r5, lr}
	ldr r1, _0803831C @ =0x03002C30
	ldr r2, _08038320 @ =0x03000440
	ldr r3, _08038324 @ =0x0000012F
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r3, r0, r1
	adds r0, r3, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	adds r4, r1, #0
	cmp r0, #0x5a
	bne _08038328
	adds r1, r3, #0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0803835E
	.align 2, 0
_0803831C: .4byte 0x03002C30
_08038320: .4byte 0x03000440
_08038324: .4byte 0x0000012F
_08038328:
	ldr r0, _0803833C @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08038340
	ldrh r0, [r3, #0x18]
	subs r0, #0x10
	b _08038344
	.align 2, 0
_0803833C: .4byte 0x03001800
_08038340:
	ldrh r0, [r3, #0x18]
	adds r0, #0x10
_08038344:
	ldr r5, _08038364 @ =0x000003FF
	adds r1, r5, #0
	ands r0, r1
	strh r0, [r3, #0x18]
	ldr r1, _08038368 @ =0x0000012F
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x2d
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
_0803835E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08038364: .4byte 0x000003FF
_08038368: .4byte 0x0000012F
	.syntax divided
