	.syntax unified

	thumb_func_start medapart_add_quantity
	.global medapart_add_quantity
medapart_add_quantity: @ 0x0804213C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	ldr r4, _08042164 @ =0x03004C40
	lsls r3, r1, #4
	subs r3, r3, r1
	lsls r3, r3, #4
	lsrs r0, r0, #0x17
	adds r3, r3, r0
	adds r3, r3, r4
	lsrs r2, r2, #0x18
	ldrb r0, [r3]
	adds r2, r2, r0
	cmp r2, #0x63
	ble _08042168
	movs r0, #0x63
	strb r0, [r3]
	b _0804216A
	.align 2, 0
_08042164: .4byte 0x03004C40
_08042168:
	strb r2, [r3]
_0804216A:
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
