	.syntax unified

	thumb_func_start dispatch_game_substate_handler_0806DFA4
dispatch_game_substate_handler_0806DFA4: @ 0x0806DFA4
	push {lr}
	ldr r1, _0806DFBC @ =0x08485F1C
	ldr r0, _0806DFC0 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0806DFBC: .4byte 0x08485F1C
_0806DFC0: .4byte 0x0300137C
	.syntax divided
