	.syntax unified

	thumb_func_start battle_execute_action_selection
battle_execute_action_selection: @ 0x08031A70
	push {r4, lr}
	bl clear_battle_action_selection
	ldr r4, _08031AB0 @ =0x03001861
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl sub_0803F624
	ldr r3, _08031AB4 @ =0x083AED20
	ldr r2, _08031AB8 @ =0x03000590
	subs r0, r4, #4
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	subs r4, #5
	ldrb r1, [r4]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	adds r0, #0x49
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	bl _call_via_r0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08031AB0: .4byte 0x03001861
_08031AB4: .4byte 0x083AED20
_08031AB8: .4byte 0x03000590
	.syntax divided
