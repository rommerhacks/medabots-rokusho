	.syntax unified

	thumb_func_start sub_0804F694
sub_0804F694: @ 0x0804F694
	push {r4, r5, r6, lr}
	ldr r0, _0804F6B0 @ =0x030057E0
	ldr r1, _0804F6B4 @ =0x00000C93
	adds r6, r0, r1
	ldrb r2, [r6]
	adds r5, r0, #0
	cmp r2, #1
	beq _0804F6F2
	cmp r2, #1
	bgt _0804F6B8
	cmp r2, #0
	beq _0804F6BE
	b _0804F7C6
	.align 2, 0
_0804F6B0: .4byte 0x030057E0
_0804F6B4: .4byte 0x00000C93
_0804F6B8:
	cmp r2, #2
	beq _0804F734
	b _0804F7C6
_0804F6BE:
	ldr r0, _0804F6E0 @ =0x03005350
	movs r2, #0xea
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r1, [r0]
	movs r0, #0x3f
	ands r1, r0
	cmp r1, #0xd
	beq _0804F6D4
	cmp r1, #0x16
	bne _0804F6E4
_0804F6D4:
	bl battle_scene_state_dispatch
	cmp r0, #0
	beq _0804F7C6
	b _0804F720
	.align 2, 0
_0804F6E0: .4byte 0x03005350
_0804F6E4:
	bl battle_scene_state_dispatch
	cmp r0, #0
	beq _0804F7C6
	bl sub_08050244
	b _0804F7C6
_0804F6F2:
	movs r0, #0x2f
	bl sub_080518F4
	adds r1, r0, #0
	ldr r4, _0804F728 @ =0x03006D20
	movs r0, #0x10
	bl sub_0807CBBC
	strb r0, [r4]
	ldr r3, _0804F72C @ =0x00000C94
	adds r0, r5, r3
	ldrb r1, [r0]
	lsls r1, r1, #4
	ldr r2, _0804F730 @ =0x00000C95
	adds r0, r5, r2
	ldrb r0, [r0]
	orrs r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x2f
	movs r2, #0
	bl sub_080500D8
_0804F720:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	b _0804F7C6
	.align 2, 0
_0804F728: .4byte 0x03006D20
_0804F72C: .4byte 0x00000C94
_0804F730: .4byte 0x00000C95
_0804F734:
	ldr r0, _0804F750 @ =0x03005350
	movs r3, #0xea
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	cmp r0, #0xd
	bne _0804F758
	ldr r1, _0804F754 @ =0x00000C67
	adds r0, r5, r1
	strb r2, [r0]
	b _0804F760
	.align 2, 0
_0804F750: .4byte 0x03005350
_0804F754: .4byte 0x00000C67
_0804F758:
	ldr r2, _0804F7CC @ =0x00000C67
	adds r1, r5, r2
	movs r0, #3
	strb r0, [r1]
_0804F760:
	ldr r3, _0804F7CC @ =0x00000C67
	adds r6, r5, r3
	ldrb r0, [r6]
	bl sub_0804F13C
	cmp r0, #0
	beq _0804F7C6
	ldr r0, _0804F7D0 @ =0x00000C5B
	adds r4, r5, r0
	movs r0, #1
	strb r0, [r4]
	ldr r1, _0804F7D4 @ =0x03002C30
	ldr r2, _0804F7D8 @ =0x083D2908
	ldr r3, _0804F7DC @ =0x00000C5C
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r2, _0804F7E0 @ =0x00000BEA
	adds r1, r1, r2
	strb r0, [r1]
	subs r3, #0xa
	adds r0, r5, r3
	ldrh r0, [r0]
	bl sub_080526F0
	ldr r2, _0804F7E4 @ =0x00000C56
	adds r1, r5, r2
	strb r0, [r1]
	ldr r3, _0804F7E8 @ =0x00000C54
	adds r0, r5, r3
	ldrh r0, [r0]
	bl sub_08052714
	ldr r2, _0804F7EC @ =0x00000C57
	adds r1, r5, r2
	strb r0, [r1]
	bl calculate_camera_scroll_from_npc
	ldrb r0, [r4]
	bl sub_08052BA0
	ldrb r0, [r6]
	bl set_battle_entity_animation_attack
	bl update_bg_scroll_offsets_a
	bl init_battle_sprites
	bl sub_08050244
_0804F7C6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804F7CC: .4byte 0x00000C67
_0804F7D0: .4byte 0x00000C5B
_0804F7D4: .4byte 0x03002C30
_0804F7D8: .4byte 0x083D2908
_0804F7DC: .4byte 0x00000C5C
_0804F7E0: .4byte 0x00000BEA
_0804F7E4: .4byte 0x00000C56
_0804F7E8: .4byte 0x00000C54
_0804F7EC: .4byte 0x00000C57
	.syntax divided
