	.syntax unified

	thumb_func_start team_select_exit_battle
team_select_exit_battle: @ 0x08004840
	push {lr}
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r0, _08004864 @ =0x03000440
	adds r0, #0x96
	movs r1, #0
	strb r1, [r0]
	ldr r0, _08004868 @ =0x03000430
	str r1, [r0]
	ldr r2, _0800486C @ =0x03002B8C
	movs r0, #7
	str r0, [r2]
	ldr r0, _08004870 @ =0x0300137C
	str r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08004864: .4byte 0x03000440
_08004868: .4byte 0x03000430
_0800486C: .4byte 0x03002B8C
_08004870: .4byte 0x0300137C
	.syntax divided
