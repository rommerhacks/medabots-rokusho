	.syntax unified

	thumb_func_start sub_08047BC0
	.global sub_08047BC0
sub_08047BC0: @ 0x08047BC0
	push {lr}
	bl sound_stop_all_with_fade_guard
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
