	.syntax unified

	thumb_func_start sub_0804AAB8
sub_0804AAB8: @ 0x0804AAB8
	push {lr}
	movs r0, #0
	bl run_blend_fade_transition
	cmp r0, #0
	beq _0804AAC8
	bl sub_0804A1C4
_0804AAC8:
	pop {r0}
	bx r0
	.syntax divided
