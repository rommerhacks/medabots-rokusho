	.syntax unified

	thumb_func_start sub_0801425C
sub_0801425C: @ 0x0801425C
	push {lr}
	bl select_battle_music
	movs r0, #0
	bl init_battle_action_select_ui
	bl sub_08018BD4
	ldr r1, _08014278 @ =0x0300137C
	movs r0, #0x44
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08014278: .4byte 0x0300137C
	.syntax divided
