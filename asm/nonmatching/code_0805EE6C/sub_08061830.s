	.syntax unified

	thumb_func_start sub_08061830
sub_08061830: @ 0x08061830
	push {lr}
	bl reset_bg_scroll
	ldr r1, _08061844 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08061844: .4byte 0x0300137C
	.syntax divided
