	.syntax unified

	thumb_func_start sub_08044B58
	.global sub_08044B58
sub_08044B58: @ 0x08044B58
	ldr r2, _08044B94 @ =0x03000BE0
	ldrb r1, [r2]
	movs r0, #0xc0
	movs r3, #0
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _08044B98 @ =0x030017A0
	movs r0, #3
	strb r0, [r1]
	strb r3, [r1, #2]
	movs r0, #0x2a
	strb r0, [r1, #3]
	strb r0, [r1, #4]
	strb r0, [r1, #5]
	strb r0, [r1, #6]
	ldr r1, _08044B9C @ =0x03004C40
	adds r0, r1, #0
	adds r0, #0x55
	movs r2, #1
	strb r2, [r0]
	ldr r3, _08044BA0 @ =0x00000145
	adds r0, r1, r3
	strb r2, [r0]
	adds r3, #0xf0
	adds r0, r1, r3
	strb r2, [r0]
	ldr r0, _08044BA4 @ =0x00000325
	adds r1, r1, r0
	strb r2, [r1]
	bx lr
	.align 2, 0
_08044B94: .4byte 0x03000BE0
_08044B98: .4byte 0x030017A0
_08044B9C: .4byte 0x03004C40
_08044BA0: .4byte 0x00000145
_08044BA4: .4byte 0x00000325
	.syntax divided
