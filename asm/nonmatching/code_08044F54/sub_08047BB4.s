	.syntax unified

	thumb_func_start sub_08047BB4
	.global sub_08047BB4
sub_08047BB4: @ 0x08047BB4
	push {lr}
	bl play_song
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
