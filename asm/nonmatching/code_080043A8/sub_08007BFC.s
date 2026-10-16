	.syntax unified

	thumb_func_start sub_08007BFC
sub_08007BFC: @ 0x08007BFC
	push {lr}
	bl sub_080093F8
	bl sub_0800A180
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	ldr r1, _08007C1C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08007C1C: .4byte 0x0300137C
	.syntax divided
