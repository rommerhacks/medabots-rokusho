	.syntax unified

	thumb_func_start sub_080704D0
sub_080704D0: @ 0x080704D0
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r1, _080704F0 @ =0x03002C30
	lsls r0, r3, #6
	adds r2, r0, r1
	ldrb r0, [r2, #8]
	adds r4, r1, #0
	cmp r0, #0x3f
	bls _080704F4
	ldrb r0, [r2, #9]
	cmp r0, #0x3f
	bls _08070506
	movs r0, #0
	b _08070524
	.align 2, 0
_080704F0: .4byte 0x03002C30
_080704F4:
	adds r0, #8
	strb r0, [r2, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bls _08070516
	movs r0, #0x40
	strb r0, [r2, #8]
	b _08070516
_08070506:
	adds r0, #8
	strb r0, [r2, #9]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bls _08070516
	movs r0, #0x40
	strb r0, [r2, #9]
_08070516:
	lsls r1, r3, #6
	adds r1, r1, r4
	adds r1, #0x21
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #1
_08070524:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
