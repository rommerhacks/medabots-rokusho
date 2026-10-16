	.syntax unified

	thumb_func_start battle_ai_select_target_jump
battle_ai_select_target_jump: @ 0x08031D7C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08031DFC @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r7, _08031E00 @ =0x03000590
	adds r6, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r6
	mov r8, r0
_08031DA2:
	ldrb r2, [r4]
	lsls r0, r2, #8
	adds r1, r0, r7
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031DDC
	adds r0, r1, #0
	adds r0, #0x91
	ldrb r0, [r0]
	cmp r0, #0x6a
	bne _08031DDC
	adds r0, r6, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r7
	ldrb r1, [r0, #6]
	adds r0, r2, #0
	bl sub_08032FD0
	cmp r0, #0
	beq _08031DDC
	mov r0, r8
	adds r1, r5, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_08031DDC:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r5, #1
	cmp r5, #2
	bls _08031DA2
	bl sub_08032FFC
	cmp r0, #0
	beq _08031E04
	bl select_battle_pending_action
	ldr r1, _08031DFC @ =0x03001800
	adds r0, #1
	b _08031EF4
	.align 2, 0
_08031DFC: .4byte 0x03001800
_08031E00: .4byte 0x03000590
_08031E04:
	ldr r4, _08031E5C @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r6, _08031E60 @ =0x03000590
	adds r3, r1, #0
	adds r4, #0x61
_08031E1E:
	ldrb r2, [r3]
	lsls r0, r2, #8
	adds r1, r0, r6
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031E3E
	adds r0, r1, #0
	adds r0, #0x91
	ldrb r0, [r0]
	cmp r0, #0x6a
	bne _08031E3E
	adds r1, r5, r4
	adds r0, r2, #1
	strb r0, [r1]
_08031E3E:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	adds r5, #1
	cmp r5, #2
	bls _08031E1E
	bl sub_08032FFC
	cmp r0, #0
	beq _08031E64
	bl select_battle_pending_action
	ldr r1, _08031E5C @ =0x03001800
	adds r0, #1
	b _08031EF4
	.align 2, 0
_08031E5C: .4byte 0x03001800
_08031E60: .4byte 0x03000590
_08031E64:
	ldr r4, _08031ED0 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r7, _08031ED4 @ =0x03000590
	adds r6, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r6
	mov r8, r0
_08031E84:
	ldrb r2, [r4]
	lsls r0, r2, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031EB2
	adds r0, r6, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r7
	ldrb r1, [r0, #6]
	adds r0, r2, #0
	bl sub_08032FD0
	cmp r0, #0
	beq _08031EB2
	mov r0, r8
	adds r1, r5, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_08031EB2:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r5, #1
	cmp r5, #2
	bls _08031E84
	bl sub_08032FFC
	cmp r0, #0
	beq _08031ED8
	bl select_battle_pending_action
	ldr r1, _08031ED0 @ =0x03001800
	adds r0, #1
	b _08031EF4
	.align 2, 0
_08031ED0: .4byte 0x03001800
_08031ED4: .4byte 0x03000590
_08031ED8:
	ldr r4, _08031F28 @ =0x03001800
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
_08031EF4:
	adds r1, #0x5e
	strb r0, [r1]
	ldr r4, _08031F28 @ =0x03001800
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
_08031F28: .4byte 0x03001800
	.syntax divided
