	.syntax unified

	thumb_func_start sub_08009A38
	.global sub_08009A38
sub_08009A38: @ 0x08009A38
	push {lr}
	sub sp, #0xc
	ldr r2, _08009A58 @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08009A64
	ldr r0, _08009A5C @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x3f
	ldrb r0, [r1]
	cmp r0, #0
	bne _08009A60
	movs r0, #4
	b _08009A62
	.align 2, 0
_08009A58: .4byte 0x03001798
_08009A5C: .4byte 0x03000440
_08009A60:
	subs r0, #1
_08009A62:
	strb r0, [r1]
_08009A64:
	ldrb r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08009A88
	ldr r0, _08009A80 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x3f
	ldrb r0, [r1]
	cmp r0, #4
	bne _08009A84
	movs r0, #0
	b _08009A86
	.align 2, 0
_08009A80: .4byte 0x03000440
_08009A84:
	adds r0, #1
_08009A86:
	strb r0, [r1]
_08009A88:
	ldrb r1, [r2]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _08009AE6
	movs r0, #2
	bl play_sound_effect
	ldr r1, _08009AEC @ =0x083B4AE0
	ldr r0, _08009AF0 @ =0x03000440
	adds r0, #0x3f
	ldrb r0, [r0]
	adds r0, #0x4b
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _08009AF4 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	movs r0, #0xa
	movs r1, #2
	movs r2, #5
	movs r3, #2
	bl write_tilemap_rect
	bl render_medal_sprite_tile
	bl render_medal_list_entries
	bl render_medal_slots_in_menu
	bl render_medal_name_display
	bl load_medal_sprite
	bl render_medal_level_display
	bl decompress_active_medal_sprite
	bl init_active_medal_battle_sprites
	bl draw_medal_position_tile
_08009AE6:
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_08009AEC: .4byte 0x083B4AE0
_08009AF0: .4byte 0x03000440
_08009AF4: .4byte 0x0400000A
	.syntax divided
