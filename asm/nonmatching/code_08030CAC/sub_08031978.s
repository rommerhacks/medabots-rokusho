	.syntax unified

	thumb_func_start sub_08031978
sub_08031978: @ 0x08031978
	push {lr}
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl text_window_init
	ldr r1, _08031990 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08031990: .4byte 0x0300137C
	.syntax divided
