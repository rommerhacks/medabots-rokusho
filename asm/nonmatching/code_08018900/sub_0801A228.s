	.syntax unified

	thumb_func_start sub_0801A228
	.global sub_0801A228
sub_0801A228: @ 0x0801A228
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r2, _0801A270 @ =0x03002C30
	ldr r5, _0801A274 @ =0x083AD3B3
	lsls r0, r0, #8
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r1, r0, #4
	adds r1, r1, r2
	adds r0, #0x20
	adds r3, r0, r2
_0801A240:
	ldrb r2, [r1, #0x1d]
	adds r0, r2, #0
	cmp r0, #0xff
	beq _0801A286
	cmp r0, #0x1f
	bhi _0801A27C
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	bne _0801A278
	ldrb r0, [r1, #0x1d]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r6, [r1]
	adds r0, r0, r6
	strh r0, [r1]
	ldrb r0, [r1, #5]
	adds r0, #2
	strb r0, [r1, #5]
	adds r0, r2, #1
	strb r0, [r1, #0x1d]
	b _0801A27C
	.align 2, 0
_0801A270: .4byte 0x03002C30
_0801A274: .4byte 0x083AD3B3
_0801A278:
	subs r0, #1
	strb r0, [r3]
_0801A27C:
	adds r1, #0x40
	adds r3, #0x40
	adds r4, #1
	cmp r4, #2
	bls _0801A240
_0801A286:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
