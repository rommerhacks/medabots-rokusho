	.syntax unified

	thumb_func_start find_medal_slot_by_id
	.global find_medal_slot_by_id
find_medal_slot_by_id: @ 0x08041D3C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r3, #0
	movs r5, #0x80
	ldr r2, _08041D5C @ =0x03000BE0
_08041D48:
	ldrb r1, [r2]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _08041D60
	ldrb r0, [r2, #1]
	cmp r0, r4
	bne _08041D60
	adds r0, r3, #1
	b _08041D6A
	.align 2, 0
_08041D5C: .4byte 0x03000BE0
_08041D60:
	adds r2, #0x40
	adds r3, #1
	cmp r3, #0x1d
	bls _08041D48
	movs r0, #0
_08041D6A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.syntax divided
