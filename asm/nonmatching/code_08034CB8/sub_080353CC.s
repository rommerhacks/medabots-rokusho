	.syntax unified

	thumb_func_start sub_080353CC
	.global sub_080353CC
sub_080353CC: @ 0x080353CC
	ldr r1, _08035404 @ =0x03002C30
	lsls r0, r0, #6
	adds r3, r0, r1
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0803540C
	adds r2, r3, #0
	adds r2, #0x23
	ldrb r0, [r2]
	cmp r0, #0x20
	beq _0803540C
	ldr r1, _08035408 @ =0x083AF310
	adds r0, r0, r1
	ldrb r1, [r0]
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	strh r0, [r3, #4]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	movs r0, #0
	b _0803540E
	.align 2, 0
_08035404: .4byte 0x03002C30
_08035408: .4byte 0x083AF310
_0803540C:
	movs r0, #1
_0803540E:
	bx lr
	.syntax divided
