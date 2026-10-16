	.syntax unified

	thumb_func_start sub_08008430
sub_08008430: @ 0x08008430
	push {lr}
	bl sub_080093F8
	bl sub_0800A180
	bl update_blend_effect
	cmp r0, #0
	beq _0800844A
	ldr r1, _08008450 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0800844A:
	pop {r0}
	bx r0
	.align 2, 0
_08008450: .4byte 0x0300137C
	.syntax divided
