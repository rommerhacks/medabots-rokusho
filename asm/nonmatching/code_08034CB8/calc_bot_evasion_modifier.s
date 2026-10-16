	.syntax unified

	thumb_func_start calc_bot_evasion_modifier
	.global calc_bot_evasion_modifier
calc_bot_evasion_modifier: @ 0x08035528
	push {r4, r5, r6, lr}
	ldr r1, _08035564 @ =0x03000590
	lsls r0, r0, #8
	adds r6, r0, r1
	adds r1, r6, #0
	adds r1, #0xe0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803555C
	ldr r5, _08035568 @ =0x083AF330
	subs r0, #1
	bl sub_08035590
	adds r4, r0, #0
	bl rng_next_080424B8
	lsls r4, r4, #3
	movs r1, #7
	ands r1, r0
	adds r4, r4, r1
	adds r4, r4, r5
	ldrb r0, [r4]
	adds r0, #1
	adds r1, r6, #0
	adds r1, #0xe1
	strb r0, [r1]
_0803555C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08035564: .4byte 0x03000590
_08035568: .4byte 0x083AF330
	.syntax divided
