	.syntax unified

	thumb_func_start sub_08037458
	.global sub_08037458
sub_08037458: @ 0x08037458
	adds r3, r1, #0
	ldr r1, _08037478 @ =0x03000590
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0x58
	ldrb r1, [r0]
	cmp r1, r3
	ble _08037480
	ldr r2, _0803747C @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xc8
	movs r1, #0
	strh r3, [r0]
	adds r0, #4
	strh r3, [r0]
	b _0803748E
	.align 2, 0
_08037478: .4byte 0x03000590
_0803747C: .4byte 0x03001800
_08037480:
	ldr r2, _08037494 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xc8
	strh r1, [r0]
	adds r0, #4
	strh r1, [r0]
	subs r1, r3, r1
_0803748E:
	subs r0, #2
	strh r1, [r0]
	bx lr
	.align 2, 0
_08037494: .4byte 0x03001800
	.syntax divided
