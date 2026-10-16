	.syntax unified

	thumb_func_start sub_0803E894
sub_0803E894: @ 0x0803E894
	ldr r0, _0803E8B0 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0803E8AE
	ldr r0, _0803E8B4 @ =0x03001C04
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldrh r1, [r0, #2]
	adds r1, #1
	strh r1, [r0, #2]
_0803E8AE:
	bx lr
	.align 2, 0
_0803E8B0: .4byte 0x03001780
_0803E8B4: .4byte 0x03001C04
	.syntax divided
