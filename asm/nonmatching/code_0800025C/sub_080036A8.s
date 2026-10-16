	.syntax unified

	thumb_func_start sub_080036A8
sub_080036A8: @ 0x080036A8
	push {lr}
	movs r0, #6
	bl play_song
	ldr r1, _080036C0 @ =0x03002B8C
	movs r0, #1
	str r0, [r1]
	ldr r1, _080036C4 @ =0x0300137C
	movs r0, #0x10
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080036C0: .4byte 0x03002B8C
_080036C4: .4byte 0x0300137C
	.syntax divided
