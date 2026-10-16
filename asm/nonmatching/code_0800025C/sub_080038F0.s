	.syntax unified

	thumb_func_start sub_080038F0
sub_080038F0: @ 0x080038F0
	push {lr}
	bl sub_080039BC
	ldr r1, _08003900 @ =0x0300137C
	movs r0, #2
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08003900: .4byte 0x0300137C
	.syntax divided
