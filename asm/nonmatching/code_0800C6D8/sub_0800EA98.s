	.syntax unified

	thumb_func_start sub_0800EA98
sub_0800EA98: @ 0x0800EA98
	push {r4, lr}
	bl sub_0800EBFC
	bl load_medapart_sprite_by_slot
	ldr r0, _0800EAF0 @ =0x03001780
	ldrb r1, [r0]
	movs r0, #4
	movs r2, #0xa8
	bl sub_08041C14
	bl sub_080100BC
	ldr r0, _0800EAF4 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800EB04
	ldr r1, _0800EAF8 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x4a
	ldrb r0, [r0]
	cmp r0, #1
	bne _0800EAFC
	adds r0, r1, #0
	adds r0, #0x3d
	ldrb r0, [r0]
	adds r1, #0x3e
	ldrb r1, [r1]
	bl sub_08042114
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xff
	lsrs r2, r0, #8
	ands r1, r0
	cmp r2, r1
	bne _0800EAFC
	movs r0, #6
	bl play_sound_effect
	b _0800EB26
	.align 2, 0
_0800EAF0: .4byte 0x03001780
_0800EAF4: .4byte 0x0300058C
_0800EAF8: .4byte 0x03000440
_0800EAFC:
	movs r0, #4
	bl play_sound_effect
	b _0800EB1A
_0800EB04:
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _0800EB26
	movs r0, #5
	bl play_sound_effect
	ldr r0, _0800EB2C @ =0x03000440
	adds r0, #0x4a
	strb r4, [r0]
_0800EB1A:
	bl sub_08010040
	ldr r1, _0800EB30 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0800EB26:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800EB2C: .4byte 0x03000440
_0800EB30: .4byte 0x0300137C
	.syntax divided
