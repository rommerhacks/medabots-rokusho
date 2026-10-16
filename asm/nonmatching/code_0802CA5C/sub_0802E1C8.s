	.syntax unified

	thumb_func_start sub_0802E1C8
sub_0802E1C8: @ 0x0802E1C8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	movs r5, #0
	ldr r6, _0802E28C @ =0x03001800
	movs r0, #0xc8
	adds r0, r0, r6
	mov sb, r0
	movs r0, #0x7f
	mov r8, r0
_0802E1E0:
	adds r0, r6, #0
	adds r0, #0xd2
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0802E26E
	adds r7, r6, #0
	adds r7, #0x60
	ldrb r0, [r7]
	adds r0, r0, r5
	bl get_random_battle_weight_entry
	strb r0, [r4]
	ldrb r0, [r7]
	adds r0, r0, r5
	ldrb r1, [r4]
	movs r2, #0xc8
	bl battle_set_damage_vs_armor
	adds r0, r6, #0
	adds r0, #0xd1
	ldrb r0, [r0]
	lsls r0, r0, #7
	ldrb r1, [r4]
	orrs r0, r1
	strb r0, [r4]
	lsls r1, r5, #1
	adds r0, r6, #0
	adds r0, #0xd6
	adds r1, r1, r0
	mov r0, sb
	ldrh r2, [r0]
	strh r2, [r1]
	ldr r3, _0802E290 @ =0x03000590
	ldrb r1, [r4]
	mov r0, r8
	ands r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldrb r0, [r7]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r1, r1, r0
	adds r1, r1, r3
	adds r1, #0x59
	ldrb r0, [r1]
	subs r0, r0, r2
	strb r0, [r1]
	ldrb r0, [r7]
	adds r0, r0, r5
	str r3, [sp]
	bl sub_08035194
	ldrb r1, [r4]
	mov r0, r8
	ands r0, r1
	ldr r3, [sp]
	cmp r0, #0
	bne _0802E26E
	ldrb r0, [r7]
	adds r1, r0, r5
	lsls r0, r1, #8
	adds r0, r0, r3
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802E26E
	adds r0, r1, #0
	bl add_bot_to_defeated_list
_0802E26E:
	adds r5, #1
	cmp r5, #2
	bls _0802E1E0
	ldr r1, _0802E28C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802E28C: .4byte 0x03001800
_0802E290: .4byte 0x03000590
	.syntax divided
