	.syntax unified

	thumb_func_start sub_08073940
sub_08073940: @ 0x08073940
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #2
	ldr r3, _08073960 @ =0x040000B0
	adds r2, r2, r3
	str r1, [r2]
	ldr r1, _08073964 @ =0x084873B8
	subs r0, #1
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2, #4]
	ldr r0, _08073968 @ =0xF6400004
	str r0, [r2, #8]
	bx lr
	.align 2, 0
_08073960: .4byte 0x040000B0
_08073964: .4byte 0x084873B8
_08073968: .4byte 0xF6400004
	.syntax divided
