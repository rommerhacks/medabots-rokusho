	.syntax unified

	thumb_func_start sub_0800EBFC
sub_0800EBFC: @ 0x0800EBFC
	ldr r0, _0800EC18 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0800EC16
	ldr r0, _0800EC1C @ =0x03001C04
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldrh r1, [r0, #2]
	adds r1, #1
	strh r1, [r0, #2]
_0800EC16:
	bx lr
	.align 2, 0
_0800EC18: .4byte 0x03001780
_0800EC1C: .4byte 0x03001C04
	.syntax divided
