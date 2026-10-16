	.syntax unified

	thumb_func_start sub_08012468
sub_08012468: @ 0x08012468
	ldr r0, _08012498 @ =0x03001800
	movs r1, #0xb5
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080124B4
	ldr r1, _0801249C @ =0x03002C30
	adds r2, r1, #0
	adds r2, #0x68
	ldrb r0, [r2]
	cmp r0, #0
	bne _080124A0
	adds r1, #0x49
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x80
	bne _080124B4
	movs r0, #1
	b _080124B2
	.align 2, 0
_08012498: .4byte 0x03001800
_0801249C: .4byte 0x03002C30
_080124A0:
	adds r1, #0x49
	ldrb r0, [r1]
	subs r0, #2
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bne _080124B4
	movs r0, #0
_080124B2:
	strb r0, [r2]
_080124B4:
	bx lr
	.align 2, 0
	.syntax divided
