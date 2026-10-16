	.syntax unified

	thumb_func_start apply_battle_damage_to_team
apply_battle_damage_to_team: @ 0x0802D5BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r0, #0
	mov sb, r0
	movs r5, #0
	ldr r6, _0802D61C @ =0x03001800
	movs r1, #0x60
	adds r1, r1, r6
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0xd6
	ldr r3, _0802D620 @ =0x03000590
	mov sl, r3
_0802D5DC:
	adds r0, r6, #0
	adds r0, #0xd2
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0802D638
	mov r1, r8
	ldrb r0, [r1]
	adds r0, r0, r5
	ldrh r2, [r7]
	movs r1, #0
	bl reduce_bot_part_stat
	mov r3, r8
	ldrb r0, [r3]
	adds r2, r0, r5
	lsls r0, r2, #8
	mov r3, sl
	adds r1, r0, r3
	adds r0, r1, #0
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802D624
	adds r0, r2, #0
	bl add_bot_to_defeated_list
	movs r0, #0x80
	strb r0, [r4]
	movs r0, #1
	mov sb, r0
	b _0802D638
	.align 2, 0
_0802D61C: .4byte 0x03001800
_0802D620: .4byte 0x03000590
_0802D624:
	adds r2, r1, #0
	adds r2, #0xbd
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0802D638
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
_0802D638:
	adds r7, #2
	adds r5, #1
	cmp r5, #2
	bls _0802D5DC
	mov r1, sb
	cmp r1, #0
	beq _0802D654
	ldr r0, _0802D650 @ =0x03001800
	adds r0, #0xaa
	movs r1, #0x10
	strb r1, [r0]
	b _0802D65E
	.align 2, 0
_0802D650: .4byte 0x03001800
_0802D654:
	ldr r1, _0802D66C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802D65E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802D66C: .4byte 0x03001800
_0802D670:
	.byte 0x04, 0x49, 0x0A, 0x1C, 0xA6, 0x32, 0x42, 0x20, 0x10, 0x70, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30
	.byte 0x08, 0x70, 0x70, 0x47, 0x00, 0x18, 0x00, 0x03
	.syntax divided
