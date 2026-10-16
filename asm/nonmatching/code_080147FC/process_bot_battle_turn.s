	.syntax unified

	thumb_func_start process_bot_battle_turn
	.global process_bot_battle_turn
process_bot_battle_turn: @ 0x08015358
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08015374 @ =0x03000590
	lsls r1, r4, #8
	adds r1, r1, r0
	adds r1, #0xc9
	ldrb r0, [r1]
	cmp r0, #0x2c
	bne _08015378
	adds r0, r4, #0
	bl select_bot_battle_action
	b _08015388
	.align 2, 0
_08015374: .4byte 0x03000590
_08015378:
	adds r0, r4, #0
	bl battle_dispatch_action_by_type
	cmp r0, #0
	beq _08015388
	adds r0, r4, #0
	bl select_bot_battle_action
_08015388:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
