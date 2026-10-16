	.syntax unified

	thumb_func_start sub_0804E570
sub_0804E570: @ 0x0804E570
	push {lr}
	bl sub_080508CC
	cmp r0, #0
	beq _0804E57E
	bl sub_08050244
_0804E57E:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
