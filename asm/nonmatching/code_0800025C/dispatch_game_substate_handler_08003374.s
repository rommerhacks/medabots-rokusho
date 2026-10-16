	.syntax unified

	thumb_func_start dispatch_game_substate_handler_08003374
dispatch_game_substate_handler_08003374: @ 0x08003374
	push {lr}
	ldr r1, _0800338C @ =0x083AC2D4
	ldr r0, _08003390 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0800338C: .4byte 0x083AC2D4
_08003390: .4byte 0x0300137C
	.syntax divided
