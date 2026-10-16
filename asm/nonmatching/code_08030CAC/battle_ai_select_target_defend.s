	.syntax unified

	thumb_func_start battle_ai_select_target_defend
battle_ai_select_target_defend: @ 0x08031BCC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08031C4C @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r7, _08031C50 @ =0x03000590
	adds r6, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r6
	mov r8, r0
_08031BF2:
	ldrb r2, [r4]
	lsls r0, r2, #8
	adds r1, r0, r7
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031C2C
	adds r0, r1, #0
	adds r0, #0x91
	ldrb r0, [r0]
	cmp r0, #0x64
	bne _08031C2C
	adds r0, r6, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r7
	ldrb r1, [r0, #6]
	adds r0, r2, #0
	bl sub_08032FD0
	cmp r0, #0
	beq _08031C2C
	mov r0, r8
	adds r1, r5, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_08031C2C:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r5, #1
	cmp r5, #2
	bls _08031BF2
	bl sub_08032FFC
	cmp r0, #0
	beq _08031C54
	bl select_battle_pending_action
	ldr r1, _08031C4C @ =0x03001800
	adds r0, #1
	b _08031D44
	.align 2, 0
_08031C4C: .4byte 0x03001800
_08031C50: .4byte 0x03000590
_08031C54:
	ldr r4, _08031CAC @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r6, _08031CB0 @ =0x03000590
	adds r3, r1, #0
	adds r4, #0x61
_08031C6E:
	ldrb r2, [r3]
	lsls r0, r2, #8
	adds r1, r0, r6
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031C8E
	adds r0, r1, #0
	adds r0, #0x91
	ldrb r0, [r0]
	cmp r0, #0x64
	bne _08031C8E
	adds r1, r5, r4
	adds r0, r2, #1
	strb r0, [r1]
_08031C8E:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	adds r5, #1
	cmp r5, #2
	bls _08031C6E
	bl sub_08032FFC
	cmp r0, #0
	beq _08031CB4
	bl select_battle_pending_action
	ldr r1, _08031CAC @ =0x03001800
	adds r0, #1
	b _08031D44
	.align 2, 0
_08031CAC: .4byte 0x03001800
_08031CB0: .4byte 0x03000590
_08031CB4:
	ldr r4, _08031D20 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r7, _08031D24 @ =0x03000590
	adds r6, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r6
	mov r8, r0
_08031CD4:
	ldrb r2, [r4]
	lsls r0, r2, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031D02
	adds r0, r6, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r7
	ldrb r1, [r0, #6]
	adds r0, r2, #0
	bl sub_08032FD0
	cmp r0, #0
	beq _08031D02
	mov r0, r8
	adds r1, r5, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_08031D02:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r5, #1
	cmp r5, #2
	bls _08031CD4
	bl sub_08032FFC
	cmp r0, #0
	beq _08031D28
	bl select_battle_pending_action
	ldr r1, _08031D20 @ =0x03001800
	adds r0, #1
	b _08031D44
	.align 2, 0
_08031D20: .4byte 0x03001800
_08031D24: .4byte 0x03000590
_08031D28:
	ldr r4, _08031D78 @ =0x03001800
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
_08031D44:
	adds r1, #0x5e
	strb r0, [r1]
	ldr r4, _08031D78 @ =0x03001800
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
_08031D78: .4byte 0x03001800
	.syntax divided
