	.syntax unified

	thumb_func_start sub_0803DE90
sub_0803DE90: @ 0x0803DE90
	push {lr}
	bl sub_0803E894
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl text_window_init
	ldr r1, _0803DEAC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0803DEAC: .4byte 0x0300137C
	.syntax divided
