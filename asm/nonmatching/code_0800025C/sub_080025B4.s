	.syntax unified

	thumb_func_start sub_080025B4
sub_080025B4: @ 0x080025B4
	push {r4, r5, r6, lr}
	ldr r2, _0800268C @ =0x03002B64
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080025CA
	ldr r1, _08002690 @ =0x03004C30
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
_080025CA:
	ldrb r2, [r2]
	movs r0, #0x80
	ands r0, r2
	adds r3, r2, #0
	cmp r0, #0
	beq _080025DE
	ldr r1, _08002690 @ =0x03004C30
	ldrh r0, [r1, #2]
	subs r0, #1
	strh r0, [r1, #2]
_080025DE:
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _080025EE
	ldr r1, _08002690 @ =0x03004C30
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080025EE:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _080025FE
	ldr r1, _08002690 @ =0x03004C30
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_080025FE:
	ldr r4, _08002694 @ =0x0300058C
	ldrb r1, [r4]
	movs r6, #2
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08002618
	ldr r0, _08002698 @ =0x03000440
	adds r0, #0x88
	ldrb r1, [r0]
	movs r2, #1
	eors r1, r2
	strb r1, [r0]
_08002618:
	ldrb r3, [r4]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r3
	cmp r0, #0
	beq _0800263C
	ldr r2, _08002698 @ =0x03000440
	movs r0, #0
	strb r0, [r2, #0xe]
	ldr r1, _0800269C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r2, #0x85
	ldrb r0, [r2]
	movs r1, #1
	eors r0, r1
	strb r0, [r2]
_0800263C:
	adds r0, r6, #0
	ands r0, r3
	cmp r0, #0
	beq _0800264E
	ldr r0, _080026A0 @ =0x03002B8C
	str r5, [r0]
	ldr r1, _0800269C @ =0x0300137C
	movs r0, #0
	str r0, [r1]
_0800264E:
	ldrb r1, [r4]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0800266A
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl text_window_init
	ldr r1, _0800269C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #2
	str r0, [r1]
_0800266A:
	ldrb r1, [r4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08002686
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl text_window_init
	ldr r1, _0800269C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #3
	str r0, [r1]
_08002686:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800268C: .4byte 0x03002B64
_08002690: .4byte 0x03004C30
_08002694: .4byte 0x0300058C
_08002698: .4byte 0x03000440
_0800269C: .4byte 0x0300137C
_080026A0: .4byte 0x03002B8C
	.syntax divided
