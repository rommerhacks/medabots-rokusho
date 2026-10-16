	.syntax unified

	thumb_func_start sub_08016068
	.global sub_08016068
sub_08016068: @ 0x08016068
	push {r4, lr}
	movs r4, #0
_0801606C:
	adds r0, r4, #0
	bl sub_08016080
	adds r4, #1
	cmp r4, #5
	bls _0801606C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
