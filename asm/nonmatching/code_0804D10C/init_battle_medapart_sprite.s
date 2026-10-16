	.syntax unified

	thumb_func_start init_battle_medapart_sprite
init_battle_medapart_sprite: @ 0x080503B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r1, #0
	adds r5, r2, #0
	mov r8, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #4]
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	mov r0, r8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r1, [sp, #4]
	adds r1, #0x4f
	mov sb, r1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sl, r1
	mov r0, sl
	bl clear_battle_sprite_entry
	adds r0, r6, #0
	bl calc_medapart_table_index
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r6, #0
	bl sub_08050264
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r1, _080504E4 @ =0x0000C804
	movs r2, #1
	str r2, [sp]
	mov r0, sl
	adds r2, r4, #0
	bl init_battle_sprite_entry_08048818
	adds r0, r6, #0
	bl sub_08050264
	mov r2, sb
	lsls r1, r2, #6
	ldr r2, _080504E8 @ =0x03002C30
	adds r7, r1, r2
	adds r1, r7, #0
	adds r1, #0x2b
	str r1, [sp, #8]
	movs r4, #0
	strb r0, [r1]
	adds r0, r6, #0
	bl sub_0805026C
	adds r1, r7, #0
	adds r1, #0x20
	strb r0, [r1]
	ldr r1, _080504EC @ =0x030057E0
	ldr r2, _080504F0 @ =0x00000C48
	adds r0, r1, r2
	lsls r5, r5, #4
	ldrh r0, [r0]
	adds r5, r5, r0
	lsls r5, r5, #8
	ldrb r0, [r7, #0xc]
	orrs r0, r5
	str r0, [r7, #0xc]
	ldr r0, _080504F4 @ =0x00000C4A
	adds r1, r1, r0
	mov r2, r8
	lsls r2, r2, #4
	mov r8, r2
	ldrh r1, [r1]
	add r8, r1
	mov r0, r8
	lsls r0, r0, #8
	mov r8, r0
	movs r5, #0xff
	ldrb r0, [r7, #0x10]
	mov r1, r8
	orrs r0, r1
	str r0, [r7, #0x10]
	ldr r0, _080504F8 @ =0x030055A0
	mov r2, sb
	lsls r2, r2, #2
	mov sb, r2
	add sb, r0
	ldr r0, _080504FC @ =0x0000FFFF
	mov r1, sb
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x2c
	strb r4, [r0]
	ldr r2, [sp, #8]
	ldrb r0, [r2]
	bl resolve_tile_from_battle_state
	adds r4, r0, #0
	strh r4, [r7, #0x30]
	mov r0, sl
	bl sub_0804877C
	ldr r0, _08050500 @ =0x083D2B8D
	adds r4, r4, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _080504D2
	ldr r4, [sp, #4]
	adds r4, #0x79
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08050504 @ =0x0000CC0C
	movs r2, #1
	str r2, [sp]
	movs r2, #0x90
	movs r3, #0xe
	bl init_battle_sprite_entry_08048818
	lsls r4, r4, #6
	ldr r0, _080504E8 @ =0x03002C30
	adds r4, r4, r0
	ldr r1, [r7, #0xc]
	asrs r1, r1, #8
	lsls r1, r1, #8
	ldr r0, [r4, #0xc]
	ands r0, r5
	orrs r0, r1
	str r0, [r4, #0xc]
	ldr r0, [r7, #0x10]
	asrs r0, r0, #8
	subs r0, #5
	lsls r0, r0, #8
	ldr r1, [r4, #0x10]
	ands r1, r5
	orrs r1, r0
	str r1, [r4, #0x10]
_080504D2:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080504E4: .4byte 0x0000C804
_080504E8: .4byte 0x03002C30
_080504EC: .4byte 0x030057E0
_080504F0: .4byte 0x00000C48
_080504F4: .4byte 0x00000C4A
_080504F8: .4byte 0x030055A0
_080504FC: .4byte 0x0000FFFF
_08050500: .4byte 0x083D2B8D
_08050504: .4byte 0x0000CC0C
	.syntax divided
