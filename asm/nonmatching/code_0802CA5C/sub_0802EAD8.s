	.syntax unified

	thumb_func_start sub_0802EAD8
sub_0802EAD8: @ 0x0802EAD8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r6, #0
	ldr r7, _0802EBB8 @ =0x03001800
	movs r0, #0xc8
	adds r0, r0, r7
	mov sl, r0
	movs r0, #0x7f
	mov sb, r0
_0802EAF2:
	adds r0, r7, #0
	adds r0, #0xd2
	adds r5, r6, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0802EB96
	ldr r0, _0802EBBC @ =0x03000590
	mov r8, r0
	adds r3, r7, #0
	adds r3, #0x60
	ldrb r0, [r3]
	adds r0, r0, r6
	lsls r0, r0, #8
	add r0, r8
	adds r0, #0xc1
	movs r1, #0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, r0, r6
	str r3, [sp]
	bl get_random_battle_weight_entry
	strb r0, [r5]
	ldr r3, [sp]
	ldrb r0, [r3]
	adds r0, r0, r6
	ldrb r1, [r5]
	lsls r4, r6, #1
	adds r2, r7, #0
	adds r2, #0xd6
	adds r4, r4, r2
	ldrh r2, [r4]
	bl battle_set_damage_vs_armor
	adds r0, r7, #0
	adds r0, #0xd1
	ldrb r0, [r0]
	lsls r0, r0, #7
	ldrb r1, [r5]
	orrs r0, r1
	strb r0, [r5]
	mov r0, sl
	ldrh r2, [r0]
	strh r2, [r4]
	ldrb r1, [r5]
	mov r0, sb
	ands r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r3, [sp]
	ldrb r0, [r3]
	adds r0, r0, r6
	lsls r0, r0, #8
	adds r1, r1, r0
	add r1, r8
	adds r1, #0x59
	ldrb r0, [r1]
	subs r0, r0, r2
	strb r0, [r1]
	ldrb r0, [r3]
	adds r0, r0, r6
	str r3, [sp]
	bl sub_08035194
	ldrb r1, [r5]
	mov r0, sb
	ands r0, r1
	ldr r3, [sp]
	cmp r0, #0
	bne _0802EB96
	ldrb r0, [r3]
	adds r1, r0, r6
	lsls r0, r1, #8
	add r0, r8
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802EB96
	adds r0, r1, #0
	bl add_bot_to_defeated_list
_0802EB96:
	adds r6, #1
	cmp r6, #2
	bls _0802EAF2
	ldr r1, _0802EBB8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802EBB8: .4byte 0x03001800
_0802EBBC: .4byte 0x03000590
	.syntax divided
