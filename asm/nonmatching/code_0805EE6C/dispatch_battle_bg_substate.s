	.syntax unified

	thumb_func_start dispatch_battle_bg_substate
dispatch_battle_bg_substate: @ 0x08060520
	push {lr}
	ldr r1, _08060538 @ =0x08483DA0
	ldr r0, _0806053C @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_08060538: .4byte 0x08483DA0
_0806053C: .4byte 0x0300137C
	.syntax divided
