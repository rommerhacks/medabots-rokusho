	.syntax unified

	thumb_func_start sub_08008A5C
sub_08008A5C: @ 0x08008A5C
	push {lr}
	bl setup_battle_cursor_sprite_0800B5E8
	ldr r0, _08008A84 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08008A92
	ldr r0, _08008A88 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x48
	ldrh r0, [r1]
	cmp r0, #0
	bne _08008A8C
	movs r0, #7
	strh r0, [r1]
	b _08008B76
	.align 2, 0
_08008A84: .4byte 0x03001798
_08008A88: .4byte 0x03000440
_08008A8C:
	subs r0, #1
	strh r0, [r1]
	b _08008B76
_08008A92:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08008AB6
	ldr r0, _08008AAC @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x48
	ldrh r0, [r1]
	cmp r0, #7
	bne _08008AB0
	strh r2, [r1]
	b _08008B76
	.align 2, 0
_08008AAC: .4byte 0x03000440
_08008AB0:
	adds r0, #1
	strh r0, [r1]
	b _08008B76
_08008AB6:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08008AE8
	ldr r1, _08008AE0 @ =0x03000BE0
	ldr r0, _08008AE4 @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x48
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	ldrh r2, [r2]
	adds r0, r0, r2
	adds r1, #0x20
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0x64
	beq _08008AE8
	adds r0, #1
	b _08008B12
	.align 2, 0
_08008AE0: .4byte 0x03000BE0
_08008AE4: .4byte 0x03000440
_08008AE8:
	ldr r0, _08008B1C @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08008B28
	ldr r1, _08008B20 @ =0x03000BE0
	ldr r0, _08008B24 @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x48
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	ldrh r2, [r2]
	adds r0, r0, r2
	adds r1, #0x20
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0
	beq _08008B28
	subs r0, #1
_08008B12:
	strb r0, [r1]
	bl render_medal_skill_stats
	b _08008B76
	.align 2, 0
_08008B1C: .4byte 0x03001798
_08008B20: .4byte 0x03000BE0
_08008B24: .4byte 0x03000440
_08008B28:
	ldr r0, _08008B54 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08008B60
	ldr r1, _08008B58 @ =0x03000BE0
	ldr r0, _08008B5C @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x48
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	ldrh r2, [r2]
	adds r0, r0, r2
	adds r1, #0x28
	adds r0, r0, r1
	movs r1, #7
	strb r1, [r0]
	bl draw_medal_skill_bars
	b _08008B76
	.align 2, 0
_08008B54: .4byte 0x0300058C
_08008B58: .4byte 0x03000BE0
_08008B5C: .4byte 0x03000440
_08008B60:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08008B76
	movs r0, #0x7f
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _08008B7C @ =0x0300137C
	movs r0, #0x3a
	str r0, [r1]
_08008B76:
	pop {r0}
	bx r0
	.align 2, 0
_08008B7C: .4byte 0x0300137C
	.syntax divided
