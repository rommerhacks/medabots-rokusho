	.syntax unified

	thumb_func_start sub_08008590
sub_08008590: @ 0x08008590
	push {lr}
	movs r0, #6
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	bl sub_080093F8
	bl sub_0800A180
	ldr r1, _080085B0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080085B0: .4byte 0x0300137C
	.syntax divided
