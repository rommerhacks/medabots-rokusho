	.syntax unified

	thumb_func_start item_add_quantity
	.global item_add_quantity
item_add_quantity: @ 0x080422B8
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	movs r1, #0xfc
	lsls r1, r1, #0x16
	ands r1, r0
	lsrs r7, r1, #0x18
	movs r6, #0
	ldr r1, _080422FC @ =0x03002BA0
	movs r0, #0x80
	adds r3, r7, #0
	orrs r3, r0
	adds r4, r1, #1
_080422D4:
	ldrb r2, [r1]
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _08042300
	movs r0, #0x7f
	ands r0, r2
	cmp r0, r7
	bne _08042306
	ldrb r0, [r1, #1]
	adds r0, r5, r0
	strb r0, [r1, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x63
	bls _08042310
	movs r0, #0x63
	strb r0, [r1, #1]
	b _08042310
	.align 2, 0
_080422FC: .4byte 0x03002BA0
_08042300:
	strb r3, [r1]
	strb r5, [r4]
	b _08042310
_08042306:
	adds r4, #2
	adds r1, #2
	adds r6, #1
	cmp r6, #0x3f
	bls _080422D4
_08042310:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
