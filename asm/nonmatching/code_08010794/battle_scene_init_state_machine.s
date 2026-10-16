	.syntax unified

	thumb_func_start battle_scene_init_state_machine
battle_scene_init_state_machine: @ 0x08012A20
	push {r4, lr}
	sub sp, #4
	ldr r1, _08012A3C @ =0x03000440
	ldr r0, _08012A40 @ =0x00000139
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, #1
	beq _08012AA4
	cmp r0, #1
	bgt _08012A44
	cmp r0, #0
	beq _08012A4A
	b _08012B22
	.align 2, 0
_08012A3C: .4byte 0x03000440
_08012A40: .4byte 0x00000139
_08012A44:
	cmp r0, #2
	beq _08012AE0
	b _08012B22
_08012A4A:
	bl sub_08043CA8
	bl load_battle_script_entry_b
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _08012A90 @ =0x0000F0FF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08012A94 @ =0x04000008
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _08012A98 @ =0x00001901
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _08012A9C @ =0x00001A0A
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _08012AA0 @ =0x00001B0B
	adds r0, r3, #0
	strh r0, [r1]
	movs r0, #0
	bl battle_phase_dispatch_0801A788
	cmp r0, #0
	beq _08012B22
	ldrb r0, [r4]
	adds r0, #1
	b _08012B20
	.align 2, 0
_08012A90: .4byte 0x0000F0FF
_08012A94: .4byte 0x04000008
_08012A98: .4byte 0x00001901
_08012A9C: .4byte 0x00001A0A
_08012AA0: .4byte 0x00001B0B
_08012AA4:
	adds r1, #0x84
	movs r0, #0
	strb r0, [r1]
	str r0, [sp]
	ldr r1, _08012AD4 @ =0x03002C30
	ldr r2, _08012AD8 @ =0x01000800
	mov r0, sp
	bl CpuFastSet
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0xfa
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r1, [r2]
	ldr r0, _08012ADC @ =0x0000FFDF
	ands r0, r1
	strh r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	b _08012B20
	.align 2, 0
_08012AD4: .4byte 0x03002C30
_08012AD8: .4byte 0x01000800
_08012ADC: .4byte 0x0000FFDF
_08012AE0:
	bl load_bg3_tilemap_08488764
	bl draw_battle_bot_portraits
	bl load_all_bot_part_sprites
	bl setup_all_battle_bot_sprite_positions
	bl init_battle_bot_sprites
	bl apply_battle_blend_effect_b
	ldr r2, _08012B2C @ =0x083B24A8
	ldr r0, _08012B30 @ =0x03001800
	adds r0, #0x38
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl decompress_to_ewram_27000
	ldr r1, _08012B34 @ =0x030017F0
	ldr r0, _08012B38 @ =sub_08044100
	str r0, [r1]
	ldr r1, _08012B3C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r0, #0
_08012B20:
	strb r0, [r4]
_08012B22:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08012B2C: .4byte 0x083B24A8
_08012B30: .4byte 0x03001800
_08012B34: .4byte 0x030017F0
_08012B38: .4byte sub_08044100
_08012B3C: .4byte 0x0300137C
	.syntax divided
