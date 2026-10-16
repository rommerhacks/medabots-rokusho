	.syntax unified

	thumb_func_start sub_08057574
sub_08057574: @ 0x08057574
	push {lr}
	movs r0, #0
	bl run_blend_fade_transition
	cmp r0, #0
	beq _08057584
	bl sub_0804A1C4
_08057584:
	pop {r0}
	bx r0
	.syntax divided
