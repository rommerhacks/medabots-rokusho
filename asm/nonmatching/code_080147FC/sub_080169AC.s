	.syntax unified

	thumb_func_start sub_080169AC
	.global sub_080169AC
sub_080169AC: @ 0x080169AC
	push {r4, lr}
	ldr r0, _08016A34 @ =0x03001800
	adds r3, r0, #0
	adds r3, #0x82
	ldrb r4, [r3]
	ldr r2, _08016A38 @ =0x0300058C
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080169C6
	movs r0, #1
	strb r0, [r3]
_080169C6:
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _080169D6
	movs r0, #0
	strb r0, [r3]
_080169D6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _080169E2
	movs r0, #2
	strb r0, [r3]
_080169E2:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080169EE
	movs r0, #3
	strb r0, [r3]
_080169EE:
	ldrb r0, [r3]
	cmp r0, r4
	beq _08016A2E
	movs r0, #2
	bl play_sound_effect
	bl sub_0801677C
	movs r0, #1
	bl sub_080167BC
	movs r0, #1
	bl sub_08016804
	movs r0, #1
	bl sub_0801684C
	movs r0, #1
	bl sub_08016894
	bl sub_08016A3C
	bl sub_08016AD8
	bl sub_08016D18
	bl sub_08016DCC
	bl sub_0801BACC
	bl sub_0801B894
_08016A2E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08016A34: .4byte 0x03001800
_08016A38: .4byte 0x0300058C
	.syntax divided
