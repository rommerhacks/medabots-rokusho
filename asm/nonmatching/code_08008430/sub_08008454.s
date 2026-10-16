	.syntax unified

	thumb_func_start sub_08008454
sub_08008454: @ 0x08008454
	push {lr}
	bl sub_080093F8
	bl sub_0800A180
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	ldr r1, _08008474 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08008474: .4byte 0x0300137C
	.syntax divided
