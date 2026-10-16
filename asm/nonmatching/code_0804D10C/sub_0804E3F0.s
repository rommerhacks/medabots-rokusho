	.syntax unified

	thumb_func_start sub_0804E3F0
sub_0804E3F0: @ 0x0804E3F0
	push {lr}
	bl sub_08050868
	cmp r0, #0
	beq _0804E3FE
	bl sub_08050244
_0804E3FE:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
