	.syntax unified

	thumb_func_start dispatch_game_mode_handler
dispatch_game_mode_handler: @ 0x080682AC
	push {lr}
	ldr r1, _080682C4 @ =0x08485C48
	ldr r0, _080682C8 @ =0x03002B8C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_080682C4: .4byte 0x08485C48
_080682C8: .4byte 0x03002B8C
	.syntax divided
