	.syntax unified

	thumb_func_start select_enemy_battle_target
select_enemy_battle_target: @ 0x08032640
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, _080326FC @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r7, _08032700 @ =0x03000590
	adds r6, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r6
	mov r8, r0
_08032668:
	ldrb r2, [r4]
	lsls r0, r2, #8
	adds r0, r0, r7
	adds r0, #0xba
	ldrb r0, [r0]
	cmp r0, #2
	bne _08032696
	adds r0, r6, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r7
	ldrb r1, [r0, #6]
	adds r0, r2, #0
	bl sub_08032FD0
	cmp r0, #0
	beq _08032696
	mov r0, r8
	adds r1, r5, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_08032696:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r5, #1
	cmp r5, #2
	bls _08032668
	bl sub_08032FFC
	cmp r0, #0
	bne _080326EC
	ldr r4, _080326FC @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r6, _08032700 @ =0x03000590
	adds r3, r1, #0
	adds r4, #0x61
_080326C4:
	ldrb r2, [r3]
	lsls r0, r2, #8
	adds r0, r0, r6
	adds r0, #0xba
	ldrb r0, [r0]
	cmp r0, #2
	bne _080326D8
	adds r1, r5, r4
	adds r0, r2, #1
	strb r0, [r1]
_080326D8:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	adds r5, #1
	cmp r5, #2
	bls _080326C4
	bl sub_08032FFC
	cmp r0, #0
	beq _08032704
_080326EC:
	bl select_battle_pending_action
	ldr r1, _080326FC @ =0x03001800
	adds r0, #1
	adds r1, #0x5e
	strb r0, [r1]
	b _0803277A
	.align 2, 0
_080326FC: .4byte 0x03001800
_08032700: .4byte 0x03000590
_08032704:
	ldr r4, _08032760 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	adds r7, r4, #0
	adds r4, r1, #0
	ldr r0, _08032764 @ =0x03000590
	mov sb, r0
	movs r0, #0x61
	adds r0, r0, r7
	mov r8, r0
_08032726:
	ldrb r0, [r4]
	adds r6, r7, #0
	adds r6, #0x5c
	ldrb r1, [r6]
	lsls r1, r1, #8
	add r1, sb
	ldrb r1, [r1, #6]
	bl sub_08032FD0
	cmp r0, #0
	beq _08032746
	mov r0, r8
	adds r1, r5, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_08032746:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r5, #1
	cmp r5, #2
	bls _08032726
	bl sub_08032FFC
	cmp r0, #0
	beq _08032768
	bl select_battle_pending_action
	b _08032776
	.align 2, 0
_08032760: .4byte 0x03001800
_08032764: .4byte 0x03000590
_08032768:
	ldrb r0, [r6]
	bl sub_08032FC4
	strb r0, [r6, #4]
	ldrb r0, [r6, #4]
	bl select_random_battle_target
_08032776:
	adds r0, #1
	strb r0, [r6, #2]
_0803277A:
	ldr r1, _08032798 @ =0x03001800
	adds r0, r1, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	adds r1, #0x5d
	ldrb r1, [r1]
	bl sub_08033154
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08032798: .4byte 0x03001800
	.syntax divided
