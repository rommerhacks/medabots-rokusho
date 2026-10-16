	.syntax unified

	thumb_func_start calc_battle_action_speed
	.global calc_battle_action_speed
calc_battle_action_speed: @ 0x0803579C
	push {r4, r5, r6, r7, lr}
	ldr r2, _080357F8 @ =0x03001800
	adds r5, r2, #0
	adds r5, #0xe8
	ldr r7, _080357FC @ =0x03000590
	lsls r4, r1, #1
	adds r4, r4, r1
	lsls r4, r4, #3
	lsls r6, r0, #8
	adds r4, r4, r6
	adds r4, r4, r7
	adds r2, r4, #0
	adds r2, #0x4d
	ldrh r1, [r5]
	ldrb r2, [r2]
	adds r1, r1, r2
	strh r1, [r5]
	bl calc_bot_matching_part_power
	ldrh r1, [r5]
	adds r1, r1, r0
	strh r1, [r5]
	bl rng_next_080424B8
	movs r1, #7
	ands r0, r1
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	adds r4, #0x4a
	ldrb r1, [r4]
	adds r1, r1, r6
	adds r2, r7, #0
	adds r2, #0x20
	adds r1, r1, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5]
	ldrb r0, [r4]
	bl sub_08042B80
	cmp r0, #0
	beq _08035800
	adds r1, r6, r7
	adds r1, #0xa6
	b _08035804
	.align 2, 0
_080357F8: .4byte 0x03001800
_080357FC: .4byte 0x03000590
_08035800:
	adds r1, r6, r7
	adds r1, #0xa5
_08035804:
	ldrh r0, [r5]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
