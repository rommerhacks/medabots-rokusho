	.syntax unified

	thumb_func_start dispatch_menu_substate_handler
dispatch_menu_substate_handler: @ 0x0800B890
	push {lr}
	ldr r1, _0800B8A8 @ =0x083AC8DC
	ldr r0, _0800B8AC @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0800B8A8: .4byte 0x083AC8DC
_0800B8AC: .4byte 0x0300137C
	.syntax divided
