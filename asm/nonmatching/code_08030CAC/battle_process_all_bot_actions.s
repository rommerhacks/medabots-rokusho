	.syntax unified

	thumb_func_start battle_process_all_bot_actions
	.global battle_process_all_bot_actions
battle_process_all_bot_actions: @ 0x08031A3C
	push {r4, r5, lr}
	ldr r1, _08031A6C @ =0x03001800
	adds r2, r1, #0
	adds r2, #0x5c
	movs r3, #0
	strb r0, [r2]
	adds r1, #0x5d
	strb r3, [r1]
	movs r4, #0
	adds r5, r1, #0
_08031A50:
	bl battle_execute_action_selection
	bl call_bot_action_handler
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	adds r4, #1
	cmp r4, #2
	bls _08031A50
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08031A6C: .4byte 0x03001800
	.syntax divided
