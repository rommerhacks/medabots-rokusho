	.syntax unified

	thumb_func_start sub_08008A34
sub_08008A34: @ 0x08008A34
	push {lr}
	movs r0, #6
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	bl sub_080093F8
	bl sub_0800A180
	bl sub_0800B130
	ldr r1, _08008A58 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08008A58: .4byte 0x0300137C
	.syntax divided
