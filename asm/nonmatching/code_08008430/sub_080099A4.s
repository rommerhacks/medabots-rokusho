	.syntax unified

	thumb_func_start sub_080099A4
	.global sub_080099A4
sub_080099A4: @ 0x080099A4
	push {lr}
	ldr r2, _080099C4 @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080099D0
	ldr r0, _080099C8 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x40
	ldrb r0, [r1]
	cmp r0, #0
	bne _080099CC
	movs r0, #5
	b _080099CE
	.align 2, 0
_080099C4: .4byte 0x03001798
_080099C8: .4byte 0x03000440
_080099CC:
	subs r0, #1
_080099CE:
	strb r0, [r1]
_080099D0:
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080099F4
	ldr r0, _080099EC @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x40
	ldrb r0, [r1]
	cmp r0, #5
	bne _080099F0
	movs r0, #0
	b _080099F2
	.align 2, 0
_080099EC: .4byte 0x03000440
_080099F0:
	adds r0, #1
_080099F2:
	strb r0, [r1]
_080099F4:
	ldrb r1, [r2]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _08009A2C
	movs r0, #2
	bl play_sound_effect
	ldr r0, _08009A30 @ =0x03002C30
	ldr r1, _08009A34 @ =0x03000440
	adds r1, #0x40
	ldrb r1, [r1]
	lsls r1, r1, #4
	adds r1, #0x28
	adds r0, #0xc4
	strh r1, [r0]
	bl render_medal_name_display
	bl load_medal_sprite
	bl render_medal_level_display
	bl decompress_active_medal_sprite
	bl init_active_medal_battle_sprites
	bl draw_medal_position_tile
_08009A2C:
	pop {r0}
	bx r0
	.align 2, 0
_08009A30: .4byte 0x03002C30
_08009A34: .4byte 0x03000440
	.syntax divided
