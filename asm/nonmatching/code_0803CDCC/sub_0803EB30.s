	.syntax unified

	thumb_func_start sub_0803EB30
sub_0803EB30: @ 0x0803EB30
	ldr r2, _0803EB54 @ =0x03001800
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, #0x68
	subs r0, r0, r1
	ldr r3, _0803EB58 @ =0x000001A1
	adds r1, r2, r3
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bhi _0803EB50
	movs r0, #0xc
	strb r0, [r1]
_0803EB50:
	bx lr
	.align 2, 0
_0803EB54: .4byte 0x03001800
_0803EB58: .4byte 0x000001A1
	.syntax divided
