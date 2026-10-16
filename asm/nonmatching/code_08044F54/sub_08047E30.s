	.syntax unified

	thumb_func_start sub_08047E30
	.global sub_08047E30
sub_08047E30: @ 0x08047E30
	push {lr}
	bl sub_08042218
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
