	.syntax unified

	thumb_func_start sub_0804DD10
sub_0804DD10: @ 0x0804DD10
	push {lr}
	movs r0, #0
	bl run_blend_fade_transition
	cmp r0, #0
	beq _0804DD20
	bl sub_08050244
_0804DD20:
	pop {r0}
	bx r0
	.syntax divided
