	.syntax unified

	thumb_func_start battle_scene_dispatch
battle_scene_dispatch: @ 0x0806E2D4
	push {lr}
	ldr r1, _0806E2F0 @ =0x08485F38
	ldr r0, _0806E2F4 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	bl scene_transition_countdown_tick
	pop {r0}
	bx r0
	.align 2, 0
_0806E2F0: .4byte 0x08485F38
_0806E2F4: .4byte 0x0300137C
	.syntax divided
