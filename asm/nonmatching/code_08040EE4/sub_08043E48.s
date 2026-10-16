	.syntax unified

	thumb_func_start sub_08043E48
	.global sub_08043E48
sub_08043E48: @ 0x08043E48
	push {lr}
	bl update_scroll_movement_a
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
