	.syntax unified

	thumb_func_start battle_process_bot_actions_for_side
	.global battle_process_bot_actions_for_side
battle_process_bot_actions_for_side: @ 0x0801531C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r6, #0
	ldr r0, _08015354 @ =0x03000590
	lsls r1, r7, #8
	adds r0, #0x40
	adds r5, r1, r0
_0801532A:
	adds r4, r7, r6
	ldrb r0, [r5]
	cmp r0, #0
	beq _08015342
	adds r0, r4, #0
	bl battle_dispatch_action_by_type
	cmp r0, #0
	beq _08015342
	adds r0, r4, #0
	bl select_bot_battle_action
_08015342:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r6, #1
	cmp r6, #2
	bls _0801532A
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015354: .4byte 0x03000590
	.syntax divided
