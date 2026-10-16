	.syntax unified

	thumb_func_start sub_0804BEE8
sub_0804BEE8: @ 0x0804BEE8
	push {r4, r5, lr}
	ldr r4, _0804BF4C @ =0x030057E0
	ldr r1, _0804BF50 @ =0x00000CB4
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r3, r0, r4
	ldr r2, _0804BF54 @ =0x000005DE
	adds r0, r3, r2
	ldrh r2, [r0]
	ldr r0, _0804BF58 @ =0x00000FFF
	ldr r5, _0804BF5C @ =0x00000C8E
	adds r1, r4, r5
	ands r0, r2
	ldrh r1, [r1]
	cmp r0, r1
	bne _0804BF44
	ldr r1, _0804BF60 @ =0x03006D20
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1b
	adds r0, #0x31
	strb r0, [r1, #0xa]
	ldr r3, _0804BF64 @ =0x03002C30
	ldrb r0, [r1, #0xa]
	lsls r0, r0, #6
	adds r0, r0, r3
	ldr r0, [r0, #0x10]
	asrs r0, r0, #8
	movs r2, #0
	strh r0, [r1, #8]
	ldrb r0, [r1, #0xa]
	lsls r0, r0, #6
	adds r0, r0, r3
	adds r0, #0x28
	strb r2, [r0]
	movs r0, #0x70
	bl sub_08047BA8
	subs r5, #5
	adds r1, r4, r5
	movs r0, #1
	strb r0, [r1]
_0804BF44:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804BF4C: .4byte 0x030057E0
_0804BF50: .4byte 0x00000CB4
_0804BF54: .4byte 0x000005DE
_0804BF58: .4byte 0x00000FFF
_0804BF5C: .4byte 0x00000C8E
_0804BF60: .4byte 0x03006D20
_0804BF64: .4byte 0x03002C30
	.syntax divided
