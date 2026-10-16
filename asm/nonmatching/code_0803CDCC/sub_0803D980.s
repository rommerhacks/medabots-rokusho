	.syntax unified

	thumb_func_start sub_0803D980
sub_0803D980: @ 0x0803D980
	push {lr}
	bl update_scroll_movement_a
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl text_window_init
	ldr r1, _0803D99C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0803D99C: .4byte 0x0300137C
	.syntax divided
