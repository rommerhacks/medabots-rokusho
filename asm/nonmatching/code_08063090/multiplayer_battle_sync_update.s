	.syntax unified

	thumb_func_start multiplayer_battle_sync_update
multiplayer_battle_sync_update: @ 0x08065994
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08065A20 @ =0x03005010
	ldr r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080659B8
	ldr r0, _08065A24 @ =0x03001780
	ldr r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _080659B8
	bl serial_link_init
_080659B8:
	bl sub_08002190
	bl init_multiplayer_id
	ldr r5, _08065A20 @ =0x03005010
	ldr r7, _08065A28 @ =0x03006F74
	ldr r6, [r7]
	movs r0, #0x49
	adds r0, r0, r6
	mov ip, r0
	ldrb r0, [r0]
	movs r2, #0xff
	lsls r2, r2, #8
	adds r1, r2, #0
	movs r2, #0
	mov r8, r2
	orrs r0, r1
	strh r0, [r5, #6]
	ldr r0, _08065A2C @ =0x03000B90
	ldrb r2, [r0]
	lsls r0, r2, #2
	adds r3, r5, #0
	adds r3, #0xa
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _08065A30 @ =0x0000FF01
	cmp r0, r4
	bne _08065A58
	adds r1, r2, #0
	movs r0, #0
	cmp r1, #0
	bne _080659FA
	movs r0, #4
_080659FA:
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, r4
	bne _08065A88
	cmp r1, #1
	bhi _08065A3C
	ldr r1, _08065A34 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	mov r0, r8
	strh r0, [r6, #0x3a]
	ldr r1, _08065A38 @ =0x03005030
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r2, #0
	strb r0, [r1]
	b _08065AFA
	.align 2, 0
_08065A20: .4byte 0x03005010
_08065A24: .4byte 0x03001780
_08065A28: .4byte 0x03006F74
_08065A2C: .4byte 0x03000B90
_08065A30: .4byte 0x0000FF01
_08065A34: .4byte 0x0300137C
_08065A38: .4byte 0x03005030
_08065A3C:
	bl sub_0803FB0C
	ldr r1, [r7]
	movs r0, #1
	str r0, [r1, #8]
	ldr r1, _08065A54 @ =0x0300137C
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	mov r0, r8
	strh r0, [r5, #6]
	b _08065A88
	.align 2, 0
_08065A54: .4byte 0x0300137C
_08065A58:
	ldr r0, [r5]
	movs r1, #3
	ands r0, r1
	cmp r0, #3
	bne _08065A88
	movs r1, #0
	cmp r2, #0
	bne _08065A6A
	movs r1, #4
_08065A6A:
	adds r1, r1, r3
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08065A88
	strh r4, [r5, #6]
	movs r0, #1
	mov r1, ip
	strb r0, [r1]
	b _08065AFA
_08065A88:
	ldr r4, _08065AB8 @ =0x03006F74
	ldr r2, [r4]
	ldrh r0, [r2, #0x3a]
	adds r0, #1
	movs r5, #0
	strh r0, [r2, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	ble _08065AC4
	bl sub_0803FB0C
	ldr r1, [r4]
	movs r0, #1
	str r0, [r1, #8]
	ldr r1, _08065ABC @ =0x0300137C
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r0, _08065AC0 @ =0x03005010
	strh r5, [r0, #6]
	b _08065AFA
	.align 2, 0
_08065AB8: .4byte 0x03006F74
_08065ABC: .4byte 0x0300137C
_08065AC0: .4byte 0x03005010
_08065AC4:
	movs r0, #0x86
	lsls r0, r0, #1
	cmp r1, r0
	ble _08065AFA
	ldr r3, _08065AF0 @ =0x03005010
	ldr r0, _08065AF4 @ =0x03000B90
	ldrb r0, [r0]
	movs r1, #0
	cmp r0, #0
	bne _08065ADA
	movs r1, #4
_08065ADA:
	adds r0, r3, #0
	adds r0, #0xa
	adds r0, r1, r0
	ldrh r1, [r0]
	movs r0, #0xff
	lsls r0, r0, #8
	cmp r1, r0
	bne _08065AF8
	strh r5, [r2, #0x3a]
	b _08065AFA
	.align 2, 0
_08065AF0: .4byte 0x03005010
_08065AF4: .4byte 0x03000B90
_08065AF8:
	strh r5, [r3, #6]
_08065AFA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
