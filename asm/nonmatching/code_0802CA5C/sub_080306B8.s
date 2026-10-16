	.syntax unified

	thumb_func_start sub_080306B8
sub_080306B8: @ 0x080306B8
	push {r4, r5, r6, r7, lr}
	ldr r0, _08030724 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x89
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0
	bne _08030712
	ldr r0, _08030728 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08030712
	movs r4, #0
	ldr r0, _0803072C @ =0x03002C30
	movs r6, #0xa0
	lsls r6, r6, #0x14
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r5, r0, r1
	movs r0, #0x80
	lsls r0, r0, #8
	adds r7, r0, #0
_080306E8:
	ldrh r0, [r5]
	ands r0, r7
	cmp r0, #0
	beq _080306F8
	lsrs r0, r6, #0x18
	movs r1, #1
	bl clear_battle_sprite_slot
_080306F8:
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r6, r6, r1
	adds r5, #0x40
	adds r4, #1
	cmp r4, #0x13
	bls _080306E8
	ldr r1, _08030730 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r2, _08030724 @ =0x03000440
_08030712:
	adds r1, r2, #0
	adds r1, #0x86
	ldrh r0, [r1]
	cmp r0, #0
	beq _08030734
	subs r0, #1
	strh r0, [r1]
	b _08030770
	.align 2, 0
_08030724: .4byte 0x03000440
_08030728: .4byte 0x03001798
_0803072C: .4byte 0x03002C30
_08030730: .4byte 0x03001800
_08030734:
	movs r4, #0
	ldr r0, _08030778 @ =0x03002C30
	movs r6, #0xa0
	lsls r6, r6, #0x14
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r5, r0, r1
	movs r0, #0x80
	lsls r0, r0, #8
	adds r7, r0, #0
_08030748:
	ldrh r0, [r5]
	ands r0, r7
	cmp r0, #0
	beq _08030758
	lsrs r0, r6, #0x18
	movs r1, #1
	bl clear_battle_sprite_slot
_08030758:
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r6, r6, r1
	adds r5, #0x40
	adds r4, #1
	cmp r4, #0x13
	bls _08030748
	ldr r1, _0803077C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08030770:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08030778: .4byte 0x03002C30
_0803077C: .4byte 0x03001800
	.syntax divided
