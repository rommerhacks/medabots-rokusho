	.syntax unified

	thumb_func_start sub_08050F10
	.global sub_08050F10
sub_08050F10: @ 0x08050F10
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _08050F2C @ =0x03005310
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08050F22
	b _0805133C
_08050F22:
	lsls r0, r0, #2
	ldr r1, _08050F30 @ =_08050F34
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08050F2C: .4byte 0x03005310
_08050F30: .4byte _08050F34
_08050F34: @ jump table
	.4byte _08050F48 @ case 0
	.4byte _0805102C @ case 1
	.4byte _08051074 @ case 2
	.4byte _08051300 @ case 3
	.4byte _0805131C @ case 4
_08050F48:
	bl set_battle_state_cancel_flag
	ldr r4, _08050FE0 @ =0x030057E0
	ldr r1, _08050FE4 @ =0x00000C56
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _08050FE8 @ =0x00000C57
	adds r1, r4, r2
	ldrb r1, [r1]
	bl find_map_event_by_coords
	cmp r0, #0
	beq _0805100C
	movs r0, #0x2f
	bl sub_080518F4
	adds r1, r0, #0
	movs r0, #0x10
	bl sub_0807CBBC
	ldr r3, _08050FEC @ =0x00000C58
	adds r1, r4, r3
	strb r0, [r1]
	ldr r6, _08050FF0 @ =0x03002C30
	movs r0, #0xbe
	lsls r0, r0, #4
	adds r5, r6, r0
	ldrb r0, [r5]
	bl field_set_player_facing
	ldrb r1, [r5]
	movs r0, #0x2f
	bl sub_080493D4
	ldr r1, _08050FF4 @ =0x00000C76
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08050FD0
	ldr r2, _08050FF8 @ =0x00000C52
	adds r0, r4, r2
	ldrh r1, [r0]
	ldr r3, _08050FFC @ =0x00000C6E
	adds r0, r4, r3
	strh r1, [r0]
	ldr r1, _08051000 @ =0x00000C54
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r2, #0x1e
	adds r0, r4, r2
	strh r1, [r0]
	ldrb r0, [r5]
	bl set_battle_state_byte_c83
	ldr r3, _08051004 @ =0x00000C2B
	adds r0, r6, r3
	ldrb r1, [r0]
	movs r2, #0xc2
	lsls r2, r2, #4
	adds r0, r6, r2
	lsls r1, r1, #2
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x30
	bl sub_080493D4
