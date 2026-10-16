	.syntax unified

	thumb_func_start sub_08007BD8
sub_08007BD8: @ 0x08007BD8
	push {lr}
	bl sub_080093F8
	bl sub_0800A180
	bl update_blend_effect
	cmp r0, #0
	beq _08007BF2
	ldr r1, _08007BF8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08007BF2:
	pop {r0}
	bx r0
	.align 2, 0
_08007BF8: .4byte 0x0300137C
	.syntax divided
