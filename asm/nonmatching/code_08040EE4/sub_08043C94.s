	.syntax unified

	thumb_func_start sub_08043C94
	.global sub_08043C94
sub_08043C94: @ 0x08043C94
	push {lr}
	bl rng_next_080424B8
	movs r1, #0x64
	muls r0, r1, r0
	movs r1, #0xff
	bl sub_0807CBBC
	pop {r1}
	bx r1
	.syntax divided
