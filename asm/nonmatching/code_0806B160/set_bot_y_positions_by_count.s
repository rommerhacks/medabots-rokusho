	.syntax unified

	thumb_func_start set_bot_y_positions_by_count
set_bot_y_positions_by_count: @ 0x0806D258
	push {r4, lr}
	movs r2, #0
	ldr r0, _0806D284 @ =0x03002C30
	movs r1, #0xf4
	lsls r1, r1, #3
	adds r3, r0, r1
	movs r4, #0xd0
	lsls r4, r4, #2
	adds r0, r0, r4
_0806D26A:
	movs r1, #0xc8
	ldrb r4, [r3]
	cmp r2, r4
	bge _0806D274
	movs r1, #0x78
_0806D274:
	strh r1, [r0, #4]
	adds r0, #0x40
	adds r2, #1
	cmp r2, #2
	ble _0806D26A
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806D284: .4byte 0x03002C30
	.syntax divided
