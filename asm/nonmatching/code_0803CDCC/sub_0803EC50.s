	.syntax unified

	thumb_func_start sub_0803EC50
sub_0803EC50: @ 0x0803EC50
	push {r4, lr}
	ldr r3, _0803EC80 @ =0x03002C30
	adds r0, r3, #0
	adds r0, #0xa4
	ldrb r0, [r0]
	adds r2, r3, #0
	adds r2, #0xa0
	ldrb r1, [r2]
	adds r0, r0, r1
	lsrs r4, r0, #2
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0xa5
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803EC84
	adds r0, r3, #0
	adds r0, #0x84
	ldrh r1, [r0]
	subs r1, r1, r4
	b _0803EC8C
	.align 2, 0
_0803EC80: .4byte 0x03002C30
_0803EC84:
	adds r0, r3, #0
	adds r0, #0x84
	ldrh r1, [r0]
	adds r1, r1, r4
_0803EC8C:
	movs r2, #0xff
	ands r1, r2
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
