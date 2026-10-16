	.syntax unified

	thumb_func_start sub_0801AE70
sub_0801AE70: @ 0x0801AE70
	push {r4, r5, lr}
	movs r2, #0
	ldr r0, _0801AEA8 @ =0x03002C30
	movs r4, #3
	ldr r3, _0801AEAC @ =0x00001E06
	adds r1, r0, r3
	movs r3, #3
_0801AE7E:
	ldrb r0, [r1, #0x1b]
	adds r0, #1
	strb r0, [r1, #0x1b]
	ands r0, r3
	cmp r0, #0
	bne _0801AE98
	ldrb r0, [r1, #0x1c]
	adds r0, #1
	ands r0, r4
	strb r0, [r1, #0x1c]
	ldr r5, _0801AEB0 @ =0x00000616
	adds r0, r0, r5
	strh r0, [r1]
_0801AE98:
	adds r1, #0x40
	adds r2, #1
	cmp r2, #7
	bls _0801AE7E
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801AEA8: .4byte 0x03002C30
_0801AEAC: .4byte 0x00001E06
_0801AEB0: .4byte 0x00000616
	.syntax divided
