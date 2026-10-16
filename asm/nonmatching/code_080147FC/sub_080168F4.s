	.syntax unified

	thumb_func_start sub_080168F4
	.global sub_080168F4
sub_080168F4: @ 0x080168F4
	push {lr}
	ldr r0, _0801690C @ =0x03001800
	adds r0, #0x82
	ldrb r0, [r0]
	cmp r0, #1
	beq _0801693C
	cmp r0, #1
	bgt _08016910
	cmp r0, #0
	beq _0801691A
	b _080169A6
	.align 2, 0
_0801690C: .4byte 0x03001800
_08016910:
	cmp r0, #2
	beq _08016960
	cmp r0, #3
	beq _08016984
	b _080169A6
_0801691A:
	ldr r0, _08016930 @ =0x03000440
	adds r0, #0x84
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08016934
	movs r0, #1
	bl sub_08016894
	b _080169A6
	.align 2, 0
_08016930: .4byte 0x03000440
_08016934:
	movs r0, #0
	bl sub_08016894
	b _080169A6
_0801693C:
	ldr r0, _08016954 @ =0x03000440
	adds r0, #0x84
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08016958
	movs r0, #1
	bl sub_080167BC
	b _080169A6
	.align 2, 0
_08016954: .4byte 0x03000440
_08016958:
	movs r0, #0
	bl sub_080167BC
	b _080169A6
_08016960:
	ldr r0, _08016978 @ =0x03000440
	adds r0, #0x84
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0801697C
	movs r0, #1
	bl sub_08016804
	b _080169A6
	.align 2, 0
_08016978: .4byte 0x03000440
_0801697C:
	movs r0, #0
	bl sub_08016804
	b _080169A6
_08016984:
	ldr r0, _0801699C @ =0x03000440
	adds r0, #0x84
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080169A0
	movs r0, #1
	bl sub_0801684C
	b _080169A6
	.align 2, 0
_0801699C: .4byte 0x03000440
_080169A0:
	movs r0, #0
	bl sub_0801684C
_080169A6:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
