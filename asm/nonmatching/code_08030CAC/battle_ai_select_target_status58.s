	.syntax unified

	thumb_func_start battle_ai_select_target_status58
battle_ai_select_target_status58: @ 0x08032A68
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08032AE4 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _08032AE8 @ =0x03000590
	adds r5, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r5
	mov r8, r0
_08032A8E:
	ldrb r1, [r4]
	lsls r0, r1, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032AC6
	adds r0, r1, #0
	bl sub_080332B4
	cmp r0, #0
	beq _08032AC6
	ldrb r0, [r4]
	adds r1, r5, #0
	adds r1, #0x5c
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r1, r1, r7
	ldrb r1, [r1, #6]
	bl sub_08032FD0
	cmp r0, #0
	beq _08032AC6
	mov r0, r8
	adds r1, r6, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_08032AC6:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r6, #1
	cmp r6, #2
	bls _08032A8E
	bl sub_08032FFC
	cmp r0, #0
	beq _08032AEC
	bl select_battle_pending_action
	ldr r1, _08032AE4 @ =0x03001800
	adds r0, #1
	b _08032BDC
	.align 2, 0
_08032AE4: .4byte 0x03001800
_08032AE8: .4byte 0x03000590
_08032AEC:
	ldr r4, _08032B44 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _08032B48 @ =0x03000590
	adds r5, r1, #0
	adds r4, #0x61
_08032B06:
	ldrb r1, [r5]
	lsls r0, r1, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032B26
	adds r0, r1, #0
	bl sub_080332B4
	cmp r0, #0
	beq _08032B26
	adds r1, r6, r4
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r1]
_08032B26:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	adds r6, #1
	cmp r6, #2
	bls _08032B06
	bl sub_08032FFC
	cmp r0, #0
	beq _08032B4C
	bl select_battle_pending_action
	ldr r1, _08032B44 @ =0x03001800
	adds r0, #1
	b _08032BDC
	.align 2, 0
_08032B44: .4byte 0x03001800
_08032B48: .4byte 0x03000590
_08032B4C:
	ldr r4, _08032BB8 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _08032BBC @ =0x03000590
	adds r5, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r5
	mov r8, r0
_08032B6C:
	ldrb r2, [r4]
	lsls r0, r2, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032B9A
	adds r0, r5, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r7
	ldrb r1, [r0, #6]
	adds r0, r2, #0
	bl sub_08032FD0
	cmp r0, #0
	beq _08032B9A
	mov r0, r8
	adds r1, r6, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_08032B9A:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r6, #1
	cmp r6, #2
	bls _08032B6C
	bl sub_08032FFC
	cmp r0, #0
	beq _08032BC0
	bl select_battle_pending_action
	ldr r1, _08032BB8 @ =0x03001800
	adds r0, #1
	b _08032BDC
	.align 2, 0
_08032BB8: .4byte 0x03001800
_08032BBC: .4byte 0x03000590
_08032BC0:
	ldr r4, _08032C04 @ =0x03001800
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
_08032BDC:
	adds r1, #0x5e
	strb r0, [r1]
	ldr r1, _08032C04 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0x5f
	movs r0, #1
	strb r0, [r2]
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
_08032C04: .4byte 0x03001800
	.syntax divided
