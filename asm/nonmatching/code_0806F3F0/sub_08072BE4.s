	.syntax unified

	thumb_func_start sub_08072BE4
sub_08072BE4: @ 0x08072BE4
	push {lr}
	bl sound_channel_finish_and_callback
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
