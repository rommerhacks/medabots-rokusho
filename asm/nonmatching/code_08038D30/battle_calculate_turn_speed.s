	.syntax unified

	thumb_func_start battle_calculate_turn_speed
battle_calculate_turn_speed: @ 0x08038F84
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r5, _08038FF0 @ =0x03001800
	adds r6, r5, #0
	adds r6, #0xee
	movs r0, #0
	strh r0, [r6]
	ldr r7, _08038FF4 @ =0x03000590
	movs r0, #0x88
	adds r0, r0, r5
	mov r8, r0
	ldrb r2, [r0]
	lsls r0, r2, #8
	adds r0, r0, r7
	adds r0, #0xbc
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0803905C
	adds r0, r2, #0
	bl accumulate_battle_speed_value
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0xa3
	ldrh r1, [r6]
	ldrb r0, [r0]
	adds r1, r1, r0
	strh r1, [r6]
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0xbc
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08038FE2
	adds r0, r6, #0
	movs r1, #8
	bl sub_08035754
_08038FE2:
	bl battle_calculate_damage_modifier
	cmp r0, #0
	beq _08038FF8
	movs r0, #1
	b _0803905E
	.align 2, 0
_08038FF0: .4byte 0x03001800
_08038FF4: .4byte 0x03000590
_08038FF8:
	adds r4, r5, #0
	adds r4, #0xe8
	movs r0, #0
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl sub_08035754
	ldrh r0, [r4]
	adds r1, r5, #0
	adds r1, #0xf2
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0803905C
	adds r0, r5, #0
	adds r0, #0xa7
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r1, r5, #0
	adds r1, #0x87
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r7
	adds r0, #0x49
	ldrb r0, [r0]
	cmp r0, #6
	beq _0803905C
	cmp r0, #7
	beq _0803905C
	adds r0, r1, r7
	adds r0, #0xd6
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803905C
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0xbc
	ldrb r2, [r0]
	movs r1, #0x10
	orrs r1, r2
	strb r1, [r0]
	movs r0, #1
	b _0803905E
_0803905C:
	movs r0, #0
_0803905E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
