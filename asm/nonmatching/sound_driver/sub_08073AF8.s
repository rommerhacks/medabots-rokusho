	.syntax unified

	thumb_func_start sub_08073AF8
	.global sub_08073AF8
sub_08073AF8: @ 0x08073AF8
	ldr r1, _08073B04 @ =0x03007014
	ldr r1, [r1]
	ldr r2, _08073B08 @ =0x00000724
	adds r1, r1, r2
	str r0, [r1]
	bx lr
	.align 2, 0
_08073B04: .4byte 0x03007014
_08073B08: .4byte 0x00000724
	.syntax divided
