	.syntax unified

	thumb_func_start sub_0804FE50
sub_0804FE50: @ 0x0804FE50
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r0, #0
	mov sb, r0
	mov r8, r0
	ldr r1, _0804FE90 @ =0x030064A0
	adds r0, r1, #0
	adds r0, #0x52
	ldrb r0, [r0]
	cmp sb, r0
	blt _0804FE6E
	b _08050042
_0804FE6E:
	adds r7, r1, #0
	ldr r2, _0804FE94 @ =0x03002C30
	mov sl, r2
_0804FE74:
	mov r0, r8
	lsls r6, r0, #3
	adds r0, r7, #0
	adds r0, #0x12
	adds r0, r6, r0
	ldrb r0, [r0]
	cmp r0, #1
	beq _0804FE98
	cmp r0, #1
	bgt _0804FE8A
	b _0805002C
_0804FE8A:
	cmp r0, #2
	beq _0804FF5C
	b _0805002C
	.align 2, 0
_0804FE90: .4byte 0x030064A0
_0804FE94: .4byte 0x03002C30
_0804FE98:
	adds r1, #2
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bhi _0804FEAC
	b _08050030
_0804FEAC:
	adds r0, r7, #0
	adds r0, #0x13
	adds r0, r6, r0
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r1, r7, #0
	adds r1, #0x14
	adds r1, r6, r1
	ldrb r1, [r1]
	orrs r0, r1
	bl battle_find_entity_by_id
	adds r5, r0, #0
	cmp r5, #0
	beq _0804FF20
	ldrb r1, [r5, #4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804FF20
	lsls r0, r1, #0x1b
	lsrs r0, r0, #3
	movs r2, #0xc4
	lsls r2, r2, #0x16
	adds r0, r0, r2
	lsrs r0, r0, #0x18
	adds r4, r7, #0
	adds r4, #0xa
	add r4, r8
	ldrb r1, [r4]
	adds r2, r5, #0
	bl set_sprite_anim_and_store
	ldrb r0, [r4]
	cmp r0, #0
	bne _0804FF20
	adds r0, r7, #0
	adds r0, #0x15
	adds r0, r6, r0
	ldrb r0, [r0]
	cmp r0, #1
	bne _0804FF20
	ldrb r0, [r5]
	ldrb r1, [r5, #1]
	bl find_map_event_by_coords
	cmp r0, #0
	beq _0804FF20
	ldr r1, _0804FF50 @ =0x03006D38
	ldrb r0, [r1, #3]
	cmp r0, #0
	beq _0804FF20
	ldr r0, _0804FF54 @ =0x083D29E6
	ldrb r1, [r1, #3]
	adds r1, r1, r0
	ldrb r0, [r1]
	bl sub_08047BA8
_0804FF20:
	adds r1, r7, #0
	adds r1, #0xa
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	adds r0, r7, #2
	add r0, r8
	strb r2, [r0]
	ldrb r0, [r1]
	cmp r0, #3
	bls _08050030
	ldrb r0, [r5, #4]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x15
	add r0, sl
	ldr r1, _0804FF58 @ =0x00000C64
	adds r0, r0, r1
	movs r1, #0xff
	strb r1, [r0]
	movs r2, #1
	mov sb, r2
	b _08050030
	.align 2, 0
_0804FF50: .4byte 0x03006D38
_0804FF54: .4byte 0x083D29E6
_0804FF58: .4byte 0x00000C64
_0804FF5C:
	adds r1, r7, #2
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _08050030
	adds r0, r7, #0
	adds r0, #0x13
	adds r0, r6, r0
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r1, r7, #0
	adds r1, #0x14
	adds r1, r6, r1
	ldrb r1, [r1]
	orrs r0, r1
	bl battle_find_entity_by_id
	adds r5, r0, #0
	cmp r5, #0
	beq _0804FFB8
	ldrb r1, [r5, #4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804FFB8
	lsls r0, r1, #0x1b
	lsrs r0, r0, #3
	movs r1, #0xc4
	lsls r1, r1, #0x16
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	adds r1, r7, #0
	adds r1, #0xa
	add r1, r8
	ldrb r2, [r1]
	movs r1, #3
	subs r1, r1, r2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r2, r5, #0
	bl set_sprite_anim_and_store
_0804FFB8:
	adds r1, r7, #0
	adds r1, #0xa
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	adds r0, r7, #2
	add r0, r8
	strb r2, [r0]
	ldrb r0, [r1]
	cmp r0, #3
	bls _08050030
	ldrb r0, [r5, #4]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x15
	add r0, sl
	ldr r1, _08050028 @ =0x00000C64
	adds r0, r0, r1
	movs r1, #0xff
	strb r1, [r0]
	ldrb r0, [r5, #4]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x15
	add r0, sl
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r0, r1
	strb r2, [r0]
	ldrb r1, [r5, #4]
	lsls r1, r1, #0x1b
	lsrs r4, r1, #3
	movs r2, #0xc4
	lsls r2, r2, #0x16
	adds r4, r4, r2
	lsrs r4, r4, #0x18
	lsrs r0, r1, #3
	adds r0, r0, r2
	lsrs r0, r0, #0x18
	lsrs r1, r1, #0x15
	add r1, sl
	movs r2, #0xc6
	lsls r2, r2, #4
	adds r1, r1, r2
	ldrb r1, [r1]
	bl sub_080502B4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl sub_080493D4
	movs r0, #1
	mov sb, r0
	b _08050030
	.align 2, 0
_08050028: .4byte 0x00000C64
_0805002C:
	movs r1, #1
	mov sb, r1
_08050030:
	movs r2, #1
	add r8, r2
	ldr r1, _0805006C @ =0x030064A0
	adds r0, r1, #0
	adds r0, #0x52
	ldrb r0, [r0]
	cmp r8, r0
	bge _08050042
	b _0804FE74
_08050042:
	mov r0, sb
	cmp r0, #0
	beq _0805005E
	ldr r1, _0805006C @ =0x030064A0
	adds r1, #0x52
	movs r0, #0
	strb r0, [r1]
	ldr r0, _0805006C @ =0x030064A0
	adds r0, #0x12
	movs r1, #0x40
	bl sub_080496C8
	bl sub_08050244
_0805005E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805006C: .4byte 0x030064A0
	.syntax divided
