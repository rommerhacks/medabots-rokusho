	.syntax unified

	thumb_func_start sub_0804765C
	.global sub_0804765C
sub_0804765C: @ 0x0804765C
	adds r1, r0, #0
	cmp r1, #0
	beq _08047668
	cmp r1, #1
	beq _080476C8
	b _080476D8
_08047668:
	ldr r1, _08047690 @ =0x03005310
	ldr r0, _08047694 @ =0x03000440
	adds r0, #0x9c
	ldrb r0, [r0]
	adds r1, #0x39
	strb r0, [r1]
	ldr r0, _08047698 @ =0x030057E0
	ldr r1, _0804769C @ =0x00000C88
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080476AC
	ldr r0, _080476A0 @ =0x0300178C
	movs r1, #1
	str r1, [r0]
	ldr r0, _080476A4 @ =0x03002B8C
	str r1, [r0]
	ldr r1, _080476A8 @ =0x0300137C
	movs r0, #5
	b _080476D6
	.align 2, 0
_08047690: .4byte 0x03005310
_08047694: .4byte 0x03000440
_08047698: .4byte 0x030057E0
_0804769C: .4byte 0x00000C88
_080476A0: .4byte 0x0300178C
_080476A4: .4byte 0x03002B8C
_080476A8: .4byte 0x0300137C
_080476AC:
	ldr r0, _080476BC @ =0x0300178C
	movs r1, #1
	str r1, [r0]
	ldr r0, _080476C0 @ =0x03002B8C
	str r1, [r0]
	ldr r1, _080476C4 @ =0x0300137C
	movs r0, #0xd
	b _080476D6
	.align 2, 0
_080476BC: .4byte 0x0300178C
_080476C0: .4byte 0x03002B8C
_080476C4: .4byte 0x0300137C
_080476C8:
	ldr r0, _080476DC @ =0x0300178C
	str r1, [r0]
	ldr r1, _080476E0 @ =0x03002B8C
	movs r0, #2
	str r0, [r1]
	ldr r1, _080476E4 @ =0x0300137C
	movs r0, #0
_080476D6:
	str r0, [r1]
_080476D8:
	bx lr
	.align 2, 0
_080476DC: .4byte 0x0300178C
_080476E0: .4byte 0x03002B8C
_080476E4: .4byte 0x0300137C
	.syntax divided
