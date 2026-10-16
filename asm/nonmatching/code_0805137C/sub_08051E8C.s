	.syntax unified

	thumb_func_start sub_08051E8C
	.global sub_08051E8C
sub_08051E8C: @ 0x08051E8C
	ldr r1, _08051EA4 @ =0x030057E0
	ldr r2, _08051EA8 @ =0x00000C76
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08051EA0
	ldr r0, _08051EAC @ =0x00000C75
	adds r1, r1, r0
	movs r0, #0xff
	strb r0, [r1]
_08051EA0:
	bx lr
	.align 2, 0
_08051EA4: .4byte 0x030057E0
_08051EA8: .4byte 0x00000C76
_08051EAC: .4byte 0x00000C75
	.syntax divided
