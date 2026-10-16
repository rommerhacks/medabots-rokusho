	.syntax unified

	thumb_func_start find_random_available_part_slot
	.global find_random_available_part_slot
find_random_available_part_slot: @ 0x0803325C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl rng_next_080424B8
	adds r5, r0, #0
	movs r0, #3
	ands r5, r0
	bl rng_next_080424B8
	adds r1, r0, #0
	movs r0, #1
	ands r1, r0
	movs r2, #0
	ldr r6, _08033294 @ =0x03000590
	movs r3, #3
	lsls r4, r4, #8
_0803327C:
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r4
	adds r0, r0, r6
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	bne _08033298
	adds r0, r5, #1
	b _080332AC
	.align 2, 0
_08033294: .4byte 0x03000590
_08033298:
	cmp r1, #0
	beq _080332A0
	adds r5, #1
	b _080332A2
_080332A0:
	subs r5, #1
_080332A2:
	ands r5, r3
	adds r2, #1
	cmp r2, #3
	bls _0803327C
	movs r0, #0
_080332AC:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
