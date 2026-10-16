	.syntax unified

	thumb_func_start ai_select_target_enemy_side_ability22_status
ai_select_target_enemy_side_ability22_status: @ 0x08031F2C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08031FB8 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r7, _08031FBC @ =0x03000590
	adds r6, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r6
	mov r8, r0
_08031F52:
	ldrb r1, [r4]
	lsls r0, r1, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031F98
	adds r0, r1, #0
	bl sub_080331F8
	cmp r0, #0
	beq _08031F98
	ldrb r2, [r4]
	lsls r0, r2, #8
	adds r0, r0, r7
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031F98
	adds r0, r6, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r7
	ldrb r1, [r0, #6]
	adds r0, r2, #0
	bl sub_08032FD0
	cmp r0, #0
	beq _08031F98
	mov r0, r8
	adds r1, r5, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_08031F98:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r5, #1
	cmp r5, #2
	bls _08031F52
	bl sub_08032FFC
	cmp r0, #0
	beq _08031FC0
	bl select_battle_pending_action
	ldr r1, _08031FB8 @ =0x03001800
	adds r0, #1
	b _080320C8
	.align 2, 0
_08031FB8: .4byte 0x03001800
_08031FBC: .4byte 0x03000590
_08031FC0:
	ldr r4, _08032024 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r7, _08032028 @ =0x03000590
	adds r6, r1, #0
	adds r4, #0x61
_08031FDA:
	ldrb r1, [r6]
	lsls r0, r1, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032006
	adds r0, r1, #0
	bl sub_080331F8
	cmp r0, #0
	beq _08032006
	ldrb r2, [r6]
	lsls r0, r2, #8
	adds r0, r0, r7
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032006
	adds r1, r5, r4
	adds r0, r2, #1
	strb r0, [r1]
_08032006:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	adds r5, #1
	cmp r5, #2
	bls _08031FDA
	bl sub_08032FFC
	cmp r0, #0
	beq _0803202C
	bl select_battle_pending_action
	ldr r1, _08032024 @ =0x03001800
	adds r0, #1
	b _080320C8
	.align 2, 0
_08032024: .4byte 0x03001800
_08032028: .4byte 0x03000590
_0803202C:
	ldr r4, _080320A4 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r7, _080320A8 @ =0x03000590
	adds r6, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r6
	mov r8, r0
_0803204C:
	ldrb r1, [r4]
	lsls r0, r1, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032084
	adds r0, r1, #0
	bl sub_080331F8
	cmp r0, #0
	beq _08032084
	ldrb r0, [r4]
	adds r1, r6, #0
	adds r1, #0x5c
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r1, r1, r7
	ldrb r1, [r1, #6]
	bl sub_08032FD0
	cmp r0, #0
	beq _08032084
	mov r0, r8
	adds r1, r5, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_08032084:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r5, #1
	cmp r5, #2
	bls _0803204C
	bl sub_08032FFC
	cmp r0, #0
	beq _080320AC
	bl select_battle_pending_action
	ldr r1, _080320A4 @ =0x03001800
	adds r0, #1
	b _080320C8
	.align 2, 0
_080320A4: .4byte 0x03001800
_080320A8: .4byte 0x03000590
_080320AC:
	ldr r4, _080320FC @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	ldrb r0, [r1]
	bl select_random_battle_target
	adds r0, #1
	adds r1, r4, #0
_080320C8:
	adds r1, #0x5e
	strb r0, [r1]
	ldr r4, _080320FC @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5e
	ldrb r0, [r0]
	subs r0, #1
	bl sub_080330E8
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0x5f
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	subs r1, #2
	ldrb r1, [r1]
	bl sub_08033154
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080320FC: .4byte 0x03001800
	.syntax divided
