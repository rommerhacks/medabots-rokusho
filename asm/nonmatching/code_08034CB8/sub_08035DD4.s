	.syntax unified

	thumb_func_start sub_08035DD4
sub_08035DD4: @ 0x08035DD4
	ldr r1, _08035DE0 @ =0xFFFFFED8
	adds r0, r0, r1
	cmp r0, #0xa8
	bls _08035DE4
	movs r0, #1
	b _08035DE6
	.align 2, 0
_08035DE0: .4byte 0xFFFFFED8
_08035DE4:
	movs r0, #0
_08035DE6:
	bx lr
	.syntax divided
