	.syntax unified

	thumb_func_start sub_08047BA8
	.global sub_08047BA8
sub_08047BA8: @ 0x08047BA8
	push {lr}
	bl play_sound_effect
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
