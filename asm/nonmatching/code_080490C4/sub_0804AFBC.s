	.syntax unified

	thumb_func_start sub_0804AFBC
sub_0804AFBC: @ 0x0804AFBC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _0804B0D0 @ =0x00007FFF
	bl run_blend_fade_transition
	cmp r0, #0
	beq _0804B0C0
	ldr r0, _0804B0D4 @ =0x03005590
	ldr r1, _0804B0D8 @ =0x08764CB0
	str r1, [r0]
	ldr r1, _0804B0DC @ =0x030057A0
	ldrb r0, [r1, #0x14]
	ldr r2, _0804B0E0 @ =0x030057E0
	mov r8, r2
	cmp r0, #0
	bne _0804AFEC
	ldrh r1, [r1, #0x26]
	ldr r0, _0804B0E4 @ =0x000007FE
	add r0, r8
	strb r1, [r0]
_0804AFEC:
	mov r5, r8
	ldr r0, _0804B0E4 @ =0x000007FE
	adds r6, r5, r0
	ldrb r0, [r6]
	bl load_npc_sprite_and_calc_camera_offset
	ldr r1, _0804B0E8 @ =0x00000C52
	adds r1, r1, r5
	mov sl, r1
	ldrh r0, [r1]
	bl sub_080526F0
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r2, _0804B0EC @ =0x00000C54
	adds r2, r2, r5
	mov sb, r2
	ldrh r0, [r2]
	bl sub_08052714
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _0804B0F0 @ =0x03006436
	ldrb r0, [r0]
	str r0, [sp]
	ldrb r0, [r6]
	movs r1, #0
	bl sub_08052960
	lsrs r0, r0, #1
	ldr r1, [sp]
	cmp r1, r0
	blo _0804B03A
	ldrb r0, [r6]
	movs r1, #0
	bl sub_08052960
	lsrs r0, r0, #1
	subs r4, r0, #1
_0804B03A:
	ldr r2, _0804B0F4 @ =0x00000C57
	adds r5, r5, r2
	ldrb r0, [r5]
	str r0, [sp, #4]
	ldrb r0, [r6]
	movs r1, #1
	bl sub_08052960
	lsrs r0, r0, #1
	ldr r1, [sp, #4]
	cmp r1, r0
	blo _0804B05E
	ldrb r0, [r6]
	movs r1, #1
	bl sub_08052960
	lsrs r0, r0, #1
	subs r7, r0, #1
_0804B05E:
	ldr r1, _0804B0F8 @ =0x00000C48
	add r1, r8
	lsls r0, r4, #4
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r6, #0
	mov r2, sl
	strh r0, [r2]
	ldr r1, _0804B0FC @ =0x00000C4A
	add r1, r8
	lsls r0, r7, #4
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sb
	strh r0, [r1]
	ldrh r0, [r2]
	bl sub_080526F0
	ldr r2, _0804B0F0 @ =0x03006436
	strb r0, [r2]
	mov r1, sb
	ldrh r0, [r1]
	bl sub_08052714
	strb r0, [r5]
	bl calculate_camera_scroll_from_npc
	ldr r0, _0804B100 @ =0x00000C5C
	add r0, r8
	ldrb r1, [r0]
	ldr r0, _0804B104 @ =0x00000C28
	add r0, r8
	strb r1, [r0]
	bl load_battle_terrain_data
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xf2
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	bl sub_0804B1FC
	ldr r0, _0804B108 @ =0x00000CBA
	add r0, r8
	strb r6, [r0]
	ldr r1, _0804B10C @ =0x0300137C
	movs r0, #1
	str r0, [r1]
_0804B0C0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804B0D0: .4byte 0x00007FFF
_0804B0D4: .4byte 0x03005590
_0804B0D8: .4byte 0x08764CB0
_0804B0DC: .4byte 0x030057A0
_0804B0E0: .4byte 0x030057E0
_0804B0E4: .4byte 0x000007FE
_0804B0E8: .4byte 0x00000C52
_0804B0EC: .4byte 0x00000C54
_0804B0F0: .4byte 0x03006436
_0804B0F4: .4byte 0x00000C57
_0804B0F8: .4byte 0x00000C48
_0804B0FC: .4byte 0x00000C4A
_0804B100: .4byte 0x00000C5C
_0804B104: .4byte 0x00000C28
_0804B108: .4byte 0x00000CBA
_0804B10C: .4byte 0x0300137C
_0804B110:
	.byte 0x70, 0x47, 0x00, 0x00, 0x30, 0xB5, 0x10, 0x49, 0x10, 0x4A, 0x11, 0x4B, 0xD0, 0x18, 0x00, 0x78
	.byte 0x80, 0x00, 0x40, 0x18, 0x01, 0x68, 0x08, 0x78, 0xFF, 0x28, 0x12, 0xD0, 0x80, 0x20, 0x00, 0x01
	.byte 0x15, 0x18, 0x12, 0x33, 0xD4, 0x18, 0x0A, 0x1C, 0x02, 0x23, 0x51, 0x78, 0x28, 0x88, 0x40, 0x08
	.byte 0x48, 0x43, 0x11, 0x78, 0x40, 0x18, 0x00, 0x19, 0x03, 0x70, 0x08, 0x32, 0x10, 0x78, 0xFF, 0x28
	.byte 0xF3, 0xD1, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x14, 0x31, 0x41, 0x08, 0xE0, 0x57, 0x00, 0x03
	.byte 0xFE, 0x07, 0x00, 0x00
	.syntax divided
