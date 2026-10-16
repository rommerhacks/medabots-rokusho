	.syntax unified

	thumb_func_start sub_08057540
sub_08057540: @ 0x08057540
	push {lr}
	movs r0, #0x40
	movs r1, #0
	bl sub_08047878
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
