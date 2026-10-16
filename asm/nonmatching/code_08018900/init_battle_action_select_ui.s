	.syntax unified

	thumb_func_start init_battle_action_select_ui
	.global init_battle_action_select_ui
init_battle_action_select_ui: @ 0x08018AB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	cmp r0, #0
	beq _08018AF0
	ldr r0, _08018AEC @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #6
	movs r1, #5
	movs r2, #0xc
	movs r3, #0xf
	bl vram_fill_tilemap_rect
	movs r0, #0
	movs r1, #1
	bl clear_battle_sprite_slot
	movs r0, #1
	movs r1, #2
	bl clear_battle_sprite_slot
	b _08018BA8
	.align 2, 0
_08018AEC: .4byte 0x0400000A
_08018AF0:
	ldr r2, _08018BB8 @ =0x084887A4
	ldr r0, _08018BBC @ =0x0400000A
	ldrh r3, [r0]
	movs r0, #0x8c
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0xc
	movs r1, #0xf
	bl set_tilemap_and_decompress_bg
	ldr r7, _08018BC0 @ =0x03002C30
	movs r0, #0
	mov sb, r0
	ldr r5, _08018BC4 @ =0x0000C404
	strh r5, [r7]
	mov r1, sb
	strb r1, [r7, #0x1c]
	movs r0, #0xa
	strb r0, [r7, #0xa]
	movs r1, #0x40
	mov r8, r1
	mov r0, r8
	strb r0, [r7, #0xb]
	movs r0, #0x78
	strh r0, [r7, #2]
	movs r0, #0x84
	strh r0, [r7, #4]
	ldr r0, _08018BC8 @ =0x00000623
	strh r0, [r7, #6]
	adds r0, r7, #0
	adds r0, #0x40
	strh r5, [r0]
	adds r0, #0x1c
	mov r1, sb
	strb r1, [r0]
	subs r0, #0x12
	movs r1, #0xa
	strb r1, [r0]
	adds r0, #1
	mov r1, r8
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0x42
	movs r0, #0x70
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x44
	movs r6, #0x90
	strh r6, [r0]
	ldr r4, _08018BCC @ =0x03001800
	adds r4, #0x57
	ldrb r0, [r4]
	movs r1, #0xa
	bl sub_0807CD58
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08018BD0 @ =0x00000624
	mov sl, r1
	add r0, sl
	adds r1, r7, #0
	adds r1, #0x46
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x80
	strh r5, [r0]
	adds r0, #0x1c
	mov r1, sb
	strb r1, [r0]
	subs r0, #0x12
	movs r1, #0xa
	strb r1, [r0]
	adds r0, #1
	mov r1, r8
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0x82
	movs r0, #0x80
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x84
	strh r6, [r0]
	ldrb r0, [r4]
	movs r1, #0xa
	bl sub_0807CDD0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add r0, sl
	adds r1, r7, #0
	adds r1, #0x86
	strh r0, [r1]
_08018BA8:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08018BB8: .4byte 0x084887A4
_08018BBC: .4byte 0x0400000A
_08018BC0: .4byte 0x03002C30
_08018BC4: .4byte 0x0000C404
_08018BC8: .4byte 0x00000623
_08018BCC: .4byte 0x03001800
_08018BD0: .4byte 0x00000624
	.syntax divided
