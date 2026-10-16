	.syntax unified

	thumb_func_start sub_0804E55C
sub_0804E55C: @ 0x0804E55C
	push {lr}
	bl sub_08050868
	cmp r0, #0
	beq _0804E56A
	bl sub_08050244
_0804E56A:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
