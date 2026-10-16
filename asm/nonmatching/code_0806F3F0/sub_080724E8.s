	.syntax unified

	thumb_func_start sub_080724E8
sub_080724E8: @ 0x080724E8
	push {lr}
	bl sound_channel_check_and_advance
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
