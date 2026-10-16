	.syntax unified

	thumb_func_start handle_medapart_selection_scroll
handle_medapart_selection_scroll: @ 0x0800FDD8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r2, _0800FE08 @ =0x03000440
	adds r0, r2, #0
	adds r0, #0x41
	ldrb r0, [r0]
	cmp r0, #1
	bhi _0800FDEC
	b _0800FF44
_0800FDEC:
	ldr r0, _0800FE0C @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800FE66
	adds r7, r2, #0
	adds r7, #0x3d
	adds r4, r2, #0
_0800FDFE:
	ldrb r0, [r7]
	cmp r0, #0
	bne _0800FE10
	movs r0, #0x77
	b _0800FE12
	.align 2, 0
_0800FE08: .4byte 0x03000440
_0800FE0C: .4byte 0x03001798
_0800FE10:
	subs r0, #1
_0800FE12:
	strb r0, [r7]
	adds r6, r4, #0
	adds r6, #0x3d
	ldrb r0, [r6]
	adds r5, r4, #0
	adds r5, #0x3e
	ldrb r1, [r5]
	bl sub_08042114
	lsls r1, r0, #0x10
	lsrs r2, r1, #0x10
	cmp r2, #0
	beq _0800FDFE
	adds r0, r4, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #1
	bne _0800FE66
	lsrs r1, r1, #0x18
	movs r0, #0xff
	ands r2, r0
	cmp r1, r2
	beq _0800FDFE
	ldrb r0, [r6]
	ldrb r1, [r5]
	movs r3, #0x87
	lsls r3, r3, #1
	adds r2, r4, r3
	bl load_part_data
	ldr r1, _0800FE88 @ =0x030017A0
	adds r0, r4, #0
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r2, _0800FE8C @ =0x00000111
	adds r1, r4, r2
	ldrb r0, [r0, #1]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0800FDFE
_0800FE66:
	ldr r0, _0800FE90 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800FEEC
	ldr r6, _0800FE94 @ =0x0300047D
	adds r4, r6, #0
	subs r4, #0x3d
	subs r3, r6, #1
	mov r8, r3
_0800FE7C:
	ldrb r0, [r6]
	cmp r0, #0x77
	bne _0800FE98
	movs r0, #0
	b _0800FE9A
	.align 2, 0
_0800FE88: .4byte 0x030017A0
_0800FE8C: .4byte 0x00000111
_0800FE90: .4byte 0x03001798
_0800FE94: .4byte 0x0300047D
_0800FE98:
	adds r0, #1
_0800FE9A:
	strb r0, [r6]
	adds r7, r4, #0
	adds r7, #0x3d
	ldrb r0, [r7]
	adds r5, r4, #0
	adds r5, #0x3e
	ldrb r1, [r5]
	bl sub_08042114
	lsls r1, r0, #0x10
	lsrs r2, r1, #0x10
	cmp r2, #0
	beq _0800FE7C
	mov r3, r8
	ldrb r0, [r3]
	cmp r0, #1
	bne _0800FEEC
	lsrs r1, r1, #0x18
	movs r0, #0xff
	ands r2, r0
	cmp r1, r2
	beq _0800FE7C
	ldrb r0, [r7]
	ldrb r1, [r5]
	movs r3, #0x87
	lsls r3, r3, #1
	adds r2, r4, r3
	bl load_part_data
	ldr r1, _0800FF34 @ =0x030017A0
	adds r0, r4, #0
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r2, _0800FF38 @ =0x00000111
	adds r1, r4, r2
	ldrb r0, [r0, #1]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0800FE7C
_0800FEEC:
	ldr r0, _0800FF3C @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _0800FF44
	movs r0, #2
	bl play_sound_effect
	ldr r2, _0800FF40 @ =0x03000440
	adds r0, r2, #0
	adds r0, #0x3d
	ldrb r0, [r0]
	adds r1, r2, #0
	adds r1, #0x3e
	ldrb r1, [r1]
	adds r2, #0xee
	bl load_part_data
	bl load_npc_sprite_data
	bl load_scene_sprite_data
	bl render_menu_tilemap_section
	bl load_script_data_to_buffer
	bl fill_bg1_tilemap_from_state
	bl render_shop_price_display
	bl load_overworld_sprite_by_direction
	movs r0, #1
	b _0800FF46
	.align 2, 0
_0800FF34: .4byte 0x030017A0
_0800FF38: .4byte 0x00000111
_0800FF3C: .4byte 0x03001798
_0800FF40: .4byte 0x03000440
_0800FF44:
	movs r0, #0
_0800FF46:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
