	.syntax unified

	thumb_func_start sub_0804A67C
sub_0804A67C: @ 0x0804A67C
	push {lr}
	ldr r0, _0804A690 @ =0x00007FFF
	bl run_blend_fade_transition
	cmp r0, #0
	beq _0804A68C
	bl sub_0804A1C4
_0804A68C:
	pop {r0}
	bx r0
	.align 2, 0
_0804A690: .4byte 0x00007FFF
	.syntax divided
