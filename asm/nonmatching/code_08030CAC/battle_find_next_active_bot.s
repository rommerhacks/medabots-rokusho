	.syntax unified

	thumb_func_start battle_find_next_active_bot
	.global battle_find_next_active_bot
battle_find_next_active_bot: @ 0x080330F4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl rng_lookup_table_value
	adds r4, r0, #0
	bl rng_next_080424B8
	adds r2, r0, #0
	movs r0, #1
	ands r2, r0
	movs r3, #0
	ldr r6, _08033134 @ =0x03000590
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r1, r0, #3
_08033112:
	lsls r0, r5, #8
	adds r0, r1, r0
	adds r0, r0, r6
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803314C
	cmp r2, #0
	beq _08033138
	adds r1, #0x18
	adds r4, #1
	cmp r4, #2
	bls _08033146
	movs r1, #0
	movs r4, #0
	b _08033146
	.align 2, 0
_08033134: .4byte 0x03000590
_08033138:
	cmp r4, #0
	bne _08033142
	movs r1, #0x30
	movs r4, #2
	b _08033146
_08033142:
	subs r1, #0x18
	subs r4, #1
_08033146:
	adds r3, #1
	cmp r3, #2
	bls _08033112
_0803314C:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.syntax divided
