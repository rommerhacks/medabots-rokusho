	.syntax unified

	thumb_func_start toggle_battle_team_side
toggle_battle_team_side: @ 0x080187A8
	push {lr}
	ldr r2, _080187D0 @ =0x03000440
	adds r1, r2, #0
	adds r1, #0x3d
	movs r0, #0
	strb r0, [r1]
	adds r2, #0x3c
	ldrb r0, [r2]
	movs r1, #1
	eors r0, r1
	strb r0, [r2]
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	movs r1, #1
	bl position_battle_team_cursors
	pop {r0}
	bx r0
	.align 2, 0
_080187D0: .4byte 0x03000440
	.syntax divided
