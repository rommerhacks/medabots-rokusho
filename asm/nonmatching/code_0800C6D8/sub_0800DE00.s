	.syntax unified

	thumb_func_start sub_0800DE00
sub_0800DE00: @ 0x0800DE00
	push {r4, lr}
	bl sub_0800EBFC
	bl sub_0800EF58
	ldr r0, _0800DE50 @ =0x03001780
	ldrb r1, [r0]
	movs r0, #3
	movs r2, #0x50
	bl sub_08041C14
	bl load_medapart_sprite_by_slot
	bl sub_0800EFFC
	cmp r0, #0
	bne _0800DEC2
	bl sub_0800F08C
	cmp r0, #0
	bne _0800DEC2
	bl sub_0800F148
	cmp r0, #0
	bne _0800DEC2
	ldr r0, _0800DE54 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800DE70
	ldr r0, _0800DE58 @ =0x03000440
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #4
	bne _0800DE5C
	movs r0, #6
	bl play_sound_effect
	b _0800DEC2
	.align 2, 0
_0800DE50: .4byte 0x03001780
_0800DE54: .4byte 0x0300058C
_0800DE58: .4byte 0x03000440
_0800DE5C:
	movs r0, #5
	bl play_sound_effect
	ldr r1, _0800DE6C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _0800DEC2
	.align 2, 0
_0800DE6C: .4byte 0x0300137C
_0800DE70:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800DEC2
	ldr r4, _0800DEA8 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x3d
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x3e
	ldrb r1, [r1]
	bl sub_08042114
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0800DEBC
	movs r0, #4
	bl play_sound_effect
	adds r0, r4, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #4
	bne _0800DEB0
	ldr r1, _0800DEAC @ =0x0300137C
	movs r0, #0x40
	str r0, [r1]
	b _0800DEC2
	.align 2, 0
_0800DEA8: .4byte 0x03000440
_0800DEAC: .4byte 0x0300137C
_0800DEB0:
	ldr r1, _0800DEB8 @ =0x0300137C
	movs r0, #0xa
	str r0, [r1]
	b _0800DEC2
	.align 2, 0
_0800DEB8: .4byte 0x0300137C
_0800DEBC:
	movs r0, #6
	bl play_sound_effect
_0800DEC2:
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
