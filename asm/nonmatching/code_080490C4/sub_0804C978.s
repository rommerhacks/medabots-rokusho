	.syntax unified

	thumb_func_start sub_0804C978
sub_0804C978: @ 0x0804C978
	push {lr}
	movs r0, #4
	movs r1, #0
	bl dispatch_jump_table_29
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
