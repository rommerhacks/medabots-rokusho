	.syntax unified

	thumb_func_start sub_0804DD24
sub_0804DD24: @ 0x0804DD24
	push {lr}
	movs r0, #0
	bl run_blend_fade_transition
	cmp r0, #0
	beq _0804DD34
	bl sub_08050244
_0804DD34:
	pop {r0}
	bx r0
	.syntax divided
