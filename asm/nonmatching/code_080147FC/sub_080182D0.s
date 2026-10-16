	.syntax unified

	thumb_func_start sub_080182D0
	.global sub_080182D0
sub_080182D0: @ 0x080182D0
	ldr r0, _080182E4 @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x46
	ldrb r1, [r2]
	adds r3, r0, #0
	cmp r1, #2
	bne _080182E8
	movs r0, #0
	b _080182EA
	.align 2, 0
_080182E4: .4byte 0x03000440
_080182E8:
	adds r0, r1, #1
_080182EA:
	strb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x3d
	adds r2, r3, #0
	adds r2, #0x46
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r1, r0
	bne _08018308
	cmp r1, #2
	bne _08018304
	movs r0, #0
	b _08018306
_08018304:
	adds r0, #1
_08018306:
	strb r0, [r2]
_08018308:
	bx lr
	.align 2, 0
	.syntax divided
