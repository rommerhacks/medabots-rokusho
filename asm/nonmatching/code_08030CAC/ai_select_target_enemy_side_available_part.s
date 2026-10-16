	.syntax unified

	thumb_func_start ai_select_target_enemy_side_available_part
ai_select_target_enemy_side_available_part: @ 0x08032478
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _080324F4 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _080324F8 @ =0x03000590
	adds r5, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r5
	mov r8, r0
_0803249E:
	ldrb r1, [r4]
	lsls r0, r1, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _080324D6
	adds r0, r1, #0
	bl find_random_available_part_slot
	cmp r0, #0
	beq _080324D6
	ldrb r0, [r4]
	adds r1, r5, #0
	adds r1, #0x5c
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r1, r1, r7
	ldrb r1, [r1, #6]
	bl sub_08032FD0
	cmp r0, #0
	beq _080324D6
	mov r0, r8
	adds r1, r6, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_080324D6:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r6, #1
	cmp r6, #2
	bls _0803249E
	bl sub_08032FFC
	cmp r0, #0
	beq _080324FC
	bl select_battle_pending_action
	ldr r1, _080324F4 @ =0x03001800
	adds r0, #1
	b _080325EC
	.align 2, 0
_080324F4: .4byte 0x03001800
_080324F8: .4byte 0x03000590
_080324FC:
	ldr r4, _08032554 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _08032558 @ =0x03000590
	adds r5, r1, #0
	adds r4, #0x61
_08032516:
	ldrb r1, [r5]
	lsls r0, r1, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032536
	adds r0, r1, #0
	bl find_random_available_part_slot
	cmp r0, #0
	beq _08032536
	adds r1, r6, r4
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r1]
_08032536:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	adds r6, #1
	cmp r6, #2
	bls _08032516
	bl sub_08032FFC
	cmp r0, #0
	beq _0803255C
	bl select_battle_pending_action
	ldr r1, _08032554 @ =0x03001800
	adds r0, #1
	b _080325EC
	.align 2, 0
_08032554: .4byte 0x03001800
_08032558: .4byte 0x03000590
_0803255C:
	ldr r4, _080325C8 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _080325CC @ =0x03000590
	adds r5, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r5
	mov r8, r0
_0803257C:
	ldrb r2, [r4]
	lsls r0, r2, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _080325AA
	adds r0, r5, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r7
	ldrb r1, [r0, #6]
	adds r0, r2, #0
	bl sub_08032FD0
	cmp r0, #0
	beq _080325AA
	mov r0, r8
	adds r1, r6, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_080325AA:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r6, #1
	cmp r6, #2
	bls _0803257C
	bl sub_08032FFC
	cmp r0, #0
	beq _080325D0
	bl select_battle_pending_action
	ldr r1, _080325C8 @ =0x03001800
	adds r0, #1
	b _080325EC
	.align 2, 0
_080325C8: .4byte 0x03001800
_080325CC: .4byte 0x03000590
_080325D0:
	ldr r4, _0803260C @ =0x03001800
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
_080325EC:
	adds r1, #0x5e
	strb r0, [r1]
	ldr r4, _0803260C @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x5e
	ldrb r0, [r5]
	subs r0, #1
	bl find_random_available_part_slot
	adds r2, r0, #0
	cmp r2, #0
	beq _08032610
	adds r0, r4, #0
	adds r0, #0x5f
	strb r2, [r0]
	b _08032620
	.align 2, 0
_0803260C: .4byte 0x03001800
_08032610:
	ldrb r0, [r5]
	subs r0, #1
	bl sub_080330E8
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0x5f
	strb r0, [r1]
_08032620:
	ldr r1, _0803263C @ =0x03001800
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
_0803263C: .4byte 0x03001800
	.syntax divided
