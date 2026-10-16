	.syntax unified

	thumb_func_start get_item_quantity_by_id
	.global get_item_quantity_by_id
get_item_quantity_by_id: @ 0x08042278
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	movs r1, #0xfc
	lsls r1, r1, #0x16
	ands r1, r0
	lsrs r4, r1, #0x18
	movs r1, #0
	ldr r3, _080422A4 @ =0x03002BA0
	movs r6, #0x80
	movs r5, #0x7f
_0804228C:
	ldrb r2, [r3]
	adds r0, r6, #0
	ands r0, r2
	cmp r0, #0
	beq _080422A8
	adds r0, r5, #0
	ands r0, r2
	cmp r0, r4
	bne _080422A8
	ldrb r0, [r3, #1]
	b _080422B2
	.align 2, 0
_080422A4: .4byte 0x03002BA0
_080422A8:
	adds r3, #2
	adds r1, #1
	cmp r1, #0x3f
	bls _0804228C
	movs r0, #0
_080422B2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.syntax divided
