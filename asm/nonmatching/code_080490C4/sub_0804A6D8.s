	.syntax unified

	thumb_func_start sub_0804A6D8
sub_0804A6D8: @ 0x0804A6D8
	push {lr}
	bl init_cursor_state
	bl sub_0804A1C4
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
