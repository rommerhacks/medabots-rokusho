	.syntax unified

	thumb_func_start sub_0801767C
	.global sub_0801767C
sub_0801767C: @ 0x0801767C
	push {lr}
	ldr r0, _08017694 @ =0x03001800
	adds r0, #0x82
	ldrb r0, [r0]
	cmp r0, #1
	beq _080176C4
	cmp r0, #1
	bgt _08017698
	cmp r0, #0
	beq _080176A2
	b _0801772E
	.align 2, 0
_08017694: .4byte 0x03001800
_08017698:
	cmp r0, #2
	beq _080176E8
	cmp r0, #3
	beq _0801770C
	b _0801772E
_080176A2:
	ldr r0, _080176B8 @ =0x03000440
	adds r0, #0x84
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080176BC
	movs r0, #1
	bl sub_08017130
	b _0801772E
	.align 2, 0
_080176B8: .4byte 0x03000440
_080176BC:
	movs r0, #0
	bl sub_08017130
	b _0801772E
_080176C4:
	ldr r0, _080176DC @ =0x03000440
	adds r0, #0x84
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080176E0
	movs r0, #1
	bl sub_08017178
	b _0801772E
	.align 2, 0
_080176DC: .4byte 0x03000440
_080176E0:
	movs r0, #0
	bl sub_08017178
	b _0801772E
_080176E8:
	ldr r0, _08017700 @ =0x03000440
	adds r0, #0x84
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08017704
	movs r0, #1
	bl sub_080171C0
	b _0801772E
	.align 2, 0
_08017700: .4byte 0x03000440
_08017704:
	movs r0, #0
	bl sub_080171C0
	b _0801772E
_0801770C:
	ldr r0, _08017724 @ =0x03000440
	adds r0, #0x84
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08017728
	movs r0, #1
	bl sub_08017208
	b _0801772E
	.align 2, 0
_08017724: .4byte 0x03000440
_08017728:
	movs r0, #0
	bl sub_08017208
_0801772E:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
