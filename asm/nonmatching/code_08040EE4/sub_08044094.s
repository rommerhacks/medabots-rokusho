	.syntax unified

	thumb_func_start sub_08044094
	.global sub_08044094
sub_08044094: @ 0x08044094
	ldr r0, _080440A8 @ =0x0300178C
	movs r1, #1
	str r1, [r0]
	ldr r0, _080440AC @ =0x03002B8C
	str r1, [r0]
	ldr r1, _080440B0 @ =0x0300137C
	movs r0, #7
	str r0, [r1]
	bx lr
	.align 2, 0
_080440A8: .4byte 0x0300178C
_080440AC: .4byte 0x03002B8C
_080440B0: .4byte 0x0300137C
	.syntax divided
