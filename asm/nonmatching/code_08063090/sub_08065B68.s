	.syntax unified

	thumb_func_start sub_08065B68
sub_08065B68: @ 0x08065B68
	push {lr}
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _08065B78
	movs r0, #7
	bl dispatch_by_index_0476e8
_08065B78:
	pop {r0}
	bx r0
	.syntax divided
