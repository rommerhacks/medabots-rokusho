	.syntax unified

	thumb_func_start sub_080175FC
	.global sub_080175FC
sub_080175FC: @ 0x080175FC
	push {r4, lr}
	ldr r0, _08017674 @ =0x03001800
	adds r3, r0, #0
	adds r3, #0x82
	ldrb r4, [r3]
	ldr r2, _08017678 @ =0x0300058C
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08017616
	movs r0, #1
	strb r0, [r3]
_08017616:
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _08017626
	movs r0, #0
	strb r0, [r3]
_08017626:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08017632
	movs r0, #2
	strb r0, [r3]
_08017632:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0801763E
	movs r0, #3
	strb r0, [r3]
_0801763E:
	ldrb r0, [r3]
	cmp r0, r4
	beq _0801766C
	movs r0, #2
	bl play_sound_effect
	movs r0, #1
	bl sub_08017178
	movs r0, #1
	bl sub_080171C0
	movs r0, #1
	bl sub_08017208
	movs r0, #1
	bl sub_08017130
	bl sub_08017268
	movs r0, #0
	bl sub_080173B4
_0801766C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08017674: .4byte 0x03001800
_08017678: .4byte 0x0300058C
	.syntax divided
