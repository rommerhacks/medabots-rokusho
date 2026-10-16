	.syntax unified

	thumb_func_start select_battle_pending_action
select_battle_pending_action: @ 0x0803301C
	push {r4, r5, r6, lr}
	bl rng_lookup_table_value
	adds r4, r0, #0
	bl rng_next_080424B8
	adds r2, r0, #0
	movs r0, #1
	ands r2, r0
	movs r3, #0
	ldr r5, _08033044 @ =0x03001861
	adds r6, r5, #0
	subs r6, #0x61
_08033036:
	adds r1, r4, r5
	ldrb r0, [r1]
	cmp r0, #0
	beq _08033048
	subs r0, #1
	b _0803306E
	.align 2, 0
_08033044: .4byte 0x03001861
_08033048:
	cmp r2, #0
	beq _08033056
	adds r4, #1
	cmp r4, #2
	bls _08033060
	movs r4, #0
	b _08033060
_08033056:
	cmp r4, #0
	bne _0803305E
	movs r4, #2
	b _08033060
_0803305E:
	subs r4, #1
_08033060:
	adds r3, #1
	cmp r3, #2
	bls _08033036
	adds r0, r6, #0
	adds r0, #0x61
	adds r0, r4, r0
	ldrb r0, [r0]
_0803306E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.syntax divided