_08050FD0:
	movs r0, #3
	bl update_battle_direction_indicator
	ldr r1, _08051008 @ =0x03005310
	movs r0, #1
	strb r0, [r1, #1]
	b _0805133C
	.align 2, 0
_08050FE0: .4byte 0x030057E0
_08050FE4: .4byte 0x00000C56
_08050FE8: .4byte 0x00000C57
_08050FEC: .4byte 0x00000C58
_08050FF0: .4byte 0x03002C30
_08050FF4: .4byte 0x00000C76
_08050FF8: .4byte 0x00000C52
_08050FFC: .4byte 0x00000C6E
_08051000: .4byte 0x00000C54
_08051004: .4byte 0x00000C2B
_08051008: .4byte 0x03005310
_0805100C:
	ldr r0, _08051024 @ =0x03006D38
	ldrb r0, [r0, #3]
	cmp r0, #4
	bne _0805101A
	movs r0, #0
	bl sub_08047BA8
_0805101A:
	ldr r1, _08051028 @ =0x03005310
	movs r0, #2
	strb r0, [r1, #1]
	b _0805133C
	.align 2, 0
_08051024: .4byte 0x03006D38
_08051028: .4byte 0x03005310
_0805102C:
	ldr r0, _08051060 @ =0x03002C30
	movs r3, #0xbe
	lsls r3, r3, #4
	adds r0, r0, r3
	ldrb r0, [r0]
	bl field_player_step
	ldr r0, _08051064 @ =0x030057E0
	ldr r1, _08051068 @ =0x00000C58
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08051048
	b _0805133C
_08051048:
	ldr r0, _0805106C @ =0x03006D38
	ldrb r0, [r0, #3]
	cmp r0, #4
	bne _08051056
	movs r0, #0
	bl sub_08047BA8
_08051056:
	ldr r1, _08051070 @ =0x03005310
	ldrb r0, [r1, #1]
	adds r0, #1
	strb r0, [r1, #1]
	b _0805133C
	.align 2, 0
_08051060: .4byte 0x03002C30
_08051064: .4byte 0x030057E0
_08051068: .4byte 0x00000C58
_0805106C: .4byte 0x03006D38
_08051070: .4byte 0x03005310
_08051074:
	movs r2, #0
	mov r8, r2
	movs r7, #0
	ldr r4, _080510A8 @ =0x030057E0
	ldr r3, _080510AC @ =0x00000C58
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08051088
	b _080512A0
_08051088:
	ldr r1, _080510B0 @ =0x00000C88
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08051094
	b _080512A0
_08051094:
	bl update_npc_random_animation
	bl find_npc_event_match
	cmp r0, #0
	beq _080510B4
	movs r2, #1
	mov r8, r2
	b _080512A0
	.align 2, 0
_080510A8: .4byte 0x030057E0
_080510AC: .4byte 0x00000C58
_080510B0: .4byte 0x00000C88
_080510B4:
	ldr r3, _0805111C @ =0x00000C56
	adds r0, r4, r3
	ldrb r0, [r0]
	ldr r2, _08051120 @ =0x00000C57
	adds r1, r4, r2
	ldrb r1, [r1]
	bl find_map_event_by_coords
	cmp r0, #0
	beq _080510F0
	ldr r0, _08051124 @ =0x03005310
	movs r1, #3
	strb r1, [r0, #1]
	ldr r1, _08051128 @ =0x03006D38
	ldrb r0, [r1, #3]
	cmp r0, #0
	beq _080510E2
	ldr r0, _0805112C @ =0x083D29E6
	ldrb r1, [r1, #3]
	adds r1, r1, r0
	ldrb r0, [r1]
	bl sub_08047BA8
_080510E2:
	ldr r0, _08051130 @ =0x00007FFF
	ldr r1, _08051134 @ =0x00000000
	ldr r2, _08051138 @ =0x42000000
	ldr r3, _0805113C @ =0x41000000
	bl setup_palette_fade_to_color_with_obj
	movs r7, #1
_080510F0:
	mov r3, r8
	cmp r3, #0
	beq _080510F8
	b _080512A0
_080510F8:
	cmp r7, #0
	beq _080510FE
	b _080512A0
_080510FE:
	ldr r0, _08051140 @ =0x03002B64
	ldrb r1, [r0]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08051150
	ldr r0, _08051144 @ =0x03002C30
	ldr r3, _08051148 @ =0x00000BEA
	adds r1, r0, r3
	strb r2, [r1]
	ldr r1, _0805114C @ =0x00000C2A
	adds r0, r0, r1
	strb r2, [r0]
	b _0805116C
	.align 2, 0
_0805111C: .4byte 0x00000C56
_08051120: .4byte 0x00000C57
_08051124: .4byte 0x03005310
_08051128: .4byte 0x03006D38
_0805112C: .4byte 0x083D29E6
_08051130: .4byte 0x00007FFF
_08051134: .4byte 0x00000000
_08051138: .4byte 0x42000000
_0805113C: .4byte 0x41000000
_08051140: .4byte 0x03002B64
_08051144: .4byte 0x03002C30
_08051148: .4byte 0x00000BEA
_0805114C: .4byte 0x00000C2A
_08051150:
	ldr r1, _0805119C @ =0x03002C30
	ldr r2, _080511A0 @ =0x083D2908
	ldr r0, _080511A4 @ =0x030057E0
	ldr r3, _080511A8 @ =0x00000C5C
	adds r0, r0, r3
	ldrb r0, [r0]
	adds r0, r0, r2
	ldrb r2, [r0]
	subs r3, #0x72
	adds r0, r1, r3
	strb r2, [r0]
	ldr r0, _080511AC @ =0x00000C2A
	adds r1, r1, r0
	strb r2, [r1]
_0805116C:
	ldr r2, _080511B0 @ =0x0300058C
	ldrb r1, [r2]
	movs r5, #1
	adds r4, r5, #0
	ands r4, r1
	cmp r4, #0
	beq _080511B8
	bl map_cursor_move_and_check_event
	cmp r0, #0
	beq _08051184
	b _080512E0
_08051184:
	bl check_room_exit_at_position
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne _08051192
	b _080512A0
_08051192:
	ldr r1, _080511B4 @ =0x0300137C
	movs r0, #8
	str r0, [r1]
	b _080512E0
	.align 2, 0
_0805119C: .4byte 0x03002C30
_080511A0: .4byte 0x083D2908
_080511A4: .4byte 0x030057E0
_080511A8: .4byte 0x00000C5C
_080511AC: .4byte 0x00000C2A
_080511B0: .4byte 0x0300058C
_080511B4: .4byte 0x0300137C
_080511B8:
	movs r3, #2
	mov sb, r3
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq _08051284
	ldr r6, _08051248 @ =0x030057E0
	ldr r1, _0805124C @ =0x00000C33
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080512A0
	bl sub_08047E4C
	ldr r0, _08051250 @ =0x0300178C
	str r4, [r0]
	ldr r0, _08051254 @ =0x03002B8C
	str r5, [r0]
	ldr r0, _08051258 @ =0x0300137C
	str r4, [r0]
	ldr r1, _0805125C @ =0x03005310
	ldr r3, _08051260 @ =0x03005000
	ldrh r0, [r3]
	strh r0, [r1, #0x1c]
	ldrh r0, [r3, #2]
	strh r0, [r1, #0x24]
	ldr r2, _08051264 @ =0x03004C30
	ldrh r0, [r2]
	strh r0, [r1, #0x1e]
	ldrh r0, [r2, #2]
	strh r0, [r1, #0x26]
	ldr r2, _08051268 @ =0x0300057C
	ldrh r0, [r2]
	strh r0, [r1, #0x20]
	ldrh r0, [r2, #2]
	strh r0, [r1, #0x28]
	ldr r2, _0805126C @ =0x03001C04
	ldrh r0, [r2]
	strh r0, [r1, #0x22]
	ldrh r0, [r2, #2]
	strh r0, [r1, #0x2a]
	strh r4, [r3]
	strh r4, [r3, #2]
	ldr r1, _08051270 @ =0x03002C30
	movs r2, #0xbe
	lsls r2, r2, #4
	adds r0, r1, r2
	ldrb r2, [r0]
	ldr r3, _08051274 @ =0x00000C67
	adds r0, r6, r3
	strb r2, [r0]
	movs r2, #0xc2
	lsls r2, r2, #4
	adds r0, r1, r2
	ldrb r2, [r0]
	adds r3, #0x1c
	adds r0, r6, r3
	strb r2, [r0]
	ldr r0, _08051278 @ =0x00000C2B
	adds r1, r1, r0
	ldrb r1, [r1]
	ldr r2, _0805127C @ =0x00000C84
	adds r0, r6, r2
	strb r1, [r0]
	bl populate_battle_entity_tile_positions
	ldr r3, _08051280 @ =0x00000CBA
	adds r0, r6, r3
	mov r1, sb
	strb r1, [r0]
	b _080512E0
	.align 2, 0
_08051248: .4byte 0x030057E0
_0805124C: .4byte 0x00000C33
_08051250: .4byte 0x0300178C
_08051254: .4byte 0x03002B8C
_08051258: .4byte 0x0300137C
_0805125C: .4byte 0x03005310
_08051260: .4byte 0x03005000
_08051264: .4byte 0x03004C30
_08051268: .4byte 0x0300057C
_0805126C: .4byte 0x03001C04
_08051270: .4byte 0x03002C30
_08051274: .4byte 0x00000C67
_08051278: .4byte 0x00000C2B
_0805127C: .4byte 0x00000C84
_08051280: .4byte 0x00000CBA
_08051284:
	ldrb r1, [r2, #1]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _080512A0
	ldr r0, _080512D4 @ =0x030057E0
	ldr r2, _080512D8 @ =0x00000C5C
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _080512A0
	movs r0, #0x74
	bl sub_08047BA8
_080512A0:
	movs r0, #0
	cmp r0, #0
	bne _080512E0
	mov r3, r8
	cmp r3, #0
	bne _080512E0
	cmp r7, #0
	bne _080512E0
	ldr r0, _080512DC @ =0x0300058C
	ldrb r1, [r0, #1]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080512CE
	ldr r0, _080512D4 @ =0x030057E0
	ldr r1, _080512D8 @ =0x00000C5C
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080512CE
	movs r0, #0x74
	bl sub_08047BA8
_080512CE:
	bl field_player_walk_input
	b _0805133C
	.align 2, 0
_080512D4: .4byte 0x030057E0
_080512D8: .4byte 0x00000C5C
_080512DC: .4byte 0x0300058C
_080512E0:
	ldr r4, _080512FC @ =0x03002C30
	movs r2, #0xbe
	lsls r2, r2, #4
	adds r0, r4, r2
	ldrb r0, [r0]
	bl field_set_player_facing
	movs r3, #0xc2
	lsls r3, r3, #4
	adds r4, r4, r3
	ldrb r0, [r4]
	bl set_battle_state_byte_c83
	b _0805133C
	.align 2, 0
_080512FC: .4byte 0x03002C30
_08051300:
	ldr r0, _08051314 @ =0x00007FFF
	bl run_blend_fade_transition
	cmp r0, #0
	beq _0805133C
	ldr r1, _08051318 @ =0x03005310
	movs r0, #4
	strb r0, [r1, #1]
	b _0805133C
	.align 2, 0
_08051314: .4byte 0x00007FFF
_08051318: .4byte 0x03005310
_0805131C:
	bl field_warp_to_area
	ldr r1, _08051354 @ =0x03005310
	movs r0, #0
	strb r0, [r1, #1]
	ldr r0, _08051358 @ =0x0300178C
	movs r1, #1
	str r1, [r0]
	ldr r0, _0805135C @ =0x03002B8C
	str r1, [r0]
	ldr r0, _08051360 @ =0x0300137C
	str r1, [r0]
	ldr r0, _08051364 @ =0x030057E0
	ldr r2, _08051368 @ =0x00000CBA
	adds r0, r0, r2
	strb r1, [r0]
_0805133C:
	bl update_bg_scroll_offsets_a
	bl update_bg_scroll_offsets_b
	bl update_entity_sprites_on_screen
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08051354: .4byte 0x03005310
_08051358: .4byte 0x0300178C
_0805135C: .4byte 0x03002B8C
_08051360: .4byte 0x0300137C
_08051364: .4byte 0x030057E0
_08051368: .4byte 0x00000CBA
	.syntax divided
