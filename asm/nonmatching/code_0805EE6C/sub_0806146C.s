	.syntax unified

	thumb_func_start sub_0806146C
sub_0806146C: @ 0x0806146C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r3, #0
	ldr r6, _080614A4 @ =0x03001780
	ldr r0, _080614A8 @ =0x0300058C
	mov r8, r0
	ldr r4, _080614AC @ =0x03002C30
	ldr r5, _080614B0 @ =0x0000BFFF
_0806147E:
	ldr r0, [r6]
	lsrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080614B4
	lsls r3, r3, #0x18
	asrs r1, r3, #0x12
	movs r7, #0xc0
	lsls r7, r7, #2
	adds r1, r1, r7
	adds r1, r1, r4
	ldrh r2, [r1]
	movs r7, #0x80
	lsls r7, r7, #7
	adds r0, r7, #0
	orrs r0, r2
	strh r0, [r1]
	b _080614D4
	.align 2, 0
_080614A4: .4byte 0x03001780
_080614A8: .4byte 0x0300058C
_080614AC: .4byte 0x03002C30
_080614B0: .4byte 0x0000BFFF
_080614B4:
	ldr r0, _080615D0 @ =0x03006F74
	ldr r0, [r0]
	ldrb r2, [r0, #0x19]
	lsls r0, r3, #0x18
	asrs r1, r0, #0x18
	adds r3, r0, #0
	cmp r2, r1
	bne _080614D4
	adds r0, r2, #0
	adds r0, #0xc
	lsls r0, r0, #6
	adds r0, r0, r4
	ldrh r2, [r0]
	adds r1, r5, #0
	ands r1, r2
	strh r1, [r0]
_080614D4:
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r3, r1
	lsrs r3, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	ble _0806147E
	mov r4, r8
	ldrb r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08061506
	movs r0, #2
	bl play_sound_effect
	ldr r0, _080615D0 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #0
	strb r0, [r1, #0x19]
	ldr r0, _080615D4 @ =0x03001780
	ldr r1, [r0]
	movs r0, #0
	bl battle_menu_highlight_icons
_08061506:
	ldrb r1, [r4]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08061528
	movs r0, #2
	bl play_sound_effect
	ldr r0, _080615D0 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #3
	strb r0, [r1, #0x19]
	ldr r0, _080615D4 @ =0x03001780
	ldr r1, [r0]
	movs r0, #3
	bl battle_menu_highlight_icons
_08061528:
	ldrb r1, [r4]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0806154A
	movs r0, #2
	bl play_sound_effect
	ldr r0, _080615D0 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #1
	strb r0, [r1, #0x19]
	ldr r0, _080615D4 @ =0x03001780
	ldr r1, [r0]
	movs r0, #1
	bl battle_menu_highlight_icons
_0806154A:
	ldrb r1, [r4]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0806156C
	movs r0, #2
	bl play_sound_effect
	ldr r0, _080615D0 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #2
	strb r0, [r1, #0x19]
	ldr r0, _080615D4 @ =0x03001780
	ldr r1, [r0]
	movs r0, #2
	bl battle_menu_highlight_icons
_0806156C:
	ldr r0, _080615D4 @ =0x03001780
	ldr r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _08061582
	ldr r0, _080615D0 @ =0x03006F74
	ldr r0, [r0]
	ldrb r0, [r0, #0x19]
	bl battle_menu_highlight_icons
_08061582:
	mov r3, r8
	ldrb r1, [r3]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08061600
	movs r0, #4
	bl play_sound_effect
	movs r3, #0
	ldr r5, _080615D8 @ =0x03002C30
	movs r7, #0x80
	lsls r7, r7, #7
	adds r4, r7, #0
_0806159E:
	lsls r2, r3, #0x18
	asrs r2, r2, #0x18
	adds r1, r2, #0
	adds r1, #0xc
	lsls r1, r1, #6
	adds r1, r1, r5
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	adds r2, #1
	lsls r2, r2, #0x18
	lsrs r3, r2, #0x18
	asrs r2, r2, #0x18
	cmp r2, #3
	ble _0806159E
	ldr r0, _080615D0 @ =0x03006F74
	ldr r2, [r0]
	ldrb r0, [r2, #0x19]
	cmp r0, #4
	bne _080615E0
_080615C6:
	ldr r1, _080615DC @ =0x0300137C
	movs r0, #0xb
	str r0, [r1]
	b _0806166C
	.align 2, 0
_080615D0: .4byte 0x03006F74
_080615D4: .4byte 0x03001780
_080615D8: .4byte 0x03002C30
_080615DC: .4byte 0x0300137C
_080615E0:
	ldr r0, _080615F8 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	adds r1, r2, #0
	adds r1, #0x48
	movs r0, #0x2d
	strb r0, [r1]
	ldr r1, _080615FC @ =0x0300137C
	movs r0, #0xc
	str r0, [r1]
	b _0806166C
	.align 2, 0
_080615F8: .4byte 0x03000440
_080615FC: .4byte 0x0300137C
_08061600:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0806166C
	movs r0, #5
	bl play_sound_effect
	movs r3, #0
	ldr r4, _08061660 @ =0x03002C30
	ldr r5, _08061664 @ =0x0000BFFF
	adds r6, r4, #0
_08061616:
	lsls r1, r3, #0x18
	asrs r1, r1, #0x18
	adds r2, r1, #0
	adds r2, #0xc
	lsls r2, r2, #6
	adds r2, r2, r4
	ldrh r3, [r2]
	adds r0, r5, #0
	ands r0, r3
	strh r0, [r2]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #3
	ble _08061616
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	adds r7, r3, #0
	adds r2, r6, r7
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08061668 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #0x10
	strh r0, [r1, #2]
	b _080615C6
	.align 2, 0
_08061660: .4byte 0x03002C30
_08061664: .4byte 0x0000BFFF
_08061668: .4byte 0x03006F74
_0806166C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
