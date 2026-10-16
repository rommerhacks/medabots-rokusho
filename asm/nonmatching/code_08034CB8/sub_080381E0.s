	.syntax unified

	thumb_func_start sub_080381E0
sub_080381E0: @ 0x080381E0
	push {r4, r5, lr}
	ldr r1, _08038208 @ =0x03002C30
	ldr r2, _0803820C @ =0x03000440
	ldr r3, _08038210 @ =0x0000012F
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r3, r0, r1
	adds r0, r3, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	adds r4, r1, #0
	cmp r0, #0x23
	bne _08038214
	adds r1, r3, #0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0803824A
	.align 2, 0
_08038208: .4byte 0x03002C30
_0803820C: .4byte 0x03000440
_08038210: .4byte 0x0000012F
_08038214:
	ldr r0, _08038228 @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0803822C
	ldrh r0, [r3, #0x18]
	subs r0, #0x10
	b _08038230
	.align 2, 0
_08038228: .4byte 0x03001800
_0803822C:
	ldrh r0, [r3, #0x18]
	adds r0, #0x10
_08038230:
	ldr r5, _08038250 @ =0x000003FF
	adds r1, r5, #0
	ands r0, r1
	strh r0, [r3, #0x18]
	ldr r1, _08038254 @ =0x0000012F
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x2d
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
_0803824A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08038250: .4byte 0x000003FF
_08038254: .4byte 0x0000012F
	.syntax divided
