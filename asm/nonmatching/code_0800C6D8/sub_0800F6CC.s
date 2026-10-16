	.syntax unified

	thumb_func_start sub_0800F6CC
sub_0800F6CC: @ 0x0800F6CC
	ldr r0, _0800F6DC @ =0x03000440
	adds r1, r0, #0
	adds r1, #0xef
	ldrb r0, [r1]
	cmp r0, #0x63
	bls _0800F6E0
	subs r0, #0x64
	b _0800F6E2
	.align 2, 0
_0800F6DC: .4byte 0x03000440
_0800F6E0:
	ldrb r0, [r1]
_0800F6E2:
	bx lr
	.syntax divided
