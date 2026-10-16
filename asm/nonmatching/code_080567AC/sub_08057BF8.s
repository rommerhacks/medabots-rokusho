	.syntax unified

	thumb_func_start sub_08057BF8
sub_08057BF8: @ 0x08057BF8
	push {lr}
	bl init_cursor_state
	bl sub_0804A1C4
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
