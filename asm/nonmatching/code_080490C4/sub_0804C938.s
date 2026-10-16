	.syntax unified

	thumb_func_start sub_0804C938
sub_0804C938: @ 0x0804C938
	push {lr}
	movs r0, #2
	movs r1, #0
	bl dispatch_jump_table_29
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
