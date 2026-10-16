	.syntax unified

	thumb_func_start load_or_clear_battle_sprites
load_or_clear_battle_sprites: @ 0x080592E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r1
	ldr r1, [sp, #0x20]
	lsls r6, r2, #0x18
	lsrs r5, r6, #0x18
	mov sb, r5
	lsls r3, r3, #0x18
	lsrs r2, r3, #0x18
	mov r8, r2
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	mov sl, r3
	ldr r4, _0805932C @ =0x030057A0
	adds r1, r4, #0
	adds r1, #0x16
	ldrb r7, [r4, #0x14]
	adds r1, r1, r7
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	beq _08059330
	mov r0, ip
	adds r1, r5, #0
	bl load_battle_sprite_from_index
	b _0805936E
	.align 2, 0
_0805932C: .4byte 0x030057A0
_08059330:
	ldrb r1, [r4, #0x15]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08059362
	lsrs r2, r6, #0x1b
	cmp r2, #0
	beq _0805936E
	adds r5, r2, #0
_08059342:
	ldrb r0, [r4, #0x13]
	bl clear_battle_sprite_entry
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x13]
	bl clear_battle_sprite_entry
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	subs r5, #1
	cmp r5, #0
	bne _08059342
	b _0805936E
_08059362:
	mov r0, ip
	mov r1, sb
	mov r2, r8
	mov r3, sl
	bl load_battle_sprite_from_index
_0805936E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
