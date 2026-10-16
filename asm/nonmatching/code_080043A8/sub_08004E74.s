	.syntax unified

	thumb_func_start sub_08004E74
	.global sub_08004E74
sub_08004E74: @ 0x08004E74
	ldr r0, _08004E90 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08004E8E
	ldr r0, _08004E94 @ =0x03001C04
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldrh r1, [r0, #2]
	adds r1, #1
	strh r1, [r0, #2]
_08004E8E:
	bx lr
	.align 2, 0
_08004E90: .4byte 0x03001780
_08004E94: .4byte 0x03001C04
	.syntax divided
