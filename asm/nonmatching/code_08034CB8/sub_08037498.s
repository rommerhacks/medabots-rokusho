	.syntax unified

	thumb_func_start sub_08037498
	.global sub_08037498
sub_08037498: @ 0x08037498
	adds r3, r1, #0
	ldr r1, _080374C0 @ =0x03000590
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0x50
	ldrb r1, [r1]
	adds r0, #0x58
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, r3
	ble _080374C8
	ldr r2, _080374C4 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xc8
	movs r1, #0
	strh r3, [r0]
	adds r0, #4
	strh r3, [r0]
	b _080374D6
	.align 2, 0
_080374C0: .4byte 0x03000590
_080374C4: .4byte 0x03001800
_080374C8:
	ldr r2, _080374DC @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xc8
	strh r1, [r0]
	adds r0, #4
	strh r1, [r0]
	subs r1, r3, r1
_080374D6:
	subs r0, #2
	strh r1, [r0]
	bx lr
	.align 2, 0
_080374DC: .4byte 0x03001800
	.syntax divided
