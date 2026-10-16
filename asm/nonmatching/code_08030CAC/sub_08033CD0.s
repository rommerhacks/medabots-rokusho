	.syntax unified

	thumb_func_start sub_08033CD0
sub_08033CD0: @ 0x08033CD0
	push {lr}
	bl battle_begin_action_phase
	bl sub_08034F08
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
