	.syntax unified

	thumb_func_start sub_0804DCB8
sub_0804DCB8: @ 0x0804DCB8
	push {lr}
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _0804DCC6
	bl sub_08050244
_0804DCC6:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
