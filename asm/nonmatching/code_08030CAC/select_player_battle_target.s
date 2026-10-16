	.syntax unified

	thumb_func_start select_player_battle_target
select_player_battle_target: @ 0x08032C08
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08032C84 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _08032C88 @ =0x03000590
	adds r5, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r5
	mov r8, r0
_08032C2E:
	ldrb r1, [r4]
	lsls r0, r1, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032C66
	adds r0, r1, #0
	bl sub_080332D0
	cmp r0, #0
	beq _08032C66
	ldrb r0, [r4]
	adds r1, r5, #0
	adds r1, #0x5c
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r1, r1, r7
	ldrb r1, [r1, #6]
	bl sub_08032FD0
	cmp r0, #0
	beq _08032C66
	mov r0, r8
	adds r1, r6, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_08032C66:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r6, #1
	cmp r6, #2
	bls _08032C2E
	bl sub_08032FFC
	cmp r0, #0
	beq _08032C8C
	bl select_battle_pending_action
	ldr r1, _08032C84 @ =0x03001800
	adds r0, #1
	b _08032D7C
	.align 2, 0
_08032C84: .4byte 0x03001800
_08032C88: .4byte 0x03000590
_08032C8C:
	ldr r4, _08032CE4 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _08032CE8 @ =0x03000590
	adds r5, r1, #0
	adds r4, #0x61
_08032CA6:
	ldrb r1, [r5]
	lsls r0, r1, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032CC6
	adds r0, r1, #0
	bl sub_080332D0
	cmp r0, #0
	beq _08032CC6
	adds r1, r6, r4
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r1]
_08032CC6:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	adds r6, #1
	cmp r6, #2
	bls _08032CA6
	bl sub_08032FFC
	cmp r0, #0
	beq _08032CEC
	bl select_battle_pending_action
	ldr r1, _08032CE4 @ =0x03001800
	adds r0, #1
	b _08032D7C
	.align 2, 0
_08032CE4: .4byte 0x03001800
_08032CE8: .4byte 0x03000590
_08032CEC:
	ldr r4, _08032D58 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _08032D5C @ =0x03000590
	adds r5, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r5
	mov r8, r0
_08032D0C:
	ldrb r2, [r4]
	lsls r0, r2, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032D3A
	adds r0, r5, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r7
	ldrb r1, [r0, #6]
	adds r0, r2, #0
	bl sub_08032FD0
	cmp r0, #0
	beq _08032D3A
	mov r0, r8
	adds r1, r6, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_08032D3A:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r6, #1
	cmp r6, #2
	bls _08032D0C
	bl sub_08032FFC
	cmp r0, #0
	beq _08032D60
	bl select_battle_pending_action
	ldr r1, _08032D58 @ =0x03001800
	adds r0, #1
	b _08032D7C
	.align 2, 0
_08032D58: .4byte 0x03001800
_08032D5C: .4byte 0x03000590
_08032D60:
	ldr r4, _08032D9C @ =0x03001800
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
_08032D7C:
	adds r1, #0x5e
	strb r0, [r1]
	ldr r1, _08032D9C @ =0x03001800
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
_08032D9C: .4byte 0x03001800
	.syntax divided
