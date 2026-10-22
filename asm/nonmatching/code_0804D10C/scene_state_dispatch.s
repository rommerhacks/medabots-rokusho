	.syntax unified

	thumb_func_start scene_state_dispatch
scene_state_dispatch: @ 0x08050C80
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r6, #0
	ldr r0, _08050CA0 @ =0x03006D20
	ldrb r1, [r0, #0xb]
	adds r2, r0, #0
	cmp r1, #4
	bls _08050C96
	b _08050F04
_08050C96:
	lsls r0, r1, #2
	ldr r1, _08050CA4 @ =_08050CA8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08050CA0: .4byte 0x03006D20
_08050CA4: .4byte _08050CA8
_08050CA8: @ jump table
	.4byte _08050CBC @ case 0
	.4byte _08050CF4 @ case 1
	.4byte _08050D26 @ case 2
	.4byte _08050EEC @ case 3
	.4byte _08050EF4 @ case 4
_08050CBC:
	cmp r4, #0x20
	bne _08050CC2
	b _08050EDE
_08050CC2:
	cmp r4, #0x12
	bne _08050CCE
	movs r0, #0x17
	movs r1, #0
	bl dispatch_jump_table_29
_08050CCE:
	movs r0, #8
	cmp r4, #8
	bne _08050CD6
	movs r0, #0xff
_08050CD6:
	ldr r4, _08050CEC @ =0x00000000
	ldr r5, _08050CF0 @ =0x42000000
	bl int_to_softfloat
	adds r3, r0, #0
	movs r0, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl setup_palette_fade_to_color_with_obj
	b _08050EDE
	.align 2, 0
_08050CEC: .4byte 0x00000000
_08050CF0: .4byte 0x42000000
_08050CF4:
	cmp r4, #0x20
	bne _08050D06
	bl populate_battle_entity_tile_positions
	movs r0, #0x20
_08050CFE:
	adds r1, r5, #0
	bl switch_game_mode
	b _08050EDE
_08050D06:
	movs r0, #0
	bl run_blend_fade_transition
	cmp r0, #0
	bne _08050D12
	b _08050F04
_08050D12:
	cmp r4, #0x12
	bne _08050D1E
	movs r0, #0x18
	movs r1, #0
	bl dispatch_jump_table_29
_08050D1E:
	bl populate_battle_entity_tile_positions
	adds r0, r4, #0
	b _08050CFE
_08050D26:
	ldr r0, _08050D90 @ =0x03002C30
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_080496C8
	ldr r0, _08050D94 @ =0x030055A0
	movs r1, #0x80
	lsls r1, r1, #2
	bl sub_080496C8
	movs r2, #0
	str r2, [sp]
	ldr r0, _08050D98 @ =0x040000D4
	mov r1, sp
	str r1, [r0]
	movs r1, #0xe0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r3, _08050D9C @ =0x85000100
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	str r2, [sp]
	mov r1, sp
	str r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	str r3, [r0, #8]
	ldr r0, [r0, #8]
	ldr r0, _08050DA0 @ =0x04000050
	strh r2, [r0]
	adds r0, #4
	strh r2, [r0]
	bl sub_0804B1FC
	bl init_battle_medapart_sprites_all
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xf2
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	cmp r4, #0x10
	beq _08050D84
	cmp r4, #0x20
	bne _08050DAC
_08050D84:
	ldr r0, _08050DA4 @ =0x030057E0
	ldr r3, _08050DA8 @ =0x00000CBA
	adds r0, r0, r3
	movs r1, #2
	b _08050DB4
	.align 2, 0
_08050D90: .4byte 0x03002C30
_08050D94: .4byte 0x030055A0
_08050D98: .4byte 0x040000D4
_08050D9C: .4byte 0x85000100
_08050DA0: .4byte 0x04000050
_08050DA4: .4byte 0x030057E0
_08050DA8: .4byte 0x00000CBA
_08050DAC:
	ldr r0, _08050E04 @ =0x030057E0
	ldr r1, _08050E08 @ =0x00000CBA
	adds r0, r0, r1
	movs r1, #1
_08050DB4:
	strb r1, [r0]
	bl update_battle_field_frame
	bl field_center_camera_on_player
	bl sub_080487E4
	cmp r4, #0x13
	bne _08050DE6
	ldr r2, _08050E0C @ =0x03005350
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	ldr r2, [r0]
	movs r0, #0x93
	movs r3, #0
	bl init_sprite_affine_matrices_and_state
_08050DDE:
	bl battle_scene_state_dispatch
	cmp r0, #0
	beq _08050DDE
_08050DE6:
	cmp r4, #8
	beq _08050DF6
	ldr r1, _08050E10 @ =0x42000000
	ldr r2, _08050E14 @ =0x00000000
	ldr r3, _08050E18 @ =0x41000000
	movs r0, #0
	bl setup_palette_fade_to_color
_08050DF6:
	cmp r4, #0x20
	bhi _08050EDE
	lsls r0, r4, #2
	ldr r1, _08050E1C @ =_08050E20
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08050E04: .4byte 0x030057E0
_08050E08: .4byte 0x00000CBA
_08050E0C: .4byte 0x03005350
_08050E10: .4byte 0x42000000
_08050E14: .4byte 0x00000000
_08050E18: .4byte 0x41000000
_08050E1C: .4byte _08050E20
_08050E20: @ jump table
	.4byte _08050EB4 @ case 0
	.4byte _08050EA8 @ case 1
	.4byte _08050EB8 @ case 2
	.4byte _08050EAC @ case 3
	.4byte _08050EDE @ case 4
	.4byte _08050EC0 @ case 5
	.4byte _08050EDE @ case 6
	.4byte _08050EDE @ case 7
	.4byte _08050EBC @ case 8
	.4byte _08050EDE @ case 9
	.4byte _08050EDE @ case 10
	.4byte _08050EDE @ case 11
	.4byte _08050EDE @ case 12
	.4byte _08050EDE @ case 13
	.4byte _08050EDE @ case 14
	.4byte _08050EDE @ case 15
	.4byte _08050EC4 @ case 16
	.4byte _08050ECC @ case 17
	.4byte _08050EC8 @ case 18
	.4byte _08050EB0 @ case 19
	.4byte _08050ED6 @ case 20
	.4byte _08050EDE @ case 21
	.4byte _08050EDE @ case 22
	.4byte _08050EDE @ case 23
	.4byte _08050EDE @ case 24
	.4byte _08050EDE @ case 25
	.4byte _08050EDE @ case 26
	.4byte _08050EDE @ case 27
	.4byte _08050EDE @ case 28
	.4byte _08050EDE @ case 29
	.4byte _08050EDE @ case 30
	.4byte _08050EDE @ case 31
	.4byte _08050EA4 @ case 32
_08050EA4:
	movs r0, #0xd
	b _08050ECE
_08050EA8:
	movs r0, #0x11
	b _08050ECE
_08050EAC:
	movs r0, #0x14
	b _08050ECE
_08050EB0:
	movs r0, #0x13
	b _08050ECE
_08050EB4:
	movs r0, #0x10
	b _08050ECE
_08050EB8:
	movs r0, #0x12
	b _08050ECE
_08050EBC:
	movs r0, #0x1b
	b _08050ECE
_08050EC0:
	movs r0, #0x1a
	b _08050ECE
_08050EC4:
	movs r0, #0x15
	b _08050ECE
_08050EC8:
	movs r0, #0x19
	b _08050ECE
_08050ECC:
	movs r0, #0x16
_08050ECE:
	movs r1, #0
	bl dispatch_jump_table_29
	b _08050EDE
_08050ED6:
	movs r0, #0xf
	movs r1, #0
	bl dispatch_jump_table_29
_08050EDE:
	ldr r1, _08050EE8 @ =0x03006D20
	ldrb r0, [r1, #0xb]
	adds r0, #1
	strb r0, [r1, #0xb]
	b _08050F04
	.align 2, 0
_08050EE8: .4byte 0x03006D20
_08050EEC:
	ldrb r0, [r2, #0xb]
	adds r0, #1
	strb r0, [r2, #0xb]
	b _08050F04
_08050EF4:
	cmp r4, #8
	beq _08050F02
	movs r0, #0
	bl run_blend_fade_transition
	cmp r0, #0
	beq _08050F04
_08050F02:
	movs r6, #1
_08050F04:
	adds r0, r6, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
