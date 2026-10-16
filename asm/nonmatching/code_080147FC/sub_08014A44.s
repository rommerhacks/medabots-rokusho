	.syntax unified

	thumb_func_start sub_08014A44
sub_08014A44: @ 0x08014A44
	push {lr}
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl text_window_init
	ldr r1, _08014A5C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08014A5C: .4byte 0x0300137C
	.syntax divided
