	.syntax unified

	thumb_func_start ai_select_target_enemy_side_ewram_check
ai_select_target_enemy_side_ewram_check: @ 0x08032100
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _0803217C @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _08032180 @ =0x03000590
	adds r5, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r5
	mov r8, r0
_08032126:
	ldrb r1, [r4]
	lsls r0, r1, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803215E
	adds r0, r1, #0
	bl find_most_damaged_part
	cmp r0, #0
	beq _0803215E
	ldrb r0, [r4]
	adds r1, r5, #0
	adds r1, #0x5c
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r1, r1, r7
	ldrb r1, [r1, #6]
	bl sub_08032FD0
	cmp r0, #0
	beq _0803215E
	mov r0, r8
	adds r1, r6, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_0803215E:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r6, #1
	cmp r6, #2
	bls _08032126
	bl sub_08032FFC
	cmp r0, #0
	beq _08032184
	bl select_battle_pending_action
	ldr r1, _0803217C @ =0x03001800
	adds r0, #1
	b _08032274
	.align 2, 0
_0803217C: .4byte 0x03001800
_08032180: .4byte 0x03000590
_08032184:
	ldr r4, _080321DC @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _080321E0 @ =0x03000590
	adds r5, r1, #0
	adds r4, #0x61
_0803219E:
	ldrb r1, [r5]
	lsls r0, r1, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _080321BE
	adds r0, r1, #0
	bl find_most_damaged_part
	cmp r0, #0
	beq _080321BE
	adds r1, r6, r4
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r1]
_080321BE:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	adds r6, #1
	cmp r6, #2
	bls _0803219E
	bl sub_08032FFC
	cmp r0, #0
	beq _080321E4
	bl select_battle_pending_action
	ldr r1, _080321DC @ =0x03001800
	adds r0, #1
	b _08032274
	.align 2, 0
_080321DC: .4byte 0x03001800
_080321E0: .4byte 0x03000590
_080321E4:
	ldr r4, _08032250 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _08032254 @ =0x03000590
	adds r5, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r5
	mov r8, r0
_08032204:
	ldrb r2, [r4]
	lsls r0, r2, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032232
	adds r0, r5, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r7
	ldrb r1, [r0, #6]
	adds r0, r2, #0
	bl sub_08032FD0
	cmp r0, #0
	beq _08032232
	mov r0, r8
	adds r1, r6, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_08032232:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r6, #1
	cmp r6, #2
	bls _08032204
	bl sub_08032FFC
	cmp r0, #0
	beq _08032258
	bl select_battle_pending_action
	ldr r1, _08032250 @ =0x03001800
	adds r0, #1
	b _08032274
	.align 2, 0
_08032250: .4byte 0x03001800
_08032254: .4byte 0x03000590
_08032258:
	ldr r4, _08032294 @ =0x03001800
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
_08032274:
	adds r1, #0x5e
	strb r0, [r1]
	ldr r4, _08032294 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x5e
	ldrb r0, [r5]
	subs r0, #1
	bl find_most_damaged_part
	adds r2, r0, #0
	cmp r2, #0
	beq _08032298
	adds r0, r4, #0
	adds r0, #0x5f
	strb r2, [r0]
	b _080322A8
	.align 2, 0
_08032294: .4byte 0x03001800
_08032298:
	ldrb r0, [r5]
	subs r0, #1
	bl sub_080330E8
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0x5f
	strb r0, [r1]
_080322A8:
	ldr r1, _080322C4 @ =0x03001800
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
_080322C4: .4byte 0x03001800
	.syntax divided
