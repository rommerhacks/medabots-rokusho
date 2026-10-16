	.syntax unified

	thumb_func_start battle_ai_select_target_ability22_enemy
battle_ai_select_target_ability22_enemy: @ 0x080322C8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08032350 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _08032354 @ =0x03000590
	adds r5, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r5
	mov r8, r0
_080322EE:
	ldrb r1, [r4]
	lsls r0, r1, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032330
	adds r0, r1, #0
	bl sub_080331F8
	cmp r0, #0
	beq _08032330
	ldrb r0, [r4]
	bl sub_08033224
	cmp r0, #0
	beq _08032330
	ldrb r0, [r4]
	adds r1, r5, #0
	adds r1, #0x5c
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r1, r1, r7
	ldrb r1, [r1, #6]
	bl sub_08032FD0
	cmp r0, #0
	beq _08032330
	mov r0, r8
	adds r1, r6, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_08032330:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r6, #1
	cmp r6, #2
	bls _080322EE
	bl sub_08032FFC
	cmp r0, #0
	beq _08032358
	bl select_battle_pending_action
	ldr r1, _08032350 @ =0x03001800
	adds r0, #1
	b _08032454
	.align 2, 0
_08032350: .4byte 0x03001800
_08032354: .4byte 0x03000590
_08032358:
	ldr r4, _080323BC @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _080323C0 @ =0x03000590
	adds r5, r1, #0
	adds r4, #0x61
_08032372:
	ldrb r1, [r5]
	lsls r0, r1, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803239C
	adds r0, r1, #0
	bl sub_080331F8
	cmp r0, #0
	beq _0803239C
	ldrb r0, [r5]
	bl sub_08033224
	cmp r0, #0
	beq _0803239C
	adds r1, r6, r4
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r1]
_0803239C:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	adds r6, #1
	cmp r6, #2
	bls _08032372
	bl sub_08032FFC
	cmp r0, #0
	beq _080323C4
	bl select_battle_pending_action
	ldr r1, _080323BC @ =0x03001800
	adds r0, #1
	b _08032454
	.align 2, 0
_080323BC: .4byte 0x03001800
_080323C0: .4byte 0x03000590
_080323C4:
	ldr r4, _08032430 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _08032434 @ =0x03000590
	adds r5, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r5
	mov r8, r0
_080323E4:
	ldrb r2, [r4]
	lsls r0, r2, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032412
	adds r0, r5, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r7
	ldrb r1, [r0, #6]
	adds r0, r2, #0
	bl sub_08032FD0
	cmp r0, #0
	beq _08032412
	mov r0, r8
	adds r1, r6, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_08032412:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r6, #1
	cmp r6, #2
	bls _080323E4
	bl sub_08032FFC
	cmp r0, #0
	beq _08032438
	bl select_battle_pending_action
	ldr r1, _08032430 @ =0x03001800
	adds r0, #1
	b _08032454
	.align 2, 0
_08032430: .4byte 0x03001800
_08032434: .4byte 0x03000590
_08032438:
	ldr r4, _08032474 @ =0x03001800
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
_08032454:
	adds r1, #0x5e
	strb r0, [r1]
	ldr r1, _08032474 @ =0x03001800
	adds r0, r1, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	adds r1, #0x5d
	ldrb r1, [r1]
	bl sub_08033154
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08032474: .4byte 0x03001800
	.syntax divided
