	.syntax unified

	thumb_func_start sub_08057588
sub_08057588: @ 0x08057588
	push {lr}
	movs r0, #6
	movs r1, #0
	bl sub_08047878
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
