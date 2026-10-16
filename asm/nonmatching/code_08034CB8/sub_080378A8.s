	.syntax unified

	thumb_func_start sub_080378A8
	.global sub_080378A8
sub_080378A8: @ 0x080378A8
	ldr r0, _080378C4 @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080378D0
	ldr r0, _080378C8 @ =0x03002C30
	ldr r1, _080378CC @ =0x00000842
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #4
	b _080378DA
	.align 2, 0
_080378C4: .4byte 0x03001800
_080378C8: .4byte 0x03002C30
_080378CC: .4byte 0x00000842
_080378D0:
	ldr r0, _080378E4 @ =0x03002C30
	ldr r1, _080378E8 @ =0x00000842
	adds r0, r0, r1
	ldrh r1, [r0]
	subs r1, #4
_080378DA:
	ldr r3, _080378EC @ =0x000001FF
	adds r2, r3, #0
	ands r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_080378E4: .4byte 0x03002C30
_080378E8: .4byte 0x00000842
_080378EC: .4byte 0x000001FF
	.syntax divided
