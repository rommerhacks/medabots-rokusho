	.syntax unified

	thumb_func_start sub_08026484
sub_08026484: @ 0x08026484
	push {r4, r5, r6, r7, lr}
	ldr r4, _080264C0 @ =0x03001800
	adds r6, r4, #0
	adds r6, #0x87
	ldrb r0, [r6]
	adds r7, r4, #0
	adds r7, #0xa7
	ldrb r1, [r7]
	bl calc_battle_action_speed
	ldrb r0, [r6]
	bl apply_battle_bot_damage_reduction
	bl decrement_battle_timer_and_check_zero
	adds r5, r0, #0
	cmp r5, #0
	beq _080264C4
	adds r1, r4, #0
	adds r1, #0xab
	movs r0, #1
	strb r0, [r1]
	subs r1, #5
	movs r0, #0x1a
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	b _080264DC
	.align 2, 0
_080264C0: .4byte 0x03001800
_080264C4:
	bl sub_08036270
	ldrb r0, [r6]
	ldrb r1, [r7]
	bl calc_battle_stat_ratio
	adds r0, r4, #0
	adds r0, #0xab
	strb r5, [r0]
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #4
_080264DC:
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
