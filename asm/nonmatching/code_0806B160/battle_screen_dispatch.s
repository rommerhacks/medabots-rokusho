	.syntax unified

	thumb_func_start battle_screen_dispatch
battle_screen_dispatch: @ 0x0806B5B0
	push {lr}
	ldr r1, _0806B5C8 @ =0x08485E5C
	ldr r0, _0806B5CC @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0806B5C8: .4byte 0x08485E5C
_0806B5CC: .4byte 0x0300137C
	.syntax divided
