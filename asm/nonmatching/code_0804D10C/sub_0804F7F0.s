	.syntax unified

	thumb_func_start sub_0804F7F0
sub_0804F7F0: @ 0x0804F7F0
	push {lr}
	bl sub_080509A0
	cmp r0, #0
	beq _0804F7FE
	bl sub_08050244
_0804F7FE:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
