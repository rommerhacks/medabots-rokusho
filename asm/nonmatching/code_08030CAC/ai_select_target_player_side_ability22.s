	.syntax unified

	thumb_func_start ai_select_target_player_side_ability22
ai_select_target_player_side_ability22: @ 0x08032DA0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08032E28 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _08032E2C @ =0x03000590
	adds r5, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r5
	mov r8, r0
_08032DC6:
	ldrb r1, [r4]
	lsls r0, r1, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032E08
	adds r0, r1, #0
	bl sub_080331F8
	cmp r0, #0
	beq _08032E08
	ldrb r0, [r4]
	bl sub_08033240
	cmp r0, #0
	beq _08032E08
	ldrb r0, [r4]
	adds r1, r5, #0
	adds r1, #0x5c
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r1, r1, r7
	ldrb r1, [r1, #6]
	bl sub_08032FD0
	cmp r0, #0
	beq _08032E08
	mov r0, r8
	adds r1, r6, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_08032E08:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r6, #1
	cmp r6, #2
	bls _08032DC6
	bl sub_08032FFC
	cmp r0, #0
	beq _08032E30
	bl select_battle_pending_action
	ldr r1, _08032E28 @ =0x03001800
	adds r0, #1
	b _08032F2C
	.align 2, 0
_08032E28: .4byte 0x03001800
_08032E2C: .4byte 0x03000590
_08032E30:
	ldr r4, _08032E94 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _08032E98 @ =0x03000590
	adds r5, r1, #0
	adds r4, #0x61
_08032E4A:
	ldrb r1, [r5]
	lsls r0, r1, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032E74
	adds r0, r1, #0
	bl sub_080331F8
	cmp r0, #0
	beq _08032E74
	ldrb r0, [r5]
	bl sub_08033240
	cmp r0, #0
	beq _08032E74
	adds r1, r6, r4
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r1]
_08032E74:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	adds r6, #1
	cmp r6, #2
	bls _08032E4A
	bl sub_08032FFC
	cmp r0, #0
	beq _08032E9C
	bl select_battle_pending_action
	ldr r1, _08032E94 @ =0x03001800
	adds r0, #1
	b _08032F2C
	.align 2, 0
_08032E94: .4byte 0x03001800
_08032E98: .4byte 0x03000590
_08032E9C:
	ldr r4, _08032F08 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _08032F0C @ =0x03000590
	adds r5, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r5
	mov r8, r0
_08032EBC:
	ldrb r2, [r4]
	lsls r0, r2, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032EEA
	adds r0, r5, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r7
	ldrb r1, [r0, #6]
	adds r0, r2, #0
	bl sub_08032FD0
	cmp r0, #0
	beq _08032EEA
	mov r0, r8
	adds r1, r6, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_08032EEA:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r6, #1
	cmp r6, #2
	bls _08032EBC
	bl sub_08032FFC
	cmp r0, #0
	beq _08032F10
	bl select_battle_pending_action
	ldr r1, _08032F08 @ =0x03001800
	adds r0, #1
	b _08032F2C
	.align 2, 0
_08032F08: .4byte 0x03001800
_08032F0C: .4byte 0x03000590
_08032F10:
	ldr r4, _08032F60 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	ldrb r0, [r1]
	bl select_random_battle_target
	adds r0, #1
	adds r1, r4, #0
_08032F2C:
	adds r1, #0x5e
	strb r0, [r1]
	ldr r4, _08032F60 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5e
	ldrb r0, [r0]
	subs r0, #1
	bl battle_find_next_active_bot
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
_08032F60: .4byte 0x03001800
	.syntax divided
