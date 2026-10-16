	.syntax unified

	thumb_func_start sub_0803E780
	.global sub_0803E780
sub_0803E780: @ 0x0803E780
	ldr r0, _0803E794 @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	bne _0803E790
	ldr r1, _0803E798 @ =0x03005010
	movs r0, #0
	strh r0, [r1, #6]
_0803E790:
	bx lr
	.align 2, 0
_0803E794: .4byte 0x03000440
_0803E798: .4byte 0x03005010
	.syntax divided
