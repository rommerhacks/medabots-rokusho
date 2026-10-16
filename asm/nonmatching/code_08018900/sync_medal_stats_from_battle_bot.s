	.syntax unified

	thumb_func_start sync_medal_stats_from_battle_bot
sync_medal_stats_from_battle_bot: @ 0x0801BF14
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r5, _0801BF5C @ =0x03000590
	lsls r4, r4, #8
	adds r0, r4, r5
	ldrb r0, [r0, #1]
	bl find_medal_slot_by_id
	subs r0, #1
	movs r7, #0
	ldr r2, _0801BF60 @ =0x03000BE0
	lsls r0, r0, #6
	adds r3, r5, #0
	adds r3, #0x28
	adds r1, r2, #0
	adds r1, #0x28
	adds r6, r0, r1
	adds r2, #0x20
	adds r5, #0x20
	adds r3, r4, r3
	adds r4, r4, r5
	adds r1, r0, r2
_0801BF40:
	ldrb r0, [r4]
	strb r0, [r1]
	ldrb r0, [r3]
	strb r0, [r6]
	adds r6, #1
	adds r3, #1
	adds r4, #1
	adds r1, #1
	adds r7, #1
	cmp r7, #7
	bls _0801BF40
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801BF5C: .4byte 0x03000590
_0801BF60: .4byte 0x03000BE0
	.syntax divided
