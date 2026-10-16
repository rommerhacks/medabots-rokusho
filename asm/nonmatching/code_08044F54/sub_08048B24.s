	.syntax unified

	thumb_func_start sub_08048B24
	.global sub_08048B24
sub_08048B24: @ 0x08048B24
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	muls r0, r1, r0
	adds r1, r0, #0
	cmp r0, #0
	bge _08048B36
	adds r1, #0xff
_08048B36:
	lsls r0, r1, #8
	asrs r0, r0, #0x10
	bx lr
	.syntax divided
