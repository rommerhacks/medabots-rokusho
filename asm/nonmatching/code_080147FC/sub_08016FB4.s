	.syntax unified

	thumb_func_start sub_08016FB4
	.global sub_08016FB4
sub_08016FB4: @ 0x08016FB4
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r0, _08017000 @ =0x03002C30
	movs r6, #0x90
	movs r5, #0x40
	adds r3, r0, #4
_08016FC0:
	ldrb r0, [r3, #5]
	adds r0, #8
	strb r0, [r3, #5]
	ldrb r0, [r3, #4]
	adds r0, #8
	strb r0, [r3, #4]
	ldrb r2, [r3, #5]
	movs r1, #0
	ldrsh r0, [r3, r1]
	subs r0, r6, r0
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	subs r0, r5, r0
	cmp r2, r0
	ble _08016FF2
	strb r0, [r3, #5]
	movs r1, #0
	ldrsh r0, [r3, r1]
	subs r0, r6, r0
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	subs r0, r5, r0
	strb r0, [r3, #4]
_08016FF2:
	adds r3, #0x40
	adds r4, #1
	cmp r4, #5
	bls _08016FC0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08017000: .4byte 0x03002C30
	.syntax divided
