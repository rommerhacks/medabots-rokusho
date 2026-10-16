	.syntax unified

	thumb_func_start sub_0806DEAC
sub_0806DEAC: @ 0x0806DEAC
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r2, _0806DECC @ =0x03002C30
	lsls r0, r4, #6
	adds r3, r0, r2
	adds r0, r3, #0
	adds r0, #0x22
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0806DED0
	movs r0, #0x73
	b _0806DED2
	.align 2, 0
_0806DECC: .4byte 0x03002C30
_0806DED0:
	movs r0, #0xc8
_0806DED2:
	strh r0, [r3, #4]
	lsls r1, r4, #6
	adds r1, r1, r2
	adds r1, #0x22
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
