	.syntax unified

	thumb_func_start sub_0803628C
	.global sub_0803628C
sub_0803628C: @ 0x0803628C
	ldr r1, _080362BC @ =0x03000590
	ldr r0, _080362C0 @ =0x03001800
	adds r0, #0x88
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r2, r0, r1
	adds r0, r2, #0
	adds r0, #0xc0
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	movs r3, #0x14
	cmp r0, #0
	beq _080362AA
	movs r3, #0x28
_080362AA:
	adds r1, r2, #0
	adds r1, #0xc1
	ldrb r0, [r1]
	adds r0, r0, r3
	cmp r0, #0x4f
	bls _080362B8
	movs r0, #0x50
_080362B8:
	strb r0, [r1]
	bx lr
	.align 2, 0
_080362BC: .4byte 0x03000590
_080362C0: .4byte 0x03001800
	.syntax divided
