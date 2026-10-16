	.syntax unified

	thumb_func_start sub_0803DC3C
sub_0803DC3C: @ 0x0803DC3C
	push {lr}
	bl update_scroll_movement_a
	movs r0, #8
	bl sound_stop_all_with_fade_guard
	ldr r1, _0803DC54 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0803DC54: .4byte 0x0300137C
	.syntax divided
