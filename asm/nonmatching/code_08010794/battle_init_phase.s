	.syntax unified

	thumb_func_start battle_init_phase
battle_init_phase: @ 0x080129C8
	push {r4, lr}
	ldr r1, _08012A14 @ =0x03000440
	ldr r0, _08012A18 @ =0x00000139
	adds r2, r1, r0
	movs r0, #0
	strb r0, [r2]
	movs r3, #0x9d
	lsls r3, r3, #1
	adds r2, r1, r3
	strb r0, [r2]
	adds r4, r1, #0
	adds r4, #0x89
	ldrb r0, [r4]
	cmp r0, #1
	beq _080129F6
	bl clear_battle_bot_array
	bl count_active_battle_bots
	bl battle_setup_bot_entry
	bl init_battle_entities_and_labels
_080129F6:
	bl battle_process_all_bots_actions
	ldrb r0, [r4]
	cmp r0, #1
	beq _08012A04
	bl sub_08018A18
_08012A04:
	ldr r1, _08012A1C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08012A14: .4byte 0x03000440
_08012A18: .4byte 0x00000139
_08012A1C: .4byte 0x0300137C
	.syntax divided
