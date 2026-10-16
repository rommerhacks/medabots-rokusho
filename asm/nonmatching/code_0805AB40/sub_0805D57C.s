	.syntax unified

	thumb_func_start sub_0805D57C
sub_0805D57C: @ 0x0805D57C
	lsls r0, r0, #0x10
	ldr r3, _0805D594 @ =0x03002C30
	ldr r2, _0805D598 @ =0x080AF7E0
	movs r1, #0xc0
	lsls r1, r1, #0xa
	ands r1, r0
	lsrs r1, r1, #0xf
	adds r1, r1, r2
	ldrh r0, [r1]
	strh r0, [r3, #6]
	bx lr
	.align 2, 0
_0805D594: .4byte 0x03002C30
_0805D598: .4byte 0x080AF7E0
	.syntax divided
