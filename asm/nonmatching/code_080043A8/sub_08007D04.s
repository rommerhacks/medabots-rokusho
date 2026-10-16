	.syntax unified

	thumb_func_start sub_08007D04
sub_08007D04: @ 0x08007D04
	push {lr}
	movs r0, #6
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	bl sub_080093F8
	bl sub_0800A180
	ldr r1, _08007D24 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08007D24: .4byte 0x0300137C
	.syntax divided
