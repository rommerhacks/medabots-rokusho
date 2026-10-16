	.syntax unified

	thumb_func_start update_battle_sprite_movement
update_battle_sprite_movement: @ 0x08050140
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	movs r7, #0
	ldr r1, _08050170 @ =0x03002C30
	lsls r0, r5, #6
	adds r4, r0, r1
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	beq _08050236
	adds r0, r4, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #1
	beq _0805018C
	cmp r0, #1
	bgt _08050174
	cmp r0, #0
	beq _0805017E
	b _080501C8
	.align 2, 0
_08050170: .4byte 0x03002C30
_08050174:
	cmp r0, #2
	beq _080501A4
	cmp r0, #3
	beq _080501B2
	b _080501C8
_0805017E:
	adds r0, r5, #0
	bl sub_080518F4
	ldr r2, [r4, #0x10]
	asrs r1, r2, #8
	subs r1, r1, r0
	b _08050198
_0805018C:
	adds r0, r5, #0
	bl sub_080518F4
	ldr r2, [r4, #0x10]
	asrs r1, r2, #8
	adds r1, r1, r0
_08050198:
	lsls r1, r1, #8
	movs r0, #0xff
	ands r0, r2
	orrs r0, r1
	str r0, [r4, #0x10]
	b _080501C8
_080501A4:
	adds r0, r5, #0
	bl sub_080518F4
	ldr r2, [r4, #0xc]
	asrs r1, r2, #8
	subs r1, r1, r0
	b _080501BE
_080501B2:
	adds r0, r5, #0
	bl sub_080518F4
	ldr r2, [r4, #0xc]
	asrs r1, r2, #8
	adds r1, r1, r0
_080501BE:
	lsls r1, r1, #8
	movs r0, #0xff
	ands r0, r2
	orrs r0, r1
	str r0, [r4, #0xc]
_080501C8:
	cmp r6, #0
	beq _080501D2
	adds r0, r5, #0
	bl advance_sprite_by_terrain_modifier
_080501D2:
	ldr r0, _080501FC @ =0x03002C30
	lsls r2, r5, #6
	adds r3, r2, r0
	adds r1, r3, #0
	adds r1, #0x28
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	adds r6, r2, #0
	cmp r0, #0
	bne _08050236
	ldrh r1, [r3, #0x30]
	cmp r1, #0x78
	beq _08050208
	cmp r1, #0x78
	bgt _08050200
	cmp r1, #0x71
	beq _08050208
	b _0805020E
	.align 2, 0
_080501FC: .4byte 0x03002C30
_08050200:
	cmp r1, #0x84
	bgt _0805020E
	cmp r1, #0x82
	blt _0805020E
_08050208:
	movs r0, #0x57
	bl sub_08047BA8
_0805020E:
	adds r0, r5, #0
	bl sub_080518F4
	adds r1, r0, #0
	ldr r4, _08050240 @ =0x03002C30
	adds r4, r6, r4
	movs r0, #0x10
	bl sub_0807CBBC
	adds r1, r4, #0
	adds r1, #0x28
	strb r0, [r1]
	adds r4, #0x27
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08050236
	movs r7, #1
_08050236:
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08050240: .4byte 0x03002C30
	.syntax divided
