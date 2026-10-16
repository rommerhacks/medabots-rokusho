	.syntax unified

	thumb_func_start sub_0801554C
	.global sub_0801554C
sub_0801554C: @ 0x0801554C
	cmp r1, #0
	bne _08015556
	cmp r0, #2
	bls _0801555A
	b _0801555E
_08015556:
	cmp r0, #2
	bls _0801555E
_0801555A:
	movs r0, #0
	b _08015560
_0801555E:
	movs r0, #1
_08015560:
	bx lr
	.align 2, 0
	.syntax divided
