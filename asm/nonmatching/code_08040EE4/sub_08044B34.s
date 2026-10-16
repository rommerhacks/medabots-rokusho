	.syntax unified

	thumb_func_start sub_08044B34
	.global sub_08044B34
sub_08044B34: @ 0x08044B34
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08044B4A
	ldr r1, _08044B4C @ =0x083B2970
	ldr r0, _08044B50 @ =0x030057E0
	ldr r2, _08044B54 @ =0x00000C5C
	adds r0, r0, r2
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
_08044B4A:
	bx lr
	.align 2, 0
_08044B4C: .4byte 0x083B2970
_08044B50: .4byte 0x030057E0
_08044B54: .4byte 0x00000C5C
	.syntax divided
