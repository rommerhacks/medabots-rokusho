	.syntax unified

	thumb_func_start accumulate_battle_speed_value
	.global accumulate_battle_speed_value
accumulate_battle_speed_value: @ 0x08035844
	push {r4, lr}
	ldr r4, _08035878 @ =0x03001800
	adds r4, #0xee
	ldr r1, _0803587C @ =0x03000590
	lsls r2, r0, #8
	adds r2, r2, r1
	ldrh r1, [r4]
	ldrb r2, [r2, #5]
	adds r1, r1, r2
	strh r1, [r4]
	bl calc_bot_matching_part_power
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	bl rng_next_080424B8
	movs r1, #7
	ands r0, r1
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035878: .4byte 0x03001800
_0803587C: .4byte 0x03000590
	.syntax divided
