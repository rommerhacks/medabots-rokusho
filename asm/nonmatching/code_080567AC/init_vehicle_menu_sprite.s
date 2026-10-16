	.syntax unified

	thumb_func_start init_vehicle_menu_sprite
init_vehicle_menu_sprite: @ 0x08057F78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0
	bl check_vehicle_usability
	movs r3, #0xd
	cmp r0, #0
	bne _08057F94
	movs r3, #0xc
_08057F94:
	ldr r0, _080580A4 @ =0x0000C004
	mov sl, r0
	movs r1, #1
	mov sb, r1
	str r1, [sp]
	movs r0, #0x20
	mov r1, sl
	movs r2, #0x91
	bl init_battle_sprite_entry_08048818
	ldr r4, _080580A8 @ =0x03002C30
	ldr r0, _080580AC @ =0x030064A0
	adds r0, #0x6f
	mov r8, r0
	ldrb r0, [r0]
	movs r7, #0x10
	subs r0, r7, r0
	lsls r0, r0, #3
	lsls r1, r5, #3
	adds r5, r1, #0
	adds r5, #0x90
	adds r0, r0, r5
	ldr r2, _080580B0 @ =0x00000802
	adds r1, r4, r2
	strh r0, [r1]
	ldr r0, _080580B4 @ =0x00000804
	adds r1, r4, r0
	movs r0, #0x18
	strh r0, [r1]
	adds r2, #9
	adds r1, r4, r2
	subs r0, #0x19
	adds r6, r0, #0
	movs r0, #0xff
	strb r0, [r1]
	movs r0, #1
	bl check_vehicle_usability
	movs r3, #0xd
	cmp r0, #0
	bne _08057FE8
	movs r3, #0xc
_08057FE8:
	mov r1, sb
	str r1, [sp]
	movs r0, #0x21
	mov r1, sl
	movs r2, #0x92
	bl init_battle_sprite_entry_08048818
	mov r2, r8
	ldrb r0, [r2]
	subs r0, r7, r0
	lsls r0, r0, #3
	adds r0, r0, r5
	ldr r2, _080580B8 @ =0x00000842
	adds r1, r4, r2
	strh r0, [r1]
	ldr r0, _080580BC @ =0x00000844
	adds r1, r4, r0
	movs r0, #0x28
	strh r0, [r1]
	adds r2, #9
	adds r1, r4, r2
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	movs r0, #2
	bl check_vehicle_usability
	movs r3, #0xd
	cmp r0, #0
	bne _08058026
	movs r3, #0xc
_08058026:
	mov r0, sb
	str r0, [sp]
	movs r0, #0x22
	mov r1, sl
	movs r2, #0x93
	bl init_battle_sprite_entry_08048818
	mov r1, r8
	ldrb r0, [r1]
	subs r0, r7, r0
	lsls r0, r0, #3
	adds r0, r0, r5
	ldr r2, _080580C0 @ =0x00000882
	adds r1, r4, r2
	strh r0, [r1]
	ldr r0, _080580C4 @ =0x00000884
	adds r1, r4, r0
	movs r0, #0x38
	strh r0, [r1]
	adds r2, #9
	adds r1, r4, r2
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	movs r0, #3
	bl check_vehicle_usability
	movs r3, #0xd
	cmp r0, #0
	bne _08058064
	movs r3, #0xc
_08058064:
	mov r0, sb
	str r0, [sp]
	movs r0, #0x23
	mov r1, sl
	movs r2, #0x94
	bl init_battle_sprite_entry_08048818
	mov r1, r8
	ldrb r0, [r1]
	subs r0, r7, r0
	lsls r0, r0, #3
	adds r0, r0, r5
	ldr r2, _080580C8 @ =0x000008C2
	adds r1, r4, r2
	strh r0, [r1]
	ldr r0, _080580CC @ =0x000008C4
	adds r1, r4, r0
	movs r0, #0x48
	strh r0, [r1]
	adds r2, #9
	adds r1, r4, r2
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080580A4: .4byte 0x0000C004
_080580A8: .4byte 0x03002C30
_080580AC: .4byte 0x030064A0
_080580B0: .4byte 0x00000802
_080580B4: .4byte 0x00000804
_080580B8: .4byte 0x00000842
_080580BC: .4byte 0x00000844
_080580C0: .4byte 0x00000882
_080580C4: .4byte 0x00000884
_080580C8: .4byte 0x000008C2
_080580CC: .4byte 0x000008C4
	.syntax divided
