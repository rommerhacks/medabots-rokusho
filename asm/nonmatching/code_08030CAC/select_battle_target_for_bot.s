	.syntax unified

	thumb_func_start select_battle_target_for_bot
select_battle_target_for_bot: @ 0x0803279C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08032814 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _08032818 @ =0x03000590
	adds r5, r4, #0
	adds r4, r1, #0
	movs r0, #0x61
	adds r0, r0, r5
	mov r8, r0
_080327C2:
	ldrb r2, [r4]
	lsls r0, r2, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _080327F6
	adds r0, r5, #0
	adds r0, #0x5c
	ldrb r1, [r0]
	cmp r2, r1
	beq _080327F6
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r7
	ldrb r1, [r0, #6]
	adds r0, r2, #0
	bl sub_08032FD0
	cmp r0, #0
	beq _080327F6
	mov r0, r8
	adds r1, r6, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r1]
_080327F6:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r6, #1
	cmp r6, #2
	bls _080327C2
	bl sub_08032FFC
	cmp r0, #0
	beq _0803281C
	bl select_battle_pending_action
	ldr r1, _08032814 @ =0x03001800
	adds r0, #1
	b _08032894
	.align 2, 0
_08032814: .4byte 0x03001800
_08032818: .4byte 0x03000590
_0803281C:
	ldr r4, _08032870 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x5c
	ldrb r0, [r5]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r7, _08032874 @ =0x03000590
	adds r3, r1, #0
	adds r4, #0x61
_08032836:
	ldrb r2, [r3]
	lsls r0, r2, #8
	adds r0, r0, r7
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032850
	ldrb r1, [r5]
	cmp r2, r1
	beq _08032850
	adds r1, r6, r4
	adds r0, r2, #1
	strb r0, [r1]
_08032850:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	adds r6, #1
	cmp r6, #2
	bls _08032836
	bl sub_08032FFC
	cmp r0, #0
	beq _08032878
	bl select_battle_pending_action
	ldr r1, _08032870 @ =0x03001800
	adds r0, #1
	b _08032894
	.align 2, 0
_08032870: .4byte 0x03001800
_08032874: .4byte 0x03000590
_08032878:
	ldr r4, _080328B4 @ =0x03001800
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
_08032894:
	adds r1, #0x5e
	strb r0, [r1]
	ldr r1, _080328B4 @ =0x03001800
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
_080328B4: .4byte 0x03001800
	.syntax divided
