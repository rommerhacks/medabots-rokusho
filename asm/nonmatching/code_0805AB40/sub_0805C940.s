	.syntax unified

	thumb_func_start sub_0805C940
sub_0805C940: @ 0x0805C940
	push {lr}
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _0805C950
	movs r0, #0xa
	bl dispatch_by_index_0476e8
_0805C950:
	pop {r0}
	bx r0
	.syntax divided
