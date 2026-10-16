	.syntax unified

	thumb_func_start sub_08073140
	.global sub_08073140
sub_08073140: @ 0x08073140
	ldr r1, _0807314C @ =0x083AB9D0
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_0807314C: .4byte 0x083AB9D0
	.syntax divided
