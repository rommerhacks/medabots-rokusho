	.syntax unified

	thumb_func_start sub_0804DD38
sub_0804DD38: @ 0x0804DD38
	push {lr}
	ldr r0, _0804DD4C @ =0x00007FFF
	bl run_blend_fade_transition
	cmp r0, #0
	beq _0804DD48
	bl sub_08050244
_0804DD48:
	pop {r0}
	bx r0
	.align 2, 0
_0804DD4C: .4byte 0x00007FFF
	.syntax divided
