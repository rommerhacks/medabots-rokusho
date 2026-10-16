	.syntax unified

	thumb_func_start sub_080093F8
	.global sub_080093F8
sub_080093F8: @ 0x080093F8
	ldr r0, _08009414 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08009412
	ldr r0, _08009418 @ =0x03001C04
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldrh r1, [r0, #2]
	adds r1, #1
	strh r1, [r0, #2]
_08009412:
	bx lr
	.align 2, 0
_08009414: .4byte 0x03001780
_08009418: .4byte 0x03001C04
	.syntax divided
