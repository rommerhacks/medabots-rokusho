	.syntax unified

	thumb_func_start sub_08065908
sub_08065908: @ 0x08065908
	push {lr}
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _08065918
	movs r0, #8
	bl dispatch_by_index_0476e8
_08065918:
	pop {r0}
	bx r0
	.syntax divided
