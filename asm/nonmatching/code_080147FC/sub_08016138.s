	.syntax unified

	thumb_func_start sub_08016138
sub_08016138: @ 0x08016138
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_0801613E:
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_08016154
	adds r4, #1
	cmp r4, #5
	bls _0801613E
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
