	.syntax unified

	thumb_func_start select_battle_targets_and_actions
select_battle_targets_and_actions: @ 0x08031AFC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08031B70 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r7, _08031B74 @ =0x03000590
	adds r6, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r6
	mov r8, r0
_08031B22:
	ldrb r2, [r4]
	lsls r0, r2, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031B50
	adds r0, r6, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r7
	ldrb r1, [r0, #6]
	adds r0, r2, #0
	bl sub_08032FD0
	cmp r0, #0
	beq _08031B50
	mov r0, r8
	adds r1, r5, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_08031B50:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r5, #1
	cmp r5, #2
	bls _08031B22
	bl sub_08032FFC
	cmp r0, #0
	beq _08031B78
	bl select_battle_pending_action
	ldr r1, _08031B70 @ =0x03001800
	adds r0, #1
	b _08031B94
	.align 2, 0
_08031B70: .4byte 0x03001800
_08031B74: .4byte 0x03000590
_08031B78:
	ldr r4, _08031BC8 @ =0x03001800
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
_08031B94:
	adds r1, #0x5e
	strb r0, [r1]
	ldr r4, _08031BC8 @ =0x03001800
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
_08031BC8: .4byte 0x03001800
	.syntax divided
