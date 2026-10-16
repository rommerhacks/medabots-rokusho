	.syntax unified

	thumb_func_start sub_08015F78
	.global sub_08015F78
sub_08015F78: @ 0x08015F78
	push {r4, lr}
	movs r4, #0
_08015F7C:
	adds r0, r4, #0
	bl sub_08015F90
	adds r4, #1
	cmp r4, #5
	bls _08015F7C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
