	.syntax unified

	thumb_func_start sub_08038258
sub_08038258: @ 0x08038258
	push {r4, r5, lr}
	ldr r0, _08038284 @ =0x03002C30
	ldr r2, _08038288 @ =0x03000440
	ldr r1, _0803828C @ =0x0000012F
	adds r1, r1, r2
	mov ip, r1
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	adds r3, r1, #0
	adds r3, #0x2d
	ldrb r3, [r3]
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r3, #0x46
	bne _08038290
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _080382E6
	.align 2, 0
_08038284: .4byte 0x03002C30
_08038288: .4byte 0x03000440
_0803828C: .4byte 0x0000012F
_08038290:
	movs r2, #1
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	beq _080382A0
	ldrh r0, [r1, #4]
	adds r0, #1
	strh r0, [r1, #4]
_080382A0:
	ldr r0, _080382BC @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _080382C0
	mov r3, ip
	ldrb r0, [r3]
	lsls r0, r0, #6
	adds r0, r0, r4
	ldrh r1, [r0, #0x18]
	subs r1, #0x10
	b _080382CC
	.align 2, 0
_080382BC: .4byte 0x03001800
_080382C0:
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #6
	adds r0, r0, r4
	ldrh r1, [r0, #0x18]
	adds r1, #0x10
_080382CC:
	ldr r3, _080382EC @ =0x000003FF
	adds r2, r3, #0
	ands r1, r2
	strh r1, [r0, #0x18]
	ldr r1, _080382F0 @ =0x0000012F
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x2d
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
_080382E6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080382EC: .4byte 0x000003FF
_080382F0: .4byte 0x0000012F
	.syntax divided
