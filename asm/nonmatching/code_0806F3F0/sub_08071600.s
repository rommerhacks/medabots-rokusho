	.syntax unified

	thumb_func_start sub_08071600
sub_08071600: @ 0x08071600
	push {lr}
	movs r0, #0
	bl play_song
	movs r0, #3
	bl sub_08047850
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
