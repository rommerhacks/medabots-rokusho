	.syntax unified

	thumb_func_start sub_08059D04
	.global sub_08059D04
sub_08059D04: @ 0x08059D04
	ldr r1, _08059D18 @ =0x03002C30
	movs r2, #0
	movs r3, #0xfe
	lsls r3, r3, #5
	adds r0, r1, r3
_08059D0E:
	strh r2, [r0]
	subs r0, #0x40
	cmp r0, r1
	bge _08059D0E
	bx lr
	.align 2, 0
_08059D18: .4byte 0x03002C30
	.syntax divided
