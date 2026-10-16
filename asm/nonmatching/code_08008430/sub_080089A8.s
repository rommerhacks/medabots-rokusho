	.syntax unified

	thumb_func_start sub_080089A8
sub_080089A8: @ 0x080089A8
	push {lr}
	bl sub_080093F8
	bl sub_0800A180
	bl sub_0800B130
	bl sub_0800A1E4
	bl sub_0800B468
	ldr r2, _080089DC @ =0x0300058C
	ldrb r1, [r2]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080089E4
	movs r0, #5
	bl play_sound_effect
	ldr r1, _080089E0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08008A24
	.align 2, 0
_080089DC: .4byte 0x0300058C
_080089E0: .4byte 0x0300137C
_080089E4:
	ldrb r1, [r2, #1]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08008A04
	movs r0, #2
	bl play_sound_effect
	ldr r2, _08008A00 @ =0x03000440
	adds r2, #0x42
	ldrb r0, [r2]
	subs r0, #1
	b _08008A1A
	.align 2, 0
_08008A00: .4byte 0x03000440
_08008A04:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08008A26
	movs r0, #2
	bl play_sound_effect
	ldr r2, _08008A2C @ =0x03000440
	adds r2, #0x42
	ldrb r0, [r2]
	adds r0, #1
_08008A1A:
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	ldr r1, _08008A30 @ =0x0300137C
	movs r0, #0x44
_08008A24:
	str r0, [r1]
_08008A26:
	pop {r0}
	bx r0
	.align 2, 0
_08008A2C: .4byte 0x03000440
_08008A30: .4byte 0x0300137C
	.syntax divided
