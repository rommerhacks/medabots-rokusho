	.syntax unified

	thumb_func_start sub_0806A584
sub_0806A584: @ 0x0806A584
	ldr r1, _0806A5A8 @ =0x03006F8C
	ldrb r0, [r1]
	cmp r0, #2
	bls _0806A5B0
	ldrb r0, [r1, #1]
	cmp r0, #2
	bls _0806A5B0
	ldrb r0, [r1, #2]
	cmp r0, #2
	bls _0806A5B0
	ldr r1, _0806A5AC @ =0x03006F88
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	cmp r0, #0xf0
	ble _0806A5B0
	movs r0, #1
	b _0806A5B2
	.align 2, 0
_0806A5A8: .4byte 0x03006F8C
_0806A5AC: .4byte 0x03006F88
_0806A5B0:
	movs r0, #0
_0806A5B2:
	bx lr
	.syntax divided
