	.syntax unified

	thumb_func_start medal_remove_by_id
	.global medal_remove_by_id
medal_remove_by_id: @ 0x08041FE4
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r2, #0
	ldr r5, _08042014 @ =0x03000BE0
	adds r3, r5, #0
_08041FF0:
	ldrb r1, [r5]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08042018
	ldrb r0, [r5, #1]
	cmp r0, r4
	bne _08042018
	movs r4, #0x1f
	ands r4, r1
	adds r0, r3, #0
	movs r1, #0x40
	movs r2, #0
	bl sub_0803F624
	strb r4, [r5]
	b _08042022
	.align 2, 0
_08042014: .4byte 0x03000BE0
_08042018:
	adds r5, #0x40
	adds r3, #0x40
	adds r2, #1
	cmp r2, #0x1d
	bls _08041FF0
_08042022:
	pop {r4, r5}
	pop {r0}
	bx r0
	.syntax divided
