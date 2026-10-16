	.syntax unified

	thumb_func_start sub_0803E4B4
sub_0803E4B4: @ 0x0803E4B4
	push {lr}
	movs r0, #8
	bl sound_stop_all_with_fade_guard
	movs r0, #6
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	ldr r1, _0803E4D4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0803E4D4: .4byte 0x0300137C
	.syntax divided
