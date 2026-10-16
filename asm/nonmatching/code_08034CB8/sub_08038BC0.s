	.syntax unified

	thumb_func_start sub_08038BC0
	.global sub_08038BC0
sub_08038BC0: @ 0x08038BC0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08038D28 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0xe8
	movs r0, #0
	strh r0, [r5]
	adds r7, r4, #0
	adds r7, #0x87
	ldrb r0, [r7]
	adds r6, r4, #0
	adds r6, #0xa7
	ldrb r1, [r6]
	bl calc_battle_action_speed
	ldrb r0, [r7]
	ldrb r1, [r6]
	movs r2, #0x88
	adds r2, r2, r4
	mov r8, r2
	ldrb r2, [r2]
	bl check_bot_ability_type_strike
	cmp r0, #0
	beq _08038C12
	ldr r2, _08038D2C @ =0x03000590
	ldrb r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r7]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	adds r0, #0x4d
	ldrb r0, [r0]
	lsls r0, r0, #4
	ldrh r3, [r5]
	adds r0, r0, r3
	strh r0, [r5]
_08038C12:
	ldrb r0, [r7]
	ldrb r1, [r6]
	mov r3, r8
	ldrb r2, [r3]
	bl check_bot_ability_type_shoot
	cmp r0, #0
	beq _08038C40
	ldr r2, _08038D2C @ =0x03000590
	ldrb r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r7]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	adds r0, #0x4d
	ldrb r0, [r0]
	lsls r0, r0, #4
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r5]
_08038C40:
	ldr r2, _08038D2C @ =0x03000590
	mov r8, r2
	ldrb r3, [r7]
	lsls r2, r3, #8
	mov r1, r8
	adds r0, r2, r1
	adds r0, #0xd6
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08038C6E
	ldrb r0, [r6]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	add r1, r8
	adds r1, #0x4d
	ldrh r0, [r5]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5]
_08038C6E:
	adds r0, r4, #0
	adds r0, #0x89
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r4
	adds r0, #0x28
	ldrh r1, [r5]
	ldrb r0, [r0]
	adds r1, r1, r0
	strh r1, [r5]
	adds r0, r3, #0
	bl sub_080358F0
	ldrb r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r7]
	lsls r1, r1, #8
	adds r0, r0, r1
	add r0, r8
	adds r2, r0, #0
	adds r2, #0x49
	ldrb r2, [r2]
	cmp r2, #8
	beq _08038CA6
	cmp r2, #9
	bne _08038CB2
_08038CA6:
	adds r1, r0, #0
	adds r1, #0x4d
	ldrh r0, [r5]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5]
_08038CB2:
	ldr r2, _08038D2C @ =0x03000590
	ldr r3, _08038D28 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xa7
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r1, r3, #0
	adds r1, #0x87
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	adds r0, #0x49
	ldrb r0, [r0]
	adds r4, r3, #0
	cmp r0, #0x34
	bne _08038CFA
	adds r0, r4, #0
	adds r0, #0x8a
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r1, r0, r4
	adds r0, r1, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	cmp r0, #0x33
	bne _08038CFA
	adds r2, r4, #0
	adds r2, #0xe8
	adds r1, #0x2c
	ldrh r0, [r2]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r2]
_08038CFA:
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl apply_battle_bot_damage_reduction
	adds r0, r4, #0
	adds r0, #0xe8
	ldr r2, _08038D2C @ =0x03000590
	adds r1, r4, #0
	adds r1, #0x88
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r1, r1, r2
	adds r1, #0xb9
	ldrb r1, [r1]
	bl sub_08035754
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038D28: .4byte 0x03001800
_08038D2C: .4byte 0x03000590
	.syntax divided
