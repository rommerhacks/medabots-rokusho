	.syntax unified

	thumb_func_start select_random_battle_target
select_random_battle_target: @ 0x08033090
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl rng_lookup_table_value
	adds r4, r0, #0
	bl rng_next_080424B8
	adds r2, r0, #0
	movs r0, #1
	ands r2, r0
	movs r3, #0
	ldr r6, _080330BC @ =0x03000590
_080330A8:
	adds r1, r5, r4
	lsls r0, r1, #8
	adds r0, r0, r6
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _080330C0
	adds r0, r1, #0
	b _080330E0
	.align 2, 0
_080330BC: .4byte 0x03000590
_080330C0:
	cmp r2, #0
	beq _080330CE
	adds r4, #1
	cmp r4, #2
	bls _080330D8
	movs r4, #0
	b _080330D8
_080330CE:
	cmp r4, #0
	bne _080330D6
	movs r4, #2
	b _080330D8
_080330D6:
	subs r4, #1
_080330D8:
	adds r3, #1
	cmp r3, #2
	bls _080330A8
	adds r0, r5, r4
_080330E0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
