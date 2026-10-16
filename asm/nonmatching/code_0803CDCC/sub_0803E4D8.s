	.syntax unified

	thumb_func_start sub_0803E4D8
sub_0803E4D8: @ 0x0803E4D8
	push {lr}
	bl update_blend_effect
	cmp r0, #0
	beq _0803E4EA
	ldr r1, _0803E4F0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803E4EA:
	pop {r0}
	bx r0
	.align 2, 0
_0803E4F0: .4byte 0x0300137C
	.syntax divided
